# Level 1 HAL Testing Specification

## History

|Version|Date (YY-MM-DD)|Author|
|-------|-----|-----|
|1.0.0| 31/08/22 |Gerald Weatherup|

## Overview

This document will define the requirements for Level 1 testing for this HAL.

## Table of Contents

- [Overview](#overview)
- [Acronyms](#acronyms)
- [Definitions](#definitions)
- [References](#references)
- [L1 Testing Requirements](#l1-testing-requirements)

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
  - `ut-core` - Common Testing Framework [https://github.com/comcast-sky/rdk-components-ut-core]

## References

- `Feedback Loops` \- [https://www.softwaretestingnews.co.uk/4-methods-to-improve-your-feedback-loops-and-supercharge-your-testing-process/]
- `Doxygen` \- SourceCode documentation tool - [https://www.doxygen.nl/index.html]
- `Black Box Testing` \- [https://en.wikipedia.org/wiki/Black-box_testing]

## L1 Testing Requirements

As per the definition of the header files, take all the API's possible and create positive and negative test cases to ideally exercise the complete interface.

The interface is defined by the git repository `[git@github.com:comcast-sky/rdk-components-hal-wifi-rdkb.git]` which is accessible via the link [https://github.com/comcast-sky/rdk-components-hal-wifi-rdkb]

from the template in `ut-core/framework/hal_template` the `UT` suite will be triggered.

## wifi_hal_ap.h

```c
INT wifi_getApAssociatedDevice(INT apIndex, mac_address_t *opDeviceMacAddArray, UINT maxNumDevices, UINT *opNumOfDevices);
INT wifi_enableCSIEngine(INT apIndex, mac_address_t sta, BOOL enable);
INT wifi_getRadioVapInfoMap(wifi_radio_index_t index, wifi_vap_info_map_t *map);
INT wifi_kickAssociatedDevice(INT apIndex, wifi_device_t *device);
void wifi_newApAssociatedDevice_callback_register(wifi_newApAssociatedDevice_callback callback_proc);
void wifi_apDeAuthEvent_callback_register(wifi_apDeAuthEvent_callback callback_proc);
void wifi_apDisassociatedDevice_callback_register(wifi_apDisassociatedDevice_callback callback_proc);
```

## wifi_hal_extender.hal

```c
INT wifi_getRadioChannelStats(INT radioIndex, wifi_channelStats_t *input_output_channelStats_array, INT array_size);
```

## wifi_hal_generic.h

```c
INT wifi_init(void);
INT wifi_getHalCapability(wifi_hal_capability_t *cap);
```

## wfi_hal_radio.h

```c
INT wifi_getRadioTransmitPower(INT radioIndex, ULONG *opRadioTxPower);
INT wifi_getRadioOperatingChannelBandwidth(INT radioIndex, CHAR *opRadioOpChnBw);
INT wifi_setRadioOperatingParameters(wifi_radio_index_t index, wifi_radio_operationParam_t *operationParam);
void wifi_scanResults_callback_register(wifi_scanResults_callback callback_proc);
```


## wifi_hal_sta.h

```c
INT wifi_startScan(wifi_radio_index_t index, wifi_neighborScanMode_t scan_mode, INT dwell_time, UINT num, UINT *chan_list);
INT wifi_connect(INT apIndex, wifi_bss_info_t *bss);
INT wifi_disconnect(INT apIndex);
void wifi_staConnectionStatus_callback_register(wifi_staConnectionStatus_callback callback_proc);
```

## wifi_hal_telemetry.h

```c
INT wifi_getRadioBandUtilization(INT radioIndex, INT *output_percentage);
INT wifi_getApAssociatedClientDiagnosticResult(INT apIndex, mac_address_t mac_addr, wifi_associated_dev3_t *dev_conn);
INT wifi_getRadioTrafficStats2(INT radioIndex, wifi_radioTrafficStats2_t *opRadioTrafficStats);
```

## wifi_hal_client_mgt.h

- **This interface is still TBC to be reviewed from a documentation standpoint and approved for testing.**

```c
INT wifi_getBandSteeringEnable(BOOL *enable);
INT wifi_setBandSteeringEnable(BOOL enable);
INT wifi_getBandSteeringApGroup(char *output_ApGroup);    
INT wifi_setBandSteeringApGroup(char *ApGroup); 
INT wifi_getBandSteeringBandUtilizationThreshold (INT radioIndex, INT *pBuThreshold);
INT wifi_setBandSteeringBandUtilizationThreshold (INT radioIndex, INT buThreshold);
INT wifi_getBandSteeringRSSIThreshold (INT radioIndex, INT *pRssiThreshold);
INT wifi_setBandSteeringRSSIThreshold (INT radioIndex, INT rssiThreshold);
INT wifi_getBandSteeringPhyRateThreshold (INT radioIndex, INT *pPrThreshold);
INT wifi_setBandSteeringPhyRateThreshold (INT radioIndex, INT prThreshold); 
INT wifi_getBandSteeringOverloadInactiveTime (INT radioIndex, INT *overloadInactiveTime); //If chip is not support, return -1
INT wifi_setBandSteeringOverloadInactiveTime (INT radioIndex, INT overloadInactiveTime); //If chip is not support, return -1
INT wifi_getBandSteeringIdleInactiveTime (INT radioIndex, INT *idleInactiveTime); //If chip is not support, return -1
INT wifi_setBandSteeringIdleInactiveTime (INT radioIndex, INT idleInactiveTime); //If chip is not support, return -1
INT wifi_getBandSteeringLog(INT record_index, ULONG *pSteeringTime, CHAR *pClientMAC, INT *pSourceSSIDIndex, INT *pDestSSIDIndex, INT *pSteeringReason); 
INT wifi_getApAssociatedDevicesHighWatermarkThreshold(INT apIndex, UINT *output);
INT wifi_setApAssociatedDevicesHighWatermarkThreshold(INT apIndex, UINT Threshold);
INT wifi_getApAssociatedDevicesHighWatermarkThresholdReached(INT apIndex, UINT *output);
INT wifi_getApAssociatedDevicesHighWatermark(INT apIndex, UINT *output);
INT wifi_getApAssociatedDevicesHighWatermarkDate(INT apIndex, ULONG *output_in_seconds);
INT wifi_setFastBSSTransitionActivated(INT apIndex, UCHAR activate);
INT wifi_getBSSTransitionActivated(INT apIndex, BOOL *activate);
INT wifi_setEAP_Param(UINT apIndex, UINT value, char  *param);
INT wifi_getEAP_Param(UINT apIndex, wifi_eap_config_t *output);
INT wifi_getFTOverDSActivated(INT apIndex, BOOL *activate);
INT wifi_setFTOverDSActivated(INT apIndex, BOOL *activate);
INT wifi_getFTMobilityDomainID(INT apIndex, UCHAR mobilityDomain[2]);
INT wifi_setFTMobilityDomainID(INT apIndex, UCHAR mobilityDomain[2]);
INT wifi_getFTResourceRequestSupported(INT apIndex, BOOL *supported);
INT wifi_setFTResourceRequestSupported(INT apIndex, BOOL *supported);
INT wifi_getFTR0KeyLifetime(INT apIndex, UINT *lifetime);
INT wifi_setFTR0KeyLifetime(INT apIndex, UINT *lifetime);
INT wifi_getFTR0KeyHolderID(INT apIndex, UCHAR *keyHolderID);
INT wifi_setFTR0KeyHolderID(INT apIndex, UCHAR *keyHolderID);
INT wifi_getFTR1KeyHolderID(INT apIndex, UCHAR *keyHolderID);
INT wifi_setFTR1KeyHolderID(INT apIndex, UCHAR *keyHolderID);
INT wifi_pushApFastTransitionConfig(INT apIndex, wifi_FastTransitionConfig_t *ftData);
INT wifi_setBSSTransitionActivation(UINT apIndex, BOOL activate);
INT wifi_getBSSTransitionActivation(UINT apIndex, BOOL *activate);
INT wifi_setNeighborReportActivation(UINT apIndex, BOOL activate);
INT wifi_getNeighborReportActivation(UINT apIndex, BOOL *activate);
```
