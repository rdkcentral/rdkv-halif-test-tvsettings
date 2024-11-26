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

dir_path = os.path.dirname(os.path.realpath(__file__))
sys.path.append(os.path.join(dir_path, "../"))

from tvSettings_L3_Tests.tvSettingsHelperClass import tvSettingsHelperClass
from raft.framework.core.logModule import logModule

class tvSettings_test15_ColorTemp(tvSettingsHelperClass):

    def __init__(self, log:logModule=None):
        """
        Initializes the test15 ColorTemp test.

        This constructor sets the test name and initializes the parent class.

        Args:
            None.
        """
        self.testName = "test15_ColorTemp"
        self.qcID = '15'
        super().__init__(self.testName, self.qcID, log)

    def testVerifyColorTempLevel(self, colorTemp, manual=False):
        """
        Verifies whether the ColorTemp level is applied.

        This method checks the color temperature level either manually or via automation.

        Args:
            colorTemp (int): ColorTemp value.
            manual (bool, optional): Indicates if manual verification is used.
                                     Defaults to False.

        Returns:
            bool: Status of color temperature application.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Has ColorTemp level {colorTemp} applied? (Y/N):")
        else:
            return False  # TODO: Add automation verification methods

    def testFunction(self):
        """
        Executes the ColorTemp test.

        This method:
        - Initializes the tvSettings module.
        - Plays each stream while setting and verifying color temperature levels.

        Returns:
            bool: Returns the final verification result.
        """
        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)

            for colorTemp in self.testtvSettings.getColorTemperatureInfo():
                self.log.stepStart(f'ColorTemp Level: {colorTemp} Stream: {stream}')

                # Set the ColorTemp level
                self.testtvSettings.setColorTempLevel(colorTemp)

                result = self.testVerifyColorTempLevel(colorTemp, True)

                self.log.stepResult(result, f'ColorTemp Level: {colorTemp} Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

        # Set the default ColorTemp level
        self.testtvSettings.setColorTempLevel()

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test15_ColorTemp(summeryLog)
    test.run(False)