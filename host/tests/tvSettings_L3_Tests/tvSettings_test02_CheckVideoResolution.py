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

class tvSettings_test02_CheckVideoResolution(tvSettingsHelperClass):
    """
    Test class for validating video resolution functionalities.

    This class is designed to test various video resolutions supported by the device.
    It extends the tvSettingsHelperClass to leverage its utility methods for device interaction
    and test execution.

    Attributes:
        testName (str): Name of the test.
    """

    def __init__(self):
        """
        Initializes the test02 VideoResolution test.

        Args:
            None.
        """
        self.testName = "test02_CheckVideoResolution"
        super().__init__(self.testName, '2') # Set test number to 3

    def testFunction(self):
        """
        Executes the Video Resolution Level test.

        This method:
        - Initializes the tvSettings module.
        - Retrieves the list of video resolutions and their corresponding stream URLs.
        - Downloads, plays, and verifies each video resolution.

        Returns:
            bool: Always returns True upon successful execution of the test.
        """
        self.log.testStart(self.testName, '2') # Log start of the test with test number

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Get the list of streams and video resolutions
        streams = self.testSetup.get("assets").get("device").get(self.testName).get("streams")
        videoResolutions = self.testtvSettings.getVideoResolutionInfo()

        # Iterate through each resolution and corresponding stream URL
        for resolution, streamUrl in zip(videoResolutions, streams):
            # Download the individual stream
            self.testDownloadAssetsByUrl(streamUrl)

            streamFullPath = os.path.join(self.deviceDownloadPath, os.path.basename(streamUrl))

            # Start the stream playback
            self.testPlayer.play(streamFullPath)
            time.sleep(3)

            self.log.stepStart(f'Video Resolution Level: {resolution} Stream: {streamFullPath}')

            self.log.stepStart(f'Video Resolution {resolution} Callback Test')

            # Retrieve the video resolution callback status
            cbVideoResolution = self.testtvSettings.getVideoResolutionCallbackStatus()

            # Log the result of the video resolution callback test
            self.log.stepResult(cbVideoResolution and resolution in cbVideoResolution, f'Video Resolution {resolution} Callback Test')

            # Check the current video resolution
            videoResolution = self.testtvSettings.checkVideoResolution()

            # Log the result of the video resolution test
            self.log.stepResult(resolution in videoResolution, f'Video Resolution {resolution} Test')

            # Stop the stream playback
            self.testPlayer.stop()

            # Clean the assets (delete the downloaded stream)
            self.testCleanAssetsByUrl(streamFullPath)

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        return True

if __name__ == '__main__':
    test = tvSettings_test02_CheckVideoResolution()
    test.run(False)
