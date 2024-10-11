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
#* *******************************************************************************

import os
import sys
import time

dir_path = os.path.dirname(os.path.realpath(__file__))
sys.path.append(os.path.join(dir_path, "../"))

from tvSettings_L3_Tests.tvSettingsHelperClass import tvSettingsHelperClass

class tvSettings_test43_SaveTVDimmingMode(tvSettingsHelperClass):

    def __init__(self):
        """
        Initializes the SaveTVDimmingMode test.

        Args:
            None.
        """
        self.testName = "test43_SaveTVDimmingMode"
        super().__init__(self.testName, '43')

    def testVerifyDimmingValue(self, pictureMode, videoFormat, dimmingLevel, manual=False):
        """
        Verifies whether the Dimming value is set or not.

        Args:
            pictureMode (str): Picture Mode.
            videoFormat (str): Video Format.
            dimmingLevel (int): Dimming value.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to other verification methods.

        Returns:
            bool: returns the status of dimming value.
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Is dimming value {dimmingLevel} applied for Picture Mode: {pictureMode} and Video Format: {videoFormat}? (Y/N):"
            )
        else:
            # TODO: Add automation verification methods
            return False

    def testFunction(self):
        """This function tests saving TV dimming values with all combinations of picture mode and video format.

        It also adds the option to restart the device to verify changes.

        Returns:
            bool
        """

        self.log.testStart(self.testName, '43')

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Get the list of streams from the test setup
        streams = self.testSetup.get("assets").get("device").get(self.testName).get("streams")

        for videoFormat, streamUrl in zip(self.testtvSettings.getVideoFormatInfo(), streams):
            # Download the individual stream
            self.testDownloadAssetsByUrl(streamUrl)

            streamFullPath = os.path.join(self.deviceDownloadPath, os.path.basename(streamUrl))

            # Play the stream
            self.testPlayer.play(streamFullPath)
            time.sleep(3)  # Allow some time for the stream to start

            for pictureMode in self.testtvSettings.getPictureModeIndex():
                for dimmingLevel in self.testtvSettings.getTVDimmingMode():
                    self.log.stepStart(f'Set Dimming Level: {dimmingLevel}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

                    # Set Picture Mode, Video Format, and Dimming Level
                    result = self.testtvSettings.saveTVDimmingModeValues(pictureMode, videoFormat, dimmingLevel)

                    self.log.info("Restarting the Stream...")
                    self.testPlayer.stop()
                    self.testPlayer.play(streamFullPath)
                    self.log.info("Stream restarted, continuing verification...")

                    # Call the verification function (manual=True allows for manual verification)
                    result = self.testVerifyDimmingValue(pictureMode, videoFormat, dimmingLevel, manual=True)

                    # Log the result for each step
                    self.log.stepResult(result, f'Dimming Level: {dimmingLevel}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

            # Stop the stream playback
            self.testPlayer.stop()

            # Clean the assets downloaded to the device
            self.testCleanAssetsByUrl(streamFullPath)

        # Terminate tvSettings Module
        self.testtvSettings.terminate()


        return result


if __name__ == '__main__':
    test = tvSettings_test43_SaveTVDimmingMode()
    test.run(False)
