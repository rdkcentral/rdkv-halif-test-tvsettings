#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
//#include "cmock.h"
#include "autoBacklightControl.h"


int blWriteSysfs(const char* path, int value)
{
  /*TODO: Implement Me!*/
  (void)path;
  (void)value;
  return (int)0;
}

int blReadSysfs(const char* path)
{
  /*TODO: Implement Me!*/
  (void)path;
  return (int)0;
}

int autoBacklightThreadInit(void)
{
  /*TODO: Implement Me!*/
  return (int)0;
}

int autoBacklightThreadTerm(void)
{
  /*TODO: Implement Me!*/
  return (int)0;
}

int autoBacklightControl(bool enable)
{
  /*TODO: Implement Me!*/
  (void)enable;
  return (int)0;
}

