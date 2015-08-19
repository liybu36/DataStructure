#ifndef _dstodstruct_HH
#define _dstodstruct_HH

#include <iostream>
#include <vector>

struct DSTODEvent
{
  DSTODEvent():
    od_eventID(-1),od_nclusters(0),od_gps_fine(0),od_gps_coarse(0),od_timestamp(0),
    od_wt_charge(0),od_cluster_charge(0),od_cluster_start(0),od_cluster_height(0),
    od_cluster_multiplicity(0),od_cluster_pass_multcut(0),od_cluster_dtprompt(0)
  {}

  Int_t od_eventID;
  Int_t od_nclusters;
  Double_t od_gps_fine;
  Double_t od_gps_coarse;
  Double_t od_timestamp;
  Double_t od_wt_charge;
  std::vector<double>  *od_cluster_charge;
  std::vector<double>  *od_cluster_start;
  std::vector<double>  *od_cluster_height;
  std::vector<double>  *od_cluster_multiplicity;
  std::vector<int>     *od_cluster_pass_multcut;
  std::vector<double>  *od_cluster_dtprompt;

};
#endif /* _dstodstruct_HH */
