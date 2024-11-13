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
from raft.framework.plugins.ut_raft.utBaseUtils import utBaseUtils

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
    tvVideoResolution_NONE               = 0                    # No Resolution
    tvVideoResolution_720x240            = auto()               # Resolution is 720x240
    tvVideoResolution_2880x240           = auto()               # Resolution is 2880x240
    tvVideoResolution_720x288            = auto()               # Resolution is 720x288
    tvVideoResolution_2880x288           = auto()               # Resolution is 2880x288
    tvVideoResolution_640x480            = auto()               # Resolution is 640x480
    tvVideoResolution_720x480            = auto()               # Resolution is 720x480
    tvVideoResolution_800x480            = auto()               # Resolution is 800x480
    tvVideoResolution_852x480            = auto()               # Resolution is 852x480
    tvVideoResolution_854x480            = auto()               # Resolution is 854x480
    tvVideoResolution_1440x480           = auto()               # Resolution is 1440x480
    tvVideoResolution_2880x480           = auto()               # Resolution is 2880x480
    tvVideoResolution_960x540            = auto()               # Resolution is 960x540
    tvVideoResolution_3840x540           = auto()               # Resolution is 3840x540
    tvVideoResolution_720x576            = auto()               # Resolution is 720x576
    tvVideoResolution_1440x576           = auto()               # Resolution is 1440x576
    tvVideoResolution_2880x576           = auto()               # Resolution is 2880x576
    tvVideoResolution_800x600            = auto()               # Resolution is 800x600
    tvVideoResolution_1024x600           = auto()               # Resolution is 1024x600
    tvVideoResolution_1280x600           = auto()               # Resolution is 1280x600
    tvVideoResolution_1280x720           = auto()               # Resolution is 1280x720
    tvVideoResolution_1280x1024          = auto()               # Resolution is 1280x1024
    tvVideoResolution_1680x720           = auto()               # Resolution is 1680x720
    tvVideoResolution_1024x768           = auto()               # Resolution is 1024x768
    tvVideoResolution_1280x768           = auto()               # Resolution is 1280x768
    tvVideoResolution_1360x768           = auto()               # Resolution is 1360x768
    tvVideoResolution_1366x768           = auto()               # Resolution is 1366x768
    tvVideoResolution_1440x900           = auto()               # Resolution is 1440x900
    tvVideoResolution_1600x900           = auto()               # Resolution is 1600x900
    tvVideoResolution_1280x960           = auto()               # Resolution is 1280x960
    tvVideoResolution_1920x1080          = auto()               # Resolution is 1920x1080
    tvVideoResolution_2560x1080          = auto()               # Resolution is 2560x1080
    tvVideoResolution_3840x1080          = auto()               # Resolution is 3840x1080
    tvVideoResolution_1600x1200          = auto()               # Resolution is 1600x1200
    tvVideoResolution_1920x1200          = auto()               # Resolution is 1920x1200
    tvVideoResolution_2160x1200          = auto()               # Resolution is 2160x1200
    tvVideoResolution_2400x1200          = auto()               # Resolution is 2400x1200
    tvVideoResolution_2560x1440          = auto()               # Resolution is 2560x1440
    tvVideoResolution_3440x1440          = auto()               # Resolution is 3440x1440
    tvVideoResolution_3840x2160          = auto()               # Resolution is 3840x2160
    tvVideoResolution_4096x2160          = auto()               # Resolution is 4096x2160

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

class TvVideoSrcType(Enum):
    VIDEO_SOURCE_ANALOGUE                 = 0               # Video source is Analogue
    VIDEO_SOURCE_COMPOSITE1               = auto()          # Video source is Composite1
    VIDEO_SOURCE_COMPOSITE2               = auto()          # Video source is Composite2
    VIDEO_SOURCE_YPBPR1                   = auto()          # Video source is YPbPr1
    VIDEO_SOURCE_YPBPR2                   = auto()          # Video source is YPbPr2
    VIDEO_SOURCE_HDMI1                    = auto()          # Video source is HDMI1
    VIDEO_SOURCE_HDMI2                    = auto()          # Video source is HDMI2
    VIDEO_SOURCE_HDMI3                    = auto()          # Video source is HDMI3
    VIDEO_SOURCE_HDMI4                    = auto()          # Video source is HDMI4
    VIDEO_SOURCE_VGA                      = auto()          # Video source is VGA
    VIDEO_SOURCE_IP                       = auto()          # Video source is IP
    VIDEO_SOURCE_TUNER                    = auto()          # Video source is Tuner
    VIDEO_SOURCE_SVIDEO                   = auto()          # Video source is SVideo
    VIDEO_SOURCE_RESERVED                 = auto()          # Video source reserved
    VIDEO_SOURCE_RESERVED1                = auto()          # Video source reserved
    VIDEO_SOURCE_RESERVED2                = auto()          # Video source reserved
    VIDEO_SOURCE_RESERVED3                = auto()          # Video source reserved
    VIDEO_SOURCE_MAX                      = auto()          # End of enum


class tvSettingsClass():

    """
    tvSettings Class

    This module provides common extensions for tvSettings Module.
    """
    def __init__(self, moduleConfigProfileFile:str, session=None, targetWorkspace="/tmp"):
        """
        Initializes the tvSettings class function.
        """
        self.moduleName    = "tvSettings"
        self.testConfigFile     =  dir_path + "/tvSettings_testConfig.yml"
        self.testSuite     = "L3 tvSettings"

        # Load configurations for device profile and menu
        self.deviceProfile = ConfigRead( moduleConfigProfileFile , self.moduleName)
        self.testConfig    = ConfigRead(self.testConfigFile, self.moduleName)
        self.testConfig.test.execute = os.path.join(targetWorkspace, self.testConfig.test.execute)
        self.utMenu        = UTSuiteNavigatorClass(self.testConfig, None, session)
        self.testSession   = session
        self.utils         = utBaseUtils()

        for artifact in self.testConfig.test.artifacts:
            filesPath = os.path.join(dir_path, artifact)
            self.utils.rsync(self.testSession, filesPath, targetWorkspace)

        # Start the user interface menu
        self.utMenu.start()

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
        Retrieves the current video format from the system.

        This function interacts with the utMenu to execute the 'Get Video Format'
        test suite and captures the video format using a regex pattern.

        Args:
            None

        Returns:
            str: The video format identifier (e.g., VIDEO_FORMAT_SDR, VIDEO_FORMAT_HDR, etc.)
                extracted from the test suite result, or None if not found.
        """
        # Use the same utMenu.select structure to interact
        result = self.utMenu.select(self.testSuite, "Get Video Format")

        # Regex pattern to extract the video format from the result string
        videoFormatPattern = r"Result GetCurrentVideoFormat\(OUT:Video Format:\[(VIDEO_FORMAT_\w+)\]\)"

        # Search the result for the video format using the pattern
        videoFormat = self.searchPattern(result, videoFormatPattern)

        return videoFormat


    def checkVideoResolution(self):
        """
        Retrieves the current video resolution from the system.

        This function interacts with the utMenu to execute the 'Get Resolution'
        test suite and captures the video resolution using a regex pattern.

        Args:
            None

        Returns:
            dict: A dictionary containing video resolution details with keys 'width', 'height', 
                'isInterlaced', and 'resolutionName', or None if not found.
        """
        # Interact with the utMenu to run the 'Get Resolution' test
        result = self.utMenu.select(self.testSuite, "Get Resolution")

        # Regex pattern to extract the video resolution from the result string
        videoResolutionPattern = r"Result GetCurrentVideoResolution\(OUT:Resolution:\[(\d+)x(\d+)\], OUT:isInterlaced:\[(\d+)\], OUT:res value:\[(tvVideoResolution_\w+)\]\)"

        # Search the result for the video resolution details using the pattern
        match = re.search(videoResolutionPattern, result)

        if match:
            # Capture the width, height, interlace status, and resolution name
            videoResolution = {
                "width": int(match.group(1)),
                "height": int(match.group(2)),
                "isInterlaced": bool(int(match.group(3))),
                "resolutionName": match.group(4)
            }
        else:
            videoResolution = None

        return videoResolution



    def checkVideoFrameRate(self):
        """
        Retrieves the current video frame rate from the system.

        This function interacts with the utMenu to execute the 'Get Video FrameRate'
        test suite and captures the frame rate using a regex pattern.

        Args:
            None

        Returns:
            str: The video frame rate identifier (e.g., tvVideoFrameRate_60, tvVideoFrameRate_24, etc.)
                extracted from the test suite result, or None if not found.
        """
        # Use the same utMenu.select structure to interact
        result = self.utMenu.select(self.testSuite, "Get Video FrameRate")

        # Regex pattern to extract the video frame rate from the result string
        videoFrameRatePattern = r"Result GetCurrentVideoFrameRate\(OUT:Frame Rate:\[(tvVideoFrameRate_\w+)\]\)"

        # Search the result for the frame rate using the pattern
        videoFrameRate = self.searchPattern(result, videoFrameRatePattern)

        return videoFrameRate


    def checkVideoSource(self):
        """
        Retrieves the current video source from the system.

        This function interacts with the utMenu to execute the 'Get Video Source'
        test suite and captures the video source using a regex pattern.

        Args:
            None

        Returns:
            str: The video source identifier (e.g., VIDEO_SOURCE_HDMI1, VIDEO_SOURCE_AV, etc.)
                extracted from the test suite result, or None if not found.
        """
        # Use the same utMenu.select structure to interact
        result = self.utMenu.select(self.testSuite, "Get Video Source")

        # Regex pattern to extract the video source from the result string
        videoSourcePattern = r"Result GetCurrentVideoSource\(OUT:Current Source:\[(VIDEO_SOURCE_\w+)\]\)"

        # Search the result for the video source using the pattern
        videoSource = self.searchPattern(result, videoSourcePattern)

        return videoSource


    def setBacklight(self, backlightLevel: int = 0):
        """
        Sets the backlight level for the video display.

        Args:
            backlightLevel (int, optional): The backlight level to be applied. Ranges from 0 to 100.
                                            Defaults to 0.

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


    def setBacklightFade(self, fromVal: int = 0, toVal: int = 0, fadeDuration: int = 0):
        """
        Sets the backlight fade effect.

        Args:
            fromVal (int, optional): The starting backlight value (0 to 100). Defaults to 0.
            toVal (int, optional): The ending backlight value (0 to 100). Defaults to 0.
            fadeDuration (int, optional): The duration of the fade effect in milliseconds (0 to 1000).
                                        Defaults to 0.

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


    def setBacklightMode(self, backlightMode: str = "tvBacklightMode_MANUAL"):
        """
        Sets the backlight mode.

        Args:
            backlightMode (int, optional): The backlight mode to be applied. Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter the number corresponding to the Backlight Mode:",
                "input": str(backlightMode)
            }
        ]

        result = self.utMenu.select(self.testSuite, "Back light Mode", promptWithAnswers)


    def setTVDimmingMode(self, TVDimmingMode: str = "tvDimmingMode_Fixed"):
        """
        Sets the TV dimming mode.

        Args:
            TVDimmingMode (int, optional): The TV dimming mode to be applied. Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter the number corresponding to the Dimming Mode:",
                "input": TVDimmingMode
            }
        ]

        result = self.utMenu.select(self.testSuite, "TV Dimming Mode", promptWithAnswers)


    def setLocalDimmingMode(self, LocalDimmingMode: str = "LDIM_STATE_NONBOOST"):
        """
        Sets the local dimming mode.

        Args:
            LocalDimmingMode (int, optional): The local dimming mode to be applied. Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter the number corresponding to the desired Local Dimming Level:",
                "input": LocalDimmingMode
            }
        ]

        result = self.utMenu.select(self.testSuite, "Local Dimming Mode", promptWithAnswers)


    def setBrightnessLevel(self, brightnessLevel: int = 0):
        """
        Sets the brightness level for the display.

        Args:
            brightnessLevel (int, optional): The brightness level to be applied. Ranges from 0 to 100.
                                            Defaults to 0.

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
        Sets the contrast level for the display.

        Args:
            contrastLevel (int, optional): The contrast level to be applied. Ranges from 0 to 100.
                                            Defaults to 0.

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
        Sets the sharpness level for the display.

        Args:
            sharpnessLevel (int, optional): The sharpness level to be applied. Ranges from 0 to 100.
                                            Defaults to 0.

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
        Sets the saturation level for the display.

        Args:
            saturationLevel (int, optional): The saturation level to be applied. Ranges from 0 to 100.
                                            Defaults to 0.

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
        Sets the hue level for the display.

        Args:
            hueLevel (int, optional): The hue level to be applied. Ranges from 0 to 100.
                                    Defaults to 0.

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


    def setColorTempLevel(self, ColorTempLevel: str = "tvColorTemp_STANDARD"):
        """
        Sets the color temperature level.

        Args:
            ColorTempLevel (str, optional): The color temperature level to be applied.
                                            Defaults to "tvColorTemp_STANDARD".

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

    def setAspectRatio(self, AspectRatio: str = "tvDisplayMode_4x3"):
        """
        Sets the aspect ratio for the display.

        Args:
            AspectRatio (str, optional): The aspect ratio level to be applied.
                                        Defaults to "tvDisplayMode_4x3".

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


    def setLowLatencyState(self, LowLatency: bool = False):
        """
        Sets the low latency state.

        Args:
            LowLatency (bool, optional): The low latency state to be applied.
                                        Use True to enable and False to disable.
                                        Defaults to False.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "direct",
                "query": "Enter 0 to Disable or 1 to Enable Low Latency:",
                "input": str(int(LowLatency))
            }
        ]

        result = self.utMenu.select(self.testSuite, "Low Latency State", promptWithAnswers)


    def setDynamicContrast(self, DynamicContrast: str = "disabled"):
        """
        Sets the dynamic contrast level.

        Args:
            DynamicContrast (str, optional): The dynamic contrast state to be applied.
                                            Use "enabled" to enable and "disabled" to disable.
                                            Defaults to "disabled".

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter '1' to Enable or '2' to Disable Dynamic Contrast:",
                "input": DynamicContrast
            }
        ]

        result = self.utMenu.select(self.testSuite, "Dynamic Contrast", promptWithAnswers)


    def setDynamicGamma(self, DynamicGamma: float = 0.0):
        """
        Sets the dynamic gamma level.

        Args:
            DynamicGamma (float, optional): The dynamic gamma value to be applied.
                                            Ranges from 1.80 to 2.60. Defaults to 0.0.

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


    def setDolbyVision(self, DolbyVision: str = "tvDolbyMode_Dark"):
        """
        Sets the Dolby Vision mode.

        Args:
            DolbyVision (str, optional): The Dolby Vision mode to be applied.
                                        Defaults to "tvDolbyMode_Dark".

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


    def setPictureMode(self, PictureMode: str = None):
        """
        Sets the picture mode.

        Args:
            PictureMode (str, optional): The picture mode to be applied.
                                        Defaults to the 0th index of deviceProfile.PictureMode.range.

        Returns:
            None
        """
        # Use the 0th index if PictureMode is not provided
        if PictureMode is None:
            PictureMode = self.deviceProfile.PictureMode.range[0]

        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter the number corresponding to the Picture Mode:",
                "input": PictureMode
            }
        ]

        result = self.utMenu.select(self.testSuite, "Picture Mode", promptWithAnswers)



    def setRgainValue(self, VideoSource: str= "TV_OFFSET", ColorTemp: str = "tvColorTemp_STANDARD", RgainValue: int = 0, SetOrSave: int = 0):
        """
        Sets the Rgain value for the specified color temperature.

        Args:
            VideoSource (str, optional): The video source to be used.
                                            Defaults to "TV_OFFSET".
            ColorTemp (str, optional): The color temperature to be applied.
                                    Defaults to "tvColorTemp_STANDARD".
            RgainValue (int, optional): The Rgain value to be applied.
                                        Ranges from 0 to 2047. Defaults to 0.
            SetOrSave (int, optional): Flag to set or save the value.
                                    Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Video Source (index):",
                "input": VideoSource
            },
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


    def setGgainValue(self, VideoSource: str= "TV_OFFSET", ColorTemp: str = "tvColorTemp_STANDARD", GgainValue: int = 0, SetOrSave: int = 0):
        """
        Sets the Ggain value for the specified color temperature.

        Args:
            VideoSource (str, optional): The video source to be used.
                                      Defaults to "TV_OFFSET".
            ColorTemp (str, optional): The color temperature to be applied.
                                    Defaults to "tvColorTemp_STANDARD".
            GgainValue (int, optional): The Ggain value to be applied.
                                        Ranges from 0 to 2047. Defaults to 0.
            SetOrSave (int, optional): Flag to set or save the value.
                                    Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Video Source (index):",
                "input": VideoSource
            },
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


    def setBgainValue(self, VideoSource: str= "TV_OFFSET", ColorTemp: str = "tvColorTemp_STANDARD", BgainValue: int = 0, SetOrSave: int = 0):
        """
        Sets the Bgain value for the specified color temperature.

        Args:
            VideoSource (str, optional): The video source to be used.
                                        Defaults to "TV_OFFSET".
            ColorTemp (str, optional): The color temperature to be applied.
                                    Defaults to "tvColorTemp_STANDARD".
            BgainValue (int, optional): The Bgain value to be applied.
                                        Ranges from 0 to 2047. Defaults to 0.
            SetOrSave (int, optional): Flag to set or save the value.
                                    Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Video Source (index):",
                "input": VideoSource
            },
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

        result = self.utMenu.select(self.testSuite, "ColorTempBgain", promptWithAnswers)


    def setRpostOffsetValue(self, VideoSource: str= "TV_OFFSET", ColorTemp: str = "tvColorTemp_STANDARD", RpostOffsetValue: int = 0, SetOrSave: int = 0):
        """
        Sets the RpostOffset value for the specified color temperature.

        Args:
            VideoSource (str, optional): The video source to be used.
                                      Defaults to "TV_OFFSET".
            ColorTemp (str, optional): The color temperature to be applied.
                                    Defaults to "tvColorTemp_STANDARD".
            RpostOffsetValue (int, optional): The RpostOffset value to be applied.
                                            Ranges from -1024 to 1023. Defaults to 0.
            SetOrSave (int, optional): Flag to set or save the value.
                                    Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Video Source (index):",
                "input": VideoSource
            },
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


    def setGpostOffsetValue(self, VideoSource: str= "TV_OFFSET", ColorTemp: str = "tvColorTemp_STANDARD", GpostOffsetValue: int = 0, SetOrSave: int = 0):
        """
        Sets the GpostOffset value for the specified color temperature.

        Args:
            VideoSource (str, optional): The video source to be used.
                                      Defaults to "TV_OFFSET".
            ColorTemp (str, optional): The color temperature to be applied.
                                    Defaults to "tvColorTemp_STANDARD".
            GpostOffsetValue (int, optional): The GpostOffset value to be applied.
                                            Ranges from -1024 to 1023. Defaults to 0.
            SetOrSave (int, optional): Flag to set or save the value.
                                    Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Video Source (index):",
                "input": VideoSource
            },
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


    def setBpostOffsetValue(self, VideoSource: str= "TV_OFFSET", ColorTemp: str = "tvColorTemp_STANDARD", BpostOffsetValue: int = 0, SetOrSave: int = 0):
        """
        Sets the BpostOffset value for the specified color temperature.

        Args:
            VideoSource (str, optional): The video source to be used.
                                      Defaults to "TV_OFFSET".
            ColorTemp (str, optional): The color temperature to be applied.
                                    Defaults to "tvColorTemp_STANDARD".
            BpostOffsetValue (int, optional): The BpostOffset value to be applied.
                                            Ranges from -1024 to 1023. Defaults to 0.
            SetOrSave (int, optional): Flag to set or save the value.
                                    Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Video Source (index):",
                "input": VideoSource
            },
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


    def setWBCalibration(self, WBcalibrationFlag: bool = 0):
        """
        Sets the White Balance (WB) calibration mode.

        Args:
            WBcalibrationFlag (bool, optional): Flag to enable (1) or disable (0) WB calibration.
                                                Defaults to 0 (Disabled).

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


    def setGammaTable(self, gammaTableSize: int = 1, gammaRed: list = None, gammaGreen: list = None, gammaBlue: list = None):
        """
        Sets the Gamma Table values.

        Args:
            gammaTableSize (int, optional): Size of the gamma table (1 to 255). Defaults to 1.
            gammaRed (list, optional): List of gamma values for Red (0 to 1023). Defaults to empty list.
            gammaGreen (list, optional): List of gamma values for Green (0 to 1023). Defaults to empty list.
            gammaBlue (list, optional): List of gamma values for Blue (0 to 1023). Defaults to empty list.

        Returns:
            None
        """
        # Set default values to empty lists if None is provided
        if gammaRed is None:
            gammaRed = []
        if gammaGreen is None:
            gammaGreen = []
        if gammaBlue is None:
            gammaBlue = []

        # Prepare the prompt with answers for user input
        promptWithAnswers = [
            {
                "query_type": "direct",
                "query": "Enter the size of the gamma table (1 - 255):",
                "input": str(gammaTableSize)
            },
            {
                "query_type": "direct",
                "query": f"Enter {gammaTableSize} gamma values for Red (0 - 1023):",
                "input": "\n".join(map(str, gammaRed))
            },
            {
                "query_type": "direct",
                "query": f"Enter {gammaTableSize} gamma values for Green (0 - 1023):",
                "input": "\n".join(map(str, gammaGreen))
            },
            {
                "query_type": "direct",
                "query": f"Enter {gammaTableSize} gamma values for Blue (0 - 1023):",
                "input": "\n".join(map(str, gammaBlue))
            }
        ]

        result = self.utMenu.select(self.testSuite, "Gamma Table", promptWithAnswers)


    def saveGammaTable(self, gammaTableSize: int = 1, gammaRed: list = None, gammaGreen: list = None, gammaBlue: list = None, colorTemperature: str = "tvColorTemp_STANDARD"):
        """
        Saves Gamma Table values and applies a specified color temperature.

        Args:
            gammaTableSize (int, optional): Size of the gamma table (1 to 255). Defaults to 1.
            gammaRed (list, optional): List of gamma values for Red (0 to 1023). Defaults to None.
            gammaGreen (list, optional): List of gamma values for Green (0 to 1023). Defaults to None.
            gammaBlue (list, optional): List of gamma values for Blue (0 to 1023). Defaults to None.
            colorTemperature (str, optional): Desired color temperature setting. Defaults to "tvColorTemp_STANDARD".

        Returns:
            None
        """
        # Initialize gamma values if not provided
        if gammaRed is None:
            gammaRed = [0] * gammaTableSize
        if gammaGreen is None:
            gammaGreen = [0] * gammaTableSize
        if gammaBlue is None:
            gammaBlue = [0] * gammaTableSize

        # Ensure gamma values are within acceptable limits (0-1023)
        gammaRed = [min(max(value, 0), 1023) for value in gammaRed]
        gammaGreen = [min(max(value, 0), 1023) for value in gammaGreen]
        gammaBlue = [min(max(value, 0), 1023) for value in gammaBlue]

        # Prepare prompt for user input if required
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter the number corresponding to the Color Temperature:",
                "input": colorTemperature
            },
            {
                "query_type": "direct",
                "query": "Enter the size of the gamma table (1 - 255):",
                "input": str(gammaTableSize)
            },
            {
                "query_type": "direct",
                "query": f"Enter {gammaTableSize} gamma values for Red (0 - 1023):",
                "input": "\n".join(map(str, gammaRed))
            },
            {
                "query_type": "direct",
                "query": f"Enter {gammaTableSize} gamma values for Green (0 - 1023):",
                "input": "\n".join(map(str, gammaGreen))
            },
            {
                "query_type": "direct",
                "query": f"Enter {gammaTableSize} gamma values for Blue (0 - 1023):",
                "input": "\n".join(map(str, gammaBlue))
            }
        ]

        # Display prompts and collect user inputs
        result = self.utMenu.select(self.testSuite, "Save Gamma Table", promptWithAnswers)



    def setComponentSaturation(self, colorIndex: str = "tvDataColor_RED", saturationValue: int = 0):
        """
        Sets Component Saturation values.

        Args:
            colorIndex (str, optional): Component color index to be applied. Defaults to "tvDataColor_RED".
            saturationValue (int, optional): Saturation value to be applied (0 to 100). Defaults to 0.

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
            colorIndex (str, optional): Component color index to be applied. Defaults to "tvDataColor_RED".
            hueValue (int, optional): Hue value to be applied (0 to 100). Defaults to 0.

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
            colorIndex (str, optional): Component color index to be applied. Defaults to "tvDataColor_RED".
            lumaValue (int, optional): Luma value to be applied (0 to 30). Defaults to 0.

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
            dvTmaxValue (int, optional): Dolby Vision TMAX value to be applied (0 to 10000). Defaults to 0.

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
            cmsState (bool, optional): CMS state to be applied (0 to Disable, 1 to Enable). Defaults to 0.

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
            enableGammaMode (bool, optional): Gamma mode to be applied (0 to Disable, 1 to Enable). Defaults to 0.

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
            gammaPatternMode (bool, optional): Gamma pattern mode to be applied (0 to Disable, 1 to Enable). Defaults to 0.

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

        result = self.utMenu.select(self.testSuite, "EnableLDIMPixelCompensation", promptWithAnswers)

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

        result = self.utMenu.select(self.testSuite, "LDIMEnable", promptWithAnswers)


    def setBacklightTestMode(self, mode: str = "tvBacklightTestMode_Normal"):
        """
        Sets backlight test mode.

        Args:
            mode (str, optional): Backlight test mode to be applied. Defaults to "tvBacklightTestMode_Normal".

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


    def enableDynamicContrast(self, mode: int = 0):
        """
        Enables dynamic contrast mode.

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


    def enableLocalContrast(self, mode: int = 0):
        """
        Enables local contrast mode.

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


    def saveBacklightValues(self,  VideoSource: str= "VIDEO_SOURCE_IP", pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD", backlightValue: int = 0):
        """
        Saves backlight values.

        Args:
            VideoSource (str, optional): The video source to be used.
                                        Defaults to "VIDEO_SOURCE_IP".
            pictureModeIndex (str, optional): Your choice of Picture Mode index.
                                            Defaults to "PQ_MODE_STANDARD".
            videoFormatIndex (str, optional): Your choice of Video Format index.
                                            Defaults to "PQ_MODE_STANDARD".
            backlightValue (int, optional): Backlight value to set.
                                            Ranges from 0 to 100. Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Video Source (index):",
                "input": VideoSource
            },
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


    def saveTVDimmingModeValues(self, VideoSource: str = "VIDEO_SOURCE_IP", pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD", dimmingModeIndex: str = "tvDimmingMode_Fixed"):
        """
        Saves TV Dimming Mode values.

        Args:
            VideoSource (str, optional): The video source to be used.
                                        Defaults to "VIDEO_SOURCE_IP".
            pictureModeIndex (str, optional): Your choice of Picture Mode index.
                                            Defaults to "PQ_MODE_STANDARD".
            videoFormatIndex (str, optional): Your choice of Video Format index.
                                            Defaults to "PQ_MODE_STANDARD".
            dimmingModeIndex (str, optional): Your choice of Dimming Mode index.
                                            Defaults to "tvDimmingMode_Fixed".

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Video Source (index):",
                "input": VideoSource
            },
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


    def saveLocalDimmingModeValues(self, VideoSource: str = "VIDEO_SOURCE_IP", pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD", dimmingLevelIndex: str = "LDIM_STATE_NONBOOST"):
        """
        Saves Local Dimming Mode values.

        Args:
            VideoSource (str, optional): The video source to be used.
                                        Defaults to "VIDEO_SOURCE_IP".
            pictureModeIndex (str, optional): Your choice of Picture Mode index.
                                            Defaults to "PQ_MODE_STANDARD".
            videoFormatIndex (str, optional): Your choice of Video Format index.
                                            Defaults to "PQ_MODE_STANDARD".
            dimmingLevelIndex (str, optional): Your choice of Local Dimming Level index.
                                                Defaults to "LDIM_STATE_NONBOOST".

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Video Source (index):",
                "input": VideoSource
            },
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
                "input": dimmingLevelIndex
            }
        ]

        result = self.utMenu.select(self.testSuite, "Save Local Dimming Mode values", promptWithAnswers)


    def saveBrightnessValues(self, VideoSource: str = "VIDEO_SOURCE_IP", pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD", brightnessValue: int = 0):
        """
        Saves brightness values.

        Args:
            VideoSource (str, optional): The video source to be used.
                                        Defaults to "VIDEO_SOURCE_IP".
            pictureModeIndex (str, optional): Your choice of Picture Mode index.
                                            Defaults to "PQ_MODE_STANDARD".
            videoFormatIndex (str, optional): Your choice of Video Format index.
                                            Defaults to "PQ_MODE_STANDARD".
            brightnessValue (int, optional): Brightness value to set (0 - 100).
                                            Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Video Source (index):",
                "input": VideoSource
            },
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


    def saveContrastValues(self, VideoSource: str = "VIDEO_SOURCE_IP", pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD", contrastValue: int = 0):
        """
        Saves contrast values.

        Args:
            VideoSource (str, optional): The video source to be used.
                                        Defaults to "VIDEO_SOURCE_IP".
            pictureModeIndex (str, optional): Your choice of Picture Mode index.
                                            Defaults to "PQ_MODE_STANDARD".
            videoFormatIndex (str, optional): Your choice of Video Format index.
                                            Defaults to "PQ_MODE_STANDARD".
            contrastValue (int, optional): Contrast value to set (0 - 100).
                                        Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Video Source (index):",
                "input": VideoSource
            },
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
                "query": "Enter the contrast value to set (0 - 100):",
                "input": str(contrastValue)
            }
        ]

        result = self.utMenu.select(self.testSuite, "Save Contrast values", promptWithAnswers)


    def saveSharpnessValues(self, VideoSource: str = "VIDEO_SOURCE_IP", pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD", sharpnessValue: int = 0):
        """
        Saves sharpness values.

        Args:
            VideoSource (str, optional): The video source to be used.
                                        Defaults to "VIDEO_SOURCE_IP".
            pictureModeIndex (str, optional): Your choice of Picture Mode index.
                                            Defaults to "PQ_MODE_STANDARD".
            videoFormatIndex (str, optional): Your choice of Video Format index.
                                            Defaults to "PQ_MODE_STANDARD".
            sharpnessValue (int, optional): Sharpness value to set (0 - 100).
                                            Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Video Source (index):",
                "input": VideoSource
            },
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


    def saveSaturationValues(self, VideoSource: str = "VIDEO_SOURCE_IP", pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD", saturationValue: int = 0):
        """
        Saves saturation values.

        Args:
            VideoSource (str, optional): The video source to be used.
                                        Defaults to "VIDEO_SOURCE_IP".
            pictureModeIndex (str, optional): Your choice of Picture Mode index.
                                            Defaults to "PQ_MODE_STANDARD".
            videoFormatIndex (str, optional): Your choice of Video Format index.
                                            Defaults to "PQ_MODE_STANDARD".
            saturationValue (int, optional): Saturation value to set (0 - 100).
                                            Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Video Source (index):",
                "input": VideoSource
            },
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


    def saveHueValues(self, VideoSource: str = "VIDEO_SOURCE_IP", pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD", hueValue: int = 0):
        """
        Saves hue values.

        Args:
            VideoSource (str, optional): The video source to be used.
                                        Defaults to "VIDEO_SOURCE_IP".
            pictureModeIndex (str, optional): Your choice of Picture Mode index.
                                            Defaults to "PQ_MODE_STANDARD".
            videoFormatIndex (str, optional): Your choice of Video Format index.
                                            Defaults to "PQ_MODE_STANDARD".
            hueValue (int, optional): Hue value to set (0 - 100).
                                    Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Video Source (index):",
                "input": VideoSource
            },
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


    def saveColorTemperatureValues(self, VideoSource: str = "VIDEO_SOURCE_IP", pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD", colorTemperatureIndex: str = "tvColorTemp_STANDARD"):
        """
        Saves color temperature values.

        Args:
            VideoSource (str, optional): The video source to be used.
                                        Defaults to "VIDEO_SOURCE_IP".
            pictureModeIndex (str, optional): Your choice of Picture Mode index.
                                            Defaults to "PQ_MODE_STANDARD".
            videoFormatIndex (str, optional): Your choice of Video Format index.
                                            Defaults to "PQ_MODE_STANDARD".
            colorTemperatureIndex (str, optional): Your choice of Color Temperature index.
                                                    Defaults to "tvColorTemp_STANDARD".

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Video Source (index):",
                "input": VideoSource
            },
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


    def saveAspectRatioValues(self, VideoSource: str = "VIDEO_SOURCE_IP", pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD", aspectRatioIndex: str = "tvDisplayMode_4x3"):
        """
        Saves aspect ratio values.

        Args:
            VideoSource (str, optional): The video source to be used.
                                        Defaults to "VIDEO_SOURCE_IP".
            pictureModeIndex (str, optional): Your choice of Picture Mode index.
                                            Defaults to "PQ_MODE_STANDARD".
            videoFormatIndex (str, optional): Your choice of Video Format index.
                                            Defaults to "PQ_MODE_STANDARD".
            aspectRatioIndex (str, optional): Your choice of Aspect Ratio index.
                                            Defaults to "tvDisplayMode_4x3".

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Video Source (index):",
                "input": VideoSource
            },
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


    def saveLowLatencyValues(self, VideoSource: str = "VIDEO_SOURCE_IP", pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD", lowLatencyIndex: int = 0):
        """
        Saves low latency values.

        Args:
            VideoSource (str, optional): The video source to be used.
                                        Defaults to "VIDEO_SOURCE_IP".
            pictureModeIndex (str, optional): Your choice of Picture Mode index.
                                            Defaults to "PQ_MODE_STANDARD".
            videoFormatIndex (str, optional): Your choice of Video Format index.
                                            Defaults to "PQ_MODE_STANDARD".
            lowLatencyIndex (int, optional): Low Latency Index (0 or 1).
                                            Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Video Source (index):",
                "input": VideoSource
            },
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


    def saveDolbyVisionValues(self, VideoSource: str = "VIDEO_SOURCE_IP", pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD", dolbyVisionModeIndex: str = "tvDolbyMode_Dark"):
        """
        Saves Dolby Vision values.

        Args:
            VideoSource (str, optional): The video source to be used.
                                        Defaults to "VIDEO_SOURCE_IP".
            pictureModeIndex (str, optional): Your choice of Picture Mode index.
                                            Defaults to "PQ_MODE_STANDARD".
            videoFormatIndex (str, optional): Your choice of Video Format index.
                                            Defaults to "PQ_MODE_STANDARD".
            dolbyVisionModeIndex (str, optional): Your choice of Dolby Vision Mode index.
                                                Defaults to "tvDolbyMode_Dark".

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Video Source (index):",
                "input": VideoSource
            },
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

        result = self.utMenu.select(self.testSuite, "Save Dolby Vision", promptWithAnswers)

    def savePictureMode(self, VideoSource: str = "VIDEO_SOURCE_IP", pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD"):
        """
        Saves the Picture Mode.

        Args:
            VideoSource (str, optional): The video source to be used.
                                        Defaults to "VIDEO_SOURCE_IP".
            pictureModeIndex (str, optional): Your choice of Picture Mode index.
                                            Defaults to "PQ_MODE_STANDARD".
            videoFormatIndex (str, optional): Your choice of Video Format index.
                                            Defaults to "PQ_MODE_STANDARD".

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Video Source (index):",
                "input": VideoSource
            },
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


    def saveDvTmaxValue(self, dimmingLevelIndex: str = "LDIM_STATE_NONBOOST", tmaxValue: int = 5000):
        """
        Saves the Dolby Vision TMAX value for a specific LDIM state.

        This function allows you to set the TMAX value for a specific LDIM state level.
        The saved TMAX value will be applied in Dolby Vision core whenever the specified LDIM state level is selected
        as a result of a picture mode change or primary video source change.

        Args:
            dimmingLevelIndex (str, optional): The LDIM state level to use. Default is "LDIM_STATE_NONBOOST".
                                            Valid values should correspond to available LDIM states (e.g., "LDIM_STATE_BOOST", "LDIM_STATE_NONBOOST").
            tmaxValue (int, optional): The TMAX value to set, which determines the maximum brightness for Dolby Vision.
                                    Valid range is between 0 and 10000. Default is 5000.

        Returns:
            None: The function does not return a value. It performs the action of saving the TMAX value for the specified LDIM state.

        Example:
            saveDvTmaxValue(dimmingLevelIndex="LDIM_STATE_BOOST", tmaxValue=7500)
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of LDIM State Level (index):",
                "input": dimmingLevelIndex
            },
            {
                "query_type": "direct",
                "query": "Enter the TMAX value to set (0 - 10000):",
                "input": str(tmaxValue)
            }
        ]

        # Use the prompt to select and set the TMAX value
        result = self.utMenu.select(self.testSuite, "Save DV Tmax", promptWithAnswers)


    def getBacklightMode(self):
        """
        Gets the Backlight Mode.

        Args:
            None.

        Returns:
            list : List of Backlight Modes.
        """
        # Get the Backlight Mode index from the profile
        backlightModes = self.deviceProfile.BacklightControl.index

        # Check if index is valid
        if backlightModes is None:
            return []

        outBacklightMode = []
        for backlightMode in backlightModes:
            outBacklightMode.append(tvBacklightMode(backlightMode).name)
        return outBacklightMode


    def saveCMS(self, VideoSource: str = "VIDEO_SOURCE_IP", pictureModeIndex: str = "PQ_MODE_STANDARD", videoFormatIndex: str = "PQ_MODE_STANDARD", componentType: str = "COMP_NONE", componentColor: str = "tvDataColor_RED", cmsValue: int = 0):
        """
        Saves the CMS settings.

        Args:
            VideoSource (str, optional): The video source to be used.
                                        Defaults to "VIDEO_SOURCE_IP".
            pictureModeIndex (str, optional): Your choice of Picture Mode index.
                                            Defaults to "PQ_MODE_STANDARD".
            videoFormatIndex (str, optional): Your choice of Video Format index.
                                            Defaults to "PQ_MODE_STANDARD".
            componentType (str, optional): The component type. Defaults to "COMP_NONE".
            componentColor (str, optional): The component color. Defaults to "tvDataColor_RED".
            cmsValue (int, optional): The CMS value (0 - 100). Defaults to 0.

        Returns:
            None
        """
        promptWithAnswers = [
            {
                "query_type": "list",
                "query": "Enter your choice of Video Source (index):",
                "input": VideoSource
            },
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
            list : list of Dimming Modes
        """
        # Get the Back light Mode index from the profile
        TVDimmingModes = self.deviceProfile.DimmingMode.index

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
            list  : list of Local Dimming Modes
        """
        # Get the Back light Mode index from the profile
        LocalDimmingModes = self.deviceProfile.LocalDimmingLevel.index

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
            list : list of ColorTemperatures
        """
        # Get the color temperature index from the profile
        ColorTempIndex = self.deviceProfile.ColorTemperature.index

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
            list : list ofAspect Ratio
        """
        # Get the color temperature index from the profile
        AspectRatioIndex = self.deviceProfile.AspectRatio.index

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
            list : list ofDolby Visions
        """
        # Get the Dolby Vision index from the profile
        DolbyVisionMode = self.deviceProfile.DolbyVisionMode.index

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
            list : list ofPicture Modes
        """
        # Get the Picture Mode index from the profile
        PictureMode = self.deviceProfile.PictureMode.range
        return PictureMode

    def getPictureModeIndex(self):
        """
        Gets the Picture Modes.

        Args:
            None.

        Returns:
            list : list ofPicture Modes
        """
        # Get the Picture Mode index from the profile
        PictureMode = self.deviceProfile.PictureMode.index

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
            list : list ofList of Video Formats.
        """
        # Get the Video Format index from the profile
        videoFormatIndex = self.deviceProfile.VideoFormat.index

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
        videoSourceIndex = self.deviceProfile.VideoSource.index

        # Check if index is valid
        if videoSourceIndex is None:
            return []

        outVideoSources = []
        for videoSource in videoSourceIndex:
                outVideoSources.append(TvVideoSrcType(videoSource).name)
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
        videoFrameRateIndex = self.deviceProfile.SupportedVideoFrameRate

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
        video_resolution_index = self.deviceProfile.SupportedVideoResolution

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
        videoFrameRateIndex = self.deviceProfile.SupportedVideoFrameRate

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
                outTVDataColors.append(color.name)

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

        formatCallbackPattern = r"Received Video Format Change callback format:\[(\w+)\]"

        return self.searchPattern(result, formatCallbackPattern)


    def getVideoResolutionCallbackStatus(self):
        """
        Retrieves the video resolution from a system callback.

        Args:
            None.

        Returns:
            None: If the function fails to retrieve the callback status.
            tuple: A tuple containing the frame resolution name, height, width, interlaced status, and user data, as indicated by the system callback.
        """
        result = self.testSession.read_until("Received Video Resolution Change callback Frame heightxwidth")

        # Updated regex pattern to capture all required data
        formatCallbackPattern = r"Received Video Resolution Change callback Frame Res:\[(\w+)\], widthxheight:\[(\d+)x(\d+)\], IsIntercaed\[(\d+)\]"

        # Use re.search to find the pattern in the result
        match = re.search(formatCallbackPattern, result)

        if match:
            # Return a tuple of the captured groups
            resolution_name = match.group(1)
            width = int(match.group(2))
            height = int(match.group(3))
            is_interlaced = int(match.group(4))

            return (resolution_name, width, height, is_interlaced)

        return None


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

        formatCallbackPattern = r"Received Video Content Change callback format:\[(\w+)\]"

        return self.searchPattern(result, formatCallbackPattern)


    def getCMSStateStatus(self):
        """
        Retrieves the CMS state from the system logs.

        Args:
            None.

        Returns:
            int: 1 if CMS state is "Enabled", 0 if "Disabled".
            None: If the function fails to retrieve the CMS state.
        """
        # Use the same utMenu.select structure to interact
        result = self.utMenu.select(self.testSuite, "Get CMS State")

        # Define a pattern to match the CMS state ("Enabled" or "Disabled")
        cmsStatePattern = r"Result GetCMSState\(OUT: retrievedCMSState\[(Enabled|Disabled)\]"

        # Search the result for the CMS state
        match = re.search(cmsStatePattern, result)
        if match:
            cmsState = match.group(1)
            return 1 if cmsState == "Enabled" else 0
        else:
            self.log.error("Failed to retrieve CMS state from logs.")
            return None


    def terminate(self):
        """
        Enables the tvSettings port.

        Args:
            None.

        Returns:
            None
        """
        result = self.utMenu.select(self.testSuite, "Terminate")

# Test and example usage code
if __name__ == '__main__':

    shell = InteractiveShell()
    shell.open()

    platformProfile = dir_path + "/../../../profiles/sink/Sink_4K_TvSettings.yaml"
    # test the class assuming that it's optional
    test = tvSettingsClass(platformProfile, shell)

    test.initialise()
    ports = test.getVideoFormatInfo

    test.terminate()

    shell.close()