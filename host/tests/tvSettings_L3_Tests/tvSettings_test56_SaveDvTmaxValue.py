#!/usr/bin/env python3
# *****************************************************************************
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
# *****************************************************************************


import os
import sys
import time

# Assuming the helper classes and modules are imported, similar to the ones used in the original test
dir_path = os.path.dirname(os.path.realpath(__file__))
sys.path.append(os.path.join(dir_path, "../"))

from tvSettings_L3_Tests.tvSettingsHelperClass import tvSettingsHelperClass
from raft.framework.core.logModule import logModule


class tvSettings_test56_SaveDvTmaxValue(tvSettingsHelperClass):

    def __init__(self, log: logModule = None):
        """
        Initializes the SaveDvTmaxValue test.

        Args:
            log (logModule, optional): The log module for logging. Defaults to None.
        """
        self.testName = "test56_SaveDvTmaxValue"
        self.qcID = '56'
        super().__init__(self.testName, self.qcID, log)
        self.tmax_value = 0

    def testVerifyDvTmaxValue(self, pictureMode: str, videoFormat: str, tmaxValue: int, manual: bool = False) -> bool:
        """
        Verifies whether the Dolby Vision TMAX value is set correctly.

        Args:
            pictureMode (str): The picture mode.
            videoFormat (str): The video format.
            tmaxValue (int): The TMAX value to verify.
            manual (bool, optional): Whether to use manual verification. Defaults to False.

        Returns:
            bool: Returns the status of the TMAX value verification (True if successful, False otherwise).
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Is TMAX value {tmaxValue} applied for Picture Mode: {pictureMode} and Video Format: {videoFormat}? (Y/N):"
            )
        else:
            # TODO: Implement automation verification methods for TMAX value (e.g., querying TV settings)
            return False

    def saveDvTmaxValuesForAllFormats(self):
        """
        Saves Dolby Vision TMAX values for all combinations of picture mode and video format.

        Returns:
            None
        """
        pictureModeIndices = self.testtvSettings.getPictureModeIndex()
        videoFormatInfo = self.testtvSettings.getVideoFormatInfo()

        # Split the TMAX values based on the number of video formats
        num_video_formats = len(videoFormatInfo)
        self.dvTmax_values = [int(i * (10000 / (num_video_formats - 1))) for i in range(num_video_formats)]

        # Get the supported LDIM states from the system
        ldim_states = self.testtvSettings.getLocalDimmingMode()

        # Save the appropriate TMAX values based on the video format
        for videoFormatIndex, videoFormat in enumerate(videoFormatInfo):
            # Select the picture mode based on video format using modulus logic
            pictureModeIndex = videoFormatIndex % len(pictureModeIndices)

            # Get the corresponding TMAX value
            tmaxValue = self.dvTmax_values[videoFormatIndex]

            # Select the LDIM state using modulus logic from the retrieved list of states
            ldim_state = ldim_states[(pictureModeIndex * len(videoFormatInfo) + videoFormatIndex) % len(ldim_states)]

            # Save the TMAX value for the selected LDIM state
            self.testtvSettings.saveDvTmaxValue(ldim_state, tmaxValue)

            # Optional: Add a delay for stability
            time.sleep(1)

    def setAllDvTmaxToDefault(self, defaultValue: int = 5000):
        """
        Sets the TMAX value to a default value for all combinations of picture modes and video formats.

        Args:
            defaultValue (int, optional): The default TMAX value to set. Defaults to 5000.

        Returns:
            None.
        """
        pictureModeIndices = self.testtvSettings.getPictureModeIndex()
        videoFormatInfo = self.testtvSettings.getVideoFormatInfo()

        # Get the supported LDIM states from the system
        ldim_states = self.testtvSettings.getLocalDimmingMode()

        for videoFormatIndex, videoFormat in enumerate(videoFormatInfo):
            # Select the picture mode based on video format using modulus logic
            pictureModeIndex = videoFormatIndex % len(pictureModeIndices)

            # Select the LDIM state using modulus logic from the retrieved list of states
            ldim_state = ldim_states[(pictureModeIndex * len(videoFormatInfo) + videoFormatIndex) % len(ldim_states)]

            # Log and save the default TMAX value
            self.testtvSettings.saveDvTmaxValue(ldim_state, defaultValue)

            # Optional delay for stability
            time.sleep(1)


    def testFunction(self):
        """
        This function tests saving the Dolby Vision TMAX values with all combinations of picture mode and video format.

        Returns:
            bool: Status of the TMAX save operations.
        """

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Save Dolby Vision TMAX values for all formats
        self.saveDvTmaxValuesForAllFormats()

        # Get the list of streams from the test setup
        streams = self.testSetup.get("assets").get("device").get(self.testName).get("streams")

        # Get the supported LDIM states from the system
        ldim_states = self.testtvSettings.getLocalDimmingMode()
        pictureModeIndices = self.testtvSettings.getPictureModeInfo()

        # Loop through video formats and corresponding stream URLs
        for videoFormatIndex, (videoFormat, streamUrl) in enumerate(zip(self.testtvSettings.getVideoFormatInfo(), streams)):

            # Download the individual stream
            self.testDownloadAssetsByUrl(streamUrl)

            streamFullPath = os.path.join(self.targetWorkspace, os.path.basename(streamUrl))

            # Play the stream
            self.testPlayer.play(streamFullPath)
            time.sleep(3)

            pictureModeIndex = videoFormatIndex % len(pictureModeIndices)

            # Get the TMAX value based on the saved indices
            tmaxValue = self.dvTmax_values[videoFormatIndex]

            # Select the picture mode based on video format index using modulus logic
            pictureMode = self.testtvSettings.getPictureModeInfo()[
                (videoFormatIndex + pictureModeIndex) % len(self.testtvSettings.getPictureModeInfo())
            ]

            # Select the LDIM state using modulus logic from the retrieved list of states
            ldim_state = ldim_states[(pictureModeIndex * len(self.testtvSettings.getVideoFormatInfo()) + videoFormatIndex) % len(ldim_states)]

            self.testtvSettings.setPictureMode(pictureMode)

            # Set the LDIM state using self.testtvSettings.setLocalDimmingMode()
            self.testtvSettings.setLocalDimmingMode(ldim_state)

            # Log and start setting the TMAX value
            self.log.stepStart(f'Setting TMAX Value: {tmaxValue}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, LDIM State: {ldim_state}, Stream: {streamUrl}')

            # Call the verification function (manual=True allows for manual verification)
            result = self.testVerifyDvTmaxValue(pictureMode, videoFormat, tmaxValue, manual=True)

            # Log the result for each step
            self.log.stepResult(result, f'Verification for TMAX Value: {tmaxValue}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, LDIM State: {ldim_state}, Stream: {streamUrl}')

            # Stop the stream playback
            self.testPlayer.stop()

            # Clean the assets downloaded to the device
            self.testCleanAssetsByUrl(streamFullPath)

        # Set all TMAX values to the default value of 5000
        self.setAllDvTmaxToDefault()

        # Terminate the tvSettings Module
        self.testtvSettings.terminate()

        return result


if __name__ == '__main__':
    # Setup logging and run the test
    log_name = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summery_log = logModule(log_name, level=logModule.INFO)
    test = tvSettings_test56_SaveDvTmaxValue(summery_log)
    test.run(False)
