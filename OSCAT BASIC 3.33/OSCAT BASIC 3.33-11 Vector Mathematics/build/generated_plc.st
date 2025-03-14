TYPE
  VECTOR_3 : STRUCT
    X : REAL;
    Y : REAL;
    Z : REAL;
  END_STRUCT;
END_TYPE

FUNCTION V3_DPRO : REAL
  VAR_INPUT
    A : VECTOR_3;
    B : VECTOR_3;
  END_VAR

  V3_DPRO := A.X * B.X + A.Y * B.Y + A.Z * B.Z;

  (* From O<<sC<AT Library, www.oscat.de *)
END_FUNCTION

FUNCTION V3_ABS : REAL
  VAR_INPUT
    A : VECTOR_3;
  END_VAR

  V3_ABS := SQRT(A.X * A.X + A.Y * A.Y + A.Z * A.Z);

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION V3_ANG : REAL
  VAR_INPUT
    A : VECTOR_3;
    B : VECTOR_3;
  END_VAR
  VAR
    _d : REAL;
  END_VAR

  _d := V3_ABS(A) * V3_ABS(B);
  IF _d > 0.0 THEN
  	V3_ANG := ACOS(LIMIT(-1.0, V3_DPRO(A, B) / _d,1.0));
  END_IF;
  (* From O<<sC<AT Library, www.oscat.de *)
END_FUNCTION

FUNCTION V3_ADD : VECTOR_3
  VAR_INPUT
    A : VECTOR_3;
    B : VECTOR_3;
  END_VAR

  V3_ADD.X := A.X + B.X;
  V3_ADD.Y := A.Y + B.Y;
  V3_ADD.Z := A.Z + B.Z;

  (* From O<<sC<AT Library, www.oscat.de *)
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

FUNCTION V3_REV : VECTOR_3
  VAR_INPUT
    A : VECTOR_3;
  END_VAR

  V3_REV.X := -A.X;
  V3_REV.Y := -A.Y;
  V3_REV.Z := -A.Z;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION V3_SMUL : VECTOR_3
  VAR_INPUT
    A : VECTOR_3;
    M : REAL;
  END_VAR

  V3_SMUL.X := A.X * M;
  V3_SMUL.Y := A.Y * M;
  V3_SMUL.Z := A.Z * M;

  (* From O<<sC<AT Library, www.oscat.de *)
END_FUNCTION

FUNCTION V3_NORM : VECTOR_3
  VAR_INPUT
    A : VECTOR_3;
  END_VAR
  VAR
    la : REAL;
  END_VAR

  la := V3_ABS(A);
  IF la > 0.0 THEN
  	V3_NORM := V3_SMUL(A, 1.0 / la);
  END_IF;

  (* From O<<sC<AT Library, www.oscat.de *)
END_FUNCTION

FUNCTION V3_NUL : BOOL
  VAR_INPUT
    A : VECTOR_3;
  END_VAR

  V3_NUL := A.X = 0.0 AND A.Y = 0.0 AND A.Z = 0.0;

  (* From O<<sC<AT Library, www.oscat.de *)
END_FUNCTION

FUNCTION V3_XPRO : VECTOR_3
  VAR_INPUT
    A : VECTOR_3;
    B : VECTOR_3;
  END_VAR

  V3_XPRO.X := A.Y * B.Z - A.Z * B.Y;
  V3_XPRO.Y := A.Z * B.X - A.X * B.Z;
  V3_XPRO.Z := A.X * B.Y - A.Y * B.X;

  (* From O<<sC<AT Library, www.oscat.de *)
END_FUNCTION

FUNCTION V3_PAR : BOOL
  VAR_INPUT
    A : VECTOR_3;
    B : VECTOR_3;
  END_VAR

  V3_PAR := V3_ABS(V3_XPRO(A, B)) = 0.0;

  (* From O<<sC<AT Library, www.oscat.de *)
END_FUNCTION

FUNCTION V3_SUB : VECTOR_3
  VAR_INPUT
    A : VECTOR_3;
    B : VECTOR_3;
  END_VAR

  V3_SUB.X := A.X - B.X;
  V3_SUB.Y := A.Y - B.Y;
  V3_SUB.Z := A.Z - B.Z;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION V3_XANG : REAL
  VAR_INPUT
    A : VECTOR_3;
  END_VAR
  VAR
    la : REAL;
  END_VAR

  la := V3_ABS(a);
  IF la > 0.0 THEN
  	V3_XANG := ACOS(A.X / la);
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION V3_YANG : REAL
  VAR_INPUT
    A : VECTOR_3;
  END_VAR
  VAR
    la : REAL;
  END_VAR

  la := V3_ABS(a);
  IF la > 0.0 THEN
  	V3_YANG := ACOS(A.Y / la);
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION V3_ZANG : REAL
  VAR_INPUT
    A : VECTOR_3;
  END_VAR
  VAR
    la : REAL;
  END_VAR

  la := V3_ABS(a);
  IF la > 0.0 THEN
  	V3_ZANG := ACOS(A.Z / la);
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
