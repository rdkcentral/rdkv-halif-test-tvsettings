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

class tvSettings_test41_EnableLocalContrast(tvSettingsHelperClass):

    # Predefined values for the Local Contrast parameter: 0 (disabled) and 1 (enabled)
    localContrastLevels = [0, 1, 0]

    def __init__(self, log:logModule=None):
        """
        Initializes the EnableLocalContrast test.

        Args:
            None.
        """
        self.testName = "test41_EnableLocalContrast"
        self.qcID = '41'
        super().__init__(self.testName, self.qcID, log)

    def testVerifyLocalContrast(self, localContrast, manual=False):
        """
        Verifies whether the Local Contrast is enabled/disabled correctly.

        Args:
            localContrast (int): Local Contrast value (0 or 1).
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Returns the status of Local Contrast.
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Is Local Contrast set to: {localContrast}? (Y/N):"
            )
        else:
            # TODO: Add automation verification methods
            return False

    def testFunction(self):
        """This function tests the Local Contrast functionality.

        Returns:
            bool: Status of the last Local Contrast verification.
        """

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)

            # Iterate over Local Contrast levels
            for contrast in self.localContrastLevels:
                self.log.stepStart(f'Set Local Contrast Level: {contrast}, Stream: {stream}')

                # Set the Local Contrast level
                self.testtvSettings.enableLocalContrast(contrast)

                # Verify the Local Contrast setting
                result = self.testVerifyLocalContrast(contrast, True)

                # Log the result of the Local Contrast verification
                self.log.stepResult(result, f'Local Contrast Level: {contrast}, Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

        # Terminate the tvSettings module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test41_EnableLocalContrast(summeryLog)
    test.run(False)
