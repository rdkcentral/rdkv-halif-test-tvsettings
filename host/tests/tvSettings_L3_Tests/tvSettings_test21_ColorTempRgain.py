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

class tvSettings_test21_ColorTempRgain(tvSettingsHelperClass):

    rgainValues = [0, 512, 1024, 1536, 2047]
    saveSetFlags = [0, 1]  # Save only or set only flags

    def __init__(self):
        """
        Initializes the test21 ColorTempRgain test.

        Args:
            None.
        """
        self.testName = "test21_ColorTempRgain"
        super().__init__(self.testName, '21')

    def testVerifyColorTempRgain(self, colorTemperature, rgain, saveSetFlag, manual=False):
        """
        Verifies whether the Color Temperature and Rgain are set or not.

        Args:
            colorTemperature (int): Color Temperature value.
            rgain (int): Rgain value.
            saveSetFlag (int): Save/Set flag (0 or 1).
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Status of Color Temperature and Rgain application.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Has Color Temperature {colorTemperature} and Rgain {rgain} with flag {saveSetFlag} applied? (Y/N):")
        else:
            # TODO: Add automation verification methods
            return False

    def testSetOperation(self):
        """Tests the Set operation for ColorTempRgain."""

        # Start the stream playback
        for stream in self.testStreams:
            self.testPlayer.play(stream)

            # Get the Color Temperature values
            colorTemperatureValues = self.testtvSettings.getColorTemperatureInfo()

            for colorTemperature in colorTemperatureValues:
                for rgain in self.rgainValues:
                    self.log.stepStart(f'Set Operation - Color Temperature: {colorTemperature} Rgain: {rgain} Stream: {stream}')

                    # Set the Color Temperature and Rgain (Save flag = 0 means Set operation)
                    self.testtvSettings.setRgainValue(colorTemperature, rgain, 0)

                    # Verify Set operation manually
                    result = self.testVerifyColorTempRgain(colorTemperature, rgain, 0, True)
                    self.log.stepResult(result, f'Set Operation - Color Temperature: {colorTemperature} Rgain: {rgain} Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

    def testSaveOperation(self):
        """Tests the Save operation for ColorTempRgain and restarts the stream to verify the changes."""

        # Apply Save operation and ask user if they want to restart the stream to verify
        for stream in self.testStreams:
            self.testPlayer.play(stream)

            # Get the Color Temperature values
            colorTemperatureValues = self.testtvSettings.getColorTemperatureInfo()

            for colorTemperature in colorTemperatureValues:
                for rgain in self.rgainValues:
                    self.log.stepStart(f'Save Operation - Color Temperature: {colorTemperature} Rgain: {rgain} Stream: {stream}')

                    # Set the Color Temperature and Rgain (Save flag = 1 means Save operation)
                    self.testtvSettings.setRgainValue(colorTemperature, rgain, 1)

                    # Stop the current stream
                    self.testPlayer.stop()

                    # Restart the stream
                    self.testPlayer.play(stream)

                    # Set the Color Temperature to the same value to apply the saved Rgain value
                    self.testtvSettings.setColorTempLevel(colorTemperature)

                    # Now verify the Save operation manually after restart and applying color temp
                    resultAfterRestart = self.testVerifyColorTempRgain(colorTemperature, rgain, 1, True)
                    self.log.stepResult(resultAfterRestart, f'Save Operation After Restart - Color Temperature: {colorTemperature} Rgain: {rgain} Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

    def testFunction(self):
        """Main function to run both Set and Save tests for ColorTempRgain."""

        self.log.testStart(self.testName, '21')

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
    test = tvSettings_test21_ColorTempRgain()
    test.run(False)