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

class tvSettings_test32_ComponentLuma(tvSettingsHelperClass):

    # Predefined luma values ranging from 1 to 30
    lumaValues = [1, 5, 10, 15, 30]
    rackDevice = "dut"

    def __init__(self):
        """
        Initializes the ComponentLuma test.

        Args:
            None.
        """
        self.testName = "test32_ComponentLuma"
        super().__init__(self.testName, '32')

    # TODO: Current version supports only manual verification.
    def testVerifyComponentLuma(self, lumaValue, manual=False):
        """
        Verifies whether the Component Luma is set correctly.

        Args:
            lumaValue (int): The component luma value to verify.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Status indicating whether the component luma is set correctly.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Has component luma value {lumaValue} applied? (Y/N):")
        else:
            # TODO: Add automation verification methods
            return False

    def testFunction(self):
        """This function tests the Component Luma settings.

        Returns:
            bool: Status of the last verification.
        """
        # Run prerequisites listed in the test setup configuration file
        self.testRunPrerequisites()

        self.log.testStart(self.testName, '32')

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Set the Component Management System (CMS) state
        self.testtvSettings.setCMSState()

        # Get available TV Data Colors
        tvDataColors = self.testtvSettings.getTVDataColor()

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)

            for colorIndex in tvDataColors:  # Iterate through available color indices
                for lumaValue in self.lumaValues:
                    self.log.stepStart(f'Color Index: {colorIndex}, Component Luma Value: {lumaValue}, Stream: {stream}')

                    # Set the component luma value
                    self.testtvSettings.setComponentLuma(colorIndex, lumaValue)

                    # Verify the component luma value
                    result = self.testVerifyComponentLuma(lumaValue, True)

                    # Log the result of the verification
                    self.log.stepResult(result, f'Color Index: {colorIndex}, Component Luma Value: {lumaValue}, Stream: {stream}')

                    #Restart the stream for the current luma value
                    self.testPlayer.stop()
                    self.testPlayer.play(stream)

                    # Verify the component luma value after the stream restart
                    result = self.testVerifyComponentLuma(lumaValue, True)
                    self.log.stepResult(result, f'Verified Component Luma after stream restart for Color Index: {colorIndex}')

            # Stop the stream playback
            self.testPlayer.stop()

        # Terminate the tvSettings module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    test = tvSettings_test32_ComponentLuma()
    test.run(False)
