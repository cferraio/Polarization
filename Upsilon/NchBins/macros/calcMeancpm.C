#include "rootIncludes.inc"

#include "TLorentzVector.h"
#include "TSystem.h"

enum{L,R};
const Int_t kNbSpecies = 3;
enum{UPS1S, UPS2S, UPS3S};
int numEvents_[4][100][100];
double meancpm[4][100][100];
double meanPt[4][100][100];
double BackgroundFrac[4][100][100];


void calcMeanPt(Int_t iRapBin = 1,
		      Int_t iPTBin = 1,
		      Int_t icpmBin = 1,
		      Double_t nSigma = 2.,
		      Int_t nUpsState=0,//[0]... 1S, [1]... 2S, [2]... 3S
		      Int_t output=999,
		      Double_t fracL = 0.5){


  Char_t fileNameIn[100];
  sprintf(fileNameIn, "AllStates_%1.2fSigma_FracLSB%dPercent/data_%dSUps_rap%d_pT%d_cpm%d.root", nSigma, int(fracL*100), nUpsState+1, iRapBin, iPTBin, icpmBin);
  //==============================
  //read inputs from input file:
  TFile *fIn = new TFile(fileNameIn);
  TLorentzVector *lepP;
  TLorentzVector *lepN;
  TTree *treeIn = (TTree *) gDirectory->Get("selectedData");
  if(gDirectory->Get("selectedData")==NULL){
    return;
  }

  //==============================

  //==========================================================
  //reading fit parameters to establish signal mass window
  //as well as the L and R sideband window for the 3D BG histo
  //==========================================================

  lepP = 0; lepN = 0;
  treeIn->SetBranchAddress("lepP", &lepP);
  treeIn->SetBranchAddress("lepN", &lepN);
  TLorentzVector *onia = new TLorentzVector();
  treeOut->Branch("CPM", &CPM, "CPM/D");

  TH1D*  onia_cpmhisto   = new TH1D( "onia_cpmhisto","", 100, 0, 100);
  TH1D*  onia_pThisto   = new TH1D( "onia_pThisto","", 100, 0, 100);
  TH1D*  onia_raphisto   = new TH1D( "onia_raphisto","", 100, 0, 1.2);

  TH1D* backfrac_ = (TH1D*)fIn->Get("background_fraction");
  double backfrac = backfrac_->GetBinContent(1);

  int Ncut=0;
  double cpmcut=0;
  bool Cut(false);

  Double_t onia_cpm;
  Double_t onia_Pt;
  Double_t onia_Rap;
  for(int iEn = 0; iEn < treeIn->GetEntries(); iEn++){
    Long64_t iEntry = treeIn->LoadTree(iEn);
    treeIn->GetEntry(iEntry);

    *onia = *(lepP) + *(lepN);
    onia_cpm = vertexWeight;
    onia_Pt = onia->Pt();
    onia_Rap = onia->Rapidity();

    Cut=false;
    	if(lepP->Pt() < pTcut || lepN->Pt() < pTcut && vertexWeight < cpmcut) {Ncut++;continue;}

       	onia_cpmhisto->Fill( onia_cpm );
       	onia_pThisto->Fill( onia_Pt );
       	onia_raphisto->Fill( TMath::Abs(onia_Rap) );

  }

	char filename[200];
	sprintf(filename, "AllStates_%1.2fSigma_FracLSB%dPercent/meancpmlll.txt", nSigma, int(fracL*100));



  if(output==0) {cout<<onia_cpmhisto->GetMean();meancpm[nUpsState][iPTBin][icpmBin]=onia_cpmhisto->GetMean();}
  if(output==1) {cout<<int((treeIn->GetEntries()-Ncut)*(1-backfrac)); numEvents_[nUpsState][iPTBin][icpmBin]=int((treeIn->GetEntries()-Ncut)*(1-backfrac));}
  if(output==2) {cout<<backfrac;BackgroundFrac[nUpsState][iPTBin][icpmBin]=100*backfrac;}
  if(output==5) {cout<<onia_raphisto->GetMean();meanRap[nUpsState][iPTBin][icpmBin]=onia_pThisto->GetMean();}

  TH1D* hMassScanInfo = (TH1D*)fIn->Get("hMassScanInfo");
  if(output==3) {cout<<hMassScanInfo->GetBinContent(1);}
  if(output==4) {cout<<hMassScanInfo->GetBinContent(2);}



  fIn->Close();

}
