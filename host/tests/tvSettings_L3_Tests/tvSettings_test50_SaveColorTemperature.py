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
from raft.framework.core.logModule import logModule

class tvSettings_test50_SaveColorTemperature(tvSettingsHelperClass):

    def __init__(self, log:logModule=None):
        """
        Initializes the SaveColorTemperature test.

        Args:
            None.
        """
        self.testName = "test50_SaveColorTemperature"
        self.qcID = '50'
        super().__init__(self.testName, self.qcID, log)
        self.color_temperature_indices = []

    def testVerifyColorTemperature(self, pictureMode, videoFormat, colorTemperature, manual=False):
        """
        Verifies whether the Color Temperature value is set correctly.

        Args:
            pictureMode (str): Picture Mode.
            videoFormat (str): Video Format.
            colorTemperature (int): Color Temperature value.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to other verification methods.

        Returns:
            bool: Returns the status of the color temperature value.
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Is color temperature {colorTemperature} applied for Picture Mode: {pictureMode} and Video Format: {videoFormat}? (Y/N):"
            )
        else:
            # TODO: Add automation verification methods
            return False

    def saveColorTemperatureForAllFormats(self):
        """
        Saves color temperature values for all combinations of picture mode index and video format.

        Returns:
            None.
        """
        pictureModeIndices = self.testtvSettings.getPictureModeIndex()
        videoFormatInfo = self.testtvSettings.getVideoFormatInfo()
        colorTemperatures = self.testtvSettings.getColorTemperatureInfo()

        # Prepare the list of color temperature assignments based on video formats
        for videoFormatIndex in range(len(videoFormatInfo)):
            # 0 or 1 based on index
            self.color_temperature_indices.append(videoFormatIndex % len(colorTemperatures))

        # Save the appropriate color temperature values based on the video format
        for pictureModeIndex in pictureModeIndices:
            for videoFormatIndex, videoFormat in enumerate(videoFormatInfo):
                colorTemperature = colorTemperatures[self.color_temperature_indices[videoFormatIndex]]

                # Log and save the color temperature values
                self.testtvSettings.saveColorTemperatureValues("VIDEO_SOURCE_IP", pictureModeIndex, videoFormat, colorTemperature)
                time.sleep(1)


    def setAllColorTemperatureToDefault(self, defaultValue='tvColorTemp_STANDARD'):
        """
        Sets the color temperature to a default value for all combinations of picture modes and video formats.

        Args:
            defaultValue (str, optional): The default color temperature value to set. Defaults to 'tvColorTemp_STANDARD'.

        Returns:
            None.
        """
        pictureModeIndices = self.testtvSettings.getPictureModeIndex()
        videoFormatInfo = self.testtvSettings.getVideoFormatInfo()

        for pictureModeIndex in pictureModeIndices:
            for videoFormat in videoFormatInfo:
                # Log and save the default color temperature value
                self.testtvSettings.saveColorTemperatureValues("VIDEO_SOURCE_IP", pictureModeIndex, videoFormat, defaultValue)
                time.sleep(1)


    def testFunction(self):
        """This function tests saving Color Temperature values with all combinations of picture mode and video format.

        Returns:
            bool: Status of the color temperature save operations.
        """
        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Save color temperature values for all formats
        self.saveColorTemperatureForAllFormats()

        # Get the list of streams from the test setup
        streams = self.testSetup.get("assets").get("device").get(self.testName).get("streams")

        # Loop through video formats and corresponding stream URLs
        for videoFormatIndex, (videoFormat,streamUrl) in enumerate(zip(self.testtvSettings.getVideoFormatInfo(),streams)):

            # Download the individual stream
            self.testDownloadAssetsByUrl(streamUrl)

            streamFullPath = os.path.join(self.targetWorkspace, os.path.basename(streamUrl))

            # Play the stream
            self.testPlayer.play(streamFullPath)

            # Allow some time for the stream to start
            time.sleep(3)

            # Loop through available picture modes
            for pictureMode in self.testtvSettings.getPictureModeInfo():

                # Determine the color temperature based on the saved indices
                colorTemperature = self.testtvSettings.getColorTemperatureInfo()[self.color_temperature_indices[videoFormatIndex]]

                self.testtvSettings.setPictureMode(pictureMode)

                self.log.stepStart(f'Setting Color Temperature: {colorTemperature}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

                # Call the verification function (manual=True allows for manual verification)
                result = self.testVerifyColorTemperature(pictureMode, videoFormat, colorTemperature, manual=True)

                # Log the result for each step
                self.log.stepResult(result, f'Verification for Color Temperature: {colorTemperature}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

            # Stop the stream playback
            self.testPlayer.stop()

            # Clean the assets downloaded to the device
            self.testCleanAssetsByUrl(streamFullPath)

        # Set all color temperature values to the default value of 'tvColorTemp_STANDARD'
        self.setAllColorTemperatureToDefault()

        # Terminate the tvSettings Module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test50_SaveColorTemperature(summeryLog)
    test.run(False)
