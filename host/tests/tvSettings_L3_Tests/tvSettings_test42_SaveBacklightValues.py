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
# * you may obtain a copy of the License at
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

class tvSettings_test42_SaveBacklightValues(tvSettingsHelperClass):

    def __init__(self, log:logModule=None):
        """
        Initializes the SaveBacklightValues test.

        Args:
            None.
        """
        self.testName = "test42_SaveBacklightValues"
        self.qcID = '42'
        super().__init__(self.testName, self.qcID, log)
        self.backlight_values = []

    def testVerifyBacklightValue(self, pictureMode, videoFormat, backlight, manual=False):
        """
        Verifies whether the Backlight value is set correctly.

        Args:
            pictureMode (str): Picture Mode.
            videoFormat (str): Video Format.
            backlight (int): Backlight value.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Returns the status of backlight value.
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Is backlight value {backlight} applied for Picture Mode: {pictureMode} and Video Format: {videoFormat}? (Y/N):"
            )
        else:
            # TODO: Add automation verification methods
            return False

    def saveBacklightValuesForAllFormats(self):
        """
        Saves backlight values for all combinations of picture mode index and video format.

        Returns:
            None.
        """
        pictureModeIndices = self.testtvSettings.getPictureModeIndex()
        videoFormatInfo = self.testtvSettings.getVideoFormatInfo()

        # Split the brightness values based on the number of video formats
        num_video_formats = len(videoFormatInfo)
        self.backlight_values = [int(i * (100 / (num_video_formats - 1))) for i in range(num_video_formats)]

        # Save the appropriate backlight values based on the video format
        for videoFormatIndex, videoFormat in enumerate(videoFormatInfo):
            for pictureModeIndex in pictureModeIndices:
                backlightValue = self.backlight_values[videoFormatIndex]

                # Log and save the backlight values
                self.testtvSettings.saveBacklightValues("VIDEO_SOURCE_IP", pictureModeIndex, videoFormat, backlightValue)

    def setAllBacklightValuesToDefault(self, defaultValue=50):
        """
        Sets the backlight value to a default value for all combinations of picture modes and video formats.

        Args:
            defaultValue (int, optional): The default backlight value to set. Defaults to 50.

        Returns:
            None.
        """
        pictureModeIndices = self.testtvSettings.getPictureModeIndex()
        videoFormatInfo = self.testtvSettings.getVideoFormatInfo()

        for videoFormat in videoFormatInfo:
            for pictureModeIndex in pictureModeIndices:
                # Log and save the default backlight value
                self.testtvSettings.saveBacklightValues("VIDEO_SOURCE_IP", pictureModeIndex, videoFormat, defaultValue)

    def testFunction(self):
        """
        Tests saving Backlight values with all combinations of picture mode and video format.

        Returns:
            bool: Status of the backlight value save operations.
        """

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Save backlight values for all formats
        self.saveBacklightValuesForAllFormats()

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
                # Get the backlight value based on the saved indices
                backlightValue = self.backlight_values[videoFormatIndex]

                self.testtvSettings.setPictureMode(pictureMode)

                self.log.stepStart(f'Setting Backlight Value: {backlightValue}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

                # Call the verification function (manual=True allows for manual verification)
                result = self.testVerifyBacklightValue(pictureMode, videoFormat, backlightValue, manual=True)

                # Log the result for each step
                self.log.stepResult(result, f'Verification for Backlight Value: {backlightValue}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

            # Stop the stream playback
            self.testPlayer.stop()

            # Clean the assets downloaded to the device
            self.testCleanAssetsByUrl(streamFullPath)

        # Set all backlight values to the default value of 50
        self.setAllBacklightValuesToDefault()

        # Terminate the tvSettings Module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test42_SaveBacklightValues(summeryLog)
    test.run(False)
