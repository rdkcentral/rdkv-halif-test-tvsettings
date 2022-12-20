/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2016 RDK Management
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
 * @brief Register test functionality
 * 
 */

/* L1 Testing Functions */
extern int test_tvsettings_hal( void );

#if 0
extern int test_wifi_generic_register( void );
extern int test_wifi_client_mgr_register( void );

extern int test_wifi_radio_register( void );
extern int test_wifi_sta_register( void );
extern int test_wifi_telemetry_register( void );
extern int test_wifi_ap_register( void );

/* L2 Testing Functions */
extern int test_wifi_hal_l2_register( void );
#endif

int register_hal_l1_tests( void )
{
    int registerFailed=0;

    registerFailed |= test_tvsettings_hal();
#if 0
    registerFailed |= test_wifi_generic_register();
    //registerFailed |= test_wifi_client_mgr_register(); /* #TODO: API to be confirmed whether it's required or not, tests yet to be implemented */
    
    registerFailed |= test_wifi_radio_register();
    registerFailed |= test_wifi_sta_register();
    registerFailed |= test_wifi_telemetry_register();
    registerFailed |= test_wifi_ap_register();
#endif
    return registerFailed;
}
#if 0

int register_hal_l2_tests( void )
{
    int registerFailed=0;

    registerFailed |= test_wifi_hal_l2_register();

    return registerFailed;
}
#endif
