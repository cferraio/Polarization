{
TFile *file = TFile::Open("DataFiles/SetOfCuts11_countTksOfPV/tmpFiles/selEvents_data_Ups.root");

TCanvas *c1 = new TCanvas("c", "c", 600, 500);
//c->SetLogy();

/*
Reco_Onia_cpm_PV_0->SetMarkerColor(8);
Reco_Onia_cpm_PV_1->SetMarkerColor(7);
Reco_Onia_cpm_PV_2->SetMarkerColor(1);
Reco_Onia_cpm_PV_3->SetMarkerColor(2);
Reco_Onia_cpm_PV_4->SetMarkerColor(3);
Reco_Onia_cpm_PV_5->SetMarkerColor(4);
Reco_Onia_cpm_PV_6->SetMarkerColor(9);
Reco_Onia_cpm_PV_7->SetMarkerColor(6);
Reco_Onia_cpm_PV_0->SetMarkerStyle(3);
Reco_Onia_cpm_PV_1->SetMarkerStyle(20);
Reco_Onia_cpm_PV_2->SetMarkerStyle(21);
Reco_Onia_cpm_PV_3->SetMarkerStyle(22);
Reco_Onia_cpm_PV_4->SetMarkerStyle(23);
Reco_Onia_cpm_PV_5->SetMarkerStyle(29);
Reco_Onia_cpm_PV_6->SetMarkerStyle(33);
Reco_Onia_cpm_PV_7->SetMarkerStyle(34);

Reco_Onia_cpm_PV_0->GetXaxis()->SetTitle("N_{ch}");
Reco_Onia_cpm_PV_0->Draw();
Reco_Onia_cpm_PV_1->Draw("same");
Reco_Onia_cpm_PV_2->Draw("same");
Reco_Onia_cpm_PV_3->Draw("same");
Reco_Onia_cpm_PV_4->Draw("same");
Reco_Onia_cpm_PV_5->Draw("same");
Reco_Onia_cpm_PV_6->Draw("same");
Reco_Onia_cpm_PV_7->Draw("same");


leg = new TLegend(0.7,0.55,.9,0.9);
leg->AddEntry(Reco_Onia_cpm_PV_0,"Total","p");
leg->AddEntry(Reco_Onia_cpm_PV_1,"nPriVtx1","p");
leg->AddEntry(Reco_Onia_cpm_PV_2,"nPriVtx2","p");
leg->AddEntry(Reco_Onia_cpm_PV_3,"nPriVtx3","p");
leg->AddEntry(Reco_Onia_cpm_PV_4,"nPriVtx4","p");
leg->AddEntry(Reco_Onia_cpm_PV_5,"nPriVtx5","p");
leg->AddEntry(Reco_Onia_cpm_PV_6,"nPriVtx6","p");
leg->AddEntry(Reco_Onia_cpm_PV_7,"nPriVtx7","p");
leg->SetFillColor(10);
leg->Draw();
c1->SaveAs("Nch_overlap.pdf"); 
*/

TH1F *Reco_3_plus_4 = (TH1F*)Reco_Onia_cpm_PV_3->Clone("Reco_3_plus_4");
Reco_3_plus_4->Add(Reco_Onia_cpm_PV_4);

TH1F *Reco_1_over_avg = (TH1F*)Reco_Onia_cpm_PV_1->Clone("Reco_1_over_avg");
Reco_1_over_avg->Divide(Reco_3_plus_4);
Reco_1_over_avg->Scale(1/Reco_1_over_avg->GetBinContent(3));

TH1F *Reco_2_over_avg = (TH1F*)Reco_Onia_cpm_PV_2->Clone("Reco_2_over_avg");
Reco_2_over_avg->Divide(Reco_3_plus_4);
Reco_2_over_avg->Scale(1/Reco_2_over_avg->GetBinContent(3));

//TH1F *Reco_3_over_avg = (TH1F*)Reco_Onia_cpm_PV_0->Clone("Reco_3_over_avg");
//Reco_3_over_avg->Divide(Reco_3_plus_4);

//TH1F *Reco_4_over_avg = (TH1F*)Reco_Onia_cpm_PV_0->Clone("Reco_4_over_avg");
//Reco_4_over_avg->Divide(Reco_3_plus_4);

TH1F *Reco_5_over_avg = (TH1F*)Reco_Onia_cpm_PV_5->Clone("Reco_5_over_avg");
Reco_5_over_avg->Divide(Reco_3_plus_4);
Reco_5_over_avg->Scale(1/Reco_5_over_avg->GetBinContent(3));

TH1F *Reco_6_over_avg = (TH1F*)Reco_Onia_cpm_PV_6->Clone("Reco_6_over_avg");
Reco_6_over_avg->Divide(Reco_3_plus_4);
Reco_6_over_avg->Scale(1/Reco_6_over_avg->GetBinContent(3));

TH1F *Reco_7_over_avg = (TH1F*)Reco_Onia_cpm_PV_7->Clone("Reco_7_over_avg");
Reco_7_over_avg->Divide(Reco_3_plus_4);
Reco_7_over_avg->Scale(1/Reco_7_over_avg->GetBinContent(3));

Reco_1_over_avg->SetMarkerStyle(20);
Reco_1_over_avg->SetMarkerColor(1);
Reco_2_over_avg->SetMarkerStyle(21);
Reco_2_over_avg->SetMarkerColor(2);
//Reco_3_over_avg->SetMarkerStyle(22);
//Reco_3_over_avg->SetMarkerColor(3);
//Reco_4_over_avg->SetMarkerStyle(23);
//Reco_4_over_avg->SetMarkerColor(4);
Reco_5_over_avg->SetMarkerStyle(29);
Reco_5_over_avg->SetMarkerColor(9);
Reco_6_over_avg->SetMarkerStyle(33);
Reco_6_over_avg->SetMarkerColor(6);
Reco_7_over_avg->SetMarkerStyle(34);
Reco_7_over_avg->SetMarkerColor(7); 

//Reco_3_over_avg->GetYaxis()->SetRangeUser(4.5, 5.5);
//Reco_3_over_avg->Draw();
Reco_1_over_avg->GetYaxis()->SetRangeUser(0.8, 1.2);
Reco_1_over_avg->GetXaxis()->SetTitle("N_{ch}");
Reco_1_over_avg->Draw();
Reco_2_over_avg->Draw("same");
//Reco_4_over_avg->Draw("same");
Reco_5_over_avg->Draw("same");
Reco_6_over_avg->Draw("same");
Reco_7_over_avg->Draw("same");

line = new TLine(0,1,60,1);
line->SetLineStyle(2);
line->Draw("same");


leg2 = new TLegend(0.7,0.7,0.9,0.9);
leg2->AddEntry(Reco_1_over_avg,"nPriVtx1/avg","p");
leg2->AddEntry(Reco_2_over_avg,"nPriVtx2/avg","p");
//leg2->AddEntry(Reco_3_over_avg,"nPriVtx3/total","p");
//leg2->AddEntry(Reco_4_over_avg,"nPriVtx4/total","p");
leg2->AddEntry(Reco_5_over_avg,"nPriVtx5/avg","p");
leg2->AddEntry(Reco_6_over_avg,"nPriVtx6/avg","p");
leg2->AddEntry(Reco_7_over_avg,"nPriVtx7/avg","p");
leg2->SetFillColor(10);
leg2->Draw();
c1->SaveAs("Ratios.pdf"); 

}