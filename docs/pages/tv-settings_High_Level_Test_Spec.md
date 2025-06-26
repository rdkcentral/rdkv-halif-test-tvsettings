# TV Settings High Level Test Specification Document

## Table of Contents

- [Acronyms, Terms and Abbreviations](#acronyms-terms-and-abbreviations)
- [References](#references)
- [Introduction](#introduction)
- [Module Description](#module-description)
- [Testing Scope](#testing-scope)
  - [Test Start up Requirement](#test-start-up-requirement)
  - [Emulator Requirement](#emulator-requirement)

## Acronyms, Terms and Abbreviations

- `SoC`   - System On a Chip
- `SEI`   - Supplemental Enhancement Information
- `FMM`   - Film Maker Mode
- `WB`    - White Balance
- `CMS`   - Color Management System
- `PQ`    - Picture Quality
- `LED`   - Light Emitting Diode
- `LDIM`  - Local Dimming Module

## References

## Introduction

This document provides an overview of the testing requirements for the tvSettings module. It outlines the scope of testing, objectives, testing levels and approaches, specific test requirements, emulator requirements, control plane requirements and expected deliverables.

Interface of the test is available in this link -  [TV Settings HAL Interface](https://github.com/rdkcentral/rdkv-halif-tvsettings/blob/main/include/tvSettings.h)

## Module Description

High level overview:

- TVSettings offers diverse functionalities allowing users to access information and customize settings such as picture quality, dimming preferences, and auto backlight controls.
- It facilitates communication with the System-on-Chip (SoC) to effect adjustments within TVSettings. Subsequently, it transmits this updated information to the caller.
- It applies only to the Sink devices.
- HAL specification of the document - [TV Settings HAL Specification](https://github.com/rdkcentral/rdkv-halif-tvsettings/blob/main/docs/pages/tv-settings_halSpec.md)

## Testing Scope

|#|Test Functionality|Test Description|
|-|------------------|----------------|
|1|[Callback Mechanisms](#callback-mechanisms)|The test validates the video format, video resolution, video content, video framerate callback, letting the system detect any changes in the primary video's format|
|2|[Video Formats](#video-formats)|The test validates by getting the all supported video formats and verfies by getting the current video formats|
|3|[Get Current Video Resolution](#get-current-video-resolution)|The test aims to verify the current video resolution of the primary video|
|4|[Get Current Video FrameRate](#get-current-video-framerate)|The test aims to verify the video frame rate of the current primary video|
|5|[Video sources](#video-sources)|The test aims to verify the supported video sources of the systems and its count|
|6|[Back Light, Back light fade, Back light modes and TV Dimming Modes](#backlight-backlightfade-backlightmodes-and-tv-dimming-modes)|The test is to verify by set and Get the current backlight value, backlight fade, backlight modes and tv dimming modes for the primary video source selected, primary video format played and picture mode selected.|
|7|[Local Dimming Level, Brightness, Contrast, Sharpness, Saturation and Hue](#localdimminglevel-brightness-contrast-sharpness-saturation-and-hue)|This test verifies the functionality of setting the local dimming level, brightness, contrast, sharpness, saturation and Hue|
|8|[Color Temperature, Aspect Ratio, Low Latency State, Dynamic Contrast and Dynamic Gamma](#colortemperature-aspectratio-lowlatencystate-dynamiccontrast-and-dynamicgamma)|This test verifies the functionality of setting the color temperature value to driver registers. It ensures that the new color temperature value is updated in the hardware and applied for the current primary video source, video format, and picture mode.|
|9|[TV Dolby Vision mode](#tv-dolby-vision-mode)|This test verifies the functionality of retrieving the supported Dolby Vision modes. It ensures that the returned list contains accurate information about the available DV modes and their count. |
|10|[Picture Modes](#picture-modes)|This test verifies the functionality of retrieving the list of supported picture modes and their count. It ensures that the returned list is accurate and contains valid picture modes.|
|11|[Color Temperature Rgain Ggain Bgain on source](#color-temperature-rgain-ggain-bgain-on-source)|This test verifies the functionality of setting or saving the RGB gain value for a specific color temperature and video source. It ensures that the value is successfully applied or saved for future use.|
|12|[Color Temperature R post G post and B post offset onsource](#color-temperature-r-post-g-post-and-b-post-offset-onsource)|This test verifies the functionality of setting or saving the RGB post offset value for a specific color temperature and video source. It ensures that the value is successfully applied or saved for future use.|
|13|[`WB` Calibration Mode](#wb-calibration-mode)|This test verifies the functionality of enabling or disabling white balance calibration mode. It ensures that the mode is successfully toggled and that the system behaves accordingly.|
|14|[Get and Set Gamma Table](#get-and-set-gamma-table)|This test verifies the functionality of setting the gamma calibrated values to the gamma hardware for the current selected color temperature. It ensures that the values are successfully applied and do not override otherSettings in the picture profile database. |
|15|[Get and Set Dv Tmax Value](#get-and-set-dv-tmax-value)|This test verifies the functionality of setting the Dolby Vision TMAX parameter in the Dolby Vision core. It ensures that the provided value is valid and can be applied successfully.|
|16|[Get Supported Component Color](#get-supported-component-color)|This test verifies the functionality of retrieving the supported component colors. It ensures that the returned value represents the bitwise OR-ed combination of all supported colors.|
|17|[Current Component Saturation, Component Hue and Component Luma](#currentcomponentsaturation-component-hue-and-component-luma)|This test verifies the functionality of setting the current component saturation, component luma and component hue value. It ensures that the provided saturation, luma and hue value is valid and can be applied successfully.|
|18|[CMS](#cms)|This test verifies the functionality of saving the `CMS` value in the picture profile database for specificSettings. It ensures that the `CMS` values are stored correctly and can be applied automatically when needed.|
|19|[PQ Params](#pq-params)|This test verifies the functionality of retrieving the default `PQ` (Picture Quality) and `PQ` parameters for a given picture mode, primary video source, and video format. It ensures that the default values and `PQ` parameter values are retrieved correctly.|
|20|[Get Max Gain Value](#get-max-gain-value)|This test verifies the functionality of retrieving the maximum gamma/white balance gain value capable for the platform. It ensures that the returned value is within the valid range and accurately reflects the maximum gain value.|
|21|[Gamma Mode, Gamma pattern and Get TV Gamma Target](#gammamode-gammapattern-and-get-tv-gamma-target)|This test verifies the functionality of enabling or disabling the gamma mode, gamma patter and get tv gamma target. It ensures that the gamma module can be successfully enabled or disabled as intended.|
|22|[Get and Set RGB Pattern Gray Pattern](#get-and-set-rgb-pattern-gray-pattern)|This test verifies the functionality of setting the RGB and Gray pattern. It ensures that the primary color levels can be set accurately and displayed as intended on the screen.|
|23|[Get Open Circuit Status](#get-open-circuit-status)|This test verifies the functionality of retrieving the current open circuit status of the backlight hardware. It ensures that the returned status indicates whether any `LED` fault is detected.|
|24|[LDIM and LDIM Sequence Test](#ldim-and-ldim-sequence-test)|This test verifies the functionality of enabling or disabling the local dimming module, pixel compensation and sequence test. It ensures that the local dimming module can be successfully validated.|
|25|[Set Backlight Test Mode](#set-backlight-test-mode)|This test verifies the functionality of setting the backlight test mode. It ensures that the backlight hardware can be configured correctly for calibration purposes based on the specified test mode.|
|26|[Enable and Disable White Balance, Dynamic Contrast and Local Contrast](#enable-and-disable-white-balance-dynamiccontrast-and-local-contrast)|This test verifies the functionality of enabling or disabling the white balance, dynamic contrast and local contrast module. It ensures that the white balance, dynamic contrast and local contrast module can be successfully enabled or disabled as intended.|
|27|[Test the save setting values](#test-the-save-setting-values)|This test verifies the functionality of saving all persistence settings by rebooting the test case.|
|28|[Get short Circuit Status](#get-short-circuit-status)|This test verifies the functionality of retrieving the short circuit status of the adjacent zones. It ensures that the returned status indicates whether any short is detected.|
-----------

### Test Start up Requirement

- The test boots with the primary video for changing the video format, video resolutions, frame rates, etc.
- The test boots with the source devices or external devices.
- The test boots with the external analyzer to check the all tvsetting functionality.
- The test begins with the following supported configuration capability information.
  - Supported video formats [tvVideoFormatType_t](https://github.com/comcast-sky/rdk-components-hal-tvsettings/blob/develop/include/tvTypes.h#L112) .
  - Supported video resolutions [tvResolutionParam_t](https://github.com/rdkcentral/rdkv-halif-tvsettings/blob/main/include/tvTypes.h#L461).
  - Supported video frame rates [tvVideoFrameRate_t](https://github.com/rdkcentral/rdkv-halif-tvsettings/blob/main/include/tvTypes.h#L216).
  - Supported video sources [tvVideoSrcType_t](https://github.com/rdkcentral/rdkv-halif-tvsettings/blob/main/include/tvTypes.h#L150).
  - Supported list of backlight support values.
  - Supported list of backlight fade support values.
  - Supported list of dimming mode supports.
  - Supported Local Dimming Level supports [tvDimmingMode_t](https://github.com/rdkcentral/rdkv-halif-tvsettings/blob/main/include/tvTypes.h#L402).
  - Supported brightness levels.
  - Supported contrast levels.
  - Supported sharpness levels.
  - Supported saturation levels.
  - Supported hue levels.
  - Supported color temperature levels.
  - Supported aspect ratio levels [tvDisplayMode_t](https://github.com/rdkcentral/rdkv-halif-tvsettings/blob/main/include/tvTypes.h#L231).
  - Supported low latency levels.
  - Supported dynamic gamma levels.
  - Supported dynamic contrast levels.
  - Supported Dolby Vision Modes [tvDolbyMode_t](https://github.com/rdkcentral/rdkv-halif-tvsettings/blob/main/include/tvTypes.h#L391).
  - Supported picture modes [pic_modes_t](https://github.com/rdkcentral/rdkv-halif-tvsettings/blob/main/include/tvTypes.h#L492).
  - Supported color temperature for RGB gain on source [tvColorTemp_t](https://github.com/rdkcentral/rdkv-halif-tvsettings/blob/main/include/tvTypes.h#251) [tvColorTempSourceOffset_t](https://github.com/rdkcentral/rdkv-halif-tvsettings/blob/main/include/tvTypes.h#L124).
  - Supported color temperature for RGB post offset on source. [tvColorTemp_t](https://github.com/rdkcentral/rdkv-halif-tvsettings/blob/main/include/tvTypes.h#251) [tvColorTempSourceOffset_t](https://github.com/rdkcentral/rdkv-halif-tvsettings/blob/main/include/tvTypes.h#L124).
  - Supported calibration modes.
  - Supported gamma table values.
  - Supported Dv Tmax values.
  - Supported component color, component saturation, component hue, component luma values [tvDataComponentColor_t](https://github.com/rdkcentral/rdkv-halif-tvsettings/blob/main/include/tvTypes.h#L298).
  - Supported component Types [tvComponentType_t](https://github.com/rdkcentral/rdkv-halif-tvsettings/blob/main/include/tvTypes.h#L311)
  - Supported `CMS` values.
  - Supported `PQ` params [tvPQParameterIndex_t](https://github.com/rdkcentral/rdkv-halif-tvsettings/blob/main/include/tvTypes.h#L374).
  - Supported Local Dimming levels [ldimStateLevel_t](https://github.com/rdkcentral/rdkv-halif-tvsettings/blob/main/include/tvTypes.h#414)
  - Supported Max Gain values.
  - Supported gamma mode values.
  - Supported gamma patterns.
  - Supported TV gamma target.
  - Supported gamma pattern mode.
  - Supported RGB pattern.
  - Supported gray pattern.
  - Supported LDIM pixel compensation.
  - Supported backlight mode test.
  - Supported white balance values.

### Emulator Requirement

The emulator boots with the above configured capability information

## Callback Mechanisms

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Verify that the callback is triggered when modifying the video formats. The test should include changes to various video formats (HDR10, HDR10+, HLG, SDR, etc.) |RegisterVideoFormatChangeCB|N|Y|Y|
|Verify the behavior of the callback to ensure it provides the default VIDEO_FORMAT_SDR when changing the video formats if the playback has not started or is stopped.|RegisterVideoFormatChangeCB|N|Y|Y|
|Verify that the callback gets triggered when modifying the video Resolution for the primary video.The test should include changes to various video Resolutions. |RegisterVideoResolutionChangeCB|N|Y|Y|
|Verify the behavior of the callback to ensure it provides the default tvVideoResolution_NONE when changing the video formats if the playback has not started or is stopped.|RegisterVideoResolutionChangeCB|N|Y|Y|
|Ensure that the callback is triggered when modifying the Filmmaker mode change event upon detection of the `FMM` enter event, which involves detecting `SEI` content-type 0x01 and content-subtype 0x00|RegisterVideoContentChangeCB|N|Y|Y|
|Ensure that the callback is triggered when modifying the Filmmaker mode change event upon detection of the `FMM` exit event, which involves detecting `SEI` content-type is other than 0x01 and content-subtype is other than 0x00|RegisterVideoContentChangeCB|N|Y|Y|
|Verify the behavior of the callback to ensure it provides the Filmmaker Exit event, which involves detecting SEI content-type if the playback has not started or is stopped.|RegisterVideoContentChangeCB|N|Y|Y|
|Verify that the callback gets triggered when modifying the video framerate. The test should include changes to various video framerates |RegisterVideoFrameRateChangeCB|N|Y|Y|
|Verify the behavior of the callback to ensure it provides the default tvVideoFrameRate_NONE if the playback has not started or is stopped.|RegisterVideoFrameRateChangeCB|N|Y|Y|

### Test Startup Requirement - Callback Mechanisms

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - Callback Mechanisms

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - Callback Mechanisms

The Control Plane dynamically adjusts to various video formats, video resolutions, Film Maker modes, and video frame rates to trigger the callbacks.

## Video Formats

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Get TV supported video formats and verify that the test provides all supported video formats and their count (minimum is 1 and maximum is VIDEO_FORMAT_MAX). Compare the test results with the platform-supported configurations file, 'Sink-4K-TvSettings.yaml', using the path 'VideoFormat/index' and loop through the indices, using the path 'VideoFormat/numberOfFormats' compare the count.|GetTVSupportedVideoFormats()|Y|N|N|
|Verify getting the current video format when there is no video playback. Default is VIDEO_FORMAT_SDR|GetCurrentVideoFormat()|Y|N|N|
|Verify getting the current video format during video playback. Check with the analyzer whether it updates the correct video format of the playback video.|GetCurrentVideoFormat()|N|Y|Y|
|Verify the current video format by dynamically changing various video formats. Check with the analyzer whether it updates the correct video format of the playback video.|GetCurrentVideoFormat()|N|Y|Y|

### Test Startup Requirement - Video Formats

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - Video Formats

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - Video Formats

- Control plane connects and dynamically adjusts various video formats from external devices.

## Get Current Video Resolution

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Verify the current video resolution of the primary video. Check with the analyzer whether it updates the correct video resolution of the playback video.|GetCurrentVideoResolution()|N|Y|N|
|Verify that the current video resolution of the primary video is 'tvVideoResolution_NONE' when playback has not started or has been stopped.|GetCurrentVideoResolution()|Y|N|N|
|Verify the current video resolution of the primary video by playing back different videos sources with different resolutions.|GetCurrentVideoResolution()|N|Y|Y|

### Test Startup Requirement - Get Current Video Resolution

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - Get Current Video Resolution

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - Get Current Video Resolution

- Control plane connects and dynamically adjusts various video resolutions from external devices.

## Get Current Video FrameRate

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Verify the video frame rate of the current primary video. Check with the analyzer whether it updates the correct video FrameRate of the playback video.|GetCurrentVideoFrameRate()|N|Y|N|
|Verify that the current video frame rate of the primary video is 'tvVideoFrameRate_NONE' when playback has not started or has been stopped.|GetCurrentVideoFrameRate()|Y|N|N|
|Verify the current video frame rate of the primary video by playing back videos with different frame rates.|GetCurrentVideoFrameRate()|N|Y|Y|

### Test Startup Requirement - Get Current Video FrameRate

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - Get Current Video FrameRate

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - Get Current Video FrameRate

- Control plane connects and dynamically adjusts various video frame rates from external devices.

## Video Sources

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Get TV Supported Video Sources - Verify the test provides all supported video sources and their count( Min is 1 and Max is VIDEO_SOURCE_MAX). Compare the test results with the platform-supported configurations file, 'Sink-4K-TvSettings.yaml', using the path 'VideoSource/index' and loop through the indices, using the path 'VideoSource/numberOfSources' compare the count.|GetTVSupportedVideoSources()|Y|N|N|
|Verify when there is no video source device is connected. Default is VIDEO_SOURCE_IP|GetCurrentVideoSource()|Y|N|N|
|Verify the video source selected for the current primary video. Check with the analyzer whether it updates the correct video sources of the playback video.|GetCurrentVideoSource()|N|Y|Y|
|Verify the video source selected for the current primary video by selecting different video sources.|GetCurrentVideoSource()|N|Y|Y|

### Test Startup Requirement - Video Sources

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - Video Sources

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - Video Sources

- Control plane connects and disconnects various video sources from external devices.

## BackLight BackLightfade Backlightmodes and TV Dimming Modes

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Sets and Gets the backlight within the valid range (0 - 100). The retrieved value should match the set value. Get values are retrieved from the `PQ` database.|SetBacklight(), GetBacklight()|Y|N|N|
|Set and Gets the Back light and check the functionality for selected video sources, formats, and picture modes. Verify that upon switching to different content and returning to the chosen source, format, and mode, the backlight remain retained. Validate using the analyzer and various video sources, video formats and picture modes.|SetBacklight(), GetBacklight()|N|Y|Y|
|Set and Gets the Back light fade within the valid ranges of from ( 0  - 100 ) , to ( 0 - 100 ), current( 0 - 100) and duration (0 - 10000 ms). The retrieved value should match the set value. Get values are retrieved from the `PQ` database. |GetCurrentBacklightFade(), SetBacklightFade()|Y|N|N|
|Set and get the backlight fade to test the backlight fade settings. Verify that upon switching to different content and returning to the chosen source, format, and mode, the backlight does not retain the previous value and moves to a new backlight value, as it does not save. Check with the analyzer whether it fades between the two different backlight values specified within a given duration. Validate this behavior with various video sources and video formats.|GetCurrentBacklightFade(), SetBacklightFade()|N|Y|Y|
|Get Supported Back light Modes - verifies to get the all supported backlight modes. Compare the test results with the platform-supported configurations file, 'Sink-4K-TvSettings.yaml', using the path 'BacklightControl/index' and loop through the indices.|GetSupportedBacklightModes()|Y|N|N|
|Set and Gets the current Back light modes. The retrieved value should match the set value. Get values are retrieved from the `PQ` database.|GetCurrentBacklightMode(), SetCurrentBacklightMode()|Y|N|Y|
|Set and Gets the current Back light modes by dynamically changing the various back light modes. Check by analyzer whether it adjust to the new back light modes. Validate with various video sources and formats.|GetCurrentBacklightMode(), SetCurrentBacklightMode()|N|Y|Y|
|Set and Gets the current backlight modes by verifying the Auto backlight mode (tvBacklightMode_AMBIENT). Check with the analyzer whether it adjusts the backlight levels of the screen based on the ambient light conditions. Validate with various video sources and formats.|GetCurrentBacklightMode(), SetCurrentBacklightMode()|N|Y|Y|
|Gets TV Supported Dimming Modes - Verify the test provides all supported backlight dimming modes and their count( Min is 1 and Max is tvDimmingMode_MAX). Compare the test results with the platform-supported configurations file, 'Sink-4K-TvSettings.yaml', using the path 'DimmingMode/index' and loop through the indices. For the count use the path 'DimmingMode/numberOfDimmingModes'|GetTVSupportedDimmingModes()|Y|N|Y|
|Set and Gets the TV Dimming modes. The retrieved value should match the set value. Get values are retrieved from the `PQ` database.|SetTVDimmingMode(), GetTVDimmingMode()|Y|N|N|
|Set and Gets the TV Dimming modes and check the functionality for selected video sources, formats, and picture modes. Verify that upon switching to different content and returning to the chosen source, format, and mode, the TV dimming modes remain retained. Validate with an analyzer whether the changes are applied to the hardware, and test using various video sources, video formats, and picture modes.|SetTVDimmingMode(), GetTVDimmingMode()|N|Y|Y|
|Set and get the TV dimming modes. Test whether changing the dimming mode affects the panel's peak brightness and verify that the EDID reloads to update the VSVDB string. Validate this with the video format managed by the Dolby Vision core. Validate by analyzer. |SetTVDimmingMode(), GetTVDimmingMode()|N|Y|Y|

### Test Startup Requirement - Back light - Back light fade - Back light modes and TV Dimming Modes

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - Back light - Back light fade - Back light modes and TV Dimming Modes

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - Back light - Back light fade - Back light modes and TV Dimming Modes

- Control plane checks the functionality with the analyzer by using different video sources, video formats, and picture settings to test the backlight fade, backlight, backlight modes, and TV dimming modes.

## LocalDimmingLevel Brightness Contrast Sharpness Saturation and Hue

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Set and Gets the local Dimming level. The retrieved value should match the set value. Get values are retrieved from the  database.|SetLocalDimmingLevel(), GetLocalDimmingLevel()|Y|N|N|
|Set and get the local dimming level, and check the functionality for selected video sources, formats, and picture modes. Verify that upon switching to different content and returning to the chosen source, format, and mode, the local dimming level remain retained. Validate with an analyzer whether the changes are applied to the hardware, and test using various video sources, video formats, and picture modes.|SetLocalDimmingLevel(), GetLocalDimmingLevel()|N|Y|Y|
|Set and get the local Dimming level. Test whether changing the dimming level affects the panel's peak brightness and verify that the EDID reloads to update the VSVDB string. Validate this with the video format managed by the Dolby Vision core. Validate by analyzer. |SetLocalDimmingLevel(), GetLocalDimmingLevel()|N|Y|Y|
|Set and Gets the brightness within the valid range ( 0 - 100 ). The retrieved value should match the set value. Get values are retrieved from the database.|SetBrightness(), GetBrightness()|Y|N|N|
|Set and get the brightness level, and check the functionality for selected video sources, formats, and picture modes. Verify that upon switching to different content and returning to the chosen source, format, and mode, the brightness remain retained. Validate with an analyzer whether the changes are applied to the hardware, and test using various video sources, video formats, and picture modes.|SetBrightness(), GetBrightness()|N|Y|Y|
|Set and Gets the contrast within the valid range ( 0 - 100 ). The retrieved value should match the set value. Get values are retrieved from the database.|SetContrast(), GetContrast()|Y|N|N|
|Set and get the contrast level, and check the functionality for selected video sources, formats, and picture modes. Verify that upon switching to different content and returning to the chosen source, format, and mode, the contrast remain retained. Validate with an analyzer whether the changes are applied to the hardware, and test using various video sources, video formats, and picture modes.|SetContrast(), GetContrast()|N|Y|Y|
|Set and Gets the sharpness ( 0 - 100 ). The retrieved value should match the set value. Get values are retrieved from the database.|SetSharpness(), GetSharpness()|Y|N|N|
|Set and get the sharpness level, and check the functionality for selected video sources, formats, and picture modes. Verify that upon switching to different content and returning to the chosen source, format, and mode, the sharpness remain retained. Validate with an analyzer whether the changes are applied to the hardware, and test using various video sources, video formats, and picture modes.|SetSharpness(), GetSharpness()|N|Y|Y|
|Set and Gets the saturation within the valid range ( 0 - 100 ). The retrieved value should match the set value. Get values are retrieved from the database.|SetSaturation(), GetSaturation()|Y|N|N|
|Set and get the saturation level, and check the functionality for selected video sources, formats, and picture modes. Verify that upon switching to different content and returning to the chosen source, format, and mode, the saturation remain retained. Validate with an analyzer whether the changes are applied to the hardware, and test using various video sources, video formats, and picture modes.|SetSaturation(), GetSaturation()|N|Y|Y|
|Set and Gets the Hue ( 0 - 100 ) . The retrieved value should match the set value. Get values are retrieved from the database.|SetHue(), GetHue()|Y|N|N|
|Set and get the Hue level, and check the functionality for selected video sources, formats, and picture modes. Verify that upon switching to different content and returning to the chosen source, format, and mode, the Hue remain retained. Validate with an analyzer whether the changes are applied to the hardware, and test using various video sources, video formats, and picture modes.|SetHue(), GetHue()|N|Y|Y|

### Test Startup Requirement - Local Dimming Level - Brightness - Contrast - Sharpness - Saturation and Hue

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - Local Dimming Level - Brightness - Contrast - Sharpness - Saturation and Hue

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - Local Dimming Level - Brightness - Contrast - Sharpness - Saturation and Hue

- Control plane checks the functionality by analyzer and the different  streams to test the local dimming level, brightness levels, contrast levels, Sharpness levels and Saturation levels.

## ColorTemperature AspectRatio LowLatencyState DynamicContrast and DynamicGamma

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Set and Gets the Color Temperature. The retrieved value should match the set value. Get values are retrieved from the database.|SetColorTemperature, GetColorTemperature|Y|N|N|
|Set and get the color Temperature, and check the functionality for selected video sources, formats, and picture modes. Verify that upon switching to different content and returning to the chosen source, format, and mode, the color temperature remain retained. Validate with an analyzer whether the changes are applied to the hardware, and test using various video sources, video formats, and picture modes.|SetColorTemperature, GetColorTemperature|N|Y|Y|
|Set and Gets the Aspect Ratio. The retrieved value should match the set value. Get values are retrieved from the database.|SetAspectRatio, GetAspectRatio|Y|N|N|
|Set and get the Aspect Ratio, and check the functionality for selected video sources, formats, and picture modes. Verify that upon switching to different content and returning to the chosen source, format, and mode, the Aspect Ratio remain retained. Validate with an analyzer whether the changes are applied to the hardware, and test using various video sources, video formats, and picture modes.|SetAspectRatio, GetAspectRatio|N|Y|Y|
|Set and Gets the Low Latency State ( 0 for disable and 1 for enable ). The retrieved value should match the set value. Get values are retrieved from the database.|SetLowLatencyState, GetLowLatencyState|Y|N|N|
|Set and get the dynamic contrast state, and check the functionality for selected video sources, formats, and picture modes. Validate whether the changes are applied in the PQ module. Verify that upon switching to different content and returning to the chosen source, format, and mode, the dynamic contrast should not be retained. Validate with an analyzer and test using various video sources, video formats, and picture modes.|SetLowLatencyState, GetLowLatencyState|N|Y|Y|
|Set and Gets the Dynamic Contrast. The retrieved value should match the set value. Get values are retrieved from the database.|SetDynamicContrast, GetDynamicContrast|Y|N|N|
|Set and Gets the Dynamic Contrast, and check the functionality for the different video sources, formats, and picture modes to ensure whether it reverts the default settings for the video format, video source and picture mode|SetDynamicContrast, GetDynamicContrast|N|Y|Y|
|Set and Gets the Dynamic Gamma within the valid range ( 1.80 to 2.60 ). The retrieved value should match the set value. Get values are retrieved from the database.|SetDynamicGamma(), GetDynamicGamma()|Y|N|N|
|Set and get the Dynamic Gamma. Validate the functionality by adjusting the color temperature and confirming that the new gamma curve shifts according to the set Dynamic Gamma value. Validate with the analyzer and with various video sources, formats, and color temperatures.|SetDynamicGamma(), GetDynamicGamma()|N|Y|Y|

### Test Startup Requirement - Color Temperature - Aspect Ratio -  Low Latency State - Dynamic Contrast and Dynamic Gamma

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - Color Temperature - Aspect Ratio -  Low Latency State - Dynamic Contrast and Dynamic Gamma

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - Color Temperature - Aspect Ratio -  Low Latency State - Dynamic Contrast and Dynamic Gamma

- Control plane checks the functionality by analyzer.
- For color temperature, aspect ratio and low latency state, control plane dynamically changing the selected video sources, formats and picture modes by the external devices
- For dynamic contrast, control plane dynamically changing the different video sources, formats and picture modes by the external devices
- For dynamic gamma, control plane adjust the color temperature by the external sources.

## TV Dolby Vision mode

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Get TV Supported Dolby Vision Modes - Verify the test provides all supported Dolby vision modes and their count( Min is 0 and Max is tvMode_Max ). Compare the test results with the platform-supported configurations file, 'Sink-4K-TvSettings.yaml', using the path 'DolbyVisionMode/index' and loop through the indices. For the count use the path 'DolbyVisionMode/numberOfDolbyVisionMode'|GetTVSupportedDolbyVisionModes()|Y|N|N|
|Set and Gets the TV Dolby Vision mode. The retrieved value should match the set value. Get values are retrieved from the database.|SetTVDolbyVisionMode(), GetTVDolbyVisionMode()|Y|N|N|
|Set and get the Dolby Vision mode value, and check the functionality for selected video sources, formats, and picture modes. Verify that upon switching to different content and returning to the chosen source, format, and mode, the Dolby Vision mode remains retained. Validate with an analyzer whether the changes are applied to the hardware, and test using various video sources, video formats, and picture modes.|SetTVDolbyVisionMode(), GetTVDolbyVisionMode()|N|Y|Y|

### Test Startup Requirement - TV Dolby Vision mode

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - TV Dolby Vision mode

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - TV Dolby Vision mode

- Control plane checks the functionality by analyzer and check the functionality for the different selected video sources, formats, and picture modes.

## Picture Modes

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Get TV Supported Picture Modes - Verify the test provides all supported Picture Modes and their count( Min is 1 and Max is PIC_MODES_SUPPORTED_MAX ). Compare the test results with the platform-supported configurations file, 'Sink-4K-TvSettings.yaml', using the path 'PictureMode/index' and loop through the indices. For the count use the path 'PictureMode/numberOfPictureModes'|GetTVSupportedPictureModes()|Y|N|N|
|Set and Gets the TV Picture Mode. The retrieved value should match the set value. Set the picture mode to a valid value as specified by `pic_modes_t.name` from the GetTVSupportedPictureModes API, with the string size limited to PIC_MODE_NAME_MAX. Get values are retrieved from the database.|GetTVSupportedPictureModes(), SetTVPictureMode(), GetTVPictureMode()|Y|N|N|
|Set and get the TV picture modes and their associated properties, and verify the functionality across selected video sources, formats, and picture modes. Confirm that upon switching to different content and returning to the chosen source, format, and mode, the set picture mode and its properties are reloaded correctly. Validate with an analyzer whether the associated changes in picture properties are applied to the new mode, and conduct testing using various video sources, formats, and picture modes.|SetTVPictureMode(), GetTVPictureMode()|N|Y|Y|

### Test Startup Requirement - Picture Modes

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - Picture Modes

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - Picture Modes

- Control plane checks the functionality by analyzer and check the functionality for the different selected video sources, formats, and picture modes.

## Color Temperature Rgain Ggain Bgain on source

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Loop through different color temperatures and source ids. Set and Gets the color Temperature Rgain on Source. The retrieved value should match the set value. Get values are retrieved from the database.|SetColorTemp_Rgain_onSource(), GetColorTemp_Rgain_onSource()|Y|N|N|
|Set and Get color temperature Rgain for a specific color temperature and video source and confirm functionality across chosen video sources, formats, and picture modes. Ensure the correct utilization of Rgain in the white balance module. When 'saveOnly = 0', validate behavior upon content change and check whether it revert to default picture profile database values. Validate using the analyzer and across video sources, formats, and picture modes.|SetColorTemp_Rgain_onSource(), GetColorTemp_Rgain_onSource()|N|Y|Y|
|Set and get color temperature Rgain for the specific video source and color temperature, and confirm functionality across chosen video sources, formats, and picture modes. Ensure the correct utilization of Rgain in the white balance module. When 'saveOnly = 1', validate behavior upon content change and switching to either selected video source, format, or picture mode color temperature will be automatically applied to the white balance module. Validate using the analyzer and across video sources, formats, and picture modes.|SetColorTemp_Rgain_onSource(), GetColorTemp_Rgain_onSource()|N|Y|Y|
|Loop through different color temperatures and source ids. Set and Gets the color Temperature Ggain on Source. The retrieved value should match the set value. Get values are retrieved from the  database.|SetColorTemp_Ggain_onSource(), GetColorTemp_Ggain_onSource()|Y|N|N|
|Set and Get color temperature Ggain for a specific color temperature and video source and confirm functionality across chosen video sources, formats, and picture modes. Ensure the correct utilization of Ggain in the white balance module. When 'saveOnly = 0', validate behavior upon content change and check whether it revert to default picture profile database values. Validate using the analyzer and across video sources, formats, and picture modes.|SetColorTemp_Rgain_onSource(), GetColorTemp_Ggain_onSource()|N|Y|Y|
|Set and get color temperature Ggain for the specific video source and color temperature, and confirm functionality across chosen video sources, formats, and picture modes. Ensure the correct utilization of Ggain in the white balance module. When 'saveOnly = 1', validate behavior upon content change and switching to either selected video source, format, or picture mode color temperature will be automatically applied to the white balance module. Validate using the analyzer and across video sources, formats, and picture modes.|SetColorTemp_Rgain_onSource(), GetColorTemp_Ggain_onSource()|N|Y|Y|
|Loop through different color temperatures and source ids. Set and Gets the color Temperature Bgain on Source. The retrieved value should match the set value. Get values are retrieved from the  database.|SetColorTemp_Bgain_onSource(), GetColorTemp_Bgain_onSource()|Y|N|N|
|Set and Get color temperature Bgain for a specific color temperature and video source and confirm functionality across chosen video sources, formats, and picture modes. Ensure the correct utilization of Bgain in the white balance module. When 'saveOnly = 0', validate behavior upon content change and check whether it revert to default picture profile database values. Validate using the analyzer and across video sources, formats, and picture modes.|SetColorTemp_Bgain_onSource(), GetColorTemp_Rgain_onSource()|N|Y|Y|
|Set and get color temperature Bgain for the specific video source and color temperature, and confirm functionality across chosen video sources, formats, and picture modes. Ensure the correct utilization of Bgain in the white balance module. When 'saveOnly = 1', validate behavior upon content change and switching to either selected video source, format, or picture mode color temperature will be automatically applied to the white balance module. Validate using the analyzer and across video sources, formats, and picture modes.|SetColorTemp_Bgain_onSource(), GetColorTemp_Rgain_onSource()|N|Y|Y|

### Test Startup Requirement - Color Temperature Rgain Ggain Bgain on source

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - Color Temperature Rgain Ggain Bgain on source

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - Color Temperature Rgain Ggain Bgain on source

- Control plane checks the functionality by analyzer and dynamically changing the selected video sources, formats, and picture modes.

## Color Temperature R post G post and B post offset onsource

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Loop through different color temperatures and source ids. Set and Gets the color Temperature R post offset on Source. The retrieved value should match the set value. Get values are retrieved from the  database.|SetColorTemp_R_post_offset_onSource(), GetColorTemp_R_post_offset_onSource()|Y|N|N|
|Set and Get color temperature R post offset for a specific color temperature and video source and confirm functionality across chosen video sources, formats, and picture modes. Ensure the correct utilization of R post offset in the white balance module. When 'saveOnly = 0', validate behavior upon content change and check whether it revert to default picture profile database values. Validate using the analyzer and across video sources, formats, and picture modes.|SetColorTemp_R_post_offset_onSource(), GetColorTemp_R_post_offset_onSource()|N|Y|Y|
|Set and get color temperature R post offset for the specific video source and color temperature, and confirm functionality across chosen video sources, formats, and picture modes. Ensure the correct utilization of R post offset in the white balance module. When 'saveOnly = 1', validate behavior upon content change and switching to either selected video source, format, or picture mode color temperature will be automatically applied to the white balance module. Validate using the analyzer and across video sources, formats, and picture modes.|SetColorTemp_R_post_offset_onSource(), GetColorTemp_R_post_offset_onSource()|N|Y|Y|
|Loop through different color temperatures and source ids. Set and Gets the color Temperature G post offset on Source. The retrieved value should match the set value. Get values are retrieved from the  database.|SetColorTemp_G_post_offset_onSource(), GetColorTemp_G_post_offset_onSource()|Y|N|N|
|Set and Get color temperature G post offset for a specific color temperature and video source and confirm functionality across chosen video sources, formats, and picture modes. Ensure the correct utilization of G post offset in the white balance module. When 'saveOnly = 0', validate behavior upon content change and check whether it revert to default picture profile database values. Validate using the analyzer and across video sources, formats, and picture modes.|SetColorTemp_G_post_offset_onSource(), GetColorTemp_G_post_offset_onSource()|N|Y|Y|
|Set and get color temperature G post offset for the specific video source and color temperature, and confirm functionality across chosen video sources, formats, and picture modes. Ensure the correct utilization of G post offset in the white balance module. When 'saveOnly = 1', validate behavior upon content change and switching to either selected video source, format, or picture mode color temperature will be automatically applied to the white balance module. Validate using the analyzer and across video sources, formats, and picture modes.|SetColorTemp_G_post_offset_onSource(), GetColorTemp_G_post_offset_onSource()|N|Y|Y|
|Loop through different color temperatures and source ids. Set and Gets the color Temperature B post offset on Source. The retrieved value should match the set value. Get values are retrieved from the  database.|SetColorTemp_B_post_offset_onSource(), GetColorTemp_B_post_offset_onSource()|Y|N|N|
|Set and Get color temperature B post offset for a specific color temperature and video source and confirm functionality across chosen video sources, formats, and picture modes. Ensure the correct utilization of B post offset in the white balance module. When 'saveOnly = 0', validate behavior upon content change and check whether it revert to default picture profile database values. Validate using the analyzer and across video sources, formats, and picture modes.|SetColorTemp_B_post_offset_onSource(), GetColorTemp_B_post_offset_onSource()|N|Y|Y|
|Set and get color temperature B post offset for the specific video source and color temperature, and confirm functionality across chosen video sources, formats, and picture modes. Ensure the correct utilization of B post offset in the white balance module. When 'saveOnly = 1', validate behavior upon content change and switching to either selected video source, format, or picture mode color temperature will be automatically applied to the white balance module. Validate using the analyzer and across video sources, formats, and picture modes.|SetColorTemp_B_post_offset_onSource(), GetColorTemp_B_post_offset_onSource()|N|Y|Y|

### Test Startup Requirement - Color Temperature R post G post and B post offset onsource

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - Color Temperature R post G post and B post offset onsource

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - Color Temperature R post G post and B post offset onsource

- Control plane checks the functionality by analyzer and dynamically changing the selected video sources, formats, and picture modes.

## `WB` Calibration Mode

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Disables the `WB` Calibration Mode and verify by the Get Current WB Calibration Mode|EnableWBCalibrationMode(), GetCurrentWBCalibrationMode()|Y|N|N|
|Enables the `WB` Calibration Mode and verify by the Get Current WB Calibration Mode|EnableWBCalibrationMode(), GetCurrentWBCalibrationMode()|Y|N|N|
|Enables the `WB` Calibration Mode and test. When enabled configures backlight in fixed dimming mode and sets all `PQ` elements except for gamma/white balance elements in bypass mode/disabled mode. Validate this with the analyzer and using the different video streams.|EnableWBCalibrationMode(), GetCurrentWBCalibrationMode()|N|Y|Y|
|Disables the `WB` Calibration Mode and test. On disable restores the dimming mode and all `PQ` elements in the last known state before the WB calibration mode was enabled. Validate this with the analyzer and test using the different video streams.|EnableWBCalibrationMode(), GetCurrentWBCalibrationMode()|N|Y|Y|

### Test Startup Requirement - `WB` Calibration Mode

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - `WB` Calibration Mode

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - `WB` Calibration Mode

- Control plane uses analyzer to check the settings when it is turned on and check the backlight stay at a constant low brightness level except gamma/white balance adjustments.
- Control plane uses analyzer to check the settings When you disable this feature, it brings back the previous dimming mode and restores all PQ adjustments to the settings they were in before you activated the white balance calibration mode.

## Get and Set Gamma Table

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Set and Gets the Gamma Table within the range ( 0 - 1023). The retrieved value should match the set value. Get values are retrieved from the  database.|GetGammaTable(), SetGammaTable()|Y|N|N|
|Test the Gamma Table functionality by setting and retrieving values across chosen video sources, formats, and picture modes. Verify that when content changes or switching between video sources, formats, and picture modes occurs, any set Gamma table values are discarded ( since it is not saved ), ensuring default values from the picture profile database are utilized. Validate this behavior with an analyzer and test across multiple video sources, formats, and picture modes.|GetGammaTable(), SetGammaTable()|N|Y|Y|
|Gets the default gamma calibrated values for gamma red, green and blue values ( 0 - 65535 ) and check the values are in the range.|GetDefaultGammaTable()|Y|N|N|

### Test Startup Requirement - Get and Set Gamma Table

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - Get and Set Gamma Table

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - Get and Set Gamma Table

- Control plane checks the functionality by analyzer and dynamically changing the selected video sources, formats, and picture modes.

## Get and Set Dv Tmax Value

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Set and Gets the Dv Tmax Value within the range ( 0 - 10000 ). The retrieved value should match the set value. Get values are retrieved from the  database.|SetDvTmaxValue(), GetDvTmaxValue()|Y|N|N|
|Set and retrieve the Dolby Vision Tmax value and verify functionality across selected video sources, formats, and picture modes. Since it is not saved, upon changing the content and switching back to the selected video sources, formats, and picture modes, the Dolby Vision Tmax value should be discarded, and the default value from the picture profile database should be used instead. Validate functionality using the analyzer and across various video sources, formats, and picture modes.|SetDvTmaxValue(), GetDvTmaxValue()|N|Y|Y|

### Test Startup Requirement - Get and Set Dv Tmax Value

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - Get and Set Dv Tmax Value

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - Get and Set Dv Tmax Value

- Control plane checks the functionality by analyzer and dynamically changing the selected video sources, formats, and picture modes.

## Get Supported Component Color

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Verifies whether the test gets the supported component colors by comparing the test results with the platform-supported configurations file, 'Sink-4K-TvSettings.yaml', using the path 'SupportedComponentColor' and loop through the indices.|GetSupportedComponentColor()|Y|N|N|

### Test Startup Requirement - Get Supported Component Color

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - Get Supported Component Color

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - Get Supported Component Color

None

## CurrentComponentSaturation Component Hue and Component Luma

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Set and Get the component saturation by verifying whether the values are within the valid range (0 - 100). The retrieved value should match the set value. Get values are fetched from the  database.|SetCurrentComponentSaturation(), GetCurrentComponentSaturation()|Y|N|N|
|Set and Get the Component Saturation, and verify its functionality with the currently selected video sources, formats, and picture modes to ensure it uses the set component saturation for the current selections. Confirm that when switching to different content and returning to the chosen source, format, and mode, the Component Saturation remains retained. Validate the component saturation using an analyzer and test it with different video sources, formats, and picture modes.|SetCurrentComponentSaturation(), GetCurrentComponentSaturation()|N|Y|Y|
|Set and Get the Component Hue by verifying whether the values are within the valid range (0 - 100). The retrieved value should match the set value. Get values are fetched from the  database.|SetCurrentComponentHue(), GetCurrentComponentHue()|Y|N|N|
|Set and Get the Component Hue, and verify its functionality with the currently selected video sources, formats, and picture modes to ensure it uses the set component Hue for the current selections. Confirm that when switching to different content and returning to the chosen source, format, and mode, the Component Hue remains retained. Validate the component Hue using an analyzer and test it with different video sources, formats, and picture modes.|SetCurrentComponentHue(), GetCurrentComponentHue()|N|Y|Y|
|Set and Gets the Component Luma by verifying whether the values are within the valid range (0 - 100). The retrieved value should match the set value. Get values are fetched from the  database.|SetCurrentComponentLuma(), GetCurrentComponentLuma()|Y|N|N|
|Set and Get the Component Luma, and verify its functionality with the currently selected video sources, formats, and picture modes to ensure it uses the set component Luma for the current selections. Confirm that when switching to different content and returning to the chosen source, format, and mode, the Component Luma remains retained. Validate the component Luma using an analyzer and test it with different video sources, formats, and picture modes.|SetCurrentComponentLuma(), GetCurrentComponentLuma()|N|Y|Y|

### Test Startup Requirement - Current Component Saturation - Component Hue and Component Luma

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - Current Component Saturation - Component Hue and Component Luma

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - Current Component Saturation - Component Hue and Component Luma

- Control plane verifies functionality using an analyzer and dynamically changes the content, then switches back to the selected video sources, formats, and picture modes.

## CMS

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Save CMS value and verify functionality with specific video sources, formats, and picture modes. Confirm its use for the selected video source, format, and mode. Ensure automatic application of the CMS value upon returning to chosen settings. Validate functionality with an analyzer across various video sources, picture modes, video formats, component types, and color types. Loop through different video sources, video formats, component type and color type. Check the case where component type and color type are 'none', ensuring CMS value acts as CMS state. Also, check the case where component type and color type are not 'none', ensuring CMS value acts within saturation (0 - 100), hue (0 - 100), and luma (0 - 30) ranges.|SaveCMS()|N|Y|Y|
|Set and Gets the `CMS` State. The retrieved value should match the set value. Get values are retrieved from the database.|SetCMSState(), GetCMSState()|Y|N|N|
|Set and Get the CMS state and verify its functionality with the currently selected video sources, formats, and picture modes to ensure it uses the saved CMS state for the selected video source, format, and mode. Ensure that when switching to different content and then returning to the selected source, format, and mode, the CMS state is applied automatically. Validate using an analyzer and with different video sources, formats, and picture modes. |SetCMSState(), GetCMSState()|N|Y|Y|

### Test Startup Requirement - CMS

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - CMS

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - CMS

- Control plane verifies functionality using an analyzer and dynamically changes the content, then switches back to the selected video sources, formats, and picture modes.

## PQ Params

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|To test the Get `PQ` Parameters, loop through the different video sources, video formats, and picture quality modes for all combinations and set the brightness, contrast, sharpness, and component saturation value (loop through different saturation colors) to 50%. For Tmax, set the value to 500, and for low latency, set it to 1. After setting these values, loop through the different video sources, video formats, and picture quality modes again, read back the GetPQ parameter values and ensure that all are set to the required values: brightness, contrast, sharpness, and component saturation at 50%, Tmax at 500, and low latency at 1.|SaveBrightness(), SaveContrast(), SaveSaturation(), SaveHue(), SaveLowLatencyState(), SetCurrentComponentSaturation(), SaveDvTmaxValue(), GetPQParams()|Y|N|N|

### Test Startup Requirement - Get Default PQ Params

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - Get Default PQ Params

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - Get Default PQ Params

None

## Get Max Gain Value

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Gets the max gamma/`WB` gain value for the platform and check it is in the range. The valid range can be from 2^10 till (2^31)-1. |GetMaxGainValue()|Y|N|N|

### Test Startup Requirement - Get Max Gain Value

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - Get Max Gain Value

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - Get Max Gain Value

None

## GammaMode Gammapattern and Get TV Gamma Target

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Enable Gamma Mode - Verifies enabling or disabling the gamma mode. It ensures successful enabling or disabling of the gamma module. Validation is required through different playback streams to test Gamma Mode, and validation by an analyzer.|EnableGammaMode()|N|Y|Y|
|Verify the Set Gamma Pattern Mode by setting the primary color level at 10-bit resolution (0 - 1023) and checking if it bypasses all PQ elements and displays the passed primary colors. Switch between different content and return to the selected source, ensuring that the Set Gamma Pattern mode is not retained as it does not save. Test with various video streams and formats. Validate this using the analyzer.|SetGammaPatternMode(true), SetGammaPattern()|N|Y|Y|
|Verify the Set Gamma Pattern Mode by setting the primary color level at 8-bit resolution (0 - 255) and checking if it bypasses all PQ elements and displays the passed primary colors. Switch between different content and return to the selected source, ensuring that the Set Gamma Pattern mode is not retained as it does not save. Test with various video streams and formats. Validate this using the analyzer.|SetGammaPatternMode(true), SetGammaPattern()|N|Y|Y|
|Get TV Gamma Target verifies the functionality of retrieving the target x and y coordinates for the panel gamma based on a given color temperature. It ensures that the returned coordinates are within the range of 0 to 1.0. Validate with various color temperatures (tvColorTemp_t).|GetTVGammaTarget()|Y|N|N|

### Test Startup Requirement - Gamma Mode - Gamma pattern and Get TV Gamma Target

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - Gamma Mode - Gamma pattern and Get TV Gamma Target

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - Gamma Mode - Gamma pattern and Get TV Gamma Target

- Control plane verifies functionality using an analyzer and dynamically changes the content, then switches back to the selected sources.

## Get and Set RGB Pattern Gray Pattern

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Set and Gets the RGB Pattern within the range ( 0 - 255 ). The retrieved value should match the set value. Get values are retrieved from the database.|SetRGBPattern(), GetRGBPattern()|Y|N|N|
|Set and Get the RGB Pattern at 8-bit resolution. The test sets the primary color level at 8-bit resolution and ensures the pattern is processed through the PQ pipeline before reaching the panel. Use the analyzer to test the scenario. Additionally, test the functionality with various video streams and formats.|SetRGBPattern(), GetRGBPattern()|N|Y|Y|
|Set and Gets the Gray Pattern within the range ( 0 - 255 ). The retrieved value should match the set value. Get values are retrieved from the database.|SetGrayPattern(), GetGrayPattern()|Y|N|N|
|Set and Get the Gray Pattern after enabling the set gamma pattern mode. The test sets various gray pattern levels and ensures it bypasses all PQ elements to display a full-screen gray pattern. Verify this using the analyzer and test with different playback streams to confirm the Gray Pattern is displayed correctly|SetGammaPatternMode(true), SetGrayPattern(), GetGrayPattern() |N|Y|Y|
|Set and Gets the Gray Pattern after disabling the set gamma pattern mode. Verify whether Set Gray Pattern take effect using the analyzer. |SetGammaPatternMode(false), SetGrayPattern(), GetGrayPattern() |N|Y|Y|

### Test Startup Requirement - Get and Set RGB Pattern Gray Pattern

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - Get and Set RGB Pattern Gray Pattern

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - Get and Set RGB Pattern Gray Pattern

- Control plane checks the functionality by analyzer and using the different playback streams to test the RGB pattern, Gray Pattern.

## Get Open Circuit Status

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Verifies the functionality of retrieving the current open circuit status of the backlight hardware. It ensures that the returned status indicates whether any `LED` fault is detected.|GetOpenCircuitStatus()|Y|N|N|

### Test Startup Requirement - Get Open Circuit Status

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - Get Open Circuit Status

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - Get Open Circuit Status

None

## LDIM and LDIM Sequence Test

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Enable `LDIM` - Enables or disables the local dimming module. When disabled, check that the backlight for all zones remains at a fixed level, and when enabled, it should not remain at a fixed level. Verify with the analyzer and different video sources, formats.|EnableLDIM()|N|Y|Y|
|Enable `LDIM` Pixel Compensation - Verifies the functionality of enabling or disabling the pixel compensation block for `LDIM` (Local Dimming). Check by analyzer and verify its functionality by playing different video streams to ensure any changes in pixel intensity caused by backlighting in local dimming zones.|EnableLDIMPixelCompensation()|N|Y|Y|
|Start `LDIM` Sequence Test - Verifies the local dimming sequence test. Initially, all local dimming (`LDIM`) zones are turned off, then each zone is turned on for a specified duration, sequentially repeating for all `LDIM` zones. Finally, the original state of all `LDIM` zones is restored at the end of the test. Monitor the behavior of the local dimming zones during the test using the analyzer.|StartLDIMSequenceTest()|N|Y|Y|

### Test Startup Requirement - LDIM and LDIM Sequence Test

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - LDIM and LDIM Sequence Test

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - LDIM and LDIM Sequence Test

- The control plane verifies functionality using an analyzer and dynamically changes various streams and formats.

## Set Backlight Test Mode

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Verifies the backlight hardware for calibration. Need to run the backlight test for normal, boost, burst and Reset modes. Monitor the calibration process by analyzer to confirm that it proceeds as intended.|SetBacklightTestMode()|N|Y|N|

### Test Startup Requirement - Set Backlight Test Mode

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - Set Backlight Test Mode

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - Set Backlight Test Mode

None

## Enable and Disable White Balance DynamicContrast and Local Contrast

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Enable White Balance - Verifies enabling or disabling the white balance module. Check with different playback video streams and verify the presence of white balance using the analyzer|EnableWhiteBalance()|N|Y|N|
|Enable Dynamic Contrast - Verifies the functionality of enabling or disabling the dynamic contrast module. Check the status by get dynamic contrast.|EnableDynamicContrast(), GetDynamicContrast()|Y|N|N|
|Enable Dynamic Contrast - Verifies enabling or disabling the Dynamic Contrast module. Check with different playback video streams and verify the presence of Dynamic Contrast using the analyzer|EnableDynamicContrast()|N|Y|Y|
|Enable Local Contrast - Verifies the functionality of enabling or disabling the local contrast module. Check with different playback video streams and verify the presence of local contrast using the analyzer|EnableLocalContrast()|N|Y|Y|

### Test Startup Requirement - Enable and Disable White Balance - Dynamic Contrast and Local Contrast

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - Enable and Disable White Balance - Dynamic Contrast and Local Contrast

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - Enable and Disable White Balance - Dynamic Contrast and Local Contrast

- Control plane checks the functionality by analyzer and using the different playback streams to test the White balance, Dynamic contrast and Local contrast.

## Test the save setting values

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Set, get, and save the backlight settings. In the same boot, verify getting the backlight settings. Verify that upon switching to different content and returning to the chosen source, format, and mode, the backlight remain retained. Validate using the analyzer and various video sources, video formats and picture modes. |SetBacklight(), GetBacklight(), SaveBacklight()|N|Y|Y|
|Set, get, and save the TV Dimming modes. In the same boot, verify getting  the TV Dimming modes. Verify that upon switching to different content and returning to the chosen source, format, and mode, the TV Dimming Mode remain retained. Validate using the analyzer and various video sources, video formats and picture modes.|SetTVDimmingMode(), GetTVDimmingMode(), SaveTVDimmingMode()|N|Y|Y|
|Set, get, and save the local Dimming level. In the same boot, verify getting  the local Dimming level. Verify that upon switching to different content and returning to the chosen source, format, and mode, the Local Dimming mode remain retained. Validate using the analyzer and various video sources, video formats and picture modes.|SetLocalDimmingLevel(), GetLocalDimmingLevel(), SaveLocalDimmingLevel()|N|Y|Y|
|Set, get, and save the brightness. In the same boot, verify getting  the brightness. Verify that upon switching to different content and returning to the chosen source, format, and mode, the Brightness level remain retained. Validate using the analyzer and various video sources, video formats and picture modes.|SetBrightness(), GetBrightness(), SaveBrightness()|N|Y|Y|
|Set, get, and save the contrast. In the same boot, verify getting  the contrast. Verify that upon switching to different content and returning to the chosen source, format, and mode, the Contrast level remain retained. Validate using the analyzer and various video sources, video formats and picture modes.|SetContrast(), GetContrast(), SaveContrast()|N|Y|Y|
|Set, get, and save the sharpness. In the same boot, verify getting  the sharpness. Verify that upon switching to different content and returning to the chosen source, format, and mode, the Sharpness remain retained. Validate using the analyzer and various video sources, video formats and picture modes.|SetSharpness(), GetSharpness(), SaveSharpness()|N|Y|Y|
|Set, get, and save the Saturation. In the same boot, verify getting  the Saturation. Verify that upon switching to different content and returning to the chosen source, format, and mode, the Saturation remain retained. Validate using the analyzer and various video sources, video formats and picture modes.|SetSaturation(), GetSaturation(), SaveSaturation()|N|Y|Y|
|Set, get, and save the Hue. In the same boot, verify getting  the Hue. Verify that upon switching to different content and returning to the chosen source, format, and mode, the Hue remain retained. Validate using the analyzer and various video sources, video formats and picture modes.|SetHue(), GetHue(), SaveHue()|N|Y|Y|
|Set, get, and save the Low Latency State. In the same boot, verify getting  the Low Latency State. Verify that upon switching to different content and returning to the chosen source, format, and mode, the low latency state remain retained. Validate using the analyzer and various video sources, video formats and picture modes.|SetLowLatencyState(), GetLowLatencyState()|N|Y|Y|
|Set, get, and save the Aspect Ratio. In the same boot, verify getting  the Aspect Ratio. Verify that upon switching to different content and returning to the chosen source, format, and mode, the Aspect Ratio remain retained. Validate using the analyzer and various video sources, video formats and picture modes.|SetAspectRatio(), GetAspectRatio(), SaveAspectRatio()|N|Y|Y|
|Set, get, and save the Color Temperature. In the same boot, verify getting  the Color Temperature. Verify that upon switching to different content and returning to the chosen source, format, and mode, the Color Temperature remain retained. Validate using the analyzer and various video sources, video formats and picture modes.|SetColorTemperature(), GetColorTemperature(), SaveColorTemperature()|N|Y|Y|
|Set, Get the Dynamic Gamma and in the same boot, verify getting  Dynamic Gamma. Verify that upon switching to different content and returning to the chosen source, format, and mode, the Dynamic Gamma remain retained.  Validate using the analyzer and various video sources, video formats and picture modes.|GetDynamicGamma(), SetDynamicGamma()|N|Y|Y|
|Set, Get the Dynamic Contrast and in the same boot, verify getting  Dynamic Contrast. Verify that upon switching to different content and returning to the chosen source, format, and mode, the Dynamic Contrast should not retained as it does not save in database. Validate using the analyzer and various video sources, video formats and picture modes.|SetDynamicContrast(), GetDynamicContrast()|N|Y|Y|
|Set, Save and Get the TV Dolby Vision mode and in the same boot, verify getting  TV Dolby Vision mode. Verify that upon switching to different content and returning to the chosen source, format, and mode, the Dolby Vision mode remain retained. Validate using the analyzer and various video sources, video formats and picture modes.|SetTVDolbyVisionMode(), GetTVDolbyVisionMode(), SaveTVDolbyVisionMode()|N|Y|Y|
|Set and Get the TV Picture Mode. in the same boot, verify getting  TV Picture Mode. Verify that upon switching to different content and returning to the chosen source, format, and mode, the TV Picture Mode remain retained.  Validate using the analyzer and various video sources, video formats and picture modes.|GetTVPictureMode(), SetTVPictureMode(), SaveSourcePictureMode()|N|Y|Y|
|Set and Get the color Temperature Rgain on Source and in the same boot, verify getting  color Temperature Rgain on Source when SaveOnly is enabled. Verify that upon switching to different content and returning to the chosen source, format, and mode, the Color Temperature R gain remain retained. Validate using the analyzer and various video sources and color temperatures.|SetColorTemp_Rgain_onSource(), GetColorTemp_Rgain_onSource()|N|Y|Y|
|Set and Get the color Temperature Rgain on Source and in the same boot, verify getting  color Temperature Rgain on Source when SaveOnly is disabled. Verify that upon switching to different content and returning to the chosen source, format, and mode, the Color Temperature R gain should not get retained. Validate using the analyzer and various video sources and color temperatures.|SetColorTemp_Rgain_onSource(), GetColorTemp_Rgain_onSource()|N|Y|Y|
|Set and Get the color Temperature Rgain on Source and in the same boot, verify getting  color Temperature Ggain on Source when SaveOnly is enabled. Verify that upon switching to different content and returning to the chosen source, format, and mode, the Color Temperature G gain remain retained. Validate using the analyzer and various video sources and color temperatures.|SetColorTemp_Ggain_onSource(), GetColorTemp_Ggain_onSource()|N|Y|Y|
|Set and Get the color Temperature Rgain on Source and in the same boot, verify getting  color Temperature Ggain on Source when SaveOnly is disabled. Verify that upon switching to different content and returning to the chosen source, format, and mode, the Color Temperature G gain should not get retained. Validate using the analyzer and various video sources and color temperatures.|SetColorTemp_Ggain_onSource(), GetColorTemp_Ggain_onSource()|N|Y|Y|
|Set and Get the color Temperature Rgain on Source and in the same boot, verify getting  color Temperature Bgain on Source when SaveOnly is enabled. Verify that upon switching to different content and returning to the chosen source, format, and mode, the Color Temperature B gain remain retained. Validate using the analyzer and various video sources and color temperatures.|SetColorTemp_Bgain_onSource(), GetColorTemp_Bgain_onSource()|N|Y|Y|
|Set and Get the color Temperature Rgain on Source and in the same boot, verify getting  color Temperature Bgain on Source when SaveOnly is disabled. Verify that upon switching to different content and returning to the chosen source, format, and mode, the Color Temperature B gain should not get retained. Validate using the analyzer and various video sources and color temperatures.|SetColorTemp_Bgain_onSource(), GetColorTemp_Bgain_onSource()|N|Y|Y|
|Set and Get the color Temperature R post offset on Source and in the same boot, verify getting  color Temperature R post offset on Source when SaveOnly is enabled. Verify that upon switching to different content and returning to the chosen source, format, and mode, the color Temperature R post offset on Source remain retained. Validate using the analyzer and various video sources and color temperatures.|SetColorTemp_R_post_offset_onSource(), GetColorTemp_R_post_offset_onSource()|N|Y|Y|
|Set and Get the color Temperature R post offset on Source and in the same boot, verify getting  color Temperature R post offset on Source when SaveOnly is disabled. Verify that upon switching to different content and returning to the chosen source, format, and mode, the color Temperature R post offset on Source should not retained. Validate using the analyzer and various video sources  and color temperatures|SetColorTemp_R_post_offset_onSource(), GetColorTemp_R_post_offset_onSource()|N|Y|Y|
|Set and Get the color Temperature R post offset on Source and in the same boot, verify getting  color Temperature G post offset on Source when SaveOnly is enabled. Verify that upon switching to different content and returning to the chosen source, format, and mode, the color Temperature G post offset on Source remain retained. Validate using the analyzer and various video sources and color temperatures|SetColorTemp_G_post_offset_onSource(), GetColorTemp_G_post_offset_onSource()|N|Y|Y|
|Set and Get the color Temperature R post offset on Source and in the same boot, verify getting  color Temperature G post offset on Source when SaveOnly is disabled. Verify that upon switching to different content and returning to the chosen source, format, and mode, the color Temperature G post offset on Source should not retained. Validate using the analyzer and various video sources and color temperatures|SetColorTemp_G_post_offset_onSource(), GetColorTemp_G_post_offset_onSource()|N|Y|Y|
|Set and Get the color Temperature R post offset on Source and in the same boot, verify getting  color Temperature B post offset on Source when SaveOnly is enabled. Verify that upon switching to different content and returning to the chosen source, format, and mode, the color Temperature B post offset on Source remain retained. Validate using the analyzer and various video sources and color Temperatures.|SetColorTemp_B_post_offset_onSource(), GetColorTemp_B_post_offset_onSource()|N|Y|Y|
|Set and Get the color Temperature R post offset on Source and in the same boot, verify getting  color Temperature B post offset on Source when SaveOnly is disabled. Verify that upon switching to different content and returning to the chosen source, format, and mode, the color Temperature B post offset on Source should not retained. Validate using the analyzer and various video sources and color Temperatures.|SetColorTemp_B_post_offset_onSource(), GetColorTemp_B_post_offset_onSource()|N|Y|Y|
|Set, Save and Get the Gamma Table and in the same boot, verify getting  Gamma Table. Verify that upon switching to different content and returning to the chosen specific color temperature and check the gamma calibrated values get retained. Validate using the analyzer and various video sources, video formats and picture modes.|SetGammaTable(), GetGammaTable(), SaveGammaTable()|N|Y|Y|
|Set and Get the Component Saturation and in the same boot, verify getting  Component Saturation. Verify that upon switching to different content and returning to the chosen source, format, and mode and check the compontent saturation values get retained. Validate using the analyzer and various video sources, video formats and picture modes.|SetCurrentComponentSaturation(), GetCurrentComponentSaturation()|N|Y|Y|
|Set and Get the Component Saturation and in the same boot, verify getting  Component Hue. Verify that upon switching to different content and returning to the chosen source, format, and mode and check the compontent Hue values get retained. Validate using the analyzer and various video sources, video formats and picture modes.|SetCurrentComponentHue(), GetCurrentComponentHue()|N|Y|Y|
|Set and Get the Component Saturation and in the same boot, verify getting  Component Luma. Verify that upon switching to different content and returning to the chosen source, format, and mode and check the compontent Luma values get retained. Validate using the analyzer and various video sources, video formats and picture modes.|SetCurrentComponentLuma(), GetCurrentComponentLuma()|N|Y|Y|
|Set, Save and Get the CMS State and in the same boot, verify getting  CMS State. Verify that upon switching to different content and returning to the chosen source, format, and mode, and check the CMS state values get retained. Validate using the analyzer and various video sources, video formats and picture modes.|SetCMSState(), GetCMSState(), SaveCMS()|N|Y|Y|

### Test Startup Requirement - Test the save setting values

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - Test the save setting values

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - Test the save setting values

- Control plane dynamically changes the video sources, video formats and picture modes.

## Get Short Circuit Status

|Description|HAL APIs|L2|L3|Control Plane requirements|
|-----------|--------|--|--|--------------------------|
|Verifies the functionality of retrieving the short circuit status of the adjacent zones. It ensures that the returned status indicates whether any short is detected.|GetLdimZoneShortCircuitStatus()|Y|N|N|

### Test Startup Requirement - Get Short Circuit Status

[Test Start up Requirement](#test-start-up-requirement)

### Emulator Requirement - Get Open Circuit Status

[Emulator Requirement](#emulator-requirement)

### Control Plane Requirement - Get Short Circuit Status

None
