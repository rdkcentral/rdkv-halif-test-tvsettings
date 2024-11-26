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
import numpy as np

# Set the directory path
dir_path = os.path.dirname(os.path.realpath(__file__))
sys.path.append(os.path.join(dir_path, "../"))

# Import necessary modules from custom and external libraries
from tvSettings_L3_Tests.tvSettingsHelperClass import tvSettingsHelperClass
from raft.framework.core.logModule import logModule

class tvSettings_test55_SaveGammaTable(tvSettingsHelperClass):
    """
    A class that implements test 55 for saving gamma table settings and performing stream playback.
    """

    def __init__(self, log:logModule=None):
        """
        Initializes the test55_SaveGammaTable class.
        Opens the necessary sessions and reads the configuration file.
        """
        self.testName = "test55_SaveGammaTable"
        self.qcID = '55'
        super().__init__(self.testName, self.qcID, log)

    def testVerifyGammaTable(self, description, color_temp, manual=False):
        """
        Verifies if the gamma table is applied with the expected values.
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Is Gamma Table set {description} for Color Temp: {color_temp}? (Y/N):"
            )
        else:
            # TODO: Add automated verification methods
            return False


    def setGammaValues(self):
        """
        Generates and applies gamma values for specified combinations based on color temperature assignments.

        Returns:
            list: List of tuples containing (color_temp, red, green, blue).
        """
        gamma_values = []  # List to store gamma values

        # Define color temperatures (to be fetched dynamically if needed)
        colorTemperatures = self.testtvSettings.getColorTemperatureInfo()

        # Predefined RGB gamma curve values for testing
        combinations = [
            {
                # Curved gamma using x ^ (1/2)
                "description": "Curved gamma (x ^ 1/2)",
                "size": 255,
                "red": list((np.sqrt(np.linspace(0, 1, 255)) * 1023).astype(int)),
                "green": list((np.sqrt(np.linspace(0, 1, 255)) * 1023).astype(int)),
                "blue": list((np.sqrt(np.linspace(0, 1, 255)) * 1023).astype(int)),
            },
            {
                # Gamma using x ^ 2.2 for higher contrast
                "description": "Gamma (x ^ 2.2)",
                "size": 255,
                "red": list((np.power(np.linspace(0, 1, 255), 2.2) * 1023).astype(int)),
                "green": list((np.power(np.linspace(0, 1, 255), 2.2) * 1023).astype(int)),
                "blue": list((np.power(np.linspace(0, 1, 255), 2.2) * 1023).astype(int)),
            },
            {
                # Linear gamma using x ^ 1
                "description": "Linear gamma (x ^ 1)",
                "size": 255,
                "red": list(np.linspace(0, 1023, 255).astype(int)),
                "green": list(np.linspace(0, 1023, 255).astype(int)),
                "blue": list(np.linspace(0, 1023, 255).astype(int)),
            }
        ]

        num_combinations = len(combinations)
        num_color_temperatures = len(colorTemperatures)

        # Loop through combinations and assign color temperatures accordingly
        for i, combo in enumerate(combinations):
            size = combo["size"]
            red = combo["red"]
            green = combo["green"]
            blue = combo["blue"]
            description = combo["description"]

            # Determine the appropriate color temperature
            if i < num_color_temperatures:
                colortemp = colorTemperatures[i]  # Assign color temperature in order
            else:
                colortemp = colorTemperatures[i % num_color_temperatures]  # Round-robin assignment

            # Save the gamma table with the generated values
            self.testtvSettings.saveGammaTable(size, red, green, blue, colortemp)

            # Store the color temp and all RGB values for logging
            gamma_values.append((colortemp, red, green, blue, description))

        return gamma_values


    def testFunction(self):
        """
        Main function that tests saving GammaTable values with all combinations of color temperatures.
        """

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Get the list of streams from the test setup
        streams = self.testSetup.get("assets").get("device").get(self.testName).get("streams")

        # Set gamma values for the color temperatures
        gamma_values = self.setGammaValues()  # This should return a list of (color_temp, red, green, blue) tuples
        colorTemperatures = self.testtvSettings.getColorTemperatureInfo()  # Get the available color temperatures

        # Loop through streams
        for stream in streams:

            streamPath =  os.path.join(self.targetWorkspace, os.path.basename(stream))

            # Play the stream
            self.testPlayer.play(streamPath)
            time.sleep(3)  # Allow the stream to start

            # Log details for the current stream
            self.log.stepStart(f'Stream: {streamPath}')

            # Loop through the combinations and assign color temperatures
            for index, (color_temp, red, green, blue, description) in enumerate(gamma_values):
                if index < len(colorTemperatures):  # Ensure we don't exceed available color temperatures
                    color_temp = colorTemperatures[index]  # Assign the color temperature based on the index

                    self.testtvSettings.setColorTempLevel(color_temp)  # Set the color temperature level

                    # Log the applied gamma values for this combination
                    self.log.stepStart(f'Applying Gamma values: description: {description}')
                    size = 255  # Size is fixed as per combinations

                    # Verify gamma table with the gamma values applied
                    result = self.testVerifyGammaTable([description], color_temp, manual=True)

                    # Log the result of the verification
                    self.log.stepResult(result, f'Gamma values verified for description: {description}')

            # Stop the stream playback and clean assets
            self.testPlayer.stop()

        # Terminate tvSettings Module
        self.testtvSettings.terminate()


        return True

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test55_SaveGammaTable(summeryLog)
    test.run(False)
