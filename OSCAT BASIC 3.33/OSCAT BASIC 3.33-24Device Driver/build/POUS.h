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
__DECLARE_ARRAY_TYPE(__ARRAY_OF_REAL_4,REAL,[4])
__DECLARE_ARRAY_TYPE(__ARRAY_OF_OSCAT_PARSET_X_4,__ARRAY_OF_REAL_4,[4])
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
BYTE BIT_LOAD_B(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE IN, 
  BOOL VAL, 
  INT POS);
// FUNCTION_BLOCK INTERLOCK_4
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,I0)
  __DECLARE_VAR(BOOL,I1)
  __DECLARE_VAR(BOOL,I2)
  __DECLARE_VAR(BOOL,I3)
  __DECLARE_VAR(BOOL,_E)
  __DECLARE_VAR(INT,MODE)
  __DECLARE_VAR(BYTE,OUT)
  __DECLARE_VAR(BOOL,_TP)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BYTE,IN)
  __DECLARE_VAR(BYTE,LAST)
  __DECLARE_VAR(BYTE,OLD)
  __DECLARE_VAR(INT,LMODE)

} INTERLOCK_4;

void INTERLOCK_4_init__(INTERLOCK_4 *data__, BOOL retain);
// Code part
void INTERLOCK_4_body__(INTERLOCK_4 *data__);
// FUNCTION
BOOL BIT_OF_DWORD(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN, 
  INT N);
// FUNCTION_BLOCK INC_DEC
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,CHA)
  __DECLARE_VAR(BOOL,CHB)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(BOOL,DIR)
  __DECLARE_VAR(INT,CNT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,EDGEA)
  __DECLARE_VAR(BOOL,CLK)
  __DECLARE_VAR(BOOL,CLKA)
  __DECLARE_VAR(BOOL,CLKB)
  __DECLARE_VAR(BOOL,EDGEB)
  __DECLARE_VAR(BOOL,AXB)

} INC_DEC;

void INC_DEC_init__(INC_DEC *data__, BOOL retain);
// Code part
void INC_DEC_body__(INC_DEC *data__);
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
UDINT T_PLC_MS(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL DEBUG);
// FUNCTION
INT _BYTE_TO_INT(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE IN);
// FUNCTION_BLOCK SIGNAL
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(BYTE,SIG)
  __DECLARE_VAR(TIME,TS)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(DWORD,TX)
  __DECLARE_VAR(BYTE,_STEP)

} SIGNAL;

void SIGNAL_init__(SIGNAL *data__, BOOL retain);
// Code part
void SIGNAL_body__(SIGNAL *data__);
// FUNCTION_BLOCK SIGNAL_4
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN1)
  __DECLARE_VAR(BOOL,IN2)
  __DECLARE_VAR(BOOL,IN3)
  __DECLARE_VAR(BOOL,IN4)
  __DECLARE_VAR(TIME,TS)
  __DECLARE_VAR(BYTE,S1)
  __DECLARE_VAR(BYTE,S2)
  __DECLARE_VAR(BYTE,S3)
  __DECLARE_VAR(BYTE,S4)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  SIGNAL SIG;

} SIGNAL_4;

void SIGNAL_4_init__(SIGNAL_4 *data__, BOOL retain);
// Code part
void SIGNAL_4_body__(SIGNAL_4 *data__);
// FUNCTION_BLOCK INTERLOCK
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,I1)
  __DECLARE_VAR(BOOL,I2)
  __DECLARE_VAR(TIME,TL)
  __DECLARE_VAR(BOOL,Q1)
  __DECLARE_VAR(BOOL,Q2)

  // FB private variables - TEMP, private and located variables
  TOF T1;
  TOF T2;

} INTERLOCK;

void INTERLOCK_init__(INTERLOCK *data__, BOOL retain);
// Code part
void INTERLOCK_body__(INTERLOCK *data__);
// FUNCTION
UDINT T_PLC_US(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL DEBUG);
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
// FUNCTION_BLOCK SRAMP
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,X)
  __DECLARE_VAR(REAL,A_UP)
  __DECLARE_VAR(REAL,A_DN)
  __DECLARE_VAR(REAL,VU_MAX)
  __DECLARE_VAR(REAL,VD_MAX)
  __DECLARE_VAR(REAL,LIMIT_HIGH)
  __DECLARE_VAR(REAL,LIMIT_LOW)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(REAL,Y)
  __DECLARE_VAR(REAL,V)

  // FB private variables - TEMP, private and located variables
  TC_S CYCLE_TIME;
  __DECLARE_VAR(BOOL,INIT)

} SRAMP;

void SRAMP_init__(SRAMP *data__, BOOL retain);
// Code part
void SRAMP_body__(SRAMP *data__);
// FUNCTION_BLOCK TUNE2
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,SET)
  __DECLARE_VAR(BOOL,SU)
  __DECLARE_VAR(BOOL,SD)
  __DECLARE_VAR(BOOL,FU)
  __DECLARE_VAR(BOOL,FD)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(REAL,SS)
  __DECLARE_VAR(REAL,FS)
  __DECLARE_VAR(REAL,LIMIT_L)
  __DECLARE_VAR(REAL,LIMIT_H)
  __DECLARE_VAR(REAL,RST_VAL)
  __DECLARE_VAR(REAL,SET_VAL)
  __DECLARE_VAR(TIME,TR)
  __DECLARE_VAR(REAL,S1)
  __DECLARE_VAR(REAL,S2)
  __DECLARE_VAR(REAL,Y)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(UDINT,TX)
  __DECLARE_VAR(UDINT,START)
  __DECLARE_VAR(INT,STATE)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(REAL,_STEP)
  __DECLARE_VAR(REAL,SPEED)
  __DECLARE_VAR(REAL,Y_START)

} TUNE2;

void TUNE2_init__(TUNE2 *data__, BOOL retain);
// Code part
void TUNE2_body__(TUNE2 *data__);
// FUNCTION_BLOCK FT_PROFILE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,K)
  __DECLARE_VAR(REAL,O)
  __DECLARE_VAR(REAL,M)
  __DECLARE_VAR(BOOL,_E)
  __DECLARE_VAR(REAL,VALUE_0)
  __DECLARE_VAR(REAL,VALUE_1)
  __DECLARE_VAR(REAL,VALUE_2)
  __DECLARE_VAR(REAL,VALUE_3)
  __DECLARE_VAR(REAL,VALUE_10)
  __DECLARE_VAR(REAL,VALUE_11)
  __DECLARE_VAR(REAL,VALUE_12)
  __DECLARE_VAR(REAL,VALUE_13)
  __DECLARE_VAR(TIME,TIME_1)
  __DECLARE_VAR(TIME,TIME_2)
  __DECLARE_VAR(TIME,TIME_3)
  __DECLARE_VAR(TIME,TIME_10)
  __DECLARE_VAR(TIME,TIME_11)
  __DECLARE_VAR(TIME,TIME_12)
  __DECLARE_VAR(TIME,TIME_13)
  __DECLARE_VAR(REAL,Y)
  __DECLARE_VAR(BOOL,RUN)
  __DECLARE_VAR(TIME,ET)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(BOOL,EDGE)
  __DECLARE_VAR(INT,STATE)
  __DECLARE_VAR(TIME,TA)
  __DECLARE_VAR(TIME,TB)
  __DECLARE_VAR(TIME,T0)
  __DECLARE_VAR(REAL,TEMP)
  __DECLARE_VAR(REAL,VA)
  __DECLARE_VAR(REAL,VB)

} FT_PROFILE;

void FT_PROFILE_init__(FT_PROFILE *data__, BOOL retain);
// Code part
void FT_PROFILE_body__(FT_PROFILE *data__);
// FUNCTION_BLOCK TP_1D
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(TIME,PT1)
  __DECLARE_VAR(TIME,PTD)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(BOOL,W)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(TIME,START)
  __DECLARE_VAR(BOOL,IX)

} TP_1D;

void TP_1D_init__(TP_1D *data__, BOOL retain);
// Code part
void TP_1D_body__(TP_1D *data__);
// FUNCTION_BLOCK FLOW_CONTROL
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(BOOL,REQ)
  __DECLARE_VAR(BOOL,ENQ)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(TIME,T_AUTO)
  __DECLARE_VAR(TIME,T_DELAY)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(BYTE,STATUS)

  // FB private variables - TEMP, private and located variables
  TP_1D TIMER;

} FLOW_CONTROL;

void FLOW_CONTROL_init__(FLOW_CONTROL *data__, BOOL retain);
// Code part
void FLOW_CONTROL_body__(FLOW_CONTROL *data__);
// FUNCTION_BLOCK MANUAL_2
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(BOOL,ENA)
  __DECLARE_VAR(BOOL,_ON)
  __DECLARE_VAR(BOOL,OFF)
  __DECLARE_VAR(BOOL,MAN)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(BYTE,STATUS)
  __DECLARE_VAR(BYTE,STATUS0)

  // FB private variables - TEMP, private and located variables

} MANUAL_2;

void MANUAL_2_init__(MANUAL_2 *data__, BOOL retain);
// Code part
void MANUAL_2_body__(MANUAL_2 *data__);
// FUNCTION
BOOL MANUAL(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL IN, 
  BOOL _ON, 
  BOOL OFF);
// FUNCTION_BLOCK MANUAL_1
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(BOOL,MAN)
  __DECLARE_VAR(BOOL,M_I)
  __DECLARE_VAR(BOOL,SET)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(BYTE,STATUS)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,S_EDGE)
  __DECLARE_VAR(BOOL,_R_EDGE)
  __DECLARE_VAR(BOOL,EDGE)

} MANUAL_1;

void MANUAL_1_init__(MANUAL_1 *data__, BOOL retain);
// Code part
void MANUAL_1_body__(MANUAL_1 *data__);
// FUNCTION_BLOCK TUNE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,SET)
  __DECLARE_VAR(BOOL,SU)
  __DECLARE_VAR(BOOL,SD)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(REAL,SS)
  __DECLARE_VAR(REAL,LIMIT_L)
  __DECLARE_VAR(REAL,LIMIT_H)
  __DECLARE_VAR(REAL,RST_VAL)
  __DECLARE_VAR(REAL,SET_VAL)
  __DECLARE_VAR(TIME,T1)
  __DECLARE_VAR(TIME,T2)
  __DECLARE_VAR(REAL,S1)
  __DECLARE_VAR(REAL,S2)
  __DECLARE_VAR(REAL,Y)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(UDINT,TX)
  __DECLARE_VAR(UDINT,START)
  __DECLARE_VAR(UDINT,START2)
  __DECLARE_VAR(INT,STATE)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(REAL,_STEP)
  __DECLARE_VAR(REAL,SPEED)
  __DECLARE_VAR(REAL,Y_START)
  __DECLARE_VAR(REAL,Y_START2)

} TUNE;

void TUNE_init__(TUNE *data__, BOOL retain);
// Code part
void TUNE_body__(TUNE *data__);
// FUNCTION
INT INC(
  BOOL EN, 
  BOOL *__ENO, 
  INT X, 
  INT _D, 
  INT M);
// FUNCTION_BLOCK MANUAL_4
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,I0)
  __DECLARE_VAR(BOOL,I1)
  __DECLARE_VAR(BOOL,I2)
  __DECLARE_VAR(BOOL,I3)
  __DECLARE_VAR(BOOL,MAN)
  __DECLARE_VAR(BOOL,STP)
  __DECLARE_VAR(BOOL,M0)
  __DECLARE_VAR(BOOL,M1)
  __DECLARE_VAR(BOOL,M2)
  __DECLARE_VAR(BOOL,M3)
  __DECLARE_VAR(BOOL,Q0)
  __DECLARE_VAR(BOOL,Q1)
  __DECLARE_VAR(BOOL,Q2)
  __DECLARE_VAR(BOOL,Q3)
  __DECLARE_VAR(BYTE,STATUS)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,EDGE)
  __DECLARE_VAR(INT,POS)
  __DECLARE_VAR(BOOL,TOG)

} MANUAL_4;

void MANUAL_4_init__(MANUAL_4 *data__, BOOL retain);
// Code part
void MANUAL_4_body__(MANUAL_4 *data__);
__DECLARE_ARRAY_TYPE(__ARRAY_OF_BYTE_7,BYTE,[7])
// FUNCTION_BLOCK DRIVER_4C
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(TIME,TIMEOUT)
  __DECLARE_VAR(__ARRAY_OF_BYTE_7,SX)
  __DECLARE_VAR(INT,SN)
  __DECLARE_VAR(BOOL,Q0)
  __DECLARE_VAR(BOOL,Q1)
  __DECLARE_VAR(BOOL,Q2)
  __DECLARE_VAR(BOOL,Q3)

  // FB private variables - TEMP, private and located variables
  TON OFF;
  __DECLARE_VAR(BOOL,EDGE)

} DRIVER_4C;

void DRIVER_4C_init__(DRIVER_4C *data__, BOOL retain);
// Code part
void DRIVER_4C_body__(DRIVER_4C *data__);
// FUNCTION_BLOCK DRIVER_1
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,SET)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(BOOL,TOGGLE_MODE)
  __DECLARE_VAR(TIME,TIMEOUT)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  TON OFF;
  __DECLARE_VAR(BOOL,EDGE)

} DRIVER_1;

void DRIVER_1_init__(DRIVER_1 *data__, BOOL retain);
// Code part
void DRIVER_1_body__(DRIVER_1 *data__);
// FUNCTION_BLOCK DRIVER_4
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,SET)
  __DECLARE_VAR(BOOL,IN0)
  __DECLARE_VAR(BOOL,IN1)
  __DECLARE_VAR(BOOL,IN2)
  __DECLARE_VAR(BOOL,IN3)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(BOOL,TOGGLE_MODE)
  __DECLARE_VAR(TIME,TIMEOUT)
  __DECLARE_VAR(BOOL,Q0)
  __DECLARE_VAR(BOOL,Q1)
  __DECLARE_VAR(BOOL,Q2)
  __DECLARE_VAR(BOOL,Q3)

  // FB private variables - TEMP, private and located variables
  DRIVER_1 D0;
  DRIVER_1 D1;
  DRIVER_1 D2;
  DRIVER_1 D3;

} DRIVER_4;

void DRIVER_4_init__(DRIVER_4 *data__, BOOL retain);
// Code part
void DRIVER_4_body__(DRIVER_4 *data__);
#endif //__POUS_H
