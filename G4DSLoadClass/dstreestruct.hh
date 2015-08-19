#ifndef _dstreestruct_HH
#define _dstreestruct_HH

#include <iostream>

struct dstreeEvent{
  dstreeEvent():
    ev(0),pdg(0),ene0(0),tpcene(0),vetoene(0),muene(0),x(0),
    y(0),z(0),r(0),px(0),py(0),pz(0),bx(0),by(0),bz(0),
    npe(0),mupe(0),vnpe(0),nph(0),ndaughters(0),ndeposits(0)
  {}

  Int_t           ev;
  Int_t           pdg;
  Float_t         ene0;
  Float_t         tpcene;
  Float_t         vetoene;
  Float_t         muene;
  Float_t         x;
  Float_t         y;
  Float_t         z;
  Float_t         r;
  Float_t         px;
  Float_t         py;
  Float_t         pz;
  Float_t         bx;
  Float_t         by;
  Float_t         bz;
  Int_t           npe;
  Int_t           munpe;
  Int_t           vnpe;
  Int_t           nph;
  Int_t           ndaughters;
  Int_t           ndeposits;
  Int_t           dau_pdg[1];   //[ndaughters]
  Int_t           dau_trackid[1];   //[ndaughters]
  Int_t           dau_parenttrackid[1];   //[ndaughters]
  Double_t        dau_time[1];   //[ndaughters]
  Float_t         dau_ene[1];   //[ndaughters]
  Float_t         dau_x[1];   //[ndaughters]
  Float_t         dau_y[1];   //[ndaughters]
  Float_t         dau_z[1];   //[ndaughters]
  Float_t         dau_r[1];   //[ndaughters]
  Float_t         dau_px[1];   //[ndaughters]
  Float_t         dau_py[1];   //[ndaughters]
  Float_t         dau_pz[1];   //[ndaughters]
  Int_t           dep_pdg[579];   //[ndeposits]
  Int_t           dep_mat[579];   //[ndeposits]
  Int_t           dep_track[579];   //[ndeposits]
  Int_t           dep_parenttrack[579];   //[ndeposits]
  Double_t        dep_time[579];   //[ndeposits]
  Float_t         dep_ene[579];   //[ndeposits]
  Float_t         dep_x[579];   //[ndeposits]
  Float_t         dep_y[579];   //[ndeposits]
  Float_t         dep_z[579];   //[ndeposits]
  Float_t         dep_r[579];   //[ndeposits]        
  Int_t           ph_volume[1];   //[nph]
  Float_t         ph_wl[1];   //[nph]
  Float_t         ph_x[1];   //[nph]
  Float_t         ph_y[1];   //[nph]
  Float_t         ph_z[1];   //[nph]
  Double_t        ph_time[1];   //[nph]    

};
#endif /* _dstreestruct_HH */
