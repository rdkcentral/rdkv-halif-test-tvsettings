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

class tvSettings_test34_SetGammaPattern(tvSettingsHelperClass):
    """
    Test class for validating Gamma Pattern settings.

    This class is designed to test the functionality of setting and verifying
    gamma patterns for different bit depths (10-bit and 8-bit) on the device.

    Attributes:
        testName (str): Name of the test.
        bitDepths (list): Predefined bit depths (0 for 10-bit, 1 for 8-bit).
        ten_bit_levels (list): Level values for 10-bit depth (0-1023 range).
        eight_bit_levels (list): Level values for 8-bit depth (0-255 range).
    """

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

    def getLevelRanges(self, bitDepth):
        """
        Retrieves level ranges based on the specified bit depth.

        Args:
            bitDepth (int): 0 for 10-bit, 1 for 8-bit.

        Returns:
            list: List of levels for Red, Green, and Blue channels.
        """
        return (self.ten_bit_levels if bitDepth == 0 else self.eight_bit_levels) * 3  # Return levels for R, G, B

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
            bool: Returns the status of gamma pattern verification.
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Is gamma pattern set to Bit Depth: {bitDepth}, "
                f"Red Level: {redLevel}, Green Level: {greenLevel}, Blue Level: {blueLevel}? (Y/N):"
            )
        else:
            # TODO: Add automation verification methods
            return False

    def testFunction(self):
        """
        Tests the Set Gamma Pattern functionality.

        This method:
          - Initializes the tvSettings module.
          - Enables the gamma pattern mode.
          - Loops through each stream and bit depth.
          - Sets the gamma pattern for each color level.
          - Verifies the gamma pattern for each setting.
          - Stops the stream playback after testing.

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
                levels = self.getLevelRanges(bitDepth)  # Get levels for current bit depth

                # Iterate over the predefined levels in order (R, G, B)
                for redLevel, greenLevel, blueLevel in zip(levels, levels, levels):
                    self.log.stepStart(
                        f'Bit Depth: {bitDepth}, Stream: {stream}, '
                        f'Red Level: {redLevel}, Green Level: {greenLevel}, Blue Level: {blueLevel}'
                    )

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
