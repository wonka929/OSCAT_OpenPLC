FUNCTION_BLOCK SHR_4UDE
  VAR_INPUT
    SET : BOOL;
    D0 : BOOL;
    D3 : BOOL;
    CLK : BOOL;
    DN : BOOL;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    Q0 : BOOL;
    Q1 : BOOL;
    Q2 : BOOL;
    Q3 : BOOL;
  END_VAR
  VAR
    trig : R_TRIG;
  END_VAR

  trig(clk := clk);

  IF set OR rst THEN
  	Q0 := NOT RST;
  	Q1 := Q0;
  	Q2 := Q0;
  	Q3 := Q0;
  ELSIF trig.Q THEN
  	IF dn THEN
  		Q0 := Q1;
  		Q1 := Q2;
  		Q2 := Q3;
  		Q3 := D3;
  	ELSE
  		Q3 := Q2;
  		Q2 := Q1;
  		Q1 := Q0;
  		Q0 := D0;
  	END_IF;
  END_IF;

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK SHR_4E
  VAR_INPUT
    SET : BOOL;
    D0 : BOOL;
    CLK : BOOL;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    Q0 : BOOL;
    Q1 : BOOL;
    Q2 : BOOL;
    Q3 : BOOL;
  END_VAR
  VAR
    trig : R_TRIG;
  END_VAR

  IF set OR rst THEN
  	Q0 := NOT RST;
  	Q1 := Q0;
  	Q2 := Q0;
  	Q3 := Q0;
  ELSIF trig.Q THEN
  	Q3 := Q2;
  	Q2 := Q1;
  	Q1 := Q0;
  	Q0 := D0;
  END_IF;

  (*From OSCAT Library, www.oscat.de *)
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

FUNCTION_BLOCK COUNT_DR
  VAR_INPUT
    SET : BOOL;
    IN : DWORD;
    UP : BOOL;
    DN : BOOL;
    _STEP : DWORD := 1;
    MX : DWORD := 16#FFFF_FFFF;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    CNT : DWORD;
  END_VAR
  VAR
    CNT2 : UDINT;
    STEP2 : UDINT;
    MX2 : UDINT;
    last_up : BOOL;
    last_dn : BOOL;
  END_VAR

  STEP2 := DWORD_TO_UDINT(_STEP);
  MX2   := DWORD_TO_UDINT(MX);
  CNT2  := DWORD_TO_UDINT(CNT);

  IF rst THEN
  	CNT2 := UDINT#0;
  ELSIF set THEN
  	CNT2 := LIMIT(UDINT#0,DWORD_TO_UDINT(in),mx2);
  ELSIF up AND NOT last_up THEN
  	IF STEP2 > MX2 - CNT2 THEN
  		CNT2 := CNT2 - MX2 + STEP2 - UDINT#1;
  	ELSE
  		CNT2 := CNT2 + STEP2;
  	END_IF;
  ELSIF dn AND NOT last_dn THEN
  	IF STEP2 > CNT2 THEN
  		CNT2 := CNT2 - STEP2 + MX2 + UDINT#1;
  	ELSE
  		CNT2 := CNT2 - STEP2;
  	END_IF;
  END_IF;
  last_up := up;
  last_dn := dn;

  CNT := UDINT_TO_DWORD(CNT2);

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION BIT_OF_DWORD : BOOL
  VAR_INPUT
    IN : DWORD;
    N : INT;
  END_VAR

  BIT_OF_DWORD := (SHR(in,N) AND 16#00000001) > 0;

  (* From Oscat Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK SHR_8PLE
  VAR_INPUT
    DIN : BOOL;
    DLOAD : BYTE;
    CLK : BOOL;
    UP : BOOL := TRUE;
    LOAD : BOOL;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    DOUT : BOOL;
  END_VAR
  VAR
    edge : BOOL := TRUE;
    register : BYTE;
  END_VAR

  IF CLK AND edge AND NOT rst THEN
  	edge := FALSE;	(* flanke wurde erkannt und weitere flankenerkennung wird verhindert bis edge wieder true ist *)
  	(* hier ist der code für das flankenevent *)
  	IF UP THEN						(*shift up *)
  		register := SHL(register,1);
          register := BIT_LOAD_B(register,Din,0);  (* register.X0 := Din; *)
          Dout     := BIT_OF_DWORD(BYTE_TO_DWORD(register),7);     (* Dout := register.X7; *)
  	ELSE						    (* shift down *)
  		register := SHR(register,1);
          register := BIT_LOAD_B(register,Din,7);  (* register.X7 := Din; *)
          Dout     := BIT_OF_DWORD(BYTE_TO_DWORD(register),0);     (* Dout := register.X0; *)
  	END_IF;
  	IF load THEN							(* the byte on Din will be loaded if load = true *)
  		register := Dload;
  		IF up THEN
              Dout := BIT_OF_DWORD(BYTE_TO_DWORD(register),7); (* register.X7 *)
          ELSE
              Dout := BIT_OF_DWORD(BYTE_TO_DWORD(register),0); (* register.X0 *)
          END_IF;
  	END_IF;
  END_IF;
  IF NOT clk THEN edge := TRUE; END_IF;	(* sobald clk wieder low wird warten auf nächste flanke *)
  IF rst THEN									(* wenn reset aktiv dann ausgang rücksetzen *)
  	register := BYTE#0;
  	Dout := FALSE;
  END_IF;

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK FF_DRE
  VAR_INPUT
    SET : BOOL;
    DI : BOOL;
    CLK : BOOL;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
  END_VAR
  VAR
    edge : BOOL;
  END_VAR

  IF rst OR set THEN
  	Q := NOT rst;
  ELSIF clk AND NOT edge THEN
  	Q := DI;
  END_IF;
  edge := CLK;

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION _BYTE_TO_INT : INT
  VAR_INPUT
    IN : BYTE;
  END_VAR

  _BYTE_TO_INT := USINT_TO_INT(BYTE_TO_USINT(IN));

  (*From OSCAT Library, www.oscat.de*)
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

FUNCTION_BLOCK COUNT_BR
  VAR_INPUT
    SET : BOOL;
    IN : BYTE;
    UP : BOOL;
    DN : BOOL;
    _STEP : BYTE := 1;
    MX : BYTE := 255;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    CNT : BYTE;
  END_VAR
  VAR
    last_up : BOOL;
    last_dn : BOOL;
  END_VAR

  IF rst THEN
  	cnt := BYTE#0;
  ELSIF set THEN
  	cnt := INT_TO_BYTE(LIMIT(0,_BYTE_TO_INT(in),_BYTE_TO_INT(mx)));
  ELSIF up AND NOT last_up THEN
  	cnt := INT_TO_BYTE(inc(_BYTE_TO_INT(cnt),_BYTE_TO_INT(_step),_BYTE_TO_INT(mx)));
  ELSIF dn AND NOT last_dn THEN
  	cnt := INT_TO_BYTE(inc(_BYTE_TO_INT(cnt),_BYTE_TO_INT(_step) * -1,_BYTE_TO_INT(mx)));
  END_IF;
  last_up := up;
  last_dn := dn;

  (*From OSCAT Library, www.oscat.de *)
  (* _BYTE_TO_INT, INC required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK FF_JKE
  VAR_INPUT
    SET : BOOL;
    J : BOOL;
    CLK : BOOL;
    K : BOOL;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
  END_VAR
  VAR
    edge : BOOL;
  END_VAR

  IF rst OR set THEN
  	Q := NOT rst;
  ELSIF clk AND NOT edge THEN
  	IF J XOR K THEN Q := J;
  	ELSE Q := K XOR Q;
  	END_IF;
  END_IF;
  edge := CLK;

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK SELECT_8
  VAR_INPUT
    EI : BOOL;
    SET : BOOL;
    IN : BYTE;
    UP : BOOL;
    DN : BOOL;
    RST : BOOL;
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
    state : INT;
  END_VAR
  VAR
    last_up : BOOL;
    last_dn : BOOL;
  END_VAR

  IF rst THEN
  	state := 0;
  ELSIF set THEN
  	state := _BYTE_TO_INT(IN);
  ELSIF up AND NOT last_up THEN
  	state := inc(state,1,7);
  ELSIF dn AND NOT last_dn THEN
  	state := inc(state,-1,7);
  END_IF;
  last_UP := UP;
  last_DN := DN;

  Q0 := FALSE;
  Q1 := FALSE;
  Q2 := FALSE;
  Q3 := FALSE;
  Q4 := FALSE;
  Q5 := FALSE;
  Q6 := FALSE;
  Q7 := FALSE;

  IF ei THEN
  	CASE state OF
  		0: Q0 := TRUE;
  		1: Q1 := TRUE;
  		2: Q2 := TRUE;
  		3: Q3 := TRUE;
  		4: Q4 := TRUE;
  		5: Q5 := TRUE;
  		6: Q6 := TRUE;
  		7: Q7 := TRUE;
  	END_CASE;
  END_IF;

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK TOGGLE
  VAR_INPUT
    CLK : BOOL;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
  END_VAR
  VAR
    edge : BOOL;
  END_VAR

  IF rst THEN
  	Q := FALSE;
  ELSIF clk AND NOT edge THEN
  	Q := NOT Q;
  END_IF;
  edge := clk;

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK LTCH
  VAR_INPUT
    DI : BOOL;
    L : BOOL;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
  END_VAR

  IF rst THEN				(* if asynchronous reset then Q=0 *)
  	Q := FALSE;
  ELSIF L THEN			(* latch is transparent *)
  	Q := DI;
  END_IF;

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK FF_RSE
  VAR_INPUT
    CS : BOOL;
    CR : BOOL;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
  END_VAR
  VAR
    es : BOOL;
    er : BOOL;
  END_VAR

  IF rst THEN
  	(* asynchronous reset *)
  	Q := FALSE;
  ELSIF CR AND NOT er THEN
  	(* rising edge on CR *)
  	Q := FALSE;
  ELSIF CS AND NOT es THEN
  	(* rising edge on CS *)
  	Q := TRUE;
  END_IF;

  es := CS;
  er := CR;

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK LTCH_4
  VAR_INPUT
    D0 : BOOL;
    D1 : BOOL;
    D2 : BOOL;
    D3 : BOOL;
    L : BOOL;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    Q0 : BOOL;
    Q1 : BOOL;
    Q2 : BOOL;
    Q3 : BOOL;
  END_VAR

  IF rst THEN			(* if asynchronous reset then Q=0 *)
  	Q0 := FALSE;
  	Q1 := FALSE;
  	Q2 := FALSE;
  	Q3 := FALSE;
  ELSIF L THEN			(* latch is transparent *)
  	Q0 := D0;
  	Q1 := D1;
  	Q2 := D2;
  	Q3 := D3;
  END_IF;

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK STORE_8
  VAR_INPUT
    SET : BOOL;
    D0 : BOOL;
    D1 : BOOL;
    D2 : BOOL;
    D3 : BOOL;
    D4 : BOOL;
    D5 : BOOL;
    D6 : BOOL;
    D7 : BOOL;
    CLR : BOOL;
    RST : BOOL;
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
    edge : BOOL;
  END_VAR

  IF rst OR set THEN
  	q0 := NOT rst;
  	q1 := q0;
  	q2 := q0;
  	q3 := q0;
  	q4 := q0;
  	q5 := q0;
  	q6 := q0;
  	q7 := q0;
  ELSE
  	IF D0 THEN Q0 := TRUE; END_IF;
  	IF D1 THEN Q1 := TRUE; END_IF;
  	IF D2 THEN Q2 := TRUE; END_IF;
  	IF D3 THEN Q3 := TRUE; END_IF;
  	IF D4 THEN Q4 := TRUE; END_IF;
  	IF D5 THEN Q5 := TRUE; END_IF;
  	IF D6 THEN Q6 := TRUE; END_IF;
  	IF D7 THEN Q7 := TRUE; END_IF;

  	IF clr AND NOT edge THEN
  		IF q0 THEN q0 := FALSE;
  		ELSIF q1 THEN q1 := FALSE;
  		ELSIF q2 THEN q2 := FALSE;
  		ELSIF q3 THEN q3 := FALSE;
  		ELSIF q4 THEN q4 := FALSE;
  		ELSIF q5 THEN q5 := FALSE;
  		ELSIF q6 THEN q6 := FALSE;
  		ELSE q7 := FALSE;
  		END_IF;
  	END_IF;
  	edge := clr;
  END_IF;

  (*From OSCAT Library, www.oscat.de *
END_FUNCTION_BLOCK

FUNCTION_BLOCK SHR_8UDE
  VAR_INPUT
    SET : BOOL;
    D0 : BOOL;
    D7 : BOOL;
    CLK : BOOL;
    DN : BOOL;
    RST : BOOL;
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
    trig : R_TRIG;
  END_VAR

  trig(clk := clk);

  IF set OR rst THEN
  	Q0 := NOT RST;
  	Q1 := Q0;
  	Q2 := Q0;
  	Q3 := Q0;
  	Q4 := Q0;
  	Q5 := Q0;
  	Q6 := Q0;
  	Q7 := Q0;
  ELSIF trig.Q THEN
  	IF dn THEN
  		Q0 := Q1;
  		Q1 := Q2;
  		Q2 := Q3;
  		Q3 := Q4;
  		Q4 := Q5;
  		Q5 := Q6;
  		Q6 := Q7;
  		Q7 := D7;
  	ELSE
  		Q7 := Q6;
  		Q6 := Q5;
  		Q5 := Q4;
  		Q4 := Q3;
  		Q3 := Q2;
  		Q2 := Q1;
  		Q1 := Q0;
  		Q0 := D0;
  	END_IF;
  END_IF;

  (*From OSCAT Library, www.oscat.de *
END_FUNCTION_BLOCK

FUNCTION_BLOCK FF_D2E
  VAR_INPUT
    D0 : BOOL;
    D1 : BOOL;
    CLK : BOOL;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    Q0 : BOOL;
    Q1 : BOOL;
  END_VAR
  VAR
    edge : BOOL;
  END_VAR

  IF rst THEN
  	Q0 := FALSE;
  	Q1 := FALSE;
  ELSIF clk AND NOT edge THEN
  	Q0 := D0;
  	Q1 := D1;
  END_IF;
  edge := CLK;

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK FF_D4E
  VAR_INPUT
    D0 : BOOL;
    D1 : BOOL;
    D2 : BOOL;
    D3 : BOOL;
    CLK : BOOL;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    Q0 : BOOL;
    Q1 : BOOL;
    Q2 : BOOL;
    Q3 : BOOL;
  END_VAR
  VAR
    edge : BOOL;
  END_VAR

  IF rst THEN
  	Q0 := FALSE;
  	Q1 := FALSE;
  	Q2 := FALSE;
  	Q3 := FALSE;
  ELSIF clk AND NOT edge THEN
  	Q0 := D0;
  	Q1 := D1;
  	Q2 := D2;
  	Q3 := D3;
  END_IF;
  edge := CLK;

  (*From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
