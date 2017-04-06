#define fracs_cxx
#include "fracs.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TGraphAsymmErrors.h"


void fracs::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L fracs.C
//      Root > fracs t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntries();
   
   cout<<"Total of "<<nentries<<" entries."<<endl;
//   nentries = 100000;
   
   bool Psi1S = true;

   
   if(!Psi1S){
   const int numCPMBins = 5;
   int cpmRange[6] = {0,15,25,35,45,100}; 
   }
   
   if(Psi1S){
   const int numCPMBins = 11;
   int cpmRange[12] = {0,10,16,20,24,28,32,36,40,48,60,100}; 
   }
   
   Long64_t nbytes = 0, nb = 0;
   double nEvents[numCPMBins][24];
   double nentriesNVtx[24];
   
   
   for(int nVtx = 0; nVtx < 24; nVtx++) {
     for(int cpm = 0; cpm < numCPMBins; cpm++) {
       nEvents[cpm][nVtx] = 0;
     }
   }
   
   
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      
      if(jentry % 100000 == 0) printf("event %d of %d events\n", (Int_t) jentry, (Int_t) nentries);
      
      //1) get number of events in each cpm bin grouped by PU
      //2) divide 1 by total number of events
      //3) uncertainty = sqrt(n)
      
      for(int nVtx = 0; nVtx < 24; nVtx++)
      {
        if(PU == nVtx+1) nentriesNVtx[nVtx]++;
        for(int cpm = 0; cpm < numCPMBins; cpm++) {
          if(CPM > cpmRange[cpm] && CPM < cpmRange[cpm+1] && PU == nVtx+1) 
          {
            nEvents[cpm][nVtx]++;             
          }
        }
      }
      
      
      }

//nEvents divided by nentries, and its error (prop. err. of the two numbers)
double fracEntries[numCPMBins][24];
double fracEntriesErr[numCPMBins][24];

//sqrt of nEvents
double nEventsErr[numCPMBins][24];

//error on nentries
double nentriesNVtxErr[24];

for(int nVtx = 0; nVtx < 24; nVtx++) {
	nentriesNVtxErr[nVtx] = sqrt(nentriesNVtx[nVtx]);
     for(int cpm = 0; cpm < numCPMBins; cpm++) {
       
       nEventsErr[cpm][nVtx]=sqrt(nEvents[cpm][nVtx]);

       fracEntries[cpm][nVtx] = double(nEvents[cpm][nVtx])/double(nentriesNVtx[nVtx]);

       fracEntriesErr[cpm][nVtx] = fracEntries[cpm][nVtx]*sqrt(pow(nEventsErr[cpm][nVtx]/nEvents[cpm][nVtx],2)+pow(double(nentriesNVtxErr[nVtx])/nentriesNVtx[nVtx],2));

     }
   }
   
Double_t PUcount[24];
for(int x = 0; x < 24; x++)
{
PUcount[x]=x;
}

TCanvas *c1 = new TCanvas("Fraction of cross section vs. PU","Fraction of cross section vs. PU",800,600);
double yaxis = 0.20;
if(!Psi1S) yaxis = 0.35;
TH1F *hFrame = gPad->DrawFrame(-1, 0., 30, yaxis);
hFrame->SetXTitle("Number of pileup collisions");
hFrame->SetYTitle("Fraction of cross section");
hFrame->Draw();
 
if(Psi1S) leg = new TLegend(0.75,0.2,0.9,0.9);
if(!Psi1S) leg = new TLegend(0.75,0.7,0.9,0.9);
leg->SetFillColor(0);
char legEntry[100];
TGraphErrors *fracGraph[numCPMBins];

for(int cpm = 0; cpm < numCPMBins; cpm++) {
  fracGraph[cpm] = new TGraphErrors(24,PUcount,fracEntries[cpm],0,fracEntriesErr[cpm]);
  fracGraph[cpm]->SetMarkerStyle(20);
  if(cpm<9) fracGraph[cpm]->SetMarkerColor(cpm+1);
  else {fracGraph[cpm]->SetMarkerColor(cpm-8); fracGraph[cpm]->SetMarkerStyle(34);}
  sprintf(legEntry,"Nch %d - %d",cpmRange[cpm],cpmRange[cpm+1]);
  leg->AddEntry(fracGraph[cpm],legEntry,"p");
  fracGraph[cpm]->Draw("p");
}

leg->Draw(); 
char savename[100];
if(Psi1S) sprintf(savename,"CrossSectionFraction_bins_Psi1S.pdf");
if(!Psi1S) sprintf(savename,"CrossSectionFraction_bins_!Psi1S.pdf");
c1->SaveAs(savename);

}
