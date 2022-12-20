# SNAG List for the testing system

|Date|Version|Author|
|----|-------|------|
|19/8/22|1.0|G.Weatherup|

## Functions no longer supported

- wifi_factoryReset()
- wifi_setLED()
- wifi_reset()
- wifi_down()
- wifi_createInitialConfigFiles()
- wifi_createHostApdConfig()
- wifi_startHostApd()
- wifi_stopHostApd()


## Profile based configuration checking


Each platform is expected to have certain capabilities, therefore the Unit Tests should be checking these fields.

This will ensure that the capabilities defined for the hardware, match the capabilities that are being returned from the driver.

The UT suite will be expected to be upgraded to support profile checking and definitions.

Each product, will have a profile defined, this should be downloaded directly to the testing suite, and the testing suite should be capable of checking the values returned for the product.

@remarks: Profile / Capability definition for each platform, this will allow one set of tests to adapt to the requirements based on platform caps

- Supported functions capability checking also required
- SYSTEM_RETURN_IF_UNSUPPORTED_FUNCTION - would be required
- SYSTEM_ASSERT_PROFILE_CHECK - would be required
- SYSTEM_GET_INT_FROM_PROFILE - would be required
- SYSTEM_GET_STRING_FROM_PROFILE - would be required
- verification from 'wl' commands to validate the functions needs to be looked at

Example requirements

```c
wifi_getHalCapability(wifi_hal_capability_t *cap);
```

```c
typedef unsigned char   mac_address_t[6];
typedef char            mac_addr_str_t[18];

typedef mac_address_t   bssid_t;
typedef char            ssid_t[32];
typedef UINT    wifi_radio_index_t;
typedef unsigned int u_int32_t;

typedef char            nas_id_t[49];
typedef unsigned char   r0r1_key_t[16];
typedef char            r0r1_key_str_t[33];

typedef char            wifi_interface_name_t[32];
typedef char            wifi_vap_name_t[64];

typedef struct {
    UINT    major;
    UINT    minor;
}__attribute__((packed)) wifi_hal_version_t;

/**
 * @brief Wifi Radio CSI capabilities
 */
typedef struct {
    UINT maxDevices;              /**< The maximun number of stations that can be configured to collect the CSI data.  Return 0 if CSI is not supported. */
    BOOL soudingFrameSupported;   /**< The value is TRUE, if the radio supports to sending souding frames in the MAC layer. */
}__attribute__((packed)) wifi_radio_csi_capabilities_t;

#define MAXIFACENAMESIZE    64

/**
 * @brief Wifi Radio Capabilities
 */
typedef struct {
    UINT index;
    CHAR ifaceName[MAXIFACENAMESIZE];                                     /**< The interface name. */
    UINT numSupportedFreqBand;                                           /**< The Number of supported frequencies band */
    wifi_freq_bands_t band[MAX_NUM_FREQ_BAND];                           /**< The frequencies band list */
    wifi_channels_list_t channel_list[MAX_NUM_FREQ_BAND];                /**< The list of supported channels for each frequencies band supported. */
    wifi_channelBandwidth_t channelWidth[MAX_NUM_FREQ_BAND];             /**< The Channel Bandwidth supported (uses bitmask to return multiples Bandwidth) for each frequencies band supported.. */
    wifi_ieee80211Variant_t mode[MAX_NUM_FREQ_BAND];                     /**< The supported modes (uses bitmask to return multiples modes) for each frequencies band supported. */
    UINT maxBitRate[MAX_NUM_FREQ_BAND];                                 /**< The maximum PHY bit rate supported for each frequencies band supported. */
    UINT supportedBitRate[MAX_NUM_FREQ_BAND];                           /**< The supported data transmit rates in Mbps for each frequencies band supported. It uses bitmask to return multiples bitrates and wifi_bitrate_t has the definition of valid values*/
    wifi_radio_trasmitPowerSupported_list_t transmitPowerSupported_list[MAX_NUM_FREQ_BAND]; /**< List of transmit power supported for each frequencies band supported. */
    BOOL autoChannelSupported;                                          /**< The value is TRUE, if Auto Channel is supported. */
    BOOL DCSSupported;                                                  /**< The value is TRUE, if DCS is supported. */
    BOOL zeroDFSSupported;                                              /**< The value is TRUE, if Zero DFS is supported. Zero DFS (also known as Background CAC) allows Wi-Fi stack to continue operation on main channel and at the same time run background CAC.*/
    wifi_radio_csi_capabilities_t csi;                                   /**< CSI capabilities */
    UINT cipherSupported;                                                /**< The list of supported cipher (uses bitmask to return multiples values). */
    UINT numcountrySupported;                                            /**< Number of supported countries. */
    wifi_countrycode_type_t countrySupported[wifi_countrycode_max];      /**< The Supported country list. it should return the current country code on first entry. */
    UINT maxNumberVAPs;                                                  /**< Max number of VAPs */
}__attribute__((packed)) wifi_radio_capabilities_t;

/**
 * @brief Wifi interface Property info
 */
typedef struct {
    unsigned int     phy_index;           /**< actual index of the phy device */
    unsigned int     rdk_radio_index;     /**< radio index of upper layer */
    wifi_interface_name_t  interface_name;
    wifi_interface_name_t  bridge_name;
    int              vlan_id;
    BOOL             primary;
    unsigned int     index;
    wifi_vap_name_t  vap_name;
}__attribute__((packed)) wifi_interface_name_idex_map_t;

typedef struct {
     UINT numRadios;                               /**< Number of radios. */
     wifi_radio_capabilities_t radiocap[MAX_NUM_RADIOS]; /**< Radio capabilities */
     wifi_interface_name_idex_map_t interface_map[(MAX_NUM_RADIOS * MAX_NUM_VAP_PER_RADIO)];
}__attribute__((packed)) wifi_platform_property_t;

typedef struct {
    wifi_hal_version_t  version;            /**< The HAL version. */
    wifi_platform_property_t wifi_prop;     /**< The plataform Property that includes the number of radios and supported frequency bands. */
    BOOL BandSteeringSupported;             /**< If BandSteeringSupported is TRUE, bandsteering is support by the HAL */
}__attribute__((packed)) wifi_hal_capability_t;
```

### Example yaml configuration file not completely sure yet if this is feasible

```yaml
wifi_hal_capability:
    length: xxx

    version:
        major:
            type: UINT
            value: 3
        minor:
            type: UINT
            value: 0

    wifi_prop:
        numRadios:
            type: UINT
            value: 3

        #radiocap:
        #    1:
        #        blah
        #    2:
        #    3:

    interface_map:

#typedef struct {
    #unsigned int     phy_index;           /**< actual index of the phy device */
    #unsigned int     rdk_radio_index;     /**< radio index of upper layer */
    #wifi_interface_name_t  interface_name;
    #wifi_interface_name_t  bridge_name;
    #int              vlan_id;
    #BOOL             primary;
    #unsigned int     index;
    #wifi_vap_name_t  vap_name;
#}__attribute__((packed)) wifi_interface_name_idex_map_t;

        1:
            phy_index:
                type: UINT
                value: 0
            rdk_radio_index:
                type: UINT
                value: 0
            interface:
                type: STRING
                value: "radio 1"
            bridge_name:
                type: STRING
                value: "bridge 1"
            vlan_id:
                type: INT
                value: xx
            primary:
                type: BOOL
                value: xx
            index:
                type: UINT
                value: xx

            vap_name:
                type: STRING
                value: xx

    BandSteeringSupported: 
        type: BOOL
        value: FALSE

```
