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
from raft.framework.core.logModule import logModule

class tvSettings_test21_ColorTempRgain(tvSettingsHelperClass):

    rgainValues = [0, 512, 1024, 1536, 2047, 1024]

    def __init__(self, log:logModule=None):
        """
        Initializes the test21 ColorTempRgain test.

        Args:
            None.
        """
        self.testName = "test21_ColorTempRgain"
        self.qcID = '21'
        super().__init__(self.testName, self.qcID, log)

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
                    self.testtvSettings.setRgainValue("TV_OFFSET", colorTemperature, rgain, 0)

                    # Verify Set operation manually
                    result = self.testVerifyColorTempRgain(colorTemperature, rgain, 0, True)

                    self.log.stepResult(result, f'Set Operation - Color Temperature: {colorTemperature} Rgain: {rgain} Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

    def testSaveOperation(self):
        """Tests the Save operation for ColorTempRgain and restarts the stream to verify the changes."""

        # Get the Color Temperature values
        colorTemperatureValues = self.testtvSettings.getColorTemperatureInfo()

        # Loop through each color temperature and Rgain value to set them
        for colorTemperature, rgain in zip(colorTemperatureValues, self.rgainValues):
            # Set the Color Temperature and Rgain (Save flag = 1 means Save operation)
            self.testtvSettings.setRgainValue("TV_OFFSET", colorTemperature, rgain, 1)

        # After setting all values, loop through the streams to play them
        for stream in self.testStreams:
            self.testPlayer.play(stream)

            # Re-pair values for each stream playback iteration
            for colorTemperature, rgain in zip(colorTemperatureValues, self.rgainValues):
                self.log.stepStart(f'Save Operation - Color Temperature: {colorTemperature} Rgain: {rgain} Stream: {stream}')

                # Set the Color Temperature to apply the saved Rgain value
                self.testtvSettings.setColorTempLevel(colorTemperature)

                # Now verify the Save operation manually after restart
                result = self.testVerifyColorTempRgain(colorTemperature, rgain, 1, True)
                self.log.stepResult(result, f'Save Operation - Color Temperature: {colorTemperature} Rgain: {rgain} Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

            # Reset each color temperature to the default Rgain value (e.g., 1024)
            defaultRgain = 1024
            for colorTemperature in colorTemperatureValues:
                self.testtvSettings.setRgainValue("TV_OFFSET", colorTemperature, defaultRgain, 1)
                self.log.info(f'Reset Color Temperature {colorTemperature} to default Rgain value: {defaultRgain}')


    def testFunction(self):
        """Main function to run both Set and Save tests for ColorTempRgain."""

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
    test = tvSettings_test21_ColorTempRgain(summeryLog)
    test.run(False)