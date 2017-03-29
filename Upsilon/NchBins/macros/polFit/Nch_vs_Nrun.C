{
TFile *file = TFile::Open("DataFiles/SetOfCuts11_NchinPriVtxBins/tmpFiles/selEvents_data_Ups.root");

TCanvas *c1 = new TCanvas("c", "c", 600, 500);
c->SetLogy();

Reco_Onia_cpm_PV_1->SetMarkerColor(0);
Reco_Onia_cpm_PV_2->SetMarkerColor(1);
Reco_Onia_cpm_PV_3->SetMarkerColor(2);
Reco_Onia_cpm_PV_4->SetMarkerColor(3);
Reco_Onia_cpm_PV_5->SetMarkerColor(4);
Reco_Onia_cpm_PV_6->SetMarkerColor(5);
Reco_Onia_cpm_PV_7->SetMarkerColor(6);
Reco_Onia_cpm_PV_1->SetMarkerStyle(20);
Reco_Onia_cpm_PV_2->SetMarkerStyle(21);
Reco_Onia_cpm_PV_3->SetMarkerStyle(22);
Reco_Onia_cpm_PV_4->SetMarkerStyle(23);
Reco_Onia_cpm_PV_5->SetMarkerStyle(29);
Reco_Onia_cpm_PV_6->SetMarkerStyle(33);
Reco_Onia_cpm_PV_7->SetMarkerStyle(34);

Reco_Onia_cpm_PV_1->Draw();
Reco_Onia_cpm_PV_2->Draw("same");
Reco_Onia_cpm_PV_3->Draw("same");
Reco_Onia_cpm_PV_4->Draw("same");
Reco_Onia_cpm_PV_5->Draw("same");
Reco_Onia_cpm_PV_6->Draw("same");
Reco_Onia_cpm_PV_7->Draw("same");

leg = new TLegend(0.1,0.1,0.3,0.3);
leg->AddEntry(Reco_Onia_cpm_PV_1,"nPriVtx1","p");
leg->AddEntry(Reco_Onia_cpm_PV_2,"nPriVtx2","p");
leg->AddEntry(Reco_Onia_cpm_PV_3,"nPriVtx3","p");
leg->AddEntry(Reco_Onia_cpm_PV_4,"nPriVtx4","p");
leg->AddEntry(Reco_Onia_cpm_PV_5,"nPriVtx5","p");
leg->AddEntry(Reco_Onia_cpm_PV_6,"nPriVtx6","p");
leg->AddEntry(Reco_Onia_cpm_PV_7,"nPriVtx7","p");
leg->Draw();

}