{


char infile[200];
char costhpx[200];
char phipx[200];
TH1D *signal_costhPX;
TH1D *signal_phiPX;
TCanvas *c1 = new TCanvas();
TFile *f[2][12];



for(int rap = 0; rap < 2; rap++){

for(int pt = 0; pt < 12; pt++){

sprintf(infile,"DataFiles/SetOfCuts16_Cowboys/Psi1S/tmpFiles/data_Psi1S_rap%d_pT%d.root",rap+1,pt+1);

f[rap][pt] = TFile::Open(infile);

signal_costhPX = hSR_cosThetaPhi_PHX->ProjectionX();
signal_phiPX = hSR_cosThetaPhi_PHX->ProjectionY();

sprintf(costhpx,"DataFiles/SetOfCuts16_Cowboys/Psi1S/tmpFiles/costhPX_rap%d_pT%d.pdf",rap+1,pt+1);
sprintf(phipx,"DataFiles/SetOfCuts16_Cowboys/Psi1S/tmpFiles/phiPX_rap%d_pT%d.pdf",rap+1,pt+1);

signal_costhPX->Draw();
c1->SaveAs(costhpx);

signal_phiPX->Draw();
c1->SaveAs(phipx);

}
}

}