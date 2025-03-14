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
UDINT T_PLC_MS(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL DEBUG);
// FUNCTION_BLOCK FT_RMP
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,RMP)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(REAL,KR)
  __DECLARE_VAR(REAL,KF)
  __DECLARE_VAR(REAL,OUT)
  __DECLARE_VAR(BOOL,BUSY)
  __DECLARE_VAR(BOOL,UD)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(TIME,LAST)
  __DECLARE_VAR(BOOL,INIT)

} FT_RMP;

void FT_RMP_init__(FT_RMP *data__, BOOL retain);
// Code part
void FT_RMP_body__(FT_RMP *data__);
// FUNCTION
INT INC1(
  BOOL EN, 
  BOOL *__ENO, 
  INT X, 
  INT N);
__DECLARE_ARRAY_TYPE(__ARRAY_OF_REAL_8,REAL,[8])
// FUNCTION_BLOCK F_POLY
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,X)
  __DECLARE_VAR(__ARRAY_OF_REAL_8,C)
  __DECLARE_VAR(REAL,_F_POLY)

  // FB private variables - TEMP, private and located variables

} F_POLY;

void F_POLY_init__(F_POLY *data__, BOOL retain);
// Code part
void F_POLY_body__(F_POLY *data__);
// PROGRAM PROGRAM0
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(DINT,LOCALVAR0)
  __DECLARE_VAR(DINT,LOCALVAR1)
  __DECLARE_VAR(DINT,LOCALVAR2)
  __DECLARE_VAR(REAL,LOCALVAR3)
  F_POLY F_POLY0;
  __DECLARE_VAR(DINT,ADD1_OUT)

} PROGRAM0;

void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain);
// Code part
void PROGRAM0_body__(PROGRAM0 *data__);
__DECLARE_ARRAY_TYPE(__ARRAY_OF_REAL_20_2,REAL,[20][2])
// FUNCTION
REAL LINEAR_INT(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  __ARRAY_OF_REAL_20_2 XY, 
  INT PTS);
// FUNCTION_BLOCK _FB_LINEAR_INT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,X)
  __DECLARE_VAR(__ARRAY_OF_REAL_20_2,XY)
  __DECLARE_VAR(INT,PTS)
  __DECLARE_VAR(REAL,_LINEAR_INT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(INT,I2)

} _FB_LINEAR_INT;

void _FB_LINEAR_INT_init__(_FB_LINEAR_INT *data__, BOOL retain);
// Code part
void _FB_LINEAR_INT_body__(_FB_LINEAR_INT *data__);
// FUNCTION
BYTE FRMP_B(
  BOOL EN, 
  BOOL *__ENO);
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
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(INT,STOP)
  __DECLARE_VAR(__ARRAY_OF_REAL_32,BUF)

} DELAY;

void DELAY_init__(DELAY *data__, BOOL retain);
// Code part
void DELAY_body__(DELAY *data__);
// FUNCTION_BLOCK FT_AVG
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(BOOL,_E)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(INT,N)
  __DECLARE_VAR(REAL,AVG)

  // FB private variables - TEMP, private and located variables
  DELAY BUFF;
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(BOOL,INIT)

} FT_AVG;

void FT_AVG_init__(FT_AVG *data__, BOOL retain);
// Code part
void FT_AVG_body__(FT_AVG *data__);
// FUNCTION
REAL F_QUAD(
  BOOL EN, 
  BOOL *__ENO);
// FUNCTION
REAL F_POWER(
  BOOL EN, 
  BOOL *__ENO);
// FUNCTION
REAL F_LIN(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL A, 
  REAL B);
// FUNCTION
REAL F_LIN2(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL X1, 
  REAL X2, 
  REAL Y1, 
  REAL Y2);
__DECLARE_ARRAY_TYPE(__ARRAY_OF_REAL_5_2,REAL,[5][2])
// FUNCTION
REAL POLYNOM_INT(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  __ARRAY_OF_REAL_5_2 XY, 
  INT PTS);
// FUNCTION_BLOCK FT_MIN_MAX
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(REAL,MX)
  __DECLARE_VAR(REAL,MN)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,INIT)

} FT_MIN_MAX;

void FT_MIN_MAX_init__(FT_MIN_MAX *data__, BOOL retain);
// Code part
void FT_MIN_MAX_body__(FT_MIN_MAX *data__);
#endif //__POUS_H
