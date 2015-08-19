#include "ReconLoadClass.hh"

using namespace std;
ClassImp(ReconLoadClass);
void ReconLoadClass::Load_ReconTree(ReconEvent & g)
{
  Recon->SetBranchAddress("event_id", &g.event_id);
  Recon->SetBranchAddress("event_pdg", &g.event_pdg);
  Recon->SetBranchAddress("event_broken", &g.event_broken);
  Recon->SetBranchAddress("volume", &g.volume);
  Recon->SetBranchAddress("n_active", &g.n_active);
  Recon->SetBranchAddress("et", &g.et);
  Recon->SetBranchAddress("ex", &g.ex);
  Recon->SetBranchAddress("ey", &g.ey);
  Recon->SetBranchAddress("ez", &g.ez);
  Recon->SetBranchAddress("edep", &g.edep);
  Recon->SetBranchAddress("eqch", &g.eqch);
  Recon->SetBranchAddress("quenchingfactor", &g.quenchingfactor);
}

void ReconLoadClass::ReconProcess(int start, int end)
{
  ReadDataFile(start,end);
  Recon = new TChain("Recon");
  Load_ReconTree(r);
}

void ReconLoadClass::ReadDataFile(int start, int end)
{
  string indir = GetReconInputdir();
  string middle= GetReconmiddle();
  string last="_clustered.root";
  for(int i=start; i<=end; i++)
    {
      TString filename;
      if(i==0)
	filename.Form("%s%s",middle.c_str(),last.c_str());
      else
	filename.Form("%s_v%d%s",middle.c_str(),i,last.c_str());
      filename.Prepend(indir.c_str());
      if(!VerifyDataFile(filename))
	continue;
      else
	DSTtree->Add(filename);
    }
}

int ReconLoadClass::Colors(int pos)
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

bool ReconLoadClass::VerifyDataFile(TString mainfile)
{
  ifstream NameCheck;
  NameCheck.open(mainfile.Data());
  if(!NameCheck.good())
    { NameCheck.close();
      return false;
    }
  else{
    TFile *f = new TFile(mainfile);
    if(!f->IsOpen() || f->IsZombie())
      {
	NameCheck.close();
	f->Close();
	return false;
      }
    else{
      cout<<"Processing the data file: "<<mainfile<<endl;
      NameCheck.close();
      f->Close();
      return true;
    }
  }
}



