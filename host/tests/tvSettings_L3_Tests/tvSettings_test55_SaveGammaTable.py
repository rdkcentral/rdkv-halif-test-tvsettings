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
    A class that implements test 57 for saving gamma table settings and performing stream playback.

    Attributes:
        testName (str): The name of the test case.
        testSetupPath (str): The path to the test setup configuration file.
        moduleName (str): The module name being tested.
        rackDevice (str): The name of the device under test (DUT).
        gammaCombinations (list): A list of dictionaries defining different gamma table combinations for testing.
    """

    # Predefined Gamma table RGB values for testing various configurations
    gammaCombinations = [
        {
            "size": 10,
            "red": [1023, 900, 800, 700, 600, 500, 400, 300, 200, 100],
            "green": [800, 750, 700, 650, 600, 500, 400, 300, 200, 100],
            "blue": [600, 500, 400, 300, 200, 100, 50, 30, 20, 10]
        },
        {
            "size": 5,
            "red": [300, 200, 100, 50, 0],
            "green": [600, 500, 400, 300, 200],
            "blue": [1023, 900, 800, 700, 600]
        },
        {
            "size": 10,
            "red": [600] * 10,
            "green": [600] * 10,
            "blue": [600] * 10
        },
        {
            "size": 5,
            "red": [1023, 1000, 900, 800, 700],
            "green": [500, 400, 300, 200, 100],
            "blue": [1023, 1000, 900, 800, 700]
        },
        {
            "size": 10,
            "red": [300] * 10,
            "green": [300] * 10,
            "blue": [300] * 10
        },
        {
            "size": 10,  # Reset Gamma Table
            "red": [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],  # Default values for Red
            "green": [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],  # Default values for Green
            "blue": [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]  # Default values for Blue
        }
    ]

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

    def testFunction(self):
        """
        Main function that tests saving GammaTable values with all combinations of picture mode and video format.

        Returns:
            bool: Final result of the test.
        """

        # Start the test log
        self.log.testStart(self.testName, '55')

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Get the list of streams from the test setup
        streams = self.testSetup.get("assets").get("device").get(self.testName).get("streams")

        # Loop through each video format and stream
        for videoFormat, streamUrl in zip(self.testtvSettings.getVideoFormatInfo(), streams):
            # Download stream assets
            self.testDownloadAssetsByUrl(streamUrl)
            streamFullPath = os.path.join(self.deviceDownloadPath, os.path.basename(streamUrl))

            # Play the stream
            self.testPlayer.play(streamFullPath)
            time.sleep(3)  # Allow the stream to start

            # Loop through picture modes and gamma combinations
            for pictureMode in self.testtvSettings.getPictureModeIndex():
                for gamma_value in self.gammaCombinations:
                    self.log.stepStart(f'Setting GammaValue: {gamma_value}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

                    # Set gamma table and query the save status
                    self.testtvSettings.saveGammaTable(pictureMode, videoFormat, gamma_value)

                    self.log.info("Restarting the Stream...")
                    self.testPlayer.stop()
                    self.testPlayer.play(streamFullPath)

                    # Manually verify gamma table settings
                    result = self.testVerifyGammaTable(pictureMode, videoFormat, gamma_value, manual=True)
                    self.log.stepResult(result, f'GammaValue: {gamma_value}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

            # Stop the stream playback and clean assets
            self.testPlayer.stop()

            self.testCleanAssetsByUrl(streamFullPath)

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    test = tvSettings_test55_SaveGammaTable()
    test.run(False)
