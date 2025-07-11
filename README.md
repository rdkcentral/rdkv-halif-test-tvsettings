# Unit Testing Suite For TV Settings HAL

## Table of Contents

- [Acronyms, Terms and Abbreviations](#acronyms-terms-and-abbreviations)
- [Description](#description)
- [Reference Documents](#reference-documents)
- [How to build the test suite](#how-to-build-the-test-suite)
- [Notes](#notes)
- [Manual way of running the L1 and L2 test cases](#manual-way-of-running-the-l1-and-l2-test-cases)
- [Setting Python environment for running the L1 L2 and L3 automation test cases](#setting-python-environment-for-running-the-l1-l2-and-l3-automation-test-cases)

## Acronyms, Terms and Abbreviations

- `HAL`- Hardware Abstraction Layer
- `L3` - Module testing with External Stimulus is required to validate and control device
- `L2` - Functional Tests
- `L1` - Functional Tests

- `High-Level Test Specification` : These specification will provide a broad overview of the system's functionality from the callers' perspective. It focuses on major use cases, system behavior, and overall caller experience.
- `Low-Level Test Specification` : These specification will deeper into the technical details. They will define specific test cases with inputs, expected outputs, and pass/fail criteria for individual functionalities, modules, or APIs.

## Description

This repository contains the Unit Test Suites (L1,L2 & L3) for TV Settings `HAL`.

## Reference Documents

|#|Document Name|Document Description|Document Link|
|---|-------------|--------------------|-------------|
|1|`HAL` Specification Document|This document provides specific information on the APIs for which tests are written in this module|[tv-settings_halSpec](https://github.com/rdkcentral/rdkv-halif-tvsettings/blob/main/docs/pages/tv-settings_halSpec.md "tv-settings_halSpec" )|
|2|High-Level Test Spec |High Level Test Specification Documentation|[tv-settings_High_Level_Test_Spec.md]( docs/pages/tv-settings_High_Level_Test_Spec.md)|
|3|`L2` Low Level Test Spec |`L2` Low Level Test Specification and Procedure Documentation|[tv-settings_L2_Low_Level_Test_Spec.md]( docs/pages/tv-settings_L2_Low_Level_Test_Spec.md)|
|4|`L1` and `L2` Test Procedure Document |`L1` and `L2` Test procedure documentation|[tv-settings_L1_L2_TestProcedure.md]( docs/pages/tv-settings_L1_L2_TestProcedure.md)|
|5|`L3` Low Level Test Spec |`L3` Low Level Test Specification|[tv-settings_L3_Low_Level_Test_Spec.md]( docs/pages/tv-settings_L3_Low_Level_Test_Spec.md)|
|6|`L3` Test Procedure Document |`L3` Test procedure documentation|[tv-settings_L3_TestProcedure.md]( docs/pages/tv-settings_L3_TestProcedure.md)|

## Notes

- Building against the actual library may introduce SOC dependencies. Hence, a template SKELETON library is created without SOC dependencies. On the real platform (target), it can be mounted, copied and bound with the actual library.
- When executing the binary, ensure to include a platform-specific profile file as an argument for the designated test cases.

## How to build the test suite

In order to build the test suits, there is a requirement to supply the toolchain, either as a vendor independent toolchain, an SDK, or an RDK Docker Toolchain .

For more information about RDK Docker Toolchain, please check [RDK Docker Toolchain](https://github.com/rdkcentral/ut-core/wiki/FAQ:-RDK-Docker-Toolchain)

- Export the Toolchain Path:

```bash
export TOOLCHAIN_PATH=/opt/toolchains/rdk-glibc-x86_64/sysroots/armv7at2hf-neon-rdk-linux-gnueabi
export CC="arm-rdk-linux-gnueabi-gcc  -march=armv7-a -mthumb -mfpu=neon -mfloat-abi=hard --sysroot=$TOOLCHAIN_PATH"
```

- Clone the `HAL` Repository:

```bash
git clone git@github.com:rdkcentral/rdkv-halif-tvsettings.git
```
- Set Project Version:

If you want to build the test repository with a specific tag or branch, set the UT_PROJECT_VERSION variable accordingly. If not set, the default main branch will be used.

```bash
export UT_PROJECT_VERSION=1.0.1  # Build using a specific tag
```

or

```bash
export UT_PROJECT_VERSION=develop  # Build using a specific branch
```

- Build Targets:

 There are two targets for the platform

  1. linux - (default)
  2. arm - TARGET=arm

```bash
build_ut.sh TARGET=arm
```

- `build_ut.sh` script will clone the hal-test repo, ut-core and generate a `hal_test_tvsettings-hal` binary in `ut/bin/` upon successful completion.

### Manual way of running the `L1` and `L2` test cases

```bash
 ./hal_test_tvsettings-hal -p Sink_4K_TvSettings.yaml
 ```

Alternatively, use the run.sh script with the profile file:
```bash
./run.sh -p /absolute/path/to/profile/file
 ```

- Profile files define the configuration for the platform available here [profile yaml file](./profiles/sink/Sink_4K_TvSettings.yaml)

### Setting Python environment for running the `L1` `L2` and `L3` automation test cases

- For running the `L1` `L2` and `L3` test suite, a host PC or server with a Python environment is required.
- Install Python Environment and Activation Scripts as detailed in the [HPK Documentation](https://github.com/rdkcentral/rdk-hpk-documentation/tree/main?tab=readme-ov-file#installing-the-python-environment-for-l3-testing-suite)
- To run the `L3` test cases follow the [tv-settings_L3_TestProcedure.md](docs/pages/tv-settings_L3_TestProcedure.md)

