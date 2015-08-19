//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Aug  2 11:48:34 2014 by ROOT version 5.99/06
// from TTree SladEleMC_Selector/SladEleMC_Selector
// found on file: period_I+III_SLAD-1.4_run-ADAM_veto-v6.root
//////////////////////////////////////////////////////////

#ifndef SladEleMC_Selector_h
#define SladEleMC_Selector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TString.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include "TProfile2D.h"
#include "TProfile3D.h"
#include "TCutG.h"

#include <vector>


// Header file for the classes stored in the TTree if any.

class SladEleMC_Selector : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
//   XYReconstructor *fMyFcn;
   Bool_t          fIsFieldSet;         //flag for field setting
   Float_t         fEdrift;             // drift field in V/cm
   Float_t         fDriftTimeMax;       // maximum drift time
   Float_t         fT_drift_cut_min;       // drift time minimum cut value
   Float_t         fT_drift_cut_max;       // drift time maximum cut value
   Float_t         fS3SepTimeMin;       // drift time minimum S3 window
   Float_t         fS3SepTimeMax;       // drift time maximum S3 window

   Int_t           fNRequiredPulses;    // number of required pulses
//   static const TString timelabels[];
//   static const TString eventlabels[];

   Float_t         fS1corr_mean_Kr_peak;
   Float_t         fS1corr_sigma_Kr_peak;

   Float_t         fPrevious_total_s1;  // this is check for bug


// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           run_id;
   Int_t           subrun_id;
   Int_t           event_id;
   Double_t        livetime;
   Double_t        inhibittime;
   Float_t         acqui_window;
   Int_t           nchannel;
   short           baseline_not_found;
   Int_t           npulses;
   Int_t           has_s3;

   Float_t         total_s1;
   Float_t         total_s1_corr;
   Float_t         total_s1_top;
   Float_t         total_s1_bottom;
   Float_t         total_f90;
   Float_t         s1_start_time;
   Float_t         s1_end_time;
   Int_t           is_saturated_pulse0;

   Float_t         total_s2;
   Float_t         total_s2_corr;
   Float_t         total_s2_top;
   Float_t         total_s2_bottom;
   Float_t         total_s2_f90;
   Float_t         s2_start_time;
   Float_t         s2_end_time;
   Int_t           is_saturated_pulse1;

   Double_t        t_drift;
   Float_t         s1_max_frac;

   Short_t         selection_results[16];

   Float_t         max_s1_frac_cut_threshold99;
   Int_t           max_s1_frac_cut_exceeds99;

   Int_t           s2_max_chan;
   Float_t         s2_max_frac;
   Float_t         s2_ch_frac[38];

   Int_t           pulse_info_npulses;
   Float_t         pulse_info_fixed_int2[22];   //[pulse_info_npulses]

   Int_t           mc_event_id;
   Double_t        mc_npe;
   Double_t        mc_npe_fixed;
   Double_t        mc_npe_fixed2;
   Double_t        mc_signal;
   Double_t        mc_signal_fixed;
   Double_t        mc_signal_fixed2;
   std::vector<int>     mc_ch_id;
   std::vector<float>   mc_ch_npe;
   std::vector<float>   mc_ch_npe_fixed;
   std::vector<float>   mc_ch_npe_fixed2;
   std::vector<double>  mc_ch_signal;
   std::vector<double>  mc_ch_signal_fixed;
   std::vector<double>  mc_ch_signal_fixed2;


   // List of branches
   TBranch        *b_run_id;   //!
   TBranch        *b_subrun_id;   //!
   TBranch        *b_event_id;   //!
   TBranch        *b_livetime;   //!
   TBranch        *b_inhibittime;   //!
   TBranch        *b_acqui_window;   //!
   TBranch        *b_nchannel;   //!
   TBranch        *b_SumChannelHasNoBaseline;   //!
   TBranch        *b_n_phys_pulses;   //!
   TBranch        *b_has_s3;   //!

   TBranch        *b_total_s1;   //!
   TBranch        *b_total_s1_corr;   //!
   TBranch        *b_total_s1_top;   //!
   TBranch        *b_total_s1_bottom;   //!
   TBranch        *b_total_f90;   //!
   TBranch        *b_is_saturated_pulse0;   //!
   TBranch        *b_total_s2;   //!
   TBranch        *b_total_s2_corr;   //!
   TBranch        *b_total_s2_top;   //!
   TBranch        *b_total_s2_bottom;   //!
   TBranch        *b_total_s2_f90;   //!
   TBranch        *b_is_saturated_pulse1;   //!
   TBranch        *b_s1_start_time;   //!
   TBranch        *b_s1_end_time;   //!
   TBranch        *b_s2_start_time;   //!
   TBranch        *b_s2_end_time;   //!

   TBranch        *b_tdrift;   //!
//   TBranch        *b_selection_results;   //!

   TBranch        *b_max_s1_frac_cut_threshold;   //!
   TBranch        *b_max_s1_frac_cut_exceeds;   //!

   TBranch        *b_selection_results;   //!

   TBranch        *b_s2_max_chan;   //!
   TBranch        *b_s2_max_frac;   //!
   TBranch        *b_s2_chan;   //!



   SladEleMC_Selector(TTree * /*tree*/ =0) :
     fChain(0),
     fIsFieldSet(false), fEdrift(-1), fDriftTimeMax(-1), fT_drift_cut_min(-1), fT_drift_cut_max(-1), fS3SepTimeMin(-1), fS3SepTimeMax(-1), fNRequiredPulses(-1),
     fPrevious_total_s1(-1),
     fOutName(""),
     fOut_Tree(0),fCutg(0)
//     hRunTime(0), hEventConter(0),
//     hTotal_livetime(0),
//     hRun_dT_Trigger(0),
//     hRun_livetime(0), hRun_inhibittime(0),
//     hTDrift(0),
//     hS1Total_vs_F90(0), hTotalS2CorrvsS1(0),hTotalS1(0),
//     hsig_npe_vs_s1(0), hs1_npe_vs_s1(0), hs1_sig_vs_s1(0), hs1_sig_vs_s1length(0)
   { }
   virtual ~SladEleMC_Selector() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   void SetOutputFile(TString name){fOutName = name;}

private:
   TString fOutName;

   TTree      *fOut_Tree; //!

   TCutG      *fCutg;      //!


   Bool_t          IsValidEvent();
   Bool_t          IsEventOK_Default();
   Bool_t          IsEventOK();
   void            FillHistograms();
   void            BookHistograms();
   void            SetCutG4Outliers();
   void            SetDriftFieldConf(Int_t Edrift, Int_t RunId);
   Double_t        SetElectronLifetime(Int_t RunId);
   Bool_t          CheckFieldSetting(Float_t acqui_window);
   Int_t           GetFieldFromAcquisitionWindow(Float_t acqui_window);
   Float_t         GetExpectedAcquisitionWindow(Int_t Edrift);
   Bool_t          HasS3(Float_t s2_starttime);
   Double_t        s1_corr_factor(Double_t t_drift_max, Double_t t_drift);
   Double_t        s1_TBAcorr_factor(Double_t s1_top, Double_t s1_bottom, Double_t s1);
   Float_t         GetXYVariance();
   Double_t        XYCorrection4S2(Double_t x, Double_t y);
   Double_t        GetRecoilEnergy(Double_t s1_corr, Double_t s2xyCorr); //function returns recoil energy with give corrected S2 & S1

//   TH1D* hRunTime, *hEventConter;
//   TH1F* hTotal_livetime;
//   TH2D *hRun_dT_Trigger;
//   TH2D *hRun_livetime, *hRun_inhibittime;
//   TH1D *hTDrift;
//   TH2D *hS1Total_vs_F90, *hTotalS2CorrvsS1;
//   TH1D *hTotalS1;
//
//   TH2D *hsig_npe_vs_s1, *hs1_npe_vs_s1, *hs1_sig_vs_s1, *hs1_sig_vs_s1length;


   ClassDef(SladEleMC_Selector,0);
};

#endif

#ifdef SladEleMC_Selector_cxx
void SladEleMC_Selector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchStatus("*",0); //disable all

//   b_run_id->SetStatus(1);
   fChain->SetBranchAddress("run_id", &run_id, &b_run_id);
   fChain->SetBranchAddress("subrun_id", &subrun_id, &b_subrun_id);
   fChain->SetBranchAddress("event_id", &event_id, &b_event_id);
   fChain->SetBranchAddress("lifetime", &livetime, &b_livetime);
   fChain->SetBranchAddress("inhibittime", &inhibittime, &b_inhibittime);
   fChain->SetBranchAddress("acqui_window", &acqui_window, &b_acqui_window);
   fChain->SetBranchAddress("nchannel", &nchannel, &b_nchannel);
   fChain->SetBranchAddress("SumChannelHasNoBaseline", &baseline_not_found, &b_SumChannelHasNoBaseline);
   fChain->SetBranchAddress("n_phys_pulses", &npulses, &b_n_phys_pulses);
   fChain->SetBranchAddress("has_s3", &has_s3, &b_has_s3);

   fChain->SetBranchAddress("total_s1", &total_s1, &b_total_s1);
   fChain->SetBranchAddress("total_s1_corr", &total_s1_corr, &b_total_s1_corr);
   fChain->SetBranchAddress("total_s1_top", &total_s1_top, &b_total_s1_top);
   fChain->SetBranchAddress("total_s1_bottom", &total_s1_bottom, &b_total_s1_bottom);
   fChain->SetBranchAddress("total_f90", &total_f90, &b_total_f90); // total_f90_fixed should be same as total_f90;
   fChain->SetBranchAddress("is_saturated_pulse0", &is_saturated_pulse0, &b_is_saturated_pulse0);
   fChain->SetBranchAddress("total_s2", &total_s2, &b_total_s2);
   fChain->SetBranchAddress("total_s2_corr", &total_s2_corr, &b_total_s2_corr);
   fChain->SetBranchAddress("total_s2_top", &total_s2_top, &b_total_s2_top);
   fChain->SetBranchAddress("total_s2_bottom", &total_s2_bottom, &b_total_s2_bottom);
   fChain->SetBranchAddress("total_s2_f90", &total_s2_f90, &b_total_s2_f90);
   fChain->SetBranchAddress("is_saturated_pulse1", &is_saturated_pulse1, &b_is_saturated_pulse1);
   fChain->SetBranchAddress("s1_start_time", &s1_start_time, &b_s1_start_time);
   fChain->SetBranchAddress("s1_end_time", &s1_end_time, &b_s1_end_time);
   fChain->SetBranchAddress("s2_start_time", &s2_start_time, &b_s2_start_time);
   fChain->SetBranchAddress("s2_end_time", &s2_end_time, &b_s2_end_time);

   fChain->SetBranchAddress("tdrift", &t_drift, &b_tdrift);
   fChain->SetBranchAddress("s1_max_frac", &s1_max_frac);
   fChain->SetBranchAddress("selection_results", selection_results, &b_selection_results);

   fChain->SetBranchAddress("max_s1_frac_cut_threshold99", &max_s1_frac_cut_threshold99, &b_max_s1_frac_cut_threshold);
   fChain->SetBranchAddress("max_s1_frac_cut_exceeds99", &max_s1_frac_cut_exceeds99, &b_max_s1_frac_cut_exceeds);

   fChain->SetBranchAddress("s2_max_chan", &s2_max_chan, &b_s2_max_chan);
   fChain->SetBranchAddress("s2_max_frac", &s2_max_frac, &b_s2_max_frac);
   fChain->SetBranchAddress("s2_chan", s2_ch_frac, &b_s2_chan);

   fChain->SetBranchAddress("pulse_info_npulses", &pulse_info_npulses);
   fChain->SetBranchAddress("pulse_info_fixed_int2", pulse_info_fixed_int2);

   fChain->SetBranchAddress("event_id", &mc_event_id);
   fChain->SetBranchAddress("npe", &mc_npe);
   fChain->SetBranchAddress("npe_fixed", &mc_npe_fixed);
   fChain->SetBranchAddress("npe_fixed2", &mc_npe_fixed2);
   fChain->SetBranchAddress("signal", &mc_signal);
   fChain->SetBranchAddress("signal_fixed", &mc_signal_fixed);
   fChain->SetBranchAddress("signal_fixed2", &mc_signal_fixed2);
   fChain->SetBranchAddress("ch_id", &mc_ch_id);
   fChain->SetBranchAddress("ch_npe", &mc_ch_npe);
   fChain->SetBranchAddress("ch_npe_fixed", &mc_ch_npe_fixed);
   fChain->SetBranchAddress("ch_npe_fixed2", &mc_ch_npe_fixed2);
   fChain->SetBranchAddress("ch_signal", &mc_ch_signal);
   fChain->SetBranchAddress("ch_signal_fixed", &mc_ch_signal_fixed);
   fChain->SetBranchAddress("ch_signal_fixed2", &mc_ch_signal_fixed2);

//   fChain->SetBranchAddress("radius", &radius);
}

Bool_t SladEleMC_Selector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef SladEleMC_Selector_cxx
