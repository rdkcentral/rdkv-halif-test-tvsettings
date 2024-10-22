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

class tvSettings_test25_GpostOffset(tvSettingsHelperClass):

    gpostValues = [512, -1024, -512, 0, 512, 1023]

    def __init__(self):
        """
        Initializes the test25 GpostOffset test.

        Args:
            None.
        """
        self.testName = "test25_GpostOffset"
        super().__init__(self.testName, '25')

    def testVerifyGpostOffset(self, colorTemperature, gpostValue, saveSetFlag, manual=False):
        """
        Verifies whether the Color Temperature and GpostOffset are set or not.

        Args:
            colorTemperature (int): Color Temperature value.
            gpostValue (int): Gpost value.
            saveSetFlag (int): Save/Set flag (0 or 1).
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Status of Color Temperature and GpostOffset application.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Has Color Temperature {colorTemperature} and GpostOffset {gpostValue} with flag {saveSetFlag} applied? (Y/N):")
        else:
            # TODO: Add automation verification methods
            return False

    def testSetOperation(self):
        """Tests the Set operation for GpostOffset."""

        # Start the stream playback
        for stream in self.testStreams:
            self.testPlayer.play(stream)

            # Get the Color Temperature values
            colorTemperatureValues = self.testtvSettings.getColorTemperatureInfo()

            for colorTemperature in colorTemperatureValues:
                for gpostValue in self.gpostValues:
                    self.log.stepStart(f'Set Operation - Color Temperature: {colorTemperature} GpostOffset: {gpostValue} Stream: {stream}')

                    # Set the Color Temperature and GpostOffset (Save flag = 0 means Set operation)
                    self.testtvSettings.setGpostOffsetValue("TV_OFFSET", colorTemperature, gpostValue, 0)

                    # Verify Set operation manually
                    result = self.testVerifyGpostOffset(colorTemperature, gpostValue, 0, True)
                    self.log.stepResult(result, f'Set Operation - Color Temperature: {colorTemperature} GpostOffset: {gpostValue} Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

    def testSaveOperation(self):
        """Tests the Save operation for GpostOffset and verifies changes after restart."""

        # Get the Color Temperature values
        colorTemperatureValues = self.testtvSettings.getColorTemperatureInfo()

        # Loop through Color Temperatures and Gpost values to set them
        for colorTemperature in colorTemperatureValues:
            for gpostValue in self.gpostValues:
                # Save the GpostOffset
                self.testtvSettings.setGpostOffsetValue("TV_OFFSET", colorTemperature, gpostValue, 1)

        # After setting all values, loop through the streams to play them
        for stream in self.testStreams:
            self.testPlayer.play(stream)

            # Verify the Save operation manually after stream playback
            for colorTemperature in colorTemperatureValues:
                for gpostValue in self.gpostValues:
                    self.log.stepStart(f'Save Operation - Color Temperature: {colorTemperature} GpostOffset: {gpostValue}')

                    # Set the Color Temperature to apply the saved GpostOffset value
                    self.testtvSettings.setColorTempLevel(colorTemperature)

                    # Now verify the Save operation manually after restart for Gpost
                    result = self.testVerifyGpostOffset(colorTemperature, gpostValue, 1, True)
                    self.log.stepResult(result, f'Save Operation - Color Temperature: {colorTemperature} GpostOffset: {gpostValue} Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

    def testFunction(self):
        """Main function to run both Set and Save tests for GpostOffset."""

        self.log.testStart(self.testName, '25')

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
    test = tvSettings_test25_GpostOffset()
    test.run(False)
