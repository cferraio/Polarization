#include "Riostream.h"
#include "TSystem.h"
#include "TString.h"
#include "TROOT.h"
#include "TTree.h"
#include "TMath.h"
#include "TVector3.h"
#include "TLorentzVector.h"
#include "TF1.h"
#include "TF2.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TProfile.h"
#include "TCanvas.h"
#include "TColor.h"
#include "TLine.h"
#include "TPolyLine.h"
#include "TEllipse.h"
#include "TStyle.h"
#include "TFile.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include "TPaveStats.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TFrame.h"




inline double contourHeight2D ( TH2D *h, double confidenceLevel ) {
  int Nx = h->GetXaxis()->GetNbins();
  int Ny = h->GetYaxis()->GetNbins();

  double totSum = h->GetSum();
  double targetSum = confidenceLevel * totSum;
  double maxHeight = h->GetMaximum();
  double step = 0.001*maxHeight;

  double tempHeight = 0.;
  double tempSum = totSum;

  while ( tempSum > targetSum && tempHeight < maxHeight ) {
    tempHeight += step;
    tempSum = 0.;
    for ( int ix = 0; ix < Nx; ix++ ) {
      for ( int iy = 0; iy < Ny; iy++ ) {
      	double binContent = h->GetBinContent(ix,iy);
        if ( binContent > tempHeight ) tempSum += binContent;
      }
    }
  }
//  cout<<"tempHeight = "<<tempHeight<<endl;
  return tempHeight;
}

inline void setContourHistogram1Sig ( TH2D *h ) {
  double cont0 = contourHeight2D( h, 0.683 );
  h->SetContour(1);
  h->SetContourLevel(0,cont0);
}

inline void setContourHistogram3Sig ( TH2D *h ) {
  double cont0 = contourHeight2D( h, 0.997 );
  h->SetContour(1);
  h->SetContourLevel(0,cont0);
}

void twodcontourplots(){

gStyle->SetOptStat(0);

double ltilde_min = -1.1;
double ltilde_max =  1.1;
double ltilde_step_1D = 0.02;
double ltilde_step_2D = 0.02;

double lph_min = -1.1;
double lph_max =  1.1;
double lph_step_1D = 0.02;
double lph_step_2D = 0.02;

double lth_min = -1.1;
double lth_max =  1.1;
double lth_step_1D = 0.02;
double lth_step_2D = 0.02;


 
char filename[200];
for(int ups = 2; ups <= 2; ups++) {
for(int pt = 1; pt <= 2; pt++) {
int n = 5;
if(ups == 3 && pt == 1) n=4;
for(int cpm = 5; cpm <= n; cpm++) {
sprintf(filename,"/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx_smallerpT2/results_%dSUps_rap1_pT%d_cpm%d.root",ups,pt,cpm);
TFile* results = new TFile(filename);
TTree* lambdaCS = (TTree*)results->Get("lambdaCS");
TTree* lambdaHX = (TTree*)results->Get("lambdaHX");
TTree* lambdaPX = (TTree*)results->Get("lambdaPX");

double lth_CS;        lambdaCS->SetBranchAddress("lth", &lth_CS);
double ltilde_CS;        lambdaCS->SetBranchAddress("ltilde", &ltilde_CS);
double lph_CS;     	     lambdaCS->SetBranchAddress("lph", &lph_CS);

double lth_HX;        lambdaHX->SetBranchAddress("lth", &lth_HX);
double ltilde_HX;        lambdaHX->SetBranchAddress("ltilde", &ltilde_HX);
double lph_HX;           lambdaHX->SetBranchAddress("lph", &lph_HX);

double lth_PX;        lambdaPX->SetBranchAddress("lth", &lth_PX);
double ltilde_PX;        lambdaPX->SetBranchAddress("ltilde", &ltilde_PX);
double lph_PX;           lambdaPX->SetBranchAddress("lph", &lph_PX);

TH2D* h_lph_vs_lth_CS = new TH2D( "h_lph_vs_lth_CS", "", int((lth_max-lth_min)/lth_step_2D), lth_min, lth_max, int((lph_max-lph_min)/lph_step_2D), lph_min, lph_max );
TH2D* h_lph_vs_ltilde_CS = new TH2D( "h_lph_vs_ltilde_CS", "", int((ltilde_max-ltilde_min)/ltilde_step_2D), ltilde_min, ltilde_max, int((lph_max-lph_min)/lph_step_2D), lph_min, lph_max );

TH2D* h_lph_vs_lth_HX = new TH2D( "h_lph_vs_lth_HX", "", int((lth_max-lth_min)/lth_step_2D), lth_min, lth_max, int((lph_max-lph_min)/lph_step_2D), lph_min, lph_max );
TH2D* h_lph_vs_ltilde_HX = new TH2D( "h_lph_vs_ltilde_HX", "", int((ltilde_max-ltilde_min)/ltilde_step_2D), ltilde_min, ltilde_max, int((lph_max-lph_min)/lph_step_2D), lph_min, lph_max );

TH2D* h_lph_vs_lth_PX = new TH2D( "h_lph_vs_lth_PX", "", int((lth_max-lth_min)/lth_step_2D), lth_min, lth_max, int((lph_max-lph_min)/lph_step_2D), lph_min, lph_max );
TH2D* h_lph_vs_ltilde_PX = new TH2D( "h_lph_vs_ltilde_PX", "", int((ltilde_max-ltilde_min)/ltilde_step_2D), ltilde_min, ltilde_max, int((lph_max-lph_min)/lph_step_2D), lph_min, lph_max );

h_lph_vs_lth_CS->SetTitle("#lambda_{#varphi}");
h_lph_vs_lth_CS->GetXaxis()->SetTitle("#lambda_{#vartheta}");
h_lph_vs_lth_PX->SetTitle("#lambda_{#varphi}");
h_lph_vs_lth_PX->GetXaxis()->SetTitle("#lambda_{#vartheta}");
h_lph_vs_lth_HX->SetTitle("#lambda_{#varphi}");
h_lph_vs_lth_HX->GetXaxis()->SetTitle("#lambda_{#vartheta}");

h_lph_vs_ltilde_CS->SetTitle("#lambda_{#varphi}");
h_lph_vs_ltilde_CS->GetXaxis()->SetTitle("#tilde{#lambda}");
h_lph_vs_ltilde_PX->SetTitle("#lambda_{#varphi}");
h_lph_vs_ltilde_PX->GetXaxis()->SetTitle("#tilde{#lambda}");
h_lph_vs_ltilde_HX->SetTitle("#lambda_{#varphi}");
h_lph_vs_ltilde_HX->GetXaxis()->SetTitle("#tilde{#lambda}");


  int n_entries = int( lambdaHX->GetEntries() );

  int n_step = n_entries/50;

  for ( int i_entry = 0; i_entry < n_entries; i_entry++ ) {

    if ( i_entry%n_step == 0 ) cout << "X";

    lambdaHX->GetEvent( i_entry );

    h_lph_vs_lth_HX->Fill( lth_HX, lph_HX );
	h_lph_vs_ltilde_HX->Fill( ltilde_HX, lph_HX);

  }

n_entries = int( lambdaPX->GetEntries() );

  n_step = n_entries/50;

  for ( int i_entry = 0; i_entry < n_entries; i_entry++ ) {

    if ( i_entry%n_step == 0 ) cout << "X";

    lambdaPX->GetEvent( i_entry );

    h_lph_vs_lth_PX->Fill( lth_PX, lph_PX );
	h_lph_vs_ltilde_PX->Fill( ltilde_PX, lph_PX);

  }

n_entries = int( lambdaCS->GetEntries() );

  n_step = n_entries/50;

  for ( int i_entry = 0; i_entry < n_entries; i_entry++ ) {

    if ( i_entry%n_step == 0 ) cout << "X";

    lambdaCS->GetEvent( i_entry );

    h_lph_vs_lth_CS->Fill( lth_CS, lph_CS );
	h_lph_vs_ltilde_CS->Fill( ltilde_CS, lph_CS);

  }

  TGraph* graph_lph_vs_lth_CS_1Sig       = NULL;
  TGraph* graph_lph_vs_lth_CS_3Sig       = NULL;
  TGraph* graph_lph_vs_lth_HX_1Sig       = NULL;
  TGraph* graph_lph_vs_lth_HX_3Sig       = NULL;
  TGraph* graph_lph_vs_lth_PX_1Sig       = NULL;
  TGraph* graph_lph_vs_lth_PX_3Sig       = NULL;
  
  TGraph* graph_lph_vs_ltilde_PX_1Sig	 = NULL;
  TGraph* graph_lph_vs_ltilde_PX_3Sig	 = NULL;
  TGraph* graph_lph_vs_ltilde_CS_1Sig	 = NULL;
  TGraph* graph_lph_vs_ltilde_CS_3Sig	 = NULL;
  TGraph* graph_lph_vs_ltilde_HX_1Sig	 = NULL;
  TGraph* graph_lph_vs_ltilde_HX_3Sig	 = NULL;
  
  TCanvas *cBuffer = new TCanvas("cBuffer", "cBuffer", 10, 28, 580,571);
  cBuffer->Range(-237.541,-66.47556,187.377,434.8609);
  cBuffer->SetFillColor(0);
  cBuffer->SetBorderMode(0);
  cBuffer->SetBorderSize(0);
  cBuffer->SetLeftMargin(0.1354167);
  cBuffer->SetRightMargin(0.01736111);
  cBuffer->SetTopMargin(0.01841621);
  cBuffer->SetBottomMargin(0.1325967);
  cBuffer->SetFrameBorderMode(0);

  
  Int_t i, j;
  Double_t x0, y0, z0;
  Double_t contours[6];
  TObjArray *conts;
  TList* contLevel = NULL;
  TGraph* curv     = NULL;
  TGraph* gc       = NULL;
  Int_t TotalConts = 0;



    
////////////////////

setContourHistogram1Sig ( h_lph_vs_ltilde_PX );
  h_lph_vs_ltilde_PX->Draw("CONT Z LIST");
  cBuffer->Update();
  conts = (TObjArray*)gROOT->GetListOfSpecials()->FindObject("contours");
  TotalConts = conts->GetSize();
  for(i = 0; i < TotalConts; i++) contLevel = (TList*)conts->At(i);
     for(i = 0; i < TotalConts; i++){
       contLevel = (TList*)conts->At(i);
       curv = (TGraph*)contLevel->First();
       for(j = 0; j < contLevel->GetSize(); j++){
          gc = (TGraph*)curv->Clone();
          curv = (TGraph*)contLevel->After(curv);
       }
   }
   cBuffer->Update();
   graph_lph_vs_ltilde_PX_1Sig= (TGraph*)gc->Clone();

   setContourHistogram3Sig ( h_lph_vs_ltilde_PX );
   h_lph_vs_ltilde_PX->Draw("CONT Z LIST");
   cBuffer->Update();
   conts = (TObjArray*)gROOT->GetListOfSpecials()->FindObject("contours");
   TotalConts = conts->GetSize();
   for(i = 0; i < TotalConts; i++) contLevel = (TList*)conts->At(i);
      for(i = 0; i < TotalConts; i++){
        contLevel = (TList*)conts->At(i);
        curv = (TGraph*)contLevel->First();
        for(j = 0; j < contLevel->GetSize(); j++){
           gc = (TGraph*)curv->Clone();
           curv = (TGraph*)contLevel->After(curv);
        }
    }
    cBuffer->Update();
    graph_lph_vs_ltilde_PX_3Sig= (TGraph*)gc->Clone();
    
/////////

setContourHistogram1Sig ( h_lph_vs_ltilde_CS );
  h_lph_vs_ltilde_CS->Draw("CONT Z LIST");
  cBuffer->Update();
  conts = (TObjArray*)gROOT->GetListOfSpecials()->FindObject("contours");
  TotalConts = conts->GetSize();
  for(i = 0; i < TotalConts; i++) contLevel = (TList*)conts->At(i);
     for(i = 0; i < TotalConts; i++){
       contLevel = (TList*)conts->At(i);
       curv = (TGraph*)contLevel->First();
       for(j = 0; j < contLevel->GetSize(); j++){
          gc = (TGraph*)curv->Clone();
          curv = (TGraph*)contLevel->After(curv);
       }
   }
   cBuffer->Update();
   graph_lph_vs_ltilde_CS_1Sig= (TGraph*)gc->Clone();

   setContourHistogram3Sig ( h_lph_vs_ltilde_CS );
   h_lph_vs_ltilde_CS->Draw("CONT Z LIST");
   cBuffer->Update();
   conts = (TObjArray*)gROOT->GetListOfSpecials()->FindObject("contours");
   TotalConts = conts->GetSize();
   for(i = 0; i < TotalConts; i++) contLevel = (TList*)conts->At(i);
      for(i = 0; i < TotalConts; i++){
        contLevel = (TList*)conts->At(i);
        curv = (TGraph*)contLevel->First();
        for(j = 0; j < contLevel->GetSize(); j++){
           gc = (TGraph*)curv->Clone();
           curv = (TGraph*)contLevel->After(curv);
        }
    }
    cBuffer->Update();
    graph_lph_vs_ltilde_CS_3Sig= (TGraph*)gc->Clone();
    
    
///////////    

setContourHistogram1Sig ( h_lph_vs_ltilde_HX );
  h_lph_vs_ltilde_HX->Draw("CONT Z LIST");
  cBuffer->Update();
  conts = (TObjArray*)gROOT->GetListOfSpecials()->FindObject("contours");
  TotalConts = conts->GetSize();
  for(i = 0; i < TotalConts; i++) contLevel = (TList*)conts->At(i);
     for(i = 0; i < TotalConts; i++){
       contLevel = (TList*)conts->At(i);
       curv = (TGraph*)contLevel->First();
       for(j = 0; j < contLevel->GetSize(); j++){
          gc = (TGraph*)curv->Clone();
          curv = (TGraph*)contLevel->After(curv);
       }
   }
   cBuffer->Update();
   graph_lph_vs_ltilde_HX_1Sig= (TGraph*)gc->Clone();

   setContourHistogram3Sig ( h_lph_vs_ltilde_HX );
   h_lph_vs_ltilde_HX->Draw("CONT Z LIST");
   cBuffer->Update();
   conts = (TObjArray*)gROOT->GetListOfSpecials()->FindObject("contours");
   TotalConts = conts->GetSize();
   for(i = 0; i < TotalConts; i++) contLevel = (TList*)conts->At(i);
      for(i = 0; i < TotalConts; i++){
        contLevel = (TList*)conts->At(i);
        curv = (TGraph*)contLevel->First();
        for(j = 0; j < contLevel->GetSize(); j++){
           gc = (TGraph*)curv->Clone();
           curv = (TGraph*)contLevel->After(curv);
        }
    }
    cBuffer->Update();
    graph_lph_vs_ltilde_HX_3Sig= (TGraph*)gc->Clone();

/////////////
  
  graph_lph_vs_ltilde_PX_1Sig->SetLineWidth(2);
  graph_lph_vs_ltilde_PX_1Sig->SetLineColor(2);
  graph_lph_vs_ltilde_PX_1Sig->SetLineStyle(1);
  graph_lph_vs_ltilde_PX_1Sig->Draw("C");
  
  graph_lph_vs_ltilde_PX_3Sig->SetLineWidth(2);
  graph_lph_vs_ltilde_PX_3Sig->SetLineColor(2);
  graph_lph_vs_ltilde_PX_3Sig->SetLineStyle(2);
  graph_lph_vs_ltilde_PX_3Sig->Draw("C");
   
  graph_lph_vs_ltilde_CS_1Sig->SetLineWidth(2);
  graph_lph_vs_ltilde_CS_1Sig->SetLineColor(3);
  graph_lph_vs_ltilde_CS_1Sig->SetLineStyle(1);
  graph_lph_vs_ltilde_CS_1Sig->Draw("C");
  
  graph_lph_vs_ltilde_CS_3Sig->SetLineWidth(2);
  graph_lph_vs_ltilde_CS_3Sig->SetLineColor(3);
  graph_lph_vs_ltilde_CS_3Sig->SetLineStyle(2);
  graph_lph_vs_ltilde_CS_3Sig->Draw("C");
  
  graph_lph_vs_ltilde_HX_1Sig->SetLineWidth(2);
  graph_lph_vs_ltilde_HX_1Sig->SetLineColor(4);
  graph_lph_vs_ltilde_HX_1Sig->SetLineStyle(1);
  graph_lph_vs_ltilde_HX_1Sig->Draw("C");
  
  graph_lph_vs_ltilde_HX_3Sig->SetLineWidth(2);
  graph_lph_vs_ltilde_HX_3Sig->SetLineColor(4);
  graph_lph_vs_ltilde_HX_3Sig->SetLineStyle(2);
  graph_lph_vs_ltilde_HX_3Sig->Draw("C");
  
  leg = new TLegend(0.25,0.7,0.48,0.9);
  leg->AddEntry(graph_lph_vs_ltilde_CS_1Sig,"CS","l");
  leg->AddEntry(graph_lph_vs_ltilde_PX_1Sig,"PX","l");
  leg->AddEntry(graph_lph_vs_ltilde_HX_1Sig,"HX","l");
  leg->Draw();
  
  char pdfname[200];
  sprintf(pdfname,"contour/lph_vs_ltilde_ups%ds_pt%d_cpm%d.pdf",ups,pt,cpm);
  cBuffer->SaveAs(pdfname);
 
  
  TCanvas *cBuffer2 = new TCanvas("cBuffer22", "cBuffer22", 10, 28, 580,571);
  cBuffer2->Range(-237.541,-66.47556,187.377,434.8609);
  cBuffer2->SetFillColor(0);
  cBuffer2->SetBorderMode(0);
  cBuffer2->SetBorderSize(0);
  cBuffer2->SetLeftMargin(0.1354167);
  cBuffer2->SetRightMargin(0.01736111);
  cBuffer2->SetTopMargin(0.01841621);
  cBuffer2->SetBottomMargin(0.1325967);
  cBuffer2->SetFrameBorderMode(0);
  
  setContourHistogram1Sig ( h_lph_vs_lth_PX );
  h_lph_vs_lth_PX->Draw("CONT Z LIST");
  cBuffer2->Update();
  conts = (TObjArray*)gROOT->GetListOfSpecials()->FindObject("contours");
  TotalConts = conts->GetSize();
  for(i = 0; i < TotalConts; i++) contLevel = (TList*)conts->At(i);
     for(i = 0; i < TotalConts; i++){
       contLevel = (TList*)conts->At(i);
       curv = (TGraph*)contLevel->First();
       for(j = 0; j < contLevel->GetSize(); j++){
          gc = (TGraph*)curv->Clone();
          curv = (TGraph*)contLevel->After(curv);
       }
   }
   cBuffer2->Update();
   graph_lph_vs_lth_PX_1Sig= (TGraph*)gc->Clone();

   setContourHistogram3Sig ( h_lph_vs_lth_PX );
   h_lph_vs_lth_PX->Draw("CONT Z LIST");
   cBuffer2->Update();
   conts = (TObjArray*)gROOT->GetListOfSpecials()->FindObject("contours");
   TotalConts = conts->GetSize();
   for(i = 0; i < TotalConts; i++) contLevel = (TList*)conts->At(i);
      for(i = 0; i < TotalConts; i++){
        contLevel = (TList*)conts->At(i);
        curv = (TGraph*)contLevel->First();
        for(j = 0; j < contLevel->GetSize(); j++){
           gc = (TGraph*)curv->Clone();
           curv = (TGraph*)contLevel->After(curv);
        }
    }
    cBuffer2->Update();
    graph_lph_vs_lth_PX_3Sig= (TGraph*)gc->Clone();
    
/////////

setContourHistogram1Sig ( h_lph_vs_lth_CS );
  h_lph_vs_lth_CS->Draw("CONT Z LIST");
  cBuffer2->Update();
  conts = (TObjArray*)gROOT->GetListOfSpecials()->FindObject("contours");
  TotalConts = conts->GetSize();
  for(i = 0; i < TotalConts; i++) contLevel = (TList*)conts->At(i);
     for(i = 0; i < TotalConts; i++){
       contLevel = (TList*)conts->At(i);
       curv = (TGraph*)contLevel->First();
       for(j = 0; j < contLevel->GetSize(); j++){
          gc = (TGraph*)curv->Clone();
          curv = (TGraph*)contLevel->After(curv);
       }
   }
   cBuffer2->Update();
   graph_lph_vs_lth_CS_1Sig= (TGraph*)gc->Clone();

   setContourHistogram3Sig ( h_lph_vs_lth_CS );
   h_lph_vs_lth_CS->Draw("CONT Z LIST");
   cBuffer2->Update();
   conts = (TObjArray*)gROOT->GetListOfSpecials()->FindObject("contours");
   TotalConts = conts->GetSize();
   for(i = 0; i < TotalConts; i++) contLevel = (TList*)conts->At(i);
      for(i = 0; i < TotalConts; i++){
        contLevel = (TList*)conts->At(i);
        curv = (TGraph*)contLevel->First();
        for(j = 0; j < contLevel->GetSize(); j++){
           gc = (TGraph*)curv->Clone();
           curv = (TGraph*)contLevel->After(curv);
        }
    }
    cBuffer2->Update();
    graph_lph_vs_lth_CS_3Sig= (TGraph*)gc->Clone();
    
    
///////////    

setContourHistogram1Sig ( h_lph_vs_lth_HX );
  h_lph_vs_lth_HX->Draw("CONT Z LIST");
  cBuffer2->Update();
  conts = (TObjArray*)gROOT->GetListOfSpecials()->FindObject("contours");
  TotalConts = conts->GetSize();
  for(i = 0; i < TotalConts; i++) contLevel = (TList*)conts->At(i);
     for(i = 0; i < TotalConts; i++){
       contLevel = (TList*)conts->At(i);
       curv = (TGraph*)contLevel->First();
       for(j = 0; j < contLevel->GetSize(); j++){
          gc = (TGraph*)curv->Clone();
          curv = (TGraph*)contLevel->After(curv);
       }
   }
   cBuffer2->Update();
   graph_lph_vs_lth_HX_1Sig= (TGraph*)gc->Clone();

   setContourHistogram3Sig ( h_lph_vs_lth_HX );
   h_lph_vs_lth_HX->Draw("CONT Z LIST");
   cBuffer2->Update();
   conts = (TObjArray*)gROOT->GetListOfSpecials()->FindObject("contours");
   TotalConts = conts->GetSize();
   for(i = 0; i < TotalConts; i++) contLevel = (TList*)conts->At(i);
      for(i = 0; i < TotalConts; i++){
        contLevel = (TList*)conts->At(i);
        curv = (TGraph*)contLevel->First();
        for(j = 0; j < contLevel->GetSize(); j++){
           gc = (TGraph*)curv->Clone();
           curv = (TGraph*)contLevel->After(curv);
        }
    }
    cBuffer2->Update();
    graph_lph_vs_lth_HX_3Sig= (TGraph*)gc->Clone();

/////////////
  
  graph_lph_vs_lth_PX_1Sig->SetLineWidth(2);
  graph_lph_vs_lth_PX_1Sig->SetLineColor(2);
  graph_lph_vs_lth_PX_1Sig->SetLineStyle(1);
  graph_lph_vs_lth_PX_1Sig->Draw("C");
  
  graph_lph_vs_lth_PX_3Sig->SetLineWidth(2);
  graph_lph_vs_lth_PX_3Sig->SetLineColor(2);
  graph_lph_vs_lth_PX_3Sig->SetLineStyle(2);
  graph_lph_vs_lth_PX_3Sig->Draw("C");
   
  graph_lph_vs_lth_CS_1Sig->SetLineWidth(2);
  graph_lph_vs_lth_CS_1Sig->SetLineColor(3);
  graph_lph_vs_lth_CS_1Sig->SetLineStyle(1);
  graph_lph_vs_lth_CS_1Sig->Draw("C");
  
  graph_lph_vs_lth_CS_3Sig->SetLineWidth(2);
  graph_lph_vs_lth_CS_3Sig->SetLineColor(3);
  graph_lph_vs_lth_CS_3Sig->SetLineStyle(2);
  graph_lph_vs_lth_CS_3Sig->Draw("C");
  
  graph_lph_vs_lth_HX_1Sig->SetLineWidth(2);
  graph_lph_vs_lth_HX_1Sig->SetLineColor(4);
  graph_lph_vs_lth_HX_1Sig->SetLineStyle(1);
  graph_lph_vs_lth_HX_1Sig->Draw("C");
  
  graph_lph_vs_lth_HX_3Sig->SetLineWidth(2);
  graph_lph_vs_lth_HX_3Sig->SetLineColor(4);
  graph_lph_vs_lth_HX_3Sig->SetLineStyle(2);
  graph_lph_vs_lth_HX_3Sig->Draw("C");
  
  leg = new TLegend(0.25,0.7,0.48,0.9);
  leg->AddEntry(graph_lph_vs_lth_CS_1Sig,"CS","l");
  leg->AddEntry(graph_lph_vs_lth_PX_1Sig,"PX","l");
  leg->AddEntry(graph_lph_vs_lth_HX_1Sig,"HX","l");
  leg->Draw();
  
  char pdfname[200];
  sprintf(pdfname,"contour/lph_vs_lth_ups%ds_pt%d_cpm%d.pdf",ups,pt,cpm);
  cBuffer2->SaveAs(pdfname);
  
 } //end pt
} //end cpm
} //end ups






}