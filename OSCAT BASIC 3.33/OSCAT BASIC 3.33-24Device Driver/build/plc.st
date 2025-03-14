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
  OSCAT_PARSET_X : ARRAY [1..4] OF REAL;
  OSCAT_PARSET : ARRAY [0..3] OF OSCAT_PARSET_X;
END_TYPE

FUNCTION BIT_LOAD_B : BYTE
  VAR_INPUT
    IN : BYTE;
    VAL : BOOL;
    POS : INT;
  END_VAR

  IF VAL THEN
  	BIT_LOAD_B := in OR SHL(BYTE#1,pos);
  ELSE
  	BIT_LOAD_B := in AND (NOT SHL(BYTE#1,pos));
  END_IF;

  (*From OSCAT Library, www.oscat.de*)
END_FUNCTION

FUNCTION_BLOCK INTERLOCK_4
  VAR_INPUT
    I0 : BOOL;
    I1 : BOOL;
    I2 : BOOL;
    I3 : BOOL;
    _E : BOOL;
    MODE : INT;
  END_VAR
  VAR_OUTPUT
    OUT : BYTE;
    _TP : BOOL;
  END_VAR
  VAR
    in : BYTE;
    last : BYTE;
    old : BYTE;
    lmode : INT;
  END_VAR

  (* check if enable is active *)
  IF _E THEN
  (* reset all vars when there is a mode change on thy fly *)
  	IF mode <> lmode THEN
  		out := BYTE#0;
  		last := BYTE#0;
  		old := BYTE#0;
  		lmode := mode;
  	END_IF;
  	(* load inputs into in *)
  	in:=BIT_LOAD_B(in,I0,0); (* in.0 *)
  	in:=BIT_LOAD_B(in,I1,1); (* in.1 *)
  	in:=BIT_LOAD_B(in,I2,2); (* in.2 *)
  	in:=BIT_LOAD_B(in,I3,3); (* in.3 *)
  	(* only execute when there is any change *)
  	IF in <> last THEN
  		(* only execute when inputs have chages state *)
  		CASE mode OF
  			0:	(* output directly display inputs as bits in byte out *)
  				out := in;

  			1:	(* the input with the highest number will be acepted *)
  				IF    (in AND BYTE#2#00001000) > BYTE#0 (* in.3 *) THEN out := BYTE#8;
  				ELSIF (in AND BYTE#2#00000100) > BYTE#0 (* in.2 *) THEN out := BYTE#4;
  				ELSIF (in AND BYTE#2#00000010) > BYTE#0 (* in.1 *) THEN out := BYTE#2;
  				ELSE out := in;
  				END_IF;

  			2:	(* input last pressed will be displayed only *)
  				last := ((in XOR last) AND in);
  				IF    (last AND BYTE#2#00001000) > BYTE#0 (* last.3 *) THEN out := BYTE#8;
  				ELSIF (last AND BYTE#2#00000100) > BYTE#0 (* last.2 *) THEN out := BYTE#4;
  				ELSIF (last AND BYTE#2#00000010) > BYTE#0 (* last.1 *) THEN out := BYTE#2;
  				ELSE out := last;
  				END_IF;

  			3:	(* any input active will disable all other inputs *)
  				IF (out AND in) = BYTE#0 THEN
  					IF    (in AND BYTE#2#00001000) > BYTE#0 (* in.3 *) THEN out := BYTE#8;
  					ELSIF (in AND BYTE#2#00000100) > BYTE#0 (* in.2 *) THEN out := BYTE#4;
  					ELSIF (in AND BYTE#2#00000010) > BYTE#0 (* in.1 *) THEN out := BYTE#2;
  					ELSE out := in;
  					END_IF;
  				END_IF;

  		END_CASE;
  		last := in;
  	END_IF;
  	_tp := out <> old;
  	old := out;
  ELSE
  	out := BYTE#0;
  	last := BYTE#0;
  	old := BYTE#0;
  	lmode := 0;
  	_tp := FALSE;
  END_IF;

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION BIT_OF_DWORD : BOOL
  VAR_INPUT
    IN : DWORD;
    N : INT;
  END_VAR

  BIT_OF_DWORD := (SHR(in,N) AND 16#00000001) > 0;

  (* From Oscat Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK INC_DEC
  VAR_INPUT
    CHA : BOOL;
    CHB : BOOL;
    RST : BOOL := 0;
  END_VAR
  VAR_OUTPUT
    DIR : BOOL;
    CNT : INT;
  END_VAR
  VAR
    edgea : BOOL := 0;
    clk : BOOL;
    clka : BOOL;
    clkb : BOOL;
    edgeb : BOOL;
    axb : BOOL;
  END_VAR

  axb := cha XOR chb;

  (* create pulses for channel a *)
  clka := cha XOR edgea;
  edgea := cha;

  clkb := chb XOR edgeb;
  edgeb := chb;

  (* create pulses for both channels *)
  clk := clka OR clkb;

  (* set the direction output *)
  IF axb AND clka THEN dir := TRUE; END_IF;
  IF axb AND clkb THEN dir := FALSE; END_IF;

  (* increment or decrement the counter *)
  IF clk AND dir THEN cnt := cnt + 1; END_IF;
  IF clk AND NOT dir THEN cnt := cnt -1; END_IF;

  (* reset the counter if rst active *)
  IF rst THEN cnt := 0; END_IF;

  (*From OSCAT Library, www.oscat.de *)
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

FUNCTION _BYTE_TO_INT : INT
  VAR_INPUT
    IN : BYTE;
  END_VAR

  _BYTE_TO_INT := USINT_TO_INT(BYTE_TO_USINT(IN));

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK SIGNAL
  VAR_INPUT
    IN : BOOL;
    SIG : BYTE;
    TS : TIME;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
  END_VAR
  VAR
    tx : DWORD;
    _step : BYTE;
  END_VAR

  IF in THEN
  	(* an alarm is present read system time first *)
      tx:= UDINT_TO_DWORD(T_PLC_MS(en:=true));

  	(* calculate the step counter which is the lowest 3 bits of (time / ts) *)
  	IF ts > t#0s THEN
  		_step := DWORD_TO_BYTE(UDINT_TO_DWORD(DWORD_TO_UDINT(tx) / TIME_TO_UDINT(ts)) AND DWORD#16#0000_0007);
  	ELSE
  		_step := DWORD_TO_BYTE(SHR(tx,7) AND DWORD#16#0000_0007);
  	END_IF;
  	(* convert the value 0-7 in step into one bit only (bit 0-7) *)
  	_step := SHL(BYTE#1,_BYTE_TO_INT(_step));
  	(* generate the output signal *)
  	Q := (_step AND sig) > BYTE#0;
  ELSE
  	Q := FALSE;
  END_IF;

  (*From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK SIGNAL_4
  VAR_INPUT
    IN1 : BOOL;
    IN2 : BOOL;
    IN3 : BOOL;
    IN4 : BOOL;
    TS : TIME;
    S1 : BYTE := 2#1111_1111;
    S2 : BYTE := 2#1111_0000;
    S3 : BYTE := 2#1010_1010;
    S4 : BYTE := 2#1010_0000;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
  END_VAR
  VAR
    sig : SIGNAL;
  END_VAR

  IF in1 THEN
  	sig(in := TRUE, sig := s1, TS := TS);
  ELSIF in2 THEN
  	sig(in := TRUE, sig := s2, TS := TS);
  ELSIF in3 THEN
  	sig(in := TRUE, sig := s3, TS := TS);
  ELSIF in4 THEN
  	sig(in := TRUE, sig := s4, TS := TS);
  ELSE
  	sig(in := FALSE);
  END_IF;

  (* set the output *)
  Q := sig.Q;

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK INTERLOCK
  VAR_INPUT
    I1 : BOOL;
    I2 : BOOL;
    TL : TIME;
  END_VAR
  VAR_OUTPUT
    Q1 : BOOL;
    Q2 : BOOL;
  END_VAR
  VAR
    T1 : TOF;
    T2 : TOF;
  END_VAR

  (* the input signal have a run delay to lockout the other input *)
  T1(IN := I1, PT := TL);
  T2(IN := I2, PT := TL);

  Q1 := I1 AND NOT t2.Q;
  Q2 := I2 AND NOT t1.Q;

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION T_PLC_US : UDINT
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

  {extern unsigned long __tick;
  extern unsigned long long common_ticktime__;
  unsigned long long ticktime_ms = (common_ticktime__)/1000000;
  UDINT plc_time = (UDINT)(ticktime_ms * (unsigned long long)__tick);
  TX = plc_time}

  T_PLC_US := tx*1000;
  IF debug THEN
  	T_PLC_US := (DWORD_TO_UDINT(SHL(UDINT_TO_DWORD(T_PLC_US),N) OR SHL(temp,N))-1) + OFFSET;
  END_IF;

  (* Original Code:
  tx := TIME();
  T_PLC_US := TIME_TO_DWORD(Tx)*1000;
  IF debug THEN
  	T_PLC_US := (SHL(T_PLC_US,N) OR SHL(DWORD#1,N)-1) + OFFSET;
  END_IF;
  *)

  (* From OSCAT library, www.oscat.de

  this is a temporary T_PLC_US FB until OpenPLC gets it´s own time() functionality *)

  (* PLC_TIME and Global variables PLC_SCAN_CYCL and PLC_CYCL_TIME required *)
END_FUNCTION

FUNCTION_BLOCK TC_S
  VAR_OUTPUT
    TC : REAL;
  END_VAR
  VAR
    init : BOOL;
    tx : UDINT;
    last : UDINT;
  END_VAR

  tx:= T_PLC_US(en:=true);

  IF NOT init THEN
  	init := TRUE;
  	TC := 0.0;
  ELSE
  	tc := UDINT_TO_REAL(tx - last) * 1.0E-6;
  END_IF;
  last := tx;

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS, R2_ADD required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK SRAMP
  VAR_INPUT
    X : REAL;
    A_UP : REAL;
    A_DN : REAL;
    VU_MAX : REAL;
    VD_MAX : REAL;
    LIMIT_HIGH : REAL;
    LIMIT_LOW : REAL;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    Y : REAL;
    V : REAL;
  END_VAR
  VAR
    cycle_time : TC_S;
    init : BOOL;
  END_VAR

  cycle_time();

  (* assure range of inputs *)
  A_up := MAX(0.0,A_UP);
  A_dn := MIN(0.0,A_dn);
  VU_max := MAX(0.0,VU_max);
  VD_max := MIN(0.0,VD_MAX);

  (* calculate the output offset *)
  IF rst OR NOT init THEN
  	init := TRUE;
  	Y := 0.0;
  	V := 0.0;
  ELSIF X = Y THEN
  	v := 0.0;
  ELSIF X > Y THEN
  	(* output is too low >> ramp up and brake at the end *)
  	(* accelerate the speed and limit to vu_max *)
  	v := MIN(v + A_UP * cycle_time.TC, vu_max);
  	(* calculate the max speed to be able to brake and select the lowest *)
  	v := MIN(SQRT((Y-X) * 2.0 * A_DN), v);
  	(* calculate the output and obey limits *)
  	y := LIMIT(limit_low, y + MIN(v * cycle_time.TC, X-Y), limit_high);
  ELSIF X < Y THEN
  	(* output is too high >> ramp dn and brake at the end *)
  	(* accelerate the speed and limit to vd_max *)
  	v := MAX(v + A_DN * cycle_time.TC, vd_max);
  	(* calculate the max speed to be able to brake and select the lowest *)
  	v := MAX(-SQRT((Y-X) * 2.0 * A_UP), v);
  	(* calculate the output and obey limits *)
  	y := LIMIT(limit_low, y + MAX(v * cycle_time.TC, X-Y), limit_high);
  END_IF;

  (*From OSCAT Library, www.oscat.de *)
  (* TC_S required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK TUNE2
  VAR_INPUT
    SET : BOOL;
    SU : BOOL;
    SD : BOOL;
    FU : BOOL;
    FD : BOOL;
    RST : BOOL;
    SS : REAL := 0.1;
    FS : REAL := 5.0;
    LIMIT_L : REAL;
    LIMIT_H : REAL := 100.0;
    RST_VAL : REAL;
    SET_VAL : REAL := 100.0;
    TR : TIME := t#500ms;
    S1 : REAL := 2.0;
    S2 : REAL := 10.0;
    Y : REAL;
  END_VAR
  VAR
    tx : UDINT;
    start : UDINT;
    state : INT;
    in : BOOL;
    _step : REAL;
    speed : REAL;
    y_start : REAL;
  END_VAR

  tx:= T_PLC_MS(en:=true);

  IF rst THEN
  	Y := RST_val;
  	state := 0;
  ELSIF set THEN
  	Y := SET_val;
  	state := 0;
  ELSIF state > 0 THEN
  	(* key has been pushed state machine operating *)
  	(* first read the correct input *)
  	CASE state OF
  		1 :	(* slow up *)
  			in := su;
  		2 :	(* slow down *)
  			in := sd;
  		3 :	(* fast up *)
  			in := fu;
  		4 :	(* fast down *)
  			in := fd;
  	END_CASE;
  	(* check for single step operation *)
  	IF NOT in AND tx - start <= TIME_TO_UDINT(TR) THEN
  		Y := Y_start + _step;
  		state := 0;
  	(* check if ramp needs to be generated *)
  	ELSIF in AND tx - start >= TIME_TO_UDINT(TR) THEN
  		Y := Y_start + UDINT_TO_REAL(tx - start - TIME_TO_UDINT(TR)) * speed;
  	ELSIF NOT in THEN
  		state := 0;
  	END_IF;
  ELSIF su THEN
  	(* slow step up *)
  	state := 1;
  	start := tx;
  	_step := ss;
  	speed := s1 * 1.0E-3;
  	Y_start := Y;
  ELSIF sd THEN
  	(* slow step down *)
  	state := 2;
  	start := tx;
  	_step := -ss;
  	speed := -s1 * 1.0E-3;
  	Y_start := Y;
  ELSIF fu THEN
  	(* fast step up *)
  	state := 3;
  	start := tx;
  	_step := fs;
  	speed := s2 * 1.0E-3;
  	y_start := Y;
  ELSIF fd THEN
  	(* fast step down *)
  	state := 4;
  	start := tx;
  	_step := -fs;
  	speed := -s2 * 1.0E-3;
  	y_start := Y;
  END_IF;

  (* make sure output does not exceed limits *)
  Y := LIMIT(LIMIT_L, Y, LIMIT_H);


  (*From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK FT_PROFILE
  VAR_INPUT
    K : REAL := 1.0;
    O : REAL := 0.0;
    M : REAL := 1.0;
    _E : BOOL;
    VALUE_0 : REAL;
    VALUE_1 : REAL;
    VALUE_2 : REAL;
    VALUE_3 : REAL;
    VALUE_10 : REAL;
    VALUE_11 : REAL;
    VALUE_12 : REAL;
    VALUE_13 : REAL;
    TIME_1 : TIME;
    TIME_2 : TIME;
    TIME_3 : TIME;
    TIME_10 : TIME;
    TIME_11 : TIME;
    TIME_12 : TIME;
    TIME_13 : TIME;
  END_VAR
  VAR_OUTPUT
    Y : REAL;
    RUN : BOOL;
    ET : TIME;
  END_VAR
  VAR
    tx : TIME;
    edge : BOOL;
    state : INT;
    ta : TIME;
    tb : TIME;
    t0 : TIME;
    temp : REAL;
    va : REAL;
    vb : REAL;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));

  (* determine start condition *)
  IF _E AND NOT edge THEN
  	RUN := TRUE;
  	ET := t#0s;
  	t0 := tx;
  	ta := tx;
  	tb := multime(time_1, M);
  	va := value_0;
  	vb := value_1;
  	temp := value_0;
  	state := 1;
  END_IF;
  edge := _E;

  (* generate startup profile *)
  IF run THEN
  	CASE state OF
  		1:	IF tx - ta >= tb THEN
  				ta := ta + tb;
  				tb := multime(time_2 - time_1, M);
  				va := value_1;
  				vb := value_2;
  				temp := value_1;
  				state := 2;
  			ELSE
  				temp := ((vb - va) * TIME_TO_REAL(tx - ta) / TIME_TO_REAL(tb) + va);
  			END_IF;
  		2:	IF tx - ta >= tb THEN
  				ta := ta + tb;
  				tb := multime(time_3 - time_2, M);
  				va := value_2;
  				vb := value_3;
  				temp := value_2;
  				state := 3;
  			ELSE
  				temp := ((vb - va) * TIME_TO_REAL(tx - ta) / TIME_TO_REAL(tb) + va);
  			END_IF;
  		3:	IF tx - ta >= tb THEN
  				ta := ta + tb;
  				tb := multime(time_10 - time_3, M);
  				va := value_3;
  				vb := value_10;
  				temp := value_3;
  				state := 4;
  			ELSE
  				temp := ((vb - va) * TIME_TO_REAL(tx - ta) / TIME_TO_REAL(tb) + va);
  			END_IF;
  		4 :	IF tx - ta >= tb THEN
  				ta := ta + tb;
  				tb := multime(time_11 - time_10, M);
  				va := value_10;
  				vb := value_11;
  				temp := value_10;
  				IF _E THEN state := 5; ELSE state := 6; END_IF;
  			ELSE
  				temp := ((vb - va) * TIME_TO_REAL(tx - ta) / TIME_TO_REAL(tb) + va);
  			END_IF;
  		5:	(* extend the signal while E is true *)
  			IF _E THEN
  				ta := tx;
  			ELSE
  				state := 6;
  			END_IF;
  		6:	IF tx - ta >= tb THEN
  				ta := ta + tb;
  				tb := multime(time_12 - time_11, M);
  				va := value_11;
  				vb := value_12;
  				temp := value_11;
  				state := 7;
  			ELSE
  				temp := ((vb - va) * TIME_TO_REAL(tx - ta) / TIME_TO_REAL(tb) + va);
  			END_IF;
  		7:	IF tx - ta >= tb THEN
  				ta := ta + tb;
  				tb := multime(time_13 - time_12, M);
  				va := value_12;
  				vb := value_13;
  				temp := value_12;
  				state := 8;
  			ELSE
  				temp := ((vb - va) * TIME_TO_REAL(tx - ta) / TIME_TO_REAL(tb) + va);
  			END_IF;
  		8:	IF tx - ta >= tb THEN
  				temp := value_13;
  				run := FALSE;
  			ELSE
  				temp := ((vb - va) * TIME_TO_REAL(tx - ta) / TIME_TO_REAL(tb) + va);
  			END_IF;
  	END_CASE;
  	Y := temp * K + O;
  	ET := tx - t0;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK TP_1D
  VAR_INPUT
    IN : BOOL;
    PT1 : TIME;
    PTD : TIME;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
    W : BOOL;
  END_VAR
  VAR
    tx : TIME;
    start : TIME;
    ix : BOOL;
  END_VAR

  tx := UDINT_TO_TIME(T_PLC_MS(en:=true));

  IF RST THEN
  	Q := FALSE;
  	rst := FALSE;
  	W := FALSE;
  ELSIF W THEN
  	IF tx - start >= PTD THEN
  		W := FALSE;
  	END_IF;
  ELSIF IN AND NOT ix THEN
  	Q := TRUE;
  	start := tx;
  	in := FALSE;
  ELSIF tx - start >= PT1 THEN
  	Q := FALSE;
  	W := TRUE;
  	start := tx;
  END_IF;

  ix := IN;

  (*From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK FLOW_CONTROL
  VAR_INPUT
    IN : BOOL;
    REQ : BOOL;
    ENQ : BOOL;
    RST : BOOL := FALSE;
    T_AUTO : TIME := t#1h;
    T_DELAY : TIME := t#23h;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
    STATUS : BYTE;
  END_VAR
  VAR
    timer : TP_1D;
  END_VAR

  STATUS := BYTE#100;
  IF RST THEN
  	Q := FALSE;
  	timer(rst := TRUE);
  	timer.RST := FALSE;
  	STATUS := BYTE#103;
  ELSIF ENQ THEN
  	IF IN THEN
  		status := BYTE#101;
  	END_IF;
  	IF REQ THEN
  		(* timer will generate a timed pulse after TP goes high *)
  		timer.PT1 := T_AUTO;
  		timer.PTD := T_DELAY;
  		timer.IN := TRUE;
  		STATUS := BYTE#102;
  	END_IF;
  END_IF;

  (* set output and run timer *)
  timer();
  timer.IN := FALSE;
  Q := (IN AND ENQ) OR timer.Q;

  (* From OSCAT Library, www.oscat.de *)
  (* TP_1D required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK MANUAL_2
  VAR_INPUT
    IN : BOOL;
    ENA : BOOL;
    _ON : BOOL;
    OFF : BOOL;
    MAN : BOOL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
    STATUS : BYTE;
    STATUS0 : BYTE;
  END_VAR

  IF ena THEN
  	IF NOT _ON AND NOT OFF THEN
  		Q := IN;
  		STATUS := BYTE#100;
  	ELSIF _on AND NOT off THEN
  		Q := TRUE;
  		STATUS := BYTE#101;
  	ELSIF NOT _on AND off THEN
  		q := FALSE;
  		STATUS := BYTE#102;
  	ELSE
  		Q := MAN;
  		STATUS := BYTE#103;
  	END_IF;
  ELSE
  	Q := FALSE;
  	STATUS := BYTE#104;
  END_IF;

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION MANUAL : BOOL
  VAR_INPUT
    IN : BOOL;
    _ON : BOOL;
    OFF : BOOL;
  END_VAR

  MANUAL := NOT OFF AND (IN OR _ON);

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK MANUAL_1
  VAR_INPUT
    IN : BOOL;
    MAN : BOOL;
    M_I : BOOL;
    SET : BOOL;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
    STATUS : BYTE;
  END_VAR
  VAR
    S_edge : BOOL;
    _R_edge : BOOL;
    edge : BOOL;
  END_VAR

  IF NOT man THEN
  	Q := IN;
  	STATUS := BYTE#100;
  	edge := FALSE;
  ELSIF NOT s_edge AND set THEN
  	Q := TRUE;
  	edge := TRUE;
  	status := BYTE#101;
  ELSIF NOT _r_edge AND rst THEN
  	Q := FALSE;
  	edge := TRUE;
  	status := BYTE#102;
  ELSIF NOT edge THEN
  	Q := M_I;
  	status := BYTE#103;
  END_IF;

  (* remember levels of manual signals *)
  s_edge := SET;
  _r_edge := RST;

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK TUNE
  VAR_INPUT
    SET : BOOL;
    SU : BOOL;
    SD : BOOL;
    RST : BOOL;
    SS : REAL := 0.1;
    LIMIT_L : REAL;
    LIMIT_H : REAL := 100.0;
    RST_VAL : REAL;
    SET_VAL : REAL := 100.0;
    T1 : TIME := t#500ms;
    T2 : TIME := t#2s;
    S1 : REAL := 2.0;
    S2 : REAL := 10.0;
    Y : REAL;
  END_VAR
  VAR
    tx : UDINT;
    start : UDINT;
    start2 : UDINT;
    state : INT;
    in : BOOL;
    _step : REAL;
    speed : REAL;
    y_start : REAL;
    y_start2 : REAL;
  END_VAR

  tx:= T_PLC_MS(en:=true);

  IF rst THEN
  	Y := RST_val;
  	state := 0;
  ELSIF set THEN
  	Y := SET_val;
  	state := 0;
  ELSIF state > 0 THEN
  	(* key has been pushed state machine operating *)
  	(* first read the correct input *)
  	IF state = 1 THEN
  		(* step up *)
  		in := su;
  	ELSE
  		(* step down *)
  		in := sd;
  	END_IF;
  	(* check for single step operation *)
  	IF NOT in AND tx - start <= TIME_TO_UDINT(T1) THEN
  		Y := Y_start + _step;
  		state := 0;
  	(* check if fast ramp needs to be generated *)
  	ELSIF in AND tx - start >= TIME_TO_UDINT(T2) THEN
  		Y := Y_start2 + UDINT_TO_REAL(tx - start2) * s2 / speed;
  	(* check if slow ramp needs to be generated *)
  	ELSIF in AND tx - start >= TIME_TO_UDINT(T1) THEN
  		Y := Y_start + UDINT_TO_REAL(tx - start - TIME_TO_UDINT(T1)) * S1 / speed;
  		start2 := tx;
  		Y_start2 := Y;
  	ELSIF NOT in THEN
  		state := 0;
  	END_IF;
  ELSIF su THEN
  	(* slow step up *)
  	state := 1;
  	start := tx;
  	_step := ss;
  	speed := 1000.0;
  	Y_start := Y;
  ELSIF sd THEN
  	(* slow step down *)
  	state := 2;
  	start := tx;
  	_step := -ss;
  	speed := -1000.0;
  	Y_start := Y;
  END_IF;

  (* make sure output does not exceed limits *)
  Y := LIMIT(LIMIT_L, Y, LIMIT_H);

  (*From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS required *)
END_FUNCTION_BLOCK

FUNCTION INC : INT
  VAR_INPUT
    X : INT;
    _D : INT;
    M : INT;
  END_VAR

  inc := (X + _D + M + 1) MOD (M + 1);
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION_BLOCK MANUAL_4
  VAR_INPUT
    I0 : BOOL;
    I1 : BOOL;
    I2 : BOOL;
    I3 : BOOL;
    MAN : BOOL;
    STP : BOOL;
    M0 : BOOL;
    M1 : BOOL;
    M2 : BOOL;
    M3 : BOOL;
  END_VAR
  VAR_OUTPUT
    Q0 : BOOL;
    Q1 : BOOL;
    Q2 : BOOL;
    Q3 : BOOL;
    STATUS : BYTE;
  END_VAR
  VAR
    edge : BOOL;
    pos : INT;
    tog : BOOL;
  END_VAR

  IF man THEN
  	IF NOT TOG THEN
  		Q0 := M0;
  		Q1 := M1;
  		Q2 := M2;
  		Q3 := M3;
  		STATUS := BYTE#101;
  	END_IF;
  	IF STP AND NOT edge THEN
  		tog := TRUE;
  		CASE pos OF
  			0:	Q0 := TRUE;
  				Q1 := FALSE;
  				Q2 := FALSE;
  				Q3 := FALSE;
  				STATUS := BYTE#110;
  			1:	Q0 := FALSE;
  				Q1 := TRUE;
  				Q2 := FALSE;
  				Q3 := FALSE;
  				STATUS := BYTE#111;
  			2:	Q0 := FALSE;
  				Q1 := FALSE;
  				Q2 := TRUE;
  				Q3 := FALSE;
  				STATUS := BYTE#112;
  			3:	Q0 := FALSE;
  				Q1 := FALSE;
  				Q2 := FALSE;
  				Q3 := TRUE;
  				STATUS := BYTE#113;
  		END_CASE;
  		pos := INC(pos,1,3);
  	END_IF;
  ELSE
  	Q0 := I0;
  	Q1 := I1;
  	Q2 := I2;
  	Q3 := I3;
  	STATUS := BYTE#100;
  	tog := FALSE;
  	pos := 0;
  END_IF;

  (* remember status of stp *)
  edge := STP;

  (*From OSCAT Library, www.oscat.de *)
  (* INC required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK DRIVER_4C
  VAR_INPUT
    IN : BOOL;
    RST : BOOL;
    TIMEOUT : TIME;
    SX : ARRAY [1..7] OF BYTE;
  END_VAR
  VAR_OUTPUT
    SN : INT;
    Q0 : BOOL;
    Q1 : BOOL;
    Q2 : BOOL;
    Q3 : BOOL;
  END_VAR
  VAR
    off : TON;
    edge : BOOL;
  END_VAR

  IF RST OR off.Q THEN
  	SN := 0;
  ELSIF IN AND NOT edge THEN
  	SN := SN + 1;
  	IF SN > 7 OR SX[SN] = BYTE#0 THEN SN := 0; END_IF;
  END_IF;
  edge := in;
  IF SN > 0 THEN
  	Q0 := (SX[SN] AND BYTE#1) > BYTE#0;
  	Q1 := (SX[SN] AND BYTE#2) > BYTE#0;
  	Q2 := (SX[SN] AND BYTE#4) > BYTE#0;
  	Q3 := (SX[SN] AND BYTE#8) > BYTE#0;
  ELSE
  	Q0 := FALSE;
  	Q1 := FALSE;
  	Q2 := FALSE;
  	Q3 := FALSE;
  END_IF;

  (* maximaum timeout *)
  IF timeout > t#0s THEN off(in := SN > 0, PT := Timeout); END_IF;
    
    (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK DRIVER_1
  VAR_INPUT
    SET : BOOL;
    IN : BOOL;
    RST : BOOL;
    TOGGLE_MODE : BOOL;
    TIMEOUT : TIME;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
  END_VAR
  VAR
    off : TON;
    edge : BOOL;
  END_VAR

  IF off.Q THEN Q := FALSE; END_IF;
  IF rst THEN
  	Q := FALSE;
  ELSIF set THEN
  	Q := TRUE;
  ELSIF IN AND NOT edge THEN
  	IF toggle_mode THEN q := NOT Q; ELSE q := TRUE; END_IF;
  END_IF;
  edge := in;
  IF timeout > t#0s THEN off(in := Q, PT := Timeout); END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK DRIVER_4
  VAR_INPUT
    SET : BOOL;
    IN0 : BOOL;
    IN1 : BOOL;
    IN2 : BOOL;
    IN3 : BOOL;
    RST : BOOL;
    TOGGLE_MODE : BOOL;
    TIMEOUT : TIME;
  END_VAR
  VAR_OUTPUT
    Q0 : BOOL;
    Q1 : BOOL;
    Q2 : BOOL;
    Q3 : BOOL;
  END_VAR
  VAR
    d0 : DRIVER_1;
    d1 : DRIVER_1;
    d2 : DRIVER_1;
    d3 : DRIVER_1;
  END_VAR

  D0(Set:=set, in:=in0, rst:=rst, toggle_mode:=toggle_mode, timeout:=timeout);
  D1(Set:=set, in:=in1, rst:=rst, toggle_mode:=toggle_mode, timeout:=timeout);
  D2(Set:=set, in:=in2, rst:=rst, toggle_mode:=toggle_mode, timeout:=timeout);
  D3(Set:=set, in:=in3, rst:=rst, toggle_mode:=toggle_mode, timeout:=timeout);
  Q0 := D0.Q;
  Q1 := D1.Q;
  Q2 := D2.Q;
  Q3 := D3.Q;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
