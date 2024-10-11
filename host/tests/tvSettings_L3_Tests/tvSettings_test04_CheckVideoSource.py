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

class tvSettings_test04_CheckVideoSource(tvSettingsHelperClass):
    """
    Test class for validating video source functionalities.

    This class is designed to test various video sources supported by the device.
    It extends the tvSettingsHelperClass to leverage its utility methods for device interaction
    and test execution.

    Attributes:
        testName (str): Name of the test.
    """

    def __init__(self):
        """
        Initializes the test04 VideoSource test.

        Args:
            None.
        """
        self.testName = "test04_CheckVideoSource"
        super().__init__(self.testName, '4')  # Set test number to 4

    def testFunction(self):
        """
        Executes the Video Source test.

        This method:
        - Initializes the tvSettings module.
        - Retrieves the list of video sources and corresponding streams.
        - Plays each stream and verifies the video source.

        Returns:
            bool: Always returns True upon successful execution of the test.
        """
        self.log.testStart(self.testName, '4')  # Log start of the test with test number

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Iterate through each video source and corresponding stream
        for source, stream in zip(self.testtvSettings.getVideoSourceInfo(), self.testStreams):
            # Start the stream playback
            self.testPlayer.play(stream)
            time.sleep(3)  # Wait for a moment to let the stream start

            self.log.stepStart(f'Video Source Level: {source} Stream: {stream}')

            self.log.stepStart(f'Video FrameRate {source} Callback Test')

            # Retrieve the video content callback status
            cbVideoSource = self.testtvSettings.getVideoContentCallbackStatus()

            # Log the result of the video content callback test
            self.log.stepResult(cbVideoSource and source in cbVideoSource, f'Video FrameRate {source} Callback Test')

            # Check the current video source
            videoSource = self.testtvSettings.checkVideoSource()

            # Log the result of the video source test
            self.log.stepResult(source in videoSource, f'Video Source {source} Test')

            # Stop the stream playback
            self.testPlayer.stop()

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        return True

if __name__ == '__main__':
    test = tvSettings_test04_CheckVideoSource()
    test.run(False)
