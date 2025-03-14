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
// FUNCTION_BLOCK TMIN
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(TIME,PT)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  TP PM;

} TMIN;

void TMIN_init__(TMIN *data__, BOOL retain);
// Code part
void TMIN_body__(TMIN *data__);
// FUNCTION_BLOCK CLICK_CNT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(INT,N)
  __DECLARE_VAR(TIME,TC)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  TP TX;
  __DECLARE_VAR(BOOL,EDGE)
  __DECLARE_VAR(INT,CNT)

} CLICK_CNT;

void CLICK_CNT_init__(CLICK_CNT *data__, BOOL retain);
// Code part
void CLICK_CNT_body__(CLICK_CNT *data__);
// FUNCTION
UDINT T_PLC_MS(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL DEBUG);
// FUNCTION_BLOCK TP_X
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(TIME,PT)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(TIME,ET)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,EDGE)
  __DECLARE_VAR(TIME,START)
  __DECLARE_VAR(TIME,TX)

} TP_X;

void TP_X_init__(TP_X *data__, BOOL retain);
// Code part
void TP_X_body__(TP_X *data__);
// FUNCTION
BOOL BIT_OF_DWORD(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN, 
  INT N);
// FUNCTION_BLOCK TONOF
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(TIME,T_ON)
  __DECLARE_VAR(TIME,T_OFF)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  TON X;
  __DECLARE_VAR(BOOL,OLD)
  __DECLARE_VAR(BOOL,MODE)

} TONOF;

void TONOF_init__(TONOF *data__, BOOL retain);
// Code part
void TONOF_body__(TONOF *data__);
// FUNCTION
INT INC2(
  BOOL EN, 
  BOOL *__ENO, 
  INT X, 
  INT _D, 
  INT L, 
  INT U);
__DECLARE_ARRAY_TYPE(__ARRAY_OF_TIME_64,TIME,[64])
// FUNCTION_BLOCK SEQUENCE_64
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,START)
  __DECLARE_VAR(INT,SMAX)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(INT,STATE)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(__ARRAY_OF_TIME_64,PROG)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(TIME,LAST)
  __DECLARE_VAR(BOOL,EDGE)

} SEQUENCE_64;

void SEQUENCE_64_init__(SEQUENCE_64 *data__, BOOL retain);
// Code part
void SEQUENCE_64_body__(SEQUENCE_64 *data__);
// FUNCTION_BLOCK CYCLE_4
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,_E)
  __DECLARE_VAR(TIME,T0)
  __DECLARE_VAR(TIME,T1)
  __DECLARE_VAR(TIME,T2)
  __DECLARE_VAR(TIME,T3)
  __DECLARE_VAR(BOOL,S0)
  __DECLARE_VAR(INT,SX)
  __DECLARE_VAR(BOOL,SL)
  __DECLARE_VAR(INT,STATE)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(TIME,LAST)
  __DECLARE_VAR(BOOL,INIT)

} CYCLE_4;

void CYCLE_4_init__(CYCLE_4 *data__, BOOL retain);
// Code part
void CYCLE_4_body__(CYCLE_4 *data__);
// PROGRAM PROGRAM0
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(DINT,LOCALVAR0)
  __DECLARE_VAR(DINT,LOCALVAR3)
  __DECLARE_VAR(DINT,LOCALVAR1)
  __DECLARE_VAR(DINT,LOCALVAR2)
  __DECLARE_VAR(DINT,ADD1_OUT)

} PROGRAM0;

void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain);
// Code part
void PROGRAM0_body__(PROGRAM0 *data__);
// FUNCTION_BLOCK B_TRIG
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,CLK)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,EDGE)

} B_TRIG;

void B_TRIG_init__(B_TRIG *data__, BOOL retain);
// Code part
void B_TRIG_body__(B_TRIG *data__);
// FUNCTION_BLOCK CLK_N
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(INT,N)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,EDGE)
  __DECLARE_VAR(BOOL,CLK)

} CLK_N;

void CLK_N_init__(CLK_N *data__, BOOL retain);
// Code part
void CLK_N_body__(CLK_N *data__);
// FUNCTION_BLOCK CLICK_DEC
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(TIME,TC)
  __DECLARE_VAR(BOOL,Q0)
  __DECLARE_VAR(BOOL,Q1)
  __DECLARE_VAR(BOOL,Q2)
  __DECLARE_VAR(BOOL,Q3)

  // FB private variables - TEMP, private and located variables
  TP TX;
  __DECLARE_VAR(BOOL,EDGE)
  __DECLARE_VAR(INT,CNT)

} CLICK_DEC;

void CLICK_DEC_init__(CLICK_DEC *data__, BOOL retain);
// Code part
void CLICK_DEC_body__(CLICK_DEC *data__);
// FUNCTION_BLOCK CLK_PRG
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(TIME,PT)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(TIME,LAST)
  __DECLARE_VAR(TIME,TX)

} CLK_PRG;

void CLK_PRG_init__(CLK_PRG *data__, BOOL retain);
// Code part
void CLK_PRG_body__(CLK_PRG *data__);
// FUNCTION_BLOCK CLK_PULSE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(TIME,PT)
  __DECLARE_VAR(INT,N)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(INT,CNT)
  __DECLARE_VAR(BOOL,RUN)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(UDINT,TX)
  __DECLARE_VAR(UDINT,TN)
  __DECLARE_VAR(BOOL,INIT)

} CLK_PULSE;

void CLK_PULSE_init__(CLK_PULSE *data__, BOOL retain);
// Code part
void CLK_PULSE_body__(CLK_PULSE *data__);
// FUNCTION_BLOCK GEN_SQ
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(TIME,PT)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(TIME,TN)
  __DECLARE_VAR(TIME,TX)

} GEN_SQ;

void GEN_SQ_init__(GEN_SQ *data__, BOOL retain);
// Code part
void GEN_SQ_body__(GEN_SQ *data__);
// FUNCTION_BLOCK TP_1
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(TIME,PT)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(TIME,START)
  __DECLARE_VAR(BOOL,IX)

} TP_1;

void TP_1_init__(TP_1 *data__, BOOL retain);
// Code part
void TP_1_body__(TP_1 *data__);
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
// FUNCTION_BLOCK D_TRIG
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(DWORD,IN)
  __DECLARE_VAR(DWORD,X)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(DWORD,LAST_IN)

} D_TRIG;

void D_TRIG_init__(D_TRIG *data__, BOOL retain);
// Code part
void D_TRIG_body__(D_TRIG *data__);
// FUNCTION_BLOCK SEQUENCE_8
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN0)
  __DECLARE_VAR(BOOL,IN1)
  __DECLARE_VAR(BOOL,IN2)
  __DECLARE_VAR(BOOL,IN3)
  __DECLARE_VAR(BOOL,IN4)
  __DECLARE_VAR(BOOL,IN5)
  __DECLARE_VAR(BOOL,IN6)
  __DECLARE_VAR(BOOL,IN7)
  __DECLARE_VAR(BOOL,START)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(TIME,WAIT0)
  __DECLARE_VAR(TIME,DELAY0)
  __DECLARE_VAR(TIME,WAIT1)
  __DECLARE_VAR(TIME,DELAY1)
  __DECLARE_VAR(TIME,WAIT2)
  __DECLARE_VAR(TIME,DELAY2)
  __DECLARE_VAR(TIME,WAIT3)
  __DECLARE_VAR(TIME,DELAY3)
  __DECLARE_VAR(TIME,WAIT4)
  __DECLARE_VAR(TIME,DELAY4)
  __DECLARE_VAR(TIME,WAIT5)
  __DECLARE_VAR(TIME,DELAY5)
  __DECLARE_VAR(TIME,WAIT6)
  __DECLARE_VAR(TIME,DELAY6)
  __DECLARE_VAR(TIME,WAIT7)
  __DECLARE_VAR(TIME,DELAY7)
  __DECLARE_VAR(BOOL,STOP_ON_ERROR)
  __DECLARE_VAR(BOOL,Q0)
  __DECLARE_VAR(BOOL,Q1)
  __DECLARE_VAR(BOOL,Q2)
  __DECLARE_VAR(BOOL,Q3)
  __DECLARE_VAR(BOOL,Q4)
  __DECLARE_VAR(BOOL,Q5)
  __DECLARE_VAR(BOOL,Q6)
  __DECLARE_VAR(BOOL,Q7)
  __DECLARE_VAR(BOOL,QX)
  __DECLARE_VAR(BOOL,RUN)
  __DECLARE_VAR(INT,_STEP)
  __DECLARE_VAR(BYTE,STATUS)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(TIME,LAST)
  __DECLARE_VAR(BOOL,EDGE)
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(BOOL,INIT)

} SEQUENCE_8;

void SEQUENCE_8_init__(SEQUENCE_8 *data__, BOOL retain);
// Code part
void SEQUENCE_8_body__(SEQUENCE_8 *data__);
// FUNCTION_BLOCK SEQUENCE_4
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN0)
  __DECLARE_VAR(BOOL,IN1)
  __DECLARE_VAR(BOOL,IN2)
  __DECLARE_VAR(BOOL,IN3)
  __DECLARE_VAR(BOOL,START)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(TIME,WAIT0)
  __DECLARE_VAR(TIME,DELAY0)
  __DECLARE_VAR(TIME,WAIT1)
  __DECLARE_VAR(TIME,DELAY1)
  __DECLARE_VAR(TIME,WAIT2)
  __DECLARE_VAR(TIME,DELAY2)
  __DECLARE_VAR(TIME,WAIT3)
  __DECLARE_VAR(TIME,DELAY3)
  __DECLARE_VAR(BOOL,STOP_ON_ERROR)
  __DECLARE_VAR(BOOL,Q0)
  __DECLARE_VAR(BOOL,Q1)
  __DECLARE_VAR(BOOL,Q2)
  __DECLARE_VAR(BOOL,Q3)
  __DECLARE_VAR(BOOL,QX)
  __DECLARE_VAR(BOOL,RUN)
  __DECLARE_VAR(INT,_STEP)
  __DECLARE_VAR(BYTE,STATUS)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(TIME,LAST)
  __DECLARE_VAR(BOOL,EDGE)
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(BOOL,INIT)

} SEQUENCE_4;

void SEQUENCE_4_init__(SEQUENCE_4 *data__, BOOL retain);
// Code part
void SEQUENCE_4_body__(SEQUENCE_4 *data__);
// FUNCTION_BLOCK SCHEDULER_2
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,E0)
  __DECLARE_VAR(BOOL,E1)
  __DECLARE_VAR(BOOL,E2)
  __DECLARE_VAR(BOOL,E3)
  __DECLARE_VAR(UINT,C0)
  __DECLARE_VAR(UINT,C1)
  __DECLARE_VAR(UINT,C2)
  __DECLARE_VAR(UINT,C3)
  __DECLARE_VAR(UINT,O0)
  __DECLARE_VAR(UINT,O1)
  __DECLARE_VAR(UINT,O2)
  __DECLARE_VAR(UINT,O3)
  __DECLARE_VAR(BOOL,Q0)
  __DECLARE_VAR(BOOL,Q1)
  __DECLARE_VAR(BOOL,Q2)
  __DECLARE_VAR(BOOL,Q3)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(UINT,SX)

} SCHEDULER_2;

void SCHEDULER_2_init__(SCHEDULER_2 *data__, BOOL retain);
// Code part
void SCHEDULER_2_body__(SCHEDULER_2 *data__);
// FUNCTION_BLOCK TMAX
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(TIME,PT)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(BOOL,Z)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(TIME,START)
  __DECLARE_VAR(BOOL,LAST_IN)

} TMAX;

void TMAX_init__(TMAX *data__, BOOL retain);
// Code part
void TMAX_body__(TMAX *data__);
// FUNCTION_BLOCK CLK_DIV
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,CLK)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(BOOL,RST0)
  __DECLARE_VAR(BOOL,Q0)
  __DECLARE_VAR(BOOL,Q1)
  __DECLARE_VAR(BOOL,Q2)
  __DECLARE_VAR(BOOL,Q3)
  __DECLARE_VAR(BOOL,Q4)
  __DECLARE_VAR(BOOL,Q5)
  __DECLARE_VAR(BOOL,Q6)
  __DECLARE_VAR(BOOL,Q7)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BYTE,CNT)

} CLK_DIV;

void CLK_DIV_init__(CLK_DIV *data__, BOOL retain);
// Code part
void CLK_DIV_body__(CLK_DIV *data__);
// FUNCTION_BLOCK TOF_1
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(TIME,PT)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(TIME,START)
  __DECLARE_VAR(TIME,TX)

} TOF_1;

void TOF_1_init__(TOF_1 *data__, BOOL retain);
// Code part
void TOF_1_body__(TOF_1 *data__);
// FUNCTION_BLOCK SCHEDULER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,E0)
  __DECLARE_VAR(BOOL,E1)
  __DECLARE_VAR(BOOL,E2)
  __DECLARE_VAR(BOOL,E3)
  __DECLARE_VAR(TIME,T0)
  __DECLARE_VAR(TIME,T1)
  __DECLARE_VAR(TIME,T2)
  __DECLARE_VAR(TIME,T3)
  __DECLARE_VAR(BOOL,Q0)
  __DECLARE_VAR(BOOL,Q1)
  __DECLARE_VAR(BOOL,Q2)
  __DECLARE_VAR(BOOL,Q3)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(TIME,S0)
  __DECLARE_VAR(TIME,S1)
  __DECLARE_VAR(TIME,S2)
  __DECLARE_VAR(TIME,S3)
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(INT,C)

} SCHEDULER;

void SCHEDULER_init__(SCHEDULER *data__, BOOL retain);
// Code part
void SCHEDULER_body__(SCHEDULER *data__);
// FUNCTION_BLOCK GEN_BIT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(DWORD,IN0)
  __DECLARE_VAR(DWORD,IN1)
  __DECLARE_VAR(DWORD,IN2)
  __DECLARE_VAR(DWORD,IN3)
  __DECLARE_VAR(BOOL,CLK)
  __DECLARE_VAR(INT,STEPS)
  __DECLARE_VAR(INT,REP)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(BOOL,Q0)
  __DECLARE_VAR(BOOL,Q1)
  __DECLARE_VAR(BOOL,Q2)
  __DECLARE_VAR(BOOL,Q3)
  __DECLARE_VAR(INT,CNT)
  __DECLARE_VAR(BOOL,RUN)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(DWORD,R0)
  __DECLARE_VAR(DWORD,R1)
  __DECLARE_VAR(DWORD,R2)
  __DECLARE_VAR(DWORD,R3)
  __DECLARE_VAR(INT,RX)

} GEN_BIT;

void GEN_BIT_init__(GEN_BIT *data__, BOOL retain);
// Code part
void GEN_BIT_body__(GEN_BIT *data__);
// FUNCTION_BLOCK A_TRIG
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(REAL,RES)
  __DECLARE_VAR(REAL,_D)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,LAST_IN)

} A_TRIG;

void A_TRIG_init__(A_TRIG *data__, BOOL retain);
// Code part
void A_TRIG_body__(A_TRIG *data__);
#endif //__POUS_H
