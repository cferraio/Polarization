{
for(int x = 1; x < 3; x++)
    {
      for(int y = 1; y < 6; y++)
          {
                std::stringstream tot, phiPXsig, savename, savename2, bg;
                tot << "/data/users/ferraioc/Polarization/Modified/Data/28sep14norm/results_3SUps_rap1_pT" << x << "_cpm" << y << ".root";
                bg << "/data/users/ferraioc/Polarization/Modified/Data/01oct14RSB/results_3SUps_rap1_pT" << x << "_cpm" << y << ".root";
                TFile *f1 = TFile::Open((tot.str()).c_str());
                    TFile *f2 = TFile::Open((bg.str()).c_str());

                    TCanvas *c1 = new TCanvas();
                    TH1D *h1 = (TH1D*) f1->FindObjectAny("total_costhPX");
                    TH1D *h2 = (TH1D*) f2->FindObjectAny("total_costhPX");
                    Double_t ymin, ymax;
                     ymin = h2->GetMinimum();
                     ymax = h1->GetMaximum();
                    TH1F *signalcosth = h1->Clone();
                    signalcosth->SetName("costh Signal");
                    signalcosth->Add(h2,-1);
                    signalcosth->GetYaxis()->SetRangeUser(ymin-50,ymax+50);
                    signalcosth->SetLineColor(2);
                    signalcosth->SetMarkerColor( 2);
                signalcosth->Draw();
                h1->SetLineColor( 1);
                h1->SetMarkerStyle( 20);
                h1->SetMarkerColor( 1);
                h1->Draw("same");
                h2->SetLineColor(3);
                h2->SetMarkerStyle( 29);
                h2->SetMarkerColor( 3);
                h2->Draw("same");
                TLegend *leg = new TLegend(0.1,0.7,0.25,0.9, "costhPX");
                leg->AddEntry(h1,"Total ","p");
                leg->AddEntry(h2,"BG","p");
                leg->AddEntry(signalcosth,"Signal","p");
                leg->Draw();
                savename << "RSBcosthPX_3SUps_rap1_pT" << x << "_cpm" << y << ".pdf";
			  	c1->Print((savename.str()).c_str());
			  	
			  	    TH1D *h1 = (TH1D*) f1->FindObjectAny("total_phiPX");
                    TH1D *h2 = (TH1D*) f2->FindObjectAny("total_phiPX");
                    Double_t yminBG, yminS;
                    yminS = h2->GetMinimum();
                    
                    ymax = h1->GetMaximum();
                    TH1F *signalphi = h1->Clone();
                    signalphi->SetName("costh Signal");
                    signalphi->Add(h2,-1);
                    yminBG = signalphi->GetMinimum();
                    if(yminBG>yminS){
		ymin = yminS;
		}
		else{
		ymin = yminBG;
		}
                    signalphi->GetYaxis()->SetRangeUser(ymin-50,ymax+50);
                    signalphi->SetLineColor(2);
                    signalphi->SetMarkerColor( 2);
                signalphi->Draw();
                h1->SetLineColor( 1);
                h1->SetMarkerStyle( 20);
                h1->SetMarkerColor( 1);
                h1->Draw("same");
                h2->SetLineColor(3);
                h2->SetMarkerStyle( 29);
                h2->SetMarkerColor( 3);
                h2->Draw("same");
                TLegend *leg = new TLegend(0.1,0.7,0.25,0.9, "phiPX");
                leg->AddEntry(h1,"Total ","p");
                leg->AddEntry(h2,"BG","p");
                leg->AddEntry(signalphi,"Signal","p");
                leg->Draw();
                savename2 << "RSBphiPX_3SUps_rap1_pT" << x << "_cpm" << y << ".pdf";
			  	c1->Print((savename2.str()).c_str());
}}}