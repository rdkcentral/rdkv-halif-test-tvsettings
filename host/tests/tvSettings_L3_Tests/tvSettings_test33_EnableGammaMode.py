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

class tvSettings_test33_EnableGammaMode(tvSettingsHelperClass):

    # Predefined gamma modes (0: Disable, 1: Enable)
    gammaModes = [0, 1, 0]

    def __init__(self, log:logModule=None):
        """
        Initializes the EnableGammaMode test.

        Args:
            None.
        """
        self.testName = "test33_EnableGammaMode"
        self.qcID = '33'
        super().__init__(self.testName, self.qcID, log)

    # TODO: Current version supports only manual verification.
    def testVerifyGammaMode(self, gammaMode, manual=False):
        """
        Verifies whether the gamma mode is set correctly.

        Args:
            gammaMode (int): Gamma mode value (0: Disable, 1: Enable).
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Returns the status of gamma mode.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Is gamma mode set to {gammaMode}? (Y/N):")
        else:
            # TODO: Add automation verification methods
            return False

    def testFunction(self):
        """This function tests the Enable Gamma Mode settings.

        Returns:
            bool: Status of the last gamma mode verification.
        """

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)

            for gammaMode in self.gammaModes:

                self.log.stepStart(f'Gamma Mode: {gammaMode}, Stream: {stream}')

                # Set the gamma mode
                self.testtvSettings.setEnableGammaMode(gammaMode)

                # Verify the gamma mode has been set
                result = self.testVerifyGammaMode(gammaMode, True)

                # Log the result of the gamma mode verification
                self.log.stepResult(result, f'Gamma Mode: {gammaMode}, Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

        # Terminate the tvSettings module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test33_EnableGammaMode(summeryLog)
    test.run(False)
