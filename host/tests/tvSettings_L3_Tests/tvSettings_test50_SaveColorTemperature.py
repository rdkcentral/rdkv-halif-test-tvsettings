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

class tvSettings_test50_SaveColorTemperature(tvSettingsHelperClass):

    def __init__(self):
        """
        Initializes the SaveColorTemperature test.

        Args:
            None.
        """
        self.testName = "test50_SaveColorTemperature"
        super().__init__(self.testName, '50')

    def testVerifyColorTemperature(self, pictureMode, videoFormat, colorTemperature, manual=False):
        """
        Verifies whether the Color Temperature value is set or not.

        Args:
            pictureMode (str): Picture Mode.
            videoFormat (str): Video Format.
            colorTemperature (int): Color Temperature value.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to other verification methods.

        Returns:
            bool: Returns the status of the color temperature value.
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Is color temperature {colorTemperature} applied for Picture Mode: {pictureMode} and Video Format: {videoFormat}? (Y/N):"
            )
        else:
            # TODO: Add automation verification methods
            return False

    def testFunction(self):
        """This function tests saving Color Temperature values with all combinations of picture mode and video format.

        It also adds the option to restart the device to verify changes.

        Returns:
            bool: Status of the color temperature save operations.
        """

        self.log.testStart(self.testName, '50')  # Start the test with the defined test name

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Get the list of streams from the test setup
        streams = self.testSetup.get("assets").get("device").get(self.testName).get("streams")

        # Loop through video formats and corresponding stream URLs
        for videoFormat, streamUrl in zip(self.testtvSettings.getVideoFormatInfo(), streams):
            # Download the individual stream
            self.testDownloadAssetsByUrl(streamUrl)

            streamFullPath = os.path.join(self.deviceDownloadPath, os.path.basename(streamUrl))

            # Play the stream
            self.testPlayer.play(streamFullPath)
            time.sleep(3)  # Allow some time for the stream to start

            # Loop through available picture modes
            for pictureMode in self.testtvSettings.getPictureModeIndex():
                # Loop through defined color temperature values
                for colorTemperature in self.testtvSettings.getColorTemperatureInfo():
                    self.log.stepStart(f'Setting Color Temperature: {colorTemperature}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

                    # Set Picture Mode, Video Format, and Color Temperature
                    self.testtvSettings.saveColorTemperatureValues(pictureMode, videoFormat, colorTemperature)  # Call the saveColorTemperature function

                    self.log.info("Restarting the Stream...")
                    self.testPlayer.stop()  # Stop the current stream playback
                    self.testPlayer.play(streamFullPath)  # Restart the stream
                    self.log.info("Stream restarted, continuing verification...")

                    # Call the verification function (manual=True allows for manual verification)
                    result = self.testVerifyColorTemperature(pictureMode, videoFormat, colorTemperature, manual=True)  # Call the verification function

                    # Log the result for each step
                    self.log.stepResult(result, f'Verification for Color Temperature: {colorTemperature}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

            # Stop the stream playback
            self.testPlayer.stop()

            # Clean the assets downloaded to the device
            self.testCleanAssetsByUrl(streamFullPath)

        # Terminate the tvSettings Module
        self.testtvSettings.terminate()

        return result  # Return the last result of the verification

if __name__ == '__main__':
    test = tvSettings_test50_SaveColorTemperature()
    test.run(False)
