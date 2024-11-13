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

class tvSettings_test23_ColorTempBgain(tvSettingsHelperClass):

    bgainValues = [0, 512, 1024, 1536, 2047, 1024]  # Bgain values to test

    def __init__(self, log:logModule=None):
        """
        Initializes the test23 ColorTempBgain test.

        Args:
            None.
        """
        self.testName = "test23_ColorTempBgain"
        self.qcID = '23'
        super().__init__(self.testName, self.qcID, log)

    def testVerifyColorTempBgain(self, colorTemperature, bgain, saveSetFlag, manual=False):
        """
        Verifies whether the Color Temperature and Bgain are set or not.

        Args:
            colorTemperature (int): Color Temperature value.
            bgain (int): Bgain value.
            saveSetFlag (int): Save/Set flag (0 or 1).
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Status of Color Temperature and Bgain application.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Has Color Temperature {colorTemperature} and Bgain {bgain} with flag {saveSetFlag} applied? (Y/N):")
        else:
            # TODO: Add automation verification methods
            return False

    def testSetOperation(self):
        """Tests the Set operation for ColorTempBgain."""

        # Start the stream playback
        for stream in self.testStreams:
            self.testPlayer.play(stream)

            # Get the Color Temperature values
            colorTemperatureValues = self.testtvSettings.getColorTemperatureInfo()

            for colorTemperature in colorTemperatureValues:
                for bgain in self.bgainValues:
                    self.log.stepStart(f'Set Operation - Color Temperature: {colorTemperature} Bgain: {bgain} Stream: {stream}')

                    # Set the Color Temperature and Bgain (Save flag = 0 means Set operation)
                    self.testtvSettings.setBgainValue("TV_OFFSET", colorTemperature, bgain, 0)

                    # Verify Set operation manually
                    result = self.testVerifyColorTempBgain(colorTemperature, bgain, 0, True)
                    self.log.stepResult(result, f'Set Operation - Color Temperature: {colorTemperature} Bgain: {bgain} Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

    def testSaveOperation(self):
        """Tests the Save operation for ColorTempBgain and restarts the stream to verify the changes."""

        # Get the Color Temperature values
        colorTemperatureValues = self.testtvSettings.getColorTemperatureInfo()

        # Loop through each color temperature and Bgain value to set them
        for colorTemperature, bgain in zip(colorTemperatureValues, self.bgainValues):
            # Set the Color Temperature and Bgain (Save flag = 1 means Save operation)
            self.testtvSettings.setBgainValue("TV_OFFSET", colorTemperature, bgain, 1)

        # After setting all values, loop through the streams to play them
        for stream in self.testStreams:
            self.testPlayer.play(stream)

            # Re-pair values for each stream playback iteration
            for colorTemperature, bgain in zip(colorTemperatureValues, self.bgainValues):
                self.log.stepStart(f'Save Operation - Color Temperature: {colorTemperature} Bgain: {bgain} Stream: {stream}')

                # Set the Color Temperature to apply the saved Bgain value
                self.testtvSettings.setColorTempLevel(colorTemperature)

                # Now verify the Save operation manually after restart
                result = self.testVerifyColorTempBgain(colorTemperature, bgain, 1, True)
                self.log.stepResult(result, f'Save Operation - Color Temperature: {colorTemperature} Bgain: {bgain} Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

            # Reset each color temperature to the default Bgain value (e.g., 1024)
            defaultBgain = 1024
            for colorTemperature in colorTemperatureValues:
                self.testtvSettings.setBgainValue("TV_OFFSET", colorTemperature, defaultBgain, 1)
                self.log.info(f'Reset Color Temperature {colorTemperature} to default Bgain value: {defaultBgain}')


    def testFunction(self):
        """Main function to run both Set and Save tests for ColorTempBgain."""

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
    test = tvSettings_test23_ColorTempBgain(summeryLog)
    test.run(False)
