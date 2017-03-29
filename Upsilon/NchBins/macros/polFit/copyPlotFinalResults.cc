/*
 * PlotFinalResults.cc
 *
 *  Created on: Dec 3, 2011
 *      Author: valentinknuenz
 */

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
#include "TGaxis.h"



int main(int argc, char** argv) {

	Char_t *JobID = "JobID"; //Storage Directory

	Char_t *SystID1Base = "Default"; //Storage Directory
  	Char_t *SystID1Specify = "Default";
  	Char_t *SystID1Title = "Default";

  	Char_t *SystID2Base = "Default"; //Storage Directory
  	Char_t *SystID2Specify = "Default";
  	Char_t *SystID2Title = "Default";

  	Char_t *SystID3Base = "Default"; //Storage Directory
  	Char_t *SystID3Specify = "Default";
  	Char_t *SystID3Title = "Default";

	Char_t *SystID4Base = "Default"; //Storage Directory
  	Char_t *SystID4Specify = "Default";
  	Char_t *SystID4Title = "Default";

	Char_t *SystID5Base = "Default"; //Storage Directory
  	Char_t *SystID5Specify = "Default";
  	Char_t *SystID5Title = "Default";

	Char_t *SystID6Base = "Default"; //Storage Directory
  	Char_t *SystID6Specify = "Default";
  	Char_t *SystID6Title = "Default";

	Char_t *SystID7Base = "Default"; //Storage Directory
  	Char_t *SystID7Specify = "Default";
  	Char_t *SystID7Title = "Default";

	Char_t *SystID8Base = "Default"; //Storage Directory
  	Char_t *SystID8Specify = "Default";
  	Char_t *SystID8Title = "Default";

  	Char_t *basedir = "Default";
  	Char_t *storagedir = "Default";
  	Char_t *DefaultID = "Default";
  	Char_t *CompareID1 = "CompareID1";
  	Char_t *CompareID2 = "CompareID2";
  	Char_t *CompareID3 = "CompareID3";
  	Char_t *CompareID4 = "CompareID4";

  	Char_t *LegendEntryDefID  = "Default";
  	Char_t *LegendEntryCompID1= "Default";
  	Char_t *LegendEntryCompID2= "Default";
  	Char_t *LegendEntryCompID3= "Default";
  	Char_t *LegendEntryCompID4= "Default";

  	Char_t *MPCentralsWithTotalSystID = "MPCentralsWithTotalSystID";
  	Char_t *GlobalUncLoc = "GlobalUncLoc";

	int cpmBinMin=1;
	int cpmBinMax=1;
	int ptBinMin=1;
	int ptBinMax=1;
	int nSystematics=1;
	int nComp=1;
	int nState=1;

	bool PlotMatt(false);
	bool PlotAsymm(false);
	bool PlotCompare(false);
	bool PlotFinalData(false);
	bool PlotSystematics(false);
	bool PlotLegend(false);
	bool PlotBrazilian(false);
	bool FitGraph(false);
	bool DrawLatexStuff(false);
	bool MultiPanelPlots(false);
	bool PlotBG0plots(false);
	bool DeltaTildeplots(false);
	bool SBmSigPlots(false);
	bool PlotAlteredPPDResults(false);
	bool CompareSyst(false);
	bool SteerIndividuals(false);
	bool BGratioFits(false);
	bool BGratioChi2Fits(false);
	bool rapBinComb(false);
	bool SetCompStyle(false);
	bool DrawPreliminary(true);
	bool PlotMattForICHEP(false);
	bool ExtendLegendInX(false);
	bool ShiftInX(true);
	bool PlotVsComp(false);
	bool PlotGlobalUnc(false);

	  for( int i=0;i < argc; ++i ) {

		    if(std::string(argv[i]).find("JobID") != std::string::npos) {char* JobIDchar = argv[i]; char* JobIDchar2 = strtok (JobIDchar, "="); JobID = JobIDchar2; cout<<"JobID = "<<JobID<<endl;}
		    if(std::string(argv[i]).find("DefaultID") != std::string::npos) {char* DefaultIDchar = argv[i]; char* DefaultIDchar2 = strtok (DefaultIDchar, "="); DefaultID = DefaultIDchar2; cout<<"DefaultID = "<<DefaultID<<endl;}
		    if(std::string(argv[i]).find("basedir") != std::string::npos) {char* basedirchar = argv[i]; char* basedirchar2 = strtok (basedirchar, "="); basedir = basedirchar2; cout<<"basedir = "<<basedir<<endl;}
		    if(std::string(argv[i]).find("storagedir") != std::string::npos) {char* storagedirchar = argv[i]; char* storagedirchar2 = strtok (storagedirchar, "="); storagedir = storagedirchar2; cout<<"storagedir = "<<storagedir<<endl;}
		    if(std::string(argv[i]).find("SystID1Base") != std::string::npos) {char* SystID1Basechar = argv[i]; char* SystID1Basechar2 = strtok (SystID1Basechar, "="); SystID1Base = SystID1Basechar2; cout<<"SystID1Base = "<<SystID1Base<<endl;}
		    if(std::string(argv[i]).find("SystID1Specify") != std::string::npos) {char* SystID1Specifychar = argv[i]; char* SystID1Specifychar2 = strtok (SystID1Specifychar, "="); SystID1Specify = SystID1Specifychar2; cout<<"SystID1Specify = "<<SystID1Specify<<endl;}
		    if(std::string(argv[i]).find("SystID1Title") != std::string::npos) {char* SystID1Titlechar = argv[i]; char* SystID1Titlechar2 = strtok (SystID1Titlechar, "="); SystID1Title = SystID1Titlechar2; cout<<"SystID1Title = "<<SystID1Title<<endl;}
		    if(std::string(argv[i]).find("SystID2Base") != std::string::npos) {char* SystID2Basechar = argv[i]; char* SystID2Basechar2 = strtok (SystID2Basechar, "="); SystID2Base = SystID2Basechar2; cout<<"SystID2Base = "<<SystID2Base<<endl;}
		    if(std::string(argv[i]).find("SystID2Specify") != std::string::npos) {char* SystID2Specifychar = argv[i]; char* SystID2Specifychar2 = strtok (SystID2Specifychar, "="); SystID2Specify = SystID2Specifychar2; cout<<"SystID2Specify = "<<SystID2Specify<<endl;}
		    if(std::string(argv[i]).find("SystID2Title") != std::string::npos) {char* SystID2Titlechar = argv[i]; char* SystID2Titlechar2 = strtok (SystID2Titlechar, "="); SystID2Title = SystID2Titlechar2; cout<<"SystID2Title = "<<SystID2Title<<endl;}
		    if(std::string(argv[i]).find("SystID3Base") != std::string::npos) {char* SystID3Basechar = argv[i]; char* SystID3Basechar2 = strtok (SystID3Basechar, "="); SystID3Base = SystID3Basechar2; cout<<"SystID3Base = "<<SystID3Base<<endl;}
		    if(std::string(argv[i]).find("SystID3Specify") != std::string::npos) {char* SystID3Specifychar = argv[i]; char* SystID3Specifychar2 = strtok (SystID3Specifychar, "="); SystID3Specify = SystID3Specifychar2; cout<<"SystID3Specify = "<<SystID3Specify<<endl;}
		    if(std::string(argv[i]).find("SystID3Title") != std::string::npos) {char* SystID3Titlechar = argv[i]; char* SystID3Titlechar2 = strtok (SystID3Titlechar, "="); SystID3Title = SystID3Titlechar2; cout<<"SystID3Title = "<<SystID3Title<<endl;}
		    if(std::string(argv[i]).find("SystID4Base") != std::string::npos) {char* SystID4Basechar = argv[i]; char* SystID4Basechar2 = strtok (SystID4Basechar, "="); SystID4Base = SystID4Basechar2; cout<<"SystID4Base = "<<SystID4Base<<endl;}
		    if(std::string(argv[i]).find("SystID4Specify") != std::string::npos) {char* SystID4Specifychar = argv[i]; char* SystID4Specifychar2 = strtok (SystID4Specifychar, "="); SystID4Specify = SystID4Specifychar2; cout<<"SystID4Specify = "<<SystID4Specify<<endl;}
		    if(std::string(argv[i]).find("SystID4Title") != std::string::npos) {char* SystID4Titlechar = argv[i]; char* SystID4Titlechar2 = strtok (SystID4Titlechar, "="); SystID4Title = SystID4Titlechar2; cout<<"SystID4Title = "<<SystID4Title<<endl;}
		    if(std::string(argv[i]).find("SystID5Base") != std::string::npos) {char* SystID5Basechar = argv[i]; char* SystID5Basechar2 = strtok (SystID5Basechar, "="); SystID5Base = SystID5Basechar2; cout<<"SystID5Base = "<<SystID5Base<<endl;}
		    if(std::string(argv[i]).find("SystID5Specify") != std::string::npos) {char* SystID5Specifychar = argv[i]; char* SystID5Specifychar2 = strtok (SystID5Specifychar, "="); SystID5Specify = SystID5Specifychar2; cout<<"SystID5Specify = "<<SystID5Specify<<endl;}
		    if(std::string(argv[i]).find("SystID5Title") != std::string::npos) {char* SystID5Titlechar = argv[i]; char* SystID5Titlechar2 = strtok (SystID5Titlechar, "="); SystID5Title = SystID5Titlechar2; cout<<"SystID5Title = "<<SystID5Title<<endl;}
		    if(std::string(argv[i]).find("SystID6Base") != std::string::npos) {char* SystID6Basechar = argv[i]; char* SystID6Basechar2 = strtok (SystID6Basechar, "="); SystID6Base = SystID6Basechar2; cout<<"SystID6Base = "<<SystID6Base<<endl;}
		    if(std::string(argv[i]).find("SystID6Specify") != std::string::npos) {char* SystID6Specifychar = argv[i]; char* SystID6Specifychar2 = strtok (SystID6Specifychar, "="); SystID6Specify = SystID6Specifychar2; cout<<"SystID6Specify = "<<SystID6Specify<<endl;}
		    if(std::string(argv[i]).find("SystID6Title") != std::string::npos) {char* SystID6Titlechar = argv[i]; char* SystID6Titlechar2 = strtok (SystID6Titlechar, "="); SystID6Title = SystID6Titlechar2; cout<<"SystID6Title = "<<SystID6Title<<endl;}
		    if(std::string(argv[i]).find("SystID7Base") != std::string::npos) {char* SystID7Basechar = argv[i]; char* SystID7Basechar2 = strtok (SystID7Basechar, "="); SystID7Base = SystID7Basechar2; cout<<"SystID7Base = "<<SystID7Base<<endl;}
		    if(std::string(argv[i]).find("SystID7Specify") != std::string::npos) {char* SystID7Specifychar = argv[i]; char* SystID7Specifychar2 = strtok (SystID7Specifychar, "="); SystID7Specify = SystID7Specifychar2; cout<<"SystID7Specify = "<<SystID7Specify<<endl;}
		    if(std::string(argv[i]).find("SystID7Title") != std::string::npos) {char* SystID7Titlechar = argv[i]; char* SystID7Titlechar2 = strtok (SystID7Titlechar, "="); SystID7Title = SystID7Titlechar2; cout<<"SystID7Title = "<<SystID7Title<<endl;}
		    if(std::string(argv[i]).find("SystID8Base") != std::string::npos) {char* SystID8Basechar = argv[i]; char* SystID8Basechar2 = strtok (SystID8Basechar, "="); SystID8Base = SystID8Basechar2; cout<<"SystID8Base = "<<SystID8Base<<endl;}
		    if(std::string(argv[i]).find("SystID8Specify") != std::string::npos) {char* SystID8Specifychar = argv[i]; char* SystID8Specifychar2 = strtok (SystID8Specifychar, "="); SystID8Specify = SystID8Specifychar2; cout<<"SystID8Specify = "<<SystID8Specify<<endl;}
		    if(std::string(argv[i]).find("SystID8Title") != std::string::npos) {char* SystID8Titlechar = argv[i]; char* SystID8Titlechar2 = strtok (SystID8Titlechar, "="); SystID8Title = SystID8Titlechar2; cout<<"SystID8Title = "<<SystID8Title<<endl;}

		    if(std::string(argv[i]).find("CompareID1") != std::string::npos) {char* CompareID1char = argv[i]; char* CompareID1char2 = strtok (CompareID1char, "="); CompareID1 = CompareID1char2; cout<<"CompareID1 = "<<CompareID1<<endl;}
		    if(std::string(argv[i]).find("CompareID2") != std::string::npos) {char* CompareID2char = argv[i]; char* CompareID2char2 = strtok (CompareID2char, "="); CompareID2 = CompareID2char2; cout<<"CompareID2 = "<<CompareID2<<endl;}
		    if(std::string(argv[i]).find("CompareID3") != std::string::npos) {char* CompareID3char = argv[i]; char* CompareID3char2 = strtok (CompareID3char, "="); CompareID3 = CompareID3char2; cout<<"CompareID3 = "<<CompareID3<<endl;}
		    if(std::string(argv[i]).find("CompareID4") != std::string::npos) {char* CompareID4char = argv[i]; char* CompareID4char2 = strtok (CompareID4char, "="); CompareID4 = CompareID4char2; cout<<"CompareID4 = "<<CompareID4<<endl;}
		    if(std::string(argv[i]).find("MPCentralsWithTotalSystID") != std::string::npos) {char* MPCentralsWithTotalSystIDchar = argv[i]; char* MPCentralsWithTotalSystIDchar2 = strtok (MPCentralsWithTotalSystIDchar, "="); MPCentralsWithTotalSystID = MPCentralsWithTotalSystIDchar2; cout<<"MPCentralsWithTotalSystID = "<<MPCentralsWithTotalSystID<<endl;}
		    if(std::string(argv[i]).find("GlobalUncLoc") != std::string::npos) {char* GlobalUncLocchar = argv[i]; char* GlobalUncLocchar2 = strtok (GlobalUncLocchar, "="); GlobalUncLoc = GlobalUncLocchar2; cout<<"GlobalUncLoc = "<<GlobalUncLoc<<endl;}

		    if(std::string(argv[i]).find("LegendEntryDefID") != std::string::npos) {char* LegendEntryDefIDchar = argv[i]; char* LegendEntryDefIDchar2 = strtok (LegendEntryDefIDchar, "="); LegendEntryDefID = LegendEntryDefIDchar2; cout<<"LegendEntryDefID = "<<LegendEntryDefID<<endl;}
		    if(std::string(argv[i]).find("LegendEntryCompID1") != std::string::npos) {char* LegendEntryCompID1char = argv[i]; char* LegendEntryCompID1char2 = strtok (LegendEntryCompID1char, "="); LegendEntryCompID1 = LegendEntryCompID1char2; cout<<"LegendEntryCompID1 = "<<LegendEntryCompID1<<endl;}
		    if(std::string(argv[i]).find("LegendEntryCompID2") != std::string::npos) {char* LegendEntryCompID2char = argv[i]; char* LegendEntryCompID2char2 = strtok (LegendEntryCompID2char, "="); LegendEntryCompID2 = LegendEntryCompID2char2; cout<<"LegendEntryCompID2 = "<<LegendEntryCompID2<<endl;}
		    if(std::string(argv[i]).find("LegendEntryCompID3") != std::string::npos) {char* LegendEntryCompID3char = argv[i]; char* LegendEntryCompID3char2 = strtok (LegendEntryCompID3char, "="); LegendEntryCompID3 = LegendEntryCompID3char2; cout<<"LegendEntryCompID3 = "<<LegendEntryCompID3<<endl;}
		    if(std::string(argv[i]).find("LegendEntryCompID4") != std::string::npos) {char* LegendEntryCompID4char = argv[i]; char* LegendEntryCompID4char2 = strtok (LegendEntryCompID4char, "="); LegendEntryCompID4 = LegendEntryCompID4char2; cout<<"LegendEntryCompID4 = "<<LegendEntryCompID4<<endl;}

		    if(std::string(argv[i]).find("ptBinMin") != std::string::npos) {char* ptBinMinchar = argv[i]; char* ptBinMinchar2 = strtok (ptBinMinchar, "p"); ptBinMin = atof(ptBinMinchar2); cout<<"ptBinMin = "<<ptBinMin<<endl;}
		    if(std::string(argv[i]).find("ptBinMax") != std::string::npos) {char* ptBinMaxchar = argv[i]; char* ptBinMaxchar2 = strtok (ptBinMaxchar, "p"); ptBinMax = atof(ptBinMaxchar2); cout<<"ptBinMax = "<<ptBinMax<<endl;}
		    if(std::string(argv[i]).find("cpmBinMin") != std::string::npos) {char* cpmBinMinchar = argv[i]; char* cpmBinMinchar2 = strtok (cpmBinMinchar, "p"); cpmBinMin = atof(cpmBinMinchar2); cout<<"cpmBinMin = "<<cpmBinMin<<endl;}
		    if(std::string(argv[i]).find("cpmBinMax") != std::string::npos) {char* cpmBinMaxchar = argv[i]; char* cpmBinMaxchar2 = strtok (cpmBinMaxchar, "p"); cpmBinMax = atof(cpmBinMaxchar2); cout<<"cpmBinMax = "<<cpmBinMax<<endl;}

		    if(std::string(argv[i]).find("nSystematics") != std::string::npos) {char* nSystematicschar = argv[i]; char* nSystematicschar2 = strtok (nSystematicschar, "p"); nSystematics = atof(nSystematicschar2); cout<<"nSystematics = "<<nSystematics<<endl;}
		    if(std::string(argv[i]).find("nComp") != std::string::npos) {char* nCompchar = argv[i]; char* nCompchar2 = strtok (nCompchar, "p"); nComp = atof(nCompchar2); cout<<"nComp = "<<nComp<<endl;}
		    if(std::string(argv[i]).find("nState") != std::string::npos) {char* nStatechar = argv[i]; char* nStatechar2 = strtok (nStatechar, "p"); nState = atof(nStatechar2); cout<<"nState = "<<nState<<endl;}

		    if(std::string(argv[i]).find("PlotMatt=1") != std::string::npos) {PlotMatt=true; cout<<"Plot Matts results"<<endl;}
		    if(std::string(argv[i]).find("PlotAsymm=1") != std::string::npos) {PlotAsymm=true; cout<<"Plot Asymms results"<<endl;}
		    if(std::string(argv[i]).find("PlotCompare=1") != std::string::npos) {PlotCompare=true; cout<<"Plot Comparison results"<<endl;}
		    if(std::string(argv[i]).find("PlotFinalData=1") != std::string::npos) {PlotFinalData=true; cout<<"Plot Data results"<<endl;}
		    if(std::string(argv[i]).find("PlotSystematics=1") != std::string::npos) {PlotSystematics=true; cout<<"Plot Systematics results"<<endl;}
		    if(std::string(argv[i]).find("PlotLegend=1") != std::string::npos) {PlotLegend=true; cout<<"Plot Legend"<<endl;}
		    if(std::string(argv[i]).find("PlotBrazilian=1") != std::string::npos) {PlotBrazilian=true; cout<<"Plot Brazilian"<<endl;}
		    if(std::string(argv[i]).find("FitGraph=1") != std::string::npos) {FitGraph=true; cout<<"FitGraph"<<endl;}
		    if(std::string(argv[i]).find("DrawLatexStuff=1") != std::string::npos) {DrawLatexStuff=true; cout<<"DrawLatexStuff"<<endl;}
		    if(std::string(argv[i]).find("MultiPanelPlots=1") != std::string::npos) {MultiPanelPlots=true; cout<<"MultiPanelPlots"<<endl;}
		    if(std::string(argv[i]).find("PlotBG0plots=1") != std::string::npos) {PlotBG0plots=true; cout<<"PlotBG0plots"<<endl;}
		    if(std::string(argv[i]).find("DeltaTildeplots=1") != std::string::npos) {DeltaTildeplots=true; cout<<"DeltaTildeplots"<<endl;}
		    if(std::string(argv[i]).find("SBmSigPlots=1") != std::string::npos) {SBmSigPlots=true; cout<<"SBmSigPlots"<<endl;}
		    if(std::string(argv[i]).find("PlotAlteredPPDResults=1") != std::string::npos) {PlotAlteredPPDResults=true; cout<<"PlotAlteredPPDResults"<<endl;}
		    if(std::string(argv[i]).find("PlotGlobalUnc=1") != std::string::npos) {PlotGlobalUnc=true; cout<<"PlotGlobalUnc"<<endl;}
		    if(std::string(argv[i]).find("CompareSyst=1") != std::string::npos) {CompareSyst=true; cout<<"CompareSyst"<<endl;}
		    if(std::string(argv[i]).find("SteerIndividuals=1") != std::string::npos) {SteerIndividuals=true; cout<<"SteerIndividuals"<<endl;}
		    if(std::string(argv[i]).find("BGratioFits=1") != std::string::npos) {BGratioFits=true; cout<<"BGratioFits"<<endl;}
		    if(std::string(argv[i]).find("BGratioChi2Fits=1") != std::string::npos) {BGratioChi2Fits=true; cout<<"BGratioChi2Fits"<<endl;}
		    if(std::string(argv[i]).find("rapBinComb=1") != std::string::npos) {rapBinComb=true; cout<<"rapBinComb"<<endl;}
		    if(std::string(argv[i]).find("SetCompStyle=1") != std::string::npos) {SetCompStyle=true; cout<<"SetCompStyle"<<endl;}
		    if(std::string(argv[i]).find("DrawPreliminary=0") != std::string::npos) {DrawPreliminary=false; cout<<"DrawPreliminary"<<endl;}
		    if(std::string(argv[i]).find("PlotMattForICHEP=1") != std::string::npos) {PlotMattForICHEP=true; cout<<"PlotMattForICHEP"<<endl;}
		    if(std::string(argv[i]).find("ExtendLegendInX=1") != std::string::npos) {ExtendLegendInX=true; cout<<"ExtendLegendInX"<<endl;}
		    if(std::string(argv[i]).find("ShiftInX=0") != std::string::npos) {ShiftInX=false; cout<<"ShiftInX false"<<endl;}
		    if(std::string(argv[i]).find("PlotVsComp=1") != std::string::npos) {PlotVsComp=false; cout<<"PlotVsComp"<<endl;}

	    }

	    gStyle->SetFrameBorderMode(0);
	    double ColordBandWidth=1.;
	    double DeltaXminOVERALL=0.;//0.9999;
	    if(ShiftInX) DeltaXminOVERALL=0.9999;
	    bool ShiftXminOVERALL=true;

	    int OneSigColor=416;
		int TwoSigColor=400;//858,898
		int ThreeSigColor=423;//423

		char filename[200];
		sprintf(filename,"%s/%s/TGraphResults_%dSUps.root",storagedir,DefaultID,nState);
		if(CompareSyst)sprintf(filename,"%s/macros/polFit/Systematics/%s/%s/TGraphResults_%dSUps.root",basedir,SystID1Base,SystID1Specify,nState);
		TFile *infileRes = new TFile(filename,"READ");

		sprintf(filename,"%s/%s/TGraphResults_%dSUps_1sigma.root",storagedir,DefaultID,nState);
		TFile *infileRes1sigma = new TFile(filename,"READ");
		sprintf(filename,"%s/%s/TGraphResults_%dSUps_2sigma.root",storagedir,DefaultID,nState);
		TFile *infileRes2sigma = new TFile(filename,"READ");
		sprintf(filename,"%s/%s/TGraphResults_%dSUps_3sigma.root",storagedir,DefaultID,nState);
		TFile *infileRes3sigma = new TFile(filename,"READ");

		if(!PlotBrazilian){
			infileRes2sigma=infileRes;
			infileRes3sigma=infileRes;
		}
		

//		sprintf(filename,"/home/ferraioc/Polarization/CMSSW_4_4_2/src/MODIFIED/CMS/Polarization/UpsilonPol2011/macros/polFit/Systematics/%s/TGraphResults_%dSUps.root",MPCentralsWithTotalSystID,nState);

		TFile *infileStat = new TFile(filename,"READ");
		if(!PlotAlteredPPDResults) infileStat=infileRes;

		sprintf(filename,"%s/macros/polFit/Systematics/%s/%s/TGraphResults_%dSUps.root",basedir,SystID1Base,SystID1Specify,nState);
		TFile *infileSyst1 = new TFile(filename,"READ");

		sprintf(filename,"%s/macros/polFit/Systematics/%s/%s/TGraphResults_%dSUps.root",basedir,SystID2Base,SystID2Specify,nState);
		TFile *infileSyst2 = new TFile(filename,"READ");
		
		sprintf(filename,"%s/macros/polFit/Systematics/%s/%s/TGraphResults_%dSUps.root",basedir,SystID3Base,SystID3Specify,nState);
		TFile *infileSyst3 = new TFile(filename,"READ");		

		sprintf(filename,"%s/macros/polFit/Systematics/%s/%s/TGraphResults_%dSUps.root",basedir,SystID4Base,SystID4Specify,nState);
		TFile *infileSyst4 = new TFile(filename,"READ");

		sprintf(filename,"%s/macros/polFit/Systematics/%s/%s/TGraphResults_%dSUps.root",basedir,SystID5Base,SystID5Specify,nState);
		TFile *infileSyst5 = new TFile(filename,"READ");

		sprintf(filename,"%s/macros/polFit/Systematics/%s/%s/TGraphResults_%dSUps.root",basedir,SystID6Base,SystID6Specify,nState);
		TFile *infileSyst6 = new TFile(filename,"READ");

		sprintf(filename,"%s/macros/polFit/Systematics/%s/%s/TGraphResults_%dSUps.root",basedir,SystID7Base,SystID7Specify,nState);
		TFile *infileSyst7 = new TFile(filename,"READ");

		sprintf(filename,"%s/macros/polFit/Systematics/%s/%s/TGraphResults_%dSUps.root",basedir,SystID8Base,SystID8Specify,nState);
		TFile *infileSyst8 = new TFile(filename,"READ");


		sprintf(filename,"%s/%s/TGraphResults_%dSUps.root",storagedir,CompareID1,nState);
		if(CompareSyst)sprintf(filename,"%s/macros/polFit/Systematics/%s/%s/TGraphResults_2SUps.root",basedir,SystID2Base,SystID2Specify,nState);
		TFile *CompareFile1 = new TFile(filename,"READ");
		if(nComp<1) CompareFile1=infileRes;

		sprintf(filename,"%s/%s/TGraphResults_%dSUps.root",storagedir,CompareID2,nState);
		if(CompareSyst)sprintf(filename,"%s/macros/polFit/Systematics/%s/%s/TGraphResults_3SUps.root",basedir,SystID3Base,SystID3Specify,nState);
		TFile *CompareFile2 = new TFile(filename,"READ");
		if(nComp<2) CompareFile2=infileRes;

		sprintf(filename,"%s/%s/TGraphResults_%dSUps.root",storagedir,CompareID3,nState);
		if(CompareSyst)sprintf(filename,"%s/macros/polFit/Systematics/%s/%s/TGraphResults_3SUps.root",basedir,SystID4Base,SystID4Specify,nState);
		TFile *CompareFile3 = new TFile(filename,"READ");
		if(nComp<3) CompareFile3=infileRes;

		sprintf(filename,"%s/%s/TGraphResults_%dSUps.root",storagedir,CompareID4,nState);
		TFile *CompareFile4 = new TFile(filename,"READ");
		if(nComp<4) CompareFile4=infileRes;

		sprintf(filename,"/home/ferraioc/Polarization/CMSSW_4_4_2/src/MODIFIED/CMS/Polarization/UpsilonPol2011/macros/polFit/Systematics/TotalSyst/%s/TGraphResults_1SUps.root",MPCentralsWithTotalSystID);
		TFile *infileMP1 = new TFile(filename,"READ");
		if(!MultiPanelPlots) infileMP1=infileRes;

		sprintf(filename,"/home/ferraioc/Polarization/CMSSW_4_4_2/src/MODIFIED/CMS/Polarization/UpsilonPol2011/macros/polFit/Systematics/TotalSyst/%s/TGraphResults_2SUps.root",MPCentralsWithTotalSystID);
		TFile *infileMP2 = new TFile(filename,"READ");
		if(!MultiPanelPlots) infileMP2=infileRes;

		sprintf(filename,"/home/ferraioc/Polarization/CMSSW_4_4_2/src/MODIFIED/CMS/Polarization/UpsilonPol2011/macros/polFit/Systematics/TotalSyst/%s/TGraphResults_3SUps.root",MPCentralsWithTotalSystID);
		TFile *infileMP3 = new TFile(filename,"READ");
		if(!MultiPanelPlots) infileMP3=infileRes; 

/*		if(MultiPanelPlots)
		{ sprintf(filename,"/data/users/ferraioc/Polarization/Modified/Data/%s/TGraphResults_1SUps.root",JobID);
		TFile *infileMP1 = new TFile(filename,"READ");
		sprintf(filename,"/data/users/ferraioc/Polarization/Modified/Data/%s/TGraphResults_2SUps.root",JobID);
		TFile *infileMP2 = new TFile(filename,"READ");
		sprintf(filename,"/data/users/ferraioc/Polarization/Modified/Data/%s/TGraphResults_3SUps.root",JobID);
		TFile *infileMP3 = new TFile(filename,"READ");
		}
*/
		sprintf(filename,"%s/%s/TGraphResults_1SUps_1sigma.root",storagedir,DefaultID);
		TFile *infileMP1_1sig = new TFile(filename,"READ");
		if(!MultiPanelPlots) infileMP1_1sig=infileRes;
		sprintf(filename,"%s/%s/TGraphResults_1SUps_2sigma.root",storagedir,DefaultID);
		TFile *infileMP1_2sig = new TFile(filename,"READ");
		if(!MultiPanelPlots) infileMP1_2sig=infileRes;
		sprintf(filename,"%s/%s/TGraphResults_1SUps_3sigma.root",storagedir,DefaultID);
		TFile *infileMP1_3sig = new TFile(filename,"READ");
		if(!MultiPanelPlots) infileMP1_3sig=infileRes;

		sprintf(filename,"%s/%s/TGraphResults_2SUps_1sigma.root",storagedir,DefaultID);
		TFile *infileMP2_1sig = new TFile(filename,"READ");
		if(!MultiPanelPlots) infileMP2_1sig=infileRes;
		sprintf(filename,"%s/%s/TGraphResults_2SUps_2sigma.root",storagedir,DefaultID);
		TFile *infileMP2_2sig = new TFile(filename,"READ");
		if(!MultiPanelPlots) infileMP2_2sig=infileRes;
		sprintf(filename,"%s/%s/TGraphResults_2SUps_3sigma.root",storagedir,DefaultID);
		TFile *infileMP2_3sig = new TFile(filename,"READ");
		if(!MultiPanelPlots) infileMP2_3sig=infileRes;

		sprintf(filename,"%s/%s/TGraphResults_3SUps_1sigma.root",storagedir,DefaultID);
		TFile *infileMP3_1sig = new TFile(filename,"READ");
		if(!MultiPanelPlots) infileMP3_1sig=infileRes;
		sprintf(filename,"%s/%s/TGraphResults_3SUps_2sigma.root",storagedir,DefaultID);
		TFile *infileMP3_2sig = new TFile(filename,"READ");
		if(!MultiPanelPlots) infileMP3_2sig=infileRes;
		sprintf(filename,"%s/%s/TGraphResults_3SUps_3sigma.root",storagedir,DefaultID);
		TFile *infileMP3_3sig = new TFile(filename,"READ");
		if(!MultiPanelPlots) infileMP3_3sig=infileRes;
		if(!PlotCompare) CompareFile1=infileRes;
		if(!PlotCompare||nComp<2) CompareFile2=infileRes;
		if(!PlotCompare||nComp<3) CompareFile3=infileRes;
		if(!PlotCompare||nComp<4) CompareFile4=infileRes;
		if(!PlotBrazilian) infileRes2sigma=infileRes;
		if(!PlotBrazilian) infileRes3sigma=infileRes;
		if(SBmSigPlots){
			CompareFile1=infileSyst1;
			CompareFile2=infileSyst2;
		}
		if(BGratioFits){
			sprintf(filename,"%s/macros/polFit/Systematics/%s/%s/TGraphResults_1SUps.root",basedir,SystID1Base,SystID1Specify);
			CompareFile1 = new TFile(filename,"READ");
			sprintf(filename,"%s/macros/polFit/Systematics/%s/%s/TGraphResults_2SUps.root",basedir,SystID2Base,SystID2Specify);
			CompareFile2 = new TFile(filename,"READ");
			sprintf(filename,"%s/macros/polFit/Systematics/%s/%s/TGraphResults_3SUps.root",basedir,SystID3Base,SystID3Specify);
			CompareFile3 = new TFile(filename,"READ");
		}



		char JobDir[200],StateDir[200],FigDir[200],SuppDir[200];
		sprintf(JobDir,"%s/macros/polFit/FinalResults/%s",basedir,JobID);
		sprintf(StateDir,"%s/%dSUps",JobDir,nState);
		sprintf(FigDir,"%s/Figures",StateDir);
		sprintf(SuppDir,"%s",JobDir);
		gSystem->mkdir(JobDir);
		gSystem->mkdir(StateDir);
		gSystem->mkdir(FigDir);

		char GraphName[200],axislabel[200], GraphNameOtherRap[200];
		double yMin,yMax;


// Declare variables needed for table production

		const int tabPtBins=ptBinMax-ptBinMin+1;
		const int tabcpmBins=cpmBinMax-cpmBinMin+1;		
		const int iParameters=12;

		double val_table[iParameters+1][tabPtBins][tabcpmBins];
		double errHigh_table[iParameters+1][tabPtBins][tabcpmBins];
		double errLow_table[iParameters+1][tabPtBins][tabcpmBins];
		double syst_table[iParameters+1][tabPtBins][tabcpmBins][nSystematics+1];
		double errHighTotal1_table[iParameters+1][tabPtBins][tabcpmBins];
		double errLowTotal1_table[iParameters+1][tabPtBins][tabcpmBins];
		double errHighTotal2_table[iParameters+1][tabPtBins][tabcpmBins];
		double errLowTotal2_table[iParameters+1][tabPtBins][tabcpmBins];
		double errHighTotal3_table[iParameters+1][tabPtBins][tabcpmBins];
		double errLowTotal3_table[iParameters+1][tabPtBins][tabcpmBins];
		double cpmmean_table[iParameters+1][tabPtBins][tabcpmBins];


		   TCanvas *MPcanvasCS;
		   TCanvas *MPcanvasHX;
		   TCanvas *MPcanvasPX;
		   TCanvas *MPcanvasCS_rap1_pt1;
		   TCanvas *MPcanvasHX_rap1_pt1;
		   TCanvas *MPcanvasPX_rap1_pt1;
		   TCanvas *MPcanvasCS_rap1_pt2;
		   TCanvas *MPcanvasHX_rap1_pt2;
		   TCanvas *MPcanvasPX_rap1_pt2;
		   TCanvas *MPcanvasTilde;
		   TCanvas *MPcanvasCDF;

		for(int iLam = 1; iLam<iParameters+1; iLam++){

		for(int rapBin = 1; rapBin < 2; rapBin++){
		for(int ptBin = ptBinMin; ptBin < ptBinMax+1; ptBin++){
		if(iLam==1)  sprintf(GraphName,"lth_CS_rap%d_pt%d",rapBin,ptBin);
		if(iLam==2)  sprintf(GraphName,"lph_CS_rap%d_pt%d",rapBin,ptBin);
		if(iLam==3)  sprintf(GraphName,"ltp_CS_rap%d_pt%d",rapBin,ptBin);

		if(iLam==4)  sprintf(GraphName,"ltilde_CS_rap%d_pt%d",rapBin,ptBin);

		if(iLam==5)  sprintf(GraphName,"lth_HX_rap%d_pt%d",rapBin,ptBin);
		if(iLam==6)  sprintf(GraphName,"lph_HX_rap%d_pt%d",rapBin,ptBin);
		if(iLam==7)  sprintf(GraphName,"ltp_HX_rap%d_pt%d",rapBin,ptBin);

		if(iLam==8) sprintf(GraphName,"ltilde_HX_rap%d_pt%d",rapBin,ptBin);

		if(iLam==9) sprintf(GraphName,"lth_PX_rap%d_pt%d",rapBin,ptBin);
		if(iLam==10) sprintf(GraphName,"lph_PX_rap%d_pt%d",rapBin,ptBin);
		if(iLam==11) sprintf(GraphName,"ltp_PX_rap%d_pt%d",rapBin,ptBin);

		if(iLam==12) sprintf(GraphName,"ltilde_PX_rap%d_pt%d",rapBin,ptBin);

		if(ptBin==1){
		if(iLam==1)  sprintf(GraphNameOtherRap,"lth_CS_rap1_pt2");
		if(iLam==2)  sprintf(GraphNameOtherRap,"lph_CS_rap1_pt2");
		if(iLam==3)  sprintf(GraphNameOtherRap,"ltp_CS_rap1_pt2");
		if(iLam==4)  sprintf(GraphNameOtherRap,"ltilde_CS_rap1_pt2");

		if(iLam==5)  sprintf(GraphNameOtherRap,"lth_HX_rap1_pt2");
		if(iLam==6)  sprintf(GraphNameOtherRap,"lph_HX_rap1_pt2");
		if(iLam==7)  sprintf(GraphNameOtherRap,"ltp_HX_rap1_pt2");

		if(iLam==8) sprintf(GraphNameOtherRap,"ltilde_HX_rap1_pt2");

		if(iLam==9) sprintf(GraphNameOtherRap,"lth_PX_rap1_pt2");
		if(iLam==10) sprintf(GraphNameOtherRap,"lph_PX_rap1_pt2");
		if(iLam==11) sprintf(GraphNameOtherRap,"ltp_PX_rap1_pt2");

		if(iLam==12) sprintf(GraphNameOtherRap,"ltilde_PX_rap1_pt2");
		}

		if(ptBin==2){
		if(iLam==1)  sprintf(GraphNameOtherRap,"lth_CS_rap1_pt1");
		if(iLam==2)  sprintf(GraphNameOtherRap,"lph_CS_rap1_pt1");
		if(iLam==3)  sprintf(GraphNameOtherRap,"ltp_CS_rap1_pt1");

		if(iLam==4)  sprintf(GraphNameOtherRap,"ltilde_CS_rap1_pt1");

		if(iLam==5)  sprintf(GraphNameOtherRap,"lth_HX_rap1_pt1");
		if(iLam==6)  sprintf(GraphNameOtherRap,"lph_HX_rap1_pt1");
		if(iLam==7)  sprintf(GraphNameOtherRap,"ltp_HX_rap1_pt1");

		if(iLam==8) sprintf(GraphNameOtherRap,"ltilde_HX_rap1_pt1");

		if(iLam==9) sprintf(GraphNameOtherRap,"lth_PX_rap1_pt1");
		if(iLam==10) sprintf(GraphNameOtherRap,"lph_PX_rap1_pt1");
		if(iLam==11) sprintf(GraphNameOtherRap,"ltp_PX_rap1_pt1");


		if(iLam==12) sprintf(GraphNameOtherRap,"ltilde_PX_rap1_pt1");
		}



		char beginLamLabel[200];
		if(PlotSystematics) sprintf(beginLamLabel,"#Delta");
		if(PlotFinalData) sprintf(beginLamLabel,"");
		if(PlotSystematics&&!PlotAsymm) sprintf(beginLamLabel,"#sigma");
		char endLamLabel[200];
		sprintf(endLamLabel,"");


		if(PlotSystematics)
		{
		if(iLam==1)  sprintf(axislabel,"(%s#lambda^{CS}_{#vartheta}%s)^{2}",beginLamLabel,endLamLabel);
		if(iLam==2)  sprintf(axislabel,"(%s#lambda^{CS}_{#varphi}%s)^{2}",beginLamLabel,endLamLabel);
		if(iLam==3)  sprintf(axislabel,"(%s#lambda^{CS}_{#vartheta#varphi}%s)^{2}",beginLamLabel,endLamLabel);
		if(iLam==4)  sprintf(axislabel,"(%s#tilde{#lambda}^{CS}%s)^{2}",beginLamLabel,endLamLabel);
		if(iLam==5)  sprintf(axislabel,"(%s#lambda^{HX}_{#vartheta}%s)^{2}",beginLamLabel,endLamLabel);
		if(iLam==6)  sprintf(axislabel,"(%s#lambda^{HX}_{#varphi}%s)^{2}",beginLamLabel,endLamLabel);
		if(iLam==7)  sprintf(axislabel,"(%s#lambda^{HX}_{#vartheta#varphi}%s)^{2}",beginLamLabel,endLamLabel);
		if(iLam==8) sprintf(axislabel,"(%s#tilde{#lambda}^{HX}%s)^{2}",beginLamLabel,endLamLabel);

		if(iLam==9) sprintf(axislabel,"(%s#lambda^{PX}_{#vartheta}%s)^{2}",beginLamLabel,endLamLabel);
		if(iLam==10) sprintf(axislabel,"(%s#lambda^{PX}_{#varphi}%s)^{2}",beginLamLabel,endLamLabel);
		if(iLam==11) sprintf(axislabel,"(%s#lambda^{PX}_{#vartheta#varphi}%s)^{2}",beginLamLabel,endLamLabel);
		if(iLam==12) sprintf(axislabel,"(%s#tilde{#lambda}^{PX}%s)^{2}",beginLamLabel,endLamLabel);//IfLamTildeClosure no PX
		if(iLam==12&&DeltaTildeplots) sprintf(axislabel,"%s#tilde{#lambda}%s)^{2}",beginLamLabel,endLamLabel);
		}
		
		if(iLam==1)  sprintf(axislabel,"#lambda^{CS}_{#vartheta}%s",beginLamLabel,endLamLabel);
		if(iLam==2)  sprintf(axislabel,"#lambda^{CS}_{#varphi}%s",beginLamLabel,endLamLabel);
		if(iLam==3)  sprintf(axislabel,"#lambda^{CS}_{#vartheta#varphi}%s",beginLamLabel,endLamLabel);
		if(iLam==4)  sprintf(axislabel,"#tilde{#lambda}^{CS}%s",beginLamLabel,endLamLabel);
		if(iLam==5)  sprintf(axislabel,"#lambda^{HX}_{#vartheta}%s",beginLamLabel,endLamLabel);
		if(iLam==6)  sprintf(axislabel,"#lambda^{HX}_{#varphi}%s",beginLamLabel,endLamLabel);
		if(iLam==7)  sprintf(axislabel,"#lambda^{HX}_{#vartheta#varphi}%s",beginLamLabel,endLamLabel);
		if(iLam==8) sprintf(axislabel,"#tilde{#lambda}^{HX}%s",beginLamLabel,endLamLabel);

		if(iLam==9) sprintf(axislabel,"#lambda^{PX}_{#vartheta}%s",beginLamLabel,endLamLabel);
		if(iLam==10) sprintf(axislabel,"#lambda^{PX}_{#varphi}%s",beginLamLabel,endLamLabel);
		if(iLam==11) sprintf(axislabel,"#lambda^{PX}_{#vartheta#varphi}%s",beginLamLabel,endLamLabel);
		if(iLam==12) sprintf(axislabel,"#tilde{#lambda}^{PX}%s",beginLamLabel,endLamLabel);//IfLamTildeClosure no PX
		if(iLam==12&&DeltaTildeplots) sprintf(axislabel,"%s#tilde{#lambda}%s",beginLamLabel,endLamLabel);

		if(iLam==1)  sprintf(filename,"%s/FinalResults_CS_lth_rap%d_pt%d.pdf",FigDir,rapBin,ptBin);
		if(iLam==2)  sprintf(filename,"%s/FinalResults_CS_lph_rap%d_pt%d.pdf",FigDir,rapBin,ptBin);
		if(iLam==3)  sprintf(filename,"%s/FinalResults_CS_ltp_rap%d_pt%d.pdf",FigDir,rapBin,ptBin);
		if(iLam==4)  sprintf(filename,"%s/FinalResults_CS_ltilde_rap%d_pt%d.pdf",FigDir,rapBin,ptBin);
		if(iLam==5)  sprintf(filename,"%s/FinalResults_HX_lth_rap%d_pt%d.pdf",FigDir,rapBin,ptBin);
		if(iLam==6)  sprintf(filename,"%s/FinalResults_HX_lph_rap%d_pt%d.pdf",FigDir,rapBin,ptBin);
		if(iLam==7)  sprintf(filename,"%s/FinalResults_HX_ltp_rap%d_pt%d.pdf",FigDir,rapBin,ptBin);
		if(iLam==8) sprintf(filename,"%s/FinalResults_HX_ltilde_rap%d_pt%d.pdf",FigDir,rapBin,ptBin);
		if(iLam==9) sprintf(filename,"%s/FinalResults_PX_lth_rap%d_pt%d.pdf",FigDir,rapBin,ptBin);
		if(iLam==10) sprintf(filename,"%s/FinalResults_PX_lph_rap%d_pt%d.pdf",FigDir,rapBin,ptBin);
		if(iLam==11) sprintf(filename,"%s/FinalResults_PX_ltp_rap%d_pt%d.pdf",FigDir,rapBin,ptBin);
		if(iLam==12) sprintf(filename,"%s/FinalResults_PX_ltilde_rap%d_pt%d.pdf",FigDir,rapBin,ptBin);



		if(BGratioChi2Fits) sprintf(axislabel,"#chi^{2} / ndf");

		int nFrame=0;

		if(iLam>0&&iLam<5) nFrame=1;
		if(iLam>4&&iLam<9) nFrame=2;
		if(iLam>8&&iLam<13) nFrame=3;

		yMin=-1.1;
		yMax=1.1;

		if(iLam==2||iLam==6||iLam==10||iLam==3||iLam==7||iLam==11){
			yMin=-0.35;
			yMax=0.35;
		}

		if(iLam==4||iLam==8||iLam==12){
			yMin=-1.1;
			yMax=1.1;
		}

		if(PlotBrazilian){
//			yMin=-1.5;
//			yMax=1.5;
			yMin=-1.275;
			yMax=1.275;

			if(iLam==2||iLam==6||iLam==10||iLam==3||iLam==7||iLam==11){
				yMin=-0.55;
				yMax=0.55;
			}

			if(iLam==6||iLam==8||iLam==12){
//				yMin=-1.5;
//				yMax=2.1;
				yMin=-1.;
				yMax=1.75;
			}
		} 
		
		if(PlotSystematics&&!PlotAsymm){
//			yMin=-1.5;
//			yMax=1.5;
			yMin=-0.4;
			yMax=0.4;

			if(iLam==2||iLam==6||iLam==10||iLam==3||iLam==7||iLam==11){
				yMin=-0.0075;
				yMax=0.0075;
			}

			if(iLam==6||iLam==8||iLam==12){
//				yMin=-1.5;
//				yMax=2.1;
				yMin=-.4;
				yMax=.4;
			}
		} 
//		yMin=-5.5; //ifPull
//		yMax=5.5; //ifPull

// Background Pol Fits:

		if(PlotBG0plots){
		yMin=-2;
		yMax=5;

		if(iLam==2||iLam==8||iLam==14||iLam==3||iLam==9||iLam==15){
			yMin=-1.5;
			yMax=1.5;
		}

		if(iLam==6||iLam==12||iLam==18){
			yMin=-7.5;
			yMax=20;
		}
		}

/*		if(SBmSigPlots){
			yMin=-2;
			yMax=2;
			if(iLam==2||iLam==8||iLam==14||iLam==3||iLam==9||iLam==15){
				yMin=-0.6;
				yMax=0.6;
			}
			if(iLam==6||iLam==12||iLam==18){
				yMin=-6;
				yMax=6;
			}
		} */

/*		if(BGratioChi2Fits){
			yMin=0.1;
			yMax=30;
		} */
/*				yMin=-4;
				yMax=4;
				if(iLam==2||iLam==8||iLam==14||iLam==3||iLam==9||iLam==15){
					yMin=-4;
					yMax=4;
				}
				if(iLam==6||iLam==12||iLam==18){
					yMin=-4;
					yMax=4;
				}
*/

//		if(CompareSyst||BGratioFits){
/*			if(BGratioFits){
		yMin=-2.5;
		yMax=2.5;
		if(iLam==2||iLam==8||iLam==14||iLam==3||iLam==9||iLam==15){
			yMin=-2.5;
			yMax=2.5;
		}
		if(iLam==6||iLam==12||iLam==18){
			yMin=-2.5;
			yMax=2.5;
		}
		} */


		TGraphAsymmErrors* graphDefaultRes = (TGraphAsymmErrors*) infileRes->Get(GraphName);
		TGraphAsymmErrors* graphDefaultRes1sigma = (TGraphAsymmErrors*) infileRes1sigma->Get(GraphName);
		TGraphAsymmErrors* graphDefaultRes2sigma = (TGraphAsymmErrors*) infileRes2sigma->Get(GraphName);
		TGraphAsymmErrors* graphDefaultRes3sigma = (TGraphAsymmErrors*) infileRes3sigma->Get(GraphName);
		TGraphAsymmErrors* graphDefaultStat = (TGraphAsymmErrors*) infileStat->Get(GraphName);
		TGraphAsymmErrors* graphSyst1 = (TGraphAsymmErrors*) infileSyst1->Get(GraphName);
		TGraphAsymmErrors* graphSyst2 = (TGraphAsymmErrors*) infileSyst2->Get(GraphName);
		TGraphAsymmErrors* graphSyst3 = (TGraphAsymmErrors*) infileSyst3->Get(GraphName);
		TGraphAsymmErrors* graphSyst4 = (TGraphAsymmErrors*) infileSyst4->Get(GraphName);
		TGraphAsymmErrors* graphSyst5 = (TGraphAsymmErrors*) infileSyst5->Get(GraphName);
		TGraphAsymmErrors* graphSyst6 = (TGraphAsymmErrors*) infileSyst6->Get(GraphName);
		TGraphAsymmErrors* graphSyst7 = (TGraphAsymmErrors*) infileSyst7->Get(GraphName);
		TGraphAsymmErrors* graphSyst8 = (TGraphAsymmErrors*) infileSyst8->Get(GraphName);


		TGraphAsymmErrors* graphCompareFile1 = (TGraphAsymmErrors*) CompareFile1->Get(GraphName);
		TGraphAsymmErrors* graphCompareFile2 = (TGraphAsymmErrors*) CompareFile2->Get(GraphName);
		TGraphAsymmErrors* graphCompareFile3 = (TGraphAsymmErrors*) CompareFile3->Get(GraphName);
		TGraphAsymmErrors* graphCompareFile4 = (TGraphAsymmErrors*) CompareFile4->Get(GraphName);



		int nBinscpm=cpmBinMax-cpmBinMin+1;
		double cpmCentre_[nBinscpm];
		double cpmCentreErr_low[nBinscpm];
		double cpmCentreErr_high[nBinscpm];
		double lmean[nBinscpm];
		double lmean_errlow[nBinscpm];
		double lmean_errhigh[nBinscpm];
		double lmean_errmean[nBinscpm];
		double lmean_errmean_minus[nBinscpm];
		double lmeanTotal1_errlow[nBinscpm];
		double lmeanTotal1_errhigh[nBinscpm];
		double lmeanTotal2_errlow[nBinscpm];
		double lmeanTotal2_errhigh[nBinscpm];
		double lmeanTotal3_errlow[nBinscpm];
		double lmeanTotal3_errhigh[nBinscpm];
		double cpmCentre_ForTable[nBinscpm];
		double lmeanBuff[nBinscpm];

		double fit_lmean_errmean[nBinscpm];
		double fit_lmean_errlow[nBinscpm];
		double fit_lmean_errhigh[nBinscpm];

		double SystError1[nBinscpm];
		double SystError2[nBinscpm];
		double SystError3[nBinscpm];
		double SystError4[nBinscpm];
		double SystError5[nBinscpm];
		double SystError6[nBinscpm];
		double SystError7[nBinscpm];
		double SystError8[nBinscpm];
		double SystError[nBinscpm];
		double ErrSystError1[nBinscpm];
		double ErrSystError2[nBinscpm];
		double ErrSystError3[nBinscpm];
		double ErrSystError4[nBinscpm];
		double ErrSystError5[nBinscpm];
		double ErrSystError6[nBinscpm];
		double ErrSystError7[nBinscpm];
		double ErrSystError8[nBinscpm];

		double SystError12[nBinscpm];
		double SystError123[nBinscpm];
		double SystError1234[nBinscpm];
		double SystError12345[nBinscpm];
		double SystError123456[nBinscpm];
		double SystError1234567[nBinscpm];
		double SystError12345678[nBinscpm];

		double Buffer[nBinscpm];


		int cpm=0;
		for(int cpmBin = cpmBinMin; cpmBin < cpmBinMax+1; cpmBin++) {
		
			graphDefaultRes->GetPoint(cpmBin-1,cpmCentre_[cpm],lmean[cpm]);
			cpmCentreErr_high[cpm]=graphDefaultRes->GetErrorXhigh(cpmBin-1);
			cpmCentreErr_low[cpm]=graphDefaultRes->GetErrorXlow(cpmBin-1);
			lmean_errhigh[cpm]=graphDefaultRes->GetErrorYhigh(cpmBin-1);

			lmean_errlow[cpm]=graphDefaultRes->GetErrorYlow(cpmBin-1);
			lmean_errmean[cpm]=(lmean_errlow[cpm]+lmean_errhigh[cpm])/2.;
			lmean_errmean_minus[cpm]=-(lmean_errlow[cpm]+lmean_errhigh[cpm])/2.;

			lmeanTotal1_errlow[cpm]=lmean_errlow[cpm];
			lmeanTotal1_errhigh[cpm]=lmean_errhigh[cpm];
//			cout<<"the mean error is for bin pt"<<ptBin<<" cpm "<<cpm<<" is "<<lmeanTotal1_errlow[cpm]<<endl;

			lmeanTotal2_errlow[cpm]=graphDefaultRes2sigma->GetErrorYlow(cpmBin-1);
			lmeanTotal2_errhigh[cpm]=graphDefaultRes2sigma->GetErrorYhigh(cpmBin-1);
			lmeanTotal3_errlow[cpm]=graphDefaultRes3sigma->GetErrorYlow(cpmBin-1);
			lmeanTotal3_errhigh[cpm]=graphDefaultRes3sigma->GetErrorYhigh(cpmBin-1);

			if(PlotAlteredPPDResults){
				graphDefaultRes->GetPoint(cpmBin-1,cpmCentre_[cpm],lmeanBuff[cpm]);
				lmean_errhigh[cpm]=graphDefaultStat->GetErrorYhigh(cpmBin-1);
				lmean_errlow[cpm]=graphDefaultStat->GetErrorYlow(cpmBin-1);
				lmean_errmean[cpm]=(lmean_errlow[cpm]+lmean_errhigh[cpm])/2.;
				lmean_errmean_minus[cpm]=-(lmean_errlow[cpm]+lmean_errhigh[cpm])/2.;
			}
			cpmCentre_ForTable[cpm]=cpmCentre_[cpm];
			if(nSystematics>0) {graphSyst1->GetPoint(cpmBin-1,Buffer[cpm],SystError1[cpm]);	ErrSystError1[cpm]=graphSyst1->GetErrorY(cpm);    if(!PlotAsymm) SystError1[cpm]=TMath::Abs(SystError1[cpm]); }
			if(nSystematics>1) {graphSyst2->GetPoint(cpmBin-1,Buffer[cpm],SystError2[cpm]);	ErrSystError2[cpm]=graphSyst2->GetErrorY(cpm);    if(!PlotAsymm) SystError2[cpm]=TMath::Abs(SystError2[cpm]); }
			if(nSystematics>2) {graphSyst3->GetPoint(cpmBin-1,Buffer[cpm],SystError3[cpm]);	ErrSystError3[cpm]=graphSyst3->GetErrorY(cpm);    if(!PlotAsymm) SystError3[cpm]=TMath::Abs(SystError3[cpm]); }
			if(nSystematics>3) {graphSyst4->GetPoint(cpmBin-1,Buffer[cpm],SystError4[cpm]);	ErrSystError4[cpm]=graphSyst4->GetErrorY(cpm);    if(!PlotAsymm) SystError4[cpm]=TMath::Abs(SystError4[cpm]); }
			if(nSystematics>4) {graphSyst5->GetPoint(cpmBin-1,Buffer[cpm],SystError5[cpm]);	ErrSystError5[cpm]=graphSyst5->GetErrorY(cpm);    if(!PlotAsymm) SystError5[cpm]=TMath::Abs(SystError5[cpm]); }
			if(nSystematics>5) {graphSyst6->GetPoint(cpmBin-1,Buffer[cpm],SystError6[cpm]);	ErrSystError6[cpm]=graphSyst6->GetErrorY(cpm);    if(!PlotAsymm) SystError6[cpm]=TMath::Abs(SystError6[cpm]); }
			if(nSystematics>6) 
			{graphSyst7->GetPoint(cpmBin-1,Buffer[cpm],SystError7[cpm]);
			ErrSystError7[cpm]=graphSyst7->GetErrorY(cpm); 
			if(!PlotAsymm) SystError7[cpm]=TMath::Abs(SystError7[cpm]); 			}
			if(nSystematics>7) {graphSyst8->GetPoint(cpmBin-1,Buffer[cpm],SystError8[cpm]);	ErrSystError8[cpm]=graphSyst8->GetErrorY(cpm);    if(!PlotAsymm) SystError8[cpm]=TMath::Abs(SystError8[cpm]); }
			double SquaredSysts;
			if(nSystematics==1) SquaredSysts=SystError1[cpm]*SystError1[cpm];
			if(nSystematics==2) SquaredSysts=SystError1[cpm]*SystError1[cpm]+SystError2[cpm]*SystError2[cpm];
			if(nSystematics==3) SquaredSysts=SystError1[cpm]*SystError1[cpm]+SystError2[cpm]*SystError2[cpm]+SystError3[cpm]*SystError3[cpm];
			if(nSystematics==4) SquaredSysts=SystError1[cpm]*SystError1[cpm]+SystError2[cpm]*SystError2[cpm]+SystError3[cpm]*SystError3[cpm]+SystError4[cpm]*SystError4[cpm];
			if(nSystematics==5) SquaredSysts=SystError1[cpm]*SystError1[cpm]+SystError2[cpm]*SystError2[cpm]+SystError3[cpm]*SystError3[cpm]+SystError4[cpm]*SystError4[cpm]+SystError5[cpm]*SystError5[cpm];
			if(nSystematics==6) SquaredSysts=SystError1[cpm]*SystError1[cpm]+SystError2[cpm]*SystError2[cpm]+SystError3[cpm]*SystError3[cpm]+SystError4[cpm]*SystError4[cpm]+SystError5[cpm]*SystError5[cpm]+SystError6[cpm]*SystError6[cpm];
			if(nSystematics==7) SquaredSysts=SystError1[cpm]*SystError1[cpm]+SystError2[cpm]*SystError2[cpm]+SystError3[cpm]*SystError3[cpm]+SystError4[cpm]*SystError4[cpm]+SystError5[cpm]*SystError5[cpm]+SystError6[cpm]*SystError6[cpm]+SystError7[cpm]*SystError7[cpm];
//			cout<<"squared syst = "<<SquaredSysts<<endl;
			if(nSystematics==8) SquaredSysts=SystError1[cpm]*SystError1[cpm]+SystError2[cpm]*SystError2[cpm]+SystError3[cpm]*SystError3[cpm]+SystError4[cpm]*SystError4[cpm]+SystError5[cpm]*SystError5[cpm]+SystError6[cpm]*SystError6[cpm]+SystError7[cpm]*SystError7[cpm]+SystError8[cpm]*SystError8[cpm];
			
			SystError[cpm]=TMath::Sqrt(SquaredSysts);
//			cout<<"syst error = "<<SystError[cpm]<<endl;

			if(nSystematics>0) {graphSyst1->GetPoint(cpmBin-1,Buffer[cpm],SystError1[cpm]);	ErrSystError1[cpm]=graphSyst1->GetErrorY(cpm);    if(!PlotAsymm) SystError1[cpm]=pow(TMath::Abs(SystError1[cpm]),2); }
			if(nSystematics>1) {graphSyst2->GetPoint(cpmBin-1,Buffer[cpm],SystError2[cpm]);	ErrSystError2[cpm]=graphSyst2->GetErrorY(cpm);    if(!PlotAsymm) SystError2[cpm]=pow(TMath::Abs(SystError2[cpm]),2); }
			if(nSystematics>2) {graphSyst3->GetPoint(cpmBin-1,Buffer[cpm],SystError3[cpm]);	ErrSystError3[cpm]=graphSyst3->GetErrorY(cpm);    if(!PlotAsymm) SystError3[cpm]=pow(TMath::Abs(SystError3[cpm]),2); }
			if(nSystematics>3) {graphSyst4->GetPoint(cpmBin-1,Buffer[cpm],SystError4[cpm]);	ErrSystError4[cpm]=graphSyst4->GetErrorY(cpm);    if(!PlotAsymm) SystError4[cpm]=pow(TMath::Abs(SystError4[cpm]),2); }
			if(nSystematics>4) {graphSyst5->GetPoint(cpmBin-1,Buffer[cpm],SystError5[cpm]);	ErrSystError5[cpm]=graphSyst5->GetErrorY(cpm);    if(!PlotAsymm) SystError5[cpm]=pow(TMath::Abs(SystError5[cpm]),2); }
			if(nSystematics>5) {graphSyst6->GetPoint(cpmBin-1,Buffer[cpm],SystError6[cpm]);	ErrSystError6[cpm]=graphSyst6->GetErrorY(cpm);    if(!PlotAsymm) SystError6[cpm]=pow(TMath::Abs(SystError6[cpm]),2); }
			if(nSystematics>6) {graphSyst7->GetPoint(cpmBin-1,Buffer[cpm],SystError7[cpm]); ErrSystError7[cpm]=graphSyst7->GetErrorY(cpm);    if(!PlotAsymm) SystError7[cpm]=pow(TMath::Abs(SystError7[cpm]),2); }
			if(nSystematics>7) {graphSyst8->GetPoint(cpmBin-1,Buffer[cpm],SystError8[cpm]);	ErrSystError8[cpm]=graphSyst8->GetErrorY(cpm);    if(!PlotAsymm) SystError8[cpm]=pow(TMath::Abs(SystError8[cpm]),2); }
			
			SystError12[cpm]=SystError1[cpm]+SystError2[cpm]; if(PlotAsymm) SystError12[cpm]=SystError2[cpm];
			SystError123[cpm]=SystError1[cpm]+SystError2[cpm]+SystError3[cpm]; if(PlotAsymm) SystError123[cpm]=SystError3[cpm];
			SystError1234[cpm]=SystError1[cpm]+SystError2[cpm]+SystError3[cpm]+SystError4[cpm]; if(PlotAsymm) SystError1234[cpm]=SystError4[cpm];
			SystError12345[cpm]=SystError1[cpm]+SystError2[cpm]+SystError3[cpm]+SystError4[cpm]+SystError5[cpm]; if(PlotAsymm) SystError12345[cpm]=SystError5[cpm]; if(DeltaTildeplots) SystError12345[cpm]=-SystError5[cpm];//IfLamTildeClosure
			SystError123456[cpm]=SystError1[cpm]+SystError2[cpm]+SystError3[cpm]+SystError4[cpm]+SystError5[cpm]+SystError6[cpm]; if(PlotAsymm) SystError123456[cpm]=SystError6[cpm];
			SystError1234567[cpm]=SystError1[cpm]+SystError2[cpm]+SystError3[cpm]+SystError4[cpm]+SystError5[cpm]+SystError6[cpm]+SystError7[cpm]; if(PlotAsymm) SystError1234567[cpm]=SystError7[cpm];
			SystError12345678[cpm]=SystError1[cpm]+SystError2[cpm]+SystError3[cpm]+SystError4[cpm]+SystError5[cpm]+SystError6[cpm]+SystError7[cpm]+SystError8[cpm]; if(PlotAsymm) SystError12345678[cpm]=SystError8[cpm];

			fit_lmean_errmean[cpm]=TMath::Sqrt(SystError[cpm]*SystError[cpm]+lmean_errmean[cpm]*lmean_errmean[cpm]);
			fit_lmean_errlow[cpm]=TMath::Sqrt(SystError[cpm]*SystError[cpm]+lmean_errlow[cpm]*lmean_errlow[cpm]);
			fit_lmean_errhigh[cpm]=TMath::Sqrt(SystError[cpm]*SystError[cpm]+lmean_errhigh[cpm]*lmean_errhigh[cpm]);

// Fill table variables

			val_table[iLam][ptBin-1][cpm]=lmean[cpm];
			errHigh_table[iLam][ptBin-1][cpm]=lmean_errhigh[cpm];
			errLow_table[iLam][ptBin-1][cpm]=lmean_errlow[cpm];
			syst_table[iLam][ptBin-1][cpm][0]=SystError[cpm];
			syst_table[iLam][ptBin-1][cpm][1]=TMath::Abs(SystError1[cpm]);
			syst_table[iLam][ptBin-1][cpm][2]=TMath::Abs(SystError2[cpm]);
			syst_table[iLam][ptBin-1][cpm][3]=TMath::Abs(SystError3[cpm]);
			syst_table[iLam][ptBin-1][cpm][4]=TMath::Abs(SystError4[cpm]);
			syst_table[iLam][ptBin-1][cpm][5]=TMath::Abs(SystError5[cpm]);
			syst_table[iLam][ptBin-1][cpm][6]=TMath::Abs(SystError6[cpm]);
			syst_table[iLam][ptBin-1][cpm][7]=TMath::Abs(SystError7[cpm]);
			syst_table[iLam][ptBin-1][cpm][8]=TMath::Abs(SystError8[cpm]);

			errHighTotal1_table[iLam][ptBin-1][cpm]=lmeanTotal1_errhigh[cpm];
			errLowTotal1_table[iLam][ptBin-1][cpm]=lmeanTotal1_errlow[cpm];
			errHighTotal2_table[iLam][ptBin-1][cpm]=lmeanTotal2_errhigh[cpm];
			errLowTotal2_table[iLam][ptBin-1][cpm]=lmeanTotal2_errlow[cpm];
			errHighTotal3_table[iLam][ptBin-1][cpm]=lmeanTotal3_errhigh[cpm];
			errLowTotal3_table[iLam][ptBin-1][cpm]=lmeanTotal3_errlow[cpm];

			cpmmean_table[iLam][ptBin-1][cpm]=cpmCentre_ForTable[cpm];

		cpm++;
		}





		   gStyle->SetPalette(1,0);
		   gStyle->SetPadBottomMargin(0.12);
		   gStyle->SetPadLeftMargin(0.13);
		   gStyle->SetPadRightMargin(0.15);

		   gStyle->SetTickLength(-0.02, "xyz");
		   gStyle->SetLabelOffset(0.02, "x");
		   gStyle->SetLabelOffset(0.02, "y");
		   gStyle->SetTitleOffset(1.3, "x");
		   gStyle->SetTitleOffset(1.4, "y");
		   gStyle->SetTitleFillColor(kWhite);
		   

		TCanvas *plotCanvas = new TCanvas("plotCanvas","plotCanvas",1000,800);

		plotCanvas->SetFillColor(kWhite);
//		plotCanvas->SetGrid();
		plotCanvas->GetFrame()->SetFillColor(kWhite);
		plotCanvas->GetFrame()->SetBorderSize(0);
		plotCanvas->SetRightMargin(0.05) ;

		TH1F *plotHisto = new TH1F;
		if(!PlotMatt) plotHisto = plotCanvas->DrawFrame(onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL,yMin,onia::cpmRange[cpmBinMax],yMax);
		if(PlotVsComp) plotHisto = plotCanvas->DrawFrame(10.1,yMin,10.7,yMax);
		plotHisto->SetXTitle("#it{N}_{ch} ");
//				 plotHisto->GetXAxis->SetTextSize(0.045);
		if(PlotVsComp) plotHisto->SetXTitle("M_{#mu#mu} GeV");
		plotHisto->SetYTitle(axislabel);
		plotHisto->GetYaxis()->SetTitleOffset(0.85);
		plotHisto->GetXaxis()->SetTitleOffset(0.85);		
		plotHisto->GetYaxis()->SetLabelSize(.04);		
		plotHisto->GetXaxis()->SetLabelSize(.04);
		plotHisto->GetYaxis()->SetTitleSize(.063);		
		plotHisto->GetXaxis()->SetTitleSize(.063);		
		TLegend* plotcompLegend=new TLegend(0.13,0.7,0.6,0.9);
		plotcompLegend->SetFillStyle(0);
		plotcompLegend->SetFillColor(0);
//		plotcompLegend->SetTextFont(72);
		plotcompLegend->SetTextSize(0.04);
		plotcompLegend->SetBorderSize(0);
		char complegendentry[200];
		TGraphAsymmErrors *graphSyst = new TGraphAsymmErrors(nBinscpm,cpmCentre_,lmean,cpmCentreErr_low,cpmCentreErr_high,SystError,SystError);
		graphSyst->SetFillColor(kCyan-9);
		graphSyst->SetFillStyle(3001);
		char drawGraphStyle[200];
		sprintf(drawGraphStyle,"PE");


///////////////////////////////////////////////////////////////
//////////////Actual FinalDataResults Plotting ////////////////
///////////////////////////////////////////////////////////////

		double BG0MarkerSize=1.;


		if(!PlotBrazilian&&!SBmSigPlots&&!BGratioFits&&!SteerIndividuals&&!PlotMatt&&!PlotVsComp) graphSyst->Draw("2");//Comment if PlotBG0plots Low
		graphDefaultRes->SetMarkerColor(ToyMC::MarkerColor[nFrame]);
		graphDefaultRes->SetLineColor(ToyMC::MarkerColor[nFrame]);
		graphDefaultRes->SetMarkerStyle(ToyMC::MarkerStyle[nState][ptBin]);
		graphDefaultRes->SetMarkerSize(ToyMC::MarkerSize[nState][ptBin]);
		if(PlotBG0plots){
			graphDefaultRes->SetMarkerStyle(20);
			graphDefaultRes->SetMarkerSize(BG0MarkerSize);

		}
		if(SetCompStyle){
			graphDefaultRes->SetMarkerStyle(24);
			graphDefaultRes->SetMarkerSize(BG0MarkerSize);

		}
		if(!PlotBrazilian&&!SBmSigPlots&&!BGratioFits&&!SteerIndividuals&&!PlotMatt&&!PlotVsComp) graphDefaultRes->Draw(drawGraphStyle);//Comment if PlotBG0plots Low


///////////start added brazillian stuff
		if(PlotBrazilian&&!SteerIndividuals&&!PlotVsComp){


			int cpmOriginal;
			int nBinsOriginal;
			double cpmCentre_Original[nBinscpm];
			double lmean_Original[nBinscpm];
			double lmean_errlow_Original[nBinscpm];
			double lmean_errhigh_Original[nBinscpm];
			double cpmCentre_errlow_Original[nBinscpm];
			double cpmCentre_errhigh_Original[nBinscpm];


			nBinsOriginal=graphSyst->GetN();
			cpmOriginal=0;
			for(int cpmBinOriginal=1;cpmBinOriginal<nBinsOriginal+1;cpmBinOriginal++){
				graphSyst->GetPoint(cpmBinOriginal-1,cpmCentre_Original[cpmOriginal],lmean_Original[cpmOriginal]);
				lmean_errhigh_Original[cpmOriginal]=graphSyst->GetErrorYhigh(cpmBinOriginal-1);
				lmean_errlow_Original[cpmOriginal]=graphSyst->GetErrorYlow(cpmBinOriginal-1);
				cpmCentre_errhigh_Original[cpmOriginal]=graphSyst->GetErrorXhigh(cpmBinOriginal-1);
				cpmCentre_errlow_Original[cpmOriginal]=graphSyst->GetErrorXlow(cpmBinOriginal-1);
				/// Alter TGraph
				cpmCentre_errhigh_Original[cpmOriginal]=0.;
				cpmCentre_errlow_Original[cpmOriginal]=0.;
				cpmOriginal++;
			}
			graphSyst = new TGraphAsymmErrors(nBinsOriginal,cpmCentre_Original,lmean_Original,cpmCentre_errlow_Original,cpmCentre_errhigh_Original,lmean_errlow_Original,lmean_errhigh_Original);

			graphSyst->SetLineColor(kBlack);
			graphSyst->SetMarkerColor(ToyMC::MarkerColor[nFrame]);
			graphSyst->SetLineColor(ToyMC::MarkerColor[nFrame]);
			graphSyst->SetMarkerStyle(ToyMC::MarkerStyle[nState][ptBin]);
			graphSyst->SetMarkerSize(ToyMC::MarkerSize[nState][ptBin]);

			nBinsOriginal=graphDefaultStat->GetN();
			cpmOriginal=0;
			for(int cpmBinOriginal=1;cpmBinOriginal<nBinsOriginal+1;cpmBinOriginal++){
				graphDefaultStat->GetPoint(cpmBinOriginal-1,cpmCentre_Original[cpmOriginal],lmean_Original[cpmOriginal]);
				lmean_errhigh_Original[cpmOriginal]=graphDefaultStat->GetErrorYhigh(cpmBinOriginal-1);
				lmean_errlow_Original[cpmOriginal]=graphDefaultStat->GetErrorYlow(cpmBinOriginal-1);
				cpmCentre_errhigh_Original[cpmOriginal]=graphDefaultStat->GetErrorXhigh(cpmBinOriginal-1);
				cpmCentre_errlow_Original[cpmOriginal]=graphDefaultStat->GetErrorXlow(cpmBinOriginal-1);
				/// Alter TGraph
				cpmCentre_errhigh_Original[cpmOriginal]=0.;
				cpmCentre_errlow_Original[cpmOriginal]=0.;
				cpmOriginal++;
			}
			graphDefaultStat = new TGraphAsymmErrors(nBinsOriginal,cpmCentre_Original,lmean_Original,cpmCentre_errlow_Original,cpmCentre_errhigh_Original,lmean_errlow_Original,lmean_errhigh_Original);

			graphDefaultStat->SetLineColor(kBlack);
			graphDefaultStat->SetMarkerColor(ToyMC::MarkerColor[nFrame]);
			graphDefaultStat->SetLineColor(ToyMC::MarkerColor[nFrame]);
			graphDefaultStat->SetMarkerStyle(ToyMC::MarkerStyle[nState][ptBin]);
			graphDefaultStat->SetMarkerSize(ToyMC::MarkerSize[nState][ptBin]);

			nBinsOriginal=graphDefaultRes1sigma->GetN();
			cpmOriginal=0;
			for(int cpmBinOriginal=1;cpmBinOriginal<nBinsOriginal+1;cpmBinOriginal++){
			cout<<"graph def is: "<<filename<<endl;
				graphDefaultRes1sigma->GetPoint(cpmBinOriginal-1,cpmCentre_Original[cpmOriginal],lmean_Original[cpmOriginal]);
				lmean_errhigh_Original[cpmOriginal]=graphDefaultRes1sigma->GetErrorYhigh(cpmBinOriginal-1);
				lmean_errlow_Original[cpmOriginal]=graphDefaultRes1sigma->GetErrorYlow(cpmBinOriginal-1);
				cpmCentre_errhigh_Original[cpmOriginal]=graphDefaultRes1sigma->GetErrorXhigh(cpmBinOriginal-1);
				cpmCentre_errlow_Original[cpmOriginal]=graphDefaultRes1sigma->GetErrorXlow(cpmBinOriginal-1);
				/// Alter TGraph
				cpmCentre_errhigh_Original[cpmOriginal]=ColordBandWidth;
				cpmCentre_errlow_Original[cpmOriginal]=ColordBandWidth;
				cpmOriginal++;
			}
			graphDefaultRes1sigma = new TGraphAsymmErrors(nBinsOriginal,cpmCentre_Original,lmean_Original,cpmCentre_errlow_Original,cpmCentre_errhigh_Original,lmean_errlow_Original,lmean_errhigh_Original);

			nBinsOriginal=graphDefaultRes2sigma->GetN();
			cpmOriginal=0;
			for(int cpmBinOriginal=1;cpmBinOriginal<nBinsOriginal+1;cpmBinOriginal++){
			cout<<"graph def 2 is: "<<infileRes2sigma->Get(GraphName)<<endl;
				graphDefaultRes2sigma->GetPoint(cpmBinOriginal-1,cpmCentre_Original[cpmOriginal],lmean_Original[cpmOriginal]);
				lmean_errhigh_Original[cpmOriginal]=graphDefaultRes2sigma->GetErrorYhigh(cpmBinOriginal-1);
				lmean_errlow_Original[cpmOriginal]=graphDefaultRes2sigma->GetErrorYlow(cpmBinOriginal-1);
				cpmCentre_errhigh_Original[cpmOriginal]=graphDefaultRes2sigma->GetErrorXhigh(cpmBinOriginal-1);
				cpmCentre_errlow_Original[cpmOriginal]=graphDefaultRes2sigma->GetErrorXlow(cpmBinOriginal-1);
				/// Alter TGraph
				cpmCentre_errhigh_Original[cpmOriginal]=ColordBandWidth;
				cpmCentre_errlow_Original[cpmOriginal]=ColordBandWidth;
				cpmOriginal++;
			}
			graphDefaultRes2sigma = new TGraphAsymmErrors(nBinsOriginal,cpmCentre_Original,lmean_Original,cpmCentre_errlow_Original,cpmCentre_errhigh_Original,lmean_errlow_Original,lmean_errhigh_Original);

			nBinsOriginal=graphDefaultRes3sigma->GetN();
			cpmOriginal=0;
			for(int cpmBinOriginal=1;cpmBinOriginal<nBinsOriginal+1;cpmBinOriginal++){
			cout<<"graph def 3 is: "<<infileRes3sigma->Get(GraphName)<<endl;
				graphDefaultRes3sigma->GetPoint(cpmBinOriginal-1,cpmCentre_Original[cpmOriginal],lmean_Original[cpmOriginal]);
				lmean_errhigh_Original[cpmOriginal]=graphDefaultRes3sigma->GetErrorYhigh(cpmBinOriginal-1);
				lmean_errlow_Original[cpmOriginal]=graphDefaultRes3sigma->GetErrorYlow(cpmBinOriginal-1);
				cpmCentre_errhigh_Original[cpmOriginal]=graphDefaultRes3sigma->GetErrorXhigh(cpmBinOriginal-1);
				cpmCentre_errlow_Original[cpmOriginal]=graphDefaultRes3sigma->GetErrorXlow(cpmBinOriginal-1);
				/// Alter TGraph
				cpmCentre_errhigh_Original[cpmOriginal]=ColordBandWidth;
				cpmCentre_errlow_Original[cpmOriginal]=ColordBandWidth;
				cpmOriginal++;
			}
			graphDefaultRes3sigma = new TGraphAsymmErrors(nBinsOriginal,cpmCentre_Original,lmean_Original,cpmCentre_errlow_Original,cpmCentre_errhigh_Original,lmean_errlow_Original,lmean_errhigh_Original);

			graphDefaultRes1sigma->SetFillColor(OneSigColor);
			graphDefaultRes1sigma->SetFillStyle(1001);
			graphDefaultRes2sigma->SetFillColor(TwoSigColor);
			graphDefaultRes2sigma->SetFillStyle(1001);
			graphDefaultRes3sigma->SetFillColor(ThreeSigColor);
			graphDefaultRes3sigma->SetFillStyle(1001);
			graphDefaultRes3sigma->Draw("2");
			graphDefaultRes2sigma->Draw("2");
			graphDefaultRes1sigma->Draw("2");
			if(!PlotAlteredPPDResults) graphSyst->Draw(drawGraphStyle);
			if(PlotAlteredPPDResults) graphDefaultStat->Draw(drawGraphStyle);
		}///////////////end added brazillian stuff


		if(CompareSyst){
			TLine* extreme0 = new TLine( onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL, 0, onia::cpmRange[cpmBinMax] ,0);
			extreme0->SetLineWidth( 2 );
			extreme0->SetLineStyle( 1 );
			extreme0->SetLineColor( kBlack );
			extreme0->Draw( "same" );
		}

		sprintf(complegendentry,"%s",LegendEntryDefID);//FindLegend
		if(!SBmSigPlots&&!BGratioFits) plotcompLegend->AddEntry(graphDefaultRes,complegendentry,"lp");





		if(PlotCompare){
		graphCompareFile1->SetMarkerColor(kRed);
		graphCompareFile1->SetLineColor(kRed);
		graphCompareFile1->SetMarkerStyle(28);
//		graphCompareFile1->SetLineWidth(3);
		graphCompareFile2->SetMarkerColor(kBlue);
		graphCompareFile2->SetLineColor(kBlue);
		graphCompareFile2->SetMarkerStyle(30);
		graphCompareFile3->SetMarkerColor(kGreen-2);
		graphCompareFile3->SetLineColor(kGreen-2);
		graphCompareFile3->SetMarkerStyle(3);
		graphCompareFile4->SetMarkerColor(kOrange);
		graphCompareFile4->SetLineColor(kOrange);
		graphCompareFile4->SetMarkerStyle(5);
		if(PlotBG0plots||SetCompStyle){
			graphCompareFile1->SetMarkerStyle(24);
			graphCompareFile2->SetMarkerStyle(24);
			graphCompareFile3->SetMarkerStyle(24);
			graphCompareFile4->SetMarkerStyle(24);
			graphCompareFile1->SetMarkerSize(BG0MarkerSize);
			graphCompareFile2->SetMarkerSize(BG0MarkerSize);
			graphCompareFile3->SetMarkerSize(BG0MarkerSize);
			graphCompareFile4->SetMarkerSize(BG0MarkerSize);

		}

		TLine* extreme0 = new TLine( onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL, 0, onia::cpmRange[cpmBinMax] ,0);
		extreme0->SetLineWidth( 1 );
		extreme0->SetLineStyle( 2 );
		extreme0->SetLineColor( kBlack );
		extreme0->Draw( "same" );


		if(nComp>0){//FindLegend
		graphCompareFile1->Draw(drawGraphStyle);
		sprintf(complegendentry,"#lambda(LSB)-#lambda(sig. region)");
		sprintf(complegendentry,"%s",LegendEntryCompID1);
		plotcompLegend->AddEntry(graphCompareFile1,complegendentry,"lp");
		}
		if(nComp>1){
			graphCompareFile2->Draw(drawGraphStyle);
			sprintf(complegendentry,"#lambda(RSB)-#lambda(sig. region)");
			sprintf(complegendentry,"%s",LegendEntryCompID2);
		plotcompLegend->AddEntry(graphCompareFile2,complegendentry,"lp");
		}
		if(nComp>2){
		
			graphCompareFile3->Draw(drawGraphStyle);
		sprintf(complegendentry,"Right sided 1.5 sigma");
		sprintf(complegendentry,"%s",LegendEntryCompID3);
		plotcompLegend->AddEntry(graphCompareFile3,complegendentry,"lp");
		}
		if(nComp>3){
			graphCompareFile4->Draw(drawGraphStyle);
		sprintf(complegendentry,"%s",LegendEntryCompID4);
		plotcompLegend->AddEntry(graphCompareFile4,complegendentry,"lp");
		}


		}

		char texTex[200];
		if(ptBin==1) sprintf(texTex,"10 < #it{p}_{T} < 15 GeV ");
		if(ptBin==2) sprintf(texTex,"15 < #it{p}_{T} < 35 GeV");
		if(rapBinComb) sprintf(texTex,"      |#it{y}| < 1.2");
		 TLatex *text = new TLatex(onia::cpmRange[cpmBinMax]*0.35,yMin+(yMax-yMin)*0.066,texTex);
		 text->SetTextSize(0.045);
		 if(!SteerIndividuals&&!PlotMattForICHEP&&!PlotVsComp) text->Draw( "same" );


		 if(PlotBG0plots){
			char texTex2[200];
			sprintf(texTex2,"      |c#tau/#sigma_{c#tau}| < 2");
			 TLatex *text2 = new TLatex(onia::cpmRange[cpmBinMax]*0.7,yMin+(yMax-yMin)*0.122,texTex2);
			 text2->SetTextSize(0.05);
			 text2->Draw( "same" );
		 }




		 if(PlotFinalData&&DrawLatexStuff&&!PlotMattForICHEP){
			 cout<<"DRAW CMS preliminary Latex"<<endl;
		 double CentralsFontSize=0.035;
		 char text[200];
		 sprintf(text,"CMS preliminary");
		 cout<<text<<endl;
		 TLatex *CentralsText1 = new TLatex(11.5-DeltaXminOVERALL,yMin+(yMax-yMin)*0.76,text);
		 CentralsText1->SetTextSize(CentralsFontSize*1.25);
		 if(DrawPreliminary) CentralsText1->Draw( "same" );
		 sprintf(text,"L_{int} = 4.9 fb^{-1}");
		 cout<<text<<endl;
		 TLatex *CentralsText2 = new TLatex(11.5-DeltaXminOVERALL,yMin+(yMax-yMin)*0.935,text);
		 CentralsText2->SetTextSize(CentralsFontSize);
		 CentralsText2->Draw( "same" );
		 sprintf(text,"pp   #sqrt{s} = 7 TeV");
		 cout<<text<<endl;
		 TLatex *CentralsText3 = new TLatex(11.5-DeltaXminOVERALL,yMin+(yMax-yMin)*0.875,text);
		 CentralsText3->SetTextSize(CentralsFontSize);
		 CentralsText3->Draw( "same" );



			TLine* extreme0 = new TLine( onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL, 0, onia::cpmRange[cpmBinMax] ,0);
			extreme0->SetLineWidth( 1 );
			extreme0->SetLineStyle( 2 );
			extreme0->SetLineColor( kBlack );
			extreme0->Draw( "same" );

			TLine* extreme1 = new TLine( onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL, 1, onia::cpmRange[cpmBinMax] , 1);
			extreme1->SetLineWidth( 1 );
			extreme1->SetLineStyle( 2 );
			extreme1->SetLineColor( kBlack );
			if(iLam==1||iLam==5||iLam==9) extreme1->Draw( "same" );

			TLine* extreme2 = new TLine( onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL, -1, onia::cpmRange[cpmBinMax] ,-1);
			extreme2->SetLineWidth( 1 );
			extreme2->SetLineStyle( 2 );
			extreme2->SetLineColor( kBlack );
			if(iLam==1||iLam==5||iLam==9) extreme2->Draw( "same" );
			if(iLam==5||iLam==8||iLam==12) extreme2->Draw( "same" );

		 }

		 if(PlotLegend) plotcompLegend->Draw();

//		plotCanvas->SetLogx(true);
		if(PlotFinalData) plotCanvas->SaveAs(filename);
		plotCanvas->Close();

		delete plotCanvas;

///////////////////////////////////////////////////////////////
////////////// End FinalDataResults Plotting //////////////////
///////////////////////////////////////////////////////////////

		if(MultiPanelPlots){

			bool NEW_MPplots=true;

			cout<<"Drawing MultiPanel"<<endl;

	int MPframe;
	int iPanel;

// Pad Definitions
	float Top_margin   = 0.;//0
	float Left_margin  = 0.15;//0.025
	float Right_margin = 0.015;//0.005
	const int nPanels=3;
	double lowestBottomMargin=0.2;//0.2
	double PadCoordYMax=0.985;//0.985
	double deltaCoordY=PadCoordYMax/(double(nPanels-1)+1./(1-lowestBottomMargin));
	double startValCoordY=deltaCoordY/(1-lowestBottomMargin);
	//double PadCoordY[nPanels+1]={0.,0.3,0.5,0.7,0.9};
	double PadCoordY[nPanels+1]={0.,startValCoordY,startValCoordY+deltaCoordY,PadCoordYMax};
	double PadCoordX[3]={0.1,0.5,0.9};

// Canvas Definitions
	int MPcanvasXpixelInitial=3000;
	int MPcanvasYpixelInitial=3000;
	int MPcanvasXpixel=MPcanvasXpixelInitial;
	int MPcanvasYpixel=MPcanvasYpixelInitial;

// Axis Definitions
	double yMinMP=yMin+0.01;
	double yMaxMP=yMax-0.01;
	double LabelSize=0.065;
	double TitleSize=0.085;
	double titleoffset=-0.65;

	double ticksize=0.015;
	int AxisDivisions=510;
	double deltaTrickAxisMin=-0.001;
	double deltaTrickAxisMax=-0.001;
	if(ptBin==2) deltaTrickAxisMax=+0.001;

// Latex definitions
	double whereTexteInPlotX;
	double whereTexteInPlotY;
	double labelOffsetX=0.02;
	double YaxistitleLatexSize=0.12;
	double MPlatexX=11.5;
	double MPlatexYmax=(yMax-yMin)*0.8775+yMin;//0.35;(yMax-yMin)*0.85+yMin
	double MPlatexDeltaYmax=0.09*(yMax-yMin);
	double CentralsFontSizeMP=0.115;
	// inner legend definitions
	double textSizeRap=0.07825;
	double xRapText;
	double xRapTextTilde;
	double yRapText=0.06;
	if(ptBin==1) xRapText=onia::cpmRange[cpmBinMax]*0.825;//0.625
	if(ptBin==2) xRapText=onia::cpmRange[cpmBinMax]*0.725;//0.525
	if(ptBin==1) xRapTextTilde=onia::cpmRange[cpmBinMax]*0.7;//0.625 with frame
	if(ptBin==2) xRapTextTilde=onia::cpmRange[cpmBinMax]*0.6;//0.525 with frame
	double xabcdefText=onia::cpmRange[cpmBinMax]*0.225;

	double XaxislabelLatexSize=0.0245;
	double YtitleAngle=0.;
	double XtitlePosition=-8.;
	double XtitlePositionYshift=0.025;

// marker definitions
	double MarkerSizeMP[4]={3.75,3.75,3.75,4.15};// for each frame
	int MarkerColorMP[4] = {1,1,632,600};//{0,600,632,418}; // for each frame
	int MarkerStyleMP[5] = {25,20,25,24,27}; // for each frame
	int MarkerStyleMPtilde[4] = {20,24,25,27}; // for each frame

// legend
	double errorLegendX1=0.165;
	double errorLegendX2=0.565;
	double errorLegendY1=0.655;
	double errorLegendY2=0.95;
	double errorLegendFontSize=0.08;


	cout<<"begin Frame dependent plots"<<endl;
	//begin Frame dependent plots
	if(!NEW_MPplots){
	if(iLam!=4&&iLam!=8&&iLam!=12){

			if(iLam>0&&iLam<5) MPframe=1;
			if(iLam>4&&iLam<8) MPframe=2;
			if(iLam>8&&iLam<13) MPframe=3;

			if(iLam==1||iLam==5||iLam==9) iPanel=1;
			if(iLam==2||iLam==6||iLam==10) iPanel=2;
			if(iLam==3||iLam==7||iLam==11) iPanel=3;

			cout<<"MultiPanel canvas"<<endl;


			if(iLam==1&&ptBin==1){
			MPcanvasCS = new TCanvas("MPcanvasCS", "MPcanvasCS",MPcanvasXpixel,MPcanvasYpixel);
			MPcanvasCS->SetFillColor(kWhite);
			MPcanvasCS->GetFrame()->SetFillColor(kWhite);
			MPcanvasCS->GetFrame()->SetBorderSize(0);
			}
			if(iLam==5&&ptBin==1){
			MPcanvasHX = new TCanvas("MPcanvasHX", "MPcanvasHX",MPcanvasXpixel,MPcanvasYpixel);
			MPcanvasHX->SetFillColor(kWhite);
			MPcanvasHX->GetFrame()->SetFillColor(kWhite);
			MPcanvasHX->GetFrame()->SetBorderSize(0);
			}
			if(iLam==9&&ptBin==1){
			MPcanvasPX = new TCanvas("MPcanvasPX", "MPcanvasPX",MPcanvasXpixel,MPcanvasYpixel);
			MPcanvasPX->SetFillColor(kWhite);
			MPcanvasPX->GetFrame()->SetFillColor(kWhite);
			MPcanvasPX->GetFrame()->SetBorderSize(0);
			}

			if(MPframe==1) MPcanvasCS->cd();
			if(MPframe==2) MPcanvasHX->cd();
			if(MPframe==3) MPcanvasPX->cd();

		   cout<<"MultiPanel pad"<<endl;
		   TPad *MPpad;
		   if(ptBin==1) MPpad = new TPad("MPpad","MPpad",0.,PadCoordY[nPanels-iPanel],0.5,PadCoordY[nPanels-iPanel+1]);
		   if(ptBin==2) MPpad = new TPad("MPpad","MPpad",0.5,PadCoordY[nPanels-iPanel],1.,PadCoordY[nPanels-iPanel+1]);
		   MPpad->Draw();
		   MPpad->cd();
		   MPpad->SetFillColor(kWhite);
		   MPpad->SetFrameFillColor(kWhite);
		   MPpad->SetBorderSize(0);
		   MPpad->SetLeftMargin(0.);
		   if(ptBin==1) MPpad->SetLeftMargin(Left_margin);
		   MPpad->SetRightMargin(0.);
		   if(ptBin==2) MPpad->SetRightMargin(Right_margin);
		   MPpad->SetTopMargin(Top_margin+0.0025);
		   MPpad->SetBottomMargin(0.0);
		   if(iPanel==nPanels) MPpad->SetBottomMargin(lowestBottomMargin);


		   cout<<"MultiPanel hist"<<endl;

		   TH1F *MPhist = new TH1F;
		   if(MPframe==1)MPhist = MPcanvasCS->DrawFrame(onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL,yMinMP,onia::cpmRange[cpmBinMax],yMaxMP);

		   if(MPframe==2)MPhist = MPcanvasHX->DrawFrame(onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL,yMinMP,onia::cpmRange[cpmBinMax],yMaxMP);
		   if(MPframe==3)MPhist = MPcanvasPX->DrawFrame(onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL,yMinMP,onia::cpmRange[cpmBinMax],yMaxMP);

		   MPhist->SetXTitle("#it{N}_{ch}");
		   MPhist->GetXaxis()->SetTitleOffset(-1.35);

		   MPhist->SetYTitle(axislabel);
		   MPhist->GetYaxis()->SetTitleOffset(titleoffset);
		   MPhist->GetYaxis()->SetTitleSize(0.);
		   if(iPanel==nPanels) MPhist->GetYaxis()->SetTitleOffset(titleoffset*1.35);
		   if(iPanel==nPanels) MPhist->GetYaxis()->SetTitleSize(0.*(1-lowestBottomMargin));

		   MPhist->GetYaxis()->SetLabelSize(LabelSize*1.25);
		   MPhist->GetXaxis()->SetLabelSize(0.);
		   MPhist->GetYaxis()->SetLabelOffset(-0.015);
		   MPhist->GetXaxis()->SetLabelOffset(-0.06);

		   if(iPanel==nPanels) MPhist->GetYaxis()->SetLabelSize(LabelSize*1.25*(1-lowestBottomMargin));
		   MPhist->GetXaxis()->SetTitleSize(TitleSize*0.85);
		   MPhist->GetXaxis()->SetAxisColor(kWhite);
		   MPhist->GetYaxis()->SetAxisColor(kWhite);
		   MPhist->GetXaxis()->SetTicks("-");
		   MPhist->GetYaxis()->SetTicks("+");


		   TLegend* MPframedepLegend;
		   MPframedepLegend=new TLegend(errorLegendX1,errorLegendY1*.8,errorLegendX2,errorLegendY2);
		   MPframedepLegend->SetFillStyle(0);
		   if((nState==2||nState==3)&&MPframe==1) MPframedepLegend=new TLegend(errorLegendX1,(errorLegendY2-(errorLegendY2-errorLegendY1)*(1-lowestBottomMargin))*.8,errorLegendX2,errorLegendY2);
		   MPframedepLegend->SetFillColor(0);
		   MPframedepLegend->SetFillStyle(0);
//		   MPframedepLegend->SetTextFont(72);
		   MPframedepLegend->SetTextSize(errorLegendFontSize);
		   if((nState==2||nState==3)&&MPframe==1) MPframedepLegend->SetTextSize(errorLegendFontSize*(1-lowestBottomMargin));
		   MPframedepLegend->SetBorderSize(0);

		   char MPframedepLegendEntry[200];

			if(ptBin==1){
		   graphSyst->SetMarkerSize(MarkerSizeMP[0]);
		   graphSyst->SetMarkerStyle(MarkerStyleMP[0]);
		   graphSyst->SetMarkerColor(MarkerColorMP[0]);

		   graphDefaultStat->SetMarkerSize(MarkerSizeMP[0]);
		   graphDefaultStat->SetMarkerStyle(MarkerStyleMP[0]);
		   graphDefaultStat->SetMarkerColor(MarkerColorMP[0]);
			}
			
			if(ptBin==2){
		   graphSyst->SetMarkerSize(MarkerSizeMP[0]);
		   graphSyst->SetMarkerStyle(MarkerStyleMP[1]);
		   graphSyst->SetMarkerColor(2);

		   graphDefaultStat->SetMarkerSize(MarkerSizeMP[0]);
		   graphDefaultStat->SetMarkerStyle(MarkerStyleMP[1]);
		   graphDefaultStat->SetMarkerColor(2);
			}
			
			
		   graphDefaultRes3sigma->Draw("2");
		   graphDefaultRes2sigma->Draw("2");
		   graphDefaultRes->Draw("2");
		   if(!PlotAlteredPPDResults) graphSyst->Draw(drawGraphStyle);
		   if(PlotAlteredPPDResults) graphDefaultStat->Draw(drawGraphStyle);


		   graphDefaultRes->SetLineColor(kGreen);
		   graphDefaultRes2sigma->SetLineColor(kYellow);
		   graphDefaultRes3sigma->SetLineColor(kCyan-9);

		   if(PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"N_{ch} dependent uncert., 68.3 %% CL");
		   if(!PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"Tot. sys. uncert.");
		   MPframedepLegend->AddEntry(graphSyst,MPframedepLegendEntry,"ple");
		   if(PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"Tot. uncert., 68.3 %% CL");
		   if(!PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"68.3 %% CL");
		   MPframedepLegend->AddEntry(graphDefaultRes,MPframedepLegendEntry,"f");
		   if(PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"Tot. uncert., 95.5 %% CL");
		   if(!PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"95.5 %% CL");
		   MPframedepLegend->AddEntry(graphDefaultRes2sigma,MPframedepLegendEntry,"f");
		   if(PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"Tot. uncert., 99.7 %% CL");
		   if(!PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"99.7 %% CL");
		   MPframedepLegend->AddEntry(graphDefaultRes3sigma,MPframedepLegendEntry,"f");

			if(ptBin==2) deltaTrickAxisMax=-0.001;

		   TGaxis *axisMPY1 = new TGaxis(onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL,yMinMP,onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL,yMaxMP,yMinMP,yMaxMP,AxisDivisions,"-US");
		   axisMPY1->SetTickSize(ticksize);
		   if(iPanel==nPanels) axisMPY1->SetTickSize(ticksize/(1-lowestBottomMargin));
		   axisMPY1->Draw("same");

		   TGaxis *axisMPY2 = new TGaxis(onia::cpmRange[cpmBinMax],yMinMP,onia::cpmRange[cpmBinMax],yMaxMP,yMinMP,yMaxMP,AxisDivisions,"+US");
		   axisMPY2->SetTickSize(ticksize);
		   if(iPanel==nPanels) axisMPY2->SetTickSize(ticksize/(1-lowestBottomMargin));
		   axisMPY2->Draw("same");


		   TGaxis *axisMPX1 = new TGaxis(onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL,yMinMP,onia::cpmRange[cpmBinMax],yMinMP,onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL+deltaTrickAxisMin,onia::cpmRange[cpmBinMax]+deltaTrickAxisMax,AxisDivisions,"+S");
		   axisMPX1->SetTickSize(ticksize*2);
		   if(iPanel==nPanels) axisMPX1->SetLabelSize(LabelSize);
		   if(iPanel<nPanels) axisMPX1->SetLabelSize(0);
		   axisMPX1->SetLabelOffset(labelOffsetX);
		   if(iPanel==nPanels) axisMPX1->SetTickSize(ticksize/(1-lowestBottomMargin));
		   axisMPX1->Draw("same");

		   TGaxis *axisMPX2 = new TGaxis(onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL,yMaxMP,onia::cpmRange[cpmBinMax],yMaxMP,onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL+deltaTrickAxisMin,onia::cpmRange[cpmBinMax]+deltaTrickAxisMax,AxisDivisions,"-US");
		   axisMPX2->SetTickSize(ticksize*2);
		   if(iPanel==nPanels) axisMPX2->SetTickSize(ticksize/(1-lowestBottomMargin));
		   axisMPX2->Draw("same");

		   whereTexteInPlotX=XtitlePosition;
		   whereTexteInPlotY=(yMaxMP+yMinMP)/2.-(yMaxMP-yMinMP)*XtitlePositionYshift;

		   char axistitleMPdep[200];
			if(iLam==1||iLam==5||iLam==9)  sprintf(axistitleMPdep,"#lambda_{#vartheta}");
			if(iLam==2||iLam==6||iLam==10)  sprintf(axistitleMPdep,"#lambda_{#varphi}");
			if(iLam==3||iLam==7||iLam==11)  sprintf(axistitleMPdep,"#lambda_{#vartheta#varphi}");

		   if(iPanel==nPanels) YaxistitleLatexSize=YaxistitleLatexSize*(1-lowestBottomMargin);
		   TLatex *MPYtitletext = new TLatex(whereTexteInPlotX-5,whereTexteInPlotY ,axistitleMPdep);
		   MPYtitletext->SetTextSize(YaxistitleLatexSize);
		   if(iPanel==nPanels) MPYtitletext->SetTextSize(YaxistitleLatexSize*(1-lowestBottomMargin));
		   MPYtitletext->SetTextColor(kBlack);
		   MPYtitletext->PaintLatex(whereTexteInPlotX-5,whereTexteInPlotY, YtitleAngle, YaxistitleLatexSize, axislabel);
		   MPYtitletext->Draw( "same" );




		   char frameMPtex[200];
		   if(MPframe==1) sprintf(frameMPtex,"CS");
		   if(MPframe==2) sprintf(frameMPtex,"HX");
		   if(MPframe==3) sprintf(frameMPtex,"PX");
		   char texTexMP[200];
		   if(ptBin==1) sprintf(texTexMP,"10 < #it{p}_{T} < 15 GeV", nState, frameMPtex);
		   if(ptBin==2) sprintf(texTexMP,"15 < #it{p}_{T} < 35 GeV", nState, frameMPtex);
		   TLatex *textMP = new TLatex(xRapText*.5,yMin+(yMax-yMin)*yRapText,texTexMP);
		   textMP->SetTextSize(textSizeRap);
		   if(iPanel==nPanels) textMP->SetTextSize(textSizeRap*(1-lowestBottomMargin));
		   textMP->Draw( "same" );

		   char abcdef[200];
		   if(ptBin==1&&iPanel==1) sprintf(abcdef,"a)");
		   if(ptBin==1&&iPanel==2) sprintf(abcdef,"b)");
		   if(ptBin==1&&iPanel==3) sprintf(abcdef,"c)");
		   if(ptBin==2&&iPanel==1) sprintf(abcdef,"d)");
		   if(ptBin==2&&iPanel==2) sprintf(abcdef,"e)");
		   if(ptBin==2&&iPanel==3) sprintf(abcdef,"f)");
		   cout<<abcdef<<endl;
		   TLatex *tex_abcdef = new TLatex(xabcdefText,yMin+(yMax-yMin)*yRapText*0.92,abcdef);
		   tex_abcdef->SetTextSize(textSizeRap);
		   if(iPanel==nPanels) tex_abcdef->SetTextSize(textSizeRap*(1-lowestBottomMargin));
		   tex_abcdef->Draw( "same" );

			 if(PlotFinalData&&DrawLatexStuff){

				TLine* extreme0MP = new TLine( onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL, 0, onia::cpmRange[cpmBinMax] ,0);
				extreme0MP->SetLineWidth( 1 );
				extreme0MP->SetLineStyle( 2 );
				extreme0MP->SetLineColor( kBlack );
				extreme0MP->Draw( "same" );

				TLine* extreme1MP = new TLine( onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL, 1, onia::cpmRange[cpmBinMax] , 1);
				extreme1MP->SetLineWidth( 1 );
				extreme1MP->SetLineStyle( 2 );
				extreme1MP->SetLineColor( kBlack );
				if(iLam==1||iLam==5||iLam==9) extreme1MP->Draw( "same" );

				TLine* extreme2MP = new TLine( onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL, -1, onia::cpmRange[cpmBinMax] ,-1);
				extreme2MP->SetLineWidth( 1 );
				extreme2MP->SetLineStyle( 2 );
				extreme2MP->SetLineColor( kBlack );
				if(iLam==1||iLam==5||iLam==9) extreme2MP->Draw( "same" );
				if(iLam==4||iLam==8||iLam==12) extreme2MP->Draw( "same" );

			 }


			 if(ptBin==1&&iPanel==1){
			 cout<<"DRAW CMS preliminary Latex"<<endl;
			 char text[200];
			 sprintf(text,"CMS preliminary  pp   #sqrt{s} = 7 TeV  L = 4.9 fb^{-1}");
			 TLatex *CentralsText1MP = new TLatex(MPlatexX,MPlatexYmax,text);
			 CentralsText1MP->SetTextSize(CentralsFontSizeMP);
			 CentralsText1MP->Draw( "same" );
/*			 sprintf(text,"L = 4.9 fb^{-1}");
			 TLatex *CentralsText2MP = new TLatex(MPlatexX,MPlatexYmax-2*MPlatexDeltaYmax,text);
			 CentralsText2MP->SetTextSize(CentralsFontSizeMP);
			 CentralsText2MP->Draw( "same" );
			 sprintf(text,"pp     #sqrt{s} = 7 TeV");
			 TLatex *CentralsText3MP = new TLatex(MPlatexX,MPlatexYmax-MPlatexDeltaYmax,text);
			 CentralsText3MP->SetTextSize(CentralsFontSizeMP);
			 CentralsText3MP->Draw( "same" );
*/
			 }

			 if(ptBin==1&&iPanel==2&&nState==1){
//				 MPframedepLegend->Draw("same");
			 }
			 if(nState==2||nState==3){
			 if(ptBin==1&&iPanel==3&&MPframe==1){
//				 MPframedepLegend->Draw("same");
			 }
			 if(ptBin==1&&iPanel==2&&MPframe!=1){
//				 MPframedepLegend->Draw("same");
			 }
			 }
			 if(ptBin==2&&iPanel==1){

				   char frameMPtex[200];
				   if(MPframe==1) sprintf(frameMPtex,"CS frame");
				   if(MPframe==2) sprintf(frameMPtex,"HX frame");
				   if(MPframe==3) sprintf(frameMPtex,"PX frame");
					 char textStateFrame[200];
					 sprintf(textStateFrame,"#Upsilon(%dS), %s", nState, frameMPtex);
				 TLatex *TexStateFrame = new TLatex(MPlatexX,MPlatexYmax,textStateFrame);
				 TexStateFrame->SetTextSize(CentralsFontSizeMP);
				 TexStateFrame->Draw( "same" );

			 }

			if(MPframe==1) MPcanvasCS->cd();
			if(MPframe==2) MPcanvasHX->cd();
			if(MPframe==3) MPcanvasPX->cd();

			whereTexteInPlotX=0.488;
			whereTexteInPlotY=startValCoordY-deltaCoordY-1.375*labelOffsetX;

			  TLatex *MPXlabeltext = new TLatex(whereTexteInPlotX,whereTexteInPlotY ,"1");
			  MPXlabeltext->SetTextSize(XaxislabelLatexSize);
			  MPXlabeltext->SetTextColor(kBlack);
			  if(iPanel==nPanels) MPXlabeltext->Draw( "same" );

			if(iLam==3&&ptBin==2){  sprintf(filename,"%s/FinalResultsCS_OLD_Ups%dS.pdf",FigDir,nState);
			if(PlotFinalData) MPcanvasCS->SaveAs(filename);
			MPcanvasCS->Close();
			}
			if(iLam==7&&ptBin==2){  sprintf(filename,"%s/FinalResultsHX_OLD_Ups%dS.pdf",FigDir,nState);
			if(PlotFinalData) MPcanvasHX->SaveAs(filename);
			MPcanvasHX->Close();
			}
			if(iLam==11&&ptBin==2){  sprintf(filename,"%s/FinalResultsPX_OLD_Ups%dS.pdf",FigDir,nState);
			if(PlotFinalData) MPcanvasPX->SaveAs(filename);
			MPcanvasPX->Close();
			}
	}//end Frame dependent plots
	} 



	cout<<"begin Frame independent plots"<<endl;
	cout<<"if(iLam==4||iLam==8||iLam==12)"<<endl;
	//begin Frame independent plots
	if(!NEW_MPplots){
	if(iLam==4||iLam==8||iLam==12){

		int mainframe;
		if(iLam==4) mainframe=1;
		if(iLam==8) mainframe=2;
		if(iLam==12) mainframe=3;

		cout<<"iLam = "<<iLam<<endl;

		if((iLam==4||iLam==8||iLam==12)&&ptBin==1){
		MPcanvasTilde = new TCanvas("MPcanvasTilde", "MPcanvasTilde",MPcanvasXpixel,MPcanvasYpixel);
		MPcanvasTilde->SetFillColor(kWhite);
		MPcanvasTilde->GetFrame()->SetFillColor(kWhite);
		MPcanvasTilde->GetFrame()->SetBorderSize(0);
		}


		for(int iStateMP=1;iStateMP<4;iStateMP++){
			if(iStateMP==1) iPanel=1;
			if(iStateMP==2) iPanel=2;
			if(iStateMP==3) iPanel=3;

			cout<<"MultiPanel canvas"<<endl;

			MPcanvasTilde->cd();

		   cout<<"MultiPanel pad"<<endl;
		   TPad *MPpad;
		   if(ptBin==1) MPpad = new TPad("MPpad","MPpad",0.,PadCoordY[nPanels-iPanel],0.5,PadCoordY[nPanels-iPanel+1]);
		   if(ptBin==2) MPpad = new TPad("MPpad","MPpad",0.5,PadCoordY[nPanels-iPanel],1.,PadCoordY[nPanels-iPanel+1]);
		   MPpad->Draw();
		   MPpad->cd();
		   MPpad->SetFillColor(kWhite);
		   MPpad->SetFrameFillColor(kWhite);
		   MPpad->SetBorderSize(0);
		   MPpad->SetLeftMargin(0.);
		   if(ptBin==1) MPpad->SetLeftMargin(Left_margin);
		   MPpad->SetRightMargin(0.);
		   if(ptBin==2) MPpad->SetRightMargin(Right_margin);
		   MPpad->SetTopMargin(Top_margin+0.0025);
		   MPpad->SetBottomMargin(0.0);
		   if(iPanel==nPanels) MPpad->SetBottomMargin(lowestBottomMargin);


		   cout<<"MultiPanel hist"<<endl;

		   TH1F *MPhist = new TH1F;
		   MPhist = MPcanvasTilde->DrawFrame(onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL,yMinMP,onia::cpmRange[cpmBinMax],yMaxMP);

		   MPhist->SetXTitle("#it{N}_{ch}");
		   MPhist->GetXaxis()->SetTitleOffset(-1.35);

		   MPhist->SetYTitle(axislabel);
		   MPhist->GetYaxis()->SetTitleOffset(titleoffset*.5);
		   MPhist->GetYaxis()->SetTitleSize(0.);
		   if(iPanel==nPanels) MPhist->GetYaxis()->SetTitleOffset(titleoffset*1.35);
		   if(iPanel==nPanels) MPhist->GetYaxis()->SetTitleSize(0.*(1-lowestBottomMargin));

		   MPhist->GetYaxis()->SetLabelSize(LabelSize*1.25);
		   MPhist->GetXaxis()->SetLabelSize(0.);
		   MPhist->GetYaxis()->SetLabelOffset(-0.015);
		   MPhist->GetXaxis()->SetLabelOffset(-0.06);

		   if(iPanel==nPanels) MPhist->GetYaxis()->SetLabelSize(LabelSize*1.25*(1-lowestBottomMargin));
		   MPhist->GetXaxis()->SetTitleSize(TitleSize*0.85);
		   MPhist->GetXaxis()->SetAxisColor(kWhite);
		   MPhist->GetYaxis()->SetAxisColor(kWhite);
		   MPhist->GetXaxis()->SetTicks("-");
		   MPhist->GetYaxis()->SetTicks("+");

		   TLegend* MPframedepLegendError;
		   MPframedepLegendError=new TLegend(errorLegendX1,errorLegendY1*.8,errorLegendX2,errorLegendY2);
		   MPframedepLegendError->SetFillStyle(0);
		   MPframedepLegendError->SetFillColor(0);
//		   MPframedepLegendError->SetTextFont(72);
		   MPframedepLegendError->SetTextSize(errorLegendFontSize);
		   MPframedepLegendError->SetBorderSize(0);

		   char MPframedepLegendEntry[200];


		   TGraphAsymmErrors* graphMP1;
		   TGraphAsymmErrors* graphMP2;
		   TGraphAsymmErrors* graphMP3;

/*		   TGraphAsymmErrors* graphMP1_1sig;
		   TGraphAsymmErrors* graphMP1_2sig;
		   TGraphAsymmErrors* graphMP1_3sig;
		   TGraphAsymmErrors* graphMP2_1sig;
		   TGraphAsymmErrors* graphMP2_2sig;
		   TGraphAsymmErrors* graphMP2_3sig;
		   TGraphAsymmErrors* graphMP3_1sig;
		   TGraphAsymmErrors* graphMP3_2sig;
		   TGraphAsymmErrors* graphMP3_3sig;
*/
		   TLegend* MPtildeLegend;
			MPtildeLegend=new TLegend(0.8,0.75,1.,0.95);
			MPtildeLegend->SetFillStyle(0);
			MPtildeLegend->SetFillColor(0);
//			MPtildeLegend->SetTextFont(72);
			MPtildeLegend->SetTextSize(0.07);
			MPtildeLegend->SetBorderSize(0);
			char MPtildeLegendEntry[200];

		   for(int iFrameMP=1;iFrameMP<4;iFrameMP++){

			   char GraphNameMP[200];


			   if(iFrameMP==1){
				   sprintf(GraphNameMP,"ltilde_CS_rap1_pt%d",ptBin);
			   }
			   if(iFrameMP==2){
				   sprintf(GraphNameMP,"ltilde_HX_rap1_pt%d",ptBin);
			   }
			   if(iFrameMP==3){
				   sprintf(GraphNameMP,"ltilde_PX_rap1_pt%d",ptBin);
			   }

				graphMP1 = (TGraphAsymmErrors*) infileMP1->Get(GraphNameMP);
				graphMP2 = (TGraphAsymmErrors*) infileMP2->Get(GraphNameMP);
				graphMP3 = (TGraphAsymmErrors*) infileMP3->Get(GraphNameMP);

				int MarkerDefinitionForThisBin[4][4]={{0,0,0,0},{0,1,2,3},{0,2,1,3},{0,2,3,1}};


				double cpmCentreMP[nBinscpm];
				double cpmCentreErr_lowMP[nBinscpm];
				double cpmCentreErr_highMP[nBinscpm];
				double lmeanMP[nBinscpm];
				double lmean_errlowMP[nBinscpm];
				double lmean_errhighMP[nBinscpm];

				double ShiftTildePlot;
				double ShiftTildePlotZero=0.5;

				if(MarkerDefinitionForThisBin[mainframe][iFrameMP]==1) ShiftTildePlot=0.;
				if(MarkerDefinitionForThisBin[mainframe][iFrameMP]==2) ShiftTildePlot=ShiftTildePlotZero;
				if(MarkerDefinitionForThisBin[mainframe][iFrameMP]==3) ShiftTildePlot=-ShiftTildePlotZero;

				int cpm=0;
				for(int cpmBin = cpmBinMin; cpmBin < cpmBinMax+1; cpmBin++) {

					graphMP1->GetPoint(cpmBin-1,cpmCentreMP[cpm],lmeanMP[cpm]);
					cpmCentreErr_highMP[cpm]=graphMP1->GetErrorXhigh(cpmBin-1);
					cpmCentreErr_lowMP[cpm]=graphMP1->GetErrorXlow(cpmBin-1);
					lmean_errhighMP[cpm]=graphMP1->GetErrorYhigh(cpmBin-1);
					lmean_errlowMP[cpm]=graphMP1->GetErrorYlow(cpmBin-1);

					cpmCentreMP[cpm]=cpmCentreMP[cpm]+ShiftTildePlot;
					cpmCentreErr_highMP[cpm]=cpmCentreErr_highMP[cpm]-ShiftTildePlot;
					cpmCentreErr_lowMP[cpm]=cpmCentreErr_lowMP[cpm]-ShiftTildePlot;

				cpm++;
				}

				graphMP1 = new TGraphAsymmErrors(nBinscpm,cpmCentreMP,lmeanMP,cpmCentreErr_lowMP,cpmCentreErr_highMP,lmean_errlowMP,lmean_errhighMP);

				cpm=0;
				for(int cpmBin = cpmBinMin; cpmBin < cpmBinMax+1; cpmBin++) {

					graphMP2->GetPoint(cpmBin-1,cpmCentreMP[cpm],lmeanMP[cpm]);
					cpmCentreErr_highMP[cpm]=graphMP2->GetErrorXhigh(cpmBin-1);
					cpmCentreErr_lowMP[cpm]=graphMP2->GetErrorXlow(cpmBin-1);
					lmean_errhighMP[cpm]=graphMP2->GetErrorYhigh(cpmBin-1);
					lmean_errlowMP[cpm]=graphMP2->GetErrorYlow(cpmBin-1);

					cpmCentreMP[cpm]=cpmCentreMP[cpm]+ShiftTildePlot;
					cpmCentreErr_highMP[cpm]=cpmCentreErr_highMP[cpm]-ShiftTildePlot;
					cpmCentreErr_lowMP[cpm]=cpmCentreErr_lowMP[cpm]-ShiftTildePlot;

				cpm++;
				}

				graphMP2 = new TGraphAsymmErrors(nBinscpm,cpmCentreMP,lmeanMP,cpmCentreErr_lowMP,cpmCentreErr_highMP,lmean_errlowMP,lmean_errhighMP);

				cpm=0;
				for(int cpmBin = cpmBinMin; cpmBin < cpmBinMax+1; cpmBin++) {

					graphMP3->GetPoint(cpmBin-1,cpmCentreMP[cpm],lmeanMP[cpm]);
					cpmCentreErr_highMP[cpm]=graphMP3->GetErrorXhigh(cpmBin-1);
					cpmCentreErr_lowMP[cpm]=graphMP3->GetErrorXlow(cpmBin-1);
					lmean_errhighMP[cpm]=graphMP3->GetErrorYhigh(cpmBin-1);
					lmean_errlowMP[cpm]=graphMP3->GetErrorYlow(cpmBin-1);

					cpmCentreMP[cpm]=cpmCentreMP[cpm]+ShiftTildePlot;
					cpmCentreErr_highMP[cpm]=cpmCentreErr_highMP[cpm]-ShiftTildePlot;
					cpmCentreErr_lowMP[cpm]=cpmCentreErr_lowMP[cpm]-ShiftTildePlot;

				cpm++;
				}

				graphMP3 = new TGraphAsymmErrors(nBinscpm,cpmCentreMP,lmeanMP,cpmCentreErr_lowMP,cpmCentreErr_highMP,lmean_errlowMP,lmean_errhighMP);

				graphMP1->SetMarkerColor(MarkerColorMP[MarkerDefinitionForThisBin[mainframe][iFrameMP]]);
				graphMP1->SetLineColor(MarkerColorMP[MarkerDefinitionForThisBin[mainframe][iFrameMP]]);
				graphMP1->SetMarkerStyle(MarkerStyleMP[MarkerDefinitionForThisBin[mainframe][iFrameMP] ]);
				graphMP1->SetMarkerSize(MarkerSizeMP[MarkerDefinitionForThisBin[mainframe][iFrameMP]]);

				graphMP2->SetMarkerColor(MarkerColorMP[MarkerDefinitionForThisBin[mainframe][iFrameMP]]);
				graphMP2->SetLineColor(MarkerColorMP[MarkerDefinitionForThisBin[mainframe][iFrameMP]]);
				graphMP2->SetMarkerStyle(MarkerStyleMP[MarkerDefinitionForThisBin[mainframe][iFrameMP]]);
				graphMP2->SetMarkerSize(MarkerSizeMP[MarkerDefinitionForThisBin[mainframe][iFrameMP]]);

				graphMP3->SetMarkerColor(MarkerColorMP[MarkerDefinitionForThisBin[mainframe][iFrameMP]]);
				graphMP3->SetLineColor(MarkerColorMP[MarkerDefinitionForThisBin[mainframe][iFrameMP]]);
				graphMP3->SetMarkerStyle(MarkerStyleMP[MarkerDefinitionForThisBin[mainframe][iFrameMP]]);
				graphMP3->SetMarkerSize(MarkerSizeMP[MarkerDefinitionForThisBin[mainframe][iFrameMP]]);


				if(mainframe==1&&iFrameMP==1){ sprintf(MPtildeLegendEntry,"CS"); MPtildeLegend->AddEntry(graphMP1,MPtildeLegendEntry,"lp"); }
				if(mainframe!=1&&iFrameMP==1){ sprintf(MPtildeLegendEntry,"CS"); MPtildeLegend->AddEntry(graphMP1,MPtildeLegendEntry,"p"); }

				if(mainframe==2&&iFrameMP==2){ sprintf(MPtildeLegendEntry,"HX"); MPtildeLegend->AddEntry(graphMP1,MPtildeLegendEntry,"lp"); }
				if(mainframe!=2&&iFrameMP==2){ sprintf(MPtildeLegendEntry,"HX"); MPtildeLegend->AddEntry(graphMP1,MPtildeLegendEntry,"p"); }

				if(mainframe==3&&iFrameMP==3){ sprintf(MPtildeLegendEntry,"PX"); MPtildeLegend->AddEntry(graphMP1,MPtildeLegendEntry,"lp"); }
				if(mainframe!=3&&iFrameMP==3){ sprintf(MPtildeLegendEntry,"PX"); MPtildeLegend->AddEntry(graphMP1,MPtildeLegendEntry,"p"); }



				   if(mainframe==1){
					   sprintf(GraphNameMP,"ltilde_CS_rap1_pt%d",ptBin);
				   }
				   if(mainframe==2){
					   sprintf(GraphNameMP,"ltilde_HX_rap1_pt%d",ptBin);
				   }
				   if(mainframe==3){
					   sprintf(GraphNameMP,"ltilde_PX_rap1_pt%d",ptBin);
				   }

/*					graphMP1_1sig = (TGraphAsymmErrors*) infileMP1_1sig->Get(GraphNameMP);
					graphMP1_2sig = (TGraphAsymmErrors*) infileMP1_2sig->Get(GraphNameMP);
					graphMP1_3sig = (TGraphAsymmErrors*) infileMP1_3sig->Get(GraphNameMP);
					graphMP2_1sig = (TGraphAsymmErrors*) infileMP2_1sig->Get(GraphNameMP);
					graphMP2_2sig = (TGraphAsymmErrors*) infileMP2_2sig->Get(GraphNameMP);
					graphMP2_3sig = (TGraphAsymmErrors*) infileMP2_3sig->Get(GraphNameMP);
					graphMP3_1sig = (TGraphAsymmErrors*) infileMP3_1sig->Get(GraphNameMP);
					graphMP3_2sig = (TGraphAsymmErrors*) infileMP3_2sig->Get(GraphNameMP);
					graphMP3_3sig = (TGraphAsymmErrors*) infileMP3_3sig->Get(GraphNameMP);


					graphMP1_1sig->SetFillColor(kGreen);
					graphMP1_1sig->SetFillStyle(1001);
					graphMP1_2sig->SetFillColor(kYellow);
					graphMP1_2sig->SetFillStyle(1001);
					graphMP1_3sig->SetFillColor(kCyan-9);
					graphMP1_3sig->SetFillStyle(1001);

					graphMP2_1sig->SetFillColor(kGreen);
					graphMP2_1sig->SetFillStyle(1001);
					graphMP2_2sig->SetFillColor(kYellow);
					graphMP2_2sig->SetFillStyle(1001);
					graphMP2_3sig->SetFillColor(kCyan-9);
					graphMP2_3sig->SetFillStyle(1001);

					graphMP3_1sig->SetFillColor(kGreen);
					graphMP3_1sig->SetFillStyle(1001);
					graphMP3_2sig->SetFillColor(kYellow);
					graphMP3_2sig->SetFillStyle(1001);
					graphMP3_3sig->SetFillColor(kCyan-9);
					graphMP3_3sig->SetFillStyle(1001);
*/
		   if(iPanel==1){

			   if(iFrameMP==1){
//				   graphMP1_3sig->Draw("2");
//				   graphMP1_2sig->Draw("2");
//				   graphMP1_1sig->Draw("2");
				   if(mainframe==1) graphMP1->Draw(drawGraphStyle);
			   }
			   if(iFrameMP==2){
				   if(mainframe==2) graphMP1->Draw(drawGraphStyle);
			   }
			   if(iFrameMP==3){
				   if(mainframe==3) graphMP1->Draw(drawGraphStyle);
			   }

			   if(iFrameMP==1){
				   if(mainframe!=1) graphMP1->Draw("PX");
			   }
			   if(iFrameMP==2){
				   if(mainframe!=2) graphMP1->Draw("PX");
			   }
			   if(iFrameMP==3){
				   if(mainframe!=3) graphMP1->Draw("PX");
			   }

		   }
		   if(iPanel==2){

			   if(iFrameMP==1){
//				   graphMP2_3sig->Draw("2");
//				   graphMP2_2sig->Draw("2");
//				   graphMP2_1sig->Draw("2");
				   if(mainframe==1) graphMP2->Draw(drawGraphStyle);
			   }
			   if(iFrameMP==2){
				   if(mainframe==2) graphMP2->Draw(drawGraphStyle);
			   }
			   if(iFrameMP==3){
				   if(mainframe==3) graphMP2->Draw(drawGraphStyle);
			   }

			   if(iFrameMP==1){
				   if(mainframe!=1) graphMP2->Draw("PX");
			   }
			   if(iFrameMP==2){
				   if(mainframe!=2) graphMP2->Draw("PX");
			   }
			   if(iFrameMP==3){
				   if(mainframe!=3) graphMP2->Draw("PX");
			   }

		   }
		   if(iPanel==3){

			   if(iFrameMP==1){
//				   graphMP3_3sig->Draw("2");
//				   graphMP3_2sig->Draw("2");
//				   graphMP3_1sig->Draw("2");
				   if(mainframe==1) graphMP3->Draw(drawGraphStyle);
			   }
			   if(iFrameMP==2){
				   if(mainframe==2) graphMP3->Draw(drawGraphStyle);
			   }
			   if(iFrameMP==3){
				   if(mainframe==3) graphMP3->Draw(drawGraphStyle);
			   }

			   if(iFrameMP==1){
				   if(mainframe!=1) graphMP3->Draw("PX");
			   }
			   if(iFrameMP==2){
				   if(mainframe!=2) graphMP3->Draw("PX");
			   }
			   if(iFrameMP==3){
				   if(mainframe!=3) graphMP3->Draw("PX");
			   }


		   }
		   }



		   TGaxis *axisMPY1 = new TGaxis(onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL,yMinMP,onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL,yMaxMP,yMinMP,yMaxMP,AxisDivisions,"-US");
		   axisMPY1->SetTickSize(ticksize);
		   if(iPanel==nPanels) axisMPY1->SetTickSize(ticksize/(1-lowestBottomMargin));
		   axisMPY1->Draw("same");

		   TGaxis *axisMPY2 = new TGaxis(onia::cpmRange[cpmBinMax],yMinMP,onia::cpmRange[cpmBinMax],yMaxMP,yMinMP,yMaxMP,AxisDivisions,"+US");
		   axisMPY2->SetTickSize(ticksize);
		   if(iPanel==nPanels) axisMPY2->SetTickSize(ticksize/(1-lowestBottomMargin));
		   axisMPY2->Draw("same");


		   TGaxis *axisM3S1 = new TGaxis(onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL,yMinMP,onia::cpmRange[cpmBinMax],yMinMP,onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL+deltaTrickAxisMin,onia::cpmRange[cpmBinMax]+deltaTrickAxisMax,AxisDivisions,"+S");
		   axisM3S1->SetTickSize(ticksize*2);
		   if(iPanel==nPanels) axisM3S1->SetLabelSize(LabelSize);
		   if(iPanel<nPanels) axisM3S1->SetLabelSize(0);
		   axisM3S1->SetLabelOffset(labelOffsetX);
		   if(iPanel==nPanels) axisM3S1->SetTickSize(ticksize/(1-lowestBottomMargin));
		   axisM3S1->Draw("same");

		   TGaxis *axisM3S2 = new TGaxis(onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL,yMaxMP,onia::cpmRange[cpmBinMax],yMaxMP,onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL+deltaTrickAxisMin,onia::cpmRange[cpmBinMax]+deltaTrickAxisMax,AxisDivisions,"-US");
		   axisM3S2->SetTickSize(ticksize*2);
		   if(iPanel==nPanels) axisM3S2->SetTickSize(ticksize/(1-lowestBottomMargin));
		   axisM3S2->Draw("same");

		   whereTexteInPlotX=XtitlePosition;
		   whereTexteInPlotY=(yMaxMP+yMinMP)/2.-(yMaxMP-yMinMP)*XtitlePositionYshift;

		   char axistitleMPtilde[200];
		   sprintf(axistitleMPtilde,"#tilde{#lambda}");
		   if(iPanel==nPanels) YaxistitleLatexSize=YaxistitleLatexSize*(1-lowestBottomMargin);
		   TLatex *MPYtitletext = new TLatex(whereTexteInPlotX,whereTexteInPlotY ,axistitleMPtilde);
		   MPYtitletext->SetTextSize(YaxistitleLatexSize);
		   if(iPanel==nPanels) MPYtitletext->SetTextSize(YaxistitleLatexSize*(1-lowestBottomMargin));
		   MPYtitletext->SetTextColor(kBlack);
		   MPYtitletext->PaintLatex(whereTexteInPlotX,whereTexteInPlotY, YtitleAngle, YaxistitleLatexSize, axislabel);
		   MPYtitletext->Draw( "same" );




		   char texTexMP[200];
		   if(ptBin==1) sprintf(texTexMP,"#Upsilon(%dS), 10 < #it{p}_{T} < 15 GeV", iPanel);
		   if(ptBin==2) sprintf(texTexMP,"#Upsilon(%dS), 15 < #it{p}_{T} < 35 GeV", iPanel);
		   TLatex *textMP = new TLatex(xRapTextTilde*.5,yMin+(yMax-yMin)*yRapText*0.92,texTexMP);
		   textMP->SetTextSize(textSizeRap);
		   if(iPanel==nPanels) textMP->SetTextSize(textSizeRap*(1-lowestBottomMargin));
		   textMP->Draw( "same" );

		   char abcdef[200];
		   if(ptBin==1&&iPanel==1) sprintf(abcdef,"a)");
		   if(ptBin==1&&iPanel==2) sprintf(abcdef,"b)");
		   if(ptBin==1&&iPanel==3) sprintf(abcdef,"c)");
		   if(ptBin==2&&iPanel==1) sprintf(abcdef,"d)");
		   if(ptBin==2&&iPanel==2) sprintf(abcdef,"e)");
		   if(ptBin==2&&iPanel==3) sprintf(abcdef,"f)");
		   cout<<abcdef<<endl;
		   TLatex *tex_abcdef = new TLatex(xabcdefText,yMin+(yMax-yMin)*yRapText*0.92,abcdef);
		   tex_abcdef->SetTextSize(textSizeRap);
		   if(iPanel==nPanels) tex_abcdef->SetTextSize(textSizeRap*(1-lowestBottomMargin));
		   tex_abcdef->Draw( "same" );

			 if(PlotFinalData&&DrawLatexStuff){

				TLine* extreme0MP = new TLine( onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL, 0, onia::cpmRange[cpmBinMax] ,0);
				extreme0MP->SetLineWidth( 1 );
				extreme0MP->SetLineStyle( 2 );
				extreme0MP->SetLineColor( kBlack );
				extreme0MP->Draw( "same" );

				TLine* extreme1MP = new TLine( onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL, 1, onia::cpmRange[cpmBinMax] , 1);
				extreme1MP->SetLineWidth( 1 );
				extreme1MP->SetLineStyle( 2 );
				extreme1MP->SetLineColor( kBlack );
				if(iLam==1||iLam==5||iLam==9) extreme1MP->Draw( "same" );

				TLine* extreme2MP = new TLine( onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL, -1, onia::cpmRange[cpmBinMax] ,-1);
				extreme2MP->SetLineWidth( 1 );
				extreme2MP->SetLineStyle( 2 );
				extreme2MP->SetLineColor( kBlack );
				if(iLam==1||iLam==5||iLam==9) extreme2MP->Draw( "same" );
				if(iLam==4||iLam==8||iLam==12) extreme2MP->Draw( "same" );

			 }


			 if(ptBin==1&&iPanel==1){
			 cout<<"DRAW CMS preliminary Latex"<<endl;
			 char text[200];
			 sprintf(text,"CMS preliminary  pp   #sqrt{s} = 7 TeV  L = 4.9 fb^{-1}");
			 TLatex *CentralsText1MP = new TLatex(MPlatexX,MPlatexYmax,text);
			 CentralsText1MP->SetTextSize(CentralsFontSizeMP);
			 CentralsText1MP->Draw( "same" );
/*			 sprintf(text,"L = 4.9 fb^{-1}");
			 TLatex *CentralsText2MP = new TLatex(MPlatexX,MPlatexYmax-2*MPlatexDeltaYmax,text);
			 CentralsText2MP->SetTextSize(CentralsFontSizeMP);
			 CentralsText2MP->Draw( "same" );
			 sprintf(text,"pp    #sqrt{s} = 7 TeV");
			 TLatex *CentralsText3MP = new TLatex(MPlatexX,MPlatexYmax-MPlatexDeltaYmax,text);
			 CentralsText3MP->SetTextSize(CentralsFontSizeMP);
			 CentralsText3MP->Draw( "same" );
*/

			 }

			 if(ptBin==1&&iPanel==2){
//				   graphMP1_1sig->SetLineColor(kGreen);
//				   graphMP1_2sig->SetLineColor(kYellow);
//				   graphMP1_3sig->SetLineColor(kCyan-9);

				   TGraphAsymmErrors *legendPhantom = (TGraphAsymmErrors*) infileMP3_3sig->Get("ltilde_CS_rap1_pt1");

				   legendPhantom->SetMarkerColor(MarkerColorMP[0]);
				   legendPhantom->SetLineColor(MarkerColorMP[0]);
				   legendPhantom->SetMarkerStyle(MarkerStyleMP[1]);
				   legendPhantom->SetMarkerSize(MarkerSizeMP[0]);


				   if(PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"N_{ch} dependent uncert., 68.3 %% CL");
				   if(!PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"Tot. sys. uncert.");
				   MPframedepLegendError->AddEntry(legendPhantom,MPframedepLegendEntry,"ple");
				   if(PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"Tot. uncert., 68.3 %% CL");
				   if(!PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"68.3 %% CL");
//				   MPframedepLegendError->AddEntry(graphMP1_1sig,MPframedepLegendEntry,"f");
				   if(PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"Tot. uncert., 95.5 %% CL");
				   if(!PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"95.5 %% CL");
//				   MPframedepLegendError->AddEntry(graphMP1_2sig,MPframedepLegendEntry,"f");
				   if(PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"Tot. uncert., 99.7 %% CL");
				   if(!PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"99.7 %% CL");
//				   MPframedepLegendError->AddEntry(graphMP1_3sig,MPframedepLegendEntry,"f");

				 MPtildeLegend->Draw("same");
//				 MPframedepLegendError->Draw("same");

			 }

/*			 if(ptBin==2&&iPanel==1){
				   char frameMPtex[200];
				   if(MPframe==1) sprintf(frameMPtex,"CS frame");
				   if(MPframe==2) sprintf(frameMPtex,"HX frame");
				   if(MPframe==3) sprintf(frameMPtex,"PX frame");
					 char textStateFrame[200];
					 sprintf(textStateFrame,"%s", frameMPtex);
				 TLatex *TexStateFrame = new TLatex(MPlatexX,MPlatexYmax,textStateFrame);
				 TexStateFrame->SetTextSize(CentralsFontSizeMP);
				 TexStateFrame->Draw( "same" );
			 }
*/
		}//end iStateMP loop

		MPcanvasTilde->cd();

			whereTexteInPlotX=0.488;
			whereTexteInPlotY=startValCoordY-deltaCoordY-1.425*labelOffsetX;

			  TLatex *M3Slabeltext = new TLatex(whereTexteInPlotX,whereTexteInPlotY ,"1");
			  M3Slabeltext->SetTextSize(XaxislabelLatexSize);
			  M3Slabeltext->SetTextColor(kBlack);
			  if(iPanel==nPanels) M3Slabeltext->Draw( "same" );

				if((iLam==4||iLam==8||iLam==12)&&ptBin==2){
					if(mainframe==1) sprintf(filename,"%s/FinalResultsTildeCS_OLD.pdf",FigDir);
					if(mainframe==2) sprintf(filename,"%s/FinalResultsTildeHX_OLD.pdf",FigDir);
					if(mainframe==3) sprintf(filename,"%s/FinalResultsTildePX_OLD.pdf",FigDir);
			if(PlotFinalData) MPcanvasTilde->SaveAs(filename);
			MPcanvasTilde->Close();
			}
	}//end Frame independent plots
	}



///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////////////// NEW MP PLOTS ///////////////////////////
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

/*	// Pad Definitions
		float Top_margin   = 0.;//0
		float Left_margin  = 0.15;//0.025
		float Right_margin = 0.15;//0.005
		const int nPanels=3;
		double lowestBottomMargin=0.3;
		double PadCoordYMax=0.95;
		double deltaCoordY=PadCoordYMax/(double(nPanels-1)+1./(1-lowestBottomMargin));
		double startValCoordY=deltaCoordY/(1-lowestBottomMargin);
		//double PadCoordY[nPanels+1]={0.,0.3,0.5,0.7,0.9};
		double PadCoordY[nPanels+1]={0.,startValCoordY,startValCoordY+deltaCoordY,PadCoordYMax};
		double PadCoordX[3]={0.1,0.5,0.9};
	// Canvas Definitions
		int MPcanvasXpixel=3000;
		int MPcanvasYpixel=3000;
	// Axis Definitions
		double yMinMP=yMin+0.01;
		double yMaxMP=yMax-0.01;
		double LabelSize=0.065;
		double TitleSize=0.085;
		double titleoffset=-0.65;
		double ticksize=0.015;
		int AxisDivisions=510;
		double deltaTrickAxisMin=-0.001;
		double deltaTrickAxisMax=-0.001;
		if(ptBin==2) deltaTrickAxisMax=+0.001;
	// Latex definitions
		double whereTexteInPlotX;
		double whereTexteInPlotY;
		double labelOffsetX=0.02;
		double YaxistitleLatexSize=0.12;
		double MPlatexX=11.5;
		double MPlatexYmax=(yMax-yMin)*0.8875+yMin;//0.35;(yMax-yMin)*0.85+yMin
		double MPlatexDeltaYmax=0.09*(yMax-yMin);
		double CentralsFontSizeMP=0.0675;
		// inner legend definitions
		double textSizeRap=0.07825;
		double xRapText;
		double xRapTextTilde;
		double yRapText=0.06;
		if(ptBin==1) xRapText=onia::cpmRange[cpmBinMax]*0.825;//0.625
		if(ptBin==2) xRacpmext=onia::cpmRange[cpmBinMax]*0.725;//0.525
		if(ptBin==1) xRacpmextTilde=onia::cpmRange[cpmBinMax]*0.7;//0.625 with frame
		if(ptBin==2) xRacpmextTilde=onia::cpmRange[cpmBinMax]*0.6;//0.525 with frame
		double xabcdefText=onia::cpmRange[cpmBinMax]*0.225;
		double XaxislabelLatexSize=0.026;
		double YtitleAngle=0.;
		double XtitlePosition=4.;
		double XtitlePositionYshift=0.025;
	// marker definitions
		double MarkerSizeMP[4]={2.75,2.75,2.75,4.15};// for each frame
		int MarkerColorMP[4] = {1,1,632,600};//{0,600,632,418}; // for each frame
		int MarkerStyleMP[4] = {20,24,25,27}; // for each frame
	// legend
		double errorLegendX1=0.165;
		double errorLegendX2=0.565;
		double errorLegendY1=0.725;
		double errorLegendY2=0.95;
		double errorLegendFontSize=0.06;
*/

	// Pad Definitions
/*			float Top_margin_MPnew   = 0.;//0
			float Left_margin_MPnew  = 0.15;//0.025
			float Right_margin_MPnew = 0.15;//0.005
			const int nPanels_MPnew=3;
			double lowestBottomMargin_MPnew=0.3;
			double PadCoordYMax_MPnew=0.95;
			double deltaCoordY_MPnew=PadCoordYMax_MPnew/(double(nPanels_MPnew-1)+1./(1-lowestBottomMargin_MPnew));
			double startValCoordY_MPnew=deltaCoordY_MPnew/(1-lowestBottomMargin_MPnew);
			//double PadCoordY[nPanels+1]={0.,0.3,0.5,0.7,0.9};
			double PadCoordY_MPnew[nPanels_MPnew+1]={0.,startValCoordY_MPnew,startValCoordY_MPnew+deltaCoordY_MPnew,PadCoordYMax_MPnew};
			double PadCoordX_MPnew[3]={0.1,0.5,0.9};
*/
		// Canvas Definitions
			int MPcanvasXpixel_MPnew=MPcanvasXpixelInitial*1.5;
			int MPcanvasYpixel_MPnew=MPcanvasYpixelInitial;

			const int nXPanels_newMP=3;
			double x_1=1./(1.+(1-Left_margin)/(1-Right_margin)+1-Left_margin);//(1.-x_tilde)/2.;

			double x_tilde=x_1*(1-Left_margin);//1./(1.+2./(1-Left_margin));
			double PadCoordX_newMP[nXPanels_newMP+1]={0.,x_1,x_1+x_tilde,1.};
			double xRapText_MPnew=44;

			cout<<"begin NEW Frame dependent plots"<<endl;
			//begin Frame dependent plots
			if(NEW_MPplots){
			if(iLam!=4&&iLam!=8&&iLam!=12){

					if(iLam>0&&iLam<5) MPframe=1;
					if(iLam>4&&iLam<9) MPframe=2;
					if(iLam>8&&iLam<13) MPframe=3;

					if(iLam==1||iLam==5||iLam==9) iPanel=1;
					if(iLam==2||iLam==6||iLam==10) iPanel=2;
					if(iLam==3||iLam==7||iLam==11) iPanel=3;

					cout<<"MultiPanel canvas"<<endl;


					if(iLam==1&&ptBin==1){
						MPcanvasCS_rap1_pt1 = new TCanvas("MPcanvasCS_rap1_pt1", "MPcanvasCS_rap1_pt1",MPcanvasXpixel_MPnew,MPcanvasYpixel_MPnew);
						MPcanvasCS_rap1_pt1->SetFillColor(kWhite);
						MPcanvasCS_rap1_pt1->GetFrame()->SetFillColor(kWhite);
						MPcanvasCS_rap1_pt1->GetFrame()->SetBorderSize(0);
					}
					if(iLam==5&&ptBin==1){
						MPcanvasHX_rap1_pt1 = new TCanvas("MPcanvasHX_rap1_pt1", "MPcanvasHX_rap1_pt1",MPcanvasXpixel_MPnew,MPcanvasYpixel_MPnew);
						MPcanvasHX_rap1_pt1->SetFillColor(kWhite);
						MPcanvasHX_rap1_pt1->GetFrame()->SetFillColor(kWhite);
						MPcanvasHX_rap1_pt1->GetFrame()->SetBorderSize(0);
					}
					if(iLam==9&&ptBin==1){
						MPcanvasPX_rap1_pt1 = new TCanvas("MPcanvasPX_rap1_pt1", "MPcanvasPX_rap1_pt1",MPcanvasXpixel_MPnew,MPcanvasYpixel_MPnew);
						MPcanvasPX_rap1_pt1->SetFillColor(kWhite);
						MPcanvasPX_rap1_pt1->GetFrame()->SetFillColor(kWhite);
						MPcanvasPX_rap1_pt1->GetFrame()->SetBorderSize(0);
					}
					if(iLam==1&&ptBin==2){
						MPcanvasCS_rap1_pt2 = new TCanvas("MPcanvasCS_rap1_pt2", "MPcanvasCS_rap1_pt2",MPcanvasXpixel_MPnew,MPcanvasYpixel_MPnew);
						MPcanvasCS_rap1_pt2->SetFillColor(kWhite);
						MPcanvasCS_rap1_pt2->GetFrame()->SetFillColor(kWhite);
						MPcanvasCS_rap1_pt2->GetFrame()->SetBorderSize(0);
					}
					if(iLam==5&&ptBin==2){
						MPcanvasHX_rap1_pt2 = new TCanvas("MPcanvasHX_rap1_pt2", "MPcanvasHX_rap1_pt2",MPcanvasXpixel_MPnew,MPcanvasYpixel_MPnew);
						MPcanvasHX_rap1_pt2->SetFillColor(kWhite);
						MPcanvasHX_rap1_pt2->GetFrame()->SetFillColor(kWhite);
						MPcanvasHX_rap1_pt2->GetFrame()->SetBorderSize(0);
					}
					if(iLam==9&&ptBin==2){
						MPcanvasPX_rap1_pt2 = new TCanvas("MPcanvasPX_rap1_pt2", "MPcanvasPX_rap1_pt2",MPcanvasXpixel_MPnew,MPcanvasYpixel_MPnew);
						MPcanvasPX_rap1_pt2->SetFillColor(kWhite);
						MPcanvasPX_rap1_pt2->GetFrame()->SetFillColor(kWhite);
						MPcanvasPX_rap1_pt2->GetFrame()->SetBorderSize(0);
					}

					for(int iStateMP=1;iStateMP<4;iStateMP++){

					if(MPframe==1&&ptBin==1) MPcanvasCS_rap1_pt1->cd();
					if(MPframe==2&&ptBin==1) MPcanvasHX_rap1_pt1->cd();
					if(MPframe==3&&ptBin==1) MPcanvasPX_rap1_pt1->cd();

					if(MPframe==1&&ptBin==2) MPcanvasCS_rap1_pt2->cd();
					if(MPframe==2&&ptBin==2) MPcanvasHX_rap1_pt2->cd();
					if(MPframe==3&&ptBin==2) MPcanvasPX_rap1_pt2->cd();


				   cout<<"MultiPanel pad"<<endl;
				   cout<<"iLam "<<iLam<<endl;
				   cout<<"MPframe "<<MPframe<<endl;
				   cout<<"iStateMP "<<iStateMP<<endl;
				   cout<<"iPanel "<<iPanel<<endl;
				   cout<<"PadYlow "<<PadCoordY[nPanels-iPanel]<<endl;
				   cout<<"PadYlow "<<PadCoordY[nPanels-iPanel+1]<<endl;

				   TPad *MPpad;
				   if(iStateMP==1) MPpad = new TPad("MPpad","MPpad",PadCoordX_newMP[iStateMP-1],PadCoordY[nPanels-iPanel],PadCoordX_newMP[iStateMP],PadCoordY[nPanels-iPanel+1]);
				   if(iStateMP==2) MPpad = new TPad("MPpad","MPpad",PadCoordX_newMP[iStateMP-1],PadCoordY[nPanels-iPanel],PadCoordX_newMP[iStateMP],PadCoordY[nPanels-iPanel+1]);
				   if(iStateMP==3) MPpad = new TPad("MPpad","MPpad",PadCoordX_newMP[iStateMP-1],PadCoordY[nPanels-iPanel],PadCoordX_newMP[iStateMP],PadCoordY[nPanels-iPanel+1]);
				   MPpad->Draw();
				   MPpad->cd();
				   MPpad->SetFillColor(kWhite);
				   MPpad->SetFrameFillColor(kWhite);
				   MPpad->SetBorderSize(0);
				   MPpad->SetLeftMargin(0.);
				   if(iStateMP==1) MPpad->SetLeftMargin(Left_margin);
				   MPpad->SetRightMargin(0.);
				   if(iStateMP==3) MPpad->SetRightMargin(Right_margin);
				   MPpad->SetTopMargin(Top_margin+0.0025);
				   MPpad->SetBottomMargin(0.0);
				   if(iPanel==nPanels) MPpad->SetBottomMargin(lowestBottomMargin);

				   double deltaXaxisMin=0.;

				   cout<<"MultiPanel hist"<<endl;
				   TH1F *MPhist = new TH1F;
				   if(MPframe==1&&ptBin==1)MPhist = MPcanvasCS_rap1_pt1->DrawFrame(onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL-deltaXaxisMin,yMinMP,onia::cpmRange[cpmBinMax],yMaxMP);

				   if(MPframe==2&&ptBin==1)MPhist = MPcanvasHX_rap1_pt1->DrawFrame(onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL-deltaXaxisMin,yMinMP,onia::cpmRange[cpmBinMax],yMaxMP);
				   if(MPframe==3&&ptBin==1)MPhist = MPcanvasPX_rap1_pt1->DrawFrame(onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL-deltaXaxisMin,yMinMP,onia::cpmRange[cpmBinMax],yMaxMP);
				   if(MPframe==1&&ptBin==2)MPhist = MPcanvasCS_rap1_pt2->DrawFrame(onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL-deltaXaxisMin,yMinMP,onia::cpmRange[cpmBinMax],yMaxMP);
				   if(MPframe==2&&ptBin==2)MPhist = MPcanvasHX_rap1_pt2->DrawFrame(onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL-deltaXaxisMin,yMinMP,onia::cpmRange[cpmBinMax],yMaxMP);
				   if(MPframe==3&&ptBin==2)MPhist = MPcanvasPX_rap1_pt2->DrawFrame(onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL-deltaXaxisMin,yMinMP,onia::cpmRange[cpmBinMax],yMaxMP);

				   MPhist->SetXTitle("#it{N}_{ch}");
				   MPhist->GetXaxis()->SetTitleOffset(-1.35);

				   MPhist->SetYTitle(axislabel);
				   MPhist->GetYaxis()->SetTitleOffset(titleoffset);
				   MPhist->GetYaxis()->SetTitleSize(0.);
				   if(iPanel==nPanels) MPhist->GetYaxis()->SetTitleOffset(titleoffset*1.35);
				   if(iPanel==nPanels) MPhist->GetYaxis()->SetTitleSize(0.*(1-lowestBottomMargin));

				   MPhist->GetYaxis()->SetLabelSize(LabelSize*1.25);
				   MPhist->GetXaxis()->SetLabelSize(0.);
				   MPhist->GetYaxis()->SetLabelOffset(-0.015);
				   MPhist->GetXaxis()->SetLabelOffset(-0.06);

				   if(iPanel==nPanels) MPhist->GetYaxis()->SetLabelSize(LabelSize*1.25*(1-lowestBottomMargin));
				   MPhist->GetXaxis()->SetTitleSize(TitleSize*0.85);
				   MPhist->GetXaxis()->SetAxisColor(kWhite);
				   MPhist->GetYaxis()->SetAxisColor(kWhite);
				   MPhist->GetXaxis()->SetTicks("-");
				   MPhist->GetYaxis()->SetTicks("+");


				   double SpecialShift=0.01;
				   TLegend* MPframedepLegend;
				   MPframedepLegend=new TLegend(errorLegendX1,errorLegendY1*.8,errorLegendX2,errorLegendY2);
				   if(MPframe==1) MPframedepLegend=new TLegend(errorLegendX1,(errorLegendY2-(errorLegendY2-errorLegendY1)*(1-lowestBottomMargin)+SpecialShift)*.8,errorLegendX2,(errorLegendY2+SpecialShift)*.8);
				   MPframedepLegend->SetFillStyle(0);
				   MPframedepLegend->SetFillColor(0);
//				   MPframedepLegend->SetTextFont(72);
				   MPframedepLegend->SetTextSize(errorLegendFontSize);
				   if(MPframe==1) MPframedepLegend->SetTextSize(errorLegendFontSize*(1-lowestBottomMargin));
				   MPframedepLegend->SetBorderSize(0);

				   char MPframedepLegendEntry[200];


//				   TGraphAsymmErrors* graphMP_3sig_MPnew;
//				   TGraphAsymmErrors* graphMP_2sig_MPnew;
//				   TGraphAsymmErrors* graphMP_1sig_MPnew;
				   TGraphAsymmErrors* graphMP_MPnew;

				   if(iStateMP==1) graphMP_MPnew = (TGraphAsymmErrors*) infileMP1->Get(GraphName);
				   if(iStateMP==2) graphMP_MPnew = (TGraphAsymmErrors*) infileMP2->Get(GraphName);
				   if(iStateMP==3) graphMP_MPnew = (TGraphAsymmErrors*) infileMP3->Get(GraphName);

/*					if(iStateMP==1) graphMP_1sig_MPnew = (TGraphAsymmErrors*) infileMP1_1sig->Get(GraphName);
					if(iStateMP==2) graphMP_1sig_MPnew = (TGraphAsymmErrors*) infileMP2_1sig->Get(GraphName);
					if(iStateMP==3) graphMP_1sig_MPnew = (TGraphAsymmErrors*) infileMP3_1sig->Get(GraphName);
					if(iStateMP==1) graphMP_2sig_MPnew = (TGraphAsymmErrors*) infileMP1_2sig->Get(GraphName);
					if(iStateMP==2) graphMP_2sig_MPnew = (TGraphAsymmErrors*) infileMP2_2sig->Get(GraphName);
					if(iStateMP==3) graphMP_2sig_MPnew = (TGraphAsymmErrors*) infileMP3_2sig->Get(GraphName);
					if(iStateMP==1) graphMP_3sig_MPnew = (TGraphAsymmErrors*) infileMP1_3sig->Get(GraphName);
					if(iStateMP==2) graphMP_3sig_MPnew = (TGraphAsymmErrors*) infileMP2_3sig->Get(GraphName);
					if(iStateMP==3) graphMP_3sig_MPnew = (TGraphAsymmErrors*) infileMP3_3sig->Get(GraphName);
*/
					int cpmMP;
					int nBinsMP;
					double cpmCentre_MP[nBinscpm];
					double lmean_MP[nBinscpm];
					double lmean_errlow_MP[nBinscpm];
					double lmean_errhigh_MP[nBinscpm];
					double cpmCentre_errlow_MP[nBinscpm];
					double cpmCentre_errhigh_MP[nBinscpm];

			/*		nBinsMP=graphMP_1sig_MPnew->GetN();
					cpmMP=0;
					for(int cpmBinMP=1;cpmBinMP<nBinsMP+1;cpmBinMP++){
						graphMP_1sig_MPnew->GetPoint(cpmBinMP-1,cpmCentre_MP[cpmMP],lmean_MP[cpmMP]);
						lmean_errhigh_MP[cpmMP]=graphMP_1sig_MPnew->GetErrorYhigh(cpmBinMP-1);
						lmean_errlow_MP[cpmMP]=graphMP_1sig_MPnew->GetErrorYlow(cpmBinMP-1);
						cpmCentre_errhigh_MP[cpmMP]=graphMP_1sig_MPnew->GetErrorXhigh(cpmBinMP-1);
						cpmCentre_errlow_MP[cpmMP]=graphMP_1sig_MPnew->GetErrorXlow(cpmBinMP-1);
						/// Alter TGraph
						cpmCentre_errhigh_MP[cpmMP]=ColordBandWidth;
						cpmCentre_errlow_MP[cpmMP]=ColordBandWidth;
						cpmMP++;
					}
					graphMP_1sig_MPnew = new TGraphAsymmErrors(nBinsMP,cpmCentre_MP,lmean_MP,cpmCentre_errlow_MP,cpmCentre_errhigh_MP,lmean_errlow_MP,lmean_errhigh_MP);

					nBinsMP=graphMP_2sig_MPnew->GetN();
					cpmMP=0;
					for(int cpmBinMP=1;cpmBinMP<nBinsMP+1;cpmBinMP++){
						graphMP_2sig_MPnew->GetPoint(cpmBinMP-1,cpmCentre_MP[cpmMP],lmean_MP[cpmMP]);
						lmean_errhigh_MP[cpmMP]=graphMP_2sig_MPnew->GetErrorYhigh(cpmBinMP-1);
						lmean_errlow_MP[cpmMP]=graphMP_2sig_MPnew->GetErrorYlow(cpmBinMP-1);
						cpmCentre_errhigh_MP[cpmMP]=graphMP_2sig_MPnew->GetErrorXhigh(cpmBinMP-1);
						cpmCentre_errlow_MP[cpmMP]=graphMP_2sig_MPnew->GetErrorXlow(cpmBinMP-1);
						/// Alter TGraph
						cpmCentre_errhigh_MP[cpmMP]=ColordBandWidth;
						cpmCentre_errlow_MP[cpmMP]=ColordBandWidth;
						cpmMP++;
					}

					graphMP_2sig_MPnew = new TGraphAsymmErrors(nBinsMP,cpmCentre_MP,lmean_MP,cpmCentre_errlow_MP,cpmCentre_errhigh_MP,lmean_errlow_MP,lmean_errhigh_MP);

					nBinsMP=graphMP_3sig_MPnew->GetN();
					cpmMP=0;
					for(int cpmBinMP=1;cpmBinMP<nBinsMP+1;cpmBinMP++){
						graphMP_3sig_MPnew->GetPoint(cpmBinMP-1,cpmCentre_MP[cpmMP],lmean_MP[cpmMP]);
						lmean_errhigh_MP[cpmMP]=graphMP_3sig_MPnew->GetErrorYhigh(cpmBinMP-1);
						lmean_errlow_MP[cpmMP]=graphMP_3sig_MPnew->GetErrorYlow(cpmBinMP-1);
						cpmCentre_errhigh_MP[cpmMP]=graphMP_3sig_MPnew->GetErrorXhigh(cpmBinMP-1);
						cpmCentre_errlow_MP[cpmMP]=graphMP_3sig_MPnew->GetErrorXlow(cpmBinMP-1);
						/// Alter TGraph
						cpmCentre_errhigh_MP[cpmMP]=ColordBandWidth;
						cpmCentre_errlow_MP[cpmMP]=ColordBandWidth;
						cpmMP++;
					}
					graphMP_3sig_MPnew = new TGraphAsymmErrors(nBinsMP,cpmCentre_MP,lmean_MP,cpmCentre_errlow_MP,cpmCentre_errhigh_MP,lmean_errlow_MP,lmean_errhigh_MP);
*/
					nBinsMP=graphMP_MPnew->GetN();

					cpmMP=0;
					for(int cpmBinMP=1;cpmBinMP<nBinsMP+1;cpmBinMP++){

						graphMP_MPnew->GetPoint(cpmBinMP-1,cpmCentre_MP[cpmMP],lmean_MP[cpmMP]);
						if(ptBin == 2) cpmCentre_MP[cpmMP]=cpmCentre_MP[cpmMP]+1; ///for x-axis offset
						lmean_errhigh_MP[cpmMP]=graphMP_MPnew->GetErrorYhigh(cpmBinMP-1);
						lmean_errlow_MP[cpmMP]=graphMP_MPnew->GetErrorYlow(cpmBinMP-1);

						cpmCentre_errhigh_MP[cpmMP]=graphMP_MPnew->GetErrorXhigh(cpmBinMP-1);
						cpmCentre_errlow_MP[cpmMP]=graphMP_MPnew->GetErrorXlow(cpmBinMP-1);
						/// Alter TGraph
						cpmCentre_errhigh_MP[cpmMP]=0.;
						cpmCentre_errlow_MP[cpmMP]=0.;
						cpmMP++;

					}

					bool RemoveHorizontalErrorBar=true;
					if(RemoveHorizontalErrorBar) graphMP_MPnew = new TGraphAsymmErrors(nBinsMP,cpmCentre_MP,lmean_MP,cpmCentre_errlow_MP,cpmCentre_errhigh_MP,lmean_errlow_MP,lmean_errhigh_MP);

					if(ptBin == 1)
					{
					graphMP_MPnew->SetMarkerSize(MarkerSizeMP[0]);
					graphMP_MPnew->SetMarkerStyle(MarkerStyleMP[0]);
					graphMP_MPnew->SetMarkerColor(2);
					graphMP_MPnew->SetLineColor(2);
					}
					
					if(ptBin == 2)
					{
					graphMP_MPnew = new TGraphAsymmErrors(nBinsMP,cpmCentre_MP,lmean_MP,cpmCentre_errlow_MP,cpmCentre_errhigh_MP,lmean_errlow_MP,lmean_errhigh_MP);
					graphMP_MPnew->SetMarkerSize(MarkerSizeMP[0]);
					graphMP_MPnew->SetMarkerStyle(MarkerStyleMP[1]);
					graphMP_MPnew->SetMarkerColor(4);
					graphMP_MPnew->SetLineColor(4);
					}

/*					graphMP_1sig_MPnew->SetFillColor(OneSigColor);
					graphMP_1sig_MPnew->SetFillStyle(1001);
					graphMP_2sig_MPnew->SetFillColor(TwoSigColor);
					graphMP_2sig_MPnew->SetFillStyle(1001);
					graphMP_3sig_MPnew->SetFillColor(ThreeSigColor);
					graphMP_3sig_MPnew->SetFillStyle(1001);
*/

//					graphMP_3sig_MPnew->Draw("2");
//					graphMP_2sig_MPnew->Draw("2");
//					graphMP_1sig_MPnew->Draw("2");
					if(PlotAlteredPPDResults) {
						graphMP_MPnew->Draw("[]");
						graphMP_MPnew->Draw(drawGraphStyle);
					}
					
					if(PlotGlobalUnc) {
					    TGraphErrors *globunctgraph;
						sprintf(filename,"%s/macros/polFit/Systematics/%s/AverageSyst/GlobalUnc/TGraphResults_%dSUps.root",basedir,GlobalUncLoc,iStateMP);
						TFile *globuncfile = new TFile(filename,"READ");
//						char graphname[200];
//   					    sprintf(graphname,"l%s_%s_rap1_pt%d", whichlambda, whichframe, ptBin+1); 
				        globunctgraph = (TGraphErrors*) globuncfile->Get(GraphName);
						globunctgraph->Draw("2");
						globuncfile->Close();	
						
					  if(iStateMP==1&&iPanel==2&&ptBin==1){
					    TGraphErrors *globunctgraph;
						sprintf(filename,"%s/macros/polFit/Systematics/%s/AverageSyst/GlobalUnc/TGraphResults_%dSUps.root",basedir,GlobalUncLoc,iStateMP);
						TFile *globuncfile = new TFile(filename,"READ");
				        globunctgraph = (TGraphErrors*) globuncfile->Get(GraphName);
						globunctgraph->Draw("2");
						
						TGraphAsymmErrors *legendPhantom = (TGraphAsymmErrors*) globuncfile->Get("ltilde_CS_rap1_pt1");
						TGraphAsymmErrors *legendPhantom2 = (TGraphAsymmErrors*) globuncfile->Get("ltilde_CS_rap1_pt2");
	
					    legendPhantom->SetMarkerColor(kOrange);
			 		    legendPhantom->SetMarkerStyle(21);
					    legendPhantom->SetMarkerSize(10);
				   
					    legendPhantom2->SetMarkerColor(kTeal);
					    legendPhantom2->SetMarkerStyle(21);
					    legendPhantom2->SetMarkerSize(10);
						TLegend *leg = new TLegend(0.15,0.1,0.7,0.3);
						leg->SetBorderSize(0);
						leg->SetFillStyle(0);
						leg->SetFillColor(0);
						leg->SetTextSize(CentralsFontSizeMP*.8);
					    leg->AddEntry(legendPhantom,"Global Uncert., 10 < #it{p}_{T} < 15 GeV","p");
					    leg->AddEntry(legendPhantom2,"Global Uncert., 15 < #it{p}_{T} < 35 GeV","p");
	 				    leg->Draw();
					
					  }
					
					}



//				   graphMP_1sig_MPnew->SetLineColor(OneSigColor);
//				   graphMP_2sig_MPnew->SetLineColor(TwoSigColor);
//				   graphMP_3sig_MPnew->SetLineColor(ThreeSigColor);

				   if(PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"N_{ch} dependent uncert., 68.3 %% CL");
				   if(!PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"Tot. sys. uncert.");
				   MPframedepLegend->AddEntry(graphMP_MPnew,MPframedepLegendEntry,"p");
				   if(PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"Tot. uncert., 68.3 %% CL");
				   if(!PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"68.3 %% CL");
//				   MPframedepLegend->AddEntry(graphMP_1sig_MPnew,MPframedepLegendEntry,"f");
				   if(PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"Tot. uncert., 95.5 %% CL");
				   if(!PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"95.5 %% CL");
//				   MPframedepLegend->AddEntry(graphMP_2sig_MPnew,MPframedepLegendEntry,"f");
				   if(PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"Tot. uncert., 99.7 %% CL");
				   if(!PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"99.7 %% CL");
//				   MPframedepLegend->AddEntry(graphMP_3sig_MPnew,MPframedepLegendEntry,"f");

				   TGaxis *axisMPY1 = new TGaxis(onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL,yMinMP,onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL,yMaxMP,yMinMP,yMaxMP,AxisDivisions,"-US");
				   axisMPY1->SetTickSize(ticksize);
				   if(iPanel==nPanels) axisMPY1->SetTickSize(ticksize/(1-lowestBottomMargin));
				   axisMPY1->Draw("same");

				   TGaxis *axisMPY2 = new TGaxis(onia::cpmRange[cpmBinMax],yMinMP,onia::cpmRange[cpmBinMax],yMaxMP,yMinMP,yMaxMP,AxisDivisions,"+US");
				   axisMPY2->SetTickSize(ticksize);
				   if(iPanel==nPanels) axisMPY2->SetTickSize(ticksize/(1-lowestBottomMargin));
				   axisMPY2->Draw("same");


				   double deltaTrickAxisMax_MPnew;
				   deltaTrickAxisMax_MPnew=-0.001;
				   //if(iStateMP==3) deltaTrickAxisMax_MPnew=+0.001;

				   TGaxis *axisMPX1 = new TGaxis(onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL,yMinMP,onia::cpmRange[cpmBinMax],yMinMP,onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL+deltaTrickAxisMin,onia::cpmRange[cpmBinMax]+deltaTrickAxisMax_MPnew,AxisDivisions,"+S");
				   axisMPX1->SetTickSize(ticksize*2);
				   if(iPanel==nPanels) axisMPX1->SetLabelSize(LabelSize);
				   if(iPanel<nPanels) axisMPX1->SetLabelSize(0);
				   axisMPX1->SetLabelOffset(labelOffsetX);
				   if(iPanel==nPanels) axisMPX1->SetTickSize(ticksize/(1-lowestBottomMargin));
				   axisMPX1->Draw("same");

				   TGaxis *axisMPX2 = new TGaxis(onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL,yMaxMP,onia::cpmRange[cpmBinMax],yMaxMP,onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL+deltaTrickAxisMin,onia::cpmRange[cpmBinMax]+deltaTrickAxisMax_MPnew,AxisDivisions,"-US");
				   axisMPX2->SetTickSize(ticksize*2);
				   if(iPanel==nPanels) axisMPX2->SetTickSize(ticksize/(1-lowestBottomMargin));
				   axisMPX2->Draw("same");

				   whereTexteInPlotX=XtitlePosition;
				   whereTexteInPlotY=(yMaxMP+yMinMP)/2.-(yMaxMP-yMinMP)*XtitlePositionYshift;

				   char axistitleMPdep[200];
					if(iLam==1||iLam==5||iLam==9)  sprintf(axistitleMPdep,"#lambda_{#vartheta}");
					if(iLam==2||iLam==6||iLam==10)  sprintf(axistitleMPdep,"#lambda_{#varphi}");
					if(iLam==3||iLam==7||iLam==11)  sprintf(axistitleMPdep,"#lambda_{#vartheta#varphi}");

				   if(iPanel==nPanels) YaxistitleLatexSize=YaxistitleLatexSize*(1-lowestBottomMargin);
				   TLatex *MPYtitletext = new TLatex(whereTexteInPlotX-1,whereTexteInPlotY ,axistitleMPdep);
				   MPYtitletext->SetTextSize(YaxistitleLatexSize);
				   if(iPanel==nPanels) MPYtitletext->SetTextSize(YaxistitleLatexSize*(1-lowestBottomMargin));
				   MPYtitletext->SetTextColor(kBlack);
				   MPYtitletext->PaintLatex(whereTexteInPlotX-DeltaXminOVERALL-1,whereTexteInPlotY, YtitleAngle, YaxistitleLatexSize, axislabel);
				   MPYtitletext->Draw( "same" );



				   double increaseSize=1.45;
				   double SpecialShiftUpsilonLabel=0.9;
				   double SpecialShiftUpsilonLabelx=-3;
				   SpecialShiftUpsilonLabel=14;//1.25;//FRchange

				   char frameMPtex[200];
				   if(MPframe==1) sprintf(frameMPtex,"CS");
				   if(MPframe==2) sprintf(frameMPtex,"HX");
				   if(MPframe==3) sprintf(frameMPtex,"PX");
				   char texTexMP[200];
				   sprintf(texTexMP,"#Upsilon(%dS)", iStateMP);
				   TLatex *textMP = new TLatex(xRapText_MPnew+SpecialShiftUpsilonLabelx,yMin+(yMax-yMin)*yRapText*SpecialShiftUpsilonLabel,texTexMP);
				   textMP->SetTextSize(textSizeRap*increaseSize);
				   if(iPanel==nPanels) textMP->SetTextSize(textSizeRap*(1-lowestBottomMargin)*increaseSize);
				   textMP->Draw( "same" );

				   char abcdef[200];
				   if(iStateMP==1&&iPanel==1) sprintf(abcdef,"a)");
				   if(iStateMP==1&&iPanel==2) sprintf(abcdef,"b)");
				   if(iStateMP==1&&iPanel==3) sprintf(abcdef,"c)");
				   if(iStateMP==2&&iPanel==1) sprintf(abcdef,"d)");
				   if(iStateMP==2&&iPanel==2) sprintf(abcdef,"e)");
				   if(iStateMP==2&&iPanel==3) sprintf(abcdef,"f)");
				   if(iStateMP==3&&iPanel==1) sprintf(abcdef,"g)");
				   if(iStateMP==3&&iPanel==2) sprintf(abcdef,"h)");
				   if(iStateMP==3&&iPanel==3) sprintf(abcdef,"i)");

				   cout<<abcdef<<endl;
				   TLatex *tex_abcdef = new TLatex(xabcdefText,yMin+(yMax-yMin)*yRapText*0.92,abcdef);
				   tex_abcdef->SetTextSize(textSizeRap);
				   if(iPanel==nPanels) tex_abcdef->SetTextSize(textSizeRap*(1-lowestBottomMargin));
//				   tex_abcdef->Draw( "same" );

					 if(PlotFinalData&&DrawLatexStuff){

						TLine* extreme0MP = new TLine( onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL, 0, onia::cpmRange[cpmBinMax] ,0);
						extreme0MP->SetLineWidth( 1 );
						extreme0MP->SetLineStyle( 2 );
						extreme0MP->SetLineColor( kBlack );
						extreme0MP->Draw( "same" );

						TLine* extreme1MP = new TLine( onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL, 1, onia::cpmRange[cpmBinMax] , 1);
						extreme1MP->SetLineWidth( 1 );
						extreme1MP->SetLineStyle( 2 );
						extreme1MP->SetLineColor( kBlack );
//						if(iLam==1||iLam==5||iLam==9) extreme1MP->Draw( "same" );

						TLine* extreme2MP = new TLine( onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL, -1, onia::cpmRange[cpmBinMax] ,-1);
						extreme2MP->SetLineWidth( 1 );
						extreme2MP->SetLineStyle( 2 );
						extreme2MP->SetLineColor( kBlack );
//						if(iLam==1||iLam==5||iLam==9) extreme2MP->Draw( "same" );
//						if(iLam==4||iLam==8||iLam==12) extreme2MP->Draw( "same" );

					 }

					 MPlatexYmax=(yMax-yMin)*0.08+yMin;//FRchange

					 if(iStateMP==1&&iPanel==1){
					 cout<<"DRAW CMS preliminary Latex"<<endl;
					 char text[200];
					 char text2[200];
					 sprintf(text,"CMS");
					 if(DrawPreliminary) sprintf(text,"CMS  preliminary");
					 TLatex *CentralsText1MP = new TLatex((MPlatexX-DeltaXminOVERALL)*.3,.8,text);
					 CentralsText1MP->SetTextSize(CentralsFontSizeMP);
					 CentralsText1MP->Draw( "same" );
//					 if(DrawPreliminary) CentralsText1MP->Draw( "same" );
		/*			 sprintf(text,"L = 4.9 fb^{-1}");
					 TLatex *CentralsText2MP = new TLatex(MPlatexX,MPlatexYmax-2*MPlatexDeltaYmax,text);
					 CentralsText2MP->SetTextSize(CentralsFontSizeMP);
					 CentralsText2MP->Draw( "same" );
					 sprintf(text,"pp    #sqrt{s} = 7 TeV");
					 TLatex *CentralsText3MP = new TLatex(MPlatexX,MPlatexYmax-MPlatexDeltaYmax,text);
					 CentralsText3MP->SetTextSize(CentralsFontSizeMP);
					 CentralsText3MP->Draw( "same" );
		*/
					 }
					 
					 if(iStateMP==1&&iPanel==1&&ptBin==1){
					 cout<<"DRAW CMS preliminary Latex"<<endl;
					 char text[200];
					 sprintf(text,"pp      #sqrt{s} = 7 TeV     L = 4.9 fb^{-1}");
					 TLatex *CentralsText1MP = new TLatex((MPlatexX-DeltaXminOVERALL)*.1,MPlatexYmax,text);
					 CentralsText1MP->SetTextSize(CentralsFontSizeMP);
					 CentralsText1MP->Draw( "same" );
					 }
					 
					if(ptBin==1&&iPanel==1&&iStateMP==1){

				   	char frameMPtex[200];
				   	   if(MPframe==1) sprintf(frameMPtex,"CS frame");
					   if(MPframe==2) sprintf(frameMPtex,"HX frame");
					   if(MPframe==3) sprintf(frameMPtex,"PX frame");
					 char textFrame[200];
					 sprintf(textFrame,"%s", frameMPtex);
					 TLatex *TexFrame = new TLatex((MPlatexX-DeltaXminOVERALL)*.3,0.5,textFrame);
					 TexFrame->SetTextSize(CentralsFontSizeMP);
					 TexFrame->Draw( "same" );

			 		}

					 if(iStateMP==1&&iPanel==2&&MPframe!=1){
//						 MPframedepLegend->Draw("same");
						 double xStatErrorLine=13.06-DeltaXminOVERALL+DeltaXminOVERALL*0.075;
						 double StatErrorLineShift=0.1575;
						 double StatErrorLineLength=(errorLegendY2-errorLegendY1)*0.25;
						 double yMeanStatErrorLine=yMin+(yMax-yMin)*errorLegendY2-(errorLegendY2-errorLegendY1)*StatErrorLineShift;


							TLine* StatErrorLine = new TLine( xStatErrorLine, yMeanStatErrorLine-StatErrorLineLength/2., xStatErrorLine ,yMeanStatErrorLine+StatErrorLineLength/2.);
							StatErrorLine->SetLineWidth( 1 );
							StatErrorLine->SetLineStyle( 1 );
							StatErrorLine->SetLineColor( kBlack );
//							StatErrorLine->Draw( "same" );

					 }
					 if(iStateMP==1&&iPanel==3&&MPframe==1){
//						 MPframedepLegend->Draw("same");
						 double xStatErrorLine=13.06-DeltaXminOVERALL+DeltaXminOVERALL*0.075;
						 double StatErrorLineShift=0.1575;
						 double StatErrorLineLength=(errorLegendY2-errorLegendY1)*0.25;
						 double yMeanStatErrorLine=yMin+(yMax-yMin)*errorLegendY2-(errorLegendY2-errorLegendY1)*StatErrorLineShift;


							TLine* StatErrorLine = new TLine( xStatErrorLine, yMeanStatErrorLine-StatErrorLineLength/2., xStatErrorLine ,yMeanStatErrorLine+StatErrorLineLength/2.);
							StatErrorLine->SetLineWidth( 1 );
							StatErrorLine->SetLineStyle( 1 );
							StatErrorLine->SetLineColor( kBlack );
//							StatErrorLine->Draw( "same" );

					 }

//					 if(iStateMP==2&&iPanel==1){
					if(iStateMP==2&&iPanel==1){//FRchange

						 double DeltaXRap;
						 if(ptBin==1) DeltaXRap=19.5-DeltaXminOVERALL;
						 if(ptBin==2) DeltaXRap=19.5-DeltaXminOVERALL;

						 MPlatexYmax=(yMax-yMin)*0.08+yMin;//FRchange
//						 DeltaXRap=-DeltaXminOVERALL;//FRchange

						   char frameMPtex[200];
							 char textStateFrame[200];
							 if(ptBin==1) {
							/* sprintf(textStateFrame,"10 < #it{p}_{T} < 15 GeV");
							 TLatex *TexStateFrame = new TLatex((MPlatexX+DeltaXRap)*.6,MPlatexYmax*.7,textStateFrame);
							 TexStateFrame->SetTextSize(CentralsFontSizeMP);
							 TexStateFrame->SetTextColor(2);
							 TexStateFrame->Draw( "same" ); */
							 TLegend *leg = new TLegend(0.,0.2,0.4,0.375);
							 leg->AddEntry(graphMP_MPnew,"10 < #it{p}_{T} < 15 GeV","p");
							 //leg->SetTextColor(2);
							 leg->SetFillStyle(0);
							 leg->SetFillColor(0);
							 leg->SetLineColor(0);
							 leg->SetTextSize(CentralsFontSizeMP);
							 leg->SetBorderSize(0);
							 leg->Draw();
							 
							 }
							 if(ptBin==2) {
						/*	 sprintf(textStateFrame,"15 < #it{p}_{T} < 35 GeV", frameMPtex);
							 TLatex *TexStateFrame = new TLatex((MPlatexX+DeltaXRap)*.6,MPlatexYmax,textStateFrame);
							 TexStateFrame->SetTextSize(CentralsFontSizeMP);
							 TexStateFrame->SetTextColor(4);
							 TexStateFrame->Draw( "same" ); */
							 TLegend *leg = new TLegend(0.,0.025,0.4,0.2);
							 leg->AddEntry(graphMP_MPnew,"15 < #it{p}_{T} < 35 GeV","p");
							 //leg->SetTextColor(4);
							 leg->SetFillStyle(0);
							 leg->SetFillColor(0);
							 leg->SetLineColor(0);
							 leg->SetTextSize(CentralsFontSizeMP);
							 leg->SetBorderSize(0);
							 leg->Draw();
							 }
					 }
					 
					
					


					}//end iState Loop

					if(MPframe==1&&ptBin==1) MPcanvasCS_rap1_pt1->cd();
					if(MPframe==2&&ptBin==1) MPcanvasHX_rap1_pt1->cd();
					if(MPframe==3&&ptBin==1) MPcanvasPX_rap1_pt1->cd();
					if(MPframe==1&&ptBin==2) MPcanvasCS_rap1_pt2->cd();
					if(MPframe==2&&ptBin==2) MPcanvasHX_rap1_pt2->cd();
					if(MPframe==3&&ptBin==2) MPcanvasPX_rap1_pt2->cd();

					whereTexteInPlotX=0.36;
					whereTexteInPlotY=startValCoordY-deltaCoordY-1.35*labelOffsetX;

					  TLatex *MPXlabeltext = new TLatex(whereTexteInPlotX,whereTexteInPlotY ,"1");
					  MPXlabeltext->SetTextSize(XaxislabelLatexSize);
					  MPXlabeltext->SetTextColor(kBlack);
					  if(iPanel==nPanels&&!ShiftXminOVERALL) MPXlabeltext->Draw( "same" );

					whereTexteInPlotX+=x_tilde;
					  MPXlabeltext = new TLatex(whereTexteInPlotX,whereTexteInPlotY ,"1");
					  MPXlabeltext->SetTextSize(XaxislabelLatexSize);
					  MPXlabeltext->SetTextColor(kBlack);
					  if(iPanel==nPanels&&!ShiftXminOVERALL) MPXlabeltext->Draw( "same" );

					if(iLam==3&&ptBin==1){  sprintf(filename,"%s/FinalResultsCS_rap1_pt%d.pdf",FigDir,ptBin);
					if(PlotFinalData) MPcanvasCS_rap1_pt1->SaveAs(filename);
					sprintf(filename,"%s/FinalResultsCS_rap1_pt%d.C",FigDir,ptBin);
					if(PlotFinalData) MPcanvasCS_rap1_pt1->SaveAs(filename);
					MPcanvasCS_rap1_pt1->Close();
					}
					if(iLam==7&&ptBin==1){  sprintf(filename,"%s/FinalResultsHX_rap1_pt%d.pdf",FigDir,ptBin);
					if(PlotFinalData) MPcanvasHX_rap1_pt1->SaveAs(filename);
					sprintf(filename,"%s/FinalResultsHX_rap1_pt%d.C",FigDir,ptBin);
					if(PlotFinalData) MPcanvasHX_rap1_pt1->SaveAs(filename);
					MPcanvasHX_rap1_pt1->Close();
					}
					if(iLam==11&&ptBin==1){  sprintf(filename,"%s/FinalResultsPX_rap1_pt%d.pdf",FigDir,ptBin);
					if(PlotFinalData) MPcanvasPX_rap1_pt1->SaveAs(filename);
					sprintf(filename,"%s/FinalResultsPX_rap1_pt%d.C",FigDir,ptBin);
					if(PlotFinalData) MPcanvasPX_rap1_pt1->SaveAs(filename);
					MPcanvasPX_rap1_pt1->Close();
					}

					if(iLam==3&&ptBin==2){  sprintf(filename,"%s/FinalResultsCS_rap1_pt%d.pdf",FigDir,ptBin);
					if(PlotFinalData) MPcanvasCS_rap1_pt2->SaveAs(filename);
					sprintf(filename,"%s/FinalResultsCS_rap1_pt%d.C",FigDir,ptBin);
					if(PlotFinalData) MPcanvasCS_rap1_pt2->SaveAs(filename);
					MPcanvasCS_rap1_pt2->Close();
					}
					if(iLam==7&&ptBin==2){  sprintf(filename,"%s/FinalResultsHX_rap1_pt%d.pdf",FigDir,ptBin);
					if(PlotFinalData) MPcanvasHX_rap1_pt2->SaveAs(filename);
					sprintf(filename,"%s/FinalResultsHX_rap1_pt%d.C",FigDir,ptBin);
					if(PlotFinalData) MPcanvasHX_rap1_pt2->SaveAs(filename);
					MPcanvasHX_rap1_pt2->Close();
					}
					if(iLam==11&&ptBin==2){  sprintf(filename,"%s/FinalResultsPX_rap1_pt%d.pdf",FigDir,ptBin);
					if(PlotFinalData) MPcanvasPX_rap1_pt2->SaveAs(filename);
					sprintf(filename,"%s/FinalResultsPX_rap1_pt%d.C",FigDir,ptBin);
					if(PlotFinalData) MPcanvasPX_rap1_pt2->SaveAs(filename);
					MPcanvasPX_rap1_pt2->Close();
					}
}//end Frame dependent plots
			}


			double TwoTOthreePanelScaleFactor=deltaCoordY*2.+deltaCoordY*lowestBottomMargin/(1.-lowestBottomMargin)+(1-PadCoordYMax);//0.83125/3.*2.+0.16875;
			int MPcanvasXpixel_MPnewTilde=MPcanvasXpixelInitial*1.5;
			int MPcanvasYpixel_MPnewTilde=MPcanvasYpixelInitial*TwoTOthreePanelScaleFactor;

//			errorLegendFontSize*=TwoTOthreePanelScaleFactor;

			const int nPanels_MPnew=2;

			double PadCoordYMax_MPnew=PadCoordYMax;
			double deltaCoordY_MPnew=PadCoordYMax_MPnew/(double(nPanels_MPnew-1)+1./(1-lowestBottomMargin));
			double startValCoordY_MPnew=deltaCoordY_MPnew/(1-lowestBottomMargin);
//			double PadCoordY_MPnew[nPanels_MPnew+1]={0.,startValCoordY_MPnew,startValCoordY_MPnew+deltaCoordY_MPnew,PadCoordYMax_MPnew};
			double PadCoordY_MPnew[nPanels_MPnew+1]={0.,startValCoordY_MPnew,PadCoordYMax_MPnew};


	cout<<"begin NEW Frame independent plots"<<endl;
	cout<<"if(iLam==4||iLam==8||iLam==12)"<<endl;
	//begin Frame independent plots
	if(NEW_MPplots){
	if(iLam==4||iLam==8||iLam==12){

		int mainframe;
		if(iLam==4) mainframe=1;
		if(iLam==8) mainframe=2;
		if(iLam==12) mainframe=3;

		cout<<"iLam = "<<iLam<<endl;

		if((iLam==4||iLam==8||iLam==12)&&ptBin==1){
		MPcanvasTilde = new TCanvas("MPcanvasTilde", "MPcanvasTilde",MPcanvasXpixel_MPnewTilde,MPcanvasYpixel_MPnewTilde);
		MPcanvasTilde->SetFillColor(kWhite);
		MPcanvasTilde->GetFrame()->SetFillColor(kWhite);
		MPcanvasTilde->GetFrame()->SetBorderSize(0);
		}


		for(int iStateMP=1;iStateMP<4;iStateMP++){
			if(ptBin==1) iPanel=1;
			if(ptBin==2) iPanel=2;

			cout<<"MultiPanel canvas"<<endl;

			MPcanvasTilde->cd();

		   cout<<"MultiPanel pad"<<endl;
		   TPad *MPpad;
		   MPpad = new TPad("MPpad","MPpad",PadCoordX_newMP[iStateMP-1],PadCoordY_MPnew[nPanels_MPnew-iPanel],PadCoordX_newMP[iStateMP],PadCoordY_MPnew[nPanels_MPnew-iPanel+1]);
		   MPpad->Draw();
		   MPpad->cd();
		   MPpad->SetFillColor(kWhite);
		   MPpad->SetFrameFillColor(kWhite);
		   MPpad->SetBorderSize(0);
		   MPpad->SetLeftMargin(0.);
		   if(iStateMP==1) MPpad->SetLeftMargin(Left_margin);
		   MPpad->SetRightMargin(0.);
		   if(iStateMP==3) MPpad->SetRightMargin(Right_margin);
		   MPpad->SetTopMargin(Top_margin+0.0025);
		   MPpad->SetBottomMargin(0.0);
		   if(iPanel==nPanels_MPnew) MPpad->SetBottomMargin(lowestBottomMargin);


		   cout<<"MultiPanel hist"<<endl;
		   TH1F *MPhist = new TH1F;
		   MPhist = MPcanvasTilde->DrawFrame(onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL,yMinMP,onia::cpmRange[cpmBinMax],yMaxMP);

		   MPhist->SetXTitle("#it{N}_{ch}");
		   MPhist->GetXaxis()->SetTitleOffset(-1.35);

		   MPhist->SetYTitle(axislabel);
		   MPhist->GetYaxis()->SetTitleOffset(titleoffset);
		   MPhist->GetYaxis()->SetTitleSize(0.);
		   if(iPanel==nPanels_MPnew) MPhist->GetYaxis()->SetTitleOffset(titleoffset*1.35);
		   if(iPanel==nPanels_MPnew) MPhist->GetYaxis()->SetTitleSize(0.*(1-lowestBottomMargin));

		   MPhist->GetYaxis()->SetLabelSize(LabelSize*1.25);
		   MPhist->GetXaxis()->SetLabelSize(0.);
		   MPhist->GetYaxis()->SetLabelOffset(-0.015);
		   MPhist->GetXaxis()->SetLabelOffset(-0.06);

		   if(iPanel==nPanels_MPnew) MPhist->GetYaxis()->SetLabelSize(LabelSize*1.25*(1-lowestBottomMargin));
		   MPhist->GetXaxis()->SetTitleSize(TitleSize*0.85);
		   MPhist->GetXaxis()->SetAxisColor(kWhite);
		   MPhist->GetYaxis()->SetAxisColor(kWhite);
		   MPhist->GetXaxis()->SetTicks("-");
		   MPhist->GetYaxis()->SetTicks("+");

		   TLegend* MPframedepLegendError;
//		   MPframedepLegendError=new TLegend(errorLegendX1-Left_margin,errorLegendY1,errorLegendX2-Left_margin,errorLegendY2);
		   MPframedepLegendError=new TLegend(errorLegendX1,(errorLegendY2-(errorLegendY2-errorLegendY1)*(1-lowestBottomMargin))*.9,errorLegendX2,errorLegendY2*.8);
		   MPframedepLegendError->SetFillColor(0);
		   MPframedepLegendError->SetFillStyle(0);
//		   MPframedepLegendError->SetTextFont(72);
		   MPframedepLegendError->SetTextSize(errorLegendFontSize*(1-lowestBottomMargin));
		   MPframedepLegendError->SetBorderSize(0);

		   char MPframedepLegendEntry[200];


		   TGraphAsymmErrors* graphMP1;
		   TGraphAsymmErrors* graphMP2;
		   TGraphAsymmErrors* graphMP3;

/*		   TGraphAsymmErrors* graphMP1_1sig;
		   TGraphAsymmErrors* graphMP1_2sig;
		   TGraphAsymmErrors* graphMP1_3sig;
		   TGraphAsymmErrors* graphMP2_1sig;
		   TGraphAsymmErrors* graphMP2_2sig;
		   TGraphAsymmErrors* graphMP2_3sig;
		   TGraphAsymmErrors* graphMP3_1sig;
		   TGraphAsymmErrors* graphMP3_2sig;
		   TGraphAsymmErrors* graphMP3_3sig;
*/
		   TLegend* MPtildeLegend;
			MPtildeLegend=new TLegend(0.8,0.75,1.,0.95);
			MPtildeLegend->SetFillColor(0);
			MPtildeLegend->SetFillStyle(0);
//			MPtildeLegend->SetTextFont(72);
			MPtildeLegend->SetTextSize(0.07);
			MPtildeLegend->SetBorderSize(0);
			char MPtildeLegendEntry[200];

		   for(int iFrameMP=1;iFrameMP<4;iFrameMP++){

			   char GraphNameMP[200];


			   if(iFrameMP==1){
				   sprintf(GraphNameMP,"ltilde_CS_rap1_pt%d",ptBin);
			   }
			   if(iFrameMP==2){
				   sprintf(GraphNameMP,"ltilde_HX_rap1_pt%d",ptBin);
			   }
			   if(iFrameMP==3){
				   sprintf(GraphNameMP,"ltilde_PX_rap1_pt%d",ptBin);
			   }

				graphMP1 = (TGraphAsymmErrors*) infileMP1->Get(GraphNameMP);
				graphMP2 = (TGraphAsymmErrors*) infileMP2->Get(GraphNameMP);
				graphMP3 = (TGraphAsymmErrors*) infileMP3->Get(GraphNameMP);

				int MarkerDefinitionForThisBin[4][4]={{0,0,0,0},{0,1,2,3},{0,2,1,3},{0,2,3,1}};


				double cpmCentreMP[nBinscpm];
				double cpmCentreErr_lowMP[nBinscpm];
				double cpmCentreErr_highMP[nBinscpm];
				double lmeanMP[nBinscpm];
				double lmean_errlowMP[nBinscpm];
				double lmean_errhighMP[nBinscpm];

				double ShiftTildePlot;
				double ShiftTildePlotZero=0.75;

				if(MarkerDefinitionForThisBin[mainframe][iFrameMP]==1) ShiftTildePlot=0.;
				if(MarkerDefinitionForThisBin[mainframe][iFrameMP]==2) ShiftTildePlot=ShiftTildePlotZero;
				if(MarkerDefinitionForThisBin[mainframe][iFrameMP]==3) ShiftTildePlot=-ShiftTildePlotZero;

				bool RemoveHorizontalErrorBar=true;

				int cpm=0;
				for(int cpmBin = cpmBinMin; cpmBin < cpmBinMax+1; cpmBin++) {

					graphMP1->GetPoint(cpmBin-1,cpmCentreMP[cpm],lmeanMP[cpm]);
					cpmCentreErr_highMP[cpm]=graphMP1->GetErrorXhigh(cpmBin-1);
					cpmCentreErr_lowMP[cpm]=graphMP1->GetErrorXlow(cpmBin-1);
					lmean_errhighMP[cpm]=graphMP1->GetErrorYhigh(cpmBin-1);
					lmean_errlowMP[cpm]=graphMP1->GetErrorYlow(cpmBin-1);

					cpmCentreMP[cpm]=cpmCentreMP[cpm]+ShiftTildePlot;
					cpmCentreErr_highMP[cpm]=cpmCentreErr_highMP[cpm]-ShiftTildePlot;
					cpmCentreErr_lowMP[cpm]=cpmCentreErr_lowMP[cpm]-ShiftTildePlot;
					if(RemoveHorizontalErrorBar) cpmCentreErr_highMP[cpm]=0;
					if(RemoveHorizontalErrorBar) cpmCentreErr_lowMP[cpm]=0;

				cpm++;
				}

				graphMP1 = new TGraphAsymmErrors(nBinscpm,cpmCentreMP,lmeanMP,cpmCentreErr_lowMP,cpmCentreErr_highMP,lmean_errlowMP,lmean_errhighMP);

				cpm=0;
				for(int cpmBin = cpmBinMin; cpmBin < cpmBinMax+1; cpmBin++) {

					graphMP2->GetPoint(cpmBin-1,cpmCentreMP[cpm],lmeanMP[cpm]);
					cpmCentreErr_highMP[cpm]=graphMP2->GetErrorXhigh(cpmBin-1);
					cpmCentreErr_lowMP[cpm]=graphMP2->GetErrorXlow(cpmBin-1);
					lmean_errhighMP[cpm]=graphMP2->GetErrorYhigh(cpmBin-1);
					lmean_errlowMP[cpm]=graphMP2->GetErrorYlow(cpmBin-1);

					cpmCentreMP[cpm]=cpmCentreMP[cpm]+ShiftTildePlot;
					cpmCentreErr_highMP[cpm]=cpmCentreErr_highMP[cpm]-ShiftTildePlot;
					cpmCentreErr_lowMP[cpm]=cpmCentreErr_lowMP[cpm]-ShiftTildePlot;
					if(RemoveHorizontalErrorBar) cpmCentreErr_highMP[cpm]=0;
					if(RemoveHorizontalErrorBar) cpmCentreErr_lowMP[cpm]=0;

				cpm++;
				}

				graphMP2 = new TGraphAsymmErrors(nBinscpm,cpmCentreMP,lmeanMP,cpmCentreErr_lowMP,cpmCentreErr_highMP,lmean_errlowMP,lmean_errhighMP);

				cpm=0;
				for(int cpmBin = cpmBinMin; cpmBin < cpmBinMax+1; cpmBin++) {

					graphMP3->GetPoint(cpmBin-1,cpmCentreMP[cpm],lmeanMP[cpm]);
					cpmCentreErr_highMP[cpm]=graphMP3->GetErrorXhigh(cpmBin-1);
					cpmCentreErr_lowMP[cpm]=graphMP3->GetErrorXlow(cpmBin-1);
					lmean_errhighMP[cpm]=graphMP3->GetErrorYhigh(cpmBin-1);
					lmean_errlowMP[cpm]=graphMP3->GetErrorYlow(cpmBin-1);

					cpmCentreMP[cpm]=cpmCentreMP[cpm]+ShiftTildePlot;
					cpmCentreErr_highMP[cpm]=cpmCentreErr_highMP[cpm]-ShiftTildePlot;
					cpmCentreErr_lowMP[cpm]=cpmCentreErr_lowMP[cpm]-ShiftTildePlot;
					if(RemoveHorizontalErrorBar) cpmCentreErr_highMP[cpm]=0;
					if(RemoveHorizontalErrorBar) cpmCentreErr_lowMP[cpm]=0;

				cpm++;
				}

				graphMP3 = new TGraphAsymmErrors(nBinscpm,cpmCentreMP,lmeanMP,cpmCentreErr_lowMP,cpmCentreErr_highMP,lmean_errlowMP,lmean_errhighMP);

				graphMP1->SetMarkerColor(MarkerColorMP[MarkerDefinitionForThisBin[mainframe][iFrameMP]]);
				graphMP1->SetLineColor(MarkerColorMP[MarkerDefinitionForThisBin[mainframe][iFrameMP]]);
				graphMP1->SetMarkerStyle(MarkerStyleMPtilde[MarkerDefinitionForThisBin[mainframe][iFrameMP]]);
				graphMP1->SetMarkerSize(MarkerSizeMP[MarkerDefinitionForThisBin[mainframe][iFrameMP]]);

				graphMP2->SetMarkerColor(MarkerColorMP[MarkerDefinitionForThisBin[mainframe][iFrameMP]]);
				graphMP2->SetLineColor(MarkerColorMP[MarkerDefinitionForThisBin[mainframe][iFrameMP]]);
				graphMP2->SetMarkerStyle(MarkerStyleMPtilde[MarkerDefinitionForThisBin[mainframe][iFrameMP]]);
				graphMP2->SetMarkerSize(MarkerSizeMP[MarkerDefinitionForThisBin[mainframe][iFrameMP]]);

				graphMP3->SetMarkerColor(MarkerColorMP[MarkerDefinitionForThisBin[mainframe][iFrameMP]]);
				graphMP3->SetLineColor(MarkerColorMP[MarkerDefinitionForThisBin[mainframe][iFrameMP]]);
				graphMP3->SetMarkerStyle(MarkerStyleMPtilde[MarkerDefinitionForThisBin[mainframe][iFrameMP]]);
				graphMP3->SetMarkerSize(MarkerSizeMP[MarkerDefinitionForThisBin[mainframe][iFrameMP]]);


				if(mainframe==1&&iFrameMP==1){ sprintf(MPtildeLegendEntry,"CS"); MPtildeLegend->AddEntry(graphMP1,MPtildeLegendEntry,"p"); }
				if(mainframe!=1&&iFrameMP==1){ sprintf(MPtildeLegendEntry,"CS"); MPtildeLegend->AddEntry(graphMP1,MPtildeLegendEntry,"p"); }

				if(mainframe==2&&iFrameMP==2){ sprintf(MPtildeLegendEntry,"HX"); MPtildeLegend->AddEntry(graphMP1,MPtildeLegendEntry,"p"); }
				if(mainframe!=2&&iFrameMP==2){ sprintf(MPtildeLegendEntry,"HX"); MPtildeLegend->AddEntry(graphMP1,MPtildeLegendEntry,"p"); }

				if(mainframe==3&&iFrameMP==3){ sprintf(MPtildeLegendEntry,"PX"); MPtildeLegend->AddEntry(graphMP1,MPtildeLegendEntry,"p"); }
				if(mainframe!=3&&iFrameMP==3){ sprintf(MPtildeLegendEntry,"PX"); MPtildeLegend->AddEntry(graphMP1,MPtildeLegendEntry,"p"); }



				   if(mainframe==1){
					   sprintf(GraphNameMP,"ltilde_CS_rap1_pt%d",ptBin);
				   }
				   if(mainframe==2){
					   sprintf(GraphNameMP,"ltilde_HX_rap1_pt%d",ptBin);
				   }
				   if(mainframe==3){
					   sprintf(GraphNameMP,"ltilde_PX_rap1_pt%d",ptBin);
				   }

/*					graphMP1_1sig = (TGraphAsymmErrors*) infileMP1_1sig->Get(GraphNameMP);
					graphMP1_2sig = (TGraphAsymmErrors*) infileMP1_2sig->Get(GraphNameMP);
					graphMP1_3sig = (TGraphAsymmErrors*) infileMP1_3sig->Get(GraphNameMP);
					graphMP2_1sig = (TGraphAsymmErrors*) infileMP2_1sig->Get(GraphNameMP);
					graphMP2_2sig = (TGraphAsymmErrors*) infileMP2_2sig->Get(GraphNameMP);
					graphMP2_3sig = (TGraphAsymmErrors*) infileMP2_3sig->Get(GraphNameMP);
					graphMP3_1sig = (TGraphAsymmErrors*) infileMP3_1sig->Get(GraphNameMP);
					graphMP3_2sig = (TGraphAsymmErrors*) infileMP3_2sig->Get(GraphNameMP);
					graphMP3_3sig = (TGraphAsymmErrors*) infileMP3_3sig->Get(GraphNameMP);
*/
					int cpmMP;
					int nBinsMP;
					double cpmCentre_MP[nBinscpm];
					double lmean_MP[nBinscpm];
					double lmean_errlow_MP[nBinscpm];
					double lmean_errhigh_MP[nBinscpm];
					double cpmCentre_errlow_MP[nBinscpm];
					double cpmCentre_errhigh_MP[nBinscpm];

/*					nBinsMP=graphMP1_1sig->GetN();
					cpmMP=0;
					for(int cpmBinMP=1;cpmBinMP<nBinsMP+1;cpmBinMP++){
						graphMP1_1sig->GetPoint(cpmBinMP-1,cpmCentre_MP[cpmMP],lmean_MP[cpmMP]);
						lmean_errhigh_MP[cpmMP]=graphMP1_1sig->GetErrorYhigh(cpmBinMP-1);
						lmean_errlow_MP[cpmMP]=graphMP1_1sig->GetErrorYlow(cpmBinMP-1);
						cpmCentre_errhigh_MP[cpmMP]=graphMP1_1sig->GetErrorXhigh(cpmBinMP-1);
						cpmCentre_errlow_MP[cpmMP]=graphMP1_1sig->GetErrorXlow(cpmBinMP-1);
						/// Alter TGraph
						cpmCentre_errhigh_MP[cpmMP]=ColordBandWidth;
						cpmCentre_errlow_MP[cpmMP]=ColordBandWidth;
						cpmMP++;
					}
					graphMP1_1sig = new TGraphAsymmErrors(nBinsMP,cpmCentre_MP,lmean_MP,cpmCentre_errlow_MP,cpmCentre_errhigh_MP,lmean_errlow_MP,lmean_errhigh_MP);

					nBinsMP=graphMP1_2sig->GetN();
					cpmMP=0;
					for(int cpmBinMP=1;cpmBinMP<nBinsMP+1;cpmBinMP++){
						graphMP1_2sig->GetPoint(cpmBinMP-1,cpmCentre_MP[cpmMP],lmean_MP[cpmMP]);
						lmean_errhigh_MP[cpmMP]=graphMP1_2sig->GetErrorYhigh(cpmBinMP-1);
						lmean_errlow_MP[cpmMP]=graphMP1_2sig->GetErrorYlow(cpmBinMP-1);
						cpmCentre_errhigh_MP[cpmMP]=graphMP1_2sig->GetErrorXhigh(cpmBinMP-1);
						cpmCentre_errlow_MP[cpmMP]=graphMP1_2sig->GetErrorXlow(cpmBinMP-1);
						/// Alter TGraph
						cpmCentre_errhigh_MP[cpmMP]=ColordBandWidth;
						cpmCentre_errlow_MP[cpmMP]=ColordBandWidth;
						cpmMP++;
					}
					graphMP1_2sig = new TGraphAsymmErrors(nBinsMP,cpmCentre_MP,lmean_MP,cpmCentre_errlow_MP,cpmCentre_errhigh_MP,lmean_errlow_MP,lmean_errhigh_MP);

					nBinsMP=graphMP1_3sig->GetN();
					cpmMP=0;
					for(int cpmBinMP=1;cpmBinMP<nBinsMP+1;cpmBinMP++){
						graphMP1_3sig->GetPoint(cpmBinMP-1,cpmCentre_MP[cpmMP],lmean_MP[cpmMP]);
						lmean_errhigh_MP[cpmMP]=graphMP1_3sig->GetErrorYhigh(cpmBinMP-1);
						lmean_errlow_MP[cpmMP]=graphMP1_3sig->GetErrorYlow(cpmBinMP-1);
						cpmCentre_errhigh_MP[cpmMP]=graphMP1_3sig->GetErrorXhigh(cpmBinMP-1);
						cpmCentre_errlow_MP[cpmMP]=graphMP1_3sig->GetErrorXlow(cpmBinMP-1);
						/// Alter TGraph
						cpmCentre_errhigh_MP[cpmMP]=ColordBandWidth;
						cpmCentre_errlow_MP[cpmMP]=ColordBandWidth;
						cpmMP++;
					}
					graphMP1_3sig = new TGraphAsymmErrors(nBinsMP,cpmCentre_MP,lmean_MP,cpmCentre_errlow_MP,cpmCentre_errhigh_MP,lmean_errlow_MP,lmean_errhigh_MP);




					nBinsMP=graphMP2_1sig->GetN();
					cpmMP=0;
					for(int cpmBinMP=1;cpmBinMP<nBinsMP+1;cpmBinMP++){
						graphMP2_1sig->GetPoint(cpmBinMP-1,cpmCentre_MP[cpmMP],lmean_MP[cpmMP]);
						lmean_errhigh_MP[cpmMP]=graphMP2_1sig->GetErrorYhigh(cpmBinMP-1);
						lmean_errlow_MP[cpmMP]=graphMP2_1sig->GetErrorYlow(cpmBinMP-1);
						cpmCentre_errhigh_MP[cpmMP]=graphMP2_1sig->GetErrorXhigh(cpmBinMP-1);
						cpmCentre_errlow_MP[cpmMP]=graphMP2_1sig->GetErrorXlow(cpmBinMP-1);
						/// Alter TGraph
						cpmCentre_errhigh_MP[cpmMP]=ColordBandWidth;
						cpmCentre_errlow_MP[cpmMP]=ColordBandWidth;
						cpmMP++;
					}
					graphMP2_1sig = new TGraphAsymmErrors(nBinsMP,cpmCentre_MP,lmean_MP,cpmCentre_errlow_MP,cpmCentre_errhigh_MP,lmean_errlow_MP,lmean_errhigh_MP);

					nBinsMP=graphMP2_2sig->GetN();
					cpmMP=0;
					for(int cpmBinMP=1;cpmBinMP<nBinsMP+1;cpmBinMP++){
						graphMP2_2sig->GetPoint(cpmBinMP-1,cpmCentre_MP[cpmMP],lmean_MP[cpmMP]);
						lmean_errhigh_MP[cpmMP]=graphMP2_2sig->GetErrorYhigh(cpmBinMP-1);
						lmean_errlow_MP[cpmMP]=graphMP2_2sig->GetErrorYlow(cpmBinMP-1);
						cpmCentre_errhigh_MP[cpmMP]=graphMP2_2sig->GetErrorXhigh(cpmBinMP-1);
						cpmCentre_errlow_MP[cpmMP]=graphMP2_2sig->GetErrorXlow(cpmBinMP-1);
						/// Alter TGraph
						cpmCentre_errhigh_MP[cpmMP]=ColordBandWidth;
						cpmCentre_errlow_MP[cpmMP]=ColordBandWidth;
						cpmMP++;
					}
					graphMP2_2sig = new TGraphAsymmErrors(nBinsMP,cpmCentre_MP,lmean_MP,cpmCentre_errlow_MP,cpmCentre_errhigh_MP,lmean_errlow_MP,lmean_errhigh_MP);

					nBinsMP=graphMP2_3sig->GetN();
					cpmMP=0;
					for(int cpmBinMP=1;cpmBinMP<nBinsMP+1;cpmBinMP++){
						graphMP2_3sig->GetPoint(cpmBinMP-1,cpmCentre_MP[cpmMP],lmean_MP[cpmMP]);
						lmean_errhigh_MP[cpmMP]=graphMP2_3sig->GetErrorYhigh(cpmBinMP-1);
						lmean_errlow_MP[cpmMP]=graphMP2_3sig->GetErrorYlow(cpmBinMP-1);
						cpmCentre_errhigh_MP[cpmMP]=graphMP2_3sig->GetErrorXhigh(cpmBinMP-1);
						cpmCentre_errlow_MP[cpmMP]=graphMP2_3sig->GetErrorXlow(cpmBinMP-1);
						/// Alter TGraph
						cpmCentre_errhigh_MP[cpmMP]=ColordBandWidth;
						cpmCentre_errlow_MP[cpmMP]=ColordBandWidth;
						cpmMP++;
					}
					graphMP2_3sig = new TGraphAsymmErrors(nBinsMP,cpmCentre_MP,lmean_MP,cpmCentre_errlow_MP,cpmCentre_errhigh_MP,lmean_errlow_MP,lmean_errhigh_MP);




					nBinsMP=graphMP3_1sig->GetN();
					cpmMP=0;
					for(int cpmBinMP=1;cpmBinMP<nBinsMP+1;cpmBinMP++){
						graphMP3_1sig->GetPoint(cpmBinMP-1,cpmCentre_MP[cpmMP],lmean_MP[cpmMP]);
						lmean_errhigh_MP[cpmMP]=graphMP3_1sig->GetErrorYhigh(cpmBinMP-1);
						lmean_errlow_MP[cpmMP]=graphMP3_1sig->GetErrorYlow(cpmBinMP-1);
						cpmCentre_errhigh_MP[cpmMP]=graphMP3_1sig->GetErrorXhigh(cpmBinMP-1);
						cpmCentre_errlow_MP[cpmMP]=graphMP3_1sig->GetErrorXlow(cpmBinMP-1);
						/// Alter TGraph
						cpmCentre_errhigh_MP[cpmMP]=ColordBandWidth;
						cpmCentre_errlow_MP[cpmMP]=ColordBandWidth;
						cpmMP++;
					}
					graphMP3_1sig = new TGraphAsymmErrors(nBinsMP,cpmCentre_MP,lmean_MP,cpmCentre_errlow_MP,cpmCentre_errhigh_MP,lmean_errlow_MP,lmean_errhigh_MP);

					nBinsMP=graphMP3_2sig->GetN();
					cpmMP=0;
					for(int cpmBinMP=1;cpmBinMP<nBinsMP+1;cpmBinMP++){
						graphMP3_2sig->GetPoint(cpmBinMP-1,cpmCentre_MP[cpmMP],lmean_MP[cpmMP]);
						lmean_errhigh_MP[cpmMP]=graphMP3_2sig->GetErrorYhigh(cpmBinMP-1);
						lmean_errlow_MP[cpmMP]=graphMP3_2sig->GetErrorYlow(cpmBinMP-1);
						cpmCentre_errhigh_MP[cpmMP]=graphMP3_2sig->GetErrorXhigh(cpmBinMP-1);
						cpmCentre_errlow_MP[cpmMP]=graphMP3_2sig->GetErrorXlow(cpmBinMP-1);
						/// Alter TGraph
						cpmCentre_errhigh_MP[cpmMP]=ColordBandWidth;
						cpmCentre_errlow_MP[cpmMP]=ColordBandWidth;
						cpmMP++;
					}
					graphMP3_2sig = new TGraphAsymmErrors(nBinsMP,cpmCentre_MP,lmean_MP,cpmCentre_errlow_MP,cpmCentre_errhigh_MP,lmean_errlow_MP,lmean_errhigh_MP);

					nBinsMP=graphMP3_3sig->GetN();
					cpmMP=0;
					for(int cpmBinMP=1;cpmBinMP<nBinsMP+1;cpmBinMP++){
						graphMP3_3sig->GetPoint(cpmBinMP-1,cpmCentre_MP[cpmMP],lmean_MP[cpmMP]);
						lmean_errhigh_MP[cpmMP]=graphMP3_3sig->GetErrorYhigh(cpmBinMP-1);
						lmean_errlow_MP[cpmMP]=graphMP3_3sig->GetErrorYlow(cpmBinMP-1);
						cpmCentre_errhigh_MP[cpmMP]=graphMP3_3sig->GetErrorXhigh(cpmBinMP-1);
						cpmCentre_errlow_MP[cpmMP]=graphMP3_3sig->GetErrorXlow(cpmBinMP-1);
						/// Alter TGraph
						cpmCentre_errhigh_MP[cpmMP]=ColordBandWidth;
						cpmCentre_errlow_MP[cpmMP]=ColordBandWidth;
						cpmMP++;
					}
					graphMP3_3sig = new TGraphAsymmErrors(nBinsMP,cpmCentre_MP,lmean_MP,cpmCentre_errlow_MP,cpmCentre_errhigh_MP,lmean_errlow_MP,lmean_errhigh_MP);



					graphMP1_1sig->SetFillColor(OneSigColor);
					graphMP1_1sig->SetFillStyle(1001);
					graphMP1_2sig->SetFillColor(TwoSigColor);
					graphMP1_2sig->SetFillStyle(1001);
					graphMP1_3sig->SetFillColor(ThreeSigColor);
					graphMP1_3sig->SetFillStyle(1001);

					graphMP2_1sig->SetFillColor(OneSigColor);
					graphMP2_1sig->SetFillStyle(1001);
					graphMP2_2sig->SetFillColor(TwoSigColor);
					graphMP2_2sig->SetFillStyle(1001);
					graphMP2_3sig->SetFillColor(ThreeSigColor);
					graphMP2_3sig->SetFillStyle(1001);

					graphMP3_1sig->SetFillColor(OneSigColor);
					graphMP3_1sig->SetFillStyle(1001);
					graphMP3_2sig->SetFillColor(TwoSigColor);
					graphMP3_2sig->SetFillStyle(1001);
					graphMP3_3sig->SetFillColor(ThreeSigColor);
					graphMP3_3sig->SetFillStyle(1001);
*/
		   if(iStateMP==1){

			   if(iFrameMP==1){
//				   graphMP1_3sig->Draw("2");
//				   graphMP1_2sig->Draw("2");
//				   graphMP1_1sig->Draw("2");
				   if(mainframe==1) graphMP1->Draw("[]");
				   if(mainframe==1) graphMP1->Draw(drawGraphStyle);
			   }
			   if(iFrameMP==2){
				   if(mainframe==2) graphMP1->Draw("[]");
				   if(mainframe==2) graphMP1->Draw(drawGraphStyle);
			   }
			   if(iFrameMP==3){
				   if(mainframe==3) graphMP1->Draw("[]");
				   if(mainframe==3) graphMP1->Draw(drawGraphStyle);
			   }

			   if(iFrameMP==1){
				   if(mainframe!=1) graphMP1->Draw("PX");
			   }
			   if(iFrameMP==2){
				   if(mainframe!=2) graphMP1->Draw("PX");
			   }
			   if(iFrameMP==3){
				   if(mainframe!=3) graphMP1->Draw("PX");
			   }

		   }
		   if(iStateMP==2){

			   if(iFrameMP==1){
//				   graphMP2_3sig->Draw("2");
//				   graphMP2_2sig->Draw("2");
//				   graphMP2_1sig->Draw("2");
				   if(mainframe==1) graphMP2->Draw("[]");
				   if(mainframe==1) graphMP2->Draw(drawGraphStyle);
			   }
			   if(iFrameMP==2){
				   if(mainframe==2) graphMP2->Draw("[]");
				   if(mainframe==2) graphMP2->Draw(drawGraphStyle);
			   }
			   if(iFrameMP==3){
				   if(mainframe==3) graphMP2->Draw("[]");
				   if(mainframe==3) graphMP2->Draw(drawGraphStyle);
			   }

			   if(iFrameMP==1){
				   if(mainframe!=1) graphMP2->Draw("PX");
			   }
			   if(iFrameMP==2){
				   if(mainframe!=2) graphMP2->Draw("PX");
			   }
			   if(iFrameMP==3){
				   if(mainframe!=3) graphMP2->Draw("PX");
			   }

		   }
		   if(iStateMP==3){

			   if(iFrameMP==1){
//				   graphMP3_3sig->Draw("2");
//				   graphMP3_2sig->Draw("2");
//				   graphMP3_1sig->Draw("2");
				   if(mainframe==1) graphMP3->Draw("[]");
				   if(mainframe==1) graphMP3->Draw(drawGraphStyle);
			   }
			   if(iFrameMP==2){
				   if(mainframe==2) graphMP3->Draw("[]");
				   if(mainframe==2) graphMP3->Draw(drawGraphStyle);
			   }
			   if(iFrameMP==3){
				   if(mainframe==3) graphMP3->Draw("[]");
				   if(mainframe==3) graphMP3->Draw(drawGraphStyle);
			   }

			   if(iFrameMP==1){
				   if(mainframe!=1) graphMP3->Draw("PX");
			   }
			   if(iFrameMP==2){
				   if(mainframe!=2) graphMP3->Draw("PX");
			   }
			   if(iFrameMP==3){
				   if(mainframe!=3) graphMP3->Draw("PX");
			   }


		   }
		   }



		   TGaxis *axisMPY1 = new TGaxis(onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL,yMinMP,onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL,yMaxMP,yMinMP,yMaxMP,AxisDivisions,"-US");
		   axisMPY1->SetTickSize(ticksize);
		   if(iPanel==nPanels_MPnew) axisMPY1->SetTickSize(ticksize/(1-lowestBottomMargin));
		   axisMPY1->Draw("same");

		   TGaxis *axisMPY2 = new TGaxis(onia::cpmRange[cpmBinMax],yMinMP,onia::cpmRange[cpmBinMax],yMaxMP,yMinMP,yMaxMP,AxisDivisions,"+US");
		   axisMPY2->SetTickSize(ticksize);
		   if(iPanel==nPanels_MPnew) axisMPY2->SetTickSize(ticksize/(1-lowestBottomMargin));
		   axisMPY2->Draw("same");


		   double deltaTrickAxisMax_MPnew;
		   deltaTrickAxisMax_MPnew=-0.001;
//		   if(iStateMP==3) deltaTrickAxisMax_MPnew=+0.001;

		   TGaxis *axisM3S1 = new TGaxis(onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL,yMinMP,onia::cpmRange[cpmBinMax],yMinMP,onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL+deltaTrickAxisMin,onia::cpmRange[cpmBinMax]+deltaTrickAxisMax_MPnew,AxisDivisions,"+S");
		   axisM3S1->SetTickSize(ticksize*2);
		   if(iPanel==nPanels_MPnew) axisM3S1->SetLabelSize(LabelSize);
		   if(iPanel<nPanels_MPnew) axisM3S1->SetLabelSize(0);
		   axisM3S1->SetLabelOffset(labelOffsetX);
		   if(iPanel==nPanels_MPnew) axisM3S1->SetTickSize(ticksize/(1-lowestBottomMargin));
		   axisM3S1->Draw("same");

		   TGaxis *axisM3S2 = new TGaxis(onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL,yMaxMP,onia::cpmRange[cpmBinMax],yMaxMP,onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL+deltaTrickAxisMin,onia::cpmRange[cpmBinMax]+deltaTrickAxisMax_MPnew,AxisDivisions,"-US");
		   axisM3S2->SetTickSize(ticksize*2);
		   if(iPanel==nPanels_MPnew) axisM3S2->SetTickSize(ticksize/(1-lowestBottomMargin));
		   axisM3S2->Draw("same");

		   whereTexteInPlotX=XtitlePosition;
		   whereTexteInPlotY=(yMaxMP+yMinMP)/2.-(yMaxMP-yMinMP)*XtitlePositionYshift;

		   char axistitleMPtilde[200];
		   sprintf(axistitleMPtilde,"#tilde{#lambda}");
		   if(iPanel==nPanels_MPnew) YaxistitleLatexSize=YaxistitleLatexSize*(1-lowestBottomMargin);
		   TLatex *MPYtitletext = new TLatex(whereTexteInPlotX,whereTexteInPlotY ,axistitleMPtilde);
		   MPYtitletext->SetTextSize(YaxistitleLatexSize);
		   if(iPanel==nPanels_MPnew) MPYtitletext->SetTextSize(YaxistitleLatexSize*(1-lowestBottomMargin));
		   MPYtitletext->SetTextColor(kBlack);
		   MPYtitletext->PaintLatex(whereTexteInPlotX-DeltaXminOVERALL,whereTexteInPlotY, YtitleAngle, YaxistitleLatexSize, axislabel);
		   MPYtitletext->Draw( "same" );



		   double increaseSize=1.25;
		   double SpecialShiftUpsilonLabel=0.9;
		   double SpecialShiftUpsilonLabelx=-3;

		   char texTexMP[200];
		   sprintf(texTexMP,"#Upsilon(%dS)", iStateMP);
//		   if(ptBin==2) sprintf(texTexMP,"#Upsilon(%dS), 15 < #it{p}_{T} < 35 GeV", iStateMP);
		   TLatex *textMP = new TLatex(5,yMin+(yMax-yMin)*yRapText*SpecialShiftUpsilonLabel,texTexMP);
		   textMP->SetTextSize(textSizeRap*increaseSize);
		   if(iPanel==nPanels_MPnew) textMP->SetTextSize(textSizeRap*(1-lowestBottomMargin)*increaseSize);
		   if(ptBin==1) textMP->Draw( "same" );
		   
		   char texMPpT[200];
		   
		   if(ptBin==1) 
		   {
		   sprintf(texMPpT,"10-15 GeV");
		   TLatex *textpT = new TLatex(35,-.8,texMPpT);
		   textpT->SetTextSize(.088);
		   if(iStateMP==3) textpT->Draw();
		   }
		   
		   if(ptBin==2) 
		   {
		   sprintf(texMPpT,"15-35 GeV");
		   TLatex *textpT = new TLatex(35,.7,texMPpT);
		   textpT->SetTextSize(.07);
		   if(iStateMP==3) textpT->Draw();
		   }
//		   textpT->SetTextSize(textSizeRap*(1-lowestBottomMargin)*increaseSize);
		   
		   
		   
		   

		   char abcdef[200];
		   if(iStateMP==1&&iPanel==1) sprintf(abcdef,"a)");
		   if(iStateMP==1&&iPanel==2) sprintf(abcdef,"b)");
		   if(iStateMP==2&&iPanel==1) sprintf(abcdef,"c)");
		   if(iStateMP==2&&iPanel==2) sprintf(abcdef,"d)");
		   if(iStateMP==3&&iPanel==1) sprintf(abcdef,"e)");
		   if(iStateMP==3&&iPanel==2) sprintf(abcdef,"f)");
		   cout<<abcdef<<endl;
		   TLatex *tex_abcdef = new TLatex(xabcdefText-DeltaXminOVERALL,yMin+(yMax-yMin)*yRapText*0.92,abcdef);
		   tex_abcdef->SetTextSize(textSizeRap);
		   if(iPanel==nPanels_MPnew) tex_abcdef->SetTextSize(textSizeRap*(1-lowestBottomMargin));
//		   tex_abcdef->Draw( "same" );

if(PlotGlobalUnc) {
					
				   
				   
					    TGraphErrors *globunctgraph;
						sprintf(filename,"%s/macros/polFit/Systematics/%s/AverageSyst/GlobalUnc/TGraphResults_%dSUps.root",basedir,GlobalUncLoc,iStateMP);
						TFile *globuncfile = new TFile(filename,"READ");
				        globunctgraph = (TGraphErrors*) globuncfile->Get(GraphName);
						globunctgraph->Draw("2");
						
						
						
						TGraphAsymmErrors *legendPhantom = (TGraphAsymmErrors*) globuncfile->Get("ltilde_CS_rap1_pt1");
				TGraphAsymmErrors *legendPhantom2 = (TGraphAsymmErrors*) globuncfile->Get("ltilde_CS_rap1_pt2");

				   legendPhantom->SetMarkerColor(kOrange);
				   legendPhantom->SetMarkerStyle(21);
				   legendPhantom->SetMarkerSize(10);
				   
				   legendPhantom2->SetMarkerColor(kTeal);
				   legendPhantom2->SetMarkerStyle(21);
				   legendPhantom2->SetMarkerSize(10);
				TLegend *leg = new TLegend(0.,0.75,0.7,0.95);
				leg->SetFillStyle(0);
					leg->SetBorderSize(0);
					leg->SetFillColor(-1);
					leg->SetTextSize(CentralsFontSizeMP*.75);
				   leg->AddEntry(legendPhantom2,"   Global Uncert.","p");

				TLegend *leg2 = new TLegend(0.075,0.75,0.7,0.95);
				leg2->SetFillStyle(0);
					leg2->SetBorderSize(0);
					leg2->SetFillColor(-1);
					leg2->SetTextColor(0);
					leg2->SetTextSize(CentralsFontSizeMP*.75);
				   leg2->AddEntry(legendPhantom,"","p");

				   if(ptBin==1&&iStateMP==2) { leg2->Draw(); leg->Draw();  }
				   
						globuncfile->Close();	
								  
					
					}

			 if(PlotFinalData&&DrawLatexStuff){

				TLine* extreme0MP = new TLine( onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL, 0, onia::cpmRange[cpmBinMax] ,0);
				extreme0MP->SetLineWidth( 1 );
				extreme0MP->SetLineStyle( 2 );
				extreme0MP->SetLineColor( kBlack );
				extreme0MP->Draw( "same" );

				TLine* extreme1MP = new TLine( onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL, 1, onia::cpmRange[cpmBinMax] , 1);
				extreme1MP->SetLineWidth( 1 );
				extreme1MP->SetLineStyle( 2 );
				extreme1MP->SetLineColor( kBlack );
				if(iLam==1||iLam==5||iLam==9) extreme1MP->Draw( "same" );

				TLine* extreme2MP = new TLine( onia::cpmRange[cpmBinMin-1]-DeltaXminOVERALL, -1, onia::cpmRange[cpmBinMax] ,-1);
				extreme2MP->SetLineWidth( 1 );
				extreme2MP->SetLineStyle( 2 );
				extreme2MP->SetLineColor( kBlack );
				if(iLam==1||iLam==5||iLam==9) extreme2MP->Draw( "same" );
//				if(iLam==4||iLam==8||iLam==12) extreme2MP->Draw( "same" );

			 }


			 if(iStateMP==1&&iPanel==1){
			 cout<<"DRAW CMS preliminary Latex"<<endl;
			 char text[200];
			 sprintf(text,"CMS  pp    #sqrt{s} = 7 TeV L = 4.9 fb^{-1}");
			 TLatex *CentralsText1MP = new TLatex((MPlatexX-DeltaXminOVERALL)*.3,MPlatexYmax,text);
			 CentralsText1MP->SetTextSize(CentralsFontSizeMP*.8);
			 CentralsText1MP->Draw( "same" );
			 sprintf(text,"Preliminary");
			 CentralsText1MP = new TLatex((MPlatexX-DeltaXminOVERALL)*.3,(yMax-yMin)*0.75+yMin,text);
			 CentralsText1MP->SetTextSize(CentralsFontSizeMP*.8);
			 if(DrawPreliminary) CentralsText1MP->Draw( "same" );
/*			 sprintf(text,"L = 4.9 fb^{-1}");
			 TLatex *CentralsText2MP = new TLatex(MPlatexX,MPlatexYmax-2*MPlatexDeltaYmax,text);
			 CentralsText2MP->SetTextSize(CentralsFontSizeMP);
			 CentralsText2MP->Draw( "same" );
			 sprintf(text,"pp    #sqrt{s} = 7 TeV");
			 TLatex *CentralsText3MP = new TLatex(MPlatexX,MPlatexYmax-MPlatexDeltaYmax,text);
			 CentralsText3MP->SetTextSize(CentralsFontSizeMP);
		 CentralsText3MP->Draw( "same" );*/

				
				 

			 }
			
					
					
			 if(iStateMP==1&&iPanel==2){
//				   graphMP1_1sig->SetLineColor(OneSigColor);
//				   graphMP1_2sig->SetLineColor(TwoSigColor);
//				   graphMP1_3sig->SetLineColor(ThreeSigColor);


					MPtildeLegend->Draw("same");
			}
			
			if(iStateMP==1&&iPanel==2){
			
					TGraphAsymmErrors *legendPhantom = (TGraphAsymmErrors*) infileMP3_3sig->Get("ltilde_CS_rap1_pt1");

				   legendPhantom->SetMarkerColor(MarkerColorMP[0]);
				   legendPhantom->SetLineColor(MarkerColorMP[0]);
				   legendPhantom->SetMarkerStyle(MarkerStyleMP[1]);
				   legendPhantom->SetMarkerSize(MarkerSizeMP[0]);		  

			
			 if(PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"N_{ch} dependent uncert., 68.3 %% CL");
				   if(!PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"Tot. sys. uncert.");
				   MPframedepLegendError->AddEntry(legendPhantom,MPframedepLegendEntry,"p");
				   if(PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"Tot. uncert., 68.3 %% CL");
				   if(!PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"68.3 %% CL");
//				   MPframedepLegendError->AddEntry(graphMP1_1sig,MPframedepLegendEntry,"f");
				   if(PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"Tot. uncert., 95.5 %% CL");
				   if(!PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"95.5 %% CL");
//				   MPframedepLegendError->AddEntry(graphMP1_2sig,MPframedepLegendEntry,"f");
				   if(PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"Tot. uncert., 99.7 %% CL");
				   if(!PlotAlteredPPDResults) sprintf(MPframedepLegendEntry,"99.7 %% CL");
//				   MPframedepLegendError->AddEntry(graphMP1_3sig,MPframedepLegendEntry,"f");
				 
//				 MPframedepLegendError->Draw("same");
/*
				 double xStatErrorLine=13.06-DeltaXminOVERALL+DeltaXminOVERALL*0.075;
				 double StatErrorLineShift=0.75;
				 double errorLegendY1Tilde=errorLegendY2-(errorLegendY2-errorLegendY1)*(1-lowestBottomMargin)+0.05;
				 double StatErrorLineLength=(errorLegendY2-errorLegendY1Tilde)*0.95;
				 double yMeanStatErrorLine=yMin+(yMax-yMin)*errorLegendY2-(errorLegendY2-errorLegendY1Tilde)*StatErrorLineShift;


					TLine* StatErrorLine = new TLine( xStatErrorLine, yMeanStatErrorLine-StatErrorLineLength/2., xStatErrorLine ,yMeanStatErrorLine+StatErrorLineLength/2.);
					StatErrorLine->SetLineWidth( 1 );
					StatErrorLine->SetLineStyle( 1 );
					StatErrorLine->SetLineColor( kBlack );
					StatErrorLine->Draw( "same" );
*/
			 }

/*			 if(ptBin==2&&iPanel==1){
				   char frameMPtex[200];
				   if(MPframe==1) sprintf(frameMPtex,"CS frame");
				   if(MPframe==2) sprintf(frameMPtex,"HX frame");
				   if(MPframe==3) sprintf(frameMPtex,"PX frame");
					 char textStateFrame[200];
					 sprintf(textStateFrame,"%s", frameMPtex);
				 TLatex *TexStateFrame = new TLatex(MPlatexX,MPlatexYmax,textStateFrame);
				 TexStateFrame->SetTextSize(CentralsFontSizeMP);
				 TexStateFrame->Draw( "same" );
			 }
*/
		}//end iStateMP loop

		MPcanvasTilde->cd();

/*			whereTexteInPlotX=0.488;
			whereTexteInPlotY=startValCoordY-deltaCoordY-1.425*labelOffsetX;
			  TLatex *M3Slabeltext = new TLatex(whereTexteInPlotX,whereTexteInPlotY ,"1");
			  M3Slabeltext->SetTextSize(XaxislabelLatexSize);
			  M3Slabeltext->SetTextColor(kBlack);
			  if(iPanel==nPanels_MPnew) M3Slabeltext->Draw( "same" );
*/
				whereTexteInPlotX=0.36035;
				whereTexteInPlotY=startValCoordY-deltaCoordY-0.006;

				  TLatex *MPXlabeltext = new TLatex(whereTexteInPlotX,whereTexteInPlotY ,"1");
				  MPXlabeltext->SetTextSize(XaxislabelLatexSize/TwoTOthreePanelScaleFactor);
				  MPXlabeltext->SetTextColor(kBlack);
				  if(iPanel==nPanels_MPnew&&!ShiftXminOVERALL) MPXlabeltext->Draw( "same" );

				whereTexteInPlotX+=x_tilde;
				  MPXlabeltext = new TLatex(whereTexteInPlotX,whereTexteInPlotY ,"1");
				  MPXlabeltext->SetTextSize(XaxislabelLatexSize/TwoTOthreePanelScaleFactor);
				  MPXlabeltext->SetTextColor(kBlack);
				  if(iPanel==nPanels_MPnew&&!ShiftXminOVERALL) MPXlabeltext->Draw( "same" );


				if((iLam==4||iLam==8||iLam==12)&&ptBin==2){
					if(mainframe==1) sprintf(filename,"%s/FinalResultsTildeCS.pdf",FigDir);
					if(mainframe==2) sprintf(filename,"%s/FinalResultsTildeHX.pdf",FigDir);
					if(mainframe==3) sprintf(filename,"%s/FinalResultsTildePX.pdf",FigDir);
			if(PlotFinalData) MPcanvasTilde->SaveAs(filename);
			if(mainframe==1) sprintf(filename,"%s/FinalResultsTildeCS.C",FigDir);
			if(mainframe==2) sprintf(filename,"%s/FinalResultsTildeHX.C",FigDir);
			if(mainframe==3) sprintf(filename,"%s/FinalResultsTildePX.C",FigDir);
	if(PlotFinalData) MPcanvasTilde->SaveAs(filename);
			MPcanvasTilde->Close();
			}
	}//end Frame independent plots NEW
	}









		}


		if(iLam==1)  sprintf(filename,"%s/Systematics_CS_lth_rap%d_pt%d.pdf",FigDir,rapBin,ptBin);
		if(iLam==2)  sprintf(filename,"%s/Systematics_CS_lph_rap%d_pt%d.pdf",FigDir,rapBin,ptBin);
		if(iLam==3)  sprintf(filename,"%s/Systematics_CS_ltp_rap%d_pt%d.pdf",FigDir,rapBin,ptBin);
		if(iLam==4)  sprintf(filename,"%s/Systematics_CS_ltilde_rap%d_pt%d.pdf",FigDir,rapBin,ptBin);


		if(iLam==5)  sprintf(filename,"%s/Systematics_HX_lth_rap%d_pt%d.pdf",FigDir,rapBin,ptBin);
		if(iLam==6)  sprintf(filename,"%s/Systematics_HX_lph_rap%d_pt%d.pdf",FigDir,rapBin,ptBin);
		if(iLam==7)  sprintf(filename,"%s/Systematics_HX_ltp_rap%d_pt%d.pdf",FigDir,rapBin,ptBin);
		if(iLam==8) sprintf(filename,"%s/Systematics_HX_ltilde_rap%d_pt%d.pdf",FigDir,rapBin,ptBin);

		if(iLam==9) sprintf(filename,"%s/Systematics_PX_lth_rap%d_pt%d.pdf",FigDir,rapBin,ptBin);
		if(iLam==10) sprintf(filename,"%s/Systematics_PX_lph_rap%d_pt%d.pdf",FigDir,rapBin,ptBin);
		if(iLam==11) sprintf(filename,"%s/Systematics_PX_ltp_rap%d_pt%d.pdf",FigDir,rapBin,ptBin);
		if(iLam==12) sprintf(filename,"%s/Systematics_PX_ltilde_rap%d_pt%d.pdf",FigDir,rapBin,ptBin);

		TCanvas *SystCanvas = new TCanvas("SystCanvas","SystCanvas",1000,800);


		SystCanvas->SetFillColor(kWhite);
		SystCanvas->SetGrid();
		SystCanvas->GetFrame()->SetFillColor(kWhite);
		SystCanvas->GetFrame()->SetBorderSize(0);
		SystCanvas->SetRightMargin(0.05) ;

		double ParametrizedFontSize[8]={0.05,0.05,0.05,0.05,0.04,0.04,0.03,0.03};
		double LegendYmin[8]={0.8,0.75,0.7,0.65,0.65,0.6,0.6,0.6};

		double LegendXmin=0.6;
		if(ExtendLegendInX) LegendXmin=0.25;

		TLegend* plotLegend=new TLegend(LegendXmin,LegendYmin[nSystematics]+.1,0.95,0.9);
		plotLegend->SetFillColor(kWhite);
		plotLegend->SetFillStyle(0);
//		plotLegend->SetTextFont(72);
		plotLegend->SetTextSize(ParametrizedFontSize[nSystematics-1]);
		plotLegend->SetBorderSize(0);
		char legendentry[200];


		double lineWidth=3;
		sprintf(drawGraphStyle,"LX");

		TH1F *SystHisto = new TH1F;
		SystHisto = SystCanvas->DrawFrame(onia::cpmRange[cpmBinMin-1],yMin,onia::cpmRange[cpmBinMax],yMax);
		SystHisto->SetXTitle("N_{ch}");
		SystHisto->SetYTitle(axislabel);
		SystHisto->GetYaxis()->SetTitleOffset(1.5);

		for(int x = 0; x < cpmBinMax; x++)
		 {
		  lmean_errmean_minus[x]=-pow(lmean_errmean_minus[x],2);
		  lmean_errmean[x]=pow(lmean_errmean[x],2);
		 }
		 
		TGraphAsymmErrors *graphStat = new TGraphAsymmErrors(nBinscpm,cpmCentre_,lmean_errmean_minus,cpmCentreErr_low,cpmCentreErr_high,0,lmean_errmean);
		graphStat->SetFillColor(kGreen-2);
		graphStat->SetFillStyle(1001);
		graphStat->SetLineColor(kGreen-2);
		graphStat->SetLineWidth(lineWidth);
		if(!PlotAsymm) graphStat->Draw("2");
		sprintf(legendentry,"Statistical Error");

		if(nSystematics>7){
		TGraphAsymmErrors *graphSyst12345678 = new TGraphAsymmErrors(nBinscpm,cpmCentre_,SystError12345678,cpmCentreErr_low,cpmCentreErr_high,SystError12345678,0);
		graphSyst12345678->SetFillColor(41);
		graphSyst12345678->SetFillStyle(1001);
		graphSyst12345678->SetLineColor(41);
		graphSyst12345678->SetLineWidth(lineWidth);
		if(!PlotAsymm) graphSyst12345678->Draw("2");
		else graphSyst12345678->Draw(drawGraphStyle);
		if(!PlotAsymm) plotLegend->AddEntry(graphSyst12345678,SystID8Title,"f");
		else plotLegend->AddEntry(graphSyst12345678,SystID8Title,"l");
		}
		if(nSystematics>6){
		TGraphAsymmErrors *graphSyst1234567 = new TGraphAsymmErrors(nBinscpm,cpmCentre_,SystError1234567,cpmCentreErr_low,cpmCentreErr_high,SystError1234567,0);
		graphSyst1234567->SetFillColor(46);
		graphSyst1234567->SetFillStyle(1001);
		graphSyst1234567->SetLineColor(46);
		graphSyst1234567->SetLineWidth(lineWidth);
		if(!PlotAsymm) graphSyst1234567->Draw("2");
		else graphSyst1234567->Draw(drawGraphStyle);
		if(!PlotAsymm) plotLegend->AddEntry(graphSyst1234567,SystID7Title,"f");
		else plotLegend->AddEntry(graphSyst1234567,SystID7Title,"l");
		}
		if(nSystematics>5){
		TGraphAsymmErrors *graphSyst123456 = new TGraphAsymmErrors(nBinscpm,cpmCentre_,SystError123456,cpmCentreErr_low,cpmCentreErr_high,SystError123456,0);
		graphSyst123456->SetFillColor(kMagenta);//kYellow
		graphSyst123456->SetFillStyle(1001);
		graphSyst123456->SetLineColor(kMagenta);//kYellow
		graphSyst123456->SetLineWidth(lineWidth);
		if(!PlotAsymm) graphSyst123456->Draw("2");
		else graphSyst123456->Draw(drawGraphStyle);
		if(!PlotAsymm) plotLegend->AddEntry(graphSyst123456,SystID6Title,"f");
		else plotLegend->AddEntry(graphSyst123456,SystID6Title,"l");
		}
		if(nSystematics>4){
		TGraphAsymmErrors *graphSyst12345 = new TGraphAsymmErrors(nBinscpm,cpmCentre_,SystError12345,cpmCentreErr_low,cpmCentreErr_high,SystError12345,0);
		graphSyst12345->SetFillColor(9);//9 //IfLamTildeClosure: kOrange
		if(DeltaTildeplots) graphSyst12345->SetFillColor(kOrange);
		graphSyst12345->SetFillStyle(1001);
		graphSyst12345->SetLineColor(9);//9 //IfLamTildeClosure: kOrange
		if(DeltaTildeplots) graphSyst12345->SetLineColor(kOrange);
		graphSyst12345->SetLineWidth(lineWidth);
		if(!PlotAsymm||DeltaTildeplots) graphSyst12345->Draw("2");
		else graphSyst12345->Draw(drawGraphStyle);
		if(!PlotAsymm&&!DeltaTildeplots) plotLegend->AddEntry(graphSyst12345,SystID5Title,"f");
		if(PlotAsymm&&!DeltaTildeplots) plotLegend->AddEntry(graphSyst12345,SystID5Title,"l");

//		graphSyst12345->Draw("2");//IfLamTildeClosure

		}
		if(nSystematics>3){
		TGraphAsymmErrors *graphSyst1234 = new TGraphAsymmErrors(nBinscpm,cpmCentre_,SystError1234,cpmCentreErr_low,cpmCentreErr_high,SystError1234,0);
		graphSyst1234->SetFillColor(kOrange);
		graphSyst1234->SetFillStyle(1001);
		graphSyst1234->SetLineColor(kOrange);
		graphSyst1234->SetLineWidth(lineWidth);
		if(!PlotAsymm||DeltaTildeplots) graphSyst1234->Draw("2");
		else graphSyst1234->Draw(drawGraphStyle);
		if(!PlotAsymm||DeltaTildeplots) plotLegend->AddEntry(graphSyst1234,SystID4Title,"f");
		else plotLegend->AddEntry(graphSyst1234,SystID4Title,"l");

//		graphSyst1234->Draw("2");//IfLamTildeClosure
//		plotLegend->AddEntry(graphSyst1234,SystID4Title,"f");//IfLamTildeClosure

		}
		if(nSystematics>2){
		TGraphAsymmErrors *graphSyst123 = new TGraphAsymmErrors(nBinscpm,cpmCentre_,SystError123,cpmCentreErr_low,cpmCentreErr_high,SystError123,0);
		graphSyst123->SetFillColor(8);
		graphSyst123->SetFillStyle(1001);
		graphSyst123->SetLineColor(8);
		graphSyst123->SetLineWidth(lineWidth);
		if(!PlotAsymm) graphSyst123->Draw("2"); //if!Pull
		else graphSyst123->Draw(drawGraphStyle); //if!Pull

/*		graphSyst123->SetMarkerStyle(20); //ifPull
		graphSyst123->SetMarkerSize(2); //ifPull
		graphSyst123->SetMarkerColor(kGreen+2); //ifPull
		graphSyst123->Draw("PX"); //ifPull
*/
		if(!PlotAsymm) plotLegend->AddEntry(graphSyst123,SystID3Title,"f");
		else plotLegend->AddEntry(graphSyst123,SystID3Title,"l");
		}
		if(nSystematics>1){
		TGraphAsymmErrors *graphSyst12 = new TGraphAsymmErrors(nBinscpm,cpmCentre_,SystError12,cpmCentreErr_low,cpmCentreErr_high,SystError12,0);
		graphSyst12->SetFillColor(kRed);
		graphSyst12->SetFillStyle(1001);
		graphSyst12->SetLineColor(kRed);
		graphSyst12->SetLineWidth(lineWidth);
		if(!PlotAsymm) graphSyst12->Draw("2"); //if!Pull
		else graphSyst12->Draw(drawGraphStyle); //if!Pull

/*		graphSyst12->SetMarkerStyle(20); //ifPull
		graphSyst12->SetMarkerSize(2); //ifPull
		graphSyst12->SetMarkerColor(kRed); //ifPull
		graphSyst12->Draw("PX"); //ifPull
*/
		if(!PlotAsymm) plotLegend->AddEntry(graphSyst12,SystID2Title,"f");
		else plotLegend->AddEntry(graphSyst12,SystID2Title,"l");
		}
		TGraphAsymmErrors *graphSyst1_ = new TGraphAsymmErrors(nBinscpm,cpmCentre_,SystError1,cpmCentreErr_low,cpmCentreErr_high,SystError1,0);
		graphSyst1_->SetFillColor(kBlue);
		graphSyst1_->SetFillStyle(1001);
		graphSyst1_->SetLineColor(kBlue);
		graphSyst1_->SetLineWidth(lineWidth);
		if(!PlotAsymm) graphSyst1_->Draw("2"); //if!Pull
		else graphSyst1_->Draw(drawGraphStyle); //if!Pull
		if(!PlotAsymm) plotLegend->AddEntry(graphSyst1_,SystID1Title,"f");
		else plotLegend->AddEntry(graphSyst1_,SystID1Title,"l");

/*		graphSyst1_->SetMarkerStyle(20); //ifPull
		graphSyst1_->SetMarkerSize(2); //ifPull
		graphSyst1_->SetMarkerColor(kBlue); //ifPull
		graphSyst1_->Draw("PX"); //ifPull
*/

		if(!PlotAsymm) plotLegend->AddEntry(graphStat,legendentry,"f");



		if(ptBin==1) sprintf(texTex,"10 < #it{p}_{T} < 15 GeV");
		if(ptBin==2) sprintf(texTex,"15 < #it{p}_{T} < 35 GeV");
		 TLatex *Systtext = new TLatex(onia::cpmRange[cpmBinMax]*0.45,yMin+(yMax-yMin)*0.1,texTex);
		 Systtext->SetTextSize(0.035);
		 Systtext->Draw( "same" );

		 if(PlotLegend) plotLegend->Draw();

		 if(BGratioChi2Fits) SystCanvas->SetLogy(true);
		 if(PlotSystematics) SystCanvas->SaveAs(filename);
		 SystCanvas->Close();

		delete SystCanvas;

		}}


		}







		FILE *NumFile;

		bool SaveTables=true;
	    if(SaveTables){


	    char framerap[200];

		char NumFileName[200];
		sprintf(NumFileName,"%s/FinalNumericalResults.tex",FigDir);
		NumFile = fopen(NumFileName,"w");

		fprintf(NumFile, "\n");
		fprintf(NumFile,"\\documentclass{article}\n\\usepackage[applemac]{inputenc}\n\\usepackage{amsmath}\n\\usepackage{textcomp}\n\\pagestyle{plain}\n\\usepackage{graphicx}\n\\usepackage{multicol}\n\\usepackage{geometry}\n\\usepackage{subfigure}\n\\usepackage{booktabs}\n\\usepackage{setspace}\n\n\n\n\\begin{document}\n");

		fprintf(NumFile, "\n\n\n\n");

	    double lth_tab;
	    double ltherr_tab;
	    double ltherr_high_tab;
	    double lph_tab;
	    double lpherr_tab;
	    double lpherr_high_tab;
	    double ltp_tab;
	    double ltperr_tab;
	    double ltperr_high_tab;
	    double ltilde_tab;
	    double ltildeerr_tab;
	    double ltildeerr_high_tab;

	    double ltherrTotal1_tab;
	    double ltherrTotal1_high_tab;
	    double lpherrTotal1_tab;
	    double lpherrTotal1_high_tab;
	    double ltperrTotal1_tab;
	    double ltperrTotal1_high_tab;
	    double ltildeerrTotal1_tab;
	    double ltildeerrTotal1_high_tab;

	    double ltherrTotal2_tab;
	    double ltherrTotal2_high_tab;
	    double lpherrTotal2_tab;
	    double lpherrTotal2_high_tab;
	    double ltperrTotal2_tab;
	    double ltperrTotal2_high_tab;
	    double ltildeerrTotal2_tab;
	    double ltildeerrTotal2_high_tab;

	    double ltherrTotal3_tab;
	    double ltherrTotal3_high_tab;
	    double lpherrTotal3_tab;
	    double lpherrTotal3_high_tab;
	    double ltperrTotal3_tab;
	    double ltperrTotal3_high_tab;
	    double ltildeerrTotal3_tab;
	    double ltildeerrTotal3_high_tab;

	    double cpmmean_tab;

	    	int nTables=2;
		    for(int iTab=1; iTab<nTables+1;iTab++){

				fprintf(NumFile, "\n\n\n\n");

				if(iTab==1){
					fprintf(NumFile, "\\begin{table}[!H]\n\\centering\n \\caption{Results of polarization parameters of the $\\Upsilon(%dS)$ analysis}\n \\begin{tabular}{|c|cccc|}\n\\hline\n");
					fprintf(NumFile, "$p_{T}$ GeV & $\\lambda_{\\vartheta}$ & $\\lambda_{\\varphi}$ &  $\\lambda_{\\vartheta \\varphi}$ & $\\tilde{\\lambda}$ \\\\\n");
				}
				if(iTab==2){
					fprintf(NumFile, "\\begin{table}[!H]\n\\centering\n \\caption{Total systematic uncertainty on the polarization parameters of the $\\Upsilon(%dS)$ analysis}\n \\begin{tabular}{|c|cccc|}\n\\hline\n");
					fprintf(NumFile, "$p_{T}$ GeV & $\\sigma^{syst}(\\lambda_{\\vartheta})$ & $\\sigma^{syst}(\\lambda_{\\varphi})$ &  $\\sigma^{syst}(\\lambda_{\\vartheta \\varphi})$ & $\\sigma^{syst}(\\tilde{\\lambda})$ \\\\\n");
				}

		    for(int iFrame=1; iFrame<4; iFrame++){


			int rap=0;
		    for(int rapBin = 1; rapBin < 2; rapBin++) {
			int pt=0;
		    for(int ptBin = 1; ptBin < 3; ptBin++) {		    

		    	if(iFrame==1) {sprintf(framerap,"\\hline \\multicolumn{5}{|c|}{CS frame, $%1.1f < #it{p}_{T} < %1.1f$}\\\\ \\hline \\rule{0pt}{4mm}\n",onia::pTRange[0][ptBin-1],onia::pTRange[0][ptBin]); fprintf(NumFile,framerap);}
		    	if(iFrame==2) {sprintf(framerap,"\\hline \\multicolumn{5}{|c|}{HX frame, $%1.1f < #it{p}_{T} < %1.1f$}\\\\ \\hline \\rule{0pt}{4mm}\n",onia::pTRange[0][ptBin-1],onia::pTRange[0][ptBin]); fprintf(NumFile,framerap);}
		    	if(iFrame==3) {sprintf(framerap,"\\hline \\multicolumn{5}{|c|}{PX frame, $%1.1f < #it{p}_{T} < %1.1f$}\\\\ \\hline \\rule{0pt}{4mm}\n",onia::pTRange[0][ptBin-1],onia::pTRange[0][ptBin]); fprintf(NumFile,framerap);}

					int cpm=0;
						for(int cpmBin = cpmBinMin; cpmBin < cpmBinMax+1; cpmBin++) {


/*							syst_table[iLam-1][rapBin-1][pt][0]=SystError[pt];
							syst_table[iLam-1][rapBin-1][pt][1]=TMath::Abs(SystError1[pt]);
							syst_table[iLam-1][rapBin-1][pt][2]=TMath::Abs(SystError2[pt]);
							syst_table[iLam-1][rapBin-1][pt][3]=TMath::Abs(SystError3[pt]);
							syst_table[iLam-1][rapBin-1][pt][4]=TMath::Abs(SystError4[pt]);
							syst_table[iLam-1][rapBin-1][pt][5]=TMath::Abs(SystError5[pt]);
							syst_table[iLam-1][rapBin-1][pt][6]=TMath::Abs(SystError6[pt]);
							syst_table[iLam-1][rapBin-1][pt][7]=TMath::Abs(SystError7[pt]);
							syst_table[iLam-1][rapBin-1][pt][8]=TMath::Abs(SystError8[pt]);
*/
							if(iTab==1){
								if(iFrame==1){
									lth_tab=val_table[1][pt][cpm]			;   ltherr_tab=errLow_table[1][pt][cpm];            ltherr_high_tab=errHigh_table[1][pt][cpm];
									lph_tab=val_table[2][pt][cpm]			;   lpherr_tab=errLow_table[2][pt][cpm];            lpherr_high_tab=errHigh_table[2][pt][cpm];
									ltp_tab=val_table[3][pt][cpm]			;   ltperr_tab=errLow_table[3][pt][cpm];            ltperr_high_tab=errHigh_table[3][pt][cpm];
									ltilde_tab=val_table[6][pt][cpm]		;   ltildeerr_tab=errLow_table[6][pt][cpm];      	ltildeerr_high_tab=errHigh_table[6][pt][cpm];
								}
								if(iFrame==2){
									lth_tab=val_table[7][pt][cpm]			;   ltherr_tab=errLow_table[7][pt][cpm];            ltherr_high_tab=errHigh_table[7][pt][cpm];
									lph_tab=val_table[8][pt][cpm]			;   lpherr_tab=errLow_table[8][pt][cpm];            lpherr_high_tab=errHigh_table[8][pt][cpm];
									ltp_tab=val_table[9][pt][cpm]			;   ltperr_tab=errLow_table[9][pt][cpm];            ltperr_high_tab=errHigh_table[9][pt][cpm];
									ltilde_tab=val_table[12][pt][cpm]		;   ltildeerr_tab=errLow_table[12][pt][cpm];      	ltildeerr_high_tab=errHigh_table[12][pt][cpm];
								}
								if(iFrame==3){
									lth_tab=val_table[13][pt][cpm]			;   ltherr_tab=errLow_table[13][pt][cpm];            ltherr_high_tab=errHigh_table[13][pt][cpm];
									lph_tab=val_table[14][pt][cpm]			;   lpherr_tab=errLow_table[14][pt][cpm];            lpherr_high_tab=errHigh_table[14][pt][cpm];
									ltp_tab=val_table[15][pt][cpm]			;   ltperr_tab=errLow_table[15][pt][cpm];            ltperr_high_tab=errHigh_table[15][pt][cpm];
									ltilde_tab=val_table[18][pt][cpm]		;   ltildeerr_tab=errLow_table[18][pt][cpm];      	ltildeerr_high_tab=errHigh_table[18][pt][cpm];
								}
								fprintf(NumFile, "%1.0f--%1.0f   &  $%1.3f _{-%1.3f}^{+%1.3f} $  & $%1.3f _{-%1.3f}^{+%1.3f}$  &  $%1.3f _{-%1.3f}^{+%1.3f}$ &  $%1.3f _{-%1.3f}^{+%1.3f}$ \\\\\n",onia::pTRange[rapBin][ptBin-1],onia::pTRange[rapBin][ptBin],lth_tab,ltherr_tab,ltherr_high_tab   ,lph_tab,lpherr_tab,lpherr_high_tab   ,ltp_tab,ltperr_tab,ltperr_high_tab   ,ltilde_tab,ltildeerr_tab,ltildeerr_high_tab );
							}

							if(iTab==2){
								if(iFrame==1){
									lth_tab=syst_table[1][pt][cpm][0]		;
									lph_tab=syst_table[2][pt][cpm][0]		;
									ltp_tab=syst_table[3][pt][cpm][0]		;
									ltilde_tab=syst_table[6][pt][cpm][0]	;
								}                                       ;
								if(iFrame==2){                          ;
									lth_tab=syst_table[7][pt][cpm][0]		;
									lph_tab=syst_table[8][pt][cpm][0]		;
									ltp_tab=syst_table[9][pt][cpm][0]		;
									ltilde_tab=syst_table[12][pt][cpm][0]	;
								}                                       ;
								if(iFrame==3){                          ;
									lth_tab=syst_table[13][pt][cpm][0]		;
									lph_tab=syst_table[14][pt][cpm][0]		;
									ltp_tab=syst_table[15][pt][cpm][0]		;
									ltilde_tab=syst_table[18][pt][cpm][0]	;
								}
								fprintf(NumFile, "%1.0f--%1.0f   &  $%1.3f  $  & $%1.3f $  &  $%1.3f $ &  $%1.3f $ \\\\\n",onia::pTRange[rapBin][ptBin-1],onia::pTRange[rapBin][ptBin],lth_tab,lph_tab,ltp_tab,ltilde_tab );
							}


							cpm++;
						}
							pt++;
							}

						rap++;

		    }//end rapBin

		    }//end iFrame



			fprintf(NumFile, "\\hline\n");
			fprintf(NumFile, "\\end{tabular}\n");
			if(iTab==1) fprintf(NumFile, "\\label{tab:results_Ups%d}\n",nState,nState);
			if(iTab==2) fprintf(NumFile, "\\label{tab:syst_Ups%d}\n",nState,nState);
			fprintf(NumFile, "\\end{table}\n");
			fprintf(NumFile, "\n");

		    }//end iTab





			fprintf(NumFile, "\\end{document}");

			fclose(NumFile);



			FILE *SuppFile;


			char SuppFileName[200];
			sprintf(SuppFileName,"%s/SupplementalMaterial.txt",SuppDir);
			if(nState==1) SuppFile = fopen(SuppFileName,"w");
			if(nState>1) SuppFile = fopen(SuppFileName,"a");

			if(nState==1){

				fprintf(SuppFile,"                                                       MEASUREMENT OF THE Y(1S), Y(2S) AND Y(3S) POLARIZATIONS\n                                                                 IN PP COLLISIONS AT SQRT(S) = 7 TeV\n\n                                                                        SUPPLEMENTAL MATERIAL\n\n\n");

				fprintf(SuppFile,"These tables list the results of the angular anisotropy parameters Lambda-Theta, Lambda-Phi, Lambda-Theta-Phi and the frame-invariant parameter Lambda-Tilde, for the Y(nS)\nstates in the Collins-Soper (CS), helicity (HX), and perpendicular helicity (PX) frames, along with their total uncertainties (TU) (68.3%%, 95.5%%, and 99.7%% CL) and statistical\nuncertainties (SU) only (68.3%% CL) for different bins of Y transverse momentum pT and rapidity y.\n\n");

				fprintf(SuppFile,"Column headings are:\n");
				fprintf(SuppFile,"      pT-min: lower border of Y transverse momentum (GeV)\n");
				fprintf(SuppFile,"      pT-max: upper border of Y transverse momentum (GeV)\n");
				fprintf(SuppFile,"     |y|-min: lower border of Y rapidity\n");
				fprintf(SuppFile,"     |y|-max: upper border of Y rapidity\n");
				fprintf(SuppFile,"    Lambda-*: central value of the result\n");
				fprintf(SuppFile,"-T.U.68.3%%CL: negative total uncertainty, 68.3%% CL\n");
				fprintf(SuppFile,"+T.U.68.3%%CL: positive total uncertainty, 68.3%% CL\n");
				fprintf(SuppFile,"-T.U.95.5%%CL: negative total uncertainty, 95.5%% CL\n");
				fprintf(SuppFile,"+T.U.95.5%%CL: positive total uncertainty, 95.5%% CL\n");
				fprintf(SuppFile,"-T.U.99.7%%CL: negative total uncertainty, 99.7%% CL\n");
				fprintf(SuppFile,"+T.U.99.7%%CL: positive total uncertainty, 99.7%% CL\n");
				fprintf(SuppFile,"-S.U.68.3%%CL: negative statistical uncertainty, 68.3%% CL\n");
				fprintf(SuppFile,"+S.U.68.3%%CL: positive statistical uncertainty, 68.3%% CL\n\n\n");

			}

		    double lambda_tab;
		    double lambdaerr_tab;
		    double lambdaerr_high_tab;

		    double lambdaerrTotal1_tab;
		    double lambdaerrTotal1_high_tab;

		    double lambdaerrTotal2_tab;
		    double lambdaerrTotal2_high_tab;

		    double lambdaerrTotal3_tab;
		    double lambdaerrTotal3_high_tab;

		    char TabParChar[200];
		    char TabParCharSpace[200];
		    char TabRapChar[200];
		    char TabFrameChar[200];


		    	for(int iLam=1;iLam<13;iLam++){
		    		
		    		int Tabframe;
		    		if(iLam>0&&iLam<5) Tabframe=1;
		    		if(iLam>4&&iLam<9) Tabframe=2;
		    		if(iLam>8&&iLam<13) Tabframe=3;

			    	if(Tabframe==1) sprintf(TabFrameChar,"CS frame");
			    	if(Tabframe==2) sprintf(TabFrameChar,"HX frame");
			    	if(Tabframe==3) sprintf(TabFrameChar,"PX frame");

			    	if(iLam==1||iLam==5||iLam==9) sprintf(TabParChar,"Lambda-Theta");
			    	if(iLam==2||iLam==6||iLam==10) sprintf(TabParChar,"Lambda-Phi");
			    	if(iLam==3||iLam==7||iLam==11) sprintf(TabParChar,"Lambda-Theta-Phi");
			    	if(iLam==4||iLam==8||iLam==12) sprintf(TabParChar,"Lambda-Tilde");

			    	if(iLam==1||iLam==5||iLam==9)  sprintf(TabParCharSpace,"  Lambda-Theta  ");
			    	if(iLam==2||iLam==6||iLam==10)  sprintf(TabParCharSpace,"   Lambda-Phi   ");
			    	if(iLam==3||iLam==7||iLam==11)  sprintf(TabParCharSpace,"Lambda-Theta-Phi");
			    	if(iLam==4||iLam==8||iLam==12) sprintf(TabParCharSpace,"  Lambda-Tilde  ");

			int rap=0;
		    for(int rapBin = 1; rapBin < 2; rapBin++) {
			int pt=0;
		    for(int ptBin = ptBinMin; ptBin < ptBinMax+1; ptBin++) {
		    	if(ptBin==1) sprintf(TabRapChar,"10 < #it{p}_{T} < 15 GeV ");
		    	if(ptBin==2) sprintf(TabRapChar,"15 < #it{p}_{T} < 35 GeV ");

		    	if(ptBin==1)fprintf(SuppFile,"Table %s, %s, Y(%dS):\n",TabParChar, TabFrameChar,nState);
		    	if(ptBin==1)fprintf(SuppFile,"pT-min   pT-max   |y|-min   |y|-max   %s   -T.U.68.3%%CL    +T.U.68.3%%CL   -T.U.95.5%%CL   +T.U.95.5%%CL   -T.U.99.7%%CL   +T.U.99.7%%CL   -S.U.68.3%%CL   +S.U.68.3%%CL\n",TabParCharSpace);
		    	
/*		    	if(ptBin==2&&nState==3)fprintf(SuppFile,"Table %s, %s, Y(%dS):\n",TabParChar, TabFrameChar,nState);
		    	if(ptBin==2&&nState==3)fprintf(SuppFile,"pT-min   pT-max   |y|-min   |y|-max   %s   -T.U.68.3%%CL    +T.U.68.3%%CL   -T.U.95.5%%CL   +T.U.95.5%%CL   -T.U.99.7%%CL   +T.U.99.7%%CL   -S.U.68.3%%CL   +S.U.68.3%%CL\n",TabParCharSpace);
 */
					int cpm=0;
						for(int cpmBin = cpmBinMin; cpmBin < cpmBinMax+1; cpmBin++) {

								lambda_tab=val_table[iLam][pt][cpm]			;   lambdaerr_tab=errLow_table[iLam][pt][cpm];            lambdaerr_high_tab=errHigh_table[iLam][pt][cpm];          lambdaerrTotal1_high_tab=errHighTotal1_table[iLam][pt][cpm];        lambdaerrTotal1_tab=errLowTotal1_table[iLam][pt][cpm];          lambdaerrTotal2_high_tab=errHighTotal2_table[iLam][pt][cpm];        lambdaerrTotal2_tab=errLowTotal2_table[iLam][pt][cpm];         lambdaerrTotal3_high_tab=errHighTotal3_table[iLam][pt][cpm];        lambdaerrTotal3_tab=errLowTotal3_table[iLam][pt][cpm];

							    cpmmean_tab=cpmmean_table[1][pt][cpm];

								fprintf(SuppFile, "  %1.0f       %1.0f       %1.1f       %1.1f          % 1.3f           -%1.3f          +%1.3f         -%1.3f         +%1.3f         -%1.3f         +%1.3f         -%1.3f         +%1.3f\n",onia::pTRange[rapBin][ptBin-1],onia::pTRange[rapBin][ptBin],onia::rapForPTRange[rapBin-1],onia::rapForPTRange[rapBin],lambda_tab,lambdaerrTotal1_tab, lambdaerrTotal1_high_tab,lambdaerrTotal2_tab, lambdaerrTotal2_high_tab,lambdaerrTotal3_tab, lambdaerrTotal3_high_tab,lambdaerr_tab, lambdaerr_high_tab );

							cpm++;
							
							}
							pt++;

					if(ptBin==2) fprintf(SuppFile,"\n");
					
					}



						rap++;

				    	

		    }//end rapBin

		    }
//		    }//end iFrame


			fclose(SuppFile);

	    }


	return 0;
}