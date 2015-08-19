#ifndef _DSTLoadClass_HH
#define _DSTLoadClass_HH

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "TF1.h"
#include "TH1.h"
#include "TH2F.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TChain.h"
#include "TRint.h"
#include "TString.h"
#include "TNtuple.h"
#include "TColor.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TPad.h"
#include "TStyle.h"
#include "TBox.h"

#include "dsttpcstruct.hh"
#include "dstodstruct.hh"

using namespace std;

class DSTLoadClass:public TObject
{
public:
  DSTLoadClass():
    DSTtree(0),dstinputdir("")
  {}

  virtual ~DSTLoadClass(){}

  DSTTPCEvent e;
  DSTODEvent t;
  
  bool VerifyDataFile(TString);
  int  Colors(int);
  void ReadDataFile(int, int);
  void Load_TPCDSTTree(DSTTPCEvent &);
  void Load_ODDSTTree(DSTODEvent &);
  void  SetDSTInputdir(string val) { dstinputdir=val; }
  string GetDSTInputdir() { return dstinputdir; }
  virtual void DSTProcess(int,int);

protected:
  TChain *DSTtree;

private:
  string dstinputdir;

  ClassDef(DSTLoadClass,0);
};
#endif /* _DSTLoadClass_HH */
