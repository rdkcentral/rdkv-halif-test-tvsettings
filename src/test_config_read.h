#ifndef TEST_CONFIG_READ_H
#define TEST_CONFIG_READ_H

#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
 
#define MAX_KEY_LENGTH 50
#define MAX_BUF_SIZE 2048
#define DV_MODE_FLAG                            0x01
#define HLG_MODE_FLAG                           0x02
#define HDR10_MODE_FLAG                         0x03
#define PIC_MODE_FLAG                           0x04
#define DIM_MODE_FLAG                           0x05
#define VIDEO_FORMAT_MODE_FLAG                  0x06
#define VIDEO_RESOLUTION_MODE_FLAG              0x07
#define FRAMERATE_MODE_FLAG                     0x08
#define COLOR_TEMP_FLAG                         0x09
#define ASPECT_RATIO_FLAG                       0x0A
#define VIDEO_SOURCE_FLAG                       0x0B
#define  BACK_LIGHT_FLAG                        0x0C
#define  LDIM_MODE_FLAG                        0x0D
#define COLOR_TEMPSOURCE_OFFSET_FLAG           0x0E 
#define COMPONENT_CLR_FLAG                     0x0F
#define COMPONENT_SATURATION_FLAG              0x10
#define COMPONENT_HUE_FLAG             		   0x11
#define COMPONENT_LUMA_FLAG                    0x12
#define COMPONENT_PQPARAM_FLAG                 0x13

#define MAX_VIDEO_FORMAT         20
#define MAX_DIMMING_MODES        20
#define MAX_PICTURE_MODES        20
#define MAX_HDR10_MODES          10
#define MAX_HLG_MODES            10
#define MAX_DV_MODES             10
#define MAX_NAME_SIZE            20
#define MAX_OFFSET               10
 
struct modes {
	char modeName[MAX_DV_MODES][MAX_NAME_SIZE];
	short int modeId[MAX_DV_MODES];
};
 
struct tvSettingConf{
	struct modes dv_modes;
	struct modes hlg_modes;
	struct modes hdr10_modes;
	struct modes pic_modes;
	struct modes colorTemperature;
	struct modes colorTempSourceOffset;
	struct modes AspectRatio;
	struct modes videoformat;
	struct modes videoResolution;
	struct modes videoframerate;
	struct modes videoSources;
	struct modes backlightModes;
	struct modes dimmode;
	struct modes ldimMode;
	struct modes componentColor;
	struct modes componentSaturation;
	struct modes componentHue;
	struct modes componentLuma;
	struct modes componentType;
	struct modes componentColorType;
	struct modes pq_paramIndex;
	struct modes wakeupconfig;
	struct modes backlightTestModes;
};
 
int config_read(char *filename);

#endif /*TEST_CONFIG_READ_H*/
