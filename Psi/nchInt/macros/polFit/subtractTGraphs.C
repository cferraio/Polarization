{


TFile *f[0] = TFile::Open("/data/users/ferraioc/Polarization/JPsi/Data/NonPrompt/TGraphResults_Psi1S.root");

TFile *f[1] = TFile::Open("/data/users/ferraioc/Polarization/JPsi/Data/2012Data_2012effs/TGraphResults_Psi1S.root");

TFile *f[2] = TFile::Open("/data/users/ferraioc/Polarization/JPsi/Data/NonPrompt2011/TGraphResults_Psi1S.root");

TFile *f[3] = TFile::Open("/data/users/ferraioc/Polarization/JPsi/Data/2011_Run3_JPsi/TGraphResults_Psi1S.root");



int ptBins = 11;
double xnp[ptBins];
double ynp[ptBins];
double ynpe[ptBins];
double xp[ptBins];
double yp[ptBins];
double ype[ptBins];


f[0].cd();
for(int x = 0; x < ptBins; x++){
lth_HX_rap1->GetPoint(x,xnp[x],ynp[x]);
ynpe[x]=lth_HX_rap1->GetErrorY(x);
}

f[1].cd();
for(int x = 0; x < ptBins; x++){
yp[x]=lth_HX_rap1->Eval(xnp[x]);
ype[x]=lth_HX_rap1->GetErrorY(x+1);
}

double diffy[x];
double diffye[x];
for(int x = 0; x < ptBins; x++){
diffy[x] = yp[x] - ynp[x];
diffye[x] = sqrt(ype[x]*ype[x]+ynpe[x]*ynpe[x]);
}

TCanvas * c1 = new TCanvas("c", "c", 600, 400);
gr = new TGraphErrors(11,xnp,diffy,0,diffye);
gr->SetTitle("Prompt - nonprompt");
gr->SetMarkerColor(4);
gr->SetMarkerStyle(21);
gr->GetYaxis()->SetRangeUser(-1,1.75);
gr->Draw("AP");
//c1->SaveAs("NP_vs_PR_diff2011.pdf");


f[2].cd();
for(int x = 0; x < ptBins; x++){
lth_HX_rap1->GetPoint(x,xnp[x],ynp[x]);
ynpe[x]=lth_HX_rap1->GetErrorY(x);
}

f[3].cd();
for(int x = 0; x < ptBins; x++){
yp[x]=lth_HX_rap1->Eval(xnp[x]);
ype[x]=lth_HX_rap1->GetErrorY(x+1);
}

//double diffy[x];
//double diffye[x];
for(int x = 0; x < ptBins; x++){
diffy[x] = yp[x] - ynp[x];
diffye[x] = sqrt(ype[x]*ype[x]+ynpe[x]*ynpe[x]);
}

//TCanvas * c1 = new TCanvas("c", "c", 600, 400);
gr = new TGraphErrors(11,xnp,diffy,0,diffye);
gr->SetTitle("Prompt - nonprompt");
gr->SetMarkerColor(2);
gr->SetMarkerStyle(21);
gr->Draw("sameP");
c1->SaveAs("NP_vs_PR_diff2011.pdf");



}