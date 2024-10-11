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

class tvSettings_test01_CheckVideoFormat(tvSettingsHelperClass):
    """
    Test class for validating video format functionalities.

    This class is designed to test various video formats supported by the device.
    It extends the tvSettingsHelperClass to leverage its utility methods for device interaction
    and test execution.

    Attributes:
        testName (str): Name of the test.
    """

    def __init__(self):
        """
        Initializes the test01 VideoFormat test.

        Args:
            None.
        """
        self.testName = "test01_CheckVideoFormat"
        super().__init__(self.testName, '1') # Set test number to 3

    def testFunction(self):
        """
        Executes the Video Format Level test.

        This method:
        - Initializes the tvSettings module.
        - Retrieves the list of video formats.
        - Iterates through each video format and corresponding stream URL.
        - Downloads, plays, and verifies each video format.

        Returns:
            bool: Always returns True upon successful execution of the test.
        """
        self.log.testStart(self.testName, '1') # Log start of the test with test number

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Get the list of video formats
        videoFormats = self.testtvSettings.getVideoFormatInfo()

        # Iterate through each video format and corresponding stream URL
        for format, streamUrl in zip(videoFormats, self.testSetup.get("assets").get("device").get(self.testName).get("streams")):

            # Download the individual stream (using the updated testDownloadAssets)
            self.testDownloadAssetsByUrl(streamUrl)

            streamFullPath = os.path.join(self.deviceDownloadPath, os.path.basename(streamUrl))

            # Play the stream
            self.testPlayer.play(streamFullPath)
            time.sleep(3)

            self.log.stepStart(f'videoFormat Level: {format} Stream: {streamFullPath}')

            self.log.stepStart(f'Video Format {format} Callback Test')

            # Retrieve the video format callback status
            cbVideoFormat = self.testtvSettings.getVideoFormatCallbackStatus()

            # Log the result of the video format callback test
            self.log.stepResult(cbVideoFormat and format in cbVideoFormat, f'Video Format {format} Callback Test')

            # Check the current video format
            videoFormat = self.testtvSettings.checkVideoFormat()

            # Log the result of the video format check
            self.log.stepResult(format in videoFormat, f'Video Format {format} Test')

            # Stop the stream playback
            self.testPlayer.stop()

            # Clean the assets (delete the downloaded stream using testCleanAssets)
            self.testCleanAssetsByUrl(streamFullPath)

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        return True

if __name__ == '__main__':
    test = tvSettings_test01_CheckVideoFormat()
    test.run(False)