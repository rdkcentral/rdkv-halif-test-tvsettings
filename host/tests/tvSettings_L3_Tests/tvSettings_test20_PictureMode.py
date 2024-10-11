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

from tvSettings_L3_Tests.tvSettingsHelperClass import tvSettingsHelperClass

class tvSettings_test20_PictureMode(tvSettingsHelperClass):

    def __init__(self):
        """
        Initializes the test20 Picture Mode test.

        Args:
            None.
        """
        self.testName = "test20_PictureMode"
        super().__init__(self.testName, '20')

    def testQueryPictureModeLevel(self, pictureMode, manual=False):
        """
        Queries whether the Picture Mode should be applied.

        Args:
            pictureMode (int): Picture Mode value.
            manual (bool, optional): Indicates if manual verification is used.
                                     Defaults to False.

        Returns:
            bool: Status of Picture Mode application.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Do you want to apply Picture Mode level {pictureMode}? (Y/N):")
        else:
            # TODO: Add automation verification methods
            return False

    def testVerifyPictureModeLevel(self, pictureMode, manual=False):
        """
        Verifies whether the Picture Mode is set or not.

        Args:
            pictureMode (int): Picture Mode value.
            manual (bool, optional): Indicates if manual verification is used.
                                     Defaults to False.

        Returns:
            bool: Status of Picture Mode application.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Has Picture Mode level {pictureMode} applied? (Y/N):")
        else:
            # TODO: Add automation verification methods
            return False

    def testFunction(self):
        """
        Executes the Picture Mode test.

        This method:
        - Initializes the tvSettings module.
        - Plays each stream while setting and verifying Picture Mode levels.

        Returns:
            bool: Returns the final verification result.
        """
        self.log.testStart(self.testName, '20')

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)

            for pictureMode in self.testtvSettings.getPictureModeInfo():
                self.log.stepStart(f'Picture Mode Level: {pictureMode} Stream: {stream}')

                # Query if Picture Mode level should be applied
                result = self.testQueryPictureModeLevel(pictureMode, True)

                self.log.stepResult(result, f'Picture Mode Level: {pictureMode} Stream: {stream}')

                if result:
                    # Set the Picture Mode level
                    self.testtvSettings.setPictureMode(pictureMode)

                    # Verify if Picture Mode level has been applied
                    result = self.testVerifyPictureModeLevel(pictureMode, True)

                    self.log.stepResult(result, f'Picture Mode Level: {pictureMode} Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    test = tvSettings_test20_PictureMode()
    test.run(False)
