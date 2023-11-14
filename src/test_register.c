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
* @defgroup TV_Settings_HALTEST_REGISTER TV Settings HAL Test's Registration
* @{
**/

#include <ut.h>

/**
 * @brief Register test functionality
 * 
 */

/* L1 Testing Functions */
extern int test_l1_tvSettings_register( void );


/* L2 Testing Functions */
extern int test_l2_tvSettings_register( void );

int UT_register_APIDEF_l1_tests( void )
{
	int registerFailed=0;

	registerFailed |= test_l1_tvSettings_register();

	return registerFailed;
}

/* Register UT Functions */
int UT_register_APIDEF_l2_tests( void )
{
	int registerFailed=0;

	registerFailed |= test_l2_tvSettings_register();

	return registerFailed;
}

/** @} */ // End of TV_Settings_HALTEST_REGISTER
/** @} */ // End of TV_Settings_HALTEST
/** @} */ // End of TV_Settings
/** @} */ // End of HPK
