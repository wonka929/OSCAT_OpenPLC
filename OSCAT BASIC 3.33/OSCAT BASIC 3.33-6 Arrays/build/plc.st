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


FUNCTION D_TRUNC : DINT
  VAR_INPUT
    x : REAL;
  END_VAR

  D_TRUNC := REAL_TO_DINT(X);
  IF X > 0.0 THEN
  	IF DINT_TO_REAL(D_TRUNC) > X THEN D_TRUNC := D_TRUNC - DINT#1; END_IF;
  ELSE
  	IF DINT_TO_REAL(D_TRUNC) < X THEN D_TRUNC := D_TRUNC + DINT#1; END_IF;
  END_IF;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION FRACT : REAL
  VAR_INPUT
    X : REAL;
  END_VAR

  IF ABS(x) < 2.0E9 THEN
  	FRACT := x - DINT_TO_REAL(D_TRUNC(x));
  ELSE
  	FRACT := 0.0;
  END_IF;
  (* from OSCAT library; www.oscat.de  *)
  (* D_TRUNC required *)
END_FUNCTION

FUNCTION BIT_OF_DWORD : BOOL
  VAR_INPUT
    IN : DWORD;
    N : INT;
  END_VAR

  BIT_OF_DWORD := (SHR(in,N) AND 16#00000001) > 0;

  (* From Oscat Library, www.oscat.de *)
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

FUNCTION BIT_LOAD_DW : DWORD
  VAR_INPUT
    IN : DWORD;
    VAL : BOOL;
    POS : INT;
  END_VAR

  IF val THEN
  	BIT_LOAD_DW := in OR SHL(DWORD#1,pos);
  ELSE
  	BIT_LOAD_DW := in AND (NOT SHL(DWORD#1,pos));
  END_IF;

  (*From OSCAT Library, www.oscat.de*)
END_FUNCTION

FUNCTION BIT_COUNT : INT
  VAR_INPUT
    IN : DWORD;
  END_VAR
  VAR
    in_temp : DWORD;
  END_VAR

  in_temp := IN;
  WHILE in_temp > DWORD#0 DO
  	IF (in_temp AND DWORD#16#00000001) > DWORD#0 THEN Bit_Count := Bit_Count +1; END_IF;
  	in_temp := SHR(in_temp,1);
  END_WHILE;

  (*From OSCAT Library, www.oscat.de*)
END_FUNCTION

FUNCTION_BLOCK RDM
  VAR_INPUT
    LAST : REAL;
  END_VAR
  VAR_OUTPUT
    _RDM : REAL;
    tn : DWORD;
    tc : INT;
  END_VAR

  tn := UDINT_TO_DWORD(T_PLC_MS(en:=true));
  tc := Bit_Count(tn);

  tn:=BIT_LOAD_DW(tn,BIT_OF_DWORD(tn,2),31); (* tn.31 := tn.2; *)
  tn:=BIT_LOAD_DW(tn,BIT_OF_DWORD(tn,5),30); (* tn.30 := tn.5; *)
  tn:=BIT_LOAD_DW(tn,BIT_OF_DWORD(tn,4),29); (* tn.29 := tn.4; *)
  tn:=BIT_LOAD_DW(tn,BIT_OF_DWORD(tn,1),28); (* tn.28 := tn.1; *)
  tn:=BIT_LOAD_DW(tn,BIT_OF_DWORD(tn,0),27); (* tn.27 := tn.0; *)
  tn:=BIT_LOAD_DW(tn,BIT_OF_DWORD(tn,7),26); (* tn.26 := tn.7; *)
  tn:=BIT_LOAD_DW(tn,BIT_OF_DWORD(tn,6),25); (* tn.25 := tn.6; *)
  tn:=BIT_LOAD_DW(tn,BIT_OF_DWORD(tn,3),24); (* tn.24 := tn.3; *)

  tn := ROL(tn,Bit_Count(tn)) OR DWORD#16#80000001;
  tn := UDINT_TO_DWORD(DWORD_TO_UDINT(tn) MOD UDINT#71474513 + INT_TO_UDINT(tc) + UDINT#77);
  _RDM := fract(DWORD_TO_REAL(tn) / 10000000.0 * (2.71828182845904523536028747135266249 - LIMIT(0.0,last,1.0)));

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS required*)
END_FUNCTION_BLOCK

FUNCTION_BLOCK RDM2
  VAR_INPUT
    LAST : INT;
    LOW : INT;
    HIGH : INT;
  END_VAR
  VAR_OUTPUT
    _RDM2 : INT;
  END_VAR
  VAR
    _rdm : RDM;
  END_VAR

  _rdm(last:=fract(INT_TO_REAL(last) * 3.14159265358979323846264338327950288));
  _RDM2 := TRUNC(_rdm._RDM * INT_TO_REAL(high - low + 1)) + low;

  (* From OSCAT Library, www.oscat.de *)
  (* RDM required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK _ARRAY_SHUFFLE
  VAR_IN_OUT
    PT : ARRAY [1..100] OF REAL;
  END_VAR
  VAR_INPUT
    SIZE : UINT;
  END_VAR
  VAR_OUTPUT
    _ARRAY_SHUFFLE_Q : BOOL;
  END_VAR
  VAR
    temp : REAL;
    pos : INT;
    i : INT;
    stop : INT;
    _rdm2 : RDM2;
  END_VAR

  stop :=LIMIT(1,UINT_TO_INT(size),1000);
  FOR i := 1 TO stop DO
          _rdm2(last:=i+pos,low:=1,high:=stop);
          pos := _rdm2._rdm2;
          (* swap elements *)
          temp := pt[i];
          pt[i] := pt[pos];
          pt[pos] := temp;
  END_FOR;

  _ARRAY_SHUFFLE_Q := TRUE;
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

FUNCTION_BLOCK _ARRAY_ABS
  VAR_IN_OUT
    PT : ARRAY [1..100] OF REAL;
  END_VAR
  VAR_INPUT
    SIZE : UINT;
  END_VAR
  VAR_OUTPUT
    _ARRAY_ABS_Q : BOOL;
  END_VAR
  VAR
    i : INT;
    stop : INT;
  END_VAR

  stop :=LIMIT(1,UINT_TO_INT(size),1000);
  FOR i := 1 TO stop DO
  	 pt[i] := ABS(pt[i]);
  END_FOR;
  _ARRAY_ABS_Q := TRUE;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK ARRAY_AVG
  VAR_IN_OUT
    PT : ARRAY [1..100] OF REAL;
  END_VAR
  VAR_INPUT
    SIZE : UINT;
  END_VAR
  VAR_OUTPUT
    _ARRAY_AVG : REAL;
  END_VAR
  VAR
    i : INT;
    stop : INT;
  END_VAR

  stop :=LIMIT(1,UINT_TO_INT(size),1000);

  _array_avg := 0.0;
  FOR i := 1 TO stop DO
  	_array_avg := _array_avg + pt[i];
  END_FOR;
  _array_avg := _array_avg / INT_TO_REAL(stop);

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION EVEN : BOOL
  VAR_INPUT
    IN : DINT;
  END_VAR

  even := NOT BIT_OF_DWORD(DINT_TO_DWORD(in),0);
  (* from OSCAT library; www.oscat.de  *)
  (* BIT_OF_DWORD required *)
END_FUNCTION

FUNCTION_BLOCK ARRAY_TREND
  VAR_IN_OUT
    PT : ARRAY [1..100] OF REAL;
  END_VAR
  VAR_INPUT
    SIZE : UINT;
  END_VAR
  VAR_OUTPUT
    _ARRAY_TREND : REAL;
  END_VAR
  VAR
    i : INT;
    stop : INT;
    stop2 : INT;
    _d : INT;
    x : REAL;
  END_VAR

  x := 0.0;
  stop :=LIMIT(1,UINT_TO_INT(size),1000);
  stop2 := WORD_TO_INT(SHR(INT_TO_WORD(stop),1)); 
  IF even(INT_TO_DINT(stop)) THEN _d:=0; ELSE _d:=1;END_IF;

  FOR i := 1 TO stop2+_d DO
      x := x - pt[i];
  END_FOR; 
  FOR i := stop2+1 TO stop DO
      x := x + pt[i];
  END_FOR; 
  _array_trend := x / INT_TO_REAL(stop2+_d);

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK IS_SORTED
  VAR_IN_OUT
    PT : ARRAY [1..100] OF REAL;
  END_VAR
  VAR_INPUT
    SIZE : UINT;
  END_VAR
  VAR_OUTPUT
    _IS_SORTED : BOOL;
  END_VAR
  VAR
    i : INT;
    i2 : INT;
    stop : INT;
  END_VAR

  stop :=LIMIT(1,UINT_TO_INT(size),1000);
  stop := stop -1;
  FOR i := 1 TO stop DO
      i2 := i+1;
  	IF pt[i] > pt[i2] THEN
  		_IS_SORTED := FALSE;
  		RETURN;
  	END_IF;
  END_FOR;

  _IS_SORTED := TRUE;


  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK ARRAY_SPR
  VAR_IN_OUT
    PT : ARRAY [1..100] OF REAL;
  END_VAR
  VAR_INPUT
    SIZE : UINT;
  END_VAR
  VAR_OUTPUT
    _ARRAY_SPR : REAL;
  END_VAR
  VAR
    i : INT;
    stop : INT;
    arr_max : REAL;
    arr_min : REAL;
  END_VAR

  stop :=LIMIT(1,UINT_TO_INT(size),1000);

  arr_min := pt[1];
  arr_max := pt[1];
  FOR i := 2 TO stop DO
  	IF pt[i] > arr_max THEN arr_max := pt[i];
  	ELSIF pt[i] < arr_min THEN arr_min := pt[i];
  	END_IF;
  END_FOR;
  _array_spr := arr_max - arr_min;


  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK _ARRAY_ADD
  VAR_IN_OUT
    PT : ARRAY [1..100] OF REAL;
  END_VAR
  VAR_INPUT
    SIZE : UINT;
    X : REAL;
    _ARRAY_ADD_Q : BOOL;
  END_VAR
  VAR
    i : INT;
    stop : INT;
  END_VAR

  stop :=LIMIT(1,UINT_TO_INT(size),1000);
  FOR i := 1 TO stop DO
  	 pt[i] := pt[i] + X;
  END_FOR;
  _ARRAY_ADD_Q := TRUE;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK _ARRAY_SORT
  VAR_IN_OUT
    PT : ARRAY [1..100] OF REAL;
  END_VAR
  VAR_INPUT
    SIZE : UINT;
  END_VAR
  VAR_OUTPUT
    _ARRAY_SORT_Q : BOOL;
  END_VAR
  VAR
    stack_count : INT;
    stack : ARRAY [1..32] OF INT;
    links : INT;
    rechts : INT;
    pivot : REAL;
    i : INT;
    j : INT;
    ende_innen : BOOL;
    ende_aussen : BOOL;
    tmp : REAL;
    x : INT;
  END_VAR

  (* Startwerte zur Arraygröße *)
  links := 1;	(* Anfangselement des Arrays *)
  rechts := DWORD_TO_INT(SHR(UINT_TO_DWORD(size),2)); (* Endelement des Arrays *)
  stack_count := 1; (* Laufvariable Stack *)

  WHILE NOT ende_aussen DO (* äußere Schleife *)
  	IF links < rechts THEN
  		x := DWORD_TO_INT(SHR(UDINT_TO_DWORD(INT_TO_UDINT(rechts)+ INT_TO_UDINT(links)),1));
  		pivot := PT[x]; (* Wert des mittleren Elements als Pivot-Wert *)
  		i := links - 1;
  		j := rechts + 1;

  		(* innere Schleife, teile Feld *)
  		ende_innen := FALSE;
  		REPEAT

  			(* steigende Reihenfolge *)
  			REPEAT	i := i+1;	UNTIL (PT[i] >= pivot) OR NOT (i < rechts)	END_REPEAT;
  			REPEAT	j := j-1;	UNTIL (PT[j] <= pivot) OR NOT (j > links)	END_REPEAT;

  			(*sinkende Reihenfolge *)
  			(*REPEAT	i := i+1;	UNTIL (PT^[i] <= pivot) OR NOT (i < rechts)	END_REPEAT	*)
  			(*REPEAT	j := j-1;	UNTIL (PT^[j] >= pivot) OR NOT (j > links)	END_REPEAT	*)

  			IF i >= j THEN
  				ende_innen := TRUE;
  			ELSE
  			    tmp := PT[j];
  				PT[j] := PT[i];
  				PT[i] := tmp;
  			END_IF;

  		UNTIL ende_innen END_REPEAT;

  		(* Push stack *)
  		stack[stack_count] := rechts;		(* rechten Teil später sortieren *)
  		IF Stack_count < 32 THEN
  			stack_count := stack_count +1;
  		ELSE
  			ende_aussen := TRUE;
  			_ARRAY_SORT_Q := FALSE;					(* Fehler: Stack zu klein *)
  		END_IF;

  		(* linken Teil sortiern *)
  		rechts := MAX(links, i-1);

  	ELSE
  		IF stack_count = 1 THEN
  			ende_aussen := TRUE;
  		ELSE

  			links := rechts+1;

  			(* pop stack *)
  			stack_count := stack_count - 1;		(* jetzt rechten Teil sortierne *)
  			rechts:= stack[stack_count];
  		END_IF;

  	END_IF;

  END_WHILE;

  _ARRAY_SORT_Q := TRUE;				(* Sortierung beendet *)

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK _ARRAY_MEDIAN
  VAR_IN_OUT
    PT : ARRAY [1..100] OF REAL;
  END_VAR
  VAR_INPUT
    SIZE : UINT;
    _ARRAY_MEDIAN_Q : REAL;
  END_VAR
  VAR
    i : INT;
    i2 : INT;
    stop : INT;
    _ARRAY_SORT_MED : _ARRAY_SORT;
  END_VAR

  (* Array sortieren *)
  _array_sort_med.pt   := pt;
  _array_sort_med.size := size;
  _array_sort_med();
  pt := _array_sort_med.pt;

  stop :=LIMIT(1,UINT_TO_INT(size),1000);
  IF even(INT_TO_DINT(stop)) THEN
      i := WORD_TO_INT(SHR(INT_TO_WORD(stop),1));
      i2 := i+1;
  	_array_median_Q := (pt[i] + pt[i2]) * 0.5;
  ELSE
      i := WORD_TO_INT(SHR(INT_TO_WORD(stop),1))+1;
  	_array_median_Q := pt[i];
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK _ARRAY_MUL
  VAR_IN_OUT
    PT : ARRAY [1..100] OF REAL;
  END_VAR
  VAR_INPUT
    SIZE : UINT;
    X : REAL;
  END_VAR
  VAR_OUTPUT
    _ARRAY_MUL_Q : BOOL;
  END_VAR
  VAR
    i : INT;
    stop : INT;
  END_VAR

  stop :=LIMIT(1,UINT_TO_INT(size),1000);
  FOR i := 1 TO stop DO
  	 pt[i] := pt[i] * X;
  END_FOR;
  _ARRAY_MUL_Q := TRUE;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK ARRAY_VAR
  VAR_IN_OUT
    PT : ARRAY [1..100] OF REAL;
  END_VAR
  VAR_INPUT
    SIZE : UINT;
  END_VAR
  VAR_OUTPUT
    _ARRAY_VAR : REAL;
  END_VAR
  VAR
    i : INT;
    stop : INT;
    avg : REAL;
  END_VAR

  (* at first we calualte the arithmetic average of the array *)

  stop :=LIMIT(1,UINT_TO_INT(size),1000);
  avg := pt[1];
  FOR i := 2 TO stop DO
  	avg := avg + pt[i];
  END_FOR;
  avg := avg / INT_TO_REAL(stop);

  (* in a second run we calculate the variance of the array *)

  _array_var := EXPT(pt[1] - avg, 2.0);
  FOR i := 2 TO stop DO
  	_array_var := _array_var + EXPT(pt[i] - avg, 2.0);
  END_FOR;
  _array_var := _array_var / INT_TO_REAL(stop-1);



  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK ARRAY_SDV
  VAR_IN_OUT
    PT : ARRAY [1..100] OF REAL;
  END_VAR
  VAR_INPUT
    SIZE : UINT;
  END_VAR
  VAR_OUTPUT
    _ARRAY_SDV : REAL;
  END_VAR
  VAR
    FB_array_var : ARRAY_VAR;
  END_VAR

  (* at first we calualte the arithmetic average of the array *)

  (* standard deviation is simply the square root of the variance *)

  FB_array_var.pt   := pt;
  FB_array_var.size := size;
  FB_array_var();
  pt := FB_array_var.pt;

  _array_sdv := SQRT(FB_array_var._array_var);




  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK ARRAY_MAX
  VAR_IN_OUT
    PT : ARRAY [1..100] OF REAL;
  END_VAR
  VAR_INPUT
    SIZE : UINT;
  END_VAR
  VAR_OUTPUT
    _ARRAY_MAX : REAL;
  END_VAR
  VAR
    i : INT;
    stop : INT;
  END_VAR

  stop :=LIMIT(1,UINT_TO_INT(size),1000);

  FOR i := 1 TO stop DO
  	IF pt[i] > _array_max THEN _array_max := pt[i]; END_IF;
  END_FOR;


  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK _ARRAY_INIT
  VAR_IN_OUT
    PT : ARRAY [1..100] OF REAL;
  END_VAR
  VAR_INPUT
    SIZE : UINT;
    INIT : REAL;
  END_VAR
  VAR_OUTPUT
    _ARRAY_INIT_Q : BOOL;
  END_VAR
  VAR
    i : INT;
    stop : INT;
  END_VAR

  stop :=LIMIT(1,UINT_TO_INT(size),1000);

  FOR i := 1 TO stop DO
  	pt[i] := init;
  END_FOR;
  _array_init_Q := TRUE;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK ARRAY_SUM
  VAR_IN_OUT
    PT : ARRAY [1..100] OF REAL;
  END_VAR
  VAR_INPUT
    SIZE : UINT;
  END_VAR
  VAR_OUTPUT
    _ARRAY_SUM : REAL;
  END_VAR
  VAR
    i : INT;
    stop : INT;
  END_VAR

  stop :=LIMIT(1,UINT_TO_INT(size),1000);

  _array_sum := pt[1];
  FOR i := 2 TO stop DO
  	_array_sum := _array_sum + pt[i];
  END_FOR;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK ARRAY_MIN
  VAR_IN_OUT
    PT : ARRAY [1..100] OF REAL;
  END_VAR
  VAR_INPUT
    SIZE : UINT;
  END_VAR
  VAR_OUTPUT
    _ARRAY_MIN : REAL;
  END_VAR
  VAR
    i : INT;
    stop : INT;
  END_VAR

  stop :=LIMIT(1,UINT_TO_INT(size),1000);

  _array_min := pt[1];
  FOR i := 2 TO stop DO
  	IF pt[i] < _array_min THEN _array_min := pt[i]; END_IF;
  END_FOR;


  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION SQRTN : REAL
  VAR_INPUT
    X : REAL;
    N : INT;
  END_VAR

  IF N > 0 THEN
  	SQRTN := EXP(LN(x) / INT_TO_REAL(n));
  ELSE
  	SQRTN := 0.0;
  END_IF;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION_BLOCK ARRAY_GAV
  VAR_IN_OUT
    PT : ARRAY [1..100] OF REAL;
  END_VAR
  VAR_INPUT
    SIZE : UINT;
  END_VAR
  VAR_OUTPUT
    _ARRAY_GAV : REAL;
  END_VAR
  VAR
    i : INT;
    stop : INT;
  END_VAR

  stop :=LIMIT(1,UINT_TO_INT(size),1000);
  _ARRAY_GAV := 1.0;
  FOR i := 1 TO stop DO
  	IF pt[i] > 0.0 THEN
  		_ARRAY_GAV := _ARRAY_GAV * pt[i];
  	ELSE
  		_ARRAY_GAV := 0.0;
  		RETURN;
  	END_IF;
  END_FOR;
  _ARRAY_GAV := SQRTN(_ARRAY_GAV,stop);


  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK ARRAY_HAV
  VAR_IN_OUT
    PT : ARRAY [1..100] OF REAL;
  END_VAR
  VAR_INPUT
    SIZE : UINT;
  END_VAR
  VAR_OUTPUT
    _ARRAY_HAV : REAL;
  END_VAR
  VAR
    i : INT;
    stop : INT;
  END_VAR

  stop :=LIMIT(1,UINT_TO_INT(size),1000);
  _ARRAY_HAV := 0.0;
  FOR i := 1 TO stop DO
  	IF pt[i] <> 0.0 THEN
  		_ARRAY_HAV := _ARRAY_HAV + 1.0/pt[i];
  	ELSE
  		_ARRAY_HAV := 0.0;
  		RETURN;
  	END_IF;
  END_FOR;
  _ARRAY_HAV := INT_TO_REAL(stop) / _ARRAY_HAV;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
