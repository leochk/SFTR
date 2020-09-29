node controleporte
  (porte_ouverte: bool;
  demande_porte: bool;
  en_station: bool;
  attention_depart: bool)
returns
  (porte_ok: bool;
  ouvrir_porte: bool;
  fermer_porte: bool);

var
  V9_depart_imminent: bool;
  V10_porte_demandee: bool;
  V11_accepter_demande: bool;
  V12_depart: bool;

let
  porte_ok = (((en_station and (not V10_porte_demandee)) and (not porte_ouverte
  )) or ((en_station and V10_porte_demandee) and fermer_porte));
  ouvrir_porte = ((en_station and V10_porte_demandee) and (not 
  V9_depart_imminent));
  fermer_porte = attention_depart;
  V9_depart_imminent = (false -> (if fermer_porte then true else (if V12_depart 
  then false else (pre V9_depart_imminent))));
  V10_porte_demandee = (false -> (if (V11_accepter_demande and demande_porte) 
  then true else (if porte_ouverte then false else (pre V10_porte_demandee))));
  V11_accepter_demande = (true -> (if V12_depart then true else (if 
  fermer_porte then false else (pre V11_accepter_demande))));
  V12_depart = ((not porte_ouverte) and (not en_station));
tel

