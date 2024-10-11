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
# *
# http://www.apache.org/licenses/LICENSE-2.0
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

class tvSettings_test03_CheckVideoFrameRate(tvSettingsHelperClass):
    """
    Test class for validating video frame rate functionalities.

    This class is designed to test various video frame rates supported by the device.
    It extends the tvSettingsHelperClass to leverage its utility methods for device interaction
    and test execution.

    Attributes:
        testName (str): Name of the test.
    """

    def __init__(self):
        """
        Initializes the test03 VideoFrameRate test.

        Args:
            None.
        """
        self.testName = "test03_CheckVideoFrameRate"
        super().__init__(self.testName, '3')  # Set test number to 3

    def testFunction(self):
        """
        Executes the Video Frame Rate test.

        This method:
        - Initializes the tvSettings module.
        - Retrieves the list of frame rates and their corresponding stream URLs.
        - Downloads, plays, and verifies each video frame rate.

        Returns:
            bool: Always returns True upon successful execution of the test.
        """
        self.log.testStart(self.testName, '3')  # Log start of the test with test number

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Get the list of frame rates and streams
        frameRates = self.testtvSettings.getVideoFrameRateInfo()
        streams = self.testSetup.get("assets").get("device").get(self.testName).get("streams")

        # Iterate through each frame rate and corresponding stream URL
        for frameRate, streamUrl in zip(frameRates, streams):
            # Download the individual stream
            self.testDownloadAssetsByUrl(streamUrl)

            streamFullPath = os.path.join(self.deviceDownloadPath, os.path.basename(streamUrl))

            # Start the stream playback
            self.testPlayer.play(streamFullPath)
            time.sleep(10)  # Wait for a moment to let the stream start

            self.log.stepStart(f'Frame Rate Level: {frameRate} Stream: {streamFullPath}')

            self.log.stepStart(f'Video FrameRate {frameRate} Callback Test')

            # Retrieve the video frameRate callback status
            cbVideoFrameRate = self.testtvSettings.getVideoFrameRateCallbackStatus()

            # Log the result of the video frameRate callback test
            self.log.stepResult(cbVideoFrameRate and frameRate in cbVideoFrameRate, f'Video FrameRate {frameRate} Callback Test')

            # Check the current frame rate
            currentFrameRate = self.testtvSettings.checkVideoFrameRate()

            # Log the result of the frame rate test
            self.log.stepResult(frameRate in currentFrameRate, f'Frame Rate {frameRate} Test')

            # Stop the stream playback
            self.testPlayer.stop()

            # Clean the assets (delete the downloaded stream)
            self.testCleanAssetsByUrl(streamFullPath)

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        return True

if __name__ == '__main__':
    test = tvSettings_test03_CheckVideoFrameRate()
    test.run(False)
