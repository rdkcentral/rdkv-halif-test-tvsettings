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

class tvSettings_test07_BacklightFade(utHelperClass):

    testName = "test07_BacklightFade"
    testSetupPath = os.path.join(dir_path, "tvSettings_L3_testSetup.yml")
    moduleName = "tvSettings"
    rackDevice = "dut"

    # Updated minimal backlight values and durations for better fade visibility
    backlightValues = [0, 50, 100]  # Using extremes and a middle value for better visibility
    fadeDurations = [500, 1000]  # Keeping fade durations shorter but noticeable

    def __init__(self):
        """
        Initializes the test07 BacklightFade test.

        Args:
            None.
        """
        super().__init__(self.testName, '1')

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
        test = self.testSetup.get("assets").get("device").get(self.testName)
        cmds = test.get("execute")
        if cmds is not None:
            for cmd in cmds:
                self.writeCommands(cmd)

    def testVerifyBacklightFadeLevel(self, fromVal, toVal, fadeDuration, manual=False):
        """
        Verifies whether the BacklightFade is set or not.

        Args:
            fromVal (int): Starting backlight value
            toVal (int): Ending backlight value
            fadeDuration (int): Fade duration in milliseconds
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to other verification methods

        Returns:
            bool : returns the status of backlight fade
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Has BacklightFade from {fromVal} to {toVal} with duration {fadeDuration} ms applied? (Y/N):")
        else:
            return False

    def testFunction(self):
        """This function tests the BacklightFade Levels

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
        self.testtvSettings.initialise()

        for stream in self.testStreams:
            for fromVal in self.backlightValues:
                for toVal in self.backlightValues:
                    for fadeDuration in self.fadeDurations:
                        self.log.stepStart(f'BacklightFade from {fromVal} to {toVal} with duration {fadeDuration} ms Stream:{stream}')

                        # Start the stream playback before each setBacklightFade
                        self.testPlayer.play(stream)

                        # Set backlightFade
                        self.testtvSettings.setBacklightFade(fromVal, toVal, fadeDuration)

                        result = self.testVerifyBacklightFadeLevel(fromVal, toVal, fadeDuration, True)

                        self.log.stepResult(result, f'BacklightFade from {fromVal} to {toVal} with duration {fadeDuration} ms Stream:{stream}')

                        # Stop the stream playback after each fade operation
                        self.testPlayer.stop()

        # Clean the assets downloaded to the device
        self.testCleanAssets()

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        # Delete the tvSettings class
        del self.testtvSettings

        return result

if __name__ == '__main__':
    test = tvSettings_test07_BacklightFade()
    test.run(False)
