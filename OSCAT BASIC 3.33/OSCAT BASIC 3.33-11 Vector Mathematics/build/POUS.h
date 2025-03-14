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
__DECLARE_STRUCT_TYPE(VECTOR_3,
  REAL X;
    REAL Y;
    REAL Z;
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
REAL V3_DPRO(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A, 
  VECTOR_3 B);
// FUNCTION
REAL V3_ABS(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A);
// FUNCTION
REAL V3_ANG(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A, 
  VECTOR_3 B);
// FUNCTION
VECTOR_3 V3_ADD(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A, 
  VECTOR_3 B);
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
VECTOR_3 V3_REV(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A);
// FUNCTION
VECTOR_3 V3_SMUL(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A, 
  REAL M);
// FUNCTION
VECTOR_3 V3_NORM(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A);
// FUNCTION
BOOL V3_NUL(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A);
// FUNCTION
VECTOR_3 V3_XPRO(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A, 
  VECTOR_3 B);
// FUNCTION
BOOL V3_PAR(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A, 
  VECTOR_3 B);
// FUNCTION
VECTOR_3 V3_SUB(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A, 
  VECTOR_3 B);
// FUNCTION
REAL V3_XANG(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A);
// FUNCTION
REAL V3_YANG(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A);
// FUNCTION
REAL V3_ZANG(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A);
#endif //__POUS_H
