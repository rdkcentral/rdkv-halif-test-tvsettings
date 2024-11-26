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

dir_path = os.path.dirname(os.path.realpath(__file__))
sys.path.append(os.path.join(dir_path, "../"))

from tvSettings_L3_Tests.tvSettingsHelperClass import tvSettingsHelperClass
from raft.framework.core.logModule import logModule

class tvSettings_test39_SetBacklightTestMode(tvSettingsHelperClass):

    def __init__(self, log:logModule=None):
        """
        Initializes the SetBacklightTestMode test.

        Args:
            None.
        """
        self.testName = "test39_SetBacklightTestMode"
        self.qcID = '39'
        super().__init__(self.testName, self.qcID, log)

    def testVerifyBacklightMode(self, backlightMode, manual=False):
        """
        Verifies whether the backlight mode is set correctly.

        Args:
            backlightMode (int): Value of the backlight mode obtained from getBacklightTestModeInfo.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Returns the status of backlight mode.
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Is backlight mode set to: {backlightMode}? (Y/N):"
            )
        else:
            # TODO: Add automation verification methods
            return False

    def testFunction(self):
        """This function tests the Backlight Test Mode.

        Returns:
            bool: Status of the last backlight mode verification.
        """
        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)

            # Iterate over available backlight modes
            for backlightMode in self.testtvSettings.getBacklightTestModeInfo():
                self.log.stepStart(f'SetBacklightTestMode to: {backlightMode}, Stream: {stream}')

                # Set the Backlight Test Mode
                self.testtvSettings.setBacklightTestMode(backlightMode)

                # Verify the backlight mode status
                result = self.testVerifyBacklightMode(backlightMode, True)

                # Log the result of the backlight mode verification
                self.log.stepResult(result, f'Backlight Mode: {backlightMode}, Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

        # Terminate the tvSettings module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test39_SetBacklightTestMode(summeryLog)
    test.run(False)
