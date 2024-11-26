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

class tvSettings_test22_ColorTempGgain(tvSettingsHelperClass):

    ggainValues = [0, 512, 1024, 1536, 2047, 1024]  # Ggain values to test

    def __init__(self, log:logModule=None):
        """
        Initializes the test22 ColorTempGgain test.

        Args:
            None.
        """
        self.testName = "test22_ColorTempGgain"
        self.qcID = '22'
        super().__init__(self.testName, self.qcID, log)

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

        # Get the Color Temperature values
        colorTemperatureValues = self.testtvSettings.getColorTemperatureInfo()

        # Loop through each color temperature and Ggain value to set them
        for colorTemperature, ggain in zip(colorTemperatureValues, self.ggainValues):
            # Set the Color Temperature and Ggain (Save flag = 1 means Save operation)
            self.testtvSettings.setGgainValue("TV_OFFSET", colorTemperature, ggain, 1)

        # After setting all values, loop through the streams to play them
        for stream in self.testStreams:
            self.testPlayer.play(stream)

            # Re-pair values for each stream playback iteration
            for colorTemperature, ggain in zip(colorTemperatureValues, self.ggainValues):
                self.log.stepStart(f'Save Operation - Color Temperature: {colorTemperature} Ggain: {ggain} Stream: {stream}')

                # Set the Color Temperature to apply the saved Ggain value
                self.testtvSettings.setColorTempLevel(colorTemperature)

                # Now verify the Save operation manually after restart
                result = self.testVerifyColorTempGgain(colorTemperature, ggain, 1, True)
                self.log.stepResult(result, f'Save Operation - Color Temperature: {colorTemperature} Ggain: {ggain} Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

            # Reset each color temperature to the default Ggain value (e.g., 1024)
            defaultGgain = 1024
            for colorTemperature in colorTemperatureValues:
                self.testtvSettings.setGgainValue("TV_OFFSET", colorTemperature, defaultGgain, 1)
                self.log.info(f'Reset Color Temperature {colorTemperature} to default Ggain value: {defaultGgain}')


    def testFunction(self):
        """Main function to run both Set and Save tests for ColorTempGgain."""

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
    test = tvSettings_test22_ColorTempGgain(summeryLog)
    test.run(False)
