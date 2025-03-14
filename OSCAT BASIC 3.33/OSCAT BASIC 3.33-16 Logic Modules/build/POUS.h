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
BOOL BIT_OF_DWORD(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN, 
  INT N);
// FUNCTION
BOOL PARITY(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN);
// FUNCTION
BYTE REVERSE(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE IN);
// FUNCTION
WORD WORD_OF_BYTE(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE B0, 
  BYTE B1);
// FUNCTION
BYTE GRAY_TO_BYTE(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE IN);
// FUNCTION
INT _BYTE_TO_INT(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE IN);
// FUNCTION
BYTE BYTE_OF_DWORD(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN, 
  BYTE N);
// FUNCTION
WORD BIT_LOAD_W2(
  BOOL EN, 
  BOOL *__ENO, 
  WORD I, 
  BOOL _D, 
  INT P, 
  INT N);
// FUNCTION
BYTE INT_TO_BCDC(
  BOOL EN, 
  BOOL *__ENO, 
  INT IN);
// FUNCTION
WORD WORD_OF_DWORD(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN, 
  BYTE N);
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
// FUNCTION
BOOL MUX_2(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL D0, 
  BOOL D1, 
  BOOL A0);
// FUNCTION
BYTE BYTE_OF_BIT(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL B0, 
  BOOL B1, 
  BOOL B2, 
  BOOL B3, 
  BOOL B4, 
  BOOL B5, 
  BOOL B6, 
  BOOL B7);
// FUNCTION
BOOL MUX_4(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL D0, 
  BOOL D1, 
  BOOL D2, 
  BOOL D3, 
  BOOL A0, 
  BOOL A1);
// FUNCTION
WORD BIT_LOAD_W(
  BOOL EN, 
  BOOL *__ENO, 
  WORD IN, 
  BOOL VAL, 
  INT POS);
// FUNCTION
BOOL DEC_2(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL DI, 
  BOOL A, 
  BOOL *__Q0, 
  BOOL *__Q1);
// FUNCTION
BOOL DEC_4(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL DI, 
  BOOL A0, 
  BOOL A1, 
  BOOL *__Q0, 
  BOOL *__Q1, 
  BOOL *__Q2, 
  BOOL *__Q3);
// FUNCTION
DWORD SHR1(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN, 
  INT N);
// FUNCTION
BOOL DEC_8(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL DI, 
  BOOL A0, 
  BOOL A1, 
  BOOL A2, 
  BOOL *__Q0, 
  BOOL *__Q1, 
  BOOL *__Q2, 
  BOOL *__Q3, 
  BOOL *__Q4, 
  BOOL *__Q5, 
  BOOL *__Q6, 
  BOOL *__Q7);
// FUNCTION
DWORD DWORD_OF_BYTE(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE B0, 
  BYTE B1, 
  BYTE B2, 
  BYTE B3);
// FUNCTION
BOOL BYTE_TO_BITS(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL *__B0, 
  BOOL *__B1, 
  BOOL *__B2, 
  BOOL *__B3, 
  BOOL *__B4, 
  BOOL *__B5, 
  BOOL *__B6, 
  BOOL *__B7);
// FUNCTION
BYTE BYTE_TO_GRAY(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE IN);
// FUNCTION
DWORD BIT_TOGGLE_DW(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN, 
  INT POS);
// FUNCTION
DWORD SWAP_BYTE2(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN);
// FUNCTION
DWORD REFLECT(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD DI, 
  INT L);
__DECLARE_ARRAY_TYPE(__ARRAY_OF_BYTE_250,BYTE,[250])
// FUNCTION_BLOCK CRC_GEN
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(__ARRAY_OF_BYTE_250,PT)
  __DECLARE_VAR(UINT,SIZE)
  __DECLARE_VAR(UINT,PL)
  __DECLARE_VAR(DWORD,PN)
  __DECLARE_VAR(DWORD,INIT)
  __DECLARE_VAR(BOOL,REV_IN)
  __DECLARE_VAR(BOOL,REV_OUT)
  __DECLARE_VAR(DWORD,XOR_OUT)
  __DECLARE_VAR(DWORD,_CRC_GEN)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,POS)
  __DECLARE_VAR(INT,SHIFT)
  __DECLARE_VAR(INT,BITS)
  __DECLARE_VAR(BYTE,DX)

} CRC_GEN;

void CRC_GEN_init__(CRC_GEN *data__, BOOL retain);
// Code part
void CRC_GEN_body__(CRC_GEN *data__);
__DECLARE_ARRAY_TYPE(__ARRAY_OF_BYTE_4,BYTE,[4])
// FUNCTION_BLOCK MATRIX
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,X1)
  __DECLARE_VAR(BOOL,X2)
  __DECLARE_VAR(BOOL,X3)
  __DECLARE_VAR(BOOL,X4)
  __DECLARE_VAR(BOOL,X5)
  __DECLARE_VAR(BOOL,RELEASE)
  __DECLARE_VAR(BYTE,CODE)
  __DECLARE_VAR(BOOL,_TP)
  __DECLARE_VAR(BOOL,Y1)
  __DECLARE_VAR(BOOL,Y2)
  __DECLARE_VAR(BOOL,Y3)
  __DECLARE_VAR(BOOL,Y4)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BYTE,LINE)
  __DECLARE_VAR(__ARRAY_OF_BYTE_4,X)
  __DECLARE_VAR(__ARRAY_OF_BYTE_4,L)
  __DECLARE_VAR(INT,I)
  __DECLARE_VAR(BYTE,TEMP)
  __DECLARE_VAR(BYTE,TEMP2)
  __DECLARE_VAR(BYTE,L_TEMP)
  __DECLARE_VAR(BOOL,TEMP_BIT)
  __DECLARE_VAR(INT,IN_TEMP)

} MATRIX;

void MATRIX_init__(MATRIX *data__, BOOL retain);
// Code part
void MATRIX_body__(MATRIX *data__);
// FUNCTION
BOOL CHECK_PARITY(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN, 
  BOOL P);
// FUNCTION
DWORD DWORD_OF_WORD(
  BOOL EN, 
  BOOL *__ENO, 
  WORD W0, 
  WORD W1);
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
// FUNCTION
WORD BIT_TOGGLE_W(
  BOOL EN, 
  BOOL *__ENO, 
  WORD IN, 
  INT POS);
// FUNCTION
DWORD SHL1(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN, 
  INT N);
// FUNCTION
WORD SWAP_BYTE(
  BOOL EN, 
  BOOL *__ENO, 
  WORD IN);
// FUNCTION
BYTE BIT_LOAD_B2(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE I, 
  BOOL _D, 
  INT P, 
  INT N);
// FUNCTION
INT BCDC_TO_INT(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE IN);
// FUNCTION
DWORD BIT_LOAD_DW2(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD I, 
  BOOL _D, 
  INT P, 
  INT N);
// FUNCTION
BYTE BIT_TOGGLE_B(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE IN, 
  INT POS);
#endif //__POUS_H
