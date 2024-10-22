# tvSettings HAL L3 Python Test Procedure

## Table of Contents

- [Acronyms, Terms and Abbreviations](#acronyms-terms-and-abbreviations)
- [Setting Up Test Environment](#setting-up-test-environment)
- [Streams Required](#streams-required)
- [Test Cases](#test-cases)
  - [tvSettings_test01_CheckVideoFormat.py](#tvsettings_test01_checkvideoformatpy)
  - [tvSettings_test02_CheckVideoResolution.py](#tvsettings_test02_checkvideoresolutionpy)
  - [tvSettings_test03_CheckVideoFrameRate.py](#tvsettings_test03_checkvideoframeratepy)
  - [tvSettings_test04_CheckVideoSource.py](#tvsettings_test04_checkvideosourcepy)
  - [tvSettings_test05_Backlight.py](#tvsettings_test05_backlightpy)
  - [tvSettings_test06_BacklightFade.py](#tvsettings_test06_backlightfadepy)
  - [tvSettings_test07_BacklightMode.py](#tvsettings_test07_backlightmodepy)
  - [tvSettings_test08_TVDimmingMode.py](#tvsettings_test08_tvdimmingmodepy)
  - [tvSettings_test09_LocalDimmingMode.py](#tvsettings_test09_localdimmingmodepy)
  - [tvSettings_test10_Brightness.py](#tvsettings_test10_brightnesspy)
  - [tvSettings_test11_Contrast.py](#tvsettings_test11_contrastpy)
  - [tvSettings_test12_Sharpness.py](#tvsettings_test12_sharpnesspy)
  - [tvSettings_test13_Saturation.py](#tvsettings_test13_saturationpy)
  - [tvSettings_test14_Hue.py](#tvsettings_test14_huepy)
  - [tvSettings_test15_ColorTemp.py](#tvsettings_test15_colortemppy)
  - [tvSettings_test16_AspectRatio.py](#tvsettings_test16_aspectratiopy)
  - [tvSettings_test17_DynamicContrast.py](#tvsettings_test17_dynamiccontrastpy)
  - [tvSettings_test18_DynamicGamma.py](#tvsettings_test18_dynamicgammapy)
  - [tvSettings_test19_DolbyVision.py](#tvsettings_test19_dolbyvisionpy)
  - [tvSettings_test20_PictureMode.py](#tvsettings_test20_picturemodepy)
  - [tvSettings_test21_ColorTempRgain.py](#tvsettings_test21_colortemprgainpy)
  - [tvSettings_test22_ColorTempGgain.py](#tvsettings_test22_colortempggainpy)
  - [tvSettings_test23_ColorTempBgain.py](#tvsettings_test23_colortempbgainpy)
  - [tvSettings_test24_colorTempRpostOffset.py](#tvsettings_test24_colortemprpostoffsetpy)
  - [tvSettings_test25_ColorTempGpostOffset.py](#tvsettings_test25_colortempgpostoffsetpy)
  - [tvSettings_test26_ColorTempBpostOffset.py](#tvsettings_test26_colortempbpostoffsetpy)
  - [tvSettings_test27_WBCalibration.py](#tvsettings_test27_wbcalibrationpy)
  - [tvSettings_test28_GammaTable.py](#tvsettings_test28_gammatablepy)
  - [tvSettings_test29_DVTmax.py](#tvsettings_test29_dvtmaxpy)
  - [tvSettings_test30_ComponentSaturation.py](#tvsettings_test30_componentsaturationpy)
  - [tvSettings_test31_componentHue.py](#tvsettings_test31_componenthuepy)
  - [tvSettings_test32_ComponentLuma.py](#tvsettings_test32_componentlumapy)
  - [tvSettings_test33_EnableGammaMode.py](#tvsettings_test33_enablegammamodepy)
  - [tvSettings_test34_SetGammaPattern.py](#tvsettings_test34_setgammapatternpy)
  - [tvSettings_test35_RGBPattern.py](#tvsettings_test35_rgbpatternpy)
  - [tvSettings_test36_GrayPattern.py](#tvsettings_test36_graypatternpy)
  - [tvSettings_test37_EnableLDIMPixelCompensation.py](#tvsettings_test37_enableldimpixelcompensationpy)
  - [tvSettings_test38_EnableLDIM.py](#tvsettings_test38_enableldimpy)
  - [tvSettings_test39_SetBacklightTestMode.py](#tvsettings_test39_setbacklighttestmodepy)
  - [tvSettings_test40_EnableDynamicContrast.py](#tvsettings_test40_enabledynamiccontrastpy)
  - [tvSettings_test41_EnableLocalContrast.py](#tvsettings_test41_enablelocalcontrastpy)
  - [tvSettings_test42_SaveBacklightValues.py](#tvsettings_test42_savebacklightvaluespy)
  - [tvSettings_test43_SaveTVDimmingMode.py](#tvsettings_test43_savetvdimmingmodepy)
  - [tvSettings_test44_SaveLocalDimmingLevel.py](#tvsettings_test44_savelocaldimminglevelpy)
  - [tvSettings_test45_SaveBrightness.py](#tvsettings_test45_savebrightnesspy)
  - [tvSettings_test46_SaveContrast.py](#tvsettings_test46_savecontrastpy)
  - [tvSettings_test47_SaveSharpness.py](#tvsettings_test47_savesharpnesspy)
  - [tvSettings_test48_saveSaturation.py](#tvsettings_test48_savesaturationpy)
  - [tvSettings_test49_saveHue.py](#tvsettings_test49_savehuepy)
  - [tvSettings_test50_saveColorTemperature.py](#tvsettings_test50_savecolortemperaturepy)
  - [tvSettings_test51_saveAspectRatio.py](#tvsettings_test51_saveaspectratiopy)
  - [tvSettings_test52_saveDolbyVision.py](#tvsettings_test52_savedolbyvisionpy)
  - [tvSettings_test53_savePictureMode.py](#tvsettings_test53_savepicturemodepy)
  - [tvSettings_test54_saveCMS.py](#tvsettings_test54_savecmspy)
  - [tvSettings_test55_saveGammaTable.py](#tvsettings_test55_savegammatablepy)

## Acronyms, Terms and Abbreviations

- `HAL`    - Hardware Abstraction Layer
- `L3`     - Level 3 Testing
- `RAFT`   - Rapid Automation Framework for Testing
- `YAML`   - YAML Ain't Markup Language

## Setting Up Test Environment

To execute `HAL` `L3` Python test cases, need a Python environment. Follow these steps mentioned in [HPK Public Documentation](https://github.com/rdkcentral/rdk-hpk-documentation/blob/main/README.md)

### Update Configuration Files

#### Rack Configuration File

Example Rack configuration File: `ut/host/tests/configs/example_rack_config.yml`

For more details refer [RAFT](https://github.com/rdkcentral/python_raft/blob/1.0.0/README.md) and [example_rack_config.yml](https://github.com/rdkcentral/python_raft/blob/1.0.0/examples/configs/example_rack_config.yml)

In this file, update the configuration to define the console sessions for the `DUT` and the outbound settings:

|Console Session|Description|
|---------------|-----------|
|default|Downloads the streams required for test cases|
|ssh_player|Plays the stream required for test case|
|ssh_hal_test|Executes the `HAL` binary for the test case|

```yaml
rackConfig:
  - dut:
      ip: "XXX.XXX.XXX.XXX"  # IP Address of the device
      description: "panel device under test"
      platform: "panel"
      consoles:
        - default:
            type: "ssh"
            port: 10022
            username: "root"
            ip: "XXX.XXX.XXX" # IP address of the device
            password: ' '
        - ssh_player:
            type: "ssh"
            port: 10022
            username: "root"
            ip: "XXX.XXX.XXX" # IP address of the device
            password: ' '
        - ssh_hal_test:
            type: "ssh"
            port: 10022
            username: "root"
            ip: "XXX.XXX.XXX" # IP address of the device
            password: ' '
      outbound:
        download_url: "tftp://tftp-server.com/rack1/slot1/"    # Download location for the CPE device
        upload_url: "sftp://server-address/home/workspace/tftp/rack1/slot1/" # Upload location
        upload_url_base_dir: "sftp://server-address/home/workspace/tftp/rack1/slot1"
        httpProxy:   # Local proxy if required
        workspaceDirectory: './logs/workspace'   # Local working directory

```

#### Device Configuration File

Example Device configuration File: `ut/host/tests/configs/deviceConfig.yml`

For more details refer [RAFT](https://github.com/rdkcentral/python_raft/blob/1.0.0/README.md) and [example_device_config.yml](https://github.com/rdkcentral/python_raft/blob/1.0.0/examples/configs/example_device_config.yml)

Update the target directory where `HAL` binaries will be copied into the device. Also, map the profile to the source/sink settings `YAML` file path.

Update the URL `streams_download_url` from which the streams are fetched.

Ensure the platform should match with the `DUT` platform in [Rack Configuration](#rack-configuration-file)

```yaml
deviceConfig:
    cpe1:
        platform: "linux"
        model: "uk"
        soc_vendor: "intel"
        target_directory: "/tmp/"  # Target Directory on device
        prompt: "" # Prompt string on console
        test:
            profile: "../../../../profiles/sink/Sink_4K_TvSettings.yaml"
            streams_download_url: "<URL_Path>" #URL path from which the streams are downloaded to the device
```

#### Test Setup Configuration File

Example Test Setup configuration File: `ut/host/tests/tvSettings_L3_Tests/tvSettings_L3_testSetup.yml`

Provide the streams for each test case. This path is appended with `streams_download_url` entry from [Device Configuration File](#device-configuration-file)

If a test case requires multiple streams or needs to be validated using several streams, ensure that all necessary streams are added sequentially for that specific test case.

```yaml
tvSettings:  # Prefix must always exist
  description: "tvSettings test setup"
  assets:
    device:
      defaults: &defaults
        artifacts:
          - "<URL Path>/bin/hal_test"
          - "<URL Path>/bin/libut_control.so"
          - "<URL Path>/bin/Sink_4K_TvSettings.yaml"
          - "<URL Path>/bin/run.sh"
        execute:
          - "chmod +x <PATH on Device>/hal_test"
          - "chmod +x <PATH on Device>/run.sh"
        streams:
      test01_CheckVideoFormat:
        <<: *defaults
        streams:
          -  "Streams/Colors_sdr.mp4"
          -  "Streams/Colors_hdr.mp4"
          -  "Streams/Colors_hlg.mp4"
      test02_CheckVideoResolution:
        <<: *defaults
        streams:
          -  "Streams/Colors_sdr.mp4"
          -  "Streams/Colors_hdr.mp4"
          -  "Streams/Colors_hlg.mp4"
      test03_CheckVideoFrameRate:
        <<: *defaults
        streams:
          -  "Streams/Colors_sdr.mp4"
          -  "Streams/Colors_hdr.mp4"
          -  "Streams/Colors_hlg.mp4"
      test04_CheckVideoSource:
```

#### Test Suite Configuration

Example Test Setup configuration File: `ut/host/tests/Classes/tvSettings_test_suite.yml`

Update the execute command according to the device path where `HAL` binaries are copied.

```yaml
tvSettings:  # Prefix must always exist
    description: "tvSettings testing profile / menu system for UT"
    test:
        execute: "<PATH on Device>run.sh -p <PATH on Device>Sink_4K_TvSettings.yaml" #Execute command
        type: UT-C # C (UT-C Cunit) / C++ (UT-G (g++ ut-core gtest backend))
```

## Run Test Cases

Once the environment is set up, you can execute the test cases with the following command

```bash
python <TestCaseName.py> --config </PATH>/ut/host/tests/configs/example_rack_config.yml --deviceConfig </PATH>/ut/host/tests/configs/deviceConfig.yml
```

## Streams Required

Refer [tvSettings_L3_Low-Level_Test_Spec.md](./tv-settings_L3_Low_Level_Test_Spec.md#tvsettings-stream-requirement) for the stream details

## Test Cases

### tvSettings_test01_CheckVideoFormat.py

#### User Input Required - test01

**No**: This test runs automatically without any need for user input.

#### Acceptance Criteria - test01

The device should play each video format stream accurately, and the callback should verify each format. When playback of non-SDR streams stops, the device should trigger a default SDR callback.

#### Expected Results - test01

The test initializes the TV settings, iterates through multiple video formats, and confirms the correct video format and callback status for each playback.

Success Criteria

- The device should correctly display each specified video format during playback.
- The default SDR callback should activate after playback stops on non-SDR streams.

#### Test Steps - test01

- **Initiate the Test:**

  - Run the Python file: **`tvSettings_test01_CheckVideoFormat.py`**
  - The test will automatically download each required video stream to the target directory, initialize TV settings, and begin playback.

- **Video Format Verification:**

  - For each video format, the test:
    - Downloads the stream.
    - Plays the stream and logs the current video format.
    - Retrieves the video format callback status for validation.

- **Playback Stop and SDR Callback Verification:**

  - After each playback, the test:
    - Stops the stream.
    - Confirms and logs that the SDR callback activates when stopping non-SDR streams.

- **Cleanup:**

  - The test deletes each downloaded stream after verifying playback.

- **Test Conclusion:**

  Upon completing playback and callback checks for all video formats, the test concludes and logs the final results based on automatic validations.

### tvSettings_test02_CheckVideoResolution.py

#### User Input Required - test02

**No**: This test runs automatically without any need for user input.

#### Acceptance Criteria - test02

The device should play each video resolution stream accurately, and the callback should verify each resolution setting.

#### Expected Results - test02

The test initializes the TV settings, iterates through multiple video resolutions, and confirms the correct video resolution and callback status for each playback.

Success Criteria

- The device should correctly display each specified video resolution during playback.
- The correct video resolution callback should activate for the stream.

#### Test Steps - test02

- **Initiate the Test:**

  - Run the Python file: **`tvSettings_test02_CheckVideoResolution.py`**
  - The test will automatically download each required video stream to the target directory, initialize TV settings, and begin playback.

- **Video Resolution Verification:**

  - For each video resolution, the test:
    - Downloads the stream.
    - Plays the stream and logs the current video resolution.
    - Retrieves and logs the video resolution callback status for validation.

- **Cleanup:**

  - The test deletes each downloaded stream after verifying playback.

- **Test Conclusion:**

  Upon completing playback and callback checks for all video resolutions, the test concludes and logs the final results based on automatic validations.

### tvSettings_test03_CheckVideoFrameRate.py

#### User Input Required - test03

**No**: This test runs automatically without any need for user input.

#### Acceptance Criteria - test03

The device should play each video frame rate stream accurately, and the callback should verify each frame rate setting.

#### Expected Results - test03

The test initializes the TV settings, iterates through multiple video frame rates, and confirms the correct video frame rate and callback status for each playback.

Success Criteria

- The device should correctly display each specified video frame rate during playback.
- The correct video frame rate callback should activate for each stream.

#### Test Steps - test03

- **Initiate the Test:**

  - Run the Python file: **`tvSettings_test03_CheckVideoFrameRate.py`**
  - The test will automatically download each required video stream to the target directory, initialize TV settings, and begin playback.

- **Video Frame Rate Verification:**

  - For each video frame rate, the test:
    - Downloads the stream.
    - Plays the stream and logs the current frame rate.
    - Retrieves and logs the video frame rate callback status for validation.

- **Cleanup:**

  - The test deletes each downloaded stream after verifying playback.

- **Test Conclusion:**

  Upon completing playback and callback checks for all video frame rates, the test concludes and logs the final results based on automatic validations.

### tvSettings_test04_CheckVideoSource.py

#### User Input Required - test04

**No**: This test runs automatically without any need for user input.

#### Acceptance Criteria - test04

The device should play each video source stream accurately, and the test should verify that the correct video source is active.

#### Expected Results - test04

The test initializes the TV settings, iterates through multiple video sources, and confirms the correct video source for the stream playback.

Success Criteria

- The device should correctly display each specified video source during playback.
- The correct video source should be verified for the stream.

#### Test Steps - test04

- **Initiate the Test:**

  - Run the Python file: **`tvSettings_test04_CheckVideoSource.py`**
  - The test will automatically download each required video stream to the target directory, initialize TV settings, and begin playback.

- **Video Source Verification:**

  - For each video source, the test:
    - Plays the stream.
    - Retrieves and logs the current video source status for validation.

- **Cleanup:**

  - The test stops playback after verifying each video source.

- **Test Conclusion:**

  Upon completing playback and source checks for all video sources, the test concludes and logs the final results based on automatic validations.

### tvSettings_test05_Backlight.py

#### User Input Required - test05

**Yes**: This test requires user input to verify whether the backlight level has been applied. The user will be prompted with a Yes/No question during the test execution.

#### Acceptance Criteria - test05

The device should adjust the backlight levels correctly as specified, and the user should confirm that the changes are applied.

#### Expected Results - test05

The test initializes the TV settings, iterates through defined backlight levels, and confirms the applied backlight level through user input during the playback of the stream.

Success Criteria

- The backlight levels should change according to the specified settings.
- The user should confirm whether the backlight change is applied for each specified level.

#### Test Steps - test05

- **Initiate the Test:**

  - Run the Python file: **`tvSettings_test05_Backlight.py`**
  - The test will automatically initialize the TV settings and begin playback of the designated streams.

- **Backlight Level Verification:**

  - For the stream, the test:
    - Plays the stream.
    - Sets the backlight level for each predefined level.
    - Prompts the user with a question:
      - **"Has backlight level {backlight} applied? (Y/N):"**
      - The user must respond with **Y** for Yes or **N** for No.

- **Logging Results:**

  - The test logs the result of the user input for each backlight level and stream.

- **Cleanup:**

  - The test stops playback after verifying each backlight level.

- **Test Conclusion:**

  Upon completing playback and verification of all backlight levels, the test concludes and logs the final results based on user confirmations.

### tvSettings_test06_BacklightFade.py

#### User Input Required - test06

**Yes**: This test requires user input to verify whether the BacklightFade effect has been applied. The user will be prompted with a Yes/No question during the test execution.

#### Acceptance Criteria - test06

The device should apply the backlight fade effect as specified, and the user should confirm that the fade has occurred according to the given parameters.

#### Expected Results - test06

The test initializes the TV settings, iterates through defined backlight fade values and durations, and confirms the applied backlight fade effect through user input during the playback of the stream.

Success Criteria

- The backlight should fade from the specified starting value to the ending value within the defined duration.
- The user should confirm whether the backlight fade effect has been applied for each specified transition.

#### Test Steps - test06

- **Initiate the Test:**

  - Run the Python file: **`tvSettings_test06_BacklightFade.py`**
  - The test will automatically initialize the TV settings and begin playback of the designated streams.

- **Backlight Fade Level Verification:**

  - For the stream, the test:
    - Sets up backlight fade transitions between defined values.
    - Plays the stream for a brief period to ensure visibility of the fade effect.
    - Prompts the user with a question:
      - **"Has BacklightFade from {fromVal} to {toVal} with duration {fadeDuration} ms applied? (Y/N):"**
      - The user must respond with **Y** for Yes or **N** for No.

- **Logging Results:**

  - The test logs the result of the user input for each backlight fade transition and stream.

- **Cleanup:**

  - The test stops playback after verifying each backlight fade operation.

- **Test Conclusion:**

  Upon completing playback and verification of all backlight fade operations, the test concludes and logs the final results based on user confirmations.

### tvSettings_test07_BacklightMode.py

#### User Input Required - test07

**Yes**: This test requires user input to confirm if the BacklightMode setting has been correctly applied. The user will be prompted with a Yes/No question during the test execution for each backlight mode setting.

#### Acceptance Criteria - test07

The device should apply the specified backlight mode as configured, and the user should verify that the mode change has been applied correctly.

#### Expected Results - test07

The test initializes the TV settings, iterates through defined backlight modes, and verifies the application of each mode during the playback of the stream by prompting the user.

Success Criteria

- The specified backlight mode should be set and visible on the device.
- The user should confirm whether each backlight mode has been correctly applied for the stream.

#### Test Steps - test07

- **Initiate the Test:**

  - Run the Python file: **`tvSettings_test07_BacklightMode.py`**
  - The test automatically initializes the TV settings and begins playback of the designated streams.

- **Backlight Mode Verification:**

  - For the stream, the test:
    - Sets up each defined backlight mode.
    - Plays the stream for a brief period to ensure visibility of the backlight mode effect.
    - Prompts the user with a question:
      - **"Has BacklightMode level {backlightMode} applied? (Y/N):"**
      - The user must respond with **Y** for Yes or **N** for No.

- **Logging Results:**

  - The test logs the result of the user input for each backlight mode level and stream.

- **Cleanup:**

  - The test stops playback after verifying each backlight mode level.

- **Test Conclusion:**

  Upon completing playback and verification of all backlight mode levels, the test concludes and logs the final results based on user confirmations.

### tvSettings_test08_TVDimmingMode.py

#### User Input Required - test08

**Yes**: This test requires user input to confirm if the TV Dimming Mode setting has been correctly applied. During the test execution, the user will be prompted with a Yes/No question to verify each TV Dimming Mode level for the stream.

#### Acceptance Criteria - test08

The device should apply the specified TV Dimming Mode as configured, and the user should verify that the mode change has been applied accurately.

#### Expected Results - test08

The test initializes the TV settings, iterates through defined TV Dimming Modes, and verifies the application of each mode during playback of the stream through user prompts.

Success Criteria

- The specified TV Dimming Mode should be set and visible on the device.
- The user should confirm whether each TV Dimming Mode level has been correctly applied for the stream.

#### Test Steps - test08

- **Initiate the Test:**

  - Run the Python file: **`tvSettings_test08_TVDimmingMode.py`**
  - The test automatically initializes the TV settings and begins playback of the designated streams.

- **TV Dimming Mode Verification:**

  - For the stream, the test:
    - Sets up each defined TV Dimming Mode level.
    - Plays the stream for a brief period to ensure visibility of the TV Dimming Mode effect.
    - Prompts the user with a question:
      - **"Has TVDimmingMode level {tvDimmingMode} applied? (Y/N):"**
      - The user must respond with **Y** for Yes or **N** for No.

- **Logging Results:**

  - The test logs the result of the user input for each TV Dimming Mode level and stream.

- **Cleanup:**

  - The test stops playback after verifying each TV Dimming Mode level.

- **Test Conclusion:**

  Upon completing playback and verification of all TV Dimming Mode levels, the test concludes and logs the final results based on user confirmations.

### tvSettings_test09_LocalDimmingMode.py

#### User Input Required - test09

**Yes**: This test requires user input to confirm if the Local Dimming Level setting has been applied correctly. The user will be prompted with a Yes/No question to verify each Local Dimming Level for each stream.

#### Acceptance Criteria - test09

The device should apply the specified Local Dimming Level as configured, and the user should verify that the mode change has been accurately applied.

#### Expected Results - test09

The test initializes the TV settings, iterates through defined Local Dimming Levels, and verifies the application of each mode during playback of each stream through user prompts.

Success Criteria

- The specified Local Dimming Level should be set and visibly applied on the device.
- The user should confirm whether each Local Dimming Level has been correctly applied for each stream.

#### Test Steps - test09

1. **Initiate the Test:**

   - Run the Python file: **`tvSettings_test09_LocalDimmingLevel.py`**
   - The test will automatically initialize the TV settings and begin playback of the designated streams.

2. **Local Dimming Level Verification:**

   - For each stream, the test:
     - Sets up each defined Local Dimming Level.
     - Plays the stream briefly to allow for visible confirmation of the Local Dimming Level effect.
     - Prompts the user with a Yes/No question to confirm the level:
       - **"Has Local Dimming Level {localDimmingLevel} applied? (Y/N):"**
       - The user should respond with **Y** for Yes if the level is applied correctly or **N** for No if it is not.

3. **Logging Results:**

   - The test logs the result of each user confirmation for each Local Dimming Level and stream.

4. **Cleanup:**

   - The test stops playback after each Local Dimming Level verification.

5. **Test Conclusion:**

   After playback and verification of all Local Dimming Levels are completed, the test concludes and logs final results based on user input.

#### Note

Ensure that you monitor the screen for visible confirmation of the Local Dimming Level changes before answering each prompt.

### tvSettings_test10_Brightness.py

#### User Input Required - test10

**Yes**: This test requires user input to confirm if the Brightness level setting has been applied correctly. The user will be prompted with a Yes/No question to verify each brightness level for each stream.

#### Acceptance Criteria - test10

The device should apply the specified Brightness level as configured, and the user should verify that the brightness adjustment has been accurately applied.

#### Expected Results - test10

The test initializes the TV settings, iterates through defined brightness levels, and verifies the application of each level during playback of each stream through user prompts.

Success Criteria

- The specified Brightness level should be set and visibly applied on the device.
- The user should confirm whether each Brightness level has been correctly applied for each stream.

#### Test Steps - test10

1. **Initiate the Test:**

   - Run the Python file: **`tvSettings_test10_Brightness.py`**
   - The test will automatically initialize the TV settings and begin playback of the designated streams.

2. **Brightness Level Verification:**

   - For each stream, the test:
     - Iterates through each defined brightness level in the list `[0, 25, 50, 75, 100, 50]`.
     - Plays the stream briefly to allow for visible confirmation of the brightness change.
     - Prompts the user with a Yes/No question to confirm the level:
       - **"Has brightness level {brightness} applied? (Y/N):"**
       - The user should respond with **Y** for Yes if the brightness level is applied correctly or **N** for No if it is not.

3. **Logging Results:**

   - The test logs the result of each user confirmation for each brightness level and stream.

4. **Cleanup:**

   - The test stops playback after each brightness level verification.

5. **Test Conclusion:**

   After playback and verification of all brightness levels are completed, the test concludes and logs final results based on user input.

### tvSettings_test11_Contrast.py

#### User Input Required - test11

**Yes**: This test requires user input to confirm if the Contrast level setting has been applied correctly. The user will be prompted with a Yes/No question to verify each contrast level for each stream.

#### Acceptance Criteria - test11

The device should apply the specified Contrast level as configured, and the user should verify that the contrast adjustment has been accurately applied.

#### Expected Results - test11

The test initializes the TV settings, iterates through defined contrast levels, and verifies the application of each level during playback of each stream through user prompts.

Success Criteria

- The specified Contrast level should be set and visibly applied on the device.
- The user should confirm whether each Contrast level has been correctly applied for each stream.

#### Test Steps - test11

1. **Initiate the Test:**

   - Run the Python file: **`tvSettings_test11_Contrast.py`**
   - The test will automatically initialize the TV settings and begin playback of the designated streams.

2. **Contrast Level Verification:**

   - For each stream, the test:
     - Iterates through each defined contrast level in the list `[0, 25, 50, 75, 100, 50]`.
     - Plays the stream briefly to allow for visible confirmation of the contrast change.
     - Prompts the user with a Yes/No question to confirm the level:
       - **"Has contrast level {contrast} applied? (Y/N):"**
       - The user should respond with **Y** for Yes if the contrast level is applied correctly or **N** for No if it is not.

3. **Logging Results:**

   - The test logs the result of each user confirmation for each contrast level and stream.

4. **Cleanup:**

   - The test stops playback after each contrast level verification.

5. **Test Conclusion:**

   After playback and verification of all contrast levels are completed, the test concludes and logs final results based on user input.

### tvSettings_test12_Sharpness.py

#### User Input Required - test12

**Yes**: This test requires user input to confirm if the Sharpness level setting has been applied correctly. The user will be prompted with a Yes/No question to verify each sharpness level for each stream.

#### Acceptance Criteria - test12

The device should apply the specified Sharpness level as configured, and the user should verify that the sharpness adjustment has been accurately applied.

#### Expected Results - test12

The test initializes the TV settings, iterates through defined sharpness levels, and verifies the application of each level during playback of each stream through user prompts.

Success Criteria

- The specified Sharpness level should be set and visibly applied on the device.
- The user should confirm whether each Sharpness level has been correctly applied for each stream.

#### Test Steps - test12

1. **Initiate the Test:**

   - Run the Python file: **`tvSettings_test12_Sharpness.py`**
   - The test will automatically initialize the TV settings and begin playback of the designated streams.

2. **Sharpness Level Verification:**

   - For each stream, the test:
     - Iterates through each defined sharpness level in the list `[0, 25, 50, 75, 100, 50]`.
     - Plays the stream briefly to allow for visible confirmation of the sharpness change.
     - Prompts the user with a Yes/No question to confirm the level:
       - **"Has sharpness level {sharpness} applied? (Y/N):"**
       - The user should respond with **Y** for Yes if the sharpness level is applied correctly or **N** for No if it is not.

3. **Logging Results:**

   - The test logs the result of each user confirmation for each sharpness level and stream.

4. **Cleanup:**

   - The test stops playback after each sharpness level verification.

5. **Test Conclusion:**

   After playback and verification of all sharpness levels are completed, the test concludes and logs final results based on user input.

### tvSettings_test13_Saturation.py

#### User Input Required - test13

**Yes**: This test requires user input to confirm if the Saturation level setting has been applied correctly. The user will be prompted with a Yes/No question to verify each saturation level for each stream.

#### Acceptance Criteria - test13

The device should apply the specified Saturation level as configured, and the user should verify that the saturation adjustment has been accurately applied.

#### Expected Results - test13

The test initializes the TV settings, iterates through defined saturation levels, and verifies the application of each level during playback of each stream through user prompts.

Success Criteria

- The specified Saturation level should be set and visibly applied on the device.
- The user should confirm whether each Saturation level has been correctly applied for each stream.

#### Test Steps - test13

1. **Initiate the Test:**

   - Run the Python file: **`tvSettings_test13_Saturation.py`**
   - The test will automatically initialize the TV settings and begin playback of the designated streams.

2. **Saturation Level Verification:**

   - For each stream, the test:
     - Iterates through each defined saturation level in the list `[0, 25, 50, 75, 100, 50]`.
     - Plays the stream briefly to allow for visible confirmation of the saturation change.
     - Prompts the user with a Yes/No question to confirm the level:
       - **"Has saturation level {saturation} applied? (Y/N):"**
       - The user should respond with **Y** for Yes if the saturation level is applied correctly or **N** for No if it is not.

3. **Logging Results:**

   - The test logs the result of each user confirmation for each saturation level and stream.

4. **Cleanup:**

   - The test stops playback after each saturation level verification.

5. **Test Conclusion:**

   After playback and verification of all saturation levels are completed, the test concludes and logs final results based on user input.

### tvSettings_test14_Hue.py

#### User Input Required - test14

**Yes**: This test requires user input to confirm if the Hue level setting has been applied correctly. The user will be prompted with a Yes/No question to verify each hue level for each stream.

#### Acceptance Criteria - test14

The device should apply the specified Hue level as configured, and the user should verify that the hue adjustment has been accurately applied.

#### Expected Results - test14

The test initializes the TV settings, iterates through defined hue levels, and verifies the application of each level during playback of each stream through user prompts.

Success Criteria

- The specified Hue level should be set and visibly applied on the device.
- The user should confirm whether each Hue level has been correctly applied for each stream.

#### Test Steps - test14

1. **Initiate the Test:**

   - Run the Python file: **`tvSettings_test14_Hue.py`**
   - The test will automatically initialize the TV settings and begin playback of the designated streams.

2. **Hue Level Verification:**

   - For each stream, the test:
     - Iterates through each defined hue level in the list `[0, 25, 50, 75, 100, 50]`.
     - Sets the hue level and prompts the user with a Yes/No question to confirm the level:
       - **"Has hue level {hue} applied? (Y/N):"**
       - The user should respond with **Y** for Yes if the hue level is applied correctly or **N** for No if it is not.

3. **Logging Results:**

   - The test logs the result of each user confirmation for each hue level and stream.

4. **Cleanup:**

   - The test stops playback after verifying each hue level.

5. **Test Conclusion:**

   After playback and verification of all hue levels are completed, the test concludes and logs final results based on user input.

### tvSettings_test15_ColorTemp.py

#### User Input Required - test15

**Yes**: This test requires user input to confirm if the Color Temperature (ColorTemp) level setting has been applied correctly. The user will be prompted with a Yes/No question to verify each color temperature level for each stream.

#### Acceptance Criteria - test15

The device should apply the specified ColorTemp level as configured, and the user should verify that the color temperature adjustment has been accurately applied.

#### Expected Results - test15

The test initializes the TV settings, iterates through defined color temperature levels, and verifies the application of each level during playback of each stream through user prompts.

Success Criteria

- The specified ColorTemp level should be set and visibly applied on the device.
- The user should confirm whether each ColorTemp level has been correctly applied for each stream.

#### Test Steps - test15

1. **Initiate the Test:**

   - Run the Python file: **`tvSettings_test15_ColorTemp.py`**
   - The test will automatically initialize the TV settings and begin playback of the designated streams.

2. **Color Temperature Level Verification:**

   - For each stream, the test:
     - Retrieves the available color temperature levels using `self.testtvSettings.getColorTemperatureInfo()`.
     - Sets each color temperature level and prompts the user with a Yes/No question to confirm the level:
       - **"Has ColorTemp level {colorTemp} applied? (Y/N):"**
       - The user should respond with **Y** for Yes if the color temperature level is applied correctly or **N** for No if it is not.

3. **Logging Results:**

   - The test logs the result of each user confirmation for each color temperature level and stream.

4. **Cleanup:**

   - The test stops playback after verifying each color temperature level.
   - It resets the color temperature level to a default setting after all verifications.

5. **Test Conclusion:**

   After playback and verification of all color temperature levels are completed, the test concludes and logs final results based on user input.

### tvSettings_test16_AspectRatio.py

#### User Input Required - test16

**Yes**: This test requires user input to confirm if the Aspect Ratio has been applied correctly. The user will be prompted with a Yes/No question to verify each aspect ratio setting for each stream.

#### Acceptance Criteria - test16

The device should apply the specified Aspect Ratio setting as configured, and the user should verify that the aspect ratio adjustment has been accurately applied.

#### Expected Results - test16

The test initializes the TV settings, iterates through the available aspect ratios, and verifies the application of each ratio during playback of each stream through user prompts.

Success Criteria

- The specified Aspect Ratio should be set and visibly applied on the device.
- The user should confirm whether each Aspect Ratio has been correctly applied for each stream.

#### Test Steps - test16

1. **Initiate the Test:**

   - Run the Python file: **`tvSettings_test16_AspectRatio.py`**
   - The test will automatically initialize the TV settings and begin playback of the designated streams.

2. **Aspect Ratio Verification:**

   - For each stream, the test:
     - Retrieves the available aspect ratios using `self.testtvSettings.getAspectRatio()`.
     - Sets each aspect ratio and prompts the user with a Yes/No question to confirm the setting:
       - **"Has AspectRatio {aspectRatio} applied? (Y/N):"**
       - The user should respond with **Y** for Yes if the aspect ratio is applied correctly or **N** for No if it is not.

3. **Logging Results:**

   - The test logs the result of each user confirmation for each aspect ratio and stream.

4. **Cleanup:**

   - The test stops playback after verifying each aspect ratio.
   - It resets the aspect ratio to a default setting after all verifications.

5. **Test Conclusion:**

   After playback and verification of all aspect ratios are completed, the test concludes and logs final results based on user input.

### tvSettings_test17_DynamicContrast.py

#### User Input Required - test17

**Yes**: This test requires user input to confirm if the Dynamic Contrast state (Enabled or Disabled) has been correctly applied. The user will be prompted with a Yes/No question to verify each state setting for each stream.

#### Acceptance Criteria - test17

The device should apply the specified Dynamic Contrast state as configured, and the user should verify that the adjustment has been accurately applied.

#### Expected Results - test17

The test initializes the TV settings, iterates through the available Dynamic Contrast states, and verifies the application of each state during playback of each stream through user prompts.

Success Criteria

- The specified Dynamic Contrast state should be set and visibly applied on the device.
- The user should confirm whether each Dynamic Contrast state has been correctly applied for each stream.

#### Test Steps - test17

1. **Initiate the Test:**

   - Run the Python file: **`tvSettings_test17_DynamicContrast.py`**
   - The test will automatically initialize the TV settings and begin playback of the designated streams.

2. **Dynamic Contrast Verification:**

   - For each stream, the test:
     - Iterates over the available Dynamic Contrast states: **Enabled** and **Disabled**.
     - Sets each state and prompts the user with a Yes/No question to confirm the setting:
       - **"Has Dynamic Contrast {dynamicContrast} applied? (Y/N):"**
       - The user should respond with **Y** for Yes if the dynamic contrast is applied correctly or **N** for No if it is not.

3. **Logging Results:**

   - The test logs the result of each user confirmation for each Dynamic Contrast state and stream.

4. **Cleanup:**

   - The test stops playback after verifying each state for each stream.

5. **Test Conclusion:**

   After playback and verification of all Dynamic Contrast states are completed, the test concludes and logs final results based on user input.

### tvSettings_test18_DynamicGamma.py

#### User Input Required - test18

**Yes**: This test requires manual verification to confirm whether the dynamic gamma levels have been applied correctly. The user must respond to a prompt indicating whether the settings are correct.

#### Acceptance Criteria - test18

The system should apply the specified dynamic gamma levels while streaming content, and the user should confirm the accuracy of the applied settings.

#### Expected Results - test18

The script initializes the TV settings, sets dynamic gamma levels for specified streams, and prompts the user to verify whether the settings were applied correctly.

Success Criteria

- Dynamic gamma levels are applied correctly for each specified stream.
- User confirmation matches the expected dynamic gamma levels.

#### Test Steps - test18

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test18_DynamicGamma.py`**

2. **Set Dynamic Gamma Levels:**

   - The script initializes the TV settings module and sets dynamic gamma levels from the defined list `[1.80, 2.10, 2.60]`.

3. **Stream Playback:**

   - The script retrieves the list of streams from the test setup and plays each stream.

4. **Dynamic Gamma Verification:**

   - After playing each stream, the script verifies whether the dynamic gamma levels were set correctly:
     - User is prompted with: **"Has Dynamic Gamma level {dynamicGamma} applied? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

5. **Logging Results:**

   - The script logs results based on user input for each dynamic gamma setting.

6. **Cleanup:**

   - After all verifications, the script stops the stream playback.

7. **Test Conclusion:**

   - Once all dynamic gamma levels are verified, the script terminates the TV settings module and logs the final results based on user responses.

### tvSettings_test19_DolbyVision.py

#### User Input Required - test19

**Yes**: This test requires user input to confirm if each Dolby Vision level has been applied correctly. The user will be prompted with a Yes/No question to verify each level setting during each stream.

#### Acceptance Criteria - test19

The device should apply the specified Dolby Vision level as configured. The user should be able to visually confirm the application of each setting.

#### Expected Results - test19

The test initializes the TV settings, iterates through the available Dolby Vision levels, and verifies the application of each level by prompting the user for confirmation.

Success Criteria

- The specified Dolby Vision level should be set and visibly applied on the device.
- The user should confirm whether each Dolby Vision level has been applied for each stream.

#### Test Steps - test19

1. **Initiate the Test:**

   - Run the Python file: **`tvSettings_test19_DolbyVision.py`**
   - The test will initialize the TV settings and begin playback of each specified stream.

2. **Dolby Vision Verification:**

   - For each stream, the test:
     - Iterates over the available Dolby Vision levels provided by `getDolbyVisionInfo`.
     - Sets each level and prompts the user with a Yes/No question to confirm the setting:
       - **"Has Dolby Vision level {DolbyVision} applied? (Y/N):"**
       - The user should respond with **Y** for Yes if the Dolby Vision level is applied correctly or **N** for No if it is not.

3. **Logging Results:**

   - The test logs the result of each user confirmation for each Dolby Vision level and stream.

4. **Cleanup:**

   - The test stops playback after verifying each Dolby Vision level for each stream.

5. **Test Conclusion:**

   - After playback and verification of all Dolby Vision levels are completed, the test concludes and logs final results based on user input.

### tvSettings_test20_PictureMode.py

#### User Input Required - test20

**Yes**: This test requires user input to confirm if each Picture Mode level has been correctly applied. The user will respond with Yes or No during each verification.

#### Acceptance Criteria - test20

The device should correctly apply the specified Picture Mode level for each stream. For the Picture Mode "FMM," the test should verify the "tvContentType_FMM" callback to ensure it has been triggered.

#### Expected Results - test20

The test initializes the TV settings, iterates through the available Picture Mode levels, and verifies the application of each level through user confirmation or automated callback checks.

Success Criteria

- The device should display the correct Picture Mode level as applied.
- The "tvContentType_FMM" callback should be triggered and verified when Picture Mode is set to "FMM."

#### Test Steps - test20

1. **Initiate the Test:**

   - Run the Python file: **`tvSettings_test20_PictureMode.py`**
   - The test will initialize TV settings and start playback of each specified stream.

2. **Picture Mode Verification:**

   - For each stream, the test:
     - Iterates over the available Picture Mode levels provided by `getPictureModeInfo`.
     - Sets each level and prompts the user to confirm the setting with a Yes/No question:
       - **"Has Picture Mode level {pictureMode} applied? (Y/N):"**
       - User should respond **Y** for Yes if the level is applied or **N** for No if not.

3. **FMM Picture Mode Callback Check:**

   - If the Picture Mode is **"FMM"**, the test will:
     - Log and verify the presence of the **"tvContentType_FMM"** callback by calling `getVideoContentCallbackStatus`.
     - Log the result of this callback verification.

4. **Logging Results:**

   - The test logs the result of each Picture Mode level verification, including the callback check for "FMM" mode.

5. **Cleanup:**

   - The test stops playback after each Picture Mode level is verified for each stream.

6. **Test Conclusion:**

   - After completing playback and verification for all Picture Mode levels, the test ends and logs final results based on user confirmations and callback status.

### tvSettings_test21_ColorTempRgain.py

#### User Input Required - test21

**Yes**: This test requires user input to confirm if each Color Temperature and Rgain setting has been applied correctly. Users will respond with Yes or No during each verification step.

#### Acceptance Criteria - test21

The device should correctly apply and retain the specified Color Temperature and Rgain settings across multiple streams. The test distinguishes between **Set** (temporary application) and **Save** (persistent application) operations.

#### Expected Results - test21

The test initializes TV settings, iterates over multiple Color Temperature and Rgain values, and verifies each application with both Set and Save flags, through user confirmation or automated checks.

Success Criteria

- The device should display the correct Color Temperature and Rgain settings as applied or saved.
- For Save operations, settings should persist when streams are restarted.

#### Test Steps - test21

1. **Initiate the Test:**

   - Run the Python file: **`tvSettings_test21_ColorTempRgain.py`**
   - The test initializes TV settings.

2. **Set Operation:**

   - For each stream, the test iterates through available Color Temperature values and Rgain values:
     - For each combination of Color Temperature and Rgain, the system sets the value temporarily (`saveSetFlag = 0`) and prompts the user:
       - **"Has Color Temperature {colorTemperature} and Rgain {rgain} with flag {saveSetFlag} applied? (Y/N):"**
       - Users should confirm with **Y** for Yes or **N** for No based on applied values.

3. **Save Operation:**

   - For each Color Temperature and Rgain combination, the test applies the Save operation (`saveSetFlag = 1`).
   - After setting all combinations, the test restarts each stream and verifies that each saved setting has been retained:
     - **"Has Color Temperature {colorTemperature} and Rgain {rgain} with flag {saveSetFlag} applied? (Y/N):"**

4. **Logging Results:**

   - The test logs the result of each Set and Save operation verification for each stream.

5. **Cleanup:**

   - The test stops playback after each verification step.

6. **Test Conclusion:**

   - After completing playback and verification for all Color Temperature and Rgain combinations, the test terminates TV settings and logs final results based on user confirmations.

### tvSettings_test22_ColorTempGgain.py

#### User Input Required - test22

**Yes**: This test requires user input to confirm if each Color Temperature and Ggain setting has been applied correctly. Users will respond with Yes or No during each verification step.

#### Acceptance Criteria - test22

The device should correctly apply and retain the specified Color Temperature and Ggain settings across multiple streams. The test distinguishes between **Set** (temporary application) and **Save** (persistent application) operations.

#### Expected Results - test22

The test initializes TV settings, iterates over multiple Color Temperature and Ggain values, and verifies each application with both Set and Save flags, through user confirmation or automated checks.

Success Criteria

- The device should display the correct Color Temperature and Ggain settings as applied or saved.
- For Save operations, settings should persist when streams are restarted.

#### Test Steps - test22

1. **Initiate the Test:**

   - Run the Python file: **`tvSettings_test22_ColorTempGgain.py`**
   - The test initializes TV settings.

2. **Set Operation:**

   - For each stream, the test iterates through available Color Temperature values and Ggain values:
     - For each combination of Color Temperature and Ggain, the system sets the value temporarily (`saveSetFlag = 0`) and prompts the user:
       - **"Has Color Temperature {colorTemperature} and Ggain {ggain} with flag {saveSetFlag} applied? (Y/N):"**
       - Users should confirm with **Y** for Yes or **N** for No based on applied values.

3. **Save Operation:**

   - For each Color Temperature and Ggain combination, the test applies the Save operation (`saveSetFlag = 1`).
   - After setting all combinations, the test restarts each stream and verifies that each saved setting has been retained:
     - **"Has Color Temperature {colorTemperature} and Ggain {ggain} with flag {saveSetFlag} applied? (Y/N):"**

4. **Logging Results:**

   - The test logs the result of each Set and Save operation verification for each stream.

5. **Cleanup:**

   - The test stops playback after each verification step.

6. **Test Conclusion:**

   - After completing playback and verification for all Color Temperature and Ggain combinations, the test terminates TV settings and logs final results based on user confirmations.

### tvSettings_test23_ColorTempBgain.py

#### User Input Required - test23

**Yes**: This test requires manual user confirmation for each application of Color Temperature and Bgain settings. Users will respond with Yes or No when prompted to verify each change.

#### Acceptance Criteria - test23

The system should correctly apply and retain the specified Color Temperature and Bgain settings for each stream tested. The script distinguishes between **Set** (temporary application) and **Save** (persistent application) operations.

#### Expected Results - test23

The script initializes TV settings, iterates over different Color Temperature and Bgain values, and verifies each application and persistence through user input.

Success Criteria

- The system should display the correct Color Temperature and Bgain settings when applied.
- Save operations should be confirmed to persist across stream restarts.

#### Test Steps - test23

1. **Initiate the Test:**

   - Run the Python file: **`tvSettings_test23_ColorTempBgain.py`**
   - The test initializes the TV settings module.

2. **Set Operation:**

   - For each stream, the script iterates through available Color Temperature values and Bgain values:
     - For each combination of Color Temperature and Bgain, the system temporarily sets the value (`saveSetFlag = 0`) and prompts the user:
       - **"Has Color Temperature {colorTemperature} and Bgain {bgain} with flag {saveSetFlag} applied? (Y/N):"**
       - Users should confirm with **Y** for Yes or **N** for No based on what is displayed.

3. **Save Operation:**

   - For each Color Temperature and Bgain combination, the script applies the Save operation (`saveSetFlag = 1`).
   - After saving all values, the script plays each stream and verifies that the saved settings are applied:
     - **"Has Color Temperature {colorTemperature} and Bgain {bgain} with flag {saveSetFlag} applied? (Y/N):"**

4. **Logging Results:**

   - The script logs results for each Set and Save operation based on user confirmation for each stream and setting.

5. **Cleanup:**

   - The script stops playback after each stream verification.

6. **Test Conclusion:**

   - After completing playback and verification, the script terminates TV settings and logs the final results based on user input.

### tvSettings_test24_colorTempRpostOffset.py

#### User Input Required - test24

**Yes**: This test requires manual confirmation for the application of Color Temperature and RpostOffset settings. Users must respond with **Y** (Yes) or **N** (No) based on whether the displayed values align with the specified settings.

#### Acceptance Criteria - test24

The system should accurately apply and retain the specified Color Temperature and RpostOffset settings for each tested stream. The script performs both **Set** (temporary) and **Save** (persistent) operations, verifying the changes based on user input.

#### Expected Results - test24

The script initializes TV settings, iterates over Color Temperature and RpostOffset values, and prompts the user to verify each setting change to ensure the correct application.

Success Criteria

- Correct Color Temperature and RpostOffset settings should appear on the screen when each setting is applied.
- Save operations should persist after the stream is restarted, confirmed through user verification.

#### Test Steps - test24

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test24_RpostOffset.py`**
   - The test initializes the TV settings module.

2. **Set Operation:**

   - For each stream in the test, the script iterates over available Color Temperature values and RpostOffset values:
     - For each combination, the system temporarily applies the setting (`saveSetFlag = 0`) and prompts the user:
       - **"Has Color Temperature {colorTemperature} and RpostOffset {rpostValue} with flag {saveSetFlag} applied? (Y/N):"**
       - Users should respond **Y** (Yes) or **N** (No) based on what is displayed.

3. **Save Operation:**

   - For each Color Temperature and RpostOffset combination, the script applies the Save operation (`saveSetFlag = 1`).
   - After saving all values, the script plays each stream and verifies that the saved settings are applied:
     - **"Has Color Temperature {colorTemperature} and RpostOffset {rpostValue} with flag {saveSetFlag} applied? (Y/N):"**

4. **Logging Results:**

   - The script logs results based on user input for each Set and Save operation across all streams and settings.

5. **Cleanup:**

   - The script stops playback after each stream verification.

6. **Test Conclusion:**

   - Once playback and verification are completed, the script terminates TV settings and logs the final results based on user responses.

### tvSettings_test25_ColorTempGpostOffset.py

#### User Input Required - test25

**Yes**: This test requires manual verification for the application of Color Temperature and GpostOffset settings. The user must confirm each setting application with **Y** (Yes) or **N** (No) based on displayed values.

#### Acceptance Criteria - test25

The system should accurately apply and retain specified Color Temperature and GpostOffset settings for each tested stream. The script performs **Set** (temporary) and **Save** (persistent) operations, with changes verified based on user input.

#### Expected Results - test25

The script initializes TV settings, iterates over Color Temperature and GpostOffset values, and prompts the user to verify each setting change to ensure correct application.

Success Criteria

- Correct Color Temperature and GpostOffset settings appear on the screen when each setting is applied.
- Save operations should persist after the stream restarts, confirmed through user verification.

#### Test Steps - test25

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test25_GpostOffset.py`**
   - The test initializes the TV settings module.

2. **Set Operation:**

   - For each stream in the test, the script iterates over available Color Temperature values and GpostOffset values:
     - For each combination, the system applies the setting temporarily (`saveSetFlag = 0`) and prompts the user:
       - **"Has Color Temperature {colorTemperature} and GpostOffset {gpostValue} with flag {saveSetFlag} applied? (Y/N):"**
       - Users respond with **Y** (Yes) or **N** (No) based on what is displayed.

3. **Save Operation:**

   - For each Color Temperature and GpostOffset combination, the script applies the Save operation (`saveSetFlag = 1`).
   - After saving all values, the script plays each stream and verifies that saved settings are applied:
     - **"Has Color Temperature {colorTemperature} and GpostOffset {gpostValue} with flag {saveSetFlag} applied? (Y/N):"**

4. **Logging Results:**

   - The script logs results based on user input for each Set and Save operation across all streams and settings.

5. **Cleanup:**

   - The script stops playback after each stream verification.

6. **Test Conclusion:**

   - Once playback and verification are completed, the script terminates TV settings and logs the final results based on user responses.

### tvSettings_test26_ColorTempBpostOffset.py

#### User Input Required - test26

**Yes**: This test requires manual verification for the application of Color Temperature and BpostOffset settings. The user must confirm each setting application with **Y** (Yes) or **N** (No) based on displayed values.

#### Acceptance Criteria - test26

The system should accurately apply and retain specified Color Temperature and BpostOffset settings for each tested stream. The script performs **Set** (temporary) and **Save** (persistent) operations, with changes verified based on user input.

#### Expected Results - test26

The script initializes TV settings, iterates over Color Temperature and BpostOffset values, and prompts the user to verify each setting change to ensure correct application.

Success Criteria

- Correct Color Temperature and BpostOffset settings appear on the screen when each setting is applied.
- Save operations should persist after the stream restarts, confirmed through user verification.

#### Test Steps - test26

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test26_BpostOffset.py`**
   - The test initializes the TV settings module.

2. **Set Operation:**

   - For each stream in the test, the script iterates over available Color Temperature values and BpostOffset values:
     - For each combination, the system applies the setting temporarily (`saveSetFlag = 0`) and prompts the user:
       - **"Has Color Temperature {colorTemperature} and BpostOffset {bpostValue} with flag {saveSetFlag} applied? (Y/N):"**
       - Users respond with **Y** (Yes) or **N** (No) based on what is displayed.

3. **Save Operation:**

   - For each Color Temperature and BpostOffset combination, the script applies the Save operation (`saveSetFlag = 1`).
   - After saving all values, the script plays each stream and verifies that saved settings are applied:
     - **"Has Color Temperature {colorTemperature} and BpostOffset {bpostValue} with flag {saveSetFlag} applied? (Y/N):"**

4. **Logging Results:**

   - The script logs results based on user input for each Set and Save operation across all streams and settings.

5. **Cleanup:**

   - The script stops playback after each stream verification.

6. **Test Conclusion:**

   - Once playback and verification are completed, the script terminates TV settings and logs the final results based on user responses.

### tvSettings_test27_WBCalibration.py

#### User Input Required - test27

**Yes**: This test relies on manual verification for applying the White Balance Calibration Mode (WBCalibrationMode) setting. The user must confirm each mode application with **Y** (Yes) or **N** (No) based on displayed values.

#### Acceptance Criteria - test27

The system should successfully apply each WBCalibrationMode value for each tested stream and display the correct calibration mode setting.

#### Expected Results - test27

The script initializes TV settings, iterates over the available WBCalibrationMode values (1 and 0), and prompts the user to verify the setting application on the screen.

Success Criteria

- Correct WBCalibrationMode setting is displayed based on the mode applied.
- User confirms the correct display of WBCalibrationMode for each stream and value.

#### Test Steps - test27

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test27_WBCalibrationMode.py`**
   - The test initializes the TV settings module.

2. **WBCalibrationMode Setting Verification:**

   - For each stream in the test, the script iterates over WBCalibrationMode values (1 for Calibration Mode enabled, 0 for disabled):
     - For each mode and stream, the system applies the WBCalibrationMode setting and prompts the user:
       - **"Has WBCalibrationMode {wbCalibrationMode} applied? (Y/N):"**
       - Users respond with **Y** (Yes) or **N** (No) based on the display.

3. **Logging Results:**

   - The script logs results based on user input for each WBCalibrationMode setting and stream.

4. **Cleanup:**

   - The script stops playback after each stream verification.

5. **Test Conclusion:**

   - Once playback and verification are completed, the script terminates TV settings and logs the final results based on user responses.

### tvSettings_test28_GammaTable.py

#### User Input Required - test28

**Yes**: This test requires manual verification to confirm the settings of the Gamma Table. The user must respond to a prompt indicating whether the Gamma Table has been set correctly.

#### Acceptance Criteria - test28

The system should apply the Gamma Table settings correctly and display the respective RGB values as specified in the test combinations.

#### Expected Results - test28

The script initializes TV settings, iterates through predefined gamma combinations, and prompts the user to verify that the Gamma Table has been set as expected.

Success Criteria

- Correct Gamma Table settings are applied for each combination.
- User confirmation matches the expected RGB values and size for the Gamma Table.

#### Test Steps - test28

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test28_GammaTable.py`**
   - The test initializes the TV settings module.

2. **Gamma Table Setting Verification:**

   - For each stream in the test, the script iterates over predefined gamma combinations:
     - Each combination consists of a size and lists of RGB values.
     - For each combination, the system applies the Gamma Table settings and prompts the user:
       - **"Is Gamma Table set with Size: {size}, R: {red}, G: {green}, B: {blue}? (Y/N):"**
       - Users respond with **Y** (Yes) or **N** (No) based on the display.

3. **Logging Results:**

   - The script logs results based on user input for each Gamma Table setting.

4. **Cleanup:**

   - The script stops playback after each stream verification.

5. **Test Conclusion:**

   - Once playback and verification are completed, the script terminates TV settings and logs the final results based on user responses.

### tvSettings_test29_DVTmax.py

#### User Input Required - test29

**Yes**: This test requires manual verification to confirm that the DVT max values are correctly applied. The user must respond to a prompt indicating whether the DVT max value has been set.

#### Acceptance Criteria - test29

The system should correctly apply the DVT max values and verify them against the expected values defined in the test.

#### Expected Results - test29

The script initializes the TV settings, iterates through predefined DVT max values, and prompts the user to verify that each value has been applied correctly.

Success Criteria

- Correct DVT max values are set for each iteration.
- User confirmation matches the expected DVT max values.

#### Test Steps - test29

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test29_DVTmax.py`**
   - The test initializes the TV settings module.

2. **DVT Max Value Setting Verification:**

   - For each stream in the test, the script iterates over predefined DVT max values:
     - Each value is logged and set using the `setDvTmaxValue` method.
     - The system prompts the user for confirmation:
       - **"Has DVT max value {dvtMaxValue} applied? (Y/N):"**
       - Users respond with **Y** (Yes) or **N** (No) based on the display.

3. **Logging Results:**

   - The script logs results based on user input for each DVT max value setting.

4. **Cleanup:**

   - The script stops playback after each stream verification.

5. **Test Conclusion:**

   - Once playback and verification are completed, the script terminates TV settings and logs the final results based on user responses.

### tvSettings_test30_ComponentSaturation.py

#### User Input Required - test30

**Yes**: This test requires manual verification to confirm that the component saturation values are correctly applied. The user must respond to a prompt indicating whether the saturation value has been set.

#### Acceptance Criteria - test30

The system should correctly apply the component saturation values and verify them against the expected values defined in the test.

#### Expected Results - test30

The script initializes the TV settings, iterates through predefined saturation values, and prompts the user to verify that each value has been applied correctly.

Success Criteria

- Correct component saturation values are set for each combination of color, picture mode, and video format.
- User confirmation matches the expected component saturation values.

#### Test Steps - test30

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test30_ComponentSaturation.py`**
   - The test initializes the TV settings module and sets the CMS (Color Management System) state.

2. **Component Saturation Setting:**

   - The script sets the component saturation values based on the available video formats and picture modes:
     - For each video format, it downloads and plays the corresponding stream.
     - It applies saturation values ranging from 0 to 100 for each combination of color and picture mode.

3. **Component Saturation Verification:**

   - The script plays each stream and verifies the applied saturation values:
     - User is prompted with: **"Has component saturation value {saturationValue} applied? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

4. **Logging Results:**

   - The script logs results based on user input for each component saturation setting.

5. **Cleanup:**

   - After all verifications, the script resets the component saturation to a default value of 50 for all color and picture mode combinations.

6. **Test Conclusion:**

   - Once all settings are verified and reset, the script terminates the TV settings module and logs the final results based on user responses.

### tvSettings_test31_ComponentHue.py

#### User Input Required - test31

**Yes**: This test requires manual verification to confirm that the component hue values are correctly applied. The user must respond to a prompt indicating whether the hue value has been set.

#### Acceptance Criteria - test31

The system should correctly apply the component hue values and verify them against the expected values defined in the test.

#### Expected Results - test31

The script initializes the TV settings, iterates through predefined hue values, and prompts the user to verify that each value has been applied correctly.

Success Criteria

- Correct component hue values are set for each combination of color, picture mode, and video format.
- User confirmation matches the expected component hue values.

#### Test Steps - test31

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test31_ComponentHue.py`**
   - The test initializes the TV settings module and sets the CMS (Color Management System) state.

2. **Component Hue Setting:**

   - The script sets the component hue values based on the available video formats and picture modes:
     - For each video format, it downloads and plays the corresponding stream.
     - It applies hue values ranging from 0 to 100 for each combination of color and picture mode.

3. **Component Hue Verification:**

   - The script plays each stream and verifies the applied hue values:
     - User is prompted with: **"Has component hue value {hueValue} applied? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

4. **Logging Results:**

   - The script logs results based on user input for each component hue setting.

5. **Cleanup:**

   - After all verifications, the script resets the component hue to a default value of 50 for all color and picture mode combinations.

6. **Test Conclusion:**

   - Once all settings are verified and reset, the script terminates the TV settings module and logs the final results based on user responses.

### tvSettings_test32_ComponentLuma.py

#### User Input Required - test32

**Yes**: This test requires manual verification to confirm that the component luma values are correctly applied. The user must respond to a prompt indicating whether the luma value has been set.

#### Acceptance Criteria - test32

The system should correctly apply the component luma values and verify them against the expected values defined in the test.

#### Expected Results - test32

The script initializes the TV settings, iterates through predefined luma values, and prompts the user to verify that each value has been applied correctly.

Success Criteria

- Correct component luma values are set for each combination of color, picture mode, and video format.
- User confirmation matches the expected component luma values.

#### Test Steps - test32

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test32_ComponentLuma.py`**
   - The test initializes the TV settings module and sets the CMS (Color Management System) state.

2. **Component Luma Setting:**

   - The script sets the component luma values based on the available video formats and picture modes:
     - For each video format, it downloads and plays the corresponding stream.
     - It applies luma values calculated to range from 0 to 30 based on the number of video formats for each combination of color and picture mode.

3. **Component Luma Verification:**

   - The script plays each stream and verifies the applied luma values:
     - User is prompted with: **"Has component luma value {lumaValue} applied? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

4. **Logging Results:**

   - The script logs results based on user input for each component luma setting.

5. **Cleanup:**

   - After all verifications, the script resets the component luma to a default value of 15 for all color and picture mode combinations.

6. **Test Conclusion:**

   - Once all settings are verified and reset, the script terminates the TV settings module and logs the final results based on user responses.

### tvSettings_test33_EnableGammaMode.py

#### User Input Required - test33

**Yes**: This test requires manual verification to confirm that the gamma mode has been set correctly. The user must respond to a prompt indicating whether the gamma mode is enabled or disabled.

#### Acceptance Criteria - test33

The system should correctly apply the gamma mode settings and verify them against the expected values defined in the test.

#### Expected Results - test33

The script initializes the TV settings, iterates through the predefined gamma modes, and prompts the user to verify that each mode has been applied correctly.

Success Criteria

- Correct gamma modes (Enable: 1, Disable: 0) are set for each stream.
- User confirmation matches the expected gamma mode settings.

#### Test Steps - test33

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test33_EnableGammaMode.py`**
   - The test initializes the TV settings module and sets the CMS (Color Management System) state.

2. **Gamma Mode Setting:**

   - The script iterates through the predefined gamma modes (0: Disable, 1: Enable) for each stream:
     - For each gamma mode, it starts the playback of the corresponding stream.
     - It sets the gamma mode using `self.testtvSettings.setEnableGammaMode(gammaMode)`.

3. **Gamma Mode Verification:**

   - After setting the gamma mode, the script verifies whether the mode was set correctly:
     - User is prompted with: **"Is gamma mode set to {gammaMode}? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

4. **Logging Results:**

   - The script logs results based on user input for each gamma mode setting.

5. **Cleanup:**

   - After all verifications, the script sets the CMS state back to 0 (disabled).
   - It terminates the TV settings module.

6. **Test Conclusion:**

   - Once all settings are verified and reset, the script logs the final results based on user responses.

### tvSettings_test34_SetGammaPattern.py

#### User Input Required - test34

**Yes**: This test requires manual verification to confirm that the gamma pattern settings have been applied correctly. The user must respond to a prompt indicating whether the gamma pattern is set to the specified bit depth and color levels.

#### Acceptance Criteria - test34

The system should correctly apply the gamma pattern settings for both 10-bit and 8-bit depths and verify them against the expected values defined in the test.

#### Expected Results - test34

The script initializes the TV settings, enables gamma pattern mode, iterates through the predefined bit depths and color levels, and prompts the user to verify that the gamma pattern has been set correctly.

Success Criteria

- Gamma pattern settings (bit depth, red level, green level, blue level) are applied for each stream.
- User confirmation matches the expected gamma pattern settings.

#### Test Steps - test34

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test34_SetGammaPattern.py`**
   - The test initializes the TV settings module and enables the gamma pattern mode.

2. **Gamma Pattern Setting:**

   - The script iterates through the predefined bit depths (0 for 10-bit, 1 for 8-bit) for each stream:
     - For each bit depth, it retrieves the corresponding level ranges for Red, Green, and Blue channels.
     - It sets the gamma pattern using `self.testtvSettings.setGammaPattern(bitDepth, redLevel, greenLevel, blueLevel)`.

3. **Gamma Pattern Verification:**

   - After setting the gamma pattern, the script verifies whether it was set correctly:
     - User is prompted with: **"Is gamma pattern set to Bit Depth: {bitDepth}, Red Level: {redLevel}, Green Level: {greenLevel}, Blue Level: {blueLevel}? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

4. **Logging Results:**

   - The script logs results based on user input for each gamma pattern setting.

5. **Cleanup:**

   - After all verifications, the script disables the gamma pattern mode.
   - It terminates the TV settings module.

6. **Test Conclusion:**

   - Once all settings are verified and reset, the script logs the final results based on user responses.

### tvSettings_test35_RGBPattern.py

#### User Input Required - test35

**Yes**: This test requires manual verification to confirm that the RGB pattern settings have been applied correctly. The user must respond to a prompt indicating whether the RGB pattern is set to the specified red, green, and blue levels.

#### Acceptance Criteria - test35

The system should correctly apply the RGB pattern settings for various predefined levels and verify them against the expected values defined in the test.

#### Expected Results - test35

The script initializes the TV settings, iterates through predefined RGB levels, sets the RGB pattern, and prompts the user to verify that the pattern has been set correctly.

Success Criteria

- RGB pattern settings (red level, green level, blue level) are applied for each predefined sample.
- User confirmation matches the expected RGB pattern settings.

#### Test Steps - test35

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test35_RGBPattern.py`**
   - The test initializes the TV settings module.

2. **RGB Pattern Setting:**

   - The script iterates through the predefined RGB levels:
     - For each set of levels, it retrieves the values for red, green, and blue.

3. **RGB Pattern Verification:**

   - After setting the RGB pattern, the script verifies whether it was set correctly:
     - User is prompted with: **"Is RGB pattern set to Red Level: {redLevel}, Green Level: {greenLevel}, Blue Level: {blueLevel}? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

4. **Logging Results:**

   - The script logs results based on user input for each RGB pattern setting.

5. **Cleanup:**

   - After all verifications, the script terminates the TV settings module.

6. **Test Conclusion:**

   - Once all settings are verified and reset, the script logs the final results based on user responses.

### tvSettings_test36_GrayPattern.py

#### User Input Required - test36

**Yes**: This test requires manual verification to confirm that the Gray pattern settings have been applied correctly. The user must respond to a prompt indicating whether the Gray pattern is set to the specified gray level.

#### Acceptance Criteria - test36

The system should correctly apply the Gray pattern settings for various predefined levels and verify them against the expected values defined in the test.

#### Expected Results - test36

The script initializes the TV settings, iterates through predefined gray levels, sets the Gray pattern, and prompts the user to verify that the pattern has been set correctly.

Success Criteria

- Gray pattern settings (gray level) are applied for each predefined sample.
- User confirmation matches the expected Gray pattern settings.

#### Test Steps - test36

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test36_GrayPattern.py`**
   - The test initializes the TV settings module.

2. **Gray Pattern Setting:**

   - The script iterates through the predefined gray levels:
     - For each gray level, it retrieves the value.

3. **Gray Pattern Verification:**

   - After setting the Gray pattern, the script verifies whether it was set correctly:
     - User is prompted with: **"Is Gray pattern set to Gray Level: {grayLevel}? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

4. **Logging Results:**

   - The script logs results based on user input for each Gray pattern setting.

5. **Cleanup:**

   - After all verifications, the script terminates the TV settings module.

6. **Test Conclusion:**

   - Once all settings are verified and reset, the script logs the final results based on user responses.

### tvSettings_test37_EnableLDIMPixelCompensation.py

#### User Input Required - test37

**Yes**: This test requires manual verification to confirm that the LDIM Pixel Compensation settings have been applied correctly. The user must respond to a prompt indicating whether the LDIM Pixel Compensation is set to the specified value.

#### Acceptance Criteria - test37

The system should correctly enable or disable the LDIM Pixel Compensation settings and verify them against the expected values defined in the test.

#### Expected Results - test37

The script initializes the TV settings, iterates through predefined LDIM Pixel Compensation values, sets the compensation, and prompts the user to verify that the setting has been applied correctly.

Success Criteria

- LDIM Pixel Compensation settings (0 or 1) are applied for each predefined sample.
- User confirmation matches the expected LDIM Pixel Compensation settings.

#### Test Steps - test37

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test37_EnableLDIMPixelCompensation.py`**
   - The test initializes the TV settings module.

2. **LDIM Pixel Compensation Setting:**

   - The script iterates through the predefined LDIM Pixel Compensation values:
     - For each value (0 for disabled and 1 for enabled), it retrieves the value.

3. **LDIM Pixel Compensation Verification:**

   - After setting the LDIM Pixel Compensation, the script verifies whether it was set correctly:
     - User is prompted with: **"Is LDIM Pixel Compensation set to: {ldimValue}? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

4. **Logging Results:**

   - The script logs results based on user input for each LDIM Pixel Compensation setting.

5. **Cleanup:**

   - After all verifications, the script terminates the TV settings module.

6. **Test Conclusion:**

   - Once all settings are verified and reset, the script logs the final results based on user responses.

### tvSettings_test38_EnableLDIM.py

#### User Input Required - test38

**Yes**: This test requires manual verification to confirm whether the LDIM settings have been applied correctly. The user must respond to a prompt indicating whether the LDIM is set to the specified value.

#### Acceptance Criteria - test38

The system should correctly enable or disable the LDIM settings and verify them against the expected values defined in the test.

#### Expected Results - test38

The script initializes the TV settings, iterates through predefined LDIM values, sets the LDIM, and prompts the user to verify that the setting has been applied correctly.

Success Criteria

- LDIM settings (0 for disabled and 1 for enabled) are applied for each predefined sample.
- User confirmation matches the expected LDIM settings.

#### Test Steps - test38

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test38_EnableLDIM.py`**
   - The test runs prerequisites specified in the test setup configuration file.

2. **LDIM Setting:**

   - The script initializes the TV settings module.
   - It iterates through the predefined LDIM values:
     - For each value (0 for disabled and 1 for enabled), it retrieves the value.

3. **LDIM Verification:**

   - After setting the LDIM, the script verifies whether it was set correctly:
     - User is prompted with: **"Is LDIM set to: {ldimValue}? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

4. **Logging Results:**

   - The script logs results based on user input for each LDIM setting.

5. **Cleanup:**

   - After all verifications, the script stops the stream playback and terminates the TV settings module.

6. **Test Conclusion:**

   - Once all settings are verified and reset, the script logs the final results based on user responses.

### tvSettings_test39_SetBacklightTestMode.py

#### User Input Required - test39

**Yes**: This test requires manual verification to confirm whether the backlight mode has been set correctly. The user must respond to a prompt indicating whether the backlight mode is set to the specified value.

#### Acceptance Criteria - test39

The system should correctly set the backlight mode according to the available options and verify it against the expected values defined in the test.

#### Expected Results - test39

The script initializes the TV settings, iterates through available backlight modes, sets the mode, and prompts the user to verify that the setting has been applied correctly.

Success Criteria

- Backlight modes are applied for each predefined sample.
- User confirmation matches the expected backlight settings.

#### Test Steps - test39

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test39_SetBacklightTestMode.py`**

2. **Backlight Mode Setting:**

   - The script initializes the TV settings module.
   - It iterates through the available backlight modes obtained from `getBacklightTestModeInfo`.

3. **Backlight Mode Verification:**

   - After setting the backlight mode, the script verifies whether it was set correctly:
     - User is prompted with: **"Is backlight mode set to: {backlightMode}? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

4. **Logging Results:**

   - The script logs results based on user input for each backlight mode setting.

5. **Cleanup:**

   - After all verifications, the script stops the stream playback and terminates the TV settings module.

6. **Test Conclusion:**

   - Once all settings are verified and reset, the script logs the final results based on user responses.

### tvSettings_test40_EnableDynamicContrast.py

#### User Input Required - test40

**Yes**: This test requires manual verification to confirm whether the dynamic contrast setting has been applied correctly. The user must respond to a prompt indicating whether the dynamic contrast is set to the specified value.

#### Acceptance Criteria - test40

The system should correctly set and verify the dynamic contrast levels according to the predefined options and ensure that the user can confirm the settings.

#### Expected Results - test40

The script initializes the TV settings, iterates through available dynamic contrast levels, applies the settings, and prompts the user to verify whether the settings were applied correctly.

Success Criteria

- Dynamic contrast levels are applied for each predefined sample.
- User confirmation matches the expected dynamic contrast settings.

#### Test Steps - test40

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test40_EnableDynamicContrast.py`**

2. **Dynamic Contrast Setting:**

   - The script initializes the TV settings module.
   - It iterates through the available dynamic contrast levels defined in `dynamicContrastLevels`.

3. **Dynamic Contrast Verification:**

   - After setting the dynamic contrast level, the script verifies whether it was set correctly:
     - User is prompted with: **"Is Dynamic Contrast set to: {dynamicContrast}? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

4. **Logging Results:**

   - The script logs results based on user input for each dynamic contrast level setting.

5. **Cleanup:**

   - After all verifications, the script stops the stream playback and terminates the TV settings module.

6. **Test Conclusion:**

   - Once all settings are verified and reset, the script logs the final results based on user responses.

### tvSettings_test41_EnableLocalContrast.py

#### User Input Required - test41

**Yes**: This test requires manual verification to confirm whether the local contrast setting has been applied correctly. The user must respond to a prompt indicating whether the local contrast is set to the specified value.

#### Acceptance Criteria - test41

The system should correctly set and verify the local contrast levels according to the predefined options and ensure that the user can confirm the settings.

#### Expected Results - test41

The script initializes the TV settings, iterates through available local contrast levels, applies the settings, and prompts the user to verify whether the settings were applied correctly.

Success Criteria

- Local contrast levels are applied for each predefined sample.
- User confirmation matches the expected local contrast settings.

#### Test Steps - test41

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test41_EnableLocalContrast.py`**

2. **Local Contrast Setting:**

   - The script initializes the TV settings module.
   - It iterates through the available local contrast levels defined in `localContrastLevels`.

3. **Local Contrast Verification:**

   - After setting the local contrast level, the script verifies whether it was set correctly:
     - User is prompted with: **"Is Local Contrast set to: {localContrast}? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

4. **Logging Results:**

   - The script logs results based on user input for each local contrast level setting.

5. **Cleanup:**

   - After all verifications, the script stops the stream playback and terminates the TV settings module.

6. **Test Conclusion:**

   - Once all settings are verified and reset, the script logs the final results based on user responses.

### tvSettings_test42_SaveBacklightValues.py

#### User Input Required - test42

**Yes**: This test requires manual verification to confirm whether the backlight value has been applied correctly for various picture modes and video formats. The user must respond to a prompt indicating whether the backlight value is correctly set.

#### Acceptance Criteria - test42

The system should save the correct backlight values for all combinations of picture modes and video formats, and the user should be able to confirm the settings through manual verification.

#### Expected Results - test42

The script initializes the TV settings, saves backlight values for different formats and modes, plays the streams, and prompts the user to verify whether the settings were applied correctly.

Success Criteria

- Backlight values are saved and applied correctly for each combination of picture mode and video format.
- User confirmation matches the expected backlight values.

#### Test Steps - test42

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test42_SaveBacklightValues.py`**

2. **Save Backlight Values:**

   - The script initializes the TV settings module and saves backlight values for all combinations of picture modes and video formats.

3. **Stream Playback:**

   - The script retrieves the list of video formats and corresponding stream URLs.
   - It downloads the individual streams and plays them.

4. **Backlight Value Verification:**

   - After playing each stream, the script verifies whether the backlight values were set correctly:
     - User is prompted with: **"Is backlight value {backlight} applied for Picture Mode: {pictureMode} and Video Format: {videoFormat}? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

5. **Logging Results:**

   - The script logs results based on user input for each backlight value setting.

6. **Cleanup:**

   - After all verifications, the script stops the stream playback, cleans up the downloaded assets, and sets all backlight values to the default value of 50.

7. **Test Conclusion:**

   - Once all settings are verified and reset, the script logs the final results based on user responses.

### tvSettings_test43_SaveTVDimmingMode.py

#### User Input Required - test43

**Yes**: This test requires manual verification to confirm whether the dimming value has been applied correctly for various picture modes and video formats. The user must respond to a prompt indicating whether the dimming level is correctly set.

#### Acceptance Criteria - test43

The system should save the correct dimming values for all combinations of picture modes and video formats, and the user should be able to confirm the settings through manual verification.

#### Expected Results - test43

The script initializes the TV settings, saves dimming values for different formats and modes, plays the streams, and prompts the user to verify whether the settings were applied correctly.

Success Criteria

- Dimming values are saved and applied correctly for each combination of picture mode and video format.
- User confirmation matches the expected dimming levels.

#### Test Steps - test43

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test43_SaveTVDimmingMode.py`**

2. **Save Dimming Values:**

   - The script initializes the TV settings module and saves dimming values for all combinations of picture modes and video formats.

3. **Stream Playback:**

   - The script retrieves the list of video formats and corresponding stream URLs.
   - It downloads the individual streams and plays them.

4. **Dimming Value Verification:**

   - After playing each stream, the script verifies whether the dimming values were set correctly:
     - User is prompted with: **"Is dimming value {dimmingLevel} applied for Picture Mode: {pictureMode} and Video Format: {videoFormat}? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

5. **Logging Results:**

   - The script logs results based on user input for each dimming value setting.

6. **Cleanup:**

   - After all verifications, the script stops the stream playback, cleans up the downloaded assets.

7. **Test Conclusion:**

   - Once all settings are verified, the script logs the final results based on user responses.

### tvSettings_test44_SaveLocalDimmingLevel.py

#### User Input Required - test44

**Yes**: This test requires manual verification to confirm whether the local dimming value has been applied correctly for various picture modes and video formats. The user must respond to a prompt indicating whether the local dimming level is correctly set.

#### Acceptance Criteria - test44

The system should save the correct local dimming values for all combinations of picture modes and video formats, and the user should be able to confirm the settings through manual verification.

#### Expected Results - test44

The script initializes the TV settings, saves local dimming values for different formats and modes, plays the streams, and prompts the user to verify whether the settings were applied correctly.

Success Criteria

- Local dimming values are saved and applied correctly for each combination of picture mode and video format.
- User confirmation matches the expected local dimming levels.

#### Test Steps - test44

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test44_SaveLocalDimmingLevel.py`**

2. **Save Local Dimming Values:**

   - The script initializes the TV settings module and saves local dimming values for all combinations of picture modes and video formats.

3. **Stream Playback:**

   - The script retrieves the list of video formats and corresponding stream URLs.
   - It downloads the individual streams and plays them.

4. **Local Dimming Value Verification:**

   - After playing each stream, the script verifies whether the local dimming values were set correctly:
     - User is prompted with: **"Is local dimming value {localDimmingLevel} applied for Picture Mode: {pictureMode} and Video Format: {videoFormat}? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

5. **Logging Results:**

   - The script logs results based on user input for each local dimming value setting.

6. **Cleanup:**

   - After all verifications, the script stops the stream playback and cleans up the downloaded assets.

7. **Test Conclusion:**

   - Once all settings are verified, the script logs the final results based on user responses.

### tvSettings_test45_SaveBrightness.py

#### User Input Required - test45

**Yes**: This test requires manual verification to confirm whether the brightness value has been applied correctly for various picture modes and video formats. The user must respond to a prompt indicating whether the brightness level is correctly set.

#### Acceptance Criteria - test45

The system should save the correct brightness values for all combinations of picture modes and video formats, and the user should be able to confirm the settings through manual verification.

#### Expected Results - test45

The script initializes the TV settings, saves brightness values for different formats and modes, plays the streams, and prompts the user to verify whether the settings were applied correctly.

Success Criteria

- Brightness values are saved and applied correctly for each combination of picture mode and video format.
- User confirmation matches the expected brightness levels.

#### Test Steps - test45

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test45_SaveBrightness.py`**

2. **Save Brightness Values:**

   - The script initializes the TV settings module and saves brightness values for all combinations of picture modes and video formats.
   - Brightness values are distributed across the number of video formats.

3. **Stream Playback:**

   - The script retrieves the list of video formats and corresponding stream URLs.
   - It downloads the individual streams and plays them.

4. **Brightness Value Verification:**

   - After playing each stream, the script verifies whether the brightness values were set correctly:
     - User is prompted with: **"Is brightness value {brightness} applied for Picture Mode: {pictureMode} and Video Format: {videoFormat}? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

5. **Logging Results:**

   - The script logs results based on user input for each brightness value setting.

6. **Cleanup:**

   - After all verifications, the script stops the stream playback and cleans up the downloaded assets.

7. **Set Default Brightness:**

   - After testing, the script sets all brightness values back to a default value of **50**.

8. **Test Conclusion:**

   - Once all settings are verified and defaults restored, the script logs the final results based on user responses.

### tvSettings_test46_SaveContrast.py

#### User Input Required - test46

**Yes**: This test requires manual verification to confirm whether the contrast value has been applied correctly for various picture modes and video formats. The user must respond to a prompt indicating whether the contrast level is correctly set.

#### Acceptance Criteria - test46

The system should save the correct contrast values for all combinations of picture modes and video formats, and the user should be able to confirm the settings through manual verification.

#### Expected Results - test46

The script initializes the TV settings, saves contrast values for different formats and modes, plays the streams, and prompts the user to verify whether the settings were applied correctly.

Success Criteria

- Contrast values are saved and applied correctly for each combination of picture mode and video format.
- User confirmation matches the expected contrast levels.

#### Test Steps - test46

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test46_SaveContrast.py`**

2. **Save Contrast Values:**

   - The script initializes the TV settings module and saves contrast values for all combinations of picture modes and video formats.
   - Contrast values are distributed across the number of video formats.

3. **Stream Playback:**

   - The script retrieves the list of video formats and corresponding stream URLs.
   - It downloads the individual streams and plays them.

4. **Contrast Value Verification:**

   - After playing each stream, the script verifies whether the contrast values were set correctly:
     - User is prompted with: **"Is contrast value {contrast} applied for Picture Mode: {pictureMode} and Video Format: {videoFormat}? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

5. **Logging Results:**

   - The script logs results based on user input for each contrast value setting.

6. **Cleanup:**

   - After all verifications, the script stops the stream playback and cleans up the downloaded assets.

7. **Set Default Contrast:**

   - After testing, the script sets all contrast values back to a default value of **50**.

8. **Test Conclusion:**

   - Once all settings are verified and defaults restored, the script logs the final results based on user responses.

### tvSettings_test47_SaveSharpness.py

#### User Input Required - test47

**Yes**: This test requires manual verification to confirm whether the sharpness value has been applied correctly for various picture modes and video formats. The user must respond to a prompt indicating whether the sharpness level is correctly set.

#### Acceptance Criteria - test47

The system should save the correct sharpness values for all combinations of picture modes and video formats, and the user should be able to confirm the settings through manual verification.

#### Expected Results - test47

The script initializes the TV settings, saves sharpness values for different formats and modes, plays the streams, and prompts the user to verify whether the settings were applied correctly.

Success Criteria

- Sharpness values are saved and applied correctly for each combination of picture mode and video format.
- User confirmation matches the expected sharpness levels.

#### Test Steps - test47

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test47_SaveSharpness.py`**

2. **Save Sharpness Values:**

   - The script initializes the TV settings module and saves sharpness values for all combinations of picture modes and video formats.
   - Sharpness values are distributed across the number of video formats.

3. **Stream Playback:**

   - The script retrieves the list of video formats and corresponding stream URLs.
   - It downloads the individual streams and plays them.

4. **Sharpness Value Verification:**

   - After playing each stream, the script verifies whether the sharpness values were set correctly:
     - User is prompted with: **"Is sharpness value {sharpness} applied for Picture Mode: {pictureMode} and Video Format: {videoFormat}? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

5. **Logging Results:**

   - The script logs results based on user input for each sharpness value setting.

6. **Cleanup:**

   - After all verifications, the script stops the stream playback and cleans up the downloaded assets.

7. **Set Default Sharpness:**

   - After testing, the script sets all sharpness values back to a default value of **50**.

8. **Test Conclusion:**

   - Once all settings are verified and defaults restored, the script logs the final results based on user responses.

### tvSettings_test48_SaveSaturation.py

#### User Input Required - test48

**Yes**: This test requires manual verification to confirm whether the saturation value has been applied correctly for various picture modes and video formats. The user must respond to a prompt indicating whether the saturation level is correctly set.

#### Acceptance Criteria - test48

The system should save the correct saturation values for all combinations of picture modes and video formats, and the user should be able to confirm the settings through manual verification.

#### Expected Results - test48

The script initializes the TV settings, saves saturation values for different formats and modes, plays the streams, and prompts the user to verify whether the settings were applied correctly.

Success Criteria

- Saturation values are saved and applied correctly for each combination of picture mode and video format.
- User confirmation matches the expected saturation levels.

#### Test Steps - test48

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test48_SaveSaturation.py`**

2. **Save Saturation Values:**

   - The script initializes the TV settings module and saves saturation values for all combinations of picture modes and video formats.
   - Saturation values are distributed across the number of video formats.

3. **Stream Playback:**

   - The script retrieves the list of video formats and corresponding stream URLs.
   - It downloads the individual streams and plays them.

4. **Saturation Value Verification:**

   - After playing each stream, the script verifies whether the saturation values were set correctly:
     - User is prompted with: **"Is saturation value {saturation} applied for Picture Mode: {pictureMode} and Video Format: {videoFormat}? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

5. **Logging Results:**

   - The script logs results based on user input for each saturation value setting.

6. **Cleanup:**

   - After all verifications, the script stops the stream playback and cleans up the downloaded assets.

7. **Set Default Saturation:**

   - After testing, the script sets all saturation values back to a default value of **50**.

8. **Test Conclusion:**

   - Once all settings are verified and defaults restored, the script logs the final results based on user responses.

### tvSettings_test49_SaveHue.py

#### User Input Required - test49

**Yes**: This test requires manual verification to confirm whether the hue value has been applied correctly for various picture modes and video formats. The user must respond to a prompt indicating whether the hue level is correctly set.

#### Acceptance Criteria - test49

The system should save the correct hue values for all combinations of picture modes and video formats, and the user should be able to confirm the settings through manual verification.

#### Expected Results - test49

The script initializes the TV settings, saves hue values for different formats and modes, plays the streams, and prompts the user to verify whether the settings were applied correctly.

Success Criteria

- Hue values are saved and applied correctly for each combination of picture mode and video format.
- User confirmation matches the expected hue levels.

#### Test Steps - test49

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test49_SaveHue.py`**

2. **Save Hue Values:**

   - The script initializes the TV settings module and saves hue values for all combinations of picture modes and video formats.
   - Hue values are distributed across the number of video formats.

3. **Stream Playback:**

   - The script retrieves the list of video formats and corresponding stream URLs.
   - It downloads the individual streams and plays them.

4. **Hue Value Verification:**

   - After playing each stream, the script verifies whether the hue values were set correctly:
     - User is prompted with: **"Is hue value {hue} applied for Picture Mode: {pictureMode} and Video Format: {videoFormat}? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

5. **Logging Results:**

   - The script logs results based on user input for each hue value setting.

6. **Cleanup:**

   - After all verifications, the script stops the stream playback and cleans up the downloaded assets.

7. **Set Default Hue:**

   - After testing, the script sets all hue values back to a default value of **50**.

8. **Test Conclusion:**

   - Once all settings are verified and defaults restored, the script logs the final results based on user responses.

### tvSettings_test50_SaveColorTemperature.py

#### User Input Required - test50

**Yes**: This test requires manual verification to confirm whether the color temperature has been applied correctly for various picture modes and video formats. The user must respond to a prompt indicating whether the color temperature is correctly set.

#### Acceptance Criteria - test50

The system should save the correct color temperature values for all combinations of picture modes and video formats, and the user should be able to confirm the settings through manual verification.

#### Expected Results - test50

The script initializes the TV settings, saves color temperature values for different formats and modes, plays the streams, and prompts the user to verify whether the settings were applied correctly.

Success Criteria

- Color temperature values are saved and applied correctly for each combination of picture mode and video format.
- User confirmation matches the expected color temperature levels.

#### Test Steps - test50

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test50_SaveColorTemperature.py`**

2. **Save Color Temperature Values:**

   - The script initializes the TV settings module and saves color temperature values for all combinations of picture modes and video formats.
   - Color temperature values are assigned based on the available formats.

3. **Stream Playback:**

   - The script retrieves the list of video formats and corresponding stream URLs.
   - It downloads the individual streams and plays them.

4. **Color Temperature Verification:**

   - After playing each stream, the script verifies whether the color temperature values were set correctly:
     - User is prompted with: **"Is color temperature {colorTemperature} applied for Picture Mode: {pictureMode} and Video Format: {videoFormat}? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

5. **Logging Results:**

   - The script logs results based on user input for each color temperature setting.

6. **Cleanup:**

   - After all verifications, the script stops the stream playback and cleans up the downloaded assets.

7. **Set Default Color Temperature:**

   - After testing, the script sets all color temperature values back to a default value of **'tvColorTemp_STANDARD'**.

8. **Test Conclusion:**

   - Once all settings are verified and defaults restored, the script logs the final results based on user responses.

### tvSettings_test51_SaveAspectRatio.py

#### User Input Required - test51

**Yes**: This test requires manual verification to confirm whether the aspect ratio has been applied correctly for various picture modes and video formats. The user must respond to a prompt indicating whether the aspect ratio is correctly set.

#### Acceptance Criteria - test51

The system should save the correct aspect ratio values for all combinations of picture modes and video formats, and the user should be able to confirm the settings through manual verification.

#### Expected Results - test51

The script initializes the TV settings, saves aspect ratio values for different formats and modes, plays the streams, and prompts the user to verify whether the settings were applied correctly.

Success Criteria

- Aspect ratio values are saved and applied correctly for each combination of picture mode and video format.
- User confirmation matches the expected aspect ratio levels.

#### Test Steps - test51

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test51_SaveAspectRatio.py`**

2. **Set Default Aspect Ratio:**

   - The script sets all aspect ratio values to a default value of **'tvDisplayMode_4x3'**.

3. **Save Aspect Ratio Values:**

   - The script initializes the TV settings module and saves aspect ratio values for all combinations of picture modes and video formats.
   - Aspect ratio values are assigned based on the available formats.

4. **Stream Playback:**

   - The script retrieves the list of video formats and corresponding stream URLs.
   - It downloads the individual streams and plays them.

5. **Aspect Ratio Verification:**

   - After playing each stream, the script verifies whether the aspect ratio values were set correctly:
     - User is prompted with: **"Is aspect ratio {aspectRatio} applied for Picture Mode: {pictureMode} and Video Format: {videoFormat}? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

6. **Logging Results:**

   - The script logs results based on user input for each aspect ratio setting.

7. **Cleanup:**

   - After all verifications, the script stops the stream playback and cleans up the downloaded assets.

8. **Set Default Aspect Ratio Again:**

   - After testing, the script sets all aspect ratio values back to a default value of **'tvDisplayMode_4x3'**.

9. **Test Conclusion:**

   - Once all settings are verified and defaults restored, the script logs the final results based on user responses.

### tvSettings_test52_SaveDolbyVision.py

#### User Input Required - test52

**Yes**: This test requires manual verification to confirm whether the Dolby Vision setting has been applied correctly for various picture modes and video formats. The user must respond to a prompt indicating whether the setting is correctly applied.

#### Acceptance Criteria - test52

The system should save the correct Dolby Vision values for all combinations of picture modes and video formats, and the user should be able to confirm the settings through manual verification.

#### Expected Results - test52

The script initializes the TV settings, saves Dolby Vision values for different formats and modes, plays the streams, and prompts the user to verify whether the settings were applied correctly.

Success Criteria

- Dolby Vision values are saved and applied correctly for each combination of picture mode and video format.
- User confirmation matches the expected Dolby Vision settings.

#### Test Steps - test52

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test52_SaveDolbyVision.py`**

2. **Save Dolby Vision Values:**

   - The script initializes the TV settings module and saves Dolby Vision values for all combinations of picture modes and video formats.

3. **Stream Playback:**

   - The script retrieves the list of video formats and corresponding stream URLs.
   - It downloads the individual streams and plays them.

4. **Dolby Vision Verification:**

   - After playing each stream, the script verifies whether the Dolby Vision values were set correctly:
     - User is prompted with: **"Is Dolby Vision '{dolbyVision}' applied for Picture Mode: {pictureMode} and Video Format: {videoFormat}? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

5. **Logging Results:**

   - The script logs results based on user input for each Dolby Vision setting.

6. **Cleanup:**

   - After all verifications, the script stops the stream playback and cleans up the downloaded assets.

7. **Set Default Dolby Vision Again:**

   - After testing, the script sets all Dolby Vision values back to a default value of **'tvDolbyMode_Dark'**.

8. **Test Conclusion:**

   - Once all settings are verified and defaults restored, the script logs the final results based on user responses.

### tvSettings_test53_SavePictureMode.py

#### User Input Required - test53

**Yes**: This test requires manual verification to confirm whether the Picture Mode setting has been applied correctly for various video formats. The user must respond to a prompt indicating whether the setting is correctly applied.

#### Acceptance Criteria - test53

The system should save the correct Picture Mode values for all combinations of video formats, and the user should be able to confirm the settings through manual verification.

#### Expected Results - test53

The script initializes the TV settings, saves Picture Mode values for different formats, plays the streams, and prompts the user to verify whether the settings were applied correctly.

Success Criteria

- Picture Mode values are saved and applied correctly for each combination of video format.
- User confirmation matches the expected Picture Mode settings.

#### Test Steps - test53

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test53_SavePictureMode.py`**

2. **Set Default Picture Mode:**

   - The script initializes the TV settings module and sets all Picture Modes to the default value of **'PQ_MODE_STANDARD'**.

3. **Save Picture Mode Values:**

   - The script saves Picture Mode values for all combinations of video formats.

4. **Stream Playback:**

   - The script retrieves the list of video formats and corresponding stream URLs.
   - It downloads the individual streams and plays them.

5. **Picture Mode Verification:**

   - After playing each stream, the script verifies whether the Picture Mode values were set correctly:
     - User is prompted with: **"Is Picture Mode '{pictureMode}' applied for Video Format: {videoFormat}? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

6. **Logging Results:**

   - The script logs results based on user input for each Picture Mode setting.

7. **Cleanup:**

   - After all verifications, the script stops the stream playback and cleans up the downloaded assets.

8. **Test Conclusion:**

   - Once all settings are verified, the script terminates the TV settings module and logs the final results based on user responses.

### tvSettings_test54_SaveCMS.py

#### User Input Required - test54

**Yes**: This test requires manual verification to confirm whether the CMS (Color Management System) values have been applied correctly for various picture modes and video formats. The user must respond to a prompt indicating whether the settings are correct.

#### Acceptance Criteria - test54

The system should save the correct CMS values for all combinations of picture modes, video formats, component types, and component colors, and the user should be able to confirm the settings through manual verification.

#### Expected Results - test54

The script initializes the TV settings, saves CMS values for different formats, plays the streams, and prompts the user to verify whether the settings were applied correctly.

Success Criteria

- CMS values are saved and applied correctly for each combination of video format, picture mode, component type, and component color.
- User confirmation matches the expected CMS values.

#### Test Steps - test54

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test54_SaveCMS.py`**

2. **Save CMS Values:**

   - The script initializes the TV settings module and saves CMS values for selected formats by cycling through component types and colors.

3. **Stream Playback:**

   - The script retrieves the list of video formats and corresponding stream URLs.
   - It downloads the individual streams and plays them.

4. **CMS Value Verification:**

   - After playing each stream, the script verifies whether the CMS values were set correctly:
     - User is prompted with: **"Is CMS Value '{cmsValue}' applied for Picture Mode '{pictureMode}', Video Format '{videoFormat}', Component Type '{componentType}', and Component Color '{componentColor}'? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

5. **Logging Results:**

   - The script logs results based on user input for each CMS setting.

6. **Cleanup:**

   - After all verifications, the script stops the stream playback and cleans up the downloaded assets.

7. **Log Captured Values:**

   - The script logs the captured CMS values for the video formats tested.

8. **Test Conclusion:**

   - Once all settings are verified, the script terminates the TV settings module and logs the final results based on user responses.

### tvSettings_test55_SaveGammaTable.py

#### User Input Required - test55

**Yes**: This test requires manual verification to confirm whether the gamma table settings have been applied correctly for different color temperatures. The user must respond to a prompt indicating whether the settings are correct.

#### Acceptance Criteria - test55

The system should save the gamma table settings for various color temperatures, and the user should confirm the accuracy of the applied gamma values.

#### Expected Results - test55

The script initializes the TV settings, saves gamma values for specified color temperatures, plays the streams, and prompts the user to verify whether the gamma settings were applied correctly.

Success Criteria

- Gamma table values are saved and applied correctly for each specified color temperature.
- User confirmation matches the expected gamma values.

#### Test Steps - test55

1. **Initiate the Test:**

   - Run the Python script: **`tvSettings_test55_SaveGammaTable.py`**

2. **Set Gamma Values:**

   - The script initializes the TV settings module and sets gamma values for the specified color temperatures.

3. **Stream Playback:**

   - The script retrieves the list of streams from the test setup and plays each stream.

4. **Gamma Value Verification:**

   - After playing each stream, the script verifies whether the gamma values were set correctly:
     - User is prompted with: **"Is Gamma Table set with Size:{size}, R:{red}, G:{green}, B:{blue} for Color Temp: {color_temp}? (Y/N):"**
     - Users respond with **Y** (Yes) or **N** (No) based on the display.

5. **Logging Results:**

   - The script logs results based on user input for each gamma setting.

6. **Cleanup:**

   - After all verifications, the script stops the stream playback.

7. **Test Conclusion:**

   - Once all gamma values are verified, the script terminates the TV settings module and logs the final results based on user responses.
