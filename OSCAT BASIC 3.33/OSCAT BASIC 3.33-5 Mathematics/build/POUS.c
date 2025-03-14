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
REAL MUL_ADD(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL K, 
  REAL O)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL MUL_ADD = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return MUL_ADD;
  }
  MUL_ADD = ((X * K) + O);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return MUL_ADD;
}


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


// FUNCTION
REAL ERF(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL X2 = 0;
  REAL AX2 = 0;
  REAL ERF = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return ERF;
  }
  X2 = (X * X);
  AX2 = ((0.147 * X2) + 1.0);
  ERF = (SQRT__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(1.0 - EXP__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)( -(X2) * ((0.27323954473516 + AX2) / AX2))))) * INT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)SGN(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)X)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return ERF;
}


// FUNCTION
REAL GAUSSCD(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL U, 
  REAL SI)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL GAUSSCD = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return GAUSSCD;
  }
  GAUSSCD = ((ERF(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)((X - U) / (SI * 1.414213562))) + 1.0) * 0.5);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return GAUSSCD;
}


// FUNCTION
REAL GOLD(
  BOOL EN, 
  BOOL *__ENO)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL X = 0;
  REAL GOLD = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return GOLD;
  }
  GOLD = ((X + SQRT__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)((X * X) + 4.0))) * 0.5);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return GOLD;
}


// FUNCTION
REAL SINC(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL SINC = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SINC;
  }
  if ((X == 0.0)) {
    SINC = 1.0;
  } else {
    SINC = (SIN__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)X) / X);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SINC;
}


// FUNCTION
REAL MAX3(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN1, 
  REAL IN2, 
  REAL IN3)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL MAX3 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return MAX3;
  }
  MAX3 = MAX__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)MAX__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)2,
      (REAL)IN1,
      (REAL)IN2),
    (REAL)IN3);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return MAX3;
}


// FUNCTION
REAL ATANH(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL ATANH = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return ATANH;
  }
  ATANH = (LN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)((1.0 + X) / (1.0 - X))) * 0.5);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return ATANH;
}


// FUNCTION
REAL NEGX(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL NEGX = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return NEGX;
  }
  NEGX =  -(X);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return NEGX;
}


// FUNCTION
INT CEIL(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT CEIL = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return CEIL;
  }
  CEIL = REAL_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)X);
  if ((INT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)CEIL) < X)) {
    CEIL = (CEIL + 1);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return CEIL;
}


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
REAL SINH(
  BOOL EN, 
  BOOL *__ENO)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL X = 0;
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


// FUNCTION
REAL CAUCHY(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL T_CAUCHY, 
  REAL U)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL TMP = 0;
  REAL CAUCHY = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return CAUCHY;
  }
  TMP = (X - T_CAUCHY);
  CAUCHY = ((0.318309886183791 * U) / ((U * U) + (TMP * TMP)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return CAUCHY;
}


// FUNCTION
REAL CAUCHYCD(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL T_CAUCHY, 
  REAL U)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL CAUCHYCD = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return CAUCHYCD;
  }
  CAUCHYCD = (0.5 + (0.318309886183791 * ATAN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)((X - T_CAUCHY) / U))));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return CAUCHYCD;
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
REAL MID3(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN1, 
  REAL IN2, 
  REAL IN3)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL _IN1 = 0;
  REAL _IN2 = 0;
  REAL _IN3 = 0;
  REAL MID3 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return MID3;
  }
  _IN1 = IN1;
  _IN2 = IN2;
  _IN3 = IN3;
  if ((_IN1 > _IN2)) {
    MID3 = _IN1;
    _IN1 = _IN2;
    _IN2 = MID3;
  };
  if ((_IN2 > _IN3)) {
    _IN2 = _IN3;
  };
  MID3 = SEL__REAL__BOOL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)(_IN1 > _IN2),
    (REAL)_IN2,
    (REAL)_IN1);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return MID3;
}


// FUNCTION
REAL GAMMA(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL GAMMA = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return GAMMA;
  }
  if ((X > 0.0)) {
    GAMMA = (SQRT__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(6.28318530717958647692528676655900576 / X)) * EXPT__REAL__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(0.367879441171442 * (X + (1.0 / ((12.0 * X) - (0.1 / X))))),
      (REAL)X));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return GAMMA;
}


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
REAL EXP10(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL EXP10 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return EXP10;
  }
  EXP10 = EXP__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(X * 2.30258509299405));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return EXP10;
}


// FUNCTION
BOOL CMP(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL Y, 
  INT N)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL TMP = 0;
  BOOL CMP = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return CMP;
  }
  TMP = ABS__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)X);
  if ((TMP > 0.0)) {
    TMP = EXP10(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)INT_TO_REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)((FLOOR(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (REAL)LOG__REAL__REAL(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (REAL)TMP)) - N) + 1)));
  } else {
    TMP = EXP10(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)TMP);
  };
  CMP = (ABS__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(X - Y)) < TMP);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return CMP;
}


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
  {
    static const FRACTION temp = {0,0};
    __SET_VAR(data__->,LOCALVAR2,,temp);
  }
  __INIT_VAR(data__->LOCALVAR1,0,retain)
  __INIT_VAR(data__->CEIL5_OUT,0,retain)
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,CEIL5_OUT,,CEIL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->LOCALVAR0,)));
  __SET_VAR(data__->,LOCALVAR1,,__GET_VAR(data__->CEIL5_OUT,));

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





// FUNCTION
BOOL SIGN_I(
  BOOL EN, 
  BOOL *__ENO, 
  DINT IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BOOL SIGN_I = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SIGN_I;
  }
  SIGN_I = BIT_OF_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)DINT_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DINT)IN),
    (INT)31);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SIGN_I;
}


// FUNCTION
REAL ACOTH(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL ACOTH = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return ACOTH;
  }
  ACOTH = (LN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)((X + 1.0) / (X - 1.0))) * 0.5);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return ACOTH;
}


// FUNCTION
REAL SIGMOID(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL SIGMOID = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SIGMOID;
  }
  if ((X > 20.0)) {
    SIGMOID = 1.0;
  } else if ((X < -85.0)) {
    SIGMOID = 0.0;
  } else {
    SIGMOID = (1.0 / (1.0 + EXP__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL) -(X))));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SIGMOID;
}


// FUNCTION
REAL LAMBERT_W(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL W = 0;
  INT I = 0;
  REAL WE = 0;
  REAL W1E = 0;
  REAL EWX = 0;
  DWORD LAST = 0;
  REAL LAMBERT_W = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return LAMBERT_W;
  }
  if ((X < -0.367879441171442)) {
    LAMBERT_W = -1000.0;
    goto __end;
  } else if ((X == 0.0)) {
    goto __end;
  } else if ((X <= 500.0)) {
    W = LN__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(X + 1.0));
    W = (((0.665 * (1.0 + (0.0195 * W))) * W) + 0.04);
  } else {
    W = (LN__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(X - 4.0)) - ((1.0 - (1.0 / LN__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)X))) * LN__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)LN__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)X))));
  };
  for(I = 0; I <= 5; I++) {
    EWX = EXP__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)W);
    WE = ((W * EWX) - X);
    W1E = ((W + 1.0) * EWX);
    LAST = (REAL_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)W) & __DWORD_LITERAL(0xFFFFFFFC));
    W = (W - (WE / (W1E - (((W + 2.0) * WE) / ((2.0 * W) + 2.0)))));
    if (((REAL_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)W) & __DWORD_LITERAL(0xFFFFFFFC)) == LAST)) {
      break;
    };
  };
  LAMBERT_W = W;

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return LAMBERT_W;
}


// FUNCTION
REAL COTH(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL COTH = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return COTH;
  }
  if ((X > 20.0)) {
    COTH = 1.0;
  } else if ((X < -20.0)) {
    COTH = -1.0;
  } else {
    COTH = (1.0 + (2.0 / (EXP__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(X * 2.0)) - 1.0)));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return COTH;
}


// FUNCTION
REAL LANGEVIN(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL LANGEVIN = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return LANGEVIN;
  }
  if ((X == 0.0)) {
    LANGEVIN = 0.0;
  } else {
    LANGEVIN = (COTH(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)X) - (1.0 / X));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return LANGEVIN;
}


// FUNCTION
BOOL WINDOW(
  BOOL EN, 
  BOOL *__ENO, 
  REAL LOW, 
  REAL IN, 
  REAL HIGH)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BOOL WINDOW = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return WINDOW;
  }
  WINDOW = ((IN < HIGH) && (IN > LOW));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return WINDOW;
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
REAL ROUND(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN, 
  INT N)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL X = 0;
  REAL ROUND = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return ROUND;
  }
  if ((N < 4)) {
    if ((N < 2)) {
      if ((N == 0)) {
        X = 1.0;
      } else {
        X = 10.0;
      };
    } else {
      if ((N == 2)) {
        X = 100.0;
      } else {
        X = 1000.0;
      };
    };
  } else {
    if ((N < 6)) {
      if ((N == 4)) {
        X = 10000.0;
      } else {
        X = 100000.0;
      };
    } else {
      if ((N == 6)) {
        X = 1000000.0;
      } else {
        X = 10000000.0;
      };
    };
  };
  ROUND = (DINT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DINT)REAL_TO_DINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(IN * X))) / X);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return ROUND;
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





// FUNCTION
REAL ERFC(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL ERFC = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return ERFC;
  }
  ERFC = (1.0 - ERF(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)X));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return ERFC;
}


// FUNCTION
REAL RAD(
  BOOL EN, 
  BOOL *__ENO, 
  REAL _DEG)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL RAD = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return RAD;
  }
  RAD = MODR(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(0.0174532925199433 * _DEG),
    (REAL)6.283185307179586476);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return RAD;
}


// FUNCTION
REAL DEG(
  BOOL EN, 
  BOOL *__ENO, 
  REAL RAD_IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL DEG = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DEG;
  }
  DEG = MODR(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(57.29577951308232 * RAD_IN),
    (REAL)360.0);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return DEG;
}


// FUNCTION
REAL EXPN(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  INT N)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  WORD N_WORD = 0;
  REAL X_TMP = 0;
  BOOL SIGN = __BOOL_LITERAL(FALSE);
  REAL EXPN = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return EXPN;
  }
  N_WORD = INT_TO_WORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)N);
  X_TMP = X;
  SIGN = BIT_OF_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)WORD_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (WORD)N_WORD),
    (INT)15);
  N_WORD = INT_TO_WORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)ABS__INT__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)N));
  if (BIT_OF_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)WORD_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (WORD)N_WORD),
    (INT)0)) {
    EXPN = X_TMP;
  } else {
    EXPN = 1.0;
  };
  N_WORD = SHR__WORD__WORD__SINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (WORD)N_WORD,
    (SINT)1);
  while ((N_WORD > __WORD_LITERAL(0))) {
    X_TMP = (X_TMP * X_TMP);
    if (BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)WORD_TO_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)N_WORD),
      (INT)0)) {
      EXPN = (EXPN * X_TMP);
    };
    N_WORD = SHR__WORD__WORD__SINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (WORD)N_WORD,
      (SINT)1);
  };
  if (SIGN) {
    EXPN = (1.0 / EXPN);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return EXPN;
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


// FUNCTION
INT GCD(
  BOOL EN, 
  BOOL *__ENO, 
  DINT A, 
  DINT B)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  DINT _T = 0;
  DINT _A = 0;
  DINT _B = 0;
  INT GCD = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return GCD;
  }
  _A = A;
  _B = B;
  if ((_A == __DINT_LITERAL(0))) {
    GCD = DINT_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DINT)ABS__DINT__DINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DINT)_B));
  } else if ((_B == __DINT_LITERAL(0))) {
    GCD = DINT_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DINT)ABS__DINT__DINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DINT)_A));
  } else {
    _A = ABS__DINT__DINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DINT)_A);
    _B = ABS__DINT__DINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DINT)_B);
    GCD = 1;
    while (!((((DINT_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DINT)_A) & __DWORD_LITERAL(1)) > __DWORD_LITERAL(0)) || ((DINT_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DINT)_B) & __DWORD_LITERAL(1)) > __DWORD_LITERAL(0))))) {
      _A = DWORD_TO_DINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)SHR__DWORD__DWORD__SINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)DINT_TO_DWORD(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (DINT)_A),
          (SINT)1));
      _B = DWORD_TO_DINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)SHR__DWORD__DWORD__SINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)DINT_TO_DWORD(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (DINT)_B),
          (SINT)1));
      GCD = DWORD_TO_INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)SHR__DWORD__DWORD__SINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)INT_TO_DWORD(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (INT)GCD),
          (SINT)1));
    };
    while ((_A > __DINT_LITERAL(0))) {
      if (!(((DINT_TO_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DINT)_A) & __DWORD_LITERAL(1)) > __DWORD_LITERAL(0)))) {
        _A = DWORD_TO_DINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)SHR__DWORD__DWORD__SINT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (DWORD)DINT_TO_DWORD(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (DINT)_A),
            (SINT)1));
      } else if (!(((DINT_TO_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DINT)_B) & __DWORD_LITERAL(1)) > __DWORD_LITERAL(0)))) {
        _B = DWORD_TO_DINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)SHR__DWORD__DWORD__SINT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (DWORD)DINT_TO_DWORD(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (DINT)_B),
            (SINT)1));
      } else {
        _T = DWORD_TO_DINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)SHR__DWORD__DWORD__SINT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (DWORD)DINT_TO_DWORD(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (DINT)ABS__DINT__DINT(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (DINT)(_A - _B))),
            (SINT)1));
        if ((_A < _B)) {
          _B = _T;
        } else {
          _A = _T;
        };
      };
    };
    GCD = (GCD * DINT_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DINT)_B));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return GCD;
}


// FUNCTION
BOOL DIFFER(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN1, 
  REAL IN2, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BOOL DIFFER = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DIFFER;
  }
  DIFFER = (ABS__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(IN1 - IN2)) > X);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return DIFFER;
}


void REAL_TO_FRAC_init__(REAL_TO_FRAC *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->N,0,retain)
  {
    static const FRACTION temp = {0,0};
    __SET_VAR(data__->,_REAL_TO_FRAC,,temp);
  }
  __INIT_VAR(data__->TEMP,0,retain)
  __INIT_VAR(data__->SIGN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->X_GERUNDET,0,retain)
  __INIT_VAR(data__->X_OHNE_NACHKOMMA,0,retain)
  __INIT_VAR(data__->NUMERATOR,1,retain)
  __INIT_VAR(data__->DENOMINATOR,0,retain)
  __INIT_VAR(data__->NUMERATOR_OLD,0,retain)
  __INIT_VAR(data__->DENOMINATOR_OLD,1,retain)
}

// Code part
void REAL_TO_FRAC_body__(REAL_TO_FRAC *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->X,) < 0.0)) {
    __SET_VAR(data__->,SIGN,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,X,,ABS__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)__GET_VAR(data__->X,)));
  };
  do {
    __SET_VAR(data__->,X_GERUNDET,,REAL_TO_DINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)__GET_VAR(data__->X,)));
    __SET_VAR(data__->,TEMP,,((__GET_VAR(data__->NUMERATOR,) * __GET_VAR(data__->X_GERUNDET,)) + __GET_VAR(data__->NUMERATOR_OLD,)));
    __SET_VAR(data__->,NUMERATOR_OLD,,__GET_VAR(data__->NUMERATOR,));
    __SET_VAR(data__->,NUMERATOR,,__GET_VAR(data__->TEMP,));
    __SET_VAR(data__->,TEMP,,((__GET_VAR(data__->DENOMINATOR,) * __GET_VAR(data__->X_GERUNDET,)) + __GET_VAR(data__->DENOMINATOR_OLD,)));
    __SET_VAR(data__->,DENOMINATOR_OLD,,__GET_VAR(data__->DENOMINATOR,));
    __SET_VAR(data__->,DENOMINATOR,,__GET_VAR(data__->TEMP,));
    __SET_VAR(data__->,X_OHNE_NACHKOMMA,,DINT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DINT)__GET_VAR(data__->X_GERUNDET,)));
    if ((__GET_VAR(data__->X,) == __GET_VAR(data__->X_OHNE_NACHKOMMA,))) {
      if ((ABS__DINT__DINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DINT)__GET_VAR(data__->DENOMINATOR,)) <= INT_TO_DINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)__GET_VAR(data__->N,)))) {
        __SET_VAR(data__->,NUMERATOR_OLD,,__GET_VAR(data__->NUMERATOR,));
        __SET_VAR(data__->,DENOMINATOR_OLD,,__GET_VAR(data__->DENOMINATOR,));
      };
      break;
    } else {
      __SET_VAR(data__->,X,,(1.0 / (__GET_VAR(data__->X,) - __GET_VAR(data__->X_OHNE_NACHKOMMA,))));
    };
  } while((ABS__DINT__DINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DINT)__GET_VAR(data__->DENOMINATOR,)) > INT_TO_DINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->N,))));
  if (__GET_VAR(data__->SIGN,)) {
    __SET_VAR(data__->,_REAL_TO_FRAC,.NUMERATOR,(-1 * ABS__INT__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)DINT_TO_INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DINT)__GET_VAR(data__->NUMERATOR_OLD,)))));
  } else {
    __SET_VAR(data__->,_REAL_TO_FRAC,.NUMERATOR,ABS__INT__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)DINT_TO_INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DINT)__GET_VAR(data__->NUMERATOR_OLD,))));
  };
  __SET_VAR(data__->,_REAL_TO_FRAC,.DENOMINATOR,ABS__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)DINT_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DINT)__GET_VAR(data__->DENOMINATOR_OLD,))));

  goto __end;

__end:
  return;
} // REAL_TO_FRAC_body__() 





// FUNCTION
DINT FIB(
  BOOL EN, 
  BOOL *__ENO, 
  INT X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  DINT T1 = 0;
  DINT T2 = 0;
  INT X_TMP = 0;
  DINT FIB = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return FIB;
  }
  T1 = __DINT_LITERAL(0);
  T2 = __DINT_LITERAL(0);
  X_TMP = X;
  if (((X_TMP < 0) || (X_TMP > 46))) {
    FIB = __DINT_LITERAL(-1);
  } else if ((X_TMP < 2)) {
    FIB = INT_TO_DINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)X_TMP);
    goto __end;
  } else {
    T2 = __DINT_LITERAL(1);
    while ((X_TMP > 3)) {
      X_TMP = (X_TMP - 2);
      T1 = (T1 + T2);
      T2 = (T1 + T2);
    };
    if ((X_TMP > 2)) {
      T1 = (T1 + T2);
    };
    FIB = (T1 + T2);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return FIB;
}


// FUNCTION
REAL BETA(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL Y)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL BETA = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return BETA;
  }
  BETA = ((GAMMA(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)X) * GAMMA(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)Y)) / GAMMA(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(X + Y)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return BETA;
}


// FUNCTION
DINT CEIL2(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  DINT CEIL2 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return CEIL2;
  }
  CEIL2 = REAL_TO_DINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)X);
  if ((DINT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DINT)CEIL2) < X)) {
    CEIL2 = (CEIL2 + __DINT_LITERAL(1));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return CEIL2;
}


// FUNCTION
REAL AGDF(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL AGDF = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return AGDF;
  }
  AGDF = LN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)((1.0 + SIN__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)X)) / COS__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)X)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return AGDF;
}


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


void RDMDW_init__(RDMDW *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->LAST,0,retain)
  __INIT_VAR(data__->_RDMDW,0,retain)
  __INIT_VAR(data__->RX,0,retain)
  __INIT_VAR(data__->M,0,retain)
  RDM_init__(&data__->_RDM,retain);
}

// Code part
void RDMDW_body__(RDMDW *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,M,,INT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)BIT_COUNT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)__GET_VAR(data__->LAST,))));
  __SET_VAR(data__->_RDM.,LAST,,FRACT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(__GET_VAR(data__->M,) * 3.14159265358979323846264338327950288)));
  RDM_body__(&data__->_RDM);
  __SET_VAR(data__->,RX,,__GET_VAR(data__->_RDM._RDM,));
  __SET_VAR(data__->,_RDMDW,,SHL__DWORD__DWORD__SINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)REAL_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(__GET_VAR(data__->RX,) * 65535.0)),
    (SINT)16));
  __SET_VAR(data__->_RDM.,LAST,,FRACT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(__GET_VAR(data__->M,) * 2.71828182845904523536028747135266249)));
  RDM_body__(&data__->_RDM);
  __SET_VAR(data__->,RX,,__GET_VAR(data__->_RDM._RDM,));
  __SET_VAR(data__->,_RDMDW,,(__GET_VAR(data__->_RDMDW,) | (REAL_TO_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(__GET_VAR(data__->RX,) * 65535.0)) & __DWORD_LITERAL(0xFFFF))));

  goto __end;

__end:
  return;
} // RDMDW_body__() 





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


// FUNCTION
REAL ASINH(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL ASINH = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return ASINH;
  }
  ASINH = LN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(SQRT__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)((X * X) + 1.0)) + X));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return ASINH;
}


// FUNCTION
REAL MIN3(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN1, 
  REAL IN2, 
  REAL IN3)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL MIN3 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return MIN3;
  }
  MIN3 = MIN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)MIN__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)2,
      (REAL)IN1,
      (REAL)IN2),
    (REAL)IN3);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return MIN3;
}


// FUNCTION
REAL TANC(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL TANC = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return TANC;
  }
  if ((X == 0.0)) {
    TANC = 1.0;
  } else {
    TANC = (TAN__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)X) / X);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return TANC;
}


// FUNCTION
BOOL WINDOW2(
  BOOL EN, 
  BOOL *__ENO, 
  REAL LOW, 
  REAL IN, 
  REAL HIGH)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BOOL WINDOW2 = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return WINDOW2;
  }
  WINDOW2 = ((IN <= HIGH) && (IN >= LOW));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return WINDOW2;
}


// FUNCTION
REAL INV(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL INV = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return INV;
  }
  if ((X != 0.0)) {
    INV = (1.0 / X);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return INV;
}


// FUNCTION
REAL TANH(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL TANH = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return TANH;
  }
  if ((X > 20.0)) {
    TANH = 1.0;
  } else if ((X < -20.0)) {
    TANH = -1.0;
  } else {
    TANH = (1.0 - (2.0 / (EXP__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(2.0 * X)) + 1.0)));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return TANH;
}


// FUNCTION
REAL GAUSS(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  REAL U, 
  REAL SI)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL TEMP = 0;
  REAL SI_INV = 0;
  REAL GAUSS = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return GAUSS;
  }
  TEMP = (X - U);
  SI_INV = (1.0 / SI);
  GAUSS = ((EXP__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)((((TEMP * TEMP) * SI_INV) * SI_INV) * -0.5)) * 0.39894228) * SI_INV);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return GAUSS;
}


// FUNCTION
REAL RND(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  INT N)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL M = 0;
  REAL RND = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return RND;
  }
  if ((X == 0.0)) {
    RND = 0.0;
  } else {
    M = EXPN(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)10.0,
      (INT)(N - CEIL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)LOG__REAL__REAL(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (REAL)ABS__REAL__REAL(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (REAL)X)))));
    RND = (DINT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DINT)REAL_TO_DINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)(X * M))) / M);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return RND;
}


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


// FUNCTION
REAL SQRTN(
  BOOL EN, 
  BOOL *__ENO)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL X = 0;
  INT N = 0;
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


// FUNCTION
REAL GDF(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL GDF = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return GDF;
  }
  if ((X == 0.0)) {
    GDF = 0.0;
  } else if ((X > 15.0)) {
    GDF = 1.5707963267949;
  } else if ((X < -15.0)) {
    GDF = -1.5707963267949;
  } else {
    GDF = ((ATAN__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)EXP__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)X)) * 2.0) - 1.5707963267949);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return GDF;
}


// FUNCTION
REAL ACOSH(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL ACOSH = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return ACOSH;
  }
  ACOSH = LN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(SQRT__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)((X * X) - 1.0)) + X));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return ACOSH;
}


// FUNCTION
INT BINOM(
  BOOL EN, 
  BOOL *__ENO, 
  INT N, 
  INT K, 
  INT I)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT BINOM = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return BINOM;
  }
  if (((2 * K) > N)) {
    K = (N - K);
  };
  if ((K > N)) {
    goto __end;
  } else if (((K == 0) || (K == N))) {
    BINOM = 1;
  } else if ((K == 1)) {
    BINOM = N;
  } else {
    BINOM = N;
    N = (N + 1);
    for(I = 2; I <= K; I++) {
      BINOM = ((BINOM * (N - I)) / I);
    };
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return BINOM;
}


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


// FUNCTION
DINT FACT(
  BOOL EN, 
  BOOL *__ENO, 
  INT X)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  DINT FACT = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return FACT;
  }
  {
    INT __case_expression = X;
    if ((__case_expression == 0)) {
      FACT = __DINT_LITERAL(1);
    }
    else if ((__case_expression == 1)) {
      FACT = __DINT_LITERAL(1);
    }
    else if ((__case_expression == 2)) {
      FACT = __DINT_LITERAL(2);
    }
    else if ((__case_expression == 3)) {
      FACT = __DINT_LITERAL(6);
    }
    else if ((__case_expression == 4)) {
      FACT = __DINT_LITERAL(24);
    }
    else if ((__case_expression == 5)) {
      FACT = __DINT_LITERAL(120);
    }
    else if ((__case_expression == 6)) {
      FACT = __DINT_LITERAL(720);
    }
    else if ((__case_expression == 7)) {
      FACT = __DINT_LITERAL(5040);
    }
    else if ((__case_expression == 8)) {
      FACT = __DINT_LITERAL(40320);
    }
    else if ((__case_expression == 9)) {
      FACT = __DINT_LITERAL(362880);
    }
    else if ((__case_expression == 10)) {
      FACT = __DINT_LITERAL(3628800);
    }
    else if ((__case_expression == 11)) {
      FACT = __DINT_LITERAL(39916800);
    }
    else if ((__case_expression == 12)) {
      FACT = __DINT_LITERAL(479001600);
    }
    else {
      FACT = __DINT_LITERAL(-1);
    }
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return FACT;
}


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


