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
UDINT _DT_TO_TOD(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  UDINT _DT_TO_TOD = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return _DT_TO_TOD;
  }
  _DT_TO_TOD = (((__UDINT_LITERAL(86400) == 0)?0:(IN % __UDINT_LITERAL(86400))) * __UDINT_LITERAL(1000));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return _DT_TO_TOD;
}


void BLIND_SHADE_init__(BLIND_SHADE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->UP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PI,0,retain)
  __INIT_VAR(data__->AI,0,retain)
  __INIT_VAR(data__->S_IN,0,retain)
  __INIT_VAR(data__->ENABLE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SUN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SUNRISE_OFFSET,__time_to_timespec(1, 0, 0, 0, 1, 0),retain)
  __INIT_VAR(data__->SUNSET_PRESET,__time_to_timespec(1, 0, 0, 0, 1, 0),retain)
  __INIT_VAR(data__->SHADE_DELAY,__time_to_timespec(1, 0, 60, 0, 0, 0),retain)
  __INIT_VAR(data__->SHADE_POS,0,retain)
  __INIT_VAR(data__->DIRECTION,180.0,retain)
  __INIT_VAR(data__->ANGLE_OFFSET,80.0,retain)
  __INIT_VAR(data__->SLAT_WIDTH,80.0,retain)
  __INIT_VAR(data__->SLAT_SPACING,60.0,retain)
  __INIT_VAR(data__->QU,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->QD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATUS,0,retain)
  __INIT_VAR(data__->PO,0,retain)
  __INIT_VAR(data__->AO,0,retain)
  {
    static const OSCAT_CALENDAR temp = {0,0,0,0,0,0,0,0,0,__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__STRING_LITERAL(0,""),0,0,0,0,0,0,0,0,0,__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__STRING_LITERAL(0,""),0};
    __SET_VAR(data__->,CX,,temp);
  }
  TOF_init__(&data__->SUN_DELAY,retain);
  __INIT_VAR(data__->ANGLE,0,retain)
}

// Code part
void BLIND_SHADE_body__(BLIND_SHADE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->SUN_DELAY.,IN,,__GET_VAR(data__->SUN,));
  __SET_VAR(data__->SUN_DELAY.,PT,,__GET_VAR(data__->SHADE_DELAY,));
  TOF_body__(&data__->SUN_DELAY);
  if ((((((((__GET_VAR(data__->UP,) && __GET_VAR(data__->DN,)) && __GET_VAR(data__->ENABLE,)) && __GET_VAR(data__->SUN_DELAY.Q,)) && (__GET_VAR(data__->CX,.SUN_HOR) > (__GET_VAR(data__->DIRECTION,) - __GET_VAR(data__->ANGLE_OFFSET,)))) && (__GET_VAR(data__->CX,.SUN_HOR) < (__GET_VAR(data__->DIRECTION,) + __GET_VAR(data__->ANGLE_OFFSET,)))) && (_DT_TO_TOD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->CX,.UTC)) > (__GET_VAR(data__->CX,.SUN_RISE) + TIME_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (TIME)__GET_VAR(data__->SUNRISE_OFFSET,))))) && (_DT_TO_TOD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->CX,.UTC)) < (__GET_VAR(data__->CX,.SUN_SET) - TIME_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (TIME)__GET_VAR(data__->SUNSET_PRESET,)))))) {
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(151));
    __SET_VAR(data__->,QU,,__GET_VAR(data__->UP,));
    __SET_VAR(data__->,QD,,__GET_VAR(data__->DN,));
    __SET_VAR(data__->,PO,,__GET_VAR(data__->SHADE_POS,));
    __SET_VAR(data__->,ANGLE,,DEG(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)ATAN__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)(__GET_VAR(data__->SLAT_SPACING,) / __GET_VAR(data__->SLAT_WIDTH,)))));
    if (((__GET_VAR(data__->CX,.SUN_VER) > 0.0) && (__GET_VAR(data__->CX,.SUN_VER) < __GET_VAR(data__->ANGLE,)))) {
      __SET_VAR(data__->,ANGLE,,(__GET_VAR(data__->CX,.SUN_VER) + DEG(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)ACOS__REAL__REAL(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (REAL)((COS__REAL__REAL(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (REAL)RAD(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (REAL)__GET_VAR(data__->CX,.SUN_VER))) * __GET_VAR(data__->SLAT_SPACING,)) / __GET_VAR(data__->SLAT_WIDTH,))))));
      __SET_VAR(data__->,AO,,INT_TO_BYTE(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)LIMIT__INT__INT__INT__INT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (INT)0,
          (INT)UDINT_TO_INT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (UDINT)TRUNC__UDINT__REAL(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (REAL)(__GET_VAR(data__->ANGLE,) * 2.833333333))),
          (INT)255)));
    } else {
      __SET_VAR(data__->,AO,,__BYTE_LITERAL(255));
    };
  } else {
    __SET_VAR(data__->,QU,,__GET_VAR(data__->UP,));
    __SET_VAR(data__->,QD,,__GET_VAR(data__->DN,));
    __SET_VAR(data__->,PO,,__GET_VAR(data__->PI,));
    __SET_VAR(data__->,AO,,__GET_VAR(data__->AI,));
    __SET_VAR(data__->,STATUS,,__GET_VAR(data__->S_IN,));
  };

  goto __end;

__end:
  return;
} // BLIND_SHADE_body__() 





// FUNCTION
REAL WATER_DENSITY(
  BOOL EN, 
  BOOL *__ENO, 
  REAL _T, 
  BOOL SAT)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL T2 = 0;
  REAL T4 = 0;
  REAL WATER_DENSITY = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return WATER_DENSITY;
  }
  T2 = (_T * _T);
  T4 = (T2 * T2);
  WATER_DENSITY = ((((((999.83952 + (16.952577 * _T)) + (-7.9905127E-3 * T2)) + ((-4.6241757E-5 * T2) * _T)) + (1.0584601E-7 * T4)) + ((-2.8103006E-10 * T4) * _T)) / (1.0 + (0.0168872 * _T)));
  if (SAT) {
    WATER_DENSITY = ((WATER_DENSITY - 0.004612) + (0.000106 * _T));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return WATER_DENSITY;
}


// FUNCTION
BOOL TIMECHECK(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT TD, 
  UDINT START, 
  UDINT STOP)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BOOL TIMECHECK = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return TIMECHECK;
  }
  if ((STOP < START)) {
    TIMECHECK = ((START <= TD) || (TD < STOP));
  } else {
    TIMECHECK = ((START <= TD) && (TD < STOP));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return TIMECHECK;
}


void BOILER_init__(BOILER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->T_UPPER,0,retain)
  __INIT_VAR(data__->T_LOWER,0,retain)
  __INIT_VAR(data__->PRESSURE,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENABLE,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->REQ_1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REQ_2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOOST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->T_UPPER_MIN,50.0,retain)
  __INIT_VAR(data__->T_UPPER_MAX,60.0,retain)
  __INIT_VAR(data__->T_LOWER_ENABLE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->T_LOWER_MAX,60.0,retain)
  __INIT_VAR(data__->T_REQUEST_1,70.0,retain)
  __INIT_VAR(data__->T_REQUEST_2,50.0,retain)
  __INIT_VAR(data__->T_REQUEST_HYS,5.0,retain)
  __INIT_VAR(data__->T_PROTECT_HIGH,80.0,retain)
  __INIT_VAR(data__->T_PROTECT_LOW,10.0,retain)
  __INIT_VAR(data__->HEAT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ERROR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATUS,0,retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOOST_MODE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FLAG_0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FLAG_1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FLAG_2,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void BOILER_body__(BOILER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->T_UPPER,) > __GET_VAR(data__->T_PROTECT_HIGH,))) {
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(1));
    __SET_VAR(data__->,HEAT,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,ERROR,,__BOOL_LITERAL(TRUE));
  } else if ((__GET_VAR(data__->T_UPPER,) < __GET_VAR(data__->T_PROTECT_LOW,))) {
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(2));
    __SET_VAR(data__->,HEAT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,ERROR,,__BOOL_LITERAL(TRUE));
  } else if (((__GET_VAR(data__->T_LOWER,) > __GET_VAR(data__->T_PROTECT_HIGH,)) && __GET_VAR(data__->T_LOWER_ENABLE,))) {
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(3));
    __SET_VAR(data__->,HEAT,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,ERROR,,__BOOL_LITERAL(TRUE));
  } else if (((__GET_VAR(data__->T_LOWER,) < __GET_VAR(data__->T_PROTECT_LOW,)) && __GET_VAR(data__->T_LOWER_ENABLE,))) {
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(4));
    __SET_VAR(data__->,HEAT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,ERROR,,__BOOL_LITERAL(TRUE));
  } else if (!(__GET_VAR(data__->PRESSURE,))) {
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(5));
    __SET_VAR(data__->,HEAT,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,ERROR,,__BOOL_LITERAL(TRUE));
  } else if ((((__GET_VAR(data__->REQ_1,) || __GET_VAR(data__->REQ_2,)) || __GET_VAR(data__->ENABLE,)) || __GET_VAR(data__->BOOST,))) {
    __SET_VAR(data__->,ERROR,,__BOOL_LITERAL(FALSE));
    if (((__GET_VAR(data__->BOOST,) && !(__GET_VAR(data__->EDGE,))) && (__GET_VAR(data__->T_UPPER,) < __GET_VAR(data__->T_UPPER_MAX,)))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(101));
      __SET_VAR(data__->,HEAT,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,BOOST_MODE,,__BOOL_LITERAL(TRUE));
    } else if ((__GET_VAR(data__->ENABLE,) && (__GET_VAR(data__->T_UPPER,) < __GET_VAR(data__->T_UPPER_MIN,)))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(102));
      __SET_VAR(data__->,HEAT,,__BOOL_LITERAL(TRUE));
    } else if ((__GET_VAR(data__->REQ_1,) && (__GET_VAR(data__->T_UPPER,) < __GET_VAR(data__->T_REQUEST_1,)))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(103));
      __SET_VAR(data__->,HEAT,,__BOOL_LITERAL(TRUE));
    } else if ((__GET_VAR(data__->REQ_2,) && (__GET_VAR(data__->T_UPPER,) < __GET_VAR(data__->T_REQUEST_2,)))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(104));
      __SET_VAR(data__->,HEAT,,__BOOL_LITERAL(TRUE));
    };
    if (__GET_VAR(data__->HEAT,)) {
      if ((__GET_VAR(data__->ENABLE,) || __GET_VAR(data__->BOOST_MODE,))) {
        __SET_VAR(data__->,FLAG_0,,__BOOL_LITERAL(TRUE));
        if ((__GET_VAR(data__->T_LOWER_ENABLE,) && (__GET_VAR(data__->T_LOWER,) > __GET_VAR(data__->T_LOWER_MAX,)))) {
          __SET_VAR(data__->,FLAG_0,,__BOOL_LITERAL(FALSE));
          __SET_VAR(data__->,BOOST_MODE,,__BOOL_LITERAL(FALSE));
        } else if ((!(__GET_VAR(data__->T_LOWER_ENABLE,)) && (__GET_VAR(data__->T_UPPER,) > __GET_VAR(data__->T_UPPER_MAX,)))) {
          __SET_VAR(data__->,FLAG_0,,__BOOL_LITERAL(FALSE));
          __SET_VAR(data__->,BOOST_MODE,,__BOOL_LITERAL(FALSE));
        };
      } else {
        __SET_VAR(data__->,FLAG_0,,__BOOL_LITERAL(FALSE));
      };
      __SET_VAR(data__->,FLAG_1,,((__GET_VAR(data__->REQ_1,) && (__GET_VAR(data__->T_UPPER,) > (__GET_VAR(data__->T_REQUEST_1,) + __GET_VAR(data__->T_REQUEST_HYS,)))) && __GET_VAR(data__->REQ_1,)));
      __SET_VAR(data__->,FLAG_2,,((__GET_VAR(data__->REQ_2,) && (__GET_VAR(data__->T_UPPER,) > (__GET_VAR(data__->T_REQUEST_2,) + __GET_VAR(data__->T_REQUEST_HYS,)))) && __GET_VAR(data__->REQ_2,)));
      __SET_VAR(data__->,HEAT,,((__GET_VAR(data__->FLAG_0,) || __GET_VAR(data__->FLAG_1,)) || __GET_VAR(data__->FLAG_2,)));
      if ((__GET_VAR(data__->HEAT,) == __BOOL_LITERAL(FALSE))) {
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(100));
      };
    };
  } else {
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(100));
    __SET_VAR(data__->,HEAT,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,ERROR,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->BOOST,));

  goto __end;

__end:
  return;
} // BOILER_body__() 





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


void INTEGRATE_init__(INTEGRATE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->_E,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->K,1.0,retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->X_LAST,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LAST,0,retain)
  __INIT_VAR(data__->TX,0,retain)
}

// Code part
void INTEGRATE_body__(INTEGRATE *data__) {
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
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,X_LAST,,__GET_VAR(data__->X,));
  } else if (__GET_VAR(data__->_E,)) {
    __SET_VAR(data__->,Y,,(((((__GET_VAR(data__->X,) + __GET_VAR(data__->X_LAST,)) * 0.5E-3) * UDINT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)(__GET_VAR(data__->TX,) - __GET_VAR(data__->LAST,)))) * __GET_VAR(data__->K,)) + __GET_VAR(data__->Y,)));
    __SET_VAR(data__->,X_LAST,,__GET_VAR(data__->X,));
  };
  __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));

  goto __end;

__end:
  return;
} // INTEGRATE_body__() 





void R2_ADD_init__(R2_ADD *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const REAL2 temp = {0,0};
    __SET_VAR(data__->,X,,temp);
  }
  __INIT_VAR(data__->Y,0,retain)
  {
    static const REAL2 temp = {0,0};
    __SET_VAR(data__->,_R2_ADD,,temp);
  }
  __INIT_VAR(data__->TEMP,0,retain)
}

// Code part
void R2_ADD_body__(R2_ADD *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,TEMP,,__GET_VAR(data__->X,.RX));
  __SET_VAR(data__->,_R2_ADD,.RX,((__GET_VAR(data__->Y,) + __GET_VAR(data__->X,.R1)) + __GET_VAR(data__->X,.RX)));
  __SET_VAR(data__->,_R2_ADD,.R1,(((__GET_VAR(data__->TEMP,) - __GET_VAR(data__->_R2_ADD,.RX)) + __GET_VAR(data__->Y,)) + __GET_VAR(data__->X,.R1)));

  goto __end;

__end:
  return;
} // R2_ADD_body__() 





void R2_SET_init__(R2_SET *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X,0,retain)
  {
    static const REAL2 temp = {0,0};
    __SET_VAR(data__->,_R2_SET,,temp);
  }
}

// Code part
void R2_SET_body__(R2_SET *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_R2_SET,.RX,__GET_VAR(data__->X,));
  __SET_VAR(data__->,_R2_SET,.R1,0.0);

  goto __end;

__end:
  return;
} // R2_SET_body__() 





void FT_INT2_init__(FT_INT2 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->K,1.0,retain)
  __INIT_VAR(data__->RUN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT_MIN,-1.0E-37,retain)
  __INIT_VAR(data__->OUT_MAX,1.0E37,retain)
  __INIT_VAR(data__->OUT,0,retain)
  __INIT_VAR(data__->LIM,__BOOL_LITERAL(FALSE),retain)
  INTEGRATE_init__(&data__->INTEG,retain);
  __INIT_VAR(data__->IX,0,retain)
  {
    static const REAL2 temp = {0,0};
    __SET_VAR(data__->,VAL,,temp);
  }
  R2_ADD_init__(&data__->_R2_ADD,retain);
  R2_SET_init__(&data__->_R2_SET,retain);
}

// Code part
void FT_INT2_body__(FT_INT2 *data__) {
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
    __SET_VAR(data__->_R2_SET.,X,,0.0);
    R2_SET_body__(&data__->_R2_SET);
    __SET_VAR(data__->,VAL,,__GET_VAR(data__->_R2_SET._R2_SET,));
    __SET_VAR(data__->,OUT,,0.0);
  } else {
    __SET_VAR(data__->INTEG.,_E,,__GET_VAR(data__->RUN,));
    __SET_VAR(data__->INTEG.,X,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->INTEG.,K,,__GET_VAR(data__->K,));
    __SET_VAR(data__->INTEG.,Y,,__GET_VAR(data__->IX,));
    INTEGRATE_body__(&data__->INTEG);
    __SET_VAR(data__->,IX,,__GET_VAR(data__->INTEG.Y));
    __SET_VAR(data__->,IX,,__GET_VAR(data__->INTEG.Y,));
    __SET_VAR(data__->_R2_ADD.,X,,__GET_VAR(data__->VAL,));
    __SET_VAR(data__->_R2_ADD.,Y,,__GET_VAR(data__->IX,));
    R2_ADD_body__(&data__->_R2_ADD);
    __SET_VAR(data__->,VAL,,__GET_VAR(data__->_R2_ADD._R2_ADD,));
    __SET_VAR(data__->,IX,,0.0);
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->VAL,.RX));
  };
  if (((__GET_VAR(data__->OUT,) > __GET_VAR(data__->OUT_MIN,)) && (__GET_VAR(data__->OUT,) < __GET_VAR(data__->OUT_MAX,)))) {
    __SET_VAR(data__->,LIM,,__BOOL_LITERAL(FALSE));
  } else {
    __SET_VAR(data__->,OUT,,LIMIT__REAL__REAL__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)__GET_VAR(data__->OUT_MIN,),
      (REAL)__GET_VAR(data__->OUT,),
      (REAL)__GET_VAR(data__->OUT_MAX,)));
    __SET_VAR(data__->_R2_SET.,X,,__GET_VAR(data__->OUT,));
    R2_SET_body__(&data__->_R2_SET);
    __SET_VAR(data__->,VAL,,__GET_VAR(data__->_R2_SET._R2_SET,));
    __SET_VAR(data__->,LIM,,__BOOL_LITERAL(TRUE));
  };

  goto __end;

__end:
  return;
} // FT_INT2_body__() 





// FUNCTION
REAL LINEAR_INT(
  BOOL EN, 
  BOOL *__ENO, 
  REAL X, 
  __ARRAY_OF_REAL_20_2 *__XY, 
  INT PTS)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  __ARRAY_OF_REAL_20_2 XY;
  if (__XY != NULL) {
    XY = *__XY;
  }
  else {
    static const __ARRAY_OF_REAL_20_2 temp = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    XY = temp;
  }
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
  if (__XY != NULL) {
    *__XY = XY;
  }
  return LINEAR_INT;
}


// FUNCTION
REAL WATER_ENTHALPY(
  BOOL EN, 
  BOOL *__ENO, 
  REAL _T)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT PTS = 11;
  __ARRAY_OF_REAL_20_2 DATA = {{0.0,0.06,10.0,42.1,20.0,83.9,30.0,125.8,40.0,167.58,50.0,209.4,60.0,251.2,70.0,293.1,80.0,335.0,90.0,377.0,100.0,419.1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
  REAL WATER_ENTHALPY = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return WATER_ENTHALPY;
  }
  WATER_ENTHALPY = LINEAR_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)_T,
    &(DATA),
    (INT)PTS);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return WATER_ENTHALPY;
}


void HEAT_METER_init__(HEAT_METER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TF,0,retain)
  __INIT_VAR(data__->TR,0,retain)
  __INIT_VAR(data__->LPH,0,retain)
  __INIT_VAR(data__->_E,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CP,0,retain)
  __INIT_VAR(data__->DENSITY,0,retain)
  __INIT_VAR(data__->CONTENT,0,retain)
  __INIT_VAR(data__->PULSE_MODE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RETURN_METER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AVG_TIME,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->C,0,retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->TX,0,retain)
  __INIT_VAR(data__->LAST,0,retain)
  FT_INT2_init__(&data__->INT1,retain);
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Y_LAST,0,retain)
}

// Code part
void HEAT_METER_body__(HEAT_METER *data__) {
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
    __SET_VAR(data__->INT1.,RST,,__BOOL_LITERAL(TRUE));
    FT_INT2_body__(&data__->INT1);
    __SET_VAR(data__->,INT1.RST,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,C,,0.0);
    __SET_VAR(data__->,Y,,0.0);
  } else if (__GET_VAR(data__->_E,)) {
    __SET_VAR(data__->,X,,(((WATER_DENSITY(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)SEL__REAL__BOOL__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BOOL)__GET_VAR(data__->RETURN_METER,),
        (REAL)__GET_VAR(data__->TF,),
        (REAL)__GET_VAR(data__->TR,)),
      (BOOL)__BOOL_LITERAL(FALSE)) * (WATER_ENTHALPY(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)__GET_VAR(data__->TF,)) - WATER_ENTHALPY(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)__GET_VAR(data__->TR,)))) * (1.0 - __GET_VAR(data__->CONTENT,))) + (((__GET_VAR(data__->CP,) * __GET_VAR(data__->DENSITY,)) * __GET_VAR(data__->CONTENT,)) * (__GET_VAR(data__->TF,) - __GET_VAR(data__->TR,)))));
  };
  __SET_VAR(data__->INT1.,IN,,((__GET_VAR(data__->X,) * __GET_VAR(data__->LPH,)) * 2.77777777777E-4));
  __SET_VAR(data__->INT1.,RUN,,(!(__GET_VAR(data__->PULSE_MODE,)) && __GET_VAR(data__->_E,)));
  FT_INT2_body__(&data__->INT1);
  if (__GET_VAR(data__->PULSE_MODE,)) {
    if ((!(__GET_VAR(data__->EDGE,)) && __GET_VAR(data__->_E,))) {
      __SET_VAR(data__->,Y,,(__GET_VAR(data__->Y,) + (__GET_VAR(data__->X,) * __GET_VAR(data__->LPH,))));
    };
  } else {
    __SET_VAR(data__->,Y,,__GET_VAR(data__->INT1.OUT,));
  };
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->_E,));
  __SET_VAR(data__->,TX,,UDINT_TO_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)T_PLC_MS(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__BOOL_LITERAL(FALSE))));
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
  };
  if ((((DWORD_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)__GET_VAR(data__->TX,)) - DWORD_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)__GET_VAR(data__->LAST,))) >= TIME_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (TIME)__GET_VAR(data__->AVG_TIME,))) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->AVG_TIME,), __time_to_timespec(1, 0, 0, 0, 0, 0)))) {
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,C,,(((__GET_VAR(data__->Y,) - __GET_VAR(data__->Y_LAST,)) * 3.6E6) / DWORD_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)TIME_TO_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (TIME)__GET_VAR(data__->AVG_TIME,)))));
    __SET_VAR(data__->,Y_LAST,,__GET_VAR(data__->Y,));
  };

  goto __end;

__end:
  return;
} // HEAT_METER_body__() 





void CYCLE_4_init__(CYCLE_4 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->_E,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->T0,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T1,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T2,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T3,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->S0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SX,0,retain)
  __INIT_VAR(data__->SL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void CYCLE_4_body__(CYCLE_4 *data__) {
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
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
  };
  if (__GET_VAR(data__->_E,)) {
    if (__GET_VAR(data__->SL,)) {
      __SET_VAR(data__->,STATE,,LIMIT__INT__INT__INT__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)0,
        (INT)__GET_VAR(data__->SX,),
        (INT)3));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
      __SET_VAR(data__->,SL,,__BOOL_LITERAL(FALSE));
    } else {
      {
        INT __case_expression = __GET_VAR(data__->STATE,);
        if ((__case_expression == 0)) {
          if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->T0,))) {
            __SET_VAR(data__->,STATE,,1);
            __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
          };
        }
        else if ((__case_expression == 1)) {
          if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->T1,))) {
            __SET_VAR(data__->,STATE,,2);
            __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
          };
        }
        else if ((__case_expression == 2)) {
          if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->T2,))) {
            __SET_VAR(data__->,STATE,,3);
            __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
          };
        }
        else if ((__case_expression == 3)) {
          if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->T3,))) {
            if (__GET_VAR(data__->S0,)) {
              __SET_VAR(data__->,STATE,,0);
            };
            __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
          };
        }
      };
    };
  } else {
    __SET_VAR(data__->,STATE,,0);
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
  };

  goto __end;

__end:
  return;
} // CYCLE_4_body__() 





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
REAL SDD(
  BOOL EN, 
  BOOL *__ENO, 
  REAL _T, 
  BOOL ICE)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL SDD = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SDD;
  }
  if (ICE) {
    SDD = (611.153 * EXP__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)((22.4433 * _T) / (272.186 + _T))));
  } else {
    SDD = (611.213 * EXP__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)((17.5043 * _T) / (241.2 + _T))));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SDD;
}


// FUNCTION
REAL DEW_CON(
  BOOL EN, 
  BOOL *__ENO, 
  REAL RH, 
  REAL _T)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL DEW_CON = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DEW_CON;
  }
  if (((RH > 0.0) && (_T > -50.0))) {
    DEW_CON = (((2.166824303E-2 * RH) * SDD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)_T,
      (BOOL)__BOOL_LITERAL(FALSE))) / (_T - -273.15));
  } else {
    DEW_CON = 0.0;
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return DEW_CON;
}


// FUNCTION
REAL DEW_RH(
  BOOL EN, 
  BOOL *__ENO, 
  REAL VC, 
  REAL _T)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL DEW_RH = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DEW_RH;
  }
  DEW_RH = LIMIT__REAL__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)0.0,
    (REAL)(VC / DEW_CON(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)1.0,
      (REAL)_T)),
    (REAL)100.0);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return DEW_RH;
}


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


// FUNCTION
BOOL LEAP_OF_DATE(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BOOL LEAP_OF_DATE = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return LEAP_OF_DATE;
  }
  LEAP_OF_DATE = (SHL__DWORD__DWORD__SINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)UDINT_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)((IDATE + __UDINT_LITERAL(43200)) / __UDINT_LITERAL(31557600))),
    (SINT)30) == __DWORD_LITERAL(0x80000000));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return LEAP_OF_DATE;
}


// FUNCTION
INT DAY_OF_YEAR(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT DAY_OF_YEAR = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DAY_OF_YEAR;
  }
  DAY_OF_YEAR = UDINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)((__UDINT_LITERAL(1461) == 0)?0:((IDATE / __UDINT_LITERAL(86400)) % __UDINT_LITERAL(1461))));
  if ((DAY_OF_YEAR > 729)) {
    if ((DAY_OF_YEAR > 1095)) {
      DAY_OF_YEAR = (DAY_OF_YEAR - 1095);
    } else {
      DAY_OF_YEAR = (DAY_OF_YEAR - 729);
    };
  } else if ((DAY_OF_YEAR > 364)) {
    DAY_OF_YEAR = (DAY_OF_YEAR - 364);
  } else {
    DAY_OF_YEAR = (DAY_OF_YEAR + 1);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return DAY_OF_YEAR;
}


// FUNCTION
INT DAY_OF_MONTH(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT DAY_OF_MONTH = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DAY_OF_MONTH;
  }
  DAY_OF_MONTH = DAY_OF_YEAR(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)IDATE);
  if (LEAP_OF_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)IDATE)) {
    {
      INT __case_expression = DAY_OF_MONTH;
      if ((__case_expression >= 32 && __case_expression <= 60)) {
        DAY_OF_MONTH = (DAY_OF_MONTH - 31);
      }
      else if ((__case_expression >= 61 && __case_expression <= 91)) {
        DAY_OF_MONTH = (DAY_OF_MONTH - 60);
      }
      else if ((__case_expression >= 92 && __case_expression <= 121)) {
        DAY_OF_MONTH = (DAY_OF_MONTH - 91);
      }
      else if ((__case_expression >= 122 && __case_expression <= 152)) {
        DAY_OF_MONTH = (DAY_OF_MONTH - 121);
      }
      else if ((__case_expression >= 153 && __case_expression <= 182)) {
        DAY_OF_MONTH = (DAY_OF_MONTH - 152);
      }
      else if ((__case_expression >= 183 && __case_expression <= 213)) {
        DAY_OF_MONTH = (DAY_OF_MONTH - 182);
      }
      else if ((__case_expression >= 214 && __case_expression <= 244)) {
        DAY_OF_MONTH = (DAY_OF_MONTH - 213);
      }
      else if ((__case_expression >= 245 && __case_expression <= 274)) {
        DAY_OF_MONTH = (DAY_OF_MONTH - 244);
      }
      else if ((__case_expression >= 275 && __case_expression <= 305)) {
        DAY_OF_MONTH = (DAY_OF_MONTH - 274);
      }
      else if ((__case_expression >= 306 && __case_expression <= 335)) {
        DAY_OF_MONTH = (DAY_OF_MONTH - 305);
      }
      else if ((__case_expression >= 336 && __case_expression <= 366)) {
        DAY_OF_MONTH = (DAY_OF_MONTH - 335);
      }
    };
  } else {
    {
      INT __case_expression = DAY_OF_MONTH;
      if ((__case_expression >= 32 && __case_expression <= 59)) {
        DAY_OF_MONTH = (DAY_OF_MONTH - 31);
      }
      else if ((__case_expression >= 60 && __case_expression <= 90)) {
        DAY_OF_MONTH = (DAY_OF_MONTH - 59);
      }
      else if ((__case_expression >= 91 && __case_expression <= 120)) {
        DAY_OF_MONTH = (DAY_OF_MONTH - 90);
      }
      else if ((__case_expression >= 121 && __case_expression <= 151)) {
        DAY_OF_MONTH = (DAY_OF_MONTH - 120);
      }
      else if ((__case_expression >= 152 && __case_expression <= 181)) {
        DAY_OF_MONTH = (DAY_OF_MONTH - 151);
      }
      else if ((__case_expression >= 182 && __case_expression <= 212)) {
        DAY_OF_MONTH = (DAY_OF_MONTH - 181);
      }
      else if ((__case_expression >= 213 && __case_expression <= 243)) {
        DAY_OF_MONTH = (DAY_OF_MONTH - 212);
      }
      else if ((__case_expression >= 244 && __case_expression <= 273)) {
        DAY_OF_MONTH = (DAY_OF_MONTH - 243);
      }
      else if ((__case_expression >= 274 && __case_expression <= 304)) {
        DAY_OF_MONTH = (DAY_OF_MONTH - 273);
      }
      else if ((__case_expression >= 305 && __case_expression <= 334)) {
        DAY_OF_MONTH = (DAY_OF_MONTH - 304);
      }
      else if ((__case_expression >= 335 && __case_expression <= 365)) {
        DAY_OF_MONTH = (DAY_OF_MONTH - 334);
      }
    };
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return DAY_OF_MONTH;
}


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





void DEBOUNCE_init__(DEBOUNCE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TD,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->PM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  TOF_init__(&data__->DEB,retain);
}

// Code part
void DEBOUNCE_body__(DEBOUNCE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((!(__GET_VAR(data__->DEB.Q,)) && __GET_VAR(data__->IN,))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
  } else if (!(__GET_VAR(data__->PM,))) {
    __SET_VAR(data__->,Q,,__GET_VAR(data__->DEB.Q,));
  } else {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->DEB.,IN,,__GET_VAR(data__->IN,));
  __SET_VAR(data__->DEB.,PT,,__GET_VAR(data__->TD,));
  TOF_body__(&data__->DEB);

  goto __end;

__end:
  return;
} // DEBOUNCE_body__() 





void SW_RECONFIG_init__(SW_RECONFIG *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TD,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TR,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->T1,retain);
  TON_init__(&data__->T2,retain);
  __INIT_VAR(data__->INV,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void SW_RECONFIG_body__(SW_RECONFIG *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->T1.,IN,,__GET_VAR(data__->IN,));
  __SET_VAR(data__->T1.,PT,,__GET_VAR(data__->TD,));
  TON_body__(&data__->T1);
  if (GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TR,), __time_to_timespec(1, 0, 0, 0, 0, 0))) {
    __SET_VAR(data__->,Q,,(__GET_VAR(data__->T1.Q,) && !__GET_VAR(data__->INV,)) || (!__GET_VAR(data__->T1.Q,) && __GET_VAR(data__->INV,)));
    __SET_VAR(data__->T2.,IN,,__GET_VAR(data__->Q,));
    __SET_VAR(data__->T2.,PT,,__GET_VAR(data__->TR,));
    TON_body__(&data__->T2);
    if (__GET_VAR(data__->T2.Q,)) {
      __SET_VAR(data__->,INV,,!(__GET_VAR(data__->INV,)));
    };
  } else {
    __SET_VAR(data__->,Q,,__GET_VAR(data__->T1.Q,));
  };

  goto __end;

__end:
  return;
} // SW_RECONFIG_body__() 





void CLICK_MODE_init__(CLICK_MODE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->T_LONG,__time_to_timespec(1, 500, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->SINGLE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DOUBLE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LONG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TP_LONG,__BOOL_LITERAL(FALSE),retain)
  TP_init__(&data__->TIMER,retain);
  __INIT_VAR(data__->CNT,0,retain)
  __INIT_VAR(data__->LAST,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void CLICK_MODE_body__(CLICK_MODE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->TIMER.,IN,,__GET_VAR(data__->IN,));
  __SET_VAR(data__->TIMER.,PT,,__GET_VAR(data__->T_LONG,));
  TP_body__(&data__->TIMER);
  __SET_VAR(data__->,SINGLE,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,DOUBLE,,__BOOL_LITERAL(FALSE));
  if (__GET_VAR(data__->TIMER.Q,)) {
    if ((!(__GET_VAR(data__->IN,)) && __GET_VAR(data__->LAST,))) {
      __SET_VAR(data__->,CNT,,(__GET_VAR(data__->CNT,) + 1));
    };
  } else {
    {
      INT __case_expression = __GET_VAR(data__->CNT,);
      if ((__case_expression == 1)) {
        __SET_VAR(data__->,SINGLE,,__BOOL_LITERAL(TRUE));
      }
      else if ((__case_expression == 2)) {
        __SET_VAR(data__->,DOUBLE,,__BOOL_LITERAL(TRUE));
      }
    };
    __SET_VAR(data__->,CNT,,0);
  };
  __SET_VAR(data__->,LAST,,__GET_VAR(data__->IN,));
  __SET_VAR(data__->,TP_LONG,,((!(__GET_VAR(data__->TIMER.Q,)) && !(__GET_VAR(data__->LONG,))) && __GET_VAR(data__->IN,)));
  __SET_VAR(data__->,LONG,,(!(__GET_VAR(data__->TIMER.Q,)) && __GET_VAR(data__->IN,)));

  goto __end;

__end:
  return;
} // CLICK_MODE_body__() 





// FUNCTION
BYTE FRMP_B(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE START, 
  BOOL DIR, 
  TIME TD, 
  TIME TR)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
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


void _RMP_B_init__(_RMP_B *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->DIR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_E,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TR,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->RMP,0,retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TL,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TN,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LAST_DIR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->START,0,retain)
}

// Code part
void _RMP_B_body__(_RMP_B *data__) {
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
  if (((((__GET_VAR(data__->_E,) && __GET_VAR(data__->INIT,)) && (__GET_VAR(data__->DIR,) == __GET_VAR(data__->LAST_DIR,))) && (__GET_VAR(data__->RMP,) != SEL__BYTE__BOOL__BYTE__BYTE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->DIR,),
    (BYTE)__BYTE_LITERAL(0),
    (BYTE)__BYTE_LITERAL(255)))) && EQ_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TR,), __GET_VAR(data__->TN,)))) {
    __SET_VAR(data__->,RMP,,FRMP_B(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->START,),
      (BOOL)__GET_VAR(data__->DIR,),
      (TIME)__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->TL,)),
      (TIME)__GET_VAR(data__->TR,)));
  } else {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,TL,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,TN,,__GET_VAR(data__->TR,));
    __SET_VAR(data__->,START,,__GET_VAR(data__->RMP,));
  };
  __SET_VAR(data__->,LAST_DIR,,__GET_VAR(data__->DIR,));

  goto __end;

__end:
  return;
} // _RMP_B_body__() 





void RMP_B_init__(RMP_B *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->SET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->_E,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->UP,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT,0,retain)
  __INIT_VAR(data__->BUSY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->HIGH,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LOW,__BOOL_LITERAL(FALSE),retain)
  _RMP_B_init__(&data__->RMP,retain);
}

// Code part
void RMP_B_body__(RMP_B *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->RMP.,DIR,,__GET_VAR(data__->UP,));
  __SET_VAR(data__->RMP.,_E,,__GET_VAR(data__->_E,));
  __SET_VAR(data__->RMP.,TR,,__GET_VAR(data__->PT,));
  __SET_VAR(data__->RMP.,RMP,,__GET_VAR(data__->OUT,));
  _RMP_B_body__(&data__->RMP);
  __SET_VAR(data__->,OUT,,__GET_VAR(data__->RMP.RMP));
  __SET_VAR(data__->,OUT,,__GET_VAR(data__->RMP.RMP,));
  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,OUT,,__BYTE_LITERAL(0));
  } else if (__GET_VAR(data__->SET,)) {
    __SET_VAR(data__->,OUT,,__BYTE_LITERAL(255));
  };
  __SET_VAR(data__->,LOW,,(__GET_VAR(data__->OUT,) == __BYTE_LITERAL(0)));
  __SET_VAR(data__->,HIGH,,(__GET_VAR(data__->OUT,) == __BYTE_LITERAL(255)));
  __SET_VAR(data__->,BUSY,,(!((__GET_VAR(data__->LOW,) || __GET_VAR(data__->HIGH,))) && __GET_VAR(data__->_E,)));

  goto __end;

__end:
  return;
} // RMP_B_body__() 





void CLICK_init__(CLICK *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->T_DEBOUNCE,__time_to_timespec(1, 10, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T_SHORT,__time_to_timespec(1, 200, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T_PAUSE,__time_to_timespec(1, 500, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T_RECONFIG,__time_to_timespec(1, 0, 0, 1, 0, 0),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SINGLE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DOUBLE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIPLE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATUS,0,retain)
  SW_RECONFIG_init__(&data__->S_IN,retain);
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
}

// Code part
void CLICK_body__(CLICK *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->S_IN.,IN,,__GET_VAR(data__->IN,));
  __SET_VAR(data__->S_IN.,TD,,__GET_VAR(data__->T_DEBOUNCE,));
  __SET_VAR(data__->S_IN.,TR,,__GET_VAR(data__->T_RECONFIG,));
  SW_RECONFIG_body__(&data__->S_IN);
  __SET_VAR(data__->,TX,,UDINT_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)T_PLC_MS(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__BOOL_LITERAL(FALSE))));
  if ((__GET_VAR(data__->S_IN.Q,) && !__GET_VAR(data__->Q,)) || (!__GET_VAR(data__->S_IN.Q,) && __GET_VAR(data__->Q,))) {
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    if (__GET_VAR(data__->S_IN.Q,)) {
      __SET_VAR(data__->,STATE,,(__GET_VAR(data__->STATE,) + 1));
    };
  };
  __SET_VAR(data__->,Q,,__GET_VAR(data__->S_IN.Q,));
  if ((__GET_VAR(data__->STATE,) > 0)) {
    if (((__GET_VAR(data__->Q,) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->T_SHORT,))) || (!(__GET_VAR(data__->Q,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->T_PAUSE,))))) {
      {
        INT __case_expression = __GET_VAR(data__->STATE,);
        if ((__case_expression == 1)) {
          __SET_VAR(data__->,SINGLE,,__BOOL_LITERAL(TRUE));
          __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(111));
        }
        else if ((__case_expression == 2)) {
          __SET_VAR(data__->,DOUBLE,,__BOOL_LITERAL(TRUE));
          __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(112));
        }
        else if ((__case_expression == 3)) {
          __SET_VAR(data__->,TRIPLE,,__BOOL_LITERAL(TRUE));
          __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(113));
        }
      };
      __SET_VAR(data__->,STATE,,0);
    };
  } else if (!(__GET_VAR(data__->Q,))) {
    __SET_VAR(data__->,SINGLE,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,DOUBLE,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,TRIPLE,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(110));
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,STATE,,0);
  };

  goto __end;

__end:
  return;
} // CLICK_body__() 





void DIMM_I_init__(DIMM_I *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->SET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VAL,255,retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->T_DEBOUNCE,__time_to_timespec(1, 10, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T_RECONFIG,__time_to_timespec(1, 0, 10, 0, 0, 0),retain)
  __INIT_VAR(data__->T_ON_MAX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T_DIMM_START,__time_to_timespec(1, 0, 1, 0, 0, 0),retain)
  __INIT_VAR(data__->T_DIMM,__time_to_timespec(1, 0, 3, 0, 0, 0),retain)
  __INIT_VAR(data__->MIN_ON,50,retain)
  __INIT_VAR(data__->MAX_ON,255,retain)
  __INIT_VAR(data__->RST_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SOFT_DIMM,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->DBL_TOGGLE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DBL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT,0,retain)
  TON_init__(&data__->T3,retain);
  SW_RECONFIG_init__(&data__->CONFIG,retain);
  CLICK_MODE_init__(&data__->DECODE,retain);
  _RMP_B_init__(&data__->DIM,retain);
  __INIT_VAR(data__->DIR,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void DIMM_I_body__(DIMM_I *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->CONFIG.,IN,,__GET_VAR(data__->IN,));
  __SET_VAR(data__->CONFIG.,TD,,__GET_VAR(data__->T_DEBOUNCE,));
  __SET_VAR(data__->CONFIG.,TR,,__GET_VAR(data__->T_RECONFIG,));
  SW_RECONFIG_body__(&data__->CONFIG);
  __SET_VAR(data__->DECODE.,IN,,__GET_VAR(data__->CONFIG.Q,));
  __SET_VAR(data__->DECODE.,T_LONG,,__GET_VAR(data__->T_DIMM_START,));
  CLICK_MODE_body__(&data__->DECODE);
  if (__GET_VAR(data__->RST,)) {
    if (__GET_VAR(data__->RST_OUT,)) {
      __SET_VAR(data__->,OUT,,__BYTE_LITERAL(0));
    };
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,DIR,,(__GET_VAR(data__->OUT,) > __BYTE_LITERAL(127)));
  } else if (__GET_VAR(data__->SET,)) {
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->VAL,));
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,DIR,,(__GET_VAR(data__->OUT,) > __BYTE_LITERAL(127)));
  } else if (__GET_VAR(data__->DECODE.SINGLE,)) {
    __SET_VAR(data__->,Q,,!(__GET_VAR(data__->Q,)));
    if (__GET_VAR(data__->Q,)) {
      __SET_VAR(data__->,OUT,,INT_TO_BYTE(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)LIMIT__INT__INT__INT__INT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (INT)MAX__INT__INT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (UINT)2,
            (INT)BYTE_TO_INT(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (BYTE)__GET_VAR(data__->MIN_ON,)),
            (INT)1),
          (INT)BYTE_TO_INT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (BYTE)__GET_VAR(data__->OUT,)),
          (INT)BYTE_TO_INT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (BYTE)__GET_VAR(data__->MAX_ON,)))));
    };
    __SET_VAR(data__->,DIR,,(__GET_VAR(data__->OUT,) > __BYTE_LITERAL(127)));
  } else if (__GET_VAR(data__->DECODE.TP_LONG,)) {
    if (!(__GET_VAR(data__->Q,))) {
      if (__GET_VAR(data__->SOFT_DIMM,)) {
        __SET_VAR(data__->,OUT,,__BYTE_LITERAL(1));
        __SET_VAR(data__->,DIR,,__BOOL_LITERAL(TRUE));
      } else {
        __SET_VAR(data__->,OUT,,INT_TO_BYTE(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (INT)LIMIT__INT__INT__INT__INT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (INT)MAX__INT__INT(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (UINT)2,
              (INT)BYTE_TO_INT(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (BYTE)__GET_VAR(data__->MIN_ON,)),
              (INT)1),
            (INT)BYTE_TO_INT(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (BYTE)__GET_VAR(data__->OUT,)),
            (INT)BYTE_TO_INT(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (BYTE)__GET_VAR(data__->MAX_ON,)))));
        __SET_VAR(data__->,DIR,,(__GET_VAR(data__->OUT,) < __BYTE_LITERAL(127)));
      };
      __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
    } else {
      __SET_VAR(data__->,DIR,,!(__GET_VAR(data__->DIR,)));
    };
  };
  if (!(__GET_VAR(data__->DBL_TOGGLE,))) {
    __SET_VAR(data__->,DBL,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->DECODE.DOUBLE,)) {
    __SET_VAR(data__->,DBL,,!(__GET_VAR(data__->DBL,)));
  };
  __SET_VAR(data__->DIM.,DIR,,__GET_VAR(data__->DIR,));
  __SET_VAR(data__->DIM.,_E,,(__GET_VAR(data__->DECODE.LONG,) && __GET_VAR(data__->Q,)));
  __SET_VAR(data__->DIM.,TR,,__GET_VAR(data__->T_DIMM,));
  __SET_VAR(data__->DIM.,RMP,,__GET_VAR(data__->OUT,));
  _RMP_B_body__(&data__->DIM);
  __SET_VAR(data__->,OUT,,__GET_VAR(data__->DIM.RMP));
  __SET_VAR(data__->,OUT,,__GET_VAR(data__->DIM.RMP,));
  if ((__GET_VAR(data__->OUT,) == __BYTE_LITERAL(0))) {
    __SET_VAR(data__->,DIR,,__BOOL_LITERAL(TRUE));
  } else if ((__GET_VAR(data__->OUT,) == __BYTE_LITERAL(255))) {
    __SET_VAR(data__->,DIR,,__BOOL_LITERAL(FALSE));
  };
  if (GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->T_ON_MAX,), __time_to_timespec(1, 0, 0, 0, 0, 0))) {
    __SET_VAR(data__->T3.,IN,,__GET_VAR(data__->Q,));
    __SET_VAR(data__->T3.,PT,,__GET_VAR(data__->T_ON_MAX,));
    TON_body__(&data__->T3);
    __SET_VAR(data__->,Q,,(__GET_VAR(data__->Q,) && !__GET_VAR(data__->T3.Q,)) || (!__GET_VAR(data__->Q,) && __GET_VAR(data__->T3.Q,)));
  };

  goto __end;

__end:
  return;
} // DIMM_I_body__() 





// FUNCTION
UDINT YEAR_END(
  BOOL EN, 
  BOOL *__ENO, 
  INT Y)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  UDINT YEAR_END = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return YEAR_END;
  }
  YEAR_END = (DWORD_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)SHR__DWORD__DWORD__SINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)UDINT_TO_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)((INT_TO_UDINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (INT)Y) * __UDINT_LITERAL(1461)) - __UDINT_LITERAL(2876712))),
      (SINT)2)) * __UDINT_LITERAL(86400));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return YEAR_END;
}


// FUNCTION
BOOL LEAP_DAY(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BOOL LEAP_DAY = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return LEAP_DAY;
  }
  LEAP_DAY = (((__UDINT_LITERAL(126230400) == 0)?0:(IDATE % __UDINT_LITERAL(126230400))) == __UDINT_LITERAL(68169600));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return LEAP_DAY;
}


// FUNCTION
INT DAY_OF_WEEK(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT DAY_OF_WEEK = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DAY_OF_WEEK;
  }
  DAY_OF_WEEK = (UDINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)((__UDINT_LITERAL(7) == 0)?0:(((IDATE / __UDINT_LITERAL(86400)) + __UDINT_LITERAL(3)) % __UDINT_LITERAL(7)))) + __INT_LITERAL(1));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return DAY_OF_WEEK;
}


// FUNCTION
UDINT _DT_TO_DATE(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  UDINT _DT_TO_DATE = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return _DT_TO_DATE;
  }
  _DT_TO_DATE = ((IN / __UDINT_LITERAL(86400)) * __UDINT_LITERAL(86400));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return _DT_TO_DATE;
}


// FUNCTION
INT YEAR_OF_DATE(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT YEAR_OF_DATE = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return YEAR_OF_DATE;
  }
  YEAR_OF_DATE = UDINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)(((IDATE + __UDINT_LITERAL(43200)) / __UDINT_LITERAL(31557600)) + __UDINT_LITERAL(1970)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return YEAR_OF_DATE;
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
UDINT DATE_TO_DT(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  UDINT DATE_TO_DT = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DATE_TO_DT;
  }
  DATE_TO_DT = IN;

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return DATE_TO_DT;
}


// FUNCTION
INT MONTH_OF_DATE(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT MONTH_OF_DATE = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return MONTH_OF_DATE;
  }
  MONTH_OF_DATE = DAY_OF_YEAR(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)IDATE);
  if ((MONTH_OF_DATE < 32)) {
    MONTH_OF_DATE = 1;
  } else if (LEAP_OF_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)IDATE)) {
    MONTH_OF_DATE = (((MONTH_OF_DATE * 53) + 1668) / 1623);
  } else {
    MONTH_OF_DATE = (((MONTH_OF_DATE * 53) + 1700) / 1620);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return MONTH_OF_DATE;
}


// FUNCTION
UDINT SET_DATE(
  BOOL EN, 
  BOOL *__ENO, 
  INT YEAR, 
  INT MONTH, 
  INT DAY)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT COUNT = 0;
  UDINT SET_DATE = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SET_DATE;
  }
  if ((MONTH > 2)) {
    COUNT = ((MONTH - 1) * 30);
    if ((MONTH > 7)) {
      COUNT = (COUNT + DWORD_TO_INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)SHR__DWORD__DWORD__SINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)DINT_TO_DWORD(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (DINT)(INT_TO_DINT(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (INT)MONTH) - INT_TO_DINT(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (INT)3))),
          (SINT)1)));
    } else {
      COUNT = (COUNT + DWORD_TO_INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)SHR__DWORD__DWORD__SINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DWORD)DINT_TO_DWORD(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (DINT)(INT_TO_DINT(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (INT)MONTH) - INT_TO_DINT(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (INT)4))),
          (SINT)1)));
    };
    if ((SHL__WORD__WORD__SINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (WORD)INT_TO_WORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)YEAR),
      (SINT)14) == __WORD_LITERAL(0))) {
      COUNT = (COUNT + 1);
    };
  } else {
    COUNT = ((MONTH - 1) * 31);
  };
  SET_DATE = ((INT_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)((COUNT + DAY) - 1)) + DWORD_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)SHR__DWORD__DWORD__SINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)UDINT_TO_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)((INT_TO_UDINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (INT)YEAR) * __UDINT_LITERAL(1461)) - __UDINT_LITERAL(2878169))),
      (SINT)2))) * __UDINT_LITERAL(86400));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SET_DATE;
}


// FUNCTION
UDINT MONTH_END(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  UDINT MONTH_END = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return MONTH_END;
  }
  MONTH_END = (SET_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)YEAR_OF_DATE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)IDATE),
    (INT)(MONTH_OF_DATE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)IDATE) + 1),
    (INT)1) - __UDINT_LITERAL(86400));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return MONTH_END;
}


void TIMER_P4_init__(TIMER_P4 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->DTIME,0,retain)
  __INIT_VAR(data__->TREF_0,0,retain)
  __INIT_VAR(data__->TREF_1,0,retain)
  __INIT_VAR(data__->HOLY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->L0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->L1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->L2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->L3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OFS,0,retain)
  __INIT_VAR(data__->ENQ,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MAN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MI,0,retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  {
    static const __ARRAY_OF_TIMER_EVENT_64 temp = {{{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0},{0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0}}};
    __SET_VAR(data__->,PROG,,temp);
  }
  __INIT_VAR(data__->Q0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATUS,0,retain)
  __INIT_VAR(data__->DAY_START,0,retain)
  __INIT_VAR(data__->START,0,retain)
  {
    static const TIMER_EVENT temp = {0,0,0,0,__time_to_timespec(1, 0, 0, 0, 0, 0),0,0,0};
    __SET_VAR(data__->,EVENT,,temp);
  }
  __INIT_VAR(data__->POS,0,retain)
  __INIT_VAR(data__->LAST_EXECUTE,0,retain)
  __INIT_VAR(data__->CURRENT_DAY,0,retain)
  __INIT_VAR(data__->MASK,0,retain)
  {
    static const __ARRAY_OF_BYTE_4 temp = {{0,0,0,0}};
    __SET_VAR(data__->,MA,,temp);
  }
  {
    static const __ARRAY_OF_BYTE_4 temp = {{0,0,0,0}};
    __SET_VAR(data__->,MO,,temp);
  }
  {
    static const __ARRAY_OF_BOOL_4 temp = {{__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE)}};
    __SET_VAR(data__->,QN,,temp);
  }
  {
    static const __ARRAY_OF_BOOL_4 temp = {{__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE)}};
    __SET_VAR(data__->,QS,,temp);
  }
  __INIT_VAR(data__->CHANNEL,0,retain)
  __INIT_VAR(data__->TX,0,retain)
  __INIT_VAR(data__->ARRAY_MAX,63,retain)
  __INIT_VAR(data__->CHANNEL_MAX,3,retain)
}

// Code part
void TIMER_P4_body__(TIMER_P4 *data__) {
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
    __SET_VAR(data__->,LAST_EXECUTE,,__UDINT_LITERAL(0));
    for(__GET_VAR(data__->POS,) = 0; __GET_VAR(data__->POS,) <= __GET_VAR(data__->ARRAY_MAX,); __GET_VAR(data__->POS,)++) {
      if (((__GET_VAR(data__->PROG,.table[(__GET_VAR(data__->POS,)) - (0)].CHANNEL) >= __GET_VAR(data__->OFS,)) && (BYTE_TO_INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->PROG,.table[(__GET_VAR(data__->POS,)) - (0)].CHANNEL)) < (BYTE_TO_INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->OFS,)) + 4)))) {
        __SET_VAR(data__->,PROG,.table[(__GET_VAR(data__->POS,)) - (0)].LAST,__GET_VAR(data__->LAST_EXECUTE,));
      };
    };
    for(__GET_VAR(data__->POS,) = 0; __GET_VAR(data__->POS,) <= __GET_VAR(data__->CHANNEL_MAX,); __GET_VAR(data__->POS,)++) {
      __SET_VAR(data__->,QS,.table[(__GET_VAR(data__->POS,)) - (0)],__BOOL_LITERAL(FALSE));
    };
  } else if ((__GET_VAR(data__->DTIME,) != __GET_VAR(data__->LAST_EXECUTE,))) {
    __SET_VAR(data__->,LAST_EXECUTE,,__GET_VAR(data__->DTIME,));
    __SET_VAR(data__->,DAY_START,,DATE_TO_DT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)_DT_TO_DATE(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)__GET_VAR(data__->DTIME,))));
    for(__GET_VAR(data__->POS,) = 0; __GET_VAR(data__->POS,) <= __GET_VAR(data__->CHANNEL_MAX,); __GET_VAR(data__->POS,)++) {
      __SET_VAR(data__->,QN,.table[(__GET_VAR(data__->POS,)) - (0)],__BOOL_LITERAL(FALSE));
    };
    for(__GET_VAR(data__->POS,) = 0; __GET_VAR(data__->POS,) <= __GET_VAR(data__->ARRAY_MAX,); __GET_VAR(data__->POS,)++) {
      __SET_VAR(data__->,EVENT,,__GET_VAR(data__->PROG,.table[(__GET_VAR(data__->POS,)) - (0)]));
      __SET_VAR(data__->,CHANNEL,,(BYTE_TO_INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->EVENT,.CHANNEL)) - BYTE_TO_INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->OFS,))));
      if ((((__GET_VAR(data__->EVENT,.TYP) > __BYTE_LITERAL(0)) && (__GET_VAR(data__->CHANNEL,) >= 0)) && (__GET_VAR(data__->CHANNEL,) <= __GET_VAR(data__->CHANNEL_MAX,)))) {
        __SET_VAR(data__->,MA,.table[(__GET_VAR(data__->CHANNEL,)) - (0)],__GET_VAR(data__->EVENT,.LAND));
        __SET_VAR(data__->,MO,.table[(__GET_VAR(data__->CHANNEL,)) - (0)],__GET_VAR(data__->EVENT,.LOR));
        {
          INT __case_expression = BYTE_TO_INT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (BYTE)__GET_VAR(data__->EVENT,.TYP));
          if ((__case_expression == 1)) {
            __SET_VAR(data__->,START,,(__GET_VAR(data__->DAY_START,) + __GET_VAR(data__->EVENT,.START)));
            __SET_VAR(data__->,QN,.table[(__GET_VAR(data__->CHANNEL,)) - (0)],((__GET_VAR(data__->DTIME,) >= __GET_VAR(data__->START,)) && (__GET_VAR(data__->DTIME,) <= (__GET_VAR(data__->START,) + TIME_TO_UDINT(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (TIME)__GET_VAR(data__->EVENT,.DURATION))))));
          }
          else if ((__case_expression == 2)) {
            if (((SHR__BYTE__BYTE__INT(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (BYTE)__BYTE_LITERAL(128),
              (INT)DAY_OF_WEEK(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (UDINT)_DT_TO_DATE(
                  (BOOL)__BOOL_LITERAL(TRUE),
                  NULL,
                  (UDINT)__GET_VAR(data__->DTIME,)))) & __GET_VAR(data__->EVENT,.DAY)) > __BYTE_LITERAL(0))) {
              __SET_VAR(data__->,START,,(__GET_VAR(data__->DAY_START,) + __GET_VAR(data__->EVENT,.START)));
              __SET_VAR(data__->,QN,.table[(__GET_VAR(data__->CHANNEL,)) - (0)],((__GET_VAR(data__->DTIME,) >= __GET_VAR(data__->START,)) && (__GET_VAR(data__->DTIME,) <= (__GET_VAR(data__->START,) + TIME_TO_UDINT(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (TIME)__GET_VAR(data__->EVENT,.DURATION))))));
            };
          }
          else if ((__case_expression == 3)) {
            if ((((BYTE_TO_DINT(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (BYTE)__GET_VAR(data__->EVENT,.DAY)) == 0)?0:(__GET_VAR(data__->CURRENT_DAY,) % BYTE_TO_DINT(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (BYTE)__GET_VAR(data__->EVENT,.DAY)))) == __DINT_LITERAL(0))) {
              __SET_VAR(data__->,START,,(__GET_VAR(data__->DAY_START,) + __GET_VAR(data__->EVENT,.START)));
              __SET_VAR(data__->,QN,.table[(__GET_VAR(data__->CHANNEL,)) - (0)],((__GET_VAR(data__->DTIME,) >= __GET_VAR(data__->START,)) && (__GET_VAR(data__->DTIME,) <= (__GET_VAR(data__->START,) + TIME_TO_UDINT(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (TIME)__GET_VAR(data__->EVENT,.DURATION))))));
            };
          }
          else if ((__case_expression == 10)) {
            if ((DAY_OF_WEEK(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (UDINT)_DT_TO_DATE(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (UDINT)__GET_VAR(data__->DTIME,))) == BYTE_TO_INT(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (BYTE)__GET_VAR(data__->EVENT,.DAY)))) {
              __SET_VAR(data__->,START,,(__GET_VAR(data__->DAY_START,) + __GET_VAR(data__->EVENT,.START)));
              __SET_VAR(data__->,QN,.table[(__GET_VAR(data__->CHANNEL,)) - (0)],((__GET_VAR(data__->DTIME,) >= __GET_VAR(data__->START,)) && (__GET_VAR(data__->DTIME,) <= (__GET_VAR(data__->START,) + TIME_TO_UDINT(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (TIME)__GET_VAR(data__->EVENT,.DURATION))))));
            };
          }
          else if ((__case_expression == 20)) {
            if ((DAY_OF_MONTH(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (UDINT)_DT_TO_DATE(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (UDINT)__GET_VAR(data__->DTIME,))) == BYTE_TO_INT(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (BYTE)__GET_VAR(data__->EVENT,.DAY)))) {
              __SET_VAR(data__->,START,,(__GET_VAR(data__->DAY_START,) + __GET_VAR(data__->EVENT,.START)));
              __SET_VAR(data__->,QN,.table[(__GET_VAR(data__->CHANNEL,)) - (0)],((__GET_VAR(data__->DTIME,) >= __GET_VAR(data__->START,)) && (__GET_VAR(data__->DTIME,) <= (__GET_VAR(data__->START,) + TIME_TO_UDINT(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (TIME)__GET_VAR(data__->EVENT,.DURATION))))));
            };
          }
          else if ((__case_expression == 21)) {
            if ((_DT_TO_DATE(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (UDINT)__GET_VAR(data__->DTIME,)) == MONTH_END(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (UDINT)_DT_TO_DATE(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (UDINT)__GET_VAR(data__->DTIME,))))) {
              __SET_VAR(data__->,START,,(__GET_VAR(data__->DAY_START,) + __GET_VAR(data__->EVENT,.START)));
              __SET_VAR(data__->,QN,.table[(__GET_VAR(data__->CHANNEL,)) - (0)],((__GET_VAR(data__->DTIME,) >= __GET_VAR(data__->START,)) && (__GET_VAR(data__->DTIME,) <= (__GET_VAR(data__->START,) + TIME_TO_UDINT(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (TIME)__GET_VAR(data__->EVENT,.DURATION))))));
            };
          }
          else if ((__case_expression == 30)) {
            if ((DAY_OF_YEAR(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (UDINT)_DT_TO_DATE(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (UDINT)__GET_VAR(data__->DTIME,))) == BYTE_TO_INT(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (BYTE)__GET_VAR(data__->EVENT,.DAY)))) {
              __SET_VAR(data__->,START,,(__GET_VAR(data__->DAY_START,) + __GET_VAR(data__->EVENT,.START)));
              __SET_VAR(data__->,QN,.table[(__GET_VAR(data__->CHANNEL,)) - (0)],((__GET_VAR(data__->DTIME,) >= __GET_VAR(data__->START,)) && (__GET_VAR(data__->DTIME,) <= (__GET_VAR(data__->START,) + TIME_TO_UDINT(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (TIME)__GET_VAR(data__->EVENT,.DURATION))))));
            };
          }
          else if ((__case_expression == 31)) {
            if ((_DT_TO_DATE(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (UDINT)__GET_VAR(data__->DTIME,)) == YEAR_END(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (INT)YEAR_OF_DATE(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (UDINT)_DT_TO_DATE(
                  (BOOL)__BOOL_LITERAL(TRUE),
                  NULL,
                  (UDINT)__GET_VAR(data__->DTIME,)))))) {
              __SET_VAR(data__->,START,,(__GET_VAR(data__->DAY_START,) + __GET_VAR(data__->EVENT,.START)));
              __SET_VAR(data__->,QN,.table[(__GET_VAR(data__->CHANNEL,)) - (0)],((__GET_VAR(data__->DTIME,) >= __GET_VAR(data__->START,)) && (__GET_VAR(data__->DTIME,) <= (__GET_VAR(data__->START,) + TIME_TO_UDINT(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (TIME)__GET_VAR(data__->EVENT,.DURATION))))));
            };
          }
          else if ((__case_expression == 40)) {
            if (LEAP_DAY(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (UDINT)_DT_TO_DATE(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (UDINT)__GET_VAR(data__->DTIME,)))) {
              __SET_VAR(data__->,START,,(__GET_VAR(data__->DAY_START,) + __GET_VAR(data__->EVENT,.START)));
              __SET_VAR(data__->,QN,.table[(__GET_VAR(data__->CHANNEL,)) - (0)],((__GET_VAR(data__->DTIME,) >= __GET_VAR(data__->START,)) && (__GET_VAR(data__->DTIME,) <= (__GET_VAR(data__->START,) + TIME_TO_UDINT(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (TIME)__GET_VAR(data__->EVENT,.DURATION))))));
            };
          }
          else if ((__case_expression == 41)) {
            if (__GET_VAR(data__->HOLY,)) {
              __SET_VAR(data__->,START,,(__GET_VAR(data__->DAY_START,) + __GET_VAR(data__->EVENT,.START)));
              __SET_VAR(data__->,QN,.table[(__GET_VAR(data__->CHANNEL,)) - (0)],((__GET_VAR(data__->DTIME,) >= __GET_VAR(data__->START,)) && (__GET_VAR(data__->DTIME,) <= (__GET_VAR(data__->START,) + TIME_TO_UDINT(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (TIME)__GET_VAR(data__->EVENT,.DURATION))))));
            };
          }
          else if ((__case_expression == 42)) {
            if (((__GET_VAR(data__->HOLY,) || (DAY_OF_WEEK(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (UDINT)_DT_TO_DATE(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (UDINT)__GET_VAR(data__->DTIME,))) == 6)) || (DAY_OF_WEEK(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (UDINT)_DT_TO_DATE(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (UDINT)__GET_VAR(data__->DTIME,))) == 7))) {
              __SET_VAR(data__->,START,,(__GET_VAR(data__->DAY_START,) + __GET_VAR(data__->EVENT,.START)));
              __SET_VAR(data__->,QN,.table[(__GET_VAR(data__->CHANNEL,)) - (0)],((__GET_VAR(data__->DTIME,) >= __GET_VAR(data__->START,)) && (__GET_VAR(data__->DTIME,) <= (__GET_VAR(data__->START,) + TIME_TO_UDINT(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (TIME)__GET_VAR(data__->EVENT,.DURATION))))));
            };
          }
          else if ((__case_expression == 43)) {
            if ((DAY_OF_WEEK(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (UDINT)_DT_TO_DATE(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (UDINT)__GET_VAR(data__->DTIME,))) < 6)) {
              __SET_VAR(data__->,START,,(__GET_VAR(data__->DAY_START,) + __GET_VAR(data__->EVENT,.START)));
              __SET_VAR(data__->,QN,.table[(__GET_VAR(data__->CHANNEL,)) - (0)],((__GET_VAR(data__->DTIME,) >= __GET_VAR(data__->START,)) && (__GET_VAR(data__->DTIME,) <= (__GET_VAR(data__->START,) + TIME_TO_UDINT(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (TIME)__GET_VAR(data__->EVENT,.DURATION))))));
            };
          }
          else if ((__case_expression == 50)) {
            {
              INT __case_expression = BYTE_TO_INT(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (BYTE)__GET_VAR(data__->PROG,.table[(__GET_VAR(data__->POS,)) - (0)].DAY));
              if ((__case_expression == 0)) {
                __SET_VAR(data__->,TX,,__GET_VAR(data__->TREF_0,));
              }
              else if ((__case_expression == 1)) {
                __SET_VAR(data__->,TX,,__GET_VAR(data__->TREF_1,));
              }
              else {
                __SET_VAR(data__->,TX,,__UDINT_LITERAL(0));
              }
            };
            __SET_VAR(data__->,START,,((__GET_VAR(data__->DAY_START,) + __GET_VAR(data__->TX,)) + __GET_VAR(data__->EVENT,.START)));
            __SET_VAR(data__->,QN,.table[(__GET_VAR(data__->CHANNEL,)) - (0)],((__GET_VAR(data__->DTIME,) >= __GET_VAR(data__->START,)) && (__GET_VAR(data__->DTIME,) <= (__GET_VAR(data__->START,) + TIME_TO_UDINT(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (TIME)__GET_VAR(data__->EVENT,.DURATION))))));
          }
          else if ((__case_expression == 51)) {
            {
              INT __case_expression = BYTE_TO_INT(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (BYTE)__GET_VAR(data__->PROG,.table[(__GET_VAR(data__->POS,)) - (0)].DAY));
              if ((__case_expression == 0)) {
                __SET_VAR(data__->,TX,,__GET_VAR(data__->TREF_0,));
              }
              else if ((__case_expression == 1)) {
                __SET_VAR(data__->,TX,,__GET_VAR(data__->TREF_1,));
              }
              else {
                __SET_VAR(data__->,TX,,__UDINT_LITERAL(0));
              }
            };
            __SET_VAR(data__->,START,,((__GET_VAR(data__->DAY_START,) + __GET_VAR(data__->TX,)) - __GET_VAR(data__->EVENT,.START)));
            __SET_VAR(data__->,QN,.table[(__GET_VAR(data__->CHANNEL,)) - (0)],((__GET_VAR(data__->DTIME,) >= __GET_VAR(data__->START,)) && (__GET_VAR(data__->DTIME,) <= (__GET_VAR(data__->START,) + TIME_TO_UDINT(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (TIME)__GET_VAR(data__->EVENT,.DURATION))))));
          }
          else if ((__case_expression == 52)) {
            {
              INT __case_expression = BYTE_TO_INT(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (BYTE)__GET_VAR(data__->PROG,.table[(__GET_VAR(data__->POS,)) - (0)].DAY));
              if ((__case_expression == 0)) {
                __SET_VAR(data__->,TX,,__GET_VAR(data__->TREF_0,));
              }
              else if ((__case_expression == 1)) {
                __SET_VAR(data__->,TX,,__GET_VAR(data__->TREF_1,));
              }
              else {
                __SET_VAR(data__->,TX,,__UDINT_LITERAL(0));
              }
            };
            __SET_VAR(data__->,START,,((__GET_VAR(data__->DAY_START,) + __GET_VAR(data__->TX,)) + __GET_VAR(data__->EVENT,.START)));
            if (((__GET_VAR(data__->DTIME,) >= __GET_VAR(data__->START,)) && (__GET_VAR(data__->DAY_START,) > __GET_VAR(data__->EVENT,.LAST)))) {
              __SET_VAR(data__->,QS,.table[(__GET_VAR(data__->CHANNEL,)) - (0)],__BOOL_LITERAL(TRUE));
              __SET_VAR(data__->,PROG,.table[(__GET_VAR(data__->POS,)) - (0)].LAST,__GET_VAR(data__->DAY_START,));
            };
          }
          else if ((__case_expression == 53)) {
            {
              INT __case_expression = BYTE_TO_INT(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (BYTE)__GET_VAR(data__->PROG,.table[(__GET_VAR(data__->POS,)) - (0)].DAY));
              if ((__case_expression == 0)) {
                __SET_VAR(data__->,TX,,__GET_VAR(data__->TREF_0,));
              }
              else if ((__case_expression == 1)) {
                __SET_VAR(data__->,TX,,__GET_VAR(data__->TREF_1,));
              }
              else {
                __SET_VAR(data__->,TX,,__UDINT_LITERAL(0));
              }
            };
            __SET_VAR(data__->,START,,((__GET_VAR(data__->DAY_START,) + __GET_VAR(data__->TX,)) + __GET_VAR(data__->EVENT,.START)));
            if (((__GET_VAR(data__->DTIME,) >= __GET_VAR(data__->START,)) && (__GET_VAR(data__->DAY_START,) > __GET_VAR(data__->EVENT,.LAST)))) {
              __SET_VAR(data__->,QS,.table[(__GET_VAR(data__->CHANNEL,)) - (0)],__BOOL_LITERAL(FALSE));
              __SET_VAR(data__->,PROG,.table[(__GET_VAR(data__->POS,)) - (0)].LAST,__GET_VAR(data__->DAY_START,));
            };
          }
          else if ((__case_expression == 54)) {
            {
              INT __case_expression = BYTE_TO_INT(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (BYTE)__GET_VAR(data__->PROG,.table[(__GET_VAR(data__->POS,)) - (0)].DAY));
              if ((__case_expression == 0)) {
                __SET_VAR(data__->,TX,,__GET_VAR(data__->TREF_0,));
              }
              else if ((__case_expression == 1)) {
                __SET_VAR(data__->,TX,,__GET_VAR(data__->TREF_1,));
              }
              else {
                __SET_VAR(data__->,TX,,__UDINT_LITERAL(0));
              }
            };
            __SET_VAR(data__->,START,,((__GET_VAR(data__->DAY_START,) + __GET_VAR(data__->TX,)) - __GET_VAR(data__->EVENT,.START)));
            if (((__GET_VAR(data__->DTIME,) >= __GET_VAR(data__->START,)) && (__GET_VAR(data__->DAY_START,) > __GET_VAR(data__->EVENT,.LAST)))) {
              __SET_VAR(data__->,QS,.table[(__GET_VAR(data__->CHANNEL,)) - (0)],__BOOL_LITERAL(TRUE));
              __SET_VAR(data__->,PROG,.table[(__GET_VAR(data__->POS,)) - (0)].LAST,__GET_VAR(data__->DAY_START,));
            };
          }
          else if ((__case_expression == 55)) {
            {
              INT __case_expression = BYTE_TO_INT(
                (BOOL)__BOOL_LITERAL(TRUE),
                NULL,
                (BYTE)__GET_VAR(data__->PROG,.table[(__GET_VAR(data__->POS,)) - (0)].DAY));
              if ((__case_expression == 0)) {
                __SET_VAR(data__->,TX,,__GET_VAR(data__->TREF_0,));
              }
              else if ((__case_expression == 1)) {
                __SET_VAR(data__->,TX,,__GET_VAR(data__->TREF_1,));
              }
              else {
                __SET_VAR(data__->,TX,,__UDINT_LITERAL(0));
              }
            };
            __SET_VAR(data__->,START,,((__GET_VAR(data__->DAY_START,) + __GET_VAR(data__->TX,)) - __GET_VAR(data__->EVENT,.START)));
            if (((__GET_VAR(data__->DTIME,) >= __GET_VAR(data__->START,)) && (__GET_VAR(data__->DAY_START,) > __GET_VAR(data__->EVENT,.LAST)))) {
              __SET_VAR(data__->,QS,.table[(__GET_VAR(data__->CHANNEL,)) - (0)],__BOOL_LITERAL(FALSE));
              __SET_VAR(data__->,PROG,.table[(__GET_VAR(data__->POS,)) - (0)].LAST,__GET_VAR(data__->DAY_START,));
            };
          }
        };
      };
    };
  };
  __SET_VAR(data__->,MASK,,__BYTE_LITERAL(255));
  __SET_VAR(data__->,MASK,,BIT_LOAD_B(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)__GET_VAR(data__->MASK,),
    (BOOL)__GET_VAR(data__->L0,),
    (INT)0));
  __SET_VAR(data__->,MASK,,BIT_LOAD_B(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)__GET_VAR(data__->MASK,),
    (BOOL)__GET_VAR(data__->L1,),
    (INT)1));
  __SET_VAR(data__->,MASK,,BIT_LOAD_B(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)__GET_VAR(data__->MASK,),
    (BOOL)__GET_VAR(data__->L2,),
    (INT)2));
  __SET_VAR(data__->,MASK,,BIT_LOAD_B(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)__GET_VAR(data__->MASK,),
    (BOOL)__GET_VAR(data__->L3,),
    (INT)3));
  __SET_VAR(data__->,Q0,,(__GET_VAR(data__->ENQ,) && ((((__GET_VAR(data__->QN,.table[(0) - (0)]) || __GET_VAR(data__->QS,.table[(0) - (0)])) && ((__GET_VAR(data__->MA,.table[(0) - (0)]) & __GET_VAR(data__->MASK,)) == __GET_VAR(data__->MA,.table[(0) - (0)]))) || ((__GET_VAR(data__->MO,.table[(0) - (0)]) & __GET_VAR(data__->MASK,)) > __BYTE_LITERAL(0))) || (__GET_VAR(data__->MAN,) && BIT_OF_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)BYTE_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->MI,)),
    (INT)0)))));
  __SET_VAR(data__->,Q1,,(__GET_VAR(data__->ENQ,) && ((((__GET_VAR(data__->QN,.table[(1) - (0)]) || __GET_VAR(data__->QS,.table[(1) - (0)])) && ((__GET_VAR(data__->MA,.table[(1) - (0)]) & __GET_VAR(data__->MASK,)) == __GET_VAR(data__->MA,.table[(1) - (0)]))) || ((__GET_VAR(data__->MO,.table[(1) - (0)]) & __GET_VAR(data__->MASK,)) > __BYTE_LITERAL(1))) || (__GET_VAR(data__->MAN,) && BIT_OF_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)BYTE_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->MI,)),
    (INT)1)))));
  __SET_VAR(data__->,Q2,,(__GET_VAR(data__->ENQ,) && ((((__GET_VAR(data__->QN,.table[(2) - (0)]) || __GET_VAR(data__->QS,.table[(2) - (0)])) && ((__GET_VAR(data__->MA,.table[(2) - (0)]) & __GET_VAR(data__->MASK,)) == __GET_VAR(data__->MA,.table[(2) - (0)]))) || ((__GET_VAR(data__->MO,.table[(2) - (0)]) & __GET_VAR(data__->MASK,)) > __BYTE_LITERAL(2))) || (__GET_VAR(data__->MAN,) && BIT_OF_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)BYTE_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->MI,)),
    (INT)2)))));
  __SET_VAR(data__->,Q3,,(__GET_VAR(data__->ENQ,) && ((((__GET_VAR(data__->QN,.table[(3) - (0)]) || __GET_VAR(data__->QS,.table[(3) - (0)])) && ((__GET_VAR(data__->MA,.table[(3) - (0)]) & __GET_VAR(data__->MASK,)) == __GET_VAR(data__->MA,.table[(3) - (0)]))) || ((__GET_VAR(data__->MO,.table[(3) - (0)]) & __GET_VAR(data__->MASK,)) > __BYTE_LITERAL(3))) || (__GET_VAR(data__->MAN,) && BIT_OF_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)BYTE_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->MI,)),
    (INT)3)))));
  if (!(__GET_VAR(data__->ENQ,))) {
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(100));
  } else if (__GET_VAR(data__->MAN,)) {
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(101));
  } else {
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(102));
  };

  goto __end;

__end:
  return;
} // TIMER_P4_body__() 





void DIMM_2_init__(DIMM_2 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->SET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VAL,255,retain)
  __INIT_VAR(data__->I1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->I2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->T_DEBOUNCE,__time_to_timespec(1, 10, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T_ON_MAX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T_DIMM_START,__time_to_timespec(1, 0, 1, 0, 0, 0),retain)
  __INIT_VAR(data__->T_DIMM,__time_to_timespec(1, 0, 3, 0, 0, 0),retain)
  __INIT_VAR(data__->MIN_ON,50,retain)
  __INIT_VAR(data__->MAX_ON,255,retain)
  __INIT_VAR(data__->RST_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SOFT_DIMM,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->DBL1_TOG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DBL2_TOG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DBL1_SET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DBL2_SET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DBL1_POS,0,retain)
  __INIT_VAR(data__->DBL2_POS,0,retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->D1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->D2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT,0,retain)
  TOF_init__(&data__->T1,retain);
  TOF_init__(&data__->T2,retain);
  TON_init__(&data__->T3,retain);
  CLICK_MODE_init__(&data__->DC1,retain);
  CLICK_MODE_init__(&data__->DC2,retain);
  _RMP_B_init__(&data__->DIM,retain);
}

// Code part
void DIMM_2_body__(DIMM_2 *data__) {
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
  __SET_VAR(data__->T1.,PT,,__GET_VAR(data__->T_DEBOUNCE,));
  TOF_body__(&data__->T1);
  __SET_VAR(data__->T2.,IN,,__GET_VAR(data__->I2,));
  __SET_VAR(data__->T2.,PT,,__GET_VAR(data__->T_DEBOUNCE,));
  TOF_body__(&data__->T2);
  __SET_VAR(data__->DC1.,IN,,__GET_VAR(data__->T1.Q,));
  __SET_VAR(data__->DC1.,T_LONG,,__GET_VAR(data__->T_DIMM_START,));
  CLICK_MODE_body__(&data__->DC1);
  __SET_VAR(data__->DC2.,IN,,__GET_VAR(data__->T2.Q,));
  __SET_VAR(data__->DC2.,T_LONG,,__GET_VAR(data__->T_DIMM_START,));
  CLICK_MODE_body__(&data__->DC2);
  if (__GET_VAR(data__->RST,)) {
    if (__GET_VAR(data__->RST_OUT,)) {
      __SET_VAR(data__->,OUT,,__BYTE_LITERAL(0));
    };
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,D1,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,D2,,__BOOL_LITERAL(FALSE));
  } else if (__GET_VAR(data__->SET,)) {
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->VAL,));
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
  } else if (__GET_VAR(data__->DC1.SINGLE,)) {
    __SET_VAR(data__->,OUT,,LIMIT__BYTE__BYTE__BYTE__BYTE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)MAX__BYTE__BYTE(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UINT)2,
        (BYTE)__GET_VAR(data__->MIN_ON,),
        (BYTE)__BYTE_LITERAL(1)),
      (BYTE)__GET_VAR(data__->OUT,),
      (BYTE)__GET_VAR(data__->MAX_ON,)));
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
  } else if (__GET_VAR(data__->DC2.SINGLE,)) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  } else if (__GET_VAR(data__->DC1.TP_LONG,)) {
    if (!(__GET_VAR(data__->Q,))) {
      __SET_VAR(data__->,OUT,,SEL__BYTE__BOOL__BYTE__BYTE(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BOOL)__GET_VAR(data__->SOFT_DIMM,),
        (BYTE)LIMIT__BYTE__BYTE__BYTE__BYTE(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)MAX__BYTE__BYTE(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (UINT)2,
            (BYTE)__GET_VAR(data__->MIN_ON,),
            (BYTE)__BYTE_LITERAL(1)),
          (BYTE)__GET_VAR(data__->OUT,),
          (BYTE)__GET_VAR(data__->MAX_ON,)),
        (BYTE)__BYTE_LITERAL(1)));
    };
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,DIM.DIR,,__BOOL_LITERAL(TRUE));
  } else if (__GET_VAR(data__->DC2.TP_LONG,)) {
    __SET_VAR(data__->,DIM.DIR,,__BOOL_LITERAL(FALSE));
  };
  if (!(__GET_VAR(data__->DBL1_TOG,))) {
    __SET_VAR(data__->,D1,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->DC1.DOUBLE,)) {
    if (__GET_VAR(data__->DBL1_SET,)) {
      __SET_VAR(data__->,OUT,,__GET_VAR(data__->DBL1_POS,));
      __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
    } else {
      __SET_VAR(data__->,D1,,!(__GET_VAR(data__->D1,)));
    };
  };
  if (!(__GET_VAR(data__->DBL2_TOG,))) {
    __SET_VAR(data__->,D2,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->DC2.DOUBLE,)) {
    if (__GET_VAR(data__->DBL2_SET,)) {
      __SET_VAR(data__->,OUT,,__GET_VAR(data__->DBL2_POS,));
      __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
    } else {
      __SET_VAR(data__->,D2,,!(__GET_VAR(data__->D2,)));
    };
  };
  __SET_VAR(data__->DIM.,DIR,,__GET_VAR(data__->DC2.LONG,));
  __SET_VAR(data__->DIM.,_E,,(__GET_VAR(data__->DC1.LONG,) || __GET_VAR(data__->DC2.LONG,)));
  __SET_VAR(data__->DIM.,TR,,__GET_VAR(data__->T_DIMM,));
  __SET_VAR(data__->DIM.,RMP,,__GET_VAR(data__->OUT,));
  _RMP_B_body__(&data__->DIM);
  __SET_VAR(data__->,OUT,,__GET_VAR(data__->DIM.RMP));
  __SET_VAR(data__->,OUT,,__GET_VAR(data__->DIM.RMP,));
  if ((__GET_VAR(data__->OUT,) == __BYTE_LITERAL(0))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  };
  if (GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->T_ON_MAX,), __time_to_timespec(1, 0, 0, 0, 0, 0))) {
    __SET_VAR(data__->T3.,IN,,__GET_VAR(data__->Q,));
    __SET_VAR(data__->T3.,PT,,__GET_VAR(data__->T_ON_MAX,));
    TON_body__(&data__->T3);
    __SET_VAR(data__->,Q,,(__GET_VAR(data__->Q,) && !__GET_VAR(data__->T3.Q,)) || (!__GET_VAR(data__->Q,) && __GET_VAR(data__->T3.Q,)));
  };

  goto __end;

__end:
  return;
} // DIMM_2_body__() 





// FUNCTION
UDINT DT_TO_DATE_2(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  UDINT DT_TO_DATE_2 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DT_TO_DATE_2;
  }
  DT_TO_DATE_2 = ((IN / __UDINT_LITERAL(86400)) * __UDINT_LITERAL(86400));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return DT_TO_DATE_2;
}


void ONTIME_init__(ONTIME *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SECONDS,0,retain)
  __INIT_VAR(data__->CYCLES,0,retain)
  __INIT_VAR(data__->TX,0,retain)
  __INIT_VAR(data__->LAST,0,retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MS,0,retain)
}

// Code part
void ONTIME_body__(ONTIME *data__) {
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
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,MS,,__UDINT_LITERAL(0));
  };
  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,SECONDS,,__UDINT_LITERAL(0));
    __SET_VAR(data__->,CYCLES,,__UDINT_LITERAL(0));
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,MS,,__UDINT_LITERAL(0));
  } else if (__GET_VAR(data__->IN,)) {
    __SET_VAR(data__->,MS,,((__GET_VAR(data__->TX,) - __GET_VAR(data__->LAST,)) + __GET_VAR(data__->MS,)));
    if ((__GET_VAR(data__->MS,) >= __UDINT_LITERAL(1000))) {
      __SET_VAR(data__->,SECONDS,,(__GET_VAR(data__->SECONDS,) + __UDINT_LITERAL(1)));
      __SET_VAR(data__->,MS,,(__GET_VAR(data__->MS,) - __UDINT_LITERAL(1000)));
    };
    __SET_VAR(data__->,CYCLES,,(__GET_VAR(data__->CYCLES,) + BOOL_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)!(__GET_VAR(data__->EDGE,)))));
  };
  __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->IN,));

  goto __end;

__end:
  return;
} // ONTIME_body__() 





void ACTUATOR_PUMP_init__(ACTUATOR_PUMP *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MANUAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MIN_ONTIME,__time_to_timespec(1, 0, 10, 0, 0, 0),retain)
  __INIT_VAR(data__->MIN_OFFTIME,__time_to_timespec(1, 0, 10, 0, 0, 0),retain)
  __INIT_VAR(data__->RUN_EVERY,__time_to_timespec(1, 0, 0, 10000, 0, 0),retain)
  __INIT_VAR(data__->PUMP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RUNTIME,0,retain)
  __INIT_VAR(data__->CYCLES,0,retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->LAST_CHANGE,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  ONTIME_init__(&data__->METER,retain);
  __INIT_VAR(data__->OLD_MAN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void ACTUATOR_PUMP_body__(ACTUATOR_PUMP *data__) {
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
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,LAST_CHANGE,,__GET_VAR(data__->TX,));
  } else if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,RST,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,RUNTIME,,__UDINT_LITERAL(0));
    __SET_VAR(data__->,CYCLES,,__UDINT_LITERAL(0));
  } else if (((__GET_VAR(data__->MANUAL,) && !(__GET_VAR(data__->PUMP,))) && !(__GET_VAR(data__->OLD_MAN,)))) {
    __SET_VAR(data__->,LAST_CHANGE,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,PUMP,,__BOOL_LITERAL(TRUE));
  } else if ((((!(__GET_VAR(data__->MANUAL,)) && __GET_VAR(data__->OLD_MAN,)) && __GET_VAR(data__->PUMP,)) && !(__GET_VAR(data__->IN,)))) {
    __SET_VAR(data__->,LAST_CHANGE,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,PUMP,,__BOOL_LITERAL(FALSE));
  } else if (((__GET_VAR(data__->IN,) && !(__GET_VAR(data__->PUMP,))) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST_CHANGE,)), __GET_VAR(data__->MIN_OFFTIME,)))) {
    __SET_VAR(data__->,LAST_CHANGE,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,PUMP,,__BOOL_LITERAL(TRUE));
  } else if ((((__GET_VAR(data__->PUMP,) && !(__GET_VAR(data__->IN,))) && !(__GET_VAR(data__->MANUAL,))) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST_CHANGE,)), __GET_VAR(data__->MIN_ONTIME,)))) {
    __SET_VAR(data__->,LAST_CHANGE,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,PUMP,,__BOOL_LITERAL(FALSE));
  } else if (((!(__GET_VAR(data__->PUMP,)) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST_CHANGE,)), __GET_VAR(data__->RUN_EVERY,))) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->RUN_EVERY,), __time_to_timespec(1, 0, 0, 0, 0, 0)))) {
    __SET_VAR(data__->,LAST_CHANGE,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,PUMP,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->METER.,IN,,__GET_VAR(data__->PUMP,));
  __SET_VAR(data__->METER.,SECONDS,,__GET_VAR(data__->RUNTIME,));
  __SET_VAR(data__->METER.,CYCLES,,__GET_VAR(data__->CYCLES,));
  ONTIME_body__(&data__->METER);
  __SET_VAR(data__->,RUNTIME,,__GET_VAR(data__->METER.SECONDS));
  __SET_VAR(data__->,CYCLES,,__GET_VAR(data__->METER.CYCLES));
  __SET_VAR(data__->,CYCLES,,__GET_VAR(data__->METER.CYCLES,));
  __SET_VAR(data__->,RUNTIME,,__GET_VAR(data__->METER.SECONDS,));
  __SET_VAR(data__->,OLD_MAN,,__GET_VAR(data__->MANUAL,));

  goto __end;

__end:
  return;
} // ACTUATOR_PUMP_body__() 





// FUNCTION
TIME TOD_TO_TIME(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  TIME TOD_TO_TIME = __time_to_timespec(1, 0, 0, 0, 0, 0);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return TOD_TO_TIME;
  }
  TOD_TO_TIME = DWORD_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)UDINT_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)IN));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return TOD_TO_TIME;
}


void ACTUATOR_COIL_init__(ACTUATOR_COIL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SELF_ACT_CYCLE,__time_to_timespec(1, 0, 0, 0, 0, 10),retain)
  __INIT_VAR(data__->SELF_ACT_TIME,__time_to_timespec(1, 0, 1, 0, 0, 0),retain)
  __INIT_VAR(data__->OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATUS,0,retain)
  __INIT_VAR(data__->LAST,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TX,0,retain)
  __INIT_VAR(data__->NOW,0,retain)
}

// Code part
void ACTUATOR_COIL_body__(ACTUATOR_COIL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,NOW,,T_PLC_MS(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__BOOL_LITERAL(FALSE)));
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->NOW,));
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
  } else if (__GET_VAR(data__->IN,)) {
    __SET_VAR(data__->,OUT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(101));
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->NOW,));
  } else {
    __SET_VAR(data__->,OUT,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(100));
    __SET_VAR(data__->,TX,,(__GET_VAR(data__->NOW,) - __GET_VAR(data__->LAST,)));
    if ((GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->SELF_ACT_CYCLE,), __time_to_timespec(1, 0, 0, 0, 0, 0)) && (__GET_VAR(data__->TX,) >= TIME_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)__GET_VAR(data__->SELF_ACT_CYCLE,))))) {
      __SET_VAR(data__->,OUT,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(102));
      if ((__GET_VAR(data__->TX,) >= TIME_TO_UDINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (TIME)__time_add(__GET_VAR(data__->SELF_ACT_CYCLE,), __GET_VAR(data__->SELF_ACT_TIME,))))) {
        __SET_VAR(data__->,LAST,,__GET_VAR(data__->NOW,));
        __SET_VAR(data__->,OUT,,__BOOL_LITERAL(FALSE));
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(100));
      };
    };
  };

  goto __end;

__end:
  return;
} // ACTUATOR_COIL_body__() 





void TONOF_init__(TONOF *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->T_ON,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T_OFF,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->X,retain);
  __INIT_VAR(data__->OLD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MODE,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void TONOF_body__(TONOF *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->IN,) && !__GET_VAR(data__->OLD,)) || (!__GET_VAR(data__->IN,) && __GET_VAR(data__->OLD,))) {
    __SET_VAR(data__->X.,IN,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->X.,PT,,SEL__TIME__BOOL__TIME__TIME(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__GET_VAR(data__->IN,),
      (TIME)__GET_VAR(data__->T_OFF,),
      (TIME)__GET_VAR(data__->T_ON,)));
    TON_body__(&data__->X);
    __SET_VAR(data__->,MODE,,__GET_VAR(data__->IN,));
    __SET_VAR(data__->,OLD,,__GET_VAR(data__->IN,));
  };
  __SET_VAR(data__->X.,IN,,__BOOL_LITERAL(TRUE));
  TON_body__(&data__->X);
  if (__GET_VAR(data__->X.Q,)) {
    __SET_VAR(data__->,Q,,__GET_VAR(data__->MODE,));
  };

  goto __end;

__end:
  return;
} // TONOF_body__() 





void TANK_LEVEL_init__(TANK_LEVEL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->LEVEL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LEAK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ACLR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MAX_VALVE_TIME,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->LEVEL_DELAY_TIME,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->VALVE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ALARM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATUS,0,retain)
  ACTUATOR_COIL_init__(&data__->CX,retain);
  TON_init__(&data__->TN,retain);
  TONOF_init__(&data__->TL,retain);
  __INIT_VAR(data__->OPEN,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void TANK_LEVEL_body__(TANK_LEVEL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->TL.,IN,,__GET_VAR(data__->LEVEL,));
  __SET_VAR(data__->TL.,T_ON,,__GET_VAR(data__->LEVEL_DELAY_TIME,));
  __SET_VAR(data__->TL.,T_OFF,,__GET_VAR(data__->LEVEL_DELAY_TIME,));
  TONOF_body__(&data__->TL);
  __SET_VAR(data__->,OPEN,,__GET_VAR(data__->TL.Q,));
  if (__GET_VAR(data__->ALARM,)) {
    if (__GET_VAR(data__->ACLR,)) {
      __SET_VAR(data__->,ALARM,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(101));
      __SET_VAR(data__->CX.,IN,,__BOOL_LITERAL(FALSE));
      ACTUATOR_COIL_body__(&data__->CX);
    };
    goto __end;
  } else if (__GET_VAR(data__->LEAK,)) {
    __SET_VAR(data__->CX.,IN,,__BOOL_LITERAL(FALSE));
    ACTUATOR_COIL_body__(&data__->CX);
    __SET_VAR(data__->,ALARM,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(1));
  } else if (__GET_VAR(data__->OPEN,)) {
    __SET_VAR(data__->CX.,IN,,__BOOL_LITERAL(TRUE));
    ACTUATOR_COIL_body__(&data__->CX);
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(102));
  } else {
    __SET_VAR(data__->CX.,IN,,__BOOL_LITERAL(FALSE));
    ACTUATOR_COIL_body__(&data__->CX);
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(100));
  };
  __SET_VAR(data__->TN.,IN,,(__GET_VAR(data__->CX.OUT,) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->MAX_VALVE_TIME,), __time_to_timespec(1, 0, 0, 0, 0, 0))));
  __SET_VAR(data__->TN.,PT,,__GET_VAR(data__->MAX_VALVE_TIME,));
  TON_body__(&data__->TN);
  if (__GET_VAR(data__->TN.Q,)) {
    __SET_VAR(data__->,ALARM,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(2));
    __SET_VAR(data__->CX.,IN,,__BOOL_LITERAL(FALSE));
    ACTUATOR_COIL_body__(&data__->CX);
  };
  __SET_VAR(data__->,VALVE,,__GET_VAR(data__->CX.OUT,));

  goto __end;

__end:
  return;
} // TANK_LEVEL_body__() 





void BLIND_ACTUATOR_init__(BLIND_ACTUATOR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->UP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->S_IN,0,retain)
  __INIT_VAR(data__->T_UD,__time_to_timespec(1, 0, 10, 0, 0, 0),retain)
  __INIT_VAR(data__->T_ANGLE,__time_to_timespec(1, 0, 3, 0, 0, 0),retain)
  __INIT_VAR(data__->T_LOCKOUT,__time_to_timespec(1, 100, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->POS,0,retain)
  __INIT_VAR(data__->ANG,0,retain)
  __INIT_VAR(data__->QU,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->QD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATUS,0,retain)
  RMP_B_init__(&data__->POSITION,retain);
  RMP_B_init__(&data__->ANGLE,retain);
  INTERLOCK_init__(&data__->LOCK,retain);
}

// Code part
void BLIND_ACTUATOR_body__(BLIND_ACTUATOR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->LOCK.,I1,,__GET_VAR(data__->UP,));
  __SET_VAR(data__->LOCK.,I2,,__GET_VAR(data__->DN,));
  __SET_VAR(data__->LOCK.,TL,,__GET_VAR(data__->T_LOCKOUT,));
  INTERLOCK_body__(&data__->LOCK);
  __SET_VAR(data__->ANGLE.,PT,,__GET_VAR(data__->T_ANGLE,));
  __SET_VAR(data__->ANGLE.,_E,,(__GET_VAR(data__->LOCK.Q1,) || __GET_VAR(data__->LOCK.Q2,)));
  __SET_VAR(data__->ANGLE.,UP,,__GET_VAR(data__->LOCK.Q1,));
  RMP_B_body__(&data__->ANGLE);
  __SET_VAR(data__->POSITION.,PT,,__GET_VAR(data__->T_UD,));
  __SET_VAR(data__->POSITION.,_E,,((__GET_VAR(data__->LOCK.Q1,) && __GET_VAR(data__->ANGLE.HIGH,)) || (__GET_VAR(data__->LOCK.Q2,) && __GET_VAR(data__->ANGLE.LOW,))));
  __SET_VAR(data__->POSITION.,UP,,__GET_VAR(data__->LOCK.Q1,));
  RMP_B_body__(&data__->POSITION);
  __SET_VAR(data__->,POS,,__GET_VAR(data__->POSITION.OUT,));
  __SET_VAR(data__->,ANG,,__GET_VAR(data__->ANGLE.OUT,));
  __SET_VAR(data__->,QU,,__GET_VAR(data__->LOCK.Q1,));
  __SET_VAR(data__->,QD,,__GET_VAR(data__->LOCK.Q2,));
  if ((__GET_VAR(data__->UP,) && __GET_VAR(data__->DN,))) {
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(1));
  } else if (__GET_VAR(data__->UP,)) {
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(121));
  } else if (__GET_VAR(data__->DN,)) {
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(122));
  } else {
    __SET_VAR(data__->,STATUS,,__GET_VAR(data__->S_IN,));
  };

  goto __end;

__end:
  return;
} // BLIND_ACTUATOR_body__() 





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





void TIMER_EXT_init__(TIMER_EXT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_ON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OFF,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MAN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SWITCH,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DT_IN,0,retain)
  __INIT_VAR(data__->SUN_SET,0,retain)
  __INIT_VAR(data__->SUN_RISE,0,retain)
  __INIT_VAR(data__->HOLIDAY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->T_DEBOUNCE,__time_to_timespec(1, 100, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T_RISE_START,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T_RISE_STOP,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T_SET_START,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T_SET_STOP,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T_DAY_START,0,retain)
  __INIT_VAR(data__->T_DAY_STOP,0,retain)
  __INIT_VAR(data__->ENABLE_SATURDAY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ENABLE_SUNDAY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ENABLE_HOLIDAY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATUS,0,retain)
  MANUAL_2_init__(&data__->MX,retain);
  DEBOUNCE_init__(&data__->DEB,retain);
  __INIT_VAR(data__->TDX,0,retain)
  __INIT_VAR(data__->WDX,0,retain)
  __INIT_VAR(data__->TC,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TX,0,retain)
  __INIT_VAR(data__->TL,0,retain)
  __INIT_VAR(data__->QX,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void TIMER_EXT_body__(TIMER_EXT *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,SUN_RISE,,((__GET_VAR(data__->SUN_RISE,) / __UDINT_LITERAL(1000)) * __UDINT_LITERAL(1000)));
  __SET_VAR(data__->,SUN_SET,,((__GET_VAR(data__->SUN_SET,) / __UDINT_LITERAL(1000)) * __UDINT_LITERAL(1000)));
  __SET_VAR(data__->,TX,,T_PLC_MS(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__BOOL_LITERAL(FALSE)));
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,TL,,__GET_VAR(data__->TX,));
  };
  __SET_VAR(data__->,TC,,UDINT_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)(__GET_VAR(data__->TX,) - __GET_VAR(data__->TL,))));
  if (LT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TC,), __time_to_timespec(1, 200, 0, 0, 0, 0))) {
    goto __end;
  };
  __SET_VAR(data__->,TL,,__GET_VAR(data__->TX,));
  __SET_VAR(data__->DEB.,IN,,__GET_VAR(data__->SWITCH,));
  __SET_VAR(data__->DEB.,TD,,__GET_VAR(data__->T_DEBOUNCE,));
  __SET_VAR(data__->DEB.,PM,,__BOOL_LITERAL(TRUE));
  DEBOUNCE_body__(&data__->DEB);
  __SET_VAR(data__->,TDX,,_DT_TO_TOD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->DT_IN,)));
  __SET_VAR(data__->,WDX,,DAY_OF_WEEK(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)_DT_TO_DATE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)__GET_VAR(data__->DT_IN,))));
  if (__GET_VAR(data__->DEB.Q,)) {
    __SET_VAR(data__->,QX,,!(__GET_VAR(data__->QX,)));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(110));
  } else if ((__GET_VAR(data__->HOLIDAY,) && !(__GET_VAR(data__->ENABLE_HOLIDAY,)))) {
    __SET_VAR(data__->,QX,,__BOOL_LITERAL(FALSE));
  } else if (((__GET_VAR(data__->WDX,) == 6) && !(__GET_VAR(data__->ENABLE_SATURDAY,)))) {
    __SET_VAR(data__->,QX,,__BOOL_LITERAL(FALSE));
  } else if (((__GET_VAR(data__->WDX,) == 7) && !(__GET_VAR(data__->ENABLE_SUNDAY,)))) {
    __SET_VAR(data__->,QX,,__BOOL_LITERAL(FALSE));
  } else if (((__GET_VAR(data__->T_DAY_START,) > __UDINT_LITERAL(0)) && ((__GET_VAR(data__->TDX,) - __GET_VAR(data__->T_DAY_START,)) <= TIME_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (TIME)__GET_VAR(data__->TC,))))) {
    __SET_VAR(data__->,QX,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(111));
  } else if (((__GET_VAR(data__->T_DAY_STOP,) > __UDINT_LITERAL(0)) && ((__GET_VAR(data__->TDX,) - __GET_VAR(data__->T_DAY_STOP,)) <= TIME_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (TIME)__GET_VAR(data__->TC,))))) {
    __SET_VAR(data__->,QX,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(112));
  } else if ((GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->T_RISE_START,), __time_to_timespec(1, 0, 0, 0, 0, 0)) && (((__GET_VAR(data__->TDX,) - __GET_VAR(data__->SUN_RISE,)) + TIME_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (TIME)__GET_VAR(data__->T_RISE_START,))) <= TIME_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (TIME)__GET_VAR(data__->TC,))))) {
    __SET_VAR(data__->,QX,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(113));
  } else if ((GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->T_RISE_STOP,), __time_to_timespec(1, 0, 0, 0, 0, 0)) && (((__GET_VAR(data__->TDX,) - __GET_VAR(data__->SUN_RISE,)) - TIME_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (TIME)__GET_VAR(data__->T_RISE_STOP,))) <= TIME_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (TIME)__GET_VAR(data__->TC,))))) {
    __SET_VAR(data__->,QX,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(114));
  } else if ((GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->T_SET_START,), __time_to_timespec(1, 0, 0, 0, 0, 0)) && (((__GET_VAR(data__->TDX,) - __GET_VAR(data__->SUN_SET,)) + TIME_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (TIME)__GET_VAR(data__->T_SET_START,))) <= TIME_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (TIME)__GET_VAR(data__->TC,))))) {
    __SET_VAR(data__->,QX,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(115));
  } else if ((GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->T_SET_STOP,), __time_to_timespec(1, 0, 0, 0, 0, 0)) && (((__GET_VAR(data__->TDX,) - __GET_VAR(data__->SUN_SET,)) - TIME_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (TIME)__GET_VAR(data__->T_SET_STOP,))) <= TIME_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (TIME)__GET_VAR(data__->TC,))))) {
    __SET_VAR(data__->,QX,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(116));
  };
  __SET_VAR(data__->MX.,IN,,__GET_VAR(data__->QX,));
  __SET_VAR(data__->MX.,ENA,,__GET_VAR(data__->ENA,));
  __SET_VAR(data__->MX.,_ON,,__GET_VAR(data__->_ON,));
  __SET_VAR(data__->MX.,OFF,,__GET_VAR(data__->OFF,));
  __SET_VAR(data__->MX.,MAN,,__GET_VAR(data__->MAN,));
  MANUAL_2_body__(&data__->MX);
  __SET_VAR(data__->,Q,,__GET_VAR(data__->MX.Q,));
  if ((__GET_VAR(data__->MX.STATUS,) > __BYTE_LITERAL(100))) {
    __SET_VAR(data__->,STATUS,,__GET_VAR(data__->MX.STATUS,));
  };

  goto __end;

__end:
  return;
} // TIMER_EXT_body__() 





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
REAL MULTI_IN(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN_1, 
  REAL IN_2, 
  REAL IN_3, 
  REAL DEFAULT, 
  REAL IN_MIN, 
  REAL IN_MAX, 
  BYTE MODE)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT COUNT = 0;
  BOOL F1 = __BOOL_LITERAL(FALSE);
  BOOL F2 = __BOOL_LITERAL(FALSE);
  BOOL F3 = __BOOL_LITERAL(FALSE);
  REAL MULTI_IN = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return MULTI_IN;
  }
  F1 = ((IN_1 > IN_MIN) && (IN_1 < IN_MAX));
  F2 = ((IN_2 > IN_MIN) && (IN_2 < IN_MAX));
  F3 = ((IN_3 > IN_MIN) && (IN_3 < IN_MAX));
  {
    INT __case_expression = BYTE_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)MODE);
    if ((__case_expression == 0)) {
      COUNT = 0;
      if (F1) {
        COUNT = (COUNT + 1);
        MULTI_IN = IN_1;
      } else {
        MULTI_IN = 0.0;
      };
      if (F2) {
        COUNT = (COUNT + 1);
        MULTI_IN = (MULTI_IN + IN_2);
      };
      if (F3) {
        COUNT = (COUNT + 1);
        MULTI_IN = (MULTI_IN + IN_3);
      };
      MULTI_IN = SEL__REAL__BOOL__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BOOL)(COUNT == 0),
        (REAL)(MULTI_IN / INT_TO_REAL(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (INT)COUNT)),
        (REAL)DEFAULT);
    }
    else if ((__case_expression == 1)) {
      MULTI_IN = SEL__REAL__BOOL__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BOOL)F1,
        (REAL)DEFAULT,
        (REAL)IN_1);
    }
    else if ((__case_expression == 2)) {
      MULTI_IN = SEL__REAL__BOOL__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BOOL)F2,
        (REAL)DEFAULT,
        (REAL)IN_2);
    }
    else if ((__case_expression == 3)) {
      MULTI_IN = SEL__REAL__BOOL__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BOOL)F3,
        (REAL)DEFAULT,
        (REAL)IN_3);
    }
    else if ((__case_expression == 4)) {
      MULTI_IN = DEFAULT;
    }
    else if ((__case_expression == 5)) {
      MULTI_IN = SEL__REAL__BOOL__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BOOL)F1,
        (REAL)IN_MAX,
        (REAL)IN_1);
      if ((F2 && (IN_2 < MULTI_IN))) {
        MULTI_IN = IN_2;
      };
      if ((F3 && (IN_3 < MULTI_IN))) {
        MULTI_IN = IN_3;
      };
      if ((MULTI_IN == IN_MAX)) {
        MULTI_IN = DEFAULT;
      };
    }
    else if ((__case_expression == 6)) {
      MULTI_IN = SEL__REAL__BOOL__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BOOL)F1,
        (REAL)IN_MIN,
        (REAL)IN_1);
      if ((F2 && (IN_2 > MULTI_IN))) {
        MULTI_IN = IN_2;
      };
      if ((F3 && (IN_3 > MULTI_IN))) {
        MULTI_IN = IN_3;
      };
      if ((MULTI_IN == IN_MIN)) {
        MULTI_IN = DEFAULT;
      };
    }
    else if ((__case_expression == 7)) {
      if (((F1 && F2) && F3)) {
        MULTI_IN = MID3(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (REAL)IN_1,
          (REAL)IN_2,
          (REAL)IN_3);
      } else if ((F1 && F2)) {
        MULTI_IN = MIN__REAL__REAL(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (UINT)2,
          (REAL)IN_1,
          (REAL)IN_2);
      } else if ((F1 && F3)) {
        MULTI_IN = MIN__REAL__REAL(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (UINT)2,
          (REAL)IN_1,
          (REAL)IN_3);
      } else if ((F2 && F3)) {
        MULTI_IN = MIN__REAL__REAL(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (UINT)2,
          (REAL)IN_2,
          (REAL)IN_3);
      } else if (F1) {
        MULTI_IN = IN_1;
      } else if (F2) {
        MULTI_IN = IN_2;
      } else if (F3) {
        MULTI_IN = IN_3;
      } else {
        MULTI_IN = DEFAULT;
      };
    }
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return MULTI_IN;
}


void BLIND_NIGHT_init__(BLIND_NIGHT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->UP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->S_IN,0,retain)
  __INIT_VAR(data__->PI,0,retain)
  __INIT_VAR(data__->AI,0,retain)
  __INIT_VAR(data__->E_NIGHT,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->E_DAY,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->DTIN,0,retain)
  __INIT_VAR(data__->SUNRISE,0,retain)
  __INIT_VAR(data__->SUNSET,0,retain)
  __INIT_VAR(data__->SUNRISE_OFFSET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->SUNSET_OFFSET,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->NIGHT_POSITION,0,retain)
  __INIT_VAR(data__->NIGHT_ANGLE,0,retain)
  __INIT_VAR(data__->QU,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->QD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATUS,0,retain)
  __INIT_VAR(data__->PO,0,retain)
  __INIT_VAR(data__->AO,0,retain)
  __INIT_VAR(data__->NIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LAST_NIGHT,0,retain)
  __INIT_VAR(data__->LAST_DAY,0,retain)
}

// Code part
void BLIND_NIGHT_body__(BLIND_NIGHT *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((!((__GET_VAR(data__->UP,) && __GET_VAR(data__->DN,))) && __GET_VAR(data__->NIGHT,))) {
    __SET_VAR(data__->,NIGHT,,__BOOL_LITERAL(FALSE));
  } else if (((((_DT_TO_TOD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->DTIN,)) > (__GET_VAR(data__->SUNSET,) + TIME_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (TIME)__GET_VAR(data__->SUNSET_OFFSET,)))) && (__GET_VAR(data__->LAST_NIGHT,) < _DT_TO_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->DTIN,)))) && !(__GET_VAR(data__->NIGHT,))) && __GET_VAR(data__->E_NIGHT,))) {
    __SET_VAR(data__->,NIGHT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,LAST_NIGHT,,_DT_TO_DATE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)__GET_VAR(data__->DTIN,)));
  } else if ((((((_DT_TO_TOD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->DTIN,)) > (__GET_VAR(data__->SUNRISE,) + TIME_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (TIME)__GET_VAR(data__->SUNRISE_OFFSET,)))) && (__GET_VAR(data__->LAST_DAY,) < _DT_TO_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->DTIN,)))) && __GET_VAR(data__->NIGHT,)) && __GET_VAR(data__->E_DAY,)) && (__GET_VAR(data__->LAST_NIGHT,) < _DT_TO_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->DTIN,))))) {
    __SET_VAR(data__->,NIGHT,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,LAST_DAY,,_DT_TO_DATE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)__GET_VAR(data__->DTIN,)));
  };
  if (((__GET_VAR(data__->UP,) && __GET_VAR(data__->DN,)) && __GET_VAR(data__->NIGHT,))) {
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(141));
    __SET_VAR(data__->,PO,,__GET_VAR(data__->NIGHT_POSITION,));
    __SET_VAR(data__->,AO,,__GET_VAR(data__->NIGHT_ANGLE,));
  } else {
    __SET_VAR(data__->,QU,,__GET_VAR(data__->UP,));
    __SET_VAR(data__->,QD,,__GET_VAR(data__->DN,));
    __SET_VAR(data__->,PO,,__GET_VAR(data__->PI,));
    __SET_VAR(data__->,AO,,__GET_VAR(data__->AI,));
    __SET_VAR(data__->,STATUS,,__GET_VAR(data__->S_IN,));
  };

  goto __end;

__end:
  return;
} // BLIND_NIGHT_body__() 





void BLIND_SECURITY_init__(BLIND_SECURITY *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->UP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->S_IN,0,retain)
  __INIT_VAR(data__->PI,0,retain)
  __INIT_VAR(data__->AI,0,retain)
  __INIT_VAR(data__->FIRE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->WIND,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ALARM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DOOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RAIN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ALARM_UP,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->WIND_UP,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RAIN_UP,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->QU,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->QD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATUS,0,retain)
  __INIT_VAR(data__->PO,0,retain)
  __INIT_VAR(data__->AO,0,retain)
}

// Code part
void BLIND_SECURITY_body__(BLIND_SECURITY *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (__GET_VAR(data__->FIRE,)) {
    __SET_VAR(data__->,QU,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,QD,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(111));
  } else if (__GET_VAR(data__->WIND,)) {
    __SET_VAR(data__->,QU,,__GET_VAR(data__->WIND_UP,));
    __SET_VAR(data__->,QD,,!(__GET_VAR(data__->WIND_UP,)));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(112));
  } else if (__GET_VAR(data__->ALARM,)) {
    __SET_VAR(data__->,QU,,__GET_VAR(data__->ALARM_UP,));
    __SET_VAR(data__->,QD,,!(__GET_VAR(data__->ALARM_UP,)));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(113));
  } else if (__GET_VAR(data__->DOOR,)) {
    __SET_VAR(data__->,QU,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,QD,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(114));
  } else if ((__GET_VAR(data__->RAIN,) && !((__GET_VAR(data__->UP,) && !__GET_VAR(data__->DN,)) || (!__GET_VAR(data__->UP,) && __GET_VAR(data__->DN,))))) {
    __SET_VAR(data__->,QU,,__GET_VAR(data__->RAIN_UP,));
    __SET_VAR(data__->,QD,,!(__GET_VAR(data__->RAIN_UP,)));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(115));
  } else {
    __SET_VAR(data__->,QU,,__GET_VAR(data__->UP,));
    __SET_VAR(data__->,QD,,__GET_VAR(data__->DN,));
    __SET_VAR(data__->,STATUS,,__GET_VAR(data__->S_IN,));
    __SET_VAR(data__->,PO,,__GET_VAR(data__->PI,));
    __SET_VAR(data__->,AO,,__GET_VAR(data__->AI,));
  };

  goto __end;

__end:
  return;
} // BLIND_SECURITY_body__() 





// FUNCTION
UDINT TIME_TO_TOD(
  BOOL EN, 
  BOOL *__ENO, 
  TIME IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  UDINT TIME_TO_TOD = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return TIME_TO_TOD;
  }
  TIME_TO_TOD = DWORD_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)TIME_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)IN));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return TIME_TO_TOD;
}


// FUNCTION
REAL WATER_CP(
  BOOL EN, 
  BOOL *__ENO, 
  REAL _T)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT PTS = 10;
  __ARRAY_OF_REAL_20_2 DATA = {{0,4.228,5.0,4.20,10.0,4.188,15.0,4.184,50.0,4.181,60.0,4.183,70.0,4.187,80.0,4.194,90.0,4.204,100.0,4.22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
  REAL WATER_CP = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return WATER_CP;
  }
  WATER_CP = LINEAR_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)_T,
    &(DATA),
    (INT)PTS);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return WATER_CP;
}


// FUNCTION
REAL AIR_DENSITY(
  BOOL EN, 
  BOOL *__ENO, 
  REAL _T, 
  REAL P, 
  REAL RH)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL AIR_DENSITY = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return AIR_DENSITY;
  }
  AIR_DENSITY = ((101325.0 * (1.0 - (((RH * SDD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)_T,
    (BOOL)__BOOL_LITERAL(TRUE))) * 3.773319E-3) / P))) / (287.05 * (_T - -273.15)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return AIR_DENSITY;
}


void TREND_DW_init__(TREND_DW *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TU,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_D,0,retain)
  __INIT_VAR(data__->LAST_X,0,retain)
}

// Code part
void TREND_DW_body__(TREND_DW *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->X,) > __GET_VAR(data__->LAST_X,))) {
    __SET_VAR(data__->,TU,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,TD,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,_D,,UDINT_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)(DWORD_TO_UDINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)__GET_VAR(data__->X,)) - DWORD_TO_UDINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)__GET_VAR(data__->LAST_X,)))));
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
  } else if ((__GET_VAR(data__->X,) < __GET_VAR(data__->LAST_X,))) {
    __SET_VAR(data__->,TD,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,TU,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,_D,,UDINT_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)(DWORD_TO_UDINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)__GET_VAR(data__->LAST_X,)) - DWORD_TO_UDINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)__GET_VAR(data__->X,)))));
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  } else {
    __SET_VAR(data__->,TU,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,TD,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,_D,,__DWORD_LITERAL(0));
  };
  __SET_VAR(data__->,LAST_X,,__GET_VAR(data__->X,));

  goto __end;

__end:
  return;
} // TREND_DW_body__() 





void _RMP_NEXT_init__(_RMP_NEXT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->_E,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->TR,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TF,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TL,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DIR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT,0,retain)
  _RMP_B_init__(&data__->RMX,retain);
  TREND_DW_init__(&data__->DIRX,retain);
  TP_init__(&data__->T_LOCK,retain);
  __INIT_VAR(data__->XEN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->XDIR,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void _RMP_NEXT_body__(_RMP_NEXT *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->DIRX.,X,,BYTE_TO_DWORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)__GET_VAR(data__->IN,)));
  TREND_DW_body__(&data__->DIRX);
  __SET_VAR(data__->T_LOCK.,IN,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->T_LOCK.,PT,,__GET_VAR(data__->TL,));
  TP_body__(&data__->T_LOCK);
  if ((__GET_VAR(data__->DIRX.TU,) && (__GET_VAR(data__->OUT,) < __GET_VAR(data__->IN,)))) {
    if ((!(__GET_VAR(data__->XDIR,)) && __GET_VAR(data__->XEN,))) {
      __SET_VAR(data__->T_LOCK.,IN,,__BOOL_LITERAL(TRUE));
      TP_body__(&data__->T_LOCK);
    };
    __SET_VAR(data__->,XEN,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,XDIR,,__BOOL_LITERAL(TRUE));
  } else if ((__GET_VAR(data__->DIRX.TD,) && (__GET_VAR(data__->OUT,) > __GET_VAR(data__->IN,)))) {
    if ((__GET_VAR(data__->XDIR,) && __GET_VAR(data__->XEN,))) {
      __SET_VAR(data__->T_LOCK.,IN,,__BOOL_LITERAL(TRUE));
      TP_body__(&data__->T_LOCK);
    };
    __SET_VAR(data__->,XEN,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,XDIR,,__BOOL_LITERAL(FALSE));
  } else if (__GET_VAR(data__->XEN,)) {
    if (((__GET_VAR(data__->XDIR,) && (__GET_VAR(data__->OUT,) >= __GET_VAR(data__->IN,))) || (!(__GET_VAR(data__->XDIR,)) && (__GET_VAR(data__->OUT,) <= __GET_VAR(data__->IN,))))) {
      __SET_VAR(data__->,XEN,,__BOOL_LITERAL(FALSE));
      if (GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TL,), __time_to_timespec(1, 0, 0, 0, 0, 0))) {
        __SET_VAR(data__->T_LOCK.,IN,,__BOOL_LITERAL(TRUE));
        TP_body__(&data__->T_LOCK);
      };
    };
  };
  if ((!(__GET_VAR(data__->T_LOCK.Q,)) && __GET_VAR(data__->XEN,))) {
    __SET_VAR(data__->,UP,,__GET_VAR(data__->XDIR,));
    __SET_VAR(data__->,DIR,,__GET_VAR(data__->XDIR,));
    __SET_VAR(data__->,DN,,!(__GET_VAR(data__->XDIR,)));
  } else {
    __SET_VAR(data__->,UP,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,DN,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->RMX.,DIR,,__GET_VAR(data__->DIR,));
  __SET_VAR(data__->RMX.,_E,,(__GET_VAR(data__->_E,) && (__GET_VAR(data__->UP,) || __GET_VAR(data__->DN,))));
  __SET_VAR(data__->RMX.,TR,,SEL__TIME__BOOL__TIME__TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->DIR,),
    (TIME)__GET_VAR(data__->TF,),
    (TIME)__GET_VAR(data__->TR,)));
  __SET_VAR(data__->RMX.,RMP,,__GET_VAR(data__->OUT,));
  _RMP_B_body__(&data__->RMX);
  __SET_VAR(data__->,OUT,,__GET_VAR(data__->RMX.RMP));
  __SET_VAR(data__->,OUT,,__GET_VAR(data__->RMX.RMP,));

  goto __end;

__end:
  return;
} // _RMP_NEXT_body__() 





void BLIND_CONTROL_S_init__(BLIND_CONTROL_S *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->UP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->S_IN,125,retain)
  __INIT_VAR(data__->PI,0,retain)
  __INIT_VAR(data__->T_UP,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T_DN,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->RU,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->T_LOCKOUT,__time_to_timespec(1, 100, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T_EXT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->EXT_TRIG,5,retain)
  __INIT_VAR(data__->R_POS_TOP,255,retain)
  __INIT_VAR(data__->R_POS_BOT,0,retain)
  __INIT_VAR(data__->POS,0,retain)
  __INIT_VAR(data__->MU,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATUS,0,retain)
  _RMP_NEXT_init__(&data__->RMP,retain);
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->PI_LAST,0,retain)
}

// Code part
void BLIND_CONTROL_S_body__(BLIND_CONTROL_S *data__) {
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
  if ((__GET_VAR(data__->UP,) && !(__GET_VAR(data__->DN,)))) {
    __SET_VAR(data__->,RMP.IN,,__BYTE_LITERAL(255));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(121));
  } else if ((__GET_VAR(data__->DN,) && !(__GET_VAR(data__->UP,)))) {
    __SET_VAR(data__->,RMP.IN,,__BYTE_LITERAL(0));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(122));
  } else if (!((__GET_VAR(data__->UP,) || __GET_VAR(data__->DN,)))) {
    __SET_VAR(data__->,RMP.IN,,__GET_VAR(data__->PI,));
    __SET_VAR(data__->,STATUS,,__GET_VAR(data__->S_IN,));
  };
  __SET_VAR(data__->RMP.,_E,,(__GET_VAR(data__->UP,) || __GET_VAR(data__->DN,)));
  __SET_VAR(data__->RMP.,TR,,__GET_VAR(data__->T_UP,));
  __SET_VAR(data__->RMP.,TF,,__GET_VAR(data__->T_DN,));
  __SET_VAR(data__->RMP.,TL,,__GET_VAR(data__->T_LOCKOUT,));
  __SET_VAR(data__->RMP.,OUT,,__GET_VAR(data__->POS,));
  _RMP_NEXT_body__(&data__->RMP);
  __SET_VAR(data__->,POS,,__GET_VAR(data__->RMP.OUT));
  __SET_VAR(data__->,POS,,__GET_VAR(data__->RMP.OUT,));
  {
    INT __case_expression = BYTE_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->STATUS,));
    if ((__case_expression == 0)) {
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
      __SET_VAR(data__->,PI_LAST,,(__GET_VAR(data__->PI,) ^ __BYTE_LITERAL(255)));
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(128));
    }
    else if ((__case_expression == 121)) {
      __SET_VAR(data__->,MU,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,MD,,__BOOL_LITERAL(FALSE));
      if ((__GET_VAR(data__->POS,) >= USINT_TO_BYTE(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (USINT)(__USINT_LITERAL(255) - BYTE_TO_USINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->EXT_TRIG,)))))) {
        __SET_VAR(data__->,POS,,__BYTE_LITERAL(255));
        __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(129));
      };
    }
    else if ((__case_expression == 122)) {
      __SET_VAR(data__->,MD,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,MU,,__BOOL_LITERAL(FALSE));
      if ((__GET_VAR(data__->POS,) <= __GET_VAR(data__->EXT_TRIG,))) {
        __SET_VAR(data__->,POS,,__BYTE_LITERAL(0));
        __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(129));
      };
    }
    else if ((__case_expression == 123)) {
      __SET_VAR(data__->,MD,,__GET_VAR(data__->RMP.DN,));
      __SET_VAR(data__->,MU,,__GET_VAR(data__->RMP.UP,));
      if (!((__GET_VAR(data__->RMP.DN,) || __GET_VAR(data__->RMP.UP,)))) {
        if ((__GET_VAR(data__->POS,) <= __GET_VAR(data__->EXT_TRIG,))) {
          __SET_VAR(data__->,MD,,__BOOL_LITERAL(TRUE));
          __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
          __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(129));
        } else if ((__GET_VAR(data__->POS,) >= USINT_TO_BYTE(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (USINT)(__USINT_LITERAL(255) - BYTE_TO_USINT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (BYTE)__GET_VAR(data__->EXT_TRIG,)))))) {
          __SET_VAR(data__->,MU,,__BOOL_LITERAL(TRUE));
          __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
          __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(129));
        } else {
          __SET_VAR(data__->,STATUS,,__GET_VAR(data__->S_IN,));
        };
      };
    }
    else if ((__case_expression == 124)) {
      __SET_VAR(data__->,MD,,__GET_VAR(data__->RMP.DN,));
      __SET_VAR(data__->,MU,,__GET_VAR(data__->RMP.UP,));
      if (!((__GET_VAR(data__->RMP.DN,) || __GET_VAR(data__->RMP.UP,)))) {
        __SET_VAR(data__->,PI_LAST,,__GET_VAR(data__->PI,));
        __SET_VAR(data__->,STATUS,,__GET_VAR(data__->S_IN,));
      };
    }
    else if ((__case_expression == 127)) {
      if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->T_LOCKOUT,))) {
        __SET_VAR(data__->,STATUS,,__GET_VAR(data__->S_IN,));
      };
    }
    else if ((__case_expression == 128)) {
      __SET_VAR(data__->,MU,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,MD,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,RMP.IN,,__BYTE_LITERAL(255));
      if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __time_add(__GET_VAR(data__->T_UP,), __GET_VAR(data__->T_EXT,)))) {
        __SET_VAR(data__->,MU,,__BOOL_LITERAL(FALSE));
        __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(127));
      };
    }
    else if ((__case_expression == 129)) {
      if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->T_EXT,))) {
        __SET_VAR(data__->,MU,,__BOOL_LITERAL(FALSE));
        __SET_VAR(data__->,MD,,__BOOL_LITERAL(FALSE));
        __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(127));
      };
    }
    else {
      __SET_VAR(data__->,MU,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,MD,,__BOOL_LITERAL(FALSE));
      if ((__GET_VAR(data__->PI,) != __GET_VAR(data__->PI_LAST,))) {
        __SET_VAR(data__->,PI_LAST,,__GET_VAR(data__->PI,));
        __SET_VAR(data__->,RMP.IN,,__GET_VAR(data__->PI,));
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(123));
      } else if (((__GET_VAR(data__->POS,) == __BYTE_LITERAL(0)) && __GET_VAR(data__->RU,))) {
        __SET_VAR(data__->,RMP.IN,,__GET_VAR(data__->R_POS_BOT,));
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(124));
      } else if (((__GET_VAR(data__->POS,) == __BYTE_LITERAL(255)) && __GET_VAR(data__->RD,))) {
        __SET_VAR(data__->,RMP.IN,,__GET_VAR(data__->R_POS_TOP,));
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(124));
      } else {
        __SET_VAR(data__->,STATUS,,__GET_VAR(data__->S_IN,));
      };
    }
  };

  goto __end;

__end:
  return;
} // BLIND_CONTROL_S_body__() 





void HYST_1_init__(HYST_1 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->HIGH,0,retain)
  __INIT_VAR(data__->LOW,0,retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->WIN,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void HYST_1_body__(HYST_1 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->IN,) < __GET_VAR(data__->LOW,))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,WIN,,__BOOL_LITERAL(FALSE));
  } else if ((__GET_VAR(data__->IN,) > __GET_VAR(data__->HIGH,))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,WIN,,__BOOL_LITERAL(FALSE));
  } else {
    __SET_VAR(data__->,WIN,,__BOOL_LITERAL(TRUE));
  };

  goto __end;

__end:
  return;
} // HYST_1_body__() 





void TIMER_1_init__(TIMER_1 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->_E,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->DTI,0,retain)
  __INIT_VAR(data__->START,0,retain)
  __INIT_VAR(data__->DURATION,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DAY,0x7F,retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STOP,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
}

// Code part
void TIMER_1_body__(TIMER_1 *data__) {
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
    __SET_VAR(data__->,STOP,,__time_add(TOD_TO_TIME(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)__GET_VAR(data__->START,)), __GET_VAR(data__->DURATION,)));
    if (GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->STOP,), __time_to_timespec(1, 0, 0, 0, 24, 0))) {
      __SET_VAR(data__->,STOP,,__time_sub(__GET_VAR(data__->STOP,), __time_to_timespec(1, 0, 0, 0, 24, 0)));
    };
    __SET_VAR(data__->,Q,,(TIMECHECK(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)_DT_TO_TOD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)__GET_VAR(data__->DTI,)),
      (UDINT)__GET_VAR(data__->START,),
      (UDINT)TIME_TO_TOD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (TIME)__GET_VAR(data__->STOP,))) && ((SHR__BYTE__BYTE__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__BYTE_LITERAL(128),
      (INT)DAY_OF_WEEK(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)_DT_TO_DATE(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (UDINT)__GET_VAR(data__->DTI,)))) & __GET_VAR(data__->DAY,)) > __BYTE_LITERAL(0))));
  } else {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // TIMER_1_body__() 





void TIMER_2_init__(TIMER_2 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->DT_IN,0,retain)
  __INIT_VAR(data__->START,0,retain)
  __INIT_VAR(data__->DURATION,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->MODE,0,retain)
  __INIT_VAR(data__->HOLIDAY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LAST_CHECK,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DAT,0,retain)
  __INIT_VAR(data__->DAYTIME,0,retain)
  __INIT_VAR(data__->ACTIVATION,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->ENABLED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->WDAY,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RUN_DATE,0,1)
}

// Code part
void TIMER_2_body__(TIMER_2 *data__) {
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
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,LAST_CHECK,,__time_sub(__GET_VAR(data__->TX,), __time_to_timespec(1, 100, 0, 0, 0, 0)));
  };
  if (LT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST_CHECK,)), __time_to_timespec(1, 100, 0, 0, 0, 0))) {
    goto __end;
  };
  __SET_VAR(data__->,DAT,,_DT_TO_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->DT_IN,)));
  __SET_VAR(data__->,DAYTIME,,_DT_TO_TOD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->DT_IN,)));
  __SET_VAR(data__->,WDAY,,DAY_OF_WEEK(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->DAT,)));
  {
    INT __case_expression = BYTE_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->MODE,));
    if ((__case_expression >= 1 && __case_expression <= 7)) {
      __SET_VAR(data__->,ENABLED,,(__GET_VAR(data__->WDAY,) == BYTE_TO_INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->MODE,))));
    }
    else if ((__case_expression == 11)) {
      __SET_VAR(data__->,ENABLED,,__BOOL_LITERAL(TRUE));
    }
    else if ((__case_expression >= 12 && __case_expression <= 16)) {
      __SET_VAR(data__->,ENABLED,,((((BYTE_TO_UDINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->MODE,)) - __UDINT_LITERAL(10)) == 0)?0:((__GET_VAR(data__->DAT,) / __UDINT_LITERAL(86400)) % (BYTE_TO_UDINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->MODE,)) - __UDINT_LITERAL(10)))) == __UDINT_LITERAL(0)));
    }
    else if ((__case_expression == 20)) {
      __SET_VAR(data__->,ENABLED,,(__GET_VAR(data__->WDAY,) <= 5));
    }
    else if ((__case_expression == 21)) {
      __SET_VAR(data__->,ENABLED,,(__GET_VAR(data__->WDAY,) > 5));
    }
    else if ((__case_expression == 22)) {
      __SET_VAR(data__->,ENABLED,,((__GET_VAR(data__->WDAY,) <= 5) && !(__GET_VAR(data__->HOLIDAY,))));
    }
    else if ((__case_expression == 23)) {
      __SET_VAR(data__->,ENABLED,,((__GET_VAR(data__->WDAY,) > 5) || __GET_VAR(data__->HOLIDAY,)));
    }
    else if ((__case_expression == 24)) {
      __SET_VAR(data__->,ENABLED,,__GET_VAR(data__->HOLIDAY,));
    }
    else if ((__case_expression == 25)) {
      __SET_VAR(data__->,ENABLED,,(DAY_OF_MONTH(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)__GET_VAR(data__->DAT,)) == 1));
    }
    else if ((__case_expression == 26)) {
      __SET_VAR(data__->,ENABLED,,(DAY_OF_MONTH(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)(__GET_VAR(data__->DAT,) + TIME_TO_UDINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (TIME)__time_to_timespec(1, 0, 0, 0, 0, 1)))) == 1));
    }
    else if ((__case_expression == 27)) {
      __SET_VAR(data__->,ENABLED,,((DAY_OF_MONTH(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)__GET_VAR(data__->DAT,)) == 31) && (MONTH_OF_DATE(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)__GET_VAR(data__->DAT,)) == 12)));
    }
    else if ((__case_expression == 28)) {
      __SET_VAR(data__->,ENABLED,,(DAY_OF_YEAR(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)__GET_VAR(data__->DAT,)) == 1));
    }
    else {
      __SET_VAR(data__->,ENABLED,,__BOOL_LITERAL(FALSE));
    }
  };
  if ((((__GET_VAR(data__->ENABLED,) && !(__GET_VAR(data__->Q,))) && (__GET_VAR(data__->DAYTIME,) >= __GET_VAR(data__->START,))) && (__GET_VAR(data__->RUN_DATE,) != __GET_VAR(data__->DAT,)))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,ACTIVATION,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,RUN_DATE,,__GET_VAR(data__->DAT,));
  } else if ((__GET_VAR(data__->Q,) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->ACTIVATION,)), __GET_VAR(data__->DURATION,)))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,LAST_CHECK,,__GET_VAR(data__->TX,));

  goto __end;

__end:
  return;
} // TIMER_2_body__() 





// FUNCTION
REAL CIRCLE_SEG(
  BOOL EN, 
  BOOL *__ENO, 
  REAL RX, 
  REAL HX)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL CIRCLE_SEG = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return CIRCLE_SEG;
  }
  if ((RX > 0.0)) {
    CIRCLE_SEG = (2.0 * ACOS__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(1.0 - LIMIT__REAL__REAL__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)0.0,
        (REAL)(HX / RX),
        (REAL)2.0))));
    CIRCLE_SEG = ((((CIRCLE_SEG - SIN__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)CIRCLE_SEG)) * RX) * RX) * 0.5);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return CIRCLE_SEG;
}


// FUNCTION
BYTE BAND_B(
  BOOL EN, 
  BOOL *__ENO, 
  BYTE X, 
  BYTE B)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BYTE BAND_B = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return BAND_B;
  }
  if ((X < B)) {
    BAND_B = __BYTE_LITERAL(0);
  } else if ((X > USINT_TO_BYTE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (USINT)(__USINT_LITERAL(255) - BYTE_TO_USINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)B))))) {
    BAND_B = __BYTE_LITERAL(255);
  } else {
    BAND_B = X;
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return BAND_B;
}


void BLIND_SET_init__(BLIND_SET *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->UP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->S_IN,0,retain)
  __INIT_VAR(data__->PI,0,retain)
  __INIT_VAR(data__->AI,0,retain)
  __INIT_VAR(data__->PX,0,retain)
  __INIT_VAR(data__->AX,0,retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OVERRIDE_MANUAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESTORE_POSITION,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESTORE_TIME,__time_to_timespec(1, 0, 60, 0, 0, 0),retain)
  __INIT_VAR(data__->QU,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->QD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATUS,0,retain)
  __INIT_VAR(data__->PO,0,retain)
  __INIT_VAR(data__->AO,0,retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->PS,0,retain)
  __INIT_VAR(data__->AS,0,retain)
}

// Code part
void BLIND_SET_body__(BLIND_SET *data__) {
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
  if (__GET_VAR(data__->IN,)) {
    if ((__GET_VAR(data__->OVERRIDE_MANUAL,) || (__GET_VAR(data__->UP,) && __GET_VAR(data__->DN,)))) {
      __SET_VAR(data__->,STATUS,,178);
    };
  };
  {
    INT __case_expression = BYTE_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->STATUS,));
    if ((__case_expression == 0)) {
      __SET_VAR(data__->,STATUS,,__GET_VAR(data__->S_IN,));
    }
    else if ((__case_expression == 178)) {
      __SET_VAR(data__->,PO,,__GET_VAR(data__->PX,));
      __SET_VAR(data__->,AO,,__GET_VAR(data__->AX,));
      __SET_VAR(data__->,QU,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,QD,,__BOOL_LITERAL(TRUE));
      if (!(__GET_VAR(data__->IN,))) {
        __SET_VAR(data__->,STATUS,,SEL__BYTE__BOOL__BYTE__BYTE(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BOOL)__GET_VAR(data__->RESTORE_POSITION,),
          (BYTE)__GET_VAR(data__->S_IN,),
          (BYTE)179));
        __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
      };
    }
    else if ((__case_expression == 179)) {
      __SET_VAR(data__->,PO,,__GET_VAR(data__->PS,));
      __SET_VAR(data__->,AO,,__GET_VAR(data__->AS,));
      if ((((__GET_VAR(data__->PO,) == __GET_VAR(data__->PI,)) && (__GET_VAR(data__->AO,) == __GET_VAR(data__->AI,))) || GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->RESTORE_TIME,)))) {
        __SET_VAR(data__->,STATUS,,__GET_VAR(data__->S_IN,));
      };
    }
    else {
      __SET_VAR(data__->,PO,,__GET_VAR(data__->PI,));
      __SET_VAR(data__->,PS,,__GET_VAR(data__->PI,));
      __SET_VAR(data__->,AO,,__GET_VAR(data__->AI,));
      __SET_VAR(data__->,AS,,__GET_VAR(data__->AI,));
      __SET_VAR(data__->,STATUS,,__GET_VAR(data__->S_IN,));
      __SET_VAR(data__->,QU,,__GET_VAR(data__->UP,));
      __SET_VAR(data__->,QD,,__GET_VAR(data__->DN,));
    }
  };

  goto __end;

__end:
  return;
} // BLIND_SET_body__() 





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
REAL DEW_TEMP(
  BOOL EN, 
  BOOL *__ENO, 
  REAL RH, 
  REAL _T)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL V = 0;
  REAL DEW_TEMP = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DEW_TEMP;
  }
  if ((RH > 0.0)) {
    V = LOG__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)((RH * 0.01) * EXP10(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)((7.5 * _T) / (237.3 + _T)))));
    DEW_TEMP = ((237.3 * V) / (7.5 - V));
  } else {
    DEW_TEMP = -273.15;
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return DEW_TEMP;
}


// FUNCTION
REAL SDT_NH3(
  BOOL EN, 
  BOOL *__ENO, 
  REAL P)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL SDT_NH3 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SDT_NH3;
  }
  if ((P < 1.0E-3)) {
    SDT_NH3 = -110.0;
  } else if ((P < 1.0)) {
    SDT_NH3 = ((506.713 / (3.18757 - LOG__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)P))) - 192.37);
  } else {
    SDT_NH3 = ((1113.928 / (4.86886 - LOG__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)P))) - 262.71);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SDT_NH3;
}


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
REAL HEAT_INDEX(
  BOOL EN, 
  BOOL *__ENO, 
  REAL _T, 
  REAL RH)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL RH2 = 0;
  REAL T2 = 0;
  REAL TX = 0;
  REAL HEAT_INDEX = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return HEAT_INDEX;
  }
  if (((RH < 20.0) || (_T < 20.0))) {
    HEAT_INDEX = _T;
  } else {
    TX = _T;
    RH2 = (RH * RH);
    TX = C_TO_F(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)TX);
    T2 = (TX * TX);
    HEAT_INDEX = ((((-42.379 + (2.04901523 * TX)) - (6.83783E-3 * T2)) + (RH * ((10.1433127 - (0.22475541 * TX)) + (1.22874E-3 * T2)))) + (RH2 * (((8.5282E-4 * TX) - 5.481717E-2) - (1.99E-6 * T2))));
    HEAT_INDEX = F_TO_C(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)HEAT_INDEX);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return HEAT_INDEX;
}


void AUTORUN_init__(AUTORUN *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TEST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ARE,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRUN,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TOFF,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ARO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ARX,__BOOL_LITERAL(FALSE),retain)
  _RMP_B_init__(&data__->TIMER,retain);
  __INIT_VAR(data__->VAL,0,retain)
}

// Code part
void AUTORUN_body__(AUTORUN *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TOFF,), __time_to_timespec(1, 0, 0, 0, 0, 0))) {
    __SET_VAR(data__->TIMER.,DIR,,__GET_VAR(data__->OUT,));
    __SET_VAR(data__->TIMER.,TR,,SEL__TIME__BOOL__TIME__TIME(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__GET_VAR(data__->OUT,),
      (TIME)__GET_VAR(data__->TOFF,),
      (TIME)__GET_VAR(data__->TRUN,)));
    __SET_VAR(data__->TIMER.,RMP,,__GET_VAR(data__->VAL,));
    _RMP_B_body__(&data__->TIMER);
    __SET_VAR(data__->,VAL,,__GET_VAR(data__->TIMER.RMP));
    __SET_VAR(data__->,VAL,,__GET_VAR(data__->TIMER.RMP,));
  } else {
    __SET_VAR(data__->,VAL,,__BYTE_LITERAL(255));
  };
  if ((((!(__GET_VAR(data__->ARX,)) && __GET_VAR(data__->ARE,)) && (__GET_VAR(data__->VAL,) == __BYTE_LITERAL(0))) || __GET_VAR(data__->TEST,))) {
    __SET_VAR(data__->,VAL,,__BYTE_LITERAL(0));
    __SET_VAR(data__->,ARO,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,ARX,,__BOOL_LITERAL(TRUE));
  } else if (((__GET_VAR(data__->VAL,) == __BYTE_LITERAL(255)) && __GET_VAR(data__->ARO,))) {
    __SET_VAR(data__->,ARO,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,ARX,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,OUT,,(__GET_VAR(data__->IN,) || __GET_VAR(data__->ARO,)));

  goto __end;

__end:
  return;
} // AUTORUN_body__() 





void BLIND_SHADE_S_init__(BLIND_SHADE_S *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->UP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PI,0,retain)
  __INIT_VAR(data__->S_IN,0,retain)
  __INIT_VAR(data__->ENABLE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SUN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->HORZ1,100.0,retain)
  __INIT_VAR(data__->HORZ2,260.0,retain)
  __INIT_VAR(data__->VERT,90.0,retain)
  __INIT_VAR(data__->ALERT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SUNRISE_OFFSET,__time_to_timespec(1, 0, 0, 0, 1, 0),retain)
  __INIT_VAR(data__->SUNSET_PRESET,__time_to_timespec(1, 0, 0, 0, 1, 0),retain)
  __INIT_VAR(data__->SHADE_DELAY,__time_to_timespec(1, 0, 60, 0, 0, 0),retain)
  __INIT_VAR(data__->SHADE_POS,0,retain)
  __INIT_VAR(data__->QU,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->QD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATUS,0,retain)
  __INIT_VAR(data__->PO,0,retain)
  {
    static const OSCAT_CALENDAR temp = {0,0,0,0,0,0,0,0,0,__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__STRING_LITERAL(0,""),0,0,0,0,0,0,0,0,0,__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__STRING_LITERAL(0,""),0};
    __SET_VAR(data__->,CX,,temp);
  }
  TOF_init__(&data__->SUN_DELAY,retain);
}

// Code part
void BLIND_SHADE_S_body__(BLIND_SHADE_S *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->SUN_DELAY.,IN,,__GET_VAR(data__->SUN,));
  __SET_VAR(data__->SUN_DELAY.,PT,,__GET_VAR(data__->SHADE_DELAY,));
  TOF_body__(&data__->SUN_DELAY);
  if (__GET_VAR(data__->ALERT,)) {
    __SET_VAR(data__->,QU,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,QD,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(152));
  } else if (((((((((__GET_VAR(data__->UP,) && __GET_VAR(data__->DN,)) && __GET_VAR(data__->ENABLE,)) && __GET_VAR(data__->SUN_DELAY.Q,)) && (__GET_VAR(data__->CX,.SUN_HOR) > __GET_VAR(data__->HORZ1,))) && (__GET_VAR(data__->CX,.SUN_HOR) < __GET_VAR(data__->HORZ2,))) && (__GET_VAR(data__->CX,.SUN_VER) < __GET_VAR(data__->VERT,))) && (_DT_TO_TOD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->CX,.UTC)) > (__GET_VAR(data__->CX,.SUN_RISE) + TIME_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (TIME)__GET_VAR(data__->SUNRISE_OFFSET,))))) && (_DT_TO_TOD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->CX,.UTC)) < (__GET_VAR(data__->CX,.SUN_SET) - TIME_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (TIME)__GET_VAR(data__->SUNSET_PRESET,)))))) {
    __SET_VAR(data__->,QU,,__GET_VAR(data__->UP,));
    __SET_VAR(data__->,QD,,__GET_VAR(data__->DN,));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(151));
    __SET_VAR(data__->,PO,,MIN__BYTE__BYTE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)2,
      (BYTE)__GET_VAR(data__->PI,),
      (BYTE)__GET_VAR(data__->SHADE_POS,)));
  } else {
    __SET_VAR(data__->,QU,,__GET_VAR(data__->UP,));
    __SET_VAR(data__->,QD,,__GET_VAR(data__->DN,));
    __SET_VAR(data__->,PO,,__GET_VAR(data__->PI,));
    __SET_VAR(data__->,STATUS,,__GET_VAR(data__->S_IN,));
  };

  goto __end;

__end:
  return;
} // BLIND_SHADE_S_body__() 





void SEQUENCE_8_init__(SEQUENCE_8 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN0,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN1,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN2,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN3,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN4,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN5,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN6,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN7,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->START,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->WAIT0,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DELAY0,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->WAIT1,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DELAY1,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->WAIT2,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DELAY2,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->WAIT3,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DELAY3,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->WAIT4,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DELAY4,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->WAIT5,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DELAY5,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->WAIT6,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DELAY6,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->WAIT7,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DELAY7,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->STOP_ON_ERROR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q5,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q6,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q7,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->QX,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RUN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_STEP,-1,retain)
  __INIT_VAR(data__->STATUS,0,retain)
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void SEQUENCE_8_body__(SEQUENCE_8 *data__) {
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
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(110));
  };
  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,_STEP,,-1);
    __SET_VAR(data__->,Q0,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q3,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q4,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q5,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q6,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q7,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(110));
    __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
  } else if ((__GET_VAR(data__->START,) && !(__GET_VAR(data__->EDGE,)))) {
    __SET_VAR(data__->,_STEP,,0);
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(111));
    __SET_VAR(data__->,Q0,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q3,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q4,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q5,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q6,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q7,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,RUN,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->START,));
  if ((((__GET_VAR(data__->STATUS,) > __BYTE_LITERAL(0)) && (__GET_VAR(data__->STATUS,) < __BYTE_LITERAL(100))) && __GET_VAR(data__->STOP_ON_ERROR,))) {
    goto __end;
  };
  if ((__GET_VAR(data__->RUN,) && (__GET_VAR(data__->_STEP,) == 0))) {
    if (((!(__GET_VAR(data__->Q0,)) && __GET_VAR(data__->IN0,)) && LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT0,)))) {
      __SET_VAR(data__->,Q0,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    } else if ((!(__GET_VAR(data__->Q0,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT0,)))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(1));
      __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
    } else if ((__GET_VAR(data__->Q0,) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY0,)))) {
      __SET_VAR(data__->,_STEP,,1);
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    };
  };
  if ((__GET_VAR(data__->RUN,) && (__GET_VAR(data__->_STEP,) == 1))) {
    if (((!(__GET_VAR(data__->Q1,)) && __GET_VAR(data__->IN1,)) && LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT1,)))) {
      __SET_VAR(data__->,Q0,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,Q1,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    } else if ((!(__GET_VAR(data__->Q1,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT1,)))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(2));
      __SET_VAR(data__->,Q0,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
    } else if ((__GET_VAR(data__->Q1,) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY1,)))) {
      __SET_VAR(data__->,_STEP,,2);
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    };
  };
  if ((__GET_VAR(data__->RUN,) && (__GET_VAR(data__->_STEP,) == 2))) {
    if (((!(__GET_VAR(data__->Q2,)) && __GET_VAR(data__->IN2,)) && LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT2,)))) {
      __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,Q2,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    } else if ((!(__GET_VAR(data__->Q2,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT2,)))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(3));
      __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
    } else if ((__GET_VAR(data__->Q2,) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY2,)))) {
      __SET_VAR(data__->,_STEP,,3);
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    };
  };
  if ((__GET_VAR(data__->RUN,) && (__GET_VAR(data__->_STEP,) == 3))) {
    if (((!(__GET_VAR(data__->Q3,)) && __GET_VAR(data__->IN3,)) && LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT3,)))) {
      __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,Q3,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    } else if ((!(__GET_VAR(data__->Q3,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT3,)))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(4));
      __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
    } else if ((__GET_VAR(data__->Q3,) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY3,)))) {
      __SET_VAR(data__->,_STEP,,4);
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    };
  };
  if ((__GET_VAR(data__->RUN,) && (__GET_VAR(data__->_STEP,) == 4))) {
    if (((!(__GET_VAR(data__->Q4,)) && __GET_VAR(data__->IN4,)) && LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT4,)))) {
      __SET_VAR(data__->,Q3,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,Q4,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    } else if ((!(__GET_VAR(data__->Q4,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT4,)))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(5));
      __SET_VAR(data__->,Q3,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
    } else if ((__GET_VAR(data__->Q4,) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT4,)))) {
      __SET_VAR(data__->,_STEP,,5);
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    };
  };
  if ((__GET_VAR(data__->RUN,) && (__GET_VAR(data__->_STEP,) == 5))) {
    if (((!(__GET_VAR(data__->Q5,)) && __GET_VAR(data__->IN5,)) && LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY4,)))) {
      __SET_VAR(data__->,Q4,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,Q5,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    } else if ((!(__GET_VAR(data__->Q5,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY4,)))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(6));
      __SET_VAR(data__->,Q4,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
    } else if ((__GET_VAR(data__->Q5,) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT5,)))) {
      __SET_VAR(data__->,_STEP,,6);
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    };
  };
  if ((__GET_VAR(data__->RUN,) && (__GET_VAR(data__->_STEP,) == 6))) {
    if (((!(__GET_VAR(data__->Q6,)) && __GET_VAR(data__->IN6,)) && LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY5,)))) {
      __SET_VAR(data__->,Q5,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,Q6,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    } else if ((!(__GET_VAR(data__->Q6,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY5,)))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(7));
      __SET_VAR(data__->,Q5,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
    } else if ((__GET_VAR(data__->Q6,) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT6,)))) {
      __SET_VAR(data__->,_STEP,,7);
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    };
  };
  if ((__GET_VAR(data__->RUN,) && (__GET_VAR(data__->_STEP,) == 7))) {
    if (((!(__GET_VAR(data__->Q7,)) && __GET_VAR(data__->IN7,)) && LE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY6,)))) {
      __SET_VAR(data__->,Q6,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,Q7,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    } else if ((!(__GET_VAR(data__->Q7,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->DELAY6,)))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(8));
      __SET_VAR(data__->,Q6,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
    } else if ((__GET_VAR(data__->Q7,) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->WAIT7,)))) {
      __SET_VAR(data__->,_STEP,,-1);
      __SET_VAR(data__->,Q7,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,RUN,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(110));
    };
  };
  __SET_VAR(data__->,QX,,(((((((__GET_VAR(data__->Q0,) || __GET_VAR(data__->Q1,)) || __GET_VAR(data__->Q2,)) || __GET_VAR(data__->Q3,)) || __GET_VAR(data__->Q4,)) || __GET_VAR(data__->Q5,)) || __GET_VAR(data__->Q6,)) || __GET_VAR(data__->Q7,)));

  goto __end;

__end:
  return;
} // SEQUENCE_8_body__() 





void LEGIONELLA_init__(LEGIONELLA *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->MANUAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TEMP_BOILER,0,retain)
  __INIT_VAR(data__->TEMP_RETURN,100.0,retain)
  __INIT_VAR(data__->DT_IN,0,retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->T_START,10800000,retain)
  __INIT_VAR(data__->DAY,7,retain)
  __INIT_VAR(data__->TEMP_SET,70.0,retain)
  __INIT_VAR(data__->TEMP_OFFSET,10.0,retain)
  __INIT_VAR(data__->TEMP_HYS,5.0,retain)
  __INIT_VAR(data__->T_MAX_HEAT,__time_to_timespec(1, 0, 0, 10, 0, 0),retain)
  __INIT_VAR(data__->T_MAX_RET,__time_to_timespec(1, 0, 0, 10, 0, 0),retain)
  __INIT_VAR(data__->TP_0,__time_to_timespec(1, 0, 0, 5, 0, 0),retain)
  __INIT_VAR(data__->TP_1,__time_to_timespec(1, 0, 0, 5, 0, 0),retain)
  __INIT_VAR(data__->TP_2,__time_to_timespec(1, 0, 0, 5, 0, 0),retain)
  __INIT_VAR(data__->TP_3,__time_to_timespec(1, 0, 0, 5, 0, 0),retain)
  __INIT_VAR(data__->TP_4,__time_to_timespec(1, 0, 0, 5, 0, 0),retain)
  __INIT_VAR(data__->TP_5,__time_to_timespec(1, 0, 0, 5, 0, 0),retain)
  __INIT_VAR(data__->TP_6,__time_to_timespec(1, 0, 0, 5, 0, 0),retain)
  __INIT_VAR(data__->TP_7,__time_to_timespec(1, 0, 0, 5, 0, 0),retain)
  __INIT_VAR(data__->HEAT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PUMP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VALVE0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VALVE1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VALVE2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VALVE3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VALVE4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VALVE5,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VALVE6,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VALVE7,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RUN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATUS,0,retain)
  TIMER_1_init__(&data__->X1,retain);
  SEQUENCE_8_init__(&data__->X2,retain);
  HYST_1_init__(&data__->X3,retain);
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LEGIONELLA_body__(LEGIONELLA *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,X1.DAY,,SHR__BYTE__BYTE__INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__BYTE_LITERAL(128),
      (INT)__GET_VAR(data__->DAY,)));
    __SET_VAR(data__->,X1.START,,__GET_VAR(data__->T_START,));
    __SET_VAR(data__->,X3.LOW,,(__GET_VAR(data__->TEMP_OFFSET,) + __GET_VAR(data__->TEMP_SET,)));
    __SET_VAR(data__->,X3.HIGH,,(__GET_VAR(data__->TEMP_HYS,) + __GET_VAR(data__->X3.LOW,)));
    __SET_VAR(data__->,X2.WAIT0,,__GET_VAR(data__->T_MAX_HEAT,));
    __SET_VAR(data__->,X2.DELAY0,,__GET_VAR(data__->TP_0,));
    __SET_VAR(data__->,X2.DELAY1,,__GET_VAR(data__->TP_1,));
    __SET_VAR(data__->,X2.DELAY2,,__GET_VAR(data__->TP_2,));
    __SET_VAR(data__->,X2.DELAY3,,__GET_VAR(data__->TP_3,));
    __SET_VAR(data__->,X2.DELAY4,,__GET_VAR(data__->TP_4,));
    __SET_VAR(data__->,X2.DELAY5,,__GET_VAR(data__->TP_5,));
    __SET_VAR(data__->,X2.DELAY6,,__GET_VAR(data__->TP_6,));
    __SET_VAR(data__->,X2.DELAY7,,__GET_VAR(data__->TP_7,));
    __SET_VAR(data__->,X2.WAIT1,,__GET_VAR(data__->T_MAX_RET,));
    __SET_VAR(data__->,X2.WAIT2,,__GET_VAR(data__->T_MAX_RET,));
    __SET_VAR(data__->,X2.WAIT3,,__GET_VAR(data__->T_MAX_RET,));
    __SET_VAR(data__->,X2.WAIT4,,__GET_VAR(data__->T_MAX_RET,));
    __SET_VAR(data__->,X2.WAIT5,,__GET_VAR(data__->T_MAX_RET,));
    __SET_VAR(data__->,X2.WAIT6,,__GET_VAR(data__->T_MAX_RET,));
    __SET_VAR(data__->,X2.WAIT7,,__GET_VAR(data__->T_MAX_RET,));
    SEQUENCE_8_body__(&data__->X2);
  };
  __SET_VAR(data__->X1.,DTI,,__GET_VAR(data__->DT_IN,));
  TIMER_1_body__(&data__->X1);
  if (((__GET_VAR(data__->X1.Q,) || __GET_VAR(data__->MANUAL,)) || __GET_VAR(data__->X2.RUN,))) {
    __SET_VAR(data__->X3.,IN,,__GET_VAR(data__->TEMP_BOILER,));
    HYST_1_body__(&data__->X3);
    __SET_VAR(data__->,X2.IN0,,(__GET_VAR(data__->X3.Q,) || __GET_VAR(data__->X3.WIN,)));
    __SET_VAR(data__->,X2.IN1,,(__GET_VAR(data__->TEMP_RETURN,) >= __GET_VAR(data__->TEMP_SET,)));
    __SET_VAR(data__->,X2.IN2,,__GET_VAR(data__->X2.IN1,));
    __SET_VAR(data__->,X2.IN3,,__GET_VAR(data__->X2.IN1,));
    __SET_VAR(data__->,X2.IN4,,__GET_VAR(data__->X2.IN1,));
    __SET_VAR(data__->,X2.IN5,,__GET_VAR(data__->X2.IN1,));
    __SET_VAR(data__->,X2.IN6,,__GET_VAR(data__->X2.IN1,));
    __SET_VAR(data__->,X2.IN7,,__GET_VAR(data__->X2.IN1,));
    __SET_VAR(data__->,X2.RST,,__GET_VAR(data__->RST,));
    __SET_VAR(data__->X2.,START,,(__GET_VAR(data__->X1.Q,) || __GET_VAR(data__->MANUAL,)));
    SEQUENCE_8_body__(&data__->X2);
    __SET_VAR(data__->,RUN,,__GET_VAR(data__->X2.RUN,));
    __SET_VAR(data__->,PUMP,,__GET_VAR(data__->X2.QX,));
    __SET_VAR(data__->,HEAT,,(!(__GET_VAR(data__->X3.Q,)) && __GET_VAR(data__->X2.RUN,)));
    __SET_VAR(data__->,VALVE0,,__GET_VAR(data__->X2.Q0,));
    __SET_VAR(data__->,VALVE1,,__GET_VAR(data__->X2.Q1,));
    __SET_VAR(data__->,VALVE2,,__GET_VAR(data__->X2.Q2,));
    __SET_VAR(data__->,VALVE3,,__GET_VAR(data__->X2.Q3,));
    __SET_VAR(data__->,VALVE4,,__GET_VAR(data__->X2.Q4,));
    __SET_VAR(data__->,VALVE5,,__GET_VAR(data__->X2.Q5,));
    __SET_VAR(data__->,VALVE6,,__GET_VAR(data__->X2.Q6,));
    __SET_VAR(data__->,VALVE7,,__GET_VAR(data__->X2.Q7,));
    __SET_VAR(data__->,PUMP,,__GET_VAR(data__->X2.QX,));
    __SET_VAR(data__->,STATUS,,__GET_VAR(data__->X2.STATUS,));
  } else {
    __SET_VAR(data__->X2.,START,,__BOOL_LITERAL(FALSE));
    SEQUENCE_8_body__(&data__->X2);
    __SET_VAR(data__->,STATUS,,__GET_VAR(data__->X2.STATUS,));
  };

  goto __end;

__end:
  return;
} // LEGIONELLA_body__() 





void BURNER_init__(BURNER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STAGE2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OVER_TEMP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OIL_TEMP,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->FLAME,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST_TIMER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PRE_HEAT_TIME,__time_to_timespec(1, 0, 5, 0, 0, 0),retain)
  __INIT_VAR(data__->PRE_VENT_TIME,__time_to_timespec(1, 0, 15, 0, 0, 0),retain)
  __INIT_VAR(data__->PRE_IGNITE_TIME,__time_to_timespec(1, 0, 15, 0, 0, 0),retain)
  __INIT_VAR(data__->POST_IGNITE_TIME,__time_to_timespec(1, 0, 25, 0, 0, 0),retain)
  __INIT_VAR(data__->STAGE2_DELAY,__time_to_timespec(1, 0, 10, 0, 0, 0),retain)
  __INIT_VAR(data__->SAFETY_TIME,__time_to_timespec(1, 0, 5, 0, 0, 0),retain)
  __INIT_VAR(data__->LOCKOUT_TIME,__time_to_timespec(1, 0, 10, 0, 0, 0),retain)
  __INIT_VAR(data__->MULTIPLE_IGNITION,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->KW1,0,retain)
  __INIT_VAR(data__->KW2,0,retain)
  __INIT_VAR(data__->MOTOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->COIL1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->COIL2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PRE_HEAT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IGNITE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FAIL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->KWH,0,retain)
  __INIT_VAR(data__->STATUS,0,retain)
  __INIT_VAR(data__->RUNTIME1,0,retain)
  __INIT_VAR(data__->RUNTIME2,0,retain)
  __INIT_VAR(data__->CYCLES,0,retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->LAST_CHANGE,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  ONTIME_init__(&data__->TIMER1,retain);
  ONTIME_init__(&data__->TIMER2,retain);
  __INIT_VAR(data__->OIL_TEMP_LAST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CYCLES2,0,retain)
}

// Code part
void BURNER_body__(BURNER *data__) {
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
  if (((__GET_VAR(data__->RST,) || __GET_VAR(data__->OVER_TEMP,)) || (__GET_VAR(data__->STATE,) == 0))) {
    if ((((__GET_VAR(data__->STATUS,) > __BYTE_LITERAL(0)) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST_CHANGE,)), __GET_VAR(data__->LOCKOUT_TIME,))) && __GET_VAR(data__->RST,))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(110));
      __SET_VAR(data__->,FAIL,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,STATE,,1);
    } else {
      __SET_VAR(data__->,MOTOR,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,COIL1,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,COIL2,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,IGNITE,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,PRE_HEAT,,__BOOL_LITERAL(FALSE));
      if (__GET_VAR(data__->OVER_TEMP,)) {
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(9));
        __SET_VAR(data__->,FAIL,,__BOOL_LITERAL(TRUE));
      };
      __SET_VAR(data__->,LAST_CHANGE,,__GET_VAR(data__->TX,));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
      __SET_VAR(data__->,STATE,,1);
    };
  };
  if (__GET_VAR(data__->RST_TIMER,)) {
    __SET_VAR(data__->,RUNTIME1,,__UDINT_LITERAL(0));
    __SET_VAR(data__->,RUNTIME2,,__UDINT_LITERAL(0));
    __SET_VAR(data__->,CYCLES,,__UDINT_LITERAL(0));
    __SET_VAR(data__->,CYCLES2,,__UDINT_LITERAL(0));
  };
  if ((((__GET_VAR(data__->STATUS,) > __BYTE_LITERAL(0)) && (__GET_VAR(data__->STATUS,) < __BYTE_LITERAL(100))) || __GET_VAR(data__->RST,))) {
    goto __end;
  };
  {
    INT __case_expression = __GET_VAR(data__->STATE,);
    if ((__case_expression == 1)) {
      if ((__GET_VAR(data__->IN,) && __GET_VAR(data__->FLAME,))) {
        __SET_VAR(data__->,STATE,,7);
        __SET_VAR(data__->,PRE_HEAT,,__BOOL_LITERAL(FALSE));
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(2));
        __SET_VAR(data__->,LAST_CHANGE,,__GET_VAR(data__->TX,));
      } else if (__GET_VAR(data__->IN,)) {
        __SET_VAR(data__->,PRE_HEAT,,__BOOL_LITERAL(TRUE));
        __SET_VAR(data__->,STATE,,2);
        __SET_VAR(data__->,LAST_CHANGE,,__GET_VAR(data__->TX,));
      };
    }
    else if ((__case_expression == 2)) {
      if (((GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST_CHANGE,)), __GET_VAR(data__->PRE_HEAT_TIME,)) && __GET_VAR(data__->OIL_TEMP,)) || (__GET_VAR(data__->OIL_TEMP,) && !(__GET_VAR(data__->OIL_TEMP_LAST,))))) {
        __SET_VAR(data__->,MOTOR,,__BOOL_LITERAL(TRUE));
        __SET_VAR(data__->,STATE,,3);
        __SET_VAR(data__->,LAST_CHANGE,,__GET_VAR(data__->TX,));
      } else if ((GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST_CHANGE,)), __GET_VAR(data__->PRE_HEAT_TIME,)) && !(__GET_VAR(data__->OIL_TEMP,)))) {
        __SET_VAR(data__->,STATE,,7);
        __SET_VAR(data__->,PRE_HEAT,,__BOOL_LITERAL(FALSE));
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(1));
        __SET_VAR(data__->,LAST_CHANGE,,__GET_VAR(data__->TX,));
      } else if (__GET_VAR(data__->FLAME,)) {
        __SET_VAR(data__->,STATE,,7);
        __SET_VAR(data__->,PRE_HEAT,,__BOOL_LITERAL(FALSE));
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(2));
        __SET_VAR(data__->,LAST_CHANGE,,__GET_VAR(data__->TX,));
      };
    }
    else if ((__case_expression == 3)) {
      if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST_CHANGE,)), __time_sub(__GET_VAR(data__->PRE_VENT_TIME,), __GET_VAR(data__->PRE_IGNITE_TIME,)))) {
        __SET_VAR(data__->,IGNITE,,__BOOL_LITERAL(TRUE));
        __SET_VAR(data__->,STATE,,4);
        __SET_VAR(data__->,LAST_CHANGE,,__GET_VAR(data__->TX,));
      } else if (__GET_VAR(data__->FLAME,)) {
        __SET_VAR(data__->,STATE,,7);
        __SET_VAR(data__->,PRE_HEAT,,__BOOL_LITERAL(FALSE));
        __SET_VAR(data__->,MOTOR,,__BOOL_LITERAL(FALSE));
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(3));
        __SET_VAR(data__->,LAST_CHANGE,,__GET_VAR(data__->TX,));
      };
    }
    else if ((__case_expression == 4)) {
      if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST_CHANGE,)), __GET_VAR(data__->PRE_IGNITE_TIME,))) {
        __SET_VAR(data__->,COIL1,,__BOOL_LITERAL(TRUE));
        __SET_VAR(data__->,STATE,,5);
        __SET_VAR(data__->,LAST_CHANGE,,__GET_VAR(data__->TX,));
      };
    }
    else if ((__case_expression == 5)) {
      if ((GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST_CHANGE,)), __GET_VAR(data__->SAFETY_TIME,)) || __GET_VAR(data__->FLAME,))) {
        if (!(__GET_VAR(data__->FLAME,))) {
          __SET_VAR(data__->,STATE,,7);
          __SET_VAR(data__->,MOTOR,,__BOOL_LITERAL(FALSE));
          __SET_VAR(data__->,COIL1,,__BOOL_LITERAL(FALSE));
          __SET_VAR(data__->,PRE_HEAT,,__BOOL_LITERAL(FALSE));
          __SET_VAR(data__->,IGNITE,,__BOOL_LITERAL(FALSE));
          __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(4));
          __SET_VAR(data__->,LAST_CHANGE,,__GET_VAR(data__->TX,));
        } else {
          __SET_VAR(data__->,STATE,,6);
          __SET_VAR(data__->,LAST_CHANGE,,__GET_VAR(data__->TX,));
        };
      };
    }
    else if ((__case_expression == 6)) {
      if ((!(__GET_VAR(data__->FLAME,)) && !(__GET_VAR(data__->MULTIPLE_IGNITION,)))) {
        __SET_VAR(data__->,STATE,,7);
        __SET_VAR(data__->,MOTOR,,__BOOL_LITERAL(FALSE));
        __SET_VAR(data__->,COIL1,,__BOOL_LITERAL(FALSE));
        __SET_VAR(data__->,COIL2,,__BOOL_LITERAL(FALSE));
        __SET_VAR(data__->,PRE_HEAT,,__BOOL_LITERAL(FALSE));
        __SET_VAR(data__->,IGNITE,,__BOOL_LITERAL(FALSE));
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(5));
        __SET_VAR(data__->,LAST_CHANGE,,__GET_VAR(data__->TX,));
      } else if ((!(__GET_VAR(data__->FLAME,)) && __GET_VAR(data__->MULTIPLE_IGNITION,))) {
        __SET_VAR(data__->,IGNITE,,__BOOL_LITERAL(TRUE));
        __SET_VAR(data__->,STATE,,5);
        __SET_VAR(data__->,COIL2,,__BOOL_LITERAL(FALSE));
        __SET_VAR(data__->,LAST_CHANGE,,__GET_VAR(data__->TX,));
      } else {
        if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST_CHANGE,)), __GET_VAR(data__->POST_IGNITE_TIME,))) {
          __SET_VAR(data__->,IGNITE,,__BOOL_LITERAL(FALSE));
        };
        if ((GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST_CHANGE,)), __GET_VAR(data__->STAGE2_DELAY,)) && __GET_VAR(data__->STAGE2,))) {
          __SET_VAR(data__->,COIL2,,__BOOL_LITERAL(TRUE));
        } else {
          __SET_VAR(data__->,COIL2,,__BOOL_LITERAL(FALSE));
        };
      };
    }
  };
  if (!(__GET_VAR(data__->IN,))) {
    __SET_VAR(data__->,STATE,,1);
    __SET_VAR(data__->,MOTOR,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,COIL1,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,COIL2,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,IGNITE,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,PRE_HEAT,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,LAST_CHANGE,,__GET_VAR(data__->TX,));
  };
  __SET_VAR(data__->TIMER1.,IN,,((((__GET_VAR(data__->FLAME,) && __GET_VAR(data__->IN,)) && __GET_VAR(data__->MOTOR,)) && __GET_VAR(data__->COIL1,)) && !(__GET_VAR(data__->COIL2,))));
  __SET_VAR(data__->TIMER1.,SECONDS,,__GET_VAR(data__->RUNTIME1,));
  __SET_VAR(data__->TIMER1.,CYCLES,,__GET_VAR(data__->CYCLES,));
  ONTIME_body__(&data__->TIMER1);
  __SET_VAR(data__->,RUNTIME1,,__GET_VAR(data__->TIMER1.SECONDS));
  __SET_VAR(data__->,CYCLES,,__GET_VAR(data__->TIMER1.CYCLES));
  __SET_VAR(data__->,CYCLES,,__GET_VAR(data__->TIMER1.CYCLES,));
  __SET_VAR(data__->,RUNTIME1,,__GET_VAR(data__->TIMER1.SECONDS,));
  __SET_VAR(data__->TIMER2.,IN,,((((__GET_VAR(data__->FLAME,) && __GET_VAR(data__->IN,)) && __GET_VAR(data__->MOTOR,)) && __GET_VAR(data__->COIL1,)) && __GET_VAR(data__->COIL2,)));
  __SET_VAR(data__->TIMER2.,SECONDS,,__GET_VAR(data__->RUNTIME2,));
  __SET_VAR(data__->TIMER2.,CYCLES,,__GET_VAR(data__->CYCLES2,));
  ONTIME_body__(&data__->TIMER2);
  __SET_VAR(data__->,RUNTIME2,,__GET_VAR(data__->TIMER2.SECONDS));
  __SET_VAR(data__->,CYCLES2,,__GET_VAR(data__->TIMER2.CYCLES));
  __SET_VAR(data__->,CYCLES2,,__GET_VAR(data__->TIMER2.CYCLES,));
  __SET_VAR(data__->,RUNTIME2,,__GET_VAR(data__->TIMER2.SECONDS,));
  __SET_VAR(data__->,KWH,,(((UDINT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->RUNTIME1,)) * __GET_VAR(data__->KW1,)) / 3600.0) + ((UDINT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->RUNTIME2,)) * __GET_VAR(data__->KW2,)) / 3600.0)));
  __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
  if (((__GET_VAR(data__->STATUS,) > __BYTE_LITERAL(0)) && (__GET_VAR(data__->STATUS,) < __BYTE_LITERAL(100)))) {
    __SET_VAR(data__->,FAIL,,__BOOL_LITERAL(TRUE));
  } else {
    __SET_VAR(data__->,FAIL,,__BOOL_LITERAL(FALSE));
    if (!(__GET_VAR(data__->IN,))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(110));
    } else if (((((__GET_VAR(data__->FLAME,) && __GET_VAR(data__->IN,)) && __GET_VAR(data__->MOTOR,)) && __GET_VAR(data__->COIL2,)) && __GET_VAR(data__->COIL1,))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(113));
    } else if ((((__GET_VAR(data__->FLAME,) && __GET_VAR(data__->IN,)) && __GET_VAR(data__->MOTOR,)) && __GET_VAR(data__->COIL1,))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(112));
    } else {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(111));
    };
  };

  goto __end;

__end:
  return;
} // BURNER_body__() 





void ACTUATOR_A_init__(ACTUATOR_A *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->I1,0,retain)
  __INIT_VAR(data__->I2,0,retain)
  __INIT_VAR(data__->IS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RV,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DX,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RUNTIME,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->SELF_ACT_TIME,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->OUT_MIN,0,retain)
  __INIT_VAR(data__->OUT_MAX,0,retain)
  __INIT_VAR(data__->Y,0,retain)
  CYCLE_4_init__(&data__->TIMER,retain);
  __INIT_VAR(data__->DX_EDGE,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void ACTUATOR_A_body__(ACTUATOR_A *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->TIMER.,T0,,__GET_VAR(data__->RUNTIME,));
  __SET_VAR(data__->TIMER.,T1,,__GET_VAR(data__->RUNTIME,));
  __SET_VAR(data__->TIMER.,T3,,__GET_VAR(data__->SELF_ACT_TIME,));
  __SET_VAR(data__->TIMER.,S0,,GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->SELF_ACT_TIME,), __time_to_timespec(1, 0, 0, 0, 0, 0)));
  __SET_VAR(data__->TIMER.,SX,,0);
  __SET_VAR(data__->TIMER.,SL,,(__GET_VAR(data__->DX,) && !(__GET_VAR(data__->DX_EDGE,))));
  CYCLE_4_body__(&data__->TIMER);
  __SET_VAR(data__->,DX_EDGE,,__GET_VAR(data__->DX,));
  {
    INT __case_expression = __GET_VAR(data__->TIMER.STATE,);
    if ((__case_expression == 0)) {
      __SET_VAR(data__->,Y,,__GET_VAR(data__->OUT_MIN,));
    }
    else if ((__case_expression == 1)) {
      __SET_VAR(data__->,Y,,__GET_VAR(data__->OUT_MAX,));
    }
    else if ((__case_expression == 3)) {
      if (__GET_VAR(data__->RV,)) {
        __SET_VAR(data__->,Y,,UDINT_TO_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (UDINT)(DWORD_TO_UDINT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (DWORD)__GET_VAR(data__->OUT_MAX,)) - (((DWORD_TO_UDINT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (DWORD)__GET_VAR(data__->OUT_MAX,)) - DWORD_TO_UDINT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (DWORD)__GET_VAR(data__->OUT_MIN,))) * BYTE_TO_UDINT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (BYTE)SEL__BYTE__BOOL__BYTE__BYTE(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (BOOL)__GET_VAR(data__->IS,),
              (BYTE)__GET_VAR(data__->I1,),
              (BYTE)__GET_VAR(data__->I2,)))) / __UDINT_LITERAL(255)))));
      } else {
        __SET_VAR(data__->,Y,,UDINT_TO_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (UDINT)((((DWORD_TO_UDINT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (DWORD)__GET_VAR(data__->OUT_MAX,)) - DWORD_TO_UDINT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (DWORD)__GET_VAR(data__->OUT_MIN,))) * BYTE_TO_UDINT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (BYTE)SEL__BYTE__BOOL__BYTE__BYTE(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (BOOL)__GET_VAR(data__->IS,),
              (BYTE)__GET_VAR(data__->I1,),
              (BYTE)__GET_VAR(data__->I2,)))) / __UDINT_LITERAL(255)) + DWORD_TO_UDINT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (DWORD)__GET_VAR(data__->OUT_MIN,)))));
      };
    }
  };

  goto __end;

__end:
  return;
} // ACTUATOR_A_body__() 





void BLIND_CONTROL_init__(BLIND_CONTROL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->UP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->S_IN,0,retain)
  __INIT_VAR(data__->PI,0,retain)
  __INIT_VAR(data__->AI,0,retain)
  __INIT_VAR(data__->T_UD,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T_ANGLE,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T_LOCKOUT,__time_to_timespec(1, 100, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->SENS,5,retain)
  __INIT_VAR(data__->POS,0,retain)
  __INIT_VAR(data__->ANG,0,retain)
  __INIT_VAR(data__->MU,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATUS,0,retain)
  BLIND_ACTUATOR_init__(&data__->ACT,retain);
  __INIT_VAR(data__->DELTA,0,retain)
  __INIT_VAR(data__->IPOS,0,retain)
  __INIT_VAR(data__->IANGEL,0,retain)
  __INIT_VAR(data__->BTIMETEST,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void BLIND_CONTROL_body__(BLIND_CONTROL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (__GET_VAR(data__->BTIMETEST,)) {
    __SET_VAR(data__->,PI,,__GET_VAR(data__->IPOS,));
    __SET_VAR(data__->,AI,,__GET_VAR(data__->IANGEL,));
    __SET_VAR(data__->,UP,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,DN,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->ACT.,T_UD,,__GET_VAR(data__->T_UD,));
  __SET_VAR(data__->ACT.,T_ANGLE,,__GET_VAR(data__->T_ANGLE,));
  __SET_VAR(data__->ACT.,T_LOCKOUT,,__GET_VAR(data__->T_LOCKOUT,));
  BLIND_ACTUATOR_body__(&data__->ACT);
  if ((__GET_VAR(data__->UP,) && __GET_VAR(data__->DN,))) {
    if ((BYTE_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->ACT.POS,)) < (BYTE_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->PI,)) - BYTE_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->DELTA,))))) {
      __SET_VAR(data__->,ACT.UP,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,ACT.DN,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,DELTA,,__BYTE_LITERAL(0));
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(121));
    } else if ((BYTE_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->ACT.POS,)) > (BYTE_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->PI,)) + BYTE_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->DELTA,))))) {
      __SET_VAR(data__->,ACT.UP,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,ACT.DN,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,DELTA,,__BYTE_LITERAL(0));
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(122));
    } else if (((BYTE_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->ACT.ANG,)) < (BYTE_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->AI,)) - BYTE_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->DELTA,)))) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->T_ANGLE,), __time_to_timespec(1, 100, 0, 0, 0, 0)))) {
      __SET_VAR(data__->,ACT.UP,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,ACT.DN,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,DELTA,,SHR__BYTE__BYTE__SINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->SENS,),
        (SINT)2));
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(123));
    } else if (((BYTE_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->ACT.ANG,)) > (BYTE_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->AI,)) + BYTE_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->DELTA,)))) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->T_ANGLE,), __time_to_timespec(1, 100, 0, 0, 0, 0)))) {
      __SET_VAR(data__->,ACT.UP,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,ACT.DN,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,DELTA,,SHR__BYTE__BYTE__SINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__GET_VAR(data__->SENS,),
        (SINT)2));
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(124));
    } else {
      __SET_VAR(data__->,ACT.UP,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,ACT.DN,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,DELTA,,__GET_VAR(data__->SENS,));
      __SET_VAR(data__->,STATUS,,__GET_VAR(data__->S_IN,));
    };
  } else {
    __SET_VAR(data__->,ACT.UP,,__GET_VAR(data__->UP,));
    __SET_VAR(data__->,ACT.DN,,__GET_VAR(data__->DN,));
    __SET_VAR(data__->,STATUS,,__GET_VAR(data__->S_IN,));
  };
  __SET_VAR(data__->ACT.,T_UD,,__GET_VAR(data__->T_UD,));
  __SET_VAR(data__->ACT.,T_ANGLE,,__GET_VAR(data__->T_ANGLE,));
  __SET_VAR(data__->ACT.,T_LOCKOUT,,__GET_VAR(data__->T_LOCKOUT,));
  BLIND_ACTUATOR_body__(&data__->ACT);
  __SET_VAR(data__->,POS,,__GET_VAR(data__->ACT.POS,));
  __SET_VAR(data__->,ANG,,__GET_VAR(data__->ACT.ANG,));
  __SET_VAR(data__->,MU,,__GET_VAR(data__->ACT.QU,));
  __SET_VAR(data__->,MD,,__GET_VAR(data__->ACT.QD,));
  __SET_VAR(data__->,STATUS,,__GET_VAR(data__->ACT.STATUS,));

  goto __end;

__end:
  return;
} // BLIND_CONTROL_body__() 





void BLIND_INPUT_init__(BLIND_INPUT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->POS,0,retain)
  __INIT_VAR(data__->ANG,0,retain)
  __INIT_VAR(data__->S1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->S2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PI,0,retain)
  __INIT_VAR(data__->AI,0,retain)
  __INIT_VAR(data__->SINGLE_SWITCH,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CLICK_EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->CLICK_TIME,__time_to_timespec(1, 500, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->MAX_RUNTIME,__time_to_timespec(1, 0, 60, 0, 0, 0),retain)
  __INIT_VAR(data__->MANUAL_TIMEOUT,__time_to_timespec(1, 0, 0, 0, 1, 0),retain)
  __INIT_VAR(data__->DEBOUNCE_TIME,__time_to_timespec(1, 20, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->DBL_CLK1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DBL_POS1,0,retain)
  __INIT_VAR(data__->DBL_ANG1,0,retain)
  __INIT_VAR(data__->DBL_CLK2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DBL_POS2,255,retain)
  __INIT_VAR(data__->DBL_ANG2,255,retain)
  __INIT_VAR(data__->D1_TOGGLE,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->D2_TOGGLE,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->MASTER_MODE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->QU,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->QD,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->STATUS,0,retain)
  __INIT_VAR(data__->PO,255,retain)
  __INIT_VAR(data__->AO,255,retain)
  __INIT_VAR(data__->D1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->D2,__BOOL_LITERAL(FALSE),retain)
  TOF_init__(&data__->S1E,retain);
  TOF_init__(&data__->S2E,retain);
  CLICK_MODE_init__(&data__->S1D,retain);
  CLICK_MODE_init__(&data__->S2D,retain);
  __INIT_VAR(data__->DIR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
}

// Code part
void BLIND_INPUT_body__(BLIND_INPUT *data__) {
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
  __SET_VAR(data__->S1E.,IN,,__GET_VAR(data__->S1,));
  __SET_VAR(data__->S1E.,PT,,__GET_VAR(data__->DEBOUNCE_TIME,));
  TOF_body__(&data__->S1E);
  __SET_VAR(data__->S2E.,IN,,__GET_VAR(data__->S2,));
  __SET_VAR(data__->S2E.,PT,,__GET_VAR(data__->DEBOUNCE_TIME,));
  TOF_body__(&data__->S2E);
  __SET_VAR(data__->S1D.,IN,,((__GET_VAR(data__->S1E.Q,) && !(__GET_VAR(data__->SINGLE_SWITCH,))) || ((__GET_VAR(data__->S1E.Q,) && __GET_VAR(data__->SINGLE_SWITCH,)) && __GET_VAR(data__->DIR,))));
  __SET_VAR(data__->S1D.,T_LONG,,__GET_VAR(data__->CLICK_TIME,));
  CLICK_MODE_body__(&data__->S1D);
  __SET_VAR(data__->S2D.,IN,,((__GET_VAR(data__->S2E.Q,) && !(__GET_VAR(data__->SINGLE_SWITCH,))) || ((__GET_VAR(data__->S1E.Q,) && __GET_VAR(data__->SINGLE_SWITCH,)) && !(__GET_VAR(data__->DIR,)))));
  __SET_VAR(data__->S2D.,T_LONG,,__GET_VAR(data__->CLICK_TIME,));
  CLICK_MODE_body__(&data__->S2D);
  if (!(__GET_VAR(data__->D1_TOGGLE,))) {
    __SET_VAR(data__->,D1,,__BOOL_LITERAL(FALSE));
  };
  if (!(__GET_VAR(data__->D2_TOGGLE,))) {
    __SET_VAR(data__->,D2,,__BOOL_LITERAL(FALSE));
  };
  if (((__GET_VAR(data__->S1D.LONG,) && __GET_VAR(data__->S2D.LONG,)) || (__GET_VAR(data__->STATUS,) == __BYTE_LITERAL(139)))) {
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(139));
    if (!((__GET_VAR(data__->S1D.LONG,) || __GET_VAR(data__->S2D.LONG,)))) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(130));
    };
  } else if (__GET_VAR(data__->S1D.TP_LONG,)) {
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(132));
  } else if (__GET_VAR(data__->S2D.TP_LONG,)) {
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(133));
  } else if (__GET_VAR(data__->S1D.SINGLE,)) {
    if (__GET_VAR(data__->CLICK_EN,)) {
      if ((__GET_VAR(data__->QU,) && !__GET_VAR(data__->QD,)) || (!__GET_VAR(data__->QU,) && __GET_VAR(data__->QD,))) {
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(131));
      } else {
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(134));
        __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
        __SET_VAR(data__->,DIR,,!(__GET_VAR(data__->DIR,)));
      };
    };
  } else if (__GET_VAR(data__->S2D.SINGLE,)) {
    if (__GET_VAR(data__->CLICK_EN,)) {
      if ((__GET_VAR(data__->QU,) && !__GET_VAR(data__->QD,)) || (!__GET_VAR(data__->QU,) && __GET_VAR(data__->QD,))) {
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(131));
      } else {
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(135));
        __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
        __SET_VAR(data__->,DIR,,!(__GET_VAR(data__->DIR,)));
      };
    };
  } else if (__GET_VAR(data__->IN,)) {
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(136));
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
  } else if (__GET_VAR(data__->S1D.DOUBLE,)) {
    if (__GET_VAR(data__->DBL_CLK1,)) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(137));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    } else {
      __SET_VAR(data__->,D1,,!(__GET_VAR(data__->D1,)));
    };
  } else if (__GET_VAR(data__->S2D.DOUBLE,)) {
    if (__GET_VAR(data__->DBL_CLK2,)) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(138));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    } else {
      if (__GET_VAR(data__->SINGLE_SWITCH,)) {
        __SET_VAR(data__->,D1,,!(__GET_VAR(data__->D1,)));
      } else {
        __SET_VAR(data__->,D2,,!(__GET_VAR(data__->D2,)));
      };
    };
  };
  {
    INT __case_expression = BYTE_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->STATUS,));
    if ((__case_expression == 0)) {
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(130));
    }
    else if ((__case_expression == 130)) {
      if (!(__GET_VAR(data__->MASTER_MODE,))) {
        __SET_VAR(data__->,PO,,__GET_VAR(data__->POS,));
        __SET_VAR(data__->,AO,,__GET_VAR(data__->ANG,));
      };
      __SET_VAR(data__->,QU,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,QD,,__BOOL_LITERAL(TRUE));
    }
    else if ((__case_expression == 131)) {
      __SET_VAR(data__->,QU,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,QD,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,PO,,__GET_VAR(data__->POS,));
      __SET_VAR(data__->,AO,,__GET_VAR(data__->ANG,));
      if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->MANUAL_TIMEOUT,))) {
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(130));
      };
    }
    else if ((__case_expression == 132)) {
      __SET_VAR(data__->,QU,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,QD,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,PO,,__GET_VAR(data__->POS,));
      __SET_VAR(data__->,AO,,__GET_VAR(data__->ANG,));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
      if (!(__GET_VAR(data__->S1D.LONG,))) {
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(131));
        __SET_VAR(data__->,DIR,,!(__GET_VAR(data__->DIR,)));
      };
    }
    else if ((__case_expression == 133)) {
      __SET_VAR(data__->,QU,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,QD,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,PO,,__GET_VAR(data__->POS,));
      __SET_VAR(data__->,AO,,__GET_VAR(data__->ANG,));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
      if (!(__GET_VAR(data__->S2D.LONG,))) {
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(131));
        __SET_VAR(data__->,DIR,,!(__GET_VAR(data__->DIR,)));
      };
    }
    else if ((__case_expression == 134)) {
      __SET_VAR(data__->,QU,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,QD,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,PO,,__GET_VAR(data__->POS,));
      __SET_VAR(data__->,AO,,__GET_VAR(data__->ANG,));
      if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->MAX_RUNTIME,))) {
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(131));
      };
    }
    else if ((__case_expression == 135)) {
      __SET_VAR(data__->,QU,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,QD,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,PO,,__GET_VAR(data__->POS,));
      __SET_VAR(data__->,AO,,__GET_VAR(data__->ANG,));
      if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->MAX_RUNTIME,))) {
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(131));
      };
    }
    else if ((__case_expression == 136)) {
      __SET_VAR(data__->,QU,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,QD,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,PO,,__GET_VAR(data__->PI,));
      __SET_VAR(data__->,AO,,__GET_VAR(data__->AI,));
      if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->MAX_RUNTIME,))) {
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(130));
      };
    }
    else if ((__case_expression == 137)) {
      __SET_VAR(data__->,QU,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,QD,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,PO,,__GET_VAR(data__->DBL_POS1,));
      __SET_VAR(data__->,AO,,__GET_VAR(data__->DBL_ANG1,));
      if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->MAX_RUNTIME,))) {
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(131));
      };
    }
    else if ((__case_expression == 138)) {
      __SET_VAR(data__->,QU,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,QD,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,PO,,__GET_VAR(data__->DBL_POS2,));
      __SET_VAR(data__->,AO,,__GET_VAR(data__->DBL_ANG2,));
      if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->MAX_RUNTIME,))) {
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(131));
      };
    }
    else if ((__case_expression == 139)) {
      __SET_VAR(data__->,QU,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,QD,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,PO,,__GET_VAR(data__->POS,));
      __SET_VAR(data__->,AO,,__GET_VAR(data__->ANG,));
    }
  };

  goto __end;

__end:
  return;
} // BLIND_INPUT_body__() 





void SWITCH_I_init__(SWITCH_I *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->SET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->T_DEBOUNCE,__time_to_timespec(1, 10, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T_RECONFIG,__time_to_timespec(1, 0, 1, 0, 0, 0),retain)
  __INIT_VAR(data__->T_ON_MAX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_R_EDGE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->T_ON,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
}

// Code part
void SWITCH_I_body__(SWITCH_I *data__) {
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
  if ((__GET_VAR(data__->SET,) && !(__GET_VAR(data__->RST,)))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,T_ON,,__GET_VAR(data__->TX,));
  } else if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  } else if (((__GET_VAR(data__->IN,) && !__GET_VAR(data__->EDGE,)) || (!__GET_VAR(data__->IN,) && __GET_VAR(data__->EDGE,)) && !((__GET_VAR(data__->STATE,) == __BYTE_LITERAL(1))))) {
    __SET_VAR(data__->,STATE,,__BYTE_LITERAL(1));
    __SET_VAR(data__->,T_ON,,__GET_VAR(data__->TX,));
  } else if (((__GET_VAR(data__->STATE,) == __BYTE_LITERAL(1)) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->T_DEBOUNCE,)), __GET_VAR(data__->T_ON,)))) {
    __SET_VAR(data__->,STATE,,__BYTE_LITERAL(2));
    if ((__GET_VAR(data__->_R_EDGE,) && !__GET_VAR(data__->IN,)) || (!__GET_VAR(data__->_R_EDGE,) && __GET_VAR(data__->IN,))) {
      __SET_VAR(data__->,Q,,!(__GET_VAR(data__->Q,)));
    };
  } else if (((__GET_VAR(data__->STATE,) == __BYTE_LITERAL(2)) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->T_RECONFIG,)), __GET_VAR(data__->T_ON,)))) {
    __SET_VAR(data__->,_R_EDGE,,__GET_VAR(data__->IN,));
  };
  if (((__GET_VAR(data__->Q,) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->T_ON_MAX,), __time_to_timespec(1, 0, 0, 0, 0, 0))) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TX,), __time_add(__GET_VAR(data__->T_ON,), __GET_VAR(data__->T_ON_MAX,))))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->IN,));

  goto __end;

__end:
  return;
} // SWITCH_I_body__() 





void PULSE_T_init__(PULSE_T *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->T1,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T2,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PULSE_T_body__(PULSE_T *data__) {
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
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
  } else if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  } else if (((__GET_VAR(data__->IN,) && !(__GET_VAR(data__->EDGE,))) && !(__GET_VAR(data__->Q,)))) {
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(TRUE));
  } else if (((!(__GET_VAR(data__->IN,)) && __GET_VAR(data__->EDGE,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->T1,)))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  } else if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->T2,))) {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,EDGE,,__GET_VAR(data__->IN,));

  goto __end;

__end:
  return;
} // PULSE_T_body__() 





// FUNCTION
REAL AIR_ENTHALPY(
  BOOL EN, 
  BOOL *__ENO, 
  REAL _T, 
  REAL RH)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL AIR_ENTHALPY = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return AIR_ENTHALPY;
  }
  AIR_ENTHALPY = ((1.00482 * _T) + (((1.86 * _T) + 2500.78) * DEW_CON(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)RH,
    (REAL)_T)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return AIR_ENTHALPY;
}


void PULSE_LENGTH_init__(PULSE_LENGTH *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->T_SHORT,__time_to_timespec(1, 100, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T_LONG,__time_to_timespec(1, 0, 1, 0, 0, 0),retain)
  __INIT_VAR(data__->SHORT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MIDDLE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LONG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TN,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PULSE_LENGTH_body__(PULSE_LENGTH *data__) {
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
  __SET_VAR(data__->,SHORT,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,MIDDLE,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,LONG,,__BOOL_LITERAL(FALSE));
  if ((__GET_VAR(data__->IN,) && !(__GET_VAR(data__->EDGE,)))) {
    __SET_VAR(data__->,EDGE,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,TN,,__GET_VAR(data__->TX,));
  } else if ((!(__GET_VAR(data__->IN,)) && __GET_VAR(data__->EDGE,))) {
    __SET_VAR(data__->,EDGE,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,TN,,__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->TN,)));
    if (LT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TN,), __GET_VAR(data__->T_SHORT,))) {
      __SET_VAR(data__->,SHORT,,__BOOL_LITERAL(TRUE));
    } else if (GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TN,), __GET_VAR(data__->T_LONG,))) {
      __SET_VAR(data__->,LONG,,__BOOL_LITERAL(TRUE));
    } else {
      __SET_VAR(data__->,MIDDLE,,__BOOL_LITERAL(TRUE));
    };
  } else if ((__GET_VAR(data__->IN,) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->TN,)), __GET_VAR(data__->T_LONG,)))) {
    __SET_VAR(data__->,LONG,,__BOOL_LITERAL(TRUE));
  };

  goto __end;

__end:
  return;
} // PULSE_LENGTH_body__() 





void SWITCH_X_init__(SWITCH_X *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN5,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN6,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->T_DEBOUNCE,__time_to_timespec(1, 50, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Q1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q5,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q6,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q31,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q41,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q51,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q61,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q32,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q42,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q52,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Q62,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  TOF_init__(&data__->T1,retain);
  TOF_init__(&data__->T2,retain);
  TOF_init__(&data__->T3,retain);
  TOF_init__(&data__->T4,retain);
  TOF_init__(&data__->T5,retain);
  TOF_init__(&data__->T6,retain);
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->X1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->X2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->E1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->E2,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void SWITCH_X_body__(SWITCH_X *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    if (LT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->T_DEBOUNCE,), __time_to_timespec(1, 50, 0, 0, 0, 0))) {
      __SET_VAR(data__->,TX,,__time_to_timespec(1, 50, 0, 0, 0, 0));
    } else {
      __SET_VAR(data__->,TX,,__GET_VAR(data__->T_DEBOUNCE,));
    };
    __SET_VAR(data__->T1.,PT,,__GET_VAR(data__->TX,));
    TOF_body__(&data__->T1);
    __SET_VAR(data__->T2.,PT,,__GET_VAR(data__->TX,));
    TOF_body__(&data__->T2);
    __SET_VAR(data__->T3.,PT,,__GET_VAR(data__->TX,));
    TOF_body__(&data__->T3);
    __SET_VAR(data__->T4.,PT,,__GET_VAR(data__->TX,));
    TOF_body__(&data__->T4);
    __SET_VAR(data__->T5.,PT,,__GET_VAR(data__->TX,));
    TOF_body__(&data__->T5);
    __SET_VAR(data__->T6.,PT,,__GET_VAR(data__->TX,));
    TOF_body__(&data__->T6);
  } else {
    __SET_VAR(data__->,Q1,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q2,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q3,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q4,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q5,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q6,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q31,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q41,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q51,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q61,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q32,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q42,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q52,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,Q62,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->T1.,IN,,__GET_VAR(data__->IN1,));
  TOF_body__(&data__->T1);
  __SET_VAR(data__->T2.,IN,,__GET_VAR(data__->IN2,));
  TOF_body__(&data__->T2);
  __SET_VAR(data__->T3.,IN,,__GET_VAR(data__->IN3,));
  TOF_body__(&data__->T3);
  __SET_VAR(data__->T4.,IN,,__GET_VAR(data__->IN4,));
  TOF_body__(&data__->T4);
  __SET_VAR(data__->T5.,IN,,__GET_VAR(data__->IN5,));
  TOF_body__(&data__->T5);
  __SET_VAR(data__->T6.,IN,,__GET_VAR(data__->IN6,));
  TOF_body__(&data__->T6);
  if ((__GET_VAR(data__->T1.Q,) && !(__GET_VAR(data__->E1,)))) {
    __SET_VAR(data__->,X1,,__BOOL_LITERAL(TRUE));
  };
  if ((__GET_VAR(data__->T2.Q,) && !(__GET_VAR(data__->E2,)))) {
    __SET_VAR(data__->,X2,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->T1.Q,)) {
    if (__GET_VAR(data__->T3.Q,)) {
      __SET_VAR(data__->,Q31,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,X1,,__BOOL_LITERAL(FALSE));
    } else if (__GET_VAR(data__->T4.Q,)) {
      __SET_VAR(data__->,Q41,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,X1,,__BOOL_LITERAL(FALSE));
    } else if (__GET_VAR(data__->T5.Q,)) {
      __SET_VAR(data__->,Q51,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,X1,,__BOOL_LITERAL(FALSE));
    } else if (__GET_VAR(data__->T6.Q,)) {
      __SET_VAR(data__->,Q61,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,X1,,__BOOL_LITERAL(FALSE));
    };
  } else if (__GET_VAR(data__->T2.Q,)) {
    if (__GET_VAR(data__->T3.Q,)) {
      __SET_VAR(data__->,Q32,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,X2,,__BOOL_LITERAL(FALSE));
    } else if (__GET_VAR(data__->T4.Q,)) {
      __SET_VAR(data__->,Q42,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,X2,,__BOOL_LITERAL(FALSE));
    } else if (__GET_VAR(data__->T5.Q,)) {
      __SET_VAR(data__->,Q52,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,X2,,__BOOL_LITERAL(FALSE));
    } else if (__GET_VAR(data__->T6.Q,)) {
      __SET_VAR(data__->,Q62,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,X2,,__BOOL_LITERAL(FALSE));
    };
  } else if (((!(__GET_VAR(data__->T1.Q,)) && __GET_VAR(data__->E1,)) && __GET_VAR(data__->X1,))) {
    __SET_VAR(data__->,Q1,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,X1,,__BOOL_LITERAL(FALSE));
  } else if (((!(__GET_VAR(data__->T2.Q,)) && __GET_VAR(data__->E2,)) && __GET_VAR(data__->X2,))) {
    __SET_VAR(data__->,Q2,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,X2,,__BOOL_LITERAL(FALSE));
  } else if (__GET_VAR(data__->T3.Q,)) {
    __SET_VAR(data__->,Q3,,__BOOL_LITERAL(TRUE));
  } else if (__GET_VAR(data__->T4.Q,)) {
    __SET_VAR(data__->,Q4,,__BOOL_LITERAL(TRUE));
  } else if (__GET_VAR(data__->T5.Q,)) {
    __SET_VAR(data__->,Q5,,__BOOL_LITERAL(TRUE));
  } else if (__GET_VAR(data__->T6.Q,)) {
    __SET_VAR(data__->,Q6,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,E1,,__GET_VAR(data__->T1.Q,));
  __SET_VAR(data__->,E2,,__GET_VAR(data__->T2.Q,));

  goto __end;

__end:
  return;
} // SWITCH_X_body__() 





void F_LAMP_init__(F_LAMP *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->SWITCH,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DIMM,255,retain)
  __INIT_VAR(data__->RST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->T_NO_DIMM,100,retain)
  __INIT_VAR(data__->T_MAINTENANCE,15000,retain)
  __INIT_VAR(data__->LAMP,0,retain)
  __INIT_VAR(data__->STATUS,0,retain)
  __INIT_VAR(data__->_ONTIME,0,retain)
  __INIT_VAR(data__->CYCLES,0,retain)
  ONTIME_init__(&data__->RUNTIME,retain);
}

// Code part
void F_LAMP_body__(F_LAMP *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->RUNTIME.,IN,,__GET_VAR(data__->SWITCH,));
  __SET_VAR(data__->RUNTIME.,SECONDS,,__GET_VAR(data__->_ONTIME,));
  __SET_VAR(data__->RUNTIME.,CYCLES,,__GET_VAR(data__->CYCLES,));
  ONTIME_body__(&data__->RUNTIME);
  __SET_VAR(data__->,_ONTIME,,__GET_VAR(data__->RUNTIME.SECONDS));
  __SET_VAR(data__->,CYCLES,,__GET_VAR(data__->RUNTIME.CYCLES));
  __SET_VAR(data__->,CYCLES,,__GET_VAR(data__->RUNTIME.CYCLES,));
  __SET_VAR(data__->,_ONTIME,,__GET_VAR(data__->RUNTIME.SECONDS,));
  if (__GET_VAR(data__->RST,)) {
    __SET_VAR(data__->,_ONTIME,,__UDINT_LITERAL(0));
    __SET_VAR(data__->,CYCLES,,__UDINT_LITERAL(0));
  };
  if (__GET_VAR(data__->SWITCH,)) {
    if ((__GET_VAR(data__->_ONTIME,) < (UINT_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UINT)__GET_VAR(data__->T_NO_DIMM,)) * __UDINT_LITERAL(3600)))) {
      __SET_VAR(data__->,LAMP,,__BYTE_LITERAL(255));
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(111));
    } else {
      __SET_VAR(data__->,LAMP,,__GET_VAR(data__->DIMM,));
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(112));
    };
  } else {
    __SET_VAR(data__->,LAMP,,__BYTE_LITERAL(0));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(110));
  };
  if (((__GET_VAR(data__->_ONTIME,) >= (UINT_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->T_MAINTENANCE,)) * __UDINT_LITERAL(3600))) && (__GET_VAR(data__->T_MAINTENANCE,) > __UINT_LITERAL(0)))) {
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(120));
  };

  goto __end;

__end:
  return;
} // F_LAMP_body__() 





// FUNCTION
REAL TANK_VOL2(
  BOOL EN, 
  BOOL *__ENO, 
  REAL TR, 
  REAL H)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL TANK_VOL2 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return TANK_VOL2;
  }
  TANK_VOL2 = (((3.14159265358979323846264338327950288 * H) * H) * (TR - (H / 3.0)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return TANK_VOL2;
}


// FUNCTION
REAL TANK_VOL1(
  BOOL EN, 
  BOOL *__ENO, 
  REAL TR, 
  REAL TL, 
  REAL H)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL TANK_VOL1 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return TANK_VOL1;
  }
  TANK_VOL1 = (CIRCLE_SEG(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)TR,
    (REAL)H) * TL);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return TANK_VOL1;
}


// FUNCTION
UDINT DT_TO_TOD_2(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  UDINT DT_TO_TOD_2 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DT_TO_TOD_2;
  }
  DT_TO_TOD_2 = (((__UDINT_LITERAL(86400) == 0)?0:(IN % __UDINT_LITERAL(86400))) * __UDINT_LITERAL(1000));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return DT_TO_TOD_2;
}


void ACTUATOR_UD_init__(ACTUATOR_UD *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->UD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_ON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MANUAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OFF,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->YUP_IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->YDN_IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT_RETURN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TON,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->_TOFF,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->YUP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->YDN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATUS,0,retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void ACTUATOR_UD_body__(ACTUATOR_UD *data__) {
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
  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
  } else if (__GET_VAR(data__->OFF,)) {
    __SET_VAR(data__->,YUP,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,YDN,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(101));
  } else if (((__GET_VAR(data__->YUP,) || __GET_VAR(data__->YDN,)) && LT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->_TON,)))) {
    goto __end;
  } else if (((!(__GET_VAR(data__->YUP,)) && !(__GET_VAR(data__->YDN,))) && LT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,)), __GET_VAR(data__->_TOFF,)))) {
    goto __end;
  } else if (__GET_VAR(data__->MANUAL,)) {
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(102));
    if (((__GET_VAR(data__->YUP,) && !(__GET_VAR(data__->UP,))) || (__GET_VAR(data__->YDN,) && !(__GET_VAR(data__->DN,))))) {
      __SET_VAR(data__->,YDN,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,YUP,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    } else if (((__GET_VAR(data__->UP,) && !(__GET_VAR(data__->DN,))) && !(__GET_VAR(data__->OFF,)))) {
      __SET_VAR(data__->,YDN,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,YUP,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(103));
    } else if (((__GET_VAR(data__->DN,) && !(__GET_VAR(data__->UP,))) && !(__GET_VAR(data__->OFF,)))) {
      __SET_VAR(data__->,YUP,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,YDN,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(104));
    } else {
      if ((__GET_VAR(data__->YUP,) || __GET_VAR(data__->YDN,))) {
        __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
      };
      __SET_VAR(data__->,YUP,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,YDN,,__BOOL_LITERAL(FALSE));
    };
  } else {
    if (((__GET_VAR(data__->YUP,) && !(__GET_VAR(data__->UD,))) || (__GET_VAR(data__->YDN,) && __GET_VAR(data__->UD,)))) {
      __SET_VAR(data__->,YUP,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,YDN,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
    } else if (((__GET_VAR(data__->UD,) && __GET_VAR(data__->_ON,)) && !(__GET_VAR(data__->OFF,)))) {
      __SET_VAR(data__->,YDN,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,YUP,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(111));
    } else if (((!(__GET_VAR(data__->UD,)) && __GET_VAR(data__->_ON,)) && !(__GET_VAR(data__->OFF,)))) {
      __SET_VAR(data__->,YUP,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,YDN,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(112));
    } else {
      if ((__GET_VAR(data__->YUP,) || __GET_VAR(data__->YDN,))) {
        __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
      };
      __SET_VAR(data__->,YUP,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,YDN,,__BOOL_LITERAL(FALSE));
      __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(110));
    };
  };
  if (((__GET_VAR(data__->YDN,) && __GET_VAR(data__->YUP_IN,)) && __GET_VAR(data__->OUT_RETURN,))) {
    __SET_VAR(data__->,YDN,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(1));
  };
  if (((__GET_VAR(data__->YUP,) && __GET_VAR(data__->YDN_IN,)) && __GET_VAR(data__->OUT_RETURN,))) {
    __SET_VAR(data__->,YUP,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(2));
  };

  goto __end;

__end:
  return;
} // ACTUATOR_UD_body__() 





void ACTUATOR_3P_init__(ACTUATOR_3P *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->TEST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ARE,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->END_POS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->T_RUN,__time_to_timespec(1, 0, 60, 0, 0, 0),retain)
  __INIT_VAR(data__->T_EXT,__time_to_timespec(1, 0, 10, 0, 0, 0),retain)
  __INIT_VAR(data__->T_CAL,__time_to_timespec(1, 0, 600, 0, 0, 0),retain)
  __INIT_VAR(data__->T_DIAG,__time_to_timespec(1, 0, 0, 0, 0, 10),retain)
  __INIT_VAR(data__->SWITCH_AVAIL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->POS,0,retain)
  __INIT_VAR(data__->ERROR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATUS,0,retain)
  __INIT_VAR(data__->ARX,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  _RMP_NEXT_init__(&data__->_RAMP,retain);
  __INIT_VAR(data__->NEXT_CAL,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->NEXT_DIAG,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->START,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
}

// Code part
void ACTUATOR_3P_body__(ACTUATOR_3P *data__) {
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
  if (__GET_VAR(data__->TEST,)) {
    __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(103));
    __SET_VAR(data__->,START,,__GET_VAR(data__->TX,));
    __SET_VAR(data__->,ARX,,__BOOL_LITERAL(TRUE));
  };
  {
    INT __case_expression = BYTE_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BYTE)__GET_VAR(data__->STATUS,));
    if ((__case_expression == 0)) {
      if ((__GET_VAR(data__->ARE,) && !(__GET_VAR(data__->ARX,)))) {
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(103));
        __SET_VAR(data__->,START,,__GET_VAR(data__->TX,));
        __SET_VAR(data__->,ARX,,__BOOL_LITERAL(TRUE));
      };
    }
    else if ((__case_expression == 100)) {
      if ((((GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->T_DIAG,), __time_to_timespec(1, 0, 0, 0, 0, 0)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TX,), __GET_VAR(data__->NEXT_DIAG,))) && __GET_VAR(data__->ARE,)) && !(__GET_VAR(data__->ARX,)))) {
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(103));
        __SET_VAR(data__->,START,,__GET_VAR(data__->TX,));
        __SET_VAR(data__->,ARX,,__BOOL_LITERAL(TRUE));
      } else if ((((GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->T_CAL,), __time_to_timespec(1, 0, 0, 0, 0, 0)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TX,), __GET_VAR(data__->NEXT_CAL,))) && __GET_VAR(data__->ARE,)) && !(__GET_VAR(data__->ARX,)))) {
        if ((__GET_VAR(data__->POS,) > __BYTE_LITERAL(127))) {
          __SET_VAR(data__->,OUT1,,__BOOL_LITERAL(TRUE));
          __SET_VAR(data__->,OUT2,,__BOOL_LITERAL(FALSE));
          __SET_VAR(data__->,_RAMP.IN,,__BYTE_LITERAL(255));
          __SET_VAR(data__->,ARX,,__BOOL_LITERAL(TRUE));
        } else {
          __SET_VAR(data__->,OUT1,,__BOOL_LITERAL(FALSE));
          __SET_VAR(data__->,OUT2,,__BOOL_LITERAL(TRUE));
          __SET_VAR(data__->,_RAMP.IN,,__BYTE_LITERAL(0));
          __SET_VAR(data__->,ARX,,__BOOL_LITERAL(TRUE));
        };
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(101));
        __SET_VAR(data__->,START,,__GET_VAR(data__->TX,));
      } else {
        if (!((__GET_VAR(data__->OUT1,) || __GET_VAR(data__->OUT2,)))) {
          __SET_VAR(data__->,NEXT_CAL,,__time_add(__GET_VAR(data__->NEXT_CAL,), __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST,))));
        };
        __SET_VAR(data__->,_RAMP.IN,,__GET_VAR(data__->IN,));
      };
    }
    else if ((__case_expression == 101)) {
      if (LT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->START,)), __GET_VAR(data__->T_EXT,))) {
        __SET_VAR(data__->,NEXT_CAL,,__time_add(__GET_VAR(data__->TX,), __GET_VAR(data__->T_CAL,)));
      } else if ((__GET_VAR(data__->SWITCH_AVAIL,) && __GET_VAR(data__->END_POS,))) {
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(100));
        __SET_VAR(data__->,ARX,,__BOOL_LITERAL(FALSE));
      } else if (GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->START,)), __time_add(__GET_VAR(data__->T_EXT,), __GET_VAR(data__->T_RUN,)))) {
        __SET_VAR(data__->,ERROR,,__GET_VAR(data__->SWITCH_AVAIL,));
        __SET_VAR(data__->,ARX,,__BOOL_LITERAL(FALSE));
      };
    }
    else if ((__case_expression == 103)) {
      if (LT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->START,)), __GET_VAR(data__->T_EXT,))) {
        __SET_VAR(data__->,ERROR,,__BOOL_LITERAL(FALSE));
        __SET_VAR(data__->,_RAMP.TR,,__GET_VAR(data__->T_RUN,));
        __SET_VAR(data__->,_RAMP.TF,,__GET_VAR(data__->T_RUN,));
        __SET_VAR(data__->,OUT1,,__BOOL_LITERAL(TRUE));
        __SET_VAR(data__->,OUT2,,__BOOL_LITERAL(FALSE));
        __SET_VAR(data__->,_RAMP.IN,,__BYTE_LITERAL(255));
      } else if ((__GET_VAR(data__->SWITCH_AVAIL,) && __GET_VAR(data__->END_POS,))) {
        __SET_VAR(data__->,_RAMP.TR,,__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->START,)));
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(104));
      } else if (GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->START,)), __time_add(__GET_VAR(data__->T_EXT,), __GET_VAR(data__->T_RUN,)))) {
        __SET_VAR(data__->,ERROR,,__GET_VAR(data__->SWITCH_AVAIL,));
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(104));
        __SET_VAR(data__->,START,,__GET_VAR(data__->TX,));
      };
    }
    else if ((__case_expression == 104)) {
      if (LT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->START,)), __GET_VAR(data__->T_EXT,))) {
        __SET_VAR(data__->,OUT1,,__BOOL_LITERAL(FALSE));
        __SET_VAR(data__->,OUT2,,__BOOL_LITERAL(TRUE));
        __SET_VAR(data__->,_RAMP.IN,,__BYTE_LITERAL(0));
        __SET_VAR(data__->,NEXT_DIAG,,__time_add(__GET_VAR(data__->TX,), __GET_VAR(data__->T_DIAG,)));
      } else if ((__GET_VAR(data__->SWITCH_AVAIL,) && __GET_VAR(data__->END_POS,))) {
        __SET_VAR(data__->,_RAMP.TR,,__time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->START,)));
        if (GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, DINT_TO_TIME(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (DINT)(ABS__DINT__DINT(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (DINT)(TIME_TO_DINT(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (TIME)__GET_VAR(data__->_RAMP.TR,)) - TIME_TO_DINT(
              (BOOL)__BOOL_LITERAL(TRUE),
              NULL,
              (TIME)__GET_VAR(data__->_RAMP.TF,)))) * __DINT_LITERAL(10))), __GET_VAR(data__->T_RUN,))) {
          __SET_VAR(data__->,ERROR,,__BOOL_LITERAL(TRUE));
        };
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(100));
        __SET_VAR(data__->,ARX,,__BOOL_LITERAL(FALSE));
        __SET_VAR(data__->,NEXT_CAL,,__time_add(__GET_VAR(data__->TX,), __GET_VAR(data__->T_CAL,)));
      } else if (GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->START,)), __time_add(__GET_VAR(data__->T_EXT,), __GET_VAR(data__->T_RUN,)))) {
        if (__GET_VAR(data__->SWITCH_AVAIL,)) {
          __SET_VAR(data__->,ERROR,,__BOOL_LITERAL(TRUE));
        };
        __SET_VAR(data__->,STATUS,,__BYTE_LITERAL(100));
        __SET_VAR(data__->,ARX,,__BOOL_LITERAL(FALSE));
        __SET_VAR(data__->,NEXT_CAL,,__time_add(__GET_VAR(data__->TX,), __GET_VAR(data__->T_CAL,)));
      };
    }
  };
  __SET_VAR(data__->_RAMP.,OUT,,__GET_VAR(data__->POS,));
  _RMP_NEXT_body__(&data__->_RAMP);
  __SET_VAR(data__->,POS,,__GET_VAR(data__->_RAMP.OUT));
  __SET_VAR(data__->,POS,,__GET_VAR(data__->_RAMP.OUT,));
  if ((__GET_VAR(data__->STATUS,) == __BYTE_LITERAL(100))) {
    __SET_VAR(data__->,OUT1,,__GET_VAR(data__->_RAMP.UP,));
    __SET_VAR(data__->,OUT2,,__GET_VAR(data__->_RAMP.DN,));
  };
  if ((__GET_VAR(data__->SWITCH_AVAIL,) && __GET_VAR(data__->END_POS,))) {
    __SET_VAR(data__->,POS,,SEL__BYTE__BOOL__BYTE__BYTE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)(__GET_VAR(data__->POS,) > __BYTE_LITERAL(127)),
      (BYTE)__BYTE_LITERAL(0),
      (BYTE)__BYTE_LITERAL(255)));
    __SET_VAR(data__->,NEXT_CAL,,__time_add(__GET_VAR(data__->TX,), __GET_VAR(data__->T_CAL,)));
  };
  __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));

  goto __end;

__end:
  return;
} // ACTUATOR_3P_body__() 





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





void FILTER_I_init__(FILTER_I *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->X,0,retain)
  __INIT_VAR(data__->_T,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Y,0,retain)
  __INIT_VAR(data__->YI,0,retain)
  __INIT_VAR(data__->LAST,0,retain)
  __INIT_VAR(data__->TX,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void FILTER_I_body__(FILTER_I *data__) {
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
  if ((!(__GET_VAR(data__->INIT,)) || EQ_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->_T,), __time_to_timespec(1, 0, 0, 0, 0, 0)))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,YI,,(INT_TO_DINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)__GET_VAR(data__->X,)) * __DINT_LITERAL(1000)));
  } else {
    __SET_VAR(data__->,YI,,(__GET_VAR(data__->YI,) + (((INT_TO_DINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)(__GET_VAR(data__->X,) - __GET_VAR(data__->Y,))) * UDINT_TO_DINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)(__GET_VAR(data__->TX,) - __GET_VAR(data__->LAST,)))) * __DINT_LITERAL(1000)) / TIME_TO_DINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)__GET_VAR(data__->_T,)))));
  };
  __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));
  __SET_VAR(data__->,Y,,DINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DINT)(__GET_VAR(data__->YI,) / __DINT_LITERAL(1000))));

  goto __end;

__end:
  return;
} // FILTER_I_body__() 





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
REAL WCT(
  BOOL EN, 
  BOOL *__ENO, 
  REAL _T, 
  REAL V)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL WCT = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return WCT;
  }
  if (((V < 5.0) || (_T > 10.0))) {
    WCT = _T;
  } else {
    WCT = ((13.12 + (0.6215 * _T)) + (((0.3965 * _T) - 11.37) * EXP__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(LN__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)V) * 0.16))));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return WCT;
}


void HEAT_TEMP_init__(HEAT_TEMP *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->T_EXT,0,retain)
  __INIT_VAR(data__->T_INT,0,retain)
  __INIT_VAR(data__->OFFSET,0,retain)
  __INIT_VAR(data__->T_REQ,0,retain)
  __INIT_VAR(data__->TY_MAX,70.0,retain)
  __INIT_VAR(data__->TY_MIN,25.0,retain)
  __INIT_VAR(data__->TY_CONFIG,70.0,retain)
  __INIT_VAR(data__->T_INT_CONFIG,20.0,retain)
  __INIT_VAR(data__->T_EXT_CONFIG,-15.0,retain)
  __INIT_VAR(data__->T_DIFF,10.0,retain)
  __INIT_VAR(data__->C,1.33,retain)
  __INIT_VAR(data__->H,3.0,retain)
  __INIT_VAR(data__->TY,0,retain)
  __INIT_VAR(data__->HEAT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TR,0,retain)
  __INIT_VAR(data__->TX,0,retain)
}

// Code part
void HEAT_TEMP_body__(HEAT_TEMP *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,TR,,(__GET_VAR(data__->T_INT,) + __GET_VAR(data__->OFFSET,)));
  __SET_VAR(data__->,TX,,((__GET_VAR(data__->TR,) - __GET_VAR(data__->T_EXT,)) / (__GET_VAR(data__->T_INT_CONFIG,) - __GET_VAR(data__->T_EXT_CONFIG,))));
  if (((__GET_VAR(data__->T_EXT,) + __GET_VAR(data__->H,)) > __GET_VAR(data__->TR,))) {
    __SET_VAR(data__->,TY,,0.0);
  } else {
    __SET_VAR(data__->,TY,,LIMIT__REAL__REAL__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)__GET_VAR(data__->TY_MIN,),
      (REAL)((__GET_VAR(data__->TR,) + ((__GET_VAR(data__->T_DIFF,) * 0.5) * __GET_VAR(data__->TX,))) + (((__GET_VAR(data__->TY_CONFIG,) - (__GET_VAR(data__->T_DIFF,) * 0.5)) - __GET_VAR(data__->TR,)) * EXPT__REAL__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)__GET_VAR(data__->TX,),
        (REAL)(1.0 / __GET_VAR(data__->C,))))),
      (REAL)__GET_VAR(data__->TY_MAX,)));
  };
  __SET_VAR(data__->,TY,,MAX__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->TY,),
    (REAL)__GET_VAR(data__->T_REQ,)));
  __SET_VAR(data__->,HEAT,,(__GET_VAR(data__->TY,) > 0.0));

  goto __end;

__end:
  return;
} // HEAT_TEMP_body__() 





void GEN_PULSE_init__(GEN_PULSE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENQ,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->PTH,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->PTL,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->Q,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TN,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void GEN_PULSE_body__(GEN_PULSE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (__GET_VAR(data__->ENQ,)) {
    __SET_VAR(data__->,TX,,UDINT_TO_TIME(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)T_PLC_MS(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BOOL)__BOOL_LITERAL(FALSE))));
    if (!(__GET_VAR(data__->INIT,))) {
      __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,TN,,__GET_VAR(data__->TX,));
    };
    if (GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->TN,)), SEL__TIME__BOOL__TIME__TIME(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__GET_VAR(data__->Q,),
      (TIME)__GET_VAR(data__->PTL,),
      (TIME)__GET_VAR(data__->PTH,)))) {
      __SET_VAR(data__->,TN,,__time_add(__GET_VAR(data__->TN,), SEL__TIME__BOOL__TIME__TIME(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BOOL)__GET_VAR(data__->Q,),
        (TIME)__GET_VAR(data__->PTL,),
        (TIME)__GET_VAR(data__->PTH,))));
      __SET_VAR(data__->,Q,,!(__GET_VAR(data__->Q,)));
    };
  } else {
    __SET_VAR(data__->,Q,,__BOOL_LITERAL(FALSE));
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // GEN_PULSE_body__() 





void ACTUATOR_2P_init__(ACTUATOR_2P *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,0,retain)
  __INIT_VAR(data__->TEST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ARE,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->CYCLE_TIME,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->SENS,0,retain)
  __INIT_VAR(data__->SELF_ACT_TIME,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->SELF_ACT_PULSE,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->SELF_ACT_CYCLES,1,retain)
  __INIT_VAR(data__->OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ARO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ARX,__BOOL_LITERAL(FALSE),retain)
  AUTORUN_init__(&data__->TIMER,retain);
  GEN_PULSE_init__(&data__->PWGEN,retain);
}

// Code part
void ACTUATOR_2P_body__(ACTUATOR_2P *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->TIMER.,TEST,,__GET_VAR(data__->TEST,));
  __SET_VAR(data__->TIMER.,ARE,,__GET_VAR(data__->ARE,));
  __SET_VAR(data__->TIMER.,TRUN,,__time_mul(__GET_VAR(data__->SELF_ACT_PULSE,), (2 * __GET_VAR(data__->SELF_ACT_CYCLES,))));
  __SET_VAR(data__->TIMER.,TOFF,,__GET_VAR(data__->SELF_ACT_TIME,));
  __SET_VAR(data__->TIMER.,ARX,,__GET_VAR(data__->ARX,));
  AUTORUN_body__(&data__->TIMER);
  __SET_VAR(data__->,ARX,,__GET_VAR(data__->TIMER.ARX));
  __SET_VAR(data__->,ARO,,__GET_VAR(data__->TIMER.ARO,));
  if (__GET_VAR(data__->ARO,)) {
    __SET_VAR(data__->PWGEN.,PTH,,__GET_VAR(data__->SELF_ACT_PULSE,));
    __SET_VAR(data__->PWGEN.,PTL,,__GET_VAR(data__->SELF_ACT_PULSE,));
    GEN_PULSE_body__(&data__->PWGEN);
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->PWGEN.Q,));
  } else if ((__GET_VAR(data__->IN,) < __GET_VAR(data__->SENS,))) {
    __SET_VAR(data__->,OUT,,__BOOL_LITERAL(FALSE));
  } else if ((BYTE_TO_USINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)__GET_VAR(data__->IN,)) > (__USINT_LITERAL(255) - BYTE_TO_USINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)__GET_VAR(data__->SENS,))))) {
    __SET_VAR(data__->,OUT,,__BOOL_LITERAL(TRUE));
  } else {
    __SET_VAR(data__->,PWGEN.PTH,,UDINT_TO_TIME(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)((TIME_TO_UDINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (TIME)__GET_VAR(data__->CYCLE_TIME,)) * BYTE_TO_UDINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)BAND_B(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (BYTE)__GET_VAR(data__->IN,),
          (BYTE)__GET_VAR(data__->SENS,)))) / BYTE_TO_UDINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (BYTE)__BYTE_LITERAL(255)))));
    __SET_VAR(data__->,PWGEN.PTL,,__time_sub(__GET_VAR(data__->CYCLE_TIME,), __GET_VAR(data__->PWGEN.PTH,)));
    GEN_PULSE_body__(&data__->PWGEN);
    __SET_VAR(data__->,OUT,,__GET_VAR(data__->PWGEN.Q,));
  };

  goto __end;

__end:
  return;
} // ACTUATOR_2P_body__() 





// FUNCTION
REAL SDD_NH3(
  BOOL EN, 
  BOOL *__ENO, 
  REAL _T)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL SDD_NH3 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SDD_NH3;
  }
  if ((_T < -33.65)) {
    SDD_NH3 = EXP__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(7.3396511649 - (1166.7498002 / (_T + 192.37))));
  } else {
    SDD_NH3 = EXP__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(11.210964456 - (2564.9140075 / (_T + 262.741))));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SDD_NH3;
}


void TEMP_EXT_init__(TEMP_EXT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->T_EXT1,0,retain)
  __INIT_VAR(data__->T_EXT2,0,retain)
  __INIT_VAR(data__->T_EXT3,0,retain)
  __INIT_VAR(data__->T_EXT_CONFIG,0,retain)
  __INIT_VAR(data__->DT_IN,0,retain)
  __INIT_VAR(data__->T_EXT_MIN,-40.0,retain)
  __INIT_VAR(data__->T_EXT_MAX,60.0,retain)
  __INIT_VAR(data__->T_EXT_DEFAULT,-10.0,retain)
  __INIT_VAR(data__->HEAT_PERIOD_START,20995200,retain)
  __INIT_VAR(data__->HEAT_PERIOD_STOP,10281600,retain)
  __INIT_VAR(data__->COOL_PERIOD_START,7776000,retain)
  __INIT_VAR(data__->COOL_PERIOD_STOP,23500800,retain)
  __INIT_VAR(data__->HEAT_START_TEMP_DAY,15.0,retain)
  __INIT_VAR(data__->HEAT_START_TEMP_NIGHT,10.0,retain)
  __INIT_VAR(data__->HEAT_STOP_TEMP,18.0,retain)
  __INIT_VAR(data__->COOL_START_TEMP_DAY,26.0,retain)
  __INIT_VAR(data__->COOL_START_TEMP_NIGHT,26.0,retain)
  __INIT_VAR(data__->COOL_STOP_TEMP,24.0,retain)
  __INIT_VAR(data__->START_DAY,32400000,retain)
  __INIT_VAR(data__->START_NIGHT,75600000,retain)
  __INIT_VAR(data__->CYCLE_TIME,__time_to_timespec(1, 0, 0, 10, 0, 0),retain)
  __INIT_VAR(data__->T_EXT,0,retain)
  __INIT_VAR(data__->HEAT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->COOL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->LAST_RUN,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->COOL_START,0,retain)
  __INIT_VAR(data__->COOL_STOP,0,retain)
  __INIT_VAR(data__->HEAT_START,0,retain)
  __INIT_VAR(data__->HEAT_STOP,0,retain)
  __INIT_VAR(data__->XDATE,0,retain)
  __INIT_VAR(data__->DAY,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void TEMP_EXT_body__(TEMP_EXT *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if (!(__GET_VAR(data__->INIT,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,HEAT_START,,SET_DATE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)1972,
      (INT)MONTH_OF_DATE(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)__GET_VAR(data__->HEAT_PERIOD_START,)),
      (INT)DAY_OF_MONTH(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)__GET_VAR(data__->HEAT_PERIOD_START,))));
    __SET_VAR(data__->,HEAT_STOP,,SET_DATE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)1972,
      (INT)MONTH_OF_DATE(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)__GET_VAR(data__->HEAT_PERIOD_STOP,)),
      (INT)DAY_OF_MONTH(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)__GET_VAR(data__->HEAT_PERIOD_STOP,))));
    __SET_VAR(data__->,COOL_START,,SET_DATE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)1972,
      (INT)MONTH_OF_DATE(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)__GET_VAR(data__->COOL_PERIOD_START,)),
      (INT)DAY_OF_MONTH(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)__GET_VAR(data__->COOL_PERIOD_START,))));
    __SET_VAR(data__->,COOL_STOP,,SET_DATE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)1972,
      (INT)MONTH_OF_DATE(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)__GET_VAR(data__->COOL_PERIOD_STOP,)),
      (INT)DAY_OF_MONTH(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)__GET_VAR(data__->COOL_PERIOD_STOP,))));
  };
  __SET_VAR(data__->,TX,,UDINT_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)T_PLC_MS(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__BOOL_LITERAL(FALSE))));
  if (LT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TX,), __GET_VAR(data__->LAST_RUN,)), __GET_VAR(data__->CYCLE_TIME,))) {
    goto __end;
  };
  __SET_VAR(data__->,XDATE,,SET_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)1972,
    (INT)MONTH_OF_DATE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)DT_TO_DATE_2(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)__GET_VAR(data__->DT_IN,))),
    (INT)DAY_OF_MONTH(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)DT_TO_DATE_2(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)__GET_VAR(data__->DT_IN,)))));
  __SET_VAR(data__->,DAY,,((DT_TO_TOD_2(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->DT_IN,)) >= __GET_VAR(data__->START_DAY,)) && (DT_TO_TOD_2(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->DT_IN,)) < __GET_VAR(data__->START_NIGHT,))));
  __SET_VAR(data__->,T_EXT,,MULTI_IN(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->T_EXT1,),
    (REAL)__GET_VAR(data__->T_EXT2,),
    (REAL)__GET_VAR(data__->T_EXT3,),
    (REAL)__GET_VAR(data__->T_EXT_DEFAULT,),
    (REAL)__GET_VAR(data__->T_EXT_MIN,),
    (REAL)__GET_VAR(data__->T_EXT_MAX,),
    (BYTE)__GET_VAR(data__->T_EXT_CONFIG,)));
  if (((((__GET_VAR(data__->HEAT_START,) <= __GET_VAR(data__->HEAT_STOP,)) && (__GET_VAR(data__->XDATE,) >= __GET_VAR(data__->HEAT_START,))) && (__GET_VAR(data__->XDATE,) <= __GET_VAR(data__->HEAT_STOP,))) || ((__GET_VAR(data__->HEAT_START,) > __GET_VAR(data__->HEAT_STOP,)) && ((__GET_VAR(data__->XDATE,) >= __GET_VAR(data__->HEAT_START,)) || (__GET_VAR(data__->XDATE,) <= __GET_VAR(data__->HEAT_STOP,)))))) {
    if ((__GET_VAR(data__->DAY,) && (__GET_VAR(data__->T_EXT,) <= __GET_VAR(data__->HEAT_START_TEMP_DAY,)))) {
      __SET_VAR(data__->,HEAT,,__BOOL_LITERAL(TRUE));
    } else if ((!(__GET_VAR(data__->DAY,)) && (__GET_VAR(data__->T_EXT,) <= __GET_VAR(data__->HEAT_START_TEMP_NIGHT,)))) {
      __SET_VAR(data__->,HEAT,,__BOOL_LITERAL(TRUE));
    } else if ((__GET_VAR(data__->T_EXT,) >= __GET_VAR(data__->HEAT_STOP_TEMP,))) {
      __SET_VAR(data__->,HEAT,,__BOOL_LITERAL(FALSE));
    };
  } else {
    __SET_VAR(data__->,HEAT,,__BOOL_LITERAL(FALSE));
  };
  if (((((__GET_VAR(data__->COOL_START,) <= __GET_VAR(data__->COOL_STOP,)) && (__GET_VAR(data__->XDATE,) >= __GET_VAR(data__->COOL_START,))) && (__GET_VAR(data__->XDATE,) <= __GET_VAR(data__->COOL_STOP,))) || ((__GET_VAR(data__->COOL_START,) > __GET_VAR(data__->COOL_STOP,)) && ((__GET_VAR(data__->XDATE,) >= __GET_VAR(data__->COOL_START,)) || (__GET_VAR(data__->XDATE,) <= __GET_VAR(data__->COOL_STOP,)))))) {
    if ((__GET_VAR(data__->DAY,) && (__GET_VAR(data__->T_EXT,) >= __GET_VAR(data__->COOL_START_TEMP_DAY,)))) {
      __SET_VAR(data__->,COOL,,__BOOL_LITERAL(TRUE));
    } else if ((!(__GET_VAR(data__->DAY,)) && (__GET_VAR(data__->T_EXT,) >= __GET_VAR(data__->COOL_START_TEMP_NIGHT,)))) {
      __SET_VAR(data__->,COOL,,__BOOL_LITERAL(TRUE));
    } else if ((__GET_VAR(data__->T_EXT,) <= __GET_VAR(data__->COOL_STOP_TEMP,))) {
      __SET_VAR(data__->,COOL,,__BOOL_LITERAL(FALSE));
    };
  } else {
    __SET_VAR(data__->,COOL,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,LAST_RUN,,__GET_VAR(data__->TX,));

  goto __end;

__end:
  return;
} // TEMP_EXT_body__() 





