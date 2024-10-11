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

class tvSettings_test54_SaveCMS(tvSettingsHelperClass):

    cmsValues = [0, 25, 50, 75, 100]  # List of CMS values to test
    rackDevice = "dut"  # Device under test

    def __init__(self):
        """
        Initializes the SaveCMS test.

        Args:
            None.
        """
        self.testName = "test54_SaveCMS"
        super().__init__(self.testName, '54')

    # TODO: Current version supports only manual verification.
    def testVerifyCMSValue(self, pictureMode, videoFormat, componentType, componentColor, cmsValue, manual=False):
        """
        Verifies whether the CMS value is set or not.

        Args:
            pictureMode (str): Picture Mode.
            videoFormat (str): Video Format.
            componentType (str): Component Type.
            componentColor (str): Component Color.
            cmsValue (int): CMS value.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to other verification methods.

        Returns:
            bool: Returns the status of CMS value.
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Is CMS value '{cmsValue}' applied for Picture Mode: {pictureMode}, Video Format: {videoFormat}, "
                f"Component Type: {componentType}, Component Color: {componentColor}? (Y/N):"
            )
        else:
            # TODO: Add automation verification methods
            return False

    def testFunction(self):
        """This function tests saving CMS values with all combinations of picture mode and video format.

        It also adds the option to restart the device to verify changes.

        Returns:
            bool: Status of the CMS save operations.
        """
        self.log.testStart(self.testName, '54')  # Start the test with the defined test name

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

            # Loop through all picture modes and component types/colors
            for pictureMode in self.testtvSettings.getPictureModeIndex():
                for componentType in self.testtvSettings.getComponentTypeInfo():
                    for componentColor in self.testtvSettings.getTVDataColor():
                        # If componentType is COMP_NONE and componentColor is tvDataColor_NONE, treat cms_value as CMS state (true/false)
                        if componentType == 'COMP_NONE' and componentColor == 'tvDataColor_NONE':
                            # Reduce cmsValues to 1 (true) or 0 (false) for CMS state
                            cmsStateValues = [1, 0]  # true or false values for CMS state
                            for cms_value in cmsStateValues:
                                self.log.stepStart(f'Setting CMS state: {cms_value}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

                                # Set Picture Mode, Video Format, and CMS state
                                result = self.testtvSettings.saveCMS(pictureMode, videoFormat, componentType, componentColor, cms_value)

                                # Log the result for each step
                                self.log.stepResult(result, f'Verification for CMS state: {cms_value}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')
                        else:
                            # Iterate over the full range of CMS values for other component types and colors
                            for cms_value in self.cmsValues:
                                self.log.stepStart(f'Setting CMS: {cms_value}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

                                # Set Picture Mode, Video Format, and CMS value
                                result = self.testtvSettings.saveCMS(pictureMode, videoFormat, componentType, componentColor, cms_value)

                                # Log the result for each step
                                self.log.stepResult(result, f'Verification for CMS: {cms_value}, Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamUrl}')

            # Stop the stream playback
            self.testPlayer.stop()

            # Clean the assets downloaded to the device
            self.testCleanAssetsByUrl(streamFullPath)

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        return result  # Return the last result of the verification

if __name__ == '__main__':
    test = tvSettings_test54_SaveCMS()
    test.run(False)
