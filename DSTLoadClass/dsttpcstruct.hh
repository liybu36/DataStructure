#ifndef _dsttpcstruct_HH
#define _dsttpcstruct_HH

#include <iostream>

struct DSTTPCEvent
{
  DSTTPCEvent():
    runID(-1),tpc_eventID(-1),tpc_event_type(-1),tpc_gps_fine(0),tpc_gps_coarse(0),
    tpc_s1_start_time(0),tpc_total_s1(0),tpc_total_f90(0),tpc_t_drift(0),tpc_s1_late(0),
    tpc_npulses(0),tpc_timestamp(0)
  {}

  Int_t    runID;
  Int_t    tpc_eventID;
  Int_t    tpc_event_type; // 0 gamma, 1 neutron, -1 else
  Double_t tpc_gps_fine; //clock cycles
  Double_t tpc_gps_coarse; //[s]
  Double_t tpc_s1_start_time; //[us]
  Double_t tpc_total_s1; //[PE]
  Double_t tpc_total_f90;
  Double_t tpc_t_drift; //[us]
  Double_t tpc_s1_late; //[PE]
  Int_t    tpc_npulses;
  Double_t tpc_timestamp;  //[us]

};
#endif /* _dsttpcstruct_HH */
