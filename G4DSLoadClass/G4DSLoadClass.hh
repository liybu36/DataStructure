#ifndef _G4DSLoadClass_HH
#define _G4DSLoadClass_HH

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

#include "dstreestruct.hh"
using namespace std;

class G4DSLoadClass:public TObject
{
public:
  G4DSLoadClass():
    dstree(0),g4dsinputdir(""),g4dsmiddle("")
  {}

  virtual ~G4DSLoadClass(){}

  dstreeEvent d;

  void Load_G4DSTree(dstreeEvent &);
  bool VerifyDataFile(TString);
  int  Colors(int);
  void ReadDataFile(int, int);
  void  SetG4DSInputdir(string val) { g4dsinputdir=val; }
  string GetG4DSInputdir() { return g4dsinputdir; }
  void  SetG4DSmiddle(string val) { g4dsmiddle=val; }
  string GetG4DSmiddle() { return g4dsmiddle; }
  virtual void G4DSProcess(int,int);

protected:
  TChain *dstree;

private:
  string g4dsinputdir;
  string g4dsmiddle;

  ClassDef(G4DSLoadClass,0);
};
#endif /* _G4DSLoadClass_HH */
