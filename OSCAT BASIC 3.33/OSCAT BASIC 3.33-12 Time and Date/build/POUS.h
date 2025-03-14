#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
__DECLARE_STRUCT_TYPE(OSCAT_SDT,
  INT YEAR;
    INT MONTH;
    INT DAY;
    INT WEEKDAY;
    INT HOUR;
    INT MINUTE;
    INT SECOND;
    INT MS;
  )
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// FUNCTION_BLOCK PYTHON_EVAL
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,CODE)
  __DECLARE_VAR(BOOL,ACK)
  __DECLARE_VAR(STRING,RESULT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(DWORD,STATE)
  __DECLARE_VAR(STRING,BUFFER)
  __DECLARE_VAR(STRING,PREBUFFER)
  __DECLARE_VAR(BOOL,TRIGM1)
  __DECLARE_VAR(BOOL,TRIGGED)

} PYTHON_EVAL;

void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain);
// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__);
// FUNCTION_BLOCK PYTHON_POLL
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,CODE)
  __DECLARE_VAR(BOOL,ACK)
  __DECLARE_VAR(STRING,RESULT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(DWORD,STATE)
  __DECLARE_VAR(STRING,BUFFER)
  __DECLARE_VAR(STRING,PREBUFFER)
  __DECLARE_VAR(BOOL,TRIGM1)
  __DECLARE_VAR(BOOL,TRIGGED)

} PYTHON_POLL;

void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain);
// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__);
// FUNCTION_BLOCK PYTHON_GEAR
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(UINT,N)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,CODE)
  __DECLARE_VAR(BOOL,ACK)
  __DECLARE_VAR(STRING,RESULT)

  // FB private variables - TEMP, private and located variables
  PYTHON_EVAL PY_EVAL;
  __DECLARE_VAR(UINT,COUNTER)
  __DECLARE_VAR(UINT,ADD10_OUT)
  __DECLARE_VAR(BOOL,EQ13_OUT)
  __DECLARE_VAR(UINT,SEL15_OUT)
  __DECLARE_VAR(BOOL,AND7_OUT)

} PYTHON_GEAR;

void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain);
// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__);
// FUNCTION
INT HOUR(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT ITOD);
// FUNCTION
UDINT SET_DATE(
  BOOL EN, 
  BOOL *__ENO, 
  INT YEAR, 
  INT MONTH, 
  INT DAY);
// FUNCTION
UDINT SET_DT(
  BOOL EN, 
  BOOL *__ENO, 
  INT YEAR, 
  INT MONTH, 
  INT DAY, 
  INT _HOUR, 
  INT MINUTE, 
  INT SECOND);
// FUNCTION
UDINT _DT_TO_DATE(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IN);
// FUNCTION
INT YEAR_OF_DATE(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE);
// FUNCTION
BOOL DST(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT UTC);
// FUNCTION
UDINT UTC_TO_LTIME(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT UTC, 
  BOOL DST_ENABLE, 
  INT TIME_ZONE_OFFSET);
// FUNCTION
TIME SECOND_TO_TIME(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN);
// FUNCTION
BOOL LEAP_OF_DATE(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE);
// FUNCTION
TIME MINUTE_TO_TIME(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN);
// FUNCTION
INT DAY_OF_YEAR(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE);
// FUNCTION
UDINT HOUR_TO_TOD(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN);
// FUNCTION
UDINT SUN_MIDDAY(
  BOOL EN, 
  BOOL *__ENO, 
  REAL LON, 
  UDINT UTC);
// FUNCTION
UDINT SET_TOD(
  BOOL EN, 
  BOOL *__ENO, 
  INT _HOUR, 
  INT MINUTE, 
  REAL SECOND);
// FUNCTION
UDINT T_PLC_MS(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL DEBUG);
// FUNCTION_BLOCK RTC_MS
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,SET)
  __DECLARE_VAR(UDINT,SDT)
  __DECLARE_VAR(INT,SMS)
  __DECLARE_VAR(UDINT,XDT)
  __DECLARE_VAR(INT,XMS)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(UDINT,LAST)
  __DECLARE_VAR(UDINT,TX)

} RTC_MS;

void RTC_MS_init__(RTC_MS *data__, BOOL retain);
// Code part
void RTC_MS_body__(RTC_MS *data__);
// FUNCTION
UDINT TIME_TO_TOD(
  BOOL EN, 
  BOOL *__ENO, 
  TIME IN);
// FUNCTION
BOOL TIMECHECK(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT TD, 
  UDINT START, 
  UDINT STOP);
// FUNCTION
INT DAYS_IN_MONTH(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE);
// FUNCTION
BOOL PERIOD(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT D1, 
  UDINT D2, 
  UDINT DX);
// FUNCTION
BOOL LEAP_DAY(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE);
// FUNCTION
BOOL BIT_OF_DWORD(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN, 
  INT N);
// FUNCTION
INT MINUTE_OF_DT(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT *__XDT);
// FUNCTION
BOOL LEAP_YEAR(
  BOOL EN, 
  BOOL *__ENO, 
  INT YEAR);
// FUNCTION
INT DAY_OF_MONTH(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE);
// FUNCTION
INT MONTH_OF_DATE(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE);
// FUNCTION
UDINT DATE_ADD(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE, 
  INT _D, 
  INT W, 
  INT M, 
  INT Y);
// FUNCTION
TIME DAY_TO_TIME(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN);
// FUNCTION
DINT FLOOR2(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
REAL MODR(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN, 
  REAL DIVI);
// FUNCTION
REAL DEG(
  BOOL EN, 
  BOOL *__ENO, 
  REAL RAD_IN);
// FUNCTION
REAL RAD(
  BOOL EN, 
  BOOL *__ENO, 
  REAL _DEG);
// PROGRAM PROGRAM0
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(DINT,LOCALVAR0)
  __DECLARE_VAR(DINT,LOCALVAR1)
  __DECLARE_VAR(DINT,LOCALVAR2)
  __DECLARE_VAR(DINT,ADD1_OUT)

} PROGRAM0;

void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain);
// Code part
void PROGRAM0_body__(PROGRAM0 *data__);
// FUNCTION
UDINT YEAR_BEGIN(
  BOOL EN, 
  BOOL *__ENO, 
  INT Y);
// FUNCTION
TIME _MULTIME(
  BOOL EN, 
  BOOL *__ENO, 
  TIME _T, 
  REAL M);
// FUNCTION
TIME HOUR_TO_TIME(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN);
// FUNCTION
INT HOUR_OF_DT(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT XDT);
// FUNCTION
INT _MINUTE(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT ITOD);
// FUNCTION
WORD BIT_LOAD_W(
  BOOL EN, 
  BOOL *__ENO, 
  WORD IN, 
  BOOL VAL, 
  INT POS);
// FUNCTION
INT DAY_OF_WEEK(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE);
// FUNCTION_BLOCK DT2_TO_SDT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(UDINT,DI)
  __DECLARE_VAR(UDINT,TI)
  __DECLARE_VAR(OSCAT_SDT,SDT)

  // FB private variables - TEMP, private and located variables

} DT2_TO_SDT;

void DT2_TO_SDT_init__(DT2_TO_SDT *data__, BOOL retain);
// Code part
void DT2_TO_SDT_body__(DT2_TO_SDT *data__);
// FUNCTION
UDINT _DT_TO_TOD(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IN);
// FUNCTION
REAL REFRACTION(
  BOOL EN, 
  BOOL *__ENO, 
  REAL ELEV);
// FUNCTION_BLOCK SUN_POS
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,LATITUDE)
  __DECLARE_VAR(REAL,LONGITUDE)
  __DECLARE_VAR(UDINT,UTC)
  __DECLARE_VAR(REAL,B)
  __DECLARE_VAR(REAL,HR)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,G)
  __DECLARE_VAR(REAL,A)
  __DECLARE_VAR(REAL,_D)
  __DECLARE_VAR(REAL,H)
  __DECLARE_VAR(REAL,T1)
  __DECLARE_VAR(REAL,N)
  __DECLARE_VAR(REAL,_E)
  __DECLARE_VAR(REAL,C)
  __DECLARE_VAR(REAL,TAU)
  __DECLARE_VAR(REAL,SIN_D)
  __DECLARE_VAR(REAL,RLAT)
  __DECLARE_VAR(REAL,SIN_LAT)
  __DECLARE_VAR(REAL,COS_LAT)
  __DECLARE_VAR(REAL,COS_TAU)
  __DECLARE_VAR(REAL,COS_D)
  __DECLARE_VAR(REAL,MATH_PI)
  __DECLARE_VAR(REAL,MATH_PI2)

} SUN_POS;

void SUN_POS_init__(SUN_POS *data__, BOOL retain);
// Code part
void SUN_POS_body__(SUN_POS *data__);
// FUNCTION_BLOCK SUN_TIME
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,LATITUDE)
  __DECLARE_VAR(REAL,LONGITUDE)
  __DECLARE_VAR(UDINT,UTC)
  __DECLARE_VAR(REAL,H)
  __DECLARE_VAR(UDINT,MIDDAY)
  __DECLARE_VAR(UDINT,SUN_RISE)
  __DECLARE_VAR(UDINT,SUN_SET)
  __DECLARE_VAR(REAL,SUN_DECLINATION)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,DK)
  __DECLARE_VAR(UDINT,DELTA)
  __DECLARE_VAR(REAL,B)

} SUN_TIME;

void SUN_TIME_init__(SUN_TIME *data__, BOOL retain);
// Code part
void SUN_TIME_body__(SUN_TIME *data__);
// FUNCTION
UDINT LTIME_TO_UTC(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT LTIME, 
  BOOL _DST, 
  INT TIME_ZONE_OFFSET);
// FUNCTION_BLOCK SDT_TO_DATE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(OSCAT_SDT,DTI)
  __DECLARE_VAR(UDINT,_SDT_TO_DATE)

  // FB private variables - TEMP, private and located variables

} SDT_TO_DATE;

void SDT_TO_DATE_init__(SDT_TO_DATE *data__, BOOL retain);
// Code part
void SDT_TO_DATE_body__(SDT_TO_DATE *data__);
// FUNCTION
REAL _SECOND(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT ITOD);
// FUNCTION
REAL JD2000(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT DTI);
// FUNCTION
INT DAYS_IN_YEAR(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE);
// FUNCTION
UDINT DATE_TO_DT(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IN);
// FUNCTION
UDINT MONTH_BEGIN(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE);
// FUNCTION
UDINT YEAR_END(
  BOOL EN, 
  BOOL *__ENO, 
  INT Y);
// FUNCTION
BOOL EVEN(
  BOOL EN, 
  BOOL *__ENO, 
  DINT IN);
__DECLARE_ARRAY_TYPE(__ARRAY_OF_BOOL_59,BOOL,[59])
// FUNCTION_BLOCK DCF77
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,REC)
  __DECLARE_VAR(BOOL,SET)
  __DECLARE_VAR(UDINT,SDT)
  __DECLARE_VAR(BOOL,DSI)
  __DECLARE_VAR(TIME,SYNC_TIMEOUT)
  __DECLARE_VAR(INT,TIME_OFFSET)
  __DECLARE_VAR(BOOL,DST_EN)
  __DECLARE_VAR(BOOL,_TP)
  __DECLARE_VAR(BOOL,DS)
  __DECLARE_VAR(INT,WDAY)
  __DECLARE_VAR(BOOL,ERROR)
  __DECLARE_VAR(UDINT,_RTC)
  __DECLARE_VAR(UDINT,RTC1)
  __DECLARE_VAR(INT,MSEC)
  __DECLARE_VAR(BOOL,SYNC)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(UDINT,MEZ)
  __DECLARE_VAR(UDINT,UTC)
  __DECLARE_VAR(INT,STATE)
  __DECLARE_VAR(BOOL,EDGE)
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(TIME,TY)
  __DECLARE_VAR(TIME,LAST)
  __DECLARE_VAR(__ARRAY_OF_BOOL_59,BITS)
  __DECLARE_VAR(INT,CNT)
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(UDINT,OLD_TIME)
  __DECLARE_VAR(INT,MINUTE)
  __DECLARE_VAR(INT,_HOUR)
  __DECLARE_VAR(INT,DAY)
  __DECLARE_VAR(INT,MONTH)
  __DECLARE_VAR(INT,YEAR)
  __DECLARE_VAR(TIME,LAST_SYNC)
  __DECLARE_VAR(TIME,T1)
  __DECLARE_VAR(TIME,TZ)
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(WORD,WORD_TEMP)
  __DECLARE_VAR(BOOL,BOOL_TEMP)

} DCF77;

void DCF77_init__(DCF77 *data__, BOOL retain);
// Code part
void DCF77_body__(DCF77 *data__);
// FUNCTION_BLOCK SDT_TO_DT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(OSCAT_SDT,DTI)
  __DECLARE_VAR(UDINT,_SDT_TO_DT)

  // FB private variables - TEMP, private and located variables

} SDT_TO_DT;

void SDT_TO_DT_init__(SDT_TO_DT *data__, BOOL retain);
// Code part
void SDT_TO_DT_body__(SDT_TO_DT *data__);
// FUNCTION_BLOCK DT_TO_SDT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(UDINT,DTI)
  __DECLARE_VAR(OSCAT_SDT,SDT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(UDINT,TMP)
  __DECLARE_VAR(UDINT,TDT)

} DT_TO_SDT;

void DT_TO_SDT_init__(DT_TO_SDT *data__, BOOL retain);
// Code part
void DT_TO_SDT_body__(DT_TO_SDT *data__);
// FUNCTION_BLOCK SDT_TO_TOD
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(OSCAT_SDT,DTI)
  __DECLARE_VAR(UDINT,_SDT_TO_TOD)

  // FB private variables - TEMP, private and located variables

} SDT_TO_TOD;

void SDT_TO_TOD_init__(SDT_TO_TOD *data__, BOOL retain);
// Code part
void SDT_TO_TOD_body__(SDT_TO_TOD *data__);
// FUNCTION
TIME TOD_TO_TIME(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IN);
// FUNCTION
DINT DAYS_DELTA(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT DATE_1, 
  UDINT DATE_2);
// FUNCTION_BLOCK RTC_2
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,SET)
  __DECLARE_VAR(UDINT,SDT)
  __DECLARE_VAR(INT,SMS)
  __DECLARE_VAR(BOOL,DEN)
  __DECLARE_VAR(INT,OFS)
  __DECLARE_VAR(UDINT,UDT)
  __DECLARE_VAR(UDINT,LDT)
  __DECLARE_VAR(BOOL,DSO)
  __DECLARE_VAR(INT,XMS)

  // FB private variables - TEMP, private and located variables
  RTC_MS RT;

} RTC_2;

void RTC_2_init__(RTC_2 *data__, BOOL retain);
// Code part
void RTC_2_body__(RTC_2 *data__);
// FUNCTION
INT WORK_WEEK(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE);
// FUNCTION
UDINT MONTH_END(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE);
// FUNCTION
INT SECOND_OF_DT(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT XDT);
// FUNCTION
UDINT EASTER(
  BOOL EN, 
  BOOL *__ENO, 
  INT YEAR);
// FUNCTION
DINT DAY_OF_DATE(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE);
#endif //__POUS_H
