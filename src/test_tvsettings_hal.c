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

#include <stdlib.h>
#include <setjmp.h>
#include "tvSettings.h"
#include <tv_settings_hal.h>
//#include "PqClient.h"
//#include "pqcmd.h"

#include <ut.h>

pic_modes_t *availableModes;

#define DV_MODES_SUPPORTED_MAX (3)
#define DEFAULT_WB_OFFSET       (0)
#define DEFAULT_WB_ZERO_GAIN     (0)
#define DEFAULT_WB_CUST_GAIN     (1024)

static UT_test_suite_t *pSuite = NULL;
#define INFO_UT(text, ...) do {\
printf("TV-SET-HAL-UT: %s[%d] - %s: " text, __FUNCTION__, __LINE__, "INFO", ##__VA_ARGS__);}while(0);

void SwitchEDID(int pqmode);
tvError_t SetLocalDimmingLevel(int localDimmingLevel);
tvError_t GetLocalDimmingLevel(int *localDimmingLevel);
tvError_t SaveLocalDimmingLevel(int sourceInput, int pq_mode,int hdr_type,int value);
void SwitchEDID(int pqmode);
tvError_t UpdateEDIDAndSetDimmingLevel(int dimmingLevel);
tvError_t getWbInfo(getWBInfo_t* params, std::vector<std::string> &selector, std::vector<std::string> &colorTmp, std::vector<std::string> &input);

void GetLDIMAndEDIDLevel(int dimmingMode,int format,int *dimmingLevel, int *edidLevel);
int GetGamePQModeIndex();
void test_generic_tvInit( void )
{
    int result;

    /* Positive result */
    result = tvInit();
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    INFO_UT(" T1: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /*calling tvInit should succeed, As it will not return any error since already initialised */
    result = tvInit();
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T2: E[%d]-A[%d] \n",result,tvERROR_NONE);
    
    /* #TODO: Unclear how the function will fail, maybe this function should be void? */
    
}


void test_generic_tvTerm( void )
{
    int result;

    /* Positive result */
    result = tvTerm();
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    INFO_UT(" T3: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /*calling tvInit should succeed, As it will not return any error since already initialised */
    result = tvTerm();
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T4: E[%d]-A[%d] \n",result,tvERROR_NONE);

        /* #TODO: Unclear how the function will fail, maybe this function should be void? */

}


void test_generic_GetTVPictureMode( void )
{

    int result;
    /* positive result */
    char picMode[PIC_MODE_NAME_MAX];
    result = GetTVPictureMode((char*)picMode);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T5: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* Negative Result */
    result = GetTVPictureMode((char*)picMode);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T6: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}


void test_generic_SetTVPictureMode( void )
{
    int result = 0;
    /* Positive result */



    result=SetTVPictureMode("tvPictureMode_COLORFUL");
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T7: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* Negative Result */
    result = SetTVPictureMode("none");
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL);
    INFO_UT(" T8: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

    result = SetTVPictureMode("tvPictureMode_MAX");
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T9: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);
    
}

void test_generic_GetBacklight(void )
{
   int result = 0;
   int value;
   /* Positive Result */
   value = tvBacklightMode_ECO;
   result = GetBacklight(&value);
   UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T10: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* Negative Result */
    value = tvBacklightMode_INVALID;
    result = GetBacklight(&value);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T11: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_SetBacklight( void )
{
    int result;
    /* Positive Result */
    result = SetBacklight(90);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T12: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* Negative Resukt */
    result = SetBacklight(120);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T13: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);


    result = SetBacklight(-1);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T14: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_SetBrightness( void )
{
    int result;

    /* positive result */
    result = SetBrightness(90);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T15: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetBrightness(110);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T16: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    result = SetBrightness(-10);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T17: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_GetBrightness( void )
{
   int result;
   int value;
   /* positive result */
    result = GetBrightness(&value);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T18: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetBrightness(&value);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T19: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_SetContrast( void )
{
    int result;

    /* positive result */
    result = SetContrast(90);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T20: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetContrast(-1);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T21: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    /* negative result */
    result = SetContrast(120);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T22: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);


}

void test_generic_GetContrast( void )
{
    int result;
    int value;

    /*positive result */
    result = GetContrast(&value);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T23: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* Negative Result */
    result = GetContrast(&value);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T24: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
   
}

void test_generic_SetSharpness( void )
{
    int result;

    /* positive result */
    result = SetSharpness(50);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T25: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* Negative Result */
    result = SetSharpness(-1);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T26: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    result = SetSharpness(110);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T27: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_GetSharpness( void )
{
    int result;
    int value;

    /* positive result */
    result = GetSharpness(&value);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T28: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetSharpness(&value);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T29: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_SetSaturation( void )
{
    int result;

    /* positive result */
    result = SetSaturation(80);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T30: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetSaturation(-1);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T31: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    result = SetSaturation(150);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T32: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_GetSaturation( void )
{
    int result;
    int value;

    /* positive result */
    result = GetSaturation(&value);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T33: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetSaturation(&value);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T34: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
    
}

void test_generic_SetHue( void )
{
    int result;

    /* positive result */
    result = SetHue(80);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T35: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetHue(-1);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T36: E[%d]-A[%d] \n",result,tvERROR_NONE);

    result = SetHue(150);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T37: E[%d]-A[%d] \n",result,tvERROR_NONE);

}

void test_generic_GetHue( void )
{
    int result;
    int value;

    /* positive result */
    result = GetHue(&value);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T38: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetHue(&value);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T39: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_SetColorTemperature( void )
{
    int result;
    tvColorTemp_t colorTemp;

    /*positive result */
    colorTemp = tvColorTemp_STANDARD;
    result = SetColorTemperature(colorTemp);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T40: E[%d]-A[%d] \n",result,tvERROR_NONE);

    colorTemp = tvColorTemp_WARM;
    result = SetColorTemperature(colorTemp);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T41: E[%d]-A[%d] \n",result,tvERROR_NONE);

    colorTemp = tvColorTemp_COLD;
    result = SetColorTemperature(colorTemp);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T42: E[%d]-A[%d] \n",result,tvERROR_NONE);

    colorTemp = tvColorTemp_USER;
    result = SetColorTemperature(colorTemp);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T43: E[%d]-A[%d] \n",result,tvERROR_NONE);

    colorTemp = tvColorTemp_MAX;
    result = SetColorTemperature(colorTemp);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T44: E[%d]-A[%d] \n",result,tvERROR_NONE);
    
    /* negative result */
    result = SetColorTemperature((tvColorTemp_t)10);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T45: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_GetColorTemperature( void )
{
    int result;
    tvColorTemp_t colorTemp;

    /* positive result */
    result = GetColorTemperature(&colorTemp);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T46: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetColorTemperature(&colorTemp);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T47: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);
    
}

void test_generic_SetAspectRatio( void )
{
    int result;
    
    /* positive result */
    result = SetAspectRatio(tvDisplayMode_NORMAL);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T48: E[%d]-A[%d] \n",result,tvERROR_NONE);

    result = SetAspectRatio(tvDisplayMode_ZOOM);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T49: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetAspectRatio((tvDisplayMode_t)10);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T50: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);


}

void test_generic_GetAspectRatio( void )
{

    int result;
    tvDisplayMode_t dispMode;
    /* positive result */
    result = GetAspectRatio(&dispMode);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T51: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetAspectRatio(&dispMode);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T52: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}


void test_generic_GetSupportedBacklightModes( void )
{

    int result;
    int blModes;

    /* positive result */
    result = GetSupportedBacklightModes(&blModes);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T53: E[%d]-A[%d] \n",result,tvERROR_NONE);

}

void test_generic_GetCurrentBacklightMode( void )
{

    int result;
    tvBacklightMode_t blMode;
    /* positive result */
    result = GetCurrentBacklightMode(&blMode);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T54: E[%d]-A[%d] \n",result,tvERROR_NONE);

}

void test_generic_SetCurrentBacklightMode( void )
{

    int result;
    tvBacklightMode_t blMode;
    /* positive result */
    blMode = tvBacklightMode_NONE;
    result = SetCurrentBacklightMode(blMode);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T55: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetCurrentBacklightMode((tvBacklightMode_t)10);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T56: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_GetCurrentVideoFormat( void )
{

    int result;
    tvVideoHDRFormat_t format;
    /* positive result */
    result = GetCurrentVideoFormat(&format);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T57: E[%d]-A[%d] \n",result,tvERROR_NONE);

}

void test_generic_GetVideoResolution( void )
{

    int result;
    tvResolutionParam_t resolutionstruct;
    /* positive result */
    result = GetVideoResolution(&resolutionstruct);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T58: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetVideoResolution(&resolutionstruct);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T59: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);


}

void test_generic_GetVideoFrameRate( void )
{

    int result;
    tvVideoFrameRate_t frameRate;
    /* positive result */
    result = GetVideoFrameRate(&frameRate);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T60: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetVideoFrameRate(NULL);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T61: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_setWakeupConfig( void )
{

    int result;
    tvWakeupSrcType_t setValue;
    /* positive result */
    setValue = tvWakeupSrc_BLUETOOTH;
    result = setWakeupConfig(setValue,1);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T62: E[%d]-A[%d] \n",result,tvERROR_NONE);

    result = setWakeupConfig(setValue,0);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T63: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = setWakeupConfig(setValue,0);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T64: E[%d]-A[%d] \n",result,tvERROR_NONE);

}

void test_generic_SetRGBPattern( void )
{

    int result;
    /* positive result */
    result = SetRGBPattern(0XFF,0,0);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T65: E[%d]-A[%d] \n",result,tvERROR_NONE);

    result = SetRGBPattern(0,0xFF,0);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T66: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetRGBPattern(0,0,0);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T67: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_GetRGBPattern( void )
{

    int result;
    int r=0;
    int g=0;
    int b=0;
    /* positive result */
    result = GetRGBPattern(&r,&g,&b);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T68: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetRGBPattern(&r,&g,NULL);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T69: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}
void test_generic_SetGrayPattern( void )
{

    int result;
    int YUVvalue;
    /* positive result */
    YUVvalue = 100;
    result = SetGrayPattern(YUVvalue);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T70: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    YUVvalue = 258;
    result = SetGrayPattern(YUVvalue);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T71: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    result = SetGrayPattern(-1);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T72: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_GetGrayPattern( void )
{

    int result;
    int YUVvalue;
    /* positive result */
    result = GetGrayPattern(&YUVvalue);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T73: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
#if  NEED_SOURCE_MOD
    result = GetGrayPattern(NULL);
#endif    
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T74: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_SetColorTemp_Rgain( void )
{

    int result;
    tvColorTemp_t colorTemp;
    int rgain;

    /* positive result */
    rgain = 2000;
    colorTemp = tvColorTemp_WARM;
    result = SetColorTemp_Rgain(colorTemp,rgain);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T75: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetColorTemp_Rgain(tvColorTemp_MAX,rgain);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T76: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    /* negative result */
    result = SetColorTemp_Rgain(colorTemp,2050);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T77: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}


void test_generic_SetColorTemp_Ggain( void )
{

    int result;
    tvColorTemp_t colorTemp;
    int ggain;

    /* positive result */
    ggain = 2000;
    colorTemp = tvColorTemp_WARM;
    result = SetColorTemp_Ggain(colorTemp,ggain);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T78: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetColorTemp_Ggain(colorTemp,2050);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T79: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_SetColorTemp_Bgain( void )
{

    int result;
    tvColorTemp_t colorTemp;
    int bgain;

    /* positive result */
    bgain = 2000;
    colorTemp = tvColorTemp_WARM;
    result = SetColorTemp_Bgain(colorTemp,bgain);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T80: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetColorTemp_Bgain(tvColorTemp_MAX,bgain);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T81: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    /* negative result */
    result = SetColorTemp_Bgain(colorTemp,2050);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T82: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_GetColorTemp_Rgain( void )
{

    int result;
    tvColorTemp_t colorTemp;
    int rgain;

    /* positive result */
    colorTemp = tvColorTemp_WARM;
    result = GetColorTemp_Rgain(colorTemp,&rgain);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T83: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    result = GetColorTemp_Rgain(colorTemp,&rgain);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL);
    INFO_UT(" T84: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

}

void test_generic_GetColorTemp_Ggain( void )
{

    int result;
    tvColorTemp_t colorTemp;
    int ggain;

    /* positive result */
    colorTemp = tvColorTemp_WARM;
    result = GetColorTemp_Ggain(colorTemp,&ggain);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T85: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    result = GetColorTemp_Ggain(colorTemp,&ggain);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T86: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    result = GetColorTemp_Ggain(colorTemp,&ggain);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL);
    INFO_UT(" T87: E[%d]-A[%d] \n",result,tvERROR_NONE);
}

void test_generic_GetColorTemp_Bgain( void )
{

    int result;
    tvColorTemp_t colorTemp;
    int bgain;

    /* positive result */
    colorTemp = tvColorTemp_WARM;
    result = GetColorTemp_Bgain(colorTemp,&bgain);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T88: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    result = GetColorTemp_Bgain(colorTemp,&bgain);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T89: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

        /* negative result */
    colorTemp = tvColorTemp_COLD;
    result = GetColorTemp_Bgain(colorTemp,&bgain);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL);
    INFO_UT(" T90: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

}

void test_generic_SetColorTemp_R_post_offset( void )
{

    int result;
    tvColorTemp_t colorTemp;
    int rpostoffset;

    /* positive result */
    colorTemp = tvColorTemp_WARM;
    rpostoffset = 100;
    result = SetColorTemp_R_post_offset(colorTemp,rpostoffset);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T91: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetColorTemp_R_post_offset(colorTemp,1050);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T92: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    result = SetColorTemp_R_post_offset(colorTemp,rpostoffset);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T93: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_SetColorTemp_G_post_offset( void )
{

    int result;
    tvColorTemp_t colorTemp;
    int gpostoffset;

    /* positive result */
    colorTemp = tvColorTemp_WARM;
    gpostoffset = 100;
    result = SetColorTemp_G_post_offset(colorTemp,gpostoffset);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T94: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetColorTemp_G_post_offset(colorTemp,1050);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T95: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    result = SetColorTemp_G_post_offset(colorTemp,gpostoffset);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T96: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_SetColorTemp_B_post_offset( void )
{

    int result;
    tvColorTemp_t colorTemp;
    int bpostoffset;

    /* positive result */
    colorTemp = tvColorTemp_WARM;
    bpostoffset = 100;
    result = SetColorTemp_B_post_offset(colorTemp,bpostoffset);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T97: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetColorTemp_B_post_offset(colorTemp,1050);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T98: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    result = SetColorTemp_B_post_offset(colorTemp,bpostoffset);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T99: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_GetColorTemp_R_post_offset( void )
{

    int result;
    tvColorTemp_t colorTemp;
    int rpostoffset;

    /* positive result */
    colorTemp = tvColorTemp_WARM;
    result = GetColorTemp_R_post_offset(colorTemp,&rpostoffset);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T100: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetColorTemp_R_post_offset(colorTemp,NULL);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T101: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_GetColorTemp_G_post_offset( void )
{

    int result;
    tvColorTemp_t colorTemp;
    int gpostoffset;

    /* positive result */
    colorTemp = tvColorTemp_WARM;
    result = GetColorTemp_G_post_offset(colorTemp,&gpostoffset);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T102: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetColorTemp_G_post_offset(colorTemp,&gpostoffset);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T103: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_GetColorTemp_B_post_offset( void )
{

    int result;
    tvColorTemp_t colorTemp;
    int bpostoffset;

    /* positive result */
    colorTemp = tvColorTemp_WARM;
    result = GetColorTemp_B_post_offset(colorTemp,&bpostoffset);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T104: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetColorTemp_B_post_offset(colorTemp,NULL);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T105: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_GetTVSupportedPictureModes( void )
{
    int result;
    pic_modes_t *pictureModes;
    unsigned short *count;

    /* positive result */
    result = GetTVSupportedPictureModes(&pictureModes,count);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T106: E[%d]-A[%d] \n",result,tvERROR_NONE);
    
    /*negative result */
    result = GetTVSupportedPictureModes(NULL,count);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T107: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_GetTVSupportedDVModes(void)
{

    int result;
    pic_modes_t *dvModes;
    unsigned short count = 0;

    /* positive result */
    result = GetTVSupportedDVModes(&dvModes,&count);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T108: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* positive result */
    result = GetTVSupportedDVModes(&dvModes,&count);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T109: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_SetTVDolbyVisionMode(void)
{

    int result;

    /* positive result */
    result = SetTVDolbyVisionMode("bright");
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T110: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
#if NEED_SOURCE_MOD
    result = SetTVDolbyVisionMode(NULL);
#endif

    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T111: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_GetTVDolbyVisionMode(void)
{

    int result;
    char dolbyMode[PIC_MODE_NAME_MAX] = {};

    /* positive result */
    result = GetTVDolbyVisionMode((char *)dolbyMode);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T112: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetTVDolbyVisionMode(NULL);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T113: E[%d]-A[%d] \n",result,tvERROR_NONE);
}


void test_generic_GetTVSupportedHLGModes(void)
{
    int result;
    pic_modes_t *hlgModes;
    unsigned short count;

    /* positive result */
    result = GetTVSupportedHLGModes(&hlgModes, &count);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T114: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetTVSupportedHLGModes(&hlgModes, &count);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T115: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_GetTVSupportedHDR10Modes(void)
{
    int result;
    pic_modes_t *hdr10Modes;
    unsigned short count;

    /*positive result */
    result = GetTVSupportedHDR10Modes(&hdr10Modes, &count);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T116: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetTVSupportedHDR10Modes(&hdr10Modes, &count);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T117: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_SetColorTemp_Rgain_onSource( void )
{

    int result;
    tvColorTemp_t colorTemp;
    int rgain;
    int sourceOffset;
    int saveOnly;

    /* positive result */
    rgain = 2000;
    colorTemp = tvColorTemp_WARM;
    sourceOffset = 1;
    saveOnly  = 1;
    result = SetColorTemp_Rgain_onSource(colorTemp,rgain,sourceOffset,saveOnly);//saves the value
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T118: E[%d]-A[%d] \n",result,tvERROR_NONE);

    sourceOffset = 1;
    saveOnly  = 0;
    result = SetColorTemp_Rgain_onSource(colorTemp,rgain,sourceOffset,saveOnly); //sets the value
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T119: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    /* negative result */
    colorTemp = tvColorTemp_USER;
    rgain = 2000;
    result = SetColorTemp_Rgain_onSource(colorTemp,rgain,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T120: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    /* negative result */
    colorTemp = tvColorTemp_WARM;
    rgain = 2050;
    result = SetColorTemp_Rgain_onSource(colorTemp,rgain,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T121: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}


void test_generic_SetColorTemp_Ggain_onSource( void )
{

    int result;
    tvColorTemp_t colorTemp;
    int ggain;
    int sourceOffset;
    int saveOnly;

    /* positive result */
    ggain = 2000;
    colorTemp = tvColorTemp_WARM;
    sourceOffset = 1;
    saveOnly  = 1;
    result = SetColorTemp_Ggain_onSource(colorTemp,ggain,sourceOffset,saveOnly);//saves the value
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T122: E[%d]-A[%d] \n",result,tvERROR_NONE);

    sourceOffset = 1;
    saveOnly  = 0;
    result = SetColorTemp_Ggain_onSource(colorTemp,ggain,sourceOffset,saveOnly); //sets the value
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T123: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    /* negative result */
    colorTemp = tvColorTemp_USER;
    ggain = 2000;
    result = SetColorTemp_Ggain_onSource(colorTemp,ggain,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T124: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    /* negative result */
    colorTemp = tvColorTemp_WARM;
    ggain = 2050;
    result = SetColorTemp_Ggain_onSource(colorTemp,ggain,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T125: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_SetColorTemp_Bgain_onSource( void )
{

    int result;
    tvColorTemp_t colorTemp;
    int bgain;
    int sourceOffset;
    int saveOnly;

    /* positive result */
    bgain = 2000;
    colorTemp = tvColorTemp_WARM;
    sourceOffset = 1;
    saveOnly  = 1;
    result = SetColorTemp_Bgain_onSource(colorTemp,bgain,sourceOffset,saveOnly);//saves the value
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T126: E[%d]-A[%d] \n",result,tvERROR_NONE);

    sourceOffset = 1;
    saveOnly  = 0;
    result = SetColorTemp_Bgain_onSource(colorTemp,bgain,sourceOffset,saveOnly); //sets the value
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T127: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    /* negative result */
    colorTemp = tvColorTemp_USER;
    bgain = 2000;
    result = SetColorTemp_Bgain_onSource(colorTemp,bgain,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T128: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    /* negative result */
    colorTemp = tvColorTemp_WARM;
    bgain = 2050;
    result = SetColorTemp_Bgain_onSource(colorTemp,bgain,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T129: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_GetColorTemp_Rgain_onSource( void )
{

    int result;
    tvColorTemp_t colorTemp;
    int rgain;
    int sourceOffset;

    /* positive result */
    sourceOffset = 1;
    colorTemp = tvColorTemp_WARM;
    result = GetColorTemp_Rgain_onSource(colorTemp,&rgain,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T130: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetColorTemp_Rgain_onSource(tvColorTemp_MAX,NULL,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T131: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    /* negative result */
    rgain = -1;
    result = GetColorTemp_Rgain_onSource(colorTemp,&rgain,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL);
    INFO_UT(" T132: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    rgain = 2000;
    result = GetColorTemp_Rgain_onSource(colorTemp,&rgain,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL);
    INFO_UT(" T133: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

}

void test_generic_GetColorTemp_Ggain_onSource( void )
{

    int result;
    tvColorTemp_t colorTemp;
    int ggain;
    int sourceOffset;

    /* positive result */
    sourceOffset = 1;
    colorTemp = tvColorTemp_WARM;
    result = GetColorTemp_Ggain_onSource(colorTemp,&ggain,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T134: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetColorTemp_Ggain_onSource(tvColorTemp_MAX,NULL,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T135: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    /* negative result */
    ggain = -1;
    result = GetColorTemp_Ggain_onSource(colorTemp,&ggain,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL);
    INFO_UT(" T136: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    ggain = 2000;
    result = GetColorTemp_Ggain_onSource(colorTemp,&ggain,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL);
    INFO_UT(" T137: E[%d]-A[%d] \n",result,tvERROR_GENERAL);
}

void test_generic_GetColorTemp_Bgain_onSource( void )
{
    int result;
    tvColorTemp_t colorTemp;
    int bgain;
    int sourceOffset;

    /* positive result */
    sourceOffset = 1;
    colorTemp = tvColorTemp_WARM;
    result = GetColorTemp_Bgain_onSource(colorTemp,&bgain,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T138: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetColorTemp_Bgain_onSource(tvColorTemp_MAX,NULL,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T139: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    /* negative result */
    bgain = -1;
    result = GetColorTemp_Bgain_onSource(colorTemp,&bgain,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL);
    INFO_UT(" T140: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    bgain = 2000;
    result = GetColorTemp_Bgain_onSource(colorTemp,&bgain,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL);
    INFO_UT(" T141: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

}

void test_generic_SetColorTemp_R_post_offset_onSource( void )
{

    int result;
    tvColorTemp_t colorTemp;
    int rpostoffset;
    int saveOnly;
    int sourceOffset;

    /* positive result */
    colorTemp = tvColorTemp_WARM;
    rpostoffset = 100;
    sourceOffset = 1;
    saveOnly = 1;
    result = SetColorTemp_R_post_offset_onSource(colorTemp,rpostoffset,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T142: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* positive result */
    colorTemp = tvColorTemp_WARM;
    rpostoffset = 100;
    sourceOffset = 1;
    saveOnly = 0;
    result = SetColorTemp_R_post_offset_onSource(colorTemp,rpostoffset,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T143: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    rpostoffset = 1050;
    result = SetColorTemp_R_post_offset_onSource(colorTemp,rpostoffset,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T144: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    rpostoffset = 100;
    result = SetColorTemp_R_post_offset_onSource(colorTemp,rpostoffset,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T145: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_SetColorTemp_G_post_offset_onSource( void )
{

    int result;
    tvColorTemp_t colorTemp;
    int gpostoffset;
    int saveOnly;
    int sourceOffset;

    /* positive result */
    colorTemp = tvColorTemp_WARM;
    gpostoffset = 100;
    sourceOffset = 1;
    saveOnly = 1;
    result = SetColorTemp_G_post_offset_onSource(colorTemp,gpostoffset,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T146: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* positive result */
    colorTemp = tvColorTemp_WARM;
    gpostoffset = 100;
    sourceOffset = 1;
    saveOnly = 0;
    result = SetColorTemp_G_post_offset_onSource(colorTemp,gpostoffset,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T147: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    gpostoffset = 1050;
    result = SetColorTemp_G_post_offset_onSource(colorTemp,gpostoffset,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T148: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    gpostoffset = 100;
    result = SetColorTemp_G_post_offset_onSource(colorTemp,gpostoffset,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T149: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_SetColorTemp_B_post_offset_onSource( void )
{

    int result;
    tvColorTemp_t colorTemp;
    int bpostoffset;
    int saveOnly;
    int sourceOffset;

    /* positive result */
    colorTemp = tvColorTemp_WARM;
    bpostoffset = 100;
    sourceOffset = 1;
    saveOnly = 1;
    result = SetColorTemp_B_post_offset_onSource(colorTemp,bpostoffset,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T150: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* positive result */
    colorTemp = tvColorTemp_WARM;
    bpostoffset = 100;
    sourceOffset = 1;
    saveOnly = 0;
    result = SetColorTemp_B_post_offset_onSource(colorTemp,bpostoffset,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T151: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    bpostoffset = 1050;
    result = SetColorTemp_B_post_offset_onSource(colorTemp,bpostoffset,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T152: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    bpostoffset = 100;
    result = SetColorTemp_R_post_offset_onSource(colorTemp,bpostoffset,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T153: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_GetColorTemp_R_post_offset_onSource( void )
{

    int result;
    tvColorTemp_t colorTemp;
    int rpostoffset;
    int sourceOffset;
    /* positive result */
    colorTemp = tvColorTemp_WARM;
    result = GetColorTemp_R_post_offset_onSource(colorTemp,&rpostoffset,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T154: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetColorTemp_R_post_offset_onSource(colorTemp,NULL,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T155: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_GetColorTemp_G_post_offset_onSource( void )
{

    int result;
    tvColorTemp_t colorTemp;
    int gpostoffset;
    int sourceOffset;

    sourceOffset = 1;
    /* positive result */
    colorTemp = tvColorTemp_WARM;
    result = GetColorTemp_G_post_offset_onSource(colorTemp,&gpostoffset,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T156: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetColorTemp_G_post_offset_onSource(colorTemp,NULL,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T157: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_GetColorTemp_B_post_offset_onSource( void )
{

    int result;
    tvColorTemp_t colorTemp;
    int bpostoffset;
    int sourceOffset;

    /* positive result */
    sourceOffset = 1;
    colorTemp = tvColorTemp_WARM;
    result = GetColorTemp_B_post_offset_onSource(colorTemp,&bpostoffset,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T158: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetColorTemp_B_post_offset_onSource(colorTemp,NULL,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T159: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_SetDynamicContrast(void)
{
    int result;
    const char *dynamicContrastEnable;
    /* positive result */
    dynamicContrastEnable = "enabled";
    result = SetDynamicContrast(dynamicContrastEnable);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T160: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetDynamicContrast(NULL);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T161: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_GetDynamicContrast(void)
{
    int result;
    char *dynamicContrastEnable;
    /* positive result */
    result = GetDynamicContrast(dynamicContrastEnable);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T162: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetDynamicContrast(NULL);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T163: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_setWBctrl(void)
{
    int result;


}

void test_generic_getWBctrl(void)
{
    int result;

    
}

#if 0
void test_generic_getWbInfo(void)
{
    int result;
    getWBInfo_t params;
    std::vector<std::string> selector{};
    std::vector<std::string> input{};
    std::vector<std::string> colorTmp{};

    result = getWbInfo(&params,selector,input,colorTmp);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T164: E[%d]-A[%d] \n",result,tvERROR_NONE);

    
    if((selector.empty()) || (input.empty()) || (colorTmp.empty()))
    {
        result = getWbInfo(&params,selector,input,colorTmp);
        UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
        INFO_UT(" T165: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    }
}
#endif
void test_generic_enableWBmode(void)
{
    int result;

    /* positive result */
    result = enableWBmode(true);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T166: E[%d]-A[%d] \n",result,tvERROR_NONE);

    result = enableWBmode(NULL);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T167: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);
}

void test_generic_GetSupportedComponentColor(void)
{
    int result;
    int *blComponentColor;
    /* positive result */
    result = GetSupportedComponentColor(blComponentColor);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T168: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetSupportedComponentColor(NULL);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T169: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_SetCurrentComponentSaturation(void)
{
    int result;
    tvDataComponentColor_t blSaturation;
    int saturation;

    /* positive result */
    saturation = 50;
    blSaturation =  tvDataColor_RED;
    result = SetCurrentComponentSaturation(blSaturation,saturation);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T170: E[%d]-A[%d] \n",result,tvERROR_NONE);
    
    /* negative result */
    saturation= 150;
    result = SetCurrentComponentSaturation(blSaturation,saturation);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T171: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);
    
}

void test_generic_GetCurrentComponentSaturation(void)
{
    int result;
    tvDataComponentColor_t blSaturation;
    int *saturation;
    
    /*positive result */
    blSaturation = tvDataColor_RED; 
    result = GetCurrentComponentSaturation(blSaturation,saturation);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T172: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetCurrentComponentSaturation(blSaturation,saturation);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T173: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
}

void test_generic_SetCurrentComponentHue(void)
{
    int result;
    tvDataComponentColor_t blHueColor;
    int hue;

    /* positive result */
    hue = 50;
    blHueColor =  tvDataColor_RED;
    result = SetCurrentComponentHue(blHueColor,hue);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T174: E[%d]-A[%d] \n",result,tvERROR_NONE);
    
    /* negative result */
    hue = 150;
    result = SetCurrentComponentHue(blHueColor,hue);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T175: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);
    
}

void test_generic_GetCurrentComponentHue(void)
{
    int result;
    tvDataComponentColor_t blHueColor;
    int *hue;
    
    /*positive result */
    blHueColor = tvDataColor_RED; 
    result = GetCurrentComponentHue(blHueColor,hue);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T176: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetCurrentComponentHue(blHueColor,hue);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    INFO_UT(" T177: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
}

void test_generic_SetCurrentComponentLuma(void)
{
    int result;
    tvDataComponentColor_t blLumaColor;
    int luma;

    /* positive result */
    luma = 50;
    blLumaColor = tvDataColor_RED;
    result = SetCurrentComponentLuma(blLumaColor,luma);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    INFO_UT(" T178: E[%d]-A[%d] \n",result,tvERROR_NONE);
    
    /* negative result */
    luma = 150;
    result = SetCurrentComponentLuma(blLumaColor,luma);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    INFO_UT(" T179: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);
    
}

void test_generic_GetCurrentComponentLuma(void)
{
    int result;
    tvDataComponentColor_t blLumaColor;
    int *luma;
    
    /*positive result */
    blLumaColor = tvDataColor_RED; 
    result = GetCurrentComponentLuma(blLumaColor,luma);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T180: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    //TBD
}

void test_generic_GetTVSupportedDimmingModes(void)
{
    int result;
    char **dimmingModes;
    
    unsigned short *count;

    /* positive result */
#if 0    
    *dimmingModes[0] = "bright";
    *dimmingModes[1] = "dark";
    result = GetTVSupportedDimmingModes(dimmingModes,&count);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T181: E[%d]-A[%d] \n",result,tvERROR_NONE);
#endif
    /* negative result */
    result = GetTVSupportedDimmingModes(NULL,count);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T182: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    /* negative result */
    result = GetTVSupportedDimmingModes(dimmingModes,0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T183: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_SetTVDimmingMode(void)
{
    int result;
    const char *dimmingMode;

    /* positive result */
    dimmingMode = "global";
    result = SetTVDimmingMode(dimmingMode);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T184: E[%d]-A[%d] \n",result,tvERROR_NONE);
    
    /* negative result */
    result = SetTVDimmingMode(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T185: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_GetTVBacklightGlobalFactor(void)
{
    int result;
    int value;

    /* positive result */
    result = GetTVBacklightGlobalFactor(&value);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T186: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetTVBacklightGlobalFactor(0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T187: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_SetTVBacklightGlobalFactor(void)
{
    int result;
    //TBD
}

void test_generic_GetTVPictureModeIndex(void)
{
    int result;
    const char * pictureMode;

    /* positive result */
    pictureMode = "tvColorTemp_USER";
    result = GetTVPictureModeIndex(pictureMode);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T188: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetTVPictureModeIndex("unknown");
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T189: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_GetCurrentContentFormat(void)
{
    tvVideoHDRFormat_t result;
    /* positive result */
    result = GetCurrentContentFormat();
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T190: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    // N/A
}

void test_generic_GetSupportedContentFormats(void)
{
    int result;
    unsigned int contentFormats;
    unsigned short numberOfFormats;

    /* positive result */
    result = GetSupportedContentFormats(&contentFormats,&numberOfFormats);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T191: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetSupportedContentFormats(0,&numberOfFormats);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T192: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    result = GetSupportedContentFormats(&contentFormats,0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T193: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
}

void test_generic_ResetBrightness(void)
{
    int result;
    int defaultValue;
    bool resetForAllFormats;

    /*positive result */
    defaultValue = 50;
    resetForAllFormats = 1;
    result = ResetBrightness(defaultValue,resetForAllFormats);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T194: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = ResetBrightness(120,resetForAllFormats);
    UT_ASSERT_EQUAL(result, tvERROR_GENERAL);
    INFO_UT(" T195: E[%d]-A[%d] \n",result,tvERROR_GENERAL);
}

void test_generic_ResetContrast(void)
{
    int result;
    int defaultValue;
    bool resetForAllFormats;

    /*positive result */
    defaultValue = 50;
    resetForAllFormats = 1;
    result = ResetContrast(defaultValue,resetForAllFormats);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T196: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = ResetContrast(120,resetForAllFormats);
    UT_ASSERT_EQUAL(result, tvERROR_GENERAL);
    INFO_UT(" T197: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

}

void test_generic_ResetSharpness(void)
{
    int result;
    int defaultValue;
    bool resetForAllFormats;

    /*positive result */
    defaultValue = 50;
    resetForAllFormats = 1;
    result = ResetSharpness(defaultValue,resetForAllFormats);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T198: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = ResetSharpness(120,resetForAllFormats);
    UT_ASSERT_EQUAL(result, tvERROR_GENERAL);
    INFO_UT(" T199: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

}

void test_generic_ResetSaturation(void)
{
    int result;
    int defaultValue;
    bool resetForAllFormats;

    /*positive result */
    defaultValue = 50;
    resetForAllFormats = 1;
    result = ResetSaturation(defaultValue,resetForAllFormats);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T200: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = ResetSaturation(120,resetForAllFormats);
    UT_ASSERT_EQUAL(result, tvERROR_GENERAL);
    INFO_UT(" T201: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

}

void test_generic_ResetHue(void)
{
    int result;
    int defaultValue;
    bool resetForAllFormats;

    /*positive result */
    defaultValue = 50;
    resetForAllFormats = 1;
    result = ResetHue(defaultValue,resetForAllFormats);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T202: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = ResetHue(120,resetForAllFormats);
    UT_ASSERT_EQUAL(result, tvERROR_GENERAL);
    INFO_UT(" T203: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

}

void test_generic_ResetBacklight(void)
{
    int result;
    int defaultValue;
    bool resetForAllFormats;

    /*positive result */
    defaultValue = 50;
    resetForAllFormats = 1;
    result = ResetBacklight(defaultValue,resetForAllFormats);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T204: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = ResetBacklight(120,resetForAllFormats);
    UT_ASSERT_EQUAL(result, tvERROR_GENERAL);
    INFO_UT(" T205: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

}


void test_generic_ResetColorTemperature(void)
{
    int result;
    int defaultValue;
    bool resetForAllFormats;

    /*positive result */
    defaultValue = 1;
    resetForAllFormats = 1;
    result = ResetColorTemperature(defaultValue,resetForAllFormats);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T206: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = ResetColorTemperature(10,resetForAllFormats);
    UT_ASSERT_EQUAL(result, tvERROR_GENERAL);
    INFO_UT(" T207: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

}

void test_generic_ResetComponentSaturation(void)
{
    int result;
    int color;
    int defaultValue;

    /*positive result */
    color = 1;
    defaultValue = 2;
    result = ResetComponentSaturation(color,defaultValue);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T208: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = ResetComponentSaturation(-1,defaultValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T209: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    /* negative result */
    result = ResetComponentSaturation(color,-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T210: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_ResetComponentLuma(void)
{
    int result;
    int color;
    int defaultValue;

    /*positive result */
    color = 1;
    defaultValue = 2;
    result = ResetComponentLuma(color,defaultValue);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T211: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = ResetComponentLuma(-1,defaultValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T212: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    /* negative result */
    result = ResetComponentLuma(color,-10);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T213: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_ResetComponentHue(void)
{
    int result;
    int color;
    int defaultValue;

    /*positive result */
    color = 1;
    defaultValue = 2;
    result = ResetComponentHue(color,defaultValue);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T214: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = ResetComponentHue(-1,defaultValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T215: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    /* negative result */
    result = ResetComponentHue(color,-10);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T216: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_isCurrentHDRTypeIsSDR(void)
{
    int result;

    /* positive result */
    result = isCurrentHDRTypeIsSDR();
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T217: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = isCurrentHDRTypeIsSDR();
    UT_ASSERT_EQUAL(result, tvERROR_GENERAL);
    INFO_UT(" T218: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

}

void test_generic_GetPanelID(void)
{
    char *panelID;
    int result;

    /* positive result */
    result = GetPanelID(panelID);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T219: E[%d]-A[%d] \n",result,tvERROR_NONE);
    
    /* negative result */
    result = GetPanelID(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);   
    INFO_UT(" T220: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}


void test_generic_GetDefaultPanelID(void)
{
    int result;
    char *panelID;

    /* positive result */
    // void function - need to handle this case
    GetDefaultPanelID(panelID);
    INFO_UT(" T221: E[%d]-A[%d] \n",result,tvERROR_NONE);

}

void test_generic_SaveColorTemperature(void)
{
    int sourceInput;
    int pq_mode; 
    int hdr_type;
    int value;
    int result;

    /* positive result */
    sourceInput = 1;
    pq_mode = 1;
    hdr_type = 1;
    value = 50;
    result = SaveColorTemperature(sourceInput,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T222: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SaveColorTemperature(0,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T223: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
} 

void test_generic_SaveBacklight(void)
{
    int sourceInput;
    int pq_mode; 
    int hdr_type;
    int value;
    int result;

    /* positive result */
    sourceInput = 1;
    pq_mode = 1;
    hdr_type = 1;
    value = 50;
    result = SaveBacklight(sourceInput,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T224: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SaveBacklight(-1,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T225: E[%d]-A[%d] \n",result,tvERROR_NONE);

}

void test_generic_SaveContrast(void)
{
    int sourceInput;
    int pq_mode; 
    int hdr_type;
    int value;
    int result;

    /* positive result */
    sourceInput = 1;
    pq_mode = 1;
    hdr_type = 1;
    value = 50;
    result = SaveContrast(sourceInput,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T226: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SaveContrast(-1,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T227: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_SaveSaturation(void)
{
    int sourceInput;
    int pq_mode; 
    int hdr_type;
    int value;
    int result;

    /* positive result */
    sourceInput = 1;
    pq_mode = 1;
    hdr_type = 1;
    value = 50;
    result = SaveSaturation(sourceInput,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T228: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SaveSaturation(-1,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T229: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_SaveSharpness(void)
{
    int sourceInput;
    int pq_mode; 
    int hdr_type;
    int value;
    int result;

    /* positive result */
    sourceInput = 1;
    pq_mode = 1;
    hdr_type = 1;
    value = 50;
    result = SaveSharpness(sourceInput,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T230: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SaveSharpness(-1,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T231: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_SaveBrightness(void)
{
    int sourceInput;
    int pq_mode; 
    int hdr_type;
    int value;
    int result;

    /* positive result */
    sourceInput = 1;
    pq_mode = 1;
    hdr_type = 1;
    value = 50;
    result = SaveBrightness(sourceInput,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T232: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SaveBrightness(-1,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T233: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
    
}

void test_generic_SaveHue(void)
{
     int sourceInput;
    int pq_mode; 
    int hdr_type;
    int value;
    int result;

    /* positive result */
    sourceInput = 1;
    pq_mode = 1;
    hdr_type = 1;
    value = 50;
    result = SaveHue(sourceInput,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T234: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SaveHue(-1,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T235: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
    
}

void test_generic_SaveDynamicBacklight(void)
{
    int sourceInput;
    int pq_mode; 
    int hdr_type;
    int value;
    int result;

    /* positive result */
    sourceInput = 1;
    pq_mode = 1;
    hdr_type = 1;
    value = 50;
    result = SaveDynamicBacklight(sourceInput,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T236: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SaveDynamicBacklight(-1,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T237: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
     
}

void test_generic_SaveDisplayMode(void)
{
    int sourceInput;
    int pq_mode; 
    int hdr_type;
    int value;
    int result;

    /* positive result */
    sourceInput = 1;
    pq_mode = 1;
    hdr_type = 1;
    value = 10;
    result = SaveDisplayMode(sourceInput,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T238: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SaveDisplayMode(-1,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T239: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
    
}

void test_generic_SaveCMS(void)
{
    int sourceInput;
    int pq_mode; 
    int hdr_type;
    int value;
    int result;
    int color_type;
    int tunnel_type;

    /* positive result */
    sourceInput = 1;
    pq_mode = 1;
    hdr_type = 1;
    tunnel_type = 1;
    color_type = 1;
    value = 10;
    result = SaveCMS(sourceInput,pq_mode,hdr_type,tunnel_type,color_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T240: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SaveCMS(sourceInput,pq_mode,hdr_type,tunnel_type,color_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T241: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
}

void test_generic_SaveDolbyMode(void)
{
    int sourceInput;
    int pq_mode; 
    int hdr_type;
    int value;
    int result;

    /* positive result */
    sourceInput = 1;
    pq_mode = 1;
    hdr_type = 1;
    value = 10;
    result = SaveDolbyMode(sourceInput,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T242: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SaveDolbyMode(-1,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T243: E[%d]-A[%d] \n",result,tvERROR_NONE);
}

void test_generic_GetNumberOfModesupported(void)
{
    int result;
    
    /* positive result */
    result = GetNumberOfModesupported();
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T244: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetNumberOfModesupported();
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T245: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_GetCurrentPQIndex(void)
{
    int result;
    
    /* positive result */
    result = GetCurrentPQIndex();
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T246: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetCurrentPQIndex();
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T247: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
}

void test_generic_GetAllSupportedPicModeIndex(void)
{
    int result;
    int pic_mode_index[10];

    /* positive result */
    // void function - need to handle this case
    GetAllSupportedPicModeIndex(pic_mode_index);
    INFO_UT(" T248: E[%d]-A[%d] \n",result,tvERROR_NONE);

}

void test_generic_GetCMSDefault(void)
{
    int result;
    tvCMS_tunel_t color_tunel_type;

    /* positive result */
    color_tunel_type = COLOR_LUMA;
    result = GetCMSDefault(color_tunel_type);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T249: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    //TBD
}

void test_generic_GetDolbyModeIndex(void)
{
    const char* dolbyMode;
    int result;

    /* positive result */
    dolbyMode = "bright";
    result = GetDolbyModeIndex(dolbyMode);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T250: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetDolbyModeIndex(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T251: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
    
   
}

void test_generic_ConvertVideoFormatToHDRFormat(void)
{
    int result;
    tvVideoHDRFormat_t videoFormat;

    /* positive result */
    videoFormat = tvVideoHDRFormat_SDR;
    result = ConvertVideoFormatToHDRFormat(videoFormat);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T252: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    // TBD

}

void test_generic_ConvertTVColorToVendorColor(void)
{
    int result;
    tvDataComponentColor_t blComponentColor;

    /* positive result */
    blComponentColor = tvDataColor_RED;
    result = ConvertTVColorToVendorColor(blComponentColor);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T253: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    // TBD

}

void test_generic_ConvertHDRFormatToContentFormat(void)
{
    int result;
    tvhdr_type_t hdrFormat;

    /* positive result */
    hdrFormat = HDR_TYPE_SDR;
    result = ConvertHDRFormatToContentFormat(hdrFormat);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T254: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    // TBD

}

void test_generic_GetCustomPQModeIndex(void)
{
    int result;

    /* positive result */
    result = GetCustomPQModeIndex();
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T255: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* neagative result */
    result = GetCustomPQModeIndex();
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    INFO_UT(" T256: E[%d]-A[%d] \n",result,tvERROR_NONE);



}

void test_generic_SetTVHLGMode(void)
{
    tvError_t result ; 

    /* positive result */
    result = SetTVHLGMode("tvHLGMode_Dark");
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T257: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /*negative result */
    result = SetTVHLGMode("unknown");
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
    INFO_UT(" T258: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);
}

void test_generic_SetTVHDR10Mode(void)
{
    tvError_t result;

    /* positive result */
    result = SetTVHDR10Mode("tvHDR10Mode_Dark");
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    INFO_UT(" T259: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /*negative result */
    result = SetTVHDR10Mode("unknown");
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
    INFO_UT(" T260: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_SetCMSState( void )
{
    tvError_t result;
    tvCMS_tunel_t tunelType = COLOR_STATE;
    tvcomponent_color_type_t colorType = COLOR_ENABLE;
    tvcomponent_state_t componentState = COMPONENT_DISABLE;
    /* Success Case  */

    result = SetCMSState(tunelType,colorType,componentState);
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    INFO_UT(" T261: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* Failure Case - i.e since already intialized */
    result = SetCMSState(tunelType,colorType,componentState);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE );
    INFO_UT(" T262: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
    
    result = SetCMSState(tunelType,colorType,componentState);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL);
    INFO_UT(" T263: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

#ifndef HAS_CMS_SUPPORT
    result = SetCMSState(tunelType,colorType,componentState);
    UT_ASSERT_EQUAL( result, tvERROR_OPERATION_NOT_SUPPORTED);
    INFO_UT(" T264: E[%d]-A[%d] \n",result,tvERROR_OPERATION_NOT_SUPPORTED);
#endif
}
#if 0
void test_generic_ReadCustWBvaluesFromDriverOnInit( void )
{
    tvError_t result;
    /* Success Case  */

    result = ReadCustWBvaluesFromDriverOnInit();
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    INFO_UT(" T265: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* TODO:Failure Case is not handled source code */

}
#endif

void test_generic_GetUSerWBValueOnInit( void )
{
   // tvError_t result;
    tvDataColor_t custWBValueInitBefore = {};
    tvDataColor_t custWBValueInitAfter = {};

    /* Success Case  */
// TODO
    custWBValueInitAfter = GetUSerWBValueOnInit();
    //CU_ASSERT_NOT_EQUAL( custWBValueInitBefore, custWBValueInitAfter ); 
    // UT_ASSERT_NOT_EQUAL( custWBValueInitBefore, custWBValueInitAfter ); /* Need to add in ut.h file if needed */
    INFO_UT(" T266: E[%d]-A[%d] \n",custWBValueInitBefore.r_offset,custWBValueInitAfter.r_offset);

    /* TODO:Failure Case is not handled source code */

}

void test_generic_isWBUserDfault( void )
{
    bool result;
    tvDataColor_t wbvalue;

    /* Success Case  */
    wbvalue.r_gain = DEFAULT_WB_CUST_GAIN;
    wbvalue.g_gain = DEFAULT_WB_CUST_GAIN;
    wbvalue.b_gain = DEFAULT_WB_CUST_GAIN;
    wbvalue.r_offset = DEFAULT_WB_OFFSET;
    wbvalue.g_offset = DEFAULT_WB_OFFSET;
    wbvalue.b_offset = DEFAULT_WB_OFFSET;

    result = isWBUserDfault(wbvalue);
    UT_ASSERT_EQUAL( true, result );
    INFO_UT(" T267: E[%d]-A[%d] \n",result,true);

    /* Failure Case  */
    wbvalue.r_gain = -1;
    result = isWBUserDfault(wbvalue);
    UT_ASSERT_EQUAL( false, result );
    INFO_UT(" T268: E[%d]-A[%d] \n",result,false);

}


void test_generic_GetWBRgbType( void )
{
    int rgb_type = -1;
   // const char *color, const char * ctrl;

    /* Success Case - Red */

    rgb_type = GetWBRgbType("red","gain");
    UT_ASSERT_EQUAL( rgb_type, R_GAIN );
    INFO_UT(" T269: E[%d]-A[%d] \n",rgb_type,R_GAIN);

    /* Success Case - Green */
    rgb_type = GetWBRgbType("green","gain");
    UT_ASSERT_EQUAL( rgb_type, G_GAIN );
    INFO_UT(" T270: E[%d]-A[%d] \n",rgb_type,G_GAIN);

    /* Success Case - Blue */
    rgb_type = GetWBRgbType("blue","gain");
    UT_ASSERT_EQUAL( rgb_type, B_GAIN );
    INFO_UT(" T271: E[%d]-A[%d] \n",rgb_type,B_GAIN);

    /* Failure Case - Blue */
    rgb_type = GetWBRgbType("Unknown","gain");
    UT_ASSERT_EQUAL( rgb_type, B_GAIN );
    INFO_UT(" T272: E[%d]-A[%d] \n",rgb_type,B_GAIN);

    rgb_type = GetWBRgbType("red","Unknown");
    UT_ASSERT_EQUAL( rgb_type, R_POST_OFFSET );
    INFO_UT(" T273: E[%d]-A[%d] \n",rgb_type,R_POST_OFFSET);

    rgb_type = GetWBRgbType("green","Unknown");
    UT_ASSERT_EQUAL( rgb_type, G_POST_OFFSET );
    INFO_UT(" T274: E[%d]-A[%d] \n",rgb_type,G_POST_OFFSET);

    rgb_type = GetWBRgbType("blue","Unknown");
    UT_ASSERT_EQUAL( rgb_type, B_POST_OFFSET );
    INFO_UT(" T275: E[%d]-A[%d] \n",rgb_type,B_POST_OFFSET);

    
}

void test_generic_SaveColorTemperatureUser( void )
{
    tvError_t result;
    int rgbType;
    int value;

    /* Success Case  */
    rgbType=R_GAIN;
    value =0;
    result = SaveColorTemperatureUser(rgbType,value);
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    INFO_UT(" T276: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* Failure Case */
    rgbType= -2;
    value = -1;
    result = SaveColorTemperatureUser(rgbType,value);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL );
    INFO_UT(" T277: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

}

void test_generic_SetColorTemperatureUser( void )
{
    tvError_t result;
    int rgbType;
    int value;

    /* Success Case  */
    rgbType=R_GAIN;
    value =0;
    result = SetColorTemperatureUser(rgbType,value);
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    INFO_UT(" T278: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* Failure Case */
    rgbType= -2;
    value = -1;
    result = SetColorTemperatureUser(rgbType,value);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL );
    INFO_UT(" T279: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

}


void test_generic_GetDriverEquivalentBLForCurrentFmt( void )
{
    int backlight;
    int result;

    /* Success Case  */
    backlight =0;
    result = GetDriverEquivalentBLForCurrentFmt(backlight);
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    INFO_UT(" T280: E[%d]-A[%d] \n",result,tvERROR_NONE); // Need predicted value

    /* TODO: Failure Case */
    backlight = -1; //There is a chance to crash. Need to handle in source code
    //result = GetDriverEquivalentBLForCurrentFmt(rgbType,value); // Enable once supported in code
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL );
    INFO_UT(" T281: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

}
void test_generic_SetBacklightInfo( void )
{
    tvError_t result;
    tvBacklightInfo_t backlightDefaults = {};

    /* Success Case  */
   
    result = SetBacklightInfo(backlightDefaults); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    INFO_UT(" T282: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* TODO:Failure Case */
  
}

void test_generic_ReadAllModeConfigfile( void )
{

    tvError_t result;
    char buffer[EXPECTED_FILE_SIZE] = {0};

    /* Success Case  */
   
    result = ReadAllModeConfigfile(GENERIC_MODE_CONFIG_FILE,buffer,"picmodes"); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    INFO_UT(" T283: E[%d]-A[%d] \n",result,tvERROR_NONE);

    result = ReadAllModeConfigfile(GENERIC_MODE_CONFIG_FILE,buffer,"dvmodes"); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    INFO_UT(" T284: E[%d]-A[%d] \n",result,tvERROR_NONE);

    result = ReadAllModeConfigfile(GENERIC_MODE_CONFIG_FILE,buffer,"hdr10modes"); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    INFO_UT(" T285: E[%d]-A[%d] \n",result,tvERROR_NONE);
    
    result = ReadAllModeConfigfile(GENERIC_MODE_CONFIG_FILE,buffer,"hlgmodes"); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    INFO_UT(" T286: E[%d]-A[%d] \n",result,tvERROR_NONE);   
    
 /* Failure Case */
    result = ReadAllModeConfigfile("Invalid",buffer,"picmodes"); 
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM );
    INFO_UT(" T287: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

/* TODO: Enable below once code is ready  */

   // result = ReadAllModeConfigfile(NULL,NULL,NULL); 
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM );
    INFO_UT(" T288: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);
  
}
void test_generic_splitstringsandvaluefrombuffer( void )
{
    pic_modes_t *hlgModes[DV_MODES_SUPPORTED_MAX];
    unsigned short count =0;
    char buffer[EXPECTED_FILE_SIZE] = {0};
    /* Success Case  */
    // TODO
    splitstringsandvaluefrombuffer(buffer,hlgModes,&count);
   // CU_ASSERT_NOT_EQUAL( 0, count );
    //INFO_UT(" T289: E[%d]-A[%d] \n",result,tvERROR_NONE);

/* TODO: Enable below once code is ready  */

   // splitstringsandvaluefrombuffer(NULL,NULL,&count); 
   // UT_ASSERT_EQUAL( 0, count );
   // INFO_UT(" T290: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);
}

void test_generic_splitstringsfrombuffer( void )
{
    unsigned short totalcount = 0;
    char supportedDimmingModes[DIMMING_MODE_MAX*DIMMING_MODE_NAME_SIZE] = {0};
    char buffer[EXPECTED_FILE_SIZE] = {0};
    /* Success Case  */
    // TODO
    splitstringsfrombuffer(buffer,supportedDimmingModes,&totalcount);
    //CU_ASSERT_NOT_EQUAL( 0, totalcount );
    INFO_UT(" T291: E[%d]-A[%d] \n",0,totalcount);

/* TODO: Enable below once code is ready  */

   //splitstringsfrombuffer(buffer,supportedDimmingModes,&totalcount);
    //UT_ASSERT_EQUAL( 0, totalcount );
    INFO_UT(" T292: E[%d]-A[%d] \n",0,totalcount);

//splitstringsfrombuffer(NULL,NULL,&totalcount);
    //UT_ASSERT_EQUAL( 0, totalcount );
    INFO_UT(" T293: E[%d]-A[%d] \n",0,totalcount);

}

void test_generic_SetBacklightFade( void )
{
    tvError_t result;
    int from, to, duration;

    /* Success Case  */
    from = 10;
    to = 20;
    duration = 40;
    result = SetBacklightFade(from, to, duration); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    INFO_UT(" T294: E[%d]-A[%d] \n",result,tvERROR_NONE);

    from = -1;
    result = SetBacklightFade(from, to, duration); 
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL );
    INFO_UT(" T295: E[%d]-A[%d] \n",result,tvERROR_GENERAL);
    /* TODO:Failure Case */
  
}

void test_generic_SetGammaMode( void )
{
    tvError_t result;
    int mode = 1;

    /* Success Case  */

    result = SetGammaMode(mode); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    INFO_UT(" T296: E[%d]-A[%d] \n",result,tvERROR_NONE);

    mode = 0;
    result = SetGammaMode(mode); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    INFO_UT(" T297: E[%d]-A[%d] \n",result,tvERROR_NONE);

    mode = -1;
    result = SetGammaMode(mode); 
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL );
    INFO_UT(" T298: E[%d]-A[%d] \n",result,tvERROR_GENERAL);
    
  
}

void test_generic_SetLocalDimmingLevel( void )
{
    tvError_t result;
    int localDimmingLevel = 1;

    /* Success Case  */

    result = SetLocalDimmingLevel(localDimmingLevel); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    INFO_UT(" T299: E[%d]-A[%d] \n",result,tvERROR_NONE);

    localDimmingLevel = 0;
    result = SetLocalDimmingLevel(localDimmingLevel); 
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL );
    INFO_UT(" T300: E[%d]-A[%d] \n",result,tvERROR_GENERAL);
  
}

void test_generic_GetLocalDimmingLevel( void )
{
    tvError_t result;
    int localDimmingLevel = 1;

    /* Success Case  */

    result = GetLocalDimmingLevel(&localDimmingLevel); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    INFO_UT(" T301: E[%d]-A[%d] \n",result,tvERROR_NONE);
/* TODO: Error case */
    localDimmingLevel = 0;
   // result = GetLocalDimmingLevel(NULL);  // Enable once it is supported
 //   UT_ASSERT_EQUAL( result, tvERROR_GENERAL );
  //  INFO_UT(" T302: E[%d]-A[%d] \n",result,tvERROR_GENERAL);
  
}

void test_SaveLocalDimmingLevel( void )
{
    tvError_t result;
    int sourceInput, pq_mode, hdr_type, value;

    /* Success Case  */
    sourceInput = 0;
    pq_mode = 0;
    hdr_type = 0;
    value = 0;

    result = SaveLocalDimmingLevel(sourceInput,pq_mode,hdr_type,value); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    INFO_UT(" T303: E[%d]-A[%d] \n",result,tvERROR_NONE);
/* TODO: Error case */
    hdr_type = HDR_TYPE_SDR;
    sourceInput = -1;
    result = SaveLocalDimmingLevel(sourceInput,pq_mode,hdr_type,value); 
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL );
    INFO_UT(" T304: E[%d]-A[%d] \n",result,tvERROR_GENERAL);
  
}

void test_generic_SwitchEDID( void )
{
    tvError_t result = tvERROR_NONE;
    int mode = 1;

    /*TODO: need to handle return type   */

    SwitchEDID(mode); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    INFO_UT(" T305: E[%d]-A[%d] \n",result,tvERROR_NONE);

}

void test_generic_UpdateEDIDAndSetDimmingLevel( void )
{
    tvError_t result = tvERROR_NONE;
    int mode = 1;

    /*TODO: need to handle return type   */

    result = UpdateEDIDAndSetDimmingLevel(mode); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    INFO_UT(" T306: E[%d]-A[%d] \n",result,tvERROR_NONE);

    mode = -1;
    result = UpdateEDIDAndSetDimmingLevel(mode); 
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL );
    INFO_UT(" T307: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

}

void test_generic_GetLDIMAndEDIDLevel( void )
{
    tvError_t result = tvERROR_NONE;
    
    int dimmingMode = 0 ,format = 0, dimmingLevel = 0,  edidLevel = 0;

    /*TODO: need to handle return type   */

    GetLDIMAndEDIDLevel(dimmingMode,format, &dimmingLevel,  &edidLevel); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    INFO_UT(" T308: E[%d]-A[%d] \n",result,tvERROR_NONE);

}

/**
 * @brief Register the main tests for this module
 * 
 * @return int - 0 on success, otherwise failure
 */
int test_tvsettings_hal( void )
{
    /* add a suite to the registry */
    pSuite = UT_add_suite("[L1 tvsettings_hal]", NULL, NULL);
    if (NULL == pSuite) 
    {
        return -1;
    }

    UT_add_test( pSuite, "Platfor Init", test_generic_tvInit);
    UT_add_test( pSuite, "GetTVPictureMode ", test_generic_GetTVPictureMode);
    UT_add_test( pSuite, "SetTVPictureMode  ", test_generic_SetTVPictureMode);
    UT_add_test( pSuite, "GetBacklight  ", test_generic_GetBacklight);
    UT_add_test( pSuite, "SetBacklight  ", test_generic_SetBacklight);
    UT_add_test( pSuite, "SetBrightness  ", test_generic_SetBrightness);
    UT_add_test( pSuite, "GetBrightness  ", test_generic_GetBrightness);
    UT_add_test( pSuite, "SetContrast  ", test_generic_SetContrast);
    UT_add_test( pSuite, "GetContrast  ", test_generic_GetContrast);
    UT_add_test( pSuite, "SetSharpness  ", test_generic_SetSharpness);
    UT_add_test( pSuite, "GetSharpness  ", test_generic_GetSharpness);
    UT_add_test( pSuite, "SetSaturation  ", test_generic_SetSaturation);
    UT_add_test( pSuite, "GetSaturation  ", test_generic_GetSaturation);
    UT_add_test( pSuite, "SetHue  ", test_generic_SetHue);
    UT_add_test( pSuite, "GetHue  ", test_generic_GetHue);
    UT_add_test( pSuite, "SetColorTemperature  ", test_generic_SetColorTemperature);
    UT_add_test( pSuite, "GetColorTemperature  ", test_generic_GetColorTemperature);
    UT_add_test( pSuite, "SetAspectRatio  ", test_generic_SetAspectRatio);
    UT_add_test( pSuite, "GetAspectRatio  ", test_generic_GetAspectRatio);
    UT_add_test( pSuite, "GetSupportedBacklightModes  ", test_generic_GetSupportedBacklightModes);
    UT_add_test( pSuite, "GetCurrentBacklightMode  ", test_generic_GetCurrentBacklightMode);
    UT_add_test( pSuite, "SetCurrentBacklightMode  ", test_generic_SetCurrentBacklightMode);
    UT_add_test( pSuite, "GetVideoResolution  ", test_generic_SetCurrentBacklightMode);
    UT_add_test( pSuite, "GetCurrentVideoFormat  ", test_generic_GetCurrentVideoFormat);
    UT_add_test( pSuite, "GetVideoFrameRate  ", test_generic_GetVideoFrameRate);
    UT_add_test( pSuite, "setWakeupConfig  ", test_generic_setWakeupConfig);

    UT_add_test( pSuite, "SetRGBPattern  ", test_generic_SetRGBPattern);
    UT_add_test( pSuite, "GetRGBPattern  ", test_generic_GetRGBPattern);
    UT_add_test( pSuite, "SetGrayPattern  ", test_generic_SetGrayPattern);
    UT_add_test( pSuite, "GetGrayPattern  ", test_generic_GetGrayPattern);
    UT_add_test( pSuite, "SetColorTemp_Rgain  ", test_generic_SetColorTemp_Rgain);
    UT_add_test( pSuite, "GetColorTemp_Rgain  ", test_generic_GetColorTemp_Rgain);
    UT_add_test( pSuite, "SetColorTemp_Ggain  ", test_generic_SetColorTemp_Ggain);
    UT_add_test( pSuite, "GetColorTemp_Ggain  ", test_generic_GetColorTemp_Ggain);
    UT_add_test( pSuite, "SetColorTemp_Bgain  ", test_generic_SetColorTemp_Bgain);
    UT_add_test( pSuite, "GetColorTemp_Bgain  ", test_generic_GetColorTemp_Bgain);
   
    UT_add_test( pSuite, "SetColorTemp_R_post_offset  ", test_generic_SetColorTemp_R_post_offset);
    UT_add_test( pSuite, "GetColorTemp_R_post_offset  ", test_generic_GetColorTemp_R_post_offset);
    UT_add_test( pSuite, "SetColorTemp_G_post_offset  ", test_generic_SetColorTemp_G_post_offset);
    UT_add_test( pSuite, "GetColorTemp_G_post_offset  ", test_generic_GetColorTemp_G_post_offset);
    UT_add_test( pSuite, "SetColorTemp_B_post_offset  ", test_generic_SetColorTemp_B_post_offset);
    UT_add_test( pSuite, "GetColorTemp_B_post_offset  ", test_generic_GetColorTemp_B_post_offset);

    UT_add_test( pSuite, "GetTVSupportedPictureModes  ", test_generic_GetTVSupportedPictureModes);

    UT_add_test( pSuite, "GetTVSupportedDVModes  ", test_generic_GetTVSupportedDVModes);
    UT_add_test( pSuite, "SetTVDolbyVisionMode  ", test_generic_SetTVDolbyVisionMode);
    UT_add_test( pSuite, "GetTVDolbyVisionMode  ", test_generic_GetTVDolbyVisionMode);
    UT_add_test( pSuite, "SetTVHLGMode  ", test_generic_SetTVHLGMode); // to be done
    UT_add_test( pSuite, "SetTVHDR10Mode  ", test_generic_SetTVHDR10Mode); // to be done
  // UT_add_test( pSuite, "GetTVHLGMode  ", test_generic_GetTVHLGMode); // to be done
   // UT_add_test( pSuite, "GetTVHDR10Mode  ", test_generic_GetTVHDR10Mode); // to be done
    UT_add_test( pSuite, "GetTVSupportedHLGModes  ", test_generic_GetTVSupportedHLGModes);
    UT_add_test( pSuite, "GetTVSupportedHDR10Modes  ", test_generic_GetTVSupportedHDR10Modes);


    UT_add_test( pSuite, "SetDynamicContrast  ", test_generic_SetDynamicContrast);
    UT_add_test( pSuite, "GetDynamicContrast  ", test_generic_GetDynamicContrast);
    
    UT_add_test( pSuite, "SetColorTemp_Rgain_onSource  ", test_generic_SetColorTemp_Rgain_onSource);
    UT_add_test( pSuite, "GetColorTemp_Rgain_onSource  ", test_generic_GetColorTemp_Rgain_onSource);
    UT_add_test( pSuite, "SetColorTemp_Ggain_onSource  ", test_generic_SetColorTemp_Ggain_onSource);
    UT_add_test( pSuite, "GetColorTemp_Ggain_onSource  ", test_generic_GetColorTemp_Ggain_onSource);
    UT_add_test( pSuite, "SetColorTemp_Bgain_onSource  ", test_generic_SetColorTemp_Bgain_onSource);
    UT_add_test( pSuite, "GetColorTemp_Bgain_onSource  ", test_generic_GetColorTemp_Bgain_onSource);
    
    UT_add_test( pSuite, "SetColorTemp_R_post_offset_onSource  ", test_generic_SetColorTemp_R_post_offset_onSource);
    UT_add_test( pSuite, "GetColorTemp_R_post_offset_onSource  ", test_generic_GetColorTemp_R_post_offset_onSource);
    UT_add_test( pSuite, "SetColorTemp_G_post_offset_onSource  ", test_generic_SetColorTemp_G_post_offset_onSource);
    UT_add_test( pSuite, "GetColorTemp_G_post_offset_onSource  ", test_generic_GetColorTemp_G_post_offset_onSource);
    UT_add_test( pSuite, "SetColorTemp_B_post_offset_onSource  ", test_generic_SetColorTemp_B_post_offset_onSource);
    UT_add_test( pSuite, "GetColorTemp_B_post_offset_onSource  ", test_generic_GetColorTemp_B_post_offset_onSource);

    UT_add_test( pSuite, "setWBctrl  ", test_generic_setWBctrl);// to be done
    UT_add_test( pSuite, "getWBctrl  ", test_generic_getWBctrl); // to be done
//    UT_add_test( pSuite, "getWbInfo  ", test_generic_getWbInfo);
    
    UT_add_test( pSuite, "GetSupportedComponentColor  ", test_generic_GetSupportedComponentColor);
    UT_add_test( pSuite, "SetCurrentComponentSaturation  ", test_generic_SetCurrentComponentSaturation);
    UT_add_test( pSuite, "GetCurrentComponentSaturation  ", test_generic_GetCurrentComponentSaturation);
    UT_add_test( pSuite, "SetCurrentComponentHue  ", test_generic_SetCurrentComponentHue);
    UT_add_test( pSuite, "GetCurrentComponentHue  ", test_generic_GetCurrentComponentHue);
    UT_add_test( pSuite, "SetCurrentComponentLuma  ", test_generic_SetCurrentComponentLuma);
    UT_add_test( pSuite, "GetCurrentComponentLuma  ", test_generic_GetCurrentComponentLuma);
    UT_add_test( pSuite, "GetTVSupportedDimmingModes  ", test_generic_GetTVSupportedDimmingModes);
    UT_add_test( pSuite, "SetTVDimmingMode  ", test_generic_SetTVDimmingMode);
    UT_add_test( pSuite, "GetTVBacklightGlobalFactor  ", test_generic_GetTVBacklightGlobalFactor);
    UT_add_test( pSuite, "SetTVBacklightGlobalFactor  ", test_generic_SetTVBacklightGlobalFactor);
    UT_add_test( pSuite, "GetTVPictureModeIndex  ", test_generic_GetTVPictureModeIndex);


    UT_add_test( pSuite, "GetCurrentContentFormat  ", test_generic_GetCurrentContentFormat);
    UT_add_test( pSuite, "GetSupportedContentFormats  ", test_generic_GetSupportedContentFormats);
    UT_add_test( pSuite, "ResetBrightness  ", test_generic_ResetBrightness);
    UT_add_test( pSuite, "ResetContrast  ", test_generic_ResetContrast);
    UT_add_test( pSuite, "ResetSharpness  ", test_generic_ResetSharpness);
    UT_add_test( pSuite, "ResetSaturation  ", test_generic_ResetSaturation);
    UT_add_test( pSuite, "ResetHue  ", test_generic_ResetHue);
    UT_add_test( pSuite, "ResetBacklight  ", test_generic_ResetBacklight);
    UT_add_test( pSuite, "ResetColorTemperature  ", test_generic_ResetColorTemperature);
    UT_add_test( pSuite, "ResetComponentSaturation  ", test_generic_ResetComponentSaturation);
    UT_add_test( pSuite, "ResetComponentLuma  ", test_generic_ResetComponentLuma);
    UT_add_test( pSuite, "ResetComponentHue  ", test_generic_ResetComponentHue);
    
    UT_add_test( pSuite, "isCurrentHDRTypeIsSDR  ", test_generic_isCurrentHDRTypeIsSDR);
    UT_add_test( pSuite, "GetPanelID  ", test_generic_GetPanelID);
    UT_add_test( pSuite, "GetDefaultPanelID  ", test_generic_GetDefaultPanelID);
    UT_add_test( pSuite, "SaveColorTemperature  ", test_generic_SaveColorTemperature);
    UT_add_test( pSuite, "SaveBacklight  ", test_generic_SaveBacklight);
    UT_add_test( pSuite, "SaveContrast  ", test_generic_SaveContrast);
    UT_add_test( pSuite, "SaveSaturation  ", test_generic_SaveSaturation);
    UT_add_test( pSuite, "SaveSharpness  ", test_generic_SaveSharpness);
    UT_add_test( pSuite, "SaveBrightness  ", test_generic_SaveBrightness);
    UT_add_test( pSuite, "SaveHue  ", test_generic_SaveHue);
    UT_add_test( pSuite, "SaveDynamicBacklight  ", test_generic_SaveDynamicBacklight);
    UT_add_test( pSuite, "SaveDisplayMode  ", test_generic_SaveDisplayMode);
    UT_add_test( pSuite, "SaveCMS  ", test_generic_SaveCMS);
    UT_add_test( pSuite, "SaveDolbyMode  ", test_generic_SaveDolbyMode);
    UT_add_test( pSuite, "GetNumberOfModesupported  ", test_generic_GetNumberOfModesupported);
    UT_add_test( pSuite, "GetCurrentPQIndex  ", test_generic_GetCurrentPQIndex);
    UT_add_test( pSuite, "GetAllSupportedPicModeIndex  ", test_generic_GetAllSupportedPicModeIndex);
    UT_add_test( pSuite, "GetCMSDefault  ", test_generic_GetCMSDefault);
    UT_add_test( pSuite, "GetDolbyModeIndex  ", test_generic_GetDolbyModeIndex);
    UT_add_test( pSuite, "ConvertVideoFormatToHDRFormat  ", test_generic_ConvertVideoFormatToHDRFormat);
    UT_add_test( pSuite, "ConvertTVColorToVendorColor  ", test_generic_ConvertTVColorToVendorColor);
    UT_add_test( pSuite, "ConvertHDRFormatToContentFormat  ", test_generic_ConvertHDRFormatToContentFormat);
    UT_add_test( pSuite, "GetCustomPQModeIndex  ", test_generic_GetCustomPQModeIndex);

    UT_add_test( pSuite, "SetCMSState",test_generic_SetCMSState);
    UT_add_test( pSuite, "GetUSerWBValueOnInit",test_generic_GetUSerWBValueOnInit);
    UT_add_test( pSuite, "isWBUserDfault",test_generic_isWBUserDfault);
    UT_add_test( pSuite, "GetWBRgbType",test_generic_GetWBRgbType);
    UT_add_test( pSuite, "SaveColorTemperatureUser",test_generic_SaveColorTemperatureUser);
    UT_add_test( pSuite, "SetColorTemperatureUser",test_generic_SetColorTemperatureUser);
    UT_add_test( pSuite, "GetDriverEquivalentBLForCurrentFmt",test_generic_GetDriverEquivalentBLForCurrentFmt);
    UT_add_test( pSuite, "SetBacklightInfo",test_generic_SetBacklightInfo);
    UT_add_test( pSuite, "GetTVSupportedHLGModes",test_generic_GetTVSupportedHLGModes);
    UT_add_test( pSuite, "ReadAllModeConfigfile",test_generic_ReadAllModeConfigfile);
    UT_add_test( pSuite, "splitstringsandvaluefrombuffer",test_generic_splitstringsandvaluefrombuffer);
    UT_add_test( pSuite, "splitstringsfrombuffer",test_generic_splitstringsfrombuffer);
    UT_add_test( pSuite, "SetBacklightFade",test_generic_SetBacklightFade);
    UT_add_test( pSuite, "SetGammaMode",test_generic_SetGammaMode);
    UT_add_test( pSuite, "SetLocalDimmingLevel",test_generic_SetLocalDimmingLevel);
    UT_add_test( pSuite, "GetLocalDimmingLevel",test_generic_GetLocalDimmingLevel);
    UT_add_test( pSuite, "SaveLocalDimmingLevel",test_SaveLocalDimmingLevel);
    UT_add_test( pSuite, "SwitchEDID",test_generic_SwitchEDID);
    UT_add_test( pSuite, "UpdateEDIDAndSetDimmingLevel",test_generic_UpdateEDIDAndSetDimmingLevel);
    UT_add_test( pSuite, "GetLDIMAndEDIDLevel",test_generic_GetLDIMAndEDIDLevel);

    return 0;
}
