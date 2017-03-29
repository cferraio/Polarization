
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "../../interface/rootIncludes.inc"
#include "../../interface/commonVar.h"
#include "ToyMC.h"

#include "TSystem.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TFile.h"
#include "TFrame.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include "TROOT.h"

#include "TH2F.h"
#include "TTree.h"
#include "TChain.h"
#include "TDirectory.h"
#include "TLegend.h"
#include "Riostream.h"
#include "TSystem.h"
#include "TString.h"
#include "TFile.h"
#include "TROOT.h"
#include "TTree.h"
#include "TMath.h"
#include "TVector3.h"
#include "TLorentzVector.h"
#include "TRandom3.h"
#include "TF1.h"
#include "TF2.h"
#include "TH1.h"
#include "TH2.h"


int main(int argc, char** argv) {

	Char_t *storagedir = "Default"; //Storage Directory
	Char_t *basedir = "Default"; //Storage Directory
  	Char_t *SystID = "Default";
  	Char_t *JobID1 = "Default";
  	
	int ptBinMin=1;
	int ptBinMax=2;
	int cpmBinMin=1;
	int cpmBinMax=5;
	int nState=1;
  
  //couts all the relevant info
  	  for( int i=0;i < argc; ++i ) {

		    if(std::string(argv[i]).find("JobID1") != std::string::npos) {char* JobID1char = argv[i]; char* JobID1char2 = strtok (JobID1char, "="); JobID1 = JobID1char2; cout<<"JobID1 = "<<JobID1<<endl;}

		    if(std::string(argv[i]).find("SystID") != std::string::npos) {char* SystIDchar = argv[i]; char* SystIDchar2 = strtok (SystIDchar, "="); SystID = SystIDchar2; cout<<"SystID = "<<SystID<<endl;}
		    if(std::string(argv[i]).find("storagedir") != std::string::npos) {char* storagedirchar = argv[i]; char* storagedirchar2 = strtok (storagedirchar, "="); storagedir = storagedirchar2; cout<<"storagedir = "<<storagedir<<endl;}
		    if(std::string(argv[i]).find("basedir") != std::string::npos) {char* basedirchar = argv[i]; char* basedirchar2 = strtok (basedirchar, "="); basedir = basedirchar2; cout<<"basedir = "<<basedir<<endl;}

		    if(std::string(argv[i]).find("cpmBinMin") != std::string::npos) {char* cpmBinMinchar = argv[i]; char* cpmBinMinchar2 = strtok (cpmBinMinchar, "p"); cpmBinMin = atof(cpmBinMinchar2); cout<<"cpmBinMin = "<<cpmBinMin<<endl;}
		    if(std::string(argv[i]).find("cpmBinMax") != std::string::npos) {char* cpmBinMaxchar = argv[i]; char* cpmBinMaxchar2 = strtok (cpmBinMaxchar, "p"); cpmBinMax = atof(cpmBinMaxchar2); cout<<"cpmBinMax = "<<cpmBinMax<<endl;}
		    if(std::string(argv[i]).find("ptBinMin") != std::string::npos) {char* ptBinMinchar = argv[i]; char* ptBinMinchar2 = strtok (ptBinMinchar, "p"); ptBinMin = atof(ptBinMinchar2); cout<<"ptBinMin = "<<ptBinMin<<endl;}
		    if(std::string(argv[i]).find("ptBinMax") != std::string::npos) {char* ptBinMaxchar = argv[i]; char* ptBinMaxchar2 = strtok (ptBinMaxchar, "p"); ptBinMax = atof(ptBinMaxchar2); cout<<"ptBinMax = "<<ptBinMax<<endl;}
		    if(std::string(argv[i]).find("nState") != std::string::npos) {char* nStatechar = argv[i]; char* nStatechar2 = strtok (nStatechar, "p"); nState = atof(nStatechar2); cout<<"nState = "<<nState<<endl;}

	    }
	    
	int rap1entries1s;
	int rap2entries1s;
	int rap1entries2s;
	int rap2entries2s;
	int rap1entries3s;
	int rap2entries3s;
  //counts the number of entires in rap 0-0.6 and 0.6-1.2 to use for calculating
  //systematics in integrated rap
	for(int cpmbin = cpmBinMin; cpmbin < cpmBinMax+1; cpmbin ++) {
	 rap1entries1s+=ToyMC::rapentries1s[0][cpmbin-1];
	 rap2entries1s+=ToyMC::rapentries1s[1][cpmbin-1];
	 rap1entries2s+=ToyMC::rapentries2s[0][cpmbin-1];
	 rap2entries2s+=ToyMC::rapentries2s[1][cpmbin-1];		
	 rap1entries3s+=ToyMC::rapentries3s[0][cpmbin-1];
	 rap2entries3s+=ToyMC::rapentries3s[1][cpmbin-1];  		
	}
  
  char tmpfilename[200];
		sprintf(tmpfilename,"%s/macros/polFit/Systematics/%s/ChangedTGraph/TGraphResults_%dSUps.root",basedir,SystID,nState);
		gSystem->Unlink(tmpfilename);

		char filename[200];
		sprintf(filename,"%s/TGraphResults_%dSUps.root",JobID1,nState);
		TFile *infile1 = new TFile(filename,"READ");

		char GraphName[200];

/*for(int UpsBin = 0; UpsBin < 3; UpsBin++){
  if(UpsBin == 0){
  TFile FW1("/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/FrameworkI/TGraphResults_1SUps.root");
  TFile FW2("/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/FrameworkII/TGraphResults_1SUps.root");
  TFile FW3("/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/FrameworkIII/TGraphResults_1SUps.root");
  TFile Par("/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/Parametrization/TGraphResults_1SUps.root");
  TFile Rho("/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/RhoFactor/TGraphResults_1SUps.root");
  TFile TnP("/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/TnP_model/TGraphResults_1SUps.root");
  } 
  if(UpsBin == 1){
  TFile FW1("/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/FrameworkI/TGraphResults_2SUps.root");
  TFile FW2("/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/FrameworkII/TGraphResults_2SUps.root");
  TFile FW3("/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/FrameworkIII/TGraphResults_2SUps.root");
  TFile Par("/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/Parametrization/TGraphResults_2SUps.root");
  TFile Rho("/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/RhoFactor/TGraphResults_2SUps.root");
  TFile TnP("/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/TnP_model/TGraphResults_2SUps.root");
  }
  if(UpsBin == 2){
  TFile FW1("/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/FrameworkI/TGraphResults_3SUps.root");
  TFile FW2("/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/FrameworkII/TGraphResults_3SUps.root");
  TFile FW3("/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/FrameworkIII/TGraphResults_3SUps.root");
  TFile Par("/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/Parametrization/TGraphResults_3SUps.root");
  TFile Rho("/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/RhoFactor/TGraphResults_3SUps.root");
  TFile TnP("/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/TnP_model/TGraphResults_3SUps.root");
  }
  
*/

		for(int iFrame = 1; iFrame<4; iFrame++){
			for(int rapBin = 1; rapBin < 3; rapBin++){

			TGraphAsymmErrors* graph_lth;
			TGraphAsymmErrors* graph_lph;
			TGraphAsymmErrors* graph_ltp;
			TGraphAsymmErrors* graph_lthstar;
			TGraphAsymmErrors* graph_lphstar;
			TGraphAsymmErrors* graph_ltilde;

			TGraphAsymmErrors* graph_DltildeCS;
			TGraphAsymmErrors* graph_DltildeHX;
			TGraphAsymmErrors* graph_DltildePX;
		
			if(iFrame==1)  {
				sprintf(GraphName,"lth_CS_rap%d",rapBin);
				graph_lth = (TGraphAsymmErrors*) infile1->Get(GraphName);
				graph_lth->Eval(ToyMC::ptCentre1s[pTbin-1][cpmbin-1]);
				
				sprintf(GraphName,"lph_CS_rap%d",rapBin);
				graph_lph = (TGraphAsymmErrors*) infile1->Get(GraphName);
				graph_lph->Eval(ToyMC::ptCentre1s[pTbin-1][cpmbin-1]);
				
				sprintf(GraphName,"ltp_CS_rap%d",rapBin);
				graph_ltp = (TGraphAsymmErrors*) infile1->Get(GraphName);
				graph_ltp->Eval(ToyMC::ptCentre1s[pTbin-1][cpmbin-1]);
				
				sprintf(GraphName,"ltilde_CS_rap%d",rapBin);
				graph_ltilde = (TGraphAsymmErrors*) infile1->Get(GraphName);
				graph_ltilde->Eval(ToyMC::ptCentre1s[pTbin-1][cpmbin-1]);
				
				sprintf(GraphName,"ltilde_CS_rap%d",rapBin);
				graph_DltildeCS = (TGraphAsymmErrors*) infile1->Get(GraphName);
				graph_DltildeCS->Eval(ToyMC::ptCentre1s[pTbin-1][cpmbin-1]);

				sprintf(GraphName,"ltilde_HX_rap%d",rapBin);
				graph_DltildeHX = (TGraphAsymmErrors*) infile1->Get(GraphName);
				graph_DltildeHX->Eval(ToyMC::ptCentre1s[pTbin-1][cpmbin-1]);
				
				sprintf(GraphName,"ltilde_PX_rap%d",rapBin);
				graph_DltildePX = (TGraphAsymmErrors*) infile1->Get(GraphName);
				graph_DltildePX->Eval(ToyMC::ptCentre1s[pTbin-1][cpmbin-1]);
				}//end frame 1 if statement
		
			} //end rap loop
		} //end ups state loop
   Double_t FW1_1S[2][5];
   TFile FW1("/data/users/ferraioc/Polarization/Systematics/systematicsPRLsummary/FrameworkI/TGraphResults_1SUps.root");
   for(int pTbin = ptBinMin; pTbin < ptBinMax+1; pTbin++){
      for(int cpmbin = cpmBinMin; cpmbin < cpmBinMax+1; cpmbin ++) {
		Double_t rap1 = lth_CS_rap1->Eval(ToyMC::ptCentre1s[pTbin-1][cpmbin-1]);
		Double_t rap2 = lth_CS_rap2->Eval(ToyMC::ptCentre1s[pTbin-1][cpmbin-1]);
		FW1_1S[pTbin-1][pTbin-1] = rap1*rap1entries1s/(rap1entries1s+rap2entries1s)+rap2*rap2entries1s/(rap1entries1s+rap2entries1s);
		cout<<FW1_1S[pTbin-1][pTbin-1]<<endl;
      } //end cpm loops
    } //end pT bin 


//} //end ups bin loops


} //end program