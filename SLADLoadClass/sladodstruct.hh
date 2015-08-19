#ifndef _sladodstruct_HH
#define _sladodstruct_HH

#include <iostream>

struct SLADODEvent {
  SLADODEvent():
    od_run(-1),od_event(-1), od_present(0),od_timestamp(0),
    lsv_total_charge(0.),wt_total_charge(0.),
    roi_lsv_charge(0),slider_lsv_charge(0),slider_lsv_time(0),
    od_nclusters(-1),od_cluster_charge(0),od_cluster_start(0),
    od_cluster_height(0),od_cluster_multiplicity(0),od_cluster_pass_multcut(0),
    od_cluster_dtprompt(0)
  {}

  Int_t    od_run;
  Int_t    od_event;
  Int_t    od_present;
  Double_t od_timestamp;
  Float_t  lsv_total_charge;
  Float_t  wt_total_charge;
  std::vector<float>   *roi_lsv_charge;
  std::vector<float>   *slider_lsv_charge;
  std::vector<float>   *slider_lsv_time;
  Int_t    od_nclusters;
  std::vector<float> *od_cluster_charge;
  std::vector<float> *od_cluster_start;//ns
  std::vector<float> *od_cluster_height;
  std::vector<float> *od_cluster_multiplicity;
  std::vector<int>   *od_cluster_pass_multcut;
  std::vector<float> *od_cluster_dtprompt;//us
};

#endif /* _sladodstruct_HH */
