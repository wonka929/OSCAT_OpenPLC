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
// FUNCTION_BLOCK SHR_4UDE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,SET)
  __DECLARE_VAR(BOOL,D0)
  __DECLARE_VAR(BOOL,D3)
  __DECLARE_VAR(BOOL,CLK)
  __DECLARE_VAR(BOOL,DN)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(BOOL,Q0)
  __DECLARE_VAR(BOOL,Q1)
  __DECLARE_VAR(BOOL,Q2)
  __DECLARE_VAR(BOOL,Q3)

  // FB private variables - TEMP, private and located variables
  R_TRIG TRIG;

} SHR_4UDE;

void SHR_4UDE_init__(SHR_4UDE *data__, BOOL retain);
// Code part
void SHR_4UDE_body__(SHR_4UDE *data__);
// FUNCTION_BLOCK SHR_4E
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,SET)
  __DECLARE_VAR(BOOL,D0)
  __DECLARE_VAR(BOOL,CLK)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(BOOL,Q0)
  __DECLARE_VAR(BOOL,Q1)
  __DECLARE_VAR(BOOL,Q2)
  __DECLARE_VAR(BOOL,Q3)

  // FB private variables - TEMP, private and located variables
  R_TRIG TRIG;

} SHR_4E;

void SHR_4E_init__(SHR_4E *data__, BOOL retain);
// Code part
void SHR_4E_body__(SHR_4E *data__);
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
BYTE BIT_LOAD_B(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE IN, 
  BOOL VAL, 
  INT POS);
// FUNCTION_BLOCK COUNT_DR
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,SET)
  __DECLARE_VAR(DWORD,IN)
  __DECLARE_VAR(BOOL,UP)
  __DECLARE_VAR(BOOL,DN)
  __DECLARE_VAR(DWORD,_STEP)
  __DECLARE_VAR(DWORD,MX)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(DWORD,CNT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(UDINT,CNT2)
  __DECLARE_VAR(UDINT,STEP2)
  __DECLARE_VAR(UDINT,MX2)
  __DECLARE_VAR(BOOL,LAST_UP)
  __DECLARE_VAR(BOOL,LAST_DN)

} COUNT_DR;

void COUNT_DR_init__(COUNT_DR *data__, BOOL retain);
// Code part
void COUNT_DR_body__(COUNT_DR *data__);
// FUNCTION
BOOL BIT_OF_DWORD(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN, 
  INT N);
// FUNCTION_BLOCK SHR_8PLE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,DIN)
  __DECLARE_VAR(BYTE,DLOAD)
  __DECLARE_VAR(BOOL,CLK)
  __DECLARE_VAR(BOOL,UP)
  __DECLARE_VAR(BOOL,LOAD)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(BOOL,DOUT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,EDGE)
  __DECLARE_VAR(BYTE,REGISTER)

} SHR_8PLE;

void SHR_8PLE_init__(SHR_8PLE *data__, BOOL retain);
// Code part
void SHR_8PLE_body__(SHR_8PLE *data__);
// FUNCTION_BLOCK FF_DRE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,SET)
  __DECLARE_VAR(BOOL,DI)
  __DECLARE_VAR(BOOL,CLK)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,EDGE)

} FF_DRE;

void FF_DRE_init__(FF_DRE *data__, BOOL retain);
// Code part
void FF_DRE_body__(FF_DRE *data__);
// FUNCTION
INT _BYTE_TO_INT(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE IN);
// FUNCTION
INT INC(
  BOOL EN, 
  BOOL *__ENO, 
  INT X, 
  INT _D, 
  INT M);
// FUNCTION_BLOCK COUNT_BR
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,SET)
  __DECLARE_VAR(BYTE,IN)
  __DECLARE_VAR(BOOL,UP)
  __DECLARE_VAR(BOOL,DN)
  __DECLARE_VAR(BYTE,_STEP)
  __DECLARE_VAR(BYTE,MX)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(BYTE,CNT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,LAST_UP)
  __DECLARE_VAR(BOOL,LAST_DN)

} COUNT_BR;

void COUNT_BR_init__(COUNT_BR *data__, BOOL retain);
// Code part
void COUNT_BR_body__(COUNT_BR *data__);
// FUNCTION_BLOCK FF_JKE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,SET)
  __DECLARE_VAR(BOOL,J)
  __DECLARE_VAR(BOOL,CLK)
  __DECLARE_VAR(BOOL,K)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,EDGE)

} FF_JKE;

void FF_JKE_init__(FF_JKE *data__, BOOL retain);
// Code part
void FF_JKE_body__(FF_JKE *data__);
// FUNCTION_BLOCK SELECT_8
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,EI)
  __DECLARE_VAR(BOOL,SET)
  __DECLARE_VAR(BYTE,IN)
  __DECLARE_VAR(BOOL,UP)
  __DECLARE_VAR(BOOL,DN)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(BOOL,Q0)
  __DECLARE_VAR(BOOL,Q1)
  __DECLARE_VAR(BOOL,Q2)
  __DECLARE_VAR(BOOL,Q3)
  __DECLARE_VAR(BOOL,Q4)
  __DECLARE_VAR(BOOL,Q5)
  __DECLARE_VAR(BOOL,Q6)
  __DECLARE_VAR(BOOL,Q7)
  __DECLARE_VAR(INT,STATE)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,LAST_UP)
  __DECLARE_VAR(BOOL,LAST_DN)

} SELECT_8;

void SELECT_8_init__(SELECT_8 *data__, BOOL retain);
// Code part
void SELECT_8_body__(SELECT_8 *data__);
// FUNCTION_BLOCK TOGGLE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,CLK)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,EDGE)

} TOGGLE;

void TOGGLE_init__(TOGGLE *data__, BOOL retain);
// Code part
void TOGGLE_body__(TOGGLE *data__);
// FUNCTION_BLOCK LTCH
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,DI)
  __DECLARE_VAR(BOOL,L)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables

} LTCH;

void LTCH_init__(LTCH *data__, BOOL retain);
// Code part
void LTCH_body__(LTCH *data__);
// FUNCTION_BLOCK FF_RSE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,CS)
  __DECLARE_VAR(BOOL,CR)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,ES)
  __DECLARE_VAR(BOOL,ER)

} FF_RSE;

void FF_RSE_init__(FF_RSE *data__, BOOL retain);
// Code part
void FF_RSE_body__(FF_RSE *data__);
// FUNCTION_BLOCK LTCH_4
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,D0)
  __DECLARE_VAR(BOOL,D1)
  __DECLARE_VAR(BOOL,D2)
  __DECLARE_VAR(BOOL,D3)
  __DECLARE_VAR(BOOL,L)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(BOOL,Q0)
  __DECLARE_VAR(BOOL,Q1)
  __DECLARE_VAR(BOOL,Q2)
  __DECLARE_VAR(BOOL,Q3)

  // FB private variables - TEMP, private and located variables

} LTCH_4;

void LTCH_4_init__(LTCH_4 *data__, BOOL retain);
// Code part
void LTCH_4_body__(LTCH_4 *data__);
// FUNCTION_BLOCK STORE_8
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,SET)
  __DECLARE_VAR(BOOL,D0)
  __DECLARE_VAR(BOOL,D1)
  __DECLARE_VAR(BOOL,D2)
  __DECLARE_VAR(BOOL,D3)
  __DECLARE_VAR(BOOL,D4)
  __DECLARE_VAR(BOOL,D5)
  __DECLARE_VAR(BOOL,D6)
  __DECLARE_VAR(BOOL,D7)
  __DECLARE_VAR(BOOL,CLR)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(BOOL,Q0)
  __DECLARE_VAR(BOOL,Q1)
  __DECLARE_VAR(BOOL,Q2)
  __DECLARE_VAR(BOOL,Q3)
  __DECLARE_VAR(BOOL,Q4)
  __DECLARE_VAR(BOOL,Q5)
  __DECLARE_VAR(BOOL,Q6)
  __DECLARE_VAR(BOOL,Q7)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,EDGE)

} STORE_8;

void STORE_8_init__(STORE_8 *data__, BOOL retain);
// Code part
void STORE_8_body__(STORE_8 *data__);
// FUNCTION_BLOCK FF_D4E
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,D0)
  __DECLARE_VAR(BOOL,D1)
  __DECLARE_VAR(BOOL,D2)
  __DECLARE_VAR(BOOL,D3)
  __DECLARE_VAR(BOOL,CLK)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(BOOL,Q0)
  __DECLARE_VAR(BOOL,Q1)
  __DECLARE_VAR(BOOL,Q2)
  __DECLARE_VAR(BOOL,Q3)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,EDGE)

} FF_D4E;

void FF_D4E_init__(FF_D4E *data__, BOOL retain);
// Code part
void FF_D4E_body__(FF_D4E *data__);
#endif //__POUS_H
