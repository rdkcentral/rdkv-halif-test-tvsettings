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

class tvSettings_test47_SaveSharpness(tvSettingsHelperClass):

    def __init__(self, log:logModule=None):
        """
        Initializes the SaveSharpness test.

        Args:
            None.
        """
        self.testName = "test47_SaveSharpness"
        self.qcID = '47'
        super().__init__(self.testName, self.qcID, log)
        self.sharpness_values = []

    def testVerifySharpnessValue(self, pictureMode, videoFormat, sharpness, manual=False):
        """
        Verifies whether the Sharpness value is set correctly.

        Args:
            pictureMode (str): Picture Mode.
            videoFormat (str): Video Format.
            sharpness (int): Sharpness value.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to other verification methods.

        Returns:
            bool: Returns the status of sharpness value.
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Is sharpness value {sharpness} applied for Picture Mode: {pictureMode} and Video Format: {videoFormat}? (Y/N):"
            )
        else:
            # TODO: Add automation verification methods
            return False

    def saveSharpnessValuesForAllFormats(self):
        """
        Saves sharpness values for all combinations of picture mode index and video format.

        Returns:
            None.
        """
        pictureModeIndices = self.testtvSettings.getPictureModeIndex()
        videoFormatInfo = self.testtvSettings.getVideoFormatInfo()

        # Split the sharpness values based on the number of video formats
        num_video_formats = len(videoFormatInfo)
        self.sharpness_values = [int(i * (100 / (num_video_formats - 1))) for i in range(num_video_formats)]

        # Save the appropriate sharpness values based on the video format
        for pictureModeIndex in pictureModeIndices:
            for videoFormatIndex, videoFormat in enumerate(videoFormatInfo):
                sharpnessValue = self.sharpness_values[videoFormatIndex]

                # Log and save the sharpness values
                self.testtvSettings.saveSharpnessValues("VIDEO_SOURCE_IP", pictureModeIndex, videoFormat, sharpnessValue)
                time.sleep(1)


    def setAllSharpnessToDefault(self, defaultValue=50):
        """
        Sets the sharpness value to a default value for all combinations of picture modes and video formats.

        Args:
            defaultValue (int, optional): The default sharpness value to set. Defaults to 50.

        Returns:
            None.
        """
        pictureModeIndices = self.testtvSettings.getPictureModeIndex()
        videoFormatInfo = self.testtvSettings.getVideoFormatInfo()

        for pictureModeIndex in pictureModeIndices:
            for videoFormat in videoFormatInfo:
                # Log and save the default sharpness value
                self.testtvSettings.saveSharpnessValues("VIDEO_SOURCE_IP", pictureModeIndex, videoFormat, defaultValue)
                time.sleep(1)


    def testFunction(self):
        """This function tests saving sharpness values with all combinations of picture mode and video format.

        Returns:
            bool: Status of the sharpness save operations.
        """

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Save sharpness values for all formats
        self.saveSharpnessValuesForAllFormats()

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
                # Get the sharpness value based on the saved indices
                sharpnessValue = self.sharpness_values[videoFormatIndex]

                self.testtvSettings.setPictureMode(pictureMode)

                self.log.stepStart(f'Setting Sharpness: {sharpnessValue}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

                # Call the verification function (manual=True allows for manual verification)
                result = self.testVerifySharpnessValue(pictureMode, videoFormat, sharpnessValue, manual=True)

                # Log the result for each step
                self.log.stepResult(result, f'Verification for Sharpness: {sharpnessValue}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

            # Stop the stream playback
            self.testPlayer.stop()

            # Clean the assets downloaded to the device
            self.testCleanAssetsByUrl(streamFullPath)

        # Set all sharpness values to the default value of 50
        self.setAllSharpnessToDefault()

        # Terminate the tvSettings Module
        self.testtvSettings.terminate()

        return result  # Return the last result of the verification

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test47_SaveSharpness(summeryLog)
    test.run(False)
