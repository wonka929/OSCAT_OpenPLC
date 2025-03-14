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
REAL WORD_TO_RANGE(
  BOOL EN, 
  BOOL *__ENO, 
  WORD X, 
  REAL LOW, 
  REAL HIGH);
// FUNCTION
REAL SCALE(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL K, 
  REAL O, 
  REAL MX, 
  REAL MN);
// FUNCTION
REAL SCALE_X4(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL IN1, 
  BOOL IN2, 
  BOOL IN3, 
  BOOL IN4, 
  REAL K, 
  REAL O, 
  REAL IN1_MIN, 
  REAL IN1_MAX, 
  REAL IN2_MIN, 
  REAL IN2_MAX, 
  REAL IN3_MIN, 
  REAL IN3_MAX, 
  REAL IN4_MIN, 
  REAL IN4_MAX);
// FUNCTION
BOOL SIGN_R(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN);
// FUNCTION
DWORD AOUT(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN, 
  BYTE BITS, 
  BYTE SIGN, 
  REAL LOW, 
  REAL HIGH);
// FUNCTION
REAL OFFSET2(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  BOOL O1, 
  BOOL O2, 
  BOOL O3, 
  BOOL O4, 
  BOOL _D);
// FUNCTION
UDINT T_PLC_MS(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL DEBUG);
// FUNCTION_BLOCK FILTER_DW
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(DWORD,X)
  __DECLARE_VAR(TIME,_T)
  __DECLARE_VAR(DWORD,Y)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(UDINT,LAST)
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(UDINT,TX)
  __DECLARE_VAR(REAL,YI)

} FILTER_DW;

void FILTER_DW_init__(FILTER_DW *data__, BOOL retain);
// Code part
void FILTER_DW_body__(FILTER_DW *data__);
// FUNCTION
WORD RANGE_TO_WORD(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL LOW, 
  REAL HIGH);
// FUNCTION
REAL SCALE_X8(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL IN1, 
  BOOL IN2, 
  BOOL IN3, 
  BOOL IN4, 
  BOOL IN5, 
  BOOL IN6, 
  BOOL IN7, 
  BOOL IN8, 
  REAL K, 
  REAL O, 
  REAL IN1_MIN, 
  REAL IN1_MAX, 
  REAL IN2_MIN, 
  REAL IN2_MAX, 
  REAL IN3_MIN, 
  REAL IN3_MAX, 
  REAL IN4_MIN, 
  REAL IN4_MAX, 
  REAL IN5_MIN, 
  REAL IN5_MAX, 
  REAL IN6_MIN, 
  REAL IN6_MAX, 
  REAL IN7_MIN, 
  REAL IN7_MAX, 
  REAL IN8_MIN, 
  REAL IN8_MAX);
// FUNCTION
INT INC1(
  BOOL EN, 
  BOOL *__ENO, 
  INT X, 
  INT N);
__DECLARE_ARRAY_TYPE(__ARRAY_OF_DWORD_32,DWORD,[32])
// FUNCTION_BLOCK FILTER_MAV_DW
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(DWORD,X)
  __DECLARE_VAR(UINT,N)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(DWORD,Y)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(__ARRAY_OF_DWORD_32,BUFFER)
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(INT,TMP)

} FILTER_MAV_DW;

void FILTER_MAV_DW_init__(FILTER_MAV_DW *data__, BOOL retain);
// Code part
void FILTER_MAV_DW_body__(FILTER_MAV_DW *data__);
__DECLARE_ARRAY_TYPE(__ARRAY_OF_REAL_32,REAL,[32])
// FUNCTION_BLOCK DELAY
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(INT,N)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(REAL,OUT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(__ARRAY_OF_REAL_32,BUF)
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(INT,STOP)

} DELAY;

void DELAY_init__(DELAY *data__, BOOL retain);
// Code part
void DELAY_body__(DELAY *data__);
// FUNCTION
REAL MIX(
  BOOL EN, 
  BOOL *__ENO, 
  REAL A, 
  REAL B, 
  REAL M);
// FUNCTION
BOOL BIT_OF_DWORD(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN, 
  INT N);
// FUNCTION
REAL AIN(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN, 
  BYTE BITS, 
  BYTE SIGN, 
  REAL LOW, 
  REAL HIGH);
// FUNCTION
REAL MUX_R4(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN0, 
  REAL IN1, 
  REAL IN2, 
  REAL IN3, 
  BOOL A0, 
  BOOL A1);
// FUNCTION
REAL BYTE_TO_RANGE(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE X, 
  REAL LOW, 
  REAL HIGH);
// FUNCTION
REAL OFFSET_OSCAT(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  BOOL O1, 
  BOOL O2, 
  BOOL O3, 
  BOOL O4, 
  BOOL _D);
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
REAL STAIR(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL _D);
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
// FUNCTION_BLOCK FILTER_W
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(WORD,X)
  __DECLARE_VAR(TIME,_T)
  __DECLARE_VAR(WORD,Y)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(UDINT,LAST)
  __DECLARE_VAR(UDINT,TX)
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(DINT,TMP)

} FILTER_W;

void FILTER_W_init__(FILTER_W *data__, BOOL retain);
// Code part
void FILTER_W_body__(FILTER_W *data__);
// FUNCTION
BYTE RANGE_TO_BYTE(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL LOW, 
  REAL HIGH);
// FUNCTION_BLOCK SH
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(BOOL,CLK)
  __DECLARE_VAR(REAL,OUT)
  __DECLARE_VAR(BOOL,TRIG)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,EDGE)

} SH;

void SH_init__(SH *data__, BOOL retain);
// Code part
void SH_body__(SH *data__);
// FUNCTION_BLOCK FADE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN1)
  __DECLARE_VAR(REAL,IN2)
  __DECLARE_VAR(BOOL,F)
  __DECLARE_VAR(TIME,TF)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(REAL,Y)

  // FB private variables - TEMP, private and located variables
  RMP_W RMX;

} FADE;

void FADE_init__(FADE *data__, BOOL retain);
// Code part
void FADE_body__(FADE *data__);
// FUNCTION_BLOCK SEL2_OF_3
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN1)
  __DECLARE_VAR(REAL,IN2)
  __DECLARE_VAR(REAL,IN3)
  __DECLARE_VAR(REAL,_D)
  __DECLARE_VAR(REAL,Y)
  __DECLARE_VAR(INT,W)
  __DECLARE_VAR(BOOL,_E)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,D12)
  __DECLARE_VAR(BOOL,D23)
  __DECLARE_VAR(BOOL,D31)

} SEL2_OF_3;

void SEL2_OF_3_init__(SEL2_OF_3 *data__, BOOL retain);
// Code part
void SEL2_OF_3_body__(SEL2_OF_3 *data__);
// FUNCTION
REAL OVERRIDE(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X1, 
  REAL X2, 
  REAL X3, 
  BOOL E1, 
  BOOL E2, 
  BOOL E3);
// FUNCTION_BLOCK SH_T
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(BOOL,_E)
  __DECLARE_VAR(REAL,OUT)

  // FB private variables - TEMP, private and located variables

} SH_T;

void SH_T_init__(SH_T *data__, BOOL retain);
// Code part
void SH_T_body__(SH_T *data__);
// FUNCTION
INT FLOOR(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION_BLOCK STAIR2
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,X)
  __DECLARE_VAR(REAL,_D)
  __DECLARE_VAR(REAL,Y)

  // FB private variables - TEMP, private and located variables

} STAIR2;

void STAIR2_init__(STAIR2 *data__, BOOL retain);
// Code part
void STAIR2_body__(STAIR2 *data__);
// FUNCTION_BLOCK FILTER_I
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(INT,X)
  __DECLARE_VAR(TIME,_T)
  __DECLARE_VAR(INT,Y)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(DINT,YI)
  __DECLARE_VAR(UDINT,LAST)
  __DECLARE_VAR(UDINT,TX)
  __DECLARE_VAR(BOOL,INIT)

} FILTER_I;

void FILTER_I_init__(FILTER_I *data__, BOOL retain);
// Code part
void FILTER_I_body__(FILTER_I *data__);
// FUNCTION
REAL SCALE_X2(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL IN1, 
  BOOL IN2, 
  REAL K, 
  REAL O, 
  REAL IN1_MIN, 
  REAL IN1_MAX, 
  REAL IN2_MIN, 
  REAL IN2_MAX);
// FUNCTION_BLOCK SH_1
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(TIME,PT)
  __DECLARE_VAR(REAL,OUT)
  __DECLARE_VAR(BOOL,TRIG)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(TIME,LAST)
  __DECLARE_VAR(TIME,TX)

} SH_1;

void SH_1_init__(SH_1 *data__, BOOL retain);
// Code part
void SH_1_body__(SH_1 *data__);
// FUNCTION
BOOL EVEN(
  BOOL EN, 
  BOOL *__ENO, 
  DINT IN);
__DECLARE_ARRAY_TYPE(__ARRAY_OF_REAL_16,REAL,[16])
// FUNCTION_BLOCK SH_2
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(TIME,PT)
  __DECLARE_VAR(INT,N)
  __DECLARE_VAR(INT,DISC)
  __DECLARE_VAR(REAL,OUT)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(REAL,AVG)
  __DECLARE_VAR(REAL,HIGH)
  __DECLARE_VAR(REAL,LOW)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,M)
  __DECLARE_VAR(__ARRAY_OF_REAL_16,BUF)
  __DECLARE_VAR(__ARRAY_OF_REAL_16,BUF2)
  __DECLARE_VAR(TIME,LAST)
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(INT,I2)
  __DECLARE_VAR(INT,START)
  __DECLARE_VAR(REAL,TEMP)
  __DECLARE_VAR(INT,STOP)
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(INT,D2)

} SH_2;

void SH_2_init__(SH_2 *data__, BOOL retain);
// Code part
void SH_2_body__(SH_2 *data__);
// FUNCTION_BLOCK DELAY_4
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(REAL,OUT1)
  __DECLARE_VAR(REAL,OUT2)
  __DECLARE_VAR(REAL,OUT3)
  __DECLARE_VAR(REAL,OUT4)
  __DECLARE_VAR(REAL,TEMP)

  // FB private variables - TEMP, private and located variables

} DELAY_4;

void DELAY_4_init__(DELAY_4 *data__, BOOL retain);
// Code part
void DELAY_4_body__(DELAY_4 *data__);
// FUNCTION
REAL SCALE_B2(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE IN1, 
  BYTE IN2, 
  REAL K, 
  REAL O, 
  REAL IN1_MIN, 
  REAL IN1_MAX, 
  REAL IN2_MIN, 
  REAL IN2_MAX);
// FUNCTION
REAL SCALE_B4(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE IN1, 
  BYTE IN2, 
  BYTE IN3, 
  BYTE IN4, 
  REAL K, 
  REAL O, 
  REAL IN1_MIN, 
  REAL IN1_MAX, 
  REAL IN2_MIN, 
  REAL IN2_MAX, 
  REAL IN3_MIN, 
  REAL IN3_MAX, 
  REAL IN4_MIN, 
  REAL IN4_MAX);
// FUNCTION_BLOCK TREND
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,X)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(BOOL,TU)
  __DECLARE_VAR(BOOL,TD)
  __DECLARE_VAR(REAL,_D)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,LAST_X)

} TREND;

void TREND_init__(TREND *data__, BOOL retain);
// Code part
void TREND_body__(TREND *data__);
// FUNCTION
REAL SCALE_B8(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE IN1, 
  BYTE IN2, 
  BYTE IN3, 
  BYTE IN4, 
  BYTE IN5, 
  BYTE IN6, 
  BYTE IN7, 
  BYTE IN8, 
  REAL K, 
  REAL O, 
  REAL IN1_MIN, 
  REAL IN1_MAX, 
  REAL IN2_MIN, 
  REAL IN2_MAX, 
  REAL IN3_MIN, 
  REAL IN3_MAX, 
  REAL IN4_MIN, 
  REAL IN4_MAX, 
  REAL IN5_MIN, 
  REAL IN5_MAX, 
  REAL IN6_MIN, 
  REAL IN6_MAX, 
  REAL IN7_MIN, 
  REAL IN7_MAX, 
  REAL IN8_MIN, 
  REAL IN8_MAX);
// FUNCTION
DWORD AOUT1(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN, 
  INT BIT_0, 
  INT BIT_N, 
  INT SIGN, 
  REAL LOW, 
  REAL HIGH, 
  REAL IN2, 
  BOOL SX);
// FUNCTION
REAL SCALE_B(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE X, 
  BYTE I_LO, 
  BYTE I_HI, 
  REAL O_LO, 
  REAL O_HI);
// FUNCTION
REAL SCALE_D(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD X, 
  DWORD I_LO, 
  DWORD I_HI, 
  REAL O_LO, 
  REAL O_HI);
// FUNCTION_BLOCK SEL2_OF_3B
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN1)
  __DECLARE_VAR(BOOL,IN2)
  __DECLARE_VAR(BOOL,IN3)
  __DECLARE_VAR(TIME,TD)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(BOOL,W)

  // FB private variables - TEMP, private and located variables
  TON TDEL;

} SEL2_OF_3B;

void SEL2_OF_3B_init__(SEL2_OF_3B *data__, BOOL retain);
// Code part
void SEL2_OF_3B_body__(SEL2_OF_3B *data__);
__DECLARE_ARRAY_TYPE(__ARRAY_OF_WORD_32,WORD,[32])
// FUNCTION_BLOCK FILTER_MAV_W
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(WORD,X)
  __DECLARE_VAR(UINT,N)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(WORD,Y)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(__ARRAY_OF_WORD_32,BUFFER)
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(UDINT,SUM)
  __DECLARE_VAR(INT,TMP)

} FILTER_MAV_W;

void FILTER_MAV_W_init__(FILTER_MAV_W *data__, BOOL retain);
// Code part
void FILTER_MAV_W_body__(FILTER_MAV_W *data__);
// FUNCTION
REAL SCALE_R(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL I_LO, 
  REAL I_HI, 
  REAL O_LO, 
  REAL O_HI);
// FUNCTION
REAL MUX_R2(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN0, 
  REAL IN1, 
  BOOL A);
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
// FUNCTION
INT DEC1(
  BOOL EN, 
  BOOL *__ENO, 
  INT X, 
  INT N);
// FUNCTION_BLOCK FILTER_WAV
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,X)
  __DECLARE_VAR(__ARRAY_OF_REAL_16,W)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(REAL,Y)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(__ARRAY_OF_REAL_16,BUFFER)
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(INT,N)

} FILTER_WAV;

void FILTER_WAV_init__(FILTER_WAV *data__, BOOL retain);
// Code part
void FILTER_WAV_body__(FILTER_WAV *data__);
#endif //__POUS_H
