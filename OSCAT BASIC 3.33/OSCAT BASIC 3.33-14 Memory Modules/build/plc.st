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


FUNCTION INC1 : INT
  VAR_INPUT
    X : INT;
    N : INT;
  END_VAR

  IF X >= N - 1 THEN
  	INC1 := 0;
  ELSE
  	INC1 := X + 1;
  END_IF;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION_BLOCK STACK_16
  VAR_INPUT
    DIN : DWORD;
    _E : BOOL := TRUE;
    RD : BOOL;
    WD : BOOL;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    DOUT : DWORD;
    EMPTY : BOOL := TRUE;
    FULL : BOOL;
  END_VAR
  VAR
    pt : INT;
    stack : ARRAY [0..15] OF DWORD;
  END_VAR

  IF RST THEN
  	(* asynchronous reset for the fifo *)
  	pt := 0;
  	EMPTY := TRUE;
  	FULL := FALSE;
  	Dout := DWORD#0;
  ELSIF _E THEN
  	IF NOT EMPTY AND RD THEN
  		(* read one element *)
  		pt := pt - 1;
  		Dout := stack[pt];
  		EMPTY := pt = 0;
  		FULL := FALSE;
  	END_IF;
  	IF NOT FULL AND WD THEN
  		(* write one element *)
  		stack[pt] := Din;
  		pt := pt + 1;
  		FULL := pt > 15;
  		EMPTY := FALSE;
  	END_IF;
  END_IF;

  (* from OSCAT library; www.oscat.de  *)
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

FUNCTION_BLOCK FIFO_32
  VAR_INPUT
    DIN : DWORD;
    _E : BOOL := TRUE;
    RD : BOOL;
    WD : BOOL;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    DOUT : DWORD;
    EMPTY : BOOL := TRUE;
    FULL : BOOL;
  END_VAR
  VAR
    fifo : ARRAY [0..31] OF DWORD;
    pr : INT;
    pw : INT;
  END_VAR

  IF RST THEN
  	pw := pr;
  	FULL := FALSE;
  	EMPTY := TRUE;
  	Dout := DWORD#0;
  ELSIF _E THEN
  	IF NOT EMPTY AND RD THEN
  		Dout := fifo[pr];
  		pr := INC1(pr,32);
  		EMPTY := pr = pw;
  		FULL := FALSE;
  	END_IF;
  	IF NOT FULL AND WD THEN
  		fifo[pw] := Din;
  		pw := INC1(pw,32);
  		FULL := pw = pr;
  		EMPTY := FALSE;
  	END_IF;
  END_IF;


  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK FIFO_16
  VAR_INPUT
    DIN : DWORD;
    _E : BOOL := TRUE;
    RD : BOOL;
    WD : BOOL;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    DOUT : DWORD;
    EMPTY : BOOL := TRUE;
    FULL : BOOL;
  END_VAR
  VAR
    fifo : ARRAY [0..15] OF DWORD;
    pr : INT;
    pw : INT;
  END_VAR

  IF RST THEN
  	pw := pr;
  	FULL := FALSE;
  	EMPTY := TRUE;
  	Dout := DWORD#0;
  ELSIF _E THEN
  	IF NOT EMPTY AND RD THEN
  		Dout := fifo[pr];
  		pr := INC1(pr,16);
  		EMPTY := pr = pw;
  		FULL := FALSE;
  	END_IF;
  	IF NOT FULL AND WD THEN
  		fifo[pw] := Din;
  		pw := INC1(pw,16);
  		FULL := pw = pr;
  		EMPTY := FALSE;
  	END_IF;
  END_IF;

  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK STACK_32
  VAR_INPUT
    DIN : DWORD;
    _E : BOOL := TRUE;
    RD : BOOL;
    WD : BOOL;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    DOUT : DWORD;
    EMPTY : BOOL := TRUE;
    FULL : BOOL;
  END_VAR
  VAR
    pt : INT;
    stack : ARRAY [0..31] OF DWORD;
  END_VAR

  IF RST THEN
  	(* asynchronous reset for the fifo *)
  	pt := 0;
  	EMPTY := TRUE;
  	FULL := FALSE;
  	Dout := DWORD#0;
  ELSIF _E THEN
  	IF NOT EMPTY AND RD THEN
  		(* read one element *)
  		pt := pt - 1;
  		Dout := stack[pt];
  		EMPTY := pt = 0;
  		FULL := FALSE;
  	END_IF;
  	IF NOT FULL AND WD THEN
  		(* write one element *)
  		stack[pt] := Din;
  		pt := pt + 1;
  		FULL := pt > 31;
  		EMPTY := FALSE;
  	END_IF;
  END_IF;

  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION_BLOCK


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
