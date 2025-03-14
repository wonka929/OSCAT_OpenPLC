TYPE
  REAL2 : STRUCT
    R1 : REAL;
    RX : REAL;
  END_STRUCT;
END_TYPE

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

FUNCTION_BLOCK R2_DIV
  VAR_INPUT
    X : REAL2;
    Y : REAL;
    _R2_DIV : REAL2;
  END_VAR

  _R2_DIV.RX := X.RX / Y;
  _R2_DIV.R1 := X.R1 / Y;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK R2_ABS
  VAR_INPUT
    X : REAL2;
  END_VAR
  VAR_OUTPUT
    _R2_ABS : REAL2;
  END_VAR

  IF X.RX >= 0.0 THEN
  	_R2_ABS.RX := X.RX;
  	_R2_ABS.R1 := X.R1;
  ELSE
  	_R2_ABS.RX := -X.RX;
  	_R2_ABS.R1 := -X.R1;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK R2_MUL
  VAR_INPUT
    X : REAL2;
    Y : REAL;
  END_VAR
  VAR_OUTPUT
    _R2_MUL : REAL2;
  END_VAR

  _R2_MUL.RX := X.RX * Y;
  _R2_MUL.R1 := X.R1 * Y;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION MUX_R2 : REAL
  VAR_INPUT
    IN0 : REAL;
    IN1 : REAL;
    A : BOOL;
  END_VAR

  MUX_R2 := SEL(A, IN0, IN1);

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK R2_ADD2
  VAR_INPUT
    X : REAL2;
    Y : REAL2;
  END_VAR
  VAR_OUTPUT
    _R2_ADD2 : REAL2;
  END_VAR

  _R2_ADD2.R1 := X.R1 + Y.R1;
  _R2_ADD2.RX := X.RX + Y.RX;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
