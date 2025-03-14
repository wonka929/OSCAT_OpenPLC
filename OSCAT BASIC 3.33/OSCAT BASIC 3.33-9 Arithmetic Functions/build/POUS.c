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


void FT_RMP_init__(FT_RMP *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RMP,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->KR,0,retain)
  __INIT_VAR(data__->KF,0,retain)
  __INIT_VAR(data__->OUT,0,retain)
  __INIT_VAR(data__->BUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void FT_RMP_body__(FT_RMP *data__) {
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
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->IN,));
  };
  if (!(__GET_VAR(data__->RMP,))) {
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->,BUSY,,__BOOL_LITERAL(FALSE));
  } else if ((__GET_VAR(data__->OUT,) > __GET_VAR(data__->IN,))) {
    __SET_VAR(data__->,OUT,,(__GET_VAR(data__->OUT,) - ((TIME_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)__GET_VAR(data__->TX,)) * 0.001) * __GET_VAR(data__->KF,))));
    __SET_VAR(data__->,OUT,,MAX__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)2,
      (REAL)__GET_VAR(data__->IN,),
      (REAL)__GET_VAR(data__->OUT,)));
  } else if ((__GET_VAR(data__->OUT,) < __GET_VAR(data__->IN,))) {
    __SET_VAR(data__->,OUT,,(__GET_VAR(data__->OUT,) + ((TIME_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)__GET_VAR(data__->TX,)) * 0.001) * __GET_VAR(data__->KR,))));
    __SET_VAR(data__->,OUT,,MIN__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)2,
      (REAL)__GET_VAR(data__->IN,),
      (REAL)__GET_VAR(data__->OUT,)));
  };
  if ((__GET_VAR(data__->OUT,) < __GET_VAR(data__->IN,))) {
    __SET_VAR(data__->,BUSY,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,UD,,__BOOL_LITERAL(TRUE));
  } else if ((__GET_VAR(data__->OUT,) > __GET_VAR(data__->IN,))) {
    __SET_VAR(data__->,BUSY,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,UD,,__BOOL_LITERAL(FALSE));
  } else {
    __SET_VAR(data__->,BUSY,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,LAST,,__time_add(__GET_VAR(data__->LAST,), __GET_VAR(data__->TX,)));

  goto __end;

__end:
  return;
} // FT_RMP_body__() 





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


void F_POLY_init__(F_POLY *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X,0,retain)
  {
    static const __ARRAY_OF_REAL_8 temp = {{0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,C,,temp);
  }
  __INIT_VAR(data__->_F_POLY,0,retain)
}

// Code part
void F_POLY_body__(F_POLY *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_F_POLY,,((((((((((((((__GET_VAR(data__->C,.table[(7) - (0)]) * __GET_VAR(data__->X,)) + __GET_VAR(data__->C,.table[(6) - (0)])) * __GET_VAR(data__->X,)) + __GET_VAR(data__->C,.table[(5) - (0)])) * __GET_VAR(data__->X,)) + __GET_VAR(data__->C,.table[(4) - (0)])) * __GET_VAR(data__->X,)) + __GET_VAR(data__->C,.table[(3) - (0)])) * __GET_VAR(data__->X,)) + __GET_VAR(data__->C,.table[(2) - (0)])) * __GET_VAR(data__->X,)) + __GET_VAR(data__->C,.table[(1) - (0)])) * __GET_VAR(data__->X,)) + __GET_VAR(data__->C,.table[(0) - (0)])));

  goto __end;

__end:
  return;
} // F_POLY_body__() 





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_VAR(data__->LOCALVAR0,0,retain)
  __INIT_VAR(data__->LOCALVAR1,0,retain)
  __INIT_VAR(data__->LOCALVAR2,0,retain)
  __INIT_VAR(data__->LOCALVAR3,0,retain)
  F_POLY_init__(&data__->F_POLY0,retain);
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
  __SET_VAR(data__->F_POLY0.,X,,__GET_VAR(data__->LOCALVAR3,));
  F_POLY_body__(&data__->F_POLY0);

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





// FUNCTION
REAL LINEAR_INT(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  __ARRAY_OF_REAL_20_2 XY, 
  INT PTS)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT I = 0;
  REAL LINEAR_INT = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return LINEAR_INT;
  }
  PTS = MIN__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)PTS,
    (INT)20);
  I = 2;
  while (((I < PTS) && (XY.table[(I) - (1)][(0) - (0)] < X))) {
    I = (I + 1);
  };
  LINEAR_INT = (((((XY.table[(I) - (1)][(1) - (0)] - XY.table[((I - 1)) - (1)][(1) - (0)]) * X) - (XY.table[(I) - (1)][(1) - (0)] * XY.table[((I - 1)) - (1)][(0) - (0)])) + (XY.table[((I - 1)) - (1)][(1) - (0)] * XY.table[(I) - (1)][(0) - (0)])) / (XY.table[(I) - (1)][(0) - (0)] - XY.table[((I - 1)) - (1)][(0) - (0)]));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return LINEAR_INT;
}


void _FB_LINEAR_INT_init__(_FB_LINEAR_INT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X,0,retain)
  {
    static const __ARRAY_OF_REAL_20_2 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,XY,,temp);
  }
  __INIT_VAR(data__->PTS,0,retain)
  __INIT_VAR(data__->_LINEAR_INT,0,retain)
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->I2,0,retain)
}

// Code part
void _FB_LINEAR_INT_body__(_FB_LINEAR_INT *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,PTS,,MIN__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->PTS,),
    (INT)20));
  __SET_VAR(data__->,I,,2);
  while (((__GET_VAR(data__->I,) < __GET_VAR(data__->PTS,)) && (__GET_VAR(data__->XY,.table[(__GET_VAR(data__->I,)) - (1)][(0) - (0)]) < __GET_VAR(data__->X,)))) {
    __SET_VAR(data__->,I,,(__GET_VAR(data__->I,) + 1));
  };
  __SET_VAR(data__->,_LINEAR_INT,,(((((__GET_VAR(data__->XY,.table[(__GET_VAR(data__->I,)) - (1)][(1) - (0)]) - __GET_VAR(data__->XY,.table[((__GET_VAR(data__->I,) - 1)) - (1)][(1) - (0)])) * __GET_VAR(data__->X,)) - (__GET_VAR(data__->XY,.table[(__GET_VAR(data__->I,)) - (1)][(1) - (0)]) * __GET_VAR(data__->XY,.table[((__GET_VAR(data__->I,) - 1)) - (1)][(0) - (0)]))) + (__GET_VAR(data__->XY,.table[((__GET_VAR(data__->I,) - 1)) - (1)][(1) - (0)]) * __GET_VAR(data__->XY,.table[(__GET_VAR(data__->I,)) - (1)][(0) - (0)]))) / (__GET_VAR(data__->XY,.table[(__GET_VAR(data__->I,)) - (1)][(0) - (0)]) - __GET_VAR(data__->XY,.table[((__GET_VAR(data__->I,) - 1)) - (1)][(0) - (0)]))));

  goto __end;

__end:
  return;
} // _FB_LINEAR_INT_body__() 





// FUNCTION
BYTE FRMP_B(
  BOOL EN, 
  BOOL *__ENO)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BYTE START = 0;
  BOOL DIR = __BOOL_LITERAL(FALSE);
  TIME TD = __time_to_timespec(1, 0, 0, 0, 0, 0);
  TIME TR = __time_to_timespec(1, 0, 0, 0, 0, 0);
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


void DELAY_init__(DELAY *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT,0,retain)
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STOP,0,retain)
  {
    static const __ARRAY_OF_REAL_32 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,BUF,,temp);
  }
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





void FT_AVG_init__(FT_AVG *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->_E,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->N,32,retain)
  __INIT_VAR(data__->AVG,0,retain)
  DELAY_init__(&data__->BUFF,retain);
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void FT_AVG_body__(FT_AVG *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,BUFF.N,,LIMIT__INT__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)0,
    (INT)__GET_VAR(data__->N,),
    (INT)32));
  if ((!(__GET_VAR(data__->INIT,)) || __GET_VAR(data__->RST,))) {
    for(__GET_VAR(data__->I,) = 1; __GET_VAR(data__->I,) <= __GET_VAR(data__->N,); __GET_VAR(data__->I,)++) {
      __SET_VAR(data__->BUFF.,IN,,__GET_VAR(data__->IN,));
      DELAY_body__(&data__->BUFF);
    };
    __SET_VAR(data__->,AVG,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
  } else if (__GET_VAR(data__->_E,)) {
    __SET_VAR(data__->BUFF.,IN,,__GET_VAR(data__->IN,));
    DELAY_body__(&data__->BUFF);
    __SET_VAR(data__->,AVG,,(__GET_VAR(data__->AVG,) + ((__GET_VAR(data__->IN,) - __GET_VAR(data__->BUFF.OUT,)) / INT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)__GET_VAR(data__->N,)))));
  };

  goto __end;

__end:
  return;
} // FT_AVG_body__() 





// FUNCTION
REAL F_QUAD(
  BOOL EN, 
  BOOL *__ENO)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL X = 0;
  REAL A = 0;
  REAL B = 0;
  REAL C = 0;
  REAL F_QUAD = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return F_QUAD;
  }
  F_QUAD = ((((A * X) + B) * X) + C);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return F_QUAD;
}


// FUNCTION
REAL F_POWER(
  BOOL EN, 
  BOOL *__ENO)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL A = 0;
  REAL X = 0;
  REAL N = 0;
  REAL F_POWER = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return F_POWER;
  }
  F_POWER = (A * EXPT__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)X,
    (REAL)N));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return F_POWER;
}


// FUNCTION
REAL F_LIN(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL A, 
  REAL B)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL F_LIN = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return F_LIN;
  }
  F_LIN = ((A * X) + B);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return F_LIN;
}


// FUNCTION
REAL F_LIN2(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL X1, 
  REAL X2, 
  REAL Y1, 
  REAL Y2)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL F_LIN2 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return F_LIN2;
  }
  F_LIN2 = ((((Y2 - Y1) / (X2 - X1)) * (X - X1)) + Y1);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return F_LIN2;
}


// FUNCTION
REAL POLYNOM_INT(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  __ARRAY_OF_REAL_5_2 XY, 
  INT PTS)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT I = 0;
  INT J = 0;
  INT STOP = 0;
  REAL POLYNOM_INT = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return POLYNOM_INT;
  }
  PTS = MIN__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)PTS,
    (INT)5);
  for(I = 1; I <= PTS; I++) {
    STOP = (I + 1);
    for(J = PTS; ((-1) > 0)? (J <= (STOP)) : (J >= (STOP)); J += (-1)) {
      XY.table[(J) - (1)][(1) - (0)] = ((XY.table[(J) - (1)][(1) - (0)] - XY.table[((J - 1)) - (1)][(1) - (0)]) / (XY.table[(J) - (1)][(0) - (0)] - XY.table[((J - I)) - (1)][(0) - (0)]));
    };
  };
  POLYNOM_INT = 0.0;
  for(I = PTS; ((-1) > 0)? (I <= (1)) : (I >= (1)); I += (-1)) {
    POLYNOM_INT = ((POLYNOM_INT * (X - XY.table[(I) - (1)][(0) - (0)])) + XY.table[(I) - (1)][(1) - (0)]);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return POLYNOM_INT;
}


void FT_MIN_MAX_init__(FT_MIN_MAX *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MX,0,retain)
  __INIT_VAR(data__->MN,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void FT_MIN_MAX_body__(FT_MIN_MAX *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (((__GET_VAR(data__->RST,) == __BOOL_LITERAL(TRUE)) || (__GET_VAR(data__->INIT,) == __BOOL_LITERAL(FALSE)))) {
    __SET_VAR(data__->,MN,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->,MX,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
  } else if ((__GET_VAR(data__->IN,) < __GET_VAR(data__->MN,))) {
    __SET_VAR(data__->,MN,,__GET_VAR(data__->IN,));
  } else if ((__GET_VAR(data__->IN,) > __GET_VAR(data__->MX,))) {
    __SET_VAR(data__->,MX,,__GET_VAR(data__->IN,));
  };

  goto __end;

__end:
  return;
} // FT_MIN_MAX_body__() 





