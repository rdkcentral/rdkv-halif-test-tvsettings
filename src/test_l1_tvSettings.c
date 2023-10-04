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
* @page tvSettings_L1_Tests TV SETTINGS Level 1 Tests
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

/**
* @brief Validate tvInit() for all positive invocation scenarios
* 
* This test ensures that the TV Settings module is initialised using tvInit()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 01@n
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call tvInit() -  Re-initialise to get the appropriate error code | void | tvERROR_INVALID_STATE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_negative_tvInit (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate tvTerm() for all positive invocation scenarios
* 
* This test ensures that the TV Settings module is terminated using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 03@n
* 
* **Pre-Conditions:** Initialise the module using tvInit()
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
* @note There is no  negative error return value currently for tvTerm()
* @brief Validate tvTerm() for all neagtive invocation scenarios
* 
* This test ensures that the TV Settings module is terminated using tvTerm()
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 04@n
* 
* **Pre-Conditions:** Initialise the module using tvInit()
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
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 05@n
* 
* **Pre-Conditions:** None@n
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | Call GetTVPictureMode() -  Retrieve the current TVPictureMode with valid arguments | char * | tvERROR_NONE | Should Pass |
* | 03 | call GetTVPictureMode() -  Retrieve the current TVPictureMode with valid arguments and validate with above value | char * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetTVPictureMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVPictureMode() for all negative invocation scenarios
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
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetTVPictureMode() - Retrieve current TV PictureMode even before tvInit() | char * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetTVPictureMode() -  Retrieve current TV PictureMode with valid input after tvTerm() | NULL | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetTVPictureMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/*Todo: add environement varaibale for picture mode ("Entertainment")*/
/**
* @brief Validate SetTVPictureMode() for all positive invocation scenarios
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 07@n
* 
* **Pre-Conditions:** None@n
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetTVPictureMode() -  Set the TV PictureMode with valid value | "Entertainment" | tvERROR_NONE | Should Pass |
* | 03 | call SetTVPictureMode() -  Reset the TV PictureMode with another valid value | "Dynamic" | tvERROR_NONE | Should Pass |
* | 04 | call SetTVPictureMode() -  Reset the TV PictureMode with another valid value | "Entertainment" | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* **Test Case ID:** 08@n
* 
* **Pre-Conditions:** None@n
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
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 09@n
* 
* **Pre-Conditions:** None@n
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetBacklight() -  Retrieve the current Backlight with valid argument |int *| tvERROR_NONE | Should Pass |
* | 03 | call GetBacklight() -  Retrieve the current Backlight with valid argument and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* **Test Case ID:** 10@n
* 
* **Pre-Conditions:** None@n
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call GetBacklight() -   Retrieve current TV backlight even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetBacklight() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
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
* **Test Case ID:** 11@n
* 
* **Pre-Conditions:** None@n
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
* | 05 | call SetBacklight() -  Reset the backlight with another valid value | 99 | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* **Test Case ID:** 12@n
* 
* **Pre-Conditions:** None@n
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* |Variation / Step|Description|Test Data|Expected Result|Notes|
* |:--:|---------|----------|--------------|-----|
* | 01 | call SetBacklight() - Set the TV backlight even before tvInit() | 30 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetBacklight() -   Set the TV backlight with lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetBacklight() -   Set the TV backlight with max range | 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetBacklight() -   Set the TV backlight with max range | 200 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call SetBacklight() -  Set the TV backlight with valid input after tvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetBacklight (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetBrightness() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetBrightness() -  Set the brightness with valid value | 00 | tvERROR_NONE | Should Pass |
* | 03 | call SetBrightness() -  Reset the brightness with another valid value | 50 | tvERROR_NONE | Should Pass |
* | 04 | call SetBrightness() -  Reset the brightness with another valid value | 100 | tvERROR_NONE | Should Pass |
* | 05 | call SetBrightness() -  Reset the brightness with another valid value | 100 | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetBrightness() - Set the TV brightness even before tvInit() | 30 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetBrightness() -   Set the TV brightness with lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetBrightness() -   Set the TV brightness with max range | 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetBrightness() -   Set the TV brightness with max range | 200 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call SetBrightness() -  Set the TV brightness with valid input after tvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetBrightness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetBrightness() for all positive invocation scenarios
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
* | 01 | call GetBrightness() -  Retrieve current TV brightness even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetBrightness() -  Retrieve current TV brightness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetBrightness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetContrast() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetContrast() -  Set the Contrast with valid value | 00 | tvERROR_NONE | Should Pass |
* | 03 | call SetContrast() -  Reset the Contrast with another valid value | 50 | tvERROR_NONE | Should Pass |
* | 04 | call SetContrast() -  Reset the Contrast with another valid value | 100 | tvERROR_NONE | Should Pass |
* | 05 | call SetContrast() -  Reset the Contrast with another valid value | 100 | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client  | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetContrast() - Set the TV contrast even before tvInit() | 30 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetContrast() -   Set the TV contrast with lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetContrast() -   Set the TV contrast with max range | 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetContrast() -   Set the TV contrast with max range | 200 | tvERROR_INVALID_PARAM | Should Pass |
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
* | 01 | call GetContrast() -  Retrieve current TV contrast even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetContrast() -  Retrieve current TV contrast valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetSharpness() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetSharpness() -  Set the sharpness with valid value | 00 | tvERROR_NONE | Should Pass |
* | 03 | call SetSharpness() -  Reset the sharpness with another valid value | 50 | tvERROR_NONE | Should Pass |
* | 04 | call SetSharpness() -  Reset the sharpness with another valid value | 100 | tvERROR_NONE | Should Pass |
* | 05 | call SetSharpness() -  Reset the sharpness with another valid value | 100 | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetSharpness() - Set the TV sharpness even before tvInit() | 30 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetSharpness() -   Set the TV sharpness with lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetSharpness() -   Set the TV sharpness with max range | 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetSharpness() -   Set the TV sharpness with max range | 200 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call SetSharpness() -  Set the TV sharpness with valid input after tvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetSharpness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetSharpness() for all positive invocation scenarios
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
* | 01 | call GetSharpness() -  Retrieve current TV sharpness even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetSharpness() -  Retrieve current TV sharpness valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetSharpness (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetSaturation() for all positive invocation scenarios
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
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetSaturation() -  Set the saturation with valid value | 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetSaturation() -  Reset the saturation with another valid value | 50 | tvERROR_NONE | Should Pass |
* | 04 | call SetSaturation() -  Reset the saturation with another valid value | 100 | tvERROR_NONE | Should Pass |
* | 05 | call SetSaturation() -  Reset the saturation with another valid value | 100 | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* **Test Case ID:** 26@n
* 
* **Pre-Conditions:** None@n
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetSaturation() - Set the TV saturation even before tvInit() | 30 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetSaturation() -   Set the TV saturation with lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetSaturation() -   Set the TV saturation with max range | 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetSaturation() -   Set the TV saturation with max range | 200 | tvERROR_INVALID_PARAM | Should Pass |
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
* | 01 | call GetSaturation() -  Retrieve current TV saturation even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetSaturation() -  Retrieve current TV saturation valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetHue() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetHue() -  Set the hue with valid value | 00 | tvERROR_NONE | Should Pass |
* | 03 | call SetHue() -  Reset the hue with another valid value | 50 | tvERROR_NONE | Should Pass |
* | 04 | call SetHue() -  Reset the hue with another valid value | 100 | tvERROR_NONE | Should Pass |
* | 05 | call SetHue() -  Reset the hue with another valid value | 100 | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetHue() - Set the TV hue even before tvInit() | 30 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetHue() -   Set the TV hue with lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetHue() -   Set the TV hue with max range | 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetHue() -   Set the TV hue with max range | 200 | tvERROR_INVALID_PARAM | Should Pass |
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
* | 01 | call GetHue() -  Retrieve current TV Hue even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetHue() -  Retrieve current TV Hue valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemperature() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemperature() -  Set the ColorTemperature with valid value | tvColorTemp_STANDARD  | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemperature() -  Reset the ColorTemperature with another valid value | tvColorTemp_WARM | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemperature() -  Reset the ColorTemperature with another valid value | tvColorTemp_COLD | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemperature() -  Reset the ColorTemperature with another valid value | tvColorTemp_COLD | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetColorTemperature() - Set the TV ColorTemperature even before tvInit() | tvColorTemp_WARM | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemperature() -   Set the TV ColorTemperature with lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemperature() -   Set the TV ColorTemperature with max range | tvColorTemp_MAX | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemperature() -  Set the TV ColorTemperature with valid input after tvTerm() | tvColorTemp_USER | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemperature (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/** 
* @brief Validate GetColorTemperature() for all positive invocation scenarios
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
* | 01 | call GetColorTemperature() -  Retrieve current TV ColorTemperature even before tvInit() | tvColorTemp_t  * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemperature() -  Retrieve current TV ColorTemperature valid arguments | tvColorTemp_t  * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetColorTemperature (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetAspectRatio() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetAspectRatio() -  Set the AspectRatio with valid value | tvDisplayMode_4x3  | tvERROR_NONE | Should Pass |
* | 03 | call SetAspectRatio() -  Reset the AspectRatio with another valid value | tvDisplayMode_16x9 | tvERROR_NONE | Should Pass |
* | 04 | call SetAspectRatio() -  Reset the AspectRatio with another valid value | tvDisplayMode_FULL | tvERROR_NONE | Should Pass |
* | 05 | call SetAspectRatio() -  Reset the AspectRatio with another valid value | tvDisplayMode_NORMAL | tvERROR_NONE | Should Pass |
* | 06 | call SetAspectRatio() -  Reset the AspectRatio with another valid value | tvDisplayMode_AUTO | tvERROR_NONE | Should Pass |
* | 07 | call SetAspectRatio() -  Reset the AspectRatio with another valid value | tvDisplayMode_DIRECT | tvERROR_NONE | Should Pass |
* | 08 | call SetAspectRatio() -  Reset the AspectRatio with another valid value | tvDisplayMode_ZOOM | tvERROR_NONE | Should Pass |
* | 09 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetAspectRatio() - Set the TV AspectRatio even before tvInit() | tvDisplayMode_16x9 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call SetAspectRatio() -  Set the TV AspectRatio with valid input after tvTerm() | tvDisplayMode_16x9 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetAspectRatio (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetAspectRatio() for all positive invocation scenarios
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
* | 01 | call GetAspectRatio() -  Retrieve current TV AspectRatio even before tvInit() | tvDisplayMode_t * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetAspectRatio() -  Retrieve current TV AspectRatio valid arguments | tvDisplayMode_t * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetAspectRatio (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetSupportedBacklightModes() for all positive invocation scenarios
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
* | 01 | call GetSupportedBacklightModes() -  Retrieve current TV SupportedBacklightModes even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetSupportedBacklightModes() -  Retrieve current TV SupportedBacklightModes valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetSupportedBacklightModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/*@todo L2 should cover GetCurrentBacklightMode is in the list of GetSupportedBacklightModes()*/
/** 
* @brief Validate GetCurrentBacklightMode() for all positive invocation scenarios
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
* | 01 | call GetCurrentBacklightMode() -  Retrieve current TV CurrentBacklightMode even before tvInit() | tvBacklightMode_t * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetCurrentBacklightMode() -  Retrieve current TV CurrentBacklightMode valid arguments | tvBacklightMode_t * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetCurrentBacklightMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/** 
* @brief Validate SetCurrentBacklightMode() for all positive invocation scenarios
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

/*@todo max range  and low range update in all the set apis*/
/*verify GetSupportedBacklightModes then SetCurrentBacklightMode validate  */
/**
* @brief Validate SetCurrentBacklightMode() for all negative invocation scenarios
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
* | 01 | call SetCurrentBacklightMode() - Set the TV CurrentBacklightMode even before tvInit() | tvBacklightMode_AMBIENT | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetCurrentBacklightMode() -   Set the TV CurrentBacklightMode with max range | tvBacklightMode_INVALID | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetCurrentBacklightMode() -   Set the TV CurrentBacklightMode with less than the lower range  | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call SetCurrentBacklightMode() -  Set the TV CurrentBacklightMode with valid input after tvTerm() | tvBacklightMode_MANUAL | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_SetCurrentBacklightMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentVideoFormat() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetCurrentVideoFormat() -  Retrieve the current CurrentVideoFormat with valid arguments | tvVideoHDRFormat_t * | tvERROR_NONE | Should Pass |
* | 03 | call GetCurrentVideoFormat() -  Retrieve the current CurrentVideoFormat with valid arguments and validate with above value | tvVideoHDRFormat_t * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetCurrentVideoFormat (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/* @note test_l1_tvSettings_negative_GetCurrentVideoFormat() is not implemented no negative return type*/

/**  
* @brief Validate GetCurrentVideoFormat() for all negative invocation scenarios
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
* | 01 | call GetCurrentVideoFormat() -  Retrieve current TV CurrentVideoFormat even before tvInit() | tvVideoHDRFormat_t * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call GetVideoResolution() -  Retrieve current TV VideoResolution even before tvInit() | tvResolutionParam_t * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetVideoResolution() -  Retrieve current TV VideoResolution valid arguments | tvResolutionParam_t * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetVideoResolution (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetVideoFrameRate() for all positive invocation scenarios
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
* | 01 | call GetVideoFrameRate() -  Retrieve current TV VideoFrameRate even before tvInit() | tvVideoFrameRate_t * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetVideoFrameRate() -  Retrieve current TV VideoFrameRate valid arguments | tvVideoFrameRate_t * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetVideoFrameRate (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate setWakeupConfig() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call setWakeupConfig() -  Set the WakeupConfig with valid value | tvWakeupSrc_VOICE , false | tvERROR_NONE | Should Pass |
* | 03 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_VOICE , true | tvERROR_NONE | Should Pass |
* | 04 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_PRESENCE_DETECTION, false | tvERROR_NONE | Should Pass |
* | 05 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_PRESENCE_DETECTION, true | tvERROR_NONE | Should Pass |
* | 06 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_BLUETOOTH, false | tvERROR_NONE | Should Pass |
* | 07 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_BLUETOOTH, true | tvERROR_NONE | Should Pass |
* | 08 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_WIFI, false | tvERROR_NONE | Should Pass |
* | 09 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_WIFI, true | tvERROR_NONE | Should Pass |
* | 10 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_IR, false | tvERROR_NONE | Should Pass |
* | 11 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_IR, true | tvERROR_NONE | Should Pass |
* | 12 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_POWER_KEY, false | tvERROR_NONE | Should Pass |
* | 13 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_POWER_KEY, true | tvERROR_NONE | Should Pass |
* | 14 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_TIMER, false | tvERROR_NONE | Should Pass |
* | 15 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_TIMER, true | tvERROR_NONE | Should Pass |
* | 16 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_CEC, false | tvERROR_NONE | Should Pass |
* | 17 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_CEC, true | tvERROR_NONE | Should Pass |
* | 18 | call setWakeupConfig() -  Reset the WakeupConfig with another valid value | tvWakeupSrc_LAN, false | tvERROR_NONE | Should Pass |
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
* | 01 | call setWakeupConfig() - Set the TV WakeupConfig even before tvInit() | tvWakeupSrc_LAN, true | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call setWakeupConfig() -   Set the TV WakeupConfig with less than lower range | -1, true  | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call setWakeupConfig() -   Set the TV WakeupConfig with  max range | tvWakeupSrc_MAX, true  | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call setWakeupConfig() -  Set the TV WakeupConfig with valid input after tvTerm() | tvWakeupSrc_CEC, false  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_setWakeupConfig (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetRGBPattern() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetRGBPattern() -  Set the RGBPattern with valid value | 00,00,00 | tvERROR_NONE | Should Pass |
* | 03 | call SetRGBPattern() -  Reset the RGBPattern with another valid value | 100,100,100 | tvERROR_NONE | Should Pass |
* | 04 | call SetRGBPattern() -  Reset the RGBPattern with another valid value | 255,255,255 | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetRGBPattern() - Set the TV RGBPattern even before tvInit() | 08,08,08 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetRGBPattern() - Set the TV RGBPattern even before tvInit() | 256,80,100 | tvERROR_GENERAL | Should Pass |
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetRGBPattern() -  Retrieve the current RGB Pattern with valid arguments | int *, int *, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetRGBPattern() -  Retrieve the current RGB Pattern with valid arguments and validate with above value | int *, int *, int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetRGBPattern (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetRGBPattern() for all negative invocation scenarios
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
* | 01 | call GetRGBPattern() -  Retrieve current TV RGBPattern even before tvInit() | int *, int *, int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() - Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetRGBPattern() -  Retrieve current TV RGBPattern valid arguments | int *, int *, int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetRGBPattern (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetGrayPattern() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetGrayPattern() -  Set the GrayPattern with valid value | 00 | tvERROR_NONE | Should Pass |
* | 03 | call SetGrayPattern() -  Reset the GrayPattern with another valid value | 100 | tvERROR_NONE | Should Pass |
* | 04 | call SetGrayPattern() -  Reset the GrayPattern with another valid value | 255 | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetGrayPattern (void)
{
	UT_FAIL(This function needs to be implemented!); 
}
/*todo experiment more than 255, check the return value hal*/
/** 
* @brief Validate SetGrayPattern() for all negative invocation scenarios
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
* | 01 | call SetGrayPattern() - Set the TV GrayPattern even before tvInit() | 30 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call SetGrayPattern() -  Set the TV GrayPattern with valid input after tvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetGrayPattern (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetGrayPattern() for all positive invocation scenarios
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 61@n
* 
* **Pre-Conditions:** None@n
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
* | 01 | call GetGrayPattern() -  Retrieve current TV GrayPattern even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetGrayPattern() -  Retrieve current TV GrayPattern valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetGrayPattern (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Rgain() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_Rgain() -  Set the ColorTemp Rgain with valid value | tvColorTemp_STANDARD , 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Rgain() -  Reset the ColorTemp Rgain with another valid value | tvColorTemp_STANDARD, 2047 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Rgain() -  Reset the ColorTemp Rgain with another valid value | tvColorTemp_WARM , 0 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_Rgain() -  Reset the ColorTemp Rgain with another valid value | tvColorTemp_WARM, 2047 | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_Rgain() -  Reset the ColorTemp Rgain with another valid value | tvColorTemp_COLD, 0 | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_Rgain() -  Reset the ColorTemp Rgain with another valid value | tvColorTemp_COLD, 2047 | tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_Rgain() -  Reset the ColorTemp Rgain with another valid value | tvColorTemp_USER, 0 | tvERROR_NONE | Should Pass |
* | 09 | call SetColorTemp_Rgain() -  Reset the ColorTemp Rgain with another valid value | tvColorTemp_USER, 2047 | tvERROR_NONE | Should Pass |
* | 10 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemp_Rgain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Rgain() for all negative invocation scenarios
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
* | 01 | call SetColorTemp_Rgain() - Set the TV ColorTemp Rgain even before tvInit() |  tvColorTemp_COLD, 2047 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Rgain() -   Set the TV ColorTemp Rgain with lower range |tvColorTemp_COLD, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_Rgain() -   Set the TV ColorTemp Rgain with max range |tvColorTemp_COLD, 2048 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_Rgain() -   Set the TV ColorTemp Rgain with max range | tvColorTemp_MAX, 100 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_Rgain() -  Set the TV ColorTemp Rgain with valid input after tvTerm() | tvColorTemp_COLD, 2047 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_Rgain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Rgain() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_Rgain() -  Retrieve the current ColorTemp Rgain with valid arguments |tvColorTemp_STANDARD, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Rgain() -  Retrieve the current ColorTemp Rgain with valid arguments and validate with above value |tvColorTemp_STANDARD, int * | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_Rgain() -  Retrieve the current ColorTemp Rgain with valid arguments and validate with above value |tvColorTemp_WARM, int * | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_Rgain() -  Retrieve the current ColorTemp Rgain with valid arguments and validate with above value |tvColorTemp_COLD, int * | tvERROR_NONE | Should Pass |
* | 06 | call GetColorTemp_Rgain() -  Retrieve the current ColorTemp Rgain with valid arguments and validate with above value |tvColorTemp_USER, int * | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_Rgain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Rgain() for all negative invocation scenarios
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
* | 01 | call GetColorTemp_Rgain() -  Retrieve current TV ColorTemp Rgain even before tvInit() | tvColorTemp_STANDARD, int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Rgain() -   Retrieve current TV ColorTemp Rgain with invalid input | tvColorTemp_STANDARD, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_Rgain() -   Retrieve current TV ColorTemp Rgain with less than lower range | -1, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_Rgain() -   Retrieve current TV ColorTemp Rgain with max range | tvColorTemp_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call GetColorTemp_Rgain() -  Retrieve current TV ColorTemp Rgain valid arguments | tvColorTemp_WARM, int * | tvERROR_INVALID_STATE | Should Pass ||
*/
void test_l1_tvSettings_negative_GetColorTemp_Rgain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Ggain() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_Ggain() -  Set the ColorTemp Ggain with valid value | tvColorTemp_STANDARD , 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Ggain() -  Reset the ColorTemp Ggain with another valid value | tvColorTemp_STANDARD, 2047 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Ggain() -  Reset the ColorTemp Ggain with another valid value | tvColorTemp_WARM , 0 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_Ggain() -  Reset the ColorTemp Ggain with another valid value | tvColorTemp_WARM, 2047 | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_Ggain() -  Reset the ColorTemp Ggain with another valid value | tvColorTemp_COLD, 0 | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_Ggain() -  Reset the ColorTemp Ggain with another valid value | tvColorTemp_COLD, 2047 | tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_Ggain() -  Reset the ColorTemp Ggain with another valid value | tvColorTemp_USER, 0 | tvERROR_NONE | Should Pass |
* | 09 | call SetColorTemp_Ggain() -  Reset the ColorTemp Ggain with another valid value | tvColorTemp_USER, 2047 | tvERROR_NONE | Should Pass |
* | 10 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemp_Ggain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Ggain() for all negative invocation scenarios
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
* | 01 | call SetColorTemp_Ggain() - Set the TV ColorTemp Ggain  even before tvInit() |  tvColorTemp_COLD, 2047 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Ggain() -   Set the TV ColorTemp Ggain with lower range |tvColorTemp_COLD, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_Ggain() -   Set the TV ColorTemp Ggain  with max range |tvColorTemp_COLD, 2048 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_Ggain() -   Set the TV ColorTemp Ggain  with lower range | -1, 100 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_Ggain() -   Set the TV ColorTemp Ggain  with max range | tvColorTemp_MAX, 100 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_Ggain() -  Set the TV ColorTemp Ggain  with valid input after tvTerm() | tvColorTemp_COLD, 2047 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_Ggain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Ggain() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_Ggain() -  Retrieve the current ColorTemp Ggain with valid arguments |tvColorTemp_STANDARD, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Ggain() -  Retrieve the current ColorTemp Ggain with valid arguments and validate with above value |tvColorTemp_STANDARD, int * | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_Ggain() -  Retrieve the current ColorTemp Ggain with valid arguments and validate with above value |tvColorTemp_WARM, int * | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_Ggain() -  Retrieve the current ColorTemp Ggain with valid arguments and validate with above value |tvColorTemp_COLD, int * | tvERROR_NONE | Should Pass |
* | 06 | call GetColorTemp_Ggain() -  Retrieve the current ColorTemp Ggain with valid arguments and validate with above value |tvColorTemp_USER, int * | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_Ggain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Ggain() for all negative invocation scenarios
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
* | 01 | call GetColorTemp_Ggain() -  Retrieve current TV ColorTemp Ggain even before tvInit() | tvColorTemp_STANDARD, int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Ggain() -   Retrieve current TV ColorTemp Ggain with invalid input | tvColorTemp_STANDARD, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_Ggain() -   Retrieve current TV ColorTemp Ggain with lower range | -1, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_Ggain() -   Retrieve current TV ColorTemp Ggain with max range | tvColorTemp_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call GetColorTemp_Ggain() -  Retrieve current TV ColorTemp Ggain valid arguments | tvColorTemp_WARM, int * | tvERROR_INVALID_STATE | Should Pass ||
*/
void test_l1_tvSettings_negative_GetColorTemp_Ggain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Bgain() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_Bgain() -  Set the ColorTemp Bgain with valid value | tvColorTemp_STANDARD , 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Bgain() -  Reset the ColorTemp Bgain with another valid value | tvColorTemp_STANDARD, 2047 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Bgain() -  Reset the ColorTemp Bgain with another valid value | tvColorTemp_WARM , 0 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_Bgain() -  Reset the ColorTemp Bgain with another valid value | tvColorTemp_WARM, 2047 | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_Bgain() -  Reset the ColorTemp Bgain with another valid value | tvColorTemp_COLD, 0 | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_Bgain() -  Reset the ColorTemp Bgain with another valid value | tvColorTemp_COLD, 2047 | tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_Bgain() -  Reset the ColorTemp Bgain with another valid value | tvColorTemp_USER, 0 | tvERROR_NONE | Should Pass |
* | 09 | call SetColorTemp_Bgain() -  Reset the ColorTemp Bgain with another valid value | tvColorTemp_USER, 2047 | tvERROR_NONE | Should Pass |
* | 10 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemp_Bgain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Bgain() for all negative invocation scenarios
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
* | 01 | call SetColorTemp_Bgain() - Set the TV ColorTemp Bgain even before tvInit() |  tvColorTemp_COLD, 2047 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Bgain() -   Set the TV ColorTemp Bgain with lower range |tvColorTemp_COLD, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_Bgain() -   Set the TV ColorTemp Bgain with max range |tvColorTemp_COLD, 2048 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_Bgain() -   Set the TV ColorTemp Bgain with lower range | -1, 100 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_Bgain() -   Set the TV ColorTemp Bgain with max range | tvColorTemp_MAX, 100 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_Bgain() -  Set the TV ColorTemp Bgain with valid input after tvTerm() | tvColorTemp_COLD, 2047 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_Bgain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Bgain() for all positive invocation scenarios
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
* | 01 | call GetColorTemp_Bgain() -  Retrieve current TV ColorTemp Bgain even before tvInit() | tvColorTemp_STANDARD, int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Bgain() -   Retrieve current TV ColorTemp Bgain with invalid input | tvColorTemp_STANDARD, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_Bgain() -   Retrieve current TV ColorTemp Bgain with lower range | -1, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_Bgain() -   Retrieve current TV ColorTemp Bgain with max range | tvColorTemp_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call GetColorTemp_Bgain() -  Retrieve current TV ColorTemp Bgain valid arguments | tvColorTemp_WARM, int * | tvERROR_INVALID_STATE | Should Pass ||
*/
void test_l1_tvSettings_negative_GetColorTemp_Bgain (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_R_post_offset() for all positive invocation scenarios
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
* | 01 | call SetColorTemp_R_post_offset() - Set the TV ColorTemp R_post_offset even before tvInit() | tvColorTemp_STANDARD, 104 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_R_post_offset() -   Set the TV ColorTemp R_post_offset with lower range | tvColorTemp_WARM, -1025 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_R_post_offset() -   Set the TV ColorTemp R_post_offset with max range | tvColorTemp_COLD, 1025 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_R_post_offset() -   Set the TV ColorTemp R_post_offset with lower range | -1, 500 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_R_post_offset() -   Set the TV ColorTemp R_post_offset with max range | tvColorTemp_MAX, 500 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_R_post_offset() -  Set the TV ColorTemp R_post_offset with valid input after tvTerm() | tvColorTemp_STANDARD, 10 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_R_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}
/todo: add cold and user 
/**
* @brief Validate GetColorTemp_R_post_offset() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_R_post_offset() -  Retrieve the current ColorTemp R_post_offset with valid arguments | tvColorTemp_WARM, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_R_post_offset() -  Retrieve the current ColorTemp R_post_offset with valid arguments and validate with above value | tvColorTemp_WARM, int * | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_R_post_offset() -  Retrieve the current ColorTemp R_post_offset with valid arguments | tvColorTemp_STANDARD, int * | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_R_post_offset() -  Retrieve the current ColorTemp R_post_offset with valid arguments and validate with above value | tvColorTemp_STANDARD, int * | tvERROR_NONE | Should Pass |
* | 06 | call GetColorTemp_R_post_offset() -  Retrieve the current ColorTemp R_post_offset with valid arguments | tvColorTemp_COLD, int * | tvERROR_NONE | Should Pass |
* | 07 | call GetColorTemp_R_post_offset() -  Retrieve the current ColorTemp R_post_offset with valid arguments and validate with above value | tvColorTemp_COLD, int * | tvERROR_NONE | Should Pass |
* | 08 | call GetColorTemp_R_post_offset() -  Retrieve the current ColorTemp R_post_offset with valid arguments | tvColorTemp_USER, int * | tvERROR_NONE | Should Pass |
* | 09 | call GetColorTemp_R_post_offset() -  Retrieve the current ColorTemp R_post_offset with valid arguments and validate with above value | tvColorTemp_USER, int * | tvERROR_NONE | Should Pass |
* | 10 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_R_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_R_post_offset() for all negative invocation scenarios
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
* | 01 | call GetColorTemp_R_post_offset() -  Retrieve current TV ColorTemp R_post_offset even before tvInit() |  tvColorTemp_COLD, int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_R_post_offset() -   Retrieve current TV ColorTemp R_post_offset with invalid input |  tvColorTemp_COLD, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_R_post_offset() -   Retrieve current TV ColorTemp R_post_offset with lower range |  -1, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_R_post_offset() -   Retrieve current TV ColorTemp R_post_offset with max range |  tvColorTemp_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
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
* | 01 | call SetColorTemp_G_post_offset() - Set the TV ColorTemp G_post_offset even before tvInit() | tvColorTemp_STANDARD, 104 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_G_post_offset() -   Set the TV ColorTemp G_post_offset with lower range | tvColorTemp_WARM, -1025 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_G_post_offset() -   Set the TV ColorTemp G_post_offset with max range | tvColorTemp_COLD, 1025 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_G_post_offset() -   Set the TV ColorTemp G_post_offset with lower range | -1, 500 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_G_post_offset() -   Set the TV ColorTemp G_post_offset with max range | tvColorTemp_MAX, 500 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_G_post_offset() -  Set the TV ColorTemp G_post_offset with valid input after tvTerm() | tvColorTemp_STANDARD, 10 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_G_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_G_post_offset() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_G_post_offset() -  Retrieve the current ColorTemp G_post_offset with valid arguments | tvColorTemp_WARM, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_G_post_offset() -  Retrieve the current ColorTemp G_post_offset with valid arguments and validate with above value | tvColorTemp_WARM, int * | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_G_post_offset() -  Retrieve the current ColorTemp G_post_offset with valid arguments | tvColorTemp_STANDARD, int * | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_G_post_offset() -  Retrieve the current ColorTemp G_post_offset with valid arguments and validate with above value | tvColorTemp_STANDARD, int * | tvERROR_NONE | Should Pass |
* | 06 | call GetColorTemp_G_post_offset() -  Retrieve the current ColorTemp G_post_offset with valid arguments | tvColorTemp_COLD, int * | tvERROR_NONE | Should Pass |
* | 07 | call GetColorTemp_G_post_offset() -  Retrieve the current ColorTemp G_post_offset with valid arguments and validate with above value | tvColorTemp_COLD, int * | tvERROR_NONE | Should Pass |
* | 08 | call GetColorTemp_G_post_offset() -  Retrieve the current ColorTemp G_post_offset with valid arguments | tvColorTemp_USER, int * | tvERROR_NONE | Should Pass |
* | 09 | call GetColorTemp_G_post_offset() -  Retrieve the current ColorTemp G_post_offset with valid arguments and validate with above value | tvColorTemp_USER, int * | tvERROR_NONE | Should Pass |
* | 10 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_G_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_G_post_offset() for all negative invocation scenarios
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
* | 01 | call GetColorTemp_G_post_offset() -  Retrieve current TV ColorTemp G_post_offset even before tvInit() |  tvColorTemp_COLD, int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_G_post_offset() -   Retrieve current TV ColorTemp G_post_offset with invalid input |  tvColorTemp_COLD, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_G_post_offset() -   Retrieve current TV ColorTemp G_post_offset with lower ranget |  -1 , int * | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_G_post_offset() -   Retrieve current TV ColorTemp G_post_offset with max range |  tvColorTemp_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
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
* | 01 | call SetColorTemp_B_post_offset() - Set the TV ColorTemp B_post_offset even before tvInit() | tvColorTemp_STANDARD, 104 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_B_post_offset() -   Set the TV ColorTemp B_post_offset with lower range | tvColorTemp_WARM, -1025 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_B_post_offset() -   Set the TV ColorTemp B_post_offset with max range | tvColorTemp_COLD, 1025 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_B_post_offset() -   Set the TV ColorTemp B_post_offset with lower range | -1, 500 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_B_post_offset() -   Set the TV ColorTemp B_post_offset with max range | tvColorTemp_MAX, 500 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_B_post_offset() -  Set the TV ColorTemp B_post_offset with valid input after tvTerm() | tvColorTemp_STANDARD, 10 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_B_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_B_post_offset() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_B_post_offset() -  Retrieve the current ColorTemp B_post_offset with valid arguments | tvColorTemp_WARM, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_B_post_offset() -  Retrieve the current ColorTemp B_post_offset with valid arguments and validate with above value | tvColorTemp_WARM, int * | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_B_post_offset() -  Retrieve the current ColorTemp B_post_offset with valid arguments | tvColorTemp_STANDARD, int * | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_B_post_offset() -  Retrieve the current ColorTemp B_post_offset with valid arguments and validate with above value | tvColorTemp_STANDARD, int * | tvERROR_NONE | Should Pass |
* | 06 | call GetColorTemp_B_post_offset() -  Retrieve the current ColorTemp B_post_offset with valid arguments | tvColorTemp_COLD, int * | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_B_post_offset() -  Retrieve the current ColorTemp B_post_offset with valid arguments and validate with above value | tvColorTemp_COLD, int * | tvERROR_NONE | Should Pass |
* | 07 | call GetColorTemp_B_post_offset() -  Retrieve the current ColorTemp B_post_offset with valid arguments | tvColorTemp_USER, int * | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_B_post_offset() -  Retrieve the current ColorTemp B_post_offset with valid arguments and validate with above value | tvColorTemp_USER, int * | tvERROR_NONE | Should Pass |
* | 08 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_B_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_B_post_offset() for all negative invocation scenarios
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
* | 01 | call GetColorTemp_B_post_offset() -  Retrieve current TV ColorTemp B_post_offset even before tvInit() |  tvColorTemp_COLD, int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_B_post_offset() -   Retrieve current TV ColorTemp B_post_offset with invalid arguments |  tvColorTemp_COLD, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_B_post_offset() -   Retrieve current TV ColorTemp B_post_offset with lower range |  -1, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_B_post_offset() -   Retrieve current TV ColorTemp B_post_offset with max range |  tvColorTemp_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value | tvColorTemp_STANDARD, 0, HDMI_OFFSET_NEW, 0| tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Rgain_onSource() -  Reset the ColorTemp Rgain_onSource with another valid value | tvColorTemp_COLD, 2047, TV_OFFSET_NEW, 0 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Rgain_onSource() -  Reset the ColorTemp Rgain_onSource with another valid value | tvColorTemp_WARM, 0, AV_OFFSET_NEW, 0 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Rgain_onSource() -  Reset the ColorTemp Rgain_onSource with another valid value | tvColorTemp_STANDARD, 2047, HDMI_OFFSET_NEW, 1 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Rgain_onSource() -  Reset the ColorTemp Rgain_onSource with another valid value | tvColorTemp_COLD, 250, TV_OFFSET_NEW, 1 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Rgain_onSource() -  Reset the ColorTemp Rgain_onSource with another valid value | tvColorTemp_WARM, 750, AV_OFFSET_NEW, 1 | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetColorTemp_Rgain_onSource() - Set the TV ColorTemp Rgain_onSource even before tvInit() | tvColorTemp_STANDARD, 0, HDMI_OFFSET_NEW, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource with invalid input | tvColorTemp_MAX, 0, HDMI_OFFSET_NEW, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource with invalid input | tvColorTemp_WARM, -1, HDMI_OFFSET_NEW, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource with invalid input | tvColorTemp_WARM, 2048, HDMI_OFFSET_NEW, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource with invalid input | tvColorTemp_WARM, 0, MAX_OFFSET_NEW, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource with invalid input | tvColorTemp_WARM, 0, TV_OFFSET_NEW, 2 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 09 | call SetColorTemp_Rgain_onSource() -  Set the TV ColorTemp Rgain_onSource with valid input after tvTerm() | tvColorTemp_WARM, 2047, AV_OFFSET_NEW, 1 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_Rgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Rgain_onSource() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_Rgain_onSource() -  Retrieve the current ColorTemp Rgain_onSource with valid arguments | tvColorTemp_STANDARD, int *, HDMI_OFFSET_NEW | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Rgain_onSource() -  Retrieve the current ColorTemp Rgain_onSource with valid arguments and validate with above value | tvColorTemp_WARM, int *, TV_OFFSET_NEW | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_Rgain_onSource() -  Retrieve the current ColorTemp Rgain_onSource with valid arguments and validate with above value | tvColorTemp_COLD, int *, AV_OFFSET_NEW | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_Rgain_onSource() -  Retrieve the current ColorTemp Rgain_onSource with valid arguments and validate with above value | tvColorTemp_USER, int *, AV_OFFSET_NEW | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call GetColorTemp_Rgain_onSource() -  Retrieve current TV ColorTemp Rgain_onSource even before tvInit() | tvColorTemp_STANDARD, int *, HDMI_OFFSET_NEW  | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource with invalid input |  tvColorTemp_MAX, int *, HDMI_OFFSET_NEW | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource with invalid input | tvColorTemp_WARM, NULL, HDMI_OFFSET_NEW | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource with invalid input | tvColorTemp_COLD, int *, 3 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call GetColorTemp_Rgain_onSource() -  Retrieve current TV ColorTemp Rgain_onSource valid arguments | tvColorTemp_WARM, int *, TV_OFFSET_NEW  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetColorTemp_Rgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Ggain_onSource() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value | tvColorTemp_STANDARD, 0, HDMI_OFFSET_NEW, 0| tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Ggain_onSource() -  Reset the ColorTemp Ggain_onSource with another valid value | tvColorTemp_COLD, 2047, TV_OFFSET_NEW, 0 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Ggain_onSource() -  Reset the ColorTemp Ggain_onSource with another valid value | tvColorTemp_WARM, 0, AV_OFFSET_NEW, 0 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_Ggain_onSource() -  Reset the ColorTemp Ggain_onSource with another valid value | tvColorTemp_STANDARD, 2047, HDMI_OFFSET_NEW, 1 | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_Ggain_onSource() -  Reset the ColorTemp Ggain_onSource with another valid value | tvColorTemp_COLD, 0, TV_OFFSET_NEW, 1 | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_Ggain_onSource() -  Reset the ColorTemp Ggain_onSource with another valid value | tvColorTemp_WARM, 2047, AV_OFFSET_NEW, 1 | tvERROR_NONE | Should Pass |
* | 08 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetColorTemp_Ggain_onSource() - Set the TV ColorTemp Ggain_onSource even before tvInit() | tvColorTemp_STANDARD, 0, HDMI_OFFSET_NEW, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource with invalid input | tvColorTemp_MAX, 0, HDMI_OFFSET_NEW, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource with invalid input | tvColorTemp_WARM, -1, HDMI_OFFSET_NEW, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource with invalid input | tvColorTemp_WARM, 2048, HDMI_OFFSET_NEW, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource with invalid input | tvColorTemp_WARM, 0, MAX_OFFSET_NEW, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource with invalid input | tvColorTemp_WARM, 0, TV_OFFSET_NEW, 2 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 09 | call SetColorTemp_Ggain_onSource() -  Set the TV ColorTemp Ggain_onSource with valid input after tvTerm() | tvColorTemp_WARM, 2047, AV_OFFSET_NEW, 1 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_Ggain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Ggain_onSource() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_Ggain_onSource() -  Retrieve the current ColorTemp Ggain_onSource with valid arguments | tvColorTemp_STANDARD, int *, HDMI_OFFSET_NEW | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Ggain_onSource() -  Retrieve the current ColorTemp Ggain_onSource with valid arguments and validate with above value | tvColorTemp_WARM, int *, TV_OFFSET_NEW | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_Ggain_onSource() -  Retrieve the current ColorTemp Ggain_onSource with valid arguments and validate with above value | tvColorTemp_COLD, int *, AV_OFFSET_NEW | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_Ggain_onSource() -  Retrieve the current ColorTemp G gain_onSource with valid arguments and validate with above value | tvColorTemp_USER, int *, AV_OFFSET_NEW | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call GetColorTemp_Ggain_onSource() -  Retrieve current TV ColorTemp Ggain_onSource even before tvInit() | tvColorTemp_STANDARD, int *, HDMI_OFFSET_NEW  | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource with invalid input |  tvColorTemp_MAX, int *, HDMI_OFFSET_NEW | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource with invalid input | tvColorTemp_WARM, NULL, HDMI_OFFSET_NEW | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource with invalid input | tvColorTemp_COLD, int *, MAX_OFFSET_NEW | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call GetColorTemp_Ggain_onSource() -  Retrieve current TV ColorTemp Ggain_onSource valid arguments | tvColorTemp_WARM, int *, TV_OFFSET_NEW  | tvERROR_INVALID_STATE | Should Pass |
*/

void test_l1_tvSettings_negative_GetColorTemp_Ggain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_Bgain_onSource() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value | tvColorTemp_STANDARD, 0, HDMI_OFFSET_NEW, 0| tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Bgain_onSource() -  Reset the ColorTemp Bgain_onSource with another valid value | tvColorTemp_COLD, 2047, TV_OFFSET_NEW, 0 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Bgain_onSource() -  Reset the ColorTemp Bgain_onSource with another valid value | tvColorTemp_WARM, 0, AV_OFFSET_NEW, 0 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_Bgain_onSource() -  Reset the ColorTemp Bgain_onSource with another valid value | tvColorTemp_STANDARD, 2047, HDMI_OFFSET_NEW, 1 | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_Bgain_onSource() -  Reset the ColorTemp Bgain_onSource with another valid value | tvColorTemp_COLD, 0, TV_OFFSET_NEW, 1 | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_Bgain_onSource() -  Reset the ColorTemp Bgain_onSource with another valid value | tvColorTemp_WARM, 2047, AV_OFFSET_NEW, 1 | tvERROR_NONE | Should Pass |
* | 08 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetColorTemp_Bgain_onSource() - Set the TV ColorTemp Bgain_onSource even before tvInit() | tvColorTemp_STANDARD, 0, HDMI_OFFSET_NEW, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource with invalid input | tvColorTemp_MAX, 0, HDMI_OFFSET_NEW, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource with invalid input | tvColorTemp_WARM, -1, HDMI_OFFSET_NEW, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource with invalid input | tvColorTemp_WARM, 2048, HDMI_OFFSET_NEW, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource with invalid input | tvColorTemp_WARM, 0, MAX_OFFSET_NEW, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource with invalid input | tvColorTemp_WARM, 0, TV_OFFSET_NEW, 2 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 09 | call SetColorTemp_Bgain_onSource() -  Set the TV ColorTemp Bgain_onSource with valid input after tvTerm() | tvColorTemp_WARM, 2047, AV_OFFSET_NEW, 1 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_Bgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_Bgain_onSource() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_Bgain_onSource() -  Retrieve the current ColorTemp Bgain_onSource with valid arguments | tvColorTemp_STANDARD, int *, HDMI_OFFSET_NEW | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Bgain_onSource() -  Retrieve the current ColorTemp Bgain_onSource with valid arguments and validate with above value | tvColorTemp_WARM, int *, TV_OFFSET_NEW | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_Bgain_onSource() -  Retrieve the current ColorTemp Bgain_onSource with valid arguments and validate with above value | tvColorTemp_COLD, int *, AV_OFFSET_NEW | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_Bgain_onSource() -  Retrieve the current ColorTemp Bgain_onSource with valid arguments and validate with above value | tvColorTemp_USER, int *, AV_OFFSET_NEW | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call GetColorTemp_Bgain_onSource() -  Retrieve current TV ColorTemp Bgain_onSource even before tvInit() | tvColorTemp_STANDARD, int *, HDMI_OFFSET_NEW  | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource with invalid input |  tvColorTemp_MAX, int *, HDMI_OFFSET_NEW | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource with invalid input | tvColorTemp_WARM, NULL, HDMI_OFFSET_NEW | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource with invalid input | tvColorTemp_COLD, int *, MAX_OFFSET_NEW | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call GetColorTemp_Bgain_onSource() -  Retrieve current TV ColorTemp Bgain_onSource valid arguments | tvColorTemp_WARM, int *, TV_OFFSET_NEW  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetColorTemp_Bgain_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_R_post_offset_onSource() for all positive invocation scenarios
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 99@n
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
* | 01 | call tvInit() -   Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value | tvColorTemp_STANDARD, -1024, HDMI_OFFSET_NEW, 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_R_post_offset_onSource() -  Reset the ColorTemp R_post_offset_onSource with another valid value | tvColorTemp_COLD, 1024, TV_OFFSET_NEW, 1 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_R_post_offset_onSource() -  Reset the ColorTemp R_post_offset_onSource with another valid value | tvColorTemp_WARM, -1024, AV_OFFSET_NEW, 0 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_R_post_offset_onSource() -  Reset the ColorTemp R_post_offset_onSource with another valid value | tvColorTemp_USER, 1024, HDMI_OFFSET_NEW, 1 | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_R_post_offset_onSource() -  Reset the ColorTemp R_post_offset_onSource with another valid value | tvColorTemp_STANDARD, 0, TV_OFFSET_NEW, 0 | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_R_post_offset_onSource() -  Reset the ColorTemp R_post_offset_onSource with another valid value | tvColorTemp_COLD, 500, AV_OFFSET_NEW, 1 | tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_R_post_offset_onSource() -  Reset the ColorTemp R_post_offset_onSource with another valid value | tvColorTemp_WARM, 100, TV_OFFSET_NEW, 0 | tvERROR_NONE | Should Pass |
* | 09 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* **Test Case ID:** 100@n
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
* | 01 | call SetColorTemp_R_post_offset_onSource() - Set the TV ColorTemp R_post_offset_onSource even before tvInit() | tvColorTemp_STANDARD, -1024, HDMI_OFFSET_NEW, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource with invalid input | tvColorTemp_MAX, -1025, HDMI_OFFSET_NEW, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource with invalid input | tvColorTemp_COLD, 0, TV_OFFSET_NEW, 5 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource with invalid input | tvColorTemp_STANDARD, 100, MAX_OFFSET_NEW, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_R_post_offset_onSource() -  Set the TV ColorTemp R_post_offset_onSource with valid input after tvTerm() | tvColorTemp_WARM, 1024, HDMI_OFFSET_NEW, 1 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_R_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_R_post_offset_onSource() for all positive invocation scenarios
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 101@n
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_R_post_offset_onSource() -  Retrieve the current ColorTemp R_post_offset_onSource with valid arguments | tvColorTemp_STANDARD, int *, HDMI_OFFSET_NEW| tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_R_post_offset_onSource() -  Retrieve the current ColorTemp R_post_offset_onSource with valid arguments and validate with above value | tvColorTemp_COLD, int *, HDMI_OFFSET_NEW | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_R_post_offset_onSource() -  Retrieve the current ColorTemp R_post_offset_onSource with valid arguments and validate with above value | tvColorTemp_WARM, int *, TV_OFFSET_NEW | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_R_post_offset_onSource() -  Retrieve the current ColorTemp R_post_offset_onSource with valid arguments and validate with above value | tvColorTemp_STANDARD, int *, TV_OFFSET_NEW | tvERROR_NONE | Should Pass |
* | 06 | call GetColorTemp_R_post_offset_onSource() -  Retrieve the current ColorTemp R_post_offset_onSource with valid arguments and validate with above value | tvColorTemp_COLD, int *, AV_OFFSET_NEW | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_R_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_R_post_offset_onSource() for all negative invocation scenarios
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
* | 01 | call GetColorTemp_R_post_offset_onSource() -  Retrieve current TV ColorTemp R_post_offset_onSource even before tvInit() | tvColorTemp_STANDARD, int *, HDMI_OFFSET_NEW | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_R_post_offset_onSource() -  Retrieve current TV ColorTemp R_post_offset_onSource with invalid input | tvColorTemp_STANDARD, NULL, HDMI_OFFSET_NEW | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_R_post_offset_onSource() -  Retrieve current TV ColorTemp R_post_offset_onSource with invalid input | tvColorTemp_MAX, int *, HDMI_OFFSET_NEW | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_R_post_offset_onSource() -  Retrieve current TV ColorTemp R_post_offset_onSource with invalid input | tvColorTemp_STANDARD, int *, MAX_OFFSET_NEW | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call GetColorTemp_R_post_offset_onSource() -  Retrieve current TV ColorTemp R_post_offset_onSource valid arguments | tvColorTemp_COLD, int *, HDMI_OFFSET_NEW | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetColorTemp_R_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_G_post_offset_onSource() for all positive invocation scenarios
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
* | 01 | call tvInit() -   Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value | tvColorTemp_STANDARD, -1024, HDMI_OFFSET_NEW, 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_G_post_offset_onSource() -  Reset the ColorTemp G_post_offset_onSource with another valid value | tvColorTemp_COLD, 1024, TV_OFFSET_NEW, 1 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_G_post_offset_onSource() -  Reset the ColorTemp G_post_offset_onSource with another valid value | tvColorTemp_WARM, -1024, AV_OFFSET_NEW, 0 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_G_post_offset_onSource() -  Reset the ColorTemp G_post_offset_onSource with another valid value | tvColorTemp_USER, 1024, HDMI_OFFSET_NEW, 1 | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_G_post_offset_onSource() -  Reset the ColorTemp G_post_offset_onSource with another valid value | tvColorTemp_STANDARD, 0, TV_OFFSET_NEW, 0 | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_G_post_offset_onSource() -  Reset the ColorTemp G_post_offset_onSource with another valid value | tvColorTemp_COLD, 500, AV_OFFSET_NEW, 1 | tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_G_post_offset_onSource() -  Reset the ColorTemp G_post_offset_onSource with another valid value | tvColorTemp_WARM, 1000, TV_OFFSET_NEW, 0 | tvERROR_NONE | Should Pass |
* | 09 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetColorTemp_G_post_offset_onSource() - Set the TV ColorTemp G_post_offset_onSource even before tvInit() | tvColorTemp_STANDARD, -1024, HDMI_OFFSET_NEW, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource with invalid input | tvColorTemp_MAX, 0, HDMI_OFFSET_NEW, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource with invalid input | tvColorTemp_COLD, -1025, TV_OFFSET_NEW, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource with invalid input | tvColorTemp_COLD, 1025, TV_OFFSET_NEW, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource with invalid input | tvColorTemp_STANDARD, 100, MAX_OFFSET_NEW, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_G_post_offset_onSource() -  Set the TV ColorTemp G_post_offset_onSource with valid input after tvTerm() | tvColorTemp_WARM, 1024, HDMI_OFFSET_NEW, 1 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_G_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_G_post_offset_onSource() for all positive invocation scenarios
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 105@n
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_G_post_offset_onSource() -  Retrieve the current ColorTemp G_post_offset_onSource with valid arguments | tvColorTemp_STANDARD, int *, HDMI_OFFSET_NEW| tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_G_post_offset_onSource() -  Retrieve the current ColorTemp G_post_offset_onSource with valid arguments and validate with above value | tvColorTemp_COLD, int *, HDMI_OFFSET_NEW | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_G_post_offset_onSource() -  Retrieve the current ColorTemp G_post_offset_onSource with valid arguments and validate with above value | tvColorTemp_WARM, int *, TV_OFFSET_NEW | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_G_post_offset_onSource() -  Retrieve the current ColorTemp G_post_offset_onSource with valid arguments and validate with above value | tvColorTemp_STANDARD, int *, TV_OFFSET_NEW | tvERROR_NONE | Should Pass |
* | 06 | call GetColorTemp_G_post_offset_onSource() -  Retrieve the current ColorTemp G_post_offset_onSource with valid arguments and validate with above value | tvColorTemp_COLD, int *, AV_OFFSET_NEW | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetColorTemp_G_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_G_post_offset_onSource() for all negative invocation scenarios
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
* | 01 | call GetColorTemp_G_post_offset_onSource() -  Retrieve current TV ColorTemp G_post_offset_onSource even before tvInit() | tvColorTemp_STANDARD, int *, HDMI_OFFSET_NEW | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_G_post_offset_onSource() -  Retrieve current TV ColorTemp G_post_offset_onSource with invalid input | tvColorTemp_STANDARD, NULL, HDMI_OFFSET_NEW | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_G_post_offset_onSource() -  Retrieve current TV ColorTemp G_post_offset_onSource with invalid input | tvColorTemp_MAX, int *, HDMI_OFFSET_NEW | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_G_post_offset_onSource() -  Retrieve current TV ColorTemp G_post_offset_onSource with invalid input | tvColorTemp_STANDARD, int *, MAX_OFFSET_NEW| tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call GetColorTemp_G_post_offset_onSource() -  Retrieve current TV ColorTemp G_post_offset_onSource valid arguments | tvColorTemp_COLD, int *, HDMI_OFFSET_NEW | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetColorTemp_G_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemp_B_post_offset_onSource() for all positive invocation scenarios
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
* | 01 | call tvInit() -   Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value | tvColorTemp_STANDARD, -1024, HDMI_OFFSET_NEW, 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_B_post_offset_onSource() -  Reset the ColorTemp B_post_offset_onSource with another valid value | tvColorTemp_COLD, 1024, TV_OFFSET_NEW, 1 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_B_post_offset_onSource() -  Reset the ColorTemp B_post_offset_onSource with another valid value | tvColorTemp_WARM, -1024, AV_OFFSET_NEW, 0 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_B_post_offset_onSource() -  Reset the ColorTemp B_post_offset_onSource with another valid value | tvColorTemp_USER, 1024, HDMI_OFFSET_NEW, 1 | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_B_post_offset_onSource() -  Reset the ColorTemp B_post_offset_onSource with another valid value | tvColorTemp_STANDARD, 0, TV_OFFSET_NEW, 0 | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_B_post_offset_onSource() -  Reset the ColorTemp B_post_offset_onSource with another valid value | tvColorTemp_COLD, 500, AV_OFFSET_NEW, 1 | tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_B_post_offset_onSource() -  Reset the ColorTemp B_post_offset_onSource with another valid value | tvColorTemp_WARM, 1000, TV_OFFSET_NEW, 0 | tvERROR_NONE | Should Pass |
* | 09 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetColorTemp_B_post_offset_onSource() - Set the TV ColorTemp B_post_offset_onSource even before tvInit() | tvColorTemp_STANDARD, -1024, HDMI_OFFSET_NEW, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource with invalid input | tvColorTemp_MAX, -1025, HDMI_OFFSET_NEW, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource with invalid input | tvColorTemp_COLD, 0, TV_OFFSET_NEW, 5 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource with invalid input | tvColorTemp_STANDARD, 100, MAX_OFFSET_NEW, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_B_post_offset_onSource() -  Set the TV ColorTemp B_post_offset_onSource with valid input after tvTerm() | tvColorTemp_WARM, 1024, HDMI_OFFSET_NEW, 1 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_B_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetColorTemp_B_post_offset_onSource() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_B_post_offset_onSource() -  Retrieve the current ColorTemp B_post_offset_onSource with valid arguments | tvColorTemp_STANDARD, int *, HDMI_OFFSET_NEW| tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_B_post_offset_onSource() -  Retrieve the current ColorTemp B_post_offset_onSource with valid arguments and validate with above value | tvColorTemp_COLD, int *, HDMI_OFFSET_NEW | tvERROR_NONE | Should Pass |
* | 04 | call GetColorTemp_B_post_offset_onSource() -  Retrieve the current ColorTemp B_post_offset_onSource with valid arguments and validate with above value | tvColorTemp_WARM, int *, TV_OFFSET_NEW | tvERROR_NONE | Should Pass |
* | 05 | call GetColorTemp_B_post_offset_onSource() -  Retrieve the current ColorTemp B_post_offset_onSource with valid arguments and validate with above value | tvColorTemp_STANDARD, int *, TV_OFFSET_NEW | tvERROR_NONE | Should Pass |
* | 06 | call GetColorTemp_B_post_offset_onSource() -  Retrieve the current ColorTemp B_post_offset_onSource with valid arguments and validate with above value | tvColorTemp_COLD, int *, AV_OFFSET_NEW | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call GetColorTemp_B_post_offset_onSource() -  Retrieve current TV ColorTemp B_post_offset_onSource even before tvInit() | tvColorTemp_STANDARD, int *, HDMI_OFFSET_NEW | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_B_post_offset_onSource() -  Retrieve current TV ColorTemp B_post_offset_onSource with invalid input | tvColorTemp_STANDARD, NULL, HDMI_OFFSET_NEW | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_B_post_offset_onSource() -  Retrieve current TV ColorTemp B_post_offset_onSource with invalid input | tvColorTemp_MAX, int *, HDMI_OFFSET_NEW | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_B_post_offset_onSource() -  Retrieve current TV ColorTemp B_post_offset_onSource with invalid input | tvColorTemp_STANDARD, int *, MAX_OFFSET_NEW | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call GetColorTemp_B_post_offset_onSource() -  Retrieve current TV ColorTemp B_post_offset_onSource valid arguments | tvColorTemp_COLD, int *, HDMI_OFFSET_NEW | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetColorTemp_B_post_offset_onSource (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVSupportedPictureModes() for all positive invocation scenarios
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
* | 01 | call GetTVSupportedPictureModes() -  Retrieve current TV Supported PictureModes even before tvInit() | pic_modes_t *, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetTVSupportedPictureModes() -  Retrieve current TV Supported PictureModes valid arguments | pic_modes_t *, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetTVSupportedPictureModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVSupportedDVModes() for all positive invocation scenarios
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
* | 01 | call GetTVSupportedDVModes() -  Retrieve current TV Supported DVModes even before tvInit() | pic_modes_t *, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetTVSupportedDVModes() -  Retrieve current TV Supported DVModes valid arguments | pic_modes_t *, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetTVSupportedDVModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetTVDolbyVisionMode() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetTVDolbyVisionMode() -  Set the TV DolbyVision Mode with valid value | "bright" | tvERROR_NONE | Should Pass |
* | 03 | call SetTVDolbyVisionMode() -  Reset the  TV DolbyVision Mode with another valid value | "dark" | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetTVDolbyVisionMode() - Set the TV DolbyVision Mode even before tvInit() | "bright" | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetTVDolbyVisionMode() -   Set the TV DolbyVision Mode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetTVDolbyVisionMode() -   Set the TV DolbyVision Mode with invalid input | "" | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetTVDolbyVisionMode() -   Set the TV DolbyVision Mode with invalid input | "invalid" | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call SetTVDolbyVisionMode() -  Set the TV DolbyVision Mode with valid input after tvTerm() | "dark" | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetTVDolbyVisionMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVDolbyVisionMode() for all positive invocation scenarios
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
* | 01 | call GetTVDolbyVisionMode() -  Retrieve current TV DolbyVision Mode even before tvInit() | char * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetTVDolbyVisionMode() -  Retrieve current TV DolbyVision Mode valid arguments | char * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetTVDolbyVisionMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetTVHLGMode() for all positive invocation scenarios
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
* | 01 | call SetTVHLGMode() - Set the TV HLG Mode even before tvInit() | "bright" | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetTVHLGMode() -   Set the TV HLG Mode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetTVHLGMode() -   Set the TV HLG Mode with invalid input | "" | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetTVHLGMode() -   Set the TV HLG Mode with invalid input | "invalid" | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call SetTVHLGMode() -  Set the TV HLG Mode with valid input after tvTerm() | "dark" | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetTVHLGMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetTVHDR10Mode() for all positive invocation scenarios
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
* | 01 | call SetTVHDR10Mode() - Set the TV HDR10 Mode even before tvInit() | "bright" | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetTVHDR10Mode() -   Set the TV HDR10 Mode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetTVHDR10Mode() -   Set the TV HDR10 Mode with invalid input | "" | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetTVHDR10Mode() -   Set the TV HDR10 Mode with invalid input | "invalid" | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call SetTVHDR10Mode() -  Set the TV HDR10 Mode with valid input after tvTerm() | "dark" | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetTVHDR10Mode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVSupportedHLGModes() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetTVSupportedHLGModes() -  Retrieve the current TV Supported HLG Modes with valid arguments | pic_modes_t *, unsigned short * | tvERROR_NONE | Should Pass |
* | 03 | call GetTVSupportedHLGModes() -  Retrieve the current TV Supported HLG Modes with valid arguments and validate with above value | pic_modes_t *, unsigned short * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call GetTVSupportedHLGModes() -  Retrieve current TV Supported HLG Modes even before tvInit() | pic_modes_t *, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetTVSupportedHLGModes() -  Retrieve current TV Supported HLG Modes valid arguments | pic_modes_t *, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetTVSupportedHLGModes (void)
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetTVSupportedHDR10Modes() -  Retrieve the current TV Supported HDR10 Mode with valid arguments | pic_modes_t *, unsigned short * | tvERROR_NONE | Should Pass |
* | 03 | call GetTVSupportedHDR10Modes() -  Retrieve the current TV Supported HDR10 Mode with valid arguments and validate with above value | pic_modes_t *, unsigned short * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call GetTVSupportedHDR10Modes() -  Retrieve current TV Supported HDR10 Mode even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetTVSupportedHDR10Modes() -   Retrieve current TV Supported HDR10 Mode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetTVSupportedHDR10Modes() -  Retrieve current TV Supported HDR10 Mode with valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetTVSupportedHDR10Modes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetDynamicContrast() for all positive invocation scenarios
*
* **Test Group ID:** Basic : 01@n
* **Test Case ID:** 127@n
* 
* **Pre-Conditions:** None@n
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* * **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetDynamicContrast() -  Set the Dynamic Contrast with valid value | true | tvERROR_NONE | Should Pass |
* | 03 | call SetDynamicContrast() -  Reset the Dynamic Contrast with another valid value | false| tvERROR_NONE | Should Pass |
* | 04 | call SetDynamicContrast() -  Reset the Dynamic Contrast with another valid value | true | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetDynamicContrast() - Set the TV Dynamic Contrast even before tvInit() | true | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call SetDynamicContrast() -  Set the TV Dynamic Contrast with valid input after tvTerm() | false | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetDynamicContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetDynamicContrast() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetDynamicContrast() -  Retrieve the current Dynamic Contrast with valid arguments | bool * | tvERROR_NONE | Should Pass |
* | 03 | call GetDynamicContrast() -  Retrieve the current Dynamic Contrast with valid arguments and validate with above value | bool * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call GetDynamicContrast() -  Retrieve current TV Dynamic Contrast even before tvInit() | bool * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetDynamicContrast() -  Retrieve current TV Dynamic Contrast valid arguments | bool * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetDynamicContrast (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate setWBctrl() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call setWBctrl() -  Set the WBctrl with valid value | "HDMI", "normal", "red", "gain", 10 | tvERROR_NONE | Should Pass |
* | 03 | call setWBctrl() -  Reset the WBctrl with valid value | "HDMI", "cool", "blue", "gain", 1024 | tvERROR_NONE | Should Pass |
* | 04 | call setWBctrl() -  Reset the WBctrl with valid value | "HDMI", "warm", "green", "gain", 2047 | tvERROR_NONE | Should Pass |
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
* | 01 | call setWBctrl() - Set the TV WBctrl even before tvInit() | "HDMI", "normal", "red", "gain", 10 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call setWBctrl() -  Set the TV WBctrl with valid input after tvTerm() | "HDMI", tvColorTemp_STANDARD, "red", "gain", 1024 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_setWBctrl (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate getWBctrl() for all positive invocation scenarios
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
* | 01 | call getWBctrl() -  Retrieve current TV WBctrl even before tvInit() | "HDMI", "normal", "red", "gain", int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call getWBctrl() -  Retrieve current TV WBctrl valid arguments | "HDMI", "normal", "red", "gain", int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_getWBctrl (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate enableWBmode() for all positive invocation scenarios
*
* @note tvERROR_GENERAL is platform specific and cannot be simulated
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
* | 01 | call enableWBmode() - enable the TV brightness even before tvInit() | true | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call enableWBmode() -  enable the TV brightness with valid input after tvTerm() | false | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_enableWBmode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/** 
* @brief Validate GetSupportedComponentColor() for all positive invocation scenarios
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
* | 01 | call GetSupportedComponentColor() -  Retrieve current TV Supported ComponentColor even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetSupportedComponentColor() -  Retrieve current TV Supported ComponentColor valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetSupportedComponentColor (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetCurrentComponentSaturation() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetCurrentComponentSaturation() -  Set the Current Component Saturation with valid value | tvDataColor_RED,  00| tvERROR_NONE | Should Pass |
* | 03 | call SetCurrentComponentSaturation() -  Reset the Current Component Saturation with another valid value | tvDataColor_GREEN,  100 | tvERROR_NONE | Should Pass |
* | 04 | call SetCurrentComponentSaturation() -  Reset the Current Component Saturation with another valid value | tvDataColor_BLUE,  00 | tvERROR_NONE | Should Pass |
* | 05 | call SetCurrentComponentSaturation() -  Reset the Current Component Saturation with another valid value | tvDataColor_YELLOW,  100 | tvERROR_NONE | Should Pass |
* | 06 | call SetCurrentComponentSaturation() -  Reset the Current Component Saturation with another valid value | tvDataColor_CYAN,  50 | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetCurrentComponentSaturation() - Set the TV Current Component Saturation even before tvInit() | tvDataColor_CYAN,  0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetCurrentComponentSaturation() -   Set the TV Current Component Saturation with invalid input | tvDataColor_GREEN,  101 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetCurrentComponentSaturation() -   Set the TV Current Component Saturation with invalid input | tvDataColor_GREEN,  -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetCurrentComponentSaturation() -   Set the TV Current Component Saturation with invalid input | tvDataColor_MAX, 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call SetCurrentComponentSaturation() -  Set the TV Current Component Saturation with valid input after tvTerm() | tvDataColor_GREEN,  0 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetCurrentComponentSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentComponentSaturation() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetCurrentComponentSaturation() -  Retrieve the current Component Saturation with valid arguments | tvDataColor_GREEN, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetCurrentComponentSaturation() -  Retrieve the current Component Saturation with valid arguments and validate with above value |tvDataColor_GREEN, int * | tvERROR_NONE | Should Pass |
* | 04 | call GetCurrentComponentSaturation() -  Retrieve the current Component Saturation with valid arguments and validate with above value |tvDataColor_RED, int * | tvERROR_NONE | Should Pass |
* | 05 | call GetCurrentComponentSaturation() -  Retrieve the current Component Saturation with valid arguments and validate with above value |tvDataColor_CYAN, int * | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetCurrentComponentSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentComponentSaturation() for all negative invocation scenarios
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
* | 01 | call GetCurrentComponentSaturation() -  Retrieve current TV Component Saturation even before tvInit() | tvDataColor_CYAN, int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetCurrentComponentSaturation() -  Retrieve current TV Component Saturation valid arguments | tvDataColor_RED, int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetCurrentComponentSaturation (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetCurrentComponentHue() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetCurrentComponentHue() -  Retrieve the Current Component Hue with valid arguments | tvDataColor_RED, 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetCurrentComponentHue() -  Retrieve the Current Component Hue with valid arguments and validate with above value | tvDataColor_RED , 0 | tvERROR_NONE | Should Pass |
* | 04 | call SetCurrentComponentHue() -  Retrieve the Current Component Hue with valid arguments | tvDataColor_RED, 100 | tvERROR_NONE | Should Pass |
* | 05 | call SetCurrentComponentHue() -  Retrieve the Current Component Hue with valid arguments and validate with above value | tvDataColor_RED , 100 | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetCurrentComponentHue() -  Retrieve current TV Current Component Hue even before tvInit() | tvDataColor_RED, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetCurrentComponentHue() -   Retrieve current TV Current Component Hue with invalid input | tvDataColor_RED, 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetCurrentComponentHue() -   Retrieve current TV Current Component Hue with invalid input | tvDataColor_RED, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetCurrentComponentHue() -   Retrieve current TV Current Component Hue with invalid input | tvDataColor_MAX, 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call SetCurrentComponentHue() -  Retrieve current TV Current Component Hue valid arguments | tvDataColor_RED, 0 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetCurrentComponentHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentComponentHue() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetCurrentComponentHue() -  Retrieve the current Current Component Hue with valid arguments | tvDataColor_RED, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetCurrentComponentHue() -  Retrieve the current Current Component Hue with valid arguments and validate with above value |tvDataColor_RED, int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetCurrentComponentHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentComponentHue() for all negative invocation scenarios
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
* | 01 | call GetCurrentComponentHue() -  Retrieve current TV brightness even before tvInit() |tvDataColor_RED, int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetCurrentComponentHue() -  Retrieve current TV brightness valid arguments | tvDataColor_RED, int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetCurrentComponentHue (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetCurrentComponentLuma() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetCurrentComponentLuma() -  Retrieve the Current Component Luma with valid arguments | tvDataColor_RED, 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetCurrentComponentLuma() -  Retrieve the Current Component Luma with valid arguments and validate with above value | tvDataColor_RED, 0 | tvERROR_NONE | Should Pass |
* | 04 | call SetCurrentComponentLuma() -  Retrieve the Current Component Luma with valid arguments | tvDataColor_RED, 30 | tvERROR_NONE | Should Pass |
* | 05 | call SetCurrentComponentLuma() -  Retrieve the Current Component Luma with valid arguments and validate with above value | tvDataColor_RED, 30 | tvERROR_NONE | Should Pass |
* | 06 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetCurrentComponentLuma() -  Retrieve Current Component Luma even before tvInit() | tvDataColor_RED, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetCurrentComponentLuma() -   Retrieve Current Component Luma with invalid input | tvDataColor_RED, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetCurrentComponentLuma() -   Retrieve Current Component Luma with invalid input | tvDataColor_RED, 31 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetCurrentComponentLuma() -   Retrieve Current Component Luma with invalid input | tvDataColor_MAX, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call SetCurrentComponentLuma() -  Retrieve Current Component Luma valid arguments | tvDataColor_RED, 0 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetCurrentComponentLuma (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentComponentLuma() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetCurrentComponentLuma() -  Retrieve the current Component Luma with valid arguments | tvDataColor_RED, int * | tvERROR_NONE | Should Pass |
* | 03 | call GetCurrentComponentLuma() -  Retrieve the current Component Luma with valid arguments and validate with above value | tvDataColor_RED, int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetCurrentComponentLuma (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentComponentLuma() for all negative invocation scenarios
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
* | 01 | call GetCurrentComponentLuma() -  Retrieve current TV Current Component Luma even before tvInit() | tvDataColor_RED, int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetCurrentComponentLuma() -  Retrieve current TV Current Component Luma valid arguments | tvDataColor_RED, int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetCurrentComponentLuma (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVSupportedDimmingModes() for all positive invocation scenarios
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
* | 01 | call GetTVSupportedDimmingModes() -  Retrieve current TV Supported DimmingModes even before tvInit() | char **, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetTVSupportedDimmingModes() -  Retrieve current TV Supported DimmingModes valid arguments | char **, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetTVSupportedDimmingModes (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetTVDimmingMode() for all positive invocation scenarios
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
* | 01 | call SetTVDimmingMode() -  Retrieve current TV Dimming Mode even before tvInit() | "local" | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetTVDimmingMode() -   Retrieve current TV Dimming Mode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetTVDimmingMode() -   Retrieve current TV Dimming Mode with invalid input | "" | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetTVDimmingMode() -   Retrieve current TV Dimming Mode with invalid input | "invalid" | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call SetTVDimmingMode() -  Retrieve current TV Dimming Mode valid arguments | "global" | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetTVDimmingMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetTVPictureModeIndex() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetTVPictureModeIndex() -  Retrieve the current TV Picture ModeIndex with valid arguments | const char * | tvERROR_NONE | Should Pass |
* | 03 | call GetTVPictureModeIndex() -  Retrieve the current TV Picture ModeIndex with valid arguments and validate with above value | const char * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetTVPictureModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/*todo : there is no return error cases*/
/**
* @brief Validate GetTVPictureModeIndex() for all negative invocation scenarios
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
* | 01 | call GetTVPictureModeIndex() -  Retrieve current TV PictureMode Index even before tvInit() | const char * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetTVPictureModeIndex() -   Retrieve current TV PictureMode Index with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetTVPictureModeIndex() -  Retrieve current TVPictureMode Index valid arguments | const char * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetTVPictureModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetCurrentContentFormat() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetCurrentContentFormat() -  Retrieve the current Current ContentFormat with valid arguments | void | tvVideoFormat_SDR  | Should Pass |
* | 03 | call GetCurrentContentFormat() -  Retrieve the current Current ContentFormat with valid arguments and validate with above value | void | tvVideoFormat_HLG  | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetCurrentContentFormat (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/*todo : there is no return error cases*/
/**
* @brief Validate GetCurrentContentFormat() for all negative invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetSupportedContentFormats() -  Retrieve the current Supported ContentFormats with valid arguments | unsigned int *, unsigned short * | tvERROR_NONE | Should Pass |
* | 03 | call GetSupportedContentFormats() -  Retrieve the current Supported ContentFormats with valid arguments and validate with above value | unsigned int *, unsigned short * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetSupportedContentFormats (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/*todo : there is no return error cases*/
/**
* @brief Validate GetSupportedContentFormats() for all negative invocation scenarios
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
* @brief Validate SaveColorTemperature() for all positive invocation scenarios
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
* | 01 | call SaveBacklight() -  Retrieve current TV Backlight even before tvInit() | HDMI, 0, HDR_TYPE_HLG, 08 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveBacklight() -   Retrieve current TV Backlight with invalid input | HDMI, 0, HDR_TYPE_MAX, 08 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveBacklight() -   Retrieve current TV Backlight with invalid input | HDMI, 0, HDR_TYPE_HLG, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveBacklight() -   Retrieve current TV Backlight with invalid input | HDMI, 0, HDR_TYPE_HLG, 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveBacklight() -   Retrieve current TV Backlight with invalid input | HDMI, 11, HDR_TYPE_HLG, 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SaveBacklight() -  Retrieve current TV Backlight valid arguments | HDMI, 3, HDR_TYPE_DOVI, 78 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SaveBacklight (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveContrast() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetNumberOfModesupported() -  Retrieve the current Mode supported with valid arguments | void | int | Should Pass |
* | 03 | call GetNumberOfModesupported() -  Retrieve the current Mode supported with valid arguments and validate with above value | void | int | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetNumberOfModesupported (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/*todo: no return value*/
/**
* @brief Validate GetNumberOfModesupported() for all negative invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetCurrentPQIndex() -  Retrieve the current PQIndex with valid arguments | void | int | Should Pass |
* | 03 | call GetCurrentPQIndex() -  Retrieve the current PQIndex with valid arguments and validate with above value | void | int | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetCurrentPQIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/*todo: no return value*/
/**
* @brief Validate GetCurrentPQIndex() for all negative invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetAllSupportedPicModeIndex() -  Retrieve the Supported PicModeIndex with valid arguments | int [] | tvERROR_NONE | Should Pass |
* | 03 | call GetAllSupportedPicModeIndex() -  Retrieve the Supported PicModeIndex with valid arguments and validate with above value | int [] | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetAllSupportedPicModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/*todo: no return value*/
/**
* @brief Validate GetAllSupportedPicModeIndex() for all negative invocation scenarios
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

/*todo: no return value*/
/**
* @brief Validate GetCMSDefault() for all negative invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetDolbyModeIndex() -  Retrieve the current Dolby ModeIndex with valid arguments | const char * | int | Should Pass |
* | 03 | call GetDolbyModeIndex() -  Retrieve the current Dolby ModeIndex with valid arguments and validate with above value | const char * | int | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetDolbyModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/*todo: no return value*/
/**
* @brief Validate GetDolbyModeIndex() for all negative invocation scenarios
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
* @brief Validate SetCMSState() for all positive invocation scenarios
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
* @brief Validate SetColorTemperatureUser() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetColorTemperatureUser() -  Set the  Color Temperature User value with valid value | R_GAIN, 08 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemperatureUser() -  Reset the  Color Temperature User value with another valid value | R_GAIN, 58 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemperatureUser() -  Reset the  Color Temperature User value with another valid value | R_GAIN, 95 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemperatureUser() -  Set the  Color Temperature User value with valid value | G_GAIN , 17 | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemperatureUser() -  Set the  Color Temperature User value with valid value | B_GAIN , 65 | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetColorTemperatureUser (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetColorTemperatureUser() for all negative invocation scenarios
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
* | 01 | call SetColorTemperatureUser() - Set the TV Color Temperature User even before tvInit() | R_GAIN, 65 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemperatureUser() -   Set the TV Color Temperature User with invalid input | R_GAIN, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemperatureUser() -   Set the TV Color Temperature User with invalid input | RGB_TYPE_MAX, 65 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemperatureUser() -  Set the TV Color Temperature User with valid input after tvTerm() | R_GAIN, 65 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemperatureUser (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveColorTemperatureUser() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SaveColorTemperatureUser() -  Save the  Color Temperature User value with valid value | R_GAIN, 08 | tvERROR_NONE | Should Pass |
* | 03 | call SaveColorTemperatureUser() -  Save the  Color Temperature User value with another valid value | R_GAIN, 58 | tvERROR_NONE | Should Pass |
* | 04 | call SaveColorTemperatureUser() -  Save the  Color Temperature User value with another valid value | R_GAIN, 95 | tvERROR_NONE | Should Pass |
* | 05 | call SaveColorTemperatureUser() -  Save the  Color Temperature User value with valid value | B_GAIN, 17 | tvERROR_NONE | Should Pass |
* | 06 | call SaveColorTemperatureUser() -  Save the  Color Temperature User value with valid value | G_GAIN, 65 | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SaveColorTemperatureUser (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveColorTemperatureUser() for all negative invocation scenarios
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
* | 01 | call SaveColorTemperatureUser() - Save the TV Color Temperature User even before tvInit() | 30 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveColorTemperatureUser() -   Save the TV Color Temperature User with invalid input | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveColorTemperatureUser() -   Save the TV Color Temperature User with invalid input | 256 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call SaveColorTemperatureUser() -  Save the TV Color Temperature User with valid input after tvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SaveColorTemperatureUser (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetHLGModeIndex() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetHLGModeIndex() -  Retrieve the current HLGModeIndex with valid arguments | const char * | tvERROR_NONE | Should Pass |
* | 03 | call GetHLGModeIndex() -  Retrieve the current HLGModeIndex with valid arguments and validate with above value | const char * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetHLGModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/*todo : no return error for this*/
/**
* @brief Validate GetHLGModeIndex() for all negative invocation scenarios
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

/**
* @brief Validate GetHDR10ModeIndex() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetHDR10ModeIndex() -  Retrieve the current HDR10 ModeIndex with valid arguments | const char * | tvERROR_NONE | Should Pass |
* | 03 | call GetHDR10ModeIndex() -  Retrieve the current HDR10 ModeIndex with valid arguments and validate with above value | const char * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetHDR10ModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/*todo : no return error for this*/
/**
* @brief Validate GetHDR10ModeIndex() for all negative invocation scenarios
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

/** TODO: Needed exact i/p parameters in header files
* @brief Validate SetBacklightFade() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetBacklightFade() -  Set the Backlight Fade with valid value | 10, 50, 500 | tvERROR_NONE | Should Pass |
* | 03 | call SetBacklightFade() -  Reset the Backlight Fade with another valid value | 50, 70, 500 | tvERROR_NONE | Should Pass |
* | 04 | call SetBacklightFade() -  Reset the Backlight Fade with another valid value | 10, 90, 500 | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetBacklightFade() - Set the TV  Backlight Fade value even before tvInit() | 10, 50, 500 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetBacklightFade() -   Set the TV  Backlight Fade value with invalid input | 10, 0, 500 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetBacklightFade() -   Set the TV  Backlight Fade value with invalid input | 0, 50, 500 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetBacklightFade() -   Set the TV  Backlight Fade value with invalid input | 10, 50, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call SetBacklightFade() -  Set the TV  Backlight Fade value with valid input after tvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetBacklightFade (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetGammaMode() for all positive invocation scenarios
* This test ensures that the TV Settings module is to set Gamma Mode value
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
* | 01 | call SetGammaMode() -  Set the Gamma Mode with valid value | 00 | tvERROR_NONE | Should Pass |
* | 02 | call SetGammaMode() -  Reset the Gamma Mode with another valid value | 01 | tvERROR_NONE | Should Pass |
* | 03 | call SetGammaMode() -  Reset the Gamma Mode with another valid value | 00 | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetGammaMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetGammaMode() for all negative invocation scenarios
* This test ensures that the TV Settings module is to set Gamma Mode value
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
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetGammaMode() -   Set the TV GammaMode with invalid input | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 02 | call SetGammaMode() -   Set the TV GammaMode with invalid input | 256 | tvERROR_INVALID_PARAM | Should Pass |
*/
void test_l1_tvSettings_negative_SetGammaMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetLocalDimmingLevel() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetLocalDimmingLevel() -  Set the Local DimmingLevel with valid value | 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetLocalDimmingLevel() -  Reset the Local DimmingLevel with another valid value | 01 | tvERROR_NONE | Should Pass |
* | 04 | call SetLocalDimmingLevel() -  Reset the Local DimmingLevel with another valid value | 0 | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetLocalDimmingLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetLocalDimmingLevel() for all negative invocation scenarios
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
* | 01 | call SetLocalDimmingLevel() - Set the TV Local DimmingLevel even before tvInit() | 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetLocalDimmingLevel() -   Set the TV Local DimmingLevel with invalid input | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetLocalDimmingLevel() -   Set the TV Local DimmingLevel with invalid input | 256 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call SetLocalDimmingLevel() -  Set the TV Local DimmingLevel with valid input after tvTerm() | 1 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetLocalDimmingLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetLocalDimmingLevel() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetLocalDimmingLevel() -  Retrieve the Local DimmingLevel with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetLocalDimmingLevel() -  Retrieve the Local DimmingLevel with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetLocalDimmingLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetLocalDimmingLevel() for all negative invocation scenarios
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
* | 01 | call GetLocalDimmingLevel() -  Retrieve current TV Local DimmingLevel even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetLocalDimmingLevel() -   Retrieve current TV Local DimmingLevel with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetLocalDimmingLevel() -  Retrieve current TV Local DimmingLevel valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetLocalDimmingLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveLocalDimmingLevel() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SaveLocalDimmingLevel() -  Save the Local DimmingLevel with valid arguments | HDMI, 0, HDR_TYPE_HLG, 0 | tvERROR_NONE | Should Pass |
* | 03 | call SaveLocalDimmingLevel() -  Save the Local DimmingLevel with valid arguments | HDMI, 1, HDR_TYPE_SDR, 0 | tvERROR_NONE | Should Pass |
* | 04 | call SaveLocalDimmingLevel() -  Save the Local DimmingLevel with valid arguments | HDMI, 2, HDR_TYPE_HDR10, 0 | tvERROR_NONE | Should Pass |
* | 05 | call SaveLocalDimmingLevel() -  Save the Local DimmingLevel with valid arguments | HDMI, 3, HDR_TYPE_DOVI, 1 | tvERROR_NONE | Should Pass |
* | 06 | call SaveLocalDimmingLevel() -  Save the Local DimmingLevel with valid arguments | HDMI, 4, HDR_TYPE_HLG, 1 | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SaveLocalDimmingLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveLocalDimmingLevel() for all negative invocation scenarios
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
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SaveLocalDimmingLevel() -  save current Local DimmingLevel even before tvInit() | HDMI, 0, HDR_TYPE_HLG, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveLocalDimmingLevel() -  save current Local DimmingLevel with invalid input | HDMI, 0, HDR_TYPE_MAX, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveLocalDimmingLevel() -  save current Local DimmingLevel with invalid input | HDMI, 0, HDR_TYPE_HLG, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveLocalDimmingLevel() -  save current Local DimmingLevel with invalid input | HDMI, 0, HDR_TYPE_HLG, 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveLocalDimmingLevel() -  save current Local DimmingLevel with invalid input | HDMI, 11, HDR_TYPE_HLG, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SaveLocalDimmingLevel() -  save current Local DimmingLevel valid arguments | HDMI, 3, HDR_TYPE_DOVI, 1 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SaveLocalDimmingLevel (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveLowLatencyState() for all positive invocation scenarios
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
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SaveLowLatencyState() -  Save the Low LatencyState with valid arguments | HDMI, 0, HDR_TYPE_HLG, 0 | tvERROR_NONE | Should Pass |
* | 03 | call SaveLowLatencyState() -  Save the Low LatencyState with valid arguments | HDMI, 1, HDR_TYPE_SDR, 0 | tvERROR_NONE | Should Pass |
* | 04 | call SaveLowLatencyState() -  Save the Low LatencyState with valid arguments | HDMI, 2, HDR_TYPE_HDR10, 1 | tvERROR_NONE | Should Pass |
* | 05 | call SaveLowLatencyState() -  Save the Low LatencyState with valid arguments | HDMI, 3, HDR_TYPE_DOVI, 1 | tvERROR_NONE | Should Pass |
* | 06 | call SaveLowLatencyState() -  Save the Low LatencyState with valid arguments | HDMI, 4, HDR_TYPE_HLG, 0 | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SaveLowLatencyState (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveLowLatencyState() for all negative invocation scenarios
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
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SaveLowLatencyState() -  save current TV Contrast even before tvInit() | HDMI, 0, HDR_TYPE_HLG, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveLowLatencyState() -  save current TV Contrast with invalid input | HDMI, 0, HDR_TYPE_MAX, 08 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveLowLatencyState() -  save current TV Contrast with invalid input | HDMI, 0, HDR_TYPE_HLG, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveLowLatencyState() -  save current TV Contrast with invalid input | HDMI, 0, HDR_TYPE_HLG, 101 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveLowLatencyState() -  save current TV Contrast with invalid input | HDMI, 11, HDR_TYPE_HLG, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SaveLowLatencyState() -  save current TV Contrast valid arguments | HDMI, 3, HDR_TYPE_DOVI, 1 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SaveLowLatencyState (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetLowLatencyState() for all positive invocation scenarios
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

/**
* @brief Validate SetGammaTable() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetGammaTable() -  Retrieve the current LowLatency State with valid arguments | unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_NONE | Should Pass |
* | 03 | call SetGammaTable() -  Retrieve the current LowLatency State with valid arguments and validate with above value | unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetGammaTable() - Set the TV LowLatency State even before tvInit() | unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetGammaTable() -   Set the TV LowLatency State with invalid input | NULL, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetGammaTable() -   Set the TV LowLatency State with invalid input | unsigned short *, NULL, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetGammaTable() -   Set the TV LowLatency State with invalid input | unsigned short *, unsigned short *, NULL, 256| tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SetGammaTable() -  Set the TV LowLatency State with valid input after tvTerm() | unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetGammaTable (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate GetGammaTable() for all positive invocation scenarios
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetGammaTable() -  Retrieve the current GammaTable value with valid arguments | int ,  unsigned short *,  unsigned short *,  unsigned short *, int | tvERROR_NONE | Should Pass |
* | 03 | call GetGammaTable() -  Retrieve the current GammaTable value with valid arguments and validate with above value | int ,  unsigned short *,  unsigned short *,  unsigned short *, int | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call GetGammaTable() -  Retrieve current TV GammaTable State even before tvInit() | int ,  unsigned short *,  unsigned short *,  unsigned short *, int | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetGammaTable() -   Retrieve current TV GammaTable State with invalid input | int ,  NULL,  unsigned short *,  unsigned short *, int | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetGammaTable() -   Retrieve current TV GammaTable State with invalid input | int , unsigned short *,  NULL, unsigned short *, int | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call GetGammaTable() -  Retrieve current TV GammaTable State valid arguments |int ,  unsigned short *,  unsigned short *,  unsigned short *, intint ,  unsigned short *,  unsigned short *,  unsigned short *, int | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetGammaTable (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SaveGammaTable() for all positive invocation scenarios
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
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SaveGammaTable() -  Retrieve the current LowLatency State with valid arguments | int , unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_NONE | Should Pass |
* | 03 | call SaveGammaTable() -  Retrieve the current LowLatency State with valid arguments and validate with above value | int , unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* **Test Case ID:** 224@n
* 
* **Pre-Conditions:** None@n
*
* **Dependencies:** None@n
* **User Interaction:** None
* 
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SaveGammaTable() - Set the TV LowLatency State even before tvInit() | int, unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveGammaTable() -   Set the TV LowLatency State with invalid input | int, NULL, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SaveGammaTable() -   Set the TV LowLatency State with invalid input | int, unsigned short *, NULL, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SaveGammaTable() -   Set the TV LowLatency State with invalid input | int, unsigned short *, unsigned short *, NULL, 256| tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SaveGammaTable() -  Set the TV LowLatency State with valid input after tvTerm() | int, unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SaveGammaTable (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetGammaPattern() for all positive invocation scenarios
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
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetGammaPattern() -  Set the GammaPattern with valid arguments | int ,int, int, int | tvERROR_NONE | Should Pass |
* | 03 | call SetGammaPattern() -  ReSet the GammaPattern with with valid arguments and validate with above value | int ,int, int, int | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_SetGammaPattern (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/**
* @brief Validate SetGammaPattern() for all negative invocation scenarios
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
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :-------: | ------------- | --------- | --------------- | ----- |
* | 01 | call SetGammaPattern() - Set the GammaPattern even before tvInit() | int ,int, int, int| tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetGammaPattern() -   Set the GammaPattern with invalid input | int ,int, int, int | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SetGammaPattern() -  Set the GammaPattern with valid input after tvTerm() | int ,int, int, int | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetGammaPattern (void)
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
	//There is no  negative error return value currently for tvTerm()
	//UT_add_test( pSuite, "tvTerm_L1_negative" ,test_l1_tvSettings_negative_tvTerm );
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
	UT_add_test( pSuite, "GetTVPictureModeIndex_L1_positive" ,test_l1_tvSettings_positive_GetTVPictureModeIndex );
	UT_add_test( pSuite, "GetTVPictureModeIndex_L1_negative" ,test_l1_tvSettings_negative_GetTVPictureModeIndex );
	UT_add_test( pSuite, "GetCurrentContentFormat_L1_positive" ,test_l1_tvSettings_positive_GetCurrentContentFormat );
	UT_add_test( pSuite, "GetCurrentContentFormat_L1_negative" ,test_l1_tvSettings_negative_GetCurrentContentFormat );
	UT_add_test( pSuite, "GetSupportedContentFormats_L1_positive" ,test_l1_tvSettings_positive_GetSupportedContentFormats );
	UT_add_test( pSuite, "GetSupportedContentFormats_L1_negative" ,test_l1_tvSettings_negative_GetSupportedContentFormats );
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
	UT_add_test( pSuite, "SetCMSState_L1_positive" ,test_l1_tvSettings_positive_SetCMSState );
	UT_add_test( pSuite, "SetCMSState_L1_negative" ,test_l1_tvSettings_negative_SetCMSState );
	UT_add_test( pSuite, "SetColorTemperatureUser_L1_positive" ,test_l1_tvSettings_positive_SetColorTemperatureUser );
	UT_add_test( pSuite, "SetColorTemperatureUser_L1_negative" ,test_l1_tvSettings_negative_SetColorTemperatureUser );
	UT_add_test( pSuite, "SaveColorTemperatureUser_L1_positive" ,test_l1_tvSettings_positive_SaveColorTemperatureUser );
	UT_add_test( pSuite, "SaveColorTemperatureUser_L1_negative" ,test_l1_tvSettings_negative_SaveColorTemperatureUser );
	UT_add_test( pSuite, "GetHLGModeIndex_L1_positive" ,test_l1_tvSettings_positive_GetHLGModeIndex );
	UT_add_test( pSuite, "GetHLGModeIndex_L1_negative" ,test_l1_tvSettings_negative_GetHLGModeIndex );
	UT_add_test( pSuite, "GetHDR10ModeIndex_L1_positive" ,test_l1_tvSettings_positive_GetHDR10ModeIndex );
	UT_add_test( pSuite, "GetHDR10ModeIndex_L1_negative" ,test_l1_tvSettings_negative_GetHDR10ModeIndex );
	UT_add_test( pSuite, "SetBacklightFade_L1_positive" ,test_l1_tvSettings_positive_SetBacklightFade );
	UT_add_test( pSuite, "SetBacklightFade_L1_negative" ,test_l1_tvSettings_negative_SetBacklightFade );
	UT_add_test( pSuite, "SetGammaMode_L1_positive" ,test_l1_tvSettings_positive_SetGammaMode );
	UT_add_test( pSuite, "SetGammaMode_L1_negative" ,test_l1_tvSettings_negative_SetGammaMode );
	UT_add_test( pSuite, "SetLocalDimmingLevel_L1_positive" ,test_l1_tvSettings_positive_SetLocalDimmingLevel );
	UT_add_test( pSuite, "SetLocalDimmingLevel_L1_negative" ,test_l1_tvSettings_negative_SetLocalDimmingLevel );
	UT_add_test( pSuite, "GetLocalDimmingLevel_L1_positive" ,test_l1_tvSettings_positive_GetLocalDimmingLevel );
	UT_add_test( pSuite, "GetLocalDimmingLevel_L1_negative" ,test_l1_tvSettings_negative_GetLocalDimmingLevel );
	UT_add_test( pSuite, "SaveLocalDimmingLevel_L1_positive" ,test_l1_tvSettings_positive_SaveLocalDimmingLevel );
	UT_add_test( pSuite, "SaveLocalDimmingLevel_L1_negative" ,test_l1_tvSettings_negative_SaveLocalDimmingLevel );
	UT_add_test( pSuite, "SaveLowLatencyState_L1_positive" ,test_l1_tvSettings_positive_SaveLowLatencyState );
	UT_add_test( pSuite, "SaveLowLatencyState_L1_negative" ,test_l1_tvSettings_negative_SaveLowLatencyState );
	UT_add_test( pSuite, "SetLowLatencyState_L1_positive" ,test_l1_tvSettings_positive_SetLowLatencyState );
	UT_add_test( pSuite, "SetLowLatencyState_L1_negative" ,test_l1_tvSettings_negative_SetLowLatencyState );
	UT_add_test( pSuite, "GetLowLatencyState_L1_positive" ,test_l1_tvSettings_positive_GetLowLatencyState );
	UT_add_test( pSuite, "GetLowLatencyState_L1_negative" ,test_l1_tvSettings_negative_GetLowLatencyState );
	UT_add_test( pSuite, "SetGammaTable_L1_positive" ,test_l1_tvSettings_positive_SetGammaTable );
	UT_add_test( pSuite, "SetGammaTable_L1_negative" ,test_l1_tvSettings_negative_SetGammaTable );
	UT_add_test( pSuite, "GetGammaTable_L1_positive" ,test_l1_tvSettings_positive_GetGammaTable );
	UT_add_test( pSuite, "GetGammaTable_L1_negative" ,test_l1_tvSettings_negative_GetGammaTable );
	UT_add_test( pSuite, "SaveGammaTable_L1_positive" ,test_l1_tvSettings_positive_SaveGammaTable );
	UT_add_test( pSuite, "SaveGammaTable_L1_negative" ,test_l1_tvSettings_negative_SaveGammaTable );
	UT_add_test( pSuite, "SetGammaPattern_L1_positive" ,test_l1_tvSettings_positive_SetGammaPattern );
	UT_add_test( pSuite, "SetGammaPattern_L1_negative" ,test_l1_tvSettings_negative_SetGammaPattern );
	return 0;
} 
