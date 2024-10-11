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

dir_path = os.path.dirname(os.path.realpath(__file__))
sys.path.append(os.path.join(dir_path, "../"))

from tvSettings_L3_Tests.tvSettingsHelperClass import tvSettingsHelperClass

class tvSettings_test28_GammaTable(tvSettingsHelperClass):

    # Predefined RGB values for testing
    gammaCombinations = [
        {
            "size": 10,
            "red": [1023, 900, 800, 700, 600, 500, 400, 300, 200, 100],
            "green": [800, 750, 700, 650, 600, 500, 400, 300, 200, 100],
            "blue": [600, 500, 400, 300, 200, 100, 50, 30, 20, 10]
        },
        {
            "size": 5,
            "red": [300, 200, 100, 50, 0],
            "green": [600, 500, 400, 300, 200],
            "blue": [1023, 900, 800, 700, 600]
        },
        {
            "size": 10,
            "red": [600] * 10,
            "green": [600] * 10,
            "blue": [600] * 10
        },
        {
            "size": 5,
            "red": [1023, 1000, 900, 800, 700],
            "green": [500, 400, 300, 200, 100],
            "blue": [1023, 1000, 900, 800, 700]
        },
        {
            "size": 10,
            "red": [300] * 10,
            "green": [300] * 10,
            "blue": [300] * 10
        },
        {
            "size": 10,  # Reset Gamma Table
            "red": [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],  # Default values for Red
            "green": [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],  # Default values for Green
            "blue": [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]  # Default values for Blue
        }
    ]

    def __init__(self):
        """
        Initializes the test28 GammaTable test.

        Args:
            None.
        """
        self.testName = "test28_GammaTable"
        super().__init__(self.testName, '28')

    # TODO: Current version supports only manual verification.
    def testVerifyGammaTable(self, size, red, green, blue, manual=False):
        """
        Verifies whether the Gamma Table settings are set correctly.

        Args:
            size (int): Gamma Table size.
            red (list): List of Red values.
            green (list): List of Green values.
            blue (list): List of Blue values.
            manual (bool, optional): Manual verification (True: manual, False: other verification methods).
                                     Defaults to False.

        Returns:
            bool: Status of Gamma Table settings.
        """
        if manual:
            return self.testUserResponse.getUserYN(f"Is Gamma Table set with Size: {size}, R: {red}, G: {green}, B: {blue}? (Y/N):")
        else:
            # TODO: Add automation verification methods
            return False

    def testFunction(self):
        """This function tests the Gamma Table settings.

        Returns:
            bool: Status of the last verification.
        """

        self.log.testStart(self.testName, '28')

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

                self.log.stepStart(f'Setting Gamma Table Size: {size}, R: {red}, G: {green}, B: {blue}')

                # Set the Gamma Table
                self.testtvSettings.setGammaTable(size, red, green, blue)

                # Verify the Gamma Table settings
                result = self.testVerifyGammaTable(size, red, green, blue, True)

                # Log the result of the verification
                self.log.stepResult(result, f'Gamma Table Size: {size} R: {red}, G: {green}, B: {blue}')

            # Stop the stream playback after each stream
            self.testPlayer.stop()

        # Terminate the tvSettings module
        self.testtvSettings.terminate()

        return result

if __name__ == '__main__':
    test = tvSettings_test28_GammaTable()
    test.run(False)
