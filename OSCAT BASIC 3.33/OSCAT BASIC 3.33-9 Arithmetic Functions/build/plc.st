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


FUNCTION T_PLC_MS : UDINT
  VAR
    tx : UDINT;
  END_VAR
  VAR_INPUT
    debug : BOOL;
  END_VAR
  VAR
    N : INT := 0;
    offset : UDINT := 0;
    temp : DWORD := 1;
  END_VAR

  tx := 0;

  {extern unsigned long __tick;
  extern unsigned long long common_ticktime__;
  unsigned long long ticktime_ms = (common_ticktime__)/1000000;
  UDINT plc_time = (UDINT)(ticktime_ms * (unsigned long long)__tick);
  TX = plc_time}

  T_PLC_MS := tx;
  IF debug THEN
  	T_PLC_MS := (DWORD_TO_UDINT(SHL(UDINT_TO_DWORD(T_PLC_MS),N) OR SHL(temp,N))-1) + OFFSET;
  END_IF;

  (* Original Code:
  tx := TIME();
  T_PLC_MS := TIME_TO_DWORD(Tx);
  IF debug THEN
  	T_PLC_MS := (SHL(T_PLC_MS,N) OR SHL(DWORD#1,N)-1) + OFFSET;
  END_IF;
  *)

  (* From OSCAT library, www.oscat.de

  this is a temporary T_PLC_MS FB until OpenPLC gets it´s own time() functionality *)

  (* PLC_TIME and Global variables PLC_SCAN_CYCL and PLC_CYCL_TIME required *)
END_FUNCTION

FUNCTION_BLOCK FT_RMP
  VAR_INPUT
    RMP : BOOL := TRUE;
    IN : REAL;
    KR : REAL;
    KF : REAL;
  END_VAR
  VAR_OUTPUT
    OUT : REAL;
    BUSY : BOOL;
    UD : BOOL;
  END_VAR
  VAR
    tx : TIME;
    last : TIME;
    init : BOOL;
  END_VAR


  tx := UDINT_TO_TIME(T_PLC_MS(en:=true)) - last;

  IF NOT init THEN
  	init := TRUE;
  	last := tx;
  	tx := t#0s;
  	out := in;
  END_IF;
  IF NOT rmp THEN
  	out := in;
  	busy := FALSE;
  ELSIF out > in THEN
  	(* ramp down *)
  	out := out - TIME_TO_REAL(tx) * 0.001 * KF;
  	out := MAX(in, out);
  ELSIF out < in THEN
  	(* ramp up *)
  	out := out + TIME_TO_REAL(tx) * 0.001 * KR;
  	out := MIN(in, out);
  END_IF;

  (* set busy and dir flags *)
  IF out < in THEN
  	busy := TRUE;
  	ud := TRUE;
  ELSIF out > in THEN
  	busy := TRUE;
  	ud := FALSE;
  ELSE
  	busy := FALSE;
  END_IF;
  last := last + tx;

  (* From Oscat Library, www.oscat.de *)
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
  (* from OSCAT library www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK F_POLY
  VAR_INPUT
    X : REAL;
    C : ARRAY [0..7] OF REAL;
  END_VAR
  VAR_OUTPUT
    _F_POLY : REAL;
  END_VAR

  _F_POLY := ((((((( c[7] * x + c[6] ) * x + c[5] ) * x + c[4] ) * x + c[3] ) * x + c[2] ) * x + c[1] ) * x + c[0] ) ;
END_FUNCTION_BLOCK

PROGRAM program0
  VAR
    LocalVar0 : DINT;
    LocalVar1 : DINT;
    LocalVar2 : DINT;
    LocalVar3 : REAL;
    F_POLY0 : F_POLY;
    ADD1_OUT : DINT;
  END_VAR

  ADD1_OUT := ADD(LocalVar0, LocalVar1);
  LocalVar2 := ADD1_OUT;
  F_POLY0(X := LocalVar3);
END_PROGRAM

FUNCTION LINEAR_INT : REAL
  VAR_INPUT
    X : REAL;
    XY : ARRAY [1..20,0..1] OF REAL;
    Pts : INT;
  END_VAR
  VAR
    i : INT;
  END_VAR

  pts := MIN(pts,20);
  i := 2;
  WHILE (i < pts) AND (XY[i,0] < X) DO
  	i := i + 1;
  END_WHILE;
  LINEAR_INT := ((XY[i,1] - XY[i-1,1]) * X - XY[i,1] * XY[i-1,0] + XY[i-1,1] * XY[i,0]) / (XY[i,0] - XY[i-1,0]);
  (* from OSCAT library www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK _FB_LINEAR_INT
  VAR_INPUT
    X : REAL;
    XY : ARRAY [1..20,0..1] OF REAL;
    PTS : INT;
  END_VAR
  VAR_OUTPUT
    _LINEAR_INT : REAL;
  END_VAR
  VAR
    i : INT;
    i2 : INT;
  END_VAR

  pts := MIN(pts,20);
  i := 2;
  WHILE (i < pts) AND (XY[i,0] < X) DO
  	i := i + 1;
  END_WHILE;
  _LINEAR_INT := ((XY[i,1] - XY[i-1,1]) * X - XY[i,1] * XY[i-1,0] + XY[i-1,1] * XY[i,0]) / (XY[i,0] - XY[i-1,0]);


  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION FRMP_B : BYTE
  VAR
    START : BYTE;
    DIR : BOOL;
    TD : TIME;
    TR : TIME;
  END_VAR

  IF TD < TR THEN
  	FRMP_B := MIN(UDINT_TO_BYTE(DWORD_TO_UDINT(SHL(TIME_TO_DWORD(TD), 8)) / TIME_TO_UDINT(TR)), SEL(DIR, START, USINT_TO_BYTE(USINT#255 - BYTE_TO_USINT(START))));
  	IF DIR THEN
  		FRMP_B := USINT_TO_BYTE(BYTE_TO_USINT(START) + BYTE_TO_USINT(FRMP_B));
  	ELSE
  		FRMP_B := USINT_TO_BYTE(BYTE_TO_USINT(START) - BYTE_TO_USINT(FRMP_B));
  	END_IF;
  ELSE
  	FRMP_B := SEL(DIR, BYTE#0, BYTE#255);
  END_IF;
  (* from OSCAT library www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK DELAY
  VAR_INPUT
    IN : REAL;
    N : INT;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    OUT : REAL;
  END_VAR
  VAR
    i : INT;
    init : BOOL;
    stop : INT;
    buf : ARRAY [0..31] OF REAL;
  END_VAR

  stop := LIMIT(0,N,32) - 1;
  IF rst OR NOT init THEN
  	init := TRUE;
  	FOR i := 0 TO stop DO buf[i] := in; END_FOR;
  	out := in;
  	i := 0;
  ELSIF stop < 0 THEN
  	out := in;
  ELSE
  	out := buf[i];
  	buf[i] := in;
  	i := INC1(i, N);
  END_IF;
  (* from OSCAT library www.oscat.de *)
  (* inc1 requiered *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK FT_AVG
  VAR_INPUT
    IN : REAL;
    _E : BOOL := TRUE;
    RST : BOOL;
    N : INT := 32;
  END_VAR
  VAR_OUTPUT
    AVG : REAL;
  END_VAR
  VAR
    buff : DELAY;
    i : INT;
    init : BOOL;
  END_VAR

  buff.N := LIMIT(0, N, 32);

  IF NOT init OR rst THEN
  	FOR i := 1 TO N DO
  		buff(in := in);
  	END_FOR;
  	avg := in;
  	init := TRUE;
  ELSIF _E THEN
  	buff(in := in);
  	avg := avg + (in - buff.out ) / INT_TO_REAL(N);
  END_IF;
  (* from OSCAT library www.oscat.de *)
  (* FB FC delay and inc1 requiered *)
END_FUNCTION_BLOCK

FUNCTION F_QUAD : REAL
  VAR
    X : REAL;
    A : REAL;
    B : REAL;
    C : REAL;
  END_VAR

  F_QUAD :=  (A * X + B) * X + C;
  (* from OSCAT library www.oscat.de *)
END_FUNCTION

FUNCTION F_POWER : REAL
  VAR
    A : REAL;
    X : REAL;
    N : REAL;
  END_VAR

  f_power := a * EXPT(X,N);
  (* from OSCAT library www.oscat.de *)
END_FUNCTION

FUNCTION F_LIN : REAL
  VAR_INPUT
    X : REAL;
    A : REAL;
    B : REAL;
  END_VAR

  F_lin := A * X + B;
  (* from OSCAT library www.oscat.de *)
END_FUNCTION

FUNCTION F_LIN2 : REAL
  VAR_INPUT
    X : REAL;
    X1 : REAL;
    X2 : REAL;
    Y1 : REAL;
    Y2 : REAL;
  END_VAR

  F_LIN2 := (Y2 - Y1) / (X2 - X1) * (X - X1) + Y1;
  (* from OSCAT library www.oscat.de *)
END_FUNCTION

FUNCTION POLYNOM_INT : REAL
  VAR_INPUT
    X : REAL;
    XY : ARRAY [1..5,0..1] OF REAL;
    Pts : INT;
  END_VAR
  VAR
    I : INT;
    J : INT;
    stop : INT;
  END_VAR

  pts := MIN(pts, 5);
  FOR i := 1 TO pts DO
  	stop := i + 1;
     	FOR j := pts TO stop BY -1 DO
     		XY[j,1] := (XY[j,1] - XY[j-1,1]) / (XY[j,0] - XY[j-i,0]);
  	END_FOR;
  END_FOR;
  POLYNOM_INT := 0.0;
  FOR i := pts TO 1 BY -1 DO
         POLYNOM_INT := POLYNOM_INT * (X - XY[i,0]) + XY[i,1];
  END_FOR;

END_FUNCTION

FUNCTION_BLOCK FT_MIN_MAX
  VAR_INPUT
    IN : REAL;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    MX : REAL;
    MN : REAL;
  END_VAR
  VAR
    init : BOOL;
  END_VAR

  IF (rst = TRUE) OR (init = FALSE) THEN
    mn := in;
    mx := in;
    init := TRUE;
  ELSIF (in < mn) THEN
    mn := in;
  ELSIF (in > mx) THEN
    mx := in;
  END_IF;
  (* from OSCAT library www.oscat.de *)
END_FUNCTION_BLOCK


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
