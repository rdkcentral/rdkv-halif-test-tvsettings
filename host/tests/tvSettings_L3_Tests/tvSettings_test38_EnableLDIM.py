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

class tvSettings_test38_EnableLDIM(tvSettingsHelperClass):

    # Two predefined values for the LDIM parameter: 0 (disabled) and 1 (enabled)
    ldimValues = [0, 1, 0]

    def __init__(self, log:logModule=None):
        """
        Initializes the EnableLDIM test.

        Args:
            None.
        """
        self.testName = "test38_EnableLDIM"
        self.qcID = '38'
        super().__init__(self.testName, self.qcID, log)

    def testVerifyLDIM(self, ldimValue, manual=False):
        """
        Verifies whether the LDIM is enabled or disabled.

        Args:
            ldimValue (int): Value for LDIM (0 for disabled, 1 for enabled).
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Returns the status of LDIM.
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Is LDIM set to: {ldimValue}? (Y/N):"
            )
        else:
            # TODO: Add automation verification methods
            return False

    def testFunction(self):
        """This function tests the LDIM functionality.

        Returns:
            bool: Status of the last LDIM verification.
        """
        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)

            # Set up different values for LDIM (0 and 1)
            for ldimValue in self.ldimValues:
                self.log.stepStart(f'LDIM: {ldimValue}, Stream: {stream}')

                # Set the LDIM
                self.testtvSettings.setEnableLDIM(ldimValue)

                # Verify the LDIM status
                result = self.testVerifyLDIM(ldimValue, True)

                # Log the result of the LDIM verification
                self.log.stepResult(result, f'LDIM: {ldimValue}, Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

        # Terminate the tvSettings module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test38_EnableLDIM(summeryLog)
    test.run(False)
