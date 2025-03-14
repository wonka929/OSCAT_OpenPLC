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
  OSCAT_ARRAY_X : ARRAY [0..1] OF REAL;
  TIMER_EVENT : STRUCT
    TYP : BYTE;
    CHANNEL : BYTE;
    DAY : BYTE;
    START : UDINT;
    DURATION : TIME;
    LAND : BYTE;
    LOR : BYTE;
    LAST : UDINT;
  END_STRUCT;
  REAL2 : STRUCT
    R1 : REAL;
    RX : REAL;
  END_STRUCT;
  OSCAT_CALENDAR : STRUCT
    UTC : UDINT;
    LDT : UDINT;
    LDATE : UDINT;
    LTOD : UDINT;
    YEAR : INT;
    MONTH : INT;
    DAY : INT;
    WEEKDAY : INT;
    OFFSET : INT;
    DST_EN : BOOL;
    DST_ON : BOOL;
    NAME : STRING;
    LANGUAGE : INT;
    LONGITUDE : REAL;
    LATITUDE : REAL;
    SUN_RISE : UDINT;
    SUN_SET : UDINT;
    SUN_MIDDAY : UDINT;
    SUN_HEIGTH : REAL;
    SUN_HOR : REAL;
    SUN_VER : REAL;
    NIGHT : BOOL;
    HOLIDAY : BOOL;
    HOLY_NAME : STRING;
    WORK_WEEK : INT;
  END_STRUCT;
END_TYPE

FUNCTION FLOOR2 : DINT
  VAR_INPUT
    x : REAL;
  END_VAR

  FLOOR2 := REAL_TO_DINT(X);
  IF DINT_TO_REAL(FLOOR2) > X THEN
  	FLOOR2 := FLOOR2 - DINT#1;
  END_IF;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION MODR : REAL
  VAR_INPUT
    IN : REAL;
    DIVI : REAL;
  END_VAR

  IF divi = 0.0 THEN
  	MODR := 0.0;
  ELSE
  	MODR := in - DINT_TO_REAL(FLOOR2(in / divi)) * divi;
  END_IF;
  (* from OSCAT library; www.oscat.de  *)
  (* FC FLOOR2 required *)
END_FUNCTION

FUNCTION DEG : REAL
  VAR_INPUT
    RAD_IN : REAL;
  END_VAR

  DEG := MODR(57.29577951308232 * RAD_IN, 360.0);
  (* from OSCAT library; www.oscat.de  *)
  (* MODR and FLOOR2 required *)
END_FUNCTION

FUNCTION RAD : REAL
  VAR_INPUT
    _DEG : REAL;
  END_VAR

  RAD := modR(0.0174532925199433 * _deg , 6.283185307179586476);
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION _DT_TO_TOD : UDINT
  VAR_INPUT
    IN : UDINT;
  END_VAR

  _DT_TO_TOD := (IN MOD UDINT#86400) * UDINT#1000;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK BLIND_SHADE
  VAR_INPUT
    UP : BOOL;
    DN : BOOL;
    PI : BYTE;
    AI : BYTE;
    S_IN : BYTE;
    ENABLE : BOOL;
    SUN : BOOL;
    SUNRISE_OFFSET : TIME := t#1h;
    SUNSET_PRESET : TIME := t#1h;
    SHADE_DELAY : TIME := t#60s;
    SHADE_POS : BYTE;
    DIRECTION : REAL := 180.0;
    ANGLE_OFFSET : REAL := 80.0;
    SLAT_WIDTH : REAL := 80.0;
    SLAT_SPACING : REAL := 60.0;
  END_VAR
  VAR_OUTPUT
    QU : BOOL;
    QD : BOOL;
    STATUS : BYTE;
    PO : BYTE;
    AO : BYTE;
  END_VAR
  VAR_IN_OUT
    CX : OSCAT_CALENDAR;
  END_VAR
  VAR
    sun_delay : TOF;
    angle : REAL;
  END_VAR

  (* the input sun is sent through tof which will delay the shade for the time shade_delay *)
  sun_delay(IN := sun, PT := shade_delay);

  IF UP AND DN AND enable AND sun_delay.Q AND cx.SUN_HOR > direction - angle_offset AND cx.SUN_HOR < direction + angle_offset AND
  	_DT_TO_TOD(cx.UTC) > cx.SUN_RISE + TIME_TO_UDINT(sunrise_offset) AND _DT_TO_TOD(cx.UTC) < cx.SUN_SET - TIME_TO_UDINT(sunset_preset) THEN
  	status := BYTE#151;
  	QU := UP;
  	QD := DN;
  	(* position is predefined *)
  	po := shade_pos;
  	(* shading is active now calculate the slat angle *)
  	(* calculate the max angle for the blind *)
  	angle := DEG(ATAN(slat_spacing / slat_width));
  	(* check if sun angle is between 0 and max angle *)
  	IF cx.SUN_VER > 0.0 AND cx.SUN_VER < angle THEN
  		angle := cx.SUN_VER + DEG(ACOS(COS(RAD(cx.SUN_VER))*slat_spacing / Slat_width));
  		ao := INT_TO_BYTE(LIMIT(0,UDINT_TO_INT(TRUNC(angle * 2.833333333)), 255));
  	ELSE
  		ao := BYTE#255;
  	END_IF;
  ELSE
  	QU := UP;
  	QD := DN;
  	po := pi;
  	ao := ai;
  	status := S_IN;
  END_IF;


  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION_BLOCK

FUNCTION WATER_DENSITY : REAL
  VAR_INPUT
    _T : REAL;
    SAT : BOOL;
  END_VAR
  VAR
    T2 : REAL;
    T4 : REAL;
  END_VAR

  T2 := _T * _T;
  T4 := T2 * T2;
  WATER_DENSITY := (999.83952 + 16.952577*_T + -7.9905127E-3*T2 + -4.6241757E-5*T2*_T + 1.0584601E-7*T4 + -2.8103006E-10*T4*_T) / (1.0 + 0.0168872*_T);
  IF sat THEN WATER_DENSITY := WATER_DENSITY - 0.004612 + 0.000106 * _T; END_IF;

  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION

FUNCTION TIMECHECK : BOOL
  VAR_INPUT
    TD : UDINT;
    START : UDINT;
    STOP : UDINT;
  END_VAR

  IF stop < start THEN
  	TIMECHECK := start <= TD OR  TD < stop;
  ELSE
  	TIMECHECK := start <= TD AND TD < stop;
  END_IF;

  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION

FUNCTION_BLOCK BOILER
  VAR_INPUT
    T_UPPER : REAL;
    T_LOWER : REAL;
    PRESSURE : BOOL := TRUE;
    ENABLE : BOOL := TRUE;
    REQ_1 : BOOL;
    REQ_2 : BOOL;
    BOOST : BOOL;
    T_UPPER_MIN : REAL := 50.0;
    T_UPPER_MAX : REAL := 60.0;
    T_LOWER_ENABLE : BOOL;
    T_LOWER_MAX : REAL := 60.0;
    T_REQUEST_1 : REAL := 70.0;
    T_REQUEST_2 : REAL := 50.0;
    T_REQUEST_HYS : REAL := 5.0;
    T_PROTECT_HIGH : REAL := 80.0;
    T_PROTECT_LOW : REAL := 10.0;
  END_VAR
  VAR_OUTPUT
    HEAT : BOOL;
    ERROR : BOOL;
    STATUS : BYTE;
  END_VAR
  VAR
    edge : BOOL;
    boost_mode : BOOL;
    flag_0 : BOOL;
    flag_1 : BOOL;
    flag_2 : BOOL;
  END_VAR

  (* read sensors and check for valid data *)
  IF t_upper > t_protect_high THEN
  	status := BYTE#1;
  	heat := FALSE;
  	error := TRUE;
  ELSIF t_upper < t_protect_low THEN
  	status := BYTE#2;
  	heat := TRUE;
  	error := TRUE;
  ELSIF t_lower > T_protect_high AND t_lower_enable THEN
  	status := BYTE#3;
  	heat := FALSE;
  	error := TRUE;
  ELSIF t_lower < t_protect_low AND t_lower_enable THEN
  	status := BYTE#4;
  	heat := TRUE;
  	error := TRUE;
  ELSIF NOT pressure THEN
  	status := BYTE#5;
  	heat := FALSE;
  	error := TRUE;
  ELSIF req_1 OR req_2 OR enable OR boost THEN
  	error := FALSE;

  	(* determine if heat needs to be turned on *)
  	IF boost AND NOT edge AND t_upper < t_upper_max THEN
  		status := BYTE#101;
  		heat := TRUE;
  		boost_mode := TRUE;
  	ELSIF enable AND t_upper < T_upper_min THEN
  		status := BYTE#102;
  		heat := TRUE;
  	ELSIF req_1 AND t_upper < T_request_1 THEN
  		status := BYTE#103;
  		heat := TRUE;
  	ELSIF req_2 AND t_upper < t_request_2 THEN
  		status := BYTE#104;
  		heat := TRUE;
  	END_IF;

  	(* determine the shut off temperature *)
  	IF heat THEN
  		IF (enable OR boost_mode) THEN
  			flag_0 := TRUE;
  			IF T_lower_enable AND T_lower > T_lower_max THEN
  				flag_0 := FALSE;
  				boost_mode := FALSE;
  			ELSIF NOT T_lower_enable AND T_upper > T_upper_max THEN
  				flag_0 := FALSE;
  				boost_mode := FALSE;
  			END_IF;
  		ELSE
  			flag_0 := FALSE;
  		END_IF;
  		flag_1 := (req_1 AND T_upper > T_request_1 + T_request_hys) AND req_1;
  		flag_2 := (req_2 AND T_upper > T_request_2 + T_request_hys) AND req_2;

  		(* shut off heat if no longer needed *)
  		heat := flag_0 OR flag_1 OR flag_2;
  		IF heat = FALSE THEN status := BYTE#100; END_IF;
  	END_IF;
  ELSE
  	status := BYTE#100;
  	heat := FALSE;
  	error := FALSE;
  END_IF;
  edge := boost;

  (* From OSCAT Library, www.OSCAT.de *)
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

  (* From OSCAT library, www.OSCAT.de

  this is a temporary T_PLC_MS FB until OpenPLC gets it´s own time() functionality *)

  (* PLC_TIME and Global variables PLC_SCAN_CYCL and PLC_CYCL_TIME required *)
END_FUNCTION

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

FUNCTION_BLOCK FT_INT2
  VAR_INPUT
    IN : REAL;
    K : REAL := 1.0;
    RUN : BOOL := TRUE;
    RST : BOOL;
    OUT_MIN : REAL := -1.0E-37;
    OUT_MAX : REAL := 1.0E37;
  END_VAR
  VAR_OUTPUT
    OUT : REAL;
    LIM : BOOL;
  END_VAR
  VAR
    INTEG : INTEGRATE;
    ix : REAL;
    val : REAL2;
    _R2_ADD : R2_ADD;
    _R2_SET : R2_SET;
  END_VAR

  IF RST THEN
  	_R2_SET(X:=0.0);
  	val:=_R2_SET._R2_SET;
  	out := 0.0;
  ELSE
  	integ(X := IN, _E := RUN, K := K, Y := ix);
  	ix := integ.Y;
  	_R2_ADD(X:=val,Y:=ix);
  	val:=_R2_ADD._R2_ADD;
  	ix := 0.0;
  	OUT := val.RX;
  END_IF;

  (* check output for limits *)
  IF out > OUT_MIN AND out < OUT_MAX THEN
  	LIM := FALSE;
  ELSE
  	OUT := LIMIT(OUT_MIN, OUT, OUT_MAX);
  	_R2_SET(X:=OUT);
  	val:=_R2_SET._R2_SET;
  	LIM := TRUE;
  END_IF;


  (* From OSCAT Library, www.oscat.de *)
  (* INTEGRATE required *)
END_FUNCTION_BLOCK

FUNCTION LINEAR_INT : REAL
  VAR_INPUT
    X : REAL;
  END_VAR
  VAR_IN_OUT
    XY : ARRAY [1..20,0..1] OF REAL;
  END_VAR
  VAR_INPUT
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

FUNCTION WATER_ENTHALPY : REAL
  VAR_INPUT
    _T : REAL;
  END_VAR
  VAR
    Pts : INT := 11;
    data : ARRAY [1..20,0..1] OF REAL := [0.0, 0.06, 10.0, 42.1, 20.0, 83.9, 30.0, 125.8, 40.0, 167.58, 50.0, 209.4, 60.0, 251.2, 70.0, 293.1, 80.0, 335.0, 90.0, 377.0, 100.0, 419.1];
  END_VAR

  WATER_ENTHALPY := LINEAR_INT(_T, data, pts);

  (* From OSCAT Library, www.OSCAT.de *)
  (* LINEAR_INT required *)
END_FUNCTION

FUNCTION_BLOCK HEAT_METER
  VAR_INPUT
    TF : REAL;
    TR : REAL;
    LPH : REAL;
    _E : BOOL;
    RST : BOOL;
    CP : REAL;
    DENSITY : REAL;
    CONTENT : REAL;
    PULSE_MODE : BOOL;
    RETURN_METER : BOOL;
    AVG_TIME : TIME;
  END_VAR
  VAR_OUTPUT
    C : REAL;
  END_VAR
  VAR_IN_OUT
    Y : REAL;
  END_VAR
  VAR
    tx : DWORD;
    last : DWORD;
    int1 : FT_INT2;
    edge : BOOL;
    x : REAL;
    init : BOOL;
    y_last : REAL;
  END_VAR

  IF rst THEN
  	int1(rst := TRUE);
  	int1.rst := FALSE;
  	C := 0.0;
  	Y := 0.0;
  ELSIF _e THEN
  	X := (WATER_DENSITY(_T:=(SEL(G:=return_meter, IN0:=TF, IN1:=TR)), sat:=FALSE) * (WATER_ENTHALPY(_T:=TF) - WATER_ENTHALPY(_T:=TR)) * (1.0 - content) + CP * Density * content * (TF-TR));
  END_IF;

  (* integrate or add consumption *)
  int1(run := NOT pulse_mode AND _e, in := X * LPH * 2.77777777777E-4);
  IF pulse_mode THEN
  	IF NOT edge AND _E THEN Y := Y + X * LPH; END_IF;
  ELSE
  	Y := int1.Out;
  END_IF;

  (* store the value of e *)
  edge := _e;

  (* read system_time *)
  tx := udint_to_dword(T_PLC_MS(en:=true));

  (* only init at startup necessary *)
  IF NOT init THEN
  	init := TRUE;
  	last := tx;
  END_IF;

  (* calculate the current consumption *)
  IF (dword_to_real(tx) - dword_to_real(last) >= TIME_TO_real(AVG_TIME)) AND (avg_time > T#0s) THEN
  	last := tx;
  	C := (Y - Y_last) * 3.6E6 / DWORD_TO_REAL(TIME_TO_DWORD(AVG_TIME));
  	Y_last := Y;
  END_IF;

  (* from OSCAT library www.oscat.de *)
  (* T_PLC_MS, FT_INT2, WATER_ENTHALPY, WATER_DENSITY required *)
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

FUNCTION SDD : REAL
  VAR_INPUT
    _T : REAL;
    ICE : BOOL;
  END_VAR

  IF ice THEN
  	SDD := 611.153 * EXP(22.4433 * _T / (272.186 + _T));
  ELSE
  	SDD := 611.213 * EXP(17.5043 * _T / (241.2 + _T));
  END_IF;

  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION

FUNCTION DEW_CON : REAL
  VAR_INPUT
    RH : REAL;
    _T : REAL;
  END_VAR

  IF RH > 0.0 AND _T > -50.0 THEN
  	DEW_CON := 2.166824303E-2 * RH * SDD(_T,FALSE)  / (_T - -273.15);
  ELSE
  	DEW_CON := 0.0;
  END_IF;

  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION

FUNCTION DEW_RH : REAL
  VAR_INPUT
    VC : REAL;
    _T : REAL;
  END_VAR

  DEW_RH := LIMIT(0.0, VC / DEW_CON(1.0, _T), 100.0);

  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION

FUNCTION C_TO_F : REAL
  VAR_INPUT
    CELSIUS : REAL;
  END_VAR

  C_TO_F := celsius * 1.8 + 32.0;

  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION

FUNCTION LEAP_OF_DATE : BOOL
  VAR_INPUT
    IDATE : UDINT;
  END_VAR

  LEAP_OF_DATE := SHL(UDINT_TO_DWORD((idate + UDINT#43200) / UDINT#31557600), 30) = DWORD#16#80000000;

  (* From OSCAT Library, www.oscat.de *)
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

FUNCTION DAY_OF_MONTH : INT
  VAR_INPUT
    IDATE : UDINT;
  END_VAR

  day_of_month := day_of_year(idate);

  IF leap_of_Date(idate) THEN
  	CASE day_of_month OF
  		32..60	:	day_of_month := day_of_month - 31;
  		61..91	:	day_of_month := day_of_month - 60;
  		92..121 :	day_of_month := day_of_month - 91;
  		122..152:	day_of_month := day_of_month - 121;
  		153..182:	day_of_month := day_of_month - 152;
  		183..213:	day_of_month := day_of_month - 182;
  		214..244:	day_of_month := day_of_month - 213;
  		245..274:	day_of_month := day_of_month - 244;
  		275..305:	day_of_month := day_of_month - 274;
  		306..335:	day_of_month := day_of_month - 305;
  		336..366:	day_of_month := day_of_month - 335;
  	END_CASE;
  ELSE
  	CASE day_of_month OF
  		32..59	:	day_of_month := day_of_month - 31;
  		60..90	:	day_of_month := day_of_month - 59;
  		91..120 :	day_of_month := day_of_month - 90;
  		121..151:	day_of_month := day_of_month - 120;
  		152..181:	day_of_month := day_of_month - 151;
  		182..212:	day_of_month := day_of_month - 181;
  		213..243:	day_of_month := day_of_month - 212;
  		244..273:	day_of_month := day_of_month - 243;
  		274..304:	day_of_month := day_of_month - 273;
  		305..334:	day_of_month := day_of_month - 304;
  		335..365:	day_of_month := day_of_month - 334;
  	END_CASE;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

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

FUNCTION_BLOCK DEBOUNCE
  VAR_INPUT
    IN : BOOL;
    TD : TIME;
    PM : BOOL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
  END_VAR
  VAR
    deb : TOF;
  END_VAR

  IF NOT deb.Q AND IN THEN
  	(* rising edge on input detetced and debounce timer elapsed *)
  	Q := TRUE;
  ELSIF NOT PM THEN
  	Q := deb.Q;
  ELSE
  	Q := FALSE;
  END_IF;

  (* run debounce timer *)
  deb(IN := IN, PT := TD);

  (* From OSCAT LIBRARY, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK SW_RECONFIG
  VAR_INPUT
    IN : BOOL;
    TD : TIME;
    TR : TIME;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
  END_VAR
  VAR
    T1 : TON;
    T2 : TON;
    INV : BOOL;
  END_VAR

  (* run debounce circuit *)
  t1(in := IN, PT := TD);

  IF tr > t#0s THEN
  	(* generate output *)
  	Q := t1.Q XOR inv;
  	(* reconfiguration timer *)
  	T2(in := Q, pt := TR);
  	(* when T2.Q goes high then reverse INV *)
  	IF T2.Q THEN INV := NOT INV; END_IF;
  ELSE
  	Q := t1.Q;
  END_IF;

  (* From OSCAT LIBRARY, www.oscat.de *)
  (* TON required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CLICK_MODE
  VAR_INPUT
    IN : BOOL;
    T_LONG : TIME := t#500ms;
  END_VAR
  VAR_OUTPUT
    SINGLE : BOOL;
    DOUBLE : BOOL;
    LONG : BOOL;
    TP_LONG : BOOL;
  END_VAR
  VAR
    timer : TP;
    cnt : INT;
    last : BOOL;
  END_VAR

  (* when input goes high start the timer to decode pulses *)
  timer(in := IN, PT := T_LONG);
  single := FALSE;
  double := FALSE;

  IF timer.Q THEN
  	(* decode pulses while the timer is active *)
  	IF NOT in AND last THEN	cnt := cnt + 1; END_IF;
  ELSE
  	CASE cnt OF
  		1 : single := TRUE;
  		2 : double := TRUE;
  	END_CASE;
  	cnt := 0;
  END_IF;
  last := in;
  TP_LONG := NOT timer.Q AND (NOT LONG) AND IN;
  LONG := NOT timer.Q AND in;

  (* From OSCAT LIBRARY, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION FRMP_B : BYTE
  VAR_INPUT
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

  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION

FUNCTION_BLOCK _RMP_B
  VAR_INPUT
    DIR : BOOL;
    _E : BOOL := TRUE;
    TR : TIME;
  END_VAR
  VAR_IN_OUT
    RMP : BYTE;
  END_VAR
  VAR
    tx : TIME;
    tl : TIME;
    tn : TIME;
    init : BOOL;
    last_dir : BOOL;
    start : BYTE;
  END_VAR

  tx := UDINT_TO_TIME(T_PLC_MS(en:=true));

  IF _E AND init AND (dir = last_dir) AND (RMP <> SEL(DIR, BYTE#0, BYTE#255)) AND TR = tn THEN
  	RMP := FRMP_B(start, DIR, tx - tl, TR);
  ELSE
  	init := TRUE;
  	tl := tx;
  	tn := tr;
  	start := RMP;
  END_IF;
  last_dir := dir;

  (* From OSCAT Library, www.OSCAT.de *)
  (* T_PLC_MS requires *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK RMP_B
  VAR_INPUT
    SET : BOOL;
    PT : TIME;
    _E : BOOL := TRUE;
    UP : BOOL := TRUE;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    OUT : BYTE;
    BUSY : BOOL;
    HIGH : BOOL;
    LOW : BOOL;
  END_VAR
  VAR
    rmp : _RMP_B;
  END_VAR

  rmp(dir := UP, _E := _E, TR := PT, RMP := out);
  out := rmp.RMP;

  (* set or reset operation *)
  IF RST THEN
  	out := BYTE#0;
  ELSIF SET THEN
  	out := BYTE#255;
  END_IF;

  (* checks for outputs stable and reset or set busy flag *)
  low := out = BYTE#0;
  high := out = BYTE#255;
  busy := NOT (low OR high) AND _E;

  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CLICK
  VAR_INPUT
    IN : BOOL;
    T_DEBOUNCE : TIME := t#10ms;
    T_SHORT : TIME := t#200ms;
    T_PAUSE : TIME := t#500ms;
    T_RECONFIG : TIME := t#1m;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
    SINGLE : BOOL;
    DOUBLE : BOOL;
    TRIPLE : BOOL;
    STATUS : BYTE;
  END_VAR
  VAR
    s_in : SW_RECONFIG;
    tx : TIME;
    state : INT;
    last : TIME;
  END_VAR

  (* reconfiguration and debounce circuitry *)
  s_in(in := in, TD := T_debounce, TR := T_reconfig);

  (* read system time *)
  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));

  (* count the mumber of clicks *)
  IF s_in.Q XOR Q THEN
  	last := tx;
  	IF s_in.Q THEN state := state + 1; END_IF;
  END_IF;
  Q := s_in.Q;

  (* set outputs *)
  IF state > 0 THEN
  	IF (Q AND tx - last > t_short) OR (NOT Q AND tx - last > t_pause) THEN
  		CASE state OF
  			1:	single := TRUE;
  				status := BYTE#111;
  			2:	double := TRUE;
  				status := BYTE#112;
  			3:	triple := TRUE;
  				status := BYTE#113;
  		END_CASE;
  		state := 0;
  	END_IF;
  ELSIF NOT q THEN
  	single := FALSE;
  	double := FALSE;
  	triple := FALSE;
  	status := BYTE#110;
  	last := tx;
  	state := 0;
  END_IF;

  (* From OSCAT LIBRARY, www.oscat.de *)
  (* SW_RECONFIG required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK DIMM_I
  VAR_INPUT
    SET : BOOL;
    VAL : BYTE := 255;
    IN : BOOL;
    RST : BOOL;
    T_DEBOUNCE : TIME := t#10ms;
    T_RECONFIG : TIME := t#10s;
    T_ON_MAX : TIME := t#0h;
    T_DIMM_START : TIME := t#1s;
    T_DIMM : TIME := t#3s;
    MIN_ON : BYTE := 50;
    MAX_ON : BYTE := 255;
    RST_OUT : BOOL;
    SOFT_DIMM : BOOL := TRUE;
    DBL_TOGGLE : BOOL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
    DBL : BOOL;
  END_VAR
  VAR_IN_OUT
    OUT : BYTE;
  END_VAR
  VAR
    t3 : TON;
    config : SW_RECONFIG;
    decode : CLICK_MODE;
    dim : _RMP_B;
    dir : BOOL;
  END_VAR

  (* the input is first sent through auto reconfiguration and debouncing *)
  config(IN := IN, TD := T_DEBOUNCE, TR := T_RECONFIG);
  decode(in := config.Q, T_LONG := T_DIMM_START);

  IF RST THEN
  	IF rst_out THEN out := BYTE#0; END_IF;
  	Q := FALSE;
  	dir := out > BYTE#127;
  ELSIF set THEN
  	out := val;
  	Q := TRUE;
  	(* set direction to up when value < 127 otherwise set dir down dir is reversed because next action will reverse again *)
  	dir := out > BYTE#127;
  ELSIF decode.SINGLE THEN
  	(* a single click reverses output Q *)
  	Q := NOT Q;
  	(* when dimmer is turned on we need to limit out to min and max limits *)
  	IF Q THEN OUT := INT_TO_BYTE(LIMIT(MAX(BYTE_TO_INT(MIN_ON),1), BYTE_TO_INT(out), BYTE_TO_INT(MAX_ON)));	END_IF;
  	(* set the appropriate direction of dimmer dir is reversed because next action will reverse again *)
  	dir := OUT > BYTE#127;
  ELSIF decode.TP_LONG THEN
  	IF NOT Q THEN
  		IF SOFT_DIMM THEN
  			OUT := BYTE#1;
  			dir := TRUE;
  		ELSE
              out := INT_TO_BYTE(LIMIT(MAX(BYTE_TO_INT(MIN_ON),1), BYTE_TO_INT(out), BYTE_TO_INT(MAX_ON)));
  			DIR := out < BYTE#127;
  		END_IF;
  		Q := TRUE;
  	ELSE
  		(* reverse direction with every long click *)
  		dir := NOT dir;
  	END_IF;
  END_IF;

  (* set the double click output *)
  IF NOT dbl_toggle THEN dbl := FALSE; END_IF;
  IF decode.DOUBLE THEN dbl := NOT dbl; END_IF;

  (* while dimming is active ramp the output out up or down *)
  dim(DIR := dir, _e := decode.LONG AND Q, TR := T_DIMM, rmp := out);
  OUT := dim.RMP;
  (* reverse direction when limits are reached *)
  IF out = BYTE#0 THEN
  	dir := TRUE;
  ELSIF out = BYTE#255 THEN
  	dir := FALSE;
  END_IF;

  (* limit the maximum runtime *)
  IF t_ON_MAX > t#0s THEN
  	t3(in := q, pt := T_ON_MAX);
  	Q := Q XOR t3.Q;
  END_IF;


  (* From OSCAT LIBRARY, www.oscat.de *)
  (* _RMP_B, CLICK_MODE, TOF required *)
END_FUNCTION_BLOCK

FUNCTION YEAR_END : UDINT
  VAR_INPUT
    Y : INT;
  END_VAR

  YEAR_END := DWORD_TO_UDINT(SHR(UDINT_TO_DWORD(INT_TO_UDINT(y) * UDINT#1461 - UDINT#2876712), 2)) * UDINT#86400;

  (* From OSCAT LIBRARY, www.oscat.de *)
END_FUNCTION

FUNCTION LEAP_DAY : BOOL
  VAR_INPUT
    IDATE : UDINT;
  END_VAR

  LEAP_DAY := IDATE MOD UDINT#126230400 = UDINT#68169600;

  (* From OSCAT LIBRARY, www.oscat.de *)
END_FUNCTION

FUNCTION DAY_OF_WEEK : INT
  VAR_INPUT
    IDATE : UDINT;
  END_VAR

  DAY_OF_WEEK := UDINT_TO_INT((idate / UDINT#86400 + UDINT#3) MOD UDINT#7) + INT#01;

  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION

FUNCTION _DT_TO_DATE : UDINT
  VAR_INPUT
    IN : UDINT;
  END_VAR

  _DT_TO_DATE := (IN / UDINT#86400) * UDINT#86400;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION YEAR_OF_DATE : INT
  VAR_INPUT
    IDATE : UDINT;
  END_VAR

  YEAR_OF_DATE := UDINT_TO_INT((IDATE+UDINT#43200) / UDINT#31557600 + UDINT#1970);

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

FUNCTION DATE_TO_DT : UDINT
  VAR_INPUT
    IN : UDINT;
  END_VAR

  DATE_TO_DT := IN;


  (* From OSCAT LIBRARY, www.oscat.de *)
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

FUNCTION SET_DATE : UDINT
  VAR_INPUT
    YEAR : INT;
    MONTH : INT;
    DAY : INT;
  END_VAR
  VAR
    count : INT;
  END_VAR

  IF month > 2 THEN
  	count := (month - 1) * 30;
  	IF month > 7 THEN
  		count := count + DWORD_TO_INT(SHR(DINT_TO_DWORD(INT_TO_DINT(month) - INT_TO_DINT(3)),1));
  	ELSE
  		count := count + DWORD_TO_INT(SHR(DINT_TO_DWORD(INT_TO_DINT(month) - INT_TO_DINT(4)),1));
  	END_IF;
  	(* chech for leap year and add one day if true *)
  	IF SHL(INT_TO_WORD(year),14) = WORD#0 THEN
  		count := count + 1;
  	END_IF;
  ELSE
  	count := (month - 1) * 31;
  END_IF;
  SET_DATE := (INT_TO_UDINT(count + day - 1) + DWORD_TO_UDINT(SHR(UDINT_TO_DWORD(INT_TO_UDINT(year) * UDINT#1461 - UDINT#2878169), 2))) * UDINT#86400;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION MONTH_END : UDINT
  VAR_INPUT
    IDATE : UDINT;
  END_VAR

  MONTH_END := SET_DATE(YEAR_OF_DATE(idate),MONTH_OF_DATE(idate)+1,1) - UDINT#86400;

  (* From OSCAT LIBRARY, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK TIMER_P4
  VAR_INPUT
    DTIME : UDINT;
    TREF_0 : UDINT;
    TREF_1 : UDINT;
    HOLY : BOOL;
    L0 : BOOL;
    L1 : BOOL;
    L2 : BOOL;
    L3 : BOOL;
    OFS : BYTE;
    ENQ : BOOL;
    MAN : BOOL;
    MI : BYTE;
    RST : BOOL;
  END_VAR
  VAR_IN_OUT
    PROG : ARRAY [0..63] OF TIMER_EVENT;
  END_VAR
  VAR_OUTPUT
    Q0 : BOOL;
    Q1 : BOOL;
    Q2 : BOOL;
    Q3 : BOOL;
    STATUS : BYTE;
  END_VAR
  VAR
    day_start : UDINT;
    start : UDINT;
    event : TIMER_EVENT;
    pos : INT;
    last_execute : UDINT;
    current_day : DINT;
    mask : BYTE;
    ma : ARRAY [0..3] OF BYTE;
    mo : ARRAY [0..3] OF BYTE;
    qn : ARRAY [0..3] OF BOOL;
    qs : ARRAY [0..3] OF BOOL;
    channel : INT;
    tx : UDINT;
    array_max : INT := 63;
    channel_max : INT := 3;
  END_VAR

  (* for performance reasons we only execute the code at the beginning of a new second *)

  IF RST THEN
  	(* reset all events to last active on 1.1.1970 *)
  	last_execute := UDINT#00; (* DT#1970-1-1-00:00 *)
  	FOR pos := 0 TO ARRAY_MAX DO
  		IF (PROG[pos].CHANNEL >= OFS) AND (BYTE_TO_INT(PROG[pos].CHANNEL) < (BYTE_TO_INT(OFS) + 4)) THEN PROG[pos].LAST := last_execute; END_IF;
  	END_FOR;

  	(* reset all set markers and logic masks *)
  	FOR pos := 0 TO channel_max DO
  		qs[pos] := FALSE;
  	END_FOR;

  (* normal operation *)
  ELSIF dtime <> last_execute THEN
  	(* save the actual second for next execution test *)
  	last_execute := DTIME;

  	(* calculate dt for the start of the day to be used in comparisons *)
  	day_start := DATE_TO_DT(_DT_TO_DATE(DTIME));

  	(* set all qn to FALSE *)
  	FOR pos := 0 TO channel_max DO qn[pos] := FALSE; END_FOR;

  	(* search the array PROG for timer events *)
  	FOR pos := 0 TO ARRAY_MAX DO
  		event := prog[pos];
  		channel := BYTE_TO_INT(event.CHANNEL) - BYTE_TO_INT(OFS);
  		IF (event.TYP > BYTE#0) AND (channel >= 0) AND (channel <= channel_max) THEN
  			ma[channel] := event.LAND;
  			mo[channel] := event.LOR;
  			CASE BYTE_TO_INT(event.TYP) OF
  				1:	(* daily event *)
  					start := day_start + event.start;
  					qn[channel] := dtime >= start AND dtime <= start + TIME_TO_UDINT(event.DURATION);

  				2: 	(* event by selected weekdays *)
  					IF (SHR(BYTE#128, DAY_OF_WEEK(_DT_TO_DATE(Dtime))) AND event.DAY) > BYTE#0 THEN
  						start := day_start + event.start;
  						qn[channel] := dtime >= start AND dtime <= start + TIME_TO_UDINT(event.DURATION);
  					END_IF;

  				3:	(* event every N days *)
  					IF current_day MOD BYTE_TO_DINT(event.DAY) = DINT#0 THEN
  						start := day_start + event.start;
  						qn[channel] := dtime >= start AND dtime <= start + TIME_TO_UDINT(event.DURATION);
  					END_IF;

  				10:	(* weekly event exactly once a week the weekday is specified in day, 1= mo *)
  					IF DAY_OF_WEEK(_DT_TO_DATE(DTIME)) = BYTE_TO_INT(event.DAY) THEN
  						start := day_start + event.start;
  						qn[channel] := dtime >= start AND dtime <= start + TIME_TO_UDINT(event.DURATION);
  					END_IF;

  				20:	(* monthly event *)
  					IF DAY_OF_MONTH(_DT_TO_DATE(DTIME)) = BYTE_TO_INT(event.DAY) THEN
  						start := day_start + event.start;
  						qn[channel] := dtime >= start AND dtime <= start + TIME_TO_UDINT(event.DURATION);
  					END_IF;

  				21:	(* event on last day of month *)
  					IF _DT_TO_DATE(DTIME) = MONTH_END(_DT_TO_DATE(dtime)) THEN
  						start := day_start + event.start;
  						qn[channel] := dtime >= start AND dtime <= start + TIME_TO_UDINT(event.DURATION);
  					END_IF;

  				30:	(* yearly event on a specific day specified in day *)
  					IF DAY_OF_YEAR(_DT_TO_DATE(DTIME)) = BYTE_TO_INT(event.DAY) THEN
  						start := day_start + event.start;
  						qn[channel] := dtime >= start AND dtime <= start + TIME_TO_UDINT(event.DURATION);
  					END_IF;

  				31:	(* event on last day of year *)
  					IF _DT_TO_DATE(DTIME) = YEAR_END(YEAR_OF_DATE(_DT_TO_DATE(dtime))) THEN
  						start := day_start + event.start;
  						qn[channel] := dtime >= start AND dtime <= start + TIME_TO_UDINT(event.DURATION);
  					END_IF;

  				40:	(* event on leap days *)
  					IF LEAP_DAY(_DT_TO_DATE(dtime)) THEN
  						start := day_start + event.start;
  						qn[channel] := dtime >= start AND dtime <= start + TIME_TO_UDINT(event.DURATION);
  					END_IF;

  				41: (* event on holidays *)
  					IF HOLY THEN
  						start := day_start + event.start;
  						qn[channel] := dtime >= start AND dtime <= start + TIME_TO_UDINT(event.DURATION);
  					END_IF;

  				42: (* event on holidays and weekends *)
  					IF (Holy OR (DAY_OF_WEEK(_DT_TO_DATE(dtime)) = 6) OR (DAY_OF_WEEK(_DT_TO_DATE(dtime)) = 7)) THEN
  						start := day_start + event.start;
  						qn[channel] := dtime >= start AND dtime <= start + TIME_TO_UDINT(event.DURATION);
  					END_IF;

  				43:	(* event on workdays Mo-FR and no holiday *)
  					IF DAY_OF_WEEK(_DT_TO_DATE(dtime)) < 6 THEN
  						start := day_start + event.start;
  						qn[channel] := dtime >= start AND dtime <= start + TIME_TO_UDINT(event.DURATION);
  					END_IF;

  				50: (* event after reference time *)
  					CASE BYTE_TO_INT(prog[pos].DAY) OF
  						0:	tx := tref_0;
  						1:	tx := tref_1;
  					ELSE
  						tx := UDINT#0 (* TOD#00:00 *);
  					END_CASE;
  					start := day_start + tx + event.start;
  					qn[channel] := dtime >= start AND dtime <= start + TIME_TO_UDINT(event.DURATION);

  				51:	(* event before reference time *)
  					CASE BYTE_TO_INT(prog[pos].DAY) OF
  						0:	tx := tref_0;
  						1:	tx := tref_1;
  					ELSE
  						tx := UDINT#0 (* TOD#00:00 *);
  					END_CASE;
  					start := day_start + tx - event.start;
  					qn[channel] := dtime >= start AND dtime <= start + TIME_TO_UDINT(event.DURATION);

  				52 : (* set output at specific time + offset  *)
  					CASE BYTE_TO_INT(prog[pos].DAY) OF
  						0:	tx := tref_0;
  						1:	tx := tref_1;
  					ELSE
  						tx := UDINT#0 (* TOD#00:00 *);
  					END_CASE;
  					start := day_start + tx + event.start;
  					IF dtime >= start AND day_start > event.LAST THEN
  						qs[channel] := TRUE;
  						prog[pos].LAST := day_start;
  					END_IF;

  				53 : (* reset output at specific time + offset *)
  					CASE BYTE_TO_INT(prog[pos].DAY) OF
  						0:	tx := tref_0;
  						1:	tx := tref_1;
  					ELSE
  						tx := UDINT#0 (* TOD#00:00 *);
  					END_CASE;
  					start := day_start + tx + event.start;
  					IF dtime >= start AND day_start > event.LAST THEN
  						qs[channel] := FALSE;
  						prog[pos].LAST := day_start;
  					END_IF;

  				54 : (* set output at specific time - offset  *)
  					CASE BYTE_TO_INT(prog[pos].DAY) OF
  						0:	tx := tref_0;
  						1:	tx := tref_1;
  					ELSE
  						tx := UDINT#0 (* TOD#00:00 *);
  					END_CASE;
  					start := day_start + tx - event.start;
  					IF dtime >= start AND day_start > event.LAST THEN
  						qs[channel] := TRUE;
  						prog[pos].LAST := day_start;
  					END_IF;

  				55 : (* reset output at specific time - offset *)
  					CASE BYTE_TO_INT(prog[pos].DAY) OF
  						0:	tx := tref_0;
  						1:	tx := tref_1;
  					ELSE
  						tx := UDINT#0 (* TOD#00:00 *);
  					END_CASE;
  					start := day_start + tx - event.start;
  					IF dtime >= start AND day_start > event.LAST THEN
  						qs[channel] := FALSE;
  						prog[pos].LAST := day_start;
  					END_IF;
  			END_CASE;
  		END_IF;
  	END_FOR;
  END_IF;

  (* prepare the logical input mask *)
  mask := BYTE#255;
  mask:=BIT_LOAD_B(mask,L0,0);
  mask:=BIT_LOAD_B(mask,L1,1);
  mask:=BIT_LOAD_B(mask,L2,2);
  mask:=BIT_LOAD_B(mask,L3,3);

  (* set the outputs *)
  Q0 := ENQ AND ((qn[0] OR qs[0]) AND ((ma[0] AND mask) = ma[0]) OR ((mo[0] AND mask) > BYTE#0) OR (man AND BIT_OF_DWORD(BYTE_TO_DWORD(MI),0)));
  Q1 := ENQ AND ((qn[1] OR qs[1]) AND ((ma[1] AND mask) = ma[1]) OR ((mo[1] AND mask) > BYTE#1) OR (man AND BIT_OF_DWORD(BYTE_TO_DWORD(MI),1)));
  Q2 := ENQ AND ((qn[2] OR qs[2]) AND ((ma[2] AND mask) = ma[2]) OR ((mo[2] AND mask) > BYTE#2) OR (man AND BIT_OF_DWORD(BYTE_TO_DWORD(MI),2)));
  Q3 := ENQ AND ((qn[3] OR qs[3]) AND ((ma[3] AND mask) = ma[3]) OR ((mo[3] AND mask) > BYTE#3) OR (man AND BIT_OF_DWORD(BYTE_TO_DWORD(MI),3)));

  (* set status *)
  IF NOT enq THEN
  	status := BYTE#100;
  ELSIF man THEN
  	status := BYTE#101;
  ELSE
  	status := BYTE#102;
  END_IF;

  (* From OSCAT LIBRARY, www.oscat.de *)
  (* several FB'S required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK DIMM_2
  VAR_INPUT
    SET : BOOL;
    VAL : BYTE := 255;
    I1 : BOOL;
    I2 : BOOL;
    RST : BOOL;
    T_DEBOUNCE : TIME := t#10ms;
    T_ON_MAX : TIME := t#0h;
    T_DIMM_START : TIME := t#1s;
    T_DIMM : TIME := t#3s;
    MIN_ON : BYTE := 50;
    MAX_ON : BYTE := 255;
    RST_OUT : BOOL;
    SOFT_DIMM : BOOL := TRUE;
    DBL1_TOG : BOOL;
    DBL2_TOG : BOOL;
    DBL1_SET : BOOL;
    DBL2_SET : BOOL;
    DBL1_POS : BYTE;
    DBL2_POS : BYTE;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
    D1 : BOOL;
    D2 : BOOL;
  END_VAR
  VAR_IN_OUT
    OUT : BYTE;
  END_VAR
  VAR
    t1 : TOF;
    t2 : TOF;
    t3 : TON;
    dc1 : CLICK_MODE;
    dc2 : CLICK_MODE;
    dim : _RMP_B;
  END_VAR

  (* debouncing for inputs i1 and i2 *)
  t1(IN := I1, PT := T_DEBOUNCE);
  t2(IN := I2, PT := T_DEBOUNCE);
  dc1(in := t1.Q, T_LONG := T_DIMM_START);
  dc2(in := t2.Q, T_LONG := T_DIMM_START);

  IF RST THEN
  	IF RST_OUT THEN out := BYTE#0; END_IF;
  	Q := FALSE;
  	D1 := FALSE;
  	D2 := FALSE;
  ELSIF set THEN
  	OUT := VAL;
  	Q := TRUE;
  ELSIF dc1.SINGLE THEN
  	(* single click on i1 turns the dimmer on *)
  	out := LIMIT(MAX(MIN_ON,BYTE#1), out, MAX_ON);
  	Q := TRUE;
  ELSIF dc2.SINGLE THEN
  	(* single click on i2 turns the dimmer off *)
  	Q := FALSE;
  ELSIF dc1.TP_LONG THEN
  	(* continuous on at i1 dimms up *)
  	IF NOT Q THEN
  		out := SEL(SOFT_DIMM, LIMIT(MAX(MIN_ON,BYTE#1), out, MAX_ON), BYTE#1);
  	END_IF;
  	Q := TRUE;
  	dim.DIR := TRUE;
  ELSIF dc2.TP_LONG THEN
  	(* continuous on at i2 dimms down *)
  	dim.DIR := FALSE;
  END_IF;

  (* set the double click output *)
  IF NOT DBL1_TOG THEN D1 := FALSE; END_IF;
  IF dc1.DOUBLE THEN
  	IF DBL1_SET THEN
  		OUT := DBL1_POS;
  		Q := TRUE;
  	ELSE
  		D1 := NOT D1;
  	END_IF;
  END_IF;
  IF NOT DBL2_TOG THEN D2 := FALSE; END_IF;
  IF dc2.DOUBLE THEN
  	IF DBL2_SET THEN
  		OUT := DBL2_POS;
  		Q := TRUE;
  	ELSE
  		D2 := NOT D2;
  	END_IF;
  END_IF;


  (* while dimming is active ramp the output out up or down *)
  dim(dir := dc2.LONG, _e := dc1.LONG OR dc2.LONG , TR := T_DIMM, rmp := out);
  out := dim.RMP;

  (* turn off output if a value of 0 is reached *)
  IF out = BYTE#0 THEN Q := FALSE; END_IF;

  (* limit the maximum runtime *)
  IF t_ON_MAX > t#0s THEN
  	t3(in := q, pt := T_ON_MAX);
  	Q := Q XOR t3.Q;
  END_IF;

  (* From OSCAT LIBRARY, www.oscat.de *)
  (* _RMP_B, CLICK_MODE, TOF required *)
END_FUNCTION_BLOCK

FUNCTION DT_TO_DATE_2 : UDINT
  VAR_INPUT
    IN : UDINT;
  END_VAR

  DT_TO_DATE_2 := (IN / UDINT#86400) * UDINT#86400;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

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

  (* From OSCAT Library, www.OSCAT.de *)
  (* T_PLC_MS, R2_ADD required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK ACTUATOR_PUMP
  VAR_INPUT
    IN : BOOL;
    MANUAL : BOOL;
    RST : BOOL := FALSE;
    MIN_ONTIME : TIME := t#10s;
    MIN_OFFTIME : TIME := t#10s;
    RUN_EVERY : TIME := t#10000m;
  END_VAR
  VAR_OUTPUT
    PUMP : BOOL;
    RUNTIME : UDINT;
    CYCLES : UDINT;
  END_VAR
  VAR
    tx : TIME;
    last_change : TIME;
    meter : ONTIME;
    old_man : BOOL;
    init : BOOL;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));

  IF NOT init THEN
  	init := TRUE;
  	last_change := tx;
  ELSIF rst THEN
  	rst := FALSE;
  	runtime := UDINT#0;
  	cycles := UDINT#0;
  ELSIF manual AND NOT pump AND NOT old_man THEN
  	last_change := tx;
  	pump := TRUE;
  ELSIF NOT manual AND old_man AND pump AND NOT in THEN
  	last_change := tx;
  	pump := FALSE;
  ELSIF in AND NOT pump AND tx - last_change >= min_offtime THEN
  	last_change := tx;
  	pump := TRUE;
  ELSIF pump AND NOT in AND NOT manual AND tx - last_change >= min_ontime THEN
  	last_change := tx;
  	pump := FALSE;
  ELSIF NOT pump AND (tx - last_change >= run_every) AND (run_every > T#0s) THEN
  	last_change := tx;
  	pump := TRUE;
  END_IF;

  meter(in := pump, SECONDS := runtime, CYCLES := cycles);
  cycles := meter.CYCLES;
  runtime := meter.SECONDS;

  old_man := manual;

  (* From OSCAT Library, www.OSCAT.de *)
  (* T_PLC_MS, ONTIME required *)
END_FUNCTION_BLOCK

FUNCTION TOD_TO_TIME : TIME
  VAR_INPUT
    IN : UDINT;
  END_VAR

  TOD_TO_TIME := DWORD_TO_TIME(UDINT_TO_DWORD(IN));

  (* From OSCAT LIBRARY, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK ACTUATOR_COIL
  VAR_INPUT
    IN : BOOL;
    SELF_ACT_CYCLE : TIME := t#10d;
    SELF_ACT_TIME : TIME := t#1s;
  END_VAR
  VAR_OUTPUT
    OUT : BOOL;
    STATUS : BYTE;
  END_VAR
  VAR
    last : UDINT;
    init : BOOL;
    tx : UDINT;
    now : UDINT;
  END_VAR

  now := T_PLC_MS(en:=true);

  (* initialize for first cycle *)
  IF NOT init THEN
  	last := now;
  	init := TRUE;
  ELSIF IN THEN
  	OUT := TRUE;
  	STATUS := BYTE#101; (* activated by input *)
  	LAST := now;
  ELSE
  	OUT := FALSE;
  	STATUS := BYTE#100; (* disabled *)
  	(* now we need to check for self activation *)
  	tx := now - last;
  	IF (self_act_cycle > T#0s) AND (tx >= TIME_TO_UDINT(self_act_cycle)) THEN
  		OUT := TRUE;
  		STATUS := BYTE#102; (* auto activation *)
  		IF tx >= TIME_TO_UDINT(self_act_cycle + self_act_time) THEN
  			last := now;
  			OUT := FALSE;
  			STATUS := BYTE#100; (* idle *)
  		END_IF;
  	END_IF;
  END_IF;

  (* From OSCAT Library, www.OSCAT.de *)
  (* T_PLC_MS required *)
END_FUNCTION_BLOCK

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

FUNCTION_BLOCK TANK_LEVEL
  VAR_INPUT
    LEVEL : BOOL;
    LEAK : BOOL;
    ACLR : BOOL;
    MAX_VALVE_TIME : TIME;
    LEVEL_DELAY_TIME : TIME;
  END_VAR
  VAR_OUTPUT
    VALVE : BOOL;
    ALARM : BOOL;
    STATUS : BYTE;
  END_VAR
  VAR
    cx : ACTUATOR_COIL;
    tn : TON;
    tl : TONOF;
    open : BOOL;
  END_VAR

  (* preprocess the level information *)
  tl(in := level, T_ON := level_delay_time, T_OFF := level_delay_time);
  open := tl.Q;

  (* start logic *)
  IF ALARM THEN
  	(* check for ACLR if ALARM is present *)
  	IF ACLR THEN
  		ALARM := FALSE;
  		STATUS := BYTE#101; (* aclr pressed *)
  		cx(in := FALSE);
  	END_IF;
  	RETURN;
  ELSIF LEAK THEN
  	(* leakeage detected *)
  	cx(in := FALSE);
  	ALARM := TRUE;
  	STATUS := BYTE#1;	(* leakeage error *)
  ELSIF open THEN
  	(* valve needs to be opened because level is too low *)
  	cx(in := TRUE);
  	STATUS := BYTE#102; (* valve open by low level *)
  ELSE
  	(* valve needs to be closed *)
  	cx(in := FALSE);
  	STATUS := BYTE#100; (* valve idle *)
  END_IF;

  (* check if valve is open too long and generate alarm if necessary *)
  tn(in := cx.out AND (MAX_VALVE_TIME > T#0s), PT := MAX_VALVE_TIME);
  IF tn.Q THEN
  	ALARM := TRUE;
  	STATUS := BYTE#2; (* overtime error *)
  	cx(in := FALSE);
  END_IF;

  (* set output signal *)
  VALVE := cx.out;

  (* From OSCAT Library, www.OSCAT.de *)
  (* TON, TONOF, ACTUATOR_COIL required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK BLIND_ACTUATOR
  VAR_INPUT
    UP : BOOL;
    DN : BOOL;
    S_IN : BYTE;
    T_UD : TIME := t#10s;
    T_ANGLE : TIME := t#3s;
    T_LOCKOUT : TIME := t#100ms;
  END_VAR
  VAR_OUTPUT
    POS : BYTE;
    ANG : BYTE;
    QU : BOOL;
    QD : BOOL;
    STATUS : BYTE;
  END_VAR
  VAR
    position : RMP_B;
    angle : RMP_B;
    lock : INTERLOCK;
  END_VAR

  (* make sure only one motor is active at a given time *)
  lock(i1 := UP, I2 := DN, TL := T_lockout);

  (* ramp up or down to simulate the angle position of the blind slats *)
  angle(_e := lock.Q1 OR lock.Q2, UP := lock.Q1, PT := T_Angle);
  position(_e := lock.Q1 AND angle.high OR lock.Q2 AND angle.low, up := lock.Q1, PT := T_UD);

  (* set the outputs *)
  pos := position.Out;
  ang := angle.Out;

  (* set the outputs *)
  QU := lock.Q1;
  QD := lock.Q2;

  (* set the status output *)
  IF UP AND DN THEN
  	 status := BYTE#1;			(* error up and down together are not allowed *)
  ELSIF UP THEN
  	status := BYTE#121;
  ELSIF DN THEN
  	status := BYTE#122;
  ELSE
  	status := S_IN;
  END_IF;

  (* From OSCAT LIBRARY, www.oscat.de *)
  (* INTERLOCK, RMP_B required *)
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

FUNCTION_BLOCK TIMER_EXT
  VAR_INPUT
    ENA : BOOL;
    _ON : BOOL;
    OFF : BOOL;
    MAN : BOOL;
    SWITCH : BOOL;
    DT_IN : UDINT;
    SUN_SET : UDINT;
    SUN_RISE : UDINT;
    HOLIDAY : BOOL;
    T_DEBOUNCE : TIME := t#100ms;
    T_RISE_START : TIME;
    T_RISE_STOP : TIME;
    T_SET_START : TIME;
    T_SET_STOP : TIME;
    T_DAY_START : UDINT;
    T_DAY_STOP : UDINT;
    ENABLE_SATURDAY : BOOL;
    ENABLE_SUNDAY : BOOL;
    ENABLE_HOLIDAY : BOOL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
    STATUS : BYTE;
  END_VAR
  VAR
    mx : MANUAL_2;
    deb : DEBOUNCE;
    tdx : UDINT;
    wdx : INT;
    tc : TIME;
    tx : UDINT;
    tl : UDINT;
    qx : BOOL;
    init : BOOL;
  END_VAR

  (* lösche die millisekunden bei sunrise und sunset *)
  SUN_RISE := SUN_RISE / UDINT#1000 * UDINT#1000;
  SUN_SET := SUN_SET / UDINT#1000 * UDINT#1000;

  (* measure cycle time tc and make sure this circuitry is not called more then once in 200ms*)
  tx:= T_PLC_MS(en:=true);
  IF NOT init THEN
  	init := TRUE;
  	tl := tx;
  END_IF;
  tc := UDINT_TO_TIME(tx - tl);
  IF tc < t#200ms THEN RETURN; END_IF;
  tl := tx;

  (* debounce *)
  deb(in := SWITCH, TD := T_DEBOUNCE, PM := TRUE);

  (* read time of day and strip off all milliseconds *)
  tdx := _DT_TO_TOD(dt_in);
  wdx := DAY_OF_WEEK(_DT_TO_DATE(dt_in));

  (* automatic output control *)
  IF deb.Q THEN
  	qx := NOT qx;
  	status := BYTE#110;
  ELSIF holiday AND NOT enable_holiday THEN
  	qx := FALSE;
  ELSIF wdx = 6 AND NOT enable_saturday THEN
  	qx := FALSE;
  ELSIF wdx = 7 AND NOT enable_sunday THEN
  	qx := FALSE;
  ELSIF T_day_start > UDINT#00 (* TOD#00:00 *) AND tdx - T_DAY_START <= TIME_TO_UDINT(tc) THEN
  	(* turn on at specified daytime *)
  	qx := TRUE;
  	status := BYTE#111;
  ELSIF T_DAY_STOP > UDINT#00 (* TOD#00:00 *) AND tdx - T_DAY_STOP <= TIME_TO_UDINT(tc) THEN
  	(* turn off at specific daytime *)
  	qx := FALSE;
  	status := BYTE#112;
  ELSIF T_RISE_START > T#0s AND tdx - SUN_RISE + TIME_TO_UDINT(T_RISE_START) <= TIME_TO_UDINT(tc) THEN
  	(* turn on before sunrise *)
  	qx := TRUE;
  	status := BYTE#113;
  ELSIF T_RISE_STOP > T#0s AND tdx - SUN_RISE - TIME_TO_UDINT(T_RISE_STOP) <= TIME_TO_UDINT(tc) THEN
  	(* turn off after sunrise *)
  	qx := FALSE;
  	status := BYTE#114;
  ELSIF T_SET_start > T#0s AND tdx - SUN_SET + TIME_TO_UDINT(T_SET_START) <= TIME_TO_UDINT(tc) THEN
  	(* turn on before sunset *)
  	qx := TRUE;
  	status := BYTE#115;
  ELSIF T_SET_STOP > T#0s AND tdx - SUN_SET - TIME_TO_UDINT(T_SET_STOP) <= TIME_TO_UDINT(tc) THEN
  	(* turn off after sunset *)
  	qx := FALSE;
  	status := BYTE#116;
  END_IF;

  (* manual and output control *)
  mx(in := qx, ena := ENA, _on := _ON, off := OFF, man := MAN);
  Q := mx.Q;

  (* set the status output *)
  IF mx.STATUS > BYTE#100 THEN status := mx.STATUS; END_IF;
    
  (* From OSCAT LIBRARY, www.oscat.de *)
  (* DEBOUNCE, T_PLC_MS, MANUAL_" required *)
END_FUNCTION_BLOCK

FUNCTION MID3 : REAL
  VAR_INPUT
    IN1 : REAL;
    IN2 : REAL;
    IN3 : REAL;
  END_VAR
  VAR
    _IN1 : REAL;
    _IN2 : REAL;
    _IN3 : REAL;
  END_VAR

  _IN1 := IN1; (* VAR_INPUT auf Variablen umkopieren , da diese schreibgeschützt sind *)
  _IN2 := IN2;
  _IN3 := IN3;

  IF _IN1 > _IN2 THEN MID3 := _IN1; _IN1 := _IN2; _IN2 := MID3; END_IF;
  IF _IN2 > _IN3 THEN _IN2 := _IN3; END_IF;
  MID3 := SEL(_IN1 > _IN2, _IN2, _IN1);
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION MULTI_IN : REAL
  VAR_INPUT
    IN_1 : REAL;
    IN_2 : REAL;
    IN_3 : REAL;
    DEFAULT : REAL;
    IN_MIN : REAL;
    IN_MAX : REAL;
    MODE : BYTE;
  END_VAR
  VAR
    count : INT;
    F1 : BOOL;
    F2 : BOOL;
    F3 : BOOL;
  END_VAR

  F1 :=  in_1 > in_min AND in_1 < in_max;
  F2 :=  in_2 > in_min AND in_2 < in_max;
  F3 :=  in_3 > in_min AND in_3 < in_max;

  CASE BYTE_TO_INT(mode) OF
  0:	count := 0;
  	IF F1 THEN
  		count := count + 1;
  		MULTI_IN := in_1;
  	ELSE
  		MULTI_IN := 0.0;
  	END_IF;
  	IF F2 THEN
  		count := count + 1;
  		MULTI_IN := MULTI_IN + in_2;
  	END_IF;
  	IF F3 THEN
  		count := count + 1;
  		MULTI_IN := MULTI_IN + in_3;
  	END_IF;
  	MULTI_IN := SEL(count = 0, MULTI_IN / INT_TO_REAL(count), default);

  1:	MULTI_IN := SEL(F1, default, IN_1);

  2:	MULTI_IN := SEL(F2, default, IN_2);

  3:	MULTI_IN := SEL(F3, default, IN_3);

  4:	MULTI_IN := default;

  5:	MULTI_IN := SEL(F1, in_max, IN_1);
  	IF F2 AND in_2 < MULTI_IN THEN MULTI_IN := in_2; END_IF;
  	IF F3 AND in_3 < MULTI_IN THEN MULTI_IN := in_3; END_IF;
  	IF MULTI_IN = in_max THEN MULTI_IN := default; END_IF;

  6:	MULTI_IN := SEL(F1, in_min, IN_1);
  	IF F2 AND in_2 > MULTI_IN THEN MULTI_IN := in_2; END_IF;
  	IF F3 AND in_3 > MULTI_IN THEN MULTI_IN := in_3; END_IF;
  	IF MULTI_IN = in_min THEN MULTI_IN := default; END_IF;

  7:	IF F1 AND F2 AND F3 THEN MULTI_IN := MID3(in_1, in_2, in_3);
  	ELSIF F1 AND F2 THEN MULTI_IN := MIN(in_1, in_2);
  	ELSIF F1 AND F3 THEN MULTI_IN := MIN(in_1, in_3);
  	ELSIF F2 AND F3 THEN MULTI_IN := MIN(in_2, in_3);
  	ELSIF F1 THEN MULTI_IN := in_1;
  	ELSIF F2 THEN MULTI_IN := in_2;
  	ELSIF F3 THEN MULTI_IN := in_3;
  	ELSE MULTI_IN := default;
  	END_IF;

  END_CASE;

  (* From OSCAT Library, www.oscat.de *)
  (* MID3 required *)
END_FUNCTION

FUNCTION_BLOCK BLIND_NIGHT
  VAR_INPUT
    UP : BOOL;
    DN : BOOL;
    S_IN : BYTE;
    PI : BYTE;
    AI : BYTE;
    E_NIGHT : BOOL := TRUE;
    E_DAY : BOOL := TRUE;
    DTIN : UDINT;
    SUNRISE : UDINT;
    SUNSET : UDINT;
    SUNRISE_OFFSET : TIME;
    SUNSET_OFFSET : TIME;
    NIGHT_POSITION : BYTE;
    NIGHT_ANGLE : BYTE;
  END_VAR
  VAR_OUTPUT
    QU : BOOL;
    QD : BOOL;
    STATUS : BYTE;
    PO : BYTE;
    AO : BYTE;
  END_VAR
  VAR
    night : BOOL;
    last_night : UDINT;
    last_day : UDINT;
  END_VAR

  IF NOT (up AND dn) AND night THEN
  	(* manual operation at night will cancel operation for one night *)
  	night := FALSE;
  ELSIF (_DT_TO_TOD(dtin) > sunset + TIME_TO_UDINT(sunset_offset)) AND (last_night < _DT_TO_DATE(dtin)) AND NOT night AND e_night THEN
  	(* enable night *)
  	night := TRUE;
  	last_night := _DT_TO_DATE(dtin);
  ELSIF (_DT_TO_TOD(dtin) > sunrise + TIME_TO_UDINT(sunrise_offset)) AND (last_day < _DT_TO_DATE(dtin)) AND night AND e_day AND (last_night < _DT_TO_DATE(dtin)) THEN
  	(* disable night *)
  	night := FALSE;
  	last_day := _DT_TO_DATE(dtin);
  END_IF;

  (* shade at night only in auto mode and enable = true *)
  IF UP AND DN AND night THEN
  	status := BYTE#141;
  	po := night_position;
  	ao := night_angle;
  ELSE
  	QU := UP;
  	QD := DN;
  	po := pi;
  	ao := ai;
  	status := s_in;
  END_IF;

  (* From OSCAT LIBRARY, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK BLIND_SECURITY
  VAR_INPUT
    UP : BOOL;
    DN : BOOL;
    S_IN : BYTE;
    PI : BYTE;
    AI : BYTE;
    FIRE : BOOL;
    WIND : BOOL;
    ALARM : BOOL;
    DOOR : BOOL;
    RAIN : BOOL;
    ALARM_UP : BOOL := TRUE;
    WIND_UP : BOOL := TRUE;
    RAIN_UP : BOOL := TRUE;
    QU : BOOL;
    QD : BOOL;
    STATUS : BYTE;
    PO : BYTE;
    AO : BYTE;
  END_VAR

  IF Fire THEN
  	QU := TRUE;
  	QD := FALSE;
  	status := BYTE#111;
  ELSIF Wind THEN
  	QU := Wind_up;
  	QD := NOT wind_up;
  	status := BYTE#112;
  ELSIF alarm THEN
  	QU := Alarm_up;
  	QD := NOT Alarm_up;
  	status := BYTE#113;
  ELSIF Door THEN
  	QU := TRUE;
  	QD := FALSE;
  	status := BYTE#114;
  ELSIF Rain AND NOT (up XOR dn) THEN
  	QU := rain_up;
  	QD := NOT rain_up;
  	status := BYTE#115;
  ELSE
  	QU := UP;
  	QD := DN;
  	status := S_IN;
  	po := pi;
  	ao := ai;
  END_IF;

  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION_BLOCK

FUNCTION TIME_TO_TOD : UDINT
  VAR_INPUT
    IN : TIME;
  END_VAR

  TIME_TO_TOD := DWORD_TO_UDINT(TIME_TO_DWORD(IN));


  (* From OSCAT LIBRARY, www.oscat.de *)
END_FUNCTION

FUNCTION WATER_CP : REAL
  VAR_INPUT
    _T : REAL;
  END_VAR
  VAR
    Pts : INT := 10;
    data : ARRAY [1..20,0..1] OF REAL := [0, 4.228, 5.0, 4.20, 10.0, 4.188, 15.0, 4.184, 50.0, 4.181, 60.0, 4.183, 70.0, 4.187, 80.0, 4.194, 90.0, 4.204, 100.0, 4.22];
  END_VAR

  WATER_CP := LINEAR_INT(_T, Data, pts);

  (* From OSCAT LIBRARY, www.oscat.de *)
  (* LINEAR_INT required *)
END_FUNCTION

FUNCTION AIR_DENSITY : REAL
  VAR_INPUT
    _T : REAL;
    P : REAL;
    RH : REAL;
  END_VAR

  AIR_DENSITY := 101325.0 * (1.0 - RH * SDD(_T, TRUE) * 3.773319E-3 / P) / (287.05 * ( _T - -273.15));

  (* From OSCAT Library, www.OSCAT.de *)
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

  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK _RMP_NEXT
  VAR_INPUT
    _E : BOOL := TRUE;
    IN : BYTE;
    TR : TIME;
    TF : TIME;
    TL : TIME;
  END_VAR
  VAR_OUTPUT
    DIR : BOOL;
    UP : BOOL;
    DN : BOOL;
  END_VAR
  VAR_IN_OUT
    OUT : BYTE;
  END_VAR
  VAR
    rmx : _RMP_B;
    dirx : TREND_DW;
    t_lock : TP;
    xen : BOOL;
    xdir : BOOL;
  END_VAR

  dirx(X := BYTE_TO_DWORD(in));

  t_lock(in := FALSE, pt := TL);

  IF dirx.TU AND (OUT < IN) THEN
  	IF NOT xdir AND xen THEN t_lock(in := TRUE); END_IF;
  	xen := TRUE;
  	xdir := TRUE;
  ELSIF dirx.TD AND (OUT > IN) THEN
  	IF xdir AND xen THEN t_lock(in := TRUE); END_IF;
  	xen := TRUE;
  	xdir := FALSE;
  ELSIF xen THEN
  	IF (xdir AND (out >= in)) OR (NOT xdir AND (out <= in)) THEN
  		xen := FALSE;
  		IF tl > t#0s THEN t_lock(IN := TRUE); END_IF;
  	END_IF;
  END_IF;

  IF NOT t_lock.Q AND xen THEN
  	UP := XDIR;
  	DIR := XDIR;
  	DN := NOT XDIR;
  ELSE
  	UP := FALSE;
  	DN := FALSE;
  END_IF;

  rmx(rmp := OUT, _E := _E AND (UP OR DN) , dir := DIR, tr := SEL(dir, TF, TR));
  OUT := rmx.RMP;

  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK BLIND_CONTROL_S
  VAR_INPUT
    UP : BOOL;
    DN : BOOL;
    S_IN : BYTE := 125;
    PI : BYTE;
    T_UP : TIME;
    T_DN : TIME;
    RU : BOOL;
    RD : BOOL;
    T_LOCKOUT : TIME := t#100ms;
    T_EXT : TIME;
    EXT_TRIG : BYTE := 5;
    R_POS_TOP : BYTE := 255;
    R_POS_BOT : BYTE;
  END_VAR
  VAR_OUTPUT
    POS : BYTE;
    MU : BOOL;
    MD : BOOL;
    STATUS : BYTE;
  END_VAR
  VAR
    rmp : _RMP_NEXT;
    tx : TIME;
    last : TIME;
    pi_last : BYTE;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));

  (* check inputs and start state machine *)
  IF UP  AND NOT DN THEN
  	(*  manual UP *)
  	rmp.IN := BYTE#255;
  	STATUS := BYTE#121;
  ELSIF DN AND NOT UP THEN
  	(* manual DN *)
  	rmp.IN := BYTE#0;
  	STATUS := BYTE#122;
  ELSIF NOT (UP OR DN) THEN
  	(* manual standby mode *)
  	rmp.IN := PI;
  	STATUS := S_IN;
  END_IF;

  (* simulate pos output *)
  rmp(_E := UP OR DN, TR := T_UP, TF := T_DN, TL := T_LOCKOUT, OUT := POS);
  pos := rmp.OUT;

  (* state machine *)
  CASE BYTE_TO_INT(STATUS) OF
  	0:		(* power up init *)
  		last := tx;
  		PI_last := PI XOR BYTE#255;
  		STATUS := BYTE#128;		(* calibrate *)

  	121: 	(* manual up *)
  		MU := TRUE;
  		MD := FALSE;
  		IF POS >= USINT_TO_BYTE(USINT#255 - BYTE_TO_USINT(EXT_TRIG)) THEN
  			(* extend cycle if top is reached *)
  			POS := BYTE#255;
  			last := tx;
  			STATUS := BYTE#129;	(* extend *)
  		END_IF;

  	122:	(* manual down *)
  		MD := TRUE;
  		MU := FALSE;
  		IF POS <= EXT_TRIG THEN
  			(* extend cycle if bottom is reached *)
  			POS := BYTE#0;
  			last := tx;
  			STATUS := BYTE#129;	(* extend *)
  		END_IF;

  	123:	(* auto positioning *)
  		MD := rmp.DN;
  		MU := rmp.UP;
  		IF NOT (rmp.DN OR rmp.UP) THEN
  			(* automatic position is reached *)
  			IF POS <= EXT_TRIG THEN
  				(* extend at bottom *)
  				MD := TRUE;
  				last := tx;
  				STATUS := BYTE#129;	(* extend *)
  			ELSIF POS >= USINT_TO_BYTE(USINT#255 - BYTE_TO_USINT(EXT_TRIG)) THEN
  				(* extend at top *)
  				MU := TRUE;
  				last := tx;
  				STATUS := BYTE#129;	(* extend *)
  			ELSE
  				STATUS := S_IN;
  			END_IF;
  		END_IF;

  	124:	(* revert from top or bottom *)
  		MD := rmp.DN;
  		MU := rmp.UP;
  		IF NOT(rmp.DN OR rmp.UP) THEN
  (*		IF POS = rmp.IN THEN  *)
  			PI_last := PI;
  			STATUS := S_IN;
  		END_IF;

  	127:	(* lockout time *)
  		IF (tx - last) >= T_LOCKOUT THEN
  				STATUS := S_IN;
  		END_IF;

  	128:	(* calibration *)
  		MU := TRUE;
  		MD := FALSE;
  		rmp.IN := BYTE#255;
  		IF (tx - last) >= (T_UP +  T_EXT) THEN
  			MU := FALSE;
  			last := tx;
  			STATUS := BYTE#127;	(* lockout *)
  		END_IF;

  	129: (* extend mode *)
  		IF (tx - last) >= T_EXT THEN
  			MU := FALSE;
  			MD := FALSE;
  			last := tx;
  			STATUS := BYTE#127;	(* lockout *)
  		END_IF;

  ELSE
  	MU := FALSE;
  	MD := FALSE;
  	IF PI <> PI_last THEN
  		PI_last := PI;
  		rmp.IN := PI;
  		STATUS := BYTE#123;	(* auto positioning *)
  	ELSIF POS = BYTE#0 AND RU THEN
  		rmp.IN := R_POS_BOT;
  		STATUS := BYTE#124;	(* revert *)
  	ELSIF pos = BYTE#255 AND RD THEN
  		rmp.IN := R_POS_TOP;
  		STATUS := BYTE#124;	(* revert *)
  	ELSE
  		STATUS := S_IN;
  	END_IF;
  END_CASE;

  (* From OSCAT LIBRARY, www.oscat.de *)
  (* T_PLC_MS, _RMP_NEXT required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK HYST_1
  VAR_INPUT
    IN : REAL;
    HIGH : REAL;
    LOW : REAL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
    WIN : BOOL;
  END_VAR

  IF in < low THEN
  	Q := FALSE;
  	win := FALSE;
  ELSIF in > high THEN
  	Q := TRUE;
  	win := FALSE;
  ELSE
  	win := TRUE;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK TIMER_1
  VAR_INPUT
    _E : BOOL := TRUE;
    DTI : UDINT;
    START : UDINT;
    DURATION : TIME;
    DAY : BYTE := 2#0111_1111;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
    STOP : TIME;
  END_VAR

  IF _E THEN
  	stop := TOD_TO_TIME(START) + DURATION;
  	IF stop > T#24h THEN stop := stop - T#24h; END_IF;
  	Q := TIMECHECK(_DT_TO_TOD(DTI), START, TIME_TO_TOD(stop)) AND (SHR(BYTE#128, DAY_OF_WEEK(_DT_TO_DATE(DTI))) AND DAY) > BYTE#0;
  ELSE
  	Q := FALSE; (* clear output when e is not true *)
  END_IF;

  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK TIMER_2
  VAR_INPUT
    DT_IN : UDINT;
    START : UDINT;
    DURATION : TIME;
    MODE : BYTE;
    HOLIDAY : BOOL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
  END_VAR
  VAR
    last_check : TIME := t#0s;
    dat : UDINT;
    daytime : UDINT;
    activation : TIME;
    tx : TIME;
    enabled : BOOL;
    wday : INT;
    init : BOOL;
  END_VAR
  VAR RETAIN
    run_date : UDINT;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));

  IF NOT init THEN
  	init := TRUE;
  	last_check := tx - t#100ms;
  END_IF;

  (* for performance resons exit if execution is not necessary *)
  IF tx - last_check < T#100ms THEN RETURN; END_IF;

  (* calculate temp variables *)
  dat := _DT_TO_DATE(dt_in);
  daytime := _DT_TO_TOD(dt_in);
  wday := DAY_OF_WEEK(dat);

  (* calculate if any action is necessary today *)
  CASE BYTE_TO_INT(mode) OF
  1..7:	(* mondays to fridays *)
  	enabled := wday = BYTE_TO_INT(mode);
  11:	(* every day *)
  	enabled := TRUE;
  12..16:	(* every nth day *)
  	enabled := (dat / UDINT#86400) MOD (BYTE_TO_UDINT(mode) - UDINT#10) = UDINT#0;
  20:	(* monday - friday *)
  	enabled := wday <= 5;
  21:	(* saturday and sunday *)
  	enabled := wday > 5;
  22: (* workdays only *)
  	enabled := wday <= 5 AND NOT holiday;
  23:	(* holidays and weekends *)
  	enabled := wday > 5 OR holiday;
  24:	(* holidays only *)
  	enabled := holiday;
  25:	(* 1st day of the month *)
  	enabled := DAY_OF_MONTH(dat) = 1;
  26:	(* last day of month *)
  	enabled := day_of_month(dat + TIME_TO_UDINT(t#1d)) = 1;
  27:	(* 31st of december *)
  	enabled := DAY_OF_MONTH(dat) = 31 AND MONTH_OF_DATE(dat) = 12;
  28:	(* 1st of january *)
  	enabled := DAY_OF_YEAR(dat) = 1;
  ELSE
  	enabled := FALSE;
  END_CASE;

  (* set output if necessary *)
  IF enabled AND NOT Q AND daytime >= start AND run_date <> dat THEN
  	Q := TRUE;
  	activation := tx;
  	run_date := dat;
  ELSIF Q AND tx - activation >= duration THEN
  	Q := FALSE;
  END_IF;
  last_check := Tx;

  (* From OSCAT LIBRARY, www.oscat.de *)
  (* T_PLC_MS required *)
END_FUNCTION_BLOCK

FUNCTION CIRCLE_SEG : REAL
  VAR_INPUT
    RX : REAL;
    HX : REAL;
  END_VAR

  IF RX > 0.0 THEN
  	CIRCLE_SEG := 2.0 * ACOS(1.0 - LIMIT(0.0, HX / RX, 2.0));
  	CIRCLE_SEG := (CIRCLE_SEG - SIN(CIRCLE_SEG)) * RX * RX * 0.5;
  END_IF;

  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION

FUNCTION BAND_B : BYTE
  VAR_INPUT
    X : BYTE;
    B : BYTE;
  END_VAR

  IF X < B THEN
  	BAND_B := BYTE#0;
  ELSIF X > USINT_TO_BYTE(USINT#255 - BYTE_TO_USINT(B)) THEN
  	BAND_B := BYTE#255;
  ELSE
  	BAND_B := X;
  END_IF;

  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION

FUNCTION_BLOCK BLIND_SET
  VAR_INPUT
    UP : BOOL;
    DN : BOOL;
    S_IN : BYTE;
    PI : BYTE;
    AI : BYTE;
    PX : BYTE;
    AX : BYTE;
    IN : BOOL;
    OVERRIDE_MANUAL : BOOL;
    RESTORE_POSITION : BOOL;
    RESTORE_TIME : TIME := t#60s;
  END_VAR
  VAR_OUTPUT
    QU : BOOL;
    QD : BOOL;
    STATUS : BYTE;
    PO : BYTE;
    AO : BYTE;
  END_VAR
  VAR
    tx : TIME;
    last : TIME;
    ps : BYTE;
    as : BYTE;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));
  (* check inputs *)
  IF IN THEN
  	IF override_manual OR (UP AND DN) THEN
  		status := 178;
  	END_IF;
  END_IF;

  (* state machine *)
  CASE byte_to_int(STATUS) OF
  	0: (* power on state *)
  		status := S_IN;

  	178: (* force values from PX and AX *)
  		PO := PX;
  		AO := AX;
  		QU := TRUE;
  		QD := TRUE;
  		(* check for end of forced position *)
  		IF NOT in THEN
  			STATUS := SEL(RESTORE_POSITION, S_IN, 179);
  			last := tx;
  		END_IF;

  	179: (* restore previous position *)
  		PO := ps;
  		AO := as;
  		IF ((PO = PI) AND (AO = AI))  OR tx - last >= RESTORE_TIME THEN
  			status := S_IN;
  		END_IF;

  ELSE
  	(* no operation transfer inputs to outputs *)
  	PO := PI;
  	ps := PI;
  	AO := AI;
  	as := AI;
  	STATUS := S_IN;
  	QU := UP;
  	QD := DN;
  END_CASE;


  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION_BLOCK

FUNCTION EXP10 : REAL
  VAR_INPUT
    x : REAL;
  END_VAR

  exp10 := EXP(X * 2.30258509299405);
  (* from OSCAT library; www.OSCAT.de  *)
END_FUNCTION

FUNCTION DEW_TEMP : REAL
  VAR_INPUT
    RH : REAL;
    _T : REAL;
  END_VAR
  VAR
    V : REAL;
  END_VAR

  IF rh > 0.0 THEN
  	V := LOG(RH * 0.01 * EXP10((7.5*_T) / (237.3+_T)));
  	DEW_TEMP := 237.3*V / (7.5-V);
  ELSE
  	DEW_TEMP:= -273.15;
  END_IF;
END_FUNCTION

FUNCTION SDT_NH3 : REAL
  VAR_INPUT
    P : REAL;
  END_VAR

  IF P < 1.0E-3 THEN
  	SDT_NH3 := -110.0;
  ELSIF P < 1.0 THEN
  	SDT_NH3 := 506.713 / (3.18757 - LOG(P)) - 192.37 ;
  ELSE
  	SDT_NH3 := 1113.928 / (4.86886 - LOG(P)) - 262.71 ;
  END_IF;

  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION

FUNCTION F_TO_C : REAL
  VAR_INPUT
    FAHRENHEIT : REAL;
  END_VAR

  F_TO_C := (fahrenheit - 32.0) * 0.5555555555555;

  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION

FUNCTION HEAT_INDEX : REAL
  VAR_INPUT
    _T : REAL;
    RH : REAL;
  END_VAR
  VAR
    RH2 : REAL;
    T2 : REAL;
    TX : REAL;
  END_VAR

  IF RH < 20.0 OR _T < 20.0 THEN
  	HEAT_INDEX := _t;
  ELSE
  	TX := _T;
  	RH2 := RH * RH;
  	TX := C_TO_F(TX);
  	T2 := TX * TX;
  	HEAT_INDEX := -42.379 + 2.04901523 * TX - 6.83783E-3 * T2
  			+ RH * (10.1433127 - 0.22475541 * TX + 1.22874E-3 * T2)
  			+ RH2 * (8.5282E-4 * TX - 5.481717E-2 - 1.99E-6 * T2);
  	HEAT_INDEX := F_TO_C(HEAT_INDEX);
  END_IF;

  (* From OSCAT Library, www.OSCAT.de *)
  (* C_TOF, F_TOC required *)
END_FUNCTION

FUNCTION_BLOCK AUTORUN
  VAR_INPUT
    IN : BOOL;
    TEST : BOOL;
    ARE : BOOL := TRUE;
    TRUN : TIME;
    TOFF : TIME;
  END_VAR
  VAR_OUTPUT
    OUT : BOOL;
    ARO : BOOL;
  END_VAR
  VAR_IN_OUT
    ARX : BOOL;
  END_VAR
  VAR
    timer : _RMP_B;
    val : BYTE;
  END_VAR

  (* run the integrator when T_off > T#0s *)
  IF TOFF > T#0s THEN
  	timer(DIR:= OUT, TR := SEL(OUT, TOFF, TRUN), RMP := val);
  	val := timer.RMP;
  ELSE
  	val := BYTE#255;
  END_IF;


  (* when timer = 0 or test then initiate autorun until timer reaches 255 *)
  IF (NOT ARX AND ARE AND val = BYTE#0) OR TEST THEN
  	val := BYTE#0;
  	ARO := TRUE;
  	ARX := TRUE;
  ELSIF val = BYTE#255 AND ARO THEN
  	ARO := FALSE;
  	ARX := FALSE;
  END_IF;

  (* output is true when autorun ARO is true or in = TRUE *)
  out := IN OR ARO;

  (* From OSCAT Library, www.OSCAT.de *)
  (* _RMP_B required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK BLIND_SHADE_S
  VAR_INPUT
    UP : BOOL;
    DN : BOOL;
    PI : BYTE;
    S_IN : BYTE;
    ENABLE : BOOL;
    SUN : BOOL;
    HORZ1 : REAL := 100.0;
    HORZ2 : REAL := 260.0;
    VERT : REAL := 90.0;
    ALERT : BOOL;
    SUNRISE_OFFSET : TIME := t#1h;
    SUNSET_PRESET : TIME := t#1h;
    SHADE_DELAY : TIME := t#60s;
    SHADE_POS : BYTE;
  END_VAR
  VAR_OUTPUT
    QU : BOOL;
    QD : BOOL;
    STATUS : BYTE;
    PO : BYTE;
  END_VAR
  VAR_IN_OUT
    CX : OSCAT_CALENDAR;
  END_VAR
  VAR
    sun_delay : TOF;
  END_VAR

  (* status definition
     151 = shadow               move shutter down for shadowing
     152 = alert                  move shutter up by setting QU:=TRUE when door is open.
  *)

  (* the input sun is sent through tof which will delay the shade for the time shade_delay *)
  sun_delay(IN := sun, PT := shade_delay);

  IF ALERT THEN
     QU := TRUE;
     QD := FALSE;
     STATUS := BYTE#152;
  ELSIF UP AND DN AND ENABLE AND sun_delay.Q
  AND (CX.SUN_HOR > HORZ1) AND (CX.SUN_HOR < HORZ2)
  AND (CX.SUN_VER < VERT)
  AND (_DT_TO_TOD(CX.UTC) > CX.SUN_RISE + time_to_udint(sunrise_offset)) AND (_DT_TO_TOD(CX.UTC) < CX.SUN_SET - time_to_udint(sunset_preset)) THEN
     QU := UP;
     QD := DN;
     STATUS := BYTE#151;
     (* Calculate Position, must be shade_pos or less *)
     PO := MIN(PI, shade_pos);
  ELSE
     QU := UP;
     QD := DN;
     PO := PI;
     STATUS := S_IN;
  END_IF;

  (* From OSCAT Library, www.OSCAT.de *)
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

FUNCTION_BLOCK LEGIONELLA
  VAR_INPUT
    MANUAL : BOOL;
    TEMP_BOILER : REAL;
    TEMP_RETURN : REAL := 100.0;
    DT_IN : UDINT;
    RST : BOOL;
    T_START : UDINT := 10800000;
    DAY : INT := 7;
    TEMP_SET : REAL := 70.0;
    TEMP_OFFSET : REAL := 10.0;
    TEMP_HYS : REAL := 5.0;
    T_MAX_HEAT : TIME := t#10m;
    T_MAX_RET : TIME := t#10m;
    TP_0 : TIME := t#5m;
    TP_1 : TIME := t#5m;
    TP_2 : TIME := t#5m;
    TP_3 : TIME := t#5m;
    TP_4 : TIME := t#5m;
    TP_5 : TIME := t#5m;
    TP_6 : TIME := t#5m;
    TP_7 : TIME := t#5m;
  END_VAR
  VAR_OUTPUT
    HEAT : BOOL;
    PUMP : BOOL;
    VALVE0 : BOOL;
    VALVE1 : BOOL;
    VALVE2 : BOOL;
    VALVE3 : BOOL;
    VALVE4 : BOOL;
    VALVE5 : BOOL;
    VALVE6 : BOOL;
    VALVE7 : BOOL;
    RUN : BOOL;
    STATUS : BYTE;
  END_VAR
  VAR
    X1 : TIMER_1;
    X2 : SEQUENCE_8;
    X3 : HYST_1;
    init : BOOL;
  END_VAR

  (* startup initialization *)
  IF NOT init THEN
  	init := TRUE;
  	X1.day := SHR(BYTE#128,day);
  	X1.start := T_start;
  	X3.low := Temp_offset + temp_set;
  	X3.high := Temp_hys + X3.low;
  	X2.wait0 := T_max_heat;
  	X2.delay0 := TP_0;
  	X2.delay1 := TP_1;
  	X2.delay2 := TP_2;
  	X2.delay3 := TP_3;
  	X2.delay4 := TP_4;
  	X2.delay5 := TP_5;
  	X2.delay6 := TP_6;
  	X2.delay7 := TP_7;
  	X2.wait1 := T_max_ret;
  	X2.wait2 := T_max_ret;
  	X2.wait3 := T_max_ret;
  	X2.wait4 := T_max_ret;
  	X2.wait5 := T_max_ret;
  	X2.wait6 := T_max_ret;
  	X2.wait7 := T_max_ret;
  	X2();
  END_IF;

  (* oerational code *)
  X1(DTi := DT_in);
  IF X1.Q OR MANUAL OR x2.run THEN
  	X3(in := temp_boiler);
  	X2.in0 := X3.Q OR x3.win;
  	X2.in1 := temp_return >= temp_set;
  	X2.in2 := x2.in1;
  	X2.in3 := x2.in1;
  	X2.in4 := x2.in1;
  	X2.in5 := x2.in1;
  	X2.in6 := x2.in1;
  	X2.in7 := x2.in1;
  	X2.rst := rst;
  	X2(start := X1.Q OR MANUAL);
  	run := x2.run;
  	pump := x2.QX;
  	Heat := NOT X3.Q AND x2.run;
  	valve0 := X2.Q0;
  	valve1 := X2.Q1;
  	valve2 := X2.Q2;
  	valve3 := X2.Q3;
  	valve4 := X2.Q4;
  	valve5 := X2.Q5;
  	valve6 := X2.Q6;
  	valve7 := X2.Q7;
  	pump := X2.QX;
  	status := X2.status;
  ELSE
  	X2(start := false);
  	status := x2.status;
  END_IF;

  (* From OSCAT Library, www.OSCAT.de *)
  (* TIMER_1, SEQUENCE_8, HYST_1 required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK BURNER
  VAR_INPUT
    IN : BOOL;
    STAGE2 : BOOL;
    OVER_TEMP : BOOL;
    OIL_TEMP : BOOL := TRUE;
    FLAME : BOOL;
    RST : BOOL;
    RST_TIMER : BOOL;
    PRE_HEAT_TIME : TIME := t#5s;
    PRE_VENT_TIME : TIME := t#15s;
    PRE_IGNITE_TIME : TIME := t#15s;
    POST_IGNITE_TIME : TIME := t#25s;
    STAGE2_DELAY : TIME := t#10s;
    SAFETY_TIME : TIME := t#5s;
    LOCKOUT_TIME : TIME := t#10s;
    MULTIPLE_IGNITION : BOOL := TRUE;
    KW1 : REAL;
    KW2 : REAL;
  END_VAR
  VAR_OUTPUT
    MOTOR : BOOL;
    COIL1 : BOOL;
    COIL2 : BOOL;
    PRE_HEAT : BOOL;
    IGNITE : BOOL;
    FAIL : BOOL;
    KWH : REAL;
    STATUS : BYTE;
  END_VAR
  VAR_IN_OUT
    RUNTIME1 : UDINT;
    RUNTIME2 : UDINT;
    CYCLES : UDINT;
  END_VAR
  VAR
    state : INT;
    last : TIME;
    tx : TIME;
    last_change : TIME;
    timer1 : ONTIME;
    timer2 : ONTIME;
    oil_temp_last : BOOL;
    cycles2 : UDINT;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));

  (* check rst input and overtemp *)
  IF rst OR over_temp OR state = 0 THEN
  	IF status > BYTE#0 AND tx - last_change >= lockout_time AND rst THEN
  		status := BYTE#110;
  		fail := FALSE;
  		state := 1;
  	ELSE
  		(* normaler reset *)
  		motor := FALSE;
  		coil1 := FALSE;
  		coil2 := FALSE;
  		ignite := FALSE;
  		pre_heat := FALSE;
  		IF over_temp THEN
  			status := BYTE#9;
  			fail := TRUE;
  		END_IF;
  		last_change := tx;
  		last := tx;
  		state := 1;
  	END_IF;
  END_IF;

  (* check for timer rst and rst timer if true *)
  IF rst_timer THEN
  	runtime1 := UDINT#0;
  	runtime2 := UDINT#0;
  	cycles := UDINT#0;
  	cycles2 := UDINT#0;
  END_IF;

  (* quit here if an error is present *)
  IF (status > BYTE#0 AND status < BYTE#100) OR rst THEN RETURN; END_IF;

  (* start sequence *)
  CASE state OF

  1:	(* in signal starts oil pre heating *)
  	IF in AND flame THEN
  		state := 7;
  		pre_heat := FALSE;
  		status := BYTE#2;
  		last_change := tx;
  	ELSIF in THEN
  		pre_heat := TRUE;
  		state := 2;
  		last_change := tx;
  	END_IF;

  2:	(* after pre_heating time start motor *)
  	IF (tx- last_change >= pre_heat_time AND oil_temp) OR (oil_temp AND NOT oil_temp_last) THEN
  		motor := TRUE;
  		state := 3;
  		last_change := tx;
  	(* pre_heat_time ist abgelaufen und oil_temp ist nicht aktiv *)
  	ELSIF tx - last_change >= pre_heat_time AND NOT oil_temp THEN
  		state := 7;
  		pre_heat := FALSE;
  		status := BYTE#1;
  		last_change := tx;
  	(* flame monitor cannot be active at this time *)
  	ELSIF flame THEN
  		state := 7;
  		pre_heat := FALSE;
  		status := BYTE#2;
  		last_change := tx;
  	END_IF;

  3:	(* abwarten bis zündung eingeschaltet werden kann *)
  	IF tx - last_change >= pre_vent_time - pre_ignite_time THEN
  		ignite := TRUE;
  		state := 4;
  		last_change := tx;
  	(* flame monitor cannot be active at this time *)
  	ELSIF flame THEN
  		state := 7;
  		pre_heat := FALSE;
  		motor := FALSE;
  		status := BYTE#3;
  		last_change := tx;
  	END_IF;

  4:	(* warten bis oelzufuhr geoeffnet werden darf *)
  	IF tx - last_change >= pre_ignite_time THEN
  		coil1 := TRUE;
  		state := 5;
  		last_change := tx;
  	END_IF;

  5:	(* warten auf flammwaechter und falls noetig abschalten *)
  	IF tx - last_change >= safety_time OR flame THEN
  		IF NOT flame THEN
  			(* notabschaltung da flammwaechster nicht angesprochen hat *)
  			state := 7;
  			motor := FALSE;
  			coil1 := FALSE;
  			pre_heat := FALSE;
  			ignite := FALSE;
  			status := BYTE#4;
  			last_change := tx;
  		ELSE
  			state := 6;
  			last_change := tx;
  		END_IF;
  	END_IF;

  6:	(* brenner läuft, flammueberwachung und nach ablauf der nachigniteszeit ignite abschalten *)
  	IF NOT flame AND NOT multiple_ignition THEN
  		(* notabschaltung da flammwaechster keine flamme meldet *)
  		state := 7;
  		motor := FALSE;
  		coil1 := FALSE;
  		coil2 := FALSE;
  		pre_heat := FALSE;
  		ignite := FALSE;
  		status := BYTE#5;
  		last_change := tx;
  	ELSIF NOT flame AND multiple_ignition THEN
  		ignite := TRUE;
  		state := 5;
  		coil2 := FALSE;
  		last_change := tx;
  	ELSE
  		IF tx - last_change >= post_ignite_time THEN
  			(* post_ignite_time abgelaufen, ignite abschalten *)
  			ignite := FALSE;
  		END_IF;
  		IF tx - last_change >= stage2_delay AND stage2 THEN
  			coil2 := TRUE;
  		ELSE
  			coil2 := FALSE;
  		END_IF;
  	END_IF;
  END_CASE;

  (* abschaltung wenn kein eingangssignal *)
  IF NOT in THEN
  	state := 1;
  	motor := FALSE;
  	coil1 := FALSE;
  	coil2 := FALSE;
  	ignite := FALSE;
  	pre_heat := FALSE;
  	last_change := tx;
  END_IF;

  (* runtimezähler *)
  timer1(in := flame AND in AND motor AND coil1 AND NOT coil2, SECONDS := runtime1, CYCLES := cycles);
  cycles := timer1.CYCLES;
  runtime1 := timer1.SECONDS;

  timer2(in := flame AND in AND motor AND coil1 AND coil2, SECONDS := runtime2, CYCLES := cycles2);
  cycles2 := timer2.CYCLES;
  runtime2 := timer2.SECONDS;

  KWH := UDINT_TO_REAL(runtime1) * KW1 / 3600.0 + UDINT_TO_REAL(runtime2) * KW2 / 3600.0;

  (* zeit fuer naechsten aufruf merken *)
  last := tx;

  (* set fail output IF ERROR and Status  if normal operation *)

  IF status > BYTE#0 AND status < BYTE#100 THEN
  	fail := TRUE;
  ELSE
  	fail := FALSE;
  	IF NOT in THEN
  		status := BYTE#110;
  	ELSIF flame AND in AND motor AND coil2 AND coil1 THEN
  		status := BYTE#113;
  	ELSIF flame AND in AND motor AND coil1 THEN
  		status := BYTE#112;
  	ELSE
  		status := BYTE#111;
  	END_IF;
  END_IF;

  (* From OSCAT Library, www.OSCAT.de *)
  (* T_PLC_MS, ONTIME required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK ACTUATOR_A
  VAR_INPUT
    I1 : BYTE;
    I2 : BYTE;
    IS : BOOL;
    RV : BOOL;
    DX : BOOL;
    RUNTIME : TIME;
    SELF_ACT_TIME : TIME;
    OUT_MIN : DWORD;
    OUT_MAX : DWORD;
  END_VAR
  VAR_OUTPUT
    Y : DWORD;
  END_VAR
  VAR
    timer : CYCLE_4;
    dx_edge : BOOL;
  END_VAR

  (* run the system timer, if self_act_time = t#0s then state is set to 0 *)
  timer(T0 := RUNTIME, T1 := RUNTIME, T3 := SELF_ACT_TIME, sl := DX AND NOT dx_edge, sx := 0, S0 := SELF_ACT_TIME > t#0s);
  dx_edge := dx;

  CASE timer.STATE OF
  	0: 	(* self act min value *)
  		Y := OUT_MIN;
  	1:	(* self_act max value *)
  		Y := OUT_MAX;
  	3:	(* normal operation *)
  		IF rv THEN
  			Y := UDINT_TO_DWORD(DWORD_TO_UDINT(OUT_MAX) - (DWORD_TO_UDINT(OUT_MAX) - DWORD_TO_UDINT(OUT_MIN)) * BYTE_TO_UDINT(SEL(IS, I1, I2)) / UDINT#255);
  		ELSE
  			Y := UDINT_TO_DWORD((DWORD_TO_UDINT(OUT_MAX) - DWORD_TO_UDINT(OUT_MIN)) * BYTE_TO_UDINT(SEL(IS, I1, I2)) / UDINT#255 + DWORD_TO_UDINT(OUT_MIN));
  		END_IF;
  END_CASE;

  (* From OSCAT Library, www.OSCAT.de *)
  (* Cycle_4 required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK BLIND_CONTROL
  VAR_INPUT
    UP : BOOL;
    DN : BOOL;
    S_IN : BYTE;
    PI : BYTE;
    AI : BYTE;
    T_UD : TIME;
    T_ANGLE : TIME;
    T_LOCKOUT : TIME := t#100ms;
    SENS : BYTE := 5;
  END_VAR
  VAR_OUTPUT
    POS : BYTE;
    ANG : BYTE;
    MU : BOOL;
    MD : BOOL;
    STATUS : BYTE;
  END_VAR
  VAR
    act : BLIND_ACTUATOR;
    delta : BYTE;
    ipos : BYTE;
    iangel : BYTE;
    bTimeTest : BOOL;
  END_VAR

  IF bTimeTest THEN
  	PI:=iPos;
  	AI:=iAngel;
  	UP:=TRUE;
  	DN:=TRUE;
  END_IF;

  (* Check Position*)
  act(T_UD:=T_UD, T_ANGLE:=T_ANGLE, T_lockout := T_Lockout);

  IF UP AND DN THEN
  	(* automatic modus detected *)
  	(* first find correct position *)
  	IF BYTE_TO_INT(act.pos) < BYTE_TO_INT(pi) - BYTE_TO_INT(delta) THEN
  		act.UP := TRUE;
  		act.DN := FALSE;
  		delta := BYTE#0;
  		STATUS := BYTE#121;
  	ELSIF BYTE_TO_INT(act.pos) > BYTE_TO_INT(pi) + BYTE_TO_INT(delta) THEN
  		act.UP := FALSE;
  		act.DN := TRUE;
  		delta := BYTE#0;
  		STATUS := BYTE#122;
  	(* regulate angle *)
  	ELSIF BYTE_TO_INT(act.ang) < BYTE_TO_INT(ai) - BYTE_TO_INT(delta) AND T_angle > T#100ms THEN
  		act.UP := TRUE;
  		act.DN := FALSE;
  		delta := SHR(sens,2);
  		STATUS := BYTE#123;
  	ELSIF BYTE_TO_INT(act.ang) > BYTE_TO_INT(ai) + BYTE_TO_INT(delta) AND T_angle > T#100ms THEN
  		act.UP := FALSE;
  		act.DN := TRUE;
  		delta := SHR(sens,2);
  		STATUS := BYTE#124;
  	(* correct position reached *)
  	ELSE
  		act.UP := FALSE;
  		act.DN := FALSE;
  		delta := sens;
  		STATUS := S_IN;
  	END_IF;
  ELSE
  	act.UP := UP;
  	act.DN := DN;
  	STATUS := S_IN;
  END_IF;

  (* blind control calls blind_actuator *)
  act(T_UD:=T_UD, T_ANGLE:=T_ANGLE, T_lockout := T_Lockout);
  pos := act.pos;
  ang := act.ang;
  MU := act.QU;
  md := act.QD;
  status := act.status;

  (* From OSCAT LIBRARY, www.oscat.de *)
  (* BLIND_ACTUATOR required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK BLIND_INPUT
  VAR_INPUT
    POS : BYTE;
    ANG : BYTE;
    S1 : BOOL;
    S2 : BOOL;
    IN : BOOL;
    PI : BYTE;
    AI : BYTE;
    SINGLE_SWITCH : BOOL;
    CLICK_EN : BOOL := TRUE;
    CLICK_TIME : TIME := t#500ms;
    MAX_RUNTIME : TIME := t#60s;
    MANUAL_TIMEOUT : TIME := t#1h;
    DEBOUNCE_TIME : TIME := t#20ms;
    DBL_CLK1 : BOOL := FALSE;
    DBL_POS1 : BYTE;
    DBL_ANG1 : BYTE;
    DBL_CLK2 : BOOL := FALSE;
    DBL_POS2 : BYTE := 255;
    DBL_ANG2 : BYTE := 255;
    D1_TOGGLE : BOOL := TRUE;
    D2_TOGGLE : BOOL := TRUE;
    MASTER_MODE : BOOL;
  END_VAR
  VAR_OUTPUT
    QU : BOOL := TRUE;
    QD : BOOL := TRUE;
    STATUS : BYTE;
    PO : BYTE := 255;
    AO : BYTE := 255;
    D1 : BOOL;
    D2 : BOOL;
  END_VAR
  VAR
    s1e : TOF;
    s2e : TOF;
    s1d : CLICK_MODE;
    s2d : CLICK_MODE;
    dir : BOOL;
    tx : TIME;
    last : TIME;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));

  (* inputs S1 and S2 are debounced and then decoded for multiple clicks *)
  s1e(in := S1, pt := DEBOUNCE_TIME);
  s2e(in := S2, pt := DEBOUNCE_TIME);
  s1d(in := (s1e.Q AND NOT SINGLE_SWITCH) OR (s1e.Q AND SINGLE_SWITCH AND dir), t_long := CLICK_TIME);
  s2d(in := (s2e.Q AND NOT SINGLE_SWITCH) OR (s1e.Q AND SINGLE_SWITCH AND NOT dir), t_long := CLICK_TIME);

  (* if d1 and d2 are not toggle clear them to make sure they are only active for oine cycle *)
  IF NOT d1_toggle THEN d1 := FALSE; END_IF;
  IF NOT d2_toggle THEN d2 := FALSE; END_IF;

  (* decode actions *)
  IF (s1d.LONG AND s2d.LONG) OR (status = BYTE#139) THEN
     status := BYTE#139;
     IF NOT (s1d.LONG OR s2d.LONG)  THEN status := BYTE#130; END_IF;
  ELSIF s1d.tp_LONG THEN
  	status := BYTE#132;
  ELSIF s2d.tp_LONG THEN
  	status := BYTE#133;
  ELSIF  s1d.SINGLE THEN
  	IF click_en THEN
  		(* if running then we stop otherwise start new direction *)
  		IF QU XOR QD THEN
  			status := BYTE#131;
  		ELSE
  			status := BYTE#134;
  			last := tx;
  			dir := NOT dir;
  		END_IF;
  	END_IF;
  ELSIF  s2d.SINGLE THEN
  	IF click_en THEN
  		(* if running then we stop otherwise start new direction *)
  		IF QU XOR QD THEN
  			status := BYTE#131;
  		ELSE
  			status := BYTE#135;
  			last := tx;
  			dir := NOT dir;
  		END_IF;
  	END_IF;
  ELSIF in THEN
  	status := BYTE#136;
  	last := tx;
  ELSIF s1d.DOUBLE THEN
  	IF dbl_clk1 THEN
  		(* a position need to be set for a double click on S1 *)
  		status := BYTE#137;
  		last := tx;
  	ELSE
  		(* toggle the output when dbl_clk1 is not active *)
  		D1 := NOT D1;
  	END_IF;
  ELSIF s2d.DOUBLE THEN
  	IF dbl_clk2 THEN
  		(* a position need to be set for a double click on S2 *)
  		status := BYTE#138;
  		last := tx;
  	ELSE
  		(* toggle the output when dbl_clk2 is not active *)
  		(* in single switch mode we need to toggle d1 instead of d2 *)
  		IF single_switch THEN D1 := NOT D1; ELSE D2 := NOT D2; END_IF;
  	END_IF;
  END_IF;


  (* state machine *)
  CASE BYTE_TO_INT(status) OF
  	0:		(* power up operation *)
  			status := BYTE#130;

  	130:	(* automatic operation standby *)
  			IF NOT master_mode THEN
  				PO := POS;
  				AO := ANG;
  			END_IF;
  			QU := TRUE;
  			QD := TRUE;

  	131:	(* manual operation standby *)
  			QU := FALSE;
  			QD := FALSE;
  			PO := POS;
  			AO := ANG;
  			(* manual mode will be ended when timeout is reached *)
  			IF tx - last >= manual_timeout THEN
  				status := BYTE#130;
  			END_IF;

  	132:	(* manual operation up *)
  			QU := TRUE;
  			QD := FALSE;
  			PO := POS; AO := ANG;
  			last := tx;
  			IF NOT s1d.LONG THEN status := BYTE#131; dir := NOT dir; END_IF;

  	133:	(* manual operation down *)
  			QU := FALSE;
  			QD := TRUE;
  			PO := POS; AO := ANG;
  			last := tx;
  			IF NOT s2d.LONG THEN	status := BYTE#131; dir := NOT dir; END_IF;

  	134:	(* manual operation single click up *)
  			QU := TRUE;
  			QD := FALSE;
  			PO := POS; AO := ANG;
  			IF tx - last >= max_runtime THEN status := BYTE#131; END_IF;

  	135:	(* manual operation single click dn *)
  			QU := FALSE;
  			QD := TRUE;
  			PO := POS; AO := ANG;
  			IF tx - last >= max_runtime THEN status := BYTE#131;	END_IF;

  	136:	(* forced input in = true *)
  			QU := TRUE;
  			QD := TRUE;
  			PO := PI; AO := AI;
  			IF tx-last >= max_runtime THEN status := BYTE#130; END_IF;

  	137:	(* double click1 position *)
  			QU := TRUE;
  			QD := TRUE;
  			PO := DBL_POS1;
  			AO := DBL_ANG1;
  			IF tx - last >= max_runtime THEN status := BYTE#131; END_IF;

  	138:	(* double click2 position *)
  			QU := TRUE;
  			QD := TRUE;
  			PO := DBL_POS2;
  			AO := DBL_ANG2;
  			IF tx - last >= max_runtime THEN status := BYTE#131; END_IF;

  	   139:   (* manual operation standby *)
  	         QU := FALSE;
  	         QD := FALSE;
  	         PO := POS;
  	         AO := ANG;

  END_CASE;

  (* From OSCAT LIBRARY, www.oscat.de *)
  (* T_PLC_MS required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK SWITCH_I
  VAR_INPUT
    SET : BOOL;
    IN : BOOL;
    RST : BOOL;
    T_DEBOUNCE : TIME := t#10ms;
    T_RECONFIG : TIME := t#1s;
    T_ON_MAX : TIME := t#0h;
  END_VAR
  VAR_OUTPUT
    Q : BOOL := FALSE;
  END_VAR
  VAR
    state : BYTE := 0;
    edge : BOOL := FALSE;
    _r_edge : BOOL := FALSE;
    T_on : TIME;
    tx : TIME;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));

  (* asynchronous set and reset first *)
  IF set AND NOT rst THEN
  	Q := TRUE;
  	T_on := tx;
  ELSIF rst THEN
  	Q := FALSE;
  (* check FOR input edge AND start debounce timer *)
  ELSIF (in XOR edge) AND NOT (state = BYTE#1) THEN
  	state := BYTE#1;
  	T_on := Tx;
  (* edge was detected and debounce time elapsed *)
  ELSIF (state = BYTE#1) AND (Tx - t_debounce >= T_on) THEN
  	state := BYTE#2;
  	(* react on rising or falling edge depending on r_edge *)
  	IF _r_edge XOR in THEN Q := NOT Q; END_IF;
  (* wait for T_reconfig and adjust r_edge *)
  ELSIF state = BYTE#2 AND Tx - t_reconfig >= T_on THEN
  	_r_edge := in;
  END_IF;
  IF Q AND T_on_max > t#0ms AND Tx >= T_on + T_on_max THEN
  	Q := FALSE;
  END_IF;
  edge := in;

  (* From OSCAT LIBRARY, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK PULSE_T
  VAR_INPUT
    IN : BOOL;
    T1 : TIME;
    T2 : TIME;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
  END_VAR
  VAR
    init : BOOL;
    last : TIME;
    tx : TIME;
    edge : BOOL;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));

  IF NOT init THEN
  	init := TRUE;
  	last := tx;
  ELSIF RST THEN
  	(* asynchronous reset *)
  	Q := FALSE;
  ELSIF IN AND NOT edge AND NOT Q THEN
  	(* a rising edge on in will reversre the output status, if new pulse is startet the start time is stored in last *)
  	last := tx;
  	Q := TRUE;
  ELSIF NOT IN AND edge AND ((tx - last) > T1) THEN
  	(* a falling edge on IN will clear the output if in was high for more then T1 *)
  	Q := FALSE;
  ELSIF (tx - last) >= T2 THEN
  	(* timeout for long pulse if second click did not occur or in stays high *)
  	Q := FALSE;
  END_IF;

  edge := IN;

  (* From OSCAT LIBRARY, www.oscat.de *)
  (* T_PLC_MS required *)
END_FUNCTION_BLOCK

FUNCTION AIR_ENTHALPY : REAL
  VAR_INPUT
    _T : REAL;
    RH : REAL;
  END_VAR

  Air_enthalpy := 1.00482 * _T + (1.86 * _T + 2500.78) * dew_con(RH,_T);

  (* From OSCAT Library, www.OSCAT.de *)
  (* DEW_CON required *)
END_FUNCTION

FUNCTION_BLOCK PULSE_LENGTH
  VAR_INPUT
    IN : BOOL;
    T_SHORT : TIME := t#100ms;
    T_LONG : TIME := t#1s;
  END_VAR
  VAR_OUTPUT
    SHORT : BOOL;
    MIDDLE : BOOL;
    LONG : BOOL;
  END_VAR
  VAR
    tx : TIME;
    tn : TIME;
    edge : BOOL;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));

  (* reset outputs, they should only be active 1 cycle *)
  short := FALSE;
  Middle := FALSE;
  long := FALSE;

  (* detect rising edge *)
  IF in AND NOT edge THEN
  	edge := TRUE;
  	tn := tx;

  (* detect for falling edge *)
  ELSIF NOT in AND edge THEN
  	edge := FALSE;
  	tn := tx - tn;
  	IF tn < t_short THEN
  		short := TRUE;
  	ELSIF tn > t_long THEN
  		long := TRUE;
  	ELSE
  		Middle := TRUE;
  	END_IF;

  (* generate long pulse as soon as T_long is reached *)
  ELSIF in AND tx - tn > t_long THEN
  	long := TRUE;
  END_IF;

  (* From OSCAT LIBRARY, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK SWITCH_X
  VAR_INPUT
    IN1 : BOOL;
    IN2 : BOOL;
    IN3 : BOOL;
    IN4 : BOOL;
    IN5 : BOOL;
    IN6 : BOOL;
    T_DEBOUNCE : TIME := t#50ms;
  END_VAR
  VAR_OUTPUT
    Q1 : BOOL;
    Q2 : BOOL;
    Q3 : BOOL;
    Q4 : BOOL;
    Q5 : BOOL;
    Q6 : BOOL;
    Q31 : BOOL;
    Q41 : BOOL;
    Q51 : BOOL;
    Q61 : BOOL;
    Q32 : BOOL;
    Q42 : BOOL;
    Q52 : BOOL;
    Q62 : BOOL;
  END_VAR
  VAR
    init : BOOL;
    T1 : TOF;
    T2 : TOF;
    T3 : TOF;
    T4 : TOF;
    T5 : TOF;
    T6 : TOF;
    tx : TIME;
    x1 : BOOL;
    x2 : BOOL;
    E1 : BOOL;
    E2 : BOOL;
  END_VAR

  (* initialize on startup *)
  IF NOT init THEN
  	init := TRUE;
  	IF t_debounce < t#50ms THEN tx := t#50ms; ELSE tx := t_debounce; END_IF;
  	T1(PT := Tx);
  	T2(PT := Tx);
  	T3(PT := Tx);
  	T4(PT := Tx);
  	T5(PT := Tx);
  	T6(PT := Tx);
  ELSE
  	Q1 := FALSE;
  	Q2 := FALSE;
  	Q3 := FALSE;
  	Q4 := FALSE;
  	Q5 := FALSE;
  	Q6 := FALSE;
  	Q31 := FALSE;
  	Q41 := FALSE;
  	Q51 := FALSE;
  	Q61 := FALSE;
  	Q32 := FALSE;
  	Q42 := FALSE;
  	Q52 := FALSE;
  	Q62 := FALSE;
  END_IF;

  (* read inputs and debounce *)
  	T1(IN := IN1);
  	T2(IN := IN2);
  	T3(IN := IN3);
  	T4(IN := IN4);
  	T5(IN := IN5);
  	T6(IN := IN6);

  (* detect edge of IN1 and IN2 *)
  IF t1.Q AND NOT E1 THEN X1 := TRUE; END_IF;
  IF t2.Q AND NOT E2 THEN X2 := TRUE; END_IF;

  IF t1.Q THEN
  	IF t3.q THEN
  		q31 := TRUE;
  		X1 := FALSE;
  	ELSIF t4.q THEN
  		q41 := TRUE;
  		X1 := FALSE;
  	ELSIF t5.q THEN
  		q51 := TRUE;
  		X1 := FALSE;
  	ELSIF t6.q THEN
  		q61 := TRUE;
  		X1 := FALSE;
  	END_IF;
  ELSIF t2.Q THEN
  	IF t3.q THEN
  		q32 := TRUE;
  		X2 := FALSE;
  	ELSIF t4.q THEN
  		q42 := TRUE;
  		X2 := FALSE;
  	ELSIF t5.q THEN
  		q52 := TRUE;
  		X2 := FALSE;
  	ELSIF t6.q THEN
  		q62 := TRUE;
  		X2 := FALSE;
  	END_IF;
  (* in1 was active alone *)
  ELSIF NOT T1.Q AND E1 AND X1 THEN
  	Q1 := TRUE;
  	X1 := FALSE;
  ELSIF NOT T2.Q AND E2 AND X2 THEN
  	Q2 := TRUE;
  	X2 := FALSE;
  ELSIF T3.Q THEN
  	Q3 := TRUE;
  ELSIF T4.Q THEN
  	Q4 := TRUE;
  ELSIF T5.Q THEN
  	Q5 := TRUE;
  ELSIF T6.Q THEN
  	Q6 := TRUE;
  END_IF;

  (* save state of in1 and in2 *)
  E1 := T1.Q;
  E2 := T2.Q;

  (* From OSCAT LIBRARY, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK F_LAMP
  VAR_INPUT
    SWITCH : BOOL;
    DIMM : BYTE := 255;
    RST : BOOL;
    T_NO_DIMM : UINT := 100;
    T_MAINTENANCE : UINT := 15000;
  END_VAR
  VAR_OUTPUT
    LAMP : BYTE;
    STATUS : BYTE;
  END_VAR
  VAR_IN_OUT
    _ONTIME : UDINT;
    CYCLES : UDINT;
  END_VAR
  VAR
    runtime : ONTIME;
  END_VAR

  runtime(in := switch, SECONDS := _ONTIME , CYCLES := CYCLES);
  CYCLES := runtime.CYCLES;
  _ONTIME := runtime.SECONDS;

  IF RST THEN
  	_ONTIME := UDINT#0;
  	CYCLES := UDINT#0;
  END_IF;
  IF SWITCH THEN
  	IF _ontime < UINT_TO_UDINT(T_NO_DIMM) * UDINT#3600 THEN
  		LAMP := BYTE#255;
  		STATUS := BYTE#111;
  	ELSE
  		LAMP := DIMM;
  		STATUS := BYTE#112;
  	END_IF;
  ELSE
  	LAMP := BYTE#0;
  	STATUS := BYTE#110;
  END_IF;

  IF _ontime >= UINT_TO_UDINT(T_maintenance) * UDINT#3600 AND T_Maintenance > UINT#0 THEN
  	STATUS := BYTE#120;
  END_IF;

  (* From OSCAT LIBRARY, www.oscat.de *)
  (* ONTIME required *)
END_FUNCTION_BLOCK

FUNCTION TANK_VOL2 : REAL
  VAR_INPUT
    TR : REAL;
    H : REAL;
  END_VAR

  TANK_VOL2 := 3.14159265358979323846264338327950288 * H * H * (TR - H / 3.0);

  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION

FUNCTION TANK_VOL1 : REAL
  VAR_INPUT
    TR : REAL;
    TL : REAL;
    H : REAL;
  END_VAR

  TANK_VOL1 := CIRCLE_SEG(TR, H) * TL;

  (* From OSCAT Library, www.OSCAT.de *)
  (* CIRCLE_SEG required *)
END_FUNCTION

FUNCTION DT_TO_TOD_2 : UDINT
  VAR_INPUT
    IN : UDINT;
  END_VAR

  DT_TO_TOD_2 := (IN MOD UDINT#86400) * UDINT#1000;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK ACTUATOR_UD
  VAR_INPUT
    UD : BOOL;
    _ON : BOOL;
    MANUAL : BOOL;
    UP : BOOL;
    DN : BOOL;
    OFF : BOOL;
    YUP_IN : BOOL;
    YDN_IN : BOOL;
    OUT_RETURN : BOOL;
    _TON : TIME;
    _TOFF : TIME;
  END_VAR
  VAR_OUTPUT
    YUP : BOOL;
    YDN : BOOL;
    STATUS : BYTE;
  END_VAR
  VAR
    tx : TIME;
    last : TIME;
    init : BOOL;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));

  IF NOT init THEN
  	(* INITIALIZATION AT FIRST CALL *)
  	last := tx;
  	init := TRUE;
  ELSIF off THEN
  	(* emergency shut off detected *)
  	Yup := FALSE;
  	Ydn := FALSE;
  	last := tx;
  	status := BYTE#101;

  (* WATH FOR MIN TON TIME *)
  ELSIF ((Yup OR Ydn) AND tx - last < _Ton) THEN RETURN;
  ELSIF NOT yup AND NOT ydn AND tx - last < _toff THEN	RETURN;

  (* manual operation *)
  ELSIF manual THEN
  	status := BYTE#102;
  	(* directional chage set both outs 0 first *)
  	IF yup AND NOT up OR ydn AND NOT dn THEN
  		ydn := FALSE;
  		yup := FALSE;
  		last := tx;
  	(* manual up operation *)
  	ELSIF UP AND NOT DN AND NOT OFF THEN
  		Ydn := FALSE;
  		Yup := TRUE;
  		last := tx;
  		status := BYTE#103;
  	(* manual down operation *)
  	ELSIF DN AND NOT UP AND NOT OFF THEN
  		Yup := FALSE;
  		Ydn := TRUE;
  		last := tx;
  		status := BYTE#104;
  	(* maual mode but no up or down *)
  	ELSE
  		IF YUP OR YDN THEN LAST := tx; END_IF;
  		Yup := FALSE;
  		Ydn := FALSE;
  	END_IF;

  (* automatic operation *)
  ELSE
  	(* directional change set outputs low first *)
  	IF yup AND NOT ud OR ydn AND UD THEN
  		yup := FALSE;
  		ydn := FALSE;
  		last := tx;
  	(* automatic up operation *)
  	ELSIF Ud AND _on AND NOT OFF THEN
  		Ydn := FALSE;
  		Yup := TRUE;
  		last := tx;
  		status := BYTE#111;

  	(* automatic down operation *)
  	ELSIF NOT UD AND _on AND NOT OFF THEN
  		Yup := FALSE;
  		Ydn := TRUE;
  		last := tx;
  		status := BYTE#112;
  	(* standby mode *)
  	ELSE
  		IF Yup OR Ydn THEN last := tx; END_IF;
  		Yup := FALSE;
  		Ydn := FALSE;
  		status := BYTE#110;
  	END_IF;
  END_IF;

  (* make sure Yup and Ydn are never on at the same time *)
  IF Ydn AND Yup_in AND out_return THEN
  	Ydn := FALSE;
  	status := BYTE#1;
  END_IF;
  IF Yup AND Ydn_in AND out_return THEN
  	Yup := FALSE;
  	status := BYTE#2;
  END_IF;

  (* From OSCAT Library, www.OSCAT.de *)
  (* T_PLC_MS required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK ACTUATOR_3P
  VAR_INPUT
    IN : BYTE;
    TEST : BOOL;
    ARE : BOOL := TRUE;
    END_POS : BOOL;
    T_RUN : TIME := t#60s;
    T_EXT : TIME := t#10s;
    T_CAL : TIME := t#600s;
    T_DIAG : TIME := t#10d;
    SWITCH_AVAIL : BOOL;
  END_VAR
  VAR_OUTPUT
    OUT1 : BOOL;
    OUT2 : BOOL;
    POS : BYTE;
    ERROR : BOOL;
    STATUS : BYTE;
  END_VAR
  VAR_IN_OUT
    ARX : BOOL;
  END_VAR
  VAR
    tx : TIME;
    _ramp : _RMP_NEXT;
    next_cal : TIME;
    next_diag : TIME;
    last : TIME;
    start : TIME;
  END_VAR

  tx := UDINT_TO_TIME(T_PLC_MS(en:=true));

  (* check test input *)
  IF TEST THEN
  	status := BYTE#103;
  	start := tx;
  	ARX := TRUE;
  END_IF;

  CASE BYTE_TO_INT(status) OF
  	0:	(* power on setup *)
  		IF ARE AND NOT ARX THEN
  			status := BYTE#103;
  			start := tx;
  			ARX := TRUE;
  		END_IF;

  	100:	(* normal operation *)
  		(* check for auto diagnostics *)
  		IF T_DIAG > T#0s AND tx > next_diag AND ARE AND NOT ARX THEN
  				status := BYTE#103;
  				start := tx;
  				ARX := TRUE;

  		(* check for auto calibration *)
  		ELSIF T_CAL > T#0s AND tx > next_cal AND ARE AND NOT ARX THEN
  			IF pos > BYTE#127 THEN
  				OUT1 := TRUE;
  				OUT2 := FALSE;
  				_ramp.IN := BYTE#255;
  				ARX := TRUE;
  			ELSE
  				OUT1 := FALSE;
  				OUT2 := TRUE;
  				_ramp.IN := BYTE#0;
  				ARX := TRUE;
  			END_IF;
  			status := BYTE#101;
  			start := tx;
  		ELSE
  			(* increment next_cal if not active *)
  			IF NOT(OUT1 OR OUT2) THEN next_cal := next_cal + (tx-last); END_IF;
  			(* set ramp generator to IN *)
  			_ramp.IN := IN;
  		END_IF;

  	101:	(* calibrate *)
  		IF tx - start < T_EXT THEN
  			next_cal := tx + T_CAL;
  		ELSIF SWITCH_AVAIL AND END_POS THEN
  			STATUS := BYTE#100;
  			ARX := FALSE;
  		ELSIF tx - start > T_EXT + T_RUN THEN
  			ERROR := SWITCH_AVAIL;
  			ARX := FALSE;
  		END_IF;

  	103:	(* diagnostics up*)
  		(* run up for T_ext *)
  		IF tx - start < T_EXT THEN
  			ERROR := FALSE;
  			_ramp.TR := T_RUN;
  			_ramp.TF := T_RUN;
  			OUT1 := TRUE;
  			OUT2 := FALSE;
  			_ramp.IN := BYTE#255;
  		ELSIF SWITCH_AVAIL AND END_POS THEN
  			_ramp.TR := tx - start;
  			STATUS := BYTE#104;
  		ELSIF tx - start > T_EXT + T_RUN THEN
  			ERROR := SWITCH_AVAIL;
  			STATUS := BYTE#104;
  			start := tx;
  		END_IF;

  	104:	(* diagnostics dn*)
  		IF tx - start < T_ext THEN
  			OUT1 := FALSE;
  			OUT2 := TRUE;
  			_ramp.IN := BYTE#0;
  			next_diag := tx + T_DIAG;
  		ELSIF SWITCH_AVAIL AND END_POS THEN
  			_ramp.TR := tx - start;
  			(* check if runtimes differ by more than 10% *)
  			IF DINT_TO_TIME(ABS(TIME_TO_DINT(_ramp.TR) - TIME_TO_DINT(_ramp.TF)) * DINT#10) > T_RUN THEN error := TRUE; END_IF;
  			STATUS := BYTE#100;
  			ARX := FALSE;
  			next_cal := tx + T_CAL;
  		ELSIF tx - start > T_EXT + T_RUN THEN
  			IF SWITCH_AVAIL THEN ERROR := TRUE; END_IF;
  			STATUS := BYTE#100;
  			ARX := FALSE;
  			next_CAL := tx + T_CAL;
  		END_IF;
  END_CASE;

  (* internal flap simulation and output activation *)
  _ramp(OUT := POS);
  POS := _ramp.OUT;
  IF STATUS = BYTE#100 THEN
  	OUT1 := _ramp.UP;
  	OUT2 := _ramp.DN;
  END_IF;

  (* adjust position if end switch is active *)
  IF SWITCH_AVAIL AND END_POS THEN
  	POS := SEL(POS > BYTE#127, BYTE#0, BYTE#255);
  	next_cal := tx + T_CAL;
  END_IF;

  (* set last to tx for next cycle *)
  last := tx;

  (* From OSCAT Library, www.OSCAT.de *)
  (* _RMP_NEXT required *)
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

FUNCTION WCT : REAL
  VAR_INPUT
    _T : REAL;
    V : REAL;
  END_VAR

  IF V < 5.0 OR _T > 10.0 THEN
  	WCT := _T;
  ELSE
  	WCT := 13.12 + 0.6215 * _T +(0.3965 * _T - 11.37) * EXP(LN(v) * 0.16);
  END_IF;

  (* From OSCAT LIBRARY, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK HEAT_TEMP
  VAR_INPUT
    T_EXT : REAL;
    T_INT : REAL;
    OFFSET : REAL;
    T_REQ : REAL;
    TY_MAX : REAL := 70.0;
    TY_MIN : REAL := 25.0;
    TY_CONFIG : REAL := 70.0;
    T_INT_CONFIG : REAL := 20.0;
    T_EXT_CONFIG : REAL := -15.0;
    T_DIFF : REAL := 10.0;
    C : REAL := 1.33;
    H : REAL := 3.0;
  END_VAR
  VAR_OUTPUT
    TY : REAL;
    HEAT : BOOL;
  END_VAR
  VAR
    tr : REAL;
    tx : REAL;
  END_VAR

  tr := T_INT + OFFSET;
  tx := (tr - T_EXT) / (T_INT_CONFIG - T_EXT_CONFIG);

  IF T_EXT + H > tr THEN
  	TY := 0.0;
  ELSE
  	TY := LIMIT(TY_MIN, tr + T_DIFF * 0.5 * tx + (TY_CONFIG - T_DIFF * 0.5 - tr) * EXPT(tx, 1.0 / C), TY_MAX);
  END_IF;

  TY := MAX(TY, T_REQ);
  HEAT := TY > 0.0;

  (* from OSCAT library www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK GEN_PULSE
  VAR_INPUT
    ENQ : BOOL := TRUE;
    PTH : TIME;
    PTL : TIME;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
  END_VAR
  VAR
    tx : TIME;
    tn : TIME;
    init : BOOL;
  END_VAR

  IF enq THEN
  		tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));
  	IF NOT init THEN init := TRUE; tn := tx; END_IF;
  	IF tx - tn >= SEL(Q, PTL, PTH) THEN
  		tn := tn + SEL(Q, PTL, PTH);
  		Q := NOT Q;
  	END_IF;
  ELSE
  	Q := FALSE;
  	init := FALSE;
  END_IF;

  (* From OSCAT Library, www.OSCAT.de *)
  (* T_PLC_MS required*)
END_FUNCTION_BLOCK

FUNCTION_BLOCK ACTUATOR_2P
  VAR_INPUT
    IN : BYTE;
    TEST : BOOL;
    ARE : BOOL := TRUE;
    CYCLE_TIME : TIME;
    SENS : BYTE;
    SELF_ACT_TIME : TIME;
    SELF_ACT_PULSE : TIME;
    SELF_ACT_CYCLES : INT := 1;
  END_VAR
  VAR_OUTPUT
    OUT : BOOL;
    ARO : BOOL;
  END_VAR
  VAR_IN_OUT
    ARX : BOOL;
  END_VAR
  VAR
    timer : AUTORUN;
    pwgen : GEN_PULSE;
  END_VAR

  (* run the autorun timer *)
  timer(trun := SELF_ACT_PULSE * (2 * SELF_ACT_CYCLES), toff := SELF_ACT_TIME, Test := TEST, ARE := ARE, arx := ARX);
  ARO := timer.ARO;

  (* run the pulse width generator *)
  IF aro THEN
  	pwgen(PTL := SELF_ACT_PULSE, PTH := SELF_ACT_PULSE);
  	out := pwgen.Q;
  ELSIF in < sens THEN
  	out := FALSE;
  ELSIF BYTE_TO_USINT(in) > USINT#255 - BYTE_TO_USINT(sens) THEN
  	out := TRUE;
  ELSE
  	pwgen.PTH := udint_to_time((time_to_udint(CYCLE_TIME) * BYTE_TO_udint(BAND_B(IN,SENS))  ) / BYTE_TO_udint(BYTE#255));
  	pwgen.PTL := CYCLE_TIME - pwgen.PTH;
  	pwgen();
  	out := pwgen.Q;
  END_IF;




  (* From OSCAT Library, www.OSCAT.de *)
  (* AUTORUN, GEN_PULE, BAND_B required *)
END_FUNCTION_BLOCK

FUNCTION SDD_NH3 : REAL
  VAR_INPUT
    _T : REAL;
  END_VAR

  IF _T < -33.65 THEN
  	SDD_NH3 := EXP(7.3396511649 - ( 1166.7498002 / ( _T + 192.37 )));
  ELSE
  	SDD_NH3 := EXP(11.210964456 - ( 2564.9140075 / ( _T + 262.741 )));
  END_IF;

  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION

FUNCTION_BLOCK TEMP_EXT
  VAR_INPUT
    T_EXT1 : REAL;
    T_EXT2 : REAL;
    T_EXT3 : REAL;
    T_EXT_CONFIG : BYTE := 0;
    DT_IN : UDINT;
    T_EXT_MIN : REAL := -40.0;
    T_EXT_MAX : REAL := 60.0;
    T_EXT_DEFAULT : REAL := -10.0;
    HEAT_PERIOD_START : UDINT := 20995200;
    HEAT_PERIOD_STOP : UDINT := 10281600;
    COOL_PERIOD_START : UDINT := 07776000;
    COOL_PERIOD_STOP : UDINT := 23500800;
    HEAT_START_TEMP_DAY : REAL := 15.0;
    HEAT_START_TEMP_NIGHT : REAL := 10.0;
    HEAT_STOP_TEMP : REAL := 18.0;
    COOL_START_TEMP_DAY : REAL := 26.0;
    COOL_START_TEMP_NIGHT : REAL := 26.0;
    COOL_STOP_TEMP : REAL := 24.0;
    START_DAY : UDINT := 32400000;
    START_NIGHT : UDINT := 75600000;
    CYCLE_TIME : TIME := t#10m;
  END_VAR
  VAR_OUTPUT
    T_EXT : REAL;
    HEAT : BOOL;
    COOL : BOOL;
  END_VAR
  VAR
    tx : TIME;
    last_run : TIME;
    init : BOOL;
    cool_start : UDINT;
    cool_stop : UDINT;
    heat_start : UDINT;
    heat_stop : UDINT;
    xdate : UDINT;
    day : BOOL;
  END_VAR

  IF NOT init THEN
  	init := TRUE;
  	heat_start := SET_DATE(1972,MONTH_OF_DATE(heat_period_start),DAY_OF_MONTH(heat_period_start));
  	heat_stop := SET_DATE(1972,MONTH_OF_DATE(heat_period_stop),DAY_OF_MONTH(heat_period_stop));
  	cool_start := SET_DATE(1972,MONTH_OF_DATE(cool_period_start),DAY_OF_MONTH(cool_period_start));
  	cool_stop := SET_DATE(1972,MONTH_OF_DATE(cool_period_stop),DAY_OF_MONTH(cool_period_stop));
  END_IF;

  (* read system time *)
  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));

  (* for efficiency exit isf this program has been executed less then 1min ago *)
  IF tx - last_run < cycle_time THEN RETURN; END_IF;

  (* calculate frequently used variables *)
  xdate := SET_DATE(1972,MONTH_OF_DATE(DT_TO_DATE_2(dt_in)),DAY_OF_MONTH(DT_TO_DATE_2(dt_in)));
  day := DT_TO_TOD_2(dt_in) >= start_day AND  DT_TO_TOD_2(dt_in) < start_night;

  (* read the correct external temperature depending on the t_ext_config setting *)
  t_ext := MULTI_IN(t_ext1, t_ext2, t_ext3, t_ext_default, t_ext_min, t_ext_max, t_ext_config);

  (* dtermine heating *)
  IF (heat_start <= heat_stop AND xdate >= heat_start AND xdate <= heat_stop) OR (heat_start > heat_stop AND (xdate >= heat_start OR xdate <= heat_stop)) THEN
  	(* heating period id true check for temperature *)
  	IF day AND t_ext <= heat_start_temp_day THEN
  		heat := TRUE;
  	ELSIF NOT day AND t_ext <= heat_start_temp_night THEN
  		heat := TRUE;
  	ELSIF t_ext >= heat_stop_temp THEN
  		heat := FALSE;
  	END_IF;
  ELSE
  	heat := FALSE;
  END_IF;

  (* dtermine cooling *)
  IF (cool_start <= cool_stop AND xdate >= cool_start AND xdate <= cool_stop) OR (cool_start > cool_stop AND (xdate >= cool_start OR xdate <= cool_stop)) THEN
  	(* cooling period is true check for temperature *)
  	IF day AND t_ext >= cool_start_temp_day THEN
  		cool := TRUE;
  	ELSIF NOT day AND t_ext >= cool_start_temp_night THEN
  		cool := TRUE;
  	ELSIF t_ext <= cool_stop_temp THEN
  		cool := FALSE;
  	END_IF;
  ELSE
  	cool := FALSE;
  END_IF;

  last_run := tx;

  (* From OSCAT LIBRARY, www.oscat.de *)
  (* many FB's required :-)  *)
END_FUNCTION_BLOCK


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
