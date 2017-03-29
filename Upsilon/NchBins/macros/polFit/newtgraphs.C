#ifndef __CINT__
//#include "RooGlobalFunc.h"
#endif

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "TROOT.h"
#include "iomanip"
#include "TStyle.h"
#include "TROOT.h"
#include "TGraphAsymmErrors.h"
#include "TMultiGraph.h"
#include "TGraphErrors.h"
#include "TFile.h"
#include "TMath.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TLine.h"

using namespace std;

void newtgraphs(int nPtCMS1S=2, int nPtCMS2S=2, int nPtCMS3S=2, int iFrame=0){ //nState=1,2,3:Upsi1S,2S,3S

	bool plot1S=false;
	bool plot2S=false;
	bool plot3S=false;

	if(nPtCMS1S>0) plot1S=true;
	if(nPtCMS2S>0) plot2S=true;
	if(nPtCMS3S>0) plot3S=true;

	char nameCMS1S[500], nameCMS2S[500], nameCMS3S[500];
	sprintf(nameCMS1S,"/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx_smallerpT2_FinalSyst_Glob/TGraphResults_1SUps.root");
	sprintf(nameCMS2S,"/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx_smallerpT2_FinalSyst_Glob/TGraphResults_2SUps.root");
	sprintf(nameCMS3S,"/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx_smallerpT2_FinalSyst_Glob/TGraphResults_3SUps.root");
	
	TFile fnew1S("myfile1s.root","RECREATE");
	TFile fnew2S("myfile2s.root","RECREATE");
	TFile fnew3S("myfile3s.root","RECREATE");
	
	TFile *fileCMS1S   = new TFile(nameCMS1S,"R");
	TFile *fileCMS2S   = new TFile(nameCMS2S,"R");
	TFile *fileCMS3S   = new TFile(nameCMS3S,"R");

	
	const int nRapCMS1Smax=1;
	const int nRapCMS2Smax=1;
	const int nRapCMS3Smax=1;
	const int nPtCMS1Smax=2;
	const int nPtCMS2Smax=2;
	const int nPtCMS3Smax=2;	

	//600, 632, 418, 616, 807
	TGraphAsymmErrors *graphCMS1S[nPtCMS1Smax];
	TGraphAsymmErrors *graphCMS2S[nPtCMS2Smax];
	TGraphAsymmErrors *graphCMS3S[nPtCMS3Smax];

	double cpmmin=0;
	double cpmmax=60;	
	double cpmbins[6]={0,10,20,30,40,60};
	double cpmbins3s[5]={0,10,20,30,60};
	
for(int theframe = 0; theframe<3; theframe++){	
	char FrameChar[200];
	if(theframe==0) sprintf(FrameChar, "HX");
	if(theframe==1) sprintf(FrameChar, "CS");
	if(theframe==2) sprintf(FrameChar, "PX");	

	int nBinscpm = 5;
	double cpmCentre_MP[5];
	double lmean_MP[5];
	double lmean_errlow_MP[5];
	double lmean_errhigh_MP[5];
	double cpmCentre_errlow_MP[5];
	double cpmCentre_errhigh_MP[5];
	
	for(int iParameter=0; iParameter <4; iParameter ++){

//		double lamMin[4][2]={{-1.1,-1.1}, {-.45,-.45}, {-.45,-.45}, {-1.1,-1.399}};
//		double lamMax[4][2]={{1.3,  1.3},  {.45, .45},   {.45, .45}, {1.4,1.3}};
		////ups 1s setup
		for(int iRap=0;iRap<nRapCMS3Smax;iRap++){
 		  for(int iPt=0;iPt<nPtCMS3Smax;iPt++){
				char graphName[500];
				if(iParameter==0) sprintf(graphName,"lth_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				if(iParameter==1) sprintf(graphName,"lph_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				if(iParameter==2) sprintf(graphName,"ltp_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				if(iParameter==3) sprintf(graphName,"ltilde_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				graphCMS3S[iPt] = (TGraphAsymmErrors*)fileCMS3S->Get(graphName);
				if (iPt == 0){ nBinscpm = 4;
				 cpmCentre_MP[nBinscpm];
				 lmean_MP[nBinscpm];
				 lmean_errlow_MP[nBinscpm];
				 lmean_errhigh_MP[nBinscpm];
				 cpmCentre_errlow_MP[nBinscpm];
				 cpmCentre_errhigh_MP[nBinscpm];
				}
				if (iPt == 1){ nBinscpm = 5;
				 cpmCentre_MP[nBinscpm];
				 lmean_MP[nBinscpm];
				 lmean_errlow_MP[nBinscpm];
				 lmean_errhigh_MP[nBinscpm];
				 cpmCentre_errlow_MP[nBinscpm];
				 cpmCentre_errhigh_MP[nBinscpm];
				}
				int cpmMP=0;
					for(int cpmBinMP=1;cpmBinMP<nBinscpm+1;cpmBinMP++){
						graphCMS3S[iPt]->GetPoint(cpmBinMP-1,cpmCentre_MP[cpmMP],lmean_MP[cpmMP]);
						lmean_errhigh_MP[cpmMP]=graphCMS3S[iPt]->GetErrorYhigh(cpmBinMP-1);
						lmean_errlow_MP[cpmMP]=graphCMS3S[iPt]->GetErrorYlow(cpmBinMP-1);
						cpmCentre_errhigh_MP[cpmMP]=cpmbins[cpmMP+1]-cpmCentre_MP[cpmMP];
						cpmCentre_errlow_MP[cpmMP]=cpmCentre_MP[cpmMP]-cpmbins[cpmMP];
						if(iPt==0){
						cpmCentre_errhigh_MP[cpmMP]=cpmbins3s[cpmMP+1]-cpmCentre_MP[cpmMP];
						cpmCentre_errlow_MP[cpmMP]=cpmCentre_MP[cpmMP]-cpmbins3s[cpmMP];
						}
						cpmMP++;
					}
				graphCMS3S[iPt] = new TGraphAsymmErrors(nBinscpm,cpmCentre_MP,lmean_MP,cpmCentre_errlow_MP,cpmCentre_errhigh_MP,lmean_errlow_MP,lmean_errhigh_MP);	
				graphCMS3S[iPt]->SetName(graphName);
				graphCMS3S[iPt]->Draw("P");
				fnew3S.cd();
				graphCMS3S[iPt]->Write();
		  }//PtCMS3S
		}//rapCMS2S
/*		for(int iRap=0;iRap<nRapCMS2Smax;iRap++){		////ups 2s setup
 		  for(int iPt=0;iPt<nPtCMS2Smax;iPt++){		
				char graphName[500];
				
				if(iParameter==0) sprintf(graphName,"lth_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				if(iParameter==1) sprintf(graphName,"lph_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				if(iParameter==2) sprintf(graphName,"ltp_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				if(iParameter==3) sprintf(graphName,"ltilde_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				graphCMS2S[iPt] = (TGraphAsymmErrors*)fileCMS2S->Get(graphName);

				int cpmMP=0;
					for(int cpmBinMP=1;cpmBinMP<nBinscpm+1;cpmBinMP++){
						graphCMS2S[iPt]->GetPoint(cpmBinMP-1,cpmCentre_MP[cpmMP],lmean_MP[cpmMP]);
						if(iPt == 1) cpmCentre_MP[cpmMP]=cpmCentre_MP[cpmMP]+1; ///for x-axis offset
						lmean_errhigh_MP[cpmMP]=graphCMS2S[iPt]->GetErrorYhigh(cpmBinMP-1);
						lmean_errlow_MP[cpmMP]=graphCMS2S[iPt]->GetErrorYlow(cpmBinMP-1);
						cpmCentre_errhigh_MP[cpmMP]=cpmbins[cpmMP+1]-cpmCentre_MP[cpmMP];
						cpmCentre_errlow_MP[cpmMP]=cpmCentre_MP[cpmMP]-cpmbins[cpmMP+1];
						cpmMP++;
					}
				graphCMS2S[iPt] = new TGraphAsymmErrors(nBinscpm,cpmCentre_MP,lmean_MP,cpmCentre_errlow_MP,cpmCentre_errhigh_MP,lmean_errlow_MP,lmean_errhigh_MP);
				graphCMS2S[iPt]->SetName(graphName);
				graphCMS2S[iPt]->Draw("P");
				fnew2s.cd();
				graphCMS2S[iPt]->Write();
			}
		}//rapCMS2S

		////ups 3s setup
		for(int iRap=0;iRap<nRapCMS3Smax;iRap++){
 		  for(int iPt=0;iPt<nPtCMS3Smax;iPt++){		
				char graphName[500];
				gStyle->SetPadLeftMargin(0.16);
				gStyle->SetPadRightMargin(0.02);
				
					
				if(iParameter==0) sprintf(graphName,"lth_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				if(iParameter==1) sprintf(graphName,"lph_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				if(iParameter==2) sprintf(graphName,"ltp_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				if(iParameter==3) sprintf(graphName,"ltilde_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				
				graphCMS3S[iPt] = (TGraphAsymmErrors*)fileCMS3S->Get(graphName);
				
				if (iPt == 0){ nBinscpm = 4;
				 cpmCentre_MP[nBinscpm];
				 lmean_MP[nBinscpm];
				 lmean_errlow_MP[nBinscpm];
				 lmean_errhigh_MP[nBinscpm];
				 cpmCentre_errlow_MP[nBinscpm];
				 cpmCentre_errhigh_MP[nBinscpm];
				}
				int cpmMP=0;
					for(int cpmBinMP=1;cpmBinMP<nBinscpm+1;cpmBinMP++){

						graphCMS3S[iPt]->GetPoint(cpmBinMP-1,cpmCentre_MP[cpmMP],lmean_MP[cpmMP]);
						if(iPt == 1) cpmCentre_MP[cpmMP]=cpmCentre_MP[cpmMP]+1; ///for x-axis offset
						lmean_errhigh_MP[cpmMP]=graphCMS3S[iPt]->GetErrorYhigh(cpmBinMP-1);
						lmean_errlow_MP[cpmMP]=graphCMS3S[iPt]->GetErrorYlow(cpmBinMP-1);

						cpmCentre_errhigh_MP[cpmMP]=cpmbins[cpmMP+1]-cpmCentre_MP[cpmMP];
						cpmCentre_errlow_MP[cpmMP]=cpmCentre_MP[cpmMP]-cpmbins[cpmMP+1];
						cpmMP++;
					}

				graphCMS3S[iPt] = new TGraphAsymmErrors(nBinscpm,cpmCentre_MP,lmean_MP,cpmCentre_errlow_MP,cpmCentre_errhigh_MP,lmean_errlow_MP,lmean_errhigh_MP);
				graphCMS3S[iPt]->SetName(graphName);
				graphCMS3S[iPt]->Draw("P");
				fnew3s.cd();
				graphCMS3S[iPt]->Write();

		  }//ptCMS3S
		}//rapCMS3S
*/
	
     }//frame
   }//parameter

}