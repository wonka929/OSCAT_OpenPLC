TYPE
  OSCAT_COMPLEX : STRUCT
    re : REAL;
    im : REAL;
  END_STRUCT;
END_TYPE

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

FUNCTION_BLOCK CLOG
  VAR_INPUT
    X : OSCAT_COMPLEX;
  END_VAR
  VAR_OUTPUT
    _CLOG : OSCAT_COMPLEX;
  END_VAR

  _CLOG.re := LN(HYPOT(X.re, X.im));
  _CLOG.im := ATAN2(X.im, X.re);

  (*From OSCAT Library, www.oscat.de *)
  (* datatype OSCAT_COMPLEX, ATAN2 required *)
END_FUNCTION_BLOCK

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

FUNCTION_BLOCK CADD
  VAR_INPUT
    X : OSCAT_COMPLEX;
    Y : OSCAT_COMPLEX;
  END_VAR
  VAR_OUTPUT
    _CADD : OSCAT_COMPLEX;
  END_VAR

  _CADD.re := x.re + y.re;
  _CADD.im := x.im + y.im;

  (*From OSCAT Library, www.oscat.de *)
  (* datatype OSCAT_COMPLEX required *)
END_FUNCTION_BLOCK

FUNCTION SINH : REAL
  VAR_INPUT
    X : REAL;
  END_VAR

  IF ABS(x) < 2.0E-3 THEN
  	SINH := X;
  ELSE
  	SINH := (EXP(x) - EXP(-x)) * 0.5;
  END_IF;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION_BLOCK CSUB
  VAR_INPUT
    X : OSCAT_COMPLEX;
    Y : OSCAT_COMPLEX;
  END_VAR
  VAR_OUTPUT
    _CSUB : OSCAT_COMPLEX;
  END_VAR

  _CSUB.re := X.re - Y.re;
  _CSUB.im := X.im - Y.im;

  (*From OSCAT Library, www.oscat.de *)
  (* datatype OSCAT_COMPLEX required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CDIV
  VAR_INPUT
    X : OSCAT_COMPLEX;
    Y : OSCAT_COMPLEX;
  END_VAR
  VAR_OUTPUT
    _CDIV : OSCAT_COMPLEX;
  END_VAR
  VAR
    temp : REAL;
  END_VAR

  temp := Y.re * Y.re + Y.im * Y.im;
  IF temp = 0.0 THEN _CDIV.re := 0.0;_CDIV.im := 0.0;RETURN;END_IF;
  _CDIV.re := (X.re * Y.re + X.im * Y.im) / temp;
  _CDIV.im := (X.im * Y.re - X.re * Y.im) / temp;

  (*From OSCAT Library, www.oscat.de *)
  (* datatype OSCAT_COMPLEX required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CABS
  VAR_INPUT
    X : OSCAT_COMPLEX;
  END_VAR
  VAR_OUTPUT
    _CABS : REAL;
  END_VAR

  _CABS := HYPOT(x.re, x.im);

  (*From OSCAT Library, www.oscat.de *)
  (* datatype OSCAT_COMPLEX, HYPOT required *)
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

FUNCTION_BLOCK CCOSH
  VAR_INPUT
    X : OSCAT_COMPLEX;
  END_VAR
  VAR_OUTPUT
    _CCOSH : OSCAT_COMPLEX;
  END_VAR

  _CCOSH.re := cosH(x.re) * COS(x.im);
  _CCOSH.im := sinH(x.re) * SIN(x.im);

  (*From OSCAT Library, www.oscat.de *)
  (* datatype OSCAT_COMPLEX, COSH, SINH required *)
END_FUNCTION_BLOCK

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

FUNCTION_BLOCK CSQRT
  VAR_INPUT
    X : OSCAT_COMPLEX;
  END_VAR
  VAR_OUTPUT
    _CSQRT : OSCAT_COMPLEX;
  END_VAR
  VAR
    temp : REAL;
  END_VAR

  temp := HYPOT(x.re, x.im);
  _CSQRT.re :=  SQRT(0.5 * (temp + x.re));
  _CSQRT.im :=  INT_TO_REAL(sgn(x.im)) * SQRT(0.5 * (temp - x.re));

  (*From OSCAT Library, www.oscat.de *)
  (* datatype OSCAT_COMPLEX, SGN required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CASINH
  VAR_INPUT
    X : OSCAT_COMPLEX;
  END_VAR
  VAR_OUTPUT
    _CASINH : OSCAT_COMPLEX;
  END_VAR
  VAR
    Y : OSCAT_COMPLEX;
    _CLOG : CLOG;
    _CSQRT : CSQRT;
  END_VAR

  y.re := (X.re - X.im)*(X.re + X.im) + 1.0;
  y.im := 2.0 * X.re * X.im;
  _CSQRT(X:=y);
  y    := _CSQRT._CSQRT;
  y.re := y.re + x.re;
  y.im := y.im + x.im;
  _CLOG(X:=y);
  _CASINH  := _CLOG._CLOG;

  (*From OSCAT Library, www.oscat.de *)
  (* datatype OSCAT_COMPLEX, CLOG, CSQRT required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CASIN
  VAR_INPUT
    X : OSCAT_COMPLEX;
  END_VAR
  VAR_OUTPUT
    _CASIN : OSCAT_COMPLEX;
  END_VAR
  VAR
    Y : OSCAT_COMPLEX;
    _CASINH : CASINH;
  END_VAR

  y.re := -x.im;
  y.im := x.re;
  _CASINH(X:=y);
  y := _CASINH._CASINH;
  _CASIN.re := y.im;
  _CASIN.im := -y.re;

  (*From OSCAT Library, www.oscat.de *)
  (* datatype OSCAT_COMPLEX, CASINH required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CCON
  VAR_INPUT
    X : OSCAT_COMPLEX;
  END_VAR
  VAR_OUTPUT
    _CCON : OSCAT_COMPLEX;
  END_VAR

  _CCON.re := x.re;
  _CCON.im := -x.im;

  (*From OSCAT Library, www.oscat.de *)
  (* datatype OSCAT_COMPLEX required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CMUL
  VAR_INPUT
    X : OSCAT_COMPLEX;
    Y : OSCAT_COMPLEX;
  END_VAR
  VAR_OUTPUT
    _CMUL : OSCAT_COMPLEX;
  END_VAR

  _CMUL.re := X.re * Y.re - X.im * Y.im;
  _CMUL.im := X.re * Y.im + X.im * Y.re;

  (*From OSCAT Library, www.oscat.de *)
  (* datatype OSCAT_COMPLEX required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CPOL
  VAR_INPUT
    L : REAL;
    A : REAL;
  END_VAR
  VAR_OUTPUT
    _CPOL : OSCAT_COMPLEX;
  END_VAR

  _CPOL.re := L * COS(A);
  _CPOL.im := L * SIN(A);

  (*From OSCAT Library, www.oscat.de *)
  (* datatype OSCAT_COMPLEX required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CACOSH
  VAR_INPUT
    X : OSCAT_COMPLEX;
  END_VAR
  VAR_OUTPUT
    _CACOSH : OSCAT_COMPLEX;
  END_VAR
  VAR
    Y : OSCAT_COMPLEX;
    _CLOG : CLOG;
    _CSQRT : CSQRT;
  END_VAR

  y.re := (X.re - X.im)*(X.re + X.im) - 1.0;
  y.im := 2.0 * X.re * X.im;
  _CSQRT(X:=y);
  y    := _CSQRT._CSQRT;
  y.re := y.re + x.re;
  y.im := y.im + x.im;
  _CLOG(X:=y);
  _CACOSH  := _CLOG._CLOG;

  (*From OSCAT Library, www.oscat.de *)
  (* datatype OSCAT_COMPLEX, CLOG, CSQRT required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CACOS
  VAR_INPUT
    X : OSCAT_COMPLEX;
  END_VAR
  VAR_OUTPUT
    _CACOS : OSCAT_COMPLEX;
  END_VAR
  VAR
    Y : OSCAT_COMPLEX;
    _CACOSH : CACOSH;
  END_VAR

  _CACOSH(X:=x);
  y := _CACOSH._CACOSH;
  _CACOS.re := y.im;
  _CACOS.im := -y.re;

  (*From OSCAT Library, www.oscat.de *)
  (* datatype OSCAT_COMPLEX, CACOSH required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CATAN
  VAR_INPUT
    X : OSCAT_COMPLEX;
  END_VAR
  VAR_OUTPUT
    _CATAN : OSCAT_COMPLEX;
  END_VAR
  VAR
    r2 : REAL;
    num : REAL;
    den : REAL;
  END_VAR

  r2 := x.re * x.re;
  den := 1.0 - r2 - x.im * x.im;
  _CATAN.re := 0.5 * ATAN(2.0 * x.re / den);
  num := x.im + 1.0;
  num := r2 + num * num;
  den := x.im - 1.0;
  den := r2 + den * den;
  _CATAN.im := 0.25 * (LN(num)-LN(den));

  (*From OSCAT Library, www.oscat.de *)
  (* datatype OSCAT_COMPLEX required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CARG
  VAR_INPUT
    X : OSCAT_COMPLEX;
  END_VAR
  VAR_OUTPUT
    _CARG : REAL;
  END_VAR

  _CARG := ATAN2(X.im, X.re);

  (*From OSCAT Library, www.oscat.de *)
  (* datatype OSCAT_COMPLEX required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CEXP
  VAR_INPUT
    X : OSCAT_COMPLEX;
  END_VAR
  VAR_OUTPUT
    _CEXP : OSCAT_COMPLEX;
  END_VAR
  VAR
    temp : REAL;
  END_VAR

  temp := EXP(X.re);
  _CEXP.re := temp * COS(X.im);
  _CEXP.im := temp * SIN(X.im);

  (*From OSCAT Library, www.oscat.de *)
  (* datatype OSCAT_COMPLEX required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CPOW
  VAR_INPUT
    X : OSCAT_COMPLEX;
    Y : OSCAT_COMPLEX;
  END_VAR
  VAR_OUTPUT
    _CPOW : OSCAT_COMPLEX;
  END_VAR
  VAR
    _CLOG : CLOG;
    _CEXP : CEXP;
    _CMUL : CMUL;
  END_VAR

  _CLOG(X:=X);
  _CMUL(X:=Y,Y:=_CLOG._CLOG);
  _CEXP(X:=_CMUL._CMUL);
  _CPOW := _CEXP._CEXP;

  (*From OSCAT Library, www.oscat.de *)
  (* datatype OSCAT_COMPLEX, CLOG, CEXP, CMUL required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CATANH
  VAR_INPUT
    X : OSCAT_COMPLEX;
  END_VAR
  VAR_OUTPUT
    _CATANH : OSCAT_COMPLEX;
  END_VAR
  VAR
    i2 : REAL;
    num : REAL;
    den : REAL;
  END_VAR

  i2 := x.im * x.im;
  num := 1.0 + x.re;
  num := i2 + num * num;
  den := 1.0 - x.re;
  den := i2 + den * den;
  _CATANH.re := 0.25 * (LN(num) - LN(den));
  den := 1.0 - x.re * x.re - i2;
  _CATANH.im := 0.5 * ATAN(2.0 * x.im / den);

  (*From OSCAT Library, www.oscat.de *)
  (* datatype OSCAT_COMPLEX, HYPOT required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CSET
  VAR_INPUT
    RE : REAL;
    IM : REAL;
  END_VAR
  VAR_OUTPUT
    _CSET : OSCAT_COMPLEX;
  END_VAR

  _CSET.re := RE;
  _CSET.im := IM;

  (*From OSCAT Library, www.oscat.de *)
  (* datatype OSCAT_COMPLEX required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CINV
  VAR_INPUT
    X : OSCAT_COMPLEX;
  END_VAR
  VAR_OUTPUT
    _CINV : OSCAT_COMPLEX;
  END_VAR
  VAR
    temp : REAL;
  END_VAR

  temp := X.re * X.re + X.im * X.im;
  IF temp = 0.0 THEN _CINV.re := 0.0;_CINV.im := 0.0;RETURN;END_IF;
  _CINV.re := X.re / temp;
  _CINV.im := -X.im / temp;

  (*From OSCAT Library, www.oscat.de *)
  (* datatype OSCAT_COMPLEX, HYPOT required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CCOS
  VAR_INPUT
    X : OSCAT_COMPLEX;
  END_VAR
  VAR_OUTPUT
    _CCOS : OSCAT_COMPLEX;
  END_VAR
  VAR
    _CSET : CSET;
    _CCOSH : CCOSH;
  END_VAR

  _CSET(RE:= -X.im,IM:=X.re);
  _CCOSH(X:=_CSET._CSET);
  _CCOS := _CCOSH._CCOSH;

  (*From OSCAT Library, www.oscat.de *)
  (* datatype OSCAT_COMPLEX, CSET, CCOSH required *)
END_FUNCTION_BLOCK


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
