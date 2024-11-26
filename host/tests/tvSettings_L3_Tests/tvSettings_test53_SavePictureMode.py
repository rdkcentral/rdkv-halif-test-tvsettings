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

class tvSettings_test53_SavePictureMode(tvSettingsHelperClass):

    def __init__(self, log:logModule=None):
        """
        Initializes the SavePictureMode test.

        Args:
            None.
        """
        self.testName = "test53_SavePictureMode"
        self.qcID = '53'
        super().__init__(self.testName, self.qcID, log)
        self.picture_mode_indices = []

    def testVerifyPictureMode(self, pictureMode, videoFormat, manual=False):
        """
        Verifies whether the Picture Mode value is set correctly.

        Args:
            pictureMode (str): Picture Mode.
            videoFormat (str): Video Format.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to other verification methods.

        Returns:
            bool: Returns the status of the picture mode value.
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Is Picture Mode '{pictureMode}' applied for Video Format: {videoFormat}? (Y/N):"
            )
        else:
            # TODO: Add automation verification methods
            return False

    def savePictureModeForAllFormats(self):
        """
        Saves picture mode values for all combinations of picture mode index and video format.

        Returns:
            None.
        """
        pictureModeIndices = self.testtvSettings.getPictureModeIndex()
        videoFormatInfo = self.testtvSettings.getVideoFormatInfo()

        # Prepare the list of picture mode assignments based on video formats
        for videoFormatIndex in range(len(videoFormatInfo)):
            # 0 or 1 based on index
            self.picture_mode_indices.append(videoFormatIndex % len(pictureModeIndices))

        # Save the appropriate picture mode values based on the video format
        for videoFormatIndex, videoFormat in enumerate(videoFormatInfo):
            pictureMode = pictureModeIndices[self.picture_mode_indices[videoFormatIndex]]
            # Log and save the picture mode values
            self.testtvSettings.savePictureMode("VIDEO_SOURCE_IP", pictureMode, videoFormat)
            time.sleep(1)


    def setAllPictureModesToDefault(self, defaultValue='PQ_MODE_STANDARD'):
        """
        Sets the Picture Mode to a default value for all combinations of video formats.

        Args:
            defaultValue (str, optional): The default picture mode value to set. Defaults to 'PQ_MODE_STANDARD'.

        Returns:
            None.
        """
        videoFormatInfo = self.testtvSettings.getVideoFormatInfo()

        for videoFormat in videoFormatInfo:
            # Log and save the default Picture Mode value
            self.testtvSettings.savePictureMode("VIDEO_SOURCE_IP", defaultValue, videoFormat)
            time.sleep(1)

    def testFunction(self):
        """This function tests saving Picture Mode values with all combinations of video format.

        Returns:
            bool: Status of the picture mode save operations.
        """

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Set all Picture Modes to the default value of 'PQ_MODE_STANDARD'
        self.setAllPictureModesToDefault()

        # Save picture mode values for all formats
        self.savePictureModeForAllFormats()

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

            # Determine the Picture Mode based on the saved indices
            pictureMode = self.testtvSettings.getPictureModeIndex()[self.picture_mode_indices[videoFormatIndex]]

            self.log.stepStart(f'Setting Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

            # Call the verification function (manual=True allows for manual verification)
            result = self.testVerifyPictureMode(pictureMode, videoFormat, manual=True)

            # Log the result for each step
            self.log.stepResult(result, f'Verification for Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

            # Stop the stream playback
            self.testPlayer.stop()

            # Clean the assets downloaded to the device
            self.testCleanAssetsByUrl(streamFullPath)

        # Terminate the tvSettings Module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test53_SavePictureMode(summeryLog)
    test.run(False)
