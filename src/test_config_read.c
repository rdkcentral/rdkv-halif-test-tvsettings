#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX_KEY_LENGTH 50
#define MAX_BUF_SIZE 2048
#define DV_MODE_FLAG 				0x01
#define HLG_MODE_FLAG 				0x02
#define HDR10_MODE_FLAG 			0x03
#define PIC_MODE_FLAG 				0x04
#define DIM_MODE_FLAG 				0x05
#define VIDEO_FORMAT_MODE_FLAG 		        0x06
#define VIDEO_RESOLUTION_MODE_FLAG 	        0x07
#define FRAMERATE_MODE_FLAG 		        0x08
#define COLOR_TEMP_FLAG 		        0x09
#define ASPECT_RATIO_FLAG 		        0x0A


#define MAX_VIDEO_FORMAT         20
#define MAX_DIMMING_MODES        20
#define MAX_PICTURE_MODES        20
#define MAX_HDR10_MODES          10
#define MAX_HLG_MODES            10
#define MAX_DV_MODES             10
#define MAX_NAME_SIZE            20

struct modes {
	char modeName[MAX_DV_MODES][MAX_NAME_SIZE];
	short int modeId[MAX_DV_MODES];
};

struct tvSettingConf{
	struct modes dv_modes;
	struct modes hlg_modes;
	struct modes hdr10_modes;
	struct modes pic_modes;
	struct modes colorTemperature;
	struct modes ApsectRatio;
	char dimmode[MAX_DIMMING_MODES][MAX_NAME_SIZE];
	char videoformat[MAX_VIDEO_FORMAT][MAX_NAME_SIZE];
	char videoresolution[MAX_VIDEO_FORMAT][MAX_NAME_SIZE];
	char videoframerate[MAX_VIDEO_FORMAT][MAX_NAME_SIZE];
};

extern struct tvSettingConf Configfile = {0};

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
			}else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "colorTemperature") == 0) {
				mode = COLOR_TEMP_FLAG;
			}else if (sscanf(buf + i, "[%[^]]]", section) == 1 && strcmp(section, "AspectRatio") == 0) {
				mode = ASPECT_RATIO_FLAG;
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
				if (sscanf(buf, "%s %hd", Configfile.pic_modes.modeName[Count], &Configfile.pic_modes.modeId[Count]) == 2) {
					printf("**%s  %d***\n", Configfile.pic_modes.modeName[Count], Configfile.pic_modes.modeId[Count]);
					Count++;
				}
			}else if(DIM_MODE_FLAG == mode){
				if (sscanf(buf, "%s", Configfile.dimmode[Count]) == 1) {
					printf("**%s  ***\n", Configfile.dimmode[Count]);
					Count++;
				}
			}else if(VIDEO_FORMAT_MODE_FLAG == mode){
				if (sscanf(buf, "%s", Configfile.videoformat[Count]) == 1) {
					Count++;
				}
			}else if(VIDEO_RESOLUTION_MODE_FLAG == mode){
				if (sscanf(buf, "%s", Configfile.videoresolution[Count]) == 1) {
					Count++;
				}
			}else if(FRAMERATE_MODE_FLAG == mode){
				if (sscanf(buf, "%s", Configfile.videoframerate[Count]) == 1){
					printf("**%s ****\n", Configfile.videoframerate[Count]);
					Count++;
				}
			}else if(COLOR_TEMP_FLAG == mode){
				if (sscanf(buf, "%s %hd", Configfile.colorTemperature.modeName[Count], &Configfile.colorTemperature.modeId[Count]) == 2) {
					printf("**%s  %d***\n", Configfile.colorTemperature.modeName[Count], Configfile.colorTemperature.modeId[Count]);
					Count++;
				}
			}else if(ASPECT_RATIO_FLAG == mode){
				if (sscanf(buf, "%s %hd", Configfile.ApsectRatio.modeName[Count], &Configfile.ApsectRatio.modeId[Count]) == 2) {
					printf("**%s  %d***\n", Configfile.ApsectRatio.modeName[Count], Configfile.ApsectRatio.modeId[Count]);
					Count++;
				}
			}
		}
	}
	
	fclose(file);
	return 1;
}
