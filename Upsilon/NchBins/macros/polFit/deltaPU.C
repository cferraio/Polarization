{
  TCanvas *c1 = new TCanvas("c","c",600,400);

//  TFile f("/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx/TGraphResults_1SUps.root");
  char fileCut[200];
  char fileNoCut[200];  
  for(Int_t state = 1; state < 4; state++) 
    {
    sprintf(fileCut,"/data/users/ferraioc/Polarization/Modified/Data/cutNPriVtx/TGraphResults_%iSUps.root",state);
    TFile *cut = new TFile(fileCut);
    
    if(state == 1 || state == 2)
    {
    Int_t    npxpt1cut = ltilde_PX_rap1_pt1->GetN();
    Double_t xpxpt1cut = ltilde_PX_rap1_pt1->GetX();
    Double_t ypxpt1cut = ltilde_PX_rap1_pt1->GetY();
	}
	
    Int_t    npxpt2cut = ltilde_PX_rap1_pt2->GetN();
    Double_t xpxpt2cut = ltilde_PX_rap1_pt2->GetX();
    Double_t ypxpt2cut = ltilde_PX_rap1_pt2->GetY();

	if(state == 1 || state == 2)
    {
    Int_t    nhxpt1cut = ltilde_HX_rap1_pt1->GetN();
    Double_t xhxpt1cut = ltilde_HX_rap1_pt1->GetX();
    Double_t yhxpt1cut = ltilde_HX_rap1_pt1->GetY();
	}
	
    Int_t    nhxpt2cut = ltilde_HX_rap1_pt2->GetN();
    Double_t xhxpt2cut = ltilde_HX_rap1_pt2->GetX();
    Double_t yhxpt2cut = ltilde_HX_rap1_pt2->GetY();
	
	if(state == 1 || state == 2)
    {
    Int_t    ncspt1cut = ltilde_CS_rap1_pt1->GetN();
    Double_t xcspt1cut = ltilde_CS_rap1_pt1->GetX();
    Double_t ycspt1cut = ltilde_CS_rap1_pt1->GetY();
	}
	
    Int_t    ncspt2cut = ltilde_CS_rap1_pt2->GetN();
    Double_t xcspt2cut = ltilde_CS_rap1_pt2->GetX();
    Double_t ycspt2cut = ltilde_CS_rap1_pt2->GetY();
    
    Double_t Nchpt1[5];
    Double_t Nchpt2[5];
    Double_t lambdaPXcutpt1[5];
    Double_t lambdaPXcutpt1h[5];
    Double_t lambdaPXcutpt1l[5];
    
    Double_t lambdaHXcutpt1[5];
    Double_t lambdaHXcutpt1h[5];
    Double_t lambdaHXcutpt1l[5];
    
    Double_t lambdaCScutpt1[5];
    Double_t lambdaCScutpt1h[5];
    Double_t lambdaCScutpt1l[5];
    
    Double_t lambdaPXcutpt2[5];
    Double_t lambdaPXcutpt2h[5];
    Double_t lambdaPXcutpt2l[5];
    
    Double_t lambdaHXcutpt2[5];
    Double_t lambdaHXcutpt2h[5];
    Double_t lambdaHXcutpt2l[5];
    
    Double_t lambdaCScutpt2[5];
    Double_t lambdaCScutpt2h[5];
    Double_t lambdaCScutpt2l[5];
    Double_t Bufferxpt1;
    Double_t Bufferypt1;
    Double_t Bufferxpt2;
    Double_t Bufferypt2;
    
    for(int i = 0; i < 5; i++)
      {
        if(state == 1 || state == 2)
    {
        ltilde_PX_rap1_pt1->GetPoint(i,Bufferxpt1,Bufferypt1);
        lambdaPXcutpt1[i] = Bufferypt1; 
        lambdaPXcutpt1h[i] = ltilde_PX_rap1_pt1->GetErrorYhigh(i);
        lambdaPXcutpt1l[i] = ltilde_PX_rap1_pt1->GetErrorYlow(i);
        
        
        Nchpt1[i] = Bufferxpt1; }
        
        ltilde_PX_rap1_pt2->GetPoint(i,Bufferxpt2,Bufferypt2);
        lambdaPXcutpt2[i] = Bufferypt2;
        lambdaPXcutpt2h[i] = ltilde_PX_rap1_pt2->GetErrorYhigh(i);
        lambdaPXcutpt2l[i] = ltilde_PX_rap1_pt2->GetErrorYlow(i);
        Nchpt2[i] = Bufferxpt2;
        
        if(state == 1 || state == 2)
    {
        ltilde_CS_rap1_pt1->GetPoint(i,Bufferxpt1,Bufferypt1);
        lambdaCScutpt1[i] = Bufferypt1; 
        lambdaCScutpt1h[i] = ltilde_CS_rap1_pt1->GetErrorYhigh(i);
        lambdaCScutpt1l[i] = ltilde_CS_rap1_pt1->GetErrorYlow(i);
        }
        
        
        ltilde_CS_rap1_pt2->GetPoint(i,Bufferxpt2,Bufferypt2);
        lambdaCScutpt2[i] = Bufferypt2;
        lambdaCScutpt2h[i] = ltilde_CS_rap1_pt2->GetErrorYhigh(i);
        lambdaCScutpt2l[i] = ltilde_CS_rap1_pt2->GetErrorYlow(i);
        
        if(state == 1 || state == 2)
    {
        ltilde_HX_rap1_pt1->GetPoint(i,Bufferxpt1,Bufferypt1);
        lambdaHXcutpt1[i] = Bufferypt1;
        lambdaHXcutpt1h[i] = ltilde_HX_rap1_pt1->GetErrorYhigh(i);
        lambdaHXcutpt1l[i] = ltilde_HX_rap1_pt1->GetErrorYlow(i);
        }
        
        ltilde_HX_rap1_pt2->GetPoint(i,Bufferxpt2,Bufferypt2);
        lambdaHXcutpt2[i] = Bufferypt2;
        lambdaHXcutpt2h[i] = ltilde_PX_rap1_pt2->GetErrorYhigh(i);
        lambdaHXcutpt2l[i] = ltilde_PX_rap1_pt2->GetErrorYlow(i);
      }
    
    sprintf(fileNoCut,"/data/users/ferraioc/Polarization/Modified/Data/GreatCPMRun2/TGraphResults_%iSUps.root",state);
    TFile *noCut = new TFile(fileNoCut);
    
    if(state == 1 || state == 2)
    {
	Int_t    npxpt1 = ltilde_PX_rap1_pt1->GetN();
    Double_t xpxpt1 = ltilde_PX_rap1_pt1->GetX();
    Double_t ypxpt1 = ltilde_PX_rap1_pt1->GetY();
	}
	
    Int_t    npxpt2 = ltilde_PX_rap1_pt2->GetN();
    Double_t xpxpt2 = ltilde_PX_rap1_pt2->GetX();
    Double_t ypxpt2 = ltilde_PX_rap1_pt2->GetY();

if(state == 1 || state == 2)
    {
    Int_t    nhxpt1 = ltilde_HX_rap1_pt1->GetN();
    Double_t xhxpt1 = ltilde_HX_rap1_pt1->GetX();
    Double_t yhxpt1 = ltilde_HX_rap1_pt1->GetY();
}

    Int_t    nhxpt2 = ltilde_HX_rap1_pt2->GetN();
    Double_t xhxpt2 = ltilde_HX_rap1_pt2->GetX();
    Double_t yhxpt2 = ltilde_HX_rap1_pt2->GetY();

if(state == 1 || state == 2)
    {
    Int_t    ncspt1 = ltilde_CS_rap1_pt1->GetN();
    Double_t xcspt1 = ltilde_CS_rap1_pt1->GetX();
    Double_t ycspt1 = ltilde_CS_rap1_pt1->GetY();
    }

    Int_t    ncspt2 = ltilde_CS_rap1_pt2->GetN();
    Double_t xcspt2 = ltilde_CS_rap1_pt2->GetX();
    Double_t ycspt2 = ltilde_CS_rap1_pt2->GetY();

    Double_t lambdaPXpt1[5];
    Double_t lambdaPXpt1h[5];
    Double_t lambdaCSpt1h[5];
    Double_t lambdaHXpt1h[5];
    Double_t lambdaPXpt2h[5];
    Double_t lambdaHXpt2h[5];
    Double_t lambdaCSpt2h[5];
    Double_t lambdaPXpt1l[5];
    Double_t lambdaCSpt1l[5];
    Double_t lambdaHXpt1l[5];
    Double_t lambdaPXpt2l[5];
    Double_t lambdaHXpt2l[5];
    Double_t lambdaCSpt2l[5];
    Double_t lambdaHXpt1[5];
    Double_t lambdaCSpt1[5];
    Double_t lambdaPXpt2[5];
    Double_t lambdaHXpt2[5];
    Double_t lambdaCSpt2[5];
    for(int i = 0; i < 5; i++)
      {
      if(state == 1 || state == 2)
    {
        ltilde_PX_rap1_pt1->GetPoint(i,Bufferxpt1,Bufferypt1);
        lambdaPXpt1[i] = Bufferypt1; 
        lambdaPXpt1h[i] = ltilde_PX_rap1_pt1->GetErrorYhigh(i);
        lambdaPXpt1l[i] = ltilde_PX_rap1_pt1->GetErrorYlow(i);
        }
        ltilde_PX_rap1_pt2->GetPoint(i,Bufferxpt2,Bufferypt2);
        lambdaPXpt2[i] = Bufferypt2;
        lambdaPXpt2h[i] = ltilde_PX_rap1_pt2->GetErrorYhigh(i);
        lambdaPXpt2l[i] = ltilde_PX_rap1_pt2->GetErrorYlow(i);
        
        if(state == 1 || state == 2)
    {
        ltilde_CS_rap1_pt1->GetPoint(i,Bufferxpt1,Bufferypt1);
        lambdaCSpt1[i] = Bufferypt1; 
        lambdaCSpt1h[i] = ltilde_CS_rap1_pt1->GetErrorYhigh(i);
        lambdaCSpt1l[i] = ltilde_CS_rap1_pt1->GetErrorYlow(i);
        }
        ltilde_CS_rap1_pt2->GetPoint(i,Bufferxpt2,Bufferypt2);
        lambdaCSpt2[i] = Bufferypt2;
        lambdaCSpt2h[i] = ltilde_CS_rap1_pt2->GetErrorYhigh(i);
        lambdaCSpt2l[i] = ltilde_CS_rap1_pt2->GetErrorYlow(i);
        
        if(state == 1 || state == 2)
    {
        ltilde_HX_rap1_pt1->GetPoint(i,Bufferxpt1,Bufferypt1);
        lambdaHXpt1[i] = Bufferypt1;
        lambdaHXpt1h[i] = ltilde_HX_rap1_pt1->GetErrorYhigh(i);
        lambdaHXpt1l[i] = ltilde_HX_rap1_pt1->GetErrorYlow(i);}
        
        ltilde_HX_rap1_pt2->GetPoint(i,Bufferxpt2,Bufferypt2);
        lambdaHXpt2[i] = Bufferypt2;
        lambdaHXpt2h[i] = ltilde_HX_rap1_pt2->GetErrorYhigh(i);
        lambdaHXpt2l[i] = ltilde_HX_rap1_pt2->GetErrorYlow(i);
      }
      
	Double_t diffPXpt1[5];
	Double_t diffCSpt1[5];
	Double_t diffHXpt1[5];
	Double_t errorPXpt1h[5];
	Double_t errorPXpt1l[5];
	Double_t errorCSpt1h[5];
	Double_t errorCSpt1l[5];
	Double_t errorHXpt1h[5];
	Double_t errorHXpt1l[5];
	Double_t errorPXpt2h[5];
	Double_t errorPXpt2l[5];
	Double_t errorCSpt2h[5];
	Double_t errorCSpt2l[5];
	Double_t errorHXpt2h[5];
	Double_t errorHXpt2l[5];
	Double_t diffPXpt2[5];
	Double_t diffHXpt2[5];
	Double_t diffCSpt2[5];
	
	for(int i = 0; i < 5; i++)
	  {
	  if(state == 1 || state == 2)
       {
	    diffPXpt1[i] = lambdaPXpt1[i] - lambdaPXcutpt1[i];
	    errorPXpt1h[i] = sqrt( pow(lambdaPXcutpt1h[i] ,2) + pow(lambdaPXpt1h[i] ,2) );
	    errorPXpt1l[i] = sqrt(pow(lambdaPXcutpt1l[i] ,2) + pow(lambdaPXpt1l[i] ,2));
	    diffHXpt1[i] = lambdaHXpt1[i] - lambdaHXcutpt1[i];
	    errorHXpt1h[i] = sqrt(pow(lambdaHXcutpt1h[i] ,2) + pow(lambdaHXpt1h[i] ,2));
	    errorHXpt1l[i] = sqrt(pow(lambdaHXcutpt1l[i] ,2) + pow(lambdaHXpt1l[i] ,2));
	    diffCSpt1[i] = lambdaCSpt1[i] - lambdaCScutpt1[i]; 
	    errorCSpt1h[i] = sqrt(pow(lambdaCScutpt1h[i] ,2) + pow(lambdaCSpt1h[i] ,2));
	    errorCSpt1l[i] = sqrt(pow(lambdaCScutpt1l[i] ,2) + pow(lambdaCSpt1l[i] ,2));
	   }
	    diffPXpt2[i] = lambdaPXpt2[i] - lambdaPXcutpt2[i];
	    errorPXpt2h[i] = sqrt(pow(lambdaPXcutpt2h[i] ,2) + pow(lambdaPXpt2h[i] ,2));
	    errorPXpt2l[i] = sqrt(pow(lambdaPXcutpt2l[i] ,2) + pow(lambdaPXpt2l[i] ,2));
	    diffHXpt2[i] = lambdaHXpt2[i] - lambdaHXcutpt2[i];
	    errorHXpt2h[i] = sqrt(pow(lambdaHXcutpt2h[i] ,2) + pow(lambdaHXpt2h[i] ,2));
	    errorHXpt2l[i] = sqrt(pow(lambdaHXcutpt2l[i] ,2) + pow(lambdaHXpt2l[i] ,2));
	    diffCSpt2[i] = lambdaCSpt2[i] - lambdaCScutpt2[i];
	    errorCSpt2h[i] = sqrt(pow(lambdaCScutpt2h[i] ,2) + pow(lambdaCSpt2h[i] ,2));
	    errorCSpt2l[i] = sqrt(pow(lambdaCScutpt2l[i] ,2) + pow(lambdaCSpt2l[i] ,2));
	  }
	  
	  
	  if(state == 1 || state == 2)
    {
// 	pxpt1diffTGraph = new TGraphAsymmErrors(5,Nchpt1,diffPXpt1,0,0,errorPXpt1h,errorPXpt1l);
 	pxpt1diffTGraph = new TGraphAsymmErrors(5,Nchpt1,diffPXpt1,0,0,0,0);
 	if(state == 1)
    {
 	pxpt1diffTGraph->GetYaxis()->SetRangeUser(-.030,.020); }
 	if(state == 2)
    {
 	pxpt1diffTGraph->GetYaxis()->SetRangeUser(-.060,.040); }
 	 	if(state == 3)
    {
 	pxpt1diffTGraph->GetYaxis()->SetRangeUser(-.040,.035); }
 	pxpt1diffTGraph->SetTitle("Lambda tidle without cuts - Lambda tilde with cuts");
 	pxpt1diffTGraph->GetYaxis()->SetTitle("#Delta#lambda tilde");
 	pxpt1diffTGraph->SetMarkerStyle(20);
 	pxpt1diffTGraph->SetMarkerColor(2);
 	pxpt1diffTGraph->SetLineColor(2);
 	pxpt1diffTGraph->Draw("apl");
 	
// 	hxpt1diffTGraph = new TGraphAsymmErrors(5,Nchpt1,diffHXpt1,0,0,errorHXpt1h,errorHXpt1l);
 	hxpt1diffTGraph = new TGraphAsymmErrors(5,Nchpt1,diffHXpt1,0,0,0,0);
 	hxpt1diffTGraph->SetMarkerStyle(21);
 	hxpt1diffTGraph->SetMarkerColor(3);
 	hxpt1diffTGraph->SetLineColor(3);
 	hxpt1diffTGraph->Draw("pl");	
 	
// 	cspt1diffTGraph = new TGraphAsymmErrors(5,Nchpt1,diffCSpt1,0,0,errorCSpt1h,errorCSpt1l);
 	cspt1diffTGraph = new TGraphAsymmErrors(5,Nchpt1,diffCSpt1,0,0,0,0);
 	cspt1diffTGraph->SetMarkerStyle(22);
 	cspt1diffTGraph->SetMarkerColor(4);
 	cspt1diffTGraph->SetLineColor(4);
 	cspt1diffTGraph->Draw("pl");
 	
 	leg = new TLegend(0.75,0.8,0.9,0.9);
 	leg->SetFillColor(0);
 	leg->AddEntry(pxpt1diffTGraph,"PX difference","lp");
 	leg->AddEntry(hxpt1diffTGraph,"HX difference","lp");
 	leg->AddEntry(cspt1diffTGraph,"CS difference","lp");
 	leg->Draw();
 	
 	char name[50];
 	sprintf(name,"diffpT1_Ups%iS.pdf",state);
 	c1->SaveAs(name);
 	}
 	
 	
// 	pxpt2diffTGraph = new TGraphAsymmErrors(5,Nchpt2,diffPXpt2,0,0,errorPXpt1h,errorPXpt2l);
 	pxpt2diffTGraph = new TGraphAsymmErrors(5,Nchpt2,diffPXpt2,0,0,0,0);
 	if(state == 1)
    {
 	pxpt2diffTGraph->GetYaxis()->SetRangeUser(-.020,.020); }
 	if(state == 2)
    {
 	pxpt2diffTGraph->GetYaxis()->SetRangeUser(-.020,.015); }
 	if(state == 3)
    {
 	pxpt2diffTGraph->GetYaxis()->SetRangeUser(-.06,.07); 
 	}
 	pxpt2diffTGraph->SetMarkerStyle(24);
 	pxpt2diffTGraph->SetTitle("Lambda tidle without cuts - Lambda tilde with cuts");
 	pxpt2diffTGraph->GetYaxis()->SetTitle("#Delta#lambda tilde");
 	pxpt2diffTGraph->GetXaxis()->SetTitle("N_{ch}");
 	pxpt2diffTGraph->SetMarkerColor(2);
 	pxpt2diffTGraph->SetLineColor(2);
 	pxpt2diffTGraph->Draw("apl");
 	
// 	hxpt2diffTGraph = new TGraphAsymmErrors(5,Nchpt2,diffHXpt2,0,0,errorHXpt1h,errorHXpt2l);
   	hxpt2diffTGraph = new TGraphAsymmErrors(5,Nchpt2,diffHXpt2,0,0,0,0);
 	hxpt2diffTGraph->SetMarkerStyle(25);
 	hxpt2diffTGraph->SetMarkerColor(3);
 	hxpt2diffTGraph->SetLineColor(3);
 	hxpt2diffTGraph->Draw("pl");
 	
// 	cspt2diffTGraph = new TGraphAsymmErrors(5,Nchpt2,diffCSpt2,0,0,errorCSpt1h,errorCSpt2l);
    cspt2diffTGraph = new TGraphAsymmErrors(5,Nchpt2,diffCSpt2,0,0,0,0); 
 	cspt2diffTGraph->SetMarkerStyle(26);
 	cspt2diffTGraph->SetMarkerColor(4);
 	cspt2diffTGraph->SetLineColor(4);
 	cspt2diffTGraph->Draw("pl"); 
 	
 	leg2 = new TLegend(0.75,0.8,0.9,0.9);
 	leg2->SetFillColor(0);
 	leg2->AddEntry(pxpt2diffTGraph,"PX difference","lp");
 	leg2->AddEntry(hxpt2diffTGraph,"HX difference","lp");
 	leg2->AddEntry(cspt2diffTGraph,"CS difference","lp");
 	leg2->Draw();
 	
 	sprintf(name,"diffpT2_Ups%iS.pdf",state);
 	c1->SaveAs(name);
 	
  }
}

