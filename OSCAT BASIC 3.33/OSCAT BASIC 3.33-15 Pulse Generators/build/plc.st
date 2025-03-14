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


FUNCTION_BLOCK TMIN
  VAR_INPUT
    IN : BOOL;
    PT : TIME;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
  END_VAR
  VAR
    pm : TP;
  END_VAR

  pm(in := IN, PT := PT);
  Q := IN OR pm.Q;

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK ClICK_CNT
  VAR_INPUT
    IN : BOOL;
    N : INT;
    TC : TIME;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
  END_VAR
  VAR
    tx : TP;
    edge : BOOL;
    cnt : INT := -1;
  END_VAR

  (* Q shall only be active for one cycle only *)
  Q := FALSE;

  IF in AND NOT edge AND NOT tx.q THEN
  	(* a rising edge on in sets the counter to 0 *)
  	cnt := 0;
  ELSIF tx.Q AND NOT IN AND edge THEN
  	(* count falling edges when tp.q is true *)
  	cnt := cnt + 1;
  ELSIF NOT tx.Q THEN
  	Q := cnt=N;
  	cnt := -1;
  END_IF;

  (* remember the status of IN *)
  edge := IN;
  tx(in := IN, pt := TC);

  (* From OSCAT Library, www.oscat.de *)
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

FUNCTION_BLOCK TP_X
  VAR_INPUT
    IN : BOOL;
    PT : TIME;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
    ET : TIME;
  END_VAR
  VAR
    edge : BOOL;
    start : TIME;
    tx : TIME;
  END_VAR

  tx := UDINT_TO_TIME(T_PLC_MS(en:=true));

  (* rising edge trigger *)
  IF IN AND NOT edge THEN
  	start := tx;
  	Q := PT > t#0ms;
  ELSIF Q THEN
  	ET := tx - start;
  	IF ET >= PT THEN
  		Q := FALSE;
  		ET := t#0ms;
  	END_IF;
  END_IF;
  edge := IN;

  (*From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS required *)
END_FUNCTION_BLOCK

FUNCTION BIT_OF_DWORD : BOOL
  VAR_INPUT
    IN : DWORD;
    N : INT;
  END_VAR

  BIT_OF_DWORD := (SHR(in,n) AND DWORD#1) > DWORD#0;

  (* From Oscat Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK TONOF
  VAR_INPUT
    IN : BOOL;
    T_ON : TIME;
    T_OFF : TIME;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
  END_VAR
  VAR
    X : TON;
    old : BOOL;
    mode : BOOL;
  END_VAR

  IF IN XOR old THEN
    X(IN := FALSE, PT := SEL(IN,T_OFF,T_ON));
    mode := IN;
    old := IN;
  END_IF;
  X(IN := TRUE);
  IF X.Q THEN Q := mode;END_IF;

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION INC2 : INT
  VAR_INPUT
    X : INT;
    _D : INT;
    L : INT;
    U : INT;
  END_VAR
  VAR
    tmp : INT;
  END_VAR

  tmp := U - L + 1;
  INC2 := (X + _D - L + tmp) MOD tmp + L;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION_BLOCK SEQUENCE_64
  VAR_INPUT
    START : BOOL;
    SMAX : INT;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    STATE : INT := -1;
    TRIG : BOOL;
  END_VAR
  VAR_IN_OUT
    PROG : ARRAY [0..63] OF TIME;
  END_VAR
  VAR
    tx : TIME;
    last : TIME;
    edge : BOOL;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));
  TRIG := FALSE;

  IF RST THEN
  	STATE := -1;

  (* start sequence *)
  ELSIF START AND NOT edge THEN
  	STATE := 0;
  	last := tx;
  	TRIG := TRUE;

  (* sequence generator *)
  ELSIF (STATE >= 0) THEN
  	IF (tx - last) >= PROG[STATE] THEN
  		STATE := INC2(STATE, 1, -1, SMAX);
  		last := tx;
  		TRIG := TRUE;
  	END_IF;
  END_IF;

  edge := START;

  (*From OSCAT Library, www.oscat.de *)
  (*T_PLC_MS, INC2 required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CYCLE_4
  VAR_INPUT
    _E : BOOL := TRUE;
    T0 : TIME;
    T1 : TIME;
    T2 : TIME;
    T3 : TIME;
    S0 : BOOL;
    SX : INT;
    SL : BOOL;
  END_VAR
  VAR_OUTPUT
    STATE : INT;
  END_VAR
  VAR
    tx : TIME;
    last : TIME;
    init : BOOL;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));

  (* init on first cycle *)
  IF NOT init THEN
  	init := TRUE;
  	last := tx;
  END_IF;

  IF _E THEN
  	IF SL THEN
  		(* when sx > 0 then the state sx is forced to start *)
  		state:= LIMIT(0,SX,3);
  		last := tx;
  		(* this is to avoid to reset sx from the calling programm it does work fine on codesys but i am not sure about other systems, because we are writing to an input *)
  		SL := FALSE;
  	ELSE
  		CASE state OF
  			0 :	(* wait for T0 and switch to next cycle *)
  				IF tx - last >= T0 THEN
  					state := 1;
  					last := tx;
  				END_IF;
  			1 : (* wait for T1 over 1st cycle *)
  				IF tx - last >= T1 THEN
  					state := 2;
  					last := tx;
  				END_IF;
  			2 : (* wait for T1 over 1st cycle *)
  				IF tx - last >= T2 THEN
  					state := 3;
  					last := tx;
  				END_IF;
  			3 : (* wait for T2 over 2nd cycle *)
  				IF tx - last >= T3 THEN
  					IF S0 THEN State := 0; END_IF; (* if S0 is false, the sequence stops at state 3 *)
  					last := tx;
  				END_IF;
  		END_CASE;
  	END_IF;
  ELSE
  	state := 0;
  	last := tx;
  END_IF;
END_FUNCTION_BLOCK

PROGRAM program0
  VAR
    LocalVar0 : DINT;
    LocalVar3 : DINT;
    LocalVar1 : DINT;
    LocalVar2 : DINT;
    ADD1_OUT : DINT;
  END_VAR

  ADD1_OUT := ADD(LocalVar0, LocalVar1);
  LocalVar2 := ADD1_OUT;
END_PROGRAM

FUNCTION_BLOCK B_TRIG
  VAR_INPUT
    CLK : BOOL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL := FALSE;
  END_VAR
  VAR
    edge : BOOL := FALSE;
  END_VAR

  Q := clk XOR edge;
  edge := CLK;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CLK_N
  VAR_INPUT
    N : INT;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
  END_VAR
  VAR
    edge : BOOL;
    clk : BOOL;
  END_VAR

  clk := BIT_OF_DWORD(SHR(UDINT_TO_DWORD(T_PLC_MS(en:=true)),N),0);
  Q := clk XOR edge;
  edge := clk;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CLICK_DEC
  VAR_INPUT
    IN : BOOL;
    TC : TIME;
  END_VAR
  VAR_OUTPUT
    Q0 : BOOL;
    Q1 : BOOL;
    Q2 : BOOL;
    Q3 : BOOL;
  END_VAR
  VAR
    tx : TP;
    edge : BOOL;
    cnt : INT := -1;
  END_VAR

  (* Q shall only be active for one cycle only *)
  IF in = FALSE THEN
  	Q0 := FALSE;
  	Q1 := FALSE;
  	Q2 := FALSE;
  	Q3 := FALSE;
  END_IF;

  IF in AND NOT edge AND NOT tx.q THEN
  	(* a rising edge on in sets the counter to 0 *)
  	cnt := 0;
  ELSIF tx.Q AND NOT IN AND edge THEN
  	(* count falling edges when tp.q is true *)
  	cnt := cnt + 1;
  ELSIF NOT tx.Q THEN
  	CASE cnt OF
  		0 : Q0 := TRUE;
  		1 : Q1 := TRUE;
  		2 : Q2 := TRUE;
  		3 : Q3 := TRUE;
  	END_CASE;
  	cnt := -1;
  END_IF;

  (* remember the status of IN *)
  edge := IN;
  tx(in := IN, pt := TC);

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CLK_PRG
  VAR_INPUT
    PT : TIME := T#10ms;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
  END_VAR
  VAR
    init : BOOL := FALSE;
    last : TIME;
    tx : TIME;
  END_VAR


  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));

  (* initialize on startup *)
  IF NOT init THEN
  	init := TRUE;
  	last := tx - pt;
  END_IF;

  (* generate output pulse when next_pulse is reached *)
  Q := tx - last >= pt;
  IF Q THEN last := tx; END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CLK_PULSE
  VAR_INPUT
    PT : TIME;
    N : INT;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
    CNT : INT;
    RUN : BOOL;
  END_VAR
  VAR
    tx : UDINT;
    tn : UDINT;
    init : BOOL;
  END_VAR

  tx:= T_PLC_MS(en:=true);
  Q := FALSE;				(* reset Q we generate pulses only for one cycle *)
  RUN := CNT < N;

  IF NOT init OR RST THEN
  	init := TRUE;
  	CNT := 0;
  	tn := tx - TIME_TO_UDINT(PT);
  	RUN := FALSE;
  ELSIF (cnt < N OR N = 0) AND tx - tn >= TIME_TO_UDINT(PT) THEN		(* generate a pulse *)
  	CNT := CNT + 1;
  	Q := TRUE;
  	tn := tn + TIME_TO_UDINT(PT);
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK GEN_SQ
  VAR_INPUT
    PT : TIME;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
  END_VAR
  VAR
    init : BOOL;
    tn : TIME;
    tx : TIME;
  END_VAR

  tx := UDINT_TO_TIME(T_PLC_MS(en:=true));

  IF NOT init THEN
  	init := TRUE;
  	tn := tx;
  	Q := TRUE;
  ELSIF tx - tn >= DWORD_TO_TIME(SHR(TIME_TO_DWORD(PT),1)) THEN
  	Q := NOT Q;
  	tn := tn + DWORD_TO_TIME(SHR(TIME_TO_DWORD(pt),1));
  END_IF;

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK TP_1
  VAR_INPUT
    IN : BOOL;
    PT : TIME;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
  END_VAR
  VAR
    tx : TIME;
    start : TIME;
    ix : BOOL;
  END_VAR

  tx := UDINT_TO_TIME(T_PLC_MS(en:=true));

  IF RST THEN
  	Q := FALSE;
  ELSIF IN AND NOT ix THEN
  	Q := TRUE;
  	start := tx;
  ELSIF tx - start >= PT THEN
  	Q := FALSE;
  END_IF;

  ix:= IN;

  (*From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS required *)
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

FUNCTION_BLOCK D_TRIG
  VAR_INPUT
    IN : DWORD;
  END_VAR
  VAR_OUTPUT
    X : DWORD;
    Q : BOOL;
  END_VAR
  VAR
    last_in : DWORD;
  END_VAR

  Q := in <> last_in;
  X := UDINT_TO_DWORD(DWORD_TO_UDINT(in) - DWORD_TO_UDINT(last_in));
  last_in := in;

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK SEQUENCE_8
  VAR_INPUT
    IN0 : BOOL := TRUE;
    IN1 : BOOL := TRUE;
    IN2 : BOOL := TRUE;
    IN3 : BOOL := TRUE;
    IN4 : BOOL := TRUE;
    IN5 : BOOL := TRUE;
    IN6 : BOOL := TRUE;
    IN7 : BOOL := TRUE;
    START : BOOL;
    RST : BOOL;
    WAIT0 : TIME;
    DELAY0 : TIME;
    WAIT1 : TIME;
    DELAY1 : TIME;
    WAIT2 : TIME;
    DELAY2 : TIME;
    WAIT3 : TIME;
    DELAY3 : TIME;
    WAIT4 : TIME;
    DELAY4 : TIME;
    WAIT5 : TIME;
    DELAY5 : TIME;
    WAIT6 : TIME;
    DELAY6 : TIME;
    WAIT7 : TIME;
    DELAY7 : TIME;
    STOP_ON_ERROR : BOOL;
  END_VAR
  VAR_OUTPUT
    Q0 : BOOL;
    Q1 : BOOL;
    Q2 : BOOL;
    Q3 : BOOL;
    Q4 : BOOL;
    Q5 : BOOL;
    Q6 : BOOL;
    Q7 : BOOL;
    QX : BOOL;
    RUN : BOOL;
    _STEP : INT := -1;
    STATUS : BYTE;
  END_VAR
  VAR
    last : TIME;
    edge : BOOL;
    tx : TIME;
    init : BOOL;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));

  (* initialize on startup *)
  IF NOT init THEN
  	last := tx;
  	init := TRUE;
  	status := BYTE#110;
  END_IF;

  (* asynchronous reset *)
  IF rst THEN
  	_step := -1;
  	Q0 := FALSE;
  	Q1 := FALSE;
  	Q2 := FALSE;
  	Q3 := FALSE;
  	Q4 := FALSE;
  	Q5 := FALSE;
  	Q6 := FALSE;
  	Q7 := FALSE;
  	status := BYTE#110;
  	run := FALSE;

  (* edge on start input restarts the sequencer *)
  ELSIF start AND NOT edge THEN
  	_step := 0;
  	last := tx;
  	status := BYTE#111;
  	Q0 := FALSE;
  	Q1 := FALSE;
  	Q2 := FALSE;
  	Q3 := FALSE;
  	Q4 := FALSE;
  	Q5 := FALSE;
  	Q6 := FALSE;
  	Q7 := FALSE;
  	run := TRUE;
  END_IF;
  edge := start;

  (* check if stop on error is necessary *)
  IF status > BYTE#0 AND status < BYTE#100 AND stop_on_error THEN RETURN; END_IF;

  (* sequence is running *)
  IF run AND _step = 0 THEN
  	IF NOT q0 AND in0 AND tx - last <= wait0 THEN
  		Q0 := TRUE;
  		last := tx;
  	ELSIF NOT q0 AND tx - last > wait0 THEN
  		status := BYTE#1;
  		run := FALSE;
  	ELSIF q0 AND tx - last >= delay0 THEN
  		_step := 1;
  		last := tx;
  	END_IF;
  END_IF;
  IF run AND _step = 1 THEN
  	IF NOT q1 AND in1 AND tx - last <= wait1 THEN
  		Q0 := FALSE;
  		Q1 := TRUE;
  		last := tx;
  	ELSIF NOT q1 AND Tx - last > wait1 THEN
  		status := BYTE#2;
  		q0 := FALSE;
  		run := FALSE;
  	ELSIF q1 AND tx - last >= delay1 THEN
  		_step := 2;
  		last := tx;
  	END_IF;
  END_IF;
  IF run AND _step = 2 THEN
  	IF NOT q2 AND in2 AND tx - last <= wait2 THEN
  		Q1 := FALSE;
  		Q2 := TRUE;
  		last := tx;
  	ELSIF NOT q2 AND Tx - last > wait2 THEN
  		status := BYTE#3;
  		q1 := FALSE;
  		run := FALSE;
  	ELSIF q2 AND tx - last >= delay2 THEN
  		_step := 3;
  		last := tx;
  	END_IF;
  END_IF;
  IF run AND _step = 3 THEN
  	IF NOT q3 AND in3 AND tx - last <= wait3 THEN
  		Q2 := FALSE;
  		Q3 := TRUE;
  		last := tx;
  	ELSIF NOT q3 AND Tx - last > wait3 THEN
  		status := BYTE#4;
  		q2 := FALSE;
  		run := FALSE;
  	ELSIF q3 AND tx - last >= delay3 THEN
  		_step := 4;
  		last := tx;
  	END_IF;
  END_IF;
  IF run AND _step = 4 THEN
  	IF NOT q4 AND in4 AND tx - last <= wait4 THEN
  		Q3 := FALSE;
  		Q4 := TRUE;
  		last := tx;
  	ELSIF NOT q4 AND Tx - last > wait4 THEN
  		status := BYTE#5;
  		q3 := FALSE;
  		run := FALSE;
  	ELSIF q4 AND tx - last >= WAIT4 THEN
  		_step := 5;
  		last := tx;
  	END_IF;
  END_IF;
  IF run AND _step = 5 THEN
  	IF NOT q5 AND in5 AND tx - last <= DELAY4 THEN
  		Q4 := FALSE;
  		Q5 := TRUE;
  		last := tx;
  	ELSIF NOT q5 AND Tx - last > DELAY4 THEN
  		status := BYTE#6;
  		q4 := FALSE;
  		run := FALSE;
  	ELSIF q5 AND tx - last >= WAIT5 THEN
  		_step := 6;
  		last := tx;
  	END_IF;
  END_IF;
  IF run AND _step = 6 THEN
  	IF NOT q6 AND in6 AND tx - last <= DELAY5 THEN
  		Q5 := FALSE;
  		Q6 := TRUE;
  		last := tx;
  	ELSIF NOT q6 AND Tx - last > DELAY5 THEN
  		status := BYTE#7;
  		q5 := FALSE;
  		run := FALSE;
  	ELSIF q6 AND tx - last >= WAIT6 THEN
  		_step := 7;
  		last := tx;
  	END_IF;
  END_IF;
  IF run AND _step = 7 THEN
  	IF NOT q7 AND in7 AND tx - last <= DELAY6 THEN
  		Q6 := FALSE;
  		Q7 := TRUE;
  		last := tx;
  	ELSIF NOT q7 AND Tx - last > DELAY6 THEN
  		status := BYTE#8;
  		q6 := FALSE;
  		run := FALSE;
  	ELSIF q7 AND tx - last >= WAIT7 THEN
  		_step := -1;
  		Q7 := FALSE;
  		Run := FALSE;
  		status := BYTE#110;
  	END_IF;
  END_IF;
  QX := q0 OR q1 OR q2 OR q3 OR q4 OR q5 OR q6 OR q7;

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK SEQUENCE_4
  VAR_INPUT
    IN0 : BOOL := TRUE;
    IN1 : BOOL := TRUE;
    IN2 : BOOL := TRUE;
    IN3 : BOOL := TRUE;
    START : BOOL;
    RST : BOOL;
    WAIT0 : TIME;
    DELAY0 : TIME;
    WAIT1 : TIME;
    DELAY1 : TIME;
    WAIT2 : TIME;
    DELAY2 : TIME;
    WAIT3 : TIME;
    DELAY3 : TIME;
    STOP_ON_ERROR : BOOL;
  END_VAR
  VAR_OUTPUT
    Q0 : BOOL;
    Q1 : BOOL;
    Q2 : BOOL;
    Q3 : BOOL;
    QX : BOOL;
    RUN : BOOL;
    _STEP : INT := -1;
    STATUS : BYTE;
  END_VAR
  VAR
    last : TIME;
    edge : BOOL;
    tx : TIME;
    init : BOOL;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));

  (* initialize on startup *)
  IF NOT init THEN
  	last := tx;
  	init := TRUE;
  	status := BYTE#110;
  END_IF;

  (* asynchronous reset *)
  IF rst THEN
  	_step := -1;
  	Q0 := FALSE;
  	Q1 := FALSE;
  	Q2 := FALSE;
  	Q3 := FALSE;
  	status := BYTE#110;
  	run := FALSE;

  (* edge on start input restarts the sequencer *)
  ELSIF start AND NOT edge THEN
  	_step := 0;
  	last := tx;
  	status := BYTE#111;
  	Q0 := FALSE;
  	Q1 := FALSE;
  	Q2 := FALSE;
  	Q3 := FALSE;
  	run := TRUE;
  END_IF;
  edge := start;

  (* check if stop on status is necessary *)
  IF status > BYTE#0 AND status < BYTE#100 AND stop_on_error THEN RETURN; END_IF;

  (* sequence is running *)
  IF run AND _step = 0 THEN
  	IF NOT q0 AND in0 AND tx - last <= wait0 THEN
  		Q0 := TRUE;
  		last := tx;
  	ELSIF NOT q0 AND tx - last > wait0 THEN
  		status := BYTE#1;
  		run := FALSE;
  	ELSIF q0 AND tx - last >= delay0 THEN
  		_step := 1;
  		last := tx;
  	END_IF;
  END_IF;
  IF run AND _step = 1 THEN
  	IF NOT q1 AND in1 AND tx - last <= DELAY0 THEN
  		Q0 := FALSE;
  		Q1 := TRUE;
  		last := tx;
  	ELSIF NOT q1 AND Tx - last > DELAY0 THEN
  		status := BYTE#2;
  		q0 := FALSE;
  		run := FALSE;
  	ELSIF q1 AND tx - last >= WAIT1 THEN
  		_step := 2;
  		last := tx;
  	END_IF;
  END_IF;
  IF run AND _step = 2 THEN
  	IF NOT q2 AND in2 AND tx - last <= DELAY1 THEN
  		Q1 := FALSE;
  		Q2 := TRUE;
  		last := tx;
  	ELSIF NOT q2 AND Tx - last > DELAY1 THEN
  		status := BYTE#3;
  		q1 := FALSE;
  		run := FALSE;
  	ELSIF q2 AND tx - last >= WAIT2 THEN
  		_step := 3;
  		last := tx;
  	END_IF;
  END_IF;
  IF run AND _step = 3 THEN
  	IF NOT q3 AND in3 AND tx - last <= DELAY2 THEN
  		Q2 := FALSE;
  		Q3 := TRUE;
  		last := tx;
  	ELSIF NOT q3 AND Tx - last > DELAY2 THEN
  		status := BYTE#4;
  		q2 := FALSE;
  		run := FALSE;
  	ELSIF q3 AND tx - last >= WAIT3 THEN
  		_step := -1;
  		q3 := FALSE;
  		run := FALSE;
  		status := BYTE#110;
  	END_IF;
  END_IF;
  QX := q0 OR q1 OR q2 OR q3;

  (*From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK SCHEDULER_2
  VAR_INPUT
    E0 : BOOL;
    E1 : BOOL;
    E2 : BOOL;
    E3 : BOOL;
    C0 : UINT;
    C1 : UINT;
    C2 : UINT;
    C3 : UINT;
    O0 : UINT;
    O1 : UINT;
    O2 : UINT;
    O3 : UINT;
  END_VAR
  VAR_OUTPUT
    Q0 : BOOL;
    Q1 : BOOL;
    Q2 : BOOL;
    Q3 : BOOL;
  END_VAR
  VAR
    sx : UINT;
  END_VAR

  Q0 := E0 AND (sx MOD C0 - O0 = UINT#0);
  Q1 := E1 AND (sx MOD C1 - O1 = UINT#0);
  Q2 := E2 AND (sx MOD C2 - O2 = UINT#0);
  Q3 := E3 AND (sx MOD C3 - O3 = UINT#0);

  (* increment cycle counter every cycle *)
  sx := sx + UINT#1;

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK TMAX
  VAR_INPUT
    IN : BOOL;
    PT : TIME;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
    Z : BOOL;
  END_VAR
  VAR
    tx : TIME;
    start : TIME;
    last_in : BOOL;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));

  Z := FALSE;

  IF NOT in THEN
  	Q := FALSE;
  ELSIF IN AND NOT last_in THEN
  	Q := TRUE;
  	start := tx;
  ELSIF (tx - start >= PT) AND Q THEN
  	Q := FALSE;
  	Z := TRUE;
  END_IF;

  last_in := IN;

  (*From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CLK_DIV
  VAR_INPUT
    CLK : BOOL;
    RST : BOOL;
    RST0 : BOOL;
  END_VAR
  VAR_OUTPUT
    Q0 : BOOL := FALSE;
    Q1 : BOOL := FALSE;
    Q2 : BOOL := FALSE;
    Q3 : BOOL := FALSE;
    Q4 : BOOL := FALSE;
    Q5 : BOOL := FALSE;
    Q6 : BOOL := FALSE;
    Q7 : BOOL := FALSE;
  END_VAR
  VAR
    cnt : BYTE;
  END_VAR

  IF rst THEN
  	cnt:= BYTE#0;
  	Q0 := FALSE;
  	Q1 := FALSE;
  	Q2 := FALSE;
  	Q3 := FALSE;
  	Q4 := FALSE;
  	Q5 := FALSE;
  	Q6 := FALSE;
  	Q7 := FALSE;
  ELSIF clk THEN
  	cnt:= USINT_TO_BYTE(BYTE_TO_USINT(cnt) + USINT#1);

      Q0 := BIT_OF_DWORD(BYTE_TO_DWORD(cnt),0); (* Q0 := cnt.X0; *)
      Q1 := BIT_OF_DWORD(BYTE_TO_DWORD(cnt),1); (* Q1 := cnt.X1; *)
      Q2 := BIT_OF_DWORD(BYTE_TO_DWORD(cnt),2); (* Q2 := cnt.X2; *)
      Q3 := BIT_OF_DWORD(BYTE_TO_DWORD(cnt),3); (* Q3 := cnt.X3; *)
      Q4 := BIT_OF_DWORD(BYTE_TO_DWORD(cnt),4); (* Q4 := cnt.X4; *)
      Q5 := BIT_OF_DWORD(BYTE_TO_DWORD(cnt),5); (* Q5 := cnt.X5; *)
      Q6 := BIT_OF_DWORD(BYTE_TO_DWORD(cnt),6); (* Q6 := cnt.X6; *)
      Q7 := BIT_OF_DWORD(BYTE_TO_DWORD(cnt),7); (* Q7 := cnt.X7; *)

  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK TOF_1
  VAR_INPUT
    IN : BOOL;
    PT : TIME;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
  END_VAR
  VAR
    start : TIME;
    tx : TIME;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));

  IF RST THEN
  	Q := FALSE;
  ELSIF IN THEN
  	Q := TRUE;
  	start := tx;
  ELSIF tx - start >= PT THEN
  	Q := FALSE;
  END_IF;


  (*From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK SCHEDULER
  VAR_INPUT
    E0 : BOOL;
    E1 : BOOL;
    E2 : BOOL;
    E3 : BOOL;
    T0 : TIME;
    T1 : TIME;
    T2 : TIME;
    T3 : TIME;
  END_VAR
  VAR_OUTPUT
    Q0 : BOOL;
    Q1 : BOOL;
    Q2 : BOOL;
    Q3 : BOOL;
  END_VAR
  VAR
    init : BOOL;
    s0 : TIME;
    s1 : TIME;
    s2 : TIME;
    s3 : TIME;
    tx : TIME;
    c : INT;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));

  IF NOT init THEN
  	init := TRUE;
  	s0 := tx - T0;
  	s1 := tx - T1;
  	s2 := tx - T2;
  	s3 := tx - T3;
  END_IF;

  Q0 := FALSE;
  Q1 := FALSE;
  Q2 := FALSE;
  Q3 := FALSE;

  CASE c OF
  	0: 	IF tx - s0 >= T0 THEN
  			Q0 := E0;
  			s0 := tx;
  		END_IF;
  		c := 1;
  	1: 	IF tx - s1 >= T1 THEN
  			Q1 := E1;
  			s1 := tx;
  		END_IF;
  		c := 2;
  	2: 	IF tx - s2 >= T2 THEN
  			Q2 := E2;
  			s2 := tx;
  		END_IF;
  		c := 3;
  	3: 	IF tx - s3 >= T3 THEN
  			Q3 := E3;
  			s3 := tx;
  		END_IF;
  		c := 0;
  END_CASE;

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK GEN_BIT
  VAR_INPUT
    IN0 : DWORD;
    IN1 : DWORD;
    IN2 : DWORD;
    IN3 : DWORD;
    CLK : BOOL;
    STEPS : INT;
    REP : INT;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    Q0 : BOOL;
    Q1 : BOOL;
    Q2 : BOOL;
    Q3 : BOOL;
    CNT : INT;
    RUN : BOOL;
  END_VAR
  VAR
    r0 : DWORD;
    r1 : DWORD;
    r2 : DWORD;
    r3 : DWORD;
    rx : INT := 1;
  END_VAR

  (* check if number of runs is finished or rep = 0 which means continuous *)

  IF clk AND NOT rst THEN
  	run := (rep = 0) OR (rx <= rep);
  	IF run THEN
  		(* check for step counter reached and reset to 0 if cnt = steps *)
  		IF cnt = steps THEN
  			cnt := 0;
  		END_IF;

  		(* when cnt = 0 then reload the inputs into the registers *)
  		IF cnt = 0 THEN
  			r0 := in0;
  			r1 := in1;
  			r2 := in2;
  			r3 := in3;
  		END_IF;

  		(* when cnt < steps, shift the lowest bits to the outputs *)
  		IF (cnt < steps) THEN
              Q0 := BIT_OF_DWORD(r0,0); (* Q0 := r0.X0; *)
              Q1 := BIT_OF_DWORD(r1,0); (* Q1 := r1.X0; *)
              Q2 := BIT_OF_DWORD(r2,0); (* Q2 := r2.X0; *)
              Q3 := BIT_OF_DWORD(r3,0); (* Q3 := r3.X0; *)
  			r0 := SHR(r0,1);
  			r1 := SHR(r1,1);
  			r2 := SHR(r2,1);
  			r3 := SHR(r3,1);
  		END_IF;

  		(* increment the step counter *)
  		cnt := cnt +1;
  		IF (cnt = steps) AND (rep <> 0) THEN rx := rx +1; END_IF;
  		IF (rx > rep) AND (rep <> 0) THEN run := FALSE; END_IF;
  	END_IF;
  ELSE
  	IF rst THEN
  		run := FALSE;
  		Q0 := FALSE;
  		Q1 := FALSE;
  		Q2 := FALSE;
  		Q3 := FALSE;
  		r0 := DWORD#0;
  		r1 := DWORD#0;
  		r2 := DWORD#0;
  		r3 := DWORD#0;
  		cnt := 0;
  		rx := 1;
  	END_IF;
  END_IF;

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK A_TRIG
  VAR_INPUT
    IN : REAL;
    RES : REAL;
  END_VAR
  VAR_OUTPUT
    _D : REAL;
    Q : BOOL;
  END_VAR
  VAR
    last_in : REAL;
  END_VAR

  _D := IN - LAST_IN;
  IF ABS(_D) >= res THEN
  	Q := TRUE;
  	last_in := IN;
  ELSE
  	Q := FALSE;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    VAR_GLOBAL
      PLC_CYCLE_COUNT : ULINT;
      TASK_TIME_MS : ULINT := 20;
    END_VAR
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
