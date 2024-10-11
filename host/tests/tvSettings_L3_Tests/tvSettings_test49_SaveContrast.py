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

class tvSettings_test49_SaveContrast(utHelperClass):

    testName = "test49_SaveContrast"
    testSetupPath = os.path.join(dir_path, "tvSettings_L3_testSetup.yml")
    moduleName = "tvSettings"
    contrastValues = [0, 25, 50, 75, 100]  # Define contrast values

    def __init__(self):
        """
        Initializes the SaveContrast test.

        Args:
            None.
        """
        super().__init__(self.testName, '49')

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

    def testVerifyContrastValue(self, pictureMode, videoFormat, contrast, manual=False):
        """
        Verifies whether the Contrast value is set or not.

        Args:
            pictureMode (str): Picture Mode.
            videoFormat (str): Video Format.
            contrast (int): Contrast value.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to other verification methods.

        Returns:
            bool: returns the status of contrast value.
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Is contrast value {contrast} applied for Picture Mode: {pictureMode} and Video Format: {videoFormat}? (Y/N):"
            )
        else:
            # TODO: Add automation verification methods
            return False

    def testFunction(self):
        """This function tests saving contrast values with all combinations of picture mode and video format.

        Returns:
            bool
        """
        # Download the assets listed in test setup configuration file
        self.testDownloadAssets()

        # Run Prerequisites listed in the test setup configuration file
        self.testRunPrerequisites()

        self.log.testStart(self.testName, '49')

        # Initialize the tvSettings module
        self.testtvSettings = tvSettingsClass(self.deviceProfile, self.hal_session)

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)

            for pictureMode in self.testtvSettings.getPictureModeInfo():
                for videoFormat in self.testtvSettings.getVideoFormatInfo():
                    for contrast in self.contrastValues:
                        self.log.stepStart(f'Set Contrast Value: {contrast}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {stream}')

                        # Set Picture Mode, Video Format, and Contrast Value
                        self.testtvSettings.setContrast(pictureMode, videoFormat, contrast)

                        result = self.testVerifyContrastValue(pictureMode, videoFormat, contrast, True)

                        self.log.stepResult(result, f'Contrast Value: {contrast}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {stream}')

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
    test = tvSettings_test49_SaveContrast()
    test.run(False)
