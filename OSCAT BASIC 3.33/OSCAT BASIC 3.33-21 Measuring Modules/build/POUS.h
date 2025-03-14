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
__DECLARE_STRUCT_TYPE(REAL2,
  REAL R1;
    REAL RX;
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
UDINT T_PLC_MS(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL DEBUG);
// FUNCTION_BLOCK CYCLE_TIME
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(TIME,CT_MIN)
  __DECLARE_VAR(TIME,CT_MAX)
  __DECLARE_VAR(TIME,CT_LAST)
  __DECLARE_VAR(TIME,SYSTIME)
  __DECLARE_VAR(INT,SYSDAYS)
  __DECLARE_VAR(DWORD,CYCLES)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(TIME,LAST_CYCLE)
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(BOOL,INIT)

} CYCLE_TIME;

void CYCLE_TIME_init__(CYCLE_TIME *data__, BOOL retain);
// Code part
void CYCLE_TIME_body__(CYCLE_TIME *data__);
// FUNCTION
BOOL LEAP_OF_DATE(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE);
// FUNCTION_BLOCK R2_ADD
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL2,X)
  __DECLARE_VAR(REAL,Y)
  __DECLARE_VAR(REAL2,_R2_ADD)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,TEMP)

} R2_ADD;

void R2_ADD_init__(R2_ADD *data__, BOOL retain);
// Code part
void R2_ADD_body__(R2_ADD *data__);
// FUNCTION
INT YEAR_OF_DATE(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE);
// FUNCTION
UDINT T_PLC_US(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL DEBUG);
// FUNCTION_BLOCK TC_US
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(DWORD,TC)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(UDINT,TX)
  __DECLARE_VAR(UDINT,LAST)

} TC_US;

void TC_US_init__(TC_US *data__, BOOL retain);
// Code part
void TC_US_body__(TC_US *data__);
// FUNCTION_BLOCK DT_SIMU
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(UDINT,START)
  __DECLARE_VAR(REAL,SPEED)
  __DECLARE_VAR(UDINT,DTS)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(UDINT,TC)
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(UDINT,LAST)
  __DECLARE_VAR(UDINT,TX)
  __DECLARE_VAR(UDINT,TD)

} DT_SIMU;

void DT_SIMU_init__(DT_SIMU *data__, BOOL retain);
// Code part
void DT_SIMU_body__(DT_SIMU *data__);
// FUNCTION_BLOCK TC_MS
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(DWORD,TC)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(UDINT,TX)
  __DECLARE_VAR(UDINT,LAST)

} TC_MS;

void TC_MS_init__(TC_MS *data__, BOOL retain);
// Code part
void TC_MS_body__(TC_MS *data__);
// FUNCTION_BLOCK INTEGRATE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,_E)
  __DECLARE_VAR(REAL,X)
  __DECLARE_VAR(REAL,K)
  __DECLARE_VAR(REAL,Y)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,X_LAST)
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(UDINT,LAST)
  __DECLARE_VAR(UDINT,TX)

} INTEGRATE;

void INTEGRATE_init__(INTEGRATE *data__, BOOL retain);
// Code part
void INTEGRATE_body__(INTEGRATE *data__);
// FUNCTION_BLOCK ALARM_2
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,X)
  __DECLARE_VAR(REAL,LO_1)
  __DECLARE_VAR(REAL,HI_1)
  __DECLARE_VAR(REAL,LO_2)
  __DECLARE_VAR(REAL,HI_2)
  __DECLARE_VAR(REAL,HYS)
  __DECLARE_VAR(BOOL,Q1_LO)
  __DECLARE_VAR(BOOL,Q1_HI)
  __DECLARE_VAR(BOOL,Q2_LO)
  __DECLARE_VAR(BOOL,Q2_HI)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,TMP)

} ALARM_2;

void ALARM_2_init__(ALARM_2 *data__, BOOL retain);
// Code part
void ALARM_2_body__(ALARM_2 *data__);
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
// FUNCTION_BLOCK METER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,M1)
  __DECLARE_VAR(REAL,M2)
  __DECLARE_VAR(BOOL,I1)
  __DECLARE_VAR(BOOL,I2)
  __DECLARE_VAR(REAL,_D)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(REAL,MX)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL2,MR)
  __DECLARE_VAR(REAL,MX1)
  __DECLARE_VAR(REAL,MX2)
  __DECLARE_VAR(UDINT,TX)
  __DECLARE_VAR(UDINT,LAST)
  __DECLARE_VAR(REAL,TC)
  __DECLARE_VAR(BOOL,INIT)
  R2_ADD _R2_ADD;

} METER;

void METER_init__(METER *data__, BOOL retain);
// Code part
void METER_body__(METER *data__);
// FUNCTION_BLOCK M_D
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,START)
  __DECLARE_VAR(BOOL,STOP)
  __DECLARE_VAR(TIME,TMAX)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(TIME,PT)
  __DECLARE_VAR(TIME,ET)
  __DECLARE_VAR(BOOL,RUN)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,EDGE)
  __DECLARE_VAR(TIME,T0)
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(BOOL,STARTUP)

} M_D;

void M_D_init__(M_D *data__, BOOL retain);
// Code part
void M_D_body__(M_D *data__);
// FUNCTION_BLOCK TC_S
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,TC)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(UDINT,TX)
  __DECLARE_VAR(UDINT,LAST)

} TC_S;

void TC_S_init__(TC_S *data__, BOOL retain);
// Code part
void TC_S_body__(TC_S *data__);
// FUNCTION_BLOCK CALIBRATE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,X)
  __DECLARE_VAR(BOOL,CO)
  __DECLARE_VAR(BOOL,CS)
  __DECLARE_VAR(REAL,Y_OFFSET)
  __DECLARE_VAR(REAL,Y_SCALE)
  __DECLARE_VAR(REAL,Y)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,OFFSET)
  __DECLARE_VAR(REAL,SCALE)

} CALIBRATE;

void CALIBRATE_init__(CALIBRATE *data__, BOOL retain);
// Code part
void CALIBRATE_body__(CALIBRATE *data__);
// FUNCTION_BLOCK M_T
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(TIME,TMAX)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(TIME,PT)
  __DECLARE_VAR(TIME,ET)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,EDGE)
  __DECLARE_VAR(TIME,START)
  __DECLARE_VAR(TIME,TX)

} M_T;

void M_T_init__(M_T *data__, BOOL retain);
// Code part
void M_T_body__(M_T *data__);
// FUNCTION
INT FLOOR(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
INT DAY_OF_YEAR(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE);
// FUNCTION
INT DAY_OF_WEEK(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE);
// FUNCTION
INT MONTH_OF_DATE(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE);
// FUNCTION_BLOCK METER_STAT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(UDINT,DI)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(REAL,LAST_DAY)
  __DECLARE_VAR(REAL,CURRENT_DAY)
  __DECLARE_VAR(REAL,LAST_WEEK)
  __DECLARE_VAR(REAL,CURRENT_WEEK)
  __DECLARE_VAR(REAL,LAST_MONTH)
  __DECLARE_VAR(REAL,CURRENT_MONTH)
  __DECLARE_VAR(REAL,LAST_YEAR)
  __DECLARE_VAR(REAL,CURRENT_YEAR)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,YEAR_START)
  __DECLARE_VAR(REAL,MONTH_START)
  __DECLARE_VAR(REAL,WEEK_START)
  __DECLARE_VAR(REAL,DAY_START)
  __DECLARE_VAR(UDINT,LAST_RUN)

} METER_STAT;

void METER_STAT_init__(METER_STAT *data__, BOOL retain);
// Code part
void METER_STAT_body__(METER_STAT *data__);
// FUNCTION_BLOCK ONTIME
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(UDINT,SECONDS)
  __DECLARE_VAR(UDINT,CYCLES)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(UDINT,TX)
  __DECLARE_VAR(UDINT,LAST)
  __DECLARE_VAR(BOOL,EDGE)
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(UDINT,MS)

} ONTIME;

void ONTIME_init__(ONTIME *data__, BOOL retain);
// Code part
void ONTIME_body__(ONTIME *data__);
// FUNCTION_BLOCK M_TX
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(TIME,TMAX)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(TIME,TH)
  __DECLARE_VAR(TIME,TL)
  __DECLARE_VAR(REAL,DC)
  __DECLARE_VAR(REAL,F)
  __DECLARE_VAR(TIME,ET)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,EDGE)
  __DECLARE_VAR(TIME,START)
  __DECLARE_VAR(TIME,STOP)
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(BOOL,RISE)
  __DECLARE_VAR(BOOL,FALL)
  __DECLARE_VAR(BOOL,STARTUP)

} M_TX;

void M_TX_init__(M_TX *data__, BOOL retain);
// Code part
void M_TX_body__(M_TX *data__);
// FUNCTION_BLOCK BAR_GRAPH
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,X)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(REAL,TRIGGER_LOW)
  __DECLARE_VAR(REAL,TRIGGER_HIGH)
  __DECLARE_VAR(BOOL,ALARM_LOW)
  __DECLARE_VAR(BOOL,ALARM_HIGH)
  __DECLARE_VAR(BOOL,LOG_SCALE)
  __DECLARE_VAR(BOOL,LOW)
  __DECLARE_VAR(BOOL,Q1)
  __DECLARE_VAR(BOOL,Q2)
  __DECLARE_VAR(BOOL,Q3)
  __DECLARE_VAR(BOOL,Q4)
  __DECLARE_VAR(BOOL,Q5)
  __DECLARE_VAR(BOOL,Q6)
  __DECLARE_VAR(BOOL,HIGH)
  __DECLARE_VAR(BOOL,ALARM)
  __DECLARE_VAR(BYTE,STATUS)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(REAL,T1)
  __DECLARE_VAR(REAL,T2)
  __DECLARE_VAR(REAL,T3)
  __DECLARE_VAR(REAL,T4)
  __DECLARE_VAR(REAL,T5)
  __DECLARE_VAR(REAL,TEMP)

} BAR_GRAPH;

void BAR_GRAPH_init__(BAR_GRAPH *data__, BOOL retain);
// Code part
void BAR_GRAPH_body__(BAR_GRAPH *data__);
// FUNCTION_BLOCK FLOW_METER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,VX)
  __DECLARE_VAR(BOOL,_E)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(BOOL,PULSE_MODE)
  __DECLARE_VAR(TIME,UPDATE_TIME)
  __DECLARE_VAR(REAL,F)
  __DECLARE_VAR(REAL,X)
  __DECLARE_VAR(UDINT,Y)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(TIME,TL)
  INTEGRATE INT1;
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(BOOL,E_LAST)
  __DECLARE_VAR(INT,TMP)
  __DECLARE_VAR(REAL,X_LAST)
  __DECLARE_VAR(UDINT,Y_LAST)

} FLOW_METER;

void FLOW_METER_init__(FLOW_METER *data__, BOOL retain);
// Code part
void FLOW_METER_body__(FLOW_METER *data__);
#endif //__POUS_H
