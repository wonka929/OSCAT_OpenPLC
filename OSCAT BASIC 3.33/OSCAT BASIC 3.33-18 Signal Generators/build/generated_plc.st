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

FUNCTION_BLOCK GEN_RDT
  VAR_INPUT
    ENABLE : BOOL := TRUE;
    MIN_TIME_MS : TIME := t#1s;
    MAX_TIME_MS : TIME := t#1.2s;
    TP_Q : TIME := t#100ms;
  END_VAR
  VAR_OUTPUT
    XQ : BOOL;
  END_VAR
  VAR
    tonRDMTimer : TON;
    tof_xQ : TOF;
    tRDMTime : TIME;
    rRDMTime : REAL;
    rdm_1 : RDM;
  END_VAR

  tonRDMTimer(IN:=Enable,PT:=tRDMTime);
  tof_xQ(IN := tonRDMTimer.Q,PT:=TP_Q);
  XQ := tof_xq.Q;
  IF tonRDMTimer.Q THEN
  	xQ := TRUE ;
      rdm_1(last:=rRDMTime);
      rRDMTime:= rdm_1._RDM;

  	tRDMTime := REAL_TO_TIME(rRDMTime * TIME_TO_REAL(Max_Time_ms - Min_Time_ms) + TIME_TO_REAL(Min_Time_ms));
  	tonRDMTimer (IN:=FALSE);
  END_IF;


  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK TP_X
  VAR_INPUT
    IN : BOOL;
    PT : TIME;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
    ET : TIME;
  END_VAR
  VAR
    edge : BOOL;
    start : TIME;
    tx : TIME;
  END_VAR

  tx := UDINT_TO_TIME(T_PLC_MS(en:=true));

  (* rising edge trigger *)
  IF IN AND NOT edge THEN
  	start := tx;
  	Q := PT > t#0ms;
  ELSIF Q THEN
  	ET := tx - start;
  	IF ET >= PT THEN
  		Q := FALSE;
  		ET := t#0ms;
  	END_IF;
  END_IF;
  edge := IN;

  (*From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS required *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK CLK_PRG
  VAR_INPUT
    PT : TIME := T#10ms;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
  END_VAR
  VAR
    init : BOOL := FALSE;
    last : TIME;
    tx : TIME;
  END_VAR


  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));

  (* initialize on startup *)
  IF NOT init THEN
  	init := TRUE;
  	last := tx - pt;
  END_IF;

  (* generate output pulse when next_pulse is reached *)
  Q := tx - last >= pt;
  IF Q THEN last := tx; END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK PWM_PW
  VAR_INPUT
    F : REAL;
    PW : TIME;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
  END_VAR
  VAR
    clk : CLK_PRG;
    pulse : TP_X;
  END_VAR

  IF F > 0.0 THEN
  	CLK(PT := REAL_TO_TIME(1000.0 / F));
  	Pulse(in := clk.Q, pt := pw);
  	Q := pulse.Q;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS, CLK_PRG, TP_X required*)
END_FUNCTION_BLOCK

FUNCTION_BLOCK GEN_RDM
  VAR_INPUT
    PT : TIME;
    AM : REAL := 1.0;
    OS : REAL;
    Q : BOOL;
    OUT : REAL;
  END_VAR
  VAR
    tx : TIME;
    last : TIME;
    init : BOOL;
    FB_rdm : RDM;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true)) - last;

  (* init section *)
  IF NOT init THEN
  	init := TRUE;
  	last := tx;
  	tx := t#0s;
  END_IF;

  (* add last if one cycle is finished *)
  IF tx >= pt THEN
  	last := last + pt;
  	tx := tx - pt;

  	(* generate output signal *)
      FB_rdm(last:=0.0);
  	out := am * (FB_rdm._RDM - 0.5) + os;
  	q := TRUE;
  ELSE
  	q := FALSE;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS, BIT_COUNT, BIT_LOAD_DW, RDM, BIT_OF_DWORD, FRACT, D_TRUNC required*)
END_FUNCTION_BLOCK

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
    LocalVar0 : DINT;
    LocalVar1 : DINT;
    LocalVar2 : DINT;
    ADD1_OUT : DINT;
  END_VAR

  ADD1_OUT := ADD(LocalVar0, LocalVar1);
  LocalVar2 := ADD1_OUT;
END_PROGRAM

FUNCTION _WORD_TO_DINT : DINT
  VAR_INPUT
    IN : WORD;
  END_VAR

  _WORD_TO_DINT := UINT_TO_DINT(WORD_TO_UINT(IN));

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK _RMP_W
  VAR_INPUT
    DIR : BOOL;
    _E : BOOL := TRUE;
    TR : TIME;
  END_VAR
  VAR_IN_OUT
    RMP : WORD;
  END_VAR
  VAR
    tx : UDINT;
    tl : UDINT;
    _step : DINT;
    init : BOOL;
    last_dir : BOOL;
  END_VAR

  tx := T_PLC_MS(en:=true);
  IF _E AND init THEN
  	(* we need to set tl = tx when direction changes *)
  	IF dir XOR last_dir THEN
  	 tl := tx;
  	 last_dir := dir;
  	END_IF;
  	(* check_elapsed time and calculate only if necessary *)
  	IF tr > t#0s THEN
  		_step := DWORD_TO_DINT(UDINT_TO_DWORD(DWORD_TO_UDINT(SHL(UDINT_TO_DWORD(tx-tl), 16)) / TIME_TO_UDINT(TR)));
  	ELSE
  		_step := DINT#65535;
  	END_IF;
  	IF _step > DINT#0 THEN
  		(* perform the step on the ramp *)
  		tl := tx;
  		(* calculate the step response *)
  		IF NOT dir THEN _step := - _step; END_IF;
  		rmp := DINT_TO_WORD(LIMIT(DINT#0, _WORD_TO_DINT(rmp) + _step, DINT#65535));
  	END_IF;
  ELSE
  	tl := tx;
  	init := TRUE;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS required, _WORD_TO_DINT required*)
END_FUNCTION_BLOCK

FUNCTION_BLOCK RMP_W
  VAR_INPUT
    SET : BOOL;
    PT : TIME;
    _E : BOOL := TRUE;
    UP : BOOL := TRUE;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    OUT : WORD;
    BUSY : BOOL;
    HIGH : BOOL;
    LOW : BOOL;
  END_VAR
  VAR
    rmp : _RMP_W;
  END_VAR

  rmp(dir := UP, _E := _E, TR := PT, rmp := out);
  out := rmp.RMP;

  (* set or reset operation *)
  IF RST THEN
  	out := WORD#0;
  ELSIF SET THEN
  	out := WORD#65535;
  END_IF;

  (* checks for outputs stable and reset or set busy flag *)
  low := out = WORD#0;
  high := out = WORD#65535;
  busy := NOT (low OR high) AND _E;
END_FUNCTION_BLOCK

FUNCTION FRMP_B : BYTE
  VAR_INPUT
    START : BYTE;
    DIR : BOOL;
    TD : TIME;
    TR : TIME;
  END_VAR

  IF TD < TR THEN
  	FRMP_B := MIN(UDINT_TO_BYTE(DWORD_TO_UDINT(SHL(TIME_TO_DWORD(TD), 8)) / TIME_TO_UDINT(TR)), SEL(DIR, START, USINT_TO_BYTE(USINT#255 - BYTE_TO_USINT(START))));
  	IF DIR THEN
  		FRMP_B := USINT_TO_BYTE(BYTE_TO_USINT(START) + BYTE_TO_USINT(FRMP_B));
  	ELSE
  		FRMP_B := USINT_TO_BYTE(BYTE_TO_USINT(START) - BYTE_TO_USINT(FRMP_B));
  	END_IF;
  ELSE
  	FRMP_B := SEL(DIR, BYTE#0, BYTE#255);
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION SIGN_R : BOOL
  VAR_INPUT
    IN : REAL;
  END_VAR

  SIGN_R := in < 0.0;
  (* from OSCAT library; www.oscat.de  *)
END_FUNCTION

FUNCTION_BLOCK _RMP_B
  VAR_INPUT
    DIR : BOOL;
    _E : BOOL := TRUE;
    TR : TIME;
  END_VAR
  VAR_IN_OUT
    RMP : BYTE;
  END_VAR
  VAR
    tx : TIME;
    tl : TIME;
    tn : TIME;
    init : BOOL;
    last_dir : BOOL;
    start : BYTE;
  END_VAR

  tx := UDINT_TO_TIME(T_PLC_MS(en:=true));

  IF _E AND init AND (dir = last_dir) AND (RMP <> SEL(DIR, BYTE#0, BYTE#255)) AND TR = tn THEN
  	RMP := FRMP_B(start, DIR, tx - tl, TR);
  ELSE
  	init := TRUE;
  	tl := tx;
  	tn := tr;
  	start := RMP;
  END_IF;
  last_dir := dir;

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS requires *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK RMP_B
  VAR_INPUT
    SET : BOOL;
    PT : TIME;
    _E : BOOL := TRUE;
    UP : BOOL := TRUE;
    RST : BOOL;
  END_VAR
  VAR_OUTPUT
    OUT : BYTE;
    BUSY : BOOL;
    HIGH : BOOL;
    LOW : BOOL;
  END_VAR
  VAR
    rmp : _RMP_B;
  END_VAR

  rmp(dir := UP, _E := _E, TR := PT, RMP := out);
  out := rmp.RMP;

  (* set or reset operation *)
  IF RST THEN
  	out := BYTE#0;
  ELSIF SET THEN
  	out := BYTE#255;
  END_IF;

  (* checks for outputs stable and reset or set busy flag *)
  low := out = BYTE#0;
  high := out = BYTE#255;
  busy := NOT (low OR high) AND _E;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK GEN_SQR
  VAR_INPUT
    PT : TIME;
    AM : REAL := 1.0;
    OS : REAL;
    DL : REAL;
    DC : REAL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
    OUT : REAL;
  END_VAR
  VAR
    tx : TIME;
    last : TIME;
    init : BOOL;
  END_VAR

  IF dc = 0.0 THEN
  	out := -am * 0.5 + os;
  	Q := FALSE;
  	RETURN;
  ELSIF dc = 1.0 THEN
  	out := am * 0.5 + os;
  	Q := TRUE;
  	RETURN;
  END_IF;

  (* read system time and prepare input data *)
  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true)) - last;
  DL := modR(dl,1.0);
  IF dl < 0.0 THEN dl := 1.0 - dl; END_IF;
  dc := modR(dc,1.0);
  IF dc < 0.0 THEN dc := 1.0 - dc; END_IF;

  (* init section *)
  IF NOT init THEN
  	init := TRUE;
  	last := tx;
  	tx := t#0s;
  END_IF;

  (* add last if one cycle is finished *)
  IF tx >= pt THEN
  	last := last + pt;
  	tx := tx - pt;
  END_IF;

  (* check if falling or rising edge first *)
  IF multime(pt, dl + dc) >= pt THEN
  	(* generate falling edge *)
  	IF tx >= multime(pt, dl + dc - 1.0) THEN
  		out := -am * 0.5 + os;
  		Q := FALSE;
  	END_IF;
  	(* generate rising edge *)
  	IF tx >= multime(pt, dl) THEN
  		out := am * 0.5 + os;
  		Q := TRUE;
  	END_IF;
  ELSE
  	(* generate rising edge first *)
  	IF tx >= multime(pt, dl) THEN
  		out := am * 0.5 + os;
  		Q := TRUE;
  	END_IF;
  	(* generate falling edge *)
  	IF tx >= multime(pt, dl + dc) THEN
  		out := -am * 0.5 +os;
  		Q := FALSE;
  	END_IF;
  END_IF;


  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS, required*)
END_FUNCTION_BLOCK

FUNCTION_BLOCK TREND_DW
  VAR_INPUT
    X : DWORD;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
    TU : BOOL;
    TD : BOOL;
    _D : DWORD;
  END_VAR
  VAR
    last_x : DWORD;
  END_VAR

  IF X > last_X THEN
  	TU := TRUE;
  	TD := FALSE;
  	_D := UDINT_TO_DWORD(DWORD_TO_UDINT(X) - DWORD_TO_UDINT(last_X));
  	Q := TRUE;
  ELSIF X < last_X THEN
  	TD := TRUE;
  	TU := FALSE;
  	_D := UDINT_TO_DWORD(DWORD_TO_UDINT(last_X) - DWORD_TO_UDINT(X));
  	Q := FALSE;
  ELSE
  	TU := FALSE;
  	TD := FALSE;
  	_D := DWORD#0;
  END_IF;
  last_X := X;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK _RMP_NEXT
  VAR_INPUT
    _E : BOOL := TRUE;
    IN : BYTE;
    TR : TIME;
    TF : TIME;
    TL : TIME;
  END_VAR
  VAR_OUTPUT
    DIR : BOOL;
    UP : BOOL;
    DN : BOOL;
  END_VAR
  VAR_IN_OUT
    OUT : BYTE;
  END_VAR
  VAR
    rmx : _RMP_B;
    dirx : TREND_DW;
    t_lock : TP;
    xen : BOOL;
    xdir : BOOL;
  END_VAR

  dirx(X := BYTE_TO_DWORD(in));

  t_lock(in := FALSE, pt := TL);

  IF dirx.TU AND (OUT < IN) THEN
  	IF NOT xdir AND xen THEN t_lock(in := TRUE); END_IF;
  	xen := TRUE;
  	xdir := TRUE;
  ELSIF dirx.TD AND (OUT > IN) THEN
  	IF xdir AND xen THEN t_lock(in := TRUE); END_IF;
  	xen := TRUE;
  	xdir := FALSE;
  ELSIF xen THEN
  	IF (xdir AND (out >= in)) OR (NOT xdir AND (out <= in)) THEN
  		xen := FALSE;
  		IF tl > t#0s THEN t_lock(IN := TRUE); END_IF;
  	END_IF;
  END_IF;

  IF NOT t_lock.Q AND xen THEN
  	UP := XDIR;
  	DIR := XDIR;
  	DN := NOT XDIR;
  ELSE
  	UP := FALSE;
  	DN := FALSE;
  END_IF;

  rmx(rmp := OUT, _E := _E AND (UP OR DN) , dir := DIR, tr := SEL(dir, TF, TR));
  OUT := rmx.RMP;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK GEN_PW2
  VAR_INPUT
    ENQ : BOOL;
    TH1 : TIME;
    TH2 : TIME;
    TL1 : TIME;
    TL2 : TIME;
    TS : BOOL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
    TH : TIME;
    TL : TIME;
  END_VAR
  VAR
    t_high : TIME;
    t_low : TIME;
    tx : TIME;
    start : TIME;
    et : TIME;
    init : BOOL;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));

  (* startup initialization *)
  IF NOT init THEN
  	start := tx;
  	init := TRUE;
  	TH := T#0s;
  	TL := T#0s;
  END_IF;

  (* timing selection *)
  IF TS THEN
  	t_high := TH2;
  	t_low := TL2;
  ELSE
  	t_high := TH1;
  	t_low := TL1;
  END_IF;

  (* normal operation *)
  IF ENQ THEN
  	et := tx - start;
  	IF NOT Q THEN
  		IF et >= t_low THEN
  			Q := TRUE;
  			start := tx;
  			TL := T#0s;
  		ELSE
  			TL := et;
  		END_IF;
  	ELSE
  		IF et >= t_high THEN
  			Q := FALSE;
  			start := tx;
  			TH := T#0s;
  		ELSE
  			TH := et;
  		END_IF;
  	END_IF;
  ELSE
  	Q := FALSE;
  	TH := T#0s;
  	TL := T#0s;
  	start := tx;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS required*)
END_FUNCTION_BLOCK

FUNCTION_BLOCK RMP_SOFT
  VAR_INPUT
    IN : BOOL;
    VAL : BYTE;
    PT_ON : TIME := t#100ms;
    PT_OFF : TIME := t#100ms;
  END_VAR
  VAR_OUTPUT
    OUT : BYTE;
  END_VAR
  VAR
    rmp : _RMP_B;
    tmp : BYTE;
  END_VAR

  tmp := SEL(in, BYTE#0, val);
  IF tmp > out THEN
  	(* we need to ramp down *)
  	rmp(dir := TRUE, _E := TRUE, TR := PT_ON, RMP := out);
  	out := rmp.RMP; 
  	(* make sure out does not surpass tmp *)
  	out := MIN(out, tmp);
  ELSIF tmp < out THEN
  	(* we need to ramp up *)
  	rmp(dir := FALSE, _E := TRUE, TR := PT_OFF, RMP := out);
  	out := rmp.RMP; 
  	(* make sure out does not surpass tmp *)
  	out := MAX(out, tmp);
  ELSE
  	(* no ramp necessary *)
  	rmp(_E := FALSE, RMP := out);
  	out := rmp.RMP; 
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK GEN_PULSE
  VAR_INPUT
    ENQ : BOOL := TRUE;
    PTH : TIME;
    PTL : TIME;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
  END_VAR
  VAR
    tx : TIME;
    tn : TIME;
    init : BOOL;
  END_VAR

  IF enq THEN
  		tx:= UDINT_TO_TIME(T_PLC_MS(en:=true));
  	IF NOT init THEN init := TRUE; tn := tx; END_IF;
  	IF tx - tn >= SEL(Q, PTL, PTH) THEN
  		tn := tn + SEL(Q, PTL, PTH);
  		Q := NOT Q;
  	END_IF;
  ELSE
  	Q := FALSE;
  	init := FALSE;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS required*)
END_FUNCTION_BLOCK

FUNCTION_BLOCK PWM_DC
  VAR_INPUT
    F : REAL;
    DC : REAL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
  END_VAR
  VAR
    clk : CLK_PRG;
    pulse : TP_X;
    tmp : REAL;
  END_VAR

  IF F > 0.0 THEN
  	tmp := 1000.0/F;
  	CLK(PT := REAL_TO_TIME(tmp));
  	Pulse(in := clk.Q, pt := REAL_TO_TIME(tmp*DC));
  	Q := pulse.Q;
  END_IF;

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS, CLK_PRG, TP_X required*)
END_FUNCTION_BLOCK

FUNCTION_BLOCK GEN_RMP
  VAR_INPUT
    PT : TIME := t#1s;
    AM : REAL := 1.0;
    OS : REAL;
    DL : REAL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
    OUT : REAL;
  END_VAR
  VAR
    tx : TIME;
    last : TIME;
    init : BOOL;
    temp : REAL;
    ltemp : REAL;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true)) - last;
  DL := modR(dl,1.0);
  IF dl < 0.0 THEN dl := 1.0 - dl; END_IF;

  (* init section *)
  IF NOT init THEN
  	init := TRUE;
  	last := tx;
  	tx := t#0s;
  END_IF;

  (* add last if one cycle is finished *)
  IF tx >= pt THEN
  	last := last + pt;
  	tx := tx - pt;
  END_IF;

  (* generate sine wave *)
  ltemp := temp;
  IF pt > t#0s THEN temp := fract(TIME_TO_REAL(tx + multime(pt, dl)) / TIME_TO_REAL(pt)); END_IF;
  out := am * temp + os;

  (* boolean output Q *)
  Q := temp < ltemp;

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS, MODR, FRACT2 required*)
END_FUNCTION_BLOCK

FUNCTION_BLOCK GEN_SIN
  VAR_INPUT
    PT : TIME;
    AM : REAL := 1.0;
    OS : REAL;
    DL : REAL;
  END_VAR
  VAR_OUTPUT
    Q : BOOL;
    OUT : REAL;
  END_VAR
  VAR
    tx : TIME;
    last : TIME;
    init : BOOL;
    temp : REAL;
  END_VAR

  tx:= UDINT_TO_TIME(T_PLC_MS(en:=true)) - last;

  DL := modR(dl,1.0);
  IF dl < 0.0 THEN dl := 1.0 - dl; END_IF;

  (* init section *)
  IF NOT init THEN
  	init := TRUE;
  	last := tx;
  	tx := t#0s;
  END_IF;

  (* add last if one cycle is finished *)
  IF tx >= pt THEN
  	last := last + pt;
  	tx := tx - pt;
  END_IF;

  (* generate sine wave *)
  IF pt > t#0s THEN temp := SIN(6.283185307179586476 * TIME_TO_REAL(tx + multime(pt, dl)) / TIME_TO_REAL(pt)); END_IF;
  out := am * 0.5 *  temp + os;

  (* boolean output Q *)
  q := NOT sign_R(temp);

  (* From OSCAT Library, www.oscat.de *)
  (* T_PLC_MS, SIGN_R required*)
END_FUNCTION_BLOCK


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
