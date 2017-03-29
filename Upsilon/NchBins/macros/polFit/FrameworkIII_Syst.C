{

char filename[200];
char tgraphname[200];

int statemax = 3;
 for(int state = 0; state < 3; state++)
 {
   int Ups = state+1;
   cout<<"For Upsilon"<<Ups<<"S"<<endl;
      
   int bkpolmax = 3;
   for(int bkpol = 0; bkpol < bkpolmax; bkpol++)
   {
   
   int scenario;
   if(bkpol == 0) scenario = 7;
   if(bkpol == 1) scenario = 8;
   if(bkpol == 2) scenario = 9;
   sprintf(filename,"/data/users/ferraioc/Polarization/Modified/ToyMC/Nch_FrameworkIII_%dS/Sig_frame3scen3_Bkg_frame3scen%d/TGraphResults_%dSUps.root",Ups,scenario,Ups);
//   cout<<"Filename is: "<<filename<<endl;
   TFile *file1 = TFile::Open(filename);
   
    int framemax = 3;
    for(int frame = 0; frame < 3; frame++) {
  
    char framename[200];
    if(frame == 0) sprintf(framename,"CS");
    if(frame == 1) sprintf(framename,"HX");
    if(frame == 2) sprintf(framename,"PX");
//    cout<<"In the "<<framename<<" frame"<<endl;
 
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
   //    cout<<"For the TGraph "<<tgraphname<<endl;
       theTGraph = (TGraphAsymmErrors*) file1->Get(tgraphname);

       int cpmMax = 5;
        if(pt==0&&state==2) int cpmMax = 4;
        Double_t cpmCenter[statemax][bkpolmax][framemax][lammax][ptmax][cpmMax];
		Double_t lmean[statemax][bkpolmax][framemax][lammax][ptmax][cpmMax];
		//Double_t errorholder[statemax][bkpolmax][framemax][lammax][ptmax][cpmMax];
        for(int cpmBin = 0; cpmBin < cpmMax; cpmBin++)
         {
          
          theTGraph->GetPoint(cpmBin,cpmCenter[state][bkpol][frame][lam][pt][cpmBin],lmean[state][bkpol][frame][lam][pt][cpmBin]);
          //errorholder[state][bkpol][frame][lam][pt][cpmBin] = theTGraph->GetErrorY(cpmBin);
          
         } //end cpm loop

   
       } // end pt loop
     } //end lambda loop
    } //end frame loop
  } //end background pol scenario loop
  } //end ups state loop
  
  for(int state = 0; state < 3; state++)
 {
   Ups = state + 1;
   
         char tfileout[200];
 sprintf(tfileout,"/data/users/ferraioc/Polarization/Modified/NchSystematics/Nch_FrameworkIII/TGraphResults_%dSUps.root",Ups);
 
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
        if(pt==0&&state==2) int cpmMax = 4;
        Double_t syst[cpmMax];
        Double_t cpmcenterforTGraph[cpmMax];
        for(int cpm = 0; cpm < cpmMax; cpm++)
         {
          syst[cpm] = (TMath::Abs(lmean[state][0][frame][lam][pt][cpm])+TMath::Abs(lmean[state][1][frame][lam][pt][cpm])+TMath::Abs(lmean[state][2][frame][lam][pt][cpm]))/3;			
         cpmcenterforTGraph[cpm] = cpmCenter[state][0][frame][lam][pt][cpm];
         } //end cpm loop
         
         systTGraph = new TGraph(cpmMax,cpmcenterforTGraph,syst);
  
  
         
         
         
         char tgraphout[200];
         sprintf(tgraphout,"%s_%s_rap1_pt%d",lamname,framename,ptBin);
         systTGraph->Write(tgraphout);
         
       } //end pt loop
       
    } // end lambda loop
    
  } //end frame loop
 		fout->Close();
 } //end state loop
  
  
 }