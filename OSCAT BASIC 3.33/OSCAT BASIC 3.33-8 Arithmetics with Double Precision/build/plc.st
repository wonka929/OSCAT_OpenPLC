TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK



FUNCTION_BLOCK python_eval
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_poll
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_gear
  VAR_INPUT
    N : UINT;
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    py_eval : python_eval;
    COUNTER : UINT;
    ADD10_OUT : UINT;
    EQ13_OUT : BOOL;
    SEL15_OUT : UINT;
    AND7_OUT : BOOL;
  END_VAR

  ADD10_OUT := ADD(COUNTER, 1);
  EQ13_OUT := EQ(N, ADD10_OUT);
  SEL15_OUT := SEL(EQ13_OUT, ADD10_OUT, 0);
  COUNTER := SEL15_OUT;
  AND7_OUT := AND(EQ13_OUT, TRIG);
  py_eval(TRIG := AND7_OUT, CODE := CODE);
  ACK := py_eval.ACK;
  RESULT := py_eval.RESULT;
END_FUNCTION_BLOCK


TYPE
  REAL2 : STRUCT
    R1 : REAL;
    RX : REAL;
  END_STRUCT;
END_TYPE

FUNCTION_BLOCK R2_SET
  VAR_INPUT
    X : REAL;
  END_VAR
  VAR_OUTPUT
    _R2_SET : REAL2;
  END_VAR

  _R2_SET.RX := X;
  _R2_SET.R1 := 0.0;

  (* From OSCAT Library, www.oscat.de *)
  (* Datatype REAL2 required *)
END_FUNCTION_BLOCK

PROGRAM program0
  VAR
    LocalVar0 : DINT;
    LocalVar1 : DINT;
    LocalVar2 : DINT;
    ADD1_OUT : DINT;
  END_VAR

  ADD1_OUT := ADD(LocalVar0, LocalVar1);
  LocalVar2 := ADD1_OUT;
END_PROGRAM

FUNCTION_BLOCK R2_ADD
  VAR_INPUT
    X : REAL2;
    Y : REAL;
    _R2_ADD : REAL2;
  END_VAR
  VAR
    temp : REAL;
  END_VAR

  temp := X.RX;
  _R2_ADD.RX := Y + X.R1 + X.RX;
  _R2_ADD.R1 := temp - _R2_ADD.RX + Y + X.R1;

  (* From OSCAT Library, www.oscat.de *)
  (* Datatype REAL2 required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK R2_DIV
  VAR_INPUT
    X : REAL2;
    Y : REAL;
    _R2_DIV : REAL2;
  END_VAR

  _R2_DIV.RX := X.RX / Y;
  _R2_DIV.R1 := X.R1 / Y;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK R2_ABS
  VAR_INPUT
    X : REAL2;
  END_VAR
  VAR_OUTPUT
    _R2_ABS : REAL2;
  END_VAR

  IF X.RX >= 0.0 THEN
  	_R2_ABS.RX := X.RX;
  	_R2_ABS.R1 := X.R1;
  ELSE
  	_R2_ABS.RX := -X.RX;
  	_R2_ABS.R1 := -X.R1;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK R2_MUL
  VAR_INPUT
    X : REAL2;
    Y : REAL;
  END_VAR
  VAR_OUTPUT
    _R2_MUL : REAL2;
  END_VAR

  _R2_MUL.RX := X.RX * Y;
  _R2_MUL.R1 := X.R1 * Y;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION MUX_R2 : REAL
  VAR_INPUT
    IN0 : REAL;
    IN1 : REAL;
    A : BOOL;
  END_VAR

  MUX_R2 := SEL(A, IN0, IN1);

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK R2_ADD2
  VAR_INPUT
    X : REAL2;
    Y : REAL2;
  END_VAR
  VAR_OUTPUT
    _R2_ADD2 : REAL2;
  END_VAR

  _R2_ADD2.R1 := X.R1 + Y.R1;
  _R2_ADD2.RX := X.RX + Y.RX;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
