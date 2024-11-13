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
from raft.framework.core.logModule import logModule

class tvSettings_test02_CheckVideoResolution(tvSettingsHelperClass):
    """
    Test class for validating video resolution functionalities.

    Attributes:
        testName (str): Name of the test.
    """

    def __init__(self, log:logModule=None):
        """
        Initializes the test02 VideoResolution test.
        """
        self.testName = "test02_CheckVideoResolution"
        self.qcID = '2'
        super().__init__(self.testName, self.qcID, log)  # Set test number to 2

        # Supported video resolutions with interlace information
        # Each entry is a list of [resolution, is_interlaced]
        self.supportedResolutions = [
            ["720x240", 0], ["2880x240", 0], ["720x288", 0], ["2880x288", 0], ["640x480", 0],
            ["720x480", 0], ["800x480", 0], ["852x480", 0], ["854x480", 0], ["1440x480", 1],
            ["2880x480", 1], ["960x540", 0], ["3840x540", 0], ["720x576", 1], ["1440x576", 1],
            ["2880x576", 1], ["800x600", 0], ["1024x600", 0], ["1280x600", 0], ["1280x720", 0],
            ["1280x1024", 0], ["1680x720", 0], ["1024x768", 0], ["1280x768", 0], ["1360x768", 0],
            ["1366x768", 0], ["1440x900", 0], ["1600x900", 0], ["1280x960", 0], ["1920x1080", 1],
            ["2560x1080", 0], ["3840x1080", 0], ["1600x1200", 0], ["1920x1200", 0], ["2160x1200", 0],
            ["2400x1200", 0], ["2560x1440", 0], ["3440x1440", 0], ["3840x2160", 0], ["4096x2160", 0]
        ]

    def testFunction(self):
        """
        Executes the Video Resolution Level test.

        Returns:
            bool: Always returns True upon successful execution of the test.
        """
        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Get the list of video resolutions and the streams
        videoResolutions = self.testtvSettings.getVideoResolutionInfo()
        streams = self.testSetup.get("assets").get("device").get(self.testName).get("streams")

        # Iterate over each resolution and stream in the supported resolutions
        for streamUrl, (resolution, is_interlaced) in zip(streams, self.supportedResolutions):
            # Check if the format is present as a substring in any item of videoFormats
            if not any(resolution in vr for vr in videoResolutions):
                continue

            # Download and play the stream
            self.testDownloadAssetsByUrl(streamUrl)
            streamFullPath = os.path.join(self.targetWorkspace, os.path.basename(streamUrl))
            self.testPlayer.play(streamFullPath)
            time.sleep(3)

            # Check the video resolution callback status
            cbVideoResolution = self.testtvSettings.getVideoResolutionCallbackStatus()

            if cbVideoResolution:
                cb_resolution_name, cb_width, cb_height, cb_is_interlaced = cbVideoResolution
                cb_res = cb_resolution_name.split('_')[-1]
                expected_width, expected_height = map(int, resolution.split('x'))
                resolution_pass = (resolution == cb_res) and (is_interlaced == cb_is_interlaced)
                height_check = (expected_height == cb_height)
                width_check = (expected_width == cb_width)

                # Log the result of the callback checks
                self.log.stepResult(
                    resolution_pass and height_check and width_check,
                    f'Callback Check Test: Resolution Match: {resolution_pass}, '
                    f'Height Check: Expected {expected_height}, Got {cb_height}, '
                    f'Width Check: Expected {expected_width}, Got {cb_width}'
                )
            else:
                self.log.stepResult(False, f'Failed to retrieve video resolution callback status.')

            # Check the current video resolution
            videoResolution = self.testtvSettings.checkVideoResolution()

            if videoResolution:
                # Extract returned resolution details
                actualWidth = videoResolution["width"]
                actualHeight = videoResolution["height"]
                actualIsInterlaced = videoResolution["isInterlaced"]
                actualResolutionName = videoResolution["resolutionName"]
                resValue = actualResolutionName.split('_')[-1]

                # Parse expected width and height from the resolution parameter
                expectedWidth, expectedHeight = map(int, resolution.split('x'))

                # Validate width, height, and interlace status
                widthCheck = actualWidth == expectedWidth
                heightCheck = actualHeight == expectedHeight
                interlaceCheck = actualIsInterlaced == is_interlaced
                resolutionCheck = resolution == resValue

                # Log the result of the video resolution check
                self.log.stepResult(
                    widthCheck and heightCheck and interlaceCheck and resolutionCheck,
                    f'Video Resolution Check: Expected {resolution} ({expectedWidth}x{expectedHeight}, Interlaced: {is_interlaced}), '
                    f'Got: {actualResolutionName} ({actualWidth}x{actualHeight}, Interlaced: {actualIsInterlaced})'
                )
            else:
                self.log.stepResult(False, 'Failed to retrieve video resolution from checkVideoResolution.')

            # Stop the stream playback and clean up
            self.testPlayer.stop()
            self.testCleanAssetsByUrl(streamFullPath)

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        return True


if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test02_CheckVideoResolution(summeryLog)
    test.run(False)
