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

class tvSettings_test04_CheckVideoSource(tvSettingsHelperClass):
    """
    Test class for validating video source functionalities.

    This class is designed to test the VIDEO_SOURCE_IP supported by the device.
    It extends the tvSettingsHelperClass to leverage its utility methods for device interaction
    and test execution.

    Attributes:
        testName (str): Name of the test.
    """

    def __init__(self, log:logModule=None):
        """
        Initializes the test04 VideoSource test.

        Args:
            None.
        """
        self.testName = "test04_CheckVideoSource"
        self.qcID = '4'
        super().__init__(self.testName, self.qcID, log)  # Set test number to 4

    def testFunction(self):
        """
        Executes the Video Source test for VIDEO_SOURCE_IP.

        This method:
        - Initializes the tvSettings module.
        - Retrieves the list of video sources.
        - Tests only VIDEO_SOURCE_IP if supported.

        Returns:
            bool: Always returns True upon successful execution of the test.
        """
        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Get the streams associated with the test
        streams = self.testSetup.get("assets").get("device").get(self.testName).get("streams")

        # Iterate through streams, but only for VIDEO_SOURCE_IP
        for stream in streams:
            # Start the stream playback
            self.testPlayer.play(stream)
            time.sleep(3)  # Wait for a moment to let the stream start

            self.log.stepStart(f'Video Source Level: VIDEO_SOURCE_IP Stream: {stream}')

            # Check the current video source
            videoSource = self.testtvSettings.checkVideoSource()

            # Log the result of the video source test
            self.log.stepResult("VIDEO_SOURCE_IP" in videoSource, 'Video Source VIDEO_SOURCE_IP Test')

            # Stop the stream playback
            self.testPlayer.stop()

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        return True

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test04_CheckVideoSource(summeryLog)
    test.run(False)
