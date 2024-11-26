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
# * you may obtain a copy of the License at
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

class tvSettings_test36_GrayPattern(tvSettingsHelperClass):

    # Five predefined Gray levels (range: 0-255)
    grayLevels = [0, 64, 128, 192, 255, 0]

    def __init__(self, log:logModule=None):
        """
        Initializes the GrayPattern test.

        Args:
            None.
        """
        self.testName = "test36_GrayPattern"
        self.qcID = '36'
        super().__init__(self.testName, self.qcID, log)

    def testVerifyGrayPattern(self, grayLevel, manual=False):
        """
        Verifies whether the Gray pattern is set correctly.

        Args:
            grayLevel (int): Gray level value.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Returns the status of the Gray pattern.
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Is Gray pattern set to Gray Level: {grayLevel}? (Y/N):"
            )
        else:
            # TODO: Add automation verification methods
            return False

    def testFunction(self):
        """This function tests the Gray Pattern functionality.

        Returns:
            bool: Status of the last Gray pattern verification.
        """

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Set up different values for gray levels across the predefined samples
        for grayLevel in self.grayLevels:
            self.log.stepStart(f'Gray Level: {grayLevel}')

            # Set the Gray pattern
            self.testtvSettings.setGrayPattern(grayLevel)

            # Verify the Gray pattern has been set correctly
            result = self.testVerifyGrayPattern(grayLevel, True)

            # Log the result of the Gray pattern verification
            self.log.stepResult(result, f'Gray Level: {grayLevel}')

        # Terminate the tvSettings module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test36_GrayPattern(summeryLog)
    test.run(False)
