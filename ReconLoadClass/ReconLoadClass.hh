#ifndef _ReconLoadClass_HH
#define _ReconLoadClass_HH

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

#include "reconstruct.hh"

using namespace std;
class ReconLoadClass:public TObject
{
public:
  ReconLoadClass():
    Recon(0),reconinputdir(""),reconmiddle("")
  {}

  virtual ~ReconLoadClass(){}

  ReconEvent r;
  
  void Load_ReconTree(ReconEvent &);
  bool VerifyDataFile(TString);
  int  Colors(int);
  void ReadDataFile(int, int);
  void  SetReconInputdir(string val) { reconinputdir=val; }
  string GetReconInputdir() { return reconinputdir; }
  void  SetReconmiddle(string val) { reconmiddle=val; }
  string GetReconmiddle() { return reconmiddle; }
  virtual void ReconProcess(int,int);
  
protected:
  TChain *Recon;
  
private:
  string reconinputdir;
  string reconmiddle;
  
  ClassDef(ReconLoadClass,0);
};
#endif /* _ReconLoadClass_HH */
