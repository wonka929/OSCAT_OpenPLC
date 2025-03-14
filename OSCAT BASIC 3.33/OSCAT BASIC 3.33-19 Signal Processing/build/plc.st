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


FUNCTION WORD_TO_RANGE : REAL
  VAR_INPUT
    X : WORD;
    LOW : REAL;
    HIGH : REAL;
  END_VAR

  WORD_TO_RANGE := (high - low) * WORD_TO_REAL(X) * 0.00001525902189669640 + low;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION SCALE : REAL
  VAR_INPUT
    X : REAL;
    K : REAL;
    O : REAL;
    MX : REAL;
    MN : REAL;
  END_VAR

  SCALE := LIMIT(MN, X * K + O, MX);

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION SCALE_X4 : REAL
  VAR_INPUT
    IN1 : BOOL;
    IN2 : BOOL;
    IN3 : BOOL;
    IN4 : BOOL;
    K : REAL;
    O : REAL;
    IN1_MIN : REAL;
    IN1_MAX : REAL;
    IN2_MIN : REAL;
    IN2_MAX : REAL;
    IN3_MIN : REAL;
    IN3_MAX : REAL;
    IN4_MIN : REAL;
    IN4_MAX : REAL;
  END_VAR

  IF NOT in1 THEN scale_X4 := in1_min; ELSE scale_X4 := in1_max; END_IF;
  IF NOT in2 THEN scale_x4 := scale_x4 + in2_min; ELSE scale_x4 := scale_x4 + in2_max; END_IF;
  IF NOT in3 THEN scale_x4 := scale_x4 + in3_min; ELSE scale_x4 := scale_x4 + in3_max; END_IF;
  IF NOT in4 THEN scale_x4 := scale_x4 + in4_min; ELSE scale_x4 := scale_x4 + in4_max; END_IF;
  scale_X4 := scale_X4 * k + O;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION SIGN_R : BOOL
  VAR_INPUT
    IN : REAL;
  END_VAR

  SIGN_R := in < 0.0;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION AOUT : DWORD
  VAR_INPUT
    IN : REAL;
    BITS : BYTE;
    SIGN : BYTE;
    LOW : REAL;
    HIGH : REAL;
  END_VAR
  VAR
    in2 : REAL;
    sx : BOOL;
  END_VAR

  (* if sign bit is defined *)
  IF sign < BYTE#32 THEN
  	sx := sign_R(in);
  	in2 := ABS(in);
  ELSE
  	in2 := in;
  END_IF;

  (* begrenze in auf die zulässigen werte *)
  in2 := LIMIT(low, in2, high);

  (* Berechne den Ausgangswert *)
  Aout := REAL_TO_DWORD((in2 - low) / (high - low) * (DWORD_TO_REAL(SHL(DWORD#2#1,BYTE_TO_INT(bits))) - 1.0)   );
  IF sx THEN Aout := SHL(DWORD#2#1,BYTE_TO_INT(sign)) OR Aout; END_IF;
    
  (* From OSCAT Library, www.oscat.de *)
  (* SIGN_R required *)
END_FUNCTION

FUNCTION OFFSET2 : REAL
  VAR_INPUT
    X : REAL;
    O1 : BOOL;
    O2 : BOOL;
    O3 : BOOL;
    O4 : BOOL;
    _D : BOOL;
  END_VAR
  VAR
    OFFSET_1 : REAL;
    OFFSET_2 : REAL;
    OFFSET_3 : REAL;
    OFFSET_4 : REAL;
    DEFAULT : REAL;
  END_VAR

  IF _D THEN Offset2 := default; ELSE Offset2 := X; END_IF;
  IF O4 THEN Offset2 := Offset2 + offset_4;
  ELSIF O3 THEN Offset2 := Offset2 + offset_3;
  ELSIF O2 THEN Offset2 := Offset2 + offset_2;
  ELSIF O1 THEN Offset2 := Offset2 + offset_1;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

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
  	T_PLC_MS := (SHL(T_PLC_MS,N) OR SHL(DWORD#1,N)-1) + _OFFSET;
  END_IF;
  *)

  (* From OSCAT library, www.oscat.de

  this is a temporary T_PLC_MS FB until OpenPLC gets it´s own time() functionality *)

  (* PLC_TIME and Global variables PLC_SCAN_CYCL and PLC_CYCL_TIME required *)
END_FUNCTION

FUNCTION_BLOCK FILTER_DW
  VAR_INPUT
    X : DWORD;
    _T : TIME;
  END_VAR
  VAR_OUTPUT
    Y : DWORD;
  END_VAR
  VAR
    last : UDINT;
    init : BOOL;
    tx : UDINT;
    Yi : REAL;
  END_VAR

  tx:= T_PLC_MS(en:=true);

  (* startup initialisation *)
  IF NOT init OR _T = t#0s THEN
  	init := TRUE;
  	Yi := DWORD_TO_REAL(X);
  ELSE
  	Yi := Yi + (DWORD_TO_REAL(X) - DWORD_TO_REAL(Y)) * UDINT_TO_REAL(tx - last) / TIME_TO_REAL(_T);
  END_IF;
  last := tx;

  Y := REAL_TO_DWORD(Yi);


  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS required *)
END_FUNCTION_BLOCK

FUNCTION RANGE_TO_WORD : WORD
  VAR_INPUT
    X : REAL;
    LOW : REAL;
    HIGH : REAL;
  END_VAR

  Range_to_Word := INT_TO_WORD(TRUNC((LIMIT(low,X,high)-low) * 65535.0 / (high - low)));

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION SCALE_X8 : REAL
  VAR_INPUT
    IN1 : BOOL;
    IN2 : BOOL;
    IN3 : BOOL;
    IN4 : BOOL;
    IN5 : BOOL;
    IN6 : BOOL;
    IN7 : BOOL;
    IN8 : BOOL;
    K : REAL;
    O : REAL;
    IN1_MIN : REAL;
    IN1_MAX : REAL;
    IN2_MIN : REAL;
    IN2_MAX : REAL;
    IN3_MIN : REAL;
    IN3_MAX : REAL;
    IN4_MIN : REAL;
    IN4_MAX : REAL;
    IN5_MIN : REAL;
    IN5_MAX : REAL;
    IN6_MIN : REAL;
    IN6_MAX : REAL;
    IN7_MIN : REAL;
    IN7_MAX : REAL;
    IN8_MIN : REAL;
    IN8_MAX : REAL;
  END_VAR

  SCALE_X8 := (SEL(IN1,IN1_MIN, IN1_MAX)+ SEL(IN2,IN2_MIN, IN2_MAX)+SEL(IN3,IN3_MIN, IN3_MAX)+ SEL(IN4,IN4_MIN, IN4_MAX)
  				+SEL(IN5,IN5_MIN, IN5_MAX)+ SEL(IN6,IN6_MIN, IN6_MAX)+SEL(IN7,IN7_MIN, IN7_MAX)+ SEL(IN8,IN8_MIN, IN8_MAX))*k + o;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

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

FUNCTION_BLOCK FILTER_MAV_DW
  VAR_INPUT
    X : DWORD;
    N : UINT;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    Y : DWORD;
  END_VAR
  VAR
    init : BOOL;
    buffer : ARRAY [0..31] OF DWORD;
    i : INT;
    tmp : INT;
  END_VAR

  N := MIN(N, UINT#32);

  (* startup initialisation *)
  IF NOT init OR rst OR N = UINT#0 THEN
  	init := TRUE;
  	tmp := UINT_TO_INT(N)-1;
  	FOR i := 0 TO tmp DO
  		buffer[i] := X;
  	END_FOR;
  	Y := X;
  ELSE
  	tmp := UINT_TO_INT(N);
  	i := INC1(i, tmp);
  	Y := UDINT_TO_DWORD(DWORD_TO_UDINT(Y) + (DWORD_TO_UDINT(X) - DWORD_TO_UDINT(buffer[i])) / UINT_TO_UDINT(N));
  	buffer[i] := X;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
  (* INC1 required *)
END_FUNCTION_BLOCK

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
    buf : ARRAY [0..31] OF REAL;
    i : INT;
    init : BOOL;
    stop : INT;
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

  (* From OSCAT Library, www.oscat.de *)
  (* INC1 required *)
END_FUNCTION_BLOCK

FUNCTION MIX : REAL
  VAR_INPUT
    A : REAL;
    B : REAL;
    M : REAL;
  END_VAR

  MIX := (1.0 - M) * A + M * B;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION BIT_OF_DWORD : BOOL
  VAR_INPUT
    IN : DWORD;
    N : INT;
  END_VAR

  BIT_OF_DWORD := (SHR(in,N) AND 16#00000001) > 0;

  (* From Oscat Library, www.oscat.de *)
END_FUNCTION

FUNCTION AIN : REAL
  VAR_INPUT
    IN : DWORD;
    BITS : BYTE;
    SIGN : BYTE;
    LOW : REAL;
    HIGH : REAL;
  END_VAR
  VAR
    temp1 : DWORD;
    temp2 : DWORD;
    sx : BOOL;
  END_VAR

  (* extract the sign bit *)
  IF sign < BYTE#32 THEN
  	temp1 := SHR(in, BYTE_TO_INT(sign));
  	sx := BIT_OF_DWORD(temp1,0); (* temp1.X0 *)
  ELSE
  	sx := FALSE;
  END_IF;
  temp1 := SHR(DWORD#16#FFFFFFFF,32 - BYTE_TO_INT(bits));
  temp2 := in AND temp1;
  AIN := (high - low)* DWORD_TO_REAL(temp2) / DWORD_TO_REAL(temp1) + low;
  IF sx THEN AIN := -AIN; END_IF;

  (* From OSCAT Library, www.oscat.de *)
  (* BIT_OF_DWORD requiered *)
END_FUNCTION

FUNCTION MUX_R4 : REAL
  VAR_INPUT
    IN0 : REAL;
    IN1 : REAL;
    IN2 : REAL;
    IN3 : REAL;
    A0 : BOOL;
    A1 : BOOL;
  END_VAR

  IF A1 THEN
  	MUX_R4 := SEL(A0, IN2, IN3);
  ELSE
  	MUX_R4 := SEL(A0, IN0, IN1);
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION BYTE_TO_RANGE : REAL
  VAR_INPUT
    X : BYTE;
    LOW : REAL;
    HIGH : REAL;
  END_VAR

  Byte_to_Range := (high - low) * BYTE_TO_REAL(X) / 255.0 + low;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION OFFSET_OSCAT : REAL
  VAR_INPUT
    X : REAL;
    O1 : BOOL;
    O2 : BOOL;
    O3 : BOOL;
    O4 : BOOL;
    _D : BOOL;
  END_VAR
  VAR
    OFFSET_1 : REAL;
    OFFSET_2 : REAL;
    OFFSET_3 : REAL;
    OFFSET_4 : REAL;
    Default : REAL;
  END_VAR

  IF _D THEN Offset_oscat := default; ELSE Offset_oscat := X; END_IF;
  IF O1 THEN Offset_oscat := Offset_oscat + offset_1; END_IF;
  IF O2 THEN Offset_oscat := Offset_oscat + offset_2; END_IF;
  IF O3 THEN Offset_oscat := Offset_oscat + offset_3; END_IF;
  IF O4 THEN Offset_oscat := Offset_oscat + offset_4; END_IF;

  (* From OSCAT Library, www.oscat.de *)
  (* Name changed to Offset_Oscat due to collision*)
END_FUNCTION

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

FUNCTION STAIR : REAL
  VAR_INPUT
    X : REAL;
    _D : REAL;
  END_VAR

  IF _D > 0.0 THEN
  	STAIR := DINT_TO_REAL(REAL_TO_DINT(X / _D)) * _D;
  ELSE
  	STAIR := X;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION _WORD_TO_DINT : DINT
  VAR_INPUT
    IN : WORD;
  END_VAR

  _WORD_TO_DINT := UINT_TO_DINT(WORD_TO_UINT(IN));

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK _RMP_W
  VAR_INPUT
    DIR : BOOL;
    _E : BOOL := TRUE;
    TR : TIME;
  END_VAR
  VAR_IN_OUT
    RMP : WORD;
  END_VAR
  VAR
    tx : UDINT;
    tl : UDINT;
    _step : DINT;
    init : BOOL;
    last_dir : BOOL;
  END_VAR

  tx := T_PLC_MS(en:=true);
  IF _E AND init THEN
  	(* we need to set tl = tx when direction changes *)
  	IF dir XOR last_dir THEN
  	 tl := tx;
  	 last_dir := dir;
  	END_IF;
  	(* check_elapsed time and calculate only if necessary *)
  	IF tr > t#0s THEN
  		_step := DWORD_TO_DINT(UDINT_TO_DWORD(DWORD_TO_UDINT(SHL(UDINT_TO_DWORD(tx-tl), 16)) / TIME_TO_UDINT(TR)));
  	ELSE
  		_step := DINT#65535;
  	END_IF;
  	IF _step > DINT#0 THEN
  		(* perform the step on the ramp *)
  		tl := tx;
  		(* calculate the step response *)
  		IF NOT dir THEN _step := - _step; END_IF;
  		rmp := DINT_TO_WORD(LIMIT(DINT#0, _WORD_TO_DINT(rmp) + _step, DINT#65535));
  	END_IF;
  ELSE
  	tl := tx;
  	init := TRUE;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS required, _WORD_TO_DINT required*)
END_FUNCTION_BLOCK

FUNCTION_BLOCK RMP_W
  VAR_INPUT
    SET : BOOL;
    PT : TIME;
    _E : BOOL := TRUE;
    UP : BOOL := TRUE;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    OUT : WORD;
    BUSY : BOOL;
    HIGH : BOOL;
    LOW : BOOL;
  END_VAR
  VAR
    rmp : _RMP_W;
  END_VAR

  rmp(dir := UP, _E := _E, TR := PT, rmp := out);
  out := rmp.RMP;

  (* set or reset operation *)
  IF RST THEN
  	out := WORD#0;
  ELSIF SET THEN
  	out := WORD#65535;
  END_IF;

  (* checks for outputs stable and reset or set busy flag *)
  low := out = WORD#0;
  high := out = WORD#65535;
  busy := NOT (low OR high) AND _E;

  (* From OSCAT Library, www.oscat.de *)
  (* _RMP_W required*)
END_FUNCTION_BLOCK

FUNCTION_BLOCK FILTER_W
  VAR_INPUT
    X : WORD;
    _T : TIME;
  END_VAR
  VAR_OUTPUT
    Y : WORD;
  END_VAR
  VAR
    last : UDINT;
    tx : UDINT;
    init : BOOL;
    tmp : DINT;
  END_VAR

  tx:= T_PLC_MS(en:=true);

  (* startup initialisation *)
  IF NOT init OR _T = T#0s THEN
  	init := TRUE;
  	last := tx;
  	Y := X;
  ELSIF Y = X THEN
  	last := tx;
  ELSE
  	tmp := UINT_TO_DINT(WORD_TO_UINT(X) - WORD_TO_UINT(Y)) * UDINT_TO_DINT(tx - last) / TIME_TO_DINT(_T);
  	IF tmp <> DINT#0 THEN
  		Y := DINT_TO_WORD(WORD_TO_DINT(Y) + tmp);
  		last := tx;
  	END_IF;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION RANGE_TO_BYTE : BYTE
  VAR_INPUT
    X : REAL;
    LOW : REAL;
    HIGH : REAL;
  END_VAR

  Range_to_Byte := INT_TO_BYTE(TRUNC((LIMIT(low,X,high)-low) * 255.0 / (high - low)));

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK SH
  VAR_INPUT
    IN : REAL;
    CLK : BOOL;
  END_VAR
  VAR_OUTPUT
    OUT : REAL;
    TRIG : BOOL;
  END_VAR
  VAR
    edge : BOOL;
  END_VAR

  IF clk AND NOT edge THEN
  	out := in;
  	trig := TRUE;
  ELSE
  	trig := FALSE;
  END_IF;
  edge := clk;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK FADE
  VAR_INPUT
    IN1 : REAL;
    IN2 : REAL;
    F : BOOL;
    TF : TIME;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    Y : REAL;
  END_VAR
  VAR
    rmx : RMP_W;
  END_VAR

  rmx(rst := rst AND NOT F, set := rst AND F, pt := TF, up := F);
  Y := (in2 - In1) / 65535.0 * WORD_TO_REAL(rmx.out) + in1;

  (* From OSCAT Library, www.oscat.de *)
  (* RMP_W required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK SEL2_OF_3
  VAR_INPUT
    IN1 : REAL;
    IN2 : REAL;
    IN3 : REAL;
    _D : REAL;
  END_VAR
  VAR_OUTPUT
    Y : REAL;
    W : INT;
    _E : BOOL;
  END_VAR
  VAR
    D12 : BOOL;
    D23 : BOOL;
    D31 : BOOL;
  END_VAR

  D12 := ABS(IN1-IN2) <= _D;
  D23 := ABS(IN2-IN3) <= _D;
  D31 := ABS(IN3-IN1) <= _D;

  IF (D12 AND D23) OR (D12 AND D31) OR (D23 AND D31) THEN
  	(* all 3 inputs are valid *)
  	Y := (IN1 + IN2 + IN3) * 0.333333333333;
  	_E := FALSE;
  	W := 0;
  ELSIF D12 THEN
  	(* only inut 1 and 2 are valid *)
  	Y := (In1 + IN2) * 0.5;
  	_E := FALSE;
  	W := 3;
  ELSIF D23 THEN
  	(* only inut 2 and 3 are valid *)
  	Y := (In2 + IN3) * 0.5;
  	_E := FALSE;
  	W := 1;
  ELSIF D31 THEN
  	(* only inut 3 and 1 are valid *)
  	Y := (In3 + IN1) * 0.5;
  	_E := FALSE;
  	W := 2;
  ELSE
  	(* no calculation possible *)
  	_E := TRUE;
  	W := 4;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION OVERRIDE : REAL
  VAR_INPUT
    X1 : REAL;
    X2 : REAL;
    X3 : REAL;
    E1 : BOOL;
    E2 : BOOL;
    E3 : BOOL;
  END_VAR

  IF E1 THEN OVERRIDE := X1; END_IF;
  IF E2 AND ABS(x2) > ABS(OVERRIDE) THEN OVERRIDE := X2; END_IF;
  IF E3 AND ABS(x3) > ABS(OVERRIDE) THEN OVERRIDE := X3; END_IF;
    
  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK SH_T
  VAR_INPUT
    IN : REAL;
    _E : BOOL;
  END_VAR
  VAR_OUTPUT
    OUT : REAL;
  END_VAR

  IF _E THEN out := in; END_IF;
    
  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION FLOOR : INT
  VAR_INPUT
    x : REAL;
  END_VAR

  FLOOR := REAL_TO_INT(X);
  IF INT_TO_REAL(FLOOR) > X THEN
  	floor := floor - 1;
  END_IF;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION_BLOCK STAIR2
  VAR_INPUT
    X : REAL;
    _D : REAL;
  END_VAR
  VAR_OUTPUT
    Y : REAL;
  END_VAR

  IF _D > 0.0 THEN
  	IF X >= Y + _D OR X <= Y - _D THEN Y := INT_TO_REAL(FLOOR(X/_D)) * _D; END_IF;
  ELSE
  	Y := X;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK FILTER_I
  VAR_INPUT
    X : INT;
    _T : TIME;
  END_VAR
  VAR_OUTPUT
    Y : INT;
  END_VAR
  VAR
    Yi : DINT;
    last : UDINT;
    tx : UDINT;
    init : BOOL;
  END_VAR

  tx:= T_PLC_MS(en:=true);

  (* startup initialisation *)
  IF NOT init OR _T = t#0s THEN
  	init := TRUE;
  	Yi := INT_TO_DINT(X) * DINT#1000;
  ELSE
  	(* to increase accuracy of the filter we calculate internal Yi wich is Y * 1000 *)
  	Yi := Yi + INT_TO_DINT(X - Y) * UDINT_TO_DINT(tx - last) * DINT#1000 / TIME_TO_DINT(_T);
  END_IF;
  last := tx;
  Y := DINT_TO_INT(yi / DINT#1000);

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS required *)
END_FUNCTION_BLOCK

FUNCTION SCALE_X2 : REAL
  VAR_INPUT
    IN1 : BOOL;
    IN2 : BOOL;
    K : REAL;
    O : REAL;
    IN1_MIN : REAL;
    IN1_MAX : REAL;
    IN2_MIN : REAL;
    IN2_MAX : REAL;
  END_VAR

  SCALE_X2 := (SEL(IN1,IN1_MIN, IN1_MAX)+ SEL(IN2,IN2_MIN, IN2_MAX))* k + o;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK SH_1
  VAR_INPUT
    IN : REAL;
    PT : TIME;
  END_VAR
  VAR_OUTPUT
    OUT : REAL;
    TRIG : BOOL;
  END_VAR
  VAR
    last : TIME;
    tx : TIME;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));

  IF tx - last >= PT THEN
  	last := tx;
  	out := in;
  	trig := TRUE;
  ELSE
  	trig := FALSE;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS required *)
END_FUNCTION_BLOCK

FUNCTION EVEN : BOOL
  VAR_INPUT
    IN : DINT;
  END_VAR

  even := NOT BIT_OF_DWORD(DINT_TO_DWORD(in),0);
  (* from OSCAT library; www.oscat.de  *)
  (* BIT_OF_DWORD required *)
END_FUNCTION

FUNCTION_BLOCK SH_2
  VAR_INPUT
    IN : REAL;
    PT : TIME;
    N : INT := 16;
    DISC : INT;
  END_VAR
  VAR_OUTPUT
    OUT : REAL;
    TRIG : BOOL;
    AVG : REAL;
    HIGH : REAL;
    LOW : REAL;
  END_VAR
  VAR
    M : INT;
    buf : ARRAY [0..15] OF REAL;
    buf2 : ARRAY [0..15] OF REAL;
    last : TIME;
    i : INT;
    i2 : INT;
    start : INT;
    temp : REAL;
    stop : INT;
    tx : TIME;
    d2 : INT;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));
  d2 := WORD_TO_INT(SHR(INT_TO_WORD(disc),1));

  IF tx - last >= PT THEN
  	last := tx;
  	trig := TRUE;

  	(* limit M to 0..16 *)
  	M := LIMIT(1,N,16);

  	(* edge detected lets take the sample *)
      i := M-1;
      WHILE (i>=1) DO
        i2 := i-1;
        buf2[i] := buf2[i2];
        i:=i-1;
      END_WHILE;

  	buf2[0] := in;
  	out := in;
  	buf := buf2;

  	(* sort the ARRAY lowest value AT 0 *)
  	FOR start := 0 TO M - 2 DO
  		FOR i := start+1 TO M - 1 DO
  			IF buf[start] > buf[i] THEN
  				temp := buf[start];
  				buf[start] := buf[i];
  				buf[i] := temp;
  			END_IF;
  		END_FOR;
  	END_FOR;

  	(* any calculation with the samples is here *)
  	stop := M - 1 - d2;
  	start := d2;
  	IF NOT even(INT_TO_DINT(disc)) THEN start := start + 1; END_IF;
  	avg := 0.0;
  	FOR i := start TO stop DO avg := avg + buf[i]; END_FOR;
  	avg := avg / INT_TO_REAL(stop - start +1);
  	low := buf[start];
  	high := buf[stop];
  ELSE
  	Trig := FALSE;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS and EVEN required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK DELAY_4
  VAR_INPUT
    IN : REAL;
  END_VAR
  VAR_OUTPUT
    OUT1 : REAL;
    OUT2 : REAL;
    OUT3 : REAL;
    OUT4 : REAL;
    temp : REAL;
  END_VAR

  out4 := out3;
  out3 := out2;
  out2 := out1;
  out1 := temp;
  temp := in;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION SCALE_B2 : REAL
  VAR_INPUT
    IN1 : BYTE;
    IN2 : BYTE;
    K : REAL;
    O : REAL;
    IN1_MIN : REAL;
    IN1_MAX : REAL;
    IN2_MIN : REAL;
    IN2_MAX : REAL;
  END_VAR

  SCALE_B2 := 	(((in1_max - in1_min)* BYTE_TO_REAL(in1) + (in2_max - in2_min)* BYTE_TO_REAL(in2)) * 0.003921569 + in1_min + in2_min) * K + O;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION SCALE_B4 : REAL
  VAR_INPUT
    IN1 : BYTE;
    IN2 : BYTE;
    IN3 : BYTE;
    IN4 : BYTE;
    K : REAL;
    O : REAL;
    IN1_MIN : REAL;
    IN1_MAX : REAL;
    IN2_MIN : REAL;
    IN2_MAX : REAL;
    IN3_MIN : REAL;
    IN3_MAX : REAL;
    IN4_MIN : REAL;
    IN4_MAX : REAL;
  END_VAR

  SCALE_B4 := 	(((in1_max - in1_min)* BYTE_TO_REAL(in1) + (in2_max - in2_min)* BYTE_TO_REAL(in2) + (in3_max - in3_min)* BYTE_TO_REAL(in3) + (in4_max - in4_min)* BYTE_TO_REAL(in4))* 0.003921569 + in1_min + in2_min + in3_min + in4_min) * K + O;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK TREND
  VAR_INPUT
    X : REAL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
    TU : BOOL;
    TD : BOOL;
    _D : REAL;
  END_VAR
  VAR
    last_x : REAL;
  END_VAR

  TU := X > last_X;
  TD := X < last_X;
  Q := TU OR TD;
  _D := X - LAST_X;

  last_X := X;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION SCALE_B8 : REAL
  VAR_INPUT
    IN1 : BYTE;
    IN2 : BYTE;
    IN3 : BYTE;
    IN4 : BYTE;
    IN5 : BYTE;
    IN6 : BYTE;
    IN7 : BYTE;
    IN8 : BYTE;
    K : REAL;
    O : REAL;
    IN1_MIN : REAL;
    IN1_MAX : REAL;
    IN2_MIN : REAL;
    IN2_MAX : REAL;
    IN3_MIN : REAL;
    IN3_MAX : REAL;
    IN4_MIN : REAL;
    IN4_MAX : REAL;
    IN5_MIN : REAL;
    IN5_MAX : REAL;
    IN6_MIN : REAL;
    IN6_MAX : REAL;
    IN7_MIN : REAL;
    IN7_MAX : REAL;
    IN8_MIN : REAL;
    IN8_MAX : REAL;
  END_VAR

  SCALE_B8 := 	(((in1_max - in1_min)* BYTE_TO_REAL(in1) + (in2_max - in2_min)* BYTE_TO_REAL(in2) + (in3_max - in3_min)* BYTE_TO_REAL(in3) + (in4_max - in4_min)* BYTE_TO_REAL(in4) +
  				(in5_max - in5_min)* BYTE_TO_REAL(in5) + (in6_max - in6_min)* BYTE_TO_REAL(in6) + (in7_max - in7_min)* BYTE_TO_REAL(in7) + (in8_max - in8_min)* BYTE_TO_REAL(in8)) * 0.003921569
  				 + in1_min + in2_min + in3_min + in4_min + in5_min + in6_min + in7_min + in8_min) * K + O;


  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION AOUT1 : DWORD
  VAR_INPUT
    IN : REAL;
    BIT_0 : INT;
    BIT_N : INT;
    SIGN : INT;
    LOW : REAL;
    HIGH : REAL;
    in2 : REAL;
    sx : BOOL;
  END_VAR

  (* if sign bit is defined *)

  IF sign < 32 THEN
  	sx := sign_R(in);
  	in2 := ABS(in);
  ELSE
      sx := FALSE;
  	in2 := in;
  END_IF;

  (* begrenze in auf die zulässigen werte *)
  in2 := LIMIT(low, in2, high);

  (* Berechne den Ausgangswert *)
  AOUT1 :=  SHL(REAL_TO_DWORD((in2 - low) / (high - low) * UDINT_TO_REAL(DWORD_TO_UDINT(SHL(DWORD#2#1,bit_n - Bit_0 + 1)) - UDINT#1)),Bit_0);

  IF sx THEN AOUT1 := SHL(DWORD#2#1,sign) OR AOUT1; END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION SCALE_B : REAL
  VAR_INPUT
    X : BYTE;
    I_LO : BYTE;
    I_HI : BYTE;
    O_LO : REAL;
    O_HI : REAL;
  END_VAR

  IF I_HI = I_LO THEN
  	SCALE_B := O_LO;
  ELSE
  	SCALE_B := (O_HI - O_LO) / USINT_TO_REAL(BYTE_TO_USINT(I_HI) - BYTE_TO_USINT(I_LO)) * BYTE_TO_REAL(LIMIT(I_LO,X,I_HI));
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION SCALE_D : REAL
  VAR_INPUT
    X : DWORD;
    I_LO : DWORD;
    I_HI : DWORD;
    O_LO : REAL;
    O_HI : REAL;
  END_VAR

  IF I_HI = I_LO THEN
  	SCALE_D := O_LO;
  ELSE
  	SCALE_D := (O_HI - O_LO) / UDINT_TO_REAL(DWORD_TO_UDINT(I_HI) - DWORD_TO_UDINT(I_LO)) * UDINT_TO_REAL(LIMIT(DWORD_TO_UDINT(I_LO),DWORD_TO_UDINT(X),DWORD_TO_UDINT(I_HI)) - DWORD_TO_UDINT(I_LO)) + O_LO;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK SEL2_OF_3B
  VAR_INPUT
    IN1 : BOOL;
    IN2 : BOOL;
    IN3 : BOOL;
    TD : TIME;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
    W : BOOL;
  END_VAR
  VAR
    TDEL : TON;
  END_VAR

  Q := (IN1 AND IN2) OR (IN1 AND IN3) OR (IN2 AND IN3);
  TDEL(IN := (in1 XOR in2) OR (in1 XOR in3) OR (in2 XOR in3), PT := TD);
  W := TDEL.Q;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK FILTER_MAV_W
  VAR_INPUT
    X : WORD;
    N : UINT;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    Y : WORD;
  END_VAR
  VAR
    init : BOOL;
    buffer : ARRAY [0..31] OF WORD;
    i : INT;
    sum : UDINT;
    tmp : INT;
  END_VAR

  N := MIN(N, UINT#32);

  (* startup initialisation *)
  IF NOT init OR rst OR N = UINT#0 THEN
  	init := TRUE;
  	tmp := UINT_TO_INT(N) - 1;
  	FOR i := 1 TO tmp DO
  		buffer[i] := X;
  	END_FOR;
  	sum := UINT_TO_UDINT(WORD_TO_UINT(Y) * N);
  	Y := X;
  ELSE
  	tmp := UINT_TO_INT(N);
  	i := INC1(i, tmp);
  	sum := sum + WORD_TO_UDINT(X) - WORD_TO_UDINT(buffer[i]);
  	Y := UDINT_TO_WORD(sum / UINT_TO_UDINT(N));
  	buffer[i] := X;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
  (* INC1 required *)
END_FUNCTION_BLOCK

FUNCTION SCALE_R : REAL
  VAR_INPUT
    X : REAL;
    I_LO : REAL;
    I_HI : REAL;
    O_LO : REAL;
    O_HI : REAL;
  END_VAR

  IF I_LO = I_HI THEN
  	SCALE_R := O_LO;
  ELSE
  	SCALE_R := (O_HI - O_LO) / (I_HI - I_LO) * (LIMIT(I_LO, X, I_HI) - I_LO) + O_LO;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION MUX_R2 : REAL
  VAR_INPUT
    IN0 : REAL;
    IN1 : REAL;
    A : BOOL;
  END_VAR

  MUX_R2 := SEL(A, IN0, IN1);

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK TREND_DW
  VAR_INPUT
    X : DWORD;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
    TU : BOOL;
    TD : BOOL;
    _D : DWORD;
  END_VAR
  VAR
    last_x : DWORD;
  END_VAR

  IF X > last_X THEN
  	TU := TRUE;
  	TD := FALSE;
  	_D := UDINT_TO_DWORD(DWORD_TO_UDINT(X) - DWORD_TO_UDINT(last_X));
  	Q := TRUE;
  ELSIF X < last_X THEN
  	TD := TRUE;
  	TU := FALSE;
  	_D := UDINT_TO_DWORD(DWORD_TO_UDINT(last_X) - DWORD_TO_UDINT(X));
  	Q := FALSE;
  ELSE
  	TU := FALSE;
  	TD := FALSE;
  	_D := DWORD#0;
  END_IF;
  last_X := X;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION DEC1 : INT
  VAR_INPUT
    x : INT;
    n : INT;
  END_VAR

  IF X = 0 THEN
  	DEC1 := N - 1;
  ELSE
  	DEC1 := X - 1;
  END_IF;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION_BLOCK FILTER_WAV
  VAR_INPUT
    X : REAL;
    W : ARRAY [0..15] OF REAL;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    Y : REAL;
  END_VAR
  VAR
    init : BOOL;
    buffer : ARRAY [0..15] OF REAL;
    i : INT;
    n : INT;
  END_VAR

  (* startup initialisation *)
  IF NOT init OR rst THEN
  	init := TRUE;
  	FOR i := 0 TO 15 DO
  		buffer[i] := X;
  	END_FOR;
  	i := 15;
  	Y := X;
  ELSE
  	i := INC1(i, 16);
  	buffer[i] := X;
  END_IF;

  (* calculate the weighted average *)
  Y := 0.0;
  FOR n := 0 TO 15 DO
  	Y := buffer[i] * W[n] + Y;
  	i := DEC1(i, 16);
  END_FOR;

  (* From OSCAT Library, www.oscat.de *)
  (* DEC1 required *)
END_FUNCTION_BLOCK


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
