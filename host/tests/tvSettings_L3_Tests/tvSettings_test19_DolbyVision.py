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

class tvSettings_test19_DolbyVision(tvSettingsHelperClass):

    def __init__(self):
        """
        Initializes the test19 Dolby Vision test.

        This constructor sets the test name and initializes the parent class.

        Args:
            None.
        """
        self.testName = "test19_DolbyVision"
        super().__init__(self.testName, '19')

    def testQueryDolbyVisionLevel(self, DolbyVision, manual=False):
        """
        Queries whether the Dolby Vision level should be applied.

        This method prompts the user to confirm applying the Dolby Vision level.

        Args:
            DolbyVision (int): Dolby Vision level.
            manual (bool, optional): Indicates if manual verification is used.
                                     Defaults to False.

        Returns:
            bool: Status of Dolby Vision level query.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Do you want to apply Dolby Vision level {DolbyVision}? (Y/N):")
        else:
            return False  # TODO: Add automation verification methods

    def testVerifyDolbyVisionLevel(self, DolbyVision, manual=False):
        """
        Verifies whether the Dolby Vision level is applied.

        This method checks the Dolby Vision level either manually or via automation.

        Args:
            DolbyVision (int): Dolby Vision level.
            manual (bool, optional): Indicates if manual verification is used.
                                     Defaults to False.

        Returns:
            bool: Status of Dolby Vision application.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Has Dolby Vision level {DolbyVision} applied? (Y/N):")
        else:
            return False  # TODO: Add automation verification methods

    def testFunction(self):
        """
        Executes the Dolby Vision test.

        This method:
        - Initializes the tvSettings module.
        - Plays each stream while setting and verifying Dolby Vision levels.

        Returns:
            bool: Returns the final verification result.
        """
        self.log.testStart(self.testName, '19')

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)

            for DolbyVision in self.testtvSettings.getDolbyVisionInfo():
                self.log.stepStart(f'Dolby Vision Level: {DolbyVision} Stream: {stream}')

                # Query if Dolby Vision level should be applied
                result = self.testQueryDolbyVisionLevel(DolbyVision, True)

                self.log.stepResult(result, f'Dolby Vision Level: {DolbyVision} Stream: {stream}')

                if result:
                    # Set the Dolby Vision level
                    self.testtvSettings.setDolbyVision(DolbyVision)

                    # Verify if Dolby Vision level has been applied
                    result = self.testVerifyDolbyVisionLevel(DolbyVision, True)

                    self.log.stepResult(result, f'Dolby Vision Level: {DolbyVision} Stream: {stream}')

            # Stop the stream playback
            self.testPlayer.stop()

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    test = tvSettings_test19_DolbyVision()
    test.run(False)