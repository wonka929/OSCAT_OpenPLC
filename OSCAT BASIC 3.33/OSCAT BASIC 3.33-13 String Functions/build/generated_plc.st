FUNCTION_BLOCK BYTE_TO_STRB
  VAR_INPUT
    IN : BYTE;
    _BYTE_TO_STRB : STRING;
  END_VAR
  VAR
    i : INT;
  END_VAR

  _BYTE_TO_STRB := '';
  FOR i := 1 TO 8 DO
      IF (in AND BYTE#2#1000_0000) = BYTE#2#1000_0000 THEN
          _BYTE_TO_STRB := CONCAT(_BYTE_TO_STRB,'1');
      ELSE
          _BYTE_TO_STRB := CONCAT(_BYTE_TO_STRB,'0');
      END_IF;
  	in := SHL(in, 1);
  END_FOR;

  (* From Oscat Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK BYTE_TO_STRH
  VAR_INPUT
    IN : BYTE;
  END_VAR
  VAR_OUTPUT
    _BYTE_TO_STRH : STRING;
  END_VAR

  _BYTE_TO_STRH:=BYTE_TO_STRING(IN,'%c');




  (* From Oscat Library, www.oscat.de *)
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


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
