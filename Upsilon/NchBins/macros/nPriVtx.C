{

blah = new TH1F("blah","blah",50, 0., 100.);


blah1 = new TH1F("blah1","blah1",50, 0., 100.);
blah2 = new TH1F("blah2","blah2",50, 0., 100.);
blah3 = new TH1F("blah3","blah3",50, 0., 100.);
blah4 = new TH1F("blah4","blah4",50, 0., 100.);
blah5 = new TH1F("blah5","blah5",50, 0., 100.);
blah6 = new TH1F("blah6","blah6",50, 0., 100.);
blah7 = new TH1F("blah7","blah7",50, 0., 100.);
blah8 = new TH1F("blah8","blah8",50, 0., 100.);
blah9 = new TH1F("blah9","blah9",50, 0., 100.);
blah10 = new TH1F("blah10","blah10",50, 0., 100.);
blah11 = new TH1F("blah11","blah11",50, 0., 100.);
blah12 = new TH1F("blah12","blah12",50, 0., 100.);
blah13 = new TH1F("blah13","blah13",50, 0., 100.);
blah14 = new TH1F("blah14","blah14",50, 0., 100.);
blah15 = new TH1F("blah15","blah15",50, 0., 100.);
blah16 = new TH1F("blah16","blah16",50, 0., 100.);
blah17 = new TH1F("blah17","blah17",50, 0., 100.);
blah18 = new TH1F("blah18","blah18",50, 0., 100.);
blah19 = new TH1F("blah19","blah19",50, 0., 100.);
blah20 = new TH1F("blah20","blah20",50, 0., 100.);
blah21 = new TH1F("blah21","blah21",50, 0., 100.);
blah22 = new TH1F("blah22","blah22",50, 0., 100.);
blah23 = new TH1F("blah23","blah23",50, 0., 100.);
blah24 = new TH1F("blah24","blah24",50, 0., 100.);

blah1->Sumw2();
blah2->Sumw2();
blah3->Sumw2();
blah4->Sumw2();
blah5->Sumw2();
blah6->Sumw2();
blah7->Sumw2();
blah8->Sumw2();
blah9->Sumw2();
blah10->Sumw2();
blah11->Sumw2();
blah12->Sumw2();
blah13->Sumw2();
blah14->Sumw2();
blah15->Sumw2();
blah16->Sumw2();
blah17->Sumw2();
blah18->Sumw2();
blah19->Sumw2();
blah20->Sumw2();
blah21->Sumw2();
blah22->Sumw2();
blah23->Sumw2();
blah24->Sumw2();


TLorentzVector  *onia, *muNeg, *muPos;
Long64_t nentries = data->GetEntries();
Int_t nPriVtx;
Double_t vertexWeight;
Double_t JpsiVprob;
onia = 0;
 muNeg = 0;
   muPos = 0;
   Double_t JpsiCtauSigMin=-1000; //-1000
  Double_t JpsiCtauSigMax=2.;
  Double_t JpsictErr;
  data->SetBranchAddress("JpsictErr",&JpsictErr);
Double_t Jpsict;
data->SetBranchAddress("Jpsict",&Jpsict);
Int_t HLT_Dimuon5_Upsilon_Barrel_v1;
data->SetBranchAddress("HLT_Dimuon5_Upsilon_Barrel_v1",&HLT_Dimuon5_Upsilon_Barrel_v1);
Int_t HLT_Dimuon5_Upsilon_Barrel_v2;
data->SetBranchAddress("HLT_Dimuon5_Upsilon_Barrel_v2",&HLT_Dimuon5_Upsilon_Barrel_v2);
Int_t HLT_Dimuon5_Upsilon_Barrel_v3;
data->SetBranchAddress("HLT_Dimuon5_Upsilon_Barrel_v3",&HLT_Dimuon5_Upsilon_Barrel_v3);
Int_t HLT_Dimuon5_Upsilon_Barrel_v5;
data->SetBranchAddress("HLT_Dimuon5_Upsilon_Barrel_v5",&HLT_Dimuon5_Upsilon_Barrel_v5);
Int_t HLT_Dimuon9_Upsilon_Barrel_v1;
data->SetBranchAddress("HLT_Dimuon9_Upsilon_Barrel_v1",&HLT_Dimuon9_Upsilon_Barrel_v1);
Int_t HLT_Dimuon7_Upsilon_Barrel_v1;
data->SetBranchAddress("HLT_Dimuon7_Upsilon_Barrel_v1",&HLT_Dimuon7_Upsilon_Barrel_v1);
Int_t HLT_Dimuon9_Upsilon_Barrel_v4;
data->SetBranchAddress("HLT_Dimuon9_Upsilon_Barrel_v4",&HLT_Dimuon9_Upsilon_Barrel_v4);
Int_t HLT_Dimuon7_Upsilon_Barrel_v4;
data->SetBranchAddress("HLT_Dimuon7_Upsilon_Barrel_v4",&HLT_Dimuon7_Upsilon_Barrel_v4);
data->SetBranchAddress("JpsiP", &onia);
data->SetBranchAddress("JpsiVprob",&JpsiVprob);
data->SetBranchAddress("nPriVtx",&nPriVtx);
data->SetBranchAddress("vertexWeight",&vertexWeight);
Double_t Nchsum[25];
Double_t nEvent[25];
for(int x = 0; x<25;x++)
{Nchsum[x]=0;
nEvent[x]=0;}

//nentries = 3000000;
 for (Long64_t jentry=0; jentry<nentries;jentry++) {
 
 if(jentry % 100000 == 0) printf("event %d\n", (Int_t) jentry);

//    Long64_t ientry = LoadTree(jentry);
//    if (ientry < 0) break;

    data->GetEntry(jentry);
//    blah->Fill(nPriVtx);
    if(vertexWeight<0) continue;
    if(onia->Pt() > 990.)
      continue;
Int_t trigPtDecision = -99;
    if(JpsiVprob < 0.01)
      continue;
if(//HLT_DoubleMu3_Quarkonium_v1 == 1 ||   //  5e32: 160404 - 161176
      //HLT_DoubleMu3_Upsilon_v1 == 1 ||      //  5e32: 161216 - 163261
      //HLT_Dimuon0_Barrel_Upsilon_v1 == 1 || //  5e32: 163269 - 163869
      HLT_Dimuon5_Upsilon_Barrel_v1 == 1 && onia->Pt() < 5.5 || //  1e33: 165088 - 166967 and 1.4E33: 167039 - 167043
      HLT_Dimuon5_Upsilon_Barrel_v2 == 1 && onia->Pt() < 5.5  || //  1e33: 166346
      HLT_Dimuon5_Upsilon_Barrel_v3 == 1 && onia->Pt() < 5.5  ||  //1.4e33: 167078 - 167913 (prescale of 2)
      HLT_Dimuon5_Upsilon_Barrel_v5 == 1 && onia->Pt() < 5.5  || //2E33 (no cowboys)
      HLT_Dimuon7_Upsilon_Barrel_v1 == 1 && onia->Pt() < 7.5  || //3E33 (L1_DoubleMu0_HighQ; becomes inactive for Linst >= 5E33)
      HLT_Dimuon9_Upsilon_Barrel_v1 == 1 && onia->Pt() < 9.5  || //3E33 (L1_DoubleMu0_HighQ)
      HLT_Dimuon7_Upsilon_Barrel_v4 == 1 && onia->Pt() < 7.5  || //5E33 (becomes inactive for Linst >= 5E33)
      HLT_Dimuon9_Upsilon_Barrel_v4 == 1 && onia->Pt() < 9.5 ) //5E33
      trigPtDecision = 1;

   if(trigPtDecision == 1)
     continue;
     Double_t rapYPS = 1.2;
      Double_t onia_rap = onia->Rapidity();
     if(TMath::Abs(onia_rap) > onia::rapYPS)
      continue;

      
      if(Jpsict > 1000.)
      continue;
    if(Jpsict < -1000.)
      continue;
      
      if(TMath::Abs(Jpsict/JpsictErr)<onia::JpsiCtauSigMin) continue;
    if(TMath::Abs(Jpsict/JpsictErr)>onia::JpsiCtauSigMax) continue;
      Double_t onia_mass = onia->M();
      
      if(onia_mass < 8.4 || onia_mass > 11.6) //all Upsilons triggered
      continue;
      
if(nPriVtx == 1) {Nchsum[1]+=vertexWeight; nEvent[1]++; blah1->Fill(vertexWeight);}
if(nPriVtx == 2) {Nchsum[2]+=vertexWeight; nEvent[2]++; blah2->Fill(vertexWeight);}
if(nPriVtx == 3) {Nchsum[3]+=vertexWeight; nEvent[3]++; blah3->Fill(vertexWeight);}
if(nPriVtx == 4) {Nchsum[4]+=vertexWeight; nEvent[4]++; blah4->Fill(vertexWeight);}
if(nPriVtx == 5) {Nchsum[5]+=vertexWeight; nEvent[5]++; blah5->Fill(vertexWeight);}
if(nPriVtx == 6) {Nchsum[6]+=vertexWeight; nEvent[6]++; blah6->Fill(vertexWeight);}
if(nPriVtx == 7) {Nchsum[7]+=vertexWeight; nEvent[7]++; blah7->Fill(vertexWeight);}
if(nPriVtx == 8) {Nchsum[8]+=vertexWeight; nEvent[8]++; blah8->Fill(vertexWeight);}
if(nPriVtx == 9) {Nchsum[9]+=vertexWeight; nEvent[9]++; blah9->Fill(vertexWeight);}
if(nPriVtx == 10) {Nchsum[10]+=vertexWeight; nEvent[10]++; blah10->Fill(vertexWeight);}
if(nPriVtx == 11) {Nchsum[11]+=vertexWeight; nEvent[11]++; blah11->Fill(vertexWeight);}
if(nPriVtx == 12) {Nchsum[12]+=vertexWeight; nEvent[12]++; blah12->Fill(vertexWeight);}
if(nPriVtx == 13) {Nchsum[13]+=vertexWeight; nEvent[13]++; blah13->Fill(vertexWeight);}
if(nPriVtx == 14) {Nchsum[14]+=vertexWeight; nEvent[14]++; blah14->Fill(vertexWeight);}
if(nPriVtx == 15) {Nchsum[15]+=vertexWeight; nEvent[15]++; blah15->Fill(vertexWeight);}
if(nPriVtx == 16) {Nchsum[16]+=vertexWeight; nEvent[16]++; blah16->Fill(vertexWeight);}
if(nPriVtx == 17) {Nchsum[17]+=vertexWeight; nEvent[17]++; blah17->Fill(vertexWeight);}
if(nPriVtx == 18) {Nchsum[18]+=vertexWeight; nEvent[18]++; blah18->Fill(vertexWeight);}
if(nPriVtx == 19) {Nchsum[19]+=vertexWeight; nEvent[19]++; blah19->Fill(vertexWeight);}
if(nPriVtx == 20) {Nchsum[20]+=vertexWeight; nEvent[20]++; blah20->Fill(vertexWeight);}
if(nPriVtx == 21) {Nchsum[21]+=vertexWeight; nEvent[21]++; blah21->Fill(vertexWeight);}
if(nPriVtx == 22) {Nchsum[22]+=vertexWeight; nEvent[22]++; blah22->Fill(vertexWeight);}
if(nPriVtx == 23) {Nchsum[23]+=vertexWeight; nEvent[23]++; blah23->Fill(vertexWeight);}
if(nPriVtx == 24) {Nchsum[24]+=vertexWeight; nEvent[24]++; blah24->Fill(vertexWeight);}
  
 
  }
//    cout<<jentry<<" blah "<<nPriVtx<<endl;
Double_t mean[24];
Double_t privtx[24];

mean[0] = blah1->GetMean();
mean[1] = blah2->GetMean();
mean[2] = blah3->GetMean();
mean[3] = blah4->GetMean();
mean[4] = blah5->GetMean();
mean[5] = blah6->GetMean();
mean[6] = blah7->GetMean();
mean[7] = blah8->GetMean();
mean[8] = blah9->GetMean();
mean[9] = blah10->GetMean();
mean[10] = blah11->GetMean();
mean[11] = blah12->GetMean();
mean[12] = blah13->GetMean();
mean[13] = blah14->GetMean();
mean[14] = blah15->GetMean();
mean[15] = blah16->GetMean();
mean[16] = blah17->GetMean();
mean[17] = blah18->GetMean();
mean[18] = blah19->GetMean();
mean[19] = blah20->GetMean();
mean[20] = blah21->GetMean();
mean[21] = blah22->GetMean();
mean[22] = blah23->GetMean();
mean[23] = blah24->GetMean();

Double_t meanerror[25];
meanerror[0] = blah1->GetMeanError();
meanerror[1] = blah2->GetMeanError();
meanerror[2] = blah3->GetMeanError();
meanerror[3] = blah4->GetMeanError();
meanerror[4] = blah5->GetMeanError();
meanerror[5] = blah6->GetMeanError();
meanerror[6] = blah7->GetMeanError();
meanerror[7] = blah8->GetMeanError();
meanerror[8] = blah9->GetMeanError();
meanerror[9] = blah10->GetMeanError();
meanerror[10] = blah11->GetMeanError();
meanerror[11] = blah12->GetMeanError();
meanerror[12] = blah13->GetMeanError();
meanerror[13] = blah14->GetMeanError();
meanerror[14] = blah15->GetMeanError();
meanerror[15] = blah16->GetMeanError();
meanerror[16] = blah17->GetMeanError();
meanerror[17] = blah18->GetMeanError();
meanerror[18] = blah19->GetMeanError();
meanerror[19] = blah20->GetMeanError();
meanerror[20] = blah21->GetMeanError();
meanerror[21] = blah22->GetMeanError();
meanerror[22] = blah23->GetMeanError();
meanerror[23] = blah24->GetMeanError();

privtx[0] = 1;
privtx[1] = 2;
privtx[2] = 3;
privtx[3] = 4;
privtx[4] = 5;
privtx[5] = 6;
privtx[6] = 7;
privtx[7] = 8;
privtx[8] = 9;
privtx[9] = 10;
privtx[10] =11 ;
privtx[11] = 12;
privtx[12] = 13;
privtx[13] = 14;
privtx[14] = 15;
privtx[15] = 16;
privtx[16] = 17;
privtx[17] = 18;
privtx[18] = 19;
privtx[19] = 20;
privtx[20] = 21;
privtx[21] = 22;
privtx[22] = 23;
privtx[23] = 24;

Double_t xerror[25];
for(int x = 0; x < 24; x++)
{
xerror[x]=0;
}


gr = new TGraphErrors(24,privtx,mean,0,meanerror);
     for(int x = 1; x<25; x++){
  Double_t poop = Nchsum[x]/nEvent[x];
  cout<<poop<<endl;
 }
 gr->Draw("alp");
 
 }