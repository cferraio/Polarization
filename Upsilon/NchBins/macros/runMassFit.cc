#include "rootIncludes.inc"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "TROOT.h"

#include "upsilon_2StepFit.C"

using namespace onia;

//====================================
int main(){

	Double_t nSigma = 1.; //sigma_mass cut for preparation of figures
	Char_t *fileNameIn = "tmpFiles/selEvents_data_Ups.root";


	  gROOT->ProcessLine(".L upsilon_2StepFit.C+");

  for(int iRap = 0; iRap <= onia::kNbRapForPTBins; iRap++){
    Int_t max = onia::kNbPTBins[iRap]+1;
    for(int iPT = 0; iPT < max; iPT++){
      for(int iCPM = 0; iCPM <= onia::NXBINS; iCPM++){
		cout<<"irap = "<<iRap<<" ipt = "<<iPT<<" icpm = "<<iCPM<<endl;
        upsilon_2StepFit(iRap, iPT, iCPM, nSigma, fileNameIn);
      }  
    }
  }

//         upsilon_2StepFit(0, 1, 5, nSigma, fileNameIn);

  cout<<"sigma Y(1S):"<<endl;
  for(int iRap = 0; iRap <= onia::kNbRapForPTBins; iRap++){
    Int_t max = onia::kNbPTBins[iRap]+1;
    for(int iPT = 0; iPT < max; iPT++){
      for(int iCPM = 0; iCPM < onia::NXBINS+1; iCPM++){
        cout<<"rap"<<iRap<<"_pT"<<iPT<<"_cpm"<<iCPM<<": "<<sigma1S_save[iRap][iPT][iCPM]<<endl;
	  }
    }
  }


  return 0;
}
