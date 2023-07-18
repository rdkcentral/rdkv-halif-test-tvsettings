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
* @file test_l1_tvSettings.c
*^ @page module_name TODO: Required field, name of the main module
*^ @subpage sub_page_name TODO: Add a function group if relevant
*
* ## Module's Role
*^ TODO: Explain the module's role in the system in general
* This is to ensure that the API meets the operational requirements of the module across all vendors.
*
*^ **Pre-Conditions:**  TODO: Add pre-conditions if any@n
*^ **Dependencies:** TODO: Add dependencies if any@n
*
* Ref to API Definition specification documentation : [halSpec.md](../../../docs/halSpec.md)
*/

#include <string.h>
#include <stdlib.h>

#include <ut.h>
#include <ut_log.h>

/**
* @brief Validate tvInit() for all positive invocation scenarios
* 
* This test ensures that the TV Settings module is initialised using tvInit()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 1@n
* 
* **Pre-Conditions:** @n
* None
*
* @post Close the module using tvTerm()
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_tvInit (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate tvInit() for all negative invocation scenarios
* 
* This test ensures that tvERROR_INVALID_STATE is returned if called tvInit() again
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 2@n
* 
* **Pre-Conditions:** @n
* None
*
* @post Close the module using tvTerm()
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call tvInit() -  Re-initialise to get the appropriate error code | void | tvERROR_INVALID_STATE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_negative_tvInit (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate tvSD3toCriSyncInit() for all positive invocation scenarios
* 
* This test ensures that white balance values sync from SD3 to driver
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 3@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call tvSD3toCriSyncInit() -  Sync the white balance SD3 values | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_tvSD3toCriSyncInit (void)
{
	UT_FAIL(This function needs to be implemented!); 
}


/**
* @brief Validate tvSD3toCriSyncInit() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully sync the SD3 values once module is initialized
* 3. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 4@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* | 01 | call tvSD3toCriSyncInit() -  Initialise and Sync the SD3 values using tvSD3toCriSyncInit()| void | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call tvSD3toCriSyncInit() -  Initialise and Sync the SD3 values using tvSD3toCriSyncInit() | void | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_tvSD3toCriSyncInit (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate tvTerm() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 5@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_tvTerm (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate tvTerm() for all neagtive invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully initialize the module
* 3. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 6@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* | 01 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_tvTerm (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVPictureMode() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the TVPictureMode value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 7@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | Call GetTVPictureMode() -  Retrieve the current TVPictureMode with valid arguments | char* | tvERROR_NONE | Should Pass |
* | 03 | call GetTVPictureMode() -  Retrieve the current TVPictureMode with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetTVPictureMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}
/**
* @brief Validate GetTVPictureMode() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the TVPictureMode value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 8@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetTVPictureMode() - Retrieve current TV PictureMode even before tvInit() | char * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetTVPictureMode() -   Retrieve current TV PictureMode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetTVPictureMode() -  Retrieve current TV PictureMode with valid input after tvTerm() | NULL | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetTVPictureMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetTVPictureMode() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the TV PictureMode value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 9@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetBrightness() -  Set the TV PictureMode with valid value | "Entertainment" | tvERROR_NONE | Should Pass |
* | 03 | call SetBrightness() -  Reset the TV PictureMode with another valid value | "Dynamic" | tvERROR_NONE | Should Pass |
* | 04 | call SetBrightness() -  Reset the TV PictureMode with another valid value | "Entertainment" | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetTVPictureMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetTVPictureMode() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the TVPictureMode value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 10@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* | 01 | call SetTVPictureMode() - Set the TV PictureMode even before tvInit() | "Entertainment"  | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetTVPictureMode() -   Set the TV PictureMode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetTVPictureMode() -   Set the TV PictureMode with invalid input | "INVALID"  | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call SetTVPictureMode() -  Set the TV PictureMode with valid input after tvTerm() | "Dynamic" | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetTVPictureMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetBacklight() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the Backlight value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 11@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetBacklight() -  Retrieve the current Backlight with valid arguments |int*| tvERROR_NONE | Should Pass |
* | 03 | call GetBacklight() -  Retrieve the current Backlight with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetBacklight (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetBacklight() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the Backlight value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 12@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetBacklight() -   Retrieve current TV backlight even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetBacklight() -   Retrieve current TV backlight with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetBacklight() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetBacklight (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetBacklight() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the backlight value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 13@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | Call SetBacklight() - Set the backlight with valid value | 8 | tvERROR_NONE | Should Pass |
* | 03 | call SetBacklight() -  Reset the backlight with another valid value | 50 | tvERROR_NONE | Should Pass |
* | 04 | call SetBacklight() -  Reset the backlight with another valid value | 99 | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetBacklight (void)
{
	UT_FAIL(This function needs to be implemented!); 
}


/**
* @brief Validate SetBacklight() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 14@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* | 01 | call SetBacklight() - Set the TV backlight even before tvInit() | 30 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetBacklight() -   Set the TV backlight with invalid input | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetBacklight() -   Set the TV backlight with invalid input | 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetBacklight() -   Set the TV backlight with invalid input | 200 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SetBacklight() -  Set the TV backlight with valid input after tvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetBacklight (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetBrightness() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the brightness value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 15@n
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetBrightness() -  Set the brightness with valid value | 08 | tvERROR_NONE | Should Pass |
* | 03 | call SetBrightness() -  Reset the brightness with another valid value | 50 | tvERROR_NONE | Should Pass |
* | 04 | call SetBrightness() -  Reset the brightness with another valid value | 99 | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetBrightness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetBrightness() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 16@n
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
* | 01 | call SetBrightness() - Set the TV brightness even before tvInit() | 30 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetBrightness() -   Set the TV brightness with invalid input | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetBrightness() -   Set the TV brightness with invalid input | 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetBrightness() -   Set the TV brightness with invalid input | 200 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SetBrightness() -  Set the TV brightness with valid input after tvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetBrightness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetBrightness() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the brightness value once module is initialized
* 3. Close the module using tvTerm()
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetBrightness() -  Retrieve the current brightness with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -  Retrieve the current brightness with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetBrightness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetBrightness() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
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
* | 01 | call GetBrightness() -  Retrieve current TV brightness even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -   Retrieve current TV brightness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetBrightness() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetBrightness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetContrast() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the contrast value once module is initialized
* 3. Close the module using tvTerm()
*  
* @note tvERROR_GENERAL is platform specific and cannot be simulated
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetContrast() -  Set the Contrast with valid value | 08 | tvERROR_NONE | Should Pass |
* | 03 | call SetContrast() -  Reset the Contrast with another valid value | 50 | tvERROR_NONE | Should Pass |
* | 04 | call SetContrast() -  Reset the Contrast with another valid value | 99 | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  Terminate and close the instance of the TV client  | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetContrast() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the contrast value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
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
* | 01 | call SetContrast() - Set the TV contrast even before tvInit() | 30 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetContrast() -   Set the TV contrast with invalid input | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetContrast() -   Set the TV contrast with invalid input | 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetContrast() -   Set the TV contrast with invalid input | 200 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call SetContrast() -  Set the TV contrast with valid input after tvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetContrast() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the Contrast value once module is initialized
* 3. Close the module using tvTerm()
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetContrast() -  Retrieve the current Contrast with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetContrast() -  Retrieve the current Contrast with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetContrast() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the Contrast value once module is initialized
* 3. Close the module using tvTerm()
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
* | 01 | call GetContrast() -  Retrieve current TV contrast even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetContrast() -   Retrieve current TV contrast with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetContrast() -  Retrieve current TV contrast valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetSharpness() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the sharpness value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetSharpness() -  Set the sharpness with valid value | 08 | tvERROR_NONE | Should Pass |
* | 03 | call SetSharpness() -  Reset the sharpness with another valid value | 50 | tvERROR_NONE | Should Pass |
* | 04 | call SetSharpness() -  Reset the sharpness with another valid value | 99 | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |

*/
void test_l1_tvSettings_positive_SetSharpness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetSharpness() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the sharpness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
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
* | 01 | call SetSharpness() - Set the TV sharpness even before tvInit() | 30 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetSharpness() -   Set the TV sharpness with invalid input | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetSharpness() -   Set the TV sharpness with invalid input | 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetSharpness() -   Set the TV sharpness with invalid input | 200 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SetSharpness() -  Set the TV sharpness with valid input after tvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetSharpness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetSharpness() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the sharpness value once module is initialized
* 3. Close the module using tvTerm()
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetSharpness() -  Retrieve the current sharpness with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetSharpness() -  Retrieve the current sharpness with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetSharpness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetSharpness() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the sharpness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
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
* | 01 | call GetSharpness() -  Retrieve current TV sharpness even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetSharpness() -   Retrieve current TV sharpness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetSharpness() -  Retrieve current TV sharpness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetSharpness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetSaturation() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the saturation value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetSaturation() -  Set the saturation with valid value | 08 | tvERROR_NONE | Should Pass |
* | 03 | call SetSaturation() -  Reset the saturation with another valid value | 50 | tvERROR_NONE | Should Pass |
* | 04 | call SetSaturation() -  Reset the saturation with another valid value | 99 | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetSaturation() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the saturation value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
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
* | 01 | call SetSaturation() - Set the TV saturation even before tvInit() | 30 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetSaturation() -   Set the TV saturation with invalid input | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetSaturation() -   Set the TV saturation with invalid input | 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetSaturation() -   Set the TV saturation with invalid input | 200 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SetSaturation() -  Set the TV saturation with valid input after tvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetSaturation() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the saturation value once module is initialized
* 3. Close the module using tvTerm()
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetSaturation() -  Retrieve the current saturation with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetSaturation() -  Retrieve the current saturation with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetSaturation() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the saturation value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
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
* | 01 | call GetSaturation() -  Retrieve current TV saturation even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetSaturation() -   Retrieve current TV saturation with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetSaturation() -  Retrieve current TV saturation valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetHue() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the hue value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetHue() -  Set the hue with valid value | 08 | tvERROR_NONE | Should Pass |
* | 03 | call SetHue() -  Reset the hue with another valid value | 50 | tvERROR_NONE | Should Pass |
* | 04 | call SetHue() -  Reset the hue with another valid value | 99 | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetHue() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the hue value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
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
* | 01 | call SetHue() - Set the TV hue even before tvInit() | 30 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetHue() -   Set the TV hue with invalid input | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetHue() -   Set the TV hue with invalid input | 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetHue() -   Set the TV hue with invalid input | 200 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call SetHue() -  Set the TV hue with valid input after tvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetHue() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the Hue value once module is initialized
* 3. Close the module using tvTerm()
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetHue() -  Retrieve the current Hue with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetHue() -  Retrieve the current Hue with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetHue() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the Hue value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
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
* | 01 | call GetHue() -  Retrieve current TV Hue even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetHue() -  Retrieve current TV Hue with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetHue() -  Retrieve current TV Hue valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemperature() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the ColorTemperature value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemperature() -  Set the ColorTemperature with valid value | tvColorTemp_STANDARD  | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemperature() -  Reset the ColorTemperature with another valid value | tvColorTemp_WARM | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemperature() -  Reset the ColorTemperature with another valid value | tvColorTemp_COLD | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemperature() -  Reset the ColorTemperature with another valid value | tvColorTemp_USER | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemperature (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemperature() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the ColorTemperature value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
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
* | 01 | call SetColorTemperature() - Set the TV ColorTemperature even before tvInit() | tvColorTemp_WARM | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemperature() -   Set the TV ColorTemperature with invalid input | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemperature() -   Set the TV ColorTemperature with invalid input | 7 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemperature() -   Set the TV ColorTemperature with invalid input | 20 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemperature() -  Set the TV ColorTemperature with valid input after tvTerm() | tvColorTemp_USER | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemperature (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemperature() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the ColorTemperature value once module is initialized
* 3. Close the module using tvTerm()
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemperature() -  Retrieve the current ColorTemperature with valid arguments | tvColorTemp_t  * | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemperature() -  Retrieve the current ColorTemperature with valid arguments and validate with above value | tvColorTemp_t  * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemperature (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemperature() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the ColorTemperature value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
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
* | 01 | call GetColorTemperature() -  Retrieve current TV ColorTemperature even before tvInit() | tvColorTemp_t  * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemperature() -   Retrieve current TV ColorTemperature with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemperature() -  Retrieve current TV ColorTemperature valid arguments | tvColorTemp_t  * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetColorTemperature (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetAspectRatio() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the AspectRatio value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetAspectRatio() -  Set the AspectRatio with valid value | tvDisplayMode_4x3  | tvERROR_NONE | Should Pass |
* | 03 | call SetAspectRatio() -  Reset the AspectRatio with another valid value | tvDisplayMode_16x9 | tvERROR_NONE | Should Pass |
* | 04 | call SetAspectRatio() -  Reset the AspectRatio with another valid value | tvDisplayMode_FULL | tvERROR_NONE | Should Pass |
* | 04 | call SetAspectRatio() -  Reset the AspectRatio with another valid value | tvDisplayMode_NORMAL | tvERROR_NONE | Should Pass |
* | 04 | call SetAspectRatio() -  Reset the AspectRatio with another valid value | tvDisplayMode_AUTO | tvERROR_NONE | Should Pass |
* | 04 | call SetAspectRatio() -  Reset the AspectRatio with another valid value | tvDisplayMode_DIRECT | tvERROR_NONE | Should Pass |
* | 04 | call SetAspectRatio() -  Reset the AspectRatio with another valid value | tvDisplayMode_ZOOM | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetAspectRatio (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetAspectRatio() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the AspectRatio value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
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
* | 01 | call SetAspectRatio() - Set the TV AspectRatio even before tvInit() | tvDisplayMode_16x9 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetAspectRatio() -   Set the TV AspectRatio with invalid input | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetAspectRatio() -   Set the TV AspectRatio with invalid input | 100 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call SetAspectRatio() -  Set the TV AspectRatio with valid input after tvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetAspectRatio (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetAspectRatio() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the AspectRatio value once module is initialized
* 3. Close the module using tvTerm()
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetAspectRatio() -  Retrieve the current AspectRatio with valid arguments | tvDisplayMode_t * | tvERROR_NONE | Should Pass |
* | 03 | call GetAspectRatio() -  Retrieve the current AspectRatio with valid arguments and validate with above value | tvDisplayMode_t * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetAspectRatio (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetAspectRatio() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the AspectRatio value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
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
* | 01 | call GetAspectRatio() -  Retrieve current TV AspectRatio even before tvInit() | tvDisplayMode_t * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetAspectRatio() -   Retrieve current TV AspectRatio with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetAspectRatio() -  Retrieve current TV AspectRatio valid arguments | tvDisplayMode_t * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetAspectRatio (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetSupportedBacklightModes() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the SupportedBacklightModes value once module is initialized
* 3. Close the module using tvTerm()
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetSupportedBacklightModes() -  Retrieve the current SupportedBacklightModes with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetSupportedBacklightModes() -  Retrieve the current SupportedBacklightModes with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetSupportedBacklightModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetSupportedBacklightModes() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the SupportedBacklightModes value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
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
* | 01 | call GetSupportedBacklightModes() -  Retrieve current TV SupportedBacklightModes even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetSupportedBacklightModes() -   Retrieve current TV SupportedBacklightModes with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetSupportedBacklightModes() -  Retrieve current TV SupportedBacklightModes valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetSupportedBacklightModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentBacklightMode() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the CurrentBacklightMode value once module is initialized
* 3. Close the module using tvTerm()
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetCurrentBacklightMode() -  Retrieve the current CurrentBacklightMode with valid arguments | tvBacklightMode_t  * | tvERROR_NONE | Should Pass |
* | 03 | call GetCurrentBacklightMode() -  Retrieve the current CurrentBacklightMode with valid arguments and validate with above value | tvBacklightMode_t  * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetCurrentBacklightMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentBacklightMode() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the CurrentBacklightMode value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
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
* | 01 | call GetCurrentBacklightMode() -  Retrieve current TV CurrentBacklightMode even before tvInit() | tvBacklightMode_t * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetCurrentBacklightMode() -   Retrieve current TV CurrentBacklightMode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetCurrentBacklightMode() -  Retrieve current TV CurrentBacklightMode valid arguments | tvBacklightMode_t * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetCurrentBacklightMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}
/**
* @brief Validate SetCurrentBacklightMode() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the CurrentBacklightMode value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetCurrentBacklightMode() -  Set the CurrentBacklightMode with valid value | tvBacklightMode_NONE  | tvERROR_NONE | Should Pass |
* | 03 | call SetCurrentBacklightMode() -  Reset the CurrentBacklightMode with another valid value | tvBacklightMode_AMBIENT | tvERROR_NONE | Should Pass |
* | 04 | call SetCurrentBacklightMode() -  Reset the CurrentBacklightMode with another valid value | tvBacklightMode_MANUAL | tvERROR_NONE | Should Pass |
* | 05 | call SetCurrentBacklightMode() -  Reset the CurrentBacklightMode with another valid value | tvBacklightMode_ECO | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SetCurrentBacklightMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetCurrentBacklightMode() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the CurrentBacklightMode value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 48@n
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
* | 01 | call SetCurrentBacklightMode() - Set the TV CurrentBacklightMode even before tvInit() | tvBacklightMode_AMBIENT | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetCurrentBacklightMode() -   Set the TV CurrentBacklightMode with invalid input | tvBacklightMode_INVALID | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetCurrentBacklightMode() -   Set the TV CurrentBacklightMode with invalid input | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetCurrentBacklightMode() -   Set the TV CurrentBacklightMode with invalid input | 20 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SetCurrentBacklightMode() -  Set the TV CurrentBacklightMode with valid input after tvTerm() | tvBacklightMode_MANUAL | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetCurrentBacklightMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentVideoFormat() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the CurrentVideoFormat value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 49@n
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetCurrentVideoFormat() -  Retrieve the current CurrentVideoFormat with valid arguments | tvVideoHDRFormat_t * | tvERROR_NONE | Should Pass |
* | 03 | call GetCurrentVideoFormat() -  Retrieve the current CurrentVideoFormat with valid arguments and validate with above value | tvVideoHDRFormat_t * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetCurrentVideoFormat (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentVideoFormat() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the CurrentVideoFormat value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 50@n
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
* | 01 | call GetCurrentVideoFormat() -  Retrieve current TV CurrentVideoFormat even before tvInit() | tvVideoHDRFormat_t * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetCurrentVideoFormat() -   Retrieve current TV CurrentVideoFormat with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetCurrentVideoFormat() -  Retrieve current TV CurrentVideoFormat valid arguments | tvVideoHDRFormat_t * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetCurrentVideoFormat (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetVideoResolution() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the VideoResolution value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 51@n
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetVideoResolution() -  Retrieve the current VideoResolution with valid arguments | tvResolutionParam_t * | tvERROR_NONE | Should Pass |
* | 03 | call GetVideoResolution() -  Retrieve the current VideoResolution with valid arguments and validate with above value | tvResolutionParam_t * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetVideoResolution (void)
{
	UT_FAIL(This function needs to be implemented!); 
}
/**
* @brief Validate GetVideoResolution() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the VideoResolution value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 52@n
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
* | 01 | call GetVideoResolution() -  Retrieve current TV VideoResolution even before tvInit() | tvResolutionParam_t * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetVideoResolution() -   Retrieve current TV VideoResolution with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetVideoResolution() -  Retrieve current TV VideoResolution valid arguments | tvResolutionParam_t * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetVideoResolution (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetVideoFrameRate() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the VideoFrameRate value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 53@n
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetVideoFrameRate() -  Retrieve the current VideoFrameRate with valid arguments | tvVideoFrameRate_t * | tvERROR_NONE | Should Pass |
* | 03 | call GetVideoFrameRate() -  Retrieve the current VideoFrameRate with valid arguments and validate with above value | tvVideoFrameRate_t * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetVideoFrameRate (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetVideoFrameRate() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the VideoFrameRate value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 54@n
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
* | 01 | call GetVideoFrameRate() -  Retrieve current TV VideoFrameRate even before tvInit() | tvVideoFrameRate_t * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetVideoFrameRate() -   Retrieve current TV VideoFrameRate with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetVideoFrameRate() -  Retrieve current TV VideoFrameRate valid arguments | tvVideoFrameRate_t * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetVideoFrameRate (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate setWakeupConfig() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the WakeupConfig value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 55@n
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call setWakeupConfig() -  Set the WakeupConfig with valid value | tvWakeupSrc_VOICE , flase | tvERROR_NONE | Should Pass |
* | 03 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_VOICE , true | tvERROR_NONE | Should Pass |
* | 04 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_PRESENCE_DETECTION, flase | tvERROR_NONE | Should Pass |
* | 05 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_PRESENCE_DETECTION, true | tvERROR_NONE | Should Pass |
* | 06 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_BLUETOOTH, flase | tvERROR_NONE | Should Pass |
* | 07 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_BLUETOOTH, true | tvERROR_NONE | Should Pass |
* | 08 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_WIFI, flase | tvERROR_NONE | Should Pass |
* | 09 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_WIFI, true | tvERROR_NONE | Should Pass |
* | 10 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_IR, flase | tvERROR_NONE | Should Pass |
* | 11 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_IR, true | tvERROR_NONE | Should Pass |
* | 12 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_POWER_KEY, flase | tvERROR_NONE | Should Pass |
* | 13 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_POWER_KEY, true | tvERROR_NONE | Should Pass |
* | 14 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_TIMER, flase | tvERROR_NONE | Should Pass |
* | 15 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_TIMER, true | tvERROR_NONE | Should Pass |
* | 16 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_CEC, flase | tvERROR_NONE | Should Pass |
* | 17 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_CEC, true | tvERROR_NONE | Should Pass |
* | 18 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_LAN, flase | tvERROR_NONE | Should Pass |
* | 19 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_LAN, true | tvERROR_NONE | Should Pass |
* | 20 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_setWakeupConfig (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate setWakeupConfig() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the WakeupConfig value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 56@n
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
* | 01 | call setWakeupConfig() - Set the TV brightness even before tvInit() | tvWakeupSrc_LAN, true | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call setWakeupConfig() -   Set the TV brightness with invalid input | tvWakeupSrc_MAX, true  | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call setWakeupConfig() -   Set the TV brightness with invalid input | tvWakeupSrc_MAX, false  | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call setWakeupConfig() -  Set the TV brightness with valid input after tvTerm() | tvWakeupSrc_CEC, false  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_setWakeupConfig (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetRGBPattern() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the RGBPattern value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 57@n
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetRGBPattern() -  Set the RGBPattern with valid value | 08,08,08 | tvERROR_NONE | Should Pass |
* | 03 | call SetRGBPattern() -  Reset the RGBPattern with another valid value | 126,126,126 | tvERROR_NONE | Should Pass |
* | 04 | call SetRGBPattern() -  Reset the RGBPattern with another valid value | 254,254,254 | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetRGBPattern (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetRGBPattern() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the RGBPattern value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 58@n
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
* | 01 | call SetRGBPattern() - Set the TV RGBPattern even before tvInit() | 08,08,08 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetRGBPattern() -   Set the TV RGBPattern with invalid input | -1, -1, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetRGBPattern() -   Set the TV RGBPattern with invalid input | 256, 256, 256 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetRGBPattern() -   Set the TV RGBPattern with invalid input | 999, 999, 999 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SetRGBPattern() -  Set the TV RGBPattern with valid input after tvTerm() | 254,254,254 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetRGBPattern (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetRGBPattern() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the RGBPattern value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 59@n
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetRGBPattern() -  Retrieve the current brightness with valid arguments | int *, int *, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetRGBPattern() -  Retrieve the current brightness with valid arguments and validate with above value | int *, int *, int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetRGBPattern (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetRGBPattern() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the RGBPattern value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 60@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetRGBPattern() -  Retrieve current TV RGBPattern even before tvInit() | int *, int *, int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetRGBPattern() -   Retrieve current TV RGBPattern with invalid input | NULL, int *, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call GetRGBPattern() -   Retrieve current TV RGBPattern with invalid input | int *, NULL, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call GetRGBPattern() -   Retrieve current TV RGBPattern with invalid input | int *, int *, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetRGBPattern() -  Retrieve current TV RGBPattern valid arguments | int *, int *, int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetRGBPattern (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetGrayPattern() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the GrayPattern value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 61@n
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetGrayPattern() -  Set the GrayPattern with valid value | 08 | tvERROR_NONE | Should Pass |
* | 03 | call SetGrayPattern() -  Reset the GrayPattern with another valid value | 126 | tvERROR_NONE | Should Pass |
* | 04 | call SetGrayPattern() -  Reset the GrayPattern with another valid value | 254 | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetGrayPattern (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetGrayPattern() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the GrayPattern value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 62@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetGrayPattern() - Set the TV GrayPattern even before tvInit() | 30 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetGrayPattern() -   Set the TV GrayPattern with invalid input | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetGrayPattern() -   Set the TV GrayPattern with invalid input | 256 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call SetGrayPattern() -  Set the TV GrayPattern with valid input after tvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetGrayPattern (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetGrayPattern() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the GrayPattern value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 63@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetGrayPattern() -  Retrieve the current GrayPattern with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetGrayPattern() -  Retrieve the current GrayPattern with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetGrayPattern (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetGrayPattern() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the GrayPattern value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 64@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetGrayPattern() -  Retrieve current TV GrayPattern even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetGrayPattern() -   Retrieve current TV GrayPattern with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetGrayPattern() -  Retrieve current TV GrayPattern valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetGrayPattern (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Rgain() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the ColorTemp Rgain value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 65@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_Rgain() -  Set the ColorTemp Rgain with valid value | tvColorTemp_STANDARD , 08 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Rgain() -  Reset the ColorTemp Rgain with another valid value | tvColorTemp_STANDARD, 2046 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Rgain() -  Reset the ColorTemp Rgain with another valid value | tvColorTemp_WARM , 08 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_Rgain() -  Reset the ColorTemp Rgain with another valid value | tvColorTemp_WARM, 2046 | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_Rgain() -  Reset the ColorTemp Rgain with another valid value | tvColorTemp_COLD, 08 | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_Rgain() -  Reset the ColorTemp Rgain with another valid value | tvColorTemp_COLD, 2046 | tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_Rgain() -  Reset the ColorTemp Rgain with another valid value | tvColorTemp_USER, 08 | tvERROR_NONE | Should Pass |
* | 09 | call SetColorTemp_Rgain() -  Reset the ColorTemp Rgain with another valid value | tvColorTemp_USER, 2046 | tvERROR_NONE | Should Pass |
* | 10 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemp_Rgain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Rgain() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the ColorTemp Rgain value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 66@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetColorTemp_Rgain() - Set the TV ColorTemp Rgain even before tvInit() |  tvColorTemp_COLD, 2046 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Rgain() -   Set the TV ColorTemp Rgain with invalid input |tvColorTemp_COLD, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_Rgain() -   Set the TV ColorTemp Rgain with invalid input |tvColorTemp_COLD, 2048 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_Rgain() -   Set the TV ColorTemp Rgain with invalid input | tvColorTemp_MAX, 100 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_Rgain() -  Set the TV ColorTemp Rgain with valid input after tvTerm() | tvColorTemp_COLD, 2046 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_Rgain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Rgain() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the ColorTemp Rgain value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 67@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_Rgain() -  Retrieve the current ColorTemp Rgain with valid arguments |tvColorTemp_STANDARD, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Rgain() -  Retrieve the current ColorTemp Rgain with valid arguments and validate with above value |tvColorTemp_STANDARD, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Rgain() -  Retrieve the current ColorTemp Rgain with valid arguments and validate with above value |tvColorTemp_WARM, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Rgain() -  Retrieve the current ColorTemp Rgain with valid arguments and validate with above value |tvColorTemp_COLD, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Rgain() -  Retrieve the current ColorTemp Rgain with valid arguments and validate with above value |tvColorTemp_USER, int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_Rgain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Rgain() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the ColorTemp Rgain value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE

*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 68@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetColorTemp_Rgain() -  Retrieve current TV ColorTemp Rgain even before tvInit() | tvColorTemp_STANDARD, int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Rgain() -   Retrieve current TV ColorTemp Rgain with invalid input | tvColorTemp_STANDARD, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call GetColorTemp_Rgain() -   Retrieve current TV ColorTemp Rgain with invalid input | tvColorTemp_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_Rgain() -  Retrieve current TV ColorTemp Rgain valid arguments | tvColorTemp_WARM, int * | tvERROR_INVALID_STATE | Should Pass ||
*/
void test_l1_tvSettings_negative_GetColorTemp_Rgain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Ggain() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the ColorTemp Ggain value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 69@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_Ggain() -  Set the ColorTemp Ggain with valid value | tvColorTemp_STANDARD , 08 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Ggain() -  Reset the ColorTemp Ggain with another valid value | tvColorTemp_STANDARD, 2046 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Ggain() -  Reset the ColorTemp Ggain with another valid value | tvColorTemp_WARM , 08 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_Ggain() -  Reset the ColorTemp Ggain with another valid value | tvColorTemp_WARM, 2046 | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_Ggain() -  Reset the ColorTemp Ggain with another valid value | tvColorTemp_COLD, 08 | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_Ggain() -  Reset the ColorTemp Ggain with another valid value | tvColorTemp_COLD, 2046 | tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_Ggain() -  Reset the ColorTemp Ggain with another valid value | tvColorTemp_USER, 08 | tvERROR_NONE | Should Pass |
* | 09 | call SetColorTemp_Ggain() -  Reset the ColorTemp Ggain with another valid value | tvColorTemp_USER, 2046 | tvERROR_NONE | Should Pass |
* | 10 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemp_Ggain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Ggain() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the ColorTemp Ggain value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 70@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetColorTemp_Ggain() - Set the TV ColorTemp Ggain  even before tvInit() |  tvColorTemp_COLD, 2046 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Ggain() -   Set the TV ColorTemp Ggain with invalid input |tvColorTemp_COLD, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_Ggain() -   Set the TV ColorTemp Ggain  with invalid input |tvColorTemp_COLD, 2048 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_Ggain() -   Set the TV ColorTemp Ggain  with invalid input | tvColorTemp_MAX, 100 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_Ggain() -  Set the TV ColorTemp Ggain  with valid input after tvTerm() | tvColorTemp_COLD, 2046 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_Ggain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Ggain() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the ColorTemp Ggain value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 71@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_Ggain() -  Retrieve the current ColorTemp Ggain with valid arguments |tvColorTemp_STANDARD, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Ggain() -  Retrieve the current ColorTemp Ggain with valid arguments and validate with above value |tvColorTemp_STANDARD, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Ggain() -  Retrieve the current ColorTemp Ggain with valid arguments and validate with above value |tvColorTemp_WARM, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Ggain() -  Retrieve the current ColorTemp Ggain with valid arguments and validate with above value |tvColorTemp_COLD, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Ggain() -  Retrieve the current ColorTemp Ggain with valid arguments and validate with above value |tvColorTemp_USER, int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_Ggain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Ggain() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the ColorTemp Ggain value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE

*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 72@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetColorTemp_Ggain() -  Retrieve current TV ColorTemp Ggain even before tvInit() | tvColorTemp_STANDARD, int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Ggain() -   Retrieve current TV ColorTemp Ggain with invalid input | tvColorTemp_STANDARD, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call GetColorTemp_Ggain() -   Retrieve current TV ColorTemp Ggain with invalid input | tvColorTemp_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_Ggain() -  Retrieve current TV ColorTemp Ggain valid arguments | tvColorTemp_WARM, int * | tvERROR_INVALID_STATE | Should Pass ||
*/
void test_l1_tvSettings_negative_GetColorTemp_Ggain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Bgain() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the ColorTemp Bgain value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 73@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_Bgain() -  Set the ColorTemp Bgain with valid value | tvColorTemp_STANDARD , 08 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Bgain() -  Reset the ColorTemp Bgain with another valid value | tvColorTemp_STANDARD, 2046 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Bgain() -  Reset the ColorTemp Bgain with another valid value | tvColorTemp_WARM , 08 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_Bgain() -  Reset the ColorTemp Bgain with another valid value | tvColorTemp_WARM, 2046 | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_Bgain() -  Reset the ColorTemp Bgain with another valid value | tvColorTemp_COLD, 08 | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_Bgain() -  Reset the ColorTemp Bgain with another valid value | tvColorTemp_COLD, 2046 | tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_Bgain() -  Reset the ColorTemp Bgain with another valid value | tvColorTemp_USER, 08 | tvERROR_NONE | Should Pass |
* | 09 | call SetColorTemp_Bgain() -  Reset the ColorTemp Bgain with another valid value | tvColorTemp_USER, 2046 | tvERROR_NONE | Should Pass |
* | 10 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemp_Bgain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Bgain() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the ColorTemp Bgain value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 74@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetColorTemp_Bgain() - Set the TV ColorTemp Bgain even before tvInit() |  tvColorTemp_COLD, 2046 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Bgain() -   Set the TV ColorTemp Bgain with invalid input |tvColorTemp_COLD, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_Bgain() -   Set the TV ColorTemp Bgain with invalid input |tvColorTemp_COLD, 2048 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_Bgain() -   Set the TV ColorTemp Bgain with invalid input | tvColorTemp_MAX, 100 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_Bgain() -  Set the TV ColorTemp Bgain with valid input after tvTerm() | tvColorTemp_COLD, 2046 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_Bgain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Bgain() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the ColorTemp Bgain value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 75@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_Bgain() -  Retrieve the current ColorTemp Bgain with valid arguments |tvColorTemp_STANDARD, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Bgain() -  Retrieve the current ColorTemp Bgain with valid arguments and validate with above value |tvColorTemp_STANDARD, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Bgain() -  Retrieve the current ColorTemp Bgain with valid arguments and validate with above value |tvColorTemp_WARM, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Bgain() -  Retrieve the current ColorTemp Bgain with valid arguments and validate with above value |tvColorTemp_COLD, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Bgain() -  Retrieve the current ColorTemp Bgain with valid arguments and validate with above value |tvColorTemp_USER, int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_Bgain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Bgain() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the ColorTemp Bgain value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE

*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 76@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetColorTemp_Bgain() -  Retrieve current TV ColorTemp Bgain even before tvInit() | tvColorTemp_STANDARD, int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Bgain() -   Retrieve current TV ColorTemp Bgain with invalid input | tvColorTemp_STANDARD, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call GetColorTemp_Bgain() -   Retrieve current TV ColorTemp Bgain with invalid input | tvColorTemp_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_Bgain() -  Retrieve current TV ColorTemp Bgain valid arguments | tvColorTemp_WARM, int * | tvERROR_INVALID_STATE | Should Pass ||
*/
void test_l1_tvSettings_negative_GetColorTemp_Bgain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_R_post_offset() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the ColorTemp R_post_offset value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 77@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_R_post_offset() -  Set the ColorTemp R_post_offset with valid value | tvColorTemp_STANDARD, -1024 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_R_post_offset() -  Reset the ColorTemp R_post_offset with another valid value |  tvColorTemp_WARM, 1024 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_R_post_offset() -  Reset the ColorTemp R_post_offset with another valid value | tvColorTemp_COLD, 0 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_R_post_offset() -  Reset the ColorTemp R_post_offset with another valid value | tvColorTemp_USER, 500 | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemp_R_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_R_post_offset() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the ColorTemp R_post_offset value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 78@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetColorTemp_R_post_offset() - Set the TV ColorTemp R_post_offset even before tvInit() | tvColorTemp_STANDARD, 104 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_R_post_offset() -   Set the TV ColorTemp R_post_offset with invalid input | tvColorTemp_WARM, -1025 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetColorTemp_R_post_offset() -   Set the TV ColorTemp R_post_offset with invalid input | tvColorTemp_COLD, 1025 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetColorTemp_R_post_offset() -   Set the TV ColorTemp R_post_offset with invalid input | tvColorTemp_MAX, 500 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetColorTemp_R_post_offset() -   Set the TV ColorTemp R_post_offset with invalid input | tvColorTemp_MAX, -1027 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_R_post_offset() -  Set the TV ColorTemp R_post_offset with valid input after tvTerm() | tvColorTemp_STANDARD, 10 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_R_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_R_post_offset() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the ColorTemp R_post_offset value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 80@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_R_post_offset() -  Retrieve the current ColorTemp R_post_offset with valid arguments | tvColorTemp_WARM, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_R_post_offset() -  Retrieve the current ColorTemp R_post_offset with valid arguments and validate with above value | tvColorTemp_WARM, int * | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_R_post_offset() -  Retrieve the current ColorTemp R_post_offset with valid arguments | tvColorTemp_STANDARD, int * | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_R_post_offset() -  Retrieve the current ColorTemp R_post_offset with valid arguments and validate with above value | tvColorTemp_STANDARD, int * | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_R_post_offset() -  Retrieve the current ColorTemp R_post_offset with valid arguments | tvColorTemp_COLD, int * | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_R_post_offset() -  Retrieve the current ColorTemp R_post_offset with valid arguments | tvColorTemp_USER, int * | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_R_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_R_post_offset() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the ColorTemp R_post_offset value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 81@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetColorTemp_R_post_offset() -  Retrieve current TV ColorTemp R_post_offset even before tvInit() |  tvColorTemp_COLD, int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_R_post_offset() -   Retrieve current TV ColorTemp R_post_offset with invalid input |  tvColorTemp_COLD, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_R_post_offset() -   Retrieve current TV ColorTemp R_post_offset with invalid input |  tvColorTemp_STANDARD, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_R_post_offset() -   Retrieve current TV ColorTemp R_post_offset with invalid input |  tvColorTemp_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call GetColorTemp_R_post_offset() -  Retrieve current TV ColorTemp R_post_offset valid arguments |  tvColorTemp_WARM, int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetColorTemp_R_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_G_post_offset() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the ColorTemp G_post_offset value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 82@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_G_post_offset() -  Set the ColorTemp G_post_offset with valid value | tvColorTemp_STANDARD, -1024 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_G_post_offset() -  Reset the ColorTemp G_post_offset with another valid value |  tvColorTemp_WARM, 1024 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_G_post_offset() -  Reset the ColorTemp G_post_offset with another valid value | tvColorTemp_COLD, 0 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_G_post_offset() -  Reset the ColorTemp G_post_offset with another valid value | tvColorTemp_USER, 500 | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemp_G_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_G_post_offset() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the ColorTemp G_post_offset value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 83@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetColorTemp_G_post_offset() - Set the TV ColorTemp G_post_offset even before tvInit() | tvColorTemp_STANDARD, 104 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_G_post_offset() -   Set the TV ColorTemp G_post_offset with invalid input | tvColorTemp_WARM, -1025 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetColorTemp_G_post_offset() -   Set the TV ColorTemp G_post_offset with invalid input | tvColorTemp_COLD, 1025 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetColorTemp_G_post_offset() -   Set the TV ColorTemp G_post_offset with invalid input | tvColorTemp_MAX, 500 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetColorTemp_G_post_offset() -   Set the TV ColorTemp G_post_offset with invalid input | tvColorTemp_MAX, -1027 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_G_post_offset() -  Set the TV ColorTemp G_post_offset with valid input after tvTerm() | tvColorTemp_STANDARD, 10 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_G_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_G_post_offset() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the ColorTemp G_post_offset value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 84@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_G_post_offset() -  Retrieve the current ColorTemp G_post_offset with valid arguments | tvColorTemp_WARM, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_G_post_offset() -  Retrieve the current ColorTemp G_post_offset with valid arguments and validate with above value | tvColorTemp_WARM, int * | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_G_post_offset() -  Retrieve the current ColorTemp G_post_offset with valid arguments | tvColorTemp_STANDARD, int * | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_G_post_offset() -  Retrieve the current ColorTemp G_post_offset with valid arguments and validate with above value | tvColorTemp_STANDARD, int * | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_G_post_offset() -  Retrieve the current ColorTemp G_post_offset with valid arguments | tvColorTemp_COLD, int * | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_G_post_offset() -  Retrieve the current ColorTemp G_post_offset with valid arguments | tvColorTemp_USER, int * | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_G_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_G_post_offset() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the ColorTemp G_post_offset value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 85@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetColorTemp_G_post_offset() -  Retrieve current TV ColorTemp G_post_offset even before tvInit() |  tvColorTemp_COLD, int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_G_post_offset() -   Retrieve current TV ColorTemp G_post_offset with invalid input |  tvColorTemp_COLD, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_G_post_offset() -   Retrieve current TV ColorTemp G_post_offset with invalid input |  tvColorTemp_STANDARD, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_G_post_offset() -   Retrieve current TV ColorTemp G_post_offset with invalid input |  tvColorTemp_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call GetColorTemp_G_post_offset() -  Retrieve current TV ColorTemp G_post_offset valid arguments |  tvColorTemp_WARM, int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetColorTemp_G_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_B_post_offset() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the ColorTemp B_post_offset value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 86@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_B_post_offset() -  Set the ColorTemp B_post_offset with valid value | tvColorTemp_STANDARD, -1024 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_B_post_offset() -  Reset the ColorTemp B_post_offset with another valid value |  tvColorTemp_WARM, 1024 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_B_post_offset() -  Reset the ColorTemp B_post_offset with another valid value | tvColorTemp_COLD, 0 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_B_post_offset() -  Reset the ColorTemp B_post_offset with another valid value | tvColorTemp_USER, 500 | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemp_B_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_B_post_offset() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the ColorTemp B_post_offset value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 87@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetColorTemp_B_post_offset() - Set the TV ColorTemp B_post_offset even before tvInit() | tvColorTemp_STANDARD, 104 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_B_post_offset() -   Set the TV ColorTemp B_post_offset with invalid input | tvColorTemp_WARM, -1025 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetColorTemp_B_post_offset() -   Set the TV ColorTemp B_post_offset with invalid input | tvColorTemp_COLD, 1025 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetColorTemp_B_post_offset() -   Set the TV ColorTemp B_post_offset with invalid input | tvColorTemp_MAX, 500 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetColorTemp_B_post_offset() -   Set the TV ColorTemp B_post_offset with invalid input | tvColorTemp_MAX, -1027 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_B_post_offset() -  Set the TV ColorTemp B_post_offset with valid input after tvTerm() | tvColorTemp_STANDARD, 10 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_B_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_B_post_offset() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the ColorTemp B_post_offset value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 88@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_B_post_offset() -  Retrieve the current ColorTemp B_post_offset with valid arguments | tvColorTemp_WARM, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_B_post_offset() -  Retrieve the current ColorTemp B_post_offset with valid arguments and validate with above value | tvColorTemp_WARM, int * | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_B_post_offset() -  Retrieve the current ColorTemp B_post_offset with valid arguments | tvColorTemp_STANDARD, int * | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_B_post_offset() -  Retrieve the current ColorTemp B_post_offset with valid arguments and validate with above value | tvColorTemp_STANDARD, int * | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_B_post_offset() -  Retrieve the current ColorTemp B_post_offset with valid arguments | tvColorTemp_COLD, int * | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_B_post_offset() -  Retrieve the current ColorTemp B_post_offset with valid arguments | tvColorTemp_USER, int * | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_B_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_B_post_offset() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the ColorTemp B_post_offset value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 89@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetColorTemp_B_post_offset() -  Retrieve current TV ColorTemp B_post_offset even before tvInit() |  tvColorTemp_COLD, int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_B_post_offset() -   Retrieve current TV ColorTemp B_post_offset with invalid input |  tvColorTemp_COLD, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_B_post_offset() -   Retrieve current TV ColorTemp B_post_offset with invalid input |  tvColorTemp_STANDARD, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_B_post_offset() -   Retrieve current TV ColorTemp B_post_offset with invalid input |  tvColorTemp_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call GetColorTemp_B_post_offset() -  Retrieve current TV ColorTemp B_post_offset valid arguments |  tvColorTemp_WARM, int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetColorTemp_B_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Rgain_onSource() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the ColorTemp Rgain_onSource value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 90@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value | tvColorTemp_STANDARD, 08, HDMI_OFFSET, 0| tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Rgain_onSource() -  Reset the ColorTemp Rgain_onSource with another valid value | tvColorTemp_COLD, 500, TV_OFFSET, 0 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Rgain_onSource() -  Reset the ColorTemp Rgain_onSource with another valid value | tvColorTemp_WARM, 999, AV_OFFSET, 0 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Rgain_onSource() -  Reset the ColorTemp Rgain_onSource with another valid value | tvColorTemp_STANDARD, 1200, HDMI_OFFSET, 1 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Rgain_onSource() -  Reset the ColorTemp Rgain_onSource with another valid value | tvColorTemp_COLD, 1500, TV_OFFSET, 1 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Rgain_onSource() -  Reset the ColorTemp Rgain_onSource with another valid value | tvColorTemp_WARM, 2046, AV_OFFSET, 1 | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemp_Rgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Rgain_onSource() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the ColorTemp Rgain_onSource value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 91@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetColorTemp_Rgain_onSource() - Set the TV ColorTemp Rgain_onSource even before tvInit() | tvColorTemp_STANDARD, 08, HDMI_OFFSET, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource with invalid input | tvColorTemp_MAX, 08, HDMI_OFFSET, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource with invalid input | tvColorTemp_WARM, -1, HDMI_OFFSET, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource with invalid input | tvColorTemp_WARM, 2048, HDMI_OFFSET, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource with invalid input | tvColorTemp_WARM, 08, 3, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource with invalid input | tvColorTemp_WARM, 08, TV_OFFSET, 2 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 09 | call SetColorTemp_Rgain_onSource() -  Set the TV ColorTemp Rgain_onSource with valid input after tvTerm() | tvColorTemp_WARM, 2046, AV_OFFSET, 1 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_Rgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Rgain_onSource() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the ColorTemp Rgain_onSource value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 92@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_Rgain_onSource() -  Retrieve the current ColorTemp Rgain_onSource with valid arguments | tvColorTemp_STANDARD, int *, HDMI_OFFSET | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Rgain_onSource() -  Retrieve the current ColorTemp Rgain_onSource with valid arguments and validate with above value | tvColorTemp_WARM, int *, TV_OFFSET | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_Rgain_onSource() -  Retrieve the current ColorTemp Rgain_onSource with valid arguments and validate with above value | tvColorTemp_COLD, int *, AV_OFFSET | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_Rgain_onSource() -  Retrieve the current ColorTemp Rgain_onSource with valid arguments and validate with above value | tvColorTemp_USER, int *, AV_OFFSET | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_Rgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Rgain_onSource() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the ColorTemp Rgain_onSource value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 93@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetColorTemp_Rgain_onSource() -  Retrieve current TV ColorTemp Rgain_onSource even before tvInit() | tvColorTemp_STANDARD, int *, HDMI_OFFSET  | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource with invalid input |  tvColorTemp_MAX, int *, HDMI_OFFSET | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource with invalid input | tvColorTemp_WARM, NULL, HDMI_OFFSET | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource with invalid input | tvColorTemp_COLD, int *, 3 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call GetColorTemp_Rgain_onSource() -  Retrieve current TV ColorTemp Rgain_onSource valid arguments | tvColorTemp_WARM, int *, TV_OFFSET  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetColorTemp_Rgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Ggain_onSource() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the ColorTemp Ggain_onSource value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 94@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value | tvColorTemp_STANDARD, 08, HDMI_OFFSET, 0| tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Ggain_onSource() -  Reset the ColorTemp Ggain_onSource with another valid value | tvColorTemp_COLD, 500, TV_OFFSET, 0 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Ggain_onSource() -  Reset the ColorTemp Ggain_onSource with another valid value | tvColorTemp_WARM, 999, AV_OFFSET, 0 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Ggain_onSource() -  Reset the ColorTemp Ggain_onSource with another valid value | tvColorTemp_STANDARD, 1200, HDMI_OFFSET, 1 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Ggain_onSource() -  Reset the ColorTemp Ggain_onSource with another valid value | tvColorTemp_COLD, 1500, TV_OFFSET, 1 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Ggain_onSource() -  Reset the ColorTemp Ggain_onSource with another valid value | tvColorTemp_WARM, 2046, AV_OFFSET, 1 | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemp_Ggain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Ggain_onSource() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the ColorTemp Ggain_onSource value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 95@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetColorTemp_Ggain_onSource() - Set the TV ColorTemp Ggain_onSource even before tvInit() | tvColorTemp_STANDARD, 08, HDMI_OFFSET, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource with invalid input | tvColorTemp_MAX, 08, HDMI_OFFSET, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource with invalid input | tvColorTemp_WARM, -1, HDMI_OFFSET, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource with invalid input | tvColorTemp_WARM, 2048, HDMI_OFFSET, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource with invalid input | tvColorTemp_WARM, 08, 3, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource with invalid input | tvColorTemp_WARM, 08, TV_OFFSET, 2 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 09 | call SetColorTemp_Ggain_onSource() -  Set the TV ColorTemp Ggain_onSource with valid input after tvTerm() | tvColorTemp_WARM, 2046, AV_OFFSET, 1 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_Ggain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Ggain_onSource() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the ColorTemp Ggain_onSource value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 96@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_Ggain_onSource() -  Retrieve the current ColorTemp Ggain_onSource with valid arguments | tvColorTemp_STANDARD, int *, HDMI_OFFSET | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Ggain_onSource() -  Retrieve the current ColorTemp Ggain_onSource with valid arguments and validate with above value | tvColorTemp_WARM, int *, TV_OFFSET | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_Ggain_onSource() -  Retrieve the current ColorTemp Ggain_onSource with valid arguments and validate with above value | tvColorTemp_COLD, int *, AV_OFFSET | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_Ggain_onSource() -  Retrieve the current ColorTemp G gain_onSource with valid arguments and validate with above value | tvColorTemp_USER, int *, AV_OFFSET | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_Ggain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Ggain_onSource() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the ColorTemp Ggain_onSource value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 97@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetColorTemp_Ggain_onSource() -  Retrieve current TV ColorTemp Ggain_onSource even before tvInit() | tvColorTemp_STANDARD, int *, HDMI_OFFSET  | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource with invalid input |  tvColorTemp_MAX, int *, HDMI_OFFSET | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource with invalid input | tvColorTemp_WARM, NULL, HDMI_OFFSET | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource with invalid input | tvColorTemp_COLD, int *, 3 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call GetColorTemp_Ggain_onSource() -  Retrieve current TV ColorTemp Ggain_onSource valid arguments | tvColorTemp_WARM, int *, TV_OFFSET  | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetColorTemp_Ggain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Bgain_onSource() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the ColorTemp Bgain_onSource value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 98@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value | tvColorTemp_STANDARD, 08, HDMI_OFFSET, 0| tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Bgain_onSource() -  Reset the ColorTemp Bgain_onSource with another valid value | tvColorTemp_COLD, 500, TV_OFFSET, 0 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Bgain_onSource() -  Reset the ColorTemp Bgain_onSource with another valid value | tvColorTemp_WARM, 999, AV_OFFSET, 0 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Bgain_onSource() -  Reset the ColorTemp Bgain_onSource with another valid value | tvColorTemp_STANDARD, 1200, HDMI_OFFSET, 1 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Bgain_onSource() -  Reset the ColorTemp Bgain_onSource with another valid value | tvColorTemp_COLD, 1500, TV_OFFSET, 1 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Bgain_onSource() -  Reset the ColorTemp Bgain_onSource with another valid value | tvColorTemp_WARM, 2046, AV_OFFSET, 1 | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemp_Bgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Bgain_onSource() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the ColorTemp Bgain_onSource value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 99@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetColorTemp_Bgain_onSource() - Set the TV ColorTemp Bgain_onSource even before tvInit() | tvColorTemp_STANDARD, 08, HDMI_OFFSET, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource with invalid input | tvColorTemp_MAX, 08, HDMI_OFFSET, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource with invalid input | tvColorTemp_WARM, -1, HDMI_OFFSET, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource with invalid input | tvColorTemp_WARM, 2048, HDMI_OFFSET, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource with invalid input | tvColorTemp_WARM, 08, 3, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource with invalid input | tvColorTemp_WARM, 08, TV_OFFSET, 2 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 09 | call SetColorTemp_Bgain_onSource() -  Set the TV ColorTemp Bgain_onSource with valid input after tvTerm() | tvColorTemp_WARM, 2046, AV_OFFSET, 1 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_Bgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Bgain_onSource() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the ColorTemp Bgain_onSource value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 100@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_Bgain_onSource() -  Retrieve the current ColorTemp Bgain_onSource with valid arguments | tvColorTemp_STANDARD, int *, HDMI_OFFSET | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Bgain_onSource() -  Retrieve the current ColorTemp Bgain_onSource with valid arguments and validate with above value | tvColorTemp_WARM, int *, TV_OFFSET | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_Bgain_onSource() -  Retrieve the current ColorTemp Bgain_onSource with valid arguments and validate with above value | tvColorTemp_COLD, int *, AV_OFFSET | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_Bgain_onSource() -  Retrieve the current ColorTemp Bgain_onSource with valid arguments and validate with above value | tvColorTemp_USER, int *, AV_OFFSET | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_Bgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Bgain_onSource() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the ColorTemp Bgain_onSource value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 101@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetColorTemp_Bgain_onSource() -  Retrieve current TV ColorTemp Bgain_onSource even before tvInit() | tvColorTemp_STANDARD, int *, HDMI_OFFSET  | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource with invalid input |  tvColorTemp_MAX, int *, HDMI_OFFSET | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource with invalid input | tvColorTemp_WARM, NULL, HDMI_OFFSET | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource with invalid input | tvColorTemp_COLD, int *, 3 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call GetColorTemp_Bgain_onSource() -  Retrieve current TV ColorTemp Bgain_onSource valid arguments | tvColorTemp_WARM, int *, TV_OFFSET  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetColorTemp_Bgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_R_post_offset_onSource() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the ColorTemp R_post_offset_onSource value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 102@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -   Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value | tvColorTemp_STANDARD, -1023, HDMI_OFFSET, 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_R_post_offset_onSource() -  Reset the ColorTemp R_post_offset_onSource with another valid value | tvColorTemp_COLD, -400, TV_OFFSET, 1 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_R_post_offset_onSource() -  Reset the ColorTemp R_post_offset_onSource with another valid value | tvColorTemp_WARM, 0, AV_OFFSET, 0 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_R_post_offset_onSource() -  Reset the ColorTemp R_post_offset_onSource with another valid value | tvColorTemp_USER, 100, HDMI_OFFSET, 1 | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_R_post_offset_onSource() -  Reset the ColorTemp R_post_offset_onSource with another valid value | tvColorTemp_STANDARD, 500, TV_OFFSET, 0 | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_R_post_offset_onSource() -  Reset the ColorTemp R_post_offset_onSource with another valid value | tvColorTemp_COLD, 700, AV_OFFSET, 1 | tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_R_post_offset_onSource() -  Reset the ColorTemp R_post_offset_onSource with another valid value | tvColorTemp_WARM, 1024, TV_OFFSET, 0 | tvERROR_NONE | Should Pass |
* | 09 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemp_R_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_R_post_offset_onSource() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the ColorTemp R_post_offset_onSource value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 103@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetColorTemp_R_post_offset_onSource() - Set the TV ColorTemp R_post_offset_onSource even before tvInit() | tvColorTemp_STANDARD, -1023, HDMI_OFFSET, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource with invalid input | tvColorTemp_MAX, -1025, HDMI_OFFSET, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource with invalid input | tvColorTemp_COLD, 0, TV_OFFSET, 5 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource with invalid input | tvColorTemp_STANDARD, 100, 5, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_R_post_offset_onSource() -  Set the TV ColorTemp R_post_offset_onSource with valid input after tvTerm() | tvColorTemp_WARM, 1024, HDMI_OFFSET, 1 | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SetColorTemp_R_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_R_post_offset_onSource() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the ColorTemp R_post_offset_onSource value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 104@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_R_post_offset_onSource() -  Retrieve the current ColorTemp R_post_offset_onSource with valid arguments | tvColorTemp_STANDARD, int *, HDMI_OFFSET| tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_R_post_offset_onSource() -  Retrieve the current ColorTemp R_post_offset_onSource with valid arguments and validate with above value | tvColorTemp_COLD, int *, HDMI_OFFSET | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_R_post_offset_onSource() -  Retrieve the current ColorTemp R_post_offset_onSource with valid arguments and validate with above value | tvColorTemp_WARM, int *, TV_OFFSET | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_R_post_offset_onSource() -  Retrieve the current ColorTemp R_post_offset_onSource with valid arguments and validate with above value | tvColorTemp_STANDARD, int *, TV_OFFSET | tvERROR_NONE | Should Pass |
* | 06 | call GetColorTemp_R_post_offset_onSource() -  Retrieve the current ColorTemp R_post_offset_onSource with valid arguments and validate with above value | tvColorTemp_COLD, int *, AV_OFFSET | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_R_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_R_post_offset_onSource() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the ColorTemp R_post_offset_onSource value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE

*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 105@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetColorTemp_R_post_offset_onSource() -  Retrieve current TV ColorTemp R_post_offset_onSource even before tvInit() | tvColorTemp_STANDARD, int *, HDMI_OFFSET | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_R_post_offset_onSource() -  Retrieve current TV ColorTemp R_post_offset_onSource with invalid input | tvColorTemp_STANDARD, NULL, HDMI_OFFSET | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_R_post_offset_onSource() -  Retrieve current TV ColorTemp R_post_offset_onSource with invalid input | tvColorTemp_MAX, int *, HDMI_OFFSET | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_R_post_offset_onSource() -  Retrieve current TV ColorTemp R_post_offset_onSource with invalid input | tvColorTemp_STANDARD, int *, 5 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call GetColorTemp_R_post_offset_onSource() -  Retrieve current TV ColorTemp R_post_offset_onSource valid arguments | tvColorTemp_COLD, int *, HDMI_OFFSET | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetColorTemp_R_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_G_post_offset_onSource() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the ColorTemp G_post_offset_onSource value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 106@n
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
* | 01 | call tvInit() -   Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value | tvColorTemp_STANDARD, -1023, HDMI_OFFSET, 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_G_post_offset_onSource() -  Reset the ColorTemp G_post_offset_onSource with another valid value | tvColorTemp_COLD, -400, TV_OFFSET, 1 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_G_post_offset_onSource() -  Reset the ColorTemp G_post_offset_onSource with another valid value | tvColorTemp_WARM, 0, AV_OFFSET, 0 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_G_post_offset_onSource() -  Reset the ColorTemp G_post_offset_onSource with another valid value | tvColorTemp_USER, 100, HDMI_OFFSET, 1 | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_G_post_offset_onSource() -  Reset the ColorTemp G_post_offset_onSource with another valid value | tvColorTemp_STANDARD, 500, TV_OFFSET, 0 | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_G_post_offset_onSource() -  Reset the ColorTemp G_post_offset_onSource with another valid value | tvColorTemp_COLD, 700, AV_OFFSET, 1 | tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_G_post_offset_onSource() -  Reset the ColorTemp G_post_offset_onSource with another valid value | tvColorTemp_WARM, 1024, TV_OFFSET, 0 | tvERROR_NONE | Should Pass |
* | 09 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemp_G_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_G_post_offset_onSource() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the ColorTemp G_post_offset_onSource value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 107@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetColorTemp_G_post_offset_onSource() - Set the TV ColorTemp G_post_offset_onSource even before tvInit() | tvColorTemp_STANDARD, -1023, HDMI_OFFSET, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource with invalid input | tvColorTemp_MAX, -1025, HDMI_OFFSET, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource with invalid input | tvColorTemp_COLD, 0, TV_OFFSET, 5 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource with invalid input | tvColorTemp_STANDARD, 100, 5, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_G_post_offset_onSource() -  Set the TV ColorTemp G_post_offset_onSource with valid input after tvTerm() | tvColorTemp_WARM, 1024, HDMI_OFFSET, 1 | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SetColorTemp_G_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_G_post_offset_onSource() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the ColorTemp G_post_offset_onSource value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 108@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_G_post_offset_onSource() -  Retrieve the current ColorTemp G_post_offset_onSource with valid arguments | tvColorTemp_STANDARD, int *, HDMI_OFFSET| tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_G_post_offset_onSource() -  Retrieve the current ColorTemp G_post_offset_onSource with valid arguments and validate with above value | tvColorTemp_COLD, int *, HDMI_OFFSET | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_G_post_offset_onSource() -  Retrieve the current ColorTemp G_post_offset_onSource with valid arguments and validate with above value | tvColorTemp_WARM, int *, TV_OFFSET | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_G_post_offset_onSource() -  Retrieve the current ColorTemp G_post_offset_onSource with valid arguments and validate with above value | tvColorTemp_STANDARD, int *, TV_OFFSET | tvERROR_NONE | Should Pass |
* | 06 | call GetColorTemp_G_post_offset_onSource() -  Retrieve the current ColorTemp G_post_offset_onSource with valid arguments and validate with above value | tvColorTemp_COLD, int *, AV_OFFSET | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_G_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_G_post_offset_onSource() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the ColorTemp G_post_offset_onSource value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE

*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 109@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetColorTemp_G_post_offset_onSource() -  Retrieve current TV ColorTemp G_post_offset_onSource even before tvInit() | tvColorTemp_STANDARD, int *, HDMI_OFFSET | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_G_post_offset_onSource() -  Retrieve current TV ColorTemp G_post_offset_onSource with invalid input | tvColorTemp_STANDARD, NULL, HDMI_OFFSET | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_G_post_offset_onSource() -  Retrieve current TV ColorTemp G_post_offset_onSource with invalid input | tvColorTemp_MAX, int *, HDMI_OFFSET | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_G_post_offset_onSource() -  Retrieve current TV ColorTemp G_post_offset_onSource with invalid input | tvColorTemp_STANDARD, int *, 5 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call GetColorTemp_G_post_offset_onSource() -  Retrieve current TV ColorTemp G_post_offset_onSource valid arguments | tvColorTemp_COLD, int *, HDMI_OFFSET | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetColorTemp_G_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_B_post_offset_onSource() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the ColorTemp B_post_offset_onSource value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 110@n
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
* | 01 | call tvInit() -   Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value | tvColorTemp_STANDARD, -1023, HDMI_OFFSET, 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_B_post_offset_onSource() -  Reset the ColorTemp B_post_offset_onSource with another valid value | tvColorTemp_COLD, -400, TV_OFFSET, 1 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_B_post_offset_onSource() -  Reset the ColorTemp B_post_offset_onSource with another valid value | tvColorTemp_WARM, 0, AV_OFFSET, 0 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_B_post_offset_onSource() -  Reset the ColorTemp B_post_offset_onSource with another valid value | tvColorTemp_USER, 100, HDMI_OFFSET, 1 | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_B_post_offset_onSource() -  Reset the ColorTemp B_post_offset_onSource with another valid value | tvColorTemp_STANDARD, 500, TV_OFFSET, 0 | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_B_post_offset_onSource() -  Reset the ColorTemp B_post_offset_onSource with another valid value | tvColorTemp_COLD, 700, AV_OFFSET, 1 | tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_B_post_offset_onSource() -  Reset the ColorTemp B_post_offset_onSource with another valid value | tvColorTemp_WARM, 1024, TV_OFFSET, 0 | tvERROR_NONE | Should Pass |
* | 09 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemp_B_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_B_post_offset_onSource() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the ColorTemp B_post_offset_onSource value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 111@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetColorTemp_B_post_offset_onSource() - Set the TV ColorTemp B_post_offset_onSource even before tvInit() | tvColorTemp_STANDARD, -1023, HDMI_OFFSET, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource with invalid input | tvColorTemp_MAX, -1025, HDMI_OFFSET, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource with invalid input | tvColorTemp_COLD, 0, TV_OFFSET, 5 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource with invalid input | tvColorTemp_STANDARD, 100, 5, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_B_post_offset_onSource() -  Set the TV ColorTemp B_post_offset_onSource with valid input after tvTerm() | tvColorTemp_WARM, 1024, HDMI_OFFSET, 1 | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SetColorTemp_B_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_B_post_offset_onSource() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the ColorTemp B_post_offset_onSource value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 112@n
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_B_post_offset_onSource() -  Retrieve the current ColorTemp B_post_offset_onSource with valid arguments | tvColorTemp_STANDARD, int *, HDMI_OFFSET| tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_B_post_offset_onSource() -  Retrieve the current ColorTemp B_post_offset_onSource with valid arguments and validate with above value | tvColorTemp_COLD, int *, HDMI_OFFSET | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_B_post_offset_onSource() -  Retrieve the current ColorTemp B_post_offset_onSource with valid arguments and validate with above value | tvColorTemp_WARM, int *, TV_OFFSET | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_B_post_offset_onSource() -  Retrieve the current ColorTemp B_post_offset_onSource with valid arguments and validate with above value | tvColorTemp_STANDARD, int *, TV_OFFSET | tvERROR_NONE | Should Pass |
* | 06 | call GetColorTemp_B_post_offset_onSource() -  Retrieve the current ColorTemp B_post_offset_onSource with valid arguments and validate with above value | tvColorTemp_COLD, int *, AV_OFFSET | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_B_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_B_post_offset_onSource() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the ColorTemp B_post_offset_onSource value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE

*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 113@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetColorTemp_B_post_offset_onSource() -  Retrieve current TV ColorTemp B_post_offset_onSource even before tvInit() | tvColorTemp_STANDARD, int *, HDMI_OFFSET | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_B_post_offset_onSource() -  Retrieve current TV ColorTemp B_post_offset_onSource with invalid input | tvColorTemp_STANDARD, NULL, HDMI_OFFSET | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_B_post_offset_onSource() -  Retrieve current TV ColorTemp B_post_offset_onSource with invalid input | tvColorTemp_MAX, int *, HDMI_OFFSET | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_B_post_offset_onSource() -  Retrieve current TV ColorTemp B_post_offset_onSource with invalid input | tvColorTemp_STANDARD, int *, 5 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call GetColorTemp_B_post_offset_onSource() -  Retrieve current TV ColorTemp B_post_offset_onSource valid arguments | tvColorTemp_COLD, int *, HDMI_OFFSET | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetColorTemp_B_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVSupportedPictureModes() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the TV Supported PictureModes value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 114@n
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetTVSupportedPictureModes() -  Retrieve the current TV Supported PictureModes with valid arguments | pic_modes_t *, unsigned short * | tvERROR_NONE | Should Pass |
* | 03 | call GetTVSupportedPictureModes() -  Retrieve the current TV Supported PictureModes with valid arguments and validate with above value |  pic_modes_t *, unsigned short * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetTVSupportedPictureModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVSupportedPictureModes() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the TV Supported PictureModes value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE

*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 115@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetTVSupportedPictureModes() -  Retrieve current TV Supported PictureModes even before tvInit() | pic_modes_t *, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetTVSupportedPictureModes() -   Retrieve current TV Supported PictureModes with invalid input | pic_modes_t *, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetTVSupportedPictureModes() -   Retrieve current TV Supported PictureModes with invalid input | NULL, unsigned short * | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetTVSupportedPictureModes() -   Retrieve current TV Supported PictureModes with invalid input | NULL, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call GetTVSupportedPictureModes() -  Retrieve current TV Supported PictureModes valid arguments | pic_modes_t *, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetTVSupportedPictureModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVSupportedDVModes() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the TV Supported DVModes value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 116@n
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetTVSupportedDVModes() -  Retrieve the current TV Supported DVModes with valid arguments | pic_modes_t *, unsigned short * | tvERROR_NONE | Should Pass |
* | 03 | call GetTVSupportedDVModes() -  Retrieve the current TV Supported DVModes with valid arguments and validate with above value |  pic_modes_t *, unsigned short * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetTVSupportedDVModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVSupportedDVModes() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the TV Supported DVModes value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE

*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 117@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetTVSupportedDVModes() -  Retrieve current TV Supported DVModes even before tvInit() | pic_modes_t *, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetTVSupportedDVModes() -   Retrieve current TV Supported DVModes with invalid input | pic_modes_t *, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetTVSupportedDVModes() -   Retrieve current TV Supported DVModes with invalid input | NULL, unsigned short * | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetTVSupportedDVModes() -   Retrieve current TV Supported DVModes with invalid input | NULL, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call GetTVSupportedDVModes() -  Retrieve current TV Supported DVModes valid arguments | pic_modes_t *, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetTVSupportedDVModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetTVDolbyVisionMode() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the TV DolbyVision Mode value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 118@n
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetTVDolbyVisionMode() -  Set the TV DolbyVision Mode with valid value | "bright" | tvERROR_NONE | Should Pass |
* | 03 | call SetTVDolbyVisionMode() -  Reset the  TV DolbyVision Mode with another valid value | "dark" | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
oid test_l1_tvSettings_positive_SetTVDolbyVisionMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetTVDolbyVisionMode() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the TV DolbyVision Mode value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 119@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetTVDolbyVisionMode() - Set the TV DolbyVision Mode even before tvInit() | "bright" | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetTVDolbyVisionMode() -   Set the TV DolbyVision Mode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetTVDolbyVisionMode() -   Set the TV DolbyVision Mode with invalid input | "invalid" | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call SetTVDolbyVisionMode() -  Set the TV DolbyVision Mode with valid input after tvTerm() | "dark" | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SetTVDolbyVisionMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVDolbyVisionMode() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the TV DolbyVision Mode value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 120@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetTVDolbyVisionMode() -  Retrieve the current DolbyVision Mode with valid arguments | char * | tvERROR_NONE | Should Pass |
* | 03 | call GetTVDolbyVisionMode() -  Retrieve the current DolbyVision Mode with valid arguments and validate with above value | char * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetTVDolbyVisionMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVDolbyVisionMode() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the TV DolbyVision Mode value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 121@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetTVDolbyVisionMode() -  Retrieve current TV DolbyVision Mode even before tvInit() | char * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetTVDolbyVisionMode() -   Retrieve current TV DolbyVision Mode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetTVDolbyVisionMode() -  Retrieve current TV DolbyVision Mode valid arguments | char * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetTVDolbyVisionMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetTVHLGMode() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the TV HLG Mode value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 122@n
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetTVHLGMode() -  Set the TV HLG Mode with valid value | "bright" | tvERROR_NONE | Should Pass |
* | 03 | call SetTVHLGMode() -  Reset the  TV HLG Mode with another valid value | "dark" | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SetTVHLGMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetTVHLGMode() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the TV HLG Mode value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 123@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetTVHLGMode() - Set the TV HLG Mode even before tvInit() | "bright" | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetTVHLGMode() -   Set the TV HLG Mode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetTVHLGMode() -   Set the TV HLG Mode with invalid input | "invalid" | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call SetTVHLGMode() -  Set the TV HLG Mode with valid input after tvTerm() | "dark" | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SetTVHLGMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetTVHDR10Mode() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the TV HDR10 Mode value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 124@n
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetTVHDR10Mode() -  Set the TV HDR10 Mode with valid value | "bright" | tvERROR_NONE | Should Pass |
* | 03 | call SetTVHDR10Mode() -  Reset the  TV HDR10 Mode with another valid value | "dark" | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SetTVHDR10Mode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetTVHDR10Mode() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the TV HDR10 Mode value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 125@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetTVHDR10Mode() - Set the TV HDR10 Mode even before tvInit() | "bright" | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetTVHDR10Mode() -   Set the TV HDR10 Mode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetTVHDR10Mode() -   Set the TV HDR10 Mode with invalid input | "invalid" | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call SetTVHDR10Mode() -  Set the TV HDR10 Mode with valid input after tvTerm() | "dark" | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SetTVHDR10Mode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVSupportedHLGModes() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the TV Supported HLG Modes value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 126@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetTVSupportedHLGModes() -  Retrieve the current TV Supported HLG Modes with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetTVSupportedHLGModes() -  Retrieve the current TV Supported HLG Modes with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetTVSupportedHLGModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVSupportedHLGModes() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE

*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 127@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetBrightness() -  Retrieve current TV brightness even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -   Retrieve current TV brightness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetBrightness() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetTVSupportedHLGModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVSupportedHDR10Modes() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the brightness value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 128@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetBrightness() -  Retrieve the current brightness with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -  Retrieve the current brightness with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetTVSupportedHDR10Modes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVSupportedHDR10Modes() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE

*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 129@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetBrightness() -  Retrieve current TV brightness even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -   Retrieve current TV brightness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetBrightness() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetTVSupportedHDR10Modes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetDynamicContrast() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the Dynamic Contrast value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 130@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* * **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetDynamicContrast() -  Set the Dynamic Contrast with valid value | "enabled" | tvERROR_NONE | Should Pass |
* | 03 | call SetDynamicContrast() -  Reset the Dynamic Contrast with another valid value | "disabled" | tvERROR_NONE | Should Pass |
* | 04 | call SetDynamicContrast() -  Reset the Dynamic Contrast with another valid value | "enabled" | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SetDynamicContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetDynamicContrast() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the Dynamic Contrast value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 131@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetDynamicContrast() - Set the TV Dynamic Contrast even before tvInit() | "enabled" | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetDynamicContrast() -  Set the TV Dynamic Contrast with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetDynamicContrast() -  Set the TV Dynamic Contrast with invalid input | "invalid" | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call SetDynamicContrast() -  Set the TV Dynamic Contrast with valid input after tvTerm() | "disabled" | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SetDynamicContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetDynamicContrast() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the Dynamic Contrast value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 132@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetDynamicContrast() -  Retrieve the current Dynamic Contrast with valid arguments | char * | tvERROR_NONE | Should Pass |
* | 03 | call GetDynamicContrast() -  Retrieve the current Dynamic Contrast with valid arguments and validate with above value | char * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetDynamicContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetDynamicContrast() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the Dynamic Contrast value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 133@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetDynamicContrast() -  Retrieve current TV Dynamic Contrast even before tvInit() | char * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetDynamicContrast() -   Retrieve current TV Dynamic Contrast with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetDynamicContrast() -  Retrieve current TV Dynamic Contrast valid arguments | char * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetDynamicContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate setWBctrl() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the WBctrl value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 134@n
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call setWBctrl() -  Set the WBctrl with valid value | "HDMI", "normal", "red", "gain", 10 | tvERROR_NONE | Should Pass |
* | 03 | call setWBctrl() -  Reset the WBctrl with valid value | "HDMI", "cool", "blue", "gain", 1024 | tvERROR_NONE | Should Pass |
* | 04 | call setWBctrl() -  Reset the WBctrl with valid value | "HDMI", "warm", "green", "gain", 2046 | tvERROR_NONE | Should Pass |
* | 05 | call setWBctrl() -  Reset the WBctrl with valid value | "TV", "normal", "red", "gain", 0 | tvERROR_NONE | Should Pass |
* | 06 | call setWBctrl() -  Reset the WBctrl with valid value | "TV", "cool", "blue", "gain", 1300 | tvERROR_NONE | Should Pass |
* | 07 | call setWBctrl() -  Reset the WBctrl with valid value | "AV", "warm", "green", "gain", 2010 | tvERROR_NONE | Should Pass |
* | 08 | call setWBctrl() -  Reset the WBctrl with valid value | "HDMI", "normal", "red", "offset", -1024 | tvERROR_NONE | Should Pass |
* | 09 | call setWBctrl() -  Reset the WBctrl with valid value | "HDMI", "normal", "blue", "offset", -500 | tvERROR_NONE | Should Pass |
* | 10 | call setWBctrl() -  Reset the WBctrl with valid value | "TV", "cool", "green", "offset", 0 | tvERROR_NONE | Should Pass |
* | 11 | call setWBctrl() -  Reset the WBctrl with another valid value | "TV", "cool", "red", "offset", 500 | tvERROR_NONE | Should Pass |
* | 12 | call setWBctrl() -  Reset the WBctrl with another valid value | "AV", "warm", "green", "offset", 1023 | tvERROR_NONE | Should Pass |
* | 13 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_setWBctrl (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate setWBctrl() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the WBctrl value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 135@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call setWBctrl() - Set the TV WBctrl even before tvInit() | "HDMI", "normal", "red", "gain", 10 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call setWBctrl() -  Set the TV WBctrl with invalid input | NULL, "normal", "red", "gain", 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call setWBctrl() -  Set the TV WBctrl with invalid input | "invalid", "normal", "red", "gain", 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call setWBctrl() -  Set the TV WBctrl with invalid input | "HDMI", NULL, "red", "gain", 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call setWBctrl() -  Set the TV WBctrl with invalid input | "HDMI", "invalid", "red", "gain", 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call setWBctrl() -  Set the TV WBctrl with invalid input | "HDMI", "normal", NULL, "gain", 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call setWBctrl() -  Set the TV WBctrl with invalid input | "HDMI", "normal", "invalid", "gain", 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call setWBctrl() -  Set the TV WBctrl with invalid input | "HDMI", "normal", "red", NULL, 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 10 | call setWBctrl() -  Set the TV WBctrl with invalid input | "HDMI", "normal", "red", "invalid", 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 11 | call setWBctrl() -  Set the TV WBctrl with valid input after tvTerm() | "HDMI", "normal", "red", "gain", -1 | tvERROR_INVALID_STATE | Should Pass |
* | 12 | call setWBctrl() -  Set the TV WBctrl with valid input after tvTerm() | "HDMI", "normal", "red", "gain", 2048 | tvERROR_INVALID_STATE | Should Pass |
* | 13 | call setWBctrl() -  Set the TV WBctrl with valid input after tvTerm() | "HDMI", "normal", "red", "offset", -1025 | tvERROR_INVALID_STATE | Should Pass |
* | 14 | call setWBctrl() -  Set the TV WBctrl with valid input after tvTerm() | "HDMI", "normal", "red", "offset", -1025 | tvERROR_INVALID_STATE | Should Pass |
* | 15 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 16 | call setWBctrl() -  Set the TV WBctrl with valid input after tvTerm() | "HDMI", tvColorTemp_STANDARD, "red", "gain", 1024 | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_setWBctrl (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate getWBctrl() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the WBctrl value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 136@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call getWBctrl() -  Retrieve the current WBctrl with valid arguments | "HDMI", "normal", "red", "gain", int * | tvERROR_NONE | Should Pass |
* | 03 | call getWBctrl() -  Retrieve the current WBctrl with valid arguments and validate with above value | "TV", "cool", "green", "gain", int * | tvERROR_NONE | Should Pass |
* | 04 | call getWBctrl() -  Retrieve the current WBctrl with valid arguments and validate with above value | "AV", "warm", "red", "offset", int * | tvERROR_NONE | Should Pass |
* | 05 | call getWBctrl() -  Retrieve the current WBctrl with valid arguments and validate with above value | "AV", "cool", "blue", "offset", int * | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_getWBctrl (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate getWBctrl() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the WBctrl value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 137@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call getWBctrl() -  Retrieve current TV WBctrl even before tvInit() | "HDMI", "normal", "red", "gain", int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call getWBctrl() -   Retrieve current TV WBctrl with invalid input | NULL, "normal", "red", "gain", int * | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call getWBctrl() -   Retrieve current TV WBctrl with invalid input | "HDMI", NULL, "red", "gain", int * | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call getWBctrl() -   Retrieve current TV WBctrl with invalid input | "HDMI", "normal", NULL, "gain", int * | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call getWBctrl() -   Retrieve current TV WBctrl with invalid input | "HDMI", "normal", "red", NULL, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call getWBctrl() -   Retrieve current TV WBctrl with invalid input | "HDMI", "normal", "red", "gain", NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call getWBctrl() -   Retrieve current TV WBctrl with invalid input | "invalid", "invalid", "invalid", "invalid", int * | tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 10 | call getWBctrl() -  Retrieve current TV WBctrl valid arguments | "HDMI", "normal", "red", "gain", int * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_getWBctrl (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate enableWBmode() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully enable the WBmode mode once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 138@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call enableWBmode() -  enable the WBmode with valid value | true | tvERROR_NONE | Should Pass |
* | 03 | call enableWBmode() -  Reenable the WBmode with another valid value | false | tvERROR_NONE | Should Pass |
* | 04 | call enableWBmode() -  Reenable the WBmode with another valid value | true | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_enableWBmode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate enableWBmode() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully enable the WBmode mode once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 139@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call enableWBmode() - enable the TV brightness even before tvInit() | true | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call enableWBmode() -  enable the TV brightness with valid input after tvTerm() | false | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_enableWBmode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/** Ga
* @brief Validate GetSupportedComponentColor() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the Supported ComponentColor value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 140@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetSupportedComponentColor() -  Retrieve the current Supported ComponentColor with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetSupportedComponentColor() -  Retrieve the current Supported ComponentColor with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetSupportedComponentColor (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetSupportedComponentColor() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the Supported ComponentColor value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 141@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetSupportedComponentColor() -  Retrieve current TV Supported ComponentColor even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetSupportedComponentColor() -   Retrieve current TV Supported ComponentColor with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetSupportedComponentColor() -  Retrieve current TV Supported ComponentColor valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetSupportedComponentColor (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetCurrentComponentSaturation() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the Current Component Saturation value once module is initialized
* 3. Close the module using tvTerm()
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 142@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetCurrentComponentSaturation() -  Set the Current Component Saturation with valid value | tvDataColor_RED,  08| tvERROR_NONE | Should Pass |
* | 03 | call SetCurrentComponentSaturation() -  Reset the Current Component Saturation with another valid value | tvDataColor_GREEN,  20 | tvERROR_NONE | Should Pass |
* | 04 | call SetCurrentComponentSaturation() -  Reset the Current Component Saturation with another valid value | tvDataColor_BLUE,  42 | tvERROR_NONE | Should Pass |
* | 05 | call SetCurrentComponentSaturation() -  Reset the Current Component Saturation with another valid value | tvDataColor_YELLOW,  74 | tvERROR_NONE | Should Pass |
* | 06 | call SetCurrentComponentSaturation() -  Reset the Current Component Saturation with another valid value | tvDataColor_CYAN,  96 | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SetCurrentComponentSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetCurrentComponentSaturation() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the Current Component Saturation value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 143@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetCurrentComponentSaturation() - Set the TV Current Component Saturation even before tvInit() | tvDataColor_CYAN,  96 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetCurrentComponentSaturation() -   Set the TV Current Component Saturation with invalid input | tvDataColor_GREEN,  105 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetCurrentComponentSaturation() -   Set the TV Current Component Saturation with invalid input | tvDataColor_GREEN,  -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetCurrentComponentSaturation() -   Set the TV Current Component Saturation with invalid input | tvDataColor_MAX, 20 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call SetCurrentComponentSaturation() -  Set the TV Current Component Saturation with valid input after tvTerm() | tvDataColor_GREEN,  20 | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SetCurrentComponentSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentComponentSaturation() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the Current Component Saturation value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 144@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetBrightness() -  Retrieve the current Component Saturation with valid arguments | tvDataColor_GREEN, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -  Retrieve the current Component Saturation with valid arguments and validate with above value |tvDataColor_GREEN, int * | tvERROR_NONE | Should Pass |
* | 04 | call GetBrightness() -  Retrieve the current Component Saturation with valid arguments and validate with above value |tvDataColor_RED, int * | tvERROR_NONE | Should Pass |
* | 05 | call GetBrightness() -  Retrieve the current Component Saturation with valid arguments and validate with above value |tvDataColor_CYAN, int * | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetCurrentComponentSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentComponentSaturation() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the Current Component Saturation value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 144@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetCurrentComponentSaturation() -  Retrieve current TV Component Saturation even before tvInit() | tvDataColor_CYAN, int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetCurrentComponentSaturation() -   Retrieve current TV Component Saturation with invalid input | tvDataColor_CYAN, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetCurrentComponentSaturation() -   Retrieve current TV Component Saturation with invalid input | tvDataColor_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call GetCurrentComponentSaturation() -  Retrieve current TV Component Saturation valid arguments | tvDataColor_RED, int * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetCurrentComponentSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetCurrentComponentHue() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the brightness value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 145@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetBrightness() -  Retrieve the current brightness with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -  Retrieve the current brightness with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SetCurrentComponentHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetCurrentComponentHue() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE

*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 146@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetBrightness() -  Retrieve current TV brightness even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -   Retrieve current TV brightness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetBrightness() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SetCurrentComponentHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentComponentHue() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the brightness value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 147@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetBrightness() -  Retrieve the current brightness with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -  Retrieve the current brightness with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetCurrentComponentHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentComponentHue() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 148@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetBrightness() -  Retrieve current TV brightness even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -   Retrieve current TV brightness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetBrightness() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetCurrentComponentHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetCurrentComponentLuma() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the brightness value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 149@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetBrightness() -  Retrieve the current brightness with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -  Retrieve the current brightness with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SetCurrentComponentLuma (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetCurrentComponentLuma() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 150@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetBrightness() -  Retrieve current TV brightness even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -   Retrieve current TV brightness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetBrightness() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SetCurrentComponentLuma (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentComponentLuma() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the brightness value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 151@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetBrightness() -  Retrieve the current brightness with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -  Retrieve the current brightness with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetCurrentComponentLuma (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentComponentLuma() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 152@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetBrightness() -  Retrieve current TV brightness even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -   Retrieve current TV brightness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetBrightness() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetCurrentComponentLuma (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVSupportedDimmingModes() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the TV Supported DimmingModes once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 153@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetTVSupportedDimmingModes() -  Retrieve the current TV Supported DimmingModes with valid arguments | char **, unsigned short * | tvERROR_NONE | Should Pass |
* | 03 | call GetTVSupportedDimmingModes() -  Retrieve the current TV Supported DimmingModes with valid arguments and validate with above value | char **, unsigned short * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetTVSupportedDimmingModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVSupportedDimmingModes() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the TV Supported DimmingModes value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 154@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetTVSupportedDimmingModes() -  Retrieve current TV Supported DimmingModes even before tvInit() | char **, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetTVSupportedDimmingModes() -   Retrieve current TV Supported DimmingModes with invalid input | char **,  NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call GetTVSupportedDimmingModes() -   Retrieve current TV Supported DimmingModes with invalid input | NULL,  unsigned short * | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetTVSupportedDimmingModes() -  Retrieve current TV Supported DimmingModes valid arguments | char **, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetTVSupportedDimmingModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetTVDimmingMode() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the TV Dimming Mode value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 155@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetTVDimmingMode() -  Retrieve the current TV Dimming Mode with valid arguments | "local" | tvERROR_NONE | Should Pass |
* | 03 | call SetTVDimmingMode() -  Retrieve the current TV Dimming Mode with valid arguments and validate with above value | "fixed" | tvERROR_NONE | Should Pass |
* | 04 | call SetTVDimmingMode() -  Retrieve the current TV Dimming Mode with valid arguments and validate with above value | "global" | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SetTVDimmingMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetTVDimmingMode() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the TV Dimming Mode value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 156@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetTVDimmingMode() -  Retrieve current TV brightness even before tvInit() | "local" | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetTVDimmingMode() -   Retrieve current TV brightness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetTVDimmingMode() -   Retrieve current TV brightness with invalid input | "invalid" | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SetTVDimmingMode() -  Retrieve current TV brightness valid arguments | "global" | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SetTVDimmingMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetTVBacklightGlobalFactor() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the TV Backlight GlobalFactor value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 158@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetTVBacklightGlobalFactor() -  Retrieve the current TV Backlight GlobalFactor with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call SetTVBacklightGlobalFactor() -  Retrieve the current TV Backlight GlobalFactor with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SetTVBacklightGlobalFactor (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetTVBacklightGlobalFactor() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 159@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetBrightness() -  Retrieve current TV brightness even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -   Retrieve current TV brightness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetBrightness() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SetTVBacklightGlobalFactor (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**Ga
* @brief Validate GetTVBacklightGlobalFactor() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the TVBacklight GlobalFactor value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 160@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetTVBacklightGlobalFactor() -  Retrieve the current TVBacklight GlobalFactor with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetTVBacklightGlobalFactor() -  Retrieve the current TVBacklight GlobalFactor with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetTVBacklightGlobalFactor (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVBacklightGlobalFactor() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the TVBacklight GlobalFactor value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 161@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetTVBacklightGlobalFactor() -  Retrieve current TV TVBacklight GlobalFactor even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetTVBacklightGlobalFactor() -   Retrieve current TV TVBacklight GlobalFactor with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetTVBacklightGlobalFactor() -  Retrieve current TV TVBacklight GlobalFactor valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetTVBacklightGlobalFactor (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/** verify kpr needed or not
* @brief Validate GetTVPictureModeIndex() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the TVPicture ModeIndex value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 162@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetTVPictureModeIndex() -  Retrieve the current TVPicture ModeIndex with valid arguments | const char * | tvERROR_NONE | Should Pass |
* | 03 | call GetTVPictureModeIndex() -  Retrieve the current TVPicture ModeIndex with valid arguments and validate with above value | const char * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetTVPictureModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVPictureModeIndex() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the TVPictureModeIndex value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 163@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetTVPictureModeIndex() -  Retrieve current TV TVPictureModeIndex even before tvInit() | const char * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetTVPictureModeIndex() -   Retrieve current TV TVPictureModeIndex with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetTVPictureModeIndex() -  Retrieve current TV TVPictureModeIndex valid arguments | const char * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetTVPictureModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentContentFormat() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the Current ContentFormat value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 164@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetCurrentContentFormat() -  Retrieve the current Current ContentFormat with valid arguments | void | tvERROR_NONE  | Should Pass |
* | 03 | call GetCurrentContentFormat() -  Retrieve the current Current ContentFormat with valid arguments and validate with above value | void | tvERROR_NONE  | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetCurrentContentFormat (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentContentFormat() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the Current ContentFormat value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 165@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetCurrentContentFormat() -  Retrieve current TV ContentFormat even before tvInit() | void | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetCurrentContentFormat() -  Retrieve current TV ContentFormat valid arguments | void | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetCurrentContentFormat (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetSupportedContentFormats() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the Supported ContentFormats value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 166@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetSupportedContentFormats() -  Retrieve the current Supported ContentFormats with valid arguments | unsigned int *, unsigned short * | tvERROR_NONE | Should Pass |
* | 03 | call GetSupportedContentFormats() -  Retrieve the current Supported ContentFormats with valid arguments and validate with above value | unsigned int *, unsigned short * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetSupportedContentFormats (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetSupportedContentFormats() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the Supported ContentFormats value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 167@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetSupportedContentFormats() -  Retrieve current TV Supported ContentFormats even before tvInit() | unsigned int *, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetSupportedContentFormats() -   Retrieve current TV Supported ContentFormats with invalid input | unsigned int *, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetSupportedContentFormats() -   Retrieve current TV Supported ContentFormats with invalid input | NULL, unsigned short * | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call GetSupportedContentFormats() -  Retrieve current TV Supported ContentFormats valid arguments | unsigned int *, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetSupportedContentFormats (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate isCurrentHDRTypeIsSDR() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully find the Current HDR Type is SDR or not ,once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 168@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call isCurrentHDRTypeIsSDR() -  Retrieve the current brightness with valid arguments | void | true | Should Pass |
* | 03 | call isCurrentHDRTypeIsSDR() -  Retrieve the current brightness with valid arguments and validate with above value | void | true | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_isCurrentHDRTypeIsSDR (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate isCurrentHDRTypeIsSDR() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the  find the Current HDR Type is SDR or not, once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 169@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call isCurrentHDRTypeIsSDR() -  Retrieve current TV brightness even before tvInit() | void | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call isCurrentHDRTypeIsSDR() -  Retrieve current TV brightness valid arguments | void | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_isCurrentHDRTypeIsSDR (void)
{
	UT_FAIL(This function needs to be implemented!); 
}


/*
* @brief Validate GetPanelID() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the Panel ID value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 170@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetPanelID() -  Retrieve the current Panel ID with valid arguments | char* | tvERROR_NONE | Should Pass |
* | 03 | call GetPanelID() -  Retrieve the current Panel ID with valid arguments and validate with above value | char* | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetPanelID (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetPanelID() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the PanelID value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 171@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetPanelID() -  Retrieve current TV PanelID even before tvInit() | char* | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetPanelID() -   Retrieve current TV PanelID with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetPanelID() -  Retrieve current TV PanelID valid arguments | char* | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetPanelID (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/*
* @brief Validate GetDefaultPanelID() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the Default PanelID value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 172@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetDefaultPanelID() -  Retrieve the current Default PanelID with valid arguments | char * | tvERROR_NONE | Should Pass |
* | 03 | call GetDefaultPanelID() -  Retrieve the current Default PanelID with valid arguments and validate with above value | char * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetDefaultPanelID (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetDefaultPanelID() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the Default PanelID value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 173@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetDefaultPanelID() -  Retrieve current TV Default PanelID even before tvInit() | char * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetDefaultPanelID() -   Retrieve current TV Default PanelID with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetDefaultPanelID() -  Retrieve current TV Default PanelID valid arguments | char * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetDefaultPanelID (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveColorTemperature() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully save the Color Temperature value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 174@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SaveColorTemperature() -  Save the current Color Temperature with valid arguments | HDMI, 0, HDR_TYPE_HLG, tvColorTemp_WARM | tvERROR_NONE | Should Pass |
* | 03 | call SaveColorTemperature() -  Save the current Color Temperature with valid arguments and validate with above value | TV, 1, HDR_TYPE_HDR10, tvColorTemp_COLD | tvERROR_NONE | Should Pass |
* | 04 | call SaveColorTemperature() -  Save the current Color Temperature with valid arguments and validate with above value | AV, 2, HDR_TYPE_DOVI, tvColorTemp_USER | tvERROR_NONE | Should Pass |
* | 05 | call SaveColorTemperature() -  Save the current Color Temperature with valid arguments and validate with above value | TV, 3, HDR_TYPE_SDR, tvColorTemp_STANDARD | tvERROR_NONE | Should Pass |
* | 06 | call SaveColorTemperature() -  Save the current Color Temperature with valid arguments and validate with above value | TV, 4, HDR_TYPE_HDR10, tvColorTemp_STANDARD | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SaveColorTemperature (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveColorTemperature() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully save the Color Temperature value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 175@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SaveColorTemperature() -  Save the current Color Temperature even before tvInit() | HDMI, 0, HDR_TYPE_HLG, tvColorTemp_WARM | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveColorTemperature() -   Save the current Color Temperature with invalid input | HDMI, 0, HDR_TYPE_HDR10, tvColorTemp_MAX | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SaveColorTemperature() -   Save the current Color Temperature with invalid input | HDMI, 0, HDR_TYPE_SDR, tvColorTemp_MAX | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SaveColorTemperature() -   Save the current Color Temperature with invalid input | HDMI, 10, HDR_TYPE_MAX, tvColorTemp_WARM | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SaveColorTemperature() -  Save the current Color Temperature valid arguments | HDMI, 0, HDR_TYPE_HLG, tvColorTemp_WARM | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SaveColorTemperature (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveBacklight() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully Save the Backlight value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 176@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SaveBacklight() -  Save the Backlight with valid arguments | HDMI, 0, HDR_TYPE_HLG, 08 | tvERROR_NONE | Should Pass |
* | 03 | call SaveBacklight() -  Save the Backlight with valid arguments | HDMI, 1, HDR_TYPE_SDR, 25 | tvERROR_NONE | Should Pass |
* | 04 | call SaveBacklight() -  Save the Backlight with valid arguments | HDMI, 2, HDR_TYPE_HDR10, 55 | tvERROR_NONE | Should Pass |
* | 05 | call SaveBacklight() -  Save the Backlight with valid arguments | HDMI, 3, HDR_TYPE_DOVI, 78 | tvERROR_NONE | Should Pass |
* | 06 | call SaveBacklight() -  Save the Backlight with valid arguments | HDMI, 4, HDR_TYPE_HLG, 95 | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SaveBacklight (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveBacklight() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully Save the Backlight value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 177@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SaveBacklight() -  Retrieve current TV brightness even before tvInit() | HDMI, 0, HDR_TYPE_HLG, 08 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveBacklight() -   Retrieve current TV brightness with invalid input | HDMI, 0, HDR_TYPE_MAX, 08 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveBacklight() -   Retrieve current TV brightness with invalid input | HDMI, 0, HDR_TYPE_HLG, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveBacklight() -   Retrieve current TV brightness with invalid input | HDMI, 0, HDR_TYPE_HLG, 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveBacklight() -   Retrieve current TV brightness with invalid input | HDMI, 11, HDR_TYPE_HLG, 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SaveBacklight() -  Retrieve current TV brightness valid arguments | HDMI, 3, HDR_TYPE_DOVI, 78 | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SaveBacklight (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveContrast() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully Save the Contrast value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 178@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SaveContrast() -  Save the Contrast with valid arguments | HDMI, 0, HDR_TYPE_HLG, 08 | tvERROR_NONE | Should Pass |
* | 03 | call SaveContrast() -  Save the Contrast with valid arguments | HDMI, 1, HDR_TYPE_SDR, 25 | tvERROR_NONE | Should Pass |
* | 04 | call SaveContrast() -  Save the Contrast with valid arguments | HDMI, 2, HDR_TYPE_HDR10, 55 | tvERROR_NONE | Should Pass |
* | 05 | call SaveContrast() -  Save the Contrast with valid arguments | HDMI, 3, HDR_TYPE_DOVI, 78 | tvERROR_NONE | Should Pass |
* | 06 | call SaveContrast() -  Save the Contrast with valid arguments | HDMI, 4, HDR_TYPE_HLG, 95 | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SaveContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveContrast() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully Save the Contrast value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 179@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SaveContrast() -  save current TV Contrast even before tvInit() | HDMI, 0, HDR_TYPE_HLG, 08 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveContrast() -  save current TV Contrast with invalid input | HDMI, 0, HDR_TYPE_MAX, 08 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveContrast() -  save current TV Contrast with invalid input | HDMI, 0, HDR_TYPE_HLG, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveContrast() -  save current TV Contrast with invalid input | HDMI, 0, HDR_TYPE_HLG, 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveContrast() -  save current TV Contrast with invalid input | HDMI, 11, HDR_TYPE_HLG, 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SaveContrast() -  save current TV Contrast valid arguments | HDMI, 3, HDR_TYPE_DOVI, 78 | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SaveContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveSaturation() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully Save the Saturation value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 180@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SaveSaturation() -  Save the Saturation with valid arguments | HDMI, 0, HDR_TYPE_HLG, 08 | tvERROR_NONE | Should Pass |
* | 03 | call SaveSaturation() -  Save the Saturation with valid arguments | HDMI, 1, HDR_TYPE_SDR, 25 | tvERROR_NONE | Should Pass |
* | 04 | call SaveSaturation() -  Save the Saturation with valid arguments | HDMI, 2, HDR_TYPE_HDR10, 55 | tvERROR_NONE | Should Pass |
* | 05 | call SaveSaturation() -  Save the Saturation with valid arguments | HDMI, 3, HDR_TYPE_DOVI, 78 | tvERROR_NONE | Should Pass |
* | 06 | call SaveSaturation() -  Save the Saturation with valid arguments | HDMI, 4, HDR_TYPE_HLG, 95 | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SaveSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveSaturation() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully Save the Saturation value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 181@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SaveSaturation() -  save current TV Saturation even before tvInit() | HDMI, 0, HDR_TYPE_HLG, 08 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveSaturation() -  save current TV Saturation with invalid input | HDMI, 0, HDR_TYPE_MAX, 08 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveSaturation() -  save current TV Saturation with invalid input | HDMI, 0, HDR_TYPE_HLG, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveSaturation() -  save current TV Saturation with invalid input | HDMI, 0, HDR_TYPE_HLG, 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveSaturation() -  save current TV Saturation with invalid input | HDMI, 11, HDR_TYPE_HLG, 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SaveSaturation() -  save current TV Saturation valid arguments | HDMI, 3, HDR_TYPE_DOVI, 78 | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SaveSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveSharpness() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully Save the Sharpness value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 182@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SaveSharpness() -  Save the Sharpness with valid arguments | HDMI, 0, HDR_TYPE_HLG, 08 | tvERROR_NONE | Should Pass |
* | 03 | call SaveSharpness() -  Save the Sharpness with valid arguments | HDMI, 1, HDR_TYPE_SDR, 25 | tvERROR_NONE | Should Pass |
* | 04 | call SaveSharpness() -  Save the Sharpness with valid arguments | HDMI, 2, HDR_TYPE_HDR10, 55 | tvERROR_NONE | Should Pass |
* | 05 | call SaveSharpness() -  Save the Sharpness with valid arguments | HDMI, 3, HDR_TYPE_DOVI, 78 | tvERROR_NONE | Should Pass |
* | 06 | call SaveSharpness() -  Save the Sharpness with valid arguments | HDMI, 4, HDR_TYPE_HLG, 95 | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SaveSharpness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveSharpness() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully save current TV Sharpness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 183@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SaveSharpness() -  save current TV Sharpness even before tvInit() | HDMI, 0, HDR_TYPE_HLG, 08 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveSharpness() -  save current TV Sharpness with invalid input | HDMI, 0, HDR_TYPE_MAX, 08 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveSharpness() -  save current TV Sharpness with invalid input | HDMI, 0, HDR_TYPE_HLG, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveSharpness() -  save current TV Sharpness with invalid input | HDMI, 0, HDR_TYPE_HLG, 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveSharpness() -  save current TV Sharpness with invalid input | HDMI, 11, HDR_TYPE_HLG, 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SaveSharpness() -  save current TV Sharpness valid arguments | HDMI, 3, HDR_TYPE_DOVI, 78 | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SaveSharpness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveBrightness() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully save the brightness value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 184@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SaveBrightness() -  Save the Brightness with valid arguments | HDMI, 0, HDR_TYPE_HLG, 08 | tvERROR_NONE | Should Pass |
* | 03 | call SaveBrightness() -  Save the Brightness with valid arguments | HDMI, 1, HDR_TYPE_SDR, 25 | tvERROR_NONE | Should Pass |
* | 04 | call SaveBrightness() -  Save the Brightness with valid arguments | HDMI, 2, HDR_TYPE_HDR10, 55 | tvERROR_NONE | Should Pass |
* | 05 | call SaveBrightness() -  Save the Brightness with valid arguments | HDMI, 3, HDR_TYPE_DOVI, 78 | tvERROR_NONE | Should Pass |
* | 06 | call SaveBrightness() -  Save the Brightness with valid arguments | HDMI, 4, HDR_TYPE_HLG, 95 | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SaveBrightness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveBrightness() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully save the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 185@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SaveBrightness() -  save current TV Brightness even before tvInit() | HDMI, 0, HDR_TYPE_HLG, 08 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveBrightness() -  save current TV Brightness with invalid input | HDMI, 0, HDR_TYPE_MAX, 08 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveBrightness() -  save current TV Brightness with invalid input | HDMI, 0, HDR_TYPE_HLG, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveBrightness() -  save current TV Brightness with invalid input | HDMI, 0, HDR_TYPE_HLG, 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveBrightness() -  save current TV Brightness with invalid input | HDMI, 11, HDR_TYPE_HLG, 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SaveBrightness() -  save current TV Brightness valid arguments | HDMI, 3, HDR_TYPE_DOVI, 78 | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SaveBrightness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveHue() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully save the Hue value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 186@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SaveHue() -  Save the Hue with valid arguments | HDMI, 0, HDR_TYPE_HLG, 08 | tvERROR_NONE | Should Pass |
* | 03 | call SaveHue() -  Save the Hue with valid arguments | HDMI, 1, HDR_TYPE_SDR, 25 | tvERROR_NONE | Should Pass |
* | 04 | call SaveHue() -  Save the Hue with valid arguments | HDMI, 2, HDR_TYPE_HDR10, 55 | tvERROR_NONE | Should Pass |
* | 05 | call SaveHue() -  Save the Hue with valid arguments | HDMI, 3, HDR_TYPE_DOVI, 78 | tvERROR_NONE | Should Pass |
* | 06 | call SaveHue() -  Save the Hue with valid arguments | HDMI, 4, HDR_TYPE_HLG, 95 | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SaveHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveHue() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully save the Hue value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 187@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SaveHue() -  save current TV Hue even before tvInit() | HDMI, 0, HDR_TYPE_HLG, 08 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveHue() -  save current TV Hue with invalid input | HDMI, 0, HDR_TYPE_MAX, 08 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveHue() -  save current TV Hue with invalid input | HDMI, 0, HDR_TYPE_HLG, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveHue() -  save current TV Hue with invalid input | HDMI, 0, HDR_TYPE_HLG, 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveHue() -  save current TV Hue with invalid input | HDMI, 11, HDR_TYPE_HLG, 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SaveHue() -  save current TV Hue valid arguments | HDMI, 3, HDR_TYPE_DOVI, 78 | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SaveHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveDynamicBacklight() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully Save the DynamicBacklight value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 188@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SaveDynamicBacklight() -  Save the DynamicBacklight with valid arguments | HDMI, 0, HDR_TYPE_HLG, tvDimmingMode_Fixed | tvERROR_NONE | Should Pass |
* | 03 | call SaveDynamicBacklight() -  Save the DynamicBacklight with valid arguments | HDMI, 1, HDR_TYPE_SDR, tvDimmingMode_Fixed | tvERROR_NONE | Should Pass |
* | 04 | call SaveDynamicBacklight() -  Save the DynamicBacklight with valid arguments | HDMI, 2, HDR_TYPE_HDR10, tvDimmingMode_Local | tvERROR_NONE | Should Pass |
* | 05 | call SaveDynamicBacklight() -  Save the DynamicBacklight with valid arguments | HDMI, 3, HDR_TYPE_DOVI, tvDimmingMode_Global | tvERROR_NONE | Should Pass |
* | 06 | call SaveDynamicBacklight() -  Save the DynamicBacklight with valid arguments | HDMI, 4, HDR_TYPE_HLG, tvDimmingMode_Global | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SaveDynamicBacklight (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveDynamicBacklight() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully save the DynamicBacklight value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 189@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SaveDynamicBacklight() -  save the DynamicBacklight even before tvInit() | HDMI, 0, HDR_TYPE_HLG, tvDimmingMode_Fixed | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveDynamicBacklight() -  save the DynamicBacklight with invalid input | HDMI, 0, HDR_TYPE_MAX, tvDimmingMode_Fixed | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveDynamicBacklight() -  save the DynamicBacklight with invalid input | HDMI, 0, HDR_TYPE_HLG, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveDynamicBacklight() -  save the DynamicBacklight with invalid input | HDMI, 0, HDR_TYPE_HLG, 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveDynamicBacklight() -  save the DynamicBacklight with invalid input | HDMI, 11, HDR_TYPE_HLG, 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SaveDynamicBacklight() -  save the DynamicBacklight valid arguments | HDMI, 3, HDR_TYPE_DOVI, tvDimmingMode_Fixed | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SaveDynamicBacklight (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveDisplayMode() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully Save the DisplayMode value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 190@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SaveDisplayMode() -  Save the DisplayMode with valid arguments | HDMI, 0, HDR_TYPE_HLG, tvDisplayMode_4x3  | tvERROR_NONE | Should Pass |
* | 03 | call SaveDisplayMode() -  Save the DisplayMode with valid arguments | HDMI, 1, HDR_TYPE_SDR, tvDisplayMode_16x9  | tvERROR_NONE | Should Pass |
* | 04 | call SaveDisplayMode() -  Save the DisplayMode with valid arguments | HDMI, 2, HDR_TYPE_HDR10, tvDisplayMode_FULL | tvERROR_NONE | Should Pass |
* | 05 | call SaveDisplayMode() -  Save the DisplayMode with valid arguments | HDMI, 3, HDR_TYPE_DOVI, tvDisplayMode_NORMAL | tvERROR_NONE | Should Pass |
* | 06 | call SaveDisplayMode() -  Save the DisplayMode with valid arguments | HDMI, 4, HDR_TYPE_HLG, tvDisplayMode_ZOOM | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SaveDisplayMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveDisplayMode() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully Save the DisplayMode value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 191@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SaveDisplayMode() -  save the DisplayMode even before tvInit() | HDMI, 0, HDR_TYPE_HLG, tvDisplayMode_4x3 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveDisplayMode() -  save the DisplayMode with invalid input | HDMI, 0, HDR_TYPE_MAX, tvDisplayMode_4x3 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveDisplayMode() -  save the DisplayMode with invalid input | HDMI, 0, HDR_TYPE_HLG, tvDisplayMode_MAX | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveDisplayMode() -  save the DisplayMode with invalid input | "Invalid", 0, HDR_TYPE_HLG, 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveDisplayMode() -  save the DisplayMode with invalid input | HDMI, 11, HDR_TYPE_HLG, tvDisplayMode_4x3 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SaveDisplayMode() -  save the DisplayMode valid arguments | HDMI, 3, HDR_TYPE_DOVI, tvDisplayMode_4x3 | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SaveDisplayMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveCMS() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully Save the CMS value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 192@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SaveCMS() -  Save the CMS with valid arguments | HDMI, 0, HDR_TYPE_HLG, COLOR_HUE, COLOR_RED, 08  | tvERROR_NONE | Should Pass |
* | 03 | call SaveCMS() -  Save the CMS with valid arguments | HDMI, 1, HDR_TYPE_SDR, COLOR_SATURATION, COLOR_GREEN, 23  | tvERROR_NONE | Should Pass |
* | 04 | call SaveCMS() -  Save the CMS with valid arguments | HDMI, 2, HDR_TYPE_HDR10, COLOR_LUMA, COLOR_BLUE, 56| tvERROR_NONE | Should Pass |
* | 05 | call SaveCMS() -  Save the CMS with valid arguments | HDMI, 3, HDR_TYPE_DOVI, COLOR_STATE, COLOR_CYAN, 78 | tvERROR_NONE | Should Pass |
* | 06 | call SaveCMS() -  Save the CMS with valid arguments | HDMI, 4, HDR_TYPE_HLG, COLOR_HUE, COLOR_MAGENTA, 92 | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SaveCMS (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveCMS() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully save the CMS value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 193@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SaveCMS() -  save the CMS even before tvInit() | HDMI, 0, HDR_TYPE_HLG, COLOR_HUE, COLOR_RED, 08 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit()  -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveCMS() -  save the CMS with invalid input | HDMI, 0, HDR_TYPE_HLG, COLOR_HUE, COLOR_RED, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveCMS() -  save the CMS with invalid input | HDMI, 0, HDR_TYPE_HLG, COLOR_HUE, COLOR_RED, 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveCMS() -  save the CMS with invalid input | HDMI, 0, HDR_TYPE_HLG, COLOR_HUE, -1, 08 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveCMS() -  save the CMS with invalid input | HDMI, 0, HDR_TYPE_HLG, -1, COLOR_RED, 08 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SaveCMS() -  save the CMS with invalid input | HDMI, 0, HDR_TYPE_MAX, COLOR_HUE, COLOR_RED, 08 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SaveCMS() -  save the CMS with invalid input | HDMI, -1, HDR_TYPE_HLG, COLOR_HUE, COLOR_RED, 08 | tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call tvTerm()  -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 10 | call SaveCMS() -  save the CMS valid arguments | HDMI, 4, HDR_TYPE_HLG, COLOR_HUE, COLOR_MAGENTA, 92 | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SaveCMS (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveDolbyMode() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully save the DolbyMode value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 194@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SaveDolbyMode() -  Save the DolbyMode with valid arguments | HDMI, 0, HDR_TYPE_HLG, dark  | tvERROR_NONE | Should Pass |
* | 03 | call SaveDolbyMode() -  Save the DolbyMode with valid arguments | HDMI, 1, HDR_TYPE_SDR, bright  | tvERROR_NONE | Should Pass |
* | 04 | call SaveDolbyMode() -  Save the DolbyMode with valid arguments | HDMI, 2, HDR_TYPE_HDR10, dark | tvERROR_NONE | Should Pass |
* | 05 | call SaveDolbyMode() -  Save the DolbyMode with valid arguments | HDMI, 3, HDR_TYPE_DOVI, bright | tvERROR_NONE | Should Pass |
* | 06 | call SaveDolbyMode() -  Save the DolbyMode with valid arguments | HDMI, 4, HDR_TYPE_HLG, dark | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SaveDolbyMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveDolbyMode() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully save the DolbyMode value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 195@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SaveDolbyMode() -  save the DolbyMode even before tvInit() | HDMI, 0, HDR_TYPE_HLG, dark | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveDolbyMode() -  save the DolbyMode with invalid input | HDMI, 0, HDR_TYPE_MAX, dark | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveDolbyMode() -  save the DolbyMode with invalid input | HDMI, 0, HDR_TYPE_HLG, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveDolbyMode() -  save the DolbyMode with invalid input | "Invalid", 0, HDR_TYPE_HLG, 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveDolbyMode() -  save the DolbyMode with invalid input | HDMI, 11, HDR_TYPE_HLG, tvDisplayMode_4x3 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SaveDolbyMode() -  save the DolbyMode valid arguments | HDMI, 3, HDR_TYPE_DOVI, bright | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SaveDolbyMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetNumberOfModesupported() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully Get the Number Of Modesupported value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 196@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetNumberOfModesupported() -  Retrieve the current Mode supported with valid arguments | void | int | Should Pass |
* | 03 | call GetNumberOfModesupported() -  Retrieve the current Mode supported with valid arguments and validate with above value | void | int | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetNumberOfModesupported (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetNumberOfModesupported() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the Number Of Modesupported value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 197@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetNumberOfModesupported() -  Retrieve current Number Of TV Mode supported even before tvInit() | void | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetNumberOfModesupported() -  Retrieve current Number Of TV Mode supported valid arguments | void | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetNumberOfModesupported (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentPQIndex() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the PQIndex value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 198@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetCurrentPQIndex() -  Retrieve the current PQIndex with valid arguments | void | int | Should Pass |
* | 03 | call GetCurrentPQIndex() -  Retrieve the current PQIndex with valid arguments and validate with above value | void | int | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetCurrentPQIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentPQIndex() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the current PQIndex value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 199@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetCurrentPQIndex() -  Retrieve current PQIndex even before tvInit() | void | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetCurrentPQIndex() -  Retrieve current PQIndex valid arguments | void | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetCurrentPQIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetAllSupportedPicModeIndex() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the Supported PicModeIndex value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 200@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetAllSupportedPicModeIndex() -  Retrieve the Supported PicModeIndex with valid arguments | int [] | tvERROR_NONE | Should Pass |
* | 03 | call GetAllSupportedPicModeIndex() -  Retrieve the Supported PicModeIndex with valid arguments and validate with above value | int [] | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetAllSupportedPicModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetAllSupportedPicModeIndex() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the Supported PicModeIndex value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 201@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetAllSupportedPicModeIndex() -  Retrieve Supported PicModeIndex even before tvInit() | int [] | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetAllSupportedPicModeIndex() -   Retrieve Supported PicModeIndex with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetAllSupportedPicModeIndex() -  Retrieve Supported PicModeIndex valid arguments | int [] | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetAllSupportedPicModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCMSDefault() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the CMS Default value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 202@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetCMSDefault() -  Retrieve the current brightness with valid arguments | COLOR_HUE  | int | Should Pass |
* | 03 | call GetCMSDefault() -  Retrieve the current brightness with valid arguments and validate with above value | COLOR_HUE | int | Should Pass |
* | 04 | call GetCMSDefault() -  Retrieve the current brightness with valid arguments | COLOR_SATURATION  | int | Should Pass |
* | 05 | call GetCMSDefault() -  Retrieve the current brightness with valid arguments | COLOR_LUMA  | int | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetCMSDefault (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCMSDefault() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the CMS Default value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 203@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetCMSDefault() -  Retrieve current TV brightness even before tvInit() | COLOR_HUE | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetCMSDefault() -   Retrieve current TV brightness with invalid input | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetCMSDefault() -  Retrieve current TV brightness valid arguments | COLOR_HUE | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetCMSDefault (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetDolbyModeIndex() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the Dolby ModeIndex value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 204@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetDolbyModeIndex() -  Retrieve the current Dolby ModeIndex with valid arguments | const char * | int | Should Pass |
* | 03 | call GetDolbyModeIndex() -  Retrieve the current Dolby ModeIndex with valid arguments and validate with above value | const char * | int | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetDolbyModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetDolbyModeIndex() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the Dolby ModeIndex value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 205@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetDolbyModeIndex() -  Retrieve current TV Dolby ModeIndex even before tvInit() | const char * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetDolbyModeIndex() -   Retrieve current TV Dolby ModeIndex with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetDolbyModeIndex() -  Retrieve current TV Dolby ModeIndex valid arguments | const char * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetDolbyModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate ConvertVideoFormatToHDRFormat() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully Convert the VideoFormat To HDRFormat value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 206@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call ConvertVideoFormatToHDRFormat() -  Convert the VideoFormat To HDRFormat with valid arguments | tvVideoHDRFormat_SDR  | int | Should Pass |
* | 03 | call ConvertVideoFormatToHDRFormat() -  Convert the VideoFormat To HDRFormat with valid arguments and validate with above value | tvVideoHDRFormat_SDR  | int | Should Pass |
* | 04 | call ConvertVideoFormatToHDRFormat() -  Convert the VideoFormat To HDRFormat with valid arguments | tvVideoHDRFormat_HLG  | int | Should Pass |
* | 05 | call ConvertVideoFormatToHDRFormat() -  Convert the VideoFormat To HDRFormat with valid arguments | tvVideoHDRFormat_HDR10  | int | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_ConvertVideoFormatToHDRFormat (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate ConvertVideoFormatToHDRFormat() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully Convert the VideoFormat To HDRFormat once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 207@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call ConvertVideoFormatToHDRFormat() -  Retrieve current TV brightness even before tvInit() | tvVideoHDRFormat_SDR | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call ConvertVideoFormatToHDRFormat() -   Retrieve current TV brightness with invalid input | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call ConvertVideoFormatToHDRFormat() -  Retrieve current TV brightness valid arguments | tvVideoHDRFormat_SDR | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_ConvertVideoFormatToHDRFormat (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate ConvertTVColorToVendorColor() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully Convert TVColor To VendorColor once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 208@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call ConvertTVColorToVendorColor() -  Convert TVColor To VendorColor with valid arguments | tvDataColor_RED | int | Should Pass |
* | 03 | call ConvertTVColorToVendorColor() -  Convert TVColor To VendorColor with valid arguments and validate with above value | tvDataColor_RED | int | Should Pass |
* | 04 | call ConvertTVColorToVendorColor() -  Convert TVColor To VendorColor with valid arguments | tvDataColor_GREEN | int | Should Pass |
* | 05 | call ConvertTVColorToVendorColor() -  Convert TVColor To VendorColor with valid arguments | tvDataColor_BLUE | int | Should Pass |
* | 06 | call ConvertTVColorToVendorColor() -  Convert TVColor To VendorColor with valid arguments | tvDataColor_CYAN | int | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_ConvertTVColorToVendorColor (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate ConvertTVColorToVendorColor() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully Convert TVColor To VendorColor once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 209@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call ConvertTVColorToVendorColor() -  Convert TVColor To VendorColor even before tvInit() | tvDataColor_RED | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call ConvertTVColorToVendorColor() -   Convert TVColor To VendorColor with invalid input | tvDataColor_MAX | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call ConvertTVColorToVendorColor() -  Convert TVColor To VendorColor valid arguments | tvDataColor_RED | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_ConvertTVColorToVendorColor (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate ConvertHDRFormatToContentFormat() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully Convert TVColor To VendorColor once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 210@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call ConvertHDRFormatToContentFormat() -  Convert TVColor To VendorColor with valid arguments | HDR_TYPE_SDR | int | Should Pass |
* | 03 | call ConvertHDRFormatToContentFormat() -  Convert TVColor To VendorColor with valid arguments and validate with above value | HDR_TYPE_SDR | int | Should Pass |
* | 04 | call ConvertHDRFormatToContentFormat() -  Convert TVColor To VendorColor with valid arguments | HDR_TYPE_HDR10 | int | Should Pass |
* | 05 | call ConvertHDRFormatToContentFormat() -  Convert TVColor To VendorColor with valid arguments | HDR_TYPE_HDR10PLUS | int | Should Pass |
* | 06 | call ConvertHDRFormatToContentFormat() -  Convert TVColor To VendorColor with valid arguments | HDR_TYPE_DOVI | int | Should Pass |
* | 07 | call ConvertHDRFormatToContentFormat() -  Convert TVColor To VendorColor with valid arguments | HDR_TYPE_HLG | int | Should Pass |
* | 08 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_ConvertHDRFormatToContentFormat (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate ConvertHDRFormatToContentFormat() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully Convert TVColor To VendorColor value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 211@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call ConvertHDRFormatToContentFormat() -  Convert TVColor To VendorColor even before tvInit() | HDR_TYPE_SDR | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call ConvertHDRFormatToContentFormat() -   Convert TVColor To VendorColor with invalid input | HDR_TYPE_MAX | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call ConvertHDRFormatToContentFormat() -  Convert TVColor To VendorColor valid arguments | HDR_TYPE_SDR | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_ConvertHDRFormatToContentFormat (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetCMSState() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully Set the CMSState value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 212@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetGrayPattern() -  Set the CMSState with valid value | COLOR_HUE, COLOR_RED, COMPONENT_ENABLE | tvERROR_NONE | Should Pass |
* | 03 | call SetGrayPattern() -  Reset the CMSState with another valid value | COLOR_HUE, COLOR_RED, COMPONENT_DISABLE | tvERROR_NONE | Should Pass |
* | 04 | call SetGrayPattern() -  Set the CMSState with valid value | COLOR_SATURATION, COLOR_GREEN, COMPONENT_ENABLE | tvERROR_NONE | Should Pass |
* | 05 | call SetGrayPattern() -  Reset the CMSState with another valid value | COLOR_SATURATION, COLOR_GREEN , COMPONENT_DISABLE| tvERROR_NONE | Should Pass |
* | 06 | call SetGrayPattern() -  Reset the CMSState with another valid value | COLOR_LUMA, COLOR_BLUE, COMPONENT_RESET | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SetCMSState (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetCMSState() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully Set the CMSState value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 213@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetCMSState() -  Set the TV CMS State even before tvInit() | COLOR_HUE, COLOR_RED, COMPONENT_ENABLE | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetCMSState() -   Set the TV CMS State with invalid input | COLOR_HUE, COLOR_MAX, COMPONENT_ENABLE | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SetCMSState() -  Set the TV CMS State with valid input after tvTerm() | COLOR_HUE, COLOR_RED, COMPONENT_ENABLE | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SetCMSState (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate isWBUserDfault() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully verify WBUser Dfault value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 214@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call isWBUserDfault() -  verify WBUser Dfault with valid value | tvDataColor_t  | true | Should Pass |
* | 03 | call isWBUserDfault() -  verify WBUser Dfault with another valid value | tvDataColor_t  | true | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_isWBUserDfault (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate isWBUserDfault() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully verify WBUser Dfault value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 215@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call isWBUserDfault() - verify WBUser Dfault even before tvInit() | 30 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call isWBUserDfault() -   verify WBUser Dfault with invalid input | tvDataColor_t | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call isWBUserDfault() -  verify WBUser Dfault with valid input after tvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_isWBUserDfault (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetWBRgbType() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the WBRgb Type value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 216@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetWBRgbType() -  Retrieve the WBRgb Type with valid arguments | "red", "gain" | int | Should Pass |
* | 03 | call GetWBRgbType() -  Retrieve the WBRgb Type with valid arguments and validate with above value | "red", "gain" | int | Should Pass |
* | 04 | call GetWBRgbType() -  Retrieve the WBRgb Type with valid arguments | "blue", "gain" | int | Should Pass |
* | 05 | call GetWBRgbType() -  Retrieve the WBRgb Type with valid arguments | "green", "gain" | int | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetWBRgbType (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetWBRgbType() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the WBRgb Type value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 217@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetWBRgbType() -  Retrieve current WBRgb Type even before tvInit() | "red", "gain" | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetWBRgbType() -   Retrieve current WBRgb Type with invalid input | "red", NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetWBRgbType() -   Retrieve current WBRgb Type with invalid input | NULL, "gain" | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call GetWBRgbType() -  Retrieve current WBRgb Type valid arguments | "red", "gain" | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetWBRgbType (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetUSerWBValueOnInit() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the USer WBValue OnInit value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 218@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetUSerWBValueOnInit() -  Retrieve the USer WBValue with valid arguments | "red", "gain"  | int | Should Pass |
* | 03 | call GetUSerWBValueOnInit() -  Retrieve the USer WBValue with valid arguments and validate with above value | "red", "gain"  | int | Should Pass |
* | 04 | call GetUSerWBValueOnInit() -  Retrieve the USer WBValue Type with valid arguments | "blue", "gain" | int | Should Pass |
* | 05 | call GetUSerWBValueOnInit() -  Retrieve the USer WBValue Type with valid arguments | "green", "gain" | int | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetUSerWBValueOnInit (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetUSerWBValueOnInit() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the USer WBValue OnInit value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 219@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetUSerWBValueOnInit() -  Retrieve USer WBValue value even before tvInit() | "red", "gain" | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetUSerWBValueOnInit() -   Retrieve current USer WBValue with invalid input | "red", NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetUSerWBValueOnInit() -   Retrieve current USer WBValue with invalid input | NULL, "gain" | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call GetUSerWBValueOnInit() -  Retrieve current USer WBValue valid arguments | "red", "gain" | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetUSerWBValueOnInit (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate areEqual() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the brightness value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 220@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetBrightness() -  Retrieve the current brightness with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -  Retrieve the current brightness with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_areEqual (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate areEqual() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 221@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call areEqual() -  Retrieve current TV brightness even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call areEqual() -   Retrieve current TV brightness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call areEqual() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_areEqual (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemperatureUser() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the brightness value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 222@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetBrightness() -  Retrieve the current brightness with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -  Retrieve the current brightness with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SetColorTemperatureUser (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemperatureUser() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 223@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetColorTemperatureUser() -  Retrieve current TV brightness even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemperatureUser() -   Retrieve current TV brightness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemperatureUser() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SetColorTemperatureUser (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveColorTemperatureUser() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the brightness value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 224@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetBrightness() -  Retrieve the current brightness with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -  Retrieve the current brightness with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SaveColorTemperatureUser (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveColorTemperatureUser() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 225@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SaveColorTemperatureUser() -  Retrieve current TV brightness even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveColorTemperatureUser() -   Retrieve current TV brightness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SaveColorTemperatureUser() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SaveColorTemperatureUser (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetBacklightInfo() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the brightness value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 226@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetBrightness() -  Retrieve the current brightness with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -  Retrieve the current brightness with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SetBacklightInfo (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetBacklightInfo() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 227@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetBacklightInfo() -  Retrieve current TV brightness even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetBacklightInfo() -   Retrieve current TV brightness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SetBacklightInfo() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SetBacklightInfo (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetDriverEquivalentBLForCurrentFmt() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the brightness value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 228@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetBrightness() -  Retrieve the current brightness with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -  Retrieve the current brightness with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetDriverEquivalentBLForCurrentFmt (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetDriverEquivalentBLForCurrentFmt() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 229@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetDriverEquivalentBLForCurrentFmt() -  Retrieve current TV brightness even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetDriverEquivalentBLForCurrentFmt() -   Retrieve current TV brightness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetDriverEquivalentBLForCurrentFmt() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetDriverEquivalentBLForCurrentFmt (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**Ga
* @brief Validate GetHLGModeIndex() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the HLGModeIndex value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 230@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetHLGModeIndex() -  Retrieve the current HLGModeIndex with valid arguments | const char * | tvERROR_NONE | Should Pass |
* | 03 | call GetHLGModeIndex() -  Retrieve the current HLGModeIndex with valid arguments and validate with above value | const char * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetHLGModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetHLGModeIndex() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully get the HLGModeIndex value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 231@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetHLGModeIndex() -  Retrieve current TV HLGModeIndex even before tvInit() | const char * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetHLGModeIndex() -   Retrieve current TV HLGModeIndex with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetHLGModeIndex() -  Retrieve current TV HLGModeIndex valid arguments | const char * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetHLGModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**Ga
* @brief Validate GetHDR10ModeIndex() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully get the HDR10 ModeIndex value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 232@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetHDR10ModeIndex() -  Retrieve the current HDR10 ModeIndex with valid arguments | const char * | tvERROR_NONE | Should Pass |
* | 03 | call GetHDR10ModeIndex() -  Retrieve the current HDR10 ModeIndex with valid arguments and validate with above value | const char * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetHDR10ModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetHDR10ModeIndex() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the HDR10 ModeIndex value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 233@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetHDR10ModeIndex() -  Retrieve current TV HDR10 ModeIndex even before tvInit() | const char * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetHDR10ModeIndex() -   Retrieve current TV HDR10 ModeIndex with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetHDR10ModeIndex() -  Retrieve current TV HDR10 ModeIndex valid arguments | const char * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetHDR10ModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetBacklightFade() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the brightness value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 234@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetBrightness() -  Retrieve the current brightness with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -  Retrieve the current brightness with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SetBacklightFade (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetBacklightFade() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 235@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetBacklightFade() -  Retrieve current TV brightness even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetBacklightFade() -   Retrieve current TV brightness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SetBacklightFade() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SetBacklightFade (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate ReadAllModeConfigfile() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the brightness value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 236@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetBrightness() -  Retrieve the current brightness with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -  Retrieve the current brightness with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_ReadAllModeConfigfile (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate ReadAllModeConfigfile() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 237@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call ReadAllModeConfigfile() -  Retrieve current TV brightness even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call ReadAllModeConfigfile() -   Retrieve current TV brightness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call ReadAllModeConfigfile() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_ReadAllModeConfigfile (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate splitstringsfrombuffer() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the brightness value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 238@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetBrightness() -  Retrieve the current brightness with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -  Retrieve the current brightness with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_splitstringsfrombuffer (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate splitstringsfrombuffer() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 239@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call splitstringsfrombuffer() -  Retrieve current TV brightness even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call splitstringsfrombuffer() -   Retrieve current TV brightness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call splitstringsfrombuffer() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_splitstringsfrombuffer (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetGammaMode() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the brightness value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 240@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetBrightness() -  Retrieve the current brightness with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -  Retrieve the current brightness with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SetGammaMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetGammaMode() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 241@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetGammaMode() -  Retrieve current TV brightness even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetGammaMode() -   Retrieve current TV brightness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SetGammaMode() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SetGammaMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetLocalDimmingLevel() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the brightness value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 242@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetBrightness() -  Retrieve the current brightness with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -  Retrieve the current brightness with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SetLocalDimmingLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetLocalDimmingLevel() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 243@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetLocalDimmingLevel() -  Retrieve current TV brightness even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetLocalDimmingLevel() -   Retrieve current TV brightness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SetLocalDimmingLevel() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SetLocalDimmingLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetLocalDimmingLevel() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the brightness value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 244@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetBrightness() -  Retrieve the current brightness with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -  Retrieve the current brightness with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetLocalDimmingLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetLocalDimmingLevel() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 245@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetLocalDimmingLevel() -  Retrieve current TV brightness even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetLocalDimmingLevel() -   Retrieve current TV brightness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetLocalDimmingLevel() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetLocalDimmingLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveLocalDimmingLevel() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the brightness value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 246@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetBrightness() -  Retrieve the current brightness with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetBrightness() -  Retrieve the current brightness with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SaveLocalDimmingLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveLocalDimmingLevel() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 246@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SaveLocalDimmingLevel() -  Retrieve current TV brightness even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveLocalDimmingLevel() -   Retrieve current TV brightness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SaveLocalDimmingLevel() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SaveLocalDimmingLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate UpdateEDIDAndSetDimmingLevel() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the brightness value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 247@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call UpdateEDIDAndSetDimmingLevel() -  Update the TV EDID and DimmingLevel with valid value | 08 | tvERROR_NONE | Should Pass |
* | 03 | call UpdateEDIDAndSetDimmingLevel() -  Update the TV EDID and DimmingLevel with another valid value | 50 | tvERROR_NONE | Should Pass |
* | 04 | call UpdateEDIDAndSetDimmingLevel() -  Update the TV EDID and DimmingLevel with another valid value | 99 | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_UpdateEDIDAndSetDimmingLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate UpdateEDIDAndSetDimmingLevel() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 248@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call UpdateEDIDAndSetDimmingLevel() - Update the TV EDID and DimmingLevel even before tvInit() | 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call UpdateEDIDAndSetDimmingLevel() -   Update the TV EDID and DimmingLevel with invalid input | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call UpdateEDIDAndSetDimmingLevel() -   Update the TV EDID and DimmingLevel with invalid input | 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call UpdateEDIDAndSetDimmingLevel() -   Update the TV EDID and DimmingLevel with invalid input | 200 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call UpdateEDIDAndSetDimmingLevel() -  Update the TV EDID and DimmingLevel with valid input after tvTerm() | 1 | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_UpdateEDIDAndSetDimmingLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetLDIMAndEDIDLevel() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the brightness value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 249@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetLDIMAndEDIDLevel() -  Retrieve the current TV LDIM And EDID Level with valid arguments | 0, 1, int *, int * | tvERROR_NONE | Should Pass |
* | 02 | call GetLDIMAndEDIDLevel() -  Retrieve the current TV LDIM And EDID Level with valid arguments and validate with above value | 0, 1, int *, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetLDIMAndEDIDLevel() -  Retrieve the current TV LDIM And EDID Level with valid arguments | 1, 0, int *, int * | tvERROR_NONE | Should Pass |
* | 04 | call GetLDIMAndEDIDLevel() -  Retrieve the current TV LDIM And EDID Level with valid arguments and validate with above value | 1, 0, int *, int * | tvERROR_NONE | Should Pass |
* | 05 | call GetLDIMAndEDIDLevel() -  Retrieve the current TV LDIM And EDID Level with valid arguments | 88, 99, int *, int * | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetLDIMAndEDIDLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetLDIMAndEDIDLevel() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 250@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetLDIMAndEDIDLevel() -  Retrieve current TV LDIM And EDID Level with invalid input  | 0, 1, NULL, NULL | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call GetLDIMAndEDIDLevel() -  Retrieve current TV LDIM And EDID Level with invalid input | 0, 1, NULL, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call GetLDIMAndEDIDLevel() -  Retrieve current TV LDIM And EDID Level with invalid input | 1, 0, int *, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetLDIMAndEDIDLevel() -  Retrieve current TV LDIM And EDID Level with invalid input |1, 0, NULL , int *| tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetLDIMAndEDIDLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveLowLatencyState() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the brightness value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 251@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SaveLowLatencyState() -  Save the TV LowLatency State with valid value | -1, 0, 1, 0 | tvERROR_NONE | Should Pass |
* | 03 | call SaveLowLatencyState() -  Save the TV LowLatency State with another valid value | -1, 0, 1, 1 | tvERROR_NONE | Should Pass |
* | 04 | call SaveLowLatencyState() -  Save the TV LowLatency State with another valid value | -1, 5, 1, 0 | tvERROR_NONE | Should Pass |
* | 04 | call SaveLowLatencyState() -  Save the TV LowLatency State with another valid value | -1, 5, 1, 1 | tvERROR_NONE | Should Pass |
* | 04 | call SaveLowLatencyState() -  Save the TV LowLatency State with another valid value | -1, 0, 6, 0 | tvERROR_NONE | Should Pass |
* | 04 | call SaveLowLatencyState() -  Save the TV LowLatency State with another valid value | -1, 0, 6, 1 | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SaveLowLatencyState (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveLowLatencyState() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 252@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SaveLowLatencyState() - Save the TV LowLatency State even before tvInit() | -1, 0, 1, 0| tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveLowLatencyState() -   Save the TV LowLatency State with invalid input | -1, -1, -1, -1| tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveLowLatencyState() -   Save the TV LowLatency State with invalid input | -1, -1, 1, 1| tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveLowLatencyState() -   Save the TV LowLatency State with invalid input | -1, 0, 1, 20| tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveLowLatencyState() -   Save the TV LowLatency State with invalid input | -1, 0, 20, 0| tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SaveLowLatencyState() -   Save the TV LowLatency State with invalid input | -1, 50, 50, 50 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SaveLowLatencyState() -   Save the TV LowLatency State with invalid input | 100, 100, 100, 100 | tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 10 | call SaveLowLatencyState() -  Save the TV LowLatency State with valid input after tvTerm() | -1, 0,1, 0 | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SaveLowLatencyState (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetLowLatencyState() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the brightness value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 253@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetLowLatencyState() -  Set the LowLatency State with valid value | 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetLowLatencyState() -  Reset the LowLatency State with another valid value | 1 | tvERROR_NONE | Should Pass |
* | 04 | call SetLowLatencyState() -  Reset the LowLatency State with another valid value | 0 | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_SetLowLatencyState (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetLowLatencyState() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 254@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetLowLatencyState() - Set the TV LowLatency State even before tvInit() | 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetLowLatencyState() -   Set the TV LowLatency State with invalid input | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetLowLatencyState() -   Set the TV LowLatency State with invalid input | 2 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetLowLatencyState() -   Set the TV LowLatency State with invalid input | 5 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SetLowLatencyState() -  Set the TV LowLatency State with valid input after tvTerm() | 1 | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SetLowLatencyState (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetLowLatencyState() for all positive invocation scenarios
* 
* This test ensure following conditions:
* 1. Initialise the Tv Settings module using tvInit()
* 2. Able to successfully set the brightness value once module is initialized
* 3. Close the module using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 255@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetLowLatencyState() -  Retrieve the current LowLatency State with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetLowLatencyState() -  Retrieve the current LowLatency State with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/

void test_l1_tvSettings_positive_GetLowLatencyState (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetLowLatencyState() for all negative invocation scenarios
* 
* This test ensure following conditions:
* 1. tvERROR_INVALID_STATE is returned if called without initialising
* 2. Able to successfully set the brightness value once module is initialized
* 3. Passing invalid parameter returns tvERROR_INVALID_PARAM
* 4. Once module is closed, API returns tvERROR_INVALID_STATE
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 256@n
* 
* **Pre-Conditions:** @n
* None
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* TODO: Add the steps to run this test and add a line in the below table for each input variation tried in this function.@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetLowLatencyState() -  Retrieve current TV LowLatency State even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetLowLatencyState() -   Retrieve current TV LowLatency State with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetLowLatencyState() -  Retrieve current TV LowLatency State valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
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
	UT_add_test( pSuite, "tvTerm_L1_positive" ,test_l1_tvSettings_positive_tvTerm );
	UT_add_test( pSuite, "tvTerm_L1_negative" ,test_l1_tvSettings_negative_tvTerm );
	UT_add_test( pSuite, "tvSD3toCriSyncInit_L1_positive" ,test_l1_tvSettings_positive_tvSD3toCriSyncInit );
	UT_add_test( pSuite, "tvSD3toCriSyncInit_L1_negative" ,test_l1_tvSettings_negative_tvSD3toCriSyncInit );
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
