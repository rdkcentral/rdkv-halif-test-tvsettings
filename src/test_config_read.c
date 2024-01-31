#include "test_config_read.h"

struct tvSettingConf Configfile = {0};

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
			Count= 0;
			printf("\n");
			if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "dvmodes") == 0) {
				mode = DV_MODE_FLAG;
			}else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "hlgmodes") == 0) {
				mode = HLG_MODE_FLAG;
			}else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "hdr10modes") == 0) {
				mode = HDR10_MODE_FLAG;
			}else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "picmodes") == 0) {
				mode = PIC_MODE_FLAG;
			}else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "dimmodes") == 0) {
				mode = DIM_MODE_FLAG;
			}else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "videoformat") == 0) {
				mode = VIDEO_FORMAT_MODE_FLAG;
			}else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "videoresolution") == 0) {
				mode = VIDEO_RESOLUTION_MODE_FLAG;
			}else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "videoframerate") == 0) {
				mode = FRAMERATE_MODE_FLAG;
			}else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "videosource") == 0) {
                mode = VIDEO_SOURCE_FLAG;
			}else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "backlightmode") == 0) {
				mode = BACK_LIGHT_FLAG;
			}else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ldimmode") == 0) {
				mode = LDIM_MODE_FLAG;
			}
			else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "colorTemperature") == 0) {
				mode = COLOR_TEMP_FLAG;
			} else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "colorTempSourceOffset") == 0) {
                		mode = COLOR_TEMPSOURCE_OFFSET_FLAG;
			}else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "AspectRatio") == 0) {
				mode = ASPECT_RATIO_FLAG;
			}else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentColor") == 0) {
				mode = COMPONENT_CLR_FLAG;
			}else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "ComponentSaturation") == 0) {
				mode = COMPONENT_SATURATION_FLAG;
			}



		}else {

			if(DV_MODE_FLAG == mode){
				if (sscanf(buf, "%s %hd", Configfile.dv_modes.modeName[Count], &Configfile.dv_modes.modeId[Count]) == 2) {
					printf("**%s  %d***\n", Configfile.dv_modes.modeName[Count], Configfile.dv_modes.modeId[Count]);
					Count++;
				}
				
			}else if(HLG_MODE_FLAG == mode){
				if (sscanf(buf, "%s %hd", Configfile.hlg_modes.modeName[Count], &Configfile.hlg_modes.modeId[Count]) == 2) {
					printf("**%s  %d***\n", Configfile.hlg_modes.modeName[Count], Configfile.hlg_modes.modeId[Count]);
					Count++;
				}
			}else if(HDR10_MODE_FLAG == mode){
				if (sscanf(buf, "%s %hd", Configfile.hdr10_modes.modeName[Count], &Configfile.hdr10_modes.modeId[Count]) == 2) {
					Count++;
				}
			}else if(PIC_MODE_FLAG == mode){
				if (sscanf(buf, "%s %hd", Configfile.dimmode.modeName[Count], &Configfile.dimmode.modeId[Count]) == 2) {
					printf("**%s  %d***\n", Configfile.dimmode.modeName[Count], Configfile.dimmode.modeId[Count]);
					Count++;
				}
			}else if(DIM_MODE_FLAG == mode){
				 if (sscanf(buf, "%s %hd", Configfile.videoformat.modeName[Count], &Configfile.videoformat.modeId[Count]) == 2) {
					printf("**%s  %d***\n", Configfile.videoformat.modeName[Count], Configfile.videoformat.modeId[Count]);
					Count++;
				 }
			}else if(VIDEO_FORMAT_MODE_FLAG == mode){
				if (sscanf(buf, "%s %hd", Configfile.videoformat.modeName[Count], &Configfile.videoformat.modeId[Count]) == 2) {
                                        printf("**%s  %d***\n", Configfile.videoformat.modeName[Count], Configfile.videoformat.modeId[Count]);
                                        Count++;
                                }
			}else if(VIDEO_RESOLUTION_MODE_FLAG == mode){
				if (sscanf(buf, "%s %hd", Configfile.videoResolution.modeName[Count], &Configfile.videoResolution.modeId[Count]) == 2) {
                                        printf("**%s  %d***\n", Configfile.videoResolution.modeName[Count], Configfile.videoResolution.modeId[Count]);
                                        Count++;
                                }

			}else if(FRAMERATE_MODE_FLAG == mode){
				if (sscanf(buf, "%s %hd", Configfile.videoframerate.modeName[Count], &Configfile.videoframerate.modeId[Count]) == 2) {
                                        printf("**%s  %d***\n", Configfile.videoframerate.modeName[Count], Configfile.videoframerate.modeId[Count]);
                                        Count++;
                                }

			}else if(VIDEO_SOURCE_FLAG == mode){
                                if (sscanf(buf, "%s %hd", Configfile.videoSources.modeName[Count], &Configfile.videoSources.modeId[Count]) == 2) {
                                        printf("**%s  %d***\n", Configfile.videoSources.modeName[Count], Configfile.videoSources.modeId[Count]);
                                        Count++;
                                }

                        }else if(BACK_LIGHT_FLAG == mode){
                                if (sscanf(buf, "%s %hd", Configfile.backlightModes.modeName[Count], &Configfile.backlightModes.modeId[Count]) == 2) {
                                        printf("**%s  %d***\n", Configfile.backlightModes.modeName[Count], Configfile.backlightModes.modeId[Count]);
                                        Count++;
                                }

                        }else if(LDIM_MODE_FLAG == mode){
                                if (sscanf(buf, "%s %hd", Configfile.ldimMode.modeName[Count], &Configfile.ldimMode.modeId[Count]) == 2) {
                                        printf("**%s  %d***\n", Configfile.ldimMode.modeName[Count], Configfile.ldimMode.modeId[Count]);
                                        Count++;
                                }

                        }else if(COLOR_TEMP_FLAG == mode){
				if (sscanf(buf, "%s %hd", Configfile.colorTemperature.modeName[Count], &Configfile.colorTemperature.modeId[Count]) == 2) {
					printf("**%s  %d***\n", Configfile.colorTemperature.modeName[Count], Configfile.colorTemperature.modeId[Count]);
					Count++;
				}
			}else if(COLOR_TEMPSOURCE_OFFSET_FLAG == mode){
                                if (sscanf(buf, "%s %hd", Configfile.colorTempSourceOffset.modeName[Count], &Configfile.colorTempSourceOffset.modeId[Count]) == 2) {
                                        printf("**%s  %d***\n", Configfile.colorTempSourceOffset.modeName[Count], Configfile.colorTempSourceOffset.modeId[Count]);
                                        Count++;
                                }
                        }else if(ASPECT_RATIO_FLAG == mode){
				if (sscanf(buf, "%s %hd", Configfile.AspectRatio.modeName[Count], &Configfile.AspectRatio.modeId[Count]) == 2) {
					printf("**%s  %d***\n", Configfile.AspectRatio.modeName[Count], Configfile.AspectRatio.modeId[Count]);
					Count++;
				}
			}else if(COMPONENT_CLR_FLAG == mode){
                                if (sscanf(buf, "%s %hd", Configfile.componentColor.modeName[Count], &Configfile.componentColor.modeId[Count]) == 2) {
                                        printf("**%s  %d***\n", Configfile.componentColor.modeName[Count], Configfile.componentColor.modeId[Count]);
                                        Count++;
                                }

                        }else if(COMPONENT_SATURATION_FLAG == mode){
                                if (sscanf(buf, "%s %hd", Configfile.componentSaturation.modeName[Count], &Configfile.componentSaturation.modeId[Count]) == 2) {
                                        printf("**%s  %d***\n", Configfile.componentSaturation.modeName[Count], Configfile.componentSaturation.modeId[Count]);
                                        Count++;
                                }

                        }


		}
	}
	
	fclose(file);
	return 1;
}
