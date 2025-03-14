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

FUNCTION_BLOCK CYCLE_TIME
  VAR_INPUT
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    CT_MIN : TIME := t#0s;
    CT_MAX : TIME := t#0s;
    CT_LAST : TIME;
    SYSTIME : TIME;
    SYSDAYS : INT;
    CYCLES : DWORD;
  END_VAR
  VAR
    last_cycle : TIME;
    tx : TIME;
    init : BOOL;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true)) - last_cycle;

  IF rst THEN
  	ct_min := t#10h;
  	ct_max := t#0ms;
  	cycles := DWORD#0;
  ELSIF last_cycle > t#0s THEN
  	IF tx < ct_min THEN ct_min := tx;
  	ELSIF tx > ct_max THEN ct_max := tx;
  	END_IF;
  	ct_last := tx;
  ELSIF ct_min = t#0s THEN
  	ct_min := t#0s - t#1ms;
  END_IF;
  IF init THEN
  	systime := systime + tx;
  		IF systime >= t#1d THEN
  			systime := systime - t#1d;
  			sysdays := sysdays + 1;
  		END_IF;
  END_IF;
  init := TRUE;
  last_cycle := last_cycle + tx;
  cycles := UDINT_TO_DWORD(DWORD_TO_UDINT(cycles) + UDINT#1);

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION LEAP_OF_DATE : BOOL
  VAR_INPUT
    IDATE : UDINT;
  END_VAR

  LEAP_OF_DATE := SHL(UDINT_TO_DWORD((idate + UDINT#43200) / UDINT#31557600), 30) = DWORD#16#80000000;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

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

FUNCTION YEAR_OF_DATE : INT
  VAR_INPUT
    IDATE : UDINT;
  END_VAR

  YEAR_OF_DATE := UDINT_TO_INT((IDATE+UDINT#43200) / UDINT#31557600 + UDINT#1970);

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

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

FUNCTION_BLOCK TC_US
  VAR_OUTPUT
    TC : DWORD;
  END_VAR
  VAR
    init : BOOL;
    tx : UDINT;
    last : UDINT;
  END_VAR

  tx:= T_PLC_US(en:=true);

  IF NOT init THEN
  	init := TRUE;
  	TC := DWORD#0;
  ELSE
  	tc := UDINT_TO_DWORD(tx - last);
  END_IF;
  last := tx;

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_US,  required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK DT_SIMU
  VAR_INPUT
    START : UDINT;
    SPEED : REAL := 1.0;
  END_VAR
  VAR_OUTPUT
    DTS : UDINT;
  END_VAR
  VAR
    tc : UDINT;
    init : BOOL;
    last : UDINT;
    tx : UDINT;
    td : UDINT;
  END_VAR

  tx:= T_PLC_MS(en:=true);
  tc := REAL_TO_UDINT(UDINT_TO_REAL(tx - last) * speed);

  IF NOT init THEN
  	init := TRUE;
  	DTS := Start;
  	tc := UDINT#0;
  	last := tx;
  ELSIF SPEED = 0.0 THEN
  	DTS := DTS + UDINT#1;
  ELSIF tc >= UDINT#1000 THEN
  	td := (tc / UDINT#1000) * UDINT#1000;
  	DTS := DTS + td;
  	last := last + REAL_TO_UDINT(UDINT_TO_REAL(td) / speed);
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK TC_MS
  VAR_OUTPUT
    TC : DWORD;
  END_VAR
  VAR
    init : BOOL;
    tx : UDINT;
    last : UDINT;
  END_VAR

  tx:= T_PLC_MS(en:=true);

  IF NOT init THEN
  	init := TRUE;
  	TC := DWORD#0;
  ELSE
  	tc := UDINT_TO_DWORD(tx - last);
  END_IF;
  last := tx;

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS, R2_ADD required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK INTEGRATE
  VAR_INPUT
    _E : BOOL := TRUE;
    X : REAL;
    K : REAL := 1.0;
  END_VAR
  VAR_IN_OUT
    Y : REAL;
  END_VAR
  VAR
    x_last : REAL;
    init : BOOL;
    last : UDINT;
    tx : UDINT;
  END_VAR

  tx:= T_PLC_MS(en:=true);

  IF NOT init THEN
  	init := TRUE;
  	X_last := X;
  ELSIF _E THEN
  	Y := (X + X_LAST) * 0.5E-3 * UDINT_TO_REAL(tx-last) * K + Y;
  	X_last := X;
  END_IF;
  last := tx;

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK ALARM_2
  VAR_INPUT
    X : REAL;
    LO_1 : REAL;
    HI_1 : REAL;
    LO_2 : REAL;
    HI_2 : REAL;
    HYS : REAL;
  END_VAR
  VAR_OUTPUT
    Q1_LO : BOOL;
    Q1_HI : BOOL;
    Q2_LO : BOOL;
    Q2_HI : BOOL;
  END_VAR
  VAR
    tmp : REAL;
  END_VAR

  tmp := X - Hys * 0.5;
  IF tmp > LO_1 THEN Q1_LO := FALSE; END_IF;
  IF tmp > HI_1 THEN Q2_LO := FALSE; END_IF;
  IF tmp > HI_1 THEN Q1_HI := TRUE; END_IF;
  IF tmp > LO_2 THEN Q2_HI := TRUE; END_IF;
  tmp := tmp + hys;
  IF tmp < LO_1 THEN Q1_LO := TRUE; END_IF;
  IF tmp < HI_1 THEN Q2_LO := TRUE; END_IF;
  IF tmp < HI_1 THEN Q1_HI := FALSE; END_IF;
  IF tmp < LO_2 THEN Q2_HI := FALSE; END_IF;

  (* From OSCAT Library, www.oscat.de *)
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

FUNCTION_BLOCK METER
  VAR_INPUT
    M1 : REAL;
    M2 : REAL;
    I1 : BOOL;
    I2 : BOOL;
    _D : REAL := 1.0;
    RST : BOOL;
  END_VAR
  VAR_IN_OUT
    MX : REAL;
  END_VAR
  VAR RETAIN
    MR : REAL2;
  END_VAR
  VAR
    MX1 : REAL;
    MX2 : REAL;
    tx : UDINT;
    last : UDINT;
    tc : REAL;
    init : BOOL;
    _R2_ADD : R2_ADD;
  END_VAR

  tx:= T_PLC_MS(en:=true);
  IF NOT init THEN
  	init := TRUE;
  	last := tx;
  	mr.RX := mx;
  	mr.R1 := 0.0;
  ELSIF tx = last THEN
  	RETURN;
  ELSE
  	tc := UDINT_TO_REAL(tx - last) * 0.001;
  END_IF;
  last := tx;

  (* reset *)
  IF rst THEN
  	mr.R1 := 0.0;
  	mr.RX := 0.0;
  ELSE
  	(* current consumption measurement *)
  	MX1 := SEL(I1,0.0,M1);
  	MX2 := SEL(I2,0.0,M2);
  	(* add up the current values in a double real *)
  	_R2_ADD(X:=MR,Y:=(SEL(I1,0.0,mx1) + SEL(I2, 0.0, mx2)) / _D * TC);
  	MR:=_R2_ADD._R2_ADD;
  	(* set the current output value *)
  	MX := mr.RX;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS, R2_ADD required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK M_D
  VAR_INPUT
    START : BOOL;
    STOP : BOOL;
    TMAX : TIME := t#10d;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    PT : TIME;
    ET : TIME;
    RUN : BOOL;
  END_VAR
  VAR
    edge : BOOL;
    T0 : TIME;
    tx : TIME;
    startup : BOOL;
  END_VAR

  IF rst OR et >= tmax THEN
  	pt := t#0ms;
  	et := t#0ms;
  	startup := FALSE;
  	run := FALSE;
  END_IF;

  (* avoid timers to start when input is true at startup *)
  IF NOT startup THEN
  	edge := start;
  	startup := TRUE;
  END_IF;

  (* read system timer *)
  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));

  (* detect rising edge on start *)
  IF start AND NOT edge AND NOT stop THEN
  	t0 := tx;
  	run := TRUE;
  	pt := t#0s;
  ELSIF stop AND run THEN
  	pt := et;
  	run := FALSE;
  END_IF;
  edge := start;
  IF run THEN et := tx - t0; END_IF;

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS required *)
END_FUNCTION_BLOCK

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

FUNCTION_BLOCK CALIBRATE
  VAR_INPUT
    X : REAL;
    CO : BOOL;
    CS : BOOL;
    Y_OFFSET : REAL;
    Y_SCALE : REAL;
  END_VAR
  VAR_OUTPUT
    Y : REAL;
  END_VAR
  VAR RETAIN
    offset : REAL;
    Scale : REAL := 1.0;
  END_VAR

  IF CO THEN
  	OFFSET := Y_Offset - X;
  ELSIF CS THEN
  	SCALE := Y_scale / (X + OFFSET);
  END_IF;
  (* calculate output *)
  Y := (X + OFFSET) * SCALE;
END_FUNCTION_BLOCK

FUNCTION_BLOCK M_T
  VAR_INPUT
    IN : BOOL;
    TMAX : TIME := t#10d;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    PT : TIME;
    ET : TIME;
  END_VAR
  VAR
    edge : BOOL;
    start : TIME;
    tx : TIME;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));

  IF RST OR ET >= TMAX THEN
  	PT := t#0s;
  	ET := PT;
  ELSIF IN THEN
  	IF NOT edge THEN start := tx; END_IF;
  	ET := tx - start;
  ELSE
  	PT := ET;
  END_IF;
  edge := IN;

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS required *)
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

FUNCTION DAY_OF_YEAR : INT
  VAR_INPUT
    IDATE : UDINT;
  END_VAR

  DAY_OF_YEAR := UDINT_TO_INT((idate / UDINT#86400) MOD UDINT#1461);
  IF DAY_OF_YEAR > 729 THEN
  	IF DAY_OF_YEAR > 1095 THEN DAY_OF_YEAR := DAY_OF_YEAR - 1095; ELSE DAY_OF_YEAR := DAY_OF_YEAR - 729; END_IF;
  ELSIF DAY_OF_YEAR > 364 THEN
  	DAY_OF_YEAR := DAY_OF_YEAR - 364;
  ELSE
  	DAY_OF_YEAR := DAY_OF_YEAR + 1;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION DAY_OF_WEEK : INT
  VAR_INPUT
    IDATE : UDINT;
  END_VAR

  DAY_OF_WEEK := UDINT_TO_INT((idate / UDINT#86400 + UDINT#3) MOD UDINT#7) + INT#01;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION MONTH_OF_DATE : INT
  VAR_INPUT
    IDATE : UDINT;
  END_VAR

  MONTH_OF_DATE := DAY_OF_YEAR(idate);
  IF MONTH_OF_DATE < 32 THEN
  	MONTH_OF_DATE := 1;
  ELSIF LEAP_OF_DATE(IDATE) THEN
  	MONTH_OF_DATE := (MONTH_OF_DATE * 53 + 1668) / 1623;
  ELSE
  	MONTH_OF_DATE := (MONTH_OF_DATE * 53 + 1700) / 1620;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
  (* DAY_OF_YEAR, LEAP_OF_DATE required *)
END_FUNCTION

FUNCTION_BLOCK METER_STAT
  VAR_INPUT
    IN : REAL;
    DI : UDINT;
    RST : BOOL;
  END_VAR
  VAR_IN_OUT
    LAST_DAY : REAL;
    CURRENT_DAY : REAL;
    LAST_WEEK : REAL;
    CURRENT_WEEK : REAL;
    LAST_MONTH : REAL;
    CURRENT_MONTH : REAL;
    LAST_YEAR : REAL;
    CURRENT_YEAR : REAL;
  END_VAR
  VAR RETAIN
    year_start : REAL;
    month_start : REAL;
    week_start : REAL;
    day_start : REAL;
    last_run : UDINT;
  END_VAR

  IF rst THEN
  	Last_Day := 0.0;
  	Current_Day := 0.0;
  	Day_start := IN;
  	Last_week := 0.0;
  	Current_week := 0.0;
  	Week_start := in;
  	Last_month := 0.0;
  	Current_month := 0.0;
  	month_start := in;
  	last_year := 0.0;
  	current_year := 0.0;
  	year_start := in;
  ELSE
  	Current_Day := IN - Day_Start;
  	Current_Week := In - Week_Start;
  	Current_Month := IN - Month_Start;
  	Current_Year := IN - Year_Start;
  END_IF;

  IF YEAR_OF_DATE(DI) > YEAR_OF_DATE(last_run) THEN
  	(* a new year has started *)
  	last_year := current_year;
  	current_year := 0.0;
  	year_start := in;
  	last_month := current_month;
  	current_month := 0.0;
  	month_start := in;
  	last_day := current_day;
  	current_day := 0.0;
  	day_start := in;
  ELSIF MONTH_OF_DATE(DI) > MONTH_OF_DATE(last_run) THEN
  	(* a new month has started, january is alrerady done by year change *)
  	last_month := current_month;
  	current_month := 0.0;
  	month_start := in;
  	last_day := current_day;
  	current_day := 0.0;
  	day_start := in;
  ELSIF DAY_OF_YEAR(di) > DAY_OF_YEAR(last_run) THEN
  	(* day has chaged, first day of year and first day of month has already been taken care of *)
  	last_day := current_day;
  	current_day := 0.0;
  	day_start := in;
  END_IF;
  IF DAY_OF_WEEK(DI) < DAY_OF_WEEK(last_run) THEN
  	(* a new week has started *)
  	last_week := current_week;
  	current_week := 0.0;
  	week_start := in;
  END_IF;
  last_run := di;

  (* From OSCAT Library, www.oscat.de *)
  (* several FB's  required :-) *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK ONTIME
  VAR_INPUT
    IN : BOOL;
    RST : BOOL;
  END_VAR
  VAR_IN_OUT
    SECONDS : UDINT;
    CYCLES : UDINT;
  END_VAR
  VAR
    tx : UDINT;
    last : UDINT;
    edge : BOOL;
    init : BOOL;
    ms : UDINT;
  END_VAR

  tx:= T_PLC_MS(en:=true);

  (* make sure the first cycle works correctly *)
  IF NOT init THEN
  	init := TRUE;
  	last := tx;
  	ms := UDINT#0;
  END_IF;
  IF RST THEN
  	SECONDS := UDINT#0;
  	CYCLES := UDINT#0;
  	last := tx;
  	ms := UDINT#0;
  ELSIF IN THEN
  	(* add the current milliseconds *)
  	ms := (tx - last) + ms;
  	IF ms >= UDINT#1000 THEN
  		seconds := seconds + UDINT#1;
  		ms := ms - UDINT#1000;
  	END_IF;
  	cycles := cycles + BOOL_TO_UDINT(NOT edge);
  END_IF;
  last := tx;
  edge := in;

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS, R2_ADD required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK M_TX
  VAR_INPUT
    IN : BOOL;
    TMAX : TIME := t#10d;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    TH : TIME;
    TL : TIME;
    DC : REAL;
    F : REAL;
    ET : TIME;
  END_VAR
  VAR
    edge : BOOL;
    start : TIME;
    stop : TIME;
    tx : TIME;
    rise : BOOL;
    fall : BOOL;
    startup : BOOL;
  END_VAR

  IF rst OR (et >= tmax) THEN
  	rise := FALSE;
  	fall := FALSE;
  	startup := FALSE;
  	th := t#0ms;
  	tl := t#0ms;
  	DC := 0.0;
  	F := 0.0;
  	ET := t#0s;
  END_IF;

  (* avoid timers to start when input is true at startup *)
  IF NOT startup THEN
  	edge := in;
  	startup := TRUE;
  END_IF;

  (* read system timer *)
  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));

  (* edge trigger rising and falling edge *)
  IF in XOR edge THEN
  	edge := in;
  	(* rising edge starts measurement *)
  	IF in THEN
  		start := Tx;
  		rise := TRUE;
  		IF fall THEN tl := start - stop; END_IF;
  		IF th > t#0ms AND tl > t#0ms THEN
  			dc := TIME_TO_REAL(th) / TIME_TO_REAL(th+tl);
  			f := 1000.0 / TIME_TO_REAL(th + tl);
  		END_IF;
  	(* falling edge starts second cycle measurement *)
  	ELSE
  		stop := Tx;
  		fall := TRUE;
  		IF rise THEN th := stop - start; END_IF;
  		IF th > t#0ms AND tl > t#0ms THEN
  			dc := TIME_TO_REAL(th) /  TIME_TO_REAL(th+tl);
  			f := 1000.0 / TIME_TO_REAL(th + tl);
  		END_IF;
  	END_IF;
  END_IF;
  IF rise THEN et := tx - start; END_IF;

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK BAR_GRAPH
  VAR_INPUT
    X : REAL;
    RST : BOOL;
    TRIGGER_LOW : REAL;
    TRIGGER_HIGH : REAL;
    ALARM_LOW : BOOL;
    ALARM_HIGH : BOOL;
    LOG_SCALE : BOOL;
  END_VAR
  VAR_OUTPUT
    LOW : BOOL;
    Q1 : BOOL;
    Q2 : BOOL;
    Q3 : BOOL;
    Q4 : BOOL;
    Q5 : BOOL;
    Q6 : BOOL;
    HIGH : BOOL;
    ALARM : BOOL;
    STATUS : BYTE;
  END_VAR
  VAR
    init : BOOL;
    T1 : REAL;
    T2 : REAL;
    T3 : REAL;
    T4 : REAL;
    T5 : REAL;
    temp : REAL;
  END_VAR

  IF NOT init THEN
  	init := TRUE;
  	IF log_scale THEN
  		temp := EXP(LN(Trigger_high / Trigger_low) * 0.166666666666666666666);
  		T1 := trigger_low * temp;
  		T2 := T1 * temp;
  		T3 := T2 * temp;
  		T4 := T3 * temp;
  		T5 := T4 * temp;
  	ELSE
  		temp := (trigger_high - trigger_low) * 0.142857142;
  		T1 := trigger_low + temp;
  		T2 := T1 + temp;
  		T3 := T2 + temp;
  		T4 := T3 + temp;
  		T5 := T4 + temp;
  	END_IF;
  END_IF;

  (* clear outputs before checking *)
  Q1 := FALSE;
  Q2 := FALSE;
  Q3 := FALSE;
  Q4 := FALSE;
  Q5 := FALSE;
  Q6 := FALSE;
  status := BYTE#110;

  (* low, high and alarm can only be cleared with rst depending on alarm_low and alarm_high *)
  IF NOT alarm_low THEN low := FALSE; END_IF;
  IF NOT alarm_high THEN high := FALSE; END_IF;
  IF rst THEN
  	alarm := FALSE;
  	low := FALSE;
  	high := FALSE;
  END_IF;

  (* check and set outputs *)
  IF X < trigger_low THEN
  	Low := TRUE;
  	status := BYTE#111;
  	IF alarm_low THEN
  		alarm := TRUE;
  		status := BYTE#1;
  	END_IF;
  ELSIF X < T1 THEN
  	Q1 := TRUE;
  ELSIF x < t2 THEN
  	Q2 := TRUE;
  ELSIF x < t3 THEN
  	Q3 := TRUE;
  ELSIF x < T4 THEN
  	Q4 := TRUE;
  ELSIF x < T5 THEN
  	q5 := TRUE;
  ELSIF x < trigger_high THEN
  	q6 := TRUE;
  ELSE
  	high := TRUE;
  	status := BYTE#112;
  	IF alarm_high THEN
  		alarm := TRUE;
  		status := BYTE#2;
  	END_IF;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK FLOW_METER
  VAR_INPUT
    VX : REAL;
    _E : BOOL;
    RST : BOOL;
    PULSE_MODE : BOOL;
    UPDATE_TIME : TIME := t#1s;
  END_VAR
  VAR_OUTPUT
    F : REAL;
  END_VAR
  VAR_IN_OUT
    X : REAL;
    Y : UDINT;
  END_VAR
  VAR
    tx : TIME;
    tl : TIME;
    int1 : INTEGRATE;
    init : BOOL;
    e_last : BOOL;
    tmp : INT;
    x_last : REAL;
    y_last : UDINT;
  END_VAR

  IF NOT init THEN	(* init on power up *)
  	init := TRUE;
  	tl := tx;
  	x_last := X;
  	y_last := Y;
  	int1.K := 2.7777777777777777E-4;
  END_IF;

  (* run integrator *)
  int1(_E := NOT (RST OR PULSE_MODE) AND _E, X := VX, Y := X);	(* gated operation *)
  X := int1.Y;

  IF RST THEN		(* reset *)
  	X := 0.0;
  	Y := UDINT#0;
  	tl := tx;
  	x_last := 0.0;
  	y_last := UDINT#0;
  ELSIF _E AND PULSE_MODE THEN	(* check for pulse mode *)
  	IF NOT e_last THEN X := X + VX; END_IF;
  END_IF;
  e_last := _E;

  (* reduce X to be less than 1 and increase Y respectively *)
  IF X > 1.0 THEN
  	tmp := FLOOR(X);
  	Y := Y + INT_TO_UDINT(tmp);
  	X := X - INT_TO_REAL(tmp);
  END_IF;

  (* calculate the current flow *)
  tx := UDINT_TO_TIME(T_PLC_MS(en:=true));
  IF tx - tl >= UPDATE_TIME AND UPDATE_TIME > t#0s THEN
  	F := (UDINT_TO_REAL(Y - y_last) + X - x_last) / TIME_TO_REAL(tx - tl) * 3.6E6;
  	y_last := Y;
  	x_last := X;
  	tl := tx;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS, FLOOR, INTEGRATE required *)
END_FUNCTION_BLOCK


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
