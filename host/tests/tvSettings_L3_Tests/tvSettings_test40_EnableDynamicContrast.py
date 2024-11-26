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

class tvSettings_test40_EnableDynamicContrast(tvSettingsHelperClass):

    dynamicContrastLevels = [0, 1, 0]

    def __init__(self, log:logModule=None):
        """
        Initializes the EnableDynamicContrast test.

        Args:
            None.
        """
        self.testName = "test40_EnableDynamicContrast"
        self.qcID = '40'
        super().__init__(self.testName, self.qcID, log)

    def testVerifyDynamicContrast(self, dynamicContrast, manual=False):
        """
        Verifies whether the Dynamic Contrast is enabled/disabled correctly.

        Args:
            dynamicContrast (int): Dynamic Contrast value (0 or 1).
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to other verification methods.

        Returns:
            bool: returns the status of Dynamic Contrast.
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Is Dynamic Contrast set to: {dynamicContrast}? (Y/N):"
            )
        else:
            # TODO: Add automation verification methods
            return False

    def testFunction(self):
        """This function tests the Dynamic Contrast functionality.

        Returns:
            bool
        """
        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)

            for contrast in self.dynamicContrastLevels:

                    self.log.stepStart(f'Query Dynamic Contrast Level: {contrast} Stream: {stream}')
                    # Set the Dynamic Contrast level
                    self.testtvSettings.enableDynamicContrast(contrast)

                    result = self.testVerifyDynamicContrast(contrast, True)

                    self.log.stepResult(result, f'Dynamic Contrast Level: {contrast} Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test40_EnableDynamicContrast(summeryLog)
    test.run(False)
