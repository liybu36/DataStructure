#ifndef _sladtpcstruct_HH
#define _sladtpcstruct_HH

#include <iostream>

struct SLADTPCEvent
{
  SLADTPCEvent():
    run_id(0),subrun_id(0),event_id(0),trigger_multiplicity(0),tpc_digital_sum(0),hasV1724(0),
    integrated_lifetime(0),integrated_inhibittime(0),gps_coarse(0),gps_fine(0),nchannel(0),
    baseline_not_found(0),life_time(0),inhibit_time(0),acqui_window(0),
    tdrift(0),npulses(0),has_s3(0),has_s1echo(0),
    s1_start_time(0),s1_end_time(0),s2_start_time(0),s2_end_time(0),
    s1(0),s1_corr(0),total_s1_top(0),total_s1_bottom(0),
    s1_total_f90(0),s1_total_f90_fixed(0),s1_total_f90_spe_mean(0),is_saturated_pulse0(0),
    s1_max_chan(0),s1_max_frac(0),max_s1_frac_cut_threshold99(0),max_s1_frac_cut_exceeds99(0),
    s2(0),s2_corr(0),total_s2_top(0),total_s2_bottom(0),s2_total_f90(0),s2_total_f90_fixed(0),s2_total_f90_spe_mean(0),
    is_saturated_pulse1(0),bary_s2_x(0),bary_s2_y(0),
    s2_max_chan(0),s2_max_frac(0),
    jason_SCM(0),jason_x(0),jason_y(0),jason_chi2(0),jason_r(0),jason_theta(0),jason_xycorr_factor(0),
    allpulses_xyl_npulses(0),
    /*
    allpulses_xyl_fidcut_ratio(0),allpulses_xyl_x(0),allpulses_xyl_y(0),
    allpulses_xyl_chi2(0),allpulses_xyl_r(0),allpulses_xyl_theta(0),allpulses_xyl_xycorr_factor(0),
    */
    masa_x(0),masa_y(0),masa_chi2(0),masa_r(0),masa_theta(0),masa_xycorr_factor(0),
    /*
    allpulses_npulses(0),allpulses_x(0),allpulses_y(0),allpulses_chi2(0),allpulses_r(0),allpulses_theta(0),allpulses_xycorr_factor(0),
    */
    pulse_info_npulses(0)
    /* pulse_info_pulse_id(0),pulse_info_start_time(0),pulse_info_end_time(0),pulse_info_peak_time(0),
    pulse_info_max_chan(0),pulse_info_total_npe(0),pulse_info_f90(0),pulse_info_f200(0),pulse_info_saturated(0),
    pulse_info_fixed_int1(0),pulse_info_fixed_int2(0),pulse_info_ch_light_size(0),pulse_info_light(0),pulse_info_satcorr_f90(0),
    pulse_info_satcorr_f90_fixed(0),pulse_info_satcorr_fixed_int1(0),pulse_info_satcorr_fixed_int2(0),
    pulse_info_satcorr_f200(0),pulse_info_satcorr_f200_fixed(0)*/
  {}

  //events tree
  int    run_id;
  int    subrun_id;
  int    event_id;
  Int_t    trigger_multiplicity;
  UInt_t    tpc_digital_sum;
  short int  hasV1724;
  //logbook tree
  Double_t integrated_lifetime;
  Double_t integrated_inhibittime;
  //gps tree
  int    gps_coarse;
  int    gps_fine;
  //nchannel tree
  int    nchannel;
  //baseline tree
  short int baseline_not_found;
  //long_lifetime tree
  Double_t life_time;
  Double_t inhibit_time;
  //acqui_window tree
  float  acqui_window;//[us]
  //standard_cuts tree
  Short_t selection_results[16];
  //tdrift tree
  Double_t tdrift;
  //npulses tree
  Int_t    npulses;
  Int_t    has_s3;
  Int_t    has_s1echo;
  //s1_time tree
  Float_t  s1_start_time;
  Float_t  s1_end_time;
  Float_t  s2_start_time;
  Float_t  s2_end_time;
  //s1 tree
  float  s1;
  float  s1_corr;
  float  total_s1_top;
  float  total_s1_bottom;
  //s1_f90 tree
  float  s1_total_f90;
  float  s1_total_f90_fixed;
  float  s1_total_f90_spe_mean;
  //s1_saturation tree
  int    is_saturated_pulse0;
  //s1_fraction tree
  int    s1_max_chan;
  float  s1_max_frac;
  //max_s1_frac_cut tree
  float  max_s1_frac_cut_threshold99;
  int    max_s1_frac_cut_exceeds99;
  //s2 tree
  float  s2;
  float  s2_corr;
  float  total_s2_top;
  float  total_s2_bottom;
  //s2_f90 tree
  float  s2_total_f90;
  float  s2_total_f90_fixed;
  float  s2_total_f90_spe_mean;
  //s2_saturation tree
  int    is_saturated_pulse1;
  //bary_s2 tree
  float  bary_s2_x;
  float  bary_s2_y;
  //s2_fraction tree
  int    s2_max_chan;
  float  s2_max_frac;
  float  s2_chan[38];
  //xylocator_xy tree
  float  jason_SCM;
  float  jason_x;
  float  jason_y;
  float  jason_chi2;
  float  jason_r;
  float  jason_theta;
  float  jason_xycorr_factor;
  //allpulses_xyl_xy tree
  Int_t    allpulses_xyl_npulses;
  Float_t  allpulses_xyl_fidcut_ratio[14]; //[allpulses_xyl_npulses]     
  Float_t  allpulses_xyl_x[14]; //[allpulses_xyl_npulses]  
  Float_t  allpulses_xyl_y[14]; //[allpulses_xyl_npulses]  
  Float_t  allpulses_xyl_chi2[14]; //[allpulses_xyl_npulses]  
  Float_t  allpulses_xyl_r[14]; //[allpulses_xyl_npulses]  
  Float_t  allpulses_xyl_theta[14]; //[allpulses_xyl_npulses]  
  Float_t  allpulses_xyl_xycorr_factor[14]; //[allpulses_xyl_npulses]  
  //masa_xy tree
  float  masa_x;
  float  masa_y;
  float  masa_chi2;
  float  masa_r;
  float  masa_theta;
  float  masa_xycorr_factor;
  //allpulses_xy tree
  Int_t   allpulses_npulses;
  Float_t allpulses_x[14]; //[allpulses_npulses]  
  Float_t allpulses_y[14];
  Float_t allpulses_chi2[14];
  Float_t allpulses_r[14];
  Float_t allpulses_theta[14];
  Float_t allpulses_xycorr_factor[14];
  //pulse_info tree
  int pulse_info_npulses;
  int pulse_info_pulse_id[100];
  float pulse_info_start_time[100];
  float pulse_info_end_time[100];
  float pulse_info_peak_time[100];
  int pulse_info_max_chan[100];
  float pulse_info_total_npe[100];
  float pulse_info_f90[100];
  float pulse_info_f200[100];
  int pulse_info_saturated[100];
  float pulse_info_fixed_int1[100];
  float pulse_info_fixed_int2[100];
  int pulse_info_ch_light_size;
  float pulse_info_light[38*100];
  float pulse_info_satcorr_f90[100];
  float pulse_info_satcorr_f90_fixed[100];
  float pulse_info_satcorr_fixed_int1[100];
  float pulse_info_satcorr_fixed_int2[100];
  float pulse_info_satcorr_f200[100];
  float pulse_info_satcorr_f200_fixed[100];
};

#endif /* _sladtpcstruct_HH */
