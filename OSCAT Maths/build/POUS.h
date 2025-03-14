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
__DECLARE_STRUCT_TYPE(FRACTION,
  INT NUMERATOR;
    INT DENOMINATOR;
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
INT SGN(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
REAL ERF(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
REAL GAUSSCD(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL U, 
  REAL SI);
// FUNCTION
REAL GOLD(
  BOOL EN, 
  BOOL *__ENO);
// FUNCTION
REAL SINC(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
REAL MAX3(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN1, 
  REAL IN2, 
  REAL IN3);
// FUNCTION
REAL ATANH(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
REAL NEGX(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
INT CEIL(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
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
  REAL RAD);
// FUNCTION
REAL RAD1(
  BOOL EN, 
  BOOL *__ENO, 
  REAL _DEG);
// FUNCTION
REAL CAUCHY(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL T_CAUCHY, 
  REAL U);
// FUNCTION
REAL CAUCHYCD(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL T_CAUCHY, 
  REAL U);
// FUNCTION
BOOL BIT_OF_DWORD(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN, 
  INT N);
// FUNCTION
REAL MID3(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN1, 
  REAL IN2, 
  REAL IN3);
// FUNCTION
REAL GAMMA(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
INT FLOOR(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
REAL EXP10(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
BOOL CMP(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL Y, 
  INT N);
// PROGRAM PROGRAM0
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,LOCALVAR0)
  __DECLARE_VAR(FRACTION,LOCALVAR2)
  __DECLARE_VAR(INT,LOCALVAR1)
  __DECLARE_VAR(INT,CEIL5_OUT)

} PROGRAM0;

void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain);
// Code part
void PROGRAM0_body__(PROGRAM0 *data__);
// FUNCTION
BOOL SIGN_I(
  BOOL EN, 
  BOOL *__ENO, 
  DINT IN);
// FUNCTION
REAL ACOTH(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
REAL SIGMOID(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
REAL LAMBERT_W(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
REAL COTH(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
REAL LANGEVIN(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
BOOL WINDOW(
  BOOL EN, 
  BOOL *__ENO, 
  REAL LOW, 
  REAL IN, 
  REAL HIGH);
// FUNCTION
BOOL SIGN_R(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN);
// FUNCTION
REAL ROUND(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN, 
  INT N);
// FUNCTION
REAL ERFC(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
REAL EXPN(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  INT N);
// FUNCTION
REAL SINH(
  BOOL EN, 
  BOOL *__ENO);
// FUNCTION
REAL MUL_ADD(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL K, 
  REAL O);
// FUNCTION
INT INC1(
  BOOL EN, 
  BOOL *__ENO, 
  INT X, 
  INT N);
// FUNCTION
INT INC2(
  BOOL EN, 
  BOOL *__ENO, 
  INT X, 
  INT _D, 
  INT L, 
  INT U);
// FUNCTION
INT GCD(
  BOOL EN, 
  BOOL *__ENO, 
  DINT A, 
  DINT B);
// FUNCTION
BOOL DIFFER(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN1, 
  REAL IN2, 
  REAL X);
// FUNCTION_BLOCK REAL_TO_FRAC
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,X)
  __DECLARE_VAR(INT,N)
  __DECLARE_VAR(FRACTION,_REAL_TO_FRAC)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(DINT,TEMP)
  __DECLARE_VAR(BOOL,SIGN)
  __DECLARE_VAR(DINT,X_GERUNDET)
  __DECLARE_VAR(REAL,X_OHNE_NACHKOMMA)
  __DECLARE_VAR(DINT,NUMERATOR)
  __DECLARE_VAR(DINT,DENOMINATOR)
  __DECLARE_VAR(DINT,NUMERATOR_OLD)
  __DECLARE_VAR(DINT,DENOMINATOR_OLD)

} REAL_TO_FRAC;

void REAL_TO_FRAC_init__(REAL_TO_FRAC *data__, BOOL retain);
// Code part
void REAL_TO_FRAC_body__(REAL_TO_FRAC *data__);
// FUNCTION
DINT FIB(
  BOOL EN, 
  BOOL *__ENO, 
  INT X);
// FUNCTION
REAL BETA(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL Y);
// FUNCTION
DINT CEIL2(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
REAL AGDF(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
REAL COSH(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
BOOL EVEN(
  BOOL EN, 
  BOOL *__ENO, 
  DINT IN);
// FUNCTION
REAL ASINH(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
REAL MIN3(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN1, 
  REAL IN2, 
  REAL IN3);
// FUNCTION
REAL TANC(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
BOOL WINDOW2(
  BOOL EN, 
  BOOL *__ENO, 
  REAL LOW, 
  REAL IN, 
  REAL HIGH);
// FUNCTION
REAL INV(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
REAL TANH(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
REAL GAUSS(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL U, 
  REAL SI);
// FUNCTION
REAL RND(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  INT N);
// FUNCTION
REAL ATAN2(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL Y);
// FUNCTION
REAL HYPOT(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL Y);
// FUNCTION
REAL SQRTN(
  BOOL EN, 
  BOOL *__ENO);
// FUNCTION
REAL GDF(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
REAL ACOSH(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION
INT BINOM(
  BOOL EN, 
  BOOL *__ENO, 
  INT N, 
  INT K, 
  INT I);
// FUNCTION
INT DEC1(
  BOOL EN, 
  BOOL *__ENO, 
  INT X, 
  INT N);
// FUNCTION
DINT FACT(
  BOOL EN, 
  BOOL *__ENO, 
  INT X);
// FUNCTION
INT INC(
  BOOL EN, 
  BOOL *__ENO, 
  INT X, 
  INT _D, 
  INT M);
#endif //__POUS_H
