/*
 * EvaluateSyst.cc
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



int main(int argc, char** argv) {

	Char_t *storagedir = "Default"; //Storage Directory
	Char_t *basedir = "Default"; //Storage Directory
  	Char_t *JobID1 = "Default";
  	Char_t *JobID2 = "Default";
  	Char_t *SystDir = "Default";

	int cpmBinMin=1;
	int cpmBinMax=1;
	int ptBinMin=1;
	int ptBinMax=1;
	int nState=1;

	bool statErrConsideration=false;

	  for( int i=0;i < argc; ++i ) {

		    if(std::string(argv[i]).find("JobID1") != std::string::npos) {char* JobID1char = argv[i]; char* JobID1char2 = strtok (JobID1char, "="); JobID1 = JobID1char2; cout<<"JobID1 = "<<JobID1<<endl;}
		    if(std::string(argv[i]).find("JobID2") != std::string::npos) {char* JobID2char = argv[i]; char* JobID2char2 = strtok (JobID2char, "="); JobID2 = JobID2char2; cout<<"JobID2 = "<<JobID2<<endl;}
		    if(std::string(argv[i]).find("SystDir") != std::string::npos) {char* SystDirchar = argv[i]; char* SystDirchar2 = strtok (SystDirchar, "="); SystDir = SystDirchar2; cout<<"SystDir = "<<SystDir<<endl;}
		    if(std::string(argv[i]).find("storagedir") != std::string::npos) {char* storagedirchar = argv[i]; char* storagedirchar2 = strtok (storagedirchar, "="); storagedir = storagedirchar2; cout<<"storagedir = "<<storagedir<<endl;}
		    if(std::string(argv[i]).find("basedir") != std::string::npos) {char* basedirchar = argv[i]; char* basedirchar2 = strtok (basedirchar, "="); basedir = basedirchar2; cout<<"basedir = "<<basedir<<endl;}

		    if(std::string(argv[i]).find("ptBinMin") != std::string::npos) {char* ptBinMinchar = argv[i]; char* ptBinMinchar2 = strtok (ptBinMinchar, "p"); ptBinMin = atof(ptBinMinchar2); cout<<"ptBinMin = "<<ptBinMin<<endl;}
		    if(std::string(argv[i]).find("ptBinMax") != std::string::npos) {char* ptBinMaxchar = argv[i]; char* ptBinMaxchar2 = strtok (ptBinMaxchar, "p"); ptBinMax = atof(ptBinMaxchar2); cout<<"ptBinMax = "<<ptBinMax<<endl;}
		    if(std::string(argv[i]).find("cpmBinMin") != std::string::npos) {char* cpmBinMinchar = argv[i]; char* cpmBinMinchar2 = strtok (cpmBinMinchar, "p"); cpmBinMin = atof(cpmBinMinchar2); cout<<"cpmBinMin = "<<cpmBinMin<<endl;}
		    if(std::string(argv[i]).find("cpmBinMax") != std::string::npos) {char* cpmBinMaxchar = argv[i]; char* cpmBinMaxchar2 = strtok (cpmBinMaxchar, "p"); cpmBinMax = atof(cpmBinMaxchar2); cout<<"cpmBinMax = "<<cpmBinMax<<endl;}

		    if(std::string(argv[i]).find("nState") != std::string::npos) {char* nStatechar = argv[i]; char* nStatechar2 = strtok (nStatechar, "p"); nState = atof(nStatechar2); cout<<"nState = "<<nState<<endl;}

		    if(std::string(argv[i]).find("statErrConsideration=true") != std::string::npos) {statErrConsideration=true; cout<<"statErrConsideration"<<endl;}

	    }

	    char tmpfilename[200];
		sprintf(tmpfilename,"%s/macros/polFit/%s/TGraphResults_%dSUps.root",basedir,SystDir,nState);
		gSystem->Unlink(tmpfilename);

		char filename[200];
		sprintf(filename,"%s/%s/TGraphResults_%dSUps.root",storagedir,JobID1,nState);
//		sprintf(filename,"/afs/hephy.at/scratch/k/knuenz/CMSSW_4_2_4_patch2/src/UpsilonPol/macros/polFit/Systematics/TotalSyst/TotalSquaredSystApr27/TGraphResults_%dSUps.root",nState);// ifCentralsWithTotalSyst
		TFile *infile1 = new TFile(filename,"READ");
		cout<<"file name is "<<filename<<endl;
		sprintf(filename,"%s/%s/TGraphResults_%dSUps.root",storagedir,JobID2,nState);
//		sprintf(filename,"/afs/hephy.at/scratch/k/knuenz/CMSSW_4_2_4_patch2/src/UpsilonPol/macros/polFit/Systematics/TotalSyst/Apr25CentralWithStatSystSquared/TGraphResults_2SUps.root");
		TFile *infile2 = new TFile(filename,"READ");

//		sprintf(filename,"%s/MCclosure_CombinedStates_MCtruthFineEta_3Sig/TGraphResults_%dSUps.root",storagedir,nState);//ifAddInforFromThirdTGraph
//		TFile *infile3 = new TFile(filename,"READ");//ifAddInforFromThirdTGraph

		char GraphName[200];

		for(int iLam = 1; iLam<19; iLam++){

		for(int rapBin = 1; rapBin < 2; rapBin++){
		  for(int ptBin = ptBinMin; ptBin < ptBinMax+1; ptBin++){



		sprintf(filename,"%s/macros/polFit/%s/TGraphResults_%dSUps.root",basedir,SystDir,nState);
		
		TFile *outfile = new TFile(filename,"UPDATE");


		if(iLam==1)  sprintf(GraphName,"lth_CS_rap%d_pt%d",rapBin,ptBin);
		if(iLam==2)  sprintf(GraphName,"lph_CS_rap%d_pt%d",rapBin,ptBin);
		if(iLam==3)  sprintf(GraphName,"ltp_CS_rap%d_pt%d",rapBin,ptBin);
		if(iLam==4)  sprintf(GraphName,"lthstar_CS_rap%d_pt%d",rapBin,ptBin);
		if(iLam==5)  sprintf(GraphName,"lphstar_CS_rap%d_pt%d",rapBin,ptBin);
		if(iLam==6)  sprintf(GraphName,"ltilde_CS_rap%d_pt%d",rapBin,ptBin);

		if(iLam==7)  sprintf(GraphName,"lth_HX_rap%d_pt%d",rapBin,ptBin);
		if(iLam==8)  sprintf(GraphName,"lph_HX_rap%d_pt%d",rapBin,ptBin);
		if(iLam==9)  sprintf(GraphName,"ltp_HX_rap%d_pt%d",rapBin,ptBin);
		if(iLam==10) sprintf(GraphName,"lthstar_HX_rap%d_pt%d",rapBin,ptBin);
		if(iLam==11) sprintf(GraphName,"lphstar_HX_rap%d_pt%d",rapBin,ptBin);
		if(iLam==12) sprintf(GraphName,"ltilde_HX_rap%d_pt%d",rapBin,ptBin);

		if(iLam==13) sprintf(GraphName,"lth_PX_rap%d_pt%d",rapBin,ptBin);
		if(iLam==14) sprintf(GraphName,"lph_PX_rap%d_pt%d",rapBin,ptBin);
		if(iLam==15) sprintf(GraphName,"ltp_PX_rap%d_pt%d",rapBin,ptBin);
		if(iLam==16) sprintf(GraphName,"lthstar_PX_rap%d_pt%d",rapBin,ptBin);
		if(iLam==17) sprintf(GraphName,"lphstar_PX_rap%d_pt%d",rapBin,ptBin);
		if(iLam==18) sprintf(GraphName,"ltilde_PX_rap%d_pt%d",rapBin,ptBin);

		int nFrame=0;

		if(iLam>0&&iLam<7) nFrame=1;
		if(iLam>6&&iLam<13) nFrame=2;
		if(iLam>12&&iLam<19) nFrame=3;

		TGraphAsymmErrors* graph1 = (TGraphAsymmErrors*) infile1->Get(GraphName);
		TGraphAsymmErrors* graph2 = (TGraphAsymmErrors*) infile2->Get(GraphName);

//		TGraphAsymmErrors* graph3 = (TGraphAsymmErrors*) infile3->Get(GraphName);//ifAddInforFromThirdTGraph


		int nBinscpm=cpmBinMax-cpmBinMin+1;
		double cpmCentre_[nBinscpm];
		double cpmCentreErr_low[nBinscpm];
		double cpmCentreErr_high[nBinscpm];
		double lmean[nBinscpm];

		double cpmCentre1_[nBinscpm];
		double cpmCentreErr1_low[nBinscpm];
		double cpmCentreErr1_high[nBinscpm];
		double cpmCentre2_[nBinscpm];
		double cpmCentreErr2_low[nBinscpm];
		double cpmCentreErr2_high[nBinscpm];

		double cpmCentre3_[nBinscpm];
		double lmean3[nBinscpm];

		double lmean1[nBinscpm];
		double lmean2[nBinscpm];

		double lmeanErr1_low[nBinscpm];
		double lmeanErr1_high[nBinscpm];
		double lmeanErr2_low[nBinscpm];
		double lmeanErr2_high[nBinscpm];

		double lmeanErr_change_low[nBinscpm];
		double lmeanErr_change_high[nBinscpm];
		double lmeanErr_change[nBinscpm];



		int cpm=0;
		for(int cpmBin = cpmBinMin; cpmBin < cpmBinMax+1; cpmBin++) {
			graph1->GetPoint(cpm,cpmCentre1_[cpm],lmean1[cpm]);
			cpmCentreErr1_high[cpm]=graph1->GetErrorXhigh(cpm);
			cpmCentreErr1_low[cpm]=graph1->GetErrorXlow(cpm);
			graph2->GetPoint(cpm,cpmCentre2_[cpm],lmean2[cpm]);
			cpmCentreErr2_high[cpm]=graph2->GetErrorXhigh(cpm);
			cpmCentreErr2_low[cpm]=graph2->GetErrorXlow(cpm);

			if(lmean1[cpm]>998) lmean1[cpm]=9999;
			cpmCentre_[cpm]=(cpmCentre1_[cpm]+cpmCentre1_[cpm])/2.;
			cpmCentreErr_low[cpm]=(cpmCentreErr1_low[cpm]+cpmCentreErr2_low[cpm])/2.;
			cpmCentreErr_high[cpm]=(cpmCentreErr1_high[cpm]+cpmCentreErr2_high[cpm])/2.;
			lmeanErr1_high[cpm]=graph1->GetErrorYhigh(cpm);
			lmeanErr1_low[cpm]=graph1->GetErrorYlow(cpm);
			lmeanErr2_high[cpm]=graph2->GetErrorYhigh(cpm);
			lmeanErr2_low[cpm]=graph2->GetErrorYlow(cpm);
			lmean[cpm]=lmean1[cpm]-lmean2[cpm];

			lmeanErr_change_high[cpm]=TMath::Sqrt(lmeanErr2_high[cpm]*lmeanErr2_high[cpm]+lmean1[cpm]*lmean1[cpm]);
			lmeanErr_change_low[cpm]=TMath::Sqrt(lmeanErr2_low[cpm]*lmeanErr2_low[cpm]+lmean1[cpm]*lmean1[cpm]);
			lmeanErr_change[cpm]=(lmeanErr_change_low[cpm]+lmeanErr_change_high[cpm])/2.;



//			lmean[pt]=lmean1[pt]+lmean2[pt];//ifCorrectCentralResultsForBias

//BiasCorrectionError

			lmeanErr_change[cpm]=999;
//			lmeanErr_change[pt]=TMath::Sqrt(TMath::Power((lmeanErr1_high[pt]+lmeanErr1_low[pt])/2.,2.)+TMath::Power((lmeanErr2_high[pt]+lmeanErr2_low[pt])/2.,2.));
			if((lmeanErr1_high[cpm]+lmeanErr1_low[cpm])/2.>(lmeanErr2_high[cpm]+lmeanErr2_low[cpm])/2.) lmeanErr_change[cpm]=TMath::Sqrt(TMath::Power((lmeanErr1_high[cpm]+lmeanErr1_low[cpm])/2.,2.)-TMath::Power((lmeanErr2_high[cpm]+lmeanErr2_low[cpm])/2.,2.));
			if((lmeanErr1_high[cpm]+lmeanErr1_low[cpm])/2.<(lmeanErr2_high[cpm]+lmeanErr2_low[cpm])/2.) lmeanErr_change[cpm]=TMath::Sqrt(TMath::Power((lmeanErr2_high[cpm]+lmeanErr2_low[cpm])/2.,2.)-TMath::Power((lmeanErr1_high[cpm]+lmeanErr1_low[cpm])/2.,2.));

			double fracErrHigh2=lmeanErr2_high[cpm]/(lmeanErr2_high[cpm]+lmeanErr2_low[cpm]);


//	unc		lmeanErr1_high[pt]=fracErrHigh2*(lmeanErr1_high[pt]+lmeanErr1_low[pt]);
//	unc		lmeanErr1_low[pt]=(1-fracErrHigh2)*(lmeanErr1_high[pt]+lmeanErr1_low[pt]);


//			graph3->GetPoint(pt,ptCentre3_[pt],lmean3[pt]);//ifAddInforFromThirdTGraph
//			lmean[pt]=lmean1[pt]-lmean2[pt]+lmean3[pt];

/*			if(ptBin<6){
				lmean[pt]=lmean1[pt]-lmean3[pt];//ifAddInforFromThirdTGraph
			}
*/
//			lmean[cpm]=lmean[cpm]/TMath::Sqrt(12.);//ifSQRT12

			double SigComp=1;

			double lmeanBuff=lmean[cpm];
			if(statErrConsideration){
				cout<<"StatErrCheck"<<endl;
				bool getSqrt=true;
				if(lmeanBuff*lmeanBuff-SigComp*SigComp*lmeanErr2_low[cpm]*lmeanErr2_low[cpm]-SigComp*SigComp*lmeanErr1_high[cpm]*lmeanErr1_high[cpm]<0 && lmeanBuff < 0) {lmean[cpm]=0;getSqrt=false;}
				if(lmeanBuff*lmeanBuff-SigComp*SigComp*lmeanErr1_low[cpm]*lmeanErr1_low[cpm]-SigComp*SigComp*lmeanErr2_high[cpm]*lmeanErr2_high[cpm]<0 && lmeanBuff > 0) {lmean[cpm]=0;getSqrt=false;}
				if(lmeanBuff==0) {lmean[cpm]=0;getSqrt=false;}
				if(lmeanBuff < 0 && getSqrt) lmean[cpm]=-TMath::Sqrt(lmeanBuff*lmeanBuff-SigComp*SigComp*lmeanErr2_low[cpm]*lmeanErr2_low[cpm]-SigComp*SigComp*lmeanErr1_high[cpm]*lmeanErr1_high[cpm]);
				if(lmeanBuff > 0 && getSqrt) lmean[cpm]=TMath::Sqrt(lmeanBuff*lmeanBuff-SigComp*SigComp*lmeanErr1_low[cpm]*lmeanErr1_low[cpm]-SigComp*SigComp*lmeanErr2_high[cpm]*lmeanErr2_high[cpm]);
			}

//			if(lmeanBuff < 0) lmean[pt]=lmeanBuff/TMath::Sqrt(lmeanErr2_low[pt]*lmeanErr2_low[pt]+lmeanErr1_high[pt]*lmeanErr1_high[pt]); //ifPull
//			else lmean[pt]=lmeanBuff/TMath::Sqrt(lmeanErr1_low[pt]*lmeanErr1_low[pt]+lmeanErr2_high[pt]*lmeanErr2_high[pt]); //ifPull

		cpm++;
		}




		TGraphAsymmErrors *graphSyst = new TGraphAsymmErrors(nBinscpm,cpmCentre_,lmean,cpmCentreErr_low,cpmCentreErr_high,0,0);
//		TGraphAsymmErrors *graphSyst = new TGraphAsymmErrors(nBinspT,ptCentre2_,lmean2,ptCentreErr2_low,ptCentreErr2_high,lmean1,lmean1);// ifCentralsWithTotalSyst
//		TGraphAsymmErrors *graphSyst = new TGraphAsymmErrors(nBinspT,ptCentre_,lmean,ptCentreErr_low,ptCentreErr_high,lmeanErr_change,lmeanErr_change);// ifCalculateBiasCorrection
//		TGraphAsymmErrors *graphSyst = new TGraphAsymmErrors(nBinspT,ptCentre_,lmean,ptCentreErr_low,ptCentreErr_high,lmeanErr1_low,lmeanErr1_high);// ifCorrectCentralResultsForBias
//		TGraphAsymmErrors *graphSyst = new TGraphAsymmErrors(nBinscpm,cpmCentre_,lmean2,cpmCentreErr_low,cpmCentreErr_high,lmeanErr1_low,lmeanErr1_high);// if 'take central value from JobID2, take error from JobID1'
//		TGraphAsymmErrors *graphSyst = new TGraphAsymmErrors(nBinspT,ptCentre_,lmean,ptCentreErr_low,ptCentreErr_high,lmeanErr1_low,lmeanErr1_high);// ifAddInforFromThirdTGraph
		graphSyst->SetMarkerColor(ToyMC::MarkerColor[nFrame]);
		graphSyst->SetLineColor(ToyMC::MarkerColor[nFrame]);
		graphSyst->SetMarkerStyle(ToyMC::MarkerStyle[nState][ptBin]);
		graphSyst->SetMarkerSize(ToyMC::MarkerSize[nState][ptBin]);
		graphSyst->SetName(GraphName);


		outfile->cd();
		graphSyst->Draw("p");
		graphSyst->Write();

		outfile->Write();
		outfile->Close();
		delete outfile;
		outfile = NULL;


		}}


		}





	return 0;
}
