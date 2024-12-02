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
 * @defgroup TV_Settings_HALTEST_L1 Settings HAL Tests L1 File
 *  @{
 * @parblock
 *
 * ### L1 test for TV_Settings HAL :
 *
 * This is to ensure that the API meets the operational requirements of the module across all vendors.
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 *
 * Refer to Device Settings HAL Documentation Guide : [tv-settings_halSpec.md](../../docs/pages/tv-settings_halSpec.md)
 *
 * @endparblock
 */

/**
* @file test_l1_tvSettings.c
*
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#include <ut.h>
#include <ut_log.h>
#include <ut_kvp_profile.h>

#include "tvSettings.h"

static int gTestGroup = 1;                                         /* Level 1 Testing -  Stress Test   */
int gTestID = 1;

#define UT_VERSION_MAJOR  1
#define UT_VERSION_MINOR  0
#define MAX_VIDEO_FORMAT         20
#define MAX_DIMMING_MODES        20
#define USER_DATA_SIZE           10
#define MIN_MAXGAIN_RANGE     (1<<10)
#define MAX_MAXGAIN_RANGE     INT_MAX

/* Global flags to support features */
static bool extendedEnumsSupported=false;

/**
 * @brief Validate TvInit() for all positive invocation scenarios
 *
 * This test ensures that the TV Settings module is initialised using TvInit()
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 01@n
 *
 * **Pre-Conditions:** None@n
 *
 * @post Close the module using TvTerm()
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_TvInit (void)
{
    gTestID = 1;                                    /* It must be 1 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_INVALID_STATE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02:  Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings initialization again and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings termination again and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
    UT_LOG("Out %s",__FUNCTION__);

}

/**
 * @brief Validate TvInit() for all negative invocation scenarios
 *
 * This test ensures that tvERROR_INVALID_STATE is returned if called TvInit() again
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 02@n
 *
 * **Pre-Conditions:** None@n
 *
 * @post Close the module using TvTerm()
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call TvInit() -  Re-initialise to get the appropriate error code | void | tvERROR_INVALID_STATE | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_negative_TvInit (void)
{
    gTestID = 2;                                    /* It must be 2 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_INVALID_STATE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
    if (extendedEnumsSupported == true)
    {
        /* Step 02: Calling tvsettings Re-initialization and expecting the API to return tvERROR_INVALID_STATE */
        result = TvInit();
        UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);
    }
    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate TvTerm() for all positive invocation scenarios
 *
 * This test ensures that the TV Settings module is terminated using TvTerm()
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 03@n
 *
 * **Pre-Conditions:** Initialise the module using TvInit()
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_TvTerm (void)
{
    gTestID = 3;                                    /* It must be 3 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate TvTerm() for all neagtive invocation scenarios
 *
 * This test ensures that tvsetting module returns error if TvTerm() is called without TvInit() or TvTerm() again
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 04@n
 *
 * **Pre-Conditions:** Initialise the module using TvInit()
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_TvTerm (void)
{
    gTestID = 4;                                    /* It must be 4 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings termination and expecting the API to return tvERROR_INVALID_STATE */
        result = TvTerm();
        UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);
    }
    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
    if (extendedEnumsSupported == true)
    {
        /* Step 04: Calling tvsettings termination and expecting the API to return tvERROR_INVALID_STATE */
        result = TvTerm();
        UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);
    }
    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate RegisterVideoFormatChangeCB() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 05@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** Callback function should be prepared to handle the video format change event.@n
 * **User Interaction:** Ensure that the test environment allows for simulating format change events, e.g., switching video formats.
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | Call RegisterVideoFormatChangeCB() - Register with the obtained data handle and a valid callback function | tvVideoFormatCallbackData * | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void tvVideoFormatChangeHandler(tvVideoFormatType_t format,void *userData)
{
    UT_LOG("callabck : %s",__FUNCTION__);
}

void test_l1_tvSettings_positive_RegisterVideoFormatChangeCB (void)
{
    gTestID = 5;                                    /* It must be 5 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoFormatCallbackData callbackData = {0};

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings RegisterVideoFormatChangeCB and expecting the API to return success*/
    callbackData.userdata = (char *)malloc(USER_DATA_SIZE);
    if(callbackData.userdata){
        strncpy(callbackData.userdata, "TestData", USER_DATA_SIZE);
        callbackData.cb = tvVideoFormatChangeHandler;
        result = RegisterVideoFormatChangeCB(&callbackData);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
        free(callbackData.userdata);
        callbackData.userdata = NULL;
        callbackData.cb = NULL;
    }
    else {
        UT_LOG_ERROR("Error: Memory Allocation Failed\n");
    }

    /* Step 03: Calling tvsettings initialization and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate RegisterVideoFormatChangeCB() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 06@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call RegisterVideoFormatChangeCB() -  Register the callback function even before TvInit() | tvVideoFormatCallbackData * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call RegisterVideoFormatChangeCB() -  Register using a NULL pointer | RegisterVideoFormatChangeCB(NULL) | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call RegisterVideoFormatChangeCB() -  Register using a callback data with NULL callback function | tvVideoFormatCallbackData(void*, NULL) | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call RegisterVideoFormatChangeCB() -  Register using a callback data with NULL user data handle | tvVideoFormatCallbackData(NULL, tvVideoFormatChangeCB) | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 07 | call RegisterVideoFormatChangeCB() -  Register the callback function even after TvInit() | tvVideoFormatCallbackData * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_RegisterVideoFormatChangeCB (void)
{
    gTestID = 6;                                    /* It must be 6 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoFormatCallbackData callbackData = {0};
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings RegisterVideoFormatChangeCB and expecting the API to return invalid state*/
        callbackData.cb = tvVideoFormatChangeHandler;
        result = RegisterVideoFormatChangeCB(&callbackData);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

     /* Step 03: Calling tvsettings RegisterVideoFormatChangeCB and expecting the API to return invalid param*/
    result = RegisterVideoFormatChangeCB(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings RegisterVideoFormatChangeCB and expecting the API to return  invalid param*/
    callbackData.cb = NULL;
    result = RegisterVideoFormatChangeCB(&callbackData);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings RegisterVideoFormatChangeCB and expecting the API to return  invalid param*/
    callbackData.userdata = NULL;
    callbackData.cb = tvVideoFormatChangeHandler;
    result = RegisterVideoFormatChangeCB(&callbackData);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings initialization and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
    if (extendedEnumsSupported == true)
    {
        /* Step 07: Calling tvsettings RegisterVideoFormatChangeCB and expecting the API to return  invalid state*/
        callbackData.cb = tvVideoFormatChangeHandler;
        result = RegisterVideoFormatChangeCB(&callbackData);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate RegisterVideoContentChangeCB() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 07@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** Callback function should be prepared to handle the video content change event.@n
 * **User Interaction:** Ensure that the test environment allows for simulating FMM mode change events, e.g., switching FMM modes.
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | Call RegisterVideoContentChangeCB() - Register with the obtained data handle and a valid callback function | tvVideoContentCallbackData * | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void tvVideoContentChangeHandler(tvContentType_t content,void *userData)
{
    UT_LOG("callabck : %s",__FUNCTION__);
}

void test_l1_tvSettings_positive_RegisterVideoContentChangeCB (void)
{
    gTestID = 7;                                    /* It must be 7 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoContentCallbackData callbackData = {0};

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings RegisterVideoContentChangeCB and expecting the API to return success*/
    callbackData.userdata = (char *)malloc(USER_DATA_SIZE);
    if(callbackData.userdata){
        strncpy(callbackData.userdata, "TestData",USER_DATA_SIZE);
        callbackData.cb = tvVideoContentChangeHandler;
        result = RegisterVideoContentChangeCB(&callbackData);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
        free(callbackData.userdata);
        callbackData.userdata = NULL;
        callbackData.cb = NULL;
    }
    else {
        UT_LOG_ERROR("Error: Memory Allocation Failed\n");
    }

    /* Step 03: Calling tvsettings initialization and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate RegisterVideoContentChangeCB() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 08@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call RegisterVideoContentChangeCB() -  Register the callback function even before TvInit() | tvVideoContentCallbackData * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call RegisterVideoContentChangeCB() -  Register using a NULL pointer | RegisterVideoContentChangeCB(NULL) | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call RegisterVideoContentChangeCB() -  Register using a callback data with NULL callback function | tvVideoContentCallbackData(void*, NULL) | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call RegisterVideoContentChangeCB() -  Register using a callback data with NULL user data handle | tvVideoContentCallbackData(NULL, tvVideoVideoContentChangeCB) | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 07 | call RegisterVideoContentChangeCB() -  Register the callback function even after TvInit() | tvVideoContentCallbackData * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_RegisterVideoContentChangeCB (void)
{
    gTestID = 8;                                    /* It must be 8 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoContentCallbackData callbackData = {0};

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings RegisterVideoContentChangeCB and expecting the API to return  invalid state*/
        callbackData.cb = tvVideoContentChangeHandler;
        result = RegisterVideoContentChangeCB(&callbackData);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings RegisterVideoContentChangeCB and expecting the API to return  invalid param*/
    result = RegisterVideoContentChangeCB(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings RegisterVideoContentChangeCB and expecting the API to return  invalid param*/
    callbackData.cb = NULL;
    result = RegisterVideoContentChangeCB(&callbackData);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings RegisterVideoContentChangeCB and expecting the API to return  invalid param*/
    callbackData.userdata = NULL;
    callbackData.cb = tvVideoContentChangeHandler;
    result = RegisterVideoContentChangeCB(&callbackData);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings initialization and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 07: Calling tvsettings RegisterVideoContentChangeCB and expecting the API to return  invalid state*/
        callbackData.cb = tvVideoContentChangeHandler;
        result = RegisterVideoContentChangeCB(&callbackData);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate RegisterVideoResolutionChangeCB() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 09@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** Callback function should be prepared to handle the video resolution change event.@n
 * **User Interaction:** Ensure that the test environment allows for simulating resolution change events, e.g., switching video resolution.
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | Call RegisterVideoResolutionChangeCB() - Register with the obtained data handle and a valid callback function | tvVideoResolutionCallbackData * | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void tvVideoResolutionChangeHandler(tvResolutionParam_t resolution,void *userData)
{
    UT_LOG("callback : %s",__FUNCTION__);
}

void test_l1_tvSettings_positive_RegisterVideoResolutionChangeCB (void)
{
    gTestID = 9;                                    /* It must be 9 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoResolutionCallbackData callbackData = {0};

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings RegisterVideoResolutionChangeCB and expecting the API to return success*/
    callbackData.userdata = (char *)malloc(USER_DATA_SIZE);
    if(callbackData.userdata){
        strncpy(callbackData.userdata, "TestData",USER_DATA_SIZE);
        callbackData.cb = tvVideoResolutionChangeHandler;
        result = RegisterVideoResolutionChangeCB(&callbackData);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
        free(callbackData.userdata);
        callbackData.userdata = NULL;
        callbackData.cb = NULL;
    }
    else {
        UT_LOG_ERROR("Error: Memory Allocation Failed\n");
    }

    /* Step 03: Calling tvsettings initialization and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate RegisterVideoResolutionChangeCB() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 10@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call RegisterVideoResolutionChangeCB() -  Register the callback function even before TvInit() | tvVideoResolutionCallbackData * | tvERROR_INVALID_STATE | | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call RegisterVideoResolutionChangeCB() -  Register using a NULL pointer | RegisterVideoResolutionChangeCB(NULL) | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call RegisterVideoResolutionChangeCB() -  Register using a callback data with NULL callback function | tvVideoResolutionCallback(void*, NULL) | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call RegisterVideoResolutionChangeCB() -  Register using a callback data with NULL user data handle | tvVideoResolutionCallbackData(NULL, tvVideoResolutionChangeCB) | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 07 | call RegisterVideoResolutionChangeCB() -  Register the callback function even after TvInit() | tvVideoResolutionCallbackData * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_RegisterVideoResolutionChangeCB (void)
{
    gTestID = 10;                                    /* It must be 10 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoResolutionCallbackData callbackData = {0};

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings RegisterVideoResolutionChangeCB and expecting the API to return  invalid state*/
        callbackData.cb = tvVideoResolutionChangeHandler;
        result = RegisterVideoResolutionChangeCB(&callbackData);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings RegisterVideoResolutionChangeCB and expecting the API to return  invalid param*/
    result = RegisterVideoResolutionChangeCB(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings RegisterVideoResolutionChangeCB and expecting the API to return  invalid param*/
    callbackData.cb = NULL;
    result = RegisterVideoResolutionChangeCB(&callbackData);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings RegisterVideoResolutionChangeCB and expecting the API to return  invalid param*/
    callbackData.userdata = NULL;
    callbackData.cb = tvVideoResolutionChangeHandler;
    result = RegisterVideoResolutionChangeCB(&callbackData);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings initialization and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 07: Calling tvsettings RegisterVideoResolutionChangeCB and expecting the API to return  invalid state*/
        callbackData.cb = tvVideoResolutionChangeHandler;
        result = RegisterVideoResolutionChangeCB(&callbackData);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}


/**
 * @brief Validate RegisterVideoFrameRateChangeCB() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 11@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** Callback function should be prepared to handle the video frame rate change event.@n
 * **User Interaction:** Ensure that the test environment allows for simulating frame rate change events, e.g., switching video frame rate.
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | Call RegisterVideoFrameRateChangeCB() - Register with the obtained data handle and a valid callback function | tvVideoFrameRateCallbackData * | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void tvVideoFrameRateChangeHandler(tvVideoFrameRate_t framerate,void *userData)
{
    UT_LOG("callback : %s",__FUNCTION__);
}

void test_l1_tvSettings_positive_RegisterVideoFrameRateChangeCB (void)
{
    gTestID = 11;                                    /* It must be 11 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoFrameRateCallbackData callbackData = {0};

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings RegisterVideoFrameRateChangeCB and expecting the API to return success*/
    callbackData.userdata = (char *)malloc(USER_DATA_SIZE);
    if(callbackData.userdata){
        strncpy(callbackData.userdata, "TestData",USER_DATA_SIZE);
        callbackData.cb = tvVideoFrameRateChangeHandler;
        result = RegisterVideoFrameRateChangeCB(&callbackData);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
        free(callbackData.userdata);
        callbackData.userdata = NULL;
        callbackData.cb = NULL;
    }
    else {
        UT_LOG_ERROR("Error: Memory Allocation Failed\n");
    }

    /* Step 03: Calling tvsettings initialization and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate RegisterVideoFrameRateChangeCB() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 12@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call RegisterVideoFrameRateChangeCB() -  Register the callback function even before TvInit() | tvVideoFrameRateCallbackData * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call RegisterVideoFrameRateChangeCB() -  Register using a NULL pointer | RegisterVideoFrameRateChangeCB(NULL) | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call RegisterVideoFrameRateChangeCB() -  Register using a callback data with NULL callback function | tvVideoFrameRateCallbackData(void*, NULL) | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call RegisterVideoFrameRateChangeCB() -  Register using a callback data with NULL user data handle | tvVideoFrameRateCallbackData(NULL, tvVideoFrameRateChangeCB) | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 07 | call RegisterVideoFrameRateChangeCB() -  Register the callback function even after TvInit() | tvVideoFrameRateCallbackData * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_RegisterVideoFrameRateChangeCB (void)
{
    gTestID = 12;                                    /* It must be 12 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoFrameRateCallbackData callbackData = {0};

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings RegisterVideoFrameRateChangeCB and expecting the API to return  invalid state*/
        callbackData.cb = tvVideoFrameRateChangeHandler;
        result = RegisterVideoFrameRateChangeCB(&callbackData);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings RegisterVideoFrameRateChangeCB and expecting the API to return  invalid param*/
    result = RegisterVideoFrameRateChangeCB(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings RegisterVideoFrameRateChangeCB and expecting the API to return  invalid param*/
    callbackData.cb = NULL;
    result = RegisterVideoFrameRateChangeCB(&callbackData);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings RegisterVideoFrameRateChangeCB and expecting the API to return  invalid param*/
    callbackData.userdata = NULL;
    callbackData.cb = tvVideoFrameRateChangeHandler;
    result = RegisterVideoFrameRateChangeCB(&callbackData);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings initialization and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 07: Calling tvsettings RegisterVideoFrameRateChangeCB and expecting the API to return  invalid state*/
        callbackData.cb = tvVideoFrameRateChangeHandler;
        result = RegisterVideoFrameRateChangeCB(&callbackData);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVSupportedVideoFormats() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 13@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetTVSupportedVideoFormats() -  Retrieve the current Supported VideoFormats and validate Supported VideoFormats by looping through the VideoFormat section of test specific config file | tvVideoFormatType_t* [], unsigned short * | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVSupportedVideoFormats() -  Retrieve the current Supported VideoFormats with valid argument and validate with above value | tvVideoFormatType_t* [], unsigned short * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetTVSupportedVideoFormats (void)
{
    gTestID = 13;                                    /* It must be 13 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };
    tvVideoFormatType_t *tvVideoFormats[1]={0};
    tvVideoFormatType_t *tvVideoFormatsRetry[1]={0};
    bool IsVideoFormatValid = true;
    unsigned short sizeReceived = 0;
    unsigned short sizeReceivedRetry = 0;
    uint32_t size = 0;
    tvVideoFormatType_t index = VIDEO_FORMAT_NONE;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    tvVideoFormats[0] = (tvVideoFormatType_t *)malloc(MAX_VIDEO_FORMAT * sizeof(tvVideoFormatType_t));
    if (tvVideoFormats[0] != NULL)
    {

        /* Step 02: Calling tvsettings GetTVSupportedVideoFormats and expectinging the API to return success */
        result = GetTVSupportedVideoFormats(tvVideoFormats, &sizeReceived);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
        size = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
        UT_ASSERT_EQUAL(sizeReceived, size);

        for (unsigned short i = 0; i < size; i++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", i);
            index = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            IsVideoFormatValid = false;
            for (unsigned short j = 0; j < sizeReceived; j++)
            {
                if (index == tvVideoFormats[0][j])
                {
                    IsVideoFormatValid = true;
                    break;
                }
            }
            UT_ASSERT_TRUE((IsVideoFormatValid));
        }
        tvVideoFormatsRetry[0] = (tvVideoFormatType_t *)malloc(MAX_VIDEO_FORMAT * sizeof(tvVideoFormatType_t));
        if (tvVideoFormatsRetry[0] != NULL)
        {

            /* Step 03: Calling tvsettings GetTVSupportedVideoFormats and expecting the API to return success */
            result = GetTVSupportedVideoFormats(tvVideoFormatsRetry, &sizeReceivedRetry);
            UT_ASSERT_EQUAL(result, tvERROR_NONE);
            UT_ASSERT_EQUAL(sizeReceived, sizeReceivedRetry);
            for (unsigned short i = 0; i < sizeReceivedRetry; i++)
            {
                IsVideoFormatValid = false;
                for (unsigned short j = 0; j < sizeReceived; j++)
                {
                    if (tvVideoFormatsRetry[0][i] == tvVideoFormats[0][j])
                    {
                        IsVideoFormatValid = true;
                        break;
                    }
                }
                UT_ASSERT_TRUE((IsVideoFormatValid));
            }
        }
        else
        {
            UT_LOG_ERROR("Memory Allocation failed for Retry step ");
        }
    }
    else
    {
        UT_LOG_ERROR("Memory Allocation failed");
    }
    if ( tvVideoFormats[0] ){
        free ( tvVideoFormats[0] );
    }
    if ( tvVideoFormatsRetry[0] ){
        free ( tvVideoFormatsRetry[0] );
    }

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);


    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVSupportedVideoFormats() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 14@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetTVSupportedVideoFormats() -  Retrieve current TV Supported VideoFormats even before TvInit() | tvVideoFormatType_t*[], unsigned short * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVSupportedVideoFormats() -   Retrieve current TV Supported VideoFormats with invalid input | tvVideoFormatType_t*[], NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetTVSupportedVideoFormats() -   Retrieve current TV Supported VideoFormats with invalid input | NULL, unsigned short * | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call GetTVSupportedVideoFormats() -  Retrieve current TV Supported VideoFormats valid arguments | tvVideoFormatType_t*[], unsigned short * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetTVSupportedVideoFormats(void)
{
    gTestID = 14; /* It must be 14 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__, gTestGroup, gTestID);

    tvError_t result = tvERROR_NONE;
    tvVideoFormatType_t *tvVideoFormats[1] = {0};
    unsigned short size = 0;

    tvVideoFormats[0] = (tvVideoFormatType_t *)malloc(MAX_VIDEO_FORMAT * sizeof(tvVideoFormatType_t));
    if (tvVideoFormats[0] != NULL)
    {

        if (extendedEnumsSupported == true)
        {
            /* Step 01: Calling tvsettings GetTVSupportedVideoFormats and expecting the API to return tvERROR_INVALID_STATE */
            result = GetTVSupportedVideoFormats(tvVideoFormats, &size);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
        }

        /* Step 02: Calling tvsettings initialization and expecting the API to return success */
        result = TvInit();
        if (result != tvERROR_NONE)
        {
            if (tvVideoFormats[0])
            {
                free(tvVideoFormats[0]);
            }
        }
        UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

        /* Step 03: Calling tvsettings GetTVSupportedVideoFormats and expecting the API to return tvERROR_INVALID_PARAM */
        result = GetTVSupportedVideoFormats(tvVideoFormats, NULL);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

        /* Step 04: Calling tvsettings GetTVSupportedVideoFormats and expecting the API to return tvERROR_INVALID_PARAM */
        result = GetTVSupportedVideoFormats(NULL, &size);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

        /* Step 05: Calling tvsettings termination and expecting the API to return success */
        result = TvTerm();
        if (result != tvERROR_NONE)
        {
            if (tvVideoFormats[0])
            {
                free(tvVideoFormats[0]);
            }
        }
        UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

        if (extendedEnumsSupported == true)
        {
            /* Step 06: Calling tvsettings GetTVSupportedVideoFormats and expecting the API to return tvERROR_INVALID_STATE */
            result = GetTVSupportedVideoFormats(tvVideoFormats, &size);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
        }
        if (tvVideoFormats[0])
        {
            free(tvVideoFormats[0]);
        }
    }
    else
    {
        UT_LOG_ERROR("Memory Allocation Failed");
    }
    UT_LOG("Out %s", __FUNCTION__);
}

/**
 * @brief Validate GetCurrentVideoFormat() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 15@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetCurrentVideoFormat() -  Retrieve the CurrentVideoFormat and validate CurrentVideoFormat with default value VIDEO_FORMAT_SDR | tvVideoFormatType_t *  | tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentVideoFormat()-  Retrieve the CurrentVideoFormat with valid argument and validate with above value | tvVideoFormatType_t * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetCurrentVideoFormat (void)
{
    gTestID = 15;                                    /* It must be 15 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    tvVideoFormatType_t tvVideoFormatType = VIDEO_FORMAT_MAX;
    tvVideoFormatType_t tvVideoFormatTypeRetry = VIDEO_FORMAT_MAX;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetCurrentVideoFormat and expectinging the API to return success */
    result = GetCurrentVideoFormat(&tvVideoFormatType);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(tvVideoFormatType,VIDEO_FORMAT_SDR)

    /* Step 03: Calling tvsettings GetCurrentVideoFormat and expectinging the API to return success */
    result = GetCurrentVideoFormat(&tvVideoFormatTypeRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(tvVideoFormatTypeRetry, tvVideoFormatType);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetCurrentVideoFormat() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 16@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetCurrentVideoFormat() -  Retrieve current TV CurrentVideoFormat even before TvInit() | tvVideoFormatType_t * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentVideoFormat() -  Retrieve current TV video format with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetCurrentVideoFormat() -  Retrieve current TV CurrentVideoFormat valid arguments | tvVideoFormatType_t * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetCurrentVideoFormat (void)
{
    gTestID = 16;                                    /* It must be 16 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoFormatType_t tvVideoFormatType = VIDEO_FORMAT_MAX;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetCurrentVideoFormat and expecting the API to return tvERROR_INVALID_STATE */
        result = GetCurrentVideoFormat(&tvVideoFormatType);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetCurrentVideoFormat and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetCurrentVideoFormat(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings GetCurrentVideoFormat and expecting the API to return tvERROR_INVALID_STATE */
        result = GetCurrentVideoFormat(&tvVideoFormatType);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);

}

/**
 * @brief Validate GetCurrentVideoResolution() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 17@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetCurrentVideoResolution() -  Retrieve the current VideoResolution and validate VideoResolution with default value tvVideoResolution_NONE | tvResolutionParam_t *  | tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentVideoResolution() -  Retrieve the current VideoResolution with valid argument and validate with above value |tvResolutionParam_t * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetCurrentVideoResolution (void)
{
    gTestID = 17;                                    /* It must be 17 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    tvResolutionParam_t  tvVideoResolution;
    tvResolutionParam_t  tvVideoResolutionRetry;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetCurrentVideoFormat and expectinging the API to return success */
    result = GetCurrentVideoResolution(&tvVideoResolution);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    UT_ASSERT_EQUAL(tvVideoResolution.resolutionValue,tvVideoResolution_NONE);

    /* Step 03: Calling tvsettings GetCurrentVideoFormat and expectinging the API to return success */
    result = GetCurrentVideoResolution(&tvVideoResolutionRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    UT_ASSERT_EQUAL(tvVideoResolutionRetry.resolutionValue, tvVideoResolution.resolutionValue);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);

}

/**
 * @brief Validate GetCurrentVideoResolution() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 18@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetCurrentVideoResolution() -  Retrieve current TV VideoResolution even before TvInit() | tvResolutionParam_t * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentVideoResolution() -  Retrieve the current TV VideoResolution with invalid arguments | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetCurrentVideoResolution() -  Retrieve current TV VideoResolution valid arguments | tvResolutionParam_t * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetCurrentVideoResolution (void)
{
    gTestID = 18;                                    /* It must be 18 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvResolutionParam_t tvResolutionParam;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetCurrentVideoResolution and expecting the API to return tvERROR_INVALID_STATE */
        result = GetCurrentVideoResolution(&tvResolutionParam);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetCurrentVideoResolution and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetCurrentVideoResolution(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings GetCurrentVideoResolution and expecting the API to return tvERROR_INVALID_STATE */
        result = GetCurrentVideoResolution(&tvResolutionParam);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetCurrentVideoFrameRate() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 19@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetCurrentVideoFrameRate() -  Retrieve the current VideoFrameRate and validate VideoFrameRate with default value tvVideoFrameRate_NONE | tvVideoFrameRate_t *  | tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentVideoFrameRate() -  Retrieve the current VideoFrameRate with valid argument and validate with above value | tvVideoFrameRate_t * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetCurrentVideoFrameRate (void)
{
    gTestID = 19;                                    /* It must be 19 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    tvVideoFrameRate_t tvVideoFramerate = tvVideoFrameRate_MAX;
    tvVideoFrameRate_t tvVideoFramerateRetry = tvVideoFrameRate_MAX;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetCurrentVideoFormat and expectinging the API to return success */
    result = GetCurrentVideoFrameRate(&tvVideoFramerate);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(tvVideoFramerate,tvVideoFrameRate_NONE)

    /* Step 03: Calling tvsettings GetCurrentVideoFormat and expectinging the API to return success */
    result = GetCurrentVideoFrameRate(&tvVideoFramerateRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(tvVideoFramerateRetry, tvVideoFramerate);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetCurrentVideoFrameRate() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 20@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetCurrentVideoFrameRate() -  Retrieve current TV VideoFrameRate even before TvInit() | tvVideoFrameRate_t * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentVideoFrameRate() -  Retrieve current TV frame rate with invalid argument | NULL | tvERROR_INVALID_PARAM |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetCurrentVideoFrameRate() -  Retrieve current TV VideoFrameRate valid arguments | tvVideoFrameRate_t * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetCurrentVideoFrameRate (void)
{
    gTestID = 20;                                    /* It must be 20 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoFrameRate_t tvVideoFrameRate = tvVideoFrameRate_MAX;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetCurrentVideoFrameRate and expecting the API to return tvERROR_INVALID_STATE */
        result = GetCurrentVideoFrameRate(&tvVideoFrameRate);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetCurrentVideoFrameRate and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetCurrentVideoFrameRate(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings GetCurrentVideoFrameRate and expecting the API to return tvERROR_INVALID_STATE */
        result = GetCurrentVideoFrameRate(&tvVideoFrameRate);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetCurrentVideoSource() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 21@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetCurrentVideoSource() -  Retrieve the current VideoSource and validate VideoSource by looping through the VideoSource section of test specific config file values | int *  | tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentVideoSource() -  Retrieve the current VideoSource with valid argument and validate with above value |int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetCurrentVideoSource (void)
{
    gTestID = 21;                                    /* It must be 21 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    tvVideoSrcType_t tvVideoSource = 0;
    tvVideoSrcType_t tvVideoSourceRetry = 0;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetCurrentVideoSource and expectinging the API to return success */
    result = GetCurrentVideoSource(&tvVideoSource);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(tvVideoSource,VIDEO_SOURCE_IP)

    /* Step 03: Calling tvsettings GetCurrentVideoSource and expectinging the API to return success */
    result = GetCurrentVideoSource(&tvVideoSourceRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    UT_ASSERT_EQUAL(tvVideoSourceRetry, tvVideoSource);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetCurrentVideoSource() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 22@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetCurrentVideoSource() -  Retrieve current VideoSource even before TvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentVideoSource() -  Retrieve the current VideoSource with invalid arguments | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetCurrentVideoSource() -  Retrieve current VideoSource valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetCurrentVideoSource (void)
{
    gTestID = 22;                                    /* It must be 22 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoSrcType_t tvVideoSource = 0;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetCurrentVideoSource and expecting the API to return tvERROR_INVALID_STATE */
        result = GetCurrentVideoSource(&tvVideoSource);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetCurrentVideoSource and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetCurrentVideoSource(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings GetCurrentVideoSource and expecting the API to return tvERROR_INVALID_STATE */
        result = GetCurrentVideoSource(&tvVideoSource);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVSupportedVideoSources() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 23@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetTVSupportedVideoSources() -  Retrieve the current TV Supported VideoSources and validate TV Supported VideoSources by looping through the VideoSource section of test specific config file | tvVideoSrcType_t *[], unsigned short * | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVSupportedVideoSources() -  Retrieve the current TV Supported VideoSources with valid argument and validate with above value | tvVideoSrcType_t *[], unsigned short * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetTVSupportedVideoSources (void)
{
    gTestID = 23;                                    /* It must be 23 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    tvVideoSrcType_t *tvVideoSources[1]={0};
    tvVideoSrcType_t *tvVideoSourcesRetry[1]={0};
    bool IsVideoSourceValid = true;
    unsigned short sizeReceived = 0;
    unsigned short sizeReceivedRetry = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };
    tvVideoSrcType_t source = VIDEO_SOURCE_ANALOGUE;
    uint32_t count = 0;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    tvVideoSources[0] = (tvVideoSrcType_t *)malloc(MAX_VIDEO_FORMAT * sizeof(tvVideoSrcType_t));
    if (tvVideoSources[0] != NULL)
    {

        /* Step 02: Calling tvsettings GetTVSupportedVideoSources and expectinging the API to return success */
        count = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
        result = GetTVSupportedVideoSources(tvVideoSources, &sizeReceived);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
        UT_ASSERT_EQUAL(sizeReceived, count);

        for (unsigned int i = 0; i < sizeReceived; i++)
        {
            IsVideoSourceValid = false;
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", i);
            source = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            for (unsigned short j = 0; j < count; j++)
            {
                if (source == tvVideoSources[0][j])
                {
                    IsVideoSourceValid = true;
                    break;
                }
            }
            UT_ASSERT_TRUE((IsVideoSourceValid));
        }
        tvVideoSourcesRetry[0] = (tvVideoSrcType_t *)malloc(MAX_VIDEO_FORMAT * sizeof(tvVideoSrcType_t));
        if (tvVideoSourcesRetry[0] != NULL)
        {

            /* Step 03: Calling tvsettings GetTVSupportedVideoSources and expectinging the API to return success */
            result = GetTVSupportedVideoSources(tvVideoSourcesRetry, &sizeReceivedRetry);
            UT_ASSERT_EQUAL(result, tvERROR_NONE);

            for (unsigned short i = 0; i < sizeReceivedRetry; i++)
            {
                IsVideoSourceValid = false;
                for (unsigned short j = 0; j < sizeReceived; j++)
                {
                    if (tvVideoSourcesRetry[0][i] == tvVideoSources[0][j])
                    {
                        IsVideoSourceValid = true;
                        break;
                    }
                }
                UT_ASSERT_TRUE((IsVideoSourceValid));
            }
        }
        else
        {
            UT_LOG_ERROR("Memory Allocation Failed for the Retry Step");
        }
    }
    else
    {
        UT_LOG_ERROR("Memory Allocation Failed");
    }
    if ( tvVideoSources[0] ){
        free ( tvVideoSources[0] );
    }
    if ( tvVideoSourcesRetry[0] ){
        free ( tvVideoSourcesRetry[0] );
    }

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVSupportedVideoSources() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 24@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetTVSupportedVideoSources() -  Retrieve current TV Supported VideoSources even before TvInit() | tvVideoSrcType_t *[], unsigned short * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVSupportedVideoSources() -  Retrieve supported TV VideoSources with invalid argument | NULL, unsigned short * | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetTVSupportedVideoSources() -  Retrieve supported TV VideoSources with invalid argument |  tvVideoSrcType_t *[], NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call GetTVSupportedVideoSources() -  Retrieve current TV Supported VideoSources valid arguments | tvVideoSrcType_t *[], unsigned short * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetTVSupportedVideoSources (void)
{
    gTestID = 24;                                    /* It must be 24 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoSrcType_t *tvVideoSrcType[1] = {0};
    unsigned short numberOfSources = 0;

    tvVideoSrcType[0] = (tvVideoSrcType_t *)malloc(MAX_VIDEO_FORMAT*sizeof(tvVideoSrcType_t));
    if (tvVideoSrcType[0] != NULL)
    {

        if (extendedEnumsSupported == true)
        {
            /* Step 01: Calling tvsettings GetTVSupportedVideoSources and expecting the API to return tvERROR_INVALID_STATE */
            result = GetTVSupportedVideoSources(tvVideoSrcType, &numberOfSources);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
        }

        /* Step 02: Calling tvsettings initialization and expecting the API to return success */
        result = TvInit();
        if (result != tvERROR_NONE)
        {
            if (tvVideoSrcType[0])
            {
                free(tvVideoSrcType[0]);
            }
        }
        UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

        /* Step 03: Calling tvsettings GetTVSupportedVideoSources and expecting the API to return tvERROR_INVALID_PARAM */
        result = GetTVSupportedVideoSources(NULL, &numberOfSources);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

        /* Step 04: Calling tvsettings GetTVSupportedVideoSources and expecting the API to return tvERROR_INVALID_PARAM */
        result = GetTVSupportedVideoSources(tvVideoSrcType, NULL);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

        /* Step 05: Calling tvsettings termination and expecting the API to return success */
        result = TvTerm();
        if (result != tvERROR_NONE)
        {
            if (tvVideoSrcType[0])
            {
                free(tvVideoSrcType[0]);
            }
        }
        UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

        if (extendedEnumsSupported == true)
        {
            /* Step 06: Calling tvsettings GetTVSupportedVideoSources and expecting the API to return tvERROR_INVALID_STATE */
            result = GetTVSupportedVideoSources(tvVideoSrcType, &numberOfSources);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
        }

        if (tvVideoSrcType[0])
        {
            free(tvVideoSrcType[0]);
        }
    }
    else
    {
        UT_LOG_ERROR("Memory Allocation Failed");
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetBacklight() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 25@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetBacklight() -  Retrieve the current Backlight and validate with valid range (0 - 100) |int *| tvERROR_NONE | Should Pass |
 * | 03 | call GetBacklight() -  Retrieve the current Backlight with valid argument and validate with above value | int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetBacklight (void)
{
    gTestID = 25;                                    /* It must be 25 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int backlight = -1;
    int backlightRetry = -1;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetBacklight and expecting the API to return success */
    result = GetBacklight(&backlight);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_TRUE( (backlight >= 0 && backlight <= 100 ));

    /* Step 03: Calling tvsettings GetBacklight again and expecting the API to return success */
    result = GetBacklight(&backlightRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(backlight, backlightRetry);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);

}

/**
 * @brief Validate GetBacklight() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 26@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetBacklight() -   Retrieve current TV backlight even before TvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetBacklight() -  Retrieve current TV backlight with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetBacklight() -  Retrieve current TV backlight valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetBacklight (void)
{
    gTestID = 26;                                    /* It must be 26 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int backlight = -1;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetTVBcklight and expecting the API to return tvERROR_INVALID_STATE */
        result = GetBacklight(&backlight);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetBacklight with invalid input and expecting the API to return tvERROR_INVALID_PARAM*/
    result = GetBacklight(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings GetBacklight and expecting the API to return tvERROR_INVALID_STATE */
        result = GetBacklight(&backlight);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetBacklight() for all positive invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 27@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | Call SetBacklight() - Set the backlight with valid value | 0 | tvERROR_NONE | Should Pass |
 * | 03 | call SetBacklight() -  Reset the backlight with another valid value | 50 | tvERROR_NONE | Should Pass |
 * | 04 | call SetBacklight() -  Reset the backlight with another valid value | 100 | tvERROR_NONE | Should Pass |
 * | 05 | call SetBacklight() -  Reset the backlight with the same value as in previous variation | 100 | tvERROR_NONE | Should Pass |
 * | 06 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetBacklight (void)
{
    gTestID = 27;                                    /* It must be 27 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SetBacklight with Backlight value 0 and expecting the API to return success */
    result = SetBacklight(0);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetBacklight with Backlight value 50 and expecting the API to return success */
    result = SetBacklight(50);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings SetBacklight with Backlight value 100 and expecting the API to return success */
    result = SetBacklight(100);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 05: Calling tvsettings SetBacklight with Backlight value 100 and expecting the API to return success */
    result = SetBacklight(100);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 06: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetBacklight() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 28@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call SetBacklight() - Set the TV backlight even before TvInit() | 30 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetBacklight() -   Set the TV backlight with less than the lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetBacklight() -   Set the TV backlight with max range | 101 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetBacklight() -   Set the TV backlight with max range | 200 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 07 | call SetBacklight() -  Set the TV backlight with valid input after TvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetBacklight (void)
{
    gTestID = 28;                                    /* It must be 28 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetBacklight and expecting the API to return tvERROR_INVALID_STATE */
        result = SetBacklight(30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetBacklight with Backlight value -1 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetBacklight(-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetBacklight with Backlight value 101 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetBacklight(101);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SetBacklight with Backlight value 200 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetBacklight(200);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 07: Calling tvsettings the SetBacklight and expecting the API to return tvERROR_INVALID_STATE */
        result = SetBacklight(50);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveBacklight() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 29@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SaveBacklight() -  Save the current Color Backlight value by looping through all the values of sourceId, pqmode, videoFormatType from the VideoSource, PictureMode, VideoFormat section of test specific config file  |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,int | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveBacklight (void)
{
    gTestID = 29;                                    /* It must be 29 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    /* Step 02: Calling tvsettings SaveBacklight for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
    for (unsigned int i = 0; i < videoSrcCount; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", i);
        videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            for (unsigned int k = 0; k < videoFmtCount; k++)
            {
                snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", k);
                videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
                result = SaveBacklight(videoSource,pqValue, \
                                            videoFormat,50);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);
            }
        }
    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveBacklight() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 30@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SaveBacklight() -  Retrieve current TV Backlight even before TvInit() |  tvVideoSrcType_t, int , tvVideoFormatType_t ,int | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SaveBacklight() -  "pq_mode,videoFormatType,value"=valid, "videoSrcType"=invalid max range| VIDEO_SOURCE_MAX, int ,tvVideoFormatType_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SaveBacklight() -  "pq_mode,videoFormatType,value"=valid, "videoSrcType"=invalid lower range| -2 , int ,tvVideoFormatType_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SaveBacklight() -  "videoSrcType,videoFormatType,value"=valid, "pq_mode"=invalid lower range | tvVideoSrcType_t, -1 ,tvVideoFormatType_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SaveBacklight() -  "videoSrcType,videoFormatType,value"=valid, "pq_mode"=invalid max range| tv_sourcetvVideoSrcType_t_input_t, PQ_MODE_MAX ,tvVideoFormatType_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SaveBacklight() -  "videoSrcType,pq_mode,value"=valid, "videoFormatType"=invalid max range| tvVideoSrcType_t, int ,VIDEO_FORMAT_MAX ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SaveBacklight() -  "videoSrcType,pq_mode,value"=valid, "videoFormatType"=invalid lower range| tvVideoSrcType_t, int , -1 ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SaveBacklight() -  "videoSrcType,pq_mode,videoFormatType"=valid, "value"=invalid lower range | tvVideoSrcType_t, int , tvVideoFormatType_t ,-1| tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SaveBacklight() -  "videoSrcType,pq_mode,videoFormatType"=valid, "value"=invalid max range | tvVideoSrcType_t, int , tvVideoFormatType_t ,101| tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SaveBacklight() -  "pq_mode,videoFormatType,value"= valid, "videoSrcType"=valid(videoSrcType not supported by the platform by looping through the VideoSource section of test specific config file)| tvVideoSrcType_t, int , tvVideoFormatType_t , int| tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call SaveBacklight() -  "videoSrcType,videoFormatType,value"= valid, "pq_mode"=valid( pq_mode not supported by the platform by looping through the PictureMode section of test specific config file)| tvVideoSrcType_t, int , tvVideoFormatType_t , int| tvERROR_INVALID_PARAM | Should Pass |
 * | 13 | call SaveBacklight() -  "videoSrcType,pq_mode,value"= valid, "videoFormatType"=valid(videoFormatType not supported by the platform by looping through the VideoFormat section of test specific config file)| tvVideoSrcType_t, int , tvVideoFormatType_t , int| tvERROR_INVALID_PARAM | Should Pass |
 * | 14 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 15 | call SaveBacklight() -  Retrieve current TV Backlight valid arguments | tvVideoSrcType_t, int , tvVideoFormatType_t ,int | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveBacklight (void)
{
    gTestID = 30;                                    /* It must be 30 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE ;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    uint32_t count = 0;
    bool SupportAvailable = true;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveBacklight(videoSource, pqValue,
                               videoFormat, 50);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveBacklight(VIDEO_SOURCE_MAX,pqValue,videoFormat,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveBacklight((tvVideoSrcType_t)-2,pqValue,videoFormat,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveBacklight(videoSource,-1,videoFormat,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveBacklight(videoSource,PQ_MODE_MAX,videoFormat,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveBacklight(videoSource,pqValue,VIDEO_FORMAT_MAX,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveBacklight(videoSource,pqValue,(tvVideoFormatType_t)-1,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveBacklight(videoSource,pqValue,videoFormat,-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);


    /* Step 10: Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveBacklight(videoSource,pqValue,videoFormat,101);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 11: Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_PARAM */
    count = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    for(int i =VIDEO_SOURCE_ALL ; i < VIDEO_SOURCE_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < count; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", j);
            videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoSource == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveBacklight((tvVideoSrcType_t)i,pqValue,videoFormat,50);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 12: Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_PARAM */
    count = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    for(int i =0 ; i < PQ_MODE_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < count; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(pqValue == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            /* TODO: Review this and similar tests, all functionality must be called to the backend API,
            it's the API that should decide if it's supported or not, not the test */
            result = SaveBacklight(videoSource,i,videoFormat,50);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 13: Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_PARAM */
    count = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < count; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", j);
            videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoFormat == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveBacklight(videoSource,pqValue,(tvVideoFormatType_t)i,50);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 14: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 15: Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveBacklight(videoSource, pqValue, videoFormat, 50);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetBacklightFade() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 31@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetBacklightFade() -  Set the BacklightFade with valid input range (0 - 100) and duration range (0 - 10000 ms) | int, int, int | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetBacklightFade (void)
{
    gTestID = 31;                                    /* It must be 31 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SetBacklightFade with inputs 0, 0, 0 and expecting the API to return success */
    result = SetBacklightFade(0,0,0);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    result = SetBacklightFade(50,50,5000);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    result = SetBacklightFade(100,100,10000);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);

}

/**
 * @brief Validate SetBacklightFade() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 32@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetBacklightFade() - Set the TV  Backlight Fade value even before TvInit() | int, int, int | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetBacklightFade() -   Set the TV  Backlight Fade value with invalid input | -1, 1, 1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetBacklightFade() -   Set the TV  Backlight Fade value with invalid input | 1, -1, 1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetBacklightFade() -   Set the TV  Backlight Fade value with invalid input | 1, 1, -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetBacklightFade() -   Set the TV  Backlight Fade value with invalid input | 101, 10, 100000 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SetBacklightFade() -   Set the TV  Backlight Fade value with invalid input | 10, 101, 100000 | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SetBacklightFade() -   Set the TV  Backlight Fade value with invalid input | 10, 10, 100001 | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 10 | call SetBacklightFade() -  Set the TV  Backlight Fade value with valid input after TvTerm() | 10, 10, 10 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetBacklightFade (void)
{
    gTestID = 32;                                    /* It must be 32 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetBacklightFade and expecting the API to return tvERROR_INVALID_STATE */
        result = SetBacklightFade(30, 30, 30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetBacklightFade with inputs -1, 1, 1 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetBacklightFade(-1, 1, 1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetBacklightFade with inputs 1, -1, 1 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetBacklightFade(1, -1, 1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SetBacklightFade with inputs 1, 1, -1 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetBacklightFade(1, 1, -1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SetBacklightFade with inputs 101, 10, 100000 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetBacklightFade(101, 10, 100000);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SetBacklightFade with inputs 10, 101, 100000 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetBacklightFade(10, 101, 100000);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings SetBacklightFade with inputs 10, 10, 100001 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetBacklightFade(10, 10, 100001);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 10: Calling tvsettings the SetBacklightFade and expecting the API to return tvERROR_INVALID_STATE */
        result = SetBacklightFade(10, 10, 10);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }
}

/**
 * @brief Validate GetCurrentBacklightFade() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 33@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetCurrentBacklightFade() -  Retrieve the current Backlight Fade and validate with range (0 - 100) and duration range (0 - 10000 ms)|int *, int*, int*| tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentBacklightFade() -  Retrieve the current Backlight Fade with valid argument and validate with above value | int *, int*, int* | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetCurrentBacklightFade (void)
{
    gTestID = 33;                                    /* It must be 25 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int from = 0, to = 0 ,current = 0;
    int fromRetry = 0, toRetry = 0, currentRetry = 0;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetBacklight and expecting the API to return success */
    result = GetCurrentBacklightFade(&from, &to, &current);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_TRUE((from >= 0 && from <= 100));
    UT_ASSERT_TRUE((to >= 0 && to <= 100));
    UT_ASSERT_TRUE((current >= 0 && current <= 10000));

    /* Step 03: Calling tvsettings GetBacklight again and expecting the API to return success */
    result = GetCurrentBacklightFade(&fromRetry , &toRetry ,&currentRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    UT_ASSERT_EQUAL(from, fromRetry);
    UT_ASSERT_EQUAL(to, toRetry);
    UT_ASSERT_EQUAL(current, currentRetry);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetCurrentBacklightFade() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 34@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetCurrentBacklightFade() -   Retrieve current Backlight Fade value even before TvInit() | int *, int*, int* | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentBacklightFade() -  Retrieve current Backlight Fade with invalid input | NULL, int*, int* | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetCurrentBacklightFade() -  Retrieve current Backlight Fade with invalid input | int*, NULL, int* | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetCurrentBacklightFade() -  Retrieve current Backlight Fade with invalid input | int*, int*, NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 07 | call GetCurrentBacklightFade() -  Retrieve current Backlight Fade with valid arguments | int *, int*, int* | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetCurrentBacklightFade (void)
{
    gTestID = 34;                                    /* It must be 26 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int from = 0, to = 0, current = 0;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetCurrentBacklightFade and expecting the API to return tvERROR_INVALID_STATE */
        result = GetCurrentBacklightFade(&from, &to, &current);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetCurrentBacklightFade and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetCurrentBacklightFade(NULL, &to, &current);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings GetCurrentBacklightFade and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetCurrentBacklightFade(&from, NULL, &current);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings GetCurrentBacklightFade and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetCurrentBacklightFade(&from, &to, NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 07: Calling tvsettings GetBacklight and expecting the API to return tvERROR_INVALID_STATE */
        result = GetCurrentBacklightFade(&from, &to, &current);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetSupportedBacklightModes() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 35@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetSupportedBacklightModes() -  Retrieve the current SupportedBacklightModes and validate SupportedBacklightModes by looping through the BacklightControl section of test specific config file values | int *  | tvERROR_NONE | Should Pass |
 * | 03 | call GetSupportedBacklightModes() -  Retrieve the current SupportedBacklightModes with valid argument and validate with above value | int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetSupportedBacklightModes (void)
{
    gTestID = 35;                                    /* It must be 35 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    int tvBacklightModes =0, tvBacklightModes_bk =0, tvBacklightModesRetry=0;
    uint32_t count = 0;
    int modeValue = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetSupportedBacklightModes and expectinging the API to return success */
    result = GetSupportedBacklightModes(&tvBacklightModes);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    tvBacklightModes_bk = tvBacklightModes;
    count = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/BacklightControl/index");
    for (unsigned int i = 0; i < count; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/BacklightControl/index/%d", i);
        modeValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
        if(modeValue & tvBacklightModes_bk)
        {
            tvBacklightModes_bk &= (~modeValue);
        }
    }

    UT_ASSERT_FALSE((tvBacklightModes_bk));

    /* Step 03: Calling tvsettings GetSupportedBacklightModes and expectinging the API to return success */
    result = GetSupportedBacklightModes(&tvBacklightModesRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    UT_ASSERT_EQUAL(tvBacklightModesRetry, tvBacklightModes);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetSupportedBacklightModes() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 36@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetSupportedBacklightModes() -  Retrieve current TV SupportedBacklightModes even before TvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetSupportedBacklightModes() -  Retrieve supported Backlight modes with invalid argument | NULL | tvERROR_INVALID_PARAM |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetSupportedBacklightModes() -  Retrieve current TV SupportedBacklightModes valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetSupportedBacklightModes (void)
{
    gTestID = 36;                                    /* It must be 36 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int backlightModes = 0;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetSupportedBacklightModes and expecting the API to return tvERROR_INVALID_STATE */
        result = GetSupportedBacklightModes(&backlightModes);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetSupportedBacklightModes and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetSupportedBacklightModes(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings GetSupportedBacklightModes and expecting the API to return tvERROR_INVALID_STATE */
        result = GetSupportedBacklightModes(&backlightModes);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetCurrentBacklightMode() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 37@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetCurrentBacklightMode() -  Retrieve the CurrentBacklightMode and validate it by looping through the BacklightControl section of test specific config file values | tvBacklightMode_t *  | tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentBacklightMode() -  Retrieve the CurrentBacklightMode with valid argument and validate with above value | tvBacklightMode_t * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetCurrentBacklightMode (void)
{
    gTestID = 37;                                    /* It must be 37 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    tvBacklightMode_t tvBacklightMode = tvBacklightMode_MAX;
    tvBacklightMode_t tvBacklightModeRetry = tvBacklightMode_MAX;
    bool IsBacklightModeValid = false;
    uint32_t count = 0;
    tvBacklightMode_t modeValue = tvBacklightMode_NONE;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetCurrentBacklightMode and expectinging the API to return success */
    result = GetCurrentBacklightMode(&tvBacklightMode);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    count = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/BacklightControl/index");
    for (unsigned int i = 0; i < count; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/BacklightControl/index/%d", i);
        modeValue = (tvBacklightMode_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
        if (modeValue == tvBacklightMode)
        {
            IsBacklightModeValid = true;
            break;
        }
    }

    UT_ASSERT_TRUE((IsBacklightModeValid));

    /* Step 03: Calling tvsettings GetCurrentBacklightMode and expectinging the API to return success */
    result = GetCurrentBacklightMode(&tvBacklightModeRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(tvBacklightModeRetry, tvBacklightMode);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
}

/**
 * @brief Validate GetCurrentBacklightMode() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 38@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetCurrentBacklightMode() -  Retrieve current TV CurrentBacklightMode even before TvInit() | tvBacklightMode_t * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentBacklightMode() -  Retrieve TV current Backlight modes with invalid argument | NULL | tvERROR_INVALID_PARAM |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetCurrentBacklightMode() -  Retrieve current TV CurrentBacklightMode valid arguments | tvBacklightMode_t * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetCurrentBacklightMode (void)
{
    gTestID = 38;                                    /* It must be 38 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvBacklightMode_t tvBacklightMode = tvBacklightMode_MAX;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetCurrentBacklightMode and expecting the API to return tvERROR_INVALID_STATE */
        result = GetCurrentBacklightMode(&tvBacklightMode);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetSupportedBacklightModes and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetCurrentBacklightMode(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings GetCurrentBacklightMode and expecting the API to return tvERROR_INVALID_STATE */
        result = GetCurrentBacklightMode(&tvBacklightMode);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetCurrentBacklightMode() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 39@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetCurrentBacklightMode() -  Set the TV Current Backlight mode by looping through all the values of backlight modes from the BacklightControl section of test specific config file | tvBacklightMode_t  | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetCurrentBacklightMode (void)
{
    gTestID = 39;                                    /* It must be 39 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    uint32_t count = 0;
    tvBacklightMode_t modeValue = tvBacklightMode_NONE;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SetCurrentBacklightMode and expecting the API to return success */
    count = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/BacklightControl/index");
    for (unsigned int i = 0; i < (count); i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/BacklightControl/index/%d", i);
        modeValue = (tvBacklightMode_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        result = SetCurrentBacklightMode(modeValue);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetCurrentBacklightMode() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 40@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetCurrentBacklightMode() - Set the TV CurrentBacklightMode even before TvInit() | tvBacklightMode_AMBIENT | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetCurrentBacklightMode() -   Set the TV CurrentBacklightMode with max range | tvBacklightMode_MAX | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetCurrentBacklightMode() -   Set the TV CurrentBacklightMode with less than the lower range  | -1 (tvBacklightMode_t)| tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetCurrentBacklightMode() -   Set the TV CurrentBacklightMode with invalid parameter of all possible combinations  | (tvBacklightMode_t| tvBacklightMode_t) | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetCurrentBacklightMode() -   Set the TV CurrentBacklightMode with valid value but not supported by the platform by looping through the BacklightControl section test specific config file  | tvBacklightMode_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 08 | call SetCurrentBacklightMode() -  Set the TV CurrentBacklightMode with valid input after TvTerm() | tvBacklightMode_MANUAL | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetCurrentBacklightMode (void)
{
    gTestID = 40;                                    /* It must be 40*/
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    int numberofBacklightModes = 0;
    bool SupportAvailable = true;
    tvBacklightMode_t modeValue = tvBacklightMode_NONE;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    modeValue = (tvBacklightMode_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/BacklightControl/index/0");

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetCurrentBacklightMode and expecting the API to return tvERROR_INVALID_STATE */
        result = SetCurrentBacklightMode(modeValue);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetCurrentBacklightMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetCurrentBacklightMode(tvBacklightMode_MAX);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetCurrentBacklightMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetCurrentBacklightMode((tvBacklightMode_t)-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SetCurrentBacklightMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetCurrentBacklightMode((tvBacklightMode_MAX | tvBacklightMode_AMBIENT));
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SetCurrentBacklightMode and expecting the API to return tvERROR_INVALID_PARAM */
    numberofBacklightModes = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/BacklightControl/index");
    for(int i =tvBacklightMode_NONE ; i < tvBacklightMode_MAX; i++)
    {
        SupportAvailable = false;
        for(int j = 0  ; j < numberofBacklightModes ; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/BacklightControl/index/%d", j);
            modeValue = (tvBacklightMode_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(modeValue == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SetCurrentBacklightMode((tvBacklightMode_t)i);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 07: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 08: Calling tvsettings the SetCurrentBacklightMode and expecting the API to return tvERROR_INVALID_STATE */
        modeValue = (tvBacklightMode_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/BacklightControl/index/0");
        result = SetCurrentBacklightMode(modeValue);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVSupportedDimmingModes() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 41@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetTVSupportedDimmingModes() -  Retrieve the current TV Supported DimmingModes and validate TV Supported DimmingModes by looping through the DimmingMode section of test specific config file | tvDimmingMode_t*[], unsigned short * | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVSupportedDimmingModes() -  Retrieve the current TTV Supported DimmingModes with valid argument and validate with above value | tvDimmingMode_t*[], unsigned short * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetTVSupportedDimmingModes (void)
{
    gTestID = 41;                                  /* It must be 41 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    tvDimmingMode_t *tvDimmingModes[1]={0};
    tvDimmingMode_t *tvDimmingModesRetry[1]={0};
    bool IsDimmingModeValid = true;
    unsigned short sizeReceived = 0;
    unsigned short sizeReceivedRetry = 0;
    uint32_t count = 0;
    tvDimmingMode_t modeValue = tvDimmingMode_Fixed;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    tvDimmingModes[0] = (tvDimmingMode_t *)malloc(MAX_VIDEO_FORMAT * sizeof(tvDimmingMode_t));
    if (tvDimmingModes[0] != NULL)
    {

        /* Step 02: Calling tvsettings GetTVSupportedDimmingModes and expectinging the API to return success */
        result = GetTVSupportedDimmingModes(tvDimmingModes, &sizeReceived);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
        count = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/DimmingMode/index");
        UT_ASSERT_EQUAL(sizeReceived, (unsigned short)count);

        for (unsigned int i = 0; i < count; i++)
        {
            IsDimmingModeValid = false;
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/DimmingMode/index/%d", i);
            modeValue = (tvDimmingMode_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            for (unsigned short j = 0; j < sizeReceived; j++)
            {
                if (modeValue == tvDimmingModes[0][j])
                {
                    IsDimmingModeValid = true;
                    break;
                }
            }
            UT_ASSERT_TRUE((IsDimmingModeValid));
        }
        tvDimmingModesRetry[0] = (tvDimmingMode_t *)malloc(MAX_VIDEO_FORMAT * sizeof(tvDimmingMode_t));
        if (tvDimmingModesRetry[0] != NULL)
        {

            /* Step 03: Calling tvsettings GetTVSupportedDimmingModes and expecting the API to return success */
            result = GetTVSupportedDimmingModes(tvDimmingModesRetry, &sizeReceivedRetry);
            UT_ASSERT_EQUAL(result, tvERROR_NONE);
            UT_ASSERT_EQUAL(sizeReceived, sizeReceivedRetry);

            for (unsigned short i = 0; i < sizeReceivedRetry; i++)
            {
                IsDimmingModeValid = false;
                for (unsigned short j = 0; j < sizeReceived; j++)
                {
                    if (tvDimmingModesRetry[0][i] == tvDimmingModes[0][j])
                    {
                        IsDimmingModeValid = true;
                        break;
                    }
                }
                UT_ASSERT_TRUE((IsDimmingModeValid));
            }
        }
        else
        {
            UT_LOG_ERROR("Memory Allocation Failed for retry step");
        }
    }
    else
    {
        UT_LOG_ERROR("Memory Allocation Failed");
    }
    if ( tvDimmingModes[0] ){
        free ( tvDimmingModes[0] );
    }
    if ( tvDimmingModesRetry[0] ){
        free ( tvDimmingModesRetry[0] );
    }

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVSupportedDimmingModes() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 42@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetTVSupportedDimmingModes() -  Retrieve current TV Supported DimmingModes even before TvInit() | tvDimmingMode_t*[], unsigned short * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVSupportedDimmingModes() -  Retrieve supported TV dimming modes with invalid argument | NULL,  unsigned short * | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetTVSupportedDimmingModes() -  Retrieve supported TV dimming modes with invalid argument | tvDimmingMode_t*[],  NULL| tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call GetTVSupportedDimmingModes() -  Retrieve current TV Supported DimmingModes valid arguments | tvDimmingMode_t*[], unsigned short * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetTVSupportedDimmingModes (void)
{
    gTestID = 42;                                    /* It must be 42 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvDimmingMode_t *tvDimmingModes[1]={0};
    unsigned short size = 0;

    tvDimmingModes[0] = (tvDimmingMode_t *)malloc(MAX_VIDEO_FORMAT *sizeof(tvDimmingMode_t));
    if (tvDimmingModes[0] != NULL)
    {

        if (extendedEnumsSupported == true)
        {
            /* Step 01: Calling tvsettings GetTVSupportedDimmingModes and expecting the API to return tvERROR_INVALID_STATE */
            result = GetTVSupportedDimmingModes(tvDimmingModes, &size);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
        }

        /* Step 02: Calling tvsettings initialization and expecting the API to return success */
        result = TvInit();
        if (result != tvERROR_NONE)
        {
            if (tvDimmingModes[0])
            {
                free(tvDimmingModes[0]);
            }
        }
        UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

        /* Step 03: Calling tvsettings GetTVSupportedDimmingModes and expecting the API to return tvERROR_INVALID_PARAM */
        result = GetTVSupportedDimmingModes(tvDimmingModes, NULL);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

        /* Step 04: Calling tvsettings GetTVSupportedDimmingModes and expecting the API to return tvERROR_INVALID_PARAM */
        result = GetTVSupportedDimmingModes(NULL, &size);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

        /* Step 05: Calling tvsettings termination and expecting the API to return success */
        result = TvTerm();
        if (result != tvERROR_NONE)
        {
            if (tvDimmingModes[0])
            {
                free(tvDimmingModes[0]);
            }
        }
        UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

        if (extendedEnumsSupported == true)
        {
            /* Step 06: Calling tvsettings GetTVSupportedDimmingModes and expecting the API to return tvERROR_INVALID_STATE */
            result = GetTVSupportedDimmingModes(tvDimmingModes, &size);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
        }

        if (tvDimmingModes[0])
        {
            free(tvDimmingModes[0]);
        }
    }
    else
    {
        UT_LOG_ERROR("Memory Allocaiton Failed");
    }
    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetTVDimmingMode() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 43@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetTVDimmingMode() -  Set the TV dimming mode by looping through all the values of dimming modes from the DimmingMode section of test specific config file | const char * | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetTVDimmingMode (void)
{
    gTestID = 43;                                    /* It must be 43 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    uint32_t count = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };
    char modeName[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings to Set the SetTVDimmingMode for all the pic_modes and expecting the API to return success */
    count = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/DimmingMode/index");
    for (unsigned int i = 0; i < count; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/DimmingMode/range/%d", i);
        UT_KVP_PROFILE_GET_STRING(keyValue,modeName);
        result = SetTVDimmingMode(modeName);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetTVDimmingMode() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 44@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetTVDimmingMode() -  Set TV Dimming Mode even before TvInit() | const char * | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetTVDimmingMode() -   Set TV Dimming Mode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call SetTVDimmingMode() -  Set TV Dimming Mode valid arguments | const char * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetTVDimmingMode (void)
{
    gTestID = 44;                                    /* It must be 44 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    char modeName[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetTVDimmingMode and expecting the API to return tvERROR_INVALID_STATE */
        UT_KVP_PROFILE_GET_STRING("tvSettings/DimmingMode/range/0",modeName);
        result = SetTVDimmingMode(modeName);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetTVDimmingMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetTVDimmingMode(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings the SetTVDimmingMode and expecting the API to return tvERROR_INVALID_STATE */
        result = SetTVDimmingMode(modeName);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVDimmingMode() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 45@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetTVDimmingMode() -  Retrieve the current TV DimmingMode and validate DimmingMode by looping through the DimmingMode section of test specific config file | const char * | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call GetTVDimmingMode() -  Retrieve the current TV DimmingMode with valid argument and validate with above value | const char * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetTVDimmingMode (void)
{
    gTestID = 45;                                    /* It must be 45 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    char dimmingMode[MAX_DIMMING_MODES]={'\0'};
    char dimmingModeRetry[MAX_DIMMING_MODES]={'\0'};
    bool IsDimmingModeValid = false;
    uint32_t count = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };
    char modeName[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetTVDimmingMode and expectinging the API to return success */
    result = GetTVDimmingMode(dimmingMode);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    count = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/DimmingMode/index");
    for (unsigned int i = 0; i < (count); i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/DimmingMode/range/%d", i);
        UT_KVP_PROFILE_GET_STRING(keyValue,modeName);
        if (!strcmp(modeName, dimmingMode))
        {
            IsDimmingModeValid = true;
            break;
        }
    }
    UT_ASSERT_TRUE((IsDimmingModeValid));

    /* Step 03: Calling tvsettings GetTVDimmingMode and expectinging the API to return success */
    result = GetTVDimmingMode(dimmingModeRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_STRING_EQUAL(dimmingModeRetry,dimmingMode);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVDimmingMode() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 46@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetTVDimmingMode() -  Retrieve current TV DimmingMode Mode even before TvInit() | const char * | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVDimmingMode() -  Retrieve current TV DimmingMode mode with invalid argument | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetTVDimmingMode() -  Retrieve current TV DimmingMode Mode valid arguments | const char * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetTVDimmingMode (void)
{
    gTestID = 46;                                    /* It must be 46 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    char dimmingMode[MAX_DIMMING_MODES]={'\0'};

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetTVDimmingMode and expecting the API to return tvERROR_INVALID_STATE */
        result = GetTVDimmingMode(dimmingMode);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetTVDimmingMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetTVDimmingMode(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings GetTVDimmingMode and expecting the API to return tvERROR_INVALID_STATE */
        result = GetTVDimmingMode(dimmingMode);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveTVDimmingMode() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 47@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SaveTVDimmingMode() -  Save the current TV DimmingMode by looping through all the values of source input, pqmode, videoFormatType and Diming mode from the VideoSource, PictureMode, VideoFormat, DimmingMode sections of test specific config file  |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,tvDimmingMode_t | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveTVDimmingMode (void)
{
    gTestID = 47;                                    /* It must be 47 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    uint32_t dimmingModeCount = 0;
    uint32_t modeValue = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SaveTVDimmingMode for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    dimmingModeCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/DimmingMode/index");
    for (unsigned int i = 0; i < videoSrcCount; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", i);
        videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            for (unsigned int k = 0; k < videoFmtCount; k++)
            {
                snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", k);
                videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
                for (unsigned int l = 0; l < dimmingModeCount; l++)
                {
                    snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/DimmingMode/index/%d", l);
                    modeValue = UT_KVP_PROFILE_GET_UINT32(keyValue);
                    result = SaveTVDimmingMode(videoSource,pqValue,\
                            videoFormat,modeValue);
                    UT_ASSERT_EQUAL(result, tvERROR_NONE);
                }
            }
        }
    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveTVDimmingMode() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 48@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SaveTVDimmingMode() -  save the TV DimmingMode even before TvInit() | tvVideoSrcType_t , int ,tvVideoFormatType_t ,tvDimmingMode_t | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SaveTVDimmingMode() -  "pq_mode,videoFormatType,dimmingMode"=valid, "videoSrcType"=invalid max range| VIDEO_SOURCE_MAX, int ,tvVideoFormatType_t ,tvDimmingMode_t| tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SaveTVDimmingMode() -  "pq_mode,videoFormatType,dimmingMode"=valid, "videoSrcType"=invalid lower range| -2, int ,tvVideoFormatType_t ,tvDimmingMode_t| tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SaveTVDimmingMode() -  "videoSrcType,videoFormatType,dimmingMode"=valid, "pq_mode"=invalid lower range| tvVideoSrcType_t, -1 ,tvVideoFormatType_t ,tvDimmingMode_t| tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SaveTVDimmingMode() -  "videoSrcType,videoFormatType,dimmingMode"=valid, "pq_mode"=invalid max range| tvVideoSrcType_t, PQ_MODE_MAX ,tvVideoFormatType_t ,tvDimmingMode_t| tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SaveTVDimmingMode() -  "videoSrcType,pq_mode,dimmingMode"=valid, "videoFormatType"=invalid max range| tvVideoSrcType_t, int ,VIDEO_FORMAT_MAX ,tvDimmingMode_t| tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SaveTVDimmingMode() -  "videoSrcType,pq_mode,dimmingMode"=valid, "videoFormatType"=invalid lower range| tvVideoSrcType_t, int , -1 ,tvDimmingMode_t| tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SaveTVDimmingMode() -  "videoSrcType,pq_mode,videoFormatType"=valid, "dimmingMode"=invalid lower range| tvVideoSrcType_t, int , tvVideoFormatType_t ,-1| tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SaveTVDimmingMode() -  "videoSrcType,pq_mode,videoFormatType"=valid, "dimmingMode"=invalid max range| tvVideoSrcType_t, int , tvVideoFormatType_t ,tvDimmingMode_MAX| tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SaveTVDimmingMode() -  Save current TV DimmingMode with valid source input, pqmode, videoFormatType and Diming mode value but not supported by the platform by looping through the VideoSource, PictureMode, VideoFormat, DimmingMode sections of test specific config file| tvVideoSrcType_t, int , tvVideoFormatType_t , tvDimmingMode_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 13 | call SaveTVDimmingMode() -  save the TV DimmingMode valid arguments | tvVideoSrcType_t , int ,tvVideoFormatType_t ,tvDimmingMode_t | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveTVDimmingMode (void)
{
    gTestID = 48;                                    /* It must be 48 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool SupportAvailable = true;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    uint32_t dimmingModeCount = 0;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    tvDimmingMode_t modeValue = tvDimmingMode_Fixed ;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    modeValue = (tvDimmingMode_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/DimmingMode/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SaveTVDimmingMode and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveTVDimmingMode(videoSource, pqValue,
                                   videoFormat, modeValue);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SaveTVDimmingMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveTVDimmingMode(VIDEO_SOURCE_MAX,pqValue,videoFormat,modeValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SaveTVDimmingMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveTVDimmingMode((tvVideoSrcType_t)-2,pqValue,videoFormat,modeValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SaveTVDimmingMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveTVDimmingMode(videoSource,-1,videoFormat,modeValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SaveTVDimmingMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveTVDimmingMode(videoSource,PQ_MODE_MAX,videoFormat,modeValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SaveTVDimmingMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveTVDimmingMode(videoSource,pqValue,VIDEO_FORMAT_MAX,modeValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings SaveTVDimmingMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveTVDimmingMode(videoSource,pqValue,(tvVideoFormatType_t)-1,modeValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings SaveTVDimmingMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveTVDimmingMode(videoSource,pqValue,videoFormat,(tvDimmingMode_t)-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 10: Calling tvsettings SaveTVDimmingMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveTVDimmingMode(videoSource,pqValue,videoFormat,tvDimmingMode_MAX);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 11: Calling tvsettings SaveTVDimmingMode and expecting the API to return tvERROR_INVALID_PARAM */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    for( int i = VIDEO_SOURCE_ALL  ; i < VIDEO_SOURCE_MAX ; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < videoSrcCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", j);
            videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoSource == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){

            result = SaveTVDimmingMode((tvVideoSrcType_t)i,pqValue,videoFormat,modeValue);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    for(int i =0 ; i < PQ_MODE_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(pqValue == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){

            result = SaveTVDimmingMode(videoSource,i,videoFormat,modeValue);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }

    }

    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < videoFmtCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", j);
            videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoFormat == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){

            result = SaveTVDimmingMode(videoSource,pqValue,(tvVideoFormatType_t) i,modeValue);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    dimmingModeCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/DimmingMode/index");
    for(int i =tvDimmingMode_Fixed ; i < tvDimmingMode_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < dimmingModeCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/DimmingMode/index/%d", j);
            modeValue = (tvDimmingMode_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(modeValue == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){

            result = SaveTVDimmingMode(videoSource,pqValue,videoFormat, (tvDimmingMode_t)i);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 12: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    modeValue = UT_KVP_PROFILE_GET_UINT32("tvSettings/DimmingMode/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 13: Calling tvsettings SaveTVDimmingMode and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveTVDimmingMode(videoSource, pqValue, videoFormat, modeValue);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetLocalDimmingLevel() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 49@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetLocalDimmingLevel() -  Set the Local DimmingLevel with valid value | LDIM_STATE_NONBOOST | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED | Should Pass |
 * | 03 | call SetLocalDimmingLevel() -  Reset the Local DimmingLevel with another valid value | LDIM_STATE_BOOST | tvERROR_NONE | Should Pass |
 * | 04 | call SetLocalDimmingLevel() -  Reset the Local DimmingLevel with another valid value | LDIM_STATE_NONBOOST | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetLocalDimmingLevel (void)
{
    gTestID = 49;                                    /* It must be 49 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SetLocalDimmingLevel with input value LDIM_STATE_NONBOOST and expecting the API to return success */
    result = SetLocalDimmingLevel(LDIM_STATE_NONBOOST);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetLocalDimmingLevel with input value LDIM_STATE_BOOST and expecting the API to return success */
    result = SetLocalDimmingLevel(LDIM_STATE_BOOST);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings SetLocalDimmingLevel with input value LDIM_STATE_NONBOOST and expecting the API to return success */
    result = SetLocalDimmingLevel(LDIM_STATE_NONBOOST);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetLocalDimmingLevel() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 50@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetLocalDimmingLevel() - Set the TV Local DimmingLevel even before TvInit() | LDIM_STATE_NONBOOST | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetLocalDimmingLevel() -   Set the TV Local DimmingLevel with invalid input with less than lower range| -1(ldimStateLevel_t ) | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetLocalDimmingLevel() -   Set the TV Local DimmingLevel with invalid input with Max range | LDIM_STATE_MAX | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call SetLocalDimmingLevel() -  Set the TV Local DimmingLevel with valid input after TvTerm() | LDIM_STATE_BOOST | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetLocalDimmingLevel (void)
{
    gTestID = 50;                                    /* It must be 50 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool SupportAvailable = false;
    ldimStateLevel_t dimmingLevel = LDIM_STATE_NONBOOST;
    uint32_t dimmingLevelCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    dimmingLevel = (ldimStateLevel_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/TMAX/DimmingLevel/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetLocalDimmingLevel with input value LDIM_STATE_NONBOOST and expecting the API to return tvERROR_INVALID_STATE */
        result = SetLocalDimmingLevel(dimmingLevel);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetLocalDimmingLevel with input value -1 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetLocalDimmingLevel((ldimStateLevel_t ) -1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetLocalDimmingLevel with input value LDIM_STATE_MAX and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetLocalDimmingLevel(LDIM_STATE_MAX);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    dimmingLevelCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/TMAX/DimmingLevel/index");
    for (unsigned int i = LDIM_STATE_NONBOOST; i < LDIM_STATE_MAX; i++)
    {
        SupportAvailable = false;
        for( int j =0; j < (dimmingLevelCount) ; j++){
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/TMAX/DimmingLevel/index/%d", j);
            dimmingLevel = (ldimStateLevel_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if( dimmingLevel == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SetLocalDimmingLevel( (ldimStateLevel_t )i);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    dimmingLevel = (ldimStateLevel_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/TMAX/DimmingLevel/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 06: Calling tvsettings SetLocalDimmingLevel with input value LDIM_STATE_BOOST and expecting the API to return tvERROR_INVALID_STATE */
        result = SetLocalDimmingLevel(dimmingLevel);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);

}

/**
 * @brief Validate GetLocalDimmingLevel() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 51@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetLocalDimmingLevel() -  Retrieve the Local DimmingLevel with valid arguments and and validate Local DimmingLevel by looping through the LocalDimming section of test specific config file | ldimStateLevel_t * | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call GetLocalDimmingLevel() -  Retrieve the current Local DimmingLevel with valid argument and validate with above value | ldimStateLevel_t *| tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetLocalDimmingLevel (void)
{
    gTestID = 51;                                    /* It must be 51 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    ldimStateLevel_t ldimStateLevel = LDIM_STATE_MAX;
    ldimStateLevel_t ldimStateLevelRetry = LDIM_STATE_MAX;
    bool IsLdimValid = false;
    ldimStateLevel_t dimmingLevel = LDIM_STATE_NONBOOST;
    uint32_t dimmingLevelCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetLocalDimmingLevel and expectinging the API to return success */
    dimmingLevelCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/TMAX/DimmingLevel/index");
    result = GetLocalDimmingLevel(&ldimStateLevel);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    for( int j =0; j < (dimmingLevelCount) ; j++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/TMAX/DimmingLevel/index/%d", j);
        dimmingLevel = (ldimStateLevel_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        if(dimmingLevel == ldimStateLevel)
        {
            IsLdimValid = true;
            break;
        }
    }
    UT_ASSERT_TRUE((IsLdimValid));

    /* Step 03: Calling tvsettings GetLocalDimmingLevel and expectinging the API to return success */
    result = GetLocalDimmingLevel(&ldimStateLevelRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(ldimStateLevelRetry, ldimStateLevel);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetLocalDimmingLevel() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 52@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetLocalDimmingLevel() -  Retrieve current TV Local DimmingLevel even before TvInit() | ldimStateLevel_t * | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetLocalDimmingLevel() -   Retrieve current TV Local DimmingLevel with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetLocalDimmingLevel() -  Retrieve current TV Local DimmingLevel valid arguments | ldimStateLevel_t * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetLocalDimmingLevel (void)
{
    gTestID = 52;                                    /* It must be 52 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    ldimStateLevel_t ldimStateLevel = LDIM_STATE_MAX;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetLocalDimmingLevel and expectinging the API to return tvERROR_INVALID_STATE */
        result = GetLocalDimmingLevel(&ldimStateLevel);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetLocalDimmingLevel and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetLocalDimmingLevel(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings GetLocalDimmingLevel and expectinging the API to return tvERROR_INVALID_STATE */
        result = GetLocalDimmingLevel(&ldimStateLevel);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveLocalDimmingLevel() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 53@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 02 | call SaveLocalDimmingLevel() -  Save the current LocalDimming Level by looping through all the values of sourceId, pqmode, videoFormatType, value from the VideoSource, PictureMode, VideoFormat, LocalDimming sections of test specific config file |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,ldimStateLevel_t | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
//TODO: DIMMING LEVEL
void test_l1_tvSettings_positive_SaveLocalDimmingLevel (void)
{
    gTestID = 53;                                    /* It must be 53 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    ldimStateLevel_t dimmingLevel = LDIM_STATE_NONBOOST;
    uint32_t dimmingLevelCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SaveLocalDimmingLevel for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    for (unsigned int i = 0; i < videoSrcCount; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", i);
        videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            for (unsigned int k = 0; k < videoFmtCount; k++)
            {
                snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", k);
                videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
                for (unsigned int l = 0; l < dimmingLevelCount; l++)
                {
                    snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/TMAX/DimmingLevel/index/%d", l);
                    dimmingLevel = (ldimStateLevel_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
                    result = SaveLocalDimmingLevel(videoSource,pqValue,\
                            videoFormat,dimmingLevel);
                    UT_ASSERT_EQUAL(result, tvERROR_NONE);
                }
            }
        }
    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveLocalDimmingLevel() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 54@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SaveLocalDimmingLevel() -  save current Local DimmingLevel even before TvInit() | tvVideoSrcType_t, int , tvVideoFormatType_t ,ldimStateLevel_t | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SaveLocalDimmingLevel() -  "pq_mode,videoFormatType,ldimStateLevel"=valid, "tvVideoSrcType_t"=invalid max range| VIDEO_SOURCE_MAX, int ,tvVideoFormatType_t ,ldimStateLevel_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SaveLocalDimmingLevel() -  "pq_mode,videoFormatType,ldimStateLevel"=valid, "tvVideoSrcType_t"=invalid lower range| -2 , int ,tvVideoFormatType_t ,ldimStateLevel_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SaveLocalDimmingLevel() -  "videoSrcType,videoFormatType,ldimStateLevel"=valid, "pq_mode"=invalid lower range| tvVideoSrcType_t, -1 ,tvVideoFormatType_t ,ldimStateLevel_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SaveLocalDimmingLevel() -  "videoSrcType,videoFormatType,ldimStateLevel"=valid, "pq_mode"=invalid max range| tvVideoSrcType_t, PQ_MODE_MAX ,tvVideoFormatType_t ,ldimStateLevel_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SaveLocalDimmingLevel() -  "videoSrcType,pq_mode,ldimStateLevel"=valid, "videoFormatType"=invalid max range| tvVideoSrcType_t, int ,VIDEO_FORMAT_MAX ,ldimStateLevel_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SaveLocalDimmingLevel() -  "videoSrcType,pq_mode,ldimStateLevel"=valid, "videoFormatType"=invalid lower range| tvVideoSrcType_t, int , -1 ,ldimStateLevel_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SaveLocalDimmingLevel() -  "videoSrcType,pq_mode,videoFormatType"=valid, "ldimStateLevel"=invalid max range| tvVideoSrcType_t, int , tvVideoFormatType_t , LDIM_STATE_MAX | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SaveLocalDimmingLevel() -  "videoSrcType,pq_mode,videoFormatType"=valid, "ldimStateLevel"=invalid lower range| tvVideoSrcType_t, int , tvVideoFormatType_t ,-1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SaveLocalDimmingLevel() -  Save current LocalDimming Level with valid value of source input, pqmode, videoFormatType but not supported by the platform by looping through the VideoSource, PictureMode, VideoFormat, LocalDimming sections of test specific config file| tvVideoSrcType_t, int , tvVideoFormatType_t ,ldimStateLevel_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 13 | call SaveLocalDimmingLevel() -  save current Local DimmingLevel valid arguments | tvVideoSrcType_t, int , tvVideoFormatType_t ,ldimStateLevel_t | tvERROR_INVALID_STATE | Should Pass |
 */
//TODO: DIMMING LEVEL
void test_l1_tvSettings_negative_SaveLocalDimmingLevel (void)
{
    gTestID = 54;                                    /* It must be 54 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool SupportAvailable = true;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    ldimStateLevel_t dimmingLevel = LDIM_STATE_NONBOOST;
    uint32_t dimmingLevelCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    dimmingLevel = (ldimStateLevel_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/TMAX/DimmingLevel/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SaveLocalDimmingLevel and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveLocalDimmingLevel(videoSource, pqValue, videoFormat, dimmingLevel);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SaveLocalDimmingLevel and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveLocalDimmingLevel(VIDEO_SOURCE_MAX,pqValue,videoFormat,dimmingLevel);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SaveLocalDimmingLevel and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveLocalDimmingLevel((tvVideoSrcType_t)-2,pqValue,videoFormat,dimmingLevel);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SaveLocalDimmingLevel and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveLocalDimmingLevel(videoSource,-1,videoFormat,dimmingLevel);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SaveLocalDimmingLevel and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveLocalDimmingLevel(videoSource,PQ_MODE_MAX,videoFormat,dimmingLevel);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SaveLocalDimmingLevel and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveLocalDimmingLevel(videoSource,pqValue,VIDEO_FORMAT_MAX,dimmingLevel);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings SaveLocalDimmingLevel and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveLocalDimmingLevel(videoSource,pqValue,(tvVideoFormatType_t)-1,dimmingLevel);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings SaveLocalDimmingLevel and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveLocalDimmingLevel(videoSource,pqValue,videoFormat,(ldimStateLevel_t)-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 10: Calling tvsettings SaveLocalDimmingLevel and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveLocalDimmingLevel(videoSource,pqValue,videoFormat,LDIM_STATE_MAX);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 11: Calling tvsettings SaveLocalDimmingLevel and expecting the API to return tvERROR_INVALID_PARAM */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    for(int i =VIDEO_SOURCE_ALL ; i < VIDEO_SOURCE_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < videoSrcCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", j);
            videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoSource == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveLocalDimmingLevel((tvVideoSrcType_t)i,pqValue,videoFormat,dimmingLevel);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    for(int i =0 ; i < PQ_MODE_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(pqValue == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveLocalDimmingLevel(videoSource,i,videoFormat,dimmingLevel);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < videoFmtCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", j);
            videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoFormat == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveLocalDimmingLevel(videoSource,pqValue,(tvVideoFormatType_t)i,dimmingLevel);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    dimmingLevelCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/TMAX/DimmingLevel/index");
    for(int i =LDIM_STATE_NONBOOST ; i < LDIM_STATE_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < dimmingLevelCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/TMAX/DimmingLevel/index/%d", j);
            dimmingLevel = (ldimStateLevel_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(dimmingLevel == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveLocalDimmingLevel(videoSource,pqValue ,videoFormat,(ldimStateLevel_t)i);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 12: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    dimmingLevel = (ldimStateLevel_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/TMAX/DimmingLevel/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 13: Calling tvsettings SaveLocalDimmingLevel and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveLocalDimmingLevel(videoSource, pqValue, videoFormat, dimmingLevel);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetBrightness() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 55@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetBrightness() -  Set the brightness with valid value | 00 | tvERROR_NONE | Should Pass |
 * | 03 | call SetBrightness() -  Reset the brightness with another valid value | 50 | tvERROR_NONE | Should Pass |
 * | 04 | call SetBrightness() -  Reset the brightness with another valid value | 100 | tvERROR_NONE | Should Pass |
 * | 05 | call SetBrightness() -  Reset the brightness with the same value as in previous variation | 100 | tvERROR_NONE | Should Pass |
 * | 06 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetBrightness (void)
{
    gTestID = 55;                                    /* It must be 55 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SetBrightness with value 0 and expecting the API to return success */
    result = SetBrightness(0);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetBrightness with value 50 and expecting the API to return success */
    result = SetBrightness(50);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings SetBrightness with value 100 and expecting the API to return success */
    result = SetBrightness(100);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 05: Calling tvsettings SetBrightness with value 100 and expecting the API to return success */
    result = SetBrightness(100);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 06: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetBrightness() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 56@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetBrightness() - Set the TV brightness even before TvInit() | 30 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetBrightness() -   Set the TV brightness with less than the lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetBrightness() -   Set the TV brightness with max range | 101 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetBrightness() -   Set the TV brightness with max range | 200 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 07 | call SetBrightness() -  Set the TV brightness with valid input after TvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetBrightness (void)
{
    gTestID = 56;                                    /* It must be 56 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetBrightness and expecting the API to return tvERROR_INVALID_STATE */
        result = SetBrightness(30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetBrightness with value -1 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetBrightness(-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetBrightness with value 101 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetBrightness(101);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SetBrightness with value 200 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetBrightness(200);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 07: Calling tvsettings the SetBrightness and expecting the API to return tvERROR_INVALID_STATE */
        result = SetBrightness(50);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);

}

/**
 * @brief Validate GetBrightness() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 57@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetBrightness() -  Retrieve the current brightness with valid arguments and validate with range (1-100) | int * | tvERROR_NONE | Should Pass |
 * | 03 | call GetBrightness() -  Retrieve the current brightness with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetBrightness (void)
{
    gTestID = 57;                                    /* It must be 57 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int brightness = -1;
    int brightnessRetry = -1;
    int range_from = 0;
    int range_to = 0;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetBrightness and expecting the API to return success */
    range_from = UT_KVP_PROFILE_GET_UINT32("tvSettings/Brightness/range_from");
    range_to = UT_KVP_PROFILE_GET_UINT32("tvSettings/Brightness/range_to");
    result = GetBrightness(&brightness);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_TRUE((brightness >= range_from && brightness <= range_to));

    /* Step 03: Calling tvsettings GetBrightness again and expecting the API to return success */
    result = GetBrightness(&brightnessRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(brightness, brightnessRetry);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetBrightness() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 58@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetBrightness() -  Retrieve current TV brightness even before TvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetBrightness() -  Retrieve current TV brightness with invalid argument | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetBrightness() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetBrightness (void)
{
    gTestID = 58;                                    /* It must be 58 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int brightness = -1;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetBrightness and expecting the API to return tvERROR_INVALID_STATE */
        result = GetBrightness(&brightness);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetBrightness with invalid input and expecting the API to return tvERROR_INVALID_PARAM*/
    result = GetBrightness(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings GetBrightness and expecting the API to return tvERROR_INVALID_STATE */
        result = GetBrightness(&brightness);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveBrightness() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 59@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SaveBrightness() -  Save the current Color Brightness by looping through all the values of sourceId, pqmode, videoFormatType from the VideoSource, PictureMode, VideoFormat sections of test specific config file  |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,int | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveBrightness (void)
{
    gTestID = 59;                                    /* It must be 59 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SaveBrightness for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    for (unsigned int i = 0; i < videoSrcCount; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", i);
        videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            for (unsigned int k = 0; k < videoFmtCount; k++)
            {
                snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", k);
                videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
                result = SaveBrightness(videoSource,pqValue,videoFormat,50);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);
            }
        }
    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveBrightness() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 60@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SaveBrightness() -  save current TV Brightness even before TvInit() | tvVideoSrcType_t , int ,tvVideoFormatType_t ,int  | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SaveBrightness() -  "pq_mode,videoFormatType,value"=valid, "videoSrcType"=invalid max range| VIDEO_SOURCE_MAX, int ,tvVideoFormatType_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SaveBrightness() -  "pq_mode,videoFormatType,value"=valid, "videoSrcType"=invalid lower range| -2, int ,tvVideoFormatType_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SaveBrightness() -  "videoSrcType,videoFormatType,value"=valid, "pq_mode"=invalid lower range | tvVideoSrcType_t, -1 ,tvVideoFormatType_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SaveBrightness() -  "videoSrcType,videoFormatType,value"=valid, "pq_mode"=invalid max range| tvVideoSrcType_t, PQ_MODE_MAX ,tvVideoFormatType_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SaveBrightness() -  "videoSrcType,pq_mode,value"=valid, "videoFormatType"=invalid max range| tvVideoSrcType_t, int ,VIDEO_FORMAT_MAX ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SaveBrightness() -  "videoSrcType,pq_mode,value"=valid, "videoFormatType"=invalid lower range| tvVideoSrcType_t, int , -1 ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SaveBrightness() -  "videoSrcType,pq_mode,videoFormatType"=valid, "value"=invalid max range| tvVideoSrcType_t, int , tvVideoFormatType_t ,101| tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SaveBrightness() -  "videoSrcType,pq_mode,videoFormatType"=valid, "value"=invalid lower range| tvVideoSrcType_t, int , tvVideoFormatType_t ,-1| tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SaveBrightness() -  Save current Color Brightness with valid source input, pqmode, videoFormatType value but not supported by the platform by looping through the VideoSource, PictureMode, VideoFormat sections of test specific config file| tvVideoSrcType_t, int , tvVideoFormatType_t , 50| tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 13 | call SaveBrightness() -  save current TV Brightness valid arguments | tvVideoSrcType_t , int ,tvVideoFormatType_t ,int  | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveBrightness (void)
{
    gTestID = 60;                                    /* It must be 60 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool SupportAvailable = true;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    uint32_t count = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SaveBrightness and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveBrightness(videoSource, pqValue, videoFormat, 50);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SaveBrightness and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveBrightness(VIDEO_SOURCE_MAX,pqValue,videoFormat,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SaveBrightness and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveBrightness((tvVideoSrcType_t)-2,pqValue,videoFormat,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SaveBrightness and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveBrightness(videoSource,-1,videoFormat,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SaveBrightness and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveBrightness(videoSource,PQ_MODE_MAX,videoFormat,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SaveBrightness and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveBrightness(videoSource,pqValue,VIDEO_FORMAT_MAX,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings SaveBrightness and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveBrightness(videoSource,pqValue,(tvVideoFormatType_t)-1,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings SaveBrightness and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveBrightness(videoSource,pqValue,videoFormat,-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 10: Calling tvsettings SaveBrightness and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveBrightness(videoSource,pqValue,videoFormat,101);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 11: Calling tvsettings SaveBrightness and expecting the API to return tvERROR_INVALID_PARAM */
    count = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    for(int i =VIDEO_SOURCE_ALL ; i < VIDEO_SOURCE_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < count; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", j);
            videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoSource == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveBrightness((tvVideoSrcType_t)i,pqValue,videoFormat,50);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    count = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    for(int i =0 ; i < PQ_MODE_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < count; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(pqValue == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveBrightness(videoSource,i,videoFormat,50);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    count = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < count; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", j);
            videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoFormat == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveBrightness(videoSource,pqValue,(tvVideoFormatType_t)i,50);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }


    /* Step 12: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 13: Calling tvsettings SaveBrightness and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveBrightness(videoSource, pqValue, videoFormat, 50);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetContrast() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 61@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetContrast() -  Set the Contrast with valid value | 00 | tvERROR_NONE | Should Pass |
 * | 03 | call SetContrast() -  Reset the Contrast with another valid value | 50 | tvERROR_NONE | Should Pass |
 * | 04 | call SetContrast() -  Reset the Contrast with another valid value | 100 | tvERROR_NONE | Should Pass |
 * | 05 | call SetContrast() -  Reset the Contrast with the same value as in previous variation | 100 | tvERROR_NONE | Should Pass |
 * | 06 | call TvTerm() -  Terminate and close the instance of the TV client  | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetContrast (void)
{
    gTestID = 61;                                    /* It must be 61 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SetContrast with Contrast value 0 and expecting the API to return success */
    result = SetContrast(0);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetContrast with Contrast value 50 and expecting the API to return success */
    result = SetContrast(50);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings SetContrast with Contrast value 100 and expecting the API to return success */
    result = SetContrast(100);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 05: Calling tvsettings SetContrast with Contrast value 100 and expecting the API to return success */
    result = SetContrast(100);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 06: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetContrast() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 62@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetContrast() - Set the TV contrast even before TvInit() | 30 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetContrast() -   Set the TV contrast with less than the lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetContrast() -   Set the TV contrast with max range | 101 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetContrast() -   Set the TV contrast with max range | 200 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 07 | call SetContrast() -  Set the TV contrast with valid input after TvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetContrast (void)
{
    gTestID = 62;                                    /* It must be 62 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetContrast and expecting the API to return tvERROR_INVALID_STATE */
        result = SetContrast(30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetContrast with Contrast value -1 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetContrast(-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetContrast with Contrast value 101 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetContrast(101);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SetContrast with Contrast value 200 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetContrast(200);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 07: Calling tvsettings the SetContrast and expecting the API to return tvERROR_INVALID_STATE */
        result = SetContrast(50);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetContrast() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 63@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetContrast() -  Retrieve the current Contrast with valid arguments and validate with range (1-100) | int * | tvERROR_NONE | Should Pass |
 * | 03 | call GetContrast() -  Retrieve the current Contrast with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetContrast (void)
{
    gTestID = 63;                                    /* It must be 63 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int contrast = -1;
    int contrastRetry = -1;
    int range_from = 0;
    int range_to = 0;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetContrast and expecting the API to return success */
    range_from = UT_KVP_PROFILE_GET_UINT32("tvSettings/Contrast/range_from");
    range_to = UT_KVP_PROFILE_GET_UINT32("tvSettings/Contrast/range_to");
    result = GetContrast(&contrast);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_TRUE((contrast >= range_from && contrast <= range_to));

    /* Step 03: Calling tvsettings GetContrast again and expecting the API to return success */
    result = GetContrast(&contrastRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(contrast, contrastRetry);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetContrast() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 64@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetContrast() -  Retrieve current TV contrast even before TvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetContrast() -  Retrieve current TV Contrast with invalid argument | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetContrast() -  Retrieve current TV contrast valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetContrast (void)
{
    gTestID = 64;                                    /* It must be 64 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int contrast = -1;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetTVBcklight and expecting the API to return tvERROR_INVALID_STATE */
        result = GetContrast(&contrast);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetContrast with invalid input and expecting the API to return tvERROR_INVALID_PARAM*/
    result = GetContrast(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings GetContrast and expecting the API to return tvERROR_INVALID_STATE */
        result = GetContrast(&contrast);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveContrast() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 65@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SaveContrast() -  Save the current Color Contrast by looping through all the values of sourceId, pqmode, videoFormatType from the VideoSource, PictureMode, VideoFormat sections of test specific config file  |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,int | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveContrast (void)
{
    gTestID = 65;                                    /* It must be 65 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SaveContrast for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    for (unsigned int i = 0; i < videoSrcCount; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", i);
        videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            for (unsigned int k = 0; k < videoFmtCount; k++)
            {
                snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", k);
                videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
                result = SaveContrast(videoSource,pqValue,videoFormat,50);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);
            }
        }
    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveContrast() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 66@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SaveContrast() -  save current TV Contrast even before TvInit() | tvVideoSrcType_t, int , tvVideoFormatType_t ,int | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SaveContrast() -  "pq_mode,videoFormatType,value"=valid, "videoSrcType"=invalid max range| VIDEO_SOURCE_MAX, int ,tvVideoFormatType_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SaveContrast() -  "pq_mode,videoFormatType,value"=valid, "videoSrcType"=invalid lower range| -2, int ,tvVideoFormatType_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SaveContrast() -  "videoSrcType,videoFormatType,value"=valid, "pq_mode"=invalid lower range| tvVideoSrcType_t, -1 ,tvVideoFormatType_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SaveContrast() -  "videoSrcType,videoFormatType,value"=valid, "pq_mode"=invalid max range| tvVideoSrcType_t, PQ_MODE_MAX ,tvVideoFormatType_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SaveContrast() -  "videoSrcType,pq_mode,value"=valid, "videoFormatType"=invalid max range| tvVideoSrcType_t, int ,VIDEO_FORMAT_MAX ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SaveContrast() -  "videoSrcType,pq_mode,value"=valid, "videoFormatType"=invalid lower range| tvVideoSrcType_t, int , -1 ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SaveContrast() -  "videoSrcType,pq_mode,videoFormatType"=valid, "value"=invalid max range| tvVideoSrcType_t, int , tvVideoFormatType_t ,101| tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SaveContrast() -  "videoSrcType,pq_mode,videoFormatType"=valid, "value"=invalid lower range| tvVideoSrcType_t, int , tvVideoFormatType_t ,-1| tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SaveContrast() -  Save current Color Contrast with valid source input, pqmode, videoFormatType value but not supported by the platform by looping through the VideoSource, PictureMode, VideoFormat sections of test specific config file| tvVideoSrcType_t, int , tvVideoFormatType_t , 50| tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 13 | call SaveContrast() -  save current TV Contrast valid arguments | tvVideoSrcType_t, int , tvVideoFormatType_t ,int | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveContrast (void)
{
    gTestID = 66;                                    /* It must be 66 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool SupportAvailable = true;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SaveContrast and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveContrast(videoSource, pqValue, videoFormat, 50);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SaveContrast and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveContrast(VIDEO_SOURCE_MAX,pqValue,videoFormat,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SaveContrast and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveContrast((tvVideoSrcType_t)-2,pqValue,videoFormat,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SaveContrast and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveContrast(videoSource,-1,videoFormat,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SaveContrast and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveContrast(videoSource,PQ_MODE_MAX,videoFormat,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SaveContrast and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveContrast(videoSource,pqValue,VIDEO_FORMAT_MAX,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings SaveContrast and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveContrast(videoSource,pqValue,(tvVideoFormatType_t)-1,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings SaveContrast and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveContrast(videoSource,pqValue,videoFormat,-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 10: Calling tvsettings SaveContrast and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveContrast(videoSource,pqValue,videoFormat,101);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 11: Calling tvsettings SaveContrast and expecting the API to return tvERROR_INVALID_PARAM */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    for(int i =VIDEO_SOURCE_ALL ; i < VIDEO_SOURCE_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < videoSrcCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", j);
            videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoSource == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveContrast((tvVideoSrcType_t)i,pqValue,videoFormat,50);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    for(int i =0 ; i < PQ_MODE_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(pqValue == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveContrast(videoSource,i,videoFormat,50);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < videoFmtCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", j);
            videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoFormat == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveContrast(videoSource,pqValue,(tvVideoFormatType_t)i,50);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }
    /* Step 12: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 13: Calling tvsettings SaveContrast and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveContrast(videoSource, pqValue, videoFormat, 50);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetSharpness() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 67@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetSharpness() -  Set the sharpness with valid value | 00 | tvERROR_NONE | Should Pass |
 * | 03 | call SetSharpness() -  Reset the sharpness with another valid value | 50 | tvERROR_NONE | Should Pass |
 * | 04 | call SetSharpness() -  Reset the sharpness with another valid value | 100 | tvERROR_NONE | Should Pass |
 * | 05 | call SetSharpness() -  Reset the sharpness with the same value as in previous variation | 100 | tvERROR_NONE | Should Pass |
 * | 06 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetSharpness (void)
{
    gTestID = 67;                                    /* It must be 67 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SetSharpness with Sharpness value 0 and expecting the API to return success */
    result = SetSharpness(0);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetSharpness with Sharpness value 50 and expecting the API to return success */
    result = SetSharpness(50);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings SetSharpness with Sharpness value 100 and expecting the API to return success */
    result = SetSharpness(100);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 05: Calling tvsettings SetSharpness with Sharpness value 100 and expecting the API to return success */
    result = SetSharpness(100);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 06: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetSharpness() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 68@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetSharpness() - Set the TV sharpness even before TvInit() | 30 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetSharpness() -   Set the TV sharpness with less than the lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetSharpness() -   Set the TV sharpness with max range | 101 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetSharpness() -   Set the TV sharpness with max range | 200 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 07 | call SetSharpness() -  Set the TV sharpness with valid input after TvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetSharpness (void)
{
    gTestID = 68;                                    /* It must be 68 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetSharpness and expecting the API to return tvERROR_INVALID_STATE */
        result = SetSharpness(30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetSharpness with Sharpness value -1 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetSharpness(-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetSharpness with Sharpness value 101 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetSharpness(101);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SetSharpness with Sharpness value 200 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetSharpness(200);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 07: Calling tvsettings the SetSharpness and expecting the API to return tvERROR_INVALID_STATE */
        result = SetSharpness(50);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetSharpness() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 69@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetSharpness() -  Retrieve the current sharpness with valid arguments and validate with range (1-100) | int * | tvERROR_NONE | Should Pass |
 * | 03 | call GetSharpness() -  Retrieve the current sharpness with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetSharpness (void)
{
    gTestID = 69;                                    /* It must be 69 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int sharpness = -1;
    int sharpnessRetry = -1;
    int range_from = 0;
    int range_to = 0;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetSharpness and expecting the API to return success */
    range_from = UT_KVP_PROFILE_GET_UINT32("tvSettings/Sharpness/range_from");
    range_to = UT_KVP_PROFILE_GET_UINT32("tvSettings/Sharpness/range_to");
    result = GetSharpness(&sharpness);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_TRUE((sharpness >= range_from && sharpness <= range_to));

    /* Step 03: Calling tvsettings GetSharpness again and expecting the API to return success */
    result = GetSharpness(&sharpnessRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(sharpness, sharpnessRetry);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetSharpness() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 70@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetSharpness() -  Retrieve current TV sharpness even before TvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetSharpness() -  Retrieve current TV Sharpness with invalid argument | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetSharpness() -  Retrieve current TV sharpness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetSharpness (void)
{
    gTestID = 70;                                    /* It must be 70 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int sharpness = -1;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetTVBcklight and expecting the API to return tvERROR_INVALID_STATE */
        result = GetSharpness(&sharpness);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetSharpness with invalid input and expecting the API to return tvERROR_INVALID_PARAM*/
    result = GetSharpness(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings GetSharpness and expecting the API to return tvERROR_INVALID_STATE */
        result = GetSharpness(&sharpness);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveSharpness() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 71@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SaveSharpness() -  Save the current Color Sharpness by looping through all the values of sourceId, pqmode, videoFormatType from the VideoSource, PictureMode, VideoFormat sections of test specific config file  |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,int | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveSharpness (void)
{
    gTestID = 71;                                    /* It must be 71 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SaveSharpness for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    for (unsigned int i = 0; i < videoSrcCount; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", i);
        videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            for (unsigned int k = 0; k < videoFmtCount; k++)
            {
                snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", k);
                videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
                result = SaveSharpness(videoSource,pqValue,videoFormat,50);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);
            }
        }
    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveSharpness() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 72@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SaveSharpness() -  save current TV Sharpness even before TvInit() | tvVideoSrcType_t, int , tvVideoFormatType_t ,int | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SaveSharpness() -  "pq_mode,videoFormatType,value"=valid, "videoSrcType"=invalid max range| VIDEO_SOURCE_MAX, int ,tvVideoFormatType_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SaveSharpness() -  "pq_mode,videoFormatType,value"=valid, "videoSrcType"=invalid lower range| -2, int ,tvVideoFormatType_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SaveSharpness() -  "videoSrcType,videoFormatType,value"=valid, "pq_mode"=invalid lower range| tvVideoSrcType_t, -1 ,tvVideoFormatType_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SaveSharpness() -  "videoSrcType,videoFormatType,value"=valid, "pq_mode"=invalid max range | tvVideoSrcType_t, PQ_MODE_MAX ,tvVideoFormatType_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SaveSharpness() -  "videoSrcType,pq_mode,value"=valid, "videoFormatType"=invalid max range| tvVideoSrcType_t, int ,VIDEO_FORMAT_MAX ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SaveSharpness() -  "videoSrcType,pq_mode,value"=valid, "videoFormatType"=invalid lower range| tvVideoSrcType_t, int , -1 ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SaveSharpness() -  "videoSrcType,pq_mode,videoFormatType"=valid, "value"=invalid max range| tvVideoSrcType_t, int , tvVideoFormatType_t ,101| tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SaveSharpness() -  "videoSrcType,pq_mode,videoFormatType"=valid, "value"=invalid lower range| tvVideoSrcType_t, int , tvVideoFormatType_t ,-1| tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SaveSharpness() -  Save current Color Sharpness with valid source input, pqmode, videoFormatType value but not supported by the platform by looping through the VideoSource, PictureMode, VideoFormat sections of test specific config file| tvVideoSrcType_t, int , tvVideoFormatType_t , 50| tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 13 | call SaveSharpness() -  save current TV Sharpness valid arguments | tvVideoSrcType_t, int , tvVideoFormatType_t ,int | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveSharpness (void)
{
    gTestID = 72;                                    /* It must be 72 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool SupportAvailable = true;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SaveSharpness and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveSharpness(videoSource, pqValue, videoFormat, 50);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SaveSharpness and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveSharpness(VIDEO_SOURCE_MAX,pqValue,videoFormat,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SaveSharpness and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveSharpness((tvVideoSrcType_t)-2,pqValue,videoFormat,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SaveSharpness and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveSharpness(videoSource,-1,videoFormat,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SaveSharpness and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveSharpness(videoSource,PQ_MODE_MAX,videoFormat,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SaveSharpness and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveSharpness(videoSource,pqValue,VIDEO_FORMAT_MAX,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings SaveSharpness and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveSharpness(videoSource,pqValue,(tvVideoFormatType_t)-1,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings SaveSharpness and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveSharpness(videoSource,pqValue,videoFormat,-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 10: Calling tvsettings SaveSharpness and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveSharpness(videoSource,pqValue,videoFormat,101);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 11: Calling tvsettings SaveSharpness and expecting the API to return tvERROR_INVALID_PARAM */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    for(int i =VIDEO_SOURCE_ALL ; i < VIDEO_SOURCE_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < videoSrcCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", j);
            videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoSource == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveSharpness((tvVideoSrcType_t)i,pqValue,videoFormat,50);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    for(int i =0 ; i < PQ_MODE_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(pqValue == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveSharpness(videoSource,i,videoFormat,50);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < videoFmtCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", j);
            videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoFormat == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveSharpness(videoSource,pqValue,(tvVideoFormatType_t)i,50);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }
    /* Step 12: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 13: Calling tvsettings SaveSharpness and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveSharpness(videoSource, pqValue, videoFormat, 50);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetSaturation() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 73@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetSaturation() -  Set the saturation with valid value | 0 | tvERROR_NONE | Should Pass |
 * | 03 | call SetSaturation() -  Reset the saturation with another valid value | 50 | tvERROR_NONE | Should Pass |
 * | 04 | call SetSaturation() -  Reset the saturation with another valid value | 100 | tvERROR_NONE | Should Pass |
 * | 05 | call SetSaturation() -  Reset the saturation with the same value as in previous variation | 100 | tvERROR_NONE | Should Pass |
 * | 06 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetSaturation (void)
{
    gTestID = 73;                                    /* It must be 73 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SetSaturation with Saturation value 0 and expecting the API to return success */
    result = SetSaturation(0);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetSaturation with Saturation value 50 and expecting the API to return success */
    result = SetSaturation(50);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings SetSaturation with Saturation value 100 and expecting the API to return success */
    result = SetSaturation(100);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 05: Calling tvsettings SetSaturation with Saturation value 100 and expecting the API to return success */
    result = SetSaturation(100);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 06: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetSaturation() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 74@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetSaturation() - Set the TV saturation even before TvInit() | 30 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetSaturation() -   Set the TV saturation with less than the lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetSaturation() -   Set the TV saturation with max range | 101 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetSaturation() -   Set the TV saturation with max range | 200 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 07 | call SetSaturation() -  Set the TV saturation with valid input after TvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetSaturation (void)
{
    gTestID = 74;                                    /* It must be 74 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetSaturation and expecting the API to return tvERROR_INVALID_STATE */
        result = SetSaturation(30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetSaturation with Saturation value -1 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetSaturation(-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetSaturation with Saturation value 101 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetSaturation(101);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SetSaturation with Saturation value 200 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetSaturation(200);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 07: Calling tvsettings the SetSaturation and expecting the API to return tvERROR_INVALID_STATE */
        result = SetSaturation(50);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetSaturation() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 75@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetSaturation() -  Retrieve the current saturation with valid arguments and validate with range (1-100) | int * | tvERROR_NONE | Should Pass |
 * | 03 | call GetSaturation() -  Retrieve the current saturation with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetSaturation (void)
{
    gTestID = 75;                                    /* It must be 75 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int saturation = -1;
    int saturationRetry = -1;
    int range_from = 0;
    int range_to = 0;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetSaturation and expecting the API to return success */
    range_from = UT_KVP_PROFILE_GET_UINT32("tvSettings/Saturation/range_from");
    range_to = UT_KVP_PROFILE_GET_UINT32("tvSettings/Saturation/range_to");
    result = GetSaturation(&saturation);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_TRUE((saturation >= range_from && saturation <= range_to));

    /* Step 03: Calling tvsettings GetSaturation again and expecting the API to return success */
    result = GetSaturation(&saturationRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(saturation, saturationRetry);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetSaturation() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 76@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetSaturation() -  Retrieve current TV saturation even before TvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetSaturation() -  Retrieve current TV Saturation with invalid argument | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetSaturation() -  Retrieve current TV saturation valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetSaturation (void)
{
    gTestID = 76;                                    /* It must be 76 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int saturation = -1;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetTVBcklight and expecting the API to return tvERROR_INVALID_STATE */
        result = GetSaturation(&saturation);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetSaturation with invalid input and expecting the API to return tvERROR_INVALID_PARAM*/
    result = GetSaturation(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings GetSaturation and expecting the API to return tvERROR_INVALID_STATE */
        result = GetSaturation(&saturation);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveSaturation() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 77@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SaveSaturation() -  Save the current Color Saturation by looping through all the values of sourceId, pqmode, videoFormatType from the VideoSource, PictureMode, VideoFormat sections of test specific config file  |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,int | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveSaturation (void)
{
    gTestID = 77;                                    /* It must be 77 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SaveSaturation for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    for (unsigned int i = 0; i < videoSrcCount; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", i);
        videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            for (unsigned int k = 0; k < videoFmtCount; k++)
            {
                snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", k);
                videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
                result = SaveSaturation(videoSource,pqValue,videoFormat,50);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);
            }
        }
    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveSaturation() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 78@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SaveSaturation() -  save current TV Saturation even before TvInit() | tvVideoSrcType_t, int , tvVideoFormatType_t ,int | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SaveSaturation() -  "pq_mode,videoFormatType,value"=valid, "videoSrcType"=invalid max range| VIDEO_SOURCE_MAX, int ,tvVideoFormatType_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SaveSaturation() -  "pq_mode,videoFormatType,value"=valid, "videoSrcType"=invalid lower range| -2, int ,tvVideoFormatType_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SaveSaturation() -  "videoSrcType,videoFormatType,value"=valid, "pq_mode"=invalid lower range | tvVideoSrcType_t, -1 ,tvVideoFormatType_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SaveSaturation() -  "videoSrcType,videoFormatType,value"=valid, "pq_mode"=invalid max range | tvVideoSrcType_t, PQ_MODE_MAX ,tvVideoFormatType_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SaveSaturation() -  "videoSrcType,pq_mode,value"=valid, "videoFormatType"=invalid max range| tvVideoSrcType_t, int ,VIDEO_FORMAT_MAX ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SaveSaturation() -  "videoSrcType,pq_mode,value"=valid, "videoFormatType"=invalid lower range| tvVideoSrcType_t, int , -1 ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SaveSaturation() -  "videoSrcType,pq_mode,videoFormatType"=valid, "value"=invalid max range| tvVideoSrcType_t, int , tvVideoFormatType_t ,101| tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SaveSaturation() -  "videoSrcType,pq_mode,videoFormatType"=valid, "value"=invalid lower range| tvVideoSrcType_t, int , tvVideoFormatType_t ,-1| tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SaveSaturation() -  Save current Color Saturation with valid source input, pqmode, videoFormatType value but not supported by the platform by looping through the VideoSource, PictureMode, VideoFormat sections of test specific config file| tvVideoSrcType_t, int , tvVideoFormatType_t , 50| tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 13 | call SaveSaturation() -  save current TV Saturation valid arguments | tvVideoSrcType_t, int , tvVideoFormatType_t ,int | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveSaturation (void)
{
    gTestID = 78;                                    /* It must be 78 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool SupportAvailable = true;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SaveSaturation and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveSaturation(videoSource, pqValue, videoFormat, 50);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SaveSaturation and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveSaturation(VIDEO_SOURCE_MAX,pqValue,videoFormat,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SaveSaturation and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveSaturation((tvVideoSrcType_t)-2,pqValue,videoFormat,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SaveSaturation and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveSaturation(videoSource,-1,videoFormat,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SaveSaturation and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveSaturation(videoSource,PQ_MODE_MAX,videoFormat,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SaveSaturation and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveSaturation(videoSource,pqValue,VIDEO_FORMAT_MAX,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings SaveSaturation and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveSaturation(videoSource,pqValue,(tvVideoFormatType_t)-1,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings SaveSaturation and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveSaturation(videoSource,pqValue,videoFormat,-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 10: Calling tvsettings SaveSaturation and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveSaturation(videoSource,pqValue,videoFormat,101);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 11: Calling tvsettings SaveSaturation and expecting the API to return tvERROR_INVALID_PARAM */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    for(int i =VIDEO_SOURCE_ALL ; i < VIDEO_SOURCE_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < videoSrcCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", j);
            videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoSource == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveSaturation((tvVideoSrcType_t)i,pqValue,videoFormat,50);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    for(int i =0 ; i < PQ_MODE_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(pqValue == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveSaturation(videoSource,i,videoFormat,50);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < videoFmtCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", j);
            videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoFormat == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveSaturation(videoSource,pqValue,(tvVideoFormatType_t)i,50);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 12: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 13: Calling tvsettings SaveSaturation and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveSaturation(videoSource, pqValue, videoFormat, 50);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetHue() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 79@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetHue() -  Set the hue with valid value | 00 | tvERROR_NONE | Should Pass |
 * | 03 | call SetHue() -  Reset the hue with another valid value | 50 | tvERROR_NONE | Should Pass |
 * | 04 | call SetHue() -  Reset the hue with another valid value | 100 | tvERROR_NONE | Should Pass |
 * | 05 | call SetHue() -  Reset the hue with the same value as in previous variation | 100 | tvERROR_NONE | Should Pass |
 * | 06 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetHue (void)
{
    gTestID = 79;                                    /* It must be 79 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SetHue with Hue value 0 and expecting the API to return success */
    result = SetHue(0);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetHue with Hue value 50 and expecting the API to return success */
    result = SetHue(50);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings SetHue with Hue value 100 and expecting the API to return success */
    result = SetHue(100);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 05: Calling tvsettings SetHue with Hue value 100 and expecting the API to return success */
    result = SetHue(100);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 06: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetHue() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 80@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetHue() - Set the TV hue even before TvInit() | 30 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetHue() -   Set the TV hue with less than the lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetHue() -   Set the TV hue with max range | 101 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetHue() -   Set the TV hue with max range | 200 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 07 | call SetHue() -  Set the TV hue with valid input after TvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetHue (void)
{
    gTestID = 80;                                    /* It must be 80 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetHue and expecting the API to return tvERROR_INVALID_STATE */
        result = SetHue(30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetHue with Hue value -1 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetHue(-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetHue with Hue value 101 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetHue(101);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SetHue with Hue value 200 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetHue(200);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 07: Calling tvsettings the SetHue and expecting the API to return tvERROR_INVALID_STATE */
        result = SetHue(50);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetHue() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 81@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetHue() -  Retrieve the current Hue with valid arguments and validate with range (1-100) | int * | tvERROR_NONE | Should Pass |
 * | 03 | call GetHue() -  Retrieve the current Hue with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetHue (void)
{
    gTestID = 81;                                    /* It must be 81 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int hue = -1;
    int hueRetry = -1;
    int range_from = 0;
    int range_to = 0;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetHue and expecting the API to return success */
    range_from = UT_KVP_PROFILE_GET_UINT32("tvSettings/Hue/range_from");
    range_to = UT_KVP_PROFILE_GET_UINT32("tvSettings/Hue/range_to");
    result = GetHue(&hue);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_TRUE((hue >= range_from && hue <= range_to));

    /* Step 03: Calling tvsettings GetHue again and expecting the API to return success */
    result = GetHue(&hueRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(hue, hueRetry);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetHue() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 82@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetHue() -  Retrieve current TV Hue even before TvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetHue() -  Retrieve current TV Hue with invalid argument | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetHue() -  Retrieve current TV Hue valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetHue (void)
{
    gTestID = 82;                                    /* It must be 82 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int hue = -1;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetTVBcklight and expecting the API to return tvERROR_INVALID_STATE */
        result = GetHue(&hue);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetHue with invalid input and expecting the API to return tvERROR_INVALID_PARAM*/
    result = GetHue(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings GetHue and expecting the API to return tvERROR_INVALID_STATE */
        result = GetHue(&hue);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveHue() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 83@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SaveHue() - Save the current Color Hue by looping through all the values of sourceId, pqmode, videoFormatType from the test specific config file  |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,int | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveHue (void)
{
    gTestID = 83;                                    /* It must be 83 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SaveHue for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    for (unsigned int i = 0; i < videoSrcCount; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", i);
        videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            for (unsigned int k = 0; k < videoFmtCount; k++)
            {
                snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", k);
                videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
                result = SaveHue(videoSource,pqValue,videoFormat,50);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);
            }
        }
    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveHue() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 84@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SaveHue() -  save current TV Hue even before TvInit() |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,int | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -   Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SaveHue() -  "pq_mode,videoFormatType,value"=valid, "videoSrcType"=invalid max range| VIDEO_SOURCE_MAX, int ,tvVideoFormatType_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SaveHue() -  "pq_mode,videoFormatType,value"=valid, "videoSrcType"=invalid lower range| -2, int ,tvVideoFormatType_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SaveHue() -  "videoSrcType,videoFormatType,value"=valid, "pq_mode"=invalid lower range | tvVideoSrcType_t, -1 ,tvVideoFormatType_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SaveHue() -  "videoSrcType,videoFormatType,value"=valid, "pq_mode"=invalid max range| tvVideoSrcType_t, PQ_MODE_MAX ,tvVideoFormatType_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SaveHue() -  "videoSrcType,pq_mode,value"=valid, "videoFormatType"=invalid max range| tvVideoSrcType_t, int ,VIDEO_FORMAT_MAX ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SaveHue() -  "videoSrcType,pq_mode,value"=valid, "videoFormatType"=invalid lower range| tvVideoSrcType_t, int , -1 ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SaveHue() -  "videoSrcType,pq_mode,videoFormatType"=valid, "value"=invalid max range| tvVideoSrcType_t, int , tvVideoFormatType_t ,101| tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SaveHue() -  "videoSrcType,pq_mode,videoFormatType"=valid, "value"=invalid lower range| tvVideoSrcType_t, int , tvVideoFormatType_t ,-1| tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SaveHue() -  Save current Color Hue with valid source input, pqmode, videoFormatType value but not supported by the platform by looping through the VideoSource, PictureMode, VideoFormat sections of test specific config file| tvVideoSrcType_t, int , tvVideoFormatType_t , 50| tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call TvTerm()  -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 13 | call SaveHue() -  save current TV Hue valid arguments |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,int | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveHue (void)
{
    gTestID = 84;                                    /* It must be 84 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool SupportAvailable = true;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SaveHue and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveHue(videoSource, pqValue, videoFormat, 50);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SaveHue and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveHue(VIDEO_SOURCE_MAX,pqValue,videoFormat,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SaveHue and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveHue((tvVideoSrcType_t)-2,pqValue,videoFormat,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SaveHue and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveHue(videoSource,-1,videoFormat,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SaveHue and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveHue(videoSource,PQ_MODE_MAX,videoFormat,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SaveHue and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveHue(videoSource,pqValue,VIDEO_FORMAT_MAX,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings SaveHue and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveHue(videoSource,pqValue,(tvVideoFormatType_t)-1,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings SaveHue and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveHue(videoSource,pqValue,videoFormat,-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 10: Calling tvsettings SaveHue and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveHue(videoSource,pqValue,videoFormat,101);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 11: Calling tvsettings SaveHue and expecting the API to return tvERROR_INVALID_PARAM */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    for(int i =VIDEO_SOURCE_ALL ; i < VIDEO_SOURCE_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < videoSrcCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", j);
            videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoSource == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveHue((tvVideoSrcType_t)i,pqValue,videoFormat,50);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    for(int i =0 ; i < PQ_MODE_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(pqValue == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveHue(videoSource,i,videoFormat,50);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < videoFmtCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", j);
            videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoFormat == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveHue(videoSource,pqValue,(tvVideoFormatType_t)i,50);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 12: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 13: Calling tvsettings SaveHue and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveHue(videoSource, pqValue, videoFormat, 50);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetColorTemperature() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 85@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetColorTemperature() -  Set the TV ColorTemperature by looping through all the values of ColorTemperatures from the ColorTemperature section of test specific config file | tvColorTemp_t | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetColorTemperature (void)
{
    gTestID = 85;                                    /* It must be 85 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SetColorTemperature and expecting the API to return success */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < colorTempCount; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", i);
        colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
        result = SetColorTemperature(colorTempValue);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetColorTemperature() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 86@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetColorTemperature() - Set the TV ColorTemperature even before TvInit() | tvColorTemp_t | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemperature() -   Set the TV ColorTemperature with less than the lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetColorTemperature() -   Set the TV ColorTemperature with max range | tvColorTemp_MAX | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetColorTemperature() -   Set the TV ColorTemperature with valid value but not supported by the platform by looping through the ColorTemperature section of test specific config file | tvColorTemp_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 07 | call SetColorTemperature() -  Set the TV ColorTemperature with valid input after TvTerm() | tvColorTemp_t | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetColorTemperature (void)
{
    gTestID = 86;                                    /* It must be 86*/
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    uint32_t numberofColortemp = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };
    bool SupportAvailable = true;

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetColorTemperature and expecting the API to return tvERROR_INVALID_STATE */
        result = SetColorTemperature(colorTempValue);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetColorTemperature and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemperature((tvColorTemp_t)-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetColorTemperature and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemperature(tvColorTemp_MAX);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SetColorTemperature and expecting the API to return tvERROR_INVALID_PARAM */
    numberofColortemp = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");

	for(int i =tvColorTemp_STANDARD ; i < tvColorTemp_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberofColortemp; j++)
		{
			snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", j);
			colorTempValue = (tvColorTemp_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
			if(colorTempValue == (tvColorTemp_t)i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SetColorTemperature((tvColorTemp_t)i);
			UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
		}
	}

    /* Step 06: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 07: Calling tvsettings the SetColorTemperature and expecting the API to return tvERROR_INVALID_STATE */
        result = SetColorTemperature(colorTempValue);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetColorTemperature() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 87@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetColorTemperature() -  Retrieve the current ColorTemperature and validate ColorTemperature by looping through the ColorTemperature section of test specific config file values | tvColorTemp_t *  | tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemperature() -  Retrieve the current ColorTemperature with valid argument and validate with above value | tvColorTemp_t * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetColorTemperature (void)
{
    gTestID = 87;                                    /* It must be 87 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    tvColorTemp_t tvColorTemp = tvColorTemp_MAX;
    tvColorTemp_t tvColorTempRetry = tvColorTemp_MAX;
    bool IsColorTempValid = false;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetColorTemperature and expectinging the API to return success */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    result = GetColorTemperature(&tvColorTemp);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    for (unsigned int i = 0; i < (colorTempCount); i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", i);
        colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
        if (colorTempValue == tvColorTemp)
        {
            IsColorTempValid = true;
            break;
        }
    }
    UT_ASSERT_TRUE((IsColorTempValid));

    /* Step 03: Calling tvsettings GetColorTemperature and expectinging the API to return success */
    result = GetColorTemperature(&tvColorTempRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(tvColorTemp, tvColorTempRetry);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetColorTemperature() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 88@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetColorTemperature() -  Retrieve current TV ColorTemperature even before TvInit() | tvColorTemp_t  * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemperature() -  Retrieve current TV ColorTemperature with invalid argument | NULL | tvERROR_INVALID_PARAM |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetColorTemperature() -  Retrieve current TV ColorTemperature valid arguments | tvColorTemp_t  * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetColorTemperature (void)
{
    gTestID = 88;                                    /* It must be 88 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    tvColorTemp_t  tvColorTemp =  tvColorTemp_MAX;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetTVColorTemperature and expecting the API to return tvERROR_INVALID_STATE */
        result = GetColorTemperature(&tvColorTemp);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetTVColorTemperature with invalid input and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemperature(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings GetTVColorTemperature and expecting the API to return tvERROR_INVALID_STATE */
        result = GetColorTemperature(&tvColorTemp);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveColorTemperature() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 89@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SaveColorTemperature() -  Save the current Color Temperature by looping through all the values of sourceId, pqmode, videoFormatType and colortemp from the VideoSource, PictureMode, VideoFormat, ColorTemperature sections of test specific config file | tvVideoSrcType_t , int ,tvVideoFormatType_t ,tvColorTemp_t | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveColorTemperature (void)
{
    gTestID = 89;                                    /* It must be 89 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    uint32_t colorTempCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SaveColorTemperature for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < videoSrcCount; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", i);
        videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            for (unsigned int k = 0; k < videoFmtCount; k++)
            {
                snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", k);
                videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
                for (unsigned int l = 0; l < colorTempCount; l++)
                {
                    snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", l);
                    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
                    result = SaveColorTemperature(videoSource,pqValue,\
                            videoFormat,colorTempValue);
                    UT_ASSERT_EQUAL(result, tvERROR_NONE);
                }
            }
        }
    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);

}

/**
 * @brief Validate SaveColorTemperature() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 90@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SaveColorTemperature() -  Save the current Color Temperature even before TvInit() | tvVideoSrcType_t , int ,tvVideoFormatType_t ,tvColorTemp_t | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SaveColorTemperature() -  "pq_mode,videoFormatType,value"=valid, "videoSrcType"=invalid max range| VIDEO_SOURCE_MAX, int ,tvVideoFormatType_t ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SaveColorTemperature() -  "pq_mode,videoFormatType,value"=valid, "videoSrcType"=invalid lower range| -2 , int ,tvVideoFormatType_t ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SaveColorTemperature() -  "videoSrcType,videoFormatType,value"=valid, "pq_mode"=invalid lower range | tvVideoSrcType_t, -1 ,tvVideoFormatType_t ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SaveColorTemperature() -  "videoSrcType,videoFormatType,value"=valid, "pq_mode"=invalid max range| tvVideoSrcType_t, PQ_MODE_MAX ,tvVideoFormatType_t ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SaveColorTemperature() -  "videoSrcType,pq_mode,value"=valid, "videoFormatType"=invalid max range| tvVideoSrcType_t, int ,VIDEO_FORMAT_MAX ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SaveColorTemperature() -  "videoSrcType,pq_mode,value"=valid, "videoFormatType"=invalid lower range| tvVideoSrcType_t, int , -1 ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SaveColorTemperature() -  "videoSrcType,pq_mode,videoFormatType"=valid, "value"=invalid max range| tvVideoSrcType_t, int , tvVideoFormatType_t ,tvColorTemp_MAX| tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SaveColorTemperature() -  "videoSrcType,pq_mode,videoFormatType"=valid, "value"=invalid lower range| tvVideoSrcType_t, int , tvVideoFormatType_t ,-1| tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SaveColorTemperature() -  Save current Color Temperature with valid source input, pqmode, videoFormatType, colortemp value but not supported by the platform by looping through the VideoSource, PictureMode, VideoFormat, ColorTemperature sections of test specific config file| tvVideoSrcType_t, int , tvVideoFormatType_t , tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 13 | call SaveColorTemperature() -  Save the current Color Temperature valid arguments | HDMI, 0, HDR_TYPE_HLG, tvColorTemp_t | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveColorTemperature (void)
{
    gTestID = 90;                                    /* It must be 90 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool SupportAvailable = true;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    uint32_t colorTempCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SaveColorTemperature and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveColorTemperature(videoSource, pqValue,
                                      videoFormat, colorTempValue);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SaveColorTemperature and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveColorTemperature(VIDEO_SOURCE_MAX,pqValue,videoFormat,colorTempValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SaveColorTemperature and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveColorTemperature((tvVideoSrcType_t)-2,pqValue,videoFormat,colorTempValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SaveColorTemperature and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveColorTemperature(videoSource,-1,videoFormat,colorTempValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SaveColorTemperature and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveColorTemperature(videoSource,PQ_MODE_MAX,videoFormat,colorTempValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SaveColorTemperature and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveColorTemperature(videoSource,pqValue,VIDEO_FORMAT_MAX,colorTempValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings SaveColorTemperature and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveColorTemperature(videoSource,pqValue,(tvVideoFormatType_t)-1,colorTempValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings SaveColorTemperature and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveColorTemperature(videoSource,pqValue,videoFormat,(tvColorTemp_t)-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 10: Calling tvsettings SaveColorTemperature and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveColorTemperature(videoSource,pqValue,videoFormat,tvColorTemp_MAX);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 11: Calling tvsettings SaveColorTemperature and expecting the API to return tvERROR_INVALID_PARAM */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    for(int i =VIDEO_SOURCE_ALL ; i < VIDEO_SOURCE_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < videoSrcCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", j);
            videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoSource == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveColorTemperature((tvVideoSrcType_t)i,pqValue,videoFormat,colorTempValue);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    for(int i =0 ; i < PQ_MODE_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(pqValue == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveColorTemperature(videoSource,i,videoFormat,colorTempValue);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < videoFmtCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", j);
            videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoFormat == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveColorTemperature(videoSource,pqValue,(tvVideoFormatType_t)i,colorTempValue);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    for(int i =tvColorTemp_STANDARD ; i < tvColorTemp_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < colorTempCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", j);
            colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(colorTempValue == (tvColorTemp_t)i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveColorTemperature(videoSource,pqValue,videoFormat,(tvColorTemp_t)i );
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 12: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 13: Calling tvsettings SaveColorTemperature and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveColorTemperature(videoSource, pqValue, videoFormat, colorTempValue);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);

}

/**
 * @brief Validate SetAspectRatio() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 91@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetAspectRatio() -  Set the TV Aspect ratio by looping through all the values of aspect ratios from the AspectRatio section of test specific config file | tvDisplayMode_t | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetAspectRatio (void)
{
    gTestID = 91;                                    /* It must be 91 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int aspectRatioCount = 0;
    int aspectRatioValue = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SetAspectRatio and expecting the API to return success */
    aspectRatioCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/AspectRatio/index");
    for (unsigned int i = 0; i < (aspectRatioCount); i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/AspectRatio/index/%d", i);
        aspectRatioValue = UT_KVP_PROFILE_GET_UINT32(keyValue);
        result = SetAspectRatio((tvDisplayMode_t)aspectRatioValue);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetAspectRatio() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 92@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetAspectRatio() - Set the TV AspectRatio even before TvInit() | tvDisplayMode_16x9 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetAspectRatio() -  Set the TV Aspect ratio with invalid input | -1 (tvDisplayMode_t )| tvERROR_INVALID_PARAM |
 * | 04 | call SetAspectRatio() -  Set the TV Aspect ratio with invalid input | tvDisplayMode_MAX | tvERROR_INVALID_PARAM |
 * | 05 | call SetAspectRatio() -   Set the TV Aspect ratio with valid value but not supported by the platform by looping through the AspectRatio section of test specific config file | tvDisplayMode_t  | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 07 | call SetAspectRatio() -  Set the TV AspectRatio with valid input after TvTerm() | tvDisplayMode_16x9 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetAspectRatio (void)
{
    gTestID = 92;                                    /* It must be 92*/
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    int numberofDisplaymode = 0;
    int aspectRatioValue = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    aspectRatioValue = UT_KVP_PROFILE_GET_UINT32("tvSettings/AspectRatio/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetTVAspectRatio and expecting the API to return tvERROR_INVALID_STATE */
        result = SetAspectRatio((tvDisplayMode_t)aspectRatioValue);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetTVAspectRatio and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetAspectRatio((tvDisplayMode_t)-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetTVAspectRatio and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetAspectRatio(tvDisplayMode_MAX);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SetTVAspectRatio and expecting the API to return tvERROR_INVALID_PARAM */
    numberofDisplaymode = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/AspectRatio/index");
    for(int i =0 ; i < numberofDisplaymode; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/AspectRatio/index/%d", i);
        aspectRatioValue = UT_KVP_PROFILE_GET_UINT32(keyValue);
        result = SetAspectRatio( tvDisplayMode_MAX | (tvDisplayMode_t) (aspectRatioValue));
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
    }

    /* Step 06: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    aspectRatioValue = UT_KVP_PROFILE_GET_UINT32("tvSettings/AspectRatio/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 07: Calling tvsettings the SetTVColorTemperature and expecting the API to return tvERROR_INVALID_STATE */
        result = SetAspectRatio((tvDisplayMode_t)aspectRatioValue);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetAspectRatio() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 93@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetAspectRatio() -  Retrieve the current AspectRatio and validate AspectRatio by looping through the AspectRatio section of test specific config file values | tvDisplayMode_t *  | tvERROR_NONE | Should Pass |
 * | 03 | call GetAspectRatio() -  Retrieve the current AspectRatio with valid argument and validate with above value | tvDisplayMode_t * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetAspectRatio (void)
{
    gTestID = 93;                                    /* It must be 93 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    tvDisplayMode_t tvDisplayMode = tvDisplayMode_MAX;
    tvDisplayMode_t tvDisplayModeRetry = tvDisplayMode_MAX;
    bool isDisplayModeValid = false;
    int aspectRatioCount = 0;
    int aspectRatioValue = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetAspectRatio and expectinging the API to return success */
    result = GetAspectRatio(&tvDisplayMode);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    aspectRatioCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/AspectRatio/index");
    for (unsigned int i = 0; i < (aspectRatioCount); i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/AspectRatio/index/%d", i);
        aspectRatioValue = UT_KVP_PROFILE_GET_UINT32(keyValue);
        if (aspectRatioValue == tvDisplayMode)
        {
            isDisplayModeValid = true;
            break;
        }
    }
    UT_ASSERT_TRUE((isDisplayModeValid));

    /* Step 03: Calling tvsettings GetAspectRatio and expectinging the API to return success */
    result = GetAspectRatio(&tvDisplayModeRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(tvDisplayMode,tvDisplayModeRetry);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
}

/**
 * @brief Validate GetAspectRatio() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 94@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetAspectRatio() -  Retrieve current TV AspectRatio even before TvInit() | tvDisplayMode_t * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetAspectRatio() -  Retrieve current TV AspectRatio with invalid argument | NULL | tvERROR_INVALID_PARAM |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetAspectRatio() -  Retrieve current TV AspectRatio valid arguments | tvDisplayMode_t * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetAspectRatio (void)
{
    gTestID = 94;                                    /* It must be 94 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvDisplayMode_t tvDisplayMode = tvDisplayMode_MAX;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetTVAspectRatio and expecting the API to return tvERROR_INVALID_STATE */
        result = GetAspectRatio(&tvDisplayMode);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetTVAspectRatio with invalid input and expecting the API to return tvERROR_INVALID_PARAM*/
    result = GetAspectRatio(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings GetTVAspectRatio and expecting the API to return tvERROR_INVALID_STATE */
        result = GetAspectRatio(&tvDisplayMode);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveAspectRatio() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 95@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SaveAspectRatio() -  Save the current Aspect Ratio by looping through all the values of sourcetype, pqmode and video format type from the VideoSource, PictureMode, VideoFormat, ColorTemperature sections of test specific config file | tvVideoSrcType_t , int ,tvVideoFormatType_t ,tvDisplayMode_t | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveAspectRatio (void)
{
    gTestID = 95;                                    /* It must be 95 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    int aspectRatioValue = 0;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    int aspectRatioCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SaveAspectRatio for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    aspectRatioCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/AspectRatio/index");
    for (unsigned int i = 0; i < videoSrcCount; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", i);
        videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            for (unsigned int k = 0; k < videoFmtCount; k++)
            {
                snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", k);
                videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
                for (unsigned int l = 0; l < aspectRatioCount; l++)
                {
                    snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/AspectRatio/index/%d", l);
                    aspectRatioValue = UT_KVP_PROFILE_GET_UINT32(keyValue);
                    result = SaveAspectRatio(videoSource,pqValue,\
                            videoFormat,(tvDisplayMode_t)aspectRatioValue);
                    UT_ASSERT_EQUAL(result, tvERROR_NONE);
                }
            }
        }
    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveAspectRatio() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 96@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SaveAspectRatio() -  Save the current Aspect Ratio even before TvInit() | tvVideoSrcType_t , int ,tvVideoFormatType_t ,tvDisplayMode_t | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SaveAspectRatio() -  "pq_mode,videoFormatType,value"=valid, "videoSrcType"=invalid max range| VIDEO_SOURCE_MAX, int ,tvVideoFormatType_t ,tvDisplayMode_t| tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SaveAspectRatio() -  "pq_mode,videoFormatType,value"=valid, "videoSrcType"=invalid lower range| -2 , int ,tvVideoFormatType_t ,tvDisplayMode_t| tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SaveAspectRatio() -  "videoSrcType,videoFormatType,value"=valid, "pq_mode"=invalid lower range | tvVideoSrcType_t, -1 ,tvVideoFormatType_t ,tvDisplayMode_t| tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SaveAspectRatio() -  "videoSrcType,videoFormatType,value"=valid, "pq_mode"=invalid max range| tvVideoSrcType_t, PQ_MODE_MAX ,tvVideoFormatType_t ,tvDisplayMode_t| tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SaveAspectRatio() -  "videoSrcType,pq_mode,value"=valid, "videoFormatType"=invalid max range| tvVideoSrcType_t, int ,VIDEO_FORMAT_MAX ,tvDisplayMode_t| tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SaveAspectRatio() -  "videoSrcType,pq_mode,value"=valid, "videoFormatType"=invalid lower range| tvVideoSrcType_t, int , -1 ,tvDisplayMode_t| tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SaveAspectRatio() -  "videoSrcType,pq_mode,videoFormatType"=valid, "value"=invalid max range| tvVideoSrcType_t, int , tvVideoFormatType_t ,tvDisplayMode_MAX| tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SaveAspectRatio() -  "videoSrcType,pq_mode,videoFormatType"=valid, "value"=invalid lower range| tvVideoSrcType_t, int , tvVideoFormatType_t ,-1| tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SaveAspectRatio() -  Save current Aspect Ratio with valid source input, pqmode, videoFormatType, aspectratio value but not supported by the platform by looping through the VideoSource, PictureMode, VideoFormat, ColorTemperature sections of test specific config file| tvVideoSrcType_t, int , tvVideoFormatType_t , tvDisplayMode_t| tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 13 | call SaveAspectRatio() -  Save the current Aspect Ratio valid arguments | tvVideoSrcType_t , int ,tvVideoFormatType_t ,tvDisplayMode_t | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveAspectRatio (void)
{
    gTestID = 96;                                    /* It must be 96 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool SupportAvailable = true;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    int aspectRatioValue = 0;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    int aspectRatioCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    aspectRatioValue = UT_KVP_PROFILE_GET_UINT32("tvSettings/AspectRatio/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SaveAspectRatio and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveAspectRatio(videoSource, pqValue,
                                 videoFormat, (tvDisplayMode_t)aspectRatioValue);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SaveAspectRatio and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveAspectRatio(VIDEO_SOURCE_MAX,pqValue,videoFormat,(tvDisplayMode_t)aspectRatioValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SaveAspectRatio and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveAspectRatio((tvVideoSrcType_t)-2,pqValue,videoFormat,(tvDisplayMode_t)aspectRatioValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SaveAspectRatio and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveAspectRatio(videoSource,-1,videoFormat,(tvDisplayMode_t)aspectRatioValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SaveAspectRatio and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveAspectRatio(videoSource,PQ_MODE_MAX,videoFormat,(tvDisplayMode_t)aspectRatioValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SaveAspectRatio and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveAspectRatio(videoSource,pqValue,VIDEO_FORMAT_MAX,(tvDisplayMode_t)aspectRatioValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings SaveAspectRatio and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveAspectRatio(videoSource,pqValue,(tvVideoFormatType_t)-1,(tvDisplayMode_t)aspectRatioValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings SaveAspectRatio and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveAspectRatio(videoSource,pqValue,videoFormat,(tvDisplayMode_t)-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 10: Calling tvsettings SaveAspectRatio and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveAspectRatio(videoSource,pqValue,videoFormat,tvDisplayMode_MAX);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 11: Calling tvsettings SaveAspectRatio and expecting the API to return tvERROR_INVALID_PARAM */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    for(int i =VIDEO_SOURCE_ALL ; i < VIDEO_SOURCE_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < videoSrcCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", j);
            videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoSource == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveAspectRatio((tvVideoSrcType_t)i,pqValue,videoFormat,(tvDisplayMode_t)aspectRatioValue);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    for(int i =0 ; i < PQ_MODE_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(pqValue == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveAspectRatio(videoSource,i,videoFormat,(tvDisplayMode_t)aspectRatioValue);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < videoFmtCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", j);
            videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoFormat == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveAspectRatio(videoSource,pqValue,(tvVideoFormatType_t)i,(tvDisplayMode_t)aspectRatioValue);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    aspectRatioCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/AspectRatio/index");
    for(int i =tvDisplayMode_4x3 ; i < tvDisplayMode_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < aspectRatioCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/AspectRatio/index/%d", j);
            aspectRatioValue = UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(aspectRatioValue == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveAspectRatio(videoSource,pqValue,videoFormat,(tvDisplayMode_t)i);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 12: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    aspectRatioValue = UT_KVP_PROFILE_GET_UINT32("tvSettings/AspectRatio/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 13: Calling tvsettings SaveAspectRatio and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveAspectRatio(videoSource, pqValue, videoFormat, (tvDisplayMode_t)aspectRatioValue);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);

}

/**
 * @brief Validate SetLowLatencyState() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 97@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetLowLatencyState() -  Set the LowLatency State with valid value | 0 | tvERROR_NONE | Should Pass |
 * | 03 | call SetLowLatencyState() -  Reset the LowLatency State with another valid value | 1 | tvERROR_NONE | Should Pass |
 * | 04 | call SetLowLatencyState() -  Reset the LowLatency State with another valid value | 0 | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetLowLatencyState (void)
{
    gTestID = 97;                                    /* It must be 97 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SetLowLatencyState with value 0 and expecting the API to return success */
    result = SetLowLatencyState(0);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetLowLatencyState with value 1 and expecting the API to return success */
    result = SetLowLatencyState(1);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings SetLowLatencyState with value 0 and expecting the API to return success */
    result = SetLowLatencyState(0);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetLowLatencyState() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 98@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetLowLatencyState() - Set the TV LowLatency State even before TvInit() | 0 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetLowLatencyState() -   Set the TV LowLatency State with invalid input with less than lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetLowLatencyState() -   Set the TV LowLatency State with invalid input with max range | 2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call SetLowLatencyState() -  Set the TV LowLatency State with valid input after TvTerm() | 1 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetLowLatencyState (void)
{
    gTestID = 98;                                    /* It must be 98 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetLowLatencyState and expecting the API to return tvERROR_INVALID_STATE */
        result = SetLowLatencyState(0);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetLowLatencyState with value -1 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetLowLatencyState(-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetLowLatencyState with value 101 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetLowLatencyState(2);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 06: Calling tvsettings the SetLowLatencyState and expecting the API to return tvERROR_INVALID_STATE */
        result = SetLowLatencyState(1);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetLowLatencyState() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 99@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetLowLatencyState() -  Retrieve the current LowLatency State with valid arguments and validate with range (0-1) | int * | tvERROR_NONE | Should Pass |
 * | 03 | call GetLowLatencyState() -  Retrieve the current LowLatency State with valid argument and validate with above value | int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetLowLatencyState (void)
{
    gTestID = 99;                                    /* It must be 99 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    int lowLatencyState = 0;
    int latencyStateRetry = 0;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetLowLatencyState and expectinging the API to return success */
    result = GetLowLatencyState(&lowLatencyState);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_TRUE( (lowLatencyState == 1 || lowLatencyState == 0));

    /* Step 03: Calling tvsettings GetLowLatencyState and expectinging the API to return success */
    result = GetLowLatencyState(&latencyStateRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(lowLatencyState,latencyStateRetry);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetLowLatencyState() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 100@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetLowLatencyState() -  Retrieve current TV LowLatency State even before TvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetLowLatencyState() -   Retrieve current TV LowLatency State with invalid argument | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetLowLatencyState() -  Retrieve current TV LowLatency State valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetLowLatencyState (void)
{
    gTestID = 100;                                    /* It must be 100 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int lowLatencyState = -1;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetLowLatencyState and expecting the API to return tvERROR_INVALID_STATE */
        result = GetLowLatencyState(&lowLatencyState);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetLowLatencyState with invalid input and expecting the API to return tvERROR_INVALID_PARAM*/
    result = GetLowLatencyState(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings GetLowLatencyState and expecting the API to return tvERROR_INVALID_STATE */
        result = GetLowLatencyState(&lowLatencyState);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveLowLatencyState() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 101@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SaveLowLatencyState() -  Save the current LowLatency State by looping through all the values of sourceId, pqmode, videoFormatType, value from the VideoSource, PictureMode, VideoFormat sections of test specific config file  |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,int | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveLowLatencyState (void)
{
    gTestID = 101;                                    /* It must be 101 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SaveLowLatencyState for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    for (unsigned int i = 0; i < videoSrcCount; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", i);
        videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            for (unsigned int k = 0; k < videoFmtCount; k++)
            {
                snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", k);
                videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
                result = SaveLowLatencyState(videoSource,pqValue,videoFormat,0);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);
            }
        }
    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveLowLatencyState() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 102@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SaveLowLatencyState() -  save current TV LowLatency even before TvInit() | tvVideoSrcType_t, int , tvVideoFormatType_t ,int | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SaveLowLatencyState() -  "pq_mode,videoFormatType,value"=valid, "videoSrcType"=invalid max range| VIDEO_SOURCE_MAX, int ,tvVideoFormatType_t ,int | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SaveLowLatencyState() -  "pq_mode,videoFormatType,value"=valid, "videoSrcType"=invalid lower range| -2 , int ,tvVideoFormatType_t ,int | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SaveLowLatencyState() -  "videoSrcType,videoFormatType,value"=valid, "pq_mode"=invalid lower range| tvVideoSrcType_t, -1 ,tvVideoFormatType_t ,int | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SaveLowLatencyState() -  "videoSrcType,videoFormatType,value"=valid, "pq_mode"=invalid max range | tvVideoSrcType_t, PQ_MODE_MAX ,tvVideoFormatType_t ,int | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SaveLowLatencyState() -  "videoSrcType,pq_mode,value"=valid, "videoFormatType"=invalid max range| tvVideoSrcType_t, int ,VIDEO_FORMAT_MAX ,int | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SaveLowLatencyState() -  "videoSrcType,pq_mode,value"=valid, "videoFormatType"=invalid lower range| tvVideoSrcType_t, int , -1 ,int | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SaveLowLatencyState() -  "videoSrcType,pq_mode,videoFormatType"=valid, "value"=invalid max range| tvVideoSrcType_t, int , tvVideoFormatType_t , 2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SaveLowLatencyState() -  "videoSrcType,pq_mode,videoFormatType"=valid, "value"=invalid lower range| tvVideoSrcType_t, int , tvVideoFormatType_t ,-1| tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SaveLowLatencyState() -  Save current LowLatency State with valid value of source input, pqmode, videoFormatType but not supported by the platform by looping through the VideoSource, PictureMode, VideoFormat sections of test specific config file| tvVideoSrcType_t, int , tvVideoFormatType_t ,int | tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 13 | call SaveLowLatencyState() -  save current TV Contrast valid arguments | tvVideoSrcType_t, int , tvVideoFormatType_t ,int | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveLowLatencyState (void)
{
    gTestID = 102;                                    /* It must be 102 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool SupportAvailable = true;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SaveLowLatencyState and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveLowLatencyState(videoSource, pqValue, videoFormat, 0);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SaveLowLatencyState and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveLowLatencyState(VIDEO_SOURCE_MAX,pqValue,videoFormat,0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SaveLowLatencyState and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveLowLatencyState((tvVideoSrcType_t)-2,pqValue,videoFormat,0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SaveLowLatencyState and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveLowLatencyState(videoSource,-1,videoFormat,0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SaveLowLatencyState and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveLowLatencyState(videoSource,PQ_MODE_MAX,videoFormat,50);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SaveLowLatencyState and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveLowLatencyState(videoSource,pqValue,VIDEO_FORMAT_MAX,0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings SaveLowLatencyState and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveLowLatencyState(videoSource,pqValue,(tvVideoFormatType_t)-1,0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings SaveLowLatencyState and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveLowLatencyState(videoSource,pqValue,videoFormat,-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 10: Calling tvsettings SaveLowLatencyState and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveLowLatencyState(videoSource,pqValue,videoFormat,2);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 11: Calling tvsettings SaveLowLatencyState and expecting the API to return tvERROR_INVALID_PARAM */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    for(int i =VIDEO_SOURCE_ALL ; i < VIDEO_SOURCE_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < videoSrcCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", j);
            videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoSource == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveLowLatencyState((tvVideoSrcType_t)i,pqValue,videoFormat,0);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    for(int i =0 ; i < PQ_MODE_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(pqValue == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveLowLatencyState(videoSource,i,videoFormat,0);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < videoFmtCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", j);
            videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoFormat == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveLowLatencyState(videoSource,pqValue,(tvVideoFormatType_t)i,0);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 12: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 13: Calling tvsettings SaveLowLatencyState and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveLowLatencyState(videoSource, pqValue, videoFormat, 50);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetDynamicContrast() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 103@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetDynamicContrast() -  Set the Dynamic Contrast with valid value | "enabled" | tvERROR_NONE | Should Pass |
 * | 03 | call SetDynamicContrast() -  Reset the Dynamic Contrast with another valid value | "disabled"| tvERROR_NONE | Should Pass |
 * | 04 | call SetDynamicContrast() -  Reset the Dynamic Contrast with another valid value | "enabled" | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetDynamicContrast (void)
{
    gTestID = 103;                                    /* It must be 103 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SetDynamicContrast with valid value "enabled" and expecting the API to return success */
    result = SetDynamicContrast("enabled");
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetDynamicContrast with valid value "disabled" and expecting the API to return success */
    result = SetDynamicContrast("disabled");
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings SetDynamicContrast with valid value "enabled" and expecting the API to return success */
    result = SetDynamicContrast("enabled");
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetDynamicContrast() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 104@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetDynamicContrast() - Set the TV Dynamic Contrast even before TvInit() | true | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetDynamicContrast() -  Set the TV Dynamic Contrast with invalid input | "ENABLE" | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call SetDynamicContrast() -  Set the TV Dynamic Contrast with valid input after TvTerm() | false | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetDynamicContrast (void)
{
    gTestID = 104;                                    /* It must be 104 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetDynamicContrast with valid value "enabled" and expecting the API to return success */
        result = SetDynamicContrast("enabled");
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetDynamicContrast with valid value "ENABLE" and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetDynamicContrast("ENABLE");
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings SetDynamicContrast with valid value "enabled" and expecting the API to return tvERROR_INVALID_STATE */
        result = SetDynamicContrast("enabled");
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetDynamicContrast() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 105@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetDynamicContrast() -  Retrieve the current Dynamic Contrast with valid arguments | char * | tvERROR_NONE | Should Pass |
 * | 03 | call GetDynamicContrast() -  Retrieve the current Dynamic Contrast with valid arguments and validate with above value | char * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetDynamicContrast (void)
{
    gTestID = 105;                                    /* It must be 105 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    char dynamicContrast[OFFSET_MAX]={'\0'};
    char dynamicContrastRetry[OFFSET_MAX]={'\0'};

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetDynamicContrast and expectinging the API to return success */
    result = GetDynamicContrast(dynamicContrast);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_TRUE((!strcmp(dynamicContrast, "enabled") || !strcmp(dynamicContrast, "disabled")));

    /* Step 03: Calling tvsettings GetDynamicContrast and expectinging the API to return success */
    result = GetDynamicContrast(dynamicContrastRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_STRING_EQUAL(dynamicContrastRetry, dynamicContrast);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetDynamicContrast() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 106@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetDynamicContrast() -  Retrieve current TV Dynamic Contrast even before TvInit() | char * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetDynamicContrast() -  Retrieve current TV Dynamic contrast with invalid argument | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetDynamicContrast() -  Retrieve current TV Dynamic Contrast valid arguments | char * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetDynamicContrast (void)
{
    gTestID = 106;                                    /* It must be 106 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    char dynamicContrast[OFFSET_MAX]={'\0'};

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetDynamicContrast and expectinging the API to return tvERROR_INVALID_STATE */
        result = GetDynamicContrast(dynamicContrast);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetDynamicContrast and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetDynamicContrast(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings GetDynamicContrast and expectinging the API to return tvERROR_INVALID_STATE */
        result = GetDynamicContrast(dynamicContrast);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);

}

/**
 * @brief Validate SetDynamicGamma() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 107@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetDynamicGamma() -  Set the Dynamic Gamma with valid value | 1.80 | tvERROR_NONE | Should Pass |
 * | 03 | call SetDynamicGamma() -  Reset the Dynamic Gamma with another valid value | 2.20 | tvERROR_NONE | Should Pass |
 * | 04 | call SetDynamicGamma() -  Reset the Dynamic Gamma with another valid value | 2.60 | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetDynamicGamma (void)
{
    gTestID = 107;                                    /* It must be 107 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SetDynamicGamma with valid value "1.80" and expecting the API to return success */
    result = SetDynamicGamma(1.80);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetDynamicGamma with valid value "2.20" and expecting the API to return success */
    result = SetDynamicGamma(2.20);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings SetDynamicGamma with valid value "2.60" and expecting the API to return success */
    result = SetDynamicGamma(2.60);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);

}

/**
 * @brief Validate SetDynamicGamma() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 108@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetDynamicGamma() - Set the TV Dynamic Gamma even before TvInit() | 2.20 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetDynamicGamma() -  Set the TV Dynamic Gamma with less than the lower range | 1.79 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetDynamicGamma() -  Set the TV Dynamic Gamma with max range | 2.61 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call SetDynamicGamma() -  Set the TV Dynamic Gamma with valid input after TvTerm() | 2.20 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetDynamicGamma (void)
{
    gTestID = 108;                                    /* It must be 108 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetDynamicGamma with valid value "2.20" and expecting the API to return tvERROR_INVALID_STATE */
        result = SetDynamicGamma(2.20);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetDynamicGamma with valid value "1.79" and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetDynamicGamma(1.79);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetDynamicGamma with valid value "2.61" and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetDynamicGamma(2.61);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 06: Calling tvsettings SetDynamicGamma with valid value "2.20" and expecting the API to return tvERROR_INVALID_STATE */
        result = SetDynamicGamma(2.20);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetDynamicGamma() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 109@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetDynamicGamma() -  Retrieve the current Dynamic Gamma with valid arguments and validate with range (1.80 till 2.60) | double * | tvERROR_NONE | Should Pass |
 * | 03 | call GetDynamicGamma() -  Retrieve the current Dynamic Gamma with valid arguments and validate with above value | double * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetDynamicGamma (void)
{
    gTestID = 109;                                    /* It must be 109 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    double dynamicGamma=0.0;
    double dynamicGammaRetry=0.0;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetDynamicGamma and expectinging the API to return success */
    result = GetDynamicGamma(&dynamicGamma);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_TRUE( (1.80 <= dynamicGamma && dynamicGamma <= 2.60));

    /* Step 03: Calling tvsettings GetDynamicGamma and expectinging the API to return success */
    result = GetDynamicGamma(&dynamicGammaRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(dynamicGammaRetry, dynamicGamma);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetDynamicGamma() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 110@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetDynamicGamma() -  Retrieve current TV Dynamic Gamma even before TvInit() | double * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetDynamicGamma() -  Retrieve current TV Dynamic Gamma with invalid argument | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetDynamicGamma() -  Retrieve current TV Dynamic Gamma valid arguments | double * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetDynamicGamma (void)
{
    gTestID = 110;                                    /* It must be 110 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    double dynamicGamma=0.0;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetDynamicGamma and expectinging the API to return tvERROR_INVALID_STATE */
        result = GetDynamicGamma(&dynamicGamma);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetDynamicGamma and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetDynamicGamma(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings GetDynamicGamma and expectinging the API to return tvERROR_INVALID_STATE */
        result = GetDynamicGamma(&dynamicGamma);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVSupportedDolbyVisionModes() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 111@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetTVSupportedDolbyVisionModes() -  Retrieve the current Supported DolbyVision Modes and validate Supported DolbyVision modes by looping through the DolbyVisionMode section of test specific config file | tvDolbyMode_t *[], unsigned short * | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVSupportedDolbyVisionModes() -  Retrieve the current Supported VideoFormats with valid argument and validate with above value | tvDolbyMode_t *[], unsigned short * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetTVSupportedDolbyVisionModes (void)
{
    gTestID = 111;                                    /* It must be 111 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    tvDolbyMode_t *tvDolbyModes[1]={0};
    tvDolbyMode_t *tvDolbyModesRetry[1]={0};
    bool IsDolbyModeValid = true;
    unsigned short sizeReceived = 0;
    unsigned short sizeReceivedRetry = 0;
    uint32_t dolbyVisonModeCount = 0;
    tvDolbyMode_t dolbyVisionModevalue = tvDolbyMode_Dark;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    tvDolbyModes[0] = (tvDolbyMode_t *)malloc(MAX_VIDEO_FORMAT * sizeof(tvDolbyMode_t));
    if (tvDolbyModes[0] != NULL)
    {

        /* Step 02: Calling tvsettings GetTVSupportedDolbyVisionModes and expectinging the API to return success */
        result = GetTVSupportedDolbyVisionModes(tvDolbyModes, &sizeReceived);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);

        dolbyVisonModeCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/DolbyVisionMode/index");
        UT_ASSERT_EQUAL(sizeReceived, (unsigned short)dolbyVisonModeCount);

        for (unsigned int i = 0; i < dolbyVisonModeCount; i++)
        {
            IsDolbyModeValid = false;
            for (unsigned short j = 0; j < sizeReceived; j++)
            {
                snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/DolbyVisionMode/index/%d", i);
                dolbyVisionModevalue = (tvDolbyMode_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
                if (dolbyVisionModevalue == tvDolbyModes[0][j])
                {
                    IsDolbyModeValid = true;
                    break;
                }
            }
            UT_ASSERT_TRUE((IsDolbyModeValid));
        }
        tvDolbyModesRetry[0] = (tvDolbyMode_t *)malloc(MAX_VIDEO_FORMAT * sizeof(tvDolbyMode_t));
        if (tvDolbyModesRetry[0] != NULL)
        {

            /* Step 03: Calling tvsettings GetTVSupportedDolbyVisionModes and expecting the API to return success */
            result = GetTVSupportedDolbyVisionModes(tvDolbyModesRetry, &sizeReceivedRetry);
            UT_ASSERT_EQUAL(result, tvERROR_NONE);
            UT_ASSERT_EQUAL(sizeReceived, sizeReceivedRetry);

            for (unsigned short i = 0; i < sizeReceivedRetry; i++)
            {
                IsDolbyModeValid = false;
                for (unsigned short j = 0; j < sizeReceived; j++)
                {
                    if (tvDolbyModesRetry[0][i] == tvDolbyModes[0][j])
                    {
                        IsDolbyModeValid = true;
                        break;
                    }
                }

                UT_ASSERT_TRUE((IsDolbyModeValid));
            }
        }
        else
        {
            UT_LOG_ERROR("Memory Allocation failed for retry step");
        }
    }
    else
    {
        UT_LOG_ERROR("Memory Allocation failed");
    }
    if ( tvDolbyModes[0] ){
        free ( tvDolbyModes[0] );
    }
    if ( tvDolbyModesRetry[0] ){
        free ( tvDolbyModesRetry[0] );
    }

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVSupportedDolbyVisionModes() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 112@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetTVSupportedDolbyVisionModes() -  Retrieve current TV Supported DolbyVision Modes even before TvInit() | tvDolbyMode_t *[], unsigned short * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVSupportedDolbyVisionModes() -   Retrieve current TV Supported DolbyVision Modes with invalid argument | tvDolbyMode_t *[], NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetTVSupportedDolbyVisionModes() -   Retrieve current TV Supported DolbyVision Modes with invalid argument | NULL, unsigned short * | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call GetTVSupportedDolbyVisionModes() -  Retrieve current TV Supported DolbyVision Modes valid arguments |tvDolbyMode_t *[], unsigned short * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetTVSupportedDolbyVisionModes (void)
{
    gTestID = 112;                                    /* It must be 112 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvDolbyMode_t *tvDolbyModes[1]={0};
    unsigned short size = 0;

    tvDolbyModes[0] = (tvDolbyMode_t *)malloc(MAX_VIDEO_FORMAT *sizeof(tvDolbyMode_t));
    if (tvDolbyModes[0] != NULL)
    {

        if (extendedEnumsSupported == true)
        {
            /* Step 01: Calling tvsettings GetTVSupportedDolbyVisionModes and expecting the API to return tvERROR_INVALID_STATE */
            result = GetTVSupportedDolbyVisionModes(tvDolbyModes, &size);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
        }

        /* Step 02: Calling tvsettings initialization and expecting the API to return success */
        result = TvInit();
        if (result != tvERROR_NONE)
        {
            if (tvDolbyModes[0])
            {
                free(tvDolbyModes[0]);
            }
        }
        UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

        /* Step 03: Calling tvsettings GetTVSupportedDolbyVisionModes and expecting the API to return tvERROR_INVALID_PARAM */
        result = GetTVSupportedDolbyVisionModes(tvDolbyModes, NULL);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

        /* Step 04: Calling tvsettings GetTVSupportedDolbyVisionModes and expecting the API to return tvERROR_INVALID_PARAM */
        result = GetTVSupportedDolbyVisionModes(NULL, &size);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

        /* Step 05: Calling tvsettings termination and expecting the API to return success */
        result = TvTerm();
        if (result != tvERROR_NONE)
        {
            if (tvDolbyModes[0])
            {
                free(tvDolbyModes[0]);
            }
        }
        UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

        if (extendedEnumsSupported == true)
        {
            /* Step 06: Calling tvsettings GetTVSupportedDolbyVisionModes and expecting the API to return tvERROR_INVALID_STATE */
            result = GetTVSupportedDolbyVisionModes(tvDolbyModes, &size);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
        }

        if (tvDolbyModes[0])
        {
            free(tvDolbyModes[0]);
        }
    }
    else
    {
        UT_LOG_ERROR("Memory Allocaiton failed");
    }
    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetTVDolbyVisionMode() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 113@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetTVDolbyVisionMode() -  Set the TV DolbyVision mode by looping through all the values of DolbyVision modes from the DolbyVisionMode section of test specific config file | tvDolbyMode_t | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetTVDolbyVisionMode (void)
{
    gTestID = 113;                                    /* It must be 113 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    uint32_t dolbyVisonModeCount = 0;
    tvDolbyMode_t dolbyVisionModevalue = tvDolbyMode_Dark;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings to Set the SetTVDolbyVisionMode for all the dv_modes and expecting the API to return success */
    dolbyVisonModeCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/DolbyVisionMode/index");
    for (unsigned int i = 0; i < dolbyVisonModeCount; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/DolbyVisionMode/index/%d" , i);
        dolbyVisionModevalue = (tvDolbyMode_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
        result = SetTVDolbyVisionMode(dolbyVisionModevalue);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetTVDolbyVisionMode() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 114@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetTVDolbyVisionMode() - Set the TV DolbyVision Mode even before TvInit() | tvDolbyMode_t | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetTVDolbyVisionMode() -   Set the TV DolbyVision Mode with invalid input | tvMode_Max | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetTVDolbyVisionMode() -   Set the TV DolbyVision Mode with invalid input | -2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call SetTVDolbyVisionMode() -  Set the TV DolbyVision Mode with valid input after TvTerm() | tvDolbyMode_t| tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetTVDolbyVisionMode (void)
{
    gTestID = 114;                                    /* It must be 114 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvDolbyMode_t dolbyVisionModevalue = tvDolbyMode_Dark;

    dolbyVisionModevalue = (tvDolbyMode_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/DolbyVisionMode/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetTVDolbyVisionMode with valid value and expecting the API to return tvERROR_INVALID_STATE */
        result = SetTVDolbyVisionMode(dolbyVisionModevalue);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetTVDolbyVisionMode with valid value and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetTVDolbyVisionMode(tvMode_Max);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetTVDolbyVisionMode with valid value and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetTVDolbyVisionMode((tvDolbyMode_t)-2);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 06: Calling tvsettings SetTVDolbyVisionMode with valid value and expecting the API to return tvERROR_INVALID_STATE */
        result = SetTVDolbyVisionMode(dolbyVisionModevalue);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVDolbyVisionMode() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 115@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetTVDolbyVisionMode() -  Retrieve the current DolbyVision and validate DolbyVision by looping through the DolbyVisionMode section of test specific config file | tvDolbyMode_t * | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call GetTVDolbyVisionMode() -  Retrieve the current DolbyVision with valid argument and validate with above value | tvDolbyMode_t * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetTVDolbyVisionMode (void)
{
    gTestID = 115;                                    /* It must be 115 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    tvDolbyMode_t tvDolbyModes = tvDolbyMode_Invalid;
    tvDolbyMode_t tvDolbyModesRetry = tvDolbyMode_Invalid;
    bool IstvDolbyModesValid = false;
    uint32_t dolbyVisonModeCount = 0;
    tvDolbyMode_t dolbyVisionModevalue = tvDolbyMode_Dark;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetTVDimmingMode and expectinging the API to return success */
    result = GetTVDolbyVisionMode(&tvDolbyModes);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    dolbyVisonModeCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/DolbyVisionMode/index");
    for (unsigned int i = 0; i < (dolbyVisonModeCount); i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/DolbyVisionMode/index/%d" , i);
        dolbyVisionModevalue = (tvDolbyMode_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
        if (dolbyVisionModevalue == tvDolbyModes)
        {
            IstvDolbyModesValid = true;
            break;
        }
    }
    UT_ASSERT_TRUE((IstvDolbyModesValid));

    /* Step 03: Calling tvsettings GetTVDimmingMode and expectinging the API to return success */
    result = GetTVDolbyVisionMode(&tvDolbyModesRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(tvDolbyModesRetry,tvDolbyModes);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVDolbyVisionMode() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 116@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetTVDolbyVisionMode() -  Retrieve current TV DolbyVision Mode even before TvInit() | tvDolbyMode_t * | (tvERROR_INVALID_STATE |  tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVDolbyVisionMode() -  Retrieve current TV DolbyVision mode with invalid argument | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetTVDolbyVisionMode() -  Retrieve current TV DolbyVision Mode valid arguments | tvDolbyMode_t * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetTVDolbyVisionMode (void)
{
    gTestID = 116;                                    /* It must be 116 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvDolbyMode_t tvDolbyModes = tvDolbyMode_Invalid;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_STATE */
        result = GetTVDolbyVisionMode(&tvDolbyModes);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetTVDolbyVisionMode(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings GetTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_STATE */
        result = GetTVDolbyVisionMode(&tvDolbyModes);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveTVDolbyVisionMode() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 117@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SaveTVDolbyVisionMode() -  Save the current DolbyVision Mode by looping through all the values of VideoSource Type, pqmode, videoFormatType, DolbyVision value from the VideoSource, PictureMode, VideoFormat DolbyVisionMode sections of test specific config file | tvVideoSrcType_t , int ,tvVideoFormatType_t ,tvDolbyMode_t | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveTVDolbyVisionMode (void)
{
    gTestID = 117;                                    /* It must be 117 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    uint32_t dolbyVisonModeCount = 0;
    tvDolbyMode_t dolbyVisionModevalue = tvDolbyMode_Dark;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SaveTVDimmingMode for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    dolbyVisonModeCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/DolbyVisionMode/index");
    for (unsigned int i = 0; i < videoSrcCount; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", i);
        videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            for (unsigned int k = 0; k < videoFmtCount; k++)
            {
                snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", k);
                videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
                for (unsigned int l = 0; l < dolbyVisonModeCount; l++)
                {
                    snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/DolbyVisionMode/index/%d" , l);
                    dolbyVisionModevalue = (tvDolbyMode_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
                    result = SaveTVDimmingMode(videoSource,pqValue,\
                            videoFormat,dolbyVisionModevalue);
                    UT_ASSERT_EQUAL(result, tvERROR_NONE);
                }
            }
        }
    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveTVDolbyVisionMode() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 118@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SaveTVDolbyVisionMode() -  save current DolbyVision Mode even before TvInit() | tvVideoSrcType_t, int , tvVideoFormatType_t ,tvDolbyMode_t | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SaveTVDolbyVisionMode() -  "pq_mode,videoFormatType,value"=valid, "videoSrcType"=invalid max range| VIDEO_SOURCE_MAX, int ,tvVideoFormatType_t ,tvDolbyMode_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SaveTVDolbyVisionMode() -  "pq_mode,videoFormatType,value"=valid, "videoSrcType"=invalid lower range| -2 , int ,tvVideoFormatType_t ,tvDolbyMode_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SaveTVDolbyVisionMode() -  "videoSrcType,videoFormatType,value"=valid, "pq_mode"=invalid lower range| tvVideoSrcType_t, -1 ,tvVideoFormatType_t ,tvDolbyMode_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SaveTVDolbyVisionMode() -  "videoSrcType,videoFormatType,value"=valid, "pq_mode"=invalid max range| tvVideoSrcType_t, PQ_MODE_MAX ,tvVideoFormatType_t ,tvDolbyMode_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SaveTVDolbyVisionMode() -  "videoSrcType,pq_mode,value"=valid, "videoFormatType"=invalid max range| tvVideoSrcType_t, int ,VIDEO_FORMAT_MAX ,tvDolbyMode_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SaveTVDolbyVisionMode() -  "videoSrcType,pq_mode,value"=valid, "videoFormatType"=invalid lower range| tvVideoSrcType_t, int , -1 ,tvDolbyMode_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SaveTVDolbyVisionMode() -  "videoSrcType,pq_mode,videoFormatType"=valid, "value"=invalid max range| tvVideoSrcType_t, int , tvVideoFormatType_t , tvMode_Max | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SaveTVDolbyVisionMode() -  "videoSrcType,pq_mode,videoFormatType"=valid, "value"=invalid lower range| tvVideoSrcType_t, int , tvVideoFormatType_t ,-2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SaveTVDolbyVisionMode() -  Save current DolbyVision Mode with valid value of source input, pqmode, videoFormatType but not supported by the platform by looping through the VideoSource, PictureMode, VideoFormat DolbyVisionMode sections of test specific config file| tvVideoSrcType_t, int , tvVideoFormatType_t ,int | tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 13 | call SaveTVDolbyVisionMode() -  save current DolbyVision Mode valid arguments | tvVideoSrcType_t, int , tvVideoFormatType_t ,tvDolbyMode_t | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveTVDolbyVisionMode (void)
{
    gTestID = 118;                                    /* It must be 118 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool SupportAvailable = true;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    uint32_t dolbyVisonModeCount = 0;
    tvDolbyMode_t dolbyVisionModevalue = tvDolbyMode_Dark;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    dolbyVisionModevalue = (tvDolbyMode_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/DolbyVisionMode/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SaveTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveTVDolbyVisionMode(videoSource, pqValue,
                                       videoFormat, dolbyVisionModevalue);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SaveTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveTVDolbyVisionMode(VIDEO_SOURCE_MAX,pqValue,videoFormat,dolbyVisionModevalue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SaveTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveTVDolbyVisionMode((tvVideoSrcType_t)-2,pqValue,videoFormat,dolbyVisionModevalue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SaveTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveTVDolbyVisionMode(videoSource,-1,videoFormat,dolbyVisionModevalue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SaveTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveTVDolbyVisionMode(videoSource,PQ_MODE_MAX,videoFormat,dolbyVisionModevalue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SaveTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveTVDolbyVisionMode(videoSource,pqValue,VIDEO_FORMAT_MAX,dolbyVisionModevalue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings SaveTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveTVDolbyVisionMode(videoSource,pqValue,(tvVideoFormatType_t)-1,dolbyVisionModevalue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings SaveTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveTVDolbyVisionMode(videoSource,pqValue,videoFormat,(tvDolbyMode_t)-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 10: Calling tvsettings SaveTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveTVDolbyVisionMode(videoSource,pqValue,videoFormat, (tvDolbyMode_t)tvMode_Max);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 11: Calling tvsettings SaveTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_PARAM */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    for( int i = VIDEO_SOURCE_ALL  ; i < VIDEO_SOURCE_MAX ; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < videoSrcCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", j);
            videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoSource == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){

            result = SaveTVDolbyVisionMode((tvVideoSrcType_t)i,pqValue,videoFormat,dolbyVisionModevalue);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 12: Calling tvsettings SaveTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_PARAM */
    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    for(int i =0 ; i < PQ_MODE_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(pqValue == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){

            result = SaveTVDolbyVisionMode(videoSource,i,videoFormat,dolbyVisionModevalue);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }

    }

    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < videoFmtCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", j);
            videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoFormat == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){

            result = SaveTVDolbyVisionMode(videoSource,pqValue,(tvVideoFormatType_t) i,dolbyVisionModevalue);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    dolbyVisonModeCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/DolbyVisionMode/index");
    for(int i =tvDimmingMode_Fixed ; i < tvMode_Max ; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < dolbyVisonModeCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/DolbyVisionMode/index/%d" , j);
            dolbyVisionModevalue = (tvDolbyMode_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(dolbyVisionModevalue == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){

            result = SaveTVDolbyVisionMode(videoSource,pqValue,videoFormat,(tvDolbyMode_t) i);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 12: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    dolbyVisionModevalue = (tvDolbyMode_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/DolbyVisionMode/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 13: Calling tvsettings SaveTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveTVDolbyVisionMode(videoSource, pqValue, videoFormat, dolbyVisionModevalue);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVSupportedPictureModes() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 119@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetTVSupportedPictureModes() -  Retrieve the current TV Supported PictureModes and validate TV Supported PictureModes by looping through the PictureMode section of test specific config file | pic_modes_t *, unsigned short * | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVSupportedPictureModes() -  Retrieve the current TV Supported PictureModes with valid argument and validate with above value | pic_modes_t *, unsigned short * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetTVSupportedPictureModes (void)
{
    gTestID = 119;                                    /* It must be 119 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    pic_modes_t tvPicModes[PIC_MODES_SUPPORTED_MAX];
    pic_modes_t tvPicModesRetry[PIC_MODES_SUPPORTED_MAX];
    bool IsPictureModeValid = true;
    unsigned short sizeReceived = 0;
    unsigned short sizeReceivedRetry = 0;
    uint32_t pqCount = 0;
    int pqValue = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetTVSupportedPictureModes and expectinging the API to return success */
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");
    result = GetTVSupportedPictureModes(&tvPicModes, &sizeReceived);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(sizeReceived, (unsigned short)pqCount);


    for (unsigned int i = 0; i < pqCount; i++)
    {
        IsPictureModeValid = false;
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", i);
        pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
        for(unsigned short j = 0; j < sizeReceived; j++)
        {
            if (pqValue == (int)tvPicModes[j].value)
            {
                IsPictureModeValid = true;
                break;
            }
        }
        UT_ASSERT_TRUE((IsPictureModeValid));
    }

    /* Step 03: Calling tvsettings GetTVSupportedPictureModes and expectinging the API to return success */
    result = GetTVSupportedPictureModes(&tvPicModesRetry, &sizeReceivedRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(sizeReceived, sizeReceivedRetry);
    for (unsigned short i = 0; i < sizeReceivedRetry; i++)
    {
        IsPictureModeValid = false;
        for(unsigned short j = 0; j < sizeReceived; j++)
        {
            if (tvPicModesRetry[i].value == tvPicModes[j].value)
            {
                IsPictureModeValid = true;
                break;
            }
        }
        UT_ASSERT_TRUE((IsPictureModeValid));
    }

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVSupportedPictureModes() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 120@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetTVSupportedPictureModes() -  Retrieve current TV Supported PictureModes even before TvInit() | pic_modes_t *, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVSupportedPictureModes() -  Retrieve supported TV PictureMode with invalid argument | NULL, unsigned short * | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetTVSupportedPictureModes() -  Retrieve supported TV PictureMode with invalid argument |  pic_modes_t *, NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call GetTVSupportedPictureModes() -  Retrieve current TV Supported PictureModes valid arguments | pic_modes_t *, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetTVSupportedPictureModes (void)
{
    gTestID = 120;                                    /* It must be 120 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    pic_modes_t *pic_modes=NULL;
    unsigned short size = 0;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetTVSupportedPictureModes and expecting the API to return tvERROR_INVALID_STATE */
        result = GetTVSupportedPictureModes(&pic_modes, &size);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetTVSupportedPictureModes and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetTVSupportedPictureModes(&pic_modes, NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings GetTVSupportedPictureModes and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetTVSupportedPictureModes(NULL,&size);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 06: Calling tvsettings GetTVSupportedPictureModes and expecting the API to return tvERROR_INVALID_STATE */
        result = GetTVSupportedPictureModes(&pic_modes, &size);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVPictureMode() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 121@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetTVPictureMode() -  Retrieve the current TVPictureMode and validate TVPictureMode by looping through the PictureMode section of test specific config file values | char *  | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVPictureMode() -  Retrieve the current TVPictureMode with valid argument and validate with above value | char * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 *
 */
void test_l1_tvSettings_positive_GetTVPictureMode (void)
{
    gTestID = 121;                                    /* It must be 121 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    char pictureMode[PIC_MODE_NAME_MAX]={'\0'};
    char pictureModeRetry[PIC_MODE_NAME_MAX]={'\0'};
    bool IsPicturModeValid = false;
    uint32_t pqCount = 0;
    char pqMode[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetTVPictureMode and expectinging the API to return success */
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/range");
    result = GetTVPictureMode(pictureMode);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    for (unsigned int i = 0; i < (pqCount); i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/range/%d", i);
        UT_KVP_PROFILE_GET_STRING(keyValue,pqMode);
        if (!strcmp(pqMode, pictureMode))
        {
            IsPicturModeValid = true;
            break;
        }
    }
    UT_ASSERT_TRUE((IsPicturModeValid));

    /* Step 03: Calling tvsettings GetTVPictureMode and expectinging the API to return success */
    result = GetTVPictureMode(pictureModeRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_STRING_EQUAL(pictureModeRetry, pictureMode);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVPictureMode() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 122@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetTVPictureMode() - Retrieve current TV PictureMode even before TvInit() | char * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVPictureMode() -  Retrieve current TV PictureMode with invalid argument | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetTVPictureMode() -  Retrieve current TV PictureMode with valid input after TvTerm() | char * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetTVPictureMode (void)
{
    gTestID = 122;                                    /* It must be 122 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    char pictureMode[PIC_MODE_NAME_MAX]={'\0'};

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetTVPictureMode and expecting the API to return tvERROR_INVALID_STATE */
        result = GetTVPictureMode(pictureMode);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetTVPictureMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetTVPictureMode(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings GetTVPictureMode and expecting the API to return tvERROR_INVALID_STATE */
        result = GetTVPictureMode(pictureMode);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetTVPictureMode() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 123@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetTVPictureMode() -  Set the TV PictureMode by looping through all the values of pictureModes from the PictureMode section of test specific config file | const char * | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetTVPictureMode (void)
{
    gTestID = 123;                                    /* It must be 123 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    uint32_t pqCount = 0;
    char pqMode[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings to Set the SetTVPictureMode for all the pic_modes and expecting the API to return success */
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/range");
    for (unsigned int i = 0; i < pqCount; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/range/%d", i);
        UT_KVP_PROFILE_GET_STRING(keyValue,pqMode);
        result = SetTVPictureMode(pqMode);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);

}

/**
 * @brief Validate SetTVPictureMode() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 124@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call SetTVPictureMode() - Set the TV PictureMode even before TvInit() with valid input | const char *  | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetTVPictureMode() -   Set the TV PictureMode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetTVPictureMode() -   Set the TV PictureMode with invalid picturemode | const char *  | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call SetTVPictureMode() -  Set the TV PictureMode with valid input after TvTerm() with valid input  | const char * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetTVPictureMode (void)
{
    gTestID = 124;                                    /* It must be 124 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    char pqMode[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    UT_KVP_PROFILE_GET_STRING("tvSettings/PictureMode/range/0",pqMode);
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetTVPictureMode and expecting the API to return tvERROR_INVALID_STATE */
        result = SetTVPictureMode(pqMode);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetTVPictureMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetTVPictureMode(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetTVPictureMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetTVPictureMode("INVALID");
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 06: Calling tvsettings the SetTVPictureMode and expecting the API to return tvERROR_INVALID_STATE */
        result = SetTVPictureMode(pqMode);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveSourcePictureMode() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 125@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SaveSourcePictureMode() -  Save the current Source PictureMode by looping through all the values of sourcetype, pqmode and video format type from the VideoSource, PictureMode, VideoFormat, PictureMode sections of test specific config file | tvVideoSrcType_t , int ,tvVideoFormatType_t | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveSourcePictureMode (void)
{
    gTestID = 125;                                    /* It must be 125 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SaveSourcePictureMode for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    for (unsigned int i = 0; i < videoSrcCount; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", i);
        videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            for (unsigned int k = 0; k < videoFmtCount; k++)
            {
                snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", k);
                videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
                result = SaveSourcePictureMode(videoSource,videoFormat, pqValue);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);
            }
        }
    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveSourcePictureMode() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 126@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SaveSourcePictureMode() -  Save the current Source PictureMode even before TvInit() | tvVideoSrcType_t , tvVideoFormatType_t ,int | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SaveSourcePictureMode() -  "videoFormatType,pictureMode"=valid, "videoSrcType"=invalid max range| VIDEO_SOURCE_MAX ,tvVideoFormatType_t, int | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SaveSourcePictureMode() -  "videoFormatType,pictureMode"=valid, "videoSrcType"=invalid lower range| -2 ,tvVideoFormatType_t , int | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SaveSourcePictureMode() -  "videoSrcType,pictureMode"=valid, "videoFormatType"=invalid max range| tvVideoSrcType_t ,VIDEO_FORMAT_MAX, int | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SaveSourcePictureMode() -  "videoSrcType,pictureMode"=valid, "videoFormatType"=invalid lower range| tvVideoSrcType_t, -1, int | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SaveSourcePictureMode() -  "videoSrcType,videoFormatType"=valid, "pictureMode"=invalid lower range | tvVideoSrcType_t,tvVideoFormatType_t, -1  | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SaveSourcePictureMode() -  "videoSrcType,videoFormatType"=valid, "pictureMode"=invalid max range| tvVideoSrcType_t ,tvVideoFormatType_t, PQ_MODE_MAX | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SaveSourcePictureMode() -  Save current Source PictureMode with valid source input, picture_mode, videoFormatType but not supported by the platform by looping through the VideoSource, PictureMode, VideoFormat, PictureMode sections of test specific config file| tvVideoSrcType_t , tvVideoFormatType_t, int | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 11 | call SaveSourcePictureMode() -  Save the current Source PictureMode valid arguments | tvVideoSrcType_t  ,tvVideoFormatType_t , int| tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveSourcePictureMode (void)
{
    gTestID = 126;                                    /* It must be 126 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool SupportAvailable = true;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SaveSourcePictureMode and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveSourcePictureMode(videoSource, videoFormat, pqValue);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SaveSourcePictureMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveSourcePictureMode(VIDEO_SOURCE_MAX,videoFormat,pqValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SaveSourcePictureMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveSourcePictureMode((tvVideoSrcType_t)-2,videoFormat,pqValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SaveSourcePictureMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveSourcePictureMode(videoSource,VIDEO_FORMAT_MAX,pqValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SaveSourcePictureMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveSourcePictureMode(videoSource,(tvVideoFormatType_t)-1,pqValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SaveSourcePictureMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveSourcePictureMode(videoSource,videoFormat,PQ_MODE_MAX);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings SaveSourcePictureMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveSourcePictureMode(videoSource,videoFormat,-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings SaveSourcePictureMode and expecting the API to return tvERROR_INVALID_PARAM */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    for( int i = VIDEO_SOURCE_ALL  ; i < VIDEO_SOURCE_MAX ; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < videoSrcCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", j);
            videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoSource == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){

            result = SaveSourcePictureMode((tvVideoSrcType_t)i,videoFormat, pqValue);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < videoFmtCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", j);
            videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoFormat == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){

            result = SaveSourcePictureMode(videoSource, i, pqValue);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    for(int i =0 ; i < PQ_MODE_MAX; i++)
    {
        SupportAvailable = false;
        for(int j =0 ; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(pqValue == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){

            result = SaveSourcePictureMode(videoSource,(tvVideoFormatType_t)videoFormat,i);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }

    }

    /* Step 10: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 11: Calling tvsettings SaveSourcePictureMode and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveSourcePictureMode(videoSource, videoFormat, pqValue);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetColorTemp_Rgain_onSource() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 127@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 0, tvColorTempSourceOffset_t , 0| tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 2047, tvColorTempSourceOffset_t , 0| tvERROR_NONE | Should Pass |
 * | 04 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 1000, tvColorTempSourceOffset_t , 0| tvERROR_NONE | Should Pass |
 * | 05 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 0, tvColorTempSourceOffset_t , 1| tvERROR_NONE | Should Pass |
 * | 06 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 2047, tvColorTempSourceOffset_t , 1| tvERROR_NONE | Should Pass |
 * | 07 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 1000, tvColorTempSourceOffset_t , 1| tvERROR_NONE | Should Pass |
 * | 08 | call SetColorTemp_Rgain_onSource() -  Reset the ColorTemp Rgain_onSource with another valid value | tvColorTemp_t, 2047, TV_OFFSET_NEW, 0 | tvERROR_NONE | Should Pass |
 * | 09 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetColorTemp_Rgain_onSource (void)
{
    gTestID = 127;                                    /* It must be 127 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02 - 08: Calling tvsettings SetColorTemp_Rgain_onSource and the API to return success */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < (colorTempCount); i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", i);
        colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = HDMI_OFFSET; j < MAX_OFFSET; j++ )
        {
            for (unsigned int k = 0; k < 2; k++ )   //(0 -set 1-save)
            {
                result = SetColorTemp_Rgain_onSource(colorTempValue,0,(tvColorTempSourceOffset_t)j, k);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);

                result = SetColorTemp_Rgain_onSource(colorTempValue,2047,(tvColorTempSourceOffset_t )j, k);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);

                result = SetColorTemp_Rgain_onSource(colorTempValue,1000,(tvColorTempSourceOffset_t )j, k);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);
            }
        }
    }

    /* Step 09: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetColorTemp_Rgain_onSource() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 128@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetColorTemp_Rgain_onSource() - Set the TV ColorTemp Rgain_onSource even before TvInit() | tvColorTemp_t, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource with max range of colortemp | tvColorTemp_MAX, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource with less than lower range of colortemp | -1, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource invalid rgain by looping through all the values of colortemp from the ColorTemperature section of test specific config file | tvColorTemp_t, -1, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource invalid rgain by looping through all the values of colortemp from the ColorTemperature section of test specific config file | tvColorTemp_t, 2048, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource invalid sourceId by looping through all the values of colortemp from the ColorTemperature section of test specific config file | tvColorTemp_t, 0, -2, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource invalid sourceId by looping through all the values of colortemp from the ColorTemperature section of test specific config file | tvColorTemp_t, 0, OFFSET_MAX, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource invalid saveonly flag by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 0, tvColorTempSourceOffset_t, -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource invalid saveonly flag by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 0, tvColorTempSourceOffset_t, 2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource with max range | tvColorTemp_MAX, 0, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp and sourceId with valid value but not supported by the platform by looping through the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 50, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 13 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 14 | call SetColorTemp_Rgain_onSource() -  Set the TV ColorTemp Rgain_onSource with valid input after TvTerm() | tvColorTemp_t, 2047, AV_OFFSET_NEW, 1 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetColorTemp_Rgain_onSource (void)
{
    gTestID = 128;                                    /* It must be 128 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool platformFlag = false;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetColorTemp_Rgain_onSource and expecting the API to return tvERROR_INVALID_STATE */
        result = SetColorTemp_Rgain_onSource(colorTempValue, 0, (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetColorTemp_Rgain_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_Rgain_onSource(tvColorTemp_MAX,0,(tvColorTempSourceOffset_t) HDMI_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetColorTemp_Rgain_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_Rgain_onSource((tvColorTemp_t)-1, 0,(tvColorTempSourceOffset_t) HDMI_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SetColorTemp_Rgain_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_Rgain_onSource(colorTempValue, -1 , (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SetColorTemp_Rgain_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_Rgain_onSource(colorTempValue, 2048 ,(tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SetColorTemp_Rgain_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_Rgain_onSource(colorTempValue, 0, (tvColorTempSourceOffset_t) MAX_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings SetColorTemp_Rgain_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_Rgain_onSource(colorTempValue,0, (tvColorTempSourceOffset_t)-2, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings SetColorTemp_Rgain_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_Rgain_onSource(colorTempValue,0, (tvColorTempSourceOffset_t) HDMI_OFFSET, 2);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 10: Calling tvsettings SetColorTemp_Rgain_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_Rgain_onSource(colorTempValue,0,(tvColorTempSourceOffset_t) HDMI_OFFSET, -1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 11: Calling tvsettings SetColorTemp_Rgain_onSource and the API to return success */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < tvColorTemp_MAX; i++)
    {
        platformFlag = false;
        for (unsigned int j = 0; j < colorTempCount ; j++ )
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", j);
            colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(colorTempValue == (tvColorTemp_t)i)
            {
                platformFlag = true;
                break;
            }
        }
        if(!platformFlag)
        {
            result = SetColorTemp_Rgain_onSource((tvColorTemp_t)i , 0, (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 13: Calling tvsettings TvTerm and the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 14: Calling tvsettings SetColorTemp_Rgain_onSource and the API to return tvERROR_INVALID_STATE */
        result = SetColorTemp_Rgain_onSource(colorTempValue, 0, (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);

}

/**
 * @brief Validate GetColorTemp_Rgain_onSource() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 129@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetColorTemp_Rgain_onSource() -  Retrieve the current ColorTemp Rgain_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemp_Rgain_onSource() -  Retrieve the current ColorTemp Rgain_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the ColorTemperature, ColorTempSourceOffset sections of test specific config file and validate with above value | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetColorTemp_Rgain_onSource (void)
{
    gTestID = 129;                                    /* It must be 129 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    int rgain = -1;
    int rgainRetry = -1;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetColorTemp_Rgain_onSource and expectinging the API to return success */
    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    result = GetColorTemp_Rgain_onSource(colorTempValue,&rgain, (tvColorTempSourceOffset_t)HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_TRUE( (rgain >= 0 && rgain < 2048));

    /* Step 03: Calling tvsettings GetColorTemp_Rgain_onSource and expectinging the API to return success */
    result = GetColorTemp_Rgain_onSource(colorTempValue,&rgainRetry, (tvColorTempSourceOffset_t)HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(rgain,rgainRetry);

    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < (colorTempCount); i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", i);
        colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < MAX_OFFSET; j++ )
        {

            result = GetColorTemp_Rgain_onSource(colorTempValue, &rgain, (tvColorTempSourceOffset_t)j );
            UT_ASSERT_EQUAL(result, tvERROR_NONE);
            UT_ASSERT_TRUE( (rgain >= 0 && rgain < 2048));

        }
    }


    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetColorTemp_Rgain_onSource() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 130@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetColorTemp_Rgain_onSource() -  Retrieve current TV ColorTemp Rgain_onSource even before TvInit() | tvColorTemp_t, int *, tvColorTempSourceOffset_t  | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource with max range color temp| tvColorTemp_MAX, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource with less range color temp |  -1, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource invalid Rgain by looping through all the values of colortemp from the colorTemperaturesections of test specific config file |  tvColorTemp_t, NULL, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource invalid SourceId by looping through all the values of colortemp from the ColorTemperature section of test specific config file |  tvColorTemp_t, int *, -2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource invalid SourceId by looping through all the values of colortemp from the ColorTemperature section of test specific config file |  tvColorTemp_t, int *, OFFSET_MAX | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call GetColorTemp_Rgain_onSource() -   Retrieve the Rgain_onSource for a valid value of TV ColorTemp and SourceId but not supported by the platform by looping through the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 10 | call GetColorTemp_Rgain_onSource() -  Retrieve current TV ColorTemp Rgain_onSource valid arguments | tvColorTemp_t, int *, int  | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetColorTemp_Rgain_onSource (void)
{
    gTestID = 130;                                    /* It must be 130 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    int rgain = -1;
    int sourceOffset = -1;
    bool platformFlag =false;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetColorTemp_Rgain_onSource and expectinging the API to return tvERROR_INVALID_STATE */
        result = GetColorTemp_Rgain_onSource(colorTempValue, &rgain, (tvColorTempSourceOffset_t)HDMI_OFFSET);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetColorTemp_Rgain_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_Rgain_onSource(tvColorTemp_MAX,&rgain, (tvColorTempSourceOffset_t)HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings GetColorTemp_Rgain_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_Rgain_onSource((tvColorTemp_t)-1,&rgain, (tvColorTempSourceOffset_t)HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings GetColorTemp_Rgain_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_Rgain_onSource(colorTempValue, NULL, (tvColorTempSourceOffset_t)HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings GetColorTemp_Rgain_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_Rgain_onSource(colorTempValue, &rgain, (tvColorTempSourceOffset_t) MAX_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings GetColorTemp_Rgain_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_Rgain_onSource(colorTempValue, &rgain, (tvColorTempSourceOffset_t)-2);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings GetColorTemp_Rgain_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < tvColorTemp_MAX; i++)
    {
        platformFlag = false;
        for (unsigned int j = 0; j < colorTempCount; j++ )
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", j);
            colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(colorTempValue == (tvColorTemp_t)i)
            {
                platformFlag = true;
                break;
            }
        }
        if(!platformFlag)
        {
            result = GetColorTemp_Rgain_onSource((tvColorTemp_t)i ,&rgain, (tvColorTempSourceOffset_t)HDMI_OFFSET );
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    for (unsigned int i = 0; i < MAX_OFFSET; i++)
    {
        platformFlag = false;
        for (unsigned int j = 0; j < MAX_OFFSET ; j++ )
        {
            if(j == (tvColorTempSourceOffset_t)i)
            {
                platformFlag = true;
                break;
            }
        }
        if(!platformFlag)
        {
            result = GetColorTemp_Rgain_onSource(colorTempValue ,&rgain,\
                    (tvColorTempSourceOffset_t)i);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

        }
    }

    /* Step 09: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 10: Calling tvsettings GetColorTemp_Rgain_onSource and expectinging the API to return tvERROR_INVALID_STATE */
        result = GetColorTemp_Rgain_onSource(colorTempValue, &rgain, (tvColorTempSourceOffset_t)sourceOffset);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetColorTemp_Ggain_onSource() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 131@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 0, tvColorTempSourceOffset_t , 0| tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 2047, tvColorTempSourceOffset_t , 0| tvERROR_NONE | Should Pass |
 * | 04 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 1000, tvColorTempSourceOffset_t , 0| tvERROR_NONE | Should Pass |
 * | 05 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 0, tvColorTempSourceOffset_t , 1| tvERROR_NONE | Should Pass |
 * | 06 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 2047, tvColorTempSourceOffset_t , 1| tvERROR_NONE | Should Pass |
 * | 07 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 1000, tvColorTempSourceOffset_t , 1| tvERROR_NONE | Should Pass |
 * | 08 | call SetColorTemp_Ggain_onSource() -  Reset the ColorTemp Ggain_onSource with another valid value | tvColorTemp_t, 2047, tvColorTempSourceOffset_t, 0 | tvERROR_NONE | Should Pass |
 * | 09 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetColorTemp_Ggain_onSource (void)
{
    gTestID = 131;                                    /* It must be 131 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02 - 08: Calling tvsettings SetColorTemp_Ggain_onSource and the API to return success */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < (colorTempCount); i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", i);
        colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < MAX_OFFSET; j++ )
        {
            for (unsigned int k = 0; k < 2; k++ )   //(0 -set 1-save)
            {
                result = SetColorTemp_Ggain_onSource(colorTempValue,0, (tvColorTempSourceOffset_t)j, k);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);

                result = SetColorTemp_Ggain_onSource(colorTempValue,2047,(tvColorTempSourceOffset_t)j, k);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);

                result = SetColorTemp_Ggain_onSource(colorTempValue,1000,(tvColorTempSourceOffset_t)j, k);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);
            }
        }
    }

    /* Step 09: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetColorTemp_Ggain_onSource() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 132@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetColorTemp_Ggain_onSource() - Set the TV ColorTemp Ggain_onSource even before TvInit() | tvColorTemp_t, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource with max range of colortemp | tvColorTemp_MAX, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource with less than lower range of colortemp | -1, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource invalid rgain by looping through all the values of colortemp from the ColorTemperature section of test specific config file | tvColorTemp_t, -1, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource invalid rgain by looping through all the values of colortemp from the ColorTemperature section of test specific config file | tvColorTemp_t, 2048, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource invalid sourceId by looping through all the values of colortemp from the ColorTemperature section of test specific config file | tvColorTemp_t, 0, -2, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource invalid sourceId by looping through all the values of colortemp from the ColorTemperature section of test specific config file | tvColorTemp_t, 0, MAX_OFFSET, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource invalid saveonly flag by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 0, tvColorTempSourceOffset_t, -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource invalid saveonly flag by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 0, tvColorTempSourceOffset_t, 2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource with max range | tvColorTemp_MAX, 0, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp and sourceId with valid value but not supported by the platform by looping through the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 50, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 13 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 14 | call SetColorTemp_Ggain_onSource() -  Set the TV ColorTemp Ggain_onSource with valid input after TvTerm() | tvColorTemp_t, 2047, tvColorTempSourceOffset_t, 1 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetColorTemp_Ggain_onSource (void)
{
    gTestID = 132;                                    /* It must be 132 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool platformFlag = false;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetColorTemp_Ggain_onSource and expecting the API to return tvERROR_INVALID_STATE */
        result = SetColorTemp_Ggain_onSource(colorTempValue, 0, (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetColorTemp_Ggain_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_Ggain_onSource(tvColorTemp_MAX,0, (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetColorTemp_Ggain_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_Ggain_onSource((tvColorTemp_t)-1, 0, (tvColorTempSourceOffset_t) HDMI_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SetColorTemp_Ggain_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_Ggain_onSource(colorTempValue, -1 ,(tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SetColorTemp_Ggain_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_Ggain_onSource(colorTempValue, 2048 ,(tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SetColorTemp_Ggain_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_Ggain_onSource(colorTempValue,0, (tvColorTempSourceOffset_t) MAX_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings SetColorTemp_Ggain_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_Ggain_onSource(colorTempValue, 0, (tvColorTempSourceOffset_t) -2, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings SetColorTemp_Ggain_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_Ggain_onSource(colorTempValue,0,(tvColorTempSourceOffset_t)HDMI_OFFSET, 2);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 10: Calling tvsettings SetColorTemp_Ggain_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_Ggain_onSource(colorTempValue,0,(tvColorTempSourceOffset_t)HDMI_OFFSET, -1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 11: Calling tvsettings SetColorTemp_Ggain_onSource and the API to return success */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < tvColorTemp_MAX; i++)
    {
        platformFlag = false;
        for (unsigned int j = 0; j < colorTempCount; j++ )
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", j);
            colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(colorTempValue == (tvColorTemp_t)i)
            {
                platformFlag = true;
                break;
            }
        }
        if(!platformFlag)
        {
            result = SetColorTemp_Ggain_onSource((tvColorTemp_t)i, 0, \
                    (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

        }
    }

    /* Step 12: Calling tvsettings SetColorTemp_Ggain_onSource and the API to return success */
    for (unsigned int i = 0; i < MAX_OFFSET; i++)
    {
        platformFlag = false;
        for (unsigned int j = 0; j < MAX_OFFSET ; j++ )
        {
            if(j == (tvColorTempSourceOffset_t)i)
            {
                platformFlag = true;
                break;
            }
        }
        if(!platformFlag)
        {
            result = SetColorTemp_Ggain_onSource(colorTempValue ,0, \
                    (tvColorTempSourceOffset_t)i, 0);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

        }
    }

    /* Step 13: Calling tvsettings TvTerm and the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 14: Calling tvsettings SetColorTemp_Ggain_onSource and the API to return tvERROR_INVALID_STATE */
        result = SetColorTemp_Ggain_onSource(colorTempValue, 0, (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetColorTemp_Ggain_onSource() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 133@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetColorTemp_Ggain_onSource() -  Retrieve the current ColorTemp Ggain_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemp_Ggain_onSource() -  Retrieve the current ColorTemp Ggain_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the ColorTemperature, ColorTempSourceOffset sections of test specific config file and validate with above value | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetColorTemp_Ggain_onSource (void)
{
    gTestID = 133;                                    /* It must be 133 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    int ggain = -1;
    int ggainRetry = -1;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02-03: Calling tvsettings GetColorTemp_Ggain_onSource and expectinging the API to return success */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < (colorTempCount); i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", i);
        colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < MAX_OFFSET; j++ )
        {
            result = GetColorTemp_Ggain_onSource(colorTempValue, &ggain, (tvColorTempSourceOffset_t)j);
            UT_ASSERT_EQUAL(result, tvERROR_NONE);
            UT_ASSERT_TRUE( (ggain >= 0 && ggain < 2048));

            result = GetColorTemp_Ggain_onSource(colorTempValue, &ggainRetry, (tvColorTempSourceOffset_t)j);
            UT_ASSERT_EQUAL(result, tvERROR_NONE);
            UT_ASSERT_EQUAL(ggain,ggainRetry);

        }
    }

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetColorTemp_Ggain_onSource() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 134@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetColorTemp_Ggain_onSource() -  Retrieve current TV ColorTemp Ggain_onSource even before TvInit() | tvColorTemp_t, int *, tvColorTempSourceOffset_t  | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource with max range color temp| tvColorTemp_MAX, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource with less range color temp |  -1, int *, int | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource invalid Rgain by looping through all the values of colortemp from the ColorTemperature section of test specific config file |  tvColorTemp_t, NULL, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource invalid SourceId by looping through all the values of colortemp from the ColorTemperature section of test specific config file |  tvColorTemp_t, int *, -2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource invalid SourceId by looping through all the values of colortemp from the ColorTemperature section of test specific config file |  tvColorTemp_t, int *, OFFSET_MAX | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call GetColorTemp_Ggain_onSource() -   Retrieve the Ggain_onSource for a valid value of TV ColorTemp and SourceId but not supported by the platform by looping through the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 10 | call GetColorTemp_Ggain_onSource() -  Retrieve current TV ColorTemp Ggain_onSource valid arguments | tvColorTemp_t, int *, tvColorTempSourceOffset_t  | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetColorTemp_Ggain_onSource (void)
{
    gTestID = 134;                                    /* It must be 134 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    int ggain = -1;
    int sourceOffset = -1;
    bool platformFlag = false;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetColorTemp_Ggain_onSource and expectinging the API to return tvERROR_INVALID_STATE */
        result = GetColorTemp_Ggain_onSource(colorTempValue, &ggain, (tvColorTempSourceOffset_t)HDMI_OFFSET);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetColorTemp_Ggain_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_Ggain_onSource(tvColorTemp_MAX,&ggain, (tvColorTempSourceOffset_t)HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings GetColorTemp_Ggain_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_Ggain_onSource((tvColorTemp_t)-1,&ggain, (tvColorTempSourceOffset_t)HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings GetColorTemp_Ggain_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_Ggain_onSource(colorTempValue, NULL, (tvColorTempSourceOffset_t)HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings GetColorTemp_Ggain_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_Ggain_onSource(colorTempValue, &ggain,\
            (tvColorTempSourceOffset_t) MAX_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings GetColorTemp_Ggain_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_Ggain_onSource(colorTempValue, &ggain,  \
            (tvColorTempSourceOffset_t)-2);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings GetColorTemp_Ggain_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < tvColorTemp_MAX; i++)
    {
        platformFlag = false;
        for (unsigned int j = 0; j < colorTempCount ; j++ )
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", j);
            colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(colorTempValue == (tvColorTemp_t)i)
            {
                platformFlag = true;
                break;
            }
        }
        if(!platformFlag)
        {
            result = GetColorTemp_Ggain_onSource((tvColorTemp_t)i ,&ggain, \
                    (tvColorTempSourceOffset_t)HDMI_OFFSET );
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    for (unsigned int i = 0; i < MAX_OFFSET; i++)
    {
        platformFlag = false;
        for (unsigned int j = 0; j < MAX_OFFSET ; j++ )
        {
            if(j == (tvColorTempSourceOffset_t)i)
            {
                platformFlag = true;
                break;
            }
        }
        if(!platformFlag)
        {
            result = GetColorTemp_Ggain_onSource(colorTempValue ,&ggain,\
                    (tvColorTempSourceOffset_t)i);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

        }
    }

    /* Step 09: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 10: Calling tvsettings GetColorTemp_Ggain_onSource and expectinging the API to return tvERROR_INVALID_STATE */
        result = GetColorTemp_Ggain_onSource(colorTempValue, &ggain, (tvColorTempSourceOffset_t)sourceOffset);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetColorTemp_Bgain_onSource() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 135@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 0, tvColorTempSourceOffset_t , 0| tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 2047, tvColorTempSourceOffset_t , 0| tvERROR_NONE | Should Pass |
 * | 04 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 1000, tvColorTempSourceOffset_t , 0| tvERROR_NONE | Should Pass |
 * | 05 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 0, tvColorTempSourceOffset_t , 1| tvERROR_NONE | Should Pass |
 * | 06 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 2047, tvColorTempSourceOffset_t , 1| tvERROR_NONE | Should Pass |
 * | 07 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 1000, tvColorTempSourceOffset_t , 1| tvERROR_NONE | Should Pass |
 * | 08 | call SetColorTemp_Bgain_onSource() -  Reset the ColorTemp Bgain_onSource with another valid value | tvColorTemp_t, 2047, int, 0 | tvERROR_NONE | Should Pass |
 * | 09 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetColorTemp_Bgain_onSource (void)
{
    gTestID = 135;                                    /* It must be 135 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02 - 08: Calling tvsettings SetColorTemp_Bgain_onSource and the API to return success */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < (colorTempCount); i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", i);
        colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < MAX_OFFSET; j++ )
        {
            for (unsigned int k = 0; k < 2; k++ )   //(0 -set 1-save)
            {
                result = SetColorTemp_Bgain_onSource(colorTempValue,0, (tvColorTempSourceOffset_t)j, k);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);

                result = SetColorTemp_Bgain_onSource(colorTempValue,2047, (tvColorTempSourceOffset_t)j, k);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);

                result = SetColorTemp_Bgain_onSource(colorTempValue,1000, (tvColorTempSourceOffset_t)j, k);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);
            }
        }
    }

    /* Step 09: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetColorTemp_Bgain_onSource() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 136@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetColorTemp_Bgain_onSource() - Set the TV ColorTemp Bgain_onSource even before TvInit() | tvColorTemp_t, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource with max range of colortemp | tvColorTemp_MAX, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource with max range less than lower range of colortemp | -1, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource invalid rgain by looping through all the values of colortemp from the ColorTemperature section of test specific config file | tvColorTemp_t, -1, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource invalid rgain by looping through all the values of colortemp from the ColorTemperature section of test specific config file | tvColorTemp_t, 2048, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource invalid sourceId by looping through all the values of colortemp from the ColorTemperature section of test specific config file | tvColorTemp_t, 0, -2, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource invalid sourceId by looping through all the values of colortemp from the ColorTemperature section of test specific config file | tvColorTemp_t, 0, OFFSET_MAX, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource invalid saveonly flag by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 0, tvColorTempSourceOffset_t, -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource invalid saveonly flag by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 0, tvColorTempSourceOffset_t, 2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource with max range | tvColorTemp_MAX, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp and sourceId with valid value but not supported by the platform by looping through the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 50, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 13 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 14 | call SetColorTemp_Bgain_onSource() -  Set the TV ColorTemp Bgain_onSource with valid input after TvTerm() | tvColorTemp_t, 2047, tvColorTempSourceOffset_t, 1 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetColorTemp_Bgain_onSource (void)
{
    gTestID = 136;                                    /* It must be 136 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool platformFlag = false;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetColorTemp_Bgain_onSource and expecting the API to return tvERROR_INVALID_STATE */
        result = SetColorTemp_Bgain_onSource(colorTempValue, 0, (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetColorTemp_Bgain_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_Bgain_onSource(tvColorTemp_MAX,0,(tvColorTempSourceOffset_t) HDMI_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetColorTemp_Bgain_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_Bgain_onSource((tvColorTemp_t)-1, 0,(tvColorTempSourceOffset_t) HDMI_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SetColorTemp_Bgain_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_Bgain_onSource(colorTempValue, -1 ,(tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SetColorTemp_Bgain_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_Bgain_onSource(colorTempValue, 2048 ,(tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SetColorTemp_Bgain_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_Bgain_onSource(colorTempValue,0, (tvColorTempSourceOffset_t) MAX_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings SetColorTemp_Bgain_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_Bgain_onSource(colorTempValue,0, (tvColorTempSourceOffset_t) -2, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings SetColorTemp_Bgain_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_Bgain_onSource(colorTempValue,0,(tvColorTempSourceOffset_t)HDMI_OFFSET, 2);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 10: Calling tvsettings SetColorTemp_Bgain_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_Bgain_onSource(colorTempValue,0, (tvColorTempSourceOffset_t)HDMI_OFFSET, -1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 11: Calling tvsettings SetColorTemp_Bgain_onSource and the API to return success */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < tvColorTemp_MAX; i++)
    {
        platformFlag = false;
        for (unsigned int j = 0; j < colorTempCount ; j++ )
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", j);
            colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(colorTempValue == (tvColorTemp_t)i)
            {
                platformFlag = true;
                break;
            }
        }
        if(!platformFlag)
        {
            result = SetColorTemp_Bgain_onSource((tvColorTemp_t)i, 0, (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 12: Calling tvsettings SetColorTemp_Bgain_onSource and the API to return success */
    for (unsigned int i = 0; i < MAX_OFFSET; i++)
    {
        platformFlag = false;
        for (unsigned int j = 0; j < MAX_OFFSET ; j++ )
        {
            if(j == (tvColorTempSourceOffset_t)i)
            {
                platformFlag = true;
                break;
            }
        }
        if(!platformFlag)
        {
            result = SetColorTemp_Bgain_onSource(colorTempValue ,0, (tvColorTempSourceOffset_t)i, 0);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

        }
    }

    /* Step 13: Calling tvsettings TvTerm and the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 14: Calling tvsettings SetColorTemp_Bgain_onSource and the API to return tvERROR_INVALID_STATE */
        result = SetColorTemp_Bgain_onSource(colorTempValue, 0, (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetColorTemp_Bgain_onSource() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 137@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetColorTemp_Bgain_onSource() -  Retrieve the current ColorTemp Bgain_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemp_Bgain_onSource() -  Retrieve the current ColorTemp Bgain_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the ColorTemperature, ColorTempSourceOffset sections of test specific config file and validate with above value | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetColorTemp_Bgain_onSource (void)
{
    gTestID = 137;                                    /* It must be 137 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    int bgain = -1;
    int bgainRetry = -1;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetColorTemp_Bgain_onSource and expectinging the API to return success */
    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    result = GetColorTemp_Bgain_onSource(colorTempValue,&bgain, (tvColorTempSourceOffset_t)HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_TRUE( (bgain >= 0 && bgain < 2048 ));

    /* Step 03: Calling tvsettings GetColorTemp_Bgain_onSource and expectinging the API to return success */
    result = GetColorTemp_Bgain_onSource(colorTempValue,&bgainRetry, (tvColorTempSourceOffset_t)HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(bgain,bgainRetry);

    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < (colorTempCount); i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", i);
        colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < MAX_OFFSET; j++ )
        {

            result = GetColorTemp_Bgain_onSource(colorTempValue, &bgain, (tvColorTempSourceOffset_t)j );
            UT_ASSERT_EQUAL(result, tvERROR_NONE);
            UT_ASSERT_TRUE( (bgain >= 0 && bgain < 2048));

        }
    }

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetColorTemp_Bgain_onSource() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 138@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetColorTemp_Bgain_onSource() -  Retrieve current TV ColorTemp Bgain_onSource even before TvInit() | tvColorTemp_t, int *, tvColorTempSourceOffset_t  | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource with max range color temp| tvColorTemp_MAX, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource with less range color temp |  -1, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource invalid Rgain by looping through all the values of colortemp from the ColorTemperature section of test specific config file |  tvColorTemp_t, NULL, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource invalid SourceId by looping through all the values of colortemp from the ColorTemperature section of test specific config file |  tvColorTemp_t, int *, -2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource invalid SourceId by looping through all the values of colortemp from the ColorTemperature section of test specific config file |  tvColorTemp_t, int *, OFFSET_MAX | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call GetColorTemp_Bgain_onSource() -   Retrieve the Bgain_onSource for a valid value of TV ColorTemp and SourceId but not supported by the platform by looping through the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 10 | call GetColorTemp_Bgain_onSource() -  Retrieve current TV ColorTemp Bgain_onSource valid arguments | tvColorTemp_t, int *, tvColorTempSourceOffset_t  | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetColorTemp_Bgain_onSource (void)
{
    gTestID = 138;                                    /* It must be 138 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    int bgain = -1;
    int sourceOffset = -1;
    bool platformFlag = false;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetColorTemp_Bgain_onSource and expectinging the API to return tvERROR_INVALID_STATE */
        result = GetColorTemp_Bgain_onSource(colorTempValue, &bgain, (tvColorTempSourceOffset_t)HDMI_OFFSET);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetColorTemp_Bgain_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_Bgain_onSource(tvColorTemp_MAX,&bgain,(tvColorTempSourceOffset_t)HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings GetColorTemp_Bgain_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_Bgain_onSource((tvColorTemp_t)-1,&bgain, (tvColorTempSourceOffset_t)HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings GetColorTemp_Bgain_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_Bgain_onSource(colorTempValue, NULL, (tvColorTempSourceOffset_t)HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings GetColorTemp_Bgain_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_Bgain_onSource(colorTempValue, &bgain,(tvColorTempSourceOffset_t) MAX_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings GetColorTemp_Bgain_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_Bgain_onSource(colorTempValue, &bgain, (tvColorTempSourceOffset_t)-2);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings GetColorTemp_Bgain_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < tvColorTemp_MAX; i++)
    {
        platformFlag = false;
        for (unsigned int j = 0; j < colorTempCount ; j++ )
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", j);
            colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(colorTempValue == (tvColorTemp_t)i)
            {
                platformFlag = true;
                break;
            }
        }
        if(!platformFlag)
        {
            result = GetColorTemp_Bgain_onSource((tvColorTemp_t)i,&bgain, (tvColorTempSourceOffset_t)HDMI_OFFSET );
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    for (unsigned int i = 0; i < MAX_OFFSET; i++)
    {
        platformFlag = false;
        for (unsigned int j = 0; j < MAX_OFFSET ; j++ )
        {
            if(j == (tvColorTempSourceOffset_t)i)
            {
                platformFlag = true;
                break;
            }
        }
        if(!platformFlag)
        {
            result = GetColorTemp_Bgain_onSource(colorTempValue ,&bgain, (tvColorTempSourceOffset_t)i);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

        }
    }

    /* Step 09: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 10: Calling tvsettings GetColorTemp_Bgain_onSource and expectinging the API to return tvERROR_INVALID_STATE */
        result = GetColorTemp_Bgain_onSource(colorTempValue, &bgain, (tvColorTempSourceOffset_t)sourceOffset);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetColorTemp_R_post_offset_onSource() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 139@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -   Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file| tvColorTemp_t, -1024, tvColorTempSourceOffset_t, 0 | tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file| tvColorTemp_t, 1023, tvColorTempSourceOffset_t, 0 | tvERROR_NONE | Should Pass |
 * | 04 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file| tvColorTemp_t, 500, tvColorTempSourceOffset_t, 0 | tvERROR_NONE | Should Pass |
 * | 05 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file| tvColorTemp_t, -1024, tvColorTempSourceOffset_t, 1 | tvERROR_NONE | Should Pass |
 * | 06 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file| tvColorTemp_t, 1023, tvColorTempSourceOffset_t, 1 | tvERROR_NONE | Should Pass |
 * | 07 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file| tvColorTemp_t, 500, tvColorTempSourceOffset_t, 1 | tvERROR_NONE | Should Pass |
 * | 08 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetColorTemp_R_post_offset_onSource (void)
{
    gTestID = 139;                                    /* It must be 139 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02 - 07: Calling tvsettings SetColorTemp_R_post_offset_onSource and the API to return success */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < (colorTempCount); i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", i);
        colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < MAX_OFFSET; j++ )
        {
            for (unsigned int k = 0; k < 2; k++ )   //(0 -set 1-save)
            {
                result = SetColorTemp_R_post_offset_onSource(colorTempValue,-1024, (tvColorTempSourceOffset_t)j, k);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);

                result = SetColorTemp_R_post_offset_onSource(colorTempValue,1023, (tvColorTempSourceOffset_t)j, k);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);

                result = SetColorTemp_R_post_offset_onSource(colorTempValue,500, (tvColorTempSourceOffset_t)j, k);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);
            }
        }
    }

    /* Step 08: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);

}

/**
 * @brief Validate SetColorTemp_R_post_offset_onSource() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 140@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetColorTemp_R_post_offset_onSource() - Set the TV ColorTemp R_post_offset_onSource even before TvInit() | tvColorTemp_t, -1024, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource with max range | tvColorTemp_Max, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource with less than the lower range | -1, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource invalid less than the lower range of rpostoffset  with by looping through all the values of colortemp and SourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, -1025, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource invalid max range of rpostoffset with by looping through all the values of colortemp and SourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 1025, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource invalid sourceId with by looping through all the values of colortemp from the ColorTemperature section of test specific config file | tvColorTemp_t, int, -2, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource invalid sourceId with by looping through all the values of colortemp from the ColorTemperature section of test specific config file | tvColorTemp_t, int, OFFSET_MAX, 0| tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource invalid saveonly flag with by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, int, tvColorTempSourceOffset_t, -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource invalid saveonly flag with by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, int, tvColorTempSourceOffset_t, 2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource with valid value of colortemp but not supported by the platform by looping through the ColorTemperature section of test specific config file | tvColorTemp_t, int, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource with valid value of sourceId but not supported by the platform by looping through the ColorTempSourceOffset section of test specific config file | tvColorTemp_t, int, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 13 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 14 | call SetColorTemp_R_post_offset_onSource() -  Set the TV ColorTemp R_post_offset_onSource with valid input after TvTerm() | tvColorTemp_t, 1024, tvColorTempSourceOffset_t, 1 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetColorTemp_R_post_offset_onSource (void)
{
    gTestID = 140;                                    /* It must be 140 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool platformFlag = false;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetColorTemp_R_post_offset_onSource and expecting the API to return tvERROR_INVALID_STATE */
        result = SetColorTemp_R_post_offset_onSource(colorTempValue, 0, (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetColorTemp_R_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_R_post_offset_onSource(tvColorTemp_MAX,0, (tvColorTempSourceOffset_t) HDMI_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetColorTemp_R_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_R_post_offset_onSource((tvColorTemp_t)-1, 0,(tvColorTempSourceOffset_t) HDMI_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SetColorTemp_R_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_R_post_offset_onSource(colorTempValue, -1025 , (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SetColorTemp_R_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_R_post_offset_onSource(colorTempValue, 1025 , (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SetColorTemp_R_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_R_post_offset_onSource(colorTempValue,0,(tvColorTempSourceOffset_t)  MAX_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings SetColorTemp_R_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_R_post_offset_onSource(colorTempValue,0,(tvColorTempSourceOffset_t) -2, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings SetColorTemp_R_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_R_post_offset_onSource(colorTempValue,0, (tvColorTempSourceOffset_t)HDMI_OFFSET, 2);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 10: Calling tvsettings SetColorTemp_R_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_R_post_offset_onSource(colorTempValue,0, (tvColorTempSourceOffset_t)HDMI_OFFSET, -1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 11: Calling tvsettings SetColorTemp_R_post_offset_onSource and the API to return success */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < tvColorTemp_MAX; i++)
    {
        platformFlag = false;
        for (unsigned int j = 0; j < colorTempCount ; j++ )
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", j);
            colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(colorTempValue == (tvColorTemp_t)i)
            {
                platformFlag = true;
                break;
            }
        }
        if(!platformFlag)
        {
            result = SetColorTemp_R_post_offset_onSource((tvColorTemp_t)i , 0,\
                    (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 12: Calling tvsettings SetColorTemp_R_post_offset_onSource and the API to return success */
    for (unsigned int i = 0; i < MAX_OFFSET; i++)
    {
        platformFlag = false;
        for (unsigned int j = 0; j < MAX_OFFSET ; j++ )
        {
            if(j == (tvColorTempSourceOffset_t)i)
            {
                platformFlag = true;
                break;
            }
        }
        if(!platformFlag)
        {
            result = SetColorTemp_R_post_offset_onSource(colorTempValue ,0,\
                    (tvColorTempSourceOffset_t)i, 0);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

        }
    }

    /* Step 13: Calling tvsettings TvTerm and the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 14: Calling tvsettings SetColorTemp_R_post_offset_onSource and the API to return tvERROR_INVALID_STATE */
        result = SetColorTemp_R_post_offset_onSource(colorTempValue, 0, (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetColorTemp_R_post_offset_onSource() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 141@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetColorTemp_R_post_offset_onSource() -  Retrieve the current ColorTemp R_post_offset_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t| tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemp_R_post_offset_onSource() -  Retrieve the current ColorTemp R_post_offset_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the ColorTemperature, ColorTempSourceOffset sections of test specific config file and validate with above value | tvColorTemp_t, int *, tvColorTempSourceOffset_t| tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetColorTemp_R_post_offset_onSource (void)
{
    gTestID = 141;                                    /* It must be 141 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    int rpostoffset = -1;
    int rpostoffsetRetry = -1;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetColorTemp_R_post_offset_onSource and expectinging the API to return success */
    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    result = GetColorTemp_R_post_offset_onSource(colorTempValue,&rpostoffset, (tvColorTempSourceOffset_t)HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_TRUE( (rpostoffset >= 0 && rpostoffset < 2048));

    /* Step 03: Calling tvsettings GetColorTemp_R_post_offset_onSource and expectinging the API to return success */
    result = GetColorTemp_R_post_offset_onSource(colorTempValue,&rpostoffsetRetry,(tvColorTempSourceOffset_t) HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(rpostoffset,rpostoffsetRetry);

    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < (colorTempCount); i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", i);
        colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < MAX_OFFSET; j++ )
        {

            result = GetColorTemp_R_post_offset_onSource(colorTempValue, &rpostoffset, (tvColorTempSourceOffset_t)j );
            UT_ASSERT_EQUAL(result, tvERROR_NONE);
            UT_ASSERT_TRUE( (rpostoffset >= 0 && rpostoffset < 2048));

        }
    }

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetColorTemp_R_post_offset_onSource() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 142@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetColorTemp_R_post_offset_onSource() -  Retrieve current TV ColorTemp R_post_offset_onSource even before TvInit() | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemp_R_post_offset_onSource() -   Retrieve current TV ColorTemp R_post_offset_onSource with max range color temp| tvColorTemp_MAX, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetColorTemp_R_post_offset_onSource() -   Retrieve current TV ColorTemp R_post_offset_onSource with less range color temp |  -1, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetColorTemp_R_post_offset_onSource() -   Retrieve current TV ColorTemp R_post_offset_onSource invalid rpostoffset  by looping through all the values of colortemp and SourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file |  tvColorTemp_t, NULL, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call GetColorTemp_R_post_offset_onSource() -   Retrieve current TV ColorTemp R_post_offset_onSource invalid SourceId by looping through all the values of colortemp from the ColorTemperature section of test specific config file |  tvColorTemp_t, int *, -2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call GetColorTemp_R_post_offset_onSource() -   Retrieve current TV ColorTemp R_post_offset_onSource invalid SourceId by looping through all the values of colortemp from the ColorTemperature section of test specific config file |  tvColorTemp_t, int *, OFFSET_MAX | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call GetColorTemp_R_post_offset_onSource() -   Retrieve the R_post_offset_onSource for a valid value of TV ColorTemp but not supported by the platform by looping through the ColorTemperature section of test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call GetColorTemp_R_post_offset_onSource() -   Retrieve the R_post_offset_onSource for a valid value of SourceId but not supported by the platform by looping through the ColorTempSourceOffset section of test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 11 | call GetColorTemp_R_post_offset_onSource() -  Retrieve current TV ColorTemp R_post_offset_onSource valid arguments | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetColorTemp_R_post_offset_onSource (void)
{
    gTestID = 142;                                    /* It must be 142 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    int rpostoffset = -1;
    int sourceOffset = -1;
    bool platformFlag = false;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetColorTemp_R_post_offset_onSource and expectinging the API to return tvERROR_INVALID_STATE */
        result = GetColorTemp_R_post_offset_onSource(colorTempValue, &rpostoffset, (tvColorTempSourceOffset_t)HDMI_OFFSET);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetColorTemp_R_post_offset_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_R_post_offset_onSource(tvColorTemp_MAX,&rpostoffset, (tvColorTempSourceOffset_t)HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings GetColorTemp_R_post_offset_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_R_post_offset_onSource((tvColorTemp_t)-1,&rpostoffset, (tvColorTempSourceOffset_t)HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings GetColorTemp_R_post_offset_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_R_post_offset_onSource(colorTempValue, NULL, (tvColorTempSourceOffset_t)HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings GetColorTemp_R_post_offset_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_R_post_offset_onSource(colorTempValue, &rpostoffset,(tvColorTempSourceOffset_t) MAX_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings GetColorTemp_R_post_offset_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_R_post_offset_onSource(colorTempValue, &rpostoffset,(tvColorTempSourceOffset_t) -2);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings GetColorTemp_R_post_offset_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < tvColorTemp_MAX; i++)
    {
        platformFlag = false;
        for (unsigned int j = 0; j < colorTempCount ; j++ )
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", j);
            colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(colorTempValue == (tvColorTemp_t)i)
            {
                platformFlag = true;
                break;
            }
        }
        if(!platformFlag)
        {
            result = GetColorTemp_R_post_offset_onSource((tvColorTemp_t)i ,&rpostoffset, (tvColorTempSourceOffset_t)HDMI_OFFSET );
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 09: Calling tvsettings GetColorTemp_R_post_offset_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    for (unsigned int i = 0; i < MAX_OFFSET; i++)
    {
        platformFlag = false;
        for (unsigned int j = 0; j < MAX_OFFSET ; j++ )
        {
            if(j == (tvColorTempSourceOffset_t)i)
            {
                platformFlag = true;
                break;
            }
        }
        if(!platformFlag)
        {
            result = GetColorTemp_R_post_offset_onSource(colorTempValue ,&rpostoffset, (tvColorTempSourceOffset_t)i);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 10: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 11: Calling tvsettings GetColorTemp_R_post_offset_onSource and expectinging the API to return tvERROR_INVALID_STATE */
        result = GetColorTemp_R_post_offset_onSource(colorTempValue, &rpostoffset, (tvColorTempSourceOffset_t)sourceOffset);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetColorTemp_G_post_offset_onSource() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 143@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -   Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file| tvColorTemp_t, -1024, tvColorTempSourceOffset_t, 0 | tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file| tvColorTemp_t, 1023, tvColorTempSourceOffset_t, 0 | tvERROR_NONE | Should Pass |
 * | 04 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file| tvColorTemp_t, 500, tvColorTempSourceOffset_t, 0 | tvERROR_NONE | Should Pass |
 * | 05 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file| tvColorTemp_t, -1024, tvColorTempSourceOffset_t, 1 | tvERROR_NONE | Should Pass |
 * | 06 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file| tvColorTemp_t, 1023, tvColorTempSourceOffset_t, 1 | tvERROR_NONE | Should Pass |
 * | 07 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file| tvColorTemp_t, 500, tvColorTempSourceOffset_t, 1 | tvERROR_NONE | Should Pass |
 * | 08 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetColorTemp_G_post_offset_onSource (void)
{
    gTestID = 143;                                    /* It must be 143 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02 - 07: Calling tvsettings SetColorTemp_G_post_offset_onSource and the API to return success */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < (colorTempCount); i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", i);
        colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < MAX_OFFSET; j++ )
        {
            for (unsigned int k = 0; k < 2; k++ )   //(0 -set 1-save)
            {
                result = SetColorTemp_G_post_offset_onSource(colorTempValue,-1024, (tvColorTempSourceOffset_t)j, k);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);

                result = SetColorTemp_G_post_offset_onSource(colorTempValue,1023, (tvColorTempSourceOffset_t)j, k);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);

                result = SetColorTemp_G_post_offset_onSource(colorTempValue,500, (tvColorTempSourceOffset_t)j, k);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);
            }
        }
    }

    /* Step 08: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetColorTemp_G_post_offset_onSource() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 144@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetColorTemp_G_post_offset_onSource() - Set the TV ColorTemp G_post_offset_onSource even before TvInit() | tvColorTemp_t, -1024, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource with max range | tvColorTemp_Max, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource with less than the lower range | -1, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource invalid less than the lower range of gpostoffset with by looping through all the values of colortemp and SourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, -1025, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource invalid max range of gpostoffset with by looping through all the values of colortemp and SourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 1025, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource invalid sourceId flag with by looping through all the values of colortemp from the ColorTemperature section of test specific config file | tvColorTemp_t, int, OFFSET_MAX, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource invalid sourceId flag with by looping through all the values of colortemp from the ColorTemperature section of test specific config file | tvColorTemp_t, int, -2, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource invalid saveonly flag with by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, int, tvColorTempSourceOffset_t, -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource invalid saveonly flag with by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, int, tvColorTempSourceOffset_t, 2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource with valid value of colortemp but not supported by the platform by looping through the ColorTemperature section of test specific config file | tvColorTemp_t, int, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource with valid value of sourceId but not supported by the platform by looping through the ColorTempSourceOffset section of test specific config file | tvColorTemp_t, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 13 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 14 | call SetColorTemp_G_post_offset_onSource() -  Set the TV ColorTemp G_post_offset_onSource with valid input after TvTerm() | tvColorTemp_t, 1024, tvColorTempSourceOffset_t, 1 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetColorTemp_G_post_offset_onSource (void)
{
    gTestID = 144;                                    /* It must be 144 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool platformFlag = false;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetColorTemp_G_post_offset_onSource and expecting the API to return tvERROR_INVALID_STATE */
        result = SetColorTemp_G_post_offset_onSource(colorTempValue, 0, (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetColorTemp_G_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_G_post_offset_onSource(tvColorTemp_MAX,0, (tvColorTempSourceOffset_t) HDMI_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetColorTemp_G_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_G_post_offset_onSource((tvColorTemp_t)-1, 0, (tvColorTempSourceOffset_t) HDMI_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SetColorTemp_G_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_G_post_offset_onSource(colorTempValue, -1025 , (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SetColorTemp_G_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_G_post_offset_onSource(colorTempValue, 1025 , (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SetColorTemp_G_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_G_post_offset_onSource(colorTempValue,0, (tvColorTempSourceOffset_t) MAX_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings SetColorTemp_G_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_G_post_offset_onSource(colorTempValue,0, (tvColorTempSourceOffset_t) -2, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings SetColorTemp_G_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_G_post_offset_onSource(colorTempValue,0, (tvColorTempSourceOffset_t) HDMI_OFFSET, 2);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 10: Calling tvsettings SetColorTemp_G_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_G_post_offset_onSource(colorTempValue,0, (tvColorTempSourceOffset_t)HDMI_OFFSET, -1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 11: Calling tvsettings SetColorTemp_G_post_offset_onSource and the API to return success */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < tvColorTemp_MAX; i++)
    {
        platformFlag = false;
        for (unsigned int j = 0; j < colorTempCount ; j++ )
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", j);
            colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(colorTempValue == (tvColorTemp_t)i)
            {
                platformFlag = true;
                break;
            }
        }
        if(!platformFlag)
        {
            result = SetColorTemp_G_post_offset_onSource((tvColorTemp_t)i , 0,\
                    (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }


    /* Step 12: Calling tvsettings SetColorTemp_G_post_offset_onSource and the API to return success */
    for (unsigned int i = 0; i < MAX_OFFSET; i++)
    {
        platformFlag = false;
        for (unsigned int j = 0; j < MAX_OFFSET ; j++ )
        {
            if(j == (tvColorTempSourceOffset_t)i)
            {
                platformFlag = true;
                break;
            }
        }
        if(!platformFlag)
        {
            result = SetColorTemp_G_post_offset_onSource(colorTempValue ,0,\
                    (tvColorTempSourceOffset_t)i, 0);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

        }
    }



    /* Step 13: Calling tvsettings TvTerm and the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 14: Calling tvsettings SetColorTemp_G_post_offset_onSource and the API to return tvERROR_INVALID_STATE */
        result = SetColorTemp_G_post_offset_onSource(colorTempValue, 0, (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }
    UT_LOG("Out %s",__FUNCTION__);

}

/**
 * @brief Validate GetColorTemp_G_post_offset_onSource() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 145@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetColorTemp_G_post_offset_onSource() -  Retrieve the current ColorTemp G_post_offset_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t| tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemp_G_post_offset_onSource() -  Retrieve the current ColorTemp G_post_offset_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the ColorTemperature, ColorTempSourceOffset sections of test specific config file and validate with above value | tvColorTemp_t, int *, tvColorTempSourceOffset_t| tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetColorTemp_G_post_offset_onSource (void)
{
    gTestID = 145;                                    /* It must be 145 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    int gpostoffset = -1;
    int gpostoffsetRetry = -1;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetColorTemp_G_post_offset_onSource and expectinging the API to return success */
    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    result = GetColorTemp_G_post_offset_onSource(colorTempValue,&gpostoffset,(tvColorTempSourceOffset_t) HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_TRUE( (gpostoffset >= 0 && gpostoffset < 2048));

    /* Step 03: Calling tvsettings GetColorTemp_G_post_offset_onSource and expectinging the API to return success */
    result = GetColorTemp_G_post_offset_onSource(colorTempValue,&gpostoffsetRetry,(tvColorTempSourceOffset_t) HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(gpostoffset,gpostoffsetRetry);

    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < (colorTempCount); i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", i);
        colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < MAX_OFFSET; j++ )
        {
            result = GetColorTemp_G_post_offset_onSource(colorTempValue, &gpostoffset, (tvColorTempSourceOffset_t) j );
            UT_ASSERT_EQUAL(result, tvERROR_NONE);
            UT_ASSERT_TRUE( (gpostoffset >= 0 && gpostoffset < 2048));
        }
    }

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetColorTemp_G_post_offset_onSource() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 146@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetColorTemp_G_post_offset_onSource() -  Retrieve current TV ColorTemp G_post_offset_onSource even before TvInit() | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemp_G_post_offset_onSource() -   Retrieve current TV ColorTemp G_post_offset_onSource with max range color temp| tvColorTemp_MAX, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetColorTemp_G_post_offset_onSource() -   Retrieve current TV ColorTemp G_post_offset_onSource with less range color temp |  -1, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetColorTemp_G_post_offset_onSource() -   Retrieve current TV ColorTemp G_post_offset_onSource invalid gpostoffset  by looping through all the values of colortemp and SourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file |  tvColorTemp_t, NULL, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call GetColorTemp_G_post_offset_onSource() -   Retrieve current TV ColorTemp G_post_offset_onSource invalid SourceId by looping through all the values of colortemp from the ColorTemperature section of test specific config file |  tvColorTemp_t, int *, -2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call GetColorTemp_G_post_offset_onSource() -   Retrieve current TV ColorTemp G_post_offset_onSource invalid SourceId by looping through all the values of colortemp from the ColorTemperature section of test specific config file |  tvColorTemp_t, int *, OFFSET_MAX | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call GetColorTemp_G_post_offset_onSource() -   Retrieve the G_post_offset_onSource for a valid value of TV ColorTemp but not supported by the platform by looping through the ColorTemperature section of test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call GetColorTemp_G_post_offset_onSource() -   Retrieve the G_post_offset_onSource for a valid value of SourceId but not supported by the platform by looping through the ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 11 | call GetColorTemp_G_post_offset_onSource() -  Retrieve current TV ColorTemp G_post_offset_onSource valid arguments | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetColorTemp_G_post_offset_onSource (void)
{
    gTestID = 146;                                    /* It must be 146 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    int gpostoffset = -1;
    int sourceOffset = -1;
    bool platformFlag = false;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetColorTemp_G_post_offset_onSource and expectinging the API to return tvERROR_INVALID_STATE */
        result = GetColorTemp_G_post_offset_onSource(colorTempValue, &gpostoffset, (tvColorTempSourceOffset_t)HDMI_OFFSET);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetColorTemp_G_post_offset_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_G_post_offset_onSource(tvColorTemp_MAX,&gpostoffset, (tvColorTempSourceOffset_t)HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings GetColorTemp_G_post_offset_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_G_post_offset_onSource((tvColorTemp_t)-1,&gpostoffset, (tvColorTempSourceOffset_t)HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings GetColorTemp_G_post_offset_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_G_post_offset_onSource(colorTempValue, NULL, (tvColorTempSourceOffset_t)HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings GetColorTemp_G_post_offset_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_G_post_offset_onSource(colorTempValue, &gpostoffset, (tvColorTempSourceOffset_t) MAX_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings GetColorTemp_G_post_offset_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_G_post_offset_onSource(colorTempValue, &gpostoffset, (tvColorTempSourceOffset_t) -2);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings GetColorTemp_G_post_offset_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < tvColorTemp_MAX; i++)
    {
        platformFlag = false;
        for (unsigned int j = 0; j < colorTempCount ; j++ )
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", j);
            colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(colorTempValue == (tvColorTemp_t)i)
            {
                platformFlag = true;
                break;
            }
        }
        if(!platformFlag)
        {
            result = GetColorTemp_G_post_offset_onSource((tvColorTemp_t)i ,&gpostoffset, (tvColorTempSourceOffset_t)HDMI_OFFSET );
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }




    /* Step 09: Calling tvsettings GetColorTemp_G_post_offset_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    for (unsigned int i = 0; i < MAX_OFFSET; i++)
    {
        platformFlag = false;
        for (unsigned int j = 0; j < MAX_OFFSET ; j++ )
        {
            if(j == (tvColorTempSourceOffset_t)i)
            {
                platformFlag = true;
                break;
            }
        }
        if(!platformFlag)
        {
            result = GetColorTemp_G_post_offset_onSource(colorTempValue ,&gpostoffset, (tvColorTempSourceOffset_t)i);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 10: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 11: Calling tvsettings GetColorTemp_G_post_offset_onSource and expectinging the API to return tvERROR_INVALID_STATE */
        result = GetColorTemp_G_post_offset_onSource(colorTempValue, &gpostoffset, (tvColorTempSourceOffset_t)sourceOffset);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetColorTemp_B_post_offset_onSource() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 147@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -   Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file| tvColorTemp_t, -1024, tvColorTempSourceOffset_t, 0 | tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file| tvColorTemp_t, 1023, tvColorTempSourceOffset_t, 0 | tvERROR_NONE | Should Pass |
 * | 04 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file| tvColorTemp_t, 500, tvColorTempSourceOffset_t, 0 | tvERROR_NONE | Should Pass |
 * | 05 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file| tvColorTemp_t, -1024, tvColorTempSourceOffset_t, 1 | tvERROR_NONE | Should Pass |
 * | 06 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file| tvColorTemp_t, 1023, tvColorTempSourceOffset_t, 1 | tvERROR_NONE | Should Pass |
 * | 07 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file| tvColorTemp_t, 500, tvColorTempSourceOffset_t, 1 | tvERROR_NONE | Should Pass |
 * | 08 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetColorTemp_B_post_offset_onSource (void)
{
    gTestID = 147;                                    /* It must be 147 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02 - 07: Calling tvsettings SetColorTemp_B_post_offset_onSource and the API to return success */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < (colorTempCount); i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", i);
        colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < MAX_OFFSET; j++ )
        {
            for (unsigned int k = 0; k < 2; k++ )   //(0 -set 1-save)
            {
                result = SetColorTemp_B_post_offset_onSource(colorTempValue,-1024, (tvColorTempSourceOffset_t)j, k);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);

                result = SetColorTemp_B_post_offset_onSource(colorTempValue,1023, (tvColorTempSourceOffset_t)j, k);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);

                result = SetColorTemp_B_post_offset_onSource(colorTempValue,500, (tvColorTempSourceOffset_t)j, k);
                UT_ASSERT_EQUAL(result, tvERROR_NONE);
            }
        }
    }

    /* Step 08: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetColorTemp_B_post_offset_onSource() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 148@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetColorTemp_B_post_offset_onSource() - Set the TV ColorTemp B_post_offset_onSource even before TvInit() | tvColorTemp_t, -1024, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource with max range | tvColorTemp_Max, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource with less than the lower range | -1, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource invalid max range of bpostoffset by looping through all the values of colortemp and SourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, -1025, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource invalid less than the lower range of bpostoffset by looping through all the values of colortemp and SourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, 1025, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource invalid sourceId flag with by looping through all the values of colortemp from the ColorTemperature section of test specific config file | tvColorTemp_t, int, OFFSET_MAX, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource invalid sourceId flag with by looping through all the values of colortemp from the ColorTemperature section of test specific config file | tvColorTemp_t, int, -2, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource invalid saveonly flag by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, int, tvColorTempSourceOffset_t, -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource invalid saveonly flag by looping through all the values of colortemp and sourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, int, tvColorTempSourceOffset_t, 2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource with valid value of colortemp but not supported by the platform by looping through the ColorTemperature section of test specific config file | tvColorTemp_t, int, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource with valid value of sourceId but not supported by the platform by looping through the ColorTempSourceOffset section of test specific config file | tvColorTemp_t, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 13 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 14 | call SetColorTemp_B_post_offset_onSource() -  Set the TV ColorTemp B_post_offset_onSource with valid input after TvTerm() | tvColorTemp_t, 1024, tvColorTempSourceOffset_t, 1 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetColorTemp_B_post_offset_onSource (void)
{
    gTestID = 148;                                    /* It must be 148 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool platformFlag = false;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetColorTemp_B_post_offset_onSource and expecting the API to return tvERROR_INVALID_STATE */
        result = SetColorTemp_B_post_offset_onSource(colorTempValue, 0, (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetColorTemp_B_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_B_post_offset_onSource(tvColorTemp_MAX,0,  (tvColorTempSourceOffset_t) HDMI_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetColorTemp_B_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_B_post_offset_onSource((tvColorTemp_t)-1, 0,  (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SetColorTemp_B_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_B_post_offset_onSource(colorTempValue, -1025 ,(tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SetColorTemp_B_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_B_post_offset_onSource(colorTempValue, 1025 , (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SetColorTemp_B_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_B_post_offset_onSource(colorTempValue,0, (tvColorTempSourceOffset_t)MAX_OFFSET, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings SetColorTemp_B_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_B_post_offset_onSource(colorTempValue,0, (tvColorTempSourceOffset_t) -2, 0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings SetColorTemp_B_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_B_post_offset_onSource(colorTempValue,0, (tvColorTempSourceOffset_t) HDMI_OFFSET, 2);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 10: Calling tvsettings SetColorTemp_B_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
    result = SetColorTemp_B_post_offset_onSource(colorTempValue,0,(tvColorTempSourceOffset_t) HDMI_OFFSET, -1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 11: Calling tvsettings SetColorTemp_B_post_offset_onSource and the API to return success */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < tvColorTemp_MAX; i++)
    {
        platformFlag = false;
        for (unsigned int j = 0; j < colorTempCount ; j++ )
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", j);
            colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(colorTempValue == (tvColorTemp_t)i)
            {
                platformFlag = true;
                break;
            }
        }
        if(!platformFlag)
        {
            result = SetColorTemp_B_post_offset_onSource((tvColorTemp_t)i , 0,\
                    (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 12: Calling tvsettings SetColorTemp_B_post_offset_onSource and the API to return success */
    for (unsigned int i = 0; i < MAX_OFFSET; i++)
    {
        platformFlag = false;
        for (unsigned int j = 0; j < MAX_OFFSET ; j++ )
        {
            if(j == (tvColorTempSourceOffset_t)i)
            {
                platformFlag = true;
                break;
            }
        }
        if(!platformFlag)
        {
            result = SetColorTemp_B_post_offset_onSource(colorTempValue ,0,\
                    (tvColorTempSourceOffset_t)i, 0);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

        }
    }

    /* Step 13: Calling tvsettings TvTerm and the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 14: Calling tvsettings SetColorTemp_B_post_offset_onSource and the API to return tvERROR_INVALID_STATE */
        result = SetColorTemp_B_post_offset_onSource(colorTempValue, 0, (tvColorTempSourceOffset_t)HDMI_OFFSET, 0);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetColorTemp_B_post_offset_onSource() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 149@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetColorTemp_B_post_offset_onSource() -  Retrieve the current ColorTemp B_post_offset_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the ColorTemperature, ColorTempSourceOffset sections of test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t| tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemp_B_post_offset_onSource() -  Retrieve the current ColorTemp B_post_offset_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the ColorTemperature, ColorTempSourceOffset sections of test specific config file and validate with above value | tvColorTemp_t, int *, tvColorTempSourceOffset_t| tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetColorTemp_B_post_offset_onSource (void)
{
    gTestID = 149;                                    /* It must be 149 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    int bpostoffset = -1;
    int bpostoffsetRetry = -1;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetColorTemp_B_post_offset_onSource and expectinging the API to return success */
    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    result = GetColorTemp_B_post_offset_onSource(colorTempValue,&bpostoffset, (tvColorTempSourceOffset_t) HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_TRUE( (bpostoffset >= 0 && bpostoffset < 2048));

    /* Step 03: Calling tvsettings GetColorTemp_B_post_offset_onSource and expectinging the API to return success */
    result = GetColorTemp_B_post_offset_onSource(colorTempValue,&bpostoffsetRetry,(tvColorTempSourceOffset_t) HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(bpostoffset,bpostoffsetRetry);

    /* Step 04: Calling tvsettings GetColorTemp_B_post_offset_onSource and expectinging the API to return success */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < (colorTempCount); i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", i);
        colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < MAX_OFFSET; j++ )
        {

            result = GetColorTemp_B_post_offset_onSource(colorTempValue, &bpostoffset, (tvColorTempSourceOffset_t)j );
            UT_ASSERT_EQUAL(result, tvERROR_NONE);
            UT_ASSERT_TRUE( (bpostoffset >= 0 && bpostoffset < 2048));

        }
    }

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetColorTemp_B_post_offset_onSource() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 150@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetColorTemp_B_post_offset_onSource() -  Retrieve current TV ColorTemp B_post_offset_onSource even before TvInit() | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemp_B_post_offset_onSource() -   Retrieve current TV ColorTemp B_post_offset_onSource with max range color temp| tvColorTemp_MAX, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetColorTemp_B_post_offset_onSource() -   Retrieve current TV ColorTemp B_post_offset_onSource with less range color temp |  -1, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetColorTemp_B_post_offset_onSource() -   Retrieve current TV ColorTemp B_post_offset_onSource invalid bpostoffset  by looping through all the values of colortemp and SourceId from the ColorTemperature, ColorTempSourceOffset sections of test specific config file |  tvColorTemp_t, NULL, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call GetColorTemp_B_post_offset_onSource() -   Retrieve current TV ColorTemp B_post_offset_onSource invalid SourceId by looping through all the values of colortemp from the ColorTemperature section of test specific config file |  tvColorTemp_t, int *, -2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call GetColorTemp_B_post_offset_onSource() -   Retrieve current TV ColorTemp B_post_offset_onSource invalid SourceId by looping through all the values of colortemp from the ColorTemperature section of test specific config file |  tvColorTemp_t, int *, OFFSET_MAX | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call GetColorTemp_B_post_offset_onSource() -   Retrieve the B_post_offset_onSource for a valid value of TV ColorTemp but not supported by the platform by looping through the ColorTemperature section of test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call GetColorTemp_B_post_offset_onSource() -   Retrieve the B_post_offset_onSource for a valid value of SourceId but not supported by the platform by looping through the ColorTempSourceOffset section of test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 11 | call GetColorTemp_B_post_offset_onSource() -  Retrieve current TV ColorTemp B_post_offset_onSource valid arguments | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetColorTemp_B_post_offset_onSource (void)
{
    gTestID = 150;                                    /* It must be 150 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    int bpostoffset = -1;
    int sourceOffset = -1;
    bool platformFlag = false;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetColorTemp_B_post_offset_onSource and expectinging the API to return tvERROR_INVALID_STATE */
        result = GetColorTemp_B_post_offset_onSource(colorTempValue, &bpostoffset, (tvColorTempSourceOffset_t)HDMI_OFFSET);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetColorTemp_B_post_offset_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_B_post_offset_onSource(tvColorTemp_MAX,&bpostoffset, (tvColorTempSourceOffset_t) HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings GetColorTemp_B_post_offset_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_B_post_offset_onSource((tvColorTemp_t)-1,&bpostoffset, (tvColorTempSourceOffset_t) HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings GetColorTemp_B_post_offset_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_B_post_offset_onSource(colorTempValue, NULL, (tvColorTempSourceOffset_t) HDMI_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings GetColorTemp_B_post_offset_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_B_post_offset_onSource(colorTempValue, &bpostoffset, (tvColorTempSourceOffset_t) MAX_OFFSET);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings GetColorTemp_B_post_offset_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetColorTemp_B_post_offset_onSource(colorTempValue, &bpostoffset, (tvColorTempSourceOffset_t) -2);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings GetColorTemp_B_post_offset_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < tvColorTemp_MAX; i++)
    {
        platformFlag = false;
        for (unsigned int j = 0; j < colorTempCount ; j++ )
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", j);
            colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(colorTempValue == (tvColorTemp_t)i)
            {
                platformFlag = true;
                break;
            }
        }
        if(!platformFlag)
        {
            result = GetColorTemp_B_post_offset_onSource((tvColorTemp_t)i ,&bpostoffset, (tvColorTempSourceOffset_t)HDMI_OFFSET );
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 09: Calling tvsettings GetColorTemp_B_post_offset_onSource and expectinging the API to return tvERROR_INVALID_PARAM */
    for (unsigned int i = 0; i < MAX_OFFSET; i++)
    {
        platformFlag = false;
        for (unsigned int j = 0; j < MAX_OFFSET ; j++ )
        {
            if(j == (tvColorTempSourceOffset_t)i)
            {
                platformFlag = true;
                break;
            }
        }
        if(!platformFlag)
        {
            result = GetColorTemp_B_post_offset_onSource(colorTempValue ,&bpostoffset, (tvColorTempSourceOffset_t)i);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }


    /* Step 10: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 11: Calling tvsettings GetColorTemp_B_post_offset_onSource and expectinging the API to return tvERROR_INVALID_STATE */
        result = GetColorTemp_B_post_offset_onSource(colorTempValue, &bpostoffset, (tvColorTempSourceOffset_t)sourceOffset);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate EnableWBCalibrationMode() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 151@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call EnableWBCalibrationMode() -  Enable the WB CalibrationMode with valid argument| true | tvERROR_NONE | Should Pass |
 * | 03 | call EnableWBCalibrationMode() -  Disable the WB CalibrationMode with valid argument| false | tvERROR_NONE | Should Pass |
 * | 04 | call EnableWBCalibrationMode() -  Enable the WB CalibrationMode with valid argument| true | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_EnableWBCalibrationMode (void)
{
    gTestID = 151;                                    /* It must be 151 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings to Set the EnableWBCalibrationMode for value true and the API to return success */
    result = EnableWBCalibrationMode(true);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the EnableWBCalibrationMode for value true and the API to return success */
    result = EnableWBCalibrationMode(false);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings to Set the EnableWBCalibrationMode for value true and the API to return success */
    result = EnableWBCalibrationMode(true);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate EnableWBCalibrationMode() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 152@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call EnableWBCalibrationMode() - Enable WB Calibration Mode even before TvInit() | true | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call EnableWBCalibrationMode() -  Enable WB Calibration Mode with valid input | true | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call EnableWBCalibrationMode() -  Enable WB Calibration Mode with valid input after TvTerm() | false | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_EnableWBCalibrationMode (void)
{
    gTestID = 152;                                    /* It must be 152 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings to Set the EnableWBCalibrationMode for value true and the API to return tvERROR_INVALID_STATE */
        result = EnableWBCalibrationMode(true);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the EnableWBCalibrationMode for value true and the API to return success */
    result = EnableWBCalibrationMode(true);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings to Set the EnableWBCalibrationMode for value true and the API to return tvERROR_INVALID_STATE */
        result = EnableWBCalibrationMode(true);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetCurrentWBCalibrationMode() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 153@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetCurrentWBCalibrationMode() -  Retrieve the current WB Calibration Mode with valid argument |bool *| tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentWBCalibrationMode() -  Retrieve the current WB Calibration Mode with valid argument and validate with above value | bool * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetCurrentWBCalibrationMode (void)
{
    gTestID = 153;                                    /* It must be 153 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool calibrationMode = false;
    bool calibrationModeRetry = false;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings to Set the GetCurrentWBCalibrationMode for value true and the API to return success */
    result = GetCurrentWBCalibrationMode(&calibrationMode);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the GetCurrentWBCalibrationMode for value true and the API to return success */
    result = GetCurrentWBCalibrationMode(&calibrationModeRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(calibrationMode,calibrationModeRetry);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetCurrentWBCalibrationMode() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 154@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetCurrentWBCalibrationMode() -   Retrieve current WB Calibration Mode even before TvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentWBCalibrationMode() -  Retrieve current WB Calibration Mode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetCurrentWBCalibrationMode() -  Retrieve current WB Calibration Mode valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetCurrentWBCalibrationMode (void)
{
    gTestID = 154;                                    /* It must be 154 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool calibrationMode = false;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings to Set the GetCurrentWBCalibrationMode for value true and the API to return tvERROR_INVALID_STATE */
        result = GetCurrentWBCalibrationMode(&calibrationMode);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the GetCurrentWBCalibrationMode for value true and the API to return success */
    result = GetCurrentWBCalibrationMode(&calibrationMode);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings to Set the GetCurrentWBCalibrationMode for value true and the API to return tvERROR_INVALID_STATE */
        result = GetCurrentWBCalibrationMode(&calibrationMode);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetGammaTable() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 155@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetGammaTable() -  Set the TV GammaTable with valid arguments for the pData_R, pData_G, pData_B values | unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetGammaTable (void)
{
    gTestID = 155;                                    /* It must be 155 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    short unsigned pData_R_limit[] = {0, 100, 1023};
    short unsigned pData_G_limit[] = {0, 100, 1023};
    short unsigned pData_B_limit[] = {0, 100, 1023};
    unsigned short  size =3;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SetGammaTable for all the valid arguments of colortemp and expecting the API to return success */
    result = SetGammaTable(pData_R_limit,pData_G_limit,pData_B_limit,size);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetGammaTable() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 156@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetGammaTable() - Set the TV GammaTable even before TvInit() | unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetGammaTable() -   Set the TV GammaTable with invalid input | NULL, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetGammaTable() -   Set the TV GammaTable with invalid input | unsigned short *, NULL, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetGammaTable() -   Set the TV GammaTable with invalid input | unsigned short *, unsigned short *, NULL, 256| tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetGammaTable() -   Set the TV GammaTable with invalid input for few elements of the array | 1025, unsigned short *, unsigned short *, 256| tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SetGammaTable() -   Set the TV GammaTable with invalid input for few elements of the array | unsigned short *, 1025, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SetGammaTable() -   Set the TV GammaTable with invalid input for few elements of the array | unsigned short *, unsigned short *, 1025, 256 | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SetGammaTable() -   Set the TV GammaTable with invalid input | unsigned short *, unsigned short *, unsigned short *, -1| tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SetGammaTable() -   Set the TV GammaTable with invalid input | unsigned short *, unsigned short *, unsigned short *, 257| tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 12 | call SetGammaTable() -  Set the TV GammaTable with valid input after TvTerm() | unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetGammaTable (void)
{
    gTestID = 156;                                    /* It must be 156 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    unsigned short pData_R_limit[] = {0, 100, 1023};
    unsigned short pData_G_limit[] = {0, 100, 1023};
    unsigned short pData_B_limit[] = {0, 100, 1023};

    unsigned short pData_R_limit_error2[] = {1025, 100, 1023};
    unsigned short pData_G_limit_error2[] = {0, 1025, 1023};
    unsigned short pData_B_limit_error2[] = {0, 100, 1025};

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetGammaTable for all the valid arguments of colortemp and expecting the API to return success */
        result = SetGammaTable(pData_R_limit, pData_G_limit, pData_B_limit, 256);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetGammaTable for all the valid arguments of colortemp and expecting the API to return success */
    result = SetGammaTable(NULL,pData_G_limit,pData_B_limit,256);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetGammaTable and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetGammaTable(pData_R_limit,NULL,pData_B_limit,256);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SetGammaTable and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetGammaTable(pData_R_limit,pData_G_limit,NULL,256);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SetGammaTable and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetGammaTable(pData_R_limit_error2,pData_G_limit,pData_B_limit,256);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SetGammaTable and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetGammaTable(pData_R_limit,pData_G_limit_error2,pData_B_limit,256);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings SetGammaTable and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetGammaTable(pData_R_limit,pData_G_limit,pData_B_limit_error2,256);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings SetGammaTable and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetGammaTable(pData_R_limit,pData_G_limit,pData_B_limit, -1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 10: Calling tvsettings SetGammaTable and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetGammaTable(pData_R_limit,pData_G_limit,pData_B_limit, 257); //MAX size
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 11: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 12: Calling tvsettings SetGammaTable for all the valid arguments of colortemp and expecting the API to return success */
        result = SetGammaTable(pData_R_limit, pData_G_limit, pData_B_limit, 256);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetDefaultGammaTable() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 157@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetDefaultGammaTable() -  Retrieve the current Default GammaTable and validate GammaTable values for the valid colortemp by looping through the ColorTemperature section of test specific config file | tvColorTemp_t ,  unsigned short *,  unsigned short *,  unsigned short *, unsigned short | tvERROR_NONE | Should Pass |
 * | 03 | call GetDefaultGammaTable() -  Retrieve the current GammaTable with valid argument and validate with above value | tvColorTemp_t ,  unsigned short *,  unsigned short *,  unsigned short *, unsigned short | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetDefaultGammaTable (void)
{
    gTestID = 157;                                    /* It must be 157 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    unsigned short pData_R_limit[]={0, 100, 1023};
    unsigned short pData_G_limit[]={0, 100, 1023};
    unsigned short pData_B_limit[]={0, 100, 1023};
    unsigned short  size =3;
    bool bflag = true;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };
    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SetGammaTable for all the valid arguments of colortemp and expecting the API to return success */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < (colorTempCount); i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", i);
        colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
        result = GetDefaultGammaTable(colorTempValue,pData_R_limit,pData_G_limit,pData_B_limit, size);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
        for(int i =0; i <size; i++ )
        {
            if(   (pData_R_limit[i] < 0 ||  pData_R_limit[i] > 1023) || \
                    (pData_G_limit[i] < 0 ||  pData_G_limit[i] > 1023) || \
                    (pData_B_limit[i] < 0 ||  pData_B_limit[i] > 1023) ){

                bflag = false;
                break;
            }
        }

        UT_ASSERT_TRUE((bflag));
    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetDefaultGammaTable() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 158@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetDefaultGammaTable() -  Retrieve current TV Default GammaTable even before TvInit() | tvColorTemp_t , unsigned short *,  unsigned short *,  unsigned short *, unsigned short | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetDefaultGammaTable() -  "pData_R, pData_G, pData_B, size"= valid , "colortemp"= Invalid maxrange | tvColorTemp_MAX ,unsigned short *,  unsigned short *,  unsigned short *, unsigned short | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetDefaultGammaTable() - "pData_R, pData_G, pData_B, size"= valid , "colortemp"= Invalid less than lower range | -1 ,unsigned short *,  unsigned short *,  unsigned short *, unsigned short | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetDefaultGammaTable() -  "colortemp, pData_G, pData_B, size"= valid , "pData_R"= Invalid | tvColorTemp_t , NULL, unsigned short *,  unsigned short *, unsigned short | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call GetDefaultGammaTable() -  "colortemp, pData_R, pData_B, size"= valid , "pData_G"= Invalid | tvColorTemp_t ,unsigned short *,NULL,  unsigned short *, unsigned short| tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call GetDefaultGammaTable() -  "colortemp, pData_R, pData_G, size"= valid , "pData_B"= Invalid | tvColorTemp_t ,unsigned short *,unsigned short *, NULL, unsigned short | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call GetDefaultGammaTable() -  "colortemp, pData_R, pData_G"= valid , "size"= Invalid | tvColorTemp_t ,unsigned short *,unsigned short *, NULL, unsigned short | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call GetDefaultGammaTable() -  Retrieve current TV Default GammaTable State with valid colortemp value but not supported by the platform by looping through the ColorTemperature section of test specific config file | tvColorTemp_t , unsigned short *,  unsigned short *, unsigned short *,  unsigned short | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 11 | call GetDefaultGammaTable() -  Retrieve current TV Default GammaTable State valid arguments |tvColorTemp_t ,  unsigned short *,  unsigned short *,  unsigned short *, unsigned short | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetDefaultGammaTable (void)
{
    gTestID = 158;                                    /* It must be 158 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    unsigned short pData_R_limit[] ={0, 100, 1023};
    unsigned short pData_G_limit[] ={0, 100, 1023};
    unsigned short pData_B_limit[]={0, 100, 1023};
    unsigned short  size = 3;
    bool platformFlag = false;
    tvError_t result = tvERROR_NONE ;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetDefaultGammaTable before TvInit and expecting the API to return tvERROR_INVALID_STATE */
        result = GetDefaultGammaTable(colorTempValue, pData_R_limit, pData_G_limit, pData_B_limit, size);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetDefaultGammaTable(-1) and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetDefaultGammaTable((tvColorTemp_t)-1, pData_R_limit,pData_G_limit,pData_B_limit, size);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings GetDefaultGammaTable (tvColorTemp_MAX) and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetDefaultGammaTable((tvColorTemp_t)tvColorTemp_MAX, pData_R_limit,pData_G_limit,pData_B_limit, size);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings GetDefaultGammaTable and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetDefaultGammaTable(colorTempValue,NULL,pData_G_limit,pData_B_limit, size);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings GetDefaultGammaTable and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetDefaultGammaTable(colorTempValue,pData_R_limit,NULL,pData_B_limit, size);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings GetDefaultGammaTable and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetDefaultGammaTable(colorTempValue, pData_R_limit,pData_G_limit,NULL, size);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings GetDefaultGammaTable and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetDefaultGammaTable(colorTempValue,pData_R_limit,pData_G_limit,NULL, -1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings GetDefaultGammaTable and expecting the API to return tvERROR_INVALID_PARAM */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < tvColorTemp_MAX; i++)
    {
        platformFlag = false;
        for (unsigned int j = 0; j < colorTempCount ; j++ )
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", j);
            colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(colorTempValue == (tvColorTemp_t)i)
            {
                platformFlag = true;
                break;
            }
        }
        if(!platformFlag)
        {
            result = GetDefaultGammaTable((tvColorTemp_t)i, \
                    pData_R_limit,pData_G_limit,pData_B_limit, size);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 10: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 11: Calling tvsettings GetDefaultGammaTable after TvTerm and expecting the API to return tvERROR_INVALID_STATE */
        result = GetDefaultGammaTable(colorTempValue, pData_R_limit, pData_G_limit, pData_B_limit, size);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetGammaTable() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 159@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetGammaTable() -  Retrieve the current GammaTable and validate GammaTable values for the valid range 0 to 1023 |  unsigned short *,  unsigned short *,  unsigned short *, unsigned short | tvERROR_NONE | Should Pass |
 * | 03 | call GetGammaTable() -  Retrieve the current GammaTable with valid argument and validate with above value |  unsigned short *,  unsigned short *,  unsigned short *, unsigned short | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetGammaTable (void)
{
    gTestID = 159;                                    /* It must be 159 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    unsigned short pData_R_limit[256]={0};
    unsigned short pData_G_limit[256]={0};
    unsigned short pData_B_limit[256]={0};
    unsigned short pData_R_limit_retry[256]={0};
    unsigned short pData_G_limit_retry[256]={0};
    unsigned short pData_B_limit_retry[256]={0};
    unsigned short  size = 256;
    bool bflag = true;
    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SetGammaTable for all the valid arguments of colortemp and expecting the API to return success */
    result = GetGammaTable(pData_R_limit,pData_G_limit,pData_B_limit, size);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    for(int i =0; i <size;i++ )
    {
        if(   (pData_R_limit[i] < 0 ||  pData_R_limit[i] > 1023) || \
                (pData_G_limit[i] < 0 ||  pData_G_limit[i] > 1023) || \
                (pData_B_limit[i] < 0 ||  pData_B_limit[i] > 1023) ){

            bflag = false;
            break;
        }
    }
    UT_ASSERT_TRUE((bflag));

    /* Step 03: Retrieve tvsettings SetGammaTable for all the valid arguments of colortemp and expecting the API to return success */
    result = GetGammaTable(pData_R_limit_retry,pData_G_limit_retry,pData_B_limit_retry, size);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    for(int i =0; i <size;i++ )
    {
        if( ( pData_R_limit[i] != pData_R_limit_retry[i]) ||  \
                (pData_G_limit[i] != pData_G_limit_retry[i] )|| \
                (pData_B_limit[i] != pData_B_limit_retry[i] ) ){

            bflag = false;
            break;
        }
    }

    UT_ASSERT_TRUE((bflag));

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetGammaTable() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 160@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetGammaTable() -  Retrieve current TV GammaTable State even before TvInit() | unsigned short *,  unsigned short *,  unsigned short *, unsigned short | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetGammaTable() -   "pData_G, pData_B, size"= valid , "pData_R"= Invalid | NULL,  unsigned short *,  unsigned short *, unsigned short | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetGammaTable() -   "pData_R, pData_B, size"= valid , "pData_G"= Invalid | unsigned short *,  NULL, unsigned short *, unsigned short | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetGammaTable() -   "pData_R, pData_G, size"= valid , "pData_B"= Invalid | unsigned short *,  unsigned short *, NULL,  unsigned short | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 07 | call GetGammaTable() -  Retrieve current TV GammaTable State valid arguments | unsigned short *,  unsigned short *,  unsigned short *, unsigned short | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetGammaTable (void)
{
    gTestID = 160;                                    /* It must be 160 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    unsigned short pData_R_limit[]={0, 100, 1023};
    unsigned short pData_G_limit[]={0, 100, 1023};
    unsigned short pData_B_limit[]={0, 100, 1023};
    unsigned short  size = 3;
    tvError_t result = tvERROR_NONE ;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetGammaTable before TvInit and expecting the API to return tvERROR_INVALID_STATE */
        result = GetGammaTable(pData_R_limit, pData_G_limit, pData_B_limit, size);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetGammaTable and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetGammaTable( NULL,pData_G_limit,pData_B_limit, size);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 03: Calling tvsettings GetGammaTable and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetGammaTable(  pData_R_limit,NULL,pData_B_limit, size);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings GetGammaTable and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetGammaTable(pData_R_limit,pData_G_limit,NULL, size);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings GetGammaTable and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetGammaTable(pData_R_limit,pData_G_limit,NULL, -1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 07: Calling tvsettings GetGammaTable and expecting the API to return tvERROR_INVALID_STATE */
        result = GetGammaTable(pData_R_limit, pData_G_limit, pData_B_limit, size);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }
    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveGammaTable() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 161@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SaveGammaTable() -  save the current GammaTable State with valid arguments of colortemp by looping through the ColorTemperature section of test specific config file | tvColorTemp_t , unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveGammaTable (void)
{
    gTestID = 161;                                    /* It must be 161 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    unsigned short pData_R_limit[] = {0, 100, 1023};
    unsigned short pData_G_limit[] = {0, 100, 1023};
    unsigned short pData_B_limit[] = {0, 100, 1023};
    unsigned short size = 3;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SetGammaTable for all the valid arguments of colortemp and expecting the API to return success */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < (colorTempCount); i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", i);
        colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
        result = SaveGammaTable(colorTempValue, pData_R_limit,pData_G_limit,pData_B_limit, size);
        UT_ASSERT_EQUAL(result, tvERROR_NONE)
    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveGammaTable() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 162@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SaveGammaTable() - save the current GammaTable State even before TvInit() | tvColorTemp_t, unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SaveGammaTable() -   save the current GammaTable State with invalid input | tvColorTemp_t, NULL, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SaveGammaTable() -   save the current GammaTable State with invalid input | tvColorTemp_t, unsigned short *, NULL, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SaveGammaTable() -   save the current GammaTable State with invalid input | tvColorTemp_t, unsigned short *, unsigned short *, NULL, 256| tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SaveGammaTable() -   save the current GammaTable State with invalid colortemp with max range | -1 , unsigned short *,  unsigned short *, unsigned short *,  int | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SaveGammaTable() -   save the current GammaTable State with invalid colortemp  less than lower range| tvColorTemp_MAX , unsigned short *,  unsigned short *, unsigned short *,  int | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SaveGammaTable() -   save the current GammaTable State with invalid input for few elements of the array | tvColorTemp_t, 1025,  unsigned short *, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SaveGammaTable() -   save the current GammaTable State with invalid input for few elements of the array | tvColorTemp_t, unsigned short *,  1025, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SaveGammaTable() -   save the current GammaTable State with invalid input for few elements of the array | tvColorTemp_t, unsigned short *,  unsigned short *, 1025, 256 | tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SaveGammaTable() -   save the current GammaTable State with invalid input | tvColorTemp_t, unsigned short *,  unsigned short *, unsigned short *, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call SaveGammaTable() -   save the current GammaTable State with invalid input | tvColorTemp_t, unsigned short *,  unsigned short *, unsigned short *, 257 | tvERROR_INVALID_PARAM | Should Pass |
 * | 13 | call SaveGammaTable() -   save the current GammaTable State with valid colortemp  value but not supported by the platform by looping through the ColorTemperature section of test specific config file | tvColorTemp_t , unsigned short *,  unsigned short *, unsigned short *, unsigned short| tvERROR_INVALID_PARAM | Should Pass |
 * | 14 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 15 | call SaveGammaTable() -  Set the current GammaTable State with valid input after TvTerm() | tvColorTemp_t, unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveGammaTable (void)
{
    gTestID = 162;                                    /* It must be 162 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    unsigned short pData_R_limit[] = {0, 100, 1023};
    unsigned short pData_G_limit[] = {0, 100, 1023};
    unsigned short pData_B_limit[] = {0, 100, 1023};

    unsigned short pData_R_limit_error2[] = {1025, 100, 1023};
    unsigned short pData_G_limit_error2[] = {0, 1025, 1023};
    unsigned short pData_B_limit_error2[] = {0, 100, 1025};
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SaveGammaTable for all the valid arguments of colortemp and expecting the API to return success */
        result = SaveGammaTable(colorTempValue, pData_R_limit, pData_G_limit, pData_B_limit, 256);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SaveGammaTable for all the valid arguments of colortemp and expecting the API to return success */
    result = SaveGammaTable(colorTempValue, NULL,pData_G_limit,pData_B_limit,256);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SaveGammaTable and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveGammaTable(colorTempValue, pData_R_limit,NULL,pData_B_limit,256);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SaveGammaTable and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveGammaTable(colorTempValue,pData_R_limit,pData_G_limit,NULL,256);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SaveGammaTable and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveGammaTable((tvColorTemp_t)-1, pData_R_limit,pData_G_limit,pData_B_limit,256);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SaveGammaTable and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveGammaTable(tvColorTemp_MAX, pData_R_limit,pData_G_limit,pData_B_limit,256);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings SaveGammaTable and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveGammaTable(colorTempValue,pData_R_limit_error2,pData_G_limit,pData_B_limit,256);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings SaveGammaTable and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveGammaTable(colorTempValue,pData_R_limit,pData_G_limit_error2,pData_B_limit,256);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 10: Calling tvsettings SaveGammaTable and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveGammaTable(colorTempValue,pData_R_limit,pData_G_limit,pData_B_limit_error2,256);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 11: Calling tvsettings SaveGammaTable and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveGammaTable(colorTempValue,pData_R_limit,pData_G_limit,pData_B_limit,-1);  //zero size
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 12: Calling tvsettings SaveGammaTable and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveGammaTable(colorTempValue,pData_R_limit,pData_G_limit,pData_B_limit, 257); //MAX size
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 13: Calling tvsettings SaveGammaTable and expecting the API to return success */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < (colorTempCount); i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", i);
        colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);

        for(int j=0; j<tvColorTemp_MAX;j++){

            if(colorTempValue != (tvColorTemp_t)j ){
                result = SaveGammaTable((tvColorTemp_t)j, pData_R_limit,pData_G_limit,pData_B_limit, 256);
                UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
            }
        }

    }

    /* Step 14: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 15: Calling tvsettings SaveGammaTable and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveGammaTable(colorTempValue, pData_R_limit, pData_G_limit, pData_B_limit, 256);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetDvTmaxValue() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 163@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetDvTmaxValue() -  Set the Dv Tmax with valid value | 0 | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call SetDvTmaxValue() -  Reset the Dv Tmax  with another valid value | 5000 | tvERROR_NONE | Should Pass |
 * | 04 | call SetDvTmaxValue() -  Reset the Dv Tmax  with another valid value | 10000 | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetDvTmaxValue (void)
{
    gTestID = 163;                                    /* It must be 163 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SetDvTmaxValue with value 0 and expecting the API to return success */
    result = SetDvTmaxValue(0);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetDvTmaxValue with value 5000 and expecting the API to return success */
    result = SetDvTmaxValue(5000);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings SetDvTmaxValue with value 10000 and expecting the API to return success */
    result = SetDvTmaxValue(10000);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetDvTmaxValue() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 164@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetDvTmaxValue() - Set the Dv Tmax even before TvInit() | 1 | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetDvTmaxValue() -   Set the Dv Tmax with invalid input with less than lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetDvTmaxValue() -   Set the Dv Tmax with invalid input with max range |10001 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call SetDvTmaxValue() -  Set the Dv Tmax with valid input after TvTerm() | 0 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetDvTmaxValue (void)
{
    gTestID = 164;                                    /* It must be 164 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetDvTmaxValue with value 1 and expecting the API to return tvERROR_INVALID_STATE */
        result = SetDvTmaxValue(1);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetDvTmaxValue with value -1 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetDvTmaxValue(-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetDvTmaxValue with value 10001 and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetDvTmaxValue(10001);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 06: Calling tvsettings SetDvTmaxValue with value 0 and expecting the API to return tvERROR_INVALID_STATE */
        result = SetDvTmaxValue(0);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetDvTmaxValue() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 165@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetDvTmaxValue() -  Retrieve the current Dv Tmax Value with valid arguments and validate with range (0 to 10000) | int * | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call GetDvTmaxValue() -  Retrieve the current Dv Tmax Value with valid argument and validate with above value | int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetDvTmaxValue (void)
{
    gTestID = 165;                                    /* It must be 165 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int tvDvTmax = -1;
    int tvDvTmaxRetry = -1;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetDvTmaxValue and expecting the API to return success */
    result = GetDvTmaxValue(&tvDvTmax);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_TRUE((tvDvTmax >= 0 && tvDvTmax <= 10000))

        /* Step 03: Calling tvsettings GetDvTmaxValue and expecting the API to return success */
        result = GetDvTmaxValue(&tvDvTmaxRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(tvDvTmax, tvDvTmaxRetry);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetDvTmaxValue() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 166@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetDvTmaxValue() -  Retrieve current Dv Tmax Value even before TvInit() | int * | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetDvTmaxValue() -   Retrieve current Dv Tmax Value with invalid argument | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetDvTmaxValue() -  Retrieve current Dv Tmax Value State valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetDvTmaxValue (void)
{
    gTestID = 166;                                    /* It must be 166 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int tvDvTmax = -1;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetDvTmaxValue and expecting the API to return tvERROR_INVALID_STATE */
        result = GetDvTmaxValue(&tvDvTmax);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetDvTmaxValue and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetDvTmaxValue(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings GetDvTmaxValue and expecting the API to return tvERROR_INVALID_STATE */
        result = GetDvTmaxValue(&tvDvTmax);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveDvTmaxValue() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 167@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SaveDvTmaxValue() -  Save the current Dv Tmax Value by looping through all the values of ldimstate level and TMax from the LocalDimming section of test specific config file  |  ldimStateLevel_t , int | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveDvTmaxValue (void)
{
    gTestID = 167;                                    /* It must be 167 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    ldimStateLevel_t dimmingLevel = LDIM_STATE_NONBOOST;
    uint32_t dimmingLevelCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SaveDvTmaxValue for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
    dimmingLevelCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/TMAX/DimmingLevel/index");
    for (unsigned int j = 0; j < dimmingLevelCount; j++)
    {

        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/TMAX/DimmingLevel/index/%d", j);
        dimmingLevel = (ldimStateLevel_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        result = SaveDvTmaxValue(dimmingLevel, 0);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);

        result = SaveDvTmaxValue(dimmingLevel, 1000);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);

        result = SaveDvTmaxValue(dimmingLevel, 10000);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);

    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveDvTmaxValue() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 168@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SaveDvTmaxValue() -  save current Dv Tmax Value even before TvInit() | ldimStateLevel_t, int | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SaveDvTmaxValue() -  Save current Dv Tmax Value with invalid source input with max range| LDIM_STATE_MAX, int | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SaveDvTmaxValue() -  Save current Dv Tmax Value with invalid source input less than the lower range| -1 , int | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SaveDvTmaxValue() -  Save current Dv Tmax Value with invalid TMax less than the lower range| ldimStateLevel_t, -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SaveDvTmaxValue() -  Save current Dv Tmax Value with invalid pqmode with max range | ldimStateLevel_t, 10001 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SaveDvTmaxValue() -  Save current Dv Tmax Value with valid value of  ldimstate level and TMax value but not supported by the platform by looping through the LocalDimming section of test specific config file|ldimStateLevel_t ,int | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 09 | call SaveDvTmaxValue() -  save current Dv Tmax Value valid arguments | ldimStateLevel_t ,int | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveDvTmaxValue (void)
{
    gTestID = 168;                                    /* It must be 168 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool flag = false;
    ldimStateLevel_t dimmingLevel = LDIM_STATE_NONBOOST;
    uint32_t dimmingLevelCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    dimmingLevel = (ldimStateLevel_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/TMAX/DimmingLevel/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SaveDvTmaxValue and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveDvTmaxValue(dimmingLevel, 500);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SaveDvTmaxValue and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveDvTmaxValue(LDIM_STATE_MAX,500);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SaveDvTmaxValue and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveDvTmaxValue((ldimStateLevel_t)-1, 500);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SaveDvTmaxValue and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveDvTmaxValue(dimmingLevel, -1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SaveDvTmaxValue and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveDvTmaxValue(dimmingLevel, 10001);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SaveDvTmaxValue and expecting the API to return tvERROR_INVALID_PARAM */

    dimmingLevelCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/TMAX/DimmingLevel/index");
    for(int i =LDIM_STATE_NONBOOST ; i < LDIM_STATE_MAX; i++){
        flag = false;
        for(int j =0 ; j < dimmingLevelCount; j++){
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/TMAX/DimmingLevel/index/%d", j);
            dimmingLevel = (ldimStateLevel_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(dimmingLevel == i)
            {
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            result = SaveDvTmaxValue((ldimStateLevel_t)i, 1000);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 08: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    dimmingLevel = (ldimStateLevel_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/TMAX/DimmingLevel/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 09: Calling tvsettings SaveDvTmaxValue and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveDvTmaxValue(dimmingLevel, 500);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetSupportedComponentColor() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 169@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetSupportedComponentColor() -  Retrieve the current Supported ComponentColor and validate Supported ComponentColor by looping through the ComponentColor section of test specific config file | int * | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call GetSupportedComponentColor() -  Retrieve the current Supported ComponentColor with valid argument and validate with above value | int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetSupportedComponentColor (void)
{
    gTestID = 169;                                    /* It must be 169 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    int tvComponentColor =0, tvComponentColor_bk =0;
    int tvComponentColorRetry =0;
    uint32_t componentColorCount = 0;
    tvDataComponentColor_t componentColor = tvDataColor_NONE;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };


    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetSupportedComponentColor and expectinging the API to return success */
    result = GetSupportedComponentColor(&tvComponentColor);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    tvComponentColor_bk = tvComponentColor;
    componentColorCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/SupportedComponentColor");
    for (unsigned int i = 0; i < componentColorCount; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/SupportedComponentColor/%d", i);
        componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        if(componentColor & tvComponentColor_bk)
        {
            tvComponentColor_bk &= (~componentColor);
        }
    }

    UT_ASSERT_FALSE((tvComponentColor_bk));

    /* Step 03: Calling tvsettings GetSupportedComponentColor and expectinging the API to return success */
    result = GetSupportedComponentColor(&tvComponentColorRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(tvComponentColorRetry, tvComponentColor);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetSupportedComponentColor() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 170@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetSupportedComponentColor() -  Retrieve current TV Supported ComponentColor even before TvInit() | int * | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetSupportedComponentColor() -  Retrieve supported component colortemperature with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetSupportedComponentColor() -  Retrieve current TV Supported ComponentColor valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetSupportedComponentColor (void)
{
    gTestID = 170;                                    /* It must be 170 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int tvComponentColor = 0x00;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetSupportedComponentColor and expecting the API to return tvERROR_INVALID_STATE */
        result = GetSupportedComponentColor(&tvComponentColor);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetSupportedComponentColor and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetSupportedComponentColor(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings GetSupportedComponentColor and expecting the API to return tvERROR_INVALID_STATE */
        result = GetSupportedComponentColor(&tvComponentColor);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetCurrentComponentSaturation() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 171@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetCMSState() - Set the CMSState with valid value | true | tvERROR_NONE | Should Pass |
 * | 03 | call SetCurrentComponentSaturation() -  Set the TV component saturation by looping through all the values of saturation from ComponentColor section of test specific config file| tvDataComponentColor_t  ,0 | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 04 | call SetCurrentComponentSaturation() -  Set the TV component saturation by looping through all the values of saturation from ComponentColor section of test specific config file| tvDataComponentColor_t ,100 | tvERROR_NONE | Should Pass |
 * | 05 | call SetCurrentComponentSaturation() -  Set the TV component saturation by looping through all the values of saturation from ComponentColor section of test specific config file| tvDataComponentColor_t  ,50 | tvERROR_NONE | Should Pass |
 * | 06 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetCurrentComponentSaturation (void)
{
    gTestID = 171;                                    /* It must be 171 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    uint32_t componentColorCount = 0;
    tvDataComponentColor_t componentColor = tvDataColor_NONE;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings to Set the SetCMSState for value true and the API to return success */
    result = SetCMSState(true);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    componentColorCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/SupportedComponentColor");
    for (unsigned int i=0; i< componentColorCount; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/SupportedComponentColor/%d", i);
        componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        /* Step 03: Calling tvsettings SetCurrentComponentSaturation and expecting the API to return tvERROR_NONE */
        result = SetCurrentComponentSaturation(componentColor,0);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);

        /* Step 04: Calling tvsettings SetCurrentComponentSaturation and expecting the API to return tvERROR_NONE */
        result = SetCurrentComponentSaturation(componentColor,100);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);

        /* Step 05: Calling tvsettings SetCurrentComponentSaturation and expecting the API to return tvERROR_NONE */
        result = SetCurrentComponentSaturation(componentColor,50);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
    }

    /* Step 06: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetCurrentComponentSaturation() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 172@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetCurrentComponentSaturation() - Set the TV Current Component Saturation even before TvInit() | tvDataComponentColor_t ,  int | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetCurrentComponentSaturation() -  Set the TV Current Component Saturation with max range by looping through all the values from ComponentColor section of test specific config file  | tvDataComponentColor_t,  101 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetCurrentComponentSaturation() -  Set the TV Current Component Saturation with less than the lower range by looping through all the values from ComponentColor section oftest specific config file | tvDataComponentColor_t,  -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetCurrentComponentSaturation() -  Set the TV Current Component Saturation with max range DataComponentColor| tvDataColor_MAX, 10 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetCurrentComponentSaturation() -  Set the TV Current Component Saturation with less than the lower range of DataComponentColor| -1, 10 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SetCurrentComponentSaturation() -  Set the TV Current Component Saturation with valid value of DataComponentColor but not supported by the platform by looping through the ComponentColor section of test specific config file | tvDataComponentColor_t, 10 | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 09 | call SetCurrentComponentSaturation() -  Set the TV Current Component Saturation with valid input after TvTerm() | tvDataComponentColor_t ,  int | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetCurrentComponentSaturation (void)
{
    gTestID = 172;                                    /* It must be 172 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool bModeMatched = false;
    uint32_t componentColorCount = 0;
    tvDataComponentColor_t componentColor = tvDataColor_NONE;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/SupportedComponentColor/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetCurrentComponentSaturation before TvInit and expecting the API to return tvERROR_INVALID_STATE */
        result = SetCurrentComponentSaturation(componentColor, 10);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetCurrentComponentSaturation and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetCurrentComponentSaturation((tvDataComponentColor_t)tvDataColor_MAX ,10);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetCurrentComponentSaturation and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetCurrentComponentSaturation((tvDataComponentColor_t)-1 ,10);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SetCurrentComponentSaturation and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetCurrentComponentSaturation(componentColor ,101);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SetCurrentComponentSaturation and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetCurrentComponentSaturation(componentColor ,-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SetCurrentComponentSaturation and expecting the API to return tvERROR_INVALID_PARAM */
    componentColorCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/SupportedComponentColor");
    for (int i=0; i< tvDataColor_MAX; i++)
    {
        bModeMatched = false;
        for(unsigned int j =0; j < componentColorCount; j++){

            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/SupportedComponentColor/%d", j);
            componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if((tvDataComponentColor_t) componentColor !=(tvDataComponentColor_t) i)
            {
                bModeMatched = true;
                break;
            }
        }
        if(!bModeMatched)
        {
            result = SetCurrentComponentSaturation((tvDataComponentColor_t)i,10);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 08: Calling tvsettings TvTerm and expecting the API to return tvERROR_NONE */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/SupportedComponentColor/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 09: Calling tvsettings SetCurrentComponentSaturation after TvTerm and expecting the API to return tvERROR_INVALID_STATE */
        result = SetCurrentComponentSaturation(componentColor, 10);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }
    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetCurrentComponentSaturation() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 173@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetCurrentComponentSaturation() -  Retrieve the current Component Saturation with valid arguments by looping through all the values of DataComponentColor from ComponentColor section of test specific config file | tvDataComponentColor_t, int * | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call GetCurrentComponentSaturation() -  Retrieve the current Component Saturation with valid argument and validate with above value | tvDataComponentColor_t, int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetCurrentComponentSaturation (void)
{
    gTestID = 173;                                    /* It must be 173 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    int saturation = 0;
    int saturationRetry = 0;
    uint32_t componentColorCount = 0;
    tvDataComponentColor_t componentColor = tvDataColor_NONE;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetCurrentComponentSaturation and expecting the API to return success */
    componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/SupportedComponentColor/0");
    result = GetCurrentComponentSaturation(componentColor,&saturation);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetCurrentComponentSaturation and expecting the API to return success */
    result = GetCurrentComponentSaturation(componentColor,&saturationRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    UT_ASSERT_EQUAL(saturation, saturationRetry);

    for (unsigned int i = 0; i < componentColorCount; ++i)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/SupportedComponentColor/%d", i);
        componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        result = GetCurrentComponentSaturation(componentColor,&saturation);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
        UT_ASSERT_TRUE( (saturation >=0 && saturation <= 100) );
    }

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetCurrentComponentSaturation() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 174@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetCurrentComponentSaturation() -  Retrieve current TV Component Saturation even before TvInit() | tvDataComponentColor_t, int * | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentComponentSaturation() -  Retrieve current TV component saturation with invalid input by looping through all the values of DataComponentColor from ComponentColor section of test specific config file | tvDataComponentColor_t, NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetCurrentComponentSaturation() -  Retrieve current TV component saturation with Max range of DataComponentColor | tvDataComponentColor_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetCurrentComponentSaturation() -  Retrieve current TV component saturation with less than lower range of DataComponentColor  | -1, int * | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 07 | call GetCurrentComponentSaturation() -  Retrieve current TV Component Saturation valid arguments | tvDataComponentColor_t, int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetCurrentComponentSaturation (void)
{
    gTestID = 174;                                    /* It must be 174 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    int saturation = 0;
    bool bModeMatched = false;
    uint32_t componentColorCount = 0;
    tvDataComponentColor_t componentColor = tvDataColor_NONE;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/SupportedComponentColor/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetCurrentComponentSaturation before TvInit and expecting the API to return tvERROR_INVALID_STATE */
        result = GetCurrentComponentSaturation(componentColor, &saturation);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);


    /* Step 03: Calling tvsettings GetCurrentComponentSaturation and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetCurrentComponentSaturation(tvDataColor_MAX,&saturation);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings GetCurrentComponentSaturation and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetCurrentComponentSaturation((tvDataComponentColor_t)-1,&saturation);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings GetCurrentComponentSaturation and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetCurrentComponentSaturation(componentColor,NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    componentColorCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/SupportedComponentColor");
    for(int i = 0; i < tvDataColor_MAX; i++)
    {
        bModeMatched = false;
        for (unsigned int j = 0; j < componentColorCount; ++j)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/SupportedComponentColor/%d", j);
            componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if((tvDataComponentColor_t) componentColor == (tvDataComponentColor_t)i)
            {
                bModeMatched = true;
                break;
            }
        }

        if(!bModeMatched)
        {
            result = GetCurrentComponentSaturation((tvDataComponentColor_t)i ,&saturation);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }


    /* Step 06: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/SupportedComponentColor/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 07 Calling tvsettings GetCurrentComponentSaturation and expectinging the API to return tvERROR_INVALID_STATE */
        result = GetCurrentComponentSaturation(componentColor, &saturation);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetCurrentComponentHue() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 175@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetCMSState() - Set the CMSState with valid value | true | tvERROR_NONE | Should Pass |
 * | 03 | call SetCurrentComponentHue() -  Set the TV component hue by looping through all the values of component hue from ComponentColor section of test specific config file| tvDataComponentColor_t , 0 | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 04 | call SetCurrentComponentHue() -  Set the TV component hue by looping through all the values of component hue from ComponentColor section of test specific config file| tvDataComponentColor_t , 100 | tvERROR_NONE | Should Pass |
 * | 05 | call SetCurrentComponentHue() -  Set the TV component hue by looping through all the values of component hue from ComponentColor section of test specific config file| tvDataComponentColor_t , 50 | tvERROR_NONE | Should Pass |
 * | 06 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetCurrentComponentHue (void)
{
    gTestID = 175;                                    /* It must be 175 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    uint32_t componentColorCount = 0;
    tvDataComponentColor_t componentColor = tvDataColor_NONE;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings to Set the SetCMSState for value true and the API to return success */
    result = SetCMSState(true);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    componentColorCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/SupportedComponentColor");
    for (unsigned int i=0; i<componentColorCount; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/SupportedComponentColor/%d", i);
        componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        /* Step 03: Calling tvsettings SetCurrentComponentHue and expecting the API to return success */
        result = SetCurrentComponentHue(componentColor,0);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);

        /* Step 04: Calling tvsettings SetCurrentComponentHue and expecting the API to return success */
        result = SetCurrentComponentHue(componentColor,100);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);

        /* Step 05: Calling tvsettings SetCurrentComponentHue and expecting the API to return success */
        result = SetCurrentComponentHue(componentColor,50);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
    }

    /* Step 06: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetCurrentComponentHue() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 176@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetCurrentComponentHue() -  Retrieve current TV Current Component Hue even before TvInit() | tvDataComponentColor_t, int | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetCurrentComponentHue() -  Set the TV Current Component Hue with max range by looping through all the values from ComponentColor section of test specific config file | tvDataComponentColor_t,  101 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetCurrentComponentHue() -  Set the TV Current Component Hue with less than the lower range by looping through all the values from ComponentColor section of test specific config file | tvDataComponentColor_t,  -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetCurrentComponentHue() -  Set the TV Current Component Hue with max range DataComponentColor| tvDataColor_MAX, 10 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetCurrentComponentHue() -  Set the TV Current Component Hue with less than the lower range of DataComponentColor| -1, 10 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SetCurrentComponentHue() -  Set the TV Current Component Hue with valid value of DataComponentColor but not supported by the platform by looping through the ComponentColor section of test specific config file| tvDataComponentColor_t, 10 | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 09 | call SetCurrentComponentHue() -  Retrieve current TV Current Component Hue valid arguments | tvDataComponentColor_t, int | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetCurrentComponentHue (void)
{
    gTestID = 176;                                    /* It must be 176 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool bModeMatched = false;
    uint32_t componentColorCount = 0;
    tvDataComponentColor_t componentColor = tvDataColor_NONE;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/SupportedComponentColor/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetCurrentComponentHue before TvInit and expecting the API to return tvERROR_INVALID_STATE */
        result = SetCurrentComponentHue(componentColor, 10);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetCurrentComponentHue and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetCurrentComponentHue((tvDataComponentColor_t)tvDataColor_MAX ,10);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetCurrentComponentHue and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetCurrentComponentHue((tvDataComponentColor_t)-1 ,10);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SetCurrentComponentHue and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetCurrentComponentHue(componentColor ,101);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SetCurrentComponentHue and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetCurrentComponentHue(componentColor ,-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SetCurrentComponentHue and expecting the API to return tvERROR_INVALID_PARAM */
    componentColorCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/SupportedComponentColor");
    for (int i=0; i<tvDataColor_MAX; i++)
    {
        bModeMatched = false;
        for(unsigned int j =0; j < componentColorCount; j++){

            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/SupportedComponentColor/%d", j);
            componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if((tvDataComponentColor_t) componentColor !=(tvDataComponentColor_t) i)
            {
                bModeMatched = true;
                break;
            }
        }
        if(!bModeMatched)
        {
            result = SetCurrentComponentHue((tvDataComponentColor_t)i,10);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 08: Calling tvsettings TvTerm and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/SupportedComponentColor/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 09: Calling tvsettings SetCurrentComponentHue after TvTerm and expecting the API to return tvERROR_INVALID_STATE */
        result = SetCurrentComponentHue(componentColor, 10);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }
    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetCurrentComponentHue() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 177@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetCurrentComponentHue() - Retrieve the current Component Hue with valid arguments by looping through all the values of DataComponentColor from ComponentColor section of test specific config file | tvDataComponentColor_t, int * | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call GetCurrentComponentHue() -  Retrieve the current Component Hue with valid argument and validate with above value | tvDataComponentColor_t, int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetCurrentComponentHue (void)
{
    gTestID = 177;                                    /* It must be 177 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    int Hue = 0;
    int HueRetry = 0;
    uint32_t componentColorCount = 0;
    tvDataComponentColor_t componentColor = tvDataColor_NONE;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetCurrentComponentHue and expecting the API to return success */
    componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/SupportedComponentColor/0");
    result = GetCurrentComponentHue(componentColor,&Hue);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetCurrentComponentHue and expecting the API to return success */
    result = GetCurrentComponentHue(componentColor,&HueRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    UT_ASSERT_EQUAL(Hue, HueRetry);

    componentColorCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/SupportedComponentColor");
    for (unsigned int j = 0; j < componentColorCount; ++j)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/SupportedComponentColor/%d", j);
        componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        result = GetCurrentComponentHue(componentColor,&Hue);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
        UT_ASSERT_TRUE( (Hue >=0 && Hue <= 100));
    }

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetCurrentComponentHue() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 178@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetCurrentComponentHue() -  Retrieve current TV brightness even before TvInit() |tvDataComponentColor_t, int * | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentComponentHue() -  Retrieve current TV component Hue with invalid input by looping through all the values of DataComponentColor from ComponentColor section of test specific config file | tvDataComponentColor_t, NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetCurrentComponentHue() -  Retrieve current TV component Hue with Max range of DataComponentColor | tvDataComponentColor_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetCurrentComponentHue() -  Retrieve current TV component Hue with less than lower range of DataComponentColor  | -1, int * | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 07 | call GetCurrentComponentHue() -  Retrieve current TV brightness valid arguments | tvDataComponentColor_t, int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetCurrentComponentHue (void)
{

    gTestID = 178;                                    /* It must be 178 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    int Hue = 0;
    bool bModeMatched = false;
    uint32_t componentColorCount = 0;
    tvDataComponentColor_t componentColor = tvDataColor_NONE;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/SupportedComponentColor/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetCurrentComponentHue before TvInit and expecting the API to return tvERROR_INVALID_STATE */
        result = GetCurrentComponentHue(componentColor, &Hue);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetCurrentComponentHue and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetCurrentComponentHue(tvDataColor_MAX,&Hue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings GetCurrentComponentHue and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetCurrentComponentHue((tvDataComponentColor_t)-1,&Hue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings GetCurrentComponentHue and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetCurrentComponentHue(componentColor,NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    componentColorCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/SupportedComponentColor");
    for (int i =0; i < tvDataColor_MAX; i++)
    {
        bModeMatched = false;
        for(unsigned int j = 0; j < componentColorCount; ++j){

            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/SupportedComponentColor/%d", j);
            componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if((tvDataComponentColor_t) componentColor == (tvDataComponentColor_t) i)
            {
                bModeMatched = true;
                break;
            }
        }
        if(!bModeMatched)
        {
            result = GetCurrentComponentHue((tvDataComponentColor_t)i ,&Hue);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 06: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/SupportedComponentColor/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 07: Calling tvsettings GetCurrentComponentHue and expectinging the API to return success */
        result = GetCurrentComponentHue(componentColor, &Hue);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetCurrentComponentLuma() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 179@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetCMSState() -  Set the CMSState with valid value | true | tvERROR_NONE | Should Pass |
 * | 03 | call SetCurrentComponentLuma() -  Set the TV component hue by looping through all the values of component Luma from ComponentColor section of test specific config file| tvDataComponentColor_t , 0 | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 04 | call SetCurrentComponentLuma() -  Set the TV component hue by looping through all the values of component Luma from ComponentColor section of test specific config file| tvDataComponentColor_t , 30 | tvERROR_NONE | Should Pass |
 * | 05 | call SetCurrentComponentLuma() -  Set the TV component hue by looping through all the values of component Luma from ComponentColor section of test specific config file| tvDataComponentColor_t , 15 | tvERROR_NONE | Should Pass |* | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetCurrentComponentLuma (void)
{
    gTestID = 179;                                    /* It must be 179 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    uint32_t componentColorCount = 0;
    tvDataComponentColor_t componentColor = tvDataColor_NONE;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings to Set the SetCMSState for value true and the API to return success */
    result = SetCMSState(true);

    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    componentColorCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/SupportedComponentColor");
    for (unsigned int i=0; i<componentColorCount; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/SupportedComponentColor/%d", i);
        componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        /* Step 03: Calling tvsettings SetCurrentComponentLuma and expecting the API to return tvERROR_INVALID_STATE */
        result = SetCurrentComponentLuma(componentColor,0);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);

        /* Step 04: Calling tvsettings SetCurrentComponentLuma and expecting the API to return tvERROR_INVALID_STATE */
        result = SetCurrentComponentLuma(componentColor,30);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);

        /* Step 05: Calling tvsettings SetCurrentComponentLuma and expecting the API to return tvERROR_INVALID_STATE */
        result = SetCurrentComponentLuma(componentColor,15);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
    }

    /* Step 06: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetCurrentComponentLuma() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 180@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetCurrentComponentLuma() -  Retrieve current TV Current Component Luma even before TvInit() | tvDataComponentColor_t, int | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetCurrentComponentLuma() -  Set the TV Current Component Luma with max range by looping through all the values from ComponentColor section of test specific config file | tvDataComponentColor_t,  31 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetCurrentComponentLuma() -  Set the TV Current Component Luma with less than the lower range by looping through all the values from ComponentColor section of test specific config file | tvDataComponentColor_t,  -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetCurrentComponentLuma() -  Set the TV Current Component Luma with max range DataComponentColor| tvDataColor_MAX, 10 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetCurrentComponentLuma() -  Set the TV Current Component Luma with less than the lower range of DataComponentColor| -1, 10 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SetCurrentComponentLuma() -  Set the TV Current Component Lima with valid value of DataComponentColor but not supported by the platform by looping through the config fil| tvDataComponentColor_t, 10 | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 09 | call SetCurrentComponentLuma() -  Retrieve current TV Current Component Luma valid arguments | tvDataComponentColor_t, int | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetCurrentComponentLuma (void)
{
    gTestID = 180;                                    /* It must be 180 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool bModeMatched = false;
    uint32_t componentColorCount = 0;
    tvDataComponentColor_t componentColor = tvDataColor_NONE;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/SupportedComponentColor/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetCurrentComponentLuma before TvInit and expecting the API to return tvERROR_INVALID_STATE */
        result = SetCurrentComponentLuma(componentColor, 10);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetCurrentComponentLuma and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetCurrentComponentLuma((tvDataComponentColor_t)tvDataColor_MAX ,10);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetCurrentComponentLuma and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetCurrentComponentLuma((tvDataComponentColor_t)-1 ,10);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SetCurrentComponentLuma and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetCurrentComponentLuma(componentColor ,31);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SetCurrentComponentLuma and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetCurrentComponentLuma(componentColor ,-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SetCurrentComponentLuma and expecting the API to return tvERROR_INVALID_PARAM */
    componentColorCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/SupportedComponentColor");
    for (int i=0; i<tvDataColor_MAX; i++)
    {
        bModeMatched = false;
        for(unsigned int j =0; j < componentColorCount; j++){

            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/SupportedComponentColor/%d", j);
            componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if((tvDataComponentColor_t) componentColor !=(tvDataComponentColor_t) i)
            {
                bModeMatched = true;
                break;

            }
        }
        if(!bModeMatched)
        {
            result = SetCurrentComponentLuma((tvDataComponentColor_t)i,10);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 08: Calling tvsettings TvTerm and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/SupportedComponentColor/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 09: Calling tvsettings SetCurrentComponentLuma after TvTerm and expecting the API to return tvERROR_INVALID_STATE */
        result = SetCurrentComponentLuma(componentColor, 10);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }
    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetCurrentComponentLuma() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 181@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetCurrentComponentLuma() - Retrieve the current Component Luma with valid arguments by looping through all the values of DataComponentColor from ComponentColor section of test specific config file | tvDataComponentColor_t, int * | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call GetCurrentComponentLuma() -  Retrieve the current Component Luma  with valid argument and validate with above value | tvDataComponentColor_t, int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetCurrentComponentLuma (void)
{
    gTestID = 181;                                    /* It must be 181 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    int Luma = 0;
    int LumaRetry = 0;
    uint32_t componentColorCount = 0;
    tvDataComponentColor_t componentColor = tvDataColor_NONE;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetCurrentComponentLuma and expecting the API to return success */
    componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/SupportedComponentColor/0");
    result = GetCurrentComponentLuma(componentColor,&Luma);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetCurrentComponentLuma and expecting the API to return success */
    result = GetCurrentComponentLuma(componentColor,&LumaRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    UT_ASSERT_EQUAL(Luma, LumaRetry);

    componentColorCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/SupportedComponentColor");
    for (unsigned int i = 0; i < componentColorCount; ++i)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/SupportedComponentColor/%d", i);
        componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        result = GetCurrentComponentLuma(componentColor,&Luma);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
        UT_ASSERT_TRUE( (Luma >=0 && Luma <= 30) );
    }

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetCurrentComponentLuma() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 182@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetCurrentComponentLuma() -  Retrieve current TV Current Component Luma even before TvInit() | tvDataColor_RED, int * | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentComponentLuma() -  Retrieve current TV component Luma with invalid input by looping through all the values of DataComponentColor from ComponentColor section of test specific config file | tvDataComponentColor_t, NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetCurrentComponentLuma() -  Retrieve current TV component Luma with Max range of DataComponentColor | tvDataComponentColor_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetCurrentComponentLuma() -  Retrieve current TV component Luma with less than lower range of DataComponentColor  | -1, int * | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 07 | call GetCurrentComponentLuma() -  Retrieve current TV Current Component Luma valid arguments | tvDataColor_RED, int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetCurrentComponentLuma (void)
{
    gTestID = 182;                                    /* It must be 182 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE;
    int Luma = 0;
    bool bModeMatched = false;
    uint32_t componentColorCount = 0;
    tvDataComponentColor_t componentColor = tvDataColor_NONE;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/SupportedComponentColor/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetCurrentComponentLuma before TvInit and expecting the API to return tvERROR_INVALID_STATE */
        result = GetCurrentComponentLuma(componentColor, &Luma);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetCurrentComponentLuma and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetCurrentComponentLuma(tvDataColor_MAX,&Luma);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings GetCurrentComponentLuma and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetCurrentComponentLuma((tvDataComponentColor_t)-1,&Luma);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings GetCurrentComponentLuma and expectinging the API to return tvERROR_INVALID_PARAM */
    result = GetCurrentComponentLuma((tvDataComponentColor_t) componentColor,NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    componentColorCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/SupportedComponentColor");
    for (int i =0; i < tvDataColor_MAX; i++)
    {
        bModeMatched = false;
        for(unsigned int j = 0; j < componentColorCount; ++j)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/SupportedComponentColor/%d", j);
            componentColor = (tvDataComponentColor_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if((tvDataComponentColor_t) componentColor !=(tvDataComponentColor_t)i)
            {
                bModeMatched = true;
                break;
            }
        }
        if(!bModeMatched)
        {
            result = GetCurrentComponentLuma((tvDataComponentColor_t)i ,&Luma);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    /* Step 06: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 07: Calling tvsettings GetCurrentComponentLuma after TvTerm and expectinging the API to return tvERROR_INVALID_STATE */
        result = GetCurrentComponentLuma(componentColor, &Luma);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveCMS() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 183@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SaveCMS() -  Save the current CMS value by looping through all the values of sourceId, pqmode, videoFormatType, component_type, color_type from the VideoSource, PictureMode, VideoFormat, ComponentType, ComponentColor section of test specific config file  |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,tvComponentType_t ,tvDataComponentColor_t ,int | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED)| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveCMS (void)
{
    gTestID = 183;                                    /* It must be 183 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SaveCMS for all the sourceId,pqmode,videoFormatType, component_type, color_type and expecting the API to return success */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    for (unsigned int i = 0; i < videoSrcCount; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", i);
        videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            for (unsigned int k = 0; k < videoFmtCount; k++)
            {
                snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", k);
                videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
                if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentSaturationRed/platformsupport") == true)
                {
                    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_SATURATION, tvDataColor_RED,30);
                    UT_ASSERT_EQUAL(result, tvERROR_NONE);
                }
                if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentSaturationBlue/platformsupport") == true)
                {
                    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_SATURATION, tvDataColor_BLUE,30);
                    UT_ASSERT_EQUAL(result, tvERROR_NONE);
                }
                if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentSaturationGreen/platformsupport") == true)
                {
                    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_SATURATION, tvDataColor_GREEN,30);
                    UT_ASSERT_EQUAL(result, tvERROR_NONE);
                }
                if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentSaturationYellow/platformsupport") == true)
                {
                    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_SATURATION, tvDataColor_YELLOW,30);
                    UT_ASSERT_EQUAL(result, tvERROR_NONE);
                }
                if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentSaturationCyan/platformsupport") == true)
                {
                    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_SATURATION, tvDataColor_CYAN,30);
                    UT_ASSERT_EQUAL(result, tvERROR_NONE);
                }
                if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentSaturationMagenta/platformsupport") == true)
                {
                    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_SATURATION, tvDataColor_MAGENTA,30);
                    UT_ASSERT_EQUAL(result, tvERROR_NONE);
                }
                if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentHueRed/platformsupport") == true)
                {
                    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_HUE, tvDataColor_RED,30);
                    UT_ASSERT_EQUAL(result, tvERROR_NONE);
                }
                if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentHueBlue/platformsupport") == true)
                {
                    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_HUE, tvDataColor_BLUE,30);
                    UT_ASSERT_EQUAL(result, tvERROR_NONE);
                }
                if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentHueGreen/platformsupport") == true)
                {
                    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_HUE, tvDataColor_GREEN,30);
                    UT_ASSERT_EQUAL(result, tvERROR_NONE);
                }
                if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentHueYellow/platformsupport") == true)
                {
                    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_HUE, tvDataColor_YELLOW,30);
                    UT_ASSERT_EQUAL(result, tvERROR_NONE);
                }
                if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentHueMagenta/platformsupport") == true)
                {
                    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_HUE, tvDataColor_MAGENTA,30);
                    UT_ASSERT_EQUAL(result, tvERROR_NONE);
                }
                if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentHueCyan/platformsupport") == true)
                {
                    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_HUE, tvDataColor_CYAN,30);
                    UT_ASSERT_EQUAL(result, tvERROR_NONE);
                }
                if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentLumaRed/platformsupport") == true)
                {
                    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_LUMA, tvDataColor_RED,30);
                    UT_ASSERT_EQUAL(result, tvERROR_NONE);
                }
                if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentLumaBlue/platformsupport") == true)
                {
                    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_LUMA, tvDataColor_BLUE,30);
                    UT_ASSERT_EQUAL(result, tvERROR_NONE);
                }
                if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentLumaGreen/platformsupport") == true)
                {
                    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_LUMA, tvDataColor_GREEN,30);
                    UT_ASSERT_EQUAL(result, tvERROR_NONE);
                }
                if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentLumaYellow/platformsupport") == true)
                {
                    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_LUMA, tvDataColor_YELLOW,30);
                    UT_ASSERT_EQUAL(result, tvERROR_NONE);
                }
                if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentLumaMagenta/platformsupport") == true)
                {
                    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_LUMA, tvDataColor_MAGENTA,30);
                    UT_ASSERT_EQUAL(result, tvERROR_NONE);
                }
                if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentLumaCyan/platformsupport") == true)
                {
                    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_LUMA, tvDataColor_CYAN,30);
                    UT_ASSERT_EQUAL(result, tvERROR_NONE);
                }
            }
        }
    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveCMS() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 184@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SaveCMS() -  save the CMS even before TvInit() |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,tvComponentType_t ,tvDataComponentColor_t ,int | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit()  -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SaveCMS() -  "pqmode,videoFormatType,component_type,color_type,value"= valid , "source"= Invalid maxrange | VIDEO_SOURCE_MAX, int ,tvVideoFormatType_t ,tvComponentType_t ,tvDataComponentColor_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SaveCMS() -  "pqmode,videoFormatType,component_type,color_type,value"= valid , "source"= Invalid lowerrange | -2 , int ,tvVideoFormatType_t ,tvComponentType_t ,tvDataComponentColor_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SaveCMS() -  "source,videoFormatType,component_type,color_type,value"= valid , "pqmode"= Invalid maxrange | tvVideoSrcType_t, PQ_MODE_MAX ,tvVideoFormatType_t ,tvComponentType_t ,tvDataComponentColor_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SaveCMS() -  "source,videoFormatType,component_type,color_type,value"= valid , "pqmode"= Invalid lowerrange | tvVideoSrcType_t, -1 ,tvVideoFormatType_t ,tvComponentType_t ,tvDataComponentColor_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SaveCMS() -  "source,pqmode,component_type,color_type,value"= valid , "videoFormatType"= Invalid maxrange | tvVideoSrcType_t, int ,VIDEO_FORMAT_MAX ,tvComponentType_t ,tvDataComponentColor_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SaveCMS() -  "source,pqmode,component_type,color_type,value"= valid , "videoFormatType"= Invalid lowerrange | tvVideoSrcType_t, int ,-1 ,tvComponentType_t ,tvDataComponentColor_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SaveCMS() -  "source,pqmode,videoFormatType,color_type,value"= valid , "component_type"= Invalid maxrange | tvVideoSrcType_t, int ,tvVideoFormatType_t ,COMP_MAX ,tvDataComponentColor_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SaveCMS() -  "source,pqmode,videoFormatType,color_type,value"= valid , "component_type"= Invalid lowerrange | tvVideoSrcType_t, int ,tvVideoFormatType_t ,-1 ,tvDataComponentColor_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SaveCMS() -  "source,pqmode,videoFormatType,component_type,value"= valid , "color_type"= Invalid maxrange | tvVideoSrcType_t, int ,-1 ,tvComponentType_t ,tvDataColor_MAX ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call SaveCMS() -  "source,pqmode,videoFormatType,component_type,value"= valid , "color_type"= Invalid lowerrange | tvVideoSrcType_t, int ,-1 ,tvComponentType_t ,-1 ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 13 | call SaveCMS() -  "source, pqmode,videoFormatType,color_type"= valid , "component_type" = Saturation "value"= Invalid maxrange | VIDEO_SOURCE_MAX, int ,tvVideoFormatType_t ,COMP_SATURATION ,tvDataComponentColor_t ,101| tvERROR_INVALID_PARAM | Should Pass |
 * | 14 | call SaveCMS() -  "source, pqmode,videoFormatType,color_type"= valid , "component_type" = Saturation "value"= Invalid lowerrange | tvVideoSrcType_t , int ,tvVideoFormatType_t ,COMP_SATURATION ,tvDataComponentColor_t ,-1| tvERROR_INVALID_PARAM | Should Pass |
 * | 15 | call SaveCMS() -  "source, pqmode,videoFormatType,color_type"= valid , "component_type" =Hue  "value"= Invalid maxrange | tvVideoSrcType_t, int ,tvVideoFormatType_t ,COMP_HUE ,tvDataComponentColor_t ,101| tvERROR_INVALID_PARAM | Should Pass |
 * | 16 | call SaveCMS() -  "source, pqmode,videoFormatType,color_type"= valid , "component_type" = Hue  "value"= Invalid lowerrange | tvVideoSrcType_t , int ,tvVideoFormatType_t ,COMP_HUE ,tvDataComponentColor_t ,-1| tvERROR_INVALID_PARAM | Should Pass |
 * | 17 | call SaveCMS() -  "source, pqmode,videoFormatType,color_type"= valid , "component_type" = Luma "value"= Invalid maxrange | tvVideoSrcType_t , int ,tvVideoFormatType_t ,COMP_LUMA ,tvDataComponentColor_t ,31| tvERROR_INVALID_PARAM | Should Pass |
 * | 18 | call SaveCMS() -  "source, pqmode,videoFormatType,color_type"= valid , "component_type" = Luma "value"= Invalid lowerrange |tvVideoSrcType_t , int ,tvVideoFormatType_t ,COMP_LUMA ,tvDataComponentColor_t ,-1| tvERROR_INVALID_PARAM | Should Pass |
 * | 19 | call SaveCMS() -  "source, pqmode,videoFormatType, component_type color_type"= valid (looping through the ComponentColor section of test specific config file),"value"= valid | -2 , int ,tvVideoFormatType_t ,tvComponentType_t ,tvDataComponentColor_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 20 | call TvTerm()  -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 21 | call SaveCMS() -  save the CMS valid arguments |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,tvComponentType_t ,tvDataComponentColor_t ,int| tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveCMS (void)
{
    gTestID = 184;                                    /* It must be 184 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool SupportAvailable = true;
    int i = 0, j = 0 ;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SaveCMS and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveCMS(videoSource, pqValue, videoFormat, COMP_HUE, tvDataColor_RED, 1);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SaveCMS and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveCMS(VIDEO_SOURCE_MAX,pqValue,videoFormat,COMP_HUE, tvDataColor_RED,1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SaveCMS and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveCMS((tvVideoSrcType_t)-2,pqValue,videoFormat,COMP_HUE, tvDataColor_RED,1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SaveCMS and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveCMS(videoSource,-1,videoFormat,COMP_HUE, tvDataColor_RED,1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SaveCMS and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveCMS(videoSource,PQ_MODE_MAX,videoFormat,COMP_HUE, tvDataColor_RED,1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SaveCMS and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveCMS(videoSource,pqValue,VIDEO_FORMAT_MAX,COMP_HUE, tvDataColor_RED,1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings SaveCMS and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveCMS(videoSource,pqValue,(tvVideoFormatType_t)-1,COMP_HUE, tvDataColor_RED,1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings SaveCMS and expecting the API to return tvERROR_INVALID_STATE */
    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_MAX, tvDataColor_RED,1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 10: Calling tvsettings SaveCMS and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveCMS(videoSource,pqValue,videoFormat,(tvComponentType_t)-1, tvDataColor_RED,1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 11: Calling tvsettings SaveCMS and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_HUE, tvDataColor_MAX,1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 12: Calling tvsettings SaveCMS and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_HUE, (tvDataComponentColor_t)-1, 1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 13: Calling tvsettings SaveCMS and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_SATURATION, tvDataColor_RED,-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 14: Calling tvsettings SaveCMS and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_SATURATION, tvDataColor_RED,101);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 15: Calling tvsettings SaveCMS and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_HUE, tvDataColor_RED,-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 16: Calling tvsettings SaveCMS and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_HUE, tvDataColor_RED,101);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 17: Calling tvsettings SaveCMS and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_LUMA, tvDataColor_RED,-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 18: Calling tvsettings SaveCMS and expecting the API to return tvERROR_INVALID_PARAM */
    result = SaveCMS(videoSource,pqValue,videoFormat,COMP_LUMA, tvDataColor_RED,31);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 19: Calling tvsettings SaveCMS and expecting the API to return tvERROR_INVALID_PARAM */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    for( i =VIDEO_SOURCE_ALL ; i < VIDEO_SOURCE_MAX; i++)
    {
        SupportAvailable = false;
        for( j =0 ; j < videoSrcCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", j);
            videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoSource == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveCMS((tvVideoSrcType_t)i,pqValue,videoFormat,COMP_HUE, tvDataColor_RED,1);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    for( i =0 ; i < PQ_MODE_MAX; i++)
    {
        SupportAvailable = false;
        for( j =0 ; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(pqValue == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveCMS(videoSource,i,videoFormat,COMP_HUE, tvDataColor_RED,1);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    for( i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
    {
        SupportAvailable = false;
        for( j =0 ; j < videoFmtCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", j);
            videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
            if(videoFormat == i)
            {
                SupportAvailable = true;
                break;
            }
        }

        if(!SupportAvailable){
            result = SaveCMS(videoSource,pqValue,(tvVideoFormatType_t)i,COMP_HUE, tvDataColor_RED,1);
            UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        }
    }

    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentSaturationRed/platformsupport") == false)
    {
        result = SaveCMS(videoSource,pqValue,videoFormat,COMP_SATURATION, tvDataColor_RED,30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
    }
    else if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentSaturationBlue/platformsupport") == false)
    {
        result = SaveCMS(videoSource,pqValue,videoFormat,COMP_SATURATION, tvDataColor_BLUE,30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
    }
    else if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentSaturationGreen/platformsupport") == false)
    {
        result = SaveCMS(videoSource,pqValue,videoFormat,COMP_SATURATION, tvDataColor_GREEN,30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
    }
    else if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentSaturationYellow/platformsupport") == false)
    {
        result = SaveCMS(videoSource,pqValue,videoFormat,COMP_SATURATION, tvDataColor_YELLOW,30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
    }
    else if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentSaturationCyan/platformsupport") == false)
    {
        result = SaveCMS(videoSource,pqValue,videoFormat,COMP_SATURATION, tvDataColor_CYAN,30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
    }
    else if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentSaturationMagenta/platformsupport") == false)
    {
        result = SaveCMS(videoSource,pqValue,videoFormat,COMP_SATURATION, tvDataColor_MAGENTA,30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
    }
    else if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentHueRed/platformsupport") == false)
    {
        result = SaveCMS(videoSource,pqValue,videoFormat,COMP_HUE, tvDataColor_RED,30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
    }
    else if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentHueBlue/platformsupport") == false)
    {
        result = SaveCMS(videoSource,pqValue,videoFormat,COMP_HUE, tvDataColor_BLUE,30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
    }
    else if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentHueGreen/platformsupport") == false)
    {
        result = SaveCMS(videoSource,pqValue,videoFormat,COMP_HUE, tvDataColor_GREEN,30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
    }
    else if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentHueYellow/platformsupport") == false)
    {
        result = SaveCMS(videoSource,pqValue,videoFormat,COMP_HUE, tvDataColor_YELLOW,30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
    }
    else if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentHueMagenta/platformsupport") == false)
    {
        result = SaveCMS(videoSource,pqValue,videoFormat,COMP_HUE, tvDataColor_MAGENTA,30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
    }
    else if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentHueCyan/platformsupport") == false)
    {
        result = SaveCMS(videoSource,pqValue,videoFormat,COMP_HUE, tvDataColor_CYAN,30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
    }
    else if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentLumaRed/platformsupport") == false)
    {
        result = SaveCMS(videoSource,pqValue,videoFormat,COMP_LUMA, tvDataColor_RED,30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
    }
    else if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentLumaBlue/platformsupport") == false)
    {
        result = SaveCMS(videoSource,pqValue,videoFormat,COMP_LUMA, tvDataColor_BLUE,30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
    }
    else if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentLumaGreen/platformsupport") == false)
    {
        result = SaveCMS(videoSource,pqValue,videoFormat,COMP_LUMA, tvDataColor_GREEN,30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
    }
    else if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentLumaYellow/platformsupport") == false)
    {
        result = SaveCMS(videoSource,pqValue,videoFormat,COMP_LUMA, tvDataColor_YELLOW,30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
    }
    else if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentLumaMagenta/platformsupport") == false)
    {
        result = SaveCMS(videoSource,pqValue,videoFormat,COMP_LUMA, tvDataColor_MAGENTA,30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
    }
    else if(UT_KVP_PROFILE_GET_BOOL("tvSettings/ComponentLumaCyan/platformsupport") == false)
    {
        result = SaveCMS(videoSource,pqValue,videoFormat,COMP_LUMA, tvDataColor_CYAN,30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
    }


    /* Step 20: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 21: Calling tvsettings SaveCMS and expecting the API to return tvERROR_INVALID_STATE */
        result = SaveCMS(videoSource, pqValue, videoFormat, COMP_HUE, tvDataColor_RED, 1);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetCMSState() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 185@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetCMSState() -  Set the CMSState with valid value | true | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call SetCMSState() -  Set the CMSState with valid value | false | tvERROR_NONE | Should Pass |
 * | 04 | call SetCMSState() -  Set the CMSState with valid value | true | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetCMSState (void)
{
    gTestID = 185;                                    /* It must be 185 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings to Set the SetCMSState for value true and the API to return success */
    result = SetCMSState(true);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the SetCMSState for value true and the API to return success */
    result = SetCMSState(false);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings to Set the SetCMSState for value true and the API to return success */
    result = SetCMSState(true);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetCMSState() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 186@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetCMSState() -  Set the TV CMS State even before TvInit() | true | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetCMSState() -  Set the TV CMS State with valid input | true | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call SetCMSState() -  Set the TV CMS State with valid input after TvTerm() | true | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetCMSState (void)
{
    gTestID = 186;                                    /* It must be 186 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings to Set the SetCMSState for value true and the API to return success */
        result = SetCMSState(true);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the SetCMSState for value true and the API to return success */
    result = SetCMSState(true);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings to Set the SetCMSState for value true and the API to return success */
        result = SetCMSState(true);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetCMSState() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 187@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetCMSState() -  Retrieve the current CMS State with valid argument |bool *| tvERROR_NONE | Should Pass |
 * | 03 | call GetCMSState() -  Retrieve the current CMS State with valid argument and validate with above value | bool * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetCMSState (void)
{
    gTestID = 187;                                    /* It must be 187 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool CMSState = false;
    bool CMSStateRetry = false;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings to Set the GetCMSState for value true and the API to return success */
    result = GetCMSState(&CMSState);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the GetCMSState for value true and the API to return success */
    result = GetCMSState(&CMSStateRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(CMSState,CMSStateRetry);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetCMSState() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 188@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetCMSState() -   Retrieve current CMS State even before TvInit() | bool * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetCMSState() -  Retrieve current CMS State with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetCMSState() -  Retrieve current CMS State valid arguments | bool * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetCMSState (void)
{
    gTestID = 188;                                    /* It must be 188 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    bool CMSState = false;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings to Set the GetCMSState for value true and the API to return tvERROR_INVALID_STATE */
        result = GetCMSState(&CMSState);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the GetCMSState for value true and the API to return tvERROR_INVALID_STATE */
    result = GetCMSState(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings to Set the GetCMSState for value true and the API to return tvERROR_INVALID_STATE */
        result = GetCMSState(&CMSState);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetDefaultPQParams() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 189@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetDefaultPQParams() -  Get the default value PQ parameter by looping through all the input params from VideoSource, VideoFormat, PQParamIndex sections of test specific config file | int ,tvVideoSrcType_t ,tvVideoFormatType_t , tvPQParameterIndex_t , int *| (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetDefaultPQParams (void)
{

    gTestID = 189;                                    /* It must be 189 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int value = 0;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SaveBacklight for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    for (unsigned int i = 0; i < videoSrcCount; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", i);
        videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            for (unsigned int k = 0; k < videoFmtCount; k++)
            {
                snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", k);
                videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
                for (unsigned int l = 0; l < PQ_PARAM_MAX; l++)
                {
                    result = GetDefaultPQParams(pqValue,videoSource,videoFormat, (tvPQParameterIndex_t)l,&value);
                    UT_ASSERT_EQUAL(result, tvERROR_NONE);
                    if( (l == PQ_PARAM_CMS_SATURATION_RED) || \
                            (l == PQ_PARAM_CMS_SATURATION_GREEN)  || \
                            (l == PQ_PARAM_CMS_SATURATION_BLUE)  || \
                            (l == PQ_PARAM_CMS_SATURATION_YELLOW)  || \
                            (l == PQ_PARAM_CMS_SATURATION_CYAN) || \
                            (l == PQ_PARAM_CMS_SATURATION_MAGENTA) || \
                            (l == PQ_PARAM_CMS_HUE_RED) || \
                            (l == PQ_PARAM_CMS_HUE_GREEN) || \
                            (l == PQ_PARAM_CMS_HUE_BLUE) || \
                            (l == PQ_PARAM_CMS_HUE_YELLOW) || \
                            (l == PQ_PARAM_CMS_HUE_CYAN) || \
                            (l == PQ_PARAM_CMS_HUE_MAGENTA) || \
                            (l == PQ_PARAM_CMS_LUMA_RED) || \
                            (l == PQ_PARAM_CMS_LUMA_GREEN) || \
                            (l == PQ_PARAM_CMS_LUMA_BLUE) || \
                            (l == PQ_PARAM_CMS_LUMA_YELLOW) || \
                            (l == PQ_PARAM_CMS_LUMA_CYAN) || \
                            (l == PQ_PARAM_CMS_LUMA_MAGENTA) || \
                            (l == PQ_PARAM_BRIGHTNESS) || \
                            (l == PQ_PARAM_CONTRAST) || \
                            (l == PQ_PARAM_SATURATION) || \
                            (l == PQ_PARAM_SHARPNESS) || \
                            (l == PQ_PARAM_HUE) || \
                            (l == PQ_PARAM_BACKLIGHT) )
                            {
                                UT_ASSERT_TRUE((value >= 0 && value <= 100));
                            }
                }
            }
        }
    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetDefaultPQParams() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 190@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetDefaultPQParams() -  Get the default value PQ parameter even before TvInit() | int ,tvVideoSrcType_t ,tvVideoFormatType_t , tvPQParameterIndex_t , int * | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit()  -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetDefaultPQParams() -  "videoSrcType,videoFormatType,pqParamIndex,value"= valid , "pqIndex"= Invalid maxrange | PQ_MODE_MAX, tvVideoSrcType_t ,tvVideoFormatType_t , tvPQParameterIndex_t , int *| tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetDefaultPQParams() -  "videoSrcType,videoFormatType,pqParamIndex,value"= valid , "pqIndex"= Invalid lowerrange |PQ_MODE_INVALID , tvVideoSrcType_t ,tvVideoFormatType_t , tvPQParameterIndex_t , int *| tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetDefaultPQParams() -  "pqIndex,videoFormatType,pqParamIndex,value"= valid , "videoSrcType"= Invalid maxrange | int, VIDEO_SOURCE_MAX ,tvVideoFormatType_t , tvPQParameterIndex_t , int *| tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call GetDefaultPQParams() -  "pqIndex,videoFormatType,pqParamIndex,value"= valid , "videoSrcType"= Invalid lowerrange | int, -2 ,tvVideoFormatType_t , tvPQParameterIndex_t , int *| tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call GetDefaultPQParams() -  "pqIndex,videoSrcType,pqParamIndex,value"= valid , "videoFormatType"= Invalid maxrange | int, tvVideoSrcType_t ,VIDEO_FORMAT_MAX , tvPQParameterIndex_t , int *| tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call GetDefaultPQParams() -  "pqIndex,videoSrcType,pqParamIndex,value"= valid , "videoFormatType"= Invalid lowerrange | int, tvVideoSrcType_t ,-1 , tvPQParameterIndex_t , int *| tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call GetDefaultPQParams() -  "pqIndex,videoSrcType,videoFormatType,value"= valid , "pqParamIndex"= Invalid maxrange |  int, tvVideoSrcType_t ,tvVideoFormatType_t , PQ_PARAM_MAX , int *| tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call GetDefaultPQParams() -  "pqIndex,videoSrcType,videoFormatType,value"= valid , "pqParamIndex"= Invalid lowerrange |  int, tvVideoSrcType_t ,tvVideoFormatType_t , -1 , int *| tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call GetDefaultPQParams() -  "pqIndex,videoSrcType,videoFormatType,pqParamIndex"= valid , "value"= Invalid NULL pointer | int, tvVideoSrcType_t ,tvVideoFormatType_t , tvPQParameterIndex_t , NULL| tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call TvTerm()  -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 13 | call GetDefaultPQParams() -  Get the default value PQ parameter valid arguments |  int, tvVideoSrcType_t ,tvVideoFormatType_t , tvPQParameterIndex_t , int *| tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetDefaultPQParams (void)
{
    gTestID = 190;                                    /* It must be 190 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int value = 0;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetDefaultPQParams before TvInit and expecting the API to return tvERROR_INVALID_STATE */
        result = GetDefaultPQParams(pqValue, videoSource, videoFormat, (tvPQParameterIndex_t)PQ_PARAM_BRIGHTNESS, &value);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetDefaultPQParams and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetDefaultPQParams(-1, videoSource,videoFormat, (tvPQParameterIndex_t)PQ_PARAM_BRIGHTNESS, &value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings GetDefaultPQParams and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetDefaultPQParams(PQ_MODE_MAX, videoSource,videoFormat, (tvPQParameterIndex_t)PQ_PARAM_BRIGHTNESS, &value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings GetDefaultPQParams and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetDefaultPQParams(pqValue,(tvVideoSrcType_t) VIDEO_SOURCE_MAX,videoFormat, (tvPQParameterIndex_t)PQ_PARAM_BRIGHTNESS,&value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings GetDefaultPQParams and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetDefaultPQParams(pqValue,(tvVideoSrcType_t) -2,videoFormat, (tvPQParameterIndex_t)PQ_PARAM_BRIGHTNESS,&value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings GetDefaultPQParams and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetDefaultPQParams(pqValue,videoSource,(tvVideoFormatType_t) VIDEO_FORMAT_MAX, (tvPQParameterIndex_t)PQ_PARAM_BRIGHTNESS,&value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings GetDefaultPQParams and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetDefaultPQParams(pqValue,videoSource,(tvVideoFormatType_t) -1, (tvPQParameterIndex_t)PQ_PARAM_BRIGHTNESS,&value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings GetDefaultPQParams and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetDefaultPQParams(pqValue,videoSource,videoFormat,(tvPQParameterIndex_t) PQ_PARAM_MAX,&value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 10: Calling tvsettings GetDefaultPQParams and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetDefaultPQParams(pqValue,videoSource,videoFormat, (tvPQParameterIndex_t) -1,&value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 11: Calling tvsettings GetDefaultPQParams and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetDefaultPQParams(pqValue,videoSource,videoFormat, (tvPQParameterIndex_t)PQ_PARAM_BRIGHTNESS, NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 12: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 13: Calling tvsettings GetDefaultPQParams after TvTerm and expecting the API to return tvERROR_INVALID_STATE */
        result = GetDefaultPQParams(pqValue, videoSource, videoFormat, (tvPQParameterIndex_t)PQ_PARAM_BRIGHTNESS, &value);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }
    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetPQParams() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 191@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetPQParams() -  Get the default value PQ parameter by looping through all the input params from VideoSource, VideoFormat, PQParamIndex sections of test specific config file | int ,tvVideoSrcType_t ,tvVideoFormatType_t , tvPQParameterIndex_t , int *| (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetPQParams (void)
{

    gTestID = 191;                                    /* It must be 191 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int value = 0;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;
    uint32_t videoSrcCount = 0;
    uint32_t pqCount = 0;
    uint32_t videoFmtCount = 0;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SaveBacklight for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
    videoSrcCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoSource/index");
    pqCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/PictureMode/index");

    videoFmtCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/VideoFormat/index");
    for (unsigned int i = 0; i < videoSrcCount; i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoSource/index/%d", i);
        videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
        for (unsigned int j = 0; j < pqCount; j++)
        {
            snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/PictureMode/index/%d", j);
            pqValue = (int)UT_KVP_PROFILE_GET_UINT32(keyValue);
            for (unsigned int k = 0; k < videoFmtCount; k++)
            {
                snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/VideoFormat/index/%d", k);
                videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32(keyValue);
                for (unsigned int l = 0; l < PQ_PARAM_MAX; l++)
                {
                    result = GetPQParams(pqValue,videoSource,videoFormat, (tvPQParameterIndex_t)l,&value);
                    UT_ASSERT_EQUAL(result, tvERROR_NONE);
                    if( (l == PQ_PARAM_CMS_SATURATION_RED) || \
                            (l == PQ_PARAM_CMS_SATURATION_GREEN)  || \
                            (l == PQ_PARAM_CMS_SATURATION_BLUE)  || \
                            (l == PQ_PARAM_CMS_SATURATION_YELLOW)  || \
                            (l == PQ_PARAM_CMS_SATURATION_CYAN) || \
                            (l == PQ_PARAM_CMS_SATURATION_MAGENTA) || \
                            (l == PQ_PARAM_CMS_HUE_RED) || \
                            (l == PQ_PARAM_CMS_HUE_GREEN) || \
                            (l == PQ_PARAM_CMS_HUE_BLUE) || \
                            (l == PQ_PARAM_CMS_HUE_YELLOW) || \
                            (l == PQ_PARAM_CMS_HUE_CYAN) || \
                            (l == PQ_PARAM_CMS_HUE_MAGENTA) || \
                            (l == PQ_PARAM_CMS_LUMA_RED) || \
                            (l == PQ_PARAM_CMS_LUMA_GREEN) || \
                            (l == PQ_PARAM_CMS_LUMA_BLUE) || \
                            (l == PQ_PARAM_CMS_LUMA_YELLOW) || \
                            (l == PQ_PARAM_CMS_LUMA_CYAN) || \
                            (l == PQ_PARAM_CMS_LUMA_MAGENTA) || \
                            (l == PQ_PARAM_BRIGHTNESS) || \
                            (l == PQ_PARAM_CONTRAST) || \
                            (l == PQ_PARAM_SATURATION) || \
                            (l == PQ_PARAM_SHARPNESS) || \
                            (l == PQ_PARAM_HUE) || \
                            (l == PQ_PARAM_BACKLIGHT) )
                            {
                                UT_ASSERT_TRUE((value >= 0 && value <= 100));
                            }
                }
            }
        }
    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetPQParams() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 192@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetPQParams() -  Get the  value PQ parameter even before TvInit() | int ,tvVideoSrcType_t ,tvVideoFormatType_t , tvPQParameterIndex_t , int * | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit()  -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetPQParams() -  "videoSrcType,videoFormatType,pqParamIndex,value"= valid , "pqIndex"= Invalid maxrange | PQ_MODE_MAX, tvVideoSrcType_t ,tvVideoFormatType_t , tvPQParameterIndex_t , int *| tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetPQParams() -  "videoSrcType,videoFormatType,pqParamIndex,value"= valid , "pqIndex"= Invalid lowerrange |PQ_MODE_INVALID , tvVideoSrcType_t ,tvVideoFormatType_t , tvPQParameterIndex_t , int *| tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetPQParams() -  "pqIndex,videoFormatType,pqParamIndex,value"= valid , "videoSrcType"= Invalid maxrange | int, VIDEO_SOURCE_MAX ,tvVideoFormatType_t , tvPQParameterIndex_t , int *| tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call GetPQParams() -  "pqIndex,videoFormatType,pqParamIndex,value"= valid , "videoSrcType"= Invalid lowerrange | int, -2 ,tvVideoFormatType_t , tvPQParameterIndex_t , int *| tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call GetPQParams() -  "pqIndex,videoSrcType,pqParamIndex,value"= valid , "videoFormatType"= Invalid maxrange | int, tvVideoSrcType_t ,VIDEO_FORMAT_MAX , tvPQParameterIndex_t , int *| tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call GetPQParams() -  "pqIndex,videoSrcType,pqParamIndex,value"= valid , "videoFormatType"= Invalid lowerrange | int, tvVideoSrcType_t ,-1 , tvPQParameterIndex_t , int *| tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call GetPQParams() -  "pqIndex,videoSrcType,videoFormatType,value"= valid , "pqParamIndex"= Invalid maxrange |  int, tvVideoSrcType_t ,tvVideoFormatType_t , PQ_PARAM_MAX , int *| tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call GetPQParams() -  "pqIndex,videoSrcType,videoFormatType,value"= valid , "pqParamIndex"= Invalid lowerrange |  int, tvVideoSrcType_t ,tvVideoFormatType_t , -1 , int *| tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call GetPQParams() -  "pqIndex,videoSrcType,videoFormatType,pqParamIndex"= valid , "value"= Invalid NULL pointer | int, tvVideoSrcType_t ,tvVideoFormatType_t , tvPQParameterIndex_t , NULL| tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call TvTerm()  -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 13 | call GetPQParams() -  Get the  value PQ parameter valid arguments |  int, tvVideoSrcType_t ,tvVideoFormatType_t , tvPQParameterIndex_t , int *| tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetPQParams (void)
{
    gTestID = 192;                                    /* It must be 192 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int value = 0;
    tvVideoSrcType_t videoSource = VIDEO_SOURCE_ANALOGUE;
    int pqValue = 0;
    tvVideoFormatType_t videoFormat = VIDEO_FORMAT_NONE;

    videoSource = (tvVideoSrcType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoSource/index/0");
    pqValue = (int)UT_KVP_PROFILE_GET_UINT32("tvSettings/PictureMode/index/0");
    videoFormat = (tvVideoFormatType_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/VideoFormat/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetPQParams before TvInit and expecting the API to return tvERROR_INVALID_STATE */
        result = GetPQParams(pqValue, videoSource, videoFormat, (tvPQParameterIndex_t)PQ_PARAM_BRIGHTNESS, &value);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetPQParams and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetPQParams(-1, videoSource,videoFormat, (tvPQParameterIndex_t)PQ_PARAM_BRIGHTNESS, &value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings GetPQParams and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetPQParams(PQ_MODE_MAX, videoSource,videoFormat, (tvPQParameterIndex_t)PQ_PARAM_BRIGHTNESS, &value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings GetPQParams and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetPQParams(pqValue,(tvVideoSrcType_t) VIDEO_SOURCE_MAX,videoFormat, (tvPQParameterIndex_t)PQ_PARAM_BRIGHTNESS,&value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings GetPQParams and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetPQParams(pqValue,(tvVideoSrcType_t) -2,videoFormat, (tvPQParameterIndex_t)PQ_PARAM_BRIGHTNESS,&value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings GetPQParams and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetPQParams(pqValue,videoSource,(tvVideoFormatType_t) VIDEO_FORMAT_MAX, (tvPQParameterIndex_t)PQ_PARAM_BRIGHTNESS,&value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings GetPQParams and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetPQParams(pqValue,videoSource,(tvVideoFormatType_t) -1, (tvPQParameterIndex_t)PQ_PARAM_BRIGHTNESS,&value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings GetPQParams and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetPQParams(pqValue,videoSource,videoFormat,(tvPQParameterIndex_t) PQ_PARAM_MAX,&value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 10: Calling tvsettings GetPQParams and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetPQParams(pqValue,videoSource,videoFormat,  (tvPQParameterIndex_t )-1,&value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 11: Calling tvsettings GetPQParams and expecting the API to return tvERROR_INVALID_PARAM */
    result = GetPQParams(pqValue,videoSource,videoFormat, (tvPQParameterIndex_t)PQ_PARAM_BRIGHTNESS, NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 12: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 13: Calling tvsettings GetPQParams after TvTermm and expecting the API to return tvERROR_INVALID_STATE */
        result = GetPQParams(pqValue, videoSource, videoFormat, (tvPQParameterIndex_t)PQ_PARAM_BRIGHTNESS, &value);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetMaxGainValue() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 193@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetMaxGainValue() -  Retrieve the current MaxGain Value | void  | int | Should Pass |
 * | 03 | call GetMaxGainValue() -  Retrieve the current MaxGain Value with valid argument and validate with above value | void | int | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetMaxGainValue (void)
{
    gTestID = 193;                                    /* It must be 193 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int maxGain = -1;
    int maxGainRetry = -1;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetMaxGainValue and expectinging the API to return success */
    maxGain = GetMaxGainValue();
    UT_ASSERT_TRUE( (maxGain >= MIN_MAXGAIN_RANGE) && ( maxGain <= MAX_MAXGAIN_RANGE));

    /* Step 03: Calling tvsettings GetMaxGainValue and expectinging the API to return success */
    maxGainRetry = GetMaxGainValue( );
    UT_ASSERT_EQUAL(maxGain, maxGainRetry);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
}

/**
 * @brief Validate GetMaxGainValue() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 194@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetMaxGainValue() -  Retrieve current MaxGain Value even before TvInit() | void | -1 | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetMaxGainValue() -  Retrieve the current MaxGain Value | void  | int | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetMaxGainValue() -  Retrieve current MaxGain Value with valid arguments | void | -1 | Should Pass |
 */
void test_l1_tvSettings_negative_GetMaxGainValue (void)
{
    gTestID = 194;                                    /* It must be 194 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int maxGain = -1;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings to Set the GetMaxGainValue for value -1 and the API to return success */
        maxGain = GetMaxGainValue();
        UT_ASSERT_FALSE((maxGain >= MIN_MAXGAIN_RANGE) && (maxGain <= MAX_MAXGAIN_RANGE));
    }
    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the GetMaxGainValue for value -1 and the API to return success */
    maxGain = GetMaxGainValue();
    UT_ASSERT_TRUE((maxGain >= MIN_MAXGAIN_RANGE) && (maxGain <= MAX_MAXGAIN_RANGE));

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings to Set the GetMaxGainValue for value -1 and the API to return success */
        maxGain = GetMaxGainValue();
        UT_ASSERT_FALSE((maxGain >= MIN_MAXGAIN_RANGE) && (maxGain <= MAX_MAXGAIN_RANGE));
    }
    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate EnableGammaMode() for all positive invocation scenarios
 * This test ensures that the TV Settings module is to set Gamma Mode value
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 195@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call EnableGammaMode() -  Set the Gamma Mode with valid value | 0 | tvERROR_NONE | Should Pass |
 * | 03 | call EnableGammaMode() -  Reset the Gamma Mode with another valid value | 1 | tvERROR_NONE | Should Pass |
 * | 04 | call EnableGammaMode() -  Reset the Gamma Mode with another valid value | 0 | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_EnableGammaMode (void)
{
    gTestID = 195;                                    /* It must be 195 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings to Set the EnableGammaMode for value 0 and the API to return success */
    result = EnableGammaMode(0);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the EnableGammaMode for value 1 and the API to return success */
    result = EnableGammaMode(1);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings to Set the EnableGammaMode for value 0 and the API to return success */
    result = EnableGammaMode(0);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate EnableGammaMode() for all negative invocation scenarios
 * This test ensures that the TV Settings module is to set Gamma Mode value
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 196@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call EnableGammaMode() -  Set the TV GammaMode with valid input before TvInit() | 0 | tvERROR_GENERAL | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call EnableGammaMode() -   Set the TV GammaMode with invalid input | -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call EnableGammaMode() -   Set the TV GammaMode with invalid input | 256 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call EnableGammaMode() -  Set the TV GammaMode with valid input after TvTerm() | 0 | tvERROR_GENERAL | Should Pass |
 */
void test_l1_tvSettings_negative_EnableGammaMode (void)
{
    gTestID = 196;                                    /* It must be 196 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings EnableGammaMode before TvInit and expecting the API to return tvERROR_GENERAL */
        result = EnableGammaMode(1);
        UT_ASSERT_EQUAL(result, tvERROR_GENERAL);
    }
    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the EnableGammaMode for value -1 and the API to return tvERROR_INVALID_PARAM */
    result = EnableGammaMode(-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings to Set the EnableGammaMode for value 256 and the API to return tvERROR_INVALID_PARAM */
    result = EnableGammaMode(256);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 06: Calling tvsettings EnableGammaMode after TvTerm and expecting the API to return tvERROR_GENERAL */
        result = EnableGammaMode(1);
        UT_ASSERT_EQUAL(result, tvERROR_GENERAL);
    }
    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetGammaPattern() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 197@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetGammaPattern() -  Set the GammaPattern with valid arguments | 0 ,0, 0, 0 | tvERROR_NONE | Should Pass |
 * | 03 | call SetGammaPattern() -  Set the GammaPattern with valid arguments | 0 ,500, 500, 500 | tvERROR_NONE | Should Pass |
 * | 04 | call SetGammaPattern() -  Set the GammaPattern with valid arguments | 0 ,1023, 1023, 1023 | tvERROR_NONE | Should Pass |
 * | 05 | call SetGammaPattern() -  Set the GammaPattern with valid arguments | 1 ,0, 0, 0 | tvERROR_NONE | Should Pass |
 * | 06 | call SetGammaPattern() -  Set the GammaPattern with valid arguments | 1 ,255, 255, 255 | tvERROR_NONE | Should Pass |
 * | 07 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetGammaPattern (void)
{
    gTestID = 197;                                    /* It must be 197 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings to Set the SetGammaPattern for value 0,0,0,0 and the API to return success */
    result = SetGammaPattern(0,0,0,0);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the SetGammaPattern for value 0,500,500,500 and the API to return success */
    result = SetGammaPattern(0,500,500,500);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings to Set the SetGammaPattern for value 0,1023,1023,1023 and the API to return success */
    result = SetGammaPattern(0,1023,1023,1023);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 05: Calling tvsettings to Set the SetGammaPattern for value 1,0,0,0 and the API to return success */
    result = SetGammaPattern(1,0,0,0);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 06: Calling tvsettings to Set the SetGammaPattern for value 1,255,255,255 and the API to return success */
    result = SetGammaPattern(1,255,255,255);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 07: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetGammaPattern() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 198@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetGammaPattern() - Set the GammaPattern even before TvInit() | int ,int, int, int| tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetGammaPattern() -   Set the GammaPattern with invalid input of RGB value| -1 ,-1, -1, -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetGammaPattern() -   Set the GammaPattern with invalid input of is_10_bit and RGB value | -1 ,1025, 1025, 1025 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetGammaPattern() -   Set the GammaPattern with invalid input of is_10_bit | -1 ,int, int, int | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetGammaPattern() -   Set the GammaPattern with invalid input of R_Value | 1 ,1026, int, int | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SetGammaPattern() -   Set the GammaPattern with invalid input of G_Value | 1 ,int, 1026, int | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SetGammaPattern() -   Set the GammaPattern with invalid input of B_Value | 1 ,int, int, 1026 | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SetGammaPattern() -   Set the GammaPattern with invalid input of is_10_bit  | 2 , 0, 0, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 11 | call SetGammaPattern() -  Set the GammaPattern with valid input after TvTerm() | int ,int, int, int | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetGammaPattern (void)
{
    gTestID = 198;                                    /* It must be 198 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings to Set the SetGammaPattern for value 0,0,0,0 and the API to return tvERROR_INVALID_STATE */
        result = SetGammaPattern(0, 0, 0, 0);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the SetGammaPattern for value -1,-1,-1,-1 and the API to return tvERROR_INVALID_PARAM */
    result = SetGammaPattern(-1,-1,-1,-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings to Set the SetGammaPattern for value -1 ,1025, 1025, 1025 and the API to return tvERROR_INVALID_PARAM */
    result = SetGammaPattern(-1,1025,1025,1025);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings to Set the SetGammaPattern for value -1,1025,0,0 and the API to return tvERROR_INVALID_PARAM */
    result = SetGammaPattern(-1,0,0,0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings to Set the SetGammaPattern for value 1,1026,1026,1026 and the API to return tvERROR_INVALID_PARAM */
    result = SetGammaPattern(1,1026,1026,1026);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings to Set the SetGammaPattern for value 1,1026,0,0 and the API to return tvERROR_INVALID_PARAM */
    result = SetGammaPattern(1,1026,0,0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings to Set the SetGammaPattern for value 1,0,1026,0 and the API to return tvERROR_INVALID_PARAM */
    result = SetGammaPattern(1,0,1026,0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings to Set the SetGammaPattern for value 1,0,0,1026 and the API to return tvERROR_INVALID_PARAM */
    result = SetGammaPattern(1,0,0,1026);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 10: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 11: Calling tvsettings to Set the SetGammaPattern for value 0,0,0,0 and the API to return tvERROR_INVALID_STATE */
        result = SetGammaPattern(0, 0, 0, 0);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVGammaTarget() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 199@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetTVGammaTarget() -  Retrieve the current Gamma Target values and validate with range (0 to 1.0) by looping through the ColorTemperature section of test specific config file | tvColorTemp_t, double *, double *| tvERROR_NONE | Should Pass |
 * | 03 | call GetTVGammaTarget() -  Retrieve the current current Gamma Target values with valid argument and validate with above value |  tvColorTemp_t, double *, double * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetTVGammaTarget (void)
{
    gTestID = 199;                                    /* It must be 199 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    double x_ValueRetry = 0.0, x_Value = 0.0;
    double y_ValueRetry = 0.0, y_Value = 0.0;
    uint32_t colorTempCount = 0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;
    char keyValue[UT_KVP_MAX_ELEMENT_SIZE] = { 0 };


    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02-03: Calling tvsettings GetTVGammaTarget and expecting the API to return success */
    colorTempCount = UT_KVP_PROFILE_GET_LIST_COUNT("tvSettings/ColorTemperature/index");
    for (unsigned int i = 0; i < (colorTempCount); i++)
    {
        snprintf(keyValue, UT_KVP_MAX_ELEMENT_SIZE, "tvSettings/ColorTemperature/index/%d", i);
        colorTempValue = (tvColorTemp_t) UT_KVP_PROFILE_GET_UINT32(keyValue);
        result = GetTVGammaTarget( colorTempValue, &x_Value, &y_Value);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
        UT_ASSERT_TRUE((x_Value >= 0 && x_Value <= 1.0) );
        UT_ASSERT_TRUE((y_Value >= 0 && y_Value <= 1.0) );

        result = GetTVGammaTarget( colorTempValue, &x_ValueRetry, &y_ValueRetry);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
        UT_ASSERT_TRUE((x_Value == x_ValueRetry && y_Value == y_ValueRetry) );
    }

    /* Step 03: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVGammaTarget() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 200@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetTVGammaTarget() -  Retrieve current TV Gamma Target even before TvInit() | tvColorTemp_t, double *, double *| tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVGammaTarget() -   Retrieve current TV Gamma Target with invalid input | tvColorTemp_t, double *, NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetTVGammaTarget() -   Retrieve current TV Gamma Target with invalid input | tvColorTemp_t, NULL, double * | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetTVGammaTarget() -   Retrieve current TV Gamma Target with invalid input with max range| tvColorTemp_MAX, double *, double * | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call GetTVGammaTarget() -   Retrieve current TV Gamma Target with invalid input with less than lower range| -1, double *, double * | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 08 | call GetTVGammaTarget() -  Retrieve current TV Gamma Target valid arguments | tvColorTemp_t, double *, double * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetTVGammaTarget (void)
{
    gTestID = 200;                                    /* It must be 200 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    double x_Value = 0.0;
    double y_Value = 0.0;
    tvColorTemp_t colorTempValue = tvColorTemp_STANDARD;

    colorTempValue = (tvColorTemp_t)UT_KVP_PROFILE_GET_UINT32("tvSettings/ColorTemperature/index/0");
    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetTVGammaTarget before TvInit */
        result = GetTVGammaTarget(colorTempValue, &x_Value, &y_Value);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }
    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetTVGammaTarget with invalid input*/
    result = GetTVGammaTarget( tvColorTemp_MAX , &x_Value, &y_Value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings GetTVGammaTarget with invalid input*/
    result = GetTVGammaTarget( (tvColorTemp_t)-1 , &x_Value, &y_Value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings GetTVGammaTarget with invalid input*/
    result = GetTVGammaTarget( colorTempValue, NULL, &y_Value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings GetTVGammaTarget with invalid input*/
    result = GetTVGammaTarget( colorTempValue, &x_Value, NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 08: Calling tvsettings GetTVGammaTarget after TvTerm*/
        result = GetTVGammaTarget(colorTempValue, &x_Value, &y_Value);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }
    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetGammaPatternMode() for all positive invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 201@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | Call SetGammaPatternMode() - Set the Gamma Pattern Mode with valid value | true| tvERROR_NONE | Should Pass |
 * | 03 | call SetGammaPatternMode() -  Reset the Gamma Pattern Mode with another valid value | false | tvERROR_NONE | Should Pass |
 * | 04 | call SetGammaPatternMode() -  Reset the Gamma Pattern Mode with another valid value | true | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetGammaPatternMode (void)
{
    gTestID = 201;                                    /* It must be 201 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings to Set the EnableGammaMode for value 0 and the API to return success */
    result = SetGammaPatternMode(true);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the EnableGammaMode for value 1 and the API to return success */
    result = SetGammaPatternMode(false);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings to Set the EnableGammaMode for value 0 and the API to return success */
    result = SetGammaPatternMode(true);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetGammaPatternMode() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 202@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call SetGammaPatternMode() - Set the Gamma Pattern Mode even before TvInit() | bool | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetGammaPatternMode() -  Set the TV backlight with valid input | true | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call SetGammaPatternMode() -  Set the TV backlight with valid input after TvTerm() | bool | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetGammaPatternMode (void)
{
    gTestID = 202;                                    /* It must be 202 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetGammaPatternMode with value true and expecting the API to tvERROR_INVALID_STATE*/
        result = SetGammaPatternMode(true);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetGammaPatternMode with value true and expecting the API to return success*/
    result = SetGammaPatternMode(true);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings SetGammaPatternMode after TvTerm and expecting the API to return tvERROR_INVALID_STATE */
        result = SetGammaPatternMode(true);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetRGBPattern() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 203@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetRGBPattern() -  Set the RGBPattern with valid value | 0,0,0 | tvERROR_NONE | Should Pass |
 * | 03 | call SetRGBPattern() -  Reset the RGBPattern with another valid value | 100,100,100 | tvERROR_NONE | Should Pass |
 * | 04 | call SetRGBPattern() -  Reset the RGBPattern with another valid value | 255,255,255 | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetRGBPattern (void)
{
    gTestID = 203;                                    /* It must be 203 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings to Set the SetRGBPattern for the RGB pattern 00,00,00 and expecting the API to return success */
    result = SetRGBPattern(00,00,00);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the SetRGBPattern for the RGB pattern 100,100,100 and expecting the API to return success */
    result = SetRGBPattern(100,100,100);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings to Set the SetRGBPattern for the RGB pattern 255,255,255 and expecting the API to return success */
    result = SetRGBPattern(255,255,255);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetRGBPattern() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 204@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetRGBPattern() - Set the TV RGBPattern even before TvInit() | 0,0,0 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetRGBPattern() - Set the TV RGBPattern with invalid value of R with  max range | 256,100,100 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetRGBPattern() - Set the TV RGBPattern with invalid value of G with  max range | 100,256,100 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetRGBPattern() - Set the TV RGBPattern with invalid value of B with  max range | 100,100,256 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetRGBPattern() - Set the TV RGBPattern with invalid value of R with less than lower range | -1,100,100 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SetRGBPattern() - Set the TV RGBPattern with invalid value of G with less than lower range | 100,-1,100 | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SetRGBPattern() - Set the TV RGBPattern with invalid value of B with less than lower range | 100,100,-1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 10 | call SetRGBPattern() -  Set the TV RGBPattern with valid input after TvTerm() | 255,255,255 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetRGBPattern (void)
{
    gTestID = 204;                                    /* It must be 204 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetRGBPattern and expecting the API to return tvERROR_INVALID_STATE */
        result = SetRGBPattern(00, 00, 00);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetRGBPattern and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetRGBPattern(256,100,100);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetRGBPattern and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetRGBPattern(100,256,100);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings SetRGBPattern and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetRGBPattern(100,100,256);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings SetRGBPattern and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetRGBPattern(-1,100,100);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings SetRGBPattern and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetRGBPattern(100,-1,100);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 08: Calling tvsettings SetRGBPattern and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetRGBPattern(100,100,-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 09: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 10: Calling tvsettings the SetRGBPattern and expecting the API to return tvERROR_INVALID_STATE */
        result = SetRGBPattern(255, 255, 255);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetRGBPattern() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 205@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetRGBPattern() -  Retrieve the current RGB Pattern and validate with range (0 - 255)  | int *, int *, int * | tvERROR_NONE | Should Pass |
 * | 03 | call GetRGBPattern() -  Retrieve the current RGB Pattern with valid arguments and validate with above value | int *, int *, int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetRGBPattern (void)
{
    gTestID = 205;                                    /* It must be 205 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int red = -1;
    int green = -1;
    int blue = -1;
    int redRetry = -1;
    int greenRetry = -1;
    int blueRetry = -1;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetRGBPattern and expecting the API to return success */
    result = GetRGBPattern(&red,&green,&blue);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_TRUE( (red >= 0 && red <= 255));
    UT_ASSERT_TRUE( (green >= 0 && green <= 255));
    UT_ASSERT_TRUE( (blue >= 0 && blue <= 255));

    /* Step 03: Calling tvsettings GetRGBPattern again and expecting the API to return success */
    result = GetRGBPattern(&redRetry,&greenRetry,&blueRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(red,redRetry);
    UT_ASSERT_EQUAL(green,greenRetry);
    UT_ASSERT_EQUAL(blue,blueRetry);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetRGBPattern() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 206@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetRGBPattern() -  Retrieve current TV RGBPattern even before TvInit() | int *, int *, int * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() - Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetRGBPattern() -  Retrieve current TV RGBPattern with invalid parameter of R |NULL, int *, int * | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetRGBPattern() -  Retrieve current TV RGBPattern with invalid parameter of G|int *,NULL , int * | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetRGBPattern() -  Retrieve current TV RGBPattern with invalid parameter of B |int *, int *, NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 07 | call GetRGBPattern() -  Retrieve current TV RGBPattern valid arguments | int *, int *, int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetRGBPattern (void)
{
    gTestID = 206;                                    /* It must be 206 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int red = -1;
    int green = -1;
    int blue = -1;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetRGBPattern and the API to return tvERROR_INVALID_STATE */
        result = GetRGBPattern(&red, &green, &blue);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetRGBPattern and the API to return tvERROR_INVALID_PARAM */
    result = GetRGBPattern(NULL,&green,&blue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings GetRGBPattern and the API to return tvERROR_INVALID_PARAM */
    result = GetRGBPattern(&red,NULL,&blue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings GetRGBPattern and the API to return tvERROR_INVALID_PARAM */
    result = GetRGBPattern(&red,&green,NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 07: Calling tvsettings GetRGBPattern and the API to return tvERROR_INVALID_STATE */
        result = GetRGBPattern(&red, &green, &blue);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetGrayPattern() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 207@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetGrayPattern() -  Set the GrayPattern with valid value | 0 | tvERROR_NONE | Should Pass |
 * | 03 | call SetGrayPattern() -  Reset the GrayPattern with another valid value | 100 | tvERROR_NONE | Should Pass |
 * | 04 | call SetGrayPattern() -  Reset the GrayPattern with another valid value | 255 | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetGrayPattern (void)
{
    gTestID = 207;                                    /* It must be 207 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings to Set the SetGrayPattern for value 00 and the API to return success */
    result = SetGrayPattern(00);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the SetGrayPattern for value 100 and the API to return success */
    result = SetGrayPattern(100);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings to Set the SetGrayPattern for value 255 and the API to return success */
    result = SetGrayPattern(255);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetGrayPattern() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 208@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetGrayPattern() - Set the TV GrayPattern even before TvInit() | 30 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetGrayPattern() - Set the TV GrayPattern with less than lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetGrayPattern() - Set the TV GrayPattern with max range | 256 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call SetGrayPattern() -  Set the TV GrayPattern with valid input after TvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetGrayPattern (void)
{
    gTestID = 208;                                    /* It must be 208 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetGrayPattern and the API to return tvERROR_INVALID_STATE */
        result = SetGrayPattern(30);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetGrayPattern and the API to return tvERROR_INVALID_PARAM */
    result = SetGrayPattern(-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetGrayPattern and the API to return tvERROR_INVALID_PARAM */
    result = SetGrayPattern(256);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 06: Calling tvsettings the SetGrayPattern and the API to return tvERROR_INVALID_STATE */
        result = SetGrayPattern(50);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetGrayPattern() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 209@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetGrayPattern() -  Retrieve the current GrayPattern and validate with range (0 - 255) | int * | tvERROR_NONE | Should Pass |
 * | 03 | call GetGrayPattern() -  Retrieve the current GrayPattern with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetGrayPattern (void)
{
    gTestID = 209;                                    /* It must be 209 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int grayPattern = -1;
    int grayPatternRetry = -1;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetBacklight and the API to return success */
    result = GetGrayPattern(&grayPattern);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_TRUE( (grayPattern >= 0 && grayPattern <= 255));

    /* Step 03: Calling tvsettings GetBacklight again and the API to return success */
    result = GetGrayPattern(&grayPatternRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(grayPattern, grayPatternRetry);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetGrayPattern() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 210@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetGrayPattern() -  Retrieve current TV GrayPattern even before TvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetGrayPattern() - Get the TV GrayPattern with invalid input value | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetGrayPattern() -  Retrieve current TV GrayPattern valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetGrayPattern (void)
{
    gTestID = 210;                                    /* It must be 210 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int grayPattern = -1;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetGrayPattern and the API to return tvERROR_INVALID_STATE */
        result = GetGrayPattern(&grayPattern);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetGrayPattern and the API to return tvERROR_INVALID_PARAM */
    result = GetGrayPattern(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings GetGrayPattern and the API to return tvERROR_INVALID_STATE */
        result = GetGrayPattern(&grayPattern);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetOpenCircuitStatus() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 211@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetOpenCircuitStatus() -  Retrieve the OpenCircuit Status | int *  | tvERROR_NONE | Should Pass |
 * | 03 | call GetOpenCircuitStatus()-  Retrieve the OpenCircuit Status with valid argument and validate with above value | int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetOpenCircuitStatus (void)
{
    gTestID = 211;                                    /* It must be 211 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int OpenCircuitStatus = -1;
    int OpenCircuitStatusRetry = -1;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetBacklight and the API to return success */
    result = GetOpenCircuitStatus(&OpenCircuitStatus);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_TRUE((OpenCircuitStatus >= 0));

    /* Step 03: Calling tvsettings GetBacklight again and the API to return success */
    result = GetOpenCircuitStatus(&OpenCircuitStatusRetry);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_ASSERT_EQUAL(OpenCircuitStatus, OpenCircuitStatusRetry);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetOpenCircuitStatus() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 212@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetOpenCircuitStatus() -  Retrieve current TV OpenCircuit Status even before TvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetOpenCircuitStatus() -  Retrieve current TV OpenCircuit Status with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetOpenCircuitStatus() -  Retrieve current TV OpenCircuit Status valid arguments | int* | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetOpenCircuitStatus (void)
{
    gTestID = 212;                                    /* It must be 212 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int OpenCircuitStatus = -1;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetGrayPattern and the API to return tvERROR_INVALID_STATE */
        result = GetOpenCircuitStatus(&OpenCircuitStatus);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetGrayPattern and the API to return tvERROR_INVALID_PARAM */
    result = GetOpenCircuitStatus(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings GetGrayPattern and the API to return tvERROR_INVALID_STATE */
        result = GetOpenCircuitStatus(&OpenCircuitStatus);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }
}

/**
 * @brief Validate EnableLDIMPixelCompensation() for all positive invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 213@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | bool | tvERROR_NONE | Should Pass |
 * | 02 | Call EnableLDIMPixelCompensation() - Enable the LDIM Pixel Compensation with valid value | true | tvERROR_NONE | Should Pass |
 * | 03 | call EnableLDIMPixelCompensation() - Disable the LDIM Pixel Compensation with valid value | false | tvERROR_NONE | Should Pass |
 * | 04 | call EnableLDIMPixelCompensation() - Enable the LDIM Pixel Compensation valid value | true | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | bool | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_EnableLDIMPixelCompensation (void)
{
    gTestID = 213;                                    /* It must be 213 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings to Set the EnableLDIMPixelCompensation for value true and the API to return success */
    result = EnableLDIMPixelCompensation(true);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the EnableLDIMPixelCompensation for value true and the API to return success */
    result = EnableLDIMPixelCompensation(false);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings to Set the EnableLDIMPixelCompensation for value true and the API to return success */
    result = EnableLDIMPixelCompensation(true);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate EnableLDIMPixelCompensation() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 214@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call EnableLDIMPixelCompensation() - Enable the LDIM Pixel Compensation even before TvInit() | true | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call EnableLDIMPixelCompensation() -  Enable the LDIM Pixel Compensation valid input | true | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call EnableLDIMPixelCompensation() -  Enable the LDIM Pixel Compensation valid input after TvTerm() | true | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_EnableLDIMPixelCompensation (void)
{
    gTestID = 214;                                    /* It must be 214 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings to Set the EnableLDIMPixelCompensation for value true and the API to return tvERROR_INVALID_STATE */
        result = EnableLDIMPixelCompensation(true);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the EnableLDIMPixelCompensation for value true and the API to return success */
    result = EnableLDIMPixelCompensation(true);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings to Set the EnableLDIMPixelCompensation for value true and the API to return tvERROR_INVALID_STATE */
        result = EnableLDIMPixelCompensation(true);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate EnableLDIM() for all positive invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 215@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | bool | tvERROR_NONE | Should Pass |
 * | 02 | Call EnableLDIM() - Enable the LDIM  with valid value | true | tvERROR_NONE | Should Pass |
 * | 03 | call EnableLDIM() - Disable the LDIM with valid value | false | tvERROR_NONE | Should Pass |
 * | 04 | call EnableLDIM() - Enable the LDIM with valid value | true | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | bool | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_EnableLDIM (void)
{
    gTestID = 215;                                    /* It must be 215 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings to Set the EnableLDIM for value true and the API to return success */
    result = EnableLDIM(true);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the EnableLDIM for value true and the API to return success */
    result = EnableLDIM(false);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings to Set the EnableLDIM for value true and the API to return success */
    result = EnableLDIM(true);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate EnableLDIM() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 216@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call EnableLDIM() - Enable the LDIM even before TvInit() | true | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call EnableLDIM() -  Enable the LDIM valid input | true | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call EnableLDIM() -  Enable the LDIM valid input after TvTerm() | true | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_EnableLDIM (void)
{
    gTestID = 216;                                    /* It must be 216 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings to Set the EnableLDIM for value true and the API to return tvERROR_INVALID_STATE */
        result = EnableLDIM(true);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the EnableLDIM for value true and the API to return success */
    result = EnableLDIM(true);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings to Set the EnableLDIM for value true and the API to return tvERROR_INVALID_STATE */
        result = EnableLDIM(true);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate StartLDIMSequenceTest() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 217@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call StartLDIMSequenceTest() -  Start the LDIM Sequence Test with valid value | 2,  100 | tvERROR_NONE | Should Pass |
 * | 03 | call StartLDIMSequenceTest() -  Restart the LDIM Sequence Test with another valid value | 2, 500 | tvERROR_NONE | Should Pass |
 * | 04 | call StartLDIMSequenceTest() -  Restart the LDIM Sequence Test with another valid value | 2, 1000 | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_StartLDIMSequenceTest (void)
{
    gTestID = 217;                                    /* It must be 217 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings StartLDIMSequenceTest for value 2, 100 and the API to return success */
    result = StartLDIMSequenceTest(2,100);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings StartLDIMSequenceTest for value 2, 500 and the API to return success */
    result = StartLDIMSequenceTest(2,500);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings StartLDIMSequenceTest for value 2, 1000 and the API to return success */
    result = StartLDIMSequenceTest(2,1000);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate StartLDIMSequenceTest() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 218@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call StartLDIMSequenceTest() - start the LDIM Sequence Test even before TvInit() | int , int | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call StartLDIMSequenceTest() - start the LDIM Sequence Test with invalid value | -1, 100 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call StartLDIMSequenceTest() - start the LDIM Sequence Test with invalid value | 0, 100 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call StartLDIMSequenceTest() - start the LDIM Sequence Test with invalid value | 1, 100 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call StartLDIMSequenceTest() - start the LDIM Sequence Test with invalid value with less than lower range | 2, -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 08 | call StartLDIMSequenceTest() -   start the LDIM Sequence Test with valid input after TvTerm() |  int , int | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_StartLDIMSequenceTest (void)
{
    gTestID = 218;                                    /* It must be 218 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings StartLDIMSequenceTest for value 2, 500 and the API to return tvERROR_INVALID_STATE */
        result = StartLDIMSequenceTest(2, 500);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings StartLDIMSequenceTest for value -1, 100 and the API to return tvERROR_INVALID_PARAM */
    result = StartLDIMSequenceTest(-1,100);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings StartLDIMSequenceTest for value 0, 100 and the API to return tvERROR_INVALID_PARAM */
    result = StartLDIMSequenceTest(0,100);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings StartLDIMSequenceTest for value 1, 100 and the API to return tvERROR_INVALID_PARAM */
    result = StartLDIMSequenceTest(1,100);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 06: Calling tvsettings StartLDIMSequenceTest for value 2, -1 and the API to return tvERROR_INVALID_PARAM */
    result = StartLDIMSequenceTest(2, -1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 07: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 08: Calling tvsettings StartLDIMSequenceTest for value 2, 500 and the API to return tvERROR_INVALID_STATE */
        result = StartLDIMSequenceTest(2, 500);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetBacklightTestMode() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 219@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetBacklightTestMode() -  Start the Backlight Test Mode a valid value |tvBacklightTestMode_Normal | tvERROR_NONE | Should Pass |
 * | 03 | call SetBacklightTestMode() -  Start the Backlight Test Mode a valid value |tvBacklightTestMode_Boost | tvERROR_NONE | Should Pass |
 * | 04 | call SetBacklightTestMode() -  Start the Backlight Test Mode a valid value |tvBacklightTestMode_Reset | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetBacklightTestMode (void)
{
    gTestID = 219;                                    /* It must be 219 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SetBacklightTestMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetBacklightTestMode(tvBacklightTestMode_Normal);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetBacklightTestMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetBacklightTestMode(tvBacklightTestMode_Boost);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings SetBacklightTestMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetBacklightTestMode(tvBacklightTestMode_Burst);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings SetBacklightTestMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetBacklightTestMode(tvBacklightTestMode_Reset);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetBacklightTestMode() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 220@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetBacklightTestMode() - start the Backlight Test Mode even before TvInit() | tvBacklightTestMode_t | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetBacklightTestMode() - start the Backlight Test Mode with invalid value with Max range |tvBacklightTestMode_Max | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetBacklightTestMode() - start the Backlight Test Mode with invalid value with less than lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call SetBacklightTestMode() -   start the Backlight Test Mode with valid input after TvTerm() | tvBacklightTestMode_t | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetBacklightTestMode (void)
{
    gTestID = 220;                                    /* It must be 220 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings SetBacklightTestMode and expecting the API to return tvERROR_INVALID_STATE */
        result = SetBacklightTestMode(tvBacklightTestMode_Normal);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings SetBacklightTestMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetBacklightTestMode(tvBacklightTestMode_Max);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings SetBacklightTestMode and expecting the API to return tvERROR_INVALID_PARAM */
    result = SetBacklightTestMode((tvBacklightTestMode_t)-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 06: Calling tvsettings the SetBacklightTestMode and expecting the API to return tvERROR_INVALID_STATE */
        result = SetBacklightTestMode(tvBacklightTestMode_Normal);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate EnableWhiteBalance() for all positive invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 221@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | bool | tvERROR_NONE | Should Pass |
 * | 02 | Call EnableWhiteBalance() - Enable White Balance  with valid value | true | tvERROR_NONE | Should Pass |
 * | 03 | call EnableWhiteBalance() - Disable White Balance with valid value | false | tvERROR_NONE | Should Pass |
 * | 04 | call EnableWhiteBalance() - Enable White Balance with valid value | true | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | bool | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_EnableWhiteBalance (void)
{
    gTestID = 221;                                    /* It must be 221 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings to Set the EnableWhiteBalance for value true and the API to return success */
    result = EnableWhiteBalance(true);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the EnableWhiteBalance for value true and the API to return success */
    result = EnableWhiteBalance(false);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings to Set the EnableWhiteBalance for value true and the API to return success */
    result = EnableWhiteBalance(true);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate EnableWhiteBalance() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 222@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call EnableWhiteBalance() - Enable White Balance even before TvInit() | true | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call EnableWhiteBalance() -  Enable White Balance valid input | true | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call EnableWhiteBalance() -  Enable White Balance valid input after TvTerm() | true | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_EnableWhiteBalance (void)
{
    gTestID = 222;                                    /* It must be 222 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings to Set the EnableWhiteBalance for value true and the API to return tvERROR_INVALID_STATE */
        result = EnableWhiteBalance(true);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the EnableWhiteBalance for value true and the API to return success */
    result = EnableWhiteBalance(true);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings to Set the EnableWhiteBalance for value true and the API to return tvERROR_INVALID_STATE */
        result = EnableWhiteBalance(true);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate EnableDynamicContrast() for all positive invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 223@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | bool | tvERROR_NONE | Should Pass |
 * | 02 | Call EnableDynamicContrast() - Enable Dynamic Contrast  with valid value | true | tvERROR_NONE | Should Pass |
 * | 03 | call EnableDynamicContrast() - Disable Dynamic Contrast with valid value | false | tvERROR_NONE | Should Pass |
 * | 04 | call EnableDynamicContrast() - Enable Dynamic Contrast with valid value | true | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | bool | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_EnableDynamicContrast (void)
{
    gTestID = 223;                                    /* It must be 223 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings to Set the EnableDynamicContrast for value true and the API to return success */
    result = EnableDynamicContrast(true);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the EnableDynamicContrast for value true and the API to return success */
    result = EnableDynamicContrast(false);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings to Set the EnableDynamicContrast for value true and the API to return success */
    result = EnableDynamicContrast(true);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 05: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate EnableDynamicContrast() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 224@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call EnableDynamicContrast() - Enable Dynamic Contrast even before TvInit() | true | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call EnableDynamicContrast() -  Enable Dynamic Contrast valid input | true | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call EnableDynamicContrast() -  Enable Dynamic Contrast valid input after TvTerm() | true | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_EnableDynamicContrast (void)
{
    gTestID = 224;                                    /* It must be 224 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings to Set the EnableDynamicContrast for value true and the API to return tvERROR_INVALID_STATE */
        result = EnableDynamicContrast(true);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the EnableDynamicContrast for value true and the API to return success */
    result = EnableDynamicContrast(true);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings to Set the EnableDynamicContrast for value true and the API to return tvERROR_INVALID_STATE */
        result = EnableDynamicContrast(true);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate EnableLocalContrast() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 225@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call EnableLocalContrast() - Enable Local Contrast with valid value | true | tvERROR_NONE | Should Pass |
 * | 03 | call EnableLocalContrast() - Enable Local Contrast with valid value | false | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_EnableLocalContrast (void)
{
    gTestID = 225;                                    /* It must be 225 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings to Set the EnableLocalContrast for value true and the API to return success */
    result = EnableLocalContrast(true);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the EnableLocalContrast for value true and the API to return success */
    result = EnableLocalContrast(false);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate EnableLocalContrast() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 226@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call EnableLocalContrast() - Enable Local Contrast even before TvInit() | true | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call EnableLocalContrast() - Enable Local Contrast with valid value | true | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call EnableLocalContrast() -  Enable Local Contrast valid input after TvTerm() | true | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_EnableLocalContrast (void)
{
    gTestID = 226;                                    /* It must be 226 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings to Set the EnableLocalContrast for value true and the API to return tvERROR_INVALID_STATE */
        result = EnableLocalContrast(true);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings to Set the EnableLocalContrast for value true and the API to return success */
    result = EnableLocalContrast(true);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Calling tvsettings to Set the EnableLocalContrast for value true and the API to return tvERROR_INVALID_STATE */
        result = EnableLocalContrast(true);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetLdimZoneShortCircuitStatus() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 227@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetLdimZoneShortCircuitStatus() -  Retrieve the shortCircuit Status | unsigned char *, unsigned int, int *  | tvERROR_NONE | Should Pass |
 * | 03 | call GetLdimZoneShortCircuitStatus()-  Retrieve the shortCircuit Status with valid argument and validate with above value | unsigned char *, unsigned int, int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetLdimZoneShortCircuitStatus (void)
{
    gTestID = 227;                                    /* It must be 227 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int shortCircuitStatus = -1;
    int shortCircuitStatusRetry = -1;
    unsigned int listsize = UT_KVP_PROFILE_GET_UINT32("tvSettings/LDIMShortCircuitStatus/size");
    unsigned char shortcircuitlist[listsize > 0? listsize: 1];
    unsigned char shortcircuitlistRetry[listsize > 0? listsize: 1];
    // Initialize array elements to 0
    for (int i = 0; i < listsize; i++ ) {
        shortcircuitlist[i] = 0; 
        shortcircuitlistRetry[i] = 0;
    }

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetLdimZoneShortCircuitStatus and the API to return success */
    if(UT_KVP_PROFILE_GET_BOOL("tvSettings/LDIMShortCircuitStatus/enable") == true) {
        result = GetLdimZoneShortCircuitStatus(shortcircuitlist, listsize, &shortCircuitStatus);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
        UT_ASSERT_TRUE((shortCircuitStatus >= 0));

        /* Step 03: Calling tvsettings GetLdimZoneShortCircuitStatus again and the API to return success */
        result = GetLdimZoneShortCircuitStatus(shortcircuitlistRetry, listsize, &shortCircuitStatusRetry);
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
        UT_ASSERT_EQUAL(shortCircuitStatus, shortCircuitStatusRetry);
    } else {
        result = GetLdimZoneShortCircuitStatus(shortcircuitlist, listsize, &shortCircuitStatus);
        UT_ASSERT_EQUAL(result, tvERROR_OPERATION_NOT_SUPPORTED);
    }

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetLdimZoneShortCircuitStatus() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 228@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetLdimZoneShortCircuitStatus() -  Retrieve current TV shortCircuit Status even before TvInit() | unsigned char *, unsigned int, int * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetLdimZoneShortCircuitStatus() -  Retrieve current TV shortCircuit Status with invalid input status | unsigned char *, unsigned int, NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetLdimZoneShortCircuitStatus() -  Retrieve current TV shortCircuit Status with invalid input shortCircuitlist | NULL , unsigned int, int* | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetLdimZoneShortCircuitStatus() -  Retrieve current TV shortCircuit Status with invalid input size | unsigned char *, 0 , int* | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call GetLdimZoneShortCircuitStatus() -  Retrieve current TV shortCircuit Status with invalid input size | unsigned char *, -1 , int* | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 08 | call GetLdimZoneShortCircuitStatus() -  Retrieve current TV shortCircuit Status valid arguments | unsigned char *, unsigned int, int* | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetLdimZoneShortCircuitStatus (void)
{
    gTestID = 228;                                    /* It must be 228 */
    UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    int shortCircuitStatus = -1;
    unsigned int listsize = UT_KVP_PROFILE_GET_UINT32("tvSettings/LDIMShortCircuitStatus/size");
    unsigned char shortcircuitlist[listsize > 0? listsize: 1];
    // Initialize array elements to 0
    for (int i = 0; i < listsize; i++ ) {
        shortcircuitlist[i] = 0; 
    }

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings GetLdimZoneShortCircuitStatus and the API to return tvERROR_INVALID_STATE */
        result = GetLdimZoneShortCircuitStatus(shortcircuitlist, listsize, &shortCircuitStatus);

        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if(UT_KVP_PROFILE_GET_BOOL("tvSettings/LDIMShortCircuitStatus/enable") == true) {
        /* Step 03: Calling tvsettings GetLdimZoneShortCircuitStatus for invalid status */
        result = GetLdimZoneShortCircuitStatus(shortcircuitlist, listsize, NULL);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        /* Step 04: Calling tvsettings GetLdimZoneShortCircuitStatus for invalid shortcircuitlist */
        result = GetLdimZoneShortCircuitStatus(NULL, listsize, &shortCircuitStatus);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        /* Step 05: Calling tvsettings GetLdimZoneShortCircuitStatus for invalid size */
        result = GetLdimZoneShortCircuitStatus(shortcircuitlist, 0, &shortCircuitStatus);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
        /* Step 06: Calling tvsettings GetLdimZoneShortCircuitStatus for invalid size */
        result = GetLdimZoneShortCircuitStatus(shortcircuitlist, -1, &shortCircuitStatus);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
    } else {
        result = GetLdimZoneShortCircuitStatus(shortcircuitlist, listsize, NULL);
        UT_ASSERT_EQUAL(result, tvERROR_OPERATION_NOT_SUPPORTED);
        result = GetLdimZoneShortCircuitStatus(NULL, listsize, &shortCircuitStatus);
        UT_ASSERT_EQUAL(result, tvERROR_OPERATION_NOT_SUPPORTED);
        result = GetLdimZoneShortCircuitStatus(shortcircuitlist, 0, &shortCircuitStatus);
        UT_ASSERT_EQUAL(result, tvERROR_OPERATION_NOT_SUPPORTED);
    }

    /* Step 06: Calling tvsettings termination and expecting the API to return success */

    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 07: Calling tvsettings GetLdimZoneShortCircuitStatus and the API to return tvERROR_INVALID_STATE */
        result = GetLdimZoneShortCircuitStatus(shortcircuitlist, listsize, &shortCircuitStatus);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }
}

/**
 * @brief Validate GetNumberOfDimmingZones() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 227@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | unsigned int* | tvERROR_NONE | Should Pass |
 * | 02 | call GetNumberOfDimmingZones() -  GetNumberOfDimmingZones Status | unsigned int*  | tvERROR_NONE | Should Pass |
 * | 03 | call GetNumberOfDimmingZones() -  GetNumberOfDimmingZones Status with valid argument and validate with above value | unsigned int* | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetNumberOfDimmingZones (void)
{
	gTestID = 227;   /* It must be 227 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    unsigned int number_of_dimming_zones = 0;
    unsigned int number_of_dimming_zones_retry = 0;

    /* Step 01: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 02: Calling tvsettings GetNumberOfDimmingZones and the API to return success */
    result = GetNumberOfDimmingZones(&number_of_dimming_zones);
    if(UT_KVP_PROFILE_GET_BOOL("tvSettings/LDIMShortCircuitStatus/enable") == true) {
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
    } else {
        UT_ASSERT_EQUAL(result, tvERROR_OPERATION_NOT_SUPPORTED);
    }

    /* Step 03: Retry tvsettings GetNumberOfDimmingZones and the API to return success */
    result = GetNumberOfDimmingZones(&number_of_dimming_zones_retry);
    if(UT_KVP_PROFILE_GET_BOOL("tvSettings/LDIMShortCircuitStatus/enable") == true) {
        UT_ASSERT_EQUAL(result, tvERROR_NONE);
    } else {
        UT_ASSERT_EQUAL(result, tvERROR_OPERATION_NOT_SUPPORTED);
    }

    UT_ASSERT_EQUAL(number_of_dimming_zones_retry, number_of_dimming_zones);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetNumberOfDimmingZones() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 228@n
 *
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 *
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetNumberOfDimmingZones() -  GetNumberOfDimmingZones Status before TvInit() | unsigned int*  | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetNumberOfDimmingZones() -  GetNumberOfDimmingZones Status with invalid argument and | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetNumberOfDimmingZones() -  GetNumberOfDimmingZones Status with valid argument | unsigned int* | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetNumberOfDimmingZones (void)
{
	gTestID = 228;   /* It must be 228 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

    tvError_t result = tvERROR_NONE ;
    unsigned int number_of_dimming_zones = 0;

    if (extendedEnumsSupported == true)
    {
        /* Step 01: Calling tvsettings tvERROR_INVALID_STATE and the API to return tvERROR_INVALID_STATE */
        result = GetNumberOfDimmingZones(&number_of_dimming_zones);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    /* Step 02: Calling tvsettings initialization and expecting the API to return success */
    result = TvInit();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    /* Step 03: Calling tvsettings GetNumberOfDimmingZones and the API to return tvERROR_INVALID_PARAM */
    result = GetNumberOfDimmingZones(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

    /* Step 04: Calling tvsettings termination and expecting the API to return success */
    result = TvTerm();
    UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

    if (extendedEnumsSupported == true)
    {
        /* Step 05: Retry tvsettings GetNumberOfDimmingZones and the API to return tvERROR_INVALID_STATE */
        result = GetNumberOfDimmingZones(&number_of_dimming_zones);
        UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    }

    UT_LOG("Out %s",__FUNCTION__);
}


static UT_test_suite_t * pSuite = NULL;

/**
 * @brief Register the main test(s) for this module
 *
 * @return int - 0 on success, otherwise failure
 */
int test_l1_tvSettings_register ( void )
{
    UT_LOG("\n*******UT version Number : %d.%d*********\n", UT_VERSION_MAJOR, UT_VERSION_MINOR);
    extendedEnumsSupported = UT_KVP_PROFILE_GET_BOOL("tvSettings/features/extendedEnumsSupported" );
    /* add a suite to the registry */
    pSuite = UT_add_suite( "[L1 tvSettings]", NULL, NULL );
    if ( NULL == pSuite )
    {
        return -1;
    }

    UT_add_test( pSuite, "TvInit_L1_positive" ,test_l1_tvSettings_positive_TvInit );
    UT_add_test( pSuite, "TvInit_L1_negative" ,test_l1_tvSettings_negative_TvInit );
    UT_add_test( pSuite, "TvTerm_L1_positive" ,test_l1_tvSettings_positive_TvTerm );
    UT_add_test( pSuite, "TvTerm_L1_negative" ,test_l1_tvSettings_negative_TvTerm );
    UT_add_test( pSuite, "GetTVSupportedVideoFormats_L1_positive" ,test_l1_tvSettings_positive_GetTVSupportedVideoFormats );
    UT_add_test( pSuite, "GetTVSupportedVideoFormats_L1_negative" ,test_l1_tvSettings_negative_GetTVSupportedVideoFormats );
    UT_add_test( pSuite, "GetCurrentVideoFormat_L1_positive" ,test_l1_tvSettings_positive_GetCurrentVideoFormat );
    UT_add_test( pSuite, "GetCurrentVideoFormat_L1_negative" ,test_l1_tvSettings_negative_GetCurrentVideoFormat );
    UT_add_test( pSuite, "GetCurrentVideoResolution_L1_positive" ,test_l1_tvSettings_positive_GetCurrentVideoResolution );
    UT_add_test( pSuite, "GetCurrentVideoResolution_L1_negative" ,test_l1_tvSettings_negative_GetCurrentVideoResolution );
    UT_add_test( pSuite, "GetCurrentVideoFrameRate_L1_positive" ,test_l1_tvSettings_positive_GetCurrentVideoFrameRate );
    UT_add_test( pSuite, "GetCurrentVideoFrameRate_L1_negative" ,test_l1_tvSettings_negative_GetCurrentVideoFrameRate );
    UT_add_test( pSuite, "GetCurrentVideoSource_L1_positive" ,test_l1_tvSettings_positive_GetCurrentVideoSource );
    UT_add_test( pSuite, "GetCurrentVideoSource_L1_negative" ,test_l1_tvSettings_negative_GetCurrentVideoSource );
    UT_add_test( pSuite, "GetTVSupportedVideoSources_L1_positive" ,test_l1_tvSettings_positive_GetTVSupportedVideoSources );
    UT_add_test( pSuite, "GetTVSupportedVideoSources_L1_negative" ,test_l1_tvSettings_negative_GetTVSupportedVideoSources );
    UT_add_test( pSuite, "GetBacklight_L1_positive" ,test_l1_tvSettings_positive_GetBacklight );
    UT_add_test( pSuite, "GetBacklight_L1_negative" ,test_l1_tvSettings_negative_GetBacklight );
    UT_add_test( pSuite, "SetBacklight_L1_positive" ,test_l1_tvSettings_positive_SetBacklight );
    UT_add_test( pSuite, "SetBacklight_L1_negative" ,test_l1_tvSettings_negative_SetBacklight );
    UT_add_test( pSuite, "SaveBacklight_L1_positive" ,test_l1_tvSettings_positive_SaveBacklight );
    UT_add_test( pSuite, "SaveBacklight_L1_negative" ,test_l1_tvSettings_negative_SaveBacklight );
    UT_add_test( pSuite, "SetBacklightFade_L1_positive" ,test_l1_tvSettings_positive_SetBacklightFade );
    UT_add_test( pSuite, "SetBacklightFade_L1_negative" ,test_l1_tvSettings_negative_SetBacklightFade );
    UT_add_test( pSuite, "GetBacklightFade_L1_positive" ,test_l1_tvSettings_positive_GetCurrentBacklightFade );
    UT_add_test( pSuite, "GetBacklightFade_L1_negative" ,test_l1_tvSettings_negative_GetCurrentBacklightFade );
    UT_add_test( pSuite, "GetSupportedBacklightModes_L1_positive" ,test_l1_tvSettings_positive_GetSupportedBacklightModes );
    UT_add_test( pSuite, "GetSupportedBacklightModes_L1_negative" ,test_l1_tvSettings_negative_GetSupportedBacklightModes );
    UT_add_test( pSuite, "GetCurrentBacklightMode_L1_positive" ,test_l1_tvSettings_positive_GetCurrentBacklightMode );
    UT_add_test( pSuite, "GetCurrentBacklightMode_L1_negative" ,test_l1_tvSettings_negative_GetCurrentBacklightMode );
    UT_add_test( pSuite, "SetCurrentBacklightMode_L1_positive" ,test_l1_tvSettings_positive_SetCurrentBacklightMode );
    UT_add_test( pSuite, "SetCurrentBacklightMode_L1_negative" ,test_l1_tvSettings_negative_SetCurrentBacklightMode );
    UT_add_test( pSuite, "GetTVSupportedDimmingModes_L1_positive" ,test_l1_tvSettings_positive_GetTVSupportedDimmingModes );
    UT_add_test( pSuite, "GetTVSupportedDimmingModes_L1_negative" ,test_l1_tvSettings_negative_GetTVSupportedDimmingModes );
    UT_add_test( pSuite, "SetTVDimmingMode_L1_positive" ,test_l1_tvSettings_positive_SetTVDimmingMode );
    UT_add_test( pSuite, "SetTVDimmingMode_L1_negative" ,test_l1_tvSettings_negative_SetTVDimmingMode );
    UT_add_test( pSuite, "GetTVDimmingMode_L1_positive" ,test_l1_tvSettings_positive_GetTVDimmingMode );
    UT_add_test( pSuite, "GetTVDimmingMode_L1_negative" ,test_l1_tvSettings_negative_GetTVDimmingMode );
    UT_add_test( pSuite, "SaveTVDimmingMode_L1_positive" ,test_l1_tvSettings_positive_SaveTVDimmingMode );
    UT_add_test( pSuite, "SaveTVDimmingMode_L1_negative" ,test_l1_tvSettings_negative_SaveTVDimmingMode );
    UT_add_test( pSuite, "SetLocalDimmingLevel_L1_positive" ,test_l1_tvSettings_positive_SetLocalDimmingLevel );
    UT_add_test( pSuite, "SetLocalDimmingLevel_L1_negative" ,test_l1_tvSettings_negative_SetLocalDimmingLevel );
    UT_add_test( pSuite, "GetLocalDimmingLevel_L1_positive" ,test_l1_tvSettings_positive_GetLocalDimmingLevel );
    UT_add_test( pSuite, "GetLocalDimmingLevel_L1_negative" ,test_l1_tvSettings_negative_GetLocalDimmingLevel );
    UT_add_test( pSuite, "SaveLocalDimmingLevel_L1_positive" ,test_l1_tvSettings_positive_SaveLocalDimmingLevel );
    UT_add_test( pSuite, "SaveLocalDimmingLevel_L1_negative" ,test_l1_tvSettings_negative_SaveLocalDimmingLevel );
    UT_add_test( pSuite, "SetBrightness_L1_positive" ,test_l1_tvSettings_positive_SetBrightness );
    UT_add_test( pSuite, "SetBrightness_L1_negative" ,test_l1_tvSettings_negative_SetBrightness );
    UT_add_test( pSuite, "GetBrightness_L1_positive" ,test_l1_tvSettings_positive_GetBrightness );
    UT_add_test( pSuite, "GetBrightness_L1_negative" ,test_l1_tvSettings_negative_GetBrightness );
    UT_add_test( pSuite, "SaveBrightness_L1_positive" ,test_l1_tvSettings_positive_SaveBrightness );
    UT_add_test( pSuite, "SaveBrightness_L1_negative" ,test_l1_tvSettings_negative_SaveBrightness );
    UT_add_test( pSuite, "SetContrast_L1_positive" ,test_l1_tvSettings_positive_SetContrast );
    UT_add_test( pSuite, "SetContrast_L1_negative" ,test_l1_tvSettings_negative_SetContrast );
    UT_add_test( pSuite, "GetContrast_L1_positive" ,test_l1_tvSettings_positive_GetContrast );
    UT_add_test( pSuite, "GetContrast_L1_negative" ,test_l1_tvSettings_negative_GetContrast );
    UT_add_test( pSuite, "SaveContrast_L1_positive" ,test_l1_tvSettings_positive_SaveContrast );
    UT_add_test( pSuite, "SaveContrast_L1_negative" ,test_l1_tvSettings_negative_SaveContrast );
    UT_add_test( pSuite, "SetSharpness_L1_positive" ,test_l1_tvSettings_positive_SetSharpness );
    UT_add_test( pSuite, "SetSharpness_L1_negative" ,test_l1_tvSettings_negative_SetSharpness );
    UT_add_test( pSuite, "GetSharpness_L1_positive" ,test_l1_tvSettings_positive_GetSharpness );
    UT_add_test( pSuite, "GetSharpness_L1_negative" ,test_l1_tvSettings_negative_GetSharpness );
    UT_add_test( pSuite, "SaveSharpness_L1_positive" ,test_l1_tvSettings_positive_SaveSharpness );
    UT_add_test( pSuite, "SaveSharpness_L1_negative" ,test_l1_tvSettings_negative_SaveSharpness );
    UT_add_test( pSuite, "SetSaturation_L1_positive" ,test_l1_tvSettings_positive_SetSaturation );
    UT_add_test( pSuite, "SetSaturation_L1_negative" ,test_l1_tvSettings_negative_SetSaturation );
    UT_add_test( pSuite, "GetSaturation_L1_positive" ,test_l1_tvSettings_positive_GetSaturation );
    UT_add_test( pSuite, "GetSaturation_L1_negative" ,test_l1_tvSettings_negative_GetSaturation );
    UT_add_test( pSuite, "SaveSaturation_L1_positive" ,test_l1_tvSettings_positive_SaveSaturation );
    UT_add_test( pSuite, "SaveSaturation_L1_negative" ,test_l1_tvSettings_negative_SaveSaturation );
    UT_add_test( pSuite, "GetNumberOfDimmingZones_L1_positive" ,test_l1_tvSettings_positive_GetNumberOfDimmingZones );
    UT_add_test( pSuite, "GetNumberOfDimmingZones_L1_negative" ,test_l1_tvSettings_negative_GetNumberOfDimmingZones );
    UT_add_test( pSuite, "SetHue_L1_positive" ,test_l1_tvSettings_positive_SetHue );
    UT_add_test( pSuite, "SetHue_L1_negative" ,test_l1_tvSettings_negative_SetHue );
    UT_add_test( pSuite, "GetHue_L1_positive" ,test_l1_tvSettings_positive_GetHue );
    UT_add_test( pSuite, "GetHue_L1_negative" ,test_l1_tvSettings_negative_GetHue );
    UT_add_test( pSuite, "SaveHue_L1_positive" ,test_l1_tvSettings_positive_SaveHue );
    UT_add_test( pSuite, "SaveHue_L1_negative" ,test_l1_tvSettings_negative_SaveHue );
    UT_add_test( pSuite, "SetColorTemperature_L1_positive" ,test_l1_tvSettings_positive_SetColorTemperature );
    UT_add_test( pSuite, "SetColorTemperature_L1_negative" ,test_l1_tvSettings_negative_SetColorTemperature );
    UT_add_test( pSuite, "GetColorTemperature_L1_positive" ,test_l1_tvSettings_positive_GetColorTemperature );
    UT_add_test( pSuite, "GetColorTemperature_L1_negative" ,test_l1_tvSettings_negative_GetColorTemperature );
    UT_add_test( pSuite, "SaveColorTemperature_L1_positive" ,test_l1_tvSettings_positive_SaveColorTemperature );
    UT_add_test( pSuite, "SaveColorTemperature_L1_negative" ,test_l1_tvSettings_negative_SaveColorTemperature );
    UT_add_test( pSuite, "SetAspectRatio_L1_positive" ,test_l1_tvSettings_positive_SetAspectRatio );
    UT_add_test( pSuite, "SetAspectRatio_L1_negative" ,test_l1_tvSettings_negative_SetAspectRatio );
    UT_add_test( pSuite, "GetAspectRatio_L1_positive" ,test_l1_tvSettings_positive_GetAspectRatio );
    UT_add_test( pSuite, "GetAspectRatio_L1_negative" ,test_l1_tvSettings_negative_GetAspectRatio );
    UT_add_test( pSuite, "SaveAspectRatio_L1_positive" ,test_l1_tvSettings_positive_SaveAspectRatio );
    UT_add_test( pSuite, "SaveAspectRatio_L1_negative" ,test_l1_tvSettings_negative_SaveAspectRatio );
    UT_add_test( pSuite, "SetLowLatencyState_L1_positive" ,test_l1_tvSettings_positive_SetLowLatencyState );
    UT_add_test( pSuite, "SetLowLatencyState_L1_negative" ,test_l1_tvSettings_negative_SetLowLatencyState );
    UT_add_test( pSuite, "GetLowLatencyState_L1_positive" ,test_l1_tvSettings_positive_GetLowLatencyState );
    UT_add_test( pSuite, "GetLowLatencyState_L1_negative" ,test_l1_tvSettings_negative_GetLowLatencyState );
    UT_add_test( pSuite, "SaveLowLatencyState_L1_positive" ,test_l1_tvSettings_positive_SaveLowLatencyState );
    UT_add_test( pSuite, "SaveLowLatencyState_L1_negative" ,test_l1_tvSettings_negative_SaveLowLatencyState );
    UT_add_test( pSuite, "SetDynamicContrast_L1_positive" ,test_l1_tvSettings_positive_SetDynamicContrast );
    UT_add_test( pSuite, "SetDynamicContrast_L1_negative" ,test_l1_tvSettings_negative_SetDynamicContrast );
    UT_add_test( pSuite, "GetDynamicContrast_L1_positive" ,test_l1_tvSettings_positive_GetDynamicContrast );
    UT_add_test( pSuite, "GetDynamicContrast_L1_negative" ,test_l1_tvSettings_negative_GetDynamicContrast );
    UT_add_test( pSuite, "SetDynamicGamma_L1_positive" ,test_l1_tvSettings_positive_SetDynamicGamma );
    UT_add_test( pSuite, "SetDynamicGamma_L1_negative" ,test_l1_tvSettings_negative_SetDynamicGamma );
    UT_add_test( pSuite, "GetDynamicGamma_L1_positive" ,test_l1_tvSettings_positive_GetDynamicGamma );
    UT_add_test( pSuite, "GetDynamicGamma_L1_negative" ,test_l1_tvSettings_negative_GetDynamicGamma );
    UT_add_test( pSuite, "GetTVSupportedDolbyVisionModes_L1_positive" ,test_l1_tvSettings_positive_GetTVSupportedDolbyVisionModes );
    UT_add_test( pSuite, "GetTVSupportedDolbyVisionModes_L1_negative" ,test_l1_tvSettings_negative_GetTVSupportedDolbyVisionModes );
    UT_add_test( pSuite, "SetTVDolbyVisionMode_L1_positive" ,test_l1_tvSettings_positive_SetTVDolbyVisionMode );
    UT_add_test( pSuite, "SetTVDolbyVisionMode_L1_negative" ,test_l1_tvSettings_negative_SetTVDolbyVisionMode );
    UT_add_test( pSuite, "GetTVDolbyVisionMode_L1_positive" ,test_l1_tvSettings_positive_GetTVDolbyVisionMode );
    UT_add_test( pSuite, "GetTVDolbyVisionMode_L1_negative" ,test_l1_tvSettings_negative_GetTVDolbyVisionMode );
    UT_add_test( pSuite, "SaveTVDolbyVisionMode_L1_positive" ,test_l1_tvSettings_positive_SaveTVDolbyVisionMode );
    UT_add_test( pSuite, "SaveTVDolbyVisionMode_L1_negative" ,test_l1_tvSettings_negative_SaveTVDolbyVisionMode );
    UT_add_test( pSuite, "GetTVSupportedPictureModes_L1_positive" ,test_l1_tvSettings_positive_GetTVSupportedPictureModes );
    UT_add_test( pSuite, "GetTVSupportedPictureModes_L1_negative" ,test_l1_tvSettings_negative_GetTVSupportedPictureModes );
    UT_add_test( pSuite, "GetTVPictureMode_L1_positive" ,test_l1_tvSettings_positive_GetTVPictureMode );
    UT_add_test( pSuite, "GetTVPictureMode_L1_negative" ,test_l1_tvSettings_negative_GetTVPictureMode );
    UT_add_test( pSuite, "SetTVPictureMode_L1_positive" ,test_l1_tvSettings_positive_SetTVPictureMode );
    UT_add_test( pSuite, "SetTVPictureMode_L1_negative" ,test_l1_tvSettings_negative_SetTVPictureMode );
    UT_add_test( pSuite, "SaveSourcePictureMode_L1_positive" ,test_l1_tvSettings_positive_SaveSourcePictureMode );
    UT_add_test( pSuite, "SaveSourcePictureMode_L1_negative" ,test_l1_tvSettings_negative_SaveSourcePictureMode );
    UT_add_test( pSuite, "SetColorTemp_Rgain_onSource_L1_positive" ,test_l1_tvSettings_positive_SetColorTemp_Rgain_onSource );
    UT_add_test( pSuite, "SetColorTemp_Rgain_onSource_L1_negative" ,test_l1_tvSettings_negative_SetColorTemp_Rgain_onSource );
    UT_add_test( pSuite, "GetColorTemp_Rgain_onSource_L1_positive" ,test_l1_tvSettings_positive_GetColorTemp_Rgain_onSource );
    UT_add_test( pSuite, "GetColorTemp_Rgain_onSource_L1_negative" ,test_l1_tvSettings_negative_GetColorTemp_Rgain_onSource );
    UT_add_test( pSuite, "SetColorTemp_Ggain_onSource_L1_positive" ,test_l1_tvSettings_positive_SetColorTemp_Ggain_onSource );
    UT_add_test( pSuite, "SetColorTemp_Ggain_onSource_L1_negative" ,test_l1_tvSettings_negative_SetColorTemp_Ggain_onSource );
    UT_add_test( pSuite, "GetColorTemp_Ggain_onSource_L1_positive" ,test_l1_tvSettings_positive_GetColorTemp_Ggain_onSource );
    UT_add_test( pSuite, "GetColorTemp_Ggain_onSource_L1_negative" ,test_l1_tvSettings_negative_GetColorTemp_Ggain_onSource );
    UT_add_test( pSuite, "SetColorTemp_Bgain_onSource_L1_positive" ,test_l1_tvSettings_positive_SetColorTemp_Bgain_onSource );
    UT_add_test( pSuite, "SetColorTemp_Bgain_onSource_L1_negative" ,test_l1_tvSettings_negative_SetColorTemp_Bgain_onSource );
    UT_add_test( pSuite, "GetColorTemp_Bgain_onSource_L1_positive" ,test_l1_tvSettings_positive_GetColorTemp_Bgain_onSource );
    UT_add_test( pSuite, "GetColorTemp_Bgain_onSource_L1_negative" ,test_l1_tvSettings_negative_GetColorTemp_Bgain_onSource );
    UT_add_test( pSuite, "SetColorTemp_R_post_offset_onSource_L1_positive" ,test_l1_tvSettings_positive_SetColorTemp_R_post_offset_onSource );
    UT_add_test( pSuite, "SetColorTemp_R_post_offset_onSource_L1_negative" ,test_l1_tvSettings_negative_SetColorTemp_R_post_offset_onSource );
    UT_add_test( pSuite, "GetColorTemp_R_post_offset_onSource_L1_positive" ,test_l1_tvSettings_positive_GetColorTemp_R_post_offset_onSource );
    UT_add_test( pSuite, "GetColorTemp_R_post_offset_onSource_L1_negative" ,test_l1_tvSettings_negative_GetColorTemp_R_post_offset_onSource );
    UT_add_test( pSuite, "SetColorTemp_G_post_offset_onSource_L1_positive" ,test_l1_tvSettings_positive_SetColorTemp_G_post_offset_onSource );
    UT_add_test( pSuite, "SetColorTemp_G_post_offset_onSource_L1_negative" ,test_l1_tvSettings_negative_SetColorTemp_G_post_offset_onSource );
    UT_add_test( pSuite, "GetColorTemp_G_post_offset_onSource_L1_positive" ,test_l1_tvSettings_positive_GetColorTemp_G_post_offset_onSource );
    UT_add_test( pSuite, "GetColorTemp_G_post_offset_onSource_L1_negative" ,test_l1_tvSettings_negative_GetColorTemp_G_post_offset_onSource );
    UT_add_test( pSuite, "SetColorTemp_B_post_offset_onSource_L1_positive" ,test_l1_tvSettings_positive_SetColorTemp_B_post_offset_onSource );
    UT_add_test( pSuite, "SetColorTemp_B_post_offset_onSource_L1_negative" ,test_l1_tvSettings_negative_SetColorTemp_B_post_offset_onSource );
    UT_add_test( pSuite, "GetColorTemp_B_post_offset_onSource_L1_positive" ,test_l1_tvSettings_positive_GetColorTemp_B_post_offset_onSource );
    UT_add_test( pSuite, "GetColorTemp_B_post_offset_onSource_L1_negative" ,test_l1_tvSettings_negative_GetColorTemp_B_post_offset_onSource );
    UT_add_test( pSuite, "EnableWBCalibrationMode_L1_positive" ,test_l1_tvSettings_positive_EnableWBCalibrationMode );
    UT_add_test( pSuite, "EnableWBCalibrationMode_L1_negative" ,test_l1_tvSettings_negative_EnableWBCalibrationMode );
    UT_add_test( pSuite, "GetCurrentWBCalibrationMode_L1_positive", test_l1_tvSettings_positive_GetCurrentWBCalibrationMode);
    UT_add_test( pSuite, "GetCurrentWBCalibrationMode_L1_negative", test_l1_tvSettings_negative_GetCurrentWBCalibrationMode);
    UT_add_test( pSuite, "SetGammaTable_L1_positive" ,test_l1_tvSettings_positive_SetGammaTable );
    UT_add_test( pSuite, "SetGammaTable_L1_negative" ,test_l1_tvSettings_negative_SetGammaTable );
    UT_add_test( pSuite, "GetDefaultGammaTable_L1_positive" ,test_l1_tvSettings_positive_GetDefaultGammaTable );
    UT_add_test( pSuite, "GetDefaultGammaTable_L1_negative" ,test_l1_tvSettings_negative_GetDefaultGammaTable );
    UT_add_test( pSuite, "GetGammaTable_L1_positive" ,test_l1_tvSettings_positive_GetGammaTable );
    UT_add_test( pSuite, "GetGammaTable_L1_negative" ,test_l1_tvSettings_negative_GetGammaTable );
    UT_add_test( pSuite, "SaveGammaTable_L1_positive" ,test_l1_tvSettings_positive_SaveGammaTable );
    UT_add_test( pSuite, "SaveGammaTable_L1_negative" ,test_l1_tvSettings_negative_SaveGammaTable );
    UT_add_test( pSuite, "SetDvTmaxValue_L1_positive" ,test_l1_tvSettings_positive_SetDvTmaxValue );
    UT_add_test( pSuite, "SetDvTmaxValue_L1_negative" ,test_l1_tvSettings_negative_SetDvTmaxValue );
    UT_add_test( pSuite, "GetDvTmaxValue_L1_positive" ,test_l1_tvSettings_positive_GetDvTmaxValue );
    UT_add_test( pSuite, "GetDvTmaxValue_L1_negative" ,test_l1_tvSettings_negative_GetDvTmaxValue );
    UT_add_test( pSuite, "SaveDvTmaxValue_L1_positive" ,test_l1_tvSettings_positive_SaveDvTmaxValue );
    UT_add_test( pSuite, "SaveDvTmaxValue_L1_negative" ,test_l1_tvSettings_negative_SaveDvTmaxValue );
    UT_add_test( pSuite, "GetSupportedComponentColor_L1_positive" ,test_l1_tvSettings_positive_GetSupportedComponentColor );
    UT_add_test( pSuite, "GetSupportedComponentColor_L1_negative" ,test_l1_tvSettings_negative_GetSupportedComponentColor );
    UT_add_test( pSuite, "SetCurrentComponentSaturation_L1_positive" ,test_l1_tvSettings_positive_SetCurrentComponentSaturation );
    UT_add_test( pSuite, "SetCurrentComponentSaturation_L1_negative" ,test_l1_tvSettings_negative_SetCurrentComponentSaturation );
    UT_add_test( pSuite, "GetCurrentComponentSaturation_L1_positive" ,test_l1_tvSettings_positive_GetCurrentComponentSaturation );
    UT_add_test( pSuite, "GetCurrentComponentSaturation_L1_negative" ,test_l1_tvSettings_negative_GetCurrentComponentSaturation );
    UT_add_test( pSuite, "SetCurrentComponentHue_L1_positive" ,test_l1_tvSettings_positive_SetCurrentComponentHue );
    UT_add_test( pSuite, "SetCurrentComponentHue_L1_negative" ,test_l1_tvSettings_negative_SetCurrentComponentHue );
    UT_add_test( pSuite, "GetCurrentComponentHue_L1_positive" ,test_l1_tvSettings_positive_GetCurrentComponentHue );
    UT_add_test( pSuite, "GetCurrentComponentHue_L1_negative" ,test_l1_tvSettings_negative_GetCurrentComponentHue );
    UT_add_test( pSuite, "SetCurrentComponentLuma_L1_positive" ,test_l1_tvSettings_positive_SetCurrentComponentLuma );
    UT_add_test( pSuite, "SetCurrentComponentLuma_L1_negative" ,test_l1_tvSettings_negative_SetCurrentComponentLuma );
    UT_add_test( pSuite, "GetCurrentComponentLuma_L1_positive" ,test_l1_tvSettings_positive_GetCurrentComponentLuma );
    UT_add_test( pSuite, "GetCurrentComponentLuma_L1_negative" ,test_l1_tvSettings_negative_GetCurrentComponentLuma );
    UT_add_test( pSuite, "SaveCMS_L1_positive" ,test_l1_tvSettings_positive_SaveCMS );
    UT_add_test( pSuite, "SaveCMS_L1_negative" ,test_l1_tvSettings_negative_SaveCMS );
    UT_add_test( pSuite, "SetCMSState_L1_positive" ,test_l1_tvSettings_positive_SetCMSState );
    UT_add_test( pSuite, "SetCMSState_L1_negative" ,test_l1_tvSettings_negative_SetCMSState );
    UT_add_test( pSuite, "GetCMSState_L1_positive" ,test_l1_tvSettings_positive_GetCMSState );
    UT_add_test( pSuite, "GetCMSState_L1_negative" ,test_l1_tvSettings_negative_GetCMSState );
    UT_add_test( pSuite, "GetDefaultPQParams_L1_positive" ,test_l1_tvSettings_positive_GetDefaultPQParams );
    UT_add_test( pSuite, "GetDefaultPQParams_L1_negative" ,test_l1_tvSettings_negative_GetDefaultPQParams );
    UT_add_test( pSuite, "GetPQParams_L1_positive" ,test_l1_tvSettings_positive_GetPQParams );
    UT_add_test( pSuite, "GetPQParams_L1_negative" ,test_l1_tvSettings_negative_GetPQParams );
    UT_add_test( pSuite, "GetMaxGainValue_L1_positive" ,test_l1_tvSettings_positive_GetMaxGainValue );
    UT_add_test( pSuite, "GetMaxGainValue_L1_negative" ,test_l1_tvSettings_negative_GetMaxGainValue );
    UT_add_test( pSuite, "EnableGammaMode_L1_positive" ,test_l1_tvSettings_positive_EnableGammaMode );
    UT_add_test( pSuite, "EnableGammaMode_L1_negative" ,test_l1_tvSettings_negative_EnableGammaMode );
    UT_add_test( pSuite, "SetGammaPattern_L1_positive" ,test_l1_tvSettings_positive_SetGammaPattern );
    UT_add_test( pSuite, "SetGammaPattern_L1_negative" ,test_l1_tvSettings_negative_SetGammaPattern );
    UT_add_test( pSuite, "GetTVGammaTarget_L1_positive" ,test_l1_tvSettings_positive_GetTVGammaTarget );
    UT_add_test( pSuite, "GetTVGammaTarget_L1_negative" ,test_l1_tvSettings_negative_GetTVGammaTarget );
    UT_add_test( pSuite, "SetGammaPatternMode_L1_positive" ,test_l1_tvSettings_positive_SetGammaPatternMode );
    UT_add_test( pSuite, "SetGammaPatternMode_L1_negative" ,test_l1_tvSettings_negative_SetGammaPatternMode );
    UT_add_test( pSuite, "SetRGBPattern_L1_positive" ,test_l1_tvSettings_positive_SetRGBPattern );
    UT_add_test( pSuite, "SetRGBPattern_L1_negative" ,test_l1_tvSettings_negative_SetRGBPattern );
    UT_add_test( pSuite, "GetRGBPattern_L1_positive" ,test_l1_tvSettings_positive_GetRGBPattern );
    UT_add_test( pSuite, "GetRGBPattern_L1_negative" ,test_l1_tvSettings_negative_GetRGBPattern );
    UT_add_test( pSuite, "SetGrayPattern_L1_positive" ,test_l1_tvSettings_positive_SetGrayPattern );
    UT_add_test( pSuite, "SetGrayPattern_L1_negative" ,test_l1_tvSettings_negative_SetGrayPattern );
    UT_add_test( pSuite, "GetGrayPattern_L1_positive" ,test_l1_tvSettings_positive_GetGrayPattern );
    UT_add_test( pSuite, "GetGrayPattern_L1_negative" ,test_l1_tvSettings_negative_GetGrayPattern );
    UT_add_test( pSuite, "GetOpenCircuitStatus_L1_positive" ,test_l1_tvSettings_positive_GetOpenCircuitStatus );
    UT_add_test( pSuite, "GetOpenCircuitStatus_L1_negative" ,test_l1_tvSettings_negative_GetOpenCircuitStatus );
    UT_add_test( pSuite, "EnableLDIMPixelCompensation_L1_positive" ,test_l1_tvSettings_positive_EnableLDIMPixelCompensation );
    UT_add_test( pSuite, "EnableLDIMPixelCompensation_L1_negative" ,test_l1_tvSettings_negative_EnableLDIMPixelCompensation );
    UT_add_test( pSuite, "EnableLDIM_L1_positive" ,test_l1_tvSettings_positive_EnableLDIM );
    UT_add_test( pSuite, "EnableLDIM_L1_negative" ,test_l1_tvSettings_negative_EnableLDIM );
    UT_add_test( pSuite, "StartLDIMSequenceTest_L1_positive" ,test_l1_tvSettings_positive_StartLDIMSequenceTest );
    UT_add_test( pSuite, "StartLDIMSequenceTest_L1_negative" ,test_l1_tvSettings_negative_StartLDIMSequenceTest );
    UT_add_test( pSuite, "SetBacklightTestMode_L1_positive" ,test_l1_tvSettings_positive_SetBacklightTestMode );
    UT_add_test( pSuite, "SetBacklightTestMode_L1_negative" ,test_l1_tvSettings_negative_SetBacklightTestMode );
    UT_add_test( pSuite, "EnableWhiteBalance_L1_positive" ,test_l1_tvSettings_positive_EnableWhiteBalance );
    UT_add_test( pSuite, "EnableWhiteBalance_L1_negative" ,test_l1_tvSettings_negative_EnableWhiteBalance );
    UT_add_test( pSuite, "EnableDynamicContrast_L1_positive" ,test_l1_tvSettings_positive_EnableDynamicContrast );
    UT_add_test( pSuite, "EnableDynamicContrast_L1_negative" ,test_l1_tvSettings_negative_EnableDynamicContrast );
    UT_add_test( pSuite, "EnableLocalContrast_L1_positive" ,test_l1_tvSettings_positive_EnableLocalContrast );
    UT_add_test( pSuite, "EnableLocalContrast_L1_negative" ,test_l1_tvSettings_negative_EnableLocalContrast );
    UT_add_test( pSuite, "GetLdimZoneShortCircuitStatus_L1_positive" ,test_l1_tvSettings_positive_GetLdimZoneShortCircuitStatus );
    UT_add_test( pSuite, "GetLdimZoneShortCircuitStatus_L1_negative" ,test_l1_tvSettings_negative_GetLdimZoneShortCircuitStatus );
    UT_add_test( pSuite, "RegisterVideoFormatChangeCB_L1_positive" ,test_l1_tvSettings_positive_RegisterVideoFormatChangeCB );
    UT_add_test( pSuite, "RegisterVideoFormatChangeCB_L1_negative" ,test_l1_tvSettings_negative_RegisterVideoFormatChangeCB );
    UT_add_test( pSuite, "RegisterVideoContentChangeCB_L1_positive" ,test_l1_tvSettings_positive_RegisterVideoContentChangeCB );
    UT_add_test( pSuite, "RegisterVideoContentChangeCB_L1_negative" ,test_l1_tvSettings_negative_RegisterVideoContentChangeCB );
    UT_add_test( pSuite, "RegisterVideoResolutionChangeCB_L1_positive" ,test_l1_tvSettings_positive_RegisterVideoResolutionChangeCB );
    UT_add_test( pSuite, "RegisterVideoResolutionChangeCB_L1_negative" ,test_l1_tvSettings_negative_RegisterVideoResolutionChangeCB );
    UT_add_test( pSuite, "RegisterVideoFrameRateChangeCB_L1_positive" ,test_l1_tvSettings_positive_RegisterVideoFrameRateChangeCB );
    UT_add_test( pSuite, "RegisterVideoFrameRateChangeCB_L1_negative" ,test_l1_tvSettings_negative_RegisterVideoFrameRateChangeCB );

    return 0;
}

/** @} */ // End of TV_Settings_HALTEST_L1
/** @} */ // End of TV_Settings_HALTEST
/** @} */ // End of TV_Settings
/** @} */ // End of HPK
