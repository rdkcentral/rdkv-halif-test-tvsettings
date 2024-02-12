#ifndef TEST_CONFIG_READ_H
#define TEST_CONFIG_READ_H

#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>
#include <ut.h>
#include <ut_log.h>

#define MAX_KEY_LENGTH 50
#define MAX_BUF_SIZE 2048

#define BRIGHTNESS_MODE_FLAG        0x01
#define CONTRAST_MODE_FLAG          0x02
#define SATURATION_MODE_FLAG        0x03
#define SHARPNESS_MODE_FLAG         0x04
#define HUE_MODE_FLAG               0x05
#define BACKLIGHT_MODE_FLAG         0x06

#define COMP_SATURATION_RED             0x07
#define COMP_SATURATION_GREEN           0x08
#define COMP_SATURATION_BLUE            0x09
#define COMP_SATURATION_YELLOW          0x0A
#define COMP_SATURATION_CYAN            0x0B
#define COMP_SATURATION_MAGENTA         0x0C

#define COMP_HUE_RED                    0x0D
#define COMP_HUE_GREEN                  0x0E
#define COMP_HUE_BLUE                   0x0F
#define COMP_HUE_YELLOW                 0x10
#define COMP_HUE_CYAN                   0x11
#define COMP_HUE_MAGENTA                0x12

#define COMP_LUMA_RED                    0x13
#define COMP_LUMA_GREEN                  0x14
#define COMP_LUMA_BLUE                   0x15
#define COMP_LUMA_YELLOW                 0x16
#define COMP_LUMA_CYAN                   0x17
#define COMP_LUMA_MAGENTA                0x18

#define LOW_LATENCY_STATE                0x19
#define COLOR_TEMP_MODE                  0x1A
#define DIMMING_MODE                     0x1B
#define BACK_LIGHT_CTL                     0x1C
#define DOLBY_VISION_MODE                     0x1D
#define ASPECT_RATIO                     0x1E
#define PICTURE_MODE_FLAG                    0x1F
#define VIDEO_SOURCE_FLAG                    0x20
#define VIDEO_FRMT_FLAG                    0x21
#define VIDEO_FRAME_RATE                   0x22
#define DIM_LEVEL_FLAG                    0x23
#define WB_RED_FLAG                    0x24
#define WB_GREEN_FLAG                    0x25
#define WB_BLUE_FLAG                    0x26
#define GAMMA_TABLE_RED                       0x27
#define GAMMA_TABLE_GREEN                      0x28
#define GAMMA_TABLE_BLUE                      0x29

#define MAX_FRAME_RATE           20
#define MAX_VIDEO_FORMAT         20
#define MAX_DIMMING_MODES        20
#define MAX_PICTURE_MODES        20
#define MAX_HDR10_MODES          10
#define MAX_HLG_MODES            10
#define MAX_DV_MODES             10
#define MAX_SOURCE               40
#define MAX_NAME_SIZE            20
#define MAX_COLOR_TEMP           20
#define MAX_OFFSET_CONF              10

struct PictureMode {
    char pqMode[MAX_PICTURE_MODES][MAX_NAME_SIZE];
    int  pqValue[MAX_PICTURE_MODES];
    size_t size;
};

struct videoSource {
    char source[MAX_SOURCE][MAX_NAME_SIZE];
    int  videoSourceValue[MAX_SOURCE];
    size_t size;
};

struct videoFormat {
    char videoFormat[MAX_VIDEO_FORMAT][MAX_NAME_SIZE];
    int  videoFormatValue[MAX_VIDEO_FORMAT];
    size_t size;
};

struct videoFrameRate {
    char frameRate[MAX_FRAME_RATE][MAX_NAME_SIZE];
    int  frameRateValue[MAX_FRAME_RATE];
    size_t size;
};

struct videoColorTemp {
    char colorTemp[MAX_COLOR_TEMP][MAX_NAME_SIZE];
    int  colorTempValue[MAX_COLOR_TEMP];
    size_t size;
};

struct ComponentColor { 
    char modeName[MAX_COLOR_TEMP][MAX_NAME_SIZE];
    int  modeId[MAX_COLOR_TEMP];
    size_t size;

};

struct DisplayPictureMode {
    int rangeFrom;
    int rangeTo;
    bool platformSupport;
    struct PictureMode picmodeStruct;
    struct videoSource videoSrcStruct;
    struct videoFormat videoFormtStruct;
};

struct DisplayColorMode {
    char modeName[MAX_NAME_SIZE][MAX_NAME_SIZE];
    int modevalue[MAX_NAME_SIZE];
    bool platformSupport;
    struct videoColorTemp colorStruct;
    struct PictureMode picmodeStruct;
    struct videoSource videoSrcStruct;
    struct videoFormat videoFormtStruct;
    size_t size;
};

struct DimmingLevel {
    int rangeFrom;
    int rangeTo;
    char dimModeName[MAX_COLOR_TEMP][MAX_NAME_SIZE];
    int dimModevalue[MAX_COLOR_TEMP];
    bool platformSupport;
    size_t size;
};

struct WhiteBalanceGamma {
    int rangeGainFrom;
    int rangeGainTo;
    int rangeOffsetFrom;
    int rangeOffsetTo;
    int gammaIndex_from;
    int gammaIndex_to;
    int rangeFrom;
    int rangeTo;
    struct videoColorTemp colorStruct;
    struct videoSource videoSrcStruct;
    bool platformSupport;
};

struct TvSettingConfig {
    struct DisplayPictureMode brightness;
    struct DisplayPictureMode contrast;
    struct DisplayPictureMode saturation;
    struct DisplayPictureMode sharpness;
    struct DisplayPictureMode hue;
    struct DisplayPictureMode backlight;
    struct DisplayPictureMode CompSaturationRed;
    struct DisplayPictureMode CompSaturationGreen;
    struct DisplayPictureMode CompSaturationBlue;
    struct DisplayPictureMode CompSaturationYellow;
    struct DisplayPictureMode CompSaturationCyan;
    struct DisplayPictureMode CompSaturationMagenta;
    struct DisplayPictureMode CompHueRed;
    struct DisplayPictureMode CompHueGreen;
    struct DisplayPictureMode CompHueBlue;
    struct DisplayPictureMode CompHueYellow;
    struct DisplayPictureMode CompHueCyan;
    struct DisplayPictureMode CompHueMagenta;
    struct DisplayPictureMode CompLumaRed;
    struct DisplayPictureMode CompLumaGreen;
    struct DisplayPictureMode CompLumaBlue;
    struct DisplayPictureMode CompLumaYellow;
    struct DisplayPictureMode CompLumaCyan;
    struct DisplayPictureMode CompLumaMagenta;
    struct DisplayPictureMode lowLatencyState;

    struct DisplayColorMode colorTemp;
    struct DisplayColorMode dimmingMode;
    struct DisplayColorMode backLightCtl;
    struct DisplayColorMode dolbyMode;
    struct DisplayColorMode aspectRatio;

    struct PictureMode picmodeStruct;
    struct videoSource videoSrcStruct;
    struct videoFormat videoFormtStruct;

    struct videoFrameRate framerate;
    struct DimmingLevel dimmingLevel;

    struct WhiteBalanceGamma wbRGB[3];
    struct WhiteBalanceGamma gammaRGB[3];
    struct ComponentColor componentColor;
    struct ComponentColor backlightTestModes;
    struct videoSource colorTempSourceOffset;
    struct videoSource pq_paramIndex;
};

int config_read(char *filename);

#endif /*TEST_CONFIG_READ_H*/
