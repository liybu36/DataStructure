#ifndef _reconstruct_HH
#define _reconstruct_HH

#include <iostream>

struct ReconEvent{
  ReconEvent():
    event_id(0),event_pdg(0),event_broken(0),volume(0),n_active(0),
    et(0),ex(0),ey(0),ez(0),edep(0),eqch(0),quenchingfactor(0)
  {}

  Int_t           event_id;
  Int_t           event_pdg;
  Bool_t          event_broken;
  vector<TString> *volume;
  Int_t           n_active;
  vector<double>  *et;
  vector<double>  *ex;
  vector<double>  *ey;
  vector<double>  *ez;
  vector<double>  *edep;
  vector<double>  *eqch;
  vector<double>  *quenchingfactor;
  
};
#endif /* _reconstruct_HH */
