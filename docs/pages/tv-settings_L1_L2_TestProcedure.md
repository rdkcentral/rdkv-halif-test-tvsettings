# tv-settings HAL L1 and L2 Test Procedure

## Table of Contents

- [Acronyms, Terms and Abbreviations](#acronyms-terms-and-abbreviations)
- [Run L1 and L2 Test directly (without python)](#run-l1-and-l2-test-directly-without-python)
- [Run L1 and L2 using python](#run-l1-and-l2-using-python)
  - [Setting Up Test Environment](#setting-up-test-environment)
  - [Update Configuration Files](#update-configuration-files)
  - [Run Test Cases](#run-test-cases)

## Acronyms, Terms and Abbreviations

- `HAL`    - Hardware Abstraction Layer
- `L1`     - Level 1 Testing
- `L2`     - Level 2 Testing
- `DUT`    - Device Under Test
- `RAFT`   - Rapid Automation Framework for Testing
- `YAML`   - YAML Ain't Markup Language

## Run L1 and L2 Test directly (without python)

Refer [Running L1 and L2 Test suits](https://github.com/rdkcentral/rdk-hpk-documentation/tree/1.4.5?tab=readme-ov-file#running-the-l1-l2-test-suite-on-the-target)

## Run L1 and L2 using python

### Setting Up Test Environment

To execute `HAL` `L1` and `L2` Python test cases, need a Python environment. Follow these steps mentioned in [HPK Public Documentation](https://github.com/rdkcentral/rdk-hpk-documentation/?tab=readme-ov-file#installing-the-python-environment-for-l3-testing-suite)

### Update Configuration Files

#### Rack Configuration File

Example Rack configuration File: [example_rack_config.yml](../../../../ut/host/tests/configs/example_rack_config.yml)

For more details refer [RAFT](https://github.com/rdkcentral/python_raft/blob/1.0.0/README.md) and [example_rack_config.yml](https://github.com/rdkcentral/python_raft/blob/1.0.0/examples/configs/example_rack_config.yml)

In this file, update the configuration to define the console sessions for the `DUT` and the outbound settings:

|Console Session|Description|
|---------------|-----------|
|default|Used by raft|
|ssh_hal_test|To run the `HAL` binary|

```yaml
rackConfig:
  - dut:
      ip: "XXX.XXX.XXX.XXX"  # IP Address of the device
      description: "stb device under test"
      platform: "stb"
      consoles:
        - default:
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
        download_url: "http://localhost:8000/"    # download location for the CPE device
        httpProxy:   # Local Proxy if required
        workspaceDirectory: './logs/workspace'   # Local working directory
```

#### Device Configuration File

Example Device configuration File: [deviceConfig.yml](ut/host/tests/configs/deviceConfig.yml)

For more details refer [RAFT](https://github.com/rdkcentral/python_raft/blob/1.0.0/README.md) and [example_device_config.yml](https://github.com/rdkcentral/python_raft/blob/1.0.0/examples/configs/example_device_config.yml)

Update below fields in the device configuration file:

- Set the path for `target_directory` where `HAL` binaries will be copied onto the device.
- Specify the device profile path in `test/profile`
- Ensure the `platform` should match with the `DUT` `platform` in [Rack Configuration](#rack-configuration-file)

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
```

#### Test Setup Configuration File

Example Test Setup configuration File: [tvSettings_L1_L2_testSetup.yml](../../../../ut/host/tests/L1_L2_TestCases/tvSettings/tvSettings_L1_L2_testSetup.yml)

This `yaml` contains the list of test_suites and test_cases to run

eg:
```yaml
tvSettings:
  description: "tvSettings L1 and L2 test setup"
  test_suites: # List of test suites to run
    - name: "L1 tvSettings"
      test_cases: # List of test cases to execute, to run all test cases in test suite with R option use `all`
        - all
    - name: "L1 tvSettings"
      test_cases:
        - TvInit_pos
        - TvInit_neg
        - TvTerm_pos
        - TvTerm_neg
        - GetTVSupportedVideoFormats_pos
        - GetTVSupportedVideoFormats_neg
        - GetCurrentVideoFormat_pos
        - GetCurrentVideoFormat_neg
        - GetCurrentVideoResolution_pos
    - name: "L2 tvSettings"
      test_cases:
        - GetSupportedVideoFormats
        - GetCurrentVideoFormat_NoVideoPlayback
        - VerifyCurrentVideoResolution
        - VerifyFrameRateWhenStopped
```

#### Test Configuration

Example Test Setup configuration File: [tvSettings_testConfig.yml](../../../../ut/host/tests/Classes/tvSettings_testConfig.yml)

Execute command to run the HAL binary was provided in this file.

```yaml
tvSettings:
    description: "tvSettings testing profile / menu system for UT"
    test:
        artifacts:
        #List of artifacts folders, test class copies the content of folder to the target device workspace
          - "../../../bin/"
        # exectute command, this will appended with the target device workspace path
        execute: "run.sh"
        type: UT-C # C (UT-C Cunit) / C++ (UT-G (g++ ut-core gtest backend))
```

### Run Test Cases

Once the environment is set up, you can execute the test cases with the following command

```bash
python dsAudio_L1_L2_tests.py --config </PATH>/ut/host/tests/configs/example_rack_config.yml --deviceConfig </PATH>/ut/host/tests/configs/deviceConfig.yml
```
