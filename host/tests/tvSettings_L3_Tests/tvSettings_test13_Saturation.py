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

class tvSettings_test13_Saturation(tvSettingsHelperClass):

    saturationLevels = [0, 25, 50, 75, 100, 50]

    def __init__(self, log:logModule=None):
        """
        Initializes the test13 Saturation test.

        This constructor sets the test name and initializes the parent class.

        Args:
            None.
        """
        self.testName = "test13_Saturation"
        self.qcID = '13'
        super().__init__(self.testName, self.qcID, log)

    def testVerifySaturationLevel(self, saturation, manual=False):
        """
        Verifies whether the Saturation level is applied.

        This method checks the saturation level either manually or via automation.

        Args:
            saturation (int): Saturation value.
            manual (bool, optional): Indicates if manual verification is used.
                                     Defaults to False.

        Returns:
            bool: Status of saturation level application.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Has saturation level {saturation} applied? (Y/N):")
        else:
            return False  # TODO: Add automation verification methods

    def testFunction(self):
        """
        Executes the Saturation test.

        This method:
        - Initializes the tvSettings module.
        - Plays each stream while setting and verifying saturation levels.

        Returns:
            bool: Returns the final verification result.
        """
        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)
            time.sleep(3)

            for saturation in self.saturationLevels:
                self.log.stepStart(f'Saturation Level: {saturation} Stream: {stream}')

                # Set the saturation level
                self.testtvSettings.setSaturationLevel(saturation)

                result = self.testVerifySaturationLevel(saturation, True)

                self.log.stepResult(result, f'Saturation Level: {saturation} Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test13_Saturation(summeryLog)
    test.run(False)
