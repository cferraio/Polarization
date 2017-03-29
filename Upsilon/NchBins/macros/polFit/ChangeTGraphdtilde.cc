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

	int cpmBinMin=1;
	int cpmBinMax=1;
	int ptBinMin=1;
	int ptBinMax=1;
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

	    char tmpfilename[200];
		sprintf(tmpfilename,"%s/macros/polFit/Systematics/%s/ChangedTGraph/TGraphResults_%dSUps.root",basedir,SystID,nState);
		gSystem->Unlink(tmpfilename);

		char filename[200];
		sprintf(filename,"%s/TGraphResults_%dSUps.root",JobID1,nState);
		TFile *infile1 = new TFile(filename,"READ");

		char GraphName[200];

		for(int iFrame = 1; iFrame<4; iFrame++){

		for(int ptBin = 1; ptBin < 3; ptBin++){



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
			sprintf(GraphName,"lth_CS_rap1_pt%d",ptBin);
			graph_lth = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"lph_CS_rap1_pt%d",ptBin);
			graph_lph = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltp_CS_rap1_pt%d",ptBin);
			graph_ltp = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"lthstar_CS_rap1_pt%d",ptBin);
			graph_lthstar = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"lphstar_CS_rap1_pt%d",ptBin);
			graph_lphstar = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltilde_CS_rap1_pt%d",ptBin);
			graph_ltilde = (TGraphAsymmErrors*) infile1->Get(GraphName);

			sprintf(GraphName,"ltilde_CS_rap1_pt%d",ptBin);
			graph_DltildeCS = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltilde_HX_rap1_pt%d",ptBin);
			graph_DltildeHX = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltilde_PX_rap1_pt%d",ptBin);
			graph_DltildePX = (TGraphAsymmErrors*) infile1->Get(GraphName);
}

		if(iFrame==2)  {
			sprintf(GraphName,"lth_HX_rap1_pt%d",ptBin);
			graph_lth = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"lph_HX_rap1_pt%d",ptBin);
			graph_lph = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltp_HX_rap1_pt%d",ptBin);
			graph_ltp = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"lthstar_HX_rap1_pt%d",ptBin);
			graph_lthstar = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"lphstar_HX_rap1_pt%d",ptBin);
			graph_lphstar = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltilde_HX_rap1_pt%d",ptBin);
			graph_ltilde = (TGraphAsymmErrors*) infile1->Get(GraphName);

			sprintf(GraphName,"ltilde_CS_rap1_pt%d",ptBin);
			graph_DltildeCS = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltilde_HX_rap1_pt%d",ptBin);
			graph_DltildeHX = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltilde_PX_rap1_pt%d",ptBin);
			graph_DltildePX = (TGraphAsymmErrors*) infile1->Get(GraphName);
}

		if(iFrame==3)  {
			sprintf(GraphName,"lth_PX_rap1_pt%d",ptBin);
			graph_lth = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"lph_PX_rap1_pt%d",ptBin);
			graph_lph = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltp_PX_rap1_pt%d",ptBin);
			graph_ltp = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"lthstar_PX_rap1_pt%d",ptBin);
			graph_lthstar = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"lphstar_PX_rap1_pt%d",ptBin);
			graph_lphstar = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltilde_PX_rap1_pt%d",ptBin);
			graph_ltilde = (TGraphAsymmErrors*) infile1->Get(GraphName);

			sprintf(GraphName,"ltilde_CS_rap1_pt%d",ptBin);
			graph_DltildeCS = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltilde_HX_rap1_pt%d",ptBin);
			graph_DltildeHX = (TGraphAsymmErrors*) infile1->Get(GraphName);
			sprintf(GraphName,"ltilde_PX_rap1_pt%d",ptBin);
			graph_DltildePX = (TGraphAsymmErrors*) infile1->Get(GraphName);
}

		cout<<"TGraphs of all parameters loaded for frame "<<iFrame<<endl;



/*		//Ups1:
		double lamtildeCS[2][10]={
		{-0.268025, -0.423266, -0.804402, -0.775923, -0.374039, -0.261726, -0.407957, -0.244021, -0.210692, 0.010428},{ -0.72549, -0.232061, -0.422995, -0.507062, -0.641677, -0.285836, -0.233993, -0.112918, -0.0927753, 0.11018}
		};
		double lamtildeHX[2][10]={
		{0.324909, 0.309998, -0.645745, -0.628765, -0.303808, -0.259237, -0.250806, -0.181788, -0.150838, 0.0462099},{-0.693424, -0.114897, -0.365809, -0.470233, -0.593041, -0.262521, -0.192101, -0.114675, -0.0880647, 0.128067}
		};
		double lamtildePX[2][10]={
		{ 0.253969, -0.204504, -0.68701, -0.696149, -0.299076, -0.245953, -0.396063, -0.23093, -0.202291, 0.03004},{-0.684952, -0.209087, -0.400518, -0.484155, -0.612468, -0.276295, -0.227099, -0.104696, -0.0858445, 0.129378}
		};
*/


		int nBinscpm=cpmBinMax-cpmBinMin+1;
		double cpmCentre[nBinscpm];
		double cpmCentreErr_low[nBinscpm];
		double cpmCentreErr_high[nBinscpm];

		double lth_lmean[nBinscpm];
		double lth_lmeanErr_low[nBinscpm];
		double lth_lmeanErr_high[nBinscpm];
		double lth_lmeanErr[nBinscpm];

		double lph_lmean[nBinscpm];
		double lph_lmeanErr_low[nBinscpm];
		double lph_lmeanErr_high[nBinscpm];
		double lph_lmeanErr[nBinscpm];

		double ltp_lmean[nBinscpm];
		double ltp_lmeanErr_low[nBinscpm];
		double ltp_lmeanErr_high[nBinscpm];
		double ltp_lmeanErr[nBinscpm];

		double lthstar_lmean[nBinscpm];
		double lthstar_lmeanErr_low[nBinscpm];
		double lthstar_lmeanErr_high[nBinscpm];
		double lthstar_lmeanErr[nBinscpm];

		double lphstar_lmean[nBinscpm];
		double lphstar_lmeanErr_low[nBinscpm];
		double lphstar_lmeanErr_high[nBinscpm];
		double lphstar_lmeanErr[nBinscpm];

		double ltilde_lmean[nBinscpm];
		double ltilde_lmeanErr_low[nBinscpm];
		double ltilde_lmeanErr_high[nBinscpm];
		double ltilde_lmeanErr[nBinscpm];

		double DltildeCS_lmean[nBinscpm];
		double DltildeHX_lmean[nBinscpm];
		double DltildePX_lmean[nBinscpm];

		int cpm=0;
		for(int cpmBin = cpmBinMin; cpmBin < cpmBinMax+1; cpmBin++) {

			graph_lth->GetPoint(cpm,cpmCentre[cpm],lth_lmean[cpm]);
			cpmCentreErr_high[cpm]=graph_lth->GetErrorXhigh(cpm);
			cpmCentreErr_low[cpm]=graph_lth->GetErrorXlow(cpm);

			graph_lth->GetPoint(cpm,cpmCentre[cpm],lth_lmean[cpm]);
			lth_lmeanErr_high[cpm]=graph_lth->GetErrorYhigh(cpm);
			lth_lmeanErr_low[cpm]=graph_lth->GetErrorYlow(cpm);
			lth_lmeanErr[cpm]=(lth_lmeanErr_high[cpm]+lth_lmeanErr_low[cpm])/2.;

			graph_lph->GetPoint(cpm,cpmCentre[cpm],lph_lmean[cpm]);
			lph_lmeanErr_high[cpm]=graph_lph->GetErrorYhigh(cpm);
			lph_lmeanErr_low[cpm]=graph_lph->GetErrorYlow(cpm);
			lph_lmeanErr[cpm]=(lph_lmeanErr_high[cpm]+lph_lmeanErr_low[cpm])/2.;

			graph_ltp->GetPoint(cpm,cpmCentre[cpm],ltp_lmean[cpm]);
			ltp_lmeanErr_high[cpm]=graph_ltp->GetErrorYhigh(cpm);
			ltp_lmeanErr_low[cpm]=graph_ltp->GetErrorYlow(cpm);
			ltp_lmeanErr[cpm]=(ltp_lmeanErr_high[cpm]+ltp_lmeanErr_low[cpm])/2.;

			graph_lthstar->GetPoint(cpm,cpmCentre[cpm],lthstar_lmean[cpm]);
			lthstar_lmeanErr_high[cpm]=graph_lthstar->GetErrorYhigh(cpm);
			lthstar_lmeanErr_low[cpm]=graph_lthstar->GetErrorYlow(cpm);
			lthstar_lmeanErr[cpm]=(lthstar_lmeanErr_high[cpm]+lthstar_lmeanErr_low[cpm])/2.;

			graph_lphstar->GetPoint(cpm,cpmCentre[cpm],lphstar_lmean[cpm]);
			lphstar_lmeanErr_high[cpm]=graph_lphstar->GetErrorYhigh(cpm);
			lphstar_lmeanErr_low[cpm]=graph_lphstar->GetErrorYlow(cpm);
			lphstar_lmeanErr[cpm]=(lphstar_lmeanErr_high[cpm]+lphstar_lmeanErr_low[cpm])/2.;

			graph_ltilde->GetPoint(cpm,cpmCentre[cpm],ltilde_lmean[cpm]);
			ltilde_lmeanErr_high[cpm]=graph_ltilde->GetErrorYhigh(cpm);
			ltilde_lmeanErr_low[cpm]=graph_ltilde->GetErrorYlow(cpm);
			ltilde_lmeanErr[cpm]=(ltilde_lmeanErr_high[cpm]+ltilde_lmeanErr_low[cpm])/2.;

			graph_DltildeCS->GetPoint(cpm,cpmCentre[cpm],DltildeCS_lmean[cpm]);
			graph_DltildeHX->GetPoint(cpm,cpmCentre[cpm],DltildeHX_lmean[cpm]);
			graph_DltildePX->GetPoint(cpm,cpmCentre[cpm],DltildePX_lmean[cpm]);

//			cout<<", "<<ltilde_lmean[cpm];
		cpm++;
		}

		cout<<"Values of all parameters loaded for frame "<<iFrame<<endl;

		for(int iParam=1;iParam<7;iParam++){

			if(iParam==1&&iFrame==1) sprintf(GraphName,"lth_CS_rap1_pt%d",ptBin);
			if(iParam==2&&iFrame==1) sprintf(GraphName,"lph_CS_rap1_pt%d",ptBin);
			if(iParam==3&&iFrame==1) sprintf(GraphName,"ltp_CS_rap1_pt%d",ptBin);
			if(iParam==4&&iFrame==1) sprintf(GraphName,"lthstar_CS_rap1_pt%d",ptBin);
			if(iParam==5&&iFrame==1) sprintf(GraphName,"lphstar_CS_rap1_pt%d",ptBin);
			if(iParam==6&&iFrame==1) sprintf(GraphName,"ltilde_CS_rap1_pt%d",ptBin);
			if(iParam==1&&iFrame==2) sprintf(GraphName,"lth_HX_rap1_pt%d",ptBin);
			if(iParam==2&&iFrame==2) sprintf(GraphName,"lph_HX_rap1_pt%d",ptBin);
			if(iParam==3&&iFrame==2) sprintf(GraphName,"ltp_HX_rap1_pt%d",ptBin);
			if(iParam==4&&iFrame==2) sprintf(GraphName,"lthstar_HX_rap1_pt%d",ptBin);
			if(iParam==5&&iFrame==2) sprintf(GraphName,"lphstar_HX_rap1_pt%d",ptBin);
			if(iParam==6&&iFrame==2) sprintf(GraphName,"ltilde_HX_rap1_pt%d",ptBin);
			if(iParam==1&&iFrame==3) sprintf(GraphName,"lth_PX_rap1_pt%d",ptBin);
			if(iParam==2&&iFrame==3) sprintf(GraphName,"lph_PX_rap1_pt%d",ptBin);
			if(iParam==3&&iFrame==3) sprintf(GraphName,"ltp_PX_rap1_pt%d",ptBin);
			if(iParam==4&&iFrame==3) sprintf(GraphName,"lthstar_PX_rap1_pt%d",ptBin);
			if(iParam==5&&iFrame==3) sprintf(GraphName,"lphstar_PX_rap1_pt%d",ptBin);
			if(iParam==6&&iFrame==3) sprintf(GraphName,"ltilde_PX_rap1_pt%d",ptBin);


		double lmean[nBinscpm];
		double lmeanErr_low[nBinscpm];
		double lmeanErr_high[nBinscpm];

		cpm=0;
		for(int cpmBin = cpmBinMin; cpmBin < cpmBinMax+1; cpmBin++) {

			if(iParam==1){
			lmean[cpm]=lth_lmean[cpm]/2.;//0.05;//1./(1-1./3.*ToyMC::fracSignal[rapBin-1][cpmBin-1]*(3+lth_lmean[cpm]))*lth_lmean[cpm];
			lmeanErr_low[cpm]=0.;//(1.-ToyMC::fracSignal[rapBin-1][cpmBin-1])/TMath::Power((1-1./3.*ToyMC::fracSignal[rapBin-1][cpmBin-1]*(3+lth_lmean[cpm])),2)*lth_lmeanErr[cpm];
			lmeanErr_high[cpm]=0.;//lmeanErr_low[cpm];
			}

			if(iParam==2){
			lmean[cpm]=lph_lmean[cpm]/2.;//0.01;//1./(1-1./3.*ToyMC::fracSignal[rapBin-1][cpmBin-1]*(3+lth_lmean[cpm]))*lph_lmean[cpm];
			lmeanErr_low[cpm]=0.;//TMath::Sqrt( (1.)/TMath::Power((1-1./3.*ToyMC::fracSignal[rapBin-1][cpmBin-1]*(3+lth_lmean[cpm])),2)*TMath::Power(lph_lmeanErr[cpm],2)        +       (1./9.)*(TMath::Power(ToyMC::fracSignal[rapBin-1][cpmBin-1],2)*TMath::Power(lph_lmean[cpm],2))/TMath::Power((1-1./3.*ToyMC::fracSignal[rapBin-1][cpmBin-1]*(3+lth_lmean[cpm])),4)*TMath::Power(lth_lmeanErr[cpm],2));
			lmeanErr_high[cpm]=0.;//lmeanErr_low[cpm];
			}

			if(iParam==3){
			lmean[cpm]=ltp_lmean[cpm]/2.;//0.01;//1./(1-1./3.*ToyMC::fracSignal[rapBin-1][cpmBin-1]*(3+lth_lmean[cpm]))*ltp_lmean[cpm];
			lmeanErr_low[cpm]=0.;//TMath::Sqrt( (1.)/TMath::Power((1-1./3.*ToyMC::fracSignal[rapBin-1][cpmBin-1]*(3+lth_lmean[cpm])),2)*TMath::Power(ltp_lmeanErr[cpm],2)        +       (1./9.)*(TMath::Power(ToyMC::fracSignal[rapBin-1][cpmBin-1],2)*TMath::Power(ltp_lmean[cpm],2))/TMath::Power((1-1./3.*ToyMC::fracSignal[rapBin-1][cpmBin-1]*(3+lth_lmean[cpm])),4)*TMath::Power(lth_lmeanErr[cpm],2));
			lmeanErr_high[cpm]=0.;//lmeanErr_low[cpm];
			}

			if(iParam==4){
			lmean[cpm]=0;
			lmeanErr_low[cpm]=0;
			lmeanErr_high[cpm]=0;
			}

			if(iParam==5){
			lmean[cpm]=0;
			lmeanErr_low[cpm]=0;
			lmeanErr_high[cpm]=0;
			}

			if(iParam==6){
			lmean[cpm]=ltilde_lmean[cpm]/2.;//0.05;//0.05;
			lmeanErr_low[cpm]=0.;
			lmeanErr_high[cpm]=0.;

			//lmean[cpm]=lamtildeCS[rapBin-1][cpm]-lamtildeHX[rapBin-1][cpm];
			//lmean[cpm]=lamtildeHX[rapBin-1][cpm]-lamtildePX[rapBin-1][cpm];
			//lmean[cpm]=lamtildePX[rapBin-1][cpm]-lamtildeCS[rapBin-1][cpm];

			lmean[cpm]=DltildeCS_lmean[cpm]-DltildeHX_lmean[cpm];
//			lmean[cpm]=DltildeHX_lmean[cpm]-DltildePX_lmean[cpm];
//			lmean[cpm]=DltildePX_lmean[cpm]-DltildeCS_lmean[cpm];


			}


		cpm++;
		}

		cout<<"Values of parameter "<<iParam<<" changed for frame "<<iFrame<<endl;

		TGraphAsymmErrors *ChangedGraph = new TGraphAsymmErrors(nBinscpm,cpmCentre,lmean,cpmCentreErr_low,cpmCentreErr_high,lmeanErr_low,lmeanErr_high);
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

		cout<<"Values of all parameters changed for frame "<<iFrame<<endl;

		}

		cout<<"Switching To Rapidity 2"<<endl;

		}
		cout<<"Switching frame"<<endl;





	return 0;
}