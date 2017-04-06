//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Dec  2 12:13:35 2016 by ROOT version 5.32/00
// from TTree selectedData/selected events
// found on file: DataFiles/SetOfCuts11_ctauScen0_FracLSB-1_FirstResults/Psi2S/tmpFiles/selEvents_data.root
//////////////////////////////////////////////////////////

#ifndef fracs_h
#define fracs_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <TLorentzVector.h>
#include <TObject.h>
#include <TVector3.h>

// Fixed size dimensions of array or collections stored in the TTree if any.

class fracs {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
 //TLorentzVector  *lepP;
   UInt_t          fUniqueID;
   UInt_t          fBits;
   UInt_t          fP_fUniqueID;
   UInt_t          fP_fBits;
   Double_t        fP_fX;
   Double_t        fP_fY;
   Double_t        fP_fZ;
   Double_t        fE;
 //TLorentzVector  *lepN;
   UInt_t          fUniqueID;
   UInt_t          fBits;
   UInt_t          fP_fUniqueID;
   UInt_t          fP_fBits;
   Double_t        fP_fX;
   Double_t        fP_fY;
   Double_t        fP_fZ;
   Double_t        fE;
 //TLorentzVector  *JpsiP;
   UInt_t          fUniqueID;
   UInt_t          fBits;
   UInt_t          fP_fUniqueID;
   UInt_t          fP_fBits;
   Double_t        fP_fX;
   Double_t        fP_fY;
   Double_t        fP_fZ;
   Double_t        fE;
   Double_t        CPM;
   Double_t        PU;
   Double_t        PriVtx;
   Double_t        nPriVtx;
   Double_t        Jpsict;
   Double_t        vertexWeight;
   Double_t        JpsictErr;
   Double_t        JpsiMassErr;
   Double_t        JpsiVprob;

   // List of branches
   TBranch        *b_lepP_fUniqueID;   //!
   TBranch        *b_lepP_fBits;   //!
   TBranch        *b_lepP_fP_fUniqueID;   //!
   TBranch        *b_lepP_fP_fBits;   //!
   TBranch        *b_lepP_fP_fX;   //!
   TBranch        *b_lepP_fP_fY;   //!
   TBranch        *b_lepP_fP_fZ;   //!
   TBranch        *b_lepP_fE;   //!
   TBranch        *b_lepN_fUniqueID;   //!
   TBranch        *b_lepN_fBits;   //!
   TBranch        *b_lepN_fP_fUniqueID;   //!
   TBranch        *b_lepN_fP_fBits;   //!
   TBranch        *b_lepN_fP_fX;   //!
   TBranch        *b_lepN_fP_fY;   //!
   TBranch        *b_lepN_fP_fZ;   //!
   TBranch        *b_lepN_fE;   //!
   TBranch        *b_JpsiP_fUniqueID;   //!
   TBranch        *b_JpsiP_fBits;   //!
   TBranch        *b_JpsiP_fP_fUniqueID;   //!
   TBranch        *b_JpsiP_fP_fBits;   //!
   TBranch        *b_JpsiP_fP_fX;   //!
   TBranch        *b_JpsiP_fP_fY;   //!
   TBranch        *b_JpsiP_fP_fZ;   //!
   TBranch        *b_JpsiP_fE;   //!
   TBranch        *b_CPM;   //!
   TBranch        *b_PU;   //!
   TBranch        *b_PriVtx;   //!
   TBranch        *b_nPriVtx;   //!
   TBranch        *b_Jpsict;   //!
   TBranch        *b_vertexWeight;   //!
   TBranch        *b_JpsictErr;   //!
   TBranch        *b_JpsiMassErr;   //!
   TBranch        *b_JpsiVprob;   //!

   fracs(TTree *tree=0);
   virtual ~fracs();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef fracs_cxx
fracs::fracs(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("DataFiles/SetOfCuts11_ctauScen0_FracLSB-1_FirstResults/Psi1S/tmpFiles/selEvents_data.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("DataFiles/SetOfCuts11_ctauScen0_FracLSB-1_FirstResults/Psi1S/tmpFiles/selEvents_data.root");
      }
      f->GetObject("selectedData",tree);

   }
   Init(tree);
}

fracs::~fracs()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t fracs::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t fracs::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void fracs::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("fUniqueID", &fUniqueID, &b_lepP_fUniqueID);
   fChain->SetBranchAddress("fBits", &fBits, &b_lepP_fBits);
   fChain->SetBranchAddress("fP.fUniqueID", &fP_fUniqueID, &b_lepP_fP_fUniqueID);
   fChain->SetBranchAddress("fP.fBits", &fP_fBits, &b_lepP_fP_fBits);
   fChain->SetBranchAddress("fP.fX", &fP_fX, &b_lepP_fP_fX);
   fChain->SetBranchAddress("fP.fY", &fP_fY, &b_lepP_fP_fY);
   fChain->SetBranchAddress("fP.fZ", &fP_fZ, &b_lepP_fP_fZ);
   fChain->SetBranchAddress("fE", &fE, &b_lepP_fE);
//    fChain->SetBranchAddress("fUniqueID", &fUniqueID, &b_lepN_fUniqueID);
//    fChain->SetBranchAddress("fBits", &fBits, &b_lepN_fBits);
//    fChain->SetBranchAddress("fP.fUniqueID", &fP_fUniqueID, &b_lepN_fP_fUniqueID);
//    fChain->SetBranchAddress("fP.fBits", &fP_fBits, &b_lepN_fP_fBits);
//    fChain->SetBranchAddress("fP.fX", &fP_fX, &b_lepN_fP_fX);
//    fChain->SetBranchAddress("fP.fY", &fP_fY, &b_lepN_fP_fY);
//    fChain->SetBranchAddress("fP.fZ", &fP_fZ, &b_lepN_fP_fZ);
//    fChain->SetBranchAddress("fE", &fE, &b_lepN_fE);
//    fChain->SetBranchAddress("fUniqueID", &fUniqueID, &b_JpsiP_fUniqueID);
//    fChain->SetBranchAddress("fBits", &fBits, &b_JpsiP_fBits);
//    fChain->SetBranchAddress("fP.fUniqueID", &fP_fUniqueID, &b_JpsiP_fP_fUniqueID);
//    fChain->SetBranchAddress("fP.fBits", &fP_fBits, &b_JpsiP_fP_fBits);
//    fChain->SetBranchAddress("fP.fX", &fP_fX, &b_JpsiP_fP_fX);
//    fChain->SetBranchAddress("fP.fY", &fP_fY, &b_JpsiP_fP_fY);
//    fChain->SetBranchAddress("fP.fZ", &fP_fZ, &b_JpsiP_fP_fZ);
//    fChain->SetBranchAddress("fE", &fE, &b_JpsiP_fE);
   fChain->SetBranchAddress("CPM", &CPM, &b_CPM);
   fChain->SetBranchAddress("PU", &PU, &b_PU);
   fChain->SetBranchAddress("PriVtx", &PriVtx, &b_PriVtx);
   fChain->SetBranchAddress("nPriVtx", &nPriVtx, &b_nPriVtx);
   fChain->SetBranchAddress("Jpsict", &Jpsict, &b_Jpsict);
   fChain->SetBranchAddress("vertexWeight", &vertexWeight, &b_vertexWeight);
   fChain->SetBranchAddress("JpsictErr", &JpsictErr, &b_JpsictErr);
   fChain->SetBranchAddress("JpsiMassErr", &JpsiMassErr, &b_JpsiMassErr);
   fChain->SetBranchAddress("JpsiVprob", &JpsiVprob, &b_JpsiVprob);
   Notify();
}

Bool_t fracs::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void fracs::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t fracs::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef fracs_cxx
