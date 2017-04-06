#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "rootIncludes.inc"
#include "commonVar.h"

#include "TH2.h"

enum{L,R};
Char_t const *bgLabel[2] = {"L", "R"};
TH2F *hCosThetaPhi[onia::kNbRapForPTBins+1][onia::kNbPTMaxBins+1][onia::NXBINS+1][onia::kNbFrames][2];
void LoadHistos(Int_t iRapBin, Int_t iPTBin, Int_t iCPMBin);
void PlotHistos(Int_t iRapBin, Int_t iPTBin, Int_t iCPMBin, Int_t iFrame, Int_t iWindow);
//===========================
int main(){

	gStyle->SetPalette(1);

	

  for(int iRap = 1; iRap <= onia::kNbRapForPTBins; iRap++){
    Int_t max = onia::kNbPTBins[iRap]+1;
    for(int iPT = 1; iPT < max; iPT++){
      for(int iCPM = 1; iCPM < onia::NXBINS+1; iCPM++){

      LoadHistos(iRap, iPT, iCPM);

        for(int iFrame = 0; iFrame < onia::kNbFrames; iFrame++){

	  PlotHistos(iRap, iPT, iCPM, iFrame, L);

	  	  		cout<<"L irap = "<<iRap<<" ipt = "<<iPT<<" icpm = "<<iCPM<<endl;
	  PlotHistos(iRap, iPT, iCPM, iFrame, R);

	  			cout<<"R irap = "<<iRap<<" ipt = "<<iPT<<" icpm = "<<iCPM<<endl;
	    }
      }
    }
  }
  return 0;
}
//===========================
void PlotHistos(Int_t iRapBin, Int_t iPTBin, Int_t iCPMBin, Int_t iFrame, Int_t iWindow){


  gStyle->SetPadRightMargin(0.12);
  gStyle->SetOptStat(0);
  gStyle->SetFrameBorderMode(0);

  Char_t name[100];
  sprintf(name, "c1_%s_rap%d_pT%d_cpm%d_%s", onia::frameLabel[iFrame], iRapBin, iPTBin, iCPMBin, bgLabel[iWindow]);
  TCanvas *c1 = new TCanvas(name, "", 500, 500);
  c1->SetFillColor(kWhite);

  double yOffset=1.4;
  hCosThetaPhi[iRapBin][iPTBin][iCPMBin][iFrame][iWindow]->GetYaxis()->SetTitleOffset(yOffset);
  gPad->SetLeftMargin(0.125);

  hCosThetaPhi[iRapBin][iPTBin][iCPMBin][iFrame][iWindow]->Draw("colz");
  sprintf(name, "Figures/cosThetaPhi_%s_rap%d_pT%d_cpm%d_%s.pdf", onia::frameLabel[iFrame], iRapBin, iPTBin, iCPMBin, bgLabel[iWindow]);
  c1->Print(name);
}

//===========================
void LoadHistos(Int_t iRapBin, Int_t iPTBin, Int_t iCPMBin){


  Char_t name[100];
  sprintf(name, "tmpFiles/data_Ups_rap%d_pT%d_cpm%d.root", iRapBin, iPTBin, iCPMBin);
  TFile *fIn = new TFile(name);

  for(int iFrame = 0; iFrame < onia::kNbFrames; iFrame++){
	  cout<<endl;
	  
    sprintf(name, "hBG_cosThetaPhi_%s_R", onia::frameLabel[iFrame]);
    cout<<"name = "<<name<<endl;
    hCosThetaPhi[iRapBin][iPTBin][iCPMBin][iFrame][R] = (TH2F *) gDirectory->Get(name);
	hCosThetaPhi[iRapBin][iPTBin][iCPMBin][iFrame][R]->Print();
    sprintf(name, "hCosThetaPhi_%s_pT%d_rap%d_cpm%d_R", onia::frameLabel[iFrame], iRapBin, iPTBin, iCPMBin);
    hCosThetaPhi[iRapBin][iPTBin][iCPMBin][iFrame][R]->SetName(name);
    
    sprintf(name, "hBG_cosThetaPhi_%s_L", onia::frameLabel[iFrame]);
    cout<<"name = "<<name<<endl;
    hCosThetaPhi[iRapBin][iPTBin][iCPMBin][iFrame][L] = (TH2F *) gDirectory->Get(name);
	hCosThetaPhi[iRapBin][iPTBin][iCPMBin][iFrame][L]->Print();
    sprintf(name, "hCosThetaPhi_%s_rap%d_pt%d_cpm%d_L", onia::frameLabel[iFrame], iRapBin, iPTBin, iCPMBin);
    hCosThetaPhi[iRapBin][iPTBin][iCPMBin][iFrame][L]->SetName(name);
  }
}
