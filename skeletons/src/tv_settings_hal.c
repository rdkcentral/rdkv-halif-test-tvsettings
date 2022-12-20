#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
//#include "cmock.h"
#include "tv_settings_hal.h"


int TVWriteSysfs(const char* path, const char* cmd)
{
  /*TODO: Implement Me!*/
  (void)path;
  (void)cmd;
  return (int)0;
}

int sourceIdFromOffset(colortemperature_source_offset_t offset)
{
  /*TODO: Implement Me!*/
  (void)offset;
  return (int)0;
}

void tvCopySD3DatatoCridataEx(void)
{
  /*TODO: Implement Me!*/
}

tvError_t ReadCustWBvaluesFromDriverOnInit(void)
{
  /*TODO: Implement Me!*/
  return (tvError_t)0;
}

int getRgbType(char* color, char* ctrl)
{
  /*TODO: Implement Me!*/
  (void)color;
  (void)ctrl;
  return (int)0;
}

tvError_t TVUpdateRawBacklight(int value, int midPointValue)
{
  /*TODO: Implement Me!*/
  (void)value;
  (void)midPointValue;
  return (tvError_t)0;
}

