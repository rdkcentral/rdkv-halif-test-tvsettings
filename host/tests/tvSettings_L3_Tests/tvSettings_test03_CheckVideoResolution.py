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
#* ******************************************************************************

import os
import sys
import time

dir_path = os.path.dirname(os.path.realpath(__file__))
sys.path.append(os.path.join(dir_path, "../"))

from Classes.tvSettings import tvSettingsClass
from raft.framework.plugins.ut_raft import utHelperClass
from raft.framework.plugins.ut_raft.configRead import ConfigRead
from raft.framework.plugins.ut_raft.utPlayer import utPlayer
from raft.framework.plugins.ut_raft.utUserResponse import utUserResponse

class tvSettings_test03_CheckVideoResolution(utHelperClass):

    testName = "test03_CheckVideoResolution"  # Updated test name to reflect the test number
    testSetupPath = os.path.join(dir_path, "tvSettings_L3_testSetup.yml")
    moduleName = "tvSettings"
    rackDevice = "dut"

    def __init__(self):
        """
        Initializes the test03 VideoResolution test.

        Args:
            None.
        """
        super().__init__(self.testName, '3')  # Set test number to 3

        # Test Setup configuration file
        self.testSetup = ConfigRead(self.testSetupPath, self.moduleName)

        # Open Session for player
        self.player_session = self.dut.getConsoleSession("ssh_player")

        # Open Session for hal test
        self.hal_session = self.dut.getConsoleSession("ssh_hal_test")

        player = self.cpe.get("test").get("player")

        # Create player Class
        self.testPlayer = utPlayer(self.player_session, player)

        # Create user response Class
        self.testUserResponse = utUserResponse()

        # Get path to device profile file
        self.deviceProfile = os.path.join(dir_path, self.cpe.get("test").get("profile"))

    def testDownloadAssets(self, stream_url):
        """
        Downloads a single stream listed in the test-setup configuration file to the dut.

        Args:
            stream_url (str): The URL of the stream to download.
        """

        # Ensure the testStreams list is cleared
        self.testStreams = []

        self.deviceDownloadPath = self.cpe.get("target_directory")

        test = self.testSetup.get("assets").get("device").get(self.testName)

        # Download test artifacts to device
        url = test.get("artifacts")
        if url is not None:
            self.downloadToDevice(url, self.deviceDownloadPath, self.rackDevice)

        # Download the specified stream to the device
        if stream_url is not None:
            self.downloadToDevice([stream_url], self.deviceDownloadPath, self.rackDevice)
            self.testStreams.append(os.path.join(self.deviceDownloadPath, os.path.basename(stream_url)))

    def testCleanAssets(self, stream_path):
        """
        Removes the specified asset copied to the dut.

        Args:
            stream_path (str): The path of the stream to delete from the device.
        """
        # Delete only the specified stream from the device
        self.deleteFromDevice([stream_path])

    def testRunPrerequisites(self):
        """
        Runs Prerequisite commands listed in test-setup configuration file on the dut.

        Args:
            None.
        """

        # Run test specific commands
        test = self.testSetup.get("assets").get("device").get(self.testName)
        cmds = test.get("execute")
        if cmds is not None:
            for cmd in cmds:
                self.writeCommands(cmd)

    def testFunction(self):
        """This function tests the VideoResolution Levels

        Returns:
            bool
        """

        # Run Prerequisites listed in the test setup configuration file
        self.testRunPrerequisites()

        # Create the tvSettings class
        self.testtvSettings = tvSettingsClass(self.deviceProfile, self.hal_session)

        self.log.testStart(self.testName, '3')  # Log start of the test with test number

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Get the list of streams
        streams = self.testSetup.get("assets").get("device").get(self.testName).get("streams")
        video_resolutions = self.testtvSettings.getVideoResolutionInfo()

        # Iterate through each resolution and corresponding stream URL
        for resolution, stream_url in zip(video_resolutions, streams):
            # Download the individual stream (using the updated testDownloadAssets)
            self.testDownloadAssets(stream_url)

            stream_full_path = os.path.join(self.deviceDownloadPath, os.path.basename(stream_url))

            # Start the stream playback
            self.testPlayer.play(stream_full_path)
            time.sleep(10)

            self.log.stepStart(f'videoResolution Level:{resolution} Stream:{stream_full_path}')

            # Check video resolution
            videoResolution = self.testtvSettings.checkVideoResolution()

            # Log the result of the test
            self.log.stepResult(resolution in videoResolution, f'Video Resolution {resolution} Test')

            # Stop the stream playback
            self.testPlayer.stop()

            # Clean the assets (delete the downloaded stream using testCleanAssets)
            self.testCleanAssets(stream_full_path)

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        # Delete the tvSettings class
        del self.testtvSettings

        return True


if __name__ == '__main__':
    test = tvSettings_test03_CheckVideoResolution()
    test.run(False)
