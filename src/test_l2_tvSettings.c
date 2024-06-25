/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:*
* Copyright 2024 RDK Management
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

/**
* @file test_l2_tvSettings.c
* @page tvSettings Level 2 Tests
*
* ## Module's Role
* This module includes Level 2 functional tests (success and failure scenarios).
* This is to ensure that the tvSettings APIs meet the requirements across all vendors.
*
* **Pre-Conditions:**  None@n
* **Dependencies:** None@n
*
* Ref to API Definition specification documentation : [tvSettings_halSpec.md](../../docs/pages/tvSettings_halSpec.md)
*/

#include <ut.h>
#include <ut_log.h>
#include <ut_kvp_profile.h>
#include <stdlib.h>
#include "tvSettings.h"

static int gTestGroup = 2;
static int gTestID = 1;

/**
* @brief This test checks the functionality of the GetSupportedVideoFormats API in the tvSettings module
*
* This test initializes the TV, retrieves the supported video formats, and checks if the number and types of formats returned are as expected. It then terminates the TV. The test is designed to verify that the GetSupportedVideoFormats API is working as expected and returning the correct video formats.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 001@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_GetSupportedVideoFormats(void)
{
    gTestID = 1;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    tvVideoFormatType_t *videoFormats[VIDEO_FORMAT_MAX] = {0};
    unsigned short numberOfFormats;
    ut_kvp_instance_t *pInstance = NULL;
    uint32_t format;
    char buffer[50];
    int flag;
    int j;

    UT_LOG_DEBUG("Invoking TvInit with valid parameters");
    status = TvInit();
    UT_LOG_DEBUG("TvInit returned : %d",status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking GetTVSupportedVideoFormats with valid parameters");
    status = GetTVSupportedVideoFormats(videoFormats, &numberOfFormats);
    UT_LOG_DEBUG("GetTVSupportedVideoFormats returned : %d numberOfFormats :%d ",status, numberOfFormats );
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE)
    {
        UT_LOG_ERROR("GetTVSupportedVideoFormats failed with status: %d", status);
        TvTerm();
        return;
    }

    UT_ASSERT_TRUE(numberOfFormats >= 1 && numberOfFormats <= VIDEO_FORMAT_MAX);

    UT_ASSERT_KVP_EQUAL_PROFILE_UINT16(numberOfFormats, "VideoFormat/numberOfFormats");

    pInstance = ut_kvp_profile_getInstance();
    for (int i=0;i<numberOfFormats;i++)
    {
        flag = 0;
        sprintf(buffer, "VideoFormat/index/%d", i);
        format = ut_kvp_getUInt32Field( pInstance, buffer);
        j = 0;
        for ( j=0; j< numberOfFormats; j++)
        {
            if (*videoFormats[j] == format)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            UT_PASS("VideoFormat match");
            UT_LOG_DEBUG("Video Format : %d is in the list of supported VideoFormats", *videoFormats[j]);
        }
        else
        {
            UT_FAIL("VideoFormat mismatch");
            UT_LOG_DEBUG("Video Format : %d is not in the list of supported VideoFormats ", *videoFormats[j]);
        }
    }

    UT_LOG_DEBUG("Invoking TvTerm");
    status = TvTerm();
    UT_LOG_DEBUG("TvTerm returned : %d",status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test for GetCurrentVideoFormat API when there is no video playback
*
* This function tests the GetCurrentVideoFormat API when there is no video playback. It first initializes the TV settings using the TvInit API, then calls the GetCurrentVideoFormat API with a valid pointer to a tvVideoFormatType_t variable, and checks that the returned video format is VIDEO_FORMAT_SDR. Finally, it de-initializes the TV settings using the TvTerm API. The function uses the Cunit assertion macros to check that the return values of the APIs are as expected.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 002@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_GetCurrentVideoFormat_NoVideoPlayback(void)
{
    gTestID = 2;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    tvVideoFormatType_t videoFormat;

    UT_LOG_DEBUG("Invoking TvInit with no input parameters");
    status = TvInit();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking GetCurrentVideoFormat with valid pointer to tvVideoFormatType_t variable");
    status = GetCurrentVideoFormat(&videoFormat);
    UT_LOG_DEBUG("Return status: %d, Video Format: %d", status, videoFormat);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    UT_ASSERT_EQUAL(videoFormat, VIDEO_FORMAT_SDR);
    if (status != tvERROR_NONE || videoFormat != VIDEO_FORMAT_SDR)
    {
        UT_LOG_ERROR("GetCurrentVideoFormat failed with status: %d", status);
        TvTerm();
        return;
    }

    UT_LOG_DEBUG("Invoking TvTerm with no input parameters");
    status = TvTerm();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the current video resolution
*
* This function tests the GetCurrentVideoResolution API by first initializing the TV settings using TvInit, then calling GetCurrentVideoResolution and checking the returned values, and finally de-initializing the TV settings using TvTerm. If GetCurrentVideoResolution fails, TvTerm is called to clean up. The function uses Cunit's assertion functions to check the return values of the APIs and the values in the returned tvResolutionParam_t structure.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 003@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_VerifyCurrentVideoResolution(void)
{
    gTestID = 3;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    tvResolutionParam_t res;

    UT_LOG_DEBUG("Invoking TvInit");
    status = TvInit();
    UT_LOG_DEBUG("TvInit status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking GetCurrentVideoResolution with valid buffer");
    status = GetCurrentVideoResolution(&res);
    UT_LOG_DEBUG("GetCurrentVideoResolution status: %d, resolutionValue: %d, frameHeight: %d, frameWidth: %d, isInterlaced: %d", status, res.resolutionValue, res.frameHeight, res.frameWidth, res.isInterlaced);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE)
    {
        UT_LOG_DEBUG("Invoking TvTerm due to failure in GetCurrentVideoResolution");
        TvTerm();
        return;
    }
    UT_ASSERT_EQUAL(res.resolutionValue, tvVideoResolution_NONE);
    UT_ASSERT_EQUAL(res.frameHeight, 0);
    UT_ASSERT_EQUAL(res.frameWidth, 0);
    UT_ASSERT_EQUAL(res.isInterlaced, 0);

    UT_LOG_DEBUG("Invoking TvTerm");
    status = TvTerm();
    UT_LOG_DEBUG("TvTerm status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the frame rate when the TV is stopped
*
* This function tests the behavior of the GetCurrentVideoFrameRate API when the TV is stopped. It first initializes the TV settings using TvInit, then gets the current video frame rate, and finally de-initializes the TV settings using TvTerm. The function uses assertions to verify that the APIs return the expected results. If GetCurrentVideoFrameRate fails, it logs an error and calls TvTerm to clean up.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 004@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_VerifyFrameRateWhenStopped(void)
{
    gTestID = 4;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t error;
    tvVideoFrameRate_t frameRate;

    UT_LOG_DEBUG("Invoking TvInit");
    error = TvInit();
    UT_LOG_DEBUG("Return status: %d", error);
    UT_ASSERT_EQUAL_FATAL(error, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking GetCurrentVideoFrameRate");
    error = GetCurrentVideoFrameRate(&frameRate);
    UT_LOG_DEBUG("Frame rate: %d, Return status: %d", frameRate, error);
    UT_ASSERT_EQUAL(error, tvERROR_NONE);
    UT_ASSERT_EQUAL(frameRate, tvVideoFrameRate_NONE);
    if (error != tvERROR_NONE || frameRate != tvVideoFrameRate_NONE)
    {
        UT_LOG_DEBUG("Invoking TvTerm due to failure of GetCurrentVideoFrameRate");
        TvTerm();
        return;
    }

    UT_LOG_DEBUG("Invoking TvTerm");
    error = TvTerm();
    UT_LOG_DEBUG("Return status: %d", error);
    UT_ASSERT_EQUAL_FATAL(error, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test for getting supported video sources from TV settings
*
* This test verifies if the GetTVSupportedVideoSources function is able to retrieve the supported video sources correctly. It checks if the function returns the correct status and the number of sources is within the expected range. Each source is then validated against the profile.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 005@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_GetTVSupportedVideoSources(void)
{
    gTestID = 5;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    tvVideoSrcType_t *videoSources[VIDEO_SOURCE_MAX];
    unsigned short numberOfSources;
    ut_kvp_instance_t *pInstance = NULL;
    char buffer[50];
    uint32_t source;
    int flag;
    int j;

    UT_LOG_DEBUG("Invoking TvInit()");
    status = TvInit();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking GetTVSupportedVideoSources()");
    status = GetTVSupportedVideoSources(videoSources, &numberOfSources);
    UT_LOG_DEBUG("Return status: %d, Number of sources: %d", status, numberOfSources);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE)
    {
        UT_LOG_DEBUG("Invoking TvTerm due to failure in GetTVSupportedVideoSources");
        TvTerm();
        return;
    }

    UT_ASSERT_TRUE(numberOfSources >= 1 && numberOfSources <= VIDEO_SOURCE_MAX);

    UT_ASSERT_KVP_EQUAL_PROFILE_UINT16(numberOfSources, "VideoSource/numberOfSources");

    pInstance = ut_kvp_profile_getInstance();
    for (int i=0;i<numberOfSources;i++)
    {
        flag = 0;
        sprintf(buffer, "VideoSource/index/%d", i);
        source = ut_kvp_getUInt32Field( pInstance, buffer);
        j = 0;
        for ( j=0; j< numberOfSources; j++)
        {
            if (*videoSources[j] == source)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            UT_PASS("VideoSource match");
            UT_LOG_DEBUG("Video source : %d is in the list of supported VideoSources", *videoSources[j]);
        }
        else
        {
            UT_FAIL("VideoSource mismatch");
            UT_LOG_DEBUG("Video Source : %d is not in the list of supported VideoFormats ", *videoSources[j]);
        }
    }

    UT_LOG_DEBUG("Invoking TvTerm()");
    status = TvTerm();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies if there is no video source in the TV settings
*
* This test function is designed to check the absence of a video source in the TV settings. It does this by invoking the TvInit() function, checking the current video source, and then terminating the TV. The test is crucial to ensure that the TV settings are correctly initialized and terminated, and that the video source is correctly set.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 006@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_VerifyNoVideoSource(void)
{
    gTestID = 6;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    int currentSource;

    UT_LOG_DEBUG("Invoking TvInit()");
    status = TvInit();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking GetCurrentVideoSource() with valid pointer");
    status = GetCurrentVideoSource(&currentSource);
    UT_LOG_DEBUG("Return status: %d, Current Source: %d", status, currentSource);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    UT_ASSERT_EQUAL(currentSource, VIDEO_SOURCE_IP);
    if (status != tvERROR_NONE || currentSource != VIDEO_SOURCE_IP)
    {
        UT_LOG_DEBUG("Invoking TvTerm due to failure of GetCurrentVideoSource");
        TvTerm();
        return;
    }

    UT_LOG_DEBUG("Invoking TvTerm()");
    status = TvTerm();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the SetBacklight and GetBacklight APIs
*
* This function tests the SetBacklight and GetBacklight APIs by setting a valid backlight value and then retrieving it to verify if the set value is correctly retrieved. The TvInit and TvTerm APIs are used as pre and post requisite APIs respectively.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 007@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetBacklight(void)
{
    gTestID = 7;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    int backlight = 50;
    int getBacklight;

    UT_LOG_DEBUG("Invoking TvInit()");
    status = TvInit();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking SetBacklight() with valid backlight value: %d", backlight);
    status = SetBacklight(backlight);
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE)
    {
        UT_LOG_ERROR("SetBacklight() failed with status: %d", status);
        UT_LOG_DEBUG("Invoking TvTerm() due to failure of SetBacklight()");
        TvTerm();
        return;
    }

    UT_LOG_DEBUG("Invoking GetBacklight()");
    status = GetBacklight(&getBacklight);
    UT_LOG_DEBUG("Return status: %d, Current backlight value: %d", status, getBacklight);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    UT_ASSERT_EQUAL(backlight, getBacklight);

    if (status != tvERROR_NONE || backlight != getBacklight)
    {
        UT_LOG_ERROR("GetBacklight() failed with status: %d", status);
    }

    UT_LOG_DEBUG("Invoking TvTerm()");
    status = TvTerm();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test aims to verify the functionality of setting and getting the backlight fade in a TV settings module.
*
* In this test, the SetBacklightFade() function is invoked with specific parameters and then the GetCurrentBacklightFade() function is called to verify if the previously set parameters are correctly retrieved. The test ensures that the TV settings module correctly handles the backlight fade settings and can retrieve them accurately.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 008@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetBacklightFade(void)
{
    gTestID = 8;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    int from = 50;
    int to = 70;
    int duration = 5000;
    int get_from, get_to, get_current;

    UT_LOG_DEBUG("Invoking TvInit()");
    status = TvInit();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking SetBacklightFade() with from: %d, to: %d, duration: %d", from, to, duration);
    status = SetBacklightFade(from, to, duration);
    UT_LOG_DEBUG("SetBacklightFade() returned status: %d", status);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE)
    {
        UT_LOG_DEBUG("Invoking TvTerm() due to failure in SetBacklightFade()");
        TvTerm();
        return;
    }

    UT_LOG_DEBUG("Invoking GetCurrentBacklightFade()");
    status = GetCurrentBacklightFade(&get_from, &get_to, &get_current);
    UT_LOG_DEBUG("GetCurrentBacklightFade() returned from: %d, to: %d, current: %d, status: %d", get_from, get_to, get_current, status);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    UT_ASSERT_EQUAL(from, get_from);
    UT_ASSERT_EQUAL(to, get_to);
    UT_ASSERT_EQUAL(duration, get_current);
    if (status != tvERROR_NONE)
    {
        UT_LOG_DEBUG("Invoking TvTerm() due to failure in GetCurrentBacklightFade()");
        TvTerm();
        return;
    }

    UT_LOG_DEBUG("Invoking TvTerm()");
    status = TvTerm();
    UT_LOG_DEBUG("TvTerm() returned status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the function GetSupportedBacklightModes
*
* This test case verifies if the function GetSupportedBacklightModes is able to fetch the supported backlight modes correctly. The function is tested under normal conditions with valid input parameters.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 009@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_GetSupportedBacklightModes(void)
{
    gTestID = 9;
    tvError_t status;
    int blModes;
    int getblModes;
    int count = 0;
    char buffer[50];
    ut_kvp_instance_t *pInstance = NULL;
    int flag = 0;

    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    UT_LOG_DEBUG("Invoking TvInit");
    status = TvInit();
    UT_LOG_DEBUG("TvInit status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking GetSupportedBacklightModes with valid pointer");
    status = GetSupportedBacklightModes(&getblModes);
    UT_LOG_DEBUG("GetSupportedBacklightModes status: %d, blModes: %d", status, getblModes);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE)
    {
        UT_LOG_DEBUG("Invoking TvTerm() due to failure in GetSupportedBacklightModes()");
        TvTerm();
        return;
    }

    pInstance = ut_kvp_profile_getInstance();
    count = ut_kvp_getListCount(pInstance,"BacklightControl/index");
    for (int i=0;i<count;i++)
    {
        flag = 0;
        sprintf(buffer, "BacklightControl/index/%d", i);
        blModes = ut_kvp_getUInt32Field( pInstance, buffer);

        if (getblModes == blModes)
        {
                flag = 1;
                break;
        }
    }
    if (flag == 1)
    {
        UT_PASS("BacklightControl match");
        UT_LOG_DEBUG("BacklightControl : %d is in the list of supported BacklightControl modes", getblModes);
    }
    else
    {
        UT_FAIL("BacklightControl mismatch");
        UT_LOG_DEBUG("BacklightControl : %d is not in the list of supported BacklightControl modes ", getblModes);
    }

    UT_LOG_DEBUG("Invoking TvTerm");
    status = TvTerm();
    UT_LOG_DEBUG("TvTerm status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test checks if the Set and Get functions for Backlight Mode in TV settings are working as expected
*
* In this test, the Backlight Mode is set using the SetCurrentBacklightMode() function and then retrieved using the GetCurrentBacklightMode() function. The test checks if the mode retrieved matches the mode set, thereby testing the correctness of both the Set and Get functions.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 010@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetBacklightMode(void)
{
    gTestID = 10;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t ret;
    tvBacklightMode_t setMode = tvBacklightMode_MANUAL;
    tvBacklightMode_t getMode;

    UT_LOG_DEBUG("Invoking TvInit()");
    ret = TvInit();
    UT_LOG_DEBUG("TvInit() returned %d", ret);
    UT_ASSERT_EQUAL_FATAL(ret, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking SetCurrentBacklightMode() with valid backlight mode %d",setMode);
    ret = SetCurrentBacklightMode(setMode);
    UT_LOG_DEBUG("SetCurrentBacklightMode() returned %d", ret);
    UT_ASSERT_EQUAL(ret, tvERROR_NONE);
    if (ret != tvERROR_NONE)
    {
        UT_LOG_DEBUG("Invoking TvTerm() due to failure in SetCurrentBacklightMode()");
        TvTerm();
        return;
    }

    UT_LOG_DEBUG("Invoking GetCurrentBacklightMode()");
    ret = GetCurrentBacklightMode(&getMode);
    UT_LOG_DEBUG("GetCurrentBacklightMode() returned %d and mode %d", ret, getMode);
    UT_ASSERT_EQUAL(ret, tvERROR_NONE);
    if (ret != tvERROR_NONE)
    {
        UT_LOG_DEBUG("Invoking TvTerm() due to failure in GetCurrentBacklightMode()");
        TvTerm();
        return;
    }
    UT_ASSERT_EQUAL(getMode, setMode);

    UT_LOG_DEBUG("Invoking TvTerm()");
    ret = TvTerm();
    UT_LOG_DEBUG("TvTerm() returned %d", ret);
    UT_ASSERT_EQUAL_FATAL(ret, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the function GetSupportedDimmingModes in tvSettings module
*
* This test case verifies if the function GetSupportedDimmingModes correctly retrieves the supported dimming modes from the TV settings. The test first initializes the TV settings using TvInit function, then calls GetSupportedDimmingModes to get the supported dimming modes, and finally terminates the TV settings using TvTerm function. The test asserts if the returned status of these functions is tvERROR_NONE, indicating successful execution. The test also checks if the number of dimming modes returned by GetSupportedDimmingModes matches with the value in the platform-supported configurations file 'Sink-4K-TvSettings.yaml'.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 011@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_GetSupportedDimmingModes(void)
{
    gTestID = 11;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    tvDimmingMode_t *dimmingModes[tvDimmingMode_MAX];
    unsigned short numDimmingModes;
    ut_kvp_instance_t *pInstance = NULL;
    char buffer[50];
    uint32_t mode;
    int flag;
    int j;

    UT_LOG_DEBUG("Invoking TvInit with no input parameters");
    status = TvInit();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking GetTVSupportedDimmingModes with valid output parameters");
    status = GetTVSupportedDimmingModes(dimmingModes, &numDimmingModes);
    UT_LOG_DEBUG("Return status: %d, Number of Dimming Modes: %d", status, numDimmingModes);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE)
    {
        UT_LOG_ERROR("GetTVSupportedDimmingModes failed with status: %d", status);
        TvTerm();
        return;
    }

    UT_ASSERT_TRUE(numDimmingModes >= 1 && numDimmingModes <= VIDEO_SOURCE_MAX);

    UT_ASSERT_KVP_EQUAL_PROFILE_UINT16(numDimmingModes, "DimmingMode/numberOfDimmingModes");

    pInstance = ut_kvp_profile_getInstance();
    for (int i=0;i<numDimmingModes;i++)
    {
        flag = 0;
        sprintf(buffer, "DimmingMode/index/%d", i);
        mode = ut_kvp_getUInt32Field( pInstance, buffer);
        j = 0;
        for ( j=0; j< numDimmingModes; j++)
        {
            if (*dimmingModes[j] == mode)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            UT_PASS("dimmingMode match");
            UT_LOG_DEBUG("dimmingMode: %d is in the list of supported dimmingModes", *dimmingModes[j]);
        }
        else
        {
            UT_FAIL("dimmingMode mismatch");
            UT_LOG_DEBUG("dimmingModes : %d is not in the list of supported dimmingModes ", *dimmingModes[j]);
        }
    }

    UT_LOG_DEBUG("Invoking TvTerm with no input parameters");
    status = TvTerm();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the setting and getting of TV Dimming Mode
*
* This test case verifies the functionality of setting and getting the TV Dimming Mode. It checks if the TV Dimming Mode can be set correctly and if the same can be retrieved without any errors. The test is performed for three different dimming modes - local, fixed, and global.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 012@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetDimmingMode(void)
{
    gTestID = 12;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    const char *dimmingModes[] = {"local", "fixed", "global"};
    char getDimmingMode[10];

    status = TvInit();
    UT_LOG_DEBUG("Invoking TvInit");
    UT_LOG_DEBUG("TvInit status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    for(int i = 0; i < 3; i++)
    {
        UT_LOG_DEBUG("Invoking SetTVDimmingMode with %s", dimmingModes[i]);
        status = SetTVDimmingMode(dimmingModes[i]);
        UT_LOG_DEBUG("SetTVDimmingMode status: %d", status);
        UT_ASSERT_EQUAL(status, tvERROR_NONE);
        if(status != tvERROR_NONE)
        {
            UT_LOG_ERROR("SetTVDimmingMode failed with status: %d", status);
            continue;
        }

        UT_LOG_DEBUG("Invoking GetTVDimmingMode");
        status = GetTVDimmingMode(getDimmingMode);
        UT_LOG_DEBUG("GetTVDimmingMode status: %d, dimmingMode: %s", status, getDimmingMode);
        UT_ASSERT_EQUAL(status, tvERROR_NONE);
        if(status != tvERROR_NONE)
        {
            UT_LOG_ERROR("GetTVDimmingMode failed with status: %d", status);
        }

        UT_ASSERT_STRING_EQUAL(getDimmingMode, dimmingModes[i]);
    }

    status = TvTerm();
    UT_LOG_DEBUG("Invoking TvTerm");
    UT_LOG_DEBUG("TvTerm status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the functionality of Set and Get Local Dimming Level
*
* This test case verifies if the SetLocalDimmingLevel and GetLocalDimmingLevel functions are working as expected. It sets the local dimming level and then gets the level to check if the set value is correctly retrieved. This is done for all possible dimming levels.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 013@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetLocalDimmingLevel(void)
{
    gTestID = 13;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    ldimStateLevel_t ldimStateLevel, ldimStateLevelGet;
    ldimStateLevel_t ldimStateLevels[] = {LDIM_STATE_NONBOOST, LDIM_STATE_BOOST, LDIM_STATE_BURST};

    UT_LOG_DEBUG("Invoking TvInit()");
    status = TvInit();
    UT_LOG_DEBUG("TvInit() returned %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    for (int i = 0; i < 3; i++)
    {
        ldimStateLevel = ldimStateLevels[i];

        UT_LOG_DEBUG("Invoking SetLocalDimmingLevel() with %d", ldimStateLevel);
        status = SetLocalDimmingLevel(ldimStateLevel);
        UT_LOG_DEBUG("SetLocalDimmingLevel() returned %d", status);
        UT_ASSERT_EQUAL(status, tvERROR_NONE);
        if (status != tvERROR_NONE)
        {
            UT_LOG_DEBUG("SetLocalDimmingLevel() failed with status : %d", status);
            continue;
        }

        UT_LOG_DEBUG("Invoking GetLocalDimmingLevel()");
        status = GetLocalDimmingLevel(&ldimStateLevelGet);
        UT_LOG_DEBUG("GetLocalDimmingLevel() returned %d and level %d", status, ldimStateLevelGet);
        UT_ASSERT_EQUAL(status, tvERROR_NONE);
        if(status != tvERROR_NONE)
        {
            UT_LOG_ERROR("GetLocalDimmingLevel failed with status: %d", status);
        }
        UT_ASSERT_EQUAL(ldimStateLevel, ldimStateLevelGet);
    }

    UT_LOG_DEBUG("Invoking TvTerm()");
    status = TvTerm();
    UT_LOG_DEBUG("TvTerm() returned %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the Set and Get Brightness functionality of the TV settings
*
* This test initializes the TV settings, sets the brightness to a specific value, retrieves the set brightness, and then de-initializes the TV settings. It uses CUnit assertions to verify the return values of the API calls. The purpose of this test is to ensure that the SetBrightness and GetBrightness functions of the TV settings are working as expected.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 014@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetBrightness(void)
{
    gTestID = 14;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    int brightness = 50;
    int get_brightness;

    UT_LOG_DEBUG("Invoking TvInit");
    status = TvInit();
    UT_LOG_DEBUG("TvInit status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking SetBrightness with brightness: %d", brightness);
    status = SetBrightness(brightness);
    UT_LOG_DEBUG("SetBrightness status: %d", status);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE)
    {
        UT_LOG_ERROR("SetBrightness failed with status: %d", status);
        UT_LOG_DEBUG("Invoking TvTerm due to SetBrightness failure");
        TvTerm();
        return;
    }

    UT_LOG_DEBUG("Invoking GetBrightness");
    status = GetBrightness(&get_brightness);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    UT_LOG_DEBUG("GetBrightness status: %d, brightness: %d", status, get_brightness);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE || get_brightness != brightness)
    {
        UT_LOG_ERROR("GetBrightness failed with status: %d", status);
    }
    UT_ASSERT_EQUAL(brightness, get_brightness);

    UT_LOG_DEBUG("Invoking TvTerm");
    status = TvTerm();
    UT_LOG_DEBUG("TvTerm status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the functionality of Set and Get Contrast in TV settings
*
* This test case validates the SetContrast and GetContrast functions of the TV settings API.
* The test sets a contrast value and then retrieves it to verify if the set value and retrieved value are same.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 015@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetContrast(void)
{
    gTestID = 15;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t ret;
    int contrast = 50;
    int getContrast;

    UT_LOG_DEBUG("Invoking TvInit()");
    ret = TvInit();
    UT_LOG_DEBUG("Return status: %d", ret);
    UT_ASSERT_EQUAL_FATAL(ret, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking SetContrast() with valid contrast value: %d", contrast);
    ret = SetContrast(contrast);
    UT_LOG_DEBUG("Return status: %d", ret);
    UT_ASSERT_EQUAL(ret, tvERROR_NONE);
    if (ret != tvERROR_NONE)
    {
        UT_LOG_ERROR("SetContrast failed with status: %d", ret);
        UT_LOG_DEBUG("Invoking TvTerm due to SetContrast failure");
        TvTerm();
        return;
    }

    UT_LOG_DEBUG("Invoking GetContrast()");
    ret = GetContrast(&getContrast);
    UT_LOG_DEBUG("Return status: %d, Contrast value: %d", ret, getContrast);
    UT_ASSERT_EQUAL(ret, tvERROR_NONE);

    if (ret != tvERROR_NONE || getContrast != contrast)
    {
        UT_LOG_ERROR("Mismatch in set and get contrast values. Set: %d, Get: %d", contrast, getContrast);
    }
    UT_ASSERT_EQUAL(contrast, getContrast);

    UT_LOG_DEBUG("Invoking TvTerm()");
    ret = TvTerm();
    UT_LOG_DEBUG("Return status: %d", ret);
    UT_ASSERT_EQUAL_FATAL(ret, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test for setting and getting the sharpness of the TV
*
* This test checks if the SetSharpness and GetSharpness functions of the TV settings API work as expected. The sharpness is set to a specific value and then retrieved to verify if the set value is correctly stored and retrieved.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 016@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetSharpness(void)
{
    gTestID = 16;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    int setSharpness = 50;
    int getSharpness = 0;

    UT_LOG_DEBUG("Invoking TvInit()");
    status = TvInit();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking SetSharpness() with sharpness: %d", setSharpness);
    status = SetSharpness(setSharpness);
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE)
    {
        UT_LOG_ERROR("SetSharpness() failed with status: %d", status);
        UT_LOG_DEBUG("Invoking TvTerm()");
        TvTerm();
        return;
    }

    UT_LOG_DEBUG("Invoking GetSharpness()");
    status = GetSharpness(&getSharpness);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    UT_LOG_DEBUG("Return status: %d, Sharpness: %d", status, getSharpness);
    if (status != tvERROR_NONE || setSharpness != getSharpness)
    {
        UT_LOG_ERROR("GetSharpness() failed with status: %d", status);
    }

    UT_ASSERT_EQUAL(setSharpness, getSharpness);

    UT_LOG_DEBUG("Invoking TvTerm()");
    status = TvTerm();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test aims to verify the Set and Get functionality of the Saturation parameter in the TV settings
*
* In this test, the SetSaturation function is invoked to set a specific saturation value. Subsequently, the GetSaturation function is called to retrieve the set value. The test verifies if the retrieved value matches the set value, thereby validating the Set and Get functionality of the Saturation parameter.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 017@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetSaturation(void)
{
    gTestID = 17;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t ret;
    int saturation_set = 50;
    int saturation_get;

    UT_LOG_DEBUG("Invoking TvInit()");
    ret = TvInit();
    UT_LOG_DEBUG("Return status: %d", ret);
    UT_ASSERT_EQUAL_FATAL(ret, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking SetSaturation() with saturation value: %d", saturation_set);
    ret = SetSaturation(saturation_set);
    UT_ASSERT_EQUAL(ret, tvERROR_NONE);
    if (ret != tvERROR_NONE)
    {
        UT_LOG_ERROR("SetSaturation failed with error: %d", ret);
        UT_LOG_DEBUG("Invoking TvTerm()");
        TvTerm();
        return;
    }

    UT_LOG_DEBUG("Invoking GetSaturation()");
    ret = GetSaturation(&saturation_get);
    UT_LOG_DEBUG("Retrieved status : %d saturation value: %d", ret, saturation_get);
    UT_ASSERT_EQUAL(ret, tvERROR_NONE);

    if (ret != tvERROR_NONE || saturation_set != saturation_get)
    {
        UT_LOG_ERROR("GetSaturation failed with error: %d", ret);
    }
    UT_ASSERT_EQUAL(saturation_set, saturation_get);

    UT_LOG_DEBUG("Invoking TvTerm()");
    ret = TvTerm();
    UT_LOG_DEBUG("Return status: %d", ret);
    UT_ASSERT_EQUAL_FATAL(ret, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the Set and Get Hue functionality of the TV settings
*
* This test initializes the TV settings, sets a hue value, retrieves the hue value and verifies it matches the set value, and then de-initializes the TV settings. It uses CUnit assertions to verify the return values of the API calls and logs the progress of the test.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 018@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetHue(void)
{
    gTestID = 18;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    int hue = 50;
    int getHue;

    UT_LOG_DEBUG("Invoking TvInit");
    status = TvInit();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking SetHue with hue: %d", hue);
    status = SetHue(hue);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE)
    {
        UT_LOG_ERROR("SetHue failed with status: %d", status);
        TvTerm();
        return;
    }

    UT_LOG_DEBUG("Invoking GetHue");
    status = GetHue(&getHue);
    UT_LOG_DEBUG("Return status: %d, Hue: %d", status, getHue);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE || hue != getHue)
    {
        UT_LOG_ERROR("GetHue failed with status: %d", status);
    }
    UT_ASSERT_EQUAL(hue, getHue);

    UT_LOG_DEBUG("Invoking TvTerm");
    status = TvTerm();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the Set and Get functionality of Color Temperature in TV settings
*
* This test case verifies if the SetColorTemperature and GetColorTemperature functions are working as expected.
* The test first sets a color temperature value and then retrieves it to check if the set value is correctly stored and retrieved.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 019@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetColorTemperature(void)
{
    gTestID = 19;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    tvColorTemp_t colorTemp = tvColorTemp_STANDARD;
    tvColorTemp_t getColorTemp;

    UT_LOG_DEBUG("Invoking TvInit");
    status = TvInit();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking SetColorTemperature with colorTemp = %d", colorTemp);
    status = SetColorTemperature(colorTemp);
    UT_LOG_DEBUG("SetColorTemperature returned status = %d", status);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE)
    {
        UT_LOG_ERROR("SetColorTemperature failed with status = %d", status);
        UT_LOG_DEBUG("Invoking TvTerm due to failure of SetColorTemperature");
        TvTerm();
        return;
    }

    UT_LOG_DEBUG("Invoking GetColorTemperature");
    status = GetColorTemperature(&getColorTemp);
    UT_LOG_DEBUG("GetColorTemperature returned status = %d and colorTemp = %d", status, getColorTemp);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE || colorTemp != getColorTemp)
    {
        UT_LOG_ERROR("GetColorTemperature failed with status = %d", status);
    }
    UT_ASSERT_EQUAL(colorTemp, getColorTemp);

    UT_LOG_DEBUG("Invoking TvTerm");
    status = TvTerm();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test aims to verify the functionality of setting and getting the aspect ratio in a TV settings module.
*
* In this test, the aspect ratio is first set to a specific mode (4x3) using the SetAspectRatio() function. The GetAspectRatio() function is then invoked to retrieve the current aspect ratio. The test verifies that the aspect ratio retrieved matches the one that was set, ensuring the correct functionality of both SetAspectRatio() and GetAspectRatio() functions.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 020@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetAspectRatio(void)
{
    gTestID = 20;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    tvDisplayMode_t setMode = tvDisplayMode_4x3;
    tvDisplayMode_t getMode;

    UT_LOG_DEBUG("Invoking TvInit()");
    status = TvInit();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking SetAspectRatio() with tvDisplayMode_4x3");
    status = SetAspectRatio(setMode);
    UT_LOG_DEBUG("SetAspectRatio() returned status: %d", status);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE)
    {
        UT_LOG_ERROR("SetAspectRatio() failed with status: %d", status);
        UT_LOG_DEBUG("Invoking TvTerm()");
        TvTerm();
        return;
    }

    UT_LOG_DEBUG("Invoking GetAspectRatio()");
    status = GetAspectRatio(&getMode);
    UT_LOG_DEBUG("GetAspectRatio() returned mode: %d and status: %d", getMode, status);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);

    if (status != tvERROR_NONE || setMode != getMode)
    {
        UT_LOG_ERROR("GetAspectRatio() failed with status: %d", status);
    }

    UT_ASSERT_EQUAL(setMode, getMode);

    UT_LOG_DEBUG("Invoking TvTerm()");
    status = TvTerm();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test checks the functionality of SetAndGetLowLatencyState API
*
* This test aims to verify the correct functionality of SetAndGetLowLatencyState API. It first sets the low latency state and then gets the state to verify if the set operation was successful. The test is designed to ensure that the API is working as expected and is able to set and get the low latency state correctly.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 021@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetLowLatencyState(void)
{
    gTestID = 21;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    int lowlatencystate;

    UT_LOG_DEBUG("Invoking TvInit()");
    status = TvInit();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking SetLowLatencyState(1)");
    status = SetLowLatencyState(1);
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE)
    {
        UT_LOG_ERROR("SetLowLatencyState(1) failed with status %d", status);
        UT_LOG_DEBUG("Invoking TvTerm()");
        TvTerm();
        return;
    }

    UT_LOG_DEBUG("Invoking GetLowLatencyState(&lowlatencystate)");
    status = GetLowLatencyState(&lowlatencystate);
    UT_LOG_DEBUG("GetLowLatencyState() returned lowlatencystate: %d and status: %d", lowlatencystate, status);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE || lowlatencystate != 1)
    {
        UT_LOG_ERROR("GetLowLatencyState() failed with status %d, lowlatencystate %d", status, lowlatencystate);
    }
    UT_ASSERT_EQUAL(lowlatencystate, 1);

    UT_LOG_DEBUG("Invoking SetLowLatencyState(0)");
    status = SetLowLatencyState(0);
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE)
    {
        UT_LOG_ERROR("SetLowLatencyState(0) failed with status %d", status);
        UT_LOG_DEBUG("Invoking TvTerm()");
        TvTerm();
        return;
    }

    UT_LOG_DEBUG("Invoking GetLowLatencyState(&lowlatencystate)");
    status = GetLowLatencyState(&lowlatencystate);
    UT_LOG_DEBUG("GetLowLatencyState() returned lowlatencystate: %d and status: %d", lowlatencystate, status);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    UT_ASSERT_EQUAL(lowlatencystate, 0);
    if (status != tvERROR_NONE || lowlatencystate != 0)
    {
        UT_LOG_ERROR("GetLowLatencyState(&lowlatencystate) failed with status %d, lowlatencystate %d", status, lowlatencystate);
    }

    UT_LOG_DEBUG("Invoking TvTerm()");
    status = TvTerm();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test checks the functionality of setting and getting dynamic contrast in TV settings
*
* This test function tests the SetDynamicContrast and GetDynamicContrast functions of the TV settings API. It first sets the dynamic contrast to "enabled" and then gets the dynamic contrast to verify if it is set correctly. It then sets the dynamic contrast to "disabled" and again gets the dynamic contrast to verify if it is set correctly. The test ensures that the SetDynamicContrast and GetDynamicContrast functions are working as expected.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 022@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetDynamicContrast(void)
{
    gTestID = 22;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    char isDynamicContrastEnabled[10];

    UT_LOG_DEBUG("Invoking TvInit");
    status = TvInit();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking SetDynamicContrast with dynamicContrastEnable = enabled");
    status = SetDynamicContrast("enabled");
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE)
    {
        UT_LOG_ERROR("SetDynamicContrast(enabled) failed with status %d", status);
        UT_LOG_DEBUG("Invoking TvTerm()");
        TvTerm();
        return;
    }

    UT_LOG_DEBUG("Invoking GetDynamicContrast");
    status = GetDynamicContrast(isDynamicContrastEnabled);
    UT_LOG_DEBUG("Return status: %d, isDynamicContrastEnabled: %s", status, isDynamicContrastEnabled);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE || strcmp(isDynamicContrastEnabled,"enabled"))
    {
        UT_LOG_ERROR("GetDynamicContrast() failed with status %d, DynamicContrast: %s", status, isDynamicContrastEnabled);
    }
    UT_ASSERT_STRING_EQUAL(isDynamicContrastEnabled, "enabled");

    UT_LOG_DEBUG("Invoking SetDynamicContrast with dynamicContrastEnable = disabled");
    status = SetDynamicContrast("disabled");
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    UT_LOG_DEBUG("Return status: %d", status);
    if (status != tvERROR_NONE)
    {
        UT_LOG_ERROR("SetDynamicContrast(disabled) failed with status %d", status);
        UT_LOG_DEBUG("Invoking TvTerm()");
        TvTerm();
        return;
    }

    UT_LOG_DEBUG("Invoking GetDynamicContrast");
    status = GetDynamicContrast(isDynamicContrastEnabled);
    UT_LOG_DEBUG("Return status: %d, isDynamicContrastEnabled: %s", status, isDynamicContrastEnabled);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE || strcmp(isDynamicContrastEnabled,"disabled"))
    {
        UT_LOG_ERROR("GetDynamicContrast() failed with status %d, DynamicContrast: %s", status, isDynamicContrastEnabled);
    }
    UT_ASSERT_STRING_EQUAL(isDynamicContrastEnabled, "disabled");

    UT_LOG_DEBUG("Invoking TvTerm");
    status = TvTerm();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to set and get the dynamic gamma value in TV settings
*
* This test function initializes the TV settings, sets a dynamic gamma value, retrieves the set value, and then terminates the TV settings. It uses assertions to validate the return values of the API calls and logs the progress of the test.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 023@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetDynamicGamma(void)
{
    gTestID = 23;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    double setGammaValue = 2.0;
    double getGammaValue = 0.0;

    UT_LOG_DEBUG("Invoking TvInit()");
    status = TvInit();
    UT_LOG_DEBUG("TvInit() returned status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking SetDynamicGamma() with valid gamma value: %f", setGammaValue);
    status = SetDynamicGamma(setGammaValue);
    UT_LOG_DEBUG("SetDynamicGamma() returned status: %d", status);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE)
    {
        UT_LOG_ERROR("SetDynamicGamma() failed with status: %d", status);
        UT_LOG_DEBUG("Invoking TvTerm()");
        TvTerm();
        return;
    }

    UT_LOG_DEBUG("Invoking GetDynamicGamma()");
    status = GetDynamicGamma(&getGammaValue);
    UT_LOG_DEBUG("GetDynamicGamma() returned gamma value: %f and status: %d", getGammaValue, status);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE || setGammaValue != getGammaValue)
    {
        UT_LOG_ERROR("GetDynamicGamma() failed with status %d, GammaValue: %s", status, getGammaValue);
    }
    UT_ASSERT_EQUAL(setGammaValue, getGammaValue);

    UT_LOG_DEBUG("Invoking TvTerm()");
    status = TvTerm();
    UT_LOG_DEBUG("TvTerm() returned status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test checks the GetSupportedDolbyVisionModes function of the L2 TV Settings API
*
* This test is designed to verify the functionality of the GetSupportedDolbyVisionModes function. It checks if the function correctly retrieves the supported Dolby Vision modes from the TV settings. The test first initializes the TV settings, then calls the GetSupportedDolbyVisionModes function with valid parameters, and finally terminates the TV settings. The test asserts that the function calls return no errors and that the count of the supported modes is within the valid range.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 024@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_GetSupportedDolbyVisionModes(void)
{
    gTestID = 24;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    tvDolbyMode_t *dvModes[tvMode_Max];
    unsigned short count;
    ut_kvp_instance_t *pInstance = NULL;
    char buffer[50];
    uint32_t mode;
    int flag;
    int j;

    UT_LOG_DEBUG("Invoking TvInit");
    status = TvInit();
    UT_LOG_DEBUG("TvInit status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking GetTVSupportedDolbyVisionModes with valid dvModes and count");
    status = GetTVSupportedDolbyVisionModes(dvModes, &count);
    UT_LOG_DEBUG("GetTVSupportedDolbyVisionModes status: %d, count: %d", status, count);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE)
    {
        UT_LOG_ERROR("GetTVSupportedDolbyVisionModes failed with status: %d", status);
        TvTerm();
        return;
    }

    UT_ASSERT_TRUE(count >= 0 && count <= tvMode_Max);

    UT_ASSERT_KVP_EQUAL_PROFILE_UINT16(count, "DolbyVisionMode/numberOfDolbyVisionMode");

    pInstance = ut_kvp_profile_getInstance();
    for (int i=0;i<count;i++)
    {
        flag = 0;
        sprintf(buffer, "DolbyVisionMode/index/%d", i);
        mode = ut_kvp_getUInt32Field( pInstance, buffer);
        j = 0;
        for ( j=0; j< count; j++)
        {
            if (*dvModes[j] == mode)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            UT_PASS("DolbyVisionMode match");
            UT_LOG_DEBUG("DolbyVision Mode : %d is in the list of supported DolbyVisionModes", *dvModes[j]);
        }
        else
        {
            UT_FAIL("DolbyVisionMode mismatch");
            UT_LOG_DEBUG("DolbyVisionMode : %d is not in the list of supported DolbyVisionModes ", *dvModes[j]);
        }
    }

    UT_LOG_DEBUG("Invoking TvTerm");
    status = TvTerm();
    UT_LOG_DEBUG("TvTerm status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the setting and getting of Dolby Vision Mode
*
* This test case verifies the functionality of setting and getting the Dolby Vision Mode in a TV. It ensures that the SetTVDolbyVisionMode and GetTVDolbyVisionMode functions work as expected and there is no mismatch in the set and get Dolby Vision Mode.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 025@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetDolbyVisionMode(void)
{
    gTestID = 25;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    tvDolbyMode_t dolbyMode = tvDolbyMode_Dark;
    tvDolbyMode_t getDolbyMode;

    UT_LOG_DEBUG("Invoking TvInit");
    status = TvInit();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking SetTVDolbyVisionMode with dolbyMode: %d", dolbyMode);
    status = SetTVDolbyVisionMode(dolbyMode);
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE)
    {
        UT_LOG_ERROR("SetTVDolbyVisionMode failed with status: %d", status);
        TvTerm();
        return;
    }

    UT_LOG_DEBUG("Invoking GetTVDolbyVisionMode");
    status = GetTVDolbyVisionMode(&getDolbyMode);
    UT_LOG_DEBUG("Return status: %d, getDolbyMode: %d", status, getDolbyMode);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    UT_ASSERT_EQUAL(getDolbyMode, dolbyMode);

    if (status != tvERROR_NONE || getDolbyMode != dolbyMode)
    {
        UT_LOG_ERROR("Mismatch in set and get Dolby Vision Mode");
    }

    UT_LOG_DEBUG("Invoking TvTerm");
    status = TvTerm();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the function GetTVSupportedPictureModes
*
* This test verifies if the function GetTVSupportedPictureModes correctly retrieves the supported picture modes. It checks if the function returns the correct status and the count of supported picture modes is within the expected range.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 026@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_GetTVSupportedPictureModes(void)
{
    gTestID = 26;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    pic_modes_t *pictureModes[PIC_MODES_SUPPORTED_MAX];
    unsigned short count;

    UT_LOG_DEBUG("Invoking TvInit with no input parameters");
    status = TvInit();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking GetTVSupportedPictureModes with valid pictureModes and count buffers");
    status = GetTVSupportedPictureModes(pictureModes, &count);
    UT_LOG_DEBUG("Return status: %d, count: %d", status, count);
    UT_ASSERT_NOT_EQUAL(status, tvERROR_INVALID_PARAM);
    UT_ASSERT_NOT_EQUAL(status, tvERROR_INVALID_STATE);
    UT_ASSERT_TRUE(count >= 1 && count <= PIC_MODES_SUPPORTED_MAX);

    for (int i = 0; i < count; i++)
    {
        UT_ASSERT_KVP_EQUAL_PROFILE_STRING(pictureModes[i]->name, "PictureMode/index");
    }

    UT_LOG_DEBUG("Invoking TvTerm with no input parameters");
    status = TvTerm();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test aims to validate the Set and Get Picture Mode functionality of the TV settings
*
* In this test, the TV is initialized and the supported picture modes are fetched. Each of these modes is then set as the current picture mode and retrieved to verify if the setting was successful. The TV is terminated at the end of the test. This test is crucial to ensure that the user can successfully change and retrieve the picture mode settings of the TV.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 027@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetPictureMode(void)
{
    gTestID = 27;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    pic_modes_t *pictureModes[PIC_MODES_SUPPORTED_MAX];
    unsigned short count;
    char pictureMode[PIC_MODE_NAME_MAX];

    UT_LOG_DEBUG("Invoking TvInit()");
    status = TvInit();
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);
    UT_LOG_DEBUG("TvInit status: %d", status);

    UT_LOG_DEBUG("Invoking GetTVSupportedPictureModes()");
    status = GetTVSupportedPictureModes(pictureModes, &count);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    UT_LOG_DEBUG("GetTVSupportedPictureModes status: %d, count: %d", status, count);
    UT_ASSERT_TRUE(count >= 1 && count <= PIC_MODES_SUPPORTED_MAX);

    for (int i = 0; i < count; i++) {
        UT_LOG_DEBUG("Invoking SetTVPictureMode() with pictureMode: %s", pictureModes[i]->name);
        status = SetTVPictureMode(pictureModes[i]->name);
        UT_ASSERT_EQUAL(status, tvERROR_NONE);
        UT_LOG_DEBUG("SetTVPictureMode status: %d", status);

        UT_LOG_DEBUG("Invoking GetTVPictureMode()");
        status = GetTVPictureMode(pictureMode);
        UT_ASSERT_EQUAL(status, tvERROR_NONE);
        UT_LOG_DEBUG("GetTVPictureMode status: %d, pictureMode: %s", status, pictureMode);
        UT_ASSERT_STRING_EQUAL(pictureModes[i]->name, pictureMode);

        if (status != tvERROR_NONE) {
            UT_LOG_ERROR("Error in SetAndGetPictureMode, invoking TvTerm()");
            status = TvTerm();
            UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);
            UT_LOG_DEBUG("TvTerm status: %d", status);
            continue;
        }
    }

    UT_LOG_DEBUG("Invoking TvTerm()");
    status = TvTerm();
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);
    UT_LOG_DEBUG("TvTerm status: %d", status);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test checks the functionality of setting and getting the color temperature Rgain in a TV settings module.
*
* This test case is designed to verify the SetColorTemp_Rgain_onSource and GetColorTemp_Rgain_onSource functions. It iterates over all color temperatures and source offsets, setting the Rgain value and then retrieving it to ensure the set and retrieved values match. This is done to ensure the correct functioning of the TV settings module in handling color temperature Rgain values.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 028@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetColorTempRgain(void)
{
    gTestID = 28;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    int rgain = 0;
    int setRgain = 0;
    tvColorTemp_t colorTemp;
    tvColorTempSourceOffset_t sourceId;

    UT_LOG_DEBUG("Invoking TvInit");
    status = TvInit();
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    for(colorTemp = tvColorTemp_STANDARD; colorTemp < tvColorTemp_MAX; colorTemp++)
    {
        for(sourceId = ALL_SRC_OFFSET; sourceId < MAX_OFFSET; sourceId++)
        {
            for(setRgain = 0; setRgain <= 2047; setRgain++)
            {
                UT_LOG_DEBUG("Invoking SetColorTemp_Rgain_onSource with colorTemp: %d, rgain: %d, sourceId: %d, saveOnly: 0", colorTemp, setRgain, sourceId);
                status = SetColorTemp_Rgain_onSource(colorTemp, setRgain, sourceId, 0);
                UT_ASSERT_EQUAL(status, tvERROR_NONE);
                if(status != tvERROR_NONE)
                {
                    UT_LOG_ERROR("SetColorTemp_Rgain_onSource failed with status: %d", status);
                    continue;
                }

                UT_LOG_DEBUG("Invoking GetColorTemp_Rgain_onSource with colorTemp: %d, sourceId: %d", colorTemp, sourceId);
                status = GetColorTemp_Rgain_onSource(colorTemp, &rgain, sourceId);
                UT_ASSERT_EQUAL(status, tvERROR_NONE);
                if(status != tvERROR_NONE)
                {
                    UT_LOG_ERROR("GetColorTemp_Rgain_onSource failed with status: %d", status);
                    continue;
                }

                UT_LOG_DEBUG("Retrieved rgain: %d", rgain);
                UT_ASSERT_EQUAL(rgain, setRgain);
                if(rgain != setRgain)
                {
                    UT_LOG_ERROR("Mismatch in set and retrieved rgain values");
                }
            }
        }
    }

    UT_LOG_DEBUG("Invoking TvTerm");
    status = TvTerm();
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the setting and getting of color temperature ggain in TV settings
*
* This test initializes the TV settings, loops through the different color temperatures and source ids, sets and gets the ggain value for each combination, verifies that the retrieved ggain value matches the set value, and finally de-initializes the TV settings. It uses Cunit's assertion functions to check the return values of the API calls.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 029@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetColorTempGgain(void)
{
    gTestID = 29;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    int ggain = 0;
    int set_ggain = 0;

    UT_LOG_DEBUG("Invoking TvInit");
    status = TvInit();
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    for(tvColorTemp_t colorTemp = tvColorTemp_STANDARD; colorTemp < tvColorTemp_MAX; colorTemp++)
    {
        for(tvColorTempSourceOffset_t sourceId = ALL_SRC_OFFSET; sourceId < MAX_OFFSET; sourceId++)
        {
            for(set_ggain = 0; set_ggain <= 2047; set_ggain++)
            {
                UT_LOG_DEBUG("Invoking SetColorTemp_Ggain_onSource with colorTemp: %d, ggain: %d, sourceId: %d, saveOnly: 0", colorTemp, set_ggain, sourceId);
                status = SetColorTemp_Ggain_onSource(colorTemp, set_ggain, sourceId, 0);
                if(status != tvERROR_NONE)
                {
                    UT_LOG_ERROR("SetColorTemp_Ggain_onSource failed with status: %d", status);
                    UT_LOG_DEBUG("Invoking TvTerm");
                    TvTerm();
                    continue;
                }

                UT_LOG_DEBUG("Invoking GetColorTemp_Ggain_onSource with colorTemp: %d, sourceId: %d", colorTemp, sourceId);
                status = GetColorTemp_Ggain_onSource(colorTemp, &ggain, sourceId);
                if(status != tvERROR_NONE)
                {
                    UT_LOG_ERROR("GetColorTemp_Ggain_onSource failed with status: %d", status);
                    UT_LOG_DEBUG("Invoking TvTerm");
                    TvTerm();
                    continue;
                }

                UT_LOG_DEBUG("ggain: %d, status: %d", ggain, status);
                UT_ASSERT_EQUAL(status, tvERROR_NONE);
                UT_ASSERT_EQUAL(ggain, set_ggain);
            }
        }
    }

    UT_LOG_DEBUG("Invoking TvTerm");
    status = TvTerm();
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test aims to set and get the color temperature background gain in a TV setting
*
* This test sets the color temperature background gain for all color temperatures and source offsets, and then retrieves the set value to verify if the set and get operations are working as expected.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 030@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetColorTempBgain(void)
{
    gTestID = 30;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    int bgain = 0;
    int get_bgain = 0;

    UT_LOG_DEBUG("Invoking TvInit");
    status = TvInit();
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    for (tvColorTemp_t colorTemp = tvColorTemp_STANDARD; colorTemp < tvColorTemp_MAX; colorTemp++)
    {
        for (tvColorTempSourceOffset_t sourceId = ALL_SRC_OFFSET; sourceId < MAX_OFFSET; sourceId++)
        {
            for (bgain = 0; bgain <= 2047; bgain++)
            {
                UT_LOG_DEBUG("Invoking SetColorTemp_Bgain_onSource with colorTemp: %d, bgain: %d, sourceId: %d, saveOnly: 0", colorTemp, bgain, sourceId);
                status = SetColorTemp_Bgain_onSource(colorTemp, bgain, sourceId, 0);
                if (status != tvERROR_NONE)
                {
                    UT_LOG_ERROR("SetColorTemp_Bgain_onSource failed with status: %d", status);
                    continue;
                }

                UT_LOG_DEBUG("Invoking GetColorTemp_Bgain_onSource with colorTemp: %d, sourceId: %d", colorTemp, sourceId);
                status = GetColorTemp_Bgain_onSource(colorTemp, &get_bgain, sourceId);
                if (status != tvERROR_NONE)
                {
                    UT_LOG_ERROR("GetColorTemp_Bgain_onSource failed with status: %d", status);
                    continue;
                }

                UT_LOG_DEBUG("bgain value retrieved: %d", get_bgain);
                UT_ASSERT_EQUAL(bgain, get_bgain);
            }
        }
    }

    UT_LOG_DEBUG("Invoking TvTerm");
    status = TvTerm();
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test aims to verify the functionality of setting and getting color temperature post offset on a source
*
* In this test, the SetColorTemp_R_post_offset_onSource and GetColorTemp_R_post_offset_onSource functions are invoked with various parameters to ensure they work as expected. The test checks if the set value is equal to the retrieved value for different color temperatures, source offsets, and saveOnly parameters. If the functions return an error, it is logged and the test continues with the next set of parameters.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 031@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetColorTemp_R_post_offset_onSource(void)
{
    gTestID = 31;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    int rpostoffset_set, rpostoffset_get;
    tvColorTemp_t colorTemp;
    tvColorTempSourceOffset_t sourceId;
    int saveOnly;

    UT_LOG_DEBUG("Invoking TvInit");
    status = TvInit();
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    for (colorTemp = tvColorTemp_STANDARD; colorTemp < tvColorTemp_MAX; colorTemp++)
    {
        for (sourceId = ALL_SRC_OFFSET; sourceId < MAX_OFFSET; sourceId++)
        {
            for (rpostoffset_set = -1024; rpostoffset_set <= 1023; rpostoffset_set++)
            {
                for (saveOnly = 0; saveOnly <= 1; saveOnly++)
                {
                    UT_LOG_DEBUG("Invoking SetColorTemp_R_post_offset_onSource with colorTemp=%d, rpostoffset=%d, sourceId=%d, saveOnly=%d", colorTemp, rpostoffset_set, sourceId, saveOnly);
                    status = SetColorTemp_R_post_offset_onSource(colorTemp, rpostoffset_set, sourceId, saveOnly);
                    UT_ASSERT_EQUAL(status, tvERROR_NONE);
                    if (status != tvERROR_NONE)
                    {
                        UT_LOG_ERROR("SetColorTemp_R_post_offset_onSource failed with status=%d", status);
                        continue;
                    }

                    UT_LOG_DEBUG("Invoking GetColorTemp_R_post_offset_onSource with colorTemp=%d, sourceId=%d", colorTemp, sourceId);
                    status = GetColorTemp_R_post_offset_onSource(colorTemp, &rpostoffset_get, sourceId);
                    UT_ASSERT_EQUAL(status, tvERROR_NONE);
                    if (status != tvERROR_NONE)
                    {
                        UT_LOG_ERROR("GetColorTemp_R_post_offset_onSource failed with status=%d", status);
                        continue;
                    }

                    UT_LOG_DEBUG("Retrieved rpostoffset=%d", rpostoffset_get);
                    UT_ASSERT_EQUAL(rpostoffset_set, rpostoffset_get);
                }
            }
        }
    }

    UT_LOG_DEBUG("Invoking TvTerm");
    status = TvTerm();
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test checks the functionality of setting and getting color temperature G post offset
*
* This test case is designed to verify the functionality of the SetColorTemp_G_post_offset_onSource and GetColorTemp_G_post_offset_onSource functions. It checks if the color temperature G post offset can be set and retrieved correctly for all color temperatures and source offsets. The test iterates over all possible color temperatures and source offsets, sets a G post offset, retrieves it and checks if the retrieved value matches the set value.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 032@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetColorTempGPostOffset(void)
{
    gTestID = 32;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    int gpostoffset_set, gpostoffset_get;
    tvColorTemp_t colorTemp;
    tvColorTempSourceOffset_t sourceId;

    status = TvInit();
    UT_LOG_DEBUG("Invoking TvInit");
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);
    UT_LOG_DEBUG("TvInit status: %d", status);

    for(colorTemp = tvColorTemp_STANDARD; colorTemp < tvColorTemp_MAX; colorTemp++)
    {
        for(sourceId = ALL_SRC_OFFSET; sourceId < MAX_OFFSET; sourceId++)
        {
            for(gpostoffset_set = -1024; gpostoffset_set <= 1023; gpostoffset_set++)
            {
                UT_LOG_DEBUG("Invoking SetColorTemp_G_post_offset_onSource with colorTemp: %d, gpostoffset: %d, sourceId: %d, saveOnly: 0", colorTemp, gpostoffset_set, sourceId);
                status = SetColorTemp_G_post_offset_onSource(colorTemp, gpostoffset_set, sourceId, 0);
                UT_ASSERT_EQUAL(status, tvERROR_NONE);
                UT_LOG_DEBUG("SetColorTemp_G_post_offset_onSource status: %d", status);

                if(status != tvERROR_NONE)
                {
                    UT_LOG_ERROR("SetColorTemp_G_post_offset_onSource failed with status: %d", status);
                    continue;
                }

                UT_LOG_DEBUG("Invoking GetColorTemp_G_post_offset_onSource with colorTemp: %d, sourceId: %d", colorTemp, sourceId);
                status = GetColorTemp_G_post_offset_onSource(colorTemp, &gpostoffset_get, sourceId);
                UT_ASSERT_EQUAL(status, tvERROR_NONE);
                UT_ASSERT_EQUAL(gpostoffset_set, gpostoffset_get);
                UT_LOG_DEBUG("GetColorTemp_G_post_offset_onSource status: %d, gpostoffset: %d", status, gpostoffset_get);

                if(status != tvERROR_NONE)
                {
                    UT_LOG_ERROR("GetColorTemp_G_post_offset_onSource failed with status: %d", status);
                    continue;
                }
            }
        }
    }

    status = TvTerm();
    UT_LOG_DEBUG("Invoking TvTerm");
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);
    UT_LOG_DEBUG("TvTerm status: %d", status);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test aims to verify the functionality of setting and getting color temperature B post offset in L2 TV settings.
*
* In this test, the SetColorTemp_B_post_offset_onSource and GetColorTemp_B_post_offset_onSource functions are tested for all color temperatures and source offsets. The test ensures that the set value is correctly retrieved by the get function. This is important to ensure the correct functioning of color temperature settings in the TV.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 033@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetColorTempBPostOffset(void)
{
    gTestID = 33;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    int bpostoffset_set, bpostoffset_get;
    tvColorTemp_t colorTemp;
    tvColorTempSourceOffset_t sourceId;

    UT_LOG_DEBUG("Invoking TvInit");
    status = TvInit();
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    for (colorTemp = tvColorTemp_STANDARD; colorTemp < tvColorTemp_MAX; colorTemp++)
    {
        for (sourceId = ALL_SRC_OFFSET; sourceId < MAX_OFFSET; sourceId++)
        {
            for (bpostoffset_set = -1024; bpostoffset_set <= 1023; bpostoffset_set++)
            {
                UT_LOG_DEBUG("Invoking SetColorTemp_B_post_offset_onSource with colorTemp=%d, bpostoffset=%d, sourceId=%d, saveOnly=1", colorTemp, bpostoffset_set, sourceId);
                status = SetColorTemp_B_post_offset_onSource(colorTemp, bpostoffset_set, sourceId, 1);
                UT_ASSERT_EQUAL(status, tvERROR_NONE);
                if (status != tvERROR_NONE)
                {
                    UT_LOG_ERROR("SetColorTemp_B_post_offset_onSource failed with status=%d", status);
                    continue;
                }

                UT_LOG_DEBUG("Invoking GetColorTemp_B_post_offset_onSource with colorTemp=%d, sourceId=%d", colorTemp, sourceId);
                status = GetColorTemp_B_post_offset_onSource(colorTemp, &bpostoffset_get, sourceId);
                UT_ASSERT_EQUAL(status, tvERROR_NONE);
                if (status != tvERROR_NONE)
                {
                    UT_LOG_ERROR("GetColorTemp_B_post_offset_onSource failed with status=%d", status);
                    continue;
                }

                UT_LOG_DEBUG("Retrieved bpostoffset=%d", bpostoffset_get);
                UT_ASSERT_EQUAL(bpostoffset_set, bpostoffset_get);
            }
        }
    }

    UT_LOG_DEBUG("Invoking TvTerm");
    status = TvTerm();
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the disabling of WB Calibration Mode in TV settings
*
* This test case verifies if the White Balance (WB) Calibration Mode in TV settings can be successfully disabled and the status is correctly reflected. The test is crucial to ensure the correct functioning of the WB Calibration Mode toggle feature.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 034@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_DisableAndVerifyWBCalibrationMode(void)
{
    gTestID = 34;
    tvError_t status;
    bool value;

    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    UT_LOG_DEBUG("Invoking TvInit()");
    status = TvInit();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking EnableWBCalibrationMode() with false");
    status = EnableWBCalibrationMode(false);
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking GetCurrentWBCalibrationMode()");
    status = GetCurrentWBCalibrationMode(&value);
    UT_LOG_DEBUG("Return status: %d, Output value: %d", status, value);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    UT_ASSERT_EQUAL(value, false);

    if (status != tvERROR_NONE || value != false)
    {
        UT_LOG_DEBUG("Invoking TvTerm()");
        status = TvTerm();
        UT_LOG_DEBUG("Return status: %d", status);
        UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the functionality of enabling and verifying the WB Calibration Mode in TV settings
*
* This test case invokes the TvInit() function to initialize the TV settings, then it enables the WB Calibration Mode by calling EnableWBCalibrationMode() function with value set to true. It then verifies the current WB Calibration Mode by calling GetCurrentWBCalibrationMode() function. The same steps are repeated to disable the WB Calibration Mode and verify it. Finally, it terminates the TV settings by calling TvTerm() function. The test case asserts that all the invoked functions return the expected status and the WB Calibration Mode is correctly enabled and disabled.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 035@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_EnableAndVerifyWBCalibrationMode(void)
{
    gTestID = 35;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    bool value;

    UT_LOG_DEBUG("Invoking TvInit()");
    status = TvInit();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking EnableWBCalibrationMode() with value set to true");
    status = EnableWBCalibrationMode(true);
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking GetCurrentWBCalibrationMode()");
    status = GetCurrentWBCalibrationMode(&value);
    UT_LOG_DEBUG("Return status: %d, Output value: %d", status, value);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    UT_ASSERT_EQUAL(value, true);

    UT_LOG_DEBUG("Invoking EnableWBCalibrationMode() with value set to false");
    status = EnableWBCalibrationMode(false);
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking GetCurrentWBCalibrationMode()");
    status = GetCurrentWBCalibrationMode(&value);
    UT_LOG_DEBUG("Return status: %d, Output value: %d", status, value);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    UT_ASSERT_EQUAL(value, false);

    UT_LOG_DEBUG("Invoking TvTerm()");
    status = TvTerm();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test aims to verify the functionality of setting and getting the Gamma Table in the TV settings.
*
* In this test, the SetGammaTable() and GetGammaTable() functions are tested to ensure they are working as expected. The test first initializes the TV, sets the Gamma Table, retrieves it, and then compares the set and retrieved values to ensure they match. If any of these steps fail, the test is considered failed.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 036@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetGammaTable(void)
{
    gTestID = 36;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t ret;
    unsigned short size = 256;
    unsigned short pData_R[size], pData_G[size], pData_B[size];
    unsigned short getData_R[size], getData_G[size], getData_B[size];

    UT_LOG_DEBUG("Invoking TvInit()");
    ret = TvInit();
    UT_ASSERT_EQUAL_FATAL(ret, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking SetGammaTable() with valid buffers");
    ret = SetGammaTable(pData_R, pData_G, pData_B, size);
    UT_LOG_DEBUG("Return status: %d", ret);
    UT_ASSERT_EQUAL(ret, tvERROR_NONE);

    if (ret != tvERROR_NONE) {
        UT_LOG_ERROR("SetGammaTable failed, invoking TvTerm()");
        TvTerm();
        return;
    }

    UT_LOG_DEBUG("Invoking GetGammaTable() with valid buffers");
    ret = GetGammaTable(getData_R, getData_G, getData_B, size);
    UT_LOG_DEBUG("Return status: %d", ret);
    UT_ASSERT_EQUAL(ret, tvERROR_NONE);

    for (int i = 0; i < size; i++) {
        UT_ASSERT_EQUAL(pData_R[i], getData_R[i]);
        UT_ASSERT_EQUAL(pData_G[i], getData_G[i]);
        UT_ASSERT_EQUAL(pData_B[i], getData_B[i]);
    }

    UT_LOG_DEBUG("Invoking TvTerm()");
    ret = TvTerm();
    UT_LOG_DEBUG("Return status: %d", ret);
    UT_ASSERT_EQUAL_FATAL(ret, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the functionality of GetDefaultGammaTable API
*
* This test case checks if the GetDefaultGammaTable API is able to fetch the default gamma table for a given color temperature. It also checks if the returned gamma values are within the expected range.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 037@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_GetDefaultGammaTable(void)
{
    gTestID = 37;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    unsigned short pData_R[256];
    unsigned short pData_G[256];
    unsigned short pData_B[256];
    tvColorTemp_t colortemp = tvColorTemp_STANDARD;

    UT_LOG_DEBUG("Invoking TvInit()");
    status = TvInit();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking GetDefaultGammaTable() with valid color temperature and arrays");
    status = GetDefaultGammaTable(colortemp, pData_R, pData_G, pData_B, 256);
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);

    for(int i = 0; i < 256; i++)
    {
        CU_ASSERT(pData_R[i] >= 0 && pData_R[i] <= 65535);
        CU_ASSERT(pData_G[i] >= 0 && pData_G[i] <= 65535);
        CU_ASSERT(pData_B[i] >= 0 && pData_B[i] <= 65535);
    }

    UT_LOG_DEBUG("Invoking TvTerm()");
    status = TvTerm();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test aims to verify the Set and Get functionality of DvTmaxValue in the TV settings
*
* In this test, we first initialize the TV, then set a DvTmaxValue and try to retrieve the same value. The test is designed to ensure that the set and get functions for DvTmaxValue are working as expected.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 038@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetDvTmaxValue(void)
{
    gTestID = 38;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    int setValue = 5000;
    int getValue;

    UT_LOG_DEBUG("Invoking TvInit");
    status = TvInit();
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking SetDvTmaxValue with value: %d", setValue);
    status = SetDvTmaxValue(setValue);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE) {
        UT_LOG_ERROR("SetDvTmaxValue failed with status: %d", status);
        UT_LOG_DEBUG("Invoking TvTerm");
        TvTerm();
        return;
    }

    UT_LOG_DEBUG("Invoking GetDvTmaxValue");
    status = GetDvTmaxValue(&getValue);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE) {
        UT_LOG_ERROR("GetDvTmaxValue failed with status: %d", status);
        UT_LOG_DEBUG("Invoking TvTerm");
        TvTerm();
        return;
    }

    UT_LOG_DEBUG("Retrieved value: %d", getValue);
    UT_ASSERT_EQUAL(setValue, getValue);

    UT_LOG_DEBUG("Invoking TvTerm");
    status = TvTerm();
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the GetSupportedComponentColor API
*
* This test function initializes the TV settings, gets the supported component colors, verifies each color, and then de-initializes the TV settings. It uses the Cunit assertion functions to check the return status of each API call. It also uses the provided macro to compare the obtained component colors with the values in the platform-supported configurations file.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 039@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_GetSupportedComponentColor(void)
{
    gTestID = 39;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    int blComponentColor;

    UT_LOG_DEBUG("Invoking TvInit()");
    status = TvInit();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking GetSupportedComponentColor() with valid address");
    status = GetSupportedComponentColor(&blComponentColor);
    UT_LOG_DEBUG("Return status: %d, Supported Component Colors: %d", status, blComponentColor);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_ASSERT_KVP_EQUAL_PROFILE_UINT32(blComponentColor, "SupportedComponentColor");

    for (int i = 0; i < sizeof(blComponentColor)*8; i++)
    {
        if ((blComponentColor >> i) & 1)
        {
            UT_LOG_DEBUG("Component color at index %d is supported", i);
        }
        else
        {
            UT_LOG_DEBUG("Component color at index %d is not supported", i);
        }
    }

    UT_LOG_DEBUG("Invoking TvTerm()");
    status = TvTerm();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test aims to set and get the component saturation for a TV
*
* In this test, the component saturation of a TV is set and then retrieved to verify if the set value is correctly stored and retrieved. This is done for all possible color components. The test is important to ensure the correct functioning of the saturation setting and retrieval mechanism in the TV settings.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 040@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetComponentSaturation(void)
{
    gTestID = 40;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    int saturation = 0;
    int setSaturation = 0;

    UT_LOG_DEBUG("Invoking TvInit()");
    status = TvInit();
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking SetCMSState(true)");
    status = SetCMSState(true);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    for(tvDataComponentColor_t color = tvDataColor_RED; color < tvDataColor_MAX; color++)
    {
        setSaturation = rand() % 101; // Random saturation value between 0 and 100

        UT_LOG_DEBUG("Invoking SetCurrentComponentSaturation(%d, %d)", color, setSaturation);
        status = SetCurrentComponentSaturation(color, setSaturation);
        UT_LOG_DEBUG("SetCurrentComponentSaturation returned %d", status);
        if(status != tvERROR_NONE)
        {
            UT_LOG_ERROR("SetCurrentComponentSaturation failed with status %d", status);
            TvTerm(); // Call post-requisite API
            continue;
        }
        UT_ASSERT_EQUAL(status, tvERROR_NONE);

        UT_LOG_DEBUG("Invoking GetCurrentComponentSaturation(%d, &saturation)", color);
        status = GetCurrentComponentSaturation(color, &saturation);
        UT_LOG_DEBUG("GetCurrentComponentSaturation returned %d and saturation %d", status, saturation);
        if(status != tvERROR_NONE)
        {
            UT_LOG_ERROR("GetCurrentComponentSaturation failed with status %d", status);
            continue;
        }
        UT_ASSERT_EQUAL(status, tvERROR_NONE);
        UT_ASSERT_EQUAL(saturation, setSaturation);
    }

    UT_LOG_DEBUG("Invoking TvTerm()");
    status = TvTerm();
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test for setting and getting the component hue in L2 TV settings
*
* This test checks if the SetCurrentComponentHue and GetCurrentComponentHue functions work as expected. It sets the hue for each color component and then retrieves it to verify if the set value is correctly stored and retrieved. This is done for all color components and for hue values from 0 to 100.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 041@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetComponentHue(void)
{
    gTestID = 41;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    int hue, hue_get;
    tvDataComponentColor_t color;

    UT_LOG_DEBUG("Invoking TvInit()");
    status = TvInit();
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking SetCMSState(true)");
    status = SetCMSState(true);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    for (color = tvDataColor_RED; color < tvDataColor_MAX; color++)
    {
        for (hue = 0; hue <= 100; hue++)
        {
            UT_LOG_DEBUG("Invoking SetCurrentComponentHue(%d, %d)", color, hue);
            status = SetCurrentComponentHue(color, hue);
            UT_LOG_DEBUG("Returned status: %d", status);
            UT_ASSERT_EQUAL(status, tvERROR_NONE);

            if (status != tvERROR_NONE)
            {
                UT_LOG_ERROR("SetCurrentComponentHue failed for color %d and hue %d", color, hue);
                continue;
            }

            UT_LOG_DEBUG("Invoking GetCurrentComponentHue(%d)", color);
            status = GetCurrentComponentHue(color, &hue_get);
            UT_LOG_DEBUG("Returned hue: %d, status: %d", hue_get, status);
            UT_ASSERT_EQUAL(status, tvERROR_NONE);
            UT_ASSERT_EQUAL(hue, hue_get);

            if (status != tvERROR_NONE || hue != hue_get)
            {
                UT_LOG_ERROR("GetCurrentComponentHue failed for color %d", color);
                continue;
            }
        }
    }

    UT_LOG_DEBUG("Invoking TvTerm()");
    status = TvTerm();
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test function is designed to test the setting and getting of component luma in the TV settings.
*
* In this test, the TV is initialized and the CMS state is set. Then, for each color component, the luma is set and then retrieved. The retrieved luma is then compared with the set luma to ensure they match. The TV is then terminated. This test is important to ensure that the luma can be correctly set and retrieved for each color component.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 042@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetComponentLuma(void)
{
    gTestID = 42;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t ret;
    int luma, lumaSet;
    tvDataComponentColor_t color;

    UT_LOG_DEBUG("Invoking TvInit()");
    ret = TvInit();
    UT_ASSERT_EQUAL_FATAL(ret, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking SetCMSState(true)");
    ret = SetCMSState(true);
    UT_ASSERT_EQUAL_FATAL(ret, tvERROR_NONE);

    for (color = tvDataColor_NONE; color < tvDataColor_MAX; color++)
    {
        lumaSet = 15; // A valid luma value in the range of 0 to 30

        UT_LOG_DEBUG("Invoking SetCurrentComponentLuma(%d, %d)", color, lumaSet);
        ret = SetCurrentComponentLuma(color, lumaSet);
        UT_LOG_DEBUG("Return status: %d", ret);
        if (ret != tvERROR_NONE)
        {
            UT_LOG_ERROR("SetCurrentComponentLuma failed for color %d", color);
            continue;
        }
        UT_ASSERT_EQUAL(ret, tvERROR_NONE);

        UT_LOG_DEBUG("Invoking GetCurrentComponentLuma(%d)", color);
        ret = GetCurrentComponentLuma(color, &luma);
        UT_LOG_DEBUG("Return status: %d, Luma: %d", ret, luma);
        if (ret != tvERROR_NONE)
        {
            UT_LOG_ERROR("GetCurrentComponentLuma failed for color %d", color);
            continue;
        }
        UT_ASSERT_EQUAL(ret, tvERROR_NONE);
        UT_ASSERT_EQUAL(luma, lumaSet);
    }

    UT_LOG_DEBUG("Invoking TvTerm()");
    ret = TvTerm();
    UT_ASSERT_EQUAL_FATAL(ret, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test aims to verify the functionality of setting and getting the CMS state in the TV settings.
*
* In this test, the CMS state is first set to true and then retrieved to verify if the set operation was successful. The same is then repeated with the CMS state set to false. The test ensures that the SetCMSState and GetCMSState functions are working as expected.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 043@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetCMSState(void)
{
    gTestID = 43;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    bool enableCMSState;

    UT_LOG_DEBUG("Invoking TvInit()");
    status = TvInit();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking SetCMSState() with enableCMSState set to true");
    status = SetCMSState(true);
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking GetCMSState()");
    status = GetCMSState(&enableCMSState);
    UT_LOG_DEBUG("Returned enableCMSState: %d, Return status: %d", enableCMSState, status);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    UT_ASSERT_EQUAL(enableCMSState, true);

    UT_LOG_DEBUG("Invoking SetCMSState() with enableCMSState set to false");
    status = SetCMSState(false);
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking GetCMSState()");
    status = GetCMSState(&enableCMSState);
    UT_LOG_DEBUG("Returned enableCMSState: %d, Return status: %d", enableCMSState, status);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    UT_ASSERT_EQUAL(enableCMSState, false);

    UT_LOG_DEBUG("Invoking TvTerm()");
    status = TvTerm();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test aims to verify the GetPQParameters function in the L2 TV Settings API
*
* This test case checks the correctness of the GetPQParameters function by setting various parameters using different functions and then retrieving them using GetPQParameters. The retrieved values are then compared with the expected values to verify the correctness of the function.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 044@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_TestGetPQParameters(void)
{
    gTestID = 44;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    int value;
    tvVideoSrcType_t videoSrcType;
    tvVideoFormatType_t videoFormatType;
    tvPQParameterIndex_t pqParamIndex;
    int pq_mode = 0;

    UT_LOG_DEBUG("Invoking TvInit()");
    status = TvInit();
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    for(videoSrcType = VIDEO_SOURCE_ANALOGUE; videoSrcType < VIDEO_SOURCE_MAX; videoSrcType++)
    {
        for(videoFormatType = VIDEO_FORMAT_NONE; videoFormatType < VIDEO_FORMAT_MAX; videoFormatType++)
        {
            for(pq_mode = 0; pq_mode < PQ_MODE_MAX; pq_mode++)
            {
                UT_LOG_DEBUG("Invoking SaveBrightness(), SaveContrast(), SaveSaturation(), SaveHue() with videoSrcType=%d, pq_mode=%d, videoFormatType=%d, value=50", videoSrcType, pq_mode, videoFormatType);
                status = SaveBrightness(videoSrcType, pq_mode, videoFormatType, 50);
                UT_ASSERT_EQUAL(status, tvERROR_NONE);
                status = SaveContrast(videoSrcType, pq_mode, videoFormatType, 50);
                UT_ASSERT_EQUAL(status, tvERROR_NONE);
                status = SaveSaturation(videoSrcType, pq_mode, videoFormatType, 50);
                UT_ASSERT_EQUAL(status, tvERROR_NONE);
                status = SaveHue(videoSrcType, pq_mode, videoFormatType, 50);
                UT_ASSERT_EQUAL(status, tvERROR_NONE);

                UT_LOG_DEBUG("Invoking SetCurrentComponentSaturation() with blSaturationColor=%d, saturation=50", videoSrcType);
                status = SetCurrentComponentSaturation(videoSrcType, 50);
                UT_ASSERT_EQUAL(status, tvERROR_NONE);

                UT_LOG_DEBUG("Invoking SaveDvTmaxValue() with state=LDIM_STATE_NONBOOST, value=500");
                status = SaveDvTmaxValue(LDIM_STATE_NONBOOST, 500);
                UT_ASSERT_EQUAL(status, tvERROR_NONE);

                UT_LOG_DEBUG("Invoking SaveLowLatencyState() with videoSrcType=%d, pq_mode=%d, videoFormatType=%d, value=1", videoSrcType, pq_mode, videoFormatType);
                status = SaveLowLatencyState(videoSrcType, pq_mode, videoFormatType, 1);
                UT_ASSERT_EQUAL(status, tvERROR_NONE);

                for(pqParamIndex = PQ_PARAM_BRIGHTNESS; pqParamIndex < PQ_PARAM_MAX; pqParamIndex++)
                {
                    UT_LOG_DEBUG("Invoking GetPQParams() with pqIndex=%d, videoSrcType=%d, videoFormatType=%d, pqParamIndex=%d", pq_mode, videoSrcType, videoFormatType, pqParamIndex);
                    status = GetPQParams(pq_mode, videoSrcType, videoFormatType, pqParamIndex, &value);
                    UT_ASSERT_EQUAL(status, tvERROR_NONE);
                    if(pqParamIndex == PQ_PARAM_LOWLATENCY_STATE)
                    {
                        UT_ASSERT_EQUAL(value, 1);
                    }
                    else if(pqParamIndex == PQ_PARAM_DOLBY_MODE)
                    {
                        UT_ASSERT_EQUAL(value, 500);
                    }
                    else
                    {
                        UT_ASSERT_EQUAL(value, 50);
                    }
                }
            }
        }
    }

    UT_LOG_DEBUG("Invoking TvTerm()");
    status = TvTerm();
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test for getting TV Gamma Target
*
* This test case checks if the GetTVGammaTarget function is able to retrieve the correct gamma target values for different color temperatures. It ensures that the returned x and y values are within the expected range (0 to 1.0) for all color temperatures.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 045@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_GetTVGammaTarget(void)
{
    gTestID = 45;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    double x, y;
    tvColorTemp_t colorTemp[] = {tvColorTemp_STANDARD, tvColorTemp_WARM, tvColorTemp_COLD, tvColorTemp_USER, tvColorTemp_BOOST_STANDARD, tvColorTemp_BOOST_WARM, tvColorTemp_BOOST_COLD, tvColorTemp_BOOST_USER, tvColorTemp_SUPERCOLD, tvColorTemp_BOOST_SUPERCOLD};

    UT_LOG_DEBUG("Invoking TvInit()");
    status = TvInit();
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    for(int i = 0; i < tvColorTemp_MAX; i++)
    {
        UT_LOG_DEBUG("Invoking GetTVGammaTarget() with colorTemp = %d", colorTemp[i]);
        GetTVGammaTarget(colorTemp[i], &x, &y);
        UT_LOG_DEBUG("Returned x = %f, y = %f", x, y);
        CU_ASSERT(x >= 0 && x <= 1.0);
        CU_ASSERT(y >= 0 && y <= 1.0);
    }

    UT_LOG_DEBUG("Invoking TvTerm()");
    status = TvTerm();
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the Set and Get RGB Pattern functionality
*
* This test initializes the TV settings, sets the RGB pattern, gets the RGB pattern, and verifies that the set and get values match. It also checks the return status of each API call and logs the results. If any API call fails, it logs the error and terminates the TV settings.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 046@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetRGBPattern(void)
{
    gTestID = 46;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    int r_set = 100, g_set = 150, b_set = 200;
    int r_get, g_get, b_get;

    UT_LOG_DEBUG("Invoking TvInit()");
    status = TvInit();
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE) {
        UT_LOG_ERROR("TvInit failed with status: %d", status);
        return;
    }

    UT_LOG_DEBUG("Invoking SetRGBPattern() with r=%d, g=%d, b=%d", r_set, g_set, b_set);
    status = SetRGBPattern(r_set, g_set, b_set);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE) {
        UT_LOG_ERROR("SetRGBPattern failed with status: %d", status);
        TvTerm();
        return;
    }

    UT_LOG_DEBUG("Invoking GetRGBPattern()");
    status = GetRGBPattern(&r_get, &g_get, &b_get);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE) {
        UT_LOG_ERROR("GetRGBPattern failed with status: %d", status);
        TvTerm();
        return;
    }
    UT_LOG_DEBUG("GetRGBPattern returned r=%d, g=%d, b=%d", r_get, g_get, b_get);

    UT_ASSERT_EQUAL(r_get, r_set);
    UT_ASSERT_EQUAL(g_get, g_set);
    UT_ASSERT_EQUAL(b_get, b_set);

    UT_LOG_DEBUG("Invoking TvTerm()");
    status = TvTerm();
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);
    if (status != tvERROR_NONE) {
        UT_LOG_ERROR("TvTerm failed with status: %d", status);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the functionality of Set and Get Gray Pattern in TV settings
*
* This test case validates the Set and Get Gray Pattern functionality of the TV settings. It checks if the set value is correctly retrieved by the Get function. This is important to ensure the correct setting of Gray Pattern in the TV settings.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 047@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_SetAndGetGrayPattern(void)
{
    gTestID = 47;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t status;
    int YUVValue = 100;
    int get_YUVValue;

    UT_LOG_DEBUG("Invoking TvInit()");
    status = TvInit();
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking SetGammaPatternMode(true)");
    status = SetGammaPatternMode(true);
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking SetGrayPattern(%d)", YUVValue);
    status = SetGrayPattern(YUVValue);
    UT_LOG_DEBUG("Return status: %d", status);
    UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking GetGrayPattern()");
    status = GetGrayPattern(&get_YUVValue);
    UT_LOG_DEBUG("Return status: %d, YUVValue: %d", status, get_YUVValue);
    UT_ASSERT_EQUAL(status, tvERROR_NONE);
    UT_ASSERT_EQUAL(YUVValue, get_YUVValue);

    if (status != tvERROR_NONE || YUVValue != get_YUVValue)
    {
        UT_LOG_DEBUG("Invoking TvTerm()");
        status = TvTerm();
        UT_LOG_DEBUG("Return status: %d", status);
        UT_ASSERT_EQUAL_FATAL(status, tvERROR_NONE);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the functionality of RetrieveOpenCircuitStatus API
*
* This test case verifies the functionality of the RetrieveOpenCircuitStatus API. It checks if the API is able to correctly retrieve the status of the open circuit in the TV settings. The test case invokes the TvInit() function to initialize the TV settings, then it calls the GetOpenCircuitStatus() function to retrieve the status of the open circuit. The test case asserts that the return values of these functions are as expected. If the status of the open circuit is greater than or equal to 1, it logs that a LED fault is detected. If the status is 0, it logs that no LED fault is detected. If the status is less than 0, it logs an error message. Finally, the test case calls the TvTerm() function to terminate the TV settings and asserts that its return value is as expected.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 048@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_RetrieveOpenCircuitStatus(void)
{
    gTestID = 48;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t ret;
    int status;

    UT_LOG_DEBUG("Invoking TvInit()");
    ret = TvInit();
    UT_ASSERT_EQUAL_FATAL(ret, tvERROR_NONE);
    UT_LOG_DEBUG("Return status: %d", ret);

    UT_LOG_DEBUG("Invoking GetOpenCircuitStatus() with valid pointer");
    ret = GetOpenCircuitStatus(&status);
    UT_LOG_DEBUG("Open circuit status: %d, Return status: %d", status, ret);

    if (status >= 1)
    {
        UT_LOG_INFO("LED fault detected");
    }
    else if (status == 0)
    {
        UT_LOG_INFO("No LED fault detected");
    }
    else
    {
        UT_LOG_ERROR("Invalid status value");
    }

    UT_ASSERT_EQUAL(ret, tvERROR_NONE);

    UT_LOG_DEBUG("Invoking TvTerm()");
    ret = TvTerm();
    UT_ASSERT_EQUAL_FATAL(ret, tvERROR_NONE);
    UT_LOG_DEBUG("Return status: %d", ret);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test checks the functionality of enabling and getting the dynamic contrast in TV settings
*
* In this test, the EnableDynamicContrast() and GetDynamicContrast() functions are tested to ensure they work as expected. The test first enables the dynamic contrast and checks if it is enabled. Then it disables the dynamic contrast and checks if it is disabled. This is done to ensure that the TV settings can correctly enable and disable the dynamic contrast and reflect the changes correctly.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 049@n
*
* **Test Procedure:**
* Refer to UT specification documentation [tvSettings_L2_Low-Level_TestSpecification.md](../../docs/pages/tvSettings_L2_Low-Level_TestSpecification.md)
*/

void test_l2_tvSettings_EnableAndGetDynamicContrast(void)
{
    gTestID = 49;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    tvError_t ret;
    char isDynamicContrastEnabled[10];

    UT_LOG_DEBUG("Invoking TvInit()");
    ret = TvInit();
    UT_ASSERT_EQUAL_FATAL(ret, tvERROR_NONE);
    UT_LOG_DEBUG("Return status: %d", ret);

    UT_LOG_DEBUG("Invoking EnableDynamicContrast() with true");
    ret = EnableDynamicContrast(true);
    UT_ASSERT_EQUAL_FATAL(ret, tvERROR_NONE);
    UT_LOG_DEBUG("Return status: %d", ret);

    UT_LOG_DEBUG("Invoking GetDynamicContrast()");
    ret = GetDynamicContrast(isDynamicContrastEnabled);
    UT_ASSERT_EQUAL_FATAL(ret, tvERROR_NONE);
    UT_ASSERT_STRING_EQUAL_FATAL(isDynamicContrastEnabled, "enabled");
    UT_LOG_DEBUG("Return status: %d, Dynamic Contrast: %s", ret, isDynamicContrastEnabled);

    UT_LOG_DEBUG("Invoking EnableDynamicContrast() with false");
    ret = EnableDynamicContrast(false);
    UT_ASSERT_EQUAL_FATAL(ret, tvERROR_NONE);
    UT_LOG_DEBUG("Return status: %d", ret);

    UT_LOG_DEBUG("Invoking GetDynamicContrast()");
    ret = GetDynamicContrast(isDynamicContrastEnabled);
    UT_ASSERT_EQUAL_FATAL(ret, tvERROR_NONE);
    UT_ASSERT_STRING_EQUAL_FATAL(isDynamicContrastEnabled, "disabled");
    UT_LOG_DEBUG("Return status: %d, Dynamic Contrast: %s", ret, isDynamicContrastEnabled);

    UT_LOG_DEBUG("Invoking TvTerm()");
    ret = TvTerm();
    UT_ASSERT_EQUAL_FATAL(ret, tvERROR_NONE);
    UT_LOG_DEBUG("Return status: %d", ret);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

static UT_test_suite_t * pSuite = NULL;

/**
 * @brief Register the main tests for this module
 *
 * @return int - 0 on success, otherwise failure
 */

int test_tvSettings_l2_register(void)
{
    // Create the test suite
    pSuite = UT_add_suite("[L2 tvSettings]", NULL, NULL);
    if (pSuite == NULL)
    {
        return -1;
    }
    // List of test function names and strings

    UT_add_test( pSuite, "l2_tvSettings_GetSupportedVideoFormats", test_l2_tvSettings_GetSupportedVideoFormats);
    UT_add_test( pSuite, "l2_tvSettings_GetCurrentVideoFormat_NoVideoPlayback", test_l2_tvSettings_GetCurrentVideoFormat_NoVideoPlayback);
    UT_add_test( pSuite, "l2_tvSettings_VerifyCurrentVideoResolution", test_l2_tvSettings_VerifyCurrentVideoResolution);
    UT_add_test( pSuite, "l2_tvSettings_VerifyFrameRateWhenStopped", test_l2_tvSettings_VerifyFrameRateWhenStopped);
    UT_add_test( pSuite, "l2_tvSettings_GetTVSupportedVideoSources", test_l2_tvSettings_GetTVSupportedVideoSources);
    UT_add_test( pSuite, "l2_tvSettings_VerifyNoVideoSource", test_l2_tvSettings_VerifyNoVideoSource);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetBacklight", test_l2_tvSettings_SetAndGetBacklight);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetBacklightFade", test_l2_tvSettings_SetAndGetBacklightFade);
    UT_add_test( pSuite, "l2_tvSettings_GetSupportedBacklightModes", test_l2_tvSettings_GetSupportedBacklightModes);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetBacklightMode", test_l2_tvSettings_SetAndGetBacklightMode);
    UT_add_test( pSuite, "l2_tvSettings_GetSupportedDimmingModes", test_l2_tvSettings_GetSupportedDimmingModes);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetDimmingMode", test_l2_tvSettings_SetAndGetDimmingMode);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetLocalDimmingLevel", test_l2_tvSettings_SetAndGetLocalDimmingLevel);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetBrightness", test_l2_tvSettings_SetAndGetBrightness);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetContrast", test_l2_tvSettings_SetAndGetContrast);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetSharpness", test_l2_tvSettings_SetAndGetSharpness);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetSaturation", test_l2_tvSettings_SetAndGetSaturation);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetHue", test_l2_tvSettings_SetAndGetHue);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetColorTemperature", test_l2_tvSettings_SetAndGetColorTemperature);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetAspectRatio", test_l2_tvSettings_SetAndGetAspectRatio);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetLowLatencyState", test_l2_tvSettings_SetAndGetLowLatencyState);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetDynamicContrast", test_l2_tvSettings_SetAndGetDynamicContrast);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetDynamicGamma", test_l2_tvSettings_SetAndGetDynamicGamma);
    UT_add_test( pSuite, "l2_tvSettings_GetSupportedDolbyVisionModes", test_l2_tvSettings_GetSupportedDolbyVisionModes);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetDolbyVisionMode", test_l2_tvSettings_SetAndGetDolbyVisionMode);
    UT_add_test( pSuite, "l2_tvSettings_GetTVSupportedPictureModes", test_l2_tvSettings_GetTVSupportedPictureModes);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetPictureMode", test_l2_tvSettings_SetAndGetPictureMode);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetColorTempRgain", test_l2_tvSettings_SetAndGetColorTempRgain);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetColorTempGgain", test_l2_tvSettings_SetAndGetColorTempGgain);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetColorTempBgain", test_l2_tvSettings_SetAndGetColorTempBgain);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetColorTemp_R_post_offset_onSource", test_l2_tvSettings_SetAndGetColorTemp_R_post_offset_onSource);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetColorTempGPostOffset", test_l2_tvSettings_SetAndGetColorTempGPostOffset);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetColorTempBPostOffset", test_l2_tvSettings_SetAndGetColorTempBPostOffset);
    UT_add_test( pSuite, "l2_tvSettings_DisableAndVerifyWBCalibrationMode", test_l2_tvSettings_DisableAndVerifyWBCalibrationMode);
    UT_add_test( pSuite, "l2_tvSettings_EnableAndVerifyWBCalibrationMode", test_l2_tvSettings_EnableAndVerifyWBCalibrationMode);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetGammaTable", test_l2_tvSettings_SetAndGetGammaTable);
    UT_add_test( pSuite, "l2_tvSettings_GetDefaultGammaTable", test_l2_tvSettings_GetDefaultGammaTable);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetDvTmaxValue", test_l2_tvSettings_SetAndGetDvTmaxValue);
    UT_add_test( pSuite, "l2_tvSettings_GetSupportedComponentColor", test_l2_tvSettings_GetSupportedComponentColor);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetComponentSaturation", test_l2_tvSettings_SetAndGetComponentSaturation);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetComponentHue", test_l2_tvSettings_SetAndGetComponentHue);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetComponentLuma", test_l2_tvSettings_SetAndGetComponentLuma);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetCMSState", test_l2_tvSettings_SetAndGetCMSState);
    UT_add_test( pSuite, "l2_tvSettings_TestGetPQParameters", test_l2_tvSettings_TestGetPQParameters);
    UT_add_test( pSuite, "l2_tvSettings_GetTVGammaTarget", test_l2_tvSettings_GetTVGammaTarget);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetRGBPattern", test_l2_tvSettings_SetAndGetRGBPattern);
    UT_add_test( pSuite, "l2_tvSettings_SetAndGetGrayPattern", test_l2_tvSettings_SetAndGetGrayPattern);
    UT_add_test( pSuite, "l2_tvSettings_RetrieveOpenCircuitStatus", test_l2_tvSettings_RetrieveOpenCircuitStatus);
    UT_add_test( pSuite, "l2_tvSettings_EnableAndGetDynamicContrast", test_l2_tvSettings_EnableAndGetDynamicContrast);

    return 0;
}