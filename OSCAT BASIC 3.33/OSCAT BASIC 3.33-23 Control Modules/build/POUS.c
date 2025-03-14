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


void FT_PIWL_init__(FT_PIWL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->KP,1.0,retain)
  __INIT_VAR(data__->KI,1.0,retain)
  __INIT_VAR(data__->LIM_L,-1.0E38,retain)
  __INIT_VAR(data__->LIM_H,1.0E38,retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->LIM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TX,0,retain)
  __INIT_VAR(data__->TC,0,retain)
  __INIT_VAR(data__->T_LAST,0,retain)
  __INIT_VAR(data__->IN_LAST,0,retain)
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->P,0,retain)
}

// Code part
void FT_PIWL_body__(FT_PIWL *data__) {
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
    __SET_VAR(data__->,IN_LAST,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->,T_LAST,,T_PLC_US(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__BOOL_LITERAL(FALSE)));
    __SET_VAR(data__->,I,,0.0);
    __SET_VAR(data__->,TC,,0.0);
  } else {
    __SET_VAR(data__->,TX,,T_PLC_US(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__BOOL_LITERAL(FALSE)));
    __SET_VAR(data__->,TC,,UDINT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)(__GET_VAR(data__->TX,) - __GET_VAR(data__->T_LAST,))));
    __SET_VAR(data__->,T_LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,P,,(__GET_VAR(data__->KP,) * __GET_VAR(data__->IN,)));
    __SET_VAR(data__->,I,,(((((__GET_VAR(data__->IN,) + __GET_VAR(data__->IN_LAST,)) * 5.0E-7) * __GET_VAR(data__->KI,)) * __GET_VAR(data__->TC,)) + __GET_VAR(data__->I,)));
    __SET_VAR(data__->,IN_LAST,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->,Y,,(__GET_VAR(data__->P,) + __GET_VAR(data__->I,)));
    if ((__GET_VAR(data__->Y,) >= __GET_VAR(data__->LIM_H,))) {
      __SET_VAR(data__->,Y,,__GET_VAR(data__->LIM_H,));
      if ((__GET_VAR(data__->KI,) != 0.0)) {
        __SET_VAR(data__->,I,,(__GET_VAR(data__->LIM_H,) - __GET_VAR(data__->P,)));
      } else {
        __SET_VAR(data__->,I,,0.0);
      };
      __SET_VAR(data__->,LIM,,__BOOL_LITERAL(TRUE));
    } else if ((__GET_VAR(data__->Y,) <= __GET_VAR(data__->LIM_L,))) {
      __SET_VAR(data__->,Y,,__GET_VAR(data__->LIM_L,));
      if ((__GET_VAR(data__->KI,) != 0.0)) {
        __SET_VAR(data__->,I,,(__GET_VAR(data__->LIM_L,) - __GET_VAR(data__->P,)));
      } else {
        __SET_VAR(data__->,I,,0.0);
      };
      __SET_VAR(data__->,LIM,,__BOOL_LITERAL(TRUE));
    } else {
      __SET_VAR(data__->,LIM,,__BOOL_LITERAL(FALSE));
    };
  };

  goto __end;

__end:
  return;
} // FT_PIWL_body__() 





void FT_DERIV_init__(FT_DERIV *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->K,1.0,retain)
  __INIT_VAR(data__->RUN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->OUT,0,retain)
  __INIT_VAR(data__->OLD,0,retain)
  __INIT_VAR(data__->TX,0,retain)
  __INIT_VAR(data__->LAST,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TC,0,retain)
}

// Code part
void FT_DERIV_body__(FT_DERIV *data__) {
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
  __SET_VAR(data__->,TC,,UDINT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)(__GET_VAR(data__->TX,) - __GET_VAR(data__->LAST,))));
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,OLD,,__GET_VAR(data__->IN,));
  } else if ((__GET_VAR(data__->RUN,) && (__GET_VAR(data__->TC,) > 0.0))) {
    __SET_VAR(data__->,OUT,,((((__GET_VAR(data__->IN,) - __GET_VAR(data__->OLD,)) / __GET_VAR(data__->TC,)) * 1000000.0) * __GET_VAR(data__->K,)));
    __SET_VAR(data__->,OLD,,__GET_VAR(data__->IN,));
  } else {
    __SET_VAR(data__->,OUT,,0.0);
  };
  __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));

  goto __end;

__end:
  return;
} // FT_DERIV_body__() 





void FT_PIDWL_init__(FT_PIDWL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->KP,1.0,retain)
  __INIT_VAR(data__->TN,1.0,retain)
  __INIT_VAR(data__->TV,1.0,retain)
  __INIT_VAR(data__->LIM_L,-1.0E38,retain)
  __INIT_VAR(data__->LIM_H,1.0E38,retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->LIM,__BOOL_LITERAL(FALSE),retain)
  FT_PIWL_init__(&data__->PIWL,retain);
  FT_DERIV_init__(&data__->DIFF,retain);
}

// Code part
void FT_PIDWL_body__(FT_PIDWL *data__) {
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
    __SET_VAR(data__->PIWL.,RST,,__BOOL_LITERAL(TRUE));
    FT_PIWL_body__(&data__->PIWL);
    __SET_VAR(data__->,PIWL.RST,,__BOOL_LITERAL(FALSE));
  } else {
    if ((__GET_VAR(data__->TN,) == 0.0)) {
      __SET_VAR(data__->PIWL.,IN,,(__GET_VAR(data__->IN,) * __GET_VAR(data__->KP,)));
      __SET_VAR(data__->PIWL.,KP,,1.0);
      __SET_VAR(data__->PIWL.,KI,,0.0);
      __SET_VAR(data__->PIWL.,LIM_L,,__GET_VAR(data__->LIM_L,));
      __SET_VAR(data__->PIWL.,LIM_H,,__GET_VAR(data__->LIM_H,));
      FT_PIWL_body__(&data__->PIWL);
    } else {
      __SET_VAR(data__->PIWL.,IN,,(__GET_VAR(data__->IN,) * __GET_VAR(data__->KP,)));
      __SET_VAR(data__->PIWL.,KP,,1.0);
      __SET_VAR(data__->PIWL.,KI,,(1.0 / __GET_VAR(data__->TN,)));
      __SET_VAR(data__->PIWL.,LIM_L,,__GET_VAR(data__->LIM_L,));
      __SET_VAR(data__->PIWL.,LIM_H,,__GET_VAR(data__->LIM_H,));
      FT_PIWL_body__(&data__->PIWL);
    };
    __SET_VAR(data__->DIFF.,IN,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->DIFF.,K,,(__GET_VAR(data__->KP,) * __GET_VAR(data__->TV,)));
    FT_DERIV_body__(&data__->DIFF);
    __SET_VAR(data__->,Y,,(__GET_VAR(data__->PIWL.Y,) + __GET_VAR(data__->DIFF.OUT,)));
    if ((__GET_VAR(data__->Y,) < __GET_VAR(data__->LIM_L,))) {
      __SET_VAR(data__->,LIM,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,Y,,__GET_VAR(data__->LIM_L,));
    } else if ((__GET_VAR(data__->Y,) > __GET_VAR(data__->LIM_H,))) {
      __SET_VAR(data__->,LIM,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,Y,,__GET_VAR(data__->LIM_H,));
    } else {
      __SET_VAR(data__->,LIM,,__BOOL_LITERAL(FALSE));
    };
  };

  goto __end;

__end:
  return;
} // FT_PIDWL_body__() 





void FT_PT1_init__(FT_PT1 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->_T,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->K,1.0,retain)
  __INIT_VAR(data__->OUT,0,retain)
  __INIT_VAR(data__->LAST,0,retain)
  __INIT_VAR(data__->TX,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void FT_PT1_body__(FT_PT1 *data__) {
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
  if ((!(__GET_VAR(data__->INIT,)) || EQ_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->_T,), __time_to_timespec(1, 0, 0, 0, 0, 0)))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,OUT,,(__GET_VAR(data__->K,) * __GET_VAR(data__->IN,)));
  } else {
    __SET_VAR(data__->,OUT,,(__GET_VAR(data__->OUT,) + (((((__GET_VAR(data__->IN,) * __GET_VAR(data__->K,)) - __GET_VAR(data__->OUT,)) * UDINT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)(__GET_VAR(data__->TX,) - __GET_VAR(data__->LAST,)))) / TIME_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)__GET_VAR(data__->_T,))) * 1.0E-3)));
    if ((ABS__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)__GET_VAR(data__->OUT,)) < 1.0E-20)) {
      __SET_VAR(data__->,OUT,,0.0);
    };
  };
  __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));

  goto __end;

__end:
  return;
} // FT_PT1_body__() 





void FT_IMP_init__(FT_IMP *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->_T,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->K,1.0,retain)
  __INIT_VAR(data__->OUT,0,retain)
  FT_PT1_init__(&data__->T1,retain);
}

// Code part
void FT_IMP_body__(FT_IMP *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->T1.,IN,,__GET_VAR(data__->IN,));
  __SET_VAR(data__->T1.,_T,,__GET_VAR(data__->_T,));
  FT_PT1_body__(&data__->T1);
  __SET_VAR(data__->,OUT,,((__GET_VAR(data__->IN,) - __GET_VAR(data__->T1.OUT,)) * __GET_VAR(data__->K,)));

  goto __end;

__end:
  return;
} // FT_IMP_body__() 





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
REAL DEAD_ZONE(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL L)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL DEAD_ZONE = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DEAD_ZONE;
  }
  if ((ABS__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)X) > L)) {
    DEAD_ZONE = X;
  } else {
    DEAD_ZONE = 0.0;
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return DEAD_ZONE;
}


void CONTROL_SET1_init__(CONTROL_SET1 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->KT,0,retain)
  __INIT_VAR(data__->TT,0,retain)
  __INIT_VAR(data__->_PI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_PID,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P_K,0.5,retain)
  __INIT_VAR(data__->PI_K,0.45,retain)
  __INIT_VAR(data__->PI_TN,0.83,retain)
  __INIT_VAR(data__->PID_K,0.6,retain)
  __INIT_VAR(data__->PID_TN,0.5,retain)
  __INIT_VAR(data__->PID_TV,0.125,retain)
  __INIT_VAR(data__->KP,0,retain)
  __INIT_VAR(data__->TN,0,retain)
  __INIT_VAR(data__->TV,0,retain)
  __INIT_VAR(data__->KI,0,retain)
  __INIT_VAR(data__->KD,0,retain)
}

// Code part
void CONTROL_SET1_body__(CONTROL_SET1 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->_PI,) && __GET_VAR(data__->_PID,))) {
    __SET_VAR(data__->,KP,,0.0);
    __SET_VAR(data__->,TN,,0.0);
    __SET_VAR(data__->,TV,,0.0);
  } else if (__GET_VAR(data__->_PID,)) {
    __SET_VAR(data__->,KP,,(__GET_VAR(data__->PID_K,) * __GET_VAR(data__->KT,)));
    __SET_VAR(data__->,TN,,(__GET_VAR(data__->PID_TN,) * __GET_VAR(data__->TT,)));
    __SET_VAR(data__->,TV,,(__GET_VAR(data__->PID_TV,) * __GET_VAR(data__->TT,)));
  } else if (__GET_VAR(data__->_PI,)) {
    __SET_VAR(data__->,KP,,(__GET_VAR(data__->PI_K,) * __GET_VAR(data__->KT,)));
    __SET_VAR(data__->,TN,,(__GET_VAR(data__->PI_TN,) * __GET_VAR(data__->TT,)));
  } else {
    __SET_VAR(data__->,KP,,(__GET_VAR(data__->P_K,) * __GET_VAR(data__->KT,)));
  };
  if ((__GET_VAR(data__->TN,) > 0.0)) {
    __SET_VAR(data__->,KI,,(__GET_VAR(data__->KP,) / __GET_VAR(data__->TN,)));
  } else {
    __SET_VAR(data__->,KI,,0.0);
  };
  __SET_VAR(data__->,KD,,(__GET_VAR(data__->KP,) * __GET_VAR(data__->TV,)));

  goto __end;

__end:
  return;
} // CONTROL_SET1_body__() 





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





void FT_INT_init__(FT_INT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->K,1.0,retain)
  __INIT_VAR(data__->RUN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT_MIN,-1.0E-37,retain)
  __INIT_VAR(data__->OUT_MAX,1.0E-37,retain)
  __INIT_VAR(data__->OUT,0,retain)
  __INIT_VAR(data__->LIM,__BOOL_LITERAL(FALSE),retain)
  INTEGRATE_init__(&data__->INTEG,retain);
}

// Code part
void FT_INT_body__(FT_INT *data__) {
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
    __SET_VAR(data__->,OUT,,0.0);
  } else {
    __SET_VAR(data__->INTEG.,_E,,__GET_VAR(data__->RUN,));
    __SET_VAR(data__->INTEG.,X,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->INTEG.,K,,__GET_VAR(data__->K,));
    __SET_VAR(data__->INTEG.,Y,,__GET_VAR(data__->OUT,));
    INTEGRATE_body__(&data__->INTEG);
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->INTEG.Y));
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->INTEG.Y,));
  };
  if ((__GET_VAR(data__->OUT,) >= __GET_VAR(data__->OUT_MAX,))) {
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->OUT_MAX,));
    __SET_VAR(data__->,LIM,,__BOOL_LITERAL(TRUE));
  } else if ((__GET_VAR(data__->OUT,) <= __GET_VAR(data__->OUT_MIN,))) {
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->OUT_MIN,));
    __SET_VAR(data__->,LIM,,__BOOL_LITERAL(TRUE));
  } else {
    __SET_VAR(data__->,LIM,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // FT_INT_body__() 





void FT_PIW_init__(FT_PIW *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->KP,1.0,retain)
  __INIT_VAR(data__->KI,1.0,retain)
  __INIT_VAR(data__->LIM_L,-1.0E38,retain)
  __INIT_VAR(data__->LIM_H,1.0E38,retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->LIM,__BOOL_LITERAL(FALSE),retain)
  FT_INT_init__(&data__->INTEG,retain);
}

// Code part
void FT_PIW_body__(FT_PIW *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->INTEG.,IN,,__GET_VAR(data__->IN,));
  __SET_VAR(data__->INTEG.,K,,__GET_VAR(data__->KI,));
  __SET_VAR(data__->INTEG.,RUN,,!(__GET_VAR(data__->LIM,)));
  __SET_VAR(data__->INTEG.,RST,,__GET_VAR(data__->RST,));
  FT_INT_body__(&data__->INTEG);
  __SET_VAR(data__->,Y,,((__GET_VAR(data__->KP,) * __GET_VAR(data__->IN,)) + __GET_VAR(data__->INTEG.OUT,)));
  if ((__GET_VAR(data__->Y,) < __GET_VAR(data__->LIM_L,))) {
    __SET_VAR(data__->,Y,,__GET_VAR(data__->LIM_L,));
    __SET_VAR(data__->,LIM,,__BOOL_LITERAL(TRUE));
  } else if ((__GET_VAR(data__->Y,) > __GET_VAR(data__->LIM_H,))) {
    __SET_VAR(data__->,Y,,__GET_VAR(data__->LIM_H,));
    __SET_VAR(data__->,LIM,,__BOOL_LITERAL(TRUE));
  } else {
    __SET_VAR(data__->,LIM,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // FT_PIW_body__() 





void R2_SET_init__(R2_SET *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X,0,retain)
  {
    static const REAL2 temp = {0,0};
    __SET_VAR(data__->,_R2_SET,,temp);
  }
}

// Code part
void R2_SET_body__(R2_SET *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_R2_SET,.RX,__GET_VAR(data__->X,));
  __SET_VAR(data__->,_R2_SET,.R1,0.0);

  goto __end;

__end:
  return;
} // R2_SET_body__() 





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





void FT_PID_init__(FT_PID *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->KP,1.0,retain)
  __INIT_VAR(data__->TN,1.0,retain)
  __INIT_VAR(data__->TV,1.0,retain)
  __INIT_VAR(data__->ILIM_L,-1.0E38,retain)
  __INIT_VAR(data__->ILIM_H,1.0E38,retain)
  __INIT_VAR(data__->IEN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->LIM,__BOOL_LITERAL(FALSE),retain)
  FT_INT_init__(&data__->INTEG,retain);
  FT_DERIV_init__(&data__->DIFF,retain);
}

// Code part
void FT_PID_body__(FT_PID *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TN,) > 0.0)) {
    __SET_VAR(data__->INTEG.,IN,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->INTEG.,K,,(1.0 / __GET_VAR(data__->TN,)));
    __SET_VAR(data__->INTEG.,RUN,,__GET_VAR(data__->IEN,));
    __SET_VAR(data__->INTEG.,RST,,__GET_VAR(data__->RST,));
    __SET_VAR(data__->INTEG.,OUT_MIN,,__GET_VAR(data__->ILIM_L,));
    __SET_VAR(data__->INTEG.,OUT_MAX,,__GET_VAR(data__->ILIM_H,));
    FT_INT_body__(&data__->INTEG);
  } else {
    __SET_VAR(data__->INTEG.,RST,,__BOOL_LITERAL(FALSE));
    FT_INT_body__(&data__->INTEG);
  };
  __SET_VAR(data__->DIFF.,IN,,__GET_VAR(data__->IN,));
  __SET_VAR(data__->DIFF.,K,,__GET_VAR(data__->TV,));
  FT_DERIV_body__(&data__->DIFF);
  __SET_VAR(data__->,Y,,(__GET_VAR(data__->KP,) * ((__GET_VAR(data__->INTEG.OUT,) + __GET_VAR(data__->DIFF.OUT,)) + __GET_VAR(data__->IN,))));
  __SET_VAR(data__->,LIM,,__GET_VAR(data__->INTEG.LIM,));

  goto __end;

__end:
  return;
} // FT_PID_body__() 





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





void CTRL_PWM_init__(CTRL_PWM *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->CI,0,retain)
  __INIT_VAR(data__->MAN_IN,0,retain)
  __INIT_VAR(data__->MANUAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->F,0,retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  PWM_DC_init__(&data__->PW,retain);
}

// Code part
void CTRL_PWM_body__(CTRL_PWM *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->PW.,F,,__GET_VAR(data__->F,));
  __SET_VAR(data__->PW.,DC,,SEL__REAL__BOOL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->MANUAL,),
    (REAL)__GET_VAR(data__->CI,),
    (REAL)__GET_VAR(data__->MAN_IN,)));
  PWM_DC_body__(&data__->PW);
  __SET_VAR(data__->,Q,,__GET_VAR(data__->PW.Q,));

  goto __end;

__end:
  return;
} // CTRL_PWM_body__() 





void DEAD_ZONE2_init__(DEAD_ZONE2 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->L,0,retain)
  __INIT_VAR(data__->Y,0,retain)
}

// Code part
void DEAD_ZONE2_body__(DEAD_ZONE2 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((ABS__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->X,)) > __GET_VAR(data__->L,))) {
    __SET_VAR(data__->,Y,,__GET_VAR(data__->X,));
  } else if ((__GET_VAR(data__->Y,) > 0.0)) {
    __SET_VAR(data__->,Y,,__GET_VAR(data__->L,));
  } else {
    __SET_VAR(data__->,Y,, -(__GET_VAR(data__->L,)));
  };

  goto __end;

__end:
  return;
} // DEAD_ZONE2_body__() 





// FUNCTION
REAL CTRL_IN(
  BOOL EN, 
  BOOL *__ENO, 
  REAL SET_POINT, 
  REAL ACTUAL, 
  REAL NOISE)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL CTRL_IN = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return CTRL_IN;
  }
  CTRL_IN = DEAD_ZONE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(SET_POINT - ACTUAL),
    (REAL)NOISE);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return CTRL_IN;
}


void FT_TN64_init__(FT_TN64 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->_T,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->OUT,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LENGTH,64,retain)
  {
    static const __ARRAY_OF_REAL_64 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,X,,temp);
  }
  __INIT_VAR(data__->CNT,0,retain)
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void FT_TN64_body__(FT_TN64 *data__) {
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
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,X,.table[(__GET_VAR(data__->CNT,)) - (0)],__GET_VAR(data__->IN,));
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
  } else if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __time_div(__GET_VAR(data__->_T,), __GET_VAR(data__->LENGTH,)))) {
    if ((__GET_VAR(data__->CNT,) == (__GET_VAR(data__->LENGTH,) - 1))) {
      __SET_VAR(data__->,CNT,,0);
    } else {
      __SET_VAR(data__->,CNT,,(__GET_VAR(data__->CNT,) + 1));
    };
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->X,.table[(__GET_VAR(data__->CNT,)) - (0)]));
    __SET_VAR(data__->,X,.table[(__GET_VAR(data__->CNT,)) - (0)],__GET_VAR(data__->IN,));
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,TRIG,,__BOOL_LITERAL(TRUE));
  };

  goto __end;

__end:
  return;
} // FT_TN64_body__() 





void HYST_init__(HYST *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->_ON,0,retain)
  __INIT_VAR(data__->OFF,0,retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->WIN,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void HYST_body__(HYST *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->_ON,) >= __GET_VAR(data__->OFF,))) {
    if ((__GET_VAR(data__->IN,) < __GET_VAR(data__->OFF,))) {
      __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,WIN,,__BOOL_LITERAL(FALSE));
    } else if ((__GET_VAR(data__->IN,) > __GET_VAR(data__->_ON,))) {
      __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,WIN,,__BOOL_LITERAL(FALSE));
    } else {
      __SET_VAR(data__->,WIN,,__BOOL_LITERAL(TRUE));
    };
  } else {
    if ((__GET_VAR(data__->IN,) > __GET_VAR(data__->OFF,))) {
      __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,WIN,,__BOOL_LITERAL(FALSE));
    } else if ((__GET_VAR(data__->IN,) < __GET_VAR(data__->_ON,))) {
      __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,WIN,,__BOOL_LITERAL(FALSE));
    } else {
      __SET_VAR(data__->,WIN,,__BOOL_LITERAL(TRUE));
    };
  };

  goto __end;

__end:
  return;
} // HYST_body__() 





void HYST_3_init__(HYST_3 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->_HYST,0,retain)
  __INIT_VAR(data__->VAL1,0,retain)
  __INIT_VAR(data__->VAL2,0,retain)
  __INIT_VAR(data__->Q1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->X,0,retain)
}

// Code part
void HYST_3_body__(HYST_3 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,X,,(__GET_VAR(data__->_HYST,) * 0.5));
  if ((__GET_VAR(data__->IN,) < (__GET_VAR(data__->VAL1,) - __GET_VAR(data__->X,)))) {
    __SET_VAR(data__->,Q1,,__BOOL_LITERAL(TRUE));
  } else if ((__GET_VAR(data__->IN,) > (__GET_VAR(data__->VAL1,) + __GET_VAR(data__->X,)))) {
    __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
  };
  if ((__GET_VAR(data__->IN,) < (__GET_VAR(data__->VAL2,) - __GET_VAR(data__->X,)))) {
    __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
  } else if ((__GET_VAR(data__->IN,) > (__GET_VAR(data__->VAL2,) + __GET_VAR(data__->X,)))) {
    __SET_VAR(data__->,Q2,,__BOOL_LITERAL(TRUE));
  };

  goto __end;

__end:
  return;
} // HYST_3_body__() 





void HYST_2_init__(HYST_2 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->VAL,0,retain)
  __INIT_VAR(data__->HYS,0,retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->WIN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TMP,0,retain)
}

// Code part
void HYST_2_body__(HYST_2 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,TMP,,(__GET_VAR(data__->VAL,) - (__GET_VAR(data__->HYS,) * 0.5)));
  if ((__GET_VAR(data__->IN,) < __GET_VAR(data__->TMP,))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,WIN,,__BOOL_LITERAL(FALSE));
  } else if ((__GET_VAR(data__->IN,) > (__GET_VAR(data__->TMP,) + __GET_VAR(data__->HYS,)))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,WIN,,__BOOL_LITERAL(FALSE));
  } else {
    __SET_VAR(data__->,WIN,,__BOOL_LITERAL(TRUE));
  };

  goto __end;

__end:
  return;
} // HYST_2_body__() 





void HYST_1_init__(HYST_1 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->HIGH,0,retain)
  __INIT_VAR(data__->LOW,0,retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->WIN,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void HYST_1_body__(HYST_1 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->IN,) < __GET_VAR(data__->LOW,))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,WIN,,__BOOL_LITERAL(FALSE));
  } else if ((__GET_VAR(data__->IN,) > __GET_VAR(data__->HIGH,))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,WIN,,__BOOL_LITERAL(FALSE));
  } else {
    __SET_VAR(data__->,WIN,,__BOOL_LITERAL(TRUE));
  };

  goto __end;

__end:
  return;
} // HYST_1_body__() 





void FT_INT2_init__(FT_INT2 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->K,1.0,retain)
  __INIT_VAR(data__->RUN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT_MIN,-1.0E-37,retain)
  __INIT_VAR(data__->OUT_MAX,1.0E37,retain)
  __INIT_VAR(data__->OUT,0,retain)
  __INIT_VAR(data__->LIM,__BOOL_LITERAL(FALSE),retain)
  INTEGRATE_init__(&data__->INTEG,retain);
  __INIT_VAR(data__->IX,0,retain)
  {
    static const REAL2 temp = {0,0};
    __SET_VAR(data__->,VAL,,temp);
  }
  R2_ADD_init__(&data__->_R2_ADD,retain);
  R2_SET_init__(&data__->_R2_SET,retain);
}

// Code part
void FT_INT2_body__(FT_INT2 *data__) {
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
    __SET_VAR(data__->_R2_SET.,X,,0.0);
    R2_SET_body__(&data__->_R2_SET);
    __SET_VAR(data__->,VAL,,__GET_VAR(data__->_R2_SET._R2_SET,));
    __SET_VAR(data__->,OUT,,0.0);
  } else {
    __SET_VAR(data__->INTEG.,_E,,__GET_VAR(data__->RUN,));
    __SET_VAR(data__->INTEG.,X,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->INTEG.,K,,__GET_VAR(data__->K,));
    __SET_VAR(data__->INTEG.,Y,,__GET_VAR(data__->IX,));
    INTEGRATE_body__(&data__->INTEG);
    __SET_VAR(data__->,IX,,__GET_VAR(data__->INTEG.Y));
    __SET_VAR(data__->,IX,,__GET_VAR(data__->INTEG.Y,));
    __SET_VAR(data__->_R2_ADD.,X,,__GET_VAR(data__->VAL,));
    __SET_VAR(data__->_R2_ADD.,Y,,__GET_VAR(data__->IX,));
    R2_ADD_body__(&data__->_R2_ADD);
    __SET_VAR(data__->,VAL,,__GET_VAR(data__->_R2_ADD._R2_ADD,));
    __SET_VAR(data__->,IX,,0.0);
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->VAL,.RX));
  };
  if (((__GET_VAR(data__->OUT,) > __GET_VAR(data__->OUT_MIN,)) && (__GET_VAR(data__->OUT,) < __GET_VAR(data__->OUT_MAX,)))) {
    __SET_VAR(data__->,LIM,,__BOOL_LITERAL(FALSE));
  } else {
    __SET_VAR(data__->,OUT,,LIMIT__REAL__REAL__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)__GET_VAR(data__->OUT_MIN,),
      (REAL)__GET_VAR(data__->OUT,),
      (REAL)__GET_VAR(data__->OUT_MAX,)));
    __SET_VAR(data__->_R2_SET.,X,,__GET_VAR(data__->OUT,));
    R2_SET_body__(&data__->_R2_SET);
    __SET_VAR(data__->,VAL,,__GET_VAR(data__->_R2_SET._R2_SET,));
    __SET_VAR(data__->,LIM,,__BOOL_LITERAL(TRUE));
  };

  goto __end;

__end:
  return;
} // FT_INT2_body__() 





void CTRL_OUT_init__(CTRL_OUT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->CI,0,retain)
  __INIT_VAR(data__->OFFSET,0,retain)
  __INIT_VAR(data__->MAN_IN,0,retain)
  __INIT_VAR(data__->LIM_L,0,retain)
  __INIT_VAR(data__->LIM_H,0,retain)
  __INIT_VAR(data__->MANUAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->LIM,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void CTRL_OUT_body__(CTRL_OUT *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,Y,,(SEL__REAL__BOOL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->MANUAL,),
    (REAL)__GET_VAR(data__->CI,),
    (REAL)__GET_VAR(data__->MAN_IN,)) + __GET_VAR(data__->OFFSET,)));
  if ((__GET_VAR(data__->Y,) >= __GET_VAR(data__->LIM_H,))) {
    __SET_VAR(data__->,Y,,__GET_VAR(data__->LIM_H,));
    __SET_VAR(data__->,LIM,,__BOOL_LITERAL(TRUE));
  } else if ((__GET_VAR(data__->Y,) <= __GET_VAR(data__->LIM_L,))) {
    __SET_VAR(data__->,Y,,__GET_VAR(data__->LIM_L,));
    __SET_VAR(data__->,LIM,,__BOOL_LITERAL(TRUE));
  } else {
    __SET_VAR(data__->,LIM,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // CTRL_OUT_body__() 





void FT_PT2_init__(FT_PT2 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->_T,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->_D,0,retain)
  __INIT_VAR(data__->K,1.0,retain)
  __INIT_VAR(data__->OUT,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  INTEGRATE_init__(&data__->INT1,retain);
  INTEGRATE_init__(&data__->INT2,retain);
  __INIT_VAR(data__->TN,0,retain)
  __INIT_VAR(data__->I1,0,retain)
  __INIT_VAR(data__->I2,0,retain)
  __INIT_VAR(data__->TN2,0,retain)
}

// Code part
void FT_PT2_body__(FT_PT2 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((!(__GET_VAR(data__->INIT,)) || EQ_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->_T,), __time_to_timespec(1, 0, 0, 0, 0, 0)))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,OUT,,(__GET_VAR(data__->K,) * __GET_VAR(data__->IN,)));
    __SET_VAR(data__->,I2,,__GET_VAR(data__->OUT,));
  } else {
    __SET_VAR(data__->,TN,,(TIME_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)__GET_VAR(data__->_T,)) / 1000.0));
    __SET_VAR(data__->,TN2,,(__GET_VAR(data__->TN,) * __GET_VAR(data__->TN,)));
    __SET_VAR(data__->INT1.,X,,((((__GET_VAR(data__->IN,) * __GET_VAR(data__->K,)) / __GET_VAR(data__->TN2,)) - (((__GET_VAR(data__->I1,) * 0.5) * __GET_VAR(data__->_D,)) / __GET_VAR(data__->TN,))) - (__GET_VAR(data__->I2,) / __GET_VAR(data__->TN2,))));
    __SET_VAR(data__->INT1.,Y,,__GET_VAR(data__->I1,));
    INTEGRATE_body__(&data__->INT1);
    __SET_VAR(data__->,I1,,__GET_VAR(data__->INT1.Y));
    __SET_VAR(data__->,I1,,__GET_VAR(data__->INT1.Y,));
    __SET_VAR(data__->INT2.,X,,__GET_VAR(data__->I1,));
    __SET_VAR(data__->INT2.,Y,,__GET_VAR(data__->I2,));
    INTEGRATE_body__(&data__->INT2);
    __SET_VAR(data__->,I2,,__GET_VAR(data__->INT2.Y));
    __SET_VAR(data__->,I2,,__GET_VAR(data__->INT2.Y,));
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->I2,));
  };

  goto __end;

__end:
  return;
} // FT_PT2_body__() 





void FT_PIDW_init__(FT_PIDW *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->KP,1.0,retain)
  __INIT_VAR(data__->TN,1.0,retain)
  __INIT_VAR(data__->TV,1.0,retain)
  __INIT_VAR(data__->LIM_L,-1.0E38,retain)
  __INIT_VAR(data__->LIM_H,1.0E38,retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->LIM,__BOOL_LITERAL(FALSE),retain)
  INTEGRATE_init__(&data__->INTEG,retain);
  FT_DERIV_init__(&data__->DIFF,retain);
  __INIT_VAR(data__->YI,0,retain)
}

// Code part
void FT_PIDW_body__(FT_PIDW *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (((__GET_VAR(data__->TN,) == 0.0) || __GET_VAR(data__->RST,))) {
    __SET_VAR(data__->INTEG.,_E,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->INTEG.,Y,,__GET_VAR(data__->YI,));
    INTEGRATE_body__(&data__->INTEG);
    __SET_VAR(data__->,YI,,__GET_VAR(data__->INTEG.Y));
    __SET_VAR(data__->,YI,,__GET_VAR(data__->INTEG.Y,));
    __SET_VAR(data__->,YI,,0.0);
  } else {
    __SET_VAR(data__->INTEG.,_E,,!(__GET_VAR(data__->LIM,)));
    __SET_VAR(data__->INTEG.,X,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->INTEG.,K,,(1.0 / __GET_VAR(data__->TN,)));
    __SET_VAR(data__->INTEG.,Y,,__GET_VAR(data__->YI,));
    INTEGRATE_body__(&data__->INTEG);
    __SET_VAR(data__->,YI,,__GET_VAR(data__->INTEG.Y));
    __SET_VAR(data__->,YI,,__GET_VAR(data__->INTEG.Y,));
  };
  __SET_VAR(data__->,Y,,(__GET_VAR(data__->KP,) * (__GET_VAR(data__->IN,) + __GET_VAR(data__->YI,))));
  __SET_VAR(data__->DIFF.,IN,,__GET_VAR(data__->IN,));
  __SET_VAR(data__->DIFF.,K,,__GET_VAR(data__->TV,));
  FT_DERIV_body__(&data__->DIFF);
  if (((__GET_VAR(data__->Y,) > __GET_VAR(data__->LIM_L,)) && (__GET_VAR(data__->Y,) < __GET_VAR(data__->LIM_H,)))) {
    __SET_VAR(data__->,LIM,,__BOOL_LITERAL(FALSE));
  } else {
    __SET_VAR(data__->,LIM,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,Y,,LIMIT__REAL__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->LIM_L,),
    (REAL)(__GET_VAR(data__->Y,) + (__GET_VAR(data__->KP,) * __GET_VAR(data__->DIFF.OUT,))),
    (REAL)__GET_VAR(data__->LIM_H,)));

  goto __end;

__end:
  return;
} // FT_PIDW_body__() 





void FT_PDT1_init__(FT_PDT1 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->KP,1.0,retain)
  __INIT_VAR(data__->TV,1.0,retain)
  __INIT_VAR(data__->T1,1.0,retain)
  __INIT_VAR(data__->Y,0,retain)
  FT_DERIV_init__(&data__->DIFF,retain);
  FT_PT1_init__(&data__->_TP,retain);
}

// Code part
void FT_PDT1_body__(FT_PDT1 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->DIFF.,IN,,__GET_VAR(data__->IN,));
  __SET_VAR(data__->DIFF.,K,,__GET_VAR(data__->TV,));
  FT_DERIV_body__(&data__->DIFF);
  __SET_VAR(data__->_TP.,IN,,__GET_VAR(data__->DIFF.OUT,));
  __SET_VAR(data__->_TP.,_T,,REAL_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->T1,)));
  FT_PT1_body__(&data__->_TP);
  __SET_VAR(data__->,Y,,(__GET_VAR(data__->KP,) * (__GET_VAR(data__->_TP.OUT,) + __GET_VAR(data__->IN,))));

  goto __end;

__end:
  return;
} // FT_PDT1_body__() 





// FUNCTION
REAL DEAD_BAND(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL L)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL DEAD_BAND = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DEAD_BAND;
  }
  if ((X > L)) {
    DEAD_BAND = (X - L);
  } else if ((X <  -(L))) {
    DEAD_BAND = (X + L);
  } else {
    DEAD_BAND = 0.0;
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return DEAD_BAND;
}


void FT_PD_init__(FT_PD *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->KP,1.0,retain)
  __INIT_VAR(data__->TV,1.0,retain)
  __INIT_VAR(data__->Y,0,retain)
  FT_DERIV_init__(&data__->DIFF,retain);
}

// Code part
void FT_PD_body__(FT_PD *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->DIFF.,IN,,__GET_VAR(data__->IN,));
  __SET_VAR(data__->DIFF.,K,,__GET_VAR(data__->TV,));
  FT_DERIV_body__(&data__->DIFF);
  __SET_VAR(data__->,Y,,(__GET_VAR(data__->KP,) * (__GET_VAR(data__->DIFF.OUT,) + __GET_VAR(data__->IN,))));

  goto __end;

__end:
  return;
} // FT_PD_body__() 





// FUNCTION
BYTE BAND_B(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE X, 
  BYTE B)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BYTE BAND_B = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return BAND_B;
  }
  if ((X < B)) {
    BAND_B = __BYTE_LITERAL(0);
  } else if ((X > USINT_TO_BYTE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (USINT)(__USINT_LITERAL(255) - BYTE_TO_USINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)B))))) {
    BAND_B = __BYTE_LITERAL(255);
  } else {
    BAND_B = X;
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return BAND_B;
}


void FT_PI_init__(FT_PI *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->KP,1.0,retain)
  __INIT_VAR(data__->KI,1.0,retain)
  __INIT_VAR(data__->ILIM_L,-1.0E38,retain)
  __INIT_VAR(data__->ILIM_H,1.0E38,retain)
  __INIT_VAR(data__->IEN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->LIM,__BOOL_LITERAL(FALSE),retain)
  FT_INT_init__(&data__->INTEG,retain);
}

// Code part
void FT_PI_body__(FT_PI *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->INTEG.,IN,,__GET_VAR(data__->IN,));
  __SET_VAR(data__->INTEG.,K,,__GET_VAR(data__->KI,));
  __SET_VAR(data__->INTEG.,RUN,,__GET_VAR(data__->IEN,));
  __SET_VAR(data__->INTEG.,RST,,__GET_VAR(data__->RST,));
  __SET_VAR(data__->INTEG.,OUT_MIN,,__GET_VAR(data__->ILIM_L,));
  __SET_VAR(data__->INTEG.,OUT_MAX,,__GET_VAR(data__->ILIM_H,));
  FT_INT_body__(&data__->INTEG);
  __SET_VAR(data__->,LIM,,__GET_VAR(data__->INTEG.LIM,));
  __SET_VAR(data__->,Y,,((__GET_VAR(data__->KP,) * __GET_VAR(data__->IN,)) + __GET_VAR(data__->INTEG.OUT,)));

  goto __end;

__end:
  return;
} // FT_PI_body__() 





void CONTROL_SET12_init__(CONTROL_SET12 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->KS,0,retain)
  __INIT_VAR(data__->TU,0,retain)
  __INIT_VAR(data__->TG,0,retain)
  __INIT_VAR(data__->_PI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_PID,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->P_K,1.0,retain)
  __INIT_VAR(data__->PI_K,0.9,retain)
  __INIT_VAR(data__->PI_TN,3.33,retain)
  __INIT_VAR(data__->PID_K,1.2,retain)
  __INIT_VAR(data__->PID_TN,2.0,retain)
  __INIT_VAR(data__->PID_TV,0.5,retain)
  __INIT_VAR(data__->KP,0,retain)
  __INIT_VAR(data__->TN,0,retain)
  __INIT_VAR(data__->TV,0,retain)
  __INIT_VAR(data__->KI,0,retain)
  __INIT_VAR(data__->KD,0,retain)
  __INIT_VAR(data__->TX,0,retain)
}

// Code part
void CONTROL_SET12_body__(CONTROL_SET12 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (((__GET_VAR(data__->TU,) > 0.0) && (__GET_VAR(data__->KS,) > 0.0))) {
    __SET_VAR(data__->,TX,,((__GET_VAR(data__->TG,) / __GET_VAR(data__->TU,)) / __GET_VAR(data__->KS,)));
  };
  if ((__GET_VAR(data__->_PI,) && __GET_VAR(data__->_PID,))) {
    __SET_VAR(data__->,KP,,0.0);
    __SET_VAR(data__->,TN,,0.0);
    __SET_VAR(data__->,TV,,0.0);
  } else if (__GET_VAR(data__->_PID,)) {
    __SET_VAR(data__->,KP,,(__GET_VAR(data__->PID_K,) * __GET_VAR(data__->TX,)));
    __SET_VAR(data__->,TN,,(__GET_VAR(data__->PID_TN,) * __GET_VAR(data__->TU,)));
    __SET_VAR(data__->,TV,,(__GET_VAR(data__->PID_TV,) * __GET_VAR(data__->TU,)));
  } else if (__GET_VAR(data__->_PI,)) {
    __SET_VAR(data__->,KP,,(__GET_VAR(data__->PI_K,) * __GET_VAR(data__->TX,)));
    __SET_VAR(data__->,TN,,(__GET_VAR(data__->PI_TN,) * __GET_VAR(data__->TU,)));
  } else {
    __SET_VAR(data__->,KP,,(__GET_VAR(data__->P_K,) * __GET_VAR(data__->TX,)));
  };
  if ((__GET_VAR(data__->TN,) > 0.0)) {
    __SET_VAR(data__->,KI,,(__GET_VAR(data__->KP,) / __GET_VAR(data__->TN,)));
  } else {
    __SET_VAR(data__->,KI,,0.0);
  };
  __SET_VAR(data__->,KD,,(__GET_VAR(data__->KP,) * __GET_VAR(data__->TV,)));

  goto __end;

__end:
  return;
} // CONTROL_SET12_body__() 





void DEAD_BAND_A_init__(DEAD_BAND_A *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->_T,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->KL,1.0,retain)
  __INIT_VAR(data__->LM,0,retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->L,0,retain)
  FT_PT1_init__(&data__->TP1,retain);
  FT_PT1_init__(&data__->TP2,retain);
}

// Code part
void DEAD_BAND_A_body__(DEAD_BAND_A *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->TP1.,IN,,__GET_VAR(data__->X,));
  __SET_VAR(data__->TP1.,_T,,__GET_VAR(data__->_T,));
  FT_PT1_body__(&data__->TP1);
  __SET_VAR(data__->TP2.,IN,,ABS__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(__GET_VAR(data__->TP1.OUT,) - __GET_VAR(data__->X,))));
  __SET_VAR(data__->TP2.,_T,,MULTIME__TIME__TIME__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (TIME)__GET_VAR(data__->_T,),
    (REAL)4.0));
  FT_PT1_body__(&data__->TP2);
  __SET_VAR(data__->,L,,MIN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)(__GET_VAR(data__->KL,) * __GET_VAR(data__->TP2.OUT,)),
    (REAL)__GET_VAR(data__->LM,)));
  if ((__GET_VAR(data__->X,) > __GET_VAR(data__->L,))) {
    __SET_VAR(data__->,Y,,(__GET_VAR(data__->X,) - __GET_VAR(data__->L,)));
  } else if ((__GET_VAR(data__->X,) <  -(__GET_VAR(data__->L,)))) {
    __SET_VAR(data__->,Y,,(__GET_VAR(data__->X,) + __GET_VAR(data__->L,)));
  } else {
    __SET_VAR(data__->,Y,,0.0);
  };

  goto __end;

__end:
  return;
} // DEAD_BAND_A_body__() 





void FT_TN16_init__(FT_TN16 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->_T,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->OUT,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LENGTH,16,retain)
  {
    static const __ARRAY_OF_REAL_16 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,X,,temp);
  }
  __INIT_VAR(data__->CNT,0,retain)
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void FT_TN16_body__(FT_TN16 *data__) {
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
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,X,.table[(__GET_VAR(data__->CNT,)) - (0)],__GET_VAR(data__->IN,));
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
  } else if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __time_div(__GET_VAR(data__->_T,), __GET_VAR(data__->LENGTH,)))) {
    if ((__GET_VAR(data__->CNT,) == (__GET_VAR(data__->LENGTH,) - 1))) {
      __SET_VAR(data__->,CNT,,0);
    } else {
      __SET_VAR(data__->,CNT,,(__GET_VAR(data__->CNT,) + 1));
    };
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->X,.table[(__GET_VAR(data__->CNT,)) - (0)]));
    __SET_VAR(data__->,X,.table[(__GET_VAR(data__->CNT,)) - (0)],__GET_VAR(data__->IN,));
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,TRIG,,__BOOL_LITERAL(TRUE));
  };

  goto __end;

__end:
  return;
} // FT_TN16_body__() 





void CTRL_PID_init__(CTRL_PID *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ACT,0,retain)
  __INIT_VAR(data__->SET,0,retain)
  __INIT_VAR(data__->SUP,0,retain)
  __INIT_VAR(data__->OFS,0,retain)
  __INIT_VAR(data__->M_I,0,retain)
  __INIT_VAR(data__->MAN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->KP,1.0,retain)
  __INIT_VAR(data__->TN,1.0,retain)
  __INIT_VAR(data__->TV,1.0,retain)
  __INIT_VAR(data__->LL,-1000.0,retain)
  __INIT_VAR(data__->LH,1000.0,retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->DIFF,0,retain)
  __INIT_VAR(data__->LIM,__BOOL_LITERAL(FALSE),retain)
  FT_PIDWL_init__(&data__->_PID,retain);
  CTRL_OUT_init__(&data__->CO,retain);
}

// Code part
void CTRL_PID_body__(CTRL_PID *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,DIFF,,CTRL_IN(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->SET,),
    (REAL)__GET_VAR(data__->ACT,),
    (REAL)__GET_VAR(data__->SUP,)));
  __SET_VAR(data__->_PID.,IN,,__GET_VAR(data__->DIFF,));
  __SET_VAR(data__->_PID.,KP,,__GET_VAR(data__->KP,));
  __SET_VAR(data__->_PID.,TN,,__GET_VAR(data__->TN,));
  __SET_VAR(data__->_PID.,TV,,__GET_VAR(data__->TV,));
  __SET_VAR(data__->_PID.,LIM_L,,__GET_VAR(data__->LL,));
  __SET_VAR(data__->_PID.,LIM_H,,__GET_VAR(data__->LH,));
  __SET_VAR(data__->_PID.,RST,,__GET_VAR(data__->RST,));
  FT_PIDWL_body__(&data__->_PID);
  __SET_VAR(data__->CO.,CI,,__GET_VAR(data__->_PID.Y,));
  __SET_VAR(data__->CO.,OFFSET,,__GET_VAR(data__->OFS,));
  __SET_VAR(data__->CO.,MAN_IN,,__GET_VAR(data__->M_I,));
  __SET_VAR(data__->CO.,LIM_L,,__GET_VAR(data__->LL,));
  __SET_VAR(data__->CO.,LIM_H,,__GET_VAR(data__->LH,));
  __SET_VAR(data__->CO.,MANUAL,,__GET_VAR(data__->MAN,));
  CTRL_OUT_body__(&data__->CO);
  __SET_VAR(data__->,Y,,__GET_VAR(data__->CO.Y,));
  __SET_VAR(data__->,LIM,,__GET_VAR(data__->CO.LIM,));

  goto __end;

__end:
  return;
} // CTRL_PID_body__() 





void CTRL_PI_init__(CTRL_PI *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ACT,0,retain)
  __INIT_VAR(data__->SET,0,retain)
  __INIT_VAR(data__->SUP,0,retain)
  __INIT_VAR(data__->OFS,0,retain)
  __INIT_VAR(data__->M_I,0,retain)
  __INIT_VAR(data__->MAN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->KP,1.0,retain)
  __INIT_VAR(data__->KI,1.0,retain)
  __INIT_VAR(data__->LL,-1000.0,retain)
  __INIT_VAR(data__->LH,1000.0,retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->DIFF,0,retain)
  __INIT_VAR(data__->LIM,__BOOL_LITERAL(FALSE),retain)
  FT_PIWL_init__(&data__->PI,retain);
  CTRL_OUT_init__(&data__->CO,retain);
}

// Code part
void CTRL_PI_body__(CTRL_PI *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,DIFF,,CTRL_IN(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->SET,),
    (REAL)__GET_VAR(data__->ACT,),
    (REAL)__GET_VAR(data__->SUP,)));
  __SET_VAR(data__->PI.,IN,,__GET_VAR(data__->DIFF,));
  __SET_VAR(data__->PI.,KP,,__GET_VAR(data__->KP,));
  __SET_VAR(data__->PI.,KI,,__GET_VAR(data__->KI,));
  __SET_VAR(data__->PI.,LIM_L,,__GET_VAR(data__->LL,));
  __SET_VAR(data__->PI.,LIM_H,,__GET_VAR(data__->LH,));
  __SET_VAR(data__->PI.,RST,,__GET_VAR(data__->RST,));
  FT_PIWL_body__(&data__->PI);
  __SET_VAR(data__->CO.,CI,,__GET_VAR(data__->PI.Y,));
  __SET_VAR(data__->CO.,OFFSET,,__GET_VAR(data__->OFS,));
  __SET_VAR(data__->CO.,MAN_IN,,__GET_VAR(data__->M_I,));
  __SET_VAR(data__->CO.,LIM_L,,__GET_VAR(data__->LL,));
  __SET_VAR(data__->CO.,LIM_H,,__GET_VAR(data__->LH,));
  __SET_VAR(data__->CO.,MANUAL,,__GET_VAR(data__->MAN,));
  CTRL_OUT_body__(&data__->CO);
  __SET_VAR(data__->,Y,,__GET_VAR(data__->CO.Y,));
  __SET_VAR(data__->,LIM,,__GET_VAR(data__->CO.LIM,));

  goto __end;

__end:
  return;
} // CTRL_PI_body__() 





void FT_TN8_init__(FT_TN8 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->_T,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->OUT,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LENGTH,8,retain)
  {
    static const __ARRAY_OF_REAL_8 temp = {{0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,X,,temp);
  }
  __INIT_VAR(data__->CNT,0,retain)
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void FT_TN8_body__(FT_TN8 *data__) {
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
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,X,.table[(__GET_VAR(data__->CNT,)) - (0)],__GET_VAR(data__->IN,));
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
  } else if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __time_div(__GET_VAR(data__->_T,), __GET_VAR(data__->LENGTH,)))) {
    if ((__GET_VAR(data__->CNT,) == (__GET_VAR(data__->LENGTH,) - 1))) {
      __SET_VAR(data__->,CNT,,0);
    } else {
      __SET_VAR(data__->,CNT,,(__GET_VAR(data__->CNT,) + 1));
    };
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->X,.table[(__GET_VAR(data__->CNT,)) - (0)]));
    __SET_VAR(data__->,X,.table[(__GET_VAR(data__->CNT,)) - (0)],__GET_VAR(data__->IN,));
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,TRIG,,__BOOL_LITERAL(TRUE));
  };

  goto __end;

__end:
  return;
} // FT_TN8_body__() 





