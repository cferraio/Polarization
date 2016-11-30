{

char infile[200];
char savename[200];
char rappt[200];
char costhrun[200];
TCanvas * c1 = new TCanvas("c", "c", 600, 400);

double ptrange[13]={10., 12., 14., 16., 18., 20., 22., 25., 30., 35., 40., 50., 70.};
double raprange[3]={0., 0.6, 1.2};

sprintf(infile,"DataFiles/SetOfCuts11_ctauScen0_FracLSB-1_2012Run3/Psi1S/Figures/AngDistHist.root");
TFile *f = TFile::Open(infile);

for(int rap = 0; rap < 2; rap++)
{
for(int pt = 0; pt < 12; pt++)
{


sprintf(costhrun,"Proj_PX_costhRunNb_rap%d_pT%d",rap+1,pt+1);
TGraphErrors *h = (TGraphErrors*)gDirectory->Get(costhrun); // THIS IS THE MISSING LINE
   

sprintf(rappt,"Avg |cos#theta| vs Run Number, %.1f < |y| < %.1f, %.1f < p_{T} < %.1f GeV",raprange[rap],raprange[rap+1],ptrange[pt],ptrange[pt+1]);
h->SetTitle(rappt);
h->GetXaxis()->SetTitle("Run Number");
h->GetYaxis()->SetTitle("Avg |cos#theta|");
if ( h ) h->Draw("ap"); // make sure the Get succeeded 

//TLatex latex;


//latex.DrawLatex(.2,.8,rappt);

sprintf(savename,"DataFiles/SetOfCuts11_ctauScen0_FracLSB-1_2012Run3/Psi1S/Figures/cosThvsRunNb_rap%d_pt%d.pdf",rap+1,pt+1);
c1->SaveAs(savename);

}
}





}