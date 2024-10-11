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
# * *******************************************************************************
import os
import sys

dir_path = os.path.dirname(os.path.realpath(__file__))
sys.path.append(os.path.join(dir_path, "../"))

from tvSettings_L3_Tests.tvSettingsHelperClass import tvSettingsHelperClass

class tvSettings_test27_WBCalibrationMode(tvSettingsHelperClass):

    wbCalibrationModes = [1, 0]  # WBCalibrationMode values

    def __init__(self):
        """
        Initializes the test27 WBCalibrationMode test.

        Args:
            None.
        """
        self.testName = "test27_WBCalibrationMode"
        super().__init__(self.testName, '27')

    # TODO: Current version supports only manual verification.
    def testQueryWBCalibrationLevel(self, wbCalibration, manual=False):
        """
        Queries whether the WBCalibration is to set or not.

        Args:
            wbCalibration (int): WBCalibration value to be set.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Status of WBCalibration setting.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Do you want to make WBCalibration {wbCalibration}? (Y/N):")
        else:
            # TODO: Add automation verification methods
            return False

    # TODO: Current version supports only manual verification.
    def testVerifyWBCalibrationMode(self, wbCalibrationMode, manual=False):
        """
        Verifies whether the WBCalibrationMode is set or not.

        Args:
            wbCalibrationMode (int): WBCalibrationMode value that was set.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Status of WBCalibrationMode application.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Has WBCalibrationMode {wbCalibrationMode} applied? (Y/N):")
        else:
            # TODO: Add automation verification methods
            return False

    def testFunction(self):
        """This function tests the WBCalibrationMode settings.

        Returns:
            bool: Returns the status of the last verification.
        """

        self.log.testStart(self.testName, '27')

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)

            for wbCalibrationMode in self.wbCalibrationModes:
                self.log.stepStart(f'WBCalibrationMode: {wbCalibrationMode} Stream: {stream}')

                # Query the user about the WBCalibration level
                self.testQueryWBCalibrationLevel(wbCalibrationMode, True)

                # Set the WBCalibrationMode
                self.testtvSettings.setWBCalibration(wbCalibrationMode)

                # Verify the applied WBCalibrationMode manually
                result = self.testVerifyWBCalibrationMode(wbCalibrationMode, True)

                # Log the result of the verification
                self.log.stepResult(result, f'WBCalibrationMode: {wbCalibrationMode} Stream: {stream}')

            # Stop the stream playback after each stream
            self.testPlayer.stop()

        # Terminate the tvSettings module
        self.testtvSettings.terminate()

        return result


if __name__ == '__main__':
    test = tvSettings_test27_WBCalibrationMode()
    test.run(False)
