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

class tvSettings_test09_LocalDimmingLevel(tvSettingsHelperClass):

    def __init__(self, log:logModule=None):
        """
        Initializes the test09 LocalDimmingLevel test.

        This constructor sets the test name and calls the parent constructor.

        Args:
            None.
        """
        self.testName = "test09_LocalDimmingLevel"
        self.qcID = '9'
        super().__init__(self.testName, self.qcID, log)

    def testVerifyLocalDimmingLevel(self, localDimmingLevel, manual=False):
        """
        Verifies whether the LocalDimmingLevel setting is applied.

        This method checks the local dimming level based on user input or automation.

        Args:
            localDimmingLevel (int): Local Dimming Level value.
            manual (bool, optional): Indicates if manual verification is used.
                                     Defaults to False.

        Returns:
            bool: Status of local dimming level application.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Has Local Dimming Level {localDimmingLevel} applied? (Y/N):")
        else:
            return False  # TODO: Add automation verification methods

    def testFunction(self):
        """
        Executes the LocalDimmingLevel test.

        This method:
        - Initializes the tvSettings module.
        - Plays each stream while verifying the local dimming level settings.

        Returns:
            bool: Returns the final verification result.
        """
        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)
            time.sleep(3)

            # Get local dimming levels from the tvSettings class
            for localDimmingLevel in self.testtvSettings.getLocalDimmingMode():
                self.log.stepStart(f'Local Dimming Level:{localDimmingLevel} Stream:{stream}')

                # Set the Local Dimming Level
                self.testtvSettings.setLocalDimmingMode(localDimmingLevel)

                result = self.testVerifyLocalDimmingLevel(localDimmingLevel, True)

                self.log.stepResult(result, f'Local Dimming Level:{localDimmingLevel} Stream:{stream}')

            # Stop the stream playback
            self.testPlayer.stop()

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test09_LocalDimmingLevel(summeryLog)
    test.run(False)
