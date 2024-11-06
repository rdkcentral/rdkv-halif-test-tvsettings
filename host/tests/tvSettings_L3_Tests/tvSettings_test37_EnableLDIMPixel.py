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

class tvSettings_test37_EnableLDIMPixelCompensation(tvSettingsHelperClass):

    # Two predefined values for the LDIM Pixel Compensation parameter: 0 and 1
    ldimPixelCompensationValues = [0, 1, 0]

    def __init__(self):
        """
        Initializes the EnableLDIMPixelCompensation test.

        Args:
            None.
        """
        self.testName = "test37_EnableLDIMPixelCompensation"
        super().__init__(self.testName, '37')

    def testVerifyLDIMPixelCompensation(self, ldimValue, manual=False):
        """
        Verifies whether the LDIM Pixel Compensation is enabled or disabled.

        Args:
            ldimValue (int): Value for LDIM Pixel Compensation (0 for disabled, 1 for enabled).
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Returns the status of LDIM Pixel Compensation.
        """
        if manual:
            return self.testUserResponse.getUserYN(
                f"Is LDIM Pixel Compensation set to: {ldimValue}? (Y/N):"
            )
        else:
            # TODO: Add automation verification methods
            return False

    def testFunction(self):
        """This function tests the LDIM Pixel Compensation functionality.

        Returns:
            bool: Status of the last LDIM Pixel Compensation verification.
        """
        self.log.testStart(self.testName, '37')

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)

            # Set up different values for LDIM Pixel Compensation (0 and 1)
            for ldimValue in self.ldimPixelCompensationValues:
                self.log.stepStart(f'LDIM Pixel Compensation: {ldimValue}, Stream: {stream}')

                # Set the LDIM Pixel Compensation
                self.testtvSettings.setEnableLDIMPixelCompensation(ldimValue)

                # Verify the LDIM Pixel Compensation status
                result = self.testVerifyLDIMPixelCompensation(ldimValue, True)

                # Log the result of the LDIM Pixel Compensation verification
                self.log.stepResult(result, f'LDIM Pixel Compensation: {ldimValue}, Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

        # Terminate the tvSettings module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    test = tvSettings_test37_EnableLDIMPixelCompensation()
    test.run(False)
