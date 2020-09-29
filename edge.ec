node edge
  (X: bool)
returns
  (Y: bool);

let
  Y = (((false -> (not (pre X))) and X) or ((false -> (pre X)) and (not X)));
tel

