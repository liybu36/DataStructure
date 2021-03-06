#ifndef _SLADLoadClass_HH
#define _SLADLoadClass_HH

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TH2F.h"
#include "TH1F.h"
#include "TString.h"
#include "TRint.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TMath.h"
#include "TColor.h"

#include "sladodstruct.hh"
#include "sladtpcstruct.hh"

using namespace std;

class SLADLoadClass:public TObject
{
public:
  SLADLoadClass():
    tpc_chain(0),s2_fraction(0),masaxy(0),jasonxy(0),pulse_info(0),
    od_chain(0),allpulses_xy(0),allpulses_xyl_xy(0)
  {}
  
  SLADTPCEvent e;
  SLADODEvent  t;

  virtual ~SLADLoadClass(){}
  bool Load_TPCTree(TChain*, SLADTPCEvent&);
  bool Load_ODTree(TChain*, SLADODEvent&);
  bool VerifyDataFile(TString);
  void Create_TPCChain();
  bool Add_TPCTree(int);
  void Add_TPCFriend();
  void Create_ODChain();
  bool Add_ODTree(int);
  int Colors(int);
  void SetSLADTPCIndir(string var) { sladtpcindir=var; }
  string GetSLADTPCIndir() { return sladtpcindir; }
  void SetSLADODIndir(string var) { sladodindir=var; }
  string GetSLADODIndir() { return sladodindir; }
  virtual void SLADProcess(int,int);

protected:
  TChain *tpc_chain, *s2_fraction, *masaxy, *jasonxy, *pulse_info;
  TChain *allpulses_xy, *allpulses_xyl_xy;
  TChain *od_chain;
  
private:
  string sladtpcindir;
  string sladodindir;
  
  ClassDef(SLADLoadClass,0);
};

#endif /* _SLADLoadClass_HH */
