TCanvas *c1 = new TCanvas("c","c",600,400);

TFile f("/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx/TGraphResults_1SUps.root")
ltilde_CS_rap1_pt2->SetMarkerColor(2);
ltilde_CS_rap1_pt2->SetLineColor(2);
ltilde_CS_rap1_pt2->SetMarkerStyle(20);
ltilde_CS_rap1_pt2->SetMarkerSize(.9);

ltilde_HX_rap1_pt2->SetMarkerColor(3);
ltilde_HX_rap1_pt2->SetLineColor(3);
ltilde_HX_rap1_pt2->SetMarkerStyle(21);
ltilde_HX_rap1_pt2->SetMarkerSize(.9);

ltilde_PX_rap1_pt2->SetMarkerColor(4);
ltilde_PX_rap1_pt2->SetLineColor(4);
ltilde_PX_rap1_pt2->SetMarkerStyle(22);
ltilde_PX_rap1_pt2->SetMarkerSize(.9);

ltilde_CS_rap1_pt2->GetYaxis()->SetRangeUser(-1.25,1.25)
ltilde_CS_rap1_pt2->Draw("alp")
ltilde_HX_rap1_pt2->Draw("p")
ltilde_PX_rap1_pt2->Draw("p")

leg = new TLegend (0.7, 0.1, 0.9, 0.3);
leg->AddEntry(ltilde_CS_rap1_pt2,"CS_withNPriVtXCut","ep")
leg->AddEntry(ltilde_PX_rap1_pt2,"PX_withNPriVtXCut","ep")
leg->AddEntry(ltilde_HX_rap1_pt2,"HX_withNPriVtXCut","ep")

TFile f("/data/users/ferraioc/Polarization/Modified/Data/GreatCPMRun2/TGraphResults_1SUps.root")
ltilde_CS_rap1_pt2->SetMarkerColor(2);
ltilde_CS_rap1_pt2->SetLineColor(2);
ltilde_CS_rap1_pt2->SetMarkerStyle(24);
ltilde_CS_rap1_pt2->SetMarkerSize(.9);

ltilde_HX_rap1_pt2->SetMarkerColor(3);
ltilde_HX_rap1_pt2->SetLineColor(3);
ltilde_HX_rap1_pt2->SetMarkerStyle(25);
ltilde_HX_rap1_pt2->SetMarkerSize(.9);

ltilde_PX_rap1_pt2->SetMarkerColor(4);
ltilde_PX_rap1_pt2->SetLineColor(4);
ltilde_PX_rap1_pt2->SetMarkerStyle(26);
ltilde_PX_rap1_pt2->SetMarkerSize(.9);

ltilde_CS_rap1_pt2->Draw("p")
ltilde_HX_rap1_pt2->Draw("p")
ltilde_PX_rap1_pt2->Draw("p")

leg->AddEntry(ltilde_CS_rap1_pt2,"CS_noCut","ep")
leg->AddEntry(ltilde_PX_rap1_pt2,"PX_noCut","ep")
leg->AddEntry(ltilde_HX_rap1_pt2,"HX_noCut","ep")
leg->SetFillColor(0)
leg->Draw()
c1->SaveAs("ltilde_cut_vs_nocut_nch5.pdf")

TCanvas *c1 = new TCanvas("c","c",600,400);

TFile f("/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx/TGraphResults_1SUps.root")
lth_CS_rap1_pt2->SetMarkerColor(2);
lth_CS_rap1_pt2->SetLineColor(2);
lth_CS_rap1_pt2->SetMarkerStyle(20);
lth_CS_rap1_pt2->SetMarkerSize(.9);

lth_HX_rap1_pt2->SetMarkerColor(3);
lth_HX_rap1_pt2->SetLineColor(3);
lth_HX_rap1_pt2->SetMarkerStyle(21);
lth_HX_rap1_pt2->SetMarkerSize(.9);

lth_PX_rap1_pt2->SetMarkerColor(4);
lth_PX_rap1_pt2->SetLineColor(4);
lth_PX_rap1_pt2->SetMarkerStyle(22);
lth_PX_rap1_pt2->SetMarkerSize(.9);

lth_CS_rap1_pt2->GetYaxis()->SetRangeUser(-1.25,1.25)
lth_CS_rap1_pt2->Draw("alp")
lth_HX_rap1_pt2->Draw("p")
lth_PX_rap1_pt2->Draw("p")

leg = new TLegend (0.7, 0.1, 0.9, 0.3);
leg->AddEntry(lth_CS_rap1_pt2,"CS_withNPriVtXCut","ep")
leg->AddEntry(lth_PX_rap1_pt2,"PX_withNPriVtXCut","ep")
leg->AddEntry(lth_HX_rap1_pt2,"HX_withNPriVtXCut","ep")

TFile f("/data/users/ferraioc/Polarization/Modified/Data/GreatCPMRun2/TGraphResults_1SUps.root")
lth_CS_rap1_pt2->SetMarkerColor(2);
lth_CS_rap1_pt2->SetLineColor(2);
lth_CS_rap1_pt2->SetMarkerStyle(24);
lth_CS_rap1_pt2->SetMarkerSize(.9);

lth_HX_rap1_pt2->SetMarkerColor(3);
lth_HX_rap1_pt2->SetLineColor(3);
lth_HX_rap1_pt2->SetMarkerStyle(25);
lth_HX_rap1_pt2->SetMarkerSize(.9);

lth_PX_rap1_pt2->SetMarkerColor(4);
lth_PX_rap1_pt2->SetLineColor(4);
lth_PX_rap1_pt2->SetMarkerStyle(26);
lth_PX_rap1_pt2->SetMarkerSize(.9);

lth_CS_rap1_pt2->Draw("p")
lth_HX_rap1_pt2->Draw("p")
lth_PX_rap1_pt2->Draw("p")

leg->AddEntry(lth_CS_rap1_pt2,"CS_noCut","ep")
leg->AddEntry(lth_PX_rap1_pt2,"PX_noCut","ep")
leg->AddEntry(lth_HX_rap1_pt2,"HX_noCut","ep")
leg->SetFillColor(0)
leg->Draw()
c1->SaveAs("lth_cut_vs_nocut_nch5.pdf")

TCanvas *c1 = new TCanvas("c","c",600,400);

TFile f("/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx/TGraphResults_1SUps.root")
ltp_CS_rap1_pt2->SetMarkerColor(2);
ltp_CS_rap1_pt2->SetLineColor(2);
ltp_CS_rap1_pt2->SetMarkerStyle(20);
ltp_CS_rap1_pt2->SetMarkerSize(.9);

ltp_HX_rap1_pt2->SetMarkerColor(3);
ltp_HX_rap1_pt2->SetLineColor(3);
ltp_HX_rap1_pt2->SetMarkerStyle(21);
ltp_HX_rap1_pt2->SetMarkerSize(.9);

ltp_PX_rap1_pt2->SetMarkerColor(4);
ltp_PX_rap1_pt2->SetLineColor(4);
ltp_PX_rap1_pt2->SetMarkerStyle(22);
ltp_PX_rap1_pt2->SetMarkerSize(.9);

ltp_CS_rap1_pt2->GetYaxis()->SetRangeUser(-.45,.45)
ltp_CS_rap1_pt2->Draw("alp")
ltp_HX_rap1_pt2->Draw("p")
ltp_PX_rap1_pt2->Draw("p")

leg = new TLegend (0.7, 0.1, 0.9, 0.3);
leg->AddEntry(ltp_CS_rap1_pt2,"CS_withNPriVtXCut","ep")
leg->AddEntry(ltp_PX_rap1_pt2,"PX_withNPriVtXCut","ep")
leg->AddEntry(ltp_HX_rap1_pt2,"HX_withNPriVtXCut","ep")

TFile f("/data/users/ferraioc/Polarization/Modified/Data/GreatCPMRun2/TGraphResults_1SUps.root")
ltp_CS_rap1_pt2->SetMarkerColor(2);
ltp_CS_rap1_pt2->SetLineColor(2);
ltp_CS_rap1_pt2->SetMarkerStyle(24);
ltp_CS_rap1_pt2->SetMarkerSize(.9);

ltp_HX_rap1_pt2->SetMarkerColor(3);
ltp_HX_rap1_pt2->SetLineColor(3);
ltp_HX_rap1_pt2->SetMarkerStyle(25);
ltp_HX_rap1_pt2->SetMarkerSize(.9);

ltp_PX_rap1_pt2->SetMarkerColor(4);
ltp_PX_rap1_pt2->SetLineColor(4);
ltp_PX_rap1_pt2->SetMarkerStyle(26);
ltp_PX_rap1_pt2->SetMarkerSize(.9);

ltp_CS_rap1_pt2->Draw("p")
ltp_HX_rap1_pt2->Draw("p")
ltp_PX_rap1_pt2->Draw("p")

leg->AddEntry(ltp_CS_rap1_pt2,"CS_noCut","ep")
leg->AddEntry(ltp_PX_rap1_pt2,"PX_noCut","ep")
leg->AddEntry(ltp_HX_rap1_pt2,"HX_noCut","ep")
leg->SetFillColor(0)
leg->Draw()
c1->SaveAs("ltp_cut_vs_nocut_nch5.pdf")

TCanvas *c1 = new TCanvas("c","c",600,400);

TFile f("/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx/TGraphResults_1SUps.root")
lph_CS_rap1_pt2->SetMarkerColor(2);
lph_CS_rap1_pt2->SetLineColor(2);
lph_CS_rap1_pt2->SetMarkerStyle(20);
lph_CS_rap1_pt2->SetMarkerSize(.9);

lph_HX_rap1_pt2->SetMarkerColor(3);
lph_HX_rap1_pt2->SetLineColor(3);
lph_HX_rap1_pt2->SetMarkerStyle(21);
lph_HX_rap1_pt2->SetMarkerSize(.9);

lph_PX_rap1_pt2->SetMarkerColor(4);
lph_PX_rap1_pt2->SetLineColor(4);
lph_PX_rap1_pt2->SetMarkerStyle(22);
lph_PX_rap1_pt2->SetMarkerSize(.9);

lph_CS_rap1_pt2->GetYaxis()->SetRangeUser(-.45,.45)
lph_CS_rap1_pt2->Draw("alp")
lph_HX_rap1_pt2->Draw("p")
lph_PX_rap1_pt2->Draw("p")

leg = new TLegend (0.7, 0.1, 0.9, 0.3);
leg->AddEntry(lph_CS_rap1_pt2,"CS_withNPriVtXCut","ep")
leg->AddEntry(lph_PX_rap1_pt2,"PX_withNPriVtXCut","ep")
leg->AddEntry(lph_HX_rap1_pt2,"HX_withNPriVtXCut","ep")

TFile f("/data/users/ferraioc/Polarization/Modified/Data/GreatCPMRun2/TGraphResults_1SUps.root")
lph_CS_rap1_pt2->SetMarkerColor(2);
lph_CS_rap1_pt2->SetLineColor(2);
lph_CS_rap1_pt2->SetMarkerStyle(24);
lph_CS_rap1_pt2->SetMarkerSize(.9);

lph_HX_rap1_pt2->SetMarkerColor(3);
lph_HX_rap1_pt2->SetLineColor(3);
lph_HX_rap1_pt2->SetMarkerStyle(25);
lph_HX_rap1_pt2->SetMarkerSize(.9);

lph_PX_rap1_pt2->SetMarkerColor(4);
lph_PX_rap1_pt2->SetLineColor(4);
lph_PX_rap1_pt2->SetMarkerStyle(26);
lph_PX_rap1_pt2->SetMarkerSize(.9);

lph_CS_rap1_pt2->Draw("p")
lph_HX_rap1_pt2->Draw("p")
lph_PX_rap1_pt2->Draw("p")

leg->AddEntry(lph_CS_rap1_pt2,"CS_noCut","ep")
leg->AddEntry(lph_PX_rap1_pt2,"PX_noCut","ep")
leg->AddEntry(lph_HX_rap1_pt2,"HX_noCut","ep")
leg->SetFillColor(0)
leg->Draw()
c1->SaveAs("lph_cut_vs_nocut_nch5.pdf")