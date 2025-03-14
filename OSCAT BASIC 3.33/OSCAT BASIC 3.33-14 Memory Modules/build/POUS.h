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
INT INC1(
  BOOL EN, 
  BOOL *__ENO, 
  INT X, 
  INT N);
__DECLARE_ARRAY_TYPE(__ARRAY_OF_DWORD_16,DWORD,[16])
// FUNCTION_BLOCK STACK_16
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(DWORD,DIN)
  __DECLARE_VAR(BOOL,_E)
  __DECLARE_VAR(BOOL,RD)
  __DECLARE_VAR(BOOL,WD)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(DWORD,DOUT)
  __DECLARE_VAR(BOOL,EMPTY)
  __DECLARE_VAR(BOOL,FULL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,PT)
  __DECLARE_VAR(__ARRAY_OF_DWORD_16,STACK)

} STACK_16;

void STACK_16_init__(STACK_16 *data__, BOOL retain);
// Code part
void STACK_16_body__(STACK_16 *data__);
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
__DECLARE_ARRAY_TYPE(__ARRAY_OF_DWORD_32,DWORD,[32])
// FUNCTION_BLOCK FIFO_32
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(DWORD,DIN)
  __DECLARE_VAR(BOOL,_E)
  __DECLARE_VAR(BOOL,RD)
  __DECLARE_VAR(BOOL,WD)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(DWORD,DOUT)
  __DECLARE_VAR(BOOL,EMPTY)
  __DECLARE_VAR(BOOL,FULL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(__ARRAY_OF_DWORD_32,FIFO)
  __DECLARE_VAR(INT,PR)
  __DECLARE_VAR(INT,PW)

} FIFO_32;

void FIFO_32_init__(FIFO_32 *data__, BOOL retain);
// Code part
void FIFO_32_body__(FIFO_32 *data__);
// FUNCTION_BLOCK FIFO_16
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(DWORD,DIN)
  __DECLARE_VAR(BOOL,_E)
  __DECLARE_VAR(BOOL,RD)
  __DECLARE_VAR(BOOL,WD)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(DWORD,DOUT)
  __DECLARE_VAR(BOOL,EMPTY)
  __DECLARE_VAR(BOOL,FULL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(__ARRAY_OF_DWORD_16,FIFO)
  __DECLARE_VAR(INT,PR)
  __DECLARE_VAR(INT,PW)

} FIFO_16;

void FIFO_16_init__(FIFO_16 *data__, BOOL retain);
// Code part
void FIFO_16_body__(FIFO_16 *data__);
// FUNCTION_BLOCK STACK_32
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(DWORD,DIN)
  __DECLARE_VAR(BOOL,_E)
  __DECLARE_VAR(BOOL,RD)
  __DECLARE_VAR(BOOL,WD)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(DWORD,DOUT)
  __DECLARE_VAR(BOOL,EMPTY)
  __DECLARE_VAR(BOOL,FULL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,PT)
  __DECLARE_VAR(__ARRAY_OF_DWORD_32,STACK)

} STACK_32;

void STACK_32_init__(STACK_32 *data__, BOOL retain);
// Code part
void STACK_32_body__(STACK_32 *data__);
#endif //__POUS_H
