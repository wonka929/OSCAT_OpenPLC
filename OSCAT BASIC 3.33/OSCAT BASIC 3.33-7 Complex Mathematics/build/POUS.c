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
REAL ATAN2(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL Y)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL ATAN2 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return ATAN2;
  }
  if ((X > 0.0)) {
    ATAN2 = ATAN__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(Y / X));
  } else if ((X < 0.0)) {
    if ((Y >= 0.0)) {
      ATAN2 = (ATAN__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)(Y / X)) + 3.14159265358979323846264338327950288);
    } else {
      ATAN2 = (ATAN__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)(Y / X)) - 3.14159265358979323846264338327950288);
    };
  } else if ((Y > 0.0)) {
    ATAN2 = 1.5707963267948965580;
  } else if ((Y < 0.0)) {
    ATAN2 = -1.5707963267948965580;
  } else {
    ATAN2 = 0.0;
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return ATAN2;
}


// FUNCTION
REAL HYPOT(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL Y)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL HYPOT = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return HYPOT;
  }
  HYPOT = SQRT__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)((X * X) + (Y * Y)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return HYPOT;
}


void CLOG_init__(CLOG *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,X,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,_CLOG,,temp);
  }
}

// Code part
void CLOG_body__(CLOG *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_CLOG,.RE,LN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)HYPOT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)__GET_VAR(data__->X,.RE),
      (REAL)__GET_VAR(data__->X,.IM))));
  __SET_VAR(data__->,_CLOG,.IM,ATAN2(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->X,.IM),
    (REAL)__GET_VAR(data__->X,.RE)));

  goto __end;

__end:
  return;
} // CLOG_body__() 





// FUNCTION
REAL COSH(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL T_C = 0;
  REAL COSH = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return COSH;
  }
  T_C = EXP__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)X);
  COSH = (((1.0 / T_C) + T_C) * 0.5);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return COSH;
}


void CADD_init__(CADD *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,X,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,Y,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,_CADD,,temp);
  }
}

// Code part
void CADD_body__(CADD *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_CADD,.RE,(__GET_VAR(data__->X,.RE) + __GET_VAR(data__->Y,.RE)));
  __SET_VAR(data__->,_CADD,.IM,(__GET_VAR(data__->X,.IM) + __GET_VAR(data__->Y,.IM)));

  goto __end;

__end:
  return;
} // CADD_body__() 





// FUNCTION
REAL SINH(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL SINH = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SINH;
  }
  if ((ABS__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)X) < 2.0E-3)) {
    SINH = X;
  } else {
    SINH = ((EXP__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)X) - EXP__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL) -(X))) * 0.5);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SINH;
}


void CSUB_init__(CSUB *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,X,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,Y,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,_CSUB,,temp);
  }
}

// Code part
void CSUB_body__(CSUB *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_CSUB,.RE,(__GET_VAR(data__->X,.RE) - __GET_VAR(data__->Y,.RE)));
  __SET_VAR(data__->,_CSUB,.IM,(__GET_VAR(data__->X,.IM) - __GET_VAR(data__->Y,.IM)));

  goto __end;

__end:
  return;
} // CSUB_body__() 





void CDIV_init__(CDIV *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,X,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,Y,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,_CDIV,,temp);
  }
  __INIT_VAR(data__->TEMP,0,retain)
}

// Code part
void CDIV_body__(CDIV *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,TEMP,,((__GET_VAR(data__->Y,.RE) * __GET_VAR(data__->Y,.RE)) + (__GET_VAR(data__->Y,.IM) * __GET_VAR(data__->Y,.IM))));
  if ((__GET_VAR(data__->TEMP,) == 0.0)) {
    __SET_VAR(data__->,_CDIV,.RE,0.0);
    __SET_VAR(data__->,_CDIV,.IM,0.0);
    goto __end;
  };
  __SET_VAR(data__->,_CDIV,.RE,(((__GET_VAR(data__->X,.RE) * __GET_VAR(data__->Y,.RE)) + (__GET_VAR(data__->X,.IM) * __GET_VAR(data__->Y,.IM))) / __GET_VAR(data__->TEMP,)));
  __SET_VAR(data__->,_CDIV,.IM,(((__GET_VAR(data__->X,.IM) * __GET_VAR(data__->Y,.RE)) - (__GET_VAR(data__->X,.RE) * __GET_VAR(data__->Y,.IM))) / __GET_VAR(data__->TEMP,)));

  goto __end;

__end:
  return;
} // CDIV_body__() 





void CABS_init__(CABS *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,X,,temp);
  }
  __INIT_VAR(data__->_CABS,0,retain)
}

// Code part
void CABS_body__(CABS *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_CABS,,HYPOT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->X,.RE),
    (REAL)__GET_VAR(data__->X,.IM)));

  goto __end;

__end:
  return;
} // CABS_body__() 





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





void CCOSH_init__(CCOSH *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,X,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,_CCOSH,,temp);
  }
}

// Code part
void CCOSH_body__(CCOSH *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_CCOSH,.RE,(COSH(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->X,.RE)) * COS__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->X,.IM))));
  __SET_VAR(data__->,_CCOSH,.IM,(SINH(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->X,.RE)) * SIN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->X,.IM))));

  goto __end;

__end:
  return;
} // CCOSH_body__() 





// FUNCTION
INT SGN(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT SGN = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SGN;
  }
  if ((X > 0.0)) {
    SGN = 1;
  } else if ((X < 0.0)) {
    SGN = -1;
  } else {
    SGN = 0;
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SGN;
}


void CSQRT_init__(CSQRT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,X,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,_CSQRT,,temp);
  }
  __INIT_VAR(data__->TEMP,0,retain)
}

// Code part
void CSQRT_body__(CSQRT *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,TEMP,,HYPOT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->X,.RE),
    (REAL)__GET_VAR(data__->X,.IM)));
  __SET_VAR(data__->,_CSQRT,.RE,SQRT__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(0.5 * (__GET_VAR(data__->TEMP,) + __GET_VAR(data__->X,.RE)))));
  __SET_VAR(data__->,_CSQRT,.IM,(INT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)SGN(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)__GET_VAR(data__->X,.IM))) * SQRT__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(0.5 * (__GET_VAR(data__->TEMP,) - __GET_VAR(data__->X,.RE))))));

  goto __end;

__end:
  return;
} // CSQRT_body__() 





void CASINH_init__(CASINH *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,X,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,_CASINH,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,Y,,temp);
  }
  CLOG_init__(&data__->_CLOG,retain);
  CSQRT_init__(&data__->_CSQRT,retain);
}

// Code part
void CASINH_body__(CASINH *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,Y,.RE,(((__GET_VAR(data__->X,.RE) - __GET_VAR(data__->X,.IM)) * (__GET_VAR(data__->X,.RE) + __GET_VAR(data__->X,.IM))) + 1.0));
  __SET_VAR(data__->,Y,.IM,((2.0 * __GET_VAR(data__->X,.RE)) * __GET_VAR(data__->X,.IM)));
  __SET_VAR(data__->_CSQRT.,X,,__GET_VAR(data__->Y,));
  CSQRT_body__(&data__->_CSQRT);
  __SET_VAR(data__->,Y,,__GET_VAR(data__->_CSQRT._CSQRT,));
  __SET_VAR(data__->,Y,.RE,(__GET_VAR(data__->Y,.RE) + __GET_VAR(data__->X,.RE)));
  __SET_VAR(data__->,Y,.IM,(__GET_VAR(data__->Y,.IM) + __GET_VAR(data__->X,.IM)));
  __SET_VAR(data__->_CLOG.,X,,__GET_VAR(data__->Y,));
  CLOG_body__(&data__->_CLOG);
  __SET_VAR(data__->,_CASINH,,__GET_VAR(data__->_CLOG._CLOG,));

  goto __end;

__end:
  return;
} // CASINH_body__() 





void CASIN_init__(CASIN *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,X,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,_CASIN,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,Y,,temp);
  }
  CASINH_init__(&data__->_CASINH,retain);
}

// Code part
void CASIN_body__(CASIN *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,Y,.RE, -(__GET_VAR(data__->X,.IM)));
  __SET_VAR(data__->,Y,.IM,__GET_VAR(data__->X,.RE));
  __SET_VAR(data__->_CASINH.,X,,__GET_VAR(data__->Y,));
  CASINH_body__(&data__->_CASINH);
  __SET_VAR(data__->,Y,,__GET_VAR(data__->_CASINH._CASINH,));
  __SET_VAR(data__->,_CASIN,.RE,__GET_VAR(data__->Y,.IM));
  __SET_VAR(data__->,_CASIN,.IM, -(__GET_VAR(data__->Y,.RE)));

  goto __end;

__end:
  return;
} // CASIN_body__() 





void CCON_init__(CCON *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,X,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,_CCON,,temp);
  }
}

// Code part
void CCON_body__(CCON *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_CCON,.RE,__GET_VAR(data__->X,.RE));
  __SET_VAR(data__->,_CCON,.IM, -(__GET_VAR(data__->X,.IM)));

  goto __end;

__end:
  return;
} // CCON_body__() 





void CMUL_init__(CMUL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,X,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,Y,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,_CMUL,,temp);
  }
}

// Code part
void CMUL_body__(CMUL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_CMUL,.RE,((__GET_VAR(data__->X,.RE) * __GET_VAR(data__->Y,.RE)) - (__GET_VAR(data__->X,.IM) * __GET_VAR(data__->Y,.IM))));
  __SET_VAR(data__->,_CMUL,.IM,((__GET_VAR(data__->X,.RE) * __GET_VAR(data__->Y,.IM)) + (__GET_VAR(data__->X,.IM) * __GET_VAR(data__->Y,.RE))));

  goto __end;

__end:
  return;
} // CMUL_body__() 





void CPOL_init__(CPOL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->L,0,retain)
  __INIT_VAR(data__->A,0,retain)
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,_CPOL,,temp);
  }
}

// Code part
void CPOL_body__(CPOL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_CPOL,.RE,(__GET_VAR(data__->L,) * COS__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->A,))));
  __SET_VAR(data__->,_CPOL,.IM,(__GET_VAR(data__->L,) * SIN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->A,))));

  goto __end;

__end:
  return;
} // CPOL_body__() 





void CACOSH_init__(CACOSH *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,X,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,_CACOSH,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,Y,,temp);
  }
  CLOG_init__(&data__->_CLOG,retain);
  CSQRT_init__(&data__->_CSQRT,retain);
}

// Code part
void CACOSH_body__(CACOSH *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,Y,.RE,(((__GET_VAR(data__->X,.RE) - __GET_VAR(data__->X,.IM)) * (__GET_VAR(data__->X,.RE) + __GET_VAR(data__->X,.IM))) - 1.0));
  __SET_VAR(data__->,Y,.IM,((2.0 * __GET_VAR(data__->X,.RE)) * __GET_VAR(data__->X,.IM)));
  __SET_VAR(data__->_CSQRT.,X,,__GET_VAR(data__->Y,));
  CSQRT_body__(&data__->_CSQRT);
  __SET_VAR(data__->,Y,,__GET_VAR(data__->_CSQRT._CSQRT,));
  __SET_VAR(data__->,Y,.RE,(__GET_VAR(data__->Y,.RE) + __GET_VAR(data__->X,.RE)));
  __SET_VAR(data__->,Y,.IM,(__GET_VAR(data__->Y,.IM) + __GET_VAR(data__->X,.IM)));
  __SET_VAR(data__->_CLOG.,X,,__GET_VAR(data__->Y,));
  CLOG_body__(&data__->_CLOG);
  __SET_VAR(data__->,_CACOSH,,__GET_VAR(data__->_CLOG._CLOG,));

  goto __end;

__end:
  return;
} // CACOSH_body__() 





void CACOS_init__(CACOS *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,X,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,_CACOS,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,Y,,temp);
  }
  CACOSH_init__(&data__->_CACOSH,retain);
}

// Code part
void CACOS_body__(CACOS *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->_CACOSH.,X,,__GET_VAR(data__->X,));
  CACOSH_body__(&data__->_CACOSH);
  __SET_VAR(data__->,Y,,__GET_VAR(data__->_CACOSH._CACOSH,));
  __SET_VAR(data__->,_CACOS,.RE,__GET_VAR(data__->Y,.IM));
  __SET_VAR(data__->,_CACOS,.IM, -(__GET_VAR(data__->Y,.RE)));

  goto __end;

__end:
  return;
} // CACOS_body__() 





void CATAN_init__(CATAN *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,X,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,_CATAN,,temp);
  }
  __INIT_VAR(data__->R2,0,retain)
  __INIT_VAR(data__->NUM,0,retain)
  __INIT_VAR(data__->DEN,0,retain)
}

// Code part
void CATAN_body__(CATAN *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,R2,,(__GET_VAR(data__->X,.RE) * __GET_VAR(data__->X,.RE)));
  __SET_VAR(data__->,DEN,,((1.0 - __GET_VAR(data__->R2,)) - (__GET_VAR(data__->X,.IM) * __GET_VAR(data__->X,.IM))));
  __SET_VAR(data__->,_CATAN,.RE,(0.5 * ATAN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)((2.0 * __GET_VAR(data__->X,.RE)) / __GET_VAR(data__->DEN,)))));
  __SET_VAR(data__->,NUM,,(__GET_VAR(data__->X,.IM) + 1.0));
  __SET_VAR(data__->,NUM,,(__GET_VAR(data__->R2,) + (__GET_VAR(data__->NUM,) * __GET_VAR(data__->NUM,))));
  __SET_VAR(data__->,DEN,,(__GET_VAR(data__->X,.IM) - 1.0));
  __SET_VAR(data__->,DEN,,(__GET_VAR(data__->R2,) + (__GET_VAR(data__->DEN,) * __GET_VAR(data__->DEN,))));
  __SET_VAR(data__->,_CATAN,.IM,(0.25 * (LN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->NUM,)) - LN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->DEN,)))));

  goto __end;

__end:
  return;
} // CATAN_body__() 





void CARG_init__(CARG *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,X,,temp);
  }
  __INIT_VAR(data__->_CARG,0,retain)
}

// Code part
void CARG_body__(CARG *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_CARG,,ATAN2(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->X,.IM),
    (REAL)__GET_VAR(data__->X,.RE)));

  goto __end;

__end:
  return;
} // CARG_body__() 





void CEXP_init__(CEXP *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,X,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,_CEXP,,temp);
  }
  __INIT_VAR(data__->TEMP,0,retain)
}

// Code part
void CEXP_body__(CEXP *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,TEMP,,EXP__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->X,.RE)));
  __SET_VAR(data__->,_CEXP,.RE,(__GET_VAR(data__->TEMP,) * COS__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->X,.IM))));
  __SET_VAR(data__->,_CEXP,.IM,(__GET_VAR(data__->TEMP,) * SIN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->X,.IM))));

  goto __end;

__end:
  return;
} // CEXP_body__() 





void CPOW_init__(CPOW *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,X,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,Y,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,_CPOW,,temp);
  }
  CLOG_init__(&data__->_CLOG,retain);
  CEXP_init__(&data__->_CEXP,retain);
  CMUL_init__(&data__->_CMUL,retain);
}

// Code part
void CPOW_body__(CPOW *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->_CLOG.,X,,__GET_VAR(data__->X,));
  CLOG_body__(&data__->_CLOG);
  __SET_VAR(data__->_CMUL.,X,,__GET_VAR(data__->Y,));
  __SET_VAR(data__->_CMUL.,Y,,__GET_VAR(data__->_CLOG._CLOG,));
  CMUL_body__(&data__->_CMUL);
  __SET_VAR(data__->_CEXP.,X,,__GET_VAR(data__->_CMUL._CMUL,));
  CEXP_body__(&data__->_CEXP);
  __SET_VAR(data__->,_CPOW,,__GET_VAR(data__->_CEXP._CEXP,));

  goto __end;

__end:
  return;
} // CPOW_body__() 





void CATANH_init__(CATANH *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,X,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,_CATANH,,temp);
  }
  __INIT_VAR(data__->I2,0,retain)
  __INIT_VAR(data__->NUM,0,retain)
  __INIT_VAR(data__->DEN,0,retain)
}

// Code part
void CATANH_body__(CATANH *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,I2,,(__GET_VAR(data__->X,.IM) * __GET_VAR(data__->X,.IM)));
  __SET_VAR(data__->,NUM,,(1.0 + __GET_VAR(data__->X,.RE)));
  __SET_VAR(data__->,NUM,,(__GET_VAR(data__->I2,) + (__GET_VAR(data__->NUM,) * __GET_VAR(data__->NUM,))));
  __SET_VAR(data__->,DEN,,(1.0 - __GET_VAR(data__->X,.RE)));
  __SET_VAR(data__->,DEN,,(__GET_VAR(data__->I2,) + (__GET_VAR(data__->DEN,) * __GET_VAR(data__->DEN,))));
  __SET_VAR(data__->,_CATANH,.RE,(0.25 * (LN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->NUM,)) - LN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->DEN,)))));
  __SET_VAR(data__->,DEN,,((1.0 - (__GET_VAR(data__->X,.RE) * __GET_VAR(data__->X,.RE))) - __GET_VAR(data__->I2,)));
  __SET_VAR(data__->,_CATANH,.IM,(0.5 * ATAN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)((2.0 * __GET_VAR(data__->X,.IM)) / __GET_VAR(data__->DEN,)))));

  goto __end;

__end:
  return;
} // CATANH_body__() 





void CSET_init__(CSET *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RE,0,retain)
  __INIT_VAR(data__->IM,0,retain)
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,_CSET,,temp);
  }
}

// Code part
void CSET_body__(CSET *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_CSET,.RE,__GET_VAR(data__->RE,));
  __SET_VAR(data__->,_CSET,.IM,__GET_VAR(data__->IM,));

  goto __end;

__end:
  return;
} // CSET_body__() 





void CINV_init__(CINV *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,X,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,_CINV,,temp);
  }
  __INIT_VAR(data__->TEMP,0,retain)
}

// Code part
void CINV_body__(CINV *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,TEMP,,((__GET_VAR(data__->X,.RE) * __GET_VAR(data__->X,.RE)) + (__GET_VAR(data__->X,.IM) * __GET_VAR(data__->X,.IM))));
  if ((__GET_VAR(data__->TEMP,) == 0.0)) {
    __SET_VAR(data__->,_CINV,.RE,0.0);
    __SET_VAR(data__->,_CINV,.IM,0.0);
    goto __end;
  };
  __SET_VAR(data__->,_CINV,.RE,(__GET_VAR(data__->X,.RE) / __GET_VAR(data__->TEMP,)));
  __SET_VAR(data__->,_CINV,.IM,( -(__GET_VAR(data__->X,.IM)) / __GET_VAR(data__->TEMP,)));

  goto __end;

__end:
  return;
} // CINV_body__() 





void CCOS_init__(CCOS *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,X,,temp);
  }
  {
    static const OSCAT_COMPLEX temp = {0,0};
    __SET_VAR(data__->,_CCOS,,temp);
  }
  CSET_init__(&data__->_CSET,retain);
  CCOSH_init__(&data__->_CCOSH,retain);
}

// Code part
void CCOS_body__(CCOS *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->_CSET.,RE,, -(__GET_VAR(data__->X,.IM)));
  __SET_VAR(data__->_CSET.,IM,,__GET_VAR(data__->X,.RE));
  CSET_body__(&data__->_CSET);
  __SET_VAR(data__->_CCOSH.,X,,__GET_VAR(data__->_CSET._CSET,));
  CCOSH_body__(&data__->_CCOSH);
  __SET_VAR(data__->,_CCOS,,__GET_VAR(data__->_CCOSH._CCOSH,));

  goto __end;

__end:
  return;
} // CCOS_body__() 





