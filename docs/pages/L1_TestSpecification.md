# Level 1 HAL Testing Specification

## History

|Version|Date (YY-MM-DD)|Author|
|-------|-----|-----|
|1.0.0| 09/12/22 |aishwariya bhaskar|

## Overview

This document will define the requirements for Level 1 testing for this HAL.

## Table of Contents

- [Overview](#overview)
- [Acronyms](#acronyms)
- [Definitions](#definitions)
- [References](#references)
- [L1 Testing Requirements](#l1-testing-requirements)

## Acronyms

- `HAL` \- Hardware Abstraction Layer, may include some common components
- `HAL.h` \- Abstracted defined API to control the hardware
- `HAL.c` \- Implementation wrapper layer created by the `OEM` or `SoC` Vendor.
- `RDK` \- Reference Design Kit for All Devices
- `RDK-B` \- Reference Design Kit for Broadband Devices
- `RDK-V` \- Reference Design Kit for Video Devices
- `UT` \- Unit Test(s)
- `OEM` \- Original Equipment Manufacture (Sky is also an OEM)
- `SoC` \- System on a Chip

## Definitions

- `Broadcom` \- `SoC` manufacturer [https://www.broadcom.com/]
- `Amlogic` \- `SoC` manufacturer [https://en.wikipedia.org/wiki/Amlogic]
- `Soc Vendor` \- Definition to encompass multiple vendors
- `Unit Tests` \- C Function tests that run on the target hardware
- `Common Testing Framework` \- Off the shelf 3rd Party Testing Framework, or framework that does not require infrastructure to control it. That's not to say it cannot be controlled via infrastructure if required. Examples of which are.
  - GTest - [https://google.github.io/googletest] \- Google Test Suit
  - CUnit - [http://cunit.sourceforge.net/] \- C Testing Suit
  - Unity - [http://www.throwtheswitch.org/unity] -C Embedded Testing Suit
  - `ut-core` - Common Testing Framework [https://github.com/comcast-sky/rdk-components-ut-core]

## References

- `Feedback Loops` \- [https://www.softwaretestingnews.co.uk/4-methods-to-improve-your-feedback-loops-and-supercharge-your-testing-process/]
- `Doxygen` \- SourceCode documentation tool - [https://www.doxygen.nl/index.html]
- `Black Box Testing` \- [https://en.wikipedia.org/wiki/Black-box_testing]

## L1 Testing Requirements

As per the definition of the header files, take all the API's possible and create positive and negative test cases to ideally exercise the complete interface.

The interface is defined by the git repository `[git@github.com:comcast-sky/rdk-components-hal-wifi-rdkb.git]` which is accessible via the link [https://github.com/comcast-sky/rdk-components-hal-wifi-rdkb]

from the template in `ut-core/framework/hal_template` the `UT` suite will be triggered.

## autoBacklightControl.h

```c
int blWriteSysfs(const char *path, int value);
int blReadSysfs(const char *path);
int autoBacklightThreadInit();
int autoBacklightThreadTerm();
int autoBacklightControl(bool enable);
```

## tvsettings.hal

```c
tvError_t tvInit();
tvError_t tvSD3toCriSyncInit();
tvError_t tvTerm();
tvError_t GetTVPictureMode(char *pictureMode);
tvError_t SetTVPictureMode(const char * pictureMode);
tvError_t GetBacklight(int *backlight);
tvError_t SetBacklight(int backlight);
tvError_t SetBrightness(int brightness);
tvError_t GetBrightness(int *brightness);
tvError_t SetContrast(int contrast);
tvError_t GetContrast(int *contrast);
tvError_t SetSharpness(int sharpness);
tvError_t GetSharpness(int *sharpness);
tvError_t SetSaturation(int saturation);
tvError_t GetSaturation(int *saturation);
tvError_t SetHue(int hue);
tvError_t GetHue(int *hue);
tvError_t SetColorTemperature(tvColorTemp_t colorTemp);
tvError_t GetColorTemperature(tvColorTemp_t *colorTemp);
tvError_t SetAspectRatio(tvDisplayMode_t dispMode);
tvError_t GetAspectRatio(tvDisplayMode_t *dispMode);
tvError_t GetTint(int *tint);
tvError_t SetTint(int tint);
tvError_t GetSupportedBacklightModes(int *blModes);
tvError_t GetCurrentBacklightMode(tvBacklightMode_t *blMode);
tvError_t SetCurrentBacklightMode(tvBacklightMode_t blMode);
tvError_t GetCurrentVideoFormat(tvVideoHDRFormat_t *format);
tvError_t GetVideoResolution(tvResolutionParam_t *res);
tvError_t GetVideoFrameRate(tvVideoFrameRate_t *format);
tvError_t setWakeupConfig(const tvWakeupSrcType_t src_type, const bool value);
tvError_t SetRGBPattern(int r,int g, int b) ;
tvError_t GetRGBPattern(int *r,int *g,int *b);
tvError_t SetGrayPattern(int YUVValue);
tvError_t GetGrayPattern(int* YUVValue);
tvError_t SetColorTemp_Rgain(tvColorTemp_t colorTemp, int rgain);
tvError_t GetColorTemp_Rgain(tvColorTemp_t colorTemp, int* rgain);
tvError_t SetColorTemp_Ggain(tvColorTemp_t colorTemp, int ggain);
tvError_t GetColorTemp_Ggain(tvColorTemp_t colorTemp, int* ggain);
tvError_t SetColorTemp_Bgain(tvColorTemp_t colorTemp, int bgain);
tvError_t GetColorTemp_Bgain(tvColorTemp_t colorTemp, int* bgain);
tvError_t SetColorTemp_R_post_offset(tvColorTemp_t colorTemp, int rpostoffset);
tvError_t GetColorTemp_R_post_offset(tvColorTemp_t colorTemp, int* rpostoffset);
tvError_t SetColorTemp_G_post_offset(tvColorTemp_t colorTemp, int gpostoffset);
tvError_t GetColorTemp_G_post_offset(tvColorTemp_t colorTemp, int* gpostoffset);
tvError_t SetColorTemp_B_post_offset(tvColorTemp_t colorTemp, int bpostoffset);
tvError_t GetColorTemp_B_post_offset(tvColorTemp_t colorTemp, int* bpostoffset);
tvError_t GetTVSupportedPictureModes(pic_modes_t *pictureModes[],unsigned short *count);
tvError_t GetTVSupportedDVModes(pic_modes_t *dvModes[],unsigned short *count);
tvError_t SetTVDolbyVisionMode(const char * dolbyMode);
tvError_t GetTVDolbyVisionMode(char *dolbyMode);
tvError_t SetTVHLGMode(const char * hlgMode);
tvError_t SetTVHDR10Mode(const char * hdr10Mode);
tvError_t GetTVHLGMode(char *hlgMode);
tvError_t GetTVHDR10Mode(char *hdr10Mode);
tvError_t GetTVSupportedHLGModes(pic_modes_t *dvModes[],unsigned short *count);
tvError_t GetTVSupportedHDR10Modes(pic_modes_t *dvModes[],unsigned short *count);
tvError_t SetDynamicContrast(const char *dynamicContrastEnable);
tvError_t GetDynamicContrast(char *isDynamicContrastEnabled);
tvError_t SetColorTemp_Rgain_onSource(tvColorTemp_t colorTemp, int rgain,int sourceId, int saveOnly);
tvError_t GetColorTemp_Rgain_onSource(tvColorTemp_t colorTemp, int* rgain,int sourceId);
tvError_t SetColorTemp_Ggain_onSource(tvColorTemp_t colorTemp, int ggain,int sourceId, int saveOnly);
tvError_t GetColorTemp_Ggain_onSource(tvColorTemp_t colorTemp, int* ggain,int sourceId);
tvError_t SetColorTemp_Bgain_onSource(tvColorTemp_t colorTemp, int bgain,int sourceId, int saveOnly);
tvError_t GetColorTemp_Bgain_onSource(tvColorTemp_t colorTemp, int* bgain,int sourceId);
tvError_t SetColorTemp_R_post_offset_onSource(tvColorTemp_t colorTemp, int rpostoffset,int sourceId, int saveOnly);
tvError_t GetColorTemp_R_post_offset_onSource(tvColorTemp_t colorTemp, int* rpostoffset,int sourceId);
tvError_t SetColorTemp_G_post_offset_onSource(tvColorTemp_t colorTemp, int gpostoffset,int sourceId, int saveOnly);
tvError_t GetColorTemp_G_post_offset_onSource(tvColorTemp_t colorTemp, int* gpostoffset,int sourceId);
tvError_t SetColorTemp_B_post_offset_onSource(tvColorTemp_t colorTemp, int bpostoffset,int sourceId, int saveOnly);
tvError_t GetColorTemp_B_post_offset_onSource(tvColorTemp_t colorTemp, int* bpostoffset,int sourceId);
tvError_t setWBctrl(char *inputSrc, char *colorTemp,char *color, char *ctrl, int value);
tvError_t getWBctrl(char *inputSrc, char *colortemp, char *color, char *ctrl, int *value);
tvError_t getWbInfo(getWBInfo_t* params, std::vector<std::string> &selector, std::vector<std::string> &colorTmp, std::vector<std::string> &input);
tvError_t enableWBmode(bool value);
tvError_t GetSupportedComponentColor(int *blComponentColor);
tvError_t SetCurrentComponentSaturation(tvDataComponentColor_t blSaturationColor, int saturation);
tvError_t GetCurrentComponentSaturation(tvDataComponentColor_t blSaturationColor, int *saturation);
tvError_t SetCurrentComponentHue(tvDataComponentColor_t blHueColor, int hue);
tvError_t GetCurrentComponentHue(tvDataComponentColor_t blHueColor, int *hue);
tvError_t SetCurrentComponentLuma(tvDataComponentColor_t blLumaColor, int Luma);
tvError_t GetCurrentComponentLuma(tvDataComponentColor_t blLumaColor, int *Luma);
tvError_t GetTVSupportedDimmingModes(char **dimmingModes,unsigned short *count);
tvError_t SetTVDimmingMode(const char *dimmingMode);
tvError_t GetTVBacklightGlobalFactor(int * value);
tvError_t SetTVBacklightGlobalFactor(int value, int rangeMidPointValue);
tvPictureMode_t GetTVPictureModeIndex(const char * pictureMode);
tvVideoHDRFormat_t GetCurrentContentFormat(void);
tvError_t GetSupportedContentFormats(unsigned int * contentFormats,unsigned short *numberOfFormats);
tvError_t ResetBrightness(int defaultValue,bool resetForAllFormats);
tvError_t ResetContrast(int defaultValue,bool resetForAllFormats);
tvError_t ResetSharpness(int defaultValue,bool resetForAllFormats);
tvError_t ResetSaturation(int defaultValue,bool resetForAllFormats);
tvError_t ResetHue(int defaultValue,bool resetForAllFormats);
tvError_t ResetBacklight(int defaultValue,bool resetForAllFormats);
tvError_t ResetColorTemperature(int defaultValue,bool resetForAllFormats);
tvError_t ResetComponentSaturation(int color,int defaultValue);
tvError_t ResetComponentLuma(int color,int defaultValue);
tvError_t ResetComponentHue(int color,int defaultValue);
bool isCurrentHDRTypeIsSDR(void);
int GetPanelID(char* panelid);
void GetDefaultPanelID(char *panelID);
tvError_t SaveColorTemperature(int sourceInput, int pq_mode,int hdr_type,int value);
tvError_t SaveBacklight(int sourceInput, int pq_mode,int hdr_type,int value);
tvError_t SaveContrast(int sourceInput, int pq_mode,int hdr_type,int value);
tvError_t SaveSaturation(int sourceInput, int pq_mode,int hdr_type,int value);
tvError_t SaveSharpness(int sourceInput, int pq_mode,int hdr_type,int value);
tvError_t SaveBrightness(int sourceInput, int pq_mode,int hdr_type,int value);
tvError_t SaveHue(int sourceInput, int pq_mode,int hdr_type,int value);
tvError_t SaveDynamicBacklight(int sourceInput, int pq_mode,int hdr_type,int value);
tvError_t SaveDisplayMode(int sourceInput, int pq_mode,int hdr_type,int value);
tvError_t SaveCMS(int sourceInput, int pq_mode,int hdr_type,int tunnel_type,int color_type,int value);
tvError_t SaveDolbyMode(int sourceInput, int pq_mode,int hdr_type,int value);
int GetNumberOfModesupported(void);
int GetCurrentPQIndex(void);
void GetAllSupportedPicModeIndex(int pic_mode_index[]);
int GetCMSDefault(tvCMS_tunel_t color_tunel_type);
int GetDolbyModeIndex(const char * dolbyMode);
int ConvertVideoFormatToHDRFormat(tvVideoHDRFormat_t videoFormat);
int ConvertTVColorToVendorColor(tvDataComponentColor_t blComponentColor);
int ConvertHDRFormatToContentFormat(tvhdr_type_t hdrFormat);
int GetCustomPQModeIndex(void);
tvError_t SetCMSState(tvCMS_tunel_t tunelType,tvcomponent_color_type_t colorType,tvcomponent_state_t componentState);
bool isWBUserDfault(tvDataColor_t wbvalue);
int GetWBRgbType(const char *color, const char * ctrl);
tvDataColor_t GetUSerWBValueOnInit(void);
bool areEqual(tvDataColor_t wbvalueThis,tvDataColor_t wbvalueThat);
tvError_t SetColorTemperatureUser(int rgbType, int value);
tvError_t SaveColorTemperatureUser(int rgbType, int value);
tvError_t SetBacklightInfo(tvBacklightInfo_t backlightDefaults);
int GetDriverEquivalentBLForCurrentFmt(int backlight);
int GetHLGModeIndex(const char * hlgMode);
int GetHDR10ModeIndex(const char * hdr10Mode);
tvError_t SetBacklightFade(int from,int to,int duration);
tvError_t ReadAllModeConfigfile(const char *file, char *cpybuffer, const char *searchstring);
void splitstringsfrombuffer(char *buffer, char *availableModes, unsigned short *totalcount);
void splitstringsandvaluefrombuffer(char *buffer, pic_modes_t *availableModes[], unsigned short *totalcount);
tvError_t SetGammaMode(int mode);
tvError_t SetLocalDimmingLevel(int localDimmingLevel);
tvError_t GetLocalDimmingLevel(int *localDimmingLevel);
tvError_t SaveLocalDimmingLevel(int sourceInput, int pq_mode,int hdr_type,int value);
void SwitchEDID(int pqmode);
tvError_t UpdateEDIDAndSetDimmingLevel(int dimmingLevel);
void GetLDIMAndEDIDLevel(int dimmingMode,int format,int *dimmingLevel, int *edidLevel);
```