#include "calculatePar.cc"

void buildLifetimePDF(RooWorkspace *ws);
void doFit(RooWorkspace *ws, int nState, double BkgRatio3Sig, double fracBkgInSBL, double fracBkgInSBR, int rapBin, int ptBin, int cpmBin);

//=================================================================================
void lifetimeFit(const std::string &infilename, int rapBin, int ptBin, int cpmBin, int nState){

	TFile* infile = new TFile(infilename.c_str(), "UPDATE");
	if(infile->IsZombie()){
		std::cout << "Error: failed to open mass root file" << std::endl;
		return;
	}
	std::string workspacename = "ws_masslifetime";
	RooWorkspace *ws=dynamic_cast<RooWorkspace*>(infile->Get(workspacename.c_str()));
	if(ws == 0){
		std::cout << "Error: failed to get workspace " << workspacename << " from file " << infilename << std::endl;
		infile->ls();
		return;
	}

	

  RooRealVar *JpsiMass = ws->var("JpsiMass");
  assert( 0 != JpsiMass );
  RooRealVar *JpsiRap = ws->var("JpsiRap");
  assert( 0 != JpsiRap );

  std::stringstream dataname;
  dataname << "data_rap" << rapBin << "_pt" << ptBin << "_cpm" << cpmBin;
  RooAbsData* data = ws->data(dataname.str().c_str());

  std::stringstream binNameSR, binNameSBL, binNameSBR;
  binNameSR  << "data_rap" << rapBin << "_pt" << ptBin << "_cpm" << cpmBin << "_SR";
  binNameSBL << "data_rap" << rapBin << "_pt" << ptBin << "_cpm" << cpmBin << "_SBL";
  binNameSBR << "data_rap" << rapBin << "_pt" << ptBin << "_cpm" << cpmBin << "_SBR";

  RooAbsData* dataSR = ws->data(binNameSR.str().c_str());
  RooAbsData* dataLSB = ws->data(binNameSBL.str().c_str());
  RooAbsData* dataRSB = ws->data(binNameSBR.str().c_str());


  std:: cout << "----------------------------" << "\n"
             << "events in SR: " << dataSR->numEntries() << "\n"
             << "events in LSB: " << dataLSB->numEntries() << "\n"
             << "events in RSB: " << dataRSB->numEntries() << "\n"
             << "----------------------------" << std::endl;
    
    
    // caculating median of different regions by filling events into histogram and getting the mean
	TH1* histSR =  dataSR->createHistogram("histSR", *JpsiMass,  Binning(120));
	TH1* histSBL = dataLSB->createHistogram("histSBL", *JpsiMass, Binning(120));
	TH1* histSBR = dataRSB->createHistogram("histSBR", *JpsiMass, Binning(120));
	
	
	double meanSR = histSR->GetMean();
	double meanSBL = histSBL->GetMean();
	double meanSBR = histSBR->GetMean();

	RooRealVar* MeanSR = new RooRealVar("MeanSR","MeanSR",meanSR);
	RooRealVar* MeanSBL = new RooRealVar("MeanSBL","MeanSBL",meanSBL);
	RooRealVar* MeanSBR = new RooRealVar("MeanSBR","MeanSBR",meanSBR);
	ws->import(RooArgList(*MeanSR, *MeanSBL, *MeanSBR));
	
	std::cout << "----------------------------" << "\n"
		<< "meanSR: " << meanSR << "\n"
		<< "meanSBL: " << meanSBL << "\n"
		<< "meanSBR: " << meanSBR 
		<< "----------------------------" << std::endl;
	

	RooRealVar *CBmass =  ws->var("CBmass_p0");
	RooRealVar *CBsigma_p0 = ws->var("CBsigma_p0");
	RooRealVar *CBsigma_p1 = ws->var("CBsigma_p1");
	RooRealVar *CBsigma_p2 = ws->var("CBsigma_p2");
	RooRealVar *fracBkg_=(RooRealVar *)ws->var("fracBkg");
	RooRealVar *BkgRatio3Sig =  ws->var("FracBkg");
	RooRealVar *fracBkgSBL =  ws->var("FracBkgSBL");
	RooRealVar *fracBkgSBR =  ws->var("FracBkgSBR");
	
    double Mean = CBmass->getVal();
	double cbsigp0 = CBsigma_p0->getVal();
	double cbsigp1 = CBsigma_p1->getVal();
	double cbsigp2 = CBsigma_p2->getVal();
	double FracBkg = BkgRatio3Sig->getVal();
	double FracBkgErr = BkgRatio3Sig->getError();

	double FracBkgSBL = fracBkgSBL->getVal();
	double FracBkgSBR = fracBkgSBR->getVal();
	double fracBkgInSBLErr = fracBkgSBL->getError();
	double fracBkgInSBRErr = fracBkgSBR->getError();


  // building lifetime pdf
  std::cout << ">>>Building Mass and LifeTime PDF" << std::endl;
  buildLifetimePDF(ws);

  // fitting
  std::cout << ">>>Fitting" << std::endl;
/*  std::cout << "input parameters: \n"
            << "fBkg in SR = " << ws->var("var_frac_jpsi_BGInSR")->getVal() << "\n"
            << "fBkg in LSB = " << ws->var("var_frac_jpsi_BGInLSB")->getVal() << "\n"
            << "fBkg in RSB = " << ws->var("var_frac_jpsi_BGInRSB")->getVal() << "\n" << std::endl;
  */          
  doFit(ws, nState, FracBkg, FracBkgSBL, FracBkgSBR, rapBin, ptBin, cpmBin); 
  
  //ws->var("var_frac_jpsi_BGInLSB")->getVal(), ws->var("var_frac_jpsi_BGInRSB")->getVal(), rapBin, ptBin);

  std::cout << ">>>Writing results to root file" << std::endl;
  ws->Write();
  infile->Close();
}

//=================================================================================

void buildLifetimePDF(RooWorkspace *ws){

	//----prompt
	//resolution function
	

	ws->factory("RooGaussModel::promptLifetime(Jpsict,promptMean[0,-.01,.01],ctResolution[1,.001,2], 1, JpsictErr)");
	((RooGaussModel*)ws->pdf("promptLifetime"))->advertiseFlatScaleFactorIntegral(true);

	ws->factory("RooGaussModel::promptLifetime2(Jpsict,promptMean, ctResolution2[1,.001,6], 1, JpsictErr)");
	((RooGaussModel*)ws->pdf("promptLifetime2"))->advertiseFlatScaleFactorIntegral(true);

	RooGaussModel* promptLifetime = (RooGaussModel*)ws->pdf("promptLifetime");
	RooGaussModel* promptLifetime2 = (RooGaussModel*)ws->pdf("promptLifetime2");
	RooRealVar fracGauss2("fracGauss2","fracGauss2",.01,.0,.45);
	RooAddModel TotalPromptLifetime("TotalPromptLifetime","TotalPromptLifetime",
			RooArgSet(*promptLifetime2,*promptLifetime),fracGauss2);
	ws->import(fracGauss2);
	ws->import(TotalPromptLifetime);
	TotalPromptLifetime.Print();

	//----noprompt
	ws->factory("RooDecay::nonPromptSSD(Jpsict,nonPromptTau[.3,.01,3],TotalPromptLifetime,RooDecay::SingleSided)");

	//----background
	//SBL
	ws->factory("RooDecay::backgroundSSD_SBL(Jpsict,bkgTauSSD_SBL[.4,0,3],TotalPromptLifetime,RooDecay::SingleSided)");
	
	ws->factory("RooDecay::backgroundFD(Jpsict,bkgTauFD[.2,.00001,3],TotalPromptLifetime,RooDecay::Flipped)");
	
	
	ws->factory("RooDecay::backgroundDSD(Jpsict,bkgTauDSD[.05,0,3],TotalPromptLifetime,RooDecay::DoubleSided)");
	ws->factory("SUM::backgroundlifetimeLpre(fBkgSSDR_SBL[.4,0,1.]*backgroundSSD_SBL,fBkgDSD_SBL[.2,0,1.]*backgroundDSD,backgroundFD)");
	////SBR
	ws->factory("RooDecay::backgroundSSD_SBR(Jpsict,bkgTauSSD_SBR[.4,0,3],TotalPromptLifetime,RooDecay::SingleSided)");
	ws->factory("SUM::backgroundlifetimeRpre(fBkgSSDR_SBR[.4,0,1.]*backgroundSSD_SBR,fBkgDSD_SBR[.2,0,1.]*backgroundDSD,backgroundFD)");
	//Signal region
	//interpolation
	ws->factory("expr::fBkgSSDR('@0+(@2-@3)*(@1-@0)/(@4-@3)',fBkgSSDR_SBL,fBkgSSDR_SBR,MeanSR,MeanSBL,MeanSBR)");
	ws->factory("expr::fBkgDSD('@0+(@2-@3)*(@1-@0)/(@4-@3)',fBkgDSD_SBL,fBkgDSD_SBR,MeanSR,MeanSBL,MeanSBR)");
	ws->factory("expr::bkgTauSSD('@0+(@2-@3)*(@1-@0)/(@4-@3)',bkgTauSSD_SBL,bkgTauSSD_SBR,MeanSR,MeanSBL,MeanSBR)");
	ws->factory("RooDecay::backgroundSSD(Jpsict,bkgTauSSD,TotalPromptLifetime,RooDecay::SingleSided)");
	ws->factory("SUM::backgroundlifetime(fBkgSSDR*backgroundSSD,fBkgDSD*backgroundDSD,backgroundFD)");
	//---final pdf
	//signal region
	ws->factory("SUM::fulllifetime(fBkg[0.5,0.,1.]*backgroundlifetime,fPrompt[0.5,0.,1.]*TotalPromptLifetime,nonPromptSSD)");
	ws->factory("RooGaussian::fBkgConstraint(fBkg, FracBkg, FracBkgErr)"); 
	ws->factory("PROD::lifetimeConstraint(fulllifetime, fBkgConstraint)"); 

	RooRealVar* fBkgSBL = new RooRealVar("fBkgSBL","fBkgSBL",0.8,0.,1.);
	RooRealVar* fBkgSBR = new RooRealVar("fBkgSBR","fBkgSBR",0.8,0.,1.);
	ws->import(*fBkgSBL); ws->import(*fBkgSBR);

	//f_P / f_NP should be same in LSB,SR,RSB, to interpolate f_P in L(R)SB from SR
	ws->factory("expr::fPromptSBL('@0*(1.-@1)/(1.-@2)',fPrompt,fBkgSBL,fBkg)");
	ws->factory("expr::fPromptSBR('@0*(1.-@1)/(1.-@2)',fPrompt,fBkgSBR,fBkg)");

	//SBL
	ws->factory("SUM::backgroundlifetimeLnoC(fBkgSBL*backgroundlifetimeLpre,fPromptSBL*TotalPromptLifetime,nonPromptSSD)");
	ws->factory("RooGaussian::fBkgSBLConstraint(fBkgSBL, FracBkgSBL, FracBkgSBLErr)");
	ws->factory("PROD::backgroundlifetimeL(backgroundlifetimeLnoC, fBkgSBLConstraint)"); 

	//SBR
	ws->factory("SUM::backgroundlifetimeRnoC(fBkgSBR*backgroundlifetimeRpre,fPromptSBR*TotalPromptLifetime,nonPromptSSD)");
	ws->factory("RooGaussian::fBkgSBRConstraint(fBkgSBR, FracBkgSBR, FracBkgSBRErr)");
	ws->factory("PROD::backgroundlifetimeR(backgroundlifetimeRnoC, fBkgSBRConstraint)"); 

	ws->Print("v");
}


//=================================================================================
void doFit(RooWorkspace *ws, int nState, double FracBkg, double fracBkgInSBL, double fracBkgInSBR, int rapBin, int ptBin, int cpmBin){
	RooRealVar JpsiMass(*ws->var("JpsiMass"));
	RooRealVar Jpsict(*ws->var("Jpsict"));
	stringstream binNameSR, binNameSBL, binNameSBR;
	binNameSR  << "data_rap" << rapBin << "_pt" << ptBin << "_cpm" << cpmBin <<"_SR";
	binNameSBL << "data_rap" << rapBin << "_pt" << ptBin << "_cpm" << cpmBin <<"_SBL";
	binNameSBR << "data_rap" << rapBin << "_pt" << ptBin << "_cpm" << cpmBin <<"_SBR";
	RooDataSet *dataSR = (RooDataSet*)ws->data(binNameSR.str().c_str());
	RooDataSet *dataSBL = (RooDataSet*)ws->data(binNameSBL.str().c_str());
	RooDataSet *dataSBR = (RooDataSet*)ws->data(binNameSBR.str().c_str());

	if(nState==4){
		ws->var("fBkgSSDR_SBL")->setVal(.7); //0.4
		ws->var("fBkgSSDR_SBR")->setVal(.7); //0.4
		ws->var("fBkgDSD_SBL")->setVal(.2);
		ws->var("fBkgDSD_SBR")->setVal(.2);
//		if(cpmBin==2 && ptBin==1){
//			ws->var("fBkgSSDR_SBL")->setVal(.785); //0.4
//			ws->var("fBkgSSDR_SBR")->setVal(.785);
//			ws->var("fBkgDSD_SBL")->setMax(.215);
//			ws->var("fBkgDSD_SBR")->setMax(.215);
		
//		}
		if(ptBin == 1 && cpmBin == 1){
			ws->var("fBkgSSDR_SBL")->setVal(.785);
			ws->var("fBkgSSDR_SBR")->setVal(.785);
			ws->var("fBkgDSD_SBL")->setMax(.215);
			ws->var("fBkgDSD_SBR")->setMax(.215);
		}
		if(ptBin == 1 && cpmBin == 2){
			ws->var("fBkgSSDR_SBL")->setVal(.785);
			ws->var("fBkgSSDR_SBR")->setVal(.785);
			ws->var("fBkgDSD_SBL")->setMax(.215);
			ws->var("fBkgDSD_SBR")->setMax(.215);
		}
		
		if(ptBin == 1 && cpmBin == 4){
			ws->var("fBkgSSDR_SBL")->setVal(.785);
			ws->var("fBkgSSDR_SBR")->setVal(.785);
			ws->var("fBkgDSD_SBL")->setMax(.215);
			ws->var("fBkgDSD_SBR")->setMax(.215);
		}
		if(ptBin == 1 && cpmBin == 8){
			//// old
			//ws->var("fBkgSSDR_SBL")->setVal(.77);
			//ws->var("fBkgSSDR_SBR")->setVal(.77);
			//ws->var("fBkgSSDR_SBL")->setConstant(kTRUE);
			//ws->var("fBkgSSDR_SBR")->setConstant(kTRUE);
			//ws->var("fBkgDSD_SBL")->setMax(.23);
			//ws->var("fBkgDSD_SBR")->setMax(.23);
			////new model
			ws->var("fBkgSSDR_SBL")->setVal(.785);
			ws->var("fBkgSSDR_SBR")->setVal(.785);
//			ws->var("fBkgSSDR_SBL")->setConstant(kTRUE);
//			ws->var("fBkgSSDR_SBR")->setConstant(kTRUE);
			ws->var("fBkgDSD_SBL")->setMax(.215);
			ws->var("fBkgDSD_SBR")->setMax(.215);
		}
		if(ptBin == 1 && cpmBin == 9){
			//// old
			//ws->var("fBkgSSDR_SBL")->setVal(.77);
			//ws->var("fBkgSSDR_SBR")->setVal(.77);
			//ws->var("fBkgSSDR_SBL")->setConstant(kTRUE);
			//ws->var("fBkgSSDR_SBR")->setConstant(kTRUE);
			//ws->var("fBkgDSD_SBL")->setMax(.23);
			//ws->var("fBkgDSD_SBR")->setMax(.23);
			////new model
			ws->var("fBkgSSDR_SBL")->setVal(.785);
			ws->var("fBkgSSDR_SBR")->setVal(.785);
//			ws->var("fBkgSSDR_SBL")->setConstant(kTRUE);
//			ws->var("fBkgSSDR_SBR")->setConstant(kTRUE);
			ws->var("fBkgDSD_SBL")->setMax(.215);
			ws->var("fBkgDSD_SBR")->setMax(.215);
		}

		if(ptBin == 1 && cpmBin == 10){
			//// old
			//ws->var("fBkgSSDR_SBL")->setVal(.77);
			//ws->var("fBkgSSDR_SBR")->setVal(.77);
			//ws->var("fBkgSSDR_SBL")->setConstant(kTRUE);
			//ws->var("fBkgSSDR_SBR")->setConstant(kTRUE);
			//ws->var("fBkgDSD_SBL")->setMax(.23);
			//ws->var("fBkgDSD_SBR")->setMax(.23);
			////new model
			ws->var("fBkgSSDR_SBL")->setVal(.785);
			ws->var("fBkgSSDR_SBR")->setVal(.785);
//			ws->var("fBkgSSDR_SBL")->setConstant(kTRUE);
//			ws->var("fBkgSSDR_SBR")->setConstant(kTRUE);
			ws->var("fBkgDSD_SBL")->setMax(.215);
			ws->var("fBkgDSD_SBR")->setMax(.215);
		}
		
		if(ptBin == 1 && cpmBin == 1){
			ws->var("fBkgSSDR_SBL")->setVal(.715); //0.4
			ws->var("fBkgSSDR_SBR")->setVal(.715); //0.4
//			ws->var("fBkgSSDR_SBL")->setConstant(kTRUE);
//			ws->var("fBkgSSDR_SBR")->setConstant(kTRUE);
			ws->var("fBkgDSD_SBL")->setVal(.225);
			ws->var("fBkgDSD_SBR")->setVal(.225);
		}
		
		if(ptBin == 2 && cpmBin == 2){
			ws->var("fBkgSSDR_SBL")->setVal(.785);
			ws->var("fBkgSSDR_SBR")->setVal(.785);
//			ws->var("fBkgSSDR_SBL")->setConstant(kTRUE);
//			ws->var("fBkgSSDR_SBR")->setConstant(kTRUE);
			ws->var("fBkgDSD_SBL")->setMax(.215);
			ws->var("fBkgDSD_SBR")->setMax(.215);
		}
		
		if(ptBin == 2 && cpmBin == 3){
			ws->var("fBkgSSDR_SBL")->setVal(.785);
			ws->var("fBkgSSDR_SBR")->setVal(.785);
//			ws->var("fBkgSSDR_SBL")->setConstant(kTRUE);
//			ws->var("fBkgSSDR_SBR")->setConstant(kTRUE);
			ws->var("fBkgDSD_SBL")->setMax(.2);
			ws->var("fBkgDSD_SBR")->setMax(.2);
		}
		
		if(ptBin == 2 && cpmBin == 5){
			ws->var("fBkgSSDR_SBL")->setVal(.77);
			ws->var("fBkgSSDR_SBR")->setVal(.77);
//			ws->var("fBkgSSDR_SBL")->setConstant(kTRUE);
//			ws->var("fBkgSSDR_SBR")->setConstant(kTRUE);
			ws->var("fBkgDSD_SBL")->setMax(.215);
			ws->var("fBkgDSD_SBR")->setMax(.215);
		}
		
		if(ptBin == 2 && cpmBin == 6){
			ws->var("fBkgSSDR_SBL")->setVal(.77);
			ws->var("fBkgSSDR_SBR")->setVal(.77);
//			ws->var("fBkgSSDR_SBL")->setConstant(kTRUE);
//			ws->var("fBkgSSDR_SBR")->setConstant(kTRUE);
			ws->var("fBkgDSD_SBL")->setMax(.215);
			ws->var("fBkgDSD_SBR")->setMax(.215);
		}
		
		if(ptBin == 2 && cpmBin == 9 ){
			ws->var("fBkgSSDR_SBL")->setVal(.77);
			ws->var("fBkgSSDR_SBR")->setVal(.77);
//			ws->var("fBkgSSDR_SBL")->setConstant(kTRUE);
//			ws->var("fBkgSSDR_SBR")->setConstant(kTRUE);
			ws->var("fBkgDSD_SBL")->setMax(.215);
			ws->var("fBkgDSD_SBR")->setMax(.215);
		}
		
		if(ptBin == 2 && cpmBin == 10 ){
			ws->var("fBkgSSDR_SBL")->setVal(.785);
			ws->var("fBkgSSDR_SBR")->setVal(.785);
//			ws->var("fBkgSSDR_SBL")->setConstant(kTRUE);
//2sep			ws->var("fBkgSSDR_SBR")->setConstant(kTRUE);
			ws->var("fBkgDSD_SBL")->setMax(.215);
			ws->var("fBkgDSD_SBR")->setMax(.215);
		}
		
		if(cpmBin == 11 ){
			ws->var("fBkgSSDR_SBL")->setVal(.785);
			ws->var("fBkgSSDR_SBR")->setVal(.785);
//			ws->var("fBkgSSDR_SBL")->setConstant(kTRUE);
//2sep			ws->var("fBkgSSDR_SBR")->setConstant(kTRUE);
			ws->var("fBkgDSD_SBL")->setMax(.215);
			ws->var("fBkgDSD_SBR")->setMax(.215);
		}
		
		if(ptBin == 2 && cpmBin == 4 ){
			ws->var("fBkgSSDR_SBL")->setVal(.77);
			ws->var("fBkgSSDR_SBR")->setVal(.77);
//			ws->var("fBkgSSDR_SBL")->setConstant(kTRUE);
//			ws->var("fBkgSSDR_SBR")->setConstant(kTRUE);
			ws->var("fBkgDSD_SBL")->setMax(.215);
			ws->var("fBkgDSD_SBR")->setMax(.215);
		}

		if(ptBin == 2 && cpmBin == 1 ){
			ws->var("fBkgSSDR_SBL")->setVal(.77);
			ws->var("fBkgSSDR_SBR")->setVal(.77);
//			ws->var("fBkgSSDR_SBL")->setConstant(kTRUE);
//			ws->var("fBkgSSDR_SBR")->setConstant(kTRUE);
			ws->var("fBkgDSD_SBL")->setMax(.215);
			ws->var("fBkgDSD_SBR")->setMax(.215);
		}


		ws->var("bkgTauSSD_SBL")->setVal(.4);
		ws->var("bkgTauSSD_SBR")->setVal(.4);
		ws->var("bkgTauFD")->setVal(.1);
		ws->var("bkgTauDSD")->setVal(.01);

		ws->var("fBkg")->setVal(FracBkg);
		ws->var("fPrompt")->setVal(.3);
		ws->var("fBkgSBL")->setVal(fracBkgInSBL);
		ws->var("fBkgSBR")->setVal(fracBkgInSBR);

		ws->var("nonPromptTau")->setVal(.4);

		//** set limit
		ws->var("bkgTauSSD_SBL")->setMax(1.);
		ws->var("bkgTauSSD_SBR")->setMax(1.);
		ws->var("bkgTauFD")->setMax(0.3);
		//ws->var("bkgTauDSD")->setMax(0.04); //0.05
		ws->var("nonPromptTau")->setMax(1.);
		//ws->var("fBkgSBL")->setMin(0.75);
		//ws->var("fBkgSBR")->setMin(0.84);
		if(ptBin>10){
			ws->var("bkgTauDSD")->setMax(0.005);
			ws->var("bkgTauDSD")->setVal(0.);
		}
		//**

		ws->var("promptMean")->setVal(0.);
		ws->var("ctResolution")->setVal(.9);
		ws->var("promptMean")->setConstant(kTRUE);
		ws->var("ctResolution")->setConstant(kTRUE);

		if(rapBin == 1)
			ws->var("ctResolution2")->setVal(1.1);
		else if(rapBin == 2)
			ws->var("ctResolution2")->setVal(1.5);
			
		ws->var("ctResolution2")->setConstant(kTRUE);
		ws->var("fracGauss2")->setVal(0.2);
		ws->var("fracGauss2")->setMin(0.04);
	}
	else if(nState==5){
	
	
		ws->var("fBkgSSDR_SBL")->setVal(.6);
		ws->var("fBkgSSDR_SBR")->setVal(.3);
		ws->var("fBkgDSD_SBL")->setVal(.4);
		ws->var("fBkgDSD_SBR")->setVal(.6);
		
		ws->var("bkgTauSSD_SBL")->setVal(.4);
		ws->var("bkgTauSSD_SBR")->setVal(.4);
		ws->var("bkgTauFD")->setVal(.1);
		ws->var("bkgTauDSD")->setVal(.01);

		ws->var("fBkg")->setVal(FracBkg);
		ws->var("fPrompt")->setVal(.3);
		ws->var("fBkgSBL")->setVal(fracBkgInSBL);
		ws->var("fBkgSBR")->setVal(fracBkgInSBR);

		ws->var("nonPromptTau")->setVal(.4);

		//** set limit
		ws->var("bkgTauSSD_SBL")->setMax(1.);
		ws->var("bkgTauSSD_SBR")->setMax(1.);
		ws->var("bkgTauFD")->setMax(0.3);
		ws->var("bkgTauDSD")->setMax(0.05);
		ws->var("nonPromptTau")->setMax(1.);
		ws->var("fBkgDSD_SBL")->setMin(0.2);
		ws->var("fBkgDSD_SBR")->setMin(0.2);
		//**

		ws->var("promptMean")->setVal(0.);
		ws->var("ctResolution")->setVal(.9);
		ws->var("promptMean")->setConstant(kTRUE);
		ws->var("ctResolution")->setConstant(kTRUE);
		ws->var("ctResolution2")->setVal(3.);
		ws->var("ctResolution2")->setConstant(kTRUE);
		ws->var("fracGauss2")->setVal(0.01);
	}
cout<<"here"<<endl;
	RooAbsPdf *ModelLifeSR = (RooAbsPdf*)ws->pdf("lifetimeConstraint");
	RooAbsPdf *ModelLifeSBL = (RooAbsPdf*)ws->pdf("backgroundlifetimeL");
	RooAbsPdf *ModelLifeSBR = (RooAbsPdf*)ws->pdf("backgroundlifetimeR");
cout<<"here1"<<endl;
	RooArgSet *NLLs = new RooArgSet();
	
	RooAbsReal *MLNLLSR = NULL, *MLNLLSBL = NULL, *MLNLLSBR = NULL;
cout<<"here2"<<endl;	
	MLNLLSR = (RooAbsReal *)ModelLifeSR->createNLL(*dataSR,
			ConditionalObservables(RooArgSet(*ws->var("JpsictErr"))),
			Constrain(RooArgSet(*ws->var("fBkg"))),
			Extended(kFALSE),
			NumCPU(6));

	MLNLLSBL = (RooAbsReal *)ModelLifeSBL->createNLL(*dataSBL,
			ConditionalObservables(RooArgSet(*ws->var("JpsictErr"))),
			Constrain(RooArgSet(*ws->var("fBkgSBL"))),
			Extended(kFALSE),
			NumCPU(6));
cout<<"here3"<<endl;
	MLNLLSBR = (RooAbsReal *)ModelLifeSBR->createNLL(*dataSBR,
			ConditionalObservables(RooArgSet(*ws->var("JpsictErr"))),
			Constrain(RooArgSet(*ws->var("fBkgSBR"))),
			Extended(kFALSE),
			NumCPU(6));
	NLLs->add(*MLNLLSR);
	NLLs->add(*MLNLLSBL);
	NLLs->add(*MLNLLSBR);
cout<<"here4"<<endl;
	RooAddition *simNLL = new RooAddition("add","add",*NLLs);
	RooMinuit *lMinuit = new RooMinuit(*simNLL);
	lMinuit->setStrategy(1); 
	if(nState==4 && ptBin > 7) lMinuit->setStrategy(2); 
cout<<"here5"<<endl;
	lMinuit->setPrintEvalErrors(-1);
	lMinuit->setEvalErrorWall(false);
	lMinuit->setVerbose(false);
	lMinuit->setPrintLevel(-1);
	cout<<"here6"<<endl;
	stringstream rltName, snapshotName;
	rltName<< "l_fitresult_rap"<<rapBin<<"_pt"<<ptBin<<"_cpm"<<cpmBin;
	snapshotName<< "l_snapshot_rap"<<rapBin<<"_pt"<<ptBin<<"_cpm"<<cpmBin;
	RooFitResult *fitresult;
	cout<<"here7"<<endl;
	lMinuit->simplex();
	cout<<"here8"<<endl;
	lMinuit->migrad();
	cout<<"here9"<<endl;
	fitresult = (RooFitResult*)lMinuit->save(rltName.str().c_str());
	cout<<"fitresult->covQual(): "<<fitresult->covQual()<<endl;
	lMinuit->migrad();
	fitresult = (RooFitResult*)lMinuit->save(rltName.str().c_str());
	cout<<"fitresult->covQual(): "<<fitresult->covQual()<<endl;
	lMinuit->hesse();
	fitresult = (RooFitResult*)lMinuit->save(rltName.str().c_str());
	cout<<"fitresult->covQual(): "<<fitresult->covQual()<<endl;

	double BkgTauFD = ((RooRealVar*)ws->var("bkgTauFD"))->getVal();
	double BkgTauDSD = ((RooRealVar*)ws->var("bkgTauDSD"))->getVal();
	double CtResolution = ((RooRealVar*)ws->var("ctResolution"))->getVal();
	double CtResolution2 = ((RooRealVar*)ws->var("ctResolution2"))->getVal();
	int refitCount = 0;
	while(BkgTauFD < BkgTauDSD){
		if(refitCount>3) break;
		cout<<"bkgTauFD < bkgTauDSD"<<endl;
		ws->var("bkgTauFD")->setVal(BkgTauDSD);
		ws->var("bkgTauDSD")->setVal(BkgTauFD);
		lMinuit->migrad();
		fitresult = (RooFitResult*)lMinuit->save(rltName.str().c_str());
		cout<<"fitresult->covQual(): "<<fitresult->covQual()<<endl;
		lMinuit->migrad();
		fitresult = (RooFitResult*)lMinuit->save(rltName.str().c_str());
		cout<<"fitresult->covQual(): "<<fitresult->covQual()<<endl;
		lMinuit->hesse();
		fitresult = (RooFitResult*)lMinuit->save(rltName.str().c_str());
		cout<<"fitresult->covQual(): "<<fitresult->covQual()<<endl;

		BkgTauFD = ((RooRealVar*)ws->var("bkgTauFD"))->getVal();
		BkgTauDSD = ((RooRealVar*)ws->var("bkgTauDSD"))->getVal();
		refitCount++;
	}
	while(CtResolution > CtResolution2){
		if(refitCount>3) break;
		cout<<"CtResolution > CtResolution2"<<endl;
		ws->var("ctResolution")->setVal(CtResolution2);
		ws->var("ctResolution2")->setVal(CtResolution);
		lMinuit->migrad();
		fitresult = (RooFitResult*)lMinuit->save(rltName.str().c_str());
		cout<<"fitresult->covQual(): "<<fitresult->covQual()<<endl;
		lMinuit->migrad();
		fitresult = (RooFitResult*)lMinuit->save(rltName.str().c_str());
		cout<<"fitresult->covQual(): "<<fitresult->covQual()<<endl;
		lMinuit->hesse();
		fitresult = (RooFitResult*)lMinuit->save(rltName.str().c_str());
		cout<<"fitresult->covQual(): "<<fitresult->covQual()<<endl;

		CtResolution = ((RooRealVar*)ws->var("ctResolution"))->getVal();
		CtResolution2 = ((RooRealVar*)ws->var("ctResolution2"))->getVal();

		refitCount++;
	}

	cout<<">>>>>>Refitted "<<refitCount<<" times"<<endl;
	if(refitCount>3) cout<<">>>>>>Fit not converged"<<endl;

	fitresult->Print();
	ws->import(*fitresult,kTRUE);

	ws->saveSnapshot(snapshotName.str().c_str(), ws->allVars());
}