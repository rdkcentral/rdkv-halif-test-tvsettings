#!/usr/bin/env python3
#** *****************************************************************************
# *
# * If not stated otherwise in this file or this component's LICENSE file the
# * following copyright and licenses apply:
# *
# * Copyright 2024 RDK Management
# *
# * Licensed under the Apache License, Version 2.0 (the "License");
# * you may not use this file except in compliance with the License.
# * You may obtain a copy of the License at
# *
# *
# http://www.apache.org/licenses/LICENSE-2.0
# *
# * Unless required by applicable law or agreed to in writing, software
# * distributed under the License is distributed on an "AS IS" BASIS,
# * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# * See the License for the specific language governing permissions and
# * limitations under the License.
# *
#* *****************************************************************************

import os
import sys

dir_path = os.path.dirname(os.path.realpath(__file__))
sys.path.append(os.path.join(dir_path, "../../"))

from raft.framework.plugins.ut_raft.configRead import ConfigRead
from raft.framework.plugins.ut_raft.utPlayer import utPlayer
from raft.framework.plugins.ut_raft.utUserResponse import utUserResponse
from raft.framework.plugins.ut_raft import utHelperClass
from raft.framework.core.logModule import logModule
from Classes.tvSettings import tvSettingsClass

class tvSettingsHelperClass(utHelperClass):

    def __init__(self, testName:str, qcId:str, log:logModule=None ):
        """
        Initializes the test class with test name, setup configuration, and sessions for the device.
        Args:
            testName (str) : name of the test
            qcId (str): QC ID of the test.
            log (class, optional): Parent log class. Defaults to None.
        """
        self.testName  = ""
        self.testSetupPath = os.path.join(dir_path, "tvSettings_L3_testSetup.yml")
        self.moduleName = "tvSettings"
        self.rackDevice = "dut"

        super().__init__(testName, qcId, log)

        # Load test setup configuration
        self.testSetup = ConfigRead(self.testSetupPath, self.moduleName)

        # Open Sessions for player, secondary player and for hal test
        self.player_session = self.dut.getConsoleSession("ssh_player")
        self.hal_session = self.dut.getConsoleSession("ssh_hal_test")

        deviceTestSetup = self.cpe.get("test")
        socVendor = self.cpe.get("soc_vendor")

        # Create player and secondary player Class
        self.testPlayer = utPlayer(self.player_session, socVendor)

        # Create user response Class
        self.testUserResponse = utUserResponse()

        # Get path to device profile file
        self.moduleConfigProfileFile = os.path.join(dir_path, deviceTestSetup.get("profile"))

        self.targetWorkspace = self.cpe.get("target_directory")
        self.targetWorkspace = os.path.join(self.targetWorkspace, self.moduleName)
        self.streamDownloadURL = deviceTestSetup.get("streams_download_url")

    def testDownloadAllAssets(self):
        """
        Downloads the test artifacts and streams listed in the test setup configuration.
        This function retrieves TV settings configurations and other necessary files and
        saves them on the DUT (Device Under Test).
        Args:
            None
        """

        # List of streams with path
        self.testStreams = []
        url = []

        streamPaths = self.testSetup.get("assets").get("device").get(self.testName).get("streams")

        # Download test streams to device
        if streamPaths and self.streamDownloadURL:
            for streamPath in streamPaths:
                url.append(os.path.join(self.streamDownloadURL, streamPath))
                self.testStreams.append(os.path.join(self.targetWorkspace, os.path.basename(streamPath)))
            self.downloadToDevice(url, self.targetWorkspace, self.rackDevice)

    def testDownloadAssetsByUrl(self, stream_url):
        """
        Downloads a single stream listed in the test-setup configuration file to the dut.

        Args:
            stream_url (str): The URL of the stream to download.
        """

        # Ensure the testStreams list is cleared
        self.testStreams = []
        url = []

        # Download the specified stream to the device
        if stream_url is not None:
            url.append(os.path.join(self.streamDownloadURL, stream_url))
            self.downloadToDevice(url, self.targetWorkspace, self.rackDevice)
            self.testStreams.append(os.path.join(self.targetWorkspace, os.path.basename(stream_url)))

    def testCleanAssetsByUrl(self, stream_path):
        """
        Removes the specified asset copied to the dut.

        Args:
            stream_path (str): The path of the stream to delete from the device.
        """
        # Delete only the specified stream from the device
        self.deleteFromDevice([stream_path])

    def testCleanAllAssets(self):
        """
        Removes the downloaded assets and test streams from the DUT after test execution.
        Args:
            None
        """
        self.deleteFromDevice(self.testStreams)


    def testPrepareFunction(self):
        """
        Prepares the environment and assets required for the test.
        This function:
        - Downloads the required assets (if applicable).
        - Creates tvSettingsClass.
        Returns:
            bool
        """

        # Get stream info from the test setup configuration
        streamInfo = self.testSetup.get("assets").get("device").get(self.testName).get("streams")

        # Check the length of streamInfo and decide whether to download assets
        if len(streamInfo) == 1:
            # Download the assets listed in the test setup configuration file if len is 1
            self.testDownloadAllAssets()


        # Create the tvSettings class
        self.testtvSettings = tvSettingsClass(self.moduleConfigProfileFile , self.hal_session, self.targetWorkspace )

        return True

    def testEndFunction(self, powerOff=True):
        """
        Cleans up after the test execution.
        - Cleans the assets downloaded to the device if len of streamInfo is 1.
        - Deletes the tvSettings instance.
        Args:
            powerOff (bool): If True, power off the device. Defaults to True.
        """
        # Get stream info from the test setup configuration
        streamInfo = self.testSetup.get("assets").get("device").get(self.testName).get("streams")

        # Clean the assets only if len is 1
        if len(streamInfo) == 1:
            self.testCleanAllAssets()

        # Clean up the tvSettings instance
        del self.testtvSettings

    def testExceptionCleanUp(self):
        """
        Handles cleanup in case of an exception during test execution.
        - Cleans the assets downloaded to the device if len of streamInfo is 1.
        """
        # Get stream info from the test setup configuration
        streamInfo = self.testSetup.get("assets").get("device").get(self.testName).get("streams")

        # Clean the assets only if len is 1
        if len(streamInfo) == 1:
            self.testCleanAllAssets()

