/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:
*
* Copyright 2022 Sky UK
* Copyright 2022 Amlogic
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
 * @file tvSettings.c
 * @brief This file contains implementation of TV Settings Hal module
 **/

/**
- * @defgroup TVSettings
- * @{
- * @defgroup hal
- * @{
- **/

#include <tv_settings_hal.h>
#if DELETE
struct TvClientWrapper_t *tvclient = NULL;
static pthread_mutex_t tvEvent_mutex = PTHREAD_MUTEX_INITIALIZER;
PqClient  * amlPqClient = NULL; //TvClient Handle
TvClient *clienttv = NULL;

static int rfcBoost = 0 ;
//Persist settings for single session
//as AMLogic GET APIs always return default value
// static int brightnessLevel = 50;
// static int contrastLevel = 50;
// static int sharpnessLevel = 50;
// static int saturationLevel = 50;
static int uAmbientBacklightLevel = 50;
// static int hueLevel = 50;
static tvPictureMode_t picModeValue = 0;
static tvDisplayMode_t aspectRatioValue = tvDisplayMode_AUTO;
static tvBacklightMode_t backlightMode = tvBacklightMode_MANUAL;
extern GMainLoop *autoBL_Gloop;
static guint update_src_format= 0;
static tvVideoHDRFormat_t m_currentVideoFormat = tvVideoHDRFormat_NONE;
static tvVideoResolution_t currentResolution = tvVideoResolution_NONE;
static tvVideoFrameRate_t currentFrameRate = tvVideoFrameRate_NONE;
static tvVideoFormatCallbackData m_videoFormatChangeCBData = {NULL,NULL};
static tvVideoResolutionCallbackData m_videoResolutionChangeCBData = {NULL,NULL};
static tvVideoFrameRateCallbackData m_videoFrameRateChangeCBData = {NULL,NULL};

static pic_modes_t pic_modes[PIC_MODES_SUPPORTED_MAX] = {0};
static unsigned short numberModesSupported;

static pic_modes_t dv_modes[DV_MODES_SUPPORTED_MAX] = {0};
static unsigned short numberDVModesSupported;
static pic_modes_t hlg_modes[DV_MODES_SUPPORTED_MAX] = {0};
static unsigned short numberHLGModesSupported;
static pic_modes_t hdr10_modes[DV_MODES_SUPPORTED_MAX] = {0};
static unsigned short numberHDR10ModesSupported;
static char supportedDimmingModes[DIMMING_MODE_MAX*DIMMING_MODE_NAME_SIZE] = {0};
static unsigned short numberDimmingModes;

static tvPictureMode_t DVModeValue = 0;

static char panelId[20] = {0};

const char *colorTempString[] = {"STANDARD", "WARM","COLD", "USER"};
const char *sourceOffsetString[] = {"HDMI", "TV","AV"};

const char* dolbyVisionMode[] = {
    [tvDolbyMode_Dark] = "dark",
    [tvDolbyMode_Bright] = "bright"
};

static tvDataColor_t wbValues[16];
mfrSerializedType_t getParamType(int i);
static tvDataColor_t custWBValueOnInit;

#ifdef SUPPORT_WB_CONTROL_CUSTOM_ONLY
static int colorTemperatureMax = tvColorTemp_USER;
#define SET_LDIM "/sys/class/aml_ldim/func_en"
#else
static int colorTemperatureMax = tvColorTemp_COLD;
#endif


static char currentDimmingMode[DIMMING_MODE_NAME_SIZE]={0};
static tvPictureMode_t getPicModeEnum(const char * pictureMode);
static void *SetAspectRatio_thread(void *Mode);
int sourceIdFromOffset(colortemperature_source_offset_t offset);
void tvCopySD3DatatoCridataEx(void);
tvError_t ReadCustWBvaluesFromDriverOnInit(void);
int getRgbType(char *color, char * ctrl);

/* backlight area(51)*/
static tvBacklightInfo_t allBacklightInfo = {0};
static int backlightFactorRangeMid = 0;
static int backlightFactor = 255;

static gboolean updateSrcFormatTime(gpointer data)
{
    int format = 0;
    FILE *fptr = NULL ;

    tvVideoHDRFormat_t currentFormat = tvVideoHDRFormat_NONE;
    if ((fptr = fopen(SRC_FORMAT_FILE_PATH, "r")) != NULL) {
        fscanf(fptr, "%d", &format);
        fclose(fptr);
        switch(format)
        {
        case 1:
            currentFormat = tvVideoHDRFormat_HDR10; break;
        case 2:
            currentFormat = tvVideoHDRFormat_HDR10PLUS; break;
        case 3:
            currentFormat = tvVideoHDRFormat_DV; break;
        case 5:
            currentFormat = tvVideoHDRFormat_HLG; break;
        case 6:
            currentFormat = tvVideoHDRFormat_SDR; break;
        default:
            break;
        }
        if(currentFormat != m_currentVideoFormat)
        {
           m_currentVideoFormat = currentFormat;
           if(m_videoFormatChangeCBData.cb) m_videoFormatChangeCBData.cb(m_currentVideoFormat,m_videoFormatChangeCBData.userdata);
           printf("TV_HAL: src format changed to :%u \n ", m_currentVideoFormat	);
           if(backlightMode ==tvBacklightMode_AMBIENT)
               TVUpdateRawBacklight(backlightFactor,backlightFactorRangeMid);
        }
    }
    else
        printf("TV_HAL: Error! opening SRC_FORMAT_FILE file");

    return TRUE;
}

/**
 * @fn tvwriteCRIdata()
 * @brief This function is used to write calibartion dtata to cri_data file
 *  *  * API from TvClient
 *
 * @param[in] tvColorTemp_t the color temperature to be inited
 * @param[in] wbDefaultVal The data to write in the cri_data file
 *
 * @return : none
 *
 **/
tvError_t tvwriteCRIdata(tvColorTemp_t colorTemp, tvDataColor_t wbDefaultVal) {
	tvError_t ret = tvERROR_NONE;
        if ( (tvERROR_NONE != amlPqClient->FactorySaveWhiteBalanceBlueGain(HDMI_DEFAULT, INT_DUMMY, INT_DUMMY, colorTemp,wbDefaultVal.b_gain)) || \
       (tvERROR_NONE != amlPqClient->FactorySaveWhiteBalanceRedGain(HDMI_DEFAULT, INT_DUMMY, INT_DUMMY, colorTemp, wbDefaultVal.r_gain)) || \
           (tvERROR_NONE != amlPqClient->FactorySaveWhiteBalanceGreenGain(HDMI_DEFAULT, INT_DUMMY, INT_DUMMY, colorTemp, wbDefaultVal.g_gain)) || \
           (tvERROR_NONE != amlPqClient->FactorySaveWhiteBalanceGreenPostOffset(HDMI_DEFAULT, INT_DUMMY, INT_DUMMY, colorTemp, wbDefaultVal.g_offset)) || \
           (tvERROR_NONE != amlPqClient->FactorySaveWhiteBalanceRedPostOffset(HDMI_DEFAULT, INT_DUMMY, INT_DUMMY, colorTemp, wbDefaultVal.r_offset)) || \
           (tvERROR_NONE != amlPqClient->FactorySaveWhiteBalanceBluePostOffset(HDMI_DEFAULT, INT_DUMMY, INT_DUMMY, colorTemp, wbDefaultVal.b_offset)) )
           {
                   printf("TV_HAL:Failed to set ColorTemp from SD3 \n");
                   ret = tvERROR_GENERAL;
           }
           return ret;
}
/**
 * @fn tvCopySD3DatatoCridata()
 * @brief This function is used to copy the pq calibartion values
 * from Serial data3 to cri_data file
 * API from TvClient
 *
 * @param[in] none
 *
 * @return : none
 *
 **/
void tvCopySD3DatatoCridata() {
    tvDataColor_t wbSD3Val;
    tvDataColor_t wbCRIVal;
    bool defaultflag = true;
    tvColorTemp_t colorTemp;
    IARM_Bus_MFRLib_GetSerializedData_Param_t param;
    IARM_Result_t iarm_ret = IARM_RESULT_IPCCORE_FAIL;
    //Standard, warm and cold
    for(int i = 0; i < 3; i++)
    {
            printf("tvCopySD3DatatoCridata  Enter \n");
            memset((void*)&wbSD3Val, '\0', sizeof(tvDataColor_t));
            memset((void*)&wbCRIVal, '\0', sizeof(tvDataColor_t));
            colorTemp = (tvColorTemp_t)i;
	    //Reading CRI data values from /opt/panel/cri_data
            wbCRIVal.r_gain = amlPqClient->FactoryGetWhiteBalanceRedGain(HDMI_DEFAULT, INT_DUMMY, INT_DUMMY, colorTemp);
            usleep(2000);
            wbCRIVal.g_gain = amlPqClient->FactoryGetWhiteBalanceGreenGain(HDMI_DEFAULT, INT_DUMMY, INT_DUMMY, colorTemp);
            wbCRIVal.b_gain = amlPqClient->FactoryGetWhiteBalanceBlueGain(HDMI_DEFAULT, INT_DUMMY, INT_DUMMY, colorTemp);
            usleep(2000);
            wbCRIVal.r_offset = amlPqClient->FactoryGetWhiteBalanceRedPostOffset(HDMI_DEFAULT, INT_DUMMY, INT_DUMMY, colorTemp);
            wbCRIVal.g_offset = amlPqClient->FactoryGetWhiteBalanceGreenPostOffset(HDMI_DEFAULT, INT_DUMMY, INT_DUMMY, colorTemp);
            usleep(2000);
            wbCRIVal.b_offset = amlPqClient->FactoryGetWhiteBalanceBluePostOffset(HDMI_DEFAULT, INT_DUMMY, INT_DUMMY, colorTemp);
            tvDataColor_t wbDefaultVal;
            memset((void*)&wbDefaultVal, '\0', sizeof(tvDataColor_t));
            memset(&param, 0, sizeof(param));

	    //standard - 0 , warm -1 and cold -2
	    if(i == 0){
                    param.type = mfrSERIALIZED_TYPE_SKY_PANEL_HDMI_WB_DATA_NORMAL;
            }else if(i == 1) {
                    param.type = mfrSERIALIZED_TYPE_SKY_PANEL_HDMI_WB_DATA_WARM;
            }else if(i == 2) {
                    param.type = mfrSERIALIZED_TYPE_SKY_PANEL_HDMI_WB_DATA_COLD;
            }

	    //Reading SD3 values through mfr layer
            iarm_ret = IARM_Bus_Call(IARM_BUS_MFRLIB_NAME, IARM_BUS_MFRLIB_API_GetSerializedData, &param, sizeof(param));
            if(iarm_ret == IARM_RESULT_SUCCESS)
            {
                memcpy((void*)&wbDefaultVal, param.buffer, sizeof(tvDataColor_t));
                printf("red gain = %d, green = %d blue =%d\n", wbDefaultVal.r_gain, wbDefaultVal.g_gain, wbDefaultVal.b_gain);
                printf("red off= %d, green off = %d blue off=%d\n", wbDefaultVal.r_offset, wbDefaultVal.g_offset, wbDefaultVal.b_offset);
                    //default values are present in the SD3 means skip the update
                if( param.type == mfrSERIALIZED_TYPE_SKY_PANEL_HDMI_WB_DATA_NORMAL){
                                if((wbDefaultVal.r_gain == 1024) && (wbDefaultVal.g_gain == 1024) && (wbDefaultVal.b_gain == 1024)){
                                    defaultflag = false;
                                }
                }else if(param.type == mfrSERIALIZED_TYPE_SKY_PANEL_HDMI_WB_DATA_WARM){
                                if((wbDefaultVal.r_gain == 1024) && (wbDefaultVal.g_gain == 960) && (wbDefaultVal.b_gain == 920)){
                                    defaultflag = false;
                                }

                }else if(param.type == mfrSERIALIZED_TYPE_SKY_PANEL_HDMI_WB_DATA_COLD){
                                if((wbDefaultVal.r_gain == 920) && (wbDefaultVal.g_gain == 960) && (wbDefaultVal.b_gain == 1024)){
                                    defaultflag = false;
                                }
                }

      	    } else {
		            defaultflag = false;
            }
	    //comparing SD3 data and Cri data, if it not match update for SD3 to /opt/panel/cri_data
	    if(defaultflag){
                    if( (wbCRIVal.r_gain != wbDefaultVal.r_gain) || (wbCRIVal.g_gain != wbDefaultVal.g_gain) || \
                                    (wbCRIVal.b_gain != wbDefaultVal.b_gain ) || (wbCRIVal.r_offset != wbDefaultVal.r_offset) ||\
                                    (wbCRIVal.g_offset != wbDefaultVal.g_offset) || (wbCRIVal.b_offset != wbDefaultVal.b_offset) )
                    {
                            printf("SD3 and CRI not are matching - %d\n", i);
                            tvwriteCRIdata(colorTemp , wbDefaultVal);
                    }else{
                            printf("SD3 and CRI are matching - %d\n", i);
                    }
            }else{

            if(((wbCRIVal.r_gain == 0) || (wbCRIVal.r_gain == 1024)) && ((wbCRIVal.g_gain == 0)|| \
                                            (wbCRIVal.g_gain == 1024) ) &&( (wbCRIVal.b_gain == 0)|| \
                            (wbCRIVal.b_gain == 1024) ))
            {
                    printf("CRI data has zero value resync now - %d\n", i);
                    tvwriteCRIdata(colorTemp , wbDefaultVal);
            }else{

                    printf("SD3 values are default  , no need to update cri_data\n");
            }
        }

    }
}

static void* tvCopySD3DatatoCridata_thread(void *arg){

    int isConnected =  0;
    IARM_Result_t iarm_ret = IARM_RESULT_IPCCORE_FAIL;

    printf("TV_HAL: Sync ENTER %s()\n", __FUNCTION__);
    int retryCount = 0;
    do{
        iarm_ret = IARM_Bus_IsConnected(IARM_BUS_MFRLIB_NAME, &isConnected);
        if(IARM_RESULT_SUCCESS != iarm_ret){
//            printf("TV_HAL: (IARM not SUCCESS) Waiting for registration of %s iarm_ret[%d] isConnected[%d]\n", IARM_BUS_MFRLIB_NAME, iarm_ret, isConnected);
            usleep(1000000);
            retryCount++;

        }else if (!isConnected){
//            printf("TV_HAL: Waiting for registration of %s iarm_ret[%d] isConnected[%d]\n", IARM_BUS_MFRLIB_NAME, iarm_ret, isConnected);
            usleep(1000000);
            retryCount++;
        }else {
//            printf("TV_HAL: Registration of %s OK iarm_ret[%d] isConnected[%d]\n", IARM_BUS_MFRLIB_NAME, iarm_ret, isConnected);
       }

    }while ((!isConnected) && (retryCount < MAX_RETRY));

    if (retryCount < MAX_RETRY) {
        printf("TV_HAL: Service Init done.. going to connect\n");
        tvCopySD3DatatoCridataEx();
    } else {
        printf("TV_HAL: Sync EXIT due to MAX Retry %s()\n", __FUNCTION__);
    }

// #ifdef SUPPORT_WB_CONTROL_CUSTOM_ONLY
//     tvCustomColorTempInit(); //Sync Custom mode data
// #endif

    printf("TV_HAL: Sync EXIT %s()\n", __FUNCTION__);

    return NULL;

}

tvError_t tvSD3toCriSyncInit()
{
    tvError_t ret = tvERROR_NONE;
    pthread_t tvCopySD3DatatoCridata_threadId;
    printf("TV_HAL:(%s): Starting SD3 <-> cri_data sync thread\n",__func__);
    int err = pthread_create(&tvCopySD3DatatoCridata_threadId, NULL, tvCopySD3DatatoCridata_thread, NULL);
    if(err != 0){
        printf("%s:%d : tvCopySD3DatatoCridata_thread creation failed!!! \n", __FUNCTION__,__LINE__);
        ret = tvERROR_GENERAL;
    }
    else {
        err = pthread_detach(tvCopySD3DatatoCridata_threadId);
        if(err != 0) {
            printf("%s:%d : tvCopySD3DatatoCridata_thread detach failed!!! \n", __FUNCTION__,__LINE__);
        }
    }
    return ret;
}

static void TvHalEventCallback(event_type_t eventType, void *eventData)
{
    printf("%s:%d eventType: %d.\n", __FUNCTION__,__LINE__, eventType);
    switch (eventType)
    {
        case TV_EVENT_TYPE_SIGLE_DETECT:
        {
            SignalDetectCallback_t *signalDetectEvent = ( SignalDetectCallback_t *)(eventData);
            printf("%s:%d source: %d, signalFmt: %d, transFmt: %d, status: %d, isDVI: %d.\n", __FUNCTION__,__LINE__,
                            signalDetectEvent->SourceInput,
                            signalDetectEvent->SignalFmt,
                            signalDetectEvent->TransFmt,
                            signalDetectEvent->SignalStatus,
                            signalDetectEvent->isDviSignal);
            if(signalDetectEvent->SourceInput == SOURCE_HDMI1 || signalDetectEvent->SourceInput == SOURCE_HDMI2 || signalDetectEvent->SourceInput == SOURCE_HDMI3){
		pthread_mutex_lock(&tvEvent_mutex);

                tvVideoResolution_t m_prevVideoResolution;
                tvVideoResolution_t m_curVideoResolution;

                m_prevVideoResolution = currentResolution;
		tvResolutionParam_t resolutionStruct;

                GetVideoResolution(&resolutionStruct);
                m_curVideoResolution = resolutionStruct.resolutionValue;

                if(m_curVideoResolution != m_prevVideoResolution)
                {
                   if(m_videoResolutionChangeCBData.cb) m_videoResolutionChangeCBData.cb(resolutionStruct, m_videoResolutionChangeCBData.userdata);
                   printf("TV_HAL: src resolution changed to :%u \n ", m_curVideoResolution);
                }

                /* Frame rate event */
                tvVideoFrameRate_t m_prevFrameRate;
                tvVideoFrameRate_t m_curFrameRate;
                m_prevFrameRate = currentFrameRate;

                GetVideoFrameRate(&m_curFrameRate);

                if(m_curFrameRate != m_prevFrameRate)
                {
                   if(m_videoFrameRateChangeCBData.cb) m_videoFrameRateChangeCBData.cb(m_curFrameRate,m_videoFrameRateChangeCBData.userdata);
                   printf("TV_HAL: src frameRate changed to :%u \n ", m_curFrameRate);
                }
		pthread_mutex_unlock(&tvEvent_mutex);
            }
        }
        default:
          break;
    }
}

/**
 * @fn tvInit()
 * @brief This function initializes the tvsettings-hal client using GetInstance
 * API from TvClient
 *
 * @param[in] none
 *
 * @return Returns on success : no error
 *                 if TVClient is null : default error
 **/

tvError_t tvInit() {

    tvError_t ret = tvERROR_NONE;
    pic_modes_t * modesAvailable = pic_modes;
    pic_modes_t * dvModes = dv_modes;
    pic_modes_t * hlgModes = hlg_modes;
    pic_modes_t * hdr10Modes = hdr10_modes;
    amlPqClient =  PqClient::GetInstance();
    clienttv = TvClient::GetInstance();
    char buffer[EXPECTED_FILE_SIZE] = {0};

   if(amlPqClient == NULL)
    {
        ret = tvERROR_GENERAL;
    }
    else
    {
        tvclient = GetInstance();
        setTvEventCallback(TvHalEventCallback);

        ret = ReadAllModeConfigfile(GENERIC_MODE_CONFIG_FILE, buffer, "picmodes");
        if(ret == tvERROR_NONE)
        {
           splitstringsandvaluefrombuffer(buffer, &modesAvailable, &numberModesSupported);

        }
        memset(buffer, '\0' , EXPECTED_FILE_SIZE);
        ret = ReadAllModeConfigfile(GENERIC_MODE_CONFIG_FILE, buffer, "dvmodes");
        if(ret == tvERROR_NONE)
        {
           splitstringsandvaluefrombuffer(buffer, &dvModes, &numberDVModesSupported);

        }
        memset(buffer, '\0' , EXPECTED_FILE_SIZE);
        ret = ReadAllModeConfigfile(GENERIC_MODE_CONFIG_FILE, buffer, "hdr10modes");
        if(ret == tvERROR_NONE)
        {
            splitstringsandvaluefrombuffer(buffer, &hdr10Modes, &numberHDR10ModesSupported);

        }
        memset(buffer, '\0' , EXPECTED_FILE_SIZE);
        ret = ReadAllModeConfigfile(GENERIC_MODE_CONFIG_FILE, buffer, "hlgmodes");
        if(ret == tvERROR_NONE)
        {
           splitstringsandvaluefrombuffer(buffer, &hlgModes, &numberHLGModesSupported);

        }
        memset(buffer, '\0' , EXPECTED_FILE_SIZE);
        ret = ReadAllModeConfigfile(GENERIC_MODE_CONFIG_FILE,  buffer, "dimmodes");
        if(ret == tvERROR_NONE)
        {
           splitstringsfrombuffer(buffer, supportedDimmingModes, &numberDimmingModes);

        }
#ifdef HAS_DIMMINGLEVEL_SUPPORT
	RFC_ParamData_t rfcParam = {0};
        WDMP_STATUS wdmpStatus;

        wdmpStatus = getRFCParameter(RFC_CALLER_ID, RFC_BOOST_COMMAND , &rfcParam);
        if(WDMP_SUCCESS == wdmpStatus)
        {
            rfcBoost=std::stoi(rfcParam.value);
            printf("Boost RFC Value read : %d\n",rfcBoost);
        }
        else
        {
            printf("Failed Reading RFC_BOOST!!! set default value 1\n");
            rfcBoost=1;
        }
#endif

#ifdef HAS_VCOM_SUPPORT
        amlPqClient->FactorySetPanelWP(0); //Set VCOM Panel WP as true to change
#endif

    }


    if(autoBacklightThreadInit() == -1) {
          printf("TV_HAL:(%s): Auto Backlight control thread init failed !!!\n",__func__);
    }

    printf("TV_HAL: Adding a sec timer \n");
    update_src_format = g_timeout_add_seconds (1 ,  updateSrcFormatTime, autoBL_Gloop);

    //Read and cache the initial custom
    //WB values in the driver
    ReadCustWBvaluesFromDriverOnInit();

    return ret;
}

//TODO: Need to implement definition
/**
 * @fn tvTerm()
 * @brief This function terminates the TVClient handle
 *
 * @param[in] none
 *
 * @return Returns no error
 **/

tvError_t tvTerm() {
    tvError_t ret = tvERROR_NONE;
    autoBacklightThreadTerm();
    return ret;
}


/**
 * @fn GetPictureMode
 * @brief This function get the picture mode from the driver
 *
 * @param[0ut]*pictureMode indicates the  pointer to enum tvPictureMode_t
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 *                 in case of default : default value
 **/

tvError_t GetTVPictureMode(char *pictureMode) {
    tvError_t ret = tvERROR_NONE;

    short int loopcount = 0;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    if(numberModesSupported)
    {   for(;loopcount<numberModesSupported;loopcount++)
        {
            if(picModeValue == pic_modes[loopcount].value)
            {
                strncpy(pictureMode,pic_modes[loopcount].name,PIC_MODE_NAME_MAX);
                // printf("picModeValue %d pictureMode %s \n",picModeValue,pictureMode);
                break;
            }
        }
    }
    else
        ret =tvERROR_GENERAL;
    return ret;
}

/**
 * @fn SetPictureMode
 * @brief This function updates the picture mode to driver
 *
 * @param[in] pictureMode indicates the mode type of picture
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 *                 on failure : default value
 **/

tvError_t SetTVPictureMode(const char * pictureMode) {
    tvError_t ret = tvERROR_NONE;
    int err = 0;
    tvPictureMode_t picmodeToSet = getPicModeEnum(pictureMode);

#ifdef HAS_DIMMINGLEVEL_SUPPORT
    SwitchEDID((int)picmodeToSet);
#endif
    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    if(picmodeToSet ==tvPictureMode_MAX)
    {
         ret = tvERROR_INVALID_PARAM;
    }
    else
        err = amlPqClient->SetPQMode(picmodeToSet,SAVE);

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    else {
        // printf("Setting up pic mode to picmodeToSet %d  \n",picmodeToSet);
        picModeValue = picmodeToSet;
    }

    return ret;
}


/**
 * @fn GetBacklight
 * @brief This function gets the back light from PQ
 *
 * @param[out] *backlight indicates the pointer variable
 *
 * @return Returns on success : no error
 *                  if amlPqClient is null : invalid state
 **/

tvError_t GetBacklight(int *backlight) {
    tvError_t ret = tvERROR_NONE;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    if(backlightMode == tvBacklightMode_MANUAL) {
        *backlight = amlPqClient->GetBacklight();
    }
    else {
        *backlight = uAmbientBacklightLevel;
    }

    return ret;
}

/**
 * @fn SetBacklight
 * @brief This function updates the back light to PQ
 *
 * @param[in] backlight indicates the back light value of TV
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 *                 if not in range 0-100 : invalid param
 **/

tvError_t SetBacklight(int backlight) {
    tvError_t ret = tvERROR_NONE;

    if((backlight < 0) || (backlight > 100)) {
        return tvERROR_INVALID_PARAM;
    }

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    if(backlightMode == tvBacklightMode_MANUAL) {
        int err = amlPqClient->SetBacklight(backlight,SAVEPARAM);
        if(err == -1) {
            ret = tvERROR_GENERAL;
        }
    }
    #if 0 
    //TODO : currently not used
    else {
        printf("TV_HAL:(%s): Auto backlight control enable... Set user backlight override: %d\n",__func__,backlight);
        
        int aml_bl =  round((245.00 * backlight) / 100) + 10;
        if(setUserAmbientBacklight(aml_bl) != 0) {
            printf("TV_HAL:(%s): Set user backlight override failed !!!\n",__func__);
        }
        else {
            uAmbientBacklightLevel = backlight;
        }
    }
    #endif
    return ret;
}

/**
 * @fn GetSupportedBacklightModes
 * @brief This function gets all supported backlight modes of TV
 *
 * @param[out] *blMode indicates the pointer to modes
 *
 * @return Returns on success : no error
 *                  if amlPqClient is null : invalid state
 **/

tvError_t GetSupportedBacklightModes(int *blModes) {
    tvError_t ret = tvERROR_NONE;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    *blModes |= tvBacklightMode_MANUAL;
    *blModes |= tvBacklightMode_AMBIENT;

    return ret;
}

/**
 * @fn GetCurrentBacklightMode
 * @brief This function gets the backlight mode
 *
 * @param[out] *blMode indicates the pointer variable
 *
 * @return Returns on success : no error
 *                  if amlPqClient is null : invalid state
 **/

tvError_t GetCurrentBacklightMode(tvBacklightMode_t *blMode) {
    tvError_t ret = tvERROR_NONE;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    *blMode = backlightMode;

    return ret;
}

/**
 * @fn SetCurrentBacklightMode
 * @brief This function sets the backlight mode
 *
 * @param[in] blMode indicates the back light mode of TV
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 *                 if not in tvBacklightMode_t : invalid param
 **/

tvError_t SetCurrentBacklightMode(tvBacklightMode_t blMode) {
    tvError_t ret = tvERROR_NONE;
    int backlight=0;
    int err;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    switch(blMode) {

        case tvBacklightMode_NONE:
        case tvBacklightMode_MANUAL:
            autoBacklightControl(0);
            err = amlPqClient->SetToUseRawBacklight(0);
            if(err == -1) {
                    ret = tvERROR_GENERAL;
            }
            backlightMode = blMode;
//Restore to default
            uAmbientBacklightLevel = 50;

	    //
	    // SKY
	    // restore manual back light value
	    //
            /*err = amlPqClient->SetBacklight( amlPqClient->GetBacklight(),0);
            if(err == -1) {
                    ret = tvERROR_GENERAL;
            }*/
            break;
        case tvBacklightMode_AMBIENT:
            err = amlPqClient->SetToUseRawBacklight(1);
            if(err == -1) {
                ret = tvERROR_GENERAL;
            }else if (autoBacklightControl(1) == 0) {
                backlightMode = blMode;
            }else {
                    amlPqClient->SetToUseRawBacklight(0);
                    ret = tvERROR_GENERAL;
            }
            break;

        case tvBacklightMode_ECO:
//TODO: Not supported currently
            ret = tvERROR_OPERATION_NOT_SUPPORTED;
            break;

        default:
            ret = tvERROR_INVALID_PARAM;
            break;
    }

    if(isCurrentHDRTypeIsSDR())
    {
        backlight = allBacklightInfo.sdrBLCurve[allBacklightInfo.defaultBLSDR];
    }else
    {
        backlight = allBacklightInfo.hdrBLCurve[allBacklightInfo.defaultBLHDR];
    }

    int rawBacklight = amlPqClient->GetBacklightRaw();
    if( backlightFactorRangeMid)
       backlightFactor = (rawBacklight*backlightFactorRangeMid)/backlight; 

    return ret;
}

/**
 * @fn GetCurrentVideoFormat
 * @brief This function gets the current video format
 *
 * @param[out] *format indicates the pointer variable
 *
 * @return Returns on success : no error
 **/

tvError_t GetCurrentVideoFormat(tvVideoHDRFormat_t *format) {
    *format= m_currentVideoFormat;
    return tvERROR_NONE;
}

/**
 * @fn RegisterVideoFormatChangeCB
 * @brief This function register a callback for video format update
 *
 * @param[in] *cb callback function
 *
 * @return Returns on success : no error
 **/

void RegisterVideoFormatChangeCB(tvVideoFormatCallbackData& cbData){
    m_videoFormatChangeCBData.userdata = cbData.userdata;
    m_videoFormatChangeCBData.cb = cbData.cb;
    return;
}

/**
 * @fn RegisterVideoResolutionChangeCB
 * @brief This function register a callback for video format update
 *
 * @param[in] *cb callback function
 *
 * @return Returns on success : no error
 **/

void RegisterVideoResolutionChangeCB(tvVideoResolutionCallbackData& cbData){
    m_videoResolutionChangeCBData.userdata = cbData.userdata;
    m_videoResolutionChangeCBData.cb = cbData.cb;
    return;
}

void RegisterVideoFrameRateChangeCB(tvVideoFrameRateCallbackData& cbData){
    m_videoFrameRateChangeCBData.userdata = cbData.userdata;
    m_videoFrameRateChangeCBData.cb = cbData.cb;
    return;
}

/**
**
 * @fn GetVideoResolution
 * @brief This function gets the current video resolution
 *
 * @param[out] *format indicates the pointer variable
 *
 * @return Returns on success : no error
 **/
tvError_t GetVideoResolution(tvResolutionParam_t *resolutionstruct) {

    int frameheight = 0;
    int framewidth = 0;
    int linescanmode = 0;
    tvVideoResolution_t resolution;

    if (NULL == tvclient)
    {
        return tvERROR_GENERAL;
    }

    framewidth = GetCurrentSourceFrameWidth(tvclient);
    frameheight = GetCurrentSourceFrameHeight(tvclient);
    linescanmode = GetCurrentSourceLineScanMode(tvclient);

    printf("%s: Video Mode Info: frameHeight: %d, frameWidth: %d linescanmode: %d\n",__PRETTY_FUNCTION__
            ,frameheight,framewidth,linescanmode);

    if (linescanmode == 2) {
        switch (frameheight) {
            case 240:
            case 288:
            case 540:
                frameheight *= 2;
                printf("%s: Interlaced mode. half frameheight detected, double it to match standard resolution. Updated frameHeight: %d\n", __PRETTY_FUNCTION__, frameheight);
                break;
        }
    }

    switch(frameheight) {
            case 240:
		switch(framewidth) {
			case 720:
                            resolution = tvVideoResolution_720x240;
                            break;
			case 2880:
			    resolution = tvVideoResolution_2880x240;
			    break;
			default:
                            resolution = tvVideoResolution_NONE;
	        }
                break;

            case 288:
		switch(framewidth) {
			case 720:
			    resolution = tvVideoResolution_720x288;
			    break;
			case 2880:
			    resolution = tvVideoResolution_2880x288;
			    break;
			default:
			    resolution = tvVideoResolution_NONE;
	        }
                break;

            case 480:
		switch(framewidth) {
			case 640:
		            resolution = tvVideoResolution_640x480;
	                    break;
			case 720:
		            resolution = tvVideoResolution_720x480;
	                    break;
			case 800:
		            resolution = tvVideoResolution_800x480;
	                    break;
			case 852:
		            resolution = tvVideoResolution_852x480;
	                    break;
			case 854:
		            resolution = tvVideoResolution_854x480;
	                    break;
			case 1440:
		            resolution = tvVideoResolution_1440x480;
	                    break;
			case 2880:
		            resolution = tvVideoResolution_2880x480;
	                    break;
			default:
			    resolution = tvVideoResolution_NONE;
		}
                break;

            case 540:
		switch(framewidth) {
			case 960:
			    resolution = tvVideoResolution_960x540;
			    break;
			case 3840:
			    resolution = tvVideoResolution_3840x540;
			    break;
			default:
			    resolution = tvVideoResolution_NONE;
		}
                break;

            case 576:
		switch(framewidth) {
			case 720:
			    resolution = tvVideoResolution_720x576;
			    break;
			case 1440:
			    resolution = tvVideoResolution_1440x576;
			    break;
			case 2880:
			    resolution = tvVideoResolution_2880x576;
			    break;
			default:
			    resolution = tvVideoResolution_NONE;
		}
                break;

            case 600:
		switch(framewidth) {
			case 800:
			    resolution = tvVideoResolution_800x600;
			    break;
			case 1024:
			    resolution = tvVideoResolution_1024x600;
			    break;
			case 1280:
			    resolution = tvVideoResolution_1280x600;
			    break;
			default:
			    resolution = tvVideoResolution_NONE;
		}
		break;

            case 720:
		switch(framewidth) {
			case 1280:
			    resolution = tvVideoResolution_1280x720;
			    break;
			case 1680:
			    resolution = tvVideoResolution_1680x720;
			    break;
			default:
			    resolution = tvVideoResolution_NONE;
		}
                break;

            case 768:
		switch(framewidth) {
			case 1024:
			    resolution = tvVideoResolution_1024x768;
			    break;
			case 1280:
			    resolution = tvVideoResolution_1280x768;
			    break;
			case 1360:
			    resolution = tvVideoResolution_1360x768;
			    break;
			case 1366:
			    resolution = tvVideoResolution_1366x768;
			    break;
			 default:
			    resolution = tvVideoResolution_NONE;
		}
                break;

            case 900:
		switch(framewidth) {
			case 1440:
			    resolution = tvVideoResolution_1440x900;
			    break;
			case 1600:
			    resolution = tvVideoResolution_1600x900;
			    break;
			default:
			    resolution = tvVideoResolution_NONE;
		}
                break;

            case 960:
		switch(framewidth) {
			case 1280:
			    resolution = tvVideoResolution_1280x960;
			    break;
			default:
			    resolution = tvVideoResolution_NONE;
		}
                break;

            case 1080:
		switch(framewidth) {
			case 1920:
			    resolution = tvVideoResolution_1920x1080;
			    break;
			case 2560:
			    resolution = tvVideoResolution_2560x1080;
			    break;
			case 3840:
			    resolution = tvVideoResolution_3840x1080;
			    break;
			default:
			    resolution = tvVideoResolution_NONE;
		}
                break;

            case 1200:
                switch(framewidth) {
	                case 1600:
		            resolution = tvVideoResolution_1600x1200;
	                    break;
	                case 1920:
		            resolution = tvVideoResolution_1920x1200;
	                    break;
	                case 2160:
		            resolution = tvVideoResolution_2160x1200;
	                    break;
	                case 2400:
		            resolution = tvVideoResolution_2400x1200;
	                    break;
			default:
			    resolution = tvVideoResolution_NONE;
		}
		break;
	    case 1024:
		switch(framewidth) {
			case 1280:
			    resolution = tvVideoResolution_1280x1024;
			    break;
			default:
			    resolution = tvVideoResolution_NONE;
		}
		break;
            case 1440:
                switch(framewidth) {
	                case 2560:
		            resolution = tvVideoResolution_2560x1440;
	                    break;
	                case 3440:
		            resolution = tvVideoResolution_3440x1440;
	                    break;
	                default:
	                    resolution = tvVideoResolution_NONE;
	        }
                break;
            case 2160:
                switch(framewidth) {
	                case 3840:
		            resolution = tvVideoResolution_3840x2160;
	                    break;
	                case 4096:
		            resolution = tvVideoResolution_4096x2160;
	                    break;
	                default:
	                    resolution = tvVideoResolution_NONE;
	        }
                break;

            default:
                resolution = tvVideoResolution_NONE;
                break;
    }
    currentResolution = resolution;
    resolutionstruct->resolutionValue = resolution;
    resolutionstruct->frameHeight = frameheight;
    resolutionstruct->frameWidth = framewidth;

    resolutionstruct->isInterlaced = false;
    if (linescanmode == 2) resolutionstruct->isInterlaced = true;

    printf("currentResolution=%d resolution %d\n",currentResolution,resolution);
    return tvERROR_NONE;
}

/**
 * @fn GetFrameRate
 * @brief This function gets the current video Frame Rate.
 *
 * @param[out] *format indicates the pointer variable
 *
 * @return Returns on success : no error
 **/

tvError_t GetVideoFrameRate(tvVideoFrameRate_t *frameRate) {

    int fps = 0;

    if (NULL == tvclient)
    {
        return tvERROR_GENERAL;
    }

    fps = GetCurrentSourceFrameFps(tvclient);

    printf("%s: Video Mode Info:  FrameRate: %d \n",__PRETTY_FUNCTION__,fps);
    switch(fps) {
            case 23:
                *frameRate = tvVideoFrameRate_23dot98;
                break;

            case 24:
                *frameRate = tvVideoFrameRate_24;
                break;

            case 25:
                *frameRate = tvVideoFrameRate_25;
                break;

            case 29:
                *frameRate = tvVideoFrameRate_29dot97;
                break;

            case 30:
                *frameRate = tvVideoFrameRate_30;
                break;

            case 49:
            case 50:
                *frameRate = tvVideoFrameRate_50;
                break;

            case 59:
                *frameRate = tvVideoFrameRate_59dot94;
                break;

            case 60:
                *frameRate = tvVideoFrameRate_60;
                break;

            default:
                *frameRate = tvVideoFrameRate_NONE;
                break;
    }
    currentFrameRate = *frameRate;
    printf("%s: Video Mode Info:  FrameRate: %d and currentFrameRate = %d\n",__PRETTY_FUNCTION__,*frameRate,currentFrameRate);
    return tvERROR_NONE;
}

/**
 * @fn SetBrightness
 * @brief This function updates the brightness to driver
 *
 * @param[in] brightness indicates the value of brightness
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 *                 if not in range 0-100 : invalid param
 **/

tvError_t SetBrightness(int brightness) {
    tvError_t ret = tvERROR_NONE;
    if((brightness < 0) || (brightness > 100)) {
        return tvERROR_INVALID_PARAM;
    }

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    int err = amlPqClient->SetBrightness(brightness,SAVEPARAM);
    if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    // else {
    //     brightnessLevel = brightness;
    // }
    return ret;
}

/**
 * @fn GetBrightness
 * @brief This function gets the brightness from driver
 *
 * @param[out] *brightness indicates the pointer variable
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/

tvError_t GetBrightness(int *brightness) {
    tvError_t ret = tvERROR_NONE;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

   *brightness = amlPqClient->GetBrightness();
    // *brightness = brightnessLevel;

    return ret;
}

/**
 * @fn SetContrast
 * @brief This function updates the contrast to driver
 *
 * @param[in] contrast indicates the contrast value
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 *                 if not in range 0-100 : invalid param
 **/

tvError_t SetContrast(int contrast) {

    tvError_t ret = tvERROR_NONE;

    if((contrast < 0) || (contrast > 100)) {
        return tvERROR_INVALID_PARAM;
    }

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    int err = amlPqClient->SetContrast(contrast,SAVEPARAM);
    if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    // else {
    //     contrastLevel = contrast;
    // }

    return ret;


}

/**
 * @fn GetContrast
 * @brief This function gets the contrast from driver
 *
 * @param[out] *contrast indicates the pointer variable
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/

tvError_t GetContrast(int *contrast) {
    tvError_t ret = tvERROR_NONE;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

   *contrast = amlPqClient->GetContrast();
    // *contrast = contrastLevel;

    return ret;
}

/**
 * @fn SetSharpness
 * @brief This function updtes the sharpness to driver
 *
 * @param[in] sharpness indicates the sharpness value
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 *                 if not in range 0-100 : invalid param
 **/

tvError_t SetSharpness(int sharpness) {

    tvError_t ret = tvERROR_NONE;

    if((sharpness < 0) || (sharpness > 100)) {
        return tvERROR_INVALID_PARAM;
    }

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    int err = amlPqClient->SetSharpness(sharpness,1,SAVEPARAM);;
    if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    // else {
    //     sharpnessLevel = sharpness;
    // }

    return ret;

}

/**
 * @fn GetSharpness
 * @brief This function gets the sharpness from driver
 *
 * @param[out] *sharpness indicates the pointer variable
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/

tvError_t GetSharpness(int *sharpness) {
    tvError_t ret = tvERROR_NONE;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

   *sharpness = amlPqClient->GetSharpness();
    // *sharpness = sharpnessLevel;
    return ret;
}

/**
 * @fn SetSaturation
 * @brief This function updates the saturation to driver
 *
 * @param[in] saturation indicates the saturation value
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 *                 if not in range 0-100 : invalid param
 **/

tvError_t SetSaturation(int saturation) {

    tvError_t ret = tvERROR_NONE;

    if((saturation < 0) || (saturation > 100)) {
        return tvERROR_INVALID_PARAM;
    }

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    int err = amlPqClient->SetSaturation(saturation,SAVEPARAM);
    if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    // else {
    //     saturationLevel = saturation;
    // }

    return ret;

}

/**
 * @fn GetSaturation
 * @brief This function gets the saturation from driver
 *
 * @param[out] *saturation indicates the pointer
 *
 * @return Returns on success : no error
 *                  if amlPqClient is null : invalid state
 **/

tvError_t GetSaturation(int *saturation) {
    tvError_t ret = tvERROR_NONE;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

   *saturation = amlPqClient->GetSaturation();
    // *saturation = saturationLevel;

    return ret;
}

/**
 * @fn SetHue
 * @brief This function updates the hue to driver
 *
 * @param[in] hue indicates the value of hue
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 *                 if not in range 0-100 : invalid param
 **/

tvError_t SetHue(int hue) {

    tvError_t ret = tvERROR_NONE;

    if((hue < 0) || (hue > 100)) {
        return tvERROR_INVALID_PARAM;
    }

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    int err = amlPqClient->SetHue(hue,SAVEPARAM);
    if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    // else {
    //     hueLevel = hue;
    // }

    return ret;

}

/**
 * @fn GetHue
 * @brief This function gets the hue from driver
 *
 * @param[out] *hue indicates the pointer variable
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/

tvError_t GetHue(int *hue) {
    tvError_t ret = tvERROR_NONE;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

   *hue = amlPqClient->GetHue();
//    *hue = hueLevel;

    return ret;
}

/**
 * @fn SetColorTemperature
 * @brief This function updates the color temperature to driver
 *
 * @param[in] colorTemp indicates the value of colorTemp
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 *                 in case of default : default value
 **/

tvError_t SetColorTemperature(tvColorTemp_t colorTemp) {

    tvError_t ret = tvERROR_NONE;
    int err = 0;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    switch(colorTemp) {

        case tvColorTemp_STANDARD:
            err = amlPqClient->SetColorTemperature(0, SAVEPARAM, -1, -1);
            break;

        case tvColorTemp_WARM:
            err = amlPqClient->SetColorTemperature(1, SAVEPARAM, -1, -1);
            break;

        case tvColorTemp_COLD:
            err = amlPqClient->SetColorTemperature(2, SAVEPARAM, -1, -1);
            break;

        case tvColorTemp_USER:
            err = amlPqClient->SetColorTemperature(3, SAVEPARAM, -1, -1);
            break;

        case tvColorTemp_MAX:
            err = amlPqClient->SetColorTemperature(4, SAVEPARAM, -1, -1);
            break;

        default:
            ret = tvERROR_INVALID_PARAM;
            break;
    }

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }
   // else {
   //     colorTempValue = colorTemp;
   // }

    return ret;

}

/**
 * @fn GetColorTemperature
 * @brief This function gets the color tmperature from driver
 *
 * @param[out] *colorTemp indicates the pointer variable to enum tvColorTemp_t
 *
 * @return Returns on success : no error
                   if amlPqClient is null : invalid state
 **/

tvError_t GetColorTemperature(tvColorTemp_t *colorTemp) {
    tvError_t ret = tvERROR_NONE;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    int ct = amlPqClient->GetColorTemperature();

    switch(ct) {

        case 0:
            *colorTemp = tvColorTemp_STANDARD;
            break;

        case 1:
            *colorTemp = tvColorTemp_WARM;
            break;

        case 2:
            *colorTemp = tvColorTemp_COLD;
            break;

        case 3:
            *colorTemp = tvColorTemp_USER;
            break;

        case 4:
            *colorTemp = tvColorTemp_MAX;
            break;

        default:
            *colorTemp = tvColorTemp_STANDARD;
            ret = tvERROR_GENERAL;
            break;
    }
    //*colorTemp = colorTempValue;

    return ret;
}

static void *SetAspectRatio_thread(void *arg)
{
    int err = 0;
    int rc = 0, status = 0, retry = 0;
    tvDisplayMode_t dispMode = *((tvDisplayMode_t*)arg);
    free(arg);

    printf("%s Enter:%d thread ID:%lu ---> dispMode=%d \n", __PRETTY_FUNCTION__,__LINE__,pthread_self(), dispMode);


    do{
#ifdef  TMP_XDG_RUNTIME_DIR
        rc = system("export XDG_RUNTIME_DIR=/tmp; westeros-gl-console get zoom-mode");
#else
	rc = system("export XDG_RUNTIME_DIR=/run; westeros-gl-console get zoom-mode");
#endif
        status = WEXITSTATUS(rc);
        if(status)
        {
            retry++;
            printf("%s:westeros-gl-console returned status:%d,retry:%d\n",__FUNCTION__,status,retry);
            usleep(5000*1000);
            if(retry == 10)
                status = 0;
        }
    }while(status);

    if(status != 0)
	printf("Aspect ratio settings is not persistent! As westeros compositor is not up in time\n");

    switch(dispMode) {
        case tvDisplayMode_4x3:
            err = amlPqClient->SetDisplayMode(0,4,SAVEPARAM);
#ifdef TMP_XDG_RUNTIME_DIR
            system("export XDG_RUNTIME_DIR=/tmp; westeros-gl-console set zoom-mode 4");
#else
	    system("export XDG_RUNTIME_DIR=/run; westeros-gl-console set zoom-mode 4");
#endif
            break;

        case tvDisplayMode_16x9:
            err = amlPqClient->SetDisplayMode(0,0,SAVEPARAM);
#ifdef TMP_XDG_RUNTIME_DIR
            system("export XDG_RUNTIME_DIR=/tmp; westeros-gl-console set zoom-mode 3");
#else
	    system("export XDG_RUNTIME_DIR=/run; westeros-gl-console set zoom-mode 3");
#endif
            break;

        case tvDisplayMode_FULL:
            err = amlPqClient->SetDisplayMode(0,5,SAVEPARAM);
#ifdef TMP_XDG_RUNTIME_DIR
            system("export XDG_RUNTIME_DIR=/tmp; westeros-gl-console set zoom-mode 3");
#else
            system("export XDG_RUNTIME_DIR=/run; westeros-gl-console set zoom-mode 3");
#endif
            break;

        case tvDisplayMode_NORMAL:
            err = amlPqClient->SetDisplayMode(0,6,SAVEPARAM);
#ifdef TMP_XDG_RUNTIME_DIR
            system("export XDG_RUNTIME_DIR=/tmp; westeros-gl-console set zoom-mode 2");
#else
            system("export XDG_RUNTIME_DIR=/run; westeros-gl-console set zoom-mode 2");
#endif
            break;

        case tvDisplayMode_AUTO:
            err = amlPqClient->SetDisplayMode(0,0,SAVEPARAM);
#ifdef TMP_XDG_RUNTIME_DIR
            system("export XDG_RUNTIME_DIR=/tmp; westeros-gl-console set zoom-mode 2");
#else
            system("export XDG_RUNTIME_DIR=/run; westeros-gl-console set zoom-mode 2");
#endif
            break;

        case tvDisplayMode_DIRECT:
            err = amlPqClient->SetDisplayMode(0,6,SAVEPARAM);
#ifdef TMP_XDG_RUNTIME_DIR
            system("export XDG_RUNTIME_DIR=/tmp; westeros-gl-console set zoom-mode 1");
#else
            system("export XDG_RUNTIME_DIR=/run; westeros-gl-console set zoom-mode 1");
#endif
            break;

        case tvDisplayMode_ZOOM:
            err = amlPqClient->SetDisplayMode(0,10,SAVEPARAM);
#ifdef TMP_XDG_RUNTIME_DIR
            system("export XDG_RUNTIME_DIR=/tmp; westeros-gl-console set zoom-mode 5");
#else
            system("export XDG_RUNTIME_DIR=/run; westeros-gl-console set zoom-mode 5");
#endif
            break;

        case tvDisplayMode_MAX:
            err = amlPqClient->SetDisplayMode(0,11,SAVEPARAM);
#ifdef TMP_XDG_RUNTIME_DIR
            system("export XDG_RUNTIME_DIR=/tmp; westeros-gl-console set zoom-mode -1");
#else
            system("export XDG_RUNTIME_DIR=/run; westeros-gl-console set zoom-mode -1");
#endif
            break;
        default:
            break;
    }

    if(err != -1) {
        aspectRatioValue = dispMode;
    }

    printf("%s Exit:%d thread ID:%lu \n", __PRETTY_FUNCTION__,__LINE__,pthread_self());
    pthread_exit(NULL);
    return NULL;
}

/**
 * @fn SetAspectRatio
 * @brief This function updates the Aspect ratio to driver
 *
 * @param[in] dispMode indicates the value of aspect ratio
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 *                 in case of default : default value
 **/

tvError_t SetAspectRatio(tvDisplayMode_t dispMode) {

    tvError_t ret = tvERROR_NONE;
    pthread_t AspectRatioThreadID;
    int *arg = (int*) malloc(sizeof(*arg));
    *arg = dispMode;

    printf("SetAspectRatio enter -->\n");
    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

   int err = pthread_create( &AspectRatioThreadID, NULL, &SetAspectRatio_thread, arg);
    if(err != 0){
        printf("%s:%d : SetAspectRatio_thread creation failed!!! \n", __FUNCTION__,__LINE__);
        ret = tvERROR_GENERAL;
    }
    else {
        err = pthread_detach(AspectRatioThreadID);
        if(err != 0) {
            printf("%s:%d : SetAspectRatio_thread failed!!! \n", __FUNCTION__,__LINE__);
        }
    }
    printf("SetAspectRatio exit <--\n");
    return ret;
}

/**
 * @fn GetAspectRatio
 * @brief This function gets the aspect ratio from driver
 *
 * @param[out] *dispMode indicates the pointer variable to enum tvDisplayMode_t
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/

tvError_t GetAspectRatio(tvDisplayMode_t *dispMode) {
    tvError_t ret = tvERROR_NONE;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

#if 0
    int aspectRatio = amlPqClient->GetAspectRatio();

    switch(aspectRatio) {

        case 4:
            *dispMode = tvDisplayMode_4x3;
            break;

        case 0:
            *dispMode = tvDisplayMode_16x9;
            break;

        case 5:
            *dispMode = tvDisplayMode_FULL;
            break;

        case 6:
            *dispMode = tvDisplayMode_NORMAL;
            break;

        case 11:
            *dispMode = tvDisplayMode_MAX;
            break;

        default:
            *dispMode = tvDisplayMode_16x9;
            ret = tvERROR_GENERAL;
            break;
    }
#endif
    *dispMode = aspectRatioValue;
    return ret;
}


/**
 * @fn SetRGBPattern
 * @brief This function updates the RGB color value for the pattern to driver
 *
 * @param[in]  indicates the r,g and b values for the pattern
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 *                 if not in range 0-100 : invalid param
 **/

tvError_t SetRGBPattern(int r,int g, int b) {

    tvError_t ret = tvERROR_NONE;
//    int Rgbvalue=0;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

//    Rgbvalue = (int) ((r & 0xff) << 16) | ((g & 0xff) << 8) | (b & 0xff);
    int err = amlPqClient->FactorySetRGBPattern(r, g, b);
    if(err == -1) {
        ret = tvERROR_GENERAL;
    }

    return ret;

}

/**
 * @fn GetRGBPattern
 * @brief This function gets the RGB pattern value  from driver
 *
 * @param[out] *r *g *b  indicates the returned rgb value from driver.
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/

tvError_t GetRGBPattern(int *r,int *g,int *b) {
    tvError_t ret = tvERROR_NONE;

    int Rgbvalue=0;
    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    Rgbvalue = amlPqClient->FactoryGetRGBPattern();
    *b = ( Rgbvalue ) & 0xFF;
    *g = ( Rgbvalue >> 8) & 0xFF;
    *r = ( Rgbvalue >> 16) & 0xFF;

    return ret;
}

/**
 * @fn SetGrayPattern
 * @brief This function updates the YUV  color value  to driver
 *
 * @param[in]  indicates the yuv values for the pattern
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 *                 if not in range 0-100 : invalid param
 **/

tvError_t SetGrayPattern(int YUVValue)

{
   tvError_t ret = tvERROR_NONE;

   if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;
   if((YUVValue  < 0) || ( YUVValue  > 255))
        return tvERROR_INVALID_PARAM;

    int err = amlPqClient->FactorySetGrayPattern(YUVValue);

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }

   return ret;
}

/*
 * @brief This function gets the GetGrayPattern  pattern value  from driver
 *
 * @param[out] *YUVValue  indicates the pointer variable
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/

tvError_t GetGrayPattern(int* YUVValue) {
    tvError_t ret = tvERROR_NONE;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    *YUVValue = amlPqClient->FactoryGetGrayPattern();
    if (*YUVValue == -1)
       ret = tvERROR_GENERAL;

    return ret;
}


/*
 * @brief This function the SetColorTemp_Rgain set rgain
 *
 *  @param[in] Rgain
   param[out] none
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/

tvError_t SetColorTemp_Rgain(tvColorTemp_t colorTemp, int rgain)
{


    tvError_t ret = tvERROR_NONE;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;
    if((rgain  < 0) || ( rgain  > 2047) || (colorTemp > tvColorTemp_COLD))
        return tvERROR_INVALID_PARAM;

    int err = amlPqClient->FactorySetWhiteBalanceRedGain(HDMI_DEFAULT, INT_DUMMY, INT_DUMMY, (int)colorTemp, rgain);

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }

    return ret;


}


/*
 * @brief This function gets the GetColorTemp_Rgain  value  from driver
 *
 * @param[out] *rgain  indicates the pointer variable
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/

tvError_t GetColorTemp_Rgain(tvColorTemp_t colorTemp, int* rgain)
{


    tvError_t ret = tvERROR_NONE;

     if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    if(colorTemp > tvColorTemp_COLD)
        return tvERROR_INVALID_PARAM;

    *rgain  = amlPqClient->FactoryGetWhiteBalanceRedGain(HDMI_DEFAULT, INT_DUMMY, INT_DUMMY, (int) colorTemp);

    if( *rgain == -1) {
        ret = tvERROR_GENERAL;
    }

   return ret;


}



/*
 * @brief This function gets the SetColorTemp_Ggain
 *
 *  @param[in] ggain value
 * @param[out] none
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/

tvError_t SetColorTemp_Ggain(tvColorTemp_t colorTemp, int ggain)
{


    tvError_t ret = tvERROR_NONE;

     if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;
    if((ggain  < 0) || ( ggain  > 2047) || (colorTemp > tvColorTemp_COLD))
        return tvERROR_INVALID_PARAM;

    int err = amlPqClient->FactorySetWhiteBalanceGreenGain(HDMI_DEFAULT, INT_DUMMY, INT_DUMMY, (int)colorTemp,ggain);

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }

   return ret;


}



/*
 * @brief This function gets the GetColorTemp_Ggain  value  from driver
 *
 * @param[out] *ggain  indicates the pointer variable
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/

tvError_t GetColorTemp_Ggain(tvColorTemp_t colorTemp, int* ggain)
{


    tvError_t ret = tvERROR_NONE;

     if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    if(colorTemp > tvColorTemp_COLD)
        return tvERROR_INVALID_PARAM;

    *ggain  = amlPqClient->FactoryGetWhiteBalanceGreenGain(HDMI_DEFAULT, INT_DUMMY, INT_DUMMY, (int) colorTemp);

    if( *ggain == -1) {
        ret = tvERROR_GENERAL;
    }

   return ret;


}


/*
 * @brief This function  SetColorTemp_Bgain set Bgain
 *  @param[in] bgain value
 * @param[out] none
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/

tvError_t SetColorTemp_Bgain(tvColorTemp_t colorTemp, int bgain)
{


    tvError_t ret = tvERROR_NONE;

     if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;
    if((bgain  < 0) || ( bgain  > 2047) || (colorTemp > tvColorTemp_COLD))
        return tvERROR_INVALID_PARAM;

    int err = amlPqClient->FactorySetWhiteBalanceBlueGain(HDMI_DEFAULT, INT_DUMMY, INT_DUMMY, (int)colorTemp,bgain);

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }

   return ret;


}

/*
 * @brief This function gets the GetColorTemp_Bgain  value  from driver
 *
 * @param[out] *ggain  indicates the pointer variable
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/

tvError_t GetColorTemp_Bgain(tvColorTemp_t colorTemp, int* bgain)
{


    tvError_t ret = tvERROR_NONE;

     if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    if(colorTemp > tvColorTemp_COLD)
        return tvERROR_INVALID_PARAM;

    *bgain  = amlPqClient->FactoryGetWhiteBalanceBlueGain(HDMI_DEFAULT, INT_DUMMY, INT_DUMMY, (int) colorTemp);

    if( *bgain == -1) {
        ret = tvERROR_GENERAL;
    }

   return ret;


}

/*
 * @brief This function sets the SetColorTemp_R_post_offset
 *
 * @param[in] rpostoffset value
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/



tvError_t SetColorTemp_R_post_offset(tvColorTemp_t colorTemp, int rpostoffset)
{
   tvError_t ret = tvERROR_NONE;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;
    if((rpostoffset  < -1024 ) || ( rpostoffset  > 1024) || (colorTemp > tvColorTemp_COLD))
        return tvERROR_INVALID_PARAM;

    int err = amlPqClient->FactorySetWhiteBalanceRedPostOffset(HDMI_DEFAULT, INT_DUMMY, INT_DUMMY, (int)colorTemp,rpostoffset);

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }

   return ret;


}

/*
 * @brief This function gets the rpostoffset
 *
 ** @param[out] *rpostoffset  indicates the pointer variable
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/



tvError_t GetColorTemp_R_post_offset(tvColorTemp_t colorTemp, int* rpostoffset)
{
     tvError_t ret = tvERROR_NONE;

     if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    if(colorTemp > tvColorTemp_COLD)
        return tvERROR_INVALID_PARAM;

     *rpostoffset = amlPqClient->FactoryGetWhiteBalanceRedPostOffset(HDMI_DEFAULT, INT_DUMMY, INT_DUMMY, (int) colorTemp);

   return ret;


}


/*
 * @brief This function sets the SetColorTemp_G_post_offset
 *
 * @param[in] gpostoffset value
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/



tvError_t SetColorTemp_G_post_offset(tvColorTemp_t colorTemp, int gpostoffset)
{
   tvError_t ret = tvERROR_NONE;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;
    if((gpostoffset  < -1024 ) || ( gpostoffset  > 1024) || (colorTemp > tvColorTemp_COLD))
        return tvERROR_INVALID_PARAM;

    int err = amlPqClient->FactorySetWhiteBalanceGreenPostOffset(HDMI_DEFAULT, INT_DUMMY, INT_DUMMY, (int)colorTemp,gpostoffset);

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }

   return ret;


}

/*
 * @brief This function gets the gpostoffset
 *
 ** @param[out] *gpostoffset  indicates the pointer variable
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/



tvError_t GetColorTemp_G_post_offset(tvColorTemp_t colorTemp, int* gpostoffset)
{
    tvError_t ret = tvERROR_NONE;

    if(amlPqClient == NULL)
       return tvERROR_INVALID_STATE;

    if(colorTemp > tvColorTemp_COLD)
        return tvERROR_INVALID_PARAM;

    *gpostoffset = amlPqClient->FactoryGetWhiteBalanceGreenPostOffset(HDMI_DEFAULT, INT_DUMMY, INT_DUMMY, (int) colorTemp);


   return ret;


}



/*
 * @brief This function sets the SetColorTemp_B_post_offset
 *
 * @param[in] Bpostoffset value
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/



tvError_t SetColorTemp_B_post_offset(tvColorTemp_t colorTemp, int bpostoffset)
{
   tvError_t ret = tvERROR_NONE;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;
    if((bpostoffset  < -1024 ) || ( bpostoffset  > 1024) || (colorTemp > tvColorTemp_COLD))
        return tvERROR_INVALID_PARAM;

    int err = amlPqClient->FactorySetWhiteBalanceBluePostOffset(HDMI_DEFAULT, INT_DUMMY, INT_DUMMY, (int)colorTemp,bpostoffset);

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }

   return ret;
}

/*
 * @brief This function gets the bpostoffset
 *
 ** @param[out] *bpostoffset  indicates the pointer variable
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/



tvError_t GetColorTemp_B_post_offset(tvColorTemp_t colorTemp, int* bpostoffset)
{
     tvError_t ret = tvERROR_NONE;

     if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    if(colorTemp > tvColorTemp_COLD)
        return tvERROR_INVALID_PARAM;

     *bpostoffset = amlPqClient->FactoryGetWhiteBalanceBluePostOffset(HDMI_DEFAULT, INT_DUMMY, INT_DUMMY, (int) colorTemp);


   return ret;


}


/**
 * @fn GetTVSupportedPictureModes
 * @brief This function get the picture mode from the driver
 *
 * @param[0ut]*pictureMode indicates the  pointer to enum tvPictureMode_t
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 *                 in case of default : default value
 **/

tvError_t GetTVSupportedPictureModes(pic_modes_t *pictureModes[],unsigned short *count) {
    tvError_t ret = tvERROR_NONE;
    pic_modes_t *availableModes = pic_modes;

    // printf("Entering Function %s Nsupported %d \n", __func__,numberModesSupported);

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    if(numberModesSupported)
        *pictureModes  = availableModes;
    else
        *pictureModes = NULL;

    *count = numberModesSupported;
    if(0 == *count)
    {
        ret = tvERROR_GENERAL;
    }
    return ret;
}

/* Keep it private */
static tvPictureMode_t getPicModeEnum(const char * pictureMode)
{
    unsigned short loopcount = 0;
    tvPictureMode_t retValue = tvPictureMode_MAX;
    for(;loopcount<numberModesSupported;loopcount++)
    {
        if(0==strcmp(pic_modes[loopcount].name,pictureMode))
        {
            retValue = pic_modes[loopcount].value;
        }
    }
    return retValue;
}

tvError_t GetTVSupportedDVModes(pic_modes_t *dvModes[],unsigned short *count) {
    tvError_t ret = tvERROR_NONE;
    pic_modes_t *availableModes = dv_modes;
    // printf("Entering Function %s Nsupported %d \n", __func__,numberModesSupported);

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    if(numberDVModesSupported)
        *dvModes  = availableModes;
    else
        *dvModes = NULL;

    *count = numberDVModesSupported;
    if(0 == *count)
    {
        ret = tvERROR_GENERAL;
    }
    return ret;
}


tvError_t GetTVDolbyVisionMode(char *dolbyMode) {
    tvError_t ret = tvERROR_NONE;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    int index=amlPqClient->GetDolbyMode();

    if( index < 0 || index > 1)
        ret=tvERROR_GENERAL;
    else
    {
        strncpy(dolbyMode,dolbyVisionMode[index],PIC_MODE_NAME_MAX);
        printf("GetTVDolbyVisionMode():DVModeindexValue %d pictureMode %s \n",index,dolbyMode);
    }

    return ret;
}

tvError_t SetTVDolbyVisionMode(const char * dolbyMode) {
    tvError_t ret = tvERROR_NONE;
    int err = 0;
    int dvToSet=GetDolbyModeIndex(dolbyMode);

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    if(dvToSet>(numberDVModesSupported-1))
    {
         ret = tvERROR_INVALID_PARAM;
    }
    else
        err = amlPqClient->SetDolbyMode(dvToSet,SAVEPARAM);

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    else {
        // printf("Setting up dolby mode to dvToSet %d  \n",dvToSet);
        DVModeValue = dvToSet;
    }

    return ret;
}

tvError_t SetTVHDR10Mode(const char * hdr10Mode) {
    tvError_t ret = tvERROR_NONE;
    int err = 0;
    int hdr10ToSet=GetHDR10ModeIndex(hdr10Mode);
    
    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    if(hdr10ToSet>tvMode_Max || hdr10ToSet < 0)
    {
        ret = tvERROR_INVALID_PARAM;
    }   
    else
        err = amlPqClient->SetDolbyMode(hdr10ToSet,SAVEPARAM);

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }

    return ret;
}

tvError_t SetTVHLGMode(const char *hlgMode) {
    tvError_t ret = tvERROR_NONE;
    int err = 0;
    int hlgToSet=GetHLGModeIndex(hlgMode);
    
    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    if(hlgToSet> tvMode_Max || hlgToSet < 0)
    {
        ret = tvERROR_INVALID_PARAM;
    }   
    else
        err = amlPqClient->SetDolbyMode(hlgToSet,SAVEPARAM);

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }

    return ret;
}

tvError_t SetDynamicContrast(const char *dynamicContrastEnable)
{
    tvError_t ret = tvERROR_NONE;
    int err = 0;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    if (strcmp(dynamicContrastEnable, "enabled") == 0) {
        err = amlPqClient->SetDynamicContrastMode(DYNAMIC_CONTRAST_HIGH,SAVE);
    }
    else if (strcmp(dynamicContrastEnable, "disabled") == 0) {
        err = amlPqClient->SetDynamicContrastMode(DYNAMIC_CONTRAST_OFF,SAVE);
    }

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }

    return ret;
}

tvError_t GetDynamicContrast(char *isDynamicContrastEnabled)
{
    tvError_t ret = tvERROR_NONE;
    int dynamicContrast = 0;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    dynamicContrast = amlPqClient->GetDynamicContrastMode();

    switch (dynamicContrast) {
        case -1:
            ret = tvERROR_GENERAL;
            break;
        case 0:
            strncpy(isDynamicContrastEnabled, "disabled",PIC_MODE_NAME_MAX);
            break;
        default:
            strncpy(isDynamicContrastEnabled, "enabled",PIC_MODE_NAME_MAX);
            break;
        }

    return ret;

}

int sourceIdFromOffset(int offset)
{
    int sourceId=SOURCE_HDMI1;

    switch (offset)
    {
    case HDMI_OFFSET:
        sourceId = SOURCE_HDMI1;
        break;
    case TV_OFFSET:
        sourceId = SOURCE_TV;
        break;
    case AV_OFFSET:
        sourceId = SOURCE_AV1;
        break;
    default:
        printf("This is not allowed , or new source id needs support\n");
        break;
    }
    return sourceId;
}

/*
 * @brief This function the SetColorTemp_Rgain set rgain
 *
 *  @param[in] Rgain
   param[out] none
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/

tvError_t SetColorTemp_Rgain_onSource(tvColorTemp_t colorTemp, int rgain,int sourceOffset, int saveOnly)
{
    tvError_t ret = tvERROR_NONE;
    int err = -1;
    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;
    if((rgain  < 0) || ( rgain  > 2047) || (colorTemp > colorTemperatureMax))
        return tvERROR_INVALID_PARAM;

    if (saveOnly == 1) {
        err = amlPqClient->FactorySaveWhiteBalanceRedGain(sourceIdFromOffset(sourceOffset), INT_DUMMY, INT_DUMMY, (int)colorTemp, rgain);
    } else if (saveOnly == 0) {
        err = amlPqClient->FactorySetWhiteBalanceRedGain(sourceIdFromOffset(sourceOffset), INT_DUMMY, INT_DUMMY, (int)colorTemp, rgain);
    }
    if(err == -1) {
        ret = tvERROR_GENERAL;
    }

    return ret;
}


/*
 * @brief This function gets the GetColorTemp_Rgain  value  from driver
 *
 * @param[out] *rgain  indicates the pointer variable
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/

tvError_t GetColorTemp_Rgain_onSource(tvColorTemp_t colorTemp, int* rgain,int sourceOffset)
{


    tvError_t ret = tvERROR_NONE;

     if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    if(colorTemp > colorTemperatureMax)
        return tvERROR_INVALID_PARAM;

    *rgain  = amlPqClient->FactoryGetWhiteBalanceRedGain(sourceIdFromOffset(sourceOffset), INT_DUMMY, INT_DUMMY, (int) colorTemp);

    if( *rgain == -1) {
        ret = tvERROR_GENERAL;
    }

   return ret;
}



/*
 * @brief This function gets the SetColorTemp_Ggain
 *
 *  @param[in] ggain value
 * @param[out] none
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/

tvError_t SetColorTemp_Ggain_onSource(tvColorTemp_t colorTemp, int ggain,int sourceOffset, int saveOnly)
{


    tvError_t ret = tvERROR_NONE;
    int err = -1;
    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;
    if((ggain  < 0) || ( ggain  > 2047) || (colorTemp > colorTemperatureMax))
        return tvERROR_INVALID_PARAM;

    if (saveOnly == 1) {
        err = amlPqClient->FactorySaveWhiteBalanceGreenGain(sourceIdFromOffset(sourceOffset), INT_DUMMY, INT_DUMMY, (int)colorTemp,ggain);
    } else if (saveOnly == 0) {
        err = amlPqClient->FactorySetWhiteBalanceGreenGain(sourceIdFromOffset(sourceOffset), INT_DUMMY, INT_DUMMY, (int)colorTemp,ggain);
    }
    if(err == -1) {
        ret = tvERROR_GENERAL;
    }

   return ret;
}



/*
 * @brief This function gets the GetColorTemp_Ggain  value  from driver
 *
 * @param[out] *ggain  indicates the pointer variable
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/

tvError_t GetColorTemp_Ggain_onSource(tvColorTemp_t colorTemp, int* ggain,int sourceOffset)
{


    tvError_t ret = tvERROR_NONE;

     if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    if(colorTemp > colorTemperatureMax)
        return tvERROR_INVALID_PARAM;

    *ggain  = amlPqClient->FactoryGetWhiteBalanceGreenGain(sourceIdFromOffset(sourceOffset), INT_DUMMY, INT_DUMMY, (int) colorTemp);

    if( *ggain == -1) {
        ret = tvERROR_GENERAL;
    }

   return ret;
}


/*
 * @brief This function  SetColorTemp_Bgain set Bgain
 *  @param[in] bgain value
 * @param[out] none
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/

tvError_t SetColorTemp_Bgain_onSource(tvColorTemp_t colorTemp, int bgain,int sourceOffset, int saveOnly)
{
    tvError_t ret = tvERROR_NONE;
    int err = -1;
    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;
    if((bgain  < 0) || ( bgain  > 2047) || (colorTemp > colorTemperatureMax))
        return tvERROR_INVALID_PARAM;

    if (saveOnly == 1) {
        err = amlPqClient->FactorySaveWhiteBalanceBlueGain(sourceIdFromOffset(sourceOffset), INT_DUMMY, INT_DUMMY, (int)colorTemp,bgain);
    } else if (saveOnly == 0) {
        err = amlPqClient->FactorySetWhiteBalanceBlueGain(sourceIdFromOffset(sourceOffset), INT_DUMMY, INT_DUMMY, (int)colorTemp,bgain);
    }

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }

   return ret;
}

/*
 * @brief This function gets the GetColorTemp_Bgain  value  from driver
 *
 * @param[out] *ggain  indicates the pointer variable
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/

tvError_t GetColorTemp_Bgain_onSource(tvColorTemp_t colorTemp, int* bgain,int sourceOffset)
{


    tvError_t ret = tvERROR_NONE;

     if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

     if(colorTemp > colorTemperatureMax)
        return tvERROR_INVALID_PARAM;

    *bgain  = amlPqClient->FactoryGetWhiteBalanceBlueGain(sourceIdFromOffset(sourceOffset), INT_DUMMY, INT_DUMMY, (int) colorTemp);

    if( *bgain == -1) {
        ret = tvERROR_GENERAL;
    }

   return ret;
}

/*
 * @brief This function sets the SetColorTemp_R_post_offset
 *
 * @param[in] rpostoffset value
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/



tvError_t SetColorTemp_R_post_offset_onSource(tvColorTemp_t colorTemp, int rpostoffset,int sourceOffset, int saveOnly)
{
    tvError_t ret = tvERROR_NONE;
    int err = -1;
    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;
    if((rpostoffset  < -1024 ) || ( rpostoffset  > 1024) || (colorTemp > colorTemperatureMax))
        return tvERROR_INVALID_PARAM;

    if (saveOnly == 1) {
        err = amlPqClient->FactorySaveWhiteBalanceRedPostOffset(sourceIdFromOffset(sourceOffset), INT_DUMMY, INT_DUMMY, (int)colorTemp,rpostoffset);
    } else if (saveOnly == 0) {
        err = amlPqClient->FactorySetWhiteBalanceRedPostOffset(sourceIdFromOffset(sourceOffset), INT_DUMMY, INT_DUMMY, (int)colorTemp,rpostoffset);
    }

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }

   return ret;
}

/*
 * @brief This function gets the rpostoffset
 *
 ** @param[out] *rpostoffset  indicates the pointer variable
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/



tvError_t GetColorTemp_R_post_offset_onSource(tvColorTemp_t colorTemp, int* rpostoffset,int sourceOffset)
{
     tvError_t ret = tvERROR_NONE;

     if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

     if(colorTemp > colorTemperatureMax)
        return tvERROR_INVALID_PARAM;

     *rpostoffset = amlPqClient->FactoryGetWhiteBalanceRedPostOffset(sourceIdFromOffset(sourceOffset), INT_DUMMY, INT_DUMMY, (int) colorTemp);

   return ret;
}


/*
 * @brief This function sets the SetColorTemp_G_post_offset
 *
 * @param[in] gpostoffset value
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/



tvError_t SetColorTemp_G_post_offset_onSource(tvColorTemp_t colorTemp, int gpostoffset,int sourceOffset, int saveOnly)
{
    tvError_t ret = tvERROR_NONE;
    int err = -1;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;
    if((gpostoffset  < -1024 ) || ( gpostoffset  > 1024) || (colorTemp > colorTemperatureMax))
        return tvERROR_INVALID_PARAM;

    if (saveOnly == 1) {
        err = amlPqClient->FactorySaveWhiteBalanceGreenPostOffset(sourceIdFromOffset(sourceOffset), INT_DUMMY, INT_DUMMY, (int)colorTemp,gpostoffset);
    } else if (saveOnly == 0) {
        err = amlPqClient->FactorySetWhiteBalanceGreenPostOffset(sourceIdFromOffset(sourceOffset), INT_DUMMY, INT_DUMMY, (int)colorTemp,gpostoffset);
    }

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }

    return ret;
}

/*
 * @brief This function gets the gpostoffset
 *
 ** @param[out] *gpostoffset  indicates the pointer variable
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/



tvError_t GetColorTemp_G_post_offset_onSource(tvColorTemp_t colorTemp, int* gpostoffset,int sourceOffset)
{
    tvError_t ret = tvERROR_NONE;

    if(amlPqClient == NULL)
       return tvERROR_INVALID_STATE;

    if(colorTemp > colorTemperatureMax)
        return tvERROR_INVALID_PARAM;

    *gpostoffset = amlPqClient->FactoryGetWhiteBalanceGreenPostOffset(sourceIdFromOffset(sourceOffset), INT_DUMMY, INT_DUMMY, (int) colorTemp);

   return ret;
}



/*
 * @brief This function sets the SetColorTemp_B_post_offset
 *
 * @param[in] Bpostoffset value
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/



tvError_t SetColorTemp_B_post_offset_onSource(tvColorTemp_t colorTemp, int bpostoffset,int sourceOffset, int saveOnly)
{
    tvError_t ret = tvERROR_NONE;
    int err = -1;
    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;
    if((bpostoffset  < -1024 ) || ( bpostoffset  > 1024) || (colorTemp > colorTemperatureMax))
        return tvERROR_INVALID_PARAM;

    if (saveOnly == 1) {
        err = amlPqClient->FactorySaveWhiteBalanceBluePostOffset(sourceIdFromOffset(sourceOffset), INT_DUMMY, INT_DUMMY, (int)colorTemp,bpostoffset);
    } else if (saveOnly == 0) {
        err = amlPqClient->FactorySetWhiteBalanceBluePostOffset(sourceIdFromOffset(sourceOffset), INT_DUMMY, INT_DUMMY, (int)colorTemp,bpostoffset);
    }

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }

   return ret;
}

/*
 * @brief This function gets the bpostoffset
 *
 ** @param[out] *bpostoffset  indicates the pointer variable
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 **/



tvError_t GetColorTemp_B_post_offset_onSource(tvColorTemp_t colorTemp, int* bpostoffset,int sourceOffset)
{
     tvError_t ret = tvERROR_NONE;

     if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

     if(colorTemp > colorTemperatureMax)
        return tvERROR_INVALID_PARAM;

     *bpostoffset = amlPqClient->FactoryGetWhiteBalanceBluePostOffset(sourceIdFromOffset(sourceOffset), INT_DUMMY, INT_DUMMY, (int) colorTemp);

   return ret;
}

bool isAllZero(tvDataColor_t wbvalue)
{
    bool status = false;
    if(wbvalue.r_gain == DEFAULT_WB_ZERO_GAIN &&
        wbvalue.g_gain == DEFAULT_WB_ZERO_GAIN &&
        wbvalue.b_gain == DEFAULT_WB_ZERO_GAIN &&
        wbvalue.r_offset == DEFAULT_WB_OFFSET &&
        wbvalue.g_offset == DEFAULT_WB_OFFSET &&
        wbvalue.b_offset == DEFAULT_WB_OFFSET)
    {
        status = true;
    }

    return status;
}

bool isDefaultNormal(tvDataColor_t wbvalue)
{
    if(wbvalue.r_gain == DEFAULT_WB_NORMAL_RGAIN &&
        wbvalue.g_gain == DEFAULT_WB_NORMAL_GGAIN &&
        wbvalue.b_gain == DEFAULT_WB_NORMAL_BGAIN &&
        wbvalue.r_offset == DEFAULT_WB_OFFSET &&
        wbvalue.g_offset == DEFAULT_WB_OFFSET &&
        wbvalue.b_offset == DEFAULT_WB_OFFSET)
    {
        return true;
    }

    return false;
}

bool isDefaultWarm(tvDataColor_t wbvalue)
{
    bool status = false;
    if(wbvalue.r_gain == DEFAULT_WB_WARM_RGAIN &&
        wbvalue.g_gain == DEFAULT_WB_WARM_GGAIN &&
        wbvalue.b_gain == DEFAULT_WB_WARM_BGAIN &&
        wbvalue.r_offset == DEFAULT_WB_OFFSET &&
        wbvalue.g_offset == DEFAULT_WB_OFFSET &&
        wbvalue.b_offset == DEFAULT_WB_OFFSET)
    {
        status = true;
    }

    return status;
}
bool isDefaultCold(tvDataColor_t wbvalue)
{
    bool status = false;
    if(wbvalue.r_gain == DEFAULT_WB_COLD_RGAIN &&
        wbvalue.g_gain == DEFAULT_WB_COLD_GGAIN &&
        wbvalue.b_gain == DEFAULT_WB_COLD_BGAIN &&
        wbvalue.r_offset == DEFAULT_WB_OFFSET &&
        wbvalue.g_offset == DEFAULT_WB_OFFSET &&
        wbvalue.b_offset == DEFAULT_WB_OFFSET)
    {
        status = true;
    }

    return status;
}

bool areEqual(tvDataColor_t wbvalueThis,tvDataColor_t wbvalueThat)
{
    bool status = false;
    if(wbvalueThis.r_gain == wbvalueThat.r_gain  &&
        wbvalueThis.g_gain == wbvalueThat.g_gain &&
        wbvalueThis.b_gain == wbvalueThat.b_gain &&
        wbvalueThis.r_offset == wbvalueThat.r_offset &&
        wbvalueThis.g_offset == wbvalueThat.g_offset &&
        wbvalueThis.b_offset == wbvalueThat.b_offset)
    {
        status = true;
    }

    return status;
}
void readWBFromCridata(int source,int colorTemp,tvDataColor_t *wbSD3Val)
{
    memset(wbSD3Val,0,sizeof(tvDataColor_t));

    wbSD3Val->r_gain = amlPqClient->FactoryGetWhiteBalanceRedGain(source, INT_DUMMY, INT_DUMMY, colorTemp);
    usleep(2000);
    wbSD3Val->g_gain = amlPqClient->FactoryGetWhiteBalanceGreenGain(source, INT_DUMMY, INT_DUMMY, colorTemp);
    wbSD3Val->b_gain = amlPqClient->FactoryGetWhiteBalanceBlueGain(source, INT_DUMMY, INT_DUMMY, colorTemp);
    usleep(2000);
    wbSD3Val->r_offset = amlPqClient->FactoryGetWhiteBalanceRedPostOffset(source, INT_DUMMY, INT_DUMMY, colorTemp);
    wbSD3Val->g_offset = amlPqClient->FactoryGetWhiteBalanceGreenPostOffset(source, INT_DUMMY, INT_DUMMY, colorTemp);
    usleep(2000);
    wbSD3Val->b_offset = amlPqClient->FactoryGetWhiteBalanceBluePostOffset(source, INT_DUMMY, INT_DUMMY, colorTemp);
}

tvError_t tvwriteCRIdataBySource(tvColorTemp_t colorTemp, tvDataColor_t wbDefaultVal,int source) {
	tvError_t ret = tvERROR_NONE;

        if ((tvERROR_NONE != amlPqClient->FactorySaveWhiteBalanceBlueGain(source, INT_DUMMY, INT_DUMMY, colorTemp,wbDefaultVal.b_gain)) || \
           (tvERROR_NONE != amlPqClient->FactorySaveWhiteBalanceRedGain(source, INT_DUMMY, INT_DUMMY, colorTemp, wbDefaultVal.r_gain)) || \
           (tvERROR_NONE != amlPqClient->FactorySaveWhiteBalanceGreenGain(source, INT_DUMMY, INT_DUMMY, colorTemp, wbDefaultVal.g_gain)))
           {
                   printf("TV_HAL:Failed to set ColorTemp Gain from SD3 \n");
                   ret = tvERROR_GENERAL;
           }
        usleep(5000); //5ms delay before writing offset
        if ((tvERROR_NONE != ret) ||\
           (tvERROR_NONE != amlPqClient->FactorySaveWhiteBalanceGreenPostOffset(source, INT_DUMMY, INT_DUMMY, colorTemp, wbDefaultVal.g_offset)) || \
           (tvERROR_NONE != amlPqClient->FactorySaveWhiteBalanceRedPostOffset(source, INT_DUMMY, INT_DUMMY, colorTemp, wbDefaultVal.r_offset)) || \
           (tvERROR_NONE != amlPqClient->FactorySaveWhiteBalanceBluePostOffset(source, INT_DUMMY, INT_DUMMY, colorTemp, wbDefaultVal.b_offset)))
           {
                   printf("TV_HAL:Failed to set ColorTemp Gain from SD3 \n");
                   ret = tvERROR_GENERAL;
           }
        return ret;
}

mfrSerializedType_t getHdmiSd3Param(int colorTemp, int *index)
{
    mfrSerializedType_t type = mfrSERIALIZED_TYPE_SKY_PANEL_HDMI_WB_DATA_NORMAL;

    if(colorTemp == tvColorTemp_STANDARD) {
        type = mfrSERIALIZED_TYPE_SKY_PANEL_HDMI_WB_DATA_NORMAL;
	*index = 0;
    }
    else if (colorTemp == tvColorTemp_WARM ) {
        type = mfrSERIALIZED_TYPE_SKY_PANEL_HDMI_WB_DATA_WARM;
	*index = 2;
    }
    else if(colorTemp == tvColorTemp_COLD) {
        type = mfrSERIALIZED_TYPE_SKY_PANEL_HDMI_WB_DATA_COLD;
	*index = 1;
    }
    else if(colorTemp == tvColorTemp_USER) {
        type = mfrSERIALIZED_TYPE_SKY_PANEL_HDMI_WB_DATA_USER;
	*index = 3;
    }

    return type;
}

mfrSerializedType_t getTVSd3Param(int colorTemp, int *index)
{
    mfrSerializedType_t type = mfrSERIALIZED_TYPE_SKY_PANEL_TV_WB_DATA_NORMAL;

    if(colorTemp == tvColorTemp_STANDARD) {
        type = mfrSERIALIZED_TYPE_SKY_PANEL_TV_WB_DATA_NORMAL;
	*index = 4;
    }
    else if (colorTemp == tvColorTemp_WARM ) {
        type = mfrSERIALIZED_TYPE_SKY_PANEL_TV_WB_DATA_WARM;
	*index = 6;
    }
    else if(colorTemp == tvColorTemp_COLD) {
        type = mfrSERIALIZED_TYPE_SKY_PANEL_TV_WB_DATA_COLD;
	*index = 5;
    }
    else if(colorTemp == tvColorTemp_USER) {
        type = mfrSERIALIZED_TYPE_SKY_PANEL_TV_WB_DATA_USER;
	*index = 7;
    }

    return type;
}

mfrSerializedType_t getAVSd3Param(int colorTemp, int *index)
{
    mfrSerializedType_t type = mfrSERIALIZED_TYPE_SKY_PANEL_AV_WB_DATA_NORMAL;

    if(colorTemp == tvColorTemp_STANDARD) {
        type = mfrSERIALIZED_TYPE_SKY_PANEL_AV_WB_DATA_NORMAL;
	*index = 8;
    }
    else if (colorTemp == tvColorTemp_WARM ) {
        type = mfrSERIALIZED_TYPE_SKY_PANEL_AV_WB_DATA_WARM;
	*index = 10;
    }
    else if(colorTemp == tvColorTemp_COLD) {
        type = mfrSERIALIZED_TYPE_SKY_PANEL_AV_WB_DATA_COLD;
	*index = 9;
    }
    else if(colorTemp == tvColorTemp_USER) {
        type = mfrSERIALIZED_TYPE_SKY_PANEL_AV_WB_DATA_USER;
	*index = 11;
    }

    return type;
}


mfrSerializedType_t getSD3ParamType(int source,int colorTemp, int *index)
{
    mfrSerializedType_t retType = mfrSERIALIZED_TYPE_SKY_PANEL_HDMI_WB_DATA_NORMAL;

    switch (source)
    {
    case HDMI_OFFSET:
        retType = getHdmiSd3Param(colorTemp, index);
        break;
    case TV_OFFSET:
         retType = getTVSd3Param(colorTemp, index);
        break;
    case AV_OFFSET:
         retType = getAVSd3Param(colorTemp, index);
        break;
    default:
        printf("This is not allowed , or new source id needs support\n");
        break;
    }
    return retType;
}

unsigned char statusOfReadSD3Entry (tvDataColor_t fromSD3,int colorTemp)
{
    unsigned char status = VALUES_ARE_NEW;

    if(isAllZero(fromSD3))
        status|= VALUES_ARE_ZERO;

    if(colorTemp == tvColorTemp_STANDARD)
    {
        if(isDefaultNormal(fromSD3))
            status |= VALUES_ARE_DEFAULT;
    }
    else if(colorTemp == tvColorTemp_WARM)
    {
        if(isDefaultWarm(fromSD3))
            status |= VALUES_ARE_DEFAULT;
    }
    else if(colorTemp == tvColorTemp_COLD)
    {
        if(isDefaultCold(fromSD3))
            status |= VALUES_ARE_DEFAULT;
    }

    return status;
}

void tvCopySD3DatatoCridataEx(void) {

    int sourcesOffset = 0;
    tvDataColor_t * wbSD3Dump;
    unsigned int sd3Valuestatus[3] = {0};
    // unsigned char sd3ValueSourceStatus[3] = {0};

    printf("TV_HAL: Enter %s \n",__FUNCTION__);

    wbSD3Dump = (tvDataColor_t*) malloc(sizeof(tvDataColor_t)*MAX_SOURCE_SUPPROTED_FOR_WB*MAX_COLOR_TEMP_SUPPROTED);

    for(sourcesOffset=0;sourcesOffset<MAX_SOURCE_SUPPROTED_FOR_WB;sourcesOffset++)
    {
        int colorTemp;
        // unsigned char sd3Status = 0;

        for(colorTemp=0;colorTemp<tvColorTemp_USER;colorTemp++)
        {
            IARM_Bus_MFRLib_GetSerializedData_Param_t param;
            IARM_Result_t iarm_ret = IARM_RESULT_IPCCORE_FAIL;
	    int index;

           param.type  = getSD3ParamType(sourcesOffset,colorTemp, &index);

           printf("TV_HAL:Reading fom SD3 for %s(%d)  %s(%d) \n",sourceOffsetString[sourcesOffset],sourcesOffset,colorTempString[colorTemp],colorTemp);
           //printf("Reading fom SD3 for source offset =(%d) temp=(%d) \n", sourcesOffset, colorTemp);
           iarm_ret = IARM_Bus_Call(IARM_BUS_MFRLIB_NAME, IARM_BUS_MFRLIB_API_GetSerializedData, &param, sizeof(param));

           if(iarm_ret == IARM_RESULT_SUCCESS)
            {
                unsigned int offset = (sourcesOffset*MAX_SOURCE_SUPPROTED_FOR_WB)+colorTemp;
                tvDataColor_t * wbSD3Local = wbSD3Dump+offset;
                unsigned char status = 0;

                memcpy((void*)wbSD3Local, param.buffer, sizeof(tvDataColor_t));
		printf("TV_HAL: Updation to local structure\n");
		memcpy((void*)&wbValues[index], param.buffer, sizeof(tvDataColor_t));

                printf("TV_HAL:red gain = %d, green = %d blue =%d\n", wbSD3Local->r_gain, wbSD3Local->g_gain, wbSD3Local->b_gain);
                printf("TV_HAL:red off= %d, green off = %d blue off=%d\n", wbSD3Local->r_offset, wbSD3Local->g_offset, wbSD3Local->b_offset);

                status = statusOfReadSD3Entry(*wbSD3Local,colorTemp);

                sd3Valuestatus[sourcesOffset] |= status <<(colorTemp*BYTE_SIZE);

                // sd3Status |= status;
            }
            else
            {
                sd3Valuestatus[sourcesOffset] |= (VALUES_ARE_ZERO<<(colorTemp*BYTE_SIZE));
                printf("TV_HAL:SD3 Read failed \n");
            }
        }
        // sd3ValueSourceStatus[sourcesOffset] = sd3Status;
    }

    /*
     *  D -> default Values /  N-> non Zero Value /  0-> Zero
     *  HDMI/TV/AV -> SD3 Values  /  hdmi/tv/av ->Cridata values
     *
     *   HDMI     TV      AV     calibrated   Action
     *    0       0       0       No          No Copy
     *    D       0       0       No       	  No Copy (Chances of new or old boxes in Llama having default HDMI value as calibrated value is low
     *                                                     and if it happens we will miss it, accepted risk).
     *    D       D       D       Yes         Sync All
     *    N       0       0       Yes         HDMI->hdmi,HDMI->tv,av (99.9999%  expected case for Llama units and all exisiting Hisense units).
     *    N       N       N       Yes         HDMI->hdmi,TV->tv,AV->av(99.9999% case for Hisense units. never happen for Llama unit)
     *    N       0       N       Yes         HDMI->hdmi, HDMI->tv, AV->av
	 *    N       N       0       Yes         HDMI->hdmi, HDMI->av, TV->tv
	 * For all copy across SD3 to Cridata happens only if SD3 and Cridata
     * Entries are NOT equal.
     */

    /* Starting with no copy conditions */
    if((sd3Valuestatus[HDMI_OFFSET] == ZERO_IN_ALL_TEMP ||
        sd3Valuestatus[HDMI_OFFSET] == DEFAULT_IN_ALL_TEMP ) &&
                sd3Valuestatus[TV_OFFSET] == ZERO_IN_ALL_TEMP &&
                sd3Valuestatus[AV_OFFSET] ==ZERO_IN_ALL_TEMP )
    {
        printf("TV_HAL: Do Nothing return as HDMI-> default/0 and Othes->0 \n");
    }
    else  /* Copy logic */
    {
        for(sourcesOffset=0;sourcesOffset<MAX_SOURCE_SUPPROTED_FOR_WB;sourcesOffset++)
        {
            int colorTemp;
            for(colorTemp=0;colorTemp<tvColorTemp_USER;colorTemp++)
            {
                int writeFromOffset = sourcesOffset;
                tvDataColor_t wbCriVal = {0};
                readWBFromCridata(sourceIdFromOffset(sourcesOffset),colorTemp,&wbCriVal);

                if(sd3Valuestatus[sourcesOffset] == ZERO_IN_ALL_TEMP&&
                    sourcesOffset != HDMI_OFFSET)
                        writeFromOffset = HDMI_OFFSET;

                if(!areEqual(*(wbSD3Dump+writeFromOffset+colorTemp),wbCriVal))
                {
                    printf("TV_HAL:Copying to Cridata %s(%d)  %s(%d) \n",sourceOffsetString[sourcesOffset],sourcesOffset,colorTempString[colorTemp],colorTemp);
                    tvwriteCRIdataBySource((tvColorTemp_t)colorTemp,
                                            *(wbSD3Dump+(writeFromOffset*MAX_SOURCE_SUPPROTED_FOR_WB+colorTemp)),
                                            sourceIdFromOffset(sourcesOffset));
                }
                else{
                     printf("TV_HAL: Not Copying as SD3=Cridata %s(%d)  %s(%d) \n",
                            sourceOffsetString[sourcesOffset],sourcesOffset,colorTempString[colorTemp],colorTemp);
                }
            }

        }
    }
    free(wbSD3Dump);
    printf("TV_HAL: Exit %s \n",__FUNCTION__);
}

/*****
  HAL call to set white balance value for specific color temperature, control, color values
Params: colortemp - color temperature value(normal,cool,warm)
color - color values (red, blue or green)
ctrl - control values (gain or offset)
value - value for selective colortemp,color and ctrl
 *****/
tvError_t setWBctrl(char *inputSrc, char *colorTemp,char *color, char *ctrl, int value)
{
	tvColorTemp_t clrTempValue = tvColorTemp_MAX;
	tvError_t error = tvERROR_NONE;
#ifdef SUPPORT_WB_CONTROL_ALL
        fp_mfrColorTemp_t mfrTempValue = mfrColorTemp_MAX;
#endif
	printf("Inside setWBctrl \n");
	if ((colorTemp == NULL) || (color == NULL )|| (ctrl == NULL)){
		printf("%s:%d Input paramter is invalid\n", __func__, __LINE__);
		error =  tvERROR_INVALID_STATE;
	} else {
#ifdef SUPPORT_WB_CONTROL_CUSTOM_ONLY
		if (strcmp(inputSrc,"") != 0) {
                        printf("%s:%d source input unsupported \n", __func__, __LINE__);
                        error = tvERROR_INVALID_STATE;
                }
		if(strcmp(colorTemp, "custom") == 0) {
			clrTempValue = tvColorTemp_USER;
		} else {
			printf("%s:%d color temperature is not valid\n",__FUNCTION__, __LINE__);
			error = tvERROR_INVALID_STATE;
		}
#elif SUPPORT_WB_CONTROL_ALL
		/* Color Temperature Validation and update */
		if(strcmp(colorTemp, "normal") == 0) {
			clrTempValue = tvColorTemp_STANDARD;
			mfrTempValue = mfrColorTemp_STANDARD;
		} else if(strcmp(colorTemp, "cool") == 0) {
			clrTempValue = tvColorTemp_COLD;
			mfrTempValue = mfrColorTemp_COLD;
		} else if(strcmp(colorTemp, "warm") == 0) {
			clrTempValue = tvColorTemp_WARM;
			mfrTempValue = mfrColorTemp_WARM;
		} else {
			printf("%s:%d color temperature is not valid\n",__FUNCTION__, __LINE__);
			error = tvERROR_INVALID_STATE;
		}
#endif
	}/* else end */
#ifdef SUPPORT_WB_CONTROL_ALL
        input_source_offset_t inputSource = MAX_OFFSET_NEW;
	if (error == tvERROR_NONE) {
		/* input source validation and update */
		if (strcmp(inputSrc,"") == 0) {
			printf("%s:%d source input is unavailable\n", __func__, __LINE__);
			error = tvERROR_INVALID_STATE;
		} else {
			if(strcmp(inputSrc, "HDMI") == 0) {
				inputSource = HDMI_OFFSET_NEW;
			} else if(strcmp(inputSrc, "TV") == 0) {
				inputSource = TV_OFFSET_NEW;
			} else if(strcmp(inputSrc, "AV") == 0) {
				inputSource = AV_OFFSET_NEW;
			}
			if (MAX_OFFSET_NEW == inputSource) {
				printf("inputSource is not valid\n");
				error = tvERROR_INVALID_STATE;
			}
		}
	}
#endif
	if(error == tvERROR_NONE) {
		/* control and color validation and update */
#if  SUPPORT_WB_CONTROL_CUSTOM_ONLY
		if (clrTempValue != tvColorTemp_MAX ) {
			if (strcmp(ctrl, "gain") == 0){
				if((value  < GAIN_MIN) || ( value  > GAIN_MAX )){
					printf("%s:%d Verification of gain value failed \n", __FUNCTION__, __LINE__);
					error = tvERROR_INVALID_STATE;
				}
			} else if (strcmp(ctrl, "offset") == 0){
				if((value  < OFFSET_MIN ) || ( value  > OFFSET_MAX)) {
					printf("%s:%d Verification of offset value failed \n", __FUNCTION__, __LINE__);
					error = tvERROR_INVALID_STATE;
				}
			}
		}
#elif SUPPORT_WB_CONTROL_ALL
		if (clrTempValue != tvColorTemp_MAX && inputSource != MAX_OFFSET_NEW){
			if (strcmp(ctrl, "gain") == 0){
				if((value  < GAIN_MIN) || ( value  > GAIN_MAX )){
					printf("%s:%d Verification of gain value failed \n", __FUNCTION__, __LINE__);
					error = tvERROR_INVALID_STATE;
				}
			} else if (strcmp(ctrl, "offset") == 0){
				if((value  < OFFSET_MIN ) || ( value  > OFFSET_MAX)) {
					printf("%s:%d Verification of offset value failed \n", __FUNCTION__, __LINE__);
					error = tvERROR_INVALID_STATE;
				}
			}
		}
#endif
	}
#ifdef SUPPORT_WB_CONTROL_CUSTOM_ONLY
	if(error != tvERROR_INVALID_STATE) {
                int result = 0;
		if (strcmp(ctrl, "gain") == 0) {
			if (strcmp(color, "red") == 0) {
				result = amlPqClient->SetColorTemperatureUser(HDMI_DEFAULT, R_GAIN, 1, value);
			} else if (strcmp(color, "blue") == 0) {
				result = amlPqClient->SetColorTemperatureUser(HDMI_DEFAULT, B_GAIN, 1, value);
			} else if (strcmp(color, "green") == 0) {
				result = amlPqClient->SetColorTemperatureUser(HDMI_DEFAULT, G_GAIN, 1, value);
			}
		} else if (strcmp(ctrl, "offset") == 0) {
			if (strcmp(color, "red") == 0) {
				result = amlPqClient->SetColorTemperatureUser(HDMI_DEFAULT, R_POST_OFFSET, 1, value);
			} else if (strcmp(color, "blue") == 0) {
				result = amlPqClient->SetColorTemperatureUser(HDMI_DEFAULT, B_POST_OFFSET, 1, value);
			} else if (strcmp(color, "green") == 0) {
				result = amlPqClient->SetColorTemperatureUser(HDMI_DEFAULT, G_POST_OFFSET, 1, value);
			} else{
				printf("%s:%d Verification of color failed under offset ctrl \n", __FUNCTION__, __LINE__);
				error = tvERROR_INVALID_STATE;

			}
		} else{
			printf("%s:%d Verification of ctrl failed\n", __FUNCTION__, __LINE__);
			error = tvERROR_INVALID_STATE;
		}
                if(result == -1) {
                    error = tvERROR_GENERAL;
                }
	}
#elif SUPPORT_WB_CONTROL_ALL
	if (error != tvERROR_INVALID_STATE) { /*verification error check*/
		if(inputSource == HDMI_OFFSET_NEW) { /*input source check */
			if(clrTempValue == tvColorTemp_STANDARD) { /* color temp check */
				/* process for all color temp and all inputs*/
				for(int j = HDMI_OFFSET_NEW; j <= AV_OFFSET_NEW; j+=4) {
					for(int i = tvColorTemp_STANDARD; i < tvColorTemp_MAX; i++) {
						/* calculation of mfr enum value for corresponding tv enum value*/
						int mfrTempVal;
						if(i == tvColorTemp_STANDARD)
							mfrTempVal = mfrColorTemp_STANDARD;
						else if(i == tvColorTemp_WARM)
							mfrTempVal = mfrColorTemp_WARM;
						else if(i == tvColorTemp_COLD)
							mfrTempVal = mfrColorTemp_COLD;

						int saveOnly = 1;
						if ((i == tvColorTemp_STANDARD) && (j == HDMI_OFFSET_NEW)) {
							saveOnly = 0;
						}

						if (strcmp(ctrl, "gain") == 0){
							if (strcmp(color, "red") == 0){
								error = SetColorTemp_Rgain_onSource((tvColorTemp_t)i, value, j/4, saveOnly);
								wbValues[j + mfrTempVal].r_gain = value;
							} else if (strcmp(color, "blue") == 0){
								error = SetColorTemp_Bgain_onSource((tvColorTemp_t)i, value, j/4, saveOnly);
								wbValues[j + mfrTempVal].b_gain = value;
							} else if (strcmp(color, "green") == 0){
								error = SetColorTemp_Ggain_onSource((tvColorTemp_t)i, value, j/4, saveOnly);
								wbValues[j + mfrTempVal].g_gain = value;
							}
						} else if (strcmp(ctrl, "offset") == 0) {
							if (strcmp(color, "red") == 0){
								error = SetColorTemp_R_post_offset_onSource((tvColorTemp_t)i, value, j/4, saveOnly);
								wbValues[j + mfrTempVal].r_offset = value;
							} else if (strcmp(color, "blue") == 0){
								error = SetColorTemp_B_post_offset_onSource((tvColorTemp_t)i, value, j/4, saveOnly);
								wbValues[j + mfrTempVal].b_offset = value;
							} else if (strcmp(color, "green") == 0){
								error = SetColorTemp_G_post_offset_onSource((tvColorTemp_t)i, value, j/4, saveOnly);
								wbValues[j + mfrTempVal].g_offset = value;
							} else{
								printf("%s:%d Verification of color failed under offset ctrl \n", __FUNCTION__, __LINE__);
								error = tvERROR_INVALID_STATE;
							}
						} else{
							printf("%s:%d Verification of ctrl failed\n", __FUNCTION__, __LINE__);
							error = tvERROR_INVALID_STATE;
						}
					}
				}
			} else {
				/* color temp is not standard, hence process for particular color temp and all inputs */
				for(int j = HDMI_OFFSET_NEW; j <= AV_OFFSET_NEW; j+=4) {
					int saveOnly = 1;
					if (j == HDMI_OFFSET_NEW) {
						saveOnly = 0;
					}

					if (strcmp(ctrl, "gain") == 0){
						if (strcmp(color, "red") == 0){
							error = SetColorTemp_Rgain_onSource(clrTempValue, value, j/4, saveOnly);
							wbValues[j + mfrTempValue].r_gain = value;
						} else if (strcmp(color, "blue") == 0){
							error = SetColorTemp_Bgain_onSource(clrTempValue, value, j/4, saveOnly);
							wbValues[j + mfrTempValue].b_gain = value;
						} else if (strcmp(color, "green") == 0){
							error = SetColorTemp_Ggain_onSource(clrTempValue, value, j/4, saveOnly);
							wbValues[j + mfrTempValue].g_gain = value;
						}
					} else if (strcmp(ctrl, "offset") == 0) {
						if (strcmp(color, "red") == 0){
							error = SetColorTemp_R_post_offset_onSource(clrTempValue, value, j/4, saveOnly);
							wbValues[j + mfrTempValue].r_offset = value;
						} else if (strcmp(color, "blue") == 0){
							error = SetColorTemp_B_post_offset_onSource(clrTempValue, value, j/4, saveOnly);
							wbValues[j + mfrTempValue].b_offset = value;
						} else if (strcmp(color, "green") == 0){
							error = SetColorTemp_G_post_offset_onSource(clrTempValue, value, j/4, saveOnly);
							wbValues[j + mfrTempValue].g_offset = value;
						} else{
							printf("%s:%d Verification of color failed under offset ctrl \n", __FUNCTION__, __LINE__);
							error = tvERROR_INVALID_STATE;
						}
					} else{
						printf("%s:%d Verification of ctrl failed\n", __FUNCTION__, __LINE__);
						error = tvERROR_INVALID_STATE;
					}

				}
			}
		} else {
			/* input source is not HDMI, hence process for particular input */
			printf("calculation of offset for particular source\n");
			if(clrTempValue == tvColorTemp_STANDARD) {
				/* process for all color temp and all inputs*/
				for(int i = tvColorTemp_STANDARD; i < tvColorTemp_MAX; i++) {
					/* calculation of mfr enum value for corresponding tv enum value*/
					int mfrTempVal;
					if(i == tvColorTemp_STANDARD)
						mfrTempVal = mfrColorTemp_STANDARD;
					else if(i == tvColorTemp_WARM)
						mfrTempVal = mfrColorTemp_WARM;
					else if(i == tvColorTemp_COLD)
						mfrTempVal = mfrColorTemp_COLD;

					int saveOnly = 1;
					if (i == tvColorTemp_STANDARD) {
						saveOnly = 0;
					}

					if (strcmp(ctrl, "gain") == 0){
						if (strcmp(color, "red") == 0){
							error = SetColorTemp_Rgain_onSource((tvColorTemp_t)i, value, inputSource/4, saveOnly);
							wbValues[inputSource + mfrTempVal].r_gain = value;
						} else if (strcmp(color, "blue") == 0){
							error = SetColorTemp_Bgain_onSource((tvColorTemp_t)i, value, inputSource/4, saveOnly);
							wbValues[inputSource + mfrTempVal].b_gain = value;
						} else if (strcmp(color, "green") == 0){
							error = SetColorTemp_Ggain_onSource((tvColorTemp_t)i, value, inputSource/4, saveOnly);
							wbValues[inputSource + mfrTempVal].g_gain = value;
						} else{
							printf("%s:%d Verification of color failed under gain ctrl\n", __FUNCTION__, __LINE__);
							error = tvERROR_INVALID_STATE;
						}
					} else if (strcmp(ctrl, "offset") == 0) {
						if (strcmp(color, "red") == 0){
							error = SetColorTemp_R_post_offset_onSource((tvColorTemp_t)i, value, inputSource/4, saveOnly);
							wbValues[inputSource + mfrTempVal].r_offset = value;
						} else if (strcmp(color, "blue") == 0){
							error = SetColorTemp_B_post_offset_onSource((tvColorTemp_t)i, value, inputSource/4, saveOnly);
							wbValues[inputSource + mfrTempVal].b_offset = value;
						} else if (strcmp(color, "green") == 0){
							error = SetColorTemp_G_post_offset_onSource((tvColorTemp_t)i, value, inputSource/4, saveOnly);
							wbValues[inputSource + mfrTempVal].g_offset = value;
						} else{
							printf("%s:%d Verification of color failed under offset ctrl \n", __FUNCTION__, __LINE__);
							error = tvERROR_INVALID_STATE;
						}
					} else{
						printf("%s:%d Verification of ctrl failed\n", __FUNCTION__, __LINE__);
						error = tvERROR_INVALID_STATE;
					}
				}
			} else {
				int saveOnly = 1;

				/*process for particular color temp*/
				if (strcmp(ctrl, "gain") == 0){
					if (strcmp(color, "red") == 0){
						error = SetColorTemp_Rgain_onSource(clrTempValue, value, inputSource/4, saveOnly);
						wbValues[inputSource + mfrTempValue].r_gain = value;
					} else if (strcmp(color, "blue") == 0){
						error = SetColorTemp_Bgain_onSource(clrTempValue, value, inputSource/4, saveOnly);
						wbValues[inputSource + mfrTempValue].b_gain = value;
					} else if (strcmp(color, "green") == 0){
						error = SetColorTemp_Ggain_onSource(clrTempValue, value, inputSource/4, saveOnly);
						wbValues[inputSource + mfrTempValue].g_gain = value;
					} else{
						printf("%s:%d Verification of color failed under gain ctrl\n", __FUNCTION__, __LINE__);
						error = tvERROR_INVALID_STATE;
					}
				} else if (strcmp(ctrl, "offset") == 0) {
					if (strcmp(color, "red") == 0){
						error = SetColorTemp_R_post_offset_onSource(clrTempValue, value, inputSource/4, saveOnly);
						wbValues[inputSource + mfrTempValue].r_offset = value;
					} else if (strcmp(color, "blue") == 0){
						error = SetColorTemp_B_post_offset_onSource(clrTempValue, value, inputSource/4, saveOnly);
						wbValues[inputSource + mfrTempValue].b_offset = value;
					} else if (strcmp(color, "green") == 0){
						error = SetColorTemp_G_post_offset_onSource(clrTempValue, value, inputSource/4, saveOnly);
						wbValues[inputSource + mfrTempValue].g_offset = value;
					} else{
						printf("%s:%d Verification of color failed under offset ctrl \n", __FUNCTION__, __LINE__);
						error = tvERROR_INVALID_STATE;
					}
				} else{
					printf("%s:%d Verification of ctrl failed\n", __FUNCTION__, __LINE__);
					error = tvERROR_INVALID_STATE;
				}
			}
		}
	} else{/*if(ret != tvERROR_INVALID_STATE) ends */
		printf("%s:%d Verification error occured\n", __FUNCTION__, __LINE__);
	}
#endif
	return error;
}

/*****
  HAL call to get white balance value for specific color temperature, control, color values
Params: colortemp - color temperature value
color - color values (red, blue or green)
ctrl - control values (gain or offset)
value - pointer to store value which will be returned by driver
 *****/
tvError_t getWBctrl(char *inputSrc, char *colortemp, char *color, char *ctrl, int *value)
{
	tvColorTemp_t clrTempValue = tvColorTemp_MAX;
	tvError_t result = tvERROR_NONE;
	printf("Inside getWBctrl \n");
	if(colortemp == NULL || color == NULL || ctrl == NULL) {
		printf("%s:%d Input parameter validation failed \n", __FUNCTION__, __LINE__);
		result = tvERROR_INVALID_STATE;
	} else {
#ifdef SUPPORT_WB_CONTROL_CUSTOM_ONLY
		if (strcmp(inputSrc,"") != 0) {
                        printf("%s:%d source input unsupported in llama\n", __func__, __LINE__);
                        result = tvERROR_INVALID_STATE;
                }
		if(strcmp(colortemp, "custom") == 0) {
			clrTempValue = tvColorTemp_USER;
		} else {
			printf("%s:%d unable to set color temperature enum value \n",__FUNCTION__, __LINE__);
			result = tvERROR_INVALID_STATE;
		}
#elif SUPPORT_WB_CONTROL_ALL
		if(strcmp(colortemp, "normal") == 0) {
			clrTempValue = tvColorTemp_STANDARD;
		} else if(strcmp(colortemp, "cool") == 0) {
			clrTempValue = tvColorTemp_COLD;
		} else if(strcmp(colortemp, "warm") == 0) {
			clrTempValue = tvColorTemp_WARM;
		} else {
			printf("%s:%d unable to set color temperature enum value \n",__FUNCTION__, __LINE__);
			result = tvERROR_INVALID_STATE;
		}
#endif
	}
#ifdef  SUPPORT_WB_CONTROL_ALL
        input_source_offset_t inputSource = MAX_OFFSET_NEW;
	if (result == tvERROR_NONE) {
		/* input source validation and update */
		if (strcmp(inputSrc,"") == 0) {
			printf("%s:%d source input is unavailable\n", __func__, __LINE__);
			result = tvERROR_INVALID_STATE;
		} else {
			if(strcmp(inputSrc, "HDMI") == 0) {
                                inputSource = HDMI_OFFSET_NEW;
                        } else if(strcmp(inputSrc, "TV") == 0) {
                                inputSource = TV_OFFSET_NEW;
                        } else if(strcmp(inputSrc, "AV") == 0) {
                                inputSource = AV_OFFSET_NEW;
                        }
			if (MAX_OFFSET_NEW == inputSource) {
				printf("inputSource is not valid\n");
				result = tvERROR_INVALID_STATE;
			}
		}
	}
#endif
	if(result != tvERROR_INVALID_STATE) {
#ifdef SUPPORT_WB_CONTROL_CUSTOM_ONLY

		if(clrTempValue != tvColorTemp_MAX) {
			if(strcmp(ctrl, "gain") == 0) {
				if(strcmp(color, "red") == 0) {
                                        result = GetColorTemp_Rgain_onSource(clrTempValue, value, HDMI_DEFAULT);
				} else if(strcmp(color, "green") == 0) {
                                        result = GetColorTemp_Ggain_onSource(clrTempValue, value, HDMI_DEFAULT);
				} else if(strcmp(color, "blue") == 0) {
                                        result = GetColorTemp_Bgain_onSource(clrTempValue, value, HDMI_DEFAULT);
				} else {
					printf("%s:%d Verification of color failed under gain ctrl value \n", __FUNCTION__, __LINE__);
					result = tvERROR_INVALID_STATE;
				}
			} else if(strcmp(ctrl, "offset") == 0) {
				if(strcmp(color, "red") == 0) {
                                        result = GetColorTemp_R_post_offset_onSource(clrTempValue, value, HDMI_DEFAULT);
				} else if(strcmp(color, "green") == 0) {
					result = GetColorTemp_G_post_offset_onSource(clrTempValue, value, HDMI_DEFAULT);
				} else if(strcmp(color, "blue") == 0) {
					result = GetColorTemp_B_post_offset_onSource(clrTempValue, value, HDMI_DEFAULT);
				} else {
					printf("%s:%d Verification of color failed under offset ctrl value \n", __FUNCTION__, __LINE__);
					result = tvERROR_INVALID_STATE;
				}
			} else {
				printf("%s:%d Verification of ctrl failed \n", __FUNCTION__, __LINE__);
				result = tvERROR_INVALID_STATE;
			}
		}

#elif SUPPORT_WB_CONTROL_ALL
		if(clrTempValue != tvColorTemp_MAX && inputSource != MAX_OFFSET_NEW) {
			if(strcmp(ctrl, "gain") == 0) {
				if(strcmp(color, "red") == 0) {
					result = GetColorTemp_Rgain_onSource(clrTempValue, value, inputSource/4);
				} else if(strcmp(color, "green") == 0) {
					result = GetColorTemp_Ggain_onSource(clrTempValue, value, inputSource/4);
				} else if(strcmp(color, "blue") == 0) {
					result = GetColorTemp_Bgain_onSource(clrTempValue, value, inputSource/4);
				} else {
					printf("%s:%d Verification of color failed under gain ctrl value \n", __FUNCTION__, __LINE__);
					result = tvERROR_INVALID_STATE;
				}
			} else if(strcmp(ctrl, "offset") == 0) {
				if(strcmp(color, "red") == 0) {
					result = GetColorTemp_R_post_offset_onSource(clrTempValue, value, inputSource/4);
				} else if(strcmp(color, "green") == 0) {
					result = GetColorTemp_G_post_offset_onSource(clrTempValue, value, inputSource/4);
				} else if(strcmp(color, "blue") == 0) {
					result = GetColorTemp_B_post_offset_onSource(clrTempValue, value, inputSource/4);;
				} else {
					printf("%s:%d Verification of color failed under offset ctrl value \n", __FUNCTION__, __LINE__);
					result = tvERROR_INVALID_STATE;
				}
			} else {
				printf("%s:%d Verification of ctrl failed \n", __FUNCTION__, __LINE__);
				result = tvERROR_INVALID_STATE;
			}
		}
#endif
	}
	return result;

}


mfrSerializedType_t getParamType(int i)
{
	if(i == 0) {
		printf("HDMI normal\n");
		return mfrSERIALIZED_TYPE_SKY_PANEL_HDMI_WB_DATA_NORMAL;
	} else if(i == 1) {
		printf("HDMI cold\n");
		return mfrSERIALIZED_TYPE_SKY_PANEL_HDMI_WB_DATA_COLD;
	} else if(i == 2) {
		printf("HDMI warm\n");
		return mfrSERIALIZED_TYPE_SKY_PANEL_HDMI_WB_DATA_WARM;
	} else if(i == 3) {
		printf("HDMI user\n");
		return mfrSERIALIZED_TYPE_SKY_PANEL_HDMI_WB_DATA_USER;
	} else if(i == 4) {
		printf("TV normal\n");
		return mfrSERIALIZED_TYPE_SKY_PANEL_TV_WB_DATA_NORMAL;
	} else if(i == 5) {
		printf("TV cold\n");
		return mfrSERIALIZED_TYPE_SKY_PANEL_TV_WB_DATA_COLD;
	} else if(i == 6) {
		printf("TV warm\n");
		return mfrSERIALIZED_TYPE_SKY_PANEL_TV_WB_DATA_WARM;
	} else if(i == 7) {
		printf("TV user\n");
		return mfrSERIALIZED_TYPE_SKY_PANEL_TV_WB_DATA_USER;
	} else if(i == 8) {
		printf("AV normal\n");
		return mfrSERIALIZED_TYPE_SKY_PANEL_AV_WB_DATA_NORMAL;
	} else if(i == 9) {
		printf("AV cold\n");
		return mfrSERIALIZED_TYPE_SKY_PANEL_AV_WB_DATA_COLD;
	} else if(i == 10) {
		printf("AV warm\n");
		return mfrSERIALIZED_TYPE_SKY_PANEL_AV_WB_DATA_WARM;
	} else if(i == 11) {
		printf("AV user\n");
		return mfrSERIALIZED_TYPE_SKY_PANEL_AV_WB_DATA_USER;
        } else
                return mfrSERIALIZED_TYPE_SKY_PANEL_HDMI_WB_DATA_NORMAL;
}

tvError_t getWbInfo(getWBInfo_t* params, std::vector<std::string> &selector
		, std::vector<std::string> &colorTmp, std::vector<std::string> &input)
{
    tvError_t ret = tvERROR_NONE;
#ifdef SUPPORT_WB_CONTROL_ALL
    selector.push_back("color temp");
    selector.push_back("input");
    colorTmp.push_back("cool");
    colorTmp.push_back("normal");
    colorTmp.push_back("warm");
    input.push_back("HDMI");
    input.push_back("TV");
    input.push_back("AV");
#elif SUPPORT_WB_CONTROL_CUSTOM_ONLY
    selector.push_back("color temp");
    colorTmp.push_back("custom");
#endif
    strcpy(params->wbControls[0], "gain");
    strcpy(params->wbControls[1], "offset");
    strcpy(params->wbGain[0], "0");
    strcpy(params->wbGain[1], "2047");
    strcpy(params->wbOffset[0], "-1024");
    strcpy(params->wbOffset[1], "1023");
    return ret;
}


#ifdef SUPPORT_WB_CONTROL_CUSTOM_ONLY
void setLDMin(const char* enable)
{
	FILE *fptr;
        unsigned int wlen = 0;
	fptr = fopen(SET_LDIM, "wb");
	if (fptr == NULL) {
		printf("Error : File Open\n");
	} else {
		wlen = strlen(enable);
		if(wlen != fwrite(enable,1,wlen,fptr)) {
			printf("fwrite failed\n");
		} else {
			printf("fwrite is success\n");
		}
	}
}
#endif

int TVWriteSysfs(const char *path, const char * cmd)
{
    int fd;
    int err=0;
    fd = open(path, O_CREAT|O_RDWR | O_TRUNC, 0777);

    if (fd >= 0) {
        write(fd,cmd,strlen(cmd));
        close(fd);
        printf("TVWriteSysfs %s %s Success\n",path,cmd);
    }
    else
    {
        printf("TVWriteSysfs %s %s Failed\n",path,cmd);
        err=-1;
    }

    return err;
}


tvError_t enableWBmode(bool value)
{
    tvError_t ret = tvERROR_NONE;
    int err = 0;

    if(NULL==amlPqClient)
        ret = tvERROR_INVALID_STATE;
    else{
        if(value)
        {
            err = amlPqClient->SetDynamicBacklight(0,0);
            err|=TVWriteSysfs("/sys/class/amvecm/lc", "lc disable");
            err|=TVWriteSysfs("/sys/class/amvecm/debug", "dnlp disable");

        }else {
            err = amlPqClient->SetDynamicBacklight(1,0);
            err |=TVWriteSysfs("/sys/class/amvecm/lc"," lc enable");
            err |=TVWriteSysfs("/sys/class/amvecm/debug", "dnlp enable");

        }
        if(err!=0)
            ret = tvERROR_GENERAL;
    }

	return ret;
}

tvError_t GetTVSupportedDimmingModes(char **dimmingModes,unsigned short *count) {
    tvError_t ret = tvERROR_NONE;

    if(amlPqClient == NULL && supportedDimmingModes != NULL)
        return tvERROR_INVALID_STATE;

    if(numberDimmingModes)
        *dimmingModes  = supportedDimmingModes;
    else
        *dimmingModes = NULL;

    *count = numberDimmingModes;
    if(0 == *count)
    {
        ret = tvERROR_GENERAL;
    }
    return ret;
}

bool isSupportedDimmingMode(const char *dimmingMode)
{
    bool status = false;
    for(int i=0;i<numberDimmingModes;i++)
    {
        if(0==strncmp(dimmingMode,supportedDimmingModes+(i*DIMMING_MODE_NAME_SIZE),DIMMING_MODE_NAME_SIZE))
        {
            status = true;
            break;
        }
    }

    return status;
}
tvError_t SetTVDimmingMode(const char *dimmingMode) {
    tvError_t ret = tvERROR_NONE;
    int err = 0;

    if(amlPqClient == NULL && supportedDimmingModes != NULL)
        return tvERROR_INVALID_STATE;

    printf("TV_HAL:(%s): Setting up the  mode %s !!!\n",__func__,dimmingMode);

    if(isSupportedDimmingMode(dimmingMode))
    {
        if( 0 != strncmp(currentDimmingMode,dimmingMode,strlen(dimmingMode)))
        {   
            /* Turn on and off the Global and Local backlight dimming mode based on the input "dimmingMode"*/
            if(0 == strncmp(dimmingMode,"global",strlen("global"))){
                err = amlPqClient->SetDynamicBacklight(2,0);
            }else if(0 == strncmp(dimmingMode,"fixed",strlen("fixed"))){
                err = amlPqClient->SetDynamicBacklight(0,0);
            }else if(0 == strncmp(dimmingMode,"local",strlen("local"))){
                err = amlPqClient->SetDynamicBacklight(1,0);
            }
            
            if( err == 0 ){
                printf("TV_HAL:(%s): Setting up the dimming mode success !!!\n",__func__);
                strncpy(currentDimmingMode,dimmingMode,DIMMING_MODE_NAME_SIZE);
            }else{
                printf("TV_HAL:(%s): Setting up the dimming mode Failed !!!\n",__func__);
                ret = tvERROR_GENERAL;
            }
        }
        else
        {
            printf("TV_HAL:(%s): Same as previous dimming mode !!!\n",__func__);
        }
    }
    else
    {
        printf("TV_HAL:(%s): Unsupported Dimming mode %s !!!\n",__func__,dimmingMode);
        ret = tvERROR_INVALID_PARAM;
    }
    return ret;
}


/**
 * @fn GetSupportedSaturationColor
 * @brief This function get the supported saturation color from the driver
 *
 * @param[0ut]*blSaturationColor indicates the  pointer
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 *                 in case of default : default value
 **/

tvError_t GetSupportedComponentColor(int *blComponentColor)
{

#ifndef HAS_CMS_SUPPORT
   tvError_t ret = tvERROR_OPERATION_NOT_SUPPORTED;
   printf("%s:%d : Not Supported \n", __FUNCTION__,__LINE__);
#else
   tvError_t ret = tvERROR_NONE;
   if(amlPqClient == NULL)
      return tvERROR_INVALID_STATE;

    *blComponentColor = 0;
    *blComponentColor |= tvDataColor_RED;
    *blComponentColor |= tvDataColor_GREEN;
    *blComponentColor |= tvDataColor_BLUE;
    *blComponentColor |= tvDataColor_YELLOW;
    *blComponentColor |= tvDataColor_CYAN;
    *blComponentColor |= tvDataColor_MAGENTA;
#endif
    return ret;

}
/**
 * @fn SetCurrentComponentSaturation
 * @brief This function set the saturation color to the driver
 *
 * @param[IN]blSaturationColor indicates color to set
 * @param[IN]saturation indicates value to set
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 *                 in case of default : default value
 **/
tvError_t SetCurrentComponentSaturation(tvDataComponentColor_t blSaturationColor, int saturation)
{
   tvError_t ret = tvERROR_NONE;
   int cms_color_type = 0;
   int err =0;

   if((saturation < 0) || (saturation > 100)) {
        return tvERROR_INVALID_PARAM;
    }
   if(amlPqClient == NULL)
      return tvERROR_INVALID_STATE;

   switch(blSaturationColor){
      case tvDataColor_RED:
          cms_color_type = COLOR_RED;
          break;
      case tvDataColor_GREEN:
          cms_color_type = COLOR_GREEN;
          break;
      case tvDataColor_BLUE:
           cms_color_type = COLOR_BLUE;
          break;
      case tvDataColor_CYAN:
           cms_color_type = COLOR_CYAN;
          break;
      case tvDataColor_MAGENTA:
           cms_color_type = COLOR_MAGENTA;
          break;
      case tvDataColor_YELLOW:
          cms_color_type = COLOR_YELLOW;
          break;
      default:
        break;
   }

   err = amlPqClient->SetCMS(2/*COLOR_SATURATION*/,cms_color_type,saturation,SAVEPARAM);
   if(err == -1) {
    ret = tvERROR_GENERAL;
   }
   return ret;
}
/**
+ * @fn GetCurrentComponentSaturation
 * @brief This function get the supported saturation color value from the driver
 *
 * @param[IN]blSaturationColor indicates color to get
 * @param[0ut]*blSaturationColor indicates the  pointerfor the value
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 *                 in case of default : default value
 **/


tvError_t GetCurrentComponentSaturation(tvDataComponentColor_t blSaturationColor, int *saturation)
{
#ifndef HAS_CMS_SUPPORT
   tvError_t ret = tvERROR_OPERATION_NOT_SUPPORTED;
   printf("%s:%d : Not Supported \n", __FUNCTION__,__LINE__);
#else 
   tvError_t ret = tvERROR_NONE;
   int cms_color_type = 0;

   if(amlPqClient == NULL)
      return tvERROR_INVALID_STATE;
   switch(blSaturationColor){
     case tvDataColor_RED:
          cms_color_type = COLOR_RED;
          break;
      case tvDataColor_GREEN:
          cms_color_type = COLOR_GREEN;
          break;
      case tvDataColor_BLUE:
          cms_color_type = COLOR_BLUE;
          break;
      case tvDataColor_CYAN:
          cms_color_type = COLOR_CYAN;
          break;
      case tvDataColor_MAGENTA:
           cms_color_type = COLOR_MAGENTA;
          break;
      case tvDataColor_YELLOW:
          cms_color_type = COLOR_YELLOW;
          break;
      default:
        break;
   }
   *saturation = amlPqClient->GetCMS(2/*COLOR_SATURATION*/,cms_color_type);
#endif
   return ret;
}

tvError_t SetTVBacklightGlobalFactor(int value,int rangeMidPointValue)
{
    tvError_t ret = tvERROR_NONE;

    ret = TVUpdateRawBacklight(value,rangeMidPointValue);
    if(ret == tvERROR_NONE) {
        backlightFactor = value;
        backlightFactorRangeMid = rangeMidPointValue;
    }
    return ret;
}
tvError_t TVUpdateRawBacklight(int value,int midPointValue)
{
    int backlight=0;
    int rawBacklight = 0;
    tvError_t ret =tvERROR_NONE;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    if(isCurrentHDRTypeIsSDR())
    {
        backlight = allBacklightInfo.sdrBLCurve[allBacklightInfo.defaultBLSDR];
    }else
    {
        backlight = allBacklightInfo.hdrBLCurve[allBacklightInfo.defaultBLHDR];
    }
    rawBacklight = (backlight*value)/midPointValue;
    printf("TVHAL: backlight :%d rawBacklight: %d \n",backlight,rawBacklight);
    int err = amlPqClient->SetBacklightRaw(rawBacklight,0);
    if(err == -1) {
        ret = tvERROR_GENERAL;
    }

    return ret;
}

tvError_t GetTVBacklightGlobalFactor(int * value)
{
    tvError_t ret = tvERROR_NONE;
    *value = backlightFactor;
    return ret;
}

tvPictureMode_t GetTVPictureModeIndex(const char * pictureMode)
{
  return getPicModeEnum(pictureMode);
}

tvVideoHDRFormat_t GetCurrentContentFormat(void)
{
    return m_currentVideoFormat;
}

tvError_t GetSupportedContentFormats(unsigned int * contentFormats,unsigned short *numberOfFormats)
{
    *contentFormats = 0;
    *contentFormats |= tvVideoHDRFormat_SDR;
    *contentFormats |= tvVideoHDRFormat_HDR10;
    *contentFormats |= tvVideoHDRFormat_HLG;
    *contentFormats |= tvVideoHDRFormat_DV;
    * numberOfFormats  = 4;
    return tvERROR_NONE;
}

tvError_t ResetBrightness(int defaultValue,bool resetForAllFormats) {
    tvError_t ret = tvERROR_NONE;
    int err = 0;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

   err = amlPqClient->ResetBrightness(defaultValue,resetForAllFormats);
   if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    return ret;
}

tvError_t ResetContrast(int defaultValue,bool resetForAllFormats) {
    tvError_t ret = tvERROR_NONE;
    int err = 0;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

   err = amlPqClient->ResetContrast(defaultValue,resetForAllFormats);
   if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    return ret;
}

tvError_t ResetSharpness(int defaultValue,bool resetForAllFormats) {
    tvError_t ret = tvERROR_NONE;
    int err = 0;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

   err = amlPqClient->ResetSharpness(defaultValue,resetForAllFormats);
   if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    return ret;
}

tvError_t ResetSaturation(int defaultValue,bool resetForAllFormats) {
    tvError_t ret = tvERROR_NONE;
    int err = 0;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

   err = amlPqClient->ResetSaturation(defaultValue,resetForAllFormats);
   if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    return ret;
}

tvError_t ResetHue(int defaultValue,bool resetForAllFormats) {
    tvError_t ret = tvERROR_NONE;
    int err = 0;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

   err = amlPqClient->ResetHue(defaultValue,resetForAllFormats);
   if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    return ret;
}

tvError_t ResetBacklight(int defaultValue,bool resetForAllFormats) {
    tvError_t ret = tvERROR_NONE;
    int err = 0;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

   err = amlPqClient->ResetBacklight(defaultValue,resetForAllFormats);
   if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    return ret;
}

tvError_t ResetColorTemperature(int defaultValue,bool resetForAllFormats) {
    tvError_t ret = tvERROR_NONE;
    int err = 0;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

   err = amlPqClient->ResetColorTemperature(defaultValue,resetForAllFormats);
   if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    return ret;
}

/**
 * @fn SetCurrentComponentHue
 * @brief This function set the hue color to the driver
 *
 * @param[IN]blHueColor indicates color to set
 * @param[IN]hue indicates value to set
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 *                 in case of default : default value
 **/
tvError_t SetCurrentComponentHue(tvDataComponentColor_t blHueColor, int hue)
{
   tvError_t ret = tvERROR_NONE;
   int cms_color_type = 0;
   int err =0;

   if((hue < 0) || (hue > 100)) {
        return tvERROR_INVALID_PARAM;
    }

   if(amlPqClient == NULL)      return tvERROR_INVALID_STATE;

   switch(blHueColor){
      case tvDataColor_RED:
          cms_color_type = COLOR_RED;
          break;
      case tvDataColor_GREEN:
          cms_color_type = COLOR_GREEN;
          break;
      case tvDataColor_BLUE:
           cms_color_type = COLOR_BLUE;
          break;
      case tvDataColor_CYAN:
           cms_color_type = COLOR_CYAN;
          break;
      case tvDataColor_MAGENTA:
           cms_color_type = COLOR_MAGENTA;
          break;
      case tvDataColor_YELLOW:
          cms_color_type = COLOR_YELLOW;
          break;
      default:
        break;
   }

   err = amlPqClient->SetCMS(1/*COLOR_HUE*/,cms_color_type,hue,SAVEPARAM);
   if(err == -1) {
    ret = tvERROR_GENERAL;
   }
   return ret;
}
/**
+ * @fn GetCurrentComponentHue
 * @brief This function get the supported hue color value from the driver
 *
 * @param[IN]blHueColor indicates color to get
 * @param[0ut]*blHueColor indicates the  pointerfor the value
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 *                 in case of default : default value
 **/


tvError_t GetCurrentComponentHue(tvDataComponentColor_t blHueColor, int *hue)
{
#ifndef HAS_CMS_SUPPORT
   tvError_t ret = tvERROR_OPERATION_NOT_SUPPORTED;
   printf("%s:%d : Not Supported \n", __FUNCTION__,__LINE__);
#else
   tvError_t ret = tvERROR_NONE;
   int cms_color_type = 0;

   if(amlPqClient == NULL)
      return tvERROR_INVALID_STATE;
   switch(blHueColor){
     case tvDataColor_RED:
          cms_color_type = COLOR_RED;
          break;
      case tvDataColor_GREEN:
          cms_color_type = COLOR_GREEN;
          break;
      case tvDataColor_BLUE:
          cms_color_type = COLOR_BLUE;
          break;
      case tvDataColor_CYAN:
          cms_color_type = COLOR_CYAN;
          break;
      case tvDataColor_MAGENTA:
           cms_color_type = COLOR_MAGENTA;
          break;
      case tvDataColor_YELLOW:
          cms_color_type = COLOR_YELLOW;
          break;
      default:
        break;
   }
   *hue = amlPqClient->GetCMS(1/*COLOR_HUE*/,cms_color_type);
#endif
   return ret;
}

/**
 * @fn SetCurrentComponentLuma
 * @brief This function set the luma color to the driver
 *
 * @param[IN]blLumaColor indicates color to set
 * @param[IN]luma indicates value to set
 * @param[IN]luma indicates value to set
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 *                 in case of default : default value
 **/
tvError_t SetCurrentComponentLuma(tvDataComponentColor_t blLumaColor, int luma)
{
   tvError_t ret = tvERROR_NONE;
   int cms_color_type = 0;
   int err =0;

   if((luma < 0) || (luma > 30)) {
        return tvERROR_INVALID_PARAM;
    }

   if(amlPqClient == NULL)      return tvERROR_INVALID_STATE;

   switch(blLumaColor){
      case tvDataColor_RED:
          cms_color_type = COLOR_RED;
          break;
      case tvDataColor_GREEN:
          cms_color_type = COLOR_GREEN;
          break;
      case tvDataColor_BLUE:
           cms_color_type = COLOR_BLUE;
          break;
      case tvDataColor_CYAN:
           cms_color_type = COLOR_CYAN;
          break;
      case tvDataColor_MAGENTA:
           cms_color_type = COLOR_MAGENTA;
          break;
      case tvDataColor_YELLOW:
          cms_color_type = COLOR_YELLOW;
          break;
      default:
        break;
   }

   err = amlPqClient->SetCMS(3/*COLOR_LUMA*/,cms_color_type,luma,SAVEPARAM);
   if(err == -1) {
    ret = tvERROR_GENERAL;
   }
   return ret;
}
/**
+ * @fn GetCurrentComponentLuma
 * @brief This function get the supported luma color value from the driver
 *
 * @param[IN]blLumaColor indicates color to get
 * @param[0ut]*blLumaColor indicates the  pointerfor the value
 *
 * @return Returns on success : no error
 *                 if amlPqClient is null : invalid state
 *                 in case of default : default value
 **/


tvError_t GetCurrentComponentLuma(tvDataComponentColor_t blLumaColor, int *luma)
{
#ifndef HAS_CMS_SUPPORT
   tvError_t ret = tvERROR_OPERATION_NOT_SUPPORTED;
   printf("%s:%d : Not Supported \n", __FUNCTION__,__LINE__);
#else
   tvError_t ret = tvERROR_NONE;
   int cms_color_type = 0;

   if(amlPqClient == NULL)
      return tvERROR_INVALID_STATE;
   switch(blLumaColor){
     case tvDataColor_RED:
          cms_color_type = COLOR_RED;
          break;
      case tvDataColor_GREEN:
          cms_color_type = COLOR_GREEN;
          break;
      case tvDataColor_BLUE:
          cms_color_type = COLOR_BLUE;
          break;
      case tvDataColor_CYAN:
          cms_color_type = COLOR_CYAN;
          break;
      case tvDataColor_MAGENTA:
           cms_color_type = COLOR_MAGENTA;
          break;
      case tvDataColor_YELLOW:
          cms_color_type = COLOR_YELLOW;
          break;
      default:
        break;
   }
   *luma = amlPqClient->GetCMS(3/*COLOR_LUMA*/,cms_color_type);
#endif
   return ret;
}

bool isCurrentHDRTypeIsSDR()
{
    bool ret=true;
    uint32_t currentFormat = GetCurrentContentFormat();
    switch(currentFormat)
    {
        case tvVideoHDRFormat_SDR:
            ret=true;
            break;
        case tvVideoHDRFormat_HDR10:
        case tvVideoHDRFormat_HLG:
        case tvVideoHDRFormat_DV:
	case tvVideoHDRFormat_HDR10PLUS:
            ret=false;
            break;
        default:
            ret=true;
            break;
     }
    return ret;
}

int GetPanelID(char *panelid)
{
    int fd, len;
    off_t offset = 0L;
    char buf[4] = {0};

    if ( NULL == panelid ) {
        printf("buf is NULL");
        return -1;
    }

    if ((fd = open(MMC_DEVICE, O_RDONLY)) < 0) {
        printf("open %s error(%s)", MMC_DEVICE, strerror (errno));
        return -1;
    }

    offset = lseek (fd, PANEL_ID_OFFSET, SEEK_SET);
    if( offset !=  PANEL_ID_OFFSET ) {
        printf("Failed to seek. offset[0x%x] requested[0x%x]\n", (uint32_t)offset, PANEL_ID_OFFSET);
        close(fd);
        return -1;
    }

    len = read(fd, buf, 4);
    if (len < 0) {
        printf("Read %s error, %s\n", MMC_DEVICE, strerror(errno));
        close(fd);
        return len;
    }
    sprintf(panelid, "%d_%d_%d%d", buf[0], buf[1], buf[2], buf[3]);

    return 0;
}

void GetDefaultPanelID(char *panelID)
{
    strcpy(panelID,"1_55_01");
}

tvError_t SaveBrightness(int sourceInput, int pq_mode,int hdr_type,int value) {
    tvError_t ret = tvERROR_NONE;
    printf("SaveBrightness: source=%d pq_mode=%d hdr_type=%d value=%d\n",sourceInput,pq_mode,hdr_type,value);
    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    int err = amlPqClient->SaveBrightness(sourceInput, pq_mode,hdr_type,value);

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    return ret;
}

tvError_t SaveContrast(int sourceInput, int pq_mode,int hdr_type,int value) {
    tvError_t ret = tvERROR_NONE;
    printf("SaveContrast: source=%d pq_mode=%d hdr_type=%d value=%d\n",sourceInput,pq_mode,hdr_type,value);
    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    int err = amlPqClient->SaveContrast(sourceInput, pq_mode,hdr_type,value);

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    return ret;
}

tvError_t SaveSharpness(int sourceInput, int pq_mode,int hdr_type,int value) {
    tvError_t ret = tvERROR_NONE;
    printf("SaveSharpness: source=%d pq_mode=%d hdr_type=%d value=%d\n",sourceInput,pq_mode,hdr_type,value);
    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    int err = amlPqClient->SaveSharpness(sourceInput, pq_mode,hdr_type,value);

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    return ret;
}

tvError_t SaveSaturation(int sourceInput, int pq_mode,int hdr_type,int value) {
    tvError_t ret = tvERROR_NONE;
    printf("SaveSaturation: source=%d pq_mode=%d hdr_type=%d value=%d\n",sourceInput,pq_mode,hdr_type,value);
    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    int err = amlPqClient->SaveSaturation(sourceInput, pq_mode,hdr_type,value);

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    return ret;
}

tvError_t SaveHue(int sourceInput, int pq_mode,int hdr_type,int value) {
    tvError_t ret = tvERROR_NONE;
    printf("SaveHue: source=%d pq_mode=%d hdr_type=%d value=%d\n",sourceInput,pq_mode,hdr_type,value);
    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    int err = amlPqClient->SaveHue(sourceInput, pq_mode,hdr_type,value);

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    return ret;
}

tvError_t SaveColorTemperature(int sourceInput, int pq_mode,int hdr_type,int value) {
    tvError_t ret = tvERROR_NONE;
    printf("SaveColorTemperature: source=%d pq_mode=%d hdr_type=%d value=%d\n",sourceInput,pq_mode,hdr_type,value);
    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    int err = amlPqClient->SaveColorTemperature(sourceInput, pq_mode,hdr_type,value);

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    return ret;
}

tvError_t SaveBacklight(int sourceInput, int pq_mode,int hdr_type,int value) {
    tvError_t ret = tvERROR_NONE;
    printf("SaveBacklight: source=%d pq_mode=%d hdr_type=%d value=%d\n",sourceInput,pq_mode,hdr_type,value);
    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    int err = amlPqClient->SaveBacklight(sourceInput, pq_mode,hdr_type,value);

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    return ret;
}

tvError_t SaveDynamicBacklight(int sourceInput, int pq_mode,int hdr_type,int value) {
    tvError_t ret = tvERROR_NONE;
    printf("SaveDynamicBacklight: source=%d pq_mode=%d hdr_type=%d value=%d\n",sourceInput,pq_mode,hdr_type,value);
    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    int err = amlPqClient->SaveDynamicBacklight(sourceInput, pq_mode,hdr_type,value);

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    return ret;
}

tvError_t SaveDisplayMode(int sourceInput, int pq_mode,int hdr_type,int value) {
    tvError_t ret = tvERROR_NONE;
    int err =-1;
    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    switch(value) {

        case tvDisplayMode_4x3:
            value = 4;
            break;

        case tvDisplayMode_16x9:
        case tvDisplayMode_AUTO:
            value   = 0;
            break;

        case tvDisplayMode_FULL:
            value=5 ;
            break;

        case tvDisplayMode_NORMAL:
        case tvDisplayMode_DIRECT:
            value = 6;
            break;

        case tvDisplayMode_ZOOM:
            value = 10;
            break;
        case tvDisplayMode_MAX:
            value = 11;
            break;
        default:
            value=-1;
            break;
    }
    printf("SaveDisplayMode: source=%d pq_mode=%d hdr_type=%d value=%d\n",sourceInput,pq_mode,hdr_type,value);

    if(value!=-1)
        err = amlPqClient->SaveDisplayMode(sourceInput, pq_mode,hdr_type,value);

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    return ret;
}

tvError_t SaveDolbyMode(int sourceInput, int pq_mode,int hdr_type,int value) {
    tvError_t ret = tvERROR_NONE;
    printf("SaveDolbyMode: source=%d pq_mode=%d hdr_type=%d value=%d\n",sourceInput,pq_mode,hdr_type,value);
    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    int err = amlPqClient->SaveDolbyMode(sourceInput, pq_mode,hdr_type,value);

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    return ret;
}

tvError_t SaveCMS(int sourceInput, int pq_mode,int hdr_type,int tunnel_type,int color_type,int value) {
    tvError_t ret = tvERROR_NONE;
    printf("SaveCMS: source=%d pq_mode=%d hdr_type=%d tunnel_type=%d color_type=%d value=%d\n",sourceInput,pq_mode,hdr_type,tunnel_type,color_type,value);
    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

    int err = amlPqClient->SaveCMS(sourceInput, pq_mode,hdr_type,tunnel_type,color_type,value);

    if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    return ret;
}

int ConvertVideoFormatToHDRFormat(tvVideoHDRFormat_t videoFormat)
{
    int ret=HDR_TYPE_NONE;
    switch(videoFormat)
    {
        case tvVideoHDRFormat_SDR:
            ret=HDR_TYPE_SDR;
            break;
        case tvVideoHDRFormat_HDR10:
	    ret=HDR_TYPE_HDR10;
	    break;
	case tvVideoHDRFormat_HDR10PLUS:
	    ret=HDR_TYPE_HDR10PLUS;
	    break;
        case tvVideoHDRFormat_HLG:
	    ret=HDR_TYPE_HLG;
	    break;
        case tvVideoHDRFormat_DV:
            ret=HDR_TYPE_DOVI;
            break;
        default:
            break;
     }
    return ret;
}

int ConvertHDRFormatToContentFormat(tvhdr_type_t hdrFormat)
{
    int ret=tvContentFormatType_SDR;
    switch(hdrFormat)
    {
        case HDR_TYPE_SDR:
	    ret=tvContentFormatType_SDR;
	    break;
	case HDR_TYPE_HDR10:
	    ret=tvContentFormatType_HDR10;
	    break;
	case HDR_TYPE_HDR10PLUS:
	    ret=tvContentFormatType_HDR10PLUS;
	    break;
	case HDR_TYPE_DOVI:
	    ret=tvContentFormatType_DOVI;
	    break;
	case HDR_TYPE_HLG:
	    ret=tvContentFormatType_HLG;
	    break;
	default:
	    break;
    }
    return ret;
}

int GetNumberOfModesupported()
{
    return numberModesSupported;
}

void GetAllSupportedPicModeIndex(int pic_mode_index[])
{
    int loopcount=0;
    for(loopcount=0;loopcount<numberModesSupported;loopcount++)
        pic_mode_index[loopcount]=pic_modes[loopcount].value;
}

tvError_t ResetComponentLuma(int color,int defaultValue) {
    tvError_t ret = tvERROR_NONE;
    int err = 0;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

   err = amlPqClient->SetCMS(3/*COLOR_LUMA*/,color,defaultValue,0);
   if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    return ret;
}

tvError_t ResetComponentSaturation(int color,int defaultValue) {
    tvError_t ret = tvERROR_NONE;
    int err = 0;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

   err = amlPqClient->SetCMS(2/*COLOR_SATURATION*/,color,defaultValue,0);
   if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    return ret;
}

tvError_t ResetComponentHue(int color,int defaultValue) {
    tvError_t ret = tvERROR_NONE;
    int err = 0;

    if(amlPqClient == NULL)
        return tvERROR_INVALID_STATE;

   err = amlPqClient->SetCMS(1/*COLOR_HUE*/,color,defaultValue,0);
   if(err == -1) {
        ret = tvERROR_GENERAL;
    }
    return ret;
}

int GetCMSDefault(tvCMS_tunel_t color_tunel_type) {
    int default_val = 0;

    if (COLOR_LUMA == color_tunel_type) {
        default_val = 15;
    }
    else if((COLOR_SATURATION == color_tunel_type) || (COLOR_HUE == color_tunel_type)) {
	default_val = 50;
    }
    else
        default_val = 0;

    return default_val;
}

int GetCurrentPQIndex() {
     return picModeValue;
}

int GetDolbyModeIndex(const char * dolbyMode)
{
    unsigned short mode = 0;

    if(strncmp(dolbyMode,"bright",strlen("bright"))==0)
        mode=tvDolbyMode_Bright;
    else if(strncmp(dolbyMode,"dark",strlen("dark"))==0)
        mode=tvDolbyMode_Dark;

    return mode;
}

int GetHDR10ModeIndex(const char * hdr10Mode)
{
    int mode = 0;
    pic_modes_t *hdr10Modes;
    unsigned short totalAvailable = 0;

    tvError_t ret = GetTVSupportedHDR10Modes(&hdr10Modes,&totalAvailable);
    if(ret == tvERROR_NONE) {
        for(int count = 0;count <totalAvailable;count++ )
        {
            if(strncmp(hdr10Mode, hdr10Modes[count].name, strlen(hdr10Mode))==0){
                mode = hdr10Modes[count].value;
                break;
            }

        }
    }else{
        mode = -1;
        printf("(%s):get supported mode is failed\n", __func__);
    }

    return mode;
}

int GetHLGModeIndex(const char * hlgMode)
{
    int mode = 0;
    pic_modes_t *hlgModes;
    unsigned short totalAvailable = 0;

    tvError_t ret = GetTVSupportedHLGModes(&hlgModes,&totalAvailable);
    if(ret == tvERROR_NONE) {
        for(int count = 0;count <totalAvailable;count++ )
        {
            if(strncmp(hlgMode, hlgModes[count].name, strlen(hlgMode))==0){
                mode = hlgModes[count].value;
                break;
            }

        }
    }else{
        mode = -1;
        printf("(%s):get supported mode is failed\n", __func__);
    }

    return mode;
}

int ConvertTVColorToVendorColor(tvDataComponentColor_t blComponentColor)
{
    int ret=0;
    switch(blComponentColor){
        case tvDataColor_RED:
            ret = COLOR_RED;
            break;
        case tvDataColor_GREEN:
            ret = COLOR_GREEN;
            break;
        case tvDataColor_BLUE:
            ret = COLOR_BLUE;
            break;
        case tvDataColor_CYAN:
            ret = COLOR_CYAN;
            break;
        case tvDataColor_MAGENTA:
            ret = COLOR_MAGENTA;
            break;
        case tvDataColor_YELLOW:
            ret = COLOR_YELLOW;
            break;
        default:
            ret=COLOR_RED;
            break;
    }
    return ret;
}

int GetCustomPQModeIndex()
{
   short int loopcount = 0;

   if(numberModesSupported)
   {
       for(;loopcount<numberModesSupported;loopcount++)
       {
           if(0==strncmp("expert",pic_modes[loopcount].name,PIC_MODE_NAME_MAX))
               break;
       }
   }
   return pic_modes[loopcount].value;
}
#endif

tvError_t SetCMSState(tvCMS_tunel_t tunelType,tvcomponent_color_type_t colorType,tvcomponent_state_t componentState)
{

    return tvERROR_NONE;
}

tvError_t ReadCustWBvaluesFromDriverOnInit(void)
{
    return tvERROR_NONE;
}

tvDataColor_t GetUSerWBValueOnInit(void)
{
    tvDataColor_t custWBValueOnInit = {};
    return custWBValueOnInit;
}

bool isWBUserDfault(tvDataColor_t wbvalue)
{
   return false;
}

int GetWBRgbType(const char *color, const char * ctrl)
{
   
    return 0;

}

tvError_t SaveColorTemperatureUser(int rgbType, int value)
{
    return 0;
}

tvError_t SetColorTemperatureUser(int rgbType, int value)
{
    return tvERROR_NONE;
}

int GetDriverEquivalentBLForCurrentFmt(int backlight)
{
   return 0;
}

tvError_t SetBacklightInfo(tvBacklightInfo_t backlightDefaults)
{
   return tvERROR_NONE;
}

tvError_t GetTVSupportedHLGModes(pic_modes_t *hlgModes[],unsigned short *count) {
  
    return tvERROR_NONE;
}

tvError_t GetTVSupportedHDR10Modes(pic_modes_t *hdr10Modes[],unsigned short *count) {
    
    return tvERROR_NONE;
}

tvError_t ReadAllModeConfigfile(const char *file, char *cpybuffer, const char *searchstring)
{
   
    return tvERROR_NONE;
}

void splitstringsandvaluefrombuffer(char *buffer, pic_modes_t *availableModes[], unsigned short *totalcount)
{
   return;
}

void splitstringsfrombuffer(char *buffer, char *availableModes, unsigned short *totalcount)
{
    return;
}

tvError_t SetBacklightFade(int from,int to,int duration)
{
    return tvERROR_NONE;
}

tvError_t SetGammaMode(int mode)
{
   return tvERROR_GENERAL;
}

tvError_t SetLocalDimmingLevel(int localDimmingLevel) {

    return tvERROR_NONE;
}

tvError_t GetLocalDimmingLevel(int *localDimmingLevel) {
    return tvERROR_NONE;
}

tvError_t SaveLocalDimmingLevel(int sourceInput, int pq_mode,int hdr_type,int value) {
    return  tvERROR_NONE;
}

void SwitchEDID(int pqmode)
{
   return;
}

tvError_t UpdateEDIDAndSetDimmingLevel(int dimmingMode)
{
       return tvERROR_NONE;
}

void GetLDIMAndEDIDLevel(int dimmingMode,int format,int *dimmingLevel, int *edidLevel)
{
   return;
}

