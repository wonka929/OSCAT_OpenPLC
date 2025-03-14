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
__DECLARE_STRUCT_TYPE(OSCAT_COMPLEX,
  REAL RE;
    REAL IM;
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
// FUNCTION_BLOCK CLOG
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(OSCAT_COMPLEX,X)
  __DECLARE_VAR(OSCAT_COMPLEX,_CLOG)

  // FB private variables - TEMP, private and located variables

} CLOG;

void CLOG_init__(CLOG *data__, BOOL retain);
// Code part
void CLOG_body__(CLOG *data__);
// FUNCTION
REAL COSH(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION_BLOCK CADD
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(OSCAT_COMPLEX,X)
  __DECLARE_VAR(OSCAT_COMPLEX,Y)
  __DECLARE_VAR(OSCAT_COMPLEX,_CADD)

  // FB private variables - TEMP, private and located variables

} CADD;

void CADD_init__(CADD *data__, BOOL retain);
// Code part
void CADD_body__(CADD *data__);
// FUNCTION
REAL SINH(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION_BLOCK CSUB
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(OSCAT_COMPLEX,X)
  __DECLARE_VAR(OSCAT_COMPLEX,Y)
  __DECLARE_VAR(OSCAT_COMPLEX,_CSUB)

  // FB private variables - TEMP, private and located variables

} CSUB;

void CSUB_init__(CSUB *data__, BOOL retain);
// Code part
void CSUB_body__(CSUB *data__);
// FUNCTION_BLOCK CDIV
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(OSCAT_COMPLEX,X)
  __DECLARE_VAR(OSCAT_COMPLEX,Y)
  __DECLARE_VAR(OSCAT_COMPLEX,_CDIV)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,TEMP)

} CDIV;

void CDIV_init__(CDIV *data__, BOOL retain);
// Code part
void CDIV_body__(CDIV *data__);
// FUNCTION_BLOCK CABS
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(OSCAT_COMPLEX,X)
  __DECLARE_VAR(REAL,_CABS)

  // FB private variables - TEMP, private and located variables

} CABS;

void CABS_init__(CABS *data__, BOOL retain);
// Code part
void CABS_body__(CABS *data__);
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
// FUNCTION_BLOCK CCOSH
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(OSCAT_COMPLEX,X)
  __DECLARE_VAR(OSCAT_COMPLEX,_CCOSH)

  // FB private variables - TEMP, private and located variables

} CCOSH;

void CCOSH_init__(CCOSH *data__, BOOL retain);
// Code part
void CCOSH_body__(CCOSH *data__);
// FUNCTION
INT SGN(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X);
// FUNCTION_BLOCK CSQRT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(OSCAT_COMPLEX,X)
  __DECLARE_VAR(OSCAT_COMPLEX,_CSQRT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,TEMP)

} CSQRT;

void CSQRT_init__(CSQRT *data__, BOOL retain);
// Code part
void CSQRT_body__(CSQRT *data__);
// FUNCTION_BLOCK CASINH
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(OSCAT_COMPLEX,X)
  __DECLARE_VAR(OSCAT_COMPLEX,_CASINH)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(OSCAT_COMPLEX,Y)
  CLOG _CLOG;
  CSQRT _CSQRT;

} CASINH;

void CASINH_init__(CASINH *data__, BOOL retain);
// Code part
void CASINH_body__(CASINH *data__);
// FUNCTION_BLOCK CASIN
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(OSCAT_COMPLEX,X)
  __DECLARE_VAR(OSCAT_COMPLEX,_CASIN)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(OSCAT_COMPLEX,Y)
  CASINH _CASINH;

} CASIN;

void CASIN_init__(CASIN *data__, BOOL retain);
// Code part
void CASIN_body__(CASIN *data__);
// FUNCTION_BLOCK CCON
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(OSCAT_COMPLEX,X)
  __DECLARE_VAR(OSCAT_COMPLEX,_CCON)

  // FB private variables - TEMP, private and located variables

} CCON;

void CCON_init__(CCON *data__, BOOL retain);
// Code part
void CCON_body__(CCON *data__);
// FUNCTION_BLOCK CMUL
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(OSCAT_COMPLEX,X)
  __DECLARE_VAR(OSCAT_COMPLEX,Y)
  __DECLARE_VAR(OSCAT_COMPLEX,_CMUL)

  // FB private variables - TEMP, private and located variables

} CMUL;

void CMUL_init__(CMUL *data__, BOOL retain);
// Code part
void CMUL_body__(CMUL *data__);
// FUNCTION_BLOCK CPOL
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,L)
  __DECLARE_VAR(REAL,A)
  __DECLARE_VAR(OSCAT_COMPLEX,_CPOL)

  // FB private variables - TEMP, private and located variables

} CPOL;

void CPOL_init__(CPOL *data__, BOOL retain);
// Code part
void CPOL_body__(CPOL *data__);
// FUNCTION_BLOCK CACOSH
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(OSCAT_COMPLEX,X)
  __DECLARE_VAR(OSCAT_COMPLEX,_CACOSH)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(OSCAT_COMPLEX,Y)
  CLOG _CLOG;
  CSQRT _CSQRT;

} CACOSH;

void CACOSH_init__(CACOSH *data__, BOOL retain);
// Code part
void CACOSH_body__(CACOSH *data__);
// FUNCTION_BLOCK CACOS
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(OSCAT_COMPLEX,X)
  __DECLARE_VAR(OSCAT_COMPLEX,_CACOS)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(OSCAT_COMPLEX,Y)
  CACOSH _CACOSH;

} CACOS;

void CACOS_init__(CACOS *data__, BOOL retain);
// Code part
void CACOS_body__(CACOS *data__);
// FUNCTION_BLOCK CATAN
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(OSCAT_COMPLEX,X)
  __DECLARE_VAR(OSCAT_COMPLEX,_CATAN)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,R2)
  __DECLARE_VAR(REAL,NUM)
  __DECLARE_VAR(REAL,DEN)

} CATAN;

void CATAN_init__(CATAN *data__, BOOL retain);
// Code part
void CATAN_body__(CATAN *data__);
// FUNCTION_BLOCK CARG
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(OSCAT_COMPLEX,X)
  __DECLARE_VAR(REAL,_CARG)

  // FB private variables - TEMP, private and located variables

} CARG;

void CARG_init__(CARG *data__, BOOL retain);
// Code part
void CARG_body__(CARG *data__);
// FUNCTION_BLOCK CEXP
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(OSCAT_COMPLEX,X)
  __DECLARE_VAR(OSCAT_COMPLEX,_CEXP)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,TEMP)

} CEXP;

void CEXP_init__(CEXP *data__, BOOL retain);
// Code part
void CEXP_body__(CEXP *data__);
// FUNCTION_BLOCK CPOW
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(OSCAT_COMPLEX,X)
  __DECLARE_VAR(OSCAT_COMPLEX,Y)
  __DECLARE_VAR(OSCAT_COMPLEX,_CPOW)

  // FB private variables - TEMP, private and located variables
  CLOG _CLOG;
  CEXP _CEXP;
  CMUL _CMUL;

} CPOW;

void CPOW_init__(CPOW *data__, BOOL retain);
// Code part
void CPOW_body__(CPOW *data__);
// FUNCTION_BLOCK CATANH
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(OSCAT_COMPLEX,X)
  __DECLARE_VAR(OSCAT_COMPLEX,_CATANH)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,I2)
  __DECLARE_VAR(REAL,NUM)
  __DECLARE_VAR(REAL,DEN)

} CATANH;

void CATANH_init__(CATANH *data__, BOOL retain);
// Code part
void CATANH_body__(CATANH *data__);
// FUNCTION_BLOCK CSET
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,RE)
  __DECLARE_VAR(REAL,IM)
  __DECLARE_VAR(OSCAT_COMPLEX,_CSET)

  // FB private variables - TEMP, private and located variables

} CSET;

void CSET_init__(CSET *data__, BOOL retain);
// Code part
void CSET_body__(CSET *data__);
// FUNCTION_BLOCK CINV
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(OSCAT_COMPLEX,X)
  __DECLARE_VAR(OSCAT_COMPLEX,_CINV)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,TEMP)

} CINV;

void CINV_init__(CINV *data__, BOOL retain);
// Code part
void CINV_body__(CINV *data__);
// FUNCTION_BLOCK CCOS
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(OSCAT_COMPLEX,X)
  __DECLARE_VAR(OSCAT_COMPLEX,_CCOS)

  // FB private variables - TEMP, private and located variables
  CSET _CSET;
  CCOSH _CCOSH;

} CCOS;

void CCOS_init__(CCOS *data__, BOOL retain);
// Code part
void CCOS_body__(CCOS *data__);
#endif //__POUS_H
