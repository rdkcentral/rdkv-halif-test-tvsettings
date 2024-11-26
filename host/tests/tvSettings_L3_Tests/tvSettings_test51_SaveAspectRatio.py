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

class tvSettings_test51_SaveAspectRatio(tvSettingsHelperClass):

    def __init__(self, log:logModule=None):
        """
        Initializes the SaveAspectRatio test.

        Args:
            None.
        """
        self.testName = "test51_SaveAspectRatio"
        self.qcID = '51'
        super().__init__(self.testName, self.qcID, log)
        self.aspect_ratio_indices = []  # List to store aspect ratio indices

    def testVerifyAspectRatio(self, pictureMode, videoFormat, aspectRatio, manual=False):
        """
        Verifies whether the Aspect Ratio value is set correctly.

        Args:
            pictureMode (str): Picture Mode.
            videoFormat (str): Video Format.
            aspectRatio (int): Aspect Ratio value.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to other verification methods.

        Returns:
            bool: Returns the status of the aspect ratio value.
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Is aspect ratio {aspectRatio} applied for Picture Mode: {pictureMode} and Video Format: {videoFormat}? (Y/N):"
            )
        else:
            # TODO: Add automation verification methods
            return False

    def saveAspectRatioForAllFormats(self):
        """
        Saves aspect ratio values for all combinations of picture mode index and video format.

        Returns:
            None.
        """
        pictureModeIndices = self.testtvSettings.getPictureModeIndex()
        videoFormatInfo = self.testtvSettings.getVideoFormatInfo()
        aspectRatios = self.testtvSettings.getAspectRatio()  # Assuming this returns a list of aspect ratios

        # Prepare the list of aspect ratio assignments based on video formats
        for videoFormatIndex in range(len(videoFormatInfo)):
            # 0 or 1 based on index
            self.aspect_ratio_indices.append(videoFormatIndex % len(aspectRatios))

        # Save the appropriate aspect ratio values based on the video format
        for pictureModeIndex in pictureModeIndices:
            for videoFormatIndex, videoFormat in enumerate(videoFormatInfo):
                aspectRatio = aspectRatios[self.aspect_ratio_indices[videoFormatIndex]]

                # Log and save the aspect ratio values
                self.testtvSettings.saveAspectRatioValues("VIDEO_SOURCE_IP", pictureModeIndex, videoFormat, aspectRatio)
                time.sleep(1)


    def setAllAspectRatioToDefault(self, defaultValue='tvDisplayMode_4x3'):
        """
        Sets the aspect ratio to a default value for all combinations of picture modes and video formats.

        Args:
            defaultValue (str, optional): The default aspect ratio value to set. Defaults to 'tvDisplayMode_4x3'.

        Returns:
            None.
        """
        pictureModeIndices = self.testtvSettings.getPictureModeIndex()
        videoFormatInfo = self.testtvSettings.getVideoFormatInfo()

        for pictureModeIndex in pictureModeIndices:
            for videoFormat in videoFormatInfo:
                # Log and save the default aspect ratio value
                self.testtvSettings.saveAspectRatioValues("VIDEO_SOURCE_IP", pictureModeIndex, videoFormat, defaultValue)
                time.sleep(1)


    def testFunction(self):
        """This function tests saving Aspect Ratio values with all combinations of picture mode and video format.

        Returns:
            bool: Status of the aspect ratio save operations.
        """
        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Set all aspect ratio values to the default value of 'tvDisplayMode_4x3'
        self.setAllAspectRatioToDefault()

        # Save aspect ratio values for all formats
        self.saveAspectRatioForAllFormats()

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

                # Determine the aspect ratio based on the saved indices
                aspectRatio = self.testtvSettings.getAspectRatio()[self.aspect_ratio_indices[videoFormatIndex]]

                self.testtvSettings.setPictureMode(pictureMode)

                self.log.stepStart(f'Setting Aspect Ratio: {aspectRatio}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

                # Call the verification function (manual=True allows for manual verification)
                result = self.testVerifyAspectRatio(pictureMode, videoFormat, aspectRatio, manual=True)

                # Log the result for each step
                self.log.stepResult(result, f'Verification for Aspect Ratio: {aspectRatio}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

            # Stop the stream playback
            self.testPlayer.stop()

            # Clean the assets downloaded to the device
            self.testCleanAssetsByUrl(streamFullPath)

        # Set all aspect ratio values to the default value of 'tvDisplayMode_4x3'
        self.setAllAspectRatioToDefault()

        # Terminate the tvSettings Module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test51_SaveAspectRatio(summeryLog)
    test.run(False)
