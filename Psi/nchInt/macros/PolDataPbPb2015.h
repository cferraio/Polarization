//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Nov 11 12:59:09 2016 by ROOT version 5.32/00
// from TTree myTree/My TTree of dimuons
// found on file: /data/users/ferraioc/Polarization/2015PbPb/OniaTree_HIOniaL1DoubleMu0B_HIRun2015-PromptReco-v1_Run_263322_263757.root
//////////////////////////////////////////////////////////

#ifndef PolData_h
#define PolData_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include <Riostream.h>
#include <TROOT.h>

#include <TH1.h>
#include <TH2D.h>

#include <TBranch.h>
#include <TCanvas.h>
#include "TClonesArray.h"
#include <TDirectory.h>
#include <TFile.h>
#include "TH1F.h"
#include <TLatex.h>
#include <TLegend.h>
#include "TLorentzVector.h"
#include <TMath.h>
#include "TRandom.h"
#include <TStyle.h>
#include <TSystem.h>
#include "TTree.h"
#include "TString.h"

// miscellaneous  
#include <fstream>
#include <map>
#include <iostream>
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <vector>

// Header file for the classes stored in the TTree if any.
#include <TClonesArray.h>

// Fixed size dimensions of array or collections stored in the TTree if any.

class PolData {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
	  static const int NMAX=100;
  UInt_t eventNb;
  UInt_t runNb;
  Int_t Centrality;
  ULong64_t HLTriggers;
  Int_t Reco_QQ_matchNtrkVtx;
  Int_t Reco_QQ_size;
  ULong64_t Reco_QQ_trig[NMAX];
  Int_t Reco_QQ_type[NMAX];
  Int_t Reco_QQ_sign[NMAX];
  Int_t Reco_QQ_NtrkDeltaR03[NMAX];
     Float_t         Jpsict[NMAX];   //[Reco_QQ_size]
   Float_t         JpsictErr[NMAX];   //[Reco_QQ_size]

  Int_t Reco_QQ_NtrkDeltaR04[NMAX];
  Int_t Reco_QQ_NtrkDeltaR05[NMAX];

  int JpsiVprob[NMAX];
  TClonesArray *Reco_QQ_4mom = 0;
  TClonesArray *Reco_QQ_mupl_4mom = 0;
  TClonesArray *Reco_QQ_mumi_4mom = 0;

  Int_t Reco_mu_size;
  Int_t Reco_mu_type[NMAX];
  Int_t Reco_mu_charge[NMAX];
  TClonesArray *Reco_mu_4mom = 0;
  int nPlusMu;
  int nMinusMu;
  float muPt[NMAX];
  float muEta[NMAX];
  float muPhi[NMAX];
  Float_t         Reco_QQ_ctau3D[NMAX];   //[Reco_QQ_size]
   Float_t         Reco_QQ_ctauErr3D[NMAX];   //[Reco_QQ_size]
  //Int_t nReco_QQ;
  Float_t invariantMass;
  Int_t QQtrig;
  Int_t QQsign;
  Int_t QQTrkDr03;
  Int_t QQTrkDr04;
  Int_t QQTrkDr05;
  float weight;
  float weight2;
  Float_t upsPt;
  Float_t upsEta;
  Float_t upsPhi;
  Float_t upsRapidity;	
  Float_t vProb;
  Float_t muPlusPt;
  Float_t muMinusPt;
  Float_t JpsiMassErr;
  Float_t muPlusEta;
  Float_t muMinusEta;
  Float_t muPlusPhi;
  Float_t muMinusPhi;
  Float_t RmuPlusPhi = 0;
  Float_t RmuMinusPhi = 0;
  Int_t upsMatchNtrkVtx;
  // centrliaty extra stuff
  Int_t Npix, NpixelTracks, Ntracks;
  Float_t zVtx;
  Float_t SumET_HF, SumET_HFplus, SumET_HFminus, SumET_HFplusEta4, SumET_HFminusEta4, SumET_EB, SumET_ET, SumET_EE, SumET_EEplus, SumET_EEminus, SumET_ZDC, SumET_ZDCplus, SumET_ZDCminus;

  // track extra stuff
  static const int NTRKMAX=100000;
  int Reco_trk_size=0;
  TClonesArray *Reco_trk_4mom = 0;
  float trkPt[NTRKMAX];
  float trkEta[NTRKMAX];
  float trkPhi[NTRKMAX];
  
   // List of branches
   TBranch        *b_eventNb;   //!
   TBranch        *b_runNb;   //!
   TBranch        *b_LS;   //!
   TBranch        *b_zVtx;   //!
   TBranch        *b_nPV;   //!
   TBranch        *b_Centrality;   //!
   TBranch        *b_nTrig;   //!
   TBranch        *b_trigPrescale;   //!
   TBranch        *b_HLTriggers;   //!
   TBranch        *b_Npix;   //!
   TBranch        *b_NpixelTracks;   //!
   TBranch        *b_Ntracks;   //!
   TBranch        *b_SumET_HF;   //!
   TBranch        *b_SumET_HFplus;   //!
   TBranch        *b_SumET_HFminus;   //!
   TBranch        *b_SumET_HFplusEta4;   //!
   TBranch        *b_SumET_HFminusEta4;   //!
   TBranch        *b_SumET_ET;   //!
   TBranch        *b_SumET_EE;   //!
   TBranch        *b_SumET_EB;   //!
   TBranch        *b_SumET_EEplus;   //!
   TBranch        *b_SumET_EEminus;   //!
   TBranch        *b_SumET_ZDC;   //!
   TBranch        *b_SumET_ZDCplus;   //!
   TBranch        *b_SumET_ZDCminus;   //!
   TBranch        *b_nEP;   //!
   TBranch        *b_rpAng;   //!
   TBranch        *b_rpSin;   //!
   TBranch        *b_rpCos;   //!
   TBranch        *b_Reco_QQ_size;   //!
   TBranch        *b_Reco_QQ_type;   //!
   TBranch        *b_Reco_QQ_sign;   //!
   TBranch        *b_Reco_QQ_4mom;   //!
   TBranch        *b_Reco_QQ_mupl_4mom;   //!
   TBranch        *b_Reco_QQ_mumi_4mom;   //!
   TBranch        *b_Reco_QQ_trig;   //!
   TBranch        *b_Reco_QQ_mupl_trig;   //!
   TBranch        *b_Reco_QQ_mumi_trig;   //!
   TBranch        *b_Reco_QQ_isCowboy;   //!
   TBranch        *b_Jpsict;   //!
   TBranch        *b_JpsictErr;   //!
   TBranch        *b_Reco_QQ_ctau3D;   //!
   TBranch        *b_Reco_QQ_ctauErr3D;   //!
   TBranch        *b_JpsiVprob;   //!
   TBranch        *b_Reco_QQ_dca;   //!
   TBranch        *b_JpsiMassErr;   //!
   TBranch        *b_Reco_QQ_vtx;   //!
   TBranch        *b_Reco_QQ_Ntrk;   //!
   TBranch        *b_Reco_QQ_mupl_SelectionType;   //!
   TBranch        *b_Reco_QQ_mumi_SelectionType;   //!
   TBranch        *b_Reco_QQ_mupl_isGoodMuon;   //!
   TBranch        *b_Reco_QQ_mumi_isGoodMuon;   //!
   TBranch        *b_Reco_QQ_mupl_highPurity;   //!
   TBranch        *b_Reco_QQ_mumi_highPurity;   //!
   TBranch        *b_Reco_QQ_mupl_TrkMuArb;   //!
   TBranch        *b_Reco_QQ_mumi_TrkMuArb;   //!
   TBranch        *b_Reco_QQ_mupl_TMOneStaTight;   //!
   TBranch        *b_Reco_QQ_mumi_TMOneStaTight;   //!
   TBranch        *b_Reco_QQ_mupl_nPixValHits;   //!
   TBranch        *b_Reco_QQ_mumi_nPixValHits;   //!
   TBranch        *b_Reco_QQ_mupl_nMuValHits;   //!
   TBranch        *b_Reco_QQ_mumi_nMuValHits;   //!
   TBranch        *b_Reco_QQ_mupl_nTrkHits;   //!
   TBranch        *b_Reco_QQ_mumi_nTrkHits;   //!
   TBranch        *b_Reco_QQ_mupl_normChi2_inner;   //!
   TBranch        *b_Reco_QQ_mumi_normChi2_inner;   //!
   TBranch        *b_Reco_QQ_mupl_normChi2_global;   //!
   TBranch        *b_Reco_QQ_mumi_normChi2_global;   //!
   TBranch        *b_Reco_QQ_mupl_nPixWMea;   //!
   TBranch        *b_Reco_QQ_mumi_nPixWMea;   //!
   TBranch        *b_Reco_QQ_mupl_nTrkWMea;   //!
   TBranch        *b_Reco_QQ_mumi_nTrkWMea;   //!
   TBranch        *b_Reco_QQ_mupl_StationsMatched;   //!
   TBranch        *b_Reco_QQ_mumi_StationsMatched;   //!
   TBranch        *b_Reco_QQ_mupl_dxy;   //!
   TBranch        *b_Reco_QQ_mumi_dxy;   //!
   TBranch        *b_Reco_QQ_mupl_dxyErr;   //!
   TBranch        *b_Reco_QQ_mumi_dxyErr;   //!
   TBranch        *b_Reco_QQ_mupl_dz;   //!
   TBranch        *b_Reco_QQ_mumi_dz;   //!
   TBranch        *b_Reco_QQ_mupl_dzErr;   //!
   TBranch        *b_Reco_QQ_mumi_dzErr;   //!
   TBranch        *b_Reco_QQ_mupl_pt_inner;   //!
   TBranch        *b_Reco_QQ_mumi_pt_inner;   //!
   TBranch        *b_Reco_QQ_mupl_pt_global;   //!
   TBranch        *b_Reco_QQ_mumi_pt_global;   //!
   TBranch        *b_Reco_QQ_mupl_ptErr_inner;   //!
   TBranch        *b_Reco_QQ_mumi_ptErr_inner;   //!
   TBranch        *b_Reco_QQ_mupl_ptErr_global;   //!
   TBranch        *b_Reco_QQ_mumi_ptErr_global;   //!
   TBranch        *b_Reco_mu_size;   //!
   TBranch        *b_Reco_mu_type;   //!
   TBranch        *b_Reco_mu_SelectionType;   //!
   TBranch        *b_Reco_mu_charge;   //!
   TBranch        *b_Reco_mu_4mom;   //!
   TBranch        *b_Reco_mu_trig;   //!
   TBranch        *b_Reco_mu_isGoodMuon;   //!
   TBranch        *b_Reco_mu_highPurity;   //!
   TBranch        *b_Reco_mu_TrkMuArb;   //!
   TBranch        *b_Reco_mu_TMOneStaTight;   //!
   TBranch        *b_Reco_mu_nPixValHits;   //!
   TBranch        *b_Reco_mu_nMuValHits;   //!
   TBranch        *b_Reco_mu_nTrkHits;   //!
   TBranch        *b_Reco_mu_normChi2_inner;   //!
   TBranch        *b_Reco_mu_normChi2_global;   //!
   TBranch        *b_Reco_mu_nPixWMea;   //!
   TBranch        *b_Reco_mu_nTrkWMea;   //!
   TBranch        *b_Reco_mu_StationsMatched;   //!
   TBranch        *b_Reco_mu_dxy;   //!
   TBranch        *b_Reco_mu_dxyErr;   //!
   TBranch        *b_Reco_mu_dz;   //!
   TBranch        *b_Reco_mu_dzErr;   //!
   TBranch        *b_Reco_mu_pt_inner;   //!
   TBranch        *b_Reco_mu_pt_global;   //!
   TBranch        *b_Reco_mu_ptErr_inner;   //!
   TBranch        *b_Reco_mu_ptErr_global;   //!

   PolData(TTree *tree=0);
   virtual ~PolData();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(int selDimuType, bool rejectCowboys, int FidCuts, bool MC, bool RequestTrigger, bool removeEta0p2_0p3, bool cutDeltaREllDpt, bool officialMC);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef PolData_cxx
PolData::PolData(TTree *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("TTree_Onia2MuMu_V8_PromptReco_v4.root");
      if (!f) {
         f = new TFile("TTree_Onia2MuMu_V8_PromptReco_v4.root");
      }
      tree = (TTree*)gDirectory->Get("myTree"); 

   }
   Init(tree);
}

PolData::~PolData()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t PolData::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t PolData::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void PolData::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   Reco_QQ_4mom = 0;
   Reco_QQ_mupl_4mom = 0;
   Reco_QQ_mumi_4mom = 0;

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);


	
  fChain->SetBranchAddress("Centrality",    &Centrality,   &b_Centrality);
  fChain->SetBranchAddress("eventNb",       &eventNb,      &b_eventNb);
  fChain->SetBranchAddress("runNb",         &runNb,        &b_runNb);
  fChain->SetBranchAddress("HLTriggers",    &HLTriggers,   &b_HLTriggers);
  fChain->SetBranchAddress("Reco_QQ_size",  &Reco_QQ_size, &b_Reco_QQ_size);
  fChain->SetBranchAddress("Reco_QQ_trig",  &Reco_QQ_trig, &b_Reco_QQ_trig);
  fChain->SetBranchAddress("Reco_QQ_type",  &Reco_QQ_type, &b_Reco_QQ_type);
  fChain->SetBranchAddress("Reco_QQ_sign",  &Reco_QQ_sign, &b_Reco_QQ_sign);
  fChain->SetBranchAddress("Reco_QQ_VtxProb", &JpsiVprob, &b_JpsiVprob);
  fChain->SetBranchAddress("Reco_QQ_4mom",      &Reco_QQ_4mom,      &b_Reco_QQ_4mom);
  fChain->SetBranchAddress("Reco_QQ_mupl_4mom", &Reco_QQ_mupl_4mom, &b_Reco_QQ_mupl_4mom);
  fChain->SetBranchAddress("Reco_QQ_mumi_4mom", &Reco_QQ_mumi_4mom, &b_Reco_QQ_mumi_4mom);
  
  fChain->SetBranchAddress("Reco_mu_size",  &Reco_mu_size,   &b_Reco_mu_size);
  fChain->SetBranchAddress("Reco_mu_type",  &Reco_mu_type,   &b_Reco_mu_type);
  fChain->SetBranchAddress("Reco_mu_charge",&Reco_mu_charge, &b_Reco_mu_charge);
  fChain->SetBranchAddress("Reco_mu_4mom",  &Reco_mu_4mom,   &b_Reco_mu_4mom);
  
  fChain->SetBranchAddress("Reco_mu_4mom",  &Reco_mu_4mom,   &b_Reco_mu_4mom);

  fChain->SetBranchAddress("Reco_QQ_ctau", &Jpsict, &b_Jpsict);
  fChain->SetBranchAddress("Reco_QQ_ctauErr", &JpsictErr, &b_JpsictErr);
  
  fChain->SetBranchAddress("Reco_QQ_MassErr", &JpsiMassErr, &b_JpsiMassErr);


  // extra centrality variables
  fChain->SetBranchAddress("zVtx",             &zVtx,              &b_zVtx);
  fChain->SetBranchAddress("Npix",             &Npix,              &b_Npix);
  fChain->SetBranchAddress("NpixelTracks",     &NpixelTracks,      &b_NpixelTracks);
  fChain->SetBranchAddress("Ntracks",          &Ntracks,           &b_Ntracks);
  fChain->SetBranchAddress("SumET_HF",         &SumET_HF,          &b_SumET_HF);
  fChain->SetBranchAddress("SumET_HFplus",     &SumET_HFplus,      &b_SumET_HFplus);
  fChain->SetBranchAddress("SumET_HFminus",    &SumET_HFminus,     &b_SumET_HFminus);
  fChain->SetBranchAddress("SumET_HFplusEta4", &SumET_HFplusEta4,  &b_SumET_HFplusEta4);
  fChain->SetBranchAddress("SumET_HFminusEta4",&SumET_HFminusEta4, &b_SumET_HFminusEta4);
  fChain->SetBranchAddress("SumET_ET",         &SumET_ET,          &b_SumET_ET);
  fChain->SetBranchAddress("SumET_EE",         &SumET_EE,          &b_SumET_EE);
  fChain->SetBranchAddress("SumET_EB",         &SumET_EB,          &b_SumET_EB);
  fChain->SetBranchAddress("SumET_EEplus",     &SumET_EEplus,      &b_SumET_EEplus);
  fChain->SetBranchAddress("SumET_EEminus",    &SumET_EEminus,     &b_SumET_EEminus);
  fChain->SetBranchAddress("SumET_ZDC"    ,    &SumET_ZDC,         &b_SumET_ZDC);
  fChain->SetBranchAddress("SumET_ZDCplus",    &SumET_ZDCplus,     &b_SumET_ZDCplus);
  fChain->SetBranchAddress("SumET_ZDCminus",   &SumET_ZDCminus,    &b_SumET_ZDCminus);
  
  // extra track variable  
   Notify();
}

Bool_t PolData::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void PolData::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t PolData::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef PolData_cxx
