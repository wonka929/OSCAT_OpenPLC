FUNCTION KMH_TO_MS : REAL
  VAR_INPUT
    KMH : REAL;
  END_VAR

  KMH_TO_MS := kmh * 0.2777777777777;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION BFT_TO_MS : REAL
  VAR_INPUT
    BfT : INT;
  END_VAR

  BFT_TO_MS := EXPT(INT_TO_REAL(BFT), 1.5) * 0.836;

  (* From OSCAT Library, www.oscat.de *)
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

FUNCTION C_TO_K : REAL
  VAR_INPUT
    CELSIUS : REAL;
  END_VAR

  C_to_K := Celsius - 273.15;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION F_TO_PT : TIME
  VAR_INPUT
    F : REAL;
  END_VAR

  F_TO_PT := DWORD_TO_TIME(REAL_TO_DWORD(1.0 / F * 1000.0));

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK PRESSURE
  VAR_INPUT
    MWS : REAL;
    TORR : REAL;
    ATT : REAL;
    ATM : REAL;
    PA : REAL;
    BAR : REAL;
  END_VAR
  VAR_OUTPUT
    YMWS : REAL;
    YTORR : REAL;
    YATT : REAL;
    YATM : REAL;
    YPA : REAL;
    YBAR : REAL;
  END_VAR

  Ybar := bar +
  		pa * 1.0E-5 +
  		0.980665 * att +
  		1.01325 * atm +
  		0.001333224 * torr +
  		0.0980665 * mws;
  Ymws := ybar * 10.1971621297793;
  Ytorr := ybar * 750.0615050434140;
  Yatt := ybar * 1.0197162129779;
  yatm := ybar * 0.9869232667160;
  Ypa := ybar * 100000.0;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION C_TO_F : REAL
  VAR_INPUT
    CELSIUS : REAL;
  END_VAR

  C_TO_F := celsius * 1.8 + 32.0;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK ENERGY
  VAR_INPUT
    J : REAL;
    C : REAL;
    WH : REAL;
  END_VAR
  VAR_OUTPUT
    YJ : REAL;
    YC : REAL;
    YWH : REAL;
  END_VAR

  YJ := J + Wh * 3600.0 + C * 4.1868;
  YC := YJ * 0.238845896627496;
  YWh := YJ * 2.7777777778E-004;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION F_TO_OM : REAL
  VAR_INPUT
    F : REAL;
  END_VAR

  F_to_OM := 6.283185307179586476 * F;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK ASTRO
  VAR_INPUT
    M : REAL;
    AE : REAL;
    PC : REAL;
    LJ : REAL;
  END_VAR
  VAR_OUTPUT
    YM : REAL;
    YAE : REAL;
    YPC : REAL;
    YLJ : REAL;
  END_VAR

  YAE :=	AE
  		+ m * 6.6845871535E-012
  		+ PC * 206265.0
  		+ LJ * 63240.0;
  Ym := YAE * 149.597870E9;
  YPC := YAE * 4.8481322570E-006;
  YLJ := YAE * 1.5812776724E-005;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION_BLOCK LENGTH
  VAR_INPUT
    M : REAL;
    P : REAL;
    IN : REAL;
    FT : REAL;
    YD : REAL;
    MILE : REAL;
    SM : REAL;
    FM : REAL;
  END_VAR
  VAR_OUTPUT
    YM : REAL;
    YP : REAL;
    YIN : REAL;
    YFT : REAL;
    YYD : REAL;
    YMILE : REAL;
    YSM : REAL;
    YFM : REAL;
  END_VAR

  Ym :=	m
  		+ p * 0.000376065
  		+ in * 0.0254
  		+ ft * 0.3048
  		+ yd * 0.9144
  		+ mile * 1609.344
  		+ sm * 1852.0
  		+ fm * 1.829;
  Yp := Ym * 2659.11478068951;
  Yin := Ym * 39.37007874016;
  Yft := Ym * 3.28083989501;
  Yyd := Ym * 1.09361329834;
  Ymile := Ym * 0.00062137119;
  Ysm := Ym * 0.00053995680;
  Yfm := Ym * 0.54674685621;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION F_TO_C : REAL
  VAR_INPUT
    FAHRENHEIT : REAL;
  END_VAR

  F_TO_C := (fahrenheit - 32.0) * 0.5555555555555;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION MS_TO_KMH : REAL
  VAR_INPUT
    MS : REAL;
  END_VAR

  MS_TO_KMH := ms * 3.6;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION K_TO_C : REAL
  VAR_INPUT
    KELVIN : REAL;
  END_VAR

  K_to_C := Kelvin + 273.15;


  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION OM_TO_F : REAL
  VAR_INPUT
    OM : REAL;
  END_VAR

  OM_to_F := OM / 6.283185307179586476;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION MS_TO_BFT : INT
  VAR_INPUT
    MS : REAL;
  END_VAR

  MS_TO_BFT := REAL_TO_INT(EXPT(MS * 1.196172, 0.666667));

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION PT_TO_F : REAL
  VAR_INPUT
    PT : TIME;
  END_VAR

  PT_TO_F := 1000.0 / DWORD_TO_REAL(TIME_TO_DWORD(PT));

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK SPEED
  VAR_INPUT
    MS : REAL;
    KMH : REAL;
    KN : REAL;
    MH : REAL;
  END_VAR
  VAR_OUTPUT
    YMS : REAL;
    YKMH : REAL;
    YKN : REAL;
    YMH : REAL;
  END_VAR

  Yms := ms +
  		kmh * 0.27777777777778 +
  		kn * 0.5144444 +
  		mh * 0.44704;
  Ykmh := Yms * 3.6;
  Ykn := Yms * 1.94384466037535;
  Ymh := Yms * 2.23693629205440;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK

FUNCTION GEO_TO_DEG : REAL
  VAR_INPUT
    _D : INT;
    M : INT;
    SEC : REAL;
  END_VAR

  GEO_TO_DEG := INT_TO_REAL(_D) + INT_TO_REAL(M) * 0.016666666666667 + sec * 0.00027777777777778;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION

FUNCTION_BLOCK TEMPERATURE
  VAR_INPUT
    K : REAL;
    C : REAL := -273.15;
    F : REAL := -459.67;
    RE : REAL := -218.52;
    RA : REAL := 0.0;
  END_VAR
  VAR_OUTPUT
    YK : REAL;
    YC : REAL;
    YF : REAL;
    YRE : REAL;
    YRA : REAL;
  END_VAR

  YK := K + (C + 273.15) + (F + 459.67) * 0.555555555555 + (Re * 1.25 + 273.15) + (Ra * 0.555555555555);
  YC := YK -273.15;
  YF := YK * 1.8 - 459.67;
  YRe := (YK - 273.15) * 0.8;
  YRa := YK * 1.8;

  (* From OSCAT Library, www.oscat.de *)
END_FUNCTION_BLOCK


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
