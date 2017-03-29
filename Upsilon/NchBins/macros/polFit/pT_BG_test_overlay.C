{

c1 = new TCanvas("c1","c1",600,400);
TFile *_file0 = TFile::Open("/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx/results_2SUps_rap1_pT2_cpm1.root");
gStyle->SetOptStat(0);
background_pT_test->Scale(.02);
background_pT_test->GetYaxis()->SetRangeUser(0.3,1.4);
leg = new TLegend(0.1,0.1,0.25,0.4);
leg->SetFillColor(-1);
background_pT_test->SetMarkerStyle(21);
background_pT_test->SetLineColor(1);
background_pT_test->SetMarkerColor(1);
leg->AddEntry(background_pT_test,"CPM1","ple");
background_pT_test->Draw("lp");

TFile *_file0 = TFile::Open("/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx/results_2SUps_rap1_pT2_cpm2.root");
background_pT_test->Scale(.02);
background_pT_test->SetMarkerStyle(21);
background_pT_test->SetLineColor(2);
background_pT_test->SetMarkerColor(2);
leg->AddEntry(background_pT_test,"CPM2","ple");
background_pT_test->Draw("same");

TFile *_file0 = TFile::Open("/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx/results_2SUps_rap1_pT2_cpm3.root");
background_pT_test->Scale(.02);
background_pT_test->SetMarkerStyle(21);
background_pT_test->SetLineColor(4);
background_pT_test->SetMarkerColor(4);
leg->AddEntry(background_pT_test,"CPM3","ple");
background_pT_test->Draw("same");

TFile *_file0 = TFile::Open("/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx/results_2SUps_rap1_pT2_cpm4.root");
background_pT_test->Scale(.02);
background_pT_test->SetMarkerStyle(21);
background_pT_test->SetLineColor(3);
background_pT_test->SetMarkerColor(3);
leg->AddEntry(background_pT_test,"CPM4","ple");
background_pT_test->Draw("same");

TFile *_file0 = TFile::Open("/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx/results_2SUps_rap1_pT2_cpm5.root");
background_pT_test->Scale(.02);
background_pT_test->SetMarkerStyle(21);
background_pT_test->SetLineColor(6);
background_pT_test->SetMarkerColor(6);
leg->AddEntry(background_pT_test,"CPM5","ple");
background_pT_test->Draw("same");
leg->Draw();
c1->SaveAs("2S_pT_BG_test_overlay_15-50.pdf");

}