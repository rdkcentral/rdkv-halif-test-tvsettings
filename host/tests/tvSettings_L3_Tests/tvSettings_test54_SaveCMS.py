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
    """

    def __init__(self):
        """
        Initializes the SaveCMS test with required parameters.
        """
        self.testName = "test54_SaveCMS"
        super().__init__(self.testName, '54')
        self.cms_values = []  # Initialize list to capture CMS values

    def testVerifyCMSValue(self, pictureMode, videoFormat, componentType, componentColor, cmsValue, manual=False):
        """
        Verifies whether the CMS value is set correctly for the specified picture mode, video format,
        component type, and component color.

        Args:
            pictureMode (str): Picture mode to verify.
            videoFormat (str): Video format for verification.
            componentType (str): Component type for verification (e.g., 'COMP_HUE', 'COMP_LUMA').
            componentColor (str): Component color for verification.
            cmsValue (int): CMS value expected for verification.
            manual (bool, optional): Manual verification (True: manual, False: automation). Defaults to False.

        Returns:
            bool: Returns True if the CMS settings are verified as correct; otherwise, False.
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Is CMS Value '{cmsValue}' applied for Picture Mode '{pictureMode}', "
                f"Video Format '{videoFormat}', Component Type '{componentType}', "
                f"and Component Color '{componentColor}'? (Y/N):"
            )
        else:
            # Automated verification logic to check if CMS settings match the expected values.
            currentCmsValue = self.testtvSettings.getCurrentCMSValue(pictureMode, videoFormat, componentType, componentColor)

            if currentCmsValue == cmsValue:
                self.log.info(f"Verification passed: CMS Value '{cmsValue}' is correctly applied for "
                            f"Picture Mode '{pictureMode}', Video Format '{videoFormat}', "
                            f"Component Type '{componentType}', and Component Color '{componentColor}'.")
                return True
            else:
                self.log.error(f"Verification failed: Expected CMS Value '{cmsValue}', but found '{currentCmsValue}' "
                            f"for Picture Mode '{pictureMode}', Video Format '{videoFormat}', "
                            f"Component Type '{componentType}', and Component Color '{componentColor}'.")
                return False


    def saveCMSValuesForSelectedFormats(self):
        """
        Saves CMS values for each available video format by cycling through component types and colors.
        """
        videoFormats = self.testtvSettings.getVideoFormatInfo()
        pictureModes = self.testtvSettings.getPictureModeIndex()
        componentTypes = self.testtvSettings.getComponentTypeInfo()
        componentColors = self.testtvSettings.getTVDataColor()

        # Iterate through each video format to assign component types and colors dynamically
        for videoFormatIndex, videoFormat in enumerate(videoFormats):
            # Cycle through component types and colors based on the videoFormat index
            componentType = componentTypes[videoFormatIndex % len(componentTypes)]
            componentColor = componentColors[videoFormatIndex % len(componentColors)]
            pictureMode = pictureModes[videoFormatIndex % len(pictureModes)]

            # Assign a CMS value based on the component type
            if componentType == 'COMP_HUE' or componentType == 'COMP_SATURATION':
                numSaturationValues = len(videoFormats)
                cms_value = [i * (100 // (numSaturationValues - 1)) for i in range(numSaturationValues)]
                cms_value = cms_value[videoFormatIndex]
            elif componentType == 'COMP_LUMA':
                numLumaValues = min(4, len(videoFormats))  # Ensure we don't exceed the range of 0-30
                cms_value = [i * (30 // (numLumaValues - 1)) for i in range(numLumaValues)]
                cms_value = cms_value[videoFormatIndex]
            else:
                cms_value = videoFormatIndex % 2  # Default CMS value for other types

            self.cms_values.append(cms_value)  # Track the cms_value used

            # Save the calculated CMS value for this specific format, component type, color, and picture mode
            self.testtvSettings.saveCMS("VIDEO_SOURCE_IP", pictureMode, videoFormat, componentType,  componentColor, cms_value )


    def testFunction(self):
        """
        Executes the test for saving CMS values across specified formats and verifies the values.

        Returns:
            bool: Overall status of the CMS save operations.
        """
        self.log.testStart(self.testName, '54')  # Start logging for the test

        self.testtvSettings.initialise()  # Initialize the tvSettings module

        self.saveCMSValuesForSelectedFormats()  # Save CMS values for selected formats

        # Get the list of streams from the test setup
        streams = self.testSetup.get("assets").get("device").get(self.testName).get("streams")

        result = True  # Initialize result as True

        videoFormats = self.testtvSettings.getVideoFormatInfo()
        pictureModes = self.testtvSettings.getPictureModeIndex()
        componentTypes = self.testtvSettings.getComponentTypeInfo()
        componentColors = self.testtvSettings.getTVDataColor()

        for videoFormatIndex, (videoFormat, streamUrl) in enumerate(zip(self.testtvSettings.getVideoFormatInfo(), streams)):

            # Dynamically assign the component type and color for verification based on the format index
            componentType = self.testtvSettings.getComponentTypeInfo()[videoFormatIndex % len(componentTypes)]
            componentColor = self.testtvSettings.getTVDataColor()[videoFormatIndex % len(componentColors)]
            pictureMode = self.testtvSettings.getPictureModeIndex()[videoFormatIndex % len(pictureModes)]
            cms_value = self.cms_values[videoFormatIndex]

            self.testDownloadAssetsByUrl(streamUrl)  # Download the individual stream

            streamFullPath = os.path.join(self.deviceDownloadPath, os.path.basename(streamUrl))

            self.testPlayer.play(streamFullPath)  # Play the stream
            time.sleep(3)  # Allow some time for the stream to start

            self.log.stepStart(f"Setting CMS: {cms_value}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}")

            result &= self.testVerifyCMSValue( pictureMode, videoFormat, componentType, componentColor, cms_value, manual=True )

            # Log the result for each step
            self.log.stepResult(result, f"Verification for CMS: {cms_value}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}")

            self.testPlayer.stop()  # Stop the stream playback

            self.testCleanAssetsByUrl(streamFullPath)  # Clean the downloaded assets

        self.log.info("Captured CMS values for video formats: " + ", ".join(map(str, self.cms_values)))  # Log captured CMS values

        self.testtvSettings.terminate()  # Terminate the tvSettings module

        return result  # Return the overall result

if __name__ == '__main__':
    test = tvSettings_test54_SaveCMS()
    test.run(False)
