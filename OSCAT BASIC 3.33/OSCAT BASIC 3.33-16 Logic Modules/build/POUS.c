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
BOOL PARITY(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  DWORD IN2 = 0;
  BOOL PARITY = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return PARITY;
  }
  IN2 = IN;
  while ((IN2 > __DWORD_LITERAL(0))) {
    PARITY = ((((PARITY && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) || (!PARITY && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)1)) || (!(PARITY && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) || (!PARITY && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)1)) && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)2)) || (!((PARITY && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) || (!PARITY && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)1)) || (!(PARITY && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) || (!PARITY && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)1)) && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)2)) && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)3)) || (!(((PARITY && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) || (!PARITY && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)1)) || (!(PARITY && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) || (!PARITY && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)1)) && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)2)) || (!((PARITY && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) || (!PARITY && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)1)) || (!(PARITY && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) || (!PARITY && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)1)) && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)2)) && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)3));
    IN2 = SHR__DWORD__DWORD__SINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (SINT)4);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return PARITY;
}


// FUNCTION
BYTE REVERSE(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BYTE REVERSE = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return REVERSE;
  }
  REVERSE = (((((SHL__BYTE__BYTE__SINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)IN,
    (SINT)7) | SHR__BYTE__BYTE__SINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)IN,
    (SINT)7)) | (ROR__BYTE__BYTE__SINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)IN,
    (SINT)3) & __BYTE_LITERAL(0x44))) | (ROL__BYTE__BYTE__SINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)IN,
    (SINT)3) & __BYTE_LITERAL(0x22))) | (SHL__BYTE__BYTE__SINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)IN,
    (SINT)1) & __BYTE_LITERAL(0x10))) | (SHR__BYTE__BYTE__SINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)IN,
    (SINT)1) & __BYTE_LITERAL(0x08)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return REVERSE;
}


// FUNCTION
WORD WORD_OF_BYTE(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE B0, 
  BYTE B1)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  WORD WORD_OF_BYTE = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return WORD_OF_BYTE;
  }
  WORD_OF_BYTE = (SHL__WORD__WORD__SINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (WORD)BYTE_TO_WORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)B1),
    (SINT)8) | BYTE_TO_WORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)B0));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return WORD_OF_BYTE;
}


// FUNCTION
BYTE GRAY_TO_BYTE(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BYTE GRAY_TO_BYTE = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return GRAY_TO_BYTE;
  }
  GRAY_TO_BYTE = (SHR__BYTE__BYTE__SINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)IN,
    (SINT)4) ^ IN);
  GRAY_TO_BYTE = (SHR__BYTE__BYTE__SINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)GRAY_TO_BYTE,
    (SINT)2) ^ GRAY_TO_BYTE);
  GRAY_TO_BYTE = (SHR__BYTE__BYTE__SINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)GRAY_TO_BYTE,
    (SINT)1) ^ GRAY_TO_BYTE);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return GRAY_TO_BYTE;
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


// FUNCTION
BYTE BYTE_OF_DWORD(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN, 
  BYTE N)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BYTE BYTE_OF_DWORD = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return BYTE_OF_DWORD;
  }
  BYTE_OF_DWORD = DWORD_TO_BYTE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)SHR__DWORD__DWORD__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN,
      (INT)_BYTE_TO_INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)SHL__BYTE__BYTE__SINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)N,
          (SINT)3))));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return BYTE_OF_DWORD;
}


// FUNCTION
WORD BIT_LOAD_W2(
  BOOL EN, 
  BOOL *__ENO, 
  WORD I, 
  BOOL _D, 
  INT P, 
  INT N)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  WORD BIT_LOAD_W2 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return BIT_LOAD_W2;
  }
  if (_D) {
    BIT_LOAD_W2 = ROL__WORD__WORD__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (WORD)(SHR__WORD__WORD__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__WORD_LITERAL(0xFFFF),
        (INT)(16 - N)) | ROR__WORD__WORD__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)I,
        (INT)P)),
      (INT)P);
  } else {
    BIT_LOAD_W2 = ROL__WORD__WORD__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (WORD)(SHL__WORD__WORD__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__WORD_LITERAL(0xFFFF),
        (INT)N) & ROR__WORD__WORD__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)I,
        (INT)P)),
      (INT)P);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return BIT_LOAD_W2;
}


// FUNCTION
BYTE INT_TO_BCDC(
  BOOL EN, 
  BOOL *__ENO, 
  INT IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BYTE INT_TO_BCDC = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return INT_TO_BCDC;
  }
  INT_TO_BCDC = (SHL__BYTE__BYTE__SINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)INT_TO_BYTE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)(IN / __INT_LITERAL(10))),
    (SINT)4) | INT_TO_BYTE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)((__INT_LITERAL(10) == 0)?0:(IN % __INT_LITERAL(10)))));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return INT_TO_BCDC;
}


// FUNCTION
WORD WORD_OF_DWORD(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN, 
  BYTE N)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  WORD WORD_OF_DWORD = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return WORD_OF_DWORD;
  }
  WORD_OF_DWORD = DWORD_TO_WORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)SHR__DWORD__DWORD__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN,
      (INT)_BYTE_TO_INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)SHL__BYTE__BYTE__SINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)N,
          (SINT)4))));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return WORD_OF_DWORD;
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


// FUNCTION
BOOL MUX_2(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL D0, 
  BOOL D1, 
  BOOL A0)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BOOL MUX_2 = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return MUX_2;
  }
  MUX_2 = SEL__BOOL__BOOL__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)A0,
    (BOOL)D0,
    (BOOL)D1);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return MUX_2;
}


// FUNCTION
BYTE BYTE_OF_BIT(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL B0, 
  BOOL B1, 
  BOOL B2, 
  BOOL B3, 
  BOOL B4, 
  BOOL B5, 
  BOOL B6, 
  BOOL B7)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BYTE BYTE_OF_BIT = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return BYTE_OF_BIT;
  }
  BYTE_OF_BIT = (SHL__BYTE__BYTE__SINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)(SHL__BYTE__BYTE__SINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)(SHL__BYTE__BYTE__SINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)(SHL__BYTE__BYTE__SINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)(SHL__BYTE__BYTE__SINT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (BYTE)(SHL__BYTE__BYTE__SINT(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (BYTE)(SHL__BYTE__BYTE__SINT(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (BYTE)BOOL_TO_BYTE(
                  (BOOL)__BOOL_LITERAL(TRUE),
                  NULL,
                  (BOOL)B7),
                (SINT)1) | BOOL_TO_BYTE(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (BOOL)B6)),
              (SINT)1) | BOOL_TO_BYTE(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (BOOL)B5)),
            (SINT)1) | BOOL_TO_BYTE(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (BOOL)B4)),
          (SINT)1) | BOOL_TO_BYTE(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BOOL)B3)),
        (SINT)1) | BOOL_TO_BYTE(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BOOL)B2)),
      (SINT)1) | BOOL_TO_BYTE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)B1)),
    (SINT)1) | BOOL_TO_BYTE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)B0));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return BYTE_OF_BIT;
}


// FUNCTION
BOOL MUX_4(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL D0, 
  BOOL D1, 
  BOOL D2, 
  BOOL D3, 
  BOOL A0, 
  BOOL A1)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BOOL MUX_4 = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return MUX_4;
  }
  if (A1) {
    MUX_4 = SEL__BOOL__BOOL__BOOL__BOOL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)A0,
      (BOOL)D2,
      (BOOL)D3);
  } else {
    MUX_4 = SEL__BOOL__BOOL__BOOL__BOOL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)A0,
      (BOOL)D0,
      (BOOL)D1);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return MUX_4;
}


// FUNCTION
WORD BIT_LOAD_W(
  BOOL EN, 
  BOOL *__ENO, 
  WORD IN, 
  BOOL VAL, 
  INT POS)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  WORD BIT_LOAD_W = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return BIT_LOAD_W;
  }
  if (VAL) {
    BIT_LOAD_W = (IN | SHL__WORD__WORD__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (WORD)__WORD_LITERAL(1),
      (INT)POS));
  } else {
    BIT_LOAD_W = (IN & ~(SHL__WORD__WORD__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (WORD)__WORD_LITERAL(1),
      (INT)POS)));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return BIT_LOAD_W;
}


// FUNCTION
BOOL DEC_2(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL DI, 
  BOOL A, 
  BOOL *__Q0, 
  BOOL *__Q1)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BOOL Q0 = __BOOL_LITERAL(FALSE);
  BOOL Q1 = __BOOL_LITERAL(FALSE);
  BOOL DEC_2 = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DEC_2;
  }
  Q0 = (DI && !(A));
  Q1 = (DI && A);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  if (__Q0 != NULL) {
    *__Q0 = Q0;
  }
  if (__Q1 != NULL) {
    *__Q1 = Q1;
  }
  return DEC_2;
}


// FUNCTION
BOOL DEC_4(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL DI, 
  BOOL A0, 
  BOOL A1, 
  BOOL *__Q0, 
  BOOL *__Q1, 
  BOOL *__Q2, 
  BOOL *__Q3)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BOOL Q0 = __BOOL_LITERAL(FALSE);
  BOOL Q1 = __BOOL_LITERAL(FALSE);
  BOOL Q2 = __BOOL_LITERAL(FALSE);
  BOOL Q3 = __BOOL_LITERAL(FALSE);
  BOOL DEC_4 = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DEC_4;
  }
  Q0 = ((DI && !(A0)) && !(A1));
  Q1 = ((DI && A0) && !(A1));
  Q2 = ((DI && !(A0)) && A1);
  Q3 = ((DI && A0) && A1);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  if (__Q0 != NULL) {
    *__Q0 = Q0;
  }
  if (__Q1 != NULL) {
    *__Q1 = Q1;
  }
  if (__Q2 != NULL) {
    *__Q2 = Q2;
  }
  if (__Q3 != NULL) {
    *__Q3 = Q3;
  }
  return DEC_4;
}


// FUNCTION
DWORD SHR1(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN, 
  INT N)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  DWORD SHR1 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SHR1;
  }
  SHR1 = (SHL__DWORD__DWORD__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)__DWORD_LITERAL(0xFFFFFFFF),
    (INT)(32 - N)) | SHR__DWORD__DWORD__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)IN,
    (INT)N));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SHR1;
}


// FUNCTION
BOOL DEC_8(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL DI, 
  BOOL A0, 
  BOOL A1, 
  BOOL A2, 
  BOOL *__Q0, 
  BOOL *__Q1, 
  BOOL *__Q2, 
  BOOL *__Q3, 
  BOOL *__Q4, 
  BOOL *__Q5, 
  BOOL *__Q6, 
  BOOL *__Q7)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BOOL Q0 = __BOOL_LITERAL(FALSE);
  BOOL Q1 = __BOOL_LITERAL(FALSE);
  BOOL Q2 = __BOOL_LITERAL(FALSE);
  BOOL Q3 = __BOOL_LITERAL(FALSE);
  BOOL Q4 = __BOOL_LITERAL(FALSE);
  BOOL Q5 = __BOOL_LITERAL(FALSE);
  BOOL Q6 = __BOOL_LITERAL(FALSE);
  BOOL Q7 = __BOOL_LITERAL(FALSE);
  BYTE X = 0;
  BOOL DEC_8 = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DEC_8;
  }
  X = BIT_LOAD_B(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)X,
    (BOOL)A0,
    (INT)0);
  X = BIT_LOAD_B(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)X,
    (BOOL)A1,
    (INT)1);
  X = BIT_LOAD_B(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)X,
    (BOOL)A2,
    (INT)2);
  Q0 = __BOOL_LITERAL(FALSE);
  Q1 = __BOOL_LITERAL(FALSE);
  Q2 = __BOOL_LITERAL(FALSE);
  Q3 = __BOOL_LITERAL(FALSE);
  Q4 = __BOOL_LITERAL(FALSE);
  Q5 = __BOOL_LITERAL(FALSE);
  Q6 = __BOOL_LITERAL(FALSE);
  Q7 = __BOOL_LITERAL(FALSE);
  {
    INT __case_expression = _BYTE_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)X);
    if ((__case_expression == 0)) {
      Q0 = DI;
    }
    else if ((__case_expression == 1)) {
      Q1 = DI;
    }
    else if ((__case_expression == 2)) {
      Q2 = DI;
    }
    else if ((__case_expression == 3)) {
      Q3 = DI;
    }
    else if ((__case_expression == 4)) {
      Q4 = DI;
    }
    else if ((__case_expression == 5)) {
      Q5 = DI;
    }
    else if ((__case_expression == 6)) {
      Q6 = DI;
    }
    else if ((__case_expression == 7)) {
      Q7 = DI;
    }
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  if (__Q0 != NULL) {
    *__Q0 = Q0;
  }
  if (__Q1 != NULL) {
    *__Q1 = Q1;
  }
  if (__Q2 != NULL) {
    *__Q2 = Q2;
  }
  if (__Q3 != NULL) {
    *__Q3 = Q3;
  }
  if (__Q4 != NULL) {
    *__Q4 = Q4;
  }
  if (__Q5 != NULL) {
    *__Q5 = Q5;
  }
  if (__Q6 != NULL) {
    *__Q6 = Q6;
  }
  if (__Q7 != NULL) {
    *__Q7 = Q7;
  }
  return DEC_8;
}


// FUNCTION
DWORD DWORD_OF_BYTE(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE B0, 
  BYTE B1, 
  BYTE B2, 
  BYTE B3)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  DWORD DWORD_OF_BYTE = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DWORD_OF_BYTE;
  }
  DWORD_OF_BYTE = (SHL__DWORD__DWORD__SINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)(SHL__DWORD__DWORD__SINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)(SHL__DWORD__DWORD__SINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)BYTE_TO_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)B3),
        (SINT)8) | BYTE_TO_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)B2)),
      (SINT)8) | BYTE_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)B1)),
    (SINT)8) | BYTE_TO_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)B0));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return DWORD_OF_BYTE;
}


// FUNCTION
BOOL BYTE_TO_BITS(
  BOOL EN, 
  BOOL *__ENO, 
  BOOL *__B0, 
  BOOL *__B1, 
  BOOL *__B2, 
  BOOL *__B3, 
  BOOL *__B4, 
  BOOL *__B5, 
  BOOL *__B6, 
  BOOL *__B7)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BYTE IN = 0;
  BOOL B0 = __BOOL_LITERAL(FALSE);
  BOOL B1 = __BOOL_LITERAL(FALSE);
  BOOL B2 = __BOOL_LITERAL(FALSE);
  BOOL B3 = __BOOL_LITERAL(FALSE);
  BOOL B4 = __BOOL_LITERAL(FALSE);
  BOOL B5 = __BOOL_LITERAL(FALSE);
  BOOL B6 = __BOOL_LITERAL(FALSE);
  BOOL B7 = __BOOL_LITERAL(FALSE);
  BOOL BYTE_TO_BITS = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return BYTE_TO_BITS;
  }
  B0 = BIT_OF_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)BYTE_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)IN),
    (INT)0);
  B1 = BIT_OF_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)BYTE_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)IN),
    (INT)1);
  B2 = BIT_OF_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)BYTE_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)IN),
    (INT)2);
  B3 = BIT_OF_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)BYTE_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)IN),
    (INT)3);
  B4 = BIT_OF_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)BYTE_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)IN),
    (INT)4);
  B5 = BIT_OF_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)BYTE_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)IN),
    (INT)5);
  B6 = BIT_OF_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)BYTE_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)IN),
    (INT)6);
  B7 = BIT_OF_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)BYTE_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)IN),
    (INT)7);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  if (__B0 != NULL) {
    *__B0 = B0;
  }
  if (__B1 != NULL) {
    *__B1 = B1;
  }
  if (__B2 != NULL) {
    *__B2 = B2;
  }
  if (__B3 != NULL) {
    *__B3 = B3;
  }
  if (__B4 != NULL) {
    *__B4 = B4;
  }
  if (__B5 != NULL) {
    *__B5 = B5;
  }
  if (__B6 != NULL) {
    *__B6 = B6;
  }
  if (__B7 != NULL) {
    *__B7 = B7;
  }
  return BYTE_TO_BITS;
}


// FUNCTION
BYTE BYTE_TO_GRAY(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BYTE BYTE_TO_GRAY = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return BYTE_TO_GRAY;
  }
  BYTE_TO_GRAY = (IN ^ SHR__BYTE__BYTE__SINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)IN,
    (SINT)1));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return BYTE_TO_GRAY;
}


// FUNCTION
DWORD BIT_TOGGLE_DW(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN, 
  INT POS)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  DWORD BIT_TOGGLE_DW = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return BIT_TOGGLE_DW;
  }
  BIT_TOGGLE_DW = (SHL__DWORD__DWORD__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)__DWORD_LITERAL(1),
    (INT)POS) ^ IN);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return BIT_TOGGLE_DW;
}


// FUNCTION
DWORD SWAP_BYTE2(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  DWORD SWAP_BYTE2 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SWAP_BYTE2;
  }
  SWAP_BYTE2 = ((ROR__DWORD__DWORD__SINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)IN,
    (SINT)8) & __DWORD_LITERAL(0xFF00FF00)) | (ROL__DWORD__DWORD__SINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)IN,
    (SINT)8) & __DWORD_LITERAL(0xFF00FF)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SWAP_BYTE2;
}


// FUNCTION
DWORD REFLECT(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD DI, 
  INT L)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT I = 0;
  DWORD _D = 0;
  DWORD REFLECT = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return REFLECT;
  }
  _D = DI;
  for(I = 1; I <= L; I++) {
    REFLECT = (SHL__DWORD__DWORD__SINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)REFLECT,
      (SINT)1) | BOOL_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)((_D & __DWORD_LITERAL(0x01)) > __DWORD_LITERAL(0))));
    _D = SHR__DWORD__DWORD__SINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)_D,
      (SINT)1);
  };
  REFLECT = (REFLECT | SHL__DWORD__DWORD__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)_D,
    (INT)L));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return REFLECT;
}


void CRC_GEN_init__(CRC_GEN *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const __ARRAY_OF_BYTE_250 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    __SET_VAR(data__->,PT,,temp);
  }
  __INIT_VAR(data__->SIZE,0,retain)
  __INIT_VAR(data__->PL,0,retain)
  __INIT_VAR(data__->PN,0,retain)
  __INIT_VAR(data__->INIT,0,retain)
  __INIT_VAR(data__->REV_IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REV_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->XOR_OUT,0,retain)
  __INIT_VAR(data__->_CRC_GEN,0,retain)
  __INIT_VAR(data__->POS,0,retain)
  __INIT_VAR(data__->SHIFT,0,retain)
  __INIT_VAR(data__->BITS,0,retain)
  __INIT_VAR(data__->DX,0,retain)
}

// Code part
void CRC_GEN_body__(CRC_GEN *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,SHIFT,,(32 - UINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->PL,))));
  __SET_VAR(data__->,PN,,SHL__DWORD__DWORD__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)__GET_VAR(data__->PN,),
    (INT)__GET_VAR(data__->SHIFT,)));
  for(__GET_VAR(data__->POS,) = 0; __GET_VAR(data__->POS,) <= 3; __GET_VAR(data__->POS,)++) {
    if (__GET_VAR(data__->REV_IN,)) {
      __SET_VAR(data__->,_CRC_GEN,,(SHL__DWORD__DWORD__SINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)__GET_VAR(data__->_CRC_GEN,),
        (SINT)8) | BYTE_TO_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)REVERSE(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->PT,.table[(__GET_VAR(data__->POS,)) - (0)])))));
    } else {
      __SET_VAR(data__->,_CRC_GEN,,(SHL__DWORD__DWORD__SINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)__GET_VAR(data__->_CRC_GEN,),
        (SINT)8) | BYTE_TO_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->PT,.table[(__GET_VAR(data__->POS,)) - (0)]))));
    };
  };
  __SET_VAR(data__->,POS,,4);
  __SET_VAR(data__->,_CRC_GEN,,(__GET_VAR(data__->_CRC_GEN,) ^ SHL__DWORD__DWORD__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)__GET_VAR(data__->INIT,),
    (INT)__GET_VAR(data__->SHIFT,))));
  while ((__GET_VAR(data__->POS,) < UINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->SIZE,)))) {
    if (__GET_VAR(data__->REV_IN,)) {
      __SET_VAR(data__->,DX,,REVERSE(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->PT,.table[(__GET_VAR(data__->POS,)) - (0)])));
    } else {
      __SET_VAR(data__->,DX,,__GET_VAR(data__->PT,.table[(__GET_VAR(data__->POS,)) - (0)]));
    };
    __SET_VAR(data__->,POS,,(__GET_VAR(data__->POS,) + 1));
    for(__GET_VAR(data__->BITS,) = 0; __GET_VAR(data__->BITS,) <= 7; __GET_VAR(data__->BITS,)++) {
      if (((__GET_VAR(data__->_CRC_GEN,) & __DWORD_LITERAL(0x80000000)) > __DWORD_LITERAL(0))) {
        __SET_VAR(data__->,_CRC_GEN,,((SHL__DWORD__DWORD__SINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)__GET_VAR(data__->_CRC_GEN,),
          (SINT)1) | BOOL_TO_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BOOL)((__GET_VAR(data__->DX,) & __BYTE_LITERAL(0x80)) > __BYTE_LITERAL(0)))) ^ __GET_VAR(data__->PN,)));
      } else {
        __SET_VAR(data__->,_CRC_GEN,,(SHL__DWORD__DWORD__SINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)__GET_VAR(data__->_CRC_GEN,),
          (SINT)1) | BOOL_TO_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BOOL)((__GET_VAR(data__->DX,) & __BYTE_LITERAL(0x80)) > __BYTE_LITERAL(0)))));
      };
      __SET_VAR(data__->,DX,,SHL__BYTE__BYTE__SINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->DX,),
        (SINT)1));
    };
  };
  for(__GET_VAR(data__->BITS,) = 0; __GET_VAR(data__->BITS,) <= 31; __GET_VAR(data__->BITS,)++) {
    if (((__GET_VAR(data__->_CRC_GEN,) & __DWORD_LITERAL(0x80000000)) > __DWORD_LITERAL(0))) {
      __SET_VAR(data__->,_CRC_GEN,,((SHL__DWORD__DWORD__SINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)__GET_VAR(data__->_CRC_GEN,),
        (SINT)1) | BOOL_TO_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BOOL)((__GET_VAR(data__->DX,) & __BYTE_LITERAL(0x80)) > __BYTE_LITERAL(0)))) ^ __GET_VAR(data__->PN,)));
    } else {
      __SET_VAR(data__->,_CRC_GEN,,(SHL__DWORD__DWORD__SINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)__GET_VAR(data__->_CRC_GEN,),
        (SINT)1) | BOOL_TO_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BOOL)((__GET_VAR(data__->DX,) & __BYTE_LITERAL(0x80)) > __BYTE_LITERAL(0)))));
    };
  };
  __SET_VAR(data__->,_CRC_GEN,,(SHR__DWORD__DWORD__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)__GET_VAR(data__->_CRC_GEN,),
    (INT)__GET_VAR(data__->SHIFT,)) ^ __GET_VAR(data__->XOR_OUT,)));
  if (__GET_VAR(data__->REV_OUT,)) {
    __SET_VAR(data__->,_CRC_GEN,,REFLECT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)__GET_VAR(data__->_CRC_GEN,),
      (INT)UINT_TO_INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UINT)__GET_VAR(data__->PL,))));
  };

  goto __end;

__end:
  return;
} // CRC_GEN_body__() 





void MATRIX_init__(MATRIX *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->X2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->X3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->X4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->X5,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RELEASE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,0,retain)
  __INIT_VAR(data__->_TP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Y1,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->Y2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Y3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Y4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LINE,0,retain)
  {
    static const __ARRAY_OF_BYTE_4 temp = {{0,0,0,0}};
    __SET_VAR(data__->,X,,temp);
  }
  {
    static const __ARRAY_OF_BYTE_4 temp = {{0,0,0,0}};
    __SET_VAR(data__->,L,,temp);
  }
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->TEMP,0,retain)
  __INIT_VAR(data__->TEMP2,0,retain)
  __INIT_VAR(data__->L_TEMP,0,retain)
  __INIT_VAR(data__->TEMP_BIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN_TEMP,0,retain)
}

// Code part
void MATRIX_body__(MATRIX *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_TP,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,CODE,,__BYTE_LITERAL(0));
  __SET_VAR(data__->,IN_TEMP,,_BYTE_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)__GET_VAR(data__->LINE,)));
  __SET_VAR(data__->,TEMP,,__GET_VAR(data__->X,.table[(__GET_VAR(data__->IN_TEMP,)) - (0)]));
  __SET_VAR(data__->,TEMP,,BIT_LOAD_B(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)__GET_VAR(data__->TEMP,),
    (BOOL)__GET_VAR(data__->X1,),
    (INT)0));
  __SET_VAR(data__->,TEMP,,BIT_LOAD_B(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)__GET_VAR(data__->TEMP,),
    (BOOL)__GET_VAR(data__->X2,),
    (INT)1));
  __SET_VAR(data__->,TEMP,,BIT_LOAD_B(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)__GET_VAR(data__->TEMP,),
    (BOOL)__GET_VAR(data__->X3,),
    (INT)2));
  __SET_VAR(data__->,TEMP,,BIT_LOAD_B(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)__GET_VAR(data__->TEMP,),
    (BOOL)__GET_VAR(data__->X4,),
    (INT)3));
  __SET_VAR(data__->,TEMP,,BIT_LOAD_B(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)__GET_VAR(data__->TEMP,),
    (BOOL)__GET_VAR(data__->X5,),
    (INT)4));
  __SET_VAR(data__->,X,.table[(__GET_VAR(data__->IN_TEMP,)) - (0)],__GET_VAR(data__->TEMP,));
  for(__GET_VAR(data__->I,) = 0; __GET_VAR(data__->I,) <= 3; __GET_VAR(data__->I,)++) {
    if ((__GET_VAR(data__->X,.table[(__GET_VAR(data__->I,)) - (0)]) != __GET_VAR(data__->L,.table[(__GET_VAR(data__->I,)) - (0)]))) {
      __SET_VAR(data__->,TEMP,,(__GET_VAR(data__->X,.table[(__GET_VAR(data__->I,)) - (0)]) ^ __GET_VAR(data__->L,.table[(__GET_VAR(data__->I,)) - (0)])));
      __SET_VAR(data__->,TEMP2,,__GET_VAR(data__->X,.table[(__GET_VAR(data__->I,)) - (0)]));
      __SET_VAR(data__->,L_TEMP,,__GET_VAR(data__->L,.table[(__GET_VAR(data__->I,)) - (0)]));
      if (BIT_OF_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)BYTE_TO_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->TEMP,)),
        (INT)0)) {
        __SET_VAR(data__->,CODE,,__BYTE_LITERAL(1));
        __SET_VAR(data__->,TEMP_BIT,,BIT_OF_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)BYTE_TO_DWORD(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (BYTE)__GET_VAR(data__->TEMP2,)),
          (INT)0));
        __SET_VAR(data__->,CODE,,BIT_LOAD_B(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->CODE,),
          (BOOL)__GET_VAR(data__->TEMP_BIT,),
          (INT)7));
        __SET_VAR(data__->,L_TEMP,,BIT_LOAD_B(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->L_TEMP,),
          (BOOL)__GET_VAR(data__->TEMP_BIT,),
          (INT)0));
      } else if (BIT_OF_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)BYTE_TO_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->TEMP,)),
        (INT)1)) {
        __SET_VAR(data__->,CODE,,__BYTE_LITERAL(2));
        __SET_VAR(data__->,TEMP_BIT,,BIT_OF_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)BYTE_TO_DWORD(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (BYTE)__GET_VAR(data__->TEMP2,)),
          (INT)1));
        __SET_VAR(data__->,CODE,,BIT_LOAD_B(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->CODE,),
          (BOOL)__GET_VAR(data__->TEMP_BIT,),
          (INT)7));
        __SET_VAR(data__->,L_TEMP,,BIT_LOAD_B(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->L_TEMP,),
          (BOOL)__GET_VAR(data__->TEMP_BIT,),
          (INT)1));
      } else if (BIT_OF_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)BYTE_TO_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->TEMP,)),
        (INT)2)) {
        __SET_VAR(data__->,CODE,,__BYTE_LITERAL(3));
        __SET_VAR(data__->,TEMP_BIT,,BIT_OF_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)BYTE_TO_DWORD(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (BYTE)__GET_VAR(data__->TEMP2,)),
          (INT)2));
        __SET_VAR(data__->,CODE,,BIT_LOAD_B(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->CODE,),
          (BOOL)__GET_VAR(data__->TEMP_BIT,),
          (INT)7));
        __SET_VAR(data__->,L_TEMP,,BIT_LOAD_B(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->L_TEMP,),
          (BOOL)__GET_VAR(data__->TEMP_BIT,),
          (INT)2));
      } else if (BIT_OF_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)BYTE_TO_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->TEMP,)),
        (INT)3)) {
        __SET_VAR(data__->,CODE,,__BYTE_LITERAL(4));
        __SET_VAR(data__->,TEMP_BIT,,BIT_OF_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)BYTE_TO_DWORD(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (BYTE)__GET_VAR(data__->TEMP2,)),
          (INT)3));
        __SET_VAR(data__->,CODE,,BIT_LOAD_B(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->CODE,),
          (BOOL)__GET_VAR(data__->TEMP_BIT,),
          (INT)7));
        __SET_VAR(data__->,L_TEMP,,BIT_LOAD_B(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->L_TEMP,),
          (BOOL)__GET_VAR(data__->TEMP_BIT,),
          (INT)3));
      } else if (BIT_OF_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)BYTE_TO_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->TEMP,)),
        (INT)4)) {
        __SET_VAR(data__->,CODE,,__BYTE_LITERAL(5));
        __SET_VAR(data__->,TEMP_BIT,,BIT_OF_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)BYTE_TO_DWORD(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (BYTE)__GET_VAR(data__->TEMP2,)),
          (INT)4));
        __SET_VAR(data__->,CODE,,BIT_LOAD_B(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->CODE,),
          (BOOL)__GET_VAR(data__->TEMP_BIT,),
          (INT)7));
        __SET_VAR(data__->,L_TEMP,,BIT_LOAD_B(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->L_TEMP,),
          (BOOL)__GET_VAR(data__->TEMP_BIT,),
          (INT)4));
      };
      __SET_VAR(data__->,L,.table[(__GET_VAR(data__->I,)) - (0)],__GET_VAR(data__->L_TEMP,));
      __SET_VAR(data__->,_TP,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,CODE,,((__GET_VAR(data__->CODE,) & __BYTE_LITERAL(0x8F)) | SHL__BYTE__BYTE__SINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)(__GET_VAR(data__->LINE,) & __BYTE_LITERAL(0x07)),
        (SINT)4)));
      if ((!(__GET_VAR(data__->RELEASE,)) && (__GET_VAR(data__->CODE,) < __BYTE_LITERAL(127)))) {
        __SET_VAR(data__->,CODE,,__BYTE_LITERAL(0));
        __SET_VAR(data__->,_TP,,__BOOL_LITERAL(FALSE));
      };
      break;
    };
  };
  __SET_VAR(data__->,LINE,,(INT_TO_BYTE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)(_BYTE_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->LINE,)) + 1)) & __BYTE_LITERAL(0x03)));
  __SET_VAR(data__->,TEMP,,SHL__BYTE__BYTE__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)__BYTE_LITERAL(1),
    (INT)_BYTE_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->LINE,))));
  __SET_VAR(data__->,Y1,,BIT_OF_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)BYTE_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->TEMP,)),
    (INT)0));
  __SET_VAR(data__->,Y2,,BIT_OF_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)BYTE_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->TEMP,)),
    (INT)1));
  __SET_VAR(data__->,Y3,,BIT_OF_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)BYTE_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->TEMP,)),
    (INT)2));
  __SET_VAR(data__->,Y4,,BIT_OF_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)BYTE_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->TEMP,)),
    (INT)3));

  goto __end;

__end:
  return;
} // MATRIX_body__() 





// FUNCTION
BOOL CHECK_PARITY(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN, 
  BOOL P)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  DWORD IN2 = 0;
  BOOL CHECK_PARITY = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return CHECK_PARITY;
  }
  IN2 = IN;
  CHECK_PARITY = !(P);
  while ((IN2 > __DWORD_LITERAL(0))) {
    CHECK_PARITY = ((((CHECK_PARITY && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) || (!CHECK_PARITY && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)1)) || (!(CHECK_PARITY && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) || (!CHECK_PARITY && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)1)) && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)2)) || (!((CHECK_PARITY && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) || (!CHECK_PARITY && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)1)) || (!(CHECK_PARITY && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) || (!CHECK_PARITY && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)1)) && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)2)) && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)3)) || (!(((CHECK_PARITY && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) || (!CHECK_PARITY && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)1)) || (!(CHECK_PARITY && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) || (!CHECK_PARITY && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)1)) && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)2)) || (!((CHECK_PARITY && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) || (!CHECK_PARITY && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)1)) || (!(CHECK_PARITY && !BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) || (!CHECK_PARITY && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)0)) && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)1)) && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)2)) && BIT_OF_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (INT)3));
    IN2 = SHR__DWORD__DWORD__SINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)IN2,
      (SINT)4);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return CHECK_PARITY;
}


// FUNCTION
DWORD DWORD_OF_WORD(
  BOOL EN, 
  BOOL *__ENO, 
  WORD W0, 
  WORD W1)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  DWORD DWORD_OF_WORD = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DWORD_OF_WORD;
  }
  DWORD_OF_WORD = (SHL__DWORD__DWORD__SINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)WORD_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (WORD)W1),
    (SINT)16) | WORD_TO_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (WORD)W0));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return DWORD_OF_WORD;
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


// FUNCTION
WORD BIT_TOGGLE_W(
  BOOL EN, 
  BOOL *__ENO, 
  WORD IN, 
  INT POS)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  WORD BIT_TOGGLE_W = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return BIT_TOGGLE_W;
  }
  BIT_TOGGLE_W = (SHL__WORD__WORD__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (WORD)__WORD_LITERAL(1),
    (INT)POS) ^ IN);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return BIT_TOGGLE_W;
}


// FUNCTION
DWORD SHL1(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD IN, 
  INT N)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  DWORD SHL1 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SHL1;
  }
  SHL1 = (SHR__DWORD__DWORD__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)__DWORD_LITERAL(0xFFFFFFFF),
    (INT)(32 - N)) | SHL__DWORD__DWORD__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)IN,
    (INT)N));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SHL1;
}


// FUNCTION
WORD SWAP_BYTE(
  BOOL EN, 
  BOOL *__ENO, 
  WORD IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  WORD SWAP_BYTE = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SWAP_BYTE;
  }
  SWAP_BYTE = ROL__WORD__WORD__SINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (WORD)IN,
    (SINT)8);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SWAP_BYTE;
}


// FUNCTION
BYTE BIT_LOAD_B2(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE I, 
  BOOL _D, 
  INT P, 
  INT N)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BYTE BIT_LOAD_B2 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return BIT_LOAD_B2;
  }
  if (_D) {
    BIT_LOAD_B2 = ROL__BYTE__BYTE__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)(SHR__BYTE__BYTE__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__BYTE_LITERAL(255),
        (INT)(8 - N)) | ROR__BYTE__BYTE__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)I,
        (INT)P)),
      (INT)P);
  } else {
    BIT_LOAD_B2 = ROL__BYTE__BYTE__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)(SHL__BYTE__BYTE__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__BYTE_LITERAL(255),
        (INT)N) & ROR__BYTE__BYTE__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)I,
        (INT)P)),
      (INT)P);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return BIT_LOAD_B2;
}


// FUNCTION
INT BCDC_TO_INT(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT BCDC_TO_INT = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return BCDC_TO_INT;
  }
  BCDC_TO_INT = (_BYTE_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)(IN & __BYTE_LITERAL(0xF))) + (_BYTE_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)SHR__BYTE__BYTE__SINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)IN,
      (SINT)4)) * 10));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return BCDC_TO_INT;
}


// FUNCTION
DWORD BIT_LOAD_DW2(
  BOOL EN, 
  BOOL *__ENO, 
  DWORD I, 
  BOOL _D, 
  INT P, 
  INT N)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  DWORD BIT_LOAD_DW2 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return BIT_LOAD_DW2;
  }
  if (_D) {
    BIT_LOAD_DW2 = ROL__DWORD__DWORD__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)(SHR__DWORD__DWORD__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)__DWORD_LITERAL(0xFFFFFFFF),
        (INT)(32 - N)) | ROR__DWORD__DWORD__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)I,
        (INT)P)),
      (INT)P);
  } else {
    BIT_LOAD_DW2 = ROL__DWORD__DWORD__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)(SHL__DWORD__DWORD__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)__DWORD_LITERAL(0xFFFFFFFF),
        (INT)N) & ROR__DWORD__DWORD__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)I,
        (INT)P)),
      (INT)P);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return BIT_LOAD_DW2;
}


// FUNCTION
BYTE BIT_TOGGLE_B(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE IN, 
  INT POS)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BYTE BIT_TOGGLE_B = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return BIT_TOGGLE_B;
  }
  BIT_TOGGLE_B = (SHL__BYTE__BYTE__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)__BYTE_LITERAL(1),
    (INT)POS) ^ IN);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return BIT_TOGGLE_B;
}


