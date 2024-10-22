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

dir_path = os.path.dirname(os.path.realpath(__file__))
sys.path.append(os.path.join(dir_path, "../"))

from tvSettings_L3_Tests.tvSettingsHelperClass import tvSettingsHelperClass

class tvSettings_test54_SaveCMS(tvSettingsHelperClass):
    """
    Test class for saving CMS values for different picture modes and video formats.

    Attributes:
        testName (str): Name of the test.
        cms_values (list): List to store calculated CMS values.
        validHueSaturationValues (list): Hue/Saturation values from 0 to 100.
        validLumaValues (list): Luma values from 0 to 30.
    """

    def __init__(self):
        """Initializes the SaveCMS test with required parameters."""
        self.testName = "test54_SaveCMS"
        super().__init__(self.testName, '54')
        self.cms_values = []  # Initialize list to capture CMS values
        self.validHueSaturationValues = list(range(101))  # Valid Hue/Saturation values (0-100)
        self.validLumaValues = list(range(31))  # Valid Luma values (0-30)

    def saveCMSValuesForAllFormats(self):
        """
        Saves CMS values for all combinations of picture modes and video formats.
        Iterates through video formats to calculate and save CMS values accordingly.
        """
        pictureModeIndices = self.testtvSettings.getPictureModeIndex()
        videoFormatInfo = self.testtvSettings.getVideoFormatInfo()

        componentTypes = self.testtvSettings.getComponentTypeInfo()
        componentColors = self.testtvSettings.getTVDataColor()

        # Loop through video formats to calculate CMS values
        for videoFormatIndex in range(len(videoFormatInfo)):
            for componentType in componentTypes:
                for componentColor in componentColors:
                    # Default CMS value to 0 or 1
                    cms_value = videoFormatIndex % 2

                    # Calculate CMS value based on component type
                    if componentType in ['COMP_HUE', 'COMP_SATURATION']:
                        cms_value = self.validHueSaturationValues[videoFormatIndex % len(self.validHueSaturationValues)]
                    elif componentType == 'COMP_LUMA':
                        cms_value = self.validLumaValues[videoFormatIndex % len(self.validLumaValues)]

                    self.cms_values.append(cms_value)  # Store calculated CMS value

                    # Save the CMS value for each picture mode
                    for pictureMode in pictureModeIndices:
                        self.testtvSettings.saveCMS(pictureMode, videoFormatInfo[videoFormatIndex], componentType, componentColor, cms_value)

    def testFunction(self):
        """
        Executes the test for saving CMS values across all formats and verifies the values.

        Returns:
            bool: Overall status of the CMS save operations.
        """
        self.log.testStart(self.testName, '54')  # Start logging for the test

        self.testtvSettings.initialise()  # Initialize the tvSettings module

        self.saveCMSValuesForAllFormats()  # Save CMS values for all formats

        # Get the list of streams from the test setup
        streams = self.testSetup.get("assets").get("device").get(self.testName).get("streams")

        result = True  # Initialize result as True
        for videoFormatIndex, videoFormat in enumerate(self.testtvSettings.getVideoFormatInfo()):
            streamUrl = streams[videoFormatIndex]

            self.testDownloadAssetsByUrl(streamUrl)  # Download the individual stream

            streamFullPath = os.path.join(self.deviceDownloadPath, os.path.basename(streamUrl))

            self.testPlayer.play(streamFullPath)  # Play the stream

            time.sleep(3)  # Allow some time for the stream to start

            # Loop through available picture modes
            for pictureMode in self.testtvSettings.getPictureModeIndex():
                cms_value = self.cms_values[videoFormatIndex]  # Get the CMS value based on index

                self.log.stepStart(f'Setting CMS: {cms_value}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

                result &= self.testVerifyCMSValue(pictureMode, videoFormat, '', '', cms_value, manual=True)  # Verify CMS value

                # Log the result for each step
                self.log.stepResult(result, f'Verification for CMS: {cms_value}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

            self.testPlayer.stop()  # Stop the stream playback

            self.testCleanAssetsByUrl(streamFullPath)  # Clean the downloaded assets

        self.log.info("Captured CMS values for video formats: " + ", ".join(map(str, self.cms_values)))  # Log captured CMS values

        self.testtvSettings.terminate()  # Terminate the tvSettings Module

        return result  # Return the overall result

if __name__ == '__main__':
    test = tvSettings_test54_SaveCMS()
    test.run(False)
