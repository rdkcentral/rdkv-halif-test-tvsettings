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
typedef enum _mfrSerializedType_t {
    mfrSERIALIZED_TYPE_MANUFACTURER = 0,
    mfrSERIALIZED_TYPE_MANUFACTUREROUI,
    mfrSERIALIZED_TYPE_MODELNAME,
    mfrSERIALIZED_TYPE_DESCRIPTION,
    mfrSERIALIZED_TYPE_PRODUCTCLASS,
    mfrSERIALIZED_TYPE_SERIALNUMBER,
    mfrSERIALIZED_TYPE_HARDWAREVERSION,
    mfrSERIALIZED_TYPE_SOFTWAREVERSION,
    mfrSERIALIZED_TYPE_PROVISIONINGCODE,
    mfrSERIALIZED_TYPE_FIRSTUSEDATE,
    mfrSERIALIZED_TYPE_DEVICEMAC,
    mfrSERIALIZED_TYPE_MOCAMAC,
    mfrSERIALIZED_TYPE_HDMIHDCP,
    mfrSERIALIZED_TYPE_PDRIVERSION,
    mfrSERIALIZED_TYPE_WIFIMAC,
    mfrSERIALIZED_TYPE_BLUETOOTHMAC,
    mfrSERIALIZED_TYPE_WPSPIN,
    mfrSERIALIZED_TYPE_MANUFACTURING_SERIALNUMBER,
    mfrSERIALIZED_TYPE_ETHERNETMAC,
    mfrSERIALIZED_TYPE_ESTBMAC,
    mfrSERIALIZED_TYPE_RF4CEMAC,
    mfrSERIALIZED_TYPE_MODELNUMBER,
    mfrSERIALIZED_TYPE_SKYMODELNAME,
    mfrSERIALIZED_TYPE_SKY_SERIAL_DATA3_SIZE,
    mfrSERIALIZED_TYPE_SKY_PANEL_ID,
    mfrSERIALIZED_TYPE_SKY_PANEL_TYPE,
    mfrSERIALIZED_TYPE_SKY_PANEL_HDMI_WB_DATA_NORMAL,
    mfrSERIALIZED_TYPE_SKY_PANEL_HDMI_WB_DATA_COLD,
    mfrSERIALIZED_TYPE_SKY_PANEL_HDMI_WB_DATA_WARM,
    mfrSERIALIZED_TYPE_SKY_PANEL_HDMI_WB_DATA_USER,
    mfrSERIALIZED_TYPE_SKY_PANEL_TV_WB_DATA_NORMAL,
    mfrSERIALIZED_TYPE_SKY_PANEL_TV_WB_DATA_COLD,
    mfrSERIALIZED_TYPE_SKY_PANEL_TV_WB_DATA_WARM,
    mfrSERIALIZED_TYPE_SKY_PANEL_TV_WB_DATA_USER,
    mfrSERIALIZED_TYPE_SKY_PANEL_AV_WB_DATA_NORMAL,
    mfrSERIALIZED_TYPE_SKY_PANEL_AV_WB_DATA_COLD,
    mfrSERIALIZED_TYPE_SKY_PANEL_AV_WB_DATA_WARM,
    mfrSERIALIZED_TYPE_SKY_PANEL_AV_WB_DATA_USER,
    mfrSERIALIZED_TYPE_SKY_PANEL_RESERVED_4K,
    mfrSERIALIZED_TYPE_SKY_PANEL_DTB_VERSION,
    mfrSERIALIZED_TYPE_SKY_PANEL_DTB_DATA_SIZE,
    mfrSERIALIZED_TYPE_SKY_PANEL_DTB_DATA,
    mfrSERIALIZED_TYPE_SKY_PANEL_RESERVED_128K,
    mfrSERIALIZED_TYPE_SKY_SKY_PANEL_SER3_CHECKSUM,
    mfrSERIALIZED_TYPE_PMI,
    mfrSERIALIZED_TYPE_HWID,
    mfrSERIALIZED_TYPE_SKY_MFG_SERIAL_NO,
    /* boot data */
    mfrSERIALIZED_TYPE_SOC_ID,
    mfrSERIALIZED_TYPE_IMAGENAME,
    mfrSERIALIZED_TYPE_IMAGETYPE,
    mfrSERIALIZED_TYPE_BLVERSION,
    /* provisional data */
    mfrSERIALIZED_TYPE_REGION,
    /* other data */
    mfrSERIALIZED_TYPE_BDRIVERSION,
    /* led data */
    mfrSERIALIZED_TYPE_LED_WHITE_LEVEL,
    mfrSERIALIZED_TYPE_LED_PATTERN,
    /* legacy data (to be deleted) */
    mfrSERIALIZED_TYPE_FACTORYBOOT,
    mfrSERIALIZED_TYPE_COUNTRYCODE,
    mfrSERIALIZED_TYPE_LANGUAGECODE,
    mfrSERIALIZED_TYPE_MANUFACTURERDATA,
    /* panel data*/
    mfrSERIALIZED_TYPE_PANEL_DATA_FUNCTION_STATUS,
    mfrSERIALIZED_TYPE_PANEL_DATA_AGEING_TIME,
    mfrSERIALIZED_TYPE_PANEL_DATA_POWER_ON_TIME,
    mfrSERIALIZED_TYPE_PANEL_DATA_BACKLIGHT_TIME,
    mfrSERIALIZED_TYPE_PANEL_DATA_TPV_APP_VERSION,
    mfrSERIALIZED_TYPE_PANEL_DATA_VALID,
    mfrSERIALIZED_TYPE_MAX,
} mfrSerializedType_t;

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
           return tvERROR_NONE;
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
    return;
}


tvError_t tvSD3toCriSyncInit()
{
    return tvERROR_NONE;
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
    return tvERROR_NONE;
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
    return tvERROR_NONE;
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
    return tvERROR_NONE;
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
    return tvERROR_NONE;
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
    return tvERROR_NONE;
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
    return tvERROR_NONE;
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
    return tvERROR_NONE;
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
    return tvERROR_NONE;
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

    return tvERROR_NONE;
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
    return;
}

void RegisterVideoFrameRateChangeCB(tvVideoFrameRateCallbackData& cbData){
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

    return tvERROR_NONE;
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

    return tvERROR_NONE;
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

    return tvERROR_NONE;
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
    return tvERROR_NONE;
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
    return tvERROR_NONE;
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

    return tvERROR_NONE;
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

    return tvERROR_NONE;

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
    return tvERROR_NONE;
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
   return tvERROR_NONE;
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
    return tvERROR_NONE;
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
    return tvERROR_NONE;
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
    return tvERROR_NONE;
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

    return tvERROR_NONE;
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
    return tvERROR_NONE;
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

    return tvERROR_NONE;

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

    return tvERROR_NONE;
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
   return tvERROR_NONE;
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
    return tvERROR_NONE;
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
    return tvERROR_NONE;
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
   return tvERROR_NONE;
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

   return tvERROR_NONE;


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

   return tvERROR_NONE;
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
   return tvERROR_NONE;
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
   return tvERROR_NONE;
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
   return tvERROR_NONE;
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
   return tvERROR_NONE;
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
   return tvERROR_NONE;
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
   return tvERROR_NONE;
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
   return tvERROR_NONE;
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
   return tvERROR_NONE;
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

    return tvERROR_NONE;
}



tvError_t GetTVSupportedDVModes(pic_modes_t *dvModes[],unsigned short *count) {
    return tvERROR_NONE;
}


tvError_t GetTVDolbyVisionMode(char *dolbyMode) {
    return tvERROR_NONE;
}

tvError_t SetTVDolbyVisionMode(const char * dolbyMode) {

    return tvERROR_NONE;
}

tvError_t SetTVHDR10Mode(const char * hdr10Mode) {

    return tvERROR_NONE;
}

tvError_t SetTVHLGMode(const char *hlgMode) {
    return tvERROR_NONE;
}

tvError_t SetDynamicContrast(const char *dynamicContrastEnable)
{
    return tvERROR_NONE;
}

tvError_t GetDynamicContrast(char *isDynamicContrastEnabled)
{
    return tvERROR_NONE;
}

int sourceIdFromOffset(int offset)
{
    return 0;
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
    return tvERROR_NONE;
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

   return tvERROR_NONE;
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
   
   return tvERROR_NONE;
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
   return tvERROR_NONE;
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
   return tvERROR_NONE;
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

   return tvERROR_NONE;
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
   return tvERROR_NONE;
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

   return tvERROR_NONE;
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
    return tvERROR_NONE;
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
   return tvERROR_NONE;
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
   return tvERROR_NONE;
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
   return tvERROR_NONE;
}

bool isAllZero(tvDataColor_t wbvalue)
{
    return false;
}

bool isDefaultNormal(tvDataColor_t wbvalue)
{
    return false;
}

bool isDefaultWarm(tvDataColor_t wbvalue)
{
    return false;
}
bool isDefaultCold(tvDataColor_t wbvalue)
{
    return false;
}

bool areEqual(tvDataColor_t wbvalueThis,tvDataColor_t wbvalueThat)
{
    return false;
}
void readWBFromCridata(int source,int colorTemp,tvDataColor_t *wbSD3Val)
{
    return;
}

tvError_t tvwriteCRIdataBySource(tvColorTemp_t colorTemp, tvDataColor_t wbDefaultVal,int source) {
        return tvERROR_NONE;
}

mfrSerializedType_t getHdmiSd3Param(int colorTemp, int *index)
{
    mfrSerializedType_t type = mfrSERIALIZED_TYPE_SKY_PANEL_HDMI_WB_DATA_NORMAL;

    return mfrSERIALIZED_TYPE_SKY_PANEL_HDMI_WB_DATA_NORMAL;
}

mfrSerializedType_t getTVSd3Param(int colorTemp, int *index)
{

    return mfrSERIALIZED_TYPE_SKY_PANEL_AV_WB_DATA_NORMAL;
}

mfrSerializedType_t getAVSd3Param(int colorTemp, int *index)
{

    return mfrSERIALIZED_TYPE_SKY_PANEL_AV_WB_DATA_NORMAL;
}


mfrSerializedType_t getSD3ParamType(int source,int colorTemp, int *index)
{

    return mfrSERIALIZED_TYPE_SKY_PANEL_HDMI_WB_DATA_NORMAL;
}

unsigned char statusOfReadSD3Entry (tvDataColor_t fromSD3,int colorTemp)
{ 
    return 0;
}

void tvCopySD3DatatoCridataEx(void) {

return;
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
	return tvERROR_NONE;
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
	return tvERROR_NONE;
}


mfrSerializedType_t getParamType(int i)
{

                return mfrSERIALIZED_TYPE_SKY_PANEL_HDMI_WB_DATA_NORMAL;
}

tvError_t getWbInfo(getWBInfo_t* params, std::vector<std::string> &selector
		, std::vector<std::string> &colorTmp, std::vector<std::string> &input)
{    
    return tvERROR_NONE;
}


int TVWriteSysfs(const char *path, const char * cmd)
{
    return 0;
}


tvError_t enableWBmode(bool value)
{
	return tvERROR_NONE;
}

tvError_t GetTVSupportedDimmingModes(char **dimmingModes,unsigned short *count) {

    return tvERROR_NONE;
}

bool isSupportedDimmingMode(const char *dimmingMode)
{
    return false;
}
tvError_t SetTVDimmingMode(const char *dimmingMode) {

    return tvERROR_NONE;
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

    return tvERROR_NONE;

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
   
   return tvERROR_NONE;
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
   return tvERROR_NONE;
}

tvError_t SetTVBacklightGlobalFactor(int value,int rangeMidPointValue)
{
   return tvERROR_NONE;
}
tvError_t TVUpdateRawBacklight(int value,int midPointValue)
{
    return tvERROR_NONE;
}

tvError_t GetTVBacklightGlobalFactor(int * value)
{
    tvError_t ret = tvERROR_NONE;
    return ret;
}

tvPictureMode_t GetTVPictureModeIndex(const char * pictureMode)
{
    tvPictureMode_t ret = 0;
  return ret;
}

tvVideoHDRFormat_t GetCurrentContentFormat(void)
{
    return tvVideoHDRFormat_NONE;
}

tvError_t GetSupportedContentFormats(unsigned int * contentFormats,unsigned short *numberOfFormats)
{
  
    return tvERROR_NONE;
}
tvError_t ResetBrightness(int defaultValue,bool resetForAllFormats) {
   
    return tvERROR_NONE;
}

tvError_t ResetContrast(int defaultValue,bool resetForAllFormats) {
   
    return tvERROR_NONE;
}

tvError_t ResetSharpness(int defaultValue,bool resetForAllFormats) {

    return tvERROR_NONE;
}

tvError_t ResetSaturation(int defaultValue,bool resetForAllFormats) {
  
    return tvERROR_NONE;
}

tvError_t ResetHue(int defaultValue,bool resetForAllFormats) {

    return tvERROR_NONE;
}

tvError_t ResetBacklight(int defaultValue,bool resetForAllFormats) {

    return tvERROR_NONE;
}

tvError_t ResetColorTemperature(int defaultValue,bool resetForAllFormats) {

    return tvERROR_NONE;
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

   return tvERROR_NONE;
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
   return tvERROR_NONE;
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

   return tvERROR_NONE;
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
   return tvERROR_NONE;
}

bool isCurrentHDRTypeIsSDR()
{

    return false;
}

int GetPanelID(char *panelid)
{
       return 0;
}

void GetDefaultPanelID(char *panelID)
{
    return;
}

tvError_t SaveBrightness(int sourceInput, int pq_mode,int hdr_type,int value) {

    return tvERROR_NONE;
}

tvError_t SaveContrast(int sourceInput, int pq_mode,int hdr_type,int value) {

    return tvERROR_NONE;
}

tvError_t SaveSharpness(int sourceInput, int pq_mode,int hdr_type,int value) {

    return tvERROR_NONE;
}

tvError_t SaveSaturation(int sourceInput, int pq_mode,int hdr_type,int value) {

    return tvERROR_NONE;
}

tvError_t SaveHue(int sourceInput, int pq_mode,int hdr_type,int value) {
 
    return tvERROR_NONE;
}

tvError_t SaveColorTemperature(int sourceInput, int pq_mode,int hdr_type,int value) {
   
    return tvERROR_NONE;
}

tvError_t SaveBacklight(int sourceInput, int pq_mode,int hdr_type,int value) {
   
    return tvERROR_NONE;
}

tvError_t SaveDynamicBacklight(int sourceInput, int pq_mode,int hdr_type,int value) {
   
    return tvERROR_NONE;
}

tvError_t SaveDisplayMode(int sourceInput, int pq_mode,int hdr_type,int value) {
  
    return tvERROR_NONE;
}

tvError_t SaveDolbyMode(int sourceInput, int pq_mode,int hdr_type,int value) {
   
    return tvERROR_NONE;
}

tvError_t SaveCMS(int sourceInput, int pq_mode,int hdr_type,int tunnel_type,int color_type,int value) {
   
    return tvERROR_NONE;
}

int ConvertVideoFormatToHDRFormat(tvVideoHDRFormat_t videoFormat)
{
 
    return 0;
}

int ConvertHDRFormatToContentFormat(tvhdr_type_t hdrFormat)
{
   
    return 0;
}

int GetNumberOfModesupported()
{
    return 0;
}

void GetAllSupportedPicModeIndex(int pic_mode_index[])
{
   return;
}

tvError_t ResetComponentLuma(int color,int defaultValue) {
   
    return tvERROR_NONE;
}

tvError_t ResetComponentSaturation(int color,int defaultValue) {

    return tvERROR_NONE;
}

tvError_t ResetComponentHue(int color,int defaultValue) {

    return tvERROR_NONE;
}

int GetCMSDefault(tvCMS_tunel_t color_tunel_type) {
   
    return 0;
}

int GetCurrentPQIndex() {
     return 0;
}

int GetDolbyModeIndex(const char * dolbyMode)
{
 
    return 0;
}

int GetHDR10ModeIndex(const char * hdr10Mode)
{
    return 0;
}

int GetHLGModeIndex(const char * hlgMode)
{
   
    return 0;
}

int ConvertTVColorToVendorColor(tvDataComponentColor_t blComponentColor)
{
   
    return 0;
}

int GetCustomPQModeIndex()
{
  
   return 0;
}

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
    return tvERROR_NONE;
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

tvError_t setWakeupConfig(const tvWakeupSrcType_t src_type, const bool config)
{
   return tvERROR_NONE; 
}