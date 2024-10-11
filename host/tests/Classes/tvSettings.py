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

class ComponentType(Enum):
    COMP_NONE                             = 0              # No Component
    COMP_HUE                              = auto()         # Component is Hue
    COMP_SATURATION                       = auto()         # Component is Saturation
    COMP_LUMA                             = auto()         # Component is Luma

class tvColorTemperature(Enum):
    tvColorTemp_STANDARD                  = 0              # Color Temperature is Standard
    tvColorTemp_WARM                      = auto()         # Color Temperature is Warm
    tvColorTemp_COLD                      = auto()         # Color Temperature is Cold
    tvColorTemp_USER                      = auto()         # User defined color temperature
    tvColorTemp_BOOST_STANDARD            = auto()         # Color Temperature is Standard for boost mode
    tvColorTemp_BOOST_WARM                = auto()         # Color Temperature is Warm for boost mode
    tvColorTemp_BOOST_COLD                = auto()         # Color Temperature is Cold for boost mode
    tvColorTemp_BOOST_USER                = auto()         # User defined color temperature for boost mode
    tvColorTemp_SUPERCOLD                 = auto()         # Color Temperature is Supercold
    tvColorTemp_BOOST_SUPERCOLD           = auto()         # Color Temperature is Supercold for boost mode

class tvDataColor(Enum):
    tvDataColor_RED                       = 1              # Color is Red
    tvDataColor_GREEN                     = 2              # Color is Green
    tvDataColor_BLUE                      = 4              # Color is Blue
    tvDataColor_YELLOW                    = 8              # Color is Yellow
    tvDataColor_CYAN                      = 16             # Color is Cyan
    tvDataColor_MAGENTA                   = 32             # Color is Magenta

class tvDolbyMode(Enum):
    tvDolbyMode_Dark                      = 0              # Dolby mode is Dolby Dark
    tvDolbyMode_Bright                    = auto()         # Dolby mode is Dolby Bright
    tvDolbyMode_Game                      = auto()         # Dolby mode is Dolby Game
    tvHDR10Mode_Dark                      = auto()         # HDR10 mode is HDR10 Dark
    tvHDR10Mode_Bright                    = auto()         # HDR10 mode is HDR10 Bright
    tvHDR10Mode_Game                      = auto()         # HDR10 mode is HDR10 Game
    tvHLGMode_Dark                        = auto()         # HLG mode is HLG Dark
    tvHLGMode_Bright                      = auto()         # HLG mode is HLG Bright
    tvHLGMode_Game                        = auto()         # HLG mode is HLG Game

class PQMode(Enum):
    standard                               = 0               # Picture mode is "Standard" or "Entertainment"
    vivid                                  = auto()          # Picture mode is "Vivid" or "Dynamic"
    energysaving                           = auto()          # Picture mode is "Energy Saving"
    custom                                 = auto()          # Picture mode is "Custom" or "Expert"
    theater                                = auto()          # Picture mode is "Theater" or "Movie"
    reserved1                              = auto()          # Picture mode is Reserved
    reserved2                              = auto()          # Picture mode is Reserved
    game                                   = auto()          # Picture mode is "Game"
    sports                                 = auto()          # Picture mode is "Sports"
    graphics                               = auto()          # Picture mode is "Graphics"
    fmm                                    = auto()          # Picture mode is "Filmmaker"
    vivid2                                 = auto()          # Picture mode is "Vivid2" or "Dynamic2"

class PQMode_(Enum):
    PQ_MODE_STANDARD                       = 0               # Picture mode is "Standard" or "Entertainment"
    PQ_MODE_VIVID                          = auto()          # Picture mode is "Vivid" or "Dynamic"
    PQ_MODE_ENERGY_SAVING                  = auto()          # Picture mode is "Energy Saving"
    PQ_MODE_CUSTOM                         = auto()          # Picture mode is "Custom" or "Expert"
    PQ_MODE_THEATER                        = auto()          # Picture mode is "Theater" or "Movie"
    PQ_MODE_RESERVED1                      = auto()          # Picture mode is Reserved
    PQ_MODE_RESERVED2                      = auto()          # Picture mode is Reserved
    PQ_MODE_GAME                           = auto()          # Picture mode is "Game"
    PQ_MODE_SPORTS                         = auto()          # Picture mode is "Sports"
    PQ_MODE_GRAPHICS                       = auto()          # Picture mode is "Graphics"
    PQ_MODE_FMM                            = auto()          # Picture mode is "Filmmaker"
    PQ_MODE_VIVID2                         = auto()          # Picture mode is "Vivid2" or "Dynamic2"

class tvBacklightMode(Enum):
    tvBacklightMode_NONE                  = 0               # No backlight
    tvBacklightMode_MANUAL                = auto()          # Backlight mode is manual
    tvBacklightMode_AMBIENT               = auto()          # Backlight mode is ambient
    tvBacklightMode_ECO                   = auto()          # Backlight mode is eco
    tvBacklightMode_INVALID               = auto()          # Backlight mode is invalid
    tvBacklightMode_MAX                   = auto()          # End of enum

class tvDimmingMode(Enum):
    tvDimmingMode_Fixed                   = 0              # Dimming Mode is Fixed
    tvDimmingMode_Local                   = auto()         # Dimming Mode is Local
    tvDimmingMode_Global                  = auto()         # Dimming Mode is Global

class LdimStateLevel(Enum):
    LDIM_STATE_NONBOOST                   = 0               # LDIM state level is non boost (AKA Normal)
    LDIM_STATE_BOOST                      = auto()          # LDIM state level is boost
    LDIM_STATE_BURST                      = auto()          # LDIM state level is burst
    LDIM_STATE_MAX                        = auto()          # End of enum

class tvDisplayMode(Enum):
    tvDisplayMode_4x3                     = 0               # Display mode is 4x3
    tvDisplayMode_16x9                    = auto()          # Display mode is 16x9
    tvDisplayMode_FULL                    = auto()          # Display mode is Full
    tvDisplayMode_NORMAL                  = auto()          # Display mode is Normal
    tvDisplayMode_AUTO                    = auto()          # Display mode is Auto
    tvDisplayMode_DIRECT                  = auto()          # Display mode is Direct
    tvDisplayMode_ZOOM                    = auto()          # Display mode is Zoom

class VideoFormat(Enum):
    VIDEO_FORMAT_NONE                     = 0               # No video format
    VIDEO_FORMAT_HDR10                    = auto()          # Video format is HDR10
    VIDEO_FORMAT_HDR10PLUS                = auto()          # Video format is HDR10 plus
    VIDEO_FORMAT_DV                       = auto()          # Video format is Dolby Vision
    VIDEO_FORMAT_PRIMESL                  = auto()          # Video format is PRIMESL
    VIDEO_FORMAT_HLG                      = auto()          # Video format is HLG
    VIDEO_FORMAT_SDR                      = auto()          # Video format is SDR
    VIDEO_FORMAT_MVC                      = auto()          # Video format is MVC

class tvBacklightTestMode(Enum):
    tvBacklightTestMode_Normal            = 0               # Backlight test mode is normal
    tvBacklightTestMode_Boost             = auto()          # Backlight test mode is boost
    tvBacklightTestMode_Burst             = auto()          # Backlight test mode is burst
    tvBacklightTestMode_Reset             = auto()          # Backlight test mode is reset

class tvVideoResolution(Enum):
    TV_VIDEO_RESOLUTION_NONE              = 0                  # No Resolution
    TV_VIDEO_RESOLUTION_720x240           = auto()             # Resolution is 720x240
    TV_VIDEO_RESOLUTION_2880x240          = auto()             # Resolution is 2880x240
    TV_VIDEO_RESOLUTION_720x288           = auto()             # Resolution is 720x288
    TV_VIDEO_RESOLUTION_2880x288          = auto()             # Resolution is 2880x288
    TV_VIDEO_RESOLUTION_640x480           = auto()             # Resolution is 640x480
    TV_VIDEO_RESOLUTION_720x480           = auto()             # Resolution is 720x480
    TV_VIDEO_RESOLUTION_800x480           = auto()             # Resolution is 800x480
    TV_VIDEO_RESOLUTION_852x480           = auto()             # Resolution is 852x480
    TV_VIDEO_RESOLUTION_854x480           = auto()             # Resolution is 854x480
    TV_VIDEO_RESOLUTION_1440x480          = auto()             # Resolution is 1440x480
    TV_VIDEO_RESOLUTION_2880x480          = auto()             # Resolution is 2880x480
    TV_VIDEO_RESOLUTION_960x540           = auto()             # Resolution is 960x540
    TV_VIDEO_RESOLUTION_3840x540          = auto()             # Resolution is 3840x540
    TV_VIDEO_RESOLUTION_720x576           = auto()             # Resolution is 720x576
    TV_VIDEO_RESOLUTION_1440x576          = auto()             # Resolution is 1440x576
    TV_VIDEO_RESOLUTION_2880x576          = auto()             # Resolution is 2880x576
    TV_VIDEO_RESOLUTION_800x600           = auto()             # Resolution is 800x600
    TV_VIDEO_RESOLUTION_1024x600          = auto()             # Resolution is 1024x600
    TV_VIDEO_RESOLUTION_1280x600          = auto()             # Resolution is 1280x600
    TV_VIDEO_RESOLUTION_1280x720          = auto()             # Resolution is 1280x720
    TV_VIDEO_RESOLUTION_1280x1024         = auto()             # Resolution is 1280x1024
    TV_VIDEO_RESOLUTION_1680x720          = auto()             # Resolution is 1680x720
    TV_VIDEO_RESOLUTION_1024x768          = auto()             # Resolution is 1024x768
    TV_VIDEO_RESOLUTION_1280x768          = auto()             # Resolution is 1280x768
    TV_VIDEO_RESOLUTION_1360x768          = auto()             # Resolution is 1360x768
    TV_VIDEO_RESOLUTION_1366x768          = auto()             # Resolution is 1366x768
    TV_VIDEO_RESOLUTION_1440x900          = auto()             # Resolution is 1440x900
    TV_VIDEO_RESOLUTION_1600x900          = auto()             # Resolution is 1600x900
    TV_VIDEO_RESOLUTION_1280x960          = auto()             # Resolution is 1280x960
    TV_VIDEO_RESOLUTION_1920x1080         = auto()             # Resolution is 1920x1080
    TV_VIDEO_RESOLUTION_2560x1080         = auto()             # Resolution is 2560x1080
    TV_VIDEO_RESOLUTION_3840x1080         = auto()             # Resolution is 3840x1080
    TV_VIDEO_RESOLUTION_1600x1200         = auto()             # Resolution is 1600x1200
    TV_VIDEO_RESOLUTION_1920x1200         = auto()             # Resolution is 1920x1200
    TV_VIDEO_RESOLUTION_2160x1200         = auto()             # Resolution is 2160x1200
    TV_VIDEO_RESOLUTION_2400x1200         = auto()             # Resolution is 2400x1200
    TV_VIDEO_RESOLUTION_2560x1440         = auto()             # Resolution is 2560x1440
    TV_VIDEO_RESOLUTION_3440x1440         = auto()             # Resolution is 3440x1440
    TV_VIDEO_RESOLUTION_3840x2160         = auto()             # Resolution is 3840x2160
    TV_VIDEO_RESOLUTION_4096x2160         = auto()             # Resolution is 4096x2160

class tvVideoFrameRate(Enum):
    tvVideoFrameRate_NONE                 = 0                  # No frame rate
    tvVideoFrameRate_24                   = auto()             # Frame rate is 24
    tvVideoFrameRate_25                   = auto()             # Frame rate is 25
    tvVideoFrameRate_30                   = auto()             # Frame rate is 30
    tvVideoFrameRate_50                   = auto()             # Frame rate is 50
    tvVideoFrameRate_60                   = auto()             # Frame rate is 60
    tvVideoFrameRate_23dot98              = auto()             # Frame rate is 23.98
    tvVideoFrameRate_29dot97              = auto()             # Frame rate is 29.97
    tvVideoFrameRate_59dot94              = auto()             # Frame rate is 59.94

class tvSettingsClass():

    moduleName = "tvSettings"
    menuConfig =  dir_path + "/tvSettings_test_suite.yml"
    testSuite = "L3 tvSettings"

    """
    tvSettings Class

    This module provides common extensions for tvSettings Module.
    """
    def __init__(self, deviceProfilePath:str, session=None, devicePath="/tmp" ):
        """
        Initializes the tvSettings class function.
        """
        self.deviceProfile = ConfigRead( deviceProfilePath, self.moduleName)
        self.suitConfig    = ConfigRead(self.menuConfig, self.moduleName)
        self.utMenu        = UTSuiteNavigatorClass(self.menuConfig, self.moduleName, session, devicePath)
        self.testSession   = session
        self.utMenu.start()
        self.formatChangeCB = self.suitConfig.get("test").get("callback").get("formatChange_status")
        self.contentChangeCB = self.suitConfig.get("test").get("callback").get("contentChange_status")
        self.resolutionChangeCB = self.suitConfig.get("test").get("callback").get("resolutionChange_status")
        self.frameRateChangeCB = self.suitConfig.get("test").get("callback").get("frameRateChange_status")

    def searchPattern(self, haystack, pattern):
        match = re.search(pattern, haystack)
        if match:
            return match.group(1)
        return None

    def initialise(self):
        """
        Initializes the tvSettings module.

        Args:
            None

        Returns:
            None
        """
        result = self.utMenu.select( self.testSuite, "Initialize")

    def checkVideoFormat(self):
        """
        Gets the current video format.

        Returns:
            None
        """
        # Use the same utMenu.select structure to interact
        result = self.utMenu.select(self.testSuite, "Get Video Format")
        videoFormatPattern = r"Result GetCurrentVideoFormat\(OUT:Video Format:\[(VIDEO_FORMAT_\w+)\]\)"
        videoFormat = self.searchPattern(result, videoFormatPattern)
        return videoFormat

    def checkVideoResolution(self):
        """
        Gets the current video resolution.

        Returns:
            None
        """
        # Use the same utMenu.select structure to interact
        result = self.utMenu.select(self.testSuite, "Get Resolution")
        videoResolutionPattern = r"Result GetCurrentVideoResolution\(OUT:Resolution:\[(0x[0-9A-F]+)\], OUT:isInterlaced:\[(\d+)\], OUT:res value:\[(tvVideoResolution_\w+)\]\)"
        videoResolution = self.searchPattern(result, videoResolutionPattern)
        return videoResolution

    def checkVideoFrameRate(self):
        """
        Gets the current video format.

        Returns:
            None
        """
        # Use the same utMenu.select structure to interact
        result = self.utMenu.select(self.testSuite, "Get Video FrameRate")
        videoFrameRatePattern = r"Result GetCurrentVideoFrameRate\(OUT:Frame Rate:\[(tvVideoFrameRate_\w+)\]\)"
        videoFrameRate = self.searchPattern(result, videoFrameRatePattern)
        return videoFrameRate

    def checkVideoSource(self):
        """
        Gets the current video format.

        Returns:
            None
        """
        # Use the same utMenu.select structure to interact
        result = self.utMenu.select(self.testSuite, "Get Video Source")
        videoSourcePattern = r"Result GetCurrentVideoSource\(OUT:Current Source:\[(VIDEO_SOURCE_\w+)\]\)"
        videoSource = self.searchPattern(result, videoSourcePattern)
        return videoSource

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

        result = self.utMenu.select(self.testSuite, "Back light", promptWithAnswers)

    def setBacklightFade(self, fromVal:int=0, toVal:int=0, fadeDuration:int=0):
        """
        Sets backlight Fade.

        Args:
            fromVal (int, optional): The starting backlight value (0 to 100). Defaults to 0.
            toVal (int, optional): The ending backlight value (0 to 100). Defaults to 0.
            fadeDuration (int, optional): The duration of the fade effect in milliseconds (0 to 1000). Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "direct",
                    "query": "Enter the 'from' backlight value (0-100):",
                    "input": str(fromVal)
                },
                {
                    "query_type": "direct",
                    "query": "Enter the 'to' backlight value (0-100):",
                    "input": str(toVal)
                },
                {
                    "query_type": "direct",
                    "query": "Enter the fade duration (0-1000 ms):",
                    "input": str(fadeDuration)
                }
        ]

        result = self.utMenu.select(self.testSuite, "Back light Fade", promptWithAnswers)

    def setBacklightMode(self, BacklightMode:int=0):
        """
        Sets backlightMode.

        Args:
            backlight mode (int, optional): backlight Mode to be applied.

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "list",
                    "query": "Enter the number corresponding to the Backlight Mode:",
                    "input": str(BacklightMode)
                }
        ]

        result = self.utMenu.select(self.testSuite, "Back light Mode", promptWithAnswers)

    def setTVDimmingMode(self, TVDimmingMode:int=0):
        """
        Sets TvDimmingMode.

        Args:
            TvDimmingMode (int, optional): TvDimmingMode Mode to be applied.

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "direct",
                    "query": "Enter the number corresponding to the Dimming Mode:",
                    "input": str(TVDimmingMode)
                }
        ]

        result = self.utMenu.select(self.testSuite, "TV Dimming Mode", promptWithAnswers)

    def setLocalDimmingMode(self, LocalDimmingMode:int=0):
        """
        Sets Local DImmingMode.

        Args:
            Local DimmingMode (int, optional): Local Dimming Mode to be applied.

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "direct",
                    "query": "Enter the number corresponding to the desired Local Dimming Level:",
                    "input": str(LocalDimmingMode)
                }
        ]

        result = self.utMenu.select(self.testSuite, "Local Dimming Mode", promptWithAnswers)


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

        result = self.utMenu.select(self.testSuite, "Brightness", promptWithAnswers)

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

        result = self.utMenu.select(self.testSuite, "Contrast", promptWithAnswers)

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

        result = self.utMenu.select(self.testSuite, "Sharpness", promptWithAnswers)

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

        result = self.utMenu.select(self.testSuite, "Saturation", promptWithAnswers)

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

        result = self.utMenu.select(self.testSuite, "Hue", promptWithAnswers)

    def setColorTempLevel(self, ColorTempLevel: str="tvColorTemp_STANDARD"):
        """
        Sets ColorTempLevel level.

        Args:
             ColorTempLevelLevel (str, optional): ColorTempLevel level to be applied.

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "list",
                    "query": "Enter the desired color temperature value:",
                     "input": ColorTempLevel
                }
        ]

        result = self.utMenu.select(self.testSuite, "ColorTemperature", promptWithAnswers)

    def setAspectRatio(self, AspectRatio: str="tvDisplayMode_4x3"):
        """
        Sets AspectRatio level.

        Args:
             AspectRatioLevel (str, optional): AspectRatio level to be applied.

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "list",
                    "query": "Enter the number corresponding to the Aspect Ratio:",
                     "input": AspectRatio
                }
        ]

        result = self.utMenu.select(self.testSuite, "Aspect Ratio", promptWithAnswers)

    def setLowLatencyState(self, LowLatency: bool=0):
        """
        Sets Low latency state.

        Args:
             Low Latency state (int, optional): low latency to be applied.

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "direct",
                    "query": "Enter 0 to Disable or 1 to Enable Low Latency:",
                     "input": str(LowLatency)
                }
        ]

        result = self.utMenu.select(self.testSuite, "Low Latency State", promptWithAnswers)

    def setDynamicContrast(self, DynamicContrast: str="disabled"):
        """
        Sets Dynamic Contrast.

        Args:
             Dynamic Contrast (str, optional): Dynamic Contrast to be applied.

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "direct",
                    "query": "Enter 'enabled' to Enable or 'disabled' to Disable Dynamic Contrast:",
                     "input": str(DynamicContrast)
                }
        ]

        result = self.utMenu.select(self.testSuite, "Dynamic Contrast", promptWithAnswers)

    def setDynamicGamma(self, DynamicGamma: float=0.0):
        """
        Sets Dynamic Gamma.

        Args:
             Dynamic Gamma (flaot, optional): Dynamic Gamma to be applied.

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "direct",
                    "query": "Enter a dynamic gamma value (1.80 to 2.60):",
                     "input": str(DynamicGamma)
                }
        ]

        result = self.utMenu.select(self.testSuite, "Dynamic Gamma", promptWithAnswers)

    def setDolbyVision(self, DolbyVision: str="tvDolbyMode_Dark"):
        """
        Sets DolbyVision.

        Args:
             DolbyVision (int, optional): Dolby vision to be applied.

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "list",
                    "query": "Enter the number corresponding to the Dolby Vision Mode:",
                     "input": DolbyVision
                }
        ]

        result = self.utMenu.select(self.testSuite, "Dolby Vision", promptWithAnswers)

    def setPictureMode(self, PictureMode: str="PQ_MODE_STANDARD"):
        """
        Sets Picture mode.

        Args:
             PictureMode (int, optional): Picture Mode to be applied.

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "list",
                    "query": "Enter the number corresponding to the Picture Mode:",
                     "input": PictureMode
                }
        ]

        result = self.utMenu.select(self.testSuite, "Picture Mode", promptWithAnswers)

    def setRgainValue(self, ColorTemp: str="tvColorTemp_STANDARD", RgainValue:int=0, SetOrSave:int=0):
        """
        Sets ColorTempRgain.

        Args:
             ColorTemp (str, optional): ColorTempRgain to be applied.
             RgainValue (int, optional): RgainValue to be applied.
             SetOrSave (int, optional): SetOrSave to be applied.

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "list",
                    "query": "Enter the number corresponding to the Color Temperature:",
                     "input": ColorTemp
                },
                {
                    "query_type": "direct",
                    "query": "Enter the Rgain Value (0 - 2047):",
                     "input": str(RgainValue)
                },
                {
                    "query_type": "direct",
                    "query": "Enter the Flag Selection:",
                     "input": str(SetOrSave)
                }
        ]

        result = self.utMenu.select(self.testSuite, "ColorTempRgain", promptWithAnswers)

    def setGgainValue(self, ColorTemp: str="tvColorTemp_STANDARD", GgainValue:int=0, SetOrSave:int=0):
        """
        Sets ColorTempGgain.

        Args:
             ColorTemp (str, optional): ColorTempGgain to be applied.
             RgainValue (int, optional): GgainValue to be applied.
             SetOrSave (int, optional): SetOrSave to be applied.

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "list",
                    "query": "Enter the number corresponding to the Color Temperature:",
                     "input": ColorTemp
                },
                {
                    "query_type": "direct",
                    "query": "Enter the Ggain Value (0 - 2047):",
                     "input": str(GgainValue)
                },
                {
                    "query_type": "direct",
                    "query": "Enter the Flag Selection:",
                     "input": str(SetOrSave)
                }
        ]

        result = self.utMenu.select(self.testSuite, "ColorTempGgain", promptWithAnswers)

    def setBgainValue(self, ColorTemp: str="tvColorTemp_STANDARD", BgainValue:int=0, SetOrSave:int=0):
        """
        Sets ColorTempBgain.

        Args:
             ColorTemp (str, optional): ColorTempBgain to be applied.
             BgainValue (int, optional): BgainValue to be applied.
             SetOrSave (int, optional): SetOrSave to be applied.

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "list",
                    "query": "Enter the number corresponding to the Color Temperature:",
                     "input": ColorTemp
                },
                {
                    "query_type": "direct",
                    "query": "Enter the Bgain Value (0 - 2047):",
                     "input": str(BgainValue)
                },
                {
                    "query_type": "direct",
                    "query": "Enter the Flag Selection:",
                     "input": str(SetOrSave)
                }
        ]

        result = self.utMenu.select(self.testSuite, "ColorTempRgain", promptWithAnswers)

    def setRpostOffsetValue(self, ColorTemp: str="tvColorTemp_STANDARD", RpostOffsetValue:int=0, SetOrSave:int=0):
        """
        Sets RpostOffsetValue.

        Args:
             ColorTemp (str, optional): ColorTemp to be applied.
             RpostOffsetValue (int, optional): RpostOffsetValue to be applied.
             SetOrSave (int, optional): SetOrSave to be applied.

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "list",
                    "query": "Enter the number corresponding to the Color Temperature:",
                     "input": ColorTemp
                },
                {
                    "query_type": "direct",
                    "query": "Enter the Rpostoffset Value (-1024 to 1023):",
                     "input": str(RpostOffsetValue)
                },
                {
                    "query_type": "direct",
                    "query": "Enter the Flag Selection:",
                     "input": str(SetOrSave)
                }
        ]

        result = self.utMenu.select(self.testSuite, "ColorTempRpost", promptWithAnswers)

    def setGpostOffsetValue(self, ColorTemp: str="tvColorTemp_STANDARD", GpostOffsetValue:int=0, SetOrSave:int=0):
        """
        Sets GpostOffsetValue.

        Args:
             ColorTemp (str, optional): ColorTemp to be applied.
             GpostOffsetValue (int, optional): GpostOffsetValue to be applied.
             SetOrSave (int, optional): SetOrSave to be applied.

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "list",
                    "query": "Enter the number corresponding to the Color Temperature:",
                     "input": ColorTemp
                },
                {
                    "query_type": "direct",
                    "query": "Enter the Gpostoffset Value (-1024 to 1023):",
                     "input": str(GpostOffsetValue)
                },
                {
                    "query_type": "direct",
                    "query": "Enter the Flag Selection:",
                     "input": str(SetOrSave)
                }
        ]

        result = self.utMenu.select(self.testSuite, "ColorTempGpost", promptWithAnswers)

    def setBpostOffsetValue(self, ColorTemp: str="tvColorTemp_STANDARD", BpostOffsetValue:int=0, SetOrSave:int=0):
        """
        Sets BpostOffsetValue.

        Args:
             ColorTemp (str, optional): ColorTemp to be applied.
             BpostOffsetValue (int, optional): BpostOffsetValue to be applied.
             SetOrSave (int, optional): SetOrSave to be applied.

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "list",
                    "query": "Enter the number corresponding to the Color Temperature:",
                     "input": ColorTemp
                },
                {
                    "query_type": "direct",
                    "query": "Enter the Bpostoffset Value (-1024 to 1023):",
                     "input": str(BpostOffsetValue)
                },
                {
                    "query_type": "direct",
                    "query": "Enter the Flag Selection:",
                     "input": str(SetOrSave)
                }
        ]

        result = self.utMenu.select(self.testSuite, "ColorTempBpost", promptWithAnswers)

    def setWBCalibration(self, WBcalibrationFlag: bool=0):
        """
        Sets WB calibration.

        Args:
             WB calibationFlag (bool, optional): WB calibration to be applied.

        Returns:
            None
        """
        promptWithAnswers = [
                {
                    "query_type": "direct",
                    "query": "Enter 1 to Enable WB Calibration Mode, 0 to Disable:",
                     "input": str(WBcalibrationFlag)
                }
        ]

        result = self.utMenu.select(self.testSuite, "WBCalibrationMode", promptWithAnswers)

    def setGammaTable(self, gammaTableSize: int = 1, gammaRed: int = 0, gammaGreen: int = 0, gammaBlue: int = 0):
        """
        Sets Gamma Table values.

        Args:
            gammaTableSize (int, optional): Size of the gamma table. Ranges from 1 to 255. Defaults to 1.
            gammaRed (int, optional): Gamma value for Red. Ranges from 0 to 1023. Defaults to 0.
            gammaGreen (int, optional): Gamma value for Green. Ranges from 0 to 1023. Defaults to 0.
            gammaBlue (int, optional): Gamma value for Blue. Ranges from 0 to 1023. Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "direct",
                "query": "Enter the size of the gamma table (1 - 255):",
                "input": str(gammaTableSize)
            },
            {
                "query_type": "direct",
                "query": f"Enter {gammaTableSize} gamma values for Red (0 - 1023):",
                "input": str(gammaRed)
            },
            {
                "query_type": "direct",
                "query": f"Enter {gammaTableSize} gamma values for Green (0 - 1023):",
                "input": str(gammaGreen)
            },
            {
                "query_type": "direct",
                "query": f"Enter {gammaTableSize} gamma values for Blue (0 - 1023):",
                "input": str(gammaBlue)
            }
        ]

        result = self.utMenu.select(self.testSuite, "Gamma Table", promptWithAnswers)

    def saveGammaTable(self, gammaTableSize: int = 1, gammaRed: list = None, gammaGreen: list = None, gammaBlue: list = None, colorTemperature: str = "tvColorTemp_STANDARD"):
        """
        Saves Gamma Table values and applies a specified color temperature.

        Args:
            gammaTableSize (int, optional): Size of the gamma table. Ranges from 1 to 255. Defaults to 1.
            gammaRed (list, optional): List of gamma values for Red. Each value ranges from 0 to 1023. Defaults to None.
            gammaGreen (list, optional): List of gamma values for Green. Each value ranges from 0 to 1023. Defaults to None.
            gammaBlue (list, optional): List of gamma values for Blue. Each value ranges from 0 to 1023. Defaults to None.
            colorTemperature (str, optional): The desired color temperature setting. Defaults to "Neutral White".

        Returns:
            None
        """
        if gammaRed is None:
            gammaRed = [0] * gammaTableSize
        if gammaGreen is None:
            gammaGreen = [0] * gammaTableSize
        if gammaBlue is None:
            gammaBlue = [0] * gammaTableSize

        # Prompt user for gamma table size
        promptWithAnswers = [
            {
                "query_type": "direct",
                "query": "Enter the size of the gamma table (1 - 255):",
                "input": str(gammaTableSize)
            },
            {
                "query_type": "list",
                "query": "Enter the number corresponding to the Color Temperature:",
                "input": colorTemperature
            },
            {
                "query_type": "direct",
                "query": f"Enter {gammaTableSize} gamma values for Red (0 - 1023):",
                "input": " ".join(map(str, gammaRed))
            },
            {
                "query_type": "direct",
                "query": f"Enter {gammaTableSize} gamma values for Green (0 - 1023):",
                "input": " ".join(map(str, gammaGreen))
            },
            {
                "query_type": "direct",
                "query": f"Enter {gammaTableSize} gamma values for Blue (0 - 1023):",
                "input": " ".join(map(str, gammaBlue))
            }
        ]

        # Display prompts and collect user inputs
        result = self.utMenu.select(self.testSuite, "Save Gamma Table", promptWithAnswers)

    def setComponentSaturation(self, colorIndex: str = "tvDataColor_RED", saturationValue: int = 0):
        """
        Sets Component Saturation values.

        Args:
            colorIndex (int, optional): Component color index to be applied. Defaults to 0.
            saturationValue (int, optional): Saturation value to be applied. Ranges from 0 to 100. Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter the component color index:",
                "input": colorIndex
            },
            {
                "query_type": "direct",
                "query": "Enter the saturation value (0 - 100):",
                "input": str(saturationValue)
            }
        ]

        result = self.utMenu.select(self.testSuite, "CompSaturation", promptWithAnswers)

    def setComponentHue(self, colorIndex: str = "tvDataColor_RED", hueValue: int = 0):
        """
        Sets Component Hue values.

        Args:
            colorIndex (int, optional): Component color index to be applied. Defaults to 0.
            hueValue (int, optional): Hue value to be applied. Ranges from 0 to 100. Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter the component color index:",
                "input": colorIndex
            },
            {
                "query_type": "direct",
                "query": "Enter the hue value (0 - 100):",
                "input": str(hueValue)
            }
        ]

        result = self.utMenu.select(self.testSuite, "CompHue", promptWithAnswers)

    def setComponentLuma(self, colorIndex: str = "tvDataColor_RED", lumaValue: int = 0):
        """
        Sets Component Luma values.

        Args:
            colorIndex (int, optional): Component color index to be applied. Defaults to 0.
            lumaValue (int, optional): Luma value to be applied. Ranges from 0 to 30. Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter the component color index:",
                "input": colorIndex
            },
            {
                "query_type": "direct",
                "query": "Enter the luma value (0 - 30):",
                "input": str(lumaValue)
            }
        ]

        result = self.utMenu.select(self.testSuite, "CompLuma", promptWithAnswers)


    def setDvTmaxValue(self, dvTmaxValue: int = 0):
        """
        Sets Dolby Vision TMAX value.

        Args:
            dvTmaxValue (int, optional): Dolby Vision TMAX value to be applied. Ranges from 0 to 10000. Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "direct",
                "query": "Enter the Dolby Vision TMAX value (0 - 10000):",
                "input": str(dvTmaxValue)
            }
        ]

        result = self.utMenu.select(self.testSuite, "DvTmaxValue", promptWithAnswers)

    def setCMSState(self, cmsState: bool = 0):
        """
        Sets CMS state.

        Args:
            cmsState (bool, optional): CMS state to be applied. Defaults to 0 (Disable), 1 (Enable).

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "direct",
                "query": "Enter CMS state to set (1 for Enable, 0 for Disable):",
                "input": str(cmsState)
            }
        ]

        result = self.utMenu.select(self.testSuite, "CMSState", promptWithAnswers)

    def setEnableGammaMode(self, enableGammaMode: bool = 0):
        """
        Sets Gamma mode.

        Args:
            enableGammaMode (bool, optional): Gamma mode to be applied. Defaults to 0 (Disable), 1 (Enable).

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "direct",
                "query": "Enter mode (0 to disable, 1 to enable):",
                "input": str(enableGammaMode)
            }
        ]

        result = self.utMenu.select(self.testSuite, "EnableGammaMode", promptWithAnswers)

    def setGammaPatternMode(self, gammaPatternMode: bool = 0):
        """
        Sets Gamma pattern mode.

        Args:
            gammaPatternMode (bool, optional): Gamma pattern mode to be applied. Defaults to 0 (Disable), 1 (Enable).

        Returns:
            None
        """
        promptWithAnswers = [
        {
            "query_type": "direct",
            "query": "Enter mode (0 to disable, 1 to enable):",
            "input": str(gammaPatternMode)
        }
    ]

        result = self.utMenu.select(self.testSuite, "GammaPatternMode", promptWithAnswers)

    def setGammaPattern(self, bitResolution: int = 0, redLevel: int = 0, greenLevel: int = 0, blueLevel: int = 0):
        """
        Sets Gamma Pattern.

        Args:
            bitResolution (int, optional): Bit resolution (0 for 10-bit, 1 for 8-bit). Defaults to 0.
            redLevel (int, optional): Red level (0 - 1023 for 10-bit, 0 - 255 for 8-bit). Defaults to 0.
            greenLevel (int, optional): Green level (0 - 1023 for 10-bit, 0 - 255 for 8-bit). Defaults to 0.
            blueLevel (int, optional): Blue level (0 - 1023 for 10-bit, 0 - 255 for 8-bit). Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "direct",
                "query": "Enter bit resolution (0 for 10-bit, 1 for 8-bit):",
                "input": str(bitResolution)
            },
            {
                "query_type": "direct",
                "query": "Enter Red level (0 - 1023 for 10-bit, 0 - 255 for 8-bit):",
                "input": str(redLevel)
            },
            {
                "query_type": "direct",
                "query": "Enter Green level (0 - 1023 for 10-bit, 0 - 255 for 8-bit):",
                "input": str(greenLevel)
            },
            {
                "query_type": "direct",
                "query": "Enter Blue level (0 - 1023 for 10-bit, 0 - 255 for 8-bit):",
                "input": str(blueLevel)
            }
        ]

        result = self.utMenu.select(self.testSuite, "SetGammaPattern", promptWithAnswers)

    def setRGBPattern(self, redLevel: int = 0, greenLevel: int = 0, blueLevel: int = 0):
        """
        Sets RGB Pattern.

        Args:
            redLevel (int, optional): Red level (0 - 255). Defaults to 0.
            greenLevel (int, optional): Green level (0 - 255). Defaults to 0.
            blueLevel (int, optional): Blue level (0 - 255). Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "direct",
                "query": "Enter Red level (0 - 255):",
                "input": str(redLevel)
            },
            {
                "query_type": "direct",
                "query": "Enter Green level (0 - 255):",
                "input": str(greenLevel)
            },
            {
                "query_type": "direct",
                "query": "Enter Blue level (0 - 255):",
                "input": str(blueLevel)
            }
        ]

        result = self.utMenu.select(self.testSuite, "RGBPattern", promptWithAnswers)


    def setGrayPattern(self, grayPattern: int = 0):
        """
        Sets Gray level pattern.

        Args:
            grayPattern (int, optional): Gray level to be applied. Ranges from 0 to 255. Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "direct",
                "query": "Enter Gray level (0 - 255):",
                "input": str(grayPattern)
            }
    ]

        result = self.utMenu.select(self.testSuite, "GrayPattern", promptWithAnswers)


    def setEnableLDIMPixelCompensation(self, mode: int = 0):
        """
        Sets LDIM Pixel Compensation mode.

        Args:
            mode (int, optional): Mode for pixel compensation (1 to enable, 0 to disable). Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "direct",
                "query": "Enter mode for pixel compensation (1 to enable, 0 to disable):",
                "input": str(mode)
            }
        ]

        result = self.utMenu.select(self.testSuite, "EnableLDIMPixel", promptWithAnswers)

    def setEnableLDIM(self, mode: int = 0):
        """
        Sets LDIM (Local Dimming) mode.

        Args:
            mode (int, optional): Mode for local dimming (1 to enable, 0 to disable). Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "direct",
                "query": "Enter mode for local dimming (1 to enable, 0 to disable):",
                "input": str(mode)
            }
        ]

        result = self.utMenu.select(self.testSuite, "EnableLDIM", promptWithAnswers)

    def setBacklightTestMode(self, mode: str = "tvBacklightTestMode_Normal"):
        """
        Sets backlight test mode.

        Args:
            mode (int, optional): Backlight test mode to be applied. Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter backlight test mode:",
                "input": mode
            }
        ]

        result = self.utMenu.select(self.testSuite, "SetBacklightTestMode", promptWithAnswers)

    def EnableDynamicContrast(self, mode: int = 0):
        """
        Enable dynamic contrast mode.

        Args:
            mode (int, optional): Dynamic contrast mode to be applied. Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "direct",
                "query": "Enter mode for dynamic contrast (1 to enable, 0 to disable):",
                "input": str(mode)
            }
        ]

        result = self.utMenu.select(self.testSuite, "EnableDynamicContrast", promptWithAnswers)

    def setEnableLocalContrast(self, mode: int = 0):
        """
        Sets local contrast mode.

        Args:
            mode (int, optional): Local contrast mode to be applied. Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "direct",
                "query": "Enter mode for local contrast (1 to enable, 0 to disable):",
                "input": str(mode)
            }
        ]

        result = self.utMenu.select(self.testSuite, "EnableLocalContrast", promptWithAnswers)

    def saveBacklightValues(self, pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD", backlightValue: int = 0):
        """
        Saves backlight values.

        Args:
            pictureModeIndex (int, optional): Your choice of Picture Mode index. Defaults to 0.
            videoFormatIndex (int, optional): Your choice of Video Format index. Defaults to 0.
            backlightValue (int, optional): Backlight value to set (0 - 100). Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Picture Mode (index):",
                "input": pictureModeIndex
            },
            {
                "query_type": "list",
                "query": "Enter your choice of Video Format (index):",
                "input": videoFormatIndex
            },
            {
                "query_type": "direct",
                "query": "Enter the backlight value to set (0 - 100):",
                "input": str(backlightValue)
            }
        ]

        result = self.utMenu.select(self.testSuite, "Save Backlight values", promptWithAnswers)


    def saveTVDimmingModeValues(self, pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD", dimmingModeIndex: str = "tvDimmingMode_Fixed"):
        """
        Saves TV Dimming Mode values.

        Args:
            pictureModeIndex (int, optional): Your choice of Picture Mode index. Defaults to 0.
            videoFormatIndex (int, optional): Your choice of Video Format index. Defaults to 0.
            dimmingModeIndex (int, optional): Your choice of Dimming Mode index. Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Picture Mode (index):",
                "input": pictureModeIndex
            },
            {
                "query_type": "list",
                "query": "Enter your choice of Video Format (index):",
                "input": videoFormatIndex
            },
            {
                "query_type": "list",
                "query": "Enter your choice of Dimming Mode (index from above):",
                "input": dimmingModeIndex
            }
        ]

        result = self.utMenu.select(self.testSuite, "Save TV Dimming Mode values", promptWithAnswers)


    def saveLocalDimmingModeValues(self, pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD",  DimmingLevelIndex: str = "LDIM_STATE_NONBOOST"):
        """
        Saves Local Dimming Mode values.

        Args:
            pictureModeIndex (int, optional): Your choice of Picture Mode index. Defaults to 0.
            videoFormatIndex (int, optional): Your choice of Video Format index. Defaults to 0.
            localDimmingLevelIndex (int, optional): Your choice of Local Dimming Level index. Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Picture Mode (index):",
                "input": pictureModeIndex
            },
            {
                "query_type": "list",
                "query": "Enter your choice of Video Format (index):",
                "input": videoFormatIndex
            },
            {
                "query_type": "list",
                "query": "Enter your choice of Local Dimming Level (index):",
                "input": DimmingLevelIndex
            }
        ]

        result = self.utMenu.select(self.testSuite, "Save Local Dimming Mode values", promptWithAnswers)


    def saveBrightnessValues(self, pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD", brightnessValue: int = 0):
        """
        Saves brightness values.

        Args:
            pictureModeIndex (int, optional): Your choice of Picture Mode index. Defaults to 0.
            videoFormatIndex (int, optional): Your choice of Video Format index. Defaults to 0.
            brightnessValue (int, optional): Brightness value to set (0 - 100). Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Picture Mode (index):",
                "input": pictureModeIndex
            },
            {
                "query_type": "list",
                "query": "Enter your choice of Video Format (index):",
                "input": videoFormatIndex
            },
            {
                "query_type": "direct",
                "query": "Enter the brightness value to set (0 - 100):",
                "input": str(brightnessValue)
            }
        ]

        result = self.utMenu.select(self.testSuite, "Save Brightness values", promptWithAnswers)


    def saveContrastValues(self, pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD", contrastValue: int = 0):
        """
        Saves contrast values.

        Args:
            pictureModeIndex (int, optional): Your choice of Picture Mode index. Defaults to 0.
            videoFormatIndex (int, optional): Your choice of Video Format index. Defaults to 0.
            contrastValue (int, optional): Contrast value to set (0 - 100). Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Picture Mode (index):",
                "input": pictureModeIndex
            },
            {
                "query_type": "direct",
                "query": "Enter your choice of Video Format (index):",
                "input": videoFormatIndex
            },
            {
                "query_type": "direct",
                "query": "Enter the contrast value to set (0 - 100):",
                "input": str(contrastValue)
            }
        ]

        result = self.utMenu.select(self.testSuite, "Save Contrast values", promptWithAnswers)


    def saveSharpnessValues(self, pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD", sharpnessValue: int = 0):
        """
        Saves sharpness values.

        Args:
            pictureModeIndex (int, optional): Your choice of Picture Mode index. Defaults to 0.
            videoFormatIndex (int, optional): Your choice of Video Format index. Defaults to 0.
            sharpnessValue (int, optional): Sharpness value to set (0 - 100). Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Picture Mode (index):",
                "input": pictureModeIndex
            },
            {
                "query_type": "list",
                "query": "Enter your choice of Video Format (index):",
                "input": videoFormatIndex
            },
            {
                "query_type": "direct",
                "query": "Enter the sharpness value to set (0 - 100):",
                "input": str(sharpnessValue)
            }
        ]

        result = self.utMenu.select(self.testSuite, "Save Sharpness values", promptWithAnswers)


    def saveSaturationValues(self, pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD", saturationValue: int = 0):
        """
        Saves saturation values.

        Args:
            pictureModeIndex (int, optional): Your choice of Picture Mode index. Defaults to 0.
            videoFormatIndex (int, optional): Your choice of Video Format index. Defaults to 0.
            saturationValue (int, optional): Saturation value to set (0 - 100). Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Picture Mode (index):",
                "input": pictureModeIndex
            },
            {
                "query_type": "list",
                "query": "Enter your choice of Video Format (index):",
                "input": videoFormatIndex
            },
            {
                "query_type": "direct",
                "query": "Enter the saturation value to set (0 - 100):",
                "input": str(saturationValue)
            }
        ]

        result = self.utMenu.select(self.testSuite, "Save Saturation values", promptWithAnswers)


    def saveHueValues(self, pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD", hueValue: int = 0):
        """
        Saves hue values.

        Args:
            pictureModeIndex (int, optional): Your choice of Picture Mode index. Defaults to 0.
            videoFormatIndex (int, optional): Your choice of Video Format index. Defaults to 0.
            hueValue (int, optional): Hue value to set (0 - 100). Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Picture Mode (index):",
                "input": pictureModeIndex
            },
            {
                "query_type": "list",
                "query": "Enter your choice of Video Format (index):",
                "input": videoFormatIndex
            },
            {
                "query_type": "direct",
                "query": "Enter the hue value to set (0 - 100):",
                "input": str(hueValue)
            }
        ]

        result = self.utMenu.select(self.testSuite, "Save Hue values", promptWithAnswers)


    def saveColorTemperatureValues(self, pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD", colorTemperatureIndex: str = "tvColorTemp_STANDARD"):
        """
        Saves color temperature values.

        Args:
            pictureModeIndex (int, optional): Your choice of Picture Mode index. Defaults to 0.
            videoFormatIndex (int, optional): Your choice of Video Format index. Defaults to 0.
            colorTemperatureIndex (int, optional): Number corresponding to the Color Temperature. Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Picture Mode (index):",
                "input": pictureModeIndex
            },
            {
                "query_type": "list",
                "query": "Enter your choice of Video Format (index):",
                "input": videoFormatIndex
            },
            {
                "query_type": "list",
                "query": "Enter the number corresponding to the Color Temperature:",
                "input": colorTemperatureIndex
            }
        ]

        result = self.utMenu.select(self.testSuite, "Save Color Temperature values", promptWithAnswers)


    def saveAspectRatioValues(self, pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD", aspectRatioIndex: str = "tvDisplayMode_4x3"):
        """
        Saves aspect ratio values.

        Args:
            pictureModeIndex (int, optional): Your choice of Picture Mode index. Defaults to 0.
            videoFormatIndex (int, optional): Your choice of Video Format index. Defaults to 0.
            aspectRatioIndex (int, optional): Number corresponding to the Aspect Ratio. Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Picture Mode (index):",
                "input": pictureModeIndex
            },
            {
                "query_type": "list",
                "query": "Enter your choice of Video Format (index):",
                "input": videoFormatIndex
            },
            {
                "query_type": "list",
                "query": "Enter the number corresponding to the Aspect Ratio:",
                "input": aspectRatioIndex
            }
        ]

        result = self.utMenu.select(self.testSuite, "Save Aspect Ratio values", promptWithAnswers)


    def saveLowLatencyValues(self, pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD", lowLatencyIndex: int = 0):
        """
        Saves low latency values.

        Args:
            pictureModeIndex (int, optional): Your choice of Picture Mode index. Defaults to 0.
            videoFormatIndex (int, optional): Your choice of Video Format index. Defaults to 0.
            lowLatencyIndex (int, optional): Low Latency Index (0 or 1). Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Picture Mode (index):",
                "input": pictureModeIndex
            },
            {
                "query_type": "list",
                "query": "Enter your choice of Video Format (index):",
                "input": videoFormatIndex
            },
            {
                "query_type": "direct",
                "query": "Enter the Low Latency Index (0 or 1):",
                "input": str(lowLatencyIndex)
            }
        ]

        result = self.utMenu.select(self.testSuite, "Save Low Latency values", promptWithAnswers)


    def saveDolbyVisionValues(self, pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD", dolbyVisionModeIndex: str = "tvDolbyMode_Dark"):
        """
        Saves Dolby Vision values.

        Args:
            pictureModeIndex (int, optional): Your choice of Picture Mode index. Defaults to 0.
            videoFormatIndex (int, optional): Your choice of Video Format index. Defaults to 0.
            dolbyVisionModeIndex (int, optional): Number corresponding to the Dolby Vision Mode. Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Picture Mode (index):",
                "input": pictureModeIndex
            },
            {
                "query_type": "list",
                "query": "Enter your choice of Video Format (index):",
                "input": videoFormatIndex
            },
            {
                "query_type": "list",
                "query": "Enter the number corresponding to the Dolby Vision Mode:",
                "input": dolbyVisionModeIndex
            }
        ]

        result = self.utMenu.select(self.testSuite, "Save Dolby vision", promptWithAnswers)

    def savePictureMode(self, pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD",):
        """
        Saves the Picture Mode.

        Args:
            videoFormatIndex (int, optional): Your choice of Video Format index. Defaults to 0.
            pictureModeIndex (int, optional): Number corresponding to the Picture Mode. Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Video Format (index):",
                "input": videoFormatIndex
            },
            {
                "query_type": "list",
                "query": "Enter the number corresponding to the Picture Mode:",
                "input": pictureModeIndex
            }
        ]

        result = self.utMenu.select(self.testSuite, "Save Picture Mode", promptWithAnswers)


    def getBacklightMode(self):
        """
        Gets the Backlight Mode.

        Args:
            None.

        Returns:
                bool : BacklightModes
        """
        # Get the Back light Mode index from the profile
        BacklightModes = self.deviceProfile.get("BacklightControl").get("index")

        # Check if index is valid
        if BacklightModes is None:
            return []

        outBacklightMode = []
        for BacklightMode in BacklightModes:
            outBacklightMode.append(tvBacklightMode(BacklightMode).name)
        return outBacklightMode

    def saveCMS(self, pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD", componentType: str = "COMP_NONE", componentColor: str = "tvDataColor_RED", cmsValue: int = 0):
        """
        Saves the CMS settings.

        Args:
            pictureModeIndex (int, optional): Your choice of Picture Mode index. Defaults to 0.
            videoFormatIndex (int, optional): Your choice of Video Format index. Defaults to 0.
            componentType (int, optional): Number corresponding to the Component Type. Defaults to 0.
            componentColor (int, optional): The component color. Defaults to 0.
            cmsValue (int, optional): The CMS value (0 - 100). Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Picture Mode (index):",
                "input": pictureModeIndex
            },
            {
                "query_type": "list",
                "query": "Enter your choice of Video Format (index):",
                "input": videoFormatIndex
            },
            {
                "query_type": "list",
                "query": "Enter the number corresponding to the Component Type:",
                "input": componentType
            },
            {
                "query_type": "list",
                "query": "Enter the component color:",
                "input": componentColor
            },
            {
                "query_type": "direct",
                "query": "Enter the CMS value (0 - 100):",
                "input": str(cmsValue)
            }
        ]

        result = self.utMenu.select(self.testSuite, "Save CMS", promptWithAnswers)

    def getTVDimmingMode(self):
        """
        Gets the TV Dimming Modes.

        Args:
            None.

        Returns:
            bool : Dimming Modes
        """
        # Get the Back light Mode index from the profile
        TVDimmingModes = self.deviceProfile.get("DimmingMode").get("index")

        # Check if index is valid
        if TVDimmingModes is None:
            return []

        outTVDimmingMode = []
        for TVDimmingMode in TVDimmingModes:
            outTVDimmingMode.append(tvDimmingMode(TVDimmingMode).name)
        return outTVDimmingMode

    def getLocalDimmingMode(self):
        """
        Gets the Local Dimming Modes.

        Args:
            None.

        Returns:
            bool : Local Dimming Modes
        """
        # Get the Back light Mode index from the profile
        LocalDimmingModes = self.deviceProfile.get("LocalDimmingLevel").get("index")

        # Check if index is valid
        if LocalDimmingModes is None:
            return []

        outLocalDimmingMode = []
        for LocalDimmingMode in LocalDimmingModes:
            outLocalDimmingMode.append(LdimStateLevel(LocalDimmingMode).name)
        return outLocalDimmingMode

    def getColorTemperatureInfo(self):
        """
        Gets the Color Temperatures.

        Args:
            None.

        Returns:
            bool : ColorTemperatures
        """
        # Get the color temperature index from the profile
        ColorTempIndex = self.deviceProfile.get("ColorTemperature").get("index")

        # Check if index is valid
        if ColorTempIndex is None:
            return []

        outColor = []
        for color in ColorTempIndex:
            outColor.append(tvColorTemperature(color).name)
        return outColor

    def getAspectRatio(self):
        """
        Gets the Aspect Ratio.

        Args:
            None.

        Returns:
            bool : Aspect Ratio
        """
        # Get the color temperature index from the profile
        AspectRatioIndex = self.deviceProfile.get("AspectRatio").get("index")

        # Check if index is valid
        if AspectRatioIndex is None:
            return []

        outAspectRatio = []
        for AspectRatio in AspectRatioIndex:
            outAspectRatio.append(tvDisplayMode(AspectRatio).name)
        return outAspectRatio

    def getDolbyVisionInfo(self):
        """
        Gets the DolbyVisions.

        Args:
            None.

        Returns:
            bool : Dolby Visions
        """
        # Get the Dolby Vision index from the profile
        DolbyVisionMode = self.deviceProfile.get("DolbyVisionMode").get("index")

        # Check if index is valid
        if DolbyVisionMode is None:
            return []

        outDolbyVision = []
        for DolbyVision in DolbyVisionMode:
            outDolbyVision.append(tvDolbyMode(DolbyVision).name)
        return outDolbyVision

    def getPictureModeInfo(self):
        """
        Gets the Picture Modes.

        Args:
            None.

        Returns:
            bool : Picture Modes
        """
        # Get the Picture Mode index from the profile
        PictureMode = self.deviceProfile.get("PictureMode").get("index")

        # Check if index is valid
        if PictureMode is None:
            return []

        outPicture = []
        for Picture in PictureMode:
            outPicture.append(PQMode(Picture).name)
        return outPicture

    def getPictureModeIndex(self):
        """
        Gets the Picture Modes.

        Args:
            None.

        Returns:
            bool : Picture Modes
        """
        # Get the Picture Mode index from the profile
        PictureMode = self.deviceProfile.get("PictureMode").get("index")

        # Check if index is valid
        if PictureMode is None:
            return []

        outPicture = []
        for Picture in PictureMode:
            outPicture.append(PQMode_(Picture).name)
        return outPicture

    def getVideoFormatInfo(self):
        """
        Gets the Video Format.

        Args:
            None.

        Returns:
            bool : List of Video Formats.
        """
        # Get the Video Format index from the profile
        videoFormatIndex = self.deviceProfile.get("VideoFormat").get("index")

        # Check if index is valid
        if videoFormatIndex is None:
            return []

        outVideoFormats = []
        for videoFormat in videoFormatIndex:
            outVideoFormats.append(VideoFormat(videoFormat).name)
        return outVideoFormats

    def getVideoSourceInfo(self):
        """
        Gets the Video Source.

        Args:
            None.

        Returns:
            list : List containing the Video Source (always VIDEO_SOURCE_IP).
        """
        # Get the Video Source index from the profile
        videoSourceIndex = self.deviceProfile.get("VideoSource").get("index")

        # Check if index is valid
        if videoSourceIndex is None:
            return []

        outVideoSources = []
        for videoSource in videoSourceIndex:
            if videoSource == "IP":
                outVideoSources.append("VIDEO_SOURCE_IP")

        return outVideoSources

    def getVideoFrameRateInfo(self):
        """
        Gets the supported Video Frame Rates.

        Args:
            None.

        Returns:
            list : List of Supported Video Frame Rates.
        """
        # Get the Video Frame Rate index from the profile
        videoFrameRateIndex = self.deviceProfile.get("SupportedVideoFrameRate")

        # Check if index is valid
        if videoFrameRateIndex is None:
            return []

        outVideoFrameRates = []
        for videoFrameRate in videoFrameRateIndex:
            outVideoFrameRates.append(tvVideoFrameRate(videoFrameRate).name)
        return outVideoFrameRates

    def getVideoResolutionInfo(self):
        """
        Gets the supported Video Resolutions.

        Args:
            None.

        Returns:
            list : List of Supported Video Resolutions.
        """
        # Get the Video Resolution index from the profile
        video_resolution_index = self.deviceProfile.get("SupportedVideoResolution")

        # Check if index is valid
        if video_resolution_index is None:
            return []

        out_video_resolutions = []
        for video_resolution in video_resolution_index:
            out_video_resolutions.append(tvVideoResolution(video_resolution).name)
        return out_video_resolutions

    def get_video_frame_rate_info(self):
        """
        Gets the supported Video Frame Rates.

        Args:
            None.

        Returns:
            list : List of Supported Video Frame Rates.
        """
        # Get the Video Frame Rate index from the profile
        videoFrameRateIndex = self.deviceProfile.get("SupportedVideoFrameRate")

        # Check if index is valid
        if videoFrameRateIndex is None:
            return []

        outVideoFrameRates = []
        for videoFrameRate in videoFrameRateIndex:
            outVideoFrameRates.append(tvVideoFrameRate(videoFrameRate).name)
        return outVideoFrameRates

    def getTVDataColor(self):
        """
        Gets the supported TV Data Colors.

        Args:
            None.

        Returns:
            list: List of supported TV Data Colors.
        """

        outTVDataColors = []
        for color in tvDataColor:
                outTVDataColors.append(tvDataColor(color).name)

        return outTVDataColors


    def getComponentTypeInfo(self):
        """
        Gets the Component Types.

        Args:
            None.

        Returns:
            list : List of component type names.
        """
        outComponents = []
        for component in ComponentType:
            outComponents.append(component.name)
        return outComponents

    def getBacklightTestModeInfo(self):
        """
        Gets the Backlight Test Modes.

        Args:
            None.

        Returns:
            list : List of backlight test mode names.
        """
        outBacklightTestModes = []
        for mode in tvBacklightTestMode:
            outBacklightTestModes.append(mode.name)
        return outBacklightTestModes

    def getVideoFrameRateCallbackStatus(self):
        """
        Retrieves the video frame rate from a system callback.

        Args:
            None.

        Returns:
            None: If the function fails to retrieve the callback status.
            str: The current stream format, as indicated by the system callback.
        """
        result = self.testSession.read_until("Received Video Frame Rate Change callback format")

        formatCallbackPattern = r"Received Video Frame Rate Change callback format:\[(\w+)\]"

        return self.searchPattern(result, formatCallbackPattern)

    def getVideoFormatCallbackStatus(self):
        """
        Retrieves the video frame rate from a system callback.

        Args:
            None.

        Returns:
            None: If the function fails to retrieve the callback status.
            str: The current stream format, as indicated by the system callback.
        """
        result = self.testSession.read_until("Received Video Format Change callback format")

        formatCallbackPattern = r"Received Video Format Change callback format:\[(\w+)\], userData\[\]\[0x([0-9A-Fa-f]+)\]"

        return self.searchPattern(result, formatCallbackPattern)

    def getVideoResolutionCallbackStatus(self):
        """
        Retrieves the video resolution from a system callback.

        Args:
            None.

        Returns:
            None: If the function fails to retrieve the callback status.
            tuple: The height, width, interlaced status, resolution, and user data, as indicated by the system callback.
        """
        result = self.testSession.read_until("Received Video Resolution Change callback Frame heightxwidth")

        formatCallbackPattern = r"Received Video Resolution Change callback Frame heightxwidth:\[(\d+)x(\d+)\], IsInterlaced\[(\d+)\] Res:\[(\w+)\], userData\[\]\[0x([0-9A-Fa-f]+)\]"

        return self.searchPattern(result, formatCallbackPattern)

    def getVideoContentCallbackStatus(self):
        """
        Retrieves the video content from a system callback.

        Args:
            None.

        Returns:
            None: If the function fails to retrieve the callback status.
            tuple: The current stream format and user data, as indicated by the system callback.
        """
        result = self.testSession.read_until("Received Video Content Change callback format")

        formatCallbackPattern = r"Received Video Content Change callback format:\[(\w+)\], userData\[\]\[0x([0-9A-Fa-f]+)\]"

        return self.searchPattern(result, formatCallbackPattern)


    def terminate(self):
        """
        Enables the tvSettings port.

        Args:
            None.

        Returns:
            None
        """
        result = self.utMenu.select(self.testSuite, "Terminate")