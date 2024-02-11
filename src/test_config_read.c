#include "test_config_read.h"
#include "../../include/tvTypes.h"

struct TvSettingConfig Configfile = {0};
int colorFlag = 0;
int paramFlag = 0;

void parseRange(const char *buf, struct DisplayPictureMode *mode)
{
	if (sscanf(buf, "range_from = %hd", &mode->rangeFrom) == 1)
	{
		printf("Range From: %d\n", mode->rangeFrom);
	}
	else if (sscanf(buf, "range_to = %hd", &mode->rangeTo) == 1)
	{
		printf("Range To: %d\n", mode->rangeTo);
	}
}

void parseRange_color(const char *buf, struct DisplayColorMode *mode)
{
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
}

void parseRange_mode(const char *buf, struct DisplayColorMode *mode)
{
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
}

void parseRange_picturemode(const char *buf, struct PictureMode *picmode)
{
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
}

void parseRange_videoSource(const char *buf, struct videoSource *videoSrcStruct)
{
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
}

void parseRange_videoFormat(const char *buf, struct videoFormat *videoFormt)
{
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
}

void parseRange_videoFramerate(const char *buf, struct videoFrameRate *videoFramerate)
{

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
}

void parseRange_dimlevel(const char *buf, struct DimmingLevel *dimlevel)
{

	char input[200] = {0};
	int i = 0;
	size_t len = 0;

	if (sscanf(buf, "range_from = %hd", &dimlevel->rangeFrom) == 1)
	{
		printf("Range From: %d\n", dimlevel->rangeFrom);
	}
	else if (sscanf(buf, "range_to = %hd", &dimlevel->rangeTo) == 1)
	{
		printf("Range To: %d\n", dimlevel->rangeTo);
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
}

void parseRange_wb(const char *buf, struct WhiteBalanceGamma *wbRGBGamma)
{
	char input[200] = {0};
	int i = 0;
	size_t len = 0;

	if (sscanf(buf, "range.gain.from = %d", &wbRGBGamma->rangeGainFrom) == 1)
	{
		printf("Range From: %d\n", wbRGBGamma->rangeGainFrom);
	}
	else if (sscanf(buf, "range.gain.to = %d", &wbRGBGamma->rangeGainTo) == 1)
	{
		printf("Range To: %d\n", wbRGBGamma->rangeGainTo);
	}

	if (sscanf(buf, "range.offset.from = %d", &wbRGBGamma->rangeOffsetFrom) == 1)
	{
		printf("Range From: %d\n", wbRGBGamma->rangeOffsetFrom);
	}
	else if (sscanf(buf, "range.offset.to = %d", &wbRGBGamma->rangeOffsetTo) == 1)
	{
		printf("Range To: %d\n", wbRGBGamma->rangeOffsetTo);
	}

	if (sscanf(buf, "gammaIndex_from = %d", &wbRGBGamma->rangeOffsetFrom) == 1)
	{
		printf("Range From: %d\n", wbRGBGamma->rangeOffsetFrom);
	}
	else if (sscanf(buf, "gammaIndex_to = %d", &wbRGBGamma->rangeOffsetTo) == 1)
	{
		printf("Range To: %d\n", wbRGBGamma->rangeOffsetTo);
	}

	if (sscanf(buf, "range_from = %d", &wbRGBGamma->rangeFrom) == 1)
	{
		printf("Range From: %d\n", wbRGBGamma->rangeFrom);
	}
	else if (sscanf(buf, "range_to = %d", &wbRGBGamma->rangeTo) == 1)
	{
		printf("Range To: %d\n", wbRGBGamma->rangeTo);
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
}

int fillstructure(const char *buf, int mode)
{
	switch (mode)
	{
	case BRIGHTNESS_MODE_FLAG:
		parseRange(buf, &Configfile.brightness);
		break;
	case CONTRAST_MODE_FLAG:
		parseRange(buf, &Configfile.contrast);
		break;
	case SATURATION_MODE_FLAG:
		parseRange(buf, &Configfile.saturation);
		break;
	case SHARPNESS_MODE_FLAG:
		parseRange(buf, &Configfile.sharpness);
		break;
	case HUE_MODE_FLAG:
		parseRange(buf, &Configfile.hue);
		break;
	case BACKLIGHT_MODE_FLAG:
		parseRange(buf, &Configfile.backlight);
		break;
	case COMP_SATURATION_RED:
		parseRange(buf, &Configfile.CompSaturationRed);
		if (strstr(buf, "range_from") != NULL)
		{
			strcpy(Configfile.componentColor.modeName[colorFlag], "RED");
			Configfile.componentColor.modeId[colorFlag] = tvDataColor_RED;
			colorFlag++;
		}
		break;
	case COMP_SATURATION_GREEN:
		parseRange(buf, &Configfile.CompSaturationGreen);
		if (strstr(buf, "range_from") != NULL)
		{
			strcpy(Configfile.componentColor.modeName[colorFlag], "GREEN");
			Configfile.componentColor.modeId[colorFlag] = tvDataColor_GREEN;
			colorFlag++;
		}
		break;
	case COMP_SATURATION_BLUE:
		parseRange(buf, &Configfile.CompSaturationBlue);
		if (strstr(buf, "range_from") != NULL)
		{
			strcpy(Configfile.componentColor.modeName[colorFlag], "BLUE");
			Configfile.componentColor.modeId[colorFlag] = tvDataColor_BLUE;
			colorFlag++;
		}
		break;
	case COMP_SATURATION_YELLOW:
		parseRange(buf, &Configfile.CompSaturationYellow);
		if (strstr(buf, "range_from") != NULL)
		{
			strcpy(Configfile.componentColor.modeName[colorFlag], "YELLOW");
			Configfile.componentColor.modeId[colorFlag] = tvDataColor_YELLOW;
			colorFlag++;
		}
		break;
	case COMP_SATURATION_CYAN:
		parseRange(buf, &Configfile.CompSaturationCyan);
		if (strstr(buf, "range_from") != NULL)
		{
			strcpy(Configfile.componentColor.modeName[colorFlag], "CYAN");
			Configfile.componentColor.modeId[colorFlag] = tvDataColor_CYAN;
			colorFlag++;
		}
		break;
	case COMP_SATURATION_MAGENTA:
		parseRange(buf, &Configfile.CompSaturationMagenta);
		if (strstr(buf, "range_from") != NULL)
		{
			strcpy(Configfile.componentColor.modeName[colorFlag], "MAGENTA");
			Configfile.componentColor.modeId[colorFlag] = tvDataColor_MAGENTA;
			colorFlag++;
		}
		break;
	case COMP_HUE_RED:
		parseRange(buf, &Configfile.CompHueRed);
		break;
	case COMP_HUE_GREEN:
		parseRange(buf, &Configfile.CompHueGreen);
		break;
	case COMP_HUE_BLUE:
		parseRange(buf, &Configfile.CompHueBlue);
		break;
	case COMP_HUE_YELLOW:
		parseRange(buf, &Configfile.CompHueYellow);
		break;
	case COMP_HUE_CYAN:
		parseRange(buf, &Configfile.CompHueCyan);
		break;
	case COMP_HUE_MAGENTA:
		parseRange(buf, &Configfile.CompHueMagenta);
		break;
	case COMP_LUMA_RED:
		parseRange(buf, &Configfile.CompLumaRed);
		break;
	case COMP_LUMA_GREEN:
		parseRange(buf, &Configfile.CompLumaGreen);
		break;
	case COMP_LUMA_BLUE:
		parseRange(buf, &Configfile.CompLumaBlue);
		break;
	case COMP_LUMA_YELLOW:
		parseRange(buf, &Configfile.CompLumaYellow);
		break;
	case COMP_LUMA_CYAN:
		parseRange(buf, &Configfile.CompLumaCyan);
		break;
	case COMP_LUMA_MAGENTA:
		parseRange(buf, &Configfile.CompLumaMagenta);
		break;
	case LOW_LATENCY_STATE:
		parseRange(buf, &Configfile.lowLatencyState);
		break;
	case COLOR_TEMP_MODE:
		parseRange_color(buf, &Configfile.colorTemp);
		break;
	case DIMMING_MODE:
		parseRange_mode(buf, &Configfile.dimmingMode);
		break;
	case BACK_LIGHT_CTL:
		parseRange_mode(buf, &Configfile.backLightCtl);
		break;
	case DOLBY_VISION_MODE:
		parseRange_mode(buf, &Configfile.dolbyMode);
		break;
	case ASPECT_RATIO:
		parseRange_mode(buf, &Configfile.aspectRatio);
		break;
	case PICTURE_MODE_FLAG:
		parseRange_picturemode(buf, &Configfile.picmodeStruct);
		break;
	case VIDEO_SOURCE_FLAG:
		parseRange_videoSource(buf, &Configfile.videoSrcStruct);
		break;
	case VIDEO_FRMT_FLAG:
		parseRange_videoFormat(buf, &Configfile.videoFormtStruct);
		break;
	case VIDEO_FRAME_RATE:
		parseRange_videoFramerate(buf, &Configfile.framerate);
		break;
	case DIM_LEVEL_FLAG:
		parseRange_dimlevel(buf, &Configfile.dimmingLevel);
		break;
	case WB_RED_FLAG:
		parseRange_wb(buf, &Configfile.wbRGB[0]);
		break;
	case WB_GREEN_FLAG:
		parseRange_wb(buf, &Configfile.wbRGB[1]);
		break;
	case WB_BLUE_FLAG:
		parseRange_wb(buf, &Configfile.wbRGB[2]);
		break;
	case GAMMA_TABLE_RED:
		parseRange_wb(buf, &Configfile.gammaRGB[0]);
		break;
	case GAMMA_TABLE_GREEN:
		parseRange_wb(buf, &Configfile.gammaRGB[1]);
		break;
	case GAMMA_TABLE_BLUE:
		parseRange_wb(buf, &Configfile.gammaRGB[2]);
		break;
	default:
		break;
	}
	return 0;
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
				printf("aspect ratio \n");
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
			fillstructure(buf, mode);
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
