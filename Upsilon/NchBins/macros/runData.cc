#ifndef __CINT__
#endif

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "TChain.h"
#include "rootIncludes.inc"
#include "PolData.C"

void BookHistosReco();
void WriteHistosReco(Char_t *fNameOut);
//==========================================
int main(int argc, char** argv){
  
	Char_t *fNameOut = "tmpFiles/selEvents_data_Ups.root";
	Bool_t rejectCowboys = kTRUE;
	bool UpsMC=false;
	bool RequestTrigger=false;

	Char_t *inputTree1 = "Default";
	Char_t *inputTree2 = "Default";
	Char_t *inputTree3 = "Default";
	Char_t *inputTree4 = "Default";
	int FidCuts=999;	

	int inputTrees=0;

	bool selectSOFT(false);
	bool selectTIGHT(false);
	bool selectMIXED(false);
	bool selectNOTMIXED(false);
	bool Odd(false);
	bool Even(false);

	  for( int i=0;i < argc; ++i ) {
	    if(std::string(argv[i]).find("rejectCowboys=false") != std::string::npos) {rejectCowboys=kFALSE; cout<<"reject Cowboys"<<endl;}
	    if(std::string(argv[i]).find("UpsMC=1") != std::string::npos) {UpsMC=true;}
	    if(std::string(argv[i]).find("RequestTrigger=1") != std::string::npos) {RequestTrigger=true;}
	    if(std::string(argv[i]).find("inputTree1") != std::string::npos) {inputTrees++; char* inputTree1char = argv[i]; char* inputTree1char2 = strtok (inputTree1char, "="); inputTree1 = inputTree1char2; cout<<"inputTree1 = "<<inputTree1<<endl;}
	    if(std::string(argv[i]).find("inputTree2") != std::string::npos) {inputTrees++; char* inputTree2char = argv[i]; char* inputTree2char2 = strtok (inputTree2char, "="); inputTree2 = inputTree2char2; cout<<"inputTree2 = "<<inputTree2<<endl;}
	    if(std::string(argv[i]).find("inputTree3") != std::string::npos) {inputTrees++; char* inputTree3char = argv[i]; char* inputTree3char2 = strtok (inputTree3char, "="); inputTree3 = inputTree3char2; cout<<"inputTree3 = "<<inputTree3<<endl;}
	    if(std::string(argv[i]).find("inputTree4") != std::string::npos) {inputTrees++; char* inputTree4char = argv[i]; char* inputTree4char2 = strtok (inputTree4char, "="); inputTree4 = inputTree4char2; cout<<"inputTree4 = "<<inputTree4<<endl;}
	    if(std::string(argv[i]).find("FidCuts") != std::string::npos) {char* FidCutschar = argv[i]; char* FidCutschar2 = strtok (FidCutschar, "p"); FidCuts = atof(FidCutschar2); cout<<"FidCuts = "<<FidCuts<<endl;}
	    if(std::string(argv[i]).find("selectSOFT=1") != std::string::npos) {selectSOFT=true; cout<<"selectSOFT"<<endl;}
	    if(std::string(argv[i]).find("selectTIGHT=1") != std::string::npos) {selectTIGHT=true; cout<<"selectTIGHT"<<endl;}
	    if(std::string(argv[i]).find("selectMIXED=1") != std::string::npos) {selectMIXED=true; cout<<"selectMIXED"<<endl;}
	    if(std::string(argv[i]).find("selectNOTMIXED=1") != std::string::npos) {selectNOTMIXED=true; cout<<"selectNOTMIXED"<<endl;}
	    if(std::string(argv[i]).find("Odd=1") != std::string::npos) {Odd=true; cout<<"Odd"<<endl;}
	    if(std::string(argv[i]).find("Even=1") != std::string::npos) {Even=true; cout<<"Even"<<endl;}
	    }

	  cout<<"Number of Input Trees = "<<inputTrees<<endl;

  TChain *chain = new TChain("data");
  chain->Add(inputTree1);
  if(inputTrees>1) chain->Add(inputTree2);
  if(inputTrees>2) chain->Add(inputTree3);
  if(inputTrees>3) chain->Add(inputTree4);

  TTree *tree = chain;
  
  TFile *fOut = fOut = new TFile(fNameOut, "RECREATE");

  PolData treeReco(tree);
  BookHistosReco();
  printf("after booking of histo\n");
  Int_t selDimuType = 4; //0...only GG, 1... only GT, 2... only TT, 3...GG+GT, 4...GG+GT+TT
  treeReco.Loop(selDimuType, rejectCowboys, FidCuts, UpsMC, RequestTrigger, selectSOFT, selectTIGHT, selectMIXED, selectNOTMIXED, Odd, Even);
  printf("writing out the histograms\n");
  WriteHistosReco(fNameOut);

  fOut->Close();

  return 0;
}
//==========================================
void BookHistosReco(){

  //mass
  Int_t nBinsMass = 320;
  Double_t massMin = 8.4, massMax = 11.6;
  //pt
  Int_t nBinsPt = 1000;
  Double_t pTMin = 0., pTMaxOnia = 100.;
  //rap
  Int_t nBinsRap = 100;
  Double_t rapMin = -2.5, rapMax = 2.5;
  //cpm
  Int_t nBinsCPM = 100;
  Double_t CPMMin = 0., CPMMax = 100.;
  
  Int_t nPriVtx = 25;
  Double_t nPriVtxMin = 0., nPriVtxMax = 24.;

  Char_t name[100], title[300];
  //statistics
  Reco_StatEv = new TH1F("Reco_StatEv", "", 12, 0., 12.);
  

//  sprintf(name, "Reco_Onia_PU");
//  Reco_Onia_PU = new TH1F("PU", "", 12, 0., 24);
//  Reco_Onia_PU->Sumw2();

  //reconstruction variables for the Onia
  for(int iRapBin = 0; iRapBin < onia::kNbRapForPTBins+1; iRapBin++){
    for(int iPTBin = 0; iPTBin < onia::kNbPTBins[iRapBin]+1; iPTBin++){
      for(int iCPMBin = 0; iCPMBin < onia::NXBINS+1; iCPMBin++){
      //Mass:
      sprintf(name, "Reco_Onia_mass_rap%d_pT%d_cpm%d", iRapBin, iPTBin, iCPMBin);
      sprintf(title, ";M [GeV]");
      Reco_Onia_mass[iPTBin][iRapBin][iCPMBin] = new TH1F(name, title, nBinsMass, massMin, massMax);
      Reco_Onia_mass[iPTBin][iRapBin][iCPMBin]->Sumw2();
      }
    }
  }

  sprintf(name, "Reco_Onia_rap_pt");
  sprintf(title, ";y(#mu#mu);p_{T}^{#mu#mu} [GeV]");
  Reco_Onia_rap_pT = new TH2F(name, title, nBinsRap,rapMin,rapMax, nBinsPt,pTMin,pTMaxOnia);
  Reco_Onia_rap_pT->Sumw2();
  
  sprintf(name, "Reco_Onia_rap_cpm");
  sprintf(title, "Nch");
  Reco_Onia_rap_cpm = new TH2F(name, title, nBinsRap,rapMin,rapMax, nBinsCPM,CPMMin,CPMMax);
  Reco_Onia_rap_cpm->Sumw2();

  sprintf(name, "Reco_Onia_pT_cpm");
  sprintf(title, "Nch");
  Reco_Onia_pT_cpm = new TH2F(name, title, nBinsPt,pTMin,pTMaxOnia, nBinsCPM,CPMMin,CPMMax);
  Reco_Onia_pT_cpm->Sumw2();
    

  for(int iCPMBin = 0; iCPMBin < onia::NXBINS; iCPMBin++)
  {
    for(int iPUBin = 0; iPUBin<26; iPUBin++)
    {
      sprintf(name, "Reco_Onia_CPM%d_PU_%d", iCPMBin, iPUBin);
      sprintf(title, "PU");
      Reco_Onia_CPMPU[iCPMBin][iPUBin] = new TH1F(name, title, (onia::cpmRange[iCPMBin+1]-onia::cpmRange[iCPMBin]), onia::cpmRange[iCPMBin], onia::cpmRange[iCPMBin+1]);
      Reco_Onia_CPMPU[iCPMBin][iPUBin]->Sumw2();
    }
  }

for(int iPUBin = 0; iPUBin<26; iPUBin++){
  sprintf(name, "Reco_Onia_CPMPU_%d_intNCH",iPUBin);
  sprintf(title, "PU_IntNch");
  Reco_Onia_CPMPU_intNCH[iPUBin] = new TH1F(name, title, 100, 0, 100);
  Reco_Onia_CPMPU_intNCH[iPUBin]->Sumw2();
}

for(int iCPMBin = 0; iCPMBin < onia::NXBINS; iCPMBin++)
  {
  sprintf(name, "binnedNch_%d", iCPMBin);
      sprintf(title, "PU int");
      Reco_Onia_CPMPUbinned[iCPMBin] = new TH1F(name, title, (onia::cpmRange[iCPMBin+1]-onia::cpmRange[iCPMBin]), onia::cpmRange[iCPMBin], onia::cpmRange[iCPMBin+1]);
      Reco_Onia_CPMPUbinned[iCPMBin]->Sumw2();
  }

  for(int iRapBin = 0; iRapBin < onia::kNbRapForPTBins+1; iRapBin++){
    //pT
    sprintf(name, "Reco_Onia_pt_rap%d", iRapBin);
    sprintf(title, ";p_{T}^{#mu#mu} [GeV]");
    Reco_Onia_pt[iRapBin]  = new TH1F(name, title, nBinsPt,pTMin,pTMaxOnia);
    Reco_Onia_pt[iRapBin]->Sumw2();
  }
  for(int iPTBin = 0; iPTBin < onia::kNbPTMaxBins+1; iPTBin++){
    //rap
    sprintf(name, "Reco_Onia_rap_pT%d", iPTBin);
    sprintf(title, ";y(#mu#mu)");
    Reco_Onia_rap[iPTBin]  = new TH1F(name, title, nBinsRap, rapMin,rapMax);
    Reco_Onia_rap[iPTBin]->Sumw2();
  }
  
  for(int iCPMBin = 0; iCPMBin < onia::NXBINS+1; iCPMBin++){
    //rap
    sprintf(name, "Reco_Onia_rap_cpm%d", iCPMBin);
    sprintf(title, ";y(#mu#mu)");
    Reco_Onia_rapcpm[iCPMBin]  = new TH1F(name, title, nBinsRap, rapMin,rapMax);
    Reco_Onia_rapcpm[iCPMBin]->Sumw2();
  }

/*  for(int iPVBin = 0; iPVBin < 14; iPVBin++){  
    sprintf(name, "Reco_Onia_cpm_PV_%d", iPVBin);
    sprintf(title, "Nch");
    Reco_Onia_cpminPriVtx[iPVBin] = new TH1F(name, title, nBinsCPM,CPMMin,CPMMax);
    Reco_Onia_cpminPriVtx[iPVBin]->Sumw2();
  } */
  
   for(int iPTBin = 0; iPTBin < onia::kNbPTMaxBins+1; iPTBin++){  
    sprintf(name, "Reco_Onia_cpm_pt%d", iPTBin);
    sprintf(title, "Nch");
    Reco_Onia_cpm[iPTBin] = new TH1F(name, title, nBinsCPM,CPMMin,CPMMax);
    Reco_Onia_cpm[iPTBin]->Sumw2();
  }
  
  

  //prepare the branches for the output tree
  treeOut = new TTree ("selectedData", "selected events");
  lepP = new TLorentzVector();
  lepN = new TLorentzVector();

  treeOut->Branch("lepP", "TLorentzVector", &lepP);
  treeOut->Branch("lepN", "TLorentzVector", &lepN);

}

//==========================================
void WriteHistosReco(Char_t *fNameOut){

  treeOut->Write();

  Reco_StatEv->Write();
//  Reco_Onia_PU->Write();

  for(int iRapBin = 0; iRapBin < onia::kNbRapForPTBins+1; iRapBin++){
    for(int iPTBin = 0; iPTBin < onia::kNbPTBins[iRapBin]+1; iPTBin++){
      for(int iCPMBin = 0; iCPMBin < onia::NXBINS+1; iCPMBin++){
      Reco_Onia_mass[iPTBin][iRapBin][iCPMBin]->Write();
      }
    }
  }

  Reco_Onia_rap_pT->Write();
  for(int iPTBin = 0; iPTBin < onia::kNbPTMaxBins+1; iPTBin++)
    Reco_Onia_rap[iPTBin]->Write();
  for(int iRapBin = 0; iRapBin < onia::kNbRapForPTBins+1; iRapBin++)
    Reco_Onia_pt[iRapBin]->Write();
  for(int iCPMBin = 0; iCPMBin < onia::NXBINS+1; iCPMBin++)
    Reco_Onia_rapcpm[iCPMBin]->Write();

  Reco_Onia_rap_cpm->Write();
  Reco_Onia_pT_cpm->Write();
  

for(int iCPMBin = 0; iCPMBin < onia::NXBINS; iCPMBin++){
for(int iPUBin = 0; iPUBin<26; iPUBin++){
  Reco_Onia_CPMPU[iCPMBin][iPUBin]->Write();}}

for(int iCPMBin = 0; iCPMBin<5; iCPMBin++){  
  Reco_Onia_CPMPUbinned[iCPMBin]->Write();
  }
  
  
/*    for(int iPVBin = 0; iPVBin < 14; iPVBin++){ 
  Reco_Onia_cpminPriVtx[iPVBin]->Write();
  } */
  
  for(int iPTBin = 0; iPTBin < onia::kNbPTMaxBins+1; iPTBin++)
    Reco_Onia_cpm[iPTBin]->Write();

}
