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
# * you may obtain a copy of the License at
# *
# * http://www.apache.org/licenses/LICENSE-2.0
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

class tvSettings_test31_ComponentHue(tvSettingsHelperClass):

    # Predefined hue values ranging from 0 to 100
    hueValues = [0, 25, 50, 75, 100]

    def __init__(self):
        """
        Initializes the ComponentHue test.

        Args:
            None.
        """
        self.testName = "test31_ComponentHue"
        super().__init__(self.testName, '31')

    # TODO: Current version supports only manual verification.
    def testVerifyComponentHue(self, hueValue, manual=False):
        """
        Verifies whether the Component Hue is set correctly.

        Args:
            hueValue (int): The component hue value to verify.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Status indicating whether the component hue is set correctly.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Has component hue value {hueValue} applied? (Y/N):")
        else:
            # TODO: Add automation verification methods
            return False

    def testFunction(self):
        """This function tests the Component Hue settings.

        Returns:
            bool: Status of the last verification.
        """

        self.log.testStart(self.testName, '31')

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Get available TV Data Colors
        tvDataColors = self.testtvSettings.getTVDataColor()

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)

            # Set the Component Management System (CMS) state
            self.testtvSettings.setCMSState(1)

            for colorIndex in tvDataColors:  # Iterate through available color indices
                for hueValue in self.hueValues:
                    self.log.stepStart(f'Color Index: {colorIndex}, Component Hue Value: {hueValue}, Stream: {stream}')

                    # Set the component hue value
                    self.testtvSettings.setComponentHue(colorIndex, hueValue)

                    # Verify the component hue value
                    result = self.testVerifyComponentHue(hueValue, True)

                    # Log the result of the verification
                    self.log.stepResult(result, f'Color Index: {colorIndex}, Component Hue Value: {hueValue}, Stream: {stream}')

                    # Restart the stream for the current hue value
                    self.testPlayer.stop()
                    self.testPlayer.play(stream)

                    # Verify the component hue value after the stream restart
                    result = self.testVerifyComponentHue(hueValue, True)
                    self.log.stepResult(result, f'Verified Component Hue after stream restart for Color Index: {colorIndex}')

            # Stop the stream playback
            self.testPlayer.stop()

            # Reset the Component Management System (CMS) state
            self.testtvSettings.setCMSState(0)

        # Terminate the tvSettings module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    test = tvSettings_test31_ComponentHue()
    test.run(False)
