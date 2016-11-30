#define PolData_cxx
#include "PolData.h"
#include "commonVar.h"
//#include "isMuonInAcceptance.C"
#include "effsAndCuts.h"

#include "TLorentzVector.h"
#include <TH2.h>
#include <TCanvas.h>



//some statistics
TH1F *Reco_StatEv;
TH1F *Reco_Onia_mass[onia::kNbPTMaxBins+1][onia::kNbRapForPTBins+1][onia::NXBINS+1];
TH2F *Reco_Onia_rap_pT;
TH1F *Reco_Onia_CPMPU[onia::NXBINS+1][25];
TH1F *Reco_Onia_pt[onia::kNbRapForPTBins+1];
TH1F *Reco_Onia_rap[onia::kNbPTMaxBins+1];
TH1F *Reco_Onia_rapcpm[onia::NXBINS+1];
TH1F *Reco_Onia_cpm[onia::kNbPTMaxBins+1];
TH2F *Reco_Onia_rap_cpm;
TH1F *Reco_Onia_CPMPUbinned[onia::NXBINS];
TH1F *Reco_Onia_CPMPU_intNCH[25];
TH2F *Reco_Onia_pT_cpm;
TTree *treeOut;
TLorentzVector *lepP, *lepN;
Int_t RunID;
Double_t mean[25];
Double_t privtx[25];
//Double_t nPriVtxRange[nPriVtxBins+1] = {0,2,4,6,8,10,12,14,16,18,20,22,24,26};
//Double_t nPriVtxRange[nPriVtxBins+1] = {1,3,5,7,9,11,13,15,17,19,21,23,25,27};

Double_t runningsumnPriVtxBins[onia::NXBINS][25];
Double_t neventsnPriVtxBins[onia::NXBINS+1][25];
Double_t runningsumIntNprivtx[onia::NXBINS+1];
Double_t runningsumforstddevIntNprivtx[onia::NXBINS+1];
Double_t neventsnIntNprivtx[onia::NXBINS+1];
Double_t avgintprivtx[onia::NXBINS+1];
Double_t avgintprivtxerror[onia::NXBINS+1];

//TH1F *Nch[nPriVtxBins+1];
//TH1F *Reco_Onia_cpminPriVtx[nPriVtxBins+1];

//polarization histos:
// TH2F *Reco2D_Onia_pol_pT_rap[onia::kNbFrames][onia::kNbPTMaxBins+1][onia::kNbRapForPTBins+1];

enum {LOOSE,TIGHT};//set of muon fiducial cuts
//==============================================
void PolData::Loop(Int_t selDimuType, Bool_t rejectCowboys, Int_t FidCuts, bool UpsMC, bool RequestTrigger, bool selectSOFT, bool selectTIGHT, bool selectMIXED, bool selectNOTMIXED, bool Odd, bool Even)
{
  if (fChain == 0) return;
	double CPM;
	double PU;
	treeOut->Branch("CPM", &CPM, "CPM/D");

	treeOut->Branch("PU", &PU, "PU/D");
	
  Long64_t nentries = fChain->GetEntries();
  Long64_t cutAtRecEvent = nentries;
  Long64_t countRecEvent = 0;
  Double_t NchRunningSum = 0;
  Double_t NchAvg = 0;
  Double_t NchBinned[26];
  Double_t EventsBinned[26];
  Double_t BinnedNchAvg[26];
  Long64_t nb = 0;
  printf("number of entries = %d\n", (Int_t) nentries);

//  nentries=500000;
  //loop over the events
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
	
    if(jentry % 100000 == 0) printf("event %d\n", (Int_t) jentry);
    
    if(Odd){
      if(jentry % 2 == 0)
        continue;
  	}
  	
  	if(Even){
      if(jentry % 2 != 0)
        continue;
  	}
  	

    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);

    //if we process MC, we must ensure that we only consider
    //reconstructed events
    if(onia->Pt() > 990.)
      continue;

    if(JpsiVprob < 0.01)
      continue;

		double cut_nPriVtx=16;
		if(nPriVtx>cut_nPriVtx) continue;

    if(runNb>=165088 && runNb<=172868) RunID=1;
    if(runNb>=175971 && runNb<=178379) RunID=2;
    if(runNb>=178380 && runNb<=180252) RunID=3;

    if(selectTIGHT){
    if(
      !(
          (muPosPglobalchi2>-1 && muNegPglobalchi2>-1) &&
          (muPosPglobalchi2<10 && muNegPglobalchi2<10)&&
          (muPosPglobalMuonHits>0 && muNegPglobalMuonHits>0)
//          && (muPosPMuonMatchedStations>1, muNegPMuonMatchedStations>1)
      )
    ) continue;
    if(
      !(
          ismuPosTMOneStationTight==1 && ismuNegTMOneStationTight==1
      )
    ) continue;
//    if(JpsiDrM1 < 0.5) continue;
    }

    if(selectSOFT){
    if(
      !(
          ismuPosTMOneStationTight==1 && ismuNegTMOneStationTight==1
      )
    ) continue;
    }

    if(selectMIXED){
    	if(!(ismuPosTMOneStationTight==1&&ismuNegTMOneStationTight==1))
    	  continue;
    	if(muPosPglobalMuonHits>0)
    	  if( !(muPosPglobalchi2<10) )
    	    continue;
    	if(muNegPglobalMuonHits>0)
    	  if( !(muNegPglobalchi2<10) )
    	    continue;
    	if(muPosPglobalMuonHits<=0) continue;
    	if(muNegPglobalMuonHits<=0) continue;

    }

    if(selectNOTMIXED){
    	if(!(ismuPosTMOneStationTight==1&&ismuNegTMOneStationTight==1))
    	    continue;
      if((muPosPglobalMuonHits>0 && muPosPglobalchi2<10) && (muNegPglobalMuonHits>0 && muNegPglobalchi2<10))
        continue;
    }

//    if(muPosPglobalOK!=1||muNegPglobalOK!=1) continue;

    Reco_StatEv->Fill(0.5);//count all events

    //check the trigger flag: 0... no trigger, 1 ... triggered+matched, 3 ... triggered (HLT_DoubleMu0)
    //for a full list of accessible triggers, check out "PolData.h"
    //and https://espace.cern.ch/cms-quarkonia/onia-polarization/L1%20%20HLT/unprescaledTriggersVsRun.aspx
    //for the run ranges per HLT path during unprescaled running periods

    Int_t trigDecision = -99;
    Int_t trigPtDecision = -99;
    
/*    if(//HLT_DoubleMu3_Quarkonium_v1 == 1 ||   //  5e32: 160404 - 161176
       //HLT_DoubleMu3_Upsilon_v1 == 1 ||      //  5e32: 161216 - 163261
       //HLT_Dimuon0_Barrel_Upsilon_v1 == 1 || //  5e32: 163269 - 163869
       HLT_Dimuon5_Upsilon_Barrel_v1 == 1 || //  1e33: 165088 - 166967 and 1.4E33: 167039 - 167043
       HLT_Dimuon5_Upsilon_Barrel_v2 == 1 || //  1e33: 166346
       HLT_Dimuon5_Upsilon_Barrel_v3 == 1)   //1.4e33: 167078 - 167913
      trigDecision = 1;
*/

  //Upsilon trigger paths:
   if(//HLT_DoubleMu3_Quarkonium_v1 == 1 ||   //  5e32: 160404 - 161176
      //HLT_DoubleMu3_Upsilon_v1 == 1 ||      //  5e32: 161216 - 163261
      //HLT_Dimuon0_Barrel_Upsilon_v1 == 1 || //  5e32: 163269 - 163869
      HLT_Dimuon5_Upsilon_Barrel_v1 == 1 || //  1e33: 165088 - 166967 and 1.4E33: 167039 - 167043
      HLT_Dimuon5_Upsilon_Barrel_v2 == 1 || //  1e33: 166346
      HLT_Dimuon5_Upsilon_Barrel_v3 == 1 ||  //1.4e33: 167078 - 167913 (prescale of 2)
      HLT_Dimuon5_Upsilon_Barrel_v5 == 1 || //2E33 (no cowboys)
      HLT_Dimuon7_Upsilon_Barrel_v1 == 1 || //3E33 (L1_DoubleMu0_HighQ; becomes inactive for Linst >= 5E33)
      HLT_Dimuon9_Upsilon_Barrel_v1 == 1 || //3E33 (L1_DoubleMu0_HighQ)
      HLT_Dimuon7_Upsilon_Barrel_v4 == 1 || //5E33 (becomes inactive for Linst >= 5E33)
      HLT_Dimuon9_Upsilon_Barrel_v4 == 1) //5E33
      trigDecision = 1;

   if(trigDecision != 1 && RequestTrigger)
     continue;


   if(//HLT_DoubleMu3_Quarkonium_v1 == 1 ||   //  5e32: 160404 - 161176
      //HLT_DoubleMu3_Upsilon_v1 == 1 ||      //  5e32: 161216 - 163261
      //HLT_Dimuon0_Barrel_Upsilon_v1 == 1 || //  5e32: 163269 - 163869
      HLT_Dimuon5_Upsilon_Barrel_v1 == 1 && onia->Pt() < 5.5 || //  1e33: 165088 - 166967 and 1.4E33: 167039 - 167043
      HLT_Dimuon5_Upsilon_Barrel_v2 == 1 && onia->Pt() < 5.5  || //  1e33: 166346
      HLT_Dimuon5_Upsilon_Barrel_v3 == 1 && onia->Pt() < 5.5  ||  //1.4e33: 167078 - 167913 (prescale of 2)
      HLT_Dimuon5_Upsilon_Barrel_v5 == 1 && onia->Pt() < 5.5  || //2E33 (no cowboys)
      HLT_Dimuon7_Upsilon_Barrel_v1 == 1 && onia->Pt() < 7.5  || //3E33 (L1_DoubleMu0_HighQ; becomes inactive for Linst >= 5E33)
      HLT_Dimuon9_Upsilon_Barrel_v1 == 1 && onia->Pt() < 9.5  || //3E33 (L1_DoubleMu0_HighQ)
      HLT_Dimuon7_Upsilon_Barrel_v4 == 1 && onia->Pt() < 7.5  || //5E33 (becomes inactive for Linst >= 5E33)
      HLT_Dimuon9_Upsilon_Barrel_v4 == 1 && onia->Pt() < 9.5 ) //5E33
      trigPtDecision = 1;

   if(trigPtDecision == 1)
     continue;




    //reject processing of events where the dimuon type (GG, GT or TT)
    //does not correspond to the chosen one
    // if(selDimuType < 3 && JpsiType != selDimuType)
    //   continue;
    // else if(selDimuType == 3 && JpsiType > 1) //only GG or GT
    //   continue;

    Reco_StatEv->Fill(1.5); //count all events

    Double_t onia_mass = onia->M();
    Double_t onia_pt = onia->Pt();
    Double_t onia_P = onia->P();
    Double_t onia_eta = onia->PseudoRapidity();
    Double_t onia_rap = onia->Rapidity();
    Double_t onia_phi = onia->Phi();
    Double_t onia_cpm = vertexWeight;
//    Int_t    onia_pv  = nPriVtx;
    Double_t onia_mT = sqrt(onia_mass*onia_mass + onia_pt*onia_pt);

    if(TMath::Abs(onia_rap) > onia::rapYPS)
      continue;
    Reco_StatEv->Fill(2.5);

    Double_t etaMuPos = muPos->PseudoRapidity();
    Double_t etaMuNeg = muNeg->PseudoRapidity();
    Double_t pTMuPos  = muPos->Pt();
    Double_t pTMuNeg  = muNeg->Pt();
    Double_t pMuPos   = muPos->P();
    Double_t pMuNeg   = muNeg->P();

    


	Double_t deltaPhi = muNeg->Phi() - muPos->Phi();
	if(deltaPhi > TMath::Pi()) deltaPhi -= 2.*TMath::Pi();
	else if(deltaPhi < -TMath::Pi()) deltaPhi += 2.*TMath::Pi();

	if(rejectCowboys)
		  if(deltaPhi < 0.) continue;

	//if(rejectCowboys)
	//	if((muNeg->Phi() - muPos->Phi()) < 0.)
	//		continue;

    Reco_StatEv->Fill(3.5);

    //select events with a cut on the lifetime to reject NP J/psis:
    if(Jpsict > onia::JpsiCtauMax)
      continue;
    if(Jpsict < onia::JpsiCtauMin)
      continue;

    if(TMath::Abs(Jpsict/JpsictErr)<onia::JpsiCtauSigMin) continue;
    if(TMath::Abs(Jpsict/JpsictErr)>onia::JpsiCtauSigMax) continue;

    Reco_StatEv->Fill(4.5);

    if(onia_mass < 8.4 || onia_mass > 11.6) //all Upsilons triggered
      continue;
    // if(onia_mass < (9.45 - 2.*0.080) || onia_mass > (9.45 + 2.*0.080)) //Ups(1S) only
    //   continue;

    Reco_StatEv->Fill(5.5);

    //apply different fiducial cuts for the muon matched to the HLT leg or the TM leg
    //for simplicity we decided to apply the stronger cuts to the higher pT muon and not
    //strictly to the HLT muon
    Bool_t muonsInAcc = kFALSE;
    if(isMuonInAcceptance(FidCuts-1, pTMuPos, etaMuPos) && isMuonInAcceptance(FidCuts-1, pTMuNeg, etaMuNeg))
      muonsInAcc = kTRUE;
    if(!muonsInAcc)
      continue;

   Reco_StatEv->Fill(5.5);

   //reject furthermore all events in which one of the muons has a pT smaller than 3 GeV/c
   // if(pTMuPos < 3.0 || pTMuNeg < 3.0)
   //   continue;

   Reco_StatEv->Fill(6.5);
   //set up the pT and y indices
   Int_t rapForPTIndex = -1;
   for(int iRap = 0; iRap < onia::kNbRapForPTBins; iRap++){
     if(TMath::Abs(onia_rap) > onia::rapForPTRange[iRap] && TMath::Abs(onia_rap) < onia::rapForPTRange[iRap+1]){
       rapForPTIndex = iRap+1;
       break;
     }
   }
   
    Int_t pTIndex = -1;
    for(int iPT = 0; iPT < onia::kNbPTBins[rapForPTIndex]; iPT++){
      if(onia_pt > onia::pTRange[rapForPTIndex][iPT] && onia_pt < onia::pTRange[rapForPTIndex][iPT+1]){
	pTIndex = iPT+1;
	break;
      }
    }
    Int_t cpmIndex = -1;
    for(int iCPM = 0; iCPM < onia::NXBINS; iCPM++){
      if(onia_cpm > onia::cpmRange[iCPM] && onia_cpm < onia::cpmRange[iCPM+1]){
    cpmIndex = iCPM+1;
    break;
      }
    }
      
    Int_t rapIntegratedPTIndex = -1;
    for(int iPT = 0; iPT < onia::kNbPTBins[0]; iPT++){
      if(onia_pt > onia::pTRange[0][iPT] && onia_pt < onia::pTRange[0][iPT+1]){
	rapIntegratedPTIndex = iPT+1;
	break;
      }
    }
    Int_t rapIndex = -1;
    for(int iRap = 0; iRap < 2*onia::kNbRapBins; iRap++){
      if(onia_rap > onia::rapRange[iRap] && onia_rap < onia::rapRange[iRap+1]){
    	rapIndex = iRap;
    	break;
      }
    }


    
/*    Int_t privtxIndex = -1;
    for(int iPV = 0; iPV < 7; iPV++){
      if(onia_pv > nPriVtxRange[iPV] && onia_pv < nPriVtxRange[iPV+1]){
	privtxIndex = iPV+1;
	break;
      }
    } */


//	Reco_Onia_PU->Fill(onia_pv);

    Reco_Onia_rap_pT->Fill(onia_rap, onia_pt);
    Reco_Onia_rap_cpm->Fill(onia_rap, vertexWeight);
    Reco_Onia_pT_cpm->Fill(onia_pt, vertexWeight);
    Reco_Onia_mass[0][0][0]->Fill(onia_mass);
    Reco_Onia_rap[0]->Fill(onia_rap);
    Reco_Onia_pt[0]->Fill(onia_pt);
//    Reco_Onia_cpminPriVtx[0]->Fill(onia_cpm);
    Reco_Onia_cpm[0]->Fill(onia_cpm);
    Reco_Onia_rapcpm[0]->Fill(onia_rap);
    NchBinned[0]+= vertexWeight;
    EventsBinned[0]++;

if(onia::NXBINS == 5) {
if(nPriVtx == 1 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][0]+=vertexWeight; neventsnPriVtxBins[0][0]++;Reco_Onia_CPMPU[0][0]->Fill(vertexWeight);}
if(nPriVtx == 2 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][1]+=vertexWeight; neventsnPriVtxBins[0][1]++;Reco_Onia_CPMPU[0][1]->Fill(vertexWeight);}
if(nPriVtx == 3 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][2]+=vertexWeight; neventsnPriVtxBins[0][2]++;Reco_Onia_CPMPU[0][2]->Fill(vertexWeight);}
if(nPriVtx == 4 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][3]+=vertexWeight; neventsnPriVtxBins[0][3]++;Reco_Onia_CPMPU[0][3]->Fill(vertexWeight);}
if(nPriVtx == 5 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][4]+=vertexWeight; neventsnPriVtxBins[0][4]++;Reco_Onia_CPMPU[0][4]->Fill(vertexWeight);}
if(nPriVtx == 6 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][5]+=vertexWeight; neventsnPriVtxBins[0][5]++;Reco_Onia_CPMPU[0][5]->Fill(vertexWeight);}
if(nPriVtx == 7 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][6]+=vertexWeight; neventsnPriVtxBins[0][6]++;Reco_Onia_CPMPU[0][6]->Fill(vertexWeight);}
if(nPriVtx == 8 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][7]+=vertexWeight; neventsnPriVtxBins[0][7]++;Reco_Onia_CPMPU[0][7]->Fill(vertexWeight);}
if(nPriVtx == 9 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][8]+=vertexWeight; neventsnPriVtxBins[0][8]++;Reco_Onia_CPMPU[0][8]->Fill(vertexWeight);}
if(nPriVtx == 10 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][9]+=vertexWeight; neventsnPriVtxBins[0][9]++;Reco_Onia_CPMPU[0][9]->Fill(vertexWeight);}
if(nPriVtx == 11 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][10]+=vertexWeight; neventsnPriVtxBins[0][10]++;Reco_Onia_CPMPU[0][10]->Fill(vertexWeight);}
if(nPriVtx == 12 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][11]+=vertexWeight; neventsnPriVtxBins[0][11]++;Reco_Onia_CPMPU[0][11]->Fill(vertexWeight);}
if(nPriVtx == 13 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][12]+=vertexWeight; neventsnPriVtxBins[0][12]++;Reco_Onia_CPMPU[0][12]->Fill(vertexWeight);}
if(nPriVtx == 14 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][13]+=vertexWeight; neventsnPriVtxBins[0][13]++;Reco_Onia_CPMPU[0][13]->Fill(vertexWeight);}
if(nPriVtx == 15 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][14]+=vertexWeight; neventsnPriVtxBins[0][14]++;Reco_Onia_CPMPU[0][14]->Fill(vertexWeight);}
if(nPriVtx == 16 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][15]+=vertexWeight; neventsnPriVtxBins[0][15]++;Reco_Onia_CPMPU[0][15]->Fill(vertexWeight);}
if(nPriVtx == 17 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][16]+=vertexWeight; neventsnPriVtxBins[0][16]++;Reco_Onia_CPMPU[0][16]->Fill(vertexWeight);}
if(nPriVtx == 18 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][17]+=vertexWeight; neventsnPriVtxBins[0][17]++;Reco_Onia_CPMPU[0][17]->Fill(vertexWeight);}
if(nPriVtx == 19 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][18]+=vertexWeight; neventsnPriVtxBins[0][18]++;Reco_Onia_CPMPU[0][18]->Fill(vertexWeight);}
if(nPriVtx == 20 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][19]+=vertexWeight; neventsnPriVtxBins[0][19]++;Reco_Onia_CPMPU[0][19]->Fill(vertexWeight);}
if(nPriVtx == 21 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][20]+=vertexWeight; neventsnPriVtxBins[0][20]++;Reco_Onia_CPMPU[0][20]->Fill(vertexWeight);}
if(nPriVtx == 22 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][21]+=vertexWeight; neventsnPriVtxBins[0][21]++;Reco_Onia_CPMPU[0][21]->Fill(vertexWeight);}
if(nPriVtx == 23 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][22]+=vertexWeight; neventsnPriVtxBins[0][22]++;Reco_Onia_CPMPU[0][22]->Fill(vertexWeight);}
if(nPriVtx == 24 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][23]+=vertexWeight; neventsnPriVtxBins[0][23]++;Reco_Onia_CPMPU[0][23]->Fill(vertexWeight);}
if(nPriVtx == 25 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][24]+=vertexWeight; neventsnPriVtxBins[0][24]++;Reco_Onia_CPMPU[0][24]->Fill(vertexWeight);}

if(nPriVtx == 1 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][0]+=vertexWeight; neventsnPriVtxBins[1][0]++;Reco_Onia_CPMPU[1][0]->Fill(vertexWeight);}
if(nPriVtx == 2 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][1]+=vertexWeight; neventsnPriVtxBins[1][1]++;Reco_Onia_CPMPU[1][1]->Fill(vertexWeight);}
if(nPriVtx == 3 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][2]+=vertexWeight; neventsnPriVtxBins[1][2]++;Reco_Onia_CPMPU[1][2]->Fill(vertexWeight);}
if(nPriVtx == 4 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][3]+=vertexWeight; neventsnPriVtxBins[1][3]++;Reco_Onia_CPMPU[1][3]->Fill(vertexWeight);}
if(nPriVtx == 5 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][4]+=vertexWeight; neventsnPriVtxBins[1][4]++;Reco_Onia_CPMPU[1][4]->Fill(vertexWeight);}
if(nPriVtx == 6 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][5]+=vertexWeight; neventsnPriVtxBins[1][5]++;Reco_Onia_CPMPU[1][5]->Fill(vertexWeight);}
if(nPriVtx == 7 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][6]+=vertexWeight; neventsnPriVtxBins[1][6]++;Reco_Onia_CPMPU[1][6]->Fill(vertexWeight);}
if(nPriVtx == 8 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][7]+=vertexWeight; neventsnPriVtxBins[1][7]++;Reco_Onia_CPMPU[1][7]->Fill(vertexWeight);}
if(nPriVtx == 9 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][8]+=vertexWeight; neventsnPriVtxBins[1][8]++;Reco_Onia_CPMPU[1][8]->Fill(vertexWeight);}
if(nPriVtx == 10 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][9]+=vertexWeight; neventsnPriVtxBins[1][9]++;Reco_Onia_CPMPU[1][9]->Fill(vertexWeight);}
if(nPriVtx == 11 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][10]+=vertexWeight; neventsnPriVtxBins[1][10]++;Reco_Onia_CPMPU[1][10]->Fill(vertexWeight);}
if(nPriVtx == 12 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][11]+=vertexWeight; neventsnPriVtxBins[1][11]++;Reco_Onia_CPMPU[1][11]->Fill(vertexWeight);}
if(nPriVtx == 13 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][12]+=vertexWeight; neventsnPriVtxBins[1][12]++;Reco_Onia_CPMPU[1][12]->Fill(vertexWeight);}
if(nPriVtx == 14 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][13]+=vertexWeight; neventsnPriVtxBins[1][13]++;Reco_Onia_CPMPU[1][13]->Fill(vertexWeight);}
if(nPriVtx == 15 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][14]+=vertexWeight; neventsnPriVtxBins[1][14]++;Reco_Onia_CPMPU[1][14]->Fill(vertexWeight);}
if(nPriVtx == 16 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][15]+=vertexWeight; neventsnPriVtxBins[1][15]++;Reco_Onia_CPMPU[1][15]->Fill(vertexWeight);}
if(nPriVtx == 17 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][16]+=vertexWeight; neventsnPriVtxBins[1][16]++;Reco_Onia_CPMPU[1][16]->Fill(vertexWeight);}
if(nPriVtx == 18 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][17]+=vertexWeight; neventsnPriVtxBins[1][17]++;Reco_Onia_CPMPU[1][17]->Fill(vertexWeight);}
if(nPriVtx == 19 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][18]+=vertexWeight; neventsnPriVtxBins[1][18]++;Reco_Onia_CPMPU[1][18]->Fill(vertexWeight);}
if(nPriVtx == 20 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][19]+=vertexWeight; neventsnPriVtxBins[1][19]++;Reco_Onia_CPMPU[1][19]->Fill(vertexWeight);}
if(nPriVtx == 21 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][20]+=vertexWeight; neventsnPriVtxBins[1][20]++;Reco_Onia_CPMPU[1][20]->Fill(vertexWeight);}
if(nPriVtx == 22 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][21]+=vertexWeight; neventsnPriVtxBins[1][21]++;Reco_Onia_CPMPU[1][21]->Fill(vertexWeight);}
if(nPriVtx == 23 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][22]+=vertexWeight; neventsnPriVtxBins[1][22]++;Reco_Onia_CPMPU[1][22]->Fill(vertexWeight);}
if(nPriVtx == 24 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][23]+=vertexWeight; neventsnPriVtxBins[1][23]++;Reco_Onia_CPMPU[1][23]->Fill(vertexWeight);}
if(nPriVtx == 25 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][24]+=vertexWeight; neventsnPriVtxBins[1][24]++;Reco_Onia_CPMPU[1][24]->Fill(vertexWeight);}

if(nPriVtx == 1 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][0]+=vertexWeight; neventsnPriVtxBins[2][0]++;Reco_Onia_CPMPU[2][0]->Fill(vertexWeight);}
if(nPriVtx == 2 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][1]+=vertexWeight; neventsnPriVtxBins[2][1]++;Reco_Onia_CPMPU[2][1]->Fill(vertexWeight);}
if(nPriVtx == 3 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][2]+=vertexWeight; neventsnPriVtxBins[2][2]++;Reco_Onia_CPMPU[2][2]->Fill(vertexWeight);}
if(nPriVtx == 4 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][3]+=vertexWeight; neventsnPriVtxBins[2][3]++;Reco_Onia_CPMPU[2][3]->Fill(vertexWeight);}
if(nPriVtx == 5 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][4]+=vertexWeight; neventsnPriVtxBins[2][4]++;Reco_Onia_CPMPU[2][4]->Fill(vertexWeight);}
if(nPriVtx == 6 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][5]+=vertexWeight; neventsnPriVtxBins[2][5]++;Reco_Onia_CPMPU[2][5]->Fill(vertexWeight);}
if(nPriVtx == 7 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][6]+=vertexWeight; neventsnPriVtxBins[2][6]++;Reco_Onia_CPMPU[2][6]->Fill(vertexWeight);}
if(nPriVtx == 8 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][7]+=vertexWeight; neventsnPriVtxBins[2][7]++;Reco_Onia_CPMPU[2][7]->Fill(vertexWeight);}
if(nPriVtx == 9 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][8]+=vertexWeight; neventsnPriVtxBins[2][8]++;Reco_Onia_CPMPU[2][8]->Fill(vertexWeight);}
if(nPriVtx == 10 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][9]+=vertexWeight; neventsnPriVtxBins[2][9]++;Reco_Onia_CPMPU[2][9]->Fill(vertexWeight);}
if(nPriVtx == 11 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][10]+=vertexWeight; neventsnPriVtxBins[2][10]++;Reco_Onia_CPMPU[2][10]->Fill(vertexWeight);}
if(nPriVtx == 12 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][11]+=vertexWeight; neventsnPriVtxBins[2][11]++;Reco_Onia_CPMPU[2][11]->Fill(vertexWeight);}
if(nPriVtx == 13 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][12]+=vertexWeight; neventsnPriVtxBins[2][12]++;Reco_Onia_CPMPU[2][12]->Fill(vertexWeight);}
if(nPriVtx == 14 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][13]+=vertexWeight; neventsnPriVtxBins[2][13]++;Reco_Onia_CPMPU[2][13]->Fill(vertexWeight);}
if(nPriVtx == 15 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][14]+=vertexWeight; neventsnPriVtxBins[2][14]++;Reco_Onia_CPMPU[2][14]->Fill(vertexWeight);}
if(nPriVtx == 16 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][15]+=vertexWeight; neventsnPriVtxBins[2][15]++;Reco_Onia_CPMPU[2][15]->Fill(vertexWeight);}
if(nPriVtx == 17 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][16]+=vertexWeight; neventsnPriVtxBins[2][16]++;Reco_Onia_CPMPU[2][16]->Fill(vertexWeight);}
if(nPriVtx == 18 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][17]+=vertexWeight; neventsnPriVtxBins[2][17]++;Reco_Onia_CPMPU[2][17]->Fill(vertexWeight);}
if(nPriVtx == 19 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][18]+=vertexWeight; neventsnPriVtxBins[2][18]++;Reco_Onia_CPMPU[2][18]->Fill(vertexWeight);}
if(nPriVtx == 20 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][19]+=vertexWeight; neventsnPriVtxBins[2][19]++;Reco_Onia_CPMPU[2][19]->Fill(vertexWeight);}
if(nPriVtx == 21 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][20]+=vertexWeight; neventsnPriVtxBins[2][20]++;Reco_Onia_CPMPU[2][20]->Fill(vertexWeight);}
if(nPriVtx == 22 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][21]+=vertexWeight; neventsnPriVtxBins[2][21]++;Reco_Onia_CPMPU[2][21]->Fill(vertexWeight);}
if(nPriVtx == 23 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][22]+=vertexWeight; neventsnPriVtxBins[2][22]++;Reco_Onia_CPMPU[2][22]->Fill(vertexWeight);}
if(nPriVtx == 24 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][23]+=vertexWeight; neventsnPriVtxBins[2][23]++;Reco_Onia_CPMPU[2][23]->Fill(vertexWeight);}
if(nPriVtx == 25 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][24]+=vertexWeight; neventsnPriVtxBins[2][24]++;Reco_Onia_CPMPU[2][24]->Fill(vertexWeight);}

if(nPriVtx == 1 && (vertexWeight > 30 && vertexWeight < 40)) {runningsumnPriVtxBins[3][0]+=vertexWeight; neventsnPriVtxBins[3][0]++;Reco_Onia_CPMPU[3][0]->Fill(vertexWeight);}
if(nPriVtx == 2 && (vertexWeight > 30 && vertexWeight < 40)) {runningsumnPriVtxBins[3][1]+=vertexWeight; neventsnPriVtxBins[3][1]++;Reco_Onia_CPMPU[3][1]->Fill(vertexWeight);}
if(nPriVtx == 3 && (vertexWeight > 30 && vertexWeight < 40)) {runningsumnPriVtxBins[3][2]+=vertexWeight; neventsnPriVtxBins[3][2]++;Reco_Onia_CPMPU[3][2]->Fill(vertexWeight);}
if(nPriVtx == 4 && (vertexWeight > 30 && vertexWeight < 40)) {runningsumnPriVtxBins[3][3]+=vertexWeight; neventsnPriVtxBins[3][3]++;Reco_Onia_CPMPU[3][3]->Fill(vertexWeight);}
if(nPriVtx == 5 && (vertexWeight > 30 && vertexWeight < 40)) {runningsumnPriVtxBins[3][4]+=vertexWeight; neventsnPriVtxBins[3][4]++;Reco_Onia_CPMPU[3][4]->Fill(vertexWeight);}
if(nPriVtx == 6 && (vertexWeight > 30 && vertexWeight < 40)) {runningsumnPriVtxBins[3][5]+=vertexWeight; neventsnPriVtxBins[3][5]++;Reco_Onia_CPMPU[3][5]->Fill(vertexWeight);}
if(nPriVtx == 7 && (vertexWeight > 30 && vertexWeight < 40)) {runningsumnPriVtxBins[3][6]+=vertexWeight; neventsnPriVtxBins[3][6]++;Reco_Onia_CPMPU[3][6]->Fill(vertexWeight);}
if(nPriVtx == 8 && (vertexWeight > 30 && vertexWeight < 40)) {runningsumnPriVtxBins[3][7]+=vertexWeight; neventsnPriVtxBins[3][7]++;Reco_Onia_CPMPU[3][7]->Fill(vertexWeight);}
if(nPriVtx == 9 && (vertexWeight > 30 && vertexWeight < 40)) {runningsumnPriVtxBins[3][8]+=vertexWeight; neventsnPriVtxBins[3][8]++;Reco_Onia_CPMPU[3][8]->Fill(vertexWeight);}
if(nPriVtx == 10 && (vertexWeight > 30 && vertexWeight < 40)) {runningsumnPriVtxBins[3][9]+=vertexWeight; neventsnPriVtxBins[3][9]++;Reco_Onia_CPMPU[3][9]->Fill(vertexWeight);}
if(nPriVtx == 11 && (vertexWeight > 30 && vertexWeight < 40)) {runningsumnPriVtxBins[3][10]+=vertexWeight; neventsnPriVtxBins[3][10]++;Reco_Onia_CPMPU[3][10]->Fill(vertexWeight);}
if(nPriVtx == 12 && (vertexWeight > 30 && vertexWeight < 40)) {runningsumnPriVtxBins[3][11]+=vertexWeight; neventsnPriVtxBins[3][11]++;Reco_Onia_CPMPU[3][11]->Fill(vertexWeight);}
if(nPriVtx == 13 && (vertexWeight > 30 && vertexWeight < 40)) {runningsumnPriVtxBins[3][12]+=vertexWeight; neventsnPriVtxBins[3][12]++;Reco_Onia_CPMPU[3][12]->Fill(vertexWeight);}
if(nPriVtx == 14 && (vertexWeight > 30 && vertexWeight < 40)) {runningsumnPriVtxBins[3][13]+=vertexWeight; neventsnPriVtxBins[3][13]++;Reco_Onia_CPMPU[3][13]->Fill(vertexWeight);}
if(nPriVtx == 15 && (vertexWeight > 30 && vertexWeight < 40)) {runningsumnPriVtxBins[3][14]+=vertexWeight; neventsnPriVtxBins[3][14]++;Reco_Onia_CPMPU[3][14]->Fill(vertexWeight);}
if(nPriVtx == 16 && (vertexWeight > 30 && vertexWeight < 40)) {runningsumnPriVtxBins[3][15]+=vertexWeight; neventsnPriVtxBins[3][15]++;Reco_Onia_CPMPU[3][15]->Fill(vertexWeight);}
if(nPriVtx == 17 && (vertexWeight > 30 && vertexWeight < 40)) {runningsumnPriVtxBins[3][16]+=vertexWeight; neventsnPriVtxBins[3][16]++;Reco_Onia_CPMPU[3][16]->Fill(vertexWeight);}
if(nPriVtx == 18 && (vertexWeight > 30 && vertexWeight < 40)) {runningsumnPriVtxBins[3][17]+=vertexWeight; neventsnPriVtxBins[3][17]++;Reco_Onia_CPMPU[3][17]->Fill(vertexWeight);}
if(nPriVtx == 19 && (vertexWeight > 30 && vertexWeight < 40)) {runningsumnPriVtxBins[3][18]+=vertexWeight; neventsnPriVtxBins[3][18]++;Reco_Onia_CPMPU[3][18]->Fill(vertexWeight);}
if(nPriVtx == 20 && (vertexWeight > 30 && vertexWeight < 40)) {runningsumnPriVtxBins[3][19]+=vertexWeight; neventsnPriVtxBins[3][19]++;Reco_Onia_CPMPU[3][19]->Fill(vertexWeight);}
if(nPriVtx == 21 && (vertexWeight > 30 && vertexWeight < 40)) {runningsumnPriVtxBins[3][20]+=vertexWeight; neventsnPriVtxBins[3][20]++;Reco_Onia_CPMPU[3][20]->Fill(vertexWeight);}
if(nPriVtx == 22 && (vertexWeight > 30 && vertexWeight < 40)) {runningsumnPriVtxBins[3][21]+=vertexWeight; neventsnPriVtxBins[3][21]++;Reco_Onia_CPMPU[3][21]->Fill(vertexWeight);}
if(nPriVtx == 23 && (vertexWeight > 30 && vertexWeight < 40)) {runningsumnPriVtxBins[3][22]+=vertexWeight; neventsnPriVtxBins[3][22]++;Reco_Onia_CPMPU[3][22]->Fill(vertexWeight);}
if(nPriVtx == 24 && (vertexWeight > 30 && vertexWeight < 40)) {runningsumnPriVtxBins[3][23]+=vertexWeight; neventsnPriVtxBins[3][23]++;Reco_Onia_CPMPU[3][23]->Fill(vertexWeight);}
if(nPriVtx == 25 && (vertexWeight > 30 && vertexWeight < 40)) {runningsumnPriVtxBins[3][24]+=vertexWeight; neventsnPriVtxBins[3][24]++;Reco_Onia_CPMPU[3][24]->Fill(vertexWeight);}

if(nPriVtx == 1 && (vertexWeight > 40 && vertexWeight < 60)) {runningsumnPriVtxBins[4][0]+=vertexWeight; neventsnPriVtxBins[4][0]++;Reco_Onia_CPMPU[4][0]->Fill(vertexWeight);}
if(nPriVtx == 2 && (vertexWeight > 40 && vertexWeight < 60)) {runningsumnPriVtxBins[4][1]+=vertexWeight; neventsnPriVtxBins[4][1]++;Reco_Onia_CPMPU[4][1]->Fill(vertexWeight);}
if(nPriVtx == 3 && (vertexWeight > 40 && vertexWeight < 60)) {runningsumnPriVtxBins[4][2]+=vertexWeight; neventsnPriVtxBins[4][2]++;Reco_Onia_CPMPU[4][2]->Fill(vertexWeight);}
if(nPriVtx == 4 && (vertexWeight > 40 && vertexWeight < 60)) {runningsumnPriVtxBins[4][3]+=vertexWeight; neventsnPriVtxBins[4][3]++;Reco_Onia_CPMPU[4][3]->Fill(vertexWeight);}
if(nPriVtx == 5 && (vertexWeight > 40 && vertexWeight < 60)) {runningsumnPriVtxBins[4][4]+=vertexWeight; neventsnPriVtxBins[4][4]++;Reco_Onia_CPMPU[4][4]->Fill(vertexWeight);}
if(nPriVtx == 6 && (vertexWeight > 40 && vertexWeight < 60)) {runningsumnPriVtxBins[4][5]+=vertexWeight; neventsnPriVtxBins[4][5]++;Reco_Onia_CPMPU[4][5]->Fill(vertexWeight);}
if(nPriVtx == 7 && (vertexWeight > 40 && vertexWeight < 60)) {runningsumnPriVtxBins[4][6]+=vertexWeight; neventsnPriVtxBins[4][6]++;Reco_Onia_CPMPU[4][6]->Fill(vertexWeight);}
if(nPriVtx == 8 && (vertexWeight > 40 && vertexWeight < 60)) {runningsumnPriVtxBins[4][7]+=vertexWeight; neventsnPriVtxBins[4][7]++;Reco_Onia_CPMPU[4][7]->Fill(vertexWeight);}
if(nPriVtx == 9 && (vertexWeight > 40 && vertexWeight < 60)) {runningsumnPriVtxBins[4][8]+=vertexWeight; neventsnPriVtxBins[4][8]++;Reco_Onia_CPMPU[4][8]->Fill(vertexWeight);}
if(nPriVtx == 10 && (vertexWeight > 40 && vertexWeight < 60)) {runningsumnPriVtxBins[4][9]+=vertexWeight; neventsnPriVtxBins[4][9]++;Reco_Onia_CPMPU[4][9]->Fill(vertexWeight);}
if(nPriVtx == 11 && (vertexWeight > 40 && vertexWeight < 60)) {runningsumnPriVtxBins[4][10]+=vertexWeight; neventsnPriVtxBins[4][10]++;Reco_Onia_CPMPU[4][10]->Fill(vertexWeight);}
if(nPriVtx == 12 && (vertexWeight > 40 && vertexWeight < 60)) {runningsumnPriVtxBins[4][11]+=vertexWeight; neventsnPriVtxBins[4][11]++;Reco_Onia_CPMPU[4][11]->Fill(vertexWeight);}
if(nPriVtx == 13 && (vertexWeight > 40 && vertexWeight < 60)) {runningsumnPriVtxBins[4][12]+=vertexWeight; neventsnPriVtxBins[4][12]++;Reco_Onia_CPMPU[4][12]->Fill(vertexWeight);}
if(nPriVtx == 14 && (vertexWeight > 40 && vertexWeight < 60)) {runningsumnPriVtxBins[4][13]+=vertexWeight; neventsnPriVtxBins[4][13]++;Reco_Onia_CPMPU[4][13]->Fill(vertexWeight);}
if(nPriVtx == 15 && (vertexWeight > 40 && vertexWeight < 60)) {runningsumnPriVtxBins[4][14]+=vertexWeight; neventsnPriVtxBins[4][14]++;Reco_Onia_CPMPU[4][14]->Fill(vertexWeight);}
if(nPriVtx == 16 && (vertexWeight > 40 && vertexWeight < 60)) {runningsumnPriVtxBins[4][15]+=vertexWeight; neventsnPriVtxBins[4][15]++;Reco_Onia_CPMPU[4][15]->Fill(vertexWeight);}
if(nPriVtx == 17 && (vertexWeight > 40 && vertexWeight < 60)) {runningsumnPriVtxBins[4][16]+=vertexWeight; neventsnPriVtxBins[4][16]++;Reco_Onia_CPMPU[4][16]->Fill(vertexWeight);}
if(nPriVtx == 18 && (vertexWeight > 40 && vertexWeight < 60)) {runningsumnPriVtxBins[4][17]+=vertexWeight; neventsnPriVtxBins[4][17]++;Reco_Onia_CPMPU[4][17]->Fill(vertexWeight);}
if(nPriVtx == 19 && (vertexWeight > 40 && vertexWeight < 60)) {runningsumnPriVtxBins[4][18]+=vertexWeight; neventsnPriVtxBins[4][18]++;Reco_Onia_CPMPU[4][18]->Fill(vertexWeight);}
if(nPriVtx == 20 && (vertexWeight > 40 && vertexWeight < 60)) {runningsumnPriVtxBins[4][19]+=vertexWeight; neventsnPriVtxBins[4][19]++;Reco_Onia_CPMPU[4][19]->Fill(vertexWeight);}
if(nPriVtx == 21 && (vertexWeight > 40 && vertexWeight < 60)) {runningsumnPriVtxBins[4][20]+=vertexWeight; neventsnPriVtxBins[4][20]++;Reco_Onia_CPMPU[4][20]->Fill(vertexWeight);}
if(nPriVtx == 22 && (vertexWeight > 40 && vertexWeight < 60)) {runningsumnPriVtxBins[4][21]+=vertexWeight; neventsnPriVtxBins[4][21]++;Reco_Onia_CPMPU[4][21]->Fill(vertexWeight);}
if(nPriVtx == 23 && (vertexWeight > 40 && vertexWeight < 60)) {runningsumnPriVtxBins[4][22]+=vertexWeight; neventsnPriVtxBins[4][22]++;Reco_Onia_CPMPU[4][22]->Fill(vertexWeight);}
if(nPriVtx == 24 && (vertexWeight > 40 && vertexWeight < 60)) {runningsumnPriVtxBins[4][23]+=vertexWeight; neventsnPriVtxBins[4][23]++;Reco_Onia_CPMPU[4][23]->Fill(vertexWeight);}
if(nPriVtx == 25 && (vertexWeight > 40 && vertexWeight < 60)) {runningsumnPriVtxBins[4][24]+=vertexWeight; neventsnPriVtxBins[4][24]++;Reco_Onia_CPMPU[4][24]->Fill(vertexWeight);}

if(nPriVtx == 1 ) {Reco_Onia_CPMPU_intNCH[0]->Fill(vertexWeight);}
if(nPriVtx == 2 ) {Reco_Onia_CPMPU_intNCH[1]->Fill(vertexWeight);}
if(nPriVtx == 3 ) {Reco_Onia_CPMPU_intNCH[2]->Fill(vertexWeight);}
if(nPriVtx == 4 ) {Reco_Onia_CPMPU_intNCH[3]->Fill(vertexWeight);}
if(nPriVtx == 5 ) {Reco_Onia_CPMPU_intNCH[4]->Fill(vertexWeight);}
if(nPriVtx == 6 ) {Reco_Onia_CPMPU_intNCH[5]->Fill(vertexWeight);}
if(nPriVtx == 7 ) {Reco_Onia_CPMPU_intNCH[6]->Fill(vertexWeight);}
if(nPriVtx == 8 ) {Reco_Onia_CPMPU_intNCH[7]->Fill(vertexWeight);}
if(nPriVtx == 9 ) {Reco_Onia_CPMPU_intNCH[8]->Fill(vertexWeight);}
if(nPriVtx == 10 ) {Reco_Onia_CPMPU_intNCH[9]->Fill(vertexWeight);}
if(nPriVtx == 11 ) {Reco_Onia_CPMPU_intNCH[10]->Fill(vertexWeight);}
if(nPriVtx == 12 ) {Reco_Onia_CPMPU_intNCH[11]->Fill(vertexWeight);}
if(nPriVtx == 13 ) {Reco_Onia_CPMPU_intNCH[12]->Fill(vertexWeight);}
if(nPriVtx == 14 ) {Reco_Onia_CPMPU_intNCH[13]->Fill(vertexWeight);}
if(nPriVtx == 15 ) {Reco_Onia_CPMPU_intNCH[14]->Fill(vertexWeight);}
if(nPriVtx == 16 ) {Reco_Onia_CPMPU_intNCH[15]->Fill(vertexWeight);}
if(nPriVtx == 17 ) {Reco_Onia_CPMPU_intNCH[16]->Fill(vertexWeight);}
if(nPriVtx == 18 ) {Reco_Onia_CPMPU_intNCH[17]->Fill(vertexWeight);}
if(nPriVtx == 19 ) {Reco_Onia_CPMPU_intNCH[18]->Fill(vertexWeight);}
if(nPriVtx == 20 ) {Reco_Onia_CPMPU_intNCH[19]->Fill(vertexWeight);}
if(nPriVtx == 21 ) {Reco_Onia_CPMPU_intNCH[20]->Fill(vertexWeight);}
if(nPriVtx == 22 ) {Reco_Onia_CPMPU_intNCH[21]->Fill(vertexWeight);}
if(nPriVtx == 23 ) {Reco_Onia_CPMPU_intNCH[22]->Fill(vertexWeight);}
if(nPriVtx == 24 ) {Reco_Onia_CPMPU_intNCH[23]->Fill(vertexWeight);}
if(nPriVtx == 25 ) {Reco_Onia_CPMPU_intNCH[24]->Fill(vertexWeight);}

if(vertexWeight > 0  && vertexWeight < 10) {runningsumforstddevIntNprivtx[0]+=vertexWeight*vertexWeight;runningsumIntNprivtx[0]+=vertexWeight; neventsnIntNprivtx[0]++; Reco_Onia_CPMPUbinned[0]->Fill(vertexWeight);}
if(vertexWeight > 10 && vertexWeight < 20) {runningsumforstddevIntNprivtx[1]+=vertexWeight*vertexWeight;runningsumIntNprivtx[1]+=vertexWeight; neventsnIntNprivtx[1]++; Reco_Onia_CPMPUbinned[1]->Fill(vertexWeight);}
if(vertexWeight > 20 && vertexWeight < 30) {runningsumforstddevIntNprivtx[2]+=vertexWeight*vertexWeight;runningsumIntNprivtx[2]+=vertexWeight; neventsnIntNprivtx[2]++; Reco_Onia_CPMPUbinned[2]->Fill(vertexWeight);}
if(vertexWeight > 30 && vertexWeight < 40) {runningsumforstddevIntNprivtx[3]+=vertexWeight*vertexWeight;runningsumIntNprivtx[3]+=vertexWeight; neventsnIntNprivtx[3]++; Reco_Onia_CPMPUbinned[3]->Fill(vertexWeight);}
if(vertexWeight > 40 && vertexWeight < 60) {runningsumforstddevIntNprivtx[4]+=vertexWeight*vertexWeight;runningsumIntNprivtx[4]+=vertexWeight; neventsnIntNprivtx[4]++; Reco_Onia_CPMPUbinned[4]->Fill(vertexWeight);}
}    
    
if(onia::NXBINS == 4) {
if(nPriVtx == 1 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][0]+=vertexWeight; neventsnPriVtxBins[0][0]++;Reco_Onia_CPMPU[0][0]->Fill(vertexWeight);}
if(nPriVtx == 2 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][1]+=vertexWeight; neventsnPriVtxBins[0][1]++;Reco_Onia_CPMPU[0][1]->Fill(vertexWeight);}
if(nPriVtx == 3 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][2]+=vertexWeight; neventsnPriVtxBins[0][2]++;Reco_Onia_CPMPU[0][2]->Fill(vertexWeight);}
if(nPriVtx == 4 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][3]+=vertexWeight; neventsnPriVtxBins[0][3]++;Reco_Onia_CPMPU[0][3]->Fill(vertexWeight);}
if(nPriVtx == 5 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][4]+=vertexWeight; neventsnPriVtxBins[0][4]++;Reco_Onia_CPMPU[0][4]->Fill(vertexWeight);}
if(nPriVtx == 6 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][5]+=vertexWeight; neventsnPriVtxBins[0][5]++;Reco_Onia_CPMPU[0][5]->Fill(vertexWeight);}
if(nPriVtx == 7 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][6]+=vertexWeight; neventsnPriVtxBins[0][6]++;Reco_Onia_CPMPU[0][6]->Fill(vertexWeight);}
if(nPriVtx == 8 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][7]+=vertexWeight; neventsnPriVtxBins[0][7]++;Reco_Onia_CPMPU[0][7]->Fill(vertexWeight);}
if(nPriVtx == 9 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][8]+=vertexWeight; neventsnPriVtxBins[0][8]++;Reco_Onia_CPMPU[0][8]->Fill(vertexWeight);}
if(nPriVtx == 10 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][9]+=vertexWeight; neventsnPriVtxBins[0][9]++;Reco_Onia_CPMPU[0][9]->Fill(vertexWeight);}
if(nPriVtx == 11 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][10]+=vertexWeight; neventsnPriVtxBins[0][10]++;Reco_Onia_CPMPU[0][10]->Fill(vertexWeight);}
if(nPriVtx == 12 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][11]+=vertexWeight; neventsnPriVtxBins[0][11]++;Reco_Onia_CPMPU[0][11]->Fill(vertexWeight);}
if(nPriVtx == 13 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][12]+=vertexWeight; neventsnPriVtxBins[0][12]++;Reco_Onia_CPMPU[0][12]->Fill(vertexWeight);}
if(nPriVtx == 14 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][13]+=vertexWeight; neventsnPriVtxBins[0][13]++;Reco_Onia_CPMPU[0][13]->Fill(vertexWeight);}
if(nPriVtx == 15 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][14]+=vertexWeight; neventsnPriVtxBins[0][14]++;Reco_Onia_CPMPU[0][14]->Fill(vertexWeight);}
if(nPriVtx == 16 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][15]+=vertexWeight; neventsnPriVtxBins[0][15]++;Reco_Onia_CPMPU[0][15]->Fill(vertexWeight);}
if(nPriVtx == 17 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][16]+=vertexWeight; neventsnPriVtxBins[0][16]++;Reco_Onia_CPMPU[0][16]->Fill(vertexWeight);}
if(nPriVtx == 18 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][17]+=vertexWeight; neventsnPriVtxBins[0][17]++;Reco_Onia_CPMPU[0][17]->Fill(vertexWeight);}
if(nPriVtx == 19 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][18]+=vertexWeight; neventsnPriVtxBins[0][18]++;Reco_Onia_CPMPU[0][18]->Fill(vertexWeight);}
if(nPriVtx == 20 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][19]+=vertexWeight; neventsnPriVtxBins[0][19]++;Reco_Onia_CPMPU[0][19]->Fill(vertexWeight);}
if(nPriVtx == 21 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][20]+=vertexWeight; neventsnPriVtxBins[0][20]++;Reco_Onia_CPMPU[0][20]->Fill(vertexWeight);}
if(nPriVtx == 22 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][21]+=vertexWeight; neventsnPriVtxBins[0][21]++;Reco_Onia_CPMPU[0][21]->Fill(vertexWeight);}
if(nPriVtx == 23 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][22]+=vertexWeight; neventsnPriVtxBins[0][22]++;Reco_Onia_CPMPU[0][22]->Fill(vertexWeight);}
if(nPriVtx == 24 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][23]+=vertexWeight; neventsnPriVtxBins[0][23]++;Reco_Onia_CPMPU[0][23]->Fill(vertexWeight);}
if(nPriVtx == 25 && (vertexWeight > 0 && vertexWeight < 10)) {runningsumnPriVtxBins[0][24]+=vertexWeight; neventsnPriVtxBins[0][24]++;Reco_Onia_CPMPU[0][24]->Fill(vertexWeight);}

if(nPriVtx == 1 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][0]+=vertexWeight; neventsnPriVtxBins[1][0]++;Reco_Onia_CPMPU[1][0]->Fill(vertexWeight);}
if(nPriVtx == 2 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][1]+=vertexWeight; neventsnPriVtxBins[1][1]++;Reco_Onia_CPMPU[1][1]->Fill(vertexWeight);}
if(nPriVtx == 3 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][2]+=vertexWeight; neventsnPriVtxBins[1][2]++;Reco_Onia_CPMPU[1][2]->Fill(vertexWeight);}
if(nPriVtx == 4 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][3]+=vertexWeight; neventsnPriVtxBins[1][3]++;Reco_Onia_CPMPU[1][3]->Fill(vertexWeight);}
if(nPriVtx == 5 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][4]+=vertexWeight; neventsnPriVtxBins[1][4]++;Reco_Onia_CPMPU[1][4]->Fill(vertexWeight);}
if(nPriVtx == 6 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][5]+=vertexWeight; neventsnPriVtxBins[1][5]++;Reco_Onia_CPMPU[1][5]->Fill(vertexWeight);}
if(nPriVtx == 7 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][6]+=vertexWeight; neventsnPriVtxBins[1][6]++;Reco_Onia_CPMPU[1][6]->Fill(vertexWeight);}
if(nPriVtx == 8 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][7]+=vertexWeight; neventsnPriVtxBins[1][7]++;Reco_Onia_CPMPU[1][7]->Fill(vertexWeight);}
if(nPriVtx == 9 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][8]+=vertexWeight; neventsnPriVtxBins[1][8]++;Reco_Onia_CPMPU[1][8]->Fill(vertexWeight);}
if(nPriVtx == 10 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][9]+=vertexWeight; neventsnPriVtxBins[1][9]++;Reco_Onia_CPMPU[1][9]->Fill(vertexWeight);}
if(nPriVtx == 11 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][10]+=vertexWeight; neventsnPriVtxBins[1][10]++;Reco_Onia_CPMPU[1][10]->Fill(vertexWeight);}
if(nPriVtx == 12 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][11]+=vertexWeight; neventsnPriVtxBins[1][11]++;Reco_Onia_CPMPU[1][11]->Fill(vertexWeight);}
if(nPriVtx == 13 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][12]+=vertexWeight; neventsnPriVtxBins[1][12]++;Reco_Onia_CPMPU[1][12]->Fill(vertexWeight);}
if(nPriVtx == 14 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][13]+=vertexWeight; neventsnPriVtxBins[1][13]++;Reco_Onia_CPMPU[1][13]->Fill(vertexWeight);}
if(nPriVtx == 15 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][14]+=vertexWeight; neventsnPriVtxBins[1][14]++;Reco_Onia_CPMPU[1][14]->Fill(vertexWeight);}
if(nPriVtx == 16 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][15]+=vertexWeight; neventsnPriVtxBins[1][15]++;Reco_Onia_CPMPU[1][15]->Fill(vertexWeight);}
if(nPriVtx == 17 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][16]+=vertexWeight; neventsnPriVtxBins[1][16]++;Reco_Onia_CPMPU[1][16]->Fill(vertexWeight);}
if(nPriVtx == 18 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][17]+=vertexWeight; neventsnPriVtxBins[1][17]++;Reco_Onia_CPMPU[1][17]->Fill(vertexWeight);}
if(nPriVtx == 19 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][18]+=vertexWeight; neventsnPriVtxBins[1][18]++;Reco_Onia_CPMPU[1][18]->Fill(vertexWeight);}
if(nPriVtx == 20 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][19]+=vertexWeight; neventsnPriVtxBins[1][19]++;Reco_Onia_CPMPU[1][19]->Fill(vertexWeight);}
if(nPriVtx == 21 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][20]+=vertexWeight; neventsnPriVtxBins[1][20]++;Reco_Onia_CPMPU[1][20]->Fill(vertexWeight);}
if(nPriVtx == 22 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][21]+=vertexWeight; neventsnPriVtxBins[1][21]++;Reco_Onia_CPMPU[1][21]->Fill(vertexWeight);}
if(nPriVtx == 23 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][22]+=vertexWeight; neventsnPriVtxBins[1][22]++;Reco_Onia_CPMPU[1][22]->Fill(vertexWeight);}
if(nPriVtx == 24 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][23]+=vertexWeight; neventsnPriVtxBins[1][23]++;Reco_Onia_CPMPU[1][23]->Fill(vertexWeight);}
if(nPriVtx == 25 && (vertexWeight > 10 && vertexWeight < 20)) {runningsumnPriVtxBins[1][24]+=vertexWeight; neventsnPriVtxBins[1][24]++;Reco_Onia_CPMPU[1][24]->Fill(vertexWeight);}

if(nPriVtx == 1 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][0]+=vertexWeight; neventsnPriVtxBins[2][0]++;Reco_Onia_CPMPU[2][0]->Fill(vertexWeight);}
if(nPriVtx == 2 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][1]+=vertexWeight; neventsnPriVtxBins[2][1]++;Reco_Onia_CPMPU[2][1]->Fill(vertexWeight);}
if(nPriVtx == 3 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][2]+=vertexWeight; neventsnPriVtxBins[2][2]++;Reco_Onia_CPMPU[2][2]->Fill(vertexWeight);}
if(nPriVtx == 4 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][3]+=vertexWeight; neventsnPriVtxBins[2][3]++;Reco_Onia_CPMPU[2][3]->Fill(vertexWeight);}
if(nPriVtx == 5 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][4]+=vertexWeight; neventsnPriVtxBins[2][4]++;Reco_Onia_CPMPU[2][4]->Fill(vertexWeight);}
if(nPriVtx == 6 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][5]+=vertexWeight; neventsnPriVtxBins[2][5]++;Reco_Onia_CPMPU[2][5]->Fill(vertexWeight);}
if(nPriVtx == 7 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][6]+=vertexWeight; neventsnPriVtxBins[2][6]++;Reco_Onia_CPMPU[2][6]->Fill(vertexWeight);}
if(nPriVtx == 8 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][7]+=vertexWeight; neventsnPriVtxBins[2][7]++;Reco_Onia_CPMPU[2][7]->Fill(vertexWeight);}
if(nPriVtx == 9 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][8]+=vertexWeight; neventsnPriVtxBins[2][8]++;Reco_Onia_CPMPU[2][8]->Fill(vertexWeight);}
if(nPriVtx == 10 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][9]+=vertexWeight; neventsnPriVtxBins[2][9]++;Reco_Onia_CPMPU[2][9]->Fill(vertexWeight);}
if(nPriVtx == 11 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][10]+=vertexWeight; neventsnPriVtxBins[2][10]++;Reco_Onia_CPMPU[2][10]->Fill(vertexWeight);}
if(nPriVtx == 12 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][11]+=vertexWeight; neventsnPriVtxBins[2][11]++;Reco_Onia_CPMPU[2][11]->Fill(vertexWeight);}
if(nPriVtx == 13 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][12]+=vertexWeight; neventsnPriVtxBins[2][12]++;Reco_Onia_CPMPU[2][12]->Fill(vertexWeight);}
if(nPriVtx == 14 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][13]+=vertexWeight; neventsnPriVtxBins[2][13]++;Reco_Onia_CPMPU[2][13]->Fill(vertexWeight);}
if(nPriVtx == 15 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][14]+=vertexWeight; neventsnPriVtxBins[2][14]++;Reco_Onia_CPMPU[2][14]->Fill(vertexWeight);}
if(nPriVtx == 16 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][15]+=vertexWeight; neventsnPriVtxBins[2][15]++;Reco_Onia_CPMPU[2][15]->Fill(vertexWeight);}
if(nPriVtx == 17 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][16]+=vertexWeight; neventsnPriVtxBins[2][16]++;Reco_Onia_CPMPU[2][16]->Fill(vertexWeight);}
if(nPriVtx == 18 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][17]+=vertexWeight; neventsnPriVtxBins[2][17]++;Reco_Onia_CPMPU[2][17]->Fill(vertexWeight);}
if(nPriVtx == 19 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][18]+=vertexWeight; neventsnPriVtxBins[2][18]++;Reco_Onia_CPMPU[2][18]->Fill(vertexWeight);}
if(nPriVtx == 20 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][19]+=vertexWeight; neventsnPriVtxBins[2][19]++;Reco_Onia_CPMPU[2][19]->Fill(vertexWeight);}
if(nPriVtx == 21 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][20]+=vertexWeight; neventsnPriVtxBins[2][20]++;Reco_Onia_CPMPU[2][20]->Fill(vertexWeight);}
if(nPriVtx == 22 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][21]+=vertexWeight; neventsnPriVtxBins[2][21]++;Reco_Onia_CPMPU[2][21]->Fill(vertexWeight);}
if(nPriVtx == 23 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][22]+=vertexWeight; neventsnPriVtxBins[2][22]++;Reco_Onia_CPMPU[2][22]->Fill(vertexWeight);}
if(nPriVtx == 24 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][23]+=vertexWeight; neventsnPriVtxBins[2][23]++;Reco_Onia_CPMPU[2][23]->Fill(vertexWeight);}
if(nPriVtx == 25 && (vertexWeight > 20 && vertexWeight < 30)) {runningsumnPriVtxBins[2][24]+=vertexWeight; neventsnPriVtxBins[2][24]++;Reco_Onia_CPMPU[2][24]->Fill(vertexWeight);}

if(nPriVtx == 1 && (vertexWeight > 30 && vertexWeight < 60)) {runningsumnPriVtxBins[3][0]+=vertexWeight; neventsnPriVtxBins[3][0]++;Reco_Onia_CPMPU[3][0]->Fill(vertexWeight);}
if(nPriVtx == 2 && (vertexWeight > 30 && vertexWeight < 60)) {runningsumnPriVtxBins[3][1]+=vertexWeight; neventsnPriVtxBins[3][1]++;Reco_Onia_CPMPU[3][1]->Fill(vertexWeight);}
if(nPriVtx == 3 && (vertexWeight > 30 && vertexWeight < 60)) {runningsumnPriVtxBins[3][2]+=vertexWeight; neventsnPriVtxBins[3][2]++;Reco_Onia_CPMPU[3][2]->Fill(vertexWeight);}
if(nPriVtx == 4 && (vertexWeight > 30 && vertexWeight < 60)) {runningsumnPriVtxBins[3][3]+=vertexWeight; neventsnPriVtxBins[3][3]++;Reco_Onia_CPMPU[3][3]->Fill(vertexWeight);}
if(nPriVtx == 5 && (vertexWeight > 30 && vertexWeight < 60)) {runningsumnPriVtxBins[3][4]+=vertexWeight; neventsnPriVtxBins[3][4]++;Reco_Onia_CPMPU[3][4]->Fill(vertexWeight);}
if(nPriVtx == 6 && (vertexWeight > 30 && vertexWeight < 60)) {runningsumnPriVtxBins[3][5]+=vertexWeight; neventsnPriVtxBins[3][5]++;Reco_Onia_CPMPU[3][5]->Fill(vertexWeight);}
if(nPriVtx == 7 && (vertexWeight > 30 && vertexWeight < 60)) {runningsumnPriVtxBins[3][6]+=vertexWeight; neventsnPriVtxBins[3][6]++;Reco_Onia_CPMPU[3][6]->Fill(vertexWeight);}
if(nPriVtx == 8 && (vertexWeight > 30 && vertexWeight < 60)) {runningsumnPriVtxBins[3][7]+=vertexWeight; neventsnPriVtxBins[3][7]++;Reco_Onia_CPMPU[3][7]->Fill(vertexWeight);}
if(nPriVtx == 9 && (vertexWeight > 30 && vertexWeight < 60)) {runningsumnPriVtxBins[3][8]+=vertexWeight; neventsnPriVtxBins[3][8]++;Reco_Onia_CPMPU[3][8]->Fill(vertexWeight);}
if(nPriVtx == 10 && (vertexWeight > 30 && vertexWeight < 60)) {runningsumnPriVtxBins[3][9]+=vertexWeight; neventsnPriVtxBins[3][9]++;Reco_Onia_CPMPU[3][9]->Fill(vertexWeight);}
if(nPriVtx == 11 && (vertexWeight > 30 && vertexWeight < 60)) {runningsumnPriVtxBins[3][10]+=vertexWeight; neventsnPriVtxBins[3][10]++;Reco_Onia_CPMPU[3][10]->Fill(vertexWeight);}
if(nPriVtx == 12 && (vertexWeight > 30 && vertexWeight < 60)) {runningsumnPriVtxBins[3][11]+=vertexWeight; neventsnPriVtxBins[3][11]++;Reco_Onia_CPMPU[3][11]->Fill(vertexWeight);}
if(nPriVtx == 13 && (vertexWeight > 30 && vertexWeight < 60)) {runningsumnPriVtxBins[3][12]+=vertexWeight; neventsnPriVtxBins[3][12]++;Reco_Onia_CPMPU[3][12]->Fill(vertexWeight);}
if(nPriVtx == 14 && (vertexWeight > 30 && vertexWeight < 60)) {runningsumnPriVtxBins[3][13]+=vertexWeight; neventsnPriVtxBins[3][13]++;Reco_Onia_CPMPU[3][13]->Fill(vertexWeight);}
if(nPriVtx == 15 && (vertexWeight > 30 && vertexWeight < 60)) {runningsumnPriVtxBins[3][14]+=vertexWeight; neventsnPriVtxBins[3][14]++;Reco_Onia_CPMPU[3][14]->Fill(vertexWeight);}
if(nPriVtx == 16 && (vertexWeight > 30 && vertexWeight < 60)) {runningsumnPriVtxBins[3][15]+=vertexWeight; neventsnPriVtxBins[3][15]++;Reco_Onia_CPMPU[3][15]->Fill(vertexWeight);}
if(nPriVtx == 17 && (vertexWeight > 30 && vertexWeight < 60)) {runningsumnPriVtxBins[3][16]+=vertexWeight; neventsnPriVtxBins[3][16]++;Reco_Onia_CPMPU[3][16]->Fill(vertexWeight);}
if(nPriVtx == 18 && (vertexWeight > 30 && vertexWeight < 60)) {runningsumnPriVtxBins[3][17]+=vertexWeight; neventsnPriVtxBins[3][17]++;Reco_Onia_CPMPU[3][17]->Fill(vertexWeight);}
if(nPriVtx == 19 && (vertexWeight > 30 && vertexWeight < 60)) {runningsumnPriVtxBins[3][18]+=vertexWeight; neventsnPriVtxBins[3][18]++;Reco_Onia_CPMPU[3][18]->Fill(vertexWeight);}
if(nPriVtx == 20 && (vertexWeight > 30 && vertexWeight < 60)) {runningsumnPriVtxBins[3][19]+=vertexWeight; neventsnPriVtxBins[3][19]++;Reco_Onia_CPMPU[3][19]->Fill(vertexWeight);}
if(nPriVtx == 21 && (vertexWeight > 30 && vertexWeight < 60)) {runningsumnPriVtxBins[3][20]+=vertexWeight; neventsnPriVtxBins[3][20]++;Reco_Onia_CPMPU[3][20]->Fill(vertexWeight);}
if(nPriVtx == 22 && (vertexWeight > 30 && vertexWeight < 60)) {runningsumnPriVtxBins[3][21]+=vertexWeight; neventsnPriVtxBins[3][21]++;Reco_Onia_CPMPU[3][21]->Fill(vertexWeight);}
if(nPriVtx == 23 && (vertexWeight > 30 && vertexWeight < 60)) {runningsumnPriVtxBins[3][22]+=vertexWeight; neventsnPriVtxBins[3][22]++;Reco_Onia_CPMPU[3][22]->Fill(vertexWeight);}
if(nPriVtx == 24 && (vertexWeight > 30 && vertexWeight < 60)) {runningsumnPriVtxBins[3][23]+=vertexWeight; neventsnPriVtxBins[3][23]++;Reco_Onia_CPMPU[3][23]->Fill(vertexWeight);}
if(nPriVtx == 25 && (vertexWeight > 30 && vertexWeight < 60)) {runningsumnPriVtxBins[3][24]+=vertexWeight; neventsnPriVtxBins[3][24]++;Reco_Onia_CPMPU[3][24]->Fill(vertexWeight);}

if(nPriVtx == 1 ) {Reco_Onia_CPMPU_intNCH[0]->Fill(vertexWeight);}
if(nPriVtx == 2 ) {Reco_Onia_CPMPU_intNCH[1]->Fill(vertexWeight);}
if(nPriVtx == 3 ) {Reco_Onia_CPMPU_intNCH[2]->Fill(vertexWeight);}
if(nPriVtx == 4 ) {Reco_Onia_CPMPU_intNCH[3]->Fill(vertexWeight);}
if(nPriVtx == 5 ) {Reco_Onia_CPMPU_intNCH[4]->Fill(vertexWeight);}
if(nPriVtx == 6 ) {Reco_Onia_CPMPU_intNCH[5]->Fill(vertexWeight);}
if(nPriVtx == 7 ) {Reco_Onia_CPMPU_intNCH[6]->Fill(vertexWeight);}
if(nPriVtx == 8 ) {Reco_Onia_CPMPU_intNCH[7]->Fill(vertexWeight);}
if(nPriVtx == 9 ) {Reco_Onia_CPMPU_intNCH[8]->Fill(vertexWeight);}
if(nPriVtx == 10 ) {Reco_Onia_CPMPU_intNCH[9]->Fill(vertexWeight);}
if(nPriVtx == 11 ) {Reco_Onia_CPMPU_intNCH[10]->Fill(vertexWeight);}
if(nPriVtx == 12 ) {Reco_Onia_CPMPU_intNCH[11]->Fill(vertexWeight);}
if(nPriVtx == 13 ) {Reco_Onia_CPMPU_intNCH[12]->Fill(vertexWeight);}
if(nPriVtx == 14 ) {Reco_Onia_CPMPU_intNCH[13]->Fill(vertexWeight);}
if(nPriVtx == 15 ) {Reco_Onia_CPMPU_intNCH[14]->Fill(vertexWeight);}
if(nPriVtx == 16 ) {Reco_Onia_CPMPU_intNCH[15]->Fill(vertexWeight);}
if(nPriVtx == 17 ) {Reco_Onia_CPMPU_intNCH[16]->Fill(vertexWeight);}
if(nPriVtx == 18 ) {Reco_Onia_CPMPU_intNCH[17]->Fill(vertexWeight);}
if(nPriVtx == 19 ) {Reco_Onia_CPMPU_intNCH[18]->Fill(vertexWeight);}
if(nPriVtx == 20 ) {Reco_Onia_CPMPU_intNCH[19]->Fill(vertexWeight);}
if(nPriVtx == 21 ) {Reco_Onia_CPMPU_intNCH[20]->Fill(vertexWeight);}
if(nPriVtx == 22 ) {Reco_Onia_CPMPU_intNCH[21]->Fill(vertexWeight);}
if(nPriVtx == 23 ) {Reco_Onia_CPMPU_intNCH[22]->Fill(vertexWeight);}
if(nPriVtx == 24 ) {Reco_Onia_CPMPU_intNCH[23]->Fill(vertexWeight);}
if(nPriVtx == 25 ) {Reco_Onia_CPMPU_intNCH[24]->Fill(vertexWeight);}

if(vertexWeight > 0  && vertexWeight < 10) {runningsumforstddevIntNprivtx[0]+=vertexWeight*vertexWeight;runningsumIntNprivtx[0]+=vertexWeight; neventsnIntNprivtx[0]++; Reco_Onia_CPMPUbinned[0]->Fill(vertexWeight);}
if(vertexWeight > 10 && vertexWeight < 20) {runningsumforstddevIntNprivtx[1]+=vertexWeight*vertexWeight;runningsumIntNprivtx[1]+=vertexWeight; neventsnIntNprivtx[1]++; Reco_Onia_CPMPUbinned[1]->Fill(vertexWeight);}
if(vertexWeight > 20 && vertexWeight < 30) {runningsumforstddevIntNprivtx[2]+=vertexWeight*vertexWeight;runningsumIntNprivtx[2]+=vertexWeight; neventsnIntNprivtx[2]++; Reco_Onia_CPMPUbinned[2]->Fill(vertexWeight);}
if(vertexWeight > 30 && vertexWeight < 60) {runningsumforstddevIntNprivtx[3]+=vertexWeight*vertexWeight;runningsumIntNprivtx[3]+=vertexWeight; neventsnIntNprivtx[3]++; Reco_Onia_CPMPUbinned[3]->Fill(vertexWeight);}
}

	if(rapIntegratedPTIndex >= 0 && cpmIndex >= 0){
      Reco_Onia_cpm[rapIntegratedPTIndex]->Fill(vertexWeight);
      Reco_Onia_rapcpm[cpmIndex]->Fill(onia_rap);
    }
    
    if(rapIntegratedPTIndex >= 0){
//      Reco_Onia_mass[rapIntegratedPTIndex][0][0]->Fill(onia_mass);
      Reco_Onia_rap[rapIntegratedPTIndex]->Fill(onia_rap);
    }
    if(rapForPTIndex > 0){
//      Reco_Onia_mass[0][rapForPTIndex][0]->Fill(onia_mass);
      Reco_Onia_pt[rapForPTIndex]->Fill(onia_pt);
    } 
    
    //if(cpmIndex >= 0){
  //    Reco_Onia_mass[0][0][cpmIndex]->Fill(onia_mass);
//	}

	if(rapIntegratedPTIndex >= 0){
    Reco_Onia_mass[rapIntegratedPTIndex][0][0]->Fill(onia_mass);
	  if(rapForPTIndex >= 0){		    
      Reco_Onia_mass[0][rapForPTIndex][0]->Fill(onia_mass);
	    if(cpmIndex >= 0){
	      Reco_Onia_mass[0][0][cpmIndex]->Fill(onia_mass);
		}
	  }
	}
	
	if(rapIntegratedPTIndex >= 0 && rapForPTIndex >= 0){
    Reco_Onia_mass[rapIntegratedPTIndex][rapForPTIndex][0]->Fill(onia_mass);
	  if(rapForPTIndex >= 0 && cpmIndex >= 0){	
	  Reco_Onia_mass[0][rapForPTIndex][cpmIndex]->Fill(onia_mass);
    	if(cpmIndex >= 0 && rapIntegratedPTIndex >= 0){
	  	Reco_Onia_mass[rapIntegratedPTIndex][0][cpmIndex]->Fill(onia_mass);
	  	}
	  }
	}
    
    //continue only if we have events within the bins we are interested in
    if(rapIndex < 0){
      // printf("rapIndex %d, rap(onia) = %f\n", rapIndex, onia_rap);
      continue;
    }
    if(rapForPTIndex < 1){
      // printf("rapForPTIndex %d, rap(onia) = %f\n", rapForPTIndex, onia_rap);
      continue;
    }
    if(pTIndex < 1){
      // printf("pTIndex %d, pT(onia) = %f\n", pTIndex, onia_pt);
      continue;
    }
        
    if(cpmIndex < 1){
      continue;
	}

    Reco_Onia_mass[pTIndex][rapForPTIndex][cpmIndex]->Fill(onia_mass);

    //remaining of the events will be used for the analysis
    countRecEvent++;
	CPM=vertexWeight;
  //  NchRunningSum+=vertexWeight;
//	PU=nPriVtx;

    lepP = muPos;
    lepN = muNeg;
    treeOut->Fill();
  }

//  BinnedNchAvg[0]=NchBinned[0]/EventsBinned[0];
//  for(int x = 0; x<14; x++) {
//    BinnedNchAvg[x]=NchBinned[x]/EventsBinned[x];
//    cout<<NchBinned[x]<<" divided by "<<EventsBinned[x]<<endl;
//    cout<<"bin "<<x<<" "<<BinnedNchAvg[x]<<endl;
 // }
 
 runningsumforstddevIntNprivtx[0]+=vertexWeight*vertexWeight;

for(int x = 0; x < onia::NXBINS; x++)
{
  avgintprivtx[x]=runningsumIntNprivtx[x]/neventsnIntNprivtx[x];
  cout<<"average is: "<<avgintprivtx[x]<<endl;
  
  avgintprivtxerror[x] = (sqrt(runningsumforstddevIntNprivtx[x]/neventsnIntNprivtx[x]-avgintprivtx[x]*avgintprivtx[x]))/sqrt(neventsnIntNprivtx[x]);
  
  cout<<"st dev is: "<<avgintprivtxerror[x]<<endl;
}
    
  printf("nb. of rec. events is %d of a total of %d events\n", (Int_t) countRecEvent, (Int_t) nentries);
//  printf("Total running Nch sum is: %d\n", (Int_t) NchRunningSum);
//  printf("Overall average Nch is: %f\n", BinnedNchAvg[0]);
}
