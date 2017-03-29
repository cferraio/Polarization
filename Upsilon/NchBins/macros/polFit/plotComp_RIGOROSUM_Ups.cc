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

void plotComp_RIGOROSUM_Ups(int nPtCMS1S=2, int nPtCMS2S=2, int nPtCMS3S=2, int iFrame=0){ //nState=1,2,3:Upsi1S,2S,3S
	gROOT->Reset();
	gStyle->SetOptStat(11);
	gStyle->SetOptFit(101);
	gStyle->SetPadTickY(0); 
	gStyle->SetPadTickX(0); 	
	gStyle->SetFillColor(kWhite);
	gStyle->SetPadBottomMargin(0.144); 
	gStyle->SetPadLeftMargin(0.13);
	gStyle->SetPadRightMargin(0.01);
	gStyle->SetPadTopMargin(0.02);

	bool plot1S=false;
	bool plot2S=false;
	bool plot3S=false;
	bool plotCSwithHX=true;
	
	if(nPtCMS1S>0) plot1S=true;
	if(nPtCMS2S>0) plot2S=true;
	if(nPtCMS3S>0) plot3S=true;

	char nameCMS1S[500], nameCMS2S[500], nameCMS3S[500], glob1S[500], glob2S[500], glob3S[500];
	sprintf(nameCMS1S,"/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx_smallerpT2_FinalSyst_Glob/TGraphResults_1SUps.root");
	sprintf(nameCMS2S,"/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx_smallerpT2_FinalSyst_Glob/TGraphResults_2SUps.root");
	sprintf(nameCMS3S,"/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx_smallerpT2_FinalSyst_Glob/TGraphResults_3SUps.root");
	
	sprintf(glob1S,"Systematics/cutNPriVtx_smallerpT2_FinalSyst/AverageSyst/GlobalUnc/TGraphResults_1SUps.root");
	sprintf(glob2S,"Systematics/cutNPriVtx_smallerpT2_FinalSyst/AverageSyst/GlobalUnc/TGraphResults_2SUps.root");
	sprintf(glob3S,"Systematics/cutNPriVtx_smallerpT2_FinalSyst/AverageSyst/GlobalUnc/TGraphResults_3SUps.root");

	TFile *fileCMS1S   = new TFile(nameCMS1S,"R");
	TFile *fileCMS2S   = new TFile(nameCMS2S,"R");
	TFile *fileCMS3S   = new TFile(nameCMS3S,"R");
	TFile *fileglob1S  = new TFile(glob1S,"R");
	TFile *fileglob2S  = new TFile(glob2S,"R");
	TFile *fileglob3S  = new TFile(glob3S,"R");

	char FrameChar[200];
	if(iFrame==0) sprintf(FrameChar, "HX");
//	if(iFrame==0) sprintf(FrameChar, "CS");
//	if(iFrame==0) sprintf(FrameChar, "PX");	

	const int nRapCMS1Smax=1;
	const int nRapCMS2Smax=1;
	const int nRapCMS3Smax=1;
	const int nPtCMS1Smax=2;
	const int nPtCMS2Smax=2;
	const int nPtCMS3Smax=2;	
	
	//int MarkerStyleCMS1S[nRapCMS1Smax]={20, 25};
	//double MarkerSizeCMS1S[nRapCMS1Smax]={1.5, 1.5};
	//int ColorCMS1S[nRapCMS1Smax]={1,600};
    //
	//int MarkerStyleCMS2S[nRapCMS2Smax]={21, 22};
	//double MarkerSizeCMS2S[nRapCMS2Smax]={1.5, 1.5};
	//int ColorCMS2S[nRapCMS2Smax]={807, 618};
    //
	//int MarkerStyleCMS3S[nRapCMS3Smax]={29, 32};
	//double MarkerSizeCMS3S[nRapCMS3Smax]={1.5, 1.5};
	//int ColorCMS3S[nRapCMS3Smax]={616, 632};
    //


	int MarkerStyleCMS1S[nPtCMS1Smax]={25, 20};
	int MarkerStyleCMS1SCS[nPtCMS1Smax]={30, 29};
	double MarkerSizeCMS1S[nPtCMS1Smax]={2.5, 2.5};
	int ColorCMS1S[nPtCMS1Smax]={2,4};
	int ColorCMS1SCS[nPtCMS1Smax]={6,kViolet-6};

	int MarkerStyleCMS2S[nPtCMS2Smax]={25, 20};
	double MarkerSizeCMS2S[nPtCMS2Smax]={2.5, 2.5};
	int ColorCMS2S[nPtCMS2Smax]={2,4};
	int MarkerStyleCMS2SCS[nPtCMS2Smax]={30, 29};
	int ColorCMS2SCS[nPtCMS2Smax]={6,kViolet-6};

	int MarkerStyleCMS3S[nPtCMS3Smax]={25, 20};
	double MarkerSizeCMS3S[nPtCMS3Smax]={2.5, 2.5};
	int ColorCMS3S[nPtCMS3Smax]={2,4};
	int MarkerStyleCMS3SCS[nPtCMS3Smax]={30, 29};
	int ColorCMS3SCS[nPtCMS3Smax]={6,kViolet-6};

	//600, 632, 418, 616, 807
	TGraphAsymmErrors *graphCMS1S[nPtCMS1Smax];
	TGraphAsymmErrors *graphCMS2S[nPtCMS2Smax];
	TGraphAsymmErrors *graphCMS3S[nPtCMS3Smax];
	TGraphAsymmErrors *graphCMS1SCS[nPtCMS1Smax];
	TGraphAsymmErrors *graphCMS2SCS[nPtCMS2Smax];
	TGraphAsymmErrors *graphCMS3SCS[nPtCMS3Smax];
	TGraphErrors 	   *globunctgraph1S[nPtCMS1Smax];
	TGraphErrors 	   *globunctgraph2S[nPtCMS2Smax];
	TGraphErrors 	   *globunctgraph3S[nPtCMS3Smax];
	TMultiGraph 	   *merged1S = new TMultiGraph();
	TMultiGraph		   *merged2S = new TMultiGraph();
	TMultiGraph 	   *merged3S = new TMultiGraph();

	double cpmmin=-2;
	double cpmmax=59.9999;	
	
	///////////fit parameters
	char FitOptions[200];
	sprintf(FitOptions,"EFNR");
	double xMin=0.;
	double xMax=60.;
	TF1* slope1s = new TF1("slope1s","pol1",xMin,xMax); ////1st order polynomial
	TF1* fixed1s = new TF1("fixed1s","pol1",xMin,xMax); ////1st order polynomial
	fixed1s->SetParameter(0,0);
	fixed1s->FixParameter(0,0);
	TF1* fixed2s = new TF1("fixed2s","pol1",xMin,xMax); ////1st order polynomial
	fixed2s->SetParameter(0,0);
	fixed2s->FixParameter(0,0);
	TF1* fixed3s = new TF1("fixed3s","pol1",xMin,xMax); ////1st order polynomial
	fixed3s->SetParameter(0,0);
	fixed3s->FixParameter(0,0);
	TF1* constant1s = new TF1("constant1s","pol0",xMin,xMax); ////constant
	TF1* slope2s = new TF1("slope2s","pol1",xMin,xMax); ////1st order polynomial
	TF1* constant2s = new TF1("constant2s","pol0",xMin,xMax); ////constant
	TF1* slope3s = new TF1("slope3s","pol1",xMin,xMax); ////1st order polynomial
	TF1* constant3s = new TF1("constant3s","pol0",xMin,xMax); ////constant
	
	
	for(int iParameter=0; iParameter <4; iParameter ++){

		double lamMin[4][2]={{-1.1,-1.1}, {-.45,-.45}, {-.45,-.45}, {-1.1,-1.399}};
		double lamMax[4][2]={{1.3,  1.3},  {.45, .45},   {.45, .45}, {1.4,1.3}};
		
						
		///global uncertainties
		for(int iRap=0;iRap<nRapCMS1Smax;iRap++){
 		  for(int iPt=0;iPt<nPtCMS1Smax;iPt++){
 		  char graphName[500];
				if(iParameter==0) sprintf(graphName,"lth_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				if(iParameter==1) sprintf(graphName,"lph_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				if(iParameter==2) sprintf(graphName,"ltp_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				if(iParameter==3) sprintf(graphName,"ltilde_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
					

				double cpmCenter[1];
				double error1S[1];
				double error2S[1];
				double error3S[1];
				double xrange[1];
				double y[1];
				xrange[0] = 1.;
				y[0]=0.;
				
				globunctgraph1S[iPt] = (TGraphErrors*)fileglob1S->Get(graphName);
				globunctgraph2S[iPt] = (TGraphErrors*)fileglob2S->Get(graphName);
				globunctgraph3S[iPt] = (TGraphErrors*)fileglob3S->Get(graphName);
				  
				if (iPt==0) 
				{
				  cpmCenter[0] = -.5;
				  error1S[0] = globunctgraph1S[iPt]->GetErrorY(0);
				  error2S[0] = globunctgraph2S[iPt]->GetErrorY(0);
				  error3S[0] = globunctgraph3S[iPt]->GetErrorY(0);
				  globunctgraph1S[0] = new TGraphErrors(1,cpmCenter,y,xrange,error1S);
				  globunctgraph2S[0] = new TGraphErrors(1,cpmCenter,y,xrange,error2S);
			  	  globunctgraph3S[0] = new TGraphErrors(1,cpmCenter,y,xrange,error3S);
			  	  globunctgraph1S[0]->SetLineColor(2);
			  	  globunctgraph2S[0]->SetLineColor(2);
				  globunctgraph3S[0]->SetLineColor(2);
				  globunctgraph1S[0]->SetLineWidth(3);
				  globunctgraph2S[0]->SetLineWidth(3);
				  globunctgraph3S[0]->SetLineWidth(3);
				  globunctgraph1S[0]->SetFillStyle(0);
				  globunctgraph2S[0]->SetFillStyle(0);
				  globunctgraph3S[0]->SetFillStyle(0);
				  globunctgraph1S[0]->SetFillColor(2);
				  globunctgraph2S[0]->SetFillColor(2);
				  globunctgraph3S[0]->SetFillColor(2);
				}
				
				if (iPt==1)
				{
				  cpmCenter[0] = 1.5;
				  error1S[0] = globunctgraph1S[iPt]->GetErrorY(0);
				  error2S[0] = globunctgraph2S[iPt]->GetErrorY(0);
				  error3S[0] = globunctgraph3S[iPt]->GetErrorY(0);
				  globunctgraph1S[1] = new TGraphErrors(1,cpmCenter,y,xrange,error1S);
				  globunctgraph2S[1] = new TGraphErrors(1,cpmCenter,y,xrange,error2S);
				  globunctgraph3S[1] = new TGraphErrors(1,cpmCenter,y,xrange,error3S);
				  globunctgraph1S[1]->SetLineColor(4);
			 	  globunctgraph2S[1]->SetLineColor(4);
			 	  globunctgraph3S[1]->SetLineColor(4);
				  globunctgraph1S[1]->SetFillColor(4);
				  globunctgraph2S[1]->SetFillColor(4);
				  globunctgraph3S[1]->SetFillColor(4);
				}		
				
 		  }
 		}

		////ups 1s setup
		for(int iRap=0;iRap<nRapCMS1Smax;iRap++){
 		  for(int iPt=0;iPt<nPtCMS1Smax;iPt++){
 		  	
				char graphName[500];
				char graphNameCS[500];
				if(iParameter==0) sprintf(graphName,"lth_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				if(iParameter==1) sprintf(graphName,"lph_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				if(iParameter==2) sprintf(graphName,"ltp_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				if(iParameter==3) sprintf(graphName,"ltilde_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				graphCMS1S[iPt] = (TGraphAsymmErrors*)fileCMS1S->Get(graphName);
				if(plotCSwithHX && iParameter==3) {

				sprintf(graphNameCS,"ltilde_CS_rap%d_pt%d", iRap+1,iPt+1);
				graphCMS1SCS[iPt] = (TGraphAsymmErrors*)fileCMS1S->Get(graphNameCS);
				}
				
				if(iParameter==0)	merged1S->Add(graphCMS1S[iPt]);
				
				
				int nBinscpm = 5;
				double cpmCentre_MP[nBinscpm];
				double lmean_MP[nBinscpm];
				double lmean_errlow_MP[nBinscpm];
				double lmean_errhigh_MP[nBinscpm];
				double cpmCentre_errlow_MP[nBinscpm];
				double cpmCentre_errhigh_MP[nBinscpm];
				double cpmCentre_MPCS[nBinscpm];
				double lmean_MPCS[nBinscpm];
				double lmean_errlow_MPCS[nBinscpm];
				double lmean_errhigh_MPCS[nBinscpm];
				double cpmCentre_errlow_MPCS[nBinscpm];
				double cpmCentre_errhigh_MPCS[nBinscpm];
				
				int cpmMP=0;
					for(int cpmBinMP=1;cpmBinMP<nBinscpm+1;cpmBinMP++){

						graphCMS1S[iPt]->GetPoint(cpmBinMP-1,cpmCentre_MP[cpmMP],lmean_MP[cpmMP]);
						if(iPt == 1) cpmCentre_MP[cpmMP]=cpmCentre_MP[cpmMP]+1; ///for x-axis offset
						lmean_errhigh_MP[cpmMP]=graphCMS1S[iPt]->GetErrorYhigh(cpmBinMP-1);
						lmean_errlow_MP[cpmMP]=graphCMS1S[iPt]->GetErrorYlow(cpmBinMP-1);

						cpmCentre_errhigh_MP[cpmMP]=0.;
						cpmCentre_errlow_MP[cpmMP]=0.;
						cpmMP++;
						
					}

				graphCMS1S[iPt] = new TGraphAsymmErrors(nBinscpm,cpmCentre_MP,lmean_MP,cpmCentre_errlow_MP,cpmCentre_errhigh_MP,lmean_errlow_MP,lmean_errhigh_MP);
				
				
				if(plotCSwithHX && iParameter==3){

						
					cpmMP=0;
					for(int cpmBinMP=1;cpmBinMP<nBinscpm+1;cpmBinMP++){	
						graphCMS1SCS[iPt]->GetPoint(cpmBinMP-1,cpmCentre_MPCS[cpmMP],lmean_MPCS[cpmMP]);
						if(iPt == 0) cpmCentre_MPCS[cpmMP]=cpmCentre_MPCS[cpmMP]-1; ///for x-axis offset
						if(iPt == 1) cpmCentre_MPCS[cpmMP]=cpmCentre_MPCS[cpmMP]+2; ///for x-axis offset
						lmean_errhigh_MPCS[cpmMP]=graphCMS1SCS[iPt]->GetErrorYhigh(cpmBinMP-1);
						lmean_errlow_MPCS[cpmMP]=graphCMS1SCS[iPt]->GetErrorYlow(cpmBinMP-1);

						cpmCentre_errhigh_MPCS[cpmMP]=0.;
						cpmCentre_errlow_MPCS[cpmMP]=0.;
						cpmMP++;
						
						}
				

				graphCMS1SCS[iPt] = new TGraphAsymmErrors(nBinscpm,cpmCentre_MPCS,lmean_MPCS,cpmCentre_errlow_MPCS,cpmCentre_errhigh_MPCS,lmean_errlow_MPCS,lmean_errhigh_MPCS);
				
				graphCMS1SCS[iPt]->SetMarkerStyle(MarkerStyleCMS1SCS[iPt]);
					graphCMS1SCS[iPt]->SetMarkerSize(MarkerSizeCMS1S[iPt]+1.25);
					graphCMS1SCS[iPt]->SetMarkerColor(ColorCMS1SCS[iPt]);
					graphCMS1SCS[iPt]->SetLineColor(ColorCMS1SCS[iPt]);
					graphCMS1SCS[iPt]->SetLineWidth(3);
				
				}
				
				
				graphCMS1S[iPt]->GetYaxis()->SetRangeUser(lamMin[iParameter][iFrame],lamMax[iParameter][iFrame]);
				graphCMS1S[iPt]->GetXaxis()->SetLimits(cpmmin, cpmmax);
				graphCMS1S[iPt]->SetTitle("");
				graphCMS1S[iPt]->GetXaxis()->SetTitle("#it{N}_{ch}");
				graphCMS1S[iPt]->GetYaxis()->SetTitle("");
				graphCMS1S[iPt]->GetYaxis()->SetTitleSize(0.08);
				graphCMS1S[iPt]->GetYaxis()->SetLabelSize(0.06);
				graphCMS1S[iPt]->GetXaxis()->SetLabelSize(0.06);
				graphCMS1S[iPt]->GetXaxis()->SetLabelOffset(0.015);
				graphCMS1S[iPt]->GetYaxis()->SetLabelOffset(0.015);
				if(iParameter==1 || iParameter==2) graphCMS1S[iPt]->GetYaxis()->SetNdivisions(505, kTRUE);
				graphCMS1S[iPt]->GetXaxis()->SetTitleSize(0.08);
				graphCMS1S[iPt]->GetXaxis()->SetTitleOffset(0.8);
				graphCMS1S[iPt]->GetYaxis()->SetTitleOffset(1.);
				graphCMS1S[iPt]->SetMarkerStyle(MarkerStyleCMS1S[iPt]);
				graphCMS1S[iPt]->SetMarkerSize(MarkerSizeCMS1S[iPt]);
				graphCMS1S[iPt]->SetMarkerColor(ColorCMS1S[iPt]);
				graphCMS1S[iPt]->SetLineColor(ColorCMS1S[iPt]);
				graphCMS1S[iPt]->SetLineWidth(3);
			
		  }//PtCMS1S
		}//rapCMS1S

		////ups 2s setup
		for(int iRap=0;iRap<nRapCMS2Smax;iRap++){
 		  for(int iPt=0;iPt<nPtCMS2Smax;iPt++){		
				char graphName[500];
				char graphNameCS[500];
				
				if(iParameter==0) sprintf(graphName,"lth_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				if(iParameter==1) sprintf(graphName,"lph_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				if(iParameter==2) sprintf(graphName,"ltp_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				if(iParameter==3) sprintf(graphName,"ltilde_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				graphCMS2S[iPt] = (TGraphAsymmErrors*)fileCMS2S->Get(graphName);
				if(plotCSwithHX && iParameter==3) {

				sprintf(graphNameCS,"ltilde_CS_rap%d_pt%d", iRap+1,iPt+1);
				graphCMS2SCS[iPt] = (TGraphAsymmErrors*)fileCMS2S->Get(graphNameCS);
				}
				
				if(iParameter==0)	merged2S->Add(graphCMS2S[iPt]);
				int nBinscpm = 5;
				double cpmCentre_MP[nBinscpm];
				double lmean_MP[nBinscpm];
				double lmean_errlow_MP[nBinscpm];
				double lmean_errhigh_MP[nBinscpm];
				double cpmCentre_errlow_MP[nBinscpm];
				double cpmCentre_errhigh_MP[nBinscpm];
				double cpmCentre_MPCS[nBinscpm];
				double lmean_MPCS[nBinscpm];
				double lmean_errlow_MPCS[nBinscpm];
				double lmean_errhigh_MPCS[nBinscpm];
				double cpmCentre_errlow_MPCS[nBinscpm];
				double cpmCentre_errhigh_MPCS[nBinscpm];
				
				int cpmMP=0;
					for(int cpmBinMP=1;cpmBinMP<nBinscpm+1;cpmBinMP++){

						graphCMS2S[iPt]->GetPoint(cpmBinMP-1,cpmCentre_MP[cpmMP],lmean_MP[cpmMP]);
						if(iPt == 1) cpmCentre_MP[cpmMP]=cpmCentre_MP[cpmMP]+1; ///for x-axis offset
						lmean_errhigh_MP[cpmMP]=graphCMS2S[iPt]->GetErrorYhigh(cpmBinMP-1);
						lmean_errlow_MP[cpmMP]=graphCMS2S[iPt]->GetErrorYlow(cpmBinMP-1);

						cpmCentre_errhigh_MP[cpmMP]=0.;
						cpmCentre_errlow_MP[cpmMP]=0.;
						cpmMP++;
					}

				graphCMS2S[iPt] = new TGraphAsymmErrors(nBinscpm,cpmCentre_MP,lmean_MP,cpmCentre_errlow_MP,cpmCentre_errhigh_MP,lmean_errlow_MP,lmean_errhigh_MP);
				
				if(plotCSwithHX && iParameter==3){

						
					cpmMP=0;
					for(int cpmBinMP=1;cpmBinMP<nBinscpm+1;cpmBinMP++){	
						graphCMS2SCS[iPt]->GetPoint(cpmBinMP-1,cpmCentre_MPCS[cpmMP],lmean_MPCS[cpmMP]);
						if(iPt == 0) cpmCentre_MPCS[cpmMP]=cpmCentre_MPCS[cpmMP]-1; ///for x-axis offset
						if(iPt == 1) cpmCentre_MPCS[cpmMP]=cpmCentre_MPCS[cpmMP]+2; ///for x-axis offset
						lmean_errhigh_MPCS[cpmMP]=graphCMS2SCS[iPt]->GetErrorYhigh(cpmBinMP-1);
						lmean_errlow_MPCS[cpmMP]=graphCMS2SCS[iPt]->GetErrorYlow(cpmBinMP-1);

						cpmCentre_errhigh_MPCS[cpmMP]=0.;
						cpmCentre_errlow_MPCS[cpmMP]=0.;
						cpmMP++;
						
						}
				

				graphCMS2SCS[iPt] = new TGraphAsymmErrors(nBinscpm,cpmCentre_MPCS,lmean_MPCS,cpmCentre_errlow_MPCS,cpmCentre_errhigh_MPCS,lmean_errlow_MPCS,lmean_errhigh_MPCS);
				
				graphCMS2SCS[iPt]->SetMarkerStyle(MarkerStyleCMS2SCS[iPt]);
					graphCMS2SCS[iPt]->SetMarkerSize(MarkerSizeCMS2S[iPt]+1.25);
					graphCMS2SCS[iPt]->SetMarkerColor(ColorCMS2SCS[iPt]);
					graphCMS2SCS[iPt]->SetLineColor(ColorCMS2SCS[iPt]);
					graphCMS2SCS[iPt]->SetLineWidth(3);
				
				}
				
				graphCMS2S[iPt]->GetYaxis()->SetRangeUser(lamMin[iParameter][iFrame],lamMax[iParameter][iFrame]);				
				graphCMS2S[iPt]->GetXaxis()->SetLimits(cpmmin, cpmmax);
				graphCMS2S[iPt]->SetTitle("");
				graphCMS2S[iPt]->GetXaxis()->SetTitle("#it{N}_{ch}");
				graphCMS2S[iPt]->GetYaxis()->SetTitle("");
				graphCMS2S[iPt]->GetYaxis()->SetTitleSize(0.08);
				graphCMS2S[iPt]->GetYaxis()->SetLabelSize(0.06);
				graphCMS2S[iPt]->GetXaxis()->SetLabelSize(0.06);				
				graphCMS2S[iPt]->GetXaxis()->SetTitleSize(0.08);
				if(iParameter==1 || iParameter==2) graphCMS2S[iPt]->GetYaxis()->SetNdivisions(505, kTRUE);
				graphCMS2S[iPt]->GetXaxis()->SetLabelOffset(0.015);
				graphCMS2S[iPt]->GetYaxis()->SetLabelOffset(0.015);
				graphCMS2S[iPt]->GetXaxis()->SetTitleOffset(0.8);
				graphCMS2S[iPt]->GetYaxis()->SetTitleOffset(1.);
				graphCMS2S[iPt]->SetMarkerStyle(MarkerStyleCMS2S[iPt]);
				graphCMS2S[iPt]->SetMarkerSize(MarkerSizeCMS2S[iPt]);
				graphCMS2S[iPt]->SetMarkerColor(ColorCMS2S[iPt]);
				graphCMS2S[iPt]->SetLineColor(ColorCMS2S[iPt]);
				graphCMS2S[iPt]->SetLineWidth(3);
		  }//ptCMS2S
		}//rapCMS2S

		////ups 3s setup
		for(int iRap=0;iRap<nRapCMS3Smax;iRap++){
 		  for(int iPt=0;iPt<nPtCMS3Smax;iPt++){		
				char graphName[500];
				char graphNameCS[500];
				gStyle->SetPadLeftMargin(0.16);
				gStyle->SetPadRightMargin(0.02);
				
					
				if(iParameter==0) sprintf(graphName,"lth_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				if(iParameter==1) sprintf(graphName,"lph_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				if(iParameter==2) sprintf(graphName,"ltp_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				if(iParameter==3) sprintf(graphName,"ltilde_%s_rap%d_pt%d",FrameChar, iRap+1,iPt+1);
				
				graphCMS3S[iPt] = (TGraphAsymmErrors*)fileCMS3S->Get(graphName);
				if(plotCSwithHX && iParameter==3) {

				sprintf(graphNameCS,"ltilde_CS_rap%d_pt%d", iRap+1,iPt+1);
				graphCMS3SCS[iPt] = (TGraphAsymmErrors*)fileCMS3S->Get(graphNameCS);
				}
				if(iParameter==0)	merged3S->Add(graphCMS3S[iPt]);
				int nBinscpm = 5;
				if (iPt == 0) nBinscpm = 4;
				double cpmCentre_MP[nBinscpm];
				double lmean_MP[nBinscpm];
				double lmean_errlow_MP[nBinscpm];
				double lmean_errhigh_MP[nBinscpm];
				double cpmCentre_errlow_MP[nBinscpm];
				double cpmCentre_errhigh_MP[nBinscpm];
				double cpmCentre_MPCS[nBinscpm];
				double lmean_MPCS[nBinscpm];
				double lmean_errlow_MPCS[nBinscpm];
				double lmean_errhigh_MPCS[nBinscpm];
				double cpmCentre_errlow_MPCS[nBinscpm];
				double cpmCentre_errhigh_MPCS[nBinscpm];
				
				int cpmMP=0;
					for(int cpmBinMP=1;cpmBinMP<nBinscpm+1;cpmBinMP++){

						graphCMS3S[iPt]->GetPoint(cpmBinMP-1,cpmCentre_MP[cpmMP],lmean_MP[cpmMP]);
						if(iPt == 1) cpmCentre_MP[cpmMP]=cpmCentre_MP[cpmMP]+1; ///for x-axis offset
						lmean_errhigh_MP[cpmMP]=graphCMS3S[iPt]->GetErrorYhigh(cpmBinMP-1);
						lmean_errlow_MP[cpmMP]=graphCMS3S[iPt]->GetErrorYlow(cpmBinMP-1);

						cpmCentre_errhigh_MP[cpmMP]=0.;
						cpmCentre_errlow_MP[cpmMP]=0.;
						cpmMP++;
					}

				graphCMS3S[iPt] = new TGraphAsymmErrors(nBinscpm,cpmCentre_MP,lmean_MP,cpmCentre_errlow_MP,cpmCentre_errhigh_MP,lmean_errlow_MP,lmean_errhigh_MP);
				
				if(plotCSwithHX && iParameter==3){

						
					cpmMP=0;
					for(int cpmBinMP=1;cpmBinMP<nBinscpm+1;cpmBinMP++){	
						graphCMS3SCS[iPt]->GetPoint(cpmBinMP-1,cpmCentre_MPCS[cpmMP],lmean_MPCS[cpmMP]);
						if(iPt == 0) cpmCentre_MPCS[cpmMP]=cpmCentre_MPCS[cpmMP]-1; ///for x-axis offset
						if(iPt == 1) cpmCentre_MPCS[cpmMP]=cpmCentre_MPCS[cpmMP]+2; ///for x-axis offset
						lmean_errhigh_MPCS[cpmMP]=graphCMS3SCS[iPt]->GetErrorYhigh(cpmBinMP-1);
						lmean_errlow_MPCS[cpmMP]=graphCMS3SCS[iPt]->GetErrorYlow(cpmBinMP-1);

						cpmCentre_errhigh_MPCS[cpmMP]=0.;
						cpmCentre_errlow_MPCS[cpmMP]=0.;
						cpmMP++;
						
						}
				

				graphCMS3SCS[iPt] = new TGraphAsymmErrors(nBinscpm,cpmCentre_MPCS,lmean_MPCS,cpmCentre_errlow_MPCS,cpmCentre_errhigh_MPCS,lmean_errlow_MPCS,lmean_errhigh_MPCS);
				
				graphCMS3SCS[iPt]->SetMarkerStyle(MarkerStyleCMS3SCS[iPt]);
					graphCMS3SCS[iPt]->SetMarkerSize(MarkerSizeCMS3S[iPt]+1.25);
					graphCMS3SCS[iPt]->SetMarkerColor(ColorCMS3SCS[iPt]);
					graphCMS3SCS[iPt]->SetLineColor(ColorCMS3SCS[iPt]);
					graphCMS3SCS[iPt]->SetLineWidth(3);
				
				}	
				
				graphCMS3S[iPt]->GetYaxis()->SetRangeUser(lamMin[iParameter][iFrame],lamMax[iParameter][iFrame]);				
				graphCMS3S[iPt]->GetXaxis()->SetLimits(cpmmin, cpmmax);
				graphCMS3S[iPt]->SetTitle("");
				graphCMS3S[iPt]->GetXaxis()->SetTitle("#it{N}_{ch}");
				graphCMS3S[iPt]->GetYaxis()->SetTitle("");
				graphCMS3S[iPt]->GetYaxis()->SetTitleSize(0.08);
				graphCMS3S[iPt]->GetYaxis()->SetLabelSize(0.06);
				graphCMS3S[iPt]->GetXaxis()->SetLabelSize(0.06);	
				if(iParameter==1 || iParameter==2) graphCMS3S[iPt]->GetYaxis()->SetNdivisions(505, kTRUE);
				graphCMS3S[iPt]->GetXaxis()->SetLabelOffset(0.015);
				graphCMS3S[iPt]->GetYaxis()->SetLabelOffset(0.015);
				graphCMS3S[iPt]->GetXaxis()->SetTitleSize(0.08);
				graphCMS3S[iPt]->GetXaxis()->SetTitleOffset(0.8);
				graphCMS3S[iPt]->GetYaxis()->SetTitleOffset(1.);
				graphCMS3S[iPt]->SetMarkerStyle(MarkerStyleCMS3S[iPt]);
				graphCMS3S[iPt]->SetMarkerSize(MarkerSizeCMS3S[iPt]);
				graphCMS3S[iPt]->SetMarkerColor(ColorCMS3S[iPt]);
				graphCMS3S[iPt]->SetLineColor(ColorCMS3S[iPt]);
				graphCMS3S[iPt]->SetLineWidth(3);
		  }//ptCMS3S
		}//rapCMS3S
		
		/////fits
		if(iParameter==0){
		int nPoints=10;
		slope1s->SetLineWidth(2);
		slope1s->SetLineColor(kRed);
		slope1s->SetLineStyle(1);
		constant1s->SetLineWidth(2);
		constant1s->SetLineColor(kBlue);
		constant1s->SetLineStyle(3);
		fixed1s->SetLineWidth(2);
		fixed1s->SetLineColor(kGreen);
		fixed1s->SetLineStyle(4);
		
		slope2s->SetLineWidth(2);
		slope2s->SetLineColor(kRed);
		slope2s->SetLineStyle(1);
		constant2s->SetLineWidth(2);
		constant2s->SetLineColor(kBlue);
		constant2s->SetLineStyle(3);
		fixed2s->SetLineWidth(2);
		fixed2s->SetLineColor(kGreen);
		fixed2s->SetLineStyle(4);
		
		slope3s->SetLineWidth(2);
		slope3s->SetLineColor(kRed);
		slope3s->SetLineStyle(1);
		constant3s->SetLineWidth(2);
		constant3s->SetLineColor(kBlue);
		constant3s->SetLineStyle(3);
		fixed3s->SetLineWidth(2);
		fixed3s->SetLineColor(kGreen);
		fixed3s->SetLineStyle(4);
		
		if(nPtCMS1S>0){
		merged1S->Fit("slope1s",FitOptions);
		double OneSslopep0 = slope1s->GetParameter(0);
		double OneSslopeerr_p0 = slope1s->GetParError(0);
		double OneSslopep1 = slope1s->GetParameter(1);
		double OneSslopeerr_p1 = slope1s->GetParError(1);
		double OneSslopechi2=slope1s->GetChisquare();
		double OneSslopeNDF=slope1s->GetNDF();
		double OneSslopeBIC=OneSslopechi2+2*TMath::Log(nPoints);
		merged1S->Fit("fixed1s",FitOptions);
		double OneSfixedp0 = fixed1s->GetParameter(0);
		double OneSfixederr_p0 = fixed1s->GetParError(0);
		double OneSfixedp1 = fixed1s->GetParameter(1);
		double OneSfixederr_p1 = fixed1s->GetParError(1);
		double OneSfixedchi2=fixed1s->GetChisquare();
		double OneSfixedNDF=fixed1s->GetNDF();
		double OneSfixedBIC=OneSfixedchi2+2*TMath::Log(nPoints);
		merged1S->Fit("constant1s",FitOptions);
		double OneSconstp0 = constant1s->GetParameter(0);
		double OneSconsterr_p0 = constant1s->GetParError(0);
		double OneSconstchi2=constant1s->GetChisquare();
		double OneSconstNDF=constant1s->GetNDF();
		double OneSconstBIC=OneSconstchi2+2*TMath::Log(nPoints);
		cout<<"1S Constant: "<<endl;
		cout<<"   p0 = "<<OneSconstp0<<" +- "<<OneSconsterr_p0<<endl; cout<<"   chi2 = "<<OneSconstchi2<<endl; cout<<"   chi2/NDF = "<<OneSconstchi2/OneSconstNDF<<endl; cout<<"   BIC = "<<OneSconstBIC<<endl;
		cout<<"1S Linear: "<<endl; 
		cout<<"   p0 = "<<OneSslopep0<<" +- "<<OneSslopeerr_p0<<endl;  cout<<"   p1 = "<<OneSslopep1<<" +- "<<OneSslopeerr_p1<<endl; cout<<"   chi2 = "<<OneSslopechi2<<endl; cout<<"   chi2/NDF = "<<OneSslopechi2/OneSslopeNDF<<endl; cout<<"   BIC = "<<OneSslopeBIC<<endl;
		cout<<"1S Fixed Linear: "<<endl; 
		cout<<"   p0 = "<<OneSfixedp0<<" +- "<<OneSfixederr_p0<<endl;  cout<<"   p1 = "<<OneSfixedp1<<" +- "<<OneSfixederr_p1<<endl; cout<<"   chi2 = "<<OneSfixedchi2<<endl; cout<<"   chi2/NDF = "<<OneSfixedchi2/OneSfixedNDF<<endl; cout<<"   BIC = "<<OneSfixedBIC<<endl;
		}
		if(nPtCMS2S>0){
		merged2S->Fit("slope2s",FitOptions);
		double TwoSslopep0 = slope2s->GetParameter(0);
		double TwoSslopeerr_p0 = slope2s->GetParError(0);
		double TwoSslopep1 = slope2s->GetParameter(1);
		double TwoSslopeerr_p1 = slope2s->GetParError(1);
		double TwoSslopechi2=slope2s->GetChisquare();
		double TwoSslopeNDF=slope2s->GetNDF();
		double TwoSslopeBIC=TwoSslopechi2+2*TMath::Log(nPoints);
		merged2S->Fit("fixed2s",FitOptions);
		double TwoSfixedp0 = fixed2s->GetParameter(0);
		double TwoSfixederr_p0 = fixed2s->GetParError(0);
		double TwoSfixedp1 = fixed2s->GetParameter(1);
		double TwoSfixederr_p1 = fixed2s->GetParError(1);
		double TwoSfixedchi2=fixed2s->GetChisquare();
		double TwoSfixedNDF=fixed2s->GetNDF();
		double TwoSfixedBIC=TwoSfixedchi2+2*TMath::Log(nPoints);
		merged2S->Fit("constant2s",FitOptions);
		double TwoSconstp0 = constant2s->GetParameter(0);
		double TwoSconsterr_p0 = constant2s->GetParError(0);
		double TwoSconstchi2=constant2s->GetChisquare();
		double TwoSconstNDF=constant2s->GetNDF();
		double TwoSconstBIC=TwoSconstchi2+2*TMath::Log(nPoints);
		cout<<"2S Constant: "<<endl;
		cout<<"   p0 = "<<TwoSconstp0<<" +- "<<TwoSconsterr_p0<<endl; cout<<"   chi2 = "<<TwoSconstchi2<<endl; cout<<"   chi2/NDF = "<<TwoSconstchi2/TwoSconstNDF<<endl; cout<<"   BIC = "<<TwoSconstBIC<<endl;
		cout<<"2S Linear: "<<endl;
		cout<<"   p0 = "<<TwoSslopep0<<" +- "<<TwoSslopeerr_p0<<endl;  cout<<"   p1 = "<<TwoSslopep1<<" +- "<<TwoSslopeerr_p1<<endl; cout<<"   chi2 = "<<TwoSslopechi2<<endl; cout<<"   chi2/NDF = "<<TwoSslopechi2/TwoSslopeNDF<<endl; cout<<"   BIC = "<<TwoSslopeBIC<<endl;
		cout<<"2S Fixed Linear: "<<endl;
		cout<<"   p0 = "<<TwoSfixedp0<<" +- "<<TwoSfixederr_p0<<endl;  cout<<"   p1 = "<<TwoSfixedp1<<" +- "<<TwoSfixederr_p1<<endl; cout<<"   chi2 = "<<TwoSfixedchi2<<endl; cout<<"   chi2/NDF = "<<TwoSfixedchi2/TwoSfixedNDF<<endl; cout<<"   BIC = "<<TwoSfixedBIC<<endl;
		}
		if(nPtCMS3S>0){
		merged3S->Fit("slope3s",FitOptions);
		double ThreeSslopep0 = slope3s->GetParameter(0);
		double ThreeSslopeerr_p0 = slope3s->GetParError(0);
		double ThreeSslopep1 = slope3s->GetParameter(1);
		double ThreeSslopeerr_p1 = slope3s->GetParError(1);
		double ThreeSslopechi2=slope3s->GetChisquare();
		double ThreeSslopeNDF=slope3s->GetNDF();
		nPoints = 9;
		double ThreeSslopeBIC=ThreeSslopechi2+2*TMath::Log(nPoints);
		merged3S->Fit("fixed3s",FitOptions);
		double ThreeSfixedp0 = fixed3s->GetParameter(0);
		double ThreeSfixederr_p0 = fixed3s->GetParError(0);
		double ThreeSfixedp1 = fixed3s->GetParameter(1);
		double ThreeSfixederr_p1 = fixed3s->GetParError(1);
		double ThreeSfixedchi2=fixed3s->GetChisquare();
		double ThreeSfixedNDF=fixed3s->GetNDF();
		double ThreeSfixedBIC=ThreeSfixedchi2+2*TMath::Log(nPoints);
		merged3S->Fit("constant3s",FitOptions);
		double ThreeSconstp0 = constant3s->GetParameter(0);
		double ThreeSconsterr_p0 = constant3s->GetParError(0);
		double ThreeSconstchi2=constant3s->GetChisquare();
		double ThreeSconstNDF=constant3s->GetNDF();
		double ThreeSconstBIC=ThreeSconstchi2+2*TMath::Log(nPoints);
		cout<<"3S Constant: "<<endl;
		cout<<"   p0 = "<<ThreeSconstp0<<" +- "<<ThreeSconsterr_p0<<endl; cout<<"   chi2 = "<<ThreeSconstchi2<<endl; cout<<"   chi2/NDF = "<<ThreeSconstchi2/ThreeSconstNDF<<endl; cout<<"   BIC = "<<ThreeSconstBIC<<endl;
		cout<<"3S Linear: "<<endl;
		cout<<"   p0 = "<<ThreeSslopep0<<" +- "<<ThreeSslopeerr_p0<<endl;  cout<<"   p1 = "<<ThreeSslopep1<<" +- "<<ThreeSslopeerr_p1<<endl; cout<<"   chi2 = "<<ThreeSslopechi2<<endl; cout<<"   chi2/NDF = "<<ThreeSslopechi2/ThreeSslopeNDF<<endl; cout<<"   BIC = "<<ThreeSslopeBIC<<endl;
		cout<<"3S Fixed Linear: "<<endl;
		cout<<"   p0 = "<<ThreeSfixedp0<<" +- "<<ThreeSfixederr_p0<<endl;  cout<<"   p1 = "<<ThreeSfixedp1<<" +- "<<ThreeSfixederr_p1<<endl; cout<<"   chi2 = "<<ThreeSfixedchi2<<endl; cout<<"   chi2/NDF = "<<ThreeSfixedchi2/ThreeSfixedNDF<<endl; cout<<"   BIC = "<<ThreeSfixedBIC<<endl;
		}
		}
		
		TCanvas *plotCanvas = new TCanvas("plotCanvas","plotCanvas",1250,960);
		plotCanvas->SetFillColor(kWhite);
		plotCanvas->SetFrameBorderMode(0);

		TLegend* legend;
		legend = new TLegend(0.35,0.2,0.65,0.4);
		legend->SetFillColor(0);
		legend->SetTextSize(0.08);
		legend->SetBorderSize(0);
		
		TLegend* legendCS;
		legendCS = new TLegend(0.225,0.2,0.525,0.35);
		legendCS->SetFillColor(0);
		legendCS->SetTextSize(0.08);
		legendCS->SetBorderSize(0);
		
		TLegend* legendge;
		legendge = new TLegend(0.2,0.2,0.5,0.35);
		legendge->SetFillColor(0);
		legendge->SetTextSize(0.08);
		legendge->SetBorderSize(0);

		TLine* extreme0 = new TLine( cpmmin, 0, cpmmax, 0);
		extreme0->SetLineWidth( 2 );
		extreme0->SetLineStyle( 7 );
		extreme0->SetLineColor( kBlack );
		

		char DrawChar[200];
		for(int iRap=0;iRap<nRapCMS1Smax;iRap++){
		  for(int iPt=0;iPt<nPtCMS1Smax;iPt++){
		    
			if(iPt>0) sprintf(DrawChar,"p");
			if(iPt<nPtCMS1S) {
			  if(iPt==0) {graphCMS1S[iPt]->Draw("ap"); extreme0->Draw(); if(iParameter==0){slope1s->Draw("same"); constant1s->Draw("same");fixed1s->Draw("same");}}
				graphCMS1S[iPt]->Draw("p");
			  globunctgraph1S[iPt]->Draw("2");
			  if(plotCSwithHX && iParameter==3){

			  graphCMS1SCS[iPt]->Draw("p");
			  
			  }
			  
			}  
		  }
		}
		
		for(int iRap=0;iRap<nRapCMS2Smax;iRap++){
		  for(int iPt=0;iPt<nPtCMS2Smax;iPt++){
			
			if(iPt>0 || nPtCMS1S>0) sprintf(DrawChar,"p");
			if(iPt<nPtCMS2S) {
			  if(iPt==0) {graphCMS2S[iPt]->Draw("ap"); extreme0->Draw(); if(iParameter==0){slope2s->Draw("same"); constant2s->Draw("same");fixed2s->Draw("same");}}
			  graphCMS2S[iPt]->Draw("p");
			  globunctgraph2S[iPt]->Draw("2");
			  
			  if(plotCSwithHX && iParameter==3){

			  graphCMS2SCS[iPt]->Draw("p");
			  
			  }
			}	
			
		  }
		}
		
		for(int iRap=0;iRap<nRapCMS3Smax;iRap++){
		  for(int iPt=0;iPt<nPtCMS3Smax;iPt++){
			
			if(iPt>0 || nPtCMS1S>0 || nPtCMS2S>0) sprintf(DrawChar,"p");
			if(iPt<nPtCMS3S) {
			  if(iPt==0) {graphCMS3S[iPt]->Draw("ap"); extreme0->Draw();if(iParameter==0){slope3s->Draw("same"); constant3s->Draw("same");fixed3s->Draw("same");}}
			  graphCMS3S[iPt]->Draw("p");
			  globunctgraph3S[iPt]->Draw("2");
			  
			  if(plotCSwithHX && iParameter==3){

			  graphCMS3SCS[iPt]->Draw("p");
			  
			  }
			  
			}
			if(iPt==0) legend->AddEntry(graphCMS3S[iPt],"10-15 GeV","p");
			if(iPt==1) legend->AddEntry(graphCMS3S[iPt],"15-35 GeV","p");
			if(iPt==0) legendCS->AddEntry(graphCMS3SCS[iPt],"10-15 GeV, CS frame","p");
			if(iPt==1) legendCS->AddEntry(graphCMS3SCS[iPt],"15-35 GeV, CS frame","p");
			legendge->SetLineWidth(1);
			if(iPt==0) legendge->AddEntry(globunctgraph1S[iPt],"Global unc., 10-15 GeV","f");
			if(iPt==1) legendge->AddEntry(globunctgraph1S[iPt],"Global unc., 15-35 GeV","f");
		  }
		}
		
		if(iParameter==0 && plot3S)legend->Draw("same");
		if(iParameter==2 && plot1S)legendge->Draw("same");
		if(iParameter==3 && plot2S)legendCS->Draw("same");

		//draw latex
		double left=0.175, top=0.92, textSize=0.045;
		TLatex *latex=new TLatex();
		latex->SetTextFont(42);
		latex->SetNDC(kTRUE);
		latex->SetTextSize(textSize);

		//latex->DrawLatex(left,top, "pp  #sqrt{s} = 7 TeV");
		//top=0.86;
		//latex->DrawLatex(left,top, Form("%s frame",FrameChar));
		//top=0.80;

		textSize=0.08;
		double center=0.45; double bottom=0.2;
		latex->SetTextFont(62);
		latex->SetTextSize(textSize);

		if(plot1S && iParameter==1) latex->DrawLatex(center,bottom, Form("#Upsilon(1S)"));
		if(plot2S && iParameter==1) latex->DrawLatex(center,bottom, Form("#Upsilon(2S)"));
		if(plot3S && iParameter==1) latex->DrawLatex(center,bottom, Form("#Upsilon(3S)"));

		if(iParameter==0 && plot1S){
			textSize=0.12;
			left=0.225; top=0.8;
			latex->SetTextFont(62);
			latex->SetTextSize(textSize);
			latex->DrawLatex(left,top, Form("CMS"));
			latex->SetTextSize(0.08);
			latex->DrawLatex(0.55,top, Form("4.9 fb^{-1} (7 TeV)"));
		}

		if(iParameter==1 && plot1S){
 			char frame[200];
 			sprintf(frame,"%s frame",FrameChar);
			textSize=0.1;
			left=0.225; top=0.8;
			latex->SetTextFont(62);
			latex->SetTextSize(.08);
			latex->DrawLatex(left,top, Form(frame));
		}


		//draw Y axis title using latex
		//left=0.0075; top=0.58;
		//textSize=0.065;
		left=0.004; top=0.62;
		textSize=0.09;
		latex->SetTextFont(42);
		latex->SetTextSize(textSize);
		if(iParameter==0) latex->DrawLatex(left,top, "#lambda_{#vartheta}");
		if(iParameter==1) latex->DrawLatex(left,top, "#lambda_{#varphi}");
		if(iParameter==2) latex->DrawLatex(left,top, "#lambda_{#vartheta#varphi}");
		if(iParameter==3) latex->DrawLatex(left,top, "#tilde{#lambda}");

		if(iParameter==0) plotCanvas->SaveAs(Form("MPFigures/Results_UpsnS_%s_lth_nPtCMS1S%d_nPtCMS2S%d_nPtCMS3S%d.pdf",FrameChar, nPtCMS1S, nPtCMS2S, nPtCMS3S));
		if(iParameter==1) plotCanvas->SaveAs(Form("MPFigures/Results_UpsnS_%s_lph_nPtCMS1S%d_nPtCMS2S%d_nPtCMS3S%d.pdf",FrameChar, nPtCMS1S, nPtCMS2S, nPtCMS3S));
		if(iParameter==2) plotCanvas->SaveAs(Form("MPFigures/Results_UpsnS_%s_ltp_nPtCMS1S%d_nPtCMS2S%d_nPtCMS3S%d.pdf",FrameChar, nPtCMS1S, nPtCMS2S, nPtCMS3S));
		if(iParameter==3) plotCanvas->SaveAs(Form("MPFigures/Results_UpsnS_%s_ltilde_nPtCMS1S%d_nPtCMS2S%d_nPtCMS3S%d.pdf",FrameChar, nPtCMS1S, nPtCMS2S, nPtCMS3S));
		
		}//parameter

}
