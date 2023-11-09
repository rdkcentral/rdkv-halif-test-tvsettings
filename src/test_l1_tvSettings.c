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
* | 03 | call GetTVPictureMode() -  Retrieve current TV PictureMode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetTVPictureMode() -  Retrieve current TV PictureMode with valid input after tvTerm() | char * | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetTVPictureMode (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

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
* | 02 | call SetTVPictureMode() -  Set the TV PictureMode by looping through all the values of pictureModes from the config file | const char * | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetTVPictureMode() - Set the TV PictureMode even before tvInit() with input as picturemode from the config file | const char *  | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetTVPictureMode() -   Set the TV PictureMode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetTVPictureMode() -   Set the TV PictureMode with invalid input with input as picturemode from not in the config file | const char *  | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call SetTVPictureMode() -  Set the TV PictureMode with valid input after tvTerm() with input as picturemode from the config file  | const char * | tvERROR_INVALID_STATE | Should Pass |
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
* | 03 | call GetTVBacklight() -  Retrieve current TV Backlight with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
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
* | 02 | Call SetBacklight() - Set the backlight with valid value | 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetBacklight() -  Reset the backlight with another valid value | 50 | tvERROR_NONE | Should Pass |
* | 04 | call SetBacklight() -  Reset the backlight with another valid value | 100 | tvERROR_NONE | Should Pass |
* | 05 | call SetBacklight() -  Reset the backlight with another valid value | 100 | tvERROR_NONE | Should Pass |
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
* | 03 | call SetBacklight() -   Set the TV backlight with less than the lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
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
* | 03 | call SetBrightness() -   Set the TV brightness with less than the lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
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
* | 03 | call GetTVBrightness() -  Retrieve current TV Brightness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
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
* | 03 | call SetContrast() -   Set the TV contrast with less than the lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
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
* | 03 | call GetTVContrast() -  Retrieve current TV Contrast with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
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
* | 03 | call SetSharpness() -   Set the TV sharpness with less than the lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
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
* | 03 | call GetTVSharpness() -  Retrieve current TV Sharpness with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
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
* | 03 | call SetSaturation() -   Set the TV saturation with less than the lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
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
* | 03 | call GetTVSaturation() -  Retrieve current TV Saturation with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
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
* | 03 | call SetHue() -   Set the TV hue with less than the lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
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
* | 02 | call SetColorTemperature() -  Set the TV ColorTemperature by looping through all the values of ColorTemperatures from the config file | const char * | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 03 | call SetColorTemperature() -   Set the TV ColorTemperature with less than the lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
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
* | 03 | call GetTVColorTemperature() -  Retrieve current TV ColorTemperature with invalid input | NULL | tvERROR_INVALID_PARAM |
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
* | 02 | call SetAspectRatio() -  Set the TV Aspect ratio by looping through all the values of aspect ratios from the config file | const char * | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 03 | call SetAspectRatio() -  Retrieve current TV Aspect ratio with invalid input | -1 | tvERROR_INVALID_PARAM |
* | 04 | call SetAspectRatio() -  Retrieve current TV Aspect ratio with invalid input | tvDisplayMode_MAX | tvERROR_INVALID_PARAM |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call SetAspectRatio() -  Set the TV AspectRatio with valid input after tvTerm() | tvDisplayMode_16x9 | tvERROR_INVALID_STATE | Should Pass |
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
* | 03 | call GetTVAspectRatio() -  Retrieve current TV AspectRatio with invalid input | NULL | tvERROR_INVALID_PARAM |
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
* | 03 | call GetSupportedBacklightModes() -  Retrieve supported Backlight modes with invalid input | NULL | tvERROR_INVALID_PARAM |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetSupportedBacklightModes() -  Retrieve current TV SupportedBacklightModes valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
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
* | 03 | call GetCurrentBacklightMode() -  Retrieve TV current Backlight modes with invalid input | NULL | tvERROR_INVALID_PARAM |
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
* | 02 | call SetCurrentBacklightMode() -  Set the TV Current Baklight mode by looping through all the values of backlight modes from the config file | const char * | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 05 | call SetCurrentBacklightMode() -   Set the TV CurrentBacklightMode with invalid parameter  | (tvBacklightMode_MANUAL| tvBacklightMode_AMBIENT) | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetCurrentBacklightMode() -   Set the TV CurrentBacklightMode with max range  | (tvBacklightMode_INVALID |tvBacklightMode_AMBIENT) | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SetCurrentBacklightMode() -  Set the TV CurrentBacklightMode with valid input after tvTerm() | tvBacklightMode_MANUAL | tvERROR_INVALID_STATE | Should Pass |
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
* | 03 | call GetCurrentVideoFormat() -  Retrieve current TV video format with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
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
* | 03 | call GetVideoResolution() -  Retrieve the current TV VideoResolution with invalid arguments | NULL | tvERROR_INVALID_PARAM | Should Pass |
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
* | 03 | call GetVideoFrameRate() -  Retrieve current TV frame rate with invalid input | NULL | tvERROR_INVALID_PARAM |
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
* | 02 | call setWakeupConfig() -  Enable the WakeupConfig with by looping through all the values of wakeup modes from the config file | const tvWakeupSrcType_t , true | tvERROR_NONE | Should Pass |
* | 03 | call setWakeupConfig() -  Disable the WakeupConfig with by looping through all the values of wakeup modes from the config file | const tvWakeupSrcType_t , false | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 04 | call setWakeupConfig() -   Set the TV WakeupConfig with less than lower range | -1, false  | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call setWakeupConfig() -   Set the TV WakeupConfig with  max range | tvWakeupSrc_MAX, true  | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call setWakeupConfig() -  Set the TV WakeupConfig with valid input after tvTerm() | tvWakeupSrc_CEC, false  | tvERROR_INVALID_STATE | Should Pass |
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
* | 03 | call SetRGBPattern() - Set the TV RGBPattern with invalid value of R with  max range | 256,100,100 | tvERROR_GENERAL | Should Pass |
* | 04 | call SetRGBPattern() - Set the TV RGBPattern with invalid value of G with  max range | 100,256,100 | tvERROR_GENERAL | Should Pass |
* | 05 | call SetRGBPattern() - Set the TV RGBPattern with invalid value of B with  max range | 100,100,256 | tvERROR_GENERAL | Should Pass |
* | 06 | call SetRGBPattern() - Set the TV RGBPattern with invalid value of R with less than lower range | -1,100,100 | tvERROR_GENERAL | Should Pass |
* | 07 | call SetRGBPattern() - Set the TV RGBPattern with invalid value of G with less than lower range | 100,-1,100 | tvERROR_GENERAL | Should Pass |
* | 08 | call SetRGBPattern() - Set the TV RGBPattern with invalid value of B with less than lower range | 100,100,-1 | tvERROR_GENERAL | Should Pass |
* | 09 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 10 | call SetRGBPattern() -  Set the TV RGBPattern with valid input after tvTerm() | 254,254,254 | tvERROR_INVALID_STATE | Should Pass |
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
* | 03 | call GetRGBPattern() -  Retrieve current TV RGBPattern with invalid parameter of R |NULL, int *, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetRGBPattern() -  Retrieve current TV RGBPattern with invalid parameter of G|int *,NULL , int * | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetRGBPattern() -  Retrieve current TV RGBPattern with invalid parameter of B |int *, int *, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call GetRGBPattern() -  Retrieve current TV RGBPattern valid arguments | int *, int *, int * | tvERROR_INVALID_STATE | Should Pass |
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
* | 03 | call SetGrayPattern() - Set the TV GrayPattern with less than lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetGrayPattern() - Set the TV GrayPattern with max range | 256 | tvERROR_INVALID_PARAM | Should Pass |
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
* | 03 | call GetGrayPattern() - Get the TV GrayPattern with invalid input value | NULL | tvERROR_INVALID_PARAM | Should Pass |
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
* | 02 | call SetColorTemp_Rgain() -  Set the ColorTemp Rgain by looping through all the values of colourtemp values from the config file | tvColorTemp_t , 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Rgain() -  Set the ColorTemp Rgain by looping through all the values of colourtemp values from the config file | tvColorTemp_t , 2047 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Rgain() -  Set the ColorTemp Rgain by looping through all the values of colourtemp values from the config file | tvColorTemp_t , 1000 | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 03 | call SetColorTemp_Rgain() -   Set the ColorTemp invalid Rgain by looping through all the values of colourtemp values from the config file |tvColorTemp_t, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_Rgain() -   Set the ColorTemp invalid Rgain by looping through all the values of colourtemp values from the config file |tvColorTemp_t, 2048 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_Rgain() -   Set the TV ColorTemp valid Rgain with invalid colourtemp max range | tvColorTemp_MAX, 100 | tvERROR_INVALID_PARAM | Should Pass |
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
* | 02 | call GetColorTemp_Rgain() -  Retrieve the current ColorTemp Rgain by looping through all the values of colourtemp values from the config file |tvColorTemp_t, int * | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 03 | call GetColorTemp_Rgain() -   Retrieve current TV ColorTemp Rgain with invalid input by looping through all the values of colourtemp values from the config file| tvColorTemp_t, NULL | tvERROR_INVALID_PARAM | Should Pass |
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
* | 02 | call SetColorTemp_Ggain() -  Set the ColorTemp Ggain by looping through all the values of colourtemp values from the config file | tvColorTemp_t , 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Ggain() -  Set the ColorTemp Ggain by looping through all the values of colourtemp values from the config file | tvColorTemp_t , 2047 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Ggain() -  Set the ColorTemp Ggain by looping through all the values of colourtemp values from the config file | tvColorTemp_t , 1000 | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetColorTemp_Ggain() - Set the TV ColorTemp Ggain even before tvInit() |  tvColorTemp_t, 2047 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Ggain() -   Set the ColorTemp invalid Ggain by looping through all the values of colourtemp values from the config file |tvColorTemp_t, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_Ggain() -   Set the ColorTemp invalid Ggain by looping through all the values of colourtemp values from the config file |tvColorTemp_t, 2048 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_Ggain() -   Set the TV ColorTemp valid Ggain with invalid colourtemp max range | tvColorTemp_MAX, 100 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_Ggain() -  Set the TV ColorTemp Ggain with valid input after tvTerm() | tvColorTemp_t, 2047 | tvERROR_INVALID_STATE | Should Pass | |
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
* | 02 | call GetColorTemp_Ggain() -  Retrieve the current ColorTemp Ggain by looping through all the values of colourtemp values from the config file |tvColorTemp_t, int * | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 03 | call GetColorTemp_Ggain() -   Retrieve current TV ColorTemp Ggain with invalid input by looping through all the values of colourtemp values from the config file| tvColorTemp_t, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_Ggain() -   Retrieve current TV ColorTemp Ggain with less than lower range | -1, int * | tvERROR_INVALID_PARAM | Should Pass |
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
* | 02 | call SetColorTemp_Bgain() -  Set the ColorTemp Bgain by looping through all the values of colourtemp values from the config file | tvColorTemp_t , 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Bgain() -  Set the ColorTemp Bgain by looping through all the values of colourtemp values from the config file | tvColorTemp_t , 2047 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Bgain() -  Set the ColorTemp Bgain by looping through all the values of colourtemp values from the config file | tvColorTemp_t , 1000 | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 03 | call SetColorTemp_Bgain() -   Set the ColorTemp invalid Bgain by looping through all the values of colourtemp values from the config file |tvColorTemp_t, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_Bgain() -   Set the ColorTemp invalid Bgain by looping through all the values of colourtemp values from the config file |tvColorTemp_t, 2048 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_Bgain() -   Set the TV ColorTemp valid Bgain with invalid colourtemp max range | tvColorTemp_MAX, 100 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_Bgain() -  Set the TV ColorTemp Bgain with valid input after tvTerm() | tvColorTemp_COLD, 2047 | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call GetColorTemp_Bgain() -  Retrieve the current ColorTemp Bgain by looping through all the values of colourtemp values from the config file |tvColorTemp_t, int * | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 03 | call GetColorTemp_Bgain() -   Retrieve current TV ColorTemp Bgain with invalid input by looping through all the values of colourtemp values from the config file| tvColorTemp_t, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_Bgain() -   Retrieve current TV ColorTemp Bgain with less than lower range | -1, int * | tvERROR_INVALID_PARAM | Should Pass |
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
* | 02 | call SetColorTemp_R_post_offset() -  Set the ColorTemp R_post_offset with valid value by looping through all the values of colourtemp modes from the config file| tvColorTemp_t, -1024 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_R_post_offset() -  Reset the ColorTemp R_post_offset with another valid value by looping through all the values of colourtemp modes from the config file | tvColorTemp_t, 1024 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_R_post_offset() -  Reset the ColorTemp R_post_offset with another valid value by looping through all the values of colourtemp modes from the config file| tvColorTemp_t, 0 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_R_post_offset() -  Reset the ColorTemp R_post_offset with another valid value by looping through all the values of colourtemp modes from the config file| tvColorTemp_t, 500 | tvERROR_NONE | Should Pass |
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
* | 03 | call SetColorTemp_R_post_offset() -   Set the TV ColorTemp R_post_offset with less than the lower range by looping through all the values of colourtemp modes from the config file| tvColorTemp_t, -1025 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_R_post_offset() -   Set the TV ColorTemp R_post_offset with max range by looping through all the values of colourtemp modes from the config file | tvColorTemp_t, 1025 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_R_post_offset() -   Set the TV ColorTemp R_post_offset with less than the lower range value of colourtemp | -1, 500 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_R_post_offset() -   Set the TV ColorTemp R_post_offset with max range value of colourtemp| tvColorTemp_MAX, 500 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_R_post_offset() -  Set the TV ColorTemp R_post_offset with valid input after tvTerm() | tvColorTemp_STANDARD, 10 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SetColorTemp_R_post_offset (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

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
* | 02 | call GetColorTemp_R_post_offset() -  Retrieve the current ColorTemp R_post_offset with valid arguments by looping through all the values of colourtemp modes from the config file| tvColorTemp_t, int * | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 03 | call GetColorTemp_R_post_offset() -   Retrieve current TV ColorTemp R_post_offset with invalid input by looping through all the values of colourtemp modes from the config file |  tvColorTemp_t, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_R_post_offset() -   Retrieve current TV ColorTemp R_post_offset with less than the lower range of colourtemp |  -1, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_R_post_offset() -   Retrieve current TV ColorTemp R_post_offset with max range of colourtemp|  tvColorTemp_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
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
* | 02 | call SetColorTemp_G_post_offset() -  Set the ColorTemp G_post_offset with valid value by looping through all the values of colourtemp modes from the config file| tvColorTemp_t, -1024 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_G_post_offset() -  Reset the ColorTemp G_post_offset with another valid value by looping through all the values of colourtemp modes from the config file |  tvColorTemp_t, 1024 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_G_post_offset() -  Reset the ColorTemp G_post_offset with another valid value by looping through all the values of colourtemp modes from the config file| tvColorTemp_t, 0 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_G_post_offset() -  Reset the ColorTemp G_post_offset with another valid value by looping through all the values of colourtemp modes from the config file| tvColorTemp_t, 500 | tvERROR_NONE | Should Pass |
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
* | 03 | call SetColorTemp_G_post_offset() -   Set the TV ColorTemp G_post_offset with less than the lower range by looping through all the values of colourtemp modes from the config file| tvColorTemp_t, -1025 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_G_post_offset() -   Set the TV ColorTemp G_post_offset with max range by looping through all the values of colourtemp modes from the config file | tvColorTemp_t, 1025 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_G_post_offset() -   Set the TV ColorTemp G_post_offset with less than the lower range value of colourtemp | -1, 500 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_G_post_offset() -   Set the TV ColorTemp G_post_offset with max range value of colourtemp| tvColorTemp_MAX, 500 | tvERROR_INVALID_PARAM | Should Pass |
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
*  | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call GetColorTemp_G_post_offset() -  Retrieve the current ColorTemp G_post_offset with valid arguments by looping through all the values of colourtemp modes from the config file| tvColorTemp_t, int * | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 03 | call GetColorTemp_G_post_offset() -   Retrieve current TV ColorTemp G_post_offset with invalid input by looping through all the values of colourtemp modes from the config file |  tvColorTemp_t, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_G_post_offset() -   Retrieve current TV ColorTemp G_post_offset with less than the lower range of colourtemp |  -1, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_G_post_offset() -   Retrieve current TV ColorTemp G_post_offset with max range of colourtemp|  tvColorTemp_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
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
* | 02 | call SetColorTemp_B_post_offset() -  Set the ColorTemp B_post_offset with valid value by looping through all the values of colourtemp modes from the config file| tvColorTemp_t, -1024 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_B_post_offset() -  Reset the ColorTemp B_post_offset with another valid value by looping through all the values of colourtemp modes from the config file |  tvColorTemp_t, 1024 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_B_post_offset() -  Reset the ColorTemp B_post_offset with another valid value by looping through all the values of colourtemp modes from the config file| tvColorTemp_t, 0 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_B_post_offset() -  Reset the ColorTemp B_post_offset with another valid value by looping through all the values of colourtemp modes from the config file| tvColorTemp_t, 500 | tvERROR_NONE | Should Pass |
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
* | 01 | call SetColorTemp_B_post_offset() - Set the TV ColorTemp B_post_offset even before tvInit() | tvColorTemp_t, 104 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_B_post_offset() -   Set the TV ColorTemp B_post_offset with less than the lower range by looping through all the values of colourtemp modes from the config file| tvColorTemp_t, -1025 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_B_post_offset() -   Set the TV ColorTemp B_post_offset with max range by looping through all the values of colourtemp modes from the config file | tvColorTemp_t, 1025 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_B_post_offset() -   Set the TV ColorTemp B_post_offset with less than the lower range value of colourtemp | -1, 500 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_B_post_offset() -   Set the TV ColorTemp B_post_offset with max range value of colourtemp| tvColorTemp_MAX, 500 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_B_post_offset() -  Set the TV ColorTemp B_post_offset with valid input after tvTerm() | tvColorTemp_t, 10 | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call GetColorTemp_B_post_offset() -  Retrieve the current ColorTemp B_post_offset with valid arguments by looping through all the values of colourtemp modes from the config file| tvColorTemp_t, int * | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call GetColorTemp_B_post_offset() -  Retrieve current TV ColorTemp B_post_offset even before tvInit() |  tvColorTemp_t, int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_B_post_offset() -   Retrieve current TV ColorTemp B_post_offset with invalid input by looping through all the values of colourtemp modes from the config file |  tvColorTemp_t, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_B_post_offset() -   Retrieve current TV ColorTemp B_post_offset with less than the lower range of colourtemp |  -1, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_B_post_offset() -   Retrieve current TV ColorTemp B_post_offset with max range of colourtemp|  tvColorTemp_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call GetColorTemp_B_post_offset() -  Retrieve current TV ColorTemp B_post_offset valid arguments |  tvColorTemp_t, int * | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value by looping through all the values of colurtemp and sourceId from the config file | tvColorTemp_t, 0, int , 0| tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value by looping through all the values of colurtemp and sourceId from the config file | tvColorTemp_t, 2047, int , 0| tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value by looping through all the values of colurtemp and sourceId from the config file | tvColorTemp_t, 1000, int , 0| tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value by looping through all the values of colurtemp and sourceId from the config file | tvColorTemp_t, 0, int , 1| tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value by looping through all the values of colurtemp and sourceId from the config file | tvColorTemp_t, 2047, int , 1| tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_Rgain_onSource() -  Set the ColorTemp Rgain_onSource with valid value by looping through all the values of colurtemp and sourceId from the config file | tvColorTemp_t, 1000, int , 1| tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_Rgain_onSource() -  Reset the ColorTemp Rgain_onSource with another valid value | tvColorTemp_COLD, 2047, TV_OFFSET_NEW, 0 | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetColorTemp_Rgain_onSource() - Set the TV ColorTemp Rgain_onSource even before tvInit() | tvColorTemp_t, 0, int, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource with max range | tvColorTemp_MAX, 0, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource with max range | -1, 0, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource invalid rgain with by looping through all the values of colourtemp from the config file | tvColorTemp_t, -1, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource invalid rgain with by looping through all the values of colourtemp from the config file | tvColorTemp_t, 2048, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource invalid sourceId with by looping through all the values of colourtemp from the config file | tvColorTemp_t, 0, -1, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource invalid sourceId with by looping through all the values of colourtemp from the config file | tvColorTemp_t, 0, 3, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource invalid saveonly flag with by looping through all the values of colourtemp and sourceId from the config file | tvColorTemp_t, 0, int, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 10 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource invalid saveonly flag with by looping through all the values of colourtemp and sourceId from the config file | tvColorTemp_t, 0, int, 2 | tvERROR_INVALID_PARAM | Should Pass |
* | 11 | call SetColorTemp_Rgain_onSource() -   Set the TV ColorTemp Rgain_onSource with max range | tvColorTemp_MAX, 0, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 12 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 13 | call SetColorTemp_Rgain_onSource() -  Set the TV ColorTemp Rgain_onSource with valid input after tvTerm() | tvColorTemp_t, 2047, AV_OFFSET_NEW, 1 | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call GetColorTemp_Rgain_onSource() -  Retrieve the current ColorTemp Rgain_onSource with valid arguments by looping through all the values of colourtemp and sourceId modes from the config file | tvColorTemp_t, int *, int | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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

* | 01 | call GetColorTemp_Rgain_onSource() -  Retrieve current TV ColorTemp Rgain_onSource even before tvInit() | tvColorTemp_t, int *, HDMI_OFFSET_NEW  | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource with max range colour temp| tvColorTemp_MAX, int *, int | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource with less range colour temp |  -1, int *, int | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource invalide Rgain by looping through all the values of colourtemp from the config file |  tvColorTemp_t, NULL, int | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource invalide SourceId by looping through all the values of colourtemp from the config file |  tvColorTemp_t, int *, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call GetColorTemp_Rgain_onSource() -   Retrieve current TV ColorTemp Rgain_onSource invalide SourceId by looping through all the values of colourtemp from the config file |  tvColorTemp_t, int *, 3 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 09 | call GetColorTemp_Rgain_onSource() -  Retrieve current TV ColorTemp Rgain_onSource valid arguments | tvColorTemp_t, int *, TV_OFFSET_NEW  | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value by looping through all the values of colurtemp and sourceId from the config file | tvColorTemp_t, 0, int , 0| tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value by looping through all the values of colurtemp and sourceId from the config file | tvColorTemp_t, 2047, int , 0| tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value by looping through all the values of colurtemp and sourceId from the config file | tvColorTemp_t, 1000, int , 0| tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value by looping through all the values of colurtemp and sourceId from the config file | tvColorTemp_t, 0, int , 1| tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value by looping through all the values of colurtemp and sourceId from the config file | tvColorTemp_t, 2047, int , 1| tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_Ggain_onSource() -  Set the ColorTemp Ggain_onSource with valid value by looping through all the values of colurtemp and sourceId from the config file | tvColorTemp_t, 1000, int , 1| tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_Ggain_onSource() -  Reset the ColorTemp Ggain_onSource with another valid value | tvColorTemp_COLD, 2047, TV_OFFSET_NEW, 0 | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetColorTemp_Ggain_onSource() - Set the TV ColorTemp Ggain_onSource even before tvInit() | tvColorTemp_t, 0, int, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource with max range | tvColorTemp_MAX, 0, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource with max range | -1, 0, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource invalid rgain with by looping through all the values of colourtemp from the config file | tvColorTemp_t, -1, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource invalid rgain with by looping through all the values of colourtemp from the config file | tvColorTemp_t, 2048, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource invalid sourceId with by looping through all the values of colourtemp from the config file | tvColorTemp_t, 0, -1, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource invalid sourceId with by looping through all the values of colourtemp from the config file | tvColorTemp_t, 0, 3, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource invalid saveonly flag with by looping through all the values of colourtemp and sourceId from the config file | tvColorTemp_t, 0, int, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 10 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource invalid saveonly flag with by looping through all the values of colourtemp and sourceId from the config file | tvColorTemp_t, 0, int, 2 | tvERROR_INVALID_PARAM | Should Pass |
* | 11 | call SetColorTemp_Ggain_onSource() -   Set the TV ColorTemp Ggain_onSource with max range | tvColorTemp_MAX, 0, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 12 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 13 | call SetColorTemp_Ggain_onSource() -  Set the TV ColorTemp Ggain_onSource with valid input after tvTerm() | tvColorTemp_t, 2047, AV_OFFSET_NEW, 1 | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call GetColorTemp_Ggain_onSource() -  Retrieve the current ColorTemp Ggain_onSource with valid arguments by looping through all the values of colourtemp and sourceId modes from the config file | tvColorTemp_t, int *, int | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call GetColorTemp_Ggain_onSource() -  Retrieve current TV ColorTemp Ggain_onSource even before tvInit() | tvColorTemp_t, int *, HDMI_OFFSET_NEW  | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource with max range colour temp| tvColorTemp_MAX, int *, int | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource with less range colour temp |  -1, int *, int | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource invalide Rgain by looping through all the values of colourtemp from the config file |  tvColorTemp_t, NULL, int | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource invalide SourceId by looping through all the values of colourtemp from the config file |  tvColorTemp_t, int *, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call GetColorTemp_Ggain_onSource() -   Retrieve current TV ColorTemp Ggain_onSource invalide SourceId by looping through all the values of colourtemp from the config file |  tvColorTemp_t, int *, 3 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 09 | call GetColorTemp_Ggain_onSource() -  Retrieve current TV ColorTemp Ggain_onSource valid arguments | tvColorTemp_t, int *, TV_OFFSET_NEW  | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value by looping through all the values of colurtemp and sourceId from the config file | tvColorTemp_t, 0, int , 0| tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value by looping through all the values of colurtemp and sourceId from the config file | tvColorTemp_t, 2047, int , 0| tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value by looping through all the values of colurtemp and sourceId from the config file | tvColorTemp_t, 1000, int , 0| tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value by looping through all the values of colurtemp and sourceId from the config file | tvColorTemp_t, 0, int , 1| tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value by looping through all the values of colurtemp and sourceId from the config file | tvColorTemp_t, 2047, int , 1| tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_Bgain_onSource() -  Set the ColorTemp Bgain_onSource with valid value by looping through all the values of colurtemp and sourceId from the config file | tvColorTemp_t, 1000, int , 1| tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemp_Bgain_onSource() -  Reset the ColorTemp Bgain_onSource with another valid value | tvColorTemp_COLD, 2047, TV_OFFSET_NEW, 0 | tvERROR_NONE | Should Pass |
* | 09 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetColorTemp_Bgain_onSource() - Set the TV ColorTemp Bgain_onSource even before tvInit() | tvColorTemp_t, 0, int, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource with max range | tvColorTemp_MAX, 0, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource with max range | -1, 0, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource invalid rgain with by looping through all the values of colourtemp from the config file | tvColorTemp_t, -1, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource invalid rgain with by looping through all the values of colourtemp from the config file | tvColorTemp_t, 2048, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource invalid sourceId with by looping through all the values of colourtemp from the config file | tvColorTemp_t, 0, -1, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource invalid sourceId with by looping through all the values of colourtemp from the config file | tvColorTemp_t, 0, 3, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource invalid saveonly flag with by looping through all the values of colourtemp and sourceId from the config file | tvColorTemp_t, 0, int, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 10 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource invalid saveonly flag with by looping through all the values of colourtemp and sourceId from the config file | tvColorTemp_t, 0, int, 2 | tvERROR_INVALID_PARAM | Should Pass |
* | 11 | call SetColorTemp_Bgain_onSource() -   Set the TV ColorTemp Bgain_onSource with max range | tvColorTemp_MAX, 0, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 12 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 13 | call SetColorTemp_Bgain_onSource() -  Set the TV ColorTemp Bgain_onSource with valid input after tvTerm() | tvColorTemp_t, 2047, AV_OFFSET_NEW, 1 | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call GetColorTemp_Bgain_onSource() -  Retrieve the current ColorTemp Bgain_onSource with valid arguments by looping through all the values of colourtemp and sourceId modes from the config file | tvColorTemp_t, int *, int | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call GetColorTemp_Bgain_onSource() -  Retrieve current TV ColorTemp Bgain_onSource even before tvInit() | tvColorTemp_t, int *, HDMI_OFFSET_NEW  | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource with max range colour temp| tvColorTemp_MAX, int *, int | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource with less range colour temp |  -1, int *, int | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource invalide Rgain by looping through all the values of colourtemp from the config file |  tvColorTemp_t, NULL, int | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource invalide SourceId by looping through all the values of colourtemp from the config file |  tvColorTemp_t, int *, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call GetColorTemp_Bgain_onSource() -   Retrieve current TV ColorTemp Bgain_onSource invalide SourceId by looping through all the values of colourtemp from the config file |  tvColorTemp_t, int *, 3 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 09 | call GetColorTemp_Bgain_onSource() -  Retrieve current TV ColorTemp Bgain_onSource valid arguments | tvColorTemp_t, int *, TV_OFFSET_NEW  | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value by looping through all the values of colourtemp and sourceId from the config file| tvColorTemp_t, -1024, int, 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value by looping through all the values of colourtemp and sourceId from the config file| tvColorTemp_t, 1024, int, 0 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value by looping through all the values of colourtemp and sourceId from the config file| tvColorTemp_t, 500, int, 0 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value by looping through all the values of colourtemp and sourceId from the config file| tvColorTemp_t, -1024, int, 1 | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value by looping through all the values of colourtemp and sourceId from the config file| tvColorTemp_t, 1024, int, 1 | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_R_post_offset_onSource() -  Set the ColorTemp R_post_offset_onSource with valid value by looping through all the values of colourtemp and sourceId from the config file| tvColorTemp_t, 500, int, 1 | tvERROR_NONE | Should Pass |
* | 08 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetColorTemp_R_post_offset_onSource() - Set the TV ColorTemp R_post_offset_onSource even before tvInit() | tvColorTemp_t, -1024, int, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource with max range | tvColorTemp_Max, 0, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource with less than the lower range | -1, 0, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource invalid gpostoffset with by looping through all the values of colourtemp and SourceId from the config file | tvColorTemp_t, -1025, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource invalid gpostoffset with by looping through all the values of colourtemp and SourceId from the config file | tvColorTemp_t, 1025, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource invalid saveonly flag with by looping through all the values of colourtemp and sourceId from the config file | tvColorTemp_t, int, int, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SetColorTemp_R_post_offset_onSource() -   Set the TV ColorTemp R_post_offset_onSource invalid saveonly flag with by looping through all the values of colourtemp and sourceId from the config file | tvColorTemp_t, int, int, 2 | tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 10 | call SetColorTemp_R_post_offset_onSource() -  Set the TV ColorTemp R_post_offset_onSource with valid input after tvTerm() | tvColorTemp_t, 1024, int, 1 | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call GetColorTemp_R_post_offset_onSource() -  Retrieve the current ColorTemp R_post_offset_onSource with valid arguments by looping through all the values of colourtemp and sourceId modes from the config file | tvColorTemp_t, int *, int| tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 03 | call GetColorTemp_R_post_offset_onSource() -   Retrieve current TV ColorTemp R_post_offset_onSource with max range colour temp| tvColorTemp_MAX, int *, int | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_R_post_offset_onSource() -   Retrieve current TV ColorTemp R_post_offset_onSource with less range colour temp |  -1, int *, int | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_R_post_offset_onSource() -   Retrieve current TV ColorTemp R_post_offset_onSource invalide gpostoffset  by looping through all the values of colourtemp and SourceId from the config file |  tvColorTemp_t, NULL, int | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call GetColorTemp_R_post_offset_onSource() -   Retrieve current TV ColorTemp R_post_offset_onSource invalide SourceId by looping through all the values of colourtemp from the config file |  tvColorTemp_t, int *, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call GetColorTemp_R_post_offset_onSource() -   Retrieve current TV ColorTemp R_post_offset_onSource invalide SourceId by looping through all the values of colourtemp from the config file |  tvColorTemp_t, int *, 3 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 09 | call GetColorTemp_R_post_offset_onSource() -  Retrieve current TV ColorTemp R_post_offset_onSource valid arguments | tvColorTemp_COLD, int *, HDMI_OFFSET_NEW | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value by looping through all the values of colourtemp and sourceId from the config file| tvColorTemp_t, -1024, int, 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value by looping through all the values of colourtemp and sourceId from the config file| tvColorTemp_t, 1024, int, 0 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value by looping through all the values of colourtemp and sourceId from the config file| tvColorTemp_t, 500, int, 0 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value by looping through all the values of colourtemp and sourceId from the config file| tvColorTemp_t, -1024, int, 1 | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value by looping through all the values of colourtemp and sourceId from the config file| tvColorTemp_t, 1024, int, 1 | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_G_post_offset_onSource() -  Set the ColorTemp G_post_offset_onSource with valid value by looping through all the values of colourtemp and sourceId from the config file| tvColorTemp_t, 500, int, 1 | tvERROR_NONE | Should Pass |
* | 08 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetColorTemp_G_post_offset_onSource() - Set the TV ColorTemp G_post_offset_onSource even before tvInit() | tvColorTemp_t, -1024, int, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource with max range | tvColorTemp_Max, 0, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource with less than the lower range | -1, 0, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource invalid gpostoffset with by looping through all the values of colourtemp and SourceId from the config file | tvColorTemp_t, -1025, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource invalid gpostoffset with by looping through all the values of colourtemp and SourceId from the config file | tvColorTemp_t, 1025, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource invalid saveonly flag with by looping through all the values of colourtemp and sourceId from the config file | tvColorTemp_t, int, int, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SetColorTemp_G_post_offset_onSource() -   Set the TV ColorTemp G_post_offset_onSource invalid saveonly flag with by looping through all the values of colourtemp and sourceId from the config file | tvColorTemp_t, int, int, 2 | tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 10 | call SetColorTemp_G_post_offset_onSource() -  Set the TV ColorTemp G_post_offset_onSource with valid input after tvTerm() | tvColorTemp_t, 1024, int, 1 | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call GetColorTemp_G_post_offset_onSource() -  Retrieve the current ColorTemp G_post_offset_onSource with valid arguments by looping through all the values of colourtemp and sourceId modes from the config file | tvColorTemp_t, int *, int| tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 03 | call GetColorTemp_G_post_offset_onSource() -   Retrieve current TV ColorTemp G_post_offset_onSource with max range colour temp| tvColorTemp_MAX, int *, int | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_G_post_offset_onSource() -   Retrieve current TV ColorTemp G_post_offset_onSource with less range colour temp |  -1, int *, int | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_G_post_offset_onSource() -   Retrieve current TV ColorTemp G_post_offset_onSource invalide gpostoffset  by looping through all the values of colourtemp and SourceId from the config file |  tvColorTemp_t, NULL, int | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call GetColorTemp_G_post_offset_onSource() -   Retrieve current TV ColorTemp G_post_offset_onSource invalide SourceId by looping through all the values of colourtemp from the config file |  tvColorTemp_t, int *, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call GetColorTemp_G_post_offset_onSource() -   Retrieve current TV ColorTemp G_post_offset_onSource invalide SourceId by looping through all the values of colourtemp from the config file |  tvColorTemp_t, int *, 3 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 09 | call GetColorTemp_G_post_offset_onSource() -  Retrieve current TV ColorTemp G_post_offset_onSource valid arguments | tvColorTemp_COLD, int *, HDMI_OFFSET_NEW | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value by looping through all the values of colourtemp and sourceId from the config file| tvColorTemp_t, -1024, int, 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value by looping through all the values of colourtemp and sourceId from the config file| tvColorTemp_t, 1024, int, 0 | tvERROR_NONE | Should Pass |
* | 04 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value by looping through all the values of colourtemp and sourceId from the config file| tvColorTemp_t, 500, int, 0 | tvERROR_NONE | Should Pass |
* | 05 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value by looping through all the values of colourtemp and sourceId from the config file| tvColorTemp_t, -1024, int, 1 | tvERROR_NONE | Should Pass |
* | 06 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value by looping through all the values of colourtemp and sourceId from the config file| tvColorTemp_t, 1024, int, 1 | tvERROR_NONE | Should Pass |
* | 07 | call SetColorTemp_B_post_offset_onSource() -  Set the ColorTemp B_post_offset_onSource with valid value by looping through all the values of colourtemp and sourceId from the config file| tvColorTemp_t, 500, int, 1 | tvERROR_NONE | Should Pass |
* | 08 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetColorTemp_B_post_offset_onSource() - Set the TV ColorTemp B_post_offset_onSource even before tvInit() | tvColorTemp_t, -1024, int, 0 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource with max range | tvColorTemp_Max, 0, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource with less than the lower range | -1, 0, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource invalid gpostoffset with by looping through all the values of colourtemp and SourceId from the config file | tvColorTemp_t, -1025, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource invalid gpostoffset with by looping through all the values of colourtemp and SourceId from the config file | tvColorTemp_t, 1025, int, 0 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource invalid saveonly flag with by looping through all the values of colourtemp and sourceId from the config file | tvColorTemp_t, int, int, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SetColorTemp_B_post_offset_onSource() -   Set the TV ColorTemp B_post_offset_onSource invalid saveonly flag with by looping through all the values of colourtemp and sourceId from the config file | tvColorTemp_t, int, int, 2 | tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 10 | call SetColorTemp_B_post_offset_onSource() -  Set the TV ColorTemp B_post_offset_onSource with valid input after tvTerm() | tvColorTemp_t, 1024, int, 1 | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call GetColorTemp_B_post_offset_onSource() -  Retrieve the current ColorTemp B_post_offset_onSource with valid arguments by looping through all the values of colourtemp and sourceId modes from the config file | tvColorTemp_t, int *, int| tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 03 | call GetColorTemp_B_post_offset_onSource() -   Retrieve current TV ColorTemp B_post_offset_onSource with max range colour temp| tvColorTemp_MAX, int *, int | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetColorTemp_B_post_offset_onSource() -   Retrieve current TV ColorTemp B_post_offset_onSource with less range colour temp |  -1, int *, int | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetColorTemp_B_post_offset_onSource() -   Retrieve current TV ColorTemp B_post_offset_onSource invalide gpostoffset  by looping through all the values of colourtemp and SourceId from the config file |  tvColorTemp_t, NULL, int | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call GetColorTemp_B_post_offset_onSource() -   Retrieve current TV ColorTemp B_post_offset_onSource invalide SourceId by looping through all the values of colourtemp from the config file |  tvColorTemp_t, int *, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call GetColorTemp_B_post_offset_onSource() -   Retrieve current TV ColorTemp B_post_offset_onSource invalide SourceId by looping through all the values of colourtemp from the config file |  tvColorTemp_t, int *, 3 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 09 | call GetColorTemp_B_post_offset_onSource() -  Retrieve current TV ColorTemp B_post_offset_onSource valid arguments | tvColorTemp_COLD, int *, HDMI_OFFSET_NEW | tvERROR_INVALID_STATE | Should Pass |
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
* | 03 | call GetTVSupportedPictureModes() -  Retrieve supported TV PictureMode with invalid input | NULL, unsigned short * | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetTVSupportedPictureModes() -  Retrieve supported TV PictureMode with invalid input |  pic_modes_t *, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call GetTVSupportedPictureModes() -  Retrieve current TV Supported PictureModes valid arguments | pic_modes_t *, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
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
* | 03 | call GetTVSupportedDVModes() -  Retrieve supported TV DV modes with invalid input | NULL, unsigned short * | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetTVSupportedDVModes() -  Retrieve supported TV DV modes with invalid input | pic_modes_t *,  NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call GetTVSupportedDVModes() -  Retrieve current TV Supported DVModes valid arguments | pic_modes_t *, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call SetTVDolbyVisionMode() -  Set the TV DolbyVision mode by looping through all the values of DolbyVision modes from the config file | const char * | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetTVDolbyVisionMode() - Set the TV DolbyVision Mode even before tvInit() | const char * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetTVDolbyVisionMode() -   Set the TV DolbyVision Mode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetTVDolbyVisionMode() -   Set the TV DolbyVision Mode with not supported platform input | " " | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call SetTVDolbyVisionMode() -  Set the TV DolbyVision Mode with valid input after tvTerm() | const char *| tvERROR_INVALID_STATE | Should Pass |
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
* | 03 | call GetTVDolbyVisionMode() -  Retrieve current TV DolbyVision mode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
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
* | 02 | call SetTVHLGMode() -  Set the TV HLG mode by looping through all the values of HLG modes from the config file | const char * | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetTVHLGMode() - Set the TV HLG Mode even before tvInit() | const char * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetTVHLGMode() -   Set the TV HLG Mode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetTVHLGMode() -   Set the TV HLG Mode with not supported platform input| " " | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call SetTVHLGMode() -  Set the TV HLG Mode with valid input after tvTerm() | const char * | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call SetTVHDR10Mode() -  Set the TV HDR10 mode by looping through all the values of HDR10 modes from the config file | const char * | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetTVHDR10Mode() - Set the TV HDR10 Mode even before tvInit() | const char * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetTVHDR10Mode() -   Set the TV HDR10 Mode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetTVHDR10Mode() -   Set the TV HDR10 Mode with not supported platform input | " " | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call SetTVHDR10Mode() -  Set the TV HDR10 Mode with valid input after tvTerm() | const char * | tvERROR_INVALID_STATE | Should Pass |
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
* | 03 | call GetTVSupportedHLGModes() -  Retrieve supported TV HLG modes with invalid input | NULL , unsigned short * | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetTVSupportedHLGModes() -  Retrieve supported TV HLG modes with invalid input | pic_modes_t * , NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call GetTVSupportedHLGModes() -  Retrieve current TV Supported HLG Modes valid arguments | pic_modes_t *, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
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
* | 03 | call GetDynamicContrast() -  Retrieve current TV Dynamic contrast with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetDynamicContrast() -  Retrieve current TV Dynamic Contrast valid arguments | bool * | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call setWBctrl() -  Set the TV White balance control of gain value by looping through all the values of Inputsrc, colourtemp and colour from the config file | char *, char * ,char * , "gain", 0  | tvERROR_NONE | Should Pass |
* | 03 | call setWBctrl() -  Set the TV White balance control of gain value by looping through all the values of Inputsrc, colourtemp and colour from the config file | char *, char * ,char * , "gain", 2047  | tvERROR_NONE | Should Pass |
* | 04 | call setWBctrl() -  Set the TV White balance control of gain value by looping through all the values of Inputsrc, colourtemp and colour from the config file | char *, char * ,char * , "gain", 1000  | tvERROR_NONE | Should Pass |
* | 05 | call setWBctrl() -  Set the TV White balance control of offset value by looping through all the values of Inputsrc, colourtemp and colour from the config file | char *, char * ,char * , "offset", -1024  | tvERROR_NONE | Should Pass |
* | 06 | call setWBctrl() -  Set the TV White balance control of offset value by looping through all the values of Inputsrc, colourtemp and colour from the config file | char *, char * ,char * , "offset", 1024  | tvERROR_NONE | Should Pass |
* | 07 | call setWBctrl() -  Set the TV White balance control of offset value by looping through all the values of Inputsrc, colourtemp and colour from the config file | char *, char * ,char * , "offset",  0  | tvERROR_NONE | Should Pass |
* | 08 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call setWBctrl() - Set the TV WBctrl even before tvInit() | char *, char * ,char *, char *ctrl, int value | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call setWBctrl() -  Set the TV White balance control of invalid value by looping through all the values of Inputsrc, colurtemp and colour from the config file | char *, char * ,char * , "gain", -1  | tvERROR_NONE | Should Pass |
* | 04 | call setWBctrl() -  Set the TV White balance control of invalid value by looping through all the values of Inputsrc, colurtemp and colour from the config file | char *, char * ,char * , "gain", 2048  | tvERROR_NONE | Should Pass |
* | 05 | call setWBctrl() -  Set the TV White balance control of invalid value by looping through all the values of Inputsrc, colurtemp and colour from the config file | char *, char * ,char * , "offset", -1025  | tvERROR_NONE | Should Pass |
* | 06 | call setWBctrl() -  Set the TV White balance control of invalid value by looping through all the values of Inputsrc, colurtemp and colour from the config file | char *, char * ,char * , "offset", 1025  | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call setWBctrl() -  Set the TV WBctrl with valid input after tvTerm() | char *, char * ,char *, char *ctrl, int value | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call getWBctrl() -  Retrieve the current WBctrl with valid arguments by looping through all the values of Inputsrc, colurtemp and colour from the config file| char *, char *,char *, char *, int * | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call getWBctrl() -  Retrieve current TV WBctrl even before tvInit() | char *, char *,char *, char *, int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call getWBctrl() -  Retrieve current White balance control with invalid input of Inputsrc, colurtemp and colour by looping through all the values from config file | NULL, , char *,char *, char *, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call getWBctrl() -  Retrieve current White balance control with invalid input of Inputsrc, colurtemp and colour by looping through all the values from config file | char *, NULL  ,char *, char *, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call getWBctrl() -  Retrieve current White balance control with invalid input of Inputsrc, colurtemp and colour by looping through all the values from config file | char *, char *,NULL  , char *, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call getWBctrl() -  Retrieve current White balance control with invalid input of Inputsrc, colurtemp and colour by looping through all the values from config file | char *, char *,char *, NULL ,  int * | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call getWBctrl() -  Retrieve current White balance control with invalid input of Inputsrc, colurtemp and colour by looping through all the values from config file | char *, char *,char *, char *, NULL  | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 09 | call getWBctrl() -  Retrieve current TV WBctrl valid arguments | "HDMI", "normal", "red", "gain", int * | tvERROR_INVALID_STATE | Should Pass |
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
* | 03 | call GetSupportedComponentColor() -  Retrieve supported component colortemperature with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
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
* | 02 | call SetCurrentComponentSaturation() -  Set the TV component saturation by looping through all the values of saturation from config file| tvDataComponentColor_t  ,0 | tvERROR_NONE | Should Pass |
* | 03 | call SetCurrentComponentSaturation() -  Set the TV component saturation by looping through all the values of saturation from config file| tvDataComponentColor_t ,100 | tvERROR_NONE | Should Pass |
* | 04 | call SetCurrentComponentSaturation() -  Set the TV component saturation by looping through all the values of saturation from config file| tvDataComponentColor_t  ,50 | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetCurrentComponentSaturation() - Set the TV Current Component Saturation even before tvInit() | tvDataComponentColor_t ,  int | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetCurrentComponentSaturation() -  Set the TV Current Component Saturation with max range by looping through all the values from config file  | tvDataComponentColor_t,  101 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetCurrentComponentSaturation() -  Set the TV Current Component Saturation with less than the lower range by looping through all the values from config file | tvDataComponentColor_t,  -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetCurrentComponentSaturation() -  Set the TV Current Component Saturation with max range DataComponentColor| tvDataColor_MAX, 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetCurrentComponentSaturation() -  Set the TV Current Component Saturation with less than the lower range of DataComponentColor| -1, 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SetCurrentComponentSaturation() -  Set the TV Current Component Saturation with valid input after tvTerm() | tvDataComponentColor_t ,  int | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call GetCurrentComponentSaturation() -  Retrieve the current Component Saturation with valid arguments by looping through all the values of DataComponentColor from config file | tvDataComponentColor_t, int * | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call GetCurrentComponentSaturation() -  Retrieve current TV Component Saturation even before tvInit() | tvDataComponentColor_t, int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetCurrentComponentSaturation() -  Retrieve current TV component saturation with invalid input by looping through all the values of DataComponentColor from config file | tvDataComponentColor_t, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetCurrentComponentSaturation() -  Retrieve current TV component saturation with Max range of DataComponentColor | tvDataComponentColor_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetCurrentComponentSaturation() -  Retrieve current TV component saturation with less than lower range of DataComponentColor  | -1, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 02 | call SetCurrentComponentHue() -  Set the TV component hue by looping through all the values of component hue from config file| tvDataComponentColor_t , 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetCurrentComponentHue() -  Set the TV component hue by looping through all the values of component hue from config file| tvDataComponentColor_t , 100 | tvERROR_NONE | Should Pass |
* | 04 | call SetCurrentComponentHue() -  Set the TV component hue by looping through all the values of component hue from config file| tvDataComponentColor_t , 50 | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetCurrentComponentHue() -  Retrieve current TV Current Component Hue even before tvInit() | tvDataComponentColor_t, int | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetCurrentComponentHue() -  Set the TV Current Component Hue with max range by looping through all the values from config file | tvDataComponentColor_t,  101 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetCurrentComponentHue() -  Set the TV Current Component Hue with less than the lower range by looping through all the values from config file | tvDataComponentColor_t,  -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetCurrentComponentHue() -  Set the TV Current Component Hue with max range DataComponentColor| tvDataColor_MAX, 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetCurrentComponentHue() -  Set the TV Current Component Hue with less than the lower range of DataComponentColor| -1, 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SetCurrentComponentHue() -  Retrieve current TV Current Component Hue valid arguments | tvDataComponentColor_t, int | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call GetCurrentComponentHue() - Retrieve the current Component Hue with valid arguments by looping through all the values of DataComponentColor from config file | tvDataComponentColor_t, int * | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call GetCurrentComponentHue() -  Retrieve current TV brightness even before tvInit() |tvDataComponentColor_t, int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetCurrentComponentHue() -  Retrieve current TV component Hue with invalid input by looping through all the values of DataComponentColor from config file | tvDataComponentColor_t, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetCurrentComponentHue() -  Retrieve current TV component Hue with Max range of DataComponentColor | tvDataComponentColor_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetCurrentComponentHue() -  Retrieve current TV component Hue with less than lower range of DataComponentColor  | -1, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 02 | call SetCurrentComponentLuma() -  Set the TV component hue by looping through all the values of component Luma from config file| tvDataComponentColor_t , 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetCurrentComponentLuma() -  Set the TV component hue by looping through all the values of component Luma from config file| tvDataComponentColor_t , 100 | tvERROR_NONE | Should Pass |
* | 04 | call SetCurrentComponentLuma() -  Set the TV component hue by looping through all the values of component Luma from config file| tvDataComponentColor_t , 50 | tvERROR_NONE | Should Pass |* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetCurrentComponentLuma() -  Retrieve current TV Current Component Luma even before tvInit() | tvDataComponentColor_t, int | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetCurrentComponentLuma() -  Set the TV Current Component Luma with max range by looping through all the values from config file | tvDataComponentColor_t,  101 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetCurrentComponentLuma() -  Set the TV Current Component Luma with less than the lower range by looping through all the values from config file | tvDataComponentColor_t,  -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetCurrentComponentLuma() -  Set the TV Current Component Luma with max range DataComponentColor| tvDataColor_MAX, 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetCurrentComponentLuma() -  Set the TV Current Component Luma with less than the lower range of DataComponentColor| -1, 10 | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SetCurrentComponentLuma() -  Retrieve current TV Current Component Luma valid arguments | tvDataComponentColor_t, int | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call GetCurrentComponentLuma() - Retrieve the current Component Luma with valid arguments by looping through all the values of DataComponentColor from config file | tvDataComponentColor_t, int * | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 03 | call GetCurrentComponentLuma() -  Retrieve current TV component Luma with invalid input by looping through all the values of DataComponentColor from config file | tvDataComponentColor_t, NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetCurrentComponentLuma() -  Retrieve current TV component Luma with Max range of DataComponentColor | tvDataComponentColor_MAX, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetCurrentComponentLuma() -  Retrieve current TV component Luma with less than lower range of DataComponentColor  | -1, int * | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetCurrentComponentLuma() -  Retrieve current TV Current Component Luma valid arguments | tvDataColor_RED, int * | tvERROR_INVALID_STATE | Should Pass |
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
* | 03 | call GetTVSupportedDimmingModes() -  Retrieve supported TV dimming modes with invalid input | NULL,  unsigned short * | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetTVSupportedDimmingModes() -  Retrieve supported TV dimming modes with invalid input | char **,  NULL| tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call GetTVSupportedDimmingModes() -  Retrieve current TV Supported DimmingModes valid arguments | char **, unsigned short * | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call SetTVDimmingMode() -  Set the TV dimming mode by looping through all the values of dimming modes from the config file | const char * | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetTVDimmingMode() -  Retrieve current TV Dimming Mode even before tvInit() | const char * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetTVDimmingMode() -   Retrieve current TV Dimming Mode with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SetTVDimmingMode() -  Retrieve current TV Dimming Mode valid arguments | const char * | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call GetTVPictureModeIndex() -  Retrieve the current TV Picture ModeIndex with validate by looping through all the values of config file | const char * | tvPictureMode_t  | Should Pass |
* | 03 | call GetTVPictureModeIndex() -  Retrieve the current TV Picture ModeIndex with valid arguments and validate by looping through all the values of config file | const char * | tvPictureMode_t  | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetTVPictureModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

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
* | 01 | call GetTVPictureModeIndex() -  Retrieve current TV PictureMode Index even before tvInit() | const char * | tvPictureMode_t  | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetTVPictureModeIndex() -   Retrieve current TV PictureMode Index return value should not in config file | NULL | tvPictureMode_t  | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetTVPictureModeIndex() -  Retrieve current TVPictureMode Index valid arguments | const char * | tvPictureMode_t  | Should Pass |
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
* | 02 | call GetCurrentContentFormat() -  Retrieve the current ContentFormat with validate by looping through all the values in config file | void | tvVideoHDRFormat_t | Should Pass |
* | 03 | call GetCurrentContentFormat() -  Retrieve the current ContentFormat with valid arguments and validate by looping through all the values in config file | void | tvVideoHDRFormat_t | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetCurrentContentFormat (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

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
* | 01 | call GetCurrentContentFormat() -  Retrieve current TV ContentFormat even before tvInit() | void | tvVideoHDRFormat_t  | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetCurrentContentFormat() -  Retrieve current TV ContentFormat valid arguments | void | tvVideoHDRFormat_t  | Should Pass |
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
* | 02 | call SaveColorTemperature() -  Save the current Color Temperature with by looping through all the values of sourceId, pqmode, hdr_type and colourtemp from the config file | tv_source_input_t , int ,tvhdr_type_t ,tvColorTemp_t | tvERROR_NONE| Should Pass|
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SaveColorTemperature() -  Save the current Color Temperature even before tvInit() | tv_source_input_t , int ,tvhdr_type_t ,tvColorTemp_t | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveColorTemperature() -  Save current Color Temperature with invalid source input with max range| SOURCE_MAX, int ,tvhdr_type_t ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveColorTemperature() -  Save current Color Temperature with invalid source input less than the lower range| SOURCE_INVALID, int ,tvhdr_type_t ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveColorTemperature() -  Save current Color Temperature with invalid pqmode | tv_source_input_t, -1 ,tvhdr_type_t ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveColorTemperature() -  Save current Color Temperature with invalid hdr_type with max range| tv_source_input_t, int ,HDR_TYPE_MAX ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SaveColorTemperature() -  Save current Color Temperature with invalid hdr_type less than the lower range| tv_source_input_t, int , -1 ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SaveColorTemperature() -  Save current Color Temperature with invalid colourtemp with max range| tv_source_input_t, int , tvhdr_type_t ,tvColorTemp_MAX| tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call SaveColorTemperature() -  Save current Color Temperature with invalid colourtemp value less than the lower range| tv_source_input_t, int , tvhdr_type_t ,-1| tvERROR_INVALID_PARAM | Should Pass |
* | 10 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 11 | call SaveColorTemperature() -  Save the current Color Temperature valid arguments | HDMI, 0, HDR_TYPE_HLG, tvColorTemp_WARM | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call SaveBacklight() -  Save the current Color Backlight with by looping through all the values of sourceId, pqmode, hdr_type and colourtemp from the config file  |  tv_source_input_t , int ,tvhdr_type_t ,int | tvERROR_NONE| Should Pass|
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SaveBacklight() -  Retrieve current TV Backlight even before tvInit() |  tv_source_input_t, int , tvhdr_type_t ,int | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveBacklight() -  Save current Color Backlight with invalid source input with max range| SOURCE_MAX, int ,tvhdr_type_t ,int| tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveBacklight() -  Save current Color Backlight with invalid source input less than the lower range| SOURCE_INVALID, int ,tvhdr_type_t ,int| tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveBacklight() -  Save current Color Backlight with invalid pqmode | tv_source_input_t, -1 ,tvhdr_type_t ,int| tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveBacklight() -  Save current Color Backlight with invalid hdr_type with max range| tv_source_input_t, int ,HDR_TYPE_MAX ,int| tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SaveBacklight() -  Save current Color Backlight with invalid hdr_type less than the lower range| tv_source_input_t, int , -1 ,int| tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SaveBacklight() -  Save current Color Backlight with invalid value with max range| tv_source_input_t, int , tvhdr_type_t ,-1| tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call SaveBacklight() -  Save current Color Backlight with invalid value less than the lower range| tv_source_input_t, int , tvhdr_type_t ,101| tvERROR_INVALID_PARAM | Should Pass |
* | 10 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 11 | call SaveBacklight() -  Retrieve current TV Backlight valid arguments | tv_source_input_t, int , tvhdr_type_t ,int | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call SaveContrast() -  Save the current Color Contrast with by looping through all the values of sourceId, pqmode, hdr_type and colourtemp from the config file  |  tv_source_input_t , int ,tvhdr_type_t ,int | tvERROR_NONE| Should Pass|
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SaveContrast() -  save current TV Contrast even before tvInit() | tv_source_input_t, int , tvhdr_type_t ,int | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveContrast() -  Save current Color Contrast with invalid source input with max range| SOURCE_MAX, int ,tvhdr_type_t ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveContrast() -  Save current Color Contrast with invalid source input less than the lower range| SOURCE_INVALID, int ,tvhdr_type_t ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveContrast() -  Save current Color Contrast with invalid pqmode | tv_source_input_t, -1 ,tvhdr_type_t ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveContrast() -  Save current Color Contrast with invalid hdr_type with max range| tv_source_input_t, int ,HDR_TYPE_MAX ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SaveContrast() -  Save current Color Contrast with invalid hdr_type less than the lower range| tv_source_input_t, int , -1 ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SaveContrast() -  Save current Color Contrast with invalid value with with max range| tv_source_input_t, int , tvhdr_type_t ,101| tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call SaveContrast() -  Save current Color Contrast with invalid value with less than the lower range| tv_source_input_t, int , tvhdr_type_t ,-1| tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call SaveContrast() -  save current TV Contrast valid arguments | tv_source_input_t, int , tvhdr_type_t ,int | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call SaveSaturation() -  Save the current Color Saturation with by looping through all the values of sourceId, pqmode, hdr_type and colourtemp from the config file  |  tv_source_input_t , int ,tvhdr_type_t ,int | tvERROR_NONE| Should Pass|

* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SaveSaturation() -  save current TV Saturation even before tvInit() | tv_source_input_t, int , tvhdr_type_t ,int | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveSaturation() -  Save current Color Saturation with invalid source input with max range| SOURCE_MAX, int ,tvhdr_type_t ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveSaturation() -  Save current Color Saturation with invalid source input less than the lower range| SOURCE_INVALID, int ,tvhdr_type_t ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveSaturation() -  Save current Color Saturation with invalid pqmode | tv_source_input_t, -1 ,tvhdr_type_t ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveSaturation() -  Save current Color Saturation with invalid hdr_type with max range| tv_source_input_t, int ,HDR_TYPE_MAX ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SaveSaturation() -  Save current Color Saturation with invalid hdr_type less than the lower range| tv_source_input_t, int , -1 ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SaveSaturation() -  Save current Color Saturation with invalid value with max range| tv_source_input_t, int , tvhdr_type_t ,101| tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call SaveSaturation() -  Save current Color Saturation with invalid value with less than the lower range| tv_source_input_t, int , tvhdr_type_t ,-1| tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call SaveSaturation() -  save current TV Saturation valid arguments | tv_source_input_t, int , tvhdr_type_t ,int | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call SaveSharpness() -  Save the current Color Sharpness with by looping through all the values of sourceId, pqmode, hdr_type and colourtemp from the config file  |  tv_source_input_t , int ,tvhdr_type_t ,int | tvERROR_NONE| Should Pass|
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SaveSharpness() -  save current TV Sharpness even before tvInit() | tv_source_input_t, int , tvhdr_type_t ,int | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveSharpness() -  Save current Color Sharpness with invalid source input with max range| SOURCE_MAX, int ,tvhdr_type_t ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveSharpness() -  Save current Color Sharpness with invalid source input less than the lower range| SOURCE_INVALID, int ,tvhdr_type_t ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveSharpness() -  Save current Color Sharpness with invalid pqmode | tv_source_input_t, -1 ,tvhdr_type_t ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveSharpness() -  Save current Color Sharpness with invalid hdr_type with max range| tv_source_input_t, int ,HDR_TYPE_MAX ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SaveSharpness() -  Save current Color Sharpness with invalid hdr_type less than the lower range| tv_source_input_t, int , -1 ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SaveSharpness() -  Save current Color Sharpness with invalid value with max range| tv_source_input_t, int , tvhdr_type_t ,101| tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call SaveSharpness() -  Save current Color Sharpness with invalid value with less than the lower range| tv_source_input_t, int , tvhdr_type_t ,-1| tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call SaveSharpness() -  save current TV Sharpness valid arguments | tv_source_input_t, int , tvhdr_type_t ,int | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call SaveBrightness() -  Save the current Color Brightness with by looping through all the values of sourceId, pqmode, hdr_type and colourtemp from the config file  |  tv_source_input_t , int ,tvhdr_type_t ,int | tvERROR_NONE| Should Pass|
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 03 | call SaveBrightness() -  Save current Color Brightness with invalid source input with max range| SOURCE_MAX, int ,tvhdr_type_t ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveBrightness() -  Save current Color Brightness with invalid source input less than the lower range| SOURCE_INVALID, int ,tvhdr_type_t ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveBrightness() -  Save current Color Brightness with invalid pqmode | tv_source_input_t, -1 ,tvhdr_type_t ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveBrightness() -  Save current Color Brightness with invalid hdr_type with max range| tv_source_input_t, int ,HDR_TYPE_MAX ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SaveBrightness() -  Save current Color Brightness with invalid hdr_type less than the lower range| tv_source_input_t, int , -1 ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SaveBrightness() -  Save current Color Brightness with invalid value with max range| tv_source_input_t, int , tvhdr_type_t ,101| tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call SaveBrightness() -  Save current Color Brightness with invalid value with less than the lower range| tv_source_input_t, int , tvhdr_type_t ,-1| tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call SaveBrightness() -  save current TV Brightness valid arguments | HDMI, 3, HDR_TYPE_DOVI, 78 | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call SaveHue() -  Save the current Color Brightness with by looping through all the values of sourceId, pqmode, hdr_type and colourtemp from the config file  |  tv_source_input_t , int ,tvhdr_type_t ,int | tvERROR_NONE| Should Pass|* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SaveHue() -  save current TV Hue even before tvInit() |  tv_source_input_t , int ,tvhdr_type_t ,int | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveHue() -  Save current Color Hue with invalid source input with max range| SOURCE_MAX, int ,tvhdr_type_t ,int| tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveHue() -  Save current Color Hue with invalid source input less than the lower range| SOURCE_INVALID, int ,tvhdr_type_t ,int| tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveHue() -  Save current Color Hue with invalid pqmode | tv_source_input_t, -1 ,tvhdr_type_t ,int| tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveHue() -  Save current Color Hue with invalid hdr_type with max range| tv_source_input_t, int ,HDR_TYPE_MAX ,int| tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SaveHue() -  Save current Color Hue with invalid hdr_type less than the lower range| tv_source_input_t, int , -1 ,int| tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SaveHue() -  Save current Color Hue with invalid value with max range| tv_source_input_t, int , tvhdr_type_t ,101| tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call SaveHue() -  Save current Color Hue with invalid value with less than the lower range| tv_source_input_t, int , tvhdr_type_t ,-1| tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call SaveHue() -  save current TV Hue valid arguments |  tv_source_input_t , int ,tvhdr_type_t ,int | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call SaveDynamicBacklight() -  Save the current Color Brightness with by looping through all the values of sourceId, pqmode, hdr_type and colourtemp from the config file  |  tv_source_input_t , int ,tvhdr_type_t ,tvDimmingMode_t | tvERROR_NONE| Should Pass|
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SaveDynamicBacklight() -  save the DynamicBacklight even before tvInit() | tv_source_input_t , int ,tvhdr_type_t ,tvDimmingMode_t | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveDynamicBacklight() -  Save current Color DynamicBacklight with invalid source input with max range| SOURCE_MAX, int ,tvhdr_type_t ,tvDimmingMode_t| tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveDynamicBacklight() -  Save current Color DynamicBacklight with invalid source input less than the lower range| SOURCE_INVALID, int ,tvhdr_type_t ,tvDimmingMode_t| tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveDynamicBacklight() -  Save current Color DynamicBacklight with invalid pqmode | tv_source_input_t, -1 ,tvhdr_type_t ,tvDimmingMode_t| tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveDynamicBacklight() -  Save current Color DynamicBacklight with invalid hdr_type with max range| tv_source_input_t, int ,HDR_TYPE_MAX ,tvDimmingMode_t| tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SaveDynamicBacklight() -  Save current Color DynamicBacklight with invalid hdr_type less than the lower range| tv_source_input_t, int , -1 ,tvDimmingMode_t| tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SaveDynamicBacklight() -  Save current Color DynamicBacklight with invalid value with max range| tv_source_input_t, int , tvhdr_type_t ,3| tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call SaveDynamicBacklight() -  Save current Color DynamicBacklight with invalid value with less than the lower range| tv_source_input_t, int , tvhdr_type_t ,-1| tvERROR_INVALID_PARAM | Should Pass |
* | 10 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 11 | call SaveDynamicBacklight() -  save the DynamicBacklight valid arguments | tv_source_input_t , int ,tvhdr_type_t ,tvDimmingMode_t | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call SaveDisplayMode() -  Save the current Color DisplayMode with by looping through all the values of sourceId, pqmode, hdr_type and colourtemp from the config file  |  tv_source_input_t , int ,tvhdr_type_t ,tvDisplayMode_t | tvERROR_NONE| Should Pass|
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SaveDisplayMode() -  save the DisplayMode even before tvInit() | tv_source_input_t , int ,tvhdr_type_t ,tvDisplayMode_t | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveDisplayMode() -  Save current Color DisplayMode with invalid source input with max range| SOURCE_MAX, int ,tvhdr_type_t ,tvDisplayMode_t| tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveDisplayMode() -  Save current Color DisplayMode with invalid source input less than the lower range| SOURCE_INVALID, int ,tvhdr_type_t ,tvDisplayMode_t| tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveDisplayMode() -  Save current Color DisplayMode with invalid pqmode | tv_source_input_t, -1 ,tvhdr_type_t ,tvDisplayMode_t| tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveDisplayMode() -  Save current Color DisplayMode with invalid hdr_type with max range| tv_source_input_t, int ,HDR_TYPE_MAX ,tvDisplayMode_t| tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SaveDisplayMode() -  Save current Color DisplayMode with invalid hdr_type less than the lower range| tv_source_input_t, int , -1 ,tvDisplayMode_t| tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SaveDisplayMode() -  Save current Color DisplayMode with invalid value with max range| tv_source_input_t, int , tvhdr_type_t ,3| tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call SaveDisplayMode() -  Save current Color DisplayMode with invalid value with less than the lower range| tv_source_input_t, int , tvhdr_type_t ,-1| tvERROR_INVALID_PARAM | Should Pass |
* | 10 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 11 | call SaveDisplayMode() -  save the DisplayMode valid arguments | tv_source_input_t , int ,tvhdr_type_t ,tvDisplayMode_t | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call SaveCMS() -  Save the current CMS value with by looping through all the values of sourceId, pqmode, hdr_type and colourtemp from the config file  |  tv_source_input_t , int ,tvhdr_type_t ,tvCMS_tunel_t ,tvcomponent_color_type_t ,int | tvERROR_NONE| Should Pass|
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SaveCMS() -  save the CMS even before tvInit() |  tv_source_input_t , int ,tvhdr_type_t ,tvCMS_tunel_t ,tvcomponent_color_type_t ,int | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit()  -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveCMS() -  Save current CMS value by looping through all the invalid input from config file| tv_source_input_t , int ,tvhdr_type_t ,tvCMS_tunel_t ,tvcomponent_color_type_t ,int| tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm()  -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call SaveCMS() -  save the CMS valid arguments |  tv_source_input_t , int ,tvhdr_type_t ,tvCMS_tunel_t ,tvcomponent_color_type_t ,int| tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call SaveDolbyMode() -  Save the current DolbyMode with by looping through all the values of sourceId, pqmode, hdr_type and colourtemp from the config file  |  tv_source_input_t , int ,tvhdr_type_t ,int | tvERROR_NONE| Should Pass|* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |

* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SaveDolbyMode() -  save the DolbyMode even before tvInit() | tv_source_input_t, int ,tvhdr_type_t ,int | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveDolbyMode() -  Save current DolbyMode with invalid source input with max range| SOURCE_MAX, int ,tvhdr_type_t ,int| tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveDolbyMode() -  Save current DolbyMode with invalid source input less than the lower range| SOURCE_INVALID, int ,tvhdr_type_t ,int| tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveDolbyMode() -  Save current DolbyMode with invalid pqmode | tv_source_input_t, -1 ,tvhdr_type_t ,int| tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveDolbyMode() -  Save current DolbyMode with invalid hdr_type with max range| tv_source_input_t, int ,HDR_TYPE_MAX ,int| tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SaveDolbyMode() -  Save current DolbyMode with invalid hdr_type less than the lower range| tv_source_input_t, int , -1 ,int| tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SaveDolbyMode() -  Save current DolbyMode with invalid value with max range| tv_source_input_t, int , tvhdr_type_t ,101| tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call SaveDolbyMode() -  Save current DolbyMode with invalid value with less than the lower range| tv_source_input_t, int , tvhdr_type_t ,-1| tvERROR_INVALID_PARAM | Should Pass |
* | 10 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 11 | call SaveDolbyMode() -  save the DolbyMode valid arguments | tv_source_input_t, int ,tvhdr_type_t ,int | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call GetNumberOfModesupported() -  Retrieve the current Mode supported with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetNumberOfModesupported() -  Retrieve the current Mode supported with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetNumberOfModesupported (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

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
* | 01 | call GetNumberOfModesupported() -  Retrieve current Number Of TV Mode supported even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetNumberOfModesupported() -  Retrieve supported TV modes with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 05 | call GetNumberOfModesupported() -  Retrieve current Number Of TV Mode supported valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void| tvERROR_NONE | Should Pass |
* | 02 | call GetCurrentPQIndex() -  Retrieve the current PQIndex with valid arguments | int * | tvERROR_NONE | Should Pass |
* | 03 | call GetCurrentPQIndex() -  Retrieve the current PQIndex with valid arguments and validate with above value | int * | tvERROR_NONE | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetCurrentPQIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/*todo : there is no return error cases*/
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
* | 01 | call GetCurrentPQIndex() -  Retrieve current PQIndex even before tvInit() | int * | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetCurrentPQIndex() -  Retrieve current TV PQIndex with invalid input | NULL | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetCurrentPQIndex() -  Retrieve current PQIndex valid arguments | int * | tvERROR_INVALID_STATE | Should Pass |
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
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call GetAllSupportedPicModeIndex() -  Retrieve Supported PicModeIndex valid arguments | int [] | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call GetCMSDefault() -  Retrieve the CMS value by looping through the values | tvCMS_tunel_t | int | Should Pass |
* | 03 | call GetCMSDefault() -  Retrieve the CMS value by looping through the values and validate with above value | tvCMS_tunel_t  | int | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetCMSDefault (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

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
* | 01 | call GetCMSDefault() -  Retrieve current TV brightness even before tvInit() | tvCMS_tunel_t  | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call GetCMSDefault() -   Retrieve current TV brightness with invalid input | -1 | -1 | Should Pass |
* | 04 | call GetCMSDefault() -   Retrieve current TV brightness with invalid input | 4 | -1 | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call GetCMSDefault() -  Retrieve current TV brightness valid arguments | tvCMS_tunel_t  | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_GetCMSDefault (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/*todo : there is no return error cases*/
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
* | 03 | call GetDolbyModeIndex() -   Retrieve current TV Dolby ModeIndex with invalid input | NULL | -1 | Should Pass |
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
* | 02 | call SetCMSState() -  Set the CMSState with by looping through the all the values from config file | tvCMS_tunel_t ,tvcomponent_color_type_t ,tvcomponent_state_t | tvERROR_NONE | Should Pass |
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetCMSState() -  Set the TV CMS State even before tvInit() | tvCMS_tunel_t ,tvcomponent_color_type_t ,tvcomponent_state_t | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetCMSState() -  Set the current CMS State with invalid tunelType with less than lower range | -1, tvcomponent_color_type_t ,tvcomponent_state_t | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetCMSState() -  Set the current CMS State with invalid tunelType with Max range | 4 , tvcomponent_color_type_t ,tvcomponent_state_t | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetCMSState() -  Set the current CMS State with invalid colorType with less than lower range | tvCMS_tunel_t , -1 ,tvcomponent_state_t | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetCMSState() -  Set the current CMS State with invalid colorType with Max range | tvCMS_tunel_t , 7 ,tvcomponent_state_t | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SetCMSState() -  Set the current CMS State with invalid componentState less than lower range | tvCMS_tunel_t , tvcomponent_color_type_t ,-1 | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SetCMSState() -  Set the current CMS State with invalid componentState with Max range | tvCMS_tunel_t , tvcomponent_color_type_t ,3 | tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 10 | call SetCMSState() -  Set the TV CMS State with valid input after tvTerm() | tvCMS_tunel_t ,tvcomponent_color_type_t ,tvcomponent_state_t | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call SetColorTemperatureUser() -  Set the current Color Temperature User value by looping through all the values of rgbType | tvRGBType_t , int | tvERROR_NONE| Should Pass|
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetColorTemperatureUser() - Set the TV Color Temperature User even before tvInit() | tvRGBType_t , int | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetColorTemperatureUser() - Set the TV Color Temperature User with invalid value by looping through the gain config values | tvRGBType_t , -1 | tvERROR_INVALID_STATE | Should Pass |
* | 04 | call SetColorTemperatureUser() - Set the TV Color Temperature User with invalid value by looping through the gain config values | tvRGBType_t , 2048 | tvERROR_INVALID_STATE | Should Pass |
* | 05 | call SetColorTemperatureUser() - Set the TV Color Temperature User with invalid value by looping through the offset config values | tvRGBType_t , -1025 | tvERROR_INVALID_STATE | Should Pass |
* | 06 | call SetColorTemperatureUser() - Set the TV Color Temperature User with invalid value by looping through the offset config values | tvRGBType_t , 1025 | tvERROR_INVALID_STATE | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SetColorTemperatureUser() -  Set the TV Color Temperature User with valid input after tvTerm() | tvRGBType_t , int | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call SaveColorTemperature() -  Save the current Color Temperature with valid inputs by looping through all the values of config file  | tvRGBType_t , int  | tvERROR_NONE| Should Pass|
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 03 | call SaveColorTemperatureUser() - Save the TV Color Temperature User with invalid value by looping through the gain config values | tvRGBType_t , -1 | tvERROR_INVALID_STATE | Should Pass |
* | 04 | call SaveColorTemperatureUser() - Save the TV Color Temperature User with invalid value by looping through the gain config values | tvRGBType_t , 2048 | tvERROR_INVALID_STATE | Should Pass |
* | 05 | call SaveColorTemperatureUser() - Save the TV Color Temperature User with invalid value by looping through the offset config values | tvRGBType_t , -1025 | tvERROR_INVALID_STATE | Should Pass |
* | 06 | call SaveColorTemperatureUser() - Save the TV Color Temperature User with invalid value by looping through the offset config values | tvRGBType_t , 1025 | tvERROR_INVALID_STATE | Should Pass |
* | 03 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 04 | call SaveColorTemperatureUser() -  Save the TV Color Temperature User with valid input after tvTerm() | 50 | tvERROR_INVALID_STATE | Should Pass |
*/
void test_l1_tvSettings_negative_SaveColorTemperatureUser (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

/*todo : there is no return error cases*/
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
* | 02 | call GetHLGModeIndex() -  Retrieve the current HLGModeIndex with valid arguments | const char * | int | Should Pass |
* | 03 | call GetHLGModeIndex() -  Retrieve the current HLGModeIndex with valid arguments and validate with above value | const char * | int | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetHLGModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

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
* | 03 | call GetHLGModeIndex() -   Retrieve current TV HLGModeIndex with invalid input | NULL | -1 | Should Pass |
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
* | 02 | call GetHDR10ModeIndex() -  Retrieve the current HDR10 ModeIndex with valid arguments | const char * | int | Should Pass |
* | 03 | call GetHDR10ModeIndex() -  Retrieve the current HDR10 ModeIndex with valid arguments and validate with above value | const char * | int | Should Pass |
* | 04 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
*/
void test_l1_tvSettings_positive_GetHDR10ModeIndex (void)
{
	UT_FAIL(This function needs to be implemented!); 
}

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
* | 03 | call GetHDR10ModeIndex() -   Retrieve current TV HDR10 ModeIndex with invalid input | NULL | -1 | Should Pass |
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
* | 02 | call SetBacklightFade() -  Set the BacklightFade with valid inputs | 0, 0, 0 | tvERROR_NONE| Should Pass|
* | 03 | call SetBacklightFade() -  Set the BacklightFade with valid inputs | 50, 50, 5000 | tvERROR_NONE| Should Pass|
* | 04 | call SetBacklightFade() -  Set the BacklightFade with valid inputs | 100, 100, 10000 | tvERROR_NONE| Should Pass|
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
* | 01 | call SetBacklightFade() - Set the TV  Backlight Fade value even before tvInit() | int, int, int | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SetBacklightFade() -   Set the TV  Backlight Fade value with invalid input | -1, -1, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetBacklightFade() -   Set the TV  Backlight Fade value with invalid input | 101, 101, 100001 | tvERROR_INVALID_PARAM | Should Pass |
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
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 02 | call SetGammaMode() -  Set the Gamma Mode with valid value | 00 | tvERROR_NONE | Should Pass |
* | 03 | call SetGammaMode() -  Reset the Gamma Mode with another valid value | 01 | tvERROR_NONE | Should Pass |
* | 04 | call SetGammaMode() -  Reset the Gamma Mode with another valid value | 00 | tvERROR_NONE | Should Pass |
* | 05 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SetGammaMode() -   Set the TV GammaMode with invalid input | -1 | tvERROR_INVALID_STATE | Should Pass |
* | 01 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 01 | call SetGammaMode() -   Set the TV GammaMode with invalid input | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 02 | call SetGammaMode() -   Set the TV GammaMode with invalid input | 256 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 01 | call SetGammaMode() -   Set the TV GammaMode with invalid input | -1 | tvERROR_INVALID_STATE | Should Pass |
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
* | 03 | call SetLocalDimmingLevel() -  Reset the Local DimmingLevel with another valid value | 1 | tvERROR_NONE | Should Pass |
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
* | 02 | call SaveLocalDimmingLevel() -  Save the current LocalDimming Level with by looping through all the values of sourceId, pqmode, hdr_type and colourtemp from the config file  |  tv_source_input_t , int ,tvhdr_type_t ,int | tvERROR_NONE| Should Pass|
* | 03 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 01 | call SaveLocalDimmingLevel() -  save current Local DimmingLevel even before tvInit() | tv_source_input_t, int , tvhdr_type_t ,int | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveLocalDimmingLevel() -  Save current LocalDimming Level with invalid source input with max range| SOURCE_MAX, int ,tvhdr_type_t ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveLocalDimmingLevel() -  Save current LocalDimming Level with invalid source input less than the lower range| SOURCE_INVALID, int ,tvhdr_type_t ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveLocalDimmingLevel() -  Save current LocalDimming Level with invalid pqmode | tv_source_input_t, -1 ,tvhdr_type_t ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveLocalDimmingLevel() -  Save current LocalDimming Level with invalid hdr_type with max range| tv_source_input_t, int ,HDR_TYPE_MAX ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SaveLocalDimmingLevel() -  Save current LocalDimming Level with invalid hdr_type less than the lower range| tv_source_input_t, int , -1 ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SaveLocalDimmingLevel() -  Save current LocalDimming Level with invalid value with max range| tv_source_input_t, int , tvhdr_type_t ,101| tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call SaveLocalDimmingLevel() -  Save current LocalDimming Level with invalid value with less than the lower range| tv_source_input_t, int , tvhdr_type_t ,-1| tvERROR_INVALID_PARAM | Should Pass |
* | 10 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 11 | call SaveLocalDimmingLevel() -  save current Local DimmingLevel valid arguments | tv_source_input_t, int , tvhdr_type_t ,int | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call SaveLowLatencyState() -  Save the current LowLatency State with by looping through all the values of sourceId, pqmode, hdr_type and colourtemp from the config file  |  tv_source_input_t , int ,tvhdr_type_t ,int | tvERROR_NONE| Should Pass|

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
* | 01 | call SaveLowLatencyState() -  save current TV LowLatency even before tvInit() | tv_source_input_t, int , tvhdr_type_t ,int | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveLowLatencyState() -  Save current LowLatency State with invalid source input with max range| SOURCE_MAX, int ,tvhdr_type_t ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveLowLatencyState() -  Save current LowLatency State with invalid source input less than the lower range| SOURCE_INVALID, int ,tvhdr_type_t ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveLowLatencyState() -  Save current LowLatency State with invalid pqmode | tv_source_input_t, -1 ,tvhdr_type_t ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveLowLatencyState() -  Save current LowLatency State with invalid hdr_type with max range| tv_source_input_t, int ,HDR_TYPE_MAX ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SaveLowLatencyState() -  Save current LowLatency State with invalid hdr_type less than the lower range| tv_source_input_t, int , -1 ,tvColorTemp_t| tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call SaveLowLatencyState() -  Save current LowLatency State with invalid value with max range| tv_source_input_t, int , tvhdr_type_t ,101| tvERROR_INVALID_PARAM | Should Pass |
* | 09 | call SaveLowLatencyState() -  Save current LowLatency State with invalid value with less than the lower range| tv_source_input_t, int , tvhdr_type_t ,-1| tvERROR_INVALID_PARAM | Should Pass |

* | 10 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 11 | call SaveLowLatencyState() -  save current TV Contrast valid arguments | tv_source_input_t, int , tvhdr_type_t ,int | tvERROR_INVALID_STATE | Should Pass |
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
* | 03 | call SetLowLatencyState() -   Set the TV LowLatency State with invalid input with less than lower range | -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetLowLatencyState() -   Set the TV LowLatency State with invalid input with max range | 2 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 06 | call SetLowLatencyState() -  Set the TV LowLatency State with valid input after tvTerm() | 1 | tvERROR_INVALID_STATE | Should Pass |
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
* | 03 | call SetGammaTable() -   Set the TV GammaTable State with invalid input | NULL, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SetGammaTable() -   Set the TV GammaTable State with invalid input | unsigned short *, NULL, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SetGammaTable() -   Set the TV GammaTable State with invalid input | unsigned short *, unsigned short *, NULL, 256| tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SetGammaTable() -   Set the TV GammaTable State with invalid input | unsigned short *, unsigned short *, unsigned short *, 0| tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 08 | call SetGammaTable() -  Set the TV LowLatency State with valid input after tvTerm() | unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_STATE | Should Pass |
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
* | 03 | call GetGammaTable() -   Retrieve current TV GammaTable State with invalid input by looping through the colourtemp from config file | int ,  NULL,  unsigned short *,  unsigned short *, int | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call GetGammaTable() -   Retrieve current TV GammaTable State with invalid input by looping through the colourtemp from config file | int , unsigned short *,  NULL, unsigned short *, int | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call GetGammaTable() -   Retrieve current TV GammaTable State with invalid input by looping through the colourtemp from config file | int , unsigned short *,  unsigned short *, NULL,  int | tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call GetGammaTable() -   Retrieve current TV GammaTable State with invalid colourtemp with max range | tvColorTemp_MAX , unsigned short *,  unsigned short *, unsigned short *,  int | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call GetGammaTable() -   Retrieve current TV GammaTable State with invalid colourtemp  less than lower range| -1 , unsigned short *,  unsigned short *, unsigned short *,  int | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 09 | call GetGammaTable() -  Retrieve current TV GammaTable State valid arguments |int ,  unsigned short *,  unsigned short *,  unsigned short *, intint ,  unsigned short *,  unsigned short *,  unsigned short *, int | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call SaveGammaTable() -  save the current GammaTable State with valid arguments by looping through the colourtemp from config file| int , unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_NONE | Should Pass |
* | 03 | call SaveGammaTable() -  save the current GammaTable State with valid arguments and validate with above value by looping through the colourtemp from config file | int , unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_NONE | Should Pass |
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
* | 01 | call SaveGammaTable() - save the current GammaTable State even before tvInit() | int, unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_STATE | Should Pass |
* | 02 | call tvInit() -  Initialise and get a valid instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 03 | call SaveGammaTable() -   save the current GammaTable State with invalid input by looping through the colourtemp from config file| int, NULL, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
* | 04 | call SaveGammaTable() -   save the current GammaTable State with invalid input by looping through the colourtemp from config file| int, unsigned short *, NULL, unsigned short *, 256 | tvERROR_INVALID_PARAM | Should Pass |
* | 05 | call SaveGammaTable() -   save the current GammaTable State with invalid input by looping through the colourtemp from config file| int, unsigned short *, unsigned short *, NULL, 256| tvERROR_INVALID_PARAM | Should Pass |
* | 06 | call SaveGammaTable() -   save the current GammaTable State with invalid colourtemp with max range | tvColorTemp_MAX , unsigned short *,  unsigned short *, unsigned short *,  int | tvERROR_INVALID_PARAM | Should Pass |
* | 07 | call SaveGammaTable() -   save the current GammaTable State with invalid colourtemp  less than lower range| -1 , unsigned short *,  unsigned short *, unsigned short *,  int | tvERROR_INVALID_PARAM | Should Pass |
* | 08 | call tvTerm() - Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
* | 09 | call SaveGammaTable() -  Set the TV LowLatency State with valid input after tvTerm() | int, unsigned short *, unsigned short *, unsigned short *, 256 | tvERROR_INVALID_STATE | Should Pass |
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
* | 02 | call SetGammaPattern() -  Set the GammaPattern with valid arguments | 0 ,0, 0, 0 | tvERROR_NONE | Should Pass |
* | 03 | call SetGammaPattern() -  Set the GammaPattern with valid arguments | 0 ,500, 500, 500 | tvERROR_NONE | Should Pass |
* | 04 | call SetGammaPattern() -  Set the GammaPattern with valid arguments | 0 ,1023, 1023, 1023 | tvERROR_NONE | Should Pass |
* | 05 | call SetGammaPattern() -  Set the GammaPattern with valid arguments | 1 ,0, 0, 0 | tvERROR_NONE | Should Pass |
* | 06 | call SetGammaPattern() -  Set the GammaPattern with valid arguments | 1 ,1023, 1023, 1023 | tvERROR_NONE | Should Pass |
* | 07 | call tvTerm() -  Terminate and close the instance of the TV client | void | tvERROR_NONE | Should Pass |
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
* | 03 | call SetGammaPattern() -   Set the GammaPattern with invalid input of RGB value| -1 ,-1, -1, -1 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetGammaPattern() -   Set the GammaPattern with invalid input of RGB value | -1 ,1025, 1025, 1025 | tvERROR_INVALID_PARAM | Should Pass |
* | 03 | call SetGammaPattern() -   Set the GammaPattern with invalid input of is_10_bit  | 2 , 0, 0, 0 | tvERROR_INVALID_PARAM | Should Pass |
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
