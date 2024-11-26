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

class tvSettings_test35_RGBPattern(tvSettingsHelperClass):

    # Five different values for red, green, and blue levels (range: 0-255)
    rgbLevels = [
        {'red': 255, 'green': 0, 'blue': 0},
        {'red': 0, 'green': 255, 'blue': 0},
        {'red': 0, 'green': 0, 'blue': 255},
        {'red': 255, 'green': 255, 'blue': 255},
        {'red': 0, 'green': 0, 'blue': 0}
    ]

    def __init__(self, log:logModule=None):
        """
        Initializes the RGBPattern test.

        Args:
            None.
        """
        self.testName = "test35_RGBPattern"
        self.qcID = '35'
        super().__init__(self.testName, self.qcID, log)

    def testVerifyRGBPattern(self, redLevel, greenLevel, blueLevel, manual=False):
        """
        Verifies whether the RGB pattern is set correctly.

        Args:
            redLevel (int): Red level value.
            greenLevel (int): Green level value.
            blueLevel (int): Blue level value.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Returns the status of RGB pattern.
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Is RGB pattern set to Red Level: {redLevel}, Green Level: {greenLevel}, Blue Level: {blueLevel}? (Y/N):"
            )
        else:
            # TODO: Add automation verification methods
            return False

    def testFunction(self):
        """This function tests the RGB Pattern functionality.

        Returns:
            bool: Status of the last RGB pattern verification.
        """

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        # Set up different values for red, green, and blue levels across the predefined samples
        for levels in self.rgbLevels:
            redLevel = levels['red']
            greenLevel = levels['green']
            blueLevel = levels['blue']

            self.log.stepStart(f'Red Level: {redLevel}, Green Level: {greenLevel}, Blue Level: {blueLevel}')

            # Set the RGB pattern
            self.testtvSettings.setRGBPattern(redLevel, greenLevel, blueLevel)

            # Verify the RGB pattern has been set correctly
            result = self.testVerifyRGBPattern(redLevel, greenLevel, blueLevel, True)

            # Log the result of the RGB pattern verification
            self.log.stepResult(result, f'Red Level: {redLevel}, Green Level: {greenLevel}, Blue Level: {blueLevel},')

        # Terminate the tvSettings module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test35_RGBPattern(summeryLog)
    test.run(False)
