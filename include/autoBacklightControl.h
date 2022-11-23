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
#ifndef __AUTO_BACKLIGHT_CONTROL_H
#define __AUTO_BACKLIGHT_CONTROL_H

#include <stdio.h>

#define ALS_SENSITIVITY 2
#define ALS_READ_COUNT_MAX 11
#define BACKLIGHT_CONTROL_SYSFS "/sys/class/backlight/aml-bl/brightness"
#define USER_BACKLIGHT_BRIGHTNESS_DEFAULT 127

typedef enum _als_lens_type {
    ALS_LENS_NONE,
    ALS_LENS_KEMET,
    ALS_LENS_FORLON,
    ALS_LENS_MAX
} als_lens_type;

//utils
int blWriteSysfs(const char *path, int value);
int blReadSysfs(const char *path);

//ABL APIs
int autoBacklightThreadInit();
int autoBacklightThreadTerm();
int autoBacklightControl(bool enable);

#define ERROR(text, ...) do {\
        printf("TV - ABL: %s[%d] - %s: " text, __FUNCTION__, __LINE__, "ERROR", ##__VA_ARGS__);}while(0);
#define INFO(text, ...) do {\
        printf("TV - ABL: %s[%d] - %s: " text, __FUNCTION__, __LINE__, "INFO", ##__VA_ARGS__);}while(0);

//#define DEBUG_ENABLED
#ifdef DEBUG_ENABLED
#define DEBUG(text, ...) do {\
        printf("TV - ABL: %s[%d] - %s: " text, __FUNCTION__, __LINE__, "DEBUG", ##__VA_ARGS__);}while(0);
#else
#define DEBUG(text, ...)
#endif

#endif //__AUTO_BACKLIGHT_CONTROL_H
