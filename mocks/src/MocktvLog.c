#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "MocktvLog.h"


static struct MocktvLogInstance
{
  unsigned char placeHolder;
} Mock;

extern jmp_buf AbortFrame;

void MocktvLog_Verify(void)
{
}

void MocktvLog_Init(void)
{
  MocktvLog_Destroy();
}

void MocktvLog_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
}

