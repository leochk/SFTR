node once_from_to
  (X: bool;
  A: bool;
  B: bool)
returns
  (ok: bool);

var
  V18_xpresent: bool;

let
  ok = ((not X) -> (if A then true else (if (B and (not (pre V18_xpresent))) 
  then false else (pre ok))));
  V18_xpresent = (false -> (if X then true else (if B then false else (pre 
  V18_xpresent))));
tel

