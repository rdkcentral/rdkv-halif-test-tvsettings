#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "MocktvTypes.h"


static struct MocktvTypesInstance
{
  unsigned char placeHolder;
} Mock;

extern jmp_buf AbortFrame;

void MocktvTypes_Verify(void)
{
}

void MocktvTypes_Init(void)
{
  MocktvTypes_Destroy();
}

void MocktvTypes_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
}

