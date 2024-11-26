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

class tvSettings_test29_DvTmax(tvSettingsHelperClass):

    # Predefined DVT max values for testing
    dvtMaxValues = [0, 2500, 5000, 7500, 10000, 5000]

    def __init__(self, log:logModule=None):
        """
        Initializes the DVTmaxValue test.

        Args:
            None.
        """
        self.testName = "test29_DVTmaxValue"
        self.qcID = '29'
        super().__init__(self.testName, self.qcID, log)

    def testVerifyDVTmaxValue(self, dvtMaxValue, manual=False):
        """
        Verifies whether the DVT max value is set correctly.

        Args:
            dvtMaxValue (int): DVT max value to verify.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Status indicating whether the DVT max value is set correctly.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Has DVT max value {dvtMaxValue} applied? (Y/N):")
        else:
            # TODO: Add automation verification methods
            return False

    def testFunction(self):
        """This function tests the DVTmaxValue settings.

        Returns:
            bool: Status of the last verification.
        """

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)

            for dvtMaxValue in self.dvtMaxValues:
                self.log.stepStart(f'DVT max value: {dvtMaxValue} Stream: {stream}')

                # Set the DVT max value
                self.testtvSettings.setDvTmaxValue(dvtMaxValue)

                # Verify the DVT max value
                result = self.testVerifyDVTmaxValue(dvtMaxValue, True)

                # Log the result of the verification
                self.log.stepResult(result, f'DVT max value: {dvtMaxValue} Stream: {stream}')

            # Stop the stream playback after each stream
            self.testPlayer.stop()

        # Terminate the tvSettings module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test29_DvTmax(summeryLog)
    test.run(False)
