node Portillon
  (A: bool;
  B: bool)
returns
  (alarm: bool);

var
  V5_lastPass: bool;

let
  alarm = (if A then V5_lastPass else (if B then V5_lastPass else false));
  V5_lastPass = (false -> (if A then true else (if B then false else (pre 
  V5_lastPass))));
tel

