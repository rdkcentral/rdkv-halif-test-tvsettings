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
from raft.framework.core.logModule import logModule

class tvSettings_test07_BacklightMode(tvSettingsHelperClass):

    def __init__(self, log:logModule=None):
        """
        Initializes the test07 BacklightMode test.

        This constructor sets the test name and calls the parent constructor.

        Args:
            None.
        """
        self.testName = "test07_BacklightMode"
        self.qcID = '7'
        super().__init__(self.testName, self.qcID, log)

    def testVerifyBacklightMode(self, backlightMode, manual=False):
        """
        Verifies whether the BacklightMode setting is applied.

        This method checks the backlight mode level based on user input or automation.

        Args:
            backlightMode (int): Backlight mode value.
            manual (bool, optional): Indicates if manual verification is used.
                                     Defaults to False.

        Returns:
            bool: Status of backlight mode application.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Has BacklightMode level {backlightMode} applied? (Y/N):")
        else:
            return False  # TODO: Add automation verification methods

    def testFunction(self):
        """
        Executes the BacklightMode Levels test.

        This method:
        - Initializes the tvSettings module.
        - Plays each stream while verifying the backlight mode settings.

        Returns:
            bool: Returns the final verification result.
        """
        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)
            time.sleep(3)

            for backlightMode in self.testtvSettings.getBacklightMode():

                self.log.stepStart(f'BacklightMode Level:{backlightMode} Stream:{stream}')

                # Set the BacklightMode level
                self.testtvSettings.setBacklightMode(backlightMode)

                result = self.testVerifyBacklightMode(backlightMode, True)

                self.log.stepResult(result, f'BacklightMode Level:{backlightMode} Stream:{stream}')

            # Set the BacklightMode level to default
            self.testtvSettings.setBacklightMode()

            # Stop the stream playback
            self.testPlayer.stop()

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test07_BacklightMode(summeryLog)
    test.run(False)
