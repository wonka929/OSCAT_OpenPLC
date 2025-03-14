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


void STACK_16_init__(STACK_16 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->DIN,0,retain)
  __INIT_VAR(data__->_E,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->WD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DOUT,0,retain)
  __INIT_VAR(data__->EMPTY,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->FULL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PT,0,retain)
  {
    static const __ARRAY_OF_DWORD_16 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,STACK,,temp);
  }
}

// Code part
void STACK_16_body__(STACK_16 *data__) {
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
    __SET_VAR(data__->,PT,,0);
    __SET_VAR(data__->,EMPTY,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,FULL,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,DOUT,,__DWORD_LITERAL(0));
  } else if (__GET_VAR(data__->_E,)) {
    if ((!(__GET_VAR(data__->EMPTY,)) && __GET_VAR(data__->RD,))) {
      __SET_VAR(data__->,PT,,(__GET_VAR(data__->PT,) - 1));
      __SET_VAR(data__->,DOUT,,__GET_VAR(data__->STACK,.table[(__GET_VAR(data__->PT,)) - (0)]));
      __SET_VAR(data__->,EMPTY,,(__GET_VAR(data__->PT,) == 0));
      __SET_VAR(data__->,FULL,,__BOOL_LITERAL(FALSE));
    };
    if ((!(__GET_VAR(data__->FULL,)) && __GET_VAR(data__->WD,))) {
      __SET_VAR(data__->,STACK,.table[(__GET_VAR(data__->PT,)) - (0)],__GET_VAR(data__->DIN,));
      __SET_VAR(data__->,PT,,(__GET_VAR(data__->PT,) + 1));
      __SET_VAR(data__->,FULL,,(__GET_VAR(data__->PT,) > 15));
      __SET_VAR(data__->,EMPTY,,__BOOL_LITERAL(FALSE));
    };
  };

  goto __end;

__end:
  return;
} // STACK_16_body__() 





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





void FIFO_32_init__(FIFO_32 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->DIN,0,retain)
  __INIT_VAR(data__->_E,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->WD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DOUT,0,retain)
  __INIT_VAR(data__->EMPTY,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->FULL,__BOOL_LITERAL(FALSE),retain)
  {
    static const __ARRAY_OF_DWORD_32 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,FIFO,,temp);
  }
  __INIT_VAR(data__->PR,0,retain)
  __INIT_VAR(data__->PW,0,retain)
}

// Code part
void FIFO_32_body__(FIFO_32 *data__) {
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
    __SET_VAR(data__->,PW,,__GET_VAR(data__->PR,));
    __SET_VAR(data__->,FULL,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,EMPTY,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,DOUT,,__DWORD_LITERAL(0));
  } else if (__GET_VAR(data__->_E,)) {
    if ((!(__GET_VAR(data__->EMPTY,)) && __GET_VAR(data__->RD,))) {
      __SET_VAR(data__->,DOUT,,__GET_VAR(data__->FIFO,.table[(__GET_VAR(data__->PR,)) - (0)]));
      __SET_VAR(data__->,PR,,INC1(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)__GET_VAR(data__->PR,),
        (INT)32));
      __SET_VAR(data__->,EMPTY,,(__GET_VAR(data__->PR,) == __GET_VAR(data__->PW,)));
      __SET_VAR(data__->,FULL,,__BOOL_LITERAL(FALSE));
    };
    if ((!(__GET_VAR(data__->FULL,)) && __GET_VAR(data__->WD,))) {
      __SET_VAR(data__->,FIFO,.table[(__GET_VAR(data__->PW,)) - (0)],__GET_VAR(data__->DIN,));
      __SET_VAR(data__->,PW,,INC1(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)__GET_VAR(data__->PW,),
        (INT)32));
      __SET_VAR(data__->,FULL,,(__GET_VAR(data__->PW,) == __GET_VAR(data__->PR,)));
      __SET_VAR(data__->,EMPTY,,__BOOL_LITERAL(FALSE));
    };
  };

  goto __end;

__end:
  return;
} // FIFO_32_body__() 





void FIFO_16_init__(FIFO_16 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->DIN,0,retain)
  __INIT_VAR(data__->_E,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->WD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DOUT,0,retain)
  __INIT_VAR(data__->EMPTY,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->FULL,__BOOL_LITERAL(FALSE),retain)
  {
    static const __ARRAY_OF_DWORD_16 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,FIFO,,temp);
  }
  __INIT_VAR(data__->PR,0,retain)
  __INIT_VAR(data__->PW,0,retain)
}

// Code part
void FIFO_16_body__(FIFO_16 *data__) {
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
    __SET_VAR(data__->,PW,,__GET_VAR(data__->PR,));
    __SET_VAR(data__->,FULL,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,EMPTY,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,DOUT,,__DWORD_LITERAL(0));
  } else if (__GET_VAR(data__->_E,)) {
    if ((!(__GET_VAR(data__->EMPTY,)) && __GET_VAR(data__->RD,))) {
      __SET_VAR(data__->,DOUT,,__GET_VAR(data__->FIFO,.table[(__GET_VAR(data__->PR,)) - (0)]));
      __SET_VAR(data__->,PR,,INC1(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)__GET_VAR(data__->PR,),
        (INT)16));
      __SET_VAR(data__->,EMPTY,,(__GET_VAR(data__->PR,) == __GET_VAR(data__->PW,)));
      __SET_VAR(data__->,FULL,,__BOOL_LITERAL(FALSE));
    };
    if ((!(__GET_VAR(data__->FULL,)) && __GET_VAR(data__->WD,))) {
      __SET_VAR(data__->,FIFO,.table[(__GET_VAR(data__->PW,)) - (0)],__GET_VAR(data__->DIN,));
      __SET_VAR(data__->,PW,,INC1(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)__GET_VAR(data__->PW,),
        (INT)16));
      __SET_VAR(data__->,FULL,,(__GET_VAR(data__->PW,) == __GET_VAR(data__->PR,)));
      __SET_VAR(data__->,EMPTY,,__BOOL_LITERAL(FALSE));
    };
  };

  goto __end;

__end:
  return;
} // FIFO_16_body__() 





void STACK_32_init__(STACK_32 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->DIN,0,retain)
  __INIT_VAR(data__->_E,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->WD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DOUT,0,retain)
  __INIT_VAR(data__->EMPTY,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->FULL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PT,0,retain)
  {
    static const __ARRAY_OF_DWORD_32 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,STACK,,temp);
  }
}

// Code part
void STACK_32_body__(STACK_32 *data__) {
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
    __SET_VAR(data__->,PT,,0);
    __SET_VAR(data__->,EMPTY,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,FULL,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,DOUT,,__DWORD_LITERAL(0));
  } else if (__GET_VAR(data__->_E,)) {
    if ((!(__GET_VAR(data__->EMPTY,)) && __GET_VAR(data__->RD,))) {
      __SET_VAR(data__->,PT,,(__GET_VAR(data__->PT,) - 1));
      __SET_VAR(data__->,DOUT,,__GET_VAR(data__->STACK,.table[(__GET_VAR(data__->PT,)) - (0)]));
      __SET_VAR(data__->,EMPTY,,(__GET_VAR(data__->PT,) == 0));
      __SET_VAR(data__->,FULL,,__BOOL_LITERAL(FALSE));
    };
    if ((!(__GET_VAR(data__->FULL,)) && __GET_VAR(data__->WD,))) {
      __SET_VAR(data__->,STACK,.table[(__GET_VAR(data__->PT,)) - (0)],__GET_VAR(data__->DIN,));
      __SET_VAR(data__->,PT,,(__GET_VAR(data__->PT,) + 1));
      __SET_VAR(data__->,FULL,,(__GET_VAR(data__->PT,) > 31));
      __SET_VAR(data__->,EMPTY,,__BOOL_LITERAL(FALSE));
    };
  };

  goto __end;

__end:
  return;
} // STACK_32_body__() 





