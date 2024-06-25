# TVSETTINGS L2 Low Level Test Specification and Procedure Documentation

## Table of Contents

- [TVSETTINGS L2 Low Level Test Specification and Procedure Documentation](#tvsettings-l2-low-level-test-specification-and-procedure-documentation)

  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
    - [Acronyms, Terms and Abbreviations](#acronyms-terms-and-abbreviations)
    - [Definitions](#definitions)
    - [References](#references)
  - [Level 2 Test Procedure](#level-2-test-procedure)

## Overview

This document describes the level 2 testing suite for the TVSETTINGS module.

### Acronyms, Terms and Abbreviations

- `HAL` \- Hardware Abstraction Layer, may include some common components
- `UT`  \- Unit Test(s)
- `OEM`  \- Original Equipment Manufacture
- `SoC`  \- System on a Chip

### Definitions

  - `ut-core` \- Common Testing Framework <https://github.com/rdkcentral/ut-core>, which wraps a open-source framework that can be expanded to the requirements for future framework.

### References
- `High Level Test Specification` - [tvSettings_Test_Spec.md](tvSettings_Test_Spec.md)

## Level 2 Test Procedure

The following functions are expecting to test the module operates correctly.

### Test 1

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_GetSupportedVideoFormats`|
|Description|Get TV supported video formats and verify that the test provides all supported video formats and their count (minimum is 1 and maximum is VIDEO_FORMAT_MAX). Compare the test results with the platform-supported configurations file 'Sink-4K-TvSettings.yaml' using the path 'VideoFormat/index' and loop through the indices. Using the path 'VideoFormat/numberOfFormats' compare the count.|
|Test Group|Module : 02|
|Test Case ID|001|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize TV using TvInit | None | tvERROR_NONE | Should be successful |
| 02 | Get supported video formats using GetTVSupportedVideoFormats | videoFormats = valid buffer, numberOfFormats = valid buffer | tvERROR_NONE | Should be successful |
| 03 | Verify the number of formats | numberOfFormats = valid buffer | tvERROR_NONE | Should be successful |
| 04 | Loop through the indices and verify each video format | videoFormats[i] = valid buffer | tvERROR_NONE | Should be successful |
| 05 | Terminate TV using TvTerm | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit] -->|tvERROR_NONE| B[GetTVSupportedVideoFormats]
    A -->|Failure| A1[Test case fail]
    B -->|tvERROR_NONE| C[Compare video formats and count]
    B -->|Failure| B1[Test case fail]
    C -->|Match| D[TvTerm]
    D -->|tvERROR_NONE| E[Test case success]
    D -->|Failure| D1[Test case fail]
```


### Test 2

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_GetCurrentVideoFormat_NoVideoPlayback`|
|Description|Verify getting the current video format when there is no video playback. Default is VIDEO_FORMAT_SDR|
|Test Group|Module : 02|
|Test Case ID|002|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Invoke TvInit with no input parameters | None | tvERROR_NONE | Should be successful |
| 02 | Invoke GetCurrentVideoFormat with valid pointer to tvVideoFormatType_t variable and verify value | videoFormat = valid pointer | tvERROR_NONE, VIDEO_FORMAT_SDR | Should be successful |
| 03 | Invoke TvTerm with no input parameters | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
A[TvInit] -->|tvERROR_NONE| B[GetCurrentVideoFormat]
A -->|!= tvERROR_NONE| A1[Test case fail]
B -->|tvERROR_NONE| C[Verify tvVideoFormatType_t <br> == VIDEO_FORMAT_SDR]
B -->|!= tvERROR_NONE| B1[Test case fail]
C -->|True| D[TvTerm]
D -->|tvERROR_NONE| E[Test case success]
D -->|!= tvERROR_NONE| D1[Test case fail]
```


### Test 3

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_VerifyCurrentVideoResolution`|
|Description|Verify that the current video resolution of the primary video is 'tvVideoResolution_NONE' when playback has not started or has been stopped.|
|Test Group|Module : 02|
|Test Case ID|003|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit | None | tvERROR_NONE | Should be successful |
| 02 | Get the current video resolution using GetCurrentVideoResolution | res = valid buffer | tvERROR_NONE | Should be successful |
| 03 | Check if the resolution value is 'tvVideoResolution_NONE' | resolutionValue = tvVideoResolution_NONE | tvVideoResolution_NONE | Should be successful |
| 04 | Check if the frame height is 0 | frameHeight = 0 | 0 | Should be successful |
| 05 | Check if the frame width is 0 | frameWidth = 0 | 0 | Should be successful |
| 06 | Check if the video is not interlaced | isInterlaced = 0 | 0 | Should be successful |
| 07 | If the status is not 'tvERROR_NONE', terminate the TV using TvTerm | None | tvERROR_NONE | Should be successful |
| 08 | Terminate the TV using TvTerm | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    TvInit[Call TvInit API] -->|tvERROR_NONE| GetCurrentVideoResolution
    TvInit -->|!= tvERROR_NONE| TestcaseFail1[Test case fail]
    GetCurrentVideoResolution[Call GetCurrentVideoResolution API] -->|Success| CheckResolutionValue
    GetCurrentVideoResolution -->|Failure| TestcaseFail2[Test case fail]
    CheckResolutionValue[Check resolutionValue field] -->|tvVideoResolution_NONE| CheckFrameHeight
    CheckResolutionValue -->|!= tvVideoResolution_NONE| TestcaseFail3[Test case fail]
    CheckFrameHeight[Check frameHeight field] -->|0| CheckFrameWidth
    CheckFrameWidth[Check frameWidth field] -->|0| CheckIsInterlaced
    CheckIsInterlaced[Check isInterlaced field] -->|0| TvTerm
    TvTerm[Call TvTerm API] -->|tvERROR_NONE| TestcaseSuccess[Test case success]
    TvTerm -->|!= tvERROR_NONE| TestcaseFail7[Test case fail]
```


### Test 4

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_VerifyFrameRateWhenStopped`|
|Description|Verify that the current video frame rate of the primary video is 'tvVideoFrameRate_NONE' when playback has not started or has been stopped.|
|Test Group|Module : 02|
|Test Case ID|004|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit | None | tvERROR_NONE | Should be successful |
| 02 | Get the current video frame rate using GetCurrentVideoFrameRate  and verify the value| frameRate = valid buffer | tvERROR_NONE, frameRate = tvVideoFrameRate_NONE | Should be successful |
| 03 | If the previous step was successful, terminate the TV using TvTerm | None | tvERROR_NONE | Should be successful |

```mermaid
graph TB
A[TvInit API Call] -->|Success: tvERROR_NONE| B[GetCurrentVideoFrameRate API Call]
A -->|Failure: Not tvERROR_NONE| A1[Test Case Fail]
B -->|Success: tvVideoFrameRate_NONE| C[Verify Frame Rate is tvVideoFrameRate_NONE]
B -->|Failure: Not tvVideoFrameRate_NONE| B1[Test Case Fail]
C -->|Success| D[TvTerm API Call]
D -->|Success: tvERROR_NONE| E[Test Case Success]
D -->|Failure: Not tvERROR_NONE| D1[Test Case Fail]
```


### Test 5

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_GetTVSupportedVideoSources`|
|Description|Get TV Supported Video Sources - Verify the test provides all supported video sources and their count( Min is 1 and Max is VIDEO_SOURCE_MAX). Compare the test results with the platform-supported configurations file 'Sink-4K-TvSettings.yaml' using the path 'VideoSource/index' and loop through the indices, using the path 'VideoSource/numberOfFormats' compare the count.|
|Test Group|Module : 02|
|Test Case ID|005|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Get supported video sources and their count using GetTVSupportedVideoSources() | videoSources = valid buffer, numberOfSources = valid buffer | tvERROR_NONE | Should be successful |
| 03 | Verify the number of sources is between 1 and VIDEO_SOURCE_MAX | numberOfSources = returned value | True | Should be successful |
| 04 | Loop through the indices and compare the test results with the platform-supported configurations file using the path 'VideoSource/index' | videoSources[i] = returned value, key = "VideoSource/index/i" | True | Should be successful |
| 05 | Terminate TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit] -->|tvERROR_NONE| B[GetTVSupportedVideoSources]
    A -->|!= tvERROR_NONE| A1[Test case fail]
    B -->|tvERROR_NONE| C[Verify count of video sources]
    B -->|!= tvERROR_NONE| B1[Test case fail]
    C -->|1 <= count <= VIDEO_SOURCE_MAX| D[Compare video sources with Sink-4K-TvSettings.yaml]
    D --> E[Compare count of video sources with configuration file]
    E --> F[TvTerm]
    F -->|tvERROR_NONE| G[Test case pass]
    F -->|!= tvERROR_NONE| F1[Test case fail]
```


### Test 6

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_VerifyNoVideoSource`|
|Description|Verify when there is no video source device is connected. Default is VIDEO_SOURCE_IP|
|Test Group|Module : 02|
|Test Case ID|006|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Invoke TvInit() to initialize the TV | None | tvERROR_NONE | Should be successful |
| 02 | Invoke GetCurrentVideoSource() with valid pointer to get the current video source | currentSource = valid pointer | tvERROR_NONE, VIDEO_SOURCE_IP | Should be successful |
| 03 | Invoke TvTerm() to terminate the TV | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit] -->|tvERROR_NONE| B[GetCurrentVideoSource]
    A -->|!=tvERROR_NONE| A1[Test case fail]
    B -->|VIDEO_SOURCE_IP| C[TvTerm]
    B -->|!=VIDEO_SOURCE_IP| B1[Test case fail]
    C -->|tvERROR_NONE| D[Test case success]
    C -->|!=tvERROR_NONE| C1[Test case fail]
```


### Test 7

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetBacklight`|
|Description|Sets and Gets the backlight within the valid range (0 - 100). The retrieved value should match the set value. Get values are retrieved from the `PQ` database.|
|Test Group|Module : 02|
|Test Case ID|007|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Set the backlight value using SetBacklight() | backlight = 50 | tvERROR_NONE | Should be successful |
| 03 | Get the backlight value using GetBacklight() and verify with set value | getBacklight = valid buffer | tvERROR_NONE, backlight = 50 | Should be successful |
| 04 | Terminate the TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
A[TvInit] -->|Success| B[SetBacklight]
A -->|Failure| A1[Test case fail]
B -->|Success| D[GetBacklight]
B -->|Failure| B1[Test case fail]
D -->|Success| F[Verify get and set backlight value]
D -->|Failure| D1[Test case fail]
F -->|Success| G[TvTerm]
G -->|Success| H[Test case success]
G -->|Failure| G1[Test case fail]
```


### Test 8

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetBacklightFade`|
|Description|Set and Gets the Back light fade within the valid ranges of from ( 0  - 100 ), to ( 0 - 100 ), current( 0 - 100) and duration (0 - 10000 ms). The retrieved value should match the set value. Get values are retrieved from the `PQ` database.|
|Test Group|Module : 02|
|Test Case ID|008|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Set the Backlight Fade using SetBacklightFade() | from = 50, to = 100, duration = 5000 | tvERROR_NONE | Should be successful |
| 03 | Get the current Backlight Fade using GetCurrentBacklightFade() | get_from, get_to, get_current | tvERROR_NONE | Should be successful |
| 04 | Validate the set and get values of from and to | from = 50, to = 100 | from = get_from, to = get_to | Should be successful |
| 05 | Terminate the TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
A[TvInit] -->|Success| B[SetBacklightFade]
A -->|Failure| A1[Test case fail]
B -->|Success| D[GetCurrentBacklightFade]
B -->|Failure| B1[Test case fail]
D -->|Success| F[Check get and set to, from , current values match]
D -->|Failure| D1[Test case fail]
F -->|Success| G[TvTerm]
G -->|Success| H[Test case success]
G -->|Failure| G1[Test case fail]
```


### Test 9

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_GetSupportedBacklightModes`|
|Description|Get Supported Back light Modes - verifies to get all the supported backlight modes. Compare the test results with the platform-supported configurations file 'Sink-4K-TvSettings.yaml' using the path 'BacklightControl/index' and loop through the indices.|
|Test Group|Module : 02|
|Test Case ID|009|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit | None | tvERROR_NONE | Should be successful |
| 02 | Get the supported backlight modes using GetSupportedBacklightModes | blModes = valid pointer | tvERROR_NONE | Should be successful |
| 03 | Compare the obtained backlight modes with the platform-supported configurations file | blModes, "BacklightControl/index" | None | Should be successful |
| 04 | Terminate the TV using TvTerm | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit API Call] -->|tvERROR_NONE| B[GetSupportedBacklightModes API Call]
    A -->|Not tvERROR_NONE| A1[Test Case Fail]
    B -->|tvERROR_NONE| C[Compare supported mode with Sink-4K-TvSettings.yaml]
    B -->|Not tvERROR_NONE| B1[Test Case Fail]
    C -->|match| D[TvTerm API Call]
    D -->|tvERROR_NONE| E[Test Case Success]
    D -->|Not tvERROR_NONE| D1[Test Case Fail]


### Test 10

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetBacklightMode`|
|Description|Set and Gets the current Back light modes. The retrieved value should match the set value. Get values are retrieved from the `PQ` database.|
|Test Group|Module : 02|
|Test Case ID|10|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Set current backlight mode using SetCurrentBacklightMode() | setMode = tvBacklightMode_MANUAL | tvERROR_NONE | Should be successful |
| 03 | Get current backlight mode using GetCurrentBacklightMode() | getMode = valid buffer | tvERROR_NONE | Should be successful |
| 04 | Validate the set and get backlight modes are same | setMode, getMode | setMode should be equal to getMode | Should be successful |
| 05 | Terminate TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
A[TvInit] -->|tvERROR_NONE| B[SetCurrentBacklightMode]
A -->|!=tvERROR_NONE| A1[Test case fail]
B -->|tvERROR_NONE| C[GetCurrentBacklightMode]
B -->|!=tvERROR_NONE| B1[Test case fail]
C -->|tvERROR_NONE| D[Verify get and set Backlight Mode]
C -->|!=tvERROR_NONE| C1[Test case fail]
D -->|Match| E[TvTerm]
E -->|tvERROR_NONE| F[Test case success]
E -->|!=tvERROR_NONE| E1[Test case fail]
```


### Test 11

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_GetSupportedDimmingModes`|
|Description|Gets TV Supported Dimming Modes - Verify the test provides all supported backlight dimming modes and their count( Min is 1 and Max is tvDimmingMode_MAX). Compare the test results with the platform-supported configurations file 'Sink-4K-TvSettings.yaml' using the path 'DimmingMode/index' and loop through the indices.|
|Test Group|Module : 02|
|Test Case ID|011|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Invoke TvInit with no input parameters | None | tvERROR_NONE | Should be successful |
| 02 | Invoke GetTVSupportedDimmingModes with valid output parameters | dimmingModes = valid buffer, numDimmingModes = valid buffer | tvERROR_NONE | Should be successful |
| 03 | Compare the number of dimming modes with the platform-supported configurations file | numDimmingModes = value from GetTVSupportedDimmingModes | Equal to the value in 'DimmingMode/index' of 'Sink-4K-TvSettings.yaml' | Should be successful |
| 04 | Invoke TvTerm with no input parameters | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit] -->|Success: tvERROR_NONE| B[GetTVSupportedDimmingModes]
    A -->|Failure: Not tvERROR_NONE| A1[Test case fail]
    B -->|Success: tvERROR_NONE| C[Compare with Sink-4K-TvSettings.yaml]
    B -->|Failure: Not tvERROR_NONE| B1[Test case fail]
    C -->|Success: Matched| D[TvTerm]
    D -->|Success: tvERROR_NONE| E[Test case pass]
    D -->|Failure: Not tvERROR_NONE| D1[Test case fail]
```


### Test 12

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetDimmingMode`|
|Description|Set and Gets the TV Dimming modes. The retrieved value should match the set value. Get values are retrieved from the `PQ` database.|
|Test Group|Module : 02|
|Test Case ID|12|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit | None | tvERROR_NONE | Should be successful |
| 02 | Set the TV Dimming mode to "local" using SetTVDimmingMode | dimmingMode = "local" | tvERROR_NONE | Should be successful |
| 03 | Get the TV Dimming mode using GetTVDimmingMode | getDimmingMode = valid buffer | tvERROR_NONE | Should be successful |
| 04 | Verify the set and get Dimming mode are same | getDimmingMode = "local" | "local" | Should be successful |
| 05 | Set the TV Dimming mode to "fixed" using SetTVDimmingMode | dimmingMode = "fixed" | tvERROR_NONE | Should be successful |
| 06 | Get the TV Dimming mode using GetTVDimmingMode | getDimmingMode = valid buffer | tvERROR_NONE | Should be successful |
| 07 | Verify the set and get Dimming mode are same | getDimmingMode = "fixed" | "fixed" | Should be successful |
| 08 | Set the TV Dimming mode to "global" using SetTVDimmingMode | dimmingMode = "global" | tvERROR_NONE | Should be successful |
| 09 | Get the TV Dimming mode using GetTVDimmingMode | getDimmingMode = valid buffer | tvERROR_NONE | Should be successful |
| 10 | Verify the set and get Dimming mode are same | getDimmingMode = "global" | "global" | Should be successful |
| 11 | Terminate the TV using TvTerm | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
A[TvInit API Call] -->|Success| B[SetTVDimmingMode API Call with <br> values 'local, fixed, global']
A -->|Failure| A1[Test Case Fail]
B -->|Success| D[GetTVDimmingMode API Call]
B -->|Failure| B1[Test Case Fail]
D -->|Success| F[Check get and set Dimming Mode]
D -->|Failure| D1[Test Case Fail]
F -->|Success| G[TvTerm API Call]
G -->|Success| H[Test Case Success]
G -->|Failure| G1[Test Case Fail]
```


### Test 13

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetLocalDimmingLevel`|
|Description|Set and Gets the local Dimming level. The retrieved value should match the set value. Get values are retrieved from the database.|
|Test Group|Module : 02|
|Test Case ID|013|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Set the local dimming level using SetLocalDimmingLevel() for each level in ldimStateLevels[] | ldimStateLevel = LDIM_STATE_NONBOOST, LDIM_STATE_BOOST, LDIM_STATE_BURST | tvERROR_NONE | Should be successful |
| 03 | Get the local dimming level using GetLocalDimmingLevel() | None | tvERROR_NONE | Should be successful |
| 04 | Assert that the set and retrieved local dimming levels are equal | None | ldimStateLevel = ldimStateLevelGet | Should be successful |
| 05 | Terminate the TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    TvInit[Call TvInit] -->|tvERROR_NONE| SetLocalDimmingLevel1
    TvInit -->|Failure| TestcaseFail1[Test case failed]
    SetLocalDimmingLevel1[Call SetLocalDimmingLevel <br> with LDIM_STATE_NONBOOST,<br> LDIM_STATE_BOOST, LDIM_STATE_BURST] -->|tvERROR_NONE| GetLocalDimmingLevel1
    SetLocalDimmingLevel1 -->|Failure| TestcaseFail2[Test case failed]
    GetLocalDimmingLevel1[Call GetLocalDimmingLevel] -->|tvERROR_NONE| Verify1
    GetLocalDimmingLevel1 -->|Failure| TestcaseFail3[Test case failed]
    Verify1[Check get matches set value] -->|success| TvTerm
    TvTerm[Call TvTerm] -->|tvERROR_NONE| TestCaseSuccess[Test case success]
    TvTerm -->|Failure| TestcaseFail8[Test case failed]
```


### Test 14

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetBrightness`|
|Description|Set and Gets the brightness within the valid range ( 0 - 100 ). The retrieved value should match the set value. Get values are retrieved from the database.|
|Test Group|Module : 02|
|Test Case ID|14|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit | None | tvERROR_NONE | Should be successful |
| 02 | Set the brightness using SetBrightness | brightness = 50 | tvERROR_NONE | Should be successful |
| 03 | Get the brightness using GetBrightness | get_brightness = valid buffer | tvERROR_NONE | Should be successful |
| 04 | Validate the set and get brightness values are equal | brightness = 50, get_brightness = 50 | Equal | Should be successful |
| 05 | Terminate the TV using TvTerm | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    Start(Start) --> Step1[Call TvInit API]
    Step1 -->|tvERROR_NONE| Step2[Call SetBrightness API with valid value]
    Step1 -->|Failure| Fail1[Test Case Failed: TvInit API failed]
    Step2 -->|tvERROR_NONE| Step3[Verify SetBrightness returns tvERROR_NONE]
    Step2 -->|Failure| Fail2[Test Case Failed: SetBrightness API failed]
    Step3 -->|Success| Step4[Call GetBrightness API]
    Step3 -->|Failure| Fail3[Test Case Failed: SetBrightness return value verification failed]
    Step4 -->|tvERROR_NONE| Step5[Verify GetBrightness returns tvERROR_NONE and value matches]
    Step4 -->|Failure| Fail4[Test Case Failed: GetBrightness API failed]
    Step5 -->|Success| Step6[Call TvTerm API]
    Step5 -->|Failure| Fail5[Test Case Failed: GetBrightness return value verification failed]
    Step6 -->|tvERROR_NONE| End[Test Case Passed]
    Step6 -->|Failure| Fail6[Test Case Failed: TvTerm API failed]
```


### Test 15

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetContrast`|
|Description|Set and Gets the contrast within the valid range ( 0 - 100 ). The retrieved value should match the set value. Get values are retrieved from the database.|
|Test Group|Module : 02|
|Test Case ID|15|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Set the contrast using SetContrast() | contrast = 50 | tvERROR_NONE | Should be successful |
| 03 | Get the contrast using GetContrast() | getContrast = valid buffer | tvERROR_NONE | Should be successful |
| 04 | Check if the set and get contrast values match | contrast = 50, getContrast = retrieved value | tvERROR_NONE, getContrast = contrast | Should be successful |
| 05 | Terminate the TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
A[TvInit API Call] -->|tvERROR_NONE| B[SetContrast API Call]
A -->|Failure| A1[Test case fail]
B -->|tvERROR_NONE| C[GetContrast API Call]
B -->|Failure| B1[Test case fail]
C -->|tvERROR_NONE and Contrast value matches| D[TvTerm API Call]
C -->|Failure| C1[Test case fail]
D -->|tvERROR_NONE| E[Test case success]
D -->|Failure| D1[Test case fail]
```


### Test 16

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetSharpness`|
|Description|Set and Gets the sharpness ( 0 - 100 ). The retrieved value should match the set value. Get values are retrieved from the database.|
|Test Group|Module : 02|
|Test Case ID|16|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Set the sharpness using SetSharpness() | setSharpness = 50 | tvERROR_NONE | Should be successful |
| 03 | If SetSharpness() fails, terminate the TV using TvTerm() and exit the test | None | None | Should fail |
| 04 | Get the sharpness using GetSharpness() | getSharpness = 0 | tvERROR_NONE | Should be successful |
| 05 | If GetSharpness() fails, terminate the TV using TvTerm() and exit the test | None | None | Should fail |
| 06 | Assert that the set sharpness and the retrieved sharpness are equal | setSharpness = 50, getSharpness = 50 | True | Should be successful |
| 07 | Terminate the TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
A[TvInit()] -->|Success| B[SetSharpness()]
A -->|Failure| A1[Test case fail]
B -->|Success| C[Verify SetSharpness() return status]
B -->|Failure| B1[Test case fail]
C -->|Success| D[GetSharpness()]
C -->|Failure| C1[Test case fail]
D -->|Success| E[Verify GetSharpness() return status]
D -->|Failure| D1[Test case fail]
E -->|Success| F[Verify sharpness value]
E -->|Failure| E1[Test case fail]
F -->|Success| G[TvTerm()]
F -->|Failure| F1[Test case fail]
G -->|Success| H[Test case success]
G -->|Failure| G1[Test case fail]
```


### Test 17

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetSaturation`|
|Description|Set and Gets the saturation within the valid range ( 0 - 100 ). The retrieved value should match the set value. Get values are retrieved from the database.|
|Test Group|Module : 02|
|Test Case ID|17|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Set the saturation value using SetSaturation() | saturation_set = 50 | tvERROR_NONE | Should be successful |
| 03 | Get the saturation value using GetSaturation() | saturation_get = address of variable | tvERROR_NONE | Should be successful |
| 04 | Compare the set and get saturation values | saturation_set, saturation_get | saturation_set should be equal to saturation_get | Should be successful |
| 05 | Terminate the TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
A[TvInit] -->|Success| B[SetSaturation]
A -->|Failure| A1[Test case fail: TvInit]
B -->|Success| C[GetSaturation]
B -->|Failure| B1[Test case fail: SetSaturation]
C -->|Success| D[Compare Saturation Value]
C -->|Failure| C1[Test case fail: GetSaturation]
D -->|Success| E[TvTerm]
D -->|Failure| D1[Test case fail: Compare Saturation Value]
E -->|Success| F[Test case pass]
E -->|Failure| E1[Test case fail: TvTerm]
```


### Test 18

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetHue`|
|Description|Set and Gets the Hue ( 0 - 100 ). The retrieved value should match the set value. Get values are retrieved from the database.|
|Test Group|Module : 02|
|Test Case ID|018|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit | None | tvERROR_NONE | Should be successful |
| 02 | Set the Hue using SetHue | hue = 50 | tvERROR_NONE | Should be successful |
| 03 | Get the Hue using GetHue | getHue = valid buffer | tvERROR_NONE | Should be successful |
| 04 | Validate the set and get Hue values are same | hue = 50, getHue = retrieved value | hue should be equal to getHue | Should be successful |
| 05 | Terminate the TV using TvTerm | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit] -->|tvERROR_NONE| B[SetHue]
    A -->|Failure| A1[Test case fail]
    B -->|tvERROR_NONE| C[GetHue]
    B -->|Failure| B1[Test case fail]
    C -->|tvERROR_NONE and hue value matches| D[TvTerm]
    C -->|Failure| C1[Test case fail]
    D -->|tvERROR_NONE| E[Test case success]
    D -->|Failure| D1[Test case fail]
```


### Test 19

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetColorTemperature`|
|Description|Set and Gets the Color Temperature. The retrieved value should match the set value. Get values are retrieved from the database.|
|Test Group|Module : 02|
|Test Case ID|19|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit | None | tvERROR_NONE | Should be successful |
| 02 | Set the color temperature using SetColorTemperature | colorTemp = tvColorTemp_STANDARD | tvERROR_NONE | Should be successful |
| 03 | Get the color temperature using GetColorTemperature | getColorTemp = valid buffer | tvERROR_NONE, colorTemp = getColorTemp | Should be successful |
| 04 | Terminate the TV using TvTerm | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit API Call] -->|Success| B[SetColorTemperature API Call]
    A -->|Failure| A1[Test case fail]
    B -->|Success| C[Verify SetColorTemperature API returns tvERROR_NONE]
    B -->|Failure| B1[Test case fail]
    C -->|Success| D[GetColorTemperature API Call]
    C -->|Failure| C1[Test case fail]
    D -->|Success| E[Verify GetColorTemperature API returns tvERROR_NONE and value matches]
    D -->|Failure| D1[Test case fail]
    E -->|Success| F[TvTerm API Call]
    E -->|Failure| E1[Test case fail]
    F -->|Success| G[Test case success]
    F -->|Failure| F1[Test case fail]
```


### Test 20

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetAspectRatio`|
|Description|Set and Gets the Aspect Ratio. The retrieved value should match the set value. Get values are retrieved from the database.|
|Test Group|Module : 02|
|Test Case ID|20|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Set the Aspect Ratio using SetAspectRatio() with tvDisplayMode_4x3 | setMode = tvDisplayMode_4x3 | tvERROR_NONE | Should be successful |
| 03 | Get the Aspect Ratio using GetAspectRatio() | getMode = valid buffer | tvERROR_NONE | Should be successful |
| 04 | Validate the set and get Aspect Ratio are same | setMode, getMode | setMode should be equal to getMode | Should be successful |
| 05 | Terminate the TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit] -->|Success| B[SetAspectRatio]
    A -->|Failure| A1[Test case fail: TvInit failed]
    B -->|Success| C[GetAspectRatio]
    B -->|Failure| B1[Test case fail: SetAspectRatio failed]
    C -->|Success| D[Verify GetAspectRatio value]
    C -->|Failure| C1[Test case fail: GetAspectRatio failed]
    D -->|Success| E[TvTerm]
    D -->|Failure| D1[Test case fail: GetAspectRatio value mismatch]
    E -->|Success| F[Test case pass]
    E -->|Failure| E1[Test case fail: TvTerm failed]
```


### Test 21

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetLowLatencyState`|
|Description|Set and Gets the Low Latency State ( 0 for disable and 1 for enable ). The retrieved value should match the set value. Get values are retrieved from the database.|
|Test Group|Module : 02|
|Test Case ID|021|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Set Low Latency State to 1 using SetLowLatencyState(1) | LowLatencyState = 1 | tvERROR_NONE | Should be successful |
| 03 | Get Low Latency State using GetLowLatencyState(&lowlatencystate) | lowlatencystate = address of integer variable | tvERROR_NONE, lowlatencystate = 1 | Should be successful |
| 04 | Set Low Latency State to 0 using SetLowLatencyState(0) | LowLatencyState = 0 | tvERROR_NONE | Should be successful |
| 05 | Get Low Latency State using GetLowLatencyState(&lowlatencystate) | lowlatencystate = address of integer variable | tvERROR_NONE, lowlatencystate = 0 | Should be successful |
| 06 | Terminate TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
A[TvInit()] -->|tvERROR_NONE| B[SetLowLatencyState(1)]
B -->|tvERROR_NONE| C[GetLowLatencyState(&lowlatencystate)]
C -->|tvERROR_NONE, lowlatencystate=1| D[SetLowLatencyState(0)]
D -->|tvERROR_NONE| E[GetLowLatencyState(&lowlatencystate)]
E -->|tvERROR_NONE, lowlatencystate=0| F[TvTerm()]
A -->|Failure| G[Test case fail]
B -->|Failure| H[Test case fail]
C -->|Failure| I[Test case fail]
D -->|Failure| J[Test case fail]
E -->|Failure| K[Test case fail]
F -->|Failure| L[Test case fail]
```


### Test 22

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetDynamicContrast`|
|Description|Set and Gets the Dynamic Contrast. The retrieved value should match the set value. Get values are retrieved from the database.|
|Test Group|Module : 02|
|Test Case ID|22|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit | None | tvERROR_NONE | Should be successful |
| 02 | Set Dynamic Contrast to enabled using SetDynamicContrast | dynamicContrastEnable = "enabled" | tvERROR_NONE | Should be successful |
| 03 | Get the Dynamic Contrast status using GetDynamicContrast | isDynamicContrastEnabled = valid buffer | tvERROR_NONE, isDynamicContrastEnabled = "enabled" | Should be successful |
| 04 | Set Dynamic Contrast to disabled using SetDynamicContrast | dynamicContrastEnable = "disabled" | tvERROR_NONE | Should be successful |
| 05 | Get the Dynamic Contrast status using GetDynamicContrast | isDynamicContrastEnabled = valid buffer | tvERROR_NONE, isDynamicContrastEnabled = "disabled" | Should be successful |
| 06 | Terminate the TV using TvTerm | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
A[TvInit()] -->|tvERROR_NONE| B[SetDynamicContrast(enabled)]
B -->|tvERROR_NONE| C[GetDynamicContrast()]
C -->|tvERROR_NONE, isDynamicContrastEnabled = enabled| D[SetDynamicContrast(disabled)]
D -->|tvERROR_NONE| E[GetDynamicContrast()]
E -->|tvERROR_NONE, isDynamicContrastEnabled = disabled| F[TvTerm()]
A -->|Failure| G[Test case fail]
B -->|Failure| H[Test case fail]
C -->|Failure| I[Test case fail]
D -->|Failure| J[Test case fail]
E -->|Failure| K[Test case fail]
F -->|Failure| L[Test case fail]
```



### Test 23

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetDynamicGamma`|
|Description|Set and Gets the Dynamic Gamma within the valid range ( 1.80 to 2.60 ). The retrieved value should match the set value. Get values are retrieved from the database.|
|Test Group|Module : 02|
|Test Case ID|23|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Set the Dynamic Gamma using SetDynamicGamma() | setGammaValue = 2.0 | tvERROR_NONE | Should be successful |
| 03 | If SetDynamicGamma() fails, terminate the TV using TvTerm() and return | None | tvERROR_NONE | Should be successful |
| 04 | Get the Dynamic Gamma using GetDynamicGamma() | getGammaValue = valid buffer | tvERROR_NONE | Should be successful |
| 05 | Assert that the set and get Gamma values are equal | setGammaValue = 2.0, getGammaValue = retrieved value | setGammaValue should be equal to getGammaValue | Should be successful |
| 06 | Terminate the TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit] -->|Success| B[SetDynamicGamma]
    A -->|Failure| A1[Test case fail]
    B -->|Success| C[GetDynamicGamma]
    B -->|Failure| B1[Test case fail]
    C -->|Success| D[Compare GetDynamicGamma value with SetDynamicGamma value]
    C -->|Failure| C1[Test case fail]
    D -->|Success| E[TvTerm]
    D -->|Failure| D1[Test case fail]
    E -->|Success| F[Test case success]
    E -->|Failure| E1[Test case fail]
```


### Test 24

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_GetSupportedDolbyVisionModes`|
|Description|Get TV Supported Dolby Vision Modes - Verify the test provides all supported Dolby Vision modes and their count( Min is 0 and Max is tvMode_Max ). Compare the test results with the platform-supported configurations file 'Sink-4K-TvSettings.yaml' using the path 'DolbyVisionMode/index' and loop through the indices.|
|Test Group|Module : 02|
|Test Case ID|24|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize TV using TvInit | None | tvERROR_NONE | Should be successful |
| 02 | Invoke GetTVSupportedDolbyVisionModes with valid dvModes and count | dvModes = valid buffer, count = valid buffer | tvERROR_NONE | Should be successful |
| 03 | Check if the count of supported Dolby Vision modes is between 0 and tvMode_Max | count = returned value from GetTVSupportedDolbyVisionModes | count >= 0 and count <= tvMode_Max | Should be successful |
| 04 | Loop through the indices and compare the test results with the platform-supported configurations file using the path 'DolbyVisionMode/index' | dvModes[i] = returned value from GetTVSupportedDolbyVisionModes | Equal to the value in the platform-supported configurations file | Should be successful |
| 05 | Terminate TV using TvTerm | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
A[TvInit API Call] -->|tvERROR_NONE| B[GetTVSupportedDolbyVisionModes API Call]
A -->|Failure| A1[Test case fail]
B -->|tvERROR_NONE| C[Verify count of supported Dolby Vision modes]
B -->|Failure| B1[Test case fail]
C -->|0 <= count <= tvMode_Max| D[Loop through array of supported Dolby Vision modes]
C -->|Failure| C1[Test case fail]
D --> E[TvTerm API Call]
E -->|tvERROR_NONE| F[Test case success]
E -->|Failure| E1[Test case fail]
```


### Test 25

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetDolbyVisionMode`|
|Description|Set and Gets the TV Dolby Vision mode. The retrieved value should match the set value. Get values are retrieved from the database.|
|Test Group|Module : 02|
|Test Case ID|025|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit | None | tvERROR_NONE | Should be successful |
| 02 | Set the TV Dolby Vision mode using SetTVDolbyVisionMode | dolbyMode = tvDolbyMode_Dark | tvERROR_NONE | Should be successful |
| 03 | Get the TV Dolby Vision mode using GetTVDolbyVisionMode | getDolbyMode = valid buffer | tvERROR_NONE, getDolbyMode = dolbyMode | Should be successful |
| 04 | If there is a mismatch in set and get Dolby Vision Mode, terminate the TV using TvTerm | None | tvERROR_NONE | Should be successful |
| 05 | Terminate the TV using TvTerm | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
A[TvInit()] -->|tvERROR_NONE| B[SetTVDolbyVisionMode()]
A -->|Failure| A1[Test case fail]
B -->|tvERROR_NONE| C[GetTVDolbyVisionMode()]
B -->|Failure| B1[Test case fail]
C -->|tvERROR_NONE| D[Verify dolbyMode]
C -->|Failure| C1[Test case fail]
D -->|Match| E[TvTerm()]
D -->|Mismatch| D1[Test case fail]
E -->|tvERROR_NONE| F[Test case pass]
E -->|Failure| E1[Test case fail]
```


### Test 26

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_GetTVSupportedPictureModes`|
|Description|Get TV Supported Picture Modes - Verify the test provides all supported Picture Modes and their count( Min is 1 and Max is PIC_MODES_SUPPORTED_MAX ). Compare the test results with the platform-supported configurations file 'Sink-4K-TvSettings.yaml' using the path 'PictureMode/index' and loop through the indices.|
|Test Group|Module : 02|
|Test Case ID|26|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize TV using TvInit | No input parameters | tvERROR_NONE | Should be successful |
| 02 | Get supported picture modes and their count using GetTVSupportedPictureModes | pictureModes = valid buffer, count = valid buffer | status not equal to tvERROR_INVALID_PARAM and tvERROR_INVALID_STATE, count between 1 and PIC_MODES_SUPPORTED_MAX | Should be successful |
| 03 | Loop through the picture modes and compare with the platform-supported configurations file | pictureModes[i]->name = "PictureMode/index" | Equal to profile string | Should be successful |
| 04 | Terminate TV using TvTerm | No input parameters | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit()] -->|tvERROR_NONE| B[GetTVSupportedPictureModes()]
    A -->|!= tvERROR_NONE| C[Test case fail]
    B -->|!= tvERROR_INVALID_PARAM, != tvERROR_INVALID_STATE| D[Check count of picture modes]
    B -->|== tvERROR_INVALID_PARAM or == tvERROR_INVALID_STATE| E[Test case fail]
    D -->|1 <= count <= PIC_MODES_SUPPORTED_MAX| F[Compare picture modes with Sink-4K-TvSettings.yaml]
    D -->|count < 1 or count > PIC_MODES_SUPPORTED_MAX| G[Test case fail]
    F -->|Match| H[Loop through picture modes]
    F -->|No Match| I[Test case fail]
    H --> J[TvTerm()]
    J -->|tvERROR_NONE| K[Test case pass]
    J -->|!= tvERROR_NONE| L[Test case fail]
```


### Test 27

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetPictureMode`|
|Description|Set and Gets the TV Picture Mode. The retrieved value should match the set value. Set the picture mode to a valid value as specified by ::pic_modes_t.name from the GetTVSupportedPictureModes API, with the string size limited to PIC_MODE_NAME_MAX. Get values are retrieved from the database.|
|Test Group|Module : 02|
|Test Case ID|27|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Get supported picture modes using GetTVSupportedPictureModes() | pictureModes = valid buffer, count = valid buffer | tvERROR_NONE | Should be successful |
| 03 | Set TV picture mode using SetTVPictureMode() for each supported mode | pictureMode = pictureModes[i]->name | tvERROR_NONE | Should be successful |
| 04 | Get TV picture mode using GetTVPictureMode() after setting each mode | pictureMode = valid buffer | tvERROR_NONE | Should be successful |
| 05 | Validate the set and get picture modes are same | pictureModes[i]->name, pictureMode | Equal | Should be successful |
| 06 | Terminate TV using TvTerm() after each set and get operation | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
A[TvInit()] -->|tvERROR_NONE| B[Declare pic_modes_t array and unsigned short variable]
B -->|tvERROR_NONE| C[GetTVSupportedPictureModes()]
C -->|tvERROR_NONE, 1 <= count <= PIC_MODES_SUPPORTED_MAX| D[Choose a valid picture mode]
D -->|Valid picture mode chosen| E[SetTVPictureMode()]
E -->|tvERROR_NONE| F[Declare char array of size PIC_MODE_NAME_MAX]
F -->|Array declared| G[GetTVPictureMode()]
G -->|tvERROR_NONE, returned picture mode matches set picture mode| H[TvTerm()]
H -->|tvERROR_NONE| I[Test case pass]
A -->|!=tvERROR_NONE| J[Test case fail]
B -->|!=tvERROR_NONE| K[Test case fail]
C -->|!=tvERROR_NONE or count < 1 or count > PIC_MODES_SUPPORTED_MAX| L[Test case fail]
D -->|Invalid picture mode chosen| M[Test case fail]
E -->|!=tvERROR_NONE| N[Test case fail]
F -->|Array declaration failed| O[Test case fail]
G -->|!=tvERROR_NONE or returned picture mode doesn't match set picture mode| P[Test case fail]
H -->|!=tvERROR_NONE| Q[Test case fail]
```



### Test 28

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetColorTempRgain`|
|Description|Loop through different color temperatures and source ids. Set and Gets the color Temperature Rgain on Source. The retrieved value should match the set value. Get values are retrieved from the  database.|
|Test Group|Module : 02|
|Test Case ID|28|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit | None | tvERROR_NONE | Should be successful |
| 02 | Loop through different color temperatures and source ids | colorTemp = tvColorTemp_STANDARD to tvColorTemp_MAX, sourceId = ALL_SRC_OFFSET to MAX_OFFSET | None | None |
| 03 | Set the color Temperature Rgain on Source using SetColorTemp_Rgain_onSource | colorTemp = current colorTemp, setRgain = 0 to 2047, sourceId = current sourceId, saveOnly = 0 | tvERROR_NONE | Should be successful |
| 04 | Get the color Temperature Rgain on Source using GetColorTemp_Rgain_onSource | colorTemp = current colorTemp, rgain = address of rgain, sourceId = current sourceId | tvERROR_NONE | Should be successful |
| 05 | Check if the retrieved rgain matches the set rgain | rgain = retrieved rgain, setRgain = set rgain | rgain should be equal to setRgain | Should be successful |
| 06 | Terminate the TV using TvTerm | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit] -->|Success| B{Loop through color temperatures and source ids}
    A -->|Failure| A1[Test case fail]
    B -->|Next Combination| C[SetColorTemp_Rgain_onSource with rgain value and saveOnly parameter as 0]
    B -->|End of Loop| G[TvTerm]
    C -->|Success| D[GetColorTemp_Rgain_onSource]
    C -->|Failure| C1[Test case fail]
    D -->|Success| E{Verify rgain value}
    D -->|Failure| D1[Test case fail]
    E -->|Match| B
    E -->|Mismatch| E1[Test case fail]
    G -->|Success| H[Test case pass]
    G -->|Failure| G1[Test case fail]
```



### Test 29

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetColorTempGgain`|
|Description|Loop through different color temperatures and source ids. Set and Gets the color Temperature Ggain on Source. The retrieved value should match the set value. Get values are retrieved from the  database.|
|Test Group|Module : 02|
|Test Case ID|29|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit | None | tvERROR_NONE | Should be successful |
| 02 | Loop through different color temperatures and source ids | colorTemp = tvColorTemp_STANDARD to tvColorTemp_MAX, sourceId = ALL_SRC_OFFSET to MAX_OFFSET | None | Should be successful |
| 03 | Set the color Temperature Ggain on Source using SetColorTemp_Ggain_onSource | colorTemp = current colorTemp, set_ggain = 0 to 2047, sourceId = current sourceId, saveOnly = 0 | tvERROR_NONE | Should be successful |
| 04 | Get the color Temperature Ggain on Source using GetColorTemp_Ggain_onSource | colorTemp = current colorTemp, ggain = address of ggain, sourceId = current sourceId | tvERROR_NONE | Should be successful |
| 05 | Check if the retrieved ggain matches the set ggain | ggain = retrieved ggain, set_ggain = set ggain | ggain should be equal to set_ggain | Should be successful |
| 06 | Terminate the TV using TvTerm | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit] -->|Success| B{Loop through color temperatures and source ids}
    A -->|Failure| A1[Test case fail]
    B -->|Next Combination| C[SetColorTemp_Ggain_onSource with ggain value and saveOnly parameter as 0]
    B -->|End of Loop| G[TvTerm]
    C -->|Success| D[GetColorTemp_Ggain_onSource]
    C -->|Failure| C1[Test case fail]
    D -->|Success| E{Verify ggain value}
    D -->|Failure| D1[Test case fail]
    E -->|Match| B
    E -->|Mismatch| E1[Test case fail]
    G -->|Success| H[Test case pass]
    G -->|Failure| G1[Test case fail]
```


### Test 30

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetColorTempBgain`|
|Description|Loop through different color temperatures and source ids. Set and Gets the color Temperature Bgain on Source. The retrieved value should match the set value. Get values are retrieved from the  database.|
|Test Group|Module : 02|
|Test Case ID|30|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit | None | tvERROR_NONE | Should be successful |
| 02 | Loop through different color temperatures and source ids | colorTemp = tvColorTemp_STANDARD to tvColorTemp_MAX, sourceId = ALL_SRC_OFFSET to MAX_OFFSET | None | Should be successful |
| 03 | Set the color Temperature Bgain on Source using SetColorTemp_Bgain_onSource | colorTemp, bgain = 0 to 2047, sourceId, saveOnly = 0 | tvERROR_NONE | Should be successful |
| 04 | Get the color Temperature Bgain on Source using GetColorTemp_Bgain_onSource | colorTemp, &get_bgain, sourceId | tvERROR_NONE | Should be successful |
| 05 | Check if the retrieved value matches the set value | bgain, get_bgain | bgain should be equal to get_bgain | Should be successful |
| 06 | Terminate the TV using TvTerm | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit] -->|Success| B{Loop through color temperatures and source ids}
    A -->|Failure| A1[Test case fail]
    B -->|Next Combination| C[SetColorTemp_Bgain_onSource]
    B -->|All Combinations Done| G[TvTerm]
    C -->|Success| D[GetColorTemp_Bgain_onSource]
    C -->|Failure| C1[Test case fail]
    D -->|Success| E{Verify bgain value}
    D -->|Failure| D1[Test case fail]
    E -->|Match| B
    E -->|Mismatch| E1[Test case fail]
    G -->|Success| H[Test case pass]
    G -->|Failure| G1[Test case fail]
```



###Test 31

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetColorTemp_R_post_offset_onSource`|
|Description|Loop through different color temperatures and source ids. Set and Gets the color Temperature R post offset on Source. The retrieved value should match the set value. Get values are retrieved from the  database.|
|Test Group|Module : 02|
|Test Case ID|031|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit | None | tvERROR_NONE | Should be successful |
| 02 | Loop through different color temperatures and source ids. Set the color Temperature R post offset on Source using SetColorTemp_R_post_offset_onSource | colorTemp = value, rpostoffset_set = value, sourceId = value, saveOnly = value | tvERROR_NONE | Should be successful |
| 03 | Get the color Temperature R post offset on Source using GetColorTemp_R_post_offset_onSource | colorTemp = value, sourceId = value | tvERROR_NONE | Should be successful |
| 04 | Check if the retrieved value matches the set value | rpostoffset_set = value, rpostoffset_get = value | rpostoffset_set should be equal to rpostoffset_get | Should be successful |
| 05 | Terminate the TV using TvTerm | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit()] -->|Success| B{Loop through color temperatures and source ids}
    A -->|Failure| A1[Test case fail]
    B -->|Next Combination| C[SetColorTemp_R_post_offset_onSource() with saveOnly=0]
    B -->|End of Loop| G[TvTerm()]
    C -->|Success| D[GetColorTemp_R_post_offset_onSource()]
    C -->|Failure| C1[Test case fail]
    D -->|Success| E{Compare set and retrieved rpostoffset values}
    D -->|Failure| D1[Test case fail]
    E -->|Match| B
    E -->|Mismatch| E1[Test case fail]
    G -->|Success| H[Test case pass]
    G -->|Failure| G1[Test case fail]
    B --> F[SetColorTemp_R_post_offset_onSource() with saveOnly=1]
    F -->|Success| I[GetColorTemp_R_post_offset_onSource()]
    F -->|Failure| F1[Test case fail]
    I -->|Success| J{Compare set and retrieved rpostoffset values}
    I -->|Failure| I1[Test case fail]
    J -->|Match| B
    J -->|Mismatch| J1[Test case fail]
```


### Test 32

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetColorTempGPostOffset`|
|Description|Loop through different color temperatures and source ids. Set and Gets the color Temperature G post offset on Source. The retrieved value should match the set value. Get values are retrieved from the  database.|
|Test Group|Module : 02|
|Test Case ID|32|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Loop through different color temperatures and source ids | colorTemp = tvColorTemp_STANDARD to tvColorTemp_MAX, sourceId = ALL_SRC_OFFSET to MAX_OFFSET | None | None |
| 03 | Set the color Temperature G post offset on Source using SetColorTemp_G_post_offset_onSource() | colorTemp, gpostoffset_set = -1024 to 1023, sourceId, saveOnly = 0 | tvERROR_NONE | Should be successful |
| 04 | Get the color Temperature G post offset on Source using GetColorTemp_G_post_offset_onSource() | colorTemp, &gpostoffset_get, sourceId | tvERROR_NONE, gpostoffset_set | Should be successful |
| 05 | Terminate the TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit] -->|Success| B{Loop through color temperatures and source ids}
    A -->|Failure| A1[Test case fail]
    B -->|Next Combination| C[SetColorTemp_G_post_offset_onSource]
    B -->|End of Loop| G[TvTerm]
    C -->|Success| D[GetColorTemp_G_post_offset_onSource]
    C -->|Failure| C1[Test case fail]
    D -->|Success| B
    D -->|Failure| D1[Test case fail]
    G -->|Success| H[Test case pass]
    G -->|Failure| G1[Test case fail]
```


### Test 33

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetColorTempBPostOffset`|
|Description|Loop through different color temperatures and source ids. Set and Gets the color Temperature B post offset on Source. The retrieved value should match the set value. Get values are retrieved from the  database.|
|Test Group|Module : 02|
|Test Case ID|033|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit | None | tvERROR_NONE | Should be successful |
| 02 | Loop through different color temperatures and source ids. Set the color Temperature B post offset on Source using SetColorTemp_B_post_offset_onSource | colorTemp = value, bpostoffset_set = value, sourceId = value, saveOnly = 1 | tvERROR_NONE | Should be successful |
| 03 | Get the color Temperature B post offset on Source using GetColorTemp_B_post_offset_onSource | colorTemp = value, sourceId = value | tvERROR_NONE | Should be successful |
| 04 | Check if the retrieved value matches the set value | bpostoffset_set = value, bpostoffset_get = value | bpostoffset_set should be equal to bpostoffset_get | Should be successful |
| 05 | Terminate the TV using TvTerm | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit] -->|Success| B{Loop through color temperatures and source ids}
    A -->|Failure| A1[Test case fail]
    B -->|Next Combination| C[SetColorTemp_B_post_offset_onSource]
    B -->|End of Loop| G[TvTerm]
    C -->|Success| D[GetColorTemp_B_post_offset_onSource]
    C -->|Failure| C1[Test case fail]
    D -->|Success| E{Compare set and retrieved bpostoffset}
    D -->|Failure| D1[Test case fail]
    E -->|Match| B
    E -->|Mismatch| E1[Test case fail]
    G -->|Success| H[Test case pass]
    G -->|Failure| G1[Test case fail]
```


### Test 34

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_DisableAndVerifyWBCalibrationMode`|
|Description|Disables the `WB` Calibration Mode and verify by the Get Current WB Calibration Mode|
|Test Group|Module : 02|
|Test Case ID|034|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Disable the WB Calibration Mode using EnableWBCalibrationMode() | false | tvERROR_NONE | Should be successful |
| 03 | Get the current WB Calibration Mode using GetCurrentWBCalibrationMode() | &value | tvERROR_NONE, false | Should be successful |
| 04 | If the status is not tvERROR_NONE or value is not false, terminate the TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    Start(Start) --> Step1
    Step1{Call TvInit API} -->|tvERROR_NONE| Step2
    Step1 -->|Failure| TestcaseFail1[Test case 34 failed]
    Step2{Call EnableWBCalibrationMode API with false} -->|tvERROR_NONE| Step3
    Step2 -->|Failure| TestcaseFail2[Test case 34 failed]
    Step3{Call GetCurrentWBCalibrationMode API} -->|tvERROR_NONE and output is false| Step4
    Step3 -->|Failure| TestcaseFail3[Test case 34 failed]
    Step4{Call TvTerm API} -->|tvERROR_NONE| End(End)
    Step4 -->|Failure| TestcaseFail4[Test case 34 failed]
```


### Test 35

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_EnableAndVerifyWBCalibrationMode`|
|Description|Enables the `WB` Calibration Mode and verify by the Get Current WB Calibration Mode|
|Test Group|Module : 02|
|Test Case ID|35|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Enable WB Calibration Mode using EnableWBCalibrationMode() | value = true | tvERROR_NONE | Should be successful |
| 03 | Get the current WB Calibration Mode using GetCurrentWBCalibrationMode() | value = address of bool variable | tvERROR_NONE, value = true | Should be successful |
| 04 | Disable WB Calibration Mode using EnableWBCalibrationMode() | value = false | tvERROR_NONE | Should be successful |
| 05 | Get the current WB Calibration Mode using GetCurrentWBCalibrationMode() | value = address of bool variable | tvERROR_NONE, value = false | Should be successful |
| 06 | Terminate the TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit()] -->|tvERROR_NONE| B[EnableWBCalibrationMode(true)]
    A -->|!=tvERROR_NONE| A1[Test case fail]
    B -->|tvERROR_NONE| C[GetCurrentWBCalibrationMode()]
    B -->|!=tvERROR_NONE| B1[Test case fail]
    C -->|tvERROR_NONE, output=true| D[EnableWBCalibrationMode(false)]
    C -->|!=tvERROR_NONE or output!=true| C1[Test case fail]
    D -->|tvERROR_NONE| E[GetCurrentWBCalibrationMode()]
    D -->|!=tvERROR_NONE| D1[Test case fail]
    E -->|tvERROR_NONE, output=false| F[TvTerm()]
    E -->|!=tvERROR_NONE or output!=false| E1[Test case fail]
    F -->|tvERROR_NONE| G[Test case pass]
    F -->|!=tvERROR_NONE| F1[Test case fail]
```



### Test 36

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetGammaTable`|
|Description|Set and Gets the Gamma Table within the range ( 0 - 1023). The retrieved value should match the set value. Get values are retrieved from the  database.|
|Test Group|Module : 02|
|Test Case ID|36|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Set the Gamma Table using SetGammaTable() with valid buffers | pData_R = valid buffer, pData_G = valid buffer, pData_B = valid buffer, size = 256 | tvERROR_NONE | Should be successful |
| 03 | If SetGammaTable() fails, terminate the TV using TvTerm() and return | None | None | Should fail |
| 04 | Get the Gamma Table using GetGammaTable() with valid buffers | getData_R = valid buffer, getData_G = valid buffer, getData_B = valid buffer, size = 256 | tvERROR_NONE | Should be successful |
| 05 | Compare the set and get values for each color | pData_R[i] = getData_R[i], pData_G[i] = getData_G[i], pData_B[i] = getData_B[i] | pData_R[i] = getData_R[i], pData_G[i] = getData_G[i], pData_B[i] = getData_B[i] | Should be successful |
| 06 | Terminate the TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit] -->|Success| B[Create three arrays of unsigned short values]
    A -->|Failure| A1[Test case fail]
    B -->|Success| C[SetGammaTable]
    B -->|Failure| B1[Test case fail]
    C -->|Success| D[GetGammaTable]
    C -->|Failure| C1[Test case fail]
    D -->|Success| E[Compare values]
    D -->|Failure| D1[Test case fail]
    E -->|Success| F[TvTerm]
    E -->|Failure| E1[Test case fail]
    F -->|Success| G[Test case pass]
    F -->|Failure| F1[Test case fail]
```


### Test 37

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_GetDefaultGammaTable`|
|Description|Gets the default gamma calibrated values for gamma red, green and blue values ( 0 - 65535 ) and check the values are in the range.|
|Test Group|Module : 02|
|Test Case ID|37|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV settings using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Get the default gamma table for standard color temperature using GetDefaultGammaTable() | colortemp = tvColorTemp_STANDARD, pData_R = valid array, pData_G = valid array, pData_B = valid array, size = 256 | tvERROR_NONE | Should be successful |
| 03 | Check if the returned gamma values for red, green and blue are in the range 0 - 65535 | pData_R = valid array, pData_G = valid array, pData_B = valid array | None | Should be successful |
| 04 | Terminate the TV settings using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
A[TvInit is called] -->|Return status is tvERROR_NONE| B[GetDefaultGammaTable is called with valid color temperature and arrays]
A -->|Return status is not tvERROR_NONE| A1[Test case 37 fails]
B -->|Return status is tvERROR_NONE| C[Check values in pData_R, pData_G, and pData_B arrays]
B -->|Return status is not tvERROR_NONE| B1[Test case 37 fails]
C -->|Values are within valid range| D[TvTerm is called]
C -->|Values are not within valid range| C1[Test case 37 fails]
D -->|Return status is tvERROR_NONE| E[Test case 37 passes]
D -->|Return status is not tvERROR_NONE| D1[Test case 37 fails]
```


### Test 38

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetDvTmaxValue`|
|Description|Set and Gets the Dv Tmax Value within the range ( 0 - 10000 ). The retrieved value should match the set value. Get values are retrieved from the  database.|
|Test Group|Module : 02|
|Test Case ID|38|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV settings using TvInit | None | tvERROR_NONE | Should be successful |
| 02 | Set the Dv Tmax Value using SetDvTmaxValue | setValue = 5000 | tvERROR_NONE | Should be successful |
| 03 | If SetDvTmaxValue fails, terminate the TV settings using TvTerm and return | None | None | Should be successful |
| 04 | Get the Dv Tmax Value using GetDvTmaxValue | getValue = address of integer variable | tvERROR_NONE | Should be successful |
| 05 | If GetDvTmaxValue fails, terminate the TV settings using TvTerm and return | None | None | Should be successful |
| 06 | Assert that the set value and the retrieved value are equal | setValue = 5000, getValue = retrieved value | setValue should be equal to getValue | Should be successful |
| 07 | Terminate the TV settings using TvTerm | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    Start(Start) --> Step1
    Step1{Call TvInit API} -->|Success| Step2
    Step1 -->|Failure| TestcaseFail1[Test case 38: Fail]
    Step2{Call SetDvTmaxValue API with value in range 0 to 10000} -->|Success| Step3
    Step2 -->|Failure| TestcaseFail2[Test case 38: Fail]
    Step3{Call GetDvTmaxValue API} -->|Success| Step4
    Step3 -->|Failure| TestcaseFail3[Test case 38: Fail]
    Step4{Verify retrieved value matches set value} -->|Success| Step5
    Step4 -->|Failure| TestcaseFail4[Test case 38: Fail]
    Step5{Call TvTerm API} -->|Success| End(End)
    Step5 -->|Failure| TestcaseFail5[Test case 38: Fail]
```


### Test 39

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_GetSupportedComponentColor`|
|Description|Verifies whether the test gets the supported component colors by comparing the test results with the platform-supported configurations file 'Sink-4K-TvSettings.yaml' using the path 'SupportedComponentColor' and loop through the indices.|
|Test Group|Module : 02|
|Test Case ID|039|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Invoke GetSupportedComponentColor() with valid address | blComponentColor = valid address | tvERROR_NONE | Should be successful |
| 03 | Compare the returned value with the value in the platform-supported configurations file | blComponentColor, "SupportedComponentColor" | Equal values | Should be successful |
| 04 | Loop through the indices of the returned value and check if the component color at each index is supported | blComponentColor = returned value | None | Should be successful |
| 05 | Terminate the TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit] -->|tvERROR_NONE| B[Declare integer variable]
    A -->|Failure| A1[Test case fail]
    B --> C[GetSupportedComponentColor]
    B -->|Failure| B1[Test case fail]
    C -->|tvERROR_NONE| D[Compare with Sink-4K-TvSettings.yaml]
    C -->|Failure| C1[Test case fail]
    D --> E[Loop through indices]
    D -->|Failure| D1[Test case fail]
    E --> F[TvTerm]
    F -->|tvERROR_NONE| G[Test case pass]
    F -->|Failure| F1[Test case fail]
```


### Test 40

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetComponentSaturation`|
|Description|Set and Get the component saturation by verifying whether the values are within the valid range (0 - 100). The retrieved value should match the set value. Get values are fetched from the  database.|
|Test Group|Module : 02|
|Test Case ID|40|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Set the CMS state to true using SetCMSState() | state = true | tvERROR_NONE | Should be successful |
| 03 | For each color component, set a random saturation value between 0 and 100 using SetCurrentComponentSaturation() | color = color component, saturation = random value between 0 and 100 | tvERROR_NONE | Should be successful |
| 04 | Get the current component saturation using GetCurrentComponentSaturation() | color = color component, saturation = pointer to saturation variable | tvERROR_NONE | Should be successful |
| 05 | Assert that the set saturation value matches the retrieved saturation value | setSaturation = set value, saturation = retrieved value | setSaturation should be equal to saturation | Should be successful |
| 06 | Terminate the TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit] -->|Success| B[SetCMSState(true)]
    B -->|Success| C[SetCurrentComponentSaturation(color, saturation)]
    C -->|Success| D[GetCurrentComponentSaturation(color)]
    D -->|Success, Saturation matches| E[SetCurrentComponentSaturation(next color, saturation)]
    E -->|Success| F[GetCurrentComponentSaturation(next color)]
    F -->|Success, Saturation matches| G[SetCurrentComponentSaturation(next color, saturation)]
    G -->|Success| H[GetCurrentComponentSaturation(next color)]
    H -->|Success, Saturation matches| I[TvTerm]
    A -->|Failure| J[Test case fail]
    B -->|Failure| K[Test case fail]
    C -->|Failure| L[Test case fail]
    D -->|Failure, Saturation doesn't match| M[Test case fail]
    E -->|Failure| N[Test case fail]
    F -->|Failure, Saturation doesn't match| O[Test case fail]
    G -->|Failure| P[Test case fail]
    H -->|Failure, Saturation doesn't match| Q[Test case fail]
    I -->|Failure| R[Test case fail]
```


### Test 41

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetComponentHue`|
|Description|Set and Get the Component Hue by verifying whether the values are within the valid range (0 - 100). The retrieved value should match the set value. Get values are fetched from the database.|
|Test Group|Module : 02|
|Test Case ID|041|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Set CMS state to true using SetCMSState() | state = true | tvERROR_NONE | Should be successful |
| 03 | Loop through each color and hue value. Set the current component hue using SetCurrentComponentHue() | color = tvDataColor_RED to tvDataColor_MAX, hue = 0 to 100 | tvERROR_NONE | Should be successful |
| 04 | Get the current component hue using GetCurrentComponentHue() | color = tvDataColor_RED to tvDataColor_MAX | tvERROR_NONE, hue value should match the set value | Should be successful |
| 05 | Terminate the TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit] -->|Success| B[SetCMSState(true)]
    B -->|Success| C[SetCurrentComponentHue(color, hue)]
    B -->|Failure| Bf[Test case fail]
    C -->|Success| D[Verify SetCurrentComponentHue returns tvERROR_NONE]
    C -->|Failure| Cf[Test case fail]
    D -->|Success| E[GetCurrentComponentHue(color)]
    D -->|Failure| Df[Test case fail]
    E -->|Success| F[Verify GetCurrentComponentHue returns tvERROR_NONE and hue matches]
    E -->|Failure| Ef[Test case fail]
    F -->|Success| G[Repeat for all colors]
    F -->|Failure| Ff[Test case fail]
    G --> H[TvTerm]
    H -->|Success| I[Test case success]
    H -->|Failure| Hf[Test case fail]
```



### Test 42

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetComponentLuma`|
|Description|Set and Gets the Component Luma by verifying whether the values are within the valid range (0 - 100). The retrieved value should match the set value. Get values are fetched from the database.|
|Test Group|Module : 02|
|Test Case ID|042|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Set CMS state to true using SetCMSState() | state = true | tvERROR_NONE | Should be successful |
| 03 | Loop through each color component. Set the luma value for the current color component using SetCurrentComponentLuma() | color = color component, lumaSet = 15 | tvERROR_NONE | Should be successful |
| 04 | Get the luma value for the current color component using GetCurrentComponentLuma() | color = color component | tvERROR_NONE, luma = lumaSet | Should be successful |
| 05 | Terminate the TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
A[TvInit()] -->|Success| B[SetCMSState(true)]
A -->|Failure| A1[Test case fail]
B -->|Success| C[For each color in tvDataComponentColor_t]
B -->|Failure| B1[Test case fail]
C --> D[SetCurrentComponentLuma(color, luma)]
D -->|Success| E[Verify return value is tvERROR_NONE]
D -->|Failure| D1[Test case fail]
E --> F[GetCurrentComponentLuma(color)]
F -->|Success| G[Verify return value is tvERROR_NONE]
F -->|Failure| F1[Test case fail]
G --> H[Verify luma value matches set value]
H --> C
C --> I[TvTerm()]
I -->|Success| J[Test case pass]
I -->|Failure| I1[Test case fail]
```


### Test 43

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetCMSState`|
|Description|Set and Gets the `CMS` State. The retrieved value should match the set value. Get values are retrieved from the database.|
|Test Group|Module : 02|
|Test Case ID|43|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Set the CMS state to true using SetCMSState() | enableCMSState = true | tvERROR_NONE | Should be successful |
| 03 | Get the CMS state using GetCMSState() | enableCMSState = address of enableCMSState variable | tvERROR_NONE, enableCMSState = true | Should be successful |
| 04 | Set the CMS state to false using SetCMSState() | enableCMSState = false | tvERROR_NONE | Should be successful |
| 05 | Get the CMS state using GetCMSState() | enableCMSState = address of enableCMSState variable | tvERROR_NONE, enableCMSState = false | Should be successful |
| 06 | Terminate the TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    Start(Start) --> Step1
    Step1{Call TvInit API} -->|tvERROR_NONE| Step2
    Step1 -->|Failure| TestcaseFail1[Test case 43 fail]
    Step2{Call SetCMSState API with true} -->|tvERROR_NONE| Step3
    Step2 -->|Failure| TestcaseFail2[Test case 43 fail]
    Step3{Call GetCMSState API, check true} -->|Success| Step4
    Step3 -->|Failure| TestcaseFail3[Test case 43 fail]
    Step4{Call SetCMSState API with false} -->|tvERROR_NONE| Step5
    Step4 -->|Failure| TestcaseFail4[Test case 43 fail]
    Step5{Call GetCMSState API, check false} -->|Success| Step6
    Step5 -->|Failure| TestcaseFail5[Test case 43 fail]
    Step6{Call TvTerm API} -->|tvERROR_NONE| End(End)
    Step6 -->|Failure| TestcaseFail6[Test case 43 fail]
```


### Test 44

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_TestGetPQParameters`|
|Description|To test the Get `PQ` Parameters, loop through the different video sources, video formats, and picture quality modes for all combinations and set the brightness, contrast, sharpness, and component saturation value (loop through different saturation colors) to 50%. For Tmax, set the value to 500, and for low latency, set it to 1. After setting these values, loop through the different video sources, video formats, and picture quality modes again, read back the GetPQ parameter values and ensure that all are set to the required values: brightness, contrast, sharpness, and component saturation at 50%, Tmax at 500, and low latency at 1.|
|Test Group|Module : 02|
|Test Case ID|044|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Loop through video sources, video formats, and PQ modes. Set brightness, contrast, saturation, hue, component saturation, Tmax value, and low latency state using respective APIs | videoSrcType = VIDEO_SOURCE_ANALOGUE to VIDEO_SOURCE_MAX, videoFormatType = VIDEO_FORMAT_NONE to VIDEO_FORMAT_MAX, pq_mode = 0 to PQ_MODE_MAX, value = 50 for brightness, contrast, saturation, hue, and component saturation, value = 500 for Tmax, value = 1 for low latency state | tvERROR_NONE | Should be successful |
| 03 | Loop through video sources, video formats, and PQ modes again. Get PQ parameters using GetPQParams() and verify the values | videoSrcType = VIDEO_SOURCE_ANALOGUE to VIDEO_SOURCE_MAX, videoFormatType = VIDEO_FORMAT_NONE to VIDEO_FORMAT_MAX, pq_mode = 0 to PQ_MODE_MAX, pqParamIndex = PQ_PARAM_BRIGHTNESS to PQ_PARAM_MAX | tvERROR_NONE, value = 50 for brightness, contrast, saturation, hue, and component saturation, value = 500 for Tmax, value = 1 for low latency state | Should be successful |
| 04 | Terminate TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit()] -->|Success| B{Loop through video sources, formats, PQ modes}
    A -->|Failure| A1[Test case fail]
    B -->|Success| C[SaveBrightness(), SaveContrast(), SaveSaturation(), SaveHue()]
    B -->|Failure| B1[Test case fail]
    C -->|Success| D[SetCurrentComponentSaturation()]
    C -->|Failure| C1[Test case fail]
    D -->|Success| E[SaveDvTmaxValue()]
    D -->|Failure| D1[Test case fail]
    E -->|Success| F[SaveLowLatencyState()]
    E -->|Failure| E1[Test case fail]
    F -->|Success| G{Loop through video sources, formats, PQ modes}
    F -->|Failure| F1[Test case fail]
    G -->|Success| H[GetPQParams()]
    G -->|Failure| G1[Test case fail]
    H -->|Success| I[TvTerm()]
    H -->|Failure| H1[Test case fail]
    I -->|Success| J[Test case success]
    I -->|Failure| I1[Test case fail]
```


### Test 45

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_GetTVGammaTarget`|
|Description|Get TV Gamma Target verifies the functionality of retrieving the target x and y coordinates for the panel gamma based on a given color temperature. It ensures that the returned coordinates are within the range of 0 to 1.0. Validate with various color temperatures (tvColorTemp_t).|
|Test Group|Module : 02|
|Test Case ID|045|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Loop through each color temperature in tvColorTemp_t and retrieve the target x and y coordinates for the panel gamma using GetTVGammaTarget() | colorTemp = tvColorTemp_STANDARD, tvColorTemp_WARM, tvColorTemp_COLD, tvColorTemp_USER, tvColorTemp_BOOST_STANDARD, tvColorTemp_BOOST_WARM, tvColorTemp_BOOST_COLD, tvColorTemp_BOOST_USER, tvColorTemp_SUPERCOLD, tvColorTemp_BOOST_SUPERCOLD | x and y coordinates should be within the range of 0 to 1.0 | Should be successful |
| 03 | Terminate TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    Start(Start) --> TvInit
    TvInit{Call TvInit API} -->|Return status is tvERROR_NONE| GetTVGammaTarget1
    TvInit -->|Return status is not tvERROR_NONE| TestcaseFail1[Test case fail]
    GetTVGammaTarget1{Call GetTVGammaTarget API with tvColorTemp_STANDARD} -->|x and y coordinates are within 0 to 1.0| GetTVGammaTarget2
    GetTVGammaTarget1 -->|x and y coordinates are not within 0 to 1.0| TestcaseFail2[Test case fail]
    GetTVGammaTarget2{Call GetTVGammaTarget API with tvColorTemp_WARM} -->|x and y coordinates are within 0 to 1.0| GetTVGammaTarget3
    GetTVGammaTarget2 -->|x and y coordinates are not within 0 to 1.0| TestcaseFail3[Test case fail]
    GetTVGammaTarget3{Call GetTVGammaTarget API with tvColorTemp_COLD} -->|x and y coordinates are within 0 to 1.0| GetTVGammaTarget4
    GetTVGammaTarget3 -->|x and y coordinates are not within 0 to 1.0| TestcaseFail4[Test case fail]
    GetTVGammaTarget4{Call GetTVGammaTarget API with tvColorTemp_USER} -->|x and y coordinates are within 0 to 1.0| GetTVGammaTarget5
    GetTVGammaTarget4 -->|x and y coordinates are not within 0 to 1.0| TestcaseFail5[Test case fail]
    GetTVGammaTarget5{Call GetTVGammaTarget API with tvColorTemp_BOOST_STANDARD} -->|x and y coordinates are within 0 to 1.0| GetTVGammaTarget6
    GetTVGammaTarget5 -->|x and y coordinates are not within 0 to 1.0| TestcaseFail6[Test case fail]
    GetTVGammaTarget6{Call GetTVGammaTarget API with tvColorTemp_BOOST_WARM} -->|x and y coordinates are within 0 to 1.0| GetTVGammaTarget7
    GetTVGammaTarget6 -->|x and y coordinates are not within 0 to 1.0| TestcaseFail7[Test case fail]
    GetTVGammaTarget7{Call GetTVGammaTarget API with tvColorTemp_BOOST_COLD} -->|x and y coordinates are within 0 to 1.0| GetTVGammaTarget8
    GetTVGammaTarget7 -->|x and y coordinates are not within 0 to 1.0| TestcaseFail8[Test case fail]
    GetTVGammaTarget8{Call GetTVGammaTarget API with tvColorTemp_BOOST_USER} -->|x and y coordinates are within 0 to 1.0| GetTVGammaTarget9
    GetTVGammaTarget8 -->|x and y coordinates are not within 0 to 1.0| TestcaseFail9[Test case fail]
    GetTVGammaTarget9{Call GetTVGammaTarget API with tvColorTemp_SUPERCOLD} -->|x and y coordinates are within 0 to 1.0| GetTVGammaTarget10
    GetTVGammaTarget9 -->|x and y coordinates are not within 0 to 1.0| TestcaseFail10[Test case fail]
    GetTVGammaTarget10{Call GetTVGammaTarget API with tvColorTemp_BOOST_SUPERCOLD} -->|x and y coordinates are within 0 to 1.0| TvTerm
    GetTVGammaTarget10 -->|x and y coordinates are not within 0 to 1.0| TestcaseFail11[Test case fail]
    TvTerm{Call TvTerm API} -->|Return status is tvERROR_NONE| End(End)
    TvTerm -->|Return status is not tvERROR_NONE| TestcaseFail12[Test case fail]
```


### Test 46

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetRGBPattern`|
|Description|Set and Gets the RGB Pattern within the range ( 0 - 255 ). The retrieved value should match the set value. Get values are retrieved from the database.|
|Test Group|Module : 02|
|Test Case ID|46|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Set the RGB pattern using SetRGBPattern() | r_set = 100, g_set = 150, b_set = 200 | tvERROR_NONE | Should be successful |
| 03 | Get the RGB pattern using GetRGBPattern() | r_get, g_get, b_get | tvERROR_NONE | Should be successful |
| 04 | Check if the retrieved RGB values match the set values | r_get, g_get, b_get | r_set, g_set, b_set | Should be successful |
| 05 | Terminate the TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit()] -->|Success| B[SetRGBPattern()]
    A -->|Failure| A1[Test case fail]
    B -->|Success| C[Verify SetRGBPattern() returns tvERROR_NONE]
    B -->|Failure| B1[Test case fail]
    C -->|Success| D[GetRGBPattern()]
    C -->|Failure| C1[Test case fail]
    D -->|Success| E[Verify GetRGBPattern() returns tvERROR_NONE]
    D -->|Failure| D1[Test case fail]
    E -->|Success| F[Check RGB values match]
    E -->|Failure| E1[Test case fail]
    F -->|Success| G[TvTerm()]
    F -->|Failure| F1[Test case fail]
    G -->|Success| H[Test case pass]
    G -->|Failure| G1[Test case fail]
```


### Test 47

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_SetAndGetGrayPattern`|
|Description|Set and Gets the Gray Pattern within the range ( 0 - 255 ). The retrieved value should match the set value. Get values are retrieved from the database.|
|Test Group|Module : 02|
|Test Case ID|47|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Set the Gamma Pattern Mode to true using SetGammaPatternMode() | Mode = true | tvERROR_NONE | Should be successful |
| 03 | Set the Gray Pattern using SetGrayPattern() | YUVValue = 100 | tvERROR_NONE | Should be successful |
| 04 | Get the Gray Pattern using GetGrayPattern() | get_YUVValue = valid buffer | tvERROR_NONE, YUVValue = 100 | Should be successful |
| 05 | If the status is not tvERROR_NONE or the set and get YUVValues do not match, terminate the TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit] -->|tvERROR_NONE| B[SetGammaPatternMode]
    A -->|Failure| A1[Test case fail]
    B -->|tvERROR_NONE| C[SetGrayPattern]
    B -->|Failure| B1[Test case fail]
    C -->|tvERROR_NONE| D[GetGrayPattern]
    C -->|Failure| C1[Test case fail]
    D -->|tvERROR_NONE, YUVValue matches| E[TvTerm]
    D -->|Failure| D1[Test case fail]
    E -->|tvERROR_NONE| F[Test case success]
    E -->|Failure| E1[Test case fail]
```


### Test 48

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_RetrieveOpenCircuitStatus`|
|Description|Verifies the functionality of retrieving the current open circuit status of the backlight hardware. It ensures that the returned status indicates whether any `LED` fault is detected.|
|Test Group|Module : 02|
|Test Case ID|48|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize the TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Retrieve the open circuit status using GetOpenCircuitStatus() | status = valid pointer | tvERROR_NONE | Should be successful |
| 03 | Check if the status indicates an LED fault | status >= 1 | LED fault detected | Should be successful |
| 04 | Check if the status indicates no LED fault | status = 0 | No LED fault detected | Should be successful |
| 05 | Check if the status value is invalid | status < 0 | Invalid status value | Should fail |
| 06 | Terminate the TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit()] -->|tvERROR_NONE| B[GetOpenCircuitStatus()]
    A -->|!=tvERROR_NONE| A1[Test case fail]
    B -->|tvERROR_NONE| C[Check returned status]
    B -->|!=tvERROR_NONE| B1[Test case fail]
    C -->|Status >= 1 or Status == 0| D[TvTerm()]
    C -->|Status < 0 or Status > 1| C1[Test case fail]
    D -->|tvERROR_NONE| E[Test case pass]
    D -->|!=tvERROR_NONE| D1[Test case fail]
```


### Test 49

|Title|Details|
|--|--|
|Function Name|`test_l2_tvSettings_EnableAndGetDynamicContrast`|
|Description|Enable Dynamic Contrast - Verifies the functionality of enabling or disabling the dynamic contrast module. Check the status by get dynamic contrast.|
|Test Group|Module : 02|
|Test Case ID|49|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Initialize TV using TvInit() | None | tvERROR_NONE | Should be successful |
| 02 | Enable Dynamic Contrast using EnableDynamicContrast() | Enable = true | tvERROR_NONE | Should be successful |
| 03 | Get Dynamic Contrast status using GetDynamicContrast() | isDynamicContrastEnabled = valid buffer | tvERROR_NONE, "enabled" | Should be successful |
| 04 | Disable Dynamic Contrast using EnableDynamicContrast() | Enable = false | tvERROR_NONE | Should be successful |
| 05 | Get Dynamic Contrast status using GetDynamicContrast() | isDynamicContrastEnabled = valid buffer | tvERROR_NONE, "disabled" | Should be successful |
| 06 | Terminate TV using TvTerm() | None | tvERROR_NONE | Should be successful |


```mermaid
graph TB
    A[TvInit()] -->|tvERROR_NONE| B[EnableDynamicContrast(true)]
    A -->|!=tvERROR_NONE| A1[Test case fail]
    B -->|tvERROR_NONE| C[GetDynamicContrast()]
    B -->|!=tvERROR_NONE| B1[Test case fail]
    C -->|tvERROR_NONE and output=="enabled"| D[EnableDynamicContrast(false)]
    C -->|!=tvERROR_NONE or output!="enabled"| C1[Test case fail]
    D -->|tvERROR_NONE| E[GetDynamicContrast()]
    D -->|!=tvERROR_NONE| D1[Test case fail]
    E -->|tvERROR_NONE and output=="disabled"| F[TvTerm()]
    E -->|!=tvERROR_NONE or output!="disabled"| E1[Test case fail]
    F -->|tvERROR_NONE| G[Test case success]
    F -->|!=tvERROR_NONE| F1[Test case fail]
```


