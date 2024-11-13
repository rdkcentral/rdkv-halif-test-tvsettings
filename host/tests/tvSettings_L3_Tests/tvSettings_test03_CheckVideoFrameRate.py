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

class tvSettings_test03_CheckVideoFrameRate(tvSettingsHelperClass):
    """
    Test class for validating video frame rate functionalities.

    This class is designed to test various video frame rates supported by the device.
    It extends the tvSettingsHelperClass to leverage its utility methods for device interaction
    and test execution.

    Attributes:
        testName (str): Name of the test.
    """

    def __init__(self, log:logModule=None):
        """
        Initializes the test03 VideoFrameRate test.

        Args:
            None.
        """
        self.testName = "test03_CheckVideoFrameRate"
        self.qcID = '3'
        super().__init__(self.testName, self.qcID, log)  # Set test number to 3

        # List of all supported video frame rates
        self.supportedFrameRates = [
            "30",
            "60",
            "23dot98",
            "59dot94"
            "24",
            "25",
            "50",
            "29dot97",
        ]

    def testFunction(self):
        """
        Executes the Video Frame Rate Level test.

        This method:
        - Initializes the tvSettings module.
        - Retrieves the list of video frame rates.
        - Iterates through each video frame rate and corresponding stream URL.
        - Downloads, plays, and verifies each video frame rate.

        Returns:
            bool: Always returns True upon successful execution of the test.
        """
        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Get the list of video frame rates currently supported
        videoFrameRates = self.testtvSettings.getVideoFrameRateInfo()

        # Get the list of streams from the test setup
        streams = self.testSetup.get("assets").get("device").get(self.testName).get("streams")

        # Iterate through each supported frame rate and corresponding stream in order
        for frameRate, streamUrl in zip(self.supportedFrameRates, streams):
            # Check if the format is present as a substring in any item of videoFormats
            if not any(frameRate in vf for vf in videoFrameRates):
                continue

            # Download the individual stream
            self.testDownloadAssetsByUrl(streamUrl)

            streamFullPath = os.path.join(self.targetWorkspace, os.path.basename(streamUrl))

            # Play the stream
            self.testPlayer.play(streamFullPath)
            time.sleep(3)

            self.log.stepStart(f'Video FrameRate {frameRate} Callback Test')

            # Retrieve the video frame rate callback status
            cbVideoFrameRate = self.testtvSettings.getVideoFrameRateCallbackStatus()

            # Log the result of the video frame rate callback test
            self.log.stepResult(cbVideoFrameRate and frameRate in cbVideoFrameRate,
                                f'Video FrameRate {frameRate} Callback Test')

            self.log.stepStart(f'Frame Rate Level: {frameRate} Stream: {streamFullPath}')

            # Check the current video frame rate
            currentFrameRate = self.testtvSettings.checkVideoFrameRate()

            # Log the result of the frame rate check
            self.log.stepResult(frameRate in currentFrameRate, f'Frame Rate {frameRate} Test')

            # Stop the stream playback
            self.testPlayer.stop()

            # Clean the assets (delete the downloaded stream)
            self.testCleanAssetsByUrl(streamFullPath)

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        return True

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test03_CheckVideoFrameRate(summeryLog)
    test.run(False)
