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

class tvSettings_test30_ComponentSaturation(tvSettingsHelperClass):

    # Predefined saturation values ranging from 0 to 100
    saturationValues = [0, 25, 50, 75, 100]

    def __init__(self):
        """
        Initializes the ComponentSaturation test.

        Args:
            None.
        """
        self.testName = "test30_ComponentSaturation"
        super().__init__(self.testName, '30')

    def testVerifyComponentSaturation(self, saturationValue, manual=False):
        """
        Verifies whether the Component Saturation is set correctly.

        Args:
            saturationValue (int): The component saturation value to verify.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Status indicating whether the component saturation is set correctly.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Has component saturation value {saturationValue} applied? (Y/N):")
        else:
            # TODO: Add automation verification methods
            return False

    def testFunction(self):
        """This function tests the Component Saturation settings.

        Returns:
            bool: Status of the last verification.
        """

        self.log.testStart(self.testName, '30')

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Get available TV Data Colors
        tvDataColors = self.testtvSettings.getTVDataColor()

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)

            # Enable the Component Management System (CMS)
            self.testtvSettings.setCMSState(1)

            for colorIndex in tvDataColors:  # Iterate through available color indices
                for saturationValue in self.saturationValues:
                    self.log.stepStart(f'Color Index: {colorIndex}, Component Saturation Value: {saturationValue}, Stream: {stream}')

                    # Set the component saturation value
                    self.testtvSettings.setComponentSaturation(colorIndex, saturationValue)

                    # Verify the component saturation value
                    result = self.testVerifyComponentSaturation(saturationValue, True)

                    # Log the result of the verification
                    self.log.stepResult(result, f'Color Index: {colorIndex}, Component Saturation Value: {saturationValue}, Stream: {stream}')

                    # Restart the stream for the current saturation value
                    self.testPlayer.stop()
                    self.testPlayer.play(stream)

                    # Verify the component saturation value after the stream restart
                    result = self.testVerifyComponentSaturation(saturationValue, True)
                    self.log.stepResult(result, f'Verified Component Saturation after stream restart for Color Index: {colorIndex}')

            # Disable the Component Management System (CMS) after testing
            self.testtvSettings.setCMSState(0)
            # Stop the stream playback
            self.testPlayer.stop()

        # Terminate the tvSettings module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    test = tvSettings_test30_ComponentSaturation()
    test.run(False)
