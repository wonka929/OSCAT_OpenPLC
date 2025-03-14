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
  LocalVar2 := ADD1_OUT;
END_PROGRAM

FUNCTION CIRCLE_A : REAL
  VAR_INPUT
    AX : REAL;
    RX : REAL;
  END_VAR

  circle_A := Rx * RX * 8.726646E-3 * Ax;

  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION

FUNCTION CIRCLE_C : REAL
  VAR_INPUT
    AX : REAL;
    RX : REAL;
  END_VAR

  circle_C := 1.7453293E-2 * Rx * Ax;
  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION

FUNCTION SPHERE_V : REAL
  VAR_INPUT
    RX : REAL;
  END_VAR

  sphere_V := 4.188790205 * Rx * RX * RX;

  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION

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

FUNCTION ELLIPSE_C : REAL
  VAR_INPUT
    R1 : REAL;
    R2 : REAL;
  END_VAR

  ELLIPSE_C := 3.14159265358979323846264338327950288 * (3.0 * (R1+R2) - SQRT((3.0 * r1 + R2) * (3.0 * r2 + r1)));

  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION

FUNCTION CONE_V : REAL
  VAR_INPUT
    RX : REAL;
    HX : REAL;
  END_VAR

  cone_V := 1.047197551 * RX * RX * hx;

  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION

FUNCTION TRIANGLE_A : REAL
  VAR_INPUT
    A : REAL;
    S1 : REAL;
    S2 : REAL;
    S3 : REAL;
  END_VAR

  IF A = 0.0 THEN
  	TRIANGLE_A := SQRT((s1+s2+S3) * (s1+s2-S3) * (S2+S3-S1) * (S3+S1-S2)) * 0.25;
  ELSE
  	TRIANGLE_A := S1 * S2 * SIN(RAD(A)) * 0.5;
  END_IF;

  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION

FUNCTION ELLIPSE_A : REAL
  VAR_INPUT
    R1 : REAL;
    R2 : REAL;
  END_VAR

  ellipse_A := 3.14159265358979323846264338327950288 * R1 * R2;

  (* From OSCAT Library, www.OSCAT.de *)
END_FUNCTION


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
