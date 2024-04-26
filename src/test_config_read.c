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
 * @addtogroup HPK Hardware Porting Kit
 * @{
 * @par The Hardware Porting Kit
 * HPK is the next evolution of the well-defined Hardware Abstraction Layer
 * (HAL), but augmented with more comprehensive documentation and test suites
 * that OEM or SOC vendors can use to self-certify their ports before taking
 * them to RDKM for validation or to an operator for final integration and
 * deployment. The Hardware Porting Kit effectively enables an OEM and/or SOC
 * vendor to self-certify their own Video Accelerator devices, with minimal RDKM
 * assistance.
 *
 */

/**
 * @addtogroup TV_Settings TV Settings Module
 * @{
 */

/**
 * @addtogroup TV_Settings_HALTEST TV Settings HAL Tests
 * @{
 */

/**
 * @defgroup TV_Settings_HALTEST_CONFIG_READ TV Settings HAL Tests Config read File
 *  @{
 * @parblock
 *
 * ### Read a platform configuration for TV_Settings HAL :
 *
 * This is to ensure that the API meets the operational requirements of the module across all vendors.
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 *
 * Refer to Device Settings HAL Documentation Guide : [tv-settings_halSpec.md](../../docs/pages/tv-settings_halSpec.md)
 *
 * @endparblock
 */

/**
* @file test_config_read.c
*
*/


#include "test_config_read.h"
#include "tvTypes.h"

struct TvSettingConfig Configfile = {0};
int colorFlag = 0;
int paramFlag = 0;

int parseRange(const char *buf, struct DisplayPictureMode *mode)
{
	if (buf == NULL || mode == NULL)
	{
		fprintf(stderr, "input param is NULL - %d.\n", errno);
		return -1;
	}
	if (sscanf(buf, "range_from = %hd", &mode->rangeFrom) == 1)
	{
		UT_LOG("\n Range From: %d\n", mode->rangeFrom);
	}
	else if (sscanf(buf, "range_to = %hd", &mode->rangeTo) == 1)
	{
		UT_LOG("\n Range To: %d\n", mode->rangeTo);
	}
	return 0;
}

int parseRange_color(const char *buf, struct DisplayColorMode *mode)
{
	if (buf == NULL || mode == NULL)
	{
		fprintf(stderr, "input param is NULL - %d.\n", errno);
		return -1;
	}
	char input[200] = {0};
	int i = 0;
	size_t len = 0;

	if (sscanf(buf, "range = %[^\n]", input) == 1)
	{
		while (i < MAX_COLOR_TEMP && sscanf(input + len, "%[^,]", &mode->colorStruct.colorTemp[i]) == 1)
		{
			len += strlen(mode->colorStruct.colorTemp[i]);

			mode->colorStruct.colorTempValue[i] = i;
			if (*(input + len) == ',')
			{
				len++;  
				i++;    
			}
			else
			{
				break;
			}
		}
		mode->colorStruct.size = i + 1;
	}
	return 0;
}

int parseRange_mode(const char *buf, struct DisplayColorMode *mode)
{
	if (buf == NULL || mode == NULL)
	{
		fprintf(stderr, "input param is NULL - %d.\n", errno);
		return -1;
	}
	char input[200] = {0};
	int i = 0;
	size_t len = 0;
	if (sscanf(buf, "range = %[^\n]", input) == 1)
	{
		while (i < MAX_NAME_SIZE && sscanf(input + len, "%[^,]", &mode->modeName[i]) == 1)
		{
			len += strlen(mode->modeName[i]);
			mode->modevalue[i] = i;
			if (*(input + len) == ',')
			{
				len++;  
				i++;    
			}
			else
			{
				break;
			}
		}
		mode->size = i + 1;
	}
	return 0;
}

int parseRange_picturemode(const char *buf, struct PictureMode *picmode)
{
	if (buf == NULL || picmode == NULL)
	{
		fprintf(stderr, "input param is NULL - %d.\n", errno);
		return -1;
	}
	char input[200] = {0};
	int i = 0;
	size_t len = 0;

	if (sscanf(buf, "range = %[^\n]", input) == 1)
	{
		while (i < MAX_NAME_SIZE && sscanf(input + len, "%[^,]", &picmode->pqMode[i]) == 1)
		{
			len += strlen(picmode->pqMode[i]);
			if (*(input + len) == ',')
			{
				len++;
				i++;
			}
			else
			{
				break;
			}
		}
		picmode->size = i + 1;
	}
	if (sscanf(buf, "index = %s", input) == 1)
	{
		len = 0;
		while (i < MAX_NAME_SIZE && sscanf(input + len, "%d,", &picmode->pqValue[i]) == 1)
		{
			len += strcspn(input + len, ",") + 1;
			i++;
		}
	}
	return 0;
}

int parseRange_videoSource(const char *buf, struct videoSource *videoSrcStruct)
{
	if (buf == NULL || videoSrcStruct == NULL)
	{
		fprintf(stderr, "input param is NULL - %d.\n", errno);
		return -1;
	}
	char input[200] = {0};
	int i = 0;
	size_t len = 0;

	if (sscanf(buf, "range = %[^\n]", input) == 1)
	{
		while (i < MAX_NAME_SIZE && sscanf(input + len, "%[^,]", &videoSrcStruct->source[i]) == 1)
		{
			len += strlen(videoSrcStruct->source[i]);
			if (*(input + len) == ',')
			{
				len++;
				i++;
			}
			else
			{
				break;
			}
		}
		videoSrcStruct->size = i + 1;
	}
	if (sscanf(buf, "index = %[^\n]", input) == 1)
	{
		len = 0;
		while (i < MAX_NAME_SIZE && sscanf(input + len, "%d,", &videoSrcStruct->videoSourceValue[i]) == 1)
		{
			len += strcspn(input + len, ",") + 1;
			i++;
		}
	}
	return 0;
}

int parseRange_videoFormat(const char *buf, struct videoFormat *videoFormt)
{
	if (buf == NULL || videoFormt == NULL)
	{
		fprintf(stderr, "input param is NULL - %d.\n", errno);
		return -1;
	}
	char input[200] = {0};
	int i = 0;
	size_t len = 0;

	if (sscanf(buf, "range = %[^\n]", input) == 1)
	{
		while (i < MAX_NAME_SIZE && sscanf(input + len, "%[^,]", &videoFormt->videoFormat[i]) == 1)
		{
			len += strlen(videoFormt->videoFormat[i]);

			if (*(input + len) == ',')
			{
				len++;
				i++; 
			}
			else
			{
				break;
			}
		}
		videoFormt->size = i + 1;
	}
	if (sscanf(buf, "index = %[^\n]", input) == 1)
	{
		len = 0;
		while (i < MAX_NAME_SIZE && sscanf(input + len, "%d,", &videoFormt->videoFormatValue[i]) == 1)
		{
			len += strcspn(input + len, ",") + 1;
			i++;
		}
	}
	return 0;
}

int parseRange_videoFramerate(const char *buf, struct videoFrameRate *videoFramerate)
{
	if (buf == NULL || videoFramerate == NULL)
	{
		fprintf(stderr, "input param is NULL - %d.\n", errno);
		return -1;
	}
	char input[200] = {0};
	int i = 0;
	size_t len = 0;

	if (sscanf(buf, "range = %[^\n]", input) == 1)
	{
		while (i < MAX_NAME_SIZE && sscanf(input + len, "%[^,]", &videoFramerate->frameRate[i]) == 1)
		{
			len += strlen(videoFramerate->frameRate[i]);
			videoFramerate->frameRateValue[i] = i + 1;
			if (*(input + len) == ',')
			{
				len++;  
				i++;  
			}
			else
			{
				break;  
			}
		}
		videoFramerate->size = i + 1;
	}
	return 0;
}

int parseRange_dimlevel(const char *buf, struct DimmingLevel *dimlevel)
{
	if (buf == NULL || dimlevel == NULL)
	{
		fprintf(stderr, "input param is NULL - %d.\n", errno);
		return -1;
	}
	char input[200] = {0};
	int i = 0;
	size_t len = 0;

	if (sscanf(buf, "range_from = %hd", &dimlevel->rangeFrom) == 1)
	{
		UT_LOG("\n Range From: %d\n", dimlevel->rangeFrom);
	}
	else if (sscanf(buf, "range_to = %hd", &dimlevel->rangeTo) == 1)
	{
		UT_LOG("\n Range To: %d\n", dimlevel->rangeTo);
	}

	if (sscanf(buf, "DimmingLevel = %s", input) == 1)
	{
		while (i < MAX_NAME_SIZE && sscanf(input + len, "%[^,]", &dimlevel->dimModeName[i]) == 1)
		{
			len += strlen(dimlevel->dimModeName[i]);
			dimlevel->dimModevalue[i] = i;
			if (*(input + len) == ',')
			{
				len++;  
				i++;  
			}  
			else
			{
				break;  
			}
		}
		dimlevel->size = i + 1;
	}
	return 0;
}

int parseRange_wb(const char *buf, struct WhiteBalanceGamma *wbRGBGamma)
{
	if (buf == NULL || wbRGBGamma == NULL)
	{
		fprintf(stderr, "input param is NULL - %d.\n", errno);
		return -1;
	}
	char input[200] = {0};
	int i = 0;
	size_t len = 0;

	if (sscanf(buf, "range.gain.from = %d", &wbRGBGamma->rangeGainFrom) == 1)
	{
		UT_LOG("\n Range From: %d\n", wbRGBGamma->rangeGainFrom);
	}
	else if (sscanf(buf, "range.gain.to = %d", &wbRGBGamma->rangeGainTo) == 1)
	{
		UT_LOG("\n Range To: %d\n", wbRGBGamma->rangeGainTo);
	}

	if (sscanf(buf, "range.offset.from = %d", &wbRGBGamma->rangeOffsetFrom) == 1)
	{
		UT_LOG("\n Range From: %d\n", wbRGBGamma->rangeOffsetFrom);
	}
	else if (sscanf(buf, "range.offset.to = %d", &wbRGBGamma->rangeOffsetTo) == 1)
	{
		UT_LOG("\n Range To: %d\n", wbRGBGamma->rangeOffsetTo);
	}

	if (sscanf(buf, "gammaIndex_from = %d", &wbRGBGamma->rangeOffsetFrom) == 1)
	{
		UT_LOG("\n Range From: %d\n", wbRGBGamma->rangeOffsetFrom);
	}
	else if (sscanf(buf, "gammaIndex_to = %d", &wbRGBGamma->rangeOffsetTo) == 1)
	{
		UT_LOG("\n Range To: %d\n", wbRGBGamma->rangeOffsetTo);
	}

	if (sscanf(buf, "range_from = %d", &wbRGBGamma->rangeFrom) == 1)
	{
		UT_LOG("\n Range From: %d\n", wbRGBGamma->rangeFrom);
	}
	else if (sscanf(buf, "range_to = %d", &wbRGBGamma->rangeTo) == 1)
	{
		UT_LOG("\n Range To: %d\n", wbRGBGamma->rangeTo);
	}

	if (sscanf(buf, "ColorTemperature = %[^\n]", input) == 1)
	{
		while (i < MAX_NAME_SIZE && sscanf(input + len, "%[^,]", &wbRGBGamma->colorStruct.colorTemp[i]) == 1)
		{
			len += strlen(wbRGBGamma->colorStruct.colorTemp[i]);
			wbRGBGamma->colorStruct.colorTempValue[i] = i;
			if (*(input + len) == ',')
			{
				len++;  
				i++;  
			}
			else
			{
				break; 
			}
		}
		wbRGBGamma->colorStruct.size = i + 1;
	}

	if (sscanf(buf, "source = %[^\n]", input) == 1)
	{
		while (i < MAX_NAME_SIZE && sscanf(input + len, "%[^,]", &wbRGBGamma->videoSrcStruct.source[i]) == 1)
		{
			len += strlen(wbRGBGamma->videoSrcStruct.source[i]);
			wbRGBGamma->videoSrcStruct.videoSourceValue[i] = i;
			if (*(input + len) == ',')
			{
				len++;  
				i++;   
			}
			else
			{
				break;  
			}
		}
	}
	return 0;
}
static bool platformsupport(const char *buf, struct DisplayPictureMode *mode)
{
	if (buf == NULL || mode == NULL)
	{
		fprintf(stderr, "input param is NULL - %d.\n", errno);
		return false;
	}
	if (sscanf(buf, "platformsupport = %s", &mode->platformSupport) == 1)
	{
	    if(mode->platformSupport == true)
		{
            UT_LOG("\n platform support: %s\n", mode->platformSupport);
			return true;
		}
	}
	else
	    return false;
}

int fillstructure(const char *buf, int mode)
{
	int ret = 0;
	switch (mode)
	{
		case BRIGHTNESS_MODE_FLAG:
			ret = parseRange(buf, &Configfile.brightness);
			break;
		case CONTRAST_MODE_FLAG:
			ret = parseRange(buf, &Configfile.contrast);
			break;
		case SATURATION_MODE_FLAG:
			ret = parseRange(buf, &Configfile.saturation);
			break;
		case SHARPNESS_MODE_FLAG:
			ret = parseRange(buf, &Configfile.sharpness);
			break;
		case HUE_MODE_FLAG:
			ret = parseRange(buf, &Configfile.hue);
			break;
		case BACKLIGHT_MODE_FLAG:
			ret = parseRange(buf, &Configfile.backlight);
			break;
		case COMP_SATURATION_RED:
			ret = parseRange(buf, &Configfile.CompSaturationRed);
			if (strstr(buf, "range_from") != NULL)
			{
				Configfile.componentColor.modeId[colorFlag] = tvDataColor_RED;
				colorFlag++;
		        Configfile.componentColor.platformSupport[COMP_SATURATION][tvDataColor_RED] = platformsupport(buf, &Configfile.CompSaturationRed);
			}
			break;
		case COMP_SATURATION_GREEN:
			ret = parseRange(buf, &Configfile.CompSaturationGreen);
			if (strstr(buf, "range_from") != NULL)
			{
				Configfile.componentColor.modeId[colorFlag] = tvDataColor_GREEN;
				colorFlag++;
				Configfile.componentColor.platformSupport[COMP_SATURATION][tvDataColor_GREEN] = platformsupport(buf, &Configfile.CompSaturationGreen);
			}
			break;
		case COMP_SATURATION_BLUE:
			ret = parseRange(buf, &Configfile.CompSaturationBlue);
			if (strstr(buf, "range_from") != NULL)
			{
				Configfile.componentColor.modeId[colorFlag] = tvDataColor_BLUE;
				colorFlag++;
				Configfile.componentColor.platformSupport[COMP_SATURATION][tvDataColor_BLUE] = platformsupport(buf, &Configfile.CompSaturationBlue);
			}
			break;
		case COMP_SATURATION_YELLOW:
			ret = parseRange(buf, &Configfile.CompSaturationYellow);
			if (strstr(buf, "range_from") != NULL)
			{
				Configfile.componentColor.modeId[colorFlag] = tvDataColor_YELLOW;
				colorFlag++;
				Configfile.componentColor.platformSupport[COMP_SATURATION][tvDataColor_YELLOW] = platformsupport(buf, &Configfile.CompSaturationYellow);
			}
			break;
		case COMP_SATURATION_CYAN:
			ret = parseRange(buf, &Configfile.CompSaturationCyan);
			if (strstr(buf, "range_from") != NULL)
			{
				Configfile.componentColor.modeId[colorFlag] = tvDataColor_CYAN;
				colorFlag++;
				Configfile.componentColor.platformSupport[COMP_SATURATION][tvDataColor_CYAN] = platformsupport(buf, &Configfile.CompSaturationCyan);
			}
			break;
		case COMP_SATURATION_MAGENTA:
			ret = parseRange(buf, &Configfile.CompSaturationMagenta);
			if (strstr(buf, "range_from") != NULL)
			{
				Configfile.componentColor.modeId[colorFlag] = tvDataColor_MAGENTA;
				colorFlag++;
				Configfile.componentColor.platformSupport[COMP_SATURATION][tvDataColor_MAGENTA] = platformsupport(buf, &Configfile.CompSaturationMagenta);
			}
			break;
		case COMP_HUE_RED:
			ret = parseRange(buf, &Configfile.CompHueRed);
			if (strstr(buf, "range_from") != NULL)
			{
				Configfile.componentColor.platformSupport[COMP_HUE][tvDataColor_RED] = platformsupport(buf, &Configfile.CompHueRed);
			}
			break;
		case COMP_HUE_GREEN:
			ret = parseRange(buf, &Configfile.CompHueGreen);
			if (strstr(buf, "range_from") != NULL)
			{
				Configfile.componentColor.platformSupport[COMP_HUE][tvDataColor_GREEN] = platformsupport(buf, &Configfile.CompHueGreen);
			}
			break;
		case COMP_HUE_BLUE:
			ret = parseRange(buf, &Configfile.CompHueBlue);
			if (strstr(buf, "range_from") != NULL)
			{
				Configfile.componentColor.platformSupport[COMP_HUE][tvDataColor_BLUE] = platformsupport(buf, &Configfile.CompHueBlue);
			}
			break;
		case COMP_HUE_YELLOW:
			ret = parseRange(buf, &Configfile.CompHueYellow);
			if (strstr(buf, "range_from") != NULL)
			{
				Configfile.componentColor.platformSupport[COMP_HUE][tvDataColor_YELLOW] = platformsupport(buf, &Configfile.CompHueYellow);
			}
			break;
		case COMP_HUE_CYAN:
			ret = parseRange(buf, &Configfile.CompHueCyan);
			if (strstr(buf, "range_from") != NULL)
			{
				Configfile.componentColor.platformSupport[COMP_HUE][tvDataColor_CYAN] = platformsupport(buf, &Configfile.CompHueCyan);
			}
			break;
		case COMP_HUE_MAGENTA:
			ret = parseRange(buf, &Configfile.CompHueMagenta);
			if (strstr(buf, "range_from") != NULL)
			{
				Configfile.componentColor.platformSupport[COMP_HUE][tvDataColor_MAGENTA] = platformsupport(buf, &Configfile.CompHueMagenta);
			}
			break;
		case COMP_LUMA_RED:
			ret = parseRange(buf, &Configfile.CompLumaRed);
			if (strstr(buf, "range_from") != NULL)
			{
				Configfile.componentColor.platformSupport[COMP_LUMA][tvDataColor_RED] = platformsupport(buf, &Configfile.CompLumaRed);
			}
			break;
		case COMP_LUMA_GREEN:
			ret = parseRange(buf, &Configfile.CompLumaGreen);
			if (strstr(buf, "range_from") != NULL)
			{
				Configfile.componentColor.platformSupport[COMP_LUMA][tvDataColor_GREEN] = platformsupport(buf, &Configfile.CompLumaGreen);
			}
			break;
		case COMP_LUMA_BLUE:
			ret = parseRange(buf, &Configfile.CompLumaBlue);
			if (strstr(buf, "range_from") != NULL)
			{
				Configfile.componentColor.platformSupport[COMP_LUMA][tvDataColor_BLUE] = platformsupport(buf, &Configfile.CompLumaBlue);
			}
			break;
		case COMP_LUMA_YELLOW:
			ret = parseRange(buf, &Configfile.CompLumaYellow);
			if (strstr(buf, "range_from") != NULL)
			{
				Configfile.componentColor.platformSupport[COMP_LUMA][tvDataColor_YELLOW] = platformsupport(buf, &Configfile.CompLumaYellow);
			}
			break;
		case COMP_LUMA_CYAN:
			ret = parseRange(buf, &Configfile.CompLumaCyan);
			if (strstr(buf, "range_from") != NULL)
			{
				Configfile.componentColor.platformSupport[COMP_LUMA][tvDataColor_CYAN] = platformsupport(buf, &Configfile.CompLumaYellow);
			}
			break;
		case COMP_LUMA_MAGENTA:
			ret = parseRange(buf, &Configfile.CompLumaMagenta);
			if (strstr(buf, "range_from") != NULL)
			{
				Configfile.componentColor.platformSupport[COMP_LUMA][tvDataColor_MAGENTA] = platformsupport(buf, &Configfile.CompLumaMagenta);
			}
			break;
		case LOW_LATENCY_STATE:
			ret = parseRange(buf, &Configfile.lowLatencyState);
			break;
		case COLOR_TEMP_MODE:
			ret = parseRange_color(buf, &Configfile.colorTemp);
			break;
		case DIMMING_MODE:
			ret = parseRange_mode(buf, &Configfile.dimmingMode);
			break;
		case BACK_LIGHT_CTL:
			ret = parseRange_mode(buf, &Configfile.backLightCtl);
			break;
		case DOLBY_VISION_MODE:
			ret = parseRange_mode(buf, &Configfile.dolbyMode);
			break;
		case ASPECT_RATIO:
			ret = parseRange_mode(buf, &Configfile.aspectRatio);
			break;
		case PICTURE_MODE_FLAG:
			ret = parseRange_picturemode(buf, &Configfile.picmodeStruct);
			break;
		case VIDEO_SOURCE_FLAG:
			ret = parseRange_videoSource(buf, &Configfile.videoSrcStruct);
			break;
		case VIDEO_FRMT_FLAG:
			ret = parseRange_videoFormat(buf, &Configfile.videoFormtStruct);
			break;
		case VIDEO_FRAME_RATE:
			ret = parseRange_videoFramerate(buf, &Configfile.framerate);
			break;
		case DIM_LEVEL_FLAG:
			ret = parseRange_dimlevel(buf, &Configfile.dimmingLevel);
			break;
		case WB_RED_FLAG:
			ret = parseRange_wb(buf, &Configfile.wbRGB[0]);
			break;
		case WB_GREEN_FLAG:
			ret = parseRange_wb(buf, &Configfile.wbRGB[1]);
			break;
		case WB_BLUE_FLAG:
			ret = parseRange_wb(buf, &Configfile.wbRGB[2]);
			break;
		case GAMMA_TABLE_RED:
			ret = parseRange_wb(buf, &Configfile.gammaRGB[0]);
			break;
		case GAMMA_TABLE_GREEN:
			ret = parseRange_wb(buf, &Configfile.gammaRGB[1]);
			break;
		case GAMMA_TABLE_BLUE:
			ret = parseRange_wb(buf, &Configfile.gammaRGB[2]);
			break;
		default:
			ret = -1;
			break;
	}
	if (ret != 0)
	{
		fprintf(stderr, "Failure in parserange - %d.\n", errno);
	}
	return ret;
}

static void Usage()
{
	fprintf(stderr, "UT usage:\n");
	fprintf(stderr, "ds_hal <example.conf>\n");
}

int config_read(char *filename)
{
	int i = 0, mode = 0;
	char buf[MAX_BUF_SIZE] = {0};
	char section[MAX_KEY_LENGTH] = {0};

	if (filename == NULL)
	{
		Usage();
		return -1;
	}

	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Cannot open conf file - %d.\n", errno);
		return -1;
	}

	while (fgets(buf, sizeof(buf), file) != NULL)
	{
		if (buf[i] == '[')
		{
			mode = 0;

			if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "Brightness") == 0)
			{
				mode = BRIGHTNESS_MODE_FLAG;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_BRIGHTNESS;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "Contrast") == 0)
			{
				mode = CONTRAST_MODE_FLAG;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_CONTRAST;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "Saturation") == 0)
			{
				mode = SATURATION_MODE_FLAG;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_SATURATION;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "Sharpness") == 0)
			{
				mode = SHARPNESS_MODE_FLAG;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_SHARPNESS;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "Hue") == 0)
			{
				mode = HUE_MODE_FLAG;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_HUE;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "Backlight") == 0)
			{
				mode = BACKLIGHT_MODE_FLAG;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_BACKLIGHT;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentSaturationRed") == 0)
			{
				mode = COMP_SATURATION_RED;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_CMS_SATURATION_RED;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentSaturationGreen") == 0)
			{
				mode = COMP_SATURATION_GREEN;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_CMS_SATURATION_GREEN;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentSaturationBlue") == 0)
			{
				mode = COMP_SATURATION_BLUE;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_CMS_SATURATION_BLUE;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentSaturationYellow") == 0)
			{
				mode = COMP_SATURATION_YELLOW;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_CMS_SATURATION_YELLOW;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentSaturationCyan") == 0)
			{
				mode = COMP_SATURATION_CYAN;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_CMS_SATURATION_CYAN;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentSaturationMagenta") == 0)
			{
				mode = COMP_SATURATION_MAGENTA;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_CMS_SATURATION_MAGENTA;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentHueRed") == 0)
			{
				mode = COMP_HUE_RED;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_CMS_HUE_RED;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentHueBlue") == 0)
			{
				mode = COMP_HUE_BLUE;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_CMS_HUE_BLUE;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentHueGreen") == 0)
			{
				mode = COMP_HUE_GREEN;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_CMS_HUE_GREEN;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentHueYellow") == 0)
			{
				mode = COMP_HUE_YELLOW;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_CMS_HUE_YELLOW;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentHueCyan") == 0)
			{
				mode = COMP_HUE_CYAN;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_CMS_HUE_CYAN;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentHueMagenta") == 0)
			{
				mode = COMP_HUE_MAGENTA;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_CMS_HUE_MAGENTA;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentLumaRed") == 0)
			{
				mode = COMP_LUMA_RED;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_CMS_LUMA_RED;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentLumaBlue") == 0)
			{
				mode = COMP_LUMA_BLUE;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_CMS_LUMA_BLUE;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentLumaGreen") == 0)
			{
				mode = COMP_LUMA_GREEN;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_CMS_LUMA_GREEN;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentLumaYellow") == 0)
			{
				mode = COMP_LUMA_YELLOW;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_CMS_LUMA_YELLOW;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentLumaCyan") == 0)
			{
				mode = COMP_LUMA_CYAN;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_CMS_LUMA_CYAN;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentLumaMagenta") == 0)
			{
				mode = COMP_LUMA_MAGENTA;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_CMS_LUMA_MAGENTA;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "LowLatencyState") == 0)
			{
				mode = LOW_LATENCY_STATE;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_LOWLATENCY_STATE;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ColorTemperature") == 0)
			{
				mode = COLOR_TEMP_MODE;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_COLOR_TEMPERATURE;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "DimmingMode") == 0)
			{
				mode = DIMMING_MODE;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_DIMMINGMODE;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "BacklightControl") == 0)
			{
				mode = BACK_LIGHT_CTL;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_BACKLIGHT;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "DolbyVisionMode") == 0)
			{
				mode = DOLBY_VISION_MODE;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_DOLBY_MODE;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "AspectRatio") == 0)
			{
				mode = ASPECT_RATIO;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_ASPECT_RATIO;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "PictureMode") == 0)
			{
				mode = PICTURE_MODE_FLAG;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "VideoSource") == 0)
			{
				mode = VIDEO_SOURCE_FLAG;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "VideoFormat") == 0)
			{
				mode = VIDEO_FRMT_FLAG;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "VideoFrameRate") == 0)
			{
				mode = VIDEO_FRAME_RATE;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "TMAX") == 0)
			{
				mode = DIM_LEVEL_FLAG;
				Configfile.pq_paramIndex.videoSourceValue[paramFlag] = PQ_PARAM_LOCALDIMMING_LEVEL;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "WhiteBalanceRed") == 0)
			{
				mode = WB_RED_FLAG;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "WhiteBalanceGreen") == 0)
			{
				mode = WB_GREEN_FLAG;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "WhiteBalanceBlue") == 0)
			{
				mode = WB_BLUE_FLAG;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "GammaTableRed") == 0)
			{
				mode = GAMMA_TABLE_RED;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "GammaTableGreen") == 0)
			{
				mode = GAMMA_TABLE_GREEN;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "GammaTableBlue") == 0)
			{
				mode = GAMMA_TABLE_BLUE;
			}
			paramFlag++;
		}
		else
		{
			int ret = fillstructure(buf, mode);
			if (ret != 0)
			{
				fprintf(stderr, "Failure in fillstructure - %d.\n", errno);
				return -1;
			}
		}
	}

	/*TvColurTemp source offset*/
	strcpy(Configfile.colorTempSourceOffset.source[0], "ALLSRC OFFSET");
	Configfile.colorTempSourceOffset.videoSourceValue[0] = ALL_SRC_OFFSET;
	strcpy(Configfile.colorTempSourceOffset.source[1], "HDMI OFFSET");
	Configfile.colorTempSourceOffset.videoSourceValue[1] = HDMI_OFFSET;
	strcpy(Configfile.colorTempSourceOffset.source[2], "TV OFFSET");
	Configfile.colorTempSourceOffset.videoSourceValue[2] = TV_OFFSET;
	strcpy(Configfile.colorTempSourceOffset.source[3], "AV OFFSET");
	Configfile.colorTempSourceOffset.videoSourceValue[3] = AV_OFFSET;
	Configfile.colorTempSourceOffset.size = MAX_OFFSET + 1; // ALL source start with -1

    Configfile.componentColor.size = colorFlag;
	Configfile.pq_paramIndex.size = paramFlag;
	fclose(file);
	return 1;
}
/** @} */ // End of TV_Settings_HALTEST_CONFIG_READ
/** @} */ // End of TV_Settings_HALTEST
/** @} */ // End of TV_Settings
/** @} */ // End of HPK
