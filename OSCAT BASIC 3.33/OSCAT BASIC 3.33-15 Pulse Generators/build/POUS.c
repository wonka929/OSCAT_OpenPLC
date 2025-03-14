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





void TMIN_init__(TMIN *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  TP_init__(&data__->PM,retain);
}

// Code part
void TMIN_body__(TMIN *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->PM.,IN,,__GET_VAR(data__->IN,));
  __SET_VAR(data__->PM.,PT,,__GET_VAR(data__->PT,));
  TP_body__(&data__->PM);
  __SET_VAR(data__->,Q,,(__GET_VAR(data__->IN,) || __GET_VAR(data__->PM.Q,)));

  goto __end;

__end:
  return;
} // TMIN_body__() 





void CLICK_CNT_init__(CLICK_CNT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TC,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  TP_init__(&data__->TX,retain);
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CNT,-1,retain)
}

// Code part
void CLICK_CNT_body__(CLICK_CNT *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  if (((__GET_VAR(data__->IN,) && !(__GET_VAR(data__->EDGE,))) && !(__GET_VAR(data__->TX.Q,)))) {
    __SET_VAR(data__->,CNT,,0);
  } else if (((__GET_VAR(data__->TX.Q,) && !(__GET_VAR(data__->IN,))) && __GET_VAR(data__->EDGE,))) {
    __SET_VAR(data__->,CNT,,(__GET_VAR(data__->CNT,) + 1));
  } else if (!(__GET_VAR(data__->TX.Q,))) {
    __SET_VAR(data__->,Q,,(__GET_VAR(data__->CNT,) == __GET_VAR(data__->N,)));
    __SET_VAR(data__->,CNT,,-1);
  };
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->IN,));
  __SET_VAR(data__->TX.,IN,,__GET_VAR(data__->IN,));
  __SET_VAR(data__->TX.,PT,,__GET_VAR(data__->TC,));
  TP_body__(&data__->TX);

  goto __end;

__end:
  return;
} // CLICK_CNT_body__() 





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
    (INT)N) & __DWORD_LITERAL(1)) > __DWORD_LITERAL(0));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return BIT_OF_DWORD;
}


void TONOF_init__(TONOF *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->T_ON,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T_OFF,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->X,retain);
  __INIT_VAR(data__->OLD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MODE,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void TONOF_body__(TONOF *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->IN,) && !__GET_VAR(data__->OLD,)) || (!__GET_VAR(data__->IN,) && __GET_VAR(data__->OLD,))) {
    __SET_VAR(data__->X.,IN,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->X.,PT,,SEL__TIME__BOOL__TIME__TIME(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__GET_VAR(data__->IN,),
      (TIME)__GET_VAR(data__->T_OFF,),
      (TIME)__GET_VAR(data__->T_ON,)));
    TON_body__(&data__->X);
    __SET_VAR(data__->,MODE,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->,OLD,,__GET_VAR(data__->IN,));
  };
  __SET_VAR(data__->X.,IN,,__BOOL_LITERAL(TRUE));
  TON_body__(&data__->X);
  if (__GET_VAR(data__->X.Q,)) {
    __SET_VAR(data__->,Q,,__GET_VAR(data__->MODE,));
  };

  goto __end;

__end:
  return;
} // TONOF_body__() 





// FUNCTION
INT INC2(
  BOOL EN, 
  BOOL *__ENO, 
  INT X, 
  INT _D, 
  INT L, 
  INT U)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT TMP = 0;
  INT INC2 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return INC2;
  }
  TMP = ((U - L) + 1);
  INC2 = (((TMP == 0)?0:((((X + _D) - L) + TMP) % TMP)) + L);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return INC2;
}


void SEQUENCE_64_init__(SEQUENCE_64 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->START,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SMAX,0,retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATE,-1,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  {
    static const __ARRAY_OF_TIME_64 temp = {{__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0),__time_to_timespec(1, 0, 0, 0, 0, 0)}};
    __SET_VAR(data__->,PROG,,temp);
  }
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void SEQUENCE_64_body__(SEQUENCE_64 *data__) {
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
  __SET_VAR(data__->,TRIG,,__BOOL_LITERAL(FALSE));
  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,STATE,,-1);
  } else if ((__GET_VAR(data__->START,) && !(__GET_VAR(data__->EDGE,)))) {
    __SET_VAR(data__->,STATE,,0);
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,TRIG,,__BOOL_LITERAL(TRUE));
  } else if ((__GET_VAR(data__->STATE,) >= 0)) {
    if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->PROG,.table[(__GET_VAR(data__->STATE,)) - (0)]))) {
      __SET_VAR(data__->,STATE,,INC2(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)__GET_VAR(data__->STATE,),
        (INT)1,
        (INT)-1,
        (INT)__GET_VAR(data__->SMAX,)));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
      __SET_VAR(data__->,TRIG,,__BOOL_LITERAL(TRUE));
    };
  };
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->START,));

  goto __end;

__end:
  return;
} // SEQUENCE_64_body__() 





void CYCLE_4_init__(CYCLE_4 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->_E,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->T0,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T1,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T2,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T3,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->S0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SX,0,retain)
  __INIT_VAR(data__->SL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void CYCLE_4_body__(CYCLE_4 *data__) {
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
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
  };
  if (__GET_VAR(data__->_E,)) {
    if (__GET_VAR(data__->SL,)) {
      __SET_VAR(data__->,STATE,,LIMIT__INT__INT__INT__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)0,
        (INT)__GET_VAR(data__->SX,),
        (INT)3));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
      __SET_VAR(data__->,SL,,__BOOL_LITERAL(FALSE));
    } else {
      {
        INT __case_expression = __GET_VAR(data__->STATE,);
        if ((__case_expression == 0)) {
          if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->T0,))) {
            __SET_VAR(data__->,STATE,,1);
            __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
          };
        }
        else if ((__case_expression == 1)) {
          if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->T1,))) {
            __SET_VAR(data__->,STATE,,2);
            __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
          };
        }
        else if ((__case_expression == 2)) {
          if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->T2,))) {
            __SET_VAR(data__->,STATE,,3);
            __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
          };
        }
        else if ((__case_expression == 3)) {
          if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->T3,))) {
            if (__GET_VAR(data__->S0,)) {
              __SET_VAR(data__->,STATE,,0);
            };
            __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
          };
        }
      };
    };
  } else {
    __SET_VAR(data__->,STATE,,0);
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
  };

  goto __end;

__end:
  return;
} // CYCLE_4_body__() 





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_VAR(data__->LOCALVAR0,0,retain)
  __INIT_VAR(data__->LOCALVAR3,0,retain)
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





void B_TRIG_init__(B_TRIG *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->CLK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void B_TRIG_body__(B_TRIG *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,Q,,(__GET_VAR(data__->CLK,) && !__GET_VAR(data__->EDGE,)) || (!__GET_VAR(data__->CLK,) && __GET_VAR(data__->EDGE,)));
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->CLK,));

  goto __end;

__end:
  return;
} // B_TRIG_body__() 





void CLK_N_init__(CLK_N *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CLK,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void CLK_N_body__(CLK_N *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,CLK,,BIT_OF_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)SHR__DWORD__DWORD__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)UDINT_TO_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)T_PLC_MS(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BOOL)__BOOL_LITERAL(FALSE))),
      (INT)__GET_VAR(data__->N,)),
    (INT)0));
  __SET_VAR(data__->,Q,,(__GET_VAR(data__->CLK,) && !__GET_VAR(data__->EDGE,)) || (!__GET_VAR(data__->CLK,) && __GET_VAR(data__->EDGE,)));
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->CLK,));

  goto __end;

__end:
  return;
} // CLK_N_body__() 





void CLICK_DEC_init__(CLICK_DEC *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TC,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Q0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q3,__BOOL_LITERAL(FALSE),retain)
  TP_init__(&data__->TX,retain);
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CNT,-1,retain)
}

// Code part
void CLICK_DEC_body__(CLICK_DEC *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->IN,) == __BOOL_LITERAL(FALSE))) {
    __SET_VAR(data__->,Q0,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q3,,__BOOL_LITERAL(FALSE));
  };
  if (((__GET_VAR(data__->IN,) && !(__GET_VAR(data__->EDGE,))) && !(__GET_VAR(data__->TX.Q,)))) {
    __SET_VAR(data__->,CNT,,0);
  } else if (((__GET_VAR(data__->TX.Q,) && !(__GET_VAR(data__->IN,))) && __GET_VAR(data__->EDGE,))) {
    __SET_VAR(data__->,CNT,,(__GET_VAR(data__->CNT,) + 1));
  } else if (!(__GET_VAR(data__->TX.Q,))) {
    {
      INT __case_expression = __GET_VAR(data__->CNT,);
      if ((__case_expression == 0)) {
        __SET_VAR(data__->,Q0,,__BOOL_LITERAL(TRUE));
      }
      else if ((__case_expression == 1)) {
        __SET_VAR(data__->,Q1,,__BOOL_LITERAL(TRUE));
      }
      else if ((__case_expression == 2)) {
        __SET_VAR(data__->,Q2,,__BOOL_LITERAL(TRUE));
      }
      else if ((__case_expression == 3)) {
        __SET_VAR(data__->,Q3,,__BOOL_LITERAL(TRUE));
      }
    };
    __SET_VAR(data__->,CNT,,-1);
  };
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->IN,));
  __SET_VAR(data__->TX.,IN,,__GET_VAR(data__->IN,));
  __SET_VAR(data__->TX.,PT,,__GET_VAR(data__->TC,));
  TP_body__(&data__->TX);

  goto __end;

__end:
  return;
} // CLICK_DEC_body__() 





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





void CLK_PULSE_init__(CLK_PULSE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->PT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CNT,0,retain)
  __INIT_VAR(data__->RUN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TX,0,retain)
  __INIT_VAR(data__->TN,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void CLK_PULSE_body__(CLK_PULSE *data__) {
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
  __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,RUN,,(__GET_VAR(data__->CNT,) < __GET_VAR(data__->N,)));
  if ((!(__GET_VAR(data__->INIT,)) || __GET_VAR(data__->RST,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,CNT,,0);
    __SET_VAR(data__->,TN,,(__GET_VAR(data__->TX,) - TIME_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)__GET_VAR(data__->PT,))));
    __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
  } else if ((((__GET_VAR(data__->CNT,) < __GET_VAR(data__->N,)) || (__GET_VAR(data__->N,) == 0)) && ((__GET_VAR(data__->TX,) - __GET_VAR(data__->TN,)) >= TIME_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (TIME)__GET_VAR(data__->PT,))))) {
    __SET_VAR(data__->,CNT,,(__GET_VAR(data__->CNT,) + 1));
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,TN,,(__GET_VAR(data__->TN,) + TIME_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)__GET_VAR(data__->PT,))));
  };

  goto __end;

__end:
  return;
} // CLK_PULSE_body__() 





void GEN_SQ_init__(GEN_SQ *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->PT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TN,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
}

// Code part
void GEN_SQ_body__(GEN_SQ *data__) {
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
    __SET_VAR(data__->,TN,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
  } else if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->TN,)), DWORD_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)SHR__DWORD__DWORD__SINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)TIME_TO_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (TIME)__GET_VAR(data__->PT,)),
      (SINT)1)))) {
    __SET_VAR(data__->,Q,,!(__GET_VAR(data__->Q,)));
    __SET_VAR(data__->,TN,,__time_add(__GET_VAR(data__->TN,), DWORD_TO_TIME(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)SHR__DWORD__DWORD__SINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)TIME_TO_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (TIME)__GET_VAR(data__->PT,)),
        (SINT)1))));
  };

  goto __end;

__end:
  return;
} // GEN_SQ_body__() 





void TP_1_init__(TP_1 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->START,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->IX,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void TP_1_body__(TP_1 *data__) {
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
  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  } else if ((__GET_VAR(data__->IN,) && !(__GET_VAR(data__->IX,)))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,START,,__GET_VAR(data__->TX,));
  } else if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->START,)), __GET_VAR(data__->PT,))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,IX,,__GET_VAR(data__->IN,));

  goto __end;

__end:
  return;
} // TP_1_body__() 





void TP_1D_init__(TP_1D *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PT1,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->PTD,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->W,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->START,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->IX,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void TP_1D_body__(TP_1D *data__) {
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
  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,RST,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,W,,__BOOL_LITERAL(FALSE));
  } else if (__GET_VAR(data__->W,)) {
    if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->START,)), __GET_VAR(data__->PTD,))) {
      __SET_VAR(data__->,W,,__BOOL_LITERAL(FALSE));
    };
  } else if ((__GET_VAR(data__->IN,) && !(__GET_VAR(data__->IX,)))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,START,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,IN,,__BOOL_LITERAL(FALSE));
  } else if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->START,)), __GET_VAR(data__->PT1,))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,W,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,START,,__GET_VAR(data__->TX,));
  };
  __SET_VAR(data__->,IX,,__GET_VAR(data__->IN,));

  goto __end;

__end:
  return;
} // TP_1D_body__() 





void D_TRIG_init__(D_TRIG *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LAST_IN,0,retain)
}

// Code part
void D_TRIG_body__(D_TRIG *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,Q,,(__GET_VAR(data__->IN,) != __GET_VAR(data__->LAST_IN,)));
  __SET_VAR(data__->,X,,UDINT_TO_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)(DWORD_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)__GET_VAR(data__->IN,)) - DWORD_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)__GET_VAR(data__->LAST_IN,)))));
  __SET_VAR(data__->,LAST_IN,,__GET_VAR(data__->IN,));

  goto __end;

__end:
  return;
} // D_TRIG_body__() 





void SEQUENCE_8_init__(SEQUENCE_8 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN0,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN1,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN2,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN3,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN4,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN5,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN6,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN7,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->START,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->WAIT0,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DELAY0,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->WAIT1,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DELAY1,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->WAIT2,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DELAY2,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->WAIT3,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DELAY3,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->WAIT4,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DELAY4,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->WAIT5,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DELAY5,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->WAIT6,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DELAY6,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->WAIT7,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DELAY7,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->STOP_ON_ERROR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q5,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q6,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q7,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->QX,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RUN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_STEP,-1,retain)
  __INIT_VAR(data__->STATUS,0,retain)
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void SEQUENCE_8_body__(SEQUENCE_8 *data__) {
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
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(110));
  };
  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,_STEP,,-1);
    __SET_VAR(data__->,Q0,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q3,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q4,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q5,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q6,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q7,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(110));
    __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
  } else if ((__GET_VAR(data__->START,) && !(__GET_VAR(data__->EDGE,)))) {
    __SET_VAR(data__->,_STEP,,0);
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(111));
    __SET_VAR(data__->,Q0,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q3,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q4,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q5,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q6,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q7,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,RUN,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->START,));
  if ((((__GET_VAR(data__->STATUS,) > __BYTE_LITERAL(0)) && (__GET_VAR(data__->STATUS,) < __BYTE_LITERAL(100))) && __GET_VAR(data__->STOP_ON_ERROR,))) {
    goto __end;
  };
  if ((__GET_VAR(data__->RUN,) && (__GET_VAR(data__->_STEP,) == 0))) {
    if (((!(__GET_VAR(data__->Q0,)) && __GET_VAR(data__->IN0,)) && LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT0,)))) {
      __SET_VAR(data__->,Q0,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    } else if ((!(__GET_VAR(data__->Q0,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT0,)))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(1));
      __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
    } else if ((__GET_VAR(data__->Q0,) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY0,)))) {
      __SET_VAR(data__->,_STEP,,1);
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    };
  };
  if ((__GET_VAR(data__->RUN,) && (__GET_VAR(data__->_STEP,) == 1))) {
    if (((!(__GET_VAR(data__->Q1,)) && __GET_VAR(data__->IN1,)) && LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT1,)))) {
      __SET_VAR(data__->,Q0,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,Q1,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    } else if ((!(__GET_VAR(data__->Q1,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT1,)))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(2));
      __SET_VAR(data__->,Q0,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
    } else if ((__GET_VAR(data__->Q1,) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY1,)))) {
      __SET_VAR(data__->,_STEP,,2);
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    };
  };
  if ((__GET_VAR(data__->RUN,) && (__GET_VAR(data__->_STEP,) == 2))) {
    if (((!(__GET_VAR(data__->Q2,)) && __GET_VAR(data__->IN2,)) && LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT2,)))) {
      __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,Q2,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    } else if ((!(__GET_VAR(data__->Q2,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT2,)))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(3));
      __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
    } else if ((__GET_VAR(data__->Q2,) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY2,)))) {
      __SET_VAR(data__->,_STEP,,3);
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    };
  };
  if ((__GET_VAR(data__->RUN,) && (__GET_VAR(data__->_STEP,) == 3))) {
    if (((!(__GET_VAR(data__->Q3,)) && __GET_VAR(data__->IN3,)) && LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT3,)))) {
      __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,Q3,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    } else if ((!(__GET_VAR(data__->Q3,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT3,)))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(4));
      __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
    } else if ((__GET_VAR(data__->Q3,) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY3,)))) {
      __SET_VAR(data__->,_STEP,,4);
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    };
  };
  if ((__GET_VAR(data__->RUN,) && (__GET_VAR(data__->_STEP,) == 4))) {
    if (((!(__GET_VAR(data__->Q4,)) && __GET_VAR(data__->IN4,)) && LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT4,)))) {
      __SET_VAR(data__->,Q3,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,Q4,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    } else if ((!(__GET_VAR(data__->Q4,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT4,)))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(5));
      __SET_VAR(data__->,Q3,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
    } else if ((__GET_VAR(data__->Q4,) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT4,)))) {
      __SET_VAR(data__->,_STEP,,5);
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    };
  };
  if ((__GET_VAR(data__->RUN,) && (__GET_VAR(data__->_STEP,) == 5))) {
    if (((!(__GET_VAR(data__->Q5,)) && __GET_VAR(data__->IN5,)) && LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY4,)))) {
      __SET_VAR(data__->,Q4,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,Q5,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    } else if ((!(__GET_VAR(data__->Q5,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY4,)))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(6));
      __SET_VAR(data__->,Q4,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
    } else if ((__GET_VAR(data__->Q5,) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT5,)))) {
      __SET_VAR(data__->,_STEP,,6);
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    };
  };
  if ((__GET_VAR(data__->RUN,) && (__GET_VAR(data__->_STEP,) == 6))) {
    if (((!(__GET_VAR(data__->Q6,)) && __GET_VAR(data__->IN6,)) && LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY5,)))) {
      __SET_VAR(data__->,Q5,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,Q6,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    } else if ((!(__GET_VAR(data__->Q6,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY5,)))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(7));
      __SET_VAR(data__->,Q5,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
    } else if ((__GET_VAR(data__->Q6,) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT6,)))) {
      __SET_VAR(data__->,_STEP,,7);
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    };
  };
  if ((__GET_VAR(data__->RUN,) && (__GET_VAR(data__->_STEP,) == 7))) {
    if (((!(__GET_VAR(data__->Q7,)) && __GET_VAR(data__->IN7,)) && LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY6,)))) {
      __SET_VAR(data__->,Q6,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,Q7,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    } else if ((!(__GET_VAR(data__->Q7,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY6,)))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(8));
      __SET_VAR(data__->,Q6,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
    } else if ((__GET_VAR(data__->Q7,) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT7,)))) {
      __SET_VAR(data__->,_STEP,,-1);
      __SET_VAR(data__->,Q7,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(110));
    };
  };
  __SET_VAR(data__->,QX,,(((((((__GET_VAR(data__->Q0,) || __GET_VAR(data__->Q1,)) || __GET_VAR(data__->Q2,)) || __GET_VAR(data__->Q3,)) || __GET_VAR(data__->Q4,)) || __GET_VAR(data__->Q5,)) || __GET_VAR(data__->Q6,)) || __GET_VAR(data__->Q7,)));

  goto __end;

__end:
  return;
} // SEQUENCE_8_body__() 





void SEQUENCE_4_init__(SEQUENCE_4 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN0,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN1,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN2,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN3,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->START,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->WAIT0,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DELAY0,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->WAIT1,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DELAY1,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->WAIT2,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DELAY2,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->WAIT3,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DELAY3,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->STOP_ON_ERROR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->QX,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RUN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_STEP,-1,retain)
  __INIT_VAR(data__->STATUS,0,retain)
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void SEQUENCE_4_body__(SEQUENCE_4 *data__) {
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
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(110));
  };
  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,_STEP,,-1);
    __SET_VAR(data__->,Q0,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q3,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(110));
    __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
  } else if ((__GET_VAR(data__->START,) && !(__GET_VAR(data__->EDGE,)))) {
    __SET_VAR(data__->,_STEP,,0);
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(111));
    __SET_VAR(data__->,Q0,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q3,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,RUN,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->START,));
  if ((((__GET_VAR(data__->STATUS,) > __BYTE_LITERAL(0)) && (__GET_VAR(data__->STATUS,) < __BYTE_LITERAL(100))) && __GET_VAR(data__->STOP_ON_ERROR,))) {
    goto __end;
  };
  if ((__GET_VAR(data__->RUN,) && (__GET_VAR(data__->_STEP,) == 0))) {
    if (((!(__GET_VAR(data__->Q0,)) && __GET_VAR(data__->IN0,)) && LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT0,)))) {
      __SET_VAR(data__->,Q0,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    } else if ((!(__GET_VAR(data__->Q0,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT0,)))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(1));
      __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
    } else if ((__GET_VAR(data__->Q0,) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY0,)))) {
      __SET_VAR(data__->,_STEP,,1);
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    };
  };
  if ((__GET_VAR(data__->RUN,) && (__GET_VAR(data__->_STEP,) == 1))) {
    if (((!(__GET_VAR(data__->Q1,)) && __GET_VAR(data__->IN1,)) && LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY0,)))) {
      __SET_VAR(data__->,Q0,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,Q1,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    } else if ((!(__GET_VAR(data__->Q1,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY0,)))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(2));
      __SET_VAR(data__->,Q0,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
    } else if ((__GET_VAR(data__->Q1,) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT1,)))) {
      __SET_VAR(data__->,_STEP,,2);
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    };
  };
  if ((__GET_VAR(data__->RUN,) && (__GET_VAR(data__->_STEP,) == 2))) {
    if (((!(__GET_VAR(data__->Q2,)) && __GET_VAR(data__->IN2,)) && LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY1,)))) {
      __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,Q2,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    } else if ((!(__GET_VAR(data__->Q2,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY1,)))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(3));
      __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
    } else if ((__GET_VAR(data__->Q2,) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT2,)))) {
      __SET_VAR(data__->,_STEP,,3);
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    };
  };
  if ((__GET_VAR(data__->RUN,) && (__GET_VAR(data__->_STEP,) == 3))) {
    if (((!(__GET_VAR(data__->Q3,)) && __GET_VAR(data__->IN3,)) && LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY2,)))) {
      __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,Q3,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    } else if ((!(__GET_VAR(data__->Q3,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY2,)))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(4));
      __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
    } else if ((__GET_VAR(data__->Q3,) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT3,)))) {
      __SET_VAR(data__->,_STEP,,-1);
      __SET_VAR(data__->,Q3,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(110));
    };
  };
  __SET_VAR(data__->,QX,,(((__GET_VAR(data__->Q0,) || __GET_VAR(data__->Q1,)) || __GET_VAR(data__->Q2,)) || __GET_VAR(data__->Q3,)));

  goto __end;

__end:
  return;
} // SEQUENCE_4_body__() 





void SCHEDULER_2_init__(SCHEDULER_2 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->E0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->E1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->E2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->E3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->C0,0,retain)
  __INIT_VAR(data__->C1,0,retain)
  __INIT_VAR(data__->C2,0,retain)
  __INIT_VAR(data__->C3,0,retain)
  __INIT_VAR(data__->O0,0,retain)
  __INIT_VAR(data__->O1,0,retain)
  __INIT_VAR(data__->O2,0,retain)
  __INIT_VAR(data__->O3,0,retain)
  __INIT_VAR(data__->Q0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SX,0,retain)
}

// Code part
void SCHEDULER_2_body__(SCHEDULER_2 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,Q0,,(__GET_VAR(data__->E0,) && ((((__GET_VAR(data__->C0,) == 0)?0:(__GET_VAR(data__->SX,) % __GET_VAR(data__->C0,))) - __GET_VAR(data__->O0,)) == __UINT_LITERAL(0))));
  __SET_VAR(data__->,Q1,,(__GET_VAR(data__->E1,) && ((((__GET_VAR(data__->C1,) == 0)?0:(__GET_VAR(data__->SX,) % __GET_VAR(data__->C1,))) - __GET_VAR(data__->O1,)) == __UINT_LITERAL(0))));
  __SET_VAR(data__->,Q2,,(__GET_VAR(data__->E2,) && ((((__GET_VAR(data__->C2,) == 0)?0:(__GET_VAR(data__->SX,) % __GET_VAR(data__->C2,))) - __GET_VAR(data__->O2,)) == __UINT_LITERAL(0))));
  __SET_VAR(data__->,Q3,,(__GET_VAR(data__->E3,) && ((((__GET_VAR(data__->C3,) == 0)?0:(__GET_VAR(data__->SX,) % __GET_VAR(data__->C3,))) - __GET_VAR(data__->O3,)) == __UINT_LITERAL(0))));
  __SET_VAR(data__->,SX,,(__GET_VAR(data__->SX,) + __UINT_LITERAL(1)));

  goto __end;

__end:
  return;
} // SCHEDULER_2_body__() 





void TMAX_init__(TMAX *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Z,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->START,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->LAST_IN,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void TMAX_body__(TMAX *data__) {
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
  __SET_VAR(data__->,Z,,__BOOL_LITERAL(FALSE));
  if (!(__GET_VAR(data__->IN,))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  } else if ((__GET_VAR(data__->IN,) && !(__GET_VAR(data__->LAST_IN,)))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,START,,__GET_VAR(data__->TX,));
  } else if ((GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->START,)), __GET_VAR(data__->PT,)) && __GET_VAR(data__->Q,))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Z,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,LAST_IN,,__GET_VAR(data__->IN,));

  goto __end;

__end:
  return;
} // TMAX_body__() 





void CLK_DIV_init__(CLK_DIV *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->CLK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q5,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q6,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q7,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CNT,0,retain)
}

// Code part
void CLK_DIV_body__(CLK_DIV *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,CNT,,__BYTE_LITERAL(0));
    __SET_VAR(data__->,Q0,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q3,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q4,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q5,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q6,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q7,,__BOOL_LITERAL(FALSE));
  } else if (__GET_VAR(data__->CLK,)) {
    __SET_VAR(data__->,CNT,,USINT_TO_BYTE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (USINT)(BYTE_TO_USINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->CNT,)) + __USINT_LITERAL(1))));
    __SET_VAR(data__->,Q0,,BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)BYTE_TO_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->CNT,)),
      (INT)0));
    __SET_VAR(data__->,Q1,,BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)BYTE_TO_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->CNT,)),
      (INT)1));
    __SET_VAR(data__->,Q2,,BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)BYTE_TO_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->CNT,)),
      (INT)2));
    __SET_VAR(data__->,Q3,,BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)BYTE_TO_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->CNT,)),
      (INT)3));
    __SET_VAR(data__->,Q4,,BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)BYTE_TO_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->CNT,)),
      (INT)4));
    __SET_VAR(data__->,Q5,,BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)BYTE_TO_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->CNT,)),
      (INT)5));
    __SET_VAR(data__->,Q6,,BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)BYTE_TO_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->CNT,)),
      (INT)6));
    __SET_VAR(data__->,Q7,,BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)BYTE_TO_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->CNT,)),
      (INT)7));
  };

  goto __end;

__end:
  return;
} // CLK_DIV_body__() 





void TOF_1_init__(TOF_1 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->START,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
}

// Code part
void TOF_1_body__(TOF_1 *data__) {
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
  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  } else if (__GET_VAR(data__->IN,)) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,START,,__GET_VAR(data__->TX,));
  } else if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->START,)), __GET_VAR(data__->PT,))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // TOF_1_body__() 





void SCHEDULER_init__(SCHEDULER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->E0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->E1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->E2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->E3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->T0,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T1,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T2,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T3,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Q0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->S0,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->S1,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->S2,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->S3,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->C,0,retain)
}

// Code part
void SCHEDULER_body__(SCHEDULER *data__) {
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
    __SET_VAR(data__->,S0,,__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->T0,)));
    __SET_VAR(data__->,S1,,__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->T1,)));
    __SET_VAR(data__->,S2,,__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->T2,)));
    __SET_VAR(data__->,S3,,__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->T3,)));
  };
  __SET_VAR(data__->,Q0,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,Q3,,__BOOL_LITERAL(FALSE));
  {
    INT __case_expression = __GET_VAR(data__->C,);
    if ((__case_expression == 0)) {
      if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->S0,)), __GET_VAR(data__->T0,))) {
        __SET_VAR(data__->,Q0,,__GET_VAR(data__->E0,));
        __SET_VAR(data__->,S0,,__GET_VAR(data__->TX,));
      };
      __SET_VAR(data__->,C,,1);
    }
    else if ((__case_expression == 1)) {
      if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->S1,)), __GET_VAR(data__->T1,))) {
        __SET_VAR(data__->,Q1,,__GET_VAR(data__->E1,));
        __SET_VAR(data__->,S1,,__GET_VAR(data__->TX,));
      };
      __SET_VAR(data__->,C,,2);
    }
    else if ((__case_expression == 2)) {
      if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->S2,)), __GET_VAR(data__->T2,))) {
        __SET_VAR(data__->,Q2,,__GET_VAR(data__->E2,));
        __SET_VAR(data__->,S2,,__GET_VAR(data__->TX,));
      };
      __SET_VAR(data__->,C,,3);
    }
    else if ((__case_expression == 3)) {
      if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->S3,)), __GET_VAR(data__->T3,))) {
        __SET_VAR(data__->,Q3,,__GET_VAR(data__->E3,));
        __SET_VAR(data__->,S3,,__GET_VAR(data__->TX,));
      };
      __SET_VAR(data__->,C,,0);
    }
  };

  goto __end;

__end:
  return;
} // SCHEDULER_body__() 





void GEN_BIT_init__(GEN_BIT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN0,0,retain)
  __INIT_VAR(data__->IN1,0,retain)
  __INIT_VAR(data__->IN2,0,retain)
  __INIT_VAR(data__->IN3,0,retain)
  __INIT_VAR(data__->CLK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STEPS,0,retain)
  __INIT_VAR(data__->REP,0,retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CNT,0,retain)
  __INIT_VAR(data__->RUN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->R0,0,retain)
  __INIT_VAR(data__->R1,0,retain)
  __INIT_VAR(data__->R2,0,retain)
  __INIT_VAR(data__->R3,0,retain)
  __INIT_VAR(data__->RX,1,retain)
}

// Code part
void GEN_BIT_body__(GEN_BIT *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->CLK,) && !(__GET_VAR(data__->RST,)))) {
    __SET_VAR(data__->,RUN,,((__GET_VAR(data__->REP,) == 0) || (__GET_VAR(data__->RX,) <= __GET_VAR(data__->REP,))));
    if (__GET_VAR(data__->RUN,)) {
      if ((__GET_VAR(data__->CNT,) == __GET_VAR(data__->STEPS,))) {
        __SET_VAR(data__->,CNT,,0);
      };
      if ((__GET_VAR(data__->CNT,) == 0)) {
        __SET_VAR(data__->,R0,,__GET_VAR(data__->IN0,));
        __SET_VAR(data__->,R1,,__GET_VAR(data__->IN1,));
        __SET_VAR(data__->,R2,,__GET_VAR(data__->IN2,));
        __SET_VAR(data__->,R3,,__GET_VAR(data__->IN3,));
      };
      if ((__GET_VAR(data__->CNT,) < __GET_VAR(data__->STEPS,))) {
        __SET_VAR(data__->,Q0,,BIT_OF_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)__GET_VAR(data__->R0,),
          (INT)0));
        __SET_VAR(data__->,Q1,,BIT_OF_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)__GET_VAR(data__->R1,),
          (INT)0));
        __SET_VAR(data__->,Q2,,BIT_OF_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)__GET_VAR(data__->R2,),
          (INT)0));
        __SET_VAR(data__->,Q3,,BIT_OF_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)__GET_VAR(data__->R3,),
          (INT)0));
        __SET_VAR(data__->,R0,,SHR__DWORD__DWORD__SINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)__GET_VAR(data__->R0,),
          (SINT)1));
        __SET_VAR(data__->,R1,,SHR__DWORD__DWORD__SINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)__GET_VAR(data__->R1,),
          (SINT)1));
        __SET_VAR(data__->,R2,,SHR__DWORD__DWORD__SINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)__GET_VAR(data__->R2,),
          (SINT)1));
        __SET_VAR(data__->,R3,,SHR__DWORD__DWORD__SINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)__GET_VAR(data__->R3,),
          (SINT)1));
      };
      __SET_VAR(data__->,CNT,,(__GET_VAR(data__->CNT,) + 1));
      if (((__GET_VAR(data__->CNT,) == __GET_VAR(data__->STEPS,)) && (__GET_VAR(data__->REP,) != 0))) {
        __SET_VAR(data__->,RX,,(__GET_VAR(data__->RX,) + 1));
      };
      if (((__GET_VAR(data__->RX,) > __GET_VAR(data__->REP,)) && (__GET_VAR(data__->REP,) != 0))) {
        __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
      };
    };
  } else {
    if (__GET_VAR(data__->RST,)) {
      __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,Q0,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,Q3,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,R0,,__DWORD_LITERAL(0));
      __SET_VAR(data__->,R1,,__DWORD_LITERAL(0));
      __SET_VAR(data__->,R2,,__DWORD_LITERAL(0));
      __SET_VAR(data__->,R3,,__DWORD_LITERAL(0));
      __SET_VAR(data__->,CNT,,0);
      __SET_VAR(data__->,RX,,1);
    };
  };

  goto __end;

__end:
  return;
} // GEN_BIT_body__() 





void A_TRIG_init__(A_TRIG *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->RES,0,retain)
  __INIT_VAR(data__->_D,0,retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LAST_IN,0,retain)
}

// Code part
void A_TRIG_body__(A_TRIG *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_D,,(__GET_VAR(data__->IN,) - __GET_VAR(data__->LAST_IN,)));
  if ((ABS__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->_D,)) >= __GET_VAR(data__->RES,))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,LAST_IN,,__GET_VAR(data__->IN,));
  } else {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // A_TRIG_body__() 





