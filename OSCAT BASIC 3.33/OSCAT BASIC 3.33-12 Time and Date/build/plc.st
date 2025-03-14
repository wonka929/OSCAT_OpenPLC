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
  OSCAT_SDT : STRUCT
    YEAR : INT;
    MONTH : INT;
    DAY : INT;
    WEEKDAY : INT;
    HOUR : INT;
    MINUTE : INT;
    SECOND : INT;
    MS : INT;
  END_STRUCT;
END_TYPE

FUNCTION HOUR : INT
  VAR_INPUT
    ITOD : UDINT;
  END_VAR

  hour := UDINT_TO_INT(itod / UDINT#3600000);

  (* From OSCAT Library, www.oscat.de *)
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

FUNCTION SET_DT : UDINT
  VAR_INPUT
    YEAR : INT;
    MONTH : INT;
    DAY : INT;
    _HOUR : INT;
    MINUTE : INT;
    SECOND : INT;
  END_VAR

  SET_DT := SET_DATE(YEAR, MONTH, DAY) + INT_TO_UDINT(SECOND) + INT_TO_UDINT(MINUTE) * UDINT#60 + INT_TO_UDINT(_HOUR) * UDINT#3600;

  (* From OSCAT Library, www.oscat.de *)
  (* SET_DATW requires *)
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

FUNCTION DST : BOOL
  VAR_INPUT
    UTC : UDINT;
  END_VAR
  VAR
    yr : INT;
    yr4 : UDINT;
    ltc : UDINT;
    idate : UDINT;
  END_VAR

  yr := YEAR_OF_DATE(_DT_TO_DATE(UTC));
  ltc := UTC;
  idate := SET_DT(yr, 3, 31, 1, 0, 0);
  yr4 := DWORD_TO_UDINT(SHR(INT_TO_DWORD(5 * yr), 2)) + UDINT#1;
  DST := (idate - ((yr4 + UDINT#3) MOD UDINT#7) * UDINT#86400 <= ltc) AND (idate + (UDINT#214 - (yr4) MOD UDINT#7) * UDINT#86400 > ltc);

  (* From OSCAT Library, www.oscat.de *)
  (* YEAR_OF_DATE, _DT_TO_DATE, SET_DT requires *)
END_FUNCTION

FUNCTION UTC_TO_LTIME : UDINT
  VAR_INPUT
    UTC : UDINT;
    DST_ENABLE : BOOL;
    TIME_ZONE_OFFSET : INT;
  END_VAR
  VAR
    tmp : INT;
  END_VAR

  UTC_TO_LTIME := UTC + INT_TO_UDINT(TIME_ZONE_OFFSET) * UDINT#60 + BOOL_TO_UDINT(DST_ENABLE AND DST(UTC)) * UDINT#3600;


  tmp := TIME_ZONE_OFFSET * 60 + BOOL_TO_INT(DST_ENABLE AND DST(UTC)) * 3600;
  IF tmp < 0 THEN
  	UTC_TO_LTIME := UTC - INT_TO_UDINT(ABS(tmp));
  ELSE
  	UTC_TO_LTIME := UTC + INT_TO_UDINT(tmp);
  END_IF;


  (* From OSCAT Library, www.oscat.de *)
  (* DST requiered *)
END_FUNCTION

FUNCTION SECOND_TO_TIME : TIME
  VAR_INPUT
    IN : REAL;
  END_VAR

  second_to_time := UDINT_TO_TIME(REAL_TO_UDINT(IN * 1000.0));

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION LEAP_OF_DATE : BOOL
  VAR_INPUT
    IDATE : UDINT;
  END_VAR

  LEAP_OF_DATE := SHL(UDINT_TO_DWORD((idate + UDINT#43200) / UDINT#31557600), 30) = DWORD#16#80000000;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION MINUTE_TO_TIME : TIME
  VAR_INPUT
    IN : REAL;
  END_VAR

  minute_to_time := UDINT_TO_TIME(REAL_TO_UDINT(IN * 60000.0));

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

FUNCTION HOUR_TO_TOD : UDINT
  VAR_INPUT
    IN : REAL;
  END_VAR

  hour_to_tod := REAL_TO_UDINT(IN * 3600000.00);

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION SUN_MIDDAY : UDINT
  VAR_INPUT
    LON : REAL;
    UTC : UDINT;
  END_VAR
  VAR
    _t : REAL;
    offset : REAL;
  END_VAR

  _T := INT_TO_REAL(DAY_OF_YEAR(utc));
  OFFSET := -0.1752 * SIN(0.033430 * _T + 0.5474) - 0.1340 * SIN(0.018234 * _T - 0.1939);
  SUN_MIDDAY := HOUR_TO_TOD(12.0 - OFFSET - lon * 0.0666666666666);

  (* HOUR_TO_TOD required *)
  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION SET_TOD : UDINT
  VAR_INPUT
    _HOUR : INT;
    MINUTE : INT;
    SECOND : REAL;
  END_VAR

  set_Tod := REAL_TO_UDINT(second * 1000.0) + INT_TO_UDINT(minute) * UDINT#60000 + INT_TO_UDINT(_hour) * UDINT#3600000;

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
  	T_PLC_MS := (SHL(T_PLC_MS,N) OR SHL(DWORD#1,N)-1) + OFFSET;
  END_IF;
  *)

  (* From OSCAT library, www.oscat.de

  this is a temporary T_PLC_MS FB until OpenPLC gets it´s own time() functionality *)

  (* PLC_TIME and Global variables PLC_SCAN_CYCL and PLC_CYCL_TIME required *)
END_FUNCTION

FUNCTION_BLOCK RTC_MS
  VAR_INPUT
    SET : BOOL;
    SDT : UDINT;
    SMS : INT;
  END_VAR
  VAR_OUTPUT
    XDT : UDINT;
    XMS : INT;
  END_VAR
  VAR
    init : BOOL;
    last : UDINT;
    tx : UDINT;
  END_VAR

  tx:= T_PLC_MS(en:=true);

  IF set OR NOT init THEN
  	(* clock needs to be set when set is true or after power up *)
  	init := TRUE;
  	xdt := SDT;
  	XMS := SMS;
  ELSE
  	XMS := XMS + UDINT_TO_INT(tx - last);
  	(* check if one second has expired *)
  	IF XMS > 999 THEN
  		XDT := XDT + UDINT#1; (* add one second *)
  		XMS := XMS - 1000;
  	END_IF;
  END_IF;
  last := tx;

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS required *)
END_FUNCTION_BLOCK

FUNCTION TIME_TO_TOD : UDINT
  VAR_INPUT
    IN : TIME;
  END_VAR

  TIME_TO_TOD := DWORD_TO_UDINT(TIME_TO_DWORD(IN));


  (* From OSCAT LIBRARY, www.oscat.de *)
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

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION DAYS_IN_MONTH : INT
  VAR_INPUT
    IDATE : UDINT;
  END_VAR

  DAYS_IN_MONTH := DAY_OF_YEAR(IDATE);
  IF LEAP_OF_DATE(IDATE) THEN
  	CASE DAYS_IN_MONTH OF
  		32..60	:	DAYS_IN_MONTH := 29;
  		92..121 :	DAYS_IN_MONTH := 30;
  		153..182:	DAYS_IN_MONTH := 30;
  		245..274:	DAYS_IN_MONTH := 30;
  		306..335:	DAYS_IN_MONTH := 30;
  	ELSE
  		DAYS_IN_MONTH := 31;
  	END_CASE;
  ELSE
  	CASE DAYS_IN_MONTH OF
  		32..59	:	DAYS_IN_MONTH := 28;
  		91..120 :	DAYS_IN_MONTH := 30;
  		152..181:	DAYS_IN_MONTH := 30;
  		244..273:	DAYS_IN_MONTH := 30;
  		305..334:	DAYS_IN_MONTH := 30;
  	ELSE
  		DAYS_IN_MONTH := 31;
  	END_CASE;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION PERIOD : BOOL
  VAR_INPUT
    D1 : UDINT;
    D2 : UDINT;
    DX : UDINT;
  END_VAR
  VAR
    day1 : INT;
    day2 : INT;
    dayx : INT;
  END_VAR

  day1 := day_of_year(d1);
  day2 := day_of_year(d2);
  dayx := day_of_year(dx);
  IF NOT leap_of_Date(dx) AND dayx > 58 THEN dayx := dayx + 1; END_IF;
  IF NOT leap_of_Date(d1) AND day1 > 58 THEN day1 := day1 + 1; END_IF;
  IF NOT leap_of_Date(d2) AND day2 > 58 THEN day2 := day2 + 1; END_IF;

  IF day2 < day1 THEN
  	(* the period spans over the new year *)
  	period := dayx <= day2 OR dayx >= day1;
  ELSE
  	period := dayx >= day1 AND dayx <= day2;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION LEAP_DAY : BOOL
  VAR_INPUT
    IDATE : UDINT;
  END_VAR

  LEAP_DAY := IDATE MOD UDINT#126230400 = UDINT#68169600;

  (* From OSCAT LIBRARY, www.oscat.de *)
END_FUNCTION

FUNCTION BIT_OF_DWORD : BOOL
  VAR_INPUT
    IN : DWORD;
    N : INT;
  END_VAR

  BIT_OF_DWORD := (SHR(in,N) AND 16#00000001) > 0;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION MINUTE_OF_DT : INT
  VAR_OUTPUT
    XDT : UDINT;
  END_VAR

  MINUTE_OF_DT := UDINT_TO_INT((XDT MOD UDINT#3600) / UDINT#60);

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION LEAP_YEAR : BOOL
  VAR_INPUT
    YEAR : INT;
  END_VAR

  IF (year MOD INT#400) = INT#00 THEN
    leap_year := TRUE;
  ELSIF (year MOD INT#100) = INT#00 THEN
    leap_year := FALSE;
  ELSIF (year MOD INT#04) = INT#00 THEN
    leap_year := TRUE;
  ELSE
    leap_year := FALSE;
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

FUNCTION DATE_ADD : UDINT
  VAR_INPUT
    IDATE : UDINT;
    _D : INT;
    W : INT;
    M : INT;
    Y : INT;
  END_VAR
  VAR
    mo : INT;
    yr : INT;
    dm : INT;
  END_VAR

  DATE_ADD := IDATE + INT_TO_UDINT(_D + W * 7) * UDINT#86400;
  yr := Y + YEAR_OF_DATE(DATE_ADD);
  mo := M + MONTH_OF_DATE(DATE_ADD);
  dm := DAY_OF_MONTH(DATE_ADD);
  WHILE mo > 12 DO
  	mo := mo - 12;
  	yr := yr + 1;
  END_WHILE;
  WHILE mo < 1 DO
  	mo := mo + 12;
  	yr := yr - 1;
  END_WHILE;
  DATE_ADD := SET_DATE(yr, mo, dm);

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION DAY_TO_TIME : TIME
  VAR_INPUT
    IN : REAL;
  END_VAR

  day_to_time := DINT_TO_TIME(UDINT_TO_DINT(REAL_TO_UDINT(IN * REAL#86400000.00)));

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

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

PROGRAM program0
  VAR
    LocalVar0 : DINT;
    LocalVar1 : DINT;
    LocalVar2 : DINT;
    ADD1_OUT : DINT;
  END_VAR

  ADD1_OUT := ADD(LocalVar0, LocalVar1);
END_PROGRAM

FUNCTION YEAR_BEGIN : UDINT
  VAR_INPUT
    Y : INT;
  END_VAR

  year_begin := DWORD_TO_UDINT(SHR(UDINT_TO_DWORD(INT_TO_UDINT(y) * UDINT#1461 - UDINT#2878169),2))  *  UDINT#86400;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION _MULTIME : TIME
  VAR_INPUT
    _T : TIME;
    M : REAL;
  END_VAR

  _multime := DWORD_TO_TIME(REAL_TO_DWORD(DWORD_TO_REAL(TIME_TO_DWORD(_t))*M));

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION HOUR_TO_TIME : TIME
  VAR_INPUT
    IN : REAL;
  END_VAR

  hour_to_time := UDINT_TO_TIME(REAL_TO_UDINT(IN * 3600000.0));

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION HOUR_OF_DT : INT
  VAR_INPUT
    XDT : UDINT;
  END_VAR

  HOUR_OF_DT := UDINT_TO_INT((XDT MOD UDINT#86400) / UDINT#3600);

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION _MINUTE : INT
  VAR_INPUT
    ITOD : UDINT;
  END_VAR

  _minute := UDINT_TO_INT((itod / UDINT#60000) - ((itod / UDINT#3600000) * UDINT#60));

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION BIT_LOAD_W : WORD
  VAR_INPUT
    IN : WORD;
    VAL : BOOL;
    POS : INT;
  END_VAR

  IF VAL THEN
  	BIT_LOAD_W := in OR SHL(WORD#1,pos);
  ELSE
  	BIT_LOAD_W := in AND (NOT SHL(WORD#1,pos));
  END_IF;

  (*From OSCAT Library, www.oscat.de*)
END_FUNCTION

FUNCTION DAY_OF_WEEK : INT
  VAR_INPUT
    IDATE : UDINT;
  END_VAR

  DAY_OF_WEEK := UDINT_TO_INT((idate / UDINT#86400 + UDINT#3) MOD UDINT#7) + INT#01;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK DT2_TO_SDT
  VAR_INPUT
    DI : UDINT;
    TI : UDINT;
  END_VAR
  VAR_IN_OUT
    SDT : OSCAT_SDT;
  END_VAR

  SDT.YEAR := YEAR_OF_DATE(di);
  SDT.MONTH := MONTH_OF_DATE(di);
  SDT.DAY := DAY_OF_MONTH(di);
  SDT.WEEKDAY := DAY_OF_WEEK(di);
  SDT.MS := UDINT_TO_INT(ti MOD UDINT#1000);
  SDT.SECOND := UDINT_TO_INT((ti / UDINT#1000) MOD UDINT#60);
  SDT.MINUTE := UDINT_TO_INT((ti / UDINT#60000) MOD UDINT#60);
  SDT.HOUR := UDINT_TO_INT(ti / UDINT#3600000);

  (* From OSCAT Library, www.oscat.de *)
  (* OSCAT_SDT (datatypa) requiered *)
END_FUNCTION_BLOCK

FUNCTION _DT_TO_TOD : UDINT
  VAR_INPUT
    IN : UDINT;
  END_VAR

  _DT_TO_TOD := (IN MOD UDINT#86400) * UDINT#1000;

END_FUNCTION

FUNCTION REFRACTION : REAL
  VAR_INPUT
    ELEV : REAL;
  END_VAR
  VAR
    tmp : REAL;
  END_VAR

  tmp := LIMIT(-1.9, elev, 80.0);
  REFRACTION := 0.0174532925199433 / TAN(0.0174532925199433 * (tmp + 10.3 / (tmp + 5.11)));

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK SUN_POS
  VAR_INPUT
    LATITUDE : REAL;
    LONGITUDE : REAL;
    UTC : UDINT;
  END_VAR
  VAR_OUTPUT
    B : REAL;
    HR : REAL;
  END_VAR
  VAR
    g : REAL;
    a : REAL;
    _d : REAL;
    h : REAL;
    t1 : REAL;
    n : REAL;
    _e : REAL;
    c : REAL;
    tau : REAL;
    sin_d : REAL;
    rlat : REAL;
    sin_lat : REAL;
    cos_lat : REAL;
    cos_tau : REAL;
    cos_d : REAL;
    Math_PI : REAL := 3.14159265358979323846264338327950288;
    Math_PI2 : REAL := 6.28318530717958647692528676655900576;
  END_VAR

  (* EXIT the routine IF it was executed within 10 seconds which is equal to 0.04 degrees accuracy
  depending on startup conditions this could lead to a lockup for 10 seconds and not delivering a usable position
  tx := T_PLC_MS();
  IF tx - last < 10000 THEN RETURN; END_IF;
  last := tx;
  *)

  (* n is the julian date and the number of days since 1.1.2000-12:00 midday *)
  (* be careful for step7 date startes 1.1.1990 instead of 1.1.1970 *)
  (* for step7 this line must change *)
  n := UDINT_TO_REAL(UTC - UDINT#946728000) * 0.000011574074074074;
  g :=MODR(6.240040768 + 0.01720197 * n, MATH_PI2);
  _d := MODR(4.89495042 + 0.017202792 * n, MATH_PI2) + 0.033423055 * SIN(g) + 0.000349066 * SIN(2.0*g);
  _e := 0.409087723 - 0.000000006981317008 * n;
  cos_d := COS(_d);
  sin_d := SIN(_d);
  a := ATAN(COS(_e) * sin_d / cos_d);
  IF cos_d < 0.0 THEN a := a + MATH_PI; END_IF;
  c := ASIN(SIN(_e) * sin_d);

  (* also here we must be very careful utc is from 1.1.1970 for step7 the formula must change *)
  tau := RAD(MODR(6.697376 + (n - 0.25) * 0.0657098245037645 + UDINT_TO_REAL(_DT_TO_TOD(utc)) * 0.0000002785383333, 24.0) * 15.0 + longitude) - a;
  rlat := RAD(latitude);
  sin_lat := SIN(rlat);
  cos_lat := COS(rlat);
  cos_tau := COS(tau);
  t1 := cos_tau * sin_lat - TAN(c) * cos_lat;
  B := ATAN(SIN(tau) / t1);
  IF t1 < 0.0 THEN B := B + MATH_PI2; ELSE B := B + MATH_PI; END_IF;
  B := DEG(MODR(B, MATH_PI2));
  h := DEG(ASIN(COS(C) * cos_tau * cos_lat +SIN(c) * sin_lat));
  IF h > 180.0 THEN h := h - 360.0; END_IF;
  (* consider refraction *)
  HR := h + REFRACTION(h);

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK SUN_TIME
  VAR_INPUT
    LATITUDE : REAL;
    LONGITUDE : REAL;
    UTC : UDINT;
    H : REAL := -0.83333333333;
  END_VAR
  VAR_OUTPUT
    MIDDAY : UDINT;
    SUN_RISE : UDINT;
    SUN_SET : UDINT;
    SUN_DECLINATION : REAL;
  END_VAR
  VAR
    DK : REAL;
    delta : UDINT;
    b : REAL;
  END_VAR

  B := latitude * 0.0174532925199433;
  MIDDAY := SUN_MIDDAY(longitude, utc);
  DK := 0.40954 * SIN(0.0172 * (INT_TO_REAL(DAY_OF_YEAR(utc)) - 79.35));
  sun_declination := DEG(DK);
  IF sun_declination > 180.0 THEN sun_declination := sun_declination - 360.0; END_IF;
  sun_declination := 90.0 - LATITUDE + sun_declination;
  delta := TIME_TO_UDINT(HOUR_TO_TIME(ACOS((SIN(RAD(H)) - SIN(B) * SIN(DK)) / (COS(B) * COS(DK))) * 3.819718632));
  sun_rise := MIDDAY - delta;
  sun_set := MIDDAY + delta;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION LTIME_TO_UTC : UDINT
  VAR_INPUT
    LTIME : UDINT;
    _DST : BOOL;
    TIME_ZONE_OFFSET : INT;
  END_VAR

  LTIME_TO_UTC := LTIME - INT_TO_UDINT(TIME_ZONE_OFFSET * 60);
  IF _DST THEN LTIME_TO_UTC := LTIME_TO_UTC - UDINT#3600; END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK SDT_TO_DATE
  VAR_INPUT
    DTI : OSCAT_SDT;
  END_VAR
  VAR_OUTPUT
    _SDT_TO_DATE : UDINT;
  END_VAR

  _SDT_TO_DATE := SET_DATE(DTI.YEAR, DTI.MONTH, DTI.DAY);

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION _SECOND : REAL
  VAR_INPUT
    ITOD : UDINT;
  END_VAR

  _second := UDINT_TO_REAL(itod MOD UDINT#60000) / REAL#1000.00;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION JD2000 : REAL
  VAR_INPUT
    DTI : UDINT;
  END_VAR

  JD2000 := UDINT_TO_REAL(DTI - UDINT#946728000) / 86400.0;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION DAYS_IN_YEAR : INT
  VAR_INPUT
    IDATE : UDINT;
  END_VAR

  IF LEAP_OF_DATE(IDATE) THEN
  	DAYS_IN_YEAR := 366;
  ELSE
  	DAYS_IN_YEAR := 365;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION DATE_TO_DT : UDINT
  VAR_INPUT
    IN : UDINT;
  END_VAR

  DATE_TO_DT := IN;


  (* From OSCAT LIBRARY, www.oscat.de *)
END_FUNCTION

FUNCTION MONTH_BEGIN : UDINT
  VAR_INPUT
    IDATE : UDINT;
  END_VAR

  MONTH_BEGIN := idate - INT_TO_UDINT(DAY_OF_MONTH(idate) - 1) * UDINT#86400;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION YEAR_END : UDINT
  VAR_INPUT
    Y : INT;
  END_VAR

  YEAR_END := DWORD_TO_UDINT(SHR(UDINT_TO_DWORD(INT_TO_UDINT(y) * UDINT#1461 - UDINT#2876712), 2)) * UDINT#86400;

  (* From OSCAT LIBRARY, www.oscat.de *)
END_FUNCTION

FUNCTION EVEN : BOOL
  VAR_INPUT
    IN : DINT;
  END_VAR

  even := NOT BIT_OF_DWORD(DINT_TO_DWORD(in),0);
  (* from OSCAT library; www.oscat.de  *)
  (* BIT_OF_DWORD required *)
END_FUNCTION

FUNCTION_BLOCK DCF77
  VAR_INPUT
    REC : BOOL;
    SET : BOOL;
    SDT : UDINT;
    DSI : BOOL;
    SYNC_TIMEOUT : TIME := t#2m;
    TIME_OFFSET : INT := 1;
    DST_EN : BOOL := TRUE;
  END_VAR
  VAR_OUTPUT
    _TP : BOOL;
    DS : BOOL;
    WDAY : INT;
    ERROR : BOOL := TRUE;
    _RTC : UDINT;
    RTC1 : UDINT;
    MSEC : INT;
    SYNC : BOOL;
  END_VAR
  VAR
    MEZ : UDINT;
    UTC : UDINT;
    state : INT;
    edge : BOOL;
    tx : TIME;
    ty : TIME;
    last : TIME;
    bits : ARRAY [0..58] OF BOOL;
    cnt : INT;
    i : INT;
    old_time : UDINT;
    minute : INT;
    _hour : INT;
    day : INT;
    month : INT;
    year : INT;
    last_sync : TIME;
    t1 : TIME;
    tz : TIME;
    init : BOOL;
    word_temp : WORD;
    bool_temp : BOOL;
  END_VAR

  (* if tp was set it should only be active for 1 cycle *)
  _TP := FALSE;

  (* read system time *)
  t1:= UDINT_TO_TIME(T_PLC_MS(en:=true));
  tx := t1 - last;

  IF rec XOR edge THEN
  	edge := rec;
  	IF NOT rec AND tx > t#1700ms AND tx < t#2000ms THEN
  		(* start condition reached *)
  		state := 0;
  		_tp := NOT error;
  	ELSIF NOT rec AND tx > t#700ms AND tx < t#1000ms THEN
  		(* second switch detected *)
  		IF state < 58 THEN state := state +1; ELSE state := 0; END_IF;
  	ELSIF rec AND tx  < t#120ms THEN
  		(* bit 0 detected  *)
  		bits[state] := FALSE;
  	ELSIF rec AND tx > t#120ms AND tx < t#250ms THEN
  		(* bit 1 detected *)
  		bits[state] := TRUE;
  	ELSE
  		(* error condition received signal is not valid *)
  		error := TRUE;
  		state := 0;
  	END_IF;
  	last := last + tx;
  	IF rec AND state = 58 THEN
  		error := FALSE;

  		(* decode the bits and check for possible errors *)
  		IF bits[0] OR NOT (bits[17] XOR bits[18]) OR NOT bits[20] THEN error := TRUE; END_IF;
  		(* decode minute *)
          word_temp := WORD#0;

          bool_temp:=bits[21];
          word_temp:=BIT_LOAD_W(word_temp,bool_temp,0);    (* word_temp.X0 := bits[21]; *)
          bool_temp:=bits[22];
          word_temp:=BIT_LOAD_W(word_temp,bool_temp,1);    (* word_temp.X1 := bits[22]; *)
          bool_temp:=bits[23];
          word_temp:=BIT_LOAD_W(word_temp,bool_temp,2);    (* word_temp.X2 := bits[23]; *)
          bool_temp:=bits[24];
          word_temp:=BIT_LOAD_W(word_temp,bool_temp,3);    (* word_temp.X3 := bits[24]; *)

          minute := WORD_TO_INT(word_temp);
  		IF bits[25] THEN minute := minute +10; END_IF;
  		IF bits[26] THEN minute := minute +20; END_IF;
  		IF bits[27] THEN minute := minute +40; END_IF;
  		IF minute > 59 OR (bits[21] XOR bits[22] XOR bits[23] XOR bits[24] XOR bits[25] XOR bits[26] XOR bits[27] XOR bits[28]) THEN error := TRUE; END_IF;

  		(* decode hour *)
          word_temp := WORD#0;

          bool_temp:=bits[29];
          word_temp:=BIT_LOAD_W(word_temp,bool_temp,0);    (* word_temp.X0 := bits[29]; *)
          bool_temp:=bits[30];
          word_temp:=BIT_LOAD_W(word_temp,bool_temp,1);    (* word_temp.X1 := bits[30]; *)
          bool_temp:=bits[31];
          word_temp:=BIT_LOAD_W(word_temp,bool_temp,2);    (* word_temp.X2 := bits[31]; *)
          bool_temp:=bits[32];
          word_temp:=BIT_LOAD_W(word_temp,bool_temp,3);    (* word_temp.X3 := bits[32]; *)

          _hour := WORD_TO_INT(word_temp);
  		IF bits[33] THEN _hour := _hour +10; END_IF;
  		IF bits[34] THEN _hour := _hour +20; END_IF;
  		IF _hour > 23 OR (bits[29] XOR bits[30] XOR bits[31] XOR bits[32] XOR bits[33] XOR bits[34] XOR bits[35]) THEN error := TRUE; END_IF;

  		(* decode day of month *)
          word_temp := WORD#0;

          bool_temp:=bits[36];
          word_temp:=BIT_LOAD_W(word_temp,bool_temp,0);    (* word_temp.X0 := bits[36]; *)
          bool_temp:=bits[37];
          word_temp:=BIT_LOAD_W(word_temp,bool_temp,1);    (* word_temp.X1 := bits[37]; *)
          bool_temp:=bits[38];
          word_temp:=BIT_LOAD_W(word_temp,bool_temp,2);    (* word_temp.X2 := bits[38]; *)
          bool_temp:=bits[39];
          word_temp:=BIT_LOAD_W(word_temp,bool_temp,3);    (* word_temp.X3 := bits[39]; *)

          day := WORD_TO_INT(word_temp);
  		IF bits[40] THEN day := day + 10; END_IF;
  		IF bits[41] THEN day := day + 20; END_IF;
  		IF day > 31 THEN error := TRUE; END_IF;

  		(* decode day of week *)
          word_temp := WORD#0;

          bool_temp:=bits[42];
          word_temp:=BIT_LOAD_W(word_temp,bool_temp,0);    (* word_temp.X0 := bits[42]; *)
          bool_temp:=bits[43];
          word_temp:=BIT_LOAD_W(word_temp,bool_temp,1);    (* word_temp.X1 := bits[43]; *)
          bool_temp:=bits[44];
          word_temp:=BIT_LOAD_W(word_temp,bool_temp,2);    (* word_temp.X2 := bits[44]; *)

          wday := WORD_TO_INT(word_temp);
  		IF wday > 7 OR wday < 1 THEN error := TRUE; END_IF;

  		(* decode month *)
          word_temp := WORD#0;

          bool_temp:=bits[45];
          word_temp:=BIT_LOAD_W(word_temp,bool_temp,0);    (* word_temp.X0 := bits[45]; *)
          bool_temp:=bits[46];
          word_temp:=BIT_LOAD_W(word_temp,bool_temp,1);    (* word_temp.X1 := bits[46]; *)
          bool_temp:=bits[47];
          word_temp:=BIT_LOAD_W(word_temp,bool_temp,2);    (* word_temp.X2 := bits[47]; *)
          bool_temp:=bits[48];
          word_temp:=BIT_LOAD_W(word_temp,bool_temp,3);    (* word_temp.X3 := bits[48]; *)

          month := WORD_TO_INT(word_temp);
  		IF bits[49] THEN month := month +10; END_IF;
  		IF month > 12 THEN error := TRUE; END_IF;

  		(* decode year *)
          word_temp := WORD#0;

          bool_temp:=bits[50];
          word_temp:=BIT_LOAD_W(word_temp,bool_temp,0);    (* word_temp.X0 := bits[50]; *)
          bool_temp:=bits[51];
          word_temp:=BIT_LOAD_W(word_temp,bool_temp,1);    (* word_temp.X1 := bits[51]; *)
          bool_temp:=bits[52];
          word_temp:=BIT_LOAD_W(word_temp,bool_temp,2);    (* word_temp.X2 := bits[52]; *)
          bool_temp:=bits[53];
          word_temp:=BIT_LOAD_W(word_temp,bool_temp,3);    (* word_temp.X3 := bits[53]; *)

          year := WORD_TO_INT(word_temp);
  		IF bits[54] THEN year := year + 10; END_IF;
  		IF bits[55] THEN year := year + 20; END_IF;
  		IF bits[56] THEN year := year + 40; END_IF;
  		IF bits[57] THEN year := year + 80; END_IF;

  		(* check parity for bits 36 to 58 *)
  		cnt := 0;
  		FOR i := 36 TO 58 DO IF bits[i] THEN cnt := cnt + 1; END_IF; END_FOR;
  		IF NOT even(INT_TO_DINT(cnt)) THEN error := TRUE; END_IF;

  		(* time must be valid for two cycles to clear error flag *)
  		IF NOT error THEN
  			(* set outputs *)
  			old_time := mez;
  			IF year >= 70 THEN year := year + 1900; ELSE year := year + 2000; END_IF;
  			mez := set_DT(year,month,day,_hour,minute,0);
  			DS := bits[17];
  			IF DS THEN
  				UTC := mez - UDINT#7200;
  			ELSE
  				UTC := mez - UDINT#3600;
  			END_IF;

  			(* set trigger signal only if the receiver has received 2 successive minutes *)
  			IF mez <> old_time + TIME_TO_UDINT(t#1m) THEN error := TRUE ; END_IF;
  		END_IF;
  	END_IF;
  END_IF;

  (* this portion implements a free running clock which is triggered by the dcf77 signal *)
  tz := UDINT_TO_TIME(INT_TO_UDINT(ABS(time_offset))* UDINT#3600000);

  (* input sdt is copied to utc at first power up *)
  IF NOT init OR SET THEN
  	init := TRUE;
  	utc := sdt;
  	_tp := TRUE;
  	DS := DSI;
  END_IF;

  IF _tp THEN
  	_rtc := utc;
  	IF DS AND dst_en THEN
  		IF time_offset < 0 THEN
          	rtc1 := _rtc - TIME_TO_UDINT(tz + t#1h);
          ELSE 
              rtc1 := _rtc + TIME_TO_UDINT(tz + t#1h);
          END_IF;
  	ELSE
  		IF time_offset < 0 THEN
              rtc1 := _rtc - TIME_TO_UDINT(tz);
          ELSE
              rtc1 := _rtc + TIME_TO_UDINT(tz);
          END_IF;
  	END_IF;
  	sync := TRUE;
  	last_sync := last;
  	ty := last;
  ELSIF _rtc > UDINT#0 AND T1 - ty >= t#1s THEN
  	_rtc := _rtc + TIME_TO_UDINT(t#1s);
  	rtc1 := rtc1 + TIME_TO_UDINT(t#1s);
  	ty := ty + t#1s;
  	sync := ty - last_sync < sync_timeout AND last_sync > t#0s;
  	wday := DAY_OF_WEEK(_DT_TO_DATE(rtc1));
  	DS := dst_en AND DST(utc);
  END_IF;
  msec := TIME_TO_INT(t1 - ty);

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS requiered *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK SDT_TO_DT
  VAR_INPUT
    DTI : OSCAT_SDT;
  END_VAR
  VAR_OUTPUT
    _SDT_TO_DT : UDINT;
  END_VAR

  _SDT_TO_DT := SET_DT(DTI.YEAR, DTI.MONTH, DTI.DAY, DTI.HOUR, DTI.MINUTE, DTI.SECOND);

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK DT_TO_SDT
  VAR_INPUT
    DTI : UDINT;
  END_VAR
  VAR_OUTPUT
    SDT : OSCAT_SDT;
  END_VAR
  VAR
    tmp : UDINT;
    tdt : UDINT;
  END_VAR

  tmp := _DT_TO_DATE(dti);
  tdt := dti - tmp;
  SDT.YEAR := YEAR_OF_DATE(tmp);
  SDT.MONTH := MONTH_OF_DATE(tmp);
  SDT.DAY := DAY_OF_MONTH(tmp);
  SDT.WEEKDAY := DAY_OF_WEEK(tmp);
  SDT.SECOND := UDINT_TO_INT(tdt MOD UDINT#60);
  SDT.MINUTE := UDINT_TO_INT((tdt / UDINT#60) MOD UDINT#60);
  SDT.HOUR := UDINT_TO_INT(tdt / UDINT#3600);

  (* From OSCAT Library, www.oscat.de *)
  (* OSCAT_SDT (datatype) requiered *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK SDT_TO_TOD
  VAR_INPUT
    DTI : OSCAT_SDT;
  END_VAR
  VAR_OUTPUT
    _SDT_TO_TOD : UDINT;
  END_VAR

  _SDT_TO_TOD := INT_TO_UDINT(DTI.HOUR) * UDINT#3600000 + INT_TO_UDINT(DTI.MINUTE) * UDINT#60000 + INT_TO_UDINT(DTI.SECOND) * UDINT#1000 + INT_TO_UDINT(DTI.MS);

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION TOD_TO_TIME : TIME
  VAR_INPUT
    IN : UDINT;
  END_VAR

  TOD_TO_TIME := DWORD_TO_TIME(UDINT_TO_DWORD(IN));

  (* From OSCAT LIBRARY, www.oscat.de *)
END_FUNCTION

FUNCTION DAYS_DELTA : DINT
  VAR_INPUT
    DATE_1 : UDINT;
    DATE_2 : UDINT;
  END_VAR

  IF DATE_1 > DATE_2 THEN
  	DAYS_DELTA := - UDINT_TO_DINT((date_1 - date_2) / UDINT#86400);
  ELSE
  	DAYS_DELTA :=   UDINT_TO_DINT((date_2 - date_1) / UDINT#86400);
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK RTC_2
  VAR_INPUT
    SET : BOOL;
    SDT : UDINT;
    SMS : INT;
    DEN : BOOL;
    OFS : INT;
  END_VAR
  VAR_OUTPUT
    UDT : UDINT;
    LDT : UDINT;
    DSO : BOOL;
    XMS : INT;
  END_VAR
  VAR
    RT : RTC_MS;
  END_VAR

  (* call rtc *)
  RT(SET := SET, SDT := SDT, SMS := SMS);
  UDT := rt.xdt;
  XMS := rt.XMS;

  (* check for daylight savings time and set dso output *)
  dso := DST(udt) AND DEN;

  (* calculate time offset and set ldt output *)
  LDT := UDT + INT_TO_UDINT(ofs + BOOL_TO_INT(DSO) * 60) * UDINT#60;

  (* From OSCAT Library, www.oscat.de *)
  (* RTC_MS required *)
END_FUNCTION_BLOCK

FUNCTION WORK_WEEK : INT
  VAR_INPUT
    IDATE : UDINT;
  END_VAR
  VAR
    d1 : UDINT;
    w1 : INT;
    ds : UDINT;
    yr : INT;
    w31 : INT;
    w01 : INT;
    wm : INT;
  END_VAR

  (* berechne den 1.1 des jahres von idate. *)
  yr := YEAR_OF_DATE(idate);
  d1 := year_begin(yr);
  (* wochentag von d1 *)
  w1 := DAY_OF_WEEK(d1);
  (* offset des montags der eletzten KW des vorjahres *)
  (* wenn der erste tag des jahres größer als donnerstag ist dann beginnt die letzte kw am montag davor *)
  (* wenn der erste tag des jahres ein donnerstag oder kleiner ist beginnt die erste kw 2 montage davor *)
  IF w1 < 5 THEN
  	ds := d1 - INT_TO_UDINT(w1+6) * UDINT#86400;
  ELSE
  	ds := d1 + INT_TO_UDINT(1-w1) * UDINT#86400;
  END_IF;

  (* kalenderwoche des eingangsdatums *)
  work_week := UDINT_TO_INT((idate - ds) / UDINT#604800);

  (* korrektur wenn work_week = 0 *)
  IF work_week = 0 THEN
  	(* work_week needs to be 53 when 1.jan of the year before is thursday or dec 31. is thursday. *)
  	(* first and last weekday of a year is equal and one more day for a leap_year. *)
  	IF w1 > 1 THEN w31 := w1 - 1; ELSE W31 := 7; END_IF;
  	IF leap_year(yr - 1) THEN IF w31 > 1 THEN w01 := W31 - 1; ELSE w1 := 7; END_IF; END_IF;
  	(* if first or last day of a year is a thursday, the year has 53 weeks *)
  	WORK_WEEK := 52 + BOOL_TO_INT(w31 = 4 OR w01 = 4);
  ELSE
  	(* end of year calculation *)
  	(* calculated the first and last weekday *)
  	IF leap_year(yr) THEN
  		IF w1 < 7 THEN w31 := w1 + 1; ELSE w31 := 1; END_IF;
  	ELSE
  		w31 := w1;
  	END_IF;
  	(* if first or last day is thursday then the year has 53 weeks otherwise only 52 *)
  	wm := 52 + BOOL_TO_INT(w31 = 4 OR w1 = 4);
  	IF work_week > wm THEN work_week := 1; END_IF;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION MONTH_END : UDINT
  VAR_INPUT
    IDATE : UDINT;
  END_VAR

  MONTH_END := SET_DATE(YEAR_OF_DATE(idate),MONTH_OF_DATE(idate)+1,1) - UDINT#86400;

  (* From OSCAT LIBRARY, www.oscat.de *)
END_FUNCTION

FUNCTION SECOND_OF_DT : INT
  VAR_INPUT
    XDT : UDINT;
  END_VAR

  SECOND_OF_DT := UDINT_TO_INT(XDT MOD UDINT#60);

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION EASTER : UDINT
  VAR_INPUT
    YEAR : INT;
  END_VAR
  VAR
    b : INT;
    c : INT;
    oday : INT;
  END_VAR

  b := (204 - 11 * (year MOD 19)) MOD 30;
  IF b > 27 THEN b := b - 1; END_IF;
  c := (year + WORD_TO_INT(SHR(INT_TO_WORD(year),2)) + b - 13) MOD 7;
  oday := 28 + b - c;
  IF oday > 33 THEN
  	easter := set_Date(year, 4, oday - 31);
  ELSE
  	easter := set_Date(year, 3, oday);
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION DAY_OF_DATE : DINT
  VAR_INPUT
    IDATE : UDINT;
  END_VAR

  day_of_date := UDINT_TO_DINT(idate / UDINT#86400);

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
