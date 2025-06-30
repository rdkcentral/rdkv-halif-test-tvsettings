# Unit Testing Suite For TV Settings HAL

## Table of Contents

- [Acronyms, Terms and Abbreviations](#acronyms-terms-and-abbreviations)
- [Description](#description)
- [Reference Documents](#reference-documents)
- [Notes](#notes)

## Acronyms, Terms and Abbreviations

- `HAL`- Hardware Abstraction Layer
- `L3` - Module testing with External Stimulus is required to validate and control device
- `L2` - Functional Tests
- `L1` - Functional Tests

- `High-Level Test Specification` : These specification will provide a broad overview of the system's functionality from the callers' perspective. It focuses on major use cases, system behavior, and overall caller experience.
- `Low-Level Test Specification` : These specification will delve deeper into the technical details. They will define specific test cases with inputs, expected outputs, and pass/fail criteria for individual functionalities, modules, or APIs.

## Description

This repository contains the Unit Test Suites (L1,L2 & L3) for TV Settings `HAL`.

## Reference Documents

|#|Document Name|Document Description|Document Link|
|---|-------------|--------------------|-------------|
|1|`HAL` Specification Document|This document provides specific information on the APIs for which tests are written in this module|[tv-settings_halSpec](https://github.com/rdkcentral/rdkv-halif-tvsettings/blob/main/docs/pages/tv-settings_halSpec.md "tv-settings_halSpec" )|
|2|High-Level Test Spec |High Level Test Specification Documentation|[tv-settings_High_Level_Test_Spec.md]( docs/pages/tv-settings_High_Level_Test_Spec.md)|
|3|`L2` Low Level Test Spec |`L2` Low Level Test Specification and Procedure Documentation|[tv-settings_L2_Low_Level_Test_Spec.md]( docs/pages/tv-settings_L2_Low_Level_Test_Spec.md)|
|4|`L3` Low Level Test Spec |`L3` Low Level Test Specification|[tv-settings_L3_Low_Level_Test_Spec.md]( docs/pages/tv-settings_L3_Low_Level_Test_Spec.md)|
|5|`L3` Test Procedure Document |`L3` Test procedure documentation|[tv-settings_L3_TestProcedure.md]( docs/pages/tv-settings_L3_TestProcedure.md)|

## Notes

- Building against the actual library may introduce SOC dependencies. Hence, a template SKELETON library is created without SOC dependencies. On the real platform (target), it can be mounted, copied and bound with the actual library.
- When executing the binary, ensure to include a platform-specific profile file as an argument for the designated test cases. The following example illustrates this:

```bash
 ./hal_test -p Sink_4K_TvSettings.yaml
 ```

Alternatively, use the run.sh script with the profile file:

```bash
./run.sh -p /absolute/path/to/profile/file
 ```

- Profile files define the configuration for the platform available here [profile yaml file](./profiles/sink/Sink_4K_TvSettings.yaml)
- Install Python Environment and Activation Scripts please check the [HPK Documentation](https://github.com/rdkcentral/rdk-hpk-documentation/blob/main/README.md)

