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

class tvSettings_test05_Backlight(tvSettingsHelperClass):

    backlightLevels = [0, 25, 50, 75, 100, 50]

    def __init__(self, log:logModule=None):
        """
        Initializes the test05 Backlight test.

        This constructor sets the test name and calls the parent constructor.

        Args:
            None.
        """
        self.testName = "test05_Backlight"
        self.qcID = '5'
        super().__init__(self.testName, self.qcID, log)

    def testVerifyBacklightLevel(self, backlight, manual=False):
        """
        Verifies whether the backlight level is applied.

        This method checks the backlight level based on user input or automation.

        Args:
            backlight (int): Backlight value to verify.
            manual (bool, optional): Indicates if manual verification is used.
                                     Defaults to False.

        Returns:
            bool: Status of backlight application.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Has backlight level {backlight} applied? (Y/N):")
        else:
            # TODO: Add automation verification methods
            return False

    def testFunction(self):
        """
        Executes the Backlight Levels test.

        This method:
        - Initializes the tvSettings module.
        - Iterates through defined backlight levels.
        - Plays each stream while verifying backlight settings.

        Returns:
            bool: Returns the final verification result.
        """
        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)
            time.sleep(3)

            for backlight in self.backlightLevels:

                self.log.stepStart(f'Backlight Level:{backlight} Stream:{stream}')

                # Set backlight
                self.testtvSettings.setBacklight(backlight)

                result = self.testVerifyBacklightLevel(backlight, True)

                self.log.stepResult(result, f'Backlight Level:{backlight} Stream:{stream}')

            # Stop the stream playback
            self.testPlayer.stop()

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        return result


if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test05_Backlight(summeryLog)
    test.run(False)
