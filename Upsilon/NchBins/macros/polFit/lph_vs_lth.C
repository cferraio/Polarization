

{

TFile f("/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx_withsys/results_1SUps_rap1_pT1_cpm1.root");
TTree *aTree=(TTree*)f->Get("Results");

   TCanvas *c1 = new TCanvas("c1", "c1",0,0,580,571);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   c1->SetHighLightColor(2);
   c1->Range(-1.451639,-1.443601,1.145082,1.147722);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(0);
   c1->SetLeftMargin(0.1354167);
   c1->SetRightMargin(0.01736111);
   c1->SetTopMargin(0.01841621);
   c1->SetBottomMargin(0.1325967);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH2D *h_lph_vs_lth = new TH2D("h_lph_vs_lth","",110,-1.1,1.1,110,-1.1,1.1);
   h_lph_vs_lth->GetXaxis()->SetTitle("#lambda_{#vartheta}");
   h_lph_vs_lth->GetXaxis()->SetLabelOffset(0.028);
   h_lph_vs_lth->GetXaxis()->SetTitleSize(0.05);
   h_lph_vs_lth->GetXaxis()->SetTickLength(-0.03);
   h_lph_vs_lth->GetXaxis()->SetTitleOffset(1.15);
   h_lph_vs_lth->GetYaxis()->SetTitle("#lambda_{#varphi}");
   h_lph_vs_lth->GetYaxis()->SetLabelOffset(0.032);
   h_lph_vs_lth->GetYaxis()->SetTitleSize(0.05);
   h_lph_vs_lth->GetYaxis()->SetTickLength(-0.03);
   h_lph_vs_lth->GetYaxis()->SetTitleOffset(1.3);
   h_lph_vs_lth->Draw("");
   
   Double_t *dum = 0;
   TPolyLine *pline = new TPolyLine(4,dum,dum,"");

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#cccccc");
   pline->SetFillColor(ci);
   pline->SetLineStyle(0);
   pline->SetPoint(0,-1.09,-1.09);
   pline->SetPoint(1,-1.09,1.09);
   pline->SetPoint(2,1.09,1.09);
   pline->SetPoint(3,1.09,-1.09);
   pline->Draw("f same");
   
   Double_t *dum = 0;
   pline = new TPolyLine(3,dum,dum,"");
   pline->SetLineStyle(0);
   pline->SetPoint(0,-1,0);
   pline->SetPoint(1,1,-1);
   pline->SetPoint(2,1,1);
   pline->Draw("f same");
   TLine *line = new TLine(-1.1,1,1.1,1);

   ci = TColor::GetColor("#666666");
   line->SetLineColor(ci);
   line->SetLineStyle(2);
   line->Draw();
   line = new TLine(-1.1,-1,1.1,-1);

   ci = TColor::GetColor("#666666");
   line->SetLineColor(ci);
   line->SetLineStyle(2);
   line->Draw();
   line = new TLine(-1.1,0,1.1,0);

   ci = TColor::GetColor("#666666");
   line->SetLineColor(ci);
   line->SetLineStyle(2);
   line->Draw();
   line = new TLine(1,-1.1,1,1.1);

   ci = TColor::GetColor("#666666");
   line->SetLineColor(ci);
   line->SetLineStyle(2);
   line->Draw();
   line = new TLine(-1,-1.1,-1,1.1);

   ci = TColor::GetColor("#666666");
   line->SetLineColor(ci);
   line->SetLineStyle(2);
   line->Draw();
   line = new TLine(0,-1.1,0,1.1);

   ci = TColor::GetColor("#666666");
   line->SetLineColor(ci);
   line->SetLineStyle(2);
   line->Draw();
   
   TGraph *graph = new TGraph(50);
   graph->SetName("Graph");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   ci = TColor::GetColor("#ff0000");
   graph->SetMarkerColor(3);
   graph->SetMarkerSize(.5);
   graph->SetMarkerStyle(20);
   
   TGraph *graph2 = new TGraph(50);
   graph2->SetName("Graph2");
   graph2->SetTitle("Graph2");
   graph2->SetFillColor(1);
   ci = TColor::GetColor("#ff0000");
   graph2->SetMarkerColor(2);
   graph2->SetMarkerSize(.5);
   graph2->SetMarkerStyle(20);
   
   TGraph *graph3 = new TGraph(50);
   graph3->SetName("Graph3");
   graph3->SetTitle("Graph3");
   graph3->SetFillColor(1);
   ci = TColor::GetColor("#ff0000");
   graph3->SetMarkerColor(4);
   graph3->SetMarkerSize(.5);
   graph3->SetMarkerStyle(20);
//   graph3->SetLineColor(ci);
//   graph3->SetLineStyle(2);
//   graph3->SetLineWidth(4);
 
 double lthCS[50];
 double lphCS[50];
 double lthPX[50];
 double lphPX[50];
 double lthHX[50];
 double lphHX[50];

Double_t lthcs;
Double_t lphcs;
Double_t lthpx;
Double_t lphpx;
Double_t lthhx;
Double_t lphhx;
aTree->SetBranchAddress("lthCS",&lthcs);
aTree->SetBranchAddress("lphCS",&lphcs);
aTree->SetBranchAddress("lthHX",&lthhx);
aTree->SetBranchAddress("lphHX",&lphhx);
aTree->SetBranchAddress("lthPX",&lthpx);
aTree->SetBranchAddress("lphPX",&lphpx);

for(int nentries = 0; nentries < 50; nentries++)
{
 aTree->GetEntry(nentries);
 lthCS[nentries] = lthcs;
 lphCS[nentries] = lphcs;
 graph->SetPoint(nentries,lthcs,lphcs);
} 

graph->Draw("cont2");

   
for(int nentries = 0; nentries < 50; nentries++)
{
 aTree->GetEntry(nentries);
 lthHX[nentries] = lthhx;
 lphHX[nentries] = lphhx;
 graph2->SetPoint(nentries,lthhx,lphhx);
} 
graph2->Draw("p");

   
   
for(int nentries = 0; nentries < 50; nentries++)
{
 aTree->GetEntry(nentries);
 lthPX[nentries] = lthpx;
 lphPX[nentries] = lphpx;
 graph3->SetPoint(nentries,lthpx,lphpx);
} 
graph3->Draw("p");

 	 TLegend* plotLegend=new TLegend(0.15,0.8,0.25,0.95);
    	 plotLegend->SetFillColor(kWhite);
//    	 plotLegend->SetTextFont(72);
    	 plotLegend->SetTextSize(0.035);
    	 plotLegend->SetBorderSize(1);
    	 char legendentry[200];
    	 sprintf(legendentry,"CS");
    	 plotLegend->AddEntry(graph,legendentry,"p");
    	 sprintf(legendentry,"HX");
    	 plotLegend->AddEntry(graph2,legendentry,"p");
    	 sprintf(legendentry,"PX");
    	 plotLegend->AddEntry(graph3,legendentry,"p");
    	 plotLegend->Draw(); plotLegend->Draw();

}