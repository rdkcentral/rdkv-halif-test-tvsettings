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
from raft.framework.core.logModule import logModule

class tvSettings_test26_colorTempBpostOffset(tvSettingsHelperClass):

    bpostValues = [512, -1024, -512, 0, 512, 1023, 0]

    def __init__(self, log:logModule=None):
        """
        Initializes the test26 BpostOffset test.

        Args:
            None.
        """
        self.testName = "test26_BpostOffset"
        self.qcID = '26'
        super().__init__(self.testName, self.qcID, log)

    def testVerifyBpostOffset(self, colorTemperature, bpostValue, saveSetFlag, manual=False):
        """
        Verifies whether the Color Temperature and BpostOffset are set or not.

        Args:
            colorTemperature (int): Color Temperature value.
            bpostValue (int): Bpost value.
            saveSetFlag (int): Save/Set flag (0 or 1).
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Status of Color Temperature and BpostOffset application.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Has Color Temperature {colorTemperature} and BpostOffset {bpostValue} with flag {saveSetFlag} applied? (Y/N):")
        else:
            # TODO: Add automation verification methods
            return False

    def testSetOperation(self):
        """Tests the Set operation for BpostOffset."""

        # Start the stream playback
        for stream in self.testStreams:
            self.testPlayer.play(stream)

            # Get the Color Temperature values
            colorTemperatureValues = self.testtvSettings.getColorTemperatureInfo()

            for colorTemperature in colorTemperatureValues:
                for bpostValue in self.bpostValues:
                    self.log.stepStart(f'Set Operation - Color Temperature: {colorTemperature} BpostOffset: {bpostValue} Stream: {stream}')

                    # Set the Color Temperature and BpostOffset (Save flag = 0 means Set operation)
                    self.testtvSettings.setBpostOffsetValue("TV_OFFSET", colorTemperature, bpostValue, 0)

                    # Verify Set operation manually
                    result = self.testVerifyBpostOffset(colorTemperature, bpostValue, 0, True)
                    self.log.stepResult(result, f'Set Operation - Color Temperature: {colorTemperature} BpostOffset: {bpostValue} Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()


    def testSaveOperation(self):
        """Tests the Save operation for BpostOffset and verifies changes after restart."""

        # Get the Color Temperature values
        colorTemperatureValues = self.testtvSettings.getColorTemperatureInfo()

        # Loop through each color temperature and corresponding BpostOffset value to set them
        for colorTemperature, bpostValue in zip(colorTemperatureValues, self.bpostValues):
            # Set the Color Temperature and BpostOffset (Save flag = 1 means Save operation)
            self.testtvSettings.setBpostOffsetValue("TV_OFFSET", colorTemperature, bpostValue, 1)

        # After setting all values, loop through the streams to play them
        for stream in self.testStreams:
            self.testPlayer.play(stream)

            # Verify the Save operation manually after stream playback
            for colorTemperature, bpostValue in zip(colorTemperatureValues, self.bpostValues):
                self.log.stepStart(f'Save Operation - Color Temperature: {colorTemperature} BpostOffset: {bpostValue} Stream: {stream}')

                # Set the Color Temperature to apply the saved BpostOffset value
                self.testtvSettings.setColorTempLevel(colorTemperature)

                # Now verify the Save operation manually after restart
                result = self.testVerifyBpostOffset(colorTemperature, bpostValue, 1, True)
                self.log.stepResult(result, f'Save Operation - Color Temperature: {colorTemperature} BpostOffset: {bpostValue} Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

            # Reset each color temperature to the default BpostOffset value (e.g., 0)
            defaultBpostValue = 0  # or whatever your default value is
            for colorTemperature in colorTemperatureValues:
                self.testtvSettings.setBpostOffsetValue("TV_OFFSET", colorTemperature, defaultBpostValue, 1)
                self.log.info(f'Reset Color Temperature {colorTemperature} to default BpostOffset value: {defaultBpostValue}')


    def testFunction(self):
        """Main function to run both Set and Save tests for BpostOffset."""

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
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test26_colorTempBpostOffset(summeryLog)
    test.run(False)
