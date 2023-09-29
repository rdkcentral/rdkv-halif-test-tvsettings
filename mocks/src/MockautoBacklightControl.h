/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCKAUTOBACKLIGHTCONTROL_H
#define _MOCKAUTOBACKLIGHTCONTROL_H

#include "unity.h"
#include "autoBacklightControl.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic push
#endif
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

#ifdef __cplusplus
extern "C" {
#endif

void MockautoBacklightControl_Init(void);
void MockautoBacklightControl_Destroy(void);
void MockautoBacklightControl_Verify(void);




#define blWriteSysfs_ExpectAndReturn(path, value, cmock_retval) blWriteSysfs_CMockExpectAndReturn(__LINE__, path, value, cmock_retval)
void blWriteSysfs_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, const char* path, int value, int cmock_to_return);
#define blReadSysfs_ExpectAndReturn(path, cmock_retval) blReadSysfs_CMockExpectAndReturn(__LINE__, path, cmock_retval)
void blReadSysfs_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, const char* path, int cmock_to_return);
#define autoBacklightThreadInit_ExpectAndReturn(cmock_retval) autoBacklightThreadInit_CMockExpectAndReturn(__LINE__, cmock_retval)
void autoBacklightThreadInit_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
#define autoBacklightThreadTerm_ExpectAndReturn(cmock_retval) autoBacklightThreadTerm_CMockExpectAndReturn(__LINE__, cmock_retval)
void autoBacklightThreadTerm_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
#define autoBacklightControl_ExpectAndReturn(enable, cmock_retval) autoBacklightControl_CMockExpectAndReturn(__LINE__, enable, cmock_retval)
void autoBacklightControl_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, bool enable, int cmock_to_return);

#ifdef __cplusplus
}
#endif

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic pop
#endif
#endif

#endif