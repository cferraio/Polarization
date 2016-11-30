{



TFile *_file0 = TFile::Open("DataFiles/SetOfCuts11_ctauScen0_FracLSB-1_2011Run3/Psi1S/Figures/AngDistHist.root");


TFile *_file1 = TFile::Open("DataFiles/SetOfCuts11_ctauScen0_FracLSB-1_2012Run3/Psi1S/Figures/AngDistHist.root");

TFile *_file2 = TFile::Open("DataFiles/SetOfCuts11_ctauScen0_FracLSB-1_2015/Psi1S/Figures/AngDistHist.root");


TCanvas * c1 = new TCanvas("c", "c");
char name[200];
char graphname[200];

Double_t norm;

TH2F * h1;
TH2F * h2;
for(int rap = 1; rap < 1; rap++)
{
for(int pt = 1; pt < 13; pt++)
{
sprintf(graphname,"CosthPhi_HX_rap%d_pT%d",rap,pt);
h1 = (TH2F*)_file0->Get(graphname); 
h2 = (TH2F*)_file1->Get(graphname); 
norm = h1->GetEntries();
h1->Scale(1/norm);
norm = h2->GetEntries();
h2->Scale(1/norm);
h2->Add(h1,-1);
h2->Draw("colz");
sprintf(name,"normcosthphi/costhPhi2012-2011_rap%d_pt%d.pdf",rap,pt);
c1->SaveAs(name);
}
}

/*TH1F * h3;
TH1F * h4;
for(int rap = 1; rap < 3; rap++)
{
for(int pt = 1; pt < 13; pt++)
{
sprintf(graphname,"Proj_PHX_costh_rap%d_pT%d",rap,pt);
h3 = (TH1F*)_file0->Get(graphname); 
h4 = (TH1F*)_file1->Get(graphname); 
norm = h3->GetEntries();
h3->Scale(1/norm);
norm = h4->GetEntries();
h4->Scale(1/norm);
h4->Add(h3,-1);
h4->Draw();
sprintf(name,"normcosthphi/costh2012-2011_rap%d_pt%d.pdf",rap,pt);
c1->SaveAs(name);

}
}
*/

TH1F * h5;
TH1F * h6;
for(int rap = 1; rap < 3; rap++)
{
for(int pt = 1; pt < 4; pt++)
{
sprintf(graphname,"Proj_PHX_costh_rap%d_pT%d",rap,pt);
h5 = (TH1F*)_file0->Get(graphname); 
h6 = (TH1F*)_file1->Get(graphname); 
h7 = (TH1F*)_file2->Get(graphname); 
h6->SetLineColor(2);
h7->SetLineColor(4);
h6->Draw();
h5->Draw("same");
h7->Draw("same");
sprintf(name,"normcosthphi/costh_rap%d_pt%d.pdf",rap,pt);
c1->SaveAs(name);
h6.Divide(h5);
h7.Divide(h5);
h6->SetTitle("Ratio 2012:2011 costh");
h6->Draw();
h7->SetLineColor(2);
h7->Draw("same");
sprintf(name,"normcosthphi/costh2012-2011_ratio_rap%d_pt%d.pdf",rap,pt);
c1->SaveAs(name);
}
}


/*for(int rap = 1; rap < 3; rap++)
{
for(int pt = 1; pt < 13; pt++)
{
sprintf(graphname,"Proj_PHX_phi_rap%d_pT%d",rap,pt);
h3 = (TH1F*)_file0->Get(graphname); 
h4 = (TH1F*)_file1->Get(graphname); 
norm = h3->GetEntries();
h3->Scale(1/norm);
norm = h4->GetEntries();
h4->Scale(1/norm);
h4->Add(h3,-1);
h4->Draw();
sprintf(name,"normcosthphi/phi2012-2011_rap%d_pt%d.pdf",rap,pt);
c1->SaveAs(name);
}
}
*/

//TH1F * h5;
//TH1F * h6;
for(int rap = 1; rap < 3; rap++)
{
for(int pt = 1; pt < 13; pt++)
{
sprintf(graphname,"Proj_PHX_phi_rap%d_pT%d",rap,pt);
h5 = (TH1F*)_file0->Get(graphname); 
h6 = (TH1F*)_file1->Get(graphname); 
h6->SetLineColor(2);
h6->SetMinimum(0);
h6->Draw();
h5->Draw("same");
sprintf(name,"normcosthphi/phi_rap%d_pt%d.pdf",rap,pt);
c1->SaveAs(name);
h6.Divide(h5);
h6->SetTitle("Ratio 2012:2011 phi");
h6->GetYaxis()->SetRangeUser(3.5,8);
h6->Draw();
sprintf(name,"normcosthphi/phi2012-2011_ratio_rap%d_pt%d.pdf",rap,pt);
c1->SaveAs(name);
}
}


}