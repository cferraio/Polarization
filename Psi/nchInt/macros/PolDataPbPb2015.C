#define PolData_cxx
#include "PolData.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "commonVar.h"
#include "TLorentzVector.h"
#include <TH2.h>
#include <TCanvas.h>
#include "effsAndCuts.h"


TH1F *Reco_StatEv;
TH1F *Reco_Onia_mass[onia::kNbPTMaxBins+1][onia::kNbRapForPTBins+1];
TH2F *Reco_Onia_rap_pT;
TH1F *Reco_Onia_pt[onia::kNbRapForPTBins+1];
TH1F *Reco_Onia_rap[onia::kNbPTMaxBins+1];
TTree *treeOut;
TLorentzVector *lepP, *lepN, *jpsi;
Int_t RunID;

void PolData::Loop(int nState, bool rejectCowboys, int FidCuts, bool MC, bool RequestTrigger, bool removeEta0p2_0p3, bool cutDeltaREllDpt, bool officialMC)
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntries();

   Long64_t nbytes = 0, nb = 0;
   Long64_t count = 0;
   
   std::cout << "number of entries = " << nentries << std::endl;
   
   double jpsict = 0;
	double runnb = 0;
	double jpsictErr = 0;
	double jpsiMassErr = 0;
	double jpsiVprob = 0;

	treeOut->Branch("Jpsict", &jpsict, "Jpsict/D");
	treeOut->Branch("JpsictErr", &jpsictErr, "JpsictErr/D");
	treeOut->Branch("JpsiMassErr", &jpsiMassErr, "JpsiMassErr/D");
	treeOut->Branch("JpsiVprob", &jpsiVprob, "JpsiVprob/D");
	treeOut->Branch("runNb", &runnb, "runNb/D");
   
//   nentries=1000000;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
   
   if(jentry % 100000 == 0) std::cout << "event " << jentry << " of " << nentries << std::endl;
   
   Long64_t ientry = LoadTree(jentry);
   if (ientry < 0) break;
   nb = fChain->GetEntry(jentry);   nbytes += nb;
   // if (Cut(ientry) < 0) continue;
	
	
	for(int iQQ = 0; iQQ < Reco_QQ_size; iQQ++)
	{
	  
	  TLorentzVector *onia  = (TLorentzVector *) Reco_QQ_4mom->At(iQQ);
	  TLorentzVector *muPos = (TLorentzVector *) Reco_QQ_mupl_4mom->At(iQQ);
	  TLorentzVector *muNeg = (TLorentzVector *) Reco_QQ_mumi_4mom->At(iQQ);	  
	  
	  if(onia->Pt() > 990.) continue;
	  if(Reco_QQ_VtxProb[iQQ] < 0.01) continue;
	  
	  
	  Reco_StatEv->Fill(0.5);
	  
	  // count events after trigger
		Reco_StatEv->Fill(1.5); 

		double onia_mass = onia->M();
		double onia_pt = onia->Pt();
		double onia_P = onia->P();
		double onia_eta = onia->PseudoRapidity();
		double onia_rap = onia->Rapidity();
		double onia_phi = onia->Phi();
		double onia_mT = sqrt(onia_mass*onia_mass + onia_pt*onia_pt);
		
		// restrict to barrel for upsilon and jpsi
		if(TMath::Abs(onia_rap) > onia::rap) continue;
		// count events after cut in rapidity
		Reco_StatEv->Fill(2.5); 

		double etaMuPos = muPos->PseudoRapidity();
		double etaMuNeg = muNeg->PseudoRapidity();
		double pTMuPos = muPos->Pt();
		double pTMuNeg = muNeg->Pt();
		double pMuPos = muPos->P();
		double pMuNeg = muNeg->P();
		double deltaPhi = muNeg->Phi() - muPos->Phi();
		if(deltaPhi > TMath::Pi()) deltaPhi -= 2.*TMath::Pi();
		else if(deltaPhi < -TMath::Pi()) deltaPhi += 2.*TMath::Pi();

		if(rejectCowboys)
			if(deltaPhi < 0.)  continue;
		// count events after cowboy rejection
		Reco_StatEv->Fill(3.5);
		
		// select mass window
		double massMin = 0, massMax = 0;
		// different mass region for different states
		massMin = onia::massMin; 
		massMax = onia::massMax;
		if(onia_mass < massMin || onia_mass > massMax) continue;   
		// count events after restriction in mass
		Reco_StatEv->Fill(4.5);

		//apply fiducial cuts
		bool muonsInAcc = kFALSE;
		if(isMuonInAcceptance(FidCuts-1, pTMuPos, etaMuPos) && isMuonInAcceptance(FidCuts-1, pTMuNeg, etaMuNeg)){
			muonsInAcc = kTRUE;
		}

		if(!muonsInAcc) continue;
		// count events after fiducial cuts
		Reco_StatEv->Fill(5.5);

		if(removeEta0p2_0p3)
			if( (TMath::Abs(etaMuPos) > 0.2 && TMath::Abs(etaMuPos) < 0.3) || 
					(TMath::Abs(etaMuNeg) > 0.2 && TMath::Abs(etaMuNeg) < 0.3) )
				continue;

		Reco_StatEv->Fill(6.5);


		double deltaEta = etaMuNeg - etaMuPos;
		double deltaPT = pTMuNeg - pTMuPos;
		double deltaREll = TMath::Sqrt(deltaEta*deltaEta + TMath::Power(1.2*deltaPhi,2));
		double deltaREllDpt = TMath::Sqrt(deltaREll*deltaREll + TMath::Power(0.00157*deltaPT,2));

		if(cutDeltaREllDpt){
			if(onia_pt>35. && onia_pt<40. && deltaREllDpt<0.18) continue;
			if(onia_pt>40. && onia_pt<50. && deltaREllDpt<0.16) continue;
			if(onia_pt>50. && onia_pt<70. && deltaREllDpt<0.14) continue;
		}

		Reco_StatEv->Fill(7.5);

		// filling mass, pt and y histograms
		// indices [0] contain all events while [1], etc. show events according to the pt and y bin

		// all events
		Reco_Onia_rap_pT->Fill(onia_rap, onia_pt);
		Reco_Onia_mass[0][0]->Fill(onia_mass);
		Reco_Onia_rap[0]->Fill(onia_rap);
		Reco_Onia_pt[0]->Fill(onia_pt);

		for(int iRap = 0; iRap < onia::kNbRapForPTBins; iRap++){
			// events integrated in pt in different rapidity bins
			if(TMath::Abs(onia_rap) > onia::rapForPTRange[iRap] && TMath::Abs(onia_rap) < onia::rapForPTRange[iRap+1]){
				Reco_Onia_pt[iRap+1]->Fill(onia_pt);
				Reco_Onia_mass[0][iRap+1]->Fill(onia_mass);
			}//if

			for(int iPT = 0; iPT < onia::kNbPTMaxBins; iPT++){		
				// events for different pT and y bins
				if(onia_pt > onia::pTRange[0][iPT] && onia_pt < onia::pTRange[0][iPT+1] &&
						TMath::Abs(onia_rap) > onia::rapForPTRange[iRap] && TMath::Abs(onia_rap) < onia::rapForPTRange[iRap+1]){
					Reco_Onia_mass[iPT+1][iRap+1]->Fill(onia_mass);
				}//if
			} // iPT
		} // iRap

		for(int iPT = 0; iPT < onia::kNbPTMaxBins; iPT++){	
			// events integrated in rapidity for different pT bins
			if(onia_pt > onia::pTRange[0][iPT] && onia_pt < onia::pTRange[0][iPT+1]){
				Reco_Onia_rap[iPT+1]->Fill(onia_rap);
				Reco_Onia_mass[iPT+1][0]->Fill(onia_mass); 
			} // if
		} // iPT

		// fill tree
		lepP = muPos;
		lepN = muNeg;
		jpsi = onia;
		runnb = runNb;
		jpsict = Jpsict[iQQ];
		jpsictErr = JpsictErr[iQQ];
		jpsiMassErr = JpsiMassErr;
		jpsiVprob = Reco_QQ_VtxProb[iQQ];
		treeOut->Fill();

		//remaining of the events will be used for the analysis
		count++;

	
	}
   }
   
   std::cout << "number of reconstructed events: " << count << " of a total of " << nentries << " events" << std::endl;
}
