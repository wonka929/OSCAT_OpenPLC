void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_EVAL_body__() 





void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_POLL_body__() 





void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PY_EVAL,retain);
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->ADD10_OUT,0,retain)
  __INIT_VAR(data__->EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SEL15_OUT,0,retain)
  __INIT_VAR(data__->AND7_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->ADD10_OUT,)));
  __SET_VAR(data__->,SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (UINT)__GET_VAR(data__->ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->SEL15_OUT,));
  __SET_VAR(data__->,AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





// FUNCTION
REAL TEMP_NI(
  BOOL EN, 
  BOOL *__ENO, 
  REAL RES, 
  REAL R0)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL TEMP_NI = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return TEMP_NI;
  }
  TEMP_NI = ((SQRT__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(0.30085225 - (2.66E-3 * (R0 - RES)))) - 0.5485) * 751.8796992);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return TEMP_NI;
}


// FUNCTION
REAL RES_PT(
  BOOL EN, 
  BOOL *__ENO, 
  REAL _T, 
  REAL R0)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL T2 = 0;
  REAL RES_PT = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return RES_PT;
  }
  T2 = (_T * _T);
  if ((_T >= 0.0)) {
    RES_PT = (R0 * ((1.0 + (3.90802E-3 * _T)) + (-5.802E-7 * T2)));
  } else {
    RES_PT = (R0 * (((1.0 + (3.90802E-3 * _T)) + (-5.802E-7 * T2)) + (((-4.27350E-12 * (_T - 100.0)) * T2) * _T)));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return RES_PT;
}


// FUNCTION
REAL TEMP_PT(
  BOOL EN, 
  BOOL *__ENO, 
  REAL RES, 
  REAL R0)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL _STEP = 50.0;
  REAL X = 0;
  REAL Y = 0;
  REAL T1 = 0;
  REAL TEMP_PT = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return TEMP_PT;
  }
  X = (3.9083E-3 * R0);
  Y = (-5.775E-7 * R0);
  if ((RES >= R0)) {
    T1 = ((X * X) - ((4.0 * Y) * (R0 - RES)));
    if ((T1 < 0.0)) {
      TEMP_PT = 10000.0;
    } else {
      TEMP_PT = (( -(X) + SQRT__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)T1)) / (2.0 * Y));
    };
  } else {
    TEMP_PT = -100.0;
    while ((_STEP > 0.01)) {
      if ((RES_PT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)TEMP_PT,
        (REAL)R0) < RES)) {
        TEMP_PT = (TEMP_PT + _STEP);
      } else {
        TEMP_PT = (TEMP_PT - _STEP);
      };
      _STEP = (_STEP * 0.5);
    };
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return TEMP_PT;
}


// FUNCTION
REAL MID3(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN1, 
  REAL IN2, 
  REAL IN3)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL _IN1 = 0;
  REAL _IN2 = 0;
  REAL _IN3 = 0;
  REAL MID3 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return MID3;
  }
  _IN1 = IN1;
  _IN2 = IN2;
  _IN3 = IN3;
  if ((_IN1 > _IN2)) {
    MID3 = _IN1;
    _IN1 = _IN2;
    _IN2 = MID3;
  };
  if ((_IN2 > _IN3)) {
    _IN2 = _IN3;
  };
  MID3 = SEL__REAL__BOOL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)(_IN1 > _IN2),
    (REAL)_IN2,
    (REAL)_IN1);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return MID3;
}


// FUNCTION
REAL MULTI_IN(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN_1, 
  REAL IN_2, 
  REAL IN_3, 
  REAL DEFAULT, 
  REAL IN_MIN, 
  REAL IN_MAX, 
  BYTE MODE)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT COUNT = 0;
  BOOL F1 = __BOOL_LITERAL(FALSE);
  BOOL F2 = __BOOL_LITERAL(FALSE);
  BOOL F3 = __BOOL_LITERAL(FALSE);
  REAL MULTI_IN = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return MULTI_IN;
  }
  F1 = ((IN_1 > IN_MIN) && (IN_1 < IN_MAX));
  F2 = ((IN_2 > IN_MIN) && (IN_2 < IN_MAX));
  F3 = ((IN_3 > IN_MIN) && (IN_3 < IN_MAX));
  {
    INT __case_expression = BYTE_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)MODE);
    if ((__case_expression == 0)) {
      COUNT = 0;
      if (F1) {
        COUNT = (COUNT + 1);
        MULTI_IN = IN_1;
      } else {
        MULTI_IN = 0.0;
      };
      if (F2) {
        COUNT = (COUNT + 1);
        MULTI_IN = (MULTI_IN + IN_2);
      };
      if (F3) {
        COUNT = (COUNT + 1);
        MULTI_IN = (MULTI_IN + IN_3);
      };
      MULTI_IN = SEL__REAL__BOOL__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BOOL)(COUNT == 0),
        (REAL)(MULTI_IN / INT_TO_REAL(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (INT)COUNT)),
        (REAL)DEFAULT);
    }
    else if ((__case_expression == 1)) {
      MULTI_IN = SEL__REAL__BOOL__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BOOL)F1,
        (REAL)DEFAULT,
        (REAL)IN_1);
    }
    else if ((__case_expression == 2)) {
      MULTI_IN = SEL__REAL__BOOL__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BOOL)F2,
        (REAL)DEFAULT,
        (REAL)IN_2);
    }
    else if ((__case_expression == 3)) {
      MULTI_IN = SEL__REAL__BOOL__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BOOL)F3,
        (REAL)DEFAULT,
        (REAL)IN_3);
    }
    else if ((__case_expression == 4)) {
      MULTI_IN = DEFAULT;
    }
    else if ((__case_expression == 5)) {
      MULTI_IN = SEL__REAL__BOOL__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BOOL)F1,
        (REAL)IN_MAX,
        (REAL)IN_1);
      if ((F2 && (IN_2 < MULTI_IN))) {
        MULTI_IN = IN_2;
      };
      if ((F3 && (IN_3 < MULTI_IN))) {
        MULTI_IN = IN_3;
      };
      if ((MULTI_IN == IN_MAX)) {
        MULTI_IN = DEFAULT;
      };
    }
    else if ((__case_expression == 6)) {
      MULTI_IN = SEL__REAL__BOOL__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BOOL)F1,
        (REAL)IN_MIN,
        (REAL)IN_1);
      if ((F2 && (IN_2 > MULTI_IN))) {
        MULTI_IN = IN_2;
      };
      if ((F3 && (IN_3 > MULTI_IN))) {
        MULTI_IN = IN_3;
      };
      if ((MULTI_IN == IN_MIN)) {
        MULTI_IN = DEFAULT;
      };
    }
    else if ((__case_expression == 7)) {
      if (((F1 && F2) && F3)) {
        MULTI_IN = MID3(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (REAL)IN_1,
          (REAL)IN_2,
          (REAL)IN_3);
      } else if ((F1 && F2)) {
        MULTI_IN = MIN__REAL__REAL(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (UINT)2,
          (REAL)IN_1,
          (REAL)IN_2);
      } else if ((F1 && F3)) {
        MULTI_IN = MIN__REAL__REAL(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (UINT)2,
          (REAL)IN_1,
          (REAL)IN_3);
      } else if ((F2 && F3)) {
        MULTI_IN = MIN__REAL__REAL(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (UINT)2,
          (REAL)IN_2,
          (REAL)IN_3);
      } else if (F1) {
        MULTI_IN = IN_1;
      } else if (F2) {
        MULTI_IN = IN_2;
      } else if (F3) {
        MULTI_IN = IN_3;
      } else {
        MULTI_IN = DEFAULT;
      };
    }
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return MULTI_IN;
}


void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_VAR(data__->LOCALVAR0,0,retain)
  __INIT_VAR(data__->LOCALVAR1,0,retain)
  __INIT_VAR(data__->LOCALVAR2,0,retain)
  __INIT_VAR(data__->ADD1_OUT,0,retain)
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,ADD1_OUT,,ADD__DINT__DINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (DINT)__GET_VAR(data__->LOCALVAR0,),
    (DINT)__GET_VAR(data__->LOCALVAR1,)));
  __SET_VAR(data__->,LOCALVAR2,,__GET_VAR(data__->ADD1_OUT,));

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





// FUNCTION
REAL TEMP_SI(
  BOOL EN, 
  BOOL *__ENO, 
  REAL RES, 
  REAL _RS, 
  REAL TS)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL TEMP_SI = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return TEMP_SI;
  }
  TEMP_SI = (((-7.64E-3 + SQRT__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(((RES / _RS) * 6.64E-5) - 0.803E-5))) * 30120.48193) + TS);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return TEMP_SI;
}


// FUNCTION
REAL RES_NI(
  BOOL EN, 
  BOOL *__ENO, 
  REAL _T, 
  REAL R0)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL T2 = 0;
  REAL RES_NI = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return RES_NI;
  }
  T2 = (_T * _T);
  RES_NI = (((R0 + (0.5485 * _T)) + (0.665E-3 * T2)) + ((2.805E-9 * T2) * T2));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return RES_NI;
}


// FUNCTION
REAL RES_NTC(
  BOOL EN, 
  BOOL *__ENO, 
  REAL _T, 
  REAL RN, 
  REAL B)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL RES_NTC = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return RES_NTC;
  }
  RES_NTC = (RN * EXP__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(B * ((1.0 / (_T + 273.15)) - 0.00335401643468053))));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return RES_NTC;
}


// FUNCTION
REAL TEMP_NTC(
  BOOL EN, 
  BOOL *__ENO, 
  REAL RES, 
  REAL RN, 
  REAL B)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL TEMP_NTC = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return TEMP_NTC;
  }
  if ((RES > 0.0)) {
    TEMP_NTC = (((B * 298.15) / (B + (LN__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(RES / RN)) * 298.15))) - 273.15);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return TEMP_NTC;
}


// FUNCTION
REAL SENSOR_INT(
  BOOL EN, 
  BOOL *__ENO, 
  REAL VOLTAGE, 
  REAL CURRENT, 
  REAL RP, 
  REAL _RS)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL RG = 0;
  REAL SENSOR_INT = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SENSOR_INT;
  }
  if ((CURRENT != 0.0)) {
    RG = (VOLTAGE / CURRENT);
    SENSOR_INT = ((RP * (RG - _RS)) / ((RP + _RS) - RG));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SENSOR_INT;
}


// FUNCTION
REAL RES_SI(
  BOOL EN, 
  BOOL *__ENO, 
  REAL _T, 
  REAL _RS, 
  REAL TS)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL TX = 0;
  REAL RES_SI = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return RES_SI;
  }
  TX = (_T - TS);
  RES_SI = (_RS * ((1.0 + (7.64E-3 * TX)) + ((1.66E-5 * TX) * TX)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return RES_SI;
}


