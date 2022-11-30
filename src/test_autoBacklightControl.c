#include <stdlib.h>
#include <setjmp.h>
#include "tvSettings.h"
#include <tv_settings_hal.h>
#include "autoBacklightControl.h"

#include <ut.h>

static UT_test_suite_t *pSuite = NULL;
#define INFO_UT(text, ...) do {\
printf("TV-SET-HAL-UT: %s[%d] - %s: " text, __FUNCTION__, __LINE__, "INFO", ##__VA_ARGS__);}while(0);

void test_generic_autoBacklightThreadInit( void )
{
    int result = 0;

    /* Positive result */
    result = autoBacklightThreadInit();
    UT_ASSERT_EQUAL( result, 0 );
    INFO_UT(" T1: E[%d]-A[%d] \n",result,0);

    /*calling autoBacklightThreadInit should fail, since already initialised */
    result = autoBacklightThreadInit();
    UT_ASSERT_EQUAL( result, -1);
    INFO_UT(" T2: E[%d]-A[%d] \n",result,-1);
    
}

void test_generic_autoBacklightThreadTerm( void )
{
    int result;

    /* Positive result */
    result = autoBacklightThreadTerm();
    UT_ASSERT_EQUAL( result, 0 );
    INFO_UT(" T3: E[%d]-A[%d] \n",result,0);

    //TODO Code modification is required to return failure. i.e always return 0
    result = autoBacklightThreadTerm();
    UT_ASSERT_EQUAL( result, -1);
    INFO_UT(" T4: E[%d]-A[%d] \n",result,-1);

}

void test_generic_autoBacklightControl( void )
{
    int result;

    /* Positive result */
    result = autoBacklightControl(1);
    UT_ASSERT_EQUAL( result, 0 );
    INFO_UT(" T5: E[%d]-A[%d] \n",result,0);

    result = autoBacklightControl(0);
    UT_ASSERT_EQUAL( result, 0);
    INFO_UT(" T6: E[%d]-A[%d] \n",result,0);

    /* Force failure */
    result = autoBacklightThreadTerm();

    result = autoBacklightControl(-1);
    UT_ASSERT_EQUAL( result, -1);
    INFO_UT(" T7: E[%d]-A[%d] \n",result,-1);
}


void test_generic_blWriteSysfs( void )
{
    int result;

    /* Positive result */
    result = blWriteSysfs(BACKLIGHT_CONTROL_SYSFS,10);
    UT_ASSERT_EQUAL( result, 0 );
    INFO_UT(" T8: E[%d]-A[%d] \n",result,0);

    /* Failure case by file is not available */
    result = blWriteSysfs("Invalid",-10);
    UT_ASSERT_EQUAL( result, -1);
    INFO_UT(" T9: E[%d]-A[%d] \n",result,-1);

}

void test_generic_blReadSysfs( void )
{
    int result;

    /* Positive result */
    result = blReadSysfs(BACKLIGHT_CONTROL_SYSFS);
    UT_ASSERT_EQUAL( result, 0 );
    INFO_UT(" T10: E[%d]-A[%d] \n",result,0);

    /* Failure case by file is not available */
    result = blReadSysfs("Invalid");
    UT_ASSERT_EQUAL( result, -1);
    INFO_UT(" T11: E[%d]-A[%d] \n",result,-1);

    /* Failure case argument as NULL */
    result = blReadSysfs(NULL);
    UT_ASSERT_EQUAL( result, -1);
    INFO_UT(" T12: E[%d]-A[%d] \n",result,-1);

}

int test_autoBacklightControl_hal( void )
{
    /* add a suite to the registry */
    pSuite = UT_add_suite("[L1 tvsettings_hal:autoBacklightControl]", NULL, NULL);
    if (NULL == pSuite) 
    {
        return -1;
    }
    
    UT_add_test( pSuite, "autoBacklightThreadInit",test_generic_autoBacklightThreadInit);
    UT_add_test( pSuite, "autoBacklightThreadTerm",test_generic_autoBacklightThreadTerm);
    UT_add_test( pSuite, "autoBacklightControl",test_generic_autoBacklightControl);
    UT_add_test( pSuite, "blWriteSysfs",test_generic_blWriteSysfs);
    UT_add_test( pSuite, "blReadSysfs",test_generic_blReadSysfs);
}
