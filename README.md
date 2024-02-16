# Unit Testing Suite For TV Settings HAL

## Table of Contents

- [Acronyms, Terms and Abbreviations](#acronyms-terms-and-abbreviations)
- [Description](#description)
- [Reference Documents](#reference-documents)

## Acronyms, Terms and Abbreviations

- `L1` - Functional Tests
- `L2` - Module (Functional) Tests
- `HAL`- Hardware Abstraction Layer

## Description

This repository contains the Unit Test Suites L1 for TV Settings HAL.

## Reference Documents

<!-- Need to update links to point to correct repo -->
|SNo|Document Name|Document Description|Document Link|
|---|-------------|--------------------|-------------|
|1|`HAL` Specification Document|This document provides specific information on the APIs for which tests are written in this module|[tv-settings_halSpec](https://github.com/comcast-sky/rdk-components-hal-tvsettings/blob/develop/docs/pages/tv-settings_halSpec.md "tv-settings_halSpec" )|
|2|`L1` Tests | `L1` Test Case File for this module | [test_l1_tvSettings.c]( https://github.com/comcast-sky/rdk-components-haltest-tvsettings/blob/master/src/test_l1_tvsettings.c         "test_l1_tvSettings.c" )|

## Note

- To run the binary, ensure that you pass the configuration file as an argument. The following example demonstrates how to do this:                             ./hal_test pq_capablities.ini
