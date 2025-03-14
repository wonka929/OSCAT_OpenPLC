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
DINT D_TRUNC(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  DINT D_TRUNC = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return D_TRUNC;
  }
  D_TRUNC = REAL_TO_DINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)X);
  if ((X > 0.0)) {
    if ((DINT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DINT)D_TRUNC) > X)) {
      D_TRUNC = (D_TRUNC - __DINT_LITERAL(1));
    };
  } else {
    if ((DINT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DINT)D_TRUNC) < X)) {
      D_TRUNC = (D_TRUNC + __DINT_LITERAL(1));
    };
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return D_TRUNC;
}


// FUNCTION
REAL FRACT(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL FRACT = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return FRACT;
  }
  if ((ABS__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)X) < 2.0E9)) {
    FRACT = (X - DINT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DINT)D_TRUNC(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)X)));
  } else {
    FRACT = 0.0;
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return FRACT;
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


// FUNCTION
DWORD BIT_LOAD_DW(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN, 
  BOOL VAL, 
  INT POS)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  DWORD BIT_LOAD_DW = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return BIT_LOAD_DW;
  }
  if (VAL) {
    BIT_LOAD_DW = (IN | SHL__DWORD__DWORD__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)__DWORD_LITERAL(1),
      (INT)POS));
  } else {
    BIT_LOAD_DW = (IN & ~(SHL__DWORD__DWORD__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)__DWORD_LITERAL(1),
      (INT)POS)));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return BIT_LOAD_DW;
}


// FUNCTION
INT BIT_COUNT(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  DWORD IN_TEMP = 0;
  INT BIT_COUNT = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return BIT_COUNT;
  }
  IN_TEMP = IN;
  while ((IN_TEMP > __DWORD_LITERAL(0))) {
    if (((IN_TEMP & __DWORD_LITERAL(0x1)) > __DWORD_LITERAL(0))) {
      BIT_COUNT = (BIT_COUNT + 1);
    };
    IN_TEMP = SHR__DWORD__DWORD__SINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN_TEMP,
      (SINT)1);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return BIT_COUNT;
}


void RDM_init__(RDM *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->LAST,0,retain)
  __INIT_VAR(data__->_RDM,0,retain)
  __INIT_VAR(data__->TN,0,retain)
  __INIT_VAR(data__->TC,0,retain)
}

// Code part
void RDM_body__(RDM *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,TN,,UDINT_TO_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)T_PLC_MS(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__BOOL_LITERAL(FALSE))));
  __SET_VAR(data__->,TC,,BIT_COUNT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)__GET_VAR(data__->TN,)));
  __SET_VAR(data__->,TN,,BIT_LOAD_DW(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)__GET_VAR(data__->TN,),
    (BOOL)BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)__GET_VAR(data__->TN,),
      (INT)2),
    (INT)31));
  __SET_VAR(data__->,TN,,BIT_LOAD_DW(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)__GET_VAR(data__->TN,),
    (BOOL)BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)__GET_VAR(data__->TN,),
      (INT)5),
    (INT)30));
  __SET_VAR(data__->,TN,,BIT_LOAD_DW(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)__GET_VAR(data__->TN,),
    (BOOL)BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)__GET_VAR(data__->TN,),
      (INT)4),
    (INT)29));
  __SET_VAR(data__->,TN,,BIT_LOAD_DW(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)__GET_VAR(data__->TN,),
    (BOOL)BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)__GET_VAR(data__->TN,),
      (INT)1),
    (INT)28));
  __SET_VAR(data__->,TN,,BIT_LOAD_DW(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)__GET_VAR(data__->TN,),
    (BOOL)BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)__GET_VAR(data__->TN,),
      (INT)0),
    (INT)27));
  __SET_VAR(data__->,TN,,BIT_LOAD_DW(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)__GET_VAR(data__->TN,),
    (BOOL)BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)__GET_VAR(data__->TN,),
      (INT)7),
    (INT)26));
  __SET_VAR(data__->,TN,,BIT_LOAD_DW(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)__GET_VAR(data__->TN,),
    (BOOL)BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)__GET_VAR(data__->TN,),
      (INT)6),
    (INT)25));
  __SET_VAR(data__->,TN,,BIT_LOAD_DW(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)__GET_VAR(data__->TN,),
    (BOOL)BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)__GET_VAR(data__->TN,),
      (INT)3),
    (INT)24));
  __SET_VAR(data__->,TN,,(ROL__DWORD__DWORD__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)__GET_VAR(data__->TN,),
    (INT)BIT_COUNT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)__GET_VAR(data__->TN,))) | __DWORD_LITERAL(0x80000001)));
  __SET_VAR(data__->,TN,,UDINT_TO_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)((((__UDINT_LITERAL(71474513) == 0)?0:(DWORD_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)__GET_VAR(data__->TN,)) % __UDINT_LITERAL(71474513))) + INT_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)__GET_VAR(data__->TC,))) + __UDINT_LITERAL(77))));
  __SET_VAR(data__->,_RDM,,FRACT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)((DWORD_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)__GET_VAR(data__->TN,)) / 10000000.0) * (2.71828182845904523536028747135266249 - LIMIT__REAL__REAL__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)0.0,
      (REAL)__GET_VAR(data__->LAST,),
      (REAL)1.0)))));

  goto __end;

__end:
  return;
} // RDM_body__() 





void GEN_RDT_init__(GEN_RDT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENABLE,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->MIN_TIME_MS,__time_to_timespec(1, 0, 1, 0, 0, 0),retain)
  __INIT_VAR(data__->MAX_TIME_MS,__time_to_timespec(1, 0, 1.2, 0, 0, 0),retain)
  __INIT_VAR(data__->TP_Q,__time_to_timespec(1, 100, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->XQ,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TONRDMTIMER,retain);
  TOF_init__(&data__->TOF_XQ,retain);
  __INIT_VAR(data__->TRDMTIME,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->RRDMTIME,0,retain)
  RDM_init__(&data__->RDM_1,retain);
}

// Code part
void GEN_RDT_body__(GEN_RDT *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->TONRDMTIMER.,IN,,__GET_VAR(data__->ENABLE,));
  __SET_VAR(data__->TONRDMTIMER.,PT,,__GET_VAR(data__->TRDMTIME,));
  TON_body__(&data__->TONRDMTIMER);
  __SET_VAR(data__->TOF_XQ.,IN,,__GET_VAR(data__->TONRDMTIMER.Q,));
  __SET_VAR(data__->TOF_XQ.,PT,,__GET_VAR(data__->TP_Q,));
  TOF_body__(&data__->TOF_XQ);
  __SET_VAR(data__->,XQ,,__GET_VAR(data__->TOF_XQ.Q,));
  if (__GET_VAR(data__->TONRDMTIMER.Q,)) {
    __SET_VAR(data__->,XQ,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->RDM_1.,LAST,,__GET_VAR(data__->RRDMTIME,));
    RDM_body__(&data__->RDM_1);
    __SET_VAR(data__->,RRDMTIME,,__GET_VAR(data__->RDM_1._RDM,));
    __SET_VAR(data__->,TRDMTIME,,REAL_TO_TIME(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)((__GET_VAR(data__->RRDMTIME,) * TIME_TO_REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (TIME)__time_sub(__GET_VAR(data__->MAX_TIME_MS,), __GET_VAR(data__->MIN_TIME_MS,)))) + TIME_TO_REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (TIME)__GET_VAR(data__->MIN_TIME_MS,)))));
    __SET_VAR(data__->TONRDMTIMER.,IN,,__BOOL_LITERAL(FALSE));
    TON_body__(&data__->TONRDMTIMER);
  };

  goto __end;

__end:
  return;
} // GEN_RDT_body__() 





void TP_X_init__(TP_X *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->START,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
}

// Code part
void TP_X_body__(TP_X *data__) {
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
  if ((__GET_VAR(data__->IN,) && !(__GET_VAR(data__->EDGE,)))) {
    __SET_VAR(data__->,START,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,Q,,GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->PT,), __time_to_timespec(1, 0, 0, 0, 0, 0)));
  } else if (__GET_VAR(data__->Q,)) {
    __SET_VAR(data__->,ET,,__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->START,)));
    if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->ET,), __GET_VAR(data__->PT,))) {
      __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,ET,,__time_to_timespec(1, 0, 0, 0, 0, 0));
    };
  };
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->IN,));

  goto __end;

__end:
  return;
} // TP_X_body__() 





void CLK_PRG_init__(CLK_PRG *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->PT,__time_to_timespec(1, 10, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
}

// Code part
void CLK_PRG_body__(CLK_PRG *data__) {
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
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,LAST,,__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->PT,)));
  };
  __SET_VAR(data__->,Q,,GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->PT,)));
  if (__GET_VAR(data__->Q,)) {
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
  };

  goto __end;

__end:
  return;
} // CLK_PRG_body__() 





void PWM_PW_init__(PWM_PW *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->F,0,retain)
  __INIT_VAR(data__->PW,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  CLK_PRG_init__(&data__->CLK,retain);
  TP_X_init__(&data__->PULSE,retain);
}

// Code part
void PWM_PW_body__(PWM_PW *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->F,) > 0.0)) {
    __SET_VAR(data__->CLK.,PT,,REAL_TO_TIME(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(1000.0 / __GET_VAR(data__->F,))));
    CLK_PRG_body__(&data__->CLK);
    __SET_VAR(data__->PULSE.,IN,,__GET_VAR(data__->CLK.Q,));
    __SET_VAR(data__->PULSE.,PT,,__GET_VAR(data__->PW,));
    TP_X_body__(&data__->PULSE);
    __SET_VAR(data__->,Q,,__GET_VAR(data__->PULSE.Q,));
  };

  goto __end;

__end:
  return;
} // PWM_PW_body__() 





void GEN_RDM_init__(GEN_RDM *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->PT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->AM,1.0,retain)
  __INIT_VAR(data__->OS,0,retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT,0,retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  RDM_init__(&data__->FB_RDM,retain);
}

// Code part
void GEN_RDM_body__(GEN_RDM *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,TX,,__time_sub(UDINT_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)T_PLC_MS(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__BOOL_LITERAL(FALSE))), __GET_VAR(data__->LAST,)));
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,TX,,__time_to_timespec(1, 0, 0, 0, 0, 0));
  };
  if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TX,), __GET_VAR(data__->PT,))) {
    __SET_VAR(data__->,LAST,,__time_add(__GET_VAR(data__->LAST,), __GET_VAR(data__->PT,)));
    __SET_VAR(data__->,TX,,__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->PT,)));
    __SET_VAR(data__->FB_RDM.,LAST,,0.0);
    RDM_body__(&data__->FB_RDM);
    __SET_VAR(data__->,OUT,,((__GET_VAR(data__->AM,) * (__GET_VAR(data__->FB_RDM._RDM,) - 0.5)) + __GET_VAR(data__->OS,)));
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
  } else {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // GEN_RDM_body__() 





// FUNCTION
DINT FLOOR2(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  DINT FLOOR2 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return FLOOR2;
  }
  FLOOR2 = REAL_TO_DINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)X);
  if ((DINT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DINT)FLOOR2) > X)) {
    FLOOR2 = (FLOOR2 - __DINT_LITERAL(1));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return FLOOR2;
}


// FUNCTION
REAL MODR(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN, 
  REAL DIVI)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL MODR = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return MODR;
  }
  if ((DIVI == 0.0)) {
    MODR = 0.0;
  } else {
    MODR = (IN - (DINT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DINT)FLOOR2(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)(IN / DIVI))) * DIVI));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return MODR;
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





// FUNCTION
BYTE FRMP_B(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE START, 
  BOOL DIR, 
  TIME TD, 
  TIME TR)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BYTE FRMP_B = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return FRMP_B;
  }
  if (LT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, TD, TR)) {
    FRMP_B = MIN__BYTE__BYTE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)2,
      (BYTE)UDINT_TO_BYTE(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)(DWORD_TO_UDINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)SHL__DWORD__DWORD__SINT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (DWORD)TIME_TO_DWORD(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (TIME)TD),
            (SINT)8)) / TIME_TO_UDINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (TIME)TR))),
      (BYTE)SEL__BYTE__BOOL__BYTE__BYTE(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BOOL)DIR,
        (BYTE)START,
        (BYTE)USINT_TO_BYTE(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (USINT)(__USINT_LITERAL(255) - BYTE_TO_USINT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (BYTE)START)))));
    if (DIR) {
      FRMP_B = USINT_TO_BYTE(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (USINT)(BYTE_TO_USINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)START) + BYTE_TO_USINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)FRMP_B)));
    } else {
      FRMP_B = USINT_TO_BYTE(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (USINT)(BYTE_TO_USINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)START) - BYTE_TO_USINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)FRMP_B)));
    };
  } else {
    FRMP_B = SEL__BYTE__BOOL__BYTE__BYTE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)DIR,
      (BYTE)__BYTE_LITERAL(0),
      (BYTE)__BYTE_LITERAL(255));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return FRMP_B;
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


void _RMP_B_init__(_RMP_B *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->DIR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_E,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TR,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->RMP,0,retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TL,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TN,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LAST_DIR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->START,0,retain)
}

// Code part
void _RMP_B_body__(_RMP_B *data__) {
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
  if (((((__GET_VAR(data__->_E,) && __GET_VAR(data__->INIT,)) && (__GET_VAR(data__->DIR,) == __GET_VAR(data__->LAST_DIR,))) && (__GET_VAR(data__->RMP,) != SEL__BYTE__BOOL__BYTE__BYTE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->DIR,),
    (BYTE)__BYTE_LITERAL(0),
    (BYTE)__BYTE_LITERAL(255)))) && EQ_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TR,), __GET_VAR(data__->TN,)))) {
    __SET_VAR(data__->,RMP,,FRMP_B(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->START,),
      (BOOL)__GET_VAR(data__->DIR,),
      (TIME)__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->TL,)),
      (TIME)__GET_VAR(data__->TR,)));
  } else {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,TL,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,TN,,__GET_VAR(data__->TR,));
    __SET_VAR(data__->,START,,__GET_VAR(data__->RMP,));
  };
  __SET_VAR(data__->,LAST_DIR,,__GET_VAR(data__->DIR,));

  goto __end;

__end:
  return;
} // _RMP_B_body__() 





void RMP_B_init__(RMP_B *data__, BOOL retain) {
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
  _RMP_B_init__(&data__->RMP,retain);
}

// Code part
void RMP_B_body__(RMP_B *data__) {
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
  _RMP_B_body__(&data__->RMP);
  __SET_VAR(data__->,OUT,,__GET_VAR(data__->RMP.RMP));
  __SET_VAR(data__->,OUT,,__GET_VAR(data__->RMP.RMP,));
  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,OUT,,__BYTE_LITERAL(0));
  } else if (__GET_VAR(data__->SET,)) {
    __SET_VAR(data__->,OUT,,__BYTE_LITERAL(255));
  };
  __SET_VAR(data__->,LOW,,(__GET_VAR(data__->OUT,) == __BYTE_LITERAL(0)));
  __SET_VAR(data__->,HIGH,,(__GET_VAR(data__->OUT,) == __BYTE_LITERAL(255)));
  __SET_VAR(data__->,BUSY,,(!((__GET_VAR(data__->LOW,) || __GET_VAR(data__->HIGH,))) && __GET_VAR(data__->_E,)));

  goto __end;

__end:
  return;
} // RMP_B_body__() 





void GEN_SQR_init__(GEN_SQR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->PT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->AM,1.0,retain)
  __INIT_VAR(data__->OS,0,retain)
  __INIT_VAR(data__->DL,0,retain)
  __INIT_VAR(data__->DC,0,retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT,0,retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void GEN_SQR_body__(GEN_SQR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->DC,) == 0.0)) {
    __SET_VAR(data__->,OUT,,(( -(__GET_VAR(data__->AM,)) * 0.5) + __GET_VAR(data__->OS,)));
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
    goto __end;
  } else if ((__GET_VAR(data__->DC,) == 1.0)) {
    __SET_VAR(data__->,OUT,,((__GET_VAR(data__->AM,) * 0.5) + __GET_VAR(data__->OS,)));
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
    goto __end;
  };
  __SET_VAR(data__->,TX,,__time_sub(UDINT_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)T_PLC_MS(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__BOOL_LITERAL(FALSE))), __GET_VAR(data__->LAST,)));
  __SET_VAR(data__->,DL,,MODR(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->DL,),
    (REAL)1.0));
  if ((__GET_VAR(data__->DL,) < 0.0)) {
    __SET_VAR(data__->,DL,,(1.0 - __GET_VAR(data__->DL,)));
  };
  __SET_VAR(data__->,DC,,MODR(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->DC,),
    (REAL)1.0));
  if ((__GET_VAR(data__->DC,) < 0.0)) {
    __SET_VAR(data__->,DC,,(1.0 - __GET_VAR(data__->DC,)));
  };
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,TX,,__time_to_timespec(1, 0, 0, 0, 0, 0));
  };
  if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TX,), __GET_VAR(data__->PT,))) {
    __SET_VAR(data__->,LAST,,__time_add(__GET_VAR(data__->LAST,), __GET_VAR(data__->PT,)));
    __SET_VAR(data__->,TX,,__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->PT,)));
  };
  if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, MULTIME__TIME__TIME__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (TIME)__GET_VAR(data__->PT,),
    (REAL)(__GET_VAR(data__->DL,) + __GET_VAR(data__->DC,))), __GET_VAR(data__->PT,))) {
    if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TX,), MULTIME__TIME__TIME__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)__GET_VAR(data__->PT,),
      (REAL)((__GET_VAR(data__->DL,) + __GET_VAR(data__->DC,)) - 1.0)))) {
      __SET_VAR(data__->,OUT,,(( -(__GET_VAR(data__->AM,)) * 0.5) + __GET_VAR(data__->OS,)));
      __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
    };
    if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TX,), MULTIME__TIME__TIME__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)__GET_VAR(data__->PT,),
      (REAL)__GET_VAR(data__->DL,)))) {
      __SET_VAR(data__->,OUT,,((__GET_VAR(data__->AM,) * 0.5) + __GET_VAR(data__->OS,)));
      __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
    };
  } else {
    if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TX,), MULTIME__TIME__TIME__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)__GET_VAR(data__->PT,),
      (REAL)__GET_VAR(data__->DL,)))) {
      __SET_VAR(data__->,OUT,,((__GET_VAR(data__->AM,) * 0.5) + __GET_VAR(data__->OS,)));
      __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
    };
    if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TX,), MULTIME__TIME__TIME__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)__GET_VAR(data__->PT,),
      (REAL)(__GET_VAR(data__->DL,) + __GET_VAR(data__->DC,))))) {
      __SET_VAR(data__->,OUT,,(( -(__GET_VAR(data__->AM,)) * 0.5) + __GET_VAR(data__->OS,)));
      __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
    };
  };

  goto __end;

__end:
  return;
} // GEN_SQR_body__() 





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





void _RMP_NEXT_init__(_RMP_NEXT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->_E,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->TR,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TF,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TL,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DIR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT,0,retain)
  _RMP_B_init__(&data__->RMX,retain);
  TREND_DW_init__(&data__->DIRX,retain);
  TP_init__(&data__->T_LOCK,retain);
  __INIT_VAR(data__->XEN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->XDIR,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void _RMP_NEXT_body__(_RMP_NEXT *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->DIRX.,X,,BYTE_TO_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)__GET_VAR(data__->IN,)));
  TREND_DW_body__(&data__->DIRX);
  __SET_VAR(data__->T_LOCK.,IN,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->T_LOCK.,PT,,__GET_VAR(data__->TL,));
  TP_body__(&data__->T_LOCK);
  if ((__GET_VAR(data__->DIRX.TU,) && (__GET_VAR(data__->OUT,) < __GET_VAR(data__->IN,)))) {
    if ((!(__GET_VAR(data__->XDIR,)) && __GET_VAR(data__->XEN,))) {
      __SET_VAR(data__->T_LOCK.,IN,,__BOOL_LITERAL(TRUE));
      TP_body__(&data__->T_LOCK);
    };
    __SET_VAR(data__->,XEN,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,XDIR,,__BOOL_LITERAL(TRUE));
  } else if ((__GET_VAR(data__->DIRX.TD,) && (__GET_VAR(data__->OUT,) > __GET_VAR(data__->IN,)))) {
    if ((__GET_VAR(data__->XDIR,) && __GET_VAR(data__->XEN,))) {
      __SET_VAR(data__->T_LOCK.,IN,,__BOOL_LITERAL(TRUE));
      TP_body__(&data__->T_LOCK);
    };
    __SET_VAR(data__->,XEN,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,XDIR,,__BOOL_LITERAL(FALSE));
  } else if (__GET_VAR(data__->XEN,)) {
    if (((__GET_VAR(data__->XDIR,) && (__GET_VAR(data__->OUT,) >= __GET_VAR(data__->IN,))) || (!(__GET_VAR(data__->XDIR,)) && (__GET_VAR(data__->OUT,) <= __GET_VAR(data__->IN,))))) {
      __SET_VAR(data__->,XEN,,__BOOL_LITERAL(FALSE));
      if (GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TL,), __time_to_timespec(1, 0, 0, 0, 0, 0))) {
        __SET_VAR(data__->T_LOCK.,IN,,__BOOL_LITERAL(TRUE));
        TP_body__(&data__->T_LOCK);
      };
    };
  };
  if ((!(__GET_VAR(data__->T_LOCK.Q,)) && __GET_VAR(data__->XEN,))) {
    __SET_VAR(data__->,UP,,__GET_VAR(data__->XDIR,));
    __SET_VAR(data__->,DIR,,__GET_VAR(data__->XDIR,));
    __SET_VAR(data__->,DN,,!(__GET_VAR(data__->XDIR,)));
  } else {
    __SET_VAR(data__->,UP,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,DN,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->RMX.,DIR,,__GET_VAR(data__->DIR,));
  __SET_VAR(data__->RMX.,_E,,(__GET_VAR(data__->_E,) && (__GET_VAR(data__->UP,) || __GET_VAR(data__->DN,))));
  __SET_VAR(data__->RMX.,TR,,SEL__TIME__BOOL__TIME__TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->DIR,),
    (TIME)__GET_VAR(data__->TF,),
    (TIME)__GET_VAR(data__->TR,)));
  __SET_VAR(data__->RMX.,RMP,,__GET_VAR(data__->OUT,));
  _RMP_B_body__(&data__->RMX);
  __SET_VAR(data__->,OUT,,__GET_VAR(data__->RMX.RMP));
  __SET_VAR(data__->,OUT,,__GET_VAR(data__->RMX.RMP,));

  goto __end;

__end:
  return;
} // _RMP_NEXT_body__() 





void GEN_PW2_init__(GEN_PW2 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENQ,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TH1,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TH2,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TL1,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TL2,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TH,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TL,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T_HIGH,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T_LOW,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->START,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->ET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void GEN_PW2_body__(GEN_PW2 *data__) {
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
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,START,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,TH,,__time_to_timespec(1, 0, 0, 0, 0, 0));
    __SET_VAR(data__->,TL,,__time_to_timespec(1, 0, 0, 0, 0, 0));
  };
  if (__GET_VAR(data__->TS,)) {
    __SET_VAR(data__->,T_HIGH,,__GET_VAR(data__->TH2,));
    __SET_VAR(data__->,T_LOW,,__GET_VAR(data__->TL2,));
  } else {
    __SET_VAR(data__->,T_HIGH,,__GET_VAR(data__->TH1,));
    __SET_VAR(data__->,T_LOW,,__GET_VAR(data__->TL1,));
  };
  if (__GET_VAR(data__->ENQ,)) {
    __SET_VAR(data__->,ET,,__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->START,)));
    if (!(__GET_VAR(data__->Q,))) {
      if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->ET,), __GET_VAR(data__->T_LOW,))) {
        __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
        __SET_VAR(data__->,START,,__GET_VAR(data__->TX,));
        __SET_VAR(data__->,TL,,__time_to_timespec(1, 0, 0, 0, 0, 0));
      } else {
        __SET_VAR(data__->,TL,,__GET_VAR(data__->ET,));
      };
    } else {
      if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->ET,), __GET_VAR(data__->T_HIGH,))) {
        __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
        __SET_VAR(data__->,START,,__GET_VAR(data__->TX,));
        __SET_VAR(data__->,TH,,__time_to_timespec(1, 0, 0, 0, 0, 0));
      } else {
        __SET_VAR(data__->,TH,,__GET_VAR(data__->ET,));
      };
    };
  } else {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,TH,,__time_to_timespec(1, 0, 0, 0, 0, 0));
    __SET_VAR(data__->,TL,,__time_to_timespec(1, 0, 0, 0, 0, 0));
    __SET_VAR(data__->,START,,__GET_VAR(data__->TX,));
  };

  goto __end;

__end:
  return;
} // GEN_PW2_body__() 





void RMP_SOFT_init__(RMP_SOFT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VAL,0,retain)
  __INIT_VAR(data__->PT_ON,__time_to_timespec(1, 100, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->PT_OFF,__time_to_timespec(1, 100, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->OUT,0,retain)
  _RMP_B_init__(&data__->RMP,retain);
  __INIT_VAR(data__->TMP,0,retain)
}

// Code part
void RMP_SOFT_body__(RMP_SOFT *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,TMP,,SEL__BYTE__BOOL__BYTE__BYTE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->IN,),
    (BYTE)__BYTE_LITERAL(0),
    (BYTE)__GET_VAR(data__->VAL,)));
  if ((__GET_VAR(data__->TMP,) > __GET_VAR(data__->OUT,))) {
    __SET_VAR(data__->RMP.,DIR,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->RMP.,_E,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->RMP.,TR,,__GET_VAR(data__->PT_ON,));
    __SET_VAR(data__->RMP.,RMP,,__GET_VAR(data__->OUT,));
    _RMP_B_body__(&data__->RMP);
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->RMP.RMP));
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->RMP.RMP,));
    __SET_VAR(data__->,OUT,,MIN__BYTE__BYTE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)2,
      (BYTE)__GET_VAR(data__->OUT,),
      (BYTE)__GET_VAR(data__->TMP,)));
  } else if ((__GET_VAR(data__->TMP,) < __GET_VAR(data__->OUT,))) {
    __SET_VAR(data__->RMP.,DIR,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->RMP.,_E,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->RMP.,TR,,__GET_VAR(data__->PT_OFF,));
    __SET_VAR(data__->RMP.,RMP,,__GET_VAR(data__->OUT,));
    _RMP_B_body__(&data__->RMP);
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->RMP.RMP));
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->RMP.RMP,));
    __SET_VAR(data__->,OUT,,MAX__BYTE__BYTE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)2,
      (BYTE)__GET_VAR(data__->OUT,),
      (BYTE)__GET_VAR(data__->TMP,)));
  } else {
    __SET_VAR(data__->RMP.,_E,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->RMP.,RMP,,__GET_VAR(data__->OUT,));
    _RMP_B_body__(&data__->RMP);
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->RMP.RMP));
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->RMP.RMP,));
  };

  goto __end;

__end:
  return;
} // RMP_SOFT_body__() 





void GEN_PULSE_init__(GEN_PULSE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENQ,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->PTH,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->PTL,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TN,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void GEN_PULSE_body__(GEN_PULSE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (__GET_VAR(data__->ENQ,)) {
    __SET_VAR(data__->,TX,,UDINT_TO_TIME(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)T_PLC_MS(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BOOL)__BOOL_LITERAL(FALSE))));
    if (!(__GET_VAR(data__->INIT,))) {
      __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,TN,,__GET_VAR(data__->TX,));
    };
    if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->TN,)), SEL__TIME__BOOL__TIME__TIME(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__GET_VAR(data__->Q,),
      (TIME)__GET_VAR(data__->PTL,),
      (TIME)__GET_VAR(data__->PTH,)))) {
      __SET_VAR(data__->,TN,,__time_add(__GET_VAR(data__->TN,), SEL__TIME__BOOL__TIME__TIME(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BOOL)__GET_VAR(data__->Q,),
        (TIME)__GET_VAR(data__->PTL,),
        (TIME)__GET_VAR(data__->PTH,))));
      __SET_VAR(data__->,Q,,!(__GET_VAR(data__->Q,)));
    };
  } else {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // GEN_PULSE_body__() 





void PWM_DC_init__(PWM_DC *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->F,0,retain)
  __INIT_VAR(data__->DC,0,retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  CLK_PRG_init__(&data__->CLK,retain);
  TP_X_init__(&data__->PULSE,retain);
  __INIT_VAR(data__->TMP,0,retain)
}

// Code part
void PWM_DC_body__(PWM_DC *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->F,) > 0.0)) {
    __SET_VAR(data__->,TMP,,(1000.0 / __GET_VAR(data__->F,)));
    __SET_VAR(data__->CLK.,PT,,REAL_TO_TIME(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)__GET_VAR(data__->TMP,)));
    CLK_PRG_body__(&data__->CLK);
    __SET_VAR(data__->PULSE.,IN,,__GET_VAR(data__->CLK.Q,));
    __SET_VAR(data__->PULSE.,PT,,REAL_TO_TIME(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(__GET_VAR(data__->TMP,) * __GET_VAR(data__->DC,))));
    TP_X_body__(&data__->PULSE);
    __SET_VAR(data__->,Q,,__GET_VAR(data__->PULSE.Q,));
  };

  goto __end;

__end:
  return;
} // PWM_DC_body__() 





void GEN_RMP_init__(GEN_RMP *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->PT,__time_to_timespec(1, 0, 1, 0, 0, 0),retain)
  __INIT_VAR(data__->AM,1.0,retain)
  __INIT_VAR(data__->OS,0,retain)
  __INIT_VAR(data__->DL,0,retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT,0,retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TEMP,0,retain)
  __INIT_VAR(data__->LTEMP,0,retain)
}

// Code part
void GEN_RMP_body__(GEN_RMP *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,TX,,__time_sub(UDINT_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)T_PLC_MS(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__BOOL_LITERAL(FALSE))), __GET_VAR(data__->LAST,)));
  __SET_VAR(data__->,DL,,MODR(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->DL,),
    (REAL)1.0));
  if ((__GET_VAR(data__->DL,) < 0.0)) {
    __SET_VAR(data__->,DL,,(1.0 - __GET_VAR(data__->DL,)));
  };
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,TX,,__time_to_timespec(1, 0, 0, 0, 0, 0));
  };
  if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TX,), __GET_VAR(data__->PT,))) {
    __SET_VAR(data__->,LAST,,__time_add(__GET_VAR(data__->LAST,), __GET_VAR(data__->PT,)));
    __SET_VAR(data__->,TX,,__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->PT,)));
  };
  __SET_VAR(data__->,LTEMP,,__GET_VAR(data__->TEMP,));
  if (GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->PT,), __time_to_timespec(1, 0, 0, 0, 0, 0))) {
    __SET_VAR(data__->,TEMP,,FRACT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(TIME_TO_REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (TIME)__time_add(__GET_VAR(data__->TX,), MULTIME__TIME__TIME__REAL(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (TIME)__GET_VAR(data__->PT,),
          (REAL)__GET_VAR(data__->DL,)))) / TIME_TO_REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (TIME)__GET_VAR(data__->PT,)))));
  };
  __SET_VAR(data__->,OUT,,((__GET_VAR(data__->AM,) * __GET_VAR(data__->TEMP,)) + __GET_VAR(data__->OS,)));
  __SET_VAR(data__->,Q,,(__GET_VAR(data__->TEMP,) < __GET_VAR(data__->LTEMP,)));

  goto __end;

__end:
  return;
} // GEN_RMP_body__() 





void GEN_SIN_init__(GEN_SIN *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->PT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->AM,1.0,retain)
  __INIT_VAR(data__->OS,0,retain)
  __INIT_VAR(data__->DL,0,retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT,0,retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TEMP,0,retain)
}

// Code part
void GEN_SIN_body__(GEN_SIN *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,TX,,__time_sub(UDINT_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)T_PLC_MS(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__BOOL_LITERAL(FALSE))), __GET_VAR(data__->LAST,)));
  __SET_VAR(data__->,DL,,MODR(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->DL,),
    (REAL)1.0));
  if ((__GET_VAR(data__->DL,) < 0.0)) {
    __SET_VAR(data__->,DL,,(1.0 - __GET_VAR(data__->DL,)));
  };
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,TX,,__time_to_timespec(1, 0, 0, 0, 0, 0));
  };
  if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TX,), __GET_VAR(data__->PT,))) {
    __SET_VAR(data__->,LAST,,__time_add(__GET_VAR(data__->LAST,), __GET_VAR(data__->PT,)));
    __SET_VAR(data__->,TX,,__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->PT,)));
  };
  if (GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->PT,), __time_to_timespec(1, 0, 0, 0, 0, 0))) {
    __SET_VAR(data__->,TEMP,,SIN__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)((6.283185307179586476 * TIME_TO_REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (TIME)__time_add(__GET_VAR(data__->TX,), MULTIME__TIME__TIME__REAL(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (TIME)__GET_VAR(data__->PT,),
          (REAL)__GET_VAR(data__->DL,))))) / TIME_TO_REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (TIME)__GET_VAR(data__->PT,)))));
  };
  __SET_VAR(data__->,OUT,,(((__GET_VAR(data__->AM,) * 0.5) * __GET_VAR(data__->TEMP,)) + __GET_VAR(data__->OS,)));
  __SET_VAR(data__->,Q,,!(SIGN_R(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->TEMP,))));

  goto __end;

__end:
  return;
} // GEN_SIN_body__() 





