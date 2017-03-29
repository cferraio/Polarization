{
//TFile f("/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx_withsys/TGraphResults_1SUps.root");
//TFile f("/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx_withsys/TGraphResults_2SUps.root");
TFile f("/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx_withsys/TGraphResults_3SUps.root");

//double cpmCentre[2][5]={{6.60749, 14.9818, 24.5746, 34.4256, 46.9465},{6.9573, 15.2325, 24.6739, 34.4821, 46.9327}};
//double cpmCentre[2][5]={{6.55258, 15.0001, 24.5743, 34.4049, 46.824},{6.9774, 15.2256, 24.7153, 34.5299, 46.8986}};
//double cpmCentre[2][5]={{6.52592, 14.9239, 24.5347, 34.3604, 46.9122},{6.89134, 15.1033, 24.6676, 34.3945, 46.9769}};
double cpmCentre[2][4]={{6.52592, 14.9239, 24.5347, 39.1154},{6.89134, 15.1033, 24.6676, 39.2905}};

double systcpmcenter[5]={5,15,25,35,50};
double systcpmlow[5]={5,5,5,5,10};
double systcpmhigh[5]={5,5,5,5,10};
//double systcpmcenter[4]={5,15,25,45};
//double systcpmlow[4]={5,5,5,15};
//double systcpmhigh[4]={5,5,5,15};

/*  double cpmcenter[5];
  double cpmlow[5];
  double cpmhigh[5];
  double lmeanCSminHX[5];
  double lmeanHXminPX[5]; 
  double lmeanPXminCS[5]; 
  double lamtildeCS[2][5];
  double lamtildeHX[2][5];
  double lamtildePX[2][5];
*/
  double cpmcenter[4];
  double cpmlow[4];
  double cpmhigh[4];
  double lmeanCSminHX[4];
  double lmeanHXminPX[4]; 
  double lmeanPXminCS[4];  
  double lamtildeCS[2][4];
  double lamtildeHX[2][4];
  double lamtildePX[2][4];

  
for(int pt = 0; pt < 1; pt++) {
//for(int pt = 1; pt < 2; pt++) {
  for(int cpm = 0; cpm < 4; cpm++) {
  double cpmcenter[cpm] = cpmCentre[pt][cpm];
  lamtildeCS[pt][cpm]=ltilde_CS_rap1_pt1->Eval(cpmCentre[pt][cpm]);
  lamtildeHX[pt][cpm]=ltilde_HX_rap1_pt1->Eval(cpmCentre[pt][cpm]);
  lamtildePX[pt][cpm]=ltilde_PX_rap1_pt1->Eval(cpmCentre[pt][cpm]);

//  lamtildeCS[pt][cpm]=ltilde_CS_rap1_pt2->Eval(cpmCentre[pt][cpm]);
//  lamtildeHX[pt][cpm]=ltilde_HX_rap1_pt2->Eval(cpmCentre[pt][cpm]);
//  lamtildePX[pt][cpm]=ltilde_PX_rap1_pt2->Eval(cpmCentre[pt][cpm]);
  
  lmeanCSminHX[cpm]=lamtildeCS[pt][cpm]-lamtildeHX[pt][cpm];
  lmeanHXminPX[cpm]=lamtildeHX[pt][cpm]-lamtildePX[pt][cpm];
  lmeanPXminCS[cpm]=lamtildePX[pt][cpm]-lamtildeCS[pt][cpm];
  cout<<lmeanPXminCS[cpm]<<endl;
  }
}

TCanvas *plotCanvas = new TCanvas("plotCanvas","plotCanvas",1000,800);
plotCanvas->SetFillColor(kWhite);
		plotCanvas->GetFrame()->SetFillColor(kWhite);
		plotCanvas->GetFrame()->SetBorderSize(0);
		plotCanvas->SetRightMargin(0.05) ;
		blah = plotCanvas->DrawFrame(0,-1.,60.,1.);
		blah->SetXTitle("N_{ch}");
		blah->SetYTitle("\\Delta\\tilde\\lambda");

//TGraphAsymmErrors *CSminHX = new TGraphAsymmErrors(5,cpmcenter,lmeanCSminHX,0,0,0,0);
TGraphAsymmErrors *CSminHX = new TGraphAsymmErrors(4,cpmcenter,lmeanCSminHX,0,0,0,0);
CSminHX->SetName("dltildeCSminHX");

CSminHX->GetYaxis()->SetRangeUser(-1.,1.);
CSminHX->SetLineColor(2);
CSminHX->SetLineWidth(2);

//TGraphAsymmErrors *HXminPX = new TGraphAsymmErrors(5,cpmcenter,lmeanHXminPX,0,0,0,0);
TGraphAsymmErrors *HXminPX = new TGraphAsymmErrors(4,cpmcenter,lmeanHXminPX,0,0,0,0);
HXminPX->SetName("dltildeHXminPX");

HXminPX->SetLineColor(3);
HXminPX->SetLineWidth(2);

//TGraphAsymmErrors *PXminCS = new TGraphAsymmErrors(5,cpmcenter,lmeanPXminCS,0,0,0,0);
TGraphAsymmErrors *PXminCS = new TGraphAsymmErrors(4,cpmcenter,lmeanPXminCS,0,0,0,0);
PXminCS->SetName("dltildePXminCS");
PXminCS->SetLineColor(4);
PXminCS->SetLineWidth(2);

/*double systlow[5];
double systhigh[5];
double systerrorhigh[5];
double systerrorlow[5];
*/
double systlow[4];
double systhigh[4];
double systerrorhigh[4];
double systerrorlow[4];

//TFile f("Systematics/cutNPriVtx/AverageSyst/TGraphResults_1SUps.root");
//TFile f("Systematics/cutNPriVtx/AverageSyst/TGraphResults_2SUps.root");
TFile f("Systematics/cutNPriVtx/AverageSyst/TGraphResults_3SUps.root");

for(int pt = 0; pt < 1; pt++) {
//for(int pt = 1; pt < 2; pt++) {
  for(int cpm = 0; cpm < 4; cpm++) {
    systhigh[cpm]=0;
    systerrorhigh[cpm]=ltilde_PX_rap1_pt1->Eval(cpmCentre[pt][cpm]);

//    systerrorhigh[cpm]=ltilde_PX_rap1_pt2->Eval(cpmCentre[pt][cpm]);
	cout<<systerrorhigh[cpm]<<endl;
}
}
    systerrorhigh[4]=ltilde_PX_rap1_pt1->Eval(cpmCentre[0][3]);
//TGraphAsymmErrors *Systhigh = new TGraphAsymmErrors(5,systcpmcenter,systhigh,systcpmlow,systcpmhigh,systerrorhigh,systerrorhigh);
TGraphAsymmErrors *Systhigh = new TGraphAsymmErrors(5,systcpmcenter,systhigh,systcpmlow,systcpmhigh,systerrorhigh,systerrorhigh);
Systhigh->SetName("systhigh");
Systhigh->SetFillColor(kOrange);
Systhigh->SetLineColor(kOrange);
Systhigh->SetLineWidth(5);

plotCanvas->Draw();
Systhigh->Draw("2");
CSminHX->Draw("same");
HXminPX->Draw("same");
PXminCS->Draw("same");

TLegend* plotcompLegend=new TLegend(0.13,0.12,0.45,0.35);
		plotcompLegend->SetFillColor(0);
		plotcompLegend->SetTextSize(0.04);
		plotcompLegend->SetBorderSize(1);
		plotcompLegend->AddEntry(Systhigh,"TotalSystematic","f");
		plotcompLegend->AddEntry(CSminHX,"\\tilde\\lambda_{CS}-\\tilde\\lambda_{HX}","l");
		plotcompLegend->AddEntry(HXminPX,"\\tilde\\lambda_{HX}-\\tilde\\lambda_{PX}","l");
		plotcompLegend->AddEntry(PXminCS,"\\tilde\\lambda_{PX}-\\tilde\\lambda_{CS}","l");
		plotcompLegend->Draw();

//plotCanvas->SaveAs("Systematics_PX_Deltatilde_rap1_pt1_Ups1S.pdf");
//plotCanvas->SaveAs("Systematics_PX_Deltatilde_rap1_pt2_Ups1S.pdf");
//plotCanvas->SaveAs("Systematics_PX_Deltatilde_rap1_pt1_Ups2S.pdf");
//plotCanvas->SaveAs("Systematics_PX_Deltatilde_rap1_pt2_Ups2S.pdf");
plotCanvas->SaveAs("Systematics_PX_Deltatilde_rap1_pt1_Ups3S.pdf");
//plotCanvas->SaveAs("Systematics_PX_Deltatilde_rap1_pt2_Ups3S.pdf");

}
