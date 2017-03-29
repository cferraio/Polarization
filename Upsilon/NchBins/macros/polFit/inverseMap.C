{

TFile *f1 = TFile::Open("/data/users/ferraioc/Polarization/Modified/Data/LambdaDiffs_2011_map/results_1SUps_rap1_pT1_cpm2.root");

 int costhBins = 64;
 int phiBins = 16;
 
  TH2D *unitHisto = new TH2D("","",64, -1, 1, 16, -180, 180);
  unitHisto->SetName("unit");
  unitHisto->Reset();
  
for(int costh = 1; costh < costhBins+1; costh++){
  for(int phi = 1; phi < phiBins+1; phi++){
	unitHisto->Fill(costh,phi);
  }
}

unitHisto->Print();
unitHisto->Draw();
//double inserse = 0;
  //  if(signal_costhphiPX->GetBinContent(costh,phi)==0) continue;
//    inverse = 1/signal_costhphiPX->GetBinContent(costh,phi);
  //  cout<<inverse<<endl;

}