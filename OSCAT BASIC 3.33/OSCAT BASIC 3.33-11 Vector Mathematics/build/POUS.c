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
REAL V3_DPRO(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A, 
  VECTOR_3 B)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL V3_DPRO = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return V3_DPRO;
  }
  V3_DPRO = (((A.X * B.X) + (A.Y * B.Y)) + (A.Z * B.Z));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return V3_DPRO;
}


// FUNCTION
REAL V3_ABS(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL V3_ABS = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return V3_ABS;
  }
  V3_ABS = SQRT__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(((A.X * A.X) + (A.Y * A.Y)) + (A.Z * A.Z)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return V3_ABS;
}


// FUNCTION
REAL V3_ANG(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A, 
  VECTOR_3 B)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL _D = 0;
  REAL V3_ANG = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return V3_ANG;
  }
  _D = (V3_ABS(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (VECTOR_3)A) * V3_ABS(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (VECTOR_3)B));
  if ((_D > 0.0)) {
    V3_ANG = ACOS__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)LIMIT__REAL__REAL__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)-1.0,
        (REAL)(V3_DPRO(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (VECTOR_3)A,
          (VECTOR_3)B) / _D),
        (REAL)1.0));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return V3_ANG;
}


// FUNCTION
VECTOR_3 V3_ADD(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A, 
  VECTOR_3 B)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  VECTOR_3 V3_ADD = {0,0,0};

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return V3_ADD;
  }
  V3_ADD.X = (A.X + B.X);
  V3_ADD.Y = (A.Y + B.Y);
  V3_ADD.Z = (A.Z + B.Z);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return V3_ADD;
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
VECTOR_3 V3_REV(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  VECTOR_3 V3_REV = {0,0,0};

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return V3_REV;
  }
  V3_REV.X =  -(A.X);
  V3_REV.Y =  -(A.Y);
  V3_REV.Z =  -(A.Z);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return V3_REV;
}


// FUNCTION
VECTOR_3 V3_SMUL(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A, 
  REAL M)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  VECTOR_3 V3_SMUL = {0,0,0};

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return V3_SMUL;
  }
  V3_SMUL.X = (A.X * M);
  V3_SMUL.Y = (A.Y * M);
  V3_SMUL.Z = (A.Z * M);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return V3_SMUL;
}


// FUNCTION
VECTOR_3 V3_NORM(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL LA = 0;
  VECTOR_3 V3_NORM = {0,0,0};

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return V3_NORM;
  }
  LA = V3_ABS(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (VECTOR_3)A);
  if ((LA > 0.0)) {
    V3_NORM = V3_SMUL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (VECTOR_3)A,
      (REAL)(1.0 / LA));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return V3_NORM;
}


// FUNCTION
BOOL V3_NUL(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BOOL V3_NUL = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return V3_NUL;
  }
  V3_NUL = (((A.X == 0.0) && (A.Y == 0.0)) && (A.Z == 0.0));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return V3_NUL;
}


// FUNCTION
VECTOR_3 V3_XPRO(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A, 
  VECTOR_3 B)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  VECTOR_3 V3_XPRO = {0,0,0};

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return V3_XPRO;
  }
  V3_XPRO.X = ((A.Y * B.Z) - (A.Z * B.Y));
  V3_XPRO.Y = ((A.Z * B.X) - (A.X * B.Z));
  V3_XPRO.Z = ((A.X * B.Y) - (A.Y * B.X));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return V3_XPRO;
}


// FUNCTION
BOOL V3_PAR(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A, 
  VECTOR_3 B)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BOOL V3_PAR = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return V3_PAR;
  }
  V3_PAR = (V3_ABS(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (VECTOR_3)V3_XPRO(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (VECTOR_3)A,
      (VECTOR_3)B)) == 0.0);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return V3_PAR;
}


// FUNCTION
VECTOR_3 V3_SUB(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A, 
  VECTOR_3 B)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  VECTOR_3 V3_SUB = {0,0,0};

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return V3_SUB;
  }
  V3_SUB.X = (A.X - B.X);
  V3_SUB.Y = (A.Y - B.Y);
  V3_SUB.Z = (A.Z - B.Z);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return V3_SUB;
}


// FUNCTION
REAL V3_XANG(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL LA = 0;
  REAL V3_XANG = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return V3_XANG;
  }
  LA = V3_ABS(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (VECTOR_3)A);
  if ((LA > 0.0)) {
    V3_XANG = ACOS__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(A.X / LA));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return V3_XANG;
}


// FUNCTION
REAL V3_YANG(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL LA = 0;
  REAL V3_YANG = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return V3_YANG;
  }
  LA = V3_ABS(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (VECTOR_3)A);
  if ((LA > 0.0)) {
    V3_YANG = ACOS__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(A.Y / LA));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return V3_YANG;
}


// FUNCTION
REAL V3_ZANG(
  BOOL EN, 
  BOOL *__ENO, 
  VECTOR_3 A)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL LA = 0;
  REAL V3_ZANG = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return V3_ZANG;
  }
  LA = V3_ABS(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (VECTOR_3)A);
  if ((LA > 0.0)) {
    V3_ZANG = ACOS__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(A.Z / LA));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return V3_ZANG;
}


