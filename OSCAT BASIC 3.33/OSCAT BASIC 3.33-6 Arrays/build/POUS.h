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
// FUNCTION_BLOCK RDM2
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(INT,LAST)
  __DECLARE_VAR(INT,LOW)
  __DECLARE_VAR(INT,HIGH)
  __DECLARE_VAR(INT,_RDM2)

  // FB private variables - TEMP, private and located variables
  RDM _RDM;

} RDM2;

void RDM2_init__(RDM2 *data__, BOOL retain);
// Code part
void RDM2_body__(RDM2 *data__);
__DECLARE_ARRAY_TYPE(__ARRAY_OF_REAL_100,REAL,[100])
// FUNCTION_BLOCK _ARRAY_SHUFFLE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(__ARRAY_OF_REAL_100,PT)
  __DECLARE_VAR(UINT,SIZE)
  __DECLARE_VAR(BOOL,_ARRAY_SHUFFLE_Q)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,TEMP)
  __DECLARE_VAR(INT,POS)
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(INT,STOP)
  RDM2 _RDM2;

} _ARRAY_SHUFFLE;

void _ARRAY_SHUFFLE_init__(_ARRAY_SHUFFLE *data__, BOOL retain);
// Code part
void _ARRAY_SHUFFLE_body__(_ARRAY_SHUFFLE *data__);
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
// FUNCTION_BLOCK _ARRAY_ABS
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(__ARRAY_OF_REAL_100,PT)
  __DECLARE_VAR(UINT,SIZE)
  __DECLARE_VAR(BOOL,_ARRAY_ABS_Q)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(INT,STOP)

} _ARRAY_ABS;

void _ARRAY_ABS_init__(_ARRAY_ABS *data__, BOOL retain);
// Code part
void _ARRAY_ABS_body__(_ARRAY_ABS *data__);
// FUNCTION_BLOCK ARRAY_AVG
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(__ARRAY_OF_REAL_100,PT)
  __DECLARE_VAR(UINT,SIZE)
  __DECLARE_VAR(REAL,_ARRAY_AVG)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(INT,STOP)

} ARRAY_AVG;

void ARRAY_AVG_init__(ARRAY_AVG *data__, BOOL retain);
// Code part
void ARRAY_AVG_body__(ARRAY_AVG *data__);
// FUNCTION
BOOL EVEN(
  BOOL EN, 
  BOOL *__ENO, 
  DINT IN);
// FUNCTION_BLOCK ARRAY_TREND
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(__ARRAY_OF_REAL_100,PT)
  __DECLARE_VAR(UINT,SIZE)
  __DECLARE_VAR(REAL,_ARRAY_TREND)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(INT,STOP)
  __DECLARE_VAR(INT,STOP2)
  __DECLARE_VAR(INT,_D)
  __DECLARE_VAR(REAL,X)

} ARRAY_TREND;

void ARRAY_TREND_init__(ARRAY_TREND *data__, BOOL retain);
// Code part
void ARRAY_TREND_body__(ARRAY_TREND *data__);
// FUNCTION_BLOCK IS_SORTED
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(__ARRAY_OF_REAL_100,PT)
  __DECLARE_VAR(UINT,SIZE)
  __DECLARE_VAR(BOOL,_IS_SORTED)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(INT,I2)
  __DECLARE_VAR(INT,STOP)

} IS_SORTED;

void IS_SORTED_init__(IS_SORTED *data__, BOOL retain);
// Code part
void IS_SORTED_body__(IS_SORTED *data__);
// FUNCTION_BLOCK ARRAY_SPR
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(__ARRAY_OF_REAL_100,PT)
  __DECLARE_VAR(UINT,SIZE)
  __DECLARE_VAR(REAL,_ARRAY_SPR)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(INT,STOP)
  __DECLARE_VAR(REAL,ARR_MAX)
  __DECLARE_VAR(REAL,ARR_MIN)

} ARRAY_SPR;

void ARRAY_SPR_init__(ARRAY_SPR *data__, BOOL retain);
// Code part
void ARRAY_SPR_body__(ARRAY_SPR *data__);
// FUNCTION_BLOCK _ARRAY_ADD
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(__ARRAY_OF_REAL_100,PT)
  __DECLARE_VAR(UINT,SIZE)
  __DECLARE_VAR(REAL,X)
  __DECLARE_VAR(BOOL,_ARRAY_ADD_Q)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(INT,STOP)

} _ARRAY_ADD;

void _ARRAY_ADD_init__(_ARRAY_ADD *data__, BOOL retain);
// Code part
void _ARRAY_ADD_body__(_ARRAY_ADD *data__);
__DECLARE_ARRAY_TYPE(__ARRAY_OF_INT_32,INT,[32])
// FUNCTION_BLOCK _ARRAY_SORT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(__ARRAY_OF_REAL_100,PT)
  __DECLARE_VAR(UINT,SIZE)
  __DECLARE_VAR(BOOL,_ARRAY_SORT_Q)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,STACK_COUNT)
  __DECLARE_VAR(__ARRAY_OF_INT_32,STACK)
  __DECLARE_VAR(INT,LINKS)
  __DECLARE_VAR(INT,RECHTS)
  __DECLARE_VAR(REAL,PIVOT)
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(INT,J)
  __DECLARE_VAR(BOOL,ENDE_INNEN)
  __DECLARE_VAR(BOOL,ENDE_AUSSEN)
  __DECLARE_VAR(REAL,TMP)
  __DECLARE_VAR(INT,X)

} _ARRAY_SORT;

void _ARRAY_SORT_init__(_ARRAY_SORT *data__, BOOL retain);
// Code part
void _ARRAY_SORT_body__(_ARRAY_SORT *data__);
// FUNCTION_BLOCK _ARRAY_MEDIAN
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(__ARRAY_OF_REAL_100,PT)
  __DECLARE_VAR(UINT,SIZE)
  __DECLARE_VAR(REAL,_ARRAY_MEDIAN_Q)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(INT,I2)
  __DECLARE_VAR(INT,STOP)
  _ARRAY_SORT _ARRAY_SORT_MED;

} _ARRAY_MEDIAN;

void _ARRAY_MEDIAN_init__(_ARRAY_MEDIAN *data__, BOOL retain);
// Code part
void _ARRAY_MEDIAN_body__(_ARRAY_MEDIAN *data__);
// FUNCTION_BLOCK _ARRAY_MUL
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(__ARRAY_OF_REAL_100,PT)
  __DECLARE_VAR(UINT,SIZE)
  __DECLARE_VAR(REAL,X)
  __DECLARE_VAR(BOOL,_ARRAY_MUL_Q)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(INT,STOP)

} _ARRAY_MUL;

void _ARRAY_MUL_init__(_ARRAY_MUL *data__, BOOL retain);
// Code part
void _ARRAY_MUL_body__(_ARRAY_MUL *data__);
// FUNCTION_BLOCK ARRAY_VAR
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(__ARRAY_OF_REAL_100,PT)
  __DECLARE_VAR(UINT,SIZE)
  __DECLARE_VAR(REAL,_ARRAY_VAR)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(INT,STOP)
  __DECLARE_VAR(REAL,AVG)

} ARRAY_VAR;

void ARRAY_VAR_init__(ARRAY_VAR *data__, BOOL retain);
// Code part
void ARRAY_VAR_body__(ARRAY_VAR *data__);
// FUNCTION_BLOCK ARRAY_SDV
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(__ARRAY_OF_REAL_100,PT)
  __DECLARE_VAR(UINT,SIZE)
  __DECLARE_VAR(REAL,_ARRAY_SDV)

  // FB private variables - TEMP, private and located variables
  ARRAY_VAR FB_ARRAY_VAR;

} ARRAY_SDV;

void ARRAY_SDV_init__(ARRAY_SDV *data__, BOOL retain);
// Code part
void ARRAY_SDV_body__(ARRAY_SDV *data__);
// FUNCTION_BLOCK ARRAY_MAX
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(__ARRAY_OF_REAL_100,PT)
  __DECLARE_VAR(UINT,SIZE)
  __DECLARE_VAR(REAL,_ARRAY_MAX)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(INT,STOP)

} ARRAY_MAX;

void ARRAY_MAX_init__(ARRAY_MAX *data__, BOOL retain);
// Code part
void ARRAY_MAX_body__(ARRAY_MAX *data__);
// FUNCTION_BLOCK _ARRAY_INIT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(__ARRAY_OF_REAL_100,PT)
  __DECLARE_VAR(UINT,SIZE)
  __DECLARE_VAR(REAL,INIT)
  __DECLARE_VAR(BOOL,_ARRAY_INIT_Q)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(INT,STOP)

} _ARRAY_INIT;

void _ARRAY_INIT_init__(_ARRAY_INIT *data__, BOOL retain);
// Code part
void _ARRAY_INIT_body__(_ARRAY_INIT *data__);
// FUNCTION_BLOCK ARRAY_SUM
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(__ARRAY_OF_REAL_100,PT)
  __DECLARE_VAR(UINT,SIZE)
  __DECLARE_VAR(REAL,_ARRAY_SUM)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(INT,STOP)

} ARRAY_SUM;

void ARRAY_SUM_init__(ARRAY_SUM *data__, BOOL retain);
// Code part
void ARRAY_SUM_body__(ARRAY_SUM *data__);
// FUNCTION_BLOCK ARRAY_MIN
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(__ARRAY_OF_REAL_100,PT)
  __DECLARE_VAR(UINT,SIZE)
  __DECLARE_VAR(REAL,_ARRAY_MIN)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(INT,STOP)

} ARRAY_MIN;

void ARRAY_MIN_init__(ARRAY_MIN *data__, BOOL retain);
// Code part
void ARRAY_MIN_body__(ARRAY_MIN *data__);
// FUNCTION
REAL SQRTN(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  INT N);
// FUNCTION_BLOCK ARRAY_GAV
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(__ARRAY_OF_REAL_100,PT)
  __DECLARE_VAR(UINT,SIZE)
  __DECLARE_VAR(REAL,_ARRAY_GAV)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(INT,STOP)

} ARRAY_GAV;

void ARRAY_GAV_init__(ARRAY_GAV *data__, BOOL retain);
// Code part
void ARRAY_GAV_body__(ARRAY_GAV *data__);
// FUNCTION_BLOCK ARRAY_HAV
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(__ARRAY_OF_REAL_100,PT)
  __DECLARE_VAR(UINT,SIZE)
  __DECLARE_VAR(REAL,_ARRAY_HAV)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(INT,STOP)

} ARRAY_HAV;

void ARRAY_HAV_init__(ARRAY_HAV *data__, BOOL retain);
// Code part
void ARRAY_HAV_body__(ARRAY_HAV *data__);
#endif //__POUS_H
