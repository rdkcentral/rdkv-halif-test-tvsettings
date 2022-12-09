/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2016 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

#include <stddef.h>
#include <tv_settings_hal.h>
#include <ut.h>

#define INFO_UT(text, ...) do {\
printf("TV-SET-HAL-UT-L2: %s[%d] - %s: " text, __FUNCTION__, __LINE__, "INFO", ##__VA_ARGS__);}while(0);

void test_generic_L2_SetCMSState( void )
{
    tvError_t result;
    tvCMS_tunel_t tunelType = COLOR_STATE;
    tvcomponent_color_type_t colorType = COLOR_ENABLE;
    tvcomponent_state_t componentState = COMPONENT_DISABLE;

    /* Simulate failure case  */

    tvTerm();

    /* Failure Case - i.e since already intialized */
    result = SetCMSState(tunelType,colorType,componentState);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE );
    INFO_UT(" T2: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);    

}

void test_generic_L2_SaveColorTemperatureUser( void )
{
    tvError_t result;
    int rgbType;
    int value;

   /* Simulate failure case  */

    tvTerm();

    /* Failure Case with proper value */
    rgbType=R_GAIN;
    value =0;
    result = SaveColorTemperatureUser(rgbType,value);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL );
    INFO_UT(" T17: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

}


void test_generic_L2_SetColorTemperatureUser( void )
{
    tvError_t result;
    int rgbType;
    int value;

    /* Success Case  */
    rgbType=R_GAIN;
    value =0;

   /* Simulate failure case with proper value */

    tvTerm();
 
    result = SetColorTemperatureUser(rgbType,value);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL );
    INFO_UT(" T19: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

}

void test_generic_L2_GetTVSupportedHLGModes( void )
{
    tvError_t result;
    pic_modes_t *hlgModes[DV_MODES_SUPPORTED_MAX];
    unsigned short count =0;
 /* Simulate failure case with proper value */
    tvTerm();
    count = 0;
     result = GetTVSupportedHLGModes(hlgModes,&count);
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    INFO_UT(" T23: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

}


void test_generic_L2_SetLocalDimmingLevel( void )
{
    tvError_t result;
    int localDimmingLevel = 1;

  /* Simulate failure case with proper value */
    tvTerm();
    localDimmingLevel = 1;
    result = SetLocalDimmingLevel(localDimmingLevel); 
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE );
    INFO_UT(" T22: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
  
}

void test_generic_L2_GetLocalDimmingLevel( void )
{
    tvError_t result;
    int localDimmingLevel = 1;

    /* Success Case  */
    tvTerm();
    result = GetLocalDimmingLevel(&localDimmingLevel); 
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE );
    INFO_UT(" T22: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
  
}

void test_generic_L2_SaveLocalDimmingLevel( void )
{
    tvError_t result;
    int sourceInput, pq_mode, hdr_type, value;

    /* Success Case  */
    sourceInput = 0;
    pq_mode = 0;
    hdr_type = HDR_TYPE_SDR;
    value = 0;
    tvTerm();
    result = SaveLocalDimmingLevel(sourceInput,pq_mode,hdr_type,value); 
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE );
    INFO_UT(" T22: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
 
  
}

void test_generic_L2_UpdateEDIDAndSetDimmingLevel( void )
{
    tvError_t result = tvERROR_NONE;
    int mode = 1;

    /*TODO: need to handle return type   */
    tvTerm();
    result = UpdateEDIDAndSetDimmingLevel(mode); 
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE );
    INFO_UT(" T22: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

/**
 * @brief Init the test system
 * 
 * @return int - 0 on success, otherwise failure
 */
int test_TvSettings_hal_init(void)
{
    return 0;
}

/**
 * @brief Clean the test system
 * 
 * @return int - 0 on success, otherwise failure
 */
int test_TvSettings_hal_clean(void)
{
    return 0;
}

/**
 * @brief Register the main tests for this module
 * 
 * @return int - 0 on success, otherwise failure
 */
int test_TvSettings_hal_l2_register( void )
{
    /* add a suite to the registry */
    UT_test_suite_t *pSuite = NULL;
    pSuite = UT_add_suite("[L2 test_TvSettings_hal]", &test_TvSettings_hal_init, &test_TvSettings_hal_clean);
    if (NULL == pSuite) 
    {
        return -1;
    }
    
    UT_add_test( pSuite, "SetCMSState", test_generic_L2_SetCMSState);
    UT_add_test( pSuite, "SaveColorTemperatureUser", test_generic_L2_SaveColorTemperatureUser);
    UT_add_test( pSuite, "SetColorTemperatureUser", test_generic_L2_SetColorTemperatureUser);
    UT_add_test( pSuite, "GetTVSupportedHLGModes", test_generic_L2_GetTVSupportedHLGModes);
    UT_add_test( pSuite, "SetLocalDimmingLevel", test_generic_L2_SetLocalDimmingLevel);
    UT_add_test( pSuite, "GetLocalDimmingLevel", test_generic_L2_GetLocalDimmingLevel);
    UT_add_test( pSuite, "SaveLocalDimmingLevel", test_generic_L2_SaveLocalDimmingLevel);
    UT_add_test( pSuite, "SetDimmingLevel", test_generic_L2_UpdateEDIDAndSetDimmingLevel);

    return 0;
}

