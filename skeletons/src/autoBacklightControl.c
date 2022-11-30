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
#include <stdio.h>
#include <stdlib.h>

#include "autoBacklightControl.h"

int _getBacklight() {
    return 0;
}

int _setBacklight(int backlight, int save) {  
    return 0;
}

void * autoBLControlLoop(void* data) {
    return NULL;
}

#ifdef HAS_ALS_SUPPORT
int alsFlashDataSync() {

    return 0;
}
#endif

int autoBlLoadSettings( void )
{   
    return 0;
}

int autoBlLoadConfigTable( void )
{
    return 0;
}

int autoBacklightThreadInit() {
    return 0;
}

int autoBacklightThreadTerm() {
  return 0;
}

/********************* sysfs utils **************************/

int blWriteSysfs(const char *path, int value)
{
   return 0;
}

int readSys(const char *path, char *buf, int count) {
    
    return 0;
}

int blReadSysfs(const char *path) {
    return 0;
}




/*********************** ALS Reading loop & Filtering API *******************/
#ifndef AUTO_BACKLIGHT_DISABLE
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void alsMapToBacklightValue() {
   return;
}
#endif

int autoBacklightControl(bool enable) {
   
    return 0;
}

#if 0
//TODO : currently not used
int setUserAmbientBacklight(int level) {

    return 0;
}
#endif
