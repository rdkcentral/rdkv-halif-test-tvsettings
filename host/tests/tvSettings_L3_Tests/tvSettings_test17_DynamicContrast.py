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

class tvSettings_test17_DynamicContrast(tvSettingsHelperClass):

    dynamicContrastStates = ["enabled", "disabled"]

    def __init__(self):
        """
        Initializes the test17 DynamicContrast test.

        This constructor sets the test name and initializes the parent class.

        Args:
            None.
        """
        self.testName = "test17_DynamicContrast"
        super().__init__(self.testName, '17')

    def testVerifyDynamicContrast(self, dynamicContrast, manual=False):
        """
        Verifies whether the Dynamic Contrast level is applied.

        This method checks the dynamic contrast either manually or via automation.

        Args:
            dynamicContrast (str): Dynamic Contrast value ("enabled" or "disabled").
            manual (bool, optional): Indicates if manual verification is used.
                                     Defaults to False.

        Returns:
            bool: Status of Dynamic Contrast application.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Has Dynamic Contrast {dynamicContrast} applied? (Y/N):")
        else:
            return False  # TODO: Add automation verification methods

    def testFunction(self):
        """
        Executes the Dynamic Contrast test.

        This method:
        - Initializes the tvSettings module.
        - Plays each stream while setting and verifying dynamic contrast states.

        Returns:
            bool: Returns the final verification result.
        """
        self.log.testStart(self.testName, '17')

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)

            for dynamicContrast in self.dynamicContrastStates:
                self.log.stepStart(f'Dynamic Contrast: {dynamicContrast} Stream: {stream}')

                # Set the Dynamic Contrast level
                self.testtvSettings.setDynamicContrast(dynamicContrast)

                result = self.testVerifyDynamicContrast(dynamicContrast, True)

                self.log.stepResult(result, f'Dynamic Contrast: {dynamicContrast} Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    test = tvSettings_test17_DynamicContrast()
    test.run(False)
