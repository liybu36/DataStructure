#ifndef _BaseClass_HH
#define _BaseClass_HH
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

#include "TChain.h"
#include "TTree.h"
#include "TString.h"
#include "TColor.h"

using namespace std;
class BaseClass:public TObject
{
public:
  BaseClass():
  {}
  
  virtual ~BaseClass(){}

  void   SetMCinputdir(string val) { MCinputdir=val; }
  string GetMCinputdir() { return MCinputdir; }
  void   SetMCFile(string val) { MCFile=val; }
  string GetMCFile() { return MCFile; }
  string GetRealinputdir() { return Realinputdir; }
  void   SetRealinputdir(string val) { Realinputdir=val; }
  void   SetRealFile(string val) { RealFile=val; }
  string GetRealFile() { return RealFile; }
  string Getoutputdir() { return outputdir; }
  void   Setoutputdir(string val) { outputdir=val; }
  void   SetOutFile(string val) { OutFile=val; }
  string GetOutFile() { return OutFile; }

  bool VerifyDataFile(TString);
  int Colors(int);

private:
  string MCFile;
  string MCinputdir;
  string RealFile;
  string Realinputdir;
  string outputdir;
  string OutFile;

  ClassDef(BaseClass,0)
};

#endif /* _BaseClass_HH */
