/*******************************************/
/*     FILE GENERATED BY iec2c             */
/* Editing this file is not recommended... */
/*******************************************/

#include "iec_std_lib.h"

// RESOURCE RES0

extern unsigned long long common_ticktime__;

#include "accessor.h"
#include "POUS.h"

#include "Config0.h"
__DECLARE_GLOBAL(ULINT,RES0,PLC_CYCLE_COUNT)
__DECLARE_GLOBAL(ULINT,RES0,TASK_TIME_MS)

#include "POUS.c"

BOOL TASK0;
PROGRAM0 RES0__INSTANCE0;
#define INSTANCE0 RES0__INSTANCE0

void RES0_init__(void) {
  BOOL retain;
  retain = 0;
  __INIT_GLOBAL(ULINT,PLC_CYCLE_COUNT,__INITIAL_VALUE(0),retain)
  __INIT_GLOBAL(ULINT,TASK_TIME_MS,__INITIAL_VALUE(20),retain)
  TASK0 = __BOOL_LITERAL(FALSE);
  PROGRAM0_init__(&INSTANCE0,retain);
}

void RES0_run__(unsigned long tick) {
  TASK0 = !(tick % 1);
  if (TASK0) {
    PROGRAM0_body__(&INSTANCE0);
  }
}

