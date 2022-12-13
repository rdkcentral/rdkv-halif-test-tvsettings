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

#include <ut.h>
#include <ut_log.h>

pic_modes_t *availableModes;

#define DV_MODES_SUPPORTED_MAX (3)
#define DEFAULT_WB_OFFSET       (0)
#define DEFAULT_WB_ZERO_GAIN     (0)
#define DEFAULT_WB_CUST_GAIN     (1024)

static UT_test_suite_t *pSuite = NULL;

void test_generic_tvInit( void )
{
    int result;

    /* Positive result */
    result = tvInit();
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    UT_LOG(" T1: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /*calling tvInit should succeed, As it will not return any error since already initialised */
    result = tvInit();
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T2: E[%d]-A[%d] \n",result,tvERROR_NONE);
    
    /* #TODO: Unclear how the function will fail, maybe this function should be void? */
    
}


void test_generic_tvTerm( void )
{
    int result;

    /* Positive result */
    result = tvTerm();
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    UT_LOG(" T3: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /*calling tvInit should succeed, As it will not return any error since already initialised */
    result = tvTerm();
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T4: E[%d]-A[%d] \n",result,tvERROR_NONE);

        /* #TODO: Unclear how the function will fail, maybe this function should be void? */

}


void test_generic_GetTVPictureMode( void )
{

    int result;
    /* positive result */
    char picMode[PIC_MODE_NAME_MAX];
    result = GetTVPictureMode((char*)picMode);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T5: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* Negative Result */
    result = GetTVPictureMode((char*)picMode);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T6: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}


void test_generic_SetTVPictureMode( void )
{
    int result = 0;
    /* Positive result */



    result=SetTVPictureMode("tvPictureMode_COLORFUL");
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T7: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* Negative Result */
    result = SetTVPictureMode("none");
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL);
    UT_LOG(" T8: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

    result = SetTVPictureMode("tvPictureMode_MAX");
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T9: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);
    
}

void test_generic_GetBacklight(void )
{
   int result = 0;
   int value;
   /* Positive Result */
   value = tvBacklightMode_ECO;
   result = GetBacklight(&value);
   UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T10: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* Negative Result */
    value = tvBacklightMode_INVALID;
    result = GetBacklight(&value);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T11: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_SetBacklight( void )
{
    int result;
    /* Positive Result */
    result = SetBacklight(90);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T12: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* Negative Resukt */
    result = SetBacklight(120);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T13: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);


    result = SetBacklight(-1);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T14: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_SetBrightness( void )
{
    int result;

    /* positive result */
    result = SetBrightness(90);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T15: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetBrightness(110);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T16: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    result = SetBrightness(-10);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T17: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_GetBrightness( void )
{
   int result;
   int value;
   /* positive result */
    result = GetBrightness(&value);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T18: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetBrightness(&value);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T19: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_SetContrast( void )
{
    int result;

    /* positive result */
    result = SetContrast(90);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T20: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetContrast(-1);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T21: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    /* negative result */
    result = SetContrast(120);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T22: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);


}

void test_generic_GetContrast( void )
{
    int result;
    int value;

    /*positive result */
    result = GetContrast(&value);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T23: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* Negative Result */
    result = GetContrast(&value);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T24: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
   
}

void test_generic_SetSharpness( void )
{
    int result;

    /* positive result */
    result = SetSharpness(50);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T25: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* Negative Result */
    result = SetSharpness(-1);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T26: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    result = SetSharpness(110);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T27: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_GetSharpness( void )
{
    int result;
    int value;

    /* positive result */
    result = GetSharpness(&value);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T28: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetSharpness(&value);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T29: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_SetSaturation( void )
{
    int result;

    /* positive result */
    result = SetSaturation(80);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T30: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetSaturation(-1);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T31: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    result = SetSaturation(150);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T32: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_GetSaturation( void )
{
    int result;
    int value;

    /* positive result */
    result = GetSaturation(&value);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T33: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetSaturation(&value);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T34: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
    
}

void test_generic_SetHue( void )
{
    int result;

    /* positive result */
    result = SetHue(80);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T35: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetHue(-1);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T36: E[%d]-A[%d] \n",result,tvERROR_NONE);

    result = SetHue(150);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T37: E[%d]-A[%d] \n",result,tvERROR_NONE);

}

void test_generic_GetHue( void )
{
    int result;
    int value;

    /* positive result */
    result = GetHue(&value);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T38: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetHue(&value);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T39: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_SetColorTemperature( void )
{
    int result;
    tvColorTemp_t colorTemp;

    /*positive result */
    colorTemp = tvColorTemp_STANDARD;
    result = SetColorTemperature(colorTemp);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T40: E[%d]-A[%d] \n",result,tvERROR_NONE);

    colorTemp = tvColorTemp_WARM;
    result = SetColorTemperature(colorTemp);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T41: E[%d]-A[%d] \n",result,tvERROR_NONE);

    colorTemp = tvColorTemp_COLD;
    result = SetColorTemperature(colorTemp);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T42: E[%d]-A[%d] \n",result,tvERROR_NONE);

    colorTemp = tvColorTemp_USER;
    result = SetColorTemperature(colorTemp);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T43: E[%d]-A[%d] \n",result,tvERROR_NONE);

    colorTemp = tvColorTemp_MAX;
    result = SetColorTemperature(colorTemp);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T44: E[%d]-A[%d] \n",result,tvERROR_NONE);
    
    /* negative result */
    result = SetColorTemperature((tvColorTemp_t)10);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T45: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_GetColorTemperature( void )
{
    int result;
    tvColorTemp_t colorTemp;

    /* positive result */
    result = GetColorTemperature(&colorTemp);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T46: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetColorTemperature(&colorTemp);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T47: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);
    
}

void test_generic_SetAspectRatio( void )
{
    int result;
    
    /* positive result */
    result = SetAspectRatio(tvDisplayMode_NORMAL);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T48: E[%d]-A[%d] \n",result,tvERROR_NONE);

    result = SetAspectRatio(tvDisplayMode_ZOOM);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T49: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetAspectRatio((tvDisplayMode_t)10);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T50: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);


}

void test_generic_GetAspectRatio( void )
{

    int result;
    tvDisplayMode_t dispMode;
    /* positive result */
    result = GetAspectRatio(&dispMode);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T51: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetAspectRatio(&dispMode);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T52: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}


void test_generic_GetSupportedBacklightModes( void )
{

    int result;
    int blModes;

    /* positive result */
    result = GetSupportedBacklightModes(&blModes);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T53: E[%d]-A[%d] \n",result,tvERROR_NONE);

}

void test_generic_GetCurrentBacklightMode( void )
{

    int result;
    tvBacklightMode_t blMode;
    /* positive result */
    result = GetCurrentBacklightMode(&blMode);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T54: E[%d]-A[%d] \n",result,tvERROR_NONE);

}

void test_generic_SetCurrentBacklightMode( void )
{

    int result;
    tvBacklightMode_t blMode;
    /* positive result */
    blMode = tvBacklightMode_NONE;
    result = SetCurrentBacklightMode(blMode);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T55: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetCurrentBacklightMode((tvBacklightMode_t)10);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T56: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_GetCurrentVideoFormat( void )
{

    int result;
    tvVideoHDRFormat_t format;
    /* positive result */
    result = GetCurrentVideoFormat(&format);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T57: E[%d]-A[%d] \n",result,tvERROR_NONE);

}

void test_generic_GetVideoResolution( void )
{

    int result;
    tvResolutionParam_t resolutionstruct;
    /* positive result */
    result = GetVideoResolution(&resolutionstruct);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T58: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetVideoResolution(&resolutionstruct);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T59: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);


}

void test_generic_GetVideoFrameRate( void )
{

    int result;
    tvVideoFrameRate_t frameRate;
    /* positive result */
    result = GetVideoFrameRate(&frameRate);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T60: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetVideoFrameRate(NULL);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T61: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_setWakeupConfig( void )
{

    int result;
    tvWakeupSrcType_t setValue;
    /* positive result */
    setValue = tvWakeupSrc_BLUETOOTH;
    result = setWakeupConfig(setValue,1);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T62: E[%d]-A[%d] \n",result,tvERROR_NONE);

    result = setWakeupConfig(setValue,0);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T63: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = setWakeupConfig(setValue,0);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T64: E[%d]-A[%d] \n",result,tvERROR_NONE);

}

void test_generic_SetRGBPattern( void )
{

    int result;
    /* positive result */
    result = SetRGBPattern(0XFF,0,0);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T65: E[%d]-A[%d] \n",result,tvERROR_NONE);

    result = SetRGBPattern(0,0xFF,0);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T66: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetRGBPattern(0,0,0);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T67: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

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
    UT_LOG(" T68: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetRGBPattern(&r,&g,NULL);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T69: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}
void test_generic_SetGrayPattern( void )
{

    int result;
    int YUVvalue;
    /* positive result */
    YUVvalue = 100;
    result = SetGrayPattern(YUVvalue);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T70: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    YUVvalue = 258;
    result = SetGrayPattern(YUVvalue);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T71: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    result = SetGrayPattern(-1);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T72: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

}

void test_generic_GetGrayPattern( void )
{

    int result;
    int YUVvalue;
    /* positive result */
    result = GetGrayPattern(&YUVvalue);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T73: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
#if  NEED_SOURCE_MOD
    result = GetGrayPattern(NULL);
#endif    
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T74: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

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
    UT_LOG(" T75: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetColorTemp_Rgain(tvColorTemp_MAX,rgain);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T76: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    /* negative result */
    result = SetColorTemp_Rgain(colorTemp,2050);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T77: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

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
    UT_LOG(" T78: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetColorTemp_Ggain(colorTemp,2050);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T79: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

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
    UT_LOG(" T80: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetColorTemp_Bgain(tvColorTemp_MAX,bgain);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T81: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    /* negative result */
    result = SetColorTemp_Bgain(colorTemp,2050);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T82: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

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
    UT_LOG(" T83: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    result = GetColorTemp_Rgain(colorTemp,&rgain);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL);
    UT_LOG(" T84: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

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
    UT_LOG(" T85: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    result = GetColorTemp_Ggain(colorTemp,&ggain);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T86: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    result = GetColorTemp_Ggain(colorTemp,&ggain);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL);
    UT_LOG(" T87: E[%d]-A[%d] \n",result,tvERROR_NONE);
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
    UT_LOG(" T88: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    result = GetColorTemp_Bgain(colorTemp,&bgain);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T89: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

        /* negative result */
    colorTemp = tvColorTemp_COLD;
    result = GetColorTemp_Bgain(colorTemp,&bgain);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL);
    UT_LOG(" T90: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

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
    UT_LOG(" T91: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetColorTemp_R_post_offset(colorTemp,1050);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T92: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    result = SetColorTemp_R_post_offset(colorTemp,rpostoffset);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T93: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

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
    UT_LOG(" T94: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetColorTemp_G_post_offset(colorTemp,1050);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T95: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    result = SetColorTemp_G_post_offset(colorTemp,gpostoffset);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T96: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

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
    UT_LOG(" T97: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetColorTemp_B_post_offset(colorTemp,1050);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T98: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    result = SetColorTemp_B_post_offset(colorTemp,bpostoffset);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T99: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

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
    UT_LOG(" T100: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetColorTemp_R_post_offset(colorTemp,NULL);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T101: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

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
    UT_LOG(" T102: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetColorTemp_G_post_offset(colorTemp,&gpostoffset);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T103: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

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
    UT_LOG(" T104: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetColorTemp_B_post_offset(colorTemp,NULL);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T105: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_GetTVSupportedPictureModes( void )
{
    int result;
    pic_modes_t *pictureModes;
    unsigned short *count;

    /* positive result */
    result = GetTVSupportedPictureModes(&pictureModes,count);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T106: E[%d]-A[%d] \n",result,tvERROR_NONE);
    
    /*negative result */
    result = GetTVSupportedPictureModes(NULL,count);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T107: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_GetTVSupportedDVModes(void)
{

    int result;
    pic_modes_t *dvModes;
    unsigned short count = 0;

    /* positive result */
    result = GetTVSupportedDVModes(&dvModes,&count);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T108: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* positive result */
    result = GetTVSupportedDVModes(&dvModes,&count);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T109: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_SetTVDolbyVisionMode(void)
{

    int result;

    /* positive result */
    result = SetTVDolbyVisionMode("bright");
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T110: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
#if NEED_SOURCE_MOD
    result = SetTVDolbyVisionMode(NULL);
#endif

    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T111: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_GetTVDolbyVisionMode(void)
{

    int result;
    char dolbyMode[PIC_MODE_NAME_MAX] = {};

    /* positive result */
    result = GetTVDolbyVisionMode((char *)dolbyMode);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T112: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetTVDolbyVisionMode(NULL);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T113: E[%d]-A[%d] \n",result,tvERROR_NONE);
}


void test_generic_GetTVSupportedHLGModes(void)
{
    int result;
    pic_modes_t *hlgModes;
    unsigned short count;

    /* positive result */
    result = GetTVSupportedHLGModes(&hlgModes, &count);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T114: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetTVSupportedHLGModes(&hlgModes, &count);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T115: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_GetTVSupportedHDR10Modes(void)
{
    int result;
    pic_modes_t *hdr10Modes;
    unsigned short count;

    /*positive result */
    result = GetTVSupportedHDR10Modes(&hdr10Modes, &count);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T116: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetTVSupportedHDR10Modes(&hdr10Modes, &count);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T117: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

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
    UT_LOG(" T118: E[%d]-A[%d] \n",result,tvERROR_NONE);

    sourceOffset = 1;
    saveOnly  = 0;
    result = SetColorTemp_Rgain_onSource(colorTemp,rgain,sourceOffset,saveOnly); //sets the value
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T119: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    /* negative result */
    colorTemp = tvColorTemp_USER;
    rgain = 2000;
    result = SetColorTemp_Rgain_onSource(colorTemp,rgain,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T120: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    /* negative result */
    colorTemp = tvColorTemp_WARM;
    rgain = 2050;
    result = SetColorTemp_Rgain_onSource(colorTemp,rgain,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T121: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

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
    UT_LOG(" T122: E[%d]-A[%d] \n",result,tvERROR_NONE);

    sourceOffset = 1;
    saveOnly  = 0;
    result = SetColorTemp_Ggain_onSource(colorTemp,ggain,sourceOffset,saveOnly); //sets the value
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T123: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    /* negative result */
    colorTemp = tvColorTemp_USER;
    ggain = 2000;
    result = SetColorTemp_Ggain_onSource(colorTemp,ggain,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T124: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    /* negative result */
    colorTemp = tvColorTemp_WARM;
    ggain = 2050;
    result = SetColorTemp_Ggain_onSource(colorTemp,ggain,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T125: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

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
    UT_LOG(" T126: E[%d]-A[%d] \n",result,tvERROR_NONE);

    sourceOffset = 1;
    saveOnly  = 0;
    result = SetColorTemp_Bgain_onSource(colorTemp,bgain,sourceOffset,saveOnly); //sets the value
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T127: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    /* negative result */
    colorTemp = tvColorTemp_USER;
    bgain = 2000;
    result = SetColorTemp_Bgain_onSource(colorTemp,bgain,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T128: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    /* negative result */
    colorTemp = tvColorTemp_WARM;
    bgain = 2050;
    result = SetColorTemp_Bgain_onSource(colorTemp,bgain,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T129: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

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
    UT_LOG(" T130: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetColorTemp_Rgain_onSource(tvColorTemp_MAX,NULL,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T131: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    /* negative result */
    rgain = -1;
    result = GetColorTemp_Rgain_onSource(colorTemp,&rgain,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL);
    UT_LOG(" T132: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    rgain = 2000;
    result = GetColorTemp_Rgain_onSource(colorTemp,&rgain,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL);
    UT_LOG(" T133: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

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
    UT_LOG(" T134: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetColorTemp_Ggain_onSource(tvColorTemp_MAX,NULL,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T135: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    /* negative result */
    ggain = -1;
    result = GetColorTemp_Ggain_onSource(colorTemp,&ggain,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL);
    UT_LOG(" T136: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    ggain = 2000;
    result = GetColorTemp_Ggain_onSource(colorTemp,&ggain,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL);
    UT_LOG(" T137: E[%d]-A[%d] \n",result,tvERROR_GENERAL);
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
    UT_LOG(" T138: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetColorTemp_Bgain_onSource(tvColorTemp_MAX,NULL,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T139: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    /* negative result */
    bgain = -1;
    result = GetColorTemp_Bgain_onSource(colorTemp,&bgain,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL);
    UT_LOG(" T140: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    bgain = 2000;
    result = GetColorTemp_Bgain_onSource(colorTemp,&bgain,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL);
    UT_LOG(" T141: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

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
    UT_LOG(" T142: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* positive result */
    colorTemp = tvColorTemp_WARM;
    rpostoffset = 100;
    sourceOffset = 1;
    saveOnly = 0;
    result = SetColorTemp_R_post_offset_onSource(colorTemp,rpostoffset,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T143: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    rpostoffset = 1050;
    result = SetColorTemp_R_post_offset_onSource(colorTemp,rpostoffset,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T144: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    rpostoffset = 100;
    result = SetColorTemp_R_post_offset_onSource(colorTemp,rpostoffset,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T145: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

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
    UT_LOG(" T146: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* positive result */
    colorTemp = tvColorTemp_WARM;
    gpostoffset = 100;
    sourceOffset = 1;
    saveOnly = 0;
    result = SetColorTemp_G_post_offset_onSource(colorTemp,gpostoffset,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T147: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    gpostoffset = 1050;
    result = SetColorTemp_G_post_offset_onSource(colorTemp,gpostoffset,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T148: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    gpostoffset = 100;
    result = SetColorTemp_G_post_offset_onSource(colorTemp,gpostoffset,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T149: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

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
    UT_LOG(" T150: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* positive result */
    colorTemp = tvColorTemp_WARM;
    bpostoffset = 100;
    sourceOffset = 1;
    saveOnly = 0;
    result = SetColorTemp_B_post_offset_onSource(colorTemp,bpostoffset,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T151: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    bpostoffset = 1050;
    result = SetColorTemp_B_post_offset_onSource(colorTemp,bpostoffset,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T152: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    /* negative result */
    colorTemp = tvColorTemp_COLD;
    bpostoffset = 100;
    result = SetColorTemp_R_post_offset_onSource(colorTemp,bpostoffset,sourceOffset,saveOnly);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T153: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

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
    UT_LOG(" T154: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetColorTemp_R_post_offset_onSource(colorTemp,NULL,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T155: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

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
    UT_LOG(" T156: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetColorTemp_G_post_offset_onSource(colorTemp,NULL,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T157: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

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
    UT_LOG(" T158: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetColorTemp_B_post_offset_onSource(colorTemp,NULL,sourceOffset);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T159: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_SetDynamicContrast(void)
{
    int result;
    const char *dynamicContrastEnable;
    /* positive result */
    dynamicContrastEnable = "enabled";
    result = SetDynamicContrast(dynamicContrastEnable);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T160: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SetDynamicContrast(NULL);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T161: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_GetDynamicContrast(void)
{
    int result;
    char *dynamicContrastEnable;
    /* positive result */
    result = GetDynamicContrast(dynamicContrastEnable);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T162: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetDynamicContrast(NULL);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T163: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_setWBctrl(void)
{
    int result;


}

void test_generic_getWBctrl(void)
{
    int result;

    
}


void test_generic_getWbInfo(void)
{
    int result;
    getWBInfo_t params;
    std::vector<std::string> selector{};
    std::vector<std::string> input{};
    std::vector<std::string> colorTmp{};

    result = getWbInfo(&params,selector,input,colorTmp);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T164: E[%d]-A[%d] \n",result,tvERROR_NONE);

    
    if((selector.empty()) || (input.empty()) || (colorTmp.empty()))
    {
        result = getWbInfo(&params,selector,input,colorTmp);
        UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
        UT_LOG(" T165: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

    }
}

void test_generic_enableWBmode(void)
{
    int result;

    /* positive result */
    result = enableWBmode(true);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T166: E[%d]-A[%d] \n",result,tvERROR_NONE);

    result = enableWBmode(NULL);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T167: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);
}

void test_generic_GetSupportedComponentColor(void)
{
    int result;
    int *blComponentColor;
    /* positive result */
    result = GetSupportedComponentColor(blComponentColor);
    UT_ASSERT_EQUAL( result, tvERROR_NONE);
    UT_LOG(" T168: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetSupportedComponentColor(NULL);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T169: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

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
    UT_LOG(" T170: E[%d]-A[%d] \n",result,tvERROR_NONE);
    
    /* negative result */
    saturation= 150;
    result = SetCurrentComponentSaturation(blSaturation,saturation);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T171: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);
    
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
    UT_LOG(" T172: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetCurrentComponentSaturation(blSaturation,saturation);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T173: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
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
    UT_LOG(" T174: E[%d]-A[%d] \n",result,tvERROR_NONE);
    
    /* negative result */
    hue = 150;
    result = SetCurrentComponentHue(blHueColor,hue);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T175: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);
    
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
    UT_LOG(" T176: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetCurrentComponentHue(blHueColor,hue);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE);
    UT_LOG(" T177: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
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
    UT_LOG(" T178: E[%d]-A[%d] \n",result,tvERROR_NONE);
    
    /* negative result */
    luma = 150;
    result = SetCurrentComponentLuma(blLumaColor,luma);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM);
    UT_LOG(" T179: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);
    
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
    UT_LOG(" T180: E[%d]-A[%d] \n",result,tvERROR_NONE);

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
    UT_LOG(" T181: E[%d]-A[%d] \n",result,tvERROR_NONE);
#endif
    /* negative result */
    result = GetTVSupportedDimmingModes(NULL,count);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T182: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    /* negative result */
    result = GetTVSupportedDimmingModes(dimmingModes,0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T183: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_SetTVDimmingMode(void)
{
    int result;
    const char *dimmingMode;

    /* positive result */
    dimmingMode = "global";
    result = SetTVDimmingMode(dimmingMode);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_LOG(" T184: E[%d]-A[%d] \n",result,tvERROR_NONE);
    
    /* negative result */
    result = SetTVDimmingMode(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T185: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_GetTVBacklightGlobalFactor(void)
{
    int result;
    int value;

    /* positive result */
    result = GetTVBacklightGlobalFactor(&value);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_LOG(" T186: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetTVBacklightGlobalFactor(0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T187: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

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
    UT_LOG(" T188: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetTVPictureModeIndex("unknown");
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T189: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_GetCurrentContentFormat(void)
{
    tvVideoHDRFormat_t result;
    /* positive result */
    result = GetCurrentContentFormat();
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_LOG(" T190: E[%d]-A[%d] \n",result,tvERROR_NONE);

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
    UT_LOG(" T191: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetSupportedContentFormats(0,&numberOfFormats);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T192: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    result = GetSupportedContentFormats(&contentFormats,0);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T193: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
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
    UT_LOG(" T194: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = ResetBrightness(120,resetForAllFormats);
    UT_ASSERT_EQUAL(result, tvERROR_GENERAL);
    UT_LOG(" T195: E[%d]-A[%d] \n",result,tvERROR_GENERAL);
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
    UT_LOG(" T196: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = ResetContrast(120,resetForAllFormats);
    UT_ASSERT_EQUAL(result, tvERROR_GENERAL);
    UT_LOG(" T197: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

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
    UT_LOG(" T198: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = ResetSharpness(120,resetForAllFormats);
    UT_ASSERT_EQUAL(result, tvERROR_GENERAL);
    UT_LOG(" T199: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

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
    UT_LOG(" T200: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = ResetSaturation(120,resetForAllFormats);
    UT_ASSERT_EQUAL(result, tvERROR_GENERAL);
    UT_LOG(" T201: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

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
    UT_LOG(" T202: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = ResetHue(120,resetForAllFormats);
    UT_ASSERT_EQUAL(result, tvERROR_GENERAL);
    UT_LOG(" T203: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

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
    UT_LOG(" T204: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = ResetBacklight(120,resetForAllFormats);
    UT_ASSERT_EQUAL(result, tvERROR_GENERAL);
    UT_LOG(" T205: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

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
    UT_LOG(" T206: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = ResetColorTemperature(10,resetForAllFormats);
    UT_ASSERT_EQUAL(result, tvERROR_GENERAL);
    UT_LOG(" T207: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

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
    UT_LOG(" T208: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = ResetComponentSaturation(-1,defaultValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T209: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    /* negative result */
    result = ResetComponentSaturation(color,-1);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T210: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

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
    UT_LOG(" T211: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = ResetComponentLuma(-1,defaultValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T212: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    /* negative result */
    result = ResetComponentLuma(color,-10);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T213: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

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
    UT_LOG(" T214: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = ResetComponentHue(-1,defaultValue);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T215: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

    /* negative result */
    result = ResetComponentHue(color,-10);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T216: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_isCurrentHDRTypeIsSDR(void)
{
    int result;

    /* positive result */
    result = isCurrentHDRTypeIsSDR();
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_LOG(" T217: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = isCurrentHDRTypeIsSDR();
    UT_ASSERT_EQUAL(result, tvERROR_GENERAL);
    UT_LOG(" T218: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

}

void test_generic_GetPanelID(void)
{
    char *panelID;
    int result;

    /* positive result */
    result = GetPanelID(panelID);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_LOG(" T219: E[%d]-A[%d] \n",result,tvERROR_NONE);
    
    /* negative result */
    result = GetPanelID(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);   
    UT_LOG(" T220: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}


void test_generic_GetDefaultPanelID(void)
{
    int result;
    char *panelID;

    /* positive result */
    // void function - need to handle this case
    GetDefaultPanelID(panelID);
    UT_LOG(" T221: E[%d]-A[%d] \n",result,tvERROR_NONE);

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
    UT_LOG(" T222: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SaveColorTemperature(0,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T223: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
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
    UT_LOG(" T224: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SaveBacklight(-1,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T225: E[%d]-A[%d] \n",result,tvERROR_NONE);

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
    UT_LOG(" T226: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SaveContrast(-1,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T227: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

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
    UT_LOG(" T228: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SaveSaturation(-1,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T229: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

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
    UT_LOG(" T230: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SaveSharpness(-1,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T231: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

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
    UT_LOG(" T232: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SaveBrightness(-1,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T233: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
    
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
    UT_LOG(" T234: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SaveHue(-1,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T235: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
    
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
    UT_LOG(" T236: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SaveDynamicBacklight(-1,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T237: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
     
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
    UT_LOG(" T238: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SaveDisplayMode(-1,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T239: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
    
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
    UT_LOG(" T240: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SaveCMS(sourceInput,pq_mode,hdr_type,tunnel_type,color_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T241: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
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
    UT_LOG(" T242: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = SaveDolbyMode(-1,pq_mode,hdr_type,value);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T243: E[%d]-A[%d] \n",result,tvERROR_NONE);
}

void test_generic_GetNumberOfModesupported(void)
{
    int result;
    
    /* positive result */
    result = GetNumberOfModesupported();
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_LOG(" T244: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetNumberOfModesupported();
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T245: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);

}

void test_generic_GetCurrentPQIndex(void)
{
    int result;
    
    /* positive result */
    result = GetCurrentPQIndex();
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_LOG(" T246: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetCurrentPQIndex();
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T247: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
}

void test_generic_GetAllSupportedPicModeIndex(void)
{
    int result;
    int pic_mode_index[10];

    /* positive result */
    // void function - need to handle this case
    GetAllSupportedPicModeIndex(pic_mode_index);
    UT_LOG(" T248: E[%d]-A[%d] \n",result,tvERROR_NONE);

}

void test_generic_GetCMSDefault(void)
{
    int result;
    tvCMS_tunel_t color_tunel_type;

    /* positive result */
    color_tunel_type = COLOR_LUMA;
    result = GetCMSDefault(color_tunel_type);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_LOG(" T249: E[%d]-A[%d] \n",result,tvERROR_NONE);

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
    UT_LOG(" T250: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    result = GetDolbyModeIndex(NULL);
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T251: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
    
   
}

void test_generic_ConvertVideoFormatToHDRFormat(void)
{
    int result;
    tvVideoHDRFormat_t videoFormat;

    /* positive result */
    videoFormat = tvVideoHDRFormat_SDR;
    result = ConvertVideoFormatToHDRFormat(videoFormat);
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_LOG(" T252: E[%d]-A[%d] \n",result,tvERROR_NONE);

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
    UT_LOG(" T253: E[%d]-A[%d] \n",result,tvERROR_NONE);

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
    UT_LOG(" T254: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* negative result */
    // TBD

}

void test_generic_GetCustomPQModeIndex(void)
{
    int result;

    /* positive result */
    result = GetCustomPQModeIndex();
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_LOG(" T255: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* neagative result */
    result = GetCustomPQModeIndex();
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_STATE);
    UT_LOG(" T256: E[%d]-A[%d] \n",result,tvERROR_NONE);



}

void test_generic_SetTVHLGMode(void)
{
    tvError_t result ; 

    /* positive result */
    result = SetTVHLGMode("tvHLGMode_Dark");
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_LOG(" T257: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /*negative result */
    result = SetTVHLGMode("unknown");
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
    UT_LOG(" T258: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);
}

void test_generic_SetTVHDR10Mode(void)
{
    tvError_t result;

    /* positive result */
    result = SetTVHDR10Mode("tvHDR10Mode_Dark");
    UT_ASSERT_EQUAL(result, tvERROR_NONE);
    UT_LOG(" T259: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /*negative result */
    result = SetTVHDR10Mode("unknown");
    UT_ASSERT_EQUAL(result, tvERROR_INVALID_PARAM);
    UT_LOG(" T260: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

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
    UT_LOG(" T261: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* Failure Case - i.e since already intialized */
    result = SetCMSState(tunelType,colorType,componentState);
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_STATE );
    UT_LOG(" T262: E[%d]-A[%d] \n",result,tvERROR_INVALID_STATE);
    
    result = SetCMSState(tunelType,colorType,componentState);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL);
    UT_LOG(" T263: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

#ifndef HAS_CMS_SUPPORT
    result = SetCMSState(tunelType,colorType,componentState);
    UT_ASSERT_EQUAL( result, tvERROR_OPERATION_NOT_SUPPORTED);
    UT_LOG(" T264: E[%d]-A[%d] \n",result,tvERROR_OPERATION_NOT_SUPPORTED);
#endif
}
#if 0
void test_generic_ReadCustWBvaluesFromDriverOnInit( void )
{
    tvError_t result;
    /* Success Case  */

    result = ReadCustWBvaluesFromDriverOnInit();
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    UT_LOG(" T265: E[%d]-A[%d] \n",result,tvERROR_NONE);

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
    UT_LOG(" T266: E[%d]-A[%d] \n",custWBValueInitBefore.r_offset,custWBValueInitAfter.r_offset);

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
    UT_LOG(" T267: E[%d]-A[%d] \n",result,true);

    /* Failure Case  */
    wbvalue.r_gain = -1;
    result = isWBUserDfault(wbvalue);
    UT_ASSERT_EQUAL( false, result );
    UT_LOG(" T268: E[%d]-A[%d] \n",result,false);

}


void test_generic_GetWBRgbType( void )
{
    int rgb_type = -1;
   // const char *color, const char * ctrl;

    /* Success Case - Red */

    rgb_type = GetWBRgbType("red","gain");
    UT_ASSERT_EQUAL( rgb_type, R_GAIN );
    UT_LOG(" T269: E[%d]-A[%d] \n",rgb_type,R_GAIN);

    /* Success Case - Green */
    rgb_type = GetWBRgbType("green","gain");
    UT_ASSERT_EQUAL( rgb_type, G_GAIN );
    UT_LOG(" T270: E[%d]-A[%d] \n",rgb_type,G_GAIN);

    /* Success Case - Blue */
    rgb_type = GetWBRgbType("blue","gain");
    UT_ASSERT_EQUAL( rgb_type, B_GAIN );
    UT_LOG(" T271: E[%d]-A[%d] \n",rgb_type,B_GAIN);

    /* Failure Case - Blue */
    rgb_type = GetWBRgbType("Unknown","gain");
    UT_ASSERT_EQUAL( rgb_type, B_GAIN );
    UT_LOG(" T272: E[%d]-A[%d] \n",rgb_type,B_GAIN);

    rgb_type = GetWBRgbType("red","Unknown");
    UT_ASSERT_EQUAL( rgb_type, R_POST_OFFSET );
    UT_LOG(" T273: E[%d]-A[%d] \n",rgb_type,R_POST_OFFSET);

    rgb_type = GetWBRgbType("green","Unknown");
    UT_ASSERT_EQUAL( rgb_type, G_POST_OFFSET );
    UT_LOG(" T274: E[%d]-A[%d] \n",rgb_type,G_POST_OFFSET);

    rgb_type = GetWBRgbType("blue","Unknown");
    UT_ASSERT_EQUAL( rgb_type, B_POST_OFFSET );
    UT_LOG(" T275: E[%d]-A[%d] \n",rgb_type,B_POST_OFFSET);

    
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
    UT_LOG(" T276: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* Failure Case */
    rgbType= -2;
    value = -1;
    result = SaveColorTemperatureUser(rgbType,value);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL );
    UT_LOG(" T277: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

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
    UT_LOG(" T278: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* Failure Case */
    rgbType= -2;
    value = -1;
    result = SetColorTemperatureUser(rgbType,value);
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL );
    UT_LOG(" T279: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

}


void test_generic_GetDriverEquivalentBLForCurrentFmt( void )
{
    int backlight;
    int result;

    /* Success Case  */
    backlight =0;
    result = GetDriverEquivalentBLForCurrentFmt(backlight);
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    UT_LOG(" T280: E[%d]-A[%d] \n",result,tvERROR_NONE); // Need predicted value

    /* TODO: Failure Case */
    backlight = -1; //There is a chance to crash. Need to handle in source code
    //result = GetDriverEquivalentBLForCurrentFmt(rgbType,value); // Enable once supported in code
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL );
    UT_LOG(" T281: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

}
void test_generic_SetBacklightInfo( void )
{
    tvError_t result;
    tvBacklightInfo_t backlightDefaults = {};

    /* Success Case  */
   
    result = SetBacklightInfo(backlightDefaults); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    UT_LOG(" T282: E[%d]-A[%d] \n",result,tvERROR_NONE);

    /* TODO:Failure Case */
  
}

void test_generic_ReadAllModeConfigfile( void )
{

    tvError_t result;
    char buffer[EXPECTED_FILE_SIZE] = {0};

    /* Success Case  */
   
    result = ReadAllModeConfigfile(GENERIC_MODE_CONFIG_FILE,buffer,"picmodes"); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    UT_LOG(" T283: E[%d]-A[%d] \n",result,tvERROR_NONE);

    result = ReadAllModeConfigfile(GENERIC_MODE_CONFIG_FILE,buffer,"dvmodes"); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    UT_LOG(" T284: E[%d]-A[%d] \n",result,tvERROR_NONE);

    result = ReadAllModeConfigfile(GENERIC_MODE_CONFIG_FILE,buffer,"hdr10modes"); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    UT_LOG(" T285: E[%d]-A[%d] \n",result,tvERROR_NONE);
    
    result = ReadAllModeConfigfile(GENERIC_MODE_CONFIG_FILE,buffer,"hlgmodes"); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    UT_LOG(" T286: E[%d]-A[%d] \n",result,tvERROR_NONE);   
    
 /* Failure Case */
    result = ReadAllModeConfigfile("Invalid",buffer,"picmodes"); 
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM );
    UT_LOG(" T287: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);

/* TODO: Enable below once code is ready  */

   // result = ReadAllModeConfigfile(NULL,NULL,NULL); 
    UT_ASSERT_EQUAL( result, tvERROR_INVALID_PARAM );
    UT_LOG(" T288: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);
  
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
    //UT_LOG(" T289: E[%d]-A[%d] \n",result,tvERROR_NONE);

/* TODO: Enable below once code is ready  */

   // splitstringsandvaluefrombuffer(NULL,NULL,&count); 
   // UT_ASSERT_EQUAL( 0, count );
   // UT_LOG(" T290: E[%d]-A[%d] \n",result,tvERROR_INVALID_PARAM);
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
    UT_LOG(" T291: E[%d]-A[%d] \n",0,totalcount);

/* TODO: Enable below once code is ready  */

   //splitstringsfrombuffer(buffer,supportedDimmingModes,&totalcount);
    //UT_ASSERT_EQUAL( 0, totalcount );
    UT_LOG(" T292: E[%d]-A[%d] \n",0,totalcount);

//splitstringsfrombuffer(NULL,NULL,&totalcount);
    //UT_ASSERT_EQUAL( 0, totalcount );
    UT_LOG(" T293: E[%d]-A[%d] \n",0,totalcount);

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
    UT_LOG(" T294: E[%d]-A[%d] \n",result,tvERROR_NONE);

    from = -1;
    result = SetBacklightFade(from, to, duration); 
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL );
    UT_LOG(" T295: E[%d]-A[%d] \n",result,tvERROR_GENERAL);
    /* TODO:Failure Case */
  
}

void test_generic_SetGammaMode( void )
{
    tvError_t result;
    int mode = 1;

    /* Success Case  */

    result = SetGammaMode(mode); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    UT_LOG(" T296: E[%d]-A[%d] \n",result,tvERROR_NONE);

    mode = 0;
    result = SetGammaMode(mode); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    UT_LOG(" T297: E[%d]-A[%d] \n",result,tvERROR_NONE);

    mode = -1;
    result = SetGammaMode(mode); 
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL );
    UT_LOG(" T298: E[%d]-A[%d] \n",result,tvERROR_GENERAL);
    
  
}

void test_generic_SetLocalDimmingLevel( void )
{
    tvError_t result;
    int localDimmingLevel = 1;

    /* Success Case  */

    result = SetLocalDimmingLevel(localDimmingLevel); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    UT_LOG(" T299: E[%d]-A[%d] \n",result,tvERROR_NONE);

    localDimmingLevel = 0;
    result = SetLocalDimmingLevel(localDimmingLevel); 
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL );
    UT_LOG(" T300: E[%d]-A[%d] \n",result,tvERROR_GENERAL);
  
}

void test_generic_GetLocalDimmingLevel( void )
{
    tvError_t result;
    int localDimmingLevel = 1;

    /* Success Case  */

    result = GetLocalDimmingLevel(&localDimmingLevel); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    UT_LOG(" T301: E[%d]-A[%d] \n",result,tvERROR_NONE);
/* TODO: Error case */
    localDimmingLevel = 0;
   // result = GetLocalDimmingLevel(NULL);  // Enable once it is supported
 //   UT_ASSERT_EQUAL( result, tvERROR_GENERAL );
  //  UT_LOG(" T302: E[%d]-A[%d] \n",result,tvERROR_GENERAL);
  
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
    UT_LOG(" T303: E[%d]-A[%d] \n",result,tvERROR_NONE);
/* TODO: Error case */
    hdr_type = HDR_TYPE_SDR;
    sourceInput = -1;
    result = SaveLocalDimmingLevel(sourceInput,pq_mode,hdr_type,value); 
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL );
    UT_LOG(" T304: E[%d]-A[%d] \n",result,tvERROR_GENERAL);
  
}

void test_generic_SwitchEDID( void )
{
    tvError_t result = tvERROR_NONE;
    int mode = 1;

    /*TODO: need to handle return type   */

    SwitchEDID(mode); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    UT_LOG(" T305: E[%d]-A[%d] \n",result,tvERROR_NONE);

}

void test_generic_UpdateEDIDAndSetDimmingLevel( void )
{
    tvError_t result = tvERROR_NONE;
    int mode = 1;

    /*TODO: need to handle return type   */

    result = UpdateEDIDAndSetDimmingLevel(mode); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    UT_LOG(" T306: E[%d]-A[%d] \n",result,tvERROR_NONE);

    mode = -1;
    result = UpdateEDIDAndSetDimmingLevel(mode); 
    UT_ASSERT_EQUAL( result, tvERROR_GENERAL );
    UT_LOG(" T307: E[%d]-A[%d] \n",result,tvERROR_GENERAL);

}

void test_generic_GetLDIMAndEDIDLevel( void )
{
    tvError_t result = tvERROR_NONE;
    
    int dimmingMode = 0 ,format = 0, dimmingLevel = 0,  edidLevel = 0;

    /*TODO: need to handle return type   */

    GetLDIMAndEDIDLevel(dimmingMode,format, &dimmingLevel,  &edidLevel); 
    UT_ASSERT_EQUAL( result, tvERROR_NONE );
    UT_LOG(" T308: E[%d]-A[%d] \n",result,tvERROR_NONE);

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
    UT_add_test( pSuite, "getWbInfo  ", test_generic_getWbInfo);
    
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
