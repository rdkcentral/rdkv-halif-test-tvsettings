#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "Mockbl_table.h"


static struct Mockbl_tableInstance
{
  unsigned char placeHolder;
} Mock;

extern jmp_buf AbortFrame;

void Mockbl_table_Verify(void)
{
}

void Mockbl_table_Init(void)
{
  Mockbl_table_Destroy();
}

void Mockbl_table_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
}

