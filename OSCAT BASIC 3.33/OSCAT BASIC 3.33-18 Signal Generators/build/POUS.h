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
// FUNCTION
DINT D_TRUNC(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
REAL FRACT(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
BOOL BIT_OF_DWORD(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN, 
  INT N);
// FUNCTION
UDINT T_PLC_MS(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL DEBUG);
// FUNCTION
DWORD BIT_LOAD_DW(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN, 
  BOOL VAL, 
  INT POS);
// FUNCTION
INT BIT_COUNT(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN);
// FUNCTION_BLOCK RDM
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,LAST)
  __DECLARE_VAR(REAL,_RDM)
  __DECLARE_VAR(DWORD,TN)
  __DECLARE_VAR(INT,TC)

  // FB private variables - TEMP, private and located variables

} RDM;

void RDM_init__(RDM *data__, BOOL retain);
// Code part
void RDM_body__(RDM *data__);
// FUNCTION_BLOCK GEN_RDT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,ENABLE)
  __DECLARE_VAR(TIME,MIN_TIME_MS)
  __DECLARE_VAR(TIME,MAX_TIME_MS)
  __DECLARE_VAR(TIME,TP_Q)
  __DECLARE_VAR(BOOL,XQ)

  // FB private variables - TEMP, private and located variables
  TON TONRDMTIMER;
  TOF TOF_XQ;
  __DECLARE_VAR(TIME,TRDMTIME)
  __DECLARE_VAR(REAL,RRDMTIME)
  RDM RDM_1;

} GEN_RDT;

void GEN_RDT_init__(GEN_RDT *data__, BOOL retain);
// Code part
void GEN_RDT_body__(GEN_RDT *data__);
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
// FUNCTION_BLOCK PWM_PW
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,F)
  __DECLARE_VAR(TIME,PW)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  CLK_PRG CLK;
  TP_X PULSE;

} PWM_PW;

void PWM_PW_init__(PWM_PW *data__, BOOL retain);
// Code part
void PWM_PW_body__(PWM_PW *data__);
// FUNCTION_BLOCK GEN_RDM
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(TIME,PT)
  __DECLARE_VAR(REAL,AM)
  __DECLARE_VAR(REAL,OS)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(REAL,OUT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(TIME,LAST)
  __DECLARE_VAR(BOOL,INIT)
  RDM FB_RDM;

} GEN_RDM;

void GEN_RDM_init__(GEN_RDM *data__, BOOL retain);
// Code part
void GEN_RDM_body__(GEN_RDM *data__);
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
DINT _WORD_TO_DINT(
  BOOL EN, 
  BOOL *__ENO, 
  WORD IN);
// FUNCTION_BLOCK _RMP_W
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,DIR)
  __DECLARE_VAR(BOOL,_E)
  __DECLARE_VAR(TIME,TR)
  __DECLARE_VAR(WORD,RMP)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(UDINT,TX)
  __DECLARE_VAR(UDINT,TL)
  __DECLARE_VAR(DINT,_STEP)
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(BOOL,LAST_DIR)

} _RMP_W;

void _RMP_W_init__(_RMP_W *data__, BOOL retain);
// Code part
void _RMP_W_body__(_RMP_W *data__);
// FUNCTION_BLOCK RMP_W
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,SET)
  __DECLARE_VAR(TIME,PT)
  __DECLARE_VAR(BOOL,_E)
  __DECLARE_VAR(BOOL,UP)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(WORD,OUT)
  __DECLARE_VAR(BOOL,BUSY)
  __DECLARE_VAR(BOOL,HIGH)
  __DECLARE_VAR(BOOL,LOW)

  // FB private variables - TEMP, private and located variables
  _RMP_W RMP;

} RMP_W;

void RMP_W_init__(RMP_W *data__, BOOL retain);
// Code part
void RMP_W_body__(RMP_W *data__);
// FUNCTION
BYTE FRMP_B(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE START, 
  BOOL DIR, 
  TIME TD, 
  TIME TR);
// FUNCTION
BOOL SIGN_R(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN);
// FUNCTION_BLOCK _RMP_B
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,DIR)
  __DECLARE_VAR(BOOL,_E)
  __DECLARE_VAR(TIME,TR)
  __DECLARE_VAR(BYTE,RMP)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(TIME,TL)
  __DECLARE_VAR(TIME,TN)
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(BOOL,LAST_DIR)
  __DECLARE_VAR(BYTE,START)

} _RMP_B;

void _RMP_B_init__(_RMP_B *data__, BOOL retain);
// Code part
void _RMP_B_body__(_RMP_B *data__);
// FUNCTION_BLOCK RMP_B
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,SET)
  __DECLARE_VAR(TIME,PT)
  __DECLARE_VAR(BOOL,_E)
  __DECLARE_VAR(BOOL,UP)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(BYTE,OUT)
  __DECLARE_VAR(BOOL,BUSY)
  __DECLARE_VAR(BOOL,HIGH)
  __DECLARE_VAR(BOOL,LOW)

  // FB private variables - TEMP, private and located variables
  _RMP_B RMP;

} RMP_B;

void RMP_B_init__(RMP_B *data__, BOOL retain);
// Code part
void RMP_B_body__(RMP_B *data__);
// FUNCTION_BLOCK GEN_SQR
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(TIME,PT)
  __DECLARE_VAR(REAL,AM)
  __DECLARE_VAR(REAL,OS)
  __DECLARE_VAR(REAL,DL)
  __DECLARE_VAR(REAL,DC)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(REAL,OUT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(TIME,LAST)
  __DECLARE_VAR(BOOL,INIT)

} GEN_SQR;

void GEN_SQR_init__(GEN_SQR *data__, BOOL retain);
// Code part
void GEN_SQR_body__(GEN_SQR *data__);
// FUNCTION_BLOCK TREND_DW
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(DWORD,X)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(BOOL,TU)
  __DECLARE_VAR(BOOL,TD)
  __DECLARE_VAR(DWORD,_D)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(DWORD,LAST_X)

} TREND_DW;

void TREND_DW_init__(TREND_DW *data__, BOOL retain);
// Code part
void TREND_DW_body__(TREND_DW *data__);
// FUNCTION_BLOCK _RMP_NEXT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,_E)
  __DECLARE_VAR(BYTE,IN)
  __DECLARE_VAR(TIME,TR)
  __DECLARE_VAR(TIME,TF)
  __DECLARE_VAR(TIME,TL)
  __DECLARE_VAR(BOOL,DIR)
  __DECLARE_VAR(BOOL,UP)
  __DECLARE_VAR(BOOL,DN)
  __DECLARE_VAR(BYTE,OUT)

  // FB private variables - TEMP, private and located variables
  _RMP_B RMX;
  TREND_DW DIRX;
  TP T_LOCK;
  __DECLARE_VAR(BOOL,XEN)
  __DECLARE_VAR(BOOL,XDIR)

} _RMP_NEXT;

void _RMP_NEXT_init__(_RMP_NEXT *data__, BOOL retain);
// Code part
void _RMP_NEXT_body__(_RMP_NEXT *data__);
// FUNCTION_BLOCK GEN_PW2
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,ENQ)
  __DECLARE_VAR(TIME,TH1)
  __DECLARE_VAR(TIME,TH2)
  __DECLARE_VAR(TIME,TL1)
  __DECLARE_VAR(TIME,TL2)
  __DECLARE_VAR(BOOL,TS)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(TIME,TH)
  __DECLARE_VAR(TIME,TL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(TIME,T_HIGH)
  __DECLARE_VAR(TIME,T_LOW)
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(TIME,START)
  __DECLARE_VAR(TIME,ET)
  __DECLARE_VAR(BOOL,INIT)

} GEN_PW2;

void GEN_PW2_init__(GEN_PW2 *data__, BOOL retain);
// Code part
void GEN_PW2_body__(GEN_PW2 *data__);
// FUNCTION_BLOCK RMP_SOFT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(BYTE,VAL)
  __DECLARE_VAR(TIME,PT_ON)
  __DECLARE_VAR(TIME,PT_OFF)
  __DECLARE_VAR(BYTE,OUT)

  // FB private variables - TEMP, private and located variables
  _RMP_B RMP;
  __DECLARE_VAR(BYTE,TMP)

} RMP_SOFT;

void RMP_SOFT_init__(RMP_SOFT *data__, BOOL retain);
// Code part
void RMP_SOFT_body__(RMP_SOFT *data__);
// FUNCTION_BLOCK GEN_PULSE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,ENQ)
  __DECLARE_VAR(TIME,PTH)
  __DECLARE_VAR(TIME,PTL)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(TIME,TN)
  __DECLARE_VAR(BOOL,INIT)

} GEN_PULSE;

void GEN_PULSE_init__(GEN_PULSE *data__, BOOL retain);
// Code part
void GEN_PULSE_body__(GEN_PULSE *data__);
// FUNCTION_BLOCK PWM_DC
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,F)
  __DECLARE_VAR(REAL,DC)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  CLK_PRG CLK;
  TP_X PULSE;
  __DECLARE_VAR(REAL,TMP)

} PWM_DC;

void PWM_DC_init__(PWM_DC *data__, BOOL retain);
// Code part
void PWM_DC_body__(PWM_DC *data__);
// FUNCTION_BLOCK GEN_RMP
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(TIME,PT)
  __DECLARE_VAR(REAL,AM)
  __DECLARE_VAR(REAL,OS)
  __DECLARE_VAR(REAL,DL)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(REAL,OUT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(TIME,LAST)
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(REAL,TEMP)
  __DECLARE_VAR(REAL,LTEMP)

} GEN_RMP;

void GEN_RMP_init__(GEN_RMP *data__, BOOL retain);
// Code part
void GEN_RMP_body__(GEN_RMP *data__);
// FUNCTION_BLOCK GEN_SIN
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(TIME,PT)
  __DECLARE_VAR(REAL,AM)
  __DECLARE_VAR(REAL,OS)
  __DECLARE_VAR(REAL,DL)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(REAL,OUT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(TIME,LAST)
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(REAL,TEMP)

} GEN_SIN;

void GEN_SIN_init__(GEN_SIN *data__, BOOL retain);
// Code part
void GEN_SIN_body__(GEN_SIN *data__);
#endif //__POUS_H
