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
# * *******************************************************************************
import os
import sys
import time
import numpy as np

dir_path = os.path.dirname(os.path.realpath(__file__))
sys.path.append(os.path.join(dir_path, "../"))

from tvSettings_L3_Tests.tvSettingsHelperClass import tvSettingsHelperClass
from raft.framework.core.logModule import logModule

class tvSettings_test28_GammaTable(tvSettingsHelperClass):

    # Predefined RGB gamma curve values for testing
    gammaCombinations = [
        {
            # Curved gamma using x ^ (1/2)
            "description": "Curved gamma (x ^ 1/2)",
            "size": 255,
            "red": list((np.sqrt(np.linspace(0, 1, 255)) * 1023).astype(int)),
            "green": list((np.sqrt(np.linspace(0, 1, 255)) * 1023).astype(int)),
            "blue": list((np.sqrt(np.linspace(0, 1, 255)) * 1023).astype(int)),
        },
        {
            # Gamma using x ^ 2.2 for higher contrast
            "description": "Gamma (x ^ 2.2)",
            "size": 255,
            "red": list((np.power(np.linspace(0, 1, 255), 2.2) * 1023).astype(int)),
            "green": list((np.power(np.linspace(0, 1, 255), 2.2) * 1023).astype(int)),
            "blue": list((np.power(np.linspace(0, 1, 255), 2.2) * 1023).astype(int)),
        },
        {
            # Linear gamma using x ^ 1
            "description": "Linear gamma (x ^ 1)",
            "size": 255,
            "red": list(np.linspace(0, 1023, 255).astype(int)),
            "green": list(np.linspace(0, 1023, 255).astype(int)),
            "blue": list(np.linspace(0, 1023, 255).astype(int)),
        }
    ]

    def __init__(self, log:logModule=None):
        """
        Initializes the test28 GammaTable test.

        Args:
            None.
        """
        self.testName = "test28_GammaTable"
        self.qcID = '28'
        super().__init__(self.testName, self.qcID, log)

    def testVerifyGammaTable(self, description, manual=False):
        """
        Verifies whether the Gamma Table settings are set correctly.

        Args:
            description (str): Description of the gamma type.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Status of Gamma Table settings.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Is Gamma Table set with: {description}? (Y/N):")
        else:
            # TODO: Add automation verification methods
            return False

    def testFunction(self):
        """This function tests the Gamma Table settings.

        Returns:
            bool: Status of the last verification.
        """

        # Initialize the tvSettings module
        self.testtvSettings.initialise()

        for stream in self.testStreams:
            # Start the stream playback
            self.testPlayer.play(stream)

            for combination in self.gammaCombinations:
                # Generate Red, Green, and Blue values based on size
                size = combination["size"]
                red = combination["red"]
                green = combination["green"]
                blue = combination["blue"]
                description = combination["description"]

                self.log.stepStart(f'Setting Gamma Table Size: {size}, R: {red}, G: {green}, B: {blue}')

                # Set the Gamma Table
                self.testtvSettings.setGammaTable(size, red, green, blue)

                # Verify the Gamma Table settings
                result = self.testVerifyGammaTable(description, True)

                # Log the result of the verification
                self.log.stepResult(result, f'Gamma Table Size: {size} R: {red}, G: {green}, B: {blue}')

            # Stop the stream playback after each stream
            self.testPlayer.stop()

        # Terminate the tvSettings module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    summerLogName = os.path.splitext(os.path.basename(__file__))[0] + "_summery"
    summeryLog = logModule(summerLogName, level=logModule.INFO)
    test = tvSettings_test28_GammaTable(summeryLog)
    test.run(False)
