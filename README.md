# Unit Testing Suite For TV Settings HAL

## Table of Contents

- [Acronyms, Terms and Abbreviations](#acronyms-terms-and-abbreviations)
- [Description](#description)
- [Reference Documents](#reference-documents)
- [Notes](#notes)

## Acronyms, Terms and Abbreviations

- `L1` - Functional Tests
- `HAL`- Hardware Abstraction Layer

## Description

This repository contains the Unit Test Suites L1 for TV Settings `HAL`.

## Reference Documents

|SNo|Document Name|Document Description|Document Link|
|---|-------------|--------------------|-------------|
|1|`HAL` Specification Document|This document provides specific information on the APIs for which tests are written in this module|[tv-settings_halSpec](https://github.com/rdkcentral/rdkv-halif-tvsettings/blob/main/docs/pages/tv-settings_halSpec.md "tv-settings_halSpec" )|
|2|`L1` Tests | `L1` Test Case File for this module | [test_l1_tvSettings.c]( https://github.com/rdkcentral/rdkv-halif-test-tvsettings/blob/main/src/test_l1_tvSettings.c         "test_l1_tvSettings.c" )|

## Notes

- Building against the actual library may introduce SOC dependencies. Hence, a template SKELETON library is created without SOC dependencies. On the real platform (target), it can be mounted, copied and bound with the actual library.
- To run the binary, ensure that you pass the configuration file as an argument. The following example demonstrates how to do this:  ./hal_test pq_capablities.ini
- Template avaliable in [pq_capablities.ini](https://github.com/rdkcentral/rdkv-halif-tvsettings/tree/main/config/pq_capablities.ini "pq_capablities.ini")
