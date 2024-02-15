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
 * @addtogroup TV_Settings TV Settings Module
 * @par Application API Specification
 * Described herein are the TV Settings HAL types and functions that are part of
 * the Host subsystem. The Host subsystem manages system-specific HAL operations.
 * @{
 */

/**
* @addtogroup TV_Settings_HAL TV Settings HALTEST
* @par Application API Specification
* TvSettings HAL provides an interface for managing the TV settings for the TV settings module
* @{
*/

/**
* @defgroup TV_Settings_HALTEST TV Settings HAL Test Cases
* @{
*/

/**
 * @file test_register.c
 * @page TV_Settings_HALTEST  
 *
 * ## Module's Role
 * This module includes Level 1 and 2 functional tests (success and failure scenarios).
 * This is to ensure that the API meets the operational requirements of the TV SETTINGS across all vendors.
 *
 * **Pre-Conditions:**  None@n
 * **Dependencies:** None@n
 *
 * Ref to API Definition specification documentation : [tv-settings_halSpec.md](../../../docs/tv-settings_halSpec.md)
 */

#include <ut.h>

/**
 * @brief Register test functionality
 * 
 */

/* L1 Testing Functions */
extern int test_l1_tvSettings_register( void );


int UT_register_APIDEF_l1_tests( void )
{
	int registerFailed=0;

	registerFailed |= test_l1_tvSettings_register();

	return registerFailed;
}
/** @} */ // End of TV_Settings_HALTEST
/** @} */ // End of TV_Settings_HAL
/** @} */ // End of TV_Settings
/** @} */ // End of HPK
