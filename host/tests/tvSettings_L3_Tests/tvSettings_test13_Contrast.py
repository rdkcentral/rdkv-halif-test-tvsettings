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

dir_path = os.path.dirname(os.path.realpath(__file__))
sys.path.append(os.path.join(dir_path, "../"))

from Classes.tvSettings import tvSettingsClass
from raft.framework.plugins.ut_raft import utHelperClass
from raft.framework.plugins.ut_raft.configRead import ConfigRead
from raft.framework.plugins.ut_raft.utPlayer import utPlayer
from raft.framework.plugins.ut_raft.utUserResponse import utUserResponse

class tvSettings_test13_Contrast(utHelperClass):

    testName = "test13_Contrast"
    testSetupPath = os.path.join(dir_path, "tvSettings_L3_testSetup.yml")
    moduleName = "tvSettings"
    rackDevice = "dut"
    contrastLevels = [0, 25, 50, 75, 100]

    def __init__(self):
        """
        Initializes the test13 Contrast test.

        Args:
            None.
        """
        super().__init__(self.testName, '1')

        # Test Setup configuration file
        self.testSetup = ConfigRead(self.testSetupPath, self.moduleName)
        self.formatChangeCB = self.testSetup.get("callback").get("formatChange_status")
        self.contentChangeCB = self.testSetup.get("callback").get("contentChange_status")
        self.resolutionChangeCB = self.testSetup.get("callback").get("resolutionChange_status")
        self.frameRateChangeCB = self.testSetup.get("callback").get("frameRateChange_status")

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

    def testDownloadAssets(self):
        """
        Downloads the artifacts and streams listed in test-setup configuration file to the dut.

        Args:
            None.
        """

        # List of streams with path
        self.testStreams = []

        self.deviceDownloadPath = self.cpe.get("target_directory")

        test = self.testSetup.get("assets").get("device").get(self.testName)

        # Download test artifacts to device
        url = test.get("artifacts")
        if url is not None:
            self.downloadToDevice(url, self.deviceDownloadPath, self.rackDevice)

        # Download test streams to device
        url = test.get("streams")
        if url is not None:
            self.downloadToDevice(url, self.deviceDownloadPath, self.rackDevice)
            for streampath in url:
                self.testStreams.append(os.path.join(self.deviceDownloadPath, os.path.basename(streampath)))

    def testCleanAssets(self):
        """
        Removes the assets copied to the dut.

        Args:
            None.
        """
        self.deleteFromDevice(self.testStreams)

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

    # TODO: Current version supports only manual verification.
    def testVerifyContrastLevel(self, contrast, manual=False):
        """
        Verifies whether the Contrast is set or not.

        Args:
            contrast (int) : contrast value
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to other verification methods

        Returns:
            bool : returns the status of contrast
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Has contrast level {contrast} applied? (Y/N):")
        else:
            # TODO: Add automation verification methods
            return False

    def testFunction(self):
        """This function tests the ContrastLevels

        Returns:
            bool
        """

        # Download the assets listed in test setup configuration file
        self.testDownloadAssets()

        # Run Prerequisites listed in the test setup configuration file
        self.testRunPrerequisites()

        # Create the tvSettings class
        self.testtvSettings = tvSettingsClass(self.deviceProfile, self.hal_session)

        self.log.testStart(self.testName, '1')

        # Initialize the tvSettings module
        self.testtvSettings.initialise(self.formatChangeCB, self.contentChangeCB, self.resolutionChangeCB, self.frameRateChangeCB)

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)

            for contrast in self.contrastLevels:
                self.log.stepStart(f'Contrast Level:{contrast} Stream:{stream}')

                #set the Contrast level
                self.testtvSettings.setContrastLevel(contrast)

                result = self.testVerifyContrastLevel(contrast, True)

                self.log.stepResult(result, f'Contrast Level:{contrast} Stream:{stream}')

            # Stop the stream playback
            self.testPlayer.stop()

        # Clean the assets downloaded to the device
        self.testCleanAssets()

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        # Delete the tvSettings class
        del self.testtvSettings

        return result


if __name__ == '__main__':
    test = tvSettings_test13_Contrast()
    test.run(False)
