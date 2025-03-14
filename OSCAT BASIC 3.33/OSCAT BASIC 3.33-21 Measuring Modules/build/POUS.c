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


void CYCLE_TIME_init__(CYCLE_TIME *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CT_MIN,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->CT_MAX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->CT_LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->SYSTIME,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->SYSDAYS,0,retain)
  __INIT_VAR(data__->CYCLES,0,retain)
  __INIT_VAR(data__->LAST_CYCLE,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void CYCLE_TIME_body__(CYCLE_TIME *data__) {
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
      (BOOL)__BOOL_LITERAL(FALSE))), __GET_VAR(data__->LAST_CYCLE,)));
  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,CT_MIN,,__time_to_timespec(1, 0, 0, 0, 10, 0));
    __SET_VAR(data__->,CT_MAX,,__time_to_timespec(1, 0, 0, 0, 0, 0));
    __SET_VAR(data__->,CYCLES,,__DWORD_LITERAL(0));
  } else if (GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->LAST_CYCLE,), __time_to_timespec(1, 0, 0, 0, 0, 0))) {
    if (LT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TX,), __GET_VAR(data__->CT_MIN,))) {
      __SET_VAR(data__->,CT_MIN,,__GET_VAR(data__->TX,));
    } else if (GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TX,), __GET_VAR(data__->CT_MAX,))) {
      __SET_VAR(data__->,CT_MAX,,__GET_VAR(data__->TX,));
    };
    __SET_VAR(data__->,CT_LAST,,__GET_VAR(data__->TX,));
  } else if (EQ_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->CT_MIN,), __time_to_timespec(1, 0, 0, 0, 0, 0))) {
    __SET_VAR(data__->,CT_MIN,,__time_sub(__time_to_timespec(1, 0, 0, 0, 0, 0), __time_to_timespec(1, 1, 0, 0, 0, 0)));
  };
  if (__GET_VAR(data__->INIT,)) {
    __SET_VAR(data__->,SYSTIME,,__time_add(__GET_VAR(data__->SYSTIME,), __GET_VAR(data__->TX,)));
    if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->SYSTIME,), __time_to_timespec(1, 0, 0, 0, 0, 1))) {
      __SET_VAR(data__->,SYSTIME,,__time_sub(__GET_VAR(data__->SYSTIME,), __time_to_timespec(1, 0, 0, 0, 0, 1)));
      __SET_VAR(data__->,SYSDAYS,,(__GET_VAR(data__->SYSDAYS,) + 1));
    };
  };
  __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->,LAST_CYCLE,,__time_add(__GET_VAR(data__->LAST_CYCLE,), __GET_VAR(data__->TX,)));
  __SET_VAR(data__->,CYCLES,,UDINT_TO_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)(DWORD_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)__GET_VAR(data__->CYCLES,)) + __UDINT_LITERAL(1))));

  goto __end;

__end:
  return;
} // CYCLE_TIME_body__() 





// FUNCTION
BOOL LEAP_OF_DATE(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BOOL LEAP_OF_DATE = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return LEAP_OF_DATE;
  }
  LEAP_OF_DATE = (SHL__DWORD__DWORD__SINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)UDINT_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)((IDATE + __UDINT_LITERAL(43200)) / __UDINT_LITERAL(31557600))),
    (SINT)30) == __DWORD_LITERAL(0x80000000));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return LEAP_OF_DATE;
}


void R2_ADD_init__(R2_ADD *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const REAL2 temp = {0,0};
    __SET_VAR(data__->,X,,temp);
  }
  __INIT_VAR(data__->Y,0,retain)
  {
    static const REAL2 temp = {0,0};
    __SET_VAR(data__->,_R2_ADD,,temp);
  }
  __INIT_VAR(data__->TEMP,0,retain)
}

// Code part
void R2_ADD_body__(R2_ADD *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,TEMP,,__GET_VAR(data__->X,.RX));
  __SET_VAR(data__->,_R2_ADD,.RX,((__GET_VAR(data__->Y,) + __GET_VAR(data__->X,.R1)) + __GET_VAR(data__->X,.RX)));
  __SET_VAR(data__->,_R2_ADD,.R1,(((__GET_VAR(data__->TEMP,) - __GET_VAR(data__->_R2_ADD,.RX)) + __GET_VAR(data__->Y,)) + __GET_VAR(data__->X,.R1)));

  goto __end;

__end:
  return;
} // R2_ADD_body__() 





// FUNCTION
INT YEAR_OF_DATE(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT YEAR_OF_DATE = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return YEAR_OF_DATE;
  }
  YEAR_OF_DATE = UDINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)(((IDATE + __UDINT_LITERAL(43200)) / __UDINT_LITERAL(31557600)) + __UDINT_LITERAL(1970)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return YEAR_OF_DATE;
}


// FUNCTION
UDINT T_PLC_US(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL DEBUG)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  UDINT TX = 0;
  INT N = 0;
  UDINT OFFSET = 0;
  DWORD TEMP = 1;
  UDINT T_PLC_US = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return T_PLC_US;
  }
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
  T_PLC_US = (TX * 1000);
  if (DEBUG) {
    T_PLC_US = ((DWORD_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)(SHL__DWORD__DWORD__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)UDINT_TO_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (UDINT)T_PLC_US),
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
  return T_PLC_US;
}


void TC_US_init__(TC_US *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TC,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TX,0,retain)
  __INIT_VAR(data__->LAST,0,retain)
}

// Code part
void TC_US_body__(TC_US *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,TX,,T_PLC_US(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__BOOL_LITERAL(FALSE)));
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,TC,,__DWORD_LITERAL(0));
  } else {
    __SET_VAR(data__->,TC,,UDINT_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)(__GET_VAR(data__->TX,) - __GET_VAR(data__->LAST,))));
  };
  __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));

  goto __end;

__end:
  return;
} // TC_US_body__() 





void DT_SIMU_init__(DT_SIMU *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->START,0,retain)
  __INIT_VAR(data__->SPEED,1.0,retain)
  __INIT_VAR(data__->DTS,0,retain)
  __INIT_VAR(data__->TC,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LAST,0,retain)
  __INIT_VAR(data__->TX,0,retain)
  __INIT_VAR(data__->TD,0,retain)
}

// Code part
void DT_SIMU_body__(DT_SIMU *data__) {
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
  __SET_VAR(data__->,TC,,REAL_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(UDINT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)(__GET_VAR(data__->TX,) - __GET_VAR(data__->LAST,))) * __GET_VAR(data__->SPEED,))));
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,DTS,,__GET_VAR(data__->START,));
    __SET_VAR(data__->,TC,,__UDINT_LITERAL(0));
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
  } else if ((__GET_VAR(data__->SPEED,) == 0.0)) {
    __SET_VAR(data__->,DTS,,(__GET_VAR(data__->DTS,) + __UDINT_LITERAL(1)));
  } else if ((__GET_VAR(data__->TC,) >= __UDINT_LITERAL(1000))) {
    __SET_VAR(data__->,TD,,((__GET_VAR(data__->TC,) / __UDINT_LITERAL(1000)) * __UDINT_LITERAL(1000)));
    __SET_VAR(data__->,DTS,,(__GET_VAR(data__->DTS,) + __GET_VAR(data__->TD,)));
    __SET_VAR(data__->,LAST,,(__GET_VAR(data__->LAST,) + REAL_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(UDINT_TO_REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)__GET_VAR(data__->TD,)) / __GET_VAR(data__->SPEED,)))));
  };

  goto __end;

__end:
  return;
} // DT_SIMU_body__() 





void TC_MS_init__(TC_MS *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TC,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TX,0,retain)
  __INIT_VAR(data__->LAST,0,retain)
}

// Code part
void TC_MS_body__(TC_MS *data__) {
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
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,TC,,__DWORD_LITERAL(0));
  } else {
    __SET_VAR(data__->,TC,,UDINT_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)(__GET_VAR(data__->TX,) - __GET_VAR(data__->LAST,))));
  };
  __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));

  goto __end;

__end:
  return;
} // TC_MS_body__() 





void INTEGRATE_init__(INTEGRATE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->_E,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->K,1.0,retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->X_LAST,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LAST,0,retain)
  __INIT_VAR(data__->TX,0,retain)
}

// Code part
void INTEGRATE_body__(INTEGRATE *data__) {
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
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,X_LAST,,__GET_VAR(data__->X,));
  } else if (__GET_VAR(data__->_E,)) {
    __SET_VAR(data__->,Y,,(((((__GET_VAR(data__->X,) + __GET_VAR(data__->X_LAST,)) * 0.5E-3) * UDINT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)(__GET_VAR(data__->TX,) - __GET_VAR(data__->LAST,)))) * __GET_VAR(data__->K,)) + __GET_VAR(data__->Y,)));
    __SET_VAR(data__->,X_LAST,,__GET_VAR(data__->X,));
  };
  __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));

  goto __end;

__end:
  return;
} // INTEGRATE_body__() 





void ALARM_2_init__(ALARM_2 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->LO_1,0,retain)
  __INIT_VAR(data__->HI_1,0,retain)
  __INIT_VAR(data__->LO_2,0,retain)
  __INIT_VAR(data__->HI_2,0,retain)
  __INIT_VAR(data__->HYS,0,retain)
  __INIT_VAR(data__->Q1_LO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q1_HI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q2_LO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q2_HI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TMP,0,retain)
}

// Code part
void ALARM_2_body__(ALARM_2 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,TMP,,(__GET_VAR(data__->X,) - (__GET_VAR(data__->HYS,) * 0.5)));
  if ((__GET_VAR(data__->TMP,) > __GET_VAR(data__->LO_1,))) {
    __SET_VAR(data__->,Q1_LO,,__BOOL_LITERAL(FALSE));
  };
  if ((__GET_VAR(data__->TMP,) > __GET_VAR(data__->HI_1,))) {
    __SET_VAR(data__->,Q2_LO,,__BOOL_LITERAL(FALSE));
  };
  if ((__GET_VAR(data__->TMP,) > __GET_VAR(data__->HI_1,))) {
    __SET_VAR(data__->,Q1_HI,,__BOOL_LITERAL(TRUE));
  };
  if ((__GET_VAR(data__->TMP,) > __GET_VAR(data__->LO_2,))) {
    __SET_VAR(data__->,Q2_HI,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,TMP,,(__GET_VAR(data__->TMP,) + __GET_VAR(data__->HYS,)));
  if ((__GET_VAR(data__->TMP,) < __GET_VAR(data__->LO_1,))) {
    __SET_VAR(data__->,Q1_LO,,__BOOL_LITERAL(TRUE));
  };
  if ((__GET_VAR(data__->TMP,) < __GET_VAR(data__->HI_1,))) {
    __SET_VAR(data__->,Q2_LO,,__BOOL_LITERAL(TRUE));
  };
  if ((__GET_VAR(data__->TMP,) < __GET_VAR(data__->HI_1,))) {
    __SET_VAR(data__->,Q1_HI,,__BOOL_LITERAL(FALSE));
  };
  if ((__GET_VAR(data__->TMP,) < __GET_VAR(data__->LO_2,))) {
    __SET_VAR(data__->,Q2_HI,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // ALARM_2_body__() 





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





void METER_init__(METER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->M1,0,retain)
  __INIT_VAR(data__->M2,0,retain)
  __INIT_VAR(data__->I1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->I2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_D,1.0,retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MX,0,retain)
  {
    static const REAL2 temp = {0,0};
    __SET_VAR(data__->,MR,,temp);
  }
  __INIT_VAR(data__->MX1,0,retain)
  __INIT_VAR(data__->MX2,0,retain)
  __INIT_VAR(data__->TX,0,retain)
  __INIT_VAR(data__->LAST,0,retain)
  __INIT_VAR(data__->TC,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  R2_ADD_init__(&data__->_R2_ADD,retain);
}

// Code part
void METER_body__(METER *data__) {
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
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,MR,.RX,__GET_VAR(data__->MX,));
    __SET_VAR(data__->,MR,.R1,0.0);
  } else if ((__GET_VAR(data__->TX,) == __GET_VAR(data__->LAST,))) {
    goto __end;
  } else {
    __SET_VAR(data__->,TC,,(UDINT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)(__GET_VAR(data__->TX,) - __GET_VAR(data__->LAST,))) * 0.001));
  };
  __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,MR,.R1,0.0);
    __SET_VAR(data__->,MR,.RX,0.0);
  } else {
    __SET_VAR(data__->,MX1,,SEL__REAL__BOOL__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__GET_VAR(data__->I1,),
      (REAL)0.0,
      (REAL)__GET_VAR(data__->M1,)));
    __SET_VAR(data__->,MX2,,SEL__REAL__BOOL__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__GET_VAR(data__->I2,),
      (REAL)0.0,
      (REAL)__GET_VAR(data__->M2,)));
    __SET_VAR(data__->_R2_ADD.,X,,__GET_VAR(data__->MR,));
    __SET_VAR(data__->_R2_ADD.,Y,,(((SEL__REAL__BOOL__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__GET_VAR(data__->I1,),
      (REAL)0.0,
      (REAL)__GET_VAR(data__->MX1,)) + SEL__REAL__BOOL__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__GET_VAR(data__->I2,),
      (REAL)0.0,
      (REAL)__GET_VAR(data__->MX2,))) / __GET_VAR(data__->_D,)) * __GET_VAR(data__->TC,)));
    R2_ADD_body__(&data__->_R2_ADD);
    __SET_VAR(data__->,MR,,__GET_VAR(data__->_R2_ADD._R2_ADD,));
    __SET_VAR(data__->,MX,,__GET_VAR(data__->MR,.RX));
  };

  goto __end;

__end:
  return;
} // METER_body__() 





void M_D_init__(M_D *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->START,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STOP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TMAX,__time_to_timespec(1, 0, 0, 0, 0, 10),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->ET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->RUN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->T0,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->STARTUP,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void M_D_body__(M_D *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->RST,) || GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->ET,), __GET_VAR(data__->TMAX,)))) {
    __SET_VAR(data__->,PT,,__time_to_timespec(1, 0, 0, 0, 0, 0));
    __SET_VAR(data__->,ET,,__time_to_timespec(1, 0, 0, 0, 0, 0));
    __SET_VAR(data__->,STARTUP,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
  };
  if (!(__GET_VAR(data__->STARTUP,))) {
    __SET_VAR(data__->,EDGE,,__GET_VAR(data__->START,));
    __SET_VAR(data__->,STARTUP,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,TX,,UDINT_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)T_PLC_MS(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__BOOL_LITERAL(FALSE))));
  if (((__GET_VAR(data__->START,) && !(__GET_VAR(data__->EDGE,))) && !(__GET_VAR(data__->STOP,)))) {
    __SET_VAR(data__->,T0,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,RUN,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,PT,,__time_to_timespec(1, 0, 0, 0, 0, 0));
  } else if ((__GET_VAR(data__->STOP,) && __GET_VAR(data__->RUN,))) {
    __SET_VAR(data__->,PT,,__GET_VAR(data__->ET,));
    __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->START,));
  if (__GET_VAR(data__->RUN,)) {
    __SET_VAR(data__->,ET,,__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->T0,)));
  };

  goto __end;

__end:
  return;
} // M_D_body__() 





void TC_S_init__(TC_S *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TC,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TX,0,retain)
  __INIT_VAR(data__->LAST,0,retain)
}

// Code part
void TC_S_body__(TC_S *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,TX,,T_PLC_US(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__BOOL_LITERAL(FALSE)));
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,TC,,0.0);
  } else {
    __SET_VAR(data__->,TC,,(UDINT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)(__GET_VAR(data__->TX,) - __GET_VAR(data__->LAST,))) * 1.0E-6));
  };
  __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));

  goto __end;

__end:
  return;
} // TC_S_body__() 





void CALIBRATE_init__(CALIBRATE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->CO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Y_OFFSET,0,retain)
  __INIT_VAR(data__->Y_SCALE,0,retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->OFFSET,0,1)
  __INIT_VAR(data__->SCALE,1.0,1)
}

// Code part
void CALIBRATE_body__(CALIBRATE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (__GET_VAR(data__->CO,)) {
    __SET_VAR(data__->,OFFSET,,(__GET_VAR(data__->Y_OFFSET,) - __GET_VAR(data__->X,)));
  } else if (__GET_VAR(data__->CS,)) {
    __SET_VAR(data__->,SCALE,,(__GET_VAR(data__->Y_SCALE,) / (__GET_VAR(data__->X,) + __GET_VAR(data__->OFFSET,))));
  };
  __SET_VAR(data__->,Y,,((__GET_VAR(data__->X,) + __GET_VAR(data__->OFFSET,)) * __GET_VAR(data__->SCALE,)));

  goto __end;

__end:
  return;
} // CALIBRATE_body__() 





void M_T_init__(M_T *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TMAX,__time_to_timespec(1, 0, 0, 0, 0, 10),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->ET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->START,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
}

// Code part
void M_T_body__(M_T *data__) {
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
  if ((__GET_VAR(data__->RST,) || GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->ET,), __GET_VAR(data__->TMAX,)))) {
    __SET_VAR(data__->,PT,,__time_to_timespec(1, 0, 0, 0, 0, 0));
    __SET_VAR(data__->,ET,,__GET_VAR(data__->PT,));
  } else if (__GET_VAR(data__->IN,)) {
    if (!(__GET_VAR(data__->EDGE,))) {
      __SET_VAR(data__->,START,,__GET_VAR(data__->TX,));
    };
    __SET_VAR(data__->,ET,,__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->START,)));
  } else {
    __SET_VAR(data__->,PT,,__GET_VAR(data__->ET,));
  };
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->IN,));

  goto __end;

__end:
  return;
} // M_T_body__() 





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


// FUNCTION
INT DAY_OF_YEAR(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT DAY_OF_YEAR = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DAY_OF_YEAR;
  }
  DAY_OF_YEAR = UDINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)((__UDINT_LITERAL(1461) == 0)?0:((IDATE / __UDINT_LITERAL(86400)) % __UDINT_LITERAL(1461))));
  if ((DAY_OF_YEAR > 729)) {
    if ((DAY_OF_YEAR > 1095)) {
      DAY_OF_YEAR = (DAY_OF_YEAR - 1095);
    } else {
      DAY_OF_YEAR = (DAY_OF_YEAR - 729);
    };
  } else if ((DAY_OF_YEAR > 364)) {
    DAY_OF_YEAR = (DAY_OF_YEAR - 364);
  } else {
    DAY_OF_YEAR = (DAY_OF_YEAR + 1);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return DAY_OF_YEAR;
}


// FUNCTION
INT DAY_OF_WEEK(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT DAY_OF_WEEK = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DAY_OF_WEEK;
  }
  DAY_OF_WEEK = (UDINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)((__UDINT_LITERAL(7) == 0)?0:(((IDATE / __UDINT_LITERAL(86400)) + __UDINT_LITERAL(3)) % __UDINT_LITERAL(7)))) + __INT_LITERAL(1));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return DAY_OF_WEEK;
}


// FUNCTION
INT MONTH_OF_DATE(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT MONTH_OF_DATE = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return MONTH_OF_DATE;
  }
  MONTH_OF_DATE = DAY_OF_YEAR(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)IDATE);
  if ((MONTH_OF_DATE < 32)) {
    MONTH_OF_DATE = 1;
  } else if (LEAP_OF_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)IDATE)) {
    MONTH_OF_DATE = (((MONTH_OF_DATE * 53) + 1668) / 1623);
  } else {
    MONTH_OF_DATE = (((MONTH_OF_DATE * 53) + 1700) / 1620);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return MONTH_OF_DATE;
}


void METER_STAT_init__(METER_STAT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->DI,0,retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LAST_DAY,0,retain)
  __INIT_VAR(data__->CURRENT_DAY,0,retain)
  __INIT_VAR(data__->LAST_WEEK,0,retain)
  __INIT_VAR(data__->CURRENT_WEEK,0,retain)
  __INIT_VAR(data__->LAST_MONTH,0,retain)
  __INIT_VAR(data__->CURRENT_MONTH,0,retain)
  __INIT_VAR(data__->LAST_YEAR,0,retain)
  __INIT_VAR(data__->CURRENT_YEAR,0,retain)
  __INIT_VAR(data__->YEAR_START,0,1)
  __INIT_VAR(data__->MONTH_START,0,1)
  __INIT_VAR(data__->WEEK_START,0,1)
  __INIT_VAR(data__->DAY_START,0,1)
  __INIT_VAR(data__->LAST_RUN,0,1)
}

// Code part
void METER_STAT_body__(METER_STAT *data__) {
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
    __SET_VAR(data__->,LAST_DAY,,0.0);
    __SET_VAR(data__->,CURRENT_DAY,,0.0);
    __SET_VAR(data__->,DAY_START,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->,LAST_WEEK,,0.0);
    __SET_VAR(data__->,CURRENT_WEEK,,0.0);
    __SET_VAR(data__->,WEEK_START,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->,LAST_MONTH,,0.0);
    __SET_VAR(data__->,CURRENT_MONTH,,0.0);
    __SET_VAR(data__->,MONTH_START,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->,LAST_YEAR,,0.0);
    __SET_VAR(data__->,CURRENT_YEAR,,0.0);
    __SET_VAR(data__->,YEAR_START,,__GET_VAR(data__->IN,));
  } else {
    __SET_VAR(data__->,CURRENT_DAY,,(__GET_VAR(data__->IN,) - __GET_VAR(data__->DAY_START,)));
    __SET_VAR(data__->,CURRENT_WEEK,,(__GET_VAR(data__->IN,) - __GET_VAR(data__->WEEK_START,)));
    __SET_VAR(data__->,CURRENT_MONTH,,(__GET_VAR(data__->IN,) - __GET_VAR(data__->MONTH_START,)));
    __SET_VAR(data__->,CURRENT_YEAR,,(__GET_VAR(data__->IN,) - __GET_VAR(data__->YEAR_START,)));
  };
  if ((YEAR_OF_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->DI,)) > YEAR_OF_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->LAST_RUN,)))) {
    __SET_VAR(data__->,LAST_YEAR,,__GET_VAR(data__->CURRENT_YEAR,));
    __SET_VAR(data__->,CURRENT_YEAR,,0.0);
    __SET_VAR(data__->,YEAR_START,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->,LAST_MONTH,,__GET_VAR(data__->CURRENT_MONTH,));
    __SET_VAR(data__->,CURRENT_MONTH,,0.0);
    __SET_VAR(data__->,MONTH_START,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->,LAST_DAY,,__GET_VAR(data__->CURRENT_DAY,));
    __SET_VAR(data__->,CURRENT_DAY,,0.0);
    __SET_VAR(data__->,DAY_START,,__GET_VAR(data__->IN,));
  } else if ((MONTH_OF_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->DI,)) > MONTH_OF_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->LAST_RUN,)))) {
    __SET_VAR(data__->,LAST_MONTH,,__GET_VAR(data__->CURRENT_MONTH,));
    __SET_VAR(data__->,CURRENT_MONTH,,0.0);
    __SET_VAR(data__->,MONTH_START,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->,LAST_DAY,,__GET_VAR(data__->CURRENT_DAY,));
    __SET_VAR(data__->,CURRENT_DAY,,0.0);
    __SET_VAR(data__->,DAY_START,,__GET_VAR(data__->IN,));
  } else if ((DAY_OF_YEAR(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->DI,)) > DAY_OF_YEAR(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->LAST_RUN,)))) {
    __SET_VAR(data__->,LAST_DAY,,__GET_VAR(data__->CURRENT_DAY,));
    __SET_VAR(data__->,CURRENT_DAY,,0.0);
    __SET_VAR(data__->,DAY_START,,__GET_VAR(data__->IN,));
  };
  if ((DAY_OF_WEEK(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->DI,)) < DAY_OF_WEEK(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->LAST_RUN,)))) {
    __SET_VAR(data__->,LAST_WEEK,,__GET_VAR(data__->CURRENT_WEEK,));
    __SET_VAR(data__->,CURRENT_WEEK,,0.0);
    __SET_VAR(data__->,WEEK_START,,__GET_VAR(data__->IN,));
  };
  __SET_VAR(data__->,LAST_RUN,,__GET_VAR(data__->DI,));

  goto __end;

__end:
  return;
} // METER_STAT_body__() 





void ONTIME_init__(ONTIME *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SECONDS,0,retain)
  __INIT_VAR(data__->CYCLES,0,retain)
  __INIT_VAR(data__->TX,0,retain)
  __INIT_VAR(data__->LAST,0,retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MS,0,retain)
}

// Code part
void ONTIME_body__(ONTIME *data__) {
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
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,MS,,__UDINT_LITERAL(0));
  };
  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,SECONDS,,__UDINT_LITERAL(0));
    __SET_VAR(data__->,CYCLES,,__UDINT_LITERAL(0));
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,MS,,__UDINT_LITERAL(0));
  } else if (__GET_VAR(data__->IN,)) {
    __SET_VAR(data__->,MS,,((__GET_VAR(data__->TX,) - __GET_VAR(data__->LAST,)) + __GET_VAR(data__->MS,)));
    if ((__GET_VAR(data__->MS,) >= __UDINT_LITERAL(1000))) {
      __SET_VAR(data__->,SECONDS,,(__GET_VAR(data__->SECONDS,) + __UDINT_LITERAL(1)));
      __SET_VAR(data__->,MS,,(__GET_VAR(data__->MS,) - __UDINT_LITERAL(1000)));
    };
    __SET_VAR(data__->,CYCLES,,(__GET_VAR(data__->CYCLES,) + BOOL_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)!(__GET_VAR(data__->EDGE,)))));
  };
  __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->IN,));

  goto __end;

__end:
  return;
} // ONTIME_body__() 





void M_TX_init__(M_TX *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TMAX,__time_to_timespec(1, 0, 0, 0, 0, 10),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TH,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TL,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DC,0,retain)
  __INIT_VAR(data__->F,0,retain)
  __INIT_VAR(data__->ET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->START,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->STOP,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->RISE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FALL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STARTUP,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void M_TX_body__(M_TX *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->RST,) || GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->ET,), __GET_VAR(data__->TMAX,)))) {
    __SET_VAR(data__->,RISE,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,FALL,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,STARTUP,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,TH,,__time_to_timespec(1, 0, 0, 0, 0, 0));
    __SET_VAR(data__->,TL,,__time_to_timespec(1, 0, 0, 0, 0, 0));
    __SET_VAR(data__->,DC,,0.0);
    __SET_VAR(data__->,F,,0.0);
    __SET_VAR(data__->,ET,,__time_to_timespec(1, 0, 0, 0, 0, 0));
  };
  if (!(__GET_VAR(data__->STARTUP,))) {
    __SET_VAR(data__->,EDGE,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->,STARTUP,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,TX,,UDINT_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)T_PLC_MS(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__BOOL_LITERAL(FALSE))));
  if ((__GET_VAR(data__->IN,) && !__GET_VAR(data__->EDGE,)) || (!__GET_VAR(data__->IN,) && __GET_VAR(data__->EDGE,))) {
    __SET_VAR(data__->,EDGE,,__GET_VAR(data__->IN,));
    if (__GET_VAR(data__->IN,)) {
      __SET_VAR(data__->,START,,__GET_VAR(data__->TX,));
      __SET_VAR(data__->,RISE,,__BOOL_LITERAL(TRUE));
      if (__GET_VAR(data__->FALL,)) {
        __SET_VAR(data__->,TL,,__time_sub(__GET_VAR(data__->START,), __GET_VAR(data__->STOP,)));
      };
      if ((GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TH,), __time_to_timespec(1, 0, 0, 0, 0, 0)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TL,), __time_to_timespec(1, 0, 0, 0, 0, 0)))) {
        __SET_VAR(data__->,DC,,(TIME_TO_REAL(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (TIME)__GET_VAR(data__->TH,)) / TIME_TO_REAL(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (TIME)__time_add(__GET_VAR(data__->TH,), __GET_VAR(data__->TL,)))));
        __SET_VAR(data__->,F,,(1000.0 / TIME_TO_REAL(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (TIME)__time_add(__GET_VAR(data__->TH,), __GET_VAR(data__->TL,)))));
      };
    } else {
      __SET_VAR(data__->,STOP,,__GET_VAR(data__->TX,));
      __SET_VAR(data__->,FALL,,__BOOL_LITERAL(TRUE));
      if (__GET_VAR(data__->RISE,)) {
        __SET_VAR(data__->,TH,,__time_sub(__GET_VAR(data__->STOP,), __GET_VAR(data__->START,)));
      };
      if ((GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TH,), __time_to_timespec(1, 0, 0, 0, 0, 0)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TL,), __time_to_timespec(1, 0, 0, 0, 0, 0)))) {
        __SET_VAR(data__->,DC,,(TIME_TO_REAL(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (TIME)__GET_VAR(data__->TH,)) / TIME_TO_REAL(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (TIME)__time_add(__GET_VAR(data__->TH,), __GET_VAR(data__->TL,)))));
        __SET_VAR(data__->,F,,(1000.0 / TIME_TO_REAL(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (TIME)__time_add(__GET_VAR(data__->TH,), __GET_VAR(data__->TL,)))));
      };
    };
  };
  if (__GET_VAR(data__->RISE,)) {
    __SET_VAR(data__->,ET,,__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->START,)));
  };

  goto __end;

__end:
  return;
} // M_TX_body__() 





void BAR_GRAPH_init__(BAR_GRAPH *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGER_LOW,0,retain)
  __INIT_VAR(data__->TRIGGER_HIGH,0,retain)
  __INIT_VAR(data__->ALARM_LOW,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ALARM_HIGH,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LOG_SCALE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LOW,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q5,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q6,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->HIGH,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ALARM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATUS,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->T1,0,retain)
  __INIT_VAR(data__->T2,0,retain)
  __INIT_VAR(data__->T3,0,retain)
  __INIT_VAR(data__->T4,0,retain)
  __INIT_VAR(data__->T5,0,retain)
  __INIT_VAR(data__->TEMP,0,retain)
}

// Code part
void BAR_GRAPH_body__(BAR_GRAPH *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    if (__GET_VAR(data__->LOG_SCALE,)) {
      __SET_VAR(data__->,TEMP,,EXP__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)(LN__REAL__REAL(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (REAL)(__GET_VAR(data__->TRIGGER_HIGH,) / __GET_VAR(data__->TRIGGER_LOW,))) * 0.166666666666666666666)));
      __SET_VAR(data__->,T1,,(__GET_VAR(data__->TRIGGER_LOW,) * __GET_VAR(data__->TEMP,)));
      __SET_VAR(data__->,T2,,(__GET_VAR(data__->T1,) * __GET_VAR(data__->TEMP,)));
      __SET_VAR(data__->,T3,,(__GET_VAR(data__->T2,) * __GET_VAR(data__->TEMP,)));
      __SET_VAR(data__->,T4,,(__GET_VAR(data__->T3,) * __GET_VAR(data__->TEMP,)));
      __SET_VAR(data__->,T5,,(__GET_VAR(data__->T4,) * __GET_VAR(data__->TEMP,)));
    } else {
      __SET_VAR(data__->,TEMP,,((__GET_VAR(data__->TRIGGER_HIGH,) - __GET_VAR(data__->TRIGGER_LOW,)) * 0.142857142));
      __SET_VAR(data__->,T1,,(__GET_VAR(data__->TRIGGER_LOW,) + __GET_VAR(data__->TEMP,)));
      __SET_VAR(data__->,T2,,(__GET_VAR(data__->T1,) + __GET_VAR(data__->TEMP,)));
      __SET_VAR(data__->,T3,,(__GET_VAR(data__->T2,) + __GET_VAR(data__->TEMP,)));
      __SET_VAR(data__->,T4,,(__GET_VAR(data__->T3,) + __GET_VAR(data__->TEMP,)));
      __SET_VAR(data__->,T5,,(__GET_VAR(data__->T4,) + __GET_VAR(data__->TEMP,)));
    };
  };
  __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,Q3,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,Q4,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,Q5,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,Q6,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(110));
  if (!(__GET_VAR(data__->ALARM_LOW,))) {
    __SET_VAR(data__->,LOW,,__BOOL_LITERAL(FALSE));
  };
  if (!(__GET_VAR(data__->ALARM_HIGH,))) {
    __SET_VAR(data__->,HIGH,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,ALARM,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,LOW,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,HIGH,,__BOOL_LITERAL(FALSE));
  };
  if ((__GET_VAR(data__->X,) < __GET_VAR(data__->TRIGGER_LOW,))) {
    __SET_VAR(data__->,LOW,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(111));
    if (__GET_VAR(data__->ALARM_LOW,)) {
      __SET_VAR(data__->,ALARM,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(1));
    };
  } else if ((__GET_VAR(data__->X,) < __GET_VAR(data__->T1,))) {
    __SET_VAR(data__->,Q1,,__BOOL_LITERAL(TRUE));
  } else if ((__GET_VAR(data__->X,) < __GET_VAR(data__->T2,))) {
    __SET_VAR(data__->,Q2,,__BOOL_LITERAL(TRUE));
  } else if ((__GET_VAR(data__->X,) < __GET_VAR(data__->T3,))) {
    __SET_VAR(data__->,Q3,,__BOOL_LITERAL(TRUE));
  } else if ((__GET_VAR(data__->X,) < __GET_VAR(data__->T4,))) {
    __SET_VAR(data__->,Q4,,__BOOL_LITERAL(TRUE));
  } else if ((__GET_VAR(data__->X,) < __GET_VAR(data__->T5,))) {
    __SET_VAR(data__->,Q5,,__BOOL_LITERAL(TRUE));
  } else if ((__GET_VAR(data__->X,) < __GET_VAR(data__->TRIGGER_HIGH,))) {
    __SET_VAR(data__->,Q6,,__BOOL_LITERAL(TRUE));
  } else {
    __SET_VAR(data__->,HIGH,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(112));
    if (__GET_VAR(data__->ALARM_HIGH,)) {
      __SET_VAR(data__->,ALARM,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(2));
    };
  };

  goto __end;

__end:
  return;
} // BAR_GRAPH_body__() 





void FLOW_METER_init__(FLOW_METER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->VX,0,retain)
  __INIT_VAR(data__->_E,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PULSE_MODE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UPDATE_TIME,__time_to_timespec(1, 0, 1, 0, 0, 0),retain)
  __INIT_VAR(data__->F,0,retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TL,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  INTEGRATE_init__(&data__->INT1,retain);
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->E_LAST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TMP,0,retain)
  __INIT_VAR(data__->X_LAST,0,retain)
  __INIT_VAR(data__->Y_LAST,0,retain)
}

// Code part
void FLOW_METER_body__(FLOW_METER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,TL,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,X_LAST,,__GET_VAR(data__->X,));
    __SET_VAR(data__->,Y_LAST,,__GET_VAR(data__->Y,));
    __SET_VAR(data__->,INT1.K,,2.7777777777777777E-4);
  };
  __SET_VAR(data__->INT1.,_E,,(!((__GET_VAR(data__->RST,) || __GET_VAR(data__->PULSE_MODE,))) && __GET_VAR(data__->_E,)));
  __SET_VAR(data__->INT1.,X,,__GET_VAR(data__->VX,));
  __SET_VAR(data__->INT1.,Y,,__GET_VAR(data__->X,));
  INTEGRATE_body__(&data__->INT1);
  __SET_VAR(data__->,X,,__GET_VAR(data__->INT1.Y));
  __SET_VAR(data__->,X,,__GET_VAR(data__->INT1.Y,));
  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,X,,0.0);
    __SET_VAR(data__->,Y,,__UDINT_LITERAL(0));
    __SET_VAR(data__->,TL,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,X_LAST,,0.0);
    __SET_VAR(data__->,Y_LAST,,__UDINT_LITERAL(0));
  } else if ((__GET_VAR(data__->_E,) && __GET_VAR(data__->PULSE_MODE,))) {
    if (!(__GET_VAR(data__->E_LAST,))) {
      __SET_VAR(data__->,X,,(__GET_VAR(data__->X,) + __GET_VAR(data__->VX,)));
    };
  };
  __SET_VAR(data__->,E_LAST,,__GET_VAR(data__->_E,));
  if ((__GET_VAR(data__->X,) > 1.0)) {
    __SET_VAR(data__->,TMP,,FLOOR(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)__GET_VAR(data__->X,)));
    __SET_VAR(data__->,Y,,(__GET_VAR(data__->Y,) + INT_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)__GET_VAR(data__->TMP,))));
    __SET_VAR(data__->,X,,(__GET_VAR(data__->X,) - INT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)__GET_VAR(data__->TMP,))));
  };
  __SET_VAR(data__->,TX,,UDINT_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)T_PLC_MS(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__BOOL_LITERAL(FALSE))));
  if ((GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->TL,)), __GET_VAR(data__->UPDATE_TIME,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->UPDATE_TIME,), __time_to_timespec(1, 0, 0, 0, 0, 0)))) {
    __SET_VAR(data__->,F,,((((UDINT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)(__GET_VAR(data__->Y,) - __GET_VAR(data__->Y_LAST,))) + __GET_VAR(data__->X,)) - __GET_VAR(data__->X_LAST,)) / TIME_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->TL,)))) * 3.6E6));
    __SET_VAR(data__->,Y_LAST,,__GET_VAR(data__->Y,));
    __SET_VAR(data__->,X_LAST,,__GET_VAR(data__->X,));
    __SET_VAR(data__->,TL,,__GET_VAR(data__->TX,));
  };

  goto __end;

__end:
  return;
} // FLOW_METER_body__() 





