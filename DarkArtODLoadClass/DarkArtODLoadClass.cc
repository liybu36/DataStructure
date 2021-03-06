#include "DartArtODLoadClass.hh"

using namespace std;
ClassImp(DarkArtODLoadClass);

bool DartArtODLoadClass::Load_DarkArtODTree(TChain *odtree, DartArtODEvent & h)
{
  odtree->SetBranchAddress("run_id",&h.od_run);
  odtree->SetBranchAddress("event_id",&h.od_event);
  odtree->SetBranchAddress("gps_timestamp_sec", &h.od_timestamp);
  odtree->SetBranchAddress("bad_time_alignment",&h.bad_time_alignment);
  odtree->SetBranchAddress("lsv_total_charge", &h.lsv_total_charge);
  odtree->SetBranchAddress("wt_total_charge", &h.wt_total_charge);
  odtree->SetBranchAddress("roi_lsv_charge_vec",&h.roi_lsv_charge);
  odtree->SetBranchAddress("slider_lsv_charge_vec",&h.slider_lsv_charge);
  odtree->SetBranchAddress("slider_lsv_time_ns_vec",&h.slider_lsv_time);

  odtree->SetBranchAddress("nclusters_lsv", &h.od_nclusters);
  odtree->SetBranchAddress("cluster_lsv_charge", &h.od_cluster_charge);
  odtree->SetBranchAddress("cluster_lsv_start_ns", &h.od_cluster_start);
  odtree->SetBranchAddress("cluster_lsv_height", &h.od_cluster_height);
  odtree->SetBranchAddress("cluster_lsv_max_multiplicity", &h.od_cluster_multiplicity);
  //odtree->SetBranchAddress("cluster_pass_multcut", &h.od_cluster_pass_multcut);
  //odtree->SetBranchAddress("cluster_dtprompt", &h.od_cluster_dtprompt);

  return true;
}

void DartArtODLoadClass::Create_DarkArtODChain()
{
  od_chain = new TChain("odtree");
}

bool DartArtODLoadClass::Add_DarkArtODTree(int i)
{
  TString odfile;
  odfile.Form("SLADOD_Run%06d.root",i);
  odfile.Prepend(GetDartArtODIndir());
  if(!VerifyDataFile(odfile))
    return false;
  else
    od_chain->Add(odfile);
  return true;
}

bool DartArtODLoadClass::VerifyDataFile(TString mainfile)
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

//Old multiplicity cut
bool DartArtODLoadClass::multiplicity_cut(float height,float multiplicity,float charge){
  return height/multiplicity < (2.563e7 + TMath::Sqrt(1.574e14+1.390e12*(charge-14.40)*(charge-14.40)));
}
/*
void DarkArtODLoadClass::Set_Pass_multcut(){
  if(multiplicity_cut(t.od_cluster_height,t.od_cluster_multiplicty,t.od_cluster_charge))
    t.od_cluster_pass_multcut->push_back(1);
  else 
    t.od_cluster_pass_multcut->push_back(0);
}
*/
void DartArtODLoadClass::DartArtODProcess(int start, int end)
{
  Create_DarkArtODChain();
  for(int i=start; i<=end; i++){
    if(!Add_DarkArtODTree(i))
      continue;
  }
  Load_DarkArtODTree(od_chain,t);
}
