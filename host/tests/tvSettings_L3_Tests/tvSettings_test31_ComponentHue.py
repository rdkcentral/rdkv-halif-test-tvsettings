#!/usr/bin/env python3
#** *****************************************************************************
# * Copyright 2024 RDK Management
# * Licensed under the Apache License, Version 2.0
# * http://www.apache.org/licenses/LICENSE-2.0
#* *****************************************************************************

import os
import sys
import time

dir_path = os.path.dirname(os.path.realpath(__file__))
sys.path.append(os.path.join(dir_path, "../"))

from tvSettings_L3_Tests.tvSettingsHelperClass import tvSettingsHelperClass
from raft.framework.core.logModule import logModule

class tvSettings_test31_ComponentHue(tvSettingsHelperClass):

    def __init__(self, log:logModule=None):
        """Initializes the ComponentHue test."""
        self.testName = "test31_ComponentHue"
        self.qcID = '31'
        super().__init__(self.testName, self.qcID, log)
        self.hueValues = []  # Predefined hue values ranging from 0 to 100

    def testVerifyComponentHue(self, hueValue, manual=False):
        """
        Verifies whether the Component Hue is set correctly.

        Args:
            hueValue (int): The component hue value to verify.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Status indicating whether the component hue is set correctly.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Has component hue value {hueValue} applied? (Y/N):")
        else:
            # TODO: Add automation verification methods
            return False

    def setComponentHueForAllStreams(self):
        """Sets the Component Hue settings based on video formats and picture modes."""

        # Get available TV Data Colors, Video Formats, and Picture Modes
        tvDataColors = self.testtvSettings.getTVDataColor()
        videoFormats = self.testtvSettings.getVideoFormatInfo()
        pictureModes = self.testtvSettings.getPictureModeInfo()

        # Sync video formats with streams
        streams = self.testSetup.get("assets").get("device").get(self.testName).get("streams")

        # Define hue values from 0 to 100 for testing purposes
        numVideoFormats = len(videoFormats)
        self.hueValues = [int(i * (100 / (numVideoFormats - 1))) for i in range(numVideoFormats)]

        # Download and play streams, set component hue for each picture mode and format
        for videoFormatIndex, (videoFormat, stream) in enumerate(zip(videoFormats, streams)):

            self.testDownloadAssetsByUrl(stream)

            streamFullPath = os.path.join(self.targetWorkspace, os.path.basename(stream))

            self.testPlayer.play(streamFullPath)
            time.sleep(3)

            # Set component hue for each picture mode
            for pictureMode in pictureModes:

                self.testtvSettings.setPictureMode(pictureMode)

                hueValue = self.hueValues[videoFormatIndex]

                color = tvDataColors[videoFormatIndex % len(tvDataColors)]

                self.testtvSettings.setComponentHue(color, hueValue)

            # Stop the stream playback
            self.testPlayer.stop()


    def resetComponentHueToDefault(self):
        """
        Sets the component hue to the default value (50) for all color and picture mode combinations.

        """

        defaultHueValue = 50
        tvDataColors = self.testtvSettings.getTVDataColor()
        pictureModes = self.testtvSettings.getPictureModeInfo()

        # Sync video formats with streams
        streams = self.testSetup.get("assets").get("device").get(self.testName).get("streams")

        for stream in streams:
            # Download and play the stream
            self.testDownloadAssetsByUrl(stream)
            streamFullPath = os.path.join(self.targetWorkspace, os.path.basename(stream))

            self.testPlayer.play(streamFullPath)
            time.sleep(3)  # Allow some time for the stream to start playing

            # Set default hue for each color and picture mode
            for pictureMode in pictureModes:
                self.testtvSettings.setPictureMode(pictureMode)
                for color in tvDataColors:
                    self.testtvSettings.setComponentHue(color, defaultHueValue)

            # Stop the stream playback after setting the default values
            self.testPlayer.stop()



    def testFunction(self):
        """This function tests the Component Hue settings.

        Returns:
            bool: Status of the last verification.
        """

        self.testtvSettings.initialise()  # Initialize the tvSettings module

        self.testtvSettings.setCMSState(1)  # Set the CMS state

        self.setComponentHueForAllStreams()  # Set the hue values for all streams

        # Get available TV Data Colors, Video Formats, and Picture Modes
        videoFormats = self.testtvSettings.getVideoFormatInfo()
        tvDataColors = self.testtvSettings.getTVDataColor()
        pictureModes = self.testtvSettings.getPictureModeInfo()

        # Sync video formats with streams
        streams = self.testSetup.get("assets").get("device").get(self.testName).get("streams")

        result = False  # Initialize result variable
        # Perform the verification by playing streams and verifying hue values
        for videoFormatIndex, (videoFormat, stream) in enumerate(zip(videoFormats, streams)):

            self.testDownloadAssetsByUrl(stream)

            streamFullPath = os.path.join(self.targetWorkspace, os.path.basename(stream))

            # Play the stream before verification
            self.testPlayer.play(streamFullPath)
            time.sleep(3)

            for pictureMode in pictureModes:
                self.testtvSettings.setPictureMode(pictureMode)

                hueValue = self.hueValues[videoFormatIndex]

                color = tvDataColors[videoFormatIndex % len(tvDataColors)]

                self.log.stepStart(f'Setting Component Hue: {hueValue},  Color: {color}, Picture Mode: {pictureMode}, '
                                   f'Video Format: {videoFormat}, Stream: {streamFullPath}')

                # Verify the component hue value
                result = self.testVerifyComponentHue(hueValue, True)

                self.log.stepResult(result, f'Verification for Component Hue: {hueValue}, Color: {color}, '
                                            f'Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamFullPath}')

            # Stop the stream playback after verification
            self.testPlayer.stop()

        #set to default values
        self.resetComponentHueToDefault()

        self.testtvSettings.setCMSState(0)  # Set the CMS state

        # Terminate the tvSettings module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test31_ComponentHue(summeryLog)
    test.run(False)
