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
import time

# Set the directory path
dir_path = os.path.dirname(os.path.realpath(__file__))
sys.path.append(os.path.join(dir_path, "../"))

# Import necessary modules from custom and external libraries
from tvSettings_L3_Tests.tvSettingsHelperClass import tvSettingsHelperClass

class tvSettings_test55_SaveGammaTable(tvSettingsHelperClass):
    """
    A class that implements test 55 for saving gamma table settings and performing stream playback.

    Attributes:
        testName (str): The name of the test case.
        testSetupPath (str): The path to the test setup configuration file.
        moduleName (str): The module name being tested.
    """

    def __init__(self):
        """
        Initializes the test55_SaveGammaTable class.
        Opens the necessary sessions and reads the configuration file.
        """
        self.testName = "test55_SaveGammaTable"
        super().__init__(self.testName, '55')

    def testVerifyGammaTable(self, size, red, green, blue, color_temp, manual=False):
        """
        Verifies if the gamma table is applied with the expected values.

        Args:
            size (int): Gamma table size.
            red (list): List of Red values.
            green (list): List of Green values.
            blue (list): List of Blue values.
            color_temp (str): Color temperature.
            manual (bool): Manual verification flag (True for manual verification).

        Returns:
            bool: Status of gamma table verification.
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Is Gamma Table set with Size:{size}, R:{red}, G:{green}, B:{blue} for Color Temp: {color_temp}? (Y/N):"
            )
        else:
            # TODO: Add automated verification methods
            return False

    def setGammaValues(self, colorTemperatures):
        """
        Generates and applies gamma values based on the provided color temperatures.

        Args:
            colorTemperatures (list): List of color temperatures.

        Returns:
            list: List of tuples containing (color_temp, red, green, blue).
        """
        gamma_values = []  # List to store gamma values

        for index, colortemp in enumerate(colorTemperatures):
            # Set gamma table with size 1
            size = 1

            # Generate RGB values in a wider range
            red = [int((index * 255) % 1024)]   # Scale index to fit range 0-1023
            green = [int(((index + 1) * 255) % 1024)]  # Unique green value
            blue = [int(((index + 2) * 255) % 1024)]   # Unique blue value

            # Call saveGammaTable with appropriate parameters
            self.testtvSettings.saveGammaTable(size, red, green, blue, colortemp)

            # Store the values for logging
            gamma_values.append((colortemp, red[0], green[0], blue[0]))

        return gamma_values

    def setGammaValuesToDefault(self, defaultRed=0, defaultGreen=0, defaultBlue=0):
        """
        Sets gamma values to default for all color temperatures.

        Args:
            defaultRed (int, optional): Default value for Red. Defaults to 512.
            defaultGreen (int, optional): Default value for Green. Defaults to 512.
            defaultBlue (int, optional): Default value for Blue. Defaults to 512.

        Returns:
            None.
        """
        colorTemperatures = self.testtvSettings.getColorTemperatureInfo()

        for colorTemp in colorTemperatures:
            size = 1  # Fixed size
            red = [defaultRed]
            green = [defaultGreen]
            blue = [defaultBlue]

            # Log and apply default gamma values
            self.log.stepStart(f'Setting default gamma values: R: {red}, G: {green}, B: {blue} for Color Temp: {colorTemp}')
            self.testtvSettings.saveGammaTable(size, red, green, blue, colorTemp)
            self.log.stepResult(True, f'Default Gamma values applied for Color Temp: {colorTemp}')

    def testFunction(self):
        """
        Main function that tests saving GammaTable values with all combinations of color temperatures.

        Returns:
            bool: Final result of the test.
        """

        # Start the test log
        self.log.testStart(self.testName, '55')

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Get the list of streams from the test setup
        streams = self.testSetup.get("assets").get("device").get(self.testName).get("streams")

        # Get the list of color temperatures
        colorTemperatures = self.testtvSettings.getColorTemperatureInfo()

        # Set gamma values for the color temperatures once, outside the stream loop
        gamma_values = self.setGammaValues(colorTemperatures)

        for stream in streams:
            # Play the stream
            self.testPlayer.play(stream)
            time.sleep(3)  # Allow the stream to start

            # Set color temperature level for each stream
            for index, colortemp in enumerate(colorTemperatures):
                self.log.stepStart(f'Setting Color Temp Level: {colortemp}')
                self.testtvSettings.setColorTempLevel(colortemp)  # Set the color temperature level
                self.log.stepResult(True, f'Color Temp Level set to {colortemp}')

                # Use pre-computed gamma values from gamma_values
                size = 1  # Size is always 1
                red, green, blue = gamma_values[index][1:4]  # Accessing RGB values
                result = self.testVerifyGammaTable(size, [red], [green], [blue], colortemp, manual=True)
                self.log.stepResult(result, f'Gamma values for Color Temp: {colortemp}, R: {red}, G: {green}, B: {blue}')

            # Stop the stream playback and clean assets
            self.testPlayer.stop()

        # Set default gamma values before applying custom values
        self.setGammaValuesToDefault()

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        return True

if __name__ == '__main__':
    test = tvSettings_test55_SaveGammaTable()
    test.run(False)
