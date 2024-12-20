/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:*
* Copyright 2024 RDK Management
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

/**
 * @addtogroup HPK Hardware Porting Kit
 * @{
 * @par The Hardware Porting Kit
 * HPK is the next evolution of the well-defined Hardware Abstraction Layer
 * (HAL), but augmented with more comprehensive documentation and test suites
 * that OEM or SOC vendors can use to self-certify their ports before taking
 * them to RDKM for validation or to an operator for final integration and
 * deployment. The Hardware Porting Kit effectively enables an OEM and/or SOC
 * vendor to self-certify their own Video Accelerator devices, with minimal RDKM
 * assistance.
 *
 */

/**
 * @addtogroup TV_Settings TV Settings Module
 * @{
 */

/**
 * @addtogroup TV_Settings_HALTEST TV Settings HAL Tests
 * @{
 */

/**
 * @defgroup TV_Settings_HALTEST_L3 TV Settings HAL Tests L3 File
 *  @{
 * @parblock
 *
 * ### L3 Tests for TV_Settings HAL :
 *
 * This is to ensure that the API meets the operational requirements of the module across all vendors.
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 *
 * Refer to Device Settings HAL Documentation Guide : [tv-settings_halSpec.md](../../docs/pages/tv-settings_halSpec.md)
 *
 * @endparblock
 */


/**
* @file test_l3_tvSettings.c
*
*/
#include <ut.h>
#include <ut_log.h>
#include <ut_kvp_profile.h>
#include <ut_control_plane.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <pthread.h>
#include "tvSettings.h"

#define UT_LOG_MENU_INFO UT_LOG_INFO
#define ASSERT assert
#define MAX_FILE_SIZE 64
#define ASSERT_COMPARE(var1, var2) \
    do \
    { \
        if ((var1) != (var2)) \
        { \
            UT_LOG_ERROR("Mismatch: %s != %s at %s:%d\n", #var1, #var2, __FILE__, __LINE__); \
        } \
    } while (0)

#define ASSERT_STRING_COMPARE(str1, str2, n) \
    do \
    { \
        const char *s1 = (str1) ? (str1) : "(NULL)"; \
        const char *s2 = (str2) ? (str2) : "(NULL)"; \
        if (!(str1 && str2 && strncmp(s1, s2, (n)) == 0)) \
        { \
            UT_LOG_ERROR("Mismatch: \"%s\" != \"%s\" at %s:%d\n", s1, s2, __FILE__, __LINE__); \
        } \
    } while (0)


#define TVSETTINGS_FORMAT_CB_FILE "tvSettings_formatChangeStatus.txt"
#define TVSETTINGS_CONTENT_CB_FILE "tvSettings_contentChangeStatus.txt"
#define TVSETTINGS_RESOLUTION_CB_FILE "tvSettings_resolutionChangeStatus.txt"
#define TVSETTINGS_FRAMERATE_CB_FILE "tvSettings_frameRateChangeStatus.txt"

/* Global Variables */
static int32_t gTestGroup = 3;
static int32_t gTestID    = 1;

static char gFormatChangeCBFile[MAX_FILE_SIZE];
static char gContentChangeCBFile[MAX_FILE_SIZE];
static char gResolutionChangeCBFile[MAX_FILE_SIZE];
static char gFrameRateChangeCBFile[MAX_FILE_SIZE];
static pthread_mutex_t gCallbackMutex = PTHREAD_MUTEX_INITIALIZER;

/* tvBacklightTestMode_t */
const static ut_control_keyStringMapping_t  tvBacklightTestMode_mapTable [] =
{
    { "tvBacklightTestMode_Normal", (int32_t)tvBacklightTestMode_Normal },
    { "tvBacklightTestMode_Boost",  (int32_t)tvBacklightTestMode_Boost  },
    { "tvBacklightTestMode_Burst",  (int32_t)tvBacklightTestMode_Burst  },
    { "tvBacklightTestMode_Reset",  (int32_t)tvBacklightTestMode_Reset  },
    { "tvBacklightTestMode_Max",    (int32_t)tvBacklightTestMode_Max    },
    {  NULL,                       -1                                  }
};

/*tvDataComponentColor_t*/
const static ut_control_keyStringMapping_t  tvDataComponentColor_mapTable [] =
{
    { "tvDataColor_NONE",     (int32_t)tvDataColor_NONE     },
    { "tvDataColor_RED",      (int32_t)tvDataColor_RED      },
    { "tvDataColor_GREEN",    (int32_t)tvDataColor_GREEN    },
    { "tvDataColor_BLUE",     (int32_t)tvDataColor_BLUE     },
    { "tvDataColor_YELLOW",   (int32_t)tvDataColor_YELLOW   },
    { "tvDataColor_CYAN",     (int32_t)tvDataColor_CYAN     },
    { "tvDataColor_MAGENTA",  (int32_t)tvDataColor_MAGENTA  },
    { "tvDataColor_MAX",      (int32_t)tvDataColor_MAX      },
    {  NULL,                  -1                            }
};

/* tvColorTempSourceOffset_t */
const static ut_control_keyStringMapping_t  tvColorTempSourceOffset_mapTable [] =
{
    { "ALL_SRC_OFFSET",   (int32_t)ALL_SRC_OFFSET   },
    { "HDMI_OFFSET",      (int32_t)HDMI_OFFSET      },
    { "TV_OFFSET",        (int32_t)TV_OFFSET        },
    { "AV_OFFSET",        (int32_t)AV_OFFSET        },
    { "MAX_OFFSET",       (int32_t)MAX_OFFSET       },
    {  NULL,              -1                        }
};

/* tvDolbyMode_t */
const static ut_control_keyStringMapping_t  tvDolbyMode_mapTable [] =
{
    { "tvDolbyMode_Invalid",         (int32_t)tvDolbyMode_Invalid         },
    { "tvDolbyMode_Dark",            (int32_t)tvDolbyMode_Dark            },
    { "tvDolbyMode_Bright",          (int32_t)tvDolbyMode_Bright          },
    { "tvDolbyMode_Game",            (int32_t)tvDolbyMode_Game            },
    { "tvHDR10Mode_Dark",            (int32_t)tvHDR10Mode_Dark            },
    { "tvHDR10Mode_Bright",          (int32_t)tvHDR10Mode_Bright          },
    { "tvHDR10Mode_Game",             (int32_t)tvHDR10Mode_Game           },
    { "tvHLGMode_Dark",              (int32_t)tvHLGMode_Dark              },
    { "tvHLGMode_Bright",            (int32_t)tvHLGMode_Bright            },
    { "tvHLGMode_Game",              (int32_t)tvHLGMode_Game              },
    { "tvMode_Max",                  (int32_t)tvMode_Max                  },
    {  NULL,                         -1                                   }
};

/* tvDisplayMode_t */
const static ut_control_keyStringMapping_t  tvDisplayMode_mapTable [] =
{
    { "tvDisplayMode_4x3",        (int32_t)tvDisplayMode_4x3        },
    { "tvDisplayMode_16x9",       (int32_t)tvDisplayMode_16x9       },
    { "tvDisplayMode_FULL",       (int32_t)tvDisplayMode_FULL       },
    { "tvDisplayMode_NORMAL",     (int32_t)tvDisplayMode_NORMAL     },
    { "tvDisplayMode_AUTO",       (int32_t)tvDisplayMode_AUTO       },
    { "tvDisplayMode_DIRECT",     (int32_t)tvDisplayMode_DIRECT     },
    { "tvDisplayMode_ZOOM",       (int32_t)tvDisplayMode_ZOOM       },
    { "tvDisplayMode_MAX",        (int32_t)tvDisplayMode_MAX        },
    {  NULL,                      -1                                }
};

/* ldimStateLevel_t */
const static ut_control_keyStringMapping_t  ldimStateLevel_mapTable[] =
{
    { "LDIM_STATE_NONBOOST", (int32_t)LDIM_STATE_NONBOOST },
    { "LDIM_STATE_BOOST",    (int32_t)LDIM_STATE_BOOST    },
    { "LDIM_STATE_BURST",    (int32_t)LDIM_STATE_BURST    },
    { "LDIM_STATE_MAX",      (int32_t)LDIM_STATE_MAX      },
    { NULL,                  -1                           }
};

/* tvBacklightMode_t  */
const static ut_control_keyStringMapping_t  tvBacklightMode_mapTable [] =
{
    { "tvBacklightMode_NONE",     (int32_t)tvBacklightMode_NONE     },
    { "tvBacklightMode_MANUAL",   (int32_t)tvBacklightMode_MANUAL   },
    { "tvBacklightMode_AMBIENT",  (int32_t)tvBacklightMode_AMBIENT  },
    { "tvBacklightMode_ECO",      (int32_t)tvBacklightMode_ECO      },
    { "tvBacklightMode_INVALID",  (int32_t)tvBacklightMode_INVALID  },
    { "tvBacklightMode_MAX",      (int32_t)tvBacklightMode_MAX      },
    {  NULL,                      -1                                }
};

/* tvVideoSrcType_t */
const static ut_control_keyStringMapping_t  tvVideoSrcType_mapTable[] =
{
    { "VIDEO_SOURCE_ALL",        (int32_t)VIDEO_SOURCE_ALL        },
    { "VIDEO_SOURCE_ANALOGUE",   (int32_t)VIDEO_SOURCE_ANALOGUE   },
    { "VIDEO_SOURCE_COMPOSITE1", (int32_t)VIDEO_SOURCE_COMPOSITE1 },
    { "VIDEO_SOURCE_COMPOSITE2", (int32_t)VIDEO_SOURCE_COMPOSITE2 },
    { "VIDEO_SOURCE_YPBPR1",     (int32_t)VIDEO_SOURCE_YPBPR1     },
    { "VIDEO_SOURCE_YPBPR2",     (int32_t)VIDEO_SOURCE_YPBPR2     },
    { "VIDEO_SOURCE_HDMI1",      (int32_t)VIDEO_SOURCE_HDMI1      },
    { "VIDEO_SOURCE_HDMI2",      (int32_t)VIDEO_SOURCE_HDMI2      },
    { "VIDEO_SOURCE_HDMI3",      (int32_t)VIDEO_SOURCE_HDMI3      },
    { "VIDEO_SOURCE_HDMI4",      (int32_t)VIDEO_SOURCE_HDMI4      },
    { "VIDEO_SOURCE_VGA",        (int32_t)VIDEO_SOURCE_VGA        },
    { "VIDEO_SOURCE_IP",         (int32_t)VIDEO_SOURCE_IP         },
    { "VIDEO_SOURCE_TUNER",      (int32_t)VIDEO_SOURCE_TUNER      },
    { "VIDEO_SOURCE_SVIDEO",     (int32_t)VIDEO_SOURCE_SVIDEO     },
    { "VIDEO_SOURCE_RESERVED",   (int32_t)VIDEO_SOURCE_RESERVED   },
    { "VIDEO_SOURCE_RESERVED1",  (int32_t)VIDEO_SOURCE_RESERVED1  },
    { "VIDEO_SOURCE_RESERVED2",  (int32_t)VIDEO_SOURCE_RESERVED2  },
    { "VIDEO_SOURCE_RESERVED3",  (int32_t)VIDEO_SOURCE_RESERVED3  },
    { "VIDEO_SOURCE_MAX",        (int32_t)VIDEO_SOURCE_MAX        },
    { NULL, -1 }
};

/* tvVideoFrameRate_t */
const static ut_control_keyStringMapping_t  tvVideoFrameRate_mapTable[] =
{
    { "tvVideoFrameRate_NONE",    (int32_t)tvVideoFrameRate_NONE    },
    { "tvVideoFrameRate_24",      (int32_t)tvVideoFrameRate_24      },
    { "tvVideoFrameRate_25",      (int32_t)tvVideoFrameRate_25      },
    { "tvVideoFrameRate_30",      (int32_t)tvVideoFrameRate_30      },
    { "tvVideoFrameRate_50",      (int32_t)tvVideoFrameRate_50      },
    { "tvVideoFrameRate_60",      (int32_t)tvVideoFrameRate_60      },
    { "tvVideoFrameRate_23dot98", (int32_t)tvVideoFrameRate_23dot98 },
    { "tvVideoFrameRate_29dot97", (int32_t)tvVideoFrameRate_29dot97 },
    { "tvVideoFrameRate_59dot94", (int32_t)tvVideoFrameRate_59dot94 },
    { "tvVideoFrameRate_MAX",     (int32_t)tvVideoFrameRate_MAX     },
    { NULL, -1 }
};

/* tvVideoResolution_t */
const static ut_control_keyStringMapping_t  tvVideoResolution_mapTable[] =
{
    { "tvVideoResolution_NONE",        (int32_t)tvVideoResolution_NONE        },
    { "tvVideoResolution_720x240",     (int32_t)tvVideoResolution_720x240     },
    { "tvVideoResolution_2880x240",    (int32_t)tvVideoResolution_2880x240    },
    { "tvVideoResolution_720x288",     (int32_t)tvVideoResolution_720x288     },
    { "tvVideoResolution_2880x288",    (int32_t)tvVideoResolution_2880x288    },
    { "tvVideoResolution_640x480",     (int32_t)tvVideoResolution_640x480     },
    { "tvVideoResolution_720x480",     (int32_t)tvVideoResolution_720x480     },
    { "tvVideoResolution_800x480",     (int32_t)tvVideoResolution_800x480     },
    { "tvVideoResolution_852x480",     (int32_t)tvVideoResolution_852x480     },
    { "tvVideoResolution_854x480",     (int32_t)tvVideoResolution_854x480     },
    { "tvVideoResolution_1440x480",    (int32_t)tvVideoResolution_1440x480    },
    { "tvVideoResolution_2880x480",    (int32_t)tvVideoResolution_2880x480    },
    { "tvVideoResolution_960x540",     (int32_t)tvVideoResolution_960x540     },
    { "tvVideoResolution_3840x540",    (int32_t)tvVideoResolution_3840x540    },
    { "tvVideoResolution_720x576",     (int32_t)tvVideoResolution_720x576     },
    { "tvVideoResolution_1440x576",    (int32_t)tvVideoResolution_1440x576    },
    { "tvVideoResolution_2880x576",    (int32_t)tvVideoResolution_2880x576    },
    { "tvVideoResolution_800x600",     (int32_t)tvVideoResolution_800x600     },
    { "tvVideoResolution_1024x600",    (int32_t)tvVideoResolution_1024x600    },
    { "tvVideoResolution_1280x600",    (int32_t)tvVideoResolution_1280x600    },
    { "tvVideoResolution_1280x720",    (int32_t)tvVideoResolution_1280x720    },
    { "tvVideoResolution_1280x1024",   (int32_t)tvVideoResolution_1280x1024   },
    { "tvVideoResolution_1680x720",    (int32_t)tvVideoResolution_1680x720    },
    { "tvVideoResolution_1024x768",    (int32_t)tvVideoResolution_1024x768    },
    { "tvVideoResolution_1280x768",    (int32_t)tvVideoResolution_1280x768    },
    { "tvVideoResolution_1360x768",    (int32_t)tvVideoResolution_1360x768    },
    { "tvVideoResolution_1366x768",    (int32_t)tvVideoResolution_1366x768    },
    { "tvVideoResolution_1440x900",    (int32_t)tvVideoResolution_1440x900    },
    { "tvVideoResolution_1600x900",    (int32_t)tvVideoResolution_1600x900    },
    { "tvVideoResolution_1280x960",    (int32_t)tvVideoResolution_1280x960    },
    { "tvVideoResolution_1920x1080",   (int32_t)tvVideoResolution_1920x1080   },
    { "tvVideoResolution_2560x1080",   (int32_t)tvVideoResolution_2560x1080   },
    { "tvVideoResolution_3840x1080",   (int32_t)tvVideoResolution_3840x1080   },
    { "tvVideoResolution_1600x1200",   (int32_t)tvVideoResolution_1600x1200   },
    { "tvVideoResolution_1920x1200",   (int32_t)tvVideoResolution_1920x1200   },
    { "tvVideoResolution_2160x1200",   (int32_t)tvVideoResolution_2160x1200   },
    { "tvVideoResolution_2400x1200",   (int32_t)tvVideoResolution_2400x1200   },
    { "tvVideoResolution_2560x1440",   (int32_t)tvVideoResolution_2560x1440   },
    { "tvVideoResolution_3440x1440",   (int32_t)tvVideoResolution_3440x1440   },
    { "tvVideoResolution_3840x2160",   (int32_t)tvVideoResolution_3840x2160   },
    { "tvVideoResolution_4096x2160",   (int32_t)tvVideoResolution_4096x2160   },
    { "tvVideoResolution_MAX",         (int32_t)tvVideoResolution_MAX         },
    { NULL, -1 }
};

/* tvContentType_t */
const static ut_control_keyStringMapping_t  tvContentType_mapTable[] =
{
    { "tvContentType_NONE", (int32_t)tvContentType_NONE },
    { "tvContentType_FMM",  (int32_t)tvContentType_FMM  },
    { "tvContentType_MAX",  (int32_t)tvContentType_MAX  },
    { NULL, -1 }
};

/* tvVideoFormatType_t */
const static ut_control_keyStringMapping_t  tvVideoFormatType_mapTable[] =
{
    { "VIDEO_FORMAT_NONE",       (int32_t)VIDEO_FORMAT_NONE       },
    { "VIDEO_FORMAT_HDR10",      (int32_t)VIDEO_FORMAT_HDR10      },
    { "VIDEO_FORMAT_HDR10PLUS",  (int32_t)VIDEO_FORMAT_HDR10PLUS  },
    { "VIDEO_FORMAT_DV",         (int32_t)VIDEO_FORMAT_DV         },
    { "VIDEO_FORMAT_PRIMESL",    (int32_t)VIDEO_FORMAT_PRIMESL    },
    { "VIDEO_FORMAT_HLG",        (int32_t)VIDEO_FORMAT_HLG        },
    { "VIDEO_FORMAT_SDR",        (int32_t)VIDEO_FORMAT_SDR        },
    { "VIDEO_FORMAT_MVC",        (int32_t)VIDEO_FORMAT_MVC        },
    { "VIDEO_FORMAT_MAX",        (int32_t)VIDEO_FORMAT_MAX        },
    { NULL, -1 }
};

/* tvError_t */
const static ut_control_keyStringMapping_t  tvError_mapTable [] =
{
  { "tvERROR_NONE",                      (int32_t)tvERROR_NONE                     },
  { "tvERROR_GENERAL",                   (int32_t)tvERROR_GENERAL                  },
  { "tvERROR_OPERATION_NOT_SUPPORTED",   (int32_t)tvERROR_OPERATION_NOT_SUPPORTED  },
  { "tvERROR_INVALID_PARAM",             (int32_t)tvERROR_INVALID_PARAM            },
  { "tvERROR_INVALID_STATE",             (int32_t)tvERROR_INVALID_STATE            },
  {  NULL, -1 }
};

/* tvColorTemp_t */
const static ut_control_keyStringMapping_t  tvColorTemp_mapTable [] =
{
    { "tvColorTemp_STANDARD",         (int32_t)tvColorTemp_STANDARD         },
    { "tvColorTemp_WARM",             (int32_t)tvColorTemp_WARM             },
    { "tvColorTemp_COLD",             (int32_t)tvColorTemp_COLD             },
    { "tvColorTemp_USER",             (int32_t)tvColorTemp_USER             },
    { "tvColorTemp_BOOST_STANDARD",   (int32_t)tvColorTemp_BOOST_STANDARD   },
    { "tvColorTemp_BOOST_WARM",       (int32_t)tvColorTemp_BOOST_WARM       },
    { "tvColorTemp_BOOST_COLD",       (int32_t)tvColorTemp_BOOST_COLD       },
    { "tvColorTemp_BOOST_USER",       (int32_t)tvColorTemp_BOOST_USER       },
    { "tvColorTemp_SUPERCOLD",        (int32_t)tvColorTemp_SUPERCOLD        },
    { "tvColorTemp_BOOST_SUPERCOLD",  (int32_t)tvColorTemp_BOOST_SUPERCOLD  },
    { "tvColorTemp_MAX",              (int32_t)tvColorTemp_MAX              },
    {  NULL,                          -1                                    }
};

/* tvDimmingMode_t */
const static ut_control_keyStringMapping_t  tvDimmingMode_mapTable [] =
{
    { "tvDimmingMode_Fixed",   (int32_t)tvDimmingMode_Fixed   },
    { "tvDimmingMode_Local",   (int32_t)tvDimmingMode_Local   },
    { "tvDimmingMode_Global",  (int32_t)tvDimmingMode_Global  },
    { "tvDimmingMode_MAX",     (int32_t)tvDimmingMode_MAX     },
    {  NULL,                   -1                              }
};

/* tvPQModeIndex_t */
const static ut_control_keyStringMapping_t  tvPQModeIndex_mapTable [] =
{
    { "PQ_MODE_INVALID",         (int32_t)PQ_MODE_INVALID         },
    { "PQ_MODE_STANDARD",        (int32_t)PQ_MODE_STANDARD        },
    { "PQ_MODE_VIVID",           (int32_t)PQ_MODE_VIVID           },
    { "PQ_MODE_ENERGY_SAVING",   (int32_t)PQ_MODE_ENERGY_SAVING   },
    { "PQ_MODE_CUSTOM",          (int32_t)PQ_MODE_CUSTOM          },
    { "PQ_MODE_THEATER",         (int32_t)PQ_MODE_THEATER         },
    { "PQ_MODE_RESERVED1",       (int32_t)PQ_MODE_RESERVED1       },
    { "PQ_MODE_RESERVED2",       (int32_t)PQ_MODE_RESERVED2       },
    { "PQ_MODE_GAME",            (int32_t)PQ_MODE_GAME            },
    { "PQ_MODE_SPORTS",          (int32_t)PQ_MODE_SPORTS          },
    { "PQ_MODE_GRAPHICS",        (int32_t)PQ_MODE_GRAPHICS        },
    { "PQ_MODE_FMM",             (int32_t)PQ_MODE_FMM             },
    { "PQ_MODE_VIVID2",          (int32_t)PQ_MODE_VIVID2          },
    { "PQ_MODE_MAX",             (int32_t)PQ_MODE_MAX             },
    {  NULL,                     -1                               }
};

/* tvPQModeIndex_t */
const static ut_control_keyStringMapping_t  tvPQModeRange_mapTable [] =
{
    { "standard",        (int32_t)PQ_MODE_STANDARD        },
    { "vivid",           (int32_t)PQ_MODE_VIVID           },
    { "energysaving",    (int32_t)PQ_MODE_ENERGY_SAVING   },
    { "custom",          (int32_t)PQ_MODE_CUSTOM          },
    { "theater",         (int32_t)PQ_MODE_THEATER         },
    { "reserved1",       (int32_t)PQ_MODE_RESERVED1       },
    { "reserved2",       (int32_t)PQ_MODE_RESERVED2       },
    { "game",            (int32_t)PQ_MODE_GAME            },
    { "sports",          (int32_t)PQ_MODE_SPORTS          },
    { "graphics",        (int32_t)PQ_MODE_GRAPHICS        },
    { "fmm",             (int32_t)PQ_MODE_FMM             },
    { "vivid2",          (int32_t)PQ_MODE_VIVID2          },
    {  NULL,             -1                               }
};

/* tvComponentType_t */
const static ut_control_keyStringMapping_t  tvComponentType_mapTable [] =
{
    { "COMP_NONE",        (int32_t)COMP_NONE        },
    { "COMP_HUE",         (int32_t)COMP_HUE         },
    { "COMP_SATURATION",  (int32_t)COMP_SATURATION  },
    { "COMP_LUMA",        (int32_t)COMP_LUMA        },
    { "COMP_MAX",         (int32_t)COMP_MAX         },
    {  NULL,              -1                       }
};

/**
 * @brief This function clears the stdin buffer.
 *
 * This function clears the stdin buffer.
 */
static void readAndDiscardRestOfLine(FILE* in)
{
   int32_t c;
   while ( (c = fgetc(in)) != EOF && c != '\n');
}
/**
 * @brief This function gets the integer Input value.
 *
 */
static void readInt(int32_t *choice)
{
    scanf("%d", choice);
    readAndDiscardRestOfLine(stdin);
}
/**
 * @brief This function gets the double Input value.
 *
 */
static void readDouble(double *choice)
{
    scanf("%lf", choice);
    readAndDiscardRestOfLine(stdin);
}
/**
 * @brief This function logs the callback.
 *
 */

static void writeCallbackLog(char *logPath, const char *format, ...)
{
    va_list args;
    va_start(args, format);


    // Get the current timestamp in seconds and microseconds
    struct timeval tv;
    gettimeofday(&tv, NULL);

    // Format the timestamp with year, month, day, time, and microseconds
    char timestamp[64];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&tv.tv_sec));

    // Append the microseconds to the timestamp
    snprintf(&timestamp[strlen(timestamp)], sizeof(timestamp) - strlen(timestamp), ".%06ld", tv.tv_usec);

    pthread_mutex_lock(&gCallbackMutex);

    // Open the log file in append mode
    FILE *fp = fopen(logPath, "a");
    if (fp == NULL) {
        fprintf(stderr, "Error opening log file: %s\n", strerror(errno));
        return;
    }

    // Print the timestamp and formatted message
    fprintf(fp, "[%s] ", timestamp);
    vfprintf(fp, format, args);
    fprintf(fp, "\n");

    // Close the log file
    fclose(fp);

    pthread_mutex_unlock(&gCallbackMutex);

    va_end(args);
}


/**
 * @brief Callback function for change in the video format.
 *
 * This function is invoked whenever a change occurs in the Video Format.
 */
static void videoFormatChangeCB (tvVideoFormatType_t format, void *userData)
{
    UT_LOG_INFO("Received Video Format Change callback format:[%s], userData[%s][0x%0X]",
                 UT_Control_GetMapString(tvVideoFormatType_mapTable, format),(char *)userData,userData);

    writeCallbackLog(gFormatChangeCBFile, "Received Video Format Change callback format:[%s], userData[%s][0x%0X]",
                 UT_Control_GetMapString(tvVideoFormatType_mapTable, format),(char *)userData,userData);


}

/**
 * @brief Callback function for change in the video content.
 *
 * This function is invoked whenever a change occurs in the video content.
 */
static void videoContentChangeCB (tvContentType_t mode, void *userData)
{
    UT_LOG_INFO("Received Video Content Change callback format:[%s], userData[%s][0x%0X]",
                 UT_Control_GetMapString(tvContentType_mapTable, mode),(char *)userData,userData);

    writeCallbackLog(gContentChangeCBFile, "Received Video Content Change callback format:[%s], userData[%s][0x%0X]",
                 UT_Control_GetMapString(tvContentType_mapTable, mode),(char *)userData,userData);

}

/**
 * @brief Callback function for change in the video Resolution.
 *
 * This function is invoked whenever a change occurs in the video Resolution.
 */
static void videoResolutionChangeCB (tvResolutionParam_t resolutionStruct, void *userData)
{
    UT_LOG_INFO("Received Video Resolution Change callback Frame Res:[%s], widthxheight:[%dx%d], IsIntercaed[%d], userData[%s][0x%0X]",
                UT_Control_GetMapString(tvVideoResolution_mapTable, resolutionStruct.resolutionValue),
                 resolutionStruct.frameWidth,
                 resolutionStruct.frameHeight,
                resolutionStruct.isInterlaced,
                (char *)userData,
                userData);

    writeCallbackLog(gResolutionChangeCBFile, "Received Video Resolution Change callback Frame heightxwidth:[%dx%d], IsIntercaed[%d] Res:[%s], userData[%s][0x%0X]",
                 resolutionStruct.frameHeight,
                 resolutionStruct.frameWidth,
                resolutionStruct.isInterlaced,
                UT_Control_GetMapString(tvVideoResolution_mapTable, resolutionStruct.resolutionValue),
                (char *)userData,
                userData);

}

/**
 * @brief Callback function for change in the video Frame Rate.
 *
 * This function is invoked whenever a change occurs in the video Frame Rate.
 */
static void videoFrameRateChangeCB (tvVideoFrameRate_t frameRate, void *userData)
{
    UT_LOG_INFO("Received Video Frame Rate Change callback format:[%s], userData[%s][0x%0X]",
                 UT_Control_GetMapString(tvVideoFrameRate_mapTable, frameRate),(char *)userData,userData);

    writeCallbackLog(gFrameRateChangeCBFile, "Received Video Frame Rate Change callback format:[%s], userData[%s][0x%0X]",
                 UT_Control_GetMapString(tvVideoFrameRate_mapTable, frameRate),(char *)userData,userData);
}

/**
* @brief This test initializes the tvSettings Module.
*
* This test function initializes the tvSettings Module.
*
* **Test Group ID:** 03@n
* **Test Case ID:** 001@n
*
* **Test Procedure:**
* Refer to Test specification documentation
* [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
*/
void test_l3_tvSettings_initialize(void)
{
    gTestID = 1;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    tvError_t ret = tvERROR_NONE;
    tvVideoFormatCallbackData videoFormatCallbackData = {0};
    tvVideoContentCallbackData videoContentCallbackData = {0};
    tvVideoResolutionCallbackData videoResolutionCallbackData = {0};
    tvVideoFrameRateCallbackData videoFrameRateCallbackData = {0};
    char videoFormatChangeData[] = "videoFormatChange";
    char videoContentData[] = "videoContentChange";
    char videoResolutionData[] = "videoResolutionChange";
    char videoFrameRateData[] = "videoFrameRateChange";

    strncpy(gFormatChangeCBFile,TVSETTINGS_FORMAT_CB_FILE, MAX_FILE_SIZE);
    strncpy(gContentChangeCBFile,TVSETTINGS_FORMAT_CB_FILE, MAX_FILE_SIZE);
    strncpy(gResolutionChangeCBFile,TVSETTINGS_FORMAT_CB_FILE, MAX_FILE_SIZE);
    strncpy(gFrameRateChangeCBFile,TVSETTINGS_FORMAT_CB_FILE, MAX_FILE_SIZE);

    /* Initialize the tvSettings Module */
    UT_LOG_INFO("Calling tvSettingsInit()");
    ret = TvInit();
    ASSERT(ret == tvERROR_NONE);
    UT_LOG_INFO("Result tvSettingsInit tvError_t:[%s]", UT_Control_GetMapString(tvError_mapTable, ret));

    /* Registration for the Video Format */
    videoFormatCallbackData.userdata = videoFormatChangeData;
    videoFormatCallbackData.cb = videoFormatChangeCB;
    UT_LOG_INFO("Calling RegisterVideoFormatChangeCB(IN:UserData:[%s][0x%0X], IN:CBFunc:[0x%0X])", (char *)videoFormatCallbackData.userdata, videoFormatCallbackData.userdata, videoFormatCallbackData.cb);
    ret = RegisterVideoFormatChangeCB(&videoFormatCallbackData);
    ASSERT(ret == tvERROR_NONE);
    UT_LOG_INFO("Result RegisterVideoFormatChangeCB(IN:UserData:[%s], IN:CBFunc:[0x%0X]), tvError_t:[%s]",
               (char *) videoFormatCallbackData.userdata, videoFormatCallbackData.cb, UT_Control_GetMapString(tvError_mapTable, ret));

    /* Registration for the Video Content */
    videoContentCallbackData.userdata = videoContentData;
    videoContentCallbackData.cb = videoContentChangeCB;
    UT_LOG_INFO("Calling RegisterVideoContentChangeCB(IN:UserData:[%s][0x%0X], IN:CBFunc:[0x%0X])",
                videoContentCallbackData.userdata,
                videoContentCallbackData.userdata,
                videoContentCallbackData.cb);
    ret = RegisterVideoContentChangeCB(&videoContentCallbackData);
    ASSERT(ret == tvERROR_NONE);
    UT_LOG_INFO("Result RegisterVideoContentChangeCB(IN:UserData:[%s], IN:CBFunc:[0x%0X]), tvError_t:[%s]",
               (char *) videoContentCallbackData.userdata, videoContentCallbackData.cb, UT_Control_GetMapString(tvError_mapTable, ret));

    /* Registration for Video Resolution */
    videoResolutionCallbackData.userdata = videoResolutionData;
    videoResolutionCallbackData.cb = videoResolutionChangeCB;
    UT_LOG_INFO("Calling RegisterVideoResolutionChangeCB(IN:UserData:[%s][0x%0X], IN:CBFunc:[0x%0X])", (char *) videoResolutionCallbackData.userdata, videoResolutionCallbackData.userdata, videoResolutionCallbackData.cb);
    ret = RegisterVideoResolutionChangeCB(&videoResolutionCallbackData);
    ASSERT(ret == tvERROR_NONE);
    UT_LOG_INFO("Result RegisterVideoResolutionChangeCB(IN:UserData:[%s], IN:CBFunc:[0x%0X]), tvError_t:[%s]",
                (char *)videoResolutionCallbackData.userdata, videoResolutionCallbackData.cb, UT_Control_GetMapString(tvError_mapTable, ret));

    /* Registration for Video Frame Rate Change */
    videoFrameRateCallbackData.userdata = videoFrameRateData;
    videoFrameRateCallbackData.cb = videoFrameRateChangeCB;
    UT_LOG_INFO("Calling RegisterVideoFrameRateChangeCB(IN:UserData:[%s][0x%0X], IN:CBFunc:[0x%0X])", (char *)videoFrameRateCallbackData.userdata, videoFrameRateCallbackData.userdata, videoFrameRateCallbackData.cb);
    ret = RegisterVideoFrameRateChangeCB(&videoFrameRateCallbackData);
    ASSERT(ret == tvERROR_NONE);
    UT_LOG_INFO("Result RegisterVideoFrameRateChangeCB(IN:UserData:[%s], IN:CBFunc:[0x%0X]), tvError_t:[%s]",
               (char *) videoFrameRateCallbackData.userdata, videoFrameRateCallbackData.cb, UT_Control_GetMapString(tvError_mapTable, ret));

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
* @brief This test terminates the tvSettings.
*
* This test function terminates the tvSettings.
*
* **Test Group ID:** 03@n
* **Test Case ID:** 02@n
*
* **Test Procedure:**
* Refer to Test specification documentation
* [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
*/
void test_l3_tvSettings_terminate(void)
{
    gTestID = 2;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);
    tvError_t ret = tvERROR_NONE;

    UT_LOG_INFO("Calling tvSettingsTerm()");
    ret = TvTerm();
    ASSERT(ret == tvERROR_NONE);
    UT_LOG_INFO("Result tvSettingsTerm tvError_t:[%s]", UT_Control_GetMapString(tvError_mapTable, ret));

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
* @brief This test retrieves the current video format.
*
* This test function retrieves the current video format using the `GetCurrentVideoFormat` function.
*
* **Test Group ID:** 03@n
* **Test Case ID:** 03@n
*
* **Test Procedure:**
* Refer to Test specification documentation
* [tvSettings_TestSpecification.md](../docs/pages/tvSettings_TestSpecification.md)
*/
void test_l3_tvSettings_GetVideoFormat(void)
{
    gTestID = 3;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);
    tvError_t ret = tvERROR_NONE;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_MAX;

    UT_LOG_INFO("Calling GetCurrentVideoFormat(OUT:videoFormat:[])");
    ret = GetCurrentVideoFormat(&videoFormat);
    ASSERT(ret == tvERROR_NONE);
    UT_LOG_INFO("Result GetCurrentVideoFormat(OUT:Video Format:[%s]), tvError_t:[%s]",
                UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
                UT_Control_GetMapString(tvError_mapTable, ret));

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
* @brief This test retrieves the current video resolution.
*
* This test function retrieves the current video resolution using the `GetCurrentVideoResolution` function.
*
* **Test Group ID:** 03@n
* **Test Case ID:** 04@n
*
* **Test Procedure:**
* Refer to Test specification documentation
* [tvSettings_TestSpecification.md](../docs/pages/tvSettings_TestSpecification.md)
*/
void test_l3_tvSettings_GetCurrentVideoResolution(void)
{
    gTestID = 4;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);
    tvError_t ret = tvERROR_NONE;
    tvResolutionParam_t resolution = {0};

    UT_LOG_INFO("Calling GetCurrentVideoResolution(OUT:res:[])");
    ret = GetCurrentVideoResolution(&resolution);
    ASSERT(ret == tvERROR_NONE);

    UT_LOG_INFO("Result GetCurrentVideoResolution(OUT:Resolution:[%dx%d], OUT:isInterlaced:[%d], OUT:res value:[%s]),tvError_t:[%s]",
                resolution.frameHeight, resolution.frameWidth, resolution.isInterlaced,
                UT_Control_GetMapString(tvVideoResolution_mapTable, resolution.resolutionValue),
                UT_Control_GetMapString(tvError_mapTable, ret));

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
* @brief This test retrieves the current video frame rate.
*
* This test function retrieves the current video frame rate using the `GetCurrentVideoFrameRate` function.
*
* **Test Group ID:** 03@n
* **Test Case ID:** 05@n
*
* **Test Procedure:**
* Refer to Test specification documentation
* [tvSettings_TestSpecification.md](../docs/pages/tvSettings_TestSpecification.md)
*/
void test_l3_tvSettings_GetCurrentVideoFrameRate(void)
{
    gTestID = 5;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);
    tvError_t ret = tvERROR_NONE;
    tvVideoFrameRate_t frameRate = tvVideoFrameRate_MAX;

    UT_LOG_INFO("Calling GetCurrentVideoFrameRate(OUT:format:[])");
    ret = GetCurrentVideoFrameRate(&frameRate);
    ASSERT(ret == tvERROR_NONE);

    UT_LOG_INFO("Result GetCurrentVideoFrameRate(OUT:Frame Rate:[%s]),tvError_t:[%s]"
                , UT_Control_GetMapString(tvVideoFrameRate_mapTable, frameRate)
                , UT_Control_GetMapString(tvError_mapTable, ret));

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
* @brief This test retrieves the current video source.
*
* This test function retrieves the current video source using the `GetCurrentVideoSource` function.
*
* **Test Group ID:** 03@n
* **Test Case ID:** 06@n
*
* **Test Procedure:**
* Refer to Test specification documentation
* [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
*/
void test_l3_tvSettings_GetCurrentVideoSource(void)
{
    gTestID = 6;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);
    tvError_t ret = tvERROR_NONE;
    tvVideoSrcType_t currentSource = 0;

    UT_LOG_INFO("Calling GetCurrentVideoSource(OUT:currentSource:[])");
    ret = GetCurrentVideoSource(&currentSource);
    ASSERT(ret == tvERROR_NONE);

    UT_LOG_INFO("Result GetCurrentVideoSource(OUT:Current Source:[%s]), tvError_t:[%s]",
                UT_Control_GetMapString(tvVideoSrcType_mapTable, currentSource), UT_Control_GetMapString(tvError_mapTable, ret));

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
* @brief This test sets  the backlight value.
*
* This test function sets the backlight value to a range of values and then retrieves it to confirm.
*
* **Test Group ID:** 03@n
* **Test Case ID:** 07@n
*
* **Test Procedure:**
* Refer to Test specification documentation
* [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
*/
void test_l3_tvSettings_backlight(void)
{
    gTestID = 7;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);
    tvError_t ret = tvERROR_NONE;
    int32_t backlightValue = -1;
    int32_t currentBacklight = -1;

    // Prompt the user for the backlight value
    UT_LOG_MENU_INFO("Enter the backlight value to set (0 - 100): ");
    readInt(&backlightValue);

    if (backlightValue < 0 || backlightValue > 100)
    {
        UT_LOG_ERROR("Invalid backlight value entered. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Set the backlight value
    UT_LOG_INFO("Calling SetBacklight(IN:backlight:[%d])", backlightValue);
    ret = SetBacklight(backlightValue);
    UT_LOG_INFO("Result SetBacklight(IN:backlight:[%d]), tvError_t:[%s]", backlightValue, UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    // Get the backlight value to confirm
    UT_LOG_INFO("Calling GetBacklight(OUT:backlight:[])");
    ret = GetBacklight(&currentBacklight);
    UT_LOG_INFO("Result GetBacklight(OUT:backlight:[%d]), tvError_t:[%s]", currentBacklight, UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    ASSERT_COMPARE(backlightValue,currentBacklight);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
* @brief This test sets the backlight fade settings.
*
* This test function sets the backlight fade settings using different values and then retrieves them to confirm.
*
* **Test Group ID:** 03@n
* **Test Case ID:** 08@n
*
* **Test Procedure:**
* Refer to Test specification documentation
* [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
*/
void test_l3_tvSettings_backlightFade(void)
{
    gTestID = 8;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);
    tvError_t ret = tvERROR_NONE;
    int32_t fromValue, toValue, durationValue;
    int32_t currentFrom = -1, currentTo = -1, currentProgress = -1;

    // Prompt the user for input values
    UT_LOG_MENU_INFO("Enter the 'from' backlight value (0-100): ");
    readInt(&fromValue);

    UT_LOG_MENU_INFO("Enter the 'to' backlight value (0-100): ");
    readInt(&toValue);

    UT_LOG_MENU_INFO("Enter the fade duration (0-1000 ms): ");
    readInt(&durationValue);

    // Validate the input values
    if (fromValue < 0 || fromValue > 100)
    {
        UT_LOG_ERROR("Invalid 'from' backlight value entered. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    if (toValue < 0 || toValue > 100)
    {
        UT_LOG_ERROR("Invalid 'to' backlight value entered. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    if (durationValue < 0 || durationValue > 1000)
    {
        UT_LOG_ERROR("Invalid fade duration entered. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Set the backlight fade settings
    UT_LOG_INFO("Calling SetBacklightFade(IN:from:[%d], IN:to:[%d], IN:duration:[%d] ms)", fromValue, toValue, durationValue);
    ret = SetBacklightFade(fromValue, toValue, durationValue);
    UT_LOG_INFO("Result SetBacklightFade(IN:from:[%d], IN:to:[%d], IN:duration:[%d] ms), tvError_t:[%s]", fromValue, toValue, durationValue, UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    // Get the backlight fade settings to confirm
    UT_LOG_INFO("Calling GetCurrentBacklightFade(OUT:from:[], OUT:to:[], OUT:current:[])");
    ret = GetCurrentBacklightFade(&currentFrom, &currentTo, &currentProgress);
    UT_LOG_INFO("Result GetCurrentBacklightFade(OUT:from:[%d], OUT:to:[%d], OUT:current:[%d]), tvError_t:[%s]", currentFrom, currentTo, currentProgress, UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    ASSERT_COMPARE(fromValue,currentFrom);
    ASSERT_COMPARE(toValue,currentTo);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
* @brief This test sets the current backlight mode.
*
* This test function retrieves the supported backlight modes, sets each supported mode,
* and then verifies that the mode is correctly applied by getting the current backlight mode.
*
* **Test Group ID:** 03@n
* **Test Case ID:** 09@n
*
* **Test Procedure:**
* Refer to Test specification documentation
* [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
*/
void test_l3_tvSettings_backlightMode(void)
{
    gTestID = 9;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    tvError_t ret = tvERROR_NONE;
    int32_t userChoice = 0;
    int32_t selectedMode = 0;
    tvBacklightMode_t currentMode = tvBacklightMode_INVALID;

    // Display available modes to the user
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Backlight Modes");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Backlight Modes");
    for (int32_t i = tvBacklightMode_MANUAL; i < tvBacklightMode_MAX; i <<= 1)
    {
        UT_LOG_INFO("%d. %s", i, UT_Control_GetMapString(tvBacklightMode_mapTable, i));
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");

    // Get user input for selecting a mode
    UT_LOG_MENU_INFO("Enter the number corresponding to the Backlight Mode: ");
    readInt(&userChoice);

    // Validate user input: must be between 1 and tvBacklightMode_MAX - 1
    if (userChoice < 1 || userChoice > (tvBacklightMode_MAX - 1))
    {
        UT_LOG_ERROR("Invalid Backlight Mode selection: %d. Exiting function.", userChoice);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    selectedMode = userChoice;

    // Set the selected backlight mode
    UT_LOG_INFO("Setting BacklightMode (IN: mode:[%s])", UT_Control_GetMapString(tvBacklightMode_mapTable, selectedMode));
    ret = SetCurrentBacklightMode(selectedMode);  // Removed the redundant cast
    UT_LOG_INFO("Result Backlight mode set to: SetCurrentBacklightMode(IN: mode[%s])", UT_Control_GetMapString(tvBacklightMode_mapTable, selectedMode));
    ASSERT(ret == tvERROR_NONE);

    // Get the current backlight mode to confirm
    UT_LOG_INFO("Calling GetCurrentBacklightMode(OUT: currentMode:[])");
    ret = GetCurrentBacklightMode(&currentMode);
    UT_LOG_INFO("Get current BacklightMode (OUT: currentMode:[%s])tvError[%s]",
        UT_Control_GetMapString(tvBacklightMode_mapTable, currentMode),
        UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    ASSERT_COMPARE(currentMode,selectedMode);  // Ensure the mode was set correctly

    UT_LOG_INFO("Out %s", __FUNCTION__);
}
/**
* @brief This test sets the TV dimming mode.
*
* This test function sets the dimming mode using TVDimmingMode.
* The test verifies if the dimming mode is set and retrieved correctly.
*
* **Test Group ID:** 03@n
* **Test Case ID:** 10@n
*
* **Test Procedure:**
* Refer to Test specification documentation
* [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
*/
void test_l3_tvSettings_TVDimmingMode(void)
{
    gTestID = 10;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    int32_t userChoice = 0;
    tvDimmingMode_t selectedMode = tvDimmingMode_MAX;
    char currentMode[16] = {0};
    char *modeStr = NULL;

    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tDimmingMode");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s","DimmingMode");
    for (int32_t i = tvDimmingMode_Fixed; i < tvDimmingMode_MAX; i++)
    {
        UT_LOG_INFO("%d. %s", i + 1, UT_Control_GetMapString(tvDimmingMode_mapTable, i));
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");


    // Get user input for selecting a mode
    UT_LOG_MENU_INFO("Enter the number corresponding to the Dimming Mode: ");
    readInt(&userChoice);

    // Use if condition for user choice validation and return on failure
    if (userChoice < 1 || userChoice > tvDimmingMode_MAX)
    {
        UT_LOG_ERROR("Invalid dimming mode choice entered.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    selectedMode = (tvDimmingMode_t)(userChoice - 1);

    // Map the selected mode to a string
    switch (selectedMode)
    {
        case tvDimmingMode_Fixed:
            modeStr = "fixed";
            break;
        case tvDimmingMode_Local:
            modeStr = "local";
            break;
        case tvDimmingMode_Global:
            modeStr = "global";
            break;
        default:
            UT_LOG_ERROR("Unknown dimming mode selected.");
            UT_LOG_INFO("Out %s", __FUNCTION__);
            return;
    }

    // Set the selected dimming mode
    UT_LOG_INFO("Setting dimming mode to (IN:mode:[%s])", modeStr);
    ret = SetTVDimmingMode(modeStr);
    UT_LOG_INFO("Result SetTVDimmingMode(IN:mode:[%s]),tvError_t:[%s]", modeStr, UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    // Get and verify the current dimming mode
    UT_LOG_INFO("Calling GetTVDimmingMode(OUT:currentMode:[])");
    ret = GetTVDimmingMode(currentMode);
    UT_LOG_INFO("Result Get TVDimmingMode (OUT:currentMode:[%s]),tvError_t:[%s]", currentMode, UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);
    ASSERT_STRING_COMPARE(modeStr,currentMode, strlen(modeStr) + 1);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief This test sets the local dimming level and immediately verifies it.
 *
 * This test function sets different local dimming levels
 * to verify it is set correctly.
 *
 * **Test Group ID:** 03@n
 * **Test Case ID:** 11@n
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_LocalDimmingLevel(void)
{
    gTestID = 11;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    int32_t userChoice = 0;
    ldimStateLevel_t levels[] = {LDIM_STATE_NONBOOST, LDIM_STATE_BOOST, LDIM_STATE_BURST};
    ldimStateLevel_t selectedLevel = LDIM_STATE_NONBOOST;
    ldimStateLevel_t currentLevel = LDIM_STATE_NONBOOST;
    int32_t numLevels = sizeof(levels) / sizeof(levels[0]);

    // Display available dimming levels to the user
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tLocalDimmingLevel");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s","LocalDimmingLevel");
    for (int32_t i = 0; i < numLevels; ++i)
    {
        UT_LOG_INFO("%d. %s", i + 1, UT_Control_GetMapString(ldimStateLevel_mapTable, levels[i]));
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");

    // Get user input for selecting a dimming level
    UT_LOG_MENU_INFO("Enter the number corresponding to the desired Local Dimming Level: ");
    readInt(&userChoice);

    // Validate user input and return on failure
    if (userChoice < 1 || userChoice > numLevels)
    {
        UT_LOG_ERROR("Invalid dimming level choice entered.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    selectedLevel = levels[userChoice - 1];

    // Set the selected dimming level
    UT_LOG_INFO("Calling SetLocalDimmingLevel(IN:ldimStateLevel:[%s])", UT_Control_GetMapString(ldimStateLevel_mapTable, selectedLevel));
    ret = SetLocalDimmingLevel(selectedLevel);
    UT_LOG_INFO("Result SetLocalDimmingLevel(IN:ldimStateLevel:[%s]),tvError_t:[%s]", UT_Control_GetMapString(ldimStateLevel_mapTable, selectedLevel), UT_Control_GetMapString(tvError_mapTable, ret));

    ASSERT(ret == tvERROR_NONE);

    // Get and verify the current dimming level
    UT_LOG_INFO("Calling GetLocalDimmingLevel()");
    ret = GetLocalDimmingLevel(&currentLevel);
    UT_LOG_INFO("Result Get LocalDimmingLevel (OUT:CurrentLevel:[%s]),tvError_t:[%s]", UT_Control_GetMapString(ldimStateLevel_mapTable, currentLevel), UT_Control_GetMapString(tvError_mapTable, ret));

    ASSERT(ret == tvERROR_NONE);
    ASSERT_COMPARE(selectedLevel, currentLevel);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}
/**
 * @brief Tests setting and getting the brightness value
 *
 * This test function sets the brightness to different values.
 *
 * **Test Group ID:** 03@n
 * **Test Case ID:** 12@n
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_Brightness(void)
{
    gTestID = 12;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    int32_t brightness = 0;
    int32_t currentBrightness = 0;

    // Prompt the user to input the desired brightness value
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tbrightness");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s","brightness");
    UT_LOG_MENU_INFO("Enter the desired brightness value (0-100): ");
    readInt(&brightness);
    UT_LOG_MENU_INFO("----------------------------------------------------------");

    // Validate brightness value and return on failure
    if (brightness < 0 || brightness > 100)
    {
        UT_LOG_ERROR("Invalid brightness value entered: [%d]. Please enter a value between 0 and 100.", brightness);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Set the brightness value
    UT_LOG_INFO("Calling SetBrightness(IN:brightness:[%d])", brightness);
    ret = SetBrightness(brightness);
    UT_LOG_INFO("Result SetBrightness(IN:brightness:[%d]),tvError_t:[%s]", brightness, UT_Control_GetMapString(tvError_mapTable, ret));

    ASSERT(ret == tvERROR_NONE);

    // Get the brightness value
    UT_LOG_INFO("Calling GetBrightness(OUT:brightness:[])");
    ret = GetBrightness(&currentBrightness);
    UT_LOG_INFO("Result GetBrightness(OUT:brightness:[%d]),tvError_t:[%s]", currentBrightness, UT_Control_GetMapString(tvError_mapTable, ret));

    ASSERT(ret == tvERROR_NONE);
    ASSERT_COMPARE(brightness, currentBrightness);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief Tests setting and getting the contrast value
 *
 * This test function sets the contrast to a user-specified value.
 *
 * **Test Group ID:** 03@n
 * **Test Case ID:** 13@n
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_Contrast(void)
{
    gTestID = 13;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    int32_t contrast = 0;
    int32_t currentContrast = 0;

    // Prompt the user to input the desired contrast value
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tContrast");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s","contrast");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter the desired contrast value (0-100): ");
    readInt(&contrast);
    UT_LOG_MENU_INFO("----------------------------------------------------------");


    // Validate contrast value and return on failure
    if (contrast < 0 || contrast > 100)
    {
        UT_LOG_ERROR("Invalid contrast value entered: [%d]. Please enter a value between 0 and 100.", contrast);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Set the contrast value
    UT_LOG_INFO("Calling SetContrast(IN:contrast:[%d])", contrast);
    ret = SetContrast(contrast);
    UT_LOG_INFO("Result SetContrast(IN:contrast:[%d]),tvError_t:[%s]", contrast, UT_Control_GetMapString(tvError_mapTable, ret));

    ASSERT(ret == tvERROR_NONE);

    // Get the current contrast value
    UT_LOG_INFO("Calling GetContrast(OUT:contrast:[])");
    ret = GetContrast(&currentContrast);
    UT_LOG_INFO("Result GetContrast(OUT:contrast:[%d]),tvError_t:[%s]", currentContrast, UT_Control_GetMapString(tvError_mapTable, ret));

    ASSERT(ret == tvERROR_NONE);
    ASSERT_COMPARE(contrast, currentContrast);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief Tests setting and getting the sharpness value
 *
 * This test function sets the sharpness to a user-specified value.
 *
 * **Test Group ID:** 03@n
 * **Test Case ID:** 14@n
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_Sharpness(void)
{
    gTestID = 14;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    int32_t sharpness = 0;
    int32_t currentSharpness = 0;

    // Prompt the user to input the desired sharpness value
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSharpness");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s","Sharpness");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter the desired sharpness value (0-100): ");
    readInt(&sharpness);
    UT_LOG_MENU_INFO("----------------------------------------------------------");

    // Validate sharpness value and return on failure
    if (sharpness < 0 || sharpness > 100)
    {
        UT_LOG_ERROR("Invalid sharpness value entered: [%d]. Please enter a value between 0 and 100.", sharpness);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Set the sharpness value
    UT_LOG_INFO("Calling SetSharpness(IN:sharpness:[%d])", sharpness);
    ret = SetSharpness(sharpness);
    UT_LOG_INFO("Result SetSharpness(IN:sharpness:[%d]),tvError_t:[%s]", sharpness, UT_Control_GetMapString(tvError_mapTable, ret));

    ASSERT(ret == tvERROR_NONE);

    // Get the current sharpness value
    UT_LOG_INFO("Calling GetSharpness(OUT:sharpness:[])");
    ret = GetSharpness(&currentSharpness);
    UT_LOG_INFO("Result GetSharpness(OUT:sharpness:[%d]),tvError_t:[%s]", currentSharpness, UT_Control_GetMapString(tvError_mapTable, ret));

    ASSERT(ret == tvERROR_NONE);
    ASSERT_COMPARE(sharpness, currentSharpness);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief Tests setting and getting the saturation value
 *
 * This test function sets the saturation to a user-specified value.
 *
 * **Test Group ID:** 03@n
 * **Test Case ID:** 15@n
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_Saturation(void)
{
    gTestID = 15;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    int32_t saturation = 0;
    int32_t currentSaturation = 0;

    // Prompt the user to input the desired saturation value
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tsaturation");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s","saturation");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter the desired saturation value (0-100): ");
    readInt(&saturation);
    UT_LOG_MENU_INFO("----------------------------------------------------------");

    // Validate saturation value and return on failure
    if (saturation < 0 || saturation > 100)
    {
        UT_LOG_ERROR("Invalid saturation value entered: [%d]. Please enter a value between 0 and 100.", saturation);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Set the saturation value
    UT_LOG_INFO("Calling SetSaturation(IN:saturation:[%d])", saturation);
    ret = SetSaturation(saturation);
    UT_LOG_INFO("Result SetSaturation(IN:saturation:[%d]),tvError_t:[%s]", saturation, UT_Control_GetMapString(tvError_mapTable, ret));

    ASSERT(ret == tvERROR_NONE);

    // Get the current saturation value
    UT_LOG_INFO("Calling GetSaturation(OUT:saturation:[])");
    ret = GetSaturation(&currentSaturation);
    UT_LOG_INFO("Result GetSaturation(OUT:saturation:[%d]),tvError_t:[%s]", currentSaturation, UT_Control_GetMapString(tvError_mapTable, ret));

    ASSERT(ret == tvERROR_NONE);
    ASSERT_COMPARE(saturation, currentSaturation);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}
/**
 * @brief Tests setting and getting the hue value
 *
 * This test function sets the hue to a user-specified value.
 *
 * **Test Group ID:** 03@n
 * **Test Case ID:** 16@n
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_Hue(void)
{
    gTestID = 16;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    int32_t hue = 0;
    int32_t currentHue = 0;

    // Prompt the user to input the desired hue value
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\thue");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s","hue");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter the desired hue value (0-100): ");
    readInt(&hue);
    UT_LOG_MENU_INFO("----------------------------------------------------------");

    // Validate hue value and return on failure
    if (hue < 0 || hue > 100)
    {
        UT_LOG_ERROR("Invalid hue value entered: [%d]. Please enter a value between 0 and 100.", hue);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Set the hue value
    UT_LOG_INFO("Calling SetHue(IN:hue:[%d])", hue);
    ret = SetHue(hue);
    UT_LOG_INFO("Result SetHue(IN:hue:[%d]),tvError_t:[%s]", hue, UT_Control_GetMapString(tvError_mapTable, ret));

    ASSERT(ret == tvERROR_NONE);

    // Get the current hue value
    UT_LOG_INFO("Calling GetHue(OUT:hue:[])");
    ret = GetHue(&currentHue);
    UT_LOG_INFO("Result GetHue(OUT:hue:[%d]),tvError_t:[%s]", currentHue, UT_Control_GetMapString(tvError_mapTable, ret));

    ASSERT(ret == tvERROR_NONE);
    ASSERT_COMPARE(hue, currentHue);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}
/**
 * @brief This test sets and gets the current color temperature.
 *
 * This test function retrieves the supported color temperatures, sets each supported temperature,
 * and then verifies that the temperature is correctly applied by getting the current color temperature.
 *
 * **Test Group ID:** 03@n
 * **Test Case ID:** 17@n
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_ColorTemperature(void)
{
    gTestID = 17;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    tvColorTemp_t currentTemperature = tvColorTemp_MAX;
    tvColorTemp_t selectedTemperature = tvColorTemp_MAX;
    int32_t userChoice = 0;

    // Retrieve and display supported color temperatures
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tcolor temperature.");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s","color temperature.");
    for (int32_t i = tvColorTemp_STANDARD; i < tvColorTemp_MAX; i++)
    {
        UT_LOG_INFO("%d. %s", i + 1, UT_Control_GetMapString(tvColorTemp_mapTable, i));
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter the desired color temperature value: ");
    // Get user input for selecting a color temperature
    readInt(&userChoice);

    // Validate user choice and handle invalid choice
    if (userChoice < 1 || userChoice > tvColorTemp_MAX)
    {
        UT_LOG_ERROR("Invalid choice! Please select a valid color temperature.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    selectedTemperature = (userChoice - 1);

    // Set the selected color temperature
    UT_LOG_INFO("Calling SetColorTemperature(IN:SelectedTemperature:[%s])", UT_Control_GetMapString(tvColorTemp_mapTable, selectedTemperature));
    ret = SetColorTemperature(selectedTemperature);
    UT_LOG_INFO("Result SetColorTemperature(IN:SelectedTemperature:[%s]),tvError_t:[%s]", UT_Control_GetMapString(tvColorTemp_mapTable, selectedTemperature), UT_Control_GetMapString(tvError_mapTable, ret));

    ASSERT(ret == tvERROR_NONE);

    // Get and confirm the current color temperature
    UT_LOG_INFO("Calling GetColorTemperature(OUT:colorTemperature:[])");
    ret = GetColorTemperature(&currentTemperature);
    UT_LOG_INFO("Result GetColorTemperature(OUT:colorTemperature:[%s]),tvError_t:[%s]", UT_Control_GetMapString(tvColorTemp_mapTable, currentTemperature), UT_Control_GetMapString(tvError_mapTable, ret));

    ASSERT(ret == tvERROR_NONE);
    ASSERT_COMPARE(selectedTemperature, currentTemperature);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}
/**
* @brief This test sets and gets the current aspect ratio.
*
* This test function retrieves the supported aspect ratios, sets each supported ratio,
* and then verifies that the ratio is correctly applied by getting the current aspect ratio.
*
* **Test Group ID:** 03@n
* **Test Case ID:** 18@n
*
* **Test Procedure:**
* Refer to Test specification documentation
* [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
*/
void test_l3_tvSettings_AspectRatio(void)
{
    gTestID = 18;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    tvDisplayMode_t currentAspectRatio = tvDisplayMode_MAX;
    tvDisplayMode_t selectedAspectRatio = tvDisplayMode_MAX;
    int32_t userChoice = 0;

    // Retrieve and display supported aspect ratios
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tAspect Ratio");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s","Aspect Ratio");
    for (int32_t i = tvDisplayMode_4x3; i < tvDisplayMode_MAX; i++)
    {
        UT_LOG_INFO("%d. %s", i + 1, UT_Control_GetMapString(tvDisplayMode_mapTable, i));
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter the number corresponding to the Aspect Ratio: ");
    readInt(&userChoice);

    // Validate user choice and handle invalid choice
    if (userChoice < 1 || userChoice > tvDisplayMode_MAX)
    {
        UT_LOG_ERROR("Invalid choice! Please select a valid aspect ratio.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    selectedAspectRatio = (userChoice - 1);

    // Set the selected aspect ratio
    UT_LOG_INFO("Calling SetAspectRatio(IN:AspectRatio:[%s])", UT_Control_GetMapString(tvDisplayMode_mapTable, selectedAspectRatio));
    ret = SetAspectRatio(selectedAspectRatio);
    UT_LOG_INFO("Result SetAspectRatio(IN:AspectRatio:[%s]),tvError_t:[%s]", UT_Control_GetMapString(tvDisplayMode_mapTable, selectedAspectRatio), UT_Control_GetMapString(tvError_mapTable, ret));

    ASSERT(ret == tvERROR_NONE);

    // Get and confirm the current aspect ratio
    UT_LOG_INFO("Calling GetAspectRatio(OUT:aspectRatio:[])");
    ret = GetAspectRatio(&currentAspectRatio);
    UT_LOG_INFO("Result GetAspectRatio(OUT:aspectRatio:[%s]),tvError_t:[%s]", UT_Control_GetMapString(tvDisplayMode_mapTable, currentAspectRatio), UT_Control_GetMapString(tvError_mapTable, ret));

    ASSERT(ret == tvERROR_NONE);
    ASSERT_COMPARE(selectedAspectRatio, currentAspectRatio);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief This test sets and gets the current low latency state.
 *
 * This test function allows the user to set the low latency state to either enable or disable,
 * and then verifies that the state is correctly applied by getting the current low latency state.
 *
 * **Test Group ID:** 03@n
 * **Test Case ID:** 19@n
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_LowLatencyState(void)
{
    gTestID = 19;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    int32_t currentLowLatencyState = -1;
    int32_t userChoice = 0;

    // Display available low latency states to the user
    UT_LOG_INFO("Available Low Latency States:");
    UT_LOG_INFO("0. Disable");
    UT_LOG_INFO("1. Enable");

    // Get user input for selecting a low latency state
    UT_LOG_MENU_INFO("Enter 0 to Disable or 1 to Enable Low Latency: ");
    readInt(&userChoice);

    // Validate user choice and handle invalid input
    if (userChoice < 0 || userChoice > 1)
    {
        UT_LOG_ERROR("Invalid choice! Please select 0 to disable or 1 to enable low latency.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Set the selected low latency state
    UT_LOG_INFO("Calling SetLowLatencyState(IN:LowLatencyState:[%d])", userChoice);
    ret = SetLowLatencyState(userChoice);
    UT_LOG_INFO("Result SetLowLatencyState(IN:LowLatencyState:[%d]),tvError_t:[%s]", userChoice, UT_Control_GetMapString(tvError_mapTable, ret));

    ASSERT(ret == tvERROR_NONE);

    // Get and confirm the current low latency state
    UT_LOG_INFO("Calling GetLowLatencyState(OUT:LowLatencyState:[])");
    ret = GetLowLatencyState(&currentLowLatencyState);
    UT_LOG_INFO("Result GetLowLatencyState(OUT:LowLatencyState:[%d]),tvError_t:[%s]", currentLowLatencyState, UT_Control_GetMapString(tvError_mapTable, ret));

    ASSERT(ret == tvERROR_NONE);
    ASSERT_COMPARE(userChoice, currentLowLatencyState);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief This test sets and gets the current dynamic contrast mode.
 *
 * This test function allows the user to enable or disable the dynamic contrast,
 * and then verifies that the mode is correctly applied by getting the current dynamic contrast mode.
 *
 * **Test Group ID:** 03@n
 * **Test Case ID:** 20@n
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_DynamicContrast(void)
{
    gTestID = 20;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    char userChoice[20] = {0};
    char currentDynamicContrast[20] = {0}; // Buffer to store the current dynamic contrast mode
    int userSelection = 0;

    // Display available dynamic contrast states to the user
    UT_LOG_INFO("Available Dynamic Contrast States:");
    UT_LOG_INFO("1. Enabled");
    UT_LOG_INFO("2. Disabled");

    // Get user input for selecting a dynamic contrast mode
    UT_LOG_MENU_INFO("Enter '1' to Enable or '2' to Disable Dynamic Contrast: ");
    if (scanf("%d", &userSelection) != 1) {
        UT_LOG_ERROR("Invalid input! Please enter 1 or 2 to select a mode.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Validate user input and set the userChoice
    if (userSelection == 1) {
        strncpy(userChoice, "enabled", sizeof(userChoice) - 1);
    } else if (userSelection == 2) {
        strncpy(userChoice, "disabled", sizeof(userChoice) - 1);
    } else {
        UT_LOG_ERROR("Invalid choice! Please enter 1 or 2 to select a mode.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Set the selected dynamic contrast mode
    UT_LOG_INFO("Calling SetDynamicContrast(IN:DynamicContrastMode:[%s])", userChoice);
    ret = SetDynamicContrast(userChoice);
    if (ret != tvERROR_NONE) {
        UT_LOG_ERROR("Failed to set dynamic contrast. Error code: %d", ret);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }
    UT_LOG_INFO("Result SetDynamicContrast(IN:DynamicContrastMode:[%s]), tvError_t:[%s]", userChoice, UT_Control_GetMapString(tvError_mapTable, ret));

    // Get the current dynamic contrast mode to confirm
    UT_LOG_INFO("Calling GetDynamicContrast(OUT:DynamicContrastMode:[])");
    ret = GetDynamicContrast(currentDynamicContrast);
    if (ret != tvERROR_NONE) {
        UT_LOG_ERROR("Failed to get dynamic contrast mode. Error code: %d", ret);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }
    UT_LOG_INFO("Result GetDynamicContrast(OUT:DynamicContrastMode:[%s])", currentDynamicContrast);

    // Verify that the setting matches the user's choice
    ASSERT_STRING_COMPARE(userChoice, currentDynamicContrast, strlen(userChoice) + 1);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}


/**
 * @brief This test sets and gets the current dynamic gamma value.
 *
 * This test function allows the user to set a dynamic gamma value within a specified range,
 * and then verifies that the gamma value is correctly applied by getting the current dynamic gamma value.
 *
 * **Test Group ID:** 03@n
 * **Test Case ID:** 21@n
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_DynamicGamma(void)
{
    gTestID = 21;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    double currentDynamicGamma = -1.0;
    double userGammaValue = 0.0;

    // Display valid gamma value range to the user
    UT_LOG_INFO("Valid Dynamic Gamma Values Range:");
    UT_LOG_INFO("From 1.80 to 2.60");

    // Get user input for selecting a dynamic gamma value
    UT_LOG_MENU_INFO("Enter a dynamic gamma value (1.80 to 2.60): ");
    readDouble(&userGammaValue);

    // Validate gamma value and handle invalid input
    if (userGammaValue < 1.80 || userGammaValue > 2.60)
    {
        UT_LOG_ERROR("Invalid gamma value entered: [%.2f]. Please enter a value between 1.80 and 2.60.", userGammaValue);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Set the selected dynamic gamma value
    UT_LOG_INFO("Calling SetDynamicGamma(IN: gammaValue:[%.2f])", userGammaValue);
    ret = SetDynamicGamma(userGammaValue);
    UT_LOG_INFO("Result SetDynamicGamma(IN: gammaValue:[%.2f]),tvError_t:[%s]", userGammaValue, UT_Control_GetMapString(tvError_mapTable, ret));

    ASSERT(ret == tvERROR_NONE);

    // Get the current dynamic gamma value to confirm
    UT_LOG_INFO("Calling GetDynamicGamma(OUT: dynamicGamma:[])");
    ret = GetDynamicGamma(&currentDynamicGamma);
    UT_LOG_INFO("Result GetDynamicGamma(OUT: dynamicGamma:[%.2f]),tvError_t:[%s]", currentDynamicGamma, UT_Control_GetMapString(tvError_mapTable, ret));

    ASSERT(ret == tvERROR_NONE);
    ASSERT_COMPARE(userGammaValue, currentDynamicGamma);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief This test sets and gets the current Dolby Vision mode.
 *
 * This test function retrieves the supported Dolby Vision modes from YAML, sets a selected mode,
 * and then verifies that the mode is correctly applied by getting the current Dolby Vision mode.
 *
 * **Test Group ID:** 03@n
 * **Test Case ID:** 22@n
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_DolbyVisionMode(void)
{
    // Initialize test ID and log entry
    gTestID = 22;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    tvDolbyMode_t currentDolbyMode = tvDolbyMode_Invalid;
    tvDolbyMode_t selectedMode = tvDolbyMode_Invalid;
    int32_t userChoice = 0;

    // Retrieve and display supported Dolby Vision modes
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tDolby Vision Mode");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s","Dolby Vision Mode");
    for (int32_t i = tvDolbyMode_Dark; i <= tvHLGMode_Game; i++)
    {
        UT_LOG_INFO("%d. %s]", i + 1, UT_Control_GetMapString(tvDolbyMode_mapTable, i));
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    // Get user input for selecting a mode
    UT_LOG_MENU_INFO("Enter the number corresponding to the Dolby Vision Mode: ");
    readInt(&userChoice);

    if (userChoice < 1 || userChoice > tvMode_Max)
    {
        UT_LOG_ERROR("Invalid choice! Please select a valid Dolby Vision mode.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    selectedMode = userChoice - 1;

    // Set the selected Dolby Vision mode
    UT_LOG_INFO("Calling SetTVDolbyVisionMode(IN: DolbyVisionMode: [%s])", UT_Control_GetMapString(tvDolbyMode_mapTable, selectedMode));
    ret = SetTVDolbyVisionMode(selectedMode);
    UT_LOG_INFO("Result SetTVDolbyVisionMode (IN:DolbyVisionMode[%s]),tvError_t:[%s]",
                UT_Control_GetMapString(tvDolbyMode_mapTable, selectedMode), UT_Control_GetMapString(tvError_mapTable, ret));

    ASSERT(ret == tvERROR_NONE);

    // Get and confirm the current Dolby Vision mode
    UT_LOG_INFO("Calling GetTVDolbyVisionMode(OUT: dolbyMode:[])");
    ret = GetTVDolbyVisionMode(&currentDolbyMode);
    UT_LOG_INFO("Result GetTVDolbyVisionMode(OUT:dolbyMode[%s]),tvError_t:[%s]",
                UT_Control_GetMapString(tvDolbyMode_mapTable, currentDolbyMode), UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);
    ASSERT_COMPARE(selectedMode, currentDolbyMode);

    // Log exit and end function
    UT_LOG_INFO("Out %s", __FUNCTION__);
}
/**
 * @brief This test sets and gets the PictureMode.
 *
 * This test function retrieves the supported picture modes from YAML, sets a selected mode,
 * and then verifies that the mode is correctly applied by getting the current picture mode
 *
 * **Test Group ID:** 03@n
 * **Test Case ID:** 23@n
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_PictureMode(void)
{
    // Initialize test ID and log entry
    gTestID = 23;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    char currentPictureMode[PIC_MODE_NAME_MAX] = {0};
    char selectedPictureMode[PIC_MODE_NAME_MAX] = {0};
    pic_modes_t *supportedPictureModes;  // Array of pointers to pic_modes_t
    unsigned short pictureModeCount = 0;
    int32_t userChoice = 0;

    // Get the supported picture modes from the system
    ret = GetTVSupportedPictureModes(&supportedPictureModes, &pictureModeCount);
    UT_LOG_INFO("GetTVSupportedPictureModes pictureModeCount[%u]",pictureModeCount);
    if (ret != tvERROR_NONE || pictureModeCount == 0)
    {
        UT_LOG_ERROR("Failed to retrieve supported picture modes or no modes available.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Display the list of supported picture modes to the user
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Picture Modes");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    for (int32_t i = 0; i < pictureModeCount; i++)
    {
        if (supportedPictureModes[i].name != NULL)
        {
            UT_LOG_INFO("%d. %s", i + 1, supportedPictureModes[i].name);
        }
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");

    // Get user input for selecting a mode by its index
    UT_LOG_MENU_INFO("Enter the number corresponding to the Picture Mode: ");
    scanf("%d", &userChoice);
    readAndDiscardRestOfLine(stdin);

    // Validate the user's choice
    if (userChoice < 1 || userChoice > pictureModeCount)
    {
        UT_LOG_ERROR("Invalid choice! Please select a valid picture mode.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Retrieve the selected mode from the list
    strncpy(selectedPictureMode, supportedPictureModes[userChoice - 1].name, sizeof(selectedPictureMode) - 1);

    // Set the selected picture mode
    UT_LOG_INFO("Calling SetTVPictureMode(IN: selectedPictureMode[%s])", selectedPictureMode);
    ret = SetTVPictureMode(selectedPictureMode);
    UT_LOG_INFO("Result SetTVPictureMode( IN: selectedPictureMode[%s]), tvError_t:[%s]", selectedPictureMode, UT_Control_GetMapString(tvError_mapTable, ret));

    ASSERT(ret == tvERROR_NONE);

    // Get and confirm the current picture mode
    UT_LOG_INFO("Calling GetTVPictureMode(OUT: currentPictureMode[])");
    ret = GetTVPictureMode(currentPictureMode);
    UT_LOG_INFO("Result GetTVPictureMode(OUT:currentPictureMode[%s]), tvError_t:[%s]", currentPictureMode, UT_Control_GetMapString(tvError_mapTable, ret));

    ASSERT(ret == tvERROR_NONE);
    ASSERT_STRING_COMPARE(selectedPictureMode, currentPictureMode, strlen(selectedPictureMode) + 1);

    // Log exit and end function
    UT_LOG_INFO("Out %s", __FUNCTION__);
}
/**
 * @brief This test sets and gets the rgain value based on user-selected color temperature and source.
 *
 * This test function retrieves the supported color temperatures from YAML, sets a selected color temperature and source
 * with a specified rgain value, and then verifies the rgain value by getting it back.
 *
 * **Test Group ID:** 03@n
 * **Test Case ID:** 27@n
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_ColorTempRgain(void)
{
    // Initialize test ID and log entry
    gTestID = 24;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    tvColorTemp_t selectedColorTemp = tvColorTemp_MAX;
    tvColorTempSourceOffset_t selectedSourceId = TV_OFFSET;
    int32_t rgainValue = 0;
    int32_t retrievedRgain = 0;
    int32_t saveOnly = 0; // 0 for set, 1 for save
    uint32_t i;
    int32_t userChoice = 0;
    int32_t userSrcChoice = 0;

    // List all options for Video sources
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video sources");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Sources");
    for (uint32_t j = HDMI_OFFSET; j <= MAX_OFFSET; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j+1, UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Source (index): ");
    readInt(&userSrcChoice);

    // Validate user input for video source
    if (userSrcChoice < HDMI_OFFSET || userSrcChoice > MAX_OFFSET)
    {
        UT_LOG_ERROR("Invalid choice of Video source. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    selectedSourceId = userSrcChoice - 1;



    // Retrieve and display supported color temperatures
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tColorTemperature");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s","ColorTemperature");
    for (i = tvColorTemp_STANDARD; i < tvColorTemp_MAX; i++)
    {
        UT_LOG_INFO("%d. %s", i + 1, UT_Control_GetMapString(tvColorTemp_mapTable, i));
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    // Get user input for selecting a color temperature
    UT_LOG_MENU_INFO("Enter the number corresponding to the Color Temperature: ");
    readInt(&userChoice);

    if (userChoice < 1 || userChoice > tvColorTemp_MAX)
    {
        UT_LOG_ERROR("Invalid color temperature choice: [%d]", userChoice);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    selectedColorTemp = userChoice - 1;

    // Get user input for rgain value
    UT_LOG_MENU_INFO("Enter the Rgain Value (0 - 2047): ");
    readInt(&rgainValue);

    if (rgainValue < 0 || rgainValue > 2047)
    {
        UT_LOG_ERROR("Invalid Rgain value: [%d]", rgainValue);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Get user input for saveOnly flag
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSaveOnly Flag Selection");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s","SaveOnly Flag");
    UT_LOG_MENU_INFO("\t0.  %-30s", "Set");
    UT_LOG_MENU_INFO("\t1.  %-30s", "Save");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter the Flag Selection:");

    readInt(&saveOnly);

    if (saveOnly < 0 || saveOnly > 1)
    {
        UT_LOG_ERROR("Invalid SaveOnly flag: [%d]", saveOnly);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Set the rgain value
    UT_LOG_INFO("Calling SetColorTemp_Rgain_onSource(IN:Color Temperature:[%s], IN:Rgain:[%d], IN:Source ID:[%s], IN:SaveOnly:[%d])",
                UT_Control_GetMapString(tvColorTemp_mapTable, selectedColorTemp),
                rgainValue,
                UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, selectedSourceId),
                saveOnly);
    ret = SetColorTemp_Rgain_onSource(selectedColorTemp, rgainValue, selectedSourceId, saveOnly);
    UT_LOG_INFO("Result SetColorTemp_Rgain_onSource(IN:Color Temperature:[%s], IN:Rgain:[%d], IN:Source ID:[%s],IN:SaveOnly:[%d]), tvError_t:[%s]",
                UT_Control_GetMapString(tvColorTemp_mapTable, selectedColorTemp),
                rgainValue,
                UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, selectedSourceId),
                saveOnly,
                UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    // Get and confirm the rgain value
    UT_LOG_INFO("Calling GetColorTemp_Rgain_onSource(IN:Color Temperature:[%s], OUT:rgain[], IN:Source ID:[%s])",
                UT_Control_GetMapString(tvColorTemp_mapTable, selectedColorTemp),
                UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, selectedSourceId));
    ret = GetColorTemp_Rgain_onSource(selectedColorTemp, &retrievedRgain, selectedSourceId);
    UT_LOG_INFO("Result GetColorTemp_Rgain_onSource(OUT:[%d]IN:Color Temperature:[%s],IN:Source ID:[%s]),tvError_t:[%s]",
                  retrievedRgain,
                  UT_Control_GetMapString(tvColorTemp_mapTable,selectedColorTemp),
                  UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, selectedSourceId),
                  UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);
    ASSERT_COMPARE(rgainValue, retrievedRgain);

    // Log exit and end function
    UT_LOG_INFO("Out %s", __FUNCTION__);
}
/**
 * @brief This test sets and gets the ggain value based on user-selected color temperature and source.
 *
 * This test function retrieves the supported color temperatures from YAML, sets a selected color temperature and source
 * with a specified ggain value, and then verifies the ggain value by getting it back.
 *
 * **Test Group ID:** 03@n
 * **Test Case ID:** 25@n
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_ColorTempGgain(void)
{
    // Initialize test ID and log entry
    gTestID = 25;  // Adjust Test ID for Ggain
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    tvColorTemp_t selectedColorTemp = tvColorTemp_MAX;
    tvColorTempSourceOffset_t selectedSourceId = TV_OFFSET;
    int32_t ggainValue = 0;
    int32_t retrievedGgain = 0;
    int32_t saveOnly = 0; // 0 for set, 1 for save
    uint32_t i;
    int32_t userChoice = 0;
    int32_t userSrcChoice = 0;

    // List all options for Video sources
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video sources");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Sources");
    for (uint32_t j = HDMI_OFFSET; j <= MAX_OFFSET; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j+1, UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Source (index): ");
    readInt(&userSrcChoice);

    // Validate user input for video source
    if (userSrcChoice < HDMI_OFFSET || userSrcChoice > MAX_OFFSET)
    {
        UT_LOG_ERROR("Invalid choice of Video source. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    selectedSourceId = userSrcChoice - 1;


    // Retrieve and display supported color temperatures
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tColorTemperature");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s","ColorTemperature");
    for (i = tvColorTemp_STANDARD; i < tvColorTemp_MAX; i++)
    {
        UT_LOG_INFO("%d. %s", i + 1, UT_Control_GetMapString(tvColorTemp_mapTable, i));
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    // Get user input for selecting a color temperature
    UT_LOG_MENU_INFO("Enter the number corresponding to the Color Temperature: ");
    readInt(&userChoice);

    if (userChoice < 1 || userChoice > tvColorTemp_MAX)
    {
        UT_LOG_ERROR("Invalid color temperature choice: [%d]", userChoice);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    selectedColorTemp = userChoice - 1;

    // Get user input for Ggain value
    UT_LOG_MENU_INFO("Enter the Ggain Value (0 - 2047): ");
    readInt(&ggainValue);

    if (ggainValue < 0 || ggainValue > 2047)
    {
        UT_LOG_ERROR("Invalid Ggain value: [%d]", ggainValue);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Get user input for saveOnly flag
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSaveOnly Flag Selection");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s","SaveOnly Flag");
    UT_LOG_MENU_INFO("\t0.  %-30s", "Set");
    UT_LOG_MENU_INFO("\t1.  %-30s", "Save");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter the Flag Selection:");

    readInt(&saveOnly);

    if (saveOnly < 0 || saveOnly > 1)
    {
        UT_LOG_ERROR("Invalid SaveOnly flag: [%d]", saveOnly);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Set the Ggain value
    UT_LOG_INFO("Calling SetColorTemp_Ggain_onSource(IN:Color Temperature:[%s], IN:Ggain:[%d], IN:Source ID:[%s], IN:SaveOnly:[%d])",
                UT_Control_GetMapString(tvColorTemp_mapTable, selectedColorTemp),
                ggainValue,
                UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, selectedSourceId),
                saveOnly);
    ret = SetColorTemp_Ggain_onSource(selectedColorTemp, ggainValue, selectedSourceId, saveOnly);
    UT_LOG_INFO("Result SetColorTemp_Ggain_onSource( IN:Color Temperature:[%s], IN:Ggain:[%d], IN:Source ID:[%s], IN:SaveOnly:[%d]), tvError_t:[%d]",
                UT_Control_GetMapString(tvColorTemp_mapTable, selectedColorTemp),
                ggainValue,
                UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, selectedSourceId),
                saveOnly,
                UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, selectedSourceId));
    ASSERT(ret == tvERROR_NONE);

    // Get and confirm the Ggain value
    UT_LOG_INFO("Calling GetColorTemp_Ggain_onSource(IN:Color Temperature:[%s], OUT:ggain[], IN:Source ID:[%s])",
                UT_Control_GetMapString(tvColorTemp_mapTable, selectedColorTemp),
                UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, selectedSourceId));
    ret = GetColorTemp_Ggain_onSource(selectedColorTemp, &retrievedGgain, selectedSourceId);
    UT_LOG_INFO("Result GetColorTemp_Ggain_onSource( IN:Color Temperature:[%s],OUT:ggain[%d] , IN:Source ID:[%s]),tvError_t:[%s]",
                UT_Control_GetMapString(tvColorTemp_mapTable, selectedColorTemp),
                retrievedGgain,
                UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, selectedSourceId),
                UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);
    ASSERT_COMPARE(ggainValue,retrievedGgain);

    // Log exit and end function
    UT_LOG_INFO("Out %s", __FUNCTION__);
}
/**
 * @brief This test sets and gets the bgain value based on user-selected color temperature and source.
 *
 * This test function retrieves the supported color temperatures from YAML, sets a selected color temperature and source
 * with a specified bgain value, and then verifies the bgain value by getting it back.
 *
 * **Test Group ID:** 03@n
 * **Test Case ID:** 26@n
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_ColorTempBgain(void)
{
    // Initialize test ID and log entry
    gTestID = 26;  // Adjust Test ID for Bgain
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    tvColorTemp_t selectedColorTemp = tvColorTemp_MAX;
    tvColorTempSourceOffset_t selectedSourceId = TV_OFFSET;
    int32_t bgainValue = 0;
    int32_t retrievedBgain = 0;
    int32_t saveOnly = 0; // 0 for set, 1 for save
    uint32_t i;
    int32_t userChoice = 0;
    int32_t userSrcChoice = 0;

    // List all options for Video sources
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video sources");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Sources");
    for (uint32_t j = HDMI_OFFSET; j <= MAX_OFFSET; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j+1, UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Source (index): ");
    readInt(&userSrcChoice);

    // Validate user input for video source
    if (userSrcChoice < HDMI_OFFSET || userSrcChoice > MAX_OFFSET)
    {
        UT_LOG_ERROR("Invalid choice of Video source. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    selectedSourceId = userSrcChoice - 1;

    // Retrieve and display supported color temperatures
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tColorTemperature");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s","ColorTemperature");
    for (i = tvColorTemp_STANDARD; i < tvColorTemp_MAX; i++)
    {
        UT_LOG_INFO("%d. %s", i + 1, UT_Control_GetMapString(tvColorTemp_mapTable, i));
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    // Get user input for selecting a color temperature
    UT_LOG_MENU_INFO("Enter the number corresponding to the Color Temperature: ");
    readInt(&userChoice);

    if (userChoice < 1 || userChoice > tvColorTemp_MAX)
    {
        UT_LOG_ERROR("Invalid color temperature choice: [%d]", userChoice);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    selectedColorTemp = userChoice - 1;

    // Get user input for Bgain value
    UT_LOG_MENU_INFO("Enter the Bgain Value (0 - 2047): ");
    readInt(&bgainValue);

    if (bgainValue < 0 || bgainValue > 2047)
    {
        UT_LOG_ERROR("Invalid Bgain value: [%d]", bgainValue);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Get user input for saveOnly flag
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSaveOnly Flag Selection");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s","SaveOnly Flag");
    UT_LOG_MENU_INFO("\t0.  %-30s", "Set");
    UT_LOG_MENU_INFO("\t1.  %-30s", "Save");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter the Flag Selection:");

    readInt(&saveOnly);

    if (saveOnly < 0 || saveOnly > 1)
    {
        UT_LOG_ERROR("Invalid SaveOnly flag: [%d]", saveOnly);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Set the Bgain value
    UT_LOG_INFO("Calling SetColorTemp_Bgain_onSource(IN:Color Temperature:[%s], IN:Bgain:[%d], IN:Source ID:[%s], IN:SaveOnly:[%d])",
                UT_Control_GetMapString(tvColorTemp_mapTable, selectedColorTemp),
                bgainValue,
                UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, selectedSourceId),
                saveOnly);
    ret = SetColorTemp_Bgain_onSource(selectedColorTemp, bgainValue, selectedSourceId, saveOnly);
    UT_LOG_INFO("Result SetColorTemp_Bgain_onSource(IN:Color Temperature:[%s], IN:Bgain:[%d], IN:Source ID:[%s], IN:SaveOnly:[%d]),tvError_t:[%s]",
                UT_Control_GetMapString(tvColorTemp_mapTable, selectedColorTemp),
                bgainValue,
                UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, selectedSourceId),
                saveOnly,
                UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    // Get and confirm the Bgain value
    UT_LOG_INFO("Calling GetColorTemp_Bgain_onSource(IN:Color Temperature:[%s], OUT:bgain[], IN:Source ID:[%s])",
                UT_Control_GetMapString(tvColorTemp_mapTable, selectedColorTemp),
                UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, selectedSourceId));
    ret = GetColorTemp_Bgain_onSource(selectedColorTemp, &retrievedBgain, selectedSourceId);
    UT_LOG_INFO("Result GetColorTemp_Bgain_onSource(IN:Color Temperature:[%s],OUT:bgain[%d], IN:Source ID:[%s]),tvError_t:[%s]",
                UT_Control_GetMapString(tvColorTemp_mapTable, selectedColorTemp),
                retrievedBgain,
                UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, selectedSourceId),
                UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);
    ASSERT_COMPARE(bgainValue, retrievedBgain);

    // Log exit and end function
    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief This test sets and gets the rpostoffset value based on user-selected color temperature and source.
 *
 * This test function retrieves the supported color temperatures from YAML, sets a selected color temperature and source
 * with a specified rpostoffset value, and then verifies the rpostoffset value by getting it back.
 *
 * **Test Group ID:** 03@n
 * **Test Case ID:** 27@n
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_ColorTempRpostoffset(void)
{
    // Initialize test ID and log entry
    gTestID = 27;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    tvColorTemp_t selectedColorTemp = tvColorTemp_MAX;
    tvColorTempSourceOffset_t selectedSourceId = TV_OFFSET;
    int32_t rpostoffsetValue = 0;
    int32_t retrievedRpostoffset = 0;
    int32_t saveOnly = 0; // 0 for set, 1 for save
    uint32_t i;
    int32_t userChoice = 0;
    int32_t userSrcChoice = 0;

    // List all options for Video sources
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video sources");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Sources");
    for (uint32_t j = HDMI_OFFSET; j <= MAX_OFFSET; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j+1, UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Source (index): ");
    readInt(&userSrcChoice);

    // Validate user input for video source
    if (userSrcChoice < HDMI_OFFSET || userSrcChoice > MAX_OFFSET)
    {
        UT_LOG_ERROR("Invalid choice of Video source. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    selectedSourceId = userSrcChoice - 1;

    // Retrieve and display supported color temperatures
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tColorTemperature");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "ColorTemperature");
    for (i = tvColorTemp_STANDARD; i < tvColorTemp_MAX; i++)
    {
        UT_LOG_INFO("%d. %s", i + 1, UT_Control_GetMapString(tvColorTemp_mapTable, i));
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    // Get user input for selecting a color temperature
    UT_LOG_MENU_INFO("Enter the number corresponding to the Color Temperature: ");
    readInt(&userChoice);

    if (userChoice < 1 || userChoice > tvColorTemp_MAX)
    {
        UT_LOG_ERROR("Invalid color temperature choice: [%d]", userChoice);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    selectedColorTemp = userChoice - 1;

    // Get user input for rpostoffset value
    UT_LOG_MENU_INFO("Enter the Rpostoffset Value (-1024 to 1023): ");
    readInt(&rpostoffsetValue);

    if (rpostoffsetValue < -1024 || rpostoffsetValue > 1023)
    {
        UT_LOG_ERROR("Invalid Rpostoffset value: [%d]", rpostoffsetValue);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Get user input for saveOnly flag
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSaveOnly Flag Selection");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s","SaveOnly Flag");
    UT_LOG_MENU_INFO("\t0.  %-30s", "Set");
    UT_LOG_MENU_INFO("\t1.  %-30s", "Save");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter the Flag Selection:");

    readInt(&saveOnly);

    if (saveOnly < 0 || saveOnly > 1)
    {
        UT_LOG_ERROR("Invalid SaveOnly flag: [%d]", saveOnly);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Set the rpostoffset value
    UT_LOG_INFO("Calling  SetColorTemp_R_post_offset_onSource(IN:rpostoffset:[%d], IN:ColorTemperature:[%s], IN:Source ID:[%s], IN:SaveOnly:[%d])",
                rpostoffsetValue,
                UT_Control_GetMapString(tvColorTemp_mapTable, selectedColorTemp),
                UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, selectedSourceId),
                saveOnly);
    ret = SetColorTemp_R_post_offset_onSource(selectedColorTemp, rpostoffsetValue, selectedSourceId, saveOnly);
    UT_LOG_INFO("Result SetColorTemp_R_post_offset_onSource(IN:rpostoffset:[%d], IN:ColorTemperature:[%s], IN:Source ID:[%s], IN:SaveOnly:[%d]),tvError_t:[%s]",
                rpostoffsetValue,
                UT_Control_GetMapString(tvColorTemp_mapTable, selectedColorTemp),
                UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, selectedSourceId),
                saveOnly,
                UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    // Verify the rpostoffset value
    UT_LOG_INFO("calling GetColorTemp_R_post_offset_onSource(IN:ColorTemperature:[%s], OUT:Rpostoffset[], IN:Source ID:[%s])",
                UT_Control_GetMapString(tvColorTemp_mapTable, selectedColorTemp),
                UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, selectedSourceId));
    ret = GetColorTemp_R_post_offset_onSource(selectedColorTemp, &retrievedRpostoffset, selectedSourceId);
    UT_LOG_INFO("Result GetColorTemp_R_post_offset_onSource(IN:rpostoffset:[%d], OUT:rpostoffset:[%d])tvError_t[%s]",
                rpostoffsetValue, retrievedRpostoffset,UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);
    ASSERT_COMPARE(rpostoffsetValue, retrievedRpostoffset);

    // Log exit and end function
    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief This test sets and gets the gpostoffset value based on user-selected color temperature and source.
 *
 * This test function retrieves the supported color temperatures from YAML, sets a selected color temperature and source
 * with a specified gpostoffset value, and then verifies the gpostoffset value by getting it back.
 *
 * **Test Group ID:** 03@n
 * **Test Case ID:** 28@n
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_ColorTempGpostoffset(void)
{
    // Initialize test ID and log entry
    gTestID = 28; // Update the test ID as needed
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    tvColorTemp_t selectedColorTemp = tvColorTemp_MAX;
    tvColorTempSourceOffset_t selectedSourceId = TV_OFFSET;
    int32_t gpostoffsetValue = 0;
    int32_t retrievedGpostoffset = 0;
    int32_t saveOnly = 0; // 0 for set, 1 for save
    uint32_t i;
    int32_t userChoice = 0;
    int32_t userSrcChoice = 0;

    // List all options for Video sources
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video sources");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Sources");
    for (uint32_t j = HDMI_OFFSET; j <= MAX_OFFSET; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j+1, UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Source (index): ");
    readInt(&userSrcChoice);

    // Validate user input for video source
    if (userSrcChoice < HDMI_OFFSET || userSrcChoice > MAX_OFFSET)
    {
        UT_LOG_ERROR("Invalid choice of Video source. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    selectedSourceId = userSrcChoice - 1;

    // Retrieve and display supported color temperatures
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tColorTemperature");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "ColorTemperature");
    for (i = tvColorTemp_STANDARD; i < tvColorTemp_MAX; i++)
    {
        UT_LOG_INFO("%d. %s", i + 1, UT_Control_GetMapString(tvColorTemp_mapTable, i));
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    // Get user input for selecting a color temperature
    UT_LOG_MENU_INFO("Enter the number corresponding to the Color Temperature: ");
    readInt(&userChoice);

    if (userChoice < 1 || userChoice > tvColorTemp_MAX)
    {
        UT_LOG_ERROR("Invalid color temperature choice: [%d]", userChoice);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    selectedColorTemp = userChoice - 1;

    // Get user input for gpostoffset value
    UT_LOG_MENU_INFO("Enter the Gpostoffset Value (-1024 to 1023): ");
    readInt(&gpostoffsetValue);

    if (gpostoffsetValue < -1024 || gpostoffsetValue > 1023)
    {
        UT_LOG_ERROR("Invalid Gpostoffset value: [%d]", gpostoffsetValue);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSaveOnly Flag Selection");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s","SaveOnly Flag");
    UT_LOG_MENU_INFO("\t0.  %-30s", "Set");
    UT_LOG_MENU_INFO("\t1.  %-30s", "Save");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter the Flag Selection:");

    readInt(&saveOnly);

    if (saveOnly < 0 || saveOnly > 1)
    {
        UT_LOG_ERROR("Invalid SaveOnly flag: [%d]", saveOnly);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Set the gpostoffset value
    UT_LOG_INFO("Calling SetColorTemp_G_post_offset_onSource(IN:gpostoffset:[%d], IN:ColorTemperature:[%s], IN:Source ID:[%s], IN:SaveOnly:[%d])",
                gpostoffsetValue,
                UT_Control_GetMapString(tvColorTemp_mapTable, selectedColorTemp),
                UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, selectedSourceId),
                saveOnly);
    ret = SetColorTemp_G_post_offset_onSource(selectedColorTemp, gpostoffsetValue, selectedSourceId, saveOnly);
    UT_LOG_INFO("Result SetColorTemp_G_post_offset_onSource(IN:gpostoffset:[%d], IN:ColorTemperature:[%s], IN:Source ID:[%s], IN:SaveOnly:[%d]),tvError_t:[%s]",
                gpostoffsetValue,
                UT_Control_GetMapString(tvColorTemp_mapTable, selectedColorTemp),
                UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, selectedSourceId),
                saveOnly,
                UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    // Verify the gpostoffset value
    UT_LOG_INFO("Calling GetColorTemp_G_post_offset_onSource(IN:ColorTemperature:[%s], OUT:Gpostoffset[], IN:Source ID:[%s])",
                UT_Control_GetMapString(tvColorTemp_mapTable, selectedColorTemp),
                UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, selectedSourceId));
    ret = GetColorTemp_G_post_offset_onSource(selectedColorTemp, &retrievedGpostoffset, selectedSourceId);
    UT_LOG_INFO("Result GetColorTemp_G_post_offset_onSource(IN:gpostoffset:[%d], OUT:gpostoffset:[%d])tvError_t:[%s]",
                gpostoffsetValue, retrievedGpostoffset,UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);
    ASSERT_COMPARE(gpostoffsetValue, retrievedGpostoffset);

    // Log exit and end function
    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief This test sets and gets the bpostoffset value based on user-selected color temperature and source.
 *
 * This test function retrieves the supported color temperatures from YAML, sets a selected color temperature and source
 * with a specified bpostoffset value, and then verifies the bpostoffset value by getting it back.
 *
 * **Test Group ID:** 03@n
 * **Test Case ID:** 29@n
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_ColorTempBpostoffset(void)
{
    // Initialize test ID and log entry
    gTestID = 29; // Update the test ID as needed
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    tvColorTemp_t selectedColorTemp = tvColorTemp_MAX;
    tvColorTempSourceOffset_t selectedSourceId = TV_OFFSET;
    int32_t bpostoffsetValue = 0;
    int32_t retrievedBpostoffset = 0;
    int32_t saveOnly = 0; // 0 for set, 1 for save
    int32_t userChoice = 0;
    int32_t userSrcChoice = 0;

    // List all options for Video sources
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video sources");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Sources");
    for (uint32_t j = HDMI_OFFSET; j <= MAX_OFFSET; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j+1, UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Source (index): ");
    readInt(&userSrcChoice);

    // Validate user input for video source
    if (userSrcChoice < HDMI_OFFSET || userSrcChoice > MAX_OFFSET)
    {
        UT_LOG_ERROR("Invalid choice of Video source. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    selectedSourceId = userSrcChoice - 1;


    // Retrieve and display supported color temperatures
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tColorTemperature");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "ColorTemperature");
    for (uint32_t i = tvColorTemp_STANDARD; i < tvColorTemp_MAX; i++)
    {
        UT_LOG_INFO("%d. %s", i + 1, UT_Control_GetMapString(tvColorTemp_mapTable, i));
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    // Get user input for selecting a color temperature
    UT_LOG_MENU_INFO("Enter the number corresponding to the Color Temperature: ");
    readInt(&userChoice);

    if (userChoice < 1 || userChoice > tvColorTemp_MAX)
    {
        UT_LOG_ERROR("Invalid color temperature choice: [%d]", userChoice);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    selectedColorTemp = userChoice - 1;

    // Get user input for bpostoffset value
    UT_LOG_MENU_INFO("Enter the Bpostoffset Value (-1024 to 1023): ");
    readInt(&bpostoffsetValue);

    if (bpostoffsetValue < -1024 || bpostoffsetValue > 1023)
    {
        UT_LOG_ERROR("Invalid Bpostoffset value: [%d]", bpostoffsetValue);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Get user input for saveOnly flag
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSaveOnly Flag Selection");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s","SaveOnly Flag");
    UT_LOG_MENU_INFO("\t0.  %-30s", "Set");
    UT_LOG_MENU_INFO("\t1.  %-30s", "Save");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter the Flag Selection:");

    readInt(&saveOnly);

    if (saveOnly < 0 || saveOnly > 1)
    {
        UT_LOG_ERROR("Invalid SaveOnly flag: [%d]", saveOnly);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Set the bpostoffset value
    UT_LOG_INFO("Calling SetColorTemp_B_post_offset_onSource(IN:bpostoffset:[%d], IN:ColorTemperature:[%s], IN:Source ID:[%s], IN:SaveOnly:[%d])",
                bpostoffsetValue,
                UT_Control_GetMapString(tvColorTemp_mapTable, selectedColorTemp),
                UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, selectedSourceId),
                saveOnly);
    ret = SetColorTemp_B_post_offset_onSource(selectedColorTemp, bpostoffsetValue, selectedSourceId, saveOnly);
    UT_LOG_INFO("Result SetColorTemp_B_post_offset_onSource(IN:bpostoffset:[%d], IN:ColorTemperature:[%s], IN:Source ID:[%s], IN:SaveOnly:[%d]),tvError_t:[%s]",
                bpostoffsetValue,
                UT_Control_GetMapString(tvColorTemp_mapTable, selectedColorTemp),
                UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, selectedSourceId),
                saveOnly,
                UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    // Verify the bpostoffset value
    UT_LOG_INFO("Calling GetColorTemp_B_post_offset_onSource ( IN:ColorTemperature:[%s], OUT:Bpostoffset[], IN:Source ID:[%s])",
                UT_Control_GetMapString(tvColorTemp_mapTable, selectedColorTemp),
                UT_Control_GetMapString(tvColorTempSourceOffset_mapTable, selectedSourceId));
    ret = GetColorTemp_B_post_offset_onSource(selectedColorTemp, &retrievedBpostoffset, selectedSourceId);
    UT_LOG_INFO("Result GetColorTemp_B_post_offset_onSource(IN:bpostoffset:[%d], OUT:bpostoffset:[%d]) tvError_t[%s]",
                bpostoffsetValue, retrievedBpostoffset,UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);
    ASSERT_COMPARE(bpostoffsetValue, retrievedBpostoffset);

    // Log exit and end function
    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief This test enables or disables the white balance (WB) calibration mode based on user input.
 *
 * This test function allows the user to enable or disable the white balance calibration mode. After setting the mode,
 * it verifies the current WB mode by retrieving it.
 *
 * **Test Group ID:** 03@n
 * **Test Case ID:** 30@n
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_WBCalibrationMode(void)
{
    // Initialize test ID and log entry
    gTestID = 30;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    tvError_t ret = tvERROR_NONE;
    bool setWbMode = false;
    bool retrievedWbMode = false;

    // Get user input for enabling or disabling WB mode
    int32_t userChoice = 0;
    UT_LOG_MENU_INFO("Enter 1 to Enable WB Calibration Mode, 0 to Disable: ");
    readInt(&userChoice);

    if (userChoice != 0 && userChoice != 1)
    {
        UT_LOG_ERROR("Invalid choice! Please enter 1 to enable or 0 to disable WB Calibration Mode.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    setWbMode = (userChoice == 1);

    // Enable or Disable WB Calibration Mode
    UT_LOG_INFO("Calling EnableWBCalibrationMode (IN: setWbMode[%s])", setWbMode ? "Enabled" : "Disabled");
    ret = EnableWBCalibrationMode(setWbMode);
    UT_LOG_INFO("Result EnableWBCalibrationMode (IN: setWbMode[%s]),tvError_t:[%s]", setWbMode ? "Enabled" : "Disabled", UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    // Verify the current WB mode
    UT_LOG_INFO("Calling GetCurrentWBCalibrationMode(OUT:[])");
    ret = GetCurrentWBCalibrationMode(&retrievedWbMode);
    UT_LOG_INFO("Result GetCurrentWBCalibrationMode(OUT: retrievedWbMode[%s]),tvError_t:[%s]", retrievedWbMode ? "Enabled" : "Disabled", UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);
    ASSERT_COMPARE(setWbMode, retrievedWbMode);

    // Log exit and end function
    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief This test sets and gets the gamma table values for primary colors (R, G, B) based on user input.
 *
 * This test function allows the user to set the gamma table values for the primary colors (R, G, B) with a specified size.
 * It then verifies the gamma values by retrieving them back.
 *
 * **Test Group ID:** 03@n
 * **Test Case ID:** 31@n
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_GammaTable(void)
{
    // Initialize test ID and log entry
    gTestID = 31;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    unsigned short size = 0;
    unsigned short pData_R[256] = {0};
    unsigned short pData_G[256] = {0};
    unsigned short pData_B[256] = {0};
    unsigned short retrievedData_R[256] = {0};
    unsigned short retrievedData_G[256] = {0};
    unsigned short retrievedData_B[256] = {0};

    // Get user input for the size of the gamma table
    UT_LOG_MENU_INFO("Enter the size of the gamma table (1 - 255): ");
    readInt((int32_t*)&size);

    if (size < 1 || size > 255)
    {
        UT_LOG_ERROR("Invalid size! Please enter a size between 1 and 255.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Get user input for gamma values for Red
    UT_LOG_MENU_INFO("Enter %hu gamma values for Red (0 - 1023): ", size);
    for (unsigned short i = 0; i < size; i++)
    {
        scanf("%hu", &pData_R[i]);
        if (pData_R[i] > 1023)
        {
            UT_LOG_ERROR("Invalid value for Red at position %hu! Please enter a value between 0 and 1023.", i + 1);
            UT_LOG_INFO("Out %s", __FUNCTION__);
            return;
        }
    }
    readAndDiscardRestOfLine(stdin);

    // Get user input for gamma values for Green
    UT_LOG_MENU_INFO("Enter %hu gamma values for Green (0 - 1023): ", size);
    for (unsigned short i = 0; i < size; i++)
    {
        scanf("%hu", &pData_G[i]);
        if (pData_G[i] > 1023)
        {
            UT_LOG_ERROR("Invalid value for Green at position %hu! Please enter a value between 0 and 1023.", i + 1);
            UT_LOG_INFO("Out %s", __FUNCTION__);
            return;
        }
    }
    readAndDiscardRestOfLine(stdin);

    // Get user input for gamma values for Blue
    UT_LOG_MENU_INFO("Enter %hu gamma values for Blue (0 - 1023): ", size);
    for (unsigned short i = 0; i < size; i++)
    {
        scanf("%hu", &pData_B[i]);
        if (pData_B[i] > 1023)
        {
            UT_LOG_ERROR("Invalid value for Blue at position %hu! Please enter a value between 0 and 1023.", i + 1);
            UT_LOG_INFO("Out %s", __FUNCTION__);
            return;
        }
    }
    readAndDiscardRestOfLine(stdin);

    // Set the gamma table values
    UT_LOG_INFO("Calling SetGammaTable( IN: size[%hu])", size);
    ret = SetGammaTable(pData_R, pData_G, pData_B, size);
    UT_LOG_INFO("Result SetGammaTable(IN:size:[%hu]),tvError_t:[%s]", size, UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    // Verify the gamma table values
    UT_LOG_INFO("Calling  GetGammaTable (OUT: size[%hu])", size);
    ret = GetGammaTable(retrievedData_R, retrievedData_G, retrievedData_B, size);
    UT_LOG_INFO("Result GetGammaTable( OUT: size[%hu]),tvError_t:[%s]", size, UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief This test sets and gets the Dolby Vision TMAX parameter based on user input.
 *
 * This test function allows the user to set the Dolby Vision TMAX parameter with a specified value.
 * It then verifies the TMAX value by retrieving it back.
 *
 * **Test Group ID:** 03@n
 * **Test Case ID:** 32@n
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_DvTmaxValue(void)
{
    // Initialize test ID and log entry
    gTestID = 32;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    int32_t tmaxValue = 0;
    int32_t retrievedTmaxValue = 0;

    // Get user input for the TMAX value
    UT_LOG_MENU_INFO("Enter the Dolby Vision TMAX value (0 - 10000): ");
    readInt(&tmaxValue);

    if (tmaxValue < 0 || tmaxValue > 10000)
    {
        UT_LOG_ERROR("Invalid TMAX value! Please enter a value between 0 and 10000.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Set the Dolby Vision TMAX value
    UT_LOG_INFO("Calling SetDvTmaxValue(IN: tmaxValue[%d])", tmaxValue);
    ret = SetDvTmaxValue(tmaxValue);
    UT_LOG_INFO("Result SetDvTmaxValue(IN:tmaxValue [%d]),tvError_t[%s]", tmaxValue, UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    // Set the Dolby Vision TMAX value
    UT_LOG_INFO("Calling SetDvTmaxValue(IN: tmaxValue[%d])", tmaxValue);
    ret = SetDvTmaxValue(tmaxValue);
    UT_LOG_INFO("Result SetDvTmaxValue(IN:tmaxValue [%d]),tvError_t[%s]", tmaxValue, UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    // Verify the Dolby Vision TMAX value
    UT_LOG_INFO("Calling GetDvTmaxValue(OUT:retrievedTmaxValue[]");
    ret = GetDvTmaxValue(&retrievedTmaxValue);
    UT_LOG_INFO("Result GetDvTmaxValue(OUT: retrievedTmaxValue[%d]),tvError_t:[%s]", retrievedTmaxValue, UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);
    ASSERT_COMPARE(tmaxValue, retrievedTmaxValue);

    // Log exit and end function
    UT_LOG_INFO("Out %s", __FUNCTION__);
}
/**
 * @brief Sets the CMS state and then gets and validates the CMS state.
 *
 * This test function sets the CMS state based on user input and then retrieves and validates
 * the CMS state to ensure it was set correctly.
 *
 * **Test Group ID:** 05
 * **Test Case ID:** 03
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_CMSState(void)
{
    // Initialize test ID and log entry
    gTestID = 33;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    bool enableCMSState = false;
    bool retrievedCMSState = false;
    int32_t userChoice = 0;

    // Get user input to set CMS state
    UT_LOG_MENU_INFO("Enter CMS state to set (1 for Enable, 0 for Disable): ");
    readInt(&userChoice);

    if (userChoice == 1)
    {
        enableCMSState = true;
    } else if (userChoice == 0)
    {
        enableCMSState = false;
    } else
    {
        UT_LOG_ERROR("Invalid input! Please enter 1 to enable or 0 to disable CMS state.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Set the CMS state
    UT_LOG_INFO("Calling SetCMSState(IN: enableCMSState[%d])", enableCMSState);
    ret = SetCMSState(enableCMSState);
    UT_LOG_INFO("Result SetCMSState(IN: enableCMSState[%d]), tvError_t:[%s]", enableCMSState, UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    // Retrieve and validate the CMS state
    UT_LOG_INFO("Calling GetCMSState OUT:retrievedCMSState[]");
    ret = GetCMSState(&retrievedCMSState);
    UT_LOG_INFO("Result GetCMSState(OUT: retrievedCMSState[%s]), tvError_t:[%s]", retrievedCMSState ? "Enabled" : "Disabled", UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);
    ASSERT_COMPARE(enableCMSState, retrievedCMSState);

    // Log exit and end function
    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief This test sets and gets the component saturation for a specified color based on user input.
 *
 * This test function allows the user to set the saturation for a specified component color using the
 * `SetCurrentComponentSaturation` API and then verifies the saturation value by retrieving it with
 * `GetCurrentComponentSaturation`.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 34
 *
 * **Test Procedure:**
 * test_l3_tvSettings_CMSState should be called before this test.
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_ComponentSaturation(void)
{
    // Initialize test ID and log entry
    gTestID = 34;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    tvDataComponentColor_t blSaturationColor = tvDataColor_NONE;
    int32_t saturationValue = 0;
    int32_t retrievedSaturationValue = 0;
    int32_t userColorChoice = 0;

    // Display supported colors
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Component Color");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Supported Component Color");
    for (uint32_t i = tvDataColor_RED; i < tvDataColor_MAX; i<<=1)
    {
        UT_LOG_MENU_INFO("%d. %s", i, UT_Control_GetMapString(tvDataComponentColor_mapTable, i));
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");

    // Get user input for component color
    UT_LOG_MENU_INFO("Enter the component color index: ");

    readInt(&userColorChoice);

    if (userColorChoice < tvDataColor_NONE || userColorChoice >= tvDataColor_MAX)
    {
        UT_LOG_ERROR("Invalid component color index! Please enter a valid index from the list.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    blSaturationColor = userColorChoice;

    // Get user input for saturation value
    UT_LOG_MENU_INFO("Enter the saturation value (0 - 100): ");
    readInt(&saturationValue);

    // Validate saturation value
    if (saturationValue < 0 || saturationValue > 100)
    {
        UT_LOG_ERROR("Invalid saturation value! Please enter a value between 0 and 100.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Set the component saturation value
    UT_LOG_INFO("Calling SetCurrentComponentSaturation( IN: color [%s] IN: value[%d])",
                UT_Control_GetMapString(tvDataComponentColor_mapTable, blSaturationColor), saturationValue);
    ret = SetCurrentComponentSaturation(blSaturationColor, saturationValue);
    UT_LOG_INFO("Result SetCurrentComponentSaturation( IN:color[%s] IN: value[%d]),tvError_t:[%s]",
                UT_Control_GetMapString(tvDataComponentColor_mapTable, blSaturationColor), saturationValue, UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    // Verify the component saturation value
    UT_LOG_INFO("Calling GetCurrentComponentSaturation (IN:color [%s] OUT: value[])",
                UT_Control_GetMapString(tvDataComponentColor_mapTable, blSaturationColor));
    ret = GetCurrentComponentSaturation(blSaturationColor, &retrievedSaturationValue);
    UT_LOG_INFO("Result GetCurrentComponentSaturation (IN:color [%s] OUT: value[%d]),tvError_t:[%s]",
                UT_Control_GetMapString(tvDataComponentColor_mapTable, blSaturationColor), retrievedSaturationValue, UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);
    ASSERT_COMPARE(saturationValue, retrievedSaturationValue);

    // Log exit and end function
    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief Sets the current component hue value and then gets and validates the component hue value.
 *
 * This test function sets the component hue value based on user input and then retrieves and validates
 * the component hue value to ensure it was set correctly.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 35
 *
 * **Test Specification:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_ComponentHue(void)
{
    // Initialize test ID and log entry
    gTestID = 35;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    tvDataComponentColor_t blHueColor = tvDataColor_NONE;
    int32_t hueValue = 0;
    int32_t retrievedHueValue = 0;
    int32_t userColorChoice = 0;

    // Display supported colors
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Component Color");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Supported Component Color");
    for (uint32_t i = tvDataColor_RED; i < tvDataColor_MAX; i<<=1)
    {
        UT_LOG_MENU_INFO("%d. %s", i, UT_Control_GetMapString(tvDataComponentColor_mapTable, i));
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");

    // Get user input for component color
    UT_LOG_MENU_INFO("Enter the component color index: ");

    readInt(&userColorChoice);

    // Validate color index
    if (userColorChoice < tvDataColor_NONE || userColorChoice >= tvDataColor_MAX)
    {
        UT_LOG_ERROR("Invalid component color index! Please enter a valid index from the list.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Set the selected component color based on user choice
    blHueColor = (tvDataComponentColor_t)(userColorChoice); // Adjust for 0-based indexing

    // Get user input for hue value
    UT_LOG_MENU_INFO("Enter the hue value (0 - 100): ");
    readInt(&hueValue);

    // Validate hue value
    if (hueValue < 0 || hueValue > 360)
    {
        UT_LOG_ERROR("Invalid hue value! Please enter a value between 0 and 360.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Set the component hue value
    UT_LOG_INFO("Calling SetCurrentComponentHue(IN:color [%s] IN: huevalue[%d])",
                UT_Control_GetMapString(tvDataComponentColor_mapTable, blHueColor), hueValue);
    ret = SetCurrentComponentHue(blHueColor, hueValue);
    UT_LOG_INFO("Result SetCurrentComponentHue(IN:color [%s] IN: huevalue[%d]) tvError_t:[%s]",
                UT_Control_GetMapString(tvDataComponentColor_mapTable, blHueColor), hueValue, UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    // Verify the component hue value
    UT_LOG_INFO("Calling GetCurrentComponentHue(IN:color [%s] OUT:value[])",
                UT_Control_GetMapString(tvDataComponentColor_mapTable, blHueColor));
    ret = GetCurrentComponentHue(blHueColor, &retrievedHueValue);
    UT_LOG_INFO("Result GetCurrentComponentHue(IN:color [%s] OUT:value[%d]), tvError_t:[%s]",
                UT_Control_GetMapString(tvDataComponentColor_mapTable, blHueColor), retrievedHueValue, UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);
    ASSERT_COMPARE(hueValue, retrievedHueValue);

    // Log function exit
    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief Sets the current component luma value and then gets and validates the component luma value.
 *
 * This test function sets the component luma value based on user input and then retrieves and validates
 * the component luma value to ensure it was set correctly.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 36
 *
 * **Test Specification:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_ComponentLuma(void)
{
    // Initialize test ID and log entry
    gTestID = 36;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    tvDataComponentColor_t blLumaColor = tvDataColor_NONE;
    int32_t lumaValue = 0;
    int32_t retrievedLumaValue = 0;
    int32_t userColorChoice = 0;

    // Display supported colors
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Component Color");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Supported Component Color");
    for (uint32_t i = tvDataColor_RED; i < tvDataColor_MAX; i<<=1)
    {
        UT_LOG_MENU_INFO("%d. %s", i, UT_Control_GetMapString(tvDataComponentColor_mapTable, i));
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");

    // Get user input for component color
    UT_LOG_MENU_INFO("Enter the component color index: ");

    readInt(&userColorChoice);

    // Validate color index
    if (userColorChoice < tvDataColor_NONE || userColorChoice >= tvDataColor_MAX)
    {
        UT_LOG_ERROR("Invalid component color index! Please enter a valid index from the list.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Set the selected component color based on user choice
    blLumaColor = (tvDataComponentColor_t)(userColorChoice); // No need to adjust for 0-based indexing

    // Get user input for luma value
    UT_LOG_MENU_INFO("Enter the luma value (0 - 30): ");
    readInt(&lumaValue);

    // Validate luma value
    if (lumaValue < 0 || lumaValue > 30)
    {
        UT_LOG_ERROR("Invalid luma value! Please enter a value between 0 and 30.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Set the component luma value
    UT_LOG_INFO("Calling SetCurrentComponentLuma (IN:color [%s] IN: lumaValue[%d])",
                UT_Control_GetMapString(tvDataComponentColor_mapTable, blLumaColor), lumaValue);
    ret = SetCurrentComponentLuma(blLumaColor, lumaValue);
    UT_LOG_INFO("Result SetCurrentComponentLuma (IN:color [%s] IN: lumaValue[%d]), tvError_t:[%s]",
                UT_Control_GetMapString(tvDataComponentColor_mapTable, blLumaColor), lumaValue, UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    // Verify the component luma value
    UT_LOG_INFO("Calling GetCurrentComponentLuma (IN:color [%s] OUT:value[])",
                UT_Control_GetMapString(tvDataComponentColor_mapTable, blLumaColor));
    ret = GetCurrentComponentLuma(blLumaColor, &retrievedLumaValue);
    UT_LOG_INFO("Result GetCurrentComponentLuma (IN:color [%s] OUT:value[%d]), tvError_t:[%s]",
                UT_Control_GetMapString(tvDataComponentColor_mapTable, blLumaColor), retrievedLumaValue, UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);
    ASSERT_COMPARE(lumaValue, retrievedLumaValue);

    // Log function exit
    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief Tests the EnableGammaMode function for enabling and disabling the gamma module.
 *
 * This test function calls EnableGammaMode to enable or disable the gamma module based on user input,
 * and validates the function's behavior for success.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 37
 *
 * **Test Specification:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_EnableGammaMode(void)
{
    // Initialize test ID and log entry
    gTestID = 37;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    tvError_t ret = tvERROR_NONE;
    int32_t mode = 0; // Default value for mode

    // User input for enabling or disabling the gamma module
    UT_LOG_MENU_INFO("Enter mode (0 to disable, 1 to enable): ");
    readInt(&mode);

    UT_LOG_INFO("Calling EnableGammaMode(IN:Mode:[%d])", mode);
    ret = EnableGammaMode(mode);
    UT_LOG_INFO("Result  EnableGammaMode(IN:Mode:[%d]) tvError_t:[%s]", mode, UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief Tests the SetGammaPatternMode function for enabling and disabling gamma pattern mode.
 *
 * This test function calls SetGammaPatternMode to enable or disable the gamma pattern mode based on user input,
 * and validates the function's behavior for success.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 38
 *
 * **Test Specification:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_SetGammaPatternMode(void)
{
    // Initialize test ID and log entry
    gTestID = 38;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    tvError_t ret = tvERROR_NONE;
    bool mode = 0;

    // User input for enabling or disabling gamma pattern mode
    UT_LOG_MENU_INFO("Enter mode (0 to disable, 1 to enable): ");
    readInt((int32_t*)&mode);

    // Validate user input
    if (mode != 0 && mode != 1)
    {
        UT_LOG_ERROR("Invalid mode value:[%d]. Expected 0 or 1.", mode);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    UT_LOG_INFO("Calling SetGammaPatternMode(IN:Mode:[%d])", mode);
    ret = SetGammaPatternMode(mode);
    UT_LOG_INFO("Result SetGammaPatternMode(IN:Mode:[%d]) tvError_t:[%s]", mode, UT_Control_GetMapString(tvError_mapTable, ret));

    ASSERT(ret == tvERROR_NONE);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief Tests the SetGammaPattern function for setting gamma patterns based on user input.
 *
 * This test function calls SetGammaPattern to set the gamma pattern based on user input,
 * and validates the function's behavior for success.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 39
 *
 * **Test Specification:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_SetGammaPattern(void)
{
    // Initialize test ID and log entry
    gTestID = 39;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    tvError_t ret = tvERROR_NONE;
    int32_t is_10_bit = 0;
    int32_t R_Value = 0, G_Value = 0, B_Value = 0;

    // User input for gamma pattern settings
    UT_LOG_MENU_INFO("Enter bit resolution (0 for 10-bit, 1 for 8-bit): ");
    scanf("%d", &is_10_bit);
    readAndDiscardRestOfLine(stdin);

    // Validate bit resolution
    if (is_10_bit != 0 && is_10_bit != 1)
    {
        UT_LOG_ERROR("Invalid bit resolution value:[%d]. Expected 0 or 1.", is_10_bit);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    UT_LOG_MENU_INFO("Enter Red level (0 - 1023 for 10-bit, 0 - 255 for 8-bit): ");
    readInt(&R_Value);

    // Validate Red value
    if (is_10_bit == 0)
    {
        if (R_Value < 0 || R_Value > 1023)
        {
            UT_LOG_ERROR("Invalid Red value for 10-bit resolution:[%d]. Expected range 0 - 1023.", R_Value);
            UT_LOG_INFO("Out %s", __FUNCTION__);
            return;
        }
    }
    else
    {
        if (R_Value < 0 || R_Value > 255)
        {
            UT_LOG_ERROR("Invalid Red value for 8-bit resolution:[%d]. Expected range 0 - 255.", R_Value);
            UT_LOG_INFO("Out %s", __FUNCTION__);
            return;
        }
    }

    UT_LOG_MENU_INFO("Enter Green level (0 - 1023 for 10-bit, 0 - 255 for 8-bit): ");
    readInt(&G_Value);

    // Validate Green value
    if (is_10_bit == 0)
    {
        if (G_Value < 0 || G_Value > 1023)
        {
            UT_LOG_ERROR("Invalid Green value for 10-bit resolution:[%d]. Expected range 0 - 1023.", G_Value);
            UT_LOG_INFO("Out %s", __FUNCTION__);
            return;
        }
    }
    else
    {
        if (G_Value < 0 || G_Value > 255)
        {
            UT_LOG_ERROR("Invalid Green value for 8-bit resolution:[%d]. Expected range 0 - 255.", G_Value);
            UT_LOG_INFO("Out %s", __FUNCTION__);
            return;
        }
    }

    UT_LOG_MENU_INFO("Enter Blue level (0 - 1023 for 10-bit, 0 - 255 for 8-bit): ");
    readInt(&B_Value);

    // Validate Blue value
    if (is_10_bit == 0)
    {
        if (B_Value < 0 || B_Value > 1023)
        {
            UT_LOG_ERROR("Invalid Blue value for 10-bit resolution:[%d]. Expected range 0 - 1023.", B_Value);
            UT_LOG_INFO("Out %s", __FUNCTION__);
            return;
        }
    }
    else
    {
        if (B_Value < 0 || B_Value > 255)
        {
            UT_LOG_ERROR("Invalid Blue value for 8-bit resolution:[%d]. Expected range 0 - 255.", B_Value);
            UT_LOG_INFO("Out %s", __FUNCTION__);
            return;
        }
    }

    UT_LOG_INFO("Calling SetGammaPattern(IN:is10BIT[%d] IN:R:[%d], IN:G:[%d], IN:B:[%d])", is_10_bit, R_Value, G_Value, B_Value);
    ret = SetGammaPattern(is_10_bit, R_Value, G_Value, B_Value);
    UT_LOG_INFO("Result SetGammaPattern(IN:is10BIT[%d] IN:R:[%d], IN:G:[%d], IN:B:[%d]), tvError_t:[%s]", is_10_bit, R_Value, G_Value, B_Value, UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    // Log function exit
    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief Tests the SetRGBPattern and GetRGBPattern functions.
 *
 * This test function sets the RGB pattern using SetRGBPattern with user-provided values,
 * then retrieves and validates the RGB values using GetRGBPattern.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 40
 *
 * **Test Specification:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_RGBPattern(void)
{
    // Initialize test ID and log entry
    gTestID = 40;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Data type declarations
    tvError_t ret = tvERROR_NONE;
    int32_t r = 0, g = 0, b = 0;
    int32_t r_get = 0, g_get = 0, b_get = 0;

    // User input for RGB pattern settings
    UT_LOG_MENU_INFO("Enter Red level (0 - 255): ");
    readInt(&r);

    if (r < 0 || r > 255)
    {
        UT_LOG_ERROR("Invalid Red value:[%d]. Expected range 0 - 255.", r);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    UT_LOG_MENU_INFO("Enter Green level (0 - 255): ");
    readInt(&g);

    if (g < 0 || g > 255)
    {
        UT_LOG_ERROR("Invalid Green value:[%d]. Expected range 0 - 255.", g);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    UT_LOG_MENU_INFO("Enter Blue level (0 - 255): ");
    readInt(&b);

    if (b < 0 || b > 255)
    {
        UT_LOG_ERROR("Invalid Blue value:[%d]. Expected range 0 - 255.", b);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    UT_LOG_INFO("Calling SetRGBPattern(IN:R:[%d], IN:G:[%d], IN:B:[%d])", r, g, b);
    ret = SetRGBPattern(r, g, b);
    UT_LOG_INFO("Result SetRGBPattern(IN:R:[%d], IN:G:[%d], IN:B:[%d]) tvError_t:[%s]", r, g, b, UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    UT_LOG_INFO("Calling GetRGBPattern(OUT:R:[], OUT:G:[], OUT:B:[])");
    ret = GetRGBPattern(&r_get, &g_get, &b_get);
    UT_LOG_INFO("Result GetRGBPattern(OUT:R:[%d], OUT:G:[%d], OUT:B:[%d]) tvError_t:[%s]", r_get, g_get, b_get, UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);
    ASSERT_COMPARE(r,r_get);
    ASSERT_COMPARE(g,b_get);
    ASSERT_COMPARE(b,b_get);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}
/**
 * @brief Tests the SetGrayPattern and GetGrayPattern functions.
 *
 * This test function sets the gray pattern using SetGrayPattern with user-provided values,
 * then retrieves and validates the gray value using GetGrayPattern.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 41
 *
 * **Test Specification:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_GrayPattern(void)
{
    // Initialize test ID and log entry
    gTestID = 41;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Data type declarations
    tvError_t ret = tvERROR_NONE;
    int32_t YUVValue = 0;
    int32_t YUVValue_get = 0;

    // User input for gray pattern setting
    UT_LOG_MENU_INFO("Enter Gray level (0 - 255): ");
    readInt(&YUVValue);

    if (YUVValue < 0 || YUVValue > 255)
    {
        UT_LOG_ERROR("Invalid Gray value:[%d]. Expected range 0 - 255.", YUVValue);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    UT_LOG_INFO("Calling SetGrayPattern(IN:YUVValue:[%d])", YUVValue);
    ret = SetGrayPattern(YUVValue);
    UT_LOG_INFO("Result SetGrayPattern(IN:YUVValue:[%d]) tvError_t:[%s]", YUVValue,UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    UT_LOG_INFO("Calling GetGrayPattern(OUT:YUVValue:[])");
    ret = GetGrayPattern(&YUVValue_get);
    UT_LOG_INFO("Result GetGrayPattern(OUT:YUVValue:[%d]) tvError_t:[%s]",YUVValue_get, UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);
    ASSERT_COMPARE(YUVValue, YUVValue_get);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}
/**
 * @brief Tests the EnableLDIMPixelCompensation function.
 *
 * This test function enables or disables the pixel compensation block based on user input.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 42
 *
 * **Test Specification:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_EnableLDIMPixelCompensation(void)
{
    // Initialize test ID and log entry
    gTestID = 42;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Data type declarations
    tvError_t ret = tvERROR_NONE;
    int32_t input_mode = 0;  // Use an int32_t to read user input

    // User input for enabling or disabling pixel compensation
    UT_LOG_MENU_INFO("Enter mode for pixel compensation (1 to enable, 0 to disable): ");
    readInt(&input_mode);

    // Validate user input
    if (input_mode != 0 && input_mode != 1)
    {
        UT_LOG_ERROR("Invalid mode value:[%d]. Expected 0 or 1.", input_mode);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Map the user input to boolean values
    bool enable = (input_mode == 1);

    UT_LOG_INFO("Calling EnableLDIMPixelCompensation(IN:Mode:[%s])", enable ? "true" : "false");
    ret = EnableLDIMPixelCompensation(enable);
    UT_LOG_INFO("Result EnableLDIMPixelCompensation(IN:Mode:[%s]) tvError_t:[%s]", enable ? "true" : "false", UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    // Log function exit
    UT_LOG_INFO("Out %s", __FUNCTION__);
}
/**
 * @brief Tests the EnableLDIM function.
 *
 * This test function enables or disables the local dimming module based on user input.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 43
 *
 * **Test Specification:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_EnableLDIM(void)
{
    // Initialize test ID and log entry
    gTestID = 43;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Data type declarations
    tvError_t ret = tvERROR_NONE;
    int32_t input_mode = 0;  // Use an int32_t to read user input

    // User input for enabling or disabling local dimming
    UT_LOG_MENU_INFO("Enter mode for local dimming (1 to enable, 0 to disable): ");
    readInt(&input_mode);

    // Validate user input
    if (input_mode != 0 && input_mode != 1)
    {
        UT_LOG_ERROR("Invalid mode value:[%d]. Expected 0 or 1.", input_mode);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    bool enable = (input_mode == 1);
    UT_LOG_INFO("Calling EnableLDIM(IN:Mode:[%s])", enable ? "true" : "false");
    ret = EnableLDIM(enable);
    UT_LOG_INFO("Result EnableLDIM(IN:Mode:[%s]) tvError_t:[%s]",
                 enable ? "true" : "false",
                 UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    // Log function exit
    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief Tests the SetBacklightTestMode function.
 *
 * This test function sets the backlight test mode based on user input.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 44
 *
 * **Test Specification:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_SetBacklightTestMode(void)
{
    // Initialize test ID and log entry
    gTestID = 44;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Data type declarations
    tvError_t ret = tvERROR_NONE;
    int32_t input_mode = 0;
    ldimStateLevel_t mode;

    // Display supported backlight test modes
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Backlight Test Modes");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Backlight Test Mode");
    for (int32_t i = tvBacklightTestMode_Normal; i < tvBacklightTestMode_Max; i++)
    {
        UT_LOG_MENU_INFO("%d. %s", i , UT_Control_GetMapString(tvBacklightTestMode_mapTable, i));
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");

    // User input for setting backlight test mode
    UT_LOG_MENU_INFO("Enter backlight test mode: ");
    readInt(&input_mode);

    // Validate user input
    if (input_mode < tvBacklightTestMode_Normal || input_mode >= (tvBacklightTestMode_Max ))
    {
        UT_LOG_ERROR("Invalid input mode: [%d]. Please enter a valid mode (0-3).", input_mode);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Set the mode based on user input
    mode = (ldimStateLevel_t)input_mode;

    // Log the function call and result
    UT_LOG_INFO("Calling SetBacklightTestMode(IN: Mode: [%s])",
                 UT_Control_GetMapString(tvBacklightTestMode_mapTable, mode));
    ret = SetBacklightTestMode(mode);
    UT_LOG_INFO("Result SetBacklightTestMode(IN: Mode: [%s]) tvError_t: [%s]",
                 UT_Control_GetMapString(tvBacklightTestMode_mapTable, mode),
                 UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    // Log function exit
    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief Tests the EnableDynamicContrast function.
 *
 * This test function enables or disables the dynamic contrast module based on user input.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 45
 *
 * **Test Specification:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_EnableDynamicContrast(void)
{
    // Initialize test ID and log entry
    gTestID = 45;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Data type declarations
    tvError_t ret = tvERROR_NONE;
    int32_t input_mode = 0;
    bool enable;

    // User input for enabling or disabling dynamic contrast
    UT_LOG_MENU_INFO("Enter mode for dynamic contrast (1 to enable, 0 to disable): ");
    readInt(&input_mode);

    // Map the user input to boolean values
    if (input_mode == 1)
    {
        enable = true;
    }
    else if (input_mode == 0)
    {
        enable = false;
    }
    else
    {
        UT_LOG_ERROR("Invalid input mode:[%d]. Please enter 1 to enable or 0 to disable.", input_mode);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    UT_LOG_INFO("Calling EnableDynamicContrast(IN:Mode:[%s])",
                 enable ? "true" : "false");
    ret = EnableDynamicContrast(enable);
    UT_LOG_INFO("Result EnableDynamicContrast(IN:Mode:[%s]) tvError_t:[%s]",
                 enable ? "true" : "false",
                 UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief Tests the EnableLocalContrast function.
 *
 * This test function enables or disables the local contrast module based on user input.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 46
 *
 * **Test Specification:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_EnableLocalContrast(void)
{
    // Initialize test ID and log entry
    gTestID = 46;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Data type declarations
    tvError_t ret = tvERROR_NONE;
    int32_t input_mode = 0;
    bool enable;

    // User input for enabling or disabling local contrast
    UT_LOG_MENU_INFO("Enter mode for local contrast (1 to enable, 0 to disable): ");
    readInt(&input_mode);

    // Map the user input to boolean values
    if (input_mode == 1)
    {
        enable = true;
    }
    else if (input_mode == 0)
    {
        enable = false;
    }
    else
    {
        UT_LOG_ERROR("Invalid input mode:[%d]. Please enter 1 to enable or 0 to disable.", input_mode);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    UT_LOG_INFO("Calling EnableLocalContrast(IN:Mode:[%s])",
                 enable ? "true" : "false");
    ret = EnableLocalContrast(enable);
    UT_LOG_INFO("Result EnableLocalContrast(IN:Mode:[%s]) tvError_t:[%s]",
             enable ? "true" : "false",
             UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief This test saves the backlight value.
 *
 * This test function allows the user to select picture mode and video format,
 * and then saves the backlight value for the selected configuration.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 47
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_BacklightSave(void)
{
    // Initialize test ID and log entry
    gTestID = 47;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Data type declarations
    tvError_t result = tvERROR_NONE;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_IP; // Set video source directly to VIDEO_SOURCE_IP
    int32_t pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    int32_t backlightValue = -1;
    int32_t userPQChoice = 0;
    int32_t userFormatChoice = 0;
    int32_t userSrcChoice = 0;

    // List all options for Video sources
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video sources");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Sources");
    for (uint32_t j = VIDEO_SOURCE_ANALOGUE; j <= VIDEO_SOURCE_MAX; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j+1, UT_Control_GetMapString(tvVideoSrcType_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Source (index): ");
    readInt(&userSrcChoice);

    // Validate user input for video source
    if (userSrcChoice < 1 || userSrcChoice > VIDEO_SOURCE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video source. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    videoSource = userSrcChoice - 1;

    // List all options for PQ Mode
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Picture Modes");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Picture Modes");
    for (uint32_t j = PQ_MODE_STANDARD; j <= PQ_MODE_VIVID2; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j + 1, UT_Control_GetMapString(tvPQModeIndex_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Picture Mode (index): ");
    readInt(&userPQChoice);

    // Validate user input for Picture Mode
    if (userPQChoice < 1 || userPQChoice > PQ_MODE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Picture Mode. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    pqValue = userPQChoice - 1;

    // List all options for Video Format
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video Formats");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Formats");
    for (uint32_t k = VIDEO_FORMAT_NONE; k < VIDEO_FORMAT_MAX; k++)
    {
        UT_LOG_MENU_INFO("%u. %s", k + 1, UT_Control_GetMapString(tvVideoFormatType_mapTable, k)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Format (index): ");
    readInt(&userFormatChoice);

    // Validate user input for Video Format
    if (userFormatChoice < 1 || userFormatChoice > (int32_t)VIDEO_FORMAT_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video Format. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Map the user's 1-based choice back to 0-based index
    videoFormat = (tvVideoFormatType_t)userFormatChoice - 1;

    // Prompt the user for the backlight value
    UT_LOG_MENU_INFO("Enter the backlight value to set (0 - 100): ");
    readInt(&backlightValue);

    // Validate the user input for backlight value
    if (backlightValue < 0 || backlightValue > 100)
    {
        UT_LOG_ERROR("Invalid backlight value entered. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    UT_LOG_INFO("Calling SaveBacklight(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:Value:[%d])",
                 UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
                 pqValue,
                 UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
                 backlightValue);
    result = SaveBacklight(videoSource, pqValue, videoFormat, backlightValue);
    UT_LOG_INFO("Result SaveBacklight(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:Value:[%d]) tvError_t:[%s]",
             UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
             pqValue,
             UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
             backlightValue,
             UT_Control_GetMapString(tvError_mapTable, result));
    ASSERT(result == tvERROR_NONE);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief This test saves the TV dimming mode.
 *
 * This test function allows the user to select video source, picture mode, video format,
 * and dimming mode, and then saves the dimming mode for the selected configuration.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 48
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_TVDimmingModeSave(void)
{
    // Initialize test ID and log entry
    gTestID = 48;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Declare and initialize variables
    tvError_t result = tvERROR_NONE;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_IP; // Set video source directly to VIDEO_SOURCE_IP
    int32_t pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    tvDimmingMode_t dimmingMode = tvDimmingMode_MAX;
    int32_t userPQChoice = 0;
    int32_t userFormatChoice = 0;
    int32_t userDimmingModeChoice = 0;

    int32_t userSrcChoice = 0;

    // List all options for Video sources
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video sources");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Sources");
    for (uint32_t j = VIDEO_SOURCE_ANALOGUE; j <= VIDEO_SOURCE_MAX; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j+1, UT_Control_GetMapString(tvVideoSrcType_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Source (index): ");
    readInt(&userSrcChoice);

    // Validate user input for video source
    if (userSrcChoice < 1 || userSrcChoice > VIDEO_SOURCE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video source. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    videoSource = userSrcChoice - 1;


    // List all options for PQ Mode
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Picture Modes");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Picture Modes");
    for (uint32_t j = PQ_MODE_STANDARD; j <= PQ_MODE_VIVID2; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j + 1, UT_Control_GetMapString(tvPQModeIndex_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Picture Mode (index from above): ");
    readInt(&userPQChoice);

    // Validate user input for Picture Mode
    if (userPQChoice < 1 || userPQChoice > PQ_MODE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Picture Mode. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    pqValue = userPQChoice + PQ_MODE_STANDARD - 1; // Convert to zero-based index

    // List all options for Video Format
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video Formats");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Formats");
    for (uint32_t k = VIDEO_FORMAT_NONE; k < VIDEO_FORMAT_MAX; k++)
    {
        UT_LOG_MENU_INFO("%u. %s", k + 1, UT_Control_GetMapString(tvVideoFormatType_mapTable, k)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Format (index from above): ");
    readInt(&userFormatChoice);

    // Validate user input for Video Format
    if (userFormatChoice < 1 || userFormatChoice > (VIDEO_FORMAT_MAX - VIDEO_FORMAT_NONE))
    {
        UT_LOG_ERROR("Invalid choice of Video Format. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Map the user's 1-based choice back to 0-based index
    videoFormat = (tvVideoFormatType_t)(userFormatChoice + VIDEO_FORMAT_NONE - 1);

    // List all options for Dimming Mode
 UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Dimming Modes");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Dimming Modes");
    for (uint32_t l = 0; l < tvDimmingMode_MAX; l++)
    {
        UT_LOG_MENU_INFO("%u. %s", l + 1, UT_Control_GetMapString(tvDimmingMode_mapTable, l)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Dimming Mode (index from above): ");
    readInt(&userDimmingModeChoice);

    // Validate user input for Dimming Mode
    if (userDimmingModeChoice < 1 || userDimmingModeChoice > (int32_t)tvDimmingMode_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Dimming Mode. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Map the user's 1-based choice back to 0-based index
    dimmingMode = (tvDimmingMode_t)(userDimmingModeChoice - 1);

    UT_LOG_INFO("Calling SaveTVDimmingMode(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:DimmingMode:[%s])",
                 UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
                 pqValue,
                 UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
                 UT_Control_GetMapString(tvDimmingMode_mapTable, dimmingMode));

    result = SaveTVDimmingMode(videoSource, pqValue, videoFormat, dimmingMode);

    UT_LOG_INFO("Result SaveTVDimmingMode(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:DimmingMode:[%s]) tvError_t:[%s]",
                 UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
                 pqValue,
                 UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
                 UT_Control_GetMapString(tvDimmingMode_mapTable, dimmingMode),
                 UT_Control_GetMapString(tvError_mapTable, result));

    ASSERT(result == tvERROR_NONE);

    // Log function exit
    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief This test saves the Local Dimming Level.
 *
 * This test function allows the user to select picture mode, video format,
 * and local dimming level, and then saves the local dimming level for the selected configuration.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 49
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_LocalDimmingLevelSave(void)
{
    // Initialize test ID and log entry
    gTestID = 49;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Declare and initialize variables
    tvError_t result = tvERROR_NONE;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_IP; // Set video source directly to VIDEO_SOURCE_IP
    int32_t pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    ldimStateLevel_t dimmingLevel = LDIM_STATE_MAX; // Initialize with the maximum value to handle invalid input
    int32_t userPQChoice = 0;
    int32_t userFormatChoice = 0;

    int32_t userSrcChoice = 0;

    // List all options for Video sources
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video sources");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Sources");
    for (uint32_t j = VIDEO_SOURCE_ANALOGUE; j <= VIDEO_SOURCE_MAX; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j+1, UT_Control_GetMapString(tvVideoSrcType_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Source (index): ");
    readInt(&userSrcChoice);

    // Validate user input for video source
    if (userSrcChoice < 1 || userSrcChoice > VIDEO_SOURCE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video source. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    videoSource = userSrcChoice - 1;


    // List all options for Picture Mode
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Picture Modes");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Picture Modes");
    for (uint32_t j = PQ_MODE_STANDARD; j <= PQ_MODE_VIVID2; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j + 1, UT_Control_GetMapString(tvPQModeIndex_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Picture Mode (index): ");
    readInt(&userPQChoice);

    // Validate user input for Picture Mode
    if (userPQChoice < 1 || userPQChoice > (int32_t)PQ_MODE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Picture Mode. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Map the user's 1-based choice back to 0-based index
    pqValue = (int32_t)userPQChoice - 1;

    // List all options for Video Format
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video Formats");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Formats");
    for (uint32_t k = VIDEO_FORMAT_NONE; k < VIDEO_FORMAT_MAX; k++)
    {
        UT_LOG_MENU_INFO("%u. %s", k + 1, UT_Control_GetMapString(tvVideoFormatType_mapTable, k)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Format (index): ");
    readInt(&userFormatChoice);

    // Validate user input for Video Format
    if (userFormatChoice < 1 || userFormatChoice > (int32_t)VIDEO_FORMAT_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video Format. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    videoFormat = (tvVideoFormatType_t)userFormatChoice - 1;

    // List all options for Local Dimming Level
    UT_LOG_MENU_INFO("Supported Local Dimming Levels:");
    for (int32_t i = 0; i < LDIM_STATE_MAX; i++)
    {
        UT_LOG_MENU_INFO("%d. %s", i, UT_Control_GetMapString(ldimStateLevel_mapTable, (ldimStateLevel_t)i));
    }
    UT_LOG_MENU_INFO("Enter your choice of Local Dimming Level (index): ");
    readInt((int32_t *)&dimmingLevel);

    // Validate the local dimming level input
    if (dimmingLevel < LDIM_STATE_NONBOOST || dimmingLevel >= LDIM_STATE_MAX)
    {
        UT_LOG_ERROR("Invalid Local Dimming Level entered. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    UT_LOG_INFO("Calling SaveLocalDimmingLevel(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:DimmingLevel:[%s])",
                 UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
                 pqValue,
                 UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
                 UT_Control_GetMapString(ldimStateLevel_mapTable, dimmingLevel));
    result = SaveLocalDimmingLevel(videoSource, pqValue, videoFormat, dimmingLevel);
    UT_LOG_INFO("Result SaveLocalDimmingLevel(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:DimmingLevel:[%s]) tvError_t:[%s]",
             UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
             pqValue,
             UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
             UT_Control_GetMapString(ldimStateLevel_mapTable, dimmingLevel),
             UT_Control_GetMapString(tvError_mapTable, result));
    ASSERT(result == tvERROR_NONE);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}


/**
 * @brief Saves the brightness value.
 *
 * This function saves the brightness value in the picture profile database for the specific picture mode,
 * primary video format type, and primary video source. The saved brightness value should be applied
 * automatically whenever the specified picture mode is selected, the specified primary video format is played,
 * and the specified primary video source is selected. There will be no change in the current brightness value
 * applied in the PQ module.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 50
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_BrightnessSave(void)
{
    // Initialize test ID and log entry
    gTestID = 50;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Declare and initialize variables
    tvError_t result = tvERROR_NONE;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_IP; // Set video source to IP directly
    int32_t pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    int32_t brightnessValue = -1;
    int32_t userPQChoice = 0;
    int32_t userFormatChoice = 0;

    int32_t userSrcChoice = 0;

    // List all options for Video sources
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video sources");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Sources");
    for (uint32_t j = VIDEO_SOURCE_ANALOGUE; j <= VIDEO_SOURCE_MAX; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j+1, UT_Control_GetMapString(tvVideoSrcType_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Source (index): ");
    readInt(&userSrcChoice);

    // Validate user input for video source
    if (userSrcChoice < 1 || userSrcChoice > VIDEO_SOURCE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video source. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    videoSource = userSrcChoice - 1;


    // List all options for PQ Mode
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Picture Modes");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Picture Modes");
    for (uint32_t j = PQ_MODE_STANDARD; j <= PQ_MODE_VIVID2; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j + 1, UT_Control_GetMapString(tvPQModeIndex_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Picture Mode (index): ");
    readInt(&userPQChoice);

    // Validate user input for Picture Mode
    if (userPQChoice < 1 || userPQChoice > (int32_t)PQ_MODE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Picture Mode. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    pqValue = (int32_t)userPQChoice - 1;

    // List all options for Video Format
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video Formats");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Formats");
    for (uint32_t k = VIDEO_FORMAT_NONE; k < VIDEO_FORMAT_MAX; k++)
    {
        UT_LOG_MENU_INFO("%u. %s", k + 1, UT_Control_GetMapString(tvVideoFormatType_mapTable, k)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Format (index): ");
    readInt(&userFormatChoice);

    // Validate user input for Video Format
    if (userFormatChoice < 1 || userFormatChoice > (int32_t)VIDEO_FORMAT_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video Format. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Map the user's 1-based choice back to 0-based index
    videoFormat = (tvVideoFormatType_t)userFormatChoice - 1;

    // Prompt the user for the brightness value
    UT_LOG_MENU_INFO("Enter the brightness value to set (0 - 100): ");
    readInt(&brightnessValue);

    // Validate the brightness value input
    if (brightnessValue < 0 || brightnessValue > 100)
    {
        UT_LOG_ERROR("Invalid brightness value entered. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    UT_LOG_INFO("Calling SaveBrightness(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:Value:[%d])",
                 UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
                 pqValue,
                 UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
                 brightnessValue);
    result = SaveBrightness(videoSource, pqValue, videoFormat, brightnessValue);
    UT_LOG_INFO("Result SaveBrightness(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:BrightnessValue:[%d]) tvError_t:[%s]",
                 UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
                 pqValue,
                 UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
                 brightnessValue,
                 UT_Control_GetMapString(tvError_mapTable, result));

    ASSERT(result == tvERROR_NONE);

    // Log function exit
    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief Saves the contrast value.
 *
 * This function saves the contrast value in the picture profile database for the specific picture mode,
 * primary video format type, and primary video source. The saved contrast value should be applied
 * automatically whenever the specified picture mode is selected, the specified primary video format is played,
 * and the specified primary video source is selected. There will be no change in the current contrast value
 * applied in the PQ module.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 51
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_ContrastSave(void)
{
    // Initialize test ID and log entry
    gTestID = 51;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Declare and initialize variables
    tvError_t result = tvERROR_NONE;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_IP; // Set video source to IP directly
    int32_t pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    int32_t contrastValue = -1;
    int32_t userPQChoice = 0;
    int32_t userFormatChoice = 0;

    int32_t userSrcChoice = 0;

    // List all options for Video sources
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video sources");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Sources");
    for (uint32_t j = VIDEO_SOURCE_ANALOGUE; j <= VIDEO_SOURCE_MAX; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j+1, UT_Control_GetMapString(tvVideoSrcType_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Source (index): ");
    readInt(&userSrcChoice);

    // Validate user input for video source
    if (userSrcChoice < 1 || userSrcChoice > VIDEO_SOURCE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video source. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    videoSource = userSrcChoice - 1;



    // List all options for PQ Mode
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Picture Modes");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Picture Modes");
    for (uint32_t j = PQ_MODE_STANDARD; j <= PQ_MODE_VIVID2; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j + 1, UT_Control_GetMapString(tvPQModeIndex_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Picture Mode (index): ");
    readInt(&userPQChoice);

    // Validate user input for Picture Mode
    if (userPQChoice < 1 || userPQChoice > (int32_t)PQ_MODE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Picture Mode. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    pqValue = (int32_t)userPQChoice - 1;

    // List all options for Video Format
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video Formats");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Formats");
    for (uint32_t k = VIDEO_FORMAT_NONE; k < VIDEO_FORMAT_MAX; k++)
    {
        UT_LOG_MENU_INFO("%u. %s", k + 1, UT_Control_GetMapString(tvVideoFormatType_mapTable, k)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Format (index): ");
    readInt(&userFormatChoice);

    // Validate user input for Video Format
    if (userFormatChoice < 1 || userFormatChoice > (int32_t)VIDEO_FORMAT_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video Format. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Map the user's 1-based choice back to 0-based index
    videoFormat = (tvVideoFormatType_t)userFormatChoice - 1;

    // Prompt the user for the contrast value
    UT_LOG_MENU_INFO("Enter the contrast value to set (0 - 100): ");
    readInt(&contrastValue);

    // Validate the contrast value input
    if (contrastValue < 0 || contrastValue > 100)
    {
        UT_LOG_ERROR("Invalid contrast value entered. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    UT_LOG_INFO("Calling SaveContrast(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:Value:[%d])",
                 UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
                 pqValue,
                 UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
                 contrastValue);

    // Save the contrast value
    result = SaveContrast(videoSource, pqValue, videoFormat, contrastValue);
    UT_LOG_INFO("Result SaveContrast(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:ContrastValue:[%d]) tvError_t:[%s]",
                 UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
                 pqValue,
                 UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
                 contrastValue,
                 UT_Control_GetMapString(tvError_mapTable, result));

    ASSERT(result == tvERROR_NONE);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief Saves the sharpness value.
 *
 * This function saves the sharpness value in the picture profile database for the specific picture mode,
 * primary video format type, and primary video source. The saved sharpness value should be applied
 * automatically whenever the specified picture mode is selected, the specified primary video format is played,
 * and the specified primary video source is selected. There will be no change in the current sharpness value
 * applied in the PQ module.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 52
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_SharpnessSave(void)
{
    // Initialize test ID and log entry
    gTestID = 52;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Declare and initialize variables
    tvError_t result = tvERROR_NONE;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_IP; // Set video source to IP directly
    int32_t pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    int32_t sharpnessValue = -1;
    int32_t userPQChoice = 0;
    int32_t userFormatChoice = 0;

    int32_t userSrcChoice = 0;

    // List all options for Video sources
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video sources");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Sources");
    for (uint32_t j = VIDEO_SOURCE_ANALOGUE; j <= VIDEO_SOURCE_MAX; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j+1, UT_Control_GetMapString(tvVideoSrcType_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Source (index): ");
    readInt(&userSrcChoice);

    // Validate user input for video source
    if (userSrcChoice < 1 || userSrcChoice > VIDEO_SOURCE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video source. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    videoSource = userSrcChoice - 1;


    // List all options for PQ Mode
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Picture Modes");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Picture Modes");
    for (uint32_t j = PQ_MODE_STANDARD; j <= PQ_MODE_VIVID2; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j + 1, UT_Control_GetMapString(tvPQModeIndex_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Picture Mode (index): ");
    readInt(&userPQChoice);

    // Validate user input for Picture Mode
    if (userPQChoice < 1 || userPQChoice > (int32_t)PQ_MODE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Picture Mode. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    pqValue = (int32_t)userPQChoice - 1;

    // List all options for Video Format
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video Formats");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Formats");
    for (uint32_t k = VIDEO_FORMAT_NONE; k < VIDEO_FORMAT_MAX; k++)
    {
        UT_LOG_MENU_INFO("%u. %s", k + 1, UT_Control_GetMapString(tvVideoFormatType_mapTable, k)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Format (index): ");
    readInt(&userFormatChoice);
 
    videoFormat = (tvVideoFormatType_t)userFormatChoice - 1;

    // Validate user input for Video Format
    if (userFormatChoice < 1 || userFormatChoice > (int32_t)VIDEO_FORMAT_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video Format. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Prompt the user for the sharpness value
    UT_LOG_MENU_INFO("Enter the sharpness value to set (0 - 100): ");
    readInt(&sharpnessValue);

    // Validate the sharpness value input
    if (sharpnessValue < 0 || sharpnessValue > 100)
    {
        UT_LOG_ERROR("Invalid sharpness value entered. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    UT_LOG_INFO("Calling SaveSharpness(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:Value:[%d])",
                 UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
                 pqValue,
                 UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
                 sharpnessValue);

    // Save the sharpness value
    result = SaveSharpness(videoSource, pqValue, videoFormat, sharpnessValue);
    UT_LOG_INFO("Result SaveSharpness(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:SharpnessValue:[%d]) tvError_t:[%s]",
                 UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
                 pqValue,
                 UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
                 sharpnessValue,
                 UT_Control_GetMapString(tvError_mapTable, result));

    ASSERT(result == tvERROR_NONE);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief Saves the hue value.
 *
 * This function saves the hue value in the picture profile database for the specific picture mode,
 * primary video format type, and primary video source. The saved hue value should be applied
 * automatically whenever the specified picture mode is selected, the specified primary video format is played,
 * and the specified primary video source is selected. There will be no change in the current hue value
 * applied in the PQ module.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 53
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_HueSave(void)
{
    // Initialize test ID and log entry
    gTestID = 53;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Declare and initialize variables
    tvError_t result = tvERROR_NONE;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_IP; // Set video source to IP directly
    int32_t pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    int32_t hueValue = -1;
    int32_t userPQChoice = 0;
    int32_t userFormatChoice = 0;

    int32_t userSrcChoice = 0;

    // List all options for Video sources
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video sources");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Sources");
    for (uint32_t j = VIDEO_SOURCE_ANALOGUE; j <= VIDEO_SOURCE_MAX; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j+1, UT_Control_GetMapString(tvVideoSrcType_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Source (index): ");
    readInt(&userSrcChoice);

    // Validate user input for video source
    if (userSrcChoice < 1 || userSrcChoice > VIDEO_SOURCE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video source. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    videoSource = userSrcChoice - 1;


    // List all options for PQ Mode
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Picture Modes");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Picture Modes");
    for (uint32_t j = PQ_MODE_STANDARD; j <= PQ_MODE_VIVID2; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j + 1, UT_Control_GetMapString(tvPQModeIndex_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Picture Mode (index): ");
    readInt(&userPQChoice);

    // Validate user input for Picture Mode
    if (userPQChoice < 1 || userPQChoice > (int32_t)PQ_MODE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Picture Mode. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    pqValue = (int32_t)userPQChoice - 1;

    // List all options for Video Format
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video Formats");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Formats");
    for (uint32_t k = VIDEO_FORMAT_NONE; k < VIDEO_FORMAT_MAX; k++)
    {
        UT_LOG_MENU_INFO("%u. %s", k + 1, UT_Control_GetMapString(tvVideoFormatType_mapTable, k)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Format (index): ");
    readInt(&userFormatChoice);

    // Validate user input for Video Format
    if (userFormatChoice < 1 || userFormatChoice > (int32_t )VIDEO_FORMAT_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video Format. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    videoFormat = (tvVideoFormatType_t)userFormatChoice - 1;

    // Prompt the user for the hue value
    UT_LOG_MENU_INFO("Enter the hue value to set (0 - 100): ");
    readInt(&hueValue);

    // Validate the hue value input
    if (hueValue < 0 || hueValue > 100)
    {
        UT_LOG_ERROR("Invalid hue value entered. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    UT_LOG_INFO("Calling SaveHue(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:Value:[%d])",
                 UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
                 pqValue,
                 UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
                 hueValue);
    // Save the hue value
    result = SaveHue(videoSource, pqValue, videoFormat, hueValue);
    UT_LOG_INFO("Result SaveHue(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:HueValue:[%d]) tvError_t:[%s]",
             UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
             pqValue,
             UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
             hueValue,
             UT_Control_GetMapString(tvError_mapTable, result));

    ASSERT(result == tvERROR_NONE);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}
/**
 * @brief Saves the saturation value.
 *
 * This function saves the saturation value in the picture profile database for the specific picture mode,
 * primary video format type, and primary video source. The saved saturation value should be applied
 * automatically whenever the specified picture mode is selected, the specified primary video format is played,
 * and the specified primary video source is selected. There will be no change in the current saturation value
 * applied in the PQ module.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 54
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_SaturationSave(void)
{
    // Initialize test ID and log entry
    gTestID = 54;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Declare and initialize variables
    tvError_t result = tvERROR_NONE;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_IP; // Set video source to IP directly
    int32_t pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    int32_t saturationValue = -1;
    int32_t userPQChoice = 0;
    int32_t userFormatChoice = 0;

    int32_t userSrcChoice = 0;

    // List all options for Video sources
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video sources");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Sources");
    for (uint32_t j = VIDEO_SOURCE_ANALOGUE; j <= VIDEO_SOURCE_MAX; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j+1, UT_Control_GetMapString(tvVideoSrcType_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Source (index): ");
    readInt(&userSrcChoice);

    // Validate user input for video source
    if (userSrcChoice < 1 || userSrcChoice > VIDEO_SOURCE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video source. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    videoSource = userSrcChoice - 1;


    // List all options for PQ Mode
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Picture Modes");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Picture Modes");
    for (uint32_t j = PQ_MODE_STANDARD; j <= PQ_MODE_VIVID2; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j + 1, UT_Control_GetMapString(tvPQModeIndex_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Picture Mode (index): ");
    readInt(&userPQChoice);

    // Validate user input for Picture Mode
    if (userPQChoice < 1 || userPQChoice > (int32_t )PQ_MODE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Picture Mode. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    pqValue = (int32_t )userPQChoice - 1;

    // List all options for Video Format
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video Formats");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Formats");
    for (uint32_t k = VIDEO_FORMAT_NONE; k < VIDEO_FORMAT_MAX; k++)
    {
        UT_LOG_MENU_INFO("%u. %s", k + 1, UT_Control_GetMapString(tvVideoFormatType_mapTable, k)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Format (index): ");
    readInt(&userFormatChoice);

    // Validate user input for Video Format
    if (userFormatChoice < 1 || userFormatChoice > (int32_t )VIDEO_FORMAT_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video Format. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    videoFormat = (tvVideoFormatType_t)userFormatChoice - 1;

    // Prompt the user for the saturation value
    UT_LOG_MENU_INFO("Enter the saturation value to set (0 - 100): ");
    readInt(&saturationValue);

    // Validate the saturation value input
    if (saturationValue < 0 || saturationValue > 100)
    {
        UT_LOG_ERROR("Invalid saturation value entered. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    UT_LOG_INFO("Calling SaveSaturation(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:Value:[%d])",
                 UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
                 pqValue,
                 UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
                 saturationValue);
    // Save the saturation value
    result = SaveSaturation(videoSource, pqValue, videoFormat, saturationValue);
    UT_LOG_INFO("Result SaveSaturation(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:SaturationValue:[%d]) tvError_t:[%s]",
             UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
             pqValue,
             UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
             saturationValue,
             UT_Control_GetMapString(tvError_mapTable, result));
    ASSERT(result == tvERROR_NONE);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief Saves the color temperature value.
 *
 * This function saves the color temperature value in the picture profile database for the specific picture mode,
 * primary video format type, and primary video source. The saved color temperature value should be applied
 * automatically whenever the specified picture mode is selected, the specified primary video format is played,
 * and the specified primary video source is selected. There will be no change in the current color temperature value
 * applied in the PQ module.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 55
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_ColorTemperatureSave(void)
{
    // Initialize test ID and log entry
    gTestID = 55;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Declare and initialize all variables at the top
    tvError_t result = tvERROR_NONE;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_IP; // Set video source to IP directly
    int32_t pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE; // Initialize to default value
    tvColorTemp_t colorTemp = tvColorTemp_MAX; // Initialize to default value
    int32_t userChoice = 0; // Declare at the top

    int32_t userSrcChoice = 0;

    // List all options for Video sources
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video sources");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Sources");
    for (uint32_t j = VIDEO_SOURCE_ANALOGUE; j <= VIDEO_SOURCE_MAX; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j+1, UT_Control_GetMapString(tvVideoSrcType_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Source (index): ");
    readInt(&userSrcChoice);

    // Validate user input for video source
    if (userSrcChoice < 1 || userSrcChoice > VIDEO_SOURCE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video source. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    videoSource = userSrcChoice - 1;


    // List all options for PQ Mode
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Picture Modes");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Picture Modes");
    for (uint32_t j = PQ_MODE_STANDARD; j <= PQ_MODE_VIVID2; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j + 1, UT_Control_GetMapString(tvPQModeIndex_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    // Get user choice for Picture Mode
    UT_LOG_MENU_INFO("Enter your choice of Picture Mode (index): ");
    readInt(&userChoice);

    // Validate user choice for Picture Mode
    if (userChoice < 1 || userChoice > (int32_t )PQ_MODE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Picture Mode. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    pqValue = (int32_t )userChoice - 1;

    // List all options for Video Format
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video Formats");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Formats");
    for (uint32_t k = VIDEO_FORMAT_NONE; k < VIDEO_FORMAT_MAX; k++)
    {
        UT_LOG_MENU_INFO("%u. %s", k + 1, UT_Control_GetMapString(tvVideoFormatType_mapTable, k)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Format (index): ");
    readInt(&userChoice);

    // Validate user choice for Video Format
    if (userChoice < 1 || userChoice > (int32_t )VIDEO_FORMAT_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video Format. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    videoFormat = (tvVideoFormatType_t)userChoice - 1;

    // Display available color temperatures to the user
    UT_LOG_MENU_INFO("Supported Color Temperatures:");
    for (uint32_t i = tvColorTemp_STANDARD; i < tvColorTemp_MAX; i++)
    {
        UT_LOG_MENU_INFO("%u. %s", i + 1, UT_Control_GetMapString(tvColorTemp_mapTable, i)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");

    // Get user input for selecting a color temperature
    UT_LOG_MENU_INFO("Enter the number corresponding to the Color Temperature: ");
    readInt(&userChoice);

    // Validate user choice for Color Temperature
    if (userChoice < 1 || userChoice > (int32_t )tvColorTemp_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Color Temperature. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    colorTemp = userChoice - 1; // Map 1-based choice to 0-based index

    UT_LOG_INFO("Calling SaveColorTemperature(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:Value:[%s])",
                 UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
                 pqValue,
                 UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
                 UT_Control_GetMapString(tvColorTemp_mapTable, colorTemp));
    // Save the color temperature value
    result = SaveColorTemperature(videoSource, pqValue, videoFormat, colorTemp);
    UT_LOG_INFO("Result SaveColorTemperature(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:ColorTemperature:[%s]) tvError_t:[%s]",
             UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
             pqValue,
             UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
             UT_Control_GetMapString(tvColorTemp_mapTable, colorTemp),
             UT_Control_GetMapString(tvError_mapTable, result));    ASSERT(result == tvERROR_NONE);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief Saves the aspect ratio value.
 *
 * This function saves the aspect ratio value in the picture profile database for the specific picture mode,
 * primary video format type, and primary video source. The saved aspect ratio value should be applied
 * automatically whenever the specified picture mode is selected, the specified primary video format is played,
 * and the specified primary video source is selected. There will be no change in the current aspect ratio value
 * applied in the PQ module.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 56
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_AspectRatioSave(void)
{
    // Initialize test ID and log entry
    gTestID = 56;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Declare and initialize all variables at the top
    tvError_t result = tvERROR_NONE;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_IP; // Set video source to IP directly
    int32_t pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE; // Initialize to default value
    tvDisplayMode_t aspectRatio = tvDisplayMode_MAX; // Initialize to default value
    int32_t userChoice = 0; // Declare at the top

    int32_t userSrcChoice = 0;

    // List all options for Video sources
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video sources");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Sources");
    for (uint32_t j = VIDEO_SOURCE_ANALOGUE; j <= VIDEO_SOURCE_MAX; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j+1, UT_Control_GetMapString(tvVideoSrcType_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Source (index): ");
    readInt(&userSrcChoice);

    // Validate user input for video source
    if (userSrcChoice < 1 || userSrcChoice > VIDEO_SOURCE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video source. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    videoSource = userSrcChoice - 1;


    // List all options for Picture Mode
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Picture Modes");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Picture Modes");
    for (uint32_t j = PQ_MODE_STANDARD; j <= PQ_MODE_VIVID2; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j + 1, UT_Control_GetMapString(tvPQModeIndex_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    // Get user choice for Picture Mode
    UT_LOG_MENU_INFO("Enter your choice of Picture Mode (index): ");
    readInt(&pqValue);

    // Validate user choice for Picture Mode
    if (pqValue < 1 || pqValue > (int32_t )PQ_MODE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Picture Mode. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Map the user's 1-based choice to 0-based index
    pqValue = (int32_t ) pqValue - 1;

    // List all options for Video Format
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video Formats");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Formats");
    for (uint32_t k = VIDEO_FORMAT_NONE; k < VIDEO_FORMAT_MAX; k++)
    {
        UT_LOG_MENU_INFO("%u. %s", k + 1, UT_Control_GetMapString(tvVideoFormatType_mapTable, k)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Format (index): ");
    readInt((int32_t *)&videoFormat);

    // Validate user choice for Video Format
    if ((int32_t )videoFormat < 1 || (int32_t )videoFormat > (int32_t )VIDEO_FORMAT_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video Format. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Map the user's 1-based choice to 0-based index
    videoFormat = (tvVideoFormatType_t)videoFormat - 1;

    // Display available aspect ratios to the user
    UT_LOG_MENU_INFO("Supported Aspect Ratios:");
    for (uint32_t i = tvDisplayMode_4x3; i < tvDisplayMode_MAX; i++)
    {
        UT_LOG_MENU_INFO("%u. %s", i + 1, UT_Control_GetMapString(tvDisplayMode_mapTable, i)); // Display index starting from 1
    }

    // Get user input for selecting an aspect ratio
    UT_LOG_MENU_INFO("Enter the number corresponding to the Aspect Ratio: ");
    readInt(&userChoice);

    // Validate user choice for Aspect Ratio
    if (userChoice < 1 || userChoice > (int32_t )tvDisplayMode_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Aspect Ratio. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    aspectRatio = userChoice - 1; // Map 1-based choice to 0-based index

    UT_LOG_INFO("Calling SaveAspectRatio(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:Value:[%s])",
                 UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
                 pqValue,
                 UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
                 UT_Control_GetMapString(tvDisplayMode_mapTable, aspectRatio));


    result = SaveAspectRatio(videoSource, pqValue, videoFormat, aspectRatio);

    UT_LOG_INFO("Result SaveAspectRatio(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:AspectRatio:[%s]) tvError_t:[%s]",
                 UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
                 pqValue,
                 UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
                 UT_Control_GetMapString(tvDisplayMode_mapTable, aspectRatio),
                 UT_Control_GetMapString(tvError_mapTable, result));

    ASSERT(result == tvERROR_NONE);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief Saves the low latency index value.
 *
 * This function saves the low latency index value in the picture profile database for the specific picture mode,
 * primary video format type, and primary video source. The saved low latency index value should be applied
 * automatically whenever the specified picture mode is selected, specified primary video format is played,
 * and specified primary video source is selected. There will be no change in the current low latency index
 * value applied in the PQ module.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 53
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_LowLatencySave(void)
{
    // Declare and initialize all variables at the top
    gTestID = 57;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    tvError_t result = tvERROR_NONE;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_IP; // Set video source to IP directly
    int32_t pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    int32_t lowLatencyIndex = -1; // Initialize to an invalid value
    int32_t userPQChoice = 0;
    int32_t userVideoFormatChoice = 0;

    int32_t userSrcChoice = 0;

    // List all options for Video sources
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video sources");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Sources");
    for (uint32_t j = VIDEO_SOURCE_ANALOGUE; j <= VIDEO_SOURCE_MAX; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j+1, UT_Control_GetMapString(tvVideoSrcType_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Source (index): ");
    readInt(&userSrcChoice);

    // Validate user input for video source
    if (userSrcChoice < 1 || userSrcChoice > VIDEO_SOURCE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video source. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    videoSource = userSrcChoice - 1;


    // List all options for Picture Mode
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Picture Modes");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Picture Modes");
    for (uint32_t j = PQ_MODE_STANDARD; j <= PQ_MODE_VIVID2; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j + 1, UT_Control_GetMapString(tvPQModeIndex_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    // Get user choice for Picture Mode
    UT_LOG_MENU_INFO("Enter your choice of Picture Mode (index): ");
    readInt(&userPQChoice);

    if (userPQChoice < 1 || userPQChoice > (int32_t )PQ_MODE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Picture Mode. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    pqValue = (int32_t )userPQChoice - 1;

    // List all options for Video Format
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video Formats");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Formats");
    for (uint32_t k = VIDEO_FORMAT_NONE; k < VIDEO_FORMAT_MAX; k++)
    {
        UT_LOG_MENU_INFO("%u. %s", k + 1, UT_Control_GetMapString(tvVideoFormatType_mapTable, k)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Format (index): ");
    readInt((int32_t *)&userVideoFormatChoice);

    if ((int32_t )userVideoFormatChoice < 1 || (int32_t )userVideoFormatChoice > (int32_t )VIDEO_FORMAT_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video Format. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    videoFormat = userVideoFormatChoice - 1;

    // Prompt the user for the low latency index
    UT_LOG_MENU_INFO("Enter the Low Latency Index (0 or 1): ");
    readInt(&lowLatencyIndex);

    // Validate the low latency index input
    if (lowLatencyIndex != 0 && lowLatencyIndex != 1)
    {
        UT_LOG_ERROR("Invalid Low Latency Index entered. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    UT_LOG_INFO("Calling SaveLowLatencyState(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:Value:[%d])",
                 UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
                 pqValue,
                 UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
                 lowLatencyIndex);
    // Save the low latency index value
    result = SaveLowLatencyState(videoSource, pqValue, videoFormat, lowLatencyIndex);
    UT_LOG_INFO("Result SaveLowLatencyState(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:Value:[%d]) tvError_t:[%s]",
                 UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
                 pqValue,
                 UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
                 lowLatencyIndex,
                 UT_Control_GetMapString(tvError_mapTable, result));

    ASSERT(result == tvERROR_NONE);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}
/**
 * @brief Saves the Dolby Vision mode value.
 *
 * This function saves the Dolby Vision mode value in the picture profile database for the specific picture mode,
 * primary video format type, and primary video source. The saved Dolby Vision mode value should be applied
 * automatically whenever the specified picture mode is selected, specified primary video format (if handled via Dolby core)
 * is played, and specified primary video source is selected. There will be no change in the current Dolby Vision mode
 * value in the Dolby Vision core.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 58
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_DolbyVision_TestSpecification.md](../docs/pages/tvSettings_L3_DolbyVision_TestSpecification.md)
 */
void test_l3_tvSettings_DolbyVisionSave(void)
{
    // Declare and initialize all variables at the top
    gTestID = 58;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    tvError_t result = tvERROR_NONE;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_IP; // Set video source to IP directly
    int32_t pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    tvDolbyMode_t selectedMode = tvMode_Max; // Initialize to an invalid value
    int32_t userPQChoice = 0, userVideoFormatChoice = 0, userChoice = 0;

    int32_t userSrcChoice = 0;

    // List all options for Video sources
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video sources");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Sources");
    for (uint32_t j = VIDEO_SOURCE_ANALOGUE; j <= VIDEO_SOURCE_MAX; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j+1, UT_Control_GetMapString(tvVideoSrcType_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Source (index): ");
    readInt(&userSrcChoice);

    // Validate user input for video source
    if (userSrcChoice < 1 || userSrcChoice > VIDEO_SOURCE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video source. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    videoSource = userSrcChoice - 1;

    // List all options for Picture Mode
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Picture Modes");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Picture Modes");
    for (uint32_t j = PQ_MODE_STANDARD; j <= PQ_MODE_VIVID2; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j + 1, UT_Control_GetMapString(tvPQModeIndex_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    // Get user choice for Picture Mode
    UT_LOG_MENU_INFO("Enter your choice of Picture Mode (index): ");
    readInt(&userPQChoice);

    if (userPQChoice < 1 || userPQChoice > (int32_t )PQ_MODE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Picture Mode. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    pqValue = (int32_t )userPQChoice - 1;

    // List all options for Video Format
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video Formats");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Formats");
    for (uint32_t k = VIDEO_FORMAT_NONE; k < VIDEO_FORMAT_MAX; k++)
    {
        UT_LOG_MENU_INFO("%u. %s", k + 1, UT_Control_GetMapString(tvVideoFormatType_mapTable, k)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Format (index): ");
    readInt((int*)&userVideoFormatChoice);

    if ((int32_t )userVideoFormatChoice < 1 || (int32_t )userVideoFormatChoice > (int32_t )VIDEO_FORMAT_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video Format. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Map the user's 1-based choice to 0-based index
    videoFormat = (tvVideoFormatType_t)userVideoFormatChoice - 1;
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Dolby Vision Modes:");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Dolby Vision Modes:");
    for (uint32_t i = tvDolbyMode_Dark; i <= tvHLGMode_Game; i++)
    {
        UT_LOG_MENU_INFO("%u. %s", i + 1, UT_Control_GetMapString(tvDolbyMode_mapTable, i)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter the number corresponding to the Dolby Vision Mode: ");
    readInt(&userChoice);

    // Validate user choice
    if (userChoice < 1 || userChoice > (int32_t )tvHLGMode_Game)
    {
        UT_LOG_ERROR("Invalid choice! Please select a valid Dolby Vision mode.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    selectedMode = userChoice - 1; // Map 1-based choice to 0-based index

    // Log function call with parameters
    UT_LOG_INFO("Calling SaveTVDolbyVisionMode(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:Value:[%d])",
                 UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
                 pqValue,
                 UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
                 selectedMode);

    // Save the Dolby Vision mode value
    result = SaveTVDolbyVisionMode(videoSource, pqValue, videoFormat, selectedMode);
    UT_LOG_INFO("Result SaveTVDolbyVisionMode(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:Value:[%d]) tvError_t:[%s]",
                 UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
                 pqValue,
                 UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
                 selectedMode,
                 UT_Control_GetMapString(tvError_mapTable, result));

    ASSERT(result == tvERROR_NONE);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief Saves the picture mode value.
 *
 * This function saves the picture mode value in the picture profile database for the specific primary video format type
 * and primary video source. The saved picture mode should be applied automatically whenever the
 * specified primary video format is played and specified primary video source is selected.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 59
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_PictureMode_TestSpecification.md](../docs/pages/tvSettings_L3_PictureMode_TestSpecification.md)
 */
void test_l3_tvSettings_PictureModeSave(void)
{
    // Declare and initialize all variables at the top
    gTestID = 59;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    tvError_t result = tvERROR_NONE;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_IP; // Set video source to IP directly
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    int32_t selectedPictureMode = 0;
    int32_t userChoice = 0;

    int32_t userSrcChoice = 0;

    // List all options for Video sources
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video sources");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Sources");
    for (uint32_t j = VIDEO_SOURCE_ANALOGUE; j <= VIDEO_SOURCE_MAX; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j+1, UT_Control_GetMapString(tvVideoSrcType_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Source (index): ");
    readInt(&userSrcChoice);

    // Validate user input for video source
    if (userSrcChoice < 1 || userSrcChoice > VIDEO_SOURCE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video source. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    videoSource = userSrcChoice - 1;

    // List all options for Video Format
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video Format");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Format");
    for (uint32_t k = VIDEO_FORMAT_NONE; k < VIDEO_FORMAT_MAX; k++)
    {
        UT_LOG_MENU_INFO("%u. %s", k + 1, UT_Control_GetMapString(tvVideoFormatType_mapTable, k)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    // Get user choice for Video Format
    UT_LOG_MENU_INFO("Enter your choice of Video Format (index): ");
    readInt((int*)&videoFormat);

    // Validate video format choice
    if ((int32_t )videoFormat < 1 || (int32_t )videoFormat > (int32_t )VIDEO_FORMAT_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video Format. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    videoFormat = (int32_t )videoFormat - 1;

    // Display available picture modes to the user
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Picture Modes");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Format");
    for (uint32_t i = PQ_MODE_STANDARD; i <= PQ_MODE_VIVID2; i++)
    {
        UT_LOG_MENU_INFO("%u. %s", i + 1, UT_Control_GetMapString(tvPQModeIndex_mapTable,i)); // Display index starting from 1
    }

    // Get user input for selecting a picture mode
    UT_LOG_MENU_INFO("Enter the number corresponding to the Picture Mode: ");
    readInt(&userChoice);

    // Validate user choice
    if (userChoice < 1 || userChoice > (int32_t )PQ_MODE_MAX)
    {
        UT_LOG_ERROR("Invalid choice! Please select a valid Picture Mode.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    selectedPictureMode = userChoice - 1; // Map 1-based choice to 0-based index

    UT_LOG_INFO("Calling SaveSourcePictureMode(IN:VideoSrcType:[%s], IN:VideoFormatType:[%s], IN:PictureMode:[0x%0X])",
                 UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
                 UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
                 selectedPictureMode);

    // Save the picture mode value
    result = SaveSourcePictureMode(videoSource, videoFormat, selectedPictureMode);
    UT_LOG_INFO("Result SaveSourcePictureMode(IN:VideoSrcType:[%s], IN:VideoFormatType:[%s], IN:PictureMode:[0x%0X]) tvError_t:[%s]",
                 UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
                 UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
                 selectedPictureMode,
                 UT_Control_GetMapString(tvError_mapTable, result));

    ASSERT(result == tvERROR_NONE);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief Saves the CMS value.
 *
 * This function saves the CMS value in the override picture profile database for the specific picture mode, primary video format type
 * and primary video source. The saved CMS value should automatically take effect whenever the
 * specified picture mode is selected, specified primary video format is played, specified primary video source is selected
 * and the CMS state is enabled for that combination. There will be no change in the current CMS value applied in the color management system.
 * When the component_type is passed as COMP_NONE and color_type is passed as tvDataColor_NONE, the cms_value
 * refers to CMS state.
 *
 * **Test Group ID:** 04
 * **Test Case ID:** 60
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_CMS_TestSpecification.md](../docs/pages/tvSettings_L3_CMS_TestSpecification.md)
 */
void test_l3_tvSettings_CMSSave(void)
{
    // Declare and initialize all variables at the top
    gTestID = 60;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    tvError_t result = tvERROR_NONE;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_IP; // Set video source to IP directly
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    int32_t cmsValue = 0;
    tvComponentType_t componentType = COMP_NONE;
    tvDataComponentColor_t colorType = tvDataColor_NONE;
    int32_t pqMode = 0;
    int32_t userColorChoice;
    int32_t maxRange = 30;

    int32_t userSrcChoice = 0;

    // List all options for Video sources
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video sources");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Sources");
    for (uint32_t j = VIDEO_SOURCE_ANALOGUE; j <= VIDEO_SOURCE_MAX; j++)
    {
        UT_LOG_MENU_INFO("%u. %s", j+1, UT_Control_GetMapString(tvVideoSrcType_mapTable, j)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Source (index): ");
    readInt(&userSrcChoice);

    // Validate user input for video source
    if (userSrcChoice < 1 || userSrcChoice > VIDEO_SOURCE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video source. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    videoSource = userSrcChoice - 1;

    // List all options for Picture Modes
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Picture Modes");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Picture Modes");
    for (uint32_t k = PQ_MODE_STANDARD; k <= PQ_MODE_VIVID2; k++)
    {
        UT_LOG_MENU_INFO("%u. %s", k + 1, UT_Control_GetMapString(tvPQModeIndex_mapTable, k)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Picture Mode (index): ");
    readInt(&pqMode);

    // Validate picture mode choice
    if (pqMode < PQ_MODE_STANDARD || pqMode > (int32_t )PQ_MODE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Picture Mode. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Map the user's 1-based choice to 0-based index
    pqMode = pqMode - 1;

    // List all options for Video Format
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Video Formats");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Video Formats");
    for (uint32_t k = VIDEO_FORMAT_NONE; k < VIDEO_FORMAT_MAX; k++)
    {
        UT_LOG_MENU_INFO("%u. %s", k + 1, UT_Control_GetMapString(tvVideoFormatType_mapTable, k)); // Display index starting from 1
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of Video Format (index): ");
    readInt((int*)&videoFormat);

    // Validate video format choice
    if ((int32_t )videoFormat < 1 || (int32_t )videoFormat > (int32_t )VIDEO_FORMAT_MAX)
    {
        UT_LOG_ERROR("Invalid choice of Video Format. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Map the user's 1-based choice to 0-based index
    videoFormat = (tvVideoFormatType_t)videoFormat - 1;

    // Retrieve supported component types
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Component Types");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Component Types");
    for (int32_t i = COMP_NONE; i < COMP_MAX; i++)
    {
        if (i == COMP_MAX) continue; // Skip COMP_MAX as it's not a valid option
        UT_LOG_MENU_INFO("%d. %s", i, UT_Control_GetMapString(tvComponentType_mapTable, i));
    }

    // Get user choice for Component Type
    UT_LOG_MENU_INFO("Enter the number corresponding to the Component Type: ");
    readInt((int*)&componentType);

    // Validate component type choice
    if (componentType < COMP_NONE || componentType >= COMP_MAX)
    {
        UT_LOG_ERROR("Invalid Component Type! Please enter a valid index from the list.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported Component Colors");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "Component Colors");

    // Start the loop from tvDataColor_NONE and proceed up to tvDataColor_MAX, doubling each iteration
    for (uint32_t i = tvDataColor_NONE; i <= tvDataColor_MAX; i = (i == 0 ? 1 : i << 1))
    {
        UT_LOG_MENU_INFO("%u. %s", i, UT_Control_GetMapString(tvDataComponentColor_mapTable, i));
    }

    // Get user input for component color
    UT_LOG_MENU_INFO("Enter the component color: ");
    readInt(&userColorChoice);

    if (userColorChoice < 0 || userColorChoice >= tvDataColor_MAX)
    {
        UT_LOG_ERROR("Invalid component color index! Please enter a valid index from the list.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    colorType = (tvDataComponentColor_t)userColorChoice;

    // Determine value range for cms_value based on componentType and colorType

    if (componentType == COMP_HUE || componentType == COMP_SATURATION)
    {
        maxRange = 100; // Range for Hue and Saturation
    }

    if (componentType == COMP_NONE && colorType == tvDataColor_NONE)
    {
        UT_LOG_MENU_INFO("Enter CMS state value (0 or 1): ");
        readInt(&cmsValue);

        if (cmsValue < 0 || cmsValue > 1)
        {
            UT_LOG_ERROR("Invalid CMS state! Please enter 0 or 1.");
            UT_LOG_INFO("Out %s", __FUNCTION__);
            return;
        }
    }
    else
    {
        UT_LOG_MENU_INFO("Enter the CMS value (0 - %d): ", maxRange);
        readInt(&cmsValue);

        if (cmsValue < 0 || cmsValue > maxRange)
        {
            UT_LOG_ERROR("Invalid CMS value! Please enter a value between 0 and %d.", maxRange);
            UT_LOG_INFO("Out %s", __FUNCTION__);
            return;
        }
    }

    UT_LOG_INFO("Calling SaveCMS(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:ComponentType:[%s], IN:ColorType:[%s], IN:CMSValue:[%d])",
                 UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
                 pqMode,
                 UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
                 UT_Control_GetMapString(tvComponentType_mapTable, componentType),
                 UT_Control_GetMapString(tvDataComponentColor_mapTable, colorType),
                 cmsValue);

    // Save the CMS value
    result = SaveCMS(videoSource, pqMode, videoFormat, componentType, colorType, cmsValue);

    UT_LOG_INFO("Result SaveCMS(IN:VideoSrcType:[%s], IN:PQMode:[%d], IN:VideoFormatType:[%s], IN:ComponentType:[%s], IN:ColorType:[%s], IN:CMSValue:[%d]) tvError_t:[%s]",
                 UT_Control_GetMapString(tvVideoSrcType_mapTable, videoSource),
                 pqMode,
                 UT_Control_GetMapString(tvVideoFormatType_mapTable, videoFormat),
                 UT_Control_GetMapString(tvComponentType_mapTable, componentType),
                 UT_Control_GetMapString(tvDataComponentColor_mapTable, colorType),
                 cmsValue,
                 UT_Control_GetMapString(tvError_mapTable, result));

    ASSERT(result == tvERROR_NONE);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief This test sets and saves the gamma table values for primary colors (R, G, B) based on user input for a specified color temperature.
 *
 * This test function allows the user to set the gamma table values for the primary colors (R, G, B) with a specified size
 * and color temperature. It then verifies the gamma values by retrieving them back.
 *
 * **Test Group ID:** 03@n
 * **Test Case ID:** 61@n
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_SaveGammaTable(void)
{
    // Initialize test ID and log entry
    gTestID = 61;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    unsigned short size = 0;
    unsigned short pData_R[256] = {0};
    unsigned short pData_G[256] = {0};
    unsigned short pData_B[256] = {0};
    unsigned short selectedColorTemp = 0;
    int32_t userChoice = 0;

    // Retrieve and display supported color temperatures
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tColorTemperature");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "ColorTemperature");
    for (unsigned short i = tvColorTemp_STANDARD; i < tvColorTemp_MAX; i++)
    {
        UT_LOG_INFO("%d. %s", i + 1, UT_Control_GetMapString(tvColorTemp_mapTable, i));
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");

    // Get user input for selecting a color temperature
    UT_LOG_MENU_INFO("Enter the number corresponding to the Color Temperature: ");
    readInt(&userChoice);

    if (userChoice < 1 || userChoice > tvColorTemp_MAX)
    {
        UT_LOG_ERROR("Invalid color temperature choice: [%d]", userChoice);
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    selectedColorTemp = userChoice - 1;

    // Get user input for the size of the gamma table
    UT_LOG_MENU_INFO("Enter the size of the gamma table (1 - 255): ");
    readInt((int32_t*)&size);

    if (size < 1 || size > 255)
    {
        UT_LOG_ERROR("Invalid size! Please enter a size between 1 and 255.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    // Get user input for gamma values for Red
    UT_LOG_MENU_INFO("Enter %hu gamma values for Red (0 - 1023): ", size);
    for (unsigned short i = 0; i < size; i++)
    {
        scanf("%hu", &pData_R[i]);
        if (pData_R[i] > 1023)
        {
            UT_LOG_ERROR("Invalid value for Red at position %hu! Please enter a value between 0 and 1023.", i + 1);
            UT_LOG_INFO("Out %s", __FUNCTION__);
            return;
        }
    }
    readAndDiscardRestOfLine(stdin);

    // Get user input for gamma values for Green
    UT_LOG_MENU_INFO("Enter %hu gamma values for Green (0 - 1023): ", size);
    for (unsigned short i = 0; i < size; i++)
    {
        scanf("%hu", &pData_G[i]);
        if (pData_G[i] > 1023)
        {
            UT_LOG_ERROR("Invalid value for Green at position %hu! Please enter a value between 0 and 1023.", i + 1);
            UT_LOG_INFO("Out %s", __FUNCTION__);
            return;
        }
    }
    readAndDiscardRestOfLine(stdin);

    // Get user input for gamma values for Blue
    UT_LOG_MENU_INFO("Enter %hu gamma values for Blue (0 - 1023): ", size);
    for (unsigned short i = 0; i < size; i++)
    {
        scanf("%hu", &pData_B[i]);
        if (pData_B[i] > 1023)
        {
            UT_LOG_ERROR("Invalid value for Blue at position %hu! Please enter a value between 0 and 1023.", i + 1);
            UT_LOG_INFO("Out %s", __FUNCTION__);
            return;
        }
    }
    readAndDiscardRestOfLine(stdin);

    // Set the gamma table values
    UT_LOG_INFO("Calling SaveGammaTable(IN: colortemp[%hu], size[%hu])", selectedColorTemp, size);
    ret = SaveGammaTable(selectedColorTemp, pData_R, pData_G, pData_B, size);
    UT_LOG_INFO("Result SaveGammaTable(colortemp:[%hu], size:[%hu]), tvError_t:[%s]", selectedColorTemp, size, UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief Retrieves and validates the CMS state without setting it.
 *
 * This test function directly calls GetCMSState to retrieve the current CMS state
 * and validates the retrieval process.
 *
 * **Test Group ID:** 05
 * **Test Case ID:** 62
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_GetCMSState(void)
{
    // Initialize test ID and log entry
    gTestID = 62;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Variable declarations
    tvError_t ret = tvERROR_NONE;
    bool retrievedCMSState = false;

    // Retrieve the CMS state
    UT_LOG_INFO("Calling GetCMSState OUT:retrievedCMSState[]");
    ret = GetCMSState(&retrievedCMSState);
    UT_LOG_INFO("Result GetCMSState(OUT: retrievedCMSState[%s]), tvError_t:[%s]",
                retrievedCMSState ? "Enabled" : "Disabled",
                UT_Control_GetMapString(tvError_mapTable, ret));
    ASSERT(ret == tvERROR_NONE);

    // Log exit and end function
    UT_LOG_INFO("Out %s", __FUNCTION__);
}

/**
 * @brief Saves the Dolby Vision TMAX parameter.
 *
 * This function saves the Dolby Vision TMAX parameter in the picture profile database
 * for the specified LDIM state level. The saved TMAX value will be applied in Dolby Vision
 * core whenever the specified LDIM state level is selected as a result of picture mode
 * change or primary video source change or primary video format change.
 *
 * **Test Group ID:** 03
 * **Test Case ID:** 63
 *
 * **Test Procedure:**
 * Refer to Test specification documentation
 * [tvSettings_L3_Low-Level_TestSpecification.md](../docs/pages/tvSettings_L3_Low-Level_TestSpecification.md)
 */
void test_l3_tvSettings_SaveDvTmaxValue(void)
{
    // Initialize test ID and log entry
    gTestID = 63;
    UT_LOG_INFO("In %s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    // Declare and initialize variables
    tvError_t result = tvERROR_NONE;
    ldimStateLevel_t ldimState = LDIM_STATE_NONBOOST; // Set initial state to non-boost
    int32_t tmaxValue = 0;
    int32_t userLdimChoice = 0;

    // List all options for LDIM State Level
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t\tSupported LDIM State Levels");
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("\t#   %-30s", "LDIM State Levels");
    for (uint32_t i = LDIM_STATE_NONBOOST; i < LDIM_STATE_MAX; i++) // Exclude LDIM_STATE_MAX
    {
        UT_LOG_MENU_INFO("%u. %s", i, UT_Control_GetMapString(ldimStateLevel_mapTable, i)); // Display index starting from 0
    }
    UT_LOG_MENU_INFO("----------------------------------------------------------");
    UT_LOG_MENU_INFO("Enter your choice of LDIM State Level (index): ");
    readInt(&userLdimChoice);

    // Validate user input for LDIM State Level
    if (userLdimChoice < 0 || userLdimChoice >= (int32_t)LDIM_STATE_MAX)
    {
        UT_LOG_ERROR("Invalid choice of LDIM State Level. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    ldimState = (ldimStateLevel_t)userLdimChoice;

    // Prompt the user for the TMAX value
    UT_LOG_MENU_INFO("Enter the TMAX value to set (0 - 10000): ");
    readInt(&tmaxValue);

    // Validate the TMAX value input
    if (tmaxValue < 0 || tmaxValue > 10000)
    {
        UT_LOG_ERROR("Invalid TMAX value entered. Exiting test.");
        UT_LOG_INFO("Out %s", __FUNCTION__);
        return;
    }

    UT_LOG_INFO("Calling SaveDvTmaxValue(IN:LDIMState:[%s], IN:TMAXValue:[%d])",
                 UT_Control_GetMapString(ldimStateLevel_mapTable, ldimState),
                 tmaxValue);

    // Save the TMAX value
    result = SaveDvTmaxValue(ldimState, tmaxValue);

    UT_LOG_INFO("Result SaveDvTmaxValue(IN:LDIMState:[%s], IN:TMAXValue:[%d]) tvError_t:[%s]",
                 UT_Control_GetMapString(ldimStateLevel_mapTable, ldimState),
                 tmaxValue,
                 UT_Control_GetMapString(tvError_mapTable, result));

    ASSERT(result == tvERROR_NONE);

    UT_LOG_INFO("Out %s", __FUNCTION__);
}

static UT_test_suite_t * pSuite = NULL;

/**
 * @brief Register the main tests for this module
 *
 * @return int32_t - 0 on success, otherwise failure
 */

int32_t test_l3_tvSettings_register(void)
{
    // Create the test suite
    pSuite = UT_add_suite("[L3 tvSettings]", NULL, NULL);

    if (pSuite == NULL)
    {
        return -1;
    }

    UT_add_test(pSuite, "Initialize", test_l3_tvSettings_initialize);
    UT_add_test(pSuite, "Terminate", test_l3_tvSettings_terminate);
    UT_add_test(pSuite, "Get Video Format", test_l3_tvSettings_GetVideoFormat);
    UT_add_test(pSuite, "Get Resolution", test_l3_tvSettings_GetCurrentVideoResolution);
    UT_add_test(pSuite, "Get Video FrameRate", test_l3_tvSettings_GetCurrentVideoFrameRate);
    UT_add_test(pSuite, "Get Video Source", test_l3_tvSettings_GetCurrentVideoSource);
    UT_add_test(pSuite, "Back light", test_l3_tvSettings_backlight);
    UT_add_test(pSuite, "Back light Fade", test_l3_tvSettings_backlightFade);
    UT_add_test(pSuite, "Back light Mode", test_l3_tvSettings_backlightMode);
    UT_add_test(pSuite, "TV Dimming Mode", test_l3_tvSettings_TVDimmingMode);
    UT_add_test(pSuite, "Local Dimming Mode", test_l3_tvSettings_LocalDimmingLevel);
    UT_add_test(pSuite, "Brightness", test_l3_tvSettings_Brightness);
    UT_add_test(pSuite, "Contrast", test_l3_tvSettings_Contrast);
    UT_add_test(pSuite, "Sharpness", test_l3_tvSettings_Sharpness);
    UT_add_test(pSuite, "Saturation", test_l3_tvSettings_Saturation);
    UT_add_test(pSuite, "Hue", test_l3_tvSettings_Hue);
    UT_add_test(pSuite, "ColorTemperature", test_l3_tvSettings_ColorTemperature);
    UT_add_test(pSuite, "Aspect Ratio", test_l3_tvSettings_AspectRatio);
    UT_add_test(pSuite, "Low Latency State", test_l3_tvSettings_LowLatencyState);
    UT_add_test(pSuite, "Dynamic Contrast", test_l3_tvSettings_DynamicContrast);
    UT_add_test(pSuite, "Dynamic Gamma", test_l3_tvSettings_DynamicGamma);
    UT_add_test(pSuite, "Dolby Vision", test_l3_tvSettings_DolbyVisionMode);
    UT_add_test(pSuite, "Picture Mode", test_l3_tvSettings_PictureMode);
    UT_add_test(pSuite, "ColorTempRgain", test_l3_tvSettings_ColorTempRgain);
    UT_add_test(pSuite, "ColorTempGgain", test_l3_tvSettings_ColorTempGgain);
    UT_add_test(pSuite, "ColorTempBgain", test_l3_tvSettings_ColorTempBgain);
    UT_add_test(pSuite, "ColorTempRpost", test_l3_tvSettings_ColorTempRpostoffset);
    UT_add_test(pSuite, "ColorTempGpost", test_l3_tvSettings_ColorTempGpostoffset);
    UT_add_test(pSuite, "ColorTempBpost", test_l3_tvSettings_ColorTempBpostoffset);
    UT_add_test(pSuite, "WBCalibrationMode", test_l3_tvSettings_WBCalibrationMode);
    UT_add_test(pSuite, "Gamma Table", test_l3_tvSettings_GammaTable);
    UT_add_test(pSuite, "DvTmaxValue", test_l3_tvSettings_DvTmaxValue);
    UT_add_test(pSuite, "CMSState", test_l3_tvSettings_CMSState);
    UT_add_test(pSuite, "CompSaturation", test_l3_tvSettings_ComponentSaturation);
    UT_add_test(pSuite, "CompHue", test_l3_tvSettings_ComponentHue);
    UT_add_test(pSuite, "CompLuma", test_l3_tvSettings_ComponentLuma);
    UT_add_test(pSuite, "EnableGammaMode", test_l3_tvSettings_EnableGammaMode);
    UT_add_test(pSuite, "GammaPatternMode", test_l3_tvSettings_SetGammaPatternMode);
    UT_add_test(pSuite, "SetGammaPattern", test_l3_tvSettings_SetGammaPattern);
    UT_add_test(pSuite, "RGBPattern", test_l3_tvSettings_RGBPattern);
    UT_add_test(pSuite, "GrayPattern", test_l3_tvSettings_GrayPattern);
    UT_add_test(pSuite, "EnableLDIMPixelCompensation", test_l3_tvSettings_EnableLDIMPixelCompensation);
    UT_add_test(pSuite, "LDIMEnable", test_l3_tvSettings_EnableLDIM);
    UT_add_test(pSuite, "SetBacklightTestMode", test_l3_tvSettings_SetBacklightTestMode);
    UT_add_test(pSuite, "EnableDynamicContrast", test_l3_tvSettings_EnableDynamicContrast);
    UT_add_test(pSuite, "EnableLocalContrast", test_l3_tvSettings_EnableLocalContrast);
    UT_add_test(pSuite, "Save Backlight values", test_l3_tvSettings_BacklightSave);
    UT_add_test(pSuite, "Save TV Dimming Mode values", test_l3_tvSettings_TVDimmingModeSave);
    UT_add_test(pSuite, "Save Local Dimming Mode values", test_l3_tvSettings_LocalDimmingLevelSave);
    UT_add_test(pSuite, "Save Brightness values", test_l3_tvSettings_BrightnessSave);
    UT_add_test(pSuite, "Save Contrast values", test_l3_tvSettings_ContrastSave);
    UT_add_test(pSuite, "Save Sharpness values", test_l3_tvSettings_SharpnessSave);
    UT_add_test(pSuite, "Save Saturation values", test_l3_tvSettings_SaturationSave);
    UT_add_test(pSuite, "Save Hue values", test_l3_tvSettings_HueSave);
    UT_add_test(pSuite, "Save Color Temperature values", test_l3_tvSettings_ColorTemperatureSave);
    UT_add_test(pSuite, "Save Aspect Ratio values", test_l3_tvSettings_AspectRatioSave);
    UT_add_test(pSuite, "Save Low Latency values", test_l3_tvSettings_LowLatencySave);
    UT_add_test(pSuite, "Save Dolby Vision", test_l3_tvSettings_DolbyVisionSave);
    UT_add_test(pSuite, "Save Picture Mode", test_l3_tvSettings_PictureModeSave);
    UT_add_test(pSuite, "Save CMS", test_l3_tvSettings_CMSSave);
    UT_add_test(pSuite, "Save Gamma Table", test_l3_tvSettings_SaveGammaTable);
    UT_add_test(pSuite, "Get CMS State", test_l3_tvSettings_GetCMSState);
    UT_add_test(pSuite, "Save DV Tmax", test_l3_tvSettings_SaveDvTmaxValue);

    return 0;
}
/** @} */ // End of TV_Settings_HALTEST_L3
/** @} */ // End of TV_Settings_HALTEST
/** @} */ // End of TV_Settings
/** @} */ // End of HPK
