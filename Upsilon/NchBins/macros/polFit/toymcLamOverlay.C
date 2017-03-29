{
 Double_t  cpmCenter;
Double_t  lmean;
 
 for(int frame = 0; frame < 3; frame++) {
  
  char framename[200];
  if(frame == 0) sprintf(framename,"CS");
  if(frame == 1) sprintf(framename,"HX");
  if(frame == 2) sprintf(framename,"PX");
 
  for(int lam = 0; lam < 4; lam++) {
   char lamname[200];
   if(lam == 0 ) sprintf(lamname,"lth");
   if(lam == 1 ) sprintf(lamname,"lph");
   if(lam == 2 ) sprintf(lamname,"ltp");
   if(lam == 3 ) sprintf(lamname,"ltilde");
    c1 = new TCanvas("c1","c1",700,500);
   
   leg = new TLegend(0.15,0.7,0.35,0.85);
   leg->SetFillColor(0);
   
   
   TFile *_file0 = TFile::Open("/data/users/ferraioc/Polarization/Modified/ToyMC/pTBGSubRatioIssue_a/Sig_frame3scen3_Bkg_frame3scen9/TGraphResults_3SUps.root");
  
   char tgraphname[200];
   sprintf(tgraphname,"%s_%s_rap1_pt2",lamname,framename);
   cout<<tgraphname<<endl;
   theTGraph = (TGraphAsymmErrors*) _file0->Get(tgraphname);
//   
   if(lam == 2) theTGraph->GetYaxis()->SetRangeUser(-.04,.04);
   if(lam == 1) theTGraph->GetYaxis()->SetRangeUser(-.1,.02);
   if(lam == 0 || lam == 3) theTGraph->GetYaxis()->SetRangeUser(-.25,.075);
   

   theTGraph->SetMarkerStyle(21);
   theTGraph->SetMarkerColor(1);
   theTGraph->GetXaxis()->SetTitle("N_{ch}");
   c1->SetLeftMargin(0.15);
   c1->SetBottomMargin(0.15);
   if(lam == 0) theTGraph->GetYaxis()->SetTitle("#lambda_{#theta}");
   if(lam == 1) theTGraph->GetYaxis()->SetTitle("#lambda_{#phi}");
   if(lam == 2) theTGraph->GetYaxis()->SetTitle("#lambda_{#theta#phi}");
   if(lam == 3) theTGraph->GetYaxis()->SetTitle("#tilde#lambda");
   theTGraph->SetTitle("");
   theTGraph->Draw("alp");
   leg->AddEntry(theTGraph,"15 < p_{T} < 50 GeV","p");
   leg->SetFillStyle(0);
   leg->SetBorderSize(0);
   
   TFile *_file0 = TFile::Open("/data/users/ferraioc/Polarization/Modified/ToyMC/pTBGSubRatioIssue_b/Sig_frame3scen3_Bkg_frame3scen9/TGraphResults_3SUps.root");
  
   char tgraphname[200];
   sprintf(tgraphname,"%s_%s_rap1_pt2",lamname,framename);
   theTGraph = (TGraphAsymmErrors*) _file0->Get(tgraphname);
   
   

   theTGraph->SetMarkerStyle(21);
   theTGraph->SetMarkerColor(2);
   theTGraph->Draw("lp");
   leg->AddEntry(theTGraph,"15 < p_{T} < 35 GeV","p");
   
   TFile *_file0 = TFile::Open("/data/users/ferraioc/Polarization/Modified/ToyMC/pTBGSubRatioIssue_c/Sig_frame3scen3_Bkg_frame3scen9/TGraphResults_3SUps.root");
  
   char tgraphname[200];
   sprintf(tgraphname,"%s_%s_rap1_pt1",lamname,framename);
   theTGraph = (TGraphAsymmErrors*) _file0->Get(tgraphname);
   
   

   theTGraph->SetMarkerStyle(21);
   theTGraph->SetMarkerColor(3);
   theTGraph->Draw("lp");
   leg->AddEntry(theTGraph,"10 < p_{T} < 15 GeV","p");
   
/*   TFile *_file0 = TFile::Open("/data/users/ferraioc/Polarization/Modified/ToyMC/pTBGSubRatioIssue_d/Sig_frame3scen3_Bkg_frame3scen9/TGraphResults_3SUps.root");
  
   char tgraphname[200];
   sprintf(tgraphname,"%s_%s_rap1_pt1",lamname,framename);
   theTGraph = (TGraphAsymmErrors*) _file0->Get(tgraphname);
   
   

   theTGraph->SetMarkerStyle(21);
   theTGraph->SetMarkerColor(4);
   theTGraph->Draw("lp");
   leg->AddEntry(theTGraph,"10-20","pl");
   
   TFile *_file0 = TFile::Open("/data/users/ferraioc/Polarization/Modified/ToyMC/pTBGSubRatioIssue_e/Sig_frame3scen3_Bkg_frame3scen9/TGraphResults_3SUps.root");
  
   char tgraphname[200];
   sprintf(tgraphname,"%s_%s_rap1_pt2",lamname,framename);
   theTGraph = (TGraphAsymmErrors*) _file0->Get(tgraphname);
   
   

   theTGraph->SetMarkerStyle(21);
   theTGraph->SetMarkerColor(6);
   theTGraph->Draw("lp");
   leg->AddEntry(theTGraph,"20-30","pl");
*/   
   leg->Draw();
   
   char savename[200];
   sprintf(savename,"ToyMCLambda/%s_%s.pdf",lamname,framename);
   c1->SaveAs(savename);
   }
   }}