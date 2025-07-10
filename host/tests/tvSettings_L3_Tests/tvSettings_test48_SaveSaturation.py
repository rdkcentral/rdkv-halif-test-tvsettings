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

class tvSettings_test48_SaveSaturation(tvSettingsHelperClass):

    def __init__(self, log:logModule=None):
        """
        Initializes the SaveSaturation test.

        Args:
            None.
        """
        self.testName = "test48_SaveSaturation"
        self.qcID = '48'
        super().__init__(self.testName, self.qcID, log)
        self.saturation_values = []

    def testVerifySaturationValue(self, pictureMode, videoFormat, saturation, manual=False):
        """
        Verifies whether the Saturation value is set correctly.

        Args:
            pictureMode (str): Picture Mode.
            videoFormat (str): Video Format.
            saturation (int): Saturation value.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to other verification methods.

        Returns:
            bool: Returns the status of saturation value.
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Is saturation value {saturation} applied for Picture Mode: {pictureMode} and Video Format: {videoFormat}? (Y/N):"
            )
        else:
            # TODO: Add automation verification methods
            return False

    def saveSaturationValuesForAllFormats(self):
        """
        Saves saturation values for all combinations of picture mode index and video format.

        Returns:
            None.
        """
        pictureModeIndices = self.testtvSettings.getSaturationPictureModeIndex()
        videoFormatInfo = self.testtvSettings.getSaturationVideoFormatInfo()

        # Split the saturation values based on the number of video formats
        num_video_formats = len(videoFormatInfo)
        self.saturation_values = [int(i * (100 / (num_video_formats - 1))) for i in range(num_video_formats)]

        # Save the appropriate saturation values based on the video format
        for pictureModeIndex in pictureModeIndices:
            for videoFormatIndex, videoFormat in enumerate(videoFormatInfo):
                saturationValue = self.saturation_values[videoFormatIndex]

                # Log and save the saturation values
                self.testtvSettings.saveSaturationValues("VIDEO_SOURCE_IP", pictureModeIndex, videoFormat, saturationValue)
                time.sleep(1)


    def setAllSaturationToDefault(self, defaultValue=50):
        """
        Sets the saturation value to a default value for all combinations of picture modes and video formats.

        Args:
            defaultValue (int, optional): The default saturation value to set. Defaults to 50.

        Returns:
            None.
        """
        pictureModeIndices = self.testtvSettings.getSaturationPictureModeIndex()
        videoFormatInfo = self.testtvSettings.getSaturationVideoFormatInfo()

        for pictureModeIndex in pictureModeIndices:
            for videoFormat in videoFormatInfo:
                # Log and save the default saturation value
                self.testtvSettings.saveSaturationValues("VIDEO_SOURCE_IP", pictureModeIndex, videoFormat, defaultValue)
                time.sleep(1)


    def testFunction(self):
        """This function tests saving saturation values with all combinations of picture mode and video format.

        It also adds the option to restart the device to verify changes.

        Returns:
            bool: Status of the saturation save operations.
        """
        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Save saturation values for all formats
        self.saveSaturationValuesForAllFormats()

        # Get the list of streams from the test setup
        streams = self.testSetup.get("assets").get("device").get(self.testName).get("streams")

        # Loop through video formats and corresponding stream URLs
        for videoFormatIndex, (videoFormat,streamUrl) in enumerate(zip(self.testtvSettings.getVideoFormatInfo(),streams)):

            # Download the individual stream
            self.testDownloadAssetsByUrl(streamUrl)

            streamFullPath = os.path.join(self.targetWorkspace, os.path.basename(streamUrl))

            # Play the stream
            self.testPlayer.play(streamFullPath)
            time.sleep(3)  # Allow some time for the stream to start

            # Loop through available picture modes
            for pictureMode in self.testtvSettings.getPictureModeInfo():
                # Get the saturation value based on the saved indices
                saturationValue = self.saturation_values[videoFormatIndex]

                self.testtvSettings.setPictureMode(pictureMode)

                self.log.stepStart(f'Setting Saturation: {saturationValue}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

                # Call the verification function (manual=True allows for manual verification)
                result = self.testVerifySaturationValue(pictureMode, videoFormat, saturationValue, manual=True)

                # Log the result for each step
                self.log.stepResult(result, f'Verification for Saturation: {saturationValue}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

            # Stop the stream playback
            self.testPlayer.stop()

            # Clean the assets downloaded to the device
            self.testCleanAssetsByUrl(streamFullPath)

        # Set all saturation values to the default value of 50
        self.setAllSaturationToDefault()

        # Terminate the tvSettings Module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test48_SaveSaturation(summeryLog)
    test.run(False)
