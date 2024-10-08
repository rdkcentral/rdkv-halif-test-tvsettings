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
# * *******************************************************************************
import os
import sys

dir_path = os.path.dirname(os.path.realpath(__file__))
sys.path.append(os.path.join(dir_path, "../"))

from tvSettings_L3_Tests.tvSettingsHelperClass import tvSettingsHelperClass

class tvSettings_test24_RpostOffset(tvSettingsHelperClass):

    rpostValues = [-1024, -512, 0, 512, 1023]
    saveSetFlags = [0, 1]  # Save only or set only flags

    def __init__(self):
        """
        Initializes the test24 RpostOffset test.

        Args:
            None.
        """
        self.testName = "test24_RpostOffset"
        super().__init__(self.testName, '24')

    def testVerifyRpostOffset(self, colorTemperature, rpostValue, saveSetFlag, manual=False):
        """
        Verifies whether the Color Temperature and RpostOffset are set or not.

        Args:
            colorTemperature (int): Color Temperature value.
            rpostValue (int): Rpost value.
            saveSetFlag (int): Save/Set flag (0 or 1).
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Status of Color Temperature and RpostOffset application.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Has Color Temperature {colorTemperature} and RpostOffset {rpostValue} with flag {saveSetFlag} applied? (Y/N):")
        else:
            # TODO: Add automation verification methods
            return False

    def testSetOperation(self):
        """Tests the Set operation for RpostOffset."""

        # Start the stream playback
        for stream in self.testStreams:
            self.testPlayer.play(stream)

            # Get the Color Temperature values
            colorTemperatureValues = self.testtvSettings.getColorTemperatureInfo()

            for colorTemperature in colorTemperatureValues:
                for rpostValue in self.rpostValues:
                    self.log.stepStart(f'Set Operation - Color Temperature: {colorTemperature} RpostOffset: {rpostValue} Stream: {stream}')

                    # Set the Color Temperature and RpostOffset (Save flag = 0 means Set operation)
                    self.testtvSettings.setRpostOffsetValue(colorTemperature, rpostValue, 0)

                    # Verify Set operation manually
                    result = self.testVerifyRpostOffset(colorTemperature, rpostValue, 0, True)
                    self.log.stepResult(result, f'Set Operation - Color Temperature: {colorTemperature} RpostOffset: {rpostValue} Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

    def testSaveOperation(self):
        """Tests the Save operation for RpostOffset and verifies changes after restart."""

        # Apply Save operation and ask user if they want to restart the stream to verify
        for stream in self.testStreams:
            self.testPlayer.play(stream)

            # Get the Color Temperature values
            colorTemperatureValues = self.testtvSettings.getColorTemperatureInfo()

            for colorTemperature in colorTemperatureValues:
                for rpostValue in self.rpostValues:
                    self.log.stepStart(f'Save Operation - Color Temperature: {colorTemperature} RpostOffset: {rpostValue} Stream: {stream}')

                    # Set the Color Temperature and RpostOffset (Save flag = 1 means Save operation)
                    self.testtvSettings.setRpostOffsetValue(colorTemperature, rpostValue, 1)

                    # Stop the current stream
                    self.testPlayer.stop()

                    # Restart the stream
                    self.testPlayer.play(stream)

                    # Set the Color Temperature to the same value to apply the saved RpostOffset value
                    self.testtvSettings.setColorTempLevel(colorTemperature)

                    # Now verify the Save operation manually after restart
                    resultAfterRestart = self.testVerifyRpostOffset(colorTemperature, rpostValue, 1, True)
                    self.log.stepResult(resultAfterRestart, f'Save Operation After Restart - Color Temperature: {colorTemperature} RpostOffset: {rpostValue} Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

    def testFunction(self):
        """Main function to run both Set and Save tests for RpostOffset."""

        self.log.testStart(self.testName, '24')

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # First, run the Set operation test
        self.testSetOperation()

        # Then, run the Save operation test
        self.testSaveOperation()

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        return True

if __name__ == '__main__':
    test = tvSettings_test24_RpostOffset()
    test.run(False)