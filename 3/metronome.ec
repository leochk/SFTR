node metronome
  (reset: bool;
  delay: int)
returns
  (tic: bool;
  tac: bool);

var
  V6_hz: int;
  V7_n: int;
  V8_first: bool;
  V9_state: bool;

let
  tic = (((V7_n = 0) and V9_state) and V8_first);
  tac = (((V7_n = 0) and (not V9_state)) and V8_first);
  V6_hz = (if (reset and (delay > 0)) then delay else (1 -> (pre V6_hz)));
  V7_n = (if (reset and (delay > 0)) then 0 else (1 -> (((pre V7_n) + 1) mod 
  V6_hz)));
  V8_first = (if reset then true else (false -> (reset or (pre V8_first))));
  V9_state = (false -> (if (V7_n = 0) then (false -> (not (pre V9_state))) else 
  (pre V9_state)));
tel

