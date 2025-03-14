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
INT HOUR(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT ITOD)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT HOUR = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return HOUR;
  }
  HOUR = UDINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)(ITOD / __UDINT_LITERAL(3600000)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return HOUR;
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
UDINT SET_DT(
  BOOL EN, 
  BOOL *__ENO, 
  INT YEAR, 
  INT MONTH, 
  INT DAY, 
  INT _HOUR, 
  INT MINUTE, 
  INT SECOND)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  UDINT SET_DT = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SET_DT;
  }
  SET_DT = (((SET_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)YEAR,
    (INT)MONTH,
    (INT)DAY) + INT_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)SECOND)) + (INT_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)MINUTE) * __UDINT_LITERAL(60))) + (INT_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)_HOUR) * __UDINT_LITERAL(3600)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SET_DT;
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
BOOL DST(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT UTC)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT YR = 0;
  UDINT YR4 = 0;
  UDINT LTC = 0;
  UDINT IDATE = 0;
  BOOL DST = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DST;
  }
  YR = YEAR_OF_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)_DT_TO_DATE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)UTC));
  LTC = UTC;
  IDATE = SET_DT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)YR,
    (INT)3,
    (INT)31,
    (INT)1,
    (INT)0,
    (INT)0);
  YR4 = (DWORD_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)SHR__DWORD__DWORD__SINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (DWORD)INT_TO_DWORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)(5 * YR)),
      (SINT)2)) + __UDINT_LITERAL(1));
  DST = (((IDATE - (((__UDINT_LITERAL(7) == 0)?0:((YR4 + __UDINT_LITERAL(3)) % __UDINT_LITERAL(7))) * __UDINT_LITERAL(86400))) <= LTC) && ((IDATE + ((__UDINT_LITERAL(214) - ((__UDINT_LITERAL(7) == 0)?0:(YR4 % __UDINT_LITERAL(7)))) * __UDINT_LITERAL(86400))) > LTC));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return DST;
}


// FUNCTION
UDINT UTC_TO_LTIME(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT UTC, 
  BOOL DST_ENABLE, 
  INT TIME_ZONE_OFFSET)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT TMP = 0;
  UDINT UTC_TO_LTIME = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return UTC_TO_LTIME;
  }
  UTC_TO_LTIME = ((UTC + (INT_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)TIME_ZONE_OFFSET) * __UDINT_LITERAL(60))) + (BOOL_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)(DST_ENABLE && DST(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)UTC))) * __UDINT_LITERAL(3600)));
  TMP = ((TIME_ZONE_OFFSET * 60) + (BOOL_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)(DST_ENABLE && DST(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)UTC))) * 3600));
  if ((TMP < 0)) {
    UTC_TO_LTIME = (UTC - INT_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)ABS__INT__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)TMP)));
  } else {
    UTC_TO_LTIME = (UTC + INT_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)TMP));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return UTC_TO_LTIME;
}


// FUNCTION
TIME SECOND_TO_TIME(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  TIME SECOND_TO_TIME = __time_to_timespec(1, 0, 0, 0, 0, 0);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SECOND_TO_TIME;
  }
  SECOND_TO_TIME = UDINT_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)REAL_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(IN * 1000.0)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SECOND_TO_TIME;
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
TIME MINUTE_TO_TIME(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  TIME MINUTE_TO_TIME = __time_to_timespec(1, 0, 0, 0, 0, 0);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return MINUTE_TO_TIME;
  }
  MINUTE_TO_TIME = UDINT_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)REAL_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(IN * 60000.0)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return MINUTE_TO_TIME;
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
UDINT HOUR_TO_TOD(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  UDINT HOUR_TO_TOD = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return HOUR_TO_TOD;
  }
  HOUR_TO_TOD = REAL_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(IN * 3600000.00));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return HOUR_TO_TOD;
}


// FUNCTION
UDINT SUN_MIDDAY(
  BOOL EN, 
  BOOL *__ENO, 
  REAL LON, 
  UDINT UTC)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL _T = 0;
  REAL OFFSET = 0;
  UDINT SUN_MIDDAY = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SUN_MIDDAY;
  }
  _T = INT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)DAY_OF_YEAR(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)UTC));
  OFFSET = ((-0.1752 * SIN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)((0.033430 * _T) + 0.5474))) - (0.1340 * SIN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)((0.018234 * _T) - 0.1939))));
  SUN_MIDDAY = HOUR_TO_TOD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)((12.0 - OFFSET) - (LON * 0.0666666666666)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SUN_MIDDAY;
}


// FUNCTION
UDINT SET_TOD(
  BOOL EN, 
  BOOL *__ENO, 
  INT _HOUR, 
  INT MINUTE, 
  REAL SECOND)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  UDINT SET_TOD = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SET_TOD;
  }
  SET_TOD = ((REAL_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(SECOND * 1000.0)) + (INT_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)MINUTE) * __UDINT_LITERAL(60000))) + (INT_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)_HOUR) * __UDINT_LITERAL(3600000)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SET_TOD;
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


void RTC_MS_init__(RTC_MS *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->SET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SDT,0,retain)
  __INIT_VAR(data__->SMS,0,retain)
  __INIT_VAR(data__->XDT,0,retain)
  __INIT_VAR(data__->XMS,0,retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LAST,0,retain)
  __INIT_VAR(data__->TX,0,retain)
}

// Code part
void RTC_MS_body__(RTC_MS *data__) {
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
  if ((__GET_VAR(data__->SET,) || !(__GET_VAR(data__->INIT,)))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,XDT,,__GET_VAR(data__->SDT,));
    __SET_VAR(data__->,XMS,,__GET_VAR(data__->SMS,));
  } else {
    __SET_VAR(data__->,XMS,,(__GET_VAR(data__->XMS,) + UDINT_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)(__GET_VAR(data__->TX,) - __GET_VAR(data__->LAST,)))));
    if ((__GET_VAR(data__->XMS,) > 999)) {
      __SET_VAR(data__->,XDT,,(__GET_VAR(data__->XDT,) + __UDINT_LITERAL(1)));
      __SET_VAR(data__->,XMS,,(__GET_VAR(data__->XMS,) - 1000));
    };
  };
  __SET_VAR(data__->,LAST,,__GET_VAR(data__->TX,));

  goto __end;

__end:
  return;
} // RTC_MS_body__() 





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


// FUNCTION
INT DAYS_IN_MONTH(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT DAYS_IN_MONTH = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DAYS_IN_MONTH;
  }
  DAYS_IN_MONTH = DAY_OF_YEAR(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)IDATE);
  if (LEAP_OF_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)IDATE)) {
    {
      INT __case_expression = DAYS_IN_MONTH;
      if ((__case_expression >= 32 && __case_expression <= 60)) {
        DAYS_IN_MONTH = 29;
      }
      else if ((__case_expression >= 92 && __case_expression <= 121)) {
        DAYS_IN_MONTH = 30;
      }
      else if ((__case_expression >= 153 && __case_expression <= 182)) {
        DAYS_IN_MONTH = 30;
      }
      else if ((__case_expression >= 245 && __case_expression <= 274)) {
        DAYS_IN_MONTH = 30;
      }
      else if ((__case_expression >= 306 && __case_expression <= 335)) {
        DAYS_IN_MONTH = 30;
      }
      else {
        DAYS_IN_MONTH = 31;
      }
    };
  } else {
    {
      INT __case_expression = DAYS_IN_MONTH;
      if ((__case_expression >= 32 && __case_expression <= 59)) {
        DAYS_IN_MONTH = 28;
      }
      else if ((__case_expression >= 91 && __case_expression <= 120)) {
        DAYS_IN_MONTH = 30;
      }
      else if ((__case_expression >= 152 && __case_expression <= 181)) {
        DAYS_IN_MONTH = 30;
      }
      else if ((__case_expression >= 244 && __case_expression <= 273)) {
        DAYS_IN_MONTH = 30;
      }
      else if ((__case_expression >= 305 && __case_expression <= 334)) {
        DAYS_IN_MONTH = 30;
      }
      else {
        DAYS_IN_MONTH = 31;
      }
    };
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return DAYS_IN_MONTH;
}


// FUNCTION
BOOL PERIOD(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT D1, 
  UDINT D2, 
  UDINT DX)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT DAY1 = 0;
  INT DAY2 = 0;
  INT DAYX = 0;
  BOOL PERIOD = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return PERIOD;
  }
  DAY1 = DAY_OF_YEAR(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)D1);
  DAY2 = DAY_OF_YEAR(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)D2);
  DAYX = DAY_OF_YEAR(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)DX);
  if ((!(LEAP_OF_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)DX)) && (DAYX > 58))) {
    DAYX = (DAYX + 1);
  };
  if ((!(LEAP_OF_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)D1)) && (DAY1 > 58))) {
    DAY1 = (DAY1 + 1);
  };
  if ((!(LEAP_OF_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)D2)) && (DAY2 > 58))) {
    DAY2 = (DAY2 + 1);
  };
  if ((DAY2 < DAY1)) {
    PERIOD = ((DAYX <= DAY2) || (DAYX >= DAY1));
  } else {
    PERIOD = ((DAYX >= DAY1) && (DAYX <= DAY2));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return PERIOD;
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
INT MINUTE_OF_DT(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT *__XDT)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  UDINT XDT = 0;
  INT MINUTE_OF_DT = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return MINUTE_OF_DT;
  }
  MINUTE_OF_DT = UDINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)(((__UDINT_LITERAL(3600) == 0)?0:(XDT % __UDINT_LITERAL(3600))) / __UDINT_LITERAL(60)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  if (__XDT != NULL) {
    *__XDT = XDT;
  }
  return MINUTE_OF_DT;
}


// FUNCTION
BOOL LEAP_YEAR(
  BOOL EN, 
  BOOL *__ENO, 
  INT YEAR)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BOOL LEAP_YEAR = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return LEAP_YEAR;
  }
  if ((((__INT_LITERAL(400) == 0)?0:(YEAR % __INT_LITERAL(400))) == __INT_LITERAL(0))) {
    LEAP_YEAR = __BOOL_LITERAL(TRUE);
  } else if ((((__INT_LITERAL(100) == 0)?0:(YEAR % __INT_LITERAL(100))) == __INT_LITERAL(0))) {
    LEAP_YEAR = __BOOL_LITERAL(FALSE);
  } else if ((((__INT_LITERAL(4) == 0)?0:(YEAR % __INT_LITERAL(4))) == __INT_LITERAL(0))) {
    LEAP_YEAR = __BOOL_LITERAL(TRUE);
  } else {
    LEAP_YEAR = __BOOL_LITERAL(FALSE);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return LEAP_YEAR;
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
UDINT DATE_ADD(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE, 
  INT _D, 
  INT W, 
  INT M, 
  INT Y)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT MO = 0;
  INT YR = 0;
  INT DM = 0;
  UDINT DATE_ADD = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DATE_ADD;
  }
  DATE_ADD = (IDATE + (INT_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)(_D + (W * 7))) * __UDINT_LITERAL(86400)));
  YR = (Y + YEAR_OF_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)DATE_ADD));
  MO = (M + MONTH_OF_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)DATE_ADD));
  DM = DAY_OF_MONTH(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)DATE_ADD);
  while ((MO > 12)) {
    MO = (MO - 12);
    YR = (YR + 1);
  };
  while ((MO < 1)) {
    MO = (MO + 12);
    YR = (YR - 1);
  };
  DATE_ADD = SET_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)YR,
    (INT)MO,
    (INT)DM);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return DATE_ADD;
}


// FUNCTION
TIME DAY_TO_TIME(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  TIME DAY_TO_TIME = __time_to_timespec(1, 0, 0, 0, 0, 0);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DAY_TO_TIME;
  }
  DAY_TO_TIME = DINT_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DINT)UDINT_TO_DINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)REAL_TO_UDINT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)(IN * __REAL_LITERAL(86400000.00)))));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return DAY_TO_TIME;
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

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





// FUNCTION
UDINT YEAR_BEGIN(
  BOOL EN, 
  BOOL *__ENO, 
  INT Y)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  UDINT YEAR_BEGIN = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return YEAR_BEGIN;
  }
  YEAR_BEGIN = (DWORD_TO_UDINT(
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
          (INT)Y) * __UDINT_LITERAL(1461)) - __UDINT_LITERAL(2878169))),
      (SINT)2)) * __UDINT_LITERAL(86400));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return YEAR_BEGIN;
}


// FUNCTION
TIME _MULTIME(
  BOOL EN, 
  BOOL *__ENO, 
  TIME _T, 
  REAL M)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  TIME _MULTIME = __time_to_timespec(1, 0, 0, 0, 0, 0);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return _MULTIME;
  }
  _MULTIME = DWORD_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (DWORD)REAL_TO_DWORD(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(DWORD_TO_REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DWORD)TIME_TO_DWORD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (TIME)_T)) * M)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return _MULTIME;
}


// FUNCTION
TIME HOUR_TO_TIME(
  BOOL EN, 
  BOOL *__ENO, 
  REAL IN)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  TIME HOUR_TO_TIME = __time_to_timespec(1, 0, 0, 0, 0, 0);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return HOUR_TO_TIME;
  }
  HOUR_TO_TIME = UDINT_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)REAL_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(IN * 3600000.0)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return HOUR_TO_TIME;
}


// FUNCTION
INT HOUR_OF_DT(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT XDT)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT HOUR_OF_DT = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return HOUR_OF_DT;
  }
  HOUR_OF_DT = UDINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)(((__UDINT_LITERAL(86400) == 0)?0:(XDT % __UDINT_LITERAL(86400))) / __UDINT_LITERAL(3600)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return HOUR_OF_DT;
}


// FUNCTION
INT _MINUTE(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT ITOD)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT _MINUTE = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return _MINUTE;
  }
  _MINUTE = UDINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)((ITOD / __UDINT_LITERAL(60000)) - ((ITOD / __UDINT_LITERAL(3600000)) * __UDINT_LITERAL(60))));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return _MINUTE;
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


void DT2_TO_SDT_init__(DT2_TO_SDT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->DI,0,retain)
  __INIT_VAR(data__->TI,0,retain)
  {
    static const OSCAT_SDT temp = {0,0,0,0,0,0,0,0};
    __SET_VAR(data__->,SDT,,temp);
  }
}

// Code part
void DT2_TO_SDT_body__(DT2_TO_SDT *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,SDT,.YEAR,YEAR_OF_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->DI,)));
  __SET_VAR(data__->,SDT,.MONTH,MONTH_OF_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->DI,)));
  __SET_VAR(data__->,SDT,.DAY,DAY_OF_MONTH(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->DI,)));
  __SET_VAR(data__->,SDT,.WEEKDAY,DAY_OF_WEEK(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->DI,)));
  __SET_VAR(data__->,SDT,.MS,UDINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)((__UDINT_LITERAL(1000) == 0)?0:(__GET_VAR(data__->TI,) % __UDINT_LITERAL(1000)))));
  __SET_VAR(data__->,SDT,.SECOND,UDINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)((__UDINT_LITERAL(60) == 0)?0:((__GET_VAR(data__->TI,) / __UDINT_LITERAL(1000)) % __UDINT_LITERAL(60)))));
  __SET_VAR(data__->,SDT,.MINUTE,UDINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)((__UDINT_LITERAL(60) == 0)?0:((__GET_VAR(data__->TI,) / __UDINT_LITERAL(60000)) % __UDINT_LITERAL(60)))));
  __SET_VAR(data__->,SDT,.HOUR,UDINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)(__GET_VAR(data__->TI,) / __UDINT_LITERAL(3600000))));

  goto __end;

__end:
  return;
} // DT2_TO_SDT_body__() 





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


// FUNCTION
REAL REFRACTION(
  BOOL EN, 
  BOOL *__ENO, 
  REAL ELEV)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL TMP = 0;
  REAL REFRACTION = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return REFRACTION;
  }
  TMP = LIMIT__REAL__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)-1.9,
    (REAL)ELEV,
    (REAL)80.0);
  REFRACTION = (0.0174532925199433 / TAN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(0.0174532925199433 * (TMP + (10.3 / (TMP + 5.11))))));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return REFRACTION;
}


void SUN_POS_init__(SUN_POS *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->LATITUDE,0,retain)
  __INIT_VAR(data__->LONGITUDE,0,retain)
  __INIT_VAR(data__->UTC,0,retain)
  __INIT_VAR(data__->B,0,retain)
  __INIT_VAR(data__->HR,0,retain)
  __INIT_VAR(data__->G,0,retain)
  __INIT_VAR(data__->A,0,retain)
  __INIT_VAR(data__->_D,0,retain)
  __INIT_VAR(data__->H,0,retain)
  __INIT_VAR(data__->T1,0,retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->_E,0,retain)
  __INIT_VAR(data__->C,0,retain)
  __INIT_VAR(data__->TAU,0,retain)
  __INIT_VAR(data__->SIN_D,0,retain)
  __INIT_VAR(data__->RLAT,0,retain)
  __INIT_VAR(data__->SIN_LAT,0,retain)
  __INIT_VAR(data__->COS_LAT,0,retain)
  __INIT_VAR(data__->COS_TAU,0,retain)
  __INIT_VAR(data__->COS_D,0,retain)
  __INIT_VAR(data__->MATH_PI,3.14159265358979323846264338327950288,retain)
  __INIT_VAR(data__->MATH_PI2,6.28318530717958647692528676655900576,retain)
}

// Code part
void SUN_POS_body__(SUN_POS *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,N,,(UDINT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)(__GET_VAR(data__->UTC,) - __UDINT_LITERAL(946728000))) * 0.000011574074074074));
  __SET_VAR(data__->,G,,MODR(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(6.240040768 + (0.01720197 * __GET_VAR(data__->N,))),
    (REAL)__GET_VAR(data__->MATH_PI2,)));
  __SET_VAR(data__->,_D,,((MODR(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(4.89495042 + (0.017202792 * __GET_VAR(data__->N,))),
    (REAL)__GET_VAR(data__->MATH_PI2,)) + (0.033423055 * SIN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->G,)))) + (0.000349066 * SIN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(2.0 * __GET_VAR(data__->G,))))));
  __SET_VAR(data__->,_E,,(0.409087723 - (0.000000006981317008 * __GET_VAR(data__->N,))));
  __SET_VAR(data__->,COS_D,,COS__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->_D,)));
  __SET_VAR(data__->,SIN_D,,SIN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->_D,)));
  __SET_VAR(data__->,A,,ATAN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)((COS__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)__GET_VAR(data__->_E,)) * __GET_VAR(data__->SIN_D,)) / __GET_VAR(data__->COS_D,))));
  if ((__GET_VAR(data__->COS_D,) < 0.0)) {
    __SET_VAR(data__->,A,,(__GET_VAR(data__->A,) + __GET_VAR(data__->MATH_PI,)));
  };
  __SET_VAR(data__->,C,,ASIN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(SIN__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)__GET_VAR(data__->_E,)) * __GET_VAR(data__->SIN_D,))));
  __SET_VAR(data__->,TAU,,(RAD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)((MODR(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)((6.697376 + ((__GET_VAR(data__->N,) - 0.25) * 0.0657098245037645)) + (UDINT_TO_REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)_DT_TO_TOD(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (UDINT)__GET_VAR(data__->UTC,))) * 0.0000002785383333)),
      (REAL)24.0) * 15.0) + __GET_VAR(data__->LONGITUDE,))) - __GET_VAR(data__->A,)));
  __SET_VAR(data__->,RLAT,,RAD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->LATITUDE,)));
  __SET_VAR(data__->,SIN_LAT,,SIN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->RLAT,)));
  __SET_VAR(data__->,COS_LAT,,COS__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->RLAT,)));
  __SET_VAR(data__->,COS_TAU,,COS__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->TAU,)));
  __SET_VAR(data__->,T1,,((__GET_VAR(data__->COS_TAU,) * __GET_VAR(data__->SIN_LAT,)) - (TAN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->C,)) * __GET_VAR(data__->COS_LAT,))));
  __SET_VAR(data__->,B,,ATAN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(SIN__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)__GET_VAR(data__->TAU,)) / __GET_VAR(data__->T1,))));
  if ((__GET_VAR(data__->T1,) < 0.0)) {
    __SET_VAR(data__->,B,,(__GET_VAR(data__->B,) + __GET_VAR(data__->MATH_PI2,)));
  } else {
    __SET_VAR(data__->,B,,(__GET_VAR(data__->B,) + __GET_VAR(data__->MATH_PI,)));
  };
  __SET_VAR(data__->,B,,DEG(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)MODR(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)__GET_VAR(data__->B,),
      (REAL)__GET_VAR(data__->MATH_PI2,))));
  __SET_VAR(data__->,H,,DEG(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)ASIN__REAL__REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(((COS__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)__GET_VAR(data__->C,)) * __GET_VAR(data__->COS_TAU,)) * __GET_VAR(data__->COS_LAT,)) + (SIN__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)__GET_VAR(data__->C,)) * __GET_VAR(data__->SIN_LAT,))))));
  if ((__GET_VAR(data__->H,) > 180.0)) {
    __SET_VAR(data__->,H,,(__GET_VAR(data__->H,) - 360.0));
  };
  __SET_VAR(data__->,HR,,(__GET_VAR(data__->H,) + REFRACTION(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->H,))));

  goto __end;

__end:
  return;
} // SUN_POS_body__() 





void SUN_TIME_init__(SUN_TIME *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->LATITUDE,0,retain)
  __INIT_VAR(data__->LONGITUDE,0,retain)
  __INIT_VAR(data__->UTC,0,retain)
  __INIT_VAR(data__->H,-0.83333333333,retain)
  __INIT_VAR(data__->MIDDAY,0,retain)
  __INIT_VAR(data__->SUN_RISE,0,retain)
  __INIT_VAR(data__->SUN_SET,0,retain)
  __INIT_VAR(data__->SUN_DECLINATION,0,retain)
  __INIT_VAR(data__->DK,0,retain)
  __INIT_VAR(data__->DELTA,0,retain)
  __INIT_VAR(data__->B,0,retain)
}

// Code part
void SUN_TIME_body__(SUN_TIME *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,B,,(__GET_VAR(data__->LATITUDE,) * 0.0174532925199433));
  __SET_VAR(data__->,MIDDAY,,SUN_MIDDAY(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->LONGITUDE,),
    (UDINT)__GET_VAR(data__->UTC,)));
  __SET_VAR(data__->,DK,,(0.40954 * SIN__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)(0.0172 * (INT_TO_REAL(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)DAY_OF_YEAR(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)__GET_VAR(data__->UTC,))) - 79.35)))));
  __SET_VAR(data__->,SUN_DECLINATION,,DEG(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->DK,)));
  if ((__GET_VAR(data__->SUN_DECLINATION,) > 180.0)) {
    __SET_VAR(data__->,SUN_DECLINATION,,(__GET_VAR(data__->SUN_DECLINATION,) - 360.0));
  };
  __SET_VAR(data__->,SUN_DECLINATION,,((90.0 - __GET_VAR(data__->LATITUDE,)) + __GET_VAR(data__->SUN_DECLINATION,)));
  __SET_VAR(data__->,DELTA,,TIME_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (TIME)HOUR_TO_TIME(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (REAL)(ACOS__REAL__REAL(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (REAL)((SIN__REAL__REAL(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (REAL)RAD(
            (BOOL)__BOOL_LITERAL(TRUE),
            NULL,
            (REAL)__GET_VAR(data__->H,))) - (SIN__REAL__REAL(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (REAL)__GET_VAR(data__->B,)) * SIN__REAL__REAL(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (REAL)__GET_VAR(data__->DK,)))) / (COS__REAL__REAL(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (REAL)__GET_VAR(data__->B,)) * COS__REAL__REAL(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (REAL)__GET_VAR(data__->DK,))))) * 3.819718632))));
  __SET_VAR(data__->,SUN_RISE,,(__GET_VAR(data__->MIDDAY,) - __GET_VAR(data__->DELTA,)));
  __SET_VAR(data__->,SUN_SET,,(__GET_VAR(data__->MIDDAY,) + __GET_VAR(data__->DELTA,)));

  goto __end;

__end:
  return;
} // SUN_TIME_body__() 





// FUNCTION
UDINT LTIME_TO_UTC(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT LTIME, 
  BOOL _DST, 
  INT TIME_ZONE_OFFSET)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  UDINT LTIME_TO_UTC = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return LTIME_TO_UTC;
  }
  LTIME_TO_UTC = (LTIME - INT_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)(TIME_ZONE_OFFSET * 60)));
  if (_DST) {
    LTIME_TO_UTC = (LTIME_TO_UTC - __UDINT_LITERAL(3600));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return LTIME_TO_UTC;
}


void SDT_TO_DATE_init__(SDT_TO_DATE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const OSCAT_SDT temp = {0,0,0,0,0,0,0,0};
    __SET_VAR(data__->,DTI,,temp);
  }
  __INIT_VAR(data__->_SDT_TO_DATE,0,retain)
}

// Code part
void SDT_TO_DATE_body__(SDT_TO_DATE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_SDT_TO_DATE,,SET_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->DTI,.YEAR),
    (INT)__GET_VAR(data__->DTI,.MONTH),
    (INT)__GET_VAR(data__->DTI,.DAY)));

  goto __end;

__end:
  return;
} // SDT_TO_DATE_body__() 





// FUNCTION
REAL _SECOND(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT ITOD)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL _SECOND = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return _SECOND;
  }
  _SECOND = (UDINT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)((__UDINT_LITERAL(60000) == 0)?0:(ITOD % __UDINT_LITERAL(60000)))) / __REAL_LITERAL(1000.00));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return _SECOND;
}


// FUNCTION
REAL JD2000(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT DTI)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  REAL JD2000 = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return JD2000;
  }
  JD2000 = (UDINT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)(DTI - __UDINT_LITERAL(946728000))) / 86400.0);

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return JD2000;
}


// FUNCTION
INT DAYS_IN_YEAR(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT DAYS_IN_YEAR = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DAYS_IN_YEAR;
  }
  if (LEAP_OF_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)IDATE)) {
    DAYS_IN_YEAR = 366;
  } else {
    DAYS_IN_YEAR = 365;
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return DAYS_IN_YEAR;
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
UDINT MONTH_BEGIN(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  UDINT MONTH_BEGIN = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return MONTH_BEGIN;
  }
  MONTH_BEGIN = (IDATE - (INT_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)(DAY_OF_MONTH(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)IDATE) - 1)) * __UDINT_LITERAL(86400)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return MONTH_BEGIN;
}


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


void DCF77_init__(DCF77 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->REC,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SDT,0,retain)
  __INIT_VAR(data__->DSI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SYNC_TIMEOUT,__time_to_timespec(1, 0, 0, 2, 0, 0),retain)
  __INIT_VAR(data__->TIME_OFFSET,1,retain)
  __INIT_VAR(data__->DST_EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->_TP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->WDAY,0,retain)
  __INIT_VAR(data__->ERROR,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->_RTC,0,retain)
  __INIT_VAR(data__->RTC1,0,retain)
  __INIT_VAR(data__->MSEC,0,retain)
  __INIT_VAR(data__->SYNC,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MEZ,0,retain)
  __INIT_VAR(data__->UTC,0,retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->EDGE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TX,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TY,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->LAST,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  {
    static const __ARRAY_OF_BOOL_59 temp = {{__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE)}};
    __SET_VAR(data__->,BITS,,temp);
  }
  __INIT_VAR(data__->CNT,0,retain)
  __INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->OLD_TIME,0,retain)
  __INIT_VAR(data__->MINUTE,0,retain)
  __INIT_VAR(data__->_HOUR,0,retain)
  __INIT_VAR(data__->DAY,0,retain)
  __INIT_VAR(data__->MONTH,0,retain)
  __INIT_VAR(data__->YEAR,0,retain)
  __INIT_VAR(data__->LAST_SYNC,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->T1,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TZ,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->WORD_TEMP,0,retain)
  __INIT_VAR(data__->BOOL_TEMP,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void DCF77_body__(DCF77 *data__) {
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
  __SET_VAR(data__->,T1,,UDINT_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)T_PLC_MS(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__BOOL_LITERAL(FALSE))));
  __SET_VAR(data__->,TX,,__time_sub(__GET_VAR(data__->T1,), __GET_VAR(data__->LAST,)));
  if ((__GET_VAR(data__->REC,) && !__GET_VAR(data__->EDGE,)) || (!__GET_VAR(data__->REC,) && __GET_VAR(data__->EDGE,))) {
    __SET_VAR(data__->,EDGE,,__GET_VAR(data__->REC,));
    if (((!(__GET_VAR(data__->REC,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TX,), __time_to_timespec(1, 1700, 0, 0, 0, 0))) && LT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TX,), __time_to_timespec(1, 2000, 0, 0, 0, 0)))) {
      __SET_VAR(data__->,STATE,,0);
      __SET_VAR(data__->,_TP,,!(__GET_VAR(data__->ERROR,)));
    } else if (((!(__GET_VAR(data__->REC,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TX,), __time_to_timespec(1, 700, 0, 0, 0, 0))) && LT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TX,), __time_to_timespec(1, 1000, 0, 0, 0, 0)))) {
      if ((__GET_VAR(data__->STATE,) < 58)) {
        __SET_VAR(data__->,STATE,,(__GET_VAR(data__->STATE,) + 1));
      } else {
        __SET_VAR(data__->,STATE,,0);
      };
    } else if ((__GET_VAR(data__->REC,) && LT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TX,), __time_to_timespec(1, 120, 0, 0, 0, 0)))) {
      __SET_VAR(data__->,BITS,.table[(__GET_VAR(data__->STATE,)) - (0)],__BOOL_LITERAL(FALSE));
    } else if (((__GET_VAR(data__->REC,) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TX,), __time_to_timespec(1, 120, 0, 0, 0, 0))) && LT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->TX,), __time_to_timespec(1, 250, 0, 0, 0, 0)))) {
      __SET_VAR(data__->,BITS,.table[(__GET_VAR(data__->STATE,)) - (0)],__BOOL_LITERAL(TRUE));
    } else {
      __SET_VAR(data__->,ERROR,,__BOOL_LITERAL(TRUE));
      __SET_VAR(data__->,STATE,,0);
    };
    __SET_VAR(data__->,LAST,,__time_add(__GET_VAR(data__->LAST,), __GET_VAR(data__->TX,)));
    if ((__GET_VAR(data__->REC,) && (__GET_VAR(data__->STATE,) == 58))) {
      __SET_VAR(data__->,ERROR,,__BOOL_LITERAL(FALSE));
      if (((__GET_VAR(data__->BITS,.table[(0) - (0)]) || !((__GET_VAR(data__->BITS,.table[(17) - (0)]) && !__GET_VAR(data__->BITS,.table[(18) - (0)])) || (!__GET_VAR(data__->BITS,.table[(17) - (0)]) && __GET_VAR(data__->BITS,.table[(18) - (0)])))) || !(__GET_VAR(data__->BITS,.table[(20) - (0)])))) {
        __SET_VAR(data__->,ERROR,,__BOOL_LITERAL(TRUE));
      };
      __SET_VAR(data__->,WORD_TEMP,,__WORD_LITERAL(0));
      __SET_VAR(data__->,BOOL_TEMP,,__GET_VAR(data__->BITS,.table[(21) - (0)]));
      __SET_VAR(data__->,WORD_TEMP,,BIT_LOAD_W(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,),
        (BOOL)__GET_VAR(data__->BOOL_TEMP,),
        (INT)0));
      __SET_VAR(data__->,BOOL_TEMP,,__GET_VAR(data__->BITS,.table[(22) - (0)]));
      __SET_VAR(data__->,WORD_TEMP,,BIT_LOAD_W(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,),
        (BOOL)__GET_VAR(data__->BOOL_TEMP,),
        (INT)1));
      __SET_VAR(data__->,BOOL_TEMP,,__GET_VAR(data__->BITS,.table[(23) - (0)]));
      __SET_VAR(data__->,WORD_TEMP,,BIT_LOAD_W(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,),
        (BOOL)__GET_VAR(data__->BOOL_TEMP,),
        (INT)2));
      __SET_VAR(data__->,BOOL_TEMP,,__GET_VAR(data__->BITS,.table[(24) - (0)]));
      __SET_VAR(data__->,WORD_TEMP,,BIT_LOAD_W(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,),
        (BOOL)__GET_VAR(data__->BOOL_TEMP,),
        (INT)3));
      __SET_VAR(data__->,MINUTE,,WORD_TO_INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,)));
      if (__GET_VAR(data__->BITS,.table[(25) - (0)])) {
        __SET_VAR(data__->,MINUTE,,(__GET_VAR(data__->MINUTE,) + 10));
      };
      if (__GET_VAR(data__->BITS,.table[(26) - (0)])) {
        __SET_VAR(data__->,MINUTE,,(__GET_VAR(data__->MINUTE,) + 20));
      };
      if (__GET_VAR(data__->BITS,.table[(27) - (0)])) {
        __SET_VAR(data__->,MINUTE,,(__GET_VAR(data__->MINUTE,) + 40));
      };
      if (((__GET_VAR(data__->MINUTE,) > 59) || (((((((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && !__GET_VAR(data__->BITS,.table[(24) - (0)])) || (!((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && __GET_VAR(data__->BITS,.table[(24) - (0)])) && !__GET_VAR(data__->BITS,.table[(25) - (0)])) || (!(((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && !__GET_VAR(data__->BITS,.table[(24) - (0)])) || (!((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && __GET_VAR(data__->BITS,.table[(24) - (0)])) && __GET_VAR(data__->BITS,.table[(25) - (0)])) && !__GET_VAR(data__->BITS,.table[(26) - (0)])) || (!((((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && !__GET_VAR(data__->BITS,.table[(24) - (0)])) || (!((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && __GET_VAR(data__->BITS,.table[(24) - (0)])) && !__GET_VAR(data__->BITS,.table[(25) - (0)])) || (!(((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && !__GET_VAR(data__->BITS,.table[(24) - (0)])) || (!((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && __GET_VAR(data__->BITS,.table[(24) - (0)])) && __GET_VAR(data__->BITS,.table[(25) - (0)])) && __GET_VAR(data__->BITS,.table[(26) - (0)])) && !__GET_VAR(data__->BITS,.table[(27) - (0)])) || (!(((((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && !__GET_VAR(data__->BITS,.table[(24) - (0)])) || (!((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && __GET_VAR(data__->BITS,.table[(24) - (0)])) && !__GET_VAR(data__->BITS,.table[(25) - (0)])) || (!(((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && !__GET_VAR(data__->BITS,.table[(24) - (0)])) || (!((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && __GET_VAR(data__->BITS,.table[(24) - (0)])) && __GET_VAR(data__->BITS,.table[(25) - (0)])) && !__GET_VAR(data__->BITS,.table[(26) - (0)])) || (!((((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && !__GET_VAR(data__->BITS,.table[(24) - (0)])) || (!((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && __GET_VAR(data__->BITS,.table[(24) - (0)])) && !__GET_VAR(data__->BITS,.table[(25) - (0)])) || (!(((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && !__GET_VAR(data__->BITS,.table[(24) - (0)])) || (!((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && __GET_VAR(data__->BITS,.table[(24) - (0)])) && __GET_VAR(data__->BITS,.table[(25) - (0)])) && __GET_VAR(data__->BITS,.table[(26) - (0)])) && __GET_VAR(data__->BITS,.table[(27) - (0)])) && !__GET_VAR(data__->BITS,.table[(28) - (0)])) || (!((((((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && !__GET_VAR(data__->BITS,.table[(24) - (0)])) || (!((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && __GET_VAR(data__->BITS,.table[(24) - (0)])) && !__GET_VAR(data__->BITS,.table[(25) - (0)])) || (!(((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && !__GET_VAR(data__->BITS,.table[(24) - (0)])) || (!((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && __GET_VAR(data__->BITS,.table[(24) - (0)])) && __GET_VAR(data__->BITS,.table[(25) - (0)])) && !__GET_VAR(data__->BITS,.table[(26) - (0)])) || (!((((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && !__GET_VAR(data__->BITS,.table[(24) - (0)])) || (!((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && __GET_VAR(data__->BITS,.table[(24) - (0)])) && !__GET_VAR(data__->BITS,.table[(25) - (0)])) || (!(((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && !__GET_VAR(data__->BITS,.table[(24) - (0)])) || (!((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && __GET_VAR(data__->BITS,.table[(24) - (0)])) && __GET_VAR(data__->BITS,.table[(25) - (0)])) && __GET_VAR(data__->BITS,.table[(26) - (0)])) && !__GET_VAR(data__->BITS,.table[(27) - (0)])) || (!(((((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && !__GET_VAR(data__->BITS,.table[(24) - (0)])) || (!((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && __GET_VAR(data__->BITS,.table[(24) - (0)])) && !__GET_VAR(data__->BITS,.table[(25) - (0)])) || (!(((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && !__GET_VAR(data__->BITS,.table[(24) - (0)])) || (!((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && __GET_VAR(data__->BITS,.table[(24) - (0)])) && __GET_VAR(data__->BITS,.table[(25) - (0)])) && !__GET_VAR(data__->BITS,.table[(26) - (0)])) || (!((((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && !__GET_VAR(data__->BITS,.table[(24) - (0)])) || (!((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && __GET_VAR(data__->BITS,.table[(24) - (0)])) && !__GET_VAR(data__->BITS,.table[(25) - (0)])) || (!(((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && !__GET_VAR(data__->BITS,.table[(24) - (0)])) || (!((__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && !__GET_VAR(data__->BITS,.table[(23) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(21) - (0)]) && !__GET_VAR(data__->BITS,.table[(22) - (0)])) || (!__GET_VAR(data__->BITS,.table[(21) - (0)]) && __GET_VAR(data__->BITS,.table[(22) - (0)])) && __GET_VAR(data__->BITS,.table[(23) - (0)])) && __GET_VAR(data__->BITS,.table[(24) - (0)])) && __GET_VAR(data__->BITS,.table[(25) - (0)])) && __GET_VAR(data__->BITS,.table[(26) - (0)])) && __GET_VAR(data__->BITS,.table[(27) - (0)])) && __GET_VAR(data__->BITS,.table[(28) - (0)])))) {
        __SET_VAR(data__->,ERROR,,__BOOL_LITERAL(TRUE));
      };
      __SET_VAR(data__->,WORD_TEMP,,__WORD_LITERAL(0));
      __SET_VAR(data__->,BOOL_TEMP,,__GET_VAR(data__->BITS,.table[(29) - (0)]));
      __SET_VAR(data__->,WORD_TEMP,,BIT_LOAD_W(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,),
        (BOOL)__GET_VAR(data__->BOOL_TEMP,),
        (INT)0));
      __SET_VAR(data__->,BOOL_TEMP,,__GET_VAR(data__->BITS,.table[(30) - (0)]));
      __SET_VAR(data__->,WORD_TEMP,,BIT_LOAD_W(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,),
        (BOOL)__GET_VAR(data__->BOOL_TEMP,),
        (INT)1));
      __SET_VAR(data__->,BOOL_TEMP,,__GET_VAR(data__->BITS,.table[(31) - (0)]));
      __SET_VAR(data__->,WORD_TEMP,,BIT_LOAD_W(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,),
        (BOOL)__GET_VAR(data__->BOOL_TEMP,),
        (INT)2));
      __SET_VAR(data__->,BOOL_TEMP,,__GET_VAR(data__->BITS,.table[(32) - (0)]));
      __SET_VAR(data__->,WORD_TEMP,,BIT_LOAD_W(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,),
        (BOOL)__GET_VAR(data__->BOOL_TEMP,),
        (INT)3));
      __SET_VAR(data__->,_HOUR,,WORD_TO_INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,)));
      if (__GET_VAR(data__->BITS,.table[(33) - (0)])) {
        __SET_VAR(data__->,_HOUR,,(__GET_VAR(data__->_HOUR,) + 10));
      };
      if (__GET_VAR(data__->BITS,.table[(34) - (0)])) {
        __SET_VAR(data__->,_HOUR,,(__GET_VAR(data__->_HOUR,) + 20));
      };
      if (((__GET_VAR(data__->_HOUR,) > 23) || ((((((__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && !__GET_VAR(data__->BITS,.table[(31) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && __GET_VAR(data__->BITS,.table[(31) - (0)])) && !__GET_VAR(data__->BITS,.table[(32) - (0)])) || (!((__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && !__GET_VAR(data__->BITS,.table[(31) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && __GET_VAR(data__->BITS,.table[(31) - (0)])) && __GET_VAR(data__->BITS,.table[(32) - (0)])) && !__GET_VAR(data__->BITS,.table[(33) - (0)])) || (!(((__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && !__GET_VAR(data__->BITS,.table[(31) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && __GET_VAR(data__->BITS,.table[(31) - (0)])) && !__GET_VAR(data__->BITS,.table[(32) - (0)])) || (!((__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && !__GET_VAR(data__->BITS,.table[(31) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && __GET_VAR(data__->BITS,.table[(31) - (0)])) && __GET_VAR(data__->BITS,.table[(32) - (0)])) && __GET_VAR(data__->BITS,.table[(33) - (0)])) && !__GET_VAR(data__->BITS,.table[(34) - (0)])) || (!((((__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && !__GET_VAR(data__->BITS,.table[(31) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && __GET_VAR(data__->BITS,.table[(31) - (0)])) && !__GET_VAR(data__->BITS,.table[(32) - (0)])) || (!((__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && !__GET_VAR(data__->BITS,.table[(31) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && __GET_VAR(data__->BITS,.table[(31) - (0)])) && __GET_VAR(data__->BITS,.table[(32) - (0)])) && !__GET_VAR(data__->BITS,.table[(33) - (0)])) || (!(((__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && !__GET_VAR(data__->BITS,.table[(31) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && __GET_VAR(data__->BITS,.table[(31) - (0)])) && !__GET_VAR(data__->BITS,.table[(32) - (0)])) || (!((__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && !__GET_VAR(data__->BITS,.table[(31) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && __GET_VAR(data__->BITS,.table[(31) - (0)])) && __GET_VAR(data__->BITS,.table[(32) - (0)])) && __GET_VAR(data__->BITS,.table[(33) - (0)])) && __GET_VAR(data__->BITS,.table[(34) - (0)])) && !__GET_VAR(data__->BITS,.table[(35) - (0)])) || (!(((((__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && !__GET_VAR(data__->BITS,.table[(31) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && __GET_VAR(data__->BITS,.table[(31) - (0)])) && !__GET_VAR(data__->BITS,.table[(32) - (0)])) || (!((__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && !__GET_VAR(data__->BITS,.table[(31) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && __GET_VAR(data__->BITS,.table[(31) - (0)])) && __GET_VAR(data__->BITS,.table[(32) - (0)])) && !__GET_VAR(data__->BITS,.table[(33) - (0)])) || (!(((__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && !__GET_VAR(data__->BITS,.table[(31) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && __GET_VAR(data__->BITS,.table[(31) - (0)])) && !__GET_VAR(data__->BITS,.table[(32) - (0)])) || (!((__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && !__GET_VAR(data__->BITS,.table[(31) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && __GET_VAR(data__->BITS,.table[(31) - (0)])) && __GET_VAR(data__->BITS,.table[(32) - (0)])) && __GET_VAR(data__->BITS,.table[(33) - (0)])) && !__GET_VAR(data__->BITS,.table[(34) - (0)])) || (!((((__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && !__GET_VAR(data__->BITS,.table[(31) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && __GET_VAR(data__->BITS,.table[(31) - (0)])) && !__GET_VAR(data__->BITS,.table[(32) - (0)])) || (!((__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && !__GET_VAR(data__->BITS,.table[(31) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && __GET_VAR(data__->BITS,.table[(31) - (0)])) && __GET_VAR(data__->BITS,.table[(32) - (0)])) && !__GET_VAR(data__->BITS,.table[(33) - (0)])) || (!(((__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && !__GET_VAR(data__->BITS,.table[(31) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && __GET_VAR(data__->BITS,.table[(31) - (0)])) && !__GET_VAR(data__->BITS,.table[(32) - (0)])) || (!((__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && !__GET_VAR(data__->BITS,.table[(31) - (0)])) || (!(__GET_VAR(data__->BITS,.table[(29) - (0)]) && !__GET_VAR(data__->BITS,.table[(30) - (0)])) || (!__GET_VAR(data__->BITS,.table[(29) - (0)]) && __GET_VAR(data__->BITS,.table[(30) - (0)])) && __GET_VAR(data__->BITS,.table[(31) - (0)])) && __GET_VAR(data__->BITS,.table[(32) - (0)])) && __GET_VAR(data__->BITS,.table[(33) - (0)])) && __GET_VAR(data__->BITS,.table[(34) - (0)])) && __GET_VAR(data__->BITS,.table[(35) - (0)])))) {
        __SET_VAR(data__->,ERROR,,__BOOL_LITERAL(TRUE));
      };
      __SET_VAR(data__->,WORD_TEMP,,__WORD_LITERAL(0));
      __SET_VAR(data__->,BOOL_TEMP,,__GET_VAR(data__->BITS,.table[(36) - (0)]));
      __SET_VAR(data__->,WORD_TEMP,,BIT_LOAD_W(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,),
        (BOOL)__GET_VAR(data__->BOOL_TEMP,),
        (INT)0));
      __SET_VAR(data__->,BOOL_TEMP,,__GET_VAR(data__->BITS,.table[(37) - (0)]));
      __SET_VAR(data__->,WORD_TEMP,,BIT_LOAD_W(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,),
        (BOOL)__GET_VAR(data__->BOOL_TEMP,),
        (INT)1));
      __SET_VAR(data__->,BOOL_TEMP,,__GET_VAR(data__->BITS,.table[(38) - (0)]));
      __SET_VAR(data__->,WORD_TEMP,,BIT_LOAD_W(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,),
        (BOOL)__GET_VAR(data__->BOOL_TEMP,),
        (INT)2));
      __SET_VAR(data__->,BOOL_TEMP,,__GET_VAR(data__->BITS,.table[(39) - (0)]));
      __SET_VAR(data__->,WORD_TEMP,,BIT_LOAD_W(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,),
        (BOOL)__GET_VAR(data__->BOOL_TEMP,),
        (INT)3));
      __SET_VAR(data__->,DAY,,WORD_TO_INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,)));
      if (__GET_VAR(data__->BITS,.table[(40) - (0)])) {
        __SET_VAR(data__->,DAY,,(__GET_VAR(data__->DAY,) + 10));
      };
      if (__GET_VAR(data__->BITS,.table[(41) - (0)])) {
        __SET_VAR(data__->,DAY,,(__GET_VAR(data__->DAY,) + 20));
      };
      if ((__GET_VAR(data__->DAY,) > 31)) {
        __SET_VAR(data__->,ERROR,,__BOOL_LITERAL(TRUE));
      };
      __SET_VAR(data__->,WORD_TEMP,,__WORD_LITERAL(0));
      __SET_VAR(data__->,BOOL_TEMP,,__GET_VAR(data__->BITS,.table[(42) - (0)]));
      __SET_VAR(data__->,WORD_TEMP,,BIT_LOAD_W(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,),
        (BOOL)__GET_VAR(data__->BOOL_TEMP,),
        (INT)0));
      __SET_VAR(data__->,BOOL_TEMP,,__GET_VAR(data__->BITS,.table[(43) - (0)]));
      __SET_VAR(data__->,WORD_TEMP,,BIT_LOAD_W(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,),
        (BOOL)__GET_VAR(data__->BOOL_TEMP,),
        (INT)1));
      __SET_VAR(data__->,BOOL_TEMP,,__GET_VAR(data__->BITS,.table[(44) - (0)]));
      __SET_VAR(data__->,WORD_TEMP,,BIT_LOAD_W(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,),
        (BOOL)__GET_VAR(data__->BOOL_TEMP,),
        (INT)2));
      __SET_VAR(data__->,WDAY,,WORD_TO_INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,)));
      if (((__GET_VAR(data__->WDAY,) > 7) || (__GET_VAR(data__->WDAY,) < 1))) {
        __SET_VAR(data__->,ERROR,,__BOOL_LITERAL(TRUE));
      };
      __SET_VAR(data__->,WORD_TEMP,,__WORD_LITERAL(0));
      __SET_VAR(data__->,BOOL_TEMP,,__GET_VAR(data__->BITS,.table[(45) - (0)]));
      __SET_VAR(data__->,WORD_TEMP,,BIT_LOAD_W(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,),
        (BOOL)__GET_VAR(data__->BOOL_TEMP,),
        (INT)0));
      __SET_VAR(data__->,BOOL_TEMP,,__GET_VAR(data__->BITS,.table[(46) - (0)]));
      __SET_VAR(data__->,WORD_TEMP,,BIT_LOAD_W(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,),
        (BOOL)__GET_VAR(data__->BOOL_TEMP,),
        (INT)1));
      __SET_VAR(data__->,BOOL_TEMP,,__GET_VAR(data__->BITS,.table[(47) - (0)]));
      __SET_VAR(data__->,WORD_TEMP,,BIT_LOAD_W(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,),
        (BOOL)__GET_VAR(data__->BOOL_TEMP,),
        (INT)2));
      __SET_VAR(data__->,BOOL_TEMP,,__GET_VAR(data__->BITS,.table[(48) - (0)]));
      __SET_VAR(data__->,WORD_TEMP,,BIT_LOAD_W(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,),
        (BOOL)__GET_VAR(data__->BOOL_TEMP,),
        (INT)3));
      __SET_VAR(data__->,MONTH,,WORD_TO_INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,)));
      if (__GET_VAR(data__->BITS,.table[(49) - (0)])) {
        __SET_VAR(data__->,MONTH,,(__GET_VAR(data__->MONTH,) + 10));
      };
      if ((__GET_VAR(data__->MONTH,) > 12)) {
        __SET_VAR(data__->,ERROR,,__BOOL_LITERAL(TRUE));
      };
      __SET_VAR(data__->,WORD_TEMP,,__WORD_LITERAL(0));
      __SET_VAR(data__->,BOOL_TEMP,,__GET_VAR(data__->BITS,.table[(50) - (0)]));
      __SET_VAR(data__->,WORD_TEMP,,BIT_LOAD_W(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,),
        (BOOL)__GET_VAR(data__->BOOL_TEMP,),
        (INT)0));
      __SET_VAR(data__->,BOOL_TEMP,,__GET_VAR(data__->BITS,.table[(51) - (0)]));
      __SET_VAR(data__->,WORD_TEMP,,BIT_LOAD_W(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,),
        (BOOL)__GET_VAR(data__->BOOL_TEMP,),
        (INT)1));
      __SET_VAR(data__->,BOOL_TEMP,,__GET_VAR(data__->BITS,.table[(52) - (0)]));
      __SET_VAR(data__->,WORD_TEMP,,BIT_LOAD_W(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,),
        (BOOL)__GET_VAR(data__->BOOL_TEMP,),
        (INT)2));
      __SET_VAR(data__->,BOOL_TEMP,,__GET_VAR(data__->BITS,.table[(53) - (0)]));
      __SET_VAR(data__->,WORD_TEMP,,BIT_LOAD_W(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,),
        (BOOL)__GET_VAR(data__->BOOL_TEMP,),
        (INT)3));
      __SET_VAR(data__->,YEAR,,WORD_TO_INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (WORD)__GET_VAR(data__->WORD_TEMP,)));
      if (__GET_VAR(data__->BITS,.table[(54) - (0)])) {
        __SET_VAR(data__->,YEAR,,(__GET_VAR(data__->YEAR,) + 10));
      };
      if (__GET_VAR(data__->BITS,.table[(55) - (0)])) {
        __SET_VAR(data__->,YEAR,,(__GET_VAR(data__->YEAR,) + 20));
      };
      if (__GET_VAR(data__->BITS,.table[(56) - (0)])) {
        __SET_VAR(data__->,YEAR,,(__GET_VAR(data__->YEAR,) + 40));
      };
      if (__GET_VAR(data__->BITS,.table[(57) - (0)])) {
        __SET_VAR(data__->,YEAR,,(__GET_VAR(data__->YEAR,) + 80));
      };
      __SET_VAR(data__->,CNT,,0);
      for(__GET_VAR(data__->I,) = 36; __GET_VAR(data__->I,) <= 58; __GET_VAR(data__->I,)++) {
        if (__GET_VAR(data__->BITS,.table[(__GET_VAR(data__->I,)) - (0)])) {
          __SET_VAR(data__->,CNT,,(__GET_VAR(data__->CNT,) + 1));
        };
      };
      if (!(EVEN(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (DINT)INT_TO_DINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (INT)__GET_VAR(data__->CNT,))))) {
        __SET_VAR(data__->,ERROR,,__BOOL_LITERAL(TRUE));
      };
      if (!(__GET_VAR(data__->ERROR,))) {
        __SET_VAR(data__->,OLD_TIME,,__GET_VAR(data__->MEZ,));
        if ((__GET_VAR(data__->YEAR,) >= 70)) {
          __SET_VAR(data__->,YEAR,,(__GET_VAR(data__->YEAR,) + 1900));
        } else {
          __SET_VAR(data__->,YEAR,,(__GET_VAR(data__->YEAR,) + 2000));
        };
        __SET_VAR(data__->,MEZ,,SET_DT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (INT)__GET_VAR(data__->YEAR,),
          (INT)__GET_VAR(data__->MONTH,),
          (INT)__GET_VAR(data__->DAY,),
          (INT)__GET_VAR(data__->_HOUR,),
          (INT)__GET_VAR(data__->MINUTE,),
          (INT)0));
        __SET_VAR(data__->,DS,,__GET_VAR(data__->BITS,.table[(17) - (0)]));
        if (__GET_VAR(data__->DS,)) {
          __SET_VAR(data__->,UTC,,(__GET_VAR(data__->MEZ,) - __UDINT_LITERAL(7200)));
        } else {
          __SET_VAR(data__->,UTC,,(__GET_VAR(data__->MEZ,) - __UDINT_LITERAL(3600)));
        };
        if ((__GET_VAR(data__->MEZ,) != (__GET_VAR(data__->OLD_TIME,) + TIME_TO_UDINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (TIME)__time_to_timespec(1, 0, 0, 1, 0, 0))))) {
          __SET_VAR(data__->,ERROR,,__BOOL_LITERAL(TRUE));
        };
      };
    };
  };
  __SET_VAR(data__->,TZ,,UDINT_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)(INT_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)ABS__INT__INT(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)__GET_VAR(data__->TIME_OFFSET,))) * __UDINT_LITERAL(3600000))));
  if ((!(__GET_VAR(data__->INIT,)) || __GET_VAR(data__->SET,))) {
    __SET_VAR(data__->,INIT,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,UTC,,__GET_VAR(data__->SDT,));
    __SET_VAR(data__->,_TP,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,DS,,__GET_VAR(data__->DSI,));
  };
  if (__GET_VAR(data__->_TP,)) {
    __SET_VAR(data__->,_RTC,,__GET_VAR(data__->UTC,));
    if ((__GET_VAR(data__->DS,) && __GET_VAR(data__->DST_EN,))) {
      if ((__GET_VAR(data__->TIME_OFFSET,) < 0)) {
        __SET_VAR(data__->,RTC1,,(__GET_VAR(data__->_RTC,) - TIME_TO_UDINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (TIME)__time_add(__GET_VAR(data__->TZ,), __time_to_timespec(1, 0, 0, 0, 1, 0)))));
      } else {
        __SET_VAR(data__->,RTC1,,(__GET_VAR(data__->_RTC,) + TIME_TO_UDINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (TIME)__time_add(__GET_VAR(data__->TZ,), __time_to_timespec(1, 0, 0, 0, 1, 0)))));
      };
    } else {
      if ((__GET_VAR(data__->TIME_OFFSET,) < 0)) {
        __SET_VAR(data__->,RTC1,,(__GET_VAR(data__->_RTC,) - TIME_TO_UDINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (TIME)__GET_VAR(data__->TZ,))));
      } else {
        __SET_VAR(data__->,RTC1,,(__GET_VAR(data__->_RTC,) + TIME_TO_UDINT(
          (BOOL)__BOOL_LITERAL(TRUE),
          NULL,
          (TIME)__GET_VAR(data__->TZ,))));
      };
    };
    __SET_VAR(data__->,SYNC,,__BOOL_LITERAL(TRUE));
    __SET_VAR(data__->,LAST_SYNC,,__GET_VAR(data__->LAST,));
    __SET_VAR(data__->,TY,,__GET_VAR(data__->LAST,));
  } else if (((__GET_VAR(data__->_RTC,) > __UDINT_LITERAL(0)) && GE_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->T1,), __GET_VAR(data__->TY,)), __time_to_timespec(1, 0, 1, 0, 0, 0)))) {
    __SET_VAR(data__->,_RTC,,(__GET_VAR(data__->_RTC,) + TIME_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)__time_to_timespec(1, 0, 1, 0, 0, 0))));
    __SET_VAR(data__->,RTC1,,(__GET_VAR(data__->RTC1,) + TIME_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (TIME)__time_to_timespec(1, 0, 1, 0, 0, 0))));
    __SET_VAR(data__->,TY,,__time_add(__GET_VAR(data__->TY,), __time_to_timespec(1, 0, 1, 0, 0, 0)));
    __SET_VAR(data__->,SYNC,,(LT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __time_sub(__GET_VAR(data__->TY,), __GET_VAR(data__->LAST_SYNC,)), __GET_VAR(data__->SYNC_TIMEOUT,)) && GT_TIME(__BOOL_LITERAL(TRUE), NULL, 2, __GET_VAR(data__->LAST_SYNC,), __time_to_timespec(1, 0, 0, 0, 0, 0))));
    __SET_VAR(data__->,WDAY,,DAY_OF_WEEK(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)_DT_TO_DATE(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (UDINT)__GET_VAR(data__->RTC1,))));
    __SET_VAR(data__->,DS,,(__GET_VAR(data__->DST_EN,) && DST(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)__GET_VAR(data__->UTC,))));
  };
  __SET_VAR(data__->,MSEC,,TIME_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (TIME)__time_sub(__GET_VAR(data__->T1,), __GET_VAR(data__->TY,))));

  goto __end;

__end:
  return;
} // DCF77_body__() 





void SDT_TO_DT_init__(SDT_TO_DT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const OSCAT_SDT temp = {0,0,0,0,0,0,0,0};
    __SET_VAR(data__->,DTI,,temp);
  }
  __INIT_VAR(data__->_SDT_TO_DT,0,retain)
}

// Code part
void SDT_TO_DT_body__(SDT_TO_DT *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_SDT_TO_DT,,SET_DT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->DTI,.YEAR),
    (INT)__GET_VAR(data__->DTI,.MONTH),
    (INT)__GET_VAR(data__->DTI,.DAY),
    (INT)__GET_VAR(data__->DTI,.HOUR),
    (INT)__GET_VAR(data__->DTI,.MINUTE),
    (INT)__GET_VAR(data__->DTI,.SECOND)));

  goto __end;

__end:
  return;
} // SDT_TO_DT_body__() 





void DT_TO_SDT_init__(DT_TO_SDT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->DTI,0,retain)
  {
    static const OSCAT_SDT temp = {0,0,0,0,0,0,0,0};
    __SET_VAR(data__->,SDT,,temp);
  }
  __INIT_VAR(data__->TMP,0,retain)
  __INIT_VAR(data__->TDT,0,retain)
}

// Code part
void DT_TO_SDT_body__(DT_TO_SDT *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,TMP,,_DT_TO_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->DTI,)));
  __SET_VAR(data__->,TDT,,(__GET_VAR(data__->DTI,) - __GET_VAR(data__->TMP,)));
  __SET_VAR(data__->,SDT,.YEAR,YEAR_OF_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->TMP,)));
  __SET_VAR(data__->,SDT,.MONTH,MONTH_OF_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->TMP,)));
  __SET_VAR(data__->,SDT,.DAY,DAY_OF_MONTH(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->TMP,)));
  __SET_VAR(data__->,SDT,.WEEKDAY,DAY_OF_WEEK(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->TMP,)));
  __SET_VAR(data__->,SDT,.SECOND,UDINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)((__UDINT_LITERAL(60) == 0)?0:(__GET_VAR(data__->TDT,) % __UDINT_LITERAL(60)))));
  __SET_VAR(data__->,SDT,.MINUTE,UDINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)((__UDINT_LITERAL(60) == 0)?0:((__GET_VAR(data__->TDT,) / __UDINT_LITERAL(60)) % __UDINT_LITERAL(60)))));
  __SET_VAR(data__->,SDT,.HOUR,UDINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)(__GET_VAR(data__->TDT,) / __UDINT_LITERAL(3600))));

  goto __end;

__end:
  return;
} // DT_TO_SDT_body__() 





void SDT_TO_TOD_init__(SDT_TO_TOD *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const OSCAT_SDT temp = {0,0,0,0,0,0,0,0};
    __SET_VAR(data__->,DTI,,temp);
  }
  __INIT_VAR(data__->_SDT_TO_TOD,0,retain)
}

// Code part
void SDT_TO_TOD_body__(SDT_TO_TOD *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_SDT_TO_TOD,,((((INT_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->DTI,.HOUR)) * __UDINT_LITERAL(3600000)) + (INT_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->DTI,.MINUTE)) * __UDINT_LITERAL(60000))) + (INT_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->DTI,.SECOND)) * __UDINT_LITERAL(1000))) + INT_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->DTI,.MS))));

  goto __end;

__end:
  return;
} // SDT_TO_TOD_body__() 





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


// FUNCTION
DINT DAYS_DELTA(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT DATE_1, 
  UDINT DATE_2)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  DINT DAYS_DELTA = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DAYS_DELTA;
  }
  if ((DATE_1 > DATE_2)) {
    DAYS_DELTA =  -(UDINT_TO_DINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)((DATE_1 - DATE_2) / __UDINT_LITERAL(86400))));
  } else {
    DAYS_DELTA = UDINT_TO_DINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (UDINT)((DATE_2 - DATE_1) / __UDINT_LITERAL(86400)));
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return DAYS_DELTA;
}


void RTC_2_init__(RTC_2 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->SET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SDT,0,retain)
  __INIT_VAR(data__->SMS,0,retain)
  __INIT_VAR(data__->DEN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OFS,0,retain)
  __INIT_VAR(data__->UDT,0,retain)
  __INIT_VAR(data__->LDT,0,retain)
  __INIT_VAR(data__->DSO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->XMS,0,retain)
  RTC_MS_init__(&data__->RT,retain);
}

// Code part
void RTC_2_body__(RTC_2 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->RT.,SET,,__GET_VAR(data__->SET,));
  __SET_VAR(data__->RT.,SDT,,__GET_VAR(data__->SDT,));
  __SET_VAR(data__->RT.,SMS,,__GET_VAR(data__->SMS,));
  RTC_MS_body__(&data__->RT);
  __SET_VAR(data__->,UDT,,__GET_VAR(data__->RT.XDT,));
  __SET_VAR(data__->,XMS,,__GET_VAR(data__->RT.XMS,));
  __SET_VAR(data__->,DSO,,(DST(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->UDT,)) && __GET_VAR(data__->DEN,)));
  __SET_VAR(data__->,LDT,,(__GET_VAR(data__->UDT,) + (INT_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)(__GET_VAR(data__->OFS,) + (BOOL_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)__GET_VAR(data__->DSO,)) * 60))) * __UDINT_LITERAL(60))));

  goto __end;

__end:
  return;
} // RTC_2_body__() 





// FUNCTION
INT WORK_WEEK(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  UDINT D1 = 0;
  INT W1 = 0;
  UDINT DS = 0;
  INT YR = 0;
  INT W31 = 0;
  INT W01 = 0;
  INT WM = 0;
  INT WORK_WEEK = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return WORK_WEEK;
  }
  YR = YEAR_OF_DATE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)IDATE);
  D1 = YEAR_BEGIN(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)YR);
  W1 = DAY_OF_WEEK(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)D1);
  if ((W1 < 5)) {
    DS = (D1 - (INT_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)(W1 + 6)) * __UDINT_LITERAL(86400)));
  } else {
    DS = (D1 + (INT_TO_UDINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)(1 - W1)) * __UDINT_LITERAL(86400)));
  };
  WORK_WEEK = UDINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)((IDATE - DS) / __UDINT_LITERAL(604800)));
  if ((WORK_WEEK == 0)) {
    if ((W1 > 1)) {
      W31 = (W1 - 1);
    } else {
      W31 = 7;
    };
    if (LEAP_YEAR(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)(YR - 1))) {
      if ((W31 > 1)) {
        W01 = (W31 - 1);
      } else {
        W1 = 7;
      };
    };
    WORK_WEEK = (52 + BOOL_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)((W31 == 4) || (W01 == 4))));
  } else {
    if (LEAP_YEAR(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)YR)) {
      if ((W1 < 7)) {
        W31 = (W1 + 1);
      } else {
        W31 = 1;
      };
    } else {
      W31 = W1;
    };
    WM = (52 + BOOL_TO_INT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (BOOL)((W31 == 4) || (W1 == 4))));
    if ((WORK_WEEK > WM)) {
      WORK_WEEK = 1;
    };
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return WORK_WEEK;
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


// FUNCTION
INT SECOND_OF_DT(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT XDT)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT SECOND_OF_DT = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return SECOND_OF_DT;
  }
  SECOND_OF_DT = UDINT_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)((__UDINT_LITERAL(60) == 0)?0:(XDT % __UDINT_LITERAL(60))));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return SECOND_OF_DT;
}


// FUNCTION
UDINT EASTER(
  BOOL EN, 
  BOOL *__ENO, 
  INT YEAR)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  INT B = 0;
  INT C = 0;
  INT ODAY = 0;
  UDINT EASTER = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return EASTER;
  }
  B = ((30 == 0)?0:((204 - (11 * ((19 == 0)?0:(YEAR % 19)))) % 30));
  if ((B > 27)) {
    B = (B - 1);
  };
  C = ((7 == 0)?0:((((YEAR + WORD_TO_INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (WORD)SHR__WORD__WORD__SINT(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (WORD)INT_TO_WORD(
        (BOOL)__BOOL_LITERAL(TRUE),
        NULL,
        (INT)YEAR),
      (SINT)2))) + B) - 13) % 7));
  ODAY = ((28 + B) - C);
  if ((ODAY > 33)) {
    EASTER = SET_DATE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)YEAR,
      (INT)4,
      (INT)(ODAY - 31));
  } else {
    EASTER = SET_DATE(
      (BOOL)__BOOL_LITERAL(TRUE),
      NULL,
      (INT)YEAR,
      (INT)3,
      (INT)ODAY);
  };

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return EASTER;
}


// FUNCTION
DINT DAY_OF_DATE(
  BOOL EN, 
  BOOL *__ENO, 
  UDINT IDATE)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  DINT DAY_OF_DATE = 0;

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return DAY_OF_DATE;
  }
  DAY_OF_DATE = UDINT_TO_DINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)(IDATE / __UDINT_LITERAL(86400)));

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return DAY_OF_DATE;
}


