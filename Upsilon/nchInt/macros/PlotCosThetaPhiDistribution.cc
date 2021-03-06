/*
 * PlotCosThetaDistribution.cc
 *
 *  Created on: Dec 8, 2011
 *      Author: valentinknuenz
 */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "rootIncludes.inc"
#include "commonVar.h"

#include "TH2.h"
#include "TH1.h"

Int_t const pT_binsFOR1Dhists=onia::kNbPTMaxBins;
Int_t const Rap_binsFOR1Dhists=onia::kNbRapForPTBins;

TH2D* CosThPhDist[onia::kNbFrames][onia::kNbRapForPTBins+1][onia::kNbPTMaxBins+1];
TH1D* CosThDist[onia::kNbFrames][onia::kNbRapForPTBins+1][onia::kNbPTMaxBins+1];
TH1D* PhiDist[onia::kNbFrames][onia::kNbRapForPTBins+1][onia::kNbPTMaxBins+1];

int nBins1DCosth=20;//20
int nBins1DPhi=18;//18

void LoadHistos(Int_t iRapBin, Int_t iPTBin, int nState, Char_t *DataPath);
void PlotHistos(Int_t iRapBin, Int_t iPTBin, Int_t iFrame, int nState, Char_t *DataPath);
//===========================
int main(int argc, char** argv){

	Char_t *DataPath = "DataPath_Default";
	int nState;

	for( int i=0;i < argc; ++i ) {
	    if(std::string(argv[i]).find("nState") != std::string::npos) {char* nStatechar = argv[i]; char* nStatechar2 = strtok (nStatechar, "p"); nState = atof(nStatechar2); cout<<"nState = "<<nState<<endl;}
	    if(std::string(argv[i]).find("DataPath") != std::string::npos) {char* DataPathchar = argv[i]; char* DataPathchar2 = strtok (DataPathchar, "="); DataPath = DataPathchar2; cout<<"DataPath = "<<DataPath<<endl;}
	  }


	gStyle->SetPalette(1);
    gStyle->SetFrameBorderMode(0);

	cout<<DataPath<<endl;

	int nBinsCT=25;//onia::kNbBinsCosT;
	int nBinsPH=25;//onia::kNbBinsPhiPol;



  for(int iRap = 0; iRap <= 2; iRap++){
    Int_t max = onia::kNbPTBins[iRap]+1;
    for(int iPT = 0; iPT < max; iPT++){
        for(int iFrame = 0; iFrame < onia::kNbFrames; iFrame++){
        	CosThPhDist[iFrame][iRap][iPT] = new TH2D("","",nBinsCT, onia::cosTMin, onia::cosTMax, nBinsPH, onia::phiPolMin, onia::phiPolMax);
        	CosThDist[iFrame][iRap][iPT] = new TH1D("","",nBins1DCosth, onia::cosTMin, onia::cosTMax);
        	PhiDist[iFrame][iRap][iPT] = new TH1D("","",nBins1DPhi, onia::phiPolMin, onia::phiPolMax);
        }
      LoadHistos(iRap, iPT,nState,DataPath);
      for(int iFrame = 0; iFrame < 3; iFrame++){
	PlotHistos(iRap, iPT, iFrame,nState,DataPath);
      }



    }
  }



  char filename[200];
  sprintf(filename, "%s/Figures/Ups%dS/AngDistHist.root", DataPath,nState);
	  TFile* AngDistHistFile = new TFile(filename, "RECREATE", "AngDistHistFile");
	  AngDistHistFile->cd();

	  for(int iRap = 0; iRap <= 2; iRap++){
	    Int_t max = onia::kNbPTBins[iRap]+1;
	    for(int iPT = 0; iPT < max; iPT++){

      char histName[200];
      for(int iFrame = 0; iFrame < 3; iFrame++){
          sprintf(histName,"Proj_%s_costh_rap%d_pT%d",onia::frameLabel[iFrame],iRap,iPT);
          CosThDist[iFrame][iRap][iPT]->SetName(histName);
          CosThDist[iFrame][iRap][iPT]->Write();
          sprintf(histName,"Proj_%s_phi_rap%d_pT%d",onia::frameLabel[iFrame],iRap,iPT);
          PhiDist[iFrame][iRap][iPT]->SetName(histName);
          PhiDist[iFrame][iRap][iPT]->Write();
          sprintf(histName,"CosthPhi_%s_rap%d_pT%d",onia::frameLabel[iFrame],iRap,iPT);
          CosThPhDist[iFrame][iRap][iPT]->SetName(histName);
          CosThPhDist[iFrame][iRap][iPT]->Write();
      }

	    }
	  }

  AngDistHistFile->Write();
  AngDistHistFile->Close();

  return 0;
}
//===========================
void PlotHistos(Int_t iRapBin, Int_t iPTBin, Int_t iFrame,int nState, Char_t *DataPath){


	  gStyle->SetPadRightMargin(0.12);
//	  gStyle->SetPadLeftMargin(0.12);
	  gStyle->SetOptStat(0);

  Char_t name[100];
  sprintf(name, "c1_%s_rap%d_pT%d", onia::frameLabel[iFrame], iRapBin, iPTBin);
  TCanvas *c1 = new TCanvas(name, "", 500, 500);
  c1->SetFillColor(kWhite);

  char XTitle[200];
  char YTitle[200];
  sprintf(XTitle,"cos#theta_{%s}",onia::frameLabel[iFrame]);
  sprintf(YTitle,"#phi_{%s} [deg]",onia::frameLabel[iFrame]);
  double yOffset=1.4;
  CosThPhDist[iFrame][iRapBin][iPTBin]->GetYaxis()->SetTitleOffset(yOffset);
  gPad->SetLeftMargin(0.125);
  CosThPhDist[iFrame][iRapBin][iPTBin]->SetStats(0);
  CosThPhDist[iFrame][iRapBin][iPTBin]->GetYaxis()->SetTitle(YTitle);
  CosThPhDist[iFrame][iRapBin][iPTBin]->GetXaxis()->SetTitle(XTitle);

  CosThPhDist[iFrame][iRapBin][iPTBin]->Draw("colz");
  sprintf(name, "%s/Figures/Ups%dS/cosThetaPhi_%s_rap%d_pT%d.pdf", DataPath,nState,onia::frameLabel[iFrame], iRapBin, iPTBin);
  cout<<name<<endl;
  c1->Print(name);
}

//===========================
void LoadHistos(Int_t iRapBin, Int_t iPTBin, int nState, Char_t *DataPath){


  Char_t name[100];
  sprintf(name, "%s/data_%dSUps_rap%d_pT%d.root", DataPath,nState, iRapBin, iPTBin);

  TFile *fIn = new TFile(name);
  TTree* selectedData = (TTree*)fIn->Get("selectedData");

  TLorentzVector *lepP;
  TLorentzVector *lepN;
  lepP = 0; lepN = 0;
  selectedData->SetBranchAddress("lepP", &lepP);
  selectedData->SetBranchAddress("lepN", &lepN);

  const double pbeam_ = 7000.; // exact number irrelevant as long as pbeam >> Mprot
  const double Mprot_ = 0.9382720;
  const double Mlepton_ = 0.10566;  // (muon)
  const double gPI_ = TMath::Pi();
  const double Ebeam_ = sqrt( pbeam_*pbeam_ + Mprot_*Mprot_ );
  TLorentzVector beam1_LAB_( 0., 0., pbeam_, Ebeam_ );
  TLorentzVector beam2_LAB_( 0., 0., -pbeam_, Ebeam_ );

  for(int i=0;i<selectedData->GetEntries();i++){

	  selectedData->GetEvent( i );


	    double lepP_pT  = lepP->Pt();
	    double lepN_pT  = lepN->Pt();

	    double lepP_eta = lepP->PseudoRapidity();
	    double lepN_eta = lepN->PseudoRapidity();

	    // dilepton 4-vector:

	    TLorentzVector dilepton = *lepP + *lepN;
	    double pT   = dilepton.Pt();
	    double rap  = dilepton.Rapidity();
	    double mass = dilepton.M();

	  TVector3 lab_to_dilep = -dilepton.BoostVector();

	    TLorentzVector beam1_DILEP = beam1_LAB_;
	    beam1_DILEP.Boost(lab_to_dilep);         // beam1 in the dilepton rest frame
	    TLorentzVector beam2_DILEP = beam2_LAB_;
	    beam2_DILEP.Boost(lab_to_dilep);         // beam2 in the dilepton rest frame

	    TVector3 beam1_direction     = beam1_DILEP.Vect().Unit();
	    TVector3 beam2_direction     = beam2_DILEP.Vect().Unit();
	    TVector3 dilep_direction     = dilepton.Vect().Unit();
	    TVector3 beam1_beam2_bisect  = ( beam1_direction - beam2_direction ).Unit();


	    // all polarization frames have the same Y axis = the normal to the plane formed by
	    // the directions of the colliding hadrons:

	    TVector3 Yaxis = ( beam1_direction.Cross( beam2_direction ) ).Unit();

	    // flip of y axis with rapidity:

	    if ( rap < 0. ) Yaxis = - Yaxis;

	    TVector3 perpendicular_to_beam = ( beam1_beam2_bisect.Cross( Yaxis ) ).Unit();


	    // positive lepton in the dilepton rest frame:

	    TLorentzVector lepton_DILEP = *lepP;
	    lepton_DILEP.Boost(lab_to_dilep);

	    // CS frame angles:

	    TVector3 newZaxis = beam1_beam2_bisect;
	    TVector3 newYaxis = Yaxis;
	    TVector3 newXaxis = newYaxis.Cross( newZaxis );

	    TRotation rotation;
	    rotation.SetToIdentity();
	    rotation.RotateAxes( newXaxis, newYaxis, newZaxis );
	    rotation.Invert();  // transforms coordinates from the "xyz" frame to the new frame
	    TVector3 lepton_DILEP_rotated = lepton_DILEP.Vect();
	    lepton_DILEP_rotated.Transform(rotation);

	    double costh_CS = lepton_DILEP_rotated.CosTheta();
	    double phi_CS   = lepton_DILEP_rotated.Phi() * 180. / gPI_;
	    double phith_CS;
	    if ( costh_CS < 0. ) phith_CS = phi_CS - 135.;
	    if ( costh_CS > 0. ) phith_CS = phi_CS - 45.;
	    if ( phith_CS < -180. ) phith_CS = 360. + phith_CS;


	    // HELICITY frame angles:

	    newZaxis = dilep_direction;
	    newYaxis = Yaxis;
	    newXaxis = newYaxis.Cross( newZaxis );

	    rotation.SetToIdentity();
	    rotation.RotateAxes( newXaxis, newYaxis, newZaxis );
	    rotation.Invert();
	    lepton_DILEP_rotated = lepton_DILEP.Vect();
	    lepton_DILEP_rotated.Transform(rotation);

	    double costh_HX = lepton_DILEP_rotated.CosTheta();
	    double phi_HX   = lepton_DILEP_rotated.Phi() * 180. / gPI_;
	    double phith_HX;
	    if ( costh_HX < 0. ) phith_HX = phi_HX - 135.;
	    if ( costh_HX > 0. ) phith_HX = phi_HX - 45.;
	    if ( phith_HX < -180. ) phith_HX = 360. + phith_HX;


	    // PERPENDICULAR HELICITY frame angles:

	    newZaxis = perpendicular_to_beam;
	    newYaxis = Yaxis;
	    newXaxis = newYaxis.Cross( newZaxis );

	    rotation.SetToIdentity();
	    rotation.RotateAxes( newXaxis, newYaxis, newZaxis );
	    rotation.Invert();
	    lepton_DILEP_rotated = lepton_DILEP.Vect();
	    lepton_DILEP_rotated.Transform(rotation);

	    double costh_PX = lepton_DILEP_rotated.CosTheta();
	    double phi_PX   = lepton_DILEP_rotated.Phi() * 180. / gPI_;
	    double phith_PX;
	    if ( costh_PX < 0. ) phith_PX = phi_PX - 135.;
	    if ( costh_PX > 0. ) phith_PX = phi_PX - 45.;
	    if ( phith_PX < -180. ) phith_PX = 360. + phith_PX;



	    CosThPhDist[0][iRapBin][iPTBin]->Fill(costh_CS,phi_CS);
	    CosThPhDist[1][iRapBin][iPTBin]->Fill(costh_HX,phi_HX);
	    CosThPhDist[2][iRapBin][iPTBin]->Fill(costh_PX,phi_PX);

	    CosThDist[0][iRapBin][iPTBin]->Fill(costh_CS);
	    PhiDist[0][iRapBin][iPTBin]->Fill(phi_CS);
	    CosThDist[1][iRapBin][iPTBin]->Fill(costh_HX);
	    PhiDist[1][iRapBin][iPTBin]->Fill(phi_HX);
	    CosThDist[2][iRapBin][iPTBin]->Fill(costh_PX);
	    PhiDist[2][iRapBin][iPTBin]->Fill(phi_PX);

  }

//  cout<<"loaded"<<endl;
 }
