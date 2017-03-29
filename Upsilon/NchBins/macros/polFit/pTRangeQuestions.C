{
TGraphAsymmErrors theTGraph;
Double_t rangebin[6];

     
    for(int lam = 0; lam < 2; lam++)
    {
      char lamname[200];
      if(lam == 0) sprintf(lamname,"th");
      if(lam == 1) sprintf(lamname,"ph");

	  
      for(int frame = 0; frame < 1; frame++)
      {
        char framename[200];
        sprintf(framename,"HX");

        char bgfile1[200];
        char bgfile2[200];
        char bgfile3[200];
        
        for(int Nch = 0; Nch < 2; Nch++)
        {
        if (Nch == 0) int Nchbin = 4;
        if (Nch == 1) int Nchbin = 5;
		
		Double_t systbiasbin1[6] = 0;
	    Double_t staterrorbin1[6] = 0;
	    Double_t comberrorbin1[6] = 0;
	    
	  Double_t lambiasvalue;
	  Double_t cpmcenter;
	  Double_t min = 999.;
	  Double_t max = 0.;
	    
	    for(int range = 0; range < 6; range++)
		{
		
	  
 		 rangebin[range] = range+1;
		  char rangefile[200];
		  if(range == 0) sprintf(rangefile,"/data/users/ferraioc/Polarization/Modified/ToyMC/15to20/");
		  if(range == 1) sprintf(rangefile,"/data/users/ferraioc/Polarization/Modified/ToyMC/15to25/");
 		 if(range == 2) sprintf(rangefile,"/data/users/ferraioc/Polarization/Modified/ToyMC/15to30/");
 		 if(range == 3) sprintf(rangefile,"/data/users/ferraioc/Polarization/Modified/ToyMC/15to35/");
 		 if(range == 4) sprintf(rangefile,"/data/users/ferraioc/Polarization/Modified/ToyMC/15to40/");
 		 if(range == 5) sprintf(rangefile,"/data/users/ferraioc/Polarization/Modified/ToyMC/15to50/");
 		 sprintf(bgfile1,"%sSig_frame3scen3_Bkg_frame3scen7/TGraphResults_1SUps.root",rangefile);        
 		 sprintf(bgfile2,"%sSig_frame3scen3_Bkg_frame3scen8/TGraphResults_1SUps.root",rangefile); 
 		 sprintf(bgfile3,"%sSig_frame3scen3_Bkg_frame3scen9/TGraphResults_1SUps.root",rangefile);
  
		TFile *file1 = new TFile(bgfile1);
        TFile *file2 = new TFile(bgfile2);
        TFile *file3 = new TFile(bgfile3);

        
        char graphname[200];
        sprintf(graphname,"l%s_%s_rap1_pt2", lamname, framename); 
        
        
        Double_t biasholder = 0;
	    Double_t statholder = 0;
	  
        theTGraph = (TGraphAsymmErrors*) file1->Get(graphname);
        theTGraph->GetPoint(Nch,cpmcenter,lambiasvalue);
        statholder+=theTGraph->GetErrorY(Nch);
        biasholder+=TMath::Abs(lambiasvalue);
        
        theTGraph = (TGraphAsymmErrors*) file2->Get(graphname);
        theTGraph->GetPoint(Nch,cpmcenter,lambiasvalue);
        biasholder+=TMath::Abs(lambiasvalue);
        statholder+=theTGraph->GetErrorY(Nch);
        
        theTGraph = (TGraphAsymmErrors*) file3->Get(graphname);
        theTGraph->GetPoint(Nch,cpmcenter,lambiasvalue);
        biasholder+=TMath::Abs(lambiasvalue);
        statholder+=theTGraph->GetErrorY(Nch);
        
        systbiasbin1[range] = biasholder/3;
        staterrorbin1[range] = statholder/3;
        comberrorbin1[range] = sqrt( pow(systbiasbin1[range],2) + pow(staterrorbin1[range],2) );
        
        if(comberrorbin1[range] > max) max = comberrorbin1[range];
        if(systbiasbin1[range] < min) min = systbiasbin1[range];
        
        }//end range loop
        
        TGraphErrors *systNch = new TGraphErrors(6,rangebin,systbiasbin1);
		TGraphErrors *statNch = new TGraphErrors(6,rangebin,staterrorbin1);
		TGraphErrors *combNch = new TGraphErrors(6,rangebin,comberrorbin1);
		
          char framename[200];
        sprintf(framename,"HX");

		TCanvas * c1 = new TCanvas("c", "c",600,400);
		systNch->GetYaxis()->SetRangeUser(min*0.5,max*1.15);
		
		systNch->SetMarkerColor(1);
		systNch->SetMarkerStyle(20);
		systNch->SetLineColor(1);
		
		statNch->SetMarkerColor(3);
		statNch->SetMarkerStyle(22);
		statNch->SetLineColor(3);
		
		combNch->SetMarkerColor(2);
		combNch->SetMarkerStyle(21);
		combNch->SetLineColor(2);
		systNch->GetYaxis()->SetTitleOffset(1.1);
		systNch->GetXaxis()->SetTitle("p_{T} Range Bin");
		if(lam == 0) systNch->GetYaxis()->SetTitle("#sigma #lambda_{#vartheta}");
		if(lam == 1) systNch->GetYaxis()->SetTitle("#sigma #lambda_{#varphi}");
		if(Nch == 0) systNch->SetTitle("#Upsilon(1S), Uncertainty by bin width, 30 < N_{ch} < 40");
		if(Nch == 1) systNch->SetTitle("#Upsilon(1S), Uncertainty by bin width, 40 < N_{ch} < 60");
		systNch->Draw("ap");
		statNch->Draw("p");
		combNch->Draw("p");
		
		leg = new TLegend( 0.7,0.65,0.85,0.85);
		leg->AddEntry(systNch,"Syst","p");
		leg->SetFillStyle(0);
		leg->SetBorderSize(0);
		leg->AddEntry(statNch,"Stat","p");
		leg->AddEntry(combNch,"Combined","p");
		leg->Draw();
		char savename[200];
		sprintf(savename,"pTRangeQuestions/Ups1S_l%s_%s_Nch%d.pdf",lamname,framename,Nchbin);
		c1->SaveAs(savename);
		
      }////end Nch loop
    }////end lam loop
} ////end frame loop

      
		
		
file1->Close();
file2->Close();
file3->Close();


}