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

class tvSettings_test01_CheckVideoFormat(tvSettingsHelperClass):
    """
    Test class for validating video format functionalities.

    This class is designed to test various video formats supported by the device.
    It extends the tvSettingsHelperClass to leverage its utility methods for device interaction
    and test execution.

    Attributes:
        testName (str): Name of the test.
    """

    def __init__(self, log:logModule=None):
        """
        Initializes the test01 VideoFormat test.

        Args:
            None.
        """
        self.testName = "test01_CheckVideoFormat"
        self.qcID = '1'
        super().__init__(self.testName, self.qcID, log) # Set test number to 1

        # List of all supported video formats
        self.supportedFormats = [
            "HDR10",
            "DV",
            "HLG",
            "SDR",
            "MVC"
            "HDR10PLUS",
            "PRIMESL",
        ]

    def testFunction(self):
        """
        Executes the Video Format Level test.

        This method:
        - Initializes the tvSettings module.
        - Retrieves the list of video formats.
        - Iterates through each video format and corresponding stream URL.
        - Downloads, plays, and verifies each video format.
        - Verifies SDR callback after stopping non-SDR streams.

        Returns:
            bool: Always returns True upon successful execution of the test.
        """
        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Get the list of video formats currently supported
        videoFormats = self.testtvSettings.getVideoFormatInfo()

        # Get the list of streams from the test setup
        streams = self.testSetup.get("assets").get("device").get(self.testName).get("streams")

        # Iterate through each supported video format and corresponding stream in order
        for streamUrl, format in zip(streams, self.supportedFormats):
            # Check if the format is present as a substring in any item of videoFormats
            if not any(format in vf for vf in videoFormats):
                continue

            # Download the individual stream
            self.testDownloadAssetsByUrl(streamUrl)

            streamFullPath = os.path.join(self.targetWorkspace, os.path.basename(streamUrl))

            # Play the stream
            self.testPlayer.play(streamFullPath)
            time.sleep(3)

            self.log.stepStart(f'Video Format {format} Callback Test')

            # Retrieve the video format callback status
            cbVideoFormat = self.testtvSettings.getVideoFormatCallbackStatus()

            # Log the result of the video format callback test
            self.log.stepResult(cbVideoFormat and format in cbVideoFormat, f'Video Format {format} Callback Test')

            self.log.stepStart(f'Video Format Level: {format} Stream: {streamFullPath}')

            # Check the current video format
            videoFormat = self.testtvSettings.checkVideoFormat()

            # Log the result of the video format check
            self.log.stepResult(format in videoFormat, f'Video Format {format} Test')

            # Stop the stream playback
            self.testPlayer.stop()

            time.sleep(2)  # Allow time for the default callback to occur
            cbVideoFormatAfterStop = self.testtvSettings.getVideoFormatCallbackStatus()

            # Clean the assets (delete the downloaded stream)
            self.testCleanAssetsByUrl(streamFullPath)

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        return True



if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test01_CheckVideoFormat(summeryLog)
    test.run(False)