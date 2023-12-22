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
	UT_FAIL(This function needs to be implemented!); 
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
* @post Close the module using tvTerm()
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
	UT_FAIL(This function needs to be implemented!); 
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
	UT_FAIL(This function needs to be implemented!); 
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
void test_l1_tvSettings_positive_GetSupportedVideoFormatsODM (void)
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
void test_l1_tvSettings_negative_GetSupportedVideoFormatsODM (void)
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
void test_l1_tvSettings_positive_GetTVSupportedVideoFormats (void)
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
void test_l1_tvSettings_negative_GetTVSupportedVideoFormats (void)
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
void test_l1_tvSettings_positive_GetCurrentVideoFormatODM (void)
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
void test_l1_tvSettings_negative_GetCurrentVideoFormatODM (void)
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
void test_l1_tvSettings_positive_GetCurrentVideoResolution (void)
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
void test_l1_tvSettings_negative_GetCurrentVideoResolution (void)
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
void test_l1_tvSettings_positive_GetCurrentVideoFrameRate (void)
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
void test_l1_tvSettings_negative_GetCurrentVideoFrameRate (void)
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
void test_l1_tvSettings_positive_GetCurrentVideoSource (void)
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
void test_l1_tvSettings_negative_GetCurrentVideoSource (void)
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
void test_l1_tvSettings_positive_GetTVSupportedVideoSources (void)
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
void test_l1_tvSettings_negative_GetTVSupportedVideoSources (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetBacklight() for all positive invocation scenarios
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
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetBacklight() -  Retrieve the current Backlight with valid argument |int *| tvERROR_NONE | Should Pass |
* | 03 | call GetBacklight() -  Retrieve the current Backlight with valid argument and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetBacklight (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetBacklight() for all negative invocation scenarios
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
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
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetBacklight() -   Retrieve current TV backlight even before TvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetTVBacklight() -  Retrieve current TV backlight with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetBacklight() -  Retrieve current TV backlight valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetBacklight (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetBacklight() for all positive invocation scenarios
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
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
	UT_FAIL(This function needs to be implemented!); 
}

/** 
* @brief Validate SetBacklight() for all negative invocation scenarios
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
* @brief Validate SetBacklightFade() for all positive invocation scenarios
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
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetBacklightFade() -  Set the BacklightFade with valid inputs | 0, 0, 0 | tvERROR_NONE| Should Pass|
* | 03 | call SetBacklightFade() -  Set the BacklightFade with valid inputs | 50, 50, 5000 | tvERROR_NONE| Should Pass|
* | 04 | call SetBacklightFade() -  Set the BacklightFade with valid inputs | 100, 100, 10000 | tvERROR_NONE| Should Pass|
* | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetBacklightFade (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetBacklightFade() for all negative invocation scenarios
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
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetBacklightFade() - Set the TV  Backlight Fade value even before TvInit() | int, int, int | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetBacklightFade() -   Set the TV  Backlight Fade value with invalid input | -1, -1, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetBacklightFade() -   Set the TV  Backlight Fade value with invalid input | 101, 101, 100001 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call SetBacklightFade() -  Set the TV  Backlight Fade value with valid input after TvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
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
void test_l1_tvSettings_positive_GetDriverEquivalentBLForCurrentFmtODM (void)
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
void test_l1_tvSettings_negative_GetDriverEquivalentBLForCurrentFmtODM (void)
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
void test_l1_tvSettings_positive_SetBacklightInfoODM (void)
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
void test_l1_tvSettings_negative_SetBacklightInfoODM (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
	UT_FAIL(This function needs to be implemented!); 
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
* | 03 | call GetSupportedBacklightModes() -  Retrieve supported Backlight modes with invalid input | NULL | tvERROR_INVALID_PARAM |
* | 04 | call GetSupportedBacklightModes() -  Retrieve supported Backlight modes modes with valid inputs and validate backlightmodes by looping through the test specific config file values | int * | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call GetSupportedBacklightModes() -  Retrieve current TV SupportedBacklightModes valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetSupportedBacklightModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 02 | call GetCurrentBacklightMode() -  Retrieve the CurrentBacklightMode and validate CurrentBacklightMode by looping through the test specific config file values | tvBacklightMode_t *  | tvERROR_NONE | Should Pass |
* | 03 | call GetCurrentBacklightMode() -  Retrieve the CurrentBacklightMode with valid argument and validate with above value | tvBacklightMode_t * | tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetCurrentBacklightMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 03 | call GetCurrentBacklightMode() -  Retrieve TV current Backlight modes with invalid input | NULL | tvERROR_INVALID_PARAM |
* | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetCurrentBacklightMode() -  Retrieve current TV CurrentBacklightMode valid arguments | tvBacklightMode_t * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetCurrentBacklightMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 02 | call SetCurrentBacklightMode() -  Set the TV Current Baklight mode by looping through all the values of backlight modes from the test specific config file | const char * | tvERROR_NONE | Should Pass |
* | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetCurrentBacklightMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 04 | call SetCurrentBacklightMode() -   Set the TV CurrentBacklightMode with less than the lower range  | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetCurrentBacklightMode() -   Set the TV CurrentBacklightMode with invalid parameter of all possible combinations  | (tvBacklightMode_t| tvBacklightMode_t) | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetCurrentBacklightMode() -   Set the TV CurrentBacklightMode with valid value but not supported by the platform by looping through the test specific config file  | tvBacklightMode_t | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SetCurrentBacklightMode() -  Set the TV CurrentBacklightMode with valid input after TvTerm() | tvBacklightMode_MANUAL | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetCurrentBacklightMode (void)
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
void test_l1_tvSettings_positive_GetTVSupportedDimmingModesODM (void)
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
void test_l1_tvSettings_negative_GetTVSupportedDimmingModesODM (void)
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
* | 02 | call SetTVDimmingMode() -  Set the TV dimming mode by looping through all the values of dimming modes from the test specific config file | const char * | tvERROR_NONE | Should Pass |
* | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetTVDimmingMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 01 | call SetTVDimmingMode() -  Set TV Dimming Mode even before TvInit() | const char * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetTVDimmingMode() -   Set TV Dimming Mode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetTVDimmingMode() -   Set TV Dimming Mode with valid value but not supported by the platform by looping through the test specific config file | const char * | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SetTVDimmingMode() -  Set TV Dimming Mode valid arguments | const char * | tvERROR_INVALID_STATE | Should Pass |
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
void test_l1_tvSettings_positive_GetTVDimmingMode (void)
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
void test_l1_tvSettings_negative_GetTVDimmingMode (void)
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
* | 05 | call SetBrightness() -  Reset the brightness with another valid value | 100 | tvERROR_NONE | Should Pass |
* | 06 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetBrightness (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
	UT_FAIL(This function needs to be implemented!); 
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
* | 02 | call GetBrightness() -  Retrieve the current brightness with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -  Retrieve the current brightness with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetBrightness (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 03 | call GetTVBrightness() -  Retrieve current TV brightness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetBrightness() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetBrightness (void)
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
* | 05 | call SetContrast() -  Reset the Contrast with another valid value | 100 | tvERROR_NONE | Should Pass |
* | 06 | call TvTerm() -  Terminate and close the instance of the TV client  | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
	UT_FAIL(This function needs to be implemented!); 
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
* | 02 | call GetContrast() -  Retrieve the current Contrast with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetContrast() -  Retrieve the current Contrast with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 03 | call GetTVContrast() -  Retrieve current TV Contrast with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetContrast() -  Retrieve current TV contrast valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetContrast (void)
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
* | 05 | call SetSharpness() -  Reset the sharpness with another valid value | 100 | tvERROR_NONE | Should Pass |
* | 06 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetSharpness (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
	UT_FAIL(This function needs to be implemented!); 
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
* | 02 | call GetSharpness() -  Retrieve the current sharpness with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetSharpness() -  Retrieve the current sharpness with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetSharpness (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 03 | call GetTVSharpness() -  Retrieve current TV Sharpness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetSharpness() -  Retrieve current TV sharpness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetSharpness (void)
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
* | 05 | call SetSaturation() -  Reset the saturation with another valid value | 100 | tvERROR_NONE | Should Pass |
* | 06 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 03 | call SetSaturation() -   Set the TV saturation with max range | 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetSaturation() -   Set the TV saturation with max range | 200 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SetSaturation() -  Set the TV saturation with valid input after TvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 02 | call GetSaturation() -  Retrieve the current saturation with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetSaturation() -  Retrieve the current saturation with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 03 | call GetTVSaturation() -  Retrieve current TV Saturation with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetSaturation() -  Retrieve current TV saturation valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetSaturation (void)
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
* | 05 | call SetHue() -  Reset the hue with another valid value | 100 | tvERROR_NONE | Should Pass |
* | 06 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
	UT_FAIL(This function needs to be implemented!); 
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
* | 02 | call GetHue() -  Retrieve the current Hue with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetHue() -  Retrieve the current Hue with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 03 | call GetHue() -  Retrieve current TV Hue with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetHue() -  Retrieve current TV Hue valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetHue (void)
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
* | 02 | call SetColorTemperature() -  Set the TV ColorTemperature by looping through all the values of ColorTemperatures from the test specific config file | const char * | tvERROR_NONE | Should Pass |
* | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemperature (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 05 | call SetColorTemperature() -   Set the TV ColorTemperature with invalid parameter of all possible combinations | (tvColorTemp_t | tvColorTemp_t) | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemperature() -   Set the TV ColorTemperature with valid value but not supported by the platform by looping through the test specific config file | tvColorTemp_t | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemperature() -  Set the TV ColorTemperature with valid input after TvTerm() | tvColorTemp_t | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemperature (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 02 | call GetColorTemperature() -  Retrieve the current ColorTemperature and validate ColorTemperature by looping through the test specific config file values | tvColorTemp_t *  | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemperature() -  Retrieve the current ColorTemperature with valid argument and validate with above value | tvColorTemp_t * | tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemperature (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 03 | call GetTVColorTemperature() -  Retrieve current TV ColorTemperature with invalid input | NULL | tvERROR_INVALID_PARAM |
* | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemperature() -  Retrieve current TV ColorTemperature valid arguments | tvColorTemp_t  * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetColorTemperature (void)
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
* | 02 | call SetAspectRatio() -  Set the TV Aspect ratio by looping through all the values of aspect ratios from the test specific config file | const char * | tvERROR_NONE | Should Pass |
* | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetAspectRatio (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 03 | call SetAspectRatio() -  Set the TV Aspect ratio with invalid input | -1 | tvERROR_INVALID_PARAM |
* | 04 | call SetAspectRatio() -  Set the TV Aspect ratio with invalid input | tvDisplayMode_MAX | tvERROR_INVALID_PARAM |
* | 05 | call SetAspectRatio() -   Set the TV Aspect ratio with invalid parameter of all possible combinations | (tvDisplayMode_t | tvDisplayMode_t) | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetAspectRatio() -   Set the TV Aspect ratio with valid value but not supported by the platform by looping through the test specific config file | tvDisplayMode_t  | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SetAspectRatio() -  Set the TV AspectRatio with valid input after TvTerm() | tvDisplayMode_16x9 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetAspectRatio (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 02 | call GetAspectRatio() -  Retrieve the current AspectRatio and validate AspectRatio by looping through the test specific config file values | tvDisplayMode_t *  | tvERROR_NONE | Should Pass |
* | 03 | call GetAspectRatio() -  Retrieve the current AspectRatio with valid argument and validate with above value | tvDisplayMode_t * | tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetAspectRatio (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 03 | call GetTVAspectRatio() -  Retrieve current TV AspectRatio with invalid input | NULL | tvERROR_INVALID_PARAM |
* | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetAspectRatio() -  Retrieve current TV AspectRatio valid arguments | tvDisplayMode_t * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetAspectRatio (void)
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
void test_l1_tvSettings_positive_SaveAspectRatio (void)
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
void test_l1_tvSettings_negative_SaveAspectRatio (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetLowLatencyState (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
	UT_FAIL(This function needs to be implemented!); 
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
* | 02 | call GetLowLatencyState() -  Retrieve the current LowLatency State with valid arguments and validate LowLatency State by looping through the test specific config file | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetLowLatencyState() -  Retrieve the current LowLatency State with valid argument and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetLowLatencyState (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 03 | call GetLowLatencyState() -   Retrieve current TV LowLatency State with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetLowLatencyState() -   Retrieve current TV LowLatency State with invalid input | 2 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call GetLowLatencyState() -  Retrieve current TV LowLatency State valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetLowLatencyState (void)
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
* | 02 | call SetDynamicContrast() -  Set the Dynamic Contrast with valid value | true | tvERROR_NONE | Should Pass |
* | 03 | call SetDynamicContrast() -  Reset the Dynamic Contrast with another valid value | false| tvERROR_NONE | Should Pass |
* | 04 | call SetDynamicContrast() -  Reset the Dynamic Contrast with another valid value | true | tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetDynamicContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 03 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call SetDynamicContrast() -  Set the TV Dynamic Contrast with valid input after TvTerm() | false | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetDynamicContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 02 | call GetDynamicContrast() -  Retrieve the current Dynamic Contrast with valid arguments | bool * | tvERROR_NONE | Should Pass |
* | 03 | call GetDynamicContrast() -  Retrieve the current Dynamic Contrast with valid arguments and validate with above value | bool * | tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetDynamicContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 01 | call GetDynamicContrast() -  Retrieve current TV Dynamic Contrast even before TvInit() | bool * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetDynamicContrast() -  Retrieve current TV Dynamic contrast with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetDynamicContrast() -  Retrieve current TV Dynamic Contrast valid arguments | bool * | tvERROR_INVALID_STATE | Should Pass |
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
void test_l1_tvSettings_positive_SetDynamicGamma (void)
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
void test_l1_tvSettings_negative_SetDynamicGamma (void)
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
void test_l1_tvSettings_positive_GetDynamicGamma (void)
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
void test_l1_tvSettings_negative_GetDynamicGamma (void)
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
void test_l1_tvSettings_positive_GetTVSupportedDolbyVisionModes (void)
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
void test_l1_tvSettings_negative_GetTVSupportedDolbyVisionModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 02 | call SetTVDolbyVisionMode() -  Set the TV DolbyVision mode by looping through all the values of DolbyVision modes from the test specific config file | const char * | tvERROR_NONE | Should Pass |
* | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetTVDolbyVisionMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 01 | call SetTVDolbyVisionMode() - Set the TV DolbyVision Mode even before TvInit() | const char * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetTVDolbyVisionMode() -   Set the TV DolbyVision Mode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetTVDolbyVisionMode() -   Set the TV DolbyVision Mode with not supported platform input | "INVALID" | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call SetTVDolbyVisionMode() -  Set the TV DolbyVision Mode with valid input after TvTerm() | const char *| tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetTVDolbyVisionMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 02 | call GetTVDolbyVisionMode() -  Retrieve the current DolbyVision and validate DolbyVision by looping through the test specific config file | char * | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
* | 03 | call GetTVDolbyVisionMode() -  Retrieve the current DolbyVision with valid argument and validate with above value | char * | tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetTVDolbyVisionMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
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
* | 01 | call GetTVDolbyVisionMode() -  Retrieve current TV DolbyVision Mode even before TvInit() | char * | (tvERROR_INVALID_STATE |  tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetTVDolbyVisionMode() -  Retrieve current TV DolbyVision mode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetTVDolbyVisionMode() -  Retrieve current TV DolbyVision Mode valid arguments | char * | tvERROR_INVALID_STATE | Should Pass |
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
void test_l1_tvSettings_positive_SaveTVDolbyVisionMode (void)
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
void test_l1_tvSettings_negative_SaveTVDolbyVisionMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVSupportedHLGModes() for all positive invocation scenarios
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
* | 02 | call GetTVSupportedHLGModes() -  Retrieve the current TV Supported HLG Modes and validate TV Supported HLG Modes by looping through the test specific config file | pic_modes_t *, unsigned short * | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
* | 03 | call GetTVSupportedHLGModes() -  Retrieve the current TV Supported HLG Modes with valid argument and validate with above value | pic_modes_t *, unsigned short * | tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetTVSupportedHLGModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/*todo : there is no return error cases*/
/**
* @brief Validate GetTVSupportedHLGModes() for all negative invocation scenarios
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
* | 01 | call GetTVSupportedHLGModes() -  Retrieve current TV Supported HLG Modes even before TvInit() | pic_modes_t *, unsigned short * | (tvERROR_INVALID_STATE |  tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetTVSupportedHLGModes() -  Retrieve supported TV HLG modes with invalid input | NULL , unsigned short * | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetTVSupportedHLGModes() -  Retrieve supported TV HLG modes with invalid input | pic_modes_t * , NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetTVSupportedHLGModes() -  Retrieve supported TV HLG modes with valid inputs and validate HLGmodes by looping through the test specific config file values | pic_modes_t *,  unsigned short *  | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call GetTVSupportedHLGModes() -  Retrieve current TV Supported HLG Modes valid arguments | pic_modes_t *, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetTVSupportedHLGModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetTVHLGMode() for all positive invocation scenarios
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
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetTVHLGMode() -  Set the TV HLG mode by looping through all the values of HLG modes from the test specific config file | const char * | (tvERROR_NONE|tvERROR_OPERATION_NOT_SUPPORTED)| Should Pass |
* | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetTVHLGMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetTVHLGMode() for all negative invocation scenarios
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
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetTVHLGMode() - Set the TV HLG Mode even before TvInit() | const char * | (tvERROR_INVALID_STATE |  tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetTVHLGMode() -   Set the TV HLG Mode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetTVHLGMode() -   Set the TV HLG Mode with not supported platform input| "INVALID" | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call SetTVHLGMode() -  Set the TV HLG Mode with valid input after TvTerm() | const char * | tvERROR_INVALID_STATE | Should Pass |
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
void test_l1_tvSettings_positive_GetTVHLGMode (void)
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
void test_l1_tvSettings_negative_GetTVHLGMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVSupportedHDR10Modes() for all positive invocation scenarios
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
* | 02 | call GetTVSupportedHDR10Modes() -  Retrieve the current TV Supported HDR10 Modes and validate TV Supported HDR10 Modes by looping through the test specific config file | pic_modes_t *, unsigned short * | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
* | 03 | call GetTVSupportedHDR10Modes() -  Retrieve the current TV Supported HDR10 Modes with valid argument and validate with above value | pic_modes_t *, unsigned short * | tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetTVSupportedHDR10Modes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/*todo : there is no return error cases*/
/**
* @brief Validate GetTVSupportedHDR10Modes() for all negative invocation scenarios
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
* | 01 | call GetTVSupportedHDR10Modes() -  Retrieve current TV Supported HDR10 Mode even before TvInit() |pic_modes_t *,  unsigned short * | (tvERROR_INVALID_STATE |  tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetTVSupportedHDR10Modes() -   Retrieve current TV Supported HDR10 Mode with invalid input | pic_modes_t *, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetTVSupportedHDR10Modes() -   Retrieve current TV Supported HDR10 Mode with invalid input | NULL , unsigned short *| tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetTVSupportedHDR10Modes() -  Retrieve supported TV HDR10 modes with valid inputs and validate HDR10modes by looping through the test specific config file values | pic_modes_t *,  unsigned short *  | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call GetTVSupportedHDR10Modes() -  Retrieve current TV Supported HDR10 Mode with valid arguments | pic_modes_t *,  unsigned short * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetTVSupportedHDR10Modes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetTVHDR10Mode() for all positive invocation scenarios
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
* | 02 | call SetTVHDR10Mode() -  Set the TV HDR10 mode by looping through all the values of HDR10 modes from the test specific config file | const char * | (tvERROR_NONE | tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass |
* | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetTVHDR10Mode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetTVHDR10Mode() for all negative invocation scenarios
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
* | 01 | call SetTVHDR10Mode() - Set the TV HDR10 Mode even before TvInit() | const char * | (tvERROR_INVALID_STATE |  tvERROR_OPERATION_NOT_SUPPORTED) | Should Pass and exit if tvERROR_OPERATION_NOT_SUPPORTED |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetTVHDR10Mode() -   Set the TV HDR10 Mode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetTVHDR10Mode() -   Set the TV HDR10 Mode with not supported platform input | "INVALID" | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call SetTVHDR10Mode() -  Set the TV HDR10 Mode with valid input after TvTerm() | const char * | tvERROR_INVALID_STATE | Should Pass |
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
void test_l1_tvSettings_positive_GetTVHDR10Mode (void)
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
void test_l1_tvSettings_negative_GetTVHDR10Mode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVSupportedPictureModes() for all positive invocation scenarios
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
* | 02 | call GetTVSupportedPictureModes() -  Retrieve the current TV Supported PictureModes and validate TV Supported PictureModes by looping through the test specific config file | pic_modes_t *, unsigned short * | tvERROR_NONE | Should Pass |
* | 03 | call GetTVSupportedPictureModes() -  Retrieve the current TV Supported PictureModes with valid argument and validate with above value | pic_modes_t *, unsigned short * | tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetTVSupportedPictureModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVSupportedPictureModes() for all negative invocation scenarios
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
* | 01 | call GetTVSupportedPictureModes() -  Retrieve current TV Supported PictureModes even before TvInit() | pic_modes_t *, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetTVSupportedPictureModes() -  Retrieve supported TV PictureMode with invalid input | NULL, unsigned short * | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetTVSupportedPictureModes() -  Retrieve supported TV PictureMode with invalid input |  pic_modes_t *, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetTVSupportedPictureModes() -  Retrieve supported TV PictureModes modes with valid inputs and validate PictureMode by looping through the test specific config file values | pic_modes_t *,  unsigned short *  | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call GetTVSupportedPictureModes() -  Retrieve current TV Supported PictureModes valid arguments | pic_modes_t *, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetTVSupportedPictureModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVPictureMode() for all positive invocation scenarios
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
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVPictureMode() for all negative invocation scenarios
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
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetTVPictureMode() - Retrieve current TV PictureMode even before TvInit() | char * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetTVPictureMode() -  Retrieve current TV PictureMode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetTVPictureMode() -  Retrieve current TV PictureMode with valid input after TvTerm() | char * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetTVPictureMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetTVPictureMode() for all positive invocation scenarios
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
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetTVPictureMode() -  Set the TV PictureMode by looping through all the values of pictureModes from the test specific config file | const char * | tvERROR_NONE | Should Pass |
* | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetTVPictureMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetTVPictureMode() for all negative invocation scenarios
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
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* | 01 | call SetTVPictureMode() - Set the TV PictureMode even before TvInit() with input as picturemode from the test specific config file | const char *  | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetTVPictureMode() -   Set the TV PictureMode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetTVPictureMode() -   Set the TV PictureMode with invalid input with input as picturemode from not in the test specific config file | const char *  | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call SetTVPictureMode() -  Set the TV PictureMode with valid input after TvTerm() with input as picturemode from the test specific config file  | const char * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetTVPictureMode (void)
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
void test_l1_tvSettings_positive_SaveSourcePictureMode (void)
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
void test_l1_tvSettings_negative_SaveSourcePictureMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Rgain_onSource() for all positive invocation scenarios
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 139@n
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
* | 02 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 0, colortemperature_source_offset_t , 0| tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 2047, colortemperature_source_offset_t , 0| tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 1000, colortemperature_source_offset_t , 0| tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 0, colortemperature_source_offset_t , 1| tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 2047, colortemperature_source_offset_t , 1| tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 1000, colortemperature_source_offset_t , 1| tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_Rgain_onSource() -  Reset the ColorTemp Rgain_onSource with another valid value | tvColorTemp_t, 2047, TV_OFFSET_NEW, 0 | tvERROR_NONE | Should Pass |
* | 09 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemp_Rgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Rgain_onSource() for all negative invocation scenarios
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
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetColorTemp_Rgain_onSource() - Set the TV ColorTemp Rgain_onSource even before TvInit() | tvColorTemp_t, 0, colortemperature_source_offset_t, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource with max range of colortemp | tvColorTemp_MAX, 0, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource with less than lower range of colortemp | -1, 0, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource invalid rgain by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, -1, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource invalid rgain by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, 2048, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource invalid sourceId by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, 0, -1, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource invalid sourceId by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, 0, OFFSET_MAX, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource invalid saveonly flag by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 0, colortemperature_source_offset_t, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 10 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource invalid saveonly flag by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 0, colortemperature_source_offset_t, 2 | tvERROR_INVALID_PARAM | Should Pass |
* | 11 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource with max range | tvColorTemp_MAX, 0, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 12 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp and sourceId with valid value but not supported by the platform by looping through the test specific config file | tvColorTemp_t, 50, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 13 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 14 | call SetColorTemp_Rgain_onSource() -  Set the TV ColorTemp Rgain_onSource with valid input after TvTerm() | tvColorTemp_t, 2047, AV_OFFSET_NEW, 1 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_Rgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Rgain_onSource() for all positive invocation scenarios
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
* | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_Rgain_onSource() -  Retrieve the current ColorTemp Rgain_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the test specific config file | tvColorTemp_t, int *, colortemperature_source_offset_t | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Rgain_onSource() -  Retrieve the current ColorTemp Rgain_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the test specific config file and validate with above value | tvColorTemp_t, int *, colortemperature_source_offset_t | tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_Rgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Rgain_onSource() for all negative invocation scenarios
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

* | 01 | call GetColorTemp_Rgain_onSource() -  Retrieve current TV ColorTemp Rgain_onSource even before TvInit() | tvColorTemp_t, int *, colortemperature_source_offset_t  | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource with max range color temp| tvColorTemp_MAX, int *, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource with less range color temp |  -1, int *, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource invalid Rgain by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, NULL, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource invalid SourceId by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, int *, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource invalid SourceId by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, int *, OFFSET_MAX | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call GetColorTemp_Rgain_onSource() -   Retrieve the Rgain_onSource for a valid value of TV ColorTemp and SourceId but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int *, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call GetColorTemp_Rgain_onSource() -  Retrieve current TV ColorTemp Rgain_onSource valid arguments | tvColorTemp_t, int *, int  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetColorTemp_Rgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Ggain_onSource() for all positive invocation scenarios
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
* | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 0, colortemperature_source_offset_t , 0| tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 2047, colortemperature_source_offset_t , 0| tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 1000, colortemperature_source_offset_t , 0| tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 0, colortemperature_source_offset_t , 1| tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 2047, colortemperature_source_offset_t , 1| tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 1000, colortemperature_source_offset_t , 1| tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_Ggain_onSource() -  Reset the ColorTemp Ggain_onSource with another valid value | tvColorTemp_t, 2047, colortemperature_source_offset_t, 0 | tvERROR_NONE | Should Pass |
* | 09 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemp_Ggain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Ggain_onSource() for all negative invocation scenarios
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
* | 01 | call SetColorTemp_Ggain_onSource() - Set the TV ColorTemp Ggain_onSource even before TvInit() | tvColorTemp_t, 0, colortemperature_source_offset_t, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource with max range of colortemp | tvColorTemp_MAX, 0, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource with less than lower range of colortemp | -1, 0, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource invalid rgain by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, -1, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource invalid rgain by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, 2048, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource invalid sourceId by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, 0, -1, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource invalid sourceId by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, 0, OFFSET_MAX3, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource invalid saveonly flag by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 0, colortemperature_source_offset_t, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 10 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource invalid saveonly flag by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 0, colortemperature_source_offset_t, 2 | tvERROR_INVALID_PARAM | Should Pass |
* | 11 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource with max range | tvColorTemp_MAX, 0, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 12 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp and sourceId with valid value but not supported by the platform by looping through the test specific config file | tvColorTemp_t, 50, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 13 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 14 | call SetColorTemp_Ggain_onSource() -  Set the TV ColorTemp Ggain_onSource with valid input after TvTerm() | tvColorTemp_t, 2047, colortemperature_source_offset_t, 1 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_Ggain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Ggain_onSource() for all positive invocation scenarios
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
* | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_Ggain_onSource() -  Retrieve the current ColorTemp Ggain_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the test specific config file | tvColorTemp_t, int *, colortemperature_source_offset_t | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Ggain_onSource() -  Retrieve the current ColorTemp Ggain_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the test specific config file and validate with above value | tvColorTemp_t, int *, colortemperature_source_offset_t | tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_Ggain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Ggain_onSource() for all negative invocation scenarios
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
* | 01 | call GetColorTemp_Ggain_onSource() -  Retrieve current TV ColorTemp Ggain_onSource even before TvInit() | tvColorTemp_t, int *, colortemperature_source_offset_t  | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource with max range color temp| tvColorTemp_MAX, int *, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource with less range color temp |  -1, int *, int | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource invalid Rgain by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, NULL, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource invalid SourceId by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, int *, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource invalid SourceId by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, int *, OFFSET_MAX | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call GetColorTemp_Ggain_onSource() -   Retrieve the Ggain_onSource for a valid value of TV ColorTemp and SourceId but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int *, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 10 | call GetColorTemp_Ggain_onSource() -  Retrieve current TV ColorTemp Ggain_onSource valid arguments | tvColorTemp_t, int *, colortemperature_source_offset_t  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetColorTemp_Ggain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Bgain_onSource() for all positive invocation scenarios
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
* | 02 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 0, colortemperature_source_offset_t , 0| tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 2047, colortemperature_source_offset_t , 0| tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 1000, colortemperature_source_offset_t , 0| tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 0, colortemperature_source_offset_t , 1| tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 2047, colortemperature_source_offset_t , 1| tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 1000, colortemperature_source_offset_t , 1| tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_Bgain_onSource() -  Reset the ColorTemp Bgain_onSource with another valid value | tvColorTemp_t, 2047, int, 0 | tvERROR_NONE | Should Pass |
* | 09 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemp_Bgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Bgain_onSource() for all negative invocation scenarios
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
* | 01 | call SetColorTemp_Bgain_onSource() - Set the TV ColorTemp Bgain_onSource even before TvInit() | tvColorTemp_t, 0, colortemperature_source_offset_t, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource with max range of colortemp | tvColorTemp_MAX, 0, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource with max range less than lower range of colortemp | -1, 0, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource invalid rgain by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, -1, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource invalid rgain by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, 2048, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource invalid sourceId by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, 0, -1, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource invalid sourceId by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, 0, OFFSET_MAX, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource invalid saveonly flag by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 0, colortemperature_source_offset_t, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 10 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource invalid saveonly flag by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, 0, colortemperature_source_offset_t, 2 | tvERROR_INVALID_PARAM | Should Pass |
* | 11 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource with max range | tvColorTemp_MAX, 0, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 12 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp and sourceId with valid value but not supported by the platform by looping through the test specific config file | tvColorTemp_t, 50, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 13 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 14 | call SetColorTemp_Bgain_onSource() -  Set the TV ColorTemp Bgain_onSource with valid input after TvTerm() | tvColorTemp_t, 2047, colortemperature_source_offset_t, 1 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_Bgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Bgain_onSource() for all positive invocation scenarios
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
* | 02 | call GetColorTemp_Bgain_onSource() -  Retrieve the current ColorTemp Bgain_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the test specific config file | tvColorTemp_t, int *, colortemperature_source_offset_t | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Bgain_onSource() -  Retrieve the current ColorTemp Bgain_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the test specific config file and validate with above value | tvColorTemp_t, int *, colortemperature_source_offset_t | tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_Bgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Bgain_onSource() for all negative invocation scenarios
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
* | 01 | call GetColorTemp_Bgain_onSource() -  Retrieve current TV ColorTemp Bgain_onSource even before TvInit() | tvColorTemp_t, int *, colortemperature_source_offset_t  | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource with max range color temp| tvColorTemp_MAX, int *, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource with less range color temp |  -1, int *, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource invalid Rgain by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, NULL, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource invalid SourceId by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, int *, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource invalid SourceId by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, int *, OFFSET_MAX | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call GetColorTemp_Bgain_onSource() -   Retrieve the Bgain_onSource for a valid value of TV ColorTemp and SourceId but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int *, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 10 | call GetColorTemp_Bgain_onSource() -  Retrieve current TV ColorTemp Bgain_onSource valid arguments | tvColorTemp_t, int *, colortemperature_source_offset_t  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetColorTemp_Bgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_R_post_offset_onSource() for all positive invocation scenarios
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 151@n
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
* | 02 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, -1024, colortemperature_source_offset_t, 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, 1024, colortemperature_source_offset_t, 0 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, 500, colortemperature_source_offset_t, 0 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, -1024, colortemperature_source_offset_t, 1 | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, 1024, colortemperature_source_offset_t, 1 | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, 500, colortemperature_source_offset_t, 1 | tvERROR_NONE | Should Pass |
* | 08 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemp_R_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_R_post_offset_onSource() for all negative invocation scenarios
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
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetColorTemp_R_post_offset_onSource() - Set the TV ColorTemp R_post_offset_onSource even before TvInit() | tvColorTemp_t, -1024, colortemperature_source_offset_t, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource with max range | tvColorTemp_Max, 0, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource with less than the lower range | -1, 0, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource invalid less than the lower range of rpostoffset  with by looping through all the values of colortemp and SourceId from the test specific config file | tvColorTemp_t, -1025, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource invalid max range of rpostoffset with by looping through all the values of colortemp and SourceId from the test specific config file | tvColorTemp_t, 1025, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource invalid sourceId with by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, int, -1, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource invalid sourceId with by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, int, OFFSET_MAX, 0| tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource invalid saveonly flag with by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, int, colortemperature_source_offset_t, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource invalid saveonly flag with by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, int, colortemperature_source_offset_t, 2 | tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource with valid value of colortemp but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 10 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource with valid value of sourceId but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 11 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 11 | call SetColorTemp_R_post_offset_onSource() -  Set the TV ColorTemp R_post_offset_onSource with valid input after TvTerm() | tvColorTemp_t, 1024, colortemperature_source_offset_t, 1 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_R_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_R_post_offset_onSource() for all positive invocation scenarios
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 153@n
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
* | 02 | call GetColorTemp_R_post_offset_onSource() -  Retrieve the current ColorTemp R_post_offset_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the test specific config file | tvColorTemp_t, int *, colortemperature_source_offset_t| tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_R_post_offset_onSource() -  Retrieve the current ColorTemp R_post_offset_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the test specific config file and validate with above value | tvColorTemp_t, int *, colortemperature_source_offset_t| tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_R_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_R_post_offset_onSource() for all negative invocation scenarios
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
* | 01 | call GetColorTemp_R_post_offset_onSource() -  Retrieve current TV ColorTemp R_post_offset_onSource even before TvInit() | tvColorTemp_t, int *, colortemperature_source_offset_t | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_R_post_offset_onSource() -   Retrieve current TV ColorTemp R_post_offset_onSource with max range color temp| tvColorTemp_MAX, int *, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_R_post_offset_onSource() -   Retrieve current TV ColorTemp R_post_offset_onSource with less range color temp |  -1, int *, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_R_post_offset_onSource() -   Retrieve current TV ColorTemp R_post_offset_onSource invalid rpostoffset  by looping through all the values of colortemp and SourceId from the test specific config file |  tvColorTemp_t, NULL, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call GetColorTemp_R_post_offset_onSource() -   Retrieve current TV ColorTemp R_post_offset_onSource invalid SourceId by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, int *, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call GetColorTemp_R_post_offset_onSource() -   Retrieve current TV ColorTemp R_post_offset_onSource invalid SourceId by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, int *, OFFSET_MAX | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call GetColorTemp_R_post_offset_onSource() -   Retrieve the R_post_offset_onSource for a valid value of TV ColorTemp but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int *, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call GetColorTemp_R_post_offset_onSource() -   Retrieve the R_post_offset_onSource for a valid value of SourceId but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int *, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 10 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 11 | call GetColorTemp_R_post_offset_onSource() -  Retrieve current TV ColorTemp R_post_offset_onSource valid arguments | tvColorTemp_t, int *, colortemperature_source_offset_t | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetColorTemp_R_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_G_post_offset_onSource() for all positive invocation scenarios
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
* | 01 | call TvInit() -   Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, -1024, colortemperature_source_offset_t, 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, 1024, colortemperature_source_offset_t, 0 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, 500, colortemperature_source_offset_t, 0 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, -1024, colortemperature_source_offset_t, 1 | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, 1024, colortemperature_source_offset_t, 1 | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, 500, colortemperature_source_offset_t, 1 | tvERROR_NONE | Should Pass |
* | 08 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemp_G_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_G_post_offset_onSource() for all negative invocation scenarios
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
* | 01 | call SetColorTemp_G_post_offset_onSource() - Set the TV ColorTemp G_post_offset_onSource even before TvInit() | tvColorTemp_t, -1024, colortemperature_source_offset_t, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource with max range | tvColorTemp_Max, 0, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource with less than the lower range | -1, 0, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource invalid less than the lower range of gpostoffset with by looping through all the values of colortemp and SourceId from the test specific config file | tvColorTemp_t, -1025, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource invalid max range of gpostoffset with by looping through all the values of colortemp and SourceId from the test specific config file | tvColorTemp_t, 1025, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource invalid sourceId flag with by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, int, OFFSET_MAX, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource invalid sourceId flag with by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, int, -1, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource invalid saveonly flag with by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, int, colortemperature_source_offset_t, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 10 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource invalid saveonly flag with by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, int, colortemperature_source_offset_t, 2 | tvERROR_INVALID_PARAM | Should Pass |
* | 11 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource with valid value of colortemp but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 12 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource with valid value of sourceId but not supported by the platform by looping through the test specific config file | tvColorTemp_t, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 13 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 14 | call SetColorTemp_G_post_offset_onSource() -  Set the TV ColorTemp G_post_offset_onSource with valid input after TvTerm() | tvColorTemp_t, 1024, colortemperature_source_offset_t, 1 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_G_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_G_post_offset_onSource() for all positive invocation scenarios
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 157@n
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
* | 02 | call GetColorTemp_G_post_offset_onSource() -  Retrieve the current ColorTemp G_post_offset_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the test specific config file | tvColorTemp_t, int *, colortemperature_source_offset_t| tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_G_post_offset_onSource() -  Retrieve the current ColorTemp G_post_offset_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the test specific config file and validate with above value | tvColorTemp_t, int *, colortemperature_source_offset_t| tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_G_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_G_post_offset_onSource() for all negative invocation scenarios
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
* | 01 | call GetColorTemp_G_post_offset_onSource() -  Retrieve current TV ColorTemp G_post_offset_onSource even before TvInit() | tvColorTemp_t, int *, colortemperature_source_offset_t | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_G_post_offset_onSource() -   Retrieve current TV ColorTemp G_post_offset_onSource with max range color temp| tvColorTemp_MAX, int *, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_G_post_offset_onSource() -   Retrieve current TV ColorTemp G_post_offset_onSource with less range color temp |  -1, int *, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_G_post_offset_onSource() -   Retrieve current TV ColorTemp G_post_offset_onSource invalid gpostoffset  by looping through all the values of colortemp and SourceId from the test specific config file |  tvColorTemp_t, NULL, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call GetColorTemp_G_post_offset_onSource() -   Retrieve current TV ColorTemp G_post_offset_onSource invalid SourceId by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, int *, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call GetColorTemp_G_post_offset_onSource() -   Retrieve current TV ColorTemp G_post_offset_onSource invalid SourceId by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, int *, OFFSET_MAX | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call GetColorTemp_G_post_offset_onSource() -   Retrieve the G_post_offset_onSource for a valid value of TV ColorTemp but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int *, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call GetColorTemp_G_post_offset_onSource() -   Retrieve the G_post_offset_onSource for a valid value of SourceId but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int *, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 10 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 11 | call GetColorTemp_G_post_offset_onSource() -  Retrieve current TV ColorTemp G_post_offset_onSource valid arguments | tvColorTemp_t, int *, colortemperature_source_offset_t | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetColorTemp_G_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_B_post_offset_onSource() for all positive invocation scenarios
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
* | 01 | call TvInit() -   Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, -1024, colortemperature_source_offset_t, 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, 1024, colortemperature_source_offset_t, 0 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, 500, colortemperature_source_offset_t, 0 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, -1024, colortemperature_source_offset_t, 1 | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, 1024, colortemperature_source_offset_t, 1 | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value by looping through all the values of colortemp and sourceId from the test specific config file| tvColorTemp_t, 500, colortemperature_source_offset_t, 1 | tvERROR_NONE | Should Pass |
* | 08 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemp_B_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_B_post_offset_onSource() for all negative invocation scenarios
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
* | 01 | call SetColorTemp_B_post_offset_onSource() - Set the TV ColorTemp B_post_offset_onSource even before TvInit() | tvColorTemp_t, -1024, colortemperature_source_offset_t, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource with max range | tvColorTemp_Max, 0, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource with less than the lower range | -1, 0, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource invalid max range of bpostoffset by looping through all the values of colortemp and SourceId from the test specific config file | tvColorTemp_t, -1025, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource invalid less than the lower range of bpostoffset by looping through all the values of colortemp and SourceId from the test specific config file | tvColorTemp_t, 1025, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource invalid sourceId flag with by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, int, OFFSET_MAX, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource invalid sourceId flag with by looping through all the values of colortemp from the test specific config file | tvColorTemp_t, int, -1, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource invalid saveonly flag by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, int, colortemperature_source_offset_t, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource invalid saveonly flag by looping through all the values of colortemp and sourceId from the test specific config file | tvColorTemp_t, int, colortemperature_source_offset_t, 2 | tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource with valid value of colortemp but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 10 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource with valid value of sourceId but not supported by the platform by looping through the test specific config file | tvColorTemp_t, colortemperature_source_offset_t, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 11 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 12 | call SetColorTemp_B_post_offset_onSource() -  Set the TV ColorTemp B_post_offset_onSource with valid input after TvTerm() | tvColorTemp_t, 1024, colortemperature_source_offset_t, 1 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_B_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_B_post_offset_onSource() for all positive invocation scenarios
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
* | 02 | call GetColorTemp_B_post_offset_onSource() -  Retrieve the current ColorTemp B_post_offset_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the test specific config file | tvColorTemp_t, int *, colortemperature_source_offset_t| tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_B_post_offset_onSource() -  Retrieve the current ColorTemp B_post_offset_onSource with valid arguments by looping through all the values of colortemp and sourceId modes from the test specific config file and validate with above value | tvColorTemp_t, int *, colortemperature_source_offset_t| tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_B_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_B_post_offset_onSource() for all negative invocation scenarios
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
* | 01 | call GetColorTemp_B_post_offset_onSource() -  Retrieve current TV ColorTemp B_post_offset_onSource even before TvInit() | tvColorTemp_t, int *, colortemperature_source_offset_t | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_B_post_offset_onSource() -   Retrieve current TV ColorTemp B_post_offset_onSource with max range color temp| tvColorTemp_MAX, int *, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_B_post_offset_onSource() -   Retrieve current TV ColorTemp B_post_offset_onSource with less range color temp |  -1, int *, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_B_post_offset_onSource() -   Retrieve current TV ColorTemp B_post_offset_onSource invalid bpostoffset  by looping through all the values of colortemp and SourceId from the test specific config file |  tvColorTemp_t, NULL, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call GetColorTemp_B_post_offset_onSource() -   Retrieve current TV ColorTemp B_post_offset_onSource invalid SourceId by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, int *, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call GetColorTemp_B_post_offset_onSource() -   Retrieve current TV ColorTemp B_post_offset_onSource invalid SourceId by looping through all the values of colortemp from the test specific config file |  tvColorTemp_t, int *, OFFSET_MAX | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call GetColorTemp_B_post_offset_onSource() -   Retrieve the B_post_offset_onSource for a valid value of TV ColorTemp but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int *, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call GetColorTemp_B_post_offset_onSource() -   Retrieve the B_post_offset_onSource for a valid value of SourceId but not supported by the platform by looping through the test specific config file | tvColorTemp_t, int *, colortemperature_source_offset_t | tvERROR_INVALID_PARAM | Should Pass |
* | 10 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 11 | call GetColorTemp_B_post_offset_onSource() -  Retrieve current TV ColorTemp B_post_offset_onSource valid arguments | tvColorTemp_t, int *, colortemperature_source_offset_t | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetColorTemp_B_post_offset_onSource (void)
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
void test_l1_tvSettings_positive_EnableWBCalibrationMode (void)
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
void test_l1_tvSettings_negative_EnableWBCalibrationMode (void)
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
void test_l1_tvSettings_positive_SetWBctrl (void)
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
void test_l1_tvSettings_negative_SetWBctrl (void)
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
void test_l1_tvSettings_positive_GetWBctrl (void)
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
void test_l1_tvSettings_negative_GetWBctrl (void)
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
* @brief Validate SetGammaTable() for all positive invocation scenarios
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
* | 02 | call SetGammaTable() -  Set the TV GammaTable with valid arguments for the pData_R, pData_G, pData_B values | unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_NONE | Should Pass |
* | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetGammaTable (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetGammaTable() for all negative invocation scenarios
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
* | 01 | call SetGammaTable() - Set the TV GammaTable even before TvInit() | unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetGammaTable() -   Set the TV GammaTable with invalid input | NULL, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetGammaTable() -   Set the TV GammaTable with invalid input | unsigned short *, NULL, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetGammaTable() -   Set the TV GammaTable with invalid input | unsigned short *, unsigned short *, NULL, 256| tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetGammaTable() -   Set the TV GammaTable with invalid input for few elements of the array | -1, unsigned short *, unsigned short *, 256| tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SetGammaTable() -   Set the TV GammaTable with invalid input for few elements of the array | 65536, unsigned short *, unsigned short *, 256| tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SetGammaTable() -   Set the TV GammaTable with invalid input for few elements of the array | unsigned short *, -1, unsigned short *, 256 | tvERROR_INVALID_STATE | Should Pass |
* | 09 | call SetGammaTable() -   Set the TV GammaTable with invalid input for few elements of the array | unsigned short *, 65536, unsigned short *, 256 | tvERROR_INVALID_STATE | Should Pass |
* | 10 | call SetGammaTable() -   Set the TV GammaTable with invalid input for few elements of the array | unsigned short *, unsigned short *, -1, 256 | tvERROR_INVALID_STATE | Should Pass |
* | 11 | call SetGammaTable() -   Set the TV GammaTable with invalid input for few elements of the array | unsigned short *, unsigned short *, 65536, 256 | tvERROR_INVALID_STATE | Should Pass |
* | 12 | call SetGammaTable() -   Set the TV GammaTable with invalid input | unsigned short *, unsigned short *, unsigned short *, 0| tvERROR_INVALID_PARAM | Should Pass |
* | 13 | call SetGammaTable() -   Set the TV GammaTable with invalid input | unsigned short *, unsigned short *, unsigned short *, 257| tvERROR_INVALID_PARAM | Should Pass |
* | 14 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 15 | call SetGammaTable() -  Set the TV GammaTable with valid input after TvTerm() | unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetGammaTable (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetGammaTable() for all positive invocation scenarios
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
* | 02 | call GetGammaTable() -  Retrieve the current GammaTable and validate GammaTable values for the valid colortemp by looping through the test specific config file | int ,  unsigned short *,  unsigned short *,  unsigned short *, unsigned short | tvERROR_NONE | Should Pass |
* | 03 | call GetGammaTable() -  Retrieve the current GammaTable with valid argument and validate with above value | int ,  unsigned short *,  unsigned short *,  unsigned short *, unsigned short | tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetGammaTable (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetGammaTable() for all negative invocation scenarios
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
* | 01 | call GetGammaTable() -  Retrieve current TV GammaTable State even before TvInit() | int ,  unsigned short *,  unsigned short *,  unsigned short *, int | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetGammaTable() -   Retrieve current TV GammaTable State with invalid input by looping through the colortemp from test specific config file | int ,  NULL,  unsigned short *,  unsigned short *, int | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetGammaTable() -   Retrieve current TV GammaTable State with invalid input by looping through the colortemp from test specific config file | int , unsigned short *,  NULL, unsigned short *, int | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetGammaTable() -   Retrieve current TV GammaTable State with invalid input by looping through the colortemp from test specific config file | int , unsigned short *,  unsigned short *, NULL,  int | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call GetGammaTable() -   Retrieve current TV GammaTable State with invalid colortemp with max range | tvColorTemp_MAX , unsigned short *,  unsigned short *, unsigned short *,  int | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call GetGammaTable() -   Retrieve current TV GammaTable State with invalid colortemp  less than lower range | -1 , unsigned short *,  unsigned short *, unsigned short *,  int | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call GetGammaTable() -   Retrieve current TV GammaTable State with invalid size | int, unsigned short *, unsigned short *, unsigned short *, 257| tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call GetGammaTable() -   Retrieve current TV GammaTable State with valid colortemp  value but not supported by the platform by looping through the test specific config file | int , unsigned short *,  unsigned short *, unsigned short *,  int | tvERROR_INVALID_PARAM | Should Pass |
* | 10 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 11 | call GetGammaTable() -  Retrieve current TV GammaTable State valid arguments |int ,  unsigned short *,  unsigned short *,  unsigned short *, intint ,  unsigned short *,  unsigned short *,  unsigned short *, int | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetGammaTable (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveGammaTable() for all positive invocation scenarios
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
* | 02 | call SaveGammaTable() -  save the current GammaTable State with valid arguments of colortemp by looping through the test specific config file | int , unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_NONE | Should Pass |
* | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SaveGammaTable (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveGammaTable() for all negative invocation scenarios
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
* | 01 | call SaveGammaTable() - save the current GammaTable State even before TvInit() | int, unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveGammaTable() -   save the current GammaTable State with invalid input by looping through the colortemp from test specific config file| int, NULL, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveGammaTable() -   save the current GammaTable State with invalid input by looping through the colortemp from test specific config file| int, unsigned short *, NULL, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveGammaTable() -   save the current GammaTable State with invalid input by looping through the colortemp from test specific config file| int, unsigned short *, unsigned short *, NULL, 256| tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveGammaTable() -   save the current GammaTable State with invalid colortemp with max range | tvColorTemp_MAX , unsigned short *,  unsigned short *, unsigned short *,  int | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SaveGammaTable() -   save the current GammaTable State with invalid colortemp  less than lower range| -1 , unsigned short *,  unsigned short *, unsigned short *,  int | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SaveGammaTable() -   save the current GammaTable State with invalid input for few elements of the array by looping through the colortemp from test specific config file| int, -1,  unsigned short *, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call SaveGammaTable() -   save the current GammaTable State with invalid input for few elements of the array by looping through the colortemp from test specific config file| int, 65536,  unsigned short *, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
* | 10 | call SaveGammaTable() -   save the current GammaTable State with invalid input for few elements of the array by looping through the colortemp from test specific config file| int, unsigned short *,  -1, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
* | 11 | call SaveGammaTable() -   save the current GammaTable State with invalid input for few elements of the array by looping through the colortemp from test specific config file| int, unsigned short *,  65536, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
* | 12 | call SaveGammaTable() -   save the current GammaTable State with invalid input for few elements of the array by looping through the colortemp from test specific config file| int, unsigned short *,  unsigned short *, -1, 256 | tvERROR_INVALID_PARAM | Should Pass |
* | 13 | call SaveGammaTable() -   save the current GammaTable State with invalid input for few elements of the array by looping through the colortemp from test specific config file| int, unsigned short *,  unsigned short *, 65536, 256 | tvERROR_INVALID_PARAM | Should Pass |
* | 14 | call SaveGammaTable() -   save the current GammaTable State with invalid input by looping through the colortemp from test specific config file| int, unsigned short *,  unsigned short *, unsigned short *, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 15 | call SaveGammaTable() -   save the current GammaTable State with invalid input by looping through the colortemp from test specific config file| int, unsigned short *,  unsigned short *, unsigned short *, 257 | tvERROR_INVALID_PARAM | Should Pass |
* | 16 | call SaveGammaTable() -   save the current GammaTable State with valid colortemp  value but not supported by the platform by looping through the test specific config file | int , unsigned short *,  unsigned short *, unsigned short *,  int | tvERROR_INVALID_PARAM | Should Pass |
* | 17 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 18 | call SaveGammaTable() -  Set the current GammaTable State with valid input after TvTerm() | int, unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SaveGammaTable (void)
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
void test_l1_tvSettings_positive_SetDvTmaxValue (void)
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
void test_l1_tvSettings_negative_SetDvTmaxValue (void)
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
void test_l1_tvSettings_positive_GetDvTmaxValue (void)
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
void test_l1_tvSettings_negative_GetDvTmaxValue (void)
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
void test_l1_tvSettings_positive_SaveDvTmaxValue (void)
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
void test_l1_tvSettings_negative_SaveDvTmaxValue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/** 
* @brief Validate GetSupportedComponentColor() for all positive invocation scenarios
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
* | 02 | call GetSupportedComponentColor() -  Retrieve the current Supported ComponentColor and validate Supported ComponentColor by looping through the test specific config file | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetSupportedComponentColor() -  Retrieve the current Supported ComponentColor with valid argument and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetSupportedComponentColor (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetSupportedComponentColor() for all negative invocation scenarios
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
* | 01 | call GetSupportedComponentColor() -  Retrieve current TV Supported ComponentColor even before TvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetSupportedComponentColor() -  Retrieve supported component colortemperature with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetSupportedComponentColor() -  Retrieve supported component color with valid inputs and validate componentColor by looping through the test specific config file values | int * | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call GetSupportedComponentColor() -  Retrieve current TV Supported ComponentColor valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetSupportedComponentColor (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetCurrentComponentSaturation() for all positive invocation scenarios
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
* | 02 | call SetCurrentComponentSaturation() -  Set the TV component saturation by looping through all the values of saturation from test specific config file| tvDataComponentColor_t  ,0 | tvERROR_NONE | Should Pass |
* | 03 | call SetCurrentComponentSaturation() -  Set the TV component saturation by looping through all the values of saturation from test specific config file| tvDataComponentColor_t ,100 | tvERROR_NONE | Should Pass |
* | 04 | call SetCurrentComponentSaturation() -  Set the TV component saturation by looping through all the values of saturation from test specific config file| tvDataComponentColor_t  ,50 | tvERROR_NONE | Should Pass |
* | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetCurrentComponentSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetCurrentComponentSaturation() for all negative invocation scenarios
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
* | 01 | call SetCurrentComponentSaturation() - Set the TV Current Component Saturation even before TvInit() | tvDataComponentColor_t ,  int | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetCurrentComponentSaturation() -  Set the TV Current Component Saturation with max range by looping through all the values from test specific config file  | tvDataComponentColor_t,  101 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetCurrentComponentSaturation() -  Set the TV Current Component Saturation with less than the lower range by looping through all the values from test specific config file | tvDataComponentColor_t,  -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetCurrentComponentSaturation() -  Set the TV Current Component Saturation with max range DataComponentColor| tvDataColor_MAX, 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetCurrentComponentSaturation() -  Set the TV Current Component Saturation with less than the lower range of DataComponentColor| -1, 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SetCurrentComponentSaturation() -  Set the TV Current Component Saturation with valid value of DataComponentColor but not supported by the platform by looping through the config fil| tvDataComponentColor_t, 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 09 | call SetCurrentComponentSaturation() -  Set the TV Current Component Saturation with valid input after TvTerm() | tvDataComponentColor_t ,  int | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetCurrentComponentSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentComponentSaturation() for all positive invocation scenarios
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
* | 02 | call GetCurrentComponentSaturation() -  Retrieve the current Component Saturation with valid arguments by looping through all the values of DataComponentColor from test specific config file | tvDataComponentColor_t, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetCurrentComponentSaturation() -  Retrieve the current Component Saturation with valid argument and validate with above value | tvDataComponentColor_t, int * | tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetCurrentComponentSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentComponentSaturation() for all negative invocation scenarios
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
* | 01 | call GetCurrentComponentSaturation() -  Retrieve current TV Component Saturation even before TvInit() | tvDataComponentColor_t, int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetCurrentComponentSaturation() -  Retrieve current TV component saturation with invalid input by looping through all the values of DataComponentColor from test specific config file | tvDataComponentColor_t, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetCurrentComponentSaturation() -  Retrieve current TV component saturation with Max range of DataComponentColor | tvDataComponentColor_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetCurrentComponentSaturation() -  Retrieve current TV component saturation with less than lower range of DataComponentColor  | -1, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call GetCurrentComponentSaturation() -  Retrieve current TV Component Saturation valid arguments | tvDataComponentColor_t, int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetCurrentComponentSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetCurrentComponentHue() for all positive invocation scenarios
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
* | 02 | call SetCurrentComponentHue() -  Set the TV component hue by looping through all the values of component hue from test specific config file| tvDataComponentColor_t , 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetCurrentComponentHue() -  Set the TV component hue by looping through all the values of component hue from test specific config file| tvDataComponentColor_t , 100 | tvERROR_NONE | Should Pass |
* | 04 | call SetCurrentComponentHue() -  Set the TV component hue by looping through all the values of component hue from test specific config file| tvDataComponentColor_t , 50 | tvERROR_NONE | Should Pass |
* | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetCurrentComponentHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetCurrentComponentHue() for all negative invocation scenarios
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
* | 01 | call SetCurrentComponentHue() -  Retrieve current TV Current Component Hue even before TvInit() | tvDataComponentColor_t, int | tvERROR_INVALID_STATE | Should Pass |
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
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentComponentHue() for all positive invocation scenarios
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
* | 02 | call GetCurrentComponentHue() - Retrieve the current Component Hue with valid arguments by looping through all the values of DataComponentColor from test specific config file | tvDataComponentColor_t, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetCurrentComponentHue() -  Retrieve the current Component Hue with valid argument and validate with above value | tvDataComponentColor_t, int * | tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetCurrentComponentHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentComponentHue() for all negative invocation scenarios
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
* | 01 | call GetCurrentComponentHue() -  Retrieve current TV brightness even before TvInit() |tvDataComponentColor_t, int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetCurrentComponentHue() -  Retrieve current TV component Hue with invalid input by looping through all the values of DataComponentColor from test specific config file | tvDataComponentColor_t, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetCurrentComponentHue() -  Retrieve current TV component Hue with Max range of DataComponentColor | tvDataComponentColor_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetCurrentComponentHue() -  Retrieve current TV component Hue with less than lower range of DataComponentColor  | -1, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call GetCurrentComponentHue() -  Retrieve current TV brightness valid arguments | tvDataComponentColor_t, int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetCurrentComponentHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetCurrentComponentLuma() for all positive invocation scenarios
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
* | 02 | call SetCurrentComponentLuma() -  Set the TV component hue by looping through all the values of component Luma from test specific config file| tvDataComponentColor_t , 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetCurrentComponentLuma() -  Set the TV component hue by looping through all the values of component Luma from test specific config file| tvDataComponentColor_t , 30 | tvERROR_NONE | Should Pass |
* | 04 | call SetCurrentComponentLuma() -  Set the TV component hue by looping through all the values of component Luma from test specific config file| tvDataComponentColor_t , 15 | tvERROR_NONE | Should Pass |* | 03 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetCurrentComponentLuma (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetCurrentComponentLuma() for all negative invocation scenarios
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
* | 01 | call SetCurrentComponentLuma() -  Retrieve current TV Current Component Luma even before TvInit() | tvDataComponentColor_t, int | tvERROR_INVALID_STATE | Should Pass |
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
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentComponentLuma() for all positive invocation scenarios
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
* | 02 | call GetCurrentComponentLuma() - Retrieve the current Component Luma with valid arguments by looping through all the values of DataComponentColor from test specific config file | tvDataComponentColor_t, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetCurrentComponentLuma() -  Retrieve the current Component Luma  with valid argument and validate with above value | tvDataComponentColor_t, int * | tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetCurrentComponentLuma (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentComponentLuma() for all negative invocation scenarios
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
* | 01 | call GetCurrentComponentLuma() -  Retrieve current TV Current Component Luma even before TvInit() | tvDataColor_RED, int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetCurrentComponentLuma() -  Retrieve current TV component Luma with invalid input by looping through all the values of DataComponentColor from test specific config file | tvDataComponentColor_t, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetCurrentComponentLuma() -  Retrieve current TV component Luma with Max range of DataComponentColor | tvDataComponentColor_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetCurrentComponentLuma() -  Retrieve current TV component Luma with less than lower range of DataComponentColor  | -1, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call TvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetCurrentComponentLuma() -  Retrieve current TV Current Component Luma valid arguments | tvDataColor_RED, int * | tvERROR_INVALID_STATE | Should Pass |
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
void test_l1_tvSettings_positive_GetDefaultParams (void)
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
void test_l1_tvSettings_negative_GetDefaultParams (void)
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
void test_l1_tvSettings_positive_GetMaxGainValue (void)
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
void test_l1_tvSettings_negative_GetMaxGainValue (void)
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
void test_l1_tvSettings_positive_EnableGammaMode (void)
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
void test_l1_tvSettings_negative_EnableGammaMode (void)
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
void test_l1_tvSettings_positive_SetGammaPattern (void)
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
void test_l1_tvSettings_negative_SetGammaPattern (void)
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
void test_l1_tvSettings_positive_SetGammaTestPoint (void)
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
void test_l1_tvSettings_negative_SetGammaTestPoint (void)
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
void test_l1_tvSettings_positive_GetGammaTestPoint (void)
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
void test_l1_tvSettings_negative_GetGammaTestPoint (void)
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
void test_l1_tvSettings_positive_GetTVGammaTarget (void)
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
void test_l1_tvSettings_negative_GetTVGammaTarget (void)
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
void test_l1_tvSettings_positive_SetGammaPatternMode (void)
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
void test_l1_tvSettings_negative_SetGammaPatternMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetRGBPattern() for all positive invocation scenarios
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
* | 02 | call SetRGBPattern() -  Set the RGBPattern with valid value | 00,00,00 | tvERROR_NONE | Should Pass |
* | 03 | call SetRGBPattern() -  Reset the RGBPattern with another valid value | 100,100,100 | tvERROR_NONE | Should Pass |
* | 04 | call SetRGBPattern() -  Reset the RGBPattern with another valid value | 255,255,255 | tvERROR_NONE | Should Pass |
* | 05 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetRGBPattern (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetRGBPattern() for all negative invocation scenarios
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
* | 01 | call SetRGBPattern() - Set the TV RGBPattern even before TvInit() | 00,00,00 | tvERROR_INVALID_STATE | Should Pass |
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
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetRGBPattern() for all positive invocation scenarios
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
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call TvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetRGBPattern() -  Retrieve the current RGB Pattern with valid arguments | int *, int *, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetRGBPattern() -  Retrieve the current RGB Pattern with valid arguments and validate with above value | int *, int *, int * | tvERROR_NONE | Should Pass |
* | 04 | call TvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetRGBPattern (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetRGBPattern() for all negative invocation scenarios
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
void test_l1_tvSettings_positive_GetOpenCircuitStatus (void)
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
void test_l1_tvSettings_negative_GetOpenCircuitStatus (void)
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
void test_l1_tvSettings_positive_EnableLDIMPixelCompensation (void)
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
void test_l1_tvSettings_negative_EnableLDIMPixelCompensation (void)
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
void test_l1_tvSettings_positive_EnableLDIM (void)
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
void test_l1_tvSettings_negative_EnableLDIM (void)
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
void test_l1_tvSettings_positive_StartLDIMSequenceTest (void)
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
void test_l1_tvSettings_negative_StartLDIMSequenceTest (void)
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
void test_l1_tvSettings_positive_SetBacklightTestMode (void)
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
void test_l1_tvSettings_negative_SetBacklightTestMode (void)
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
void test_l1_tvSettings_positive_EnableWhiteBalance (void)
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
void test_l1_tvSettings_negative_EnableWhiteBalance (void)
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
void test_l1_tvSettings_positive_EnableDynamicContrast (void)
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
void test_l1_tvSettings_negative_EnableDynamicContrast (void)
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
void test_l1_tvSettings_positive_EnableLocalContrast (void)
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
void test_l1_tvSettings_negative_EnableLocalContrast (void)
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
void test_l1_tvSettings_positive_SetWakeupConfig (void)
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
void test_l1_tvSettings_negative_SetWakeupConfig (void)
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
void test_l1_tvSettings_positive_GetPanelIDODM (void)
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
void test_l1_tvSettings_negative_GetPanelIDODM (void)
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
void test_l1_tvSettings_positive_TvSyncCalibrationInfoODM (void)
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
void test_l1_tvSettings_negative_TvSyncCalibrationInfoODM (void)
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
void test_l1_tvSettings_positive_ReadAllModeConfigfileODM (void)
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
void test_l1_tvSettings_negative_ReadAllModeConfigfileODM (void)
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
void test_l1_tvSettings_positive_ConvertVideoFormatToHDRFormatODM (void)
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
void test_l1_tvSettings_negative_ConvertVideoFormatToHDRFormatODM (void)
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
void test_l1_tvSettings_positive_ConvertHDRFormatToContentFormatODM (void)
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
void test_l1_tvSettings_negative_ConvertHDRFormatToContentFormatODM (void)
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

	UT_add_test( pSuite, "TvInit_L1_positive" ,test_l1_tvSettings_positive_TvInit );
	UT_add_test( pSuite, "TvInit_L1_negative" ,test_l1_tvSettings_negative_TvInit );
	UT_add_test( pSuite, "TvTerm_L1_positive" ,test_l1_tvSettings_positive_TvTerm );
	UT_add_test( pSuite, "TvTerm_L1_negative" ,test_l1_tvSettings_negative_TvTerm );
	UT_add_test( pSuite, "GetSupportedVideoFormatsODM_L1_positive" ,test_l1_tvSettings_positive_GetSupportedVideoFormatsODM );
	UT_add_test( pSuite, "GetSupportedVideoFormatsODM_L1_negative" ,test_l1_tvSettings_negative_GetSupportedVideoFormatsODM );
	UT_add_test( pSuite, "GetTVSupportedVideoFormats_L1_positive" ,test_l1_tvSettings_positive_GetTVSupportedVideoFormats );
	UT_add_test( pSuite, "GetTVSupportedVideoFormats_L1_negative" ,test_l1_tvSettings_negative_GetTVSupportedVideoFormats );
	UT_add_test( pSuite, "GetCurrentVideoFormatODM_L1_positive" ,test_l1_tvSettings_positive_GetCurrentVideoFormatODM );
	UT_add_test( pSuite, "GetCurrentVideoFormatODM_L1_negative" ,test_l1_tvSettings_negative_GetCurrentVideoFormatODM );
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
	UT_add_test( pSuite, "GetDriverEquivalentBLForCurrentFmtODM_L1_positive" ,test_l1_tvSettings_positive_GetDriverEquivalentBLForCurrentFmtODM );
	UT_add_test( pSuite, "GetDriverEquivalentBLForCurrentFmtODM_L1_negative" ,test_l1_tvSettings_negative_GetDriverEquivalentBLForCurrentFmtODM );
	UT_add_test( pSuite, "SetBacklightInfoODM_L1_positive" ,test_l1_tvSettings_positive_SetBacklightInfoODM );
	UT_add_test( pSuite, "SetBacklightInfoODM_L1_negative" ,test_l1_tvSettings_negative_SetBacklightInfoODM );
	UT_add_test( pSuite, "GetSupportedBacklightModes_L1_positive" ,test_l1_tvSettings_positive_GetSupportedBacklightModes );
	UT_add_test( pSuite, "GetSupportedBacklightModes_L1_negative" ,test_l1_tvSettings_negative_GetSupportedBacklightModes );
	UT_add_test( pSuite, "GetCurrentBacklightMode_L1_positive" ,test_l1_tvSettings_positive_GetCurrentBacklightMode );
	UT_add_test( pSuite, "GetCurrentBacklightMode_L1_negative" ,test_l1_tvSettings_negative_GetCurrentBacklightMode );
	UT_add_test( pSuite, "SetCurrentBacklightMode_L1_positive" ,test_l1_tvSettings_positive_SetCurrentBacklightMode );
	UT_add_test( pSuite, "SetCurrentBacklightMode_L1_negative" ,test_l1_tvSettings_negative_SetCurrentBacklightMode );
	UT_add_test( pSuite, "GetTVSupportedDimmingModesODM_L1_positive" ,test_l1_tvSettings_positive_GetTVSupportedDimmingModesODM );
	UT_add_test( pSuite, "GetTVSupportedDimmingModesODM_L1_negative" ,test_l1_tvSettings_negative_GetTVSupportedDimmingModesODM );
	UT_add_test( pSuite, "GetTVSupportedDimmingModes_L1_positive" ,test_l1_tvSettings_positive_GetTVSupportedDimmingModes );
	UT_add_test( pSuite, "GetTVSupportedDimmingModes_L1_negative" ,test_l1_tvSettings_negative_GetTVSupportedDimmingModes );
	UT_add_test( pSuite, "SetTVDimmingMode_L1_positive" ,test_l1_tvSettings_positive_SetTVDimmingMode );
	UT_add_test( pSuite, "SetTVDimmingMode_L1_negative" ,test_l1_tvSettings_negative_SetTVDimmingMode );
	UT_add_test( pSuite, "GetTVDimmingMode_L1_positive" ,test_l1_tvSettings_positive_GetTVDimmingMode );
	UT_add_test( pSuite, "GetTVDimmingMode_L1_negative" ,test_l1_tvSettings_negative_GetTVDimmingMode );
	UT_add_test( pSuite, "SaveDynamicBacklight_L1_positive" ,test_l1_tvSettings_positive_SaveDynamicBacklight );
	UT_add_test( pSuite, "SaveDynamicBacklight_L1_negative" ,test_l1_tvSettings_negative_SaveDynamicBacklight );
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
	UT_add_test( pSuite, "GetTVSupportedHLGModes_L1_positive" ,test_l1_tvSettings_positive_GetTVSupportedHLGModes );
	UT_add_test( pSuite, "GetTVSupportedHLGModes_L1_negative" ,test_l1_tvSettings_negative_GetTVSupportedHLGModes );
	UT_add_test( pSuite, "SetTVHLGMode_L1_positive" ,test_l1_tvSettings_positive_SetTVHLGMode );
	UT_add_test( pSuite, "SetTVHLGMode_L1_negative" ,test_l1_tvSettings_negative_SetTVHLGMode );
	UT_add_test( pSuite, "GetTVHLGMode_L1_positive" ,test_l1_tvSettings_positive_GetTVHLGMode );
	UT_add_test( pSuite, "GetTVHLGMode_L1_negative" ,test_l1_tvSettings_negative_GetTVHLGMode );
	UT_add_test( pSuite, "GetTVSupportedHDR10Modes_L1_positive" ,test_l1_tvSettings_positive_GetTVSupportedHDR10Modes );
	UT_add_test( pSuite, "GetTVSupportedHDR10Modes_L1_negative" ,test_l1_tvSettings_negative_GetTVSupportedHDR10Modes );
	UT_add_test( pSuite, "SetTVHDR10Mode_L1_positive" ,test_l1_tvSettings_positive_SetTVHDR10Mode );
	UT_add_test( pSuite, "SetTVHDR10Mode_L1_negative" ,test_l1_tvSettings_negative_SetTVHDR10Mode );
	UT_add_test( pSuite, "GetTVHDR10Mode_L1_positive" ,test_l1_tvSettings_positive_GetTVHDR10Mode );
	UT_add_test( pSuite, "GetTVHDR10Mode_L1_negative" ,test_l1_tvSettings_negative_GetTVHDR10Mode );
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
	UT_add_test( pSuite, "SetWBctrl_L1_positive" ,test_l1_tvSettings_positive_SetWBctrl );
	UT_add_test( pSuite, "SetWBctrl_L1_negative" ,test_l1_tvSettings_negative_SetWBctrl );
	UT_add_test( pSuite, "GetWBctrl_L1_positive" ,test_l1_tvSettings_positive_GetWBctrl );
	UT_add_test( pSuite, "GetWBctrl_L1_negative" ,test_l1_tvSettings_negative_GetWBctrl );
	UT_add_test( pSuite, "SaveColorTemperatureUser_L1_positive" ,test_l1_tvSettings_positive_SaveColorTemperatureUser );
	UT_add_test( pSuite, "SaveColorTemperatureUser_L1_negative" ,test_l1_tvSettings_negative_SaveColorTemperatureUser );
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
	UT_add_test( pSuite, "GetCMSDefault_L1_positive" ,test_l1_tvSettings_positive_GetCMSDefault );
	UT_add_test( pSuite, "GetCMSDefault_L1_negative" ,test_l1_tvSettings_negative_GetCMSDefault );
	UT_add_test( pSuite, "GetDefaultParams_L1_positive" ,test_l1_tvSettings_positive_GetDefaultParams );
	UT_add_test( pSuite, "GetDefaultParams_L1_negative" ,test_l1_tvSettings_negative_GetDefaultParams );
	UT_add_test( pSuite, "GetMaxGainValue_L1_positive" ,test_l1_tvSettings_positive_GetMaxGainValue );
	UT_add_test( pSuite, "GetMaxGainValue_L1_negative" ,test_l1_tvSettings_negative_GetMaxGainValue );
	UT_add_test( pSuite, "EnableGammaMode_L1_positive" ,test_l1_tvSettings_positive_EnableGammaMode );
	UT_add_test( pSuite, "EnableGammaMode_L1_negative" ,test_l1_tvSettings_negative_EnableGammaMode );
	UT_add_test( pSuite, "SetGammaPattern_L1_positive" ,test_l1_tvSettings_positive_SetGammaPattern );
	UT_add_test( pSuite, "SetGammaPattern_L1_negative" ,test_l1_tvSettings_negative_SetGammaPattern );
	UT_add_test( pSuite, "SetGammaTestPoint_L1_positive" ,test_l1_tvSettings_positive_SetGammaTestPoint );
	UT_add_test( pSuite, "SetGammaTestPoint_L1_negative" ,test_l1_tvSettings_negative_SetGammaTestPoint );
	UT_add_test( pSuite, "GetGammaTestPoint_L1_positive" ,test_l1_tvSettings_positive_GetGammaTestPoint );
	UT_add_test( pSuite, "GetGammaTestPoint_L1_negative" ,test_l1_tvSettings_negative_GetGammaTestPoint );
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
	UT_add_test( pSuite, "GetPanelIDODM_L1_positive" ,test_l1_tvSettings_positive_GetPanelIDODM );
	UT_add_test( pSuite, "GetPanelIDODM_L1_negative" ,test_l1_tvSettings_negative_GetPanelIDODM );
	UT_add_test( pSuite, "TvSyncCalibrationInfoODM_L1_positive" ,test_l1_tvSettings_positive_TvSyncCalibrationInfoODM );
	UT_add_test( pSuite, "TvSyncCalibrationInfoODM_L1_negative" ,test_l1_tvSettings_negative_TvSyncCalibrationInfoODM );
	UT_add_test( pSuite, "ReadAllModeConfigfileODM_L1_positive" ,test_l1_tvSettings_positive_ReadAllModeConfigfileODM );
	UT_add_test( pSuite, "ReadAllModeConfigfileODM_L1_negative" ,test_l1_tvSettings_negative_ReadAllModeConfigfileODM );
	UT_add_test( pSuite, "ConvertVideoFormatToHDRFormatODM_L1_positive" ,test_l1_tvSettings_positive_ConvertVideoFormatToHDRFormatODM );
	UT_add_test( pSuite, "ConvertVideoFormatToHDRFormatODM_L1_negative" ,test_l1_tvSettings_negative_ConvertVideoFormatToHDRFormatODM );
	UT_add_test( pSuite, "ConvertHDRFormatToContentFormatODM_L1_positive" ,test_l1_tvSettings_positive_ConvertHDRFormatToContentFormatODM );
	UT_add_test( pSuite, "ConvertHDRFormatToContentFormatODM_L1_negative" ,test_l1_tvSettings_negative_ConvertHDRFormatToContentFormatODM );
	

	return 0;
} 
