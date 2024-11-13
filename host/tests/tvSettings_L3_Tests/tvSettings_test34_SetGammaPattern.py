#!/usr/bin/env python3
import os
import sys
import time

dir_path = os.path.dirname(os.path.realpath(__file__))
sys.path.append(os.path.join(dir_path, "../"))

from tvSettings_L3_Tests.tvSettingsHelperClass import tvSettingsHelperClass
from raft.framework.core.logModule import logModule

class tvSettings_test34_SetGammaPattern(tvSettingsHelperClass):
    """
    Test class for validating Gamma Pattern settings.

    This class is designed to test the functionality of setting and verifying
    gamma patterns for different bit depths (10-bit and 8-bit) on the device.
    """

    # Predefined bit depths (0: 10-bit, 1: 8-bit)
    bitDepths = [0, 1]

    # Specific level values for each bit depth and RGB combination
    ten_bit_levels = [
        (1023, 0, 0),    # Red
        (0, 1023, 0),    # Green
        (0, 0, 1023),    # Blue
        (1023, 1023, 1023),  # White
        (0, 0, 0)  # White
    ]
    eight_bit_levels = [
        (255, 0, 0),     # Red
        (0, 255, 0),     # Green
        (0, 0, 255),     # Blue
        (255, 255, 255),  # White
        (0, 0, 0)  # White
    ]

    def __init__(self, log:logModule=None):
        """
        Initializes the SetGammaPattern test.
        """
        self.testName = "test34_SetGammaPattern"
        self.qcID = '34'
        super().__init__(self.testName, self.qcID, log)

    def getLevelRanges(self, bitDepth):
        """
        Retrieves level ranges based on the specified bit depth.

        Args:
            bitDepth (int): 0 for 10-bit, 1 for 8-bit.

        Returns:
            list: List of tuples representing (red, green, blue) levels.
        """
        return self.ten_bit_levels if bitDepth == 0 else self.eight_bit_levels

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

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Enable Gamma Pattern Mode
        self.testtvSettings.setGammaPatternMode(1)

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)
            time.sleep(3)

            for bitDepth in self.bitDepths:
                levels = self.getLevelRanges(bitDepth)  # Get predefined RGB levels

                # Iterate over the predefined levels for R, G, B channels
                for redLevel, greenLevel, blueLevel in levels:
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
        self.testtvSettings.setGammaPatternMode(0)

        # Terminate the tvSettings module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test34_SetGammaPattern(summeryLog)
    test.run(False)
