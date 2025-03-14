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





void RDM2_init__(RDM2 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->LAST,0,retain)
  __INIT_VAR(data__->LOW,0,retain)
  __INIT_VAR(data__->HIGH,0,retain)
  __INIT_VAR(data__->_RDM2,0,retain)
  RDM_init__(&data__->_RDM,retain);
}

// Code part
void RDM2_body__(RDM2 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->_RDM.,LAST,,FRACT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(INT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)__GET_VAR(data__->LAST,)) * 3.14159265358979323846264338327950288)));
  RDM_body__(&data__->_RDM);
  __SET_VAR(data__->,_RDM2,,(TRUNC__INT__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(__GET_VAR(data__->_RDM._RDM,) * INT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)((__GET_VAR(data__->HIGH,) - __GET_VAR(data__->LOW,)) + 1)))) + __GET_VAR(data__->LOW,)));

  goto __end;

__end:
  return;
} // RDM2_body__() 





void _ARRAY_SHUFFLE_init__(_ARRAY_SHUFFLE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const __ARRAY_OF_REAL_100 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,PT,,temp);
  }
  __INIT_VAR(data__->SIZE,0,retain)
  __INIT_VAR(data__->_ARRAY_SHUFFLE_Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TEMP,0,retain)
  __INIT_VAR(data__->POS,0,retain)
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->STOP,0,retain)
  RDM2_init__(&data__->_RDM2,retain);
}

// Code part
void _ARRAY_SHUFFLE_body__(_ARRAY_SHUFFLE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,STOP,,LIMIT__INT__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)1,
    (INT)UINT_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)__GET_VAR(data__->SIZE,)),
    (INT)1000));
  for(__GET_VAR(data__->I,) = 1; __GET_VAR(data__->I,) <= __GET_VAR(data__->STOP,); __GET_VAR(data__->I,)++) {
    __SET_VAR(data__->_RDM2.,LAST,,(__GET_VAR(data__->I,) + __GET_VAR(data__->POS,)));
    __SET_VAR(data__->_RDM2.,LOW,,1);
    __SET_VAR(data__->_RDM2.,HIGH,,__GET_VAR(data__->STOP,));
    RDM2_body__(&data__->_RDM2);
    __SET_VAR(data__->,POS,,__GET_VAR(data__->_RDM2._RDM2,));
    __SET_VAR(data__->,TEMP,,__GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)]));
    __SET_VAR(data__->,PT,.table[(__GET_VAR(data__->I,)) - (1)],__GET_VAR(data__->PT,.table[(__GET_VAR(data__->POS,)) - (1)]));
    __SET_VAR(data__->,PT,.table[(__GET_VAR(data__->POS,)) - (1)],__GET_VAR(data__->TEMP,));
  };
  __SET_VAR(data__->,_ARRAY_SHUFFLE_Q,,__BOOL_LITERAL(TRUE));

  goto __end;

__end:
  return;
} // _ARRAY_SHUFFLE_body__() 





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





void _ARRAY_ABS_init__(_ARRAY_ABS *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const __ARRAY_OF_REAL_100 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,PT,,temp);
  }
  __INIT_VAR(data__->SIZE,0,retain)
  __INIT_VAR(data__->_ARRAY_ABS_Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->STOP,0,retain)
}

// Code part
void _ARRAY_ABS_body__(_ARRAY_ABS *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,STOP,,LIMIT__INT__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)1,
    (INT)UINT_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)__GET_VAR(data__->SIZE,)),
    (INT)1000));
  for(__GET_VAR(data__->I,) = 1; __GET_VAR(data__->I,) <= __GET_VAR(data__->STOP,); __GET_VAR(data__->I,)++) {
    __SET_VAR(data__->,PT,.table[(__GET_VAR(data__->I,)) - (1)],ABS__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)__GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)])));
  };
  __SET_VAR(data__->,_ARRAY_ABS_Q,,__BOOL_LITERAL(TRUE));

  goto __end;

__end:
  return;
} // _ARRAY_ABS_body__() 





void ARRAY_AVG_init__(ARRAY_AVG *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const __ARRAY_OF_REAL_100 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,PT,,temp);
  }
  __INIT_VAR(data__->SIZE,0,retain)
  __INIT_VAR(data__->_ARRAY_AVG,0,retain)
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->STOP,0,retain)
}

// Code part
void ARRAY_AVG_body__(ARRAY_AVG *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,STOP,,LIMIT__INT__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)1,
    (INT)UINT_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)__GET_VAR(data__->SIZE,)),
    (INT)1000));
  __SET_VAR(data__->,_ARRAY_AVG,,0.0);
  for(__GET_VAR(data__->I,) = 1; __GET_VAR(data__->I,) <= __GET_VAR(data__->STOP,); __GET_VAR(data__->I,)++) {
    __SET_VAR(data__->,_ARRAY_AVG,,(__GET_VAR(data__->_ARRAY_AVG,) + __GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)])));
  };
  __SET_VAR(data__->,_ARRAY_AVG,,(__GET_VAR(data__->_ARRAY_AVG,) / INT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->STOP,))));

  goto __end;

__end:
  return;
} // ARRAY_AVG_body__() 





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


void ARRAY_TREND_init__(ARRAY_TREND *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const __ARRAY_OF_REAL_100 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,PT,,temp);
  }
  __INIT_VAR(data__->SIZE,0,retain)
  __INIT_VAR(data__->_ARRAY_TREND,0,retain)
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->STOP,0,retain)
  __INIT_VAR(data__->STOP2,0,retain)
  __INIT_VAR(data__->_D,0,retain)
  __INIT_VAR(data__->X,0,retain)
}

// Code part
void ARRAY_TREND_body__(ARRAY_TREND *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,X,,0.0);
  __SET_VAR(data__->,STOP,,LIMIT__INT__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)1,
    (INT)UINT_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)__GET_VAR(data__->SIZE,)),
    (INT)1000));
  __SET_VAR(data__->,STOP2,,WORD_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (WORD)SHR__WORD__WORD__SINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (WORD)INT_TO_WORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)__GET_VAR(data__->STOP,)),
      (SINT)1)));
  if (EVEN(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DINT)INT_TO_DINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)__GET_VAR(data__->STOP,)))) {
    __SET_VAR(data__->,_D,,0);
  } else {
    __SET_VAR(data__->,_D,,1);
  };
  for(__GET_VAR(data__->I,) = 1; __GET_VAR(data__->I,) <= (__GET_VAR(data__->STOP2,) + __GET_VAR(data__->_D,)); __GET_VAR(data__->I,)++) {
    __SET_VAR(data__->,X,,(__GET_VAR(data__->X,) - __GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)])));
  };
  for(__GET_VAR(data__->I,) = (__GET_VAR(data__->STOP2,) + 1); __GET_VAR(data__->I,) <= __GET_VAR(data__->STOP,); __GET_VAR(data__->I,)++) {
    __SET_VAR(data__->,X,,(__GET_VAR(data__->X,) + __GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)])));
  };
  __SET_VAR(data__->,_ARRAY_TREND,,(__GET_VAR(data__->X,) / INT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)(__GET_VAR(data__->STOP2,) + __GET_VAR(data__->_D,)))));

  goto __end;

__end:
  return;
} // ARRAY_TREND_body__() 





void IS_SORTED_init__(IS_SORTED *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const __ARRAY_OF_REAL_100 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,PT,,temp);
  }
  __INIT_VAR(data__->SIZE,0,retain)
  __INIT_VAR(data__->_IS_SORTED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->I2,0,retain)
  __INIT_VAR(data__->STOP,0,retain)
}

// Code part
void IS_SORTED_body__(IS_SORTED *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,STOP,,LIMIT__INT__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)1,
    (INT)UINT_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)__GET_VAR(data__->SIZE,)),
    (INT)1000));
  __SET_VAR(data__->,STOP,,(__GET_VAR(data__->STOP,) - 1));
  for(__GET_VAR(data__->I,) = 1; __GET_VAR(data__->I,) <= __GET_VAR(data__->STOP,); __GET_VAR(data__->I,)++) {
    __SET_VAR(data__->,I2,,(__GET_VAR(data__->I,) + 1));
    if ((__GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)]) > __GET_VAR(data__->PT,.table[(__GET_VAR(data__->I2,)) - (1)]))) {
      __SET_VAR(data__->,_IS_SORTED,,__BOOL_LITERAL(FALSE));
      goto __end;
    };
  };
  __SET_VAR(data__->,_IS_SORTED,,__BOOL_LITERAL(TRUE));

  goto __end;

__end:
  return;
} // IS_SORTED_body__() 





void ARRAY_SPR_init__(ARRAY_SPR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const __ARRAY_OF_REAL_100 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,PT,,temp);
  }
  __INIT_VAR(data__->SIZE,0,retain)
  __INIT_VAR(data__->_ARRAY_SPR,0,retain)
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->STOP,0,retain)
  __INIT_VAR(data__->ARR_MAX,0,retain)
  __INIT_VAR(data__->ARR_MIN,0,retain)
}

// Code part
void ARRAY_SPR_body__(ARRAY_SPR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,STOP,,LIMIT__INT__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)1,
    (INT)UINT_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)__GET_VAR(data__->SIZE,)),
    (INT)1000));
  __SET_VAR(data__->,ARR_MIN,,__GET_VAR(data__->PT,.table[(1) - (1)]));
  __SET_VAR(data__->,ARR_MAX,,__GET_VAR(data__->PT,.table[(1) - (1)]));
  for(__GET_VAR(data__->I,) = 2; __GET_VAR(data__->I,) <= __GET_VAR(data__->STOP,); __GET_VAR(data__->I,)++) {
    if ((__GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)]) > __GET_VAR(data__->ARR_MAX,))) {
      __SET_VAR(data__->,ARR_MAX,,__GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)]));
    } else if ((__GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)]) < __GET_VAR(data__->ARR_MIN,))) {
      __SET_VAR(data__->,ARR_MIN,,__GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)]));
    };
  };
  __SET_VAR(data__->,_ARRAY_SPR,,(__GET_VAR(data__->ARR_MAX,) - __GET_VAR(data__->ARR_MIN,)));

  goto __end;

__end:
  return;
} // ARRAY_SPR_body__() 





void _ARRAY_ADD_init__(_ARRAY_ADD *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const __ARRAY_OF_REAL_100 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,PT,,temp);
  }
  __INIT_VAR(data__->SIZE,0,retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->_ARRAY_ADD_Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->STOP,0,retain)
}

// Code part
void _ARRAY_ADD_body__(_ARRAY_ADD *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,STOP,,LIMIT__INT__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)1,
    (INT)UINT_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)__GET_VAR(data__->SIZE,)),
    (INT)1000));
  for(__GET_VAR(data__->I,) = 1; __GET_VAR(data__->I,) <= __GET_VAR(data__->STOP,); __GET_VAR(data__->I,)++) {
    __SET_VAR(data__->,PT,.table[(__GET_VAR(data__->I,)) - (1)],(__GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)]) + __GET_VAR(data__->X,)));
  };
  __SET_VAR(data__->,_ARRAY_ADD_Q,,__BOOL_LITERAL(TRUE));

  goto __end;

__end:
  return;
} // _ARRAY_ADD_body__() 





void _ARRAY_SORT_init__(_ARRAY_SORT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const __ARRAY_OF_REAL_100 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,PT,,temp);
  }
  __INIT_VAR(data__->SIZE,0,retain)
  __INIT_VAR(data__->_ARRAY_SORT_Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STACK_COUNT,0,retain)
  {
    static const __ARRAY_OF_INT_32 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,STACK,,temp);
  }
  __INIT_VAR(data__->LINKS,0,retain)
  __INIT_VAR(data__->RECHTS,0,retain)
  __INIT_VAR(data__->PIVOT,0,retain)
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->J,0,retain)
  __INIT_VAR(data__->ENDE_INNEN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ENDE_AUSSEN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TMP,0,retain)
  __INIT_VAR(data__->X,0,retain)
}

// Code part
void _ARRAY_SORT_body__(_ARRAY_SORT *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,LINKS,,1);
  __SET_VAR(data__->,RECHTS,,DWORD_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)SHR__DWORD__DWORD__SINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)UINT_TO_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UINT)__GET_VAR(data__->SIZE,)),
      (SINT)2)));
  __SET_VAR(data__->,STACK_COUNT,,1);
  while (!(__GET_VAR(data__->ENDE_AUSSEN,))) {
    if ((__GET_VAR(data__->LINKS,) < __GET_VAR(data__->RECHTS,))) {
      __SET_VAR(data__->,X,,DWORD_TO_INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)SHR__DWORD__DWORD__SINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)UDINT_TO_DWORD(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (UDINT)(INT_TO_UDINT(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (INT)__GET_VAR(data__->RECHTS,)) + INT_TO_UDINT(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (INT)__GET_VAR(data__->LINKS,)))),
          (SINT)1)));
      __SET_VAR(data__->,PIVOT,,__GET_VAR(data__->PT,.table[(__GET_VAR(data__->X,)) - (1)]));
      __SET_VAR(data__->,I,,(__GET_VAR(data__->LINKS,) - 1));
      __SET_VAR(data__->,J,,(__GET_VAR(data__->RECHTS,) + 1));
      __SET_VAR(data__->,ENDE_INNEN,,__BOOL_LITERAL(FALSE));
      do {
        do {
          __SET_VAR(data__->,I,,(__GET_VAR(data__->I,) + 1));
        } while(((__GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)]) >= __GET_VAR(data__->PIVOT,)) || !((__GET_VAR(data__->I,) < __GET_VAR(data__->RECHTS,)))));
        do {
          __SET_VAR(data__->,J,,(__GET_VAR(data__->J,) - 1));
        } while(((__GET_VAR(data__->PT,.table[(__GET_VAR(data__->J,)) - (1)]) <= __GET_VAR(data__->PIVOT,)) || !((__GET_VAR(data__->J,) > __GET_VAR(data__->LINKS,)))));
        if ((__GET_VAR(data__->I,) >= __GET_VAR(data__->J,))) {
          __SET_VAR(data__->,ENDE_INNEN,,__BOOL_LITERAL(TRUE));
        } else {
          __SET_VAR(data__->,TMP,,__GET_VAR(data__->PT,.table[(__GET_VAR(data__->J,)) - (1)]));
          __SET_VAR(data__->,PT,.table[(__GET_VAR(data__->J,)) - (1)],__GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)]));
          __SET_VAR(data__->,PT,.table[(__GET_VAR(data__->I,)) - (1)],__GET_VAR(data__->TMP,));
        };
      } while(__GET_VAR(data__->ENDE_INNEN,));
      __SET_VAR(data__->,STACK,.table[(__GET_VAR(data__->STACK_COUNT,)) - (1)],__GET_VAR(data__->RECHTS,));
      if ((__GET_VAR(data__->STACK_COUNT,) < 32)) {
        __SET_VAR(data__->,STACK_COUNT,,(__GET_VAR(data__->STACK_COUNT,) + 1));
      } else {
        __SET_VAR(data__->,ENDE_AUSSEN,,__BOOL_LITERAL(TRUE));
        __SET_VAR(data__->,_ARRAY_SORT_Q,,__BOOL_LITERAL(FALSE));
      };
      __SET_VAR(data__->,RECHTS,,MAX__INT__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UINT)2,
        (INT)__GET_VAR(data__->LINKS,),
        (INT)(__GET_VAR(data__->I,) - 1)));
    } else {
      if ((__GET_VAR(data__->STACK_COUNT,) == 1)) {
        __SET_VAR(data__->,ENDE_AUSSEN,,__BOOL_LITERAL(TRUE));
      } else {
        __SET_VAR(data__->,LINKS,,(__GET_VAR(data__->RECHTS,) + 1));
        __SET_VAR(data__->,STACK_COUNT,,(__GET_VAR(data__->STACK_COUNT,) - 1));
        __SET_VAR(data__->,RECHTS,,__GET_VAR(data__->STACK,.table[(__GET_VAR(data__->STACK_COUNT,)) - (1)]));
      };
    };
  };
  __SET_VAR(data__->,_ARRAY_SORT_Q,,__BOOL_LITERAL(TRUE));

  goto __end;

__end:
  return;
} // _ARRAY_SORT_body__() 





void _ARRAY_MEDIAN_init__(_ARRAY_MEDIAN *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const __ARRAY_OF_REAL_100 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,PT,,temp);
  }
  __INIT_VAR(data__->SIZE,0,retain)
  __INIT_VAR(data__->_ARRAY_MEDIAN_Q,0,retain)
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->I2,0,retain)
  __INIT_VAR(data__->STOP,0,retain)
  _ARRAY_SORT_init__(&data__->_ARRAY_SORT_MED,retain);
}

// Code part
void _ARRAY_MEDIAN_body__(_ARRAY_MEDIAN *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_ARRAY_SORT_MED.PT,,__GET_VAR(data__->PT,));
  __SET_VAR(data__->,_ARRAY_SORT_MED.SIZE,,__GET_VAR(data__->SIZE,));
  _ARRAY_SORT_body__(&data__->_ARRAY_SORT_MED);
  __SET_VAR(data__->,PT,,__GET_VAR(data__->_ARRAY_SORT_MED.PT,));
  __SET_VAR(data__->,STOP,,LIMIT__INT__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)1,
    (INT)UINT_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)__GET_VAR(data__->SIZE,)),
    (INT)1000));
  if (EVEN(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DINT)INT_TO_DINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)__GET_VAR(data__->STOP,)))) {
    __SET_VAR(data__->,I,,WORD_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (WORD)SHR__WORD__WORD__SINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)INT_TO_WORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (INT)__GET_VAR(data__->STOP,)),
        (SINT)1)));
    __SET_VAR(data__->,I2,,(__GET_VAR(data__->I,) + 1));
    __SET_VAR(data__->,_ARRAY_MEDIAN_Q,,((__GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)]) + __GET_VAR(data__->PT,.table[(__GET_VAR(data__->I2,)) - (1)])) * 0.5));
  } else {
    __SET_VAR(data__->,I,,(WORD_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (WORD)SHR__WORD__WORD__SINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)INT_TO_WORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (INT)__GET_VAR(data__->STOP,)),
        (SINT)1)) + 1));
    __SET_VAR(data__->,_ARRAY_MEDIAN_Q,,__GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)]));
  };

  goto __end;

__end:
  return;
} // _ARRAY_MEDIAN_body__() 





void _ARRAY_MUL_init__(_ARRAY_MUL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const __ARRAY_OF_REAL_100 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,PT,,temp);
  }
  __INIT_VAR(data__->SIZE,0,retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->_ARRAY_MUL_Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->STOP,0,retain)
}

// Code part
void _ARRAY_MUL_body__(_ARRAY_MUL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,STOP,,LIMIT__INT__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)1,
    (INT)UINT_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)__GET_VAR(data__->SIZE,)),
    (INT)1000));
  for(__GET_VAR(data__->I,) = 1; __GET_VAR(data__->I,) <= __GET_VAR(data__->STOP,); __GET_VAR(data__->I,)++) {
    __SET_VAR(data__->,PT,.table[(__GET_VAR(data__->I,)) - (1)],(__GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)]) * __GET_VAR(data__->X,)));
  };
  __SET_VAR(data__->,_ARRAY_MUL_Q,,__BOOL_LITERAL(TRUE));

  goto __end;

__end:
  return;
} // _ARRAY_MUL_body__() 





void ARRAY_VAR_init__(ARRAY_VAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const __ARRAY_OF_REAL_100 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,PT,,temp);
  }
  __INIT_VAR(data__->SIZE,0,retain)
  __INIT_VAR(data__->_ARRAY_VAR,0,retain)
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->STOP,0,retain)
  __INIT_VAR(data__->AVG,0,retain)
}

// Code part
void ARRAY_VAR_body__(ARRAY_VAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,STOP,,LIMIT__INT__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)1,
    (INT)UINT_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)__GET_VAR(data__->SIZE,)),
    (INT)1000));
  __SET_VAR(data__->,AVG,,__GET_VAR(data__->PT,.table[(1) - (1)]));
  for(__GET_VAR(data__->I,) = 2; __GET_VAR(data__->I,) <= __GET_VAR(data__->STOP,); __GET_VAR(data__->I,)++) {
    __SET_VAR(data__->,AVG,,(__GET_VAR(data__->AVG,) + __GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)])));
  };
  __SET_VAR(data__->,AVG,,(__GET_VAR(data__->AVG,) / INT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->STOP,))));
  __SET_VAR(data__->,_ARRAY_VAR,,EXPT__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(__GET_VAR(data__->PT,.table[(1) - (1)]) - __GET_VAR(data__->AVG,)),
    (REAL)2.0));
  for(__GET_VAR(data__->I,) = 2; __GET_VAR(data__->I,) <= __GET_VAR(data__->STOP,); __GET_VAR(data__->I,)++) {
    __SET_VAR(data__->,_ARRAY_VAR,,(__GET_VAR(data__->_ARRAY_VAR,) + EXPT__REAL__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(__GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)]) - __GET_VAR(data__->AVG,)),
      (REAL)2.0)));
  };
  __SET_VAR(data__->,_ARRAY_VAR,,(__GET_VAR(data__->_ARRAY_VAR,) / INT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)(__GET_VAR(data__->STOP,) - 1))));

  goto __end;

__end:
  return;
} // ARRAY_VAR_body__() 





void ARRAY_SDV_init__(ARRAY_SDV *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const __ARRAY_OF_REAL_100 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,PT,,temp);
  }
  __INIT_VAR(data__->SIZE,0,retain)
  __INIT_VAR(data__->_ARRAY_SDV,0,retain)
  ARRAY_VAR_init__(&data__->FB_ARRAY_VAR,retain);
}

// Code part
void ARRAY_SDV_body__(ARRAY_SDV *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,FB_ARRAY_VAR.PT,,__GET_VAR(data__->PT,));
  __SET_VAR(data__->,FB_ARRAY_VAR.SIZE,,__GET_VAR(data__->SIZE,));
  ARRAY_VAR_body__(&data__->FB_ARRAY_VAR);
  __SET_VAR(data__->,PT,,__GET_VAR(data__->FB_ARRAY_VAR.PT,));
  __SET_VAR(data__->,_ARRAY_SDV,,SQRT__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->FB_ARRAY_VAR._ARRAY_VAR,)));

  goto __end;

__end:
  return;
} // ARRAY_SDV_body__() 





void ARRAY_MAX_init__(ARRAY_MAX *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const __ARRAY_OF_REAL_100 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,PT,,temp);
  }
  __INIT_VAR(data__->SIZE,0,retain)
  __INIT_VAR(data__->_ARRAY_MAX,0,retain)
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->STOP,0,retain)
}

// Code part
void ARRAY_MAX_body__(ARRAY_MAX *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,STOP,,LIMIT__INT__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)1,
    (INT)UINT_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)__GET_VAR(data__->SIZE,)),
    (INT)1000));
  for(__GET_VAR(data__->I,) = 1; __GET_VAR(data__->I,) <= __GET_VAR(data__->STOP,); __GET_VAR(data__->I,)++) {
    if ((__GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)]) > __GET_VAR(data__->_ARRAY_MAX,))) {
      __SET_VAR(data__->,_ARRAY_MAX,,__GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)]));
    };
  };

  goto __end;

__end:
  return;
} // ARRAY_MAX_body__() 





void _ARRAY_INIT_init__(_ARRAY_INIT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const __ARRAY_OF_REAL_100 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,PT,,temp);
  }
  __INIT_VAR(data__->SIZE,0,retain)
  __INIT_VAR(data__->INIT,0,retain)
  __INIT_VAR(data__->_ARRAY_INIT_Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->STOP,0,retain)
}

// Code part
void _ARRAY_INIT_body__(_ARRAY_INIT *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,STOP,,LIMIT__INT__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)1,
    (INT)UINT_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)__GET_VAR(data__->SIZE,)),
    (INT)1000));
  for(__GET_VAR(data__->I,) = 1; __GET_VAR(data__->I,) <= __GET_VAR(data__->STOP,); __GET_VAR(data__->I,)++) {
    __SET_VAR(data__->,PT,.table[(__GET_VAR(data__->I,)) - (1)],__GET_VAR(data__->INIT,));
  };
  __SET_VAR(data__->,_ARRAY_INIT_Q,,__BOOL_LITERAL(TRUE));

  goto __end;

__end:
  return;
} // _ARRAY_INIT_body__() 





void ARRAY_SUM_init__(ARRAY_SUM *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const __ARRAY_OF_REAL_100 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,PT,,temp);
  }
  __INIT_VAR(data__->SIZE,0,retain)
  __INIT_VAR(data__->_ARRAY_SUM,0,retain)
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->STOP,0,retain)
}

// Code part
void ARRAY_SUM_body__(ARRAY_SUM *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,STOP,,LIMIT__INT__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)1,
    (INT)UINT_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)__GET_VAR(data__->SIZE,)),
    (INT)1000));
  __SET_VAR(data__->,_ARRAY_SUM,,__GET_VAR(data__->PT,.table[(1) - (1)]));
  for(__GET_VAR(data__->I,) = 2; __GET_VAR(data__->I,) <= __GET_VAR(data__->STOP,); __GET_VAR(data__->I,)++) {
    __SET_VAR(data__->,_ARRAY_SUM,,(__GET_VAR(data__->_ARRAY_SUM,) + __GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)])));
  };

  goto __end;

__end:
  return;
} // ARRAY_SUM_body__() 





void ARRAY_MIN_init__(ARRAY_MIN *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const __ARRAY_OF_REAL_100 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,PT,,temp);
  }
  __INIT_VAR(data__->SIZE,0,retain)
  __INIT_VAR(data__->_ARRAY_MIN,0,retain)
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->STOP,0,retain)
}

// Code part
void ARRAY_MIN_body__(ARRAY_MIN *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,STOP,,LIMIT__INT__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)1,
    (INT)UINT_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)__GET_VAR(data__->SIZE,)),
    (INT)1000));
  __SET_VAR(data__->,_ARRAY_MIN,,__GET_VAR(data__->PT,.table[(1) - (1)]));
  for(__GET_VAR(data__->I,) = 2; __GET_VAR(data__->I,) <= __GET_VAR(data__->STOP,); __GET_VAR(data__->I,)++) {
    if ((__GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)]) < __GET_VAR(data__->_ARRAY_MIN,))) {
      __SET_VAR(data__->,_ARRAY_MIN,,__GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)]));
    };
  };

  goto __end;

__end:
  return;
} // ARRAY_MIN_body__() 





// FUNCTION
REAL SQRTN(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  INT N)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL SQRTN = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SQRTN;
  }
  if ((N > 0)) {
    SQRTN = EXP__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(LN__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)X) / INT_TO_REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)N)));
  } else {
    SQRTN = 0.0;
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SQRTN;
}


void ARRAY_GAV_init__(ARRAY_GAV *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const __ARRAY_OF_REAL_100 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,PT,,temp);
  }
  __INIT_VAR(data__->SIZE,0,retain)
  __INIT_VAR(data__->_ARRAY_GAV,0,retain)
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->STOP,0,retain)
}

// Code part
void ARRAY_GAV_body__(ARRAY_GAV *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,STOP,,LIMIT__INT__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)1,
    (INT)UINT_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)__GET_VAR(data__->SIZE,)),
    (INT)1000));
  __SET_VAR(data__->,_ARRAY_GAV,,1.0);
  for(__GET_VAR(data__->I,) = 1; __GET_VAR(data__->I,) <= __GET_VAR(data__->STOP,); __GET_VAR(data__->I,)++) {
    if ((__GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)]) > 0.0)) {
      __SET_VAR(data__->,_ARRAY_GAV,,(__GET_VAR(data__->_ARRAY_GAV,) * __GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)])));
    } else {
      __SET_VAR(data__->,_ARRAY_GAV,,0.0);
      goto __end;
    };
  };
  __SET_VAR(data__->,_ARRAY_GAV,,SQRTN(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->_ARRAY_GAV,),
    (INT)__GET_VAR(data__->STOP,)));

  goto __end;

__end:
  return;
} // ARRAY_GAV_body__() 





void ARRAY_HAV_init__(ARRAY_HAV *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const __ARRAY_OF_REAL_100 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,PT,,temp);
  }
  __INIT_VAR(data__->SIZE,0,retain)
  __INIT_VAR(data__->_ARRAY_HAV,0,retain)
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->STOP,0,retain)
}

// Code part
void ARRAY_HAV_body__(ARRAY_HAV *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,STOP,,LIMIT__INT__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)1,
    (INT)UINT_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)__GET_VAR(data__->SIZE,)),
    (INT)1000));
  __SET_VAR(data__->,_ARRAY_HAV,,0.0);
  for(__GET_VAR(data__->I,) = 1; __GET_VAR(data__->I,) <= __GET_VAR(data__->STOP,); __GET_VAR(data__->I,)++) {
    if ((__GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)]) != 0.0)) {
      __SET_VAR(data__->,_ARRAY_HAV,,(__GET_VAR(data__->_ARRAY_HAV,) + (1.0 / __GET_VAR(data__->PT,.table[(__GET_VAR(data__->I,)) - (1)]))));
    } else {
      __SET_VAR(data__->,_ARRAY_HAV,,0.0);
      goto __end;
    };
  };
  __SET_VAR(data__->,_ARRAY_HAV,,(INT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->STOP,)) / __GET_VAR(data__->_ARRAY_HAV,)));

  goto __end;

__end:
  return;
} // ARRAY_HAV_body__() 





