# Level 2 HAL Testing Specification

## History

|Version|Date (YY-MM-DD)|Author|Comments|
|-------|-----|-----|----|
|1.0.0| 31/08/21 |Gerald Weatherup|Draft Revision|

## Document Scope

This document will define the requirements for testing for this HAL.

## Table of Contents

- [Overview](#overview)
- [Acronyms](#acronyms)
- [Definitions](#definitions)
- [References](#references)
- [Testing Requirements](#testing-requirements)
- [Top Level Testing Requirements](#top-level-testing-requirements)

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
  - `ut-core` - Common Testing Framework [https://github.com/comcast-sky/rdk-components-ut-core], which wraps a open-source framework that can be expanded to the requirements for future comcast-sky framework.

## References

- `Feedback Loops` \- [https://www.softwaretestingnews.co.uk/4-methods-to-improve-your-feedback-loops-and-supercharge-your-testing-process/]
- `Doxygen` \- SourceCode documentation tool - [https://www.doxygen.nl/index.html]
- `Black Box Testing` \- [https://en.wikipedia.org/wiki/Black-box_testing]

## Testing Requirements

The following level 2 tests are to be expected at this state.


### Top Level Testing Requirements

|Main Focus|Description|
|----------|-----------|
|SSID| Testing scenario's for all radio's setting the SSID|
|TBC| Review of TDK HAL Testings is required |
|TBC| Review of QA Requirements is required |

### SSID Checks

Basic L2 SSID checks have been created, but focus on the testing specification, for the requirements for this level of testing, needs to be clearly defined.

| Test | Purpose|
|------|---------|
|setValidSSID_2Ghz| Check SSID is capable on 2Ghz|
|setValidSSID_5Ghz| Check SSID is capable on 5Ghz|
|setValidSSID_6Ghz| Check SSID is capable on 6Ghz|
|setNULLSSID_2Ghz| Set SSID is as NULL, API should fail|
|setNULLSSID_5Ghz| Set SSID is as NULL, API should fail|
|setNULLSSID_6Ghz| Set SSID is as NULL, API should fail|
