/**
*  If not stated otherwise in this file or this component's Licenses.txt
*  file the following copyright and licenses apply:
*
*  Copyright 2022 RDK Management
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
* @file TODO: test_l1_tvSettings.c
* @page module_name TODO: Required field, name of the main module
* @subpage sub_page_name TODO: Add a function group if relevant
*
* ## Module's Role
* TODO: Explain the module's role in the system in general
* This is to ensure that the API meets the operational requirements of the module across all vendors.
*
* **Pre-Conditions:**  TODO: Add pre-conditions if any@n
* **Dependencies:** TODO: Add dependencies if any@n
*
* Ref to API Definition specification documentation : [halSpec.md](../../../docs/halSpec.md)
*/

#include <string.h>
#include <stdlib.h>

#include <ut.h>
#include <ut_log.h>

/**
* @brief This function tests positive scenarios for tvInit()

* Call tvInit() - tv settings initialization must succeed
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 001@n
*
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** None@n
*
* **Test Procedure:**@n
*
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* |01| Call `tvInit()` | Initialization | tvERROR_NONE | Should Pass |
* |02| Call `tvTerm()` | Termination | tvERROR_NONE | Should Pass |
* |03| Call `tvInit()` | Initialization | tvERROR_NONE | Should Pass |
* |04| Call `tvTerm()` | Termination | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_tvInit (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief This function tests negative scenarios for tvInit()

* Call tvInit() - tv settings initialization must succeed
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 002@n
*
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** None@n
*
* **Test Procedure:**@n
*
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
*/
void test_l1_tvSettings_negative_tvInit (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief This function tests positive scenarios for tvSD3toCriSyncInit()

* Call tvSD3toCriSyncInit() - tv settings initialization must succeed
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 003@n
*
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** None@n
*
* **Test Procedure:**@n
*
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* |01| Call `tvSD3toCriSyncInit()` | Initialization | tvERROR_NONE | Should Pass |
* |02| Call `tvTerm()` | Termination | tvERROR_NONE | Should Pass |
* |03| Call `tvSD3toCriSyncInit()` | Initialization | tvERROR_NONE | Should Pass |
* |04| Call `tvTerm()` | Termination | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_tvSD3toCriSyncInit (void)
{
	UT_FAIL(This function needs to be implemented!); 
}


/**
* @brief This function tests negative scenarios for tvSD3toCriSyncInit()

* Call tvSD3toCriSyncInit() - tv settings initialization must succeed
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 004@n
*
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** None@n
*
* **Test Procedure:**@n
*
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
*/
void test_l1_tvSettings_negative_tvSD3toCriSyncInit (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief This function tests positive scenarios for tvterm()

* Call tvTerm() - tv settings termination must succeed
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 005@n
*
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** None@n
*
* **Test Procedure:**@n
*
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* |01| Call `tvInit()` | Initialization | tvERROR_NONE | Should Pass |
* |02| Call `tvTerm()` | Termination | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_tvTerm (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief This function tests negative scenarios for tvterm()

* Call tvTerm() - tv settings termination must succeed
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 006@n
*
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** None@n
*
* **Test Procedure:**@n
*
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
*/
void test_l1_tvSettings_negative_tvTerm (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief This function tests positive scenarios for GetTVPictureMode()

* Call GetTVPictureMode() - tv settings GetTVPictureMode must succeed
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 007@n
*
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** None@n
*
* **Test Procedure:**@n
*
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* |01| Call `tvInit()` | Initialization | tvERROR_NONE | Should Pass |
* |02| Call `GetTVPictureMode()` | call GetTVPictureMode function | pass Mode data | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetTVPictureMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}
/**
* @brief This function tests negative scenarios for GetTVPictureMode()

* Call GetTVPictureMode() - tv settings GetTVPictureMode must succeed
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 008@n
*
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** None@n
*
* **Test Procedure:**@n
*
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* |01| Call `tvInit()` | Initialization | tvERROR_NONE | Should Pass |
* |02| Call `GetTVPictureMode()` | call GetTVPictureMode function | pass Mode data | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetTVPictureMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief This function tests positive scenarios for SetTVPictureMode()

* Call SetTVPictureMode() - tv settings SetTVPictureMode must succeed
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 009@n
*
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** None@n
*
* **Test Procedure:**@n
*
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* |01| Call `tvInit()` | Initialization | tvERROR_NONE | Should Pass |
* |02| Call `SetTVPictureMode()` | call SetTVPictureMode function | pass string input | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetTVPictureMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief This function tests negative scenarios for SetTVPictureMode()

* Call SetTVPictureMode() - tv settings SetTVPictureMode must succeed
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 010@n
*
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** None@n
*
* **Test Procedure:**@n
*
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* |01| Call `tvInit()` | Initialization | tvERROR_NONE | Should Pass |
* |02| Call `SetTVPictureMode()` | call SetTVPictureMode function | pass string input | tvERROR_GENERAL | Should Pass |
* |03| Call `SetTVPictureMode()` | call SetTVPictureMode function | pass string input | tvERROR_INVALID_PARAM | Should Pass |
*/
void test_l1_tvSettings_negative_SetTVPictureMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief This function tests positive scenarios for GetBacklight()

* Call GetBacklight() - tv settings GetBacklight must succeed
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 011@n
*
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** None@n
*
* **Test Procedure:**@n
*
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* |01| Call `tvInit()` | Initialization | tvERROR_NONE | Should Pass |
* |02| Call `GetBacklight()` | call GetBacklight function | pass string input | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetBacklight (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief This function tests negative scenarios for SetTVPictureMode()

* Call GetBacklight() - tv settings GetBacklight must succeed
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 012@n
*
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** None@n
*
* **Test Procedure:**@n
*
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* |01| Call `tvInit()` | Initialization | tvERROR_NONE | Should Pass |
* |02| Call `GetBacklight()` | call SetTVPictureMode function | pass string input | tvERROR_INVALID_PARAM | Should Pass |
*/
void test_l1_tvSettings_negative_GetBacklight (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief This function tests positive scenarios for SetBacklight()

* Call SetBacklight() - tv settings SetBacklight must succeed
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 013@n
*
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** None@n
*
* **Test Procedure:**@n
*
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* |01| Call `tvInit()` | Initialization | tvERROR_NONE | Should Pass |
* |02| Call `SetBacklight()` | call SetBacklight function | pass input | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetBacklight (void)
{
	UT_FAIL(This function needs to be implemented!); 
}


/**
* @brief This function tests negative scenarios for SetBacklight ()

* Call SetBacklight () - tv settings SetBacklight  must succeed
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 014@n
*
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** None@n
*
* **Test Procedure:**@n
*
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* |01| Call `tvInit()` | Initialization | tvERROR_NONE | Should Pass |
* |02| Call `SetBacklight()` | call SetBacklight  function | pass input | tvERROR_INVALID_PARAM | Should Pass |
*/
void test_l1_tvSettings_negative_SetBacklight (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief This function tests positive scenarios for SetBrightness ()

* Call SetBrightness () - tv settings SetBrightness  must succeed
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 015@n
*
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** None@n
*
* **Test Procedure:**@n
*
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* |01| Call `tvInit()` | Initialization | tvERROR_NONE | Should Pass |
* |02| Call `SetBrightness()` | call SetBrightness  function | pass input | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetBrightness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief This function tests negative scenarios for SetBrightness ()

* Call SetBrightness () - tv settings SetBrightness  must succeed
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 016@n
*
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** None@n
*
* **Test Procedure:**@n
*
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* |01| Call `tvInit()` | Initialization | tvERROR_NONE | Should Pass |
* |02| Call `SetBrightness()` | call SetBrightness  function | pass input | tvERROR_INVALID_PARAM | Should Pass |
*/
void test_l1_tvSettings_negative_SetBrightness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetBrightness() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully get the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 17@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 02 | call GetBrightness() -  trying to get brightness with valid arguments after tvInit | &value | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetBrightness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetBrightness() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully get the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 18@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetBrightness() -  trying to get brightness ,even before tvInit | &value | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -  invoke to get brightness with invalid input | &value = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 05 | call GetBrightness() -  trying to get brightness with valid arguments | &value | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetBrightness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure SetContrast() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully set contrast value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 19@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 02 | call SetContrast() -  trying to set contrast with valid arguments after tvInit | contrast = 50 | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure SetContrast() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully set contrast value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 20@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetContrast() -  trying to set contrast ,even before tvInit | contrast | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call SetContrast() -  invoke to set contrast with invalid input | contrast = 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetContrast() -  invoke to set contrast with invalid input | contrast = 100 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetContrast() -  trying to set contrast with valid arguments after tvInit | contrast = 50 | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 06 | call SetContrast() -  trying to set contrast with valid arguments | contrast = 50 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetContrast() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully get contrast value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 21@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |

* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 04 | call GetContrast() -  trying to get contrast with valid arguments after tvInit | &contrast | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetContrast() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully get contrast value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 22@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetContrast() -  trying to get contrast ,even before tvInit | contrast | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call GetContrast() -  invoke to get contrast with invalid input | &contrast = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 06 | call GetContrast() -  trying to get contrast with valid arguments | &contrast  | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure SetSharpness() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully Set Sharpness value once module is initialized
* 3. Passing invalid parameter values excluding between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 23@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |

* | 01 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 02 | call SetSharpness() -  trying to Set Sharpness with valid arguments after tvInit | sharpness = 50 | tvERROR_NONE | Should Pass |
* | 03 | call SetSharpness() -  trying to Set Sharpness with valid arguments after tvInit | sharpness = 70 | tvERROR_NONE | Should Pass |
* | 04 | call SetSharpness() -  trying to Set Sharpness with valid arguments after tvInit | sharpness = 90 | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |

*/
void test_l1_tvSettings_positive_SetSharpness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure SetSharpness() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully Set Sharpness value once module is initialized
* 3. Passing invalid parameter values excluding between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 24@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetSharpness() -  trying to Set Sharpness ,even before tvInit | sharpness | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call SetSharpness() -  invoke to Set Sharpness with invalid input | sharpness = 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetSharpness() -  invoke to Set Sharpness with invalid input | sharpness = 100 | tvERROR_INVALID_PARAM | Should Pass |

* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 06 | call SetSharpness() -  trying to Set Sharpness with valid arguments | sharpness = 50 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetSharpness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetSharpness() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully Get Sharpness value once module is initialized
* 3. Passing invalid address(NULL) as parameter, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 25@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 02 | call GetSharpness() -  trying to Get Sharpness with valid arguments after tvInit | &sharpness | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetSharpness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetSharpness() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully Get Sharpness value once module is initialized
* 3. Passing invalid address(NULL) as parameter, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 26@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetSharpness() -  trying to Get Sharpness ,even before tvInit | &sharpness | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call GetSharpness() -  invoke to Get Sharpness with invalid input | &sharpness = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 05 | call GetSharpness() -  trying to Get Sharpness with valid arguments | &sharpness  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetSharpness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure SetSaturation() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully Set Saturation value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 27@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 02 | call SetSaturation() -  trying to Set Saturation with valid arguments after tvInit | saturation = 50 | tvERROR_NONE | Should Pass |
* | 03 | call SetSaturation() -  trying to Set Saturation with valid arguments after tvInit | saturation = 70 | tvERROR_NONE | Should Pass |
* | 04 | call SetSaturation() -  trying to Set Saturation with valid arguments after tvInit | saturation = 90 | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure SetSaturation() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully Set Saturation value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 28@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetSaturation() -  trying to Set Saturation ,even before tvInit | saturation | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call SetSaturation() -  invoke to Set Saturation with invalid input | saturation = 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetSaturation() -  invoke to Set Saturation with invalid input | saturation = 100 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 06 | call SetSaturation() -  trying to Set Saturation with valid arguments | saturation = 50 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetSaturation() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully Get Saturation value once module is initialized
* 3. Passing invalid address(NULL) as parameter, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 29@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 02 | call GetSaturation() -  trying to Get Saturation with valid arguments after tvInit | &saturation | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetSaturation() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully Get Saturation value once module is initialized
* 3. Passing invalid address(NULL) as parameter, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 30@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetSaturation() -  trying to Get Saturation ,even before tvInit | &saturation | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call GetSaturation() -  Invoke to Get Saturation with invalid input | &saturation = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 05 | call GetSaturation() -  trying to Get Saturation with valid arguments | &saturation  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure SetHue() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully Set Hue value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 31@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 02 | call SetHue() -  trying to Set Hue with valid arguments after tvInit | hue = 50 | tvERROR_NONE | Should Pass |
* | 03 | call SetHue() -  trying to Set Hue with valid arguments after tvInit | hue = 70 | tvERROR_NONE | Should Pass |
* | 04 | call SetHue() -  trying to Set Hue with valid arguments after tvInit | hue = 90 | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure SetHue() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully Set Hue value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 32@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetHue() -  trying to Set Hue ,even before tvInit | hue | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call SetHue() -  invoke to Set Hue with invalid input | hue = 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetHue() -  invoke to Set Hue with invalid input | hue = 100 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 06 | call SetHue() -  trying to Set Hue with valid arguments | hue = 50 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetHue() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully Get Hue  value once module is initialized
* 3. Passing invalid address(NULL) as parameter, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 33@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 02 | call GetHue() -  trying to Get Hue with valid arguments after tvInit | &hue | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetHue() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully Get Hue  value once module is initialized
* 3. Passing invalid address(NULL) as parameter, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 34@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetHue() -  trying to Get Hue ,even before tvInit | &hue | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call GetHue() -  invoke to Get Hue with invalid input | &hue = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 05 | call GetHue() -  trying to Get Hue with valid arguments | &hue  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure SetColorTemperature() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully Set ColorTemperature value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 4, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 35@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemperature() -  trying to Set ColorTemperature with valid arguments after tvInit | colorTemp = 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemperature() -  trying to Set ColorTemperature with valid arguments after tvInit | colorTemp = 1 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemperature() -  trying to Set ColorTemperature with valid arguments after tvInit | colorTemp = 2 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemperature() -  trying to Set ColorTemperature with valid arguments after tvInit | colorTemp = 3 | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemperature() -  trying to Set ColorTemperature with valid arguments after tvInit | colorTemp = 4 | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemperature (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure SetColorTemperature() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully Set ColorTemperature value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 4, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 36@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetColorTemperature() -  trying to Set ColorTemperature ,even before tvInit | colorTemp | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemperature() -  invoke to Set ColorTemperature with invalid input | colorTemp >= 5 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemperature() -  trying to Set ColorTemperaturewith valid arguments | colorTemp = 0 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemperature (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetColorTemperature() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully Get ColorTemperature  value once module is initialized
* 3. Passing invalid address(NULL) as parameter, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 37@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemperature() -  trying to Get ColorTemperature with valid arguments after tvInit | &colorTemp | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemperature (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetColorTemperature() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully Get ColorTemperature  value once module is initialized
* 3. Passing invalid address(NULL) as parameter, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 38@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetColorTemperature() -  trying to Get ColorTemperature ,even before tvInit | &colorTemp | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemperature() -  invoke to Get ColorTemperature with invalid input | &colorTemp = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 05 | call GetGetColorTemperatureHue() -  trying to Get ColorTemperature with valid arguments | &colorTemp  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetColorTemperature (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure SetAspectRatio() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully SetAspectRatio  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 39@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 02 | call SetAspectRatio() -  trying to Set AspectRatio with valid arguments after tvInit | &dispMode | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetAspectRatio (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure SetAspectRatio() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully SetAspectRatio  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 40@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetAspectRatio() -  trying to Set AspectRatio ,even before tvInit | dispMode | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call SetAspectRatio() -  invoke to Set AspectRatio with invalid input | dispMode = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 0 | call SetAspectRatio() -  trying to Set AspectRatio with valid arguments | &dispMode  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetAspectRatio (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetAspectRatio() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully GetAspectRatio  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 41@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 02 | call GetAspectRatio() -  trying to Get AspectRatio with valid arguments after tvInit | &contrast | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetAspectRatio (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetAspectRatio() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully GetAspectRatio  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 42@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetAspectRatio() -  trying to Get AspectRatio ,even before tvInit | contrast | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call GetAspectRatio() -  invoke to Get AspectRatio with invalid input | &contrast = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 05 | call GetAspectRatio() -  trying to Get AspectRatio with valid arguments | &contrast  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetAspectRatio (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetSupportedBacklightModes() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully GetSupportedBacklightModes  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 43@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 02 | call GetSupportedBacklightModes() -  trying to Get SupportedBacklightModes with valid arguments after tvInit | &contrast | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetSupportedBacklightModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetSupportedBacklightModes() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully GetSupportedBacklightModes  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 44@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetSupportedBacklightModes() -  trying to Get SupportedBacklightModes ,even before tvInit | contrast | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call GetSupportedBacklightModes() -  invoke to Get SupportedBacklightModes with invalid input | &contrast = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 05 | call GetSupportedBacklightModes() -  trying to Get SupportedBacklightModes with valid arguments | &contrast  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetSupportedBacklightModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetCurrentBacklightMode() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully GetCurrentBacklightMode  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 45@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 02 | call GetCurrentBacklightMode() -  trying to Get CurrentBacklightMode with valid arguments after tvInit | &contrast | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetCurrentBacklightMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetCurrentBacklightMode() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully GetCurrentBacklightMode  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 46@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetCurrentBacklightMode() -  trying to Get CurrentBacklightMode ,even before tvInit | contrast | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call GetCurrentBacklightMode() -  invoke to Get CurrentBacklightMode with invalid input | &contrast = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 05 | call GetCurrentBacklightMode() -  trying to Get CurrentBacklightMode with valid arguments | &contrast  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetCurrentBacklightMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure SetCurrentBacklightMode() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully SetCurrentBacklightMode  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 47@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetCurrentBacklightMode() -  trying to Set CurrentBacklightMode ,even before tvInit | contrast | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call SetCurrentBacklightMode() -  invoke to Set CurrentBacklightMode with invalid input | &contrast = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetCurrentBacklightMode() -  trying to Set CurrentBacklightMode with valid arguments after tvInit | &contrast | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 06 | call SetCurrentBacklightMode() -  trying to Set CurrentBacklightMode with valid arguments | &contrast  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_positive_SetCurrentBacklightMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetCurrentBacklightMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetCurrentVideoFormat() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully GetCurrentVideoFormat  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** logs@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetCurrentVideoFormat() -  trying to Get CurrentVideoFormat ,even before tvInit | contrast | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call GetCurrentVideoFormat() -  invoke to Get CurrentVideoFormat with invalid input | &contrast = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetCurrentVideoFormat() -  trying to Get CurrentVideoFormat with valid arguments after tvInit | &contrast | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 06 | call GetCurrentVideoFormat() -  trying to Get CurrentVideoFormat with valid arguments | &contrast  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_positive_GetCurrentVideoFormat (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetCurrentVideoFormat (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetVideoResolution() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully GetVideoResolution  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** logs@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetVideoResolution() -  trying to Get VideoResolution ,even before tvInit | contrast | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call GetVideoResolution() -  invoke to Get VideoResolution with invalid input | &contrast = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetVideoResolution() -  trying to Get VideoResolution with valid arguments after tvInit | &contrast | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 06 | call GetVideoResolution() -  trying to Get VideoResolution with valid arguments | &contrast  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_positive_GetVideoResolution (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetVideoResolution (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetVideoFrameRate() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully GetVideoFrameRate  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** logs@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetVideoFrameRate() -  trying to Get VideoFrameRate ,even before tvInit | contrast | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call GetVideoFrameRate() -  invoke to Get VideoFrameRate with invalid input | &contrast = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetVideoFrameRate() -  trying to Get VideoFrameRate with valid arguments after tvInit | &contrast | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 06 | call GetVideoFrameRate() -  trying to Get VideoFrameRate with valid arguments | &contrast  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_positive_GetVideoFrameRate (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetVideoFrameRate (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure setWakeupConfig() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully setWakeupConfig  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** logs@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call setWakeupConfig() -  trying to Set WakeupConfig ,even before tvInit | contrast | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call setWakeupConfig() -  invoke to Set WakeupConfig with invalid input | &contrast = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call setWakeupConfig() -  trying to Set WakeupConfig with valid arguments after tvInit | &contrast | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 06 | call setWakeupConfig() -  trying to Set WakeupConfig with valid arguments | &contrast  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_positive_setWakeupConfig (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_setWakeupConfig (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure SetRGBPattern() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully SetRGBPattern  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** logs@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetRGBPattern() -  trying to Set RGBPattern ,even before tvInit | contrast | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call SetRGBPattern() -  invoke to Set RGBPattern with invalid input | &contrast = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetRGBPattern() -  trying to Set RGBPattern with valid arguments after tvInit | &contrast | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 06 | call SetRGBPattern() -  trying to Set RGBPattern with valid arguments | &contrast  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_positive_SetRGBPattern (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetRGBPattern (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetRGBPattern() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully GetRGBPattern  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** logs@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetRGBPattern() -  trying to Get RGBPattern ,even before tvInit | contrast | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call GetRGBPattern() -  invoke to Get RGBPattern with invalid input | &contrast = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetRGBPattern() -  trying to Get RGBPattern with valid arguments after tvInit | &contrast | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 06 | call GetRGBPattern() -  trying to Get RGBPattern with valid arguments | &contrast  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_positive_GetRGBPattern (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetRGBPattern (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure SetGrayPattern() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully SetGrayPattern  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** logs@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetGrayPattern() -  trying to Set GrayPattern ,even before tvInit | contrast | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call SetGrayPattern() -  invoke to Set GrayPattern with invalid input | &contrast = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetGrayPattern() -  trying to Set GrayPattern with valid arguments after tvInit | &contrast | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 06 | call SetGrayPattern() -  trying to Set GrayPattern with valid arguments | &contrast  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_positive_SetGrayPattern (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetGrayPattern (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetGrayPattern() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully GetGrayPattern  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** logs@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetGrayPattern() -  trying to Get GrayPattern ,even before tvInit | contrast | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call GetGrayPattern() -  invoke to Get GrayPattern with invalid input | &contrast = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetGrayPattern() -  trying to Get GrayPattern with valid arguments after tvInit | &contrast | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 06 | call GetGrayPattern() -  trying to Get GrayPattern with valid arguments | &contrast  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_positive_GetGrayPattern (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetGrayPattern (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SetColorTemp_Rgain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetColorTemp_Rgain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetColorTemp_Rgain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetColorTemp_Rgain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SetColorTemp_Ggain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetColorTemp_Ggain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetColorTemp_Ggain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetColorTemp_Ggain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SetColorTemp_Bgain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetColorTemp_Bgain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetColorTemp_Bgain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetColorTemp_Bgain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SetColorTemp_R_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetColorTemp_R_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetColorTemp_R_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetColorTemp_R_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SetColorTemp_G_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetColorTemp_G_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetColorTemp_G_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetColorTemp_G_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SetColorTemp_B_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetColorTemp_B_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetColorTemp_B_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetColorTemp_B_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SetColorTemp_Rgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetColorTemp_Rgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetColorTemp_Rgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetColorTemp_Rgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SetColorTemp_Ggain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetColorTemp_Ggain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetColorTemp_Ggain_onSource() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully GetColorTemp_Ggain_onSource  value once module is initialized
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** logs@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_Ggain_onSource() -  trying to Get ggain value with valid arguments after tvInit | colorTemp =0, &ggain, sourceOffset | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Ggain_onSource() -  trying to Get ggain value with valid arguments after tvInit | colorTemp =1, &ggain, sourceOffset | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_Ggain_onSource() -  trying to Get ggain value with valid arguments after tvInit | colorTemp =2, &ggain, sourceOffset | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_Ggain_onSource() -  trying to Get ggain value with valid arguments after tvInit | colorTemp =3, &ggain, sourceOffset | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_Ggain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetColorTemp_Ggain_onSource() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully GetColorTemp_Ggain_onSource  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** logs@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetColorTemp_Ggain_onSource() -  trying to Get ggain value ,even before tvInit | colorTemp =0, &ggain, sourceOffset | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Ggain_onSource() -  invoke to Get ggain value with invalid input of color temp| colorTemp >= 5, &ggain, sourceOffset  | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_Ggain_onSource() -  invoke to Get ggain value with invalid input address| colorTemp, &ggain = NULL, sourceOffset  | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_Ggain_onSource() -  invoke to Get ggain value with invalid input of source offset| colorTemp , &ggain, sourceOffset =-1 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call GetColorTemp_Ggain_onSource() -  invoke to Get ggain value with invalid inputs| colorTemp >= 5, &ggain = NULL, sourceOffset = -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 08 | call GetColorTemp_Ggain_onSource() -  trying to Get ggain value with valid arguments | colorTemp =0, &ggain, sourceOffset | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetColorTemp_Ggain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure SetColorTemp_Bgain_onSource() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully SetColorTemp_Bgain_onSource  value once module is initialized
* 3. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** logs@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_Bgain_onSource() -  trying to Set Bgain value with valid input arguments after tvInit | colorTemp =0, bgain = 1000, sourceOffset, saveOnly =0| tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Bgain_onSource() -  trying to Set Bgain value with valid input arguments after tvInit | colorTemp =1, bgain = 2000, sourceOffset, saveOnly =0| tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Bgain_onSource() -  trying to Set Bgain value with valid input arguments after tvInit | colorTemp =3, bgain = 2046, sourceOffset, saveOnly =0| tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_Bgain_onSource() -  trying to Set Bgain value with valid input arguments after tvInit | colorTemp =4, bgain = 1500, sourceOffset, saveOnly =0| tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_Bgain_onSource() -  trying to Set Bgain value with valid input arguments after tvInit | colorTemp =0, bgain = 1000, sourceOffset, saveOnly =1| tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_Bgain_onSource() -  trying to Set Bgain value with valid input arguments after tvInit | colorTemp =1, bgain = 2000, sourceOffset, saveOnly =1| tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_Bgain_onSource() -  trying to Set Bgain value with valid input arguments after tvInit | colorTemp =2, bgain = 2046, sourceOffset, saveOnly =1| tvERROR_NONE | Should Pass |
* | 09 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemp_Bgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure SetColorTemp_Bgain_onSource() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully SetColorTemp_Bgain_onSource  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** logs@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetColorTemp_Bgain_onSource() -  trying to Set Bgain,even before tvInit | colorTemp =0, bgain = 1000, sourceOffset, saveOnly =0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Bgain_onSource() -  invoke to Set Bgain with invalid input | colorTemp >= 5, bgain = 1000, sourceOffset, saveOnly =0| tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_Bgain_onSource() -  invoke to Set Bgain with invalid input | colorTemp = 0, bgain = -1, sourceOffset, saveOnly =0| tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_Bgain_onSource() -  invoke to Set Bgain with invalid input | colorTemp = 1, bgain = 2048, sourceOffset, saveOnly =0| tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_Bgain_onSource() -  invoke to Set Bgain with invalid input | colorTemp = 2, bgain = 1000, sourceOffset = -1, saveOnly =0| tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SetColorTemp_Bgain_onSource() -  invoke to Set Bgain with invalid input | colorTemp = 2, bgain = 1000, sourceOffset, saveOnly = 2| tvERROR_GENERAL | Should Pass |
* | 08 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 09 | call SetColorTemp_Bgain_onSource() -  trying to Set Bgain with valid arguments | colorTemp =0, bgain = 1000, sourceOffset, saveOnly =0| tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_Bgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetColorTemp_Bgain_onSource() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully GetColorTemp_Bgain_onSource  value once module is initialized
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** logs@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_Bgain_onSource() -  trying to Get bgain value with valid arguments after tvInit | colorTemp =0, &bgain, sourceOffset | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Bgain_onSource() -  trying to Get bgain value with valid arguments after tvInit | colorTemp =1, &bgain, sourceOffset | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_Bgain_onSource() -  trying to Get bgain value with valid arguments after tvInit | colorTemp =2, &bgain, sourceOffset | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_Bgain_onSource() -  trying to Get bgain value with valid arguments after tvInit | colorTemp =3, &bgain, sourceOffset | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_Bgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetColorTemp_Bgain_onSource() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully GetColorTemp_Bgain_onSource  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** logs@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetColorTemp_Bgain_onSource() -  trying to Get bgain value ,even before tvInit | colorTemp =0, &bgain, sourceOffset | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Bgain_onSource() -  invoke to Get bgain value with invalid input of color temp| colorTemp >= 5, &bgain, sourceOffset  | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_Bgain_onSource() -  invoke to Get bgain value with invalid input address| colorTemp, &bgain = NULL, sourceOffset  | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_Bgain_onSource() -  invoke to Get bgain value with invalid input of source offset| colorTemp , &bgain, sourceOffset =-1 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call GetColorTemp_Bgain_onSource() -  invoke to Get bgain value with invalid inputs| colorTemp >= 5, &bgain = NULL, sourceOffset = -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 08 | call GetColorTemp_Bgain_onSource() -  trying to Get bgain value with valid arguments | colorTemp =0, &bgain, sourceOffset | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetColorTemp_Bgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure SetColorTemp_R_post_offset_onSource() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully SetColorTemp_R_post_offset_onSource  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** logs@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_R_post_offset_onSource() -  trying to Set rpostoffset value with valid input arguments after tvInit | colorTemp =0, rpostoffset = -1024, sourceOffset, saveOnly =0| tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_R_post_offset_onSource() -  trying to Set rpostoffset value with valid input arguments after tvInit | colorTemp =1, rpostoffset = 1024, sourceOffset, saveOnly =0| tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_R_post_offset_onSource() -  trying to Set rpostoffset value with valid input arguments after tvInit | colorTemp =3, rpostoffset = 100, sourceOffset, saveOnly =0| tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_R_post_offset_onSource() -  trying to Set rpostoffset value with valid input arguments after tvInit | colorTemp =4, rpostoffset = 500, sourceOffset, saveOnly =0| tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_R_post_offset_onSource() -  trying to Set rpostoffset value with valid input arguments after tvInit | colorTemp =0, rpostoffset = 0, sourceOffset, saveOnly =1| tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_R_post_offset_onSource() -  trying to Set rpostoffset value with valid input arguments after tvInit | colorTemp =1, rpostoffset = -500, sourceOffset, saveOnly =1| tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_R_post_offset_onSource() -  trying to Set rpostoffset value with valid input arguments after tvInit | colorTemp =2, rpostoffset = -100, sourceOffset, saveOnly =1| tvERROR_NONE | Should Pass |
* | 09 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemp_R_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure SetColorTemp_R_post_offset_onSource() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully SetColorTemp_R_post_offset_onSource  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** logs@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetColorTemp_R_post_offset_onSource() -  trying to Set rpostoffset,even before tvInit | colorTemp =0, rpostoffset = 1000, sourceOffset, saveOnly =0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_R_post_offset_onSource() -  invoke to Set rpostoffset with invalid input | colorTemp >= 5, rpostoffset = 1000, sourceOffset, saveOnly =0| tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_R_post_offset_onSource() -  invoke to Set rpostoffset with invalid input | colorTemp = 0, rpostoffset = -1025, sourceOffset, saveOnly =0| tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_R_post_offset_onSource() -  invoke to Set rpostoffset with invalid input | colorTemp = 1, rpostoffset = 1025, sourceOffset, saveOnly =0| tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_R_post_offset_onSource() -  invoke to Set rpostoffset with invalid input | colorTemp = 2, rpostoffset = 1000, sourceOffset = -1, saveOnly =0| tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SetColorTemp_R_post_offset_onSource() -  invoke to Set rpostoffset with invalid input | colorTemp = 2, rpostoffset = 1000, sourceOffset, saveOnly = 2| tvERROR_GENERAL | Should Pass |
* | 08 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 09 | call SetColorTemp_R_post_offset_onSource() -  trying to Set rpostoffset with valid arguments | colorTemp =0, rpostoffset = 1000, sourceOffset, saveOnly =0| tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_R_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetColorTemp_R_post_offset_onSource() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully GetColorTemp_R_post_offset_onSource  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** logs@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetColorTemp_R_post_offset_onSource() -  trying to Get ColorTemp_R_post_offset_onSource ,even before tvInit | contrast | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_R_post_offset_onSource() -  invoke to Get ColorTemp_R_post_offset_onSource with invalid input | &contrast = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_R_post_offset_onSource() -  trying to Get ColorTemp_R_post_offset_onSource with valid arguments after tvInit | &contrast | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 06 | call GetColorTemp_R_post_offset_onSource() -  trying to Get ColorTemp_R_post_offset_onSource with valid arguments | &contrast  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_R_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetColorTemp_R_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure SetColorTemp_G_post_offset_onSource() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully SetColorTemp_G_post_offset_onSource  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** logs@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetColorTemp_G_post_offset_onSource() -  trying to Set ColorTemp_G_post_offset_onSource ,even before tvInit | contrast | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_G_post_offset_onSource() -  invoke to Set ColorTemp_G_post_offset_onSource with invalid input | &contrast = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_G_post_offset_onSource() -  trying to Set ColorTemp_G_post_offset_onSource with valid arguments after tvInit | &contrast | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_G_post_offset_onSource() -  trying to Set ColorTemp_G_post_offset_onSource with valid arguments | &contrast  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemp_G_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetColorTemp_G_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetColorTemp_G_post_offset_onSource() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully GetColorTemp_G_post_offset_onSource  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** logs@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetColorTemp_G_post_offset_onSource() -  trying to Get ColorTemp_G_post_offset_onSource ,even before tvInit | contrast | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_G_post_offset_onSource() -  invoke to Get ColorTemp_G_post_offset_onSource with invalid input | &contrast = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_G_post_offset_onSource() -  trying to Get ColorTemp_G_post_offset_onSource with valid arguments after tvInit | &contrast | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 06 | call GetColorTemp_G_post_offset_onSource() -  trying to Get ColorTemp_G_post_offset_onSource with valid arguments | &contrast  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_G_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetColorTemp_G_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure SetColorTemp_B_post_offset_onSource() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully SetColorTemp_B_post_offset_onSource  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** logs@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetColorTemp_B_post_offset_onSource() -  trying to Set ColorTemp_B_post_offset_onSource ,even before tvInit | contrast | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_B_post_offset_onSource() -  invoke to Set ColorTemp_B_post_offset_onSource with invalid input | &contrast = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_B_post_offset_onSource() -  trying to Set ColorTemp_B_post_offset_onSource with valid arguments after tvInit | &contrast | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_B_post_offset_onSource() -  trying to Set ColorTemp_B_post_offset_onSource with valid arguments | &contrast  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemp_B_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetColorTemp_B_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetColorTemp_B_post_offset_onSource() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully GetColorTemp_B_post_offset_onSource  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** logs@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetColorTemp_B_post_offset_onSource() -  trying to Get ColorTemp_G_post_offset_onSource ,even before tvInit | contrast | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_B_post_offset_onSource() -  invoke to Get GetColorTemp_B_post_offset_onSource with invalid input | &contrast = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_B_post_offset_onSource() -  trying to Get GetColorTemp_B_post_offset_onSource with valid arguments after tvInit | &contrast | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 06 | call GetColorTemp_B_post_offset_onSource() -  trying to Get GetColorTemp_B_post_offset_onSource with valid arguments | &contrast  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_B_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetColorTemp_B_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetTVSupportedPictureModes() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully GetTVSupportedPictureModes  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** logs@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetTVSupportedPictureModes() -  trying to Get TVSupportedPictureModes ,even before tvInit | contrast | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call GetTVSupportedPictureModes() -  invoke to Get TVSupportedPictureModes with invalid input | &contrast = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetTVSupportedPictureModes() -  trying to Get TVSupportedPictureModes with valid arguments after tvInit | &contrast | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 06 | call GetTVSupportedPictureModes() -  trying to Get TVSupportedPictureModes with valid arguments | &contrast  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_positive_GetTVSupportedPictureModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetTVSupportedPictureModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure GetTVSupportedDVModes() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully GetTVSupportedDVModes  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** logs@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetTVSupportedDVModes() -  trying to Get TVSupportedDVModes ,even before tvInit | contrast | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call GetTVSupportedDVModes() -  invoke to Get TVSupportedDVModes with invalid input | &contrast = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetTVSupportedDVModes() -  trying to Get TVSupportedDVModes with valid arguments after tvInit | &contrast | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 06 | call GetTVSupportedDVModes() -  trying to Get TVSupportedDVModes with valid arguments | &contrast  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_positive_GetTVSupportedDVModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetTVSupportedDVModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Ensure SetTVDolbyVisionMode() returns correct error codes, during all of this API's invocation scenarios
* 
* This test ensure following conditions:
* 1. Module invalid state error is returned if called without initialising
* 2. Able to successfully SetTVDolbyVisionMode  value once module is initialized
* 3. Passing invalid parameter excluding values between 0 and 100, returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns invalid state error.
*  tvERROR_GENERAL : is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** logs@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetTVDolbyVisionMode() -  trying to Set TVDolbyVisionMode ,even before tvInit | contrast | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and getInstance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 03 | call SetTVDolbyVisionMode() -  invoke to Set TVDolbyVisionMode with invalid input | &contrast = NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetTVDolbyVisionMode() -  trying to Set TVDolbyVisionMode with valid arguments after tvInit | &contrast | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  terminates and close Instance of Tvclient | void | tvERROR_NONE | Should Pass |
* | 06 | call SetTVDolbyVisionMode() -  trying to Set TVDolbyVisionMode with valid arguments | &contrast  | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_positive_SetTVDolbyVisionMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetTVDolbyVisionMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetTVDolbyVisionMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetTVDolbyVisionMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SetTVHLGMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetTVHLGMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SetTVHDR10Mode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetTVHDR10Mode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetTVSupportedHLGModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetTVSupportedHLGModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetTVSupportedHDR10Modes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetTVSupportedHDR10Modes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SetDynamicContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetDynamicContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetDynamicContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetDynamicContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_setWBctrl (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_setWBctrl (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_getWBctrl (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_getWBctrl (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_enableWBmode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_enableWBmode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetSupportedComponentColor (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetSupportedComponentColor (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SetCurrentComponentSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetCurrentComponentSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetCurrentComponentSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetCurrentComponentSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SetCurrentComponentHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetCurrentComponentHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetCurrentComponentHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetCurrentComponentHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SetCurrentComponentLuma (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetCurrentComponentLuma (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetCurrentComponentLuma (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetCurrentComponentLuma (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetTVSupportedDimmingModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetTVSupportedDimmingModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SetTVDimmingMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetTVDimmingMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SetTVBacklightGlobalFactor (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetTVBacklightGlobalFactor (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetTVBacklightGlobalFactor (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetTVBacklightGlobalFactor (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetTVPictureModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetTVPictureModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetCurrentContentFormat (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetCurrentContentFormat (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetSupportedContentFormats (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetSupportedContentFormats (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_isCurrentHDRTypeIsSDR (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_isCurrentHDRTypeIsSDR (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetPanelID (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetPanelID (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetDefaultPanelID (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetDefaultPanelID (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SaveColorTemperature (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SaveColorTemperature (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SaveBacklight (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SaveBacklight (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SaveContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SaveContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SaveSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SaveSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SaveSharpness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SaveSharpness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SaveBrightness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SaveBrightness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SaveHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SaveHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SaveDynamicBacklight (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SaveDynamicBacklight (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SaveDisplayMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SaveDisplayMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SaveCMS (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SaveCMS (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SaveDolbyMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SaveDolbyMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetNumberOfModesupported (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetNumberOfModesupported (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetCurrentPQIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetCurrentPQIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetAllSupportedPicModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetAllSupportedPicModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetCMSDefault (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetCMSDefault (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetDolbyModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetDolbyModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_ConvertVideoFormatToHDRFormat (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_ConvertVideoFormatToHDRFormat (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_ConvertTVColorToVendorColor (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_ConvertTVColorToVendorColor (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_ConvertHDRFormatToContentFormat (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_ConvertHDRFormatToContentFormat (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SetCMSState (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetCMSState (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_isWBUserDfault (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_isWBUserDfault (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetWBRgbType (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetWBRgbType (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetUSerWBValueOnInit (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetUSerWBValueOnInit (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_areEqual (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_areEqual (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SetColorTemperatureUser (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetColorTemperatureUser (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SaveColorTemperatureUser (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SaveColorTemperatureUser (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SetBacklightInfo (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetBacklightInfo (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetDriverEquivalentBLForCurrentFmt (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetDriverEquivalentBLForCurrentFmt (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetHLGModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetHLGModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetHDR10ModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetHDR10ModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SetBacklightFade (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetBacklightFade (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_ReadAllModeConfigfile (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_ReadAllModeConfigfile (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_splitstringsfrombuffer (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_splitstringsfrombuffer (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SetGammaMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetGammaMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SetLocalDimmingLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetLocalDimmingLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetLocalDimmingLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetLocalDimmingLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SaveLocalDimmingLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SaveLocalDimmingLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_UpdateEDIDAndSetDimmingLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_UpdateEDIDAndSetDimmingLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetLDIMAndEDIDLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetLDIMAndEDIDLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SaveLowLatencyState (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SaveLowLatencyState (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_SetLowLatencyState (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_SetLowLatencyState (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_positive_GetLowLatencyState (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief TODO: Describe the objective of the test
*
* TODO: Add the description of what is tested and why in this test@n
*
* **Test Group ID:** TODO: Basic (for L1): 01 / Module (L2): 02 / Stress (L2): 03)@n
* **Test Case ID:** TODO: Add the ID of the test case so that it can be logically tracked in the logs@n
* @n
* **Pre-Conditions:** TODO: Add pre-conditions, if any@n
* **Dependencies:** TODO: Add dependencies for this test, if any@n
* **User Interaction:** TODO: Add any user interactions required during this test, if any
* @n
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | First set of conditions | What is input data to be tested | How to gauge success, is it a success variable? | Should be successful |
*/
void test_l1_tvSettings_negative_GetLowLatencyState (void)
{
	UT_FAIL(This function needs to be implemented!); 
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

	UT_add_test( pSuite, "tvInit_L1_positive" ,test_l1_tvSettings_positive_tvInit );
	UT_add_test( pSuite, "tvInit_L1_negative" ,test_l1_tvSettings_negative_tvInit );
	UT_add_test( pSuite, "tvSD3toCriSyncInit_L1_positive" ,test_l1_tvSettings_positive_tvSD3toCriSyncInit );
	UT_add_test( pSuite, "tvSD3toCriSyncInit_L1_negative" ,test_l1_tvSettings_negative_tvSD3toCriSyncInit );
	UT_add_test( pSuite, "tvTerm_L1_positive" ,test_l1_tvSettings_positive_tvTerm );
	UT_add_test( pSuite, "tvTerm_L1_negative" ,test_l1_tvSettings_negative_tvTerm );
	UT_add_test( pSuite, "GetTVPictureMode_L1_positive" ,test_l1_tvSettings_positive_GetTVPictureMode );
	UT_add_test( pSuite, "GetTVPictureMode_L1_negative" ,test_l1_tvSettings_negative_GetTVPictureMode );
	UT_add_test( pSuite, "SetTVPictureMode_L1_positive" ,test_l1_tvSettings_positive_SetTVPictureMode );
	UT_add_test( pSuite, "SetTVPictureMode_L1_negative" ,test_l1_tvSettings_negative_SetTVPictureMode );
	UT_add_test( pSuite, "GetBacklight_L1_positive" ,test_l1_tvSettings_positive_GetBacklight );
	UT_add_test( pSuite, "GetBacklight_L1_negative" ,test_l1_tvSettings_negative_GetBacklight );
	UT_add_test( pSuite, "SetBacklight_L1_positive" ,test_l1_tvSettings_positive_SetBacklight );
	UT_add_test( pSuite, "SetBacklight_L1_negative" ,test_l1_tvSettings_negative_SetBacklight );
	UT_add_test( pSuite, "SetBrightness_L1_positive" ,test_l1_tvSettings_positive_SetBrightness );
	UT_add_test( pSuite, "SetBrightness_L1_negative" ,test_l1_tvSettings_negative_SetBrightness );
	UT_add_test( pSuite, "GetBrightness_L1_positive" ,test_l1_tvSettings_positive_GetBrightness );
	UT_add_test( pSuite, "GetBrightness_L1_negative" ,test_l1_tvSettings_negative_GetBrightness );
	UT_add_test( pSuite, "SetContrast_L1_positive" ,test_l1_tvSettings_positive_SetContrast );
	UT_add_test( pSuite, "SetContrast_L1_negative" ,test_l1_tvSettings_negative_SetContrast );
	UT_add_test( pSuite, "GetContrast_L1_positive" ,test_l1_tvSettings_positive_GetContrast );
	UT_add_test( pSuite, "GetContrast_L1_negative" ,test_l1_tvSettings_negative_GetContrast );
	UT_add_test( pSuite, "SetSharpness_L1_positive" ,test_l1_tvSettings_positive_SetSharpness );
	UT_add_test( pSuite, "SetSharpness_L1_negative" ,test_l1_tvSettings_negative_SetSharpness );
	UT_add_test( pSuite, "GetSharpness_L1_positive" ,test_l1_tvSettings_positive_GetSharpness );
	UT_add_test( pSuite, "GetSharpness_L1_negative" ,test_l1_tvSettings_negative_GetSharpness );
	UT_add_test( pSuite, "SetSaturation_L1_positive" ,test_l1_tvSettings_positive_SetSaturation );
	UT_add_test( pSuite, "SetSaturation_L1_negative" ,test_l1_tvSettings_negative_SetSaturation );
	UT_add_test( pSuite, "GetSaturation_L1_positive" ,test_l1_tvSettings_positive_GetSaturation );
	UT_add_test( pSuite, "GetSaturation_L1_negative" ,test_l1_tvSettings_negative_GetSaturation );
	UT_add_test( pSuite, "SetHue_L1_positive" ,test_l1_tvSettings_positive_SetHue );
	UT_add_test( pSuite, "SetHue_L1_negative" ,test_l1_tvSettings_negative_SetHue );
	UT_add_test( pSuite, "GetHue_L1_positive" ,test_l1_tvSettings_positive_GetHue );
	UT_add_test( pSuite, "GetHue_L1_negative" ,test_l1_tvSettings_negative_GetHue );
	UT_add_test( pSuite, "SetColorTemperature_L1_positive" ,test_l1_tvSettings_positive_SetColorTemperature );
	UT_add_test( pSuite, "SetColorTemperature_L1_negative" ,test_l1_tvSettings_negative_SetColorTemperature );
	UT_add_test( pSuite, "GetColorTemperature_L1_positive" ,test_l1_tvSettings_positive_GetColorTemperature );
	UT_add_test( pSuite, "GetColorTemperature_L1_negative" ,test_l1_tvSettings_negative_GetColorTemperature );
	UT_add_test( pSuite, "SetAspectRatio_L1_positive" ,test_l1_tvSettings_positive_SetAspectRatio );
	UT_add_test( pSuite, "SetAspectRatio_L1_negative" ,test_l1_tvSettings_negative_SetAspectRatio );
	UT_add_test( pSuite, "GetAspectRatio_L1_positive" ,test_l1_tvSettings_positive_GetAspectRatio );
	UT_add_test( pSuite, "GetAspectRatio_L1_negative" ,test_l1_tvSettings_negative_GetAspectRatio );
	UT_add_test( pSuite, "GetSupportedBacklightModes_L1_positive" ,test_l1_tvSettings_positive_GetSupportedBacklightModes );
	UT_add_test( pSuite, "GetSupportedBacklightModes_L1_negative" ,test_l1_tvSettings_negative_GetSupportedBacklightModes );
	UT_add_test( pSuite, "GetCurrentBacklightMode_L1_positive" ,test_l1_tvSettings_positive_GetCurrentBacklightMode );
	UT_add_test( pSuite, "GetCurrentBacklightMode_L1_negative" ,test_l1_tvSettings_negative_GetCurrentBacklightMode );
	UT_add_test( pSuite, "SetCurrentBacklightMode_L1_positive" ,test_l1_tvSettings_positive_SetCurrentBacklightMode );
	UT_add_test( pSuite, "SetCurrentBacklightMode_L1_negative" ,test_l1_tvSettings_negative_SetCurrentBacklightMode );
	UT_add_test( pSuite, "GetCurrentVideoFormat_L1_positive" ,test_l1_tvSettings_positive_GetCurrentVideoFormat );
	UT_add_test( pSuite, "GetCurrentVideoFormat_L1_negative" ,test_l1_tvSettings_negative_GetCurrentVideoFormat );
	UT_add_test( pSuite, "GetVideoResolution_L1_positive" ,test_l1_tvSettings_positive_GetVideoResolution );
	UT_add_test( pSuite, "GetVideoResolution_L1_negative" ,test_l1_tvSettings_negative_GetVideoResolution );
	UT_add_test( pSuite, "GetVideoFrameRate_L1_positive" ,test_l1_tvSettings_positive_GetVideoFrameRate );
	UT_add_test( pSuite, "GetVideoFrameRate_L1_negative" ,test_l1_tvSettings_negative_GetVideoFrameRate );
	UT_add_test( pSuite, "setWakeupConfig_L1_positive" ,test_l1_tvSettings_positive_setWakeupConfig );
	UT_add_test( pSuite, "setWakeupConfig_L1_negative" ,test_l1_tvSettings_negative_setWakeupConfig );
	UT_add_test( pSuite, "SetRGBPattern_L1_positive" ,test_l1_tvSettings_positive_SetRGBPattern );
	UT_add_test( pSuite, "SetRGBPattern_L1_negative" ,test_l1_tvSettings_negative_SetRGBPattern );
	UT_add_test( pSuite, "GetRGBPattern_L1_positive" ,test_l1_tvSettings_positive_GetRGBPattern );
	UT_add_test( pSuite, "GetRGBPattern_L1_negative" ,test_l1_tvSettings_negative_GetRGBPattern );
	UT_add_test( pSuite, "SetGrayPattern_L1_positive" ,test_l1_tvSettings_positive_SetGrayPattern );
	UT_add_test( pSuite, "SetGrayPattern_L1_negative" ,test_l1_tvSettings_negative_SetGrayPattern );
	UT_add_test( pSuite, "GetGrayPattern_L1_positive" ,test_l1_tvSettings_positive_GetGrayPattern );
	UT_add_test( pSuite, "GetGrayPattern_L1_negative" ,test_l1_tvSettings_negative_GetGrayPattern );
	UT_add_test( pSuite, "SetColorTemp_Rgain_L1_positive" ,test_l1_tvSettings_positive_SetColorTemp_Rgain );
	UT_add_test( pSuite, "SetColorTemp_Rgain_L1_negative" ,test_l1_tvSettings_negative_SetColorTemp_Rgain );
	UT_add_test( pSuite, "GetColorTemp_Rgain_L1_positive" ,test_l1_tvSettings_positive_GetColorTemp_Rgain );
	UT_add_test( pSuite, "GetColorTemp_Rgain_L1_negative" ,test_l1_tvSettings_negative_GetColorTemp_Rgain );
	UT_add_test( pSuite, "SetColorTemp_Ggain_L1_positive" ,test_l1_tvSettings_positive_SetColorTemp_Ggain );
	UT_add_test( pSuite, "SetColorTemp_Ggain_L1_negative" ,test_l1_tvSettings_negative_SetColorTemp_Ggain );
	UT_add_test( pSuite, "GetColorTemp_Ggain_L1_positive" ,test_l1_tvSettings_positive_GetColorTemp_Ggain );
	UT_add_test( pSuite, "GetColorTemp_Ggain_L1_negative" ,test_l1_tvSettings_negative_GetColorTemp_Ggain );
	UT_add_test( pSuite, "SetColorTemp_Bgain_L1_positive" ,test_l1_tvSettings_positive_SetColorTemp_Bgain );
	UT_add_test( pSuite, "SetColorTemp_Bgain_L1_negative" ,test_l1_tvSettings_negative_SetColorTemp_Bgain );
	UT_add_test( pSuite, "GetColorTemp_Bgain_L1_positive" ,test_l1_tvSettings_positive_GetColorTemp_Bgain );
	UT_add_test( pSuite, "GetColorTemp_Bgain_L1_negative" ,test_l1_tvSettings_negative_GetColorTemp_Bgain );
	UT_add_test( pSuite, "SetColorTemp_R_post_offset_L1_positive" ,test_l1_tvSettings_positive_SetColorTemp_R_post_offset );
	UT_add_test( pSuite, "SetColorTemp_R_post_offset_L1_negative" ,test_l1_tvSettings_negative_SetColorTemp_R_post_offset );
	UT_add_test( pSuite, "GetColorTemp_R_post_offset_L1_positive" ,test_l1_tvSettings_positive_GetColorTemp_R_post_offset );
	UT_add_test( pSuite, "GetColorTemp_R_post_offset_L1_negative" ,test_l1_tvSettings_negative_GetColorTemp_R_post_offset );
	UT_add_test( pSuite, "SetColorTemp_G_post_offset_L1_positive" ,test_l1_tvSettings_positive_SetColorTemp_G_post_offset );
	UT_add_test( pSuite, "SetColorTemp_G_post_offset_L1_negative" ,test_l1_tvSettings_negative_SetColorTemp_G_post_offset );
	UT_add_test( pSuite, "GetColorTemp_G_post_offset_L1_positive" ,test_l1_tvSettings_positive_GetColorTemp_G_post_offset );
	UT_add_test( pSuite, "GetColorTemp_G_post_offset_L1_negative" ,test_l1_tvSettings_negative_GetColorTemp_G_post_offset );
	UT_add_test( pSuite, "SetColorTemp_B_post_offset_L1_positive" ,test_l1_tvSettings_positive_SetColorTemp_B_post_offset );
	UT_add_test( pSuite, "SetColorTemp_B_post_offset_L1_negative" ,test_l1_tvSettings_negative_SetColorTemp_B_post_offset );
	UT_add_test( pSuite, "GetColorTemp_B_post_offset_L1_positive" ,test_l1_tvSettings_positive_GetColorTemp_B_post_offset );
	UT_add_test( pSuite, "GetColorTemp_B_post_offset_L1_negative" ,test_l1_tvSettings_negative_GetColorTemp_B_post_offset );
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
	UT_add_test( pSuite, "GetTVSupportedPictureModes_L1_positive" ,test_l1_tvSettings_positive_GetTVSupportedPictureModes );
	UT_add_test( pSuite, "GetTVSupportedPictureModes_L1_negative" ,test_l1_tvSettings_negative_GetTVSupportedPictureModes );
	UT_add_test( pSuite, "GetTVSupportedDVModes_L1_positive" ,test_l1_tvSettings_positive_GetTVSupportedDVModes );
	UT_add_test( pSuite, "GetTVSupportedDVModes_L1_negative" ,test_l1_tvSettings_negative_GetTVSupportedDVModes );
	UT_add_test( pSuite, "SetTVDolbyVisionMode_L1_positive" ,test_l1_tvSettings_positive_SetTVDolbyVisionMode );
	UT_add_test( pSuite, "SetTVDolbyVisionMode_L1_negative" ,test_l1_tvSettings_negative_SetTVDolbyVisionMode );
	UT_add_test( pSuite, "GetTVDolbyVisionMode_L1_positive" ,test_l1_tvSettings_positive_GetTVDolbyVisionMode );
	UT_add_test( pSuite, "GetTVDolbyVisionMode_L1_negative" ,test_l1_tvSettings_negative_GetTVDolbyVisionMode );
	UT_add_test( pSuite, "SetTVHLGMode_L1_positive" ,test_l1_tvSettings_positive_SetTVHLGMode );
	UT_add_test( pSuite, "SetTVHLGMode_L1_negative" ,test_l1_tvSettings_negative_SetTVHLGMode );
	UT_add_test( pSuite, "SetTVHDR10Mode_L1_positive" ,test_l1_tvSettings_positive_SetTVHDR10Mode );
	UT_add_test( pSuite, "SetTVHDR10Mode_L1_negative" ,test_l1_tvSettings_negative_SetTVHDR10Mode );
	UT_add_test( pSuite, "GetTVSupportedHLGModes_L1_positive" ,test_l1_tvSettings_positive_GetTVSupportedHLGModes );
	UT_add_test( pSuite, "GetTVSupportedHLGModes_L1_negative" ,test_l1_tvSettings_negative_GetTVSupportedHLGModes );
	UT_add_test( pSuite, "GetTVSupportedHDR10Modes_L1_positive" ,test_l1_tvSettings_positive_GetTVSupportedHDR10Modes );
	UT_add_test( pSuite, "GetTVSupportedHDR10Modes_L1_negative" ,test_l1_tvSettings_negative_GetTVSupportedHDR10Modes );
	UT_add_test( pSuite, "SetDynamicContrast_L1_positive" ,test_l1_tvSettings_positive_SetDynamicContrast );
	UT_add_test( pSuite, "SetDynamicContrast_L1_negative" ,test_l1_tvSettings_negative_SetDynamicContrast );
	UT_add_test( pSuite, "GetDynamicContrast_L1_positive" ,test_l1_tvSettings_positive_GetDynamicContrast );
	UT_add_test( pSuite, "GetDynamicContrast_L1_negative" ,test_l1_tvSettings_negative_GetDynamicContrast );
	UT_add_test( pSuite, "setWBctrl_L1_positive" ,test_l1_tvSettings_positive_setWBctrl );
	UT_add_test( pSuite, "setWBctrl_L1_negative" ,test_l1_tvSettings_negative_setWBctrl );
	UT_add_test( pSuite, "getWBctrl_L1_positive" ,test_l1_tvSettings_positive_getWBctrl );
	UT_add_test( pSuite, "getWBctrl_L1_negative" ,test_l1_tvSettings_negative_getWBctrl );
	UT_add_test( pSuite, "enableWBmode_L1_positive" ,test_l1_tvSettings_positive_enableWBmode );
	UT_add_test( pSuite, "enableWBmode_L1_negative" ,test_l1_tvSettings_negative_enableWBmode );
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
	UT_add_test( pSuite, "GetTVSupportedDimmingModes_L1_positive" ,test_l1_tvSettings_positive_GetTVSupportedDimmingModes );
	UT_add_test( pSuite, "GetTVSupportedDimmingModes_L1_negative" ,test_l1_tvSettings_negative_GetTVSupportedDimmingModes );
	UT_add_test( pSuite, "SetTVDimmingMode_L1_positive" ,test_l1_tvSettings_positive_SetTVDimmingMode );
	UT_add_test( pSuite, "SetTVDimmingMode_L1_negative" ,test_l1_tvSettings_negative_SetTVDimmingMode );
	UT_add_test( pSuite, "SetTVBacklightGlobalFactor_L1_positive" ,test_l1_tvSettings_positive_SetTVBacklightGlobalFactor );
	UT_add_test( pSuite, "SetTVBacklightGlobalFactor_L1_negative" ,test_l1_tvSettings_negative_SetTVBacklightGlobalFactor );
	UT_add_test( pSuite, "GetTVBacklightGlobalFactor_L1_positive" ,test_l1_tvSettings_positive_GetTVBacklightGlobalFactor );
	UT_add_test( pSuite, "GetTVBacklightGlobalFactor_L1_negative" ,test_l1_tvSettings_negative_GetTVBacklightGlobalFactor );
	UT_add_test( pSuite, "GetTVPictureModeIndex_L1_positive" ,test_l1_tvSettings_positive_GetTVPictureModeIndex );
	UT_add_test( pSuite, "GetTVPictureModeIndex_L1_negative" ,test_l1_tvSettings_negative_GetTVPictureModeIndex );
	UT_add_test( pSuite, "GetCurrentContentFormat_L1_positive" ,test_l1_tvSettings_positive_GetCurrentContentFormat );
	UT_add_test( pSuite, "GetCurrentContentFormat_L1_negative" ,test_l1_tvSettings_negative_GetCurrentContentFormat );
	UT_add_test( pSuite, "GetSupportedContentFormats_L1_positive" ,test_l1_tvSettings_positive_GetSupportedContentFormats );
	UT_add_test( pSuite, "GetSupportedContentFormats_L1_negative" ,test_l1_tvSettings_negative_GetSupportedContentFormats );
	UT_add_test( pSuite, "isCurrentHDRTypeIsSDR_L1_positive" ,test_l1_tvSettings_positive_isCurrentHDRTypeIsSDR );
	UT_add_test( pSuite, "isCurrentHDRTypeIsSDR_L1_negative" ,test_l1_tvSettings_negative_isCurrentHDRTypeIsSDR );
	UT_add_test( pSuite, "GetPanelID_L1_positive" ,test_l1_tvSettings_positive_GetPanelID );
	UT_add_test( pSuite, "GetPanelID_L1_negative" ,test_l1_tvSettings_negative_GetPanelID );
	UT_add_test( pSuite, "GetDefaultPanelID_L1_positive" ,test_l1_tvSettings_positive_GetDefaultPanelID );
	UT_add_test( pSuite, "GetDefaultPanelID_L1_negative" ,test_l1_tvSettings_negative_GetDefaultPanelID );
	UT_add_test( pSuite, "SaveColorTemperature_L1_positive" ,test_l1_tvSettings_positive_SaveColorTemperature );
	UT_add_test( pSuite, "SaveColorTemperature_L1_negative" ,test_l1_tvSettings_negative_SaveColorTemperature );
	UT_add_test( pSuite, "SaveBacklight_L1_positive" ,test_l1_tvSettings_positive_SaveBacklight );
	UT_add_test( pSuite, "SaveBacklight_L1_negative" ,test_l1_tvSettings_negative_SaveBacklight );
	UT_add_test( pSuite, "SaveContrast_L1_positive" ,test_l1_tvSettings_positive_SaveContrast );
	UT_add_test( pSuite, "SaveContrast_L1_negative" ,test_l1_tvSettings_negative_SaveContrast );
	UT_add_test( pSuite, "SaveSaturation_L1_positive" ,test_l1_tvSettings_positive_SaveSaturation );
	UT_add_test( pSuite, "SaveSaturation_L1_negative" ,test_l1_tvSettings_negative_SaveSaturation );
	UT_add_test( pSuite, "SaveSharpness_L1_positive" ,test_l1_tvSettings_positive_SaveSharpness );
	UT_add_test( pSuite, "SaveSharpness_L1_negative" ,test_l1_tvSettings_negative_SaveSharpness );
	UT_add_test( pSuite, "SaveBrightness_L1_positive" ,test_l1_tvSettings_positive_SaveBrightness );
	UT_add_test( pSuite, "SaveBrightness_L1_negative" ,test_l1_tvSettings_negative_SaveBrightness );
	UT_add_test( pSuite, "SaveHue_L1_positive" ,test_l1_tvSettings_positive_SaveHue );
	UT_add_test( pSuite, "SaveHue_L1_negative" ,test_l1_tvSettings_negative_SaveHue );
	UT_add_test( pSuite, "SaveDynamicBacklight_L1_positive" ,test_l1_tvSettings_positive_SaveDynamicBacklight );
	UT_add_test( pSuite, "SaveDynamicBacklight_L1_negative" ,test_l1_tvSettings_negative_SaveDynamicBacklight );
	UT_add_test( pSuite, "SaveDisplayMode_L1_positive" ,test_l1_tvSettings_positive_SaveDisplayMode );
	UT_add_test( pSuite, "SaveDisplayMode_L1_negative" ,test_l1_tvSettings_negative_SaveDisplayMode );
	UT_add_test( pSuite, "SaveCMS_L1_positive" ,test_l1_tvSettings_positive_SaveCMS );
	UT_add_test( pSuite, "SaveCMS_L1_negative" ,test_l1_tvSettings_negative_SaveCMS );
	UT_add_test( pSuite, "SaveDolbyMode_L1_positive" ,test_l1_tvSettings_positive_SaveDolbyMode );
	UT_add_test( pSuite, "SaveDolbyMode_L1_negative" ,test_l1_tvSettings_negative_SaveDolbyMode );
	UT_add_test( pSuite, "GetNumberOfModesupported_L1_positive" ,test_l1_tvSettings_positive_GetNumberOfModesupported );
	UT_add_test( pSuite, "GetNumberOfModesupported_L1_negative" ,test_l1_tvSettings_negative_GetNumberOfModesupported );
	UT_add_test( pSuite, "GetCurrentPQIndex_L1_positive" ,test_l1_tvSettings_positive_GetCurrentPQIndex );
	UT_add_test( pSuite, "GetCurrentPQIndex_L1_negative" ,test_l1_tvSettings_negative_GetCurrentPQIndex );
	UT_add_test( pSuite, "GetAllSupportedPicModeIndex_L1_positive" ,test_l1_tvSettings_positive_GetAllSupportedPicModeIndex );
	UT_add_test( pSuite, "GetAllSupportedPicModeIndex_L1_negative" ,test_l1_tvSettings_negative_GetAllSupportedPicModeIndex );
	UT_add_test( pSuite, "GetCMSDefault_L1_positive" ,test_l1_tvSettings_positive_GetCMSDefault );
	UT_add_test( pSuite, "GetCMSDefault_L1_negative" ,test_l1_tvSettings_negative_GetCMSDefault );
	UT_add_test( pSuite, "GetDolbyModeIndex_L1_positive" ,test_l1_tvSettings_positive_GetDolbyModeIndex );
	UT_add_test( pSuite, "GetDolbyModeIndex_L1_negative" ,test_l1_tvSettings_negative_GetDolbyModeIndex );
	UT_add_test( pSuite, "ConvertVideoFormatToHDRFormat_L1_positive" ,test_l1_tvSettings_positive_ConvertVideoFormatToHDRFormat );
	UT_add_test( pSuite, "ConvertVideoFormatToHDRFormat_L1_negative" ,test_l1_tvSettings_negative_ConvertVideoFormatToHDRFormat );
	UT_add_test( pSuite, "ConvertTVColorToVendorColor_L1_positive" ,test_l1_tvSettings_positive_ConvertTVColorToVendorColor );
	UT_add_test( pSuite, "ConvertTVColorToVendorColor_L1_negative" ,test_l1_tvSettings_negative_ConvertTVColorToVendorColor );
	UT_add_test( pSuite, "ConvertHDRFormatToContentFormat_L1_positive" ,test_l1_tvSettings_positive_ConvertHDRFormatToContentFormat );
	UT_add_test( pSuite, "ConvertHDRFormatToContentFormat_L1_negative" ,test_l1_tvSettings_negative_ConvertHDRFormatToContentFormat );
	UT_add_test( pSuite, "SetCMSState_L1_positive" ,test_l1_tvSettings_positive_SetCMSState );
	UT_add_test( pSuite, "SetCMSState_L1_negative" ,test_l1_tvSettings_negative_SetCMSState );
	UT_add_test( pSuite, "isWBUserDfault_L1_positive" ,test_l1_tvSettings_positive_isWBUserDfault );
	UT_add_test( pSuite, "isWBUserDfault_L1_negative" ,test_l1_tvSettings_negative_isWBUserDfault );
	UT_add_test( pSuite, "GetWBRgbType_L1_positive" ,test_l1_tvSettings_positive_GetWBRgbType );
	UT_add_test( pSuite, "GetWBRgbType_L1_negative" ,test_l1_tvSettings_negative_GetWBRgbType );
	UT_add_test( pSuite, "GetUSerWBValueOnInit_L1_positive" ,test_l1_tvSettings_positive_GetUSerWBValueOnInit );
	UT_add_test( pSuite, "GetUSerWBValueOnInit_L1_negative" ,test_l1_tvSettings_negative_GetUSerWBValueOnInit );
	UT_add_test( pSuite, "areEqual_L1_positive" ,test_l1_tvSettings_positive_areEqual );
	UT_add_test( pSuite, "areEqual_L1_negative" ,test_l1_tvSettings_negative_areEqual );
	UT_add_test( pSuite, "SetColorTemperatureUser_L1_positive" ,test_l1_tvSettings_positive_SetColorTemperatureUser );
	UT_add_test( pSuite, "SetColorTemperatureUser_L1_negative" ,test_l1_tvSettings_negative_SetColorTemperatureUser );
	UT_add_test( pSuite, "SaveColorTemperatureUser_L1_positive" ,test_l1_tvSettings_positive_SaveColorTemperatureUser );
	UT_add_test( pSuite, "SaveColorTemperatureUser_L1_negative" ,test_l1_tvSettings_negative_SaveColorTemperatureUser );
	UT_add_test( pSuite, "SetBacklightInfo_L1_positive" ,test_l1_tvSettings_positive_SetBacklightInfo );
	UT_add_test( pSuite, "SetBacklightInfo_L1_negative" ,test_l1_tvSettings_negative_SetBacklightInfo );
	UT_add_test( pSuite, "GetDriverEquivalentBLForCurrentFmt_L1_positive" ,test_l1_tvSettings_positive_GetDriverEquivalentBLForCurrentFmt );
	UT_add_test( pSuite, "GetDriverEquivalentBLForCurrentFmt_L1_negative" ,test_l1_tvSettings_negative_GetDriverEquivalentBLForCurrentFmt );
	UT_add_test( pSuite, "GetHLGModeIndex_L1_positive" ,test_l1_tvSettings_positive_GetHLGModeIndex );
	UT_add_test( pSuite, "GetHLGModeIndex_L1_negative" ,test_l1_tvSettings_negative_GetHLGModeIndex );
	UT_add_test( pSuite, "GetHDR10ModeIndex_L1_positive" ,test_l1_tvSettings_positive_GetHDR10ModeIndex );
	UT_add_test( pSuite, "GetHDR10ModeIndex_L1_negative" ,test_l1_tvSettings_negative_GetHDR10ModeIndex );
	UT_add_test( pSuite, "SetBacklightFade_L1_positive" ,test_l1_tvSettings_positive_SetBacklightFade );
	UT_add_test( pSuite, "SetBacklightFade_L1_negative" ,test_l1_tvSettings_negative_SetBacklightFade );
	UT_add_test( pSuite, "ReadAllModeConfigfile_L1_positive" ,test_l1_tvSettings_positive_ReadAllModeConfigfile );
	UT_add_test( pSuite, "ReadAllModeConfigfile_L1_negative" ,test_l1_tvSettings_negative_ReadAllModeConfigfile );
	UT_add_test( pSuite, "splitstringsfrombuffer_L1_positive" ,test_l1_tvSettings_positive_splitstringsfrombuffer );
	UT_add_test( pSuite, "splitstringsfrombuffer_L1_negative" ,test_l1_tvSettings_negative_splitstringsfrombuffer );
	UT_add_test( pSuite, "SetGammaMode_L1_positive" ,test_l1_tvSettings_positive_SetGammaMode );
	UT_add_test( pSuite, "SetGammaMode_L1_negative" ,test_l1_tvSettings_negative_SetGammaMode );
	UT_add_test( pSuite, "SetLocalDimmingLevel_L1_positive" ,test_l1_tvSettings_positive_SetLocalDimmingLevel );
	UT_add_test( pSuite, "SetLocalDimmingLevel_L1_negative" ,test_l1_tvSettings_negative_SetLocalDimmingLevel );
	UT_add_test( pSuite, "GetLocalDimmingLevel_L1_positive" ,test_l1_tvSettings_positive_GetLocalDimmingLevel );
	UT_add_test( pSuite, "GetLocalDimmingLevel_L1_negative" ,test_l1_tvSettings_negative_GetLocalDimmingLevel );
	UT_add_test( pSuite, "SaveLocalDimmingLevel_L1_positive" ,test_l1_tvSettings_positive_SaveLocalDimmingLevel );
	UT_add_test( pSuite, "SaveLocalDimmingLevel_L1_negative" ,test_l1_tvSettings_negative_SaveLocalDimmingLevel );
	UT_add_test( pSuite, "UpdateEDIDAndSetDimmingLevel_L1_positive" ,test_l1_tvSettings_positive_UpdateEDIDAndSetDimmingLevel );
	UT_add_test( pSuite, "UpdateEDIDAndSetDimmingLevel_L1_negative" ,test_l1_tvSettings_negative_UpdateEDIDAndSetDimmingLevel );
	UT_add_test( pSuite, "GetLDIMAndEDIDLevel_L1_positive" ,test_l1_tvSettings_positive_GetLDIMAndEDIDLevel );
	UT_add_test( pSuite, "GetLDIMAndEDIDLevel_L1_negative" ,test_l1_tvSettings_negative_GetLDIMAndEDIDLevel );
	UT_add_test( pSuite, "SaveLowLatencyState_L1_positive" ,test_l1_tvSettings_positive_SaveLowLatencyState );
	UT_add_test( pSuite, "SaveLowLatencyState_L1_negative" ,test_l1_tvSettings_negative_SaveLowLatencyState );
	UT_add_test( pSuite, "SetLowLatencyState_L1_positive" ,test_l1_tvSettings_positive_SetLowLatencyState );
	UT_add_test( pSuite, "SetLowLatencyState_L1_negative" ,test_l1_tvSettings_negative_SetLowLatencyState );
	UT_add_test( pSuite, "GetLowLatencyState_L1_positive" ,test_l1_tvSettings_positive_GetLowLatencyState );
	UT_add_test( pSuite, "GetLowLatencyState_L1_negative" ,test_l1_tvSettings_negative_GetLowLatencyState );
	

	return 0;
} 
