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

class tvSettings_test14_Hue(tvSettingsHelperClass):

    hueLevels = [0, 25, 50, 75, 100, 50]

    def __init__(self):
        """
        Initializes the test14 Hue test.

        This constructor sets the test name and initializes the parent class.

        Args:
            None.
        """
        self.testName = "test14_Hue"
        super().__init__(self.testName, '14')

    def testVerifyHueLevel(self, hue, manual=False):
        """
        Verifies whether the Hue level is applied.

        This method checks the hue level either manually or via automation.

        Args:
            hue (int): Hue value.
            manual (bool, optional): Indicates if manual verification is used.
                                     Defaults to False.

        Returns:
            bool: Status of hue level application.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Has hue level {hue} applied? (Y/N):")
        else:
            return False  # TODO: Add automation verification methods

    def testFunction(self):
        """
        Executes the Hue test.

        This method:
        - Initializes the tvSettings module.
        - Plays each stream while setting and verifying hue levels.

        Returns:
            bool: Returns the final verification result.
        """
        self.log.testStart(self.testName, '14')

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)

            for hue in self.hueLevels:
                self.log.stepStart(f'Hue Level: {hue} Stream: {stream}')

                # Set the hue level
                self.testtvSettings.setHueLevel(hue)

                result = self.testVerifyHueLevel(hue, True)

                self.log.stepResult(result, f'Hue Level: {hue} Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    test = tvSettings_test14_Hue()
    test.run(False)
