TYPE
  FRACTION : STRUCT
    Numerator : INT;
    Denominator : INT;
  END_STRUCT;
END_TYPE

FUNCTION MUL_ADD : REAL
  VAR_INPUT
    X : REAL;
    K : REAL;
    O : REAL;
  END_VAR

  MUL_ADD := X * K + O;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION SGN : INT
  VAR_INPUT
    x : REAL;
  END_VAR

  IF X > 0.0 THEN
  	sgn := 1;
  ELSIF X < 0.0 THEN
  	sgn := -1;
  ELSE
  	sgn := 0;
  END_IF;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION ERF : REAL
  VAR_INPUT
    x : REAL;
  END_VAR
  VAR
    x2 : REAL;
    ax2 : REAL;
  END_VAR

  x2 := X*X;
  ax2 := 0.147 * x2 + 1.0;
  ERF := SQRT(1.0 - EXP(-X2 * ((0.27323954473516 + aX2)/(ax2)))) * INT_TO_REAL(SGN(x));
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION GAUSSCD : REAL
  VAR_INPUT
    X : REAL;
    U : REAL;
    SI : REAL;
  END_VAR

  GAUSSCD := (ERF((X - U) / (SI * 1.414213562)) + 1.0) * 0.5;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION GOLD : REAL
  VAR
    X : REAL;
  END_VAR

  GOLD := (X + SQRT(X*X + 4.0)) * 0.5;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION SINC : REAL
  VAR_INPUT
    X : REAL;
  END_VAR

  IF X = 0.0 THEN
  	SINC := 1.0;
  ELSE
  	SINC := SIN(x) / x;
  END_IF;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION MAX3 : REAL
  VAR_INPUT
    IN1 : REAL;
    IN2 : REAL;
    IN3 : REAL;
  END_VAR

  MAX3 := MAX(MAX(IN1,IN2),IN3);
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION ATANH : REAL
  VAR_INPUT
    x : REAL;
  END_VAR

  ATANH := LN((1.0 + x)/(1.0 - x)) * 0.5;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION NEGX : REAL
  VAR_INPUT
    x : REAL;
  END_VAR

  NEGX := -X;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION CEIL : INT
  VAR_INPUT
    x : REAL;
  END_VAR

  CEIL := REAL_TO_INT(x);
  IF INT_TO_REAL(CEIL) < X THEN
          CEIL := CEIL + 1;
  END_IF;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

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

FUNCTION SINH : REAL
  VAR
    X : REAL;
  END_VAR

  IF ABS(x) < 2.0E-3 THEN
  	SINH := X;
  ELSE
  	SINH := (EXP(x) - EXP(-x)) * 0.5;
  END_IF;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION CAUCHY : REAL
  VAR_INPUT
    X : REAL;
    T_Cauchy : REAL;
    U : REAL;
  END_VAR
  VAR
    tmp : REAL;
  END_VAR

  tmp := x - T_Cauchy;
  CAUCHY := 0.318309886183791 * U / (U*U + tmp*tmp);

  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION CAUCHYCD : REAL
  VAR_INPUT
    X : REAL;
    T_Cauchy : REAL;
    U : REAL;
  END_VAR

  CAUCHYCD := 0.5 + 0.318309886183791 * ATAN((X - T_Cauchy) / U);

  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION BIT_OF_DWORD : BOOL
  VAR_INPUT
    IN : DWORD;
    N : INT;
  END_VAR

  BIT_OF_DWORD := (SHR(in,N) AND 16#00000001) > 0;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

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

FUNCTION GAMMA : REAL
  VAR_INPUT
    x : REAL;
  END_VAR

  IF x > 0.0 THEN
  	GAMMA := SQRT(6.28318530717958647692528676655900576 / X) * EXPT(0.367879441171442 * (x + 1.0 / (12.0 * x - 0.1 / X)), X);
  END_IF;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

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

FUNCTION EXP10 : REAL
  VAR_INPUT
    x : REAL;
  END_VAR

  exp10 := EXP(X * 2.30258509299405);
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION CMP : BOOL
  VAR_INPUT
    x : REAL;
    y : REAL;
    n : INT;
  END_VAR
  VAR
    tmp : REAL;
  END_VAR

  tmp := ABS(x);
  IF tmp > 0.0 THEN
  	tmp := EXP10(INT_TO_REAL(FLOOR(LOG(tmp))-N+1));
  ELSE
  	tmp := EXP10(tmp);
  END_IF;
  CMP := ABS(X - Y) < tmp;
  (* from OSCAT library; www.oscat.de  *)
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

PROGRAM program0
  VAR
    LocalVar0 : REAL;
    LocalVar2 : FRACTION;
    LocalVar1 : INT;
    CEIL5_OUT : INT;
  END_VAR

  CEIL5_OUT := CEIL(LocalVar0);
  LocalVar1 := CEIL5_OUT;
END_PROGRAM

FUNCTION SIGN_I : BOOL
  VAR_INPUT
    IN : DINT;
  END_VAR

  sign_I := BIT_OF_DWORD(DINT_TO_DWORD(in),31);
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION ACOTH : REAL
  VAR_INPUT
    x : REAL;
  END_VAR

  ACOTH := LN((x+1.0)/(x-1.0))*0.5;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION SIGMOID : REAL
  VAR_INPUT
    X : REAL;
  END_VAR

  IF X > 20.0 THEN
  	SIGMOID := 1.0;
  ELSIF x < -85.0 THEN
  	SIGMOID := 0.0;
  ELSE
  	SIGMOID := 1.0 / (1.0 + EXP(-X));
  END_IF;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION LAMBERT_W : REAL
  VAR_INPUT
    X : REAL;
  END_VAR
  VAR
    w : REAL;
    i : INT;
    we : REAL;
    w1e : REAL;
    ewx : REAL;
    last : DWORD;
  END_VAR

  IF x < -0.367879441171442 THEN
  	LAMBERT_W := -1000.0;
  	RETURN;
  (* return 0 if x = 0 *)
  ELSIF x = 0.0 THEN
  	RETURN;
  (* first an estimate is calculated *)
  ELSIF x <= 500.0 THEN
  	w := LN(x + 1.0);
  	w := 0.665 * (1.0 + 0.0195 * w) * w + 0.04;
  ELSE
  	w := LN(x - 4.0) - (1.0 - 1.0/LN(x)) * LN(LN(x));
  END_IF;
  (* use estimate to calculate exact result *)
  FOR i := 0 TO 5 DO
  	ewx := EXP(w);
  	we := w * ewx - x;
  	w1e := (w+1.0) * ewx;
  	last := REAL_TO_DWORD(w) AND DWORD#16#FFFF_FFFC;
  	w := w - (we / (w1e - (w+2.0) * we / (2.0 * w + 2.0)));
  	IF (REAL_TO_DWORD(w) AND DWORD#16#FFFF_FFFC) = last THEN EXIT; END_IF;
  END_FOR;
  LAMBERT_W := w;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION COTH : REAL
  VAR_INPUT
    x : REAL;
  END_VAR

  IF X > 20.0 THEN
  	COTH :=1.0;
  ELSIF X < -20.0 THEN
  	COTH := -1.0;
  ELSE
  	COTH := 1.0 + 2.0 / (EXP(X * 2.0) - 1.0);
  END_IF;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION LANGEVIN : REAL
  VAR_INPUT
    X : REAL;
  END_VAR

  IF X = 0.0 THEN
  	LANGEVIN := 0.0;
  ELSE
  	LANGEVIN := COTH(X) - 1.0 / X;
  END_IF;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION WINDOW : BOOL
  VAR_INPUT
    LOW : REAL;
    IN : REAL;
    HIGH : REAL;
  END_VAR

  window := (in < high) AND (in > low);
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION SIGN_R : BOOL
  VAR_INPUT
    IN : REAL;
  END_VAR

  SIGN_R := in < 0.0;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION ROUND : REAL
  VAR_INPUT
    IN : REAL;
    N : INT;
  END_VAR
  VAR
    X : REAL;
  END_VAR

  IF N < 4 THEN
  	IF N < 2 THEN
  		IF N = 0 THEN X := 1.0; ELSE X := 10.0; END_IF;
  	ELSE
  		IF N = 2 THEN X := 100.0; ELSE X := 1000.0; END_IF;
  	END_IF;
  ELSE
  	IF N < 6 THEN
  		IF N = 4 THEN X := 10000.0; ELSE X := 100000.0; END_IF;
  	ELSE
  		IF N = 6 THEN X := 1000000.0; ELSE X := 10000000.0; END_IF;
  	END_IF;
  END_IF;

  ROUND := DINT_TO_REAL(REAL_TO_DINT(in * X)) / X;

  (* from OSCAT library; www.oscat.de  *)
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

FUNCTION ERFC : REAL
  VAR_INPUT
    x : REAL;
  END_VAR

  ERFC := 1.0 - ERF(X);
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION RAD : REAL
  VAR_INPUT
    _DEG : REAL;
  END_VAR

  RAD := modR(0.0174532925199433 * _deg , 6.283185307179586476);
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION DEG : REAL
  VAR_INPUT
    RAD_IN : REAL;
  END_VAR

  DEG := MODR(57.29577951308232 * RAD_IN, 360.0);
  (* from OSCAT library; www.oscat.de  *)
  (* MODR and FLOOR2 required *)
END_FUNCTION

FUNCTION EXPN : REAL
  VAR_INPUT
    X : REAL;
    N : INT;
  END_VAR
  VAR
    N_Word : WORD;
    X_Tmp : REAL;
    sign : BOOL;
  END_VAR

  N_word := INT_TO_WORD(N);
  X_tmp := X;
  sign := BIT_OF_DWORD(WORD_TO_DWORD(N_word),15);
  N_word := INT_TO_WORD(ABS(N));
  IF BIT_OF_DWORD(WORD_TO_DWORD(N_word),0) THEN expn := X_tmp; ELSE expn := 1.0; END_IF;    (* N_word.N *)
  N_word := SHR(N_word,1);
  WHILE N_word > WORD#0 DO
  	X_tmp := X_tmp * X_tmp;
  	IF BIT_OF_DWORD(WORD_TO_DWORD(N_word),0) THEN expn := expn * X_tmp; END_IF;       (* N_word.N *)
  	N_word := SHR(N_word,1);
  END_WHILE;
  IF sign THEN EXPN := 1.0 / EXPN; END_IF;
  (* from OSCAT library; www.oscat.de  *)
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

FUNCTION GCD : INT
  VAR_INPUT
    A : DINT;
    B : DINT;
  END_VAR
  VAR
    _t : DINT;
    _a : DINT;
    _b : DINT;
  END_VAR

  _A := A;
  _B := B;

  IF _A = DINT#0 THEN
  	GCD := DINT_TO_INT(ABS(_B));
  ELSIF _B = DINT#0 THEN
  	GCD := DINT_TO_INT(ABS(_A));
  ELSE
  	_A := ABS(_A);
  	_B := ABS(_B);
  	GCD := 1;

  	WHILE NOT((DINT_TO_DWORD(_A) AND DWORD#1) > DWORD#0 OR (DINT_TO_DWORD(_B) AND DWORD#1) > DWORD#0) DO
  		_A := DWORD_TO_DINT(SHR(DINT_TO_DWORD(_A),1));
  		_B := DWORD_TO_DINT(SHR(DINT_TO_DWORD(_B),1));
  		GCD := DWORD_TO_INT(SHR(INT_TO_DWORD(GCD),1));
  	END_WHILE;
  	WHILE _A > DINT#0 DO
  		IF NOT((DINT_TO_DWORD(_A) AND DWORD#1) > DWORD#0) THEN
  			_A := DWORD_TO_DINT(SHR(DINT_TO_DWORD(_A),1));
  		ELSIF NOT((DINT_TO_DWORD(_B) AND DWORD#1) > DWORD#0) THEN
  			_B := DWORD_TO_DINT(SHR(DINT_TO_DWORD(_B),1));
  		ELSE
  			_t := DWORD_TO_DINT(SHR(DINT_TO_DWORD(ABS(_A-_B)),1));
  			IF _A < _B THEN
  				_B := _t;
  			ELSE
  				_A := _t;
  			END_IF;
  		END_IF;
  	END_WHILE;
  	GCD := GCD * DINT_TO_INT(_B);
  END_IF;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION DIFFER : BOOL
  VAR_INPUT
    IN1 : REAL;
    IN2 : REAL;
    x : REAL;
  END_VAR

  DIFFER := ABS(in1 - in2) > X;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION_BLOCK REAL_TO_FRAC
  VAR_INPUT
    x : REAL;
    n : INT;
  END_VAR
  VAR_OUTPUT
    _REAL_TO_FRAC : FRACTION;
  END_VAR
  VAR
    temp : DINT;
    sign : BOOL;
    X_gerundet : DINT;
    X_ohne_Nachkomma : REAL;
    Numerator : DINT := 1;
    Denominator : DINT := 0;
    Numerator_old : DINT := 0;
    Denominator_old : DINT := 1;
  END_VAR

  IF X < 0.0 THEN
  	sign := TRUE;								(* Vorzeichen merken *)
  	X := ABS(X);								(* Absolutwert berechnen *)
  END_IF;

  REPEAT
  	X_gerundet := REAL_TO_DINT(X);

  	(* Zaehler berechnen *)
  	temp := numerator * X_gerundet + numerator_old;		(* Zaehler um Vorkammawert erweitern *)
  	numerator_old := numerator;							(* Zaehler der letzten Berechnung speichern *)
  	numerator := temp;									(* Zaehler dieser Berechnung speichern *)

  	(* Nenner berechnen *)
  	temp := denominator * X_gerundet + denominator_old;	(* Nenner um Vorkammawert erweitern *)
  	denominator_old := denominator;						(* Nenner der letzten Berechnung speichern *)
  	denominator := temp;								(* Nenner dieser Berechnung speichern *)

  	(* Restwert berechnen *)
  	X_ohne_Nachkomma := DINT_TO_REAL(X_gerundet);
  	IF X = X_ohne_Nachkomma THEN						(* Bruch geht ohne Rest auf *)
  		IF ABS(denominator) <= INT_TO_DINT(N) THEN		(* kein Rundungsfehler *)
  			numerator_old := numerator;					(* Numerator_old wird von Funktion zurückgegeben *)
  			denominator_old := denominator;				(* Denominator_old wird von Funktion zurückgegeben *)
  		END_IF;
  		EXIT;											(* keine weitere Berechnung notwendig *)
  	ELSE
  		X := 1.0 / (X - X_ohne_Nachkomma);				(* Kehrwert vom Rest -> Neuer Bruch *)
  	END_IF;

  UNTIL
  	( ABS(Denominator) > INT_TO_DINT(N))
  END_REPEAT;

  IF sign THEN
  	_REAL_TO_FRAC.NUMERATOR := -1 * ABS(DINT_TO_INT(numerator_old));
  ELSE
  	_REAL_TO_FRAC.NUMERATOR :=  ABS(DINT_TO_INT(numerator_old));
  END_IF;

  _REAL_TO_FRAC.DENOMINATOR := ABS(DINT_TO_INT(denominator_old));

  (* from OSCAT library; www.oscat.de  *)
  (* user defined data type "FRACTION" required *)
END_FUNCTION_BLOCK

FUNCTION FIB : DINT
  VAR_INPUT
    X : INT;
  END_VAR
  VAR
    t1 : DINT;
    t2 : DINT;
    x_tmp : INT;
  END_VAR

  t1 := DINT#0;
  t2 := DINT#0;
  X_tmp := X;
  IF X_tmp < 0 OR X_tmp > 46 THEN
  	FIB := DINT#-1;
  ELSIF X_tmp < 2 THEN
  	FIB := INT_TO_DINT(X_tmp);
  	RETURN;
  ELSE
  	(* the fibonacci number is the sum of the two suceeding fibonaci numbers *)
  	(* we store the numbers alternatively in t1 and t2 depending on pt *)
  	t2 := DINT#1;
  	WHILE X_tmp > 3 DO
  		X_tmp := X_tmp - 2;
  		t1 := t1 + t2;
  		t2 := t1 + t2;
  	END_WHILE;
  	IF X_tmp > 2 THEN t1 := t1 + t2; END_IF;
  	fib := t1 + t2;
  END_IF;

  (* alternative code for very big numbers

  IF X < 31 THEN
  	fib := 0.4472136 * (expn(1.618034,X) - expn(-0.618034,X));
  ELSE
  	fib := 0.4472133 * expn(1.618034,X);
  END_IF;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION BETA : REAL
  VAR_INPUT
    x : REAL;
    y : REAL;
  END_VAR

  BETA := GAMMA(X)*GAMMA(Y) / GAMMA(x+y);
  (* FC Gamma required *)
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION CEIL2 : DINT
  VAR_INPUT
    x : REAL;
  END_VAR

  CEIL2 := REAL_TO_DINT(x);
  IF DINT_TO_REAL(CEIL2) < X THEN
          CEIL2 := CEIL2 + DINT#1;
  END_IF;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION AGDF : REAL
  VAR_INPUT
    X : REAL;
  END_VAR

  AGDF := LN((1.0 + SIN(X)) / COS(X));

  (* comment
  the current implementation gives sufficient accuracy only up to X = 1.57 or an output > 10.
  is X closer to PI/2 then the function is more and more unreliable
  *)
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION COSH : REAL
  VAR_INPUT
    x : REAL;
  END_VAR
  VAR
    t_c : REAL;
  END_VAR

  t_c := EXP(X);
  COSH := (1.0 / t_c + t_c) * 0.5;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION_BLOCK RDMDW
  VAR_INPUT
    LAST : DWORD;
  END_VAR
  VAR_OUTPUT
    _RDMDW : DWORD;
  END_VAR
  VAR
    RX : REAL;
    M : REAL;
    _rdm : RDM;
  END_VAR

  M := INT_TO_REAL(BIT_COUNT(last)); 
  _rdm(last:=FRACT(M*3.14159265358979323846264338327950288));
  RX:=_rdm._RDM;
  _RDMDW := SHL(REAL_TO_DWORD(rx*65535.0),16); 

  _rdm(last:=FRACT(M*2.71828182845904523536028747135266249));
  RX:=_rdm._RDM;
  _RDMDW := _RDMDW OR (REAL_TO_DWORD(rx*65535.0) AND DWORD#16#0000FFFF); 

  (* From OSCAT Library, www.oscat.de *)
  (* RDM required *)
END_FUNCTION_BLOCK

FUNCTION EVEN : BOOL
  VAR_INPUT
    IN : DINT;
  END_VAR

  even := NOT BIT_OF_DWORD(DINT_TO_DWORD(in),0);
  (* from OSCAT library; www.oscat.de  *)
  (* BIT_OF_DWORD required *)
END_FUNCTION

FUNCTION ASINH : REAL
  VAR_INPUT
    X : REAL;
  END_VAR

  ASINH := LN(SQRT(X * X + 1.0)+X);
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION MIN3 : REAL
  VAR_INPUT
    IN1 : REAL;
    IN2 : REAL;
    IN3 : REAL;
  END_VAR

  MIN3 := MIN(MIN(IN1,IN2),IN3);
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION TANC : REAL
  VAR_INPUT
    X : REAL;
  END_VAR

  IF X = 0.0 THEN
  	TANC := 1.0;
  ELSE
  	TANC := TAN(x) / x;
  END_IF;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION WINDOW2 : BOOL
  VAR_INPUT
    LOW : REAL;
    IN : REAL;
    HIGH : REAL;
  END_VAR

  window2 := (in <= high) AND (in >= low);
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION INV : REAL
  VAR_INPUT
    X : REAL;
  END_VAR

  IF X <> 0.0 THEN INV := 1.0 / X; END_IF;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION TANH : REAL
  VAR_INPUT
    X : REAL;
  END_VAR

  IF X > 20.0 THEN
  	TANH := 1.0;
  ELSIF X < -20.0 THEN
  	TANH := -1.0;
  ELSE
  	TANH := 1.0 - 2.0 / (EXP(2.0 * x) + 1.0);
  END_IF;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION GAUSS : REAL
  VAR_INPUT
    X : REAL;
    U : REAL;
    SI : REAL;
  END_VAR
  VAR
    temp : REAL;
    si_inv : REAL;
  END_VAR

  temp := X - U;
  si_inv := 1.0  / si;
  GAUSS := EXP(Temp * Temp * si_inv * SI_inv * - 0.5) * 0.39894228 * si_inv;
  (* BIT_OF_DWORD required *)
END_FUNCTION

FUNCTION RND : REAL
  VAR_INPUT
    X : REAL;
    N : INT;
  END_VAR
  VAR
    M : REAL;
  END_VAR

  IF X = 0.0 THEN
  	RND := 0.0;
  ELSE
  	M := EXPN(10.0,N - CEIL(LOG(ABS(X))));
  	RND := DINT_TO_REAL(REAL_TO_DINT(X * M)) / M ;
  END_IF;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION ATAN2 : REAL
  VAR_INPUT
    X : REAL;
    Y : REAL;
  END_VAR

  IF X > 0.0 THEN
  	ATAN2 := ATAN(Y/X);
  ELSIF X < 0.0 THEN
  	IF Y >= 0.0 THEN
  		ATAN2 := ATAN(Y/X) + 3.14159265358979323846264338327950288;
  	ELSE
  		ATAN2 := ATAN(Y/X) - 3.14159265358979323846264338327950288;
  	END_IF;
  ELSIF Y > 0.0 THEN
  	ATAN2 := 1.5707963267948965580;
  ELSIF Y < 0.0 THEN
  	ATAN2 := -1.5707963267948965580;
  ELSE
  	ATAN2 := 0.0;
  END_IF;


  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION HYPOT : REAL
  VAR_INPUT
    X : REAL;
    Y : REAL;
  END_VAR

  HYPOT := SQRT(x*x + y*y);
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION SQRTN : REAL
  VAR
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

FUNCTION GDF : REAL
  VAR_INPUT
    x : REAL;
  END_VAR

  IF X = 0.0 THEN
  	GDF := 0.0;
  ELSIF X > 15.0 THEN
  	GDF := 1.5707963267949;
  ELSIF X < -15.0 THEN
  	GDF := -1.5707963267949;
  ELSE
  	GDF := ATAN(EXP(X)) * 2.0 - 1.5707963267949;
  END_IF;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION ACOSH : REAL
  VAR_INPUT
    X : REAL;
  END_VAR

  ACOSH := LN(SQRT(X * X - 1.0) + X);
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION BINOM : INT
  VAR_INPUT
    N : INT;
    K : INT;
    i : INT;
  END_VAR

  IF 2 * K > n THEN
  	k := n - k;
  END_IF;
  IF k > n THEN
  	RETURN;
  ELSIF k = 0 OR k = n THEN
  	BINOM := 1;
  ELSIF k = 1 THEN
  	BINOM := n;
  ELSE
  	BINOM := n;
  	n := n + 1;
  	FOR i := 2 TO k DO
  		BINOM := BINOM * (n - i) / i;
  	END_FOR;
  END_IF;

  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

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

FUNCTION FACT : DINT
  VAR_INPUT
    x : INT;
  END_VAR

  CASE X OF
  00: FACT := DINT#1;
  01: FACT := DINT#1;
  02: FACT := DINT#2;
  03: FACT := DINT#6;
  04: FACT := DINT#24;
  05: FACT := DINT#120;
  06: FACT := DINT#720;
  07: FACT := DINT#5040;
  08: FACT := DINT#40320;
  09: FACT := DINT#362880;
  10: FACT := DINT#3628800;
  11: FACT := DINT#39916800;
  12: FACT := DINT#479001600;
  ELSE
      FACT := DINT#-1;
  END_CASE;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION INC : INT
  VAR_INPUT
    X : INT;
    _D : INT;
    M : INT;
  END_VAR

  inc := (X + _D + M + 1) MOD (M + 1);
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
