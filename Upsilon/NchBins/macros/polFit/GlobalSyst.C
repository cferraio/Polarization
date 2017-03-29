{

TGraphAsymmErrors theTGraph;
TGraphErrors *globuncgraphpt1;
TGraphErrors *globuncgraphpt2;
Double_t  GlobalUnc;
Double_t  cpmCenter[5];
Double_t  lmean[5];
Double_t 	  tgraphxpt1[0] = 0;
Double_t 	  tgraphxpt2[0];
Double_t	  tgraphxer[0]=1;
Double_t	  tgraphy[0]=0;
Double_t      tgraphypt1[0];
Double_t      tgraphypt2[0];

  int whichstate = 1;
  for(int nstate = 0; nstate < 3; nstate++)
   {
   
   cout<<"Stating Upsilon("<<whichstate<<"S)"<<endl;

    char fileout[200];
    sprintf(fileout,"Systematics/cutNPriVtx_smallerpT2/AverageSyst/GlobalUnc/TGraphResults_%dSUps.root",whichstate);
    TFile *fout = new TFile (fileout,"RECREATE");
    fout->Close();
    
    char fileinname[200];
    sprintf(fileinname,"Systematics/cutNPriVtx_smallerpT2_FinalSyst/AverageSyst/TGraphResults_%dSUps.root",whichstate);
    TFile *filein = new TFile (fileinname);

	
    
    for(int frame = 0; frame<3; frame++)
    {
     char whichframe[200];
     if(frame==0) sprintf(whichframe,"CS");
     if(frame==1) sprintf(whichframe,"HX");
     if(frame==2) sprintf(whichframe,"PX");
      
     for(int lambda = 0; lambda < 4; lambda++)
     {
      char whichlambda[200];
      if(lambda == 0) sprintf(whichlambda,"th");
      if(lambda == 1) sprintf(whichlambda,"ph");
      if(lambda == 2) sprintf(whichlambda,"tp");
      if(lambda == 3) sprintf(whichlambda,"tilde");
     
      for(int ptBin = 0; ptBin < 2; ptBin++)
      {
        
      
        char graphname[200];
        sprintf(graphname,"l%s_%s_rap1_pt%d", whichlambda, whichframe, ptBin+1); 
        theTGraph = (TGraphAsymmErrors*) filein->Get(graphname);
        
        int cpmMax = 5;
        if(ptBin==1&&nstate==2) int cpmMax = 4;
        for(int cpmBin = 0; cpmBin < cpmMax; cpmBin++)
         {
          theTGraph->GetPoint(cpmBin,cpmCenter[cpmBin],lmean[cpmBin]);
          if(cpmBin == 0) GlobalUnc = lmean[0];
          if(lmean[cpmBin] > GlobalUnc) GlobalUnc = lmean[cpmBin];
          
         } //end cpm
         
        cout<<graphname<<" glob unc is "<<GlobalUnc<<endl;
        
        char fileoutupdate[200];
        sprintf(fileoutupdate,"Systematics/cutNPriVtx_smallerpT2/AverageSyst/GlobalUnc/TGraphResults_%dSUps.root",whichstate);
        TFile *fout = new TFile (fileoutupdate,"UPDATE");
       
        if(lambda == 3) { tgraphxpt2[0] = .25; tgraphxpt1[0] = .25; }
        else tgraphxpt2[0] = 2;
        
//        TCanvas *c1 = new TCanvas("c1","c1",400,600);
        if(ptBin==0) {
        globuncgraphpt1 = new TGraphErrors(1,tgraphxpt1,tgraphy,tgraphxer,lmean);
        globuncgraphpt1->SetFillColor(kOrange);
        globuncgraphpt1->SetLineColor(kOrange);
        globuncgraphpt1->SetName(graphname);
        globuncgraphpt1->GetYaxis()->SetRangeUser(-0.2,0.2);
        globuncgraphpt1->Draw("alp2");
        char savegraphname[200];
        sprintf(savegraphname,"tmpfigures/Ups%dS_l%s_%s_rap1_pt%d.pdf", whichstate, whichlambda, whichframe, ptBin+1); 
        globuncgraphpt1->Write();        
//        c1->SaveAs(savegraphname);
        }
        
        if(ptBin==1) {
        globuncgraphpt2 = new TGraphErrors(1,tgraphxpt2,tgraphy,tgraphxer,lmean);
        globuncgraphpt2->SetFillColor(kTeal);
        globuncgraphpt2->SetLineColor(kTeal);        
        globuncgraphpt2->SetName(graphname);
        globuncgraphpt2->GetYaxis()->SetRangeUser(-0.2,0.2);
        globuncgraphpt2->Draw("alp2");
        char savegraphname[200];
        sprintf(savegraphname,"tmpfigures/Ups%dS_l%s_%s_rap1_pt%d.pdf", whichstate, whichlambda, whichframe, ptBin+1); 
        globuncgraphpt2->Write();
//        c1->SaveAs(savegraphname);
        }
        
        
        
        fout->Close();

      } //end pt
     } //end lambda
    } //end frame
     cout<<"Ending Upsilon("<<whichstate<<"S)"<<endl;
     whichstate++;
   } //end nstate





}