{

TFile *f[2][5];
TCanvas *c1 = new TCanvas();

char infile[200];
char outname[200];

for(int rap = 0; rap < 2; rap++)
{
for(int pt = 0; pt < 5; pt++)
{
cout<<"rap is "<<rap<<" pt is "<<pt<<endl;
sprintf(infile,"/data/users/ferraioc/Polarization/JPsi/ToyMC/tests/Sig_frame1scen3_Bkg_frame1scen3/rap%d_pT%d/Generation1/results.root",rap+1,pt+1);

sprintf(outname,"costhphiPX_rap%d_pt%d.pdf",rap+1,pt+1);

f[rap][pt] = TFile::Open(infile);

total_costhphiPX->Draw("colz");

c1->SaveAs(outname);

}
}
}