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

// For level2 testing analysis
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

#if DELETE
void test_wifi_hal_L2_setValidSSID_2Ghz(void)
{
    INT ap_index = 0; 
    INT radioIndex = 0;
    INT ap_pointing_index = 0;
    int result;

    result = test_utils_setValidSSID(radioIndex, ap_index, ap_pointing_index);
    UT_ASSERT_EQUAL( result, WIFI_HAL_SUCCESS );
    return;
}

void test_wifi_hal_L2_setInValidIndexSSID_2Ghz(void)
{
    INT ap_index = 25; /* Invalid Index */
    INT radioIndex = 0;
    INT ap_pointing_index = 0;
    int result;
    result = test_utils_setInValidIndexSSID(radioIndex, ap_index, ap_pointing_index);
    UT_ASSERT_EQUAL( result, WIFI_HAL_INVALID_ARGUMENTS);
    return;
}

void test_wifi_hal_L2_setNULLSSID_2Ghz(void)
{

    INT ap_index = 0;
    INT radioIndex = 0;
    INT ap_pointing_index = 0;
    int result;

    result = test_utils_setNULLSSID(radioIndex, ap_index, ap_pointing_index);
    UT_ASSERT_EQUAL( result, WIFI_HAL_ERROR);
}

void test_wifi_hal_L2_setValidSSID_5Ghz(void)
{
    INT ap_index = 1;
    INT radioIndex = 1;
    INT ap_pointing_index = 0;
    int result;

    result = test_utils_setValidSSID(radioIndex, ap_index, ap_pointing_index);
    UT_ASSERT_EQUAL( result, WIFI_HAL_SUCCESS );
    return;
}

void test_wifi_hal_L2_setInValidIndexSSID_5Ghz(void)
{
    INT ap_index = 25; /* Invalid Index */
    INT radioIndex = 1;
    INT ap_pointing_index = 0;
    int result;
    result = test_utils_setInValidIndexSSID(radioIndex, ap_index, ap_pointing_index);
    UT_ASSERT_EQUAL( result, WIFI_HAL_INVALID_ARGUMENTS);
    return;
}

void test_wifi_hal_L2_setNULLSSID_5Ghz(void)
{

    INT ap_index = 1;
    INT radioIndex = 1;
    INT ap_pointing_index = 0;
    int result;

    result = test_utils_setNULLSSID(radioIndex, ap_index, ap_pointing_index);
    UT_ASSERT_EQUAL( result, WIFI_HAL_ERROR);
}

void test_wifi_hal_L2_setValidSSID_6Ghz(void)
{
    INT ap_index = 16;
    INT radioIndex = 2;
    INT ap_pointing_index = 0;
    int result;

    result = test_utils_setValidSSID(radioIndex, ap_index, ap_pointing_index);
    UT_ASSERT_EQUAL( result, WIFI_HAL_SUCCESS );
    return;
}

void test_wifi_hal_L2_setInValidIndexSSID_6Ghz(void)
{
    INT ap_index = 25; /* Invalid Index */
    INT radioIndex = 2;
    INT ap_pointing_index = 0;
    int result;
    result = test_utils_setInValidIndexSSID(radioIndex, ap_index, ap_pointing_index);
    UT_ASSERT_EQUAL( result, WIFI_HAL_INVALID_ARGUMENTS);
    return;
}

void test_wifi_hal_L2_setNULLSSID_6Ghz(void)
{

    INT ap_index = 16;
    INT radioIndex = 2;
    INT ap_pointing_index = 0;
    int result;

    result = test_utils_setNULLSSID(radioIndex, ap_index, ap_pointing_index);
    UT_ASSERT_EQUAL( result, WIFI_HAL_ERROR);
}

/* This will test AP Enable/Disable functionality*
* positive case * maps to WIFI_HAL_SUCCESS *
* set main interface AP to disable first and check it through get *
* now set it to enable and check it through get *
* virtaul/guest Enable/Disable set check is not added yet
*
* Negative case * WIFI_HAL_ERROR *
* Try to Enable AP  with wrong AP indexes * Here 25,26,27 are taken as wrong indeces */

#if 0
void test_wifi_hal_L2_setApDisable_2GHz(void)
{
    int result;
    int ap_index = 0;
    BOOL enable;

    /* Positive case */
    /* Disable the APs */
    enable = FALSE;
    result = test_utils_setApEnable (enable, ap_index);
    UT_ASSERT_EQUAL( result, WIFI_HAL_SUCCESS);
    return;
}

void test_wifi_hal_L2_setApDisable_5GHz(void)
{
    int result;
    int ap_index = 1;
    BOOL enable;

    /* Positive case */
    /* Disable the APs */
    enable = FALSE;
    result = test_utils_setApEnable (enable, ap_index);
    UT_ASSERT_EQUAL( result, WIFI_HAL_SUCCESS);
    return;
}

void test_wifi_hal_L2_setApDisable_6GHz(void)
{
    int result;
    int ap_index = 16;
    BOOL enable;

    /* Positive case */
    /* Disable the APs */
    enable = FALSE;
    result = test_utils_setApEnable (enable, ap_index);
    UT_ASSERT_EQUAL( result, WIFI_HAL_SUCCESS);
    return;
}

void test_wifi_hal_L2_setApEnable_2GHz(void)
{
    /* Positive case */
    /* Enable the APs */
    int result;
    int ap_index = 0;
    BOOL enable = TRUE;
    result = test_utils_setApEnable (enable, ap_index);
    UT_ASSERT_EQUAL( result, WIFI_HAL_SUCCESS);
    return;
}

void test_wifi_hal_L2_setApEnable_5GHz(void)
{
    /* Positive case */
    /* Enable the APs */
    int result;
    int ap_index = 1;
    BOOL enable = TRUE;
    result = test_utils_setApEnable (enable, ap_index);
    UT_ASSERT_EQUAL( result, WIFI_HAL_SUCCESS);
    return;
}

void test_wifi_hal_L2_setApEnable_6GHz(void)
{
    /* Positive case */
    /* Enable the APs */
    int result;
    int ap_index = 16;
    BOOL enable = TRUE;
    result = test_utils_setApEnable (enable, ap_index);
    UT_ASSERT_EQUAL( result, WIFI_HAL_SUCCESS);
    return;
}

void test_wifi_hal_L2_setInvalidIndexApDisable(void)
{
    /* Negative case */
    /* Enable  the APs  with wrong index */
    int ap_index=25;
    BOOL enable = FALSE;
    int result;

    result = test_utils_setApEnable (enable, ap_index);
    UT_ASSERT_EQUAL( result, WIFI_HAL_ERROR);

    /* Done */
    return;
}

void test_wifi_hal_L2_setInvalidIndexApEnable(void)
{
    /* Negative case */
    /* Enable  the APs  with wrong index */
    int ap_index=25;
    BOOL enable = TRUE;
    int result;

    result = test_utils_setApEnable (enable, ap_index);
    UT_ASSERT_EQUAL( result, WIFI_HAL_ERROR);

    /* Done */
    return;
}

/* This will test Radio Channel push functionality*
* positive case * maps to WIFI_HAL_SUCCESS *
* set Radios to valid channel and check the value through get*
*
* Negative case * WIFI_HAL_SUCCESS, WIFI_HAL_INVALID_ARGUMENTS *
* Set Radios Invalid Channel *
* Set the channel with wrong radio index *
*/
void test_wifi_L2_Validchannel_push_2GHz(void)
{
    /* set 2.4 GHz channel first */

    /* Positive */
    /* Set it for a valid channel e.g 13 */
    /* Available Channels in 2.4GHz 1,2,3,4,5,6,7,8,9,10,11,12,13 */
    INT radioIndex = 0;
    ULONG channel = 13;
    INT result;

    result = test_utils_channelPush(radioIndex, channel);
    UT_ASSERT_EQUAL( result, WIFI_HAL_SUCCESS);
    return;
}

void test_wifi_L2_InValidchannel_push_2GHz(void)
{

    /* Negative */
    /* Set it for Invalid Channel */
    INT radioIndex = 0;
    ULONG channel = 25;
    INT result;

    result = test_utils_channelPush(radioIndex, channel);
    UT_ASSERT_EQUAL( result, WIFI_HAL_ERROR);
    return;
}

void test_wifi_L2_InValidIndex_channel_push_2GHz(void)
{
    /* Negative */
    /* set it with wrong radio index */
    INT radioIndex = 0;
    ULONG channel = 25;
    INT result;

    radioIndex = 5;
    channel = 13;
    result = test_utils_channelPush(radioIndex, channel);
    UT_ASSERT_EQUAL( result, WIFI_HAL_INVALID_ARGUMENTS);
    return;
}


void test_wifi_L2_Validchannel_push_5GHz(void)
{
    /* set 5 Ghz channel */
    /* Positive */
    /* Set it for a valid channel e.g 149 */ /* selected channel with all bandwidth capable 20/40/80/160 */
    /* Available Channels in 5 GHz NON DFS 36,40,44,48,149,153,157,161,165 */
    INT radioIndex = 1;
    ULONG channel = 149;
    INT result;

    result = test_utils_channelPush(radioIndex, channel);
    UT_ASSERT_EQUAL( result, WIFI_HAL_SUCCESS);
    return;
}

void test_wifi_L2_InValidchannel_push_5GHz(void)
{
    /* Negative */
    /* Set it for Invalid Channel */
    ULONG channel = 178;
    INT radioIndex = 1;
    INT result;

    result = test_utils_channelPush(radioIndex, channel);
    UT_ASSERT_EQUAL( result, WIFI_HAL_ERROR);
    return;
}

void test_wifi_L2_InValidIndex_channel_push_5GHz(void)
{
    /* Negative */
    INT radioIndex = 5;
    ULONG channel = 149;
    INT result;

    result = test_utils_channelPush(radioIndex, channel);
    UT_ASSERT_EQUAL( result, WIFI_HAL_INVALID_ARGUMENTS);
    return;
}

void test_wifi_L2_Validchannel_push_6GHz(void)
{
    /* set 6 Ghz channel */
    /* Positive */
    /* Set it for a valid channel e.g 1 */
    /* Available Channels in 6 GHz  1,5,9,13,17,21,25,29,33,37,41,45,49,53,57,61,65,69,73,77,81,85,89,93  */
    INT radioIndex = 2;
    ULONG channel = 1;
    INT result;

    result = test_utils_channelPush(radioIndex, channel);
    UT_ASSERT_EQUAL( result, WIFI_HAL_SUCCESS);
    return;
}

void test_wifi_L2_InValidchannel_push_6GHz(void)
{
    /* Negative */
    /* Set it for Invalid Channel */
    ULONG channel = 178;
    INT radioIndex =2;
    INT result;
    result = test_utils_channelPush(radioIndex, channel);
    UT_ASSERT_EQUAL( result, WIFI_HAL_ERROR);
    return;
}

void test_wifi_L2_InValidIndex_channel_push_6GHz(void)
{
    /* Negative */
    INT radioIndex = 5;
    ULONG channel = 1;
    INT result;

    result = test_utils_channelPush(radioIndex, channel);
    UT_ASSERT_EQUAL( result, WIFI_HAL_INVALID_ARGUMENTS);
    return;
}

/* This will test Radio bandwidth set functionality*
* positive case * maps to WIFI_HAL_SUCCESS*
* set Radios to valid bandwidth and check the value through get*
*
* Negative case * WIFI_HAL_ERROR, WIFI_HAL_INVALID_ARGUMENTS *
* Set Radios Invalid bandwidth *
* Set the bandwidth with wrong radio index *
* Set the bandwidth to NULL *
*/
void test_wifi_L2_set_valid_bandwidth_2Ghz_40MHz(void)
{
    /* set 2.4 GHz bandwidth first */

    /* Positive */
    /* Set it for a valid bandwidth */
    /* Available Channels in 2.4GHz is 20 Mhz, 40 Mhz */
    INT radioIndex = 0;
    UINT bandwidth;
    INT result;

    bandwidth = WIFI_CHANNELBANDWIDTH_40MHZ;
    result = test_utils_setBandwidth(radioIndex, bandwidth);
    UT_ASSERT_EQUAL( result, WIFI_HAL_SUCCESS);
    return;
}

void test_wifi_L2_set_valid_bandwidth_2Ghz_20MHz(void)
{
    /* set 2.4 GHz bandwidth first */

    /* Positive */
    /* Set it for a valid bandwidth */
    /* Available Channels in 2.4GHz is 20 Mhz, 40 Mhz */
    INT radioIndex = 0;
    UINT bandwidth;
    INT result;

    bandwidth = WIFI_CHANNELBANDWIDTH_20MHZ;
    result = test_utils_setBandwidth(radioIndex, bandwidth);
    UT_ASSERT_EQUAL( result, WIFI_HAL_SUCCESS);
    return;
}


void test_wifi_L2_set_Invalid_bandwidth_2Ghz(void)
{
    /* Negative */
    /* Set it for Invalid bandwidth */
    INT radioIndex = 0;
    UINT bandwidth = 0x12;
    INT result;

    result = test_utils_setBandwidth(radioIndex, bandwidth);
    UT_ASSERT_EQUAL( result, WIFI_HAL_ERROR);
    return;
}

void test_wifi_L2_set_Invalid_bandwidth_5Ghz(void)
{
    /* Negative */
    /* Set it for Invalid bandwidth */
    INT radioIndex = 1;
    UINT bandwidth = 0x12;
    INT result;

    result = test_utils_setBandwidth(radioIndex, bandwidth);
    UT_ASSERT_EQUAL( result, WIFI_HAL_ERROR);
    return;
}

void test_wifi_L2_set_Invalid_bandwidth_6Ghz(void)
{
    /* Negative */
    /* Set it for Invalid bandwidth */
    INT radioIndex = 2;
    UINT bandwidth = 0x12;
    INT result;

    result = test_utils_setBandwidth(radioIndex, bandwidth);
    UT_ASSERT_EQUAL( result, WIFI_HAL_ERROR);
    return;
}


void test_wifi_L2_set_InvalidIndex_bandwidth_2Ghz(void)
{
    /* Negative */
    /* Invalid radio index */
    INT radioIndex = 5;
    UINT bandwidth = WIFI_CHANNELBANDWIDTH_40MHZ;
    INT result;

    result = test_utils_setBandwidth(radioIndex, bandwidth);
    UT_ASSERT_EQUAL( result, WIFI_HAL_INVALID_ARGUMENTS);
    return;
}

void test_wifi_L2_set_InvalidIndex_bandwidth_5Ghz(void)
{
    /* Negative */
    /* Invalid radio index */
    INT radioIndex = 5;
    UINT bandwidth = WIFI_CHANNELBANDWIDTH_80MHZ;
    INT result;

    result = test_utils_setBandwidth(radioIndex, bandwidth);
    UT_ASSERT_EQUAL( result, WIFI_HAL_INVALID_ARGUMENTS);
    return;
}

void test_wifi_L2_set_InvalidIndex_bandwidth_6Ghz(void)
{
    /* Negative */
    /* Invalid radio index */
    INT radioIndex = 5;
    UINT bandwidth = WIFI_CHANNELBANDWIDTH_80MHZ;
    INT result;

    result = test_utils_setBandwidth(radioIndex, bandwidth);
    UT_ASSERT_EQUAL( result, WIFI_HAL_INVALID_ARGUMENTS);
    return;
}

void test_wifi_L2_set_valid_bandwidth_5Ghz_80MHz(void)
{
    /* set 5 GHz bandwidth */

    /* Positive */
    /* Set it for a valid bandwidth */
    /* Available Channels in 5 GHz is 20 Mhz, 40 Mhz, 80 Mhz, 160 Mhz*/
    INT radioIndex = 1;
    UINT bandwidth = WIFI_CHANNELBANDWIDTH_80MHZ;
    INT result;

    result = test_utils_setBandwidth(radioIndex, bandwidth);
    UT_ASSERT_EQUAL( result, WIFI_HAL_SUCCESS);
    return ;
}

void test_wifi_L2_set_valid_bandwidth_6Ghz_80MHz(void)
{
    /* set 6 GHz bandwidth */

    /* Positive */
    /* Set it for a valid bandwidth */
    /* Available Channels in 5 GHz is 20 Mhz, 40 Mhz, 80 Mhz, 160 Mhz*/
    INT radioIndex = 2;
    UINT bandwidth = WIFI_CHANNELBANDWIDTH_80MHZ;
    INT result;

    result = test_utils_setBandwidth(radioIndex, bandwidth);
    UT_ASSERT_EQUAL( result, WIFI_HAL_SUCCESS);
    return;
}


void test_wifi_L2_set_valid_bandwidth_5Ghz_20MHz(void)
{
    /* set 5 GHz bandwidth */

    /* Positive */
    /* Set it for a valid bandwidth */
    /* Available Channels in 5 GHz is 20 Mhz, 40 Mhz, 80 Mhz, 160 Mhz*/
    INT radioIndex = 1;
    UINT bandwidth = WIFI_CHANNELBANDWIDTH_20MHZ;
    INT result;

    result = test_utils_setBandwidth(radioIndex, bandwidth);
    UT_ASSERT_EQUAL( result, WIFI_HAL_SUCCESS);
    return;
}

void test_wifi_L2_set_valid_bandwidth_6Ghz_20MHz(void)
{
    /* set 6 GHz bandwidth */

    /* Positive */
    /* Set it for a valid bandwidth */
    /* Available Channels in 5 GHz is 20 Mhz, 40 Mhz, 80 Mhz, 160 Mhz*/
    INT radioIndex = 2;
    UINT bandwidth = WIFI_CHANNELBANDWIDTH_20MHZ;
    INT result;

    result = test_utils_setBandwidth(radioIndex, bandwidth);
    UT_ASSERT_EQUAL( result, WIFI_HAL_SUCCESS);
    return;
}


void test_wifi_L2_set_valid_bandwidth_5Ghz_40MHz(void)
{
    /* set 5 GHz bandwidth */

    /* Positive */
    /* Set it for a valid bandwidth */
    /* Available Channels in 5 GHz is 20 Mhz, 40 Mhz, 80 Mhz, 160 Mhz*/
    INT radioIndex = 1;
    UINT bandwidth = WIFI_CHANNELBANDWIDTH_40MHZ;
    INT result;

    result = test_utils_setBandwidth(radioIndex, bandwidth);
    UT_ASSERT_EQUAL( result, WIFI_HAL_SUCCESS);
    return;
}

void test_wifi_L2_set_valid_bandwidth_6Ghz_40MHz(void)
{
    /* set 6 GHz bandwidth */

    /* Positive */
    /* Set it for a valid bandwidth */
    /* Available Channels in 5 GHz is 20 Mhz, 40 Mhz, 80 Mhz, 160 Mhz*/
    INT radioIndex = 2;
    UINT bandwidth = WIFI_CHANNELBANDWIDTH_40MHZ;
    INT result;

    result = test_utils_setBandwidth(radioIndex, bandwidth);
    UT_ASSERT_EQUAL( result, WIFI_HAL_SUCCESS);
    return;
}


void test_wifi_L2_set_valid_bandwidth_5Ghz_160MHz(void)
{
    /* set 5 GHz bandwidth */

    /* Positive */
    /* Set it for a valid bandwidth */
    /* Available Channels in 5 GHz is 20 Mhz, 40 Mhz, 80 Mhz, 160 Mhz*/
    INT radioIndex = 1;
    UINT bandwidth = WIFI_CHANNELBANDWIDTH_160MHZ;
    INT result;

    result = test_utils_setBandwidth(radioIndex, bandwidth);
    UT_ASSERT_EQUAL( result, WIFI_HAL_SUCCESS);
    return;
}

void test_wifi_L2_set_valid_bandwidth_6Ghz_160MHz(void)
{
    /* set 6 GHz bandwidth */

    /* Positive */
    /* Set it for a valid bandwidth */
    /* Available Channels in 5 GHz is 20 Mhz, 40 Mhz, 80 Mhz, 160 Mhz*/
    INT radioIndex = 2;
    UINT bandwidth = WIFI_CHANNELBANDWIDTH_160MHZ;
    INT result;

    result = test_utils_setBandwidth(radioIndex, bandwidth);
    UT_ASSERT_EQUAL( result, WIFI_HAL_SUCCESS);
    return;
}

void test_wifi_L2_set_valid_bandwidth_5Ghz_80_80MHz(void)
{
    /* set 5 GHz bandwidth */

    /* Positive */
    /* Set it for a valid bandwidth */
    /* Available Channels in 5 GHz is 20 Mhz, 40 Mhz, 80 Mhz, 160 Mhz*/
    INT radioIndex = 1;
    UINT bandwidth = WIFI_CHANNELBANDWIDTH_80_80MHZ;
    INT result;

    result = test_utils_setBandwidth(radioIndex, bandwidth);
    UT_ASSERT_EQUAL( result, WIFI_HAL_SUCCESS);
    return;
}

void test_wifi_L2_set_valid_bandwidth_6Ghz_80_80MHz(void)
{
    /* set 6 GHz bandwidth */

    /* Positive */
    /* Set it for a valid bandwidth */
    /* Available Channels in 5 GHz is 20 Mhz, 40 Mhz, 80 Mhz, 160 Mhz*/
    INT radioIndex = 2;
    UINT bandwidth = WIFI_CHANNELBANDWIDTH_80_80MHZ;
    INT result;

    result = test_utils_setBandwidth(radioIndex, bandwidth);
    UT_ASSERT_EQUAL( result, WIFI_HAL_SUCCESS);
    return;
}
#endif

static UT_test_suite_t *pSuite = NULL;

/**
 * @brief Init the test system
 * 
 * @return int - 0 on success, otherwise failure
 */
int test_wifi_hal_init(void)
{
    return 0;
}

/**
 * @brief Clean the test system
 * 
 * @return int - 0 on success, otherwise failure
 */
int test_wifi_hal_clean(void)
{
    return 0;
}

/**
 * @brief Register the main tests for this module
 * 
 * @return int - 0 on success, otherwise failure
 */
int test_wifi_hal_l2_register( void )
{
    /* add a suite to the registry */
    pSuite = UT_add_suite("[L2 test_wifi_hal]", &test_wifi_hal_init, &test_wifi_hal_clean);
    if (NULL == pSuite) 
    {
        return -1;
    }
    UT_add_test( pSuite, "set_Valid_SSID_2GHz (test@1234)", test_wifi_hal_L2_setValidSSID_2Ghz);
    UT_add_test( pSuite, "set_InValidIndex_SSID_2GHz", test_wifi_hal_L2_setInValidIndexSSID_2Ghz);
    UT_add_test( pSuite, "set_NULL_SSID_2GHz", test_wifi_hal_L2_setNULLSSID_2Ghz);
    UT_add_test( pSuite, "set_Valid_SSID_5GHz", test_wifi_hal_L2_setValidSSID_5Ghz);
    UT_add_test( pSuite, "set_InValidIndex_SSID_5GHz", test_wifi_hal_L2_setInValidIndexSSID_5Ghz);
    UT_add_test( pSuite, "set_NULL_SSID_5GHz", test_wifi_hal_L2_setNULLSSID_5Ghz);
    UT_add_test( pSuite, "set_Valid_SSID_6GHz", test_wifi_hal_L2_setValidSSID_6Ghz);
    UT_add_test( pSuite, "set_InValidIndex_SSID_6GHz", test_wifi_hal_L2_setInValidIndexSSID_6Ghz);
    UT_add_test( pSuite, "set_NULL_SSID_6GHz", test_wifi_hal_L2_setNULLSSID_6Ghz);

#if 0
    UT_add_test( pSuite, "set_ap_Disable_2GHz", test_wifi_hal_L2_setApDisable_2GHz);
    UT_add_test( pSuite, "set_ap_Disable_5GHz", test_wifi_hal_L2_setApDisable_5GHz);
    UT_add_test( pSuite, "set_ap_Disable_6GHz", test_wifi_hal_L2_setApDisable_6GHz);
    UT_add_test( pSuite, "set_ap_Enable_2GHz", test_wifi_hal_L2_setApEnable_2GHz);
    UT_add_test( pSuite, "set_ap_Enable_5GHz", test_wifi_hal_L2_setApEnable_5GHz);
    UT_add_test( pSuite, "set_ap_Enable_6GHz", test_wifi_hal_L2_setApEnable_6GHz);
    UT_add_test( pSuite, "set_ap_InValidIndex_Disable",test_wifi_hal_L2_setInvalidIndexApDisable);
    UT_add_test( pSuite, "set_ap_InValidIndex_Enable",test_wifi_hal_L2_setInvalidIndexApEnable);
    UT_add_test( pSuite, "valid_channel_push_2GHz", test_wifi_L2_Validchannel_push_2GHz);
    UT_add_test( pSuite, "Invalid_channel_push_2GHz", test_wifi_L2_InValidchannel_push_2GHz);
    UT_add_test( pSuite, "Invalid_Index_channel_push_2GHz", test_wifi_L2_InValidIndex_channel_push_2GHz);
    UT_add_test( pSuite, "valid_channel_push_5GHz", test_wifi_L2_Validchannel_push_5GHz);
    UT_add_test( pSuite, "Invalid_channel_push_5GHz", test_wifi_L2_InValidchannel_push_5GHz);
    UT_add_test( pSuite, "Invalid_Index_channel_push_5GHz", test_wifi_L2_InValidIndex_channel_push_5GHz);
    UT_add_test( pSuite, "valid_channel_push_6GHz", test_wifi_L2_Validchannel_push_6GHz);
    UT_add_test( pSuite, "Invalid_channel_push_6GHz", test_wifi_L2_InValidchannel_push_6GHz);
    UT_add_test( pSuite, "Invalid_Index_channel_push_6GHz", test_wifi_L2_InValidIndex_channel_push_6GHz);
    UT_add_test( pSuite, "set_Valid_bandwidth_2GHz_40MHz",test_wifi_L2_set_valid_bandwidth_2Ghz_40MHz);
    UT_add_test( pSuite, "set_Valid_bandwidth_2GHz_20MHz",test_wifi_L2_set_valid_bandwidth_2Ghz_20MHz);
    UT_add_test( pSuite, "set_InValid_bandwidth_2GHz",test_wifi_L2_set_Invalid_bandwidth_2Ghz);
    UT_add_test( pSuite, "set_InValidIndex_bandwidth_2GHz",test_wifi_L2_set_InvalidIndex_bandwidth_2Ghz);
    UT_add_test( pSuite, "set_Valid_bandwidth_5GHz_20MHz",test_wifi_L2_set_valid_bandwidth_5Ghz_20MHz);
    UT_add_test( pSuite, "set_Valid_bandwidth_5GHz_40MHz",test_wifi_L2_set_valid_bandwidth_5Ghz_40MHz);
    UT_add_test( pSuite, "set_Valid_bandwidth_5GHz_80MHz",test_wifi_L2_set_valid_bandwidth_5Ghz_80MHz);
    UT_add_test( pSuite, "set_Valid_bandwidth_5GHz_160MHz",test_wifi_L2_set_valid_bandwidth_5Ghz_160MHz);
    UT_add_test( pSuite, "set_Valid_bandwidth_5GHz_80_80MHz",test_wifi_L2_set_valid_bandwidth_5Ghz_80_80MHz);
    UT_add_test( pSuite, "set_InValid_bandwidth_5GHz",test_wifi_L2_set_Invalid_bandwidth_5Ghz);
    UT_add_test( pSuite, "set_InValidIndex_bandwidth_5GHz",test_wifi_L2_set_InvalidIndex_bandwidth_5Ghz);
    UT_add_test( pSuite, "set_Valid_bandwidth_6GHz_20MHz",test_wifi_L2_set_valid_bandwidth_6Ghz_20MHz);
    UT_add_test( pSuite, "set_Valid_bandwidth_6GHz_20MHz",test_wifi_L2_set_valid_bandwidth_6Ghz_40MHz);
    UT_add_test( pSuite, "set_Valid_bandwidth_6GHz_160MHz",test_wifi_L2_set_valid_bandwidth_6Ghz_160MHz);
    UT_add_test( pSuite, "set_Valid_bandwidth_6GHz_80MHz",test_wifi_L2_set_valid_bandwidth_6Ghz_80MHz);
    UT_add_test( pSuite, "set_Valid_bandwidth_6GHz_80_80MHz",test_wifi_L2_set_valid_bandwidth_6Ghz_80_80MHz);
    UT_add_test( pSuite, "set_InValid_bandwidth_6GHz",test_wifi_L2_set_Invalid_bandwidth_6Ghz);
    UT_add_test( pSuite, "set_InValidIndex_bandwidth_6GHz",test_wifi_L2_set_InvalidIndex_bandwidth_6Ghz);
#endif

    return 0;
}

#endif //DELETE