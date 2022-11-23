/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:
*
* Copyright 2022 Sky UK
* Copyright 2022 Amlogic
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
 * @file tvSettings.h
 * @brief This file contains implementation of TV Settings Hal module
 **/

/**
- * @defgroup TVSettings
- * @{
- * @defgroup hal
- * @{
- **/
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<ctype.h>
#include<fcntl.h>
#include<unistd.h>

#include "tvSettings.h"
#if DELETE
#include "TvClient.h"
#include "TvClientWrapper.h"
#include "autoBacklightControl.h"
#include "PqClient.h"
#include "pqcmd.h"
#include "binder/IPCThreadState.h"
#include "binder/ProcessState.h"
#include "math.h"
#include <glib.h>
#include "libIARMCore.h"
#include "libIBus.h"
#include "mfrMgr.h"
#include "rfcapi.h"
#endif
#define SRC_FORMAT_FILE_PATH "/sys/module/amdolby_vision/parameters/dolby_vision_src_format"

#define HDMI_DEFAULT 1  //Placeholder only . HDMI Source input not used by amlogic TvServer
#define INT_DUMMY 0 /* unused PQ Client arguments */
#define SAVE 1
#define SAVEPARAM 0
#define DYNAMIC_CONTRAST_OFF 0
#define DYNAMIC_CONTRAST_HIGH 2
#define IARM_BUS_TVSETTINGS_HAL "tvsettings_hal"

#define DV_MODES_SUPPORTED_MAX (3)

#define SYSFS_LOCAL_DIMMING     "/sys/class/aml_ldim/func_en"
#define SYSFS_PIXEL_REMAP "/sys/class/aml_ldim/remap"

/*WB defines*/
#define MAX_SOURCE_SUPPROTED_FOR_WB (3)
#define MAX_COLOR_TEMP_SUPPROTED (3)

/*defaults from MFR*/
#define DEFAULT_WB_NORMAL_RGAIN  (1024)
#define DEFAULT_WB_NORMAL_GGAIN  (1024)
#define DEFAULT_WB_NORMAL_BGAIN  (1024)
#define DEFAULT_WB_COLD_RGAIN    (920)
#define DEFAULT_WB_COLD_GGAIN    (960)
#define DEFAULT_WB_COLD_BGAIN   (1024)
#define DEFAULT_WB_WARM_RGAIN   (1024)
#define DEFAULT_WB_WARM_GGAIN   (960)
#define DEFAULT_WB_WARM_BGAIN   (920)
#define DEFAULT_WB_OFFSET       (0)
#define DEFAULT_WB_ZERO_GAIN     (0)
#define DEFAULT_WB_CUST_GAIN     (1024)

#define  ZERO_IN_ALL_TEMP    (0x00010101)
#define  DEFAULT_IN_ALL_TEMP (0x00040404)
#define BYTE_SIZE            (8)

#define MAX_RETRY (10)

//Panel ID
#define PANEL_ID_OFFSET 0x9000004
#define MMC_DEVICE      ("/dev/mmcblk0")

int TVWriteSysfs(const char *path, const char * cmd);
#define FADE_PATH "/sys/class/backlight/aml-bl/fade"
#define GAMMA_PATH "/sys/class/amvecm/debug"
#define DISABLE_STR "gamma disable"
#define ENABLE_STR "gamma enable"

//cri_data source offset * AML specific *
typedef enum colortemperature_source_offset_e {
    HDMI_OFFSET = 0,
    TV_OFFSET   = 1,
    AV_OFFSET   = 2
} colortemperature_source_offset_t;

typedef enum wb_values_status{
    are_zero = 0,
    
    are_equal = 1,
    are_default = 2
}wb_values_status_t;

#define VALUES_ARE_NEW    (0)
#define VALUES_ARE_ZERO    (1<<are_zero)
#define VALUES_ARE_DEFAULT  (1<<are_default)
#define ARE_SAME_STRINGS(STR1,STR2) (!strncmp(STR1,STR2,strlen(STR2)))

#define RFC_CALLER_ID "TvSettings"
#define RFC_BOOST_COMMAND "Device.DeviceInfo.X_RDKCENTRAL-COM_RFC.TvSettings.Boost"


int sourceIdFromOffset(colortemperature_source_offset_t offset);
void tvCopySD3DatatoCridataEx(void);
tvError_t ReadCustWBvaluesFromDriverOnInit(void);
int getRgbType(char *color, char * ctrl);

/* backlight area(51)*/
#define BACKLIGHT_RAW_VALUE_MAX    (255)

tvError_t TVUpdateRawBacklight(int value,int midPointValue);
