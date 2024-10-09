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
import yaml
import os
import sys
from enum import Enum, auto
import re

# Add parent outside of the class directory
dir_path = os.path.dirname(os.path.realpath(__file__))
sys.path.append(dir_path+"/../")

from raft.framework.plugins.ut_raft.configRead import ConfigRead
from raft.framework.plugins.ut_raft.utSuiteNavigator import UTSuiteNavigatorClass
from raft.framework.plugins.ut_raft.interactiveShell import InteractiveShell

class tvSettingsClass():

    moduleName = "tvSettings"
    menuConfig =  dir_path + "/tvSettings_test_suite.yml"
    testSuite = "L3 tvSettings"

    """
    tvSettings Class

    This module provides common extensions for tvSettings Module.
    """
    def __init__(self, deviceProfilePath:str, session=None ):
        """
        Initializes the tvSettings class function.
        """
        self.deviceProfile = ConfigRead( deviceProfilePath, self.moduleName)
        self.utMenu        = UTSuiteNavigatorClass(self.menuConfig, self.moduleName, session)
        self.testSession   = session
        self.utMenu.start()

    def initialise(self, formatChangeCBFile:str="", contentChangeCBFile:str="", resolutionChangeCBFile:str="", frameRateChangeCBFile:str=""):
        """
        Initializes the tvSettings module.

        Args:
            formatChangeCBFile - to log the format change callback status
            contentChangeCBFile - to log the content change callback status
            resolutionChangeCBFile - to log the resolution change callback status
            frameRateChangeCBFile - to log the frame rate change callback status

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "direct",
                    "query": "Enter file name with path to log Format change callbacks:",
                    "input": formatChangeCBFile
                },
                {
                    "query_type": "direct",
                    "query": "Enter file name with path to log content change callbacks:",
                    "input": contentChangeCBFile
                },
                {
                    "query_type": "direct",
                    "query": "Enter file name with path to log resolution change callbacks:",
                    "input": resolutionChangeCBFile
                },
                {
                    "query_type": "direct",
                    "query": "Enter file name with path to log Frame Rate change callbacks:",
                    "input": frameRateChangeCBFile
                }
        ]
        result = self.utMenu.select( self.testSuite, "Initialize tvSettings", promptWithAnswers)

    def setBacklight(self, backlightLevel:int=0):
        """
        Sets backlight.

        Args:
            backlight (int, optional): backlight to be applied. Ranges from 0 to 100. Defaults to 0

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "direct",
                    "query": "Enter the backlight value to set (0 - 100):",
                    "input": str(backlightLevel)
                }
        ]

        result = self.utMenu.select(self.testSuite, "Back light for tvSettings", promptWithAnswers)


    def setBrightnessLevel(self, brightnessLevel:int=0):
        """
        Sets brightness level.

        Args:
            brightnessLevel (int, optional): Brightness level to be applied. Ranges from 0 to 100. Defaults to 0

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "direct",
                    "query": "Enter the desired brightness value (0-100):",
                    "input": str(brightnessLevel)
                }
        ]

        result = self.utMenu.select(self.testSuite, "Brightness for tvSettings", promptWithAnswers)

    def setContrastLevel(self, contrastLevel: int = 0):
        """
        Sets contrast level.

        Args:
            contrastLevel (int, optional): Contrast level to be applied. Ranges from 0 to 100. Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "direct",
                    "query": "Enter the desired contrast value (0-100):",
                    "input": str(contrastLevel)
                }
        ]

        result = self.utMenu.select(self.testSuite, "Contrast for tvSettings", promptWithAnswers)

    def setSharpnessLevel(self, sharpnessLevel: int = 0):
        """
        Sets sharpness level.

        Args:
            sharpnessLevel (int, optional): Sharpness level to be applied. Ranges from 0 to 100. Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "direct",
                    "query": "Enter the desired sharpness value (0-100):",
                    "input": str(sharpnessLevel)
                }
        ]

        result = self.utMenu.select(self.testSuite, "Sharpness for tvSettings", promptWithAnswers)

    def setSaturationLevel(self, saturationLevel: int = 0):
        """
        Sets saturation level.

        Args:
            saturationLevel (int, optional): Saturation level to be applied. Ranges from 0 to 100. Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "direct",
                    "query": "Enter the desired saturation value (0-100):",
                    "input": str(saturationLevel)
                }
        ]

        result = self.utMenu.select(self.testSuite, "Saturation for tvSettings", promptWithAnswers)

    def setHueLevel(self, hueLevel: int = 0):
        """
        Sets hue level.

        Args:
             hueLevel (int, optional): Hue level to be applied. Ranges from 0 to 100. Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "direct",
                    "query": "Enter the desired hue value (0-100):",
                     "input": str(hueLevel)
                }
        ]

        result = self.utMenu.select(self.testSuite, "Hue for tvSettings", promptWithAnswers)

    def setColorTempLevel(self, ColorTempLevel: int=0):
        """
        Sets ColorTempLevel level.

        Args:
             ColorTempLevelLevel (int, optional): ColorTempLevel level to be applied. Ranges from 0 to 100. Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "direct",
                    "query": "Enter the desired color temperature. value:",
                     "input": str(ColorTempLevel)
                }
        ]

        result = self.utMenu.select(self.testSuite, "ColorTemperature for tvSettings", promptWithAnswers)

    def getColorTemperature(self):
        return self.deviceProfile.get("ColorTemperature").get("index")


    def terminate(self):
        """
        Enables the tvSettings port.

        Args:
            None.

        Returns:
            None
        """
        result = self.utMenu.select(self.testSuite, "Terminate tvSettings")