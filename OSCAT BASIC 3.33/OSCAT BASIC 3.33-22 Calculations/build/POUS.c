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
REAL KMH_TO_MS(
  BOOL EN, 
  BOOL *__ENO, 
  REAL KMH)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL KMH_TO_MS = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return KMH_TO_MS;
  }
  KMH_TO_MS = (KMH * 0.2777777777777);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return KMH_TO_MS;
}


// FUNCTION
REAL BFT_TO_MS(
  BOOL EN, 
  BOOL *__ENO, 
  INT BFT)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL BFT_TO_MS = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return BFT_TO_MS;
  }
  BFT_TO_MS = (EXPT__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)INT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)BFT),
    (REAL)1.5) * 0.836);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return BFT_TO_MS;
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
REAL C_TO_K(
  BOOL EN, 
  BOOL *__ENO, 
  REAL CELSIUS)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL C_TO_K = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return C_TO_K;
  }
  C_TO_K = (CELSIUS - 273.15);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return C_TO_K;
}


// FUNCTION
TIME F_TO_PT(
  BOOL EN, 
  BOOL *__ENO, 
  REAL F)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  TIME F_TO_PT = __time_to_timespec(1, 0, 0, 0, 0, 0);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return F_TO_PT;
  }
  F_TO_PT = DWORD_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)REAL_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)((1.0 / F) * 1000.0)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return F_TO_PT;
}


void PRESSURE_init__(PRESSURE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->MWS,0,retain)
  __INIT_VAR(data__->TORR,0,retain)
  __INIT_VAR(data__->ATT,0,retain)
  __INIT_VAR(data__->ATM,0,retain)
  __INIT_VAR(data__->PA,0,retain)
  __INIT_VAR(data__->BAR,0,retain)
  __INIT_VAR(data__->YMWS,0,retain)
  __INIT_VAR(data__->YTORR,0,retain)
  __INIT_VAR(data__->YATT,0,retain)
  __INIT_VAR(data__->YATM,0,retain)
  __INIT_VAR(data__->YPA,0,retain)
  __INIT_VAR(data__->YBAR,0,retain)
}

// Code part
void PRESSURE_body__(PRESSURE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,YBAR,,(((((__GET_VAR(data__->BAR,) + (__GET_VAR(data__->PA,) * 1.0E-5)) + (0.980665 * __GET_VAR(data__->ATT,))) + (1.01325 * __GET_VAR(data__->ATM,))) + (0.001333224 * __GET_VAR(data__->TORR,))) + (0.0980665 * __GET_VAR(data__->MWS,))));
  __SET_VAR(data__->,YMWS,,(__GET_VAR(data__->YBAR,) * 10.1971621297793));
  __SET_VAR(data__->,YTORR,,(__GET_VAR(data__->YBAR,) * 750.0615050434140));
  __SET_VAR(data__->,YATT,,(__GET_VAR(data__->YBAR,) * 1.0197162129779));
  __SET_VAR(data__->,YATM,,(__GET_VAR(data__->YBAR,) * 0.9869232667160));
  __SET_VAR(data__->,YPA,,(__GET_VAR(data__->YBAR,) * 100000.0));

  goto __end;

__end:
  return;
} // PRESSURE_body__() 





// FUNCTION
REAL C_TO_F(
  BOOL EN, 
  BOOL *__ENO, 
  REAL CELSIUS)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL C_TO_F = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return C_TO_F;
  }
  C_TO_F = ((CELSIUS * 1.8) + 32.0);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return C_TO_F;
}


void ENERGY_init__(ENERGY *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->J,0,retain)
  __INIT_VAR(data__->C,0,retain)
  __INIT_VAR(data__->WH,0,retain)
  __INIT_VAR(data__->YJ,0,retain)
  __INIT_VAR(data__->YC,0,retain)
  __INIT_VAR(data__->YWH,0,retain)
}

// Code part
void ENERGY_body__(ENERGY *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,YJ,,((__GET_VAR(data__->J,) + (__GET_VAR(data__->WH,) * 3600.0)) + (__GET_VAR(data__->C,) * 4.1868)));
  __SET_VAR(data__->,YC,,(__GET_VAR(data__->YJ,) * 0.238845896627496));
  __SET_VAR(data__->,YWH,,(__GET_VAR(data__->YJ,) * 2.7777777778E-004));

  goto __end;

__end:
  return;
} // ENERGY_body__() 





// FUNCTION
REAL F_TO_OM(
  BOOL EN, 
  BOOL *__ENO, 
  REAL F)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL F_TO_OM = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return F_TO_OM;
  }
  F_TO_OM = (6.283185307179586476 * F);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return F_TO_OM;
}


void ASTRO_init__(ASTRO *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->M,0,retain)
  __INIT_VAR(data__->AE,0,retain)
  __INIT_VAR(data__->PC,0,retain)
  __INIT_VAR(data__->LJ,0,retain)
  __INIT_VAR(data__->YM,0,retain)
  __INIT_VAR(data__->YAE,0,retain)
  __INIT_VAR(data__->YPC,0,retain)
  __INIT_VAR(data__->YLJ,0,retain)
}

// Code part
void ASTRO_body__(ASTRO *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,YAE,,(((__GET_VAR(data__->AE,) + (__GET_VAR(data__->M,) * 6.6845871535E-012)) + (__GET_VAR(data__->PC,) * 206265.0)) + (__GET_VAR(data__->LJ,) * 63240.0)));
  __SET_VAR(data__->,YM,,(__GET_VAR(data__->YAE,) * 149.597870E9));
  __SET_VAR(data__->,YPC,,(__GET_VAR(data__->YAE,) * 4.8481322570E-006));
  __SET_VAR(data__->,YLJ,,(__GET_VAR(data__->YAE,) * 1.5812776724E-005));

  goto __end;

__end:
  return;
} // ASTRO_body__() 





void LENGTH_init__(LENGTH *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->M,0,retain)
  __INIT_VAR(data__->P,0,retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->FT,0,retain)
  __INIT_VAR(data__->YD,0,retain)
  __INIT_VAR(data__->MILE,0,retain)
  __INIT_VAR(data__->SM,0,retain)
  __INIT_VAR(data__->FM,0,retain)
  __INIT_VAR(data__->YM,0,retain)
  __INIT_VAR(data__->YP,0,retain)
  __INIT_VAR(data__->YIN,0,retain)
  __INIT_VAR(data__->YFT,0,retain)
  __INIT_VAR(data__->YYD,0,retain)
  __INIT_VAR(data__->YMILE,0,retain)
  __INIT_VAR(data__->YSM,0,retain)
  __INIT_VAR(data__->YFM,0,retain)
}

// Code part
void LENGTH_body__(LENGTH *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,YM,,(((((((__GET_VAR(data__->M,) + (__GET_VAR(data__->P,) * 0.000376065)) + (__GET_VAR(data__->IN,) * 0.0254)) + (__GET_VAR(data__->FT,) * 0.3048)) + (__GET_VAR(data__->YD,) * 0.9144)) + (__GET_VAR(data__->MILE,) * 1609.344)) + (__GET_VAR(data__->SM,) * 1852.0)) + (__GET_VAR(data__->FM,) * 1.829)));
  __SET_VAR(data__->,YP,,(__GET_VAR(data__->YM,) * 2659.11478068951));
  __SET_VAR(data__->,YIN,,(__GET_VAR(data__->YM,) * 39.37007874016));
  __SET_VAR(data__->,YFT,,(__GET_VAR(data__->YM,) * 3.28083989501));
  __SET_VAR(data__->,YYD,,(__GET_VAR(data__->YM,) * 1.09361329834));
  __SET_VAR(data__->,YMILE,,(__GET_VAR(data__->YM,) * 0.00062137119));
  __SET_VAR(data__->,YSM,,(__GET_VAR(data__->YM,) * 0.00053995680));
  __SET_VAR(data__->,YFM,,(__GET_VAR(data__->YM,) * 0.54674685621));

  goto __end;

__end:
  return;
} // LENGTH_body__() 





// FUNCTION
REAL F_TO_C(
  BOOL EN, 
  BOOL *__ENO, 
  REAL FAHRENHEIT)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL F_TO_C = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return F_TO_C;
  }
  F_TO_C = ((FAHRENHEIT - 32.0) * 0.5555555555555);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return F_TO_C;
}


// FUNCTION
REAL MS_TO_KMH(
  BOOL EN, 
  BOOL *__ENO, 
  REAL MS)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL MS_TO_KMH = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return MS_TO_KMH;
  }
  MS_TO_KMH = (MS * 3.6);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return MS_TO_KMH;
}


// FUNCTION
REAL K_TO_C(
  BOOL EN, 
  BOOL *__ENO, 
  REAL KELVIN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL K_TO_C = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return K_TO_C;
  }
  K_TO_C = (KELVIN + 273.15);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return K_TO_C;
}


// FUNCTION
REAL OM_TO_F(
  BOOL EN, 
  BOOL *__ENO, 
  REAL OM)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL OM_TO_F = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return OM_TO_F;
  }
  OM_TO_F = (OM / 6.283185307179586476);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return OM_TO_F;
}


// FUNCTION
INT MS_TO_BFT(
  BOOL EN, 
  BOOL *__ENO, 
  REAL MS)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT MS_TO_BFT = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return MS_TO_BFT;
  }
  MS_TO_BFT = REAL_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)EXPT__REAL__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(MS * 1.196172),
      (REAL)0.666667));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return MS_TO_BFT;
}


// FUNCTION
REAL PT_TO_F(
  BOOL EN, 
  BOOL *__ENO, 
  TIME PT)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL PT_TO_F = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return PT_TO_F;
  }
  PT_TO_F = (1000.0 / DWORD_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)TIME_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)PT)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return PT_TO_F;
}


void SPEED_init__(SPEED *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->MS,0,retain)
  __INIT_VAR(data__->KMH,0,retain)
  __INIT_VAR(data__->KN,0,retain)
  __INIT_VAR(data__->MH,0,retain)
  __INIT_VAR(data__->YMS,0,retain)
  __INIT_VAR(data__->YKMH,0,retain)
  __INIT_VAR(data__->YKN,0,retain)
  __INIT_VAR(data__->YMH,0,retain)
}

// Code part
void SPEED_body__(SPEED *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,YMS,,(((__GET_VAR(data__->MS,) + (__GET_VAR(data__->KMH,) * 0.27777777777778)) + (__GET_VAR(data__->KN,) * 0.5144444)) + (__GET_VAR(data__->MH,) * 0.44704)));
  __SET_VAR(data__->,YKMH,,(__GET_VAR(data__->YMS,) * 3.6));
  __SET_VAR(data__->,YKN,,(__GET_VAR(data__->YMS,) * 1.94384466037535));
  __SET_VAR(data__->,YMH,,(__GET_VAR(data__->YMS,) * 2.23693629205440));

  goto __end;

__end:
  return;
} // SPEED_body__() 





// FUNCTION
REAL GEO_TO_DEG(
  BOOL EN, 
  BOOL *__ENO, 
  INT _D, 
  INT M, 
  REAL SEC)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL GEO_TO_DEG = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return GEO_TO_DEG;
  }
  GEO_TO_DEG = ((INT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)_D) + (INT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)M) * 0.016666666666667)) + (SEC * 0.00027777777777778));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return GEO_TO_DEG;
}


void TEMPERATURE_init__(TEMPERATURE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->K,0,retain)
  __INIT_VAR(data__->C,-273.15,retain)
  __INIT_VAR(data__->F,-459.67,retain)
  __INIT_VAR(data__->RE,-218.52,retain)
  __INIT_VAR(data__->RA,0.0,retain)
  __INIT_VAR(data__->YK,0,retain)
  __INIT_VAR(data__->YC,0,retain)
  __INIT_VAR(data__->YF,0,retain)
  __INIT_VAR(data__->YRE,0,retain)
  __INIT_VAR(data__->YRA,0,retain)
}

// Code part
void TEMPERATURE_body__(TEMPERATURE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,YK,,((((__GET_VAR(data__->K,) + (__GET_VAR(data__->C,) + 273.15)) + ((__GET_VAR(data__->F,) + 459.67) * 0.555555555555)) + ((__GET_VAR(data__->RE,) * 1.25) + 273.15)) + (__GET_VAR(data__->RA,) * 0.555555555555)));
  __SET_VAR(data__->,YC,,(__GET_VAR(data__->YK,) - 273.15));
  __SET_VAR(data__->,YF,,((__GET_VAR(data__->YK,) * 1.8) - 459.67));
  __SET_VAR(data__->,YRE,,((__GET_VAR(data__->YK,) - 273.15) * 0.8));
  __SET_VAR(data__->,YRA,,(__GET_VAR(data__->YK,) * 1.8));

  goto __end;

__end:
  return;
} // TEMPERATURE_body__() 





