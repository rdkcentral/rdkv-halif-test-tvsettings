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
from raft.framework.core.logModule import logModule

class tvSettings_test27_WBcalibration(tvSettingsHelperClass):

    wbCalibrationModes = [0, 1, 0]  # WBCalibrationMode values

    def __init__(self, log:logModule=None):
        """
        Initializes the test27 WBCalibrationMode test.

        Args:
            None.
        """
        self.testName = "test27_WBCalibrationMode"
        self.qcID = '27'
        super().__init__(self.testName, self.qcID, log)

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

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)

            for wbCalibrationMode in self.wbCalibrationModes:
                self.log.stepStart(f'WBCalibrationMode: {wbCalibrationMode} Stream: {stream}')

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
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test27_WBcalibration(summeryLog)
    test.run(False)
