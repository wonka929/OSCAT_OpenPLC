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
REAL KMH_TO_MS(
  BOOL EN, 
  BOOL *__ENO, 
  REAL KMH);
// FUNCTION
REAL BFT_TO_MS(
  BOOL EN, 
  BOOL *__ENO, 
  INT BFT);
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
REAL C_TO_K(
  BOOL EN, 
  BOOL *__ENO, 
  REAL CELSIUS);
// FUNCTION
TIME F_TO_PT(
  BOOL EN, 
  BOOL *__ENO, 
  REAL F);
// FUNCTION_BLOCK PRESSURE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,MWS)
  __DECLARE_VAR(REAL,TORR)
  __DECLARE_VAR(REAL,ATT)
  __DECLARE_VAR(REAL,ATM)
  __DECLARE_VAR(REAL,PA)
  __DECLARE_VAR(REAL,BAR)
  __DECLARE_VAR(REAL,YMWS)
  __DECLARE_VAR(REAL,YTORR)
  __DECLARE_VAR(REAL,YATT)
  __DECLARE_VAR(REAL,YATM)
  __DECLARE_VAR(REAL,YPA)
  __DECLARE_VAR(REAL,YBAR)

  // FB private variables - TEMP, private and located variables

} PRESSURE;

void PRESSURE_init__(PRESSURE *data__, BOOL retain);
// Code part
void PRESSURE_body__(PRESSURE *data__);
// FUNCTION
REAL C_TO_F(
  BOOL EN, 
  BOOL *__ENO, 
  REAL CELSIUS);
// FUNCTION_BLOCK ENERGY
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,J)
  __DECLARE_VAR(REAL,C)
  __DECLARE_VAR(REAL,WH)
  __DECLARE_VAR(REAL,YJ)
  __DECLARE_VAR(REAL,YC)
  __DECLARE_VAR(REAL,YWH)

  // FB private variables - TEMP, private and located variables

} ENERGY;

void ENERGY_init__(ENERGY *data__, BOOL retain);
// Code part
void ENERGY_body__(ENERGY *data__);
// FUNCTION
REAL F_TO_OM(
  BOOL EN, 
  BOOL *__ENO, 
  REAL F);
// FUNCTION_BLOCK ASTRO
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,M)
  __DECLARE_VAR(REAL,AE)
  __DECLARE_VAR(REAL,PC)
  __DECLARE_VAR(REAL,LJ)
  __DECLARE_VAR(REAL,YM)
  __DECLARE_VAR(REAL,YAE)
  __DECLARE_VAR(REAL,YPC)
  __DECLARE_VAR(REAL,YLJ)

  // FB private variables - TEMP, private and located variables

} ASTRO;

void ASTRO_init__(ASTRO *data__, BOOL retain);
// Code part
void ASTRO_body__(ASTRO *data__);
// FUNCTION_BLOCK LENGTH
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,M)
  __DECLARE_VAR(REAL,P)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(REAL,FT)
  __DECLARE_VAR(REAL,YD)
  __DECLARE_VAR(REAL,MILE)
  __DECLARE_VAR(REAL,SM)
  __DECLARE_VAR(REAL,FM)
  __DECLARE_VAR(REAL,YM)
  __DECLARE_VAR(REAL,YP)
  __DECLARE_VAR(REAL,YIN)
  __DECLARE_VAR(REAL,YFT)
  __DECLARE_VAR(REAL,YYD)
  __DECLARE_VAR(REAL,YMILE)
  __DECLARE_VAR(REAL,YSM)
  __DECLARE_VAR(REAL,YFM)

  // FB private variables - TEMP, private and located variables

} LENGTH;

void LENGTH_init__(LENGTH *data__, BOOL retain);
// Code part
void LENGTH_body__(LENGTH *data__);
// FUNCTION
REAL F_TO_C(
  BOOL EN, 
  BOOL *__ENO, 
  REAL FAHRENHEIT);
// FUNCTION
REAL MS_TO_KMH(
  BOOL EN, 
  BOOL *__ENO, 
  REAL MS);
// FUNCTION
REAL K_TO_C(
  BOOL EN, 
  BOOL *__ENO, 
  REAL KELVIN);
// FUNCTION
REAL OM_TO_F(
  BOOL EN, 
  BOOL *__ENO, 
  REAL OM);
// FUNCTION
INT MS_TO_BFT(
  BOOL EN, 
  BOOL *__ENO, 
  REAL MS);
// FUNCTION
REAL PT_TO_F(
  BOOL EN, 
  BOOL *__ENO, 
  TIME PT);
// FUNCTION_BLOCK SPEED
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,MS)
  __DECLARE_VAR(REAL,KMH)
  __DECLARE_VAR(REAL,KN)
  __DECLARE_VAR(REAL,MH)
  __DECLARE_VAR(REAL,YMS)
  __DECLARE_VAR(REAL,YKMH)
  __DECLARE_VAR(REAL,YKN)
  __DECLARE_VAR(REAL,YMH)

  // FB private variables - TEMP, private and located variables

} SPEED;

void SPEED_init__(SPEED *data__, BOOL retain);
// Code part
void SPEED_body__(SPEED *data__);
// FUNCTION
REAL GEO_TO_DEG(
  BOOL EN, 
  BOOL *__ENO, 
  INT _D, 
  INT M, 
  REAL SEC);
// FUNCTION_BLOCK TEMPERATURE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,K)
  __DECLARE_VAR(REAL,C)
  __DECLARE_VAR(REAL,F)
  __DECLARE_VAR(REAL,RE)
  __DECLARE_VAR(REAL,RA)
  __DECLARE_VAR(REAL,YK)
  __DECLARE_VAR(REAL,YC)
  __DECLARE_VAR(REAL,YF)
  __DECLARE_VAR(REAL,YRE)
  __DECLARE_VAR(REAL,YRA)

  // FB private variables - TEMP, private and located variables

} TEMPERATURE;

void TEMPERATURE_init__(TEMPERATURE *data__, BOOL retain);
// Code part
void TEMPERATURE_body__(TEMPERATURE *data__);
#endif //__POUS_H
