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

class tvSettings_test34_SetGammaPattern(tvSettingsHelperClass):

    # Predefined bit depths (0: 10-bit, 1: 8-bit)
    bitDepths = [0, 1]
    ten_bit_levels = [20, 1023, 10]  # Level values for 10-bit depth (0-1023 range)
    eight_bit_levels = [20, 255, 10]  # Level values for 8-bit depth (0-255 range)

    def __init__(self):
        """
        Initializes the SetGammaPattern test.

        Args:
            None.
        """
        self.testName = "test34_SetGammaPattern"
        super().__init__(self.testName, '34')

    def testVerifyGammaPattern(self, bitDepth, redLevel, greenLevel, blueLevel, manual=False):
        """
        Verifies whether the gamma pattern is set correctly.

        Args:
            bitDepth (int): 0 for 10-bit, 1 for 8-bit.
            redLevel (int): Red level value.
            greenLevel (int): Green level value.
            blueLevel (int): Blue level value.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Returns the status of gamma pattern.
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Is gamma pattern set to Bit Depth: {bitDepth}, "
                f"Red Level: {redLevel}, Green Level: {greenLevel}, Blue Level: {blueLevel}? (Y/N):"
            )
        else:
            # TODO: Add automation verification methods
            return False

    # TODO: Current version supports only manual verification.
    def testQueryGammaPatternLevel(self, bitDepth, redLevel, greenLevel, blueLevel, manual=False):
        """
        Queries whether the Gamma Pattern levels are to be set or not.

        Args:
            bitDepth (int): Bit depth value (0: 10-bit, 1: 8-bit).
            redLevel (int): Red level value.
            greenLevel (int): Green level value.
            blueLevel (int): Blue level value.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                    Defaults to False.

        Returns:
            bool: Returns the status of Gamma Pattern level.
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Do you want to set Gamma Pattern levels to {bitDepth}, {redLevel}, {greenLevel}, {blueLevel}? (Y/N):"
            )
        else:
            # TODO: Add automation verification methods
            return False

    def testFunction(self):
        """This function tests the Set Gamma Pattern functionality.

        Returns:
            bool: Status of the last gamma pattern verification.
        """
        self.log.testStart(self.testName, '34')

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Enable Gamma Pattern Mode
        self.testtvSettings.setGammaPatternMode(True)

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)

            for bitDepth in self.bitDepths:
                # Determine level ranges based on bit depth
                if bitDepth == 0:  # 10-bit depth case
                    redLevels = self.ten_bit_levels
                    greenLevels = self.ten_bit_levels
                    blueLevels = self.ten_bit_levels
                else:  # 8-bit depth case
                    redLevels = self.eight_bit_levels
                    greenLevels = self.eight_bit_levels
                    blueLevels = self.eight_bit_levels

                # Iterate over the predefined levels in order
                for redLevel, greenLevel, blueLevel in zip(redLevels, greenLevels, blueLevels):
                    self.log.stepStart(
                        f'Bit Depth: {bitDepth}, Stream: {stream}, '
                        f'Red Level: {redLevel}, Green Level: {greenLevel}, Blue Level: {blueLevel}'
                    )

                    # Query the user about setting the gamma pattern
                    result = self.testQueryGammaPatternLevel(bitDepth, redLevel, greenLevel, blueLevel, True)

                    if result:
                        # Set the gamma pattern
                        self.testtvSettings.setGammaPattern(bitDepth, redLevel, greenLevel, blueLevel)

                        # Verify the gamma pattern has been set correctly
                        result = self.testVerifyGammaPattern(bitDepth, redLevel, greenLevel, blueLevel, True)

                    # Log the result of the gamma pattern verification
                    self.log.stepResult(
                        result,
                        f'Bit Depth: {bitDepth}, Stream: {stream}, '
                        f'Red Level: {redLevel}, Green Level: {greenLevel}, Blue Level: {blueLevel}'
                    )

            # Stop the stream playback
            self.testPlayer.stop()

        # Disable Gamma Pattern Mode
        self.testtvSettings.setGammaPatternMode(False)

        # Terminate the tvSettings module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    test = tvSettings_test34_SetGammaPattern()
    test.run(False)
