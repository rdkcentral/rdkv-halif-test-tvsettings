#include "test_config_read.h"

struct TvSettingConfig Configfile = { 0 };

void parseRange(const char* buf, struct DisplayPictureMode* mode) {
    if (sscanf(buf, "range_from = %hd", &mode->rangeFrom) == 1) {
        printf("Range From: %d\n", mode->rangeFrom);
    }
    else if (sscanf(buf, "range_to = %hd", &mode->rangeTo) == 1) {
        printf("Range To: %d\n", mode->rangeTo);
    }
}

void parseRange_color(const char* buf, struct DisplayColorMode* mode) {

    char input[200] = { 0 };
    int i = 0;
    size_t len = 0;

    if (sscanf(buf, "range = %s", input) == 1) {

        while (i < MAX_COLOR_TEMP && sscanf(input+len, "%[^,]", &mode->colorStruct.colorTemp[i])== 1) {
            // Move to the next substring after the comma
            len += strlen(mode->colorStruct.colorTemp[i]);
            
            mode->colorStruct.colorTempValue[i] = i;
            printf("Range From: %d\n", mode->colorStruct.colorTemp[i]);
            // Skip the comma if present
            if (*(input+len) == ',') {
                len++; // Move past the comma
                i++;     // Move to the next array element
            }
            else {
                break;   // Exit the loop if no more commas are found
            }
        }
    }

}

void parseRange_mode(const char* buf, struct DisplayColorMode* mode) {

    char input[200] = { 0 };
    int i = 0;
    size_t len = 0;

    if (sscanf(buf, "range = %s", input) == 1) {

        while (i < MAX_NAME_SIZE && sscanf(input + len, "%[^,]", &mode->modeName[i]) == 1) {
            // Move to the next substring after the comma
            len += strlen(mode->modeName[i]);

            mode->modevalue[i] = i;
            printf("Diming mode: %d\n", mode->modevalue[i]);  // Skip the comma if present
            if (*(input + len) == ',') {
                len++; // Move past the comma
                i++;     // Move to the next array element
            }
            else {
                break;   // Exit the loop if no more commas are found
            }
        }
    }

}

void parseRange_picturemode(const char* buf, struct PictureMode *picmode) {

    char input[200] = { 0 };
    int i = 0;
    size_t len = 0;

    if (sscanf(buf, "range = %s", input) == 1) {

        while (i < MAX_NAME_SIZE && sscanf(input + len, "%[^,]", &picmode->pqMode[i]) == 1) {
            // Move to the next substring after the comma
            len += strlen(picmode->pqMode[i]);

            
            printf("Diming mode: %s\n", picmode->pqMode[i]);  // Skip the comma if present
            if (*(input + len) == ',') {
                len++; // Move past the comma
                i++;     // Move to the next array element
            }
            else {
                break;   // Exit the loop if no more commas are found
            }
        }
    }
    if (sscanf(buf, "index = %s", input) == 1) {
        len = 0;
        while (i < MAX_NAME_SIZE && sscanf(input+len, "%d,", &picmode->pqValue[i]) == 1) {
            // Move to the next substring after the comma
            len += strcspn(input, ",") + 1;
            i++;
        }
    }

}

void parseRange_videoSource(const char* buf, struct videoSource *videoSrcStruct) {

    char input[200] = { 0 };
    int i = 0;
    size_t len = 0;

    if (sscanf(buf, "range = %s", input) == 1) {

        while (i < MAX_NAME_SIZE && sscanf(input + len, "%[^,]", &videoSrcStruct->source[i]) == 1) {
            // Move to the next substring after the comma
            len += strlen(videoSrcStruct->source[i]);


            printf("Diming mode: %s\n", videoSrcStruct->source[i]);  // Skip the comma if present
            if (*(input + len) == ',') {
                len++; // Move past the comma
                i++;     // Move to the next array element
            }
            else {
                break;   // Exit the loop if no more commas are found
            }
        }
    }
    if (sscanf(buf, "index = %s", input) == 1) {
        len = 0;
        while (i < MAX_NAME_SIZE && sscanf(input + len, "%d,", &videoSrcStruct->videoSourceValue[i]) == 1) {
            // Move to the next substring after the comma
            len += strcspn(input, ",") + 1;
            i++;
        }
    }

}

void parseRange_videoFormat(const char* buf, struct videoFormat* videoFormt) {

    char input[200] = { 0 };
    int i = 0;
    size_t len = 0;

    if (sscanf(buf, "range = %s", input) == 1) {

        while (i < MAX_NAME_SIZE && sscanf(input + len, "%[^,]", &videoFormt->videoFormat[i]) == 1) {
            // Move to the next substring after the comma
            len += strlen(videoFormt->videoFormat[i]);


            printf("Diming mode: %s\n", videoFormt->videoFormat[i]);  // Skip the comma if present
            if (*(input + len) == ',') {
                len++; // Move past the comma
                i++;     // Move to the next array element
            }
            else {
                break;   // Exit the loop if no more commas are found
            }
        }
    }
    if (sscanf(buf, "index = %s", input) == 1) {
        len = 0;
        while (i < MAX_NAME_SIZE && sscanf(input + len, "%d,", &videoFormt->videoFormatValue[i]) == 1) {
            // Move to the next substring after the comma
            len += strcspn(input, ",") + 1;
            i++;
        }
    }

}

void parseRange_videoFramerate(const char* buf, struct videoFrameRate* videoFramerate) {

    char input[200] = { 0 };
    int i = 0;
    size_t len = 0;

    if (sscanf(buf, "range = %s", input) == 1) {

        while (i < MAX_NAME_SIZE && sscanf(input + len, "%[^,]", &videoFramerate->frameRate[i]) == 1) {
            // Move to the next substring after the comma
            len += strlen(videoFramerate->frameRate[i]);

            videoFramerate->frameRateValue[i] = i;
            printf("Diming mode: %s\n", videoFramerate->frameRate[i]);  // Skip the comma if present
            if (*(input + len) == ',') {
                len++; // Move past the comma
                i++;     // Move to the next array element
            }
            else {
                break;   // Exit the loop if no more commas are found
            }
        }
    }
}

void parseRange_dimlevel(const char* buf, struct DimmingLevel* dimlevel) {

    char input[200] = { 0 };
    int i = 0;
    size_t len = 0;

    if (sscanf(buf, "range_from = %hd", &dimlevel->rangeFrom) == 1) {
        printf("Range From: %d\n", dimlevel->rangeFrom);
    }
    else if (sscanf(buf, "range_to = %hd", &dimlevel->rangeTo) == 1) {
        printf("Range To: %d\n", dimlevel->rangeTo);
    }

    if (sscanf(buf, "DimmingLevel = %s", input) == 1) {

        while (i < MAX_NAME_SIZE && sscanf(input + len, "%[^,]", &dimlevel->dimModeName[i]) == 1) {
            // Move to the next substring after the comma
            len += strlen(dimlevel->dimModeName[i]);

            dimlevel->dimModevalue[i] = i;
            printf("Diming mode: %s\n", dimlevel->dimModeName[i]);  // Skip the comma if present
            if (*(input + len) == ',') {
                len++; // Move past the comma
                i++;     // Move to the next array element
            }
            else {
                break;   // Exit the loop if no more commas are found
            }
        }
    }
}

void parseRange_wb(const char* buf, struct WhiteBalanceGamma* wbRGBGamma)
{
    char input[200] = { 0 };
    int i = 0;
    size_t len = 0;

    if (sscanf(buf, "range.gain.from = %hd", &wbRGBGamma->rangeGainFrom) == 1) {
        printf("Range From: %d\n", wbRGBGamma->rangeGainFrom);
    }
    else if (sscanf(buf, "range.gain.to = %hd", &wbRGBGamma->rangeGainTo) == 1) {
        printf("Range To: %d\n", wbRGBGamma->rangeGainTo);
    }

    if (sscanf(buf, "range.offset.from = %hd", &wbRGBGamma->rangeOffsetFrom) == 1) {
        printf("Range From: %d\n", wbRGBGamma->rangeOffsetFrom);
    }
    else if (sscanf(buf, "range.offset.to = %hd", &wbRGBGamma->rangeOffsetTo) == 1) {
        printf("Range To: %d\n", wbRGBGamma->rangeOffsetTo);
    }

    if (sscanf(buf, "gammaIndex_from = %hd", &wbRGBGamma->rangeOffsetFrom) == 1) {
        printf("Range From: %d\n", wbRGBGamma->rangeOffsetFrom);
    }
    else if (sscanf(buf, "gammaIndex_to = %hd", &wbRGBGamma->rangeOffsetTo) == 1) {
        printf("Range To: %d\n", wbRGBGamma->rangeOffsetTo);
    }

    if (sscanf(buf, "ColorTemperature = %s", input) == 1) {

        while (i < MAX_NAME_SIZE && sscanf(input + len, "%[^,]", &wbRGBGamma->colorStruct.colorTemp[i]) == 1) {
            // Move to the next substring after the comma
            len += strlen(wbRGBGamma->colorStruct.colorTemp[i]);

            wbRGBGamma->colorStruct.colorTempValue[i] = i;
            printf("Diming mode: %s\n", wbRGBGamma->colorStruct.colorTemp[i]);  // Skip the comma if present
            if (*(input + len) == ',') {
                len++; // Move past the comma
                i++;     // Move to the next array element
            }
            else {
                break;   // Exit the loop if no more commas are found
            }
        }
    }

    if (sscanf(buf, "source = %s", input) == 1) {

        while (i < MAX_NAME_SIZE && sscanf(input + len, "%[^,]", &wbRGBGamma->videoSrcStruct.source[i]) == 1) {
            // Move to the next substring after the comma
            len += strlen(wbRGBGamma->videoSrcStruct.source[i]);

            wbRGBGamma->videoSrcStruct.videoSourceValue[i] = i;
            printf("Diming mode: %s\n", wbRGBGamma->videoSrcStruct.source[i]);  // Skip the comma if present
            if (*(input + len) == ',') {
                len++; // Move past the comma
                i++;     // Move to the next array element
            }
            else {
                break;   // Exit the loop if no more commas are found
            }
        }
    }
}

int fillstructure(const char *buf , int mode)
{
    switch (mode) {
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
        break;
    case COMP_SATURATION_GREEN:
        parseRange(buf, &Configfile.CompSaturationGreen);
        break;
    case COMP_SATURATION_BLUE:
        parseRange(buf, &Configfile.CompSaturationBlue);
        break;
    case COMP_SATURATION_YELLOW:
        parseRange(buf, &Configfile.CompSaturationYellow);
        break;
    case COMP_SATURATION_CYAN:
        parseRange(buf, &Configfile.CompSaturationCyan);
        break;
    case COMP_SATURATION_MAGENTA:
        parseRange(buf, &Configfile.CompSaturationMagenta);
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
        
    case  VIDEO_FRAME_RATE:
        parseRange_videoFramerate(buf, &Configfile.framerate);
        break;

    case  DIM_LEVEL_FLAG:
        parseRange_dimlevel(buf, &Configfile.dimmingLevel);
        break;
    case  WB_RED_FLAG:
        parseRange_wb(buf, &Configfile.wbRGB[0]);
        break;

    case  WB_GREEN_FLAG:
        parseRange_wb(buf, &Configfile.wbRGB[1]);
        break;

    case  WB_BLUE_FLAG:
        parseRange_wb(buf, &Configfile.wbRGB[2]);
        break;

    case GAMMA_TABLE_RED:
        parseRange_wb(buf, &Configfile.gammaRGB[0]);
        break;

    case  GAMMA_TABLE_GREEN:
        parseRange_wb(buf, &Configfile.gammaRGB[1]);
        break;
    case  GAMMA_TABLE_BLUE:
        parseRange_wb(buf, &Configfile.gammaRGB[2]);
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
	int i =0, mode, Count =0;
	char buf[MAX_BUF_SIZE]={0};
	char section[MAX_KEY_LENGTH];
	
	if(filename == NULL){
		Usage();
		return -1;
	}	

	FILE *file = fopen(filename, "r");
	if(file == NULL){
		fprintf(stderr, "Cannot open conf file - %d.\n", errno);
		return -1;
	}
	
	while (fgets(buf, sizeof(buf), file) != NULL) {
	    if (buf[i] == '[') {
		mode = 0;
		Count = 0;
		printf("\n");
		if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "Brightness") == 0) {
		    mode = BRIGHTNESS_MODE_FLAG;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "Contrast") == 0) {
		    mode = CONTRAST_MODE_FLAG;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "Saturation") == 0) {
		    mode = SATURATION_MODE_FLAG;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "Sharpness") == 0) {
		    mode = SHARPNESS_MODE_FLAG;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "Hue") == 0) {
		    mode = HUE_MODE_FLAG;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "Backlight") == 0) {
		    mode = BACKLIGHT_MODE_FLAG;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentSaturationRed") == 0) {
		    mode = COMP_SATURATION_RED;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentSaturationGreen") == 0) {
		    mode = COMP_SATURATION_GREEN;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentSaturationBlue") == 0) {
		    mode = COMP_SATURATION_BLUE;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentSaturationYellow") == 0) {
		    mode = COMP_SATURATION_YELLOW;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentSaturationCyan") == 0) {
		    mode = COMP_SATURATION_CYAN;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentSaturationMagenta") == 0) {
		    mode = COMP_SATURATION_MAGENTA;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentHueRed") == 0) {
		    mode = COMP_HUE_RED;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentHueBlue") == 0) {
		    mode = COMP_HUE_BLUE;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentHueGreen") == 0) {
		    mode = COMP_HUE_GREEN;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentHueYellow") == 0) {
		    mode = COMP_HUE_YELLOW;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentHueCyan") == 0) {
		    mode = COMP_HUE_CYAN;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentHueMagenta") == 0) {
		    mode = COMP_HUE_MAGENTA;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentLumaRed") == 0) {
		    mode = COMP_LUMA_RED;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentLumaBlue") == 0) {
		    mode = COMP_LUMA_BLUE;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentLumaGreen") == 0) {
		    mode = COMP_LUMA_GREEN;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentLumaYellow") == 0) {
		    mode = COMP_LUMA_YELLOW;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentLumaCyan") == 0) {
		    mode = COMP_LUMA_CYAN;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentLumaMagenta") == 0) {
		    mode = COMP_LUMA_MAGENTA;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "LowLatencyState") == 0) {
		    mode = LOW_LATENCY_STATE;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ColorTemperature") == 0) {
		    mode = COLOR_TEMP_MODE;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "DimmingMode") == 0) {
		    mode = DIMMING_MODE;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "BacklightControl") == 0) {
		    mode = BACK_LIGHT_CTL;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "DolbyVisionMode") == 0) {
		    mode = DOLBY_VISION_MODE;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "AspectRatio") == 0) {
		    mode = ASPECT_RATIO;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "PictureMode") == 0) {
		    mode = PICTURE_MODE_FLAG;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "VideoSource") == 0) {
		    mode = VIDEO_SOURCE_FLAG;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "VideoFormat") == 0) {
		    mode = VIDEO_FRMT_FLAG;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "VideoFrameRate") == 0) {
		    mode = VIDEO_FRAME_RATE;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "TMAX") == 0) {
		    mode = DIM_LEVEL_FLAG;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "WhiteBalanceRed") == 0) {
		    mode = WB_RED_FLAG;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "WhiteBalanceGreen") == 0) {
			mode = WB_GREEN_FLAG;
		}
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "WhiteBalanceBlue") == 0) {
		     mode = WB_BLUE_FLAG;
		 }
		else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "GammaTableRed") == 0) {
		     mode = GAMMA_TABLE_RED;
		 }else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "GammaTableGreen") == 0) {
		     mode = GAMMA_TABLE_GREEN;
		 }else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "GammaTableBlue") == 0) {
		      mode = GAMMA_TABLE_BLUE;
		 } 
	    }
	    else {
		fillstructure(buf, mode);
	    }
	}	
	fclose(file);
	return 1;
}
