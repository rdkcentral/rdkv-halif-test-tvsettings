/**
*  If not stated otherwise in this file or this component's LICENSE
*  file the following copyright and licenses apply:
*
*  Copyright 2023 RDK Management
*
*  Licensed under the Apache License, Version 2.0 (the License);
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*  http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an AS IS BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
*/

/**
 * @addtogroup HPK Hardware Porting Kit
 * @{
 * @par The Hardware Porting Kit
 * HPK is the next evolution of the well-defined Hardware Abstraction Layer
 * (HAL), but augmented with more comprehensive documentation and test suites
 * that OEM or SOC vendors can use to self-certify their ports before taking
 * them to RDKM for validation or to an operator for final integration and
 * deployment. The Hardware Porting Kit effectively enables an OEM and/or SOC
 * vendor to self-certify their own Video Accelerator devices, with minimal RDKM
 * assistance.
 *
 */

/**
 * @addtogroup TV_Settings TV Settings Module
 * @{
 */

/**
 * @addtogroup TV_Settings_HALTEST TV Settings HAL Tests
 * @{
 */

/**
 * @defgroup TV_Settings_HALTEST_CAPS_REPOSITORY TV Settings HAL Tests Caps Repository File
 *  @{
 * @parblock
 *
 * ### VTS Capability Repository for TV_Settings HAL :
 *
 * This is to ensure that the API meets the operational requirements of the module across all vendors.
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 *
 * @endparblock
 */

/**
* @file vts_capability_repository.h
*
*/

#ifndef __VTS_CAPABILITY_REPOSITORY_H_
#define __VTS_CAPABILITY_REPOSITORY_H__

#include <unistd.h>

#include "tvSettings.h"

/*********************************************************************
 *              Expected Capability Structures
 *********************************************************************/

/*
 * Represents a single valid context combination of picture mode, 
 * source and format.
 *
 * Example:
 *   PQ Mode  : Standard
 *   Format   : SDR
 *   Source   : HDMI1
 *
 * Expected values are generated from the YAML and compared against
 * tvConfigContext_t entries returned by HAL.
 */
typedef struct
{
    tvPQModeIndex_t     pqMode;
    tvVideoFormatType_t format;
    tvVideoSrcType_t    source;
} ExpectedConfigContext_t;

/*
 * Represents all valid context combinations for a capability.
 *
 * Example:
 *    Brightness
 *    Contrast
 *    ColorTemperature
 *
 * Each entry corresponds to one expected tvConfigContext_t
 */
typedef struct
{
    size_t numContextGroups;
    size_t numContexts;
    ExpectedConfigContext_t *contexts;
} ExpectedContextCaps_t;

/*
* Expected capability for range based properties.
*
* Used by:
*   Brightness
*   Contrast
*   Sharpness
*   Backlight
*   Hue
*   Saturation
*   Low Latency State
*/
typedef struct
{
    int minValue;
    int maxValue;
    ExpectedContextCaps_t contextCaps;
} ExpectedRangeCaps_t;
 
/*
* Expected capability for enum based properties.
*
* Stores the supported enum values and the contexts
* in which those values are valid.
*
* Used by:
*   ColorTemperature
*   AspectRatio
*   DimmingMode
*   BacklightMode
*   PictureMode
*/
typedef struct
{
    int *values;
    size_t numValues;
    ExpectedContextCaps_t contextCaps;
} ExpectedEnumCaps_t;
 
/*
* Expected capability for CMS.
*
* Stores:
*   Hue range
*   Saturation range
*   Luma range
*   Supported colors
*   Supported components
*   Supported contexts
*/
typedef struct
{
    int hueMin;
    int hueMax;
    int saturationMin;
    int saturationMax;
    int lumaMin;
    int lumaMax;
    tvDataComponentColor_t *colors;
    size_t numColors;
    tvComponentType_t *components;
    size_t numComponents;
    ExpectedContextCaps_t contextCaps;
    size_t numContexts;
} ExpectedCMSCaps_t;
 
/*
* Expected capability for 2 Point White Balance.
*
* Stores:
*   Gain range
*   Offset range
*   Supported colors
*   Supported controls
*   Supported color temperatures
*   Supported contexts
*/
typedef struct
{
    int minGain;
    int maxGain;
    int minOffset;
    int maxOffset;
    tvWBColor_t *colors;
    size_t numColors;
    tvWBControl_t *controls;
    size_t numControls;
    tvColorTemp_t *colorTemps;
    size_t numColorTemps;
    ExpectedContextCaps_t contextCaps;
} Expected2PointWBCaps_t;
 
/*
* Expected capability for Multi Point White Balance.
*
* Stores:
*   Number of matrix points
*   RGB min/max limits
*   Supported contexts
*/
typedef struct
{
    int points;
    int rgbMin;
    int rgbMax;
    ExpectedContextCaps_t contextCaps;
} ExpectedMultiPointWBCaps_t;
 
/*
* Expected capability for Video Source.
*
* Stores all video sources supported by the platform.
*
* Used by:
*   GetVideoSourceCaps()
*
* Example:
*   HDMI1
*   HDMI2
*   HDMI3
*   HDMI4
*   IP
*   Tuner
*   Composite1
*
* This capability is global and does not contain
* any context information.
*/
typedef struct
{
    tvVideoSrcType_t *sources;
    size_t numSources;
} ExpectedVideoSourceCaps_t;
 
/*
* Expected capability for Video Format.
*
* Stores all video formats supported by the platform.
*
* Used by:
*   GetVideoFormatCaps()
*
* Example:
*   SDR
*   HDR10
*   HLG
*   DV
*
* This capability is global and does not contain
* any context information.
*/
typedef struct
{
    tvVideoFormatType_t *formats;
    size_t numFormats;
} ExpectedVideoFormatCaps_t;
 
/*
* Expected capability for Video Resolution.
*
* Stores all video resolutions supported by the platform.
*
* Used by:
*   GetVideoResolutionCaps()
*
* Example:
*   480p
*   720p
*   1080p
*   2160p
*
* This capability is global and does not contain
* any context information.
*/
typedef struct
{
    tvVideoResolution_t *resolutions;
    size_t numResolutions;
} ExpectedVideoResolutionCaps_t;
 
/*
* In-memory capability repository.
*
* Populated once from YAML during VTS initialization.
*
* Serves as the source of expected capabilities during
* capability validation.
**/
typedef struct
{
    ExpectedRangeCaps_t backlight;
    ExpectedRangeCaps_t brightness;
    ExpectedRangeCaps_t contrast;
    ExpectedRangeCaps_t sharpness;
    ExpectedRangeCaps_t saturation;
    ExpectedRangeCaps_t hue;
    ExpectedRangeCaps_t lowLatencyState;
 
    ExpectedEnumCaps_t dimmingMode;
    ExpectedEnumCaps_t colorTemperature;
    ExpectedEnumCaps_t aspectRatio;
    ExpectedEnumCaps_t pictureMode;
    ExpectedEnumCaps_t backlightMode;
 
    ExpectedCMSCaps_t cms;
    Expected2PointWBCaps_t wb2Point;
    ExpectedMultiPointWBCaps_t multiPointWb;
 
    ExpectedVideoSourceCaps_t videoSource;
    ExpectedVideoFormatCaps_t videoFormat;
 
} CapabilityDatabase_t;

extern CapabilityDatabase_t gCapsDb;

/**
 * @brief Initialize the capability database from the YAML profile.
 *
 * Loads all expected capabilities defined in the TV Settings YAML
 * profile and populates the global capability repository.
 *
 * Initialization includes:
 *   - Loading enum definitions from the _defs section.
 *   - Loading all capability definitions.
 *   - Expanding context combinations.
 *   - Populating gCapsDb.
 *
 * This API must be invoked once before executing any
 * Get*Caps capability validation tests.
 *
 * @param None
 *
 * @return true if initialization succeeds.
 * @return false if YAML parsing or capability loading fails.
 */
bool CapabilityDatabase_Init(void);

/**
 * @brief Validate a range-based capability against the expected YAML capability.
 *
 * Compares the maximum supported value returned by the HAL against the
 * expected range information loaded from YAML. Also validates all supported
 * contexts associated with the capability.
 *
 * Used for capabilities such as Brightness, Contrast, Sharpness,
 * Saturation, Hue, Backlight, MEMC, AISuperResolution,
 * LocalContrastEnhancement, DigitalNoiseReduction,
 * MPEGNoiseReduction, BacklightDimmingLevel and LowLatencyState.
 *
 * @param expected Expected capability loaded from YAML.
 * @param actualMax Maximum value returned by the HAL API.
 * @param actualContexts Context capabilities returned by the HAL API.
 *
 * @return true if capability validation succeeds, false otherwise.
 */
bool ValidateRangeProperty(
        const ExpectedRangeCaps_t *expected,
        int actualMax,
        tvContextCaps_t *actualContexts);

/**
 * @brief Validate an enum-based capability against the expected YAML capability.
 *
 * Compares the supported enum values returned by the HAL against the
 * expected supported values loaded from YAML. Also validates all
 * associated contexts.
 *
 * Used for capabilities such as ColorTemperature, AspectRatio,
 * PictureMode, DimmingMode and BacklightMode.
 *
 * @param expected Expected capability loaded from YAML.
 * @param actualValues Enum values returned by the HAL API.
 * @param actualCount Number of enum values returned by the HAL API.
 * @param actualContexts Context capabilities returned by the HAL API.
 *
 * @return true if capability validation succeeds, false otherwise.
 */
bool ValidateEnumProperty(
        const ExpectedEnumCaps_t *expected,
        int *actualValues,
        size_t actualCount,
        tvContextCaps_t *actualContexts);

/**
 * @brief Validate CMS capabilities against the expected YAML capability.
 *
 * Compares supported CMS ranges, colors, components and contexts
 * returned by the HAL against the expected values loaded from YAML.
 *
 * Validation includes:
 *   - Hue range
 *   - Saturation range
 *   - Luma range
 *   - Supported colors
 *   - Supported components
 *   - Supported contexts
 *
 * @param expected Expected CMS capability loaded from YAML.
 * @param actualMaxHue Maximum supported hue value returned by HAL.
 * @param actualMaxSaturation Maximum supported saturation value returned by HAL.
 * @param actualMaxLuma Maximum supported luma value returned by HAL.
 * @param actualColors Supported CMS colors returned by HAL.
 * @param actualComponents Supported CMS components returned by HAL.
 * @param actualNumColors Number of supported colors.
 * @param actualNumComponents Number of supported components.
 * @param actualContexts Context capabilities returned by HAL.
 *
 * @return true if capability validation succeeds, false otherwise.
 */
bool ValidateCMSProperty(
        const ExpectedCMSCaps_t *expected,
        int actualMaxHue,
        int actualMaxSaturation,
        int actualMaxLuma,
        tvDataComponentColor_t *actualColors,
        tvComponentType_t *actualComponents,
        size_t actualNumColors,
        size_t actualNumComponents,
        tvContextCaps_t *actualContexts);

/**
 * @brief Validate 2 Point White Balance capabilities against the expected YAML capability.
 *
 * Compares gain range, offset range, supported colors, controls,
 * color temperatures and contexts returned by the HAL against the
 * expected values loaded from YAML.
 *
 * This helper can be used for both Get2PointWBCaps() and
 * GetCustom2PointWhiteBalanceCaps().
 *
 * @param expected Expected 2 Point White Balance capability loaded from YAML.
 * @param actualMinGain Minimum gain value returned by HAL.
 * @param actualMinOffset Minimum offset value returned by HAL.
 * @param actualMaxGain Maximum gain value returned by HAL.
 * @param actualMaxOffset Maximum offset value returned by HAL.
 * @param actualColors Supported WB colors returned by HAL.
 * @param actualControls Supported WB controls returned by HAL.
 * @param actualColorTemps Supported color temperatures returned by HAL.
 * @param actualNumColors Number of supported colors.
 * @param actualNumControls Number of supported controls.
 * @param actualNumColorTemps Number of supported color temperatures.
 * @param actualContexts Context capabilities returned by HAL.
 * @param validateColorTemperatures Indicates whether color temperature
 *                                  validation should be performed.
 *
 * @return true if capability validation succeeds, false otherwise.
 */
bool Validate2PointWBProperty(
        const Expected2PointWBCaps_t *expected,
        int actualMinGain,
        int actualMinOffset,
        int actualMaxGain,
        int actualMaxOffset,
        tvWBColor_t *actualColors,
        tvWBControl_t *actualControls,
        tvColorTemp_t *actualColorTemps,
        size_t actualNumColors,
        size_t actualNumControls,
        size_t actualNumColorTemps,
        tvContextCaps_t *actualContexts,
        bool validateColorTemperatures);

/**
 * @brief Validate Multi Point White Balance capabilities against the expected YAML capability.
 *
 * Compares matrix point count, RGB range information and supported
 * contexts returned by the HAL against the expected values loaded
 * from YAML.
 *
 * @param expected Expected Multi Point White Balance capability loaded from YAML.
 * @param actualNumHalPoints Number of HAL matrix points returned by HAL.
 * @param actualRgbMin Minimum RGB value supported by HAL.
 * @param actualRgbMax Maximum RGB value supported by HAL.
 * @param actualNumUiPoints Number of UI matrix points returned by HAL.
 * @param actualUiPositions UI matrix positions returned by HAL.
 * @param actualContexts Context capabilities returned by HAL.
 *
 * @return true if capability validation succeeds, false otherwise.
 */
bool ValidateMultiPointWBProperty(
        const ExpectedMultiPointWBCaps_t *expected,
        int actualNumHalPoints,
        int actualRgbMin,
        int actualRgbMax,
        int actualNumUiPoints,
        double *actualUiPositions,
        tvContextCaps_t *actualContexts);

/**
 * @brief Validate video source capabilities against the expected YAML capability.
 *
 * Compares all supported video sources returned by the HAL against
 * the list of video sources defined in YAML.
 *
 * This capability is global and does not contain context information.
 *
 * @param expected Expected video source capability loaded from YAML.
 * @param actualSources Video sources returned by HAL.
 * @param actualNumSources Number of video sources returned by HAL.
 *
 * @return true if capability validation succeeds, false otherwise.
 */
bool ValidateVideoSourceCaps(
        const ExpectedVideoSourceCaps_t *expected,
        tvVideoSrcType_t *actualSources,
        size_t actualNumSources);

/**
 * @brief Validate video format capabilities against the expected YAML capability.
 *
 * Compares all supported video formats returned by the HAL against
 * the list of video formats defined in YAML.
 *
 * This capability is global and does not contain context information.
 *
 * @param expected Expected video format capability loaded from YAML.
 * @param actualFormats Video formats returned by HAL.
 * @param actualNumFormats Number of video formats returned by HAL.
 *
 * @return true if capability validation succeeds, false otherwise.
 */
bool ValidateVideoFormatCaps(
        const ExpectedVideoFormatCaps_t *expected,
        tvVideoFormatType_t *actualFormats,
        size_t actualNumFormats);
        
/**
 * @brief Validate video resolution capabilities against the expected YAML capability.
 *
 * Compares all supported video resolutions returned by the HAL against
 * the list of video resolutions defined in YAML.
 *
 * This capability is global and does not contain context information.
 *
 * @param expected Expected video resolution capability loaded from YAML.
 * @param actualResolutions Video resolutions returned by HAL.
 * @param actualNumResolutions Number of video resolutions returned by HAL.
 *
 * @return true if capability validation succeeds, false otherwise.
 */
bool ValidateVideoResolutionCaps(
        const ExpectedVideoResolutionCaps_t *expected,
        tvVideoResolution_t *actualResolutions,
        size_t actualNumResolutions);

/**
 * @brief Release all resources allocated by the capability database.
 *
 * Frees dynamically allocated memory used by the capability repository,
 * including:
 *   - Context capability lists
 *   - Enum capability lists
 *   - CMS capability data
 *   - White Balance capability data
 *   - Video source capability data
 *   - Video format capability data
 *   - Video resolution capability data
 *    TO DO - Add for other data 
 *
 * After this API completes, the capability repository is no longer
 * valid and must be reinitialized before use.
 *
 * @param None
 *
 * @return None
 */
void CapabilityDatabase_DeInit(void);

#endif /* __VTS_CAPABILITY_REPOSITORY_H__ */