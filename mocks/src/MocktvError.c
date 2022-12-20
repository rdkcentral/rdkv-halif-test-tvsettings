#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "MocktvError.h"


static struct MocktvErrorInstance
{
  unsigned char placeHolder;
} Mock;

extern jmp_buf AbortFrame;

void MocktvError_Verify(void)
{
}

void MocktvError_Init(void)
{
  MocktvError_Destroy();
}

void MocktvError_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
}

