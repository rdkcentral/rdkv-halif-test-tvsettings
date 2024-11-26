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

class tvSettings_test06_BacklightFade(tvSettingsHelperClass):

    backlightValues = [0, 50, 100]  # Using extremes and a middle value for better visibility
    fadeDurations = [500, 1000]  # Keeping fade durations shorter but noticeable

    def __init__(self, log:logModule=None):
        """
        Initializes the test06 BacklightFade test.

        This constructor sets the test name and calls the parent constructor.

        Args:
            None.
        """
        self.testName = "test06_BacklightFade"
        self.qcID = '6'
        super().__init__(self.testName, self.qcID, log)

    def testVerifyBacklightFadeLevel(self, fromVal, toVal, fadeDuration, manual=False):
        """
        Verifies whether the BacklightFade effect is applied.

        This method checks the backlight fade level based on user input or automation.

        Args:
            fromVal (int): Starting backlight value.
            toVal (int): Ending backlight value.
            fadeDuration (int): Fade duration in milliseconds.
            manual (bool, optional): Indicates if manual verification is used.
                                     Defaults to False.

        Returns:
            bool: Status of backlight fade application.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Has BacklightFade from {fromVal} to {toVal} with duration {fadeDuration} ms applied? (Y/N):")
        else:
            return False

    def testFunction(self):
        """
        Executes the BacklightFade Levels test.

        This method:
        - Initializes the tvSettings module.
        - Iterates through defined backlight values and fade durations.
        - Plays each stream while verifying backlight fade settings.

        Returns:
            bool: Returns the final verification result.
        """
        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        for stream in self.testStreams:
            for fromVal in self.backlightValues:
                for toVal in self.backlightValues:
                    for fadeDuration in self.fadeDurations:

                        self.log.stepStart(f'BacklightFade from {fromVal} to {toVal} with duration {fadeDuration} ms Stream:{stream}')

                        # Start the stream playback before setting backlight fade
                        self.testPlayer.play(stream)
                        time.sleep(3)

                        # Set backlightFade
                        self.testtvSettings.setBacklightFade(fromVal, toVal, fadeDuration)

                        result = self.testVerifyBacklightFadeLevel(fromVal, toVal, fadeDuration, True)

                        self.log.stepResult(result, f'BacklightFade from {fromVal} to {toVal} with duration {fadeDuration} ms Stream:{stream}')

                        # Stop the stream playback after each fade operation
                        self.testPlayer.stop()

        # Terminate tvSettings Module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test06_BacklightFade(summeryLog)
    test.run(False)
