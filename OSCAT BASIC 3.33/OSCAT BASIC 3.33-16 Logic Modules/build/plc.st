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


FUNCTION BIT_OF_DWORD : BOOL
  VAR_INPUT
    IN : DWORD;
    N : INT;
  END_VAR

  BIT_OF_DWORD := (SHR(in,N) AND 16#00000001) > 0;

  (* From Oscat Library, www.oscat.de *)
END_FUNCTION

FUNCTION PARITY : BOOL
  VAR_INPUT
    IN : DWORD;
  END_VAR
  VAR
    in2 : DWORD;
  END_VAR

  in2:=in;
  WHILE in2 > DWORD#0 DO
  	parity := parity XOR BIT_OF_DWORD(in2,0) XOR BIT_OF_DWORD(in2,1) XOR BIT_OF_DWORD(in2,2) XOR BIT_OF_DWORD(in2,3);
  	in2 := SHR(in2,4);
  END_WHILE;

  (* Fromm Oscat Library, www.oscat.de *)
END_FUNCTION

FUNCTION REVERSE : BYTE
  VAR_INPUT
    IN : BYTE;
  END_VAR

  reverse := SHL(in,7) OR SHR(in,7) OR (ROR(in,3) AND BYTE#2#01000100) OR (ROL(in,3) AND BYTE#2#00100010)
  	OR (SHL(in,1) AND BYTE#2#00010000) OR (SHR(in,1) AND BYTE#2#00001000);


  (* Fromm Oscat Library, www.oscat.de *)
END_FUNCTION

FUNCTION WORD_OF_BYTE : WORD
  VAR_INPUT
    B0 : BYTE;
    B1 : BYTE;
  END_VAR

  WORD_OF_BYTE := SHL(BYTE_TO_WORD(B1),8) OR BYTE_TO_WORD(B0);

  (* Fromm Oscat Library, www.oscat.de *)
END_FUNCTION

FUNCTION GRAY_TO_BYTE : BYTE
  VAR_INPUT
    IN : BYTE;
  END_VAR

  GRAY_TO_BYTE := SHR(IN,4) XOR IN;
  GRAY_TO_BYTE := SHR(GRAY_TO_BYTE,2) XOR GRAY_TO_BYTE;
  GRAY_TO_BYTE := SHR(GRAY_TO_BYTE,1) XOR GRAY_TO_BYTE;

  (* Fromm Oscat Library, www.oscat.de *)
END_FUNCTION

FUNCTION _BYTE_TO_INT : INT
  VAR_INPUT
    IN : BYTE;
  END_VAR

  _BYTE_TO_INT := USINT_TO_INT(BYTE_TO_USINT(IN));

  (*From OSCAT Library, www.oscat.de*)
END_FUNCTION

FUNCTION BYTE_OF_DWORD : BYTE
  VAR_INPUT
    IN : DWORD;
    N : BYTE;
  END_VAR

  BYTE_OF_DWORD := DWORD_TO_BYTE(SHR(in,_BYTE_TO_INT(SHL(n,3))));

  (*From OSCAT Library, www.oscat.de*)
END_FUNCTION

FUNCTION BIT_LOAD_W2 : WORD
  VAR_INPUT
    I : WORD;
    _D : BOOL;
    P : INT;
    N : INT;
  END_VAR

  IF _D THEN
  	BIT_LOAD_W2 := ROL(SHR(WORD#16#FFFF, 16 - N) OR ROR(I, P), P);
  ELSE
  	BIT_LOAD_W2 := ROL(SHL(WORD#16#FFFF, N) AND ROR(I, P), P);
  END_IF;

  (*From OSCAT Library, www.oscat.de*)
END_FUNCTION

FUNCTION INT_TO_BCDC : BYTE
  VAR_INPUT
    IN : INT;
  END_VAR

  INT_TO_BCDC := SHL(INT_TO_BYTE(IN / INT#10),4) OR INT_TO_BYTE(in MOD INT#10);

  (* Fromm Oscat Library, www.oscat.de *)
END_FUNCTION

FUNCTION WORD_OF_DWORD : WORD
  VAR_INPUT
    IN : DWORD;
    N : BYTE;
  END_VAR

  WORD_OF_DWORD := DWORD_TO_WORD(SHR(in,_BYTE_TO_INT(SHL(n,4))));

  (* Fromm Oscat Library, www.oscat.de *)
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

FUNCTION MUX_2 : BOOL
  VAR_INPUT
    D0 : BOOL;
    D1 : BOOL;
    A0 : BOOL;
  END_VAR

  MUX_2 := SEL(A0, D0, D1);

  (* Fromm Oscat Library, www.oscat.de *)
END_FUNCTION

FUNCTION BYTE_OF_BIT : BYTE
  VAR_INPUT
    B0 : BOOL;
    B1 : BOOL;
    B2 : BOOL;
    B3 : BOOL;
    B4 : BOOL;
    B5 : BOOL;
    B6 : BOOL;
    B7 : BOOL;
  END_VAR

  Byte_of_bit := SHL(SHL(SHL(SHL(SHL(SHL(SHL(BOOL_TO_BYTE(B7),1) OR BOOL_TO_BYTE(B6),1)
   OR BOOL_TO_BYTE(B5),1) OR BOOL_TO_BYTE(B4),1) OR BOOL_TO_BYTE(B3),1) OR BOOL_TO_BYTE(B2),1)
   OR BOOL_TO_BYTE(B1),1) OR BOOL_TO_BYTE(B0);

  (*From OSCAT Library, www.oscat.de*)
END_FUNCTION

FUNCTION MUX_4 : BOOL
  VAR_INPUT
    D0 : BOOL;
    D1 : BOOL;
    D2 : BOOL;
    D3 : BOOL;
    A0 : BOOL;
    A1 : BOOL;
  END_VAR

  IF A1 THEN
  	MUX_4 := SEL(A0, D2, D3);
  ELSE
  	MUX_4 := SEL(A0, D0, D1);
  END_IF;

  (* Fromm Oscat Library, www.oscat.de *)
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

FUNCTION DEC_2 : BOOL
  VAR_INPUT
    DI : BOOL;
    A : BOOL;
  END_VAR
  VAR_OUTPUT
    Q0 : BOOL;
    Q1 : BOOL;
  END_VAR

  Q0 := DI AND NOT A;
  Q1 := DI AND A;

  (* Fromm Oscat Library, www.oscat.de *)
END_FUNCTION

FUNCTION DEC_4 : BOOL
  VAR_INPUT
    DI : BOOL;
    A0 : BOOL;
    A1 : BOOL;
  END_VAR
  VAR_OUTPUT
    Q0 : BOOL;
    Q1 : BOOL;
    Q2 : BOOL;
    Q3 : BOOL;
  END_VAR

  Q0 := DI AND NOT A0 AND NOT A1;
  Q1 := DI AND A0 AND NOT A1;
  Q2 := DI AND NOT A0 AND A1;
  Q3 := DI AND A0 AND A1;

  (* Fromm Oscat Library, www.oscat.de *)
END_FUNCTION

FUNCTION SHR1 : DWORD
  VAR_INPUT
    IN : DWORD;
    N : INT;
  END_VAR

  SHR1 := SHL(DWORD#16#FF_FF_FF_FF,32-N) OR SHR(IN,N);

  (* Fromm Oscat Library, www.oscat.de *)
END_FUNCTION

FUNCTION DEC_8 : BOOL
  VAR_INPUT
    DI : BOOL;
    A0 : BOOL;
    A1 : BOOL;
    A2 : BOOL;
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
  END_VAR
  VAR
    X : BYTE;
  END_VAR

  X:=BIT_LOAD_B(X,A0,0); (* X.0 := A0; *)
  X:=BIT_LOAD_B(X,A1,1); (* X.1 := A1; *)
  X:=BIT_LOAD_B(X,A2,2); (* X.2 := A2; *)

  Q0 := FALSE;
  Q1 := FALSE;
  Q2 := FALSE;
  Q3 := FALSE;
  Q4 := FALSE;
  Q5 := FALSE;
  Q6 := FALSE;
  Q7 := FALSE;

  CASE _BYTE_TO_INT(X) OF
  	0 : Q0 := DI;
  	1 : Q1 := DI;
  	2 : Q2 := DI;
  	3 : Q3 := DI;
  	4 : Q4 := DI;
  	5 : Q5 := DI;
  	6 : Q6 := DI;
  	7 : Q7 := DI;
  END_CASE;

  (* Fromm Oscat Library, www.oscat.de *)
END_FUNCTION

FUNCTION DWORD_OF_BYTE : DWORD
  VAR_INPUT
    B0 : BYTE;
    B1 : BYTE;
    B2 : BYTE;
    B3 : BYTE;
  END_VAR

  DWORD_OF_BYTE := SHL(SHL(SHL(BYTE_TO_DWORD(B3),8) OR BYTE_TO_DWORD(B2),8) OR BYTE_TO_DWORD(B1),8) OR BYTE_TO_DWORD(B0);

  (* Fromm Oscat Library, www.oscat.de *)
END_FUNCTION

FUNCTION BYTE_TO_BITS : BOOL
  VAR
    IN : BYTE;
  END_VAR
  VAR_OUTPUT
    B0 : BOOL;
    B1 : BOOL;
    B2 : BOOL;
    B3 : BOOL;
    B4 : BOOL;
    B5 : BOOL;
    B6 : BOOL;
    B7 : BOOL;
  END_VAR

  B0 := BIT_OF_DWORD(BYTE_TO_DWORD(IN),0); (* IN.X0 *)
  B1 := BIT_OF_DWORD(BYTE_TO_DWORD(IN),1); (* IN.X1 *)
  B2 := BIT_OF_DWORD(BYTE_TO_DWORD(IN),2); (* IN.X2 *)
  B3 := BIT_OF_DWORD(BYTE_TO_DWORD(IN),3); (* IN.X3 *)
  B4 := BIT_OF_DWORD(BYTE_TO_DWORD(IN),4); (* IN.X4 *)
  B5 := BIT_OF_DWORD(BYTE_TO_DWORD(IN),5); (* IN.X5 *)
  B6 := BIT_OF_DWORD(BYTE_TO_DWORD(IN),6); (* IN.X6 *)
  B7 := BIT_OF_DWORD(BYTE_TO_DWORD(IN),7); (* IN.X7 *)

  (*From OSCAT Library, www.oscat.de*)
END_FUNCTION

FUNCTION BYTE_TO_GRAY : BYTE
  VAR_INPUT
    IN : BYTE;
  END_VAR

  BYTE_TO_GRAY := IN XOR SHR(IN,1);

  (*From OSCAT Library, www.oscat.de*)
END_FUNCTION

FUNCTION BIT_TOGGLE_DW : DWORD
  VAR_INPUT
    IN : DWORD;
    POS : INT;
  END_VAR

  BIT_TOGGLE_DW := SHL(DWORD#1, POS) XOR IN;

  (*From OSCAT Library, www.oscat.de*)
END_FUNCTION

FUNCTION SWAP_BYTE2 : DWORD
  VAR_INPUT
    IN : DWORD;
  END_VAR

  Swap_Byte2 := (ROR(in,8) AND DWORD#16#FF00FF00) OR (ROL(in,8) AND DWORD#16#00FF00FF);

  (* Fromm Oscat Library, www.oscat.de *)
END_FUNCTION

FUNCTION REFLECT : DWORD
  VAR_INPUT
    DI : DWORD;
    L : INT;
  END_VAR
  VAR
    i : INT;
    _d : DWORD;
  END_VAR

  _d := DI;
  FOR i := 1 TO L DO
  	REFLECT := SHL(REFLECT, 1) OR BOOL_TO_DWORD((_d AND DWORD#2#0000_0001) > DWORD#0); (* D.0 *)
  	_d := SHR(_d, 1);
  END_FOR;
  REFLECT := REFLECT OR SHL(_d, L);


  (* Fromm Oscat Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK CRC_GEN
  VAR_IN_OUT
    PT : ARRAY [0..249] OF BYTE;
  END_VAR
  VAR_INPUT
    SIZE : UINT;
    PL : UINT;
    PN : DWORD;
    INIT : DWORD;
    REV_IN : BOOL;
    REV_OUT : BOOL;
    XOR_OUT : DWORD;
  END_VAR
  VAR_OUTPUT
    _CRC_GEN : DWORD;
  END_VAR
  VAR
    pos : INT;
    shift : INT;
    bits : INT;
    dx : BYTE;
  END_VAR

  shift := 32 - UINT_TO_INT(PL);
  PN := SHL(PN, shift);

  (* load first 4 bytes into register minimum message size is 4 bytes
  	for smaller messages fill with 0#s at the beginning*)
  FOR pos := 0 TO 3 DO
  	IF REV_IN THEN _CRC_GEN := SHL(_CRC_GEN, 8) OR BYTE_TO_DWORD(REVERSE(PT[pos])); ELSE _CRC_GEN := SHL(_CRC_GEN, 8) OR BYTE_TO_DWORD(PT[pos]); END_IF;
  END_FOR;
  pos := 4;

  (* xor with init value *)
  _CRC_GEN := _CRC_GEN XOR SHL(init, shift);

  (* calculate CRC for each byte *)
  WHILE pos < UINT_TO_INT(size) DO
  	IF REV_IN THEN DX := REVERSE(PT[pos]); ELSE DX := PT[pos]; END_IF;
  	pos := pos + 1;
  	(* crc calculation for one byte *)
  	FOR bits := 0 TO 7 DO
  		IF (_CRC_GEN AND DWORD#16#8000_0000) > DWORD#0 THEN (* CRC_GEN.31 *)
  			_CRC_GEN := (SHL(_CRC_GEN, 1) OR BOOL_TO_DWORD((DX AND BYTE#16#80) > BYTE#0)) XOR PN; (* DX.7 *)
  		ELSE
  			_CRC_GEN := SHL(_CRC_GEN, 1) OR BOOL_TO_DWORD((DX AND BYTE#16#80) > BYTE#0); (* DX.7 *)
  		END_IF;
  		dx := SHL(dx, 1);
  	END_FOR;
  END_WHILE;

  (* all bytes are processed, need to finish the registers 32 bits *)
  FOR bits := 0 TO 31 DO
  	IF (_CRC_GEN AND DWORD#16#8000_0000) > DWORD#0 THEN (* CRC_GEN.31 *)
  		_CRC_GEN := (SHL(_CRC_GEN, 1) OR BOOL_TO_DWORD((DX AND BYTE#16#80) > BYTE#0)) XOR PN; (* DX.7 *)
  	ELSE
  		_CRC_GEN := SHL(_CRC_GEN, 1) OR BOOL_TO_DWORD((DX AND BYTE#16#80) > BYTE#0); (* DX.7 *)
  	END_IF;
  END_FOR;

  (* final XOR *)
  _CRC_GEN := SHR(_CRC_GEN, shift) XOR XOR_OUT;

  (* reverse the crc_out put if necessary *)
  IF REV_OUT THEN _CRC_GEN := REFLECT(_CRC_GEN, UINT_TO_INT(PL)); END_IF;


  (* typical crc polynoms

  CRC-4-ITU 			x4 + x + 1 					(ITU G.704, p. 12) 	0x3 or 0xC (0x9)
  CRC-5-ITU 			x5 + x4 + x2 + 1 			(ITU G.704, p. 9) 	0x15 or 0x15 (0x0B) Bluetooth
  CRC-5-USB 			x5 + x2 + 1 				(use: USB token packets) 	0x05 or 0x14 (0x9)
  CRC-6-ITU 			x6 + x + 1 					(ITU G.704, p. 3) 	0x03 or 0x30 (0x21)
  CRC-7 				x7 + x3 + 1 				(use: telecom systems, MMC) 	0x09 or 0x48 (0x11)
  CRC-8-ATM 			x8 + x2 + x + 1 				(use: ATM HEC) 	0x07 or 0xE0 (0xC1)
  CRC-8-CCITT 		x8 + x7 + x3 + x2 + 1 		(use: 1-Wire bus) 	0x8D or 0xB1 (0x63)
  CRC-8-Dallas/Maxim 	x8 + x5 + x4 + 1 			(use: 1-Wire bus) 	0x31 or 0x8C (0x19)
  CRC-8 				x8 + x7 + x6 + x4 + x2 + 1 	0xD5 or 0xAB (0x57)
  CRC-8-SAE J1850 	x8 + x4 + x3 + x2 + 1 		0x1D or 0xB8
  CRC-10 				x10 + x9 + x5 + x4 + x + 1 	0x233 or 0x331 (0x263)
  CRC-12 				x12 + x11 + x3 + x2 + x + 1 (use: telecom systems) 	0x80F or 0xF01 (0xE03)
  CRC-15-CAN 			x15 + x14 + x10 + x8 + x7 + x4 + x3 + 1 	0x4599 or 0x4CD1 (0x19A3)
  CRC-16-Fletcher 	Not a CRC; see Fletcher's checksum 	Used in Adler-32 A & B CRCs
  CRC-16-CCITT 	x16 + x12 + x5 + 1 (XMODEM,X.25, V.41, Bluetooth, PPP, IrDA; known as "CRC-CCITT") 	0x1021 or 0x8408 (0x0811)
  CRC-16-IBM 	x16 + x15 + x2 + 1 (USB, many others; also known as "CRC-16") 	0x8005 or 0xA001 (0x4003)
  CRC-24-Radix-64 	x24 + x23 + x18 + x17 + x14 + x11 + x10 + x7 + x6 + x5 + x4 + x3 + x + 1 	0x864CFB or 0xDF3261 (0xBE64C3)
  CRC-32-Adler 	Not a CRC; see Adler-32 	See Adler-32
  CRC-32-MPEG2 	x32 + x26 + x23 + x22 + x16 + x12 + x11 + x10 + x8 + x7 + x5 + x4 + x2 + x + 1 	0x04C11DB7 or 0xEDB88320 (0xDB710641) Also used in IEEE 802.3
  CRC-32-IEEE 802.3 	x32 + x26 + x23 + x22 + x16 + x12 + x11 + x10 + x8 + x7 + x5 + x4 + x2 + x + 1 (V.42) 	0x04C11DB7 or 0xEDB88320 (0xDB710641)
  CRC-32C (Castagnoli) 	x32 + x28 + x27 + x26 + x25 + x23 + x22 + x20 + x19 + x18 + x14 + x13 + x11 + x10 + x9 + x8 + x6 + 1 	0x1EDC6F41 or 0x82F63B78 (0x05EC76F1)
  CRC-64-ISO 	x64 + x4 + x3 + x + 1 (use: ISO 3309) 	0x000000000000001B or 0xD800000000000000 (0xB000000000000001)
  CRC-64-ECMA-182 	x64 + x62 + x57 + x55 + x54 + x53 + x52 + x47 + x46 + x45 + x40 + x39 + x38 + x37 + x35 + x33 + x32 + x31 + x29 + x27 + x24 + x23 + x22 + x21 + x19 + x17 + x13 + x12 + x10 + x9 + x7 + x4 + x + 1
  (as described in ECMA-182 p.63) 	0x42F0E1EBA9EA3693 or 0xC96C5795D7870F42 (0x92D8AF2BAF0E1E85)
  *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK MATRIX
  VAR_INPUT
    X1 : BOOL;
    X2 : BOOL;
    X3 : BOOL;
    X4 : BOOL;
    X5 : BOOL;
    RELEASE : BOOL;
  END_VAR
  VAR_OUTPUT
    CODE : BYTE;
    _TP : BOOL;
    Y1 : BOOL := TRUE;
    Y2 : BOOL;
    Y3 : BOOL;
    Y4 : BOOL;
  END_VAR
  VAR
    line : BYTE;
    x : ARRAY [0..3] OF BYTE;
    l : ARRAY [0..3] OF BYTE;
    i : INT;
    temp : BYTE;
    temp2 : BYTE;
    L_temp : BYTE;
    temp_bit : BOOL;
    in_temp : INT;
  END_VAR

  _TP := FALSE;
  code := BYTE#0;

  (* read scan lines *)
  in_temp := _BYTE_TO_INT(line);
  temp := X[in_temp];  (* X[LINE] umkopieren *)

  temp:=BIT_LOAD_B(temp,X1,0); (* X[line].0 := X1; *)
  temp:=BIT_LOAD_B(temp,X2,1); (* X[line].1 := X2; *)
  temp:=BIT_LOAD_B(temp,X3,2); (* X[line].2 := X3; *)
  temp:=BIT_LOAD_B(temp,X4,3); (* X[line].3 := X4; *)
  temp:=BIT_LOAD_B(temp,X5,4); (* X[line].4 := X5; *)

  X[in_temp] := temp; (* X[LINE] zurückkopieren *)

  (* compare for change *)
  FOR i := 0 TO 3 DO
  	IF X[i] <> L[i] THEN
  		(* scan line information has changed code need to be found and generated *)
  		temp   := x[i] XOR L[i];
          temp2  := X[i];
          L_temp := L[i];

          IF BIT_OF_DWORD(BYTE_TO_DWORD(temp),0) THEN (* temp.l *)
  			code := BYTE#1;
              temp_bit := BIT_OF_DWORD(BYTE_TO_DWORD(temp2),0);   (* X[i].l *)
              code := BIT_LOAD_B(code,temp_bit,7);     			(* code.X7 *)
              L_temp := BIT_LOAD_B(L_temp,temp_bit,0); 			(* L[i].l *)
  		ELSIF BIT_OF_DWORD(BYTE_TO_DWORD(temp),1) THEN          (* temp.X1 *)
  			code := BYTE#2;
              temp_bit := BIT_OF_DWORD(BYTE_TO_DWORD(temp2),1);   (* X[i].X1 *)
              code := BIT_LOAD_B(code,temp_bit,7);     			(* code.X7 *)
              L_temp := BIT_LOAD_B(L_temp,temp_bit,1); 			(* L[i].X1 *)
  		ELSIF BIT_OF_DWORD(BYTE_TO_DWORD(temp),2) THEN          (* temp.X2 *)
  			code := BYTE#3;
              temp_bit := BIT_OF_DWORD(BYTE_TO_DWORD(temp2),2);   (* X[i].X2 *)
              code := BIT_LOAD_B(code,temp_bit,7);     			(* code.X7 *)
              L_temp := BIT_LOAD_B(L_temp,temp_bit,2); 			(* L[i].X2 *)
  		ELSIF BIT_OF_DWORD(BYTE_TO_DWORD(temp),3) THEN          (* temp.X3 *)
  			code := BYTE#4;
              temp_bit := BIT_OF_DWORD(BYTE_TO_DWORD(temp2),3);   (* X[i].X3 *)
              code := BIT_LOAD_B(code,temp_bit,7);     			(* code.X7 *)
              L_temp := BIT_LOAD_B(L_temp,temp_bit,3); 			(* L[i].X3 *)
  		ELSIF BIT_OF_DWORD(BYTE_TO_DWORD(temp),4) THEN          (* temp.X4 *)
  			code := BYTE#5;
              temp_bit := BIT_OF_DWORD(BYTE_TO_DWORD(temp2),4);   (* X[i].X4 *)
              code := BIT_LOAD_B(code,temp_bit,7);     			(* code.X7 *)
              L_temp := BIT_LOAD_B(L_temp,temp_bit,4); 			(* L[i].X4 *)
  		END_IF;
          L[i] := L_temp;
  		_TP := TRUE;
          code := (code AND BYTE#2#1000_1111) OR SHL(LINE AND BYTE#2#0000_0111,4);
          (* obere zeile enspricht: Code.X4 := Line.l; /  Code.X5 := Line.X1; / Code.RELEASE := Line.X2; *)

  		(* check if release codes need to be killed *)
  		IF NOT release AND code < BYTE#127 THEN
  			code := BYTE#0;
  			_TP := FALSE;
  		END_IF;
          EXIT;
  	END_IF;
  END_FOR;

  (* increment scan line every cycle *)
  line := INT_TO_BYTE(_BYTE_TO_INT(line) + 1) AND BYTE#2#0000_0011;
  temp := SHL(BYTE#1,_BYTE_TO_INT(line));

  Y1 := BIT_OF_DWORD(BYTE_TO_DWORD(temp),0); (* temp.0 *)
  Y2 := BIT_OF_DWORD(BYTE_TO_DWORD(temp),1); (* temp.1 *)
  Y3 := BIT_OF_DWORD(BYTE_TO_DWORD(temp),2); (* temp.2 *)
  Y4 := BIT_OF_DWORD(BYTE_TO_DWORD(temp),3); (* temp.3 *)

  (* Fromm Oscat Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION CHECK_PARITY : BOOL
  VAR_INPUT
    IN : DWORD;
    P : BOOL;
  END_VAR
  VAR
    IN2 : DWORD;
  END_VAR

  in2:=in;
  check_parity := NOT p;
  WHILE in2 > DWORD#0 DO
  	check_parity := check_parity XOR BIT_OF_DWORD(in2,0) XOR BIT_OF_DWORD(in2,1) XOR BIT_OF_DWORD(in2,2) XOR BIT_OF_DWORD(in2,3);
  	in2 := SHR(in2,4);
  END_WHILE;

  (* Fromm Oscat Library, www.oscat.de *)
END_FUNCTION

FUNCTION DWORD_OF_WORD : DWORD
  VAR_INPUT
    W0 : WORD;
    W1 : WORD;
  END_VAR

  DWORD_OF_WORD := SHL(WORD_TO_DWORD(W1),16) OR WORD_TO_DWORD(W0);

  (* Fromm Oscat Library, www.oscat.de *)
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

FUNCTION BIT_TOGGLE_W : WORD
  VAR_INPUT
    IN : WORD;
    POS : INT;
  END_VAR

  BIT_TOGGLE_W := SHL(WORD#1, POS) XOR IN;

  (*From OSCAT Library, www.oscat.de*)
END_FUNCTION

FUNCTION SHL1 : DWORD
  VAR_INPUT
    IN : DWORD;
    N : INT;
  END_VAR

  SHL1 := SHR(DWORD#16#FF_FF_FF_FF,32-N) OR SHL(IN,N);

  (* Fromm Oscat Library, www.oscat.de *)
END_FUNCTION

FUNCTION SWAP_BYTE : WORD
  VAR_INPUT
    IN : WORD;
  END_VAR

  Swap_Byte := ROL(in,8);

  (* Fromm Oscat Library, www.oscat.de *)
END_FUNCTION

FUNCTION BIT_LOAD_B2 : BYTE
  VAR_INPUT
    I : BYTE;
    _D : BOOL;
    P : INT;
    N : INT;
  END_VAR

  IF _D THEN
  	BIT_LOAD_B2 := ROL(SHR(BYTE#255, 8 - N) OR ROR(I, P), P);
  ELSE
  	BIT_LOAD_B2 := ROL(SHL(BYTE#255, N) AND ROR(I, P), P);
  END_IF;

  (*From OSCAT Library, www.oscat.de*)
END_FUNCTION

FUNCTION BCDC_TO_INT : INT
  VAR_INPUT
    IN : BYTE;
  END_VAR

  BCDC_TO_INT := _BYTE_TO_INT(in AND BYTE#16#0F) + (_BYTE_TO_INT(SHR(in,4)) * 10);

  (*From OSCAT Library, www.oscat.de*)
  (*_BYTE_TO_INT required*)
END_FUNCTION

FUNCTION BIT_LOAD_DW2 : DWORD
  VAR_INPUT
    I : DWORD;
    _D : BOOL;
    P : INT;
    N : INT;
  END_VAR

  IF _D THEN
  	BIT_LOAD_DW2 := ROL(SHR(DWORD#16#FFFFFFFF, 32 - N) OR ROR(I, P), P);
  ELSE
  	BIT_LOAD_DW2 := ROL(SHL(DWORD#16#FFFFFFFF, N) AND ROR(I, P), P);
  END_IF;

  (*From OSCAT Library, www.oscat.de*)
END_FUNCTION

FUNCTION BIT_TOGGLE_B : BYTE
  VAR_INPUT
    IN : BYTE;
    POS : INT;
  END_VAR

  BIT_TOGGLE_B := SHL(BYTE#1, POS) XOR IN;

  (*From OSCAT Library, www.oscat.de*)
END_FUNCTION


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
