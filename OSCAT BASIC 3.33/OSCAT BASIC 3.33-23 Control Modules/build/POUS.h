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
__DECLARE_STRUCT_TYPE(REAL2,
  REAL R1;
    REAL RX;
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
UDINT T_PLC_US(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL DEBUG);
// FUNCTION_BLOCK FT_PIWL
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(REAL,KP)
  __DECLARE_VAR(REAL,KI)
  __DECLARE_VAR(REAL,LIM_L)
  __DECLARE_VAR(REAL,LIM_H)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(REAL,Y)
  __DECLARE_VAR(BOOL,LIM)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(UDINT,TX)
  __DECLARE_VAR(REAL,TC)
  __DECLARE_VAR(UDINT,T_LAST)
  __DECLARE_VAR(REAL,IN_LAST)
  __DECLARE_VAR(REAL,I)
  __DECLARE_VAR(REAL,P)

} FT_PIWL;

void FT_PIWL_init__(FT_PIWL *data__, BOOL retain);
// Code part
void FT_PIWL_body__(FT_PIWL *data__);
// FUNCTION_BLOCK FT_DERIV
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(REAL,K)
  __DECLARE_VAR(BOOL,RUN)
  __DECLARE_VAR(REAL,OUT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,OLD)
  __DECLARE_VAR(UDINT,TX)
  __DECLARE_VAR(UDINT,LAST)
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(REAL,TC)

} FT_DERIV;

void FT_DERIV_init__(FT_DERIV *data__, BOOL retain);
// Code part
void FT_DERIV_body__(FT_DERIV *data__);
// FUNCTION_BLOCK FT_PIDWL
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(REAL,KP)
  __DECLARE_VAR(REAL,TN)
  __DECLARE_VAR(REAL,TV)
  __DECLARE_VAR(REAL,LIM_L)
  __DECLARE_VAR(REAL,LIM_H)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(REAL,Y)
  __DECLARE_VAR(BOOL,LIM)

  // FB private variables - TEMP, private and located variables
  FT_PIWL PIWL;
  FT_DERIV DIFF;

} FT_PIDWL;

void FT_PIDWL_init__(FT_PIDWL *data__, BOOL retain);
// Code part
void FT_PIDWL_body__(FT_PIDWL *data__);
// FUNCTION_BLOCK FT_PT1
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(TIME,_T)
  __DECLARE_VAR(REAL,K)
  __DECLARE_VAR(REAL,OUT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(UDINT,LAST)
  __DECLARE_VAR(UDINT,TX)
  __DECLARE_VAR(BOOL,INIT)

} FT_PT1;

void FT_PT1_init__(FT_PT1 *data__, BOOL retain);
// Code part
void FT_PT1_body__(FT_PT1 *data__);
// FUNCTION_BLOCK FT_IMP
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(TIME,_T)
  __DECLARE_VAR(REAL,K)
  __DECLARE_VAR(REAL,OUT)

  // FB private variables - TEMP, private and located variables
  FT_PT1 T1;

} FT_IMP;

void FT_IMP_init__(FT_IMP *data__, BOOL retain);
// Code part
void FT_IMP_body__(FT_IMP *data__);
// FUNCTION_BLOCK R2_ADD
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL2,X)
  __DECLARE_VAR(REAL,Y)
  __DECLARE_VAR(REAL2,_R2_ADD)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,TEMP)

} R2_ADD;

void R2_ADD_init__(R2_ADD *data__, BOOL retain);
// Code part
void R2_ADD_body__(R2_ADD *data__);
// FUNCTION
REAL DEAD_ZONE(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL L);
// FUNCTION_BLOCK CONTROL_SET1
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,KT)
  __DECLARE_VAR(REAL,TT)
  __DECLARE_VAR(BOOL,_PI)
  __DECLARE_VAR(BOOL,_PID)
  __DECLARE_VAR(REAL,P_K)
  __DECLARE_VAR(REAL,PI_K)
  __DECLARE_VAR(REAL,PI_TN)
  __DECLARE_VAR(REAL,PID_K)
  __DECLARE_VAR(REAL,PID_TN)
  __DECLARE_VAR(REAL,PID_TV)
  __DECLARE_VAR(REAL,KP)
  __DECLARE_VAR(REAL,TN)
  __DECLARE_VAR(REAL,TV)
  __DECLARE_VAR(REAL,KI)
  __DECLARE_VAR(REAL,KD)

  // FB private variables - TEMP, private and located variables

} CONTROL_SET1;

void CONTROL_SET1_init__(CONTROL_SET1 *data__, BOOL retain);
// Code part
void CONTROL_SET1_body__(CONTROL_SET1 *data__);
// FUNCTION
UDINT T_PLC_MS(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL DEBUG);
// FUNCTION_BLOCK TP_X
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,IN)
  __DECLARE_VAR(TIME,PT)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(TIME,ET)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,EDGE)
  __DECLARE_VAR(TIME,START)
  __DECLARE_VAR(TIME,TX)

} TP_X;

void TP_X_init__(TP_X *data__, BOOL retain);
// Code part
void TP_X_body__(TP_X *data__);
// FUNCTION_BLOCK INTEGRATE
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,_E)
  __DECLARE_VAR(REAL,X)
  __DECLARE_VAR(REAL,K)
  __DECLARE_VAR(REAL,Y)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,X_LAST)
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(UDINT,LAST)
  __DECLARE_VAR(UDINT,TX)

} INTEGRATE;

void INTEGRATE_init__(INTEGRATE *data__, BOOL retain);
// Code part
void INTEGRATE_body__(INTEGRATE *data__);
// FUNCTION_BLOCK FT_INT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(REAL,K)
  __DECLARE_VAR(BOOL,RUN)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(REAL,OUT_MIN)
  __DECLARE_VAR(REAL,OUT_MAX)
  __DECLARE_VAR(REAL,OUT)
  __DECLARE_VAR(BOOL,LIM)

  // FB private variables - TEMP, private and located variables
  INTEGRATE INTEG;

} FT_INT;

void FT_INT_init__(FT_INT *data__, BOOL retain);
// Code part
void FT_INT_body__(FT_INT *data__);
// FUNCTION_BLOCK FT_PIW
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(REAL,KP)
  __DECLARE_VAR(REAL,KI)
  __DECLARE_VAR(REAL,LIM_L)
  __DECLARE_VAR(REAL,LIM_H)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(REAL,Y)
  __DECLARE_VAR(BOOL,LIM)

  // FB private variables - TEMP, private and located variables
  FT_INT INTEG;

} FT_PIW;

void FT_PIW_init__(FT_PIW *data__, BOOL retain);
// Code part
void FT_PIW_body__(FT_PIW *data__);
// FUNCTION_BLOCK R2_SET
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,X)
  __DECLARE_VAR(REAL2,_R2_SET)

  // FB private variables - TEMP, private and located variables

} R2_SET;

void R2_SET_init__(R2_SET *data__, BOOL retain);
// Code part
void R2_SET_body__(R2_SET *data__);
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
// FUNCTION_BLOCK FT_PID
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(REAL,KP)
  __DECLARE_VAR(REAL,TN)
  __DECLARE_VAR(REAL,TV)
  __DECLARE_VAR(REAL,ILIM_L)
  __DECLARE_VAR(REAL,ILIM_H)
  __DECLARE_VAR(BOOL,IEN)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(REAL,Y)
  __DECLARE_VAR(BOOL,LIM)

  // FB private variables - TEMP, private and located variables
  FT_INT INTEG;
  FT_DERIV DIFF;

} FT_PID;

void FT_PID_init__(FT_PID *data__, BOOL retain);
// Code part
void FT_PID_body__(FT_PID *data__);
// FUNCTION_BLOCK CLK_PRG
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(TIME,PT)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,INIT)
  __DECLARE_VAR(TIME,LAST)
  __DECLARE_VAR(TIME,TX)

} CLK_PRG;

void CLK_PRG_init__(CLK_PRG *data__, BOOL retain);
// Code part
void CLK_PRG_body__(CLK_PRG *data__);
// FUNCTION_BLOCK PWM_DC
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,F)
  __DECLARE_VAR(REAL,DC)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  CLK_PRG CLK;
  TP_X PULSE;
  __DECLARE_VAR(REAL,TMP)

} PWM_DC;

void PWM_DC_init__(PWM_DC *data__, BOOL retain);
// Code part
void PWM_DC_body__(PWM_DC *data__);
// FUNCTION_BLOCK CTRL_PWM
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,CI)
  __DECLARE_VAR(REAL,MAN_IN)
  __DECLARE_VAR(BOOL,MANUAL)
  __DECLARE_VAR(REAL,F)
  __DECLARE_VAR(BOOL,Q)

  // FB private variables - TEMP, private and located variables
  PWM_DC PW;

} CTRL_PWM;

void CTRL_PWM_init__(CTRL_PWM *data__, BOOL retain);
// Code part
void CTRL_PWM_body__(CTRL_PWM *data__);
// FUNCTION_BLOCK DEAD_ZONE2
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,X)
  __DECLARE_VAR(REAL,L)
  __DECLARE_VAR(REAL,Y)

  // FB private variables - TEMP, private and located variables

} DEAD_ZONE2;

void DEAD_ZONE2_init__(DEAD_ZONE2 *data__, BOOL retain);
// Code part
void DEAD_ZONE2_body__(DEAD_ZONE2 *data__);
// FUNCTION
REAL CTRL_IN(
  BOOL EN, 
  BOOL *__ENO, 
  REAL SET_POINT, 
  REAL ACTUAL, 
  REAL NOISE);
__DECLARE_ARRAY_TYPE(__ARRAY_OF_REAL_64,REAL,[64])
// FUNCTION_BLOCK FT_TN64
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(TIME,_T)
  __DECLARE_VAR(REAL,OUT)
  __DECLARE_VAR(BOOL,TRIG)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,LENGTH)
  __DECLARE_VAR(__ARRAY_OF_REAL_64,X)
  __DECLARE_VAR(INT,CNT)
  __DECLARE_VAR(TIME,LAST)
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(BOOL,INIT)

} FT_TN64;

void FT_TN64_init__(FT_TN64 *data__, BOOL retain);
// Code part
void FT_TN64_body__(FT_TN64 *data__);
// FUNCTION_BLOCK HYST
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(REAL,_ON)
  __DECLARE_VAR(REAL,OFF)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(BOOL,WIN)

  // FB private variables - TEMP, private and located variables

} HYST;

void HYST_init__(HYST *data__, BOOL retain);
// Code part
void HYST_body__(HYST *data__);
// FUNCTION_BLOCK HYST_3
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(REAL,_HYST)
  __DECLARE_VAR(REAL,VAL1)
  __DECLARE_VAR(REAL,VAL2)
  __DECLARE_VAR(BOOL,Q1)
  __DECLARE_VAR(BOOL,Q2)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,X)

} HYST_3;

void HYST_3_init__(HYST_3 *data__, BOOL retain);
// Code part
void HYST_3_body__(HYST_3 *data__);
// FUNCTION_BLOCK HYST_2
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(REAL,VAL)
  __DECLARE_VAR(REAL,HYS)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(BOOL,WIN)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,TMP)

} HYST_2;

void HYST_2_init__(HYST_2 *data__, BOOL retain);
// Code part
void HYST_2_body__(HYST_2 *data__);
// FUNCTION_BLOCK HYST_1
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(REAL,HIGH)
  __DECLARE_VAR(REAL,LOW)
  __DECLARE_VAR(BOOL,Q)
  __DECLARE_VAR(BOOL,WIN)

  // FB private variables - TEMP, private and located variables

} HYST_1;

void HYST_1_init__(HYST_1 *data__, BOOL retain);
// Code part
void HYST_1_body__(HYST_1 *data__);
// FUNCTION_BLOCK FT_INT2
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(REAL,K)
  __DECLARE_VAR(BOOL,RUN)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(REAL,OUT_MIN)
  __DECLARE_VAR(REAL,OUT_MAX)
  __DECLARE_VAR(REAL,OUT)
  __DECLARE_VAR(BOOL,LIM)

  // FB private variables - TEMP, private and located variables
  INTEGRATE INTEG;
  __DECLARE_VAR(REAL,IX)
  __DECLARE_VAR(REAL2,VAL)
  R2_ADD _R2_ADD;
  R2_SET _R2_SET;

} FT_INT2;

void FT_INT2_init__(FT_INT2 *data__, BOOL retain);
// Code part
void FT_INT2_body__(FT_INT2 *data__);
// FUNCTION_BLOCK CTRL_OUT
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,CI)
  __DECLARE_VAR(REAL,OFFSET)
  __DECLARE_VAR(REAL,MAN_IN)
  __DECLARE_VAR(REAL,LIM_L)
  __DECLARE_VAR(REAL,LIM_H)
  __DECLARE_VAR(BOOL,MANUAL)
  __DECLARE_VAR(REAL,Y)
  __DECLARE_VAR(BOOL,LIM)

  // FB private variables - TEMP, private and located variables

} CTRL_OUT;

void CTRL_OUT_init__(CTRL_OUT *data__, BOOL retain);
// Code part
void CTRL_OUT_body__(CTRL_OUT *data__);
// FUNCTION_BLOCK FT_PT2
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(TIME,_T)
  __DECLARE_VAR(REAL,_D)
  __DECLARE_VAR(REAL,K)
  __DECLARE_VAR(REAL,OUT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,INIT)
  INTEGRATE INT1;
  INTEGRATE INT2;
  __DECLARE_VAR(REAL,TN)
  __DECLARE_VAR(REAL,I1)
  __DECLARE_VAR(REAL,I2)
  __DECLARE_VAR(REAL,TN2)

} FT_PT2;

void FT_PT2_init__(FT_PT2 *data__, BOOL retain);
// Code part
void FT_PT2_body__(FT_PT2 *data__);
// FUNCTION_BLOCK FT_PIDW
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(REAL,KP)
  __DECLARE_VAR(REAL,TN)
  __DECLARE_VAR(REAL,TV)
  __DECLARE_VAR(REAL,LIM_L)
  __DECLARE_VAR(REAL,LIM_H)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(REAL,Y)
  __DECLARE_VAR(BOOL,LIM)

  // FB private variables - TEMP, private and located variables
  INTEGRATE INTEG;
  FT_DERIV DIFF;
  __DECLARE_VAR(REAL,YI)

} FT_PIDW;

void FT_PIDW_init__(FT_PIDW *data__, BOOL retain);
// Code part
void FT_PIDW_body__(FT_PIDW *data__);
// FUNCTION_BLOCK FT_PDT1
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(REAL,KP)
  __DECLARE_VAR(REAL,TV)
  __DECLARE_VAR(REAL,T1)
  __DECLARE_VAR(REAL,Y)

  // FB private variables - TEMP, private and located variables
  FT_DERIV DIFF;
  FT_PT1 _TP;

} FT_PDT1;

void FT_PDT1_init__(FT_PDT1 *data__, BOOL retain);
// Code part
void FT_PDT1_body__(FT_PDT1 *data__);
// FUNCTION
REAL DEAD_BAND(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL L);
// FUNCTION_BLOCK FT_PD
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(REAL,KP)
  __DECLARE_VAR(REAL,TV)
  __DECLARE_VAR(REAL,Y)

  // FB private variables - TEMP, private and located variables
  FT_DERIV DIFF;

} FT_PD;

void FT_PD_init__(FT_PD *data__, BOOL retain);
// Code part
void FT_PD_body__(FT_PD *data__);
// FUNCTION
BYTE BAND_B(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE X, 
  BYTE B);
// FUNCTION_BLOCK FT_PI
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(REAL,KP)
  __DECLARE_VAR(REAL,KI)
  __DECLARE_VAR(REAL,ILIM_L)
  __DECLARE_VAR(REAL,ILIM_H)
  __DECLARE_VAR(BOOL,IEN)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(REAL,Y)
  __DECLARE_VAR(BOOL,LIM)

  // FB private variables - TEMP, private and located variables
  FT_INT INTEG;

} FT_PI;

void FT_PI_init__(FT_PI *data__, BOOL retain);
// Code part
void FT_PI_body__(FT_PI *data__);
// FUNCTION_BLOCK CONTROL_SET12
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,KS)
  __DECLARE_VAR(REAL,TU)
  __DECLARE_VAR(REAL,TG)
  __DECLARE_VAR(BOOL,_PI)
  __DECLARE_VAR(BOOL,_PID)
  __DECLARE_VAR(REAL,P_K)
  __DECLARE_VAR(REAL,PI_K)
  __DECLARE_VAR(REAL,PI_TN)
  __DECLARE_VAR(REAL,PID_K)
  __DECLARE_VAR(REAL,PID_TN)
  __DECLARE_VAR(REAL,PID_TV)
  __DECLARE_VAR(REAL,KP)
  __DECLARE_VAR(REAL,TN)
  __DECLARE_VAR(REAL,TV)
  __DECLARE_VAR(REAL,KI)
  __DECLARE_VAR(REAL,KD)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(REAL,TX)

} CONTROL_SET12;

void CONTROL_SET12_init__(CONTROL_SET12 *data__, BOOL retain);
// Code part
void CONTROL_SET12_body__(CONTROL_SET12 *data__);
// FUNCTION_BLOCK DEAD_BAND_A
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,X)
  __DECLARE_VAR(TIME,_T)
  __DECLARE_VAR(REAL,KL)
  __DECLARE_VAR(REAL,LM)
  __DECLARE_VAR(REAL,Y)
  __DECLARE_VAR(REAL,L)

  // FB private variables - TEMP, private and located variables
  FT_PT1 TP1;
  FT_PT1 TP2;

} DEAD_BAND_A;

void DEAD_BAND_A_init__(DEAD_BAND_A *data__, BOOL retain);
// Code part
void DEAD_BAND_A_body__(DEAD_BAND_A *data__);
__DECLARE_ARRAY_TYPE(__ARRAY_OF_REAL_16,REAL,[16])
// FUNCTION_BLOCK FT_TN16
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(TIME,_T)
  __DECLARE_VAR(REAL,OUT)
  __DECLARE_VAR(BOOL,TRIG)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,LENGTH)
  __DECLARE_VAR(__ARRAY_OF_REAL_16,X)
  __DECLARE_VAR(INT,CNT)
  __DECLARE_VAR(TIME,LAST)
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(BOOL,INIT)

} FT_TN16;

void FT_TN16_init__(FT_TN16 *data__, BOOL retain);
// Code part
void FT_TN16_body__(FT_TN16 *data__);
// FUNCTION_BLOCK CTRL_PID
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,ACT)
  __DECLARE_VAR(REAL,SET)
  __DECLARE_VAR(REAL,SUP)
  __DECLARE_VAR(REAL,OFS)
  __DECLARE_VAR(REAL,M_I)
  __DECLARE_VAR(BOOL,MAN)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(REAL,KP)
  __DECLARE_VAR(REAL,TN)
  __DECLARE_VAR(REAL,TV)
  __DECLARE_VAR(REAL,LL)
  __DECLARE_VAR(REAL,LH)
  __DECLARE_VAR(REAL,Y)
  __DECLARE_VAR(REAL,DIFF)
  __DECLARE_VAR(BOOL,LIM)

  // FB private variables - TEMP, private and located variables
  FT_PIDWL _PID;
  CTRL_OUT CO;

} CTRL_PID;

void CTRL_PID_init__(CTRL_PID *data__, BOOL retain);
// Code part
void CTRL_PID_body__(CTRL_PID *data__);
// FUNCTION_BLOCK CTRL_PI
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,ACT)
  __DECLARE_VAR(REAL,SET)
  __DECLARE_VAR(REAL,SUP)
  __DECLARE_VAR(REAL,OFS)
  __DECLARE_VAR(REAL,M_I)
  __DECLARE_VAR(BOOL,MAN)
  __DECLARE_VAR(BOOL,RST)
  __DECLARE_VAR(REAL,KP)
  __DECLARE_VAR(REAL,KI)
  __DECLARE_VAR(REAL,LL)
  __DECLARE_VAR(REAL,LH)
  __DECLARE_VAR(REAL,Y)
  __DECLARE_VAR(REAL,DIFF)
  __DECLARE_VAR(BOOL,LIM)

  // FB private variables - TEMP, private and located variables
  FT_PIWL PI;
  CTRL_OUT CO;

} CTRL_PI;

void CTRL_PI_init__(CTRL_PI *data__, BOOL retain);
// Code part
void CTRL_PI_body__(CTRL_PI *data__);
__DECLARE_ARRAY_TYPE(__ARRAY_OF_REAL_8,REAL,[8])
// FUNCTION_BLOCK FT_TN8
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(REAL,IN)
  __DECLARE_VAR(TIME,_T)
  __DECLARE_VAR(REAL,OUT)
  __DECLARE_VAR(BOOL,TRIG)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(INT,LENGTH)
  __DECLARE_VAR(__ARRAY_OF_REAL_8,X)
  __DECLARE_VAR(INT,CNT)
  __DECLARE_VAR(TIME,LAST)
  __DECLARE_VAR(TIME,TX)
  __DECLARE_VAR(BOOL,INIT)

} FT_TN8;

void FT_TN8_init__(FT_TN8 *data__, BOOL retain);
// Code part
void FT_TN8_body__(FT_TN8 *data__);
#endif //__POUS_H
