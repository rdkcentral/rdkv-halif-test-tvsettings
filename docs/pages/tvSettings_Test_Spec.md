# TVSettings Test Document

## Version History

| Date(DD/MM/YY) | Comment       | Version |
| -------------- | ------------- | ------- |
| 19/03/2024     | First Release | 1.0.0   |

## Table of Contents

- [Acronyms, Terms and Abbreviations](#acronyms-terms-and-abbreviations)
- [References](#references)
- [Introduction](#introduction)
- [Module Description](#module-description)
- [Testing Scope](#testing-scope)

## Acronyms, Terms and Abbreviations

- `HAL`   - Hardware Abstraction layer
- `SoC`   - System On a Chip
- `EDID`  - Extended Display Identification
- `API`   - Application programming interface
- `CPU`   - Central processing unit
- `RDK`   - Reference Design Kit

## References

## Introduction

This document provides an overview of the testing requirements for the tvSettings module. It outlines the scope of testing, objectives, testing levels and approaches, specific test requirements, emulator requirements, control plane requirements and expected deliverables.

Interface of the test is available in this link -  [https://github.com/rdkcentral/rdkv-halif-tvsettings/blob/main/include/tvSettings.h](https://github.com/rdkcentral/rdkv-halif-tvsettings/blob/main/include/tvSettings.h)

## Module Description

High level overview:

- TV settings give you different ways to get information and change things like picture quality, dimming, and auto backlight.
- It helps communicate with the SoC to adjust TV settings. After that, it sends this information to the person who requested it.
- It applies only to the Sink devices.

## Testing Scope

|#|Test Functionality|Test Description|
|-|------------------|----------------|
|1|Callback Mechanisms for Modifying Video Formats|The test registers the video format callback, letting the system detect any changes in the primary video's format|
|2|Callback Mechanisms for Modifying Video Resolutions|The test registers the video resolution callback, letting the system detect any changes in the video resolution|
|3|Callback Mechanisms for Modifying Video Content| The test regiters the video content callback, letting the system detect any changes in the video Flimcontent|
|4|Callback Mechanisms for Modifying Video framerate| The test registers the video framerate callback, letting the system detect any changes in the video frame rate|
|5|Get TV Supported Video Formats|The test aims to provide the all supported video formats|
|6|Get Current Video Format|The test aims to provide the current video format of the primary video|
|7|Get Current Video Resolution|The test aims to provide the current video resolution of the primary video|
|8|Get Current Video FrameRate|The test aims to provide the video frame rate of the current primary video|
|9|Get Current Video Source|The test aims to provide the video source selected for the primary video|
|10|Get TV supported video sources|The test aims to provide the supported video sources of the systems and its count|
|11|Test on Back light - Set, Get and Save|The test aims to Set and Get the current backlight value for the primary video source selected, primary video format played and picture mode selected.|
|12|Test on Back light Fade - Set, Get and Save|This test verifies the functionality of initiating backlight fading between two different backlight values over a specified duration. It ensures that the fading process starts and behaves as expected.|
|13|Get supported Back light modes|This test verifies the functionality of retrieving all supported backlight modes for the TV. It ensures that the returned modes are valid and consistent.|
|14|Test on current Back light mode - Set,Get and Save|This test verifies the functionality of retrieving the current backlight mode. It ensures that the returned mode is valid and reflects the current state accurately.|
|15|Gets TV Supported Dimming Modes |This test verifies the functionality of retrieving all supported backlight dimming modes for the TV. It ensures that the returned modes are valid and consistent.|
|16|Test on TV Dimming Mode - Get,Set and Save|This test verifies the functionality of setting the TV backlight dimming mode. It ensures that the specified mode is correctly applied and reflects the desired state.|
|17|Test on Local Dimming Level - Get,Set and Save|This test verifies the functionality of setting the local dimming level. It ensures that the specified dimming level is correctly applied for the given parameters.|
|18|Test on Brightness - Set,Get and Save|This test verifies the functionality of setting the brightness value. It ensures that the specified brightness value is correctly applied for the given parameters.|
|19|Test on Contrast - Set, Get and Save|This test verifies the functionality of setting the contrast value. It ensures that the specified contrast value is correctly applied for the given parameters.|
|20|Test on Sharpness - Set,Get and Save|This test verifies the functionality of setting the sharpness value. It ensures that the specified sharpness value is correctly applied for the given parameters.|
|21|Test on Saturation - Set,Get and Save|This test verifies the functionality of setting the saturation value to driver registers. It ensures that the new saturation value is updated in the hardware and applied for the current primary video source, video format, and picture mode.|
|22|Test on Hue - Set,Get and Save|This test verifies the functionality of setting the hue value to driver registers. It ensures that the new hue value is updated in the hardware and applied for the current primary video source, video format, and picture mode.|
|23|Test on Color Temperature - Set, Get and Save|This test verifies the functionality of setting the color temperature value to driver registers. It ensures that the new color temperature value is updated in the hardware and applied for the current primary video source, video format, and picture mode.|
|24|Test on Aspect Ratio - Set, Get and Save|This test verifies the functionality of setting the aspect ratio value to driver registers. It ensures that the new aspect ratio value is updated in the hardware and applied for the current primary video source, video format, and picture mode.|
|25|Test on Low Latency State - Set,Get and Save|This test verifies the functionality of setting the low latency state value to driver registers. It ensures that the new low latency state value is updated in the hardware and applied for the current primary video source, video format, and picture mode.|
|26|Test on Dynamic Contrast - Set, Get and Save|This test verifies the functionality of setting the dynamic contrast mode. It ensures that the new dynamic contrast mode is applied and affects the PQ module accordingly.|
|27|Test on Dynamic Gamma - Set,Get and Save|This test verifies the functionality of retrieving the current dynamic gamma value. It ensures that the returned value is accurate and reflects the current state of dynamic gamma.|
|28|Get TV Supported Dolby Vision Modes|This test verifies the functionality of retrieving the supported Dolby Vision modes. It ensures that the returned list contains accurate information about the available DV modes and their count. |
|29|Test on TV Dolby Vision Mode - Set,Get and Save|This test verifies the functionality of setting the Dolby Vision mode for the current primary video source, video format, and picture mode. It ensures that the mode is successfully updated and saved in the override picture profile database.|
|30|Get TV Supported Picture Modes|This test verifies the functionality of retrieving the list of supported picture modes and their count. It ensures that the returned list is accurate and contains valid picture modes.|
|31|Test on TV Picture Mode - Get,Set and Save|This test verifies the functionality of retrieving the current selected picture mode for the current primary video source and video format. It ensures that the returned mode is accurate and reflects the current selection.|
|32|Test on Color Temperature Rgain onSource - Get and Set|This test verifies the functionality of setting or saving the Rgain value for a specific color temperature and video source. It ensures that the value is successfully applied or saved for future use.|
|33|Test on Color Temp Ggain onSource - Get and Set|This test verifies the functionality of setting or saving the Ggain value for a specific color temperature and video source. It ensures that the value is successfully applied or saved for future use.|
|34|Test on Color Temp Bgain onSource - Get and Set|This test verifies the functionality of setting or saving the Bgain value for a specific color temperature and video source. It ensures that the value is successfully applied or saved for future use.|
|35|Test on Color Temp R post offset onSource - Get and Set|This test verifies the functionality of setting or saving the R post offset value for a specific color temperature and video source. It ensures that the value is successfully applied or saved for future use.|
|36|Test on Color Temp G post offset onSource - Get and Set|This test verifies the functionality of setting or saving the G post offset value for a specific color temperature and video source. It ensures that the value is successfully applied or saved for future use.|
|37|Test on Color Temp B post offset onSource - Get and Set|This test verifies the functionality of setting or saving the B post offset value for a specific color temperature and video source. It ensures that the value is successfully applied or saved for future use.|
|38|Enable WB Calibration Mode|This test verifies the functionality of enabling or disabling white balance calibration mode. It ensures that the mode is successfully toggled and that the system behaves accordingly.|
|39|Get Current WB Calibration Mode|This test verifies the functionality of retrieving the current status of white balance calibration mode. It ensures that the returned status is accurate and reflects the current state.|
|40|Set Gamma Table|This test verifies the functionality of setting the gamma calibrated values to the gamma hardware for the current selected color temperature. It ensures that the values are successfully applied and do not override other settings in the picture profile database. |
|41|Get Default Gamma Table|This test verifies the functionality of retrieving the default gamma calibrated values for the primary colors for a specific color temperature from the picture profile database. It ensures that the returned values are within the valid range and accurate.|
|42|Test on Gamma Table - Get and Save|This test verifies the functionality of retrieving the current gamma calibrated values for the primary colors for the current selected color temperature. It ensures that the returned values are within the valid range and accurate.|
|43|Dv Tmax Value - Get,Set and Save|This test verifies the functionality of setting the Dolby Vision TMAX parameter in the Dolby Vision core. It ensures that the provided value is valid and can be applied successfully.|
|44|Get Supported Component Color|This test verifies the functionality of retrieving the supported component colors. It ensures that the returned value represents the bitwise OR-ed combination of all supported colors.|
|45|Test on Current Component Saturation - Set and Get|This test verifies the functionality of setting the current component saturation value. It ensures that the provided saturation value is valid and can be applied successfully.|
|46|Test on Current Component Hue - Set and Get|This test verifies the functionality of setting the current component hue value. It ensures that the provided hue value is valid and can be applied successfully.|
|47|Test on Current Component Luma - Set and Get|This test verifies the functionality of setting the current component luma value. It ensures that the provided luma value is valid and can be applied successfully.|
|48|Save CMS|This test verifies the functionality of saving the CMS value in the picture profile database for specific settings. It ensures that the CMS values are stored correctly and can be applied automatically when needed.|
|49|Test on CMS State - Get & Set|This test verifies the functionality of setting the CMS (Color Management System) state. It ensures that the CMS state can be successfully enabled or disabled as intended.|
|50|Get Default PQ Params|This test verifies the functionality of retrieving the default PQ (Picture Quality) parameters for a given picture mode, primary video source, and video format. It ensures that the default values are retrieved correctly.|
|51|Get PQ Params|This test verifies the functionality of retrieving the override PQ parameters for a given picture mode, primary video source, and video format. It ensures that the override values are retrieved correctly.|
|52|Get Max Gain Value|This test verifies the functionality of retrieving the maximum gamma/white balance gain value capable for the platform. It ensures that the returned value is within the valid range and accurately reflects the maximum gain value.|
|53|Enable Gamma Mode|This test verifies the functionality of enabling or disabling the gamma mode. It ensures that the gamma module can be successfully enabled or disabled as intended.|
|54|Set Gamma Pattern|This test verifies the functionality of setting the gamma pattern. It ensures that the primary color level can be set accurately and displayed as intended on the screen.|
|55|Get TV Gamma Target|This test verifies the functionality of retrieving the target x and y coordinates for the panel gamma based on a given color temperature. It ensures that the returned coordinates are accurate and reflect the desired color temperature.|
|56|Set Gamma Pattern Mode|This test verifies the functionality of enabling or disabling the gamma pattern mode. It ensures that the gamma pattern mode can be successfully enabled or disabled as intended.|
|57|Test on RGB Pattern - Set and Get|This test verifies the functionality of setting the RGB pattern. It ensures that the primary color levels can be set accurately and displayed as intended on the screen.|
|58|Test on Gray Pattern - Set and Get|This test verifies the functionality of setting the gray pattern. It ensures that the gray level can be set accurately and displayed as intended on the screen.|
|59|Get Open Circuit Status|This test verifies the functionality of retrieving the current open circuit status of the backlight hardware. It ensures that the returned status indicates whether any LED fault is detected.|
|60|Enable LDIM Pixel Compensation|This test verifies the functionality of enabling or disabling the pixel compensation block for LDIM (Local Dimming). It ensures that the pixel compensation block can be successfully enabled or disabled as intended.|
|61|Enable LDIM|This test verifies the functionality of enabling or disabling the local dimming module. It ensures that the local dimming module can be successfully enabled or disabled as intended.|
|62|Start LDIM Sequence Test|This test verifies the functionality of starting the local dimming sequence test. It ensures that the test sequence is executed correctly, turning on each LDIM zone for the specified duration.|
|63|Set Backlight Test Mode|This test verifies the functionality of setting the backlight test mode. It ensures that the backlight hardware can be configured correctly for calibration purposes based on the specified test mode.|
|64|Enable White Balance|This test verifies the functionality of enabling or disabling the white balance module. It ensures that the white balance module can be successfully enabled or disabled as intended.|
|65|Enable Dynamic Contrast|This test verifies the functionality of enabling or disabling the dynamic contrast module. It ensures that the dynamic contrast module can be successfully enabled or disabled as intended.|
|66|Enable Local Contrast|This test verifies the functionality of enabling or disabling the local contrast module. It ensures that the local contr
-----------

## Callback Mechanisms for Modifying Video Formats

|Description|L2|L3|
|-----------|--|--|
|Verify that the callback gets triggered when modifying the video formats.|N|Y|

### Test Startup Requirement - 

None

### Emulator Requirement - 

The emulator boots with the configured set of video formats.

### Control Plane Requirement - 

Control Plane handles the change in video formats.

## Callback Mechanisms for Modifying Video Resolutions

|Description|L2|L3|
|-----------|--|--|
|Verify that the callback gets triggered when modifying the video Resolution.|N|Y|              

### Test Startup Requirement - Callback Mechanisms for Modifying Video Resolutions

None

### Emulator Requirement - Callback Mechanisms for Modifying Video Resolutions

The emulator boots with the configured set of video Resolutions.

### Control Plane Requirement - Callback Mechanisms for Modifying Video Resolutions

Control Plane handles the change in video resolution.

## Callback Mechanisms for Modifying Video Content

|Description|L2|L3|
|-----------|--|--|
|Verify that the callback gets triggered when modifying to the Filmmaker mode change event|N|Y|

### Test Startup Requirement - Callback Mechanisms for Modifying Video Content

None

### Emulator Requirement - Callback Mechanisms for Modifying Video Content

The emulator should boot with the configuration of Filmmaker mode content_type detecting values (0x01 and subtype 0x00).

### Control Plane Requirement - Callback Mechanisms for Modifying Video Content

Control Plane handles the change in Filmmaker mode.

## Callback Mechanisms for Modifying Video framerate.

|Description|L2|L3|Control Plane Requirements|
|-----------|--|--|--------------------------|
|Verify that the callback gets triggered when modifying the video framerate|N|Y|

### Test Startup Requirement - Callback Mechanisms for Modifying Video framerate.

None

### Emulator Requirement - Callback Mechanisms for Modifying Video framerate.

The emulator should boot with the configuration of video frame rates.

### Control Plane Requirement - Callback Mechanisms for Modifying Video framerate.

Control Plane handles the change in video frame rate.


## Get TV supported video Formats

|Description|L2|L3|
|-----------|--|--|
|Verify that the test provides the TV supportted Video formats|Y|N|

### Test Startup Requirement - Get TV supported video Formats

None

### Emulator Requirement - Get TV supported video Formats

None

### Control Plane Requirement - Get TV supported video Formats

None

## Get Current Video Format

|Description|L2|L3|
|-----------|--|--|
|Verify getting the video format when there is no video playback. Default is VIDEO_FORMAT_SDR|Y|N|
|Verify getting the video format when there is video playback. |N|Y|

### Test Startup Requirement - Get Current Video Format

None

### Emulator Requirement - Get Current Video Format

None

### Control Plane Requirement - Get Current Video Format

None

## Get Current Video Resolution

|Description|L2|L3|
|-----------|--|--|
|Verify the current video resolution of the primary video.|N|Y|

### Test Startup Requirement - Get Current Video Resolution

Test should start with the Video analyzer that detects the change of the video resolution.

### Emulator Requirement - Get Current Video Resolution

Emulator boots with the set of configured video Resolutions.

### Control Plane Requirement - Get Current Video Resolution

Control Plane handles to change the video resolution.

## Get Current Video FrameRate

|Description|L2|L3|
|-----------|--|--|
|Verify the video frame rate of the current primary video.|N|Y|

### Test Startup Requirement - Get Current Video FrameRate

Test should start with the Video analyzer that detects the change of the video Format.

### Emulator Requirement - Get Current Video FrameRate

Emulator boots with the set of configured video Formats.

### Control Plane Requirement - Get Current Video FrameRate

Control plane detects the video format with the help of video analyzer device.

## Get Current Video Source

|Description|L2|L3|
|-----------|--|--|
|Verify when there is no video source device is connected. Default is VIDEO_SOURCE_IP|Y|Y|
|Verify the video source selected for the current primary video.|N|Y|

### Test Startup Requirement - Get Current Video Source

Source device should be connected to test the video source.

### Emulator Requirement - Get Current Video Source

Emulator boots with the configurations of video source.

### Control Plane Requirement - Get Current Video Source

None

## Get TV supported video sources

|Description|L2|L3|
|-----------|--|--|
|Verify the TV supported Video sources|Y|Y|

### Test Startup Requirement - Get TV supported video sources

None

### Emulator Requirement - Get TV supported video sources

Emulator boots with the set of configured video sources

### Control Plane Requirement - Get TV supported video sources

None

## Test on Back light - Get, Set and Save

|Description|L2|L3|
|-----------|--|--|
|Verifies by getting the default backlight value|Y|N|
|Sets the backlight value between the range of ( 0 - 100 )|N|Y|
|Gets the backlight value after setting the backlight. Ensure it received the correct back light value which set in previous call.|N|Y|
|Saves the backlight value after setting the backlight.|N|Y|
|Gets the backlight value after setting the backlight. Ensure it received the correct back light value which set in previous call.|N|Y|

### Test Startup Requirement - Get Back light

None

### Emulator Requirement - Get Back light

Emulator boots with the set of configured back light values.

### Control Plane Requirement - Get Back light

None

## Test on Back light Fade - Get, Set and Save

| Description|L2|L3|
|------------|--|--|
| verifies by getting the default back light fade value(1-100)|Y|N|
| Sets the backlight fade between the range of (0 - 100)|N|Y|
| Gets the backlight fade value after setting. Ensure it received the correct value set previously.|N|Y|
| Saves the backlight fade value after setting.|N|Y|

### Test Startup Requirement - Set Back light Fade

None

### Emulator Requirement - Set Back light Fade

None

### Control Plane Requirement - Set Back light Fade

None

## Get supported Back light modes

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of retrieving all supported backlight modes for the TV. It ensures that the returned modes are valid and consistent.|N|Y|

### Test Startup Requirement - Get supported Back light modes

None

### Emulator Requirement - Get supported Back light modes

None

### Control Plane Requirement - Get supported Back light modes

None

## Test on current Back light mode - Get and Set 

| Description| L2 | L3 |
|------------|----|----|
| Sets the backlight mode|N|Y|
| Gets the backlight mode value after setting. Ensure it received the correct value set previously.|N|Y|

### Test Startup Requirement - Get current Back light mode

None

### Emulator Requirement - Get current Back light mode

None

### Control Plane Requirement - Get current Back light mode

None

## Get TV Supported Dimming Modes

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of retrieving all supported backlight dimming modes for the TV. It ensures that the returned modes are valid and consistent.|N|Y|

### Test Startup Requirement - Get TV Supported Dimming Modes

None

### Emulator Requirement - Get TV Supported Dimming Modes

None

### Control Plane Requirement - Get TV Supported Dimming Modes

None

## Test on TV Dimming Mode - Get, Set and Save

| Description|L2|L3|
|------------|--|--|
| Sets the TV dimming mode|N|Y|
| Gets the TV dimming mode value after setting. Ensure it received the correct value set previously.( "local", "fixed", "global" )|N|Y |
| Saves the TV dimming mode value after setting.|N|Y|  
| Gets the TV dimming mode value after setting. Ensure it received the correct value set previously.( "local", "fixed", "global" )|N|Y |

### Test Startup Requirement - Save TV Dimming Mode

None

### Emulator Requirement - Save TV Dimming Mode

None

### Control Plane Requirement - Save TV Dimming Mode

None

## Test on Local Dimming Level - Get, Set and Save

|Description|L2|L3|
|-----------|--|--|
|Sets the local dimming mode|N|Y|
|Gets the local dimming mode value after setting. Ensure it received the correct value set previously.|N|Y|
|Saves the local dimming mode value after setting.|N|Y|
|Gets the local dimming mode value after setting. Ensure it received the correct value set previously.|N|Y|

### Test Startup Requirement - Set Local Dimming Level

None

### Emulator Requirement - Set Local Dimming Level

None

### Control Plane Requirement - Set Local Dimming Level

None

## Test on Brightness - Get, Set and Save

| Description|L2|L3|
|------------|--|--|
|Verify by getting the default Brightness value(0-100)|Y|N|
|Sets the brightness between the range of (0 - 100)| N  | Y  |
|Gets the brightness value after setting. Ensure it received the correct value set previously.|N|Y|
|Saves the brightness value after setting.|N|Y|
|Gets the brightness value after setting. Ensure it received the correct value set previously.|N|Y|

### Test Startup Requirement - Set Brightness

None

### Emulator Requirement - Set Brightness

None

### Control Plane Requirement - Set Brightness

None

## Test on Contrast - Get ,Set and Save

| Description|L2|L3|
|------------|--|--|
|Verify by getting the default Contrast values(0-100)|Y|N|
|Sets the contrast between the range of (0 - 100)|N|Y|
|Gets the contrast value after setting. Ensure it received the correct value set previously.|N|Y|
|Saves the contrast value after setting.|N|Y|
|Gets the contrast value after setting. Ensure it received the correct value set previously.|N|Y|

### Test Startup Requirement - Set Contrast

None

### Emulator Requirement - Set Contrast

None

### Control Plane Requirement - Set Contrast

None

## Test on Sharpness - Get, Set and Save

|Description|L2|L3|
|-----------|--|--|
|Verify by getting the default Sharpness values(0-100)|Y|N|
|Sets the sharpness between the range of (0 - 100)|N|Y|
|Gets the sharpness value after setting. Ensure it received the correct value set previously.|N|Y|
|Saves the sharpness value after setting.|N|Y|
|Gets the sharpness value after setting. Ensure it received the correct value set previously.|N|Y|

### Test Startup Requirement - Set Sharpness

None

### Emulator Requirement - Set Sharpness

None

### Control Plane Requirement - Set Sharpness

None

## Test on Saturation - Get, Set and Save

|Description|L2|L3|
|-----------|--|--|
|Verify by getting the default Saturation values(0-100)|Y|N|
|Sets the saturation between the range of (0 - 100)|N|Y|
|Gets the saturation value after setting. Ensure it received the correct value set previously.|N|Y|
|Saves the saturation value after setting.|N|Y|
|Gets the saturation value after setting. Ensure it received the correct value set previously.|N|Y|

### Test Startup Requirement - Set Saturation

None

### Emulator Requirement - Set Saturation

None

### Control Plane Requirement - Set Saturation

None

## Test on Hue - Get, Set and Save

|Description|L2|L3|
|-----------|--|--|
|Verify by getting the default Hue value ( 0-100 )|Y|N|
|Sets the hue between the range of (0 - 100)|N|Y|
|Gets the hue value after setting. Ensure it received the correct value set previously.|N|Y|
|Saves the hue value after setting.|N|Y|
|Gets the hue value after setting. Ensure it received the correct value set previously.|N|Y|

### Test Startup Requirement - Set Hue

None

### Emulator Requirement - Set Hue

None

### Control Plane Requirement - Set Hue

None

## Test on Color Temperature - Get, Set and Save

|Description|L2|L3|
|-----------|--|--|
|Sets the color temperature|N|Y|
|Gets the color temperature value after setting. Ensure it received the correct value set previously.|N|Y|
|Saves the color temperature value after setting.|N|Y|

### Test Startup Requirement - Set Color Temperature

None

### Emulator Requirement - Set Color Temperature

None

### Control Plane Requirement - Set Color Temperature

None

## Test on Aspect Ratio  - Get, Set and Save

|Description|L2|L3|
|-----------|--|--|
|Sets the aspect ratio|N|Y|
|Gets the aspect ratio value after setting. Ensure it received the correct value set previously.|N|Y|
|Saves the aspect ratio value after setting.|N|Y|

### Test Startup Requirement - Set Aspect Ratio

None

### Emulator Requirement - Set Aspect Ratio

None

### Control Plane Requirement - Set Aspect Ratio

None

## Set Low Latency State

|Description|L2|L3|
|-----------|--|--|
|Sets the low latency state|N|Y|
|Gets the low latency state value after setting. Ensure it received the correct value set previously.|N|Y|
|Saves the low latency state value after setting.|N|Y|

### Test Startup Requirement - Set Low Latency State

None

### Emulator Requirement - Set Low Latency State

None

### Control Plane Requirement - Set Low Latency State

None

## Test on  Dynamic Contrast - Get and Save

|Description|L2|L3|
|-----------|--|--|
|Sets the dynamic contrast|N|Y|
|Gets the dynamic contrast value after setting. Ensure it received the correct value set previously.|N|Y|

### Test Startup Requirement - Set Dynamic Contrast

None

### Emulator Requirement - Set Dynamic Contrast

None

### Control Plane Requirement - Set Dynamic Contrast

None

## Test on Dynamic Gamma - Get and Set

|Description|L2|L3|
|-----------|--|--|
|Sets the dynamic gamma|N|Y|
|Gets the dynamic gamma value after setting. Ensure it received the correct value set previously.|N|Y|
|Saves the dynamic gamma value after setting.|N|Y|

### Test Startup Requirement - Set Dynamic Gamma

None

### Emulator Requirement - Set Dynamic Gamma

None

### Control Plane Requirement - Set Dynamic Gamma

None

## Get TV Supported Dolby Vision Modes

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of retrieving the supported Dolby Vision modes. It ensures that the returned list contains accurate information about the available DV modes and their count.|N|Y|

### Test Startup Requirement - Get TV Supported Dolby Vision Modes

None

### Emulator Requirement - Get TV Supported Dolby Vision Modes

None

### Control Plane Requirement - Get TV Supported Dolby Vision Modes

None

## Test on TV Dolby Vision Mode - Set, Get and Save

|Description|L2|L3|
|-----------|--|--|
|Sets the Dolby Vision mode|N|Y|
|Gets the Dolby Vision mode value after setting. Ensure it received the correct value set previously.|N|Y|
|Saves the Dolby Vision mode value after setting.|N|Y|

### Test Startup Requirement - Set TV Dolby Vision Mode

None

### Emulator Requirement - Set TV Dolby Vision Mode

None

### Control Plane Requirement - Set TV Dolby Vision Mode

None

## Get TV Supported Picture Modes

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of retrieving the list of supported picture modes and their count. It ensures that the returned list is accurate and contains valid picture modes.|N|Y|

### Test Startup Requirement - Get TV Supported Picture Modes

None

### Emulator Requirement - Get TV Supported Picture Modes

None

### Control Plane Requirement - Get TV Supported Picture Modes

None

## Get TV Picture Mode

|Description|L2|L3|
|-----------|--|--|
|Sets the picture mode|N|Y|
|Gets the picture mode value after setting. Ensure it received the correct value set previously.|N|Y|

### Test Startup Requirement - Get TV Picture Mode

None

### Emulator Requirement - Get TV Picture Mode

None

### Control Plane Requirement - Get TV Picture Mode

None


## Save Source Picture Mode

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of saving the picture mode in the picture profile database for the specific primary video format type and primary video source. It ensures that the saved mode is applied automatically when the specified conditions are met.|N|Y|

### Test Startup Requirement - Save Source Picture Mode

None

### Emulator Requirement - Save Source Picture Mode

None

### Control Plane Requirement - Save Source Picture Mode

None

## Set Color Temperature Rgain onSource

|Description|L2|L3|
|-----------|--|--|
|Sets the temperature R gain on source|N|Y|
|Gets the temperature R gain on source value after setting. Ensure it received the correct value set previously.|N|Y|

### Test Startup Requirement - Set Color Temperature Rgain onSource

None

### Emulator Requirement - Set Color Temperature Rgain onSource

None

### Control Plane Requirement - Set Color Temperature Rgain onSource

None

## Get Color Temp Ggain onSource

|Description|L2|L3|
|-----------|--|--|
|Sets the temperature G gain on source|N|Y|
|Gets the temperature G gain on source value after setting. Ensure it received the correct value set previously.|N|Y|

### Test Startup Requirement - Get Color Temp Ggain onSource

None

### Emulator Requirement - Get Color Temp Ggain onSource

None

### Control Plane Requirement - Get Color Temp Ggain onSource

None

## Get Color Temp zgain onSource

|Description|L2|L3|
|-----------|--|--|
|Sets the temperature B gain on source|N|Y|
|Gets the temperature B gain on source value after setting. Ensure it received the correct value set previously.|N|Y|

### Test Startup Requirement - Get Color Temp zgain onSource

None

### Emulator Requirement - Get Color Temp zgain onSource

None

### Control Plane Requirement - Get Color Temp zgain onSource

None

## Set Color Temp R post offset onSource

|Description|L2|L3|
|-----------|--|--|
|Sets the temperature R post offset on source|N|Y|
|Gets the temperature R post offset on source value after setting. Ensure it received the correct value set previously.|N|Y|

### Test Startup Requirement - Set Color Temp R post offset onSource

None

### Emulator Requirement - Set Color Temp R post offset onSource

None

### Control Plane Requirement - Set Color Temp R post offset onSource

None

## Set Color Temp G post offset onSource

|Description|L2|L3|
|-----------|--|--|
|Sets the temperature G post offset on source|N|Y|
|Gets the temperature G post offset on source value after setting. Ensure it received the correct value set previously.|N|Y|
|Saves the temperature G post offset on source value after setting.|N|Y|

### Test Startup Requirement - Set Color Temp G post offset onSource

None

### Emulator Requirement - Set Color Temp G post offset onSource

None

### Control Plane Requirement - Set Color Temp G post offset onSource

None

## Set Color Temp B post offset onSource

|Description|L2|L3|
|-----------|--|--|
|Sets the temperature B post offset on source|N|Y|
|Gets the temperature B post offset on source value after setting. Ensure it received the correct value set previously.| N  | Y  |

### Test Startup Requirement - Set Color Temp B post offset onSource

None

### Emulator Requirement - Set Color Temp B post offset onSource

None

### Control Plane Requirement - Set Color Temp B post offset onSource

None

## Enable WB Calibration Mode

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of enabling or disabling white balance calibration mode. It ensures that the mode is successfully toggled and that the system behaves accordingly.|N|Y|

### Test Startup Requirement - Enable WB Calibration Mode

None

### Emulator Requirement - Enable WB Calibration Mode

None

### Control Plane Requirement - Enable WB Calibration Mode

None

## Get Current WB Calibration Mode

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of retrieving the current status of white balance calibration mode. It ensures that the returned status is accurate and reflects the current state.|N|Y|

### Test Startup Requirement - Get Current WB Calibration Mode

None

### Emulator Requirement - Get Current WB Calibration Mode

None

### Control Plane Requirement - Get Current WB Calibration Mode

None

## Set Gamma Table

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of setting the gamma calibrated values to the gamma hardware for the current selected color temperature. It ensures that the values are successfully applied and do not override other settings in the picture profile database.|N|Y|

### Test Startup Requirement - Set Gamma Table

None

### Emulator Requirement - Set Gamma Table

None

### Control Plane Requirement - Set Gamma Table

None

## Get Default Gamma Table

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of retrieving the default gamma calibrated values for the primary colors for a specific color temperature from the picture profile database. It ensures that the returned values are within the valid range and accurate.|N|Y|

### Test Startup Requirement - Get Default Gamma Table

None

### Emulator Requirement - Get Default Gamma Table

None

### Control Plane Requirement - Get Default Gamma Table

None

## Get Gamma Table

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of retrieving the current gamma calibrated values for the primary colors for the current selected color temperature. It ensures that the returned values are within the valid range and accurate.|N|Y|

### Test Startup Requirement - Get Gamma Table

None

### Emulator Requirement - Get Gamma Table

None

### Control Plane Requirement - Get Gamma Table

None

## Save Gamma Table

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of saving the gamma calibrated values in the picture profile database for a specific color temperature. It ensures that the values are stored correctly and can be applied automatically when needed.|N|Y|

### Test Startup Requirement - Save Gamma Table

None

### Emulator Requirement - Save Gamma Table

None

### Control Plane Requirement - Save Gamma Table

None

## Set Dv Tmax Value

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of setting the Dolby Vision TMAX parameter in the Dolby Vision core. It ensures that the provided value is valid and can be applied successfully.|N|Y|

### Test Startup Requirement - Set Dv Tmax Value

None

### Emulator Requirement - Set Dv Tmax Value

None

### Control Plane Requirement - Set Dv Tmax Value

None

## Get Dv Tmax Value

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of retrieving the current Dolby Vision TMAX parameter from the Dolby Vision core. It ensures that the returned value is accurate and reflects the current state.|N|Y|

### Test Startup Requirement - Get Dv Tmax Value

None

### Emulator Requirement - Get Dv Tmax Value

None

### Control Plane Requirement - Get Dv Tmax Value

None

## Save Dv Tmax Value

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of saving the Dolby Vision TMAX parameter in the picture profile database for a specified LDIM state level. It ensures that the value is stored correctly and can be applied when needed.|N|Y|

### Test Startup Requirement - Save Dv Tmax Value

None

### Emulator Requirement - Save Dv Tmax Value

None

### Control Plane Requirement - Save Dv Tmax Value

None

## Get Supported Component Color



### Test Startup Requirement - Get Supported Component Color

None

### Emulator Requirement - Get Supported Component Color

None

### Control Plane Requirement - Get Supported Component Color

None

## Get Current Component Saturation

|Description|L2|L3|
|-----------|--|--|
|Sets the current component saturation|N|Y|
|Gets the current component saturation value after setting. Ensure it received the correct value set previously.|N|Y|
|Saves the current component saturation value after setting.|N|Y|

### Test Startup Requirement - Get Current Component Saturation

None

### Emulator Requirement - Get Current Component Saturation

None

### Control Plane Requirement - Get Current Component Saturation

None

## Set Current Component Hue

|Description|L2|L3|
|-----------|--|--|
|Sets the current component hue|N|Y|
|Gets the current component hue value after setting. Ensure it received the correct value set previously.|N|Y|

### Test Startup Requirement - Set Current Component Hue

None

### Emulator Requirement - Set Current Component Hue

None

### Control Plane Requirement - Set Current Component Hue

None

## Set Current Component Luma

|Description|L2|L3|
|-----------|--|--|
|Sets the current component luma|N|Y|
|Gets the current component luma value after setting. Ensure it received the correct value set previously.|N|Y|
|Saves the current component luma value after setting.|N|Y|

### Test Startup Requirement - Set Current Component Luma

None

### Emulator Requirement - Set Current Component Luma

None

### Control Plane Requirement - Set Current Component Luma

None

## Save CMS


### Test Startup Requirement - Save CMS

None

### Emulator Requirement - Save CMS

None

### Control Plane Requirement - Save CMS

None

## Set CMS State

|Description|L2|L3|
|-----------|--|--|
|Sets the CMS state|N|Y|
|Gets the CMS state value after setting. Ensure it received the correct value set previously.|N|Y|

### Test Startup Requirement - Set CMS State

None

### Emulator Requirement - Set CMS State

None

### Control Plane Requirement - Set CMS State

None

## Get Default PQ Params

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of retrieving the default PQ (Picture Quality) parameters for a given picture mode, primary video source, and video format. It ensures that the default values are retrieved correctly.|N|Y|

### Test Startup Requirement - Get Default PQ Params

None

### Emulator Requirement - Get Default PQ Params

None

### Control Plane Requirement - Get Default PQ Params

None

## Get PQ Params

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of retrieving the override PQ parameters for a given picture mode, primary video source, and video format. It ensures that the override values are retrieved correctly.|N|Y|

### Test Startup Requirement - Get PQ Params

None

### Emulator Requirement - Get PQ Params

None

### Control Plane Requirement - Get PQ Params

None

## Get Max Gain Value

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of retrieving the maximum gamma/white balance gain value capable for the platform. It ensures that the returned value is within the valid range and accurately reflects the maximum gain value.|N|Y|

### Test Startup Requirement - Get Max Gain Value

None

### Emulator Requirement - Get Max Gain Value

None

### Control Plane Requirement - Get Max Gain Value

None

## Enable Gamma Mode

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of enabling or disabling the gamma mode. It ensures that the gamma module can be successfully enabled or disabled as intended.|N|Y|

### Test Startup Requirement - Enable Gamma Mode

None

### Emulator Requirement - Enable Gamma Mode

None

### Control Plane Requirement - Enable Gamma Mode

None

## Set Gamma Pattern

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of setting the gamma pattern. It ensures that the primary color level can be set accurately and displayed as intended on the screen.|N|Y|

### Test Startup Requirement - Set Gamma Pattern

None

### Emulator Requirement - Set Gamma Pattern

None

### Control Plane Requirement - Set Gamma Pattern

None

## Get TV Gamma Target

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of retrieving the target x and y coordinates for the panel gamma based on a given color temperature. It ensures that the returned coordinates are accurate and reflect the desired color temperature.|N|Y|

### Test Startup Requirement - Get TV Gamma Target

None

### Emulator Requirement - Get TV Gamma Target

None

### Control Plane Requirement - Get TV Gamma Target

None

## Set Gamma Pattern Mode

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of enabling or disabling the gamma pattern mode. It ensures that the gamma pattern mode can be successfully enabled or disabled as intended.|N|Y|

### Test Startup Requirement - Set Gamma Pattern Mode

None

### Emulator Requirement - Set Gamma Pattern Mode

None

### Control Plane Requirement - Set Gamma Pattern Mode

None

## Set RGB Pattern

|Description|L2|L3|
|-----------|--|--|
|Sets the RGB pattern|N|Y|
|Gets the RGB pattern value after setting. Ensure it received the correct value set previously.|N|Y|
|Saves the RGB pattern value after setting.|N|Y|

### Test Startup Requirement - Set RGB Pattern

None

### Emulator Requirement - Set RGB Pattern

None

### Control Plane Requirement - Set RGB Pattern

None

## Set Gray Pattern

|Description|L2|L3|
|-----------|--|--|
|Sets the gray pattern|N|Y|
|Gets the gray pattern value after setting. Ensure it received the correct value set previously.|N|Y|
|Saves the gray pattern value after setting.|N|Y|

### Test Startup Requirement - Set Gray Pattern

None

### Emulator Requirement - Set Gray Pattern

None

### Control Plane Requirement - Set Gray Pattern

None

## Get Gray Pattern

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of retrieving the current gray pattern value. It ensures that the returned value accurately reflects the current gray pattern setting.|N|Y|

### Test Startup Requirement - Get Gray Pattern

None

### Emulator Requirement - Get Gray Pattern

None

### Control Plane Requirement - Get Gray Pattern

None

## Get Open Circuit Status

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of retrieving the current open circuit status of the backlight hardware. It ensures that the returned status indicates whether any LED fault is detected.|N|Y|

### Test Startup Requirement - Get Open Circuit Status

None

### Emulator Requirement - Get Open Circuit Status

None

### Control Plane Requirement - Get Open Circuit Status

None

## Enable LDIM Pixel Compensation

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of enabling or disabling the pixel compensation block for LDIM (Local Dimming). It ensures that the pixel compensation block can be successfully enabled or disabled as intended.|N|Y|

### Test Startup Requirement - Enable LDIM Pixel Compensation

None

### Emulator Requirement - Enable LDIM Pixel Compensation

None

### Control Plane Requirement - Enable LDIM Pixel Compensation

None

## Enable LDIM

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of enabling or disabling the local dimming module. It ensures that the local dimming module can be successfully enabled or disabled as intended.|N|Y|

### Test Startup Requirement - Enable LDIM

None

### Emulator Requirement - Enable LDIM

None

### Control Plane Requirement - Enable LDIM

None

## Start LDIM Sequence Test

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of starting the local dimming sequence test. It ensures that the test sequence is executed correctly, turning on each LDIM zone for the specified duration.|N|Y|

### Test Startup Requirement - Start LDIM Sequence Test

None

### Emulator Requirement - Start LDIM Sequence Test

None

### Control Plane Requirement - Start LDIM Sequence Test

None

## Set Backlight Test Mode

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of setting the backlight test mode. It ensures that the backlight hardware can be configured correctly for calibration purposes based on the specified test mode.|N|Y|

### Test Startup Requirement - Set Backlight Test Mode

None

### Emulator Requirement - Set Backlight Test Mode

None

### Control Plane Requirement - Set Backlight Test Mode

None

## Enable White Balance

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of enabling or disabling the white balance module. It ensures that the white balance module can be successfully enabled or disabled as intended.|N|Y|

### Test Startup Requirement - Enable White Balance

None

### Emulator Requirement - Enable White Balance

None

### Control Plane Requirement - Enable White Balance

None

## Enable Dynamic Contrast

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of enabling or disabling the dynamic contrast module. It ensures that the dynamic contrast module can be successfully enabled or disabled as intended.|N|Y|

### Test Startup Requirement - Enable Dynamic Contrast

None

### Emulator Requirement - Enable Dynamic Contrast

None

### Control Plane Requirement - Enable Dynamic Contrast

None

## Enable Local Contrast

|Description|L2|L3|
|-----------|--|--|
|This test verifies the functionality of enabling or disabling the local contrast module. It ensures that the local contrast module can be successfully enabled or disabled as intended.|N|Y|

### Test Startup Requirement - Enable Local Contrast

None

### Emulator Requirement - Enable Local Contrast

None

### Control Plane Requirement - Enable Local Contrast

None