#define SladEleMC_Selector_cxx
// The class definition in SladEleMC_Selector.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("SladEleMC_Selector.C")
// root> T->Process("SladEleMC_Selector.C","some options")
// root> T->Process("SladEleMC_Selector.C+")
//

#include "SladEleMC_Selector.h"
#include <TH2.h>
#include <TStyle.h>
#include <TMath.h>
#include <iostream>

#include "PMTGeom.h"

using namespace std;

enum TimeCategory_t {RUNT, LT, IT, LTS1, LTS3};
const Int_t nTimeBins = 5;
const TString timelabels[nTimeBins] = { "Run Time", "Live Time", "Inhibit Time", "LT_{S1}", "LT_{S3}"};

enum EvntCut_t {TOTAL, ACCEPTED, NCHANNEL, BASELINE, BASIC, LIVETIME, NPULSE, TRIGERWINDOW, SMALLF90, VALIDS2};
const Int_t nEventBins = 20;
const TString eventlabels[nEventBins] = {"Total", "Accepted", "Number of Channels", "Baseline Cut", "After Basic Cuts", "Short livetime", "# of pulse Cut", "Trigger Time Cut", "Small F90", "Valid S2"};

#define JASONS_XY

void SladEleMC_Selector::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
//   Info("SladEleMC_Selector::Begin()",Form("GetOption() = %s",option.Data()));
//   std::cout << "GetOption() = " << option.Data() << std::endl;
   TObjArray* optarr = option.Tokenize(":");
   TString outdir = ((TObjString*)optarr->At(0))->GetString();
   SetOutputFile(outdir);

}

void SladEleMC_Selector::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).
  Info("SladEleMC_Selector::SlaveBegin()","begining ...");

//  TString option = GetOption();

   SetCutG4Outliers();

   Int_t Edrift = 200;//GetFieldFromAcquisitionWindow(acqui_window);
   run_id=123456;
    //Drift field setting
    SetDriftFieldConf(Edrift, 123456);
    BookHistograms();


//#define OUTTREE

#ifdef OUTTREE
//   fOut_Tree = new TTree("TAlphas","Tree for high energy alpha candidates");
   fOut_Tree = new TTree("TOutliers","Tree for outliers (DM candidates)");
   fOut_Tree->Branch("run_id",&run_id,"run_id/I");
   fOut_Tree->Branch("event_id",&event_id,"event_id/I");
   fOut_Tree->Branch("total_s1",&total_s1,"total_s1/F");
   fOut_Tree->Branch("total_s1_corr",&total_s1_corr,"total_s1_corr/F");
   fOut_Tree->Branch("total_f90",&total_f90,"total_f90/F");
   fOut_Tree->Branch("total_s2",&total_s2,"total_s2/F");
   fOut_Tree->Branch("total_s2_corr",&total_s2_corr,"total_s2_corr/F");
//   fOut_Tree->Branch("total_s2_true",&total_s2_true,"total_s2_true/F");
   fOut_Tree->Branch("t_drift",&t_drift,"t_drift/D");
   fOut_Tree->Branch("radius",&radius,"radius/F");
   fOut_Tree->Branch("s1_max_frac",&s1_max_frac,"s1_max_frac/F");
   fOut_Tree->Branch("max_s1_frac_cut_threshold99",&max_s1_frac_cut_threshold99,"max_s1_frac_cut_threshold99/F");
//   fOut_Tree->Branch("s2",&s2,"s2[38]/D");

   fOutput->Add(fOut_Tree);
#endif
}

Bool_t SladEleMC_Selector::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either SladEleMC_Selector::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.


  Int_t chainentry = fChain->GetChainEntryNumber(entry);
  if(chainentry%(fChain->GetEntries()/10)==0) printf("Processing Entry number %ld [%ld %% of %lld]\n", (long int)chainentry, (long int)(chainentry/(fChain->GetEntries()/100)), fChain->GetEntries());
  fChain->GetTree()->GetEntry(entry);


  fPrevious_total_s1 = total_s1;

  TList  &list = *fOutput;
  ((TH2D*)list("hRun_dT_Trigger"))->Fill(livetime+inhibittime, run_id);
  ((TH2D*)list("hRun_livetime"))->Fill(livetime, run_id);
  ((TH2D*)list("hRun_inhibittime"))->Fill(inhibittime, run_id);

  TH1D* hRunTime = (TH1D*)list("hRunTime");
  hRunTime->Fill(LT, livetime);
  hRunTime->Fill(IT, inhibittime);
  if(livetime>=200.e-6) // longer than 200 us
    hRunTime->Fill(LTS1, livetime);
  else
    hRunTime->Fill(LTS3, livetime);

  ((TH1*)list("hEventConter"))->Fill(TOTAL);
  if(IsValidEvent()) {
      ((TH1*)list("hTotal_livetime"))->Fill(0.5,livetime-std::max(1.35e-3 - inhibittime, 0.));
  }


    FillHistograms();

   return kTRUE;
}

void SladEleMC_Selector::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void SladEleMC_Selector::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
  Info("SladEleMC_Selector::Terminate()","closining ...");

  Int_t nhists = 0;
  TList *list = GetOutputList();
//  list->Print();
  TIter next(list);
  TFile *hOutF = new TFile(fOutName.Data(), "RECREATE");
  TH1 *h;
  TObject* obj;
  while ((obj = (TObject*) next()))
  {
      if(!obj) continue;
      if (obj->InheritsFrom(TH1::Class()))
      {
          h = (TH1*) obj;
//          if(h->InheritsFrom(TH2::Class())){
//          }
          h->Write();

//          if (Debug)cout << "Write " << h->GetName() << " into the file" << endl;
//          delete h;
          nhists++;
      } else if (obj->InheritsFrom(TTree::Class())) {
          fOut_Tree = (TTree*) obj;
          fOut_Tree->Write();
      }
  }
  fCutg->Write();

  hOutF->Save();
  hOutF->Close();
}

Bool_t SladEleMC_Selector::IsValidEvent(){
#define X1      (nchannel==38)                                      // Number of channels                                                                    // Number of channels
#define X2      (baseline_not_found==0)                        // Baseline                                                                    // Baseline
#define X3      (1.35E-3<(livetime+inhibittime))                    // Livetime and inhibit time                                                                    // Livetime and inhibit time
#define X4      (lifetime<1.)                                       // Stalled DAQ                                                                    // Stalled DAQ
#define X5      (veto_present)                                      // Veto present
  TH1* hEventConter = (TH1*)fOutput->FindObject("hEventConter");

  //  if(X1 && X2 && X3 ) return true;
  if (!X1) {
          hEventConter->Fill(1);
          return false;
  }
  else if (!X2) {
          hEventConter->Fill(2);
          return false;
  }
  else if (!X3) {
          hEventConter->Fill(3);
          return false;
  }
  else return true;
}


Bool_t SladEleMC_Selector::IsEventOK(){
  // Define cuts // from cutdef.h on 09/18/2014
                                                                                                    // Veto present
#define X6      (roi_total_prompt_charge<10.)                                                                                            // Coincident veto signal
#define X7      (lsv_max_window_charge<80.&&lsv_late_window_charge<110.&&wt_charge<200.)                                                   // High energy veto signal
#define X8      (npulses==2||(has_s3==1&&npulses==3))                                                                       // Number of pulses
#define X9      ((run_id<7344 &&-0.25<s1_start_time&&s1_start_time<=-0.15) || (run_id>=7344&&run_id<7641&&-4.10<s1_start_time&&s1_start_time<=-4.00) || (run_id>7640&&-6.10<s1_start_time&&s1_start_time<=-6.00))   // Trigger time
#define X10     (is_saturated_pulse0==0)                                                                                                // S1 saturation
#define X11     (s1_max_frac < max_s1_frac_cut_threshold99)                                                                                                      // S1 maximum fraction
//#define X11     (s1_max_frac<0.4)                                                                                                      // S1 maximum fraction
#define X12     (total_s2_f90 < 0.20 && total_s2 > 30.) //(total_s2_f90<0.20)                                                                                               // Valid S2
#define X13     (100. > total_s2_true)                                                                                                    // Minimal S2
#define X14     ((60. < total_s1_corr)&&(total_s1_corr < 200.))                                                                             // S1 range
//#define X15     ((40.0<t_drift)&&(t_drift<334.5))                                                                                         // Drift time
#define X15     ((fT_drift_cut_min < t_drift)&&( t_drift <=fT_drift_cut_max))                                                                                         // Drift time
//cout<<"fT_drift_cut_min: "<<fT_drift_cut_min<<" fT_drift_cut_max: "<<fT_drift_cut_max<<" t_drift: "<<t_drift<<endl;
//cout<<X15<<" "<<(fT_drift_cut_min < t_drift)<<" "<<( t_drift < fT_drift_cut_max)<<endl;
  TH1* hEventConter = (TH1*)fOutput->FindObject("hEventConter");

//	if (!X12 && npulses<2) {
//		  hEventConter->Fill(15);
////		  return false;
//	  }
//	if (!X12) {
//		  hEventConter->Fill(12);
//		  return false;
//	  } else
	if (!X8 && fNRequiredPulses==2) {
	  hEventConter->Fill(8);
//	  return false;
  }
//  else
//    if (!X9) {
//	  hEventConter->Fill(9);
//	  return false;
//  }
//  else if (!X10) {
//	  hEventConter->Fill(10);
//	  return false;
//  }
//  else if (!X11) {
//	  hEventConter->Fill(11);
//	  return false;
//  }
//  else
//    if (!X12 && fNRequiredPulses==2) {
//	  hEventConter->Fill(12);
//	  return false;
//  }
  else {

//	  if (!X15 && fNRequiredPulses==2){
//		  hEventConter->Fill(15);
//		  return false;
//	  }
	  return true;
  }
  return true;
}

void SladEleMC_Selector::FillHistograms(){
  total_s1 = pulse_info_fixed_int2[0]; //assume the first pulse is S2

  TList  &list = *GetOutputList();

  ((TH1D*)list("hTDrift"))->Fill(t_drift);

  ((TH2D*)list("hS1Total_vs_F90"))->Fill(total_s1, total_f90);

  ((TH1D*)list("hTotalS1"))->Fill( total_s1);
  ((TH2D*)list("hTotalS2CorrvsS1"))->Fill( total_s1,  total_s2_corr);

/*  ((TH2D*)list("hsig_npe_vs_s1"))->Fill(total_s1, mc_signal_fixed - mc_npe_fixed);
  ((TH2D*)list("hs1_npe_vs_s1"))->Fill(total_s1, total_s1 - mc_npe_fixed);
  ((TH2D*)list("hs1_sig_vs_s1"))->Fill(total_s1, total_s1 - mc_signal_fixed);
  ((TH2D*)list("hs1_sig_vs_s1length"))->Fill(s1_end_time - s1_start_time, total_s1 - mc_signal_fixed);
//  ((TH2D*)list.FindObject("hsig_npe_vs_npe"))->Fill(mc_npe_fixed, mc_signal_fixed - mc_npe_fixed);
  ((TH2D*)list("hsig_npe_vs_npe"))->Fill(mc_npe_fixed, mc_signal_fixed - mc_npe_fixed);
//  cout<<"total_s1: "<<total_s1<<" mc_npe_fixed: "<<mc_npe_fixed<<" mc_signal_fixed: "<<mc_signal_fixed<<endl;
*/
  ((TH2D*)list("hsig_npe_vs_s1"))->Fill(total_s1, mc_signal_fixed2 - mc_npe_fixed2);
  ((TH2D*)list("hs1_npe_vs_s1"))->Fill(total_s1, total_s1 - mc_npe_fixed2);
  ((TH2D*)list("hs1_sig_vs_s1"))->Fill(total_s1, total_s1 - mc_signal_fixed2);
  ((TH2D*)list("hs1_sig_vs_s1length"))->Fill(s1_end_time - s1_start_time, total_s1 - mc_signal_fixed2);
//  ((TH2D*)list.FindObject("hsig_npe_vs_npe"))->Fill(mc_npe_fixed2, mc_signal_fixed2 - mc_npe_fixed2);
  ((TH2D*)list("hsig_npe_vs_npe"))->Fill(mc_npe_fixed2, mc_signal_fixed2 - mc_npe_fixed2);
  cout<<"total_s1: "<<total_s1<<" mc_npe_fixed2: "<<mc_npe_fixed2<<" mc_signal_fixed2: "<<mc_signal_fixed2<<endl;

}

void SladEleMC_Selector::BookHistograms()
{
//  if(Debug)
    Info("SladEleMC_Selector::BookHistograms()","booking histogram...");

    TList  *list = GetOutputList();

    TH1D* hRunTime = new TH1D("hRunTime", "Time summary [ns];Time Categories", nTimeBins, -0.5, nTimeBins-0.5);
    for (Int_t i=0; i<nTimeBins; i++) hRunTime->GetXaxis()->SetBinLabel(i+1, timelabels[i].Data());
    hRunTime->SetFillColor(kCyan+1);
    list->Add(hRunTime);

    TH1D* hEventConter = new TH1D("hEventConter", "Event Counter", nEventBins, -0.5, nEventBins-0.5);
//    for (Int_t i=0; i<nEventBins; i++) hEventConter->GetXaxis()->SetBinLabel(i+1, eventlabels[i].Data());
    for (Int_t i=0; i<nEventBins; i++) hEventConter->GetXaxis()->SetBinLabel(i+1, Form("CX%d",i));
    hEventConter->SetFillColor(kCyan+1);
    list->Add(hEventConter);


    Double_t minDriftT(0.), maxDriftT((int)(fDriftTimeMax*1.2));
    Double_t minRunId(TMath::Max(run_id-1000, 0)+0.5), maxRunId(run_id+1000+0.5);
    Int_t nRunId = maxRunId - minRunId;
    cout<<"nRunId: "<<nRunId<<endl;

  Int_t nS1Bins(30), nS2Bins(110);
  Float_t minS1(3600), maxS1(3900), minS2(0.), maxS2(5.5e+3);


  list->Add(new TH1F("hTotal_livetime", "total_livetime", 1, 0, 10));
  list->Add(new TH2D("hRun_livetime", "Run ID vs livetime;livetime [s];run_id", 250, 0., 2.5e-3, nRunId, minRunId, maxRunId));
  list->Add(new TH2D("hRun_inhibittime", "Run ID vs inhibittime;inhibittime [s];run_id", 250, 0., 2.5e-3, nRunId, minRunId, maxRunId));
  list->Add(new TH2D("hRun_dT_Trigger", "Run ID vs time from previous trigger (inhibit + live time);inhibittime + livetime [s];run_id", 250, 0., 2.5e-3, nRunId, minRunId, maxRunId));

  list->Add(new TH1D("hTDrift", "Drift time; t_drift [#mus]", 400, minDriftT, maxDriftT));
  list->Add(new TH2D("hS1Total_vs_F90", "S1 Spectrum vs f90;total_s1 [PE];total_f90", 700, 0., 7e+4, 550, 0, 1.1));
  list->Add(new TH1D("hTotalS1", "S1; total_s1 [PE]", nS1Bins, minS1, maxS1));
  list->Add(new TH2D("hTotalS2CorrvsS1", "S2_{Corr.} vs S1; total_s1 [PE]; total_s2_corr [PE]", nS1Bins, minS1, maxS1, nS2Bins, minS2, maxS2));

  Int_t nS1Diff =150;
  Float_t S1DiffMin(-150.), S1DiffMax(150.);
//  list->Add(new TH2D("hsig_npe_vs_s1", "S1 digitization resolution vs S1; total_s1 [PE]; signal_fixed - npe_fixed [PE]", nS1Bins, minS1, maxS1, nS1Diff, S1DiffMin, S1DiffMax));
//  list->Add(new TH2D("hs1_npe_vs_s1", "S1 reconstruction resolution vs S1; total_s1 [PE]; total_s1 - npe_fixed [PE]", nS1Bins, minS1, maxS1, nS1Diff, S1DiffMin, S1DiffMax));
//  list->Add(new TH2D("hs1_sig_vs_s1", "S1 resolution due to baseline vs S1; total_s1 [PE]; total_s1 - signal_fixed [PE]", nS1Bins, minS1, maxS1, 100, -50, 50));
//  list->Add(new TH2D("hs1_sig_vs_s1length", "S1 resolution due to baseline vs S1 length; s1 length [#mus]; total_s1 - signal_fixed [PE]", 20, 0, 20, 100, -50, 50));
//
//  list->Add(new TH2D("hsig_npe_vs_npe", "S1 digitization resolution vs npe; npe [PE]; signal_fixed - npe_fixed [PE]", nS1Bins, minS1, maxS1, nS1Diff, S1DiffMin, S1DiffMax));

  list->Add(new TH2D("hsig_npe_vs_s1", "S1 digitization resolution vs S1; total_s1 [PE]; signal_fixed - npe_fixed [PE]", nS2Bins, minS2, maxS2, nS1Diff, S1DiffMin, S1DiffMax));
  list->Add(new TH2D("hs1_npe_vs_s1", "S1 reconstruction resolution vs S1; total_s1 [PE]; total_s1 - npe_fixed [PE]", nS2Bins, minS2, maxS2, nS1Diff, S1DiffMin, S1DiffMax));
  list->Add(new TH2D("hs1_sig_vs_s1", "S1 resolution due to baseline vs S1; total_s1 [PE]; total_s1 - signal_fixed [PE]", nS2Bins, minS2, maxS2, 100, -50, 50));
  list->Add(new TH2D("hs1_sig_vs_s1length", "S1 resolution due to baseline vs S1 length; s1 length [#mus]; total_s1 - signal_fixed [PE]", 200, 0, 200, 100, -50, 50));

  list->Add(new TH2D("hsig_npe_vs_npe", "S1 digitization resolution vs npe; npe [PE]; signal_fixed - npe_fixed [PE]", nS2Bins, minS2, maxS2, nS1Diff, S1DiffMin, S1DiffMax));

}

void SladEleMC_Selector::SetCutG4Outliers(){
  fCutg = new TCutG("outlierscut",9);
  fCutg->SetVarX("total_s1_corr");
  fCutg->SetVarY("total_f90");
  fCutg->SetPoint(0,40,0.75);
  fCutg->SetPoint(1,60,0.66);
  fCutg->SetPoint(2,80,0.62);
  fCutg->SetPoint(3,100,0.58);
  fCutg->SetPoint(4,120,0.56);
  fCutg->SetPoint(5,160,0.52);
  fCutg->SetPoint(6,1000,0.52);
  fCutg->SetPoint(7,1000,1.1);
  fCutg->SetPoint(8,40,1.1);
  fCutg->SetPoint(9,40,0.7);

  fOutput->Add(fCutg);

}

void SladEleMC_Selector::SetDriftFieldConf(Int_t Edrift, Int_t RunId) {
  fIsFieldSet = true;
  fEdrift = Edrift;
  fNRequiredPulses=2;
  if(Edrift == 0){
      fDriftTimeMax = 10.; // usually acquisition window is 25 us
      fNRequiredPulses=1; //default is 2
      fS1corr_mean_Kr_peak = (RunId<7909)? 326.7 : 321.6; //Kr peak position need to be checked.
      fS1corr_sigma_Kr_peak = 20.;
  } else if (Edrift == 50){
      fDriftTimeMax = 1250 ;
      fS1corr_mean_Kr_peak = 308.1;
      fS1corr_sigma_Kr_peak = 20.;
  } else if (Edrift == 100){
      fDriftTimeMax = (RunId<7909)? 650.4 : 665.;
      fS1corr_mean_Kr_peak = (RunId<7909)? 301.7 : 300.6;
      fS1corr_sigma_Kr_peak = 20.;
  } else if (Edrift == 150){
      fDriftTimeMax = (RunId<7909)? 464.3 : 469.;
      fS1corr_mean_Kr_peak = (RunId<7909)? 296.9 : 294.3;
      fS1corr_sigma_Kr_peak = 20.;
  } else if (Edrift == 200){
      fDriftTimeMax = (RunId<7909)? 373.3 : 376.;
      fS1corr_mean_Kr_peak = (RunId<7909)? 290.6 : 288.8;
      fS1corr_sigma_Kr_peak = 20.;
  } else {
      cout<<"Unknown Drift field value!! Please check input value. E_drift: "<<Edrift<<endl;
  }
  if(Edrift !=0){
      const Float_t t_drift_default = 373.3;
      const Double_t t_s3_sep_min_ratio = 372./t_drift_default; //[us] // scaled by 200 V/cm value
      const Double_t t_s3_sep_max_ratio = 400./t_drift_default; //[us]
      fS3SepTimeMin = t_s3_sep_min_ratio*fDriftTimeMax;
      fS3SepTimeMax = t_s3_sep_max_ratio*fDriftTimeMax;
      cout<<"fS3SepTimeMin: "<<fS3SepTimeMin<<" us, fS3SepTimeMax: "<<fS3SepTimeMax<<" us"<<endl;

      Float_t delta_t = 10./t_drift_default*fDriftTimeMax;
      fT_drift_cut_min = delta_t;
      fT_drift_cut_max = fDriftTimeMax - delta_t;
      cout<<"t_drift_cut_min: "<<fT_drift_cut_min<<" us, T_drift_cut_max: "<<fT_drift_cut_max<<" us"<<endl;
  }
  cout<<"======== XYRecSelector::SetDriftFieldConf() =========="<<endl;
  cout<<"Drift field is "<<Edrift<< " and max drift time is "<< fDriftTimeMax <<endl;
  cout<<"Number of required pulses is "<<fNRequiredPulses<<endl;
}

Double_t SladEleMC_Selector::SetElectronLifetime(Int_t RunId) {
  if (RunId >= 5369 && RunId <= 5547) { // the start of 50 days data
      return 3900.;
  } else if (RunId < 7909){ // change of HHV supply
      return 9600.;
  } else if (RunId < 8434){ // the end of 50 days data
        return 9600.;
  }else if (RunId < 11511){ // the end of 50 days data
      return 9600.;
  } else if (RunId > 11851){ // the start of UAr field on data
        return 4807.;
  } else {
      cout<<"Unknown Run number!! Please check input value. RunId: "<<RunId<<endl;
      return -999.;
  }
}


Bool_t SladEleMC_Selector::CheckFieldSetting(Float_t acqui_wind){
  if (acqui_wind<fDriftTimeMax) return false;
  else return true;
}

Int_t SladEleMC_Selector::GetFieldFromAcquisitionWindow(Float_t acqui_wind){
  if(acqui_wind<100.){ // null field
      return 0;
  } else if (acqui_wind<480.){ // 200 V/cm
      return 200;
  } else if (acqui_wind<600.){ // 150 V/cm
      return 150;
  } else if (acqui_wind<800.){ // 100 V/cm
      return 100;
  } else if (acqui_wind<2000.){ // 50 V/cm
      return 50;
  } else {
      cout<<"Too long acquisition window: "<<acqui_wind<<" us. Please check the data."<<endl;
      return -1;
  }
}

Float_t SladEleMC_Selector::GetExpectedAcquisitionWindow(Int_t Edrift){
  switch (Edrift){ // null field
  case 0:
    return 25.;
  case 200:
    return 440.;
  case 150:
    return 530.;
  case 100:
    return 720.;
  case 50:
    return 1500.;
  default:
    cout<<"unknown drift field: "<<Edrift<<" V/cm."<<endl;
    return -1.;
  }
}



Double_t SladEleMC_Selector::s1_corr_factor(Double_t t_drift_max, Double_t t_drift)
{
  Double_t z = t_drift/(0.5*t_drift_max); // note normalization is to 0.5*t_drift_max
  // looked at Kr peaks in 15us t_drift windows (Run5330+5340), and fit these to [0]*z^5 + [1]*z^4 + [2]*z^3+[3]*z^2+[4]*z+[5].
  Double_t fit_par0 = 0.0407;
  Double_t fit_par1 = -0.206;
  Double_t fit_par2 = 0.407;
  Double_t fit_par3 = -0.389;
  Double_t fit_par4 = 0.247;
  Double_t fit_par5 = 0.898;
  // normalizing all points on fitted curve to expected Kr peak at t_drift_max/2
  Double_t exp_Kr_peak_at_half_t_drift_max = fit_par0 + fit_par1 + fit_par2 + fit_par3 + fit_par4 + fit_par5;
  Double_t exp_Kr_peak_at_t_drift = fit_par0*z*z*z*z*z + fit_par1*z*z*z*z + fit_par2*z*z*z + fit_par3*z*z + fit_par4*z + fit_par5;
  return exp_Kr_peak_at_half_t_drift_max/exp_Kr_peak_at_t_drift; // s1 correction factor
}

Double_t SladEleMC_Selector::s1_TBAcorr_factor(Double_t s1_top, Double_t s1_bottom, Double_t s1)
{
  //TBAsymmetry correction
   Double_t par2[] = {-0.0397956, -0.27216, 0.794036, 1.70427, -3.98323, -8.50783, -2.66051};
   Double_t x = (s1_top-s1_bottom)/ s1;// TBAsym;
   Double_t diff_total_s1 = par2[0]+(par2[1]+(par2[2]+(par2[3]+(par2[4]+par2[5]*x)*x)*x)*x)*x; //(total_s1-total_s1_corr)/total_s1
//   Double_t total_s1_TBAcorr =  s1*(1.-diff_total_s1);
   return (1.-diff_total_s1);
}

Float_t SladEleMC_Selector::GetXYVariance(){
  Double_t bary_x(0.), bary_y(0.), bary_x_sq(0.), bary_y_sq(0.);
  Double_t top_s2(0.), top_s2_sq(0.);
  for (Int_t ch = PMTGeom::N_CHANNELS/2; ch < PMTGeom::N_CHANNELS; ch++) {
    Double_t s2 =total_s2*s2_ch_frac[ch];

    top_s2 += s2;
    top_s2_sq += s2*s2;
    bary_x += PMTGeom::pmtUnit*PMTGeom::pmt_x[ch] * s2;
    bary_y += PMTGeom::pmtUnit*PMTGeom::pmt_y[ch] * s2;
    bary_x_sq += PMTGeom::pmtUnit*PMTGeom::pmtUnit*PMTGeom::pmt_x[ch]*PMTGeom::pmt_x[ch] * s2;
    bary_y_sq += PMTGeom::pmtUnit*PMTGeom::pmtUnit*PMTGeom::pmt_y[ch]*PMTGeom::pmt_y[ch] * s2;
  }// end loop over channels

  //calculate unbiased weighted variance of xy
  Double_t denom = top_s2*top_s2 - top_s2_sq;
  Double_t variance_x = (top_s2*bary_x_sq - bary_x*bary_x)/denom;
  Double_t variance_y = (top_s2*bary_y_sq - bary_y*bary_y)/denom;

//  Double_t biased_variance_x = (top_s2*bary_x_sq - bary_x*bary_x)/top_s2/top_s2;

//  cout<<"unbiased variance_x: "<<variance_x<<endl;//TMath::Sqrt(variance_x)<<endl;
//  cout<<"unbiased variance_y: "<<variance_y<<endl;//<<TMath::Sqrt(variance_y)<<endl;
//  cout<<"biased variance_x: "<<biased_variance_x<<endl;//TMath::Sqrt(biased_variance_x)<<endl;

  return variance_x + variance_y;


}


Double_t SladEleMC_Selector::GetRecoilEnergy(Double_t s1_corr, Double_t s2xyCorr) //function returns recoil energy with give corrected S2 & S1
{
// This is obtained from fit to Kr peak in total_s2_xy_corr vs total_s1_corr of 100, 150, and 200 V/cm data
// from Oct. 2013 and Feb. 2014 on Jan. 21 2015 by Masa.
/*  Double_t Woverg2  = 5.51861e-04;   //error:  1.20967e-05
  Double_t g2overg1 = 2.29496e+02;   //error:  5.59447e+00
  Double_t Eee = Woverg2*(s2xyCorr+g2overg1*s1_corr);
  */
  Double_t W = 23.6e-3; //keV Energy required to make an ion-electron pair
  Double_t f = 0.21; // ratio of excited atoms to ions
//  Double_t epsi1 = 0.154; // PE(S1) per excited atoms
//  Double_t epsi2 = 35.34;
  Double_t epsi1 = 0.1572; // PE(S1) per excited atoms
  Double_t epsi2 = 27.47;

  Double_t Eee = W/(1.+f)*(s2xyCorr/epsi2+s1_corr/epsi1);

  return Eee;
}
