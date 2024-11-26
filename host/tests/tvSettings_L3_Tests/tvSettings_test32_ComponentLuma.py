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

class tvSettings_test32_ComponentLuma(tvSettingsHelperClass):

    def __init__(self, log:logModule=None):
        """Initializes the ComponentLuma test."""
        self.testName = "test32_ComponentLuma"
        self.qcID = '32'
        super().__init__(self.testName, self.qcID, log)
        self.lumaValues = []

    def testVerifyComponentLuma(self, lumaValue, manual=False):
        """
        Verifies whether the Component Luma is set correctly.

        Args:
            lumaValue (int): The component luma value to verify.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Status indicating whether the component luma is set correctly.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Has component luma value {lumaValue} applied? (Y/N):")
        else:
            # TODO: Add automation verification methods
            return False

    def setComponentLumaForAllStreams(self):
        """Sets the Component Luma settings based on video formats and picture modes."""

        # Get available TV Data Colors, Video Formats, and Picture Modes
        tvDataColors = self.testtvSettings.getTVDataColor()
        videoFormats = self.testtvSettings.getVideoFormatInfo()
        pictureModes = self.testtvSettings.getPictureModeInfo()

        # Sync video formats with streams
        streams = self.testSetup.get("assets").get("device").get(self.testName).get("streams")

        # Calculate luma values based on number of video formats
        numVideoFormats = len(videoFormats)
        self.lumaValues = [int(i * (30 / (numVideoFormats - 1))) for i in range(numVideoFormats)]

        # Download and play streams, set component luma for each picture mode and format
        for videoFormatIndex, (videoFormat, stream) in enumerate(zip(videoFormats, streams)):

            self.testDownloadAssetsByUrl(stream)

            streamFullPath = os.path.join(self.targetWorkspace, os.path.basename(stream))

            self.testPlayer.play(streamFullPath)
            time.sleep(3)

            # Set component luma for each picture mode
            for pictureMode in pictureModes:

                self.testtvSettings.setPictureMode(pictureMode)

                lumaValue = self.lumaValues[videoFormatIndex]

                color = tvDataColors[videoFormatIndex % len(tvDataColors)]

                self.testtvSettings.setComponentLuma(color, lumaValue)

            # Stop the stream playback
            self.testPlayer.stop()


    def resetComponentLumaToDefault(self):
        """
        Sets the component luma to the default value (15) for all color and picture mode combinations.

        """

        defaultLumaValue = 15
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

            # Set default luma for each color and picture mode
            for pictureMode in pictureModes:
                self.testtvSettings.setPictureMode(pictureMode)
                for color in tvDataColors:
                    self.testtvSettings.setComponentLuma(color, defaultLumaValue)

            # Stop the stream playback after setting the default values
            self.testPlayer.stop()


    def testFunction(self):
        """This function tests the Component Luma settings.

        Returns:
            bool: Status of the last verification.
        """

        self.testtvSettings.initialise()  # Initialize the tvSettings module

        self.testtvSettings.setCMSState(1)  # Set the CMS state

        self.setComponentLumaForAllStreams()  # Set the luma values for all streams

        # Get available TV Data Colors, Video Formats, and Picture Modes
        videoFormats = self.testtvSettings.getVideoFormatInfo()
        tvDataColors = self.testtvSettings.getTVDataColor()
        pictureModes = self.testtvSettings.getPictureModeInfo()

        # Sync video formats with streams
        streams = self.testSetup.get("assets").get("device").get(self.testName).get("streams")

        result = False  # Initialize result variable
        # Perform the verification by playing streams and verifying luma values
        for videoFormatIndex, (videoFormat, stream) in enumerate(zip(videoFormats, streams)):

            self.testDownloadAssetsByUrl(stream)

            streamFullPath = os.path.join(self.targetWorkspace, os.path.basename(stream))

            # Play the stream before verification
            self.testPlayer.play(streamFullPath)
            time.sleep(3)

            for pictureMode in pictureModes:
                self.testtvSettings.setPictureMode(pictureMode)

                lumaValue = self.lumaValues[videoFormatIndex]

                color = tvDataColors[videoFormatIndex % len(tvDataColors)]

                self.log.stepStart(f'Setting Component Luma: {lumaValue},  Color: {color}, Picture Mode: {pictureMode}, '
                                   f'Video Format: {videoFormat}, Stream: {streamFullPath}')

                # Verify the component luma value
                result = self.testVerifyComponentLuma(lumaValue, True)

                self.log.stepResult(result, f'Verification for Component Luma: {lumaValue}, Color: {color}, '
                                            f'Picture Mode: {pictureMode}, Video Format: {videoFormat}, Stream: {streamFullPath}')

            # Stop the stream playback after verification
            self.testPlayer.stop()

        #reset to default values
        self.resetComponentLumaToDefault()

        self.testtvSettings.setCMSState(0)  # Reset the CMS state

        # Terminate the tvSettings module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test32_ComponentLuma(summeryLog)
    test.run(False)
