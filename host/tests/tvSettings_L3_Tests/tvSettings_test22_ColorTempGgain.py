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
# * *******************************************************************************
import os
import sys

dir_path = os.path.dirname(os.path.realpath(__file__))
sys.path.append(os.path.join(dir_path, "../"))

from tvSettings_L3_Tests.tvSettingsHelperClass import tvSettingsHelperClass

class tvSettings_test22_ColorTempGgain(tvSettingsHelperClass):

    ggainValues = [0, 512, 1024, 1536, 2047]  # Ggain values to test
    saveSetFlags = [0, 1]  # Save only or set only flags

    def __init__(self):
        """
        Initializes the test22 ColorTempGgain test.

        Args:
            None.
        """
        self.testName = "test22_ColorTempGgain"
        super().__init__(self.testName, '22')

    def testVerifyColorTempGgain(self, colorTemperature, ggain, saveSetFlag, manual=False):
        """
        Verifies whether the Color Temperature and Ggain are set or not.

        Args:
            colorTemperature (int): Color Temperature value.
            ggain (int): Ggain value.
            saveSetFlag (int): Save/Set flag (0 or 1).
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Status of Color Temperature and Ggain application.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Has Color Temperature {colorTemperature} and Ggain {ggain} with flag {saveSetFlag} applied? (Y/N):")
        else:
            # TODO: Add automation verification methods
            return False

    def testSetOperation(self):
        """Tests the Set operation for ColorTempGgain."""

        # Start the stream playback
        for stream in self.testStreams:
            self.testPlayer.play(stream)

            # Get the Color Temperature values
            colorTemperatureValues = self.testtvSettings.getColorTemperatureInfo()

            for colorTemperature in colorTemperatureValues:
                for ggain in self.ggainValues:
                    self.log.stepStart(f'Set Operation - Color Temperature: {colorTemperature} Ggain: {ggain} Stream: {stream}')

                    # Set the Color Temperature and Ggain (Save flag = 0 means Set operation)
                    self.testtvSettings.setGgainValue("TV_OFFSET", colorTemperature, ggain, 0)

                    # Verify Set operation manually
                    result = self.testVerifyColorTempGgain(colorTemperature, ggain, 0, True)
                    self.log.stepResult(result, f'Set Operation - Color Temperature: {colorTemperature} Ggain: {ggain} Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

    def testSaveOperation(self):
        """Tests the Save operation for ColorTempGgain and restarts the stream to verify the changes."""

        # Apply Save operation and ask user if they want to restart the stream to verify
        for stream in self.testStreams:
            self.testPlayer.play(stream)

            # Get the Color Temperature values
            colorTemperatureValues = self.testtvSettings.getColorTemperatureInfo()

            for colorTemperature in colorTemperatureValues:
                for ggain in self.ggainValues:
                    self.log.stepStart(f'Save Operation - Color Temperature: {colorTemperature} Ggain: {ggain} Stream: {stream}')

                    # Set the Color Temperature and Ggain (Save flag = 1 means Save operation)
                    self.testtvSettings.setGgainValue("TV_OFFSET", colorTemperature, ggain, 1)

                    # Stop the current stream
                    self.testPlayer.stop()

                    # Restart the stream
                    self.testPlayer.play(stream)

                    # Set the Color Temperature to the same value to apply the saved Ggain value
                    self.testtvSettings.setColorTempLevel(colorTemperature)

                    # Now verify the Save operation manually after restart and applying color temp
                    resultAfterRestart = self.testVerifyColorTempGgain(colorTemperature, ggain, 1, True)
                    self.log.stepResult(resultAfterRestart, f'Save Operation After Restart - Color Temperature: {colorTemperature} Ggain: {ggain} Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

    def testFunction(self):
        """Main function to run both Set and Save tests for ColorTempGgain."""

        self.log.testStart(self.testName, '22')

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
    test = tvSettings_test22_ColorTempGgain()
    test.run(False)
