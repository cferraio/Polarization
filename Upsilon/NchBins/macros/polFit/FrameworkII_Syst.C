{

char tgraphname[200];
TFile *file1 = TFile::Open("/data/users/ferraioc/Polarization/Modified/ToyMC/Nch_FrameworkII/Sig_frame3scen2_Bkg_frame3scen3/TGraphResults_1SUps.root");

 int framemax = 3;
    for(int frame = 0; frame < 3; frame++) {
  
    char framename[200];
    if(frame == 0) sprintf(framename,"CS");
    if(frame == 1) sprintf(framename,"HX");
    if(frame == 2) sprintf(framename,"PX");
 
      int lammax = 4;
      for(int lam = 0; lam < 4; lam++) {
       char lamname[200];
       if(lam == 0 ) sprintf(lamname,"lth");
       if(lam == 1 ) sprintf(lamname,"lph");
       if(lam == 2 ) sprintf(lamname,"ltp");
       if(lam == 3 ) sprintf(lamname,"ltilde");
       
       int ptmax=2;
       for(int pt = 0; pt < ptmax; pt++)
       {
       int ptBin = pt + 1;
       sprintf(tgraphname,"%s_%s_rap1_pt%d",lamname,framename,ptBin);
       theTGraph = (TGraphAsymmErrors*) file1->Get(tgraphname);

       int cpmMax = 5;
        Double_t cpmCenter[ptmax][cpmMax];
		Double_t lmeanscen2[framemax][lammax][ptmax][cpmMax];
        for(int cpmBin = 0; cpmBin < cpmMax; cpmBin++)
         {
			theTGraph->GetPoint(cpmBin,cpmCenter[pt][cpmBin],lmeanscen2[frame][lam][pt][cpmBin]);
          
         } //end cpm loop

   
       } // end pt loop
     } //end lambda loop
    } //end frame loop
file1->Close();
TFile *file2 = TFile::Open("/data/users/ferraioc/Polarization/Modified/ToyMC/Nch_FrameworkII/Sig_frame3scen4_Bkg_frame3scen3/TGraphResults_1SUps.root");

 int framemax = 3;
    for(int frame = 0; frame < 3; frame++) {
  
    char framename[200];
    if(frame == 0) sprintf(framename,"CS");
    if(frame == 1) sprintf(framename,"HX");
    if(frame == 2) sprintf(framename,"PX");
 
      int lammax = 4;
      for(int lam = 0; lam < 4; lam++) {
       char lamname[200];
       if(lam == 0 ) sprintf(lamname,"lth");
       if(lam == 1 ) sprintf(lamname,"lph");
       if(lam == 2 ) sprintf(lamname,"ltp");
       if(lam == 3 ) sprintf(lamname,"ltilde");
       
       int ptmax=2;
       for(int pt = 0; pt < ptmax; pt++)
       {
       int ptBin = pt + 1;
       sprintf(tgraphname,"%s_%s_rap1_pt%d",lamname,framename,ptBin);
       theTGraph = (TGraphAsymmErrors*) file2->Get(tgraphname);

       int cpmMax = 5;
        Double_t cpmCenter[ptmax][cpmMax];
		Double_t lmeanscen4[framemax][lammax][ptmax][cpmMax];
        for(int cpmBin = 0; cpmBin < cpmMax; cpmBin++)
         {
			theTGraph->GetPoint(cpmBin,cpmCenter[pt][cpmBin],lmeanscen4[frame][lam][pt][cpmBin]);
          
         } //end cpm loop

   
       } // end pt loop
     } //end lambda loop
    } //end frame loop


file2->Close();
         char tfileout[200];
 sprintf(tfileout,"/data/users/ferraioc/Polarization/Modified/NchSystematics/Nch_FrameworkII/TGraphResults_1SUps.root");
 
         TFile fout(tfileout,"RECREATE");
         
for(int frame = 0; frame < 3; frame++) {
  
    char framename[200];
    if(frame == 0) sprintf(framename,"CS");
    if(frame == 1) sprintf(framename,"HX");
    if(frame == 2) sprintf(framename,"PX");
    
    
    for(int lam = 0; lam < 4; lam++) {
       char lamname[200];
       if(lam == 0 ) sprintf(lamname,"lth");
       if(lam == 1 ) sprintf(lamname,"lph");
       if(lam == 2 ) sprintf(lamname,"ltp");
       if(lam == 3 ) sprintf(lamname,"ltilde");
       
       int ptmax=2;
       for(int pt = 0; pt < ptmax; pt++)
       {
         ptBin = pt + 1;
         int cpmMax = 5;
        Double_t syst[cpmMax];
        Double_t cpmcenterforTGraph[cpmMax];
        for(int cpm = 0; cpm < cpmMax; cpm++)
         {
          syst[cpm] = (TMath::Abs(lmeanscen2[frame][lam][pt][cpm])+TMath::Abs(lmeanscen4[frame][lam][pt][cpm]))/2;			
         cpmcenterforTGraph[cpm] = cpmCenter[pt][cpm];
         } //end cpm loop
         
         systTGraph = new TGraph(cpmMax,cpmcenterforTGraph,syst);
  
         
         char tgraphout[200];
         sprintf(tgraphout,"%s_%s_rap1_pt%d",lamname,framename,ptBin);
         systTGraph->Write(tgraphout);
         
       } //end pt loop
       
    } // end lambda loop
    
  } 







}