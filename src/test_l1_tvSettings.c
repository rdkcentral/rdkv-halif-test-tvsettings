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
 * @addtogroup HPK HPK
 * @{
 **/

/**
 * @defgroup TV_Settings TV Settings Module
 * @{
 **/

/**
 * @defgroup TV_Settings_HALTEST TV Settings HAL Test
 * @{
 **/

/**
 * @defgroup TV_Settings_HALTEST_L1 TV Settings HAL L1 Test Cases
 * @{
 **/

/**
 * @file test_l1_tvSettings.c
 * @page TV_Settings_HALTEST_L1  
 *
 * ## Module's Role
 * This module includes Level 1 functional tests (success and failure scenarios).
 * This is to ensure that the API meets the operational requirements of the TV SETTINGS across all vendors.
 *
 * **Pre-Conditions:**  None@n
 * **Dependencies:** None@n
 *
 * Ref to API Definition specification documentation : [halSpec.md](../../../docs/halSpec.md)
 */

#include <string.h>
#include <stdlib.h>

#include <ut.h>
#include <ut_log.h>

#include "tvError.h"
#include "../../include/tvSettings.h"
#include "test_config_read.h"

static int gTestGroup = 1;                                         /* Level 1 Testing -  Stress Test   */
int gTestID = 1;
extern struct tvSettingConf Configfile;

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
	char pictureMode[PIC_MODE_NAME_MAX]={'\0'};

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings initialization again and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination again and expecting the API to return success */
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

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);


	/* Calling tvsettings Re-initialization and expecting the API to return tvERROR_INVALID_STATE */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings termination and expecting the API to return success */
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

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate TvTerm() for all neagtive invocation scenarios
 * 
 * This test ensures that the TV Settings module is terminated using TvTerm()
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

	/* Calling tvsettings termination and expecting the API to return tvERROR_INVALID_STATE */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return tvERROR_INVALID_STATE */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

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
 * | 02 | Call RegisterVideoFormatChangeCB() - Register with the obtained data handle and a valid callback function | tvVideoFormatCallbackData& | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED)| Should Pass |
 * | 03 | Simulate an video format change event, e.g., switching to a different video format | | tvERROR_NONE | The callback function should be triggered with the correct status |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
	tvVideoFormatCallbackData callbackData;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings RegisterVideoFormatChangeCB and expecting the API to return success*/
	callbackData.cb = tvVideoFormatChangeHandler;
	RegisterVideoFormatChangeCB(callbackData);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
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
 * | 01 | call RegisterVideoFormatChangeCB() -  Register the callback function even before TvInit() | tvVideoFormatCallbackData& | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call RegisterVideoFormatChangeCB() -  Register using a NULL data handle | tvVideoFormatCallbackData&(NULL, tvVideoFormatChangeCB) | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call RegisterVideoFormatChangeCB() -  Register using a NULL callback function | tvVideoFormatCallbackData&(void*, NULL) | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call RegisterVideoFormatChangeCB() -  Register the callback function even after TvInit() | tvVideoFormatCallbackData& | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_RegisterVideoFormatChangeCB (void)
{
	gTestID = 6;                                    /* It must be 6 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	tvVideoFormatCallbackData callbackData;

	/* Calling tvsettings RegisterVideoFormatChangeCB and expecting the API to return success*/
	callbackData.cb = tvVideoFormatChangeHandler;
	RegisterVideoFormatChangeCB(callbackData);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings RegisterVideoFormatChangeCB and expecting the API to return success*/
	callbackData.cb = NULL;
	RegisterVideoFormatChangeCB(callbackData);

	/* Calling tvsettings RegisterVideoFormatChangeCB and expecting the API to return success*/
	callbackData.userdata = NULL;
	RegisterVideoFormatChangeCB(callbackData);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
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
 * | 02 | Call RegisterVideoContentChangeCB() - Register with the obtained data handle and a valid callback function | tvVideoContentCallbackData& | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED)| Should Pass |
 * | 03 | Simulate an video format change event, e.g., switching to a different playback FMM content | | tvERROR_NONE | The callback function should be triggered with the correct status |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
	tvVideoContentCallbackData callbackData;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings RegisterVideoContentChangeCB and expecting the API to return success*/
	callbackData.cb = tvVideoContentChangeHandler;
	RegisterVideoContentChangeCB(callbackData);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);	
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
 * | 01 | call RegisterVideoContentChangeCB() -  Register the callback function even before TvInit() | tvVideoContentCallbackData& | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call RegisterVideoContentChangeCB() -  Register using a NULL data handle | tvVideoContentCallbackData&(NULL, tvVideoFormatChangeCB) | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call RegisterVideoContentChangeCB() -  Register using a NULL callback function | tvVideoContentCallbackData&(void*, NULL) | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call RegisterVideoContentChangeCB() -  Register the callback function even after TvInit() | tvVideoContentCallbackData& | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_RegisterVideoContentChangeCB (void)
{
	gTestID = 8;                                    /* It must be 8 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	tvVideoContentCallbackData callbackData;

	/* Calling tvsettings RegisterVideoContentChangeCB and expecting the API to return success*/
	callbackData.cb = tvVideoContentChangeHandler;
	RegisterVideoContentChangeCB(callbackData);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings RegisterVideoContentChangeCB and expecting the API to return success*/
	callbackData.cb = NULL;
	RegisterVideoContentChangeCB(callbackData);

	/* Calling tvsettings RegisterVideoContentChangeCB and expecting the API to return success*/
	callbackData.userdata = NULL;
	RegisterVideoContentChangeCB(callbackData);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE); 
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
 * | 02 | Call RegisterVideoResolutionChangeCB() - Register with the obtained data handle and a valid callback function | tvVideoResolutionCallbackData& | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED)| Should Pass |
 * | 03 | Simulate an video format change event, e.g., switching to a different video resolution | | tvERROR_NONE | The callback function should be triggered with the correct status |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void tvVideoResolutionChangeHandler(tvResolutionParam_t resolution,void *userData)
{
	UT_LOG("callabck : %s",__FUNCTION__);
}

void test_l1_tvSettings_positive_RegisterVideoResolutionChangeCB (void)
{
	gTestID = 9;                                    /* It must be 9 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	tvVideoResolutionCallbackData callbackData;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings RegisterVideoResolutionChangeCB and expecting the API to return success*/
	callbackData.cb = tvVideoResolutionChangeHandler;
	RegisterVideoResolutionChangeCB(callbackData);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
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
 * | 01 | call RegisterVideoResolutionChangeCB() -  Register the callback function even before TvInit() | tvVideoResolutionCallbackData& | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call RegisterVideoResolutionChangeCB() -  Register using a NULL data handle | tvVideoResolutionCallbackData&(NULL, tvVideoFormatChangeCB) | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call RegisterVideoResolutionChangeCB() -  Register using a NULL callback function | tvVideoResolutionCallbackData&(void*, NULL) | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call RegisterVideoResolutionChangeCB() -  Register the callback function even after TvInit() | tvVideoResolutionCallbackData& | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_RegisterVideoResolutionChangeCB (void)
{
	gTestID = 10;                                    /* It must be 10 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	tvVideoResolutionCallbackData callbackData;

	/* Calling tvsettings RegisterVideoResolutionChangeCB and expecting the API to return success*/
	callbackData.cb = tvVideoResolutionChangeHandler;
	RegisterVideoResolutionChangeCB(callbackData);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings RegisterVideoResolutionChangeCB and expecting the API to return success*/
	callbackData.cb = NULL;
	RegisterVideoResolutionChangeCB(callbackData);

	/* Calling tvsettings RegisterVideoResolutionChangeCB and expecting the API to return success*/
	callbackData.userdata = NULL;
	RegisterVideoResolutionChangeCB(callbackData);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
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
 * | 02 | Call RegisterVideoFrameRateChangeCB() - Register with the obtained data handle and a valid callback function | tvVideoFrameRateCallbackData& | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED)| Should Pass |
 * | 03 | Simulate an video format change event, e.g., switching to a different video frame rate  | | tvERROR_NONE | The callback function should be triggered with the correct status |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void tvVideoFrameRateChangeHandler(tvVideoFrameRate_t framerate,void *userData)
{
	UT_LOG("callabck : %s",__FUNCTION__);
}

void test_l1_tvSettings_positive_RegisterVideoFrameRateChangeCB (void)
{
	gTestID = 7;                                    /* It must be 7 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	tvVideoFrameRateCallbackData callbackData;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings RegisterVideoFrameRateChangeCB and expecting the API to return success*/
	callbackData.cb = tvVideoFrameRateChangeHandler;
	RegisterVideoFrameRateChangeCB(callbackData);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
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
 * | 01 | call RegisterVideoFrameRateChangeCB() -  Register the callback function even before TvInit() | tvVideoFrameRateCallbackData& | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call RegisterVideoFrameRateChangeCB() -  Register using a NULL data handle | tvVideoFrameRateCallbackData&(NULL, tvVideoFormatChangeCB) | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call RegisterVideoFrameRateChangeCB() -  Register using a NULL callback function | tvVideoFrameRateCallbackData&(void*, NULL) | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call RegisterVideoFrameRateChangeCB() -  Register the callback function even after TvInit() | tvVideoFrameRateCallbackData& | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_RegisterVideoFrameRateChangeCB (void)
{
	gTestID = 12;                                    /* It must be 12 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	tvVideoFrameRateCallbackData callbackData;

	/* Calling tvsettings RegisterVideoFrameRateChangeCB and expecting the API to return success*/
	callbackData.cb = tvVideoFrameRateChangeHandler;
	RegisterVideoFrameRateChangeCB(callbackData);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings RegisterVideoFrameRateChangeCB and expecting the API to return success*/
	callbackData.cb = NULL;
	RegisterVideoFrameRateChangeCB(callbackData);

	/* Calling tvsettings RegisterVideoFrameRateChangeCB and expecting the API to return success*/
	callbackData.userdata = NULL;
	RegisterVideoFrameRateChangeCB(callbackData);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
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
 * | 02 | call GetTVSupportedVideoFormats() -  Retrieve the current Supported VideoFormats and validate Supported VideoFormats by looping through the test specific config file | tvVideoFormatType_t* [], unsigned short * | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVSupportedVideoFormats() -  Retrieve the current Supported VideoFormats with valid argument and validate with above value | tvVideoFormatType_t* [], unsigned short * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetTVSupportedVideoFormats (void)
{
	gTestID = 13;                                    /* It must be 13 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	printf("%d", MAX_VIDEO_FORMAT);
	tvError_t result = tvERROR_NONE;
	tvVideoFormatType_t *tvVideoFormats[MAX_VIDEO_FORMAT];
	tvVideoFormatType_t *tvVideoFormatsRetry[MAX_VIDEO_FORMAT];
	bool IsVideoFormatValid;
	unsigned short sizeReceived;
	unsigned short sizeReceivedRetry;
	size_t sizeFromConfig;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVSupportedVideoFormats and expeting the API to return success */
	result = GetTVSupportedVideoFormats(tvVideoFormats, &sizeReceived);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	sizeFromConfig = sizeof(Configfile.videoformat.modeId) / sizeof(Configfile.videoformat.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(sizeReceived, (unsigned short)sizeFromConfig);

	for (size_t i = 0; i < sizeFromConfig; i++)
	{
		IsVideoFormatValid = false;
		for(unsigned short j = 0; j < sizeReceived; j++)
		{
			if (Configfile.videoformat.modeId[i] == *tvVideoFormats[j])
			{
				IsVideoFormatValid = true;
				break;
			}
		}
		UT_ASSERT_FALSE_FATAL(IsVideoFormatValid);
	}

	/* Calling tvsettings GetTVSupportedVideoFormats and expeting the API to return success */
	result = GetTVSupportedVideoFormats(tvVideoFormatsRetry, &sizeReceivedRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL_FATAL(sizeReceived, sizeReceivedRetry);
	for (unsigned short i = 0; i < sizeReceivedRetry; i++)
	{
		IsVideoFormatValid = false;
		for(unsigned short j = 0; j < sizeReceived; j++)
		{
			if (*tvVideoFormatsRetry[i] == *tvVideoFormats[j])
			{
				IsVideoFormatValid = true;
				break;
			}
		}
		UT_ASSERT_FALSE_FATAL(IsVideoFormatValid);
	}

	/* Calling tvsettings termination and expecting the API to return success */
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
void test_l1_tvSettings_negative_GetTVSupportedVideoFormats (void)
{
	gTestID = 14;                                    /* It must be 14 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	tvVideoFormatType_t *tvVideoFormats[MAX_VIDEO_FORMAT];
	unsigned short size;

	/* Calling tvsettings GetTVSupportedVideoFormats and expecting the API to return tvERROR_INVALID_STATE */
	result = GetTVSupportedVideoFormats(tvVideoFormats, &size);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVSupportedVideoFormats and expecting the API to return tvERROR_INVALID_PARAM */
	result = GetTVSupportedVideoFormats(tvVideoFormats, NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings GetTVSupportedVideoFormats and expecting the API to return tvERROR_INVALID_PARAM */
	result = GetTVSupportedVideoFormats(NULL,&size);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVSupportedVideoFormats and expecting the API to return tvERROR_INVALID_STATE */
	result = GetTVSupportedVideoFormats(tvVideoFormats,&size);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);
	UT_LOG("Out %s",__FUNCTION__);
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
 * | 02 | call GetCurrentVideoFormat() -  Retrieve the CurrentVideoFormat and validate CurrentVideoFormat by looping through the test specific config file values | tvVideoFormatType_t *  | tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentVideoFormat()-  Retrieve the CurrentVideoFormat with valid argument and validate with above value | tvVideoFormatType_t * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetCurrentVideoFormat (void)
{
	gTestID = 15;                                    /* It must be 15 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	tvVideoFormatType_t tvVideoFormatType;
	tvVideoFormatType_t tvVideoFormatTypeRetry;
	bool IsVideoFormatValid = false;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetCurrentVideoFormat and expeting the API to return success */
	result = GetCurrentVideoFormat(&tvVideoFormatType);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	for (size_t i = 0; i < (sizeof(Configfile.videoformat.modeId) / sizeof(Configfile.videoformat.modeId[0])); i++)
	{
		if ( Configfile.videoformat.modeId[i] == tvVideoFormatType)
		{
			IsVideoFormatValid = true;
			break;
		}
	}
	UT_ASSERT_FALSE(IsVideoFormatValid);

	/* Calling tvsettings GetCurrentVideoFormat and expeting the API to return success */
	result = GetCurrentVideoFormat(&tvVideoFormatTypeRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL_FATAL(tvVideoFormatTypeRetry, tvVideoFormatType);

	/* Calling tvsettings termination and expecting the API to return success */
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
	tvVideoFormatType_t tvVideoFormatType;

	/* Calling tvsettings GetCurrentVideoFormat and expecting the API to return tvERROR_INVALID_STATE */
	result = GetCurrentVideoFormat(&tvVideoFormatType);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetCurrentVideoFormat and expecting the API to return tvERROR_INVALID_PARAM */
	result = GetCurrentVideoFormat(NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetCurrentVideoFormat and expecting the API to return tvERROR_INVALID_STATE */
	result = GetCurrentVideoFormat(&tvVideoFormatType);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

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
 * | 02 | call GetCurrentVideoResolution() -  Retrieve the current VideoResolution and validate VideoResolution by looping through the test specific config file values | tvResolutionParam_t *  | tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentVideoResolution() -  Retrieve the current VideoResolution with valid argument and validate with above value |tvResolutionParam_t * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetCurrentVideoResolution (void)
{
	gTestID = 15;                                    /* It must be 15 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	tvResolutionParam_t  tvVideoResolution;
	tvResolutionParam_t  tvVideoResolutionRetry;
	bool IsVideoResolutionValid = false;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetCurrentVideoFormat and expeting the API to return success */
	result = GetCurrentVideoResolution(&tvVideoResolution);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	if(  (tvVideoResolution.resolutionValue > tvVideoResolution_NONE)  && (tvVideoResolution.resolutionValue < tvVideoResolution_MAX) && \
			(tvVideoResolution.frameHeight > 0) && (tvVideoResolution.frameWidth > 0) 	) {
		IsVideoResolutionValid = true;
	} 
	UT_ASSERT_FALSE(IsVideoResolutionValid);

	/* Calling tvsettings GetCurrentVideoFormat and expeting the API to return success */
	result = GetCurrentVideoResolution(&tvVideoResolutionRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_ASSERT_EQUAL_FATAL(tvVideoResolutionRetry.resolutionValue, tvVideoResolution.resolutionValue);
	UT_ASSERT_EQUAL_FATAL(tvVideoResolutionRetry.frameHeight, tvVideoResolution.frameHeight);
	UT_ASSERT_EQUAL_FATAL(tvVideoResolutionRetry.frameWidth, tvVideoResolution.frameWidth);
	UT_ASSERT_EQUAL_FATAL(tvVideoResolutionRetry.isInterlaced, tvVideoResolution.isInterlaced);

	/* Calling tvsettings termination and expecting the API to return success */
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

	/* Calling tvsettings GetCurrentVideoResolution and expecting the API to return tvERROR_INVALID_STATE */
	result = GetCurrentVideoResolution(&tvResolutionParam);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetCurrentVideoResolution and expecting the API to return tvERROR_INVALID_PARAM */
	result = GetCurrentVideoResolution(NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetCurrentVideoResolution and expecting the API to return tvERROR_INVALID_STATE */
	result = GetCurrentVideoResolution(&tvResolutionParam);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

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
 * | 02 | call GetCurrentVideoFrameRate() -  Retrieve the current VideoFrameRate and validate VideoFrameRate by looping through the test specific config file values | tvVideoFrameRate_t *  | tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentVideoFrameRate() -  Retrieve the current VideoFrameRate with valid argument and validate with above value | tvVideoFrameRate_t * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetCurrentVideoFrameRate (void)
{
	gTestID = 19;                                    /* It must be 19 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	tvVideoFrameRate_t tvVideoFramerate;
	tvVideoFrameRate_t tvVideoFramerateRetry;
	bool IsVideoFramerateValid = false;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetCurrentVideoFormat and expeting the API to return success */
	result = GetCurrentVideoFrameRate(&tvVideoFramerate);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	for (size_t i = 0; i < (sizeof(Configfile.videoframerate.modeId) / sizeof(Configfile.videoframerate.modeId[0])); i++)
	{
		if ( Configfile.videoframerate.modeId[i] == tvVideoFramerate)
		{
			IsVideoFramerateValid = true;
			break;
		}
	}
	UT_ASSERT_FALSE(IsVideoFramerateValid);

	/* Calling tvsettings GetCurrentVideoFormat and expeting the API to return success */
	result = GetCurrentVideoFrameRate(&tvVideoFramerateRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL_FATAL(tvVideoFramerateRetry, tvVideoFramerate);

	/* Calling tvsettings termination and expecting the API to return success */
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
	tvVideoFrameRate_t tvVideoFrameRate;

	/* Calling tvsettings GetCurrentVideoFrameRate and expecting the API to return tvERROR_INVALID_STATE */
	result = GetCurrentVideoFrameRate(&tvVideoFrameRate);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetCurrentVideoFrameRate and expecting the API to return tvERROR_INVALID_PARAM */
	result = GetCurrentVideoFrameRate(NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetCurrentVideoFrameRate and expecting the API to return tvERROR_INVALID_STATE */
	result = GetCurrentVideoFrameRate(&tvVideoFrameRate);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

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
 * | 02 | call GetCurrentVideoSource() -  Retrieve the current VideoSource and validate VideoSource by looping through the test specific config file values | int *  | tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentVideoSource() -  Retrieve the current VideoSource with valid argument and validate with above value |int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetCurrentVideoSource (void)
{
	gTestID = 21;                                    /* It must be 21 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	int tvVideoSource;
	int tvVideoSourceRetry;
	bool IsVideoSourceValid = false;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetCurrentVideoSource and expeting the API to return success */
	result = GetCurrentVideoSource(&tvVideoSource);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	for (size_t i = 0; i < (sizeof(Configfile.videoSources.modeId) / sizeof(Configfile.videoSources.modeId[0])); i++)
	{
		if (Configfile.videoSources.modeId[i] == tvVideoSource)
		{
			IsVideoSourceValid = true;
			break;
		}
	}
	UT_ASSERT_FALSE(IsVideoSourceValid);

	/* Calling tvsettings GetCurrentVideoSource and expeting the API to return success */
	result = GetCurrentVideoSource(&tvVideoSourceRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_ASSERT_EQUAL_FATAL(tvVideoSourceRetry, tvVideoSource);

	/* Calling tvsettings termination and expecting the API to return success */
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
	int tvVideoSource;

	/* Calling tvsettings GetCurrentVideoSource and expecting the API to return tvERROR_INVALID_STATE */
	result = GetCurrentVideoSource(&tvVideoSource);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetCurrentVideoSource and expecting the API to return tvERROR_INVALID_PARAM */
	result = GetCurrentVideoSource(NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetCurrentVideoSource and expecting the API to return tvERROR_INVALID_STATE */
	result = GetCurrentVideoSource(&tvVideoSource);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

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
 * | 02 | call GetTVSupportedVideoSources() -  Retrieve the current TV Supported VideoSources and validate TV Supported VideoSources by looping through the test specific config file | tvVideoSrcType_t *[], unsigned short * | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVSupportedVideoSources() -  Retrieve the current TV Supported VideoSources with valid argument and validate with above value | tvVideoSrcType_t *[], unsigned short * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetTVSupportedVideoSources (void)
{
	gTestID = 23;                                    /* It must be 23 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	tvVideoSrcType_t *tvVideoSources[MAX_NAME_SIZE];
	tvVideoSrcType_t *tvVideoSourcesRetry[MAX_NAME_SIZE];
	bool IsVideoSourceValid;
	unsigned short sizeReceived;
	unsigned short sizeReceivedRetry;
	size_t sizeFromConfig;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVSupportedVideoSources and expeting the API to return success */
	result = GetTVSupportedVideoSources(tvVideoSources, &sizeReceived);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	sizeFromConfig = sizeof(Configfile.videoSources.modeId) / sizeof(Configfile.videoSources.modeId[0]);

	for (size_t i = 0; i < sizeReceived; i++)
	{
		IsVideoSourceValid = false;
		for(unsigned short j = 0; j < sizeFromConfig; j++)
		{
			if (Configfile.videoSources.modeId[j] == *tvVideoSources[i])
			{
				IsVideoSourceValid = true;
				break;
			}
		}
		UT_ASSERT_FALSE_FATAL(IsVideoSourceValid);
	}

	/* Calling tvsettings GetTVSupportedVideoSources and expeting the API to return success */
	result = GetTVSupportedVideoSources(tvVideoSourcesRetry, &sizeReceivedRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	for (unsigned short i = 0; i < sizeReceivedRetry; i++)
	{
		IsVideoSourceValid = false;
		for(unsigned short j = 0; j < sizeReceived; j++)
		{
			if (*tvVideoSourcesRetry[i] == *tvVideoSources[j])
			{
				IsVideoSourceValid = true;
				break;
			}
		}
		UT_ASSERT_FALSE_FATAL(IsVideoSourceValid);
	}

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 05 | call GetTVSupportedVideoSources() -  Retrieve supported TV VideoSources with valid inputs and validate VideoSources by looping through the test specific config file values | tvVideoSrcType_t *[],  unsigned short *  | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 07 | call GetTVSupportedVideoSources() -  Retrieve current TV Supported VideoSources valid arguments | tvVideoSrcType_t *[], unsigned short * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetTVSupportedVideoSources (void)
{
	gTestID = 24;                                    /* It must be 24 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	tvVideoSrcType_t *tvVideoSrcType[10] = {0};
	unsigned short numberOfSources;

	/* Calling tvsettings GetTVSupportedVideoSources and expecting the API to return tvERROR_INVALID_STATE */
	result = GetTVSupportedVideoSources(tvVideoSrcType,&numberOfSources);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVSupportedVideoSources and expecting the API to return tvERROR_INVALID_PARAM */
	result = GetTVSupportedVideoSources(NULL,&numberOfSources);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings GetTVSupportedVideoSources and expecting the API to return tvERROR_INVALID_PARAM */
	result = GetTVSupportedVideoSources(tvVideoSrcType,NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVSupportedVideoSources and expecting the API to return tvERROR_INVALID_STATE */
	result = GetTVSupportedVideoSources(tvVideoSrcType,&numberOfSources);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

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
 * | 02 | call GetBacklight() -  Retrieve the current Backlight with valid argument |int *| tvERROR_NONE | Should Pass |
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

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetBacklight and expecting the API to return success */
	result = GetBacklight(&backlight);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_TRUE(backlight >= 0 && backlight <= 100);

	/* Calling tvsettings GetBacklight again and expecting the API to return success */
	result = GetBacklight(&backlightRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL_FATAL(backlight, backlightRetry);

	/* Calling tvsettings termination and expecting the API to return success */
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

	/* Calling tvsettings GetTVBcklight and expecting the API to return tvERROR_INVALID_STATE */
	result = GetBacklight(&backlight);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetBacklight with invalid input and expecting the API to return tvERROR_INVALID_PARAM*/
	result = GetBacklight(NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetBacklight and expecting the API to return tvERROR_INVALID_STATE */
	result = GetBacklight(&backlight);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

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
 * | 05 | call SetBacklight() -  Reset the backlight with another valid value | 100 | tvERROR_NONE | Should Pass |
 * | 06 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetBacklight (void)
{
	gTestID = 27;                                    /* It must be 27 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetBacklight with Backlight value 0 and expecting the API to return success */
	result = SetBacklight(0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetBacklight with Backlight value 50 and expecting the API to return success */
	result = SetBacklight(50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetBacklight with Backlight value 100 and expecting the API to return success */
	result = SetBacklight(100);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetBacklight with Backlight value 100 and expecting the API to return success */
	result = SetBacklight(100);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
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

	/* Calling tvsettings SetBacklight and expecting the API to return tvERROR_INVALID_STATE */
	result = SetBacklight(30);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetBacklight with Backlight value -1 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetBacklight(-1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetBacklight with Backlight value 101 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetBacklight(101);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetBacklight with Backlight value 200 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetBacklight(200);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings the SetBacklight and expecting the API to return tvERROR_INVALID_STATE */
	result = SetBacklight(50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

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
 * | 02 | call SaveBacklight() -  Save the current Color Backlight value by looping through all the values of sourceId, pqmode, videoFormatType from the test specific config file  |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,int | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveBacklight (void)
{
	gTestID = 29;                                    /* It must be 29 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveBacklight for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
	for (size_t i = 0; i < sizeof(Configfile.videoSources.modeId) / sizeof(Configfile.videoSources.modeId[0]); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.pic_modes.modeId) / sizeof(Configfile.pic_modes.modeId[0]); j++)
		{
			for (size_t k = 0; k < sizeof(Configfile.videoformat.modeId) / sizeof(Configfile.videoformat.modeId[0]); k++)
			{
				result = SaveBacklight((tvVideoSrcType_t) Configfile.videoSources.modeId[i],Configfile.pic_modes.modeId[j],(tvVideoFormatType_t) Configfile.videoformat.modeId[k],50);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 11 | call SaveBacklight() -  "pq_mode,videoFormatType,value"= valid, "videoSrcType"=valid(videoSrcType not supported by the platform by looping through the test specific config file)| tvVideoSrcType_t, int , tvVideoFormatType_t , int| tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call SaveBacklight() -  "videoSrcType,videoFormatType,value"= valid, "pq_mode"=valid( pq_mode not supported by the platform by looping through the test specific config file)| tvVideoSrcType_t, int , tvVideoFormatType_t , int| tvERROR_INVALID_PARAM | Should Pass |
 * | 13 | call SaveBacklight() -  "videoSrcType,pq_mode,value"= valid, "videoFormatType"=valid(videoFormatType not supported by the platform by looping through the test specific config file)| tvVideoSrcType_t, int , tvVideoFormatType_t , int| tvERROR_INVALID_PARAM | Should Pass |
 * | 14 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 15 | call SaveBacklight() -  Retrieve current TV Backlight valid arguments | tvVideoSrcType_t, int , tvVideoFormatType_t ,int | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveBacklight (void)
{
	gTestID = 30;                                    /* It must be 30 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int numberOfSources;
	int numberOfPqmodes;
	int numberOfFormats;
	bool SupportAvailable;

	/* Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveBacklight((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveBacklight(VIDEO_SOURCE_MAX,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveBacklight((tvVideoSrcType_t)-2,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveBacklight((tvVideoSrcType_t)Configfile.videoSources.modeId[0],-1,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveBacklight((tvVideoSrcType_t)Configfile.videoSources.modeId[0],PQ_MODE_MAX,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveBacklight((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],VIDEO_FORMAT_MAX,50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveBacklight((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)-1,50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveBacklight((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],-1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);


	/* Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveBacklight((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],101);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfSources = sizeof(Configfile.videoSources.modeId)/sizeof(Configfile.videoSources.modeId[0]);
	for(int i =VIDEO_SOURCE_ALL ; i < VIDEO_SOURCE_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfSources; j++)
		{
			if(Configfile.videoSources.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveBacklight((tvVideoSrcType_t)i,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfPqmodes = sizeof(Configfile.pic_modes.modeId)/sizeof(Configfile.pic_modes.modeId[0]);
	for(int i =0 ; i < PQ_MODE_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfPqmodes; j++)
		{
			if(Configfile.pic_modes.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveBacklight((tvVideoSrcType_t)Configfile.videoSources.modeId[0],i,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfFormats = sizeof(Configfile.videoformat.modeId)/sizeof(Configfile.videoformat.modeId[0]);
	for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfFormats; j++)
		{
			if(Configfile.videoformat.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveBacklight((tvVideoSrcType_t) Configfile.videoSources.modeId[i],Configfile.pic_modes.modeId[i],(tvVideoFormatType_t)i,50);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveBacklight and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveBacklight((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

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
 * | 02 | call SetBacklightFade() -  Set the BacklightFade with valid inputs by looping through the input range | int, int, int | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetBacklightFade (void)
{
	gTestID = 31;                                    /* It must be 31 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetBacklightFade with inputs 0, 0, 0 and expecting the API to return success */
	result = SetBacklightFade(0,0,0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetBacklightFade with inputs 50, 50, 5000 and expecting the API to return success */
	result = SetBacklightFade(50,50,5000);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetBacklightFade with inputs 100, 100, 10000 and expecting the API to return success */
	result = SetBacklightFade(100,100,10000);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
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

	/* Calling tvsettings SetBacklightFade and expecting the API to return tvERROR_INVALID_STATE */
	result = SetBacklightFade(30,30,30);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetBacklightFade with inputs -1, 1, 1 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetBacklightFade(-1, 1, 1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetBacklightFade with inputs 1, -1, 1 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetBacklightFade(1, -1, 1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetBacklightFade with inputs 1, 1, -1 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetBacklightFade(1, 1, -1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetBacklightFade with inputs 101, 10, 100000 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetBacklightFade(101, 10, 100000);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetBacklightFade with inputs 10, 101, 100000 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetBacklightFade(10, 101, 100000);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetBacklightFade with inputs 10, 10, 100001 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetBacklightFade(10, 10, 100001);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings the SetBacklightFade and expecting the API to return tvERROR_INVALID_STATE */
	result = SetBacklightFade(10,10,10);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);
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
 * | 02 | call GetCurrentBacklightFade() -  Retrieve the current Backlight Fade with valid argument |int *, int*, int*| tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentBacklightFade() -  Retrieve the current Backlight Fade with valid argument and validate with above value | int *, int*, int* | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetCurrentBacklightFade (void)
{
	gTestID = 33;                                    /* It must be 25 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int from , to ,current;
	int fromRetry , toRetry ,currentRetry;
	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

#if 0
	/* Calling tvsettings GetBacklight and expecting the API to return success */
	result = GetCurrentBacklightFade(&from, &to, &current);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_TRUE(from >= 0 && from <= 100);
	UT_ASSERT_TRUE(to >= 0 && to <= 100);
	UT_ASSERT_TRUE(current >= 0 && current <= 10000);

	/* Calling tvsettings GetBacklight again and expecting the API to return success */
	result = GetCurrentBacklightFade(&fromRetry , &toRetry ,&currentRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_ASSERT_EQUAL_FATAL(from, fromRetry);
	UT_ASSERT_EQUAL_FATAL(to, toRetry);
	UT_ASSERT_EQUAL_FATAL(current, currentRetry);
#endif
	/* Calling tvsettings termination and expecting the API to return success */
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
	int from , to ,current;

#if 0
	result = GetCurrentBacklightFade(&from, &to, &current);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = GetCurrentBacklightFade(NULL, &to, &current);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = GetCurrentBacklightFade(&from, NULL, &current);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = GetCurrentBacklightFade(&from, &to, NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetBacklight and expecting the API to return tvERROR_INVALID_STATE */
	result = GetCurrentBacklightFade(&from, &to, &current);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);
	UT_LOG("Out %s",__FUNCTION__);
#endif
}

/**
 * @brief Validate GetSupportedBacklightModes() for all positive invocation scenarios
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
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetSupportedBacklightModes() -  Retrieve the current SupportedBacklightModes and validate SupportedBacklightModes by looping through the test specific config file values | int *  | tvERROR_NONE | Should Pass |
 * | 03 | call GetSupportedBacklightModes() -  Retrieve the current SupportedBacklightModes with valid argument and validate with above value | int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetSupportedBacklightModes (void)
{
	gTestID = 33;                                    /* It must be 33 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	int tvBacklightModes, tvBacklightModes_bk, tvBacklightModesRetry;
	size_t sizeFromConfig;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetSupportedBacklightModes and expeting the API to return success */
	result = GetSupportedBacklightModes(&tvBacklightModes);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	tvBacklightModes_bk = tvBacklightModes;

	sizeFromConfig = sizeof(Configfile.backlightModes.modeId) / sizeof(Configfile.backlightModes.modeId[0]);

	for (size_t i = 0; i < sizeFromConfig; i++)
	{
		if(Configfile.backlightModes.modeId[i] & tvBacklightModes_bk)
		{
			tvBacklightModes_bk &= (~Configfile.backlightModes.modeId[i]);
		}
	}

	UT_ASSERT_FALSE(tvBacklightModes_bk);

	/* Calling tvsettings GetSupportedBacklightModes and expeting the API to return success */
	result = GetSupportedBacklightModes(&tvBacklightModesRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);


	UT_ASSERT_EQUAL_FATAL(tvBacklightModesRetry, tvBacklightModes);
	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetSupportedBacklightModes() for all negative invocation scenarios
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
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetSupportedBacklightModes() -  Retrieve current TV SupportedBacklightModes even before TvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetSupportedBacklightModes() -  Retrieve supported Backlight modes with invalid argument | NULL | tvERROR_INVALID_PARAM |
 * | 04 | call GetSupportedBacklightModes() -  Retrieve supported Backlight modes modes with valid inputs and validate backlightmodes by looping through the test specific config file values | int * | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call GetSupportedBacklightModes() -  Retrieve current TV SupportedBacklightModes valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetSupportedBacklightModes (void)
{
	gTestID = 34;                                    /* It must be 34 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int backlightModes;

	/* Calling tvsettings GetSupportedBacklightModes and expecting the API to return tvERROR_INVALID_STATE */
	result = GetSupportedBacklightModes(&backlightModes);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetSupportedBacklightModes and expecting the API to return tvERROR_INVALID_PARAM */
	result = GetSupportedBacklightModes(NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetSupportedBacklightModes and expecting the API to return tvERROR_INVALID_STATE */
	result = GetSupportedBacklightModes(&backlightModes);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/** 
 * @brief Validate GetCurrentBacklightMode() for all positive invocation scenarios
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
 * | 02 | call GetCurrentBacklightMode() -  Retrieve the CurrentBacklightMode and validate it by looping through the test specific config file values | tvBacklightMode_t *  | tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentBacklightMode() -  Retrieve the CurrentBacklightMode with valid argument and validate with above value | tvBacklightMode_t * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetCurrentBacklightMode (void)
{
	gTestID = 35;                                    /* It must be 35 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	tvBacklightMode_t tvBacklightMode;
	tvBacklightMode_t tvBacklightModeRetry;
	bool IsBacklightModeValid = false;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetCurrentBacklightMode and expeting the API to return success */
	result = GetCurrentBacklightMode(&tvBacklightMode);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	for (size_t i = 0; i < (sizeof(Configfile.backlightModes.modeId) / sizeof(Configfile.backlightModes.modeId[0])); i++)
	{
		if (Configfile.backlightModes.modeId[i] == tvBacklightMode)
		{
			IsBacklightModeValid = true;
			break;
		}
	}

	//TODO: check crash happens here, whether HAL or UT
	UT_ASSERT_TRUE(IsBacklightModeValid);

	/* Calling tvsettings GetCurrentBacklightMode and expeting the API to return success */
	result = GetCurrentBacklightMode(&tvBacklightModeRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_STRING_EQUAL(tvBacklightModeRetry, tvBacklightMode);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
}

/**
 * @brief Validate GetCurrentBacklightMode() for all negative invocation scenarios
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
 * | 01 | call GetCurrentBacklightMode() -  Retrieve current TV CurrentBacklightMode even before TvInit() | tvBacklightMode_t * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentBacklightMode() -  Retrieve TV current Backlight modes with invalid argument | NULL | tvERROR_INVALID_PARAM |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetCurrentBacklightMode() -  Retrieve current TV CurrentBacklightMode valid arguments | tvBacklightMode_t * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetCurrentBacklightMode (void)
{
	gTestID = 36;                                    /* It must be 36 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	tvBacklightMode_t tvBacklightMode;

	/* Calling tvsettings GetCurrentBacklightMode and expecting the API to return tvERROR_INVALID_STATE */
	result = GetCurrentBacklightMode(&tvBacklightMode);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetSupportedBacklightModes and expecting the API to return tvERROR_INVALID_PARAM */
	result = GetCurrentBacklightMode(NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetCurrentBacklightMode and expecting the API to return tvERROR_INVALID_STATE */
	result = GetCurrentBacklightMode(&tvBacklightMode);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/** 
 * @brief Validate SetCurrentBacklightMode() for all positive invocation scenarios
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
 * | 02 | call SetCurrentBacklightMode() -  Set the TV Current Backlight mode by looping through all the values of backlight modes from the test specific config file | tvBacklightMode_t  | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetCurrentBacklightMode (void)
{
	gTestID = 37;                                    /* It must be 37 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetCurrentBacklightMode and expecting the API to return success */
	for (size_t i = 0; i < (sizeof(Configfile.backlightModes.modeId)/sizeof(Configfile.backlightModes.modeId[0])); i++)
	{
		result = SetCurrentBacklightMode((tvBacklightMode_t)Configfile.backlightModes.modeId[i]);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	}

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 01 | call SetCurrentBacklightMode() - Set the TV CurrentBacklightMode even before TvInit() | tvBacklightMode_AMBIENT | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetCurrentBacklightMode() -   Set the TV CurrentBacklightMode with max range | tvBacklightMode_INVALID | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetCurrentBacklightMode() -   Set the TV CurrentBacklightMode with less than the lower range  | -1 (tvBacklightMode_t)| tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetCurrentBacklightMode() -   Set the TV CurrentBacklightMode with invalid parameter of all possible combinations  | (tvBacklightMode_t| tvBacklightMode_t) | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetCurrentBacklightMode() -   Set the TV CurrentBacklightMode with valid value but not supported by the platform by looping through the test specific config file  | tvBacklightMode_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 08 | call SetCurrentBacklightMode() -  Set the TV CurrentBacklightMode with valid input after TvTerm() | tvBacklightMode_MANUAL | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetCurrentBacklightMode (void)
{
	gTestID = 38;                                    /* It must be 38*/
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	int numberofBacklightModes;
	bool SupportAvailable;

	/* Calling tvsettings SetCurrentBacklightMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SetCurrentBacklightMode((tvBacklightMode_t)Configfile.backlightModes.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetCurrentBacklightMode and expecting the API to return success */
	result = SetCurrentBacklightMode((tvBacklightMode_t)-1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetCurrentBacklightMode and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetCurrentBacklightMode(tvBacklightMode_INVALID);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
	/* Calling tvsettings SetCurrentBacklightMode and expecting the API to return tvERROR_INVALID_PARAM */
	numberofBacklightModes = sizeof(Configfile.backlightModes.modeId)/sizeof(Configfile.backlightModes.modeId[0]);
	for(int i =0 ; i < numberofBacklightModes; i++)
	{
		SupportAvailable = false;
		for(int j = tvBacklightMode_NONE  ; j < tvBacklightMode_MAX ; j++)
		{
			if(Configfile.backlightModes.modeId[i] == j)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SetCurrentBacklightMode((tvBacklightMode_t) (Configfile.backlightModes.modeId[i]));
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings the SetCurrentBacklightMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SetCurrentBacklightMode((tvBacklightMode_t)Configfile.backlightModes.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVSupportedDimmingModes() for all positive invocation scenarios
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
 * | 02 | call GetTVSupportedDimmingModes() -  Retrieve the current TV Supported DimmingModes and validate TV Supported DimmingModes by looping through the test specific config file | tvDimmingMode_t*[], unsigned short * | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVSupportedDimmingModes() -  Retrieve the current TTV Supported DimmingModes with valid argument and validate with above value | tvDimmingMode_t*[], unsigned short * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetTVSupportedDimmingModes (void)
{
	gTestID = 39;                                    /* It must be 39 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	tvDimmingMode_t *tvDimmingModes[MAX_DIMMING_MODES];
	tvDimmingMode_t *tvDimmingModesRetry[MAX_DIMMING_MODES];
	bool IsDimmingModeValid;
	unsigned short sizeReceived;
	unsigned short sizeReceivedRetry;
	size_t sizeFromConfig;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVSupportedDimmingModes and expeting the API to return success */
	result = GetTVSupportedDimmingModes(tvDimmingModes, &sizeReceived);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	sizeFromConfig = sizeof(Configfile.dimmode.modeId) / sizeof(Configfile.dimmode.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(sizeReceived, (unsigned short)sizeFromConfig);

	for (size_t i = 0; i < sizeFromConfig; i++)
	{
		IsDimmingModeValid = false;
		for(unsigned short j = 0; j < sizeReceived; j++)
		{
			if ((tvDimmingMode_t)Configfile.dimmode.modeId[i] == *tvDimmingModes[j])
			{
				IsDimmingModeValid = true;
				break;
			}
		}
		UT_ASSERT_FALSE_FATAL(IsDimmingModeValid);
	}

	/* Calling tvsettings GetTVSupportedDimmingModes and expeting the API to return success */
	result = GetTVSupportedDimmingModes(tvDimmingModesRetry, &sizeReceivedRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL_FATAL(sizeReceived, sizeReceivedRetry);
	for (unsigned short i = 0; i < sizeReceivedRetry; i++)
	{
		IsDimmingModeValid = false;
		for(unsigned short j = 0; j < sizeReceived; j++)
		{
			if (*tvDimmingModesRetry[i] == *tvDimmingModes[j])
			{
				IsDimmingModeValid = true;
				break;
			}
		}
		UT_ASSERT_FALSE_FATAL(IsDimmingModeValid);
	}

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 01 | call GetTVSupportedDimmingModes() -  Retrieve current TV Supported DimmingModes even before TvInit() | tvDimmingMode_t*[], unsigned short * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVSupportedDimmingModes() -  Retrieve supported TV dimming modes with invalid argument | NULL,  unsigned short * | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetTVSupportedDimmingModes() -  Retrieve supported TV dimming modes with invalid argument | tvDimmingMode_t*[],  NULL| tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call GetTVSupportedDimmingModes() -  Retrieve current TV Supported DimmingModes valid arguments | tvDimmingMode_t*[], unsigned short * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetTVSupportedDimmingModes (void)
{
	UT_FAIL("This function needs to be implemented!"); 
	gTestID = 14;                                    /* It must be 14 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	tvDimmingMode_t *tvDimmingModes[MAX_DIMMING_MODES];
	unsigned short size;

	/* Calling tvsettings GetTVSupportedDimmingModes and expecting the API to return tvERROR_INVALID_STATE */
	result = GetTVSupportedDimmingModes(tvDimmingModes, &size);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVSupportedDimmingModes and expecting the API to return tvERROR_INVALID_PARAM */
	result = GetTVSupportedDimmingModes(tvDimmingModes, NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings GetTVSupportedDimmingModes and expecting the API to return tvERROR_INVALID_PARAM */
	result = GetTVSupportedDimmingModes(NULL,&size);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVSupportedDimmingModes and expecting the API to return tvERROR_INVALID_STATE */
	result = GetTVSupportedDimmingModes(tvDimmingModes,&size);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetTVDimmingMode() for all positive invocation scenarios
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
 * | 02 | call SetTVDimmingMode() -  Set the TV dimming mode by looping through all the values of dimming modes from the test specific config file | const char * | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetTVDimmingMode (void)
{
	gTestID = 41;                                    /* It must be 41 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the SetTVDimmingMode for all the pic_modes and expecting the API to return success */
	for (size_t i = 0; i < sizeof(Configfile.dimmode.modeId) / sizeof(Configfile.dimmode.modeId[0]); i++)
	{
		result = SetTVDimmingMode(Configfile.dimmode.modeName[i]);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	}

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 01 | call SetTVDimmingMode() -  Set TV Dimming Mode even before TvInit() | const char * | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetTVDimmingMode() -   Set TV Dimming Mode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetTVDimmingMode() -   Set TV Dimming Mode with valid value but not supported by the platform by looping through the test specific config file | const char * | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call SetTVDimmingMode() -  Set TV Dimming Mode valid arguments | const char * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetTVDimmingMode (void)
{
	gTestID = 42;                                    /* It must be 42 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings SetTVDimmingMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SetTVDimmingMode(Configfile.dimmode.modeName[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetTVDimmingMode and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetTVDimmingMode(NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings the SetTVDimmingMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SetTVDimmingMode(Configfile.dimmode.modeName[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVDimmingMode() for all positive invocation scenarios
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
 * | 02 | call GetTVDimmingMode() -  Retrieve the current TV DimmingMode and validate DimmingMode by looping through the test specific config file | const char * | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call GetTVDimmingMode() -  Retrieve the current TV DimmingMode with valid argument and validate with above value | const char * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetTVDimmingMode (void)
{
	gTestID = 43;                                    /* It must be 43 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	char dimmingMode[MAX_DIMMING_MODES]={'\0'};
	char dimmingModeRetry[MAX_DIMMING_MODES]={'\0'};
	bool IsDimmingModeValid = false;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
#if 0
	/* Calling tvsettings GetTVDimmingMode and expeting the API to return success */
	result = GetTVDimmingMode(dimmingMode);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	for (size_t i = 0; i < (sizeof(Configfile.dimmode.modeName) / sizeof(Configfile.dimmode.modeName[0])); i++)
	{
		if (!strcmp(Configfile.dimmode.modeName[i], dimmingMode))
		{
			IsDimmingModeValid = true;
			break;
		}
	}
	UT_ASSERT_FALSE(IsDimmingModeValid);

	/* Calling tvsettings GetTVDimmingMode and expeting the API to return success */
	result = GetTVDimmingMode(dimmingModeRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_STRING_EQUAL_FATAL(dimmingModeRetry,dimmingMode);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
#endif
	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVDimmingMode() for all negative invocation scenarios
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
 * | 01 | call GetTVDimmingMode() -  Retrieve current TV DimmingMode Mode even before TvInit() | const char * | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVDimmingMode() -  Retrieve current TV DimmingMode mode with invalid argument | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetTVDimmingMode() -  Retrieve current TV DimmingMode Mode valid arguments | const char * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetTVDimmingMode (void)
{
	gTestID = 44;                                    /* It must be 44 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	char dimmingMode[MAX_DIMMING_MODES]={'\0'};
#if 0
	/* Calling tvsettings GetTVDimmingMode and expecting the API to return tvERROR_INVALID_STATE */
	result = GetTVDimmingMode(dimmingMode);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVDimmingMode and expecting the API to return tvERROR_INVALID_PARAM */
	result = GetTVDimmingMode(NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVDimmingMode and expecting the API to return tvERROR_INVALID_STATE */
	result = GetTVDimmingMode(dimmingMode);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);
#endif
	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveTVDimmingMode() for all positive invocation scenarios
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
 * | 02 | call SaveTVDimmingMode() -  Save the current TV DimmingMode by looping through all the values of source input, pqmode, videoFormatType and Diming mode from the test specific config file  |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,tvDimmingMode_t | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveTVDimmingMode (void)
{
	gTestID = 45;                                    /* It must be 45 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveTVDimmingMode for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
	for (size_t i = 0; i < sizeof(Configfile.videoSources.modeId) / sizeof(Configfile.videoSources.modeId[0]); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.pic_modes.modeId) / sizeof(Configfile.pic_modes.modeId[0]); j++)
		{
			for (size_t k = 0; k < sizeof(Configfile.videoformat.modeId) / sizeof(Configfile.videoformat.modeId[0]); k++)                
			{
				for (size_t l = 0; l < sizeof(Configfile.dimmode.modeId) / sizeof(Configfile.dimmode.modeId[0]); l++)
				{
					result = SaveTVDimmingMode((tvVideoSrcType_t) Configfile.videoSources.modeId[i],Configfile.pic_modes.modeId[j],(tvVideoFormatType_t) Configfile.videoformat.modeId[k],(tvDimmingMode_t)Configfile.dimmode.modeId[l]);
					UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
				}
			}
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 11 | call SaveTVDimmingMode() -  Save current TV DimmingMode with valid source input, pqmode, videoFormatType and Diming mode value but not supported by the platform by looping through the test specific config file| tvVideoSrcType_t, int , tvVideoFormatType_t , tvDimmingMode_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 13 | call SaveTVDimmingMode() -  save the TV DimmingMode valid arguments | tvVideoSrcType_t , int ,tvVideoFormatType_t ,tvDimmingMode_t | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveTVDimmingMode (void)
{
	gTestID = 46;                                    /* It must be 46 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int numberOfSources;
	int numberOfPqmodes;
	int numberOfFormats;
	int numberOfDimmodes;
	bool SupportAvailable;

	/* Calling tvsettings SaveTVDimmingMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveTVDimmingMode((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDimmingMode_t)Configfile.dimmode.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveTVDimmingMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveTVDimmingMode(VIDEO_SOURCE_MAX,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDimmingMode_t)Configfile.dimmode.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveTVDimmingMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveTVDimmingMode((tvVideoSrcType_t)-2,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDimmingMode_t)Configfile.dimmode.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveTVDimmingMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveTVDimmingMode((tvVideoSrcType_t)Configfile.videoSources.modeId[0],-1,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDimmingMode_t)Configfile.dimmode.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveTVDimmingMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveTVDimmingMode((tvVideoSrcType_t)Configfile.videoSources.modeId[0],PQ_MODE_MAX,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDimmingMode_t)Configfile.dimmode.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveTVDimmingMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveTVDimmingMode((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],VIDEO_FORMAT_MAX,(tvDimmingMode_t)Configfile.dimmode.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveTVDimmingMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveTVDimmingMode((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)-1,(tvDimmingMode_t)Configfile.dimmode.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveTVDimmingMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveTVDimmingMode((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDimmingMode_t)-1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveTVDimmingMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveTVDimmingMode((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],tvDimmingMode_MAX);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveTVDimmingMode and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfSources = sizeof(Configfile.videoSources.modeId)/sizeof(Configfile.videoSources.modeId[0]);
	for( int i = VIDEO_SOURCE_ALL  ; i < VIDEO_SOURCE_MAX ; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfSources; j++)
		{
			if(Configfile.videoSources.modeId[j] == i)
			{
				SupportAvailable = true;
				break;	
			}
		}

		if(!SupportAvailable){

			result = SaveTVDimmingMode((tvVideoSrcType_t)i,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDimmingMode_t)Configfile.dimmode.modeId[0]);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveTVDimmingMode and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfPqmodes = sizeof(Configfile.pic_modes.modeId)/sizeof(Configfile.pic_modes.modeId[0]);
	for(int i =0 ; i < PQ_MODE_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfPqmodes; j++)
		{
			if(Configfile.pic_modes.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){

			result = SaveTVDimmingMode((tvVideoSrcType_t) Configfile.videoSources.modeId[0],i,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDimmingMode_t)Configfile.dimmode.modeId[0]);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}

	}

	numberOfFormats = sizeof(Configfile.videoformat.modeId)/sizeof(Configfile.videoformat.modeId[0]);
	for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfFormats; j++)
		{
			if(Configfile.videoformat.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){

			result = SaveTVDimmingMode((tvVideoSrcType_t) Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t) i,(tvDimmingMode_t)Configfile.dimmode.modeId[0]);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveTVDimmingMode and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfDimmodes = sizeof(Configfile.dimmode.modeId)/sizeof(Configfile.dimmode.modeId[0]);
	for(int i =tvDimmingMode_Fixed ; i < tvDimmingMode_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfDimmodes; j++)
		{
			if(Configfile.dimmode.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){

			result = SaveTVDimmingMode((tvVideoSrcType_t) Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0], (tvDimmingMode_t)i);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveTVDimmingMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveTVDimmingMode((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDimmingMode_t)Configfile.dimmode.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetLocalDimmingLevel() for all positive invocation scenarios
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
 * | 02 | call SetLocalDimmingLevel() -  Set the Local DimmingLevel with valid value | LDIM_STATE_NONBOOST | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED | Should Pass |
 * | 03 | call SetLocalDimmingLevel() -  Reset the Local DimmingLevel with another valid value | LDIM_STATE_BOOST | tvERROR_NONE | Should Pass |
 * | 04 | call SetLocalDimmingLevel() -  Reset the Local DimmingLevel with another valid value | LDIM_STATE_NONBOOST | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetLocalDimmingLevel (void)
{
	gTestID = 47;                                    /* It must be 47 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetLocalDimmingLevel with input value LDIM_STATE_BOOST and expecting the API to return success */
	for (size_t i = 0; i < (sizeof(Configfile.ldimMode.modeId)/sizeof(Configfile.ldimMode.modeId[0])); i++){
		result = SetLocalDimmingLevel((ldimStateLevel_t) Configfile.ldimMode.modeId[i]);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	}

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 01 | call SetLocalDimmingLevel() - Set the TV Local DimmingLevel even before TvInit() | LDIM_STATE_NONBOOST | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetLocalDimmingLevel() -   Set the TV Local DimmingLevel with invalid input with less than lower range| -1(ldimStateLevel_t ) | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetLocalDimmingLevel() -   Set the TV Local DimmingLevel with invalid input with Max range | LDIM_STATE_MAX | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call SetLocalDimmingLevel() -  Set the TV Local DimmingLevel with valid input after TvTerm() | LDIM_STATE_BOOST | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetLocalDimmingLevel (void)
{
	gTestID = 48;                                    /* It must be 48 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	bool SupportAvailable = false;;

	/* Calling tvsettings SetLocalDimmingLevel with input value LDIM_STATE_NONBOOST and expecting the API to return success */
	result = SetLocalDimmingLevel( (ldimStateLevel_t) Configfile.ldimMode.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetLocalDimmingLevel with input value -1 and expecting the API to return success */
	result = SetLocalDimmingLevel((ldimStateLevel_t ) -1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetLocalDimmingLevel with input value LDIM_STATE_MAX and expecting the API to return success */
	result = SetLocalDimmingLevel(LDIM_STATE_MAX);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	for (size_t i = 0; i < LDIM_STATE_MAX; i++)
	{
		SupportAvailable = false;
		for( int j =0; j < (sizeof(Configfile.ldimMode.modeId)/sizeof(Configfile.ldimMode.modeId[0])) ; j++){
			if( Configfile.ldimMode.modeId[j] == i)	
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SetLocalDimmingLevel( (ldimStateLevel_t )Configfile.ldimMode.modeId[i]);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}


	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetLocalDimmingLevel with input value LDIM_STATE_BOOST and expecting the API to return success */
	result = SetLocalDimmingLevel( (ldimStateLevel_t )Configfile.ldimMode.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	UT_LOG("Out %s",__FUNCTION__);

}

/**
 * @brief Validate GetLocalDimmingLevel() for all positive invocation scenarios
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
 * | 02 | call GetLocalDimmingLevel() -  Retrieve the Local DimmingLevel with valid arguments and and validate Local DimmingLevel by looping through the test specific config file | ldimStateLevel_t * | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call GetLocalDimmingLevel() -  Retrieve the current Local DimmingLevel with valid argument and validate with above value | ldimStateLevel_t *| tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetLocalDimmingLevel (void)
{
	gTestID = 49;                                    /* It must be 49 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	ldimStateLevel_t ldimStateLevel;
	ldimStateLevel_t ldimStateLevelRetry;
	bool IsLdimValid = false;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetLocalDimmingLevel and expeting the API to return success */
	result = GetLocalDimmingLevel(&ldimStateLevel);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	for( int j =0; j < (sizeof(Configfile.ldimMode.modeId)/sizeof(Configfile.ldimMode.modeId[0])) ; j++)
	{
		if(Configfile.ldimMode.modeId[j] == ldimStateLevel)
		{
			IsLdimValid = true;
		}
	}
	UT_ASSERT_TRUE_FATAL(IsLdimValid);

	/* Calling tvsettings GetLocalDimmingLevel and expeting the API to return success */
	result = GetLocalDimmingLevel(&ldimStateLevelRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL_FATAL(ldimStateLevelRetry, ldimStateLevel);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetLocalDimmingLevel() for all negative invocation scenarios
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
 * | 01 | call GetLocalDimmingLevel() -  Retrieve current TV Local DimmingLevel even before TvInit() | ldimStateLevel_t * | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetLocalDimmingLevel() -   Retrieve current TV Local DimmingLevel with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetLocalDimmingLevel() -  Retrieve current TV Local DimmingLevel valid arguments | ldimStateLevel_t * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetLocalDimmingLevel (void)
{
	gTestID = 50;                                    /* It must be 50 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	ldimStateLevel_t ldimStateLevel;

	/* Calling tvsettings GetLocalDimmingLevel and expeting the API to return success */
	result = GetLocalDimmingLevel(&ldimStateLevel);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = GetLocalDimmingLevel(NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetLocalDimmingLevel and expeting the API to return success */
	result = GetLocalDimmingLevel(&ldimStateLevel);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveLocalDimmingLevel() for all positive invocation scenarios
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
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 02 | call SaveLocalDimmingLevel() -  Save the current LocalDimming Level by looping through all the values of sourceId, pqmode, videoFormatType, value from the test specific config file |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,ldimStateLevel_t | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveLocalDimmingLevel (void)
{
	gTestID = 51;                                    /* It must be 51 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveLocalDimmingLevel for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
	for (size_t i = 0; i < sizeof(Configfile.videoSources.modeId) / sizeof(Configfile.videoSources.modeId[0]); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.pic_modes.modeId) / sizeof(Configfile.pic_modes.modeId[0]); j++)
		{
			for (size_t k = 0; k < sizeof(Configfile.videoformat.modeId) / sizeof(Configfile.videoformat.modeId[0]); k++)
			{
				for (size_t l = 0; l < sizeof(Configfile.ldimMode.modeId) / sizeof(Configfile.ldimMode.modeId[0]); l++)
				{
					result = SaveLocalDimmingLevel((tvVideoSrcType_t) Configfile.videoSources.modeId[i],Configfile.pic_modes.modeId[j],(tvVideoFormatType_t) Configfile.videoformat.modeId[k],(ldimStateLevel_t)Configfile.ldimMode.modeId[l]);
					UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
				}
			}
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 11 | call SaveLocalDimmingLevel() -  Save current LocalDimming Level with valid value of source input, pqmode, videoFormatType but not supported by the platform by looping through the test specific config file| tvVideoSrcType_t, int , tvVideoFormatType_t ,ldimStateLevel_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 13 | call SaveLocalDimmingLevel() -  save current Local DimmingLevel valid arguments | tvVideoSrcType_t, int , tvVideoFormatType_t ,ldimStateLevel_t | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveLocalDimmingLevel (void)
{
	gTestID = 52;                                    /* It must be 52 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int numberOfSources;
	int numberOfPqmodes;
	int numberOfFormats;
	int numberOfLdimmodes;
	bool SupportAvailable;

	/* Calling tvsettings SaveLocalDimmingLevel and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveLocalDimmingLevel((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(ldimStateLevel_t)Configfile.ldimMode.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveLocalDimmingLevel and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveLocalDimmingLevel(VIDEO_SOURCE_MAX,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(ldimStateLevel_t)Configfile.ldimMode.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveLocalDimmingLevel and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveLocalDimmingLevel((tvVideoSrcType_t)-2,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(ldimStateLevel_t)Configfile.ldimMode.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveLocalDimmingLevel and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveLocalDimmingLevel((tvVideoSrcType_t)Configfile.videoSources.modeId[0],-1,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(ldimStateLevel_t)Configfile.ldimMode.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveLocalDimmingLevel and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveLocalDimmingLevel((tvVideoSrcType_t)Configfile.videoSources.modeId[0],PQ_MODE_MAX,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(ldimStateLevel_t)Configfile.ldimMode.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveLocalDimmingLevel and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveLocalDimmingLevel((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],VIDEO_FORMAT_MAX,(ldimStateLevel_t)Configfile.ldimMode.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveLocalDimmingLevel and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveLocalDimmingLevel((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)-1,(ldimStateLevel_t)Configfile.ldimMode.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveLocalDimmingLevel and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveLocalDimmingLevel((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(ldimStateLevel_t)-1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveLocalDimmingLevel and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveLocalDimmingLevel((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],LDIM_STATE_MAX);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveLocalDimmingLevel and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfSources = sizeof(Configfile.videoSources.modeId)/sizeof(Configfile.videoSources.modeId[0]);
	for(int i =VIDEO_SOURCE_ALL ; i < VIDEO_SOURCE_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfSources; j++)
		{
			if(Configfile.videoSources.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveLocalDimmingLevel((tvVideoSrcType_t)i,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(ldimStateLevel_t)Configfile.ldimMode.modeId[0]);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveLocalDimmingLevel and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfPqmodes = sizeof(Configfile.pic_modes.modeId)/sizeof(Configfile.pic_modes.modeId[0]);
	for(int i =0 ; i < PQ_MODE_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfPqmodes; j++)
		{
			if(Configfile.pic_modes.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveLocalDimmingLevel((tvVideoSrcType_t) Configfile.videoSources.modeId[0],i,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(ldimStateLevel_t)Configfile.ldimMode.modeId[0]);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveLocalDimmingLevel and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfFormats = sizeof(Configfile.videoformat.modeId)/sizeof(Configfile.videoformat.modeId[0]);
	for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfFormats; j++)
		{
			if(Configfile.videoformat.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveLocalDimmingLevel((tvVideoSrcType_t) Configfile.videoSources.modeId[0],i,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(ldimStateLevel_t)Configfile.ldimMode.modeId[0]);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveLocalDimmingLevel and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfLdimmodes = sizeof(Configfile.ldimMode.modeId)/sizeof(Configfile.ldimMode.modeId[0]);
	for(int i =LDIM_STATE_NONBOOST ; i < LDIM_STATE_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfLdimmodes; j++)
		{
			if(Configfile.videoformat.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveLocalDimmingLevel((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0] ,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(ldimStateLevel_t)i);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveLocalDimmingLevel and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveLocalDimmingLevel((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(ldimStateLevel_t)Configfile.ldimMode.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetBrightness() for all positive invocation scenarios
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
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SetBrightness() -  Set the brightness with valid value | 00 | tvERROR_NONE | Should Pass |
 * | 03 | call SetBrightness() -  Reset the brightness with another valid value | 50 | tvERROR_NONE | Should Pass |
 * | 04 | call SetBrightness() -  Reset the brightness with another valid value | 100 | tvERROR_NONE | Should Pass |
 * | 05 | call SetBrightness() -  Reset the brightness with another valid value | 100 | tvERROR_NONE | Should Pass |
 * | 06 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetBrightness (void)
{
	gTestID = 53;                                    /* It must be 53 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetBrightness with value 0 and expecting the API to return success */
	result = SetBrightness(0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetBrightness with value 50 and expecting the API to return success */
	result = SetBrightness(50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetBrightness with value 100 and expecting the API to return success */
	result = SetBrightness(100);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetBrightness with value 100 and expecting the API to return success */
	result = SetBrightness(100);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
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
	gTestID = 54;                                    /* It must be 54 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings SetBrightness and expecting the API to return tvERROR_INVALID_STATE */
	result = SetBrightness(30);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetBrightness with value -1 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetBrightness(-1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetBrightness with value 101 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetBrightness(101);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetBrightness with value 200 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetBrightness(200);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings the SetBrightness and expecting the API to return tvERROR_INVALID_STATE */
	result = SetBrightness(50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);

}

/**
 * @brief Validate GetBrightness() for all positive invocation scenarios
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
 * | 02 | call GetBrightness() -  Retrieve the current brightness with valid arguments | int * | tvERROR_NONE | Should Pass |
 * | 03 | call GetBrightness() -  Retrieve the current brightness with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetBrightness (void)
{
	gTestID = 55;                                    /* It must be 55 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int brightness = -1;
	int brightnessRetry = -1;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetBrightness and expecting the API to return success */
	result = GetBrightness(&brightness);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_TRUE(brightness >= 0 && brightness <= 100);

	/* Calling tvsettings GetBrightness again and expecting the API to return success */
	result = GetBrightness(&brightnessRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL_FATAL(brightness, brightnessRetry);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetBrightness() for all negative invocation scenarios
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
 * | 01 | call GetBrightness() -  Retrieve current TV brightness even before TvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVBrightness() -  Retrieve current TV brightness with invalid argument | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetBrightness() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetBrightness (void)
{
	gTestID = 56;                                    /* It must be 56 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int brightness = -1;

	/* Calling tvsettings GetBrightness and expecting the API to return tvERROR_INVALID_STATE */
	result = GetBrightness(&brightness);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetBrightness with invalid input and expecting the API to return tvERROR_INVALID_PARAM*/
	result = GetBrightness(NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetBrightness and expecting the API to return tvERROR_INVALID_STATE */
	result = GetBrightness(&brightness);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveBrightness() for all positive invocation scenarios
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
 * | 02 | call SaveBrightness() -  Save the current Color Brightness by looping through all the values of sourceId, pqmode, videoFormatType from the test specific config file  |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,int | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveBrightness (void)
{
	gTestID = 57;                                    /* It must be 57 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveBrightness for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
	for (size_t i = 0; i < sizeof(Configfile.videoSources.modeId) / sizeof(Configfile.videoSources.modeId[0]); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.pic_modes.modeName) / sizeof(Configfile.pic_modes.modeName[0]); j++)
		{
			for (size_t k = 0; k < sizeof(Configfile.videoformat.modeId) / sizeof(Configfile.videoformat.modeId[0]); k++)
			{
				result = SaveBrightness((tvVideoSrcType_t) Configfile.videoSources.modeId[i],Configfile.pic_modes.modeId[j],(tvVideoFormatType_t) Configfile.videoformat.modeId[k],50);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 11 | call SaveBrightness() -  Save current Color Brightness with valid source input, pqmode, videoFormatType value but not supported by the platform by looping through the test specific config file| tvVideoSrcType_t, int , tvVideoFormatType_t , 50| tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 13 | call SaveBrightness() -  save current TV Brightness valid arguments | tvVideoSrcType_t , int ,tvVideoFormatType_t ,int  | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveBrightness (void)
{
	gTestID = 58;                                    /* It must be 58 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int numberOfSources;
	int numberOfPqmodes;
	int numberOfFormats;
	bool SupportAvailable;

	/* Calling tvsettings SaveBrightness and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveBrightness((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveBrightness and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveBrightness(VIDEO_SOURCE_MAX,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveBrightness and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveBrightness((tvVideoSrcType_t)-2,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveBrightness and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveBrightness((tvVideoSrcType_t)Configfile.videoSources.modeId[0],-1,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveBrightness and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveBrightness((tvVideoSrcType_t)Configfile.videoSources.modeId[0],PQ_MODE_MAX,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveBrightness and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveBrightness((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],VIDEO_FORMAT_MAX,50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveBrightness and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveBrightness((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)-1,50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveBrightness and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveBrightness((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],-1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveBrightness and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveBrightness((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],101);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveBrightness and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfSources = sizeof(Configfile.videoSources.modeId)/sizeof(Configfile.videoSources.modeId[0]);
	for(int i =VIDEO_SOURCE_ALL ; i < VIDEO_SOURCE_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfSources; j++)
		{
			if(Configfile.videoSources.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveBrightness((tvVideoSrcType_t)i,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveBrightness and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfPqmodes = sizeof(Configfile.pic_modes.modeId)/sizeof(Configfile.pic_modes.modeId[0]);
	for(int i =0 ; i < PQ_MODE_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfPqmodes; j++)
		{
			if(Configfile.pic_modes.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveBrightness((tvVideoSrcType_t)Configfile.videoSources.modeId[0],i,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveBrightness and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfFormats = sizeof(Configfile.videoformat.modeId)/sizeof(Configfile.videoformat.modeId[0]);
	for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfFormats; j++)
		{
			if(Configfile.videoformat.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveBrightness((tvVideoSrcType_t) Configfile.videoSources.modeId[i],Configfile.pic_modes.modeId[i],(tvVideoFormatType_t)i,50);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}


	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveBrightness and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveBrightness((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetContrast() for all positive invocation scenarios
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
 * | 02 | call SetContrast() -  Set the Contrast with valid value | 00 | tvERROR_NONE | Should Pass |
 * | 03 | call SetContrast() -  Reset the Contrast with another valid value | 50 | tvERROR_NONE | Should Pass |
 * | 04 | call SetContrast() -  Reset the Contrast with another valid value | 100 | tvERROR_NONE | Should Pass |
 * | 05 | call SetContrast() -  Reset the Contrast with another valid value | 100 | tvERROR_NONE | Should Pass |
 * | 06 | call TvTerm() -  Terminate and close the instance of the TV client  | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetContrast (void)
{
	gTestID = 59;                                    /* It must be 59 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetContrast with Contrast value 0 and expecting the API to return success */
	result = SetContrast(0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetContrast with Contrast value 50 and expecting the API to return success */
	result = SetContrast(50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetContrast with Contrast value 100 and expecting the API to return success */
	result = SetContrast(100);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetContrast with Contrast value 100 and expecting the API to return success */
	result = SetContrast(100);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
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
	gTestID = 60;                                    /* It must be 60 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings SetContrast and expecting the API to return tvERROR_INVALID_STATE */
	result = SetContrast(30);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetContrast with Contrast value -1 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetContrast(-1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetContrast with Contrast value 101 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetContrast(101);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetContrast with Contrast value 200 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetContrast(200);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings the SetContrast and expecting the API to return tvERROR_INVALID_STATE */
	result = SetContrast(50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetContrast() for all positive invocation scenarios
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
 * | 02 | call GetContrast() -  Retrieve the current Contrast with valid arguments | int * | tvERROR_NONE | Should Pass |
 * | 03 | call GetContrast() -  Retrieve the current Contrast with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetContrast (void)
{
	gTestID = 61;                                    /* It must be 61 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int contrast = -1;
	int contrastRetry = -1;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetContrast and expecting the API to return success */
	result = GetContrast(&contrast);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_TRUE_FATAL(contrast >= 0 && contrast <= 100);

	/* Calling tvsettings GetContrast again and expecting the API to return success */
	result = GetContrast(&contrastRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL_FATAL(contrast, contrastRetry);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetContrast() for all negative invocation scenarios
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
 * | 01 | call GetContrast() -  Retrieve current TV contrast even before TvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVContrast() -  Retrieve current TV Contrast with invalid argument | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetContrast() -  Retrieve current TV contrast valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetContrast (void)
{
	gTestID = 62;                                    /* It must be 62 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int contrast = -1;

	/* Calling tvsettings GetTVBcklight and expecting the API to return tvERROR_INVALID_STATE */
	result = GetContrast(&contrast);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetContrast with invalid input and expecting the API to return tvERROR_INVALID_PARAM*/
	result = GetContrast(NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetContrast and expecting the API to return tvERROR_INVALID_STATE */
	result = GetContrast(&contrast);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveContrast() for all positive invocation scenarios
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
 * | 02 | call SaveContrast() -  Save the current Color Contrast by looping through all the values of sourceId, pqmode, videoFormatType  from the test specific config file  |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,int | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveContrast (void)
{
	gTestID = 63;                                    /* It must be 63 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveContrast for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
	for (size_t i = 0; i < sizeof(Configfile.videoSources.modeId) / sizeof(Configfile.videoSources.modeId[0]); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.pic_modes.modeName) / sizeof(Configfile.pic_modes.modeName[0]); j++)
		{
			for (size_t k = 0; k < sizeof(Configfile.videoformat.modeId) / sizeof(Configfile.videoformat.modeId[0]); k++)
			{
				result = SaveContrast((tvVideoSrcType_t) Configfile.videoSources.modeId[i],Configfile.pic_modes.modeId[j],(tvVideoFormatType_t) Configfile.videoformat.modeId[k],50);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 11 | call SaveContrast() -  Save current Color Contrast with valid source input, pqmode, videoFormatType value but not supported by the platform by looping through the test specific config file| tvVideoSrcType_t, int , tvVideoFormatType_t , 50| tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 13 | call SaveContrast() -  save current TV Contrast valid arguments | tvVideoSrcType_t, int , tvVideoFormatType_t ,int | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveContrast (void)
{
	gTestID = 64;                                    /* It must be 64 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int numberOfSources;
	int numberOfPqmodes;
	int numberOfFormats;
	bool SupportAvailable;

	/* Calling tvsettings SaveContrast and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveContrast((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveContrast and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveContrast(VIDEO_SOURCE_MAX,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveContrast and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveContrast((tvVideoSrcType_t)-2,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveContrast and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveContrast((tvVideoSrcType_t)Configfile.videoSources.modeId[0],-1,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveContrast and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveContrast((tvVideoSrcType_t)Configfile.videoSources.modeId[0],PQ_MODE_MAX,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveContrast and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveContrast((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],VIDEO_FORMAT_MAX,50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveContrast and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveContrast((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)-1,50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveContrast and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveContrast((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],-1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveContrast and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveContrast((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],101);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveContrast and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfSources = sizeof(Configfile.videoSources.modeId)/sizeof(Configfile.videoSources.modeId[0]);
	for(int i =VIDEO_SOURCE_ALL ; i < VIDEO_SOURCE_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfSources; j++)
		{
			if(Configfile.videoSources.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveContrast((tvVideoSrcType_t)i,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveContrast and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfPqmodes = sizeof(Configfile.pic_modes.modeId)/sizeof(Configfile.pic_modes.modeId[0]);
	for(int i =0 ; i < PQ_MODE_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfPqmodes; j++)
		{
			if(Configfile.pic_modes.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveContrast((tvVideoSrcType_t)Configfile.videoSources.modeId[0],i,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveContrast and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfFormats = sizeof(Configfile.videoformat.modeId)/sizeof(Configfile.videoformat.modeId[0]);
	for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfFormats; j++)
		{
			if(Configfile.videoformat.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveContrast((tvVideoSrcType_t) Configfile.videoSources.modeId[i],Configfile.pic_modes.modeId[i],(tvVideoFormatType_t)i,50);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}
	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveContrast and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveContrast((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetSharpness() for all positive invocation scenarios
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
 * | 02 | call SetSharpness() -  Set the sharpness with valid value | 00 | tvERROR_NONE | Should Pass |
 * | 03 | call SetSharpness() -  Reset the sharpness with another valid value | 50 | tvERROR_NONE | Should Pass |
 * | 04 | call SetSharpness() -  Reset the sharpness with another valid value | 100 | tvERROR_NONE | Should Pass |
 * | 05 | call SetSharpness() -  Reset the sharpness with another valid value | 100 | tvERROR_NONE | Should Pass |
 * | 06 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetSharpness (void)
{
	gTestID = 65;                                    /* It must be 65 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetSharpness with Sharpness value 0 and expecting the API to return success */
	result = SetSharpness(0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetSharpness with Sharpness value 50 and expecting the API to return success */
	result = SetSharpness(50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetSharpness with Sharpness value 100 and expecting the API to return success */
	result = SetSharpness(100);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetSharpness with Sharpness value 100 and expecting the API to return success */
	result = SetSharpness(100);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
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
	gTestID = 66;                                    /* It must be 66 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings SetSharpness and expecting the API to return tvERROR_INVALID_STATE */
	result = SetSharpness(30);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetSharpness with Sharpness value -1 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetSharpness(-1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetSharpness with Sharpness value 101 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetSharpness(101);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetSharpness with Sharpness value 200 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetSharpness(200);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings the SetSharpness and expecting the API to return tvERROR_INVALID_STATE */
	result = SetSharpness(50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetSharpness() for all positive invocation scenarios
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
 * | 02 | call GetSharpness() -  Retrieve the current sharpness with valid arguments | int * | tvERROR_NONE | Should Pass |
 * | 03 | call GetSharpness() -  Retrieve the current sharpness with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetSharpness (void)
{
	gTestID = 67;                                    /* It must be 67 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int sharpness = -1;
	int sharpnessRetry = -1;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetSharpness and expecting the API to return success */
	result = GetSharpness(&sharpness);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_TRUE(sharpness >= 0 && sharpness <= 100);

	/* Calling tvsettings GetSharpness again and expecting the API to return success */
	result = GetSharpness(&sharpnessRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL_FATAL(sharpness, sharpnessRetry);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetSharpness() for all negative invocation scenarios
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
 * | 01 | call GetSharpness() -  Retrieve current TV sharpness even before TvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVSharpness() -  Retrieve current TV Sharpness with invalid argument | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetSharpness() -  Retrieve current TV sharpness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetSharpness (void)
{
	gTestID = 68;                                    /* It must be 68 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int sharpness = -1;

	/* Calling tvsettings GetTVBcklight and expecting the API to return tvERROR_INVALID_STATE */
	result = GetSharpness(&sharpness);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetSharpness with invalid input and expecting the API to return tvERROR_INVALID_PARAM*/
	result = GetSharpness(NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetSharpness and expecting the API to return tvERROR_INVALID_STATE */
	result = GetSharpness(&sharpness);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveSharpness() for all positive invocation scenarios
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
 * | 02 | call SaveSharpness() -  Save the current Color Sharpness by looping through all the values of sourceId, pqmode, videoFormatType from the test specific config file  |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,int | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveSharpness (void)
{
	gTestID = 69;                                    /* It must be 69 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveSharpness for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
	for (size_t i = 0; i < sizeof(Configfile.videoSources.modeId) / sizeof(Configfile.videoSources.modeId[0]); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.pic_modes.modeName) / sizeof(Configfile.pic_modes.modeName[0]); j++)
		{
			for (size_t k = 0; k < sizeof(Configfile.videoformat.modeId) / sizeof(Configfile.videoformat.modeId[0]); k++)
			{
				result = SaveSharpness((tvVideoSrcType_t) Configfile.videoSources.modeId[i],Configfile.pic_modes.modeId[j],(tvVideoFormatType_t) Configfile.videoformat.modeId[k],50);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 11 | call SaveSharpness() -  Save current Color Sharpness with valid source input, pqmode, videoFormatType value but not supported by the platform by looping through the test specific config file| tvVideoSrcType_t, int , tvVideoFormatType_t , 50| tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 13 | call SaveSharpness() -  save current TV Sharpness valid arguments | tvVideoSrcType_t, int , tvVideoFormatType_t ,int | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveSharpness (void)
{
	gTestID = 70;                                    /* It must be 70 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int numberOfSources;
	int numberOfPqmodes;
	int numberOfFormats;
	bool SupportAvailable;

	/* Calling tvsettings SaveSharpness and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSharpness((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveSharpness and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSharpness(VIDEO_SOURCE_MAX,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveSharpness and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSharpness((tvVideoSrcType_t)-2,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveSharpness and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSharpness((tvVideoSrcType_t)Configfile.videoSources.modeId[0],-1,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveSharpness and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSharpness((tvVideoSrcType_t)Configfile.videoSources.modeId[0],PQ_MODE_MAX,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveSharpness and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSharpness((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],VIDEO_FORMAT_MAX,50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveSharpness and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSharpness((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)-1,50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveSharpness and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSharpness((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],-1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveSharpness and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSharpness((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],101);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveSharpness and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfSources = sizeof(Configfile.videoSources.modeId)/sizeof(Configfile.videoSources.modeId[0]);
	for(int i =VIDEO_SOURCE_ALL ; i < VIDEO_SOURCE_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfSources; j++)
		{
			if(Configfile.videoSources.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveSharpness((tvVideoSrcType_t)i,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveSharpness and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfPqmodes = sizeof(Configfile.pic_modes.modeId)/sizeof(Configfile.pic_modes.modeId[0]);
	for(int i =0 ; i < PQ_MODE_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfPqmodes; j++)
		{
			if(Configfile.pic_modes.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveSharpness((tvVideoSrcType_t)Configfile.videoSources.modeId[0],i,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveSharpness and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfFormats = sizeof(Configfile.videoformat.modeId)/sizeof(Configfile.videoformat.modeId[0]);
	for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfFormats; j++)
		{
			if(Configfile.videoformat.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveSharpness((tvVideoSrcType_t) Configfile.videoSources.modeId[i],Configfile.pic_modes.modeId[i],(tvVideoFormatType_t)i,50);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}
	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveSharpness and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSharpness((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetSaturation() for all positive invocation scenarios
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
 * | 02 | call SetSaturation() -  Set the saturation with valid value | 0 | tvERROR_NONE | Should Pass |
 * | 03 | call SetSaturation() -  Reset the saturation with another valid value | 50 | tvERROR_NONE | Should Pass |
 * | 04 | call SetSaturation() -  Reset the saturation with another valid value | 100 | tvERROR_NONE | Should Pass |
 * | 05 | call SetSaturation() -  Reset the saturation with another valid value | 100 | tvERROR_NONE | Should Pass |
 * | 06 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetSaturation (void)
{
	gTestID = 71;                                    /* It must be 71 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetSaturation with Saturation value 0 and expecting the API to return success */
	result = SetSaturation(0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetSaturation with Saturation value 50 and expecting the API to return success */
	result = SetSaturation(50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetSaturation with Saturation value 100 and expecting the API to return success */
	result = SetSaturation(100);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetSaturation with Saturation value 100 and expecting the API to return success */
	result = SetSaturation(100);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
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
	gTestID = 72;                                    /* It must be 72 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings SetSaturation and expecting the API to return tvERROR_INVALID_STATE */
	result = SetSaturation(30);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetSaturation with Saturation value -1 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetSaturation(-1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetSaturation with Saturation value 101 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetSaturation(101);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetSaturation with Saturation value 200 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetSaturation(200);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings the SetSaturation and expecting the API to return tvERROR_INVALID_STATE */
	result = SetSaturation(50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetSaturation() for all positive invocation scenarios
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
 * | 02 | call GetSaturation() -  Retrieve the current saturation with valid arguments | int * | tvERROR_NONE | Should Pass |
 * | 03 | call GetSaturation() -  Retrieve the current saturation with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetSaturation (void)
{
	gTestID = 73;                                    /* It must be 73 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int saturation = -1;
	int saturationRetry = -1;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetSaturation and expecting the API to return success */
	result = GetSaturation(&saturation);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_TRUE(saturation >= 0 && saturation <= 100);

	/* Calling tvsettings GetSaturation again and expecting the API to return success */
	result = GetSaturation(&saturationRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL_FATAL(saturation, saturationRetry);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetSaturation() for all negative invocation scenarios
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
 * | 01 | call GetSaturation() -  Retrieve current TV saturation even before TvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVSaturation() -  Retrieve current TV Saturation with invalid argument | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetSaturation() -  Retrieve current TV saturation valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetSaturation (void)
{
	gTestID = 74;                                    /* It must be 74 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int saturation = -1;

	/* Calling tvsettings GetTVBcklight and expecting the API to return tvERROR_INVALID_STATE */
	result = GetSaturation(&saturation);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetSaturation with invalid input and expecting the API to return tvERROR_INVALID_PARAM*/
	result = GetSaturation(NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetSaturation and expecting the API to return tvERROR_INVALID_STATE */
	result = GetSaturation(&saturation);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveSaturation() for all positive invocation scenarios
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
 * | 02 | call SaveSaturation() -  Save the current Color Saturation by looping through all the values of sourceId, pqmode, videoFormatType from the test specific config file  |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,int | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveSaturation (void)
{
	gTestID = 75;                                    /* It must be 75 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveSaturation for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
	for (size_t i = 0; i < sizeof(Configfile.videoSources.modeId) / sizeof(Configfile.videoSources.modeId[0]); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.pic_modes.modeName) / sizeof(Configfile.pic_modes.modeName[0]); j++)
		{
			for (size_t k = 0; k < sizeof(Configfile.videoformat.modeId) / sizeof(Configfile.videoformat.modeId[0]); k++)
			{
				result = SaveSaturation((tvVideoSrcType_t) Configfile.videoSources.modeId[i],Configfile.pic_modes.modeId[j],(tvVideoFormatType_t) Configfile.videoformat.modeId[k],50);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 11 | call SaveSaturation() -  Save current Color Saturation with valid source input, pqmode, videoFormatType value but not supported by the platform by looping through the test specific config file| tvVideoSrcType_t, int , tvVideoFormatType_t , 50| tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 13 | call SaveSaturation() -  save current TV Saturation valid arguments | tvVideoSrcType_t, int , tvVideoFormatType_t ,int | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveSaturation (void)
{
	gTestID = 76;                                    /* It must be 76 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int numberOfSources;
	int numberOfPqmodes;
	int numberOfFormats;
	bool SupportAvailable;

	/* Calling tvsettings SaveSaturation and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSaturation((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveSaturation and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSaturation(VIDEO_SOURCE_MAX,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveSaturation and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSaturation((tvVideoSrcType_t)-2,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveSaturation and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSaturation((tvVideoSrcType_t)Configfile.videoSources.modeId[0],-1,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveSaturation and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSaturation((tvVideoSrcType_t)Configfile.videoSources.modeId[0],PQ_MODE_MAX,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveSaturation and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSaturation((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],VIDEO_FORMAT_MAX,50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveSaturation and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSaturation((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)-1,50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveSaturation and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSaturation((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],-1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveSaturation and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSaturation((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],101);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveSaturation and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfSources = sizeof(Configfile.videoSources.modeId)/sizeof(Configfile.videoSources.modeId[0]);
	for(int i =VIDEO_SOURCE_ALL ; i < VIDEO_SOURCE_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfSources; j++)
		{
			if(Configfile.videoSources.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveSaturation((tvVideoSrcType_t)i,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveSaturation and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfPqmodes = sizeof(Configfile.pic_modes.modeId)/sizeof(Configfile.pic_modes.modeId[0]);
	for(int i =0 ; i < PQ_MODE_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfPqmodes; j++)
		{
			if(Configfile.pic_modes.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveSaturation((tvVideoSrcType_t)Configfile.videoSources.modeId[0],i,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveSaturation and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfFormats = sizeof(Configfile.videoformat.modeId)/sizeof(Configfile.videoformat.modeId[0]);
	for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfFormats; j++)
		{
			if(Configfile.videoformat.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveSaturation((tvVideoSrcType_t) Configfile.videoSources.modeId[i],Configfile.pic_modes.modeId[i],(tvVideoFormatType_t)i,50);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveSaturation and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSaturation((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetHue() for all positive invocation scenarios
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
 * | 02 | call SetHue() -  Set the hue with valid value | 00 | tvERROR_NONE | Should Pass |
 * | 03 | call SetHue() -  Reset the hue with another valid value | 50 | tvERROR_NONE | Should Pass |
 * | 04 | call SetHue() -  Reset the hue with another valid value | 100 | tvERROR_NONE | Should Pass |
 * | 05 | call SetHue() -  Reset the hue with another valid value | 100 | tvERROR_NONE | Should Pass |
 * | 06 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetHue (void)
{
	gTestID = 77;                                    /* It must be 77 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetHue with Hue value 0 and expecting the API to return success */
	result = SetHue(0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetHue with Hue value 50 and expecting the API to return success */
	result = SetHue(50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetHue with Hue value 100 and expecting the API to return success */
	result = SetHue(100);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetHue with Hue value 100 and expecting the API to return success */
	result = SetHue(100);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
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
	gTestID = 78;                                    /* It must be 78 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings SetHue and expecting the API to return tvERROR_INVALID_STATE */
	result = SetHue(30);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetHue with Hue value -1 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetHue(-1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetHue with Hue value 101 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetHue(101);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetHue with Hue value 200 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetHue(200);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings the SetHue and expecting the API to return tvERROR_INVALID_STATE */
	result = SetHue(50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetHue() for all positive invocation scenarios
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
 * | 02 | call GetHue() -  Retrieve the current Hue with valid arguments | int * | tvERROR_NONE | Should Pass |
 * | 03 | call GetHue() -  Retrieve the current Hue with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetHue (void)
{
	gTestID = 79;                                    /* It must be 79 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int hue = -1;
	int hueRetry = -1;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetHue and expecting the API to return success */
	result = GetHue(&hue);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_TRUE(hue >= 0 && hue <= 100);

	/* Calling tvsettings GetHue again and expecting the API to return success */
	result = GetHue(&hueRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL_FATAL(hue, hueRetry);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetHue() for all negative invocation scenarios
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
 * | 01 | call GetHue() -  Retrieve current TV Hue even before TvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetHue() -  Retrieve current TV Hue with invalid argument | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetHue() -  Retrieve current TV Hue valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetHue (void)
{
	gTestID = 80;                                    /* It must be 80 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int hue = -1;

	/* Calling tvsettings GetTVBcklight and expecting the API to return tvERROR_INVALID_STATE */
	result = GetHue(&hue);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetHue with invalid input and expecting the API to return tvERROR_INVALID_PARAM*/
	result = GetHue(NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetHue and expecting the API to return tvERROR_INVALID_STATE */
	result = GetHue(&hue);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveHue() for all positive invocation scenarios
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
 * | 02 | call SaveHue() - Save the current Color Hue by looping through all the values of sourceId, pqmode, videoFormatType from the test specific config file  |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,int | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveHue (void)
{
	gTestID = 29;                                    /* It must be 29 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveHue for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
	for (size_t i = 0; i < sizeof(Configfile.videoSources.modeId) / sizeof(Configfile.videoSources.modeId[0]); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.pic_modes.modeName) / sizeof(Configfile.pic_modes.modeName[0]); j++)
		{
			for (size_t k = 0; k < sizeof(Configfile.videoformat.modeId) / sizeof(Configfile.videoformat.modeId[0]); k++)
			{
				result = SaveHue((tvVideoSrcType_t) Configfile.videoSources.modeId[i],Configfile.pic_modes.modeId[j],(tvVideoFormatType_t) Configfile.videoformat.modeId[k],50);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 11 | call SaveHue() -  Save current Color Hue with valid source input, pqmode, videoFormatType value but not supported by the platform by looping through the test specific config file| tvVideoSrcType_t, int , tvVideoFormatType_t , 50| tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call TvTerm()  -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 13 | call SaveHue() -  save current TV Hue valid arguments |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,int | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveHue (void)
{
	gTestID = 82;                                    /* It must be 82 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int numberOfSources;
	int numberOfPqmodes;
	int numberOfFormats;
	bool SupportAvailable;

	/* Calling tvsettings SaveHue and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveHue((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveHue and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveHue(VIDEO_SOURCE_MAX,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveHue and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveHue((tvVideoSrcType_t)-2,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveHue and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveHue((tvVideoSrcType_t)Configfile.videoSources.modeId[0],-1,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveHue and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveHue((tvVideoSrcType_t)Configfile.videoSources.modeId[0],PQ_MODE_MAX,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveHue and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveHue((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],VIDEO_FORMAT_MAX,50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveHue and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveHue((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)-1,50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveHue and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveHue((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],-1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveHue and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveHue((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],101);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveHue and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfSources = sizeof(Configfile.videoSources.modeId)/sizeof(Configfile.videoSources.modeId[0]);
	for(int i =VIDEO_SOURCE_ALL ; i < VIDEO_SOURCE_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfSources; j++)
		{
			if(Configfile.videoSources.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveHue((tvVideoSrcType_t)i,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveHue and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfPqmodes = sizeof(Configfile.pic_modes.modeId)/sizeof(Configfile.pic_modes.modeId[0]);
	for(int i =0 ; i < PQ_MODE_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfPqmodes; j++)
		{
			if(Configfile.pic_modes.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveHue((tvVideoSrcType_t)Configfile.videoSources.modeId[0],i,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveHue and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfFormats = sizeof(Configfile.videoformat.modeId)/sizeof(Configfile.videoformat.modeId[0]);
	for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfFormats; j++)
		{
			if(Configfile.videoformat.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveHue((tvVideoSrcType_t) Configfile.videoSources.modeId[i],Configfile.pic_modes.modeId[i],(tvVideoFormatType_t)i,50);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveHue and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveHue((tvVideoSrcType_t)Configfile.videoSources.modeId[0], Configfile.pic_modes.modeId[0], (tvVideoFormatType_t)Configfile.videoformat.modeId[0], 50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetColorTemperature() for all positive invocation scenarios
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
 * | 02 | call SetColorTemperature() -  Set the TV ColorTemperature by looping through all the values of ColorTemperatures from the test specific config file | tvColorTemp_t | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetColorTemperature (void)
{
	gTestID = 83;                                    /* It must be 83 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemperature and expecting the API to return success */
	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{
		result = SetColorTemperature((tvColorTemp_t)Configfile.colorTemperature.modeId[i]);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	}

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 01 | call SetColorTemperature() - Set the TV ColorTemperature even before TvInit() | tvColorTemp_t | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemperature() -   Set the TV ColorTemperature with less than the lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetColorTemperature() -   Set the TV ColorTemperature with max range | tvColorTemp_MAX | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetColorTemperature() -   Set the TV ColorTemperature with valid value but not supported by the platform by looping through the test specific config file | tvColorTemp_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 07 | call SetColorTemperature() -  Set the TV ColorTemperature with valid input after TvTerm() | tvColorTemp_t | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetColorTemperature (void)
{
	gTestID = 84;                                    /* It must be 84*/
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	int numberofColortemp;

	/* Calling tvsettings SetColorTemperature and expecting the API to return tvERROR_INVALID_STATE */
	result = SetColorTemperature((tvColorTemp_t)Configfile.colorTemperature.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemperature and expecting the API to return success */
	result = SetColorTemperature((tvColorTemp_t)-1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetColorTemperature and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemperature(tvColorTemp_MAX);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetColorTemperature and expecting the API to return tvERROR_INVALID_PARAM */
	numberofColortemp = sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0]);
	for(int i =0 ; i < numberofColortemp; i++)
	{
		for(int j = i+1 ; j < numberofColortemp; j++)
		{
			result = SetColorTemperature((tvColorTemp_t) (Configfile.colorTemperature.modeId[i] | Configfile.colorTemperature.modeId[j]));
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings the SetColorTemperature and expecting the API to return tvERROR_INVALID_STATE */
	result = SetColorTemperature((tvColorTemp_t)Configfile.colorTemperature.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/** 
 * @brief Validate GetColorTemperature() for all positive invocation scenarios
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
 * | 02 | call GetColorTemperature() -  Retrieve the current ColorTemperature and validate ColorTemperature by looping through the test specific config file values | tvColorTemp_t *  | tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemperature() -  Retrieve the current ColorTemperature with valid argument and validate with above value | tvColorTemp_t * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetColorTemperature (void)
{
	gTestID = 85;                                    /* It must be 85 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	tvColorTemp_t tvColorTemp = tvColorTemp_MAX;
	tvColorTemp_t tvColorTempRetry = tvColorTemp_MAX;
	bool IsColorTempValid = false;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetColorTemperature and expeting the API to return success */
	result = GetColorTemperature(&tvColorTemp);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{
		if (Configfile.colorTemperature.modeId[i] == tvColorTemp)
		{
			IsColorTempValid = true;
			break;
		}
	}
	UT_ASSERT_FALSE(IsColorTempValid);

	/* Calling tvsettings GetColorTemperature and expeting the API to return success */
	result = GetColorTemperature(&tvColorTempRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL_FATAL(tvColorTemp, tvColorTempRetry);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetColorTemperature() for all negative invocation scenarios
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
 * | 01 | call GetColorTemperature() -  Retrieve current TV ColorTemperature even before TvInit() | tvColorTemp_t  * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVColorTemperature() -  Retrieve current TV ColorTemperature with invalid argument | NULL | tvERROR_INVALID_PARAM |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetColorTemperature() -  Retrieve current TV ColorTemperature valid arguments | tvColorTemp_t  * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetColorTemperature (void)
{
	gTestID = 86;                                    /* It must be 86 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	tvColorTemp_t  tvColorTemp =  tvColorTemp_MAX;

	/* Calling tvsettings GetTVColorTemperature and expecting the API to return tvERROR_INVALID_STATE */
	result = GetColorTemperature(&tvColorTemp);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVColorTemperature with invalid input and expecting the API to return tvERROR_INVALID_PARAM */
	result = GetColorTemperature(NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVColorTemperature and expecting the API to return tvERROR_INVALID_STATE */
	result = GetColorTemperature(&tvColorTemp);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveColorTemperature() for all positive invocation scenarios
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
 * | 02 | call SaveColorTemperature() -  Save the current Color Temperature by looping through all the values of sourceId, pqmode, videoFormatType and colortemp from the test specific config file | tvVideoSrcType_t , int ,tvVideoFormatType_t ,tvColorTemp_t | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveColorTemperature (void)
{
	gTestID = 87;                                    /* It must be 87 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveColorTemperature for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
	for (size_t i = 0; i < sizeof(Configfile.videoSources.modeId) / sizeof(Configfile.videoSources.modeId[0]); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.pic_modes.modeId) / sizeof(Configfile.pic_modes.modeId[0]); j++)
		{
			for (size_t k = 0; k < sizeof(Configfile.videoformat.modeId) / sizeof(Configfile.videoformat.modeId[0]); k++)
			{
				for (size_t l = 0; l < sizeof(Configfile.colorTemperature.modeId) / sizeof(Configfile.colorTemperature.modeId[0]); l++)
				{
					result = SaveColorTemperature((tvVideoSrcType_t) Configfile.videoSources.modeId[i],Configfile.pic_modes.modeId[j],(tvVideoFormatType_t) Configfile.videoformat.modeId[k],(tvColorTemp_t)Configfile.colorTemperature.modeId[l]);
					UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
				}
			}
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 11 | call SaveColorTemperature() -  Save current Color Temperature with valid source input, pqmode, videoFormatType, colortemp value but not supported by the platform by looping through the test specific config file| tvVideoSrcType_t, int , tvVideoFormatType_t , tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 13 | call SaveColorTemperature() -  Save the current Color Temperature valid arguments | HDMI, 0, HDR_TYPE_HLG, tvColorTemp_t | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveColorTemperature (void)
{
	gTestID = 88;                                    /* It must be 88 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int numberOfSources;
	int numberOfPqmodes;
	int numberOfFormats;
	int numberOfDimmodes, numberOfColorTemperature;
	bool SupportAvailable;

	/* Calling tvsettings SaveColorTemperature and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveColorTemperature((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvColorTemp_t)Configfile.colorTemperature.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveColorTemperature and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveColorTemperature(VIDEO_SOURCE_MAX,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvColorTemp_t)Configfile.colorTemperature.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveColorTemperature and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveColorTemperature((tvVideoSrcType_t)-2,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvColorTemp_t)Configfile.colorTemperature.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveColorTemperature and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveColorTemperature((tvVideoSrcType_t)Configfile.videoSources.modeId[0],-1,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvColorTemp_t)Configfile.colorTemperature.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveColorTemperature and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveColorTemperature((tvVideoSrcType_t)Configfile.videoSources.modeId[0],PQ_MODE_MAX,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvColorTemp_t)Configfile.colorTemperature.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveColorTemperature and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveColorTemperature((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],VIDEO_FORMAT_MAX,(tvColorTemp_t)Configfile.colorTemperature.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveColorTemperature and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveColorTemperature((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)-1,(tvColorTemp_t)Configfile.colorTemperature.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveColorTemperature and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveColorTemperature((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvColorTemp_t)-1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveColorTemperature and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveColorTemperature((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],tvColorTemp_MAX);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveColorTemperature and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfSources = sizeof(Configfile.videoSources.modeId)/sizeof(Configfile.videoSources.modeId[0]);
	for(int i =VIDEO_SOURCE_ALL ; i < VIDEO_SOURCE_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfSources; j++)
		{
			if(Configfile.videoSources.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveColorTemperature((tvVideoSrcType_t)i,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvColorTemp_t)Configfile.colorTemperature.modeId[0]);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveColorTemperature and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfPqmodes = sizeof(Configfile.pic_modes.modeId)/sizeof(Configfile.pic_modes.modeId[0]);
	for(int i =0 ; i < PQ_MODE_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfPqmodes; j++)
		{
			if(Configfile.pic_modes.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveColorTemperature((tvVideoSrcType_t)Configfile.videoSources.modeId[0],i,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvColorTemp_t)Configfile.colorTemperature.modeId[0]);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveColorTemperature and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfFormats = sizeof(Configfile.videoformat.modeId)/sizeof(Configfile.videoformat.modeId[0]);
	for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfFormats; j++)
		{
			if(Configfile.videoformat.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveColorTemperature((tvVideoSrcType_t) Configfile.videoSources.modeId[i],Configfile.pic_modes.modeId[i],(tvVideoFormatType_t)i,(tvColorTemp_t)Configfile.colorTemperature.modeId[0]);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveColorTemperature and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfColorTemperature = sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0]);
	for(int i =tvColorTemp_STANDARD ; i < tvColorTemp_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfColorTemperature; j++)
		{
			if(Configfile.colorTemperature.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveColorTemperature((tvVideoSrcType_t) Configfile.videoSources.modeId[i],Configfile.pic_modes.modeId[i],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvColorTemp_t)i);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveColorTemperature and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveColorTemperature((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvColorTemp_t)Configfile.colorTemperature.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);

}

/**
 * @brief Validate SetAspectRatio() for all positive invocation scenarios
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
 * | 02 | call SetAspectRatio() -  Set the TV Aspect ratio by looping through all the values of aspect ratios from the test specific config file | tvDisplayMode_t | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetAspectRatio (void)
{
	gTestID = 89;                                    /* It must be 89 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetAspectRatio and expecting the API to return success */
	for (size_t i = 0; i < (sizeof(Configfile.AspectRatio.modeId)/sizeof(Configfile.AspectRatio.modeId[0])); i++)
	{
		result = SetAspectRatio((tvDisplayMode_t)Configfile.AspectRatio.modeId[i]);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	}

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 01 | call SetAspectRatio() - Set the TV AspectRatio even before TvInit() | tvDisplayMode_16x9 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetAspectRatio() -  Set the TV Aspect ratio with invalid input | -1 (tvDisplayMode_t )| tvERROR_INVALID_PARAM |
 * | 04 | call SetAspectRatio() -  Set the TV Aspect ratio with invalid input | tvDisplayMode_MAX | tvERROR_INVALID_PARAM |
 * | 05 | call SetAspectRatio() -   Set the TV Aspect ratio with valid value but not supported by the platform by looping through the test specific config file | tvDisplayMode_t  | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 07 | call SetAspectRatio() -  Set the TV AspectRatio with valid input after TvTerm() | tvDisplayMode_16x9 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetAspectRatio (void)
{
	gTestID = 90;                                    /* It must be 90*/
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	int numberofDisplaymode;

	/* Calling tvsettings SetTVAspectRatio and expecting the API to return tvERROR_INVALID_STATE */
	result = SetAspectRatio((tvDisplayMode_t)Configfile.AspectRatio.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetTVAspectRatio and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetAspectRatio((tvDisplayMode_t)-1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetTVAspectRatio and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetAspectRatio(tvDisplayMode_MAX);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetTVAspectRatio and expecting the API to return tvERROR_INVALID_PARAM */
	numberofDisplaymode = sizeof(Configfile.AspectRatio.modeId)/sizeof(Configfile.AspectRatio.modeId[0]);
	for(int i =0 ; i < numberofDisplaymode; i++)
	{
		for(int j = i+1 ; j < numberofDisplaymode; j++)
		{
			result = SetAspectRatio((tvDisplayMode_t) (Configfile.AspectRatio.modeId[i] | Configfile.AspectRatio.modeId[j]));
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings the SetTVColorTemperature and expecting the API to return tvERROR_INVALID_STATE */
	result = SetAspectRatio((tvDisplayMode_t)Configfile.AspectRatio.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetAspectRatio() for all positive invocation scenarios
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
 * | 02 | call GetAspectRatio() -  Retrieve the current AspectRatio and validate AspectRatio by looping through the test specific config file values | tvDisplayMode_t *  | tvERROR_NONE | Should Pass |
 * | 03 | call GetAspectRatio() -  Retrieve the current AspectRatio with valid argument and validate with above value | tvDisplayMode_t * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetAspectRatio (void)
{
	gTestID = 91;                                    /* It must be 91 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	tvDisplayMode_t tvDisplayMode = tvDisplayMode_MAX;
	tvDisplayMode_t tvDisplayModeRetry = tvDisplayMode_MAX;
	bool isDisplayModeValid = false;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetAspectRatio and expeting the API to return success */
	result = GetAspectRatio(&tvDisplayMode);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	for (size_t i = 0; i < (sizeof(Configfile.AspectRatio.modeId)/sizeof(Configfile.AspectRatio.modeId[0])); i++)
	{
		if (Configfile.AspectRatio.modeId[i] == tvDisplayMode)
		{
			isDisplayModeValid = true;
			break;
		}
	}
	UT_ASSERT_FALSE(isDisplayModeValid);

	/* Calling tvsettings GetAspectRatio and expeting the API to return success */
	result = GetAspectRatio(&tvDisplayModeRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL_FATAL(tvDisplayMode,tvDisplayModeRetry);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
}

/**
 * @brief Validate GetAspectRatio() for all negative invocation scenarios
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
 * | 01 | call GetAspectRatio() -  Retrieve current TV AspectRatio even before TvInit() | tvDisplayMode_t * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetAspectRatio() -  Retrieve current TV AspectRatio with invalid argument | NULL | tvERROR_INVALID_PARAM |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetAspectRatio() -  Retrieve current TV AspectRatio valid arguments | tvDisplayMode_t * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetAspectRatio (void)
{
	gTestID = 92;                                    /* It must be 92 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	tvDisplayMode_t tvDisplayMode = tvDisplayMode_MAX;

	/* Calling tvsettings GetTVAspectRatio and expecting the API to return tvERROR_INVALID_STATE */
	result = GetAspectRatio(&tvDisplayMode);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVAspectRatio with invalid input and expecting the API to return tvERROR_INVALID_PARAM*/
	result = GetAspectRatio(NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVAspectRatio and expecting the API to return tvERROR_INVALID_STATE */
	result = GetAspectRatio(&tvDisplayMode);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveAspectRatio() for all positive invocation scenarios
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
 * | 02 | call SaveAspectRatio() -  Save the current Aspect Ratio by looping through all the values of sourcetype, pqmode and video format type from the test specific config file | tvVideoSrcType_t , int ,tvVideoFormatType_t ,tvDisplayMode_t | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveAspectRatio (void)
{
	gTestID = 93;                                    /* It must be 93 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveAspectRatio for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
	for (size_t i = 0; i < sizeof(Configfile.videoSources.modeId) / sizeof(Configfile.videoSources.modeId[0]); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.pic_modes.modeId) / sizeof(Configfile.pic_modes.modeId[0]); j++)
		{
			for (size_t k = 0; k < sizeof(Configfile.videoformat.modeId) / sizeof(Configfile.videoformat.modeId[0]); k++)
			{
				for (size_t l = 0; l < sizeof(Configfile.AspectRatio.modeId) / sizeof(Configfile.AspectRatio.modeId[0]); l++)
				{
					result = SaveAspectRatio((tvVideoSrcType_t) Configfile.videoSources.modeId[i],Configfile.pic_modes.modeId[j],(tvVideoFormatType_t) Configfile.videoformat.modeId[k],(tvDisplayMode_t)Configfile.AspectRatio.modeId[l]);
					UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
				}
			}
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 11 | call SaveAspectRatio() -  Save current Aspect Ratio with valid source input, pqmode, videoFormatType, aspectratio value but not supported by the platform by looping through the test specific config file| tvVideoSrcType_t, int , tvVideoFormatType_t , tvDisplayMode_t| tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 13 | call SaveAspectRatio() -  Save the current Aspect Ratio valid arguments | tvVideoSrcType_t , int ,tvVideoFormatType_t ,tvDisplayMode_t | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveAspectRatio (void)
{
	gTestID = 94;                                    /* It must be 94 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int numberOfSources;
	int numberOfPqmodes;
	int numberOfFormats;
	int numberOfAspectRatios;
	bool SupportAvailable;

	/* Calling tvsettings SaveAspectRatio and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveAspectRatio((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDisplayMode_t)Configfile.AspectRatio.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveAspectRatio and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveAspectRatio(VIDEO_SOURCE_MAX,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDisplayMode_t)Configfile.AspectRatio.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveAspectRatio and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveAspectRatio((tvVideoSrcType_t)-2,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDisplayMode_t)Configfile.AspectRatio.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveAspectRatio and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveAspectRatio((tvVideoSrcType_t)Configfile.videoSources.modeId[0],-1,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDisplayMode_t)Configfile.AspectRatio.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveAspectRatio and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveAspectRatio((tvVideoSrcType_t)Configfile.videoSources.modeId[0],PQ_MODE_MAX,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDisplayMode_t)Configfile.AspectRatio.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveAspectRatio and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveAspectRatio((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],VIDEO_FORMAT_MAX,(tvDisplayMode_t)Configfile.AspectRatio.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveAspectRatio and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveAspectRatio((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)-1,(tvDisplayMode_t)Configfile.AspectRatio.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveAspectRatio and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveAspectRatio((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDisplayMode_t)-1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveAspectRatio and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveAspectRatio((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],tvDisplayMode_MAX);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveAspectRatio and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfSources = sizeof(Configfile.videoSources.modeId)/sizeof(Configfile.videoSources.modeId[0]);
	for(int i =VIDEO_SOURCE_ALL ; i < VIDEO_SOURCE_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfSources; j++)
		{
			if(Configfile.videoSources.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveAspectRatio((tvVideoSrcType_t)i,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDisplayMode_t)Configfile.AspectRatio.modeId[0]);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveAspectRatio and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfPqmodes = sizeof(Configfile.pic_modes.modeId)/sizeof(Configfile.pic_modes.modeId[0]);
	for(int i =0 ; i < PQ_MODE_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfPqmodes; j++)
		{
			if(Configfile.pic_modes.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveAspectRatio((tvVideoSrcType_t)Configfile.videoSources.modeId[0],i,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDisplayMode_t)Configfile.AspectRatio.modeId[0]);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveAspectRatio and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfFormats = sizeof(Configfile.videoformat.modeId)/sizeof(Configfile.videoformat.modeId[0]);
	for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfFormats; j++)
		{
			if(Configfile.videoformat.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveAspectRatio((tvVideoSrcType_t) Configfile.videoSources.modeId[i],Configfile.pic_modes.modeId[i],(tvVideoFormatType_t)i,(tvDisplayMode_t)Configfile.AspectRatio.modeId[0]);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveAspectRatio and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfAspectRatios = sizeof(Configfile.AspectRatio.modeId)/sizeof(Configfile.AspectRatio.modeId[0]);
	for(int i =tvDisplayMode_4x3 ; i < tvDisplayMode_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfAspectRatios; j++)
		{
			if(Configfile.AspectRatio.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveAspectRatio((tvVideoSrcType_t) Configfile.videoSources.modeId[i],Configfile.pic_modes.modeId[i],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDisplayMode_t)i);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveAspectRatio and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveAspectRatio((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDisplayMode_t)Configfile.AspectRatio.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);

}

/**
 * @brief Validate SetLowLatencyState() for all positive invocation scenarios
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
 * | 02 | call SetLowLatencyState() -  Set the LowLatency State with valid value | 0 | tvERROR_NONE | Should Pass |
 * | 03 | call SetLowLatencyState() -  Reset the LowLatency State with another valid value | 1 | tvERROR_NONE | Should Pass |
 * | 04 | call SetLowLatencyState() -  Reset the LowLatency State with another valid value | 0 | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetLowLatencyState (void)
{
	gTestID = 95;                                    /* It must be 95 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetLowLatencyState with value 0 and expecting the API to return success */
	result = SetLowLatencyState(0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetLowLatencyState with value 1 and expecting the API to return success */
	result = SetLowLatencyState(1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetLowLatencyState with value 0 and expecting the API to return success */
	result = SetLowLatencyState(0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 01 | call SetLowLatencyState() - Set the TV LowLatency State even before TvInit() | 0 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetLowLatencyState() -   Set the TV LowLatency State with invalid input with less than lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetLowLatencyState() -   Set the TV LowLatency State with invalid input with max range | 2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call SetLowLatencyState() -  Set the TV LowLatency State with valid input after TvTerm() | 1 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetLowLatencyState (void)
{
	gTestID = 96;                                    /* It must be 96 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings SetLowLatencyState and expecting the API to return tvERROR_INVALID_STATE */
	result = SetLowLatencyState(0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetLowLatencyState with value -1 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetLowLatencyState(-1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetLowLatencyState with value 101 and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetLowLatencyState(2);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings the SetLowLatencyState and expecting the API to return tvERROR_INVALID_STATE */
	result = SetLowLatencyState(1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);
	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetLowLatencyState() for all positive invocation scenarios
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
 * | 02 | call GetLowLatencyState() -  Retrieve the current LowLatency State with valid arguments and validate LowLatency State by looping through the test specific config file | int * | tvERROR_NONE | Should Pass |
 * | 03 | call GetLowLatencyState() -  Retrieve the current LowLatency State with valid argument and validate with above value | int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetLowLatencyState (void)
{
	gTestID = 97;                                    /* It must be 97 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	int lowLatencyState = 0;
	int latencyStateRetry = 0;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetLowLatencyState and expeting the API to return success */
	result = GetLowLatencyState(&lowLatencyState);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_TRUE( lowLatencyState == 1 || lowLatencyState == 0);

	/* Calling tvsettings GetLowLatencyState and expeting the API to return success */
	result = GetLowLatencyState(&latencyStateRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL_FATAL(lowLatencyState,latencyStateRetry);

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 01 | call GetLowLatencyState() -  Retrieve current TV LowLatency State even before TvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetLowLatencyState() -   Retrieve current TV LowLatency State with invalid argument | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetLowLatencyState() -  Retrieve current TV LowLatency State valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetLowLatencyState (void)
{
	gTestID = 98;                                    /* It must be 98 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int lowLatencyState = -1;

	/* Calling tvsettings GetLowLatencyState and expecting the API to return tvERROR_INVALID_STATE */
	result = GetLowLatencyState(&lowLatencyState);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetLowLatencyState with invalid input and expecting the API to return tvERROR_INVALID_PARAM*/
	result = GetLowLatencyState(NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetLowLatencyState and expecting the API to return tvERROR_INVALID_STATE */
	result = GetLowLatencyState(&lowLatencyState);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveLowLatencyState() for all positive invocation scenarios
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
 * | 02 | call SaveLowLatencyState() -  Save the current LowLatency State by looping through all the values of sourceId, pqmode, videoFormatType, value from the test specific config file  |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,int | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveLowLatencyState (void)
{
	gTestID = 99;                                    /* It must be 99 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveLowLatencyState for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
	for (size_t i = 0; i < sizeof(Configfile.videoSources.modeId) / sizeof(Configfile.videoSources.modeId[0]); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.pic_modes.modeName) / sizeof(Configfile.pic_modes.modeName[0]); j++)
		{
			for (size_t k = 0; k < sizeof(Configfile.videoformat.modeId) / sizeof(Configfile.videoformat.modeId[0]); k++)
			{
				result = SaveLowLatencyState((tvVideoSrcType_t) Configfile.videoSources.modeId[i],Configfile.pic_modes.modeId[j],(tvVideoFormatType_t) Configfile.videoformat.modeId[k],0);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 11 | call SaveLowLatencyState() -  Save current LowLatency State with valid value of source input, pqmode, videoFormatType but not supported by the platform by looping through the test specific config file| tvVideoSrcType_t, int , tvVideoFormatType_t ,int | tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 13 | call SaveLowLatencyState() -  save current TV Contrast valid arguments | tvVideoSrcType_t, int , tvVideoFormatType_t ,int | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveLowLatencyState (void)
{
	gTestID = 100;                                    /* It must be 100 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int numberOfSources;
	int numberOfPqmodes;
	int numberOfFormats;
	bool SupportAvailable;

	/* Calling tvsettings SaveLowLatencyState and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveLowLatencyState((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveLowLatencyState and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveLowLatencyState(VIDEO_SOURCE_MAX,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveLowLatencyState and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveLowLatencyState((tvVideoSrcType_t)-2,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveLowLatencyState and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveLowLatencyState((tvVideoSrcType_t)Configfile.videoSources.modeId[0],-1,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveLowLatencyState and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveLowLatencyState((tvVideoSrcType_t)Configfile.videoSources.modeId[0],PQ_MODE_MAX,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveLowLatencyState and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveLowLatencyState((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],VIDEO_FORMAT_MAX,0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveLowLatencyState and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveLowLatencyState((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)-1,0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveLowLatencyState and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveLowLatencyState((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],-1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveLowLatencyState and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveLowLatencyState((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],2);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveLowLatencyState and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfSources = sizeof(Configfile.videoSources.modeId)/sizeof(Configfile.videoSources.modeId[0]);
	for(int i =VIDEO_SOURCE_ALL ; i < VIDEO_SOURCE_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfSources; j++)
		{
			if(Configfile.videoSources.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveLowLatencyState((tvVideoSrcType_t)i,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],0);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveLowLatencyState and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfPqmodes = sizeof(Configfile.pic_modes.modeId)/sizeof(Configfile.pic_modes.modeId[0]);
	for(int i =0 ; i < PQ_MODE_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfPqmodes; j++)
		{
			if(Configfile.pic_modes.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveLowLatencyState((tvVideoSrcType_t)Configfile.videoSources.modeId[0],i,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],0);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveLowLatencyState and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfFormats = sizeof(Configfile.videoformat.modeId)/sizeof(Configfile.videoformat.modeId[0]);
	for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfFormats; j++)
		{
			if(Configfile.videoformat.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){
			result = SaveLowLatencyState((tvVideoSrcType_t) Configfile.videoSources.modeId[i],Configfile.pic_modes.modeId[i],(tvVideoFormatType_t)i,0);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveLowLatencyState and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveLowLatencyState((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetDynamicContrast() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 101@n
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
	gTestID = 101;                                    /* It must be 101 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetDynamicContrast with valid value "enabled" and expecting the API to return success */
	result = SetDynamicContrast("enabled");
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	/* Calling tvsettings SetDynamicContrast with valid value "disabled" and expecting the API to return success */
	result = SetDynamicContrast("disabled");
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetDynamicContrast with valid value "enabled" and expecting the API to return success */
	result = SetDynamicContrast("enabled");
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 01 | call SetDynamicContrast() - Set the TV Dynamic Contrast even before TvInit() | true | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetDynamicContrast() -  Set the TV Dynamic Contrast with invalid input | "ENABLE" | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call SetDynamicContrast() -  Set the TV Dynamic Contrast with valid input after TvTerm() | false | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetDynamicContrast (void)
{
	gTestID = 102;                                    /* It must be 102 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings SetDynamicContrast with valid value "enabled" and expecting the API to return success */
	result = SetDynamicContrast("enabled");
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetDynamicContrast with valid value "ENABLE" and expecting the API to return success */
	result = SetDynamicContrast("ENABLE");
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetDynamicContrast with valid value "enabled" and expecting the API to return success */
	result = SetDynamicContrast("enabled");
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetDynamicContrast() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 103@n
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
	gTestID = 103;                                    /* It must be 103 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	char dynamicContrast[OFFSET_MAX]={'\0'};
	char dynamicContrastRetry[OFFSET_MAX]={'\0'};

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetDynamicContrast and expeting the API to return success */
	result = GetDynamicContrast(dynamicContrast);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_TRUE_FATAL(!strcmp(dynamicContrast, "enabled") || !strcmp(dynamicContrast, "disabled"));

	/* Calling tvsettings GetDynamicContrast and expeting the API to return success */
	result = GetDynamicContrast(dynamicContrastRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_STRING_EQUAL_FATAL(dynamicContrastRetry, dynamicContrast);

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 01 | call GetDynamicContrast() -  Retrieve current TV Dynamic Contrast even before TvInit() | char * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetDynamicContrast() -  Retrieve current TV Dynamic contrast with invalid argument | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetDynamicContrast() -  Retrieve current TV Dynamic Contrast valid arguments | char * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetDynamicContrast (void)
{
	gTestID = 104;                                    /* It must be 104 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	char dynamicContrast[OFFSET_MAX]={'\0'};

	/* Calling tvsettings GetDynamicContrast and expeting the API to return success */
	result = GetDynamicContrast(dynamicContrast);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetDynamicContrast and expeting the API to return success */
	result = GetDynamicContrast(NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings GetDynamicContrast and expeting the API to return success */
	result = GetDynamicContrast(dynamicContrast);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);

}

/**
 * @brief Validate SetDynamicGamma() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 105@n
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
	gTestID = 105;                                    /* It must be 105 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetDynamicGamma with valid value "1.80" and expecting the API to return success */
	result = SetDynamicGamma(1.80);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);	

	/* Calling tvsettings SetDynamicGamma with valid value "2.20" and expecting the API to return success */
	result = SetDynamicGamma(2.20);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetDynamicGamma with valid value "2.60" and expecting the API to return success */
	result = SetDynamicGamma(2.60);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 01 | call SetDynamicGamma() - Set the TV Dynamic Gamma even before TvInit() | 2.20 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetDynamicGamma() -  Set the TV Dynamic Gamma with less than the lower range | 1.79 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetDynamicGamma() -  Set the TV Dynamic Gamma with max range | 2.61 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call SetDynamicGamma() -  Set the TV Dynamic Gamma with valid input after TvTerm() | 2.20 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetDynamicGamma (void)
{
	gTestID = 105;                                    /* It must be 105 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings SetDynamicGamma with valid value "2.20" and expecting the API to return success */
	result = SetDynamicGamma(2.20);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetDynamicGamma with valid value "1.79" and expecting the API to return success */
	result = SetDynamicGamma(1.79);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = SetDynamicGamma(2.61);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetDynamicGamma with valid value "2.20" and expecting the API to return success */
	result = SetDynamicGamma(2.20);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetDynamicGamma() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 107@n
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
 * | 02 | call GetDynamicGamma() -  Retrieve the current Dynamic Gamma with valid arguments and validate range matching with the test specific config file | double * | tvERROR_NONE | Should Pass |
 * | 03 | call GetDynamicGamma() -  Retrieve the current Dynamic Gamma with valid arguments and validate with above value | double * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetDynamicGamma (void)
{
	gTestID = 107;                                    /* It must be 107 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	double dynamicGamma=0.0;
	double dynamicGammaRetry=0.0;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetDynamicGamma and expeting the API to return success */
	result = GetDynamicGamma(&dynamicGamma);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_TRUE_FATAL( 1.80 <= dynamicGamma && dynamicGamma <= 2.60);

	/* Calling tvsettings GetDynamicGamma and expeting the API to return success */
	result = GetDynamicGamma(&dynamicGammaRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL_FATAL(dynamicGammaRetry, dynamicGamma);

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 01 | call GetDynamicGamma() -  Retrieve current TV Dynamic Gamma even before TvInit() | double * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetDynamicGamma() -  Retrieve current TV Dynamic Gamma with invalid argument | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetDynamicGamma() -  Retrieve current TV Dynamic Gamma valid arguments | double * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetDynamicGamma (void)
{
	gTestID = 108;                                    /* It must be 108 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	double dynamicGamma=0.0;

	/* Calling tvsettings GetDynamicGamma and expeting the API to return success */
	result = GetDynamicGamma(&dynamicGamma);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetDynamicGamma and expeting the API to return success */
	result = GetDynamicGamma(NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings GetDynamicGamma and expeting the API to return success */
	result = GetDynamicGamma(&dynamicGamma);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVSupportedDolbyVisionModes() for all positive invocation scenarios
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
 * | 02 | call GetTVSupportedDolbyVisionModes() -  Retrieve the current Supported DolbyVision Modes and validate Supported DolbyVision modes by looping through the test specific config file | tvDolbyMode_t *[], unsigned short * | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVSupportedDolbyVisionModes() -  Retrieve the current Supported VideoFormats with valid argument and validate with above value | tvDolbyMode_t *[], unsigned short * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetTVSupportedDolbyVisionModes (void)
{
	gTestID = 109;                                    /* It must be 109 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	tvDolbyMode_t *tvDolbyModes[MAX_DV_MODES];
	tvDolbyMode_t *tvDolbyModesRetry[MAX_DV_MODES];
	bool IsDolbyModeValid;
	unsigned short sizeReceived;
	unsigned short sizeReceivedRetry;
	size_t sizeFromConfig;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVSupportedDolbyVisionModes and expeting the API to return success */
	result = GetTVSupportedDolbyVisionModes(tvDolbyModes, &sizeReceived);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	sizeFromConfig = sizeof(Configfile.dv_modes.modeId) / sizeof(Configfile.dv_modes.modeId[0]);

	for (size_t i = 0; i < sizeFromConfig; i++)
	{
		IsDolbyModeValid = false;
		for(unsigned short j = 0; j < sizeReceived; j++)
		{
			if ((tvDolbyMode_t)Configfile.dv_modes.modeId[i] == *tvDolbyModes[j])
			{
				IsDolbyModeValid = true;
				break;
			}
		}
		UT_ASSERT_FALSE_FATAL(IsDolbyModeValid);
	}

	/* Calling tvsettings GetTVSupportedDolbyVisionModes and expeting the API to return success */
	result = GetTVSupportedDolbyVisionModes(tvDolbyModesRetry, &sizeReceivedRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	for (unsigned short i = 0; i < sizeReceivedRetry; i++)
	{
		IsDolbyModeValid = false;
		for(unsigned short j = 0; j < sizeReceived; j++)
		{
			if (*tvDolbyModesRetry[i] == *tvDolbyModes[j])
			{
				IsDolbyModeValid = true;
				break;
			}
		}
		UT_ASSERT_FALSE_FATAL(IsDolbyModeValid);
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVSupportedDolbyVisionModes() for all negative invocation scenarios
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
 * | 01 | call GetTVSupportedDolbyVisionModes() -  Retrieve current TV Supported DolbyVision Modes even before TvInit() | tvDolbyMode_t *[], unsigned short * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVSupportedDolbyVisionModes() -   Retrieve current TV Supported DolbyVision Modes with invalid argument | tvDolbyMode_t *[], NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetTVSupportedDolbyVisionModes() -   Retrieve current TV Supported DolbyVision Modes with invalid argument | NULL, unsigned short * | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call GetTVSupportedDolbyVisionModes() -  Retrieve current TV Supported DolbyVision Modes valid arguments |tvDolbyMode_t *[], unsigned short * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetTVSupportedDolbyVisionModes (void)
{
	UT_FAIL("This function needs to be implemented!"); 
	gTestID = 14;                                    /* It must be 14 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	tvDolbyMode_t *tvDolbyModes[MAX_VIDEO_FORMAT];
	unsigned short size;

	/* Calling tvsettings GetTVSupportedDolbyVisionModes and expecting the API to return tvERROR_INVALID_STATE */
	result = GetTVSupportedDolbyVisionModes(tvDolbyModes, &size);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVSupportedDolbyVisionModes and expecting the API to return tvERROR_INVALID_PARAM */
	result = GetTVSupportedDolbyVisionModes(tvDolbyModes, NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings GetTVSupportedDolbyVisionModes and expecting the API to return tvERROR_INVALID_PARAM */
	result = GetTVSupportedDolbyVisionModes(NULL,&size);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVSupportedDolbyVisionModes and expecting the API to return tvERROR_INVALID_STATE */
	result = GetTVSupportedDolbyVisionModes(tvDolbyModes,&size);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetTVDolbyVisionMode() for all positive invocation scenarios
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
 * | 02 | call SetTVDolbyVisionMode() -  Set the TV DolbyVision mode by looping through all the values of DolbyVision modes from the test specific config file | tvDolbyMode_t | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetTVDolbyVisionMode (void)
{
	gTestID = 111;                                    /* It must be 111 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the SetTVDolbyVisionMode for all the dv_modes and expecting the API to return success */
	for (size_t i = 0; i < sizeof(Configfile.dv_modes.modeId) / sizeof(Configfile.dv_modes.modeId[0]); i++)
	{
		result = SetTVDolbyVisionMode((tvDolbyMode_t)Configfile.dv_modes.modeId[i]);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	}

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 01 | call SetTVDolbyVisionMode() - Set the TV DolbyVision Mode even before TvInit() | tvDolbyMode_t | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetTVDolbyVisionMode() -   Set the TV DolbyVision Mode with invalid input | tvMode_Max | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetTVDolbyVisionMode() -   Set the TV DolbyVision Mode with invalid input | -2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call SetTVDolbyVisionMode() -  Set the TV DolbyVision Mode with valid input after TvTerm() | tvDolbyMode_t| tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetTVDolbyVisionMode (void)
{
	gTestID = 112;                                    /* It must be 112 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings SetTVDolbyVisionMode with valid value and expecting the API to return success */
	result = SetTVDolbyVisionMode((tvDolbyMode_t)Configfile.dv_modes.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetTVDolbyVisionMode with valid value and expecting the API to return success */
	result = SetTVDolbyVisionMode(tvMode_Max);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SetTVDolbyVisionMode with valid value and expecting the API to return success */
	result = SetTVDolbyVisionMode((tvDolbyMode_t)-2);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetTVDolbyVisionMode with valid value and expecting the API to return success */
	result = SetTVDolbyVisionMode((tvDolbyMode_t)Configfile.dv_modes.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVDolbyVisionMode() for all positive invocation scenarios
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
 * | 02 | call GetTVDolbyVisionMode() -  Retrieve the current DolbyVision and validate DolbyVision by looping through the test specific config file | tvDolbyMode_t * | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call GetTVDolbyVisionMode() -  Retrieve the current DolbyVision with valid argument and validate with above value | tvDolbyMode_t * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetTVDolbyVisionMode (void)
{
	gTestID = 113;                                    /* It must be 43 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	tvDolbyMode_t tvDolbyModes;
	tvDolbyMode_t tvDolbyModesRetry;
	bool IstvDolbyModesValid = false;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVDimmingMode and expeting the API to return success */
	result = GetTVDolbyVisionMode(&tvDolbyModes);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	for (size_t i = 0; i < (sizeof(Configfile.dv_modes.modeId) / sizeof(Configfile.dv_modes.modeId[0])); i++)
	{
		if (Configfile.dv_modes.modeId[i] == tvDolbyModes)
		{
			IstvDolbyModesValid = true;
			break;
		}
	}
	UT_ASSERT_FALSE(IstvDolbyModesValid);

	/* Calling tvsettings GetTVDimmingMode and expeting the API to return success */
	result = GetTVDolbyVisionMode(&tvDolbyModesRetry);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
	UT_ASSERT_STRING_EQUAL_FATAL(tvDolbyModesRetry,tvDolbyModes);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVDolbyVisionMode() for all negative invocation scenarios
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
 * | 01 | call GetTVDolbyVisionMode() -  Retrieve current TV DolbyVision Mode even before TvInit() | tvDolbyMode_t * | (tvERROR_INVALID_STATE |  tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVDolbyVisionMode() -  Retrieve current TV DolbyVision mode with invalid argument | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetTVDolbyVisionMode() -  Retrieve current TV DolbyVision Mode valid arguments | tvDolbyMode_t * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetTVDolbyVisionMode (void)
{
	gTestID = 114;                                    /* It must be 114 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	tvDolbyMode_t tvDolbyModes;

	/* Calling tvsettings GetTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_STATE */
	result = GetTVDolbyVisionMode(&tvDolbyModes);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_PARAM */
	result = GetTVDolbyVisionMode(NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_STATE */
	result = GetTVDolbyVisionMode(&tvDolbyModes);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveTVDolbyVisionMode() for all positive invocation scenarios
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
 * | 02 | call SaveTVDolbyVisionMode() -  Save the current DolbyVision Mode by looping through all the values of videosource Type, pqmode, videoFormatType, DolbyVision value from the test specific config file | tvVideoSrcType_t , int ,tvVideoFormatType_t ,tvDolbyMode_t | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveTVDolbyVisionMode (void)
{
	gTestID = 115;                                    /* It must be 45 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveTVDimmingMode for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
	for (size_t i = 0; i < sizeof(Configfile.videoSources.modeId) / sizeof(Configfile.videoSources.modeId[0]); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.pic_modes.modeId) / sizeof(Configfile.pic_modes.modeId[0]); j++)
		{
			for (size_t k = 0; k < sizeof(Configfile.videoformat.modeId) / sizeof(Configfile.videoformat.modeId[0]); k++)                
			{
				for (size_t l = 0; l < sizeof(Configfile.dv_modes.modeId) / sizeof(Configfile.dv_modes.modeId[0]); l++)
				{
					result = SaveTVDimmingMode((tvVideoSrcType_t) Configfile.videoSources.modeId[i],Configfile.pic_modes.modeId[j],(tvVideoFormatType_t) Configfile.videoformat.modeId[k],(tvDimmingMode_t)Configfile.dv_modes.modeId[l]);
					UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
				}
			}
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate SaveTVDolbyVisionMode() for all negative invocation scenarios
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
 * | 11 | call SaveTVDolbyVisionMode() -  Save current DolbyVision Mode with valid value of source input, pqmode, videoFormatType but not supported by the platform by looping through the test specific config file| tvVideoSrcType_t, int , tvVideoFormatType_t ,int | tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 13 | call SaveTVDolbyVisionMode() -  save current DolbyVision Mode valid arguments | tvVideoSrcType_t, int , tvVideoFormatType_t ,tvDolbyMode_t | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveTVDolbyVisionMode (void)
{
	gTestID = 115;                                    /* It must be 46 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int numberOfSources;
	int numberOfPqmodes;
	int numberOfFormats;
	int numberOfdv_modess;
	bool SupportAvailable;

	/* Calling tvsettings SaveTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveTVDolbyVisionMode((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDolbyMode_t)Configfile.dv_modes.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveTVDolbyVisionMode(VIDEO_SOURCE_MAX,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDolbyMode_t)Configfile.dv_modes.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveTVDolbyVisionMode((tvVideoSrcType_t)-2,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDolbyMode_t)Configfile.dv_modes.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveTVDolbyVisionMode((tvVideoSrcType_t)Configfile.videoSources.modeId[0],-1,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDolbyMode_t)Configfile.dv_modes.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveTVDolbyVisionMode((tvVideoSrcType_t)Configfile.videoSources.modeId[0],PQ_MODE_MAX,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDolbyMode_t)Configfile.dv_modes.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveTVDolbyVisionMode((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],VIDEO_FORMAT_MAX,(tvDolbyMode_t)Configfile.dv_modes.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveTVDolbyVisionMode((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)-1,(tvDolbyMode_t)Configfile.dv_modes.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveTVDolbyVisionMode((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDolbyMode_t)-1);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveTVDolbyVisionMode((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0], (tvDolbyMode_t)tvMode_Max);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfSources = sizeof(Configfile.videoSources.modeId)/sizeof(Configfile.videoSources.modeId[0]);
	for( int i = VIDEO_SOURCE_ALL  ; i < VIDEO_SOURCE_MAX ; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfSources; j++)
		{
			if(Configfile.videoSources.modeId[j] == i)
			{
				SupportAvailable = true;
				break;	
			}
		}

		if(!SupportAvailable){

			result = SaveTVDolbyVisionMode((tvVideoSrcType_t)i,Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDolbyMode_t)Configfile.dv_modes.modeId[0]);
			UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfPqmodes = sizeof(Configfile.pic_modes.modeId)/sizeof(Configfile.pic_modes.modeId[0]);
	for(int i =0 ; i < PQ_MODE_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfPqmodes; j++)
		{
			if(Configfile.pic_modes.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){

			result = SaveTVDolbyVisionMode((tvVideoSrcType_t) Configfile.videoSources.modeId[0],i,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDolbyMode_t)Configfile.dv_modes.modeId[0]);
			UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
		}

	}

	numberOfFormats = sizeof(Configfile.videoformat.modeId)/sizeof(Configfile.videoformat.modeId[0]);
	for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfFormats; j++)
		{
			if(Configfile.videoformat.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){

			result = SaveTVDolbyVisionMode((tvVideoSrcType_t) Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t) i,(tvDolbyMode_t)Configfile.dv_modes.modeId[0]);
			UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfdv_modess = sizeof(Configfile.dv_modes.modeId)/sizeof(Configfile.dv_modes.modeId[0]);
	for(int i =tvDimmingMode_Fixed ; i < tvMode_Max ; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfdv_modess; j++)
		{
			if(Configfile.dv_modes.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){

			result = SaveTVDolbyVisionMode((tvVideoSrcType_t) Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDolbyMode_t) i);
			UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveTVDolbyVisionMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveTVDolbyVisionMode((tvVideoSrcType_t)Configfile.videoSources.modeId[0],Configfile.pic_modes.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],(tvDolbyMode_t)Configfile.dv_modes.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVSupportedPictureModes() for all positive invocation scenarios
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
 * | 02 | call GetTVSupportedPictureModes() -  Retrieve the current TV Supported PictureModes and validate TV Supported PictureModes by looping through the test specific config file | pic_modes_t *, unsigned short * | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVSupportedPictureModes() -  Retrieve the current TV Supported PictureModes with valid argument and validate with above value | pic_modes_t *, unsigned short * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetTVSupportedPictureModes (void)
{
	gTestID = 117;                                    /* It must be 117 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	pic_modes_t *tvPicModes[PIC_MODE_NAME_MAX];
	pic_modes_t *tvPicModesRetry[PIC_MODE_NAME_MAX];
	bool IsPictureModeValid;
	unsigned short sizeReceived;
	unsigned short sizeReceivedRetry;
	size_t sizeFromConfig;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVSupportedPictureModes and expeting the API to return success */
	result = GetTVSupportedPictureModes(tvPicModes, &sizeReceived);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	sizeFromConfig = sizeof(Configfile.pic_modes.modeId) / sizeof(Configfile.pic_modes.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(sizeReceived, (unsigned short)sizeFromConfig);

	for (size_t i = 0; i < sizeFromConfig; i++)
	{
		IsPictureModeValid = false;
		for(unsigned short j = 0; j < sizeReceived; j++)
		{
			if (Configfile.pic_modes.modeId[i] == (int)tvPicModes[j]->value)
			{
				IsPictureModeValid = true;
				break;
			}
		}
		UT_ASSERT_FALSE_FATAL(IsPictureModeValid);
	}

	/* Calling tvsettings GetTVSupportedPictureModes and expeting the API to return success */
	result = GetTVSupportedPictureModes(tvPicModesRetry, &sizeReceivedRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL_FATAL(sizeReceived, sizeReceivedRetry);
	for (unsigned short i = 0; i < sizeReceivedRetry; i++)
	{
		IsPictureModeValid = false;
		for(unsigned short j = 0; j < sizeReceived; j++)
		{
			if (tvPicModesRetry[i]->value == tvPicModes[j]->value)
			{
				IsPictureModeValid = true;
				break;
			}
		}
		UT_ASSERT_FALSE_FATAL(IsPictureModeValid);
	}

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 01 | call GetTVSupportedPictureModes() -  Retrieve current TV Supported PictureModes even before TvInit() | pic_modes_t *, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVSupportedPictureModes() -  Retrieve supported TV PictureMode with invalid argument | NULL, unsigned short * | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetTVSupportedPictureModes() -  Retrieve supported TV PictureMode with invalid argument |  pic_modes_t *, NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetTVSupportedPictureModes() -  Retrieve supported TV PictureModes modes and validate PictureMode by looping through the test specific config file values | pic_modes_t *,  unsigned short *  | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 07 | call GetTVSupportedPictureModes() -  Retrieve current TV Supported PictureModes valid arguments | pic_modes_t *, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetTVSupportedPictureModes (void)
{
	UT_FAIL("This function needs to be implemented!"); 
	gTestID = 14;                                    /* It must be 14 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	pic_modes_t *pic_modes[MAX_PICTURE_MODES];
	unsigned short size;

	/* Calling tvsettings GetTVSupportedPictureModes and expecting the API to return tvERROR_INVALID_STATE */
	result = GetTVSupportedPictureModes(pic_modes, &size);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVSupportedPictureModes and expecting the API to return tvERROR_INVALID_PARAM */
	result = GetTVSupportedPictureModes(pic_modes, NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings GetTVSupportedPictureModes and expecting the API to return tvERROR_INVALID_PARAM */
	result = GetTVSupportedPictureModes(NULL,&size);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVSupportedPictureModes and expecting the API to return tvERROR_INVALID_STATE */
	result = GetTVSupportedPictureModes(pic_modes,&size);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVPictureMode() for all positive invocation scenarios
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
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetTVPictureMode() -  Retrieve the current TVPictureMode and validate TVPictureMode by looping through the test specific config file values | char *  | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVPictureMode() -  Retrieve the current TVPictureMode with valid argument and validate with above value | char * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 *
 */
void test_l1_tvSettings_positive_GetTVPictureMode (void)
{
	gTestID = 119;                                    /* It must be 119 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	char pictureMode[PIC_MODE_NAME_MAX]={'\0'};
	char pictureModeRetry[PIC_MODE_NAME_MAX]={'\0'};
	bool IsPicturModeValid = false;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVPictureMode and expeting the API to return success */
	result = GetTVPictureMode(pictureMode);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	for (size_t i = 0; i < (sizeof(Configfile.pic_modes.modeName) / sizeof(Configfile.pic_modes.modeName[0])); i++)
	{
		if (!strcmp(Configfile.pic_modes.modeName[i], pictureMode))
		{
			IsPicturModeValid = true;
			break;
		}
	}
	UT_ASSERT_FALSE(IsPicturModeValid);

	/* Calling tvsettings GetTVPictureMode and expeting the API to return success */
	result = GetTVPictureMode(pictureModeRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_STRING_EQUAL(pictureModeRetry, pictureMode);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVPictureMode() for all negative invocation scenarios
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
	gTestID = 120;                                    /* It must be 120 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	char pictureMode[PIC_MODE_NAME_MAX]={'\0'};

	/* Calling tvsettings GetTVPictureMode and expecting the API to return tvERROR_INVALID_STATE */
	result = GetTVPictureMode(pictureMode);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVPictureMode and expecting the API to return tvERROR_INVALID_PARAM */
	result = GetTVPictureMode(NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVPictureMode and expecting the API to return tvERROR_INVALID_STATE */
	result = GetTVPictureMode(pictureMode);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetTVPictureMode() for all positive invocation scenarios
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
 * | 02 | call SetTVPictureMode() -  Set the TV PictureMode by looping through all the values of pictureModes from the test specific config file | const char * | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetTVPictureMode (void)
{
	gTestID = 121;                                    /* It must be 121 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the SetTVPictureMode for all the pic_modes and expecting the API to return success */
	for (size_t i = 0; i < sizeof(Configfile.pic_modes.modeName) / sizeof(Configfile.pic_modes.modeName[0]); i++)
	{
		result = SetTVPictureMode(Configfile.pic_modes.modeName[i]);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	}

	/* Calling tvsettings termination and expecting the API to return success */
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
 * **Test Case ID:** 122@n
 * 
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call SetTVPictureMode() - Set the TV PictureMode even before TvInit() with input as picturemode from the test specific config file | const char *  | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetTVPictureMode() -   Set the TV PictureMode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetTVPictureMode() -   Set the TV PictureMode with invalid picturemode | const char *  | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call SetTVPictureMode() -  Set the TV PictureMode with valid input after TvTerm() with input as picturemode from the test specific config file  | const char * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetTVPictureMode (void)
{
	gTestID = 122;                                    /* It must be 122 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings SetTVPictureMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SetTVPictureMode(Configfile.pic_modes.modeName[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetTVPictureMode and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetTVPictureMode(NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetTVPictureMode and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetTVPictureMode("INVALID");
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings the SetTVPictureMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SetTVPictureMode(Configfile.pic_modes.modeName[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveSourcePictureMode() for all positive invocation scenarios
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
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call SaveSourcePictureMode() -  Save the current Source PictureMode by looping through all the values of sourcetype, pqmode and video format type from the test specific config file | tvVideoSrcType_t , int ,tvVideoFormatType_t | tvERROR_NONE| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveSourcePictureMode (void)
{
	gTestID = 123;                                    /* It must be 45 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
#if 0
	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveSourcePictureMode for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
	for (size_t i = 0; i < sizeof(Configfile.videoSources.modeId) / sizeof(Configfile.videoSources.modeId[0]); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.pic_modes.modeId) / sizeof(Configfile.pic_modes.modeId[0]); j++)
		{
			for (size_t k = 0; k < sizeof(Configfile.videoformat.modeId) / sizeof(Configfile.videoformat.modeId[0]); k++)                
			{
				result = SaveSourcePictureMode((tvVideoSrcType_t) Configfile.videoSources.modeId[i],(tvVideoFormatType_t) Configfile.videoformat.modeId[k], Configfile.pic_modes.modeId[j]);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
#endif
	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveSourcePictureMode() for all negative invocation scenarios
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
 * | 09 | call SaveSourcePictureMode() -  Save current Source PictureMode with valid source input, picture_mode, videoFormatType but not supported by the platform by looping through the test specific config file| tvVideoSrcType_t , tvVideoFormatType_t, int | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 11 | call SaveSourcePictureMode() -  Save the current Source PictureMode valid arguments | tvVideoSrcType_t  ,tvVideoFormatType_t , int| tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveSourcePictureMode (void)
{
	gTestID = 115;                                    /* It must be 46 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int numberOfSources;
	int numberOfPqmodes;
	int numberOfFormats;
	bool SupportAvailable;
#if 0
	/* Calling tvsettings SaveSourcePictureMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSourcePictureMode((tvVideoSrcType_t)Configfile.videoSources.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],Configfile.pic_modes.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveSourcePictureMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSourcePictureMode(VIDEO_SOURCE_MAX,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],Configfile.pic_modes.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveSourcePictureMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSourcePictureMode((tvVideoSrcType_t)-2,(tvVideoFormatType_t)Configfile.videoformat.modeId[0],Configfile.pic_modes.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveSourcePictureMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSourcePictureMode((tvVideoSrcType_t)Configfile.videoSources.modeId[0],VIDEO_FORMAT_MAX,Configfile.pic_modes.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveSourcePictureMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSourcePictureMode((tvVideoSrcType_t)Configfile.videoSources.modeId[0],(tvVideoFormatType_t)-1,Configfile.pic_modes.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveSourcePictureMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSourcePictureMode((tvVideoSrcType_t)Configfile.videoSources.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],VIDEO_FORMAT_MAX);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveSourcePictureMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveSourcePictureMode((tvVideoSrcType_t)Configfile.videoSources.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],-1);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings SaveSourcePictureMode and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfSources = sizeof(Configfile.videoSources.modeId)/sizeof(Configfile.videoSources.modeId[0]);
	for( int i = VIDEO_SOURCE_ALL  ; i < VIDEO_SOURCE_MAX ; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfSources; j++)
		{
			if(Configfile.videoSources.modeId[j] == i)
			{
				SupportAvailable = true;
				break;	
			}
		}

		if(!SupportAvailable){

			result = SaveSourcePictureMode((tvVideoSrcType_t)i,(tvVideoFormatType_t)Configfile.videoformat.modeId[0], Configfile.pic_modes.modeId[0]);
			UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
		}
	}

	numberOfFormats = sizeof(Configfile.videoformat.modeId)/sizeof(Configfile.videoformat.modeId[0]);
	for(int i =VIDEO_FORMAT_NONE ; i < VIDEO_FORMAT_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfFormats; j++)
		{
			if(Configfile.videoformat.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){

			result = SaveSourcePictureMode((tvVideoSrcType_t) Configfile.videoSources.modeId[0], (tvVideoFormatType_t)i, Configfile.pic_modes.modeId[0]);
			UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SaveSourcePictureMode and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfPqmodes = sizeof(Configfile.pic_modes.modeId)/sizeof(Configfile.pic_modes.modeId[0]);
	for(int i =0 ; i < PQ_MODE_MAX; i++)
	{
		SupportAvailable = false;
		for(int j =0 ; j < numberOfPqmodes; j++)
		{
			if(Configfile.pic_modes.modeId[j] == i)
			{
				SupportAvailable = true;
				break;
			}
		}

		if(!SupportAvailable){

			result = SaveSourcePictureMode((tvVideoSrcType_t) Configfile.videoSources.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],i);
			UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
		}

	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
#endif
}

/**
 * @brief Validate SetColorTemp_Rgain_onSource() for all positive invocation scenarios
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
 * | 02 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 0, tvColorTempSourceOffset_t , 0| tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 2047, tvColorTempSourceOffset_t , 0| tvERROR_NONE | Should Pass |
 * | 04 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 1000, tvColorTempSourceOffset_t , 0| tvERROR_NONE | Should Pass |
 * | 05 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 0, tvColorTempSourceOffset_t , 1| tvERROR_NONE | Should Pass |
 * | 06 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 2047, tvColorTempSourceOffset_t , 1| tvERROR_NONE | Should Pass |
 * | 07 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 1000, tvColorTempSourceOffset_t , 1| tvERROR_NONE | Should Pass |
 * | 08 | call SetColorTemp_Rgain_onSource() -  Reset the ColorTemp Rgain_onSource with another valid value | tvColorTemp_t, 2047, TV_OFFSET_NEW, 0 | tvERROR_NONE | Should Pass |
 * | 09 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetColorTemp_Rgain_onSource (void)
{
	gTestID = 129;                                    /* It must be 129 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_Rgain_onSource and the API to return success */
	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.colorTempSourceOffset.modeId)/sizeof(Configfile.colorTempSourceOffset.modeId[0]); j++ )
		{
			for (size_t k = 0; k < 2; k++ )   //(0 -set 1-save)
			{
				result = SetColorTemp_Rgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[i],0,(tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[j], k);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

				result = SetColorTemp_Rgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[i],2047,(tvColorTempSourceOffset_t )Configfile.colorTempSourceOffset.modeId[j], k);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

				result = SetColorTemp_Rgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[i],1000,(tvColorTempSourceOffset_t )Configfile.colorTempSourceOffset.modeId[j], k);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate SetColorTemp_Rgain_onSource() for all negative invocation scenarios
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
 * | 01 | call SetColorTemp_Rgain_onSource() - Set the TV ColorTemp Rgain_onSource even before TvInit() | tvColorTemp_t, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource with max range of colortemp | tvColorTemp_MAX, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource with less than lower range of colortemp | -1, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource invalid rgain by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, -1, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource invalid rgain by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, 2048, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource invalid sourceId by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, 0, -2, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource invalid sourceId by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, 0, OFFSET_MAX, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource invalid saveonly flag by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 0, tvColorTempSourceOffset_t, -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource invalid saveonly flag by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 0, tvColorTempSourceOffset_t, 2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource with max range | tvColorTemp_MAX, 0, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp and sourceId with valid value but not supported by the platform by looping through the test specific config file | tvColorTemp_t, 50, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 13 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 14 | call SetColorTemp_Rgain_onSource() -  Set the TV ColorTemp Rgain_onSource with valid input after TvTerm() | tvColorTemp_t, 2047, AV_OFFSET_NEW, 1 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetColorTemp_Rgain_onSource (void)
{
	gTestID = 126;                                    /* It must be 126 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int numberofColortemp;

	/* Calling tvsettings SetColorTemp_Rgain_onSource and expecting the API to return tvERROR_INVALID_STATE */
	result = SetColorTemp_Rgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0,(tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_Rgain_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_Rgain_onSource(tvColorTemp_MAX,0,(tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_Rgain_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_Rgain_onSource((tvColorTemp_t)-1, 0,(tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	result = SetColorTemp_Rgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], -1 , (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_Rgain_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_Rgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], 2048 ,(tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_Rgain_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_Rgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], 0, (tvColorTempSourceOffset_t) MAX_OFFSET, 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_Rgain_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_Rgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0, (tvColorTempSourceOffset_t)-2, 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	result = SetColorTemp_Rgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0, (tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0], 2);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	result = SetColorTemp_Rgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0,(tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0], -1);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_Rgain_onSource and the API to return success */
	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{		
		for (size_t j = 0; j < tvColorTemp_MAX ; j++ )
		{
			if(Configfile.colorTemperature.modeId[i] != (tvColorTemp_t)j) 
			{
				result = SetColorTemp_Rgain_onSource((tvColorTemp_t)j ,0, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	for (size_t i = 0; i < (sizeof(Configfile.colorTempSourceOffset.modeId)/sizeof(Configfile.colorTempSourceOffset.modeId[0])); i++)
	{		
		for (size_t j = 0; j < tvColorTemp_MAX ; j++ )
		{
			if(Configfile.colorTempSourceOffset.modeId[i] != (tvColorTempSourceOffset_t)j) 
			{
				result = SetColorTemp_Rgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0] ,0, (tvColorTempSourceOffset_t)j, 0);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_Rgain_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_Rgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__); 

}

/**
 * @brief Validate GetColorTemp_Rgain_onSource() for all positive invocation scenarios
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
 * | 02 | call GetColorTemp_Rgain_onSource() -  Retrieve the current ColorTemp Rgain_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemp_Rgain_onSource() -  Retrieve the current ColorTemp Rgain_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the test specific config file and validate with above value | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetColorTemp_Rgain_onSource (void)
{
	gTestID = 131;                                    /* It must be 131 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	tvColorTemp_t tvColorTemp = tvColorTemp_MAX;
	tvColorTemp_t tvColorTempRetry = tvColorTemp_MAX;
	int rgain = -1;
	int rgainRetry = -1;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetColorTemp_Rgain_onSource and expeting the API to return success */
	result = GetColorTemp_Rgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],&rgain, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
	UT_ASSERT_TRUE_FATAL( rgain > 0 && rgain < 2048);

	/* Calling tvsettings GetColorTemp_Rgain_onSource and expeting the API to return success */
	result = GetColorTemp_Rgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],&rgainRetry, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL_FATAL(rgain,rgainRetry);

	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.colorTempSourceOffset.modeId)/sizeof(Configfile.colorTempSourceOffset.modeId[0]); j++ )
		{

			result = GetColorTemp_Rgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[i], &rgain, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[j] );
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			UT_ASSERT_TRUE_FATAL( rgain > 0 && rgain < 2048);

		}	
	}


	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetColorTemp_Rgain_onSource() for all negative invocation scenarios
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
 * | 01 | call GetColorTemp_Rgain_onSource() -  Retrieve current TV ColorTemp Rgain_onSource even before TvInit() | tvColorTemp_t, int *, tvColorTempSourceOffset_t  | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource with max range color temp| tvColorTemp_MAX, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource with less range color temp |  -1, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource invalid Rgain by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, NULL, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource invalid SourceId by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, int *, -2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource invalid SourceId by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, int *, OFFSET_MAX | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call GetColorTemp_Rgain_onSource() -   Retrieve the Rgain_onSource for a valid value of TV ColorTemp and SourceId but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 10 | call GetColorTemp_Rgain_onSource() -  Retrieve current TV ColorTemp Rgain_onSource valid arguments | tvColorTemp_t, int *, int  | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetColorTemp_Rgain_onSource (void)
{
	gTestID = 132;                                    /* It must be 132 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvColorTemp_t tvColorTemp = tvColorTemp_MAX;
	tvError_t result = tvERROR_NONE;
	int rgain = -1;
	int sourceOffset = -1;
	int numberofColortemp;
	int numberofSourceOffset;

	/* Calling tvsettings GetColorTemp_Rgain_onSource and expeting the API to return tvERROR_INVALID_STATE */
	result = GetColorTemp_Rgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],&rgain, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetColorTemp_Rgain_onSource and expeting the API to return tvERROR_INVALID_PARAM */
	result = GetColorTemp_Rgain_onSource(tvColorTemp_MAX,&rgain, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings GetColorTemp_Rgain_onSource and expeting the API to return tvERROR_INVALID_PARAM */
	result = GetColorTemp_Rgain_onSource((tvColorTemp_t)-1,&rgain, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	result = GetColorTemp_Rgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], NULL, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	result = GetColorTemp_Rgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], &rgain, (tvColorTempSourceOffset_t) MAX_OFFSET);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);


	result = GetColorTemp_Rgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], &rgain, (tvColorTempSourceOffset_t)-2);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{		
		for (size_t j = 0; j < tvColorTemp_MAX ; j++ )
		{
			if(Configfile.colorTemperature.modeId[i] != (tvColorTemp_t)j) 
			{
				result = GetColorTemp_Rgain_onSource((tvColorTemp_t)j ,&rgain, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0] );
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	for (size_t i = 0; i < (sizeof(Configfile.colorTempSourceOffset.modeId)/sizeof(Configfile.colorTempSourceOffset.modeId[0])); i++)
	{		
		for (size_t j = 0; j < tvColorTemp_MAX ; j++ )
		{
			if(Configfile.colorTempSourceOffset.modeId[i] != (tvColorTempSourceOffset_t)j) 
			{
				result = GetColorTemp_Rgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0] ,&rgain, (tvColorTempSourceOffset_t)j);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings GetColorTemp_Rgain_onSource and expeting the API to return tvERROR_INVALID_STATE */
	result = GetColorTemp_Rgain_onSource(tvColorTemp,&rgain, (tvColorTempSourceOffset_t)sourceOffset);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate SetColorTemp_Ggain_onSource() for all positive invocation scenarios
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
 * | 02 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 0, tvColorTempSourceOffset_t , 0| tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 2047, tvColorTempSourceOffset_t , 0| tvERROR_NONE | Should Pass |
 * | 04 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 1000, tvColorTempSourceOffset_t , 0| tvERROR_NONE | Should Pass |
 * | 05 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 0, tvColorTempSourceOffset_t , 1| tvERROR_NONE | Should Pass |
 * | 06 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 2047, tvColorTempSourceOffset_t , 1| tvERROR_NONE | Should Pass |
 * | 07 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 1000, tvColorTempSourceOffset_t , 1| tvERROR_NONE | Should Pass |
 * | 08 | call SetColorTemp_Ggain_onSource() -  Reset the ColorTemp Ggain_onSource with another valid value | tvColorTemp_t, 2047, tvColorTempSourceOffset_t, 0 | tvERROR_NONE | Should Pass |
 * | 09 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetColorTemp_Ggain_onSource (void)
{
	gTestID = 129;                                    /* It must be 129 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_Ggain_onSource and the API to return success */
	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.colorTempSourceOffset.modeId)/sizeof(Configfile.colorTempSourceOffset.modeId[0]); j++ )
		{
			for (size_t k = 0; k < 2; k++ )   //(0 -set 1-save)
			{
				result = SetColorTemp_Ggain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[i],0, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[j], k);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

				result = SetColorTemp_Ggain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[i],2047,(tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[j], k);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

				result = SetColorTemp_Ggain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[i],1000,(tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[j], k);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate SetColorTemp_Ggain_onSource() for all negative invocation scenarios
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
 * | 01 | call SetColorTemp_Ggain_onSource() - Set the TV ColorTemp Ggain_onSource even before TvInit() | tvColorTemp_t, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource with max range of colortemp | tvColorTemp_MAX, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource with less than lower range of colortemp | -1, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource invalid rgain by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, -1, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource invalid rgain by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, 2048, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource invalid sourceId by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, 0, -2, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource invalid sourceId by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, 0, MAX_OFFSET, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource invalid saveonly flag by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 0, tvColorTempSourceOffset_t, -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource invalid saveonly flag by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 0, tvColorTempSourceOffset_t, 2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource with max range | tvColorTemp_MAX, 0, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp and sourceId with valid value but not supported by the platform by looping through the test specific config file | tvColorTemp_t, 50, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 13 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 14 | call SetColorTemp_Ggain_onSource() -  Set the TV ColorTemp Ggain_onSource with valid input after TvTerm() | tvColorTemp_t, 2047, tvColorTempSourceOffset_t, 1 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetColorTemp_Ggain_onSource (void)
{
	gTestID = 130;                                    /* It must be 130 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int numberofColortemp;

	/* Calling tvsettings SetColorTemp_Ggain_onSource and expecting the API to return tvERROR_INVALID_STATE */
	result = SetColorTemp_Ggain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_Ggain_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_Ggain_onSource(tvColorTemp_MAX,0, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_Ggain_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_Ggain_onSource((tvColorTemp_t)-1, 0, (tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	result = SetColorTemp_Ggain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], -1 ,(tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_Ggain_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_Ggain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], 2048 ,(tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_Ggain_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_Ggain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0, (tvColorTempSourceOffset_t) MAX_OFFSET, 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_Ggain_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_Ggain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], 0, (tvColorTempSourceOffset_t) -2, 0);

	result = SetColorTemp_Ggain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0,(tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 2);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	result = SetColorTemp_Ggain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0,(tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], -1);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_Ggain_onSource and the API to return success */
	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{		
		for (size_t j = 0; j < tvColorTemp_MAX ; j++ )
		{
			if(Configfile.colorTemperature.modeId[i] != (tvColorTemp_t)j) 
			{
				result = SetColorTemp_Ggain_onSource((tvColorTemp_t)j ,0,(tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	for (size_t i = 0; i < (sizeof(Configfile.colorTempSourceOffset.modeId)/sizeof(Configfile.colorTempSourceOffset.modeId[0])); i++)
	{		
		for (size_t j = 0; j < tvColorTemp_MAX ; j++ )
		{
			if(Configfile.colorTempSourceOffset.modeId[i] != (tvColorTempSourceOffset_t)j) 
			{
				result = SetColorTemp_Ggain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0] ,0, (tvColorTempSourceOffset_t)j, 0);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_Ggain_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_Ggain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0,(tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate GetColorTemp_Ggain_onSource() for all positive invocation scenarios
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
 * | 02 | call GetColorTemp_Ggain_onSource() -  Retrieve the current ColorTemp Ggain_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemp_Ggain_onSource() -  Retrieve the current ColorTemp Ggain_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the test specific config file and validate with above value | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetColorTemp_Ggain_onSource (void)
{
	gTestID = 131;                                    /* It must be 131 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	tvColorTemp_t tvColorTemp = tvColorTemp_MAX;
	tvColorTemp_t tvColorTempRetry = tvColorTemp_MAX;
	int rgain = -1;
	int rgainRetry = -1;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetColorTemp_Ggain_onSource and expeting the API to return success */
	result = GetColorTemp_Ggain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],&rgain, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
	UT_ASSERT_TRUE_FATAL( rgain > 0 && rgain < 2048);

	/* Calling tvsettings GetColorTemp_Ggain_onSource and expeting the API to return success */
	result = GetColorTemp_Ggain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],&rgainRetry, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL_FATAL(rgain,rgainRetry);

	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.colorTempSourceOffset.modeId)/sizeof(Configfile.colorTempSourceOffset.modeId[0]); j++ )
		{

			result = GetColorTemp_Ggain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[i], &rgain, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[j]);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			UT_ASSERT_TRUE_FATAL( rgain > 0 && rgain < 2048);

		}	
	}


	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetColorTemp_Ggain_onSource() for all negative invocation scenarios
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
 * | 01 | call GetColorTemp_Ggain_onSource() -  Retrieve current TV ColorTemp Ggain_onSource even before TvInit() | tvColorTemp_t, int *, tvColorTempSourceOffset_t  | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource with max range color temp| tvColorTemp_MAX, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource with less range color temp |  -1, int *, int | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource invalid Rgain by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, NULL, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource invalid SourceId by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, int *, -2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource invalid SourceId by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, int *, OFFSET_MAX | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call GetColorTemp_Ggain_onSource() -   Retrieve the Ggain_onSource for a valid value of TV ColorTemp and SourceId but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 10 | call GetColorTemp_Ggain_onSource() -  Retrieve current TV ColorTemp Ggain_onSource valid arguments | tvColorTemp_t, int *, tvColorTempSourceOffset_t  | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetColorTemp_Ggain_onSource (void)
{
	gTestID = 132;                                    /* It must be 132 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvColorTemp_t tvColorTemp = tvColorTemp_MAX;
	tvError_t result = tvERROR_NONE;
	int rgain = -1;
	int sourceOffset = -1;
	int numberofColortemp;
	int numberofSourceOffset;

	/* Calling tvsettings GetColorTemp_Ggain_onSource and expeting the API to return tvERROR_INVALID_STATE */
	result = GetColorTemp_Ggain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],&rgain, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetColorTemp_Ggain_onSource and expeting the API to return tvERROR_INVALID_PARAM */
	result = GetColorTemp_Ggain_onSource(tvColorTemp_MAX,&rgain, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings GetColorTemp_Ggain_onSource and expeting the API to return tvERROR_INVALID_PARAM */
	result = GetColorTemp_Ggain_onSource((tvColorTemp_t)-1,&rgain, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	result = GetColorTemp_Ggain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], NULL, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	result = GetColorTemp_Ggain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], &rgain,(tvColorTempSourceOffset_t) MAX_OFFSET);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);


	result = GetColorTemp_Ggain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], &rgain,  (tvColorTempSourceOffset_t)-2);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{		
		for (size_t j = 0; j < tvColorTemp_MAX ; j++ )
		{
			if(Configfile.colorTemperature.modeId[i] != (tvColorTemp_t)j) 
			{
				result = GetColorTemp_Ggain_onSource((tvColorTemp_t)j ,&rgain, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0] );
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	for (size_t i = 0; i < (sizeof(Configfile.colorTempSourceOffset.modeId)/sizeof(Configfile.colorTempSourceOffset.modeId[0])); i++)
	{		
		for (size_t j = 0; j < tvColorTemp_MAX ; j++ )
		{
			if(Configfile.colorTempSourceOffset.modeId[i] != (tvColorTempSourceOffset_t)j) 
			{
				result = GetColorTemp_Ggain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0] ,&rgain, (tvColorTempSourceOffset_t)j);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings GetColorTemp_Ggain_onSource and expeting the API to return tvERROR_INVALID_STATE */
	result = GetColorTemp_Ggain_onSource(tvColorTemp,&rgain, (tvColorTempSourceOffset_t)sourceOffset);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate SetColorTemp_Bgain_onSource() for all positive invocation scenarios
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
 * | 02 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 0, tvColorTempSourceOffset_t , 0| tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 2047, tvColorTempSourceOffset_t , 0| tvERROR_NONE | Should Pass |
 * | 04 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 1000, tvColorTempSourceOffset_t , 0| tvERROR_NONE | Should Pass |
 * | 05 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 0, tvColorTempSourceOffset_t , 1| tvERROR_NONE | Should Pass |
 * | 06 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 2047, tvColorTempSourceOffset_t , 1| tvERROR_NONE | Should Pass |
 * | 07 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 1000, tvColorTempSourceOffset_t , 1| tvERROR_NONE | Should Pass |
 * | 08 | call SetColorTemp_Bgain_onSource() -  Reset the ColorTemp Bgain_onSource with another valid value | tvColorTemp_t, 2047, int, 0 | tvERROR_NONE | Should Pass |
 * | 09 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetColorTemp_Bgain_onSource (void)
{
	gTestID = 129;                                    /* It must be 129 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_Bgain_onSource and the API to return success */
	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.colorTempSourceOffset.modeId)/sizeof(Configfile.colorTempSourceOffset.modeId[0]); j++ )
		{
			for (size_t k = 0; k < 2; k++ )   //(0 -set 1-save)
			{
				result = SetColorTemp_Bgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[i],0, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[j], k);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

				result = SetColorTemp_Bgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[i],2047, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[j], k);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

				result = SetColorTemp_Bgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[i],1000, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[j], k);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate SetColorTemp_Bgain_onSource() for all negative invocation scenarios
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
 * | 01 | call SetColorTemp_Bgain_onSource() - Set the TV ColorTemp Bgain_onSource even before TvInit() | tvColorTemp_t, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource with max range of colortemp | tvColorTemp_MAX, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource with max range less than lower range of colortemp | -1, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource invalid rgain by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, -1, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource invalid rgain by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, 2048, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource invalid sourceId by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, 0, -2, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource invalid sourceId by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, 0, OFFSET_MAX, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource invalid saveonly flag by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 0, tvColorTempSourceOffset_t, -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource invalid saveonly flag by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 0, tvColorTempSourceOffset_t, 2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource with max range | tvColorTemp_MAX, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp and sourceId with valid value but not supported by the platform by looping through the test specific config file | tvColorTemp_t, 50, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 13 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 14 | call SetColorTemp_Bgain_onSource() -  Set the TV ColorTemp Bgain_onSource with valid input after TvTerm() | tvColorTemp_t, 2047, tvColorTempSourceOffset_t, 1 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetColorTemp_Bgain_onSource (void)
{
	gTestID = 130;                                    /* It must be 130 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int numberofColortemp;

	/* Calling tvsettings SetColorTemp_Bgain_onSource and expecting the API to return tvERROR_INVALID_STATE */
	result = SetColorTemp_Bgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_Bgain_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_Bgain_onSource(tvColorTemp_MAX,0,(tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_Bgain_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_Bgain_onSource((tvColorTemp_t)-1, 0,(tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	result = SetColorTemp_Bgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], -1 ,(tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_Bgain_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_Bgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], 2048 ,(tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_Bgain_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_Bgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0, (tvColorTempSourceOffset_t) MAX_OFFSET, 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_Bgain_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_Bgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0, (tvColorTempSourceOffset_t) -2, 0);

	result = SetColorTemp_Bgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0,(tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 2);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	result = SetColorTemp_Bgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], -1);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_Bgain_onSource and the API to return success */
	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{		
		for (size_t j = 0; j < tvColorTemp_MAX ; j++ )
		{
			if(Configfile.colorTemperature.modeId[i] != (tvColorTemp_t)j) 
			{
				result = SetColorTemp_Bgain_onSource((tvColorTemp_t)j ,0, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	for (size_t i = 0; i < (sizeof(Configfile.colorTempSourceOffset.modeId)/sizeof(Configfile.colorTempSourceOffset.modeId[0])); i++)
	{		
		for (size_t j = 0; j < tvColorTemp_MAX ; j++ )
		{
			if(Configfile.colorTempSourceOffset.modeId[i] != (tvColorTempSourceOffset_t)j) 
			{
				result = SetColorTemp_Bgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0] ,0, (tvColorTempSourceOffset_t)j, 0);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_Bgain_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_Bgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate GetColorTemp_Bgain_onSource() for all positive invocation scenarios
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
 * | 02 | call GetColorTemp_Bgain_onSource() -  Retrieve the current ColorTemp Bgain_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemp_Bgain_onSource() -  Retrieve the current ColorTemp Bgain_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the test specific config file and validate with above value | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetColorTemp_Bgain_onSource (void)
{
	gTestID = 131;                                    /* It must be 131 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	tvColorTemp_t tvColorTemp = tvColorTemp_MAX;
	tvColorTemp_t tvColorTempRetry = tvColorTemp_MAX;
	int rgain = -1;
	int rgainRetry = -1;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetColorTemp_Bgain_onSource and expeting the API to return success */
	result = GetColorTemp_Bgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],&rgain, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
	UT_ASSERT_TRUE_FATAL( rgain > 0 && rgain < 2048);

	/* Calling tvsettings GetColorTemp_Bgain_onSource and expeting the API to return success */
	result = GetColorTemp_Bgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],&rgainRetry, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL_FATAL(rgain,rgainRetry);

	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.colorTempSourceOffset.modeId)/sizeof(Configfile.colorTempSourceOffset.modeId[0]); j++ )
		{

			result = GetColorTemp_Bgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[i], &rgain, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[j] );
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			UT_ASSERT_TRUE_FATAL( rgain > 0 && rgain < 2048);

		}	
	}


	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetColorTemp_Bgain_onSource() for all negative invocation scenarios
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
 * | 01 | call GetColorTemp_Bgain_onSource() -  Retrieve current TV ColorTemp Bgain_onSource even before TvInit() | tvColorTemp_t, int *, tvColorTempSourceOffset_t  | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource with max range color temp| tvColorTemp_MAX, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource with less range color temp |  -1, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource invalid Rgain by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, NULL, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource invalid SourceId by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, int *, -2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource invalid SourceId by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, int *, OFFSET_MAX | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call GetColorTemp_Bgain_onSource() -   Retrieve the Bgain_onSource for a valid value of TV ColorTemp and SourceId but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 10 | call GetColorTemp_Bgain_onSource() -  Retrieve current TV ColorTemp Bgain_onSource valid arguments | tvColorTemp_t, int *, tvColorTempSourceOffset_t  | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetColorTemp_Bgain_onSource (void)
{
	gTestID = 132;                                    /* It must be 132 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvColorTemp_t tvColorTemp = tvColorTemp_MAX;
	tvError_t result = tvERROR_NONE;
	int rgain = -1;
	int sourceOffset = -1;
	int numberofColortemp;
	int numberofSourceOffset;

	/* Calling tvsettings GetColorTemp_Bgain_onSource and expeting the API to return tvERROR_INVALID_STATE */
	result = GetColorTemp_Bgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],&rgain, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetColorTemp_Bgain_onSource and expeting the API to return tvERROR_INVALID_PARAM */
	result = GetColorTemp_Bgain_onSource(tvColorTemp_MAX,&rgain,(tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings GetColorTemp_Bgain_onSource and expeting the API to return tvERROR_INVALID_PARAM */
	result = GetColorTemp_Bgain_onSource((tvColorTemp_t)-1,&rgain, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	result = GetColorTemp_Bgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], NULL, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	result = GetColorTemp_Bgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], &rgain,(tvColorTempSourceOffset_t) MAX_OFFSET);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);


	result = GetColorTemp_Bgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], &rgain, (tvColorTempSourceOffset_t)-2);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{		
		for (size_t j = 0; j < tvColorTemp_MAX ; j++ )
		{
			if(Configfile.colorTemperature.modeId[i] != (tvColorTemp_t)j) 
			{
				result = GetColorTemp_Bgain_onSource((tvColorTemp_t)j ,&rgain, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0] );
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	for (size_t i = 0; i < (sizeof(Configfile.colorTempSourceOffset.modeId)/sizeof(Configfile.colorTempSourceOffset.modeId[0])); i++)
	{		
		for (size_t j = 0; j < tvColorTemp_MAX ; j++ )
		{
			if(Configfile.colorTempSourceOffset.modeId[i] != (tvColorTempSourceOffset_t)j) 
			{
				result = GetColorTemp_Bgain_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0] ,&rgain, (tvColorTempSourceOffset_t)j);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings GetColorTemp_Bgain_onSource and expeting the API to return tvERROR_INVALID_STATE */
	result = GetColorTemp_Bgain_onSource(tvColorTemp,&rgain, (tvColorTempSourceOffset_t)sourceOffset);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate SetColorTemp_R_post_offset_onSource() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 137@n
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
 * | 02 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, -1024, tvColorTempSourceOffset_t, 0 | tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, 1023, tvColorTempSourceOffset_t, 0 | tvERROR_NONE | Should Pass |
 * | 04 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, 500, tvColorTempSourceOffset_t, 0 | tvERROR_NONE | Should Pass |
 * | 05 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, -1024, tvColorTempSourceOffset_t, 1 | tvERROR_NONE | Should Pass |
 * | 06 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, 1023, tvColorTempSourceOffset_t, 1 | tvERROR_NONE | Should Pass |
 * | 07 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, 500, tvColorTempSourceOffset_t, 1 | tvERROR_NONE | Should Pass |
 * | 08 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetColorTemp_R_post_offset_onSource (void)
{
	gTestID = 137;                                    /* It must be 129 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_R_post_offset_onSource and the API to return success */
	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.colorTempSourceOffset.modeId)/sizeof(Configfile.colorTempSourceOffset.modeId[0]); j++ )
		{
			for (size_t k = 0; k < 2; k++ )   //(0 -set 1-save)
			{
				result = SetColorTemp_R_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[i],-1024, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[j], k);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

				result = SetColorTemp_R_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[i],0, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[j], k);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

				result = SetColorTemp_R_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[i],1023, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[j], k);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__); 

}

/**
 * @brief Validate SetColorTemp_R_post_offset_onSource() for all negative invocation scenarios
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
 * **User Interaction:** None
 * 
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call SetColorTemp_R_post_offset_onSource() - Set the TV ColorTemp R_post_offset_onSource even before TvInit() | tvColorTemp_t, -1024, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource with max range | tvColorTemp_Max, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource with less than the lower range | -1, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource invalid less than the lower range of rpostoffset  with by looping through all the values of colortemp and SourceId from the test specific config file | tvColorTemp_t, -1025, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource invalid max range of rpostoffset with by looping through all the values of colortemp and SourceId from the test specific config file | tvColorTemp_t, 1025, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource invalid sourceId with by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, int, -2, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource invalid sourceId with by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, int, OFFSET_MAX, 0| tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource invalid saveonly flag with by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, int, tvColorTempSourceOffset_t, -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource invalid saveonly flag with by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, int, tvColorTempSourceOffset_t, 2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource with valid value of colortemp but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource with valid value of sourceId but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 13 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 14 | call SetColorTemp_R_post_offset_onSource() -  Set the TV ColorTemp R_post_offset_onSource with valid input after TvTerm() | tvColorTemp_t, 1024, tvColorTempSourceOffset_t, 1 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetColorTemp_R_post_offset_onSource (void)
{
	gTestID = 138;                                    /* It must be 138 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int numberofColortemp;

	/* Calling tvsettings SetColorTemp_R_post_offset_onSource and expecting the API to return tvERROR_INVALID_STATE */
	result = SetColorTemp_R_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_R_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_R_post_offset_onSource(tvColorTemp_MAX,0, (tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_R_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_R_post_offset_onSource((tvColorTemp_t)-1, 0,(tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	result = SetColorTemp_R_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], -1025 , (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_R_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_R_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], 1024 , (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_R_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_R_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0,(tvColorTempSourceOffset_t)  MAX_OFFSET, 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_R_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_R_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0,(tvColorTempSourceOffset_t) -2, 0);

	result = SetColorTemp_R_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 2);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	result = SetColorTemp_R_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], -1);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_R_post_offset_onSource and the API to return success */
	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{		
		for (size_t j = 0; j < tvColorTemp_MAX ; j++ )
		{
			if(Configfile.colorTemperature.modeId[i] != (tvColorTemp_t)j) 
			{
				result = SetColorTemp_R_post_offset_onSource((tvColorTemp_t)j ,0, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	for (size_t i = 0; i < (sizeof(Configfile.colorTempSourceOffset.modeId)/sizeof(Configfile.colorTempSourceOffset.modeId[0])); i++)
	{		
		for (size_t j = 0; j < tvColorTemp_MAX ; j++ )
		{
			if(Configfile.colorTempSourceOffset.modeId[i] != (tvColorTempSourceOffset_t)j) 
			{
				result = SetColorTemp_R_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0] ,0, (tvColorTempSourceOffset_t)j, 0);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_R_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_R_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate GetColorTemp_R_post_offset_onSource() for all positive invocation scenarios
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
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetColorTemp_R_post_offset_onSource() -  Retrieve the current ColorTemp R_post_offset_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t| tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemp_R_post_offset_onSource() -  Retrieve the current ColorTemp R_post_offset_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the test specific config file and validate with above value | tvColorTemp_t, int *, tvColorTempSourceOffset_t| tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetColorTemp_R_post_offset_onSource (void)
{
	gTestID = 139;                                    /* It must be 139 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	tvColorTemp_t tvColorTemp = tvColorTemp_MAX;
	tvColorTemp_t tvColorTempRetry = tvColorTemp_MAX;
	int rpostoffset = -1;
	int rpostoffsetRetry = -1;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetColorTemp_R_post_offset_onSource and expeting the API to return success */
	result = GetColorTemp_R_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],&rpostoffset, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
	UT_ASSERT_TRUE_FATAL( rpostoffset > 0 && rpostoffset < 2048);

	/* Calling tvsettings GetColorTemp_R_post_offset_onSource and expeting the API to return success */
	result = GetColorTemp_R_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],&rpostoffsetRetry,(tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL_FATAL(rpostoffset,rpostoffsetRetry);

	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.colorTempSourceOffset.modeId)/sizeof(Configfile.colorTempSourceOffset.modeId[0]); j++ )
		{

			result = GetColorTemp_R_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[i], &rpostoffset, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[j] );
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			UT_ASSERT_TRUE_FATAL( rpostoffset > 0 && rpostoffset < 2048);

		}	
	}


	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetColorTemp_R_post_offset_onSource() for all negative invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 140@n
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
 * | 05 | call GetColorTemp_R_post_offset_onSource() -   Retrieve current TV ColorTemp R_post_offset_onSource invalid rpostoffset  by looping through all the values of colortemp and SourceId from the test specific config file |  tvColorTemp_t, NULL, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call GetColorTemp_R_post_offset_onSource() -   Retrieve current TV ColorTemp R_post_offset_onSource invalid SourceId by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, int *, -2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call GetColorTemp_R_post_offset_onSource() -   Retrieve current TV ColorTemp R_post_offset_onSource invalid SourceId by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, int *, OFFSET_MAX | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call GetColorTemp_R_post_offset_onSource() -   Retrieve the R_post_offset_onSource for a valid value of TV ColorTemp but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call GetColorTemp_R_post_offset_onSource() -   Retrieve the R_post_offset_onSource for a valid value of SourceId but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 11 | call GetColorTemp_R_post_offset_onSource() -  Retrieve current TV ColorTemp R_post_offset_onSource valid arguments | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetColorTemp_R_post_offset_onSource (void)
{
	gTestID = 140;                                    /* It must be 140 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvColorTemp_t tvColorTemp = tvColorTemp_MAX;
	tvError_t result = tvERROR_NONE;
	int rpostoffset = -1;
	int sourceOffset = -1;
	int numberofColortemp;
	int numberofSourceOffset;

	/* Calling tvsettings GetColorTemp_R_post_offset_onSource and expeting the API to return tvERROR_INVALID_STATE */
	result = GetColorTemp_R_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],&rpostoffset, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetColorTemp_R_post_offset_onSource and expeting the API to return tvERROR_INVALID_PARAM */
	result = GetColorTemp_R_post_offset_onSource(tvColorTemp_MAX,&rpostoffset, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings GetColorTemp_R_post_offset_onSource and expeting the API to return tvERROR_INVALID_PARAM */
	result = GetColorTemp_R_post_offset_onSource((tvColorTemp_t)-1,&rpostoffset, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	result = GetColorTemp_R_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], NULL, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	result = GetColorTemp_R_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], &rpostoffset,(tvColorTempSourceOffset_t) MAX_OFFSET);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);


	result = GetColorTemp_R_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], &rpostoffset,(tvColorTempSourceOffset_t) -2);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{		
		for (size_t j = 0; j < tvColorTemp_MAX ; j++ )
		{
			if(Configfile.colorTemperature.modeId[i] != (tvColorTemp_t)j) 
			{
				result = GetColorTemp_R_post_offset_onSource((tvColorTemp_t)j ,&rpostoffset, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0] );
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	for (size_t i = 0; i < (sizeof(Configfile.colorTempSourceOffset.modeId)/sizeof(Configfile.colorTempSourceOffset.modeId[0])); i++)
	{		
		for (size_t j = 0; j < tvColorTemp_MAX ; j++ )
		{
			if(Configfile.colorTempSourceOffset.modeId[i] != (tvColorTempSourceOffset_t)j) 
			{
				result = GetColorTemp_R_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0] ,&rpostoffset, (tvColorTempSourceOffset_t)j);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings GetColorTemp_R_post_offset_onSource and expeting the API to return tvERROR_INVALID_STATE */
	result = GetColorTemp_R_post_offset_onSource(tvColorTemp,&rpostoffset, (tvColorTempSourceOffset_t)sourceOffset);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate SetColorTemp_G_post_offset_onSource() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 141@n
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
 * | 02 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, -1024, tvColorTempSourceOffset_t, 0 | tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, 1023, tvColorTempSourceOffset_t, 0 | tvERROR_NONE | Should Pass |
 * | 04 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, 500, tvColorTempSourceOffset_t, 0 | tvERROR_NONE | Should Pass |
 * | 05 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, -1024, tvColorTempSourceOffset_t, 1 | tvERROR_NONE | Should Pass |
 * | 06 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, 1023, tvColorTempSourceOffset_t, 1 | tvERROR_NONE | Should Pass |
 * | 07 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, 500, tvColorTempSourceOffset_t, 1 | tvERROR_NONE | Should Pass |
 * | 08 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetColorTemp_G_post_offset_onSource (void)
{
	gTestID = 141;                                    /* It must be 141 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_G_post_offset_onSource and the API to return success */
	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.colorTempSourceOffset.modeId)/sizeof(Configfile.colorTempSourceOffset.modeId[0]); j++ )
		{
			for (size_t k = 0; k < 2; k++ )   //(0 -set 1-save)
			{
				result = SetColorTemp_G_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[i],-1024, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[j], k);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

				result = SetColorTemp_G_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[i],0, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[j], k);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

				result = SetColorTemp_G_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[i],1023, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[j], k);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate SetColorTemp_G_post_offset_onSource() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
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
 * | 01 | call SetColorTemp_G_post_offset_onSource() - Set the TV ColorTemp G_post_offset_onSource even before TvInit() | tvColorTemp_t, -1024, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource with max range | tvColorTemp_Max, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource with less than the lower range | -1, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource invalid less than the lower range of gpostoffset with by looping through all the values of colortemp and SourceId from the test specific config file | tvColorTemp_t, -1025, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource invalid max range of gpostoffset with by looping through all the values of colortemp and SourceId from the test specific config file | tvColorTemp_t, 1025, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource invalid sourceId flag with by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, int, OFFSET_MAX, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource invalid sourceId flag with by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, int, -2, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource invalid saveonly flag with by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, int, tvColorTempSourceOffset_t, -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource invalid saveonly flag with by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, int, tvColorTempSourceOffset_t, 2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource with valid value of colortemp but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource with valid value of sourceId but not supported by the platform by looping through the test specific config file | tvColorTemp_t, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 13 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 14 | call SetColorTemp_G_post_offset_onSource() -  Set the TV ColorTemp G_post_offset_onSource with valid input after TvTerm() | tvColorTemp_t, 1024, tvColorTempSourceOffset_t, 1 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetColorTemp_G_post_offset_onSource (void)
{
	gTestID = 142;                                    /* It must be 142 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	int numberofColortemp;

	/* Calling tvsettings SetColorTemp_G_post_offset_onSource and expecting the API to return tvERROR_INVALID_STATE */
	result = SetColorTemp_G_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_G_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_G_post_offset_onSource(tvColorTemp_MAX,0, (tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_G_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_G_post_offset_onSource((tvColorTemp_t)-1, 0, (tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	result = SetColorTemp_G_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], -1025 , (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_G_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_G_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], 1024 , (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_G_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_G_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0, (tvColorTempSourceOffset_t) MAX_OFFSET, 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_G_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_G_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0, (tvColorTempSourceOffset_t) -2, 0);

	result = SetColorTemp_G_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0, (tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0], 2);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	result = SetColorTemp_G_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], -1);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_G_post_offset_onSource and the API to return success */
	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{		
		for (size_t j = 0; j < tvColorTemp_MAX ; j++ )
		{
			if(Configfile.colorTemperature.modeId[i] != (tvColorTemp_t)j) 
			{
				result = SetColorTemp_G_post_offset_onSource((tvColorTemp_t)j ,0, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	for (size_t i = 0; i < (sizeof(Configfile.colorTempSourceOffset.modeId)/sizeof(Configfile.colorTempSourceOffset.modeId[0])); i++)
	{		
		for (size_t j = 0; j < tvColorTemp_MAX ; j++ )
		{
			if(Configfile.colorTempSourceOffset.modeId[i] != (tvColorTempSourceOffset_t)j) 
			{
				result = SetColorTemp_G_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0] ,0, (tvColorTempSourceOffset_t)j, 0);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_G_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_G_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0, (tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

}

/**
 * @brief Validate GetColorTemp_G_post_offset_onSource() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 143@n
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
 * | 02 | call GetColorTemp_G_post_offset_onSource() -  Retrieve the current ColorTemp G_post_offset_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t| tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemp_G_post_offset_onSource() -  Retrieve the current ColorTemp G_post_offset_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the test specific config file and validate with above value | tvColorTemp_t, int *, tvColorTempSourceOffset_t| tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetColorTemp_G_post_offset_onSource (void)
{
	gTestID = 143;                                    /* It must be 143 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	tvColorTemp_t tvColorTemp = tvColorTemp_MAX;
	tvColorTemp_t tvColorTempRetry = tvColorTemp_MAX;
	int rpostoffset = -1;
	int rpostoffsetRetry = -1;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetColorTemp_G_post_offset_onSource and expeting the API to return success */
	result = GetColorTemp_G_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],&rpostoffset,(tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
	UT_ASSERT_TRUE_FATAL( rpostoffset > 0 && rpostoffset < 2048);

	/* Calling tvsettings GetColorTemp_G_post_offset_onSource and expeting the API to return success */
	result = GetColorTemp_G_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],&rpostoffsetRetry,(tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL_FATAL(rpostoffset,rpostoffsetRetry);

	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.colorTempSourceOffset.modeId)/sizeof(Configfile.colorTempSourceOffset.modeId[0]); j++ )
		{

			result = GetColorTemp_G_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[i], &rpostoffset, (tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[j] );
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			UT_ASSERT_TRUE_FATAL( rpostoffset > 0 && rpostoffset < 2048);

		}	
	}


	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetColorTemp_G_post_offset_onSource() for all negative invocation scenarios
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
 * | 01 | call GetColorTemp_G_post_offset_onSource() -  Retrieve current TV ColorTemp G_post_offset_onSource even before TvInit() | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemp_G_post_offset_onSource() -   Retrieve current TV ColorTemp G_post_offset_onSource with max range color temp| tvColorTemp_MAX, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetColorTemp_G_post_offset_onSource() -   Retrieve current TV ColorTemp G_post_offset_onSource with less range color temp |  -1, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetColorTemp_G_post_offset_onSource() -   Retrieve current TV ColorTemp G_post_offset_onSource invalid gpostoffset  by looping through all the values of colortemp and SourceId from the test specific config file |  tvColorTemp_t, NULL, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call GetColorTemp_G_post_offset_onSource() -   Retrieve current TV ColorTemp G_post_offset_onSource invalid SourceId by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, int *, -2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call GetColorTemp_G_post_offset_onSource() -   Retrieve current TV ColorTemp G_post_offset_onSource invalid SourceId by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, int *, OFFSET_MAX | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call GetColorTemp_G_post_offset_onSource() -   Retrieve the G_post_offset_onSource for a valid value of TV ColorTemp but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call GetColorTemp_G_post_offset_onSource() -   Retrieve the G_post_offset_onSource for a valid value of SourceId but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 11 | call GetColorTemp_G_post_offset_onSource() -  Retrieve current TV ColorTemp G_post_offset_onSource valid arguments | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetColorTemp_G_post_offset_onSource (void)
{
	gTestID = 144;                                    /* It must be 144 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvColorTemp_t tvColorTemp = tvColorTemp_MAX;
	tvError_t result = tvERROR_NONE;
	int rpostoffset = -1;
	int sourceOffset = -1;
	int numberofColortemp;
	int numberofSourceOffset;

	/* Calling tvsettings GetColorTemp_G_post_offset_onSource and expeting the API to return tvERROR_INVALID_STATE */
	result = GetColorTemp_G_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],&rpostoffset, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetColorTemp_G_post_offset_onSource and expeting the API to return tvERROR_INVALID_PARAM */
	result = GetColorTemp_G_post_offset_onSource(tvColorTemp_MAX,&rpostoffset, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings GetColorTemp_G_post_offset_onSource and expeting the API to return tvERROR_INVALID_PARAM */
	result = GetColorTemp_G_post_offset_onSource((tvColorTemp_t)-1,&rpostoffset, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	result = GetColorTemp_G_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], NULL, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	result = GetColorTemp_G_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], &rpostoffset, (tvColorTempSourceOffset_t) MAX_OFFSET);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);


	result = GetColorTemp_G_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], &rpostoffset, (tvColorTempSourceOffset_t) -2);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{		
		for (size_t j = 0; j < tvColorTemp_MAX ; j++ )
		{
			if(Configfile.colorTemperature.modeId[i] != (tvColorTemp_t)j) 
			{
				result = GetColorTemp_G_post_offset_onSource((tvColorTemp_t)j ,&rpostoffset, (tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0] );
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	for (size_t i = 0; i < (sizeof(Configfile.colorTempSourceOffset.modeId)/sizeof(Configfile.colorTempSourceOffset.modeId[0])); i++)
	{		
		for (size_t j = 0; j < tvColorTemp_MAX ; j++ )
		{
			if(Configfile.colorTempSourceOffset.modeId[i] != (tvColorTempSourceOffset_t)j) 
			{
				result = GetColorTemp_G_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0] ,&rpostoffset, (tvColorTempSourceOffset_t)j);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings GetColorTemp_G_post_offset_onSource and expeting the API to return tvERROR_INVALID_STATE */
	result = GetColorTemp_G_post_offset_onSource(tvColorTemp,&rpostoffset, (tvColorTempSourceOffset_t)sourceOffset);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate SetColorTemp_B_post_offset_onSource() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 145@n
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
 * | 02 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, -1024, tvColorTempSourceOffset_t, 0 | tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, 1023, tvColorTempSourceOffset_t, 0 | tvERROR_NONE | Should Pass |
 * | 04 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, 500, tvColorTempSourceOffset_t, 0 | tvERROR_NONE | Should Pass |
 * | 05 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, -1024, tvColorTempSourceOffset_t, 1 | tvERROR_NONE | Should Pass |
 * | 06 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, 1023, tvColorTempSourceOffset_t, 1 | tvERROR_NONE | Should Pass |
 * | 07 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, 500, tvColorTempSourceOffset_t, 1 | tvERROR_NONE | Should Pass |
 * | 08 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetColorTemp_B_post_offset_onSource (void)
{
	gTestID = 145;                                    /* It must be 145 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_B_post_offset_onSource and the API to return success */
	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.colorTempSourceOffset.modeId)/sizeof(Configfile.colorTempSourceOffset.modeId[0]); j++ )
		{
			for (size_t k = 0; k < 2; k++ )   //(0 -set 1-save)
			{
				result = SetColorTemp_B_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[i],-1024, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[j], k);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

				result = SetColorTemp_B_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[i],0, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[j], k);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

				result = SetColorTemp_B_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[i],1023, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[j], k);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate SetColorTemp_B_post_offset_onSource() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
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
 * | 01 | call SetColorTemp_B_post_offset_onSource() - Set the TV ColorTemp B_post_offset_onSource even before TvInit() | tvColorTemp_t, -1024, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource with max range | tvColorTemp_Max, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource with less than the lower range | -1, 0, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource invalid max range of bpostoffset by looping through all the values of colortemp and SourceId from the test specific config file | tvColorTemp_t, -1025, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource invalid less than the lower range of bpostoffset by looping through all the values of colortemp and SourceId from the test specific config file | tvColorTemp_t, 1025, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource invalid sourceId flag with by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, int, OFFSET_MAX, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource invalid sourceId flag with by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, int, -2, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource invalid saveonly flag by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, int, tvColorTempSourceOffset_t, -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource invalid saveonly flag by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, int, tvColorTempSourceOffset_t, 2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource with valid value of colortemp but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource with valid value of sourceId but not supported by the platform by looping through the test specific config file | tvColorTemp_t, tvColorTempSourceOffset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 13 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 14 | call SetColorTemp_B_post_offset_onSource() -  Set the TV ColorTemp B_post_offset_onSource with valid input after TvTerm() | tvColorTemp_t, 1024, tvColorTempSourceOffset_t, 1 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetColorTemp_B_post_offset_onSource (void)
{
	gTestID = 146;                                    /* It must be 146 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);


	tvError_t result = tvERROR_NONE ;

	int numberofColortemp;

	/* Calling tvsettings SetColorTemp_B_post_offset_onSource and expecting the API to return tvERROR_INVALID_STATE */
	result = SetColorTemp_B_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_B_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_B_post_offset_onSource(tvColorTemp_MAX,0,  (tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_B_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_B_post_offset_onSource((tvColorTemp_t)-1, 0,  (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	result = SetColorTemp_B_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], -1025 ,(tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_B_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_B_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], 1024 , (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_B_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_B_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0, (tvColorTempSourceOffset_t)MAX_OFFSET, 0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_B_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_B_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0, (tvColorTempSourceOffset_t) -2, 0);

	result = SetColorTemp_B_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0, (tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0], 2);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	result = SetColorTemp_B_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0,(tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0], -1);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_B_post_offset_onSource and the API to return success */
	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{		
		for (size_t j = 0; j < tvColorTemp_MAX ; j++ )
		{
			if(Configfile.colorTemperature.modeId[i] != (tvColorTemp_t)j) 
			{
				result = SetColorTemp_B_post_offset_onSource((tvColorTemp_t)j ,0, (tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0], 0);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	for (size_t i = 0; i < (sizeof(Configfile.colorTempSourceOffset.modeId)/sizeof(Configfile.colorTempSourceOffset.modeId[0])); i++)
	{		
		for (size_t j = 0; j < tvColorTemp_MAX ; j++ )
		{
			if(Configfile.colorTempSourceOffset.modeId[i] != (tvColorTempSourceOffset_t)j) 
			{
				result = SetColorTemp_B_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0] ,0, (tvColorTempSourceOffset_t)j, 0);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetColorTemp_B_post_offset_onSource and the API to return tvERROR_INVALID_PARAM */
	result = SetColorTemp_B_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],0, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0], 0);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate GetColorTemp_B_post_offset_onSource() for all positive invocation scenarios
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
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetColorTemp_B_post_offset_onSource() -  Retrieve the current ColorTemp B_post_offset_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t| tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemp_B_post_offset_onSource() -  Retrieve the current ColorTemp B_post_offset_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the test specific config file and validate with above value | tvColorTemp_t, int *, tvColorTempSourceOffset_t| tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetColorTemp_B_post_offset_onSource (void)
{
	gTestID = 147;                                    /* It must be 147 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	tvColorTemp_t tvColorTemp = tvColorTemp_MAX;
	tvColorTemp_t tvColorTempRetry = tvColorTemp_MAX;
	int rpostoffset = -1;
	int rpostoffsetRetry = -1;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetColorTemp_B_post_offset_onSource and expeting the API to return success */
	result = GetColorTemp_B_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],&rpostoffset, (tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
	UT_ASSERT_TRUE_FATAL( rpostoffset > 0 && rpostoffset < 2048);

	/* Calling tvsettings GetColorTemp_B_post_offset_onSource and expeting the API to return success */
	result = GetColorTemp_B_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],&rpostoffsetRetry,(tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL_FATAL(rpostoffset,rpostoffsetRetry);

	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.colorTempSourceOffset.modeId)/sizeof(Configfile.colorTempSourceOffset.modeId[0]); j++ )
		{

			result = GetColorTemp_B_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[i], &rpostoffset, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[j] );
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			UT_ASSERT_TRUE_FATAL( rpostoffset > 0 && rpostoffset < 2048);

		}	
	}


	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetColorTemp_B_post_offset_onSource() for all negative invocation scenarios
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
 * | 01 | call GetColorTemp_B_post_offset_onSource() -  Retrieve current TV ColorTemp B_post_offset_onSource even before TvInit() | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetColorTemp_B_post_offset_onSource() -   Retrieve current TV ColorTemp B_post_offset_onSource with max range color temp| tvColorTemp_MAX, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetColorTemp_B_post_offset_onSource() -   Retrieve current TV ColorTemp B_post_offset_onSource with less range color temp |  -1, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetColorTemp_B_post_offset_onSource() -   Retrieve current TV ColorTemp B_post_offset_onSource invalid bpostoffset  by looping through all the values of colortemp and SourceId from the test specific config file |  tvColorTemp_t, NULL, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call GetColorTemp_B_post_offset_onSource() -   Retrieve current TV ColorTemp B_post_offset_onSource invalid SourceId by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, int *, -2 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call GetColorTemp_B_post_offset_onSource() -   Retrieve current TV ColorTemp B_post_offset_onSource invalid SourceId by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, int *, OFFSET_MAX | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call GetColorTemp_B_post_offset_onSource() -   Retrieve the B_post_offset_onSource for a valid value of TV ColorTemp but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call GetColorTemp_B_post_offset_onSource() -   Retrieve the B_post_offset_onSource for a valid value of SourceId but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 11 | call GetColorTemp_B_post_offset_onSource() -  Retrieve current TV ColorTemp B_post_offset_onSource valid arguments | tvColorTemp_t, int *, tvColorTempSourceOffset_t | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetColorTemp_B_post_offset_onSource (void)
{
	gTestID = 148;                                    /* It must be 148 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvColorTemp_t tvColorTemp = tvColorTemp_MAX;
	tvError_t result = tvERROR_NONE;
	int rpostoffset = -1;
	int sourceOffset = -1;
	int numberofColortemp;
	int numberofSourceOffset;

	/* Calling tvsettings GetColorTemp_B_post_offset_onSource and expeting the API to return tvERROR_INVALID_STATE */
	result = GetColorTemp_B_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0],&rpostoffset, (tvColorTempSourceOffset_t)Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetColorTemp_B_post_offset_onSource and expeting the API to return tvERROR_INVALID_PARAM */
	result = GetColorTemp_B_post_offset_onSource(tvColorTemp_MAX,&rpostoffset, (tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings GetColorTemp_B_post_offset_onSource and expeting the API to return tvERROR_INVALID_PARAM */
	result = GetColorTemp_B_post_offset_onSource((tvColorTemp_t)-1,&rpostoffset, (tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	result = GetColorTemp_B_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], NULL, (tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0]);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	result = GetColorTemp_B_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], &rpostoffset, (tvColorTempSourceOffset_t) MAX_OFFSET);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);


	result = GetColorTemp_B_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0], &rpostoffset, (tvColorTempSourceOffset_t) -2);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{		
		for (size_t j = 0; j < tvColorTemp_MAX ; j++ )
		{
			if(Configfile.colorTemperature.modeId[i] != (tvColorTemp_t)j) 
			{
				result = GetColorTemp_B_post_offset_onSource((tvColorTemp_t)j ,&rpostoffset, (tvColorTempSourceOffset_t) Configfile.colorTempSourceOffset.modeId[0] );
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	for (size_t i = 0; i < (sizeof(Configfile.colorTempSourceOffset.modeId)/sizeof(Configfile.colorTempSourceOffset.modeId[0])); i++)
	{		
		for (size_t j = 0; j < tvColorTemp_MAX ; j++ )
		{
			if(Configfile.colorTempSourceOffset.modeId[i] != (tvColorTempSourceOffset_t)j) 
			{
				result = GetColorTemp_B_post_offset_onSource((tvColorTemp_t)Configfile.colorTemperature.modeId[0] ,&rpostoffset, (tvColorTempSourceOffset_t)j);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
			}
		}	
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings GetColorTemp_B_post_offset_onSource and expeting the API to return tvERROR_INVALID_STATE */
	result = GetColorTemp_B_post_offset_onSource(tvColorTemp,&rpostoffset, (tvColorTempSourceOffset_t)sourceOffset);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
}

/**
 * @brief Validate EnableWBCalibrationMode() for all positive invocation scenarios
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
 * | 02 | call EnableWBCalibrationMode() -  Enable the WB CalibrationMode with valid argument| true | tvERROR_NONE | Should Pass |
 * | 03 | call EnableWBCalibrationMode() -  Disable the WB CalibrationMode with valid argument| false | tvERROR_NONE | Should Pass |
 * | 04 | call EnableWBCalibrationMode() -  Enable the WB CalibrationMode with valid argument| true | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_EnableWBCalibrationMode (void)
{
	gTestID = 149;                                    /* It must be 149 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableWBCalibrationMode for value true and the API to return success */
	result = EnableWBCalibrationMode(true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableWBCalibrationMode for value true and the API to return success */
	result = EnableWBCalibrationMode(false);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableWBCalibrationMode for value true and the API to return success */
	result = EnableWBCalibrationMode(true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate EnableWBCalibrationMode() for all negative invocation scenarios
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
 * | 01 | call EnableWBCalibrationMode() - Enable WB Calibration Mode even before TvInit() | true | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 04 | call EnableWBCalibrationMode() -  Enable WB Calibration Mode with valid input after TvTerm() | false | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_EnableWBCalibrationMode (void)
{
	gTestID = 150;                                    /* It must be 150 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings to Set the EnableWBCalibrationMode for value true and the API to return success */
	result = EnableWBCalibrationMode(true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableWBCalibrationMode for value true and the API to return success */
	result = EnableWBCalibrationMode(true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate SetGammaTable() for all positive invocation scenarios
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
 * | 02 | call SetGammaTable() -  Set the TV GammaTable with valid arguments for the pData_R, pData_G, pData_B values | unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetGammaTable (void)
{
	gTestID = 151;                                    /* It must be 151 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	short unsigned pData_R_limit[] = {0, 100, 1023};
	short unsigned pData_G_limit[] = {0, 100, 1023};
	short unsigned pData_B_limit[] = {0, 100, 1023};

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetGammaTable for all the valid arguments of colortemp and expecting the API to return success */ 
	result = SetGammaTable(pData_R_limit,pData_G_limit,pData_B_limit,256);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetGammaTable() for all negative invocation scenarios
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
 * | 01 | call SetGammaTable() - Set the TV GammaTable even before TvInit() | unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetGammaTable() -   Set the TV GammaTable with invalid input | NULL, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetGammaTable() -   Set the TV GammaTable with invalid input | unsigned short *, NULL, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetGammaTable() -   Set the TV GammaTable with invalid input | unsigned short *, unsigned short *, NULL, 256| tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetGammaTable() -   Set the TV GammaTable with invalid input for few elements of the array | -1, unsigned short *, unsigned short *, 256| tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SetGammaTable() -   Set the TV GammaTable with invalid input for few elements of the array | 1023, unsigned short *, unsigned short *, 256| tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SetGammaTable() -   Set the TV GammaTable with invalid input for few elements of the array | unsigned short *, -1, unsigned short *, 256 | tvERROR_INVALID_STATE | Should Pass |
 * | 09 | call SetGammaTable() -   Set the TV GammaTable with invalid input for few elements of the array | unsigned short *, 1023, unsigned short *, 256 | tvERROR_INVALID_STATE | Should Pass |
 * | 10 | call SetGammaTable() -   Set the TV GammaTable with invalid input for few elements of the array | unsigned short *, unsigned short *, -1, 256 | tvERROR_INVALID_STATE | Should Pass |
 * | 11 | call SetGammaTable() -   Set the TV GammaTable with invalid input for few elements of the array | unsigned short *, unsigned short *, 1023, 256 | tvERROR_INVALID_STATE | Should Pass |
 * | 12 | call SetGammaTable() -   Set the TV GammaTable with invalid input | unsigned short *, unsigned short *, unsigned short *, -1| tvERROR_INVALID_PARAM | Should Pass |
 * | 13 | call SetGammaTable() -   Set the TV GammaTable with invalid input | unsigned short *, unsigned short *, unsigned short *, 257| tvERROR_INVALID_PARAM | Should Pass |
 * | 14 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 15 | call SetGammaTable() -  Set the TV GammaTable with valid input after TvTerm() | unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetGammaTable (void)
{
	gTestID = 152;                                    /* It must be 151 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	unsigned short pData_R_limit[] = {0, 100, 1023};
	unsigned short pData_G_limit[] = {0, 100, 1023};
	unsigned short pData_B_limit[] = {0, 100, 1023};

	unsigned short pData_R_limit_error[] = {1025, 100, 1023};
	unsigned short pData_G_limit_error[] = {0, 1025, 1023};
	unsigned short pData_B_limit_error[] = {0, 100, 1025};

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetGammaTable for all the valid arguments of colortemp and expecting the API to return success */ 
	result = SetGammaTable(NULL,pData_G_limit,pData_B_limit,256);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = SetGammaTable(pData_R_limit,NULL,pData_B_limit,256);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = SetGammaTable(pData_R_limit,pData_G_limit,NULL,256);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = SetGammaTable(pData_R_limit,pData_G_limit,NULL,0);  //zero size
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = SetGammaTable(pData_R_limit,pData_G_limit,NULL, 257); //MAX size
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = SetGammaTable(pData_R_limit_error,pData_G_limit,pData_B_limit,256);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = SetGammaTable(pData_R_limit,pData_G_limit_error,pData_B_limit,256);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = SetGammaTable(pData_R_limit,pData_G_limit,pData_B_limit_error,256);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);


	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetDefaultGammaTable() for all positive invocation scenarios
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
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetDefaultGammaTable() -  Retrieve the current Default GammaTable and validate GammaTable values for the valid colortemp by looping through the test specific config file | tvColorTemp_t ,  unsigned short *,  unsigned short *,  unsigned short *, unsigned short | tvERROR_NONE | Should Pass |
 * | 03 | call GetDefaultGammaTable() -  Retrieve the current GammaTable with valid argument and validate with above value | tvColorTemp_t ,  unsigned short *,  unsigned short *,  unsigned short *, unsigned short | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetDefaultGammaTable (void)
{
	unsigned short pData_R_limit[]={0, 100, 1023};
	unsigned short pData_G_limit[]={0, 100, 1023};
	unsigned short pData_B_limit[]={0, 100, 1023};
	unsigned short  size;
	bool bflag = true;
	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{
		/* Calling tvsettings SetGammaTable for all the valid arguments of colortemp and expecting the API to return success */ 
		result = GetGammaTable(pData_R_limit,pData_G_limit,pData_B_limit, size);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

		for(int i =0; i <size; i++ )
		{
			if(   (pData_R_limit[i] < 0 ||  pData_R_limit[i] > 1023) || \
					(pData_G_limit[i] < 0 ||  pData_G_limit[i] > 1023) || \
					(pData_B_limit[i] < 0 ||  pData_B_limit[i] > 1023) ){

				bflag = false;
				break;
			}
		}

		UT_ASSERT_TRUE_FATAL(bflag);
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetDefaultGammaTable() for all negative invocation scenarios
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
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetDefaultGammaTable() -  Retrieve current TV Default GammaTable even before TvInit() | tvColorTemp_t , unsigned short *,  unsigned short *,  unsigned short *, unsigned short | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetDefaultGammaTable() -  "pData_R, pData_G, pData_B, size"= valid , "colortemp"= Invalid maxrange | tvColorTemp_MAX ,unsigned short *,  unsigned short *,  unsigned short *, unsigned short | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetDefaultGammaTable() - "pData_R, pData_G, pData_B, size"= valid , "colortemp"= Invalid less than lower range | -1 ,unsigned short *,  unsigned short *,  unsigned short *, unsigned short | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetDefaultGammaTable() -  "colortemp, pData_G, pData_B, size"= valid , "pData_R"= Invalid | tvColorTemp_t , NULL, unsigned short *,  unsigned short *, unsigned short | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call GetDefaultGammaTable() -  "colortemp, pData_R, pData_B, size"= valid , "pData_G"= Invalid | tvColorTemp_t ,unsigned short *,NULL,  unsigned short *, unsigned short| tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call GetDefaultGammaTable() -  "colortemp, pData_R, pData_G, size"= valid , "pData_B"= Invalid | tvColorTemp_t ,unsigned short *,unsigned short *, NULL, unsigned short | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call GetDefaultGammaTable() -  Retrieve current TV Default GammaTable State with valid colortemp value but not supported by the platform by looping through the test specific config file | tvColorTemp_t , unsigned short *,  unsigned short *, unsigned short *,  unsigned short | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 10 | call GetDefaultGammaTable() -  Retrieve current TV Default GammaTable State valid arguments |tvColorTemp_t ,  unsigned short *,  unsigned short *,  unsigned short *, unsigned short | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetDefaultGammaTable (void)
{
	unsigned short pData_R_limit[] ={0, 100, 1023};
	unsigned short pData_G_limit[] ={0, 100, 1023};
	unsigned short pData_B_limit[]={0, 100, 1023};
	unsigned short  size;
	bool bflag = true;
	tvError_t result = tvERROR_NONE ;

#if 0
	result = GetGammaTable(pData_R_limit,pData_G_limit,pData_B_limit, &size);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = GetGammaTable((tvColorTemp_t)tvColorTemp_MAX, pData_R_limit,pData_G_limit,pData_B_limit, &size);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = GetGammaTable((tvColorTemp_t)-1, pData_R_limit,pData_G_limit,pData_B_limit, &size);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = GetGammaTable((tvColorTemp_t)Configfile.colorTemperature.modeId[0], NULL,pData_G_limit,pData_B_limit, &size);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = GetGammaTable((tvColorTemp_t)Configfile.colorTemperature.modeId[0], pData_R_limit,NULL,pData_B_limit, &size);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = GetGammaTable((tvColorTemp_t)Configfile.colorTemperature.modeId[0], pData_R_limit,pData_G_limit,NULL, &size);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = GetGammaTable((tvColorTemp_t)Configfile.colorTemperature.modeId[0], pData_R_limit,pData_G_limit,NULL, NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{

		for(int j=0; j<tvColorTemp_MAX;j++){

			if(Configfile.colorTemperature.modeId[i] == (tvColorTemp_t)j ){
				/* Calling tvsettings SetGammaTable for all the valid arguments of colortemp and expecting the API to return success */ 
				result = GetGammaTable((tvColorTemp_t)j, pData_R_limit,pData_G_limit,pData_B_limit, &size);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
			}
		}

	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);


	result = GetGammaTable((tvColorTemp_t)Configfile.colorTemperature.modeId[0], pData_R_limit,pData_G_limit,pData_B_limit, &size);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);
#endif
	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetGammaTable() for all positive invocation scenarios
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
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetGammaTable() -  Retrieve the current GammaTable and validate GammaTable values for the valid colortemp by looping through the test specific config file | tvColorTemp_t ,  unsigned short *,  unsigned short *,  unsigned short *, unsigned short | tvERROR_NONE | Should Pass |
 * | 03 | call GetGammaTable() -  Retrieve the current GammaTable with valid argument and validate with above value | tvColorTemp_t ,  unsigned short *,  unsigned short *,  unsigned short *, unsigned short | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetGammaTable (void)
{
	unsigned short pData_R_limit[]={0, 100, 1023};
	unsigned short pData_G_limit[]={0, 100, 1023};
	unsigned short pData_B_limit[]={0, 100, 1023};
	unsigned short  size;
	bool bflag = true;
	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
#if 0
	/* Calling tvsettings SetGammaTable for all the valid arguments of colortemp and expecting the API to return success */ 
	result = GetGammaTable(pData_R_limit,pData_G_limit,pData_B_limit, &size);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	for(int i =0; i <size, i++ )
	{
		if(   (pData_R_limit[i] < 0 ||  pData_R_limit[i] > 1023) || \
				(pData_G_limit[i] < 0 ||  pData_G_limit[i] > 1023) || \
				(pData_B_limit[i] < 0 ||  pData_B_limit[i] > 1023) ){

			bflag = false;
			break;
		}
	}

	UT_ASSERT_TRUE_FATAL(bflag);
#endif
	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetGammaTable() for all negative invocation scenarios
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
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call GetGammaTable() -  Retrieve current TV GammaTable State even before TvInit() | tvColorTemp_t ,  unsigned short *,  unsigned short *,  unsigned short *, unsigned short | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetGammaTable() -   Retrieve current TV GammaTable State with invalid input by looping through the colortemp from test specific config file | tvColorTemp_t ,  NULL,  unsigned short *,  unsigned short *, unsigned short | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetGammaTable() -   Retrieve current TV GammaTable State with invalid input by looping through the colortemp from test specific config file | tvColorTemp_t , unsigned short *,  NULL, unsigned short *, unsigned short | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetGammaTable() -   Retrieve current TV GammaTable State with invalid input by looping through the colortemp from test specific config file | tvColorTemp_t , unsigned short *,  unsigned short *, NULL,  unsigned short | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call GetGammaTable() -   Retrieve current TV GammaTable State with invalid colortemp with max range | tvColorTemp_MAX , unsigned short *,  unsigned short *, unsigned short *,  unsigned short| tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call GetGammaTable() -   Retrieve current TV GammaTable State with invalid colortemp  less than lower range | -1 , unsigned short *,  unsigned short *, unsigned short *,  unsigned short | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call GetGammaTable() -   Retrieve current TV GammaTable State with invalid size | tvColorTemp_t, unsigned short *, unsigned short *, unsigned short *, 257| tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call GetGammaTable() -   Retrieve current TV GammaTable State with valid colortemp  value but not supported by the platform by looping through the test specific config file | tvColorTemp_t , unsigned short *,  unsigned short *, unsigned short *,  unsigned short | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 11 | call GetGammaTable() -  Retrieve current TV GammaTable State valid arguments |tvColorTemp_t ,  unsigned short *,  unsigned short *,  unsigned short *, unsigned short | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetGammaTable (void)
{
	unsigned short pData_R_limit[]={0, 100, 1023};
	unsigned short pData_G_limit[]={0, 100, 1023};
	unsigned short pData_B_limit[]={0, 100, 1023};
	unsigned short  size;
	tvError_t result = tvERROR_NONE ;

#if 0
	result = GetGammaTable( pData_R_limit,pData_G_limit,pData_B_limit, &size);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = GetGammaTable( NULL,pData_G_limit,pData_B_limit, &size);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = GetGammaTable(  pData_R_limit,NULL,pData_B_limit, &size);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = GetGammaTable(pData_R_limit,pData_G_limit,NULL, &size);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = GetGammaTable(pData_R_limit,pData_G_limit,NULL, NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);


	result = GetGammaTable( pData_R_limit,pData_G_limit,pData_B_limit, &size);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);
#endif
	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveGammaTable() for all positive invocation scenarios
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
 * | 02 | call SaveGammaTable() -  save the current GammaTable State with valid arguments of colortemp by looping through the test specific config file | tvColorTemp_t , unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveGammaTable (void)
{
	gTestID = 151;                                    /* It must be 151 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	unsigned short pData_R_limit[] = {0, 100, 1023};
	unsigned short pData_G_limit[] = {0, 100, 1023};
	unsigned short pData_B_limit[] = {0, 100, 1023};
	unsigned short size;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{	
		/* Calling tvsettings SetGammaTable for all the valid arguments of colortemp and expecting the API to return success */ 
		result = SaveGammaTable((tvColorTemp_t)Configfile.colorTemperature.modeId[i], pData_R_limit,pData_G_limit,pData_B_limit, size);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM)
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveGammaTable() for all negative invocation scenarios
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
 * | 01 | call SaveGammaTable() - save the current GammaTable State even before TvInit() | tvColorTemp_t, unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SaveGammaTable() -   save the current GammaTable State with invalid input by looping through the colortemp from test specific config file| tvColorTemp_t, NULL, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SaveGammaTable() -   save the current GammaTable State with invalid input by looping through the colortemp from test specific config file| tvColorTemp_t, unsigned short *, NULL, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SaveGammaTable() -   save the current GammaTable State with invalid input by looping through the colortemp from test specific config file| tvColorTemp_t, unsigned short *, unsigned short *, NULL, 256| tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SaveGammaTable() -   save the current GammaTable State with invalid colortemp with max range | tvColorTemp_MAX , unsigned short *,  unsigned short *, unsigned short *,  int | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SaveGammaTable() -   save the current GammaTable State with invalid colortemp  less than lower range| -1 , unsigned short *,  unsigned short *, unsigned short *,  int | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call SaveGammaTable() -   save the current GammaTable State with invalid input for few elements of the array by looping through the colortemp from test specific config file| tvColorTemp_t, -1,  unsigned short *, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
 * | 09 | call SaveGammaTable() -   save the current GammaTable State with invalid input for few elements of the array by looping through the colortemp from test specific config file| tvColorTemp_t, 1023,  unsigned short *, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
 * | 10 | call SaveGammaTable() -   save the current GammaTable State with invalid input for few elements of the array by looping through the colortemp from test specific config file| tvColorTemp_t, unsigned short *,  -1, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
 * | 11 | call SaveGammaTable() -   save the current GammaTable State with invalid input for few elements of the array by looping through the colortemp from test specific config file| tvColorTemp_t, unsigned short *,  1023, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
 * | 12 | call SaveGammaTable() -   save the current GammaTable State with invalid input for few elements of the array by looping through the colortemp from test specific config file| tvColorTemp_t, unsigned short *,  unsigned short *, -1, 256 | tvERROR_INVALID_PARAM | Should Pass |
 * | 13 | call SaveGammaTable() -   save the current GammaTable State with invalid input for few elements of the array by looping through the colortemp from test specific config file| tvColorTemp_t, unsigned short *,  unsigned short *, 1023, 256 | tvERROR_INVALID_PARAM | Should Pass |
 * | 14 | call SaveGammaTable() -   save the current GammaTable State with invalid input by looping through the colortemp from test specific config file| tvColorTemp_t, unsigned short *,  unsigned short *, unsigned short *, 0 | tvERROR_INVALID_PARAM | Should Pass |
 * | 15 | call SaveGammaTable() -   save the current GammaTable State with invalid input by looping through the colortemp from test specific config file| tvColorTemp_t, unsigned short *,  unsigned short *, unsigned short *, 257 | tvERROR_INVALID_PARAM | Should Pass |
 * | 16 | call SaveGammaTable() -   save the current GammaTable State with valid colortemp  value but not supported by the platform by looping through the test specific config file | tvColorTemp_t , unsigned short *,  unsigned short *, unsigned short *, unsigned short| tvERROR_INVALID_PARAM | Should Pass |
 * | 17 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 18 | call SaveGammaTable() -  Set the current GammaTable State with valid input after TvTerm() | tvColorTemp_t, unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveGammaTable (void)
{
	gTestID = 152;                                    /* It must be 151 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	unsigned short pData_R_limit[] = {0, 100, 1023};
	unsigned short pData_G_limit[] = {0, 100, 1023};
	unsigned short pData_B_limit[] = {0, 100, 1023};

	unsigned short pData_R_limit_error[] = {1025, 100, 1023};
	unsigned short pData_G_limit_error[] = {0, 1025, 1023};
	unsigned short pData_B_limit_error[] = {0, 100, 1025};

	/* Calling tvsettings SaveGammaTable for all the valid arguments of colortemp and expecting the API to return success */ 
	result = SaveGammaTable((tvColorTemp_t)Configfile.colorTemperature.modeId[0], pData_R_limit ,pData_G_limit,pData_B_limit,256);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = SaveGammaTable(tvColorTemp_MAX, pData_R_limit,pData_G_limit,pData_B_limit,256);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = SaveGammaTable((tvColorTemp_t)-1, pData_R_limit,pData_G_limit,pData_B_limit,256);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveGammaTable for all the valid arguments of colortemp and expecting the API to return success */ 
	result = SaveGammaTable((tvColorTemp_t)Configfile.colorTemperature.modeId[0], NULL,pData_G_limit,pData_B_limit,256);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = SaveGammaTable((tvColorTemp_t)Configfile.colorTemperature.modeId[0], pData_R_limit,NULL,pData_B_limit,256);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = SaveGammaTable((tvColorTemp_t)Configfile.colorTemperature.modeId[0],pData_R_limit,pData_G_limit,NULL,256);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = SaveGammaTable((tvColorTemp_t)Configfile.colorTemperature.modeId[0],pData_R_limit,pData_G_limit,NULL,0);  //zero size
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = SaveGammaTable((tvColorTemp_t)Configfile.colorTemperature.modeId[0],pData_R_limit,pData_G_limit,NULL, 257); //MAX size
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = SaveGammaTable((tvColorTemp_t)Configfile.colorTemperature.modeId[0],pData_R_limit_error,pData_G_limit,pData_B_limit,256);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = SaveGammaTable((tvColorTemp_t)Configfile.colorTemperature.modeId[0],pData_R_limit,pData_G_limit_error,pData_B_limit,256);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = SaveGammaTable((tvColorTemp_t)Configfile.colorTemperature.modeId[0],pData_R_limit,pData_G_limit,pData_B_limit_error,256);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{

		for(int j=0; j<tvColorTemp_MAX;j++){

			if(Configfile.colorTemperature.modeId[i] != (tvColorTemp_t)j ){
				/* Calling tvsettings SetGammaTable for all the valid arguments of colortemp and expecting the API to return success */ 
				result = SaveGammaTable((tvColorTemp_t)j, pData_R_limit,pData_G_limit,pData_B_limit, 256);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
			}
		}

	}


	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	result = SaveGammaTable((tvColorTemp_t)Configfile.colorTemperature.modeId[0], pData_R_limit ,pData_G_limit,pData_B_limit,256);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetDvTmaxValue() for all positive invocation scenarios
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
 * | 02 | call SetDvTmaxValue() -  Set the Dv Tmax with valid value | 0 | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call SetDvTmaxValue() -  Reset the Dv Tmax  with another valid value | 5000 | tvERROR_NONE | Should Pass |
 * | 04 | call SetDvTmaxValue() -  Reset the Dv Tmax  with another valid value | 10000 | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetDvTmaxValue (void)
{
	gTestID = 157;                                    /* It must be 157 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetDvTmaxValue with value 0 and expecting the API to return success */
	result = SetDvTmaxValue(0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetDvTmaxValue with value 5000 and expecting the API to return success */
	result = SetDvTmaxValue(5000);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetDvTmaxValue with value 10000 and expecting the API to return success */
	result = SetDvTmaxValue(10000);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetDvTmaxValue() for all negative invocation scenarios
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
 * | 01 | call SetDvTmaxValue() - Set the Dv Tmax even before TvInit() | 1 | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetDvTmaxValue() -   Set the Dv Tmax with invalid input with less than lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetDvTmaxValue() -   Set the Dv Tmax with invalid input with max range |10001 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call SetDvTmaxValue() -  Set the Dv Tmax with valid input after TvTerm() | 0 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetDvTmaxValue (void)
{
	gTestID = 158;                                    /* It must be 158 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings SetDvTmaxValue with value 1 and expecting the API to return success */
	result = SetDvTmaxValue(1);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetDvTmaxValue with value -1 and expecting the API to return success */
	result = SetDvTmaxValue(-1);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetDvTmaxValue with value 10001 and expecting the API to return success */
	result = SetDvTmaxValue(10001);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetDvTmaxValue with value 0 and expecting the API to return success */
	result = SetDvTmaxValue(0);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetDvTmaxValue() for all positive invocation scenarios
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
 * | 02 | call GetDvTmaxValue() -  Retrieve the current Dv Tmax Value with valid arguments and validate it againt test specific config file | int * | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call GetDvTmaxValue() -  Retrieve the current Dv Tmax Value with valid argument and validate with above value | int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetDvTmaxValue (void)
{
	gTestID = 159;                                    /* It must be 159 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int tvDvTmax = -1;
	int tvDvTmaxRetry = -1;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetDvTmaxValue and expecting the API to return success */
	result = GetDvTmaxValue(&tvDvTmax);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
	UT_ASSERT_TRUE_FATAL(tvDvTmax >= 0 && tvDvTmax <= 10000)

		/* Calling tvsettings GetDvTmaxValue and expecting the API to return success */
		result = GetDvTmaxValue(&tvDvTmaxRetry);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL(tvDvTmax, tvDvTmaxRetry);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetDvTmaxValue() for all negative invocation scenarios
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
 * | 01 | call GetDvTmaxValue() -  Retrieve current Dv Tmax Value even before TvInit() | int * | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetDvTmaxValue() -   Retrieve current Dv Tmax Value with invalid argument | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetDvTmaxValue() -  Retrieve current Dv Tmax Value State valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetDvTmaxValue (void)
{
	gTestID = 160;                                    /* It must be 160 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int tvDvTmax = -1;

	/* Calling tvsettings GetDvTmaxValue and expecting the API to return success */
	result = GetDvTmaxValue(&tvDvTmax);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetDvTmaxValue and expecting the API to return success */
	result = GetDvTmaxValue(NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetDvTmaxValue and expecting the API to return success */
	result = GetDvTmaxValue(&tvDvTmax);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveDvTmaxValue() for all positive invocation scenarios
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
 * | 02 | call SaveDvTmaxValue() -  Save the current Dv Tmax Value by looping through all the values of ldimstate level and TMax from the test specific config file  |  ldimStateLevel_t , int | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveDvTmaxValue (void)
{
	gTestID = 161;                                    /* It must be 161 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveDvTmaxValue for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
	for (size_t j = 0; j < sizeof(Configfile.ldimMode.modeId) / sizeof(Configfile.ldimMode.modeId[0]); j++)
	{

		result = SaveDvTmaxValue((ldimStateLevel_t)Configfile.ldimMode.modeId[j], 0);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

		result = SaveDvTmaxValue((ldimStateLevel_t)Configfile.ldimMode.modeId[j], 1000);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

		result = SaveDvTmaxValue((ldimStateLevel_t)Configfile.ldimMode.modeId[j], 10000);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveDvTmaxValue() for all negative invocation scenarios
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
 * | 01 | call SaveDvTmaxValue() -  save current Dv Tmax Value even before TvInit() | ldimStateLevel_t, int | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SaveDvTmaxValue() -  Save current Dv Tmax Value with invalid source input with max range| LDIM_STATE_MAX, int | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SaveDvTmaxValue() -  Save current Dv Tmax Value with invalid source input less than the lower range| -1 , int | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SaveDvTmaxValue() -  Save current Dv Tmax Value with invalid TMax less than the lower range| ldimStateLevel_t, -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SaveDvTmaxValue() -  Save current Dv Tmax Value with invalid pqmode with max range | ldimStateLevel_t, 10001 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SaveDvTmaxValue() -  Save current Dv Tmax Value with valid value of  ldimstate level and TMax value but not supported by the platform by looping through the test specific config file|ldimStateLevel_t ,int | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 09 | call SaveDvTmaxValue() -  save current Dv Tmax Value valid arguments | ldimStateLevel_t ,int | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveDvTmaxValue (void)
{
	gTestID = 162;                                    /* It must be 162 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int numberOfSources;
	int numberOfPqmodes;
	int numberOfFormats;
	int numberOfLdimmodes;

	/* Calling tvsettings SaveDvTmaxValue and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveDvTmaxValue((ldimStateLevel_t)Configfile.ldimMode.modeId[0],500);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveDvTmaxValue and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveDvTmaxValue(LDIM_STATE_MAX,500);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveDvTmaxValue and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveDvTmaxValue((ldimStateLevel_t)-1, 500);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveDvTmaxValue and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveDvTmaxValue((ldimStateLevel_t)Configfile.ldimMode.modeId[0], -1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveDvTmaxValue and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveDvTmaxValue((ldimStateLevel_t)Configfile.ldimMode.modeId[0], 10001);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SaveDvTmaxValue and expecting the API to return tvERROR_INVALID_PARAM */
	numberOfLdimmodes = sizeof(Configfile.ldimMode.modeId)/sizeof(Configfile.ldimMode.modeId[0]);

	for(int j =0 ; j < numberOfLdimmodes; j++)
	{
		for(int i =LDIM_STATE_NONBOOST ; i < LDIM_STATE_MAX; i++){
			if(Configfile.ldimMode.modeId[j] != i)
			{
				result = SaveDvTmaxValue((ldimStateLevel_t)i, 1000);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
			}
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveDvTmaxValue and expecting the API to return tvERROR_INVALID_STATE */
	result = SaveDvTmaxValue((ldimStateLevel_t)Configfile.ldimMode.modeId[0],500);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	UT_LOG("Out %s",__FUNCTION__);
}

/** 
 * @brief Validate GetSupportedComponentColor() for all positive invocation scenarios
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
 * | 02 | call GetSupportedComponentColor() -  Retrieve the current Supported ComponentColor and validate Supported ComponentColor by looping through the test specific config file | int * | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call GetSupportedComponentColor() -  Retrieve the current Supported ComponentColor with valid argument and validate with above value | int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetSupportedComponentColor (void)
{
	gTestID = 163;                                    /* It must be 163 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	int tvComponentColor , tvComponentColor_bk;
	int tvComponentColorRetry ;
	bool IsComponentColorValid;
	size_t sizeReceived;
	size_t sizeReceivedRetry;
	size_t sizeFromConfig;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetSupportedComponentColor and expeting the API to return success */
	result = GetSupportedComponentColor(&tvComponentColor);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
	tvComponentColor_bk = tvComponentColor;

	for (size_t i = 0; i < sizeFromConfig; i++)
	{
		if(Configfile.componentColor.modeId[i] & tvComponentColor_bk)
		{
			tvComponentColor_bk &= (~Configfile.componentColor.modeId[i]);
		}
	}

	UT_ASSERT_FALSE(tvComponentColor_bk);

	/* Calling tvsettings GetSupportedComponentColor and expeting the API to return success */
	result = GetSupportedComponentColor(&tvComponentColorRetry);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL(tvComponentColorRetry, tvComponentColor);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetSupportedComponentColor() for all negative invocation scenarios
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
 * | 01 | call GetSupportedComponentColor() -  Retrieve current TV Supported ComponentColor even before TvInit() | int * | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetSupportedComponentColor() -  Retrieve supported component colortemperature with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetSupportedComponentColor() -  Retrieve supported component color with valid inputs and validate componentColor by looping through the test specific config file values | int * | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call GetSupportedComponentColor() -  Retrieve current TV Supported ComponentColor valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetSupportedComponentColor (void)
{
	gTestID = 164;                                    /* It must be 164 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int tvComponentColor = 0x00;

	/* Calling tvsettings GetSupportedComponentColor and expecting the API to return tvERROR_INVALID_STATE */
	result = GetSupportedComponentColor(&tvComponentColor);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetSupportedComponentColor and expecting the API to return tvERROR_INVALID_PARAM */
	result = GetSupportedComponentColor(NULL);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings GetSupportedComponentColor and expecting the API to return tvERROR_INVALID_STATE */
	result = GetSupportedComponentColor(&tvComponentColor);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetCurrentComponentSaturation() for all positive invocation scenarios
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
 * | 02 | call SetCurrentComponentSaturation() -  Set the TV component saturation by looping through all the values of saturation from test specific config file| tvDataComponentColor_t  ,0 | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call SetCurrentComponentSaturation() -  Set the TV component saturation by looping through all the values of saturation from test specific config file| tvDataComponentColor_t ,100 | tvERROR_NONE | Should Pass |
 * | 04 | call SetCurrentComponentSaturation() -  Set the TV component saturation by looping through all the values of saturation from test specific config file| tvDataComponentColor_t  ,50 | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetCurrentComponentSaturation (void)
{
	UT_FAIL("This function needs to be implemented!"); 
	gTestID = 165;                                    /* It must be 165 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetCurrentComponentSaturation and expecting the API to return tvERROR_INVALID_STATE */
	for (size_t i=0; i<(sizeof(Configfile.componentSaturation.modeId)/sizeof(Configfile.componentSaturation.modeId[0])); i++)
	{
		result = SetCurrentComponentSaturation((tvDataComponentColor_t)Configfile.componentSaturation.modeId[i],0);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

		result = SetCurrentComponentSaturation((tvDataComponentColor_t)Configfile.componentSaturation.modeId[i],100);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

		result = SetCurrentComponentSaturation((tvDataComponentColor_t)Configfile.componentSaturation.modeId[i],50);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetCurrentComponentSaturation() for all negative invocation scenarios
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
 * | 01 | call SetCurrentComponentSaturation() - Set the TV Current Component Saturation even before TvInit() | tvDataComponentColor_t ,  int | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetCurrentComponentSaturation() -  Set the TV Current Component Saturation with max range by looping through all the values from test specific config file  | tvDataComponentColor_t,  101 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetCurrentComponentSaturation() -  Set the TV Current Component Saturation with less than the lower range by looping through all the values from test specific config file | tvDataComponentColor_t,  -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetCurrentComponentSaturation() -  Set the TV Current Component Saturation with max range DataComponentColor| tvDataColor_MAX, 10 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetCurrentComponentSaturation() -  Set the TV Current Component Saturation with less than the lower range of DataComponentColor| -1, 10 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SetCurrentComponentSaturation() -  Set the TV Current Component Saturation with valid value of DataComponentColor but not supported by the platform by looping through the config file | tvDataComponentColor_t, 10 | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 09 | call SetCurrentComponentSaturation() -  Set the TV Current Component Saturation with valid input after TvTerm() | tvDataComponentColor_t ,  int | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetCurrentComponentSaturation (void)
{
	gTestID = 166;                                    /* It must be 166 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int numberOfSaturation;


	result = SetCurrentComponentSaturation((tvDataComponentColor_t)Configfile.componentSaturation.modeId[0],10);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);


	result = SetCurrentComponentSaturation((tvDataComponentColor_t)tvDataColor_MAX ,10);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);


	result = SetCurrentComponentSaturation((tvDataComponentColor_t)-1 ,10);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);


	result = SetCurrentComponentSaturation((tvDataComponentColor_t)Configfile.componentSaturation.modeId[0] ,101);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	result = SetCurrentComponentSaturation((tvDataComponentColor_t)Configfile.componentSaturation.modeId[0] ,-1);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);


	/* Calling tvsettings SetCurrentComponentSaturation and expecting the API to return tvERROR_INVALID_STATE */
	for (size_t i=0; i<(sizeof(Configfile.componentSaturation.modeId)/sizeof(Configfile.componentSaturation.modeId[0])); i++)
	{

		for(int j =0; j < tvDataColor_MAX; j++){

			if((tvDataComponentColor_t) Configfile.componentSaturation.modeId[i] !=(tvDataComponentColor_t) j){
				result = SetCurrentComponentSaturation((tvDataComponentColor_t)j,10);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
			}
		}
	}

	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	result = SetCurrentComponentSaturation((tvDataComponentColor_t)Configfile.componentSaturation.modeId[0],10);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetCurrentComponentSaturation() for all positive invocation scenarios
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
 * | 02 | call GetCurrentComponentSaturation() -  Retrieve the current Component Saturation with valid arguments by looping through all the values of DataComponentColor from test specific config file | tvDataComponentColor_t, int * | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call GetCurrentComponentSaturation() -  Retrieve the current Component Saturation with valid argument and validate with above value | tvDataComponentColor_t, int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetCurrentComponentSaturation (void)
{
	gTestID = 167;                                    /* It must be 167 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	int saturation;
	int saturationRetry;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = GetCurrentComponentSaturation((tvDataComponentColor_t)Configfile.componentSaturation.modeId[0],&saturation);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = GetCurrentComponentSaturation((tvDataComponentColor_t)Configfile.componentSaturation.modeId[0],&saturationRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_ASSERT_EQUAL_FATAL(saturation, saturationRetry);

	/* Calling tvsettings GetCurrentComponentSaturation and expeting the API to return success */
	for (size_t i = 0; i < (sizeof(Configfile.componentSaturation.modeId) / sizeof(Configfile.componentSaturation.modeId[0])); ++i)
	{
		result = GetCurrentComponentSaturation((tvDataComponentColor_t)Configfile.componentSaturation.modeId[i],&saturation);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
		UT_ASSERT_TRUE_FATAL( saturation >=0 && saturation <= 100);
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetCurrentComponentSaturation() for all negative invocation scenarios
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
 * | 01 | call GetCurrentComponentSaturation() -  Retrieve current TV Component Saturation even before TvInit() | tvDataComponentColor_t, int * | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentComponentSaturation() -  Retrieve current TV component saturation with invalid input by looping through all the values of DataComponentColor from test specific config file | tvDataComponentColor_t, NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetCurrentComponentSaturation() -  Retrieve current TV component saturation with Max range of DataComponentColor | tvDataComponentColor_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetCurrentComponentSaturation() -  Retrieve current TV component saturation with less than lower range of DataComponentColor  | -1, int * | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 07 | call GetCurrentComponentSaturation() -  Retrieve current TV Component Saturation valid arguments | tvDataComponentColor_t, int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetCurrentComponentSaturation (void)
{
	gTestID = 168;                                    /* It must be 168 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	int saturation;

	result = GetCurrentComponentSaturation((tvDataComponentColor_t)Configfile.componentSaturation.modeId[0],&saturation);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);


	/* Calling tvsettings GetCurrentComponentSaturation and expeting the API to return success */
	result = GetCurrentComponentSaturation(tvDataColor_MAX,&saturation);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings GetCurrentComponentSaturation and expeting the API to return success */
	result = GetCurrentComponentSaturation((tvDataComponentColor_t)-1,&saturation);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = GetCurrentComponentSaturation((tvDataComponentColor_t)Configfile.componentSaturation.modeId[0],NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings GetCurrentComponentSaturation and expeting the API to return success */
	for (size_t i = 0; i < (sizeof(Configfile.componentSaturation.modeId) / sizeof(Configfile.componentSaturation.modeId[0])); ++i)
	{

		for(int j =0; j < tvDataColor_MAX; j++){

			if((tvDataComponentColor_t) Configfile.componentSaturation.modeId[i] !=(tvDataComponentColor_t) j){
				result = GetCurrentComponentSaturation((tvDataComponentColor_t)j ,&saturation);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
			}
		}
	}


	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetCurrentComponentSaturation and expeting the API to return success */
	result = GetCurrentComponentSaturation((tvDataComponentColor_t)Configfile.componentSaturation.modeId[0],&saturation);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetCurrentComponentHue() for all positive invocation scenarios
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
 * | 02 | call SetCurrentComponentHue() -  Set the TV component hue by looping through all the values of component hue from test specific config file| tvDataComponentColor_t , 0 | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call SetCurrentComponentHue() -  Set the TV component hue by looping through all the values of component hue from test specific config file| tvDataComponentColor_t , 100 | tvERROR_NONE | Should Pass |
 * | 04 | call SetCurrentComponentHue() -  Set the TV component hue by looping through all the values of component hue from test specific config file| tvDataComponentColor_t , 50 | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetCurrentComponentHue (void)
{
	gTestID = 169;                                    /* It must be 169 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetCurrentComponentHue and expecting the API to return tvERROR_INVALID_STATE */
	for (size_t i=0; i<(sizeof(Configfile.componentHue.modeId)/sizeof(Configfile.componentHue.modeId[0])); i++)
	{
		result = SetCurrentComponentHue((tvDataComponentColor_t)Configfile.componentHue.modeId[i],0);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

		result = SetCurrentComponentHue((tvDataComponentColor_t)Configfile.componentHue.modeId[i],100);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

		result = SetCurrentComponentHue((tvDataComponentColor_t)Configfile.componentHue.modeId[i],50);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetCurrentComponentHue() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
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
 * | 01 | call SetCurrentComponentHue() -  Retrieve current TV Current Component Hue even before TvInit() | tvDataComponentColor_t, int | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetCurrentComponentHue() -  Set the TV Current Component Hue with max range by looping through all the values from test specific config file | tvDataComponentColor_t,  101 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetCurrentComponentHue() -  Set the TV Current Component Hue with less than the lower range by looping through all the values from test specific config file | tvDataComponentColor_t,  -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetCurrentComponentHue() -  Set the TV Current Component Hue with max range DataComponentColor| tvDataColor_MAX, 10 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetCurrentComponentHue() -  Set the TV Current Component Hue with less than the lower range of DataComponentColor| -1, 10 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SetCurrentComponentHue() -  Set the TV Current Component Hue with valid value of DataComponentColor but not supported by the platform by looping through the config fil| tvDataComponentColor_t, 10 | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 09 | call SetCurrentComponentHue() -  Retrieve current TV Current Component Hue valid arguments | tvDataComponentColor_t, int | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetCurrentComponentHue (void)
{
	gTestID = 166;                                    /* It must be 166 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int numberOfSaturation;


	result = SetCurrentComponentHue((tvDataComponentColor_t)Configfile.componentHue.modeId[0],10);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);


	result = SetCurrentComponentHue((tvDataComponentColor_t)tvDataColor_MAX ,10);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);


	result = SetCurrentComponentHue((tvDataComponentColor_t)-1 ,10);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);


	result = SetCurrentComponentHue((tvDataComponentColor_t)Configfile.componentHue.modeId[0] ,101);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	result = SetCurrentComponentHue((tvDataComponentColor_t)Configfile.componentHue.modeId[0] ,-1);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);


	/* Calling tvsettings SetCurrentComponentHue and expecting the API to return tvERROR_INVALID_STATE */
	for (size_t i=0; i<(sizeof(Configfile.componentHue.modeId)/sizeof(Configfile.componentHue.modeId[0])); i++)
	{

		for(int j =0; j < tvDataColor_MAX; j++){

			if((tvDataComponentColor_t) Configfile.componentHue.modeId[i] !=(tvDataComponentColor_t) j){
				result = SetCurrentComponentHue((tvDataComponentColor_t)j,10);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
			}
		}
	}

	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	result = SetCurrentComponentHue((tvDataComponentColor_t)Configfile.componentHue.modeId[0],10);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetCurrentComponentHue() for all positive invocation scenarios
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
 * | 02 | call GetCurrentComponentHue() - Retrieve the current Component Hue with valid arguments by looping through all the values of DataComponentColor from test specific config file | tvDataComponentColor_t, int * | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call GetCurrentComponentHue() -  Retrieve the current Component Hue with valid argument and validate with above value | tvDataComponentColor_t, int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetCurrentComponentHue (void)
{
	gTestID = 167;                                    /* It must be 167 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	int Hue;
	int HueRetry;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = GetCurrentComponentHue((tvDataComponentColor_t)Configfile.componentHue.modeId[0],&Hue);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = GetCurrentComponentHue((tvDataComponentColor_t)Configfile.componentHue.modeId[0],&HueRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_ASSERT_EQUAL_FATAL(Hue, HueRetry);

	/* Calling tvsettings GetCurrentComponentHue and expeting the API to return success */
	for (size_t i = 0; i < (sizeof(Configfile.componentHue.modeId) / sizeof(Configfile.componentHue.modeId[0])); ++i)
	{
		result = GetCurrentComponentHue((tvDataComponentColor_t)Configfile.componentHue.modeId[i],&Hue);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
		UT_ASSERT_TRUE_FATAL( Hue >=0 && Hue <= 100);
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetCurrentComponentHue() for all negative invocation scenarios
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
 * | 01 | call GetCurrentComponentHue() -  Retrieve current TV brightness even before TvInit() |tvDataComponentColor_t, int * | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentComponentHue() -  Retrieve current TV component Hue with invalid input by looping through all the values of DataComponentColor from test specific config file | tvDataComponentColor_t, NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetCurrentComponentHue() -  Retrieve current TV component Hue with Max range of DataComponentColor | tvDataComponentColor_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetCurrentComponentHue() -  Retrieve current TV component Hue with less than lower range of DataComponentColor  | -1, int * | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 07 | call GetCurrentComponentHue() -  Retrieve current TV brightness valid arguments | tvDataComponentColor_t, int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetCurrentComponentHue (void)
{

	gTestID = 168;                                    /* It must be 168 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	int Hue;

	result = GetCurrentComponentHue((tvDataComponentColor_t)Configfile.componentHue.modeId[0],&Hue);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);


	/* Calling tvsettings GetCurrentComponentHue and expeting the API to return success */
	result = GetCurrentComponentHue(tvDataColor_MAX,&Hue);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings GetCurrentComponentHue and expeting the API to return success */
	result = GetCurrentComponentHue((tvDataComponentColor_t)-1,&Hue);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = GetCurrentComponentHue((tvDataComponentColor_t)Configfile.componentHue.modeId[0],NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings GetCurrentComponentHue and expeting the API to return success */
	for (size_t i = 0; i < (sizeof(Configfile.componentHue.modeId) / sizeof(Configfile.componentHue.modeId[0])); ++i)
	{

		for(int j =0; j < tvDataColor_MAX; j++){

			if((tvDataComponentColor_t) Configfile.componentHue.modeId[i] !=(tvDataComponentColor_t) j){
				result = GetCurrentComponentHue((tvDataComponentColor_t)j ,&Hue);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
			}
		}
	}


	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetCurrentComponentHue and expeting the API to return success */
	result = GetCurrentComponentHue((tvDataComponentColor_t)Configfile.componentHue.modeId[0],&Hue);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetCurrentComponentLuma() for all positive invocation scenarios
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
 * | 02 | call SetCurrentComponentLuma() -  Set the TV component hue by looping through all the values of component Luma from test specific config file| tvDataComponentColor_t , 0 | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call SetCurrentComponentLuma() -  Set the TV component hue by looping through all the values of component Luma from test specific config file| tvDataComponentColor_t , 30 | tvERROR_NONE | Should Pass |
 * | 04 | call SetCurrentComponentLuma() -  Set the TV component hue by looping through all the values of component Luma from test specific config file| tvDataComponentColor_t , 15 | tvERROR_NONE | Should Pass |* | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetCurrentComponentLuma (void)
{
	gTestID = 165;                                    /* It must be 165 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetCurrentComponentLuma and expecting the API to return tvERROR_INVALID_STATE */
	for (size_t i=0; i<(sizeof(Configfile.componentLuma.modeId)/sizeof(Configfile.componentLuma.modeId[0])); i++)
	{
		result = SetCurrentComponentLuma((tvDataComponentColor_t)Configfile.componentLuma.modeId[i],0);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

		result = SetCurrentComponentLuma((tvDataComponentColor_t)Configfile.componentLuma.modeId[i],30);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

		result = SetCurrentComponentLuma((tvDataComponentColor_t)Configfile.componentLuma.modeId[i],15);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetCurrentComponentLuma() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
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
 * | 01 | call SetCurrentComponentLuma() -  Retrieve current TV Current Component Luma even before TvInit() | tvDataComponentColor_t, int | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetCurrentComponentLuma() -  Set the TV Current Component Luma with max range by looping through all the values from test specific config file | tvDataComponentColor_t,  31 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetCurrentComponentLuma() -  Set the TV Current Component Luma with less than the lower range by looping through all the values from test specific config file | tvDataComponentColor_t,  -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetCurrentComponentLuma() -  Set the TV Current Component Luma with max range DataComponentColor| tvDataColor_MAX, 10 | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetCurrentComponentLuma() -  Set the TV Current Component Luma with less than the lower range of DataComponentColor| -1, 10 | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SetCurrentComponentLuma() -  Set the TV Current Component Lima with valid value of DataComponentColor but not supported by the platform by looping through the config fil| tvDataComponentColor_t, 10 | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 09 | call SetCurrentComponentLuma() -  Retrieve current TV Current Component Luma valid arguments | tvDataComponentColor_t, int | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetCurrentComponentLuma (void)
{
	gTestID = 166;                                    /* It must be 166 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int numberOfSaturation;


	result = SetCurrentComponentLuma((tvDataComponentColor_t)Configfile.componentLuma.modeId[0],10);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);


	result = SetCurrentComponentLuma((tvDataComponentColor_t)tvDataColor_MAX ,10);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);


	result = SetCurrentComponentLuma((tvDataComponentColor_t)-1 ,10);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);


	result = SetCurrentComponentLuma((tvDataComponentColor_t)Configfile.componentLuma.modeId[0] ,31);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	result = SetCurrentComponentLuma((tvDataComponentColor_t)Configfile.componentLuma.modeId[0] ,-1);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);


	/* Calling tvsettings SetCurrentComponentLuma and expecting the API to return tvERROR_INVALID_STATE */
	for (size_t i=0; i<(sizeof(Configfile.componentLuma.modeId)/sizeof(Configfile.componentLuma.modeId[0])); i++)
	{

		for(int j =0; j < tvDataColor_MAX; j++){

			if((tvDataComponentColor_t) Configfile.componentLuma.modeId[i] !=(tvDataComponentColor_t) j){
				result = SetCurrentComponentLuma((tvDataComponentColor_t)j,10);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
			}
		}
	}

	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	result = SetCurrentComponentLuma((tvDataComponentColor_t)Configfile.componentLuma.modeId[0],10);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetCurrentComponentLuma() for all positive invocation scenarios
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
 * | 02 | call GetCurrentComponentLuma() - Retrieve the current Component Luma with valid arguments by looping through all the values of DataComponentColor from test specific config file | tvDataComponentColor_t, int * | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call GetCurrentComponentLuma() -  Retrieve the current Component Luma  with valid argument and validate with above value | tvDataComponentColor_t, int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetCurrentComponentLuma (void)
{
	gTestID = 167;                                    /* It must be 167 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	int Luma;
	int LumaRetry;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = GetCurrentComponentLuma((tvDataComponentColor_t)Configfile.componentLuma.modeId[0],&Luma);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = GetCurrentComponentLuma((tvDataComponentColor_t)Configfile.componentLuma.modeId[0],&LumaRetry);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_ASSERT_EQUAL_FATAL(Luma, LumaRetry);

	/* Calling tvsettings GetCurrentComponentLuma and expeting the API to return success */
	for (size_t i = 0; i < (sizeof(Configfile.componentLuma.modeId) / sizeof(Configfile.componentLuma.modeId[0])); ++i)
	{
		result = GetCurrentComponentLuma((tvDataComponentColor_t)Configfile.componentLuma.modeId[i],&Luma);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
		UT_ASSERT_TRUE_FATAL( Luma >=0 && Luma <= 100);
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetCurrentComponentLuma() for all negative invocation scenarios
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
 * | 01 | call GetCurrentComponentLuma() -  Retrieve current TV Current Component Luma even before TvInit() | tvDataColor_RED, int * | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetCurrentComponentLuma() -  Retrieve current TV component Luma with invalid input by looping through all the values of DataComponentColor from test specific config file | tvDataComponentColor_t, NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call GetCurrentComponentLuma() -  Retrieve current TV component Luma with Max range of DataComponentColor | tvDataComponentColor_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call GetCurrentComponentLuma() -  Retrieve current TV component Luma with less than lower range of DataComponentColor  | -1, int * | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 07 | call GetCurrentComponentLuma() -  Retrieve current TV Current Component Luma valid arguments | tvDataColor_RED, int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetCurrentComponentLuma (void)
{
	gTestID = 168;                                    /* It must be 168 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	int Luma;

	result = GetCurrentComponentLuma((tvDataComponentColor_t)Configfile.componentLuma.modeId[0],&Luma);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);


	/* Calling tvsettings GetCurrentComponentLuma and expeting the API to return success */
	result = GetCurrentComponentLuma(tvDataColor_MAX,&Luma);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings GetCurrentComponentLuma and expeting the API to return success */
	result = GetCurrentComponentLuma((tvDataComponentColor_t)-1,&Luma);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = GetCurrentComponentLuma((tvDataComponentColor_t) Configfile.componentLuma.modeId[0],NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings GetCurrentComponentLuma and expeting the API to return success */
	for (size_t i = 0; i < (sizeof(Configfile.componentLuma.modeId) / sizeof(Configfile.componentLuma.modeId[0])); ++i)
	{

		for(int j =0; j < tvDataColor_MAX; j++){

			if((tvDataComponentColor_t) Configfile.componentLuma.modeId[i] !=(tvDataComponentColor_t) j){
				result = GetCurrentComponentLuma((tvDataComponentColor_t)j ,&Luma);
				UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
			}
		}
	}


	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetCurrentComponentLuma and expeting the API to return success */
	result = GetCurrentComponentLuma((tvDataComponentColor_t)Configfile.componentLuma.modeId[0],&Luma);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveCMS() for all positive invocation scenarios
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
 * | 02 | call SaveCMS() -  Save the current CMS value by looping through all the values of sourceId, pqmode, videoFormatType, component_type, color_type from the test specific config file  |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,tvComponentType_t ,tvDataComponentColor_t ,int | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED)| Should Pass|
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SaveCMS (void)
{
	gTestID = 161;                                    /* It must be 161 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveCMS for all the sourceId,pqmode,videoFormatType, component_type, color_type and expecting the API to return success */
	for (size_t i = 0; i < sizeof(Configfile.videoSources.modeName) / sizeof(Configfile.videoSources.modeName[0]); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.pic_modes.modeName) / sizeof(Configfile.pic_modes.modeName[0]); j++)
		{
			for (size_t k = 0; k < sizeof(Configfile.videoformat.modeId) / sizeof(Configfile.videoformat.modeId[0]); k++)
			{
				for (size_t l = 0; l < sizeof(Configfile.componentType.modeId) / sizeof(Configfile.componentType.modeId[0]); l++)
				{
					for (size_t m = 0; m < sizeof(Configfile.componentColorType.modeId) / sizeof(Configfile.componentColorType.modeId[0]); m++)
					{
						result = SaveCMS((tvVideoSrcType_t) Configfile.videoSources.modeId[i],Configfile.pic_modes.modeId[j],(tvVideoFormatType_t) Configfile.videoformat.modeId[k],(tvComponentType_t)Configfile.componentType.modeId[l],(tvDataComponentColor_t)Configfile.componentColorType.modeId[m],30);
						UT_ASSERT_EQUAL(result, tvERROR_NONE);
					}
				}
			}
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SaveCMS() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
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
 * | 19 | call SaveCMS() -  "source, pqmode,videoFormatType, component_type color_type"= valid (looping through the test specific config file),"value"= valid | -2 , int ,tvVideoFormatType_t ,tvComponentType_t ,tvDataComponentColor_t ,int| tvERROR_INVALID_PARAM | Should Pass |
 * | 20 | call TvTerm()  -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 21 | call SaveCMS() -  save the CMS valid arguments |  tvVideoSrcType_t , int ,tvVideoFormatType_t ,tvComponentType_t ,tvDataComponentColor_t ,int| tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SaveCMS (void)
{
	UT_FAIL("This function needs to be implemented!"); 
}

/**
 * @brief Validate SetCMSState() for all positive invocation scenarios
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
 * | 02 | call SetCMSState() -  Set the CMSState with valid value | true | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call SetCMSState() -  Set the CMSState with valid value | false | tvERROR_NONE | Should Pass |
 * | 04 | call SetCMSState() -  Set the CMSState with valid value | true | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetCMSState (void)
{
	gTestID = 179;                                    /* It must be 179 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the SetCMSState for value true and the API to return success */
	result = SetCMSState(true);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the SetCMSState for value true and the API to return success */
	result = SetCMSState(false);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the SetCMSState for value true and the API to return success */
	result = SetCMSState(true);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate SetCMSState() for all negative invocation scenarios
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
 * | 01 | call SetCMSState() -  Set the TV CMS State even before TvInit() | true | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 04 | call SetCMSState() -  Set the TV CMS State with valid input after TvTerm() | true | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetCMSState (void)
{
	gTestID = 180;                                    /* It must be 180 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings to Set the SetCMSState for value true and the API to return success */
	result = SetCMSState(true);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the SetCMSState for value true and the API to return success */
	result = SetCMSState(true);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate GetDefaultPQParams() for all positive invocation scenarios
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
 * | 02 | call GetDefaultPQParams() -  Get the default value PQ parameter by looping through all the input params from test specific config file | int ,tvVideoSrcType_t ,tvVideoFormatType_t , tvPQParameterIndex_t , int *| (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetDefaultPQParams (void)
{

	gTestID = 29;                                    /* It must be 29 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
int value;
#if 0
	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveBacklight for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
	for (size_t i = 0; i < sizeof(Configfile.videoSources.modeId) / sizeof(Configfile.videoSources.modeId[0]); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.pic_modes.modeId) / sizeof(Configfile.pic_modes.modeId[0]); j++)
		{
			for (size_t k = 0; k < sizeof(Configfile.videoformat.modeId) / sizeof(Configfile.videoformat.modeId[0]); k++)
			{
				for (size_t l = 0; l < sizeof(Configfile.pq_paramIndex.modeId) / sizeof(Configfile.pq_paramIndex.modeId[0]); l++)
				{
					result = GetDefaultPQParams(Configfile.pic_modes.modeId[j],(tvVideoSrcType_t) Configfile.videoSources.modeId[i],(tvVideoFormatType_t) Configfile.videoformat.modeId[k], (tvPQParameterIndex_t)Configfile.pq_paramIndex.modeId[l],&value);
					UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
				}
			}
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
#endif
	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetDefaultPQParams() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
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
 * | 12 | call GetDefaultPQParams() -  "pqIndex,videoSrcType,videoFormatType,pqParamIndex"= valid (looping through the test specific config file),"value"= valid | int, tvVideoSrcType_t ,tvVideoFormatType_t , tvPQParameterIndex_t , int *| tvERROR_INVALID_PARAM | Should Pass |
 * | 13 | call TvTerm()  -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 14 | call GetDefaultPQParams() -  Get the default value PQ parameter valid arguments |  int, tvVideoSrcType_t ,tvVideoFormatType_t , tvPQParameterIndex_t , int *| tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetDefaultPQParams (void)
{
	gTestID = 30;                                    /* It must be 30 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int value;

#if 0
	/* Calling tvsettings GetDefaultPQParams and expecting the API to return tvERROR_INVALID_STATE */
	result = GetDefaultPQParams(Configfile.pic_modes.modeId[0],(tvVideoSrcType_t) Configfile.videoSources.modeId[0],(tvVideoFormatType_t) Configfile.videoformat.modeId[0], (tvPQParameterIndex_t)Configfile.pq_paramIndex.modeId[0],&value);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = GetDefaultPQParams(-1, (tvVideoSrcType_t) Configfile.videoSources.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0], (tvPQParameterIndex_t)Configfile.pq_paramIndex.modeId[0], &value);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = GetDefaultPQParams(PQ_MODE_MAX, (tvVideoSrcType_t) Configfile.videoSources.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0], (tvPQParameterIndex_t)Configfile.pq_paramIndex.modeId[0], &value);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = GetDefaultPQParams(Configfile.pic_modes.modeId[0],(tvVideoSrcType_t) VIDEO_SOURCE_MAX,(tvVideoFormatType_t) Configfile.videoformat.modeId[0], (tvPQParameterIndex_t)Configfile.pq_paramIndex.modeId[0],&value);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = GetDefaultPQParams(Configfile.pic_modes.modeId[0],(tvVideoSrcType_t) -2,(tvVideoFormatType_t) Configfile.videoformat.modeId[0], (tvPQParameterIndex_t)Configfile.pq_paramIndex.modeId[0],&value);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);


	result = GetDefaultPQParams(Configfile.pic_modes.modeId[0],(tvVideoSrcType_t) Configfile.videoSources.modeId[0],(tvVideoFormatType_t) VIDEO_FORMAT_MAX, (tvPQParameterIndex_t)Configfile.pq_paramIndex.modeId[0],&value);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = GetDefaultPQParams(Configfile.pic_modes.modeId[0],(tvVideoSrcType_t) Configfile.videoSources.modeId[0],(tvVideoFormatType_t) -1, (tvPQParameterIndex_t)Configfile.pq_paramIndex.modeId[0],&value);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = GetDefaultPQParams(Configfile.pic_modes.modeId[0],(tvVideoSrcType_t) Configfile.videoSources.modeId[0],(tvVideoFormatType_t) Configfile.videoformat.modeId[0],(tvPQParameterIndex_t) PQ_PARAM_MAX,&value);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);


	result = GetDefaultPQParams(Configfile.pic_modes.modeId[0],(tvVideoSrcType_t) Configfile.videoSources.modeId[0],(tvVideoFormatType_t) Configfile.videoformat.modeId[0], (tvPQParameterIndex_t) -1,&value);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = GetDefaultPQParams(Configfile.pic_modes.modeId[0],(tvVideoSrcType_t) Configfile.videoSources.modeId[0],(tvVideoFormatType_t) Configfile.videoformat.modeId[0], (tvPQParameterIndex_t)Configfile.pq_paramIndex.modeId[0], NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings GetDefaultPQParams and expecting the API to return tvERROR_INVALID_STATE */
	result = GetDefaultPQParams(Configfile.pic_modes.modeId[0],(tvVideoSrcType_t) Configfile.videoSources.modeId[0],(tvVideoFormatType_t) Configfile.videoformat.modeId[0], (tvPQParameterIndex_t)Configfile.pq_paramIndex.modeId[0], &value);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);
#endif
	UT_LOG("Out %s",__FUNCTION__);
}


/**
 * @brief Validate GetPQParams() for all positive invocation scenarios
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
 * | 02 | call GetPQParams() -  Get the default value PQ parameter by looping through all the input params from test specific config file | int ,tvVideoSrcType_t ,tvVideoFormatType_t , tvPQParameterIndex_t , int *| (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetPQParams (void)
{

	gTestID = 29;                                    /* It must be 29 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int value;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SaveBacklight for all the sourceId,pqmode,videoFormatType and expecting the API to return success */
	for (size_t i = 0; i < sizeof(Configfile.videoSources.modeId) / sizeof(Configfile.videoSources.modeId[0]); i++)
	{
		for (size_t j = 0; j < sizeof(Configfile.pic_modes.modeId) / sizeof(Configfile.pic_modes.modeId[0]); j++)
		{
			for (size_t k = 0; k < sizeof(Configfile.videoformat.modeId) / sizeof(Configfile.videoformat.modeId[0]); k++)
			{
				for (size_t l = 0; l < sizeof(Configfile.pq_paramIndex.modeId) / sizeof(Configfile.pq_paramIndex.modeId[0]); l++)
				{
					result = GetPQParams(Configfile.pic_modes.modeId[j],(tvVideoSrcType_t) Configfile.videoSources.modeId[i],(tvVideoFormatType_t) Configfile.videoformat.modeId[k], (tvPQParameterIndex_t)Configfile.pq_paramIndex.modeId[l],&value);
					UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
				}
			}
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetPQParams() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
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
 * | 01 | call GetPQParams() -  Get the default value PQ parameter even before TvInit() | int ,tvVideoSrcType_t ,tvVideoFormatType_t , tvPQParameterIndex_t , int * | (tvERROR_INVALID_STATE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
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
 * | 12 | call GetPQParams() -  "pqIndex,videoSrcType,videoFormatType,pqParamIndex"= valid (looping through the test specific config file),"value"= valid | int, tvVideoSrcType_t ,tvVideoFormatType_t , tvPQParameterIndex_t , int *| tvERROR_INVALID_PARAM | Should Pass |
 * | 13 | call TvTerm()  -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 14 | call GetPQParams() -  Get the default value PQ parameter valid arguments |  int, tvVideoSrcType_t ,tvVideoFormatType_t , tvPQParameterIndex_t , int *| tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetPQParams (void)
{
	gTestID = 30;                                    /* It must be 30 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int value;


	/* Calling tvsettings GetPQParams and expecting the API to return tvERROR_INVALID_STATE */
	result = GetPQParams(Configfile.pic_modes.modeId[0],(tvVideoSrcType_t) Configfile.videoSources.modeId[0],(tvVideoFormatType_t) Configfile.videoformat.modeId[0], (tvPQParameterIndex_t)Configfile.pq_paramIndex.modeId[0],&value);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	result = GetPQParams(-1, (tvVideoSrcType_t) Configfile.videoSources.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0], (tvPQParameterIndex_t)Configfile.pq_paramIndex.modeId[0], &value);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = GetPQParams(PQ_MODE_MAX, (tvVideoSrcType_t) Configfile.videoSources.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0], (tvPQParameterIndex_t)Configfile.pq_paramIndex.modeId[0], &value);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = GetPQParams(Configfile.pic_modes.modeId[0],(tvVideoSrcType_t) VIDEO_SOURCE_MAX,(tvVideoFormatType_t) Configfile.videoformat.modeId[0], (tvPQParameterIndex_t)Configfile.pq_paramIndex.modeId[0],&value);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = GetPQParams(Configfile.pic_modes.modeId[0],(tvVideoSrcType_t) -2,(tvVideoFormatType_t) Configfile.videoformat.modeId[0], (tvPQParameterIndex_t)Configfile.pq_paramIndex.modeId[0],&value);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);


	result = GetPQParams(Configfile.pic_modes.modeId[0],(tvVideoSrcType_t) Configfile.videoSources.modeId[0],(tvVideoFormatType_t) VIDEO_FORMAT_MAX, (tvPQParameterIndex_t)Configfile.pq_paramIndex.modeId[0],&value);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = GetPQParams(Configfile.pic_modes.modeId[0],(tvVideoSrcType_t) Configfile.videoSources.modeId[0],(tvVideoFormatType_t) -1, (tvPQParameterIndex_t)Configfile.pq_paramIndex.modeId[0],&value);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = GetPQParams(Configfile.pic_modes.modeId[0],(tvVideoSrcType_t) Configfile.videoSources.modeId[0],(tvVideoFormatType_t) Configfile.videoformat.modeId[0],(tvPQParameterIndex_t) PQ_PARAM_MAX,&value);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);


	result = GetPQParams(Configfile.pic_modes.modeId[0],(tvVideoSrcType_t) Configfile.videoSources.modeId[0],(tvVideoFormatType_t) Configfile.videoformat.modeId[0],  (tvPQParameterIndex_t )-1,&value);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	result = GetPQParams(Configfile.pic_modes.modeId[0],(tvVideoSrcType_t) Configfile.videoSources.modeId[0],(tvVideoFormatType_t) Configfile.videoformat.modeId[0], (tvPQParameterIndex_t)Configfile.pq_paramIndex.modeId[0], NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings GetPQParams and expecting the API to return tvERROR_INVALID_STATE */
	result = GetPQParams(Configfile.pic_modes.modeId[0],(tvVideoSrcType_t)Configfile.videoSources.modeId[0],(tvVideoFormatType_t)Configfile.videoformat.modeId[0],  (tvPQParameterIndex_t)Configfile.pq_paramIndex.modeId[0],&value);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetMaxGainValue() for all positive invocation scenarios
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
 * | 02 | call GetMaxGainValue() -  Retrieve the current MaxGain Value and validate it against the test specific config file values | void  | int | Should Pass |
 * | 03 | call GetMaxGainValue() -  Retrieve the current MaxGain Value with valid argument and validate with above value | void | int | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetMaxGainValue (void)
{
	gTestID = 183;                                    /* It must be 183 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int maxGain = -1;
	int maxGainRetry = -1;


	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetMaxGainValue and expeting the API to return success */
	maxGain = GetMaxGainValue();
	UT_ASSERT_TRUE(  maxGain >= 2^10 && maxGain <= (2^31)-1);

	/* Calling tvsettings GetMaxGainValue and expeting the API to return success */
	maxGainRetry = GetMaxGainValue( );
	UT_ASSERT_EQUAL(maxGain, maxGainRetry);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
}

/**
 * @brief Validate GetMaxGainValue() for all negative invocation scenarios
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
 * | 01 | call GetMaxGainValue() -  Retrieve current MaxGain Value even before TvInit() | void | -1 | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 04 | call GetMaxGainValue() -  Retrieve current MaxGain Value with valid arguments | void | -1 | Should Pass |
 */
void test_l1_tvSettings_negative_GetMaxGainValue (void)
{
	gTestID = 184;                                    /* It must be 184 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int maxGain = -1;

	/* Calling tvsettings to Set the GetMaxGainValue for value -1 and the API to return success */
	maxGain = GetMaxGainValue();
	UT_ASSERT_FALSE(  maxGain >= 2^10 && maxGain <= (2^31)-1);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the GetMaxGainValue for value -1 and the API to return success */
	maxGain = GetMaxGainValue();
	UT_ASSERT_FALSE(  maxGain >= 2^10 && maxGain <= (2^31)-1);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate EnableGammaMode() for all positive invocation scenarios
 * This test ensures that the TV Settings module is to set Gamma Mode value
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
 * | 02 | call EnableGammaMode() -  Set the Gamma Mode with valid value | 0 | tvERROR_NONE | Should Pass |
 * | 03 | call EnableGammaMode() -  Reset the Gamma Mode with another valid value | 1 | tvERROR_NONE | Should Pass |
 * | 04 | call EnableGammaMode() -  Reset the Gamma Mode with another valid value | 0 | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_EnableGammaMode (void)
{
	gTestID = 185;                                    /* It must be 185 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableGammaMode for value 0 and the API to return success */
	result = EnableGammaMode(0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableGammaMode for value 1 and the API to return success */
	result = EnableGammaMode(1);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableGammaMode for value 0 and the API to return success */
	result = EnableGammaMode(0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate EnableGammaMode() for all negative invocation scenarios
 * This test ensures that the TV Settings module is to set Gamma Mode value
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
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call EnableGammaMode() -   Set the TV GammaMode with invalid input | -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 03 | call EnableGammaMode() -   Set the TV GammaMode with invalid input | 256 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_negative_EnableGammaMode (void)
{
	gTestID = 186;                                    /* It must be 186 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	result = EnableGammaMode(1);
	UT_ASSERT_EQUAL(result, tvERROR_GENERAL);
	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableGammaMode for value -1 and the API to return success */
	result = EnableGammaMode(-1);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings to Set the EnableGammaMode for value 256 and the API to return success */
	result = EnableGammaMode(2);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	result = EnableGammaMode(1);
	UT_ASSERT_EQUAL(result, tvERROR_GENERAL);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate SetGammaPattern() for all positive invocation scenarios
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
	gTestID = 187;                                    /* It must be 187 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the SetGammaPattern for value 0,0,0,0 and the API to return success */
	result = SetGammaPattern(0,0,0,0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the SetGammaPattern for value 0,500,500,500 and the API to return success */
	result = SetGammaPattern(0,500,500,500);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the SetGammaPattern for value 0,1023,1023,1023 and the API to return success */
	result = SetGammaPattern(0,1023,1023,1023);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the SetGammaPattern for value 1,0,0,0 and the API to return success */
	result = SetGammaPattern(1,0,0,0);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the SetGammaPattern for value 1,255,255,255 and the API to return success */
	result = SetGammaPattern(1,255,255,255);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate SetGammaPattern() for all negative invocation scenarios
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
	gTestID = 188;                                    /* It must be 188 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings to Set the SetGammaPattern for value 0,0,0,0 and the API to return success */
	result = SetGammaPattern(0,0,0,0);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the SetGammaPattern for value -1,-1,-1,-1 and the API to return success */
	result = SetGammaPattern(-1,-1,-1,-1);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings to Set the SetGammaPattern for value -1,100,100,100 and the API to return success */
	result = SetGammaPattern(2,100,100,100);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings to Set the SetGammaPattern for value -1,0,0,0 and the API to return success */
	result = SetGammaPattern(-1,0,0,0);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings to Set the SetGammaPattern for value 1,1026,1026,1026 and the API to return success */
	result = SetGammaPattern(1,1026,1026,1026);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings to Set the SetGammaPattern for value 1,1026,0,0 and the API to return success */
	result = SetGammaPattern(1,1026,0,0);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings to Set the SetGammaPattern for value 1,0,1026,0 and the API to return success */
	result = SetGammaPattern(1,0,1026,0);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings to Set the SetGammaPattern for value 1,0,0,1026 and the API to return success */
	result = SetGammaPattern(1,0,0,1026);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the SetGammaPattern for value 0,0,0,0 and the API to return success */
	result = SetGammaPattern(0,0,0,0);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate GetTVGammaTarget() for all positive invocation scenarios
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
 * | 02 | call GetTVGammaTarget() -  Retrieve the current Gamma Target values and validate it by looping through the test specific config file | tvColorTemp_t, double *, double *| void | Should Pass |
 * | 03 | call GetTVGammaTarget() -  Retrieve the current current Gamma Target values with valid argument and validate with above value |  tvColorTemp_t, double *, double * | void | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetTVGammaTarget (void)
{
	gTestID = 189;                                    /* It must be 189 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	double x_ValueRetry, x_Value;
	double y_ValueRetry, y_Value;


	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	for (size_t i = 0; i < (sizeof(Configfile.colorTemperature.modeId)/sizeof(Configfile.colorTemperature.modeId[0])); i++)
	{
		GetTVGammaTarget( (tvColorTemp_t)Configfile.colorTemperature.modeId[i], &x_Value, &y_Value);
		UT_ASSERT_TRUE_FATAL(x_Value >= 0 && x_Value <= 1.0 );
		UT_ASSERT_TRUE_FATAL(y_Value >= 0 && y_Value <= 1.0 );
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetTVGammaTarget() for all negative invocation scenarios
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
 * | 01 | call GetTVGammaTarget() -  Retrieve current TV Gamma Target even before TvInit() | tvColorTemp_t, double *, double *| void | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetTVGammaTarget() -   Retrieve current TV Gamma Target with invalid input | tvColorTemp_t, double *, NULL | void | Should Pass |
 * | 04 | call GetTVGammaTarget() -   Retrieve current TV Gamma Target with invalid input | tvColorTemp_t, NULL, double * | void | Should Pass |
 * | 05 | call GetTVGammaTarget() -   Retrieve current TV Gamma Target with invalid input with max range| tvColorTemp_MAX, double *, double * | void | Should Pass |
 * | 06 | call GetTVGammaTarget() -   Retrieve current TV Gamma Target with invalid input with less than lower range| -1, double *, double * | void | Should Pass |
 * | 07 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 08 | call GetTVSupportedVideoFormats() -  Retrieve current TV Gamma Target valid arguments | tvColorTemp_t, double *, double * | void | Should Pass |
 */
void test_l1_tvSettings_negative_GetTVGammaTarget (void)
{
	gTestID = 189;                                    /* It must be 189 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	double x_ValueRetry, x_Value;
	double y_ValueRetry, y_Value;

	GetTVGammaTarget( (tvColorTemp_t)Configfile.colorTemperature.modeId[0], &x_Value, &y_Value);
	UT_ASSERT_FALSE_FATAL(x_Value >= 0 && x_Value <= 1.0 );
	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	GetTVGammaTarget( (tvColorTemp_t)tvColorTemp_MAX , &x_Value, &y_Value);
	UT_ASSERT_FALSE_FATAL(x_Value >= 0 && x_Value <= 1.0 );
	UT_ASSERT_FALSE_FATAL(y_Value >= 0 && y_Value <= 1.0 );

	GetTVGammaTarget( (tvColorTemp_t)-1 , &x_Value, &y_Value);
	UT_ASSERT_FALSE_FATAL(x_Value >= 0 && x_Value <= 1.0 );
	UT_ASSERT_FALSE_FATAL(y_Value >= 0 && y_Value <= 1.0 );

	GetTVGammaTarget( (tvColorTemp_t)Configfile.colorTemperature.modeId[0], NULL, &y_Value);
	UT_ASSERT_FALSE_FATAL(x_Value >= 0 && x_Value <= 1.0 );
	UT_ASSERT_FALSE_FATAL(y_Value >= 0 && y_Value <= 1.0 );

	GetTVGammaTarget( (tvColorTemp_t)Configfile.colorTemperature.modeId[0], &x_Value, NULL);
	UT_ASSERT_FALSE_FATAL(x_Value >= 0 && x_Value <= 1.0 );
	UT_ASSERT_FALSE_FATAL(y_Value >= 0 && y_Value <= 1.0 );

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	GetTVGammaTarget( (tvColorTemp_t)Configfile.colorTemperature.modeId[0], &x_Value, &y_Value);
	UT_ASSERT_FALSE_FATAL(x_Value >= 0 && x_Value <= 1.0 );

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate SetGammaPatternMode() for all positive invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
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
	gTestID = 185;                                    /* It must be 185 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableGammaMode for value 0 and the API to return success */
	result = SetGammaPatternMode(true);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableGammaMode for value 1 and the API to return success */
	result = SetGammaPatternMode(false);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableGammaMode for value 0 and the API to return success */
	result = SetGammaPatternMode(true);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/** 
 * @brief Validate SetGammaPatternMode() for all negative invocation scenarios
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
 * |Variation / Step|Description|Test Data|Expected Result|Notes|
 * |:--:|---------|----------|--------------|-----|
 * | 01 | call SetGammaPatternMode() - Set the Gamma Pattern Mode even before TvInit() | bool | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 04 | call SetGammaPatternMode() -  Set the TV backlight with valid input after TvTerm() | bool | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetGammaPatternMode (void)
{
	gTestID = 186;                                    /* It must be 186 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	result = SetGammaPatternMode(true);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	result = SetGammaPatternMode(true);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate SetRGBPattern() for all positive invocation scenarios
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
 * | 02 | call SetRGBPattern() -  Set the RGBPattern with valid value | 0,0,0 | tvERROR_NONE | Should Pass |
 * | 03 | call SetRGBPattern() -  Reset the RGBPattern with another valid value | 100,100,100 | tvERROR_NONE | Should Pass |
 * | 04 | call SetRGBPattern() -  Reset the RGBPattern with another valid value | 255,255,255 | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetRGBPattern (void)
{
	gTestID = 193;                                    /* It must be 193 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the SetRGBPattern for the RGB pattern 00,00,00 and expecting the API to return success */
	result = SetRGBPattern(00,00,00);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the SetRGBPattern for the RGB pattern 100,100,100 and expecting the API to return success */
	result = SetRGBPattern(100,100,100);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the SetRGBPattern for the RGB pattern 255,255,255 and expecting the API to return success */
	result = SetRGBPattern(255,255,255);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate SetRGBPattern() for all negative invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
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
	gTestID = 194;                                    /* It must be 194 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings SetRGBPattern and expecting the API to return tvERROR_INVALID_STATE */
	result = SetRGBPattern(00,00,00);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetRGBPattern and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetRGBPattern(256,100,100);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetRGBPattern and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetRGBPattern(100,256,100);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetRGBPattern and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetRGBPattern(100,100,256);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetRGBPattern and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetRGBPattern(-1,100,100);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetRGBPattern and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetRGBPattern(100,-1,100);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetRGBPattern and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetRGBPattern(100,100,-1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings the SetRGBPattern and expecting the API to return tvERROR_INVALID_STATE */
	result = SetRGBPattern(255,255,255);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate GetRGBPattern() for all positive invocation scenarios
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
 * | 02 | call GetRGBPattern() -  Retrieve the current RGB Pattern with valid arguments | int *, int *, int * | tvERROR_NONE | Should Pass |
 * | 03 | call GetRGBPattern() -  Retrieve the current RGB Pattern with valid arguments and validate with above value | int *, int *, int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetRGBPattern (void)
{
	gTestID = 195;                                    /* It must be 195 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int red = -1;
	int green = -1;
	int blue = -1;
	int redRetry = -1;
	int greenRetry = -1;
	int blueRetry = -1;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetRGBPattern and expecting the API to return success */
	result = GetRGBPattern(&red,&green,&blue);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_ASSERT_TRUE( red >= 0 && red <= 255);
	UT_ASSERT_TRUE( green >= 0 && green <= 255);
	UT_ASSERT_TRUE( blue >= 0 && blue <= 255);

	/* Calling tvsettings GetRGBPattern again and expecting the API to return success */
	result = GetRGBPattern(&redRetry,&greenRetry,&blueRetry);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL(red,redRetry);
	UT_ASSERT_EQUAL(green,greenRetry);
	UT_ASSERT_EQUAL(blue,blueRetry);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate GetRGBPattern() for all negative invocation scenarios
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
	gTestID = 196;                                    /* It must be 196 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int red = -1;
	int green = -1;
	int blue = -1;

	/* Calling tvsettings GetRGBPattern and the API to return tvERROR_INVALID_STATE */
	result = GetRGBPattern(&red,&green,&blue);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetRGBPattern and the API to return tvERROR_INVALID_PARAM */
	result = GetRGBPattern(NULL,&green,&blue);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings GetRGBPattern and the API to return tvERROR_INVALID_PARAM */
	result = GetRGBPattern(&red,NULL,&blue);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings GetRGBPattern and the API to return tvERROR_INVALID_PARAM */
	result = GetRGBPattern(&red,&green,NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetRGBPattern and the API to return tvERROR_INVALID_STATE */
	result = GetRGBPattern(&red,&green,&blue);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate SetGrayPattern() for all positive invocation scenarios
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
 * | 02 | call SetGrayPattern() -  Set the GrayPattern with valid value | 0 | tvERROR_NONE | Should Pass |
 * | 03 | call SetGrayPattern() -  Reset the GrayPattern with another valid value | 100 | tvERROR_NONE | Should Pass |
 * | 04 | call SetGrayPattern() -  Reset the GrayPattern with another valid value | 255 | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetGrayPattern (void)
{
	gTestID = 197;                                    /* It must be 197 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the SetGrayPattern for value 00 and the API to return success */
	result = SetGrayPattern(00);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the SetGrayPattern for value 100 and the API to return success */
	result = SetGrayPattern(100);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the SetGrayPattern for value 255 and the API to return success */
	result = SetGrayPattern(255);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 01 | call SetGrayPattern() - Set the TV GrayPattern even before TvInit() | 30 | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetGrayPattern() - Set the TV GrayPattern with less than lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetGrayPattern() - Set the TV GrayPattern with max range | 256 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call SetGrayPattern() -  Set the TV GrayPattern with valid input after TvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetGrayPattern (void)
{
	gTestID = 198;                                    /* It must be 198 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings SetGrayPattern and the API to return tvERROR_INVALID_STATE */
	result = SetGrayPattern(30);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetGrayPattern and the API to return tvERROR_INVALID_PARAM */
	result = SetGrayPattern(-1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetGrayPattern and the API to return tvERROR_INVALID_PARAM */
	result = SetGrayPattern(256);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings the SetGrayPattern and the API to return tvERROR_INVALID_STATE */
	result = SetGrayPattern(50);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate GetGrayPattern() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 199@n
 * 
 * **Pre-Conditions:** None@n
 *
 * **Dependencies:** None@n
 * **User Interaction:** None
 * **Test Procedure:**@n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetGrayPattern() -  Retrieve the current GrayPattern with valid arguments | int * | tvERROR_NONE | Should Pass |
 * | 03 | call GetGrayPattern() -  Retrieve the current GrayPattern with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetGrayPattern (void)
{
	gTestID = 199;                                    /* It must be 199 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int grayPattern = -1;
	int grayPatternRetry = -1;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVBacklight and the API to return success */
	result = GetGrayPattern(&grayPattern);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
	UT_ASSERT_TRUE( grayPattern >= 0 && grayPattern <= 255);

	/* Calling tvsettings GetTVBacklight again and the API to return success */
	result = GetGrayPattern(&grayPatternRetry);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL(grayPattern, grayPatternRetry);

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 01 | call GetGrayPattern() -  Retrieve current TV GrayPattern even before TvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call GetGrayPattern() - Get the TV GrayPattern with invalid input value | NULL | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 05 | call GetGrayPattern() -  Retrieve current TV GrayPattern valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_GetGrayPattern (void)
{
	gTestID = 200;                                    /* It must be 200 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int grayPattern = -1;

	/* Calling tvsettings GetGrayPattern and the API to return tvERROR_INVALID_STATE */
	result = GetGrayPattern(&grayPattern);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetGrayPattern and the API to return tvERROR_INVALID_PARAM */
	result = GetGrayPattern(NULL);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetGrayPattern and the API to return tvERROR_INVALID_STATE */
	result = GetGrayPattern(&grayPattern);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate GetOpenCircuitStatus() for all positive invocation scenarios
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
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :-------: | ------------- | --------- | --------------- | ----- |
 * | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 02 | call GetOpenCircuitStatus() -  Retrieve the OpenCircuit Status and validate it by looping through the test specific config file values | int *  | tvERROR_NONE | Should Pass |
 * | 03 | call GetOpenCircuitStatus()-  Retrieve the OpenCircuit Status with valid argument and validate with above value | int * | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_GetOpenCircuitStatus (void)
{
	gTestID = 199;                                    /* It must be 199 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int OpenCircuitStatus = -1;
	int OpenCircuitStatusRetry = -1;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetTVBacklight and the API to return success */
	result = GetOpenCircuitStatus(&OpenCircuitStatus);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
	UT_ASSERT_TRUE(OpenCircuitStatus >= 0);

	/* Calling tvsettings GetTVBacklight again and the API to return success */
	result = GetOpenCircuitStatus(&OpenCircuitStatusRetry);
	UT_ASSERT_EQUAL(result, tvERROR_NONE);
	UT_ASSERT_EQUAL(OpenCircuitStatus, OpenCircuitStatusRetry);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**  
 * @brief Validate GetOpenCircuitStatus() for all negative invocation scenarios
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
	gTestID = 200;                                    /* It must be 200 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;
	int OpenCircuitStatus = -1;

	/* Calling tvsettings GetGrayPattern and the API to return tvERROR_INVALID_STATE */
	result = GetOpenCircuitStatus(&OpenCircuitStatus);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings GetGrayPattern and the API to return tvERROR_INVALID_PARAM */
	result = GetOpenCircuitStatus(NULL);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings GetGrayPattern and the API to return tvERROR_INVALID_STATE */
	result = GetOpenCircuitStatus(&OpenCircuitStatus);
	UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
}

/**
 * @brief Validate EnableLDIMPixelCompensation() for all positive invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
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
	gTestID = 203;                                    /* It must be 203 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableLDIMPixelCompensation for value true and the API to return success */
	result = EnableLDIMPixelCompensation(true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableLDIMPixelCompensation for value true and the API to return success */
	result = EnableLDIMPixelCompensation(false);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableLDIMPixelCompensation for value true and the API to return success */
	result = EnableLDIMPixelCompensation(true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
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
 * **Test Case ID:** 204@n
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
 * | 03 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 04 | call EnableLDIMPixelCompensation() -  Enable the LDIM Pixel Compensation valid input after TvTerm() | true | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_EnableLDIMPixelCompensation (void)
{
	gTestID = 204;                                    /* It must be 204 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings to Set the EnableLDIMPixelCompensation for value true and the API to return success */
	result = EnableLDIMPixelCompensation(true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableLDIMPixelCompensation for value true and the API to return success */
	result = EnableLDIMPixelCompensation(true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);  
}

/**
 * @brief Validate EnableLDIM() for all positive invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
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
	gTestID = 205;                                    /* It must be 205 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableLDIM for value true and the API to return success */
	result = EnableLDIM(true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableLDIM for value true and the API to return success */
	result = EnableLDIM(false);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableLDIM for value true and the API to return success */
	result = EnableLDIM(true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
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
 * **Test Case ID:** 206@n
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
 * | 03 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 04 | call EnableLDIM() -  Enable the LDIM valid input after TvTerm() | true | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_EnableLDIM (void)
{
	gTestID = 206;                                    /* It must be 206 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings to Set the EnableLDIM for value true and the API to return success */
	result = EnableLDIM(true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableLDIM for value true and the API to return success */
	result = EnableLDIM(true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate StartLDIMSequenceTest() for all positive invocation scenarios
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
 * | 02 | call StartLDIMSequenceTest() -  Start the LDIM Sequence Test with valid value | 2,  100 | tvERROR_NONE | Should Pass |
 * | 03 | call StartLDIMSequenceTest() -  Restart the LDIM Sequence Test with another valid value | 2, 500 | tvERROR_NONE | Should Pass |
 * | 04 | call StartLDIMSequenceTest() -  Restart the LDIM Sequence Test with another valid value | 2, 1000 | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_StartLDIMSequenceTest (void)
{
	gTestID = 207;                                    /* It must be 207 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings StartLDIMSequenceTest for value 2, 100 and the API to return success */
	result = StartLDIMSequenceTest(2,100);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings StartLDIMSequenceTest for value 2, 500 and the API to return success */
	result = StartLDIMSequenceTest(2,500);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings StartLDIMSequenceTest for value 2, 1000 and the API to return success */
	result = StartLDIMSequenceTest(2,1000);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 01 | call StartLDIMSequenceTest() - start the LDIM Sequence Test even before TvInit() | int , int | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call StartLDIMSequenceTest() - start the LDIM Sequence Test with invalid value | -1, 100 | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call StartLDIMSequenceTest() - start the LDIM Sequence Test with invalid value with less than lower range | 2, -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call StartLDIMSequenceTest() -   start the LDIM Sequence Test with valid input after TvTerm() |  int , int | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_StartLDIMSequenceTest (void)
{
	gTestID = 208;                                    /* It must be 208 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings StartLDIMSequenceTest for value 2, 500 and the API to return success */
	result = StartLDIMSequenceTest(2,500);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings StartLDIMSequenceTest for value -1, 100 and the API to return success */
	result = StartLDIMSequenceTest(-1,100);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings StartLDIMSequenceTest for value 2, -1 and the API to return success */
	result = StartLDIMSequenceTest(2, -1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings StartLDIMSequenceTest for value 2, 500 and the API to return success */
	result = StartLDIMSequenceTest(2,500);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate SetBacklightTestMode() for all positive invocation scenarios
 *
 * **Test Group ID:** Basic : 01@n
 * **Test Case ID:** 209@n
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
 * | 02 | call SetBacklightTestMode() -  Start the Backlight Test Mode by looping through the test specific config file |tvBacklightTestMode_t | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetBacklightTestMode (void)
{
	gTestID = 210;                                    /* It must be 210 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings SetBacklightTestMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SetBacklightTestMode((tvBacklightTestMode_t)Configfile.backlightTestModes.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetBacklightTestMode and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetBacklightTestMode(tvBacklightTestMode_Max);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetBacklightTestMode and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetBacklightTestMode((tvBacklightTestMode_t)-1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings the SetBacklightTestMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SetBacklightTestMode( (tvBacklightTestMode_t)Configfile.backlightTestModes.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);

}

/** 
 * @brief Validate SetBacklightTestMode() for all negative invocation scenarios
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
 * | 01 | call SetBacklightTestMode() - start the Backlight Test Mode even before TvInit() | tvBacklightTestMode_t | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetBacklightTestMode() - start the Backlight Test Mode with invalid value with Max range |tvBacklightTestMode_Max | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetBacklightTestMode() - start the Backlight Test Mode with invalid value with less than lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 06 | call SetBacklightTestMode() -   start the Backlight Test Mode with valid input after TvTerm() | tvBacklightTestMode_t | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetBacklightTestMode (void)
{

	gTestID = 210;                                    /* It must be 210 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings SetBacklightTestMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SetBacklightTestMode((tvBacklightTestMode_t)Configfile.backlightTestModes.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings SetBacklightTestMode and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetBacklightTestMode(tvBacklightTestMode_Max);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetBacklightTestMode and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetBacklightTestMode((tvBacklightTestMode_t)-1);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings the SetBacklightTestMode and expecting the API to return tvERROR_INVALID_STATE */
	result = SetBacklightTestMode( (tvBacklightTestMode_t)Configfile.backlightTestModes.modeId[0]);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__);
}

/**
 * @brief Validate EnableWhiteBalance() for all positive invocation scenarios
 *
 * @note tvERROR_GENERAL is platform specific and cannot be simulated
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
	gTestID = 211;                                    /* It must be 211 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableWhiteBalance for value true and the API to return success */
	result = EnableWhiteBalance(true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableWhiteBalance for value true and the API to return success */
	result = EnableWhiteBalance(false);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableWhiteBalance for value true and the API to return success */
	result = EnableWhiteBalance(true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
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
 * **Test Case ID:** 212@n
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
 * | 03 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 04 | call EnableWhiteBalance() -  Enable White Balance valid input after TvTerm() | true | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_EnableWhiteBalance (void)
{
	gTestID = 212;                                    /* It must be 212 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings to Set the EnableWhiteBalance for value true and the API to return success */
	result = EnableWhiteBalance(true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableWhiteBalance for value true and the API to return success */
	result = EnableWhiteBalance(true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate EnableDynamicContrast() for all positive invocation scenarios
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
 * | 02 | Call EnableDynamicContrast() - Enable Dynamic Contrast  with valid value | true | tvERROR_NONE | Should Pass |
 * | 03 | call EnableDynamicContrast() - Disable Dynamic Contrast with valid value | false | tvERROR_NONE | Should Pass |
 * | 04 | call EnableDynamicContrast() - Enable Dynamic Contrast with valid value | true | tvERROR_NONE | Should Pass |
 * | 05 | call TvTerm() -  Terminate and close the instance of the TV client | bool | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_EnableDynamicContrast (void)
{
	gTestID = 213;                                    /* It must be 213 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableDynamicContrast for value true and the API to return success */
	result = EnableDynamicContrast(true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableDynamicContrast for value true and the API to return success */
	result = EnableDynamicContrast(false);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableDynamicContrast for value true and the API to return success */
	result = EnableDynamicContrast(true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 01 | call EnableDynamicContrast() - Enable Dynamic Contrast even before TvInit() | true | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 04 | call EnableDynamicContrast() -  Enable Dynamic Contrast valid input after TvTerm() | true | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_EnableDynamicContrast (void)
{
	gTestID = 214;                                    /* It must be 214 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings to Set the EnableDynamicContrast for value true and the API to return success */
	result = EnableDynamicContrast(true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableDynamicContrast for value true and the API to return success */
	result = EnableDynamicContrast(true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/** 
 * @brief Validate EnableLocalContrast() for all negative invocation scenarios
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
 * | 01 | call EnableLocalContrast() - Enable Local Contrast even before TvInit() | true | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 04 | call EnableLocalContrast() -  Enable Local Contrast valid input after TvTerm() | true | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_positive_EnableLocalContrast (void)
{
	gTestID = 215;                                    /* It must be 215 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableLocalContrast for value true and the API to return success */
	result = EnableLocalContrast(true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableLocalContrast for value true and the API to return success */
	result = EnableLocalContrast(false);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableLocalContrast for value true and the API to return success */
	result = EnableLocalContrast(true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
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
 * | 01 | call EnableLocalContrast() - Enable Local Contrast even before TvInit() | true | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 04 | call EnableLocalContrast() -  Enable Local Contrast valid input after TvTerm() | true | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_EnableLocalContrast (void)
{
	gTestID = 216;                                    /* It must be 216 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings to Set the EnableLocalContrast for value true and the API to return success */
	result = EnableLocalContrast(true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL(result, tvERROR_NONE);

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings to Set the EnableLocalContrast for value true and the API to return success */
	result = EnableLocalContrast(true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate SetWakeupConfig() for all positive invocation scenarios
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
 * | 02 | call SetWakeupConfig() -  Enable the WakeupConfig by looping through all the values of wakeup modes from the test specific config file | const tvWakeupSrcType_t , true | tvERROR_NONE | Should Pass |
 * | 03 | call SetWakeupConfig() -  Disable the WakeupConfig by looping through all the values of wakeup modes from the test specific config file | const tvWakeupSrcType_t , false | tvERROR_NONE | Should Pass |
 * | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 */
void test_l1_tvSettings_positive_SetWakeupConfig (void)
{
	gTestID = 217;                                    /* It must be 217 */
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE ;

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetWakeupConfig and expecting the API to return success */
	for (size_t i = 0; i < (sizeof(Configfile.wakeupconfig.modeId)/sizeof(Configfile.wakeupconfig.modeId[0])); i++)
	{
		result = SetWakeupConfig((tvWakeupSrcType_t)Configfile.wakeupconfig.modeId[i], true);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	}

	/* Calling tvsettings SetWakeupConfig and expecting the API to return success */
	for (size_t i = 0; i < (sizeof(Configfile.wakeupconfig.modeId)/sizeof(Configfile.wakeupconfig.modeId[0])); i++)
	{
		result = SetWakeupConfig((tvWakeupSrcType_t)Configfile.wakeupconfig.modeId[i], false);
		UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	UT_LOG("Out %s",__FUNCTION__); 
}

/**
 * @brief Validate SetWakeupConfig() for all negative invocation scenarios
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
 * | 01 | call SetWakeupConfig() - Set the TV WakeupConfig even before TvInit() | tvWakeupSrcType_t, true | tvERROR_INVALID_STATE | Should Pass |
 * | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 03 | call SetWakeupConfig() -   Set the TV WakeupConfig with less than lower range | -1, true  | tvERROR_INVALID_PARAM | Should Pass |
 * | 04 | call SetWakeupConfig() -   Set the TV WakeupConfig with less than lower range | -1, false  | tvERROR_INVALID_PARAM | Should Pass |
 * | 05 | call SetWakeupConfig() -   Set the TV WakeupConfig with  max range | tvWakeupSrc_MAX, true  | tvERROR_INVALID_PARAM | Should Pass |
 * | 06 | call SetWakeupConfig() -   Set the TV WakeupConfig with valid value but not supported by the platform by looping through the test specific config file | tvWakeupSrcType_t, true  | tvERROR_INVALID_PARAM | Should Pass |
 * | 07 | call SetWakeupConfig() -   Set the TV WakeupConfig with valid value but not supported by the platform by looping through the test specific config file | tvWakeupSrcType_t, false  | tvERROR_INVALID_PARAM | Should Pass |
 * | 08 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
 * | 09 | call SetWakeupConfig() -  Set the TV WakeupConfig with valid input after TvTerm() | tvWakeupSrcType_t, false  | tvERROR_INVALID_STATE | Should Pass |
 */
void test_l1_tvSettings_negative_SetWakeupConfig (void)
{
	gTestID = 54;                                    /* It must be 54*/
	UT_LOG("In:%s [%02d%03d]", __FUNCTION__,gTestGroup,gTestID);

	tvError_t result = tvERROR_NONE;
	int numberofWakeupConfig = 0;

	/* Calling tvsettings SetWakeupConfig and expecting the API to return tvERROR_INVALID_STATE */
	result = SetWakeupConfig((tvWakeupSrcType_t)Configfile.wakeupconfig.modeId[0], true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);

	/* Calling tvsettings initialization and expecting the API to return success */
	result = TvInit();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings SetWakeupConfig and expecting the API to return success */
	result = SetWakeupConfig((tvWakeupSrcType_t)-1,true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetWakeupConfig and expecting the API to return success */
	result = SetWakeupConfig((tvWakeupSrcType_t)-1,false);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetWakeupConfig and expecting the API to return tvERROR_INVALID_PARAM */
	result = SetWakeupConfig(tvWakeupSrc_MAX,true);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);

	/* Calling tvsettings SetWakeupConfig and expecting the API to return tvERROR_INVALID_PARAM */
	numberofWakeupConfig = sizeof(Configfile.wakeupconfig.modeId)/sizeof(Configfile.wakeupconfig.modeId[0]);
	for(int i =0 ; i < numberofWakeupConfig; i++)
	{
		for(int j = i+1 ; j < numberofWakeupConfig; j++)
		{
			result = SetWakeupConfig((tvWakeupSrcType_t) (Configfile.wakeupconfig.modeId[i] | Configfile.wakeupconfig.modeId[j]),true);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings SetWakeupConfig and expecting the API to return tvERROR_INVALID_PARAM */
	numberofWakeupConfig = sizeof(Configfile.wakeupconfig.modeId)/sizeof(Configfile.wakeupconfig.modeId[0]);
	for(int i =0 ; i < numberofWakeupConfig; i++)
	{
		for(int j = i+1 ; j < numberofWakeupConfig; j++)
		{
			result = SetWakeupConfig((tvWakeupSrcType_t) (Configfile.wakeupconfig.modeId[i] | Configfile.wakeupconfig.modeId[j]),false);
			UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_PARAM);
		}
	}

	/* Calling tvsettings termination and expecting the API to return success */
	result = TvTerm();
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_NONE);

	/* Calling tvsettings the SetWakeupConfig and expecting the API to return tvERROR_INVALID_STATE */
	result = SetWakeupConfig((tvWakeupSrcType_t)Configfile.wakeupconfig.modeId[0],false);
	UT_ASSERT_EQUAL_FATAL(result, tvERROR_INVALID_STATE);
}

static UT_test_suite_t * pSuite = NULL;

/**
 * @brief Register the main test(s) for this module
 *
 * @return int - 0 on success, otherwise failure
 */
int test_l1_tvSettings_register ( void )
{
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
	UT_add_test( pSuite, "SetGammaTable_L1_positive" ,test_l1_tvSettings_positive_SetGammaTable );
	UT_add_test( pSuite, "SetGammaTable_L1_negative" ,test_l1_tvSettings_negative_SetGammaTable );
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
	UT_add_test( pSuite, "GetDefaultPQParams_L1_positive" ,test_l1_tvSettings_positive_GetDefaultPQParams );
	UT_add_test( pSuite, "GetDefaultPQParams_L1_negative" ,test_l1_tvSettings_negative_GetDefaultPQParams );
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
	UT_add_test( pSuite, "SetWakeupConfig_L1_positive" ,test_l1_tvSettings_positive_SetWakeupConfig );
	UT_add_test( pSuite, "SetWakeupConfig_L1_negative" ,test_l1_tvSettings_negative_SetWakeupConfig );
	return 0;
} 

/** @} */ // End of TV_Settings_HALTEST_L1
/** @} */ // End of TV_Settings_HALTEST
/** @} */ // End of TV_Settings
/** @} */ // End of HPK

