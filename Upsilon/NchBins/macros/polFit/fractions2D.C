//this file is the output of polData.C -> same exact code used for the analysis, 
//just with added functionality to plot Nch distros in nPriVtx bins

{

TFile* file1 = new TFile("../DataFiles/SetOfCuts11_smallerpT2/tmpFiles/selEvents_data_Ups.root");
//TFile* file2 = new TFile("../DataFiles/SetOfCuts11_cutPriVtx_at1/tmpFiles/selEvents_data_Ups.root");
//TFile* file2 = new TFile("../DataFiles/SetOfCuts11_cutNPriVtx_at10/tmpFiles/selEvents_data_Ups.root");
TFile* file2 = new TFile("../DataFiles/SetOfCuts11_cutPriVtx_at5/tmpFiles/selEvents_data_Ups.root");

Double_t XSecIntegralcut16[5][25];
Double_t XSecIntegralErrorcut16[5][25];
Double_t XSecFraction0cut16[25];
Double_t XSecFraction1cut16[25];
Double_t XSecFraction2cut16[25];
Double_t XSecFraction3cut16[25];
Double_t XSecFraction4cut16[25];
Double_t XSecFractionError0cut16[25];
Double_t XSecFractionError1cut16[25];
Double_t XSecFractionError2cut16[25];
Double_t XSecFractionError3cut16[25];
Double_t XSecFractionError4cut16[25];
Double_t total16[5];
Double_t totale16[5];

Double_t XSecIntegralcut10[5][25];
Double_t XSecIntegralErrorcut10[5][25];
Double_t XSecFraction0cut10[25];
Double_t XSecFraction1cut10[25];
Double_t XSecFraction2cut10[25];
Double_t XSecFraction3cut10[25];
Double_t XSecFraction4cut10[25];
Double_t XSecFractionError0cut10[25];
Double_t XSecFractionError1cut10[25];
Double_t XSecFractionError2cut10[25];
Double_t XSecFractionError3cut10[25];
Double_t XSecFractionError4cut10[25];
Double_t total10[5];
Double_t totale10[5];

char PUhisto[200];
Double_t buffer16[5];
Double_t buffer10[5];
for(int Nchbin = 0; Nchbin < 5; Nchbin++)
{
  total16[Nchbin] = 0;
  buffer16[Nchbin] = 0;
  
  for(int PUbin = 0; PUbin < 16; PUbin++)
  {
    sprintf(PUhisto,"Reco_Onia_CPM%d_PU_%d",Nchbin,PUbin);
    theGraph = (TH1F*) file1->Get(PUhisto);
    XSecIntegralcut16[Nchbin][PUbin]=theGraph->Integral();
    total16[Nchbin]+=XSecIntegralcut16[Nchbin][PUbin];
    theGraph->IntegralAndError(0,-1,XSecIntegralErrorcut16[Nchbin][PUbin]);
	buffer16[Nchbin]+=XSecIntegralErrorcut16[Nchbin][PUbin]*XSecIntegralErrorcut16[Nchbin][PUbin];
  }
}

for(int Nchbin = 0; Nchbin < 5; Nchbin++)
{
  total10[Nchbin] = 0;
  buffer10[Nchbin] = 0;
  
  for(int PUbin = 0; PUbin < 10; PUbin++)
  {
    sprintf(PUhisto,"Reco_Onia_CPM%d_PU_%d",Nchbin,PUbin);
    theGraph = (TH1F*) file2->Get(PUhisto);
    XSecIntegralcut10[Nchbin][PUbin]=theGraph->Integral();
    total10[Nchbin]+=XSecIntegralcut10[Nchbin][PUbin];
    theGraph->IntegralAndError(0,-1,XSecIntegralErrorcut10[Nchbin][PUbin]);
    buffer10[Nchbin]+=XSecIntegralErrorcut10[Nchbin][PUbin]*XSecIntegralErrorcut10[Nchbin][PUbin];
  }
}

Double_t ratio[5];
Double_t ratioe[5];
Double_t cpmbin[5];
for(int Nchbin = 0; Nchbin < 5; Nchbin++)
{
  cpmbin[Nchbin]=Nchbin+1;
  totale16[Nchbin]=sqrt(buffer16[Nchbin]);
  totale10[Nchbin]=sqrt(buffer10[Nchbin]); 
  ratio[Nchbin]=(total10[Nchbin])/(total16[Nchbin]);
  ratioe[Nchbin]=ratio[Nchbin]*sqrt(pow(totale16[Nchbin]/total16[Nchbin],2)+pow(totale10[Nchbin]/total10[Nchbin],2));
}






 TCanvas *c1 = new TCanvas("Fraction of cross section vs. PU","Fraction of cross section vs. PU",600,400);
// TH1F *hFrame = gPad->DrawFrame(0, 0.75, 6, .85);
 TH1F *hFrame = gPad->DrawFrame(0, 0.25, 6, .35);
//TH1F *hFrame = gPad->DrawFrame(0, 0.005, 6, .01);
 hFrame->SetXTitle("N_{ch} Bin");
// hFrame->SetTitle("Ratio of number of events with nPriVtx cut 1/16");
  hFrame->SetTitle("Ratio of number of events with nPriVtx cut 5/16");
//   hFrame->SetTitle("Ratio of number of events with nPriVtx cut 10/16");
 hFrame->SetYTitle("Events Ratio");
 hFrame->GetYaxis()->SetTitleOffset(1.2);
//hFrame->GetYaxis()->SetTitleOffset(1.4);
 hFrame->Draw();

 graph = new TGraphErrors(5,cpmbin,ratio,0,ratioe);
 graph->SetMarkerStyle(20);
 graph->Draw("p");


 c1->SaveAs("CrossSectionFractionRatioat5.pdf");

}
