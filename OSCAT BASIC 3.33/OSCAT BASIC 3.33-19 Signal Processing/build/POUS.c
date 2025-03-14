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
REAL WORD_TO_RANGE(
  BOOL EN, 
  BOOL *__ENO, 
  WORD X, 
  REAL LOW, 
  REAL HIGH)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL WORD_TO_RANGE = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return WORD_TO_RANGE;
  }
  WORD_TO_RANGE = ((((HIGH - LOW) * WORD_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (WORD)X)) * 0.00001525902189669640) + LOW);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return WORD_TO_RANGE;
}


// FUNCTION
REAL SCALE(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL K, 
  REAL O, 
  REAL MX, 
  REAL MN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL SCALE = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SCALE;
  }
  SCALE = LIMIT__REAL__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)MN,
    (REAL)((X * K) + O),
    (REAL)MX);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SCALE;
}


// FUNCTION
REAL SCALE_X4(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL IN1, 
  BOOL IN2, 
  BOOL IN3, 
  BOOL IN4, 
  REAL K, 
  REAL O, 
  REAL IN1_MIN, 
  REAL IN1_MAX, 
  REAL IN2_MIN, 
  REAL IN2_MAX, 
  REAL IN3_MIN, 
  REAL IN3_MAX, 
  REAL IN4_MIN, 
  REAL IN4_MAX)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL SCALE_X4 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SCALE_X4;
  }
  if (!(IN1)) {
    SCALE_X4 = IN1_MIN;
  } else {
    SCALE_X4 = IN1_MAX;
  };
  if (!(IN2)) {
    SCALE_X4 = (SCALE_X4 + IN2_MIN);
  } else {
    SCALE_X4 = (SCALE_X4 + IN2_MAX);
  };
  if (!(IN3)) {
    SCALE_X4 = (SCALE_X4 + IN3_MIN);
  } else {
    SCALE_X4 = (SCALE_X4 + IN3_MAX);
  };
  if (!(IN4)) {
    SCALE_X4 = (SCALE_X4 + IN4_MIN);
  } else {
    SCALE_X4 = (SCALE_X4 + IN4_MAX);
  };
  SCALE_X4 = ((SCALE_X4 * K) + O);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SCALE_X4;
}


// FUNCTION
BOOL SIGN_R(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BOOL SIGN_R = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SIGN_R;
  }
  SIGN_R = (IN < 0.0);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SIGN_R;
}


// FUNCTION
DWORD AOUT(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN, 
  BYTE BITS, 
  BYTE SIGN, 
  REAL LOW, 
  REAL HIGH)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL IN2 = 0;
  BOOL SX = __BOOL_LITERAL(FALSE);
  DWORD AOUT = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return AOUT;
  }
  if ((SIGN < __BYTE_LITERAL(32))) {
    SX = SIGN_R(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)IN);
    IN2 = ABS__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)IN);
  } else {
    IN2 = IN;
  };
  IN2 = LIMIT__REAL__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)LOW,
    (REAL)IN2,
    (REAL)HIGH);
  AOUT = REAL_TO_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(((IN2 - LOW) / (HIGH - LOW)) * (DWORD_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)SHL__DWORD__DWORD__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)__DWORD_LITERAL(0x1),
        (INT)BYTE_TO_INT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)BITS))) - 1.0)));
  if (SX) {
    AOUT = (SHL__DWORD__DWORD__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)__DWORD_LITERAL(0x1),
      (INT)BYTE_TO_INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)SIGN)) | AOUT);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return AOUT;
}


// FUNCTION
REAL OFFSET2(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  BOOL O1, 
  BOOL O2, 
  BOOL O3, 
  BOOL O4, 
  BOOL _D)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL OFFSET_1 = 0;
  REAL OFFSET_2 = 0;
  REAL OFFSET_3 = 0;
  REAL OFFSET_4 = 0;
  REAL DEFAULT = 0;
  REAL OFFSET2 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return OFFSET2;
  }
  if (_D) {
    OFFSET2 = DEFAULT;
  } else {
    OFFSET2 = X;
  };
  if (O4) {
    OFFSET2 = (OFFSET2 + OFFSET_4);
  } else if (O3) {
    OFFSET2 = (OFFSET2 + OFFSET_3);
  } else if (O2) {
    OFFSET2 = (OFFSET2 + OFFSET_2);
  } else if (O1) {
    OFFSET2 = (OFFSET2 + OFFSET_1);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return OFFSET2;
}


// FUNCTION
UDINT T_PLC_MS(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL DEBUG)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  UDINT TX = 0;
  INT N = 0;
  UDINT OFFSET = 0;
  DWORD TEMP = 1;
  UDINT T_PLC_MS = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return T_PLC_MS;
  }
  TX = 0;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern unsigned long __tick;
  extern unsigned long long common_ticktime__;
  unsigned long long ticktime_ms = (common_ticktime__)/1000000;
  UDINT plc_time = (UDINT)(ticktime_ms * (unsigned long long)__tick);
  TX = plc_time
  #undef GetFbVar
  #undef SetFbVar
;
  T_PLC_MS = TX;
  if (DEBUG) {
    T_PLC_MS = ((DWORD_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)(SHL__DWORD__DWORD__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)UDINT_TO_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (UDINT)T_PLC_MS),
        (INT)N) | SHL__DWORD__DWORD__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)TEMP,
        (INT)N))) - 1) + OFFSET);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return T_PLC_MS;
}


void FILTER_DW_init__(FILTER_DW *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->_T,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->LAST,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TX,0,retain)
  __INIT_VAR(data__->YI,0,retain)
}

// Code part
void FILTER_DW_body__(FILTER_DW *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,TX,,T_PLC_MS(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__BOOL_LITERAL(FALSE)));
  if ((!(__GET_VAR(data__->INIT,)) || EQ_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->_T,), __time_to_timespec(1, 0, 0, 0, 0, 0)))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,YI,,DWORD_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)__GET_VAR(data__->X,)));
  } else {
    __SET_VAR(data__->,YI,,(__GET_VAR(data__->YI,) + (((DWORD_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)__GET_VAR(data__->X,)) - DWORD_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)__GET_VAR(data__->Y,))) * UDINT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)(__GET_VAR(data__->TX,) - __GET_VAR(data__->LAST,)))) / TIME_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)__GET_VAR(data__->_T,)))));
  };
  __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
  __SET_VAR(data__->,Y,,REAL_TO_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->YI,)));

  goto __end;

__end:
  return;
} // FILTER_DW_body__() 





// FUNCTION
WORD RANGE_TO_WORD(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL LOW, 
  REAL HIGH)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  WORD RANGE_TO_WORD = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return RANGE_TO_WORD;
  }
  RANGE_TO_WORD = INT_TO_WORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)TRUNC__INT__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(((LIMIT__REAL__REAL__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)LOW,
        (REAL)X,
        (REAL)HIGH) - LOW) * 65535.0) / (HIGH - LOW))));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return RANGE_TO_WORD;
}


// FUNCTION
REAL SCALE_X8(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL IN1, 
  BOOL IN2, 
  BOOL IN3, 
  BOOL IN4, 
  BOOL IN5, 
  BOOL IN6, 
  BOOL IN7, 
  BOOL IN8, 
  REAL K, 
  REAL O, 
  REAL IN1_MIN, 
  REAL IN1_MAX, 
  REAL IN2_MIN, 
  REAL IN2_MAX, 
  REAL IN3_MIN, 
  REAL IN3_MAX, 
  REAL IN4_MIN, 
  REAL IN4_MAX, 
  REAL IN5_MIN, 
  REAL IN5_MAX, 
  REAL IN6_MIN, 
  REAL IN6_MAX, 
  REAL IN7_MIN, 
  REAL IN7_MAX, 
  REAL IN8_MIN, 
  REAL IN8_MAX)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL SCALE_X8 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SCALE_X8;
  }
  SCALE_X8 = (((((((((SEL__REAL__BOOL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)IN1,
    (REAL)IN1_MIN,
    (REAL)IN1_MAX) + SEL__REAL__BOOL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)IN2,
    (REAL)IN2_MIN,
    (REAL)IN2_MAX)) + SEL__REAL__BOOL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)IN3,
    (REAL)IN3_MIN,
    (REAL)IN3_MAX)) + SEL__REAL__BOOL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)IN4,
    (REAL)IN4_MIN,
    (REAL)IN4_MAX)) + SEL__REAL__BOOL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)IN5,
    (REAL)IN5_MIN,
    (REAL)IN5_MAX)) + SEL__REAL__BOOL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)IN6,
    (REAL)IN6_MIN,
    (REAL)IN6_MAX)) + SEL__REAL__BOOL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)IN7,
    (REAL)IN7_MIN,
    (REAL)IN7_MAX)) + SEL__REAL__BOOL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)IN8,
    (REAL)IN8_MIN,
    (REAL)IN8_MAX)) * K) + O);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SCALE_X8;
}


// FUNCTION
INT INC1(
  BOOL EN, 
  BOOL *__ENO, 
  INT X, 
  INT N)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT INC1 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return INC1;
  }
  if ((X >= (N - 1))) {
    INC1 = 0;
  } else {
    INC1 = (X + 1);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return INC1;
}


void FILTER_MAV_DW_init__(FILTER_MAV_DW *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  {
    static const __ARRAY_OF_DWORD_32 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,BUFFER,,temp);
  }
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->TMP,0,retain)
}

// Code part
void FILTER_MAV_DW_body__(FILTER_MAV_DW *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,N,,MIN__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__UINT_LITERAL(32)));
  if (((!(__GET_VAR(data__->INIT,)) || __GET_VAR(data__->RST,)) || (__GET_VAR(data__->N,) == __UINT_LITERAL(0)))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,TMP,,(UINT_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)__GET_VAR(data__->N,)) - 1));
    for(__GET_VAR(data__->I,) = 0; __GET_VAR(data__->I,) <= __GET_VAR(data__->TMP,); __GET_VAR(data__->I,)++) {
      __SET_VAR(data__->,BUFFER,.table[(__GET_VAR(data__->I,)) - (0)],__GET_VAR(data__->X,));
    };
    __SET_VAR(data__->,Y,,__GET_VAR(data__->X,));
  } else {
    __SET_VAR(data__->,TMP,,UINT_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)__GET_VAR(data__->N,)));
    __SET_VAR(data__->,I,,INC1(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)__GET_VAR(data__->I,),
      (INT)__GET_VAR(data__->TMP,)));
    __SET_VAR(data__->,Y,,UDINT_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)(DWORD_TO_UDINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)__GET_VAR(data__->Y,)) + ((DWORD_TO_UDINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)__GET_VAR(data__->X,)) - DWORD_TO_UDINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)__GET_VAR(data__->BUFFER,.table[(__GET_VAR(data__->I,)) - (0)]))) / UINT_TO_UDINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UINT)__GET_VAR(data__->N,))))));
    __SET_VAR(data__->,BUFFER,.table[(__GET_VAR(data__->I,)) - (0)],__GET_VAR(data__->X,));
  };

  goto __end;

__end:
  return;
} // FILTER_MAV_DW_body__() 





void DELAY_init__(DELAY *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT,0,retain)
  {
    static const __ARRAY_OF_REAL_32 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,BUF,,temp);
  }
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STOP,0,retain)
}

// Code part
void DELAY_body__(DELAY *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,STOP,,(LIMIT__INT__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)0,
    (INT)__GET_VAR(data__->N,),
    (INT)32) - 1));
  if ((__GET_VAR(data__->RST,) || !(__GET_VAR(data__->INIT,)))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    for(__GET_VAR(data__->I,) = 0; __GET_VAR(data__->I,) <= __GET_VAR(data__->STOP,); __GET_VAR(data__->I,)++) {
      __SET_VAR(data__->,BUF,.table[(__GET_VAR(data__->I,)) - (0)],__GET_VAR(data__->IN,));
    };
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->,I,,0);
  } else if ((__GET_VAR(data__->STOP,) < 0)) {
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->IN,));
  } else {
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->BUF,.table[(__GET_VAR(data__->I,)) - (0)]));
    __SET_VAR(data__->,BUF,.table[(__GET_VAR(data__->I,)) - (0)],__GET_VAR(data__->IN,));
    __SET_VAR(data__->,I,,INC1(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)__GET_VAR(data__->I,),
      (INT)__GET_VAR(data__->N,)));
  };

  goto __end;

__end:
  return;
} // DELAY_body__() 





// FUNCTION
REAL MIX(
  BOOL EN, 
  BOOL *__ENO, 
  REAL A, 
  REAL B, 
  REAL M)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL MIX = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return MIX;
  }
  MIX = (((1.0 - M) * A) + (M * B));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return MIX;
}


// FUNCTION
BOOL BIT_OF_DWORD(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN, 
  INT N)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BOOL BIT_OF_DWORD = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return BIT_OF_DWORD;
  }
  BIT_OF_DWORD = ((SHR__DWORD__DWORD__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)IN,
    (INT)N) & 0x1) > 0);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return BIT_OF_DWORD;
}


// FUNCTION
REAL AIN(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN, 
  BYTE BITS, 
  BYTE SIGN, 
  REAL LOW, 
  REAL HIGH)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  DWORD TEMP1 = 0;
  DWORD TEMP2 = 0;
  BOOL SX = __BOOL_LITERAL(FALSE);
  REAL AIN = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return AIN;
  }
  if ((SIGN < __BYTE_LITERAL(32))) {
    TEMP1 = SHR__DWORD__DWORD__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN,
      (INT)BYTE_TO_INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)SIGN));
    SX = BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)TEMP1,
      (INT)0);
  } else {
    SX = __BOOL_LITERAL(FALSE);
  };
  TEMP1 = SHR__DWORD__DWORD__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)__DWORD_LITERAL(0xFFFFFFFF),
    (INT)(32 - BYTE_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)BITS)));
  TEMP2 = (IN & TEMP1);
  AIN = ((((HIGH - LOW) * DWORD_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)TEMP2)) / DWORD_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)TEMP1)) + LOW);
  if (SX) {
    AIN =  -(AIN);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return AIN;
}


// FUNCTION
REAL MUX_R4(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN0, 
  REAL IN1, 
  REAL IN2, 
  REAL IN3, 
  BOOL A0, 
  BOOL A1)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL MUX_R4 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return MUX_R4;
  }
  if (A1) {
    MUX_R4 = SEL__REAL__BOOL__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)A0,
      (REAL)IN2,
      (REAL)IN3);
  } else {
    MUX_R4 = SEL__REAL__BOOL__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)A0,
      (REAL)IN0,
      (REAL)IN1);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return MUX_R4;
}


// FUNCTION
REAL BYTE_TO_RANGE(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE X, 
  REAL LOW, 
  REAL HIGH)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL BYTE_TO_RANGE = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return BYTE_TO_RANGE;
  }
  BYTE_TO_RANGE = ((((HIGH - LOW) * BYTE_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)X)) / 255.0) + LOW);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return BYTE_TO_RANGE;
}


// FUNCTION
REAL OFFSET_OSCAT(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  BOOL O1, 
  BOOL O2, 
  BOOL O3, 
  BOOL O4, 
  BOOL _D)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL OFFSET_1 = 0;
  REAL OFFSET_2 = 0;
  REAL OFFSET_3 = 0;
  REAL OFFSET_4 = 0;
  REAL DEFAULT = 0;
  REAL OFFSET_OSCAT = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return OFFSET_OSCAT;
  }
  if (_D) {
    OFFSET_OSCAT = DEFAULT;
  } else {
    OFFSET_OSCAT = X;
  };
  if (O1) {
    OFFSET_OSCAT = (OFFSET_OSCAT + OFFSET_1);
  };
  if (O2) {
    OFFSET_OSCAT = (OFFSET_OSCAT + OFFSET_2);
  };
  if (O3) {
    OFFSET_OSCAT = (OFFSET_OSCAT + OFFSET_3);
  };
  if (O4) {
    OFFSET_OSCAT = (OFFSET_OSCAT + OFFSET_4);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return OFFSET_OSCAT;
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
REAL STAIR(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL _D)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL STAIR = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return STAIR;
  }
  if ((_D > 0.0)) {
    STAIR = (DINT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DINT)REAL_TO_DINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)(X / _D))) * _D);
  } else {
    STAIR = X;
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return STAIR;
}


// FUNCTION
DINT _WORD_TO_DINT(
  BOOL EN, 
  BOOL *__ENO, 
  WORD IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  DINT _WORD_TO_DINT = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return _WORD_TO_DINT;
  }
  _WORD_TO_DINT = UINT_TO_DINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)WORD_TO_UINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (WORD)IN));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return _WORD_TO_DINT;
}


void _RMP_W_init__(_RMP_W *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->DIR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_E,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TR,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->RMP,0,retain)
  __INIT_VAR(data__->TX,0,retain)
  __INIT_VAR(data__->TL,0,retain)
  __INIT_VAR(data__->_STEP,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LAST_DIR,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void _RMP_W_body__(_RMP_W *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,TX,,T_PLC_MS(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__BOOL_LITERAL(FALSE)));
  if ((__GET_VAR(data__->_E,) && __GET_VAR(data__->INIT,))) {
    if ((__GET_VAR(data__->DIR,) && !__GET_VAR(data__->LAST_DIR,)) || (!__GET_VAR(data__->DIR,) && __GET_VAR(data__->LAST_DIR,))) {
      __SET_VAR(data__->,TL,,__GET_VAR(data__->TX,));
      __SET_VAR(data__->,LAST_DIR,,__GET_VAR(data__->DIR,));
    };
    if (GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TR,), __time_to_timespec(1, 0, 0, 0, 0, 0))) {
      __SET_VAR(data__->,_STEP,,DWORD_TO_DINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)UDINT_TO_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (UDINT)(DWORD_TO_UDINT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (DWORD)SHL__DWORD__DWORD__SINT(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (DWORD)UDINT_TO_DWORD(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (UDINT)(__GET_VAR(data__->TX,) - __GET_VAR(data__->TL,))),
              (SINT)16)) / TIME_TO_UDINT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (TIME)__GET_VAR(data__->TR,))))));
    } else {
      __SET_VAR(data__->,_STEP,,__DINT_LITERAL(65535));
    };
    if ((__GET_VAR(data__->_STEP,) > __DINT_LITERAL(0))) {
      __SET_VAR(data__->,TL,,__GET_VAR(data__->TX,));
      if (!(__GET_VAR(data__->DIR,))) {
        __SET_VAR(data__->,_STEP,, -(__GET_VAR(data__->_STEP,)));
      };
      __SET_VAR(data__->,RMP,,DINT_TO_WORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DINT)LIMIT__DINT__DINT__DINT__DINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DINT)__DINT_LITERAL(0),
          (DINT)(_WORD_TO_DINT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (WORD)__GET_VAR(data__->RMP,)) + __GET_VAR(data__->_STEP,)),
          (DINT)__DINT_LITERAL(65535))));
    };
  } else {
    __SET_VAR(data__->,TL,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
  };

  goto __end;

__end:
  return;
} // _RMP_W_body__() 





void RMP_W_init__(RMP_W *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->SET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->_E,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->UP,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT,0,retain)
  __INIT_VAR(data__->BUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->HIGH,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LOW,__BOOL_LITERAL(FALSE),retain)
  _RMP_W_init__(&data__->RMP,retain);
}

// Code part
void RMP_W_body__(RMP_W *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->RMP.,DIR,,__GET_VAR(data__->UP,));
  __SET_VAR(data__->RMP.,_E,,__GET_VAR(data__->_E,));
  __SET_VAR(data__->RMP.,TR,,__GET_VAR(data__->PT,));
  __SET_VAR(data__->RMP.,RMP,,__GET_VAR(data__->OUT,));
  _RMP_W_body__(&data__->RMP);
  __SET_VAR(data__->,OUT,,__GET_VAR(data__->RMP.RMP));
  __SET_VAR(data__->,OUT,,__GET_VAR(data__->RMP.RMP,));
  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,OUT,,__WORD_LITERAL(0));
  } else if (__GET_VAR(data__->SET,)) {
    __SET_VAR(data__->,OUT,,__WORD_LITERAL(65535));
  };
  __SET_VAR(data__->,LOW,,(__GET_VAR(data__->OUT,) == __WORD_LITERAL(0)));
  __SET_VAR(data__->,HIGH,,(__GET_VAR(data__->OUT,) == __WORD_LITERAL(65535)));
  __SET_VAR(data__->,BUSY,,(!((__GET_VAR(data__->LOW,) || __GET_VAR(data__->HIGH,))) && __GET_VAR(data__->_E,)));

  goto __end;

__end:
  return;
} // RMP_W_body__() 





void FILTER_W_init__(FILTER_W *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->_T,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->LAST,0,retain)
  __INIT_VAR(data__->TX,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TMP,0,retain)
}

// Code part
void FILTER_W_body__(FILTER_W *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,TX,,T_PLC_MS(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__BOOL_LITERAL(FALSE)));
  if ((!(__GET_VAR(data__->INIT,)) || EQ_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->_T,), __time_to_timespec(1, 0, 0, 0, 0, 0)))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,Y,,__GET_VAR(data__->X,));
  } else if ((__GET_VAR(data__->Y,) == __GET_VAR(data__->X,))) {
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
  } else {
    __SET_VAR(data__->,TMP,,((UINT_TO_DINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)(WORD_TO_UINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->X,)) - WORD_TO_UINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->Y,)))) * UDINT_TO_DINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)(__GET_VAR(data__->TX,) - __GET_VAR(data__->LAST,)))) / TIME_TO_DINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)__GET_VAR(data__->_T,))));
    if ((__GET_VAR(data__->TMP,) != __DINT_LITERAL(0))) {
      __SET_VAR(data__->,Y,,DINT_TO_WORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DINT)(WORD_TO_DINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (WORD)__GET_VAR(data__->Y,)) + __GET_VAR(data__->TMP,))));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    };
  };

  goto __end;

__end:
  return;
} // FILTER_W_body__() 





// FUNCTION
BYTE RANGE_TO_BYTE(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL LOW, 
  REAL HIGH)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BYTE RANGE_TO_BYTE = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return RANGE_TO_BYTE;
  }
  RANGE_TO_BYTE = INT_TO_BYTE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)TRUNC__INT__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(((LIMIT__REAL__REAL__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)LOW,
        (REAL)X,
        (REAL)HIGH) - LOW) * 255.0) / (HIGH - LOW))));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return RANGE_TO_BYTE;
}


void SH_init__(SH *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->CLK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void SH_body__(SH *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->CLK,) && !(__GET_VAR(data__->EDGE,)))) {
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->,TRIG,,__BOOL_LITERAL(TRUE));
  } else {
    __SET_VAR(data__->,TRIG,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->CLK,));

  goto __end;

__end:
  return;
} // SH_body__() 





void FADE_init__(FADE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN1,0,retain)
  __INIT_VAR(data__->IN2,0,retain)
  __INIT_VAR(data__->F,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TF,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Y,0,retain)
  RMP_W_init__(&data__->RMX,retain);
}

// Code part
void FADE_body__(FADE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->RMX.,SET,,(__GET_VAR(data__->RST,) && __GET_VAR(data__->F,)));
  __SET_VAR(data__->RMX.,PT,,__GET_VAR(data__->TF,));
  __SET_VAR(data__->RMX.,UP,,__GET_VAR(data__->F,));
  __SET_VAR(data__->RMX.,RST,,(__GET_VAR(data__->RST,) && !(__GET_VAR(data__->F,))));
  RMP_W_body__(&data__->RMX);
  __SET_VAR(data__->,Y,,((((__GET_VAR(data__->IN2,) - __GET_VAR(data__->IN1,)) / 65535.0) * WORD_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (WORD)__GET_VAR(data__->RMX.OUT,))) + __GET_VAR(data__->IN1,)));

  goto __end;

__end:
  return;
} // FADE_body__() 





void SEL2_OF_3_init__(SEL2_OF_3 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN1,0,retain)
  __INIT_VAR(data__->IN2,0,retain)
  __INIT_VAR(data__->IN3,0,retain)
  __INIT_VAR(data__->_D,0,retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->W,0,retain)
  __INIT_VAR(data__->_E,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->D12,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->D23,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->D31,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void SEL2_OF_3_body__(SEL2_OF_3 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,D12,,(ABS__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(__GET_VAR(data__->IN1,) - __GET_VAR(data__->IN2,))) <= __GET_VAR(data__->_D,)));
  __SET_VAR(data__->,D23,,(ABS__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(__GET_VAR(data__->IN2,) - __GET_VAR(data__->IN3,))) <= __GET_VAR(data__->_D,)));
  __SET_VAR(data__->,D31,,(ABS__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(__GET_VAR(data__->IN3,) - __GET_VAR(data__->IN1,))) <= __GET_VAR(data__->_D,)));
  if ((((__GET_VAR(data__->D12,) && __GET_VAR(data__->D23,)) || (__GET_VAR(data__->D12,) && __GET_VAR(data__->D31,))) || (__GET_VAR(data__->D23,) && __GET_VAR(data__->D31,)))) {
    __SET_VAR(data__->,Y,,(((__GET_VAR(data__->IN1,) + __GET_VAR(data__->IN2,)) + __GET_VAR(data__->IN3,)) * 0.333333333333));
    __SET_VAR(data__->,_E,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,W,,0);
  } else if (__GET_VAR(data__->D12,)) {
    __SET_VAR(data__->,Y,,((__GET_VAR(data__->IN1,) + __GET_VAR(data__->IN2,)) * 0.5));
    __SET_VAR(data__->,_E,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,W,,3);
  } else if (__GET_VAR(data__->D23,)) {
    __SET_VAR(data__->,Y,,((__GET_VAR(data__->IN2,) + __GET_VAR(data__->IN3,)) * 0.5));
    __SET_VAR(data__->,_E,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,W,,1);
  } else if (__GET_VAR(data__->D31,)) {
    __SET_VAR(data__->,Y,,((__GET_VAR(data__->IN3,) + __GET_VAR(data__->IN1,)) * 0.5));
    __SET_VAR(data__->,_E,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,W,,2);
  } else {
    __SET_VAR(data__->,_E,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,W,,4);
  };

  goto __end;

__end:
  return;
} // SEL2_OF_3_body__() 





// FUNCTION
REAL OVERRIDE(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X1, 
  REAL X2, 
  REAL X3, 
  BOOL E1, 
  BOOL E2, 
  BOOL E3)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL OVERRIDE = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return OVERRIDE;
  }
  if (E1) {
    OVERRIDE = X1;
  };
  if ((E2 && (ABS__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)X2) > ABS__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)OVERRIDE)))) {
    OVERRIDE = X2;
  };
  if ((E3 && (ABS__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)X3) > ABS__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)OVERRIDE)))) {
    OVERRIDE = X3;
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return OVERRIDE;
}


void SH_T_init__(SH_T *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->_E,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT,0,retain)
}

// Code part
void SH_T_body__(SH_T *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (__GET_VAR(data__->_E,)) {
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->IN,));
  };

  goto __end;

__end:
  return;
} // SH_T_body__() 





// FUNCTION
INT FLOOR(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT FLOOR = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return FLOOR;
  }
  FLOOR = REAL_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)X);
  if ((INT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)FLOOR) > X)) {
    FLOOR = (FLOOR - 1);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return FLOOR;
}


void STAIR2_init__(STAIR2 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->_D,0,retain)
  __INIT_VAR(data__->Y,0,retain)
}

// Code part
void STAIR2_body__(STAIR2 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->_D,) > 0.0)) {
    if (((__GET_VAR(data__->X,) >= (__GET_VAR(data__->Y,) + __GET_VAR(data__->_D,))) || (__GET_VAR(data__->X,) <= (__GET_VAR(data__->Y,) - __GET_VAR(data__->_D,))))) {
      __SET_VAR(data__->,Y,,(INT_TO_REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)FLOOR(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (REAL)(__GET_VAR(data__->X,) / __GET_VAR(data__->_D,)))) * __GET_VAR(data__->_D,)));
    };
  } else {
    __SET_VAR(data__->,Y,,__GET_VAR(data__->X,));
  };

  goto __end;

__end:
  return;
} // STAIR2_body__() 





void FILTER_I_init__(FILTER_I *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->_T,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->YI,0,retain)
  __INIT_VAR(data__->LAST,0,retain)
  __INIT_VAR(data__->TX,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void FILTER_I_body__(FILTER_I *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,TX,,T_PLC_MS(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__BOOL_LITERAL(FALSE)));
  if ((!(__GET_VAR(data__->INIT,)) || EQ_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->_T,), __time_to_timespec(1, 0, 0, 0, 0, 0)))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,YI,,(INT_TO_DINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)__GET_VAR(data__->X,)) * __DINT_LITERAL(1000)));
  } else {
    __SET_VAR(data__->,YI,,(__GET_VAR(data__->YI,) + (((INT_TO_DINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)(__GET_VAR(data__->X,) - __GET_VAR(data__->Y,))) * UDINT_TO_DINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)(__GET_VAR(data__->TX,) - __GET_VAR(data__->LAST,)))) * __DINT_LITERAL(1000)) / TIME_TO_DINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)__GET_VAR(data__->_T,)))));
  };
  __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
  __SET_VAR(data__->,Y,,DINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DINT)(__GET_VAR(data__->YI,) / __DINT_LITERAL(1000))));

  goto __end;

__end:
  return;
} // FILTER_I_body__() 





// FUNCTION
REAL SCALE_X2(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL IN1, 
  BOOL IN2, 
  REAL K, 
  REAL O, 
  REAL IN1_MIN, 
  REAL IN1_MAX, 
  REAL IN2_MIN, 
  REAL IN2_MAX)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL SCALE_X2 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SCALE_X2;
  }
  SCALE_X2 = (((SEL__REAL__BOOL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)IN1,
    (REAL)IN1_MIN,
    (REAL)IN1_MAX) + SEL__REAL__BOOL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)IN2,
    (REAL)IN2_MIN,
    (REAL)IN2_MAX)) * K) + O);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SCALE_X2;
}


void SH_1_init__(SH_1 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->PT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->OUT,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
}

// Code part
void SH_1_body__(SH_1 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,TX,,UDINT_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)T_PLC_MS(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__BOOL_LITERAL(FALSE))));
  if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->PT,))) {
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->,TRIG,,__BOOL_LITERAL(TRUE));
  } else {
    __SET_VAR(data__->,TRIG,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // SH_1_body__() 





// FUNCTION
BOOL EVEN(
  BOOL EN, 
  BOOL *__ENO, 
  DINT IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BOOL EVEN = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return EVEN;
  }
  EVEN = !(BIT_OF_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)DINT_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DINT)IN),
    (INT)0));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return EVEN;
}


void SH_2_init__(SH_2 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->PT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->N,16,retain)
  __INIT_VAR(data__->DISC,0,retain)
  __INIT_VAR(data__->OUT,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AVG,0,retain)
  __INIT_VAR(data__->HIGH,0,retain)
  __INIT_VAR(data__->LOW,0,retain)
  __INIT_VAR(data__->M,0,retain)
  {
    static const __ARRAY_OF_REAL_16 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,BUF,,temp);
  }
  {
    static const __ARRAY_OF_REAL_16 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,BUF2,,temp);
  }
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->I2,0,retain)
  __INIT_VAR(data__->START,0,retain)
  __INIT_VAR(data__->TEMP,0,retain)
  __INIT_VAR(data__->STOP,0,retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->D2,0,retain)
}

// Code part
void SH_2_body__(SH_2 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,TX,,UDINT_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)T_PLC_MS(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__BOOL_LITERAL(FALSE))));
  __SET_VAR(data__->,D2,,WORD_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (WORD)SHR__WORD__WORD__SINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (WORD)INT_TO_WORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)__GET_VAR(data__->DISC,)),
      (SINT)1)));
  if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->PT,))) {
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,TRIG,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,M,,LIMIT__INT__INT__INT__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)1,
      (INT)__GET_VAR(data__->N,),
      (INT)16));
    __SET_VAR(data__->,I,,(__GET_VAR(data__->M,) - 1));
    while ((__GET_VAR(data__->I,) >= 1)) {
      __SET_VAR(data__->,I2,,(__GET_VAR(data__->I,) - 1));
      __SET_VAR(data__->,BUF2,.table[(__GET_VAR(data__->I,)) - (0)],__GET_VAR(data__->BUF2,.table[(__GET_VAR(data__->I2,)) - (0)]));
      __SET_VAR(data__->,I,,(__GET_VAR(data__->I,) - 1));
    };
    __SET_VAR(data__->,BUF2,.table[(0) - (0)],__GET_VAR(data__->IN,));
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->,BUF,,__GET_VAR(data__->BUF2,));
    for(__GET_VAR(data__->START,) = 0; __GET_VAR(data__->START,) <= (__GET_VAR(data__->M,) - 2); __GET_VAR(data__->START,)++) {
      for(__GET_VAR(data__->I,) = (__GET_VAR(data__->START,) + 1); __GET_VAR(data__->I,) <= (__GET_VAR(data__->M,) - 1); __GET_VAR(data__->I,)++) {
        if ((__GET_VAR(data__->BUF,.table[(__GET_VAR(data__->START,)) - (0)]) > __GET_VAR(data__->BUF,.table[(__GET_VAR(data__->I,)) - (0)]))) {
          __SET_VAR(data__->,TEMP,,__GET_VAR(data__->BUF,.table[(__GET_VAR(data__->START,)) - (0)]));
          __SET_VAR(data__->,BUF,.table[(__GET_VAR(data__->START,)) - (0)],__GET_VAR(data__->BUF,.table[(__GET_VAR(data__->I,)) - (0)]));
          __SET_VAR(data__->,BUF,.table[(__GET_VAR(data__->I,)) - (0)],__GET_VAR(data__->TEMP,));
        };
      };
    };
    __SET_VAR(data__->,STOP,,((__GET_VAR(data__->M,) - 1) - __GET_VAR(data__->D2,)));
    __SET_VAR(data__->,START,,__GET_VAR(data__->D2,));
    if (!(EVEN(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DINT)INT_TO_DINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)__GET_VAR(data__->DISC,))))) {
      __SET_VAR(data__->,START,,(__GET_VAR(data__->START,) + 1));
    };
    __SET_VAR(data__->,AVG,,0.0);
    for(__GET_VAR(data__->I,) = __GET_VAR(data__->START,); __GET_VAR(data__->I,) <= __GET_VAR(data__->STOP,); __GET_VAR(data__->I,)++) {
      __SET_VAR(data__->,AVG,,(__GET_VAR(data__->AVG,) + __GET_VAR(data__->BUF,.table[(__GET_VAR(data__->I,)) - (0)])));
    };
    __SET_VAR(data__->,AVG,,(__GET_VAR(data__->AVG,) / INT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)((__GET_VAR(data__->STOP,) - __GET_VAR(data__->START,)) + 1))));
    __SET_VAR(data__->,LOW,,__GET_VAR(data__->BUF,.table[(__GET_VAR(data__->START,)) - (0)]));
    __SET_VAR(data__->,HIGH,,__GET_VAR(data__->BUF,.table[(__GET_VAR(data__->STOP,)) - (0)]));
  } else {
    __SET_VAR(data__->,TRIG,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // SH_2_body__() 





void DELAY_4_init__(DELAY_4 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->OUT1,0,retain)
  __INIT_VAR(data__->OUT2,0,retain)
  __INIT_VAR(data__->OUT3,0,retain)
  __INIT_VAR(data__->OUT4,0,retain)
  __INIT_VAR(data__->TEMP,0,retain)
}

// Code part
void DELAY_4_body__(DELAY_4 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,OUT4,,__GET_VAR(data__->OUT3,));
  __SET_VAR(data__->,OUT3,,__GET_VAR(data__->OUT2,));
  __SET_VAR(data__->,OUT2,,__GET_VAR(data__->OUT1,));
  __SET_VAR(data__->,OUT1,,__GET_VAR(data__->TEMP,));
  __SET_VAR(data__->,TEMP,,__GET_VAR(data__->IN,));

  goto __end;

__end:
  return;
} // DELAY_4_body__() 





// FUNCTION
REAL SCALE_B2(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE IN1, 
  BYTE IN2, 
  REAL K, 
  REAL O, 
  REAL IN1_MIN, 
  REAL IN1_MAX, 
  REAL IN2_MIN, 
  REAL IN2_MAX)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL SCALE_B2 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SCALE_B2;
  }
  SCALE_B2 = ((((((((IN1_MAX - IN1_MIN) * BYTE_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)IN1)) + ((IN2_MAX - IN2_MIN) * BYTE_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)IN2))) * 0.003921569) + IN1_MIN) + IN2_MIN) * K) + O);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SCALE_B2;
}


// FUNCTION
REAL SCALE_B4(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE IN1, 
  BYTE IN2, 
  BYTE IN3, 
  BYTE IN4, 
  REAL K, 
  REAL O, 
  REAL IN1_MIN, 
  REAL IN1_MAX, 
  REAL IN2_MIN, 
  REAL IN2_MAX, 
  REAL IN3_MIN, 
  REAL IN3_MAX, 
  REAL IN4_MIN, 
  REAL IN4_MAX)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL SCALE_B4 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SCALE_B4;
  }
  SCALE_B4 = ((((((((((((IN1_MAX - IN1_MIN) * BYTE_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)IN1)) + ((IN2_MAX - IN2_MIN) * BYTE_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)IN2))) + ((IN3_MAX - IN3_MIN) * BYTE_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)IN3))) + ((IN4_MAX - IN4_MIN) * BYTE_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)IN4))) * 0.003921569) + IN1_MIN) + IN2_MIN) + IN3_MIN) + IN4_MIN) * K) + O);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SCALE_B4;
}


void TREND_init__(TREND *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TU,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_D,0,retain)
  __INIT_VAR(data__->LAST_X,0,retain)
}

// Code part
void TREND_body__(TREND *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,TU,,(__GET_VAR(data__->X,) > __GET_VAR(data__->LAST_X,)));
  __SET_VAR(data__->,TD,,(__GET_VAR(data__->X,) < __GET_VAR(data__->LAST_X,)));
  __SET_VAR(data__->,Q,,(__GET_VAR(data__->TU,) || __GET_VAR(data__->TD,)));
  __SET_VAR(data__->,_D,,(__GET_VAR(data__->X,) - __GET_VAR(data__->LAST_X,)));
  __SET_VAR(data__->,LAST_X,,__GET_VAR(data__->X,));

  goto __end;

__end:
  return;
} // TREND_body__() 





// FUNCTION
REAL SCALE_B8(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE IN1, 
  BYTE IN2, 
  BYTE IN3, 
  BYTE IN4, 
  BYTE IN5, 
  BYTE IN6, 
  BYTE IN7, 
  BYTE IN8, 
  REAL K, 
  REAL O, 
  REAL IN1_MIN, 
  REAL IN1_MAX, 
  REAL IN2_MIN, 
  REAL IN2_MAX, 
  REAL IN3_MIN, 
  REAL IN3_MAX, 
  REAL IN4_MIN, 
  REAL IN4_MAX, 
  REAL IN5_MIN, 
  REAL IN5_MAX, 
  REAL IN6_MIN, 
  REAL IN6_MAX, 
  REAL IN7_MIN, 
  REAL IN7_MAX, 
  REAL IN8_MIN, 
  REAL IN8_MAX)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL SCALE_B8 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SCALE_B8;
  }
  SCALE_B8 = ((((((((((((((((((((IN1_MAX - IN1_MIN) * BYTE_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)IN1)) + ((IN2_MAX - IN2_MIN) * BYTE_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)IN2))) + ((IN3_MAX - IN3_MIN) * BYTE_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)IN3))) + ((IN4_MAX - IN4_MIN) * BYTE_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)IN4))) + ((IN5_MAX - IN5_MIN) * BYTE_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)IN5))) + ((IN6_MAX - IN6_MIN) * BYTE_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)IN6))) + ((IN7_MAX - IN7_MIN) * BYTE_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)IN7))) + ((IN8_MAX - IN8_MIN) * BYTE_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)IN8))) * 0.003921569) + IN1_MIN) + IN2_MIN) + IN3_MIN) + IN4_MIN) + IN5_MIN) + IN6_MIN) + IN7_MIN) + IN8_MIN) * K) + O);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SCALE_B8;
}


// FUNCTION
DWORD AOUT1(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN, 
  INT BIT_0, 
  INT BIT_N, 
  INT SIGN, 
  REAL LOW, 
  REAL HIGH, 
  REAL IN2, 
  BOOL SX)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  DWORD AOUT1 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return AOUT1;
  }
  if ((SIGN < 32)) {
    SX = SIGN_R(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)IN);
    IN2 = ABS__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)IN);
  } else {
    SX = __BOOL_LITERAL(FALSE);
    IN2 = IN;
  };
  IN2 = LIMIT__REAL__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)LOW,
    (REAL)IN2,
    (REAL)HIGH);
  AOUT1 = SHL__DWORD__DWORD__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)REAL_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(((IN2 - LOW) / (HIGH - LOW)) * UDINT_TO_REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)(DWORD_TO_UDINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)SHL__DWORD__DWORD__INT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (DWORD)__DWORD_LITERAL(0x1),
            (INT)((BIT_N - BIT_0) + 1))) - __UDINT_LITERAL(1))))),
    (INT)BIT_0);
  if (SX) {
    AOUT1 = (SHL__DWORD__DWORD__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)__DWORD_LITERAL(0x1),
      (INT)SIGN) | AOUT1);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return AOUT1;
}


// FUNCTION
REAL SCALE_B(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE X, 
  BYTE I_LO, 
  BYTE I_HI, 
  REAL O_LO, 
  REAL O_HI)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL SCALE_B = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SCALE_B;
  }
  if ((I_HI == I_LO)) {
    SCALE_B = O_LO;
  } else {
    SCALE_B = (((O_HI - O_LO) / USINT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (USINT)(BYTE_TO_USINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)I_HI) - BYTE_TO_USINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)I_LO)))) * BYTE_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)LIMIT__BYTE__BYTE__BYTE__BYTE(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)I_LO,
        (BYTE)X,
        (BYTE)I_HI)));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SCALE_B;
}


// FUNCTION
REAL SCALE_D(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD X, 
  DWORD I_LO, 
  DWORD I_HI, 
  REAL O_LO, 
  REAL O_HI)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL SCALE_D = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SCALE_D;
  }
  if ((I_HI == I_LO)) {
    SCALE_D = O_LO;
  } else {
    SCALE_D = ((((O_HI - O_LO) / UDINT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)(DWORD_TO_UDINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)I_HI) - DWORD_TO_UDINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)I_LO)))) * UDINT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)(LIMIT__UDINT__UDINT__UDINT__UDINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)DWORD_TO_UDINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)I_LO),
        (UDINT)DWORD_TO_UDINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)X),
        (UDINT)DWORD_TO_UDINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)I_HI)) - DWORD_TO_UDINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)I_LO)))) + O_LO);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SCALE_D;
}


void SEL2_OF_3B_init__(SEL2_OF_3B *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TD,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->W,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TDEL,retain);
}

// Code part
void SEL2_OF_3B_body__(SEL2_OF_3B *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,Q,,(((__GET_VAR(data__->IN1,) && __GET_VAR(data__->IN2,)) || (__GET_VAR(data__->IN1,) && __GET_VAR(data__->IN3,))) || (__GET_VAR(data__->IN2,) && __GET_VAR(data__->IN3,))));
  __SET_VAR(data__->TDEL.,IN,,(((__GET_VAR(data__->IN1,) && !__GET_VAR(data__->IN2,)) || (!__GET_VAR(data__->IN1,) && __GET_VAR(data__->IN2,)) || (__GET_VAR(data__->IN1,) && !__GET_VAR(data__->IN3,)) || (!__GET_VAR(data__->IN1,) && __GET_VAR(data__->IN3,))) || (__GET_VAR(data__->IN2,) && !__GET_VAR(data__->IN3,)) || (!__GET_VAR(data__->IN2,) && __GET_VAR(data__->IN3,))));
  __SET_VAR(data__->TDEL.,PT,,__GET_VAR(data__->TD,));
  TON_body__(&data__->TDEL);
  __SET_VAR(data__->,W,,__GET_VAR(data__->TDEL.Q,));

  goto __end;

__end:
  return;
} // SEL2_OF_3B_body__() 





void FILTER_MAV_W_init__(FILTER_MAV_W *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  {
    static const __ARRAY_OF_WORD_32 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,BUFFER,,temp);
  }
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->SUM,0,retain)
  __INIT_VAR(data__->TMP,0,retain)
}

// Code part
void FILTER_MAV_W_body__(FILTER_MAV_W *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,N,,MIN__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__UINT_LITERAL(32)));
  if (((!(__GET_VAR(data__->INIT,)) || __GET_VAR(data__->RST,)) || (__GET_VAR(data__->N,) == __UINT_LITERAL(0)))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,TMP,,(UINT_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)__GET_VAR(data__->N,)) - 1));
    for(__GET_VAR(data__->I,) = 1; __GET_VAR(data__->I,) <= __GET_VAR(data__->TMP,); __GET_VAR(data__->I,)++) {
      __SET_VAR(data__->,BUFFER,.table[(__GET_VAR(data__->I,)) - (0)],__GET_VAR(data__->X,));
    };
    __SET_VAR(data__->,SUM,,UINT_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)(WORD_TO_UINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->Y,)) * __GET_VAR(data__->N,))));
    __SET_VAR(data__->,Y,,__GET_VAR(data__->X,));
  } else {
    __SET_VAR(data__->,TMP,,UINT_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)__GET_VAR(data__->N,)));
    __SET_VAR(data__->,I,,INC1(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)__GET_VAR(data__->I,),
      (INT)__GET_VAR(data__->TMP,)));
    __SET_VAR(data__->,SUM,,((__GET_VAR(data__->SUM,) + WORD_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (WORD)__GET_VAR(data__->X,))) - WORD_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (WORD)__GET_VAR(data__->BUFFER,.table[(__GET_VAR(data__->I,)) - (0)]))));
    __SET_VAR(data__->,Y,,UDINT_TO_WORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)(__GET_VAR(data__->SUM,) / UINT_TO_UDINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UINT)__GET_VAR(data__->N,)))));
    __SET_VAR(data__->,BUFFER,.table[(__GET_VAR(data__->I,)) - (0)],__GET_VAR(data__->X,));
  };

  goto __end;

__end:
  return;
} // FILTER_MAV_W_body__() 





// FUNCTION
REAL SCALE_R(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL I_LO, 
  REAL I_HI, 
  REAL O_LO, 
  REAL O_HI)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL SCALE_R = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SCALE_R;
  }
  if ((I_LO == I_HI)) {
    SCALE_R = O_LO;
  } else {
    SCALE_R = ((((O_HI - O_LO) / (I_HI - I_LO)) * (LIMIT__REAL__REAL__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)I_LO,
      (REAL)X,
      (REAL)I_HI) - I_LO)) + O_LO);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SCALE_R;
}


// FUNCTION
REAL MUX_R2(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN0, 
  REAL IN1, 
  BOOL A)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL MUX_R2 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return MUX_R2;
  }
  MUX_R2 = SEL__REAL__BOOL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)A,
    (REAL)IN0,
    (REAL)IN1);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return MUX_R2;
}


void TREND_DW_init__(TREND_DW *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TU,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_D,0,retain)
  __INIT_VAR(data__->LAST_X,0,retain)
}

// Code part
void TREND_DW_body__(TREND_DW *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->X,) > __GET_VAR(data__->LAST_X,))) {
    __SET_VAR(data__->,TU,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,TD,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,_D,,UDINT_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)(DWORD_TO_UDINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)__GET_VAR(data__->X,)) - DWORD_TO_UDINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)__GET_VAR(data__->LAST_X,)))));
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
  } else if ((__GET_VAR(data__->X,) < __GET_VAR(data__->LAST_X,))) {
    __SET_VAR(data__->,TD,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,TU,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,_D,,UDINT_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)(DWORD_TO_UDINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)__GET_VAR(data__->LAST_X,)) - DWORD_TO_UDINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)__GET_VAR(data__->X,)))));
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  } else {
    __SET_VAR(data__->,TU,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,TD,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,_D,,__DWORD_LITERAL(0));
  };
  __SET_VAR(data__->,LAST_X,,__GET_VAR(data__->X,));

  goto __end;

__end:
  return;
} // TREND_DW_body__() 





// FUNCTION
INT DEC1(
  BOOL EN, 
  BOOL *__ENO, 
  INT X, 
  INT N)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT DEC1 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DEC1;
  }
  if ((X == 0)) {
    DEC1 = (N - 1);
  } else {
    DEC1 = (X - 1);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return DEC1;
}


void FILTER_WAV_init__(FILTER_WAV *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X,0,retain)
  {
    static const __ARRAY_OF_REAL_16 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,W,,temp);
  }
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  {
    static const __ARRAY_OF_REAL_16 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,BUFFER,,temp);
  }
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->N,0,retain)
}

// Code part
void FILTER_WAV_body__(FILTER_WAV *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((!(__GET_VAR(data__->INIT,)) || __GET_VAR(data__->RST,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    for(__GET_VAR(data__->I,) = 0; __GET_VAR(data__->I,) <= 15; __GET_VAR(data__->I,)++) {
      __SET_VAR(data__->,BUFFER,.table[(__GET_VAR(data__->I,)) - (0)],__GET_VAR(data__->X,));
    };
    __SET_VAR(data__->,I,,15);
    __SET_VAR(data__->,Y,,__GET_VAR(data__->X,));
  } else {
    __SET_VAR(data__->,I,,INC1(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)__GET_VAR(data__->I,),
      (INT)16));
    __SET_VAR(data__->,BUFFER,.table[(__GET_VAR(data__->I,)) - (0)],__GET_VAR(data__->X,));
  };
  __SET_VAR(data__->,Y,,0.0);
  for(__GET_VAR(data__->N,) = 0; __GET_VAR(data__->N,) <= 15; __GET_VAR(data__->N,)++) {
    __SET_VAR(data__->,Y,,((__GET_VAR(data__->BUFFER,.table[(__GET_VAR(data__->I,)) - (0)]) * __GET_VAR(data__->W,.table[(__GET_VAR(data__->N,)) - (0)])) + __GET_VAR(data__->Y,)));
    __SET_VAR(data__->,I,,DEC1(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)__GET_VAR(data__->I,),
      (INT)16));
  };

  goto __end;

__end:
  return;
} // FILTER_WAV_body__() 





