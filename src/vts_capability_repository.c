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
* @file vts_capability_repository.c
*
*/

#include <string.h>
#include <stdlib.h>
#include <limits.h>

#include <ut.h>
#include <ut_log.h>
#include <ut_kvp_profile.h>

#include "vts_capability_repository.h"

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/*
* Global capability repository.
* Initialized during test suite startup and reused by
* all positive capability validation tests.
*/
CapabilityDatabase_t gCapsDb;

/*********************************************************************
 *                       Enum Lookup Repository
 *
 * Stores name-to-index mappings loaded from YAML _defs section.
 * Used while converting YAML string values into enum/index values
 * expected by HAL capability structures.
 *********************************************************************/

typedef struct
{
    char name[256];
    int value;
} EnumLookup_t;

static EnumLookup_t gPictureModeLookup[64];
static size_t gNumPictureModes;

static EnumLookup_t gVideoFormatLookup[32];
static size_t gNumVideoFormats;

static EnumLookup_t gVideoSourceLookup[32];
static size_t gNumVideoSources;

/*
static EnumLookup_t gColorTempLookup[16];
static size_t gNumColorTemps;

static EnumLookup_t gAspectRatioLookup[16];
static size_t gNumAspectRatios;

static EnumLookup_t gDimmingModeLookup[16];
static size_t gNumDimmingModes;
*/

/*********************************************************************
 *                   Helper Function Prototypes
 *********************************************************************/
static bool LoadEnumDefinitions(void);
static bool LoadEnumDefinitionGroup(const char *yamlPath, EnumLookup_t *lookupTable, size_t lookupTableCapacity, size_t *entryCount);
static int LookupEnumValue(const EnumLookup_t *table, size_t count, const char *name);
static bool LoadRangeCaps(const char *propertyName, ExpectedRangeCaps_t *caps);
/*
static bool LoadEnumCaps();
static bool LoadCMSCaps();
static bool Load2PointWBCaps();
static bool LoadMultiPointWBCaps();
static bool LoadVideoSourceCaps();
static bool LoadVideoFormatCaps();
*/
static bool PopulateExpectedContexts(const char *yamlPath, ExpectedContextCaps_t *contextCaps);
static size_t GetExpandedContextCount(const char *yamlPath, size_t numContextGroups);
static bool ReadFormatArray(const char *yamlPath, tvVideoFormatType_t **formats, size_t *numFormats, size_t groupIndex);
static bool ReadPqModeArray(const char *yamlPath, tvPQModeIndex_t **pqModes, size_t *numPqModes, size_t groupIndex);
static bool ReadSourceArray(const char *yamlPath, tvVideoSrcType_t **sources, size_t *numSources, size_t groupIndex);
static void ExpandContextGroup(ExpectedContextCaps_t *contextCaps, size_t *currentIndex, const tvVideoFormatType_t *formats, size_t numFormats, const tvPQModeIndex_t *pqModes, size_t numPqModes, const tvVideoSrcType_t *sources, size_t numSources);
static bool ValidateContextCaps(const ExpectedContextCaps_t *expected,const tvContextCaps_t *actual);
static void FreeRangeCaps(ExpectedRangeCaps_t *caps);
/*
static void FreeEnumCaps(ExpectedEnumCaps_t *caps);
static void FreeCMSCaps();
static void Free2PointWBCaps();
static void FreeMultiPointWBCaps();
static bool FreeVideoSourceCaps();
static bool FreeVideoFormatCaps();
etc
*/
static void FreeContextCaps(ExpectedContextCaps_t *contextCaps);

/*********************************************************************
 *                   Helper Function Definitions
 *********************************************************************/

static bool LoadEnumDefinitions(void)
{
    if (!LoadEnumDefinitionGroup(
        "_defs/pictureModes",
        gPictureModeLookup,
        ARRAY_SIZE(gPictureModeLookup),
        &gNumPictureModes))
    {
        UT_LOG_ERROR("LoadEnumDefinitionsGroup failed for Picture Modes \n");
        return false;
    }

    if (!LoadEnumDefinitionGroup(
        "_defs/videoFormats",
        gVideoFormatLookup,
        ARRAY_SIZE(gVideoFormatLookup),
        &gNumVideoFormats))
    {
        UT_LOG_ERROR("LoadEnumDefinitionsGroup failed for Video Formats \n");
        return false;
    }

    if (!LoadEnumDefinitionGroup(
        "_defs/videoSources",
        gVideoSourceLookup,
        ARRAY_SIZE(gVideoSourceLookup),
        &gNumVideoSources))
    {
        UT_LOG_ERROR("LoadEnumDefinitionsGroup failed for Video Sources \n");
        return false;
    }

    if ((gNumPictureModes == 0) ||
        (gNumVideoFormats == 0) ||
        (gNumVideoSources == 0))
    {
        UT_LOG_ERROR("One or more required enum definition groups were not loaded successfully");
        return false;
    }

    // TO DO for
    /*
    colorTemperatures
    aspectRatios
    dimmingModes
    cmsColors
    cmsComponents
    wbColors
    wbControls
    */

    return true;
}

static bool LoadEnumDefinitionGroup(
        const char *enumPathYaml,
        EnumLookup_t *lookupTable,
        size_t lookupTableCapacity,
        size_t *entryCount)
{
    size_t i;
    char yamlNode[256];

    if ((enumPathYaml == NULL) ||
        (lookupTable == NULL) ||
        (entryCount == NULL))
    {
        UT_LOG_ERROR("NULL Input Parameters for LoadEnumDefinitionGroup\n");
        return false;
    }

    *entryCount = UT_KVP_PROFILE_GET_LIST_COUNT(enumPathYaml);

    if (*entryCount > lookupTableCapacity)
    {
        UT_LOG_ERROR("Entry count (%zu) exceeds lookup table capacity (%zu) for %s",
                *entryCount,
                lookupTableCapacity,
                enumPathYaml);

        return false;
    }

    for (i = 0; i < *entryCount; i++)
    {
        snprintf(yamlNode,
                 sizeof(yamlNode),
                 "%s/%zu/name",
                 enumPathYaml,
                 i);

        UT_KVP_PROFILE_GET_STRING(yamlNode, lookupTable[i].name);

        snprintf(yamlNode,
                 sizeof(yamlNode),
                 "%s/%zu/index",
                 enumPathYaml,
                 i);

        lookupTable[i].value = UT_KVP_PROFILE_GET_UINT32(yamlNode);
    }

    return true;
}

static int LookupEnumValue(
        const EnumLookup_t *table,
        size_t count,
        const char *name)
{
    for (size_t i = 0; i< count; i++)
    {
        if (strcmp(table[i].name, name) == 0)
        {
            return table[i].value;
        }
    }
    return -1;
}

static bool LoadRangeCaps(
        const char *propertyName,
        ExpectedRangeCaps_t *caps)
{
    char propertyPathYaml[256];

    memset(caps, 0, sizeof(ExpectedRangeCaps_t));

    snprintf(propertyPathYaml,
             sizeof(propertyPathYaml),
             "tvSettings/%s/rangeInfo/from",
             propertyName);

    caps->minValue = UT_KVP_PROFILE_GET_UINT32(propertyPathYaml);

    snprintf(propertyPathYaml,
             sizeof(propertyPathYaml),
             "tvSettings/%s/rangeInfo/to",
             propertyName);

    caps->maxValue = UT_KVP_PROFILE_GET_UINT32(propertyPathYaml);

    snprintf(propertyPathYaml,
             sizeof(propertyPathYaml),
             "tvSettings/%s/context",
             propertyName);

    if (!PopulateExpectedContexts(
            propertyPathYaml,
            &caps->contextCaps))
    {
        UT_LOG_ERROR("PopulateExpectedContexts failed for LoadRangeCaps of %s \n", propertyName);
        return false;
    }

    return true;
}

/*
TO DO : Add definitions for below APIs 
static bool LoadEnumCaps();
static bool LoadCMSCaps();
static bool Load2PointWBCaps();
static bool LoadMultiPointWBCaps();
static bool LoadVideoSourceCaps();
static bool LoadVideoFormatCaps();
*/

static bool PopulateExpectedContexts(
        const char *yamlPath,
        ExpectedContextCaps_t *contextCaps)
{
    size_t groupIndex;
    size_t currentContextIndex = 0;
    bool success = false;

    if ((yamlPath == NULL) ||
        (contextCaps == NULL))
    {
        UT_LOG_ERROR("NULL Input Parameters for PopulateExpectedContexts\n");
        return false;
    }

    memset(contextCaps,
           0,
           sizeof(ExpectedContextCaps_t));

    UT_LOG_DEBUG("PopulateExpectedContexts() yamlPath = [%s]\n", yamlPath);

    // Determine number of context groups and total expanded contexts.
    contextCaps->numContextGroups = UT_KVP_PROFILE_GET_LIST_COUNT(yamlPath);
    contextCaps->numContexts = GetExpandedContextCount(yamlPath, contextCaps->numContextGroups);

    // Allocate storage for expanded context combinations.
    contextCaps->contexts = calloc(contextCaps->numContexts, sizeof(ExpectedConfigContext_t));

    if (contextCaps->contexts == NULL)
    {
        UT_LOG_ERROR("NULL contextCaps->contexts for PopulateExpectedContexts\n");
        return false;
    }

    tvVideoFormatType_t *formats = NULL;
    tvPQModeIndex_t *pqModes = NULL;
    tvVideoSrcType_t *sources = NULL;

    // Read all context groups and expand them.
    for (groupIndex = 0;
         groupIndex < contextCaps->numContextGroups;
         groupIndex++)
    {
        size_t numFormats = 0;
        size_t numPqModes = 0;
        size_t numSources = 0;

        formats = NULL;
        pqModes = NULL;
        sources = NULL;

        // Read Video Formats
        if (!ReadFormatArray(yamlPath, &formats, &numFormats, groupIndex))
        {
            UT_LOG_ERROR("ReadFormatArray failed for context group: %zu \n", groupIndex);
            goto cleanup;
        }

        // Read Picture Modes
        if (!ReadPqModeArray(yamlPath, &pqModes, &numPqModes, groupIndex))
        {
            UT_LOG_ERROR("ReadPqModeArray failed for context group: %zu \n", groupIndex);
            goto cleanup;
        }

        // Read Sources
        if (!ReadSourceArray(yamlPath, &sources, &numSources, groupIndex))
        {
            UT_LOG_ERROR("ReadSourceArray failed for context group: %zu \n", groupIndex);
            goto cleanup;
        }

        // Expand combinations
        ExpandContextGroup(contextCaps, &currentContextIndex, formats, numFormats, pqModes, numPqModes, sources, numSources);

        free(formats);
        formats = NULL;

        free(pqModes);
        pqModes = NULL;

        free(sources);
        sources = NULL;
    }

    success = true;

cleanup:

    free(formats);
    free(pqModes);
    free(sources);

    if (!success)
    {
        free(contextCaps->contexts);
        contextCaps->contexts = NULL;
        contextCaps->numContexts = 0;
        contextCaps->numContextGroups = 0;
    }

    return success;

}

static size_t GetExpandedContextCount(
        const char *yamlPath,
        size_t numContextGroups)
{
    size_t totalContexts = 0;
    char yamlNode[256];

    for (size_t groupIndex = 0;
         groupIndex < numContextGroups;
         groupIndex++)
    {
        size_t numFormats = 0;
        size_t numPqModes = 0;
        size_t numSources = 0;

        snprintf(yamlNode,
                 sizeof(yamlNode),
                 "%s/%zu/format",
                 yamlPath,
                 groupIndex);

        numFormats = UT_KVP_PROFILE_GET_LIST_COUNT(yamlNode);

        snprintf(yamlNode,
                 sizeof(yamlNode),
                 "%s/%zu/pqmode",
                 yamlPath,
                 groupIndex);

        numPqModes = UT_KVP_PROFILE_GET_LIST_COUNT(yamlNode);

        snprintf(yamlNode,
                 sizeof(yamlNode),
                 "%s/%zu/source",
                 yamlPath,
                 groupIndex);

        numSources = UT_KVP_PROFILE_GET_LIST_COUNT(yamlNode);

        totalContexts +=
                (numFormats *
                 numPqModes *
                 numSources);
    }

    return totalContexts;
}

static bool ReadFormatArray(
        const char *yamlPath,
        tvVideoFormatType_t **formats,
        size_t *numFormats,
        size_t groupIndex)
{
    char yamlNode[256];

    snprintf(yamlNode,
                sizeof(yamlNode),
                "%s/%zu/format",
                yamlPath,
                groupIndex);

    UT_LOG_DEBUG("ReadFormatArray() yamlNode = [%s]\n", yamlNode);

    *numFormats = UT_KVP_PROFILE_GET_LIST_COUNT(yamlNode);
    UT_LOG_DEBUG("ReadFormatArray() numFormats = [%zu]\n", *numFormats);

    *formats = calloc(*numFormats, sizeof(tvVideoFormatType_t));
    if (*formats == NULL)
    {
        return false;
    }

    // Read format values

    for (size_t formatIndex = 0;
            formatIndex < *numFormats;
            formatIndex++)
    {
        char formatName[256];
        int formatValue;

        snprintf(yamlNode,
                    sizeof(yamlNode),
                    "%s/%zu/format/%zu",
                    yamlPath,
                    groupIndex,
                    formatIndex);

        UT_LOG_DEBUG("ReadFormatArray() yamlNode = [%s]\n", yamlNode);

        UT_KVP_PROFILE_GET_STRING(yamlNode, formatName);

        formatValue = LookupEnumValue(gVideoFormatLookup, gNumVideoFormats, formatName);
        if (formatValue < 0)
        {
            UT_LOG_ERROR("Unknown format '%s' in YAML path '%s'", formatName, yamlNode);
            free(*formats);
            *formats = NULL;
            *numFormats = 0;
            return false;
        }

        (*formats)[formatIndex] = (tvVideoFormatType_t)formatValue;
    }

    return true;
}

static bool ReadPqModeArray(
        const char *yamlPath, 
        tvPQModeIndex_t **pqModes, 
        size_t *numPqModes,
        size_t groupIndex)
{
    char yamlNode[256];

    snprintf(yamlNode,
                sizeof(yamlNode),
                "%s/%zu/pqmode",
                yamlPath,
                groupIndex);

    UT_LOG_DEBUG("ReadPqModeArray() yamlNode = [%s]\n", yamlNode);

    *numPqModes = UT_KVP_PROFILE_GET_LIST_COUNT(yamlNode);
    UT_LOG_DEBUG("ReadFormatArray() numPqModes = [%zu]\n", *numPqModes);

    *pqModes = calloc(*numPqModes, sizeof(tvPQModeIndex_t));
    if (*pqModes == NULL)
    {
        return false;
    }

    for (size_t pqModeIndex = 0;
            pqModeIndex < *numPqModes;
            pqModeIndex++)
    {
        char pqModeName[256];
        int pqModeValue;

        snprintf(yamlNode,
                    sizeof(yamlNode),
                    "%s/%zu/pqmode/%zu",
                    yamlPath,
                    groupIndex,
                    pqModeIndex);

        UT_LOG_DEBUG("ReadPqModeArray() yamlNode = [%s]\n", yamlNode);

        UT_KVP_PROFILE_GET_STRING(yamlNode, pqModeName);

        pqModeValue = LookupEnumValue(gPictureModeLookup, gNumPictureModes, pqModeName);
        if (pqModeValue < 0)
        {
            UT_LOG_ERROR("Unknown PQ Mode '%s' in YAML path '%s'", pqModeName, yamlNode);
            free(*pqModes);
            *pqModes = NULL;
            *numPqModes = 0;
            return false;
        }

        (*pqModes)[pqModeIndex] = (tvPQModeIndex_t)pqModeValue;
    }

    return true;
}

static bool ReadSourceArray(
        const char *yamlPath, 
        tvVideoSrcType_t **sources, 
        size_t *numSources,
        size_t groupIndex)
{
    char yamlNode[256];

    snprintf(yamlNode,
                sizeof(yamlNode),
                "%s/%zu/source",
                yamlPath,
                groupIndex);

    UT_LOG_DEBUG("ReadSourceArray() yamlNode = [%s]\n", yamlNode);

    *numSources = UT_KVP_PROFILE_GET_LIST_COUNT(yamlNode);
    UT_LOG_DEBUG("ReadFormatArray() numSources = [%zu]\n", *numSources);

    *sources = calloc(*numSources, sizeof(tvVideoSrcType_t));
    if (*sources == NULL)
    {
        return false;
    }

    for (size_t sourceIndex = 0;
            sourceIndex < *numSources;
            sourceIndex++)
    {
        char sourceName[256];
        int sourceValue;

        snprintf(yamlNode,
                    sizeof(yamlNode),
                    "%s/%zu/source/%zu",
                    yamlPath,
                    groupIndex,
                    sourceIndex);

        UT_LOG_DEBUG("ReadSourceArray() yamlNode = [%s]\n", yamlNode);

        UT_KVP_PROFILE_GET_STRING(yamlNode, sourceName);

        sourceValue = LookupEnumValue(gVideoSourceLookup, gNumVideoSources, sourceName);
        if (sourceValue < 0)
        {
            UT_LOG_ERROR("Unknown source '%s' in YAML path '%s'", sourceName, yamlNode);
            free(*sources);
            *sources = NULL;
            *numSources = 0;
            return false;
        }

        (*sources)[sourceIndex] = (tvVideoSrcType_t)sourceValue;
    }

    return true;
}

static void ExpandContextGroup(
        ExpectedContextCaps_t *contextCaps,
        size_t *currentIndex,
        const tvVideoFormatType_t *formats,
        size_t numFormats,
        const tvPQModeIndex_t *pqModes,
        size_t numPqModes,
        const tvVideoSrcType_t *sources,
        size_t numSources)
{
    size_t formatIdx;
    size_t pqModeIdx;
    size_t sourceIdx;

    if ((contextCaps == NULL) ||
        (currentIndex == NULL) ||
        (formats == NULL) ||
        (pqModes == NULL) ||
        (sources == NULL))
    {
        UT_LOG_ERROR("NULL Input Parameters for ExpandContextGroup\n");
        return;
    }

    for (formatIdx = 0;
         formatIdx < numFormats;
         formatIdx++)
    {
        for(pqModeIdx = 0;
             pqModeIdx < numPqModes;
             pqModeIdx++)
        {
            for (sourceIdx = 0;
                 sourceIdx < numSources;
                 sourceIdx++)
            {
                contextCaps->contexts[*currentIndex].format =
                        formats[formatIdx];

                contextCaps->contexts[*currentIndex].pqMode =
                        pqModes[pqModeIdx];

                contextCaps->contexts[*currentIndex].source =
                        sources[sourceIdx];

                (*currentIndex)++;
            }
        }
    }
}

static bool ValidateContextCaps(
        const ExpectedContextCaps_t *expected,
        const tvContextCaps_t *actual)
{
    bool validationPassed = true;

    if ((expected == NULL) || (actual == NULL))
    {
        UT_LOG_ERROR("ValidateContextCaps NULL parameters \n");
        return false;
    }

	if (expected->numContexts != actual->num_contexts)
	{
        UT_LOG_ERROR("Context count mismatch. Expected numContexts: %zu , Actual numContexts: %zu \n",
                expected->numContexts, actual->num_contexts);
		validationPassed = false;
	}

	for (size_t i = 0; i < expected->numContexts; i++)
	{
		bool found = false;
 
		for (size_t j = 0; j < actual->num_contexts; j++)
		{
			if (expected->contexts[i].pqMode == actual->contexts[j].pq_mode &&
				expected->contexts[i].format == actual->contexts[j].videoFormatType &&
				expected->contexts[i].source == actual->contexts[j].videoSrcType)
			{
				found = true;
				break;
			}
		}
 
		if (!found)
		{
            validationPassed = false;
            UT_LOG_ERROR("Missing context:\n Expected[%zu]: PQ=%d Format=%d Source=%d\n",
                i,
                expected->contexts[i].pqMode,
                expected->contexts[i].format,
                expected->contexts[i].source);
		}
	}

    return validationPassed;
}

static void FreeRangeCaps(ExpectedRangeCaps_t *caps)
{
    if (caps == NULL) { return; }

    FreeContextCaps(&caps->contextCaps);
}

/*
static void FreeEnumCaps(ExpectedEnumCaps_t *caps)
{
    if (caps == NULL) { return; }

    free(caps->values);
    caps->values = NULL;
    caps->numValues = 0;
    FreeContextCaps(&caps->contextCaps);
}

TO DO: Add definitions for below
static bool FreeCMSCaps()
static bool Free2PointWBCaps()
static bool FreeMultiPointWBCaps()
static bool FreeVideoSourceCaps()
static bool FreeVideoFormatCaps()
etc
*/

static void FreeContextCaps(ExpectedContextCaps_t *contextCaps)
{
    if (contextCaps == NULL) { return; }

    free(contextCaps->contexts);

    contextCaps->contexts = NULL;
    contextCaps->numContexts = 0;
    contextCaps->numContextGroups = 0;
}

/******************************************************************************
 *                          Public API Definitions
 ******************************************************************************/

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
bool CapabilityDatabase_Init(void)
{
    if(!LoadEnumDefinitions())
    {
        UT_LOG_ERROR("LoadEnumDefinitions failed \n");
        return false;
    }

    memset(&gCapsDb,0,sizeof(gCapsDb));

    // Range-based Capabilities
    if (!LoadRangeCaps(
        "Brightness",
        &gCapsDb.brightness))
    {
        UT_LOG_ERROR("LoadRangeCaps failed for Brightness \n");
        return false;
    }
/*
    LoadRangeCaps(
        "Contrast",
        &gCapsDb.contrast);

    LoadRangeCaps(
        "Sharpness",
        &gCapsDb.sharpness);

    LoadRangeCaps(
        "Backlight",
        &gCapsDb.backlight);

    LoadRangeCaps(
        "Saturation",
        &gCapsDb.saturation);

    LoadRangeCaps(
        "Hue",
        &gCapsDb.hue);

    // Enum-based Capabilities
    LoadEnumCaps(
        "ColorTemperature",
        &gCapsDb.colorTemperature);

    LoadEnumCaps(
        "AspectRatio",
        &gCapsDb.aspectRatio);

    LoadEnumCaps(
        "DimmingMode",
        &gCapsDb.dimmingMode);

    LoadEnumCaps(
        "PictureMode",
        &gCapsDb.pictureMode);

    LoadEnumCaps(
        "BacklightMode",
        &gCapsDb.backlightMode);

    // CMS Capabilities
    LoadCMSCaps(
        &gCapsDb.cms);

    // 2 point WB Capabilities
    Load2PointWBCaps(
        &gCapsDb.wb2Point);

    // Multi point WB Capabilities
    LoadMultiPointWBCaps(
        &gCapsDb.multiPointWb);

    // Video Source Capabilities
    LoadVideoSourceCaps(
        &gCapsDb.videoSource);

    // Video Format Capabilities
    LoadVideoFormatCaps(
        &gCapsDb.videoFormat);
*/
    return true;
}

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
        tvContextCaps_t *actualContexts)
{
    if(expected == NULL)
    {
        UT_LOG_ERROR("ValidateRangeProperty() *expected is NULL \n");
        return false;
    }

    if(actualContexts == NULL)
    {
        UT_LOG_ERROR("ValidateRangeProperty() *actualContexts is NULL \n");
        return false;
    }

    // Validate maximum supported value.
    if (expected->maxValue != actualMax)
    {
        UT_LOG_ERROR("ValidateRangeProperty() Expected MaxValue: %d , Actual MaxValue: %d \n", expected->maxValue, actualMax);
        return false;
    }

    // Validate all supported contexts 
    if (!ValidateContextCaps(&expected->contextCaps, actualContexts))
    {
        UT_LOG_ERROR("ValidateRangeProperty() ValidateContextCaps failed!");
        return false;
    }

    return true;
}

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
        tvContextCaps_t *actualContexts)
{
    // TO DO
    return false;
}

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
        tvContextCaps_t *actualContexts)
{
    // TO DO
    return false;
}

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
        bool validateColorTemperatures)
{
    // TO DO
    return false;
}

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
        tvContextCaps_t *actualContexts)
{
    // TO DO
    return false;
}

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
        size_t actualNumSources)
{
    // TO DO
    return false;
}

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
        size_t actualNumFormats)
{
    // TO DO
    return false;
}

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
        size_t actualNumResolutions)
{
    // TO DO
    return false;
}

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
void CapabilityDatabase_Deinit(void)
{
    FreeRangeCaps(&gCapsDb.brightness);
/*
    FreeRangeCaps(&gCapsDb.contrast);
    FreeRangeCaps(&gCapsDb.sharpness);

    FreeEnumCaps(&gCapsDb.colorTemperature);
    FreeEnumCaps(&gCapsDb.aspectRatio);

    TO DO the free calls for other parameters
*/
}
