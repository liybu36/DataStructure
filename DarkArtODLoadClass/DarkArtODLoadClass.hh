#ifndef _DarkArtODLoadClass_HH
#define _DarkArtODLoadClass_HH
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

#include "darkartodstruct.hh"

using namespace std;

class DarkArtODLoadClass::public TObject
{
public:
  DarkArtODLoadClass():
    od_chain(0),darkartodindir("")
  {}

  virtual ~DarkArtODLoadClass(){}

  DarkArtODEvent t;
  
  bool multiplicity_cut(float,float,float);
  bool Load_DarkArtODTree(TChain*, DarkArtODEvent&);
  bool VerifyDataFile(TString);
  bool Add_DarkArtODTree(int);
  void Create_DarkArtODChain();
  void SetDarkArtODIndir(string var) { darkartodindir=var; }
  string GetDarkArtODIndir() { return darkartodindir; }
  virtual void DarkArtODProcess(int,int);
  
protected:
  TChain *od_chain;

private:
  string darkartodindir;

  ClassDef(DarkArtODLoadClass,0);
};
#endif /* _DarkArtODLoadClass_HH */
