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





void SHR_4UDE_init__(SHR_4UDE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->SET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->D0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->D3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CLK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q3,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->TRIG,retain);
}

// Code part
void SHR_4UDE_body__(SHR_4UDE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->TRIG.,CLK,,__GET_VAR(data__->CLK,));
  R_TRIG_body__(&data__->TRIG);
  if ((__GET_VAR(data__->SET,) || __GET_VAR(data__->RST,))) {
    __SET_VAR(data__->,Q0,,!(__GET_VAR(data__->RST,)));
    __SET_VAR(data__->,Q1,,__GET_VAR(data__->Q0,));
    __SET_VAR(data__->,Q2,,__GET_VAR(data__->Q0,));
    __SET_VAR(data__->,Q3,,__GET_VAR(data__->Q0,));
  } else if (__GET_VAR(data__->TRIG.Q,)) {
    if (__GET_VAR(data__->DN,)) {
      __SET_VAR(data__->,Q0,,__GET_VAR(data__->Q1,));
      __SET_VAR(data__->,Q1,,__GET_VAR(data__->Q2,));
      __SET_VAR(data__->,Q2,,__GET_VAR(data__->Q3,));
      __SET_VAR(data__->,Q3,,__GET_VAR(data__->D3,));
    } else {
      __SET_VAR(data__->,Q3,,__GET_VAR(data__->Q2,));
      __SET_VAR(data__->,Q2,,__GET_VAR(data__->Q1,));
      __SET_VAR(data__->,Q1,,__GET_VAR(data__->Q0,));
      __SET_VAR(data__->,Q0,,__GET_VAR(data__->D0,));
    };
  };

  goto __end;

__end:
  return;
} // SHR_4UDE_body__() 





void SHR_4E_init__(SHR_4E *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->SET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->D0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CLK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q3,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->TRIG,retain);
}

// Code part
void SHR_4E_body__(SHR_4E *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->SET,) || __GET_VAR(data__->RST,))) {
    __SET_VAR(data__->,Q0,,!(__GET_VAR(data__->RST,)));
    __SET_VAR(data__->,Q1,,__GET_VAR(data__->Q0,));
    __SET_VAR(data__->,Q2,,__GET_VAR(data__->Q0,));
    __SET_VAR(data__->,Q3,,__GET_VAR(data__->Q0,));
  } else if (__GET_VAR(data__->TRIG.Q,)) {
    __SET_VAR(data__->,Q3,,__GET_VAR(data__->Q2,));
    __SET_VAR(data__->,Q2,,__GET_VAR(data__->Q1,));
    __SET_VAR(data__->,Q1,,__GET_VAR(data__->Q0,));
    __SET_VAR(data__->,Q0,,__GET_VAR(data__->D0,));
  };

  goto __end;

__end:
  return;
} // SHR_4E_body__() 





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


void COUNT_DR_init__(COUNT_DR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->SET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->UP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_STEP,1,retain)
  __INIT_VAR(data__->MX,0xFFFFFFFF,retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CNT,0,retain)
  __INIT_VAR(data__->CNT2,0,retain)
  __INIT_VAR(data__->STEP2,0,retain)
  __INIT_VAR(data__->MX2,0,retain)
  __INIT_VAR(data__->LAST_UP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LAST_DN,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void COUNT_DR_body__(COUNT_DR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,STEP2,,DWORD_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)__GET_VAR(data__->_STEP,)));
  __SET_VAR(data__->,MX2,,DWORD_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)__GET_VAR(data__->MX,)));
  __SET_VAR(data__->,CNT2,,DWORD_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)__GET_VAR(data__->CNT,)));
  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,CNT2,,__UDINT_LITERAL(0));
  } else if (__GET_VAR(data__->SET,)) {
    __SET_VAR(data__->,CNT2,,LIMIT__UDINT__UDINT__UDINT__UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)__UDINT_LITERAL(0),
      (UDINT)DWORD_TO_UDINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)__GET_VAR(data__->IN,)),
      (UDINT)__GET_VAR(data__->MX2,)));
  } else if ((__GET_VAR(data__->UP,) && !(__GET_VAR(data__->LAST_UP,)))) {
    if ((__GET_VAR(data__->STEP2,) > (__GET_VAR(data__->MX2,) - __GET_VAR(data__->CNT2,)))) {
      __SET_VAR(data__->,CNT2,,(((__GET_VAR(data__->CNT2,) - __GET_VAR(data__->MX2,)) + __GET_VAR(data__->STEP2,)) - __UDINT_LITERAL(1)));
    } else {
      __SET_VAR(data__->,CNT2,,(__GET_VAR(data__->CNT2,) + __GET_VAR(data__->STEP2,)));
    };
  } else if ((__GET_VAR(data__->DN,) && !(__GET_VAR(data__->LAST_DN,)))) {
    if ((__GET_VAR(data__->STEP2,) > __GET_VAR(data__->CNT2,))) {
      __SET_VAR(data__->,CNT2,,(((__GET_VAR(data__->CNT2,) - __GET_VAR(data__->STEP2,)) + __GET_VAR(data__->MX2,)) + __UDINT_LITERAL(1)));
    } else {
      __SET_VAR(data__->,CNT2,,(__GET_VAR(data__->CNT2,) - __GET_VAR(data__->STEP2,)));
    };
  };
  __SET_VAR(data__->,LAST_UP,,__GET_VAR(data__->UP,));
  __SET_VAR(data__->,LAST_DN,,__GET_VAR(data__->DN,));
  __SET_VAR(data__->,CNT,,UDINT_TO_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->CNT2,)));

  goto __end;

__end:
  return;
} // COUNT_DR_body__() 





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


void SHR_8PLE_init__(SHR_8PLE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->DIN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DLOAD,0,retain)
  __INIT_VAR(data__->CLK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UP,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->LOAD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DOUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->REGISTER,0,retain)
}

// Code part
void SHR_8PLE_body__(SHR_8PLE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (((__GET_VAR(data__->CLK,) && __GET_VAR(data__->EDGE,)) && !(__GET_VAR(data__->RST,)))) {
    __SET_VAR(data__->,EDGE,,__BOOL_LITERAL(FALSE));
    if (__GET_VAR(data__->UP,)) {
      __SET_VAR(data__->,REGISTER,,SHL__BYTE__BYTE__SINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->REGISTER,),
        (SINT)1));
      __SET_VAR(data__->,REGISTER,,BIT_LOAD_B(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->REGISTER,),
        (BOOL)__GET_VAR(data__->DIN,),
        (INT)0));
      __SET_VAR(data__->,DOUT,,BIT_OF_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)BYTE_TO_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->REGISTER,)),
        (INT)7));
    } else {
      __SET_VAR(data__->,REGISTER,,SHR__BYTE__BYTE__SINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->REGISTER,),
        (SINT)1));
      __SET_VAR(data__->,REGISTER,,BIT_LOAD_B(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->REGISTER,),
        (BOOL)__GET_VAR(data__->DIN,),
        (INT)7));
      __SET_VAR(data__->,DOUT,,BIT_OF_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)BYTE_TO_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->REGISTER,)),
        (INT)0));
    };
    if (__GET_VAR(data__->LOAD,)) {
      __SET_VAR(data__->,REGISTER,,__GET_VAR(data__->DLOAD,));
      if (__GET_VAR(data__->UP,)) {
        __SET_VAR(data__->,DOUT,,BIT_OF_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)BYTE_TO_DWORD(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (BYTE)__GET_VAR(data__->REGISTER,)),
          (INT)7));
      } else {
        __SET_VAR(data__->,DOUT,,BIT_OF_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)BYTE_TO_DWORD(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (BYTE)__GET_VAR(data__->REGISTER,)),
          (INT)0));
      };
    };
  };
  if (!(__GET_VAR(data__->CLK,))) {
    __SET_VAR(data__->,EDGE,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,REGISTER,,__BYTE_LITERAL(0));
    __SET_VAR(data__->,DOUT,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // SHR_8PLE_body__() 





void FF_DRE_init__(FF_DRE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->SET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CLK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void FF_DRE_body__(FF_DRE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->RST,) || __GET_VAR(data__->SET,))) {
    __SET_VAR(data__->,Q,,!(__GET_VAR(data__->RST,)));
  } else if ((__GET_VAR(data__->CLK,) && !(__GET_VAR(data__->EDGE,)))) {
    __SET_VAR(data__->,Q,,__GET_VAR(data__->DI,));
  };
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->CLK,));

  goto __end;

__end:
  return;
} // FF_DRE_body__() 





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


void COUNT_BR_init__(COUNT_BR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->SET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->UP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_STEP,1,retain)
  __INIT_VAR(data__->MX,255,retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CNT,0,retain)
  __INIT_VAR(data__->LAST_UP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LAST_DN,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void COUNT_BR_body__(COUNT_BR *data__) {
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
    __SET_VAR(data__->,CNT,,__BYTE_LITERAL(0));
  } else if (__GET_VAR(data__->SET,)) {
    __SET_VAR(data__->,CNT,,INT_TO_BYTE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)LIMIT__INT__INT__INT__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)0,
        (INT)_BYTE_TO_INT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->IN,)),
        (INT)_BYTE_TO_INT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->MX,)))));
  } else if ((__GET_VAR(data__->UP,) && !(__GET_VAR(data__->LAST_UP,)))) {
    __SET_VAR(data__->,CNT,,INT_TO_BYTE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)INC(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)_BYTE_TO_INT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->CNT,)),
        (INT)_BYTE_TO_INT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->_STEP,)),
        (INT)_BYTE_TO_INT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->MX,)))));
  } else if ((__GET_VAR(data__->DN,) && !(__GET_VAR(data__->LAST_DN,)))) {
    __SET_VAR(data__->,CNT,,INT_TO_BYTE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)INC(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)_BYTE_TO_INT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->CNT,)),
        (INT)(_BYTE_TO_INT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->_STEP,)) * -1),
        (INT)_BYTE_TO_INT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->MX,)))));
  };
  __SET_VAR(data__->,LAST_UP,,__GET_VAR(data__->UP,));
  __SET_VAR(data__->,LAST_DN,,__GET_VAR(data__->DN,));

  goto __end;

__end:
  return;
} // COUNT_BR_body__() 





void FF_JKE_init__(FF_JKE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->SET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->J,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CLK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->K,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void FF_JKE_body__(FF_JKE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->RST,) || __GET_VAR(data__->SET,))) {
    __SET_VAR(data__->,Q,,!(__GET_VAR(data__->RST,)));
  } else if ((__GET_VAR(data__->CLK,) && !(__GET_VAR(data__->EDGE,)))) {
    if ((__GET_VAR(data__->J,) && !__GET_VAR(data__->K,)) || (!__GET_VAR(data__->J,) && __GET_VAR(data__->K,))) {
      __SET_VAR(data__->,Q,,__GET_VAR(data__->J,));
    } else {
      __SET_VAR(data__->,Q,,(__GET_VAR(data__->K,) && !__GET_VAR(data__->Q,)) || (!__GET_VAR(data__->K,) && __GET_VAR(data__->Q,)));
    };
  };
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->CLK,));

  goto __end;

__end:
  return;
} // FF_JKE_body__() 





void SELECT_8_init__(SELECT_8 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->EI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->UP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q5,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q6,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q7,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->LAST_UP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LAST_DN,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void SELECT_8_body__(SELECT_8 *data__) {
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
    __SET_VAR(data__->,STATE,,0);
  } else if (__GET_VAR(data__->SET,)) {
    __SET_VAR(data__->,STATE,,_BYTE_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->IN,)));
  } else if ((__GET_VAR(data__->UP,) && !(__GET_VAR(data__->LAST_UP,)))) {
    __SET_VAR(data__->,STATE,,INC(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)__GET_VAR(data__->STATE,),
      (INT)1,
      (INT)7));
  } else if ((__GET_VAR(data__->DN,) && !(__GET_VAR(data__->LAST_DN,)))) {
    __SET_VAR(data__->,STATE,,INC(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)__GET_VAR(data__->STATE,),
      (INT)-1,
      (INT)7));
  };
  __SET_VAR(data__->,LAST_UP,,__GET_VAR(data__->UP,));
  __SET_VAR(data__->,LAST_DN,,__GET_VAR(data__->DN,));
  __SET_VAR(data__->,Q0,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,Q3,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,Q4,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,Q5,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,Q6,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,Q7,,__BOOL_LITERAL(FALSE));
  if (__GET_VAR(data__->EI,)) {
    {
      INT __case_expression = __GET_VAR(data__->STATE,);
      if ((__case_expression == 0)) {
        __SET_VAR(data__->,Q0,,__BOOL_LITERAL(TRUE));
      }
      else if ((__case_expression == 1)) {
        __SET_VAR(data__->,Q1,,__BOOL_LITERAL(TRUE));
      }
      else if ((__case_expression == 2)) {
        __SET_VAR(data__->,Q2,,__BOOL_LITERAL(TRUE));
      }
      else if ((__case_expression == 3)) {
        __SET_VAR(data__->,Q3,,__BOOL_LITERAL(TRUE));
      }
      else if ((__case_expression == 4)) {
        __SET_VAR(data__->,Q4,,__BOOL_LITERAL(TRUE));
      }
      else if ((__case_expression == 5)) {
        __SET_VAR(data__->,Q5,,__BOOL_LITERAL(TRUE));
      }
      else if ((__case_expression == 6)) {
        __SET_VAR(data__->,Q6,,__BOOL_LITERAL(TRUE));
      }
      else if ((__case_expression == 7)) {
        __SET_VAR(data__->,Q7,,__BOOL_LITERAL(TRUE));
      }
    };
  };

  goto __end;

__end:
  return;
} // SELECT_8_body__() 





void TOGGLE_init__(TOGGLE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->CLK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void TOGGLE_body__(TOGGLE *data__) {
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
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  } else if ((__GET_VAR(data__->CLK,) && !(__GET_VAR(data__->EDGE,)))) {
    __SET_VAR(data__->,Q,,!(__GET_VAR(data__->Q,)));
  };
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->CLK,));

  goto __end;

__end:
  return;
} // TOGGLE_body__() 





void LTCH_init__(LTCH *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->DI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->L,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LTCH_body__(LTCH *data__) {
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
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  } else if (__GET_VAR(data__->L,)) {
    __SET_VAR(data__->,Q,,__GET_VAR(data__->DI,));
  };

  goto __end;

__end:
  return;
} // LTCH_body__() 





void FF_RSE_init__(FF_RSE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->CS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ES,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ER,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void FF_RSE_body__(FF_RSE *data__) {
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
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  } else if ((__GET_VAR(data__->CR,) && !(__GET_VAR(data__->ER,)))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  } else if ((__GET_VAR(data__->CS,) && !(__GET_VAR(data__->ES,)))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,ES,,__GET_VAR(data__->CS,));
  __SET_VAR(data__->,ER,,__GET_VAR(data__->CR,));

  goto __end;

__end:
  return;
} // FF_RSE_body__() 





void LTCH_4_init__(LTCH_4 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->D0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->D1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->D2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->D3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->L,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q3,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LTCH_4_body__(LTCH_4 *data__) {
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
    __SET_VAR(data__->,Q0,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q3,,__BOOL_LITERAL(FALSE));
  } else if (__GET_VAR(data__->L,)) {
    __SET_VAR(data__->,Q0,,__GET_VAR(data__->D0,));
    __SET_VAR(data__->,Q1,,__GET_VAR(data__->D1,));
    __SET_VAR(data__->,Q2,,__GET_VAR(data__->D2,));
    __SET_VAR(data__->,Q3,,__GET_VAR(data__->D3,));
  };

  goto __end;

__end:
  return;
} // LTCH_4_body__() 





void STORE_8_init__(STORE_8 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->SET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->D0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->D1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->D2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->D3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->D4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->D5,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->D6,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->D7,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CLR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q5,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q6,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q7,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void STORE_8_body__(STORE_8 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->RST,) || __GET_VAR(data__->SET,))) {
    __SET_VAR(data__->,Q0,,!(__GET_VAR(data__->RST,)));
    __SET_VAR(data__->,Q1,,__GET_VAR(data__->Q0,));
    __SET_VAR(data__->,Q2,,__GET_VAR(data__->Q0,));
    __SET_VAR(data__->,Q3,,__GET_VAR(data__->Q0,));
    __SET_VAR(data__->,Q4,,__GET_VAR(data__->Q0,));
    __SET_VAR(data__->,Q5,,__GET_VAR(data__->Q0,));
    __SET_VAR(data__->,Q6,,__GET_VAR(data__->Q0,));
    __SET_VAR(data__->,Q7,,__GET_VAR(data__->Q0,));
  } else {
    if (__GET_VAR(data__->D0,)) {
      __SET_VAR(data__->,Q0,,__BOOL_LITERAL(TRUE));
    };
    if (__GET_VAR(data__->D1,)) {
      __SET_VAR(data__->,Q1,,__BOOL_LITERAL(TRUE));
    };
    if (__GET_VAR(data__->D2,)) {
      __SET_VAR(data__->,Q2,,__BOOL_LITERAL(TRUE));
    };
    if (__GET_VAR(data__->D3,)) {
      __SET_VAR(data__->,Q3,,__BOOL_LITERAL(TRUE));
    };
    if (__GET_VAR(data__->D4,)) {
      __SET_VAR(data__->,Q4,,__BOOL_LITERAL(TRUE));
    };
    if (__GET_VAR(data__->D5,)) {
      __SET_VAR(data__->,Q5,,__BOOL_LITERAL(TRUE));
    };
    if (__GET_VAR(data__->D6,)) {
      __SET_VAR(data__->,Q6,,__BOOL_LITERAL(TRUE));
    };
    if (__GET_VAR(data__->D7,)) {
      __SET_VAR(data__->,Q7,,__BOOL_LITERAL(TRUE));
    };
    if ((__GET_VAR(data__->CLR,) && !(__GET_VAR(data__->EDGE,)))) {
      if (__GET_VAR(data__->Q0,)) {
        __SET_VAR(data__->,Q0,,__BOOL_LITERAL(FALSE));
      } else if (__GET_VAR(data__->Q1,)) {
        __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
      } else if (__GET_VAR(data__->Q2,)) {
        __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
      } else if (__GET_VAR(data__->Q3,)) {
        __SET_VAR(data__->,Q3,,__BOOL_LITERAL(FALSE));
      } else if (__GET_VAR(data__->Q4,)) {
        __SET_VAR(data__->,Q4,,__BOOL_LITERAL(FALSE));
      } else if (__GET_VAR(data__->Q5,)) {
        __SET_VAR(data__->,Q5,,__BOOL_LITERAL(FALSE));
      } else if (__GET_VAR(data__->Q6,)) {
        __SET_VAR(data__->,Q6,,__BOOL_LITERAL(FALSE));
      } else {
        __SET_VAR(data__->,Q7,,__BOOL_LITERAL(FALSE));
      };
    };
    __SET_VAR(data__->,EDGE,,__GET_VAR(data__->CLR,));
  };

  goto __end;

__end:
  return;
} // STORE_8_body__() 





void FF_D4E_init__(FF_D4E *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->D0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->D1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->D2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->D3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CLK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void FF_D4E_body__(FF_D4E *data__) {
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
    __SET_VAR(data__->,Q0,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q3,,__BOOL_LITERAL(FALSE));
  } else if ((__GET_VAR(data__->CLK,) && !(__GET_VAR(data__->EDGE,)))) {
    __SET_VAR(data__->,Q0,,__GET_VAR(data__->D0,));
    __SET_VAR(data__->,Q1,,__GET_VAR(data__->D1,));
    __SET_VAR(data__->,Q2,,__GET_VAR(data__->D2,));
    __SET_VAR(data__->,Q3,,__GET_VAR(data__->D3,));
  };
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->CLK,));

  goto __end;

__end:
  return;
} // FF_D4E_body__() 





