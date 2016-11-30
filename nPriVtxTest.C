{
TTree *fChain;   //!pointer to the analyzed TTree or TChain

  // Declaration of leaf types
  TLorentzVector  *onia, *muPos, *muNeg;
  int eventNb;
  int runNb;
  int nPriVtx;
  double vertexWeight;

  TCanvas *c1 = new TCanvas("c", "c");
  TH1F *h_nPriVtx[2];
  TH1F *h_vertexWeight[2];
  TH1F *h_jpsi_pt[2];
  TH1F *h_muplus_pt[2];
  TH1F *h_muminus_pt[2];
  TH2F *h_Jpsi_pt_nPrivtx[2];
  TH2F *h_Jpsi_costh_nPrivtx[2];

for(int x = 0; x < 2; x++)
  {
  h_nPriVtx[x] = new TH1F("","",50,0,50);
  h_vertexWeight[x] = new TH1F("","",150,0,150);
  h_jpsi_pt[x] = new TH1F("JPsi p_{T}","",90,0,30);
  h_muplus_pt[x] = new TH1F("muplus p_{T}","",100,0,15);
  h_muminus_pt[x] = new TH1F("muminus p_{T}","",100,0,15);
  h_Jpsi_pt_nPrivtx[x] = new TH2F("nPriVtx vs Jpsi pT","",50,0,50,500,0,75);
  h_Jpsi_costh_nPrivtx[x] = new TH2F("nPriVtx vs Jpsi pT","",50,0,50,30,0,1);
}

bool rejectCowboys = true;



   gStyle->SetOptStat(0);
   
   Long64_t nentries;
TFile *f[2];

Long64_t nbytes = 0, nb = 0;

for(int data2011 = 0; data2011 < 2; data2011++)
   {
   	 if (data2011 == 0) useData2011=false;
   	 if (data2011 == 1) useData2011=true;
cout<<"file is "<<data2011<<endl;
 	if(useData2011) 
  		f[data2011] = TFile::Open("/data/users/ferraioc/TTree_Onia2MuMu_v30_PromptRecoAB_10May2012_Jpsi.root");
  		

  	if(!useData2011)
  		f[data2011] = TFile::Open("/data/users/ferraioc/Polarization/2012ppOniaData/r2012A_DoubMu_jpsi_v8.root");

  f[data2011]->cd();
  
  		f[data2011]->GetObject("data",fChain);

  onia = 0;
  muNeg = 0;
  muPos = 0;
  fChain->SetBranchAddress("JpsiP", &onia);
  fChain->SetBranchAddress("muNegP", &muNeg);
  fChain->SetBranchAddress("muPosP", &muPos);
  fChain->SetBranchAddress("eventNb", &eventNb);
  fChain->SetBranchAddress("runNb", &runNb);
  fChain->SetBranchAddress("nPriVtx", &nPriVtx);
  fChain->SetBranchAddress("vertexWeight", &vertexWeight);

  Long64_t nentries = fChain->GetEntriesFast();

	std::cout << "File "<<data2011<<"; number of entries = " << nentries << std::endl;
	nentries = 5416828;
	nentries = 100000;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
   fChain->GetEntry(jentry);

	if(jentry % 10000 == 0) std::cout << "event " << jentry << " of " << nentries << std::endl;

	double deltaPhi = muNeg->Phi() - muPos->Phi();
	if(deltaPhi > TMath::Pi()) deltaPhi -= 2.*TMath::Pi();
	else if(deltaPhi < -TMath::Pi()) deltaPhi += 2.*TMath::Pi();
	
	if(onia->Pt() < 10.) continue;
	
	if(rejectCowboys){
	if(deltaPhi < 0.)  continue;
	}

	 h_vertexWeight[data2011]->Fill(vertexWeight);

  h_nPriVtx[data2011]->Fill(nPriVtx);

  h_jpsi_pt[data2011]->Fill(onia->Pt());
  h_muplus_pt[data2011]->Fill(muPos->Pt());
  h_muminus_pt[data2011]->Fill(muNeg->Pt());

  h_Jpsi_pt_nPrivtx[data2011]->Fill(nPriVtx,onia->Pt());
  h_Jpsi_costh_nPrivtx[data2011]->Fill(nPriVtx,onia->CosTheta());
}

}
char pdfname[200];
   
   Double_t norm; 
for(int data2011 = 0; data2011 < 2; data2011++)
   {

   		norm = h_nPriVtx[data2011]->GetEntries();
   		h_nPriVtx[data2011]->Scale(1/norm);
   		h_nPriVtx[data2011]->SetLineColor(data2011+1);

   		norm = h_vertexWeight[data2011]->GetEntries();
   		h_vertexWeight[data2011]->Scale(1/norm);
   		h_vertexWeight[data2011]->SetLineColor(data2011+1);

   		h_muminus_pt[data2011]->GetEntries();
		h_muminus_pt[data2011]->Scale(1/norm);
		h_muminus_pt[data2011]->SetLineColor(data2011+1);
		
		h_muplus_pt[data2011]->GetEntries();
		h_muplus_pt[data2011]->Scale(1/norm);
		h_muplus_pt[data2011]->SetLineColor(data2011+1);
		
		h_jpsi_pt[data2011]->GetEntries();
		h_jpsi_pt[data2011]->Scale(1/norm);
		h_jpsi_pt[data2011]->SetLineColor(data2011+1);
		
		}

		 leg = new TLegend(0.7,0.75,0.9,0.9);
    leg->AddEntry(h_jpsi_pt[0],"2012 Data","f");
    leg->AddEntry(h_jpsi_pt[1],"2011 Data","f");
    leg->SetFillStyle(0);
    gStyle->SetStatStyle(0); 
	gStyle->SetTitleStyle(0); 
	gROOT->ForceStyle();

    gStyle->SetFrameFillColor(-1);  

    for(int x = 0; x < 2; x++)
   {
  h_nPriVtx[x]->SetTitle("nPriVtx");
  h_vertexWeight[x]->SetTitle("vertexWeight");
  h_muminus_pt[x]->SetTitle("MuMinus p_{T}");
  h_jpsi_pt[x]->SetTitle("Jpsi p_{T}");
  h_muplus_pt[x]->SetTitle("MuPlus p_{T}");
  }

   h_nPriVtx[1]->Draw();
   h_nPriVtx[0]->Draw("same");
   leg->Draw();
   c1->SaveAs("nPriVtx.pdf");
   h_vertexWeight[0]->Draw();
   h_vertexWeight[1]->Draw("same");
   leg->Draw();
   c1->SaveAs("vertexWeight.pdf");
   
   h_muminus_pt[0]->Draw();
h_muminus_pt[1]->Draw("same");
leg->Draw();
c1->SaveAs("muminuspT.pdf");

h_jpsi_pt[1]->Draw();
h_jpsi_pt[0]->Draw("same");
leg->Draw();
c1->SaveAs("jpsipT.pdf");
h_muplus_pt[0]->Draw();
h_muplus_pt[1]->Draw("same");
leg->Draw();
c1->SaveAs("mupluspT.pdf");

h_Jpsi_pt_nPrivtx[0]->Draw("colz");
c1->SaveAs("2011vtxpt.pdf");

h_Jpsi_pt_nPrivtx[1]->Draw("colz");
c1->SaveAs("2012vtxpt.pdf");

h_Jpsi_costh_nPrivtx[0]->Draw("colz");
c1->SaveAs("2011vtxcosth.pdf");

h_Jpsi_costh_nPrivtx[1]->Draw("colz");
c1->SaveAs("2012vtxcosth.pdf");



}
