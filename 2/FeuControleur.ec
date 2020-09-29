node FeuControleur
  (TD: bool;
  TI: bool;
  CP: bool;
  AB: bool;
  LP: bool)
returns
  (veilleuses: bool;
  codes: bool;
  phares: bool;
  anti_brouillard: bool;
  longue_portee: bool);

var
  V12_stepT: int;
  V13_stepC: bool;
  V14_isAB: bool;
  V15_isLP: bool;

let
  veilleuses = (if (V12_stepT = 1) then true else false);
  codes = (if ((V12_stepT = 2) and V13_stepC) then true else false);
  phares = (if ((V12_stepT = 2) and (not V13_stepC)) then true else false);
  anti_brouillard = (V14_isAB and codes);
  longue_portee = (V15_isLP and phares);
  V12_stepT = (0 -> (if (TD and ((pre V12_stepT) < 2)) then ((pre V12_stepT) + 
  1) else (if (TI and ((pre V12_stepT) > 0)) then ((pre V12_stepT) - 1) else 
  (pre V12_stepT))));
  V13_stepC = (true -> (if CP then (not (pre V13_stepC)) else (pre V13_stepC)))
  ;
  V14_isAB = (false -> (if AB then (not (pre V14_isAB)) else (pre V14_isAB)));
  V15_isLP = (false -> (if LP then (not (pre V15_isLP)) else (pre V15_isLP)));
tel

