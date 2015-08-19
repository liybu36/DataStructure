#include "SLADLoadClass.hh"

using namespace std;
ClassImp(SLADLoadClass);

bool SLADLoadClass::Load_TPCTree(TChain* tpctree, SLADTPCEvent & g)
{
  /*  //logbook tree
  tpctree->SetBranchAddress("logbook.integrated_lifetime", &g.integrated_lifetime);
  tpctree->SetBranchAddress("logbook.integrated_inhibittime", &g.integrated_inhibittime);
  */
  //events tree
  tpctree->SetBranchAddress("run_id", &g.run_id);
  tpctree->SetBranchAddress("subrun_id", &g.subrun_id);
  tpctree->SetBranchAddress("event_id", &g.event_id);
  tpctree->SetBranchAddress("trigger_multiplicity", &g.trigger_multiplicity);
  tpctree->SetBranchAddress("tpc_digital_sum", &g.tpc_digital_sum);
  tpctree->SetBranchAddress("hasV1724", &g.hasV1724);
  //gps tree
  tpctree->SetBranchAddress("gps_coarse", &g.gps_coarse);
  tpctree->SetBranchAddress("gps_fine", &g.gps_fine);
  //nchannel tree
  tpctree->SetBranchAddress("nchannel.nchannel", &g.nchannel);
  //baseline tree
  tpctree->SetBranchAddress("baseline.SumChannelHasNoBaseline", &g.baseline_not_found);
  //long_lifetime tree
  tpctree->SetBranchAddress("long_lifetime.lifetime", &g.life_time);
  tpctree->SetBranchAddress("long_lifetime.inhibittime", &g.inhibit_time);
  //acqui_window tree
  tpctree->SetBranchAddress("acqui_window.acqui_window", &g.acqui_window);
  //standard_cuts tree
  tpctree->SetBranchAddress("standard_cuts.selection_results", &g.selection_results);
  //tdrift tree
  tpctree->SetBranchAddress("tdrift.tdrift", &g.tdrift);
  //npulses tree
  tpctree->SetBranchAddress("npulses.n_phys_pulses", &g.npulses);
  tpctree->SetBranchAddress("npulses.has_s3", &g.has_s3);
  tpctree->SetBranchAddress("npulses.has_s1echo", &g.has_s1echo);
  //s1_time tree
  tpctree->SetBranchAddress("s1_time.s1_start_time", &g.s1_start_time);
  tpctree->SetBranchAddress("s1_time.s1_end_time", &g.s1_end_time);
  tpctree->SetBranchAddress("s1_time.s2_start_time", &g.s2_start_time);
  tpctree->SetBranchAddress("s1_time.s2_end_time", &g.s2_end_time);
  //s1 tree
  tpctree->SetBranchAddress("s1.total_s1", &g.s1);
  tpctree->SetBranchAddress("s1.total_s1_corr", &g.s1_corr);
  tpctree->SetBranchAddress("s1.total_s1_top", &g.total_s1_top);
  tpctree->SetBranchAddress("s1.total_s1_bottom", &g.total_s1_bottom);
  //s1_f90 tree 
  tpctree->SetBranchAddress("s1_f90.total_f90", &g.s1_total_f90);
  tpctree->SetBranchAddress("s1_f90.total_f90_fixed", &g.s1_total_f90_fixed);
  tpctree->SetBranchAddress("s1_f90.total_f90_spe_mean", &g.s1_total_f90_spe_mean);
  //s1_saturation tree
  tpctree->SetBranchAddress("s1_saturation.is_saturated_pulse0", &g.is_saturated_pulse0);
  //s1_fraction tree
  tpctree->SetBranchAddress("s1_fraction.s1_max_chan", &g.s1_max_chan);
  tpctree->SetBranchAddress("s1_fraction.s1_max_frac", &g.s1_max_frac);
  //max_s1_frac_cut tree
  tpctree->SetBranchAddress("max_s1_frac_cut.max_s1_frac_cut_threshold99", &g.max_s1_frac_cut_threshold99);
  tpctree->SetBranchAddress("max_s1_frac_cut.max_s1_frac_cut_exceeds99", &g.max_s1_frac_cut_exceeds99);
  //s2 tree
  tpctree->SetBranchAddress("s2.total_s2", &g.s2);
  tpctree->SetBranchAddress("s2.total_s2_corr", &g.s2_corr);
  tpctree->SetBranchAddress("s2.total_s2_top", &g.total_s2_top);
  tpctree->SetBranchAddress("s2.total_s2_bottom", &g.total_s2_bottom);
  //s2_f90 tree
  tpctree->SetBranchAddress("s2_f90.total_s2_f90", &g.s2_total_f90);
  tpctree->SetBranchAddress("s2_f90.total_s2_f90_fixed", &g.s2_total_f90_fixed);
  tpctree->SetBranchAddress("s2_f90.total_s2_f90_spe_mean", &g.s2_total_f90_spe_mean);
  //s2_saturation tree
  tpctree->SetBranchAddress("s2_saturation.is_saturated_pulse1", &g.is_saturated_pulse1);
  //bary_s2 tree
  tpctree->SetBranchAddress("bary_s2.bary_s2_x", &g.bary_s2_x);
  tpctree->SetBranchAddress("bary_s2.bary_s2_y", &g.bary_s2_y);
  //s2_fraction tree
  tpctree->SetBranchAddress("s2_fraction.s2_chan", g.s2_chan);
  tpctree->SetBranchAddress("s2_fraction.s2_max_chan", &g.s2_max_chan);
  tpctree->SetBranchAddress("s2_fraction.s2_max_frac", &g.s2_max_frac);
  //xylocator_xy tree
  tpctree->SetBranchAddress("xylocator_xy.xyl_SCM", &g.jason_SCM);
  tpctree->SetBranchAddress("xylocator_xy.xyl_best_x", &g.jason_x);
  tpctree->SetBranchAddress("xylocator_xy.xyl_best_y", &g.jason_y);
  tpctree->SetBranchAddress("xylocator_xy.xyl_best_chi2", &g.jason_chi2);
  tpctree->SetBranchAddress("xylocator_xy.xyl_best_r", &g.jason_r);
  tpctree->SetBranchAddress("xylocator_xy.xyl_best_theta", &g.jason_theta);
  tpctree->SetBranchAddress("xylocator_xy.xyl_best_xycorr_factor", &g.jason_xycorr_factor);
  //allpulses_xyl_xy tree
  tpctree->SetBranchAddress("allpulses_xyl_xy.allpulses_xyl_npulses", &g.allpulses_xyl_npulses);
  tpctree->SetBranchAddress("allpulses_xyl_xy.allpulses_xyl_fidcut_ratio", g.allpulses_xyl_fidcut_ratio);
  tpctree->SetBranchAddress("allpulses_xyl_xy.allpulses_xyl_x", g.allpulses_xyl_x);
  tpctree->SetBranchAddress("allpulses_xyl_xy.allpulses_xyl_y", g.allpulses_xyl_y);
  tpctree->SetBranchAddress("allpulses_xyl_xy.allpulses_xyl_chi2", g.allpulses_xyl_chi2);
  tpctree->SetBranchAddress("allpulses_xyl_xy.allpulses_xyl_r", g.allpulses_xyl_r);
  tpctree->SetBranchAddress("allpulses_xyl_xy.allpulses_xyl_theta", g.allpulses_xyl_theta);
  tpctree->SetBranchAddress("allpulses_xyl_xy.allpulses_xyl_xycorr_factor", g.allpulses_xyl_xycorr_factor);
  //masa_xy tree
  tpctree->SetBranchAddress("masas_xy.masas_x", &g.masa_x);
  tpctree->SetBranchAddress("masas_xy.masas_y", &g.masa_y);
  tpctree->SetBranchAddress("masas_xy.masas_chi2", &g.masa_chi2);
  tpctree->SetBranchAddress("masas_xy.masas_r", &g.masa_r);
  tpctree->SetBranchAddress("masas_xy.masas_theta", &g.masa_theta);
  tpctree->SetBranchAddress("masas_xy.masas_xycorr_factor", &g.masa_xycorr_factor);
  //allpulses_xy tree
  tpctree->SetBranchAddress("allpulses_xy.allpulses_npulses", &g.allpulses_npulses);
  tpctree->SetBranchAddress("allpulses_xy.allpulses_x", g.allpulses_x);
  tpctree->SetBranchAddress("allpulses_xy.allpulses_y", g.allpulses_y);
  tpctree->SetBranchAddress("allpulses_xy.allpulses_chi2", g.allpulses_chi2);
  tpctree->SetBranchAddress("allpulses_xy.allpulses_r", g.allpulses_r);
  tpctree->SetBranchAddress("allpulses_xy.allpulses_theta", g.allpulses_theta);
  tpctree->SetBranchAddress("allpulses_xy.allpulses_xycorr_factor", g.allpulses_xycorr_factor);
  //pulse_info tree
  tpctree->SetBranchAddress("pulse_info.pulse_info_npulses",&g.pulse_info_npulses);
  tpctree->SetBranchAddress("pulse_info.pulse_info_pulse_id",&g.pulse_info_pulse_id);
  tpctree->SetBranchAddress("pulse_info.pulse_info_start_time",&g.pulse_info_start_time);
  tpctree->SetBranchAddress("pulse_info.pulse_info_end_time",&g.pulse_info_end_time);
  tpctree->SetBranchAddress("pulse_info.pulse_info_peak_time",&g.pulse_info_peak_time);
  tpctree->SetBranchAddress("pulse_info.pulse_info_max_chan",&g.pulse_info_max_chan);
  tpctree->SetBranchAddress("pulse_info.pulse_info_total_npe",&g.pulse_info_total_npe);
  tpctree->SetBranchAddress("pulse_info.pulse_info_f90",&g.pulse_info_f90);
  tpctree->SetBranchAddress("pulse_info.pulse_info_f200",&g.pulse_info_f200);
  tpctree->SetBranchAddress("pulse_info.pulse_info_saturated",&g.pulse_info_saturated);
  tpctree->SetBranchAddress("pulse_info.pulse_info_fixed_int1",&g.pulse_info_fixed_int1);
  tpctree->SetBranchAddress("pulse_info.pulse_info_fixed_int2",&g.pulse_info_fixed_int2);
  tpctree->SetBranchAddress("pulse_info.pulse_info_ch_light_size",&g.pulse_info_ch_light_size);
  tpctree->SetBranchAddress("pulse_info.pulse_info_ch_light",&g.pulse_info_light);
  tpctree->SetBranchAddress("pulse_info.pulse_info_satcorr_f90",&g.pulse_info_satcorr_f90);
  tpctree->SetBranchAddress("pulse_info.pulse_info_satcorr_f90_fixed",&g.pulse_info_satcorr_f90_fixed);
  tpctree->SetBranchAddress("pulse_info.pulse_info_satcorr_fixed_int1",&g.pulse_info_satcorr_fixed_int1);
  tpctree->SetBranchAddress("pulse_info.pulse_info_satcorr_fixed_int2",&g.pulse_info_satcorr_fixed_int2);
  tpctree->SetBranchAddress("pulse_info.pulse_info_satcorr_f200",&g.pulse_info_satcorr_f200);
  tpctree->SetBranchAddress("pulse_info.pulse_info_satcorr_f200_fixed",&g.pulse_info_satcorr_f200_fixed);

  cout<<"!Load SLADTPCTree"<<endl;
  return true;
}

bool SLADLoadClass::Load_ODTree(TChain* odtree, SLADODEvent & h)
{
  odtree->SetBranchAddress("veto_run_id",&h.od_run);
  odtree->SetBranchAddress("veto_event_id",&h.od_event);
  odtree->SetBranchAddress("veto_present",&h.od_present);
  odtree->SetBranchAddress("veto_timestamp_us", &h.od_timestamp);
  odtree->SetBranchAddress("veto_lsv_total_charge", &h.lsv_total_charge);
  odtree->SetBranchAddress("veto_wt_total_charge", &h.wt_total_charge);
  odtree->SetBranchAddress("veto_roi_lsv_charge_vec",&h.roi_lsv_charge);
  odtree->SetBranchAddress("veto_slider_lsv_charge_vec",&h.slider_lsv_charge);
  odtree->SetBranchAddress("veto_slider_lsv_time_vec",&h.slider_lsv_time);
  
  odtree->SetBranchAddress("veto_nclusters", &h.od_nclusters);
  odtree->SetBranchAddress("veto_cluster_charge_vec", &h.od_cluster_charge);
  odtree->SetBranchAddress("veto_cluster_start_ns_vec", &h.od_cluster_start);
  odtree->SetBranchAddress("veto_cluster_height_vec", &h.od_cluster_height);
  odtree->SetBranchAddress("veto_cluster_multiplicity_vec", &h.od_cluster_multiplicity);
  odtree->SetBranchAddress("veto_cluster_pass_multcut_vec", &h.od_cluster_pass_multcut);
  odtree->SetBranchAddress("veto_cluster_dtprompt_vec", &h.od_cluster_dtprompt);
  
  cout<<"!Load SLADODTree"<<endl;
  return true;
}
  
void SLADLoadClass::Create_TPCChain()
{
  tpc_chain = new TChain("events");
  s2_fraction = new TChain("s2_fraction");
  masaxy = new TChain("masas_xy");
  allpulses_xy = new TChain("allpulses_xy");
  jasonxy = new TChain("xylocator_xy");
  allpulses_xyl_xy = new TChain("allpulses_xyl_xy");
  pulse_info = new TChain("pulse_info");
  cout<<"Creat TPC Chain"<<endl;
}

bool SLADLoadClass::Add_TPCTree(int i)
{
  TString tpcfile;
  tpcfile.Form("Run%06d.root",i);
  tpcfile.Prepend(GetSLADTPCIndir());

  if(!VerifyDataFile(tpcfile))
    return false;

  TString s2file = tpcfile;
  s2file.Remove(s2file.Length()-5);
  s2file+="_s2.root";

  TString masaxyfile = tpcfile;
  masaxyfile.Remove(masaxyfile.Length()-5);
  masaxyfile+="_masas_xy.root";

  TString jasonxyfile = tpcfile;
  jasonxyfile.Remove(jasonxyfile.Length()-5);
  jasonxyfile+="_xylocator_xy.root";

  TString pulsefile = tpcfile;
  pulsefile.Remove(pulsefile.Length()-5);
  pulsefile+="_allpulses.root";

  if(!VerifyDataFile(s2file) || !VerifyDataFile(masaxyfile) || !VerifyDataFile(jasonxyfile) || !VerifyDataFile(pulsefile))
    return false;

  tpc_chain->Add(tpcfile);
  s2_fraction->Add(s2file);
  masaxy->Add(masaxyfile);
  allpulses_xy->Add(masaxyfile);
  jasonxy->Add(jasonxyfile);
  allpulses_xyl_xy->Add(jasonxyfile);
  pulse_info->Add(pulsefile);
  cout<<"Add TPC Tree"<<endl;
  return true;
}
void SLADLoadClass::Add_TPCFriend()
{
  tpc_chain->AddFriend(s2_fraction);
  tpc_chain->AddFriend(masaxy);
  tpc_chain->AddFriend(allpulses_xy);
  tpc_chain->AddFriend(jasonxy);
  tpc_chain->AddFriend(allpulses_xyl_xy);
  tpc_chain->AddFriend(pulse_info);
  cout<<"Add TPC Friend"<<endl;
}

void SLADLoadClass::Create_ODChain()
{
  od_chain = new TChain("veto");
  cout<<"create OD Chain"<<endl;
}

bool SLADLoadClass::Add_ODTree(int i)
{
  TString odfile;
  odfile.Form("Run%06d_veto.root",i);
  odfile.Prepend(GetSLADODIndir());
  if(!VerifyDataFile(odfile))
    return false;
  else
    od_chain->Add(odfile);
  cout<<"Add OD Tree"<<endl;
  return true;
}

void SLADLoadClass::SLADProcess(int start, int end)
{
  Create_TPCChain();
  Create_ODChain();
  for(int i=start; i<=end; i++){
    if(!Add_TPCTree(i) || ! Add_ODTree(i))
      continue;
  }
  Add_TPCFriend();
  tpc_chain->AddFriend(od_chain);
  Load_TPCTree(tpc_chain,e);
  Load_ODTree(tpc_chain,t);
}

bool SLADLoadClass::VerifyDataFile(TString mainfile)
{
  ifstream NameCheck;
  NameCheck.open(mainfile.Data());
  if(!NameCheck.good()){
    NameCheck.close();
    return false;
  }else{
    TFile *f = new TFile(mainfile);
    if(!f->IsOpen() || f->IsZombie()){
      NameCheck.close();
      f->Close();
      return false;
    }else{   
      cout<<"Processing the data file: "<<mainfile<<endl;
      NameCheck.close();
      f->Close();
      return true;
    }
  }
}

int SLADLoadClass::Colors(int pos)
{
  vector<int> color;
  color.push_back(TColor::GetColor("#FF2007")); //red         0
  color.push_back(TColor::GetColor("#5A1DE8")); //violet      1
  color.push_back(TColor::GetColor("#000000"));
  color.push_back(TColor::GetColor("#F73CFF")); //pink        5
  color.push_back(TColor::GetColor("#1CFFDF")); //low green   7
  color.push_back(TColor::GetColor("#1485CC")); //blue        4
  color.push_back(TColor::GetColor("#FF791F")); //orange      6
  color.push_back(TColor::GetColor("#AF2FCC")); //dark pink   8
  color.push_back(TColor::GetColor("#E8A60C"));
  color.push_back(TColor::GetColor("#B26618"));
  color.push_back(TColor::GetColor("#79FFFF"));
  color.push_back(TColor::GetColor("#11FF8F"));
  color.push_back(TColor::GetColor("#59FF49")); //green       12

  int size = (int) color.size();
  return color.at(pos%size);
}
