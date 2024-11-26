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

class tvSettings_test52_SaveDolbyVision(tvSettingsHelperClass):

    def __init__(self, log:logModule=None):
        """
        Initializes the SaveDolbyVision test.

        Args:
            None.
        """
        self.testName = "test52_SaveDolbyVision"
        self.qcID = '52'
        super().__init__(self.testName, self.qcID, log)
        self.dolby_vision_indices = []

    def testVerifyDolbyVision(self, pictureMode, videoFormat, dolbyVision, manual=False):
        """
        Verifies whether the Dolby Vision value is set correctly.

        Args:
            pictureMode (str): Picture Mode.
            videoFormat (str): Video Format.
            dolbyVision (str): Dolby Vision value.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to other verification methods.

        Returns:
            bool: Returns the status of the Dolby Vision value.
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Is Dolby Vision '{dolbyVision}' applied for Picture Mode: {pictureMode} and Video Format: {videoFormat} as expected? (Y/N):"
            )
        else:
            # TODO: Add automation verification methods
            return False

    def saveDolbyVisionForAllFormats(self):
        """
        Saves Dolby Vision values for all combinations of picture mode index and video format.

        Returns:
            None.
        """
        pictureModeIndices = self.testtvSettings.getPictureModeIndex()
        videoFormatInfo = self.testtvSettings.getVideoFormatInfo()
        dolbyVisionValues = self.testtvSettings.getDolbyVisionInfo()

        # Prepare the list of Dolby Vision assignments based on video formats
        for videoFormatIndex in range(len(videoFormatInfo)):
            # Assign Dolby Vision indices (0 or 1 based on index)
            self.dolby_vision_indices.append(videoFormatIndex % len(dolbyVisionValues))

        # Save the appropriate Dolby Vision values based on the video format
        for pictureModeIndex in pictureModeIndices:
            for videoFormatIndex, videoFormat in enumerate(videoFormatInfo):
                dolbyVision = dolbyVisionValues[self.dolby_vision_indices[videoFormatIndex]]

                # Log and save the Dolby Vision values
                self.testtvSettings.saveDolbyVisionValues("VIDEO_SOURCE_IP", pictureModeIndex, videoFormat, dolbyVision)
                time.sleep(1)


    def setAllDolbyVisionToDefault(self, defaultValue='tvDolbyMode_Dark'):
        """
        Sets the Dolby Vision value to a default value for all combinations of picture modes and video formats.

        Args:
            defaultValue (str, optional): The default Dolby Vision value to set. Defaults to 'tvDolbyMode_Dark'.

        Returns:
            None.
        """
        pictureModeIndices = self.testtvSettings.getPictureModeIndex()
        videoFormatInfo = self.testtvSettings.getVideoFormatInfo()

        for pictureModeIndex in pictureModeIndices:
            for videoFormat in videoFormatInfo:
                # Log and save the default Dolby Vision value
                self.testtvSettings.saveDolbyVisionValues("VIDEO_SOURCE_IP", pictureModeIndex, videoFormat, defaultValue)
                time.sleep(1)


    def testFunction(self):
        """This function tests saving Dolby Vision values with all combinations of picture mode and video format.

        Returns:
            bool: Status of the Dolby Vision save operations.
        """
        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Save Dolby Vision values for all formats
        self.saveDolbyVisionForAllFormats()

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

                # Determine the Dolby Vision value based on the saved indices
                dolbyVision = self.testtvSettings.getDolbyVisionInfo()[self.dolby_vision_indices[videoFormatIndex]]

                self.testtvSettings.setPictureMode(pictureMode)

                self.log.stepStart(f'Setting Dolby Vision: {dolbyVision}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

                # Call the verification function (manual=True allows for manual verification)
                result = self.testVerifyDolbyVision(pictureMode, videoFormat, dolbyVision, manual=True)

                # Log the result for each step
                self.log.stepResult(result, f'Verification for Dolby Vision: {dolbyVision}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

            # Stop the stream playback
            self.testPlayer.stop()

            # Clean the assets downloaded to the device
            self.testCleanAssetsByUrl(streamFullPath)


        # Set all Dolby Vision values to the default value of 'tvDolbyMode_Dark'
        self.setAllDolbyVisionToDefault()

        # Terminate the tvSettings Module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test52_SaveDolbyVision(summeryLog)
    test.run(False)
