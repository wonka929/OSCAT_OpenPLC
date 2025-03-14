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
BYTE BIT_LOAD_B(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE IN, 
  BOOL VAL, 
  INT POS)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BYTE BIT_LOAD_B = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return BIT_LOAD_B;
  }
  if (VAL) {
    BIT_LOAD_B = (IN | SHL__BYTE__BYTE__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__BYTE_LITERAL(1),
      (INT)POS));
  } else {
    BIT_LOAD_B = (IN & ~(SHL__BYTE__BYTE__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__BYTE_LITERAL(1),
      (INT)POS)));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return BIT_LOAD_B;
}


void INTERLOCK_4_init__(INTERLOCK_4 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->I0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->I1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->I2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->I3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_E,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MODE,0,retain)
  __INIT_VAR(data__->OUT,0,retain)
  __INIT_VAR(data__->_TP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->LAST,0,retain)
  __INIT_VAR(data__->OLD,0,retain)
  __INIT_VAR(data__->LMODE,0,retain)
}

// Code part
void INTERLOCK_4_body__(INTERLOCK_4 *data__) {
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
    if ((__GET_VAR(data__->MODE,) != __GET_VAR(data__->LMODE,))) {
      __SET_VAR(data__->,OUT,,__BYTE_LITERAL(0));
      __SET_VAR(data__->,LAST,,__BYTE_LITERAL(0));
      __SET_VAR(data__->,OLD,,__BYTE_LITERAL(0));
      __SET_VAR(data__->,LMODE,,__GET_VAR(data__->MODE,));
    };
    __SET_VAR(data__->,IN,,BIT_LOAD_B(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->IN,),
      (BOOL)__GET_VAR(data__->I0,),
      (INT)0));
    __SET_VAR(data__->,IN,,BIT_LOAD_B(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->IN,),
      (BOOL)__GET_VAR(data__->I1,),
      (INT)1));
    __SET_VAR(data__->,IN,,BIT_LOAD_B(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->IN,),
      (BOOL)__GET_VAR(data__->I2,),
      (INT)2));
    __SET_VAR(data__->,IN,,BIT_LOAD_B(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->IN,),
      (BOOL)__GET_VAR(data__->I3,),
      (INT)3));
    if ((__GET_VAR(data__->IN,) != __GET_VAR(data__->LAST,))) {
      {
        INT __case_expression = __GET_VAR(data__->MODE,);
        if ((__case_expression == 0)) {
          __SET_VAR(data__->,OUT,,__GET_VAR(data__->IN,));
        }
        else if ((__case_expression == 1)) {
          if (((__GET_VAR(data__->IN,) & __BYTE_LITERAL(0x08)) > __BYTE_LITERAL(0))) {
            __SET_VAR(data__->,OUT,,__BYTE_LITERAL(8));
          } else if (((__GET_VAR(data__->IN,) & __BYTE_LITERAL(0x04)) > __BYTE_LITERAL(0))) {
            __SET_VAR(data__->,OUT,,__BYTE_LITERAL(4));
          } else if (((__GET_VAR(data__->IN,) & __BYTE_LITERAL(0x02)) > __BYTE_LITERAL(0))) {
            __SET_VAR(data__->,OUT,,__BYTE_LITERAL(2));
          } else {
            __SET_VAR(data__->,OUT,,__GET_VAR(data__->IN,));
          };
        }
        else if ((__case_expression == 2)) {
          __SET_VAR(data__->,LAST,,((__GET_VAR(data__->IN,) ^ __GET_VAR(data__->LAST,)) & __GET_VAR(data__->IN,)));
          if (((__GET_VAR(data__->LAST,) & __BYTE_LITERAL(0x08)) > __BYTE_LITERAL(0))) {
            __SET_VAR(data__->,OUT,,__BYTE_LITERAL(8));
          } else if (((__GET_VAR(data__->LAST,) & __BYTE_LITERAL(0x04)) > __BYTE_LITERAL(0))) {
            __SET_VAR(data__->,OUT,,__BYTE_LITERAL(4));
          } else if (((__GET_VAR(data__->LAST,) & __BYTE_LITERAL(0x02)) > __BYTE_LITERAL(0))) {
            __SET_VAR(data__->,OUT,,__BYTE_LITERAL(2));
          } else {
            __SET_VAR(data__->,OUT,,__GET_VAR(data__->LAST,));
          };
        }
        else if ((__case_expression == 3)) {
          if (((__GET_VAR(data__->OUT,) & __GET_VAR(data__->IN,)) == __BYTE_LITERAL(0))) {
            if (((__GET_VAR(data__->IN,) & __BYTE_LITERAL(0x08)) > __BYTE_LITERAL(0))) {
              __SET_VAR(data__->,OUT,,__BYTE_LITERAL(8));
            } else if (((__GET_VAR(data__->IN,) & __BYTE_LITERAL(0x04)) > __BYTE_LITERAL(0))) {
              __SET_VAR(data__->,OUT,,__BYTE_LITERAL(4));
            } else if (((__GET_VAR(data__->IN,) & __BYTE_LITERAL(0x02)) > __BYTE_LITERAL(0))) {
              __SET_VAR(data__->,OUT,,__BYTE_LITERAL(2));
            } else {
              __SET_VAR(data__->,OUT,,__GET_VAR(data__->IN,));
            };
          };
        }
      };
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->IN,));
    };
    __SET_VAR(data__->,_TP,,(__GET_VAR(data__->OUT,) != __GET_VAR(data__->OLD,)));
    __SET_VAR(data__->,OLD,,__GET_VAR(data__->OUT,));
  } else {
    __SET_VAR(data__->,OUT,,__BYTE_LITERAL(0));
    __SET_VAR(data__->,LAST,,__BYTE_LITERAL(0));
    __SET_VAR(data__->,OLD,,__BYTE_LITERAL(0));
    __SET_VAR(data__->,LMODE,,0);
    __SET_VAR(data__->,_TP,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // INTERLOCK_4_body__() 





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


void INC_DEC_init__(INC_DEC *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->CHA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CHB,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,0,retain)
  __INIT_VAR(data__->DIR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CNT,0,retain)
  __INIT_VAR(data__->EDGEA,0,retain)
  __INIT_VAR(data__->CLK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CLKA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CLKB,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EDGEB,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AXB,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void INC_DEC_body__(INC_DEC *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,AXB,,(__GET_VAR(data__->CHA,) && !__GET_VAR(data__->CHB,)) || (!__GET_VAR(data__->CHA,) && __GET_VAR(data__->CHB,)));
  __SET_VAR(data__->,CLKA,,(__GET_VAR(data__->CHA,) && !__GET_VAR(data__->EDGEA,)) || (!__GET_VAR(data__->CHA,) && __GET_VAR(data__->EDGEA,)));
  __SET_VAR(data__->,EDGEA,,__GET_VAR(data__->CHA,));
  __SET_VAR(data__->,CLKB,,(__GET_VAR(data__->CHB,) && !__GET_VAR(data__->EDGEB,)) || (!__GET_VAR(data__->CHB,) && __GET_VAR(data__->EDGEB,)));
  __SET_VAR(data__->,EDGEB,,__GET_VAR(data__->CHB,));
  __SET_VAR(data__->,CLK,,(__GET_VAR(data__->CLKA,) || __GET_VAR(data__->CLKB,)));
  if ((__GET_VAR(data__->AXB,) && __GET_VAR(data__->CLKA,))) {
    __SET_VAR(data__->,DIR,,__BOOL_LITERAL(TRUE));
  };
  if ((__GET_VAR(data__->AXB,) && __GET_VAR(data__->CLKB,))) {
    __SET_VAR(data__->,DIR,,__BOOL_LITERAL(FALSE));
  };
  if ((__GET_VAR(data__->CLK,) && __GET_VAR(data__->DIR,))) {
    __SET_VAR(data__->,CNT,,(__GET_VAR(data__->CNT,) + 1));
  };
  if ((__GET_VAR(data__->CLK,) && !(__GET_VAR(data__->DIR,)))) {
    __SET_VAR(data__->,CNT,,(__GET_VAR(data__->CNT,) - 1));
  };
  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,CNT,,0);
  };

  goto __end;

__end:
  return;
} // INC_DEC_body__() 





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
INT _BYTE_TO_INT(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT _BYTE_TO_INT = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return _BYTE_TO_INT;
  }
  _BYTE_TO_INT = USINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (USINT)BYTE_TO_USINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)IN));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return _BYTE_TO_INT;
}


void SIGNAL_init__(SIGNAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SIG,0,retain)
  __INIT_VAR(data__->TS,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TX,0,retain)
  __INIT_VAR(data__->_STEP,0,retain)
}

// Code part
void SIGNAL_body__(SIGNAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (__GET_VAR(data__->IN,)) {
    __SET_VAR(data__->,TX,,UDINT_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)T_PLC_MS(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BOOL)__BOOL_LITERAL(FALSE))));
    if (GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TS,), __time_to_timespec(1, 0, 0, 0, 0, 0))) {
      __SET_VAR(data__->,_STEP,,DWORD_TO_BYTE(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)(UDINT_TO_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (UDINT)(DWORD_TO_UDINT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (DWORD)__GET_VAR(data__->TX,)) / TIME_TO_UDINT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (TIME)__GET_VAR(data__->TS,)))) & __DWORD_LITERAL(0x0007))));
    } else {
      __SET_VAR(data__->,_STEP,,DWORD_TO_BYTE(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)(SHR__DWORD__DWORD__SINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)__GET_VAR(data__->TX,),
          (SINT)7) & __DWORD_LITERAL(0x0007))));
    };
    __SET_VAR(data__->,_STEP,,SHL__BYTE__BYTE__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__BYTE_LITERAL(1),
      (INT)_BYTE_TO_INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->_STEP,))));
    __SET_VAR(data__->,Q,,((__GET_VAR(data__->_STEP,) & __GET_VAR(data__->SIG,)) > __BYTE_LITERAL(0)));
  } else {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // SIGNAL_body__() 





void SIGNAL_4_init__(SIGNAL_4 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TS,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->S1,0xFF,retain)
  __INIT_VAR(data__->S2,0xF0,retain)
  __INIT_VAR(data__->S3,0xAA,retain)
  __INIT_VAR(data__->S4,0xA0,retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  SIGNAL_init__(&data__->SIG,retain);
}

// Code part
void SIGNAL_4_body__(SIGNAL_4 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (__GET_VAR(data__->IN1,)) {
    __SET_VAR(data__->SIG.,IN,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->SIG.,SIG,,__GET_VAR(data__->S1,));
    __SET_VAR(data__->SIG.,TS,,__GET_VAR(data__->TS,));
    SIGNAL_body__(&data__->SIG);
  } else if (__GET_VAR(data__->IN2,)) {
    __SET_VAR(data__->SIG.,IN,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->SIG.,SIG,,__GET_VAR(data__->S2,));
    __SET_VAR(data__->SIG.,TS,,__GET_VAR(data__->TS,));
    SIGNAL_body__(&data__->SIG);
  } else if (__GET_VAR(data__->IN3,)) {
    __SET_VAR(data__->SIG.,IN,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->SIG.,SIG,,__GET_VAR(data__->S3,));
    __SET_VAR(data__->SIG.,TS,,__GET_VAR(data__->TS,));
    SIGNAL_body__(&data__->SIG);
  } else if (__GET_VAR(data__->IN4,)) {
    __SET_VAR(data__->SIG.,IN,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->SIG.,SIG,,__GET_VAR(data__->S4,));
    __SET_VAR(data__->SIG.,TS,,__GET_VAR(data__->TS,));
    SIGNAL_body__(&data__->SIG);
  } else {
    __SET_VAR(data__->SIG.,IN,,__BOOL_LITERAL(FALSE));
    SIGNAL_body__(&data__->SIG);
  };
  __SET_VAR(data__->,Q,,__GET_VAR(data__->SIG.Q,));

  goto __end;

__end:
  return;
} // SIGNAL_4_body__() 





void INTERLOCK_init__(INTERLOCK *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->I1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->I2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TL,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Q1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q2,__BOOL_LITERAL(FALSE),retain)
  TOF_init__(&data__->T1,retain);
  TOF_init__(&data__->T2,retain);
}

// Code part
void INTERLOCK_body__(INTERLOCK *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->T1.,IN,,__GET_VAR(data__->I1,));
  __SET_VAR(data__->T1.,PT,,__GET_VAR(data__->TL,));
  TOF_body__(&data__->T1);
  __SET_VAR(data__->T2.,IN,,__GET_VAR(data__->I2,));
  __SET_VAR(data__->T2.,PT,,__GET_VAR(data__->TL,));
  TOF_body__(&data__->T2);
  __SET_VAR(data__->,Q1,,(__GET_VAR(data__->I1,) && !(__GET_VAR(data__->T2.Q,))));
  __SET_VAR(data__->,Q2,,(__GET_VAR(data__->I2,) && !(__GET_VAR(data__->T1.Q,))));

  goto __end;

__end:
  return;
} // INTERLOCK_body__() 





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





void SRAMP_init__(SRAMP *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->A_UP,0,retain)
  __INIT_VAR(data__->A_DN,0,retain)
  __INIT_VAR(data__->VU_MAX,0,retain)
  __INIT_VAR(data__->VD_MAX,0,retain)
  __INIT_VAR(data__->LIMIT_HIGH,0,retain)
  __INIT_VAR(data__->LIMIT_LOW,0,retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->V,0,retain)
  TC_S_init__(&data__->CYCLE_TIME,retain);
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void SRAMP_body__(SRAMP *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  TC_S_body__(&data__->CYCLE_TIME);
  __SET_VAR(data__->,A_UP,,MAX__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)0.0,
    (REAL)__GET_VAR(data__->A_UP,)));
  __SET_VAR(data__->,A_DN,,MIN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)0.0,
    (REAL)__GET_VAR(data__->A_DN,)));
  __SET_VAR(data__->,VU_MAX,,MAX__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)0.0,
    (REAL)__GET_VAR(data__->VU_MAX,)));
  __SET_VAR(data__->,VD_MAX,,MIN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)0.0,
    (REAL)__GET_VAR(data__->VD_MAX,)));
  if ((__GET_VAR(data__->RST,) || !(__GET_VAR(data__->INIT,)))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,Y,,0.0);
    __SET_VAR(data__->,V,,0.0);
  } else if ((__GET_VAR(data__->X,) == __GET_VAR(data__->Y,))) {
    __SET_VAR(data__->,V,,0.0);
  } else if ((__GET_VAR(data__->X,) > __GET_VAR(data__->Y,))) {
    __SET_VAR(data__->,V,,MIN__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)2,
      (REAL)(__GET_VAR(data__->V,) + (__GET_VAR(data__->A_UP,) * __GET_VAR(data__->CYCLE_TIME.TC,))),
      (REAL)__GET_VAR(data__->VU_MAX,)));
    __SET_VAR(data__->,V,,MIN__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)2,
      (REAL)SQRT__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)(((__GET_VAR(data__->Y,) - __GET_VAR(data__->X,)) * 2.0) * __GET_VAR(data__->A_DN,))),
      (REAL)__GET_VAR(data__->V,)));
    __SET_VAR(data__->,Y,,LIMIT__REAL__REAL__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)__GET_VAR(data__->LIMIT_LOW,),
      (REAL)(__GET_VAR(data__->Y,) + MIN__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UINT)2,
        (REAL)(__GET_VAR(data__->V,) * __GET_VAR(data__->CYCLE_TIME.TC,)),
        (REAL)(__GET_VAR(data__->X,) - __GET_VAR(data__->Y,)))),
      (REAL)__GET_VAR(data__->LIMIT_HIGH,)));
  } else if ((__GET_VAR(data__->X,) < __GET_VAR(data__->Y,))) {
    __SET_VAR(data__->,V,,MAX__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)2,
      (REAL)(__GET_VAR(data__->V,) + (__GET_VAR(data__->A_DN,) * __GET_VAR(data__->CYCLE_TIME.TC,))),
      (REAL)__GET_VAR(data__->VD_MAX,)));
    __SET_VAR(data__->,V,,MAX__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)2,
      (REAL) -(SQRT__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)(((__GET_VAR(data__->Y,) - __GET_VAR(data__->X,)) * 2.0) * __GET_VAR(data__->A_UP,)))),
      (REAL)__GET_VAR(data__->V,)));
    __SET_VAR(data__->,Y,,LIMIT__REAL__REAL__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)__GET_VAR(data__->LIMIT_LOW,),
      (REAL)(__GET_VAR(data__->Y,) + MAX__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UINT)2,
        (REAL)(__GET_VAR(data__->V,) * __GET_VAR(data__->CYCLE_TIME.TC,)),
        (REAL)(__GET_VAR(data__->X,) - __GET_VAR(data__->Y,)))),
      (REAL)__GET_VAR(data__->LIMIT_HIGH,)));
  };

  goto __end;

__end:
  return;
} // SRAMP_body__() 





void TUNE2_init__(TUNE2 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->SET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SU,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FU,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SS,0.1,retain)
  __INIT_VAR(data__->FS,5.0,retain)
  __INIT_VAR(data__->LIMIT_L,0,retain)
  __INIT_VAR(data__->LIMIT_H,100.0,retain)
  __INIT_VAR(data__->RST_VAL,0,retain)
  __INIT_VAR(data__->SET_VAL,100.0,retain)
  __INIT_VAR(data__->TR,__time_to_timespec(1, 500, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->S1,2.0,retain)
  __INIT_VAR(data__->S2,10.0,retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->TX,0,retain)
  __INIT_VAR(data__->START,0,retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_STEP,0,retain)
  __INIT_VAR(data__->SPEED,0,retain)
  __INIT_VAR(data__->Y_START,0,retain)
}

// Code part
void TUNE2_body__(TUNE2 *data__) {
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
  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,Y,,__GET_VAR(data__->RST_VAL,));
    __SET_VAR(data__->,STATE,,0);
  } else if (__GET_VAR(data__->SET,)) {
    __SET_VAR(data__->,Y,,__GET_VAR(data__->SET_VAL,));
    __SET_VAR(data__->,STATE,,0);
  } else if ((__GET_VAR(data__->STATE,) > 0)) {
    {
      INT __case_expression = __GET_VAR(data__->STATE,);
      if ((__case_expression == 1)) {
        __SET_VAR(data__->,IN,,__GET_VAR(data__->SU,));
      }
      else if ((__case_expression == 2)) {
        __SET_VAR(data__->,IN,,__GET_VAR(data__->SD,));
      }
      else if ((__case_expression == 3)) {
        __SET_VAR(data__->,IN,,__GET_VAR(data__->FU,));
      }
      else if ((__case_expression == 4)) {
        __SET_VAR(data__->,IN,,__GET_VAR(data__->FD,));
      }
    };
    if ((!(__GET_VAR(data__->IN,)) && ((__GET_VAR(data__->TX,) - __GET_VAR(data__->START,)) <= TIME_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)__GET_VAR(data__->TR,))))) {
      __SET_VAR(data__->,Y,,(__GET_VAR(data__->Y_START,) + __GET_VAR(data__->_STEP,)));
      __SET_VAR(data__->,STATE,,0);
    } else if ((__GET_VAR(data__->IN,) && ((__GET_VAR(data__->TX,) - __GET_VAR(data__->START,)) >= TIME_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)__GET_VAR(data__->TR,))))) {
      __SET_VAR(data__->,Y,,(__GET_VAR(data__->Y_START,) + (UDINT_TO_REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)((__GET_VAR(data__->TX,) - __GET_VAR(data__->START,)) - TIME_TO_UDINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (TIME)__GET_VAR(data__->TR,)))) * __GET_VAR(data__->SPEED,))));
    } else if (!(__GET_VAR(data__->IN,))) {
      __SET_VAR(data__->,STATE,,0);
    };
  } else if (__GET_VAR(data__->SU,)) {
    __SET_VAR(data__->,STATE,,1);
    __SET_VAR(data__->,START,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,_STEP,,__GET_VAR(data__->SS,));
    __SET_VAR(data__->,SPEED,,(__GET_VAR(data__->S1,) * 1.0E-3));
    __SET_VAR(data__->,Y_START,,__GET_VAR(data__->Y,));
  } else if (__GET_VAR(data__->SD,)) {
    __SET_VAR(data__->,STATE,,2);
    __SET_VAR(data__->,START,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,_STEP,, -(__GET_VAR(data__->SS,)));
    __SET_VAR(data__->,SPEED,,( -(__GET_VAR(data__->S1,)) * 1.0E-3));
    __SET_VAR(data__->,Y_START,,__GET_VAR(data__->Y,));
  } else if (__GET_VAR(data__->FU,)) {
    __SET_VAR(data__->,STATE,,3);
    __SET_VAR(data__->,START,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,_STEP,,__GET_VAR(data__->FS,));
    __SET_VAR(data__->,SPEED,,(__GET_VAR(data__->S2,) * 1.0E-3));
    __SET_VAR(data__->,Y_START,,__GET_VAR(data__->Y,));
  } else if (__GET_VAR(data__->FD,)) {
    __SET_VAR(data__->,STATE,,4);
    __SET_VAR(data__->,START,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,_STEP,, -(__GET_VAR(data__->FS,)));
    __SET_VAR(data__->,SPEED,,( -(__GET_VAR(data__->S2,)) * 1.0E-3));
    __SET_VAR(data__->,Y_START,,__GET_VAR(data__->Y,));
  };
  __SET_VAR(data__->,Y,,LIMIT__REAL__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->LIMIT_L,),
    (REAL)__GET_VAR(data__->Y,),
    (REAL)__GET_VAR(data__->LIMIT_H,)));

  goto __end;

__end:
  return;
} // TUNE2_body__() 





void FT_PROFILE_init__(FT_PROFILE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->K,1.0,retain)
  __INIT_VAR(data__->O,0.0,retain)
  __INIT_VAR(data__->M,1.0,retain)
  __INIT_VAR(data__->_E,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VALUE_0,0,retain)
  __INIT_VAR(data__->VALUE_1,0,retain)
  __INIT_VAR(data__->VALUE_2,0,retain)
  __INIT_VAR(data__->VALUE_3,0,retain)
  __INIT_VAR(data__->VALUE_10,0,retain)
  __INIT_VAR(data__->VALUE_11,0,retain)
  __INIT_VAR(data__->VALUE_12,0,retain)
  __INIT_VAR(data__->VALUE_13,0,retain)
  __INIT_VAR(data__->TIME_1,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TIME_2,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TIME_3,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TIME_10,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TIME_11,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TIME_12,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TIME_13,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->RUN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->TA,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TB,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T0,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TEMP,0,retain)
  __INIT_VAR(data__->VA,0,retain)
  __INIT_VAR(data__->VB,0,retain)
}

// Code part
void FT_PROFILE_body__(FT_PROFILE *data__) {
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
  if ((__GET_VAR(data__->_E,) && !(__GET_VAR(data__->EDGE,)))) {
    __SET_VAR(data__->,RUN,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,ET,,__time_to_timespec(1, 0, 0, 0, 0, 0));
    __SET_VAR(data__->,T0,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,TA,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,TB,,MULTIME__TIME__TIME__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)__GET_VAR(data__->TIME_1,),
      (REAL)__GET_VAR(data__->M,)));
    __SET_VAR(data__->,VA,,__GET_VAR(data__->VALUE_0,));
    __SET_VAR(data__->,VB,,__GET_VAR(data__->VALUE_1,));
    __SET_VAR(data__->,TEMP,,__GET_VAR(data__->VALUE_0,));
    __SET_VAR(data__->,STATE,,1);
  };
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->_E,));
  if (__GET_VAR(data__->RUN,)) {
    {
      INT __case_expression = __GET_VAR(data__->STATE,);
      if ((__case_expression == 1)) {
        if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->TA,)), __GET_VAR(data__->TB,))) {
          __SET_VAR(data__->,TA,,__time_add(__GET_VAR(data__->TA,), __GET_VAR(data__->TB,)));
          __SET_VAR(data__->,TB,,MULTIME__TIME__TIME__REAL(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (TIME)__time_sub(__GET_VAR(data__->TIME_2,), __GET_VAR(data__->TIME_1,)),
            (REAL)__GET_VAR(data__->M,)));
          __SET_VAR(data__->,VA,,__GET_VAR(data__->VALUE_1,));
          __SET_VAR(data__->,VB,,__GET_VAR(data__->VALUE_2,));
          __SET_VAR(data__->,TEMP,,__GET_VAR(data__->VALUE_1,));
          __SET_VAR(data__->,STATE,,2);
        } else {
          __SET_VAR(data__->,TEMP,,((((__GET_VAR(data__->VB,) - __GET_VAR(data__->VA,)) * TIME_TO_REAL(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (TIME)__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->TA,)))) / TIME_TO_REAL(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (TIME)__GET_VAR(data__->TB,))) + __GET_VAR(data__->VA,)));
        };
      }
      else if ((__case_expression == 2)) {
        if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->TA,)), __GET_VAR(data__->TB,))) {
          __SET_VAR(data__->,TA,,__time_add(__GET_VAR(data__->TA,), __GET_VAR(data__->TB,)));
          __SET_VAR(data__->,TB,,MULTIME__TIME__TIME__REAL(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (TIME)__time_sub(__GET_VAR(data__->TIME_3,), __GET_VAR(data__->TIME_2,)),
            (REAL)__GET_VAR(data__->M,)));
          __SET_VAR(data__->,VA,,__GET_VAR(data__->VALUE_2,));
          __SET_VAR(data__->,VB,,__GET_VAR(data__->VALUE_3,));
          __SET_VAR(data__->,TEMP,,__GET_VAR(data__->VALUE_2,));
          __SET_VAR(data__->,STATE,,3);
        } else {
          __SET_VAR(data__->,TEMP,,((((__GET_VAR(data__->VB,) - __GET_VAR(data__->VA,)) * TIME_TO_REAL(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (TIME)__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->TA,)))) / TIME_TO_REAL(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (TIME)__GET_VAR(data__->TB,))) + __GET_VAR(data__->VA,)));
        };
      }
      else if ((__case_expression == 3)) {
        if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->TA,)), __GET_VAR(data__->TB,))) {
          __SET_VAR(data__->,TA,,__time_add(__GET_VAR(data__->TA,), __GET_VAR(data__->TB,)));
          __SET_VAR(data__->,TB,,MULTIME__TIME__TIME__REAL(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (TIME)__time_sub(__GET_VAR(data__->TIME_10,), __GET_VAR(data__->TIME_3,)),
            (REAL)__GET_VAR(data__->M,)));
          __SET_VAR(data__->,VA,,__GET_VAR(data__->VALUE_3,));
          __SET_VAR(data__->,VB,,__GET_VAR(data__->VALUE_10,));
          __SET_VAR(data__->,TEMP,,__GET_VAR(data__->VALUE_3,));
          __SET_VAR(data__->,STATE,,4);
        } else {
          __SET_VAR(data__->,TEMP,,((((__GET_VAR(data__->VB,) - __GET_VAR(data__->VA,)) * TIME_TO_REAL(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (TIME)__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->TA,)))) / TIME_TO_REAL(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (TIME)__GET_VAR(data__->TB,))) + __GET_VAR(data__->VA,)));
        };
      }
      else if ((__case_expression == 4)) {
        if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->TA,)), __GET_VAR(data__->TB,))) {
          __SET_VAR(data__->,TA,,__time_add(__GET_VAR(data__->TA,), __GET_VAR(data__->TB,)));
          __SET_VAR(data__->,TB,,MULTIME__TIME__TIME__REAL(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (TIME)__time_sub(__GET_VAR(data__->TIME_11,), __GET_VAR(data__->TIME_10,)),
            (REAL)__GET_VAR(data__->M,)));
          __SET_VAR(data__->,VA,,__GET_VAR(data__->VALUE_10,));
          __SET_VAR(data__->,VB,,__GET_VAR(data__->VALUE_11,));
          __SET_VAR(data__->,TEMP,,__GET_VAR(data__->VALUE_10,));
          if (__GET_VAR(data__->_E,)) {
            __SET_VAR(data__->,STATE,,5);
          } else {
            __SET_VAR(data__->,STATE,,6);
          };
        } else {
          __SET_VAR(data__->,TEMP,,((((__GET_VAR(data__->VB,) - __GET_VAR(data__->VA,)) * TIME_TO_REAL(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (TIME)__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->TA,)))) / TIME_TO_REAL(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (TIME)__GET_VAR(data__->TB,))) + __GET_VAR(data__->VA,)));
        };
      }
      else if ((__case_expression == 5)) {
        if (__GET_VAR(data__->_E,)) {
          __SET_VAR(data__->,TA,,__GET_VAR(data__->TX,));
        } else {
          __SET_VAR(data__->,STATE,,6);
        };
      }
      else if ((__case_expression == 6)) {
        if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->TA,)), __GET_VAR(data__->TB,))) {
          __SET_VAR(data__->,TA,,__time_add(__GET_VAR(data__->TA,), __GET_VAR(data__->TB,)));
          __SET_VAR(data__->,TB,,MULTIME__TIME__TIME__REAL(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (TIME)__time_sub(__GET_VAR(data__->TIME_12,), __GET_VAR(data__->TIME_11,)),
            (REAL)__GET_VAR(data__->M,)));
          __SET_VAR(data__->,VA,,__GET_VAR(data__->VALUE_11,));
          __SET_VAR(data__->,VB,,__GET_VAR(data__->VALUE_12,));
          __SET_VAR(data__->,TEMP,,__GET_VAR(data__->VALUE_11,));
          __SET_VAR(data__->,STATE,,7);
        } else {
          __SET_VAR(data__->,TEMP,,((((__GET_VAR(data__->VB,) - __GET_VAR(data__->VA,)) * TIME_TO_REAL(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (TIME)__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->TA,)))) / TIME_TO_REAL(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (TIME)__GET_VAR(data__->TB,))) + __GET_VAR(data__->VA,)));
        };
      }
      else if ((__case_expression == 7)) {
        if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->TA,)), __GET_VAR(data__->TB,))) {
          __SET_VAR(data__->,TA,,__time_add(__GET_VAR(data__->TA,), __GET_VAR(data__->TB,)));
          __SET_VAR(data__->,TB,,MULTIME__TIME__TIME__REAL(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (TIME)__time_sub(__GET_VAR(data__->TIME_13,), __GET_VAR(data__->TIME_12,)),
            (REAL)__GET_VAR(data__->M,)));
          __SET_VAR(data__->,VA,,__GET_VAR(data__->VALUE_12,));
          __SET_VAR(data__->,VB,,__GET_VAR(data__->VALUE_13,));
          __SET_VAR(data__->,TEMP,,__GET_VAR(data__->VALUE_12,));
          __SET_VAR(data__->,STATE,,8);
        } else {
          __SET_VAR(data__->,TEMP,,((((__GET_VAR(data__->VB,) - __GET_VAR(data__->VA,)) * TIME_TO_REAL(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (TIME)__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->TA,)))) / TIME_TO_REAL(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (TIME)__GET_VAR(data__->TB,))) + __GET_VAR(data__->VA,)));
        };
      }
      else if ((__case_expression == 8)) {
        if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->TA,)), __GET_VAR(data__->TB,))) {
          __SET_VAR(data__->,TEMP,,__GET_VAR(data__->VALUE_13,));
          __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
        } else {
          __SET_VAR(data__->,TEMP,,((((__GET_VAR(data__->VB,) - __GET_VAR(data__->VA,)) * TIME_TO_REAL(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (TIME)__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->TA,)))) / TIME_TO_REAL(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (TIME)__GET_VAR(data__->TB,))) + __GET_VAR(data__->VA,)));
        };
      }
    };
    __SET_VAR(data__->,Y,,((__GET_VAR(data__->TEMP,) * __GET_VAR(data__->K,)) + __GET_VAR(data__->O,)));
    __SET_VAR(data__->,ET,,__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->T0,)));
  };

  goto __end;

__end:
  return;
} // FT_PROFILE_body__() 





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





void FLOW_CONTROL_init__(FLOW_CONTROL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REQ,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ENQ,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->T_AUTO,__time_to_timespec(1, 0, 0, 0, 1, 0),retain)
  __INIT_VAR(data__->T_DELAY,__time_to_timespec(1, 0, 0, 0, 23, 0),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATUS,0,retain)
  TP_1D_init__(&data__->TIMER,retain);
}

// Code part
void FLOW_CONTROL_body__(FLOW_CONTROL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(100));
  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->TIMER.,RST,,__BOOL_LITERAL(TRUE));
    TP_1D_body__(&data__->TIMER);
    __SET_VAR(data__->,TIMER.RST,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(103));
  } else if (__GET_VAR(data__->ENQ,)) {
    if (__GET_VAR(data__->IN,)) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(101));
    };
    if (__GET_VAR(data__->REQ,)) {
      __SET_VAR(data__->,TIMER.PT1,,__GET_VAR(data__->T_AUTO,));
      __SET_VAR(data__->,TIMER.PTD,,__GET_VAR(data__->T_DELAY,));
      __SET_VAR(data__->,TIMER.IN,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(102));
    };
  };
  TP_1D_body__(&data__->TIMER);
  __SET_VAR(data__->,TIMER.IN,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,Q,,((__GET_VAR(data__->IN,) && __GET_VAR(data__->ENQ,)) || __GET_VAR(data__->TIMER.Q,)));

  goto __end;

__end:
  return;
} // FLOW_CONTROL_body__() 





void MANUAL_2_init__(MANUAL_2 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ENA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_ON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OFF,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MAN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATUS,0,retain)
  __INIT_VAR(data__->STATUS0,0,retain)
}

// Code part
void MANUAL_2_body__(MANUAL_2 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (__GET_VAR(data__->ENA,)) {
    if ((!(__GET_VAR(data__->_ON,)) && !(__GET_VAR(data__->OFF,)))) {
      __SET_VAR(data__->,Q,,__GET_VAR(data__->IN,));
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(100));
    } else if ((__GET_VAR(data__->_ON,) && !(__GET_VAR(data__->OFF,)))) {
      __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(101));
    } else if ((!(__GET_VAR(data__->_ON,)) && __GET_VAR(data__->OFF,))) {
      __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(102));
    } else {
      __SET_VAR(data__->,Q,,__GET_VAR(data__->MAN,));
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(103));
    };
  } else {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(104));
  };

  goto __end;

__end:
  return;
} // MANUAL_2_body__() 





// FUNCTION
BOOL MANUAL(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL IN, 
  BOOL _ON, 
  BOOL OFF)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BOOL MANUAL = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return MANUAL;
  }
  MANUAL = (!(OFF) && (IN || _ON));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return MANUAL;
}


void MANUAL_1_init__(MANUAL_1 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MAN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M_I,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATUS,0,retain)
  __INIT_VAR(data__->S_EDGE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_R_EDGE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void MANUAL_1_body__(MANUAL_1 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (!(__GET_VAR(data__->MAN,))) {
    __SET_VAR(data__->,Q,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(100));
    __SET_VAR(data__->,EDGE,,__BOOL_LITERAL(FALSE));
  } else if ((!(__GET_VAR(data__->S_EDGE,)) && __GET_VAR(data__->SET,))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,EDGE,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(101));
  } else if ((!(__GET_VAR(data__->_R_EDGE,)) && __GET_VAR(data__->RST,))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,EDGE,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(102));
  } else if (!(__GET_VAR(data__->EDGE,))) {
    __SET_VAR(data__->,Q,,__GET_VAR(data__->M_I,));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(103));
  };
  __SET_VAR(data__->,S_EDGE,,__GET_VAR(data__->SET,));
  __SET_VAR(data__->,_R_EDGE,,__GET_VAR(data__->RST,));

  goto __end;

__end:
  return;
} // MANUAL_1_body__() 





void TUNE_init__(TUNE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->SET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SU,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SS,0.1,retain)
  __INIT_VAR(data__->LIMIT_L,0,retain)
  __INIT_VAR(data__->LIMIT_H,100.0,retain)
  __INIT_VAR(data__->RST_VAL,0,retain)
  __INIT_VAR(data__->SET_VAL,100.0,retain)
  __INIT_VAR(data__->T1,__time_to_timespec(1, 500, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T2,__time_to_timespec(1, 0, 2, 0, 0, 0),retain)
  __INIT_VAR(data__->S1,2.0,retain)
  __INIT_VAR(data__->S2,10.0,retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->TX,0,retain)
  __INIT_VAR(data__->START,0,retain)
  __INIT_VAR(data__->START2,0,retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_STEP,0,retain)
  __INIT_VAR(data__->SPEED,0,retain)
  __INIT_VAR(data__->Y_START,0,retain)
  __INIT_VAR(data__->Y_START2,0,retain)
}

// Code part
void TUNE_body__(TUNE *data__) {
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
  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,Y,,__GET_VAR(data__->RST_VAL,));
    __SET_VAR(data__->,STATE,,0);
  } else if (__GET_VAR(data__->SET,)) {
    __SET_VAR(data__->,Y,,__GET_VAR(data__->SET_VAL,));
    __SET_VAR(data__->,STATE,,0);
  } else if ((__GET_VAR(data__->STATE,) > 0)) {
    if ((__GET_VAR(data__->STATE,) == 1)) {
      __SET_VAR(data__->,IN,,__GET_VAR(data__->SU,));
    } else {
      __SET_VAR(data__->,IN,,__GET_VAR(data__->SD,));
    };
    if ((!(__GET_VAR(data__->IN,)) && ((__GET_VAR(data__->TX,) - __GET_VAR(data__->START,)) <= TIME_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)__GET_VAR(data__->T1,))))) {
      __SET_VAR(data__->,Y,,(__GET_VAR(data__->Y_START,) + __GET_VAR(data__->_STEP,)));
      __SET_VAR(data__->,STATE,,0);
    } else if ((__GET_VAR(data__->IN,) && ((__GET_VAR(data__->TX,) - __GET_VAR(data__->START,)) >= TIME_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)__GET_VAR(data__->T2,))))) {
      __SET_VAR(data__->,Y,,(__GET_VAR(data__->Y_START2,) + ((UDINT_TO_REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)(__GET_VAR(data__->TX,) - __GET_VAR(data__->START2,))) * __GET_VAR(data__->S2,)) / __GET_VAR(data__->SPEED,))));
    } else if ((__GET_VAR(data__->IN,) && ((__GET_VAR(data__->TX,) - __GET_VAR(data__->START,)) >= TIME_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)__GET_VAR(data__->T1,))))) {
      __SET_VAR(data__->,Y,,(__GET_VAR(data__->Y_START,) + ((UDINT_TO_REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)((__GET_VAR(data__->TX,) - __GET_VAR(data__->START,)) - TIME_TO_UDINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (TIME)__GET_VAR(data__->T1,)))) * __GET_VAR(data__->S1,)) / __GET_VAR(data__->SPEED,))));
      __SET_VAR(data__->,START2,,__GET_VAR(data__->TX,));
      __SET_VAR(data__->,Y_START2,,__GET_VAR(data__->Y,));
    } else if (!(__GET_VAR(data__->IN,))) {
      __SET_VAR(data__->,STATE,,0);
    };
  } else if (__GET_VAR(data__->SU,)) {
    __SET_VAR(data__->,STATE,,1);
    __SET_VAR(data__->,START,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,_STEP,,__GET_VAR(data__->SS,));
    __SET_VAR(data__->,SPEED,,1000.0);
    __SET_VAR(data__->,Y_START,,__GET_VAR(data__->Y,));
  } else if (__GET_VAR(data__->SD,)) {
    __SET_VAR(data__->,STATE,,2);
    __SET_VAR(data__->,START,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,_STEP,, -(__GET_VAR(data__->SS,)));
    __SET_VAR(data__->,SPEED,,-1000.0);
    __SET_VAR(data__->,Y_START,,__GET_VAR(data__->Y,));
  };
  __SET_VAR(data__->,Y,,LIMIT__REAL__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->LIMIT_L,),
    (REAL)__GET_VAR(data__->Y,),
    (REAL)__GET_VAR(data__->LIMIT_H,)));

  goto __end;

__end:
  return;
} // TUNE_body__() 





// FUNCTION
INT INC(
  BOOL EN, 
  BOOL *__ENO, 
  INT X, 
  INT _D, 
  INT M)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT INC = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return INC;
  }
  INC = (((M + 1) == 0)?0:((((X + _D) + M) + 1) % (M + 1)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return INC;
}


void MANUAL_4_init__(MANUAL_4 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->I0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->I1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->I2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->I3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MAN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATUS,0,retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->POS,0,retain)
  __INIT_VAR(data__->TOG,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void MANUAL_4_body__(MANUAL_4 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (__GET_VAR(data__->MAN,)) {
    if (!(__GET_VAR(data__->TOG,))) {
      __SET_VAR(data__->,Q0,,__GET_VAR(data__->M0,));
      __SET_VAR(data__->,Q1,,__GET_VAR(data__->M1,));
      __SET_VAR(data__->,Q2,,__GET_VAR(data__->M2,));
      __SET_VAR(data__->,Q3,,__GET_VAR(data__->M3,));
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(101));
    };
    if ((__GET_VAR(data__->STP,) && !(__GET_VAR(data__->EDGE,)))) {
      __SET_VAR(data__->,TOG,,__BOOL_LITERAL(TRUE));
      {
        INT __case_expression = __GET_VAR(data__->POS,);
        if ((__case_expression == 0)) {
          __SET_VAR(data__->,Q0,,__BOOL_LITERAL(TRUE));
          __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
          __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
          __SET_VAR(data__->,Q3,,__BOOL_LITERAL(FALSE));
          __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(110));
        }
        else if ((__case_expression == 1)) {
          __SET_VAR(data__->,Q0,,__BOOL_LITERAL(FALSE));
          __SET_VAR(data__->,Q1,,__BOOL_LITERAL(TRUE));
          __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
          __SET_VAR(data__->,Q3,,__BOOL_LITERAL(FALSE));
          __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(111));
        }
        else if ((__case_expression == 2)) {
          __SET_VAR(data__->,Q0,,__BOOL_LITERAL(FALSE));
          __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
          __SET_VAR(data__->,Q2,,__BOOL_LITERAL(TRUE));
          __SET_VAR(data__->,Q3,,__BOOL_LITERAL(FALSE));
          __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(112));
        }
        else if ((__case_expression == 3)) {
          __SET_VAR(data__->,Q0,,__BOOL_LITERAL(FALSE));
          __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
          __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
          __SET_VAR(data__->,Q3,,__BOOL_LITERAL(TRUE));
          __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(113));
        }
      };
      __SET_VAR(data__->,POS,,INC(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)__GET_VAR(data__->POS,),
        (INT)1,
        (INT)3));
    };
  } else {
    __SET_VAR(data__->,Q0,,__GET_VAR(data__->I0,));
    __SET_VAR(data__->,Q1,,__GET_VAR(data__->I1,));
    __SET_VAR(data__->,Q2,,__GET_VAR(data__->I2,));
    __SET_VAR(data__->,Q3,,__GET_VAR(data__->I3,));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(100));
    __SET_VAR(data__->,TOG,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,POS,,0);
  };
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->STP,));

  goto __end;

__end:
  return;
} // MANUAL_4_body__() 





void DRIVER_4C_init__(DRIVER_4C *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TIMEOUT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  {
    static const __ARRAY_OF_BYTE_7 temp = {{0,0,0,0,0,0,0}};
    __SET_VAR(data__->,SX,,temp);
  }
  __INIT_VAR(data__->SN,0,retain)
  __INIT_VAR(data__->Q0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q3,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->OFF,retain);
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void DRIVER_4C_body__(DRIVER_4C *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->RST,) || __GET_VAR(data__->OFF.Q,))) {
    __SET_VAR(data__->,SN,,0);
  } else if ((__GET_VAR(data__->IN,) && !(__GET_VAR(data__->EDGE,)))) {
    __SET_VAR(data__->,SN,,(__GET_VAR(data__->SN,) + 1));
    if (((__GET_VAR(data__->SN,) > 7) || (__GET_VAR(data__->SX,.table[(__GET_VAR(data__->SN,)) - (1)]) == __BYTE_LITERAL(0)))) {
      __SET_VAR(data__->,SN,,0);
    };
  };
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->IN,));
  if ((__GET_VAR(data__->SN,) > 0)) {
    __SET_VAR(data__->,Q0,,((__GET_VAR(data__->SX,.table[(__GET_VAR(data__->SN,)) - (1)]) & __BYTE_LITERAL(1)) > __BYTE_LITERAL(0)));
    __SET_VAR(data__->,Q1,,((__GET_VAR(data__->SX,.table[(__GET_VAR(data__->SN,)) - (1)]) & __BYTE_LITERAL(2)) > __BYTE_LITERAL(0)));
    __SET_VAR(data__->,Q2,,((__GET_VAR(data__->SX,.table[(__GET_VAR(data__->SN,)) - (1)]) & __BYTE_LITERAL(4)) > __BYTE_LITERAL(0)));
    __SET_VAR(data__->,Q3,,((__GET_VAR(data__->SX,.table[(__GET_VAR(data__->SN,)) - (1)]) & __BYTE_LITERAL(8)) > __BYTE_LITERAL(0)));
  } else {
    __SET_VAR(data__->,Q0,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q3,,__BOOL_LITERAL(FALSE));
  };
  if (GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TIMEOUT,), __time_to_timespec(1, 0, 0, 0, 0, 0))) {
    __SET_VAR(data__->OFF.,IN,,(__GET_VAR(data__->SN,) > 0));
    __SET_VAR(data__->OFF.,PT,,__GET_VAR(data__->TIMEOUT,));
    TON_body__(&data__->OFF);
  };

  goto __end;

__end:
  return;
} // DRIVER_4C_body__() 





void DRIVER_1_init__(DRIVER_1 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->SET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TOGGLE_MODE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TIMEOUT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->OFF,retain);
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void DRIVER_1_body__(DRIVER_1 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (__GET_VAR(data__->OFF.Q,)) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  } else if (__GET_VAR(data__->SET,)) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
  } else if ((__GET_VAR(data__->IN,) && !(__GET_VAR(data__->EDGE,)))) {
    if (__GET_VAR(data__->TOGGLE_MODE,)) {
      __SET_VAR(data__->,Q,,!(__GET_VAR(data__->Q,)));
    } else {
      __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
    };
  };
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->IN,));
  if (GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TIMEOUT,), __time_to_timespec(1, 0, 0, 0, 0, 0))) {
    __SET_VAR(data__->OFF.,IN,,__GET_VAR(data__->Q,));
    __SET_VAR(data__->OFF.,PT,,__GET_VAR(data__->TIMEOUT,));
    TON_body__(&data__->OFF);
  };

  goto __end;

__end:
  return;
} // DRIVER_1_body__() 





void DRIVER_4_init__(DRIVER_4 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->SET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TOGGLE_MODE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TIMEOUT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Q0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q3,__BOOL_LITERAL(FALSE),retain)
  DRIVER_1_init__(&data__->D0,retain);
  DRIVER_1_init__(&data__->D1,retain);
  DRIVER_1_init__(&data__->D2,retain);
  DRIVER_1_init__(&data__->D3,retain);
}

// Code part
void DRIVER_4_body__(DRIVER_4 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->D0.,SET,,__GET_VAR(data__->SET,));
  __SET_VAR(data__->D0.,IN,,__GET_VAR(data__->IN0,));
  __SET_VAR(data__->D0.,RST,,__GET_VAR(data__->RST,));
  __SET_VAR(data__->D0.,TOGGLE_MODE,,__GET_VAR(data__->TOGGLE_MODE,));
  __SET_VAR(data__->D0.,TIMEOUT,,__GET_VAR(data__->TIMEOUT,));
  DRIVER_1_body__(&data__->D0);
  __SET_VAR(data__->D1.,SET,,__GET_VAR(data__->SET,));
  __SET_VAR(data__->D1.,IN,,__GET_VAR(data__->IN1,));
  __SET_VAR(data__->D1.,RST,,__GET_VAR(data__->RST,));
  __SET_VAR(data__->D1.,TOGGLE_MODE,,__GET_VAR(data__->TOGGLE_MODE,));
  __SET_VAR(data__->D1.,TIMEOUT,,__GET_VAR(data__->TIMEOUT,));
  DRIVER_1_body__(&data__->D1);
  __SET_VAR(data__->D2.,SET,,__GET_VAR(data__->SET,));
  __SET_VAR(data__->D2.,IN,,__GET_VAR(data__->IN2,));
  __SET_VAR(data__->D2.,RST,,__GET_VAR(data__->RST,));
  __SET_VAR(data__->D2.,TOGGLE_MODE,,__GET_VAR(data__->TOGGLE_MODE,));
  __SET_VAR(data__->D2.,TIMEOUT,,__GET_VAR(data__->TIMEOUT,));
  DRIVER_1_body__(&data__->D2);
  __SET_VAR(data__->D3.,SET,,__GET_VAR(data__->SET,));
  __SET_VAR(data__->D3.,IN,,__GET_VAR(data__->IN3,));
  __SET_VAR(data__->D3.,RST,,__GET_VAR(data__->RST,));
  __SET_VAR(data__->D3.,TOGGLE_MODE,,__GET_VAR(data__->TOGGLE_MODE,));
  __SET_VAR(data__->D3.,TIMEOUT,,__GET_VAR(data__->TIMEOUT,));
  DRIVER_1_body__(&data__->D3);
  __SET_VAR(data__->,Q0,,__GET_VAR(data__->D0.Q,));
  __SET_VAR(data__->,Q1,,__GET_VAR(data__->D1.Q,));
  __SET_VAR(data__->,Q2,,__GET_VAR(data__->D2.Q,));
  __SET_VAR(data__->,Q3,,__GET_VAR(data__->D3.Q,));

  goto __end;

__end:
  return;
} // DRIVER_4_body__() 





