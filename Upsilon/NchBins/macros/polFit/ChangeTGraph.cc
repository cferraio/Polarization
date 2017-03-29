/*
 * AverageSystematics.cc
 *
 *  Created on: Dec 5, 2011
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
  	Char_t *SystID = "Default";
  	Char_t *JobID1 = "Default";

	int ptBinMin=1;
	int ptBinMax=1;
	int cpmBinMin=1;
	int cpmBinMax=1;
	int nState=1;

	  for( int i=0;i < argc; ++i ) {

		    if(std::string(argv[i]).find("JobID1") != std::string::npos) {char* JobID1char = argv[i]; char* JobID1char2 = strtok (JobID1char, "="); JobID1 = JobID1char2; cout<<"JobID1 = "<<JobID1<<endl;}

		    if(std::string(argv[i]).find("SystID") != std::string::npos) {char* SystIDchar = argv[i]; char* SystIDchar2 = strtok (SystIDchar, "="); SystID = SystIDchar2; cout<<"SystID = "<<SystID<<endl;}
		    if(std::string(argv[i]).find("storagedir") != std::string::npos) {char* storagedirchar = argv[i]; char* storagedirchar2 = strtok (storagedirchar, "="); storagedir = storagedirchar2; cout<<"storagedir = "<<storagedir<<endl;}
		    if(std::string(argv[i]).find("basedir") != std::string::npos) {char* basedirchar = argv[i]; char* basedirchar2 = strtok (basedirchar, "="); basedir = basedirchar2; cout<<"basedir = "<<basedir<<endl;}

		    if(std::string(argv[i]).find("ptBinMin") != std::string::npos) {char* ptBinMinchar = argv[i]; char* ptBinMinchar2 = strtok (ptBinMinchar, "p"); ptBinMin = atof(ptBinMinchar2); cout<<"ptBinMin = "<<ptBinMin<<endl;}
		    if(std::string(argv[i]).find("ptBinMax") != std::string::npos) {char* ptBinMaxchar = argv[i]; char* ptBinMaxchar2 = strtok (ptBinMaxchar, "p"); ptBinMax = atof(ptBinMaxchar2); cout<<"ptBinMax = "<<ptBinMax<<endl;}
		    if(std::string(argv[i]).find("cpmBinMin") != std::string::npos) {char* cpmBinMinchar = argv[i]; char* cpmBinMinchar2 = strtok (cpmBinMinchar, "p"); cpmBinMin = atof(cpmBinMinchar2); cout<<"cpmBinMin = "<<cpmBinMin<<endl;}
		    if(std::string(argv[i]).find("cpmBinMax") != std::string::npos) {char* cpmBinMaxchar = argv[i]; char* cpmBinMaxchar2 = strtok (cpmBinMaxchar, "p"); cpmBinMax = atof(cpmBinMaxchar2); cout<<"cpmBinMax = "<<cpmBinMax<<endl;}
		    if(std::string(argv[i]).find("nState") != std::string::npos) {char* nStatechar = argv[i]; char* nStatechar2 = strtok (nStatechar, "p"); nState = atof(nStatechar2); cout<<"nState = "<<nState<<endl;}

	    }

//	int rap1entries[ptBinMax][cpmBinMax];
//	int rap2entries[ptBinMax][cpmBinMax];

  //counts the number of entires in rap 0-0.6 and 0.6-1.2 to use for calculating
  //systematics in integrated rap
/*  for(int ptBin = ptBinMin; ptBin < ptBinMax+1; ptBin ++) {  
	for(int cpmbin = cpmBinMin; cpmbin < cpmBinMax+1; cpmbin ++) {
	 rap1entries[ptBin][cpmBin]==ToyMC::rap1entries[ptBin-1][cpmbin-1];
	 cout<<
	 rap2entries[ptBin][cpmBin]==ToyMC::rap2entries[ptBin-1][cpmbin-1];
	}
   }
*/	    char tmpfilename[200];
		sprintf(tmpfilename,"%s/macros/polFit/Systematics/%s/ChangedTGraph/TGraphResults_%dSUps.root",basedir,SystID,nState);
		gSystem->Unlink(tmpfilename);

		char filename[200];
		sprintf(filename,"%s/TGraphResults_%dSUps.root",JobID1,nState);
		TFile *infile1 = new TFile(filename,"READ");

		char GraphName[200];

//		for(int iFrame = 1; iFrame<2; iFrame++){
		for(int iFrame = 1; iFrame<4; iFrame++){

		TGraphAsymmErrors* graphrap1_lth;
		TGraphAsymmErrors* graphrap1_lph;
		TGraphAsymmErrors* graphrap1_ltp;
		TGraphAsymmErrors* graphrap1_ltilde;
		TGraphAsymmErrors* graphrap2_lth;
		TGraphAsymmErrors* graphrap2_lph;
		TGraphAsymmErrors* graphrap2_ltp;
		TGraphAsymmErrors* graphrap2_ltilde;
		TGraphAsymmErrors* graphrap1_DltildeCS;
		TGraphAsymmErrors* graphrap1_DltildeHX;
		TGraphAsymmErrors* graphrap1_DltildePX;
		TGraphAsymmErrors* graphrap2_DltildeCS;
		TGraphAsymmErrors* graphrap2_DltildeHX;
		TGraphAsymmErrors* graphrap2_DltildePX;
		
		for(int rapBin = 1; rapBin < 2; rapBin++){
		
		////the following two if statements load the rap 1 and rap 2 root plots that have to be averaged
		if(rapBin = 1) {
		if(iFrame==1)  {
			sprintf(GraphName,"lth_CS_rap%d",rapBin);
			graphrap1_lth = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"lph_CS_rap%d",rapBin);
			graphrap1_lph = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltp_CS_rap%d",rapBin);
			graphrap1_ltp = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltilde_CS_rap%d",rapBin);
			graphrap1_ltilde = (TGraphAsymmErrors*) infile1->Get(GraphName);

			sprintf(GraphName,"ltilde_CS_rap%d",rapBin);
			graphrap1_DltildeCS = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltilde_HX_rap%d",rapBin);
			graphrap1_DltildeHX = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltilde_PX_rap%d",rapBin);
			graphrap1_DltildePX = (TGraphAsymmErrors*) infile1->Get(GraphName);
}

		if(iFrame==2)  {
			sprintf(GraphName,"lth_HX_rap%d",rapBin);
			graphrap1_lth = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"lph_HX_rap%d",rapBin);
			graphrap1_lph = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltp_HX_rap%d",rapBin);
			graphrap1_ltp = (TGraphAsymmErrors*) infile1->Get(GraphName);

			sprintf(GraphName,"ltilde_HX_rap%d",rapBin);
			graphrap1_ltilde = (TGraphAsymmErrors*) infile1->Get(GraphName);

			sprintf(GraphName,"ltilde_CS_rap%d",rapBin);
			graphrap1_DltildeCS = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltilde_HX_rap%d",rapBin);
			graphrap1_DltildeHX = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltilde_PX_rap%d",rapBin);
			graphrap1_DltildePX = (TGraphAsymmErrors*) infile1->Get(GraphName);
}

		if(iFrame==3)  {
			sprintf(GraphName,"lth_PX_rap%d",rapBin);
			graphrap1_lth = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"lph_PX_rap%d",rapBin);
			graphrap1_lph = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltp_PX_rap%d",rapBin);
			graphrap1_ltp = (TGraphAsymmErrors*) infile1->Get(GraphName);

			sprintf(GraphName,"ltilde_PX_rap%d",rapBin);
			graphrap1_ltilde = (TGraphAsymmErrors*) infile1->Get(GraphName);

			sprintf(GraphName,"ltilde_CS_rap%d",rapBin);
			graphrap1_DltildeCS = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltilde_HX_rap%d",rapBin);
			graphrap1_DltildeHX = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltilde_PX_rap%d",rapBin);
			graphrap1_DltildePX = (TGraphAsymmErrors*) infile1->Get(GraphName);
}
		}
		
		if(rapBin = 2) {
		if(iFrame==1)  {
			sprintf(GraphName,"lth_CS_rap%d",rapBin);
			graphrap2_lth = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"lph_CS_rap%d",rapBin);
			graphrap2_lph = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltp_CS_rap%d",rapBin);
			graphrap2_ltp = (TGraphAsymmErrors*) infile1->Get(GraphName);

			sprintf(GraphName,"ltilde_CS_rap%d",rapBin);
			graphrap2_ltilde = (TGraphAsymmErrors*) infile1->Get(GraphName);

			sprintf(GraphName,"ltilde_CS_rap%d",rapBin);
			graphrap2_DltildeCS = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltilde_HX_rap%d",rapBin);
			graphrap2_DltildeHX = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltilde_PX_rap%d",rapBin);
			graphrap2_DltildePX = (TGraphAsymmErrors*) infile1->Get(GraphName);
}

		if(iFrame==2)  {
			sprintf(GraphName,"lth_HX_rap%d",rapBin);
			graphrap2_lth = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"lph_HX_rap%d",rapBin);
			graphrap2_lph = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltp_HX_rap%d",rapBin);
			graphrap2_ltp = (TGraphAsymmErrors*) infile1->Get(GraphName);

			sprintf(GraphName,"ltilde_HX_rap%d",rapBin);
			graphrap2_ltilde = (TGraphAsymmErrors*) infile1->Get(GraphName);

			sprintf(GraphName,"ltilde_CS_rap%d",rapBin);
			graphrap2_DltildeCS = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltilde_HX_rap%d",rapBin);
			graphrap2_DltildeHX = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltilde_PX_rap%d",rapBin);
			graphrap2_DltildePX = (TGraphAsymmErrors*) infile1->Get(GraphName);
}

		if(iFrame==3)  {
			sprintf(GraphName,"lth_PX_rap%d",rapBin);
			graphrap2_lth = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"lph_PX_rap%d",rapBin);
			graphrap2_lph = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltp_PX_rap%d",rapBin);
			graphrap2_ltp = (TGraphAsymmErrors*) infile1->Get(GraphName);

			sprintf(GraphName,"ltilde_PX_rap%d",rapBin);
			graphrap2_ltilde = (TGraphAsymmErrors*) infile1->Get(GraphName);

			sprintf(GraphName,"ltilde_CS_rap%d",rapBin);
			graphrap2_DltildeCS = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltilde_HX_rap%d",rapBin);
			graphrap2_DltildeHX = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltilde_PX_rap%d",rapBin);
			graphrap2_DltildePX = (TGraphAsymmErrors*) infile1->Get(GraphName);
}
		}		
		cout<<"TGraphs of all parameters loaded for frame "<<iFrame<<endl;
} // end rap bin that loads everything


		double newlth[2][5];
		double newlph[2][5];	
		double newltp[2][5];
		double newltilde[2][5];		
		int pt=0;
		for(int ptBin = ptBinMin; ptBin < ptBinMax+1; ptBin++) {
//		for(int ptBin = ptBinMin; ptBin < ptBinMax; ptBin++) {
		int cpm=0;
		
		int nBinspT=ptBinMax-ptBinMin+1;
		int nBinscpm=cpmBinMax-cpmBinMin+1;		
		double ptCentre[nBinspT][nBinscpm];
		double ptCentreErr_low[nBinspT][nBinscpm];
		double ptCentreErr_high[nBinspT][nBinscpm];
		
		double cpmCentre[nBinscpm];
		double cpmCentreErr_low[nBinscpm];
		double cpmCentreErr_high[nBinscpm];		

		double lth_lmean[nBinspT][nBinscpm];
		double lth_lmeanErr_low[nBinspT][nBinscpm];
		double lth_lmeanErr_high[nBinspT][nBinscpm];
		double lth_lmeanErr[nBinspT][nBinscpm];

		double lph_lmean[nBinspT][nBinscpm];
		double lph_lmeanErr_low[nBinspT][nBinscpm];
		double lph_lmeanErr_high[nBinspT][nBinscpm];
		double lph_lmeanErr[nBinspT][nBinscpm];

		double ltp_lmean[nBinspT][nBinscpm];
		double ltp_lmeanErr_low[nBinspT][nBinscpm];
		double ltp_lmeanErr_high[nBinspT][nBinscpm];
		double ltp_lmeanErr[nBinspT][nBinscpm];
		
		double ltilde_lmean[nBinspT][nBinscpm];
		double ltilde_lmeanErr_low[nBinspT][nBinscpm];
		double ltilde_lmeanErr_high[nBinspT][nBinscpm];
		double ltilde_lmeanErr[nBinspT][nBinscpm];

		double DltildeCS_lmean[nBinspT][nBinscpm];
		double DltildeHX_lmean[nBinspT][nBinscpm];
		double DltildePX_lmean[nBinspT][nBinscpm];

		cout<<"Values of all parameters loaded for frame "<<iFrame<<endl;

//		for(int iParam=1;iParam<2;iParam++){
		for(int iParam=1;iParam<5;iParam++){		

			if(iParam==1&&iFrame==1) sprintf(GraphName,"lth_CS_rap1_pt%d",ptBin);
			if(iParam==2&&iFrame==1) sprintf(GraphName,"lph_CS_rap1_pt%d",ptBin);
			if(iParam==3&&iFrame==1) sprintf(GraphName,"ltp_CS_rap1_pt%d",ptBin);
			if(iParam==4&&iFrame==1) sprintf(GraphName,"ltilde_CS_rap1_pt%d",ptBin);
			if(iParam==1&&iFrame==2) sprintf(GraphName,"lth_HX_rap1_pt%d",ptBin);
			if(iParam==2&&iFrame==2) sprintf(GraphName,"lph_HX_rap1_pt%d",ptBin);
			if(iParam==3&&iFrame==2) sprintf(GraphName,"ltp_HX_rap1_pt%d",ptBin);
			if(iParam==4&&iFrame==2) sprintf(GraphName,"ltilde_HX_rap1_pt%d",ptBin);
			if(iParam==1&&iFrame==3) sprintf(GraphName,"lth_PX_rap1_pt%d",ptBin);
			if(iParam==2&&iFrame==3) sprintf(GraphName,"lph_PX_rap1_pt%d",ptBin);
			if(iParam==3&&iFrame==3) sprintf(GraphName,"ltp_PX_rap1_pt%d",ptBin);
			if(iParam==4&&iFrame==3) sprintf(GraphName,"ltilde_PX_rap1_pt%d",ptBin);

		double lmean_pt1[nBinscpm];
		double lmean_pt2[nBinscpm];		
		double lmeanErr_low_pt1[nBinscpm];
		double lmeanErr_high_pt1[nBinscpm];
		double lmeanErr_low_pt2[nBinscpm];
		double lmeanErr_high_pt2[nBinscpm];		
		double cpmcenter[nBinscpm];
		double cpmlow[nBinscpm];
		double cpmhigh[nBinscpm];		

		int cpm=0;
		for(int cpmBin = cpmBinMin; cpmBin < cpmBinMax+1; cpmBin++) {		
			if(iFrame==1) {
			double lthrap1 = graphrap1_lth->Eval(ToyMC::ptCentre[ptBin-1][cpmBin-1]);
			double lthrap2 = graphrap2_lth->Eval(ToyMC::ptCentre[ptBin-1][cpmBin-1]);
			newlth[pt][cpm]=lthrap1*ToyMC::rap1entries[pt][cpm]/(ToyMC::rap1entries[pt][cpm]+ToyMC::rap2entries[pt][cpm])+lthrap2*ToyMC::rap1entries[pt][cpm]/(ToyMC::rap1entries[pt][cpm]+ToyMC::rap2entries[pt][cpm]);

		
			double lphrap1 = graphrap1_lph->Eval(ToyMC::ptCentre[ptBin-1][cpmBin-1]);
			double lphrap2 = graphrap2_lph->Eval(ToyMC::ptCentre[ptBin-1][cpmBin-1]);
			newlph[pt][cpm]=lphrap1*ToyMC::rap1entries[pt][cpm]/(ToyMC::rap1entries[pt][cpm]+ToyMC::rap2entries[pt][cpm])+lphrap2*ToyMC::rap2entries[pt][cpm]/(ToyMC::rap1entries[pt][cpm]+ToyMC::rap2entries[pt][cpm]);
		
			double ltprap1 = graphrap1_ltp->Eval(ToyMC::ptCentre[ptBin-1][cpmBin-1]);
			double ltprap2 = graphrap2_ltp->Eval(ToyMC::ptCentre[ptBin-1][cpmBin-1]);
			newltp[pt][cpm]=ltprap1*ToyMC::rap1entries[pt][cpm]/(ToyMC::rap1entries[pt][cpm]+ToyMC::rap2entries[pt][cpm])+ltprap2*ToyMC::rap2entries[pt][cpm]/(ToyMC::rap1entries[pt][cpm]+ToyMC::rap2entries[pt][cpm]);
		
			double ltilderap1 = graphrap1_ltilde->Eval(ToyMC::ptCentre[ptBin-1][cpmBin-1]);
			double ltilderap2 = graphrap2_ltilde->Eval(ToyMC::ptCentre[ptBin-1][cpmBin-1]);
			newltilde[pt][cpm]=ltilderap1*ToyMC::rap1entries[pt][cpm]/(ToyMC::rap1entries[pt][cpm]+ToyMC::rap2entries[pt][cpm])+ltilderap2*ToyMC::rap2entries[pt][cpm]/(ToyMC::rap1entries[pt][cpm]+ToyMC::rap2entries[pt][cpm]);
			}
			if(iFrame==2) {
			double lthrap1 = graphrap1_lth->Eval(ToyMC::ptCentre[ptBin-1][cpmBin-1]);
			double lthrap2 = graphrap2_lth->Eval(ToyMC::ptCentre[ptBin-1][cpmBin-1]);
			newlth[pt][cpm]=lthrap1*ToyMC::rap1entries[pt][cpm]/(ToyMC::rap1entries[pt][cpm]+ToyMC::rap2entries[pt][cpm])+lthrap2*ToyMC::rap2entries[pt][cpm]/(ToyMC::rap1entries[pt][cpm]+ToyMC::rap2entries[pt][cpm]);
		
			double lphrap1 = graphrap1_lph->Eval(ToyMC::ptCentre[ptBin-1][cpmBin-1]);
			double lphrap2 = graphrap2_lph->Eval(ToyMC::ptCentre[ptBin-1][cpmBin-1]);
			newlph[pt][cpm]=lphrap1*ToyMC::rap1entries[pt][cpm]/(ToyMC::rap1entries[pt][cpm]+ToyMC::rap2entries[pt][cpm])+lphrap2*ToyMC::rap2entries[pt][cpm]/(ToyMC::rap1entries[pt][cpm]+ToyMC::rap2entries[pt][cpm]);
		
			double ltprap1 = graphrap1_ltp->Eval(ToyMC::ptCentre[ptBin-1][cpmBin-1]);
			double ltprap2 = graphrap2_ltp->Eval(ToyMC::ptCentre[ptBin-1][cpmBin-1]);
			newltp[pt][cpm]=ltprap1*ToyMC::rap1entries[pt][cpm]/(ToyMC::rap1entries[pt][cpm]+ToyMC::rap2entries[pt][cpm])+ltprap2*ToyMC::rap2entries[pt][cpm]/(ToyMC::rap1entries[pt][cpm]+ToyMC::rap2entries[pt][cpm]);
		
			double ltilderap1 = graphrap1_ltilde->Eval(ToyMC::ptCentre[ptBin-1][cpmBin-1]);
			double ltilderap2 = graphrap2_ltilde->Eval(ToyMC::ptCentre[ptBin-1][cpmBin-1]);
			newltilde[pt][cpm]=ltilderap1*ToyMC::rap1entries[pt][cpm]/(ToyMC::rap1entries[pt][cpm]+ToyMC::rap2entries[pt][cpm])+ltilderap2*ToyMC::rap2entries[pt][cpm]/(ToyMC::rap1entries[pt][cpm]+ToyMC::rap2entries[pt][cpm]);
			}
			if(iFrame==3) {
			double lthrap1 = graphrap1_lth->Eval(ToyMC::ptCentre[ptBin-1][cpmBin-1]);
			double lthrap2 = graphrap2_lth->Eval(ToyMC::ptCentre[ptBin-1][cpmBin-1]);
			newlth[pt][cpm]=lthrap1*ToyMC::rap1entries[pt][cpm]/(ToyMC::rap1entries[pt][cpm]+ToyMC::rap2entries[pt][cpm])+lthrap2*ToyMC::rap2entries[pt][cpm]/(ToyMC::rap1entries[pt][cpm]+ToyMC::rap2entries[pt][cpm]);
		
			double lphrap1 = graphrap1_lph->Eval(ToyMC::ptCentre[ptBin-1][cpmBin-1]);
			double lphrap2 = graphrap2_lph->Eval(ToyMC::ptCentre[ptBin-1][cpmBin-1]);
			newlph[pt][cpm]=lphrap1*ToyMC::rap1entries[pt][cpm]/(ToyMC::rap1entries[pt][cpm]+ToyMC::rap2entries[pt][cpm])+lphrap2*ToyMC::rap2entries[pt][cpm]/(ToyMC::rap1entries[pt][cpm]+ToyMC::rap2entries[pt][cpm]);
		
			double ltprap1 = graphrap1_ltp->Eval(ToyMC::ptCentre[ptBin-1][cpmBin-1]);
			double ltprap2 = graphrap2_ltp->Eval(ToyMC::ptCentre[ptBin-1][cpmBin-1]);
			newltp[pt][cpm]=ltprap1*ToyMC::rap1entries[pt][cpm]/(ToyMC::rap1entries[pt][cpm]+ToyMC::rap2entries[pt][cpm])+ltprap2*ToyMC::rap2entries[pt][cpm]/(ToyMC::rap1entries[pt][cpm]+ToyMC::rap2entries[pt][cpm]);
		
			double ltilderap1 = graphrap1_ltilde->Eval(ToyMC::ptCentre[ptBin-1][cpmBin-1]);
			double ltilderap2 = graphrap2_ltilde->Eval(ToyMC::ptCentre[ptBin-1][cpmBin-1]);
			newltilde[pt][cpm]=ltilderap1*ToyMC::rap1entries[pt][cpm]/(ToyMC::rap1entries[pt][cpm]+ToyMC::rap2entries[pt][cpm])+ltilderap2*ToyMC::rap2entries[pt][cpm]/(ToyMC::rap1entries[pt][cpm]+ToyMC::rap2entries[pt][cpm]);
			}
			
			if(iParam==1){
			if(ptBin==1){
			lmean_pt1[cpm]=newlth[0][cpm];
			lmeanErr_low_pt1[cpm]=0.;
			lmeanErr_high_pt1[cpm]=0.;
			}
			if(ptBin==2){
			lmean_pt2[cpm]=newlth[1][cpm];
			lmeanErr_low_pt2[cpm]=0.;
			lmeanErr_high_pt2[cpm]=0.;
			}
			}

			if(iParam==2){
			if(ptBin==1){
			lmean_pt1[cpm]=newlph[0][cpm];
			lmeanErr_low_pt1[cpm]=0.;
			lmeanErr_high_pt1[cpm]=0.;
			}
			if(ptBin==2){
			lmean_pt2[cpm]=newlph[1][cpm];
			lmeanErr_low_pt2[cpm]=0.;
			lmeanErr_high_pt2[cpm]=0.;
			}
			}
			
			if(iParam==3){
			if(ptBin==1){
			lmean_pt1[cpm]=newltp[0][cpm];
			lmeanErr_low_pt1[cpm]=0.;
			lmeanErr_high_pt1[cpm]=0.;
			}
			if(ptBin==2){
			lmean_pt2[cpm]=newltp[1][cpm];
			lmeanErr_low_pt2[cpm]=0.;
			lmeanErr_high_pt2[cpm]=0.;
			}
			}
			
			if(iParam==4){
			if(ptBin==1){
			lmean_pt1[cpm]=newltilde[0][cpm];
			lmeanErr_low_pt1[cpm]=0.;
			lmeanErr_high_pt1[cpm]=0.;
			}
			if(ptBin==2){
			lmean_pt2[cpm]=newltilde[1][cpm];
			lmeanErr_low_pt2[cpm]=0.;
			lmeanErr_high_pt2[cpm]=0.;	
			}
			}

		cpmcenter[cpm] = ToyMC::cpmCentre[pt][cpm];
//		cpmlow[cpm] = onia::cpmRange[cpm];
//		cout<<cpmlow[cpm]<<" is low"<<endl;
//		cpmhigh[cpm] = onia::cpmRange[cpm+1];
//		cout<<cpmhigh[cpm]<<" is high"<<endl;
		cpmlow[cpm]=TMath::Abs(ToyMC::cpmCentre[ptBin-1][cpmBin-1]-onia::cpmRange[cpmBin-1]);
		cpmhigh[cpm]=TMath::Abs(ToyMC::cpmCentre[ptBin-1][cpmBin-1]-onia::cpmRange[cpmBin]);


		cpm++;
		}		

		cout<<"Values of parameter "<<iParam<<" changed for frame "<<iFrame<<endl;

		if(ptBin==1){
		TGraphAsymmErrors *ChangedGraph = new TGraphAsymmErrors(nBinscpm,cpmcenter,lmean_pt1,cpmlow,cpmhigh,lmeanErr_low_pt1,lmeanErr_high_pt1);
		ChangedGraph->SetMarkerColor(ToyMC::MarkerColor[ptBin]);
	    ChangedGraph->SetLineColor(ToyMC::MarkerColor[ptBin]);
		ChangedGraph->SetMarkerSize(2);
		ChangedGraph->SetName(GraphName);
		

		sprintf(filename,"%s/macros/polFit/Systematics/%s/ChangedTGraph/TGraphResults_%dSUps.root",basedir,SystID,nState);
		TFile *outfile = new TFile(filename,"UPDATE");

		outfile->cd();
		ChangedGraph->Draw("P");
		ChangedGraph->Write();

		outfile->Write();
		outfile->Close();
		delete outfile;
		outfile = NULL; 
		}
		if(ptBin==2){
		TGraphAsymmErrors *ChangedGraph = new TGraphAsymmErrors(nBinscpm,cpmcenter,lmean_pt2,cpmlow,cpmhigh,lmeanErr_low_pt2,lmeanErr_high_pt2);
		ChangedGraph->SetMarkerColor(ToyMC::MarkerColor[ptBin]);
	    ChangedGraph->SetLineColor(ToyMC::MarkerColor[ptBin]);
		ChangedGraph->SetMarkerSize(2);
		ChangedGraph->SetName(GraphName);
		

		sprintf(filename,"%s/macros/polFit/Systematics/%s/ChangedTGraph/TGraphResults_%dSUps.root",basedir,SystID,nState);
		TFile *outfile = new TFile(filename,"UPDATE");

		outfile->cd();
		ChangedGraph->Draw("P");
		ChangedGraph->Write();

		outfile->Write();
		outfile->Close();
		delete outfile;
		outfile = NULL; 
		}		


			 }
		pt++;		 
		}
		cout<<"Values of all parameters changed for frame "<<iFrame<<endl;
//		if(ptBin==1)cout<<"Switching To pt 2"<<endl;
		}
		cout<<"Switching frame"<<endl;
	return 0;
}