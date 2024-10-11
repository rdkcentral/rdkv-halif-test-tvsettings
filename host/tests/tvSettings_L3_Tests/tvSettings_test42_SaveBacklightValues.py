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
# * http://www.apache.org/licenses/LICENSE-2.0
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

class tvSettings_test42_SaveBacklightValues(tvSettingsHelperClass):

    # Predefined backlight values to test: 0, 25, 50, 75, 100
    backlightValues = [0, 25, 50, 75, 100]

    def __init__(self):
        """
        Initializes the SaveBacklightValues test.

        Args:
            None.
        """
        self.testName = "test42_SaveBacklightValues"
        super().__init__(self.testName, '42')

    def testVerifyBacklightValue(self, pictureMode, videoFormat, backlight, manual=False):
        """
        Verifies whether the Backlight value is set correctly.

        Args:
            pictureMode (str): Picture Mode.
            videoFormat (str): Video Format.
            backlight (int): Backlight value.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Returns the status of backlight value.
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Is backlight value {backlight} applied for Picture Mode: {pictureMode} and Video Format: {videoFormat}? (Y/N):"
            )
        else:
            # TODO: Add automation verification methods
            return False

    def testFunction(self):
        """This function tests saving backlight values with all combinations of picture mode and video format.

        Adds the option to restart the device to verify changes.

        Returns:
            bool: Status of the backlight save operations.
        """
        self.log.testStart(self.testName, '42')

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Loop through video formats and corresponding stream URLs
        for videoFormat, streamUrl in zip(self.testtvSettings.getVideoFormatInfo(), self.testSetup.get("assets").get("device").get(self.testName).get("streams")):
            # Download the individual stream (using the updated testDownloadAssets)
            self.testDownloadAssetsByUrl(streamUrl)

            streamFullPath = os.path.join(self.deviceDownloadPath, os.path.basename(streamUrl))

            # Play the stream
            self.testPlayer.play(streamFullPath)
            time.sleep(3)  # Wait for the stream to start

            # Loop through available picture modes
            for pictureMode in self.testtvSettings.getPictureModeIndex():
                # Loop through predefined backlight values
                for backlight in self.backlightValues:

                    self.log.stepStart(f'Set Backlight Value: {backlight}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

                    # Set Picture Mode, Video Format, and Backlight Value
                    self.testtvSettings.saveBacklightValues(pictureMode, videoFormat, backlight)

                    self.log.info("Restarting the Stream...")
                    self.testPlayer.stop()
                    self.testPlayer.play(streamFullPath)
                    self.log.info("Device restarted, continuing verification...")

                    # Call the verification function (manual=True allows for manual verification)
                    result = self.testVerifyBacklightValue(pictureMode, videoFormat, backlight, manual=True)

                    # Log the result for each step
                    self.log.stepResult(result, f'Backlight Value: {backlight}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

            # Stop the stream playback
            self.testPlayer.stop()

            # Clean the assets downloaded to the device
            self.testCleanAssetsByUrl(streamFullPath)

        # Terminate the tvSettings module
        self.testtvSettings.terminate()

        return True

if __name__ == '__main__':
    test = tvSettings_test42_SaveBacklightValues()
    test.run(False)
